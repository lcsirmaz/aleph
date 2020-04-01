/* rules.ale */

#include "stddata.h"
#include "rules.h"
#include "symbols.h"
#include "tags.h"
#include "types.h"
#include "lexical.h"
#include "disc.h"
#include "display.h"
#include "pragmats.h"
#include "rulebody.h"

/* ============================================= */
/* messages */
static int
wrong_formal_selector,formal_selector_tag_expected,formal_list_tag_missing,
expected,rule_in_affix,formal_tag_expected,in_rule_head,rule_tag_expected,
rule_type_different,formal_type_mismatch,formal_list_calibre_mismatch,
formal_list_ssel_mismatch,double_formal_selector,formal_affix_redefined,
doubly_defined_selector,tag_redefined,extra_affix,missing_formal_affix,
more_repeat_affix,last_repeat_affix,function_without_out_affixes,
exit_rule_with_out_affixes,no_external_string;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void add_messages(void){
 addMSG("formal selector syntax",wrong_formal_selector);
 addMSG("formal selector tag expected",formal_selector_tag_expected);
 addMSG("formal list tag is missing",formal_list_tag_missing);
 addMSG("rule %p: symbol %p is expected here",expected);
 addMSG("rule %p: rule as formal affix",rule_in_affix);
 addMSG("rule %p: formal affix syntax",formal_tag_expected);
 addMSG("rule %p: error in rule head",in_rule_head);
 addMSG("rule tag expected",rule_tag_expected);
 addMSG("rule %p: redefined differenty at %l",rule_type_different);
 addMSG("rule %p: formal affix %p has wrong type (was %p at %l)",formal_type_mismatch);
 addMSG("rule %p: formal list affix %p has different calibre (at %l)",formal_list_calibre_mismatch);
 addMSG("rule %p: formal list affix %p has different standard selector (at %l)",formal_list_ssel_mismatch);
 addMSG("rule %p: formal list affix %p selector %p doubly defined",double_formal_selector);
 addMSG("rule %p: formal affix %p defined twice",formal_affix_redefined);
 addMSG("selector %p in formal list %p is redefined",doubly_defined_selector);
 addMSG("tag %p redefined (was %p at %l)",tag_redefined);
 addMSG("rule %p: extra formal affix (%l)",extra_affix);
 addMSG("rule %p: missing formal affixes (%l)",missing_formal_affix);
 addMSG("rule %p: more than one repeat affix",more_repeat_affix);
 addMSG("rule %p: repeat affix * is the last one",last_repeat_affix);
 addMSG("rule %p: function without out affixes",function_without_out_affixes);
 addMSG("rule %p: exit rule with out affixes",exit_rule_with_out_affixes);
 addMSG("external rule %p: missing string",no_external_string);
}
#undef addMSG

