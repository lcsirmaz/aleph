/* main.c */
#include "stddata.h"
#include "data.h"
#include "input.h"
#include "lexical.h"
#include "item.h"
#include "input.h"
#include "error.h"


static void passi(void){
  int par[2];int ext;
  nxt:par[0]=0;if(wasError()){;}
  else if(nextSource(par)){ext=par[1];par[0]=ext;
     headSection(par);itemSection();dataSection();goto nxt;}
  else{checkAllItems();looseEvaluation();}
}

int main(int argc,char *argv[]){
  initialize_stdstacks(argc,argv);
  initialize_stdfiles();
  initialize_data();
  initialize_error();
  initialize_input();
  initialize_item();
  initialize_lexical();
  /* ---------------------- */
  passi();
  return 0;
}