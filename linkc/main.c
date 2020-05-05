/* main.c */
#include "stddata.h"
#include "data.h"
#include "input.h"
#include "lexical.h"
#include "item.h"
#include "input.h"
#include "error.h"
#include "target.h"


static void passi(void){
  int par[2];int ext;
  nxt:par[0]=0;if(wasError()){;}
  else if(nextSource(par)){ext=par[1];par[0]=ext;
     headSection(par);itemSection();dataSection();goto nxt;}
// printf("read all, checking ...\n");
  else{ checkAllItems();looseEvaluation();looseBounds(); }
}

static void passii(void){
  int par[2];
  nxt:advanceBaseItem(par);/* ext=par[0]; */
  if(nextSource(par)){skipHeadSection();skipItemSection();dataSectionII();goto nxt;}
  if(wasError()){;}
  else{distributeVirtualAddress();finalizePointerConstants();finalEvaluation();
       assignReprNumbers();openTarget();dataDeclaration();
  /* DEBUG printBounds(); */
  }
}

int main(int argc,char *argv[]){
  initialize_stdstacks(argc,argv);
  initialize_stdfiles();
  initialize_data();
  initialize_error();
  initialize_input();
  initialize_lexical();
  initialize_target();
  initialize_item(); /* should come after lexical() to define StdString */
  /* ---------------------- */
  passi();
  if(wasError()){return 1;}
  passii();
  return 0;
}

/* EOF */