/* ============================================= */
static void mustTag(int *a){/* x> */
  if(isTag(a)){return;}
  fprintf(stderr,"tag must be here\n"); exit(24);
}
/* - - - - - - - - - - - - - - - - - - - - - - - */
static void skipFieldList(int *a){ /* >err> */
  int par[2];
  par[0]=Sopen;if(R(par)){nxt:if(isTag(par)){
    par[0]=Scomma;if(R(par)){goto nxt;}
    par[0]=Sequals;if(R(par)){goto nxt;}
    par[0]=Sclose;if(R(par)){;}
    else{par[0]=wrong_formal_selector;Error(1,par);a[0]=1;}}
    else{par[0]=formal_selector_tag_expected;Error(1,par);a[0]=1;}}
}
static void getListTag(int *a){ /* tag>+>err> */
  int par[2];
  initRestore();par[0]=a[1];skipFieldList(par);a[1]=par[0];
  a[0]=0;if(isTag(par)){a[0]=par[0];}
  else if(a[0]){;}
  else{par[0]=formal_list_tag_missing;Error(1,par);a[1]=1;}
  if(a[1]){forgetRestore();}else{makeRestore();}
}
/* - - - - - - - - - - - - - - - - - - - - - - - */
/* skipover formal affixes */
static void subbus(int *a){/* >tag + >err> */
  int par[3];
  if(a[1]){par[0]=Ssub;Rskip(par);par[0]=Sbus;Rskip(par);}
  else if(par[0]=Ssub,R(par)){par[0]=Sbus;if(R(par)){;}
   else{a[1]=1;par[0]=expected;par[1]=a[0];par[2]=Sbus;Error(3,par);}}
  else{a[1]=1;par[0]=expected;par[1]=a[0];par[2]=Ssub;Error(3,par);}
}
static void expectFormalTag(int *a){ /* >ruletag+>err> */
  int par[2];int tag;
  if(a[1]){isRawTag(par);}
  else if(isTag(par)){tag=par[0];if(tag==a[0]){a[1]=1;
    par[0]=rule_in_affix;par[1]=tag;Error(2,par);}}
  else{a[1]=1;par[0]=formal_tag_expected;par[1]=a[0];Error(2,par);}
}
static void skipFormalAffix(int *a){/* >ruletag + >err> */
  int par[3];
//printf("skip formal affix, looking at %d \"",inpt);par[0]=inpt;printPointer(par);printf("\"\n");
  if(ahead(Ssub)){par[0]=a[0];par[1]=a[1];subbus(par);a[1]=par[1];
   par[0]=a[1];skipFieldList(par);a[1]=par[0];par[0]=a[0];par[1]=a[1];
   expectFormalTag(par);a[1]=par[1];par[0]=a[0];par[1]=a[1];subbus(par);
   a[1]=par[1];}
  else if(ahead(Sopen)){par[0]=a[1];skipFieldList(par);a[1]=par[0];
   par[0]=a[0];par[1]=a[1];expectFormalTag(par);a[1]=par[1];par[0]=a[0];
   par[1]=a[1];subbus(par);a[1]=par[1];}
  else if(par[0]=Squoteimage,R(par)){par[0]=a[0];par[1]=a[1];
    expectFormalTag(par);a[1]=par[1];}
  else if(par[0]=Sright,R(par)){par[0]=a[0];par[1]=a[1];
    expectFormalTag(par);a[1]=par[1];par[0]=Sright;Rskip(par);}
  else if(par[0]=Sasterisk,R(par)){;}
  else{par[0]=a[0];par[1]=a[1];expectFormalTag(par);a[1]=par[1];
   par[0]=Sright;if(R(par)){;}else if(ahead(Ssub)){ par[0]=a[0];
     par[1]=a[1];subbus(par);a[1]=par[1];}else if(ahead(Smreq)){;}
     else if(a[1]){;} else {a[1]=1;par[0]=expected;par[1]=a[0];
     par[2]=Sright;Error(3,par);}}
}
static void peekAfterFormalAffixes(int *a){ /* >ruletag+fast>+>err> */
  int par[2];
  if(a[2]){a[1]=0;return;}
  initRestore();a[1]=0;nxt:par[0]=Splus;
  if(R(par)){par[0]=a[0];par[1]=a[2];skipFormalAffix(par);a[2]=par[1];goto nxt;}
  if(a[2]){;}
  else if(ahead(Spoint)){a[1]=1;}
  else if(ahead(Scomma)){a[1]=1;}
  else if(ahead(Sequals)){a[1]=1;}
  else if(ahead(Smreq)){a[1]=1;}
  else if(ahead(Sminus)){;}
  else if(ahead(Scolon)){;}
  else{par[0]=in_rule_head;par[1]=a[0];Error(2,par);a[2]=1;}
  if(a[2]){forgetRestore();}else{makeRestore();}
 }
