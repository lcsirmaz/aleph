/* symbols.ale */

#include "stddata.h"
#include "symbols.h"
#include "display.h"
#include "lexical.h"
#include "tags.h"
#include "disc.h"

/* -------------------------------------------------------- */
static int too_large_backtrack,inserted,text_skipped;

#define addMSG(x,y)  add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void add_messages(void){
  addMSG("too large backtrack, aborting",too_large_backtrack);
  addMSG("symbol %p is inserted",inserted);
  addMSG("program text skipped until the next point",text_skipped);
}
#undef addMSG

/* ----------------------------------------------------- */
static int readFromRestore(void);
static void setSymbolPosition(void);
static void countRestore(int *a);

/* ----------------------------------------------------- */
static int linenum=0;
int inpt=0;
/* restore facility */
#define restoresize	500
static int inrestore,outrestore,restoreCount=0,
 oldRestore=0,doRestore=0,oldInpt=0,oldLinenum=0;

static void clear_restore_stack(void){
  int par[4];int i;
  par[0]=STACKpar(RESTORE);par[1]=1;par[2]=par[3]=0;
  for(i=0;i<restoresize;i++)expandstack(par);
  inrestore=outrestore=RESTORE->alwb;
}

void initRestore(void){
  if(doRestore){printf("problem in initRestore\n");exit(23);}
  oldRestore=outrestore;oldInpt=inpt;oldLinenum=linenum;doRestore=1;
}
void makeRestore(void){
  if(!doRestore){printf("problem in makeRestore\n");exit(24);}
  if(restoreCount>=restoresize){printf("restoreCount too large\n");exit(25);}
  outrestore=oldRestore;inpt=oldInpt;linenum=oldLinenum;doRestore=0;
}
void forgetRestore(void){
  makeRestore(); nxt:
  if(readFromRestore()){setSymbolPosition();goto nxt;}
}
static void saveToRestore(void){
  int par[1];
  if(!doRestore){return;}
  if(outrestore!=inrestore){printf("problem in saveToRestore\n");exit(25);}
  restoreCount++;par[0]=inrestore;countRestore(par);inrestore=par[0];
  outrestore=inrestore;RESTORE->offset[inrestore]=inpt;
}
static int readFromRestore(void){
  int par[1];
  if(inrestore==outrestore){ return 0; }
  par[0]=outrestore;countRestore(par);outrestore=par[0];
  inpt=RESTORE->offset[outrestore];
  if(doRestore){;}else{restoreCount--;}
  if(restoreCount>=0){;}else{printf("problem in readFormRestore\n");exit(25);}
  return 1;
}
static void countRestore(int *a){
  if(a[0]>=RESTORE->aupb){a[0]=RESTORE->alwb;}
  else{a[0]++;}
}
/* --------------------------------------------------------- */
static void setSymbolPosition(void){
  int par[1];
  if(inpt==Seol){linenum++;if(doRestore){;}else{par[0]=Dline;D(par);}}
}
void nextSymbol(void){
  int par[1]; nxt:
  if(readFromRestore()){;}else{Aread(par);inpt=par[0];saveToRestore();}
  setSymbolPosition();
  if(inpt==Seol){goto nxt;}
//DEBUGk
//printf("next symbol: %d ",inpt); 
//if(SPECIAL->alwb<inpt && inpt<=SPECIAL->aupb){par[0]=inpt;printPointer(par);}
//if(TTAG->alwb<inpt&&inpt<=TTAG->aupb){par[0]=inpt;printPointer(par);}
//printf("\n");
}
int R(int *a){ /* >x */
  if(a[0]==inpt){nextSymbol(); return 1;}
  return 0;
}
void Rskip(int *a){ /* >symbol */
  int par[2];
  if(a[0]==inpt){nextSymbol();}
  else{par[0]=STACKpar(LADM);par[1]=a[0];
   if(was(par) && inpt==LADM->offset[a[0]-LADM_tag]){nextSymbol();}}
}
void must(int *a){ /* >symbol */
  int par[2];
  if(a[0]==inpt){nextSymbol();}
  else{par[0]=inserted;par[1]=a[0];Error(2,par);}
}
int isRawTag(int *a){ /* tag> */
  int par[2];par[0]=STACKpar(TTAG);par[1]=inpt;if(was(par)){
    a[0]=inpt;nextSymbol();return 1;}
  return 0;
}
int isCons(int *a){ /* value> */
  int par[2];par[0]=STACKpar(CONST);par[1]=inpt;if(was(par)){
    a[0]=CONST->offset[inpt];nextSymbol();return 1;}
  return 0;
}
int aheadCons(void){
  int par[2];par[0]=STACKpar(CONST);par[1]=inpt;return was(par);
}
int isString(int *a){ /* str> */
  int par[2];par[0]=STACKpar(LEXT);par[1]=inpt;if(was(par)){
    a[0]=inpt;nextSymbol(); return 1;}
  return 0;
}
int isTagdl(int *a){ /* tag> + dl> */
  int par[2];par[0]=STACKpar(TTAG);par[1]=inpt;if(was(par)){
    if(inrestore==outrestore){par[0]=inpt;par[1]=linenum;addDICT(par);}
    a[1]=linenum;par[0]=inpt;getTagEntry(par);a[0]=par[1];nextSymbol();
    return 1;
  }
  return 0;
}
int isTag(int *a){ /* tag> */
  int par[2];par[0]=STACKpar(TTAG);par[1]=inpt;if(was(par)){
    if(inrestore==outrestore){par[0]=inpt;par[1]=linenum;addDICT(par);}
    par[0]=inpt;getTagEntry(par);a[0]=par[1];nextSymbol();return 1;
  }
  return 0;
}
/* ------------------------------------------------ */
/* skip */
static void skipSymbol(void){
  int par[1];nxt:
  if(readFromRestore()){;}else{skip(par);inpt=par[0];saveToRestore();}
  setSymbolPosition();
  if(inpt==Seol){goto nxt;}
}
void skipSilently(void){
  nxt:if(ahead(Spoint)){;}else if(ahead(Sendsymb)){;}
  else{skipSymbol();goto nxt;}
}
void skipAll(void){
  int par[1];
  if(ahead(Spoint)){;}else{par[0]=text_skipped;message(1,par);
//printf("a\n");TTAG->offset[0]=0;
    skipSilently();}
}
void skipToPoint(void){
  int par[1];
  skipAll();par[0]=Spoint;Rskip(par);
}
/* --------------------------------- */
void getLinenum(int *a){ /* x> */
  a[0]=linenum; }
void setLinenum(int *a){linenum=a[0];}
void advanceLinenum(void){int par[1];linenum++;par[0]=Dline;D(par);}
/* -------------------------------- */
/* initialize all */
void initialize_symbols(void){
  add_messages();
  clear_restore_stack();
}


/* EOD */

