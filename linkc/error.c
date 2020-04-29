/* error.ale */
#include "stddata.h"
#include "error.h"
#include "input.h"
#include "lexical.h"
#include "item.h"


static int too_many_errors,fatal_head,fatal_tail,corrupted_head;
static int std_null,std_q,std_dots;

#define addMSG(x,y)	add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_MSG(void){
 addMSG("too many errors,quitting",too_many_errors);
 addMSG("internal error at %f/",fatal_head);
 addMSG(", program aborted",fatal_tail);
 addMSG(".ice file corrupted; found at %f/",corrupted_head);
 addMSG("[NULL]",std_null);
 addMSG("[?]",std_q);
 addMSG("[...]",std_dots);
}
#undef addMSG
static int prpos=0;
static void printChar(int ch){
  int par[3];
  prpos++;par[0]=CHFILEpar(PRINTFILE);par[1]=ch;Aputchar(par);
}
static void nlcr(void){
  if(prpos<=1){prpos=1;}
  else{prpos=0;printChar('\n');}
}
static void tabLine(int pos){
  nxt: if(prpos==pos){;}
  else if(prpos>pos){nlcr();goto nxt;}
  else{ printChar(' ');goto nxt;}
}
static void printInt1(int n,int c){
  int q,r;
  r=n%10;q=(n-r)/10;if(q==0){;}else{printInt1(q,'0');}
  printChar(r+c);
}
#include <limits.h>
static void printInt(int n){
  if(n==INT_MIN){printChar('-');n=-1-n;printInt1(n,'1');}
  else if(n<0){printChar('-');n=-n;printInt1(n,'0');}
  else{printInt1(n,'0');}
}
static void printForm1(int n,int m){
  int q,r;
  if(m==0){;}
  else{m--;r=n%10;q=(n-r)/10;printForm1(q,m);printChar(r+'0');}
}
static void printForm(int n){
  printForm1(n,4);
}
static void print(int *a){/* t[]+>p */
  int par[3];
  if(was(a)){par[0]=CHFILEpar(PRINTFILE);par[1]=a[0];par[2]=a[1];
  Aputstring(par);par[0]=a[0];par[1]=a[1];stringlength(par);
  prpos+=par[2];}
}
void printPointer(int *a){
  int par[3];
  if(a[0]==0){par[0]=STACKpar(MESSAGE);par[1]=std_null;print(par);}
  else if(par[0]=STACKpar(MESSAGE),par[1]=a[0],was(par)){
    par[0]=STACKpar(MESSAGE);par[1]=a[0];print(par);}
  else if(par[0]=STACKpar(STDARG),par[1]=a[0],was(par)){
    par[0]=STACKpar(STDARG);par[1]=a[0];print(par);}
  else if(par[0]=STACKpar(BOLD),par[1]=a[0],was(par)){
    par[0]=STACKpar(BOLD);par[1]=a[0];print(par);}
  else{internalError(__FILE__,__LINE__);}
}
static void printBase(int *a){/* >str */
  int par[4];int obuff,ptr;
  obuff=BUFFER->aupb;par[0]=STACKpar(LEXT);par[1]=a[0];
  if(was(par)){par[0]=a[0];getTagImage(par);a[0]=par[1];
    par[0]=STACKpar(LEXT);par[1]=a[0];par[2]=STACKpar(BUFFER);
    unpackstring(par);}
  else if((par[0]=STACKpar(STDARG),was(par))){
    par[0]=STACKpar(STDARG);par[1]=a[0];par[2]=STACKpar(BUFFER);
    unpackstring(par);}
  else{internalError(__FILE__,__LINE__);}
  ptr=BUFFER->aupb;nxt1:if(ptr<=obuff){;}
  else if(BUFFER->offset[ptr]=='/'||BUFFER->offset[ptr]=='\\'
         ||BUFFER->offset[ptr]==':'){;}
  else{ptr--;goto nxt1;}ptr++;nxt2:
  if(BUFFER->aupb<ptr){;}
  else if(BUFFER->offset[ptr]=='.'){;}
  else{ printChar(BUFFER->offset[ptr]);ptr++;goto nxt2;}
  par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
}
static void printItem(int *a){/* item */
  int par[4];int line,source,module;
  par[0]=a[0];findItemLineno(par);line=par[1];source=par[2];module=par[3];
  if(line<=0){;}else{printForm(line-1);}
  if(source==Squoteimage){;}else{printChar('/');par[0]=source;printBase(par);}
  printChar(' ');printChar('(');par[0]=module;printPointer(par);
  printChar(')');
}
static void printLine(int *a){/* line */
  int par[4];int line,source;
  par[0]=a[0];findLineno(par);line=par[1];source=par[2];
  if(line<=0){;}else{printForm(line-1);}
  if(source==Squoteimage){;}else{printChar('/');par[0]=source;printBase(par);}
}
#define SHIFT	cnt--;a++
static void formatPrint(int cnt,int *a){
  int par[4];int optr,ptr;
  optr=BUFFER->aupb;par[0]=STACKpar(MESSAGE);par[1]=a[0];par[2]=STACKpar(BUFFER);
  unpackstring(par);ptr=optr+1;nxt:
  if(BUFFER->aupb<ptr){;}
  else if(BUFFER->offset[ptr]!='%'){printChar(BUFFER->offset[ptr]);ptr++;goto nxt;}
  else{ptr++;if(BUFFER->aupb<ptr){printChar('%');}
   else{int t=BUFFER->offset[ptr];
    if(t=='p'){if(cnt>0){SHIFT;par[0]=a[0];printPointer(par);}else{
      par[0]=STACKpar(MESSAGE);par[1]=std_q;print(par);} ptr++;goto nxt;}
    else if(t=='i'){ if(cnt>0){SHIFT;par[0]=a[0];printItem(par);}else{
      par[0]=STACKpar(MESSAGE);par[1]=std_q;print(par);} ptr++;goto nxt;}
    else if(t=='f'){if(cnt>0){SHIFT;printForm(a[0]);}else{
      par[0]=STACKpar(MESSAGE);par[1]=std_q;print(par);} ptr++;goto nxt;}
    else if(t=='l'){if(cnt>0){SHIFT;par[0]=a[0];printLine(par);}else{
      par[0]=STACKpar(MESSAGE);par[1]=std_q;print(par);} ptr++;goto nxt;}
    else if(t=='d'){if(cnt>0){SHIFT;printInt(a[0]);}else{
      par[0]=STACKpar(MESSAGE);par[1]=std_q;print(par);} ptr++;goto nxt;}
    else{printChar(t);ptr++;goto nxt;}}}
  if(cnt>1){par[0]=STACKpar(MESSAGE);par[1]=std_dots;print(par);}
  par[0]=STACKpar(BUFFER);par[1]=optr;unstackto(par);
}
#undef SHIFT
static int errorNo=0;
#define maximalErrors	51
#define messageCol	16

