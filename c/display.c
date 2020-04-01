/* display.ale private part */

/* header files */
#include "stddata.h"
#include "display.h"
#include "lexical.h"
#include "input.h"
#include "pragmats.h"
#include "types.h"
#include "tags.h"

/* error message, standard strings */

static int internal_error_message=0;
static int std_null=0,std_qopen=0,std_qclose=0,std_dots,
           std_missing=0,std_missingm=0,std_newline=0;

/* initialization */
void initialize_display(void)
{ add_new_string("internal error: ",MESSAGE);
  internal_error_message=MESSAGE->aupb;
  /* strings in format print */
  add_new_string("[NULL]",MESSAGE);std_null=MESSAGE->aupb;
  add_new_string("[?",MESSAGE);std_qopen=MESSAGE->aupb;
  add_new_string("]",MESSAGE);std_qclose=MESSAGE->aupb;
  add_new_string("[...]",MESSAGE);std_dots=MESSAGE->aupb;
  add_new_string("[?]",MESSAGE);std_missing=MESSAGE->aupb;
  add_new_string("[m?]",MESSAGE);std_missingm=MESSAGE->aupb;
  add_new_string("<newline>",MESSAGE);std_newline=MESSAGE->aupb;
}

/* forward declarations */
static void printInt1(int *a);
static void printForm1(int *a);

/* ************************************** */
#define T	1
#define F	0

#define countCol	2
#define progCol		9

static int prpos=0,oldPrpos=1,prposOK=1,prline=0;

static void printChar(int *a){ /* >ch */
  int par[2]; prpos++;
  par[0]=CHFILEpar(PRINTFILE);par[1]=a[0];Aputchar(par);
}
static void nlcr(void){
  int par[1];
  if(prpos<=1){prpos=1;}
  else{prpos=0;par[0]=newline;printChar(par);}
}
static void tabLine(int *a){ /* >pos */
  int par[1]; again:
  if(prpos==a[0]){;}
  else if(prpos>a[0]){nlcr(); goto again; }
  else{par[0]=' ';printChar(par);goto again;}
}
#include <values.h> /* MININT */
static void printInt(int *a){ /* >n */
  int par[3];
  if(a[0]==MININT){par[0]='-';printChar(par);par[0]=-1;par[1]=a[0];
    subtr(par);a[0]=par[2];
    par[0]=a[0];par[1]='1';printInt1(par);}
  else if(a[0]<0){par[0]='-';printChar(par);par[0]=a[0];getabs(par);
    a[0]=par[1];par[0]=a[0];par[1]='0';printInt1(par);}
  else{par[0]=a[0];par[1]='0';printInt1(par);}
}
static void printInt1(int *a){ /* >n+>c */
  int par[4];int q,r;
  par[0]=a[0];par[1]=10;divrem(par);q=par[2];r=par[3];
  if(q==0){;}else{par[0]=q;par[1]='0';printInt1(par);}
  r=r+a[1];par[0]=r;printChar(par);
}
static void printForm(int *a){ /* >n */
  int par[2];par[0]=a[0];par[1]=4;printForm1(par);
}
static void printForm1(int *a){/* >n+>m */
  int par[4];int q,r;
  if(a[1]==0){;}
  else{a[1]--;par[0]=a[0];par[1]=10;divrem(par);q=par[2];r=par[3];
   par[0]=q;par[1]=a[1];printForm1(par);r=r+'0';par[0]=r;printChar(par);}
}
//DEBUG !!!
void print(int *a){ /* +t[]+>p */
  int par[4];
//printf("[str=%d,ptr=%d]\n",a[0],a[1]);
  par[0]=a[0];par[1]=a[1];if(was(par)){par[0]=CHFILEpar(PRINTFILE);
    par[1]=a[0];par[2]=a[1];Aputstring(par);par[0]=a[0];par[1]=a[1];
    stringlength(par);prpos+=par[2];}
}
void resetPrLine(void){
  prline=0;nlcr();
} 
static void savePrpos(void){
  if(prposOK){prposOK=0;oldPrpos=prpos;}
}
static void printLineHead(int *a){ /* >show */
  int par[2];
  if(a[0]){nlcr();par[0]=countCol;tabLine(par);par[0]=prline;
    printForm(par);par[0]=progCol;tabLine(par);}
}
void displayChar(int *a){ /* >char + >show */
  int par[2];
  if(a[0]==newline){prline++;prposOK=T;par[0]=a[1];printLineHead(par);}
  else if(a[1]){if(prposOK){;}else{prposOK=1;par[0]=oldPrpos;tabLine(par);}
    par[0]=a[0];printChar(par);}
}
/* formatted printing */
static void printBase(int *a){ /* >str */
  int par[4];int obuff,ptr;
  obuff=BUFFER->aupb;par[0]=STACKpar(LEXT);par[1]=a[0];par[2]=STACKpar(BUFFER);
    unpackstring(par);ptr=BUFFER->aupb;nxt1:
    if(ptr<=obuff){;}else if(BUFFER->offset[ptr]=='/'){;}
    else if(BUFFER->offset[ptr]=='\\'){;}
    else if(BUFFER->offset[ptr]==':'){;}
    else{ptr--;goto nxt1;}
    ptr++;nxt2:
    if(BUFFER->aupb<ptr){;}else if(BUFFER->offset[ptr]=='.'){;}
    else{par[0]=BUFFER->offset[ptr];printChar(par);ptr++;goto nxt2;}
    par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
}
static void printSourceLine(int *a){ /* >n */
  int par[3]; int n,str;
  if(a[0]==0){par[0]='0';printChar(par);}
  else{par[0]=a[0];findLinenum(par);n=par[1];str=par[2];
   par[0]=n;printForm(par);par[0]='/';printChar(par);par[0]=str;
   printBase(par);}
}
/* static void printPointer(int *a){ */
void printPointer(int *a){ /* >ptr */
  int par[3];int v;
  if(a[0]==0){par[0]=STACKpar(MESSAGE);par[1]=std_null;print(par);}
  else if((par[0]=STACKpar(MESSAGE),par[1]=a[0],was(par))){
    par[0]=STACKpar(MESSAGE);par[1]=a[0];print(par);}
  else if((par[0]=STACKpar(DSYMB),par[1]=a[0],was(par))){
    par[0]=STACKpar(DSYMB);par[1]=a[0];print(par);}
  else if((par[0]=a[0],par[1]=STACKpar(BUFFER),wasLexicalPointer(par)) ||
   (par[0]=a[0],par[1]=STACKpar(BUFFER),wasTagPointer(par))||
   (par[0]=a[0],par[1]=STACKpar(BUFFER),wasTypePointer(par))){
     par[0]=STACKpar(BUFFER);par[1]=BUFFER->aupb;print(par);
     par[0]=STACKpar(BUFFER);unstackstring(par);}
  else if((par[0]=a[0],wasLexicalInteger(par))){v=par[1];par[0]=v;
     printInt(par);}
  else{par[0]=STACKpar(MESSAGE);par[1]=std_qopen;print(par);par[0]=a[0];
    printInt(par);par[0]=STACKpar(MESSAGE);par[1]=std_qclose;print(par);}
}
static void pushBUFFER(int *a){
  int par[2]; par[0]=STACKpar(BUFFER);par[1]=a[0];extend(par);}