/* =============================================================== */
/* formal affixes */
static int repeatAffix=0;
static void checkAsFormal(int *a){/* >rtag+>formal>+>tag+>type+>err> */
  int par[5];int otype,l;
  if(a[4]){return;}
  if(a[1]){par[0]=a[1];getType(par);otype=par[1];if(otype==a[3]){;}
    else{par[0]=a[0];getDefline(par);l=par[1];par[0]=formal_type_mismatch;
     par[1]=a[0];par[2]=a[2];par[3]=otype;par[4]=l;Error(5,par);a[4]=1;}}
  else{par[0]=a[3];par[1]=a[2];newFormalTag(par);a[1]=par[2];}
}
static void defineAsFormal(int *a){ /* >rtag+>formal> + >tag+>type+>err> */
  int par[5];
  if(a[4]){return;}
  par[0]=a[2];if(hasFormalType(par)){a[4]=1;
    par[0]=formal_affix_redefined;par[1]=a[0];par[2]=a[2];Error(3,par);}
  else{par[0]=a[0];par[1]=a[1];par[2]=a[2];par[3]=a[3];par[4]=a[4];
    checkAsFormal(par);a[1]=par[1];a[4]=par[4];if(a[4]){;}
    else if(a[2]==Xstar){repeatAffix=a[1];}
    else{par[0]=a[2];par[1]=a[1];redefineTag(par);}}
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* formal list affix */
static void checkSelectorList(int *a){/* >tag+n>+ssel> */
  int par[2];int sel;
  par[0]=Sopen;if(R(par)){a[1]=1;a[2]=-1;nxt:mustTag(par);sel=par[0];
    if(a[0]==sel){a[2]=a[1];}
    if(par[0]=Scomma,R(par)){a[1]++;goto nxt;}
    else if(par[0]=Sequals,R(par)){goto nxt;}
    else {par[0]=Sclose;must(par);}}
  else{a[1]=-1;a[2]=1;}
}
static void createFormalSelector(int *a){ /* >rtag+>tag+>sel+>offset+>err> */
  int par[5];int fsel,formal;
  if(a[4]){return;}
  par[0]=a[2];par[1]=a[1];packSelector(par);fsel=par[2];par[0]=fsel;
//DEBUG
//printf("create formal, tag=%d, sel=%d, to %d, offs=%d, tag=\"",a[1],a[2],fsel,a[3]);par[0]=a[1];printPointer(par);printf("\"\n");par[0]=fsel;
  if(hasFormalType(par)){par[0]=double_formal_selector;par[1]=a[0];
    par[2]=a[1];par[3]=a[2];Error(4,par);a[4]=1;}
  else{par[0]=IformalSelector;par[1]=fsel;newFormalTag(par);formal=par[2];
    par[0]=formal;par[1]=a[3];putRepr(par);par[0]=fsel;par[1]=formal;
    redefineTag(par);
//DEBUG
//printf("  formal ssel created from %d as=%d \"",fsel,formal);par[0]=formal;printPointer(par);printf("\"\n");
    }
}
static void defineSelectorList(int *a){/* >rtag+>tag+n>+ssel>+>err> */
                                      /*   0     1   2   3      4   */
  int par[5];int sel;
  par[0]=Sopen;if(R(par)){a[2]=1;a[3]=-1;nxt:mustTag(par);sel=par[0];
    if(a[1]==sel){a[3]=a[2];}
    par[0]=a[0];par[1]=a[1];par[2]=sel;par[3]=a[2];par[4]=a[4];
    createFormalSelector(par);a[4]=par[4];par[0]=Scomma;
    if(R(par)){a[2]++;goto nxt;}
    par[0]=Sequals;if(R(par)){goto nxt;}
    par[0]=Sclose;must(par);
    if(a[3]>0){;}
    else{par[0]=a[0];par[1]=a[1];par[2]=a[1];par[3]=-1;par[4]=a[4];
      createFormalSelector(par);a[4]=par[4];}}
  else{
//DEBUG
//printf("creating ssel for %d\n",a[1]);
    a[2]=-1;a[3]=1;par[0]=a[0];par[1]=a[1];par[2]=a[1];par[3]=1;par[4]=a[4];
    createFormalSelector(par);a[4]=par[4];}
}
static void checkFormalListData(int *a){
  /* >rtag + >formal + >tag+ >ftype + >fcal + >fssel + >err> 
       0       1         2     3        4         5      6    */
  int par[5];int ocal,ossel,otype,ol;
  par[0]=a[0];getDefline(par);ol=par[1];par[0]=a[1];getType(par);
  otype=par[1];par[0]=a[1];getFormalCalibre(par);ocal=par[1];
  par[0]=a[1];getFormalSsel(par);ossel=par[1];
  if(a[3]!=otype){par[0]=formal_type_mismatch;par[1]=a[0];
    par[2]=a[2];par[3]=otype;par[4]=ol;Error(5,par);a[6]=1;}
  else if(a[4]!=ocal){par[0]=formal_list_calibre_mismatch;
    par[1]=a[0];par[2]=a[2];par[3]=ol;Error(4,par);a[6]=1;}
  else if(a[5]!=ossel){par[0]=formal_list_ssel_mismatch;
//printf("ssel here:%d; cal was: %d, ssel was:%d\n",a[5],ocal,ossel);
    par[1]=a[0];par[2]=a[2];par[3]=ol;Error(4,par);a[6]=1;}
}
static void checkAsFormalList(int *a){
  /* >rtag + >formal> + >tag + >ftype + >err> 
       0        1         2        3       4  */
  int par[7];int fcal,fssel;
  par[0]=a[2];checkSelectorList(par);fcal=par[1];fssel=par[2];
//printf("check selector list for tag=%d returns cal=%d,sel=%d\n",a[2],fcal,fssel);
  par[0]=a[2];Rskip(par);par[0]=a[0];par[2]=a[4];subbus(par);a[4]=par[2];
  if(a[1]){par[0]=a[0];par[1]=a[1];par[2]=a[2];par[3]=a[3];par[4]=fcal;
    par[5]=fssel;par[6]=a[4];checkFormalListData(par);a[4]=par[6];}
  else{par[0]=a[3];par[1]=a[2];newFormalTag(par);a[1]=par[2];
    par[0]=a[1];par[1]=fcal;putFormalCalibre(par);par[0]=a[1];
    par[1]=fssel;putFormalSsel(par);}
}
static void defineAsFormalList(int *a){
 /* >rtag + >formal> + >tag + >ftype + >err> */
 int par[7];int fcal,fssel;
 par[0]=a[2];if(hasFormalType(par)){a[4]=1;
   par[0]=formal_affix_redefined;par[1]=a[0];par[2]=a[2];Error(3,par);}
 else{par[0]=a[0];par[1]=a[2];par[4]=a[4];defineSelectorList(par);
   fcal=par[2];fssel=par[3];a[4]=par[4];par[0]=a[2];Rskip(par);
   par[0]=a[0];par[1]=a[4];subbus(par);a[4]=par[1];if(a[4]){;}
   else if(a[1]){par[0]=a[0];par[1]=a[1];par[2]=a[2];par[3]=a[3];
     par[4]=fcal;par[5]=fssel;par[6]=a[4];checkFormalListData(par);
     a[4]=par[6];}
   else{par[0]=a[3];par[1]=a[2];newFormalTag(par);a[1]=par[2];
     par[0]=a[1];par[1]=fcal;putFormalCalibre(par);par[0]=a[1];
     par[1]=fssel;putFormalSsel(par);}
   if(a[4]){;}else{par[0]=a[2];par[1]=a[1];redefineTag(par);}}
}
static void formalListAffix(int *a){
  /* >rtag+ >fast + >formal> + >ftype + >err> 
       0      1        2          3      4   */
  int par[5];int tag;
  par[1]=a[4];getListTag(par);tag=par[0];a[4]=par[1];
  if(a[4]){;}
  else if(a[1]){par[0]=a[0];par[1]=a[2];par[2]=tag;par[3]=a[3];
    par[4]=a[4];checkAsFormalList(par);a[2]=par[1];a[4]=par[4];}
  else{par[0]=a[0];par[1]=a[2];par[2]=tag;par[3]=a[3];par[4]=a[4];
    defineAsFormalList(par);a[2]=par[1];a[4]=par[4];}
}
static void checkAsFormalTableAffix(int *a){/* >rtag+>tag+>formal>+>err> */
  int par[7];
  if(a[2]){par[0]=a[0];par[1]=a[2];par[2]=a[1];par[3]=IformalTable;
    par[4]=-1;par[5]=1;par[6]=a[3];checkFormalListData(par);a[2]=par[1];
    a[3]=par[6];}
  else{par[0]=IformalTable;par[1]=a[1];newFormalTag(par);a[2]=par[2];
    par[0]=a[2];par[1]=-1;putFormalCalibre(par);par[0]=a[2];par[1]=1;
    putFormalSsel(par);}
}
static void defineAsFormalTableAffix(int *a){ /*>rtag+>tag+>formal>+>err> */
  int par[5];
  if(a[3]){return;}
//DEBUG
//printf("define as formal table affix; tag=%d\n",a[1]);
  par[0]=a[1];if(hasFormalType(par)){a[3]=1;
    par[0]=formal_affix_redefined;par[1]=a[0];par[2]=a[1];Error(3,par);}
  else{par[0]=a[0];par[1]=a[1];par[2]=a[2];par[3]=a[3];
    checkAsFormalTableAffix(par);a[2]=par[2];a[3]=par[3];
    if(a[3]){;}
    else{par[0]=a[1];par[1]=a[1];par[2]=a[1];par[3]=1;par[4]=a[3];
      createFormalSelector(par);a[3]=par[4];par[0]=a[1];
      par[1]=a[2];redefineTag(par);}}
}
static void formalTableAffix(int *a){/* >rtag+>fast+>formal>+>tag+>err> */
  int par[4];
  if(a[1]){par[0]=a[0];par[1]=a[3];par[2]=a[2];par[3]=a[4];
    checkAsFormalTableAffix(par);a[2]=par[2];a[4]=par[3];}
  else{par[0]=a[0];par[1]=a[3];par[2]=a[2];par[3]=a[4];
    defineAsFormalTableAffix(par);a[2]=par[2];a[4]=par[3];}
}
/* - - - - - - - - - - - - - - - - - - - - - - - - */
static void formalFlatAffix(int *a){
  /* >rtag + >fast + >formal> + >tag+ >ftype + >err> 
       0       1        2         3      4       5   */
  int par[5];
  if(a[1]){par[0]=a[0];par[1]=a[2];par[2]=a[3];par[3]=a[4];par[4]=a[5];
    checkAsFormal(par);a[2]=par[1];a[5]=par[4];}
  else{par[0]=a[0];par[1]=a[2];par[2]=a[3];par[3]=a[4];par[4]=a[5];
    defineAsFormal(par);a[2]=par[1];a[5]=par[4];}
}
static void formalAffix(int *a){/* >rtag+>fast+>formal>+>err> */
  int par[6];int tag,type;
  if(a[3]){return;}
//printf("formal affix, formal=%d\n",a[2]);
  par[0]=Ssub;if(R(par)){par[0]=Sbus;Rskip(par);par[0]=a[0];par[1]=a[1];
    par[2]=a[2];par[3]=IformalStack;par[4]=a[3];
    formalListAffix(par);a[2]=par[2];a[3]=par[4];}
  else if(ahead(Sopen)){par[0]=a[0];par[1]=a[1];par[2]=a[2];
    par[3]=IformalTable;par[4]=a[3];formalListAffix(par);a[2]=par[2];a[3]=par[4];}
  else if(par[0]=Squoteimage,R(par)){mustTag(par);tag=par[0];par[0]=a[0];
    par[1]=a[1];par[2]=a[2];par[3]=tag;par[4]=IformalFile;par[5]=a[3];
    formalFlatAffix(par);a[2]=par[2];a[3]=par[5];}
  else if(par[0]=Sright,R(par)){mustTag(par);tag=par[0];par[0]=Sright;
    if(R(par)){type=IformalInout;}
    else if(ahead(Smore)){type=IformalInout;}
    else{type=IformalIn;}par[0]=a[0];
    par[1]=a[1];par[2]=a[2];par[3]=tag;par[4]=type;par[5]=a[3];
    formalFlatAffix(par);a[2]=par[2];a[3]=par[5];}
  else if(par[0]=Sasterisk,R(par)){par[0]=a[0];par[1]=a[1];par[2]=a[2];
    par[3]=Xstar;par[4]=IformalRepeat;par[5]=a[3];
    formalFlatAffix(par);a[2]=par[2];a[3]=par[5];}
  else{mustTag(par);tag=par[0];par[0]=Sright;if(R(par) || ahead(Smreq)){par[0]=a[0];
     par[1]=a[1];par[2]=a[2];par[3]=tag;par[4]=IformalOut;par[5]=a[3];
     formalFlatAffix(par);a[2]=par[2];a[3]=par[5];}
     else{par[0]=a[0];par[1]=a[3];subbus(par);a[3]=par[1];par[0]=a[0];
     par[1]=a[1];par[2]=a[2];par[3]=tag;par[4]=a[3];
     formalTableAffix(par);a[2]=par[2];a[3]=par[4];}}
}
/* ------------------------------------------------------- */
static void checkRuleType(int *a){/* >ruletype+>ruletag+>dl+err> */
  int par[4];int otype;
  a[3]=0;par[0]=a[1];getType(par);otype=par[1];
  if(otype==Iempty){par[0]=a[1];par[1]=Irule;putType(par);par[0]=a[1];
    par[1]=a[0];setTagFlag(par);par[0]=a[1];par[1]=a[2];
    addTagPrototype(par);}
  else if(otype==Irule){par[0]=a[1];par[1]=rtype;getTagFlag(par);
    otype=par[2];if(otype==a[0]){;}else{par[0]=a[1];getDefline(par);
      a[2]=par[1];par[0]=rule_type_different;par[1]=a[1];par[2]=a[2];
      Error(3,par);a[3]=1;}}
  else{par[0]=a[1];getDefline(par);a[2]=par[1];par[0]=tag_redefined;
    par[1]=a[2];par[2]=otype;par[3]=a[2];Error(4,par);a[3]=1;}
}
static void checkFormalAffixes(int *a){ /* >fast + >rtag + err> */
  int par[4];int formal,line;
//printf("check forma affixes, fast=%d\n",a[0]);
  a[2]=0;repeatAffix=0;par[0]=a[1];getDefline(par);line=par[1];
  par[0]=a[1];getAdm(par);formal=par[1]; nxt:
  if(a[2]){;}
  else if(par[0]=Splus,R(par)){if(formal==0){par[0]=extra_affix;
     par[1]=a[1];par[2]=line;Error(3,par);a[2]=1;}
     else{par[0]=a[1];par[1]=a[0];par[2]=formal;par[3]=a[2];
       formalAffix(par);formal=par[2];a[2]=par[3];par[0]=formal;
       getAdm(par);formal=par[1];goto nxt;}}
  if(a[2]){skipAll();}
  else if(formal==0){;}
  else{par[0]=missing_formal_affix;par[1]=a[1];par[2]=line;
    Error(3,par);a[2]=1;}
}
static void checkOutAffixes(int *a){/* >rtag + >flag */
  int par[3];int va[2];
  par[0]=a[0];par[1]=rtype;getTagFlag(par);
  if(par[2]==rfunc && a[1]==0){va[0]=function_without_out_affixes;
    va[1]=a[0];Warning(5,2,va);}
  else if(par[2]==rexit && a[1]!=0){par[0]=exit_rule_with_out_affixes;
    par[1]=a[0];Error(2,par);}
}
static void createFormalAffixes(int *a){/* >fast+>rtag+err> */
  int par[4];int link,formal,ftype,flag1,flag2;
//printf("createFormalAffixes, err=%d, fast=%d\n",a[2],a[0]);
  a[2]=0;flag1=flag2=0;repeatAffix=0;link=a[1];nxt:
  if(a[2]){;}
  else{par[0]=Splus;if(R(par)){formal=0;par[0]=a[1];par[1]=a[0];
    par[2]=formal;par[3]=a[2];formalAffix(par);formal=par[2];
    a[2]=par[3];if(a[2]){;}else{par[0]=formal;getType(par);
      ftype=par[1];if(ftype==IformalRepeat){
        if(flag1){a[2]=1;par[0]=more_repeat_affix;par[1]=a[1];
          Error(2,par);}
        else{flag1=1;par[0]=a[1];par[1]=rvararg;setTagFlag(par);}}
      else if(ftype==IformalOut){flag2=1;
        if(flag1){par[0]=a[1];par[1]=routvararg;setTagFlag(par);}}
      else if(ftype==IformalInout){flag2=1;}}
      par[0]=link;par[1]=formal;putAdm(par);link=formal;goto nxt;}
    else if(flag1==0){;}
    else{par[0]=link;getType(par);if(par[1]==IformalRepeat){a[2]=1;
      par[0]=last_repeat_affix;par[1]=a[1];Error(2,par);}}}
  if(a[2]){par[0]=a[1];par[1]=0;putAdm(par);skipAll();}
  else{par[0]=a[1];par[1]=raffixes;setTagFlag(par);par[0]=a[1];
    par[1]=flag2;checkOutAffixes(par);}
}
/* ======================================================= */
static void ruleExternalDeclarer(int *a){/* >tag+>dl */
  int par[3];int str,err;
  par[0]=Smreq;if(R(par)){;}else{par[0]=Sequals;must(par);}err=0;
  if(isString(par)){str=par[0];}
  else{str=0;err=1;par[0]=no_external_string;par[1]=a[0];
    Error(2,par);}
  par[0]=a[0];par[1]=a[1];par[2]=err;addTagExternal(par);err=par[2];
  if(err){;}else{par[0]=a[0];par[1]=str;putRepr(par);}
}
static void rulePrototype(int *a){ /* >tag + >dl */
  int par[3];int proto,err;
  err=0;par[0]=pgtProto;getPragmatValue(par);proto=par[1];
  if(proto==1){par[0]=a[0];par[1]=a[1];par[2]=err;addTagImport(par);err=par[2];}
  else if(proto==2){par[0]=a[0];par[1]=a[1];par[2]=err;addTagPublic(par);err=par[2];}
  else{par[0]=a[0];par[1]=a[1];addTagPrototype(par);}
}
static void ruleDefinition(int *a){ /* >rtag + >ext + >dl */
  int par[3];int err;
  par[0]=a[0];par[1]=raffixes;
  if(isTagFlag(par)){par[0]=1;par[1]=a[0];checkFormalAffixes(par);
    err=par[2];}
  else{par[0]=1;par[1]=a[0];createFormalAffixes(par);err=par[2];}
  if(err){skipAll();}
  else if(a[1]){par[0]=a[0];par[1]=a[2];ruleExternalDeclarer(par);}
  else{par[0]=a[0];par[1]=a[2];rulePrototype(par);}
}
static void ruleDefinitionSequence(int *a){/* >ruletype + >ext */
  int par[4];int tag,err,dl;nxt:
  par[0]=Scomma;if(R(par)){
    if(isTagdl(par)){tag=par[0];dl=par[1];par[1]=tag;par[0]=a[0];
      par[2]=dl;checkRuleType(par);err=par[3];par[0]=tag;par[2]=err;
      peekAfterFormalAffixes(par);err=par[2];
      if(err){skipAll();}
      else{par[0]=tag;par[1]=a[1];par[2]=dl;ruleDefinition(par);}
      goto nxt;}
    else{par[0]=rule_tag_expected;Error(1,par);skipAll();goto nxt;}}
  else if(par[0]=Spoint,R(par)){;}
  else{par[0]=Spoint;must(par);skipToPoint();}
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
static void ruleDeclarer(int *a){ /* >rtag + >dl */
  int par[4];int err;
  par[0]=a[0];par[1]=raffixes;if(isTagFlag(par)){
    par[0]=0;par[1]=a[0];checkFormalAffixes(par);err=par[2];}
  else{par[0]=0;par[1]=a[0];createFormalAffixes(par);err=par[2];}
  par[0]=a[0];par[1]=a[1];par[2]=err;addTagDefinition(par);
  err=par[2];if(err){skipToPoint();}
  else{par[0]=a[0];par[1]=repeatAffix;ruleBody(par);}
}
/* ------------------------------------------------------- */

void ruleDeclaration(int *a){ /* >ruletype+ >ext  */
  int par[4]; int tag,err,fast,dl;
  if(isTag(par)){tag=par[0];getLinenum(par);dl=par[0];
    par[1]=tag;par[0]=a[0];par[2]=dl;checkRuleType(par);
    err=par[3];par[0]=tag;par[2]=err;peekAfterFormalAffixes(par);
    fast=par[1];err=par[2];
    if(err){skipToPoint();}
    else if(a[1]||fast){par[0]=tag;par[1]=a[1];par[2]=dl;
      ruleDefinition(par);par[0]=a[0];par[1]=a[1];
      ruleDefinitionSequence(par);}
    else{par[0]=tag;par[1]=dl;ruleDeclarer(par);restoreTags();}}
  else{par[0]=rule_tag_expected;Error(1,par);skipToPoint(); }
}

void initialize_rules(void){
  add_messages();
}

/* EOF */