int wasError(void){
  return errorNo>0?1 : 0;
}

static void messageHead(int M){
  int par[3];
  nlcr();printChar(M);printChar(' ');getObjFile(par);
  if(par[0]==0){;}else{printBase(par);}
  tabLine(messageCol);
}
void error(int n,int *a){/* + * +>mess */
  int par[1];
  messageHead('E');formatPrint(n,a);nlcr();
  errorNo++;if(errorNo<maximalErrors){;}
  else{par[0]=too_many_errors;Ferror(1,par);}
}
void warning(int n,int *a){
  messageHead('W');formatPrint(n,a);nlcr();
}
void Ferror(int n,int *a){
  messageHead('F');formatPrint(n,a);nlcr();
  cleanUp();exit(1);
}
void internalError(const char*file,int line){
  int par[2];
  messageHead('F');par[0]=fatal_head;par[1]=line;formatPrint(2,par);
   printf("%s",file);par[0]=fatal_tail;formatPrint(1,par);nlcr();
   cleanUp();exit(2);
}
void corruptedObjFile(const char*file,int line){
  int par[2];
  messageHead('F');par[0]=corrupted_head;par[1]=line;formatPrint(2,par);
  printf("%s",file);par[0]=fatal_tail;formatPrint(1,par);nlcr();
  cleanUp();exit(1);
}
/* ----------------------------------------------------- */

void initialize_error(void){
  init_MSG();
}

/* EOF */