static void popBUFFER(int *a){
  int par[1];a[0]=BUFFER->offset[BUFFER->aupb];par[0]=STACKpar(BUFFER);unstack(par);}
#define SHIFT_AFFIX(cnt,v)  cnt--;v++
static void formatPrint(int cnt,int *v){/* *+>fmt */
  int par[4];int optr,ptr,level;
  level=0;again:
  optr=BUFFER->aupb;par[0]=STACKpar(MESSAGE);par[1]=v[0];
  par[2]=STACKpar(BUFFER);unpackstring(par);ptr=optr;ptr++;nxt:
  if(BUFFER->aupb<ptr){if(level>0){level--;par[0]=STACKpar(BUFFER);
    par[1]=optr;unstackto(par);popBUFFER(par);optr=par[0];
    popBUFFER(par);ptr=par[0];
     goto nxt;
    }}
  else if(BUFFER->offset[ptr]!='%'){par[0]=BUFFER->offset[ptr];
    printChar(par);ptr++;goto nxt;}
  else{ptr++;if(BUFFER->aupb<ptr){par[0]='%';printChar(par);}
    else if(BUFFER->offset[ptr]=='d'){if(cnt>1){SHIFT_AFFIX(cnt,v);
       par[0]=v[0];printInt(par);}else{par[0]=STACKpar(MESSAGE);
       par[1]=std_missing;print(par);}}
    else if(BUFFER->offset[ptr]=='c'){if(cnt>1){SHIFT_AFFIX(cnt,v);
       if(v[0]==newline){par[0]=STACKpar(MESSAGE);par[1]=std_newline;print(par);}
       else{par[0]=v[0];printChar(par);}}else{par[0]=STACKpar(MESSAGE);
       par[1]=std_missing;print(par);}}
    else if(BUFFER->offset[ptr]=='l'){if(cnt>1){SHIFT_AFFIX(cnt,v);
       par[0]=v[0];printSourceLine(par);}else{par[0]=STACKpar(MESSAGE);
       par[1]=std_missing;print(par);}}
    else if(BUFFER->offset[ptr]=='p'){if(cnt>1){SHIFT_AFFIX(cnt,v);
       par[0]=v[0];printPointer(par);}else{par[0]=STACKpar(MESSAGE);
       par[1]=std_missing;print(par);}}
    else if(BUFFER->offset[ptr]=='m'){if(cnt>1){SHIFT_AFFIX(cnt,v);
       ptr++;par[0]=ptr;pushBUFFER(par);par[0]=optr;pushBUFFER(par);level++;goto again;}
       else{par[0]=STACKpar(MESSAGE);par[1]=std_missingm;print(par);}}
    else if(BUFFER->offset[ptr]=='*'){if(cnt>1){SHIFT_AFFIX(cnt,v);}}
    else{par[0]=BUFFER->offset[ptr];printChar(par);}
    ptr++;goto nxt;}
  if(cnt>1){par[0]=STACKpar(MESSAGE);par[1]=std_dots;print(par);}
  par[0]=STACKpar(BUFFER);par[1]=optr;unstackto(par);
}
#undef SHIFT_AFFIX_BLOCK
/* --------------------------------------------- */
/* dictioary printing */
static int lastDictSrc=0,rightHandMargin=120;
static void DICTtab(void){
  int par[4];again:
  if(prpos>rightHandMargin){par[0]=8;tabLine(par);}
  else{par[0]=' ';printChar(par);par[0]=prpos;par[1]=6;divrem(par);
    if(par[3]==1){;}else{goto again;}}
}
void DICTheader(int *a){/* >tag + >defline */
  int par[4];int l;
  nlcr();lastDictSrc=0;par[0]=pgtMargin;getPragmatValue(par);
  rightHandMargin=par[1];par[0]=a[0];printPointer(par);
  par[0]=' ';printChar(par);
  if(prpos<8){par[0]=8;tabLine(par);}
  if(a[1]<=0){;}else{par[0]=a[1];findLinenum(par);l=par[1];lastDictSrc=par[2];
    par[0]=lastDictSrc;printBase(par);par[0]=':';printChar(par);
    par[0]=l;printForm(par);par[0]='*';printChar(par);}
}
void DICTitem(int *a){/* >line */
  int par[4];int src,l;
  par[0]=a[0];findLinenum(par);l=par[1];src=par[2];
  if(src==lastDictSrc){;}else{lastDictSrc=src;DICTtab();
    par[0]=lastDictSrc;printBase(par);par[0]=':';printChar(par);}
  DICTtab();par[0]=l;printForm(par);
}
void DICTtail(void){ nlcr(); }

