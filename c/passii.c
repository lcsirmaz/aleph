/* passii.ale */

#include "stddata.h"
#include "passii.h"
#include "display.h"
#include "disc.h"
#include "tags.h"
#include "types.h"
#include "drules.h"
#include "pragmats.h"
#include "node.h"
#include "obj.h"

/* ---------------------------------------------------- */
/* messages */

static int 
tag_not_defined,cannot_be_public,cannot_be_macro,extrule,imprule,
macro_ignored,unknown_disc_symbol,wrong_pragmat_value;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void add_messages(void){
 addMSG("%p: not defined",tag_not_defined);
 addMSG("%p %p: cannot be public (%l)",cannot_be_public);
 addMSG("%p %p: cannot be macro (%l)",cannot_be_macro);
 addMSG("external rule ",extrule);
 addMSG("imported rule ",imprule);
 addMSG("pragmat macro=%p: ignored",macro_ignored);
 addMSG("pass II, unknown disc symbol",unknown_disc_symbol);
 addMSG("d read pragmat: unknown pragmat number %d",wrong_pragmat_value);
}
#undef addMSG

/* --------------------------------------------------- */
static void dReadPragmat(void),dStoreMacro(int *a);

void passII(void){
  int par[3];nxt:
  par[0]=Drule;if(Q(par)){mustQtag(par);dStoreMacro(par);dCheckRule(par);goto nxt;}
  par[0]=Droot;if(Q(par)){mustQtag(par);dCheckRule(par);goto nxt;}
  par[0]=Dpragmat;if(Q(par)){dReadPragmat();goto nxt;}
  par[0]=Dexpression;if(Q(par)){dExpression();goto nxt;}
  par[0]=Dfile;if(Q(par)){dFileData();goto nxt;}
  par[0]=Dfill;if(Q(par)){dListFilling();goto nxt;}
  par[0]=Dlist;if(Q(par)){dListSize();goto nxt;}
  par[0]=Dend;if(Q(par)){;}
  else{printf("unknown disc symbol\n"); exit(33); }
}
void passIII(void){
  int par[1];nxt:
  par[0]=Drule;if(Q(par)){mustQtag(par);generateRule(par);goto nxt;}
  par[0]=Droot;if(Q(par)){mustQtag(par);generateRule(par);goto nxt;}
  par[0]=Dpragmat;if(Q(par)){mustQcons(par);if(Qcons(par)){;}else{mustQtag(par);};goto nxt;}
  par[0]=Dexpression;if(Q(par)){par[0]=Dpoint;Qskip(par);goto nxt;}
  par[0]=Dfile;if(Q(par)){par[0]=Dpoint;Qskip(par);goto nxt;}
  par[0]=Dfill;if(Q(par)){par[0]=Dpoint;Qskip(par);goto nxt;}
  par[0]=Dlist;if(Q(par)){par[0]=Dpoint;Qskip(par);goto nxt;}
  par[0]=Dend;if(Q(par)){;}
  else{printf("passIII: wrong disc symbol\n");exit(33);}
}
/* ----------------------------------------------------------- */
/* store macros */
static void dStoreMacro(int *a){ /* >tag */
  int par[3];int dpos,dnum;
  if(wasError()){;}
  else{par[0]=a[0];par[1]=rmacro;if(isTagFlag(par)){saveDiscPosition(par);
    dpos=par[0];dnum=par[1];par[0]=a[0];par[1]=dpos;par[2]=dnum;
    linkMacroRule(par);}}
}
/* ----------------------------------------------------------- */
/* pragmats */
static void checkTagForPublic(int *a){ /* >tag */
  int par[4];int dl,type;
  par[0]=a[0];par[1]=tdefined;if(isTagFlag(par)){par[0]=a[0];
    getDefline(par);dl=par[1];par[0]=a[0];getType(par);type=par[1];
    par[0]=a[0];par[1]=texternal;if(isTagFlag(par)){
      par[0]=cannot_be_public;par[1]=type;par[2]=a[0];par[3]=dl;Error(4,par);return;}
    par[0]=a[0];par[1]=timported;if(isTagFlag(par)){
      par[0]=cannot_be_public;par[1]=type;par[2]=a[0];par[3]=dl;Error(4,par);return;}}
  else{par[0]=a[0];par[1]=tpublic;if(isTagFlag(par)){par[0]=tag_not_defined;
      par[1]=a[0];Error(2,par);}}
}
static void checkTagForMacro(int *a){ /* >tag */
  int par[4];int dl,type;
  par[0]=a[0];par[1]=tdefined;if(isTagFlag(par)){
    par[0]=a[0];getDefline(par);dl=par[1];par[0]=a[0];getType(par);type=par[1];
    if(type!=Irule){par[0]=a[0];par[1]=rmacro;clearTagFlag(par);
       par[0]=cannot_be_macro;par[1]=type;par[2]=a[0];
       par[3]=dl;Warning(3,4,par);return;}
    par[0]=a[0];par[1]=texternal;if(isTagFlag(par)){par[0]=a[0];par[1]=rmacro;
      clearTagFlag(par);par[0]=cannot_be_macro;par[1]=extrule;
      par[2]=a[0];par[3]=dl;Warning(3,4,par);return;}
    par[1]=timported;if(isTagFlag(par)){par[0]=a[0];par[1]=rmacro;
      clearTagFlag(par);par[0]=cannot_be_macro;par[1]=imprule;
      par[2]=a[0];par[3]=dl;Error(4,par);return;}}
  else{par[0]=macro_ignored;par[1]=a[0];Warning(3,2,par);}
}
static void dReadPragmat(void){
   int par[3]; int pgt,x;
   mustQcons(par);pgt=par[0];
   if(pgt==pgtWarningLevel){mustQcons(par);x=par[0];par[0]=pgt;par[1]=x;
     setPragmatValue(par);}
   else if(pgt==pgtMacro){mustQtag(par);checkTagForMacro(par);}
   else if(pgt==pgtPublic){mustQtag(par);checkTagForPublic(par);}
   else{par[0]=wrong_pragmat_value;par[1]=pgt,internalError(2,par);}
}
/* ----------------------------------------------------------- */
void initialize_passii(void){
  add_messages();
}



/* EOF */


