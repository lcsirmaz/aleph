/* mcheck.ale */

#include "stddata.h"
#include "mcheck.h"
#include "display.h"
#include "disc.h"
#include "tags.h"

static int recursive_macro_call;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_msg(void){
  addMSG("rule %p: unbounded macro substitution",recursive_macro_call);
}
#undef addMSG

static void checkMacro(int *a){
  int par[3];
  par[0]=a[0];searchMacroRule(par);par[0]=par[1];par[1]=par[2];
  restoreDiscPosition(par); /* ruleBody() */
}

void mCheckMacroRules(void){
   int par[3];int tag;
   tag=0;nxt:par[0]=tag;if(nextMacroRule(par)){tag=par[0];
      par[0]=tag;par[1]=rmchecked;if(isTagFlag(par)){;}
      else if((par[1]=rmchecking,isTagFlag(par))){
        par[0]=recursive_macro_call;par[1]=tag;Error(2,par);}
      else{par[1]=rmchecking;setTagFlag(par);par[0]=tag;checkMacro(par);
        par[0]=tag;par[1]=rmchecking;clearTagFlag(par);
        par[0]=tag;par[1]=rmchecked;setTagFlag(par);}
      goto nxt;}
}


void initialize_mcheck(void){
   init_msg();
}

/* EOF */