/* ************************************************************************* */
/* Error messages */

/* local variables */
static int errorNo=0,localErrorNo=0;

int wasError(void){if(errorNo>0){return 1;} return 0;}
void getErrorNo(int *a){a[0]=errorNo;}
void clearLocalError(int *a){ /* old> */
  a[0]=localErrorNo;localErrorNo=0;
}
int wasLocalError(int *a){ /* >old */
  int x=localErrorNo;
  localErrorNo=a[0]+x;if(x>0){return 1;}
  return 0;
}
#define lineCol		4
#define messCol		22

static void messageHeader(int *a){ /* >line + >level */
  /* line=-1: most recent; 0: none; >0: use this */
  int par[3];
  savePrpos();nlcr();if(a[1]<0){par[0]='I';printChar(par);}
  else if(a[1]<10){par[0]='W';printChar(par);par[0]=a[1]+'0';printChar(par);}
  else{par[0]='E';printChar(par);}
  if(a[0]==0){;}/* no line information */
  else{par[0]=lineCol;tabLine(par);par[0]=a[0];printSourceLine(par);}
  par[0]=messCol;tabLine(par);
}
void Error(int cnt,int *v){
  int par[2];
  errorNo++;localErrorNo++;par[0]=-1;par[1]=10;messageHeader(par);
  formatPrint(cnt,v);nlcr();
}
void Xerror(int line,int cnt,int *v){
  int par[2];
  errorNo++;localErrorNo++;par[0]=line;par[1]=10;messageHeader(par);
  formatPrint(cnt,v);nlcr();
}
void Warning(int level,int cnt,int *v){ /* >level+*+>mess */
  int par[2];
  par[0]=pgtWarningLevel;getPragmatValue(par);if(level<par[1]){;}
  else{par[0]=-1;par[1]=level;messageHeader(par);
    formatPrint(cnt,v);nlcr();}
}
void Xwarning(int line,int level,int cnt,int *v){ /* >level+*+>mess */
  int par[2];
  par[0]=pgtWarningLevel;getPragmatValue(par);
//printf("Xwarning, level=%d, pragmat=%d\n",level,par[1]);
  if(level<par[1]){;}
  else{par[0]=line;par[1]=level;messageHeader(par);
    formatPrint(cnt,v);nlcr();}
}
void message(int cnt,int *v){
  int par[2];
  par[0]=-1;par[1]=-1;messageHeader(par);formatPrint(cnt,v);nlcr();
}
void internalError(int cnt,int *a){ /* +*+>mess */
  int par[3];
  par[0]=0;par[1]=10;messageHeader(par);par[0]=STACKpar(MESSAGE);
  par[1]=internal_error_message;print(par);formatPrint(cnt,a);
  nlcr();a[0]=MESSAGE->offset[0];exit(88);
}

/* EOF */

