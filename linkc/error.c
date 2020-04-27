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
 addMSG("internal error at ",fatal_head);
 addMSG(", program aborted",fatal_tail);
 addMSG(".ice file corrupted; found at ",corrupted_head);
 addMSG("[NULL]",std_null);
 addMSG("[?]",std_q);
 addMSG("[...]",std_dots);
}
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
static void printInt1(int n,c){
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
static int printForm1(int n,m){
  int q,r;
  if(m==0){;}
  else{m--;r=n%10;q=(n-r)/10;printForm1(q,m);printChar(r+'0');}
}
static int printForm(int n){
  printForm1(n,4);
}
static int print(int *a){/* t[]+>p */
  int par[3];
  if(was(a)){par[0]=CHFILEpar(PRINTFILE);par[1]=a[0];par[2]=a[1];
  putstring(par);par[0]=a[0];par[1]=a[1];stringlength(par);
  prpos+=par[2];}
}
void printPointer(int *a){
  int par[3];
  if(a[0]==0){par[0]=STACKpar(MESSAGE);par[1]=std_null;print(par);}
  else if(par[0]=STACKpar(MESSAGE),par[1]=a[0],was(par)){
    par[0]=STACKpar(MESSAGE);par[1]=a[0];print(par);}
  else if(par[0]=STACKpar(STDARG),par[1]=a[0],was(par)){
    par[0]=STACKpar(STDARG);par[1]=a[0];print(par);}
  else{internalError(__FILE__,__LINE__);}
}
static void printBase(int *a){/* >str */
  int par[4];int obuff,ptr;
  obuff=BUFFER->aupb;par[0]=STACKpar(LEXT);par[1]=a[0];
  if(was(par)){par[0]=a[0];getTagImage(par);a[0]=par[1];
    par[0]=STACKpar(LEXT);par[1]=a[0];par[2]=STACKpar(BUFFER);
    unpackstring(par);}
  else if((par[0]=STACKpar(STDARG),was(par))){
    par[0]=STACKpar(STDARD);par[1]=a[0];par[2]=STACKpar(BUFFER);
    unpackstrin(par);}
  else{internalError(__FILE__,__LINE__);}
  ptr=BUFFER->aupb;nxt1:if(ptr<=obuff){;}
  else if(BUFFER->offset[ptr]=='/'||BUFFER->offset[ptr]=='\\'
         |BUFFER->offset[ptr]==':'){;}
  else{ptr--;goto nxt1;}nxt2:
  if(BUFFER->aupb>ptr){;}
  else if(BUFFER->offset[ptr]=='.'){;}
  else printChar(BUFFER->offset[ptr]);ptr++;goto nxt2;}
  par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
}

/* ----------------------------------------------------- */

void initialize_error(void){
  init_MSG();
}

/* EOF */