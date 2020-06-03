/* main.c */
#include "stddata.h"
#include "data.h"
#include "input.h"
#include "lexical.h"
#include "item.h"
#include "input.h"
#include "error.h"
#include "target.h"
#include "rule.h"


static void passi(void){
  int par[2];int ext;
  nxt:par[0]=0;if(wasError()){;}
  else if(nextSource(par)){ext=par[1];par[0]=ext;
     headSection(par);itemSection();dataSection();goto nxt;}
// printf("read all, checking ...\n");
  else{ advanceBaseItem(par);checkAllItems();looseEvaluation();looseBounds(); }
}

static void passii(void){
  int par[2];
  nxt:advanceBaseItem(par);/* ext=par[0]; */
  if(nextSource(par)){skipHeadSection();skipItemSection();dataSectionII();goto nxt;}
  if(wasError()){;}
  else{distributeVirtualAddress();finalizePointerConstants();finalEvaluation();
       assignReprNumbers();
//       openTarget();dataDeclaration();
  /* DEBUG printBounds(); */
  }
}
static void passiii(void){
  int par[2];
  openTarget();targetPrelude();dataDeclaration();
  fillTableHead();
  nxt:advanceBaseItem(par); /* ext=par[0]; */
  if(nextSource(par)){skipHeadSection();skipItemSection();dataSectionIII();goto nxt;}
  fillTableTail();
  dataInitialization();targetMain();
}

static void passiv(void){
  int par[2];
  nxt:advanceBaseItem(par);
  if(nextSource(par)){skipHeadSection();skipItemSection();dataSectionIV();goto nxt;}
}

int main(int argc,char *argv[]){
  initialize_stdstacks(argc,argv);
  initialize_stdfiles();
  initialize_data();
  initialize_error();
  initialize_input();
  initialize_target();
  initialize_rule();
  initialize_lexical(); /* target adds strings to LEXT to be hash-ed */
  initialize_item(); /* this relies on Itable to be defined */
  rehash_lexical();  /* thus we have to postpone rehash() */
  /* ---------------------- */
  passi();
  if(wasError()){return 1;}
  passii();
  if(wasError()){return 1;}
  passiii();
  if(wasError()){return 1;}
  passiv();
  return 0;
}

/* EOF */
