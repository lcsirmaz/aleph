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

static void skipSource(void){
  int par[2];
  if(Qcons(par)){;}
  else if((par[0]=Dlwb,Q(par))||(par[0]=Dupb,Q(par))||
    (par[0]=Dvlwb,Q(par))||(par[0]=Dvupb,Q(par))||(par[0]=Dcalibre,Q(par))){
    mustQtag(par);}
  else if((par[0]=Dsub,Q(par))){skipSource();par[0]=Dbus;mustQ(par);mustQtag(par);
    if(Qtag(par)){;}else{mustQcons(par);}}
  else if((par[0]=Dnoarg,Q(par))){;}
  else{mustQtag(par);}
}
static void skipAffixes(void){
  int par[1];next:par[0]=Dplus;if(Q(par)){skipSource();goto next;}
}
static void classification(void),alternative(void),
  altSequence(void),member(void),checkMacroRule(int *a);

static void ruleBody(void){
  int par[1];
  par[0]=Dlabel;if(Q(par)){mustQtag(par);}
  par[0]=Dlocal;if(Q(par)){par[0]=Dcolon;Qskip(par);}
  par[0]=Dbox;if(Q(par)){par[0]=Dbox;Qskip(par);classification();}
  else{altSequence();}
}
static void classification(void){
  int par[1];nxt:
  par[0]=Darea;mustQ(par);par[0]=Darea;Qskip(par);par[0]=Dcomma;mustQ(par);
  alternative();par[0]=Dsemicolon;if(Q(par)){goto nxt;}
}
static void alternative(void){
  int par[1];nxt:
  member();par[0]=Dcomma;if(Q(par)){goto nxt;}
}
static void altSequence(void){
  int par[1];nxt:
  alternative();par[0]=Dsemicolon;if(Q(par)){goto nxt;}
}
static void member(void){
  int par[2];int tag;
  par[0]=Dopen;if(Q(par)){ruleBody();par[0]=Dclose;mustQ(par);return;}
  par[0]=Dextension;if(Q(par)){par[0]=Dextension;Qskip(par);return;}
  par[0]=Djump;if(Q(par)){mustQtag(par);return;}
  par[0]=Dplus;if(Q(par)){return;}
  par[0]=Dminus;if(Q(par)){return;}
  mustQtag(par);tag=par[0];par[1]=rmacro;if(isTagFlag(par)){
    par[0]=tag;checkMacroRule(par);}skipAffixes();
}
static void checkMacroRule(int *a){ /* >tag */
  int par[3];int dpos,dnum,mp,mn;
  par[0]=a[0];par[1]=rmchecked;if(isTagFlag(par)){return;}
  par[0]=a[0];par[1]=rmchecking;if(isTagFlag(par)){
    par[0]=recursive_macro_call;par[1]=a[0];Error(2,par);
    par[0]=a[0];par[1]=rmchecking;clearTagFlag(par);
    par[0]=a[0];par[1]=rmchecked;setTagFlag(par); return;}
  par[0]=a[0];par[1]=rmchecking;setTagFlag(par);saveDiscPosition(par);
  dpos=par[0];dnum=par[1];par[0]=a[0];searchMacroRule(par);
  mp=par[1];mn=par[2];par[0]=mp;par[1]=mn;restoreDiscPosition(par);
  ruleBody();par[0]=a[0];par[1]=rmchecking;clearTagFlag(par);
  par[0]=a[0];par[1]=rmchecked;setTagFlag(par);par[0]=dpos;par[1]=dnum;
  restoreDiscPosition(par);
}

void mCheckMacroRules(void){
   int par[3];int tag;
   tag=0;nxt:par[0]=tag;if(nextMacroRule(par)){tag=par[0];
     checkMacroRule(par);goto nxt;}
}

/* --------------------------------------------- */

void initialize_mcheck(void){
   init_msg();
}

/* EOF */

