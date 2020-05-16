/* rulebody.ale */

#include "stddata.h"
#include "rulebody.h"
#include "symbols.h"
#include "tags.h"
#include "types.h"
#include "lexical.h"
#include "disc.h"
#include "display.h"
#include "pragmats.h"

/* ================================================= */
/* messages */
static int
expected,expected_after,tag_expected_after,tag_expected,source_or_tag_expected,
selector_tag_expected,stack_tag_expected,wrong_affix_form,unknown_label,
source_expected,undefined_formal_selector,member_expected,formal_as_rule,
no_formal_repeat_affix,wrong_zone,empty_classification;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void add_messages(void){
 addMSG("symbol %p is expected here",expected);
 addMSG("symbol %p is expected after %p",expected_after);
 addMSG("tag expected after %p",tag_expected_after);
 addMSG("tag expected",tag_expected);
 addMSG("source or tag expected",source_or_tag_expected);
 addMSG("in extension selector expected",selector_tag_expected);
 addMSG("after extension tag expected",stack_tag_expected);
 addMSG("wrong affix form",wrong_affix_form);
 addMSG("rule %p: unknown label %p",unknown_label);
 addMSG("source expected after %p",source_expected);
 addMSG("formal selector %p not defined",undefined_formal_selector);
 addMSG("rule %p: member expected",member_expected);
 addMSG("formal affix %p as a rule",formal_as_rule);
 addMSG("rule %p: no formal repeat affix",no_formal_repeat_affix);
 addMSG("rule %p: zone syntax (cannot be empty)",wrong_zone);
 addMSG("classification has no cases",empty_classification);
}
#undef addMSG

/* --------------------------------------------------*/
static void Eerror(int *a,int n,int *va){
  if(a[0]){return;}
  a[0]=1;Error(n,va);
}
static int ruleTag=0,formalRepeatAffix;
/* ================================================== */
static void handleFormalList(int *a){/* >formal */
  int par[3];int x;
  x=LLOC->offset[LLOC->aupb-LLOC_type];if(x==IformalStack||x==IformalTable){
    par[0]=a[0];getFormalCalibre(par);LLOC->offset[LLOC->aupb-LLOC_calibre]=par[1];
    getFormalSsel(par);LLOC->offset[LLOC->aupb-LLOC_ssel]=par[1];}
}
/* open a range */
static void setupLocalStack(int *a){ /* >rtag+ loc> */
  int par[8];int formal;
  par[0]=STACKpar(LLOC);scratch(par);par[0]=a[0];getAdm(par);formal=par[1];
  nxt:
  if(formal==0){;}
  else{par[0]=STACKpar(LLOC);par[1]=6;
    par[7-LLOC_flag]=par[7-LLOC_repr]=0;
    par[7-LLOC_type]=LADM->offset[formal-LADM_type];
    par[7-LLOC_tag]=formal;
    par[7-LLOC_orepr]=par[7-LLOC_otype]=0;expandstack(par);
    par[0]=formal;handleFormalList(par);
    par[0]=formal;par[1]=LLOC->aupb;putRepr(par);
    par[0]=formal;getAdm(par);formal=par[1];goto nxt;}
  a[1]=LLOC->aupb;par[0]=Dlabel;D(par);par[0]=a[0];Dtag(par);
  par[0]=STACKpar(LLOC);par[1]=6;
  par[7-LLOC_flag]=par[7-LLOC_repr]=0;par[7-LLOC_type]=Ilabel;
  par[7-LLOC_orepr]=par[7-LLOC_otype]=0;par[7-LLOC_tag]=a[0];
  expandstack(par);
}
static void openNewLocalRange(int *a){ /* >label + old> */
  int par[8];
  a[1]=LLOC->aupb;
  if(a[0]==0){;}
  else{par[0]=STACKpar(LLOC);par[1]=6;par[7-LLOC_flag]=par[7-LLOC_repr]=
    par[7-LLOC_orepr]=par[7-LLOC_otype]=0;par[7-LLOC_type]=Ilabel;
    par[7-LLOC_tag]=a[0];expandstack(par);par[0]=Dlabel;D(par);par[0]=a[0];
    Dtag(par);}
}
static void addLocalAffix(int *a){ /* >tag */
  int par[8];int orepr,otype;
  par[0]=a[0];getRepr(par);orepr=par[1];par[0]=a[0];getType(par);otype=par[1];
  par[0]=STACKpar(LLOC);par[1]=6;par[7-LLOC_flag]=par[7-LLOC_repr]=0;
  par[7-LLOC_type]=Ilocal;par[7-LLOC_tag]=a[0];par[7-LLOC_orepr]=orepr;
  par[7-LLOC_otype]=otype;expandstack(par);
  par[0]=a[0];par[1]=Ilocal;putType(par);par[0]=a[0];par[1]=LLOC->aupb;
  putRepr(par);
}
static void closeLocalRange(int *a){ /* >old */
  int par[2]; nxt:
  if(LLOC->aupb<=a[0]){;}
  else{if(LLOC->offset[LLOC->aupb-LLOC_type]==Ilocal){
    par[0]=LLOC->offset[LLOC->aupb-LLOC_tag];par[1]=LLOC->offset[LLOC->aupb-LLOC_orepr];
    putRepr(par);par[0]=LLOC->offset[LLOC->aupb-LLOC_tag];par[1]=
    LLOC->offset[LLOC->aupb-LLOC_otype];putType(par);}
   par[0]=STACKpar(LLOC);unstack(par);goto nxt;}
}
/* ================================================== */
static void skipOverSource(int *a);
static void source(int *a); /* >tag + >err> */
static void compoundMember(void);
static void classification(void);
static void alternativeSeries(void);
static void alternative(void);

static void skipOverAnIndex(int *a){ /* >err> */
  int par[2];int va[2];
  par[0]=Ssub;if(R(par)){
    par[1]=a[0];skipOverSource(par);a[0]=par[1];par[0]=Sbus;
    if(R(par)){;}else{va[0]=expected;va[1]=Sbus;Eerror(a,2,va);}
}}
static void skipOverSource(int *a){ /* single> + >err> */
  int par[2];int va[2]; int symb;
//printf("skip over source, inpt=%d\n",inpt);
  a[0]=0; symb=inpt; if(isCons(par)){;}
  else if(isTag(par)){par[0]=Sasterisk;if(R(par)){
     if(isTag(par)){par[0]=a[1];skipOverAnIndex(par);a[1]=par[0];}
     else{par[0]=a[1];va[0]=tag_expected_after;va[1]=Sasterisk;
       Eerror(par,2,va);a[1]=par[0];}}
   else if(ahead(Ssub)){par[0]=a[1];skipOverAnIndex(par);a[1]=par[0];}
   else{a[0]=1;}}
  else if((par[0]=Slwb,R(par))||(par[0]=Supb,R(par))||
    (par[0]=Svupb,R(par))||
    (par[0]=Svlwb,R(par))||(par[0]=Scalibre,R(par))){
//printf("skip over source, symp=%d,next=%d\n",symb,inpt);
      if(isTag(par)){;}
      else{par[0]=a[1];va[0]=tag_expected_after;va[1]=symb;Eerror(par,2,va);
        a[1]=par[0];}}
  else{par[0]=a[1];va[0]=source_or_tag_expected;Eerror(par,1,va);a[1]=par[0];}
}
static void skipOverDestination(int *a){ /* >err> */
  int par[2];int va[2];
  par[0]=Sarrow;if(R(par)){nxt:if(isTag(par)){par[0]=Sarrow;if(R(par)){goto nxt;}}
    else{va[0]=selector_tag_expected;Eerror(a,1,va);}}
  else{va[0]=expected;va[1]=Sarrow;Eerror(a,2,va);}
}

static void skipOverExtension(int *a){ /* >ex + tag> + simple> + err> */
                                       /*  0     1       2        3   */
  int par[2]; int va[2];
  a[1]=a[2]=a[3]=0;initRestore();par[0]=Sasterisk;
  if(R(par)){;}else{a[3]=1;} nxt:
  par[1]=a[3];skipOverSource(par);a[3]=par[1];
  par[0]=a[3];skipOverDestination(par);a[3]=par[0];
  par[0]=Scomma;if(R(par)){goto nxt;}
  par[0]=Sasterisk;must(par);par[0]=Sclose;if(a[0]&&R(par)){a[2]=1;}
  if(isTag(par)){a[1]=par[0];}
  else{par[0]=a[3];va[0]=stack_tag_expected;Eerror(par,1,va);a[0]=par[0];}
  if(a[3]){forgetRestore();skipAll();}else{makeRestore();}
}
static void peekAfterSource(int *a){ /* tag> + err> */
  int par[2];int va[2];int singleTag;
  initRestore();a[1]=a[0]=0;par[1]=a[1];skipOverSource(par);
  singleTag=par[0];a[1]=par[1];par[0]=inpt;
  if(isSpecialRule(par)){a[0]=par[1];}
  else if(singleTag){;}
  else{par[0]=a[1];va[0]=wrong_affix_form;Eerror(par,1,va);a[1]=par[0];}
  if(a[1]){forgetRestore();skipAll();}else{makeRestore();}
}
/* ---------------------------------------------------- */
static void searchJump(int *a){ /* >tag */
  int par[3];int loc;
  loc=LLOC->aupb;nxt:
  if(loc<LLOC->alwb){par[0]=unknown_label;par[1]=ruleTag;par[2]=a[0];
    Error(3,par);}
  else if(LLOC->offset[loc-LLOC_type]==Ilabel && LLOC->offset[loc-
    LLOC_tag]==a[0]){par[0]=Djump;D(par);par[0]=loc;Dtag(par);}
  else{par[0]=STACKpar(LLOC);par[1]=loc;previous(par);loc=par[1];goto nxt;}
}
static int terminator(void){
  int par[2];
  par[0]=Splus;if(R(par)){par[0]=Dplus;D(par);}
  else if(par[0]=Sminus,R(par)){par[0]=Dminus;D(par);}
  else if(par[0]=Sexit,R(par)){par[0]=Xexit;Dtag(par);par[0]=Xexit;
    useTag(par);par[0]=Dplus;D(par);par[0]=Xexit;par[1]=0;source(par);}
  else if(par[0]=Scolon,R(par)){
    if(isTag(par)){searchJump(par);}else{par[0]=tag_expected_after;
      par[1]=Scolon;Error(2,par);}}
  else{ return 0;}
  return 1;
}
static void indexSource(int *a){ /* >tag + >err> */
  int par[2];int va[3];
  par[0]=Ssub;if(R(par)){par[0]=Dsub;D(par);par[0]=a[0];Dtag(par);
    par[0]=a[0];par[1]=a[1];source(par);a[1]=par[1];
    par[0]=Dbus;D(par);par[0]=Sbus;if(R(par)){;}
    else{par[0]=a[1];va[0]=expected_after;va[1]=Sbus;va[2]=a[0];
      Eerror(par,3,va);a[1]=par[0];}}
  else{par[0]=Dsub;D(par);par[0]=a[0];Dtag(par);par[0]=Dupb;D(par);
    par[0]=a[0];Dtag(par);par[0]=Dbus;D(par);}
}
static void selector(int *a){ /* >sel + >tag */
  int par[4];int repr;
//DEBUG
//printf("selector, sel=%d, tag=%d ",a[0],a[1]);par[0]=a[1];printPointer(par);printf("\n");

  par[0]=a[0];par[1]=a[1];packSelector(par);a[0]=par[2];par[0]=a[1];
  if(hasFormalType(par)){par[0]=a[0];getType(par);
//DEBUG
//printf("formal =%d, type=%d,IformalSelector=%d\n",a[0],par[1],IformalSelector);
    if(par[1]==IformalSelector){par[0]=a[0];getRepr(par);repr=par[1];}
    else{repr=-1;}
    if(repr>0){par[0]=repr;Dcons(par);}
    else{par[0]=undefined_formal_selector;par[1]=a[0];Error(2,par);}}
  else{par[0]=a[0];Dtag(par);}
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
static void listTag(int *a){ /* >x + >err> */
  int par[2];int va[2];int tag;
  if(isTag(par)){tag=par[0];useTag(par);par[0]=tag;Dtag(par);}
  else{par[0]=a[1];va[0]=tag_expected_after;va[1]=a[0];Eerror(par,2,va);
    a[1]=par[0];}
}
static void source(int *a){ /* >tag + >err> */
 int par[3];int va[3];int x,y;
  if(isCons(par)){Dcons(par);}
  else if(isTag(par)){x=par[0];par[0]=Sasterisk;
    if(R(par)){if(isTag(par)){y=par[0];par[0]=y;par[1]=a[1];
        indexSource(par);a[1]=par[1];par[0]=y;useTag(par);
        par[0]=x;par[1]=y;selector(par);}
      else{par[0]=a[1];va[0]=tag_expected_after;va[1]=Sasterisk;
        Eerror(par,2,va);a[1]=par[0];}}
    else if(ahead(Ssub)){par[0]=x;par[1]=a[1];indexSource(par);a[1]=par[1];
      par[0]=x;useTag(par);par[0]=par[1]=x;selector(par);}
    else{par[0]=x;useTag(par);par[0]=x;Dtag(par);}}
  else if(par[0]=Slwb,R(par)){par[0]=Dlwb;D(par);par[0]=Slwb;par[1]=a[1];
    listTag(par);a[1]=par[1];}
  else if(par[0]=Supb,R(par)){par[0]=Dupb;D(par);par[0]=Supb;par[1]=a[1];
    listTag(par);a[1]=par[1];}
  else if(par[0]=Svlwb,R(par)){par[0]=Dvlwb;D(par);par[0]=Svlwb;
    par[1]=a[1];listTag(par);a[1]=par[1];}
  else if(par[0]=Svupb,R(par)){par[0]=Dvupb;D(par);par[0]=Svupb;
    par[1]=a[1];listTag(par);a[1]=par[1];}
  else if(par[0]=Scalibre,R(par)){par[0]=Dcalibre;D(par);par[0]=Scalibre;
    par[1]=a[1];listTag(par);a[1]=par[1];}
  else{
//printf("error here, inpt=%d, Sopen=%d ",inpt,Sopen);par[0]=inpt;printPointer(par);printf("\n");
  par[0]=a[1];va[0]=source_expected;va[1]=a[0];Eerror(par,2,va);
    a[1]=par[0];skipAll();
    }
}
static void sourceOrString(int *a){ /* >tag + >err> */
  int par[2];int c;
//printf(" ### source or string, inpt=");par[0]=inpt;printPointer(par);printf("\n");
  if(isString(par)){newStdstring(par);c=par[1];
    par[0]=Dplus;D(par);par[0]=Xstringtable;
    Dtag(par);par[0]=Dplus;D(par);par[0]=c;Dtag(par);}
  else if(par[0]=Snoarg,R(par)){par[0]=Dplus;D(par);par[0]=Dnoarg;D(par);}
  else if(par[0]=Senquiry,R(par)){par[0]=Dplus;D(par);par[0]=Dnoarg;D(par);}
  else{par[0]=Dplus;D(par);source(a);}
}
static int repeatAffix(void){
  int par[2];
  par[0]=Sasterisk;if(R(par)){
    if(formalRepeatAffix){par[0]=Dplus;D(par);par[0]=formalRepeatAffix;Dtag(par);}
    else{par[0]=no_formal_repeat_affix;par[1]=ruleTag;Error(2,par);}}
  else{return 0;}
  return 1;
}
static void affixForm(void){
  int par[2];int tag,err;
  if(isTag(par)){tag=par[0];
    if(hasFormalType(par)){par[0]=formal_as_rule;par[1]=tag;Error(2,par);
      skipAll();}
    else{par[0]=tag;Dtag(par);par[0]=tag;useTag(par);err=0;nxt:par[0]=Splus;
      if(R(par)){if(repeatAffix()){;}
                 else{par[0]=tag;par[1]=err;sourceOrString(par);err=par[1];
                      goto nxt;}}}}
  else{par[0]=tag_expected;Error(1,par);skipAll();}
}
static void specialAffixForm(int *a){ /* >tag */
  int par[3]; int err;
  par[0]=a[0];Dtag(par);par[0]=a[0];useTag(par);par[0]=Dplus;D(par);err=0;
  par[0]=a[0];par[1]=err;source(par);err=par[1];
  if(err){;}else{nextSymbol();}
  par[0]=Dplus;D(par);par[0]=a[0];par[1]=err;source(par);err=par[1];
  if(a[0]==Xarrow){nxt:par[0]=Sarrow;if(R(par)){
    par[0]=Dplus;D(par);par[0]=a[0];par[1]=err;source(par);err=par[1];
    goto nxt;}}
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */
static void toSelectors(int *a){/* >tag + >err> */
  int par[3];int va[2];int sel;
  par[0]=Sarrow;if(R(par)){nxt:
    if(isTag(par)){sel=par[0];par[0]=Dto;D(par);par[0]=sel;par[1]=a[0];
      selector(par);par[0]=Sarrow;if(R(par)){goto nxt;}}
    else{par[0]=a[1];va[0]=tag_expected_after;va[1]=Sarrow;Eerror(par,2,va);
      a[1]=par[0];skipAll();}}
  else{par[0]=a[1];va[0]=expected;va[1]=Sarrow;Eerror(par,2,va);a[1]=par[0];}  
}
static void extension(int *a){ /* >tag */ 
  int par[3];int err;
  par[0]=Dextension;D(par);par[0]=a[0];useTag(par);par[0]=a[0];Dtag(par);
  par[0]=Sasterisk;
  Rskip(par);err=0;nxt:par[0]=a[0];par[1]=err;source(par);err=par[1];
  par[0]=a[0];par[1]=err;toSelectors(par);err=par[1];par[0]=Scomma;
  if(R(par)){goto nxt;}
  par[0]=Dextension;D(par);par[0]=Sasterisk;Rskip(par);par[0]=Sclose;
  Rskip(par);par[0]=a[0];Rskip(par);
}
static int lookingAtaMember(void){
  if(inpt==Sopen||inpt==Sasterisk||inpt==Slwb||inpt==Supb||inpt==Svlwb
     ||inpt==Svupb||inpt==Scalibre
     ||(TTAG->alwb<=inpt&&inpt<=TTAG->aupb)
     ||(CONST->alwb<=inpt && inpt<=CONST->aupb)){return 1;}
  return 0;
}
static void member(void){
  int par[4];int err,tag,simple;
  par[0]=Sopen;if(R(par)){
    if(ahead(Sasterisk)){par[0]=1;skipOverExtension(par);err=par[3];
      tag=par[1];simple=par[2];
      if(err){;}
      else if(simple){par[0]=tag;extension(par);}
      else{compoundMember();}}
    else{compoundMember();}}
  else if(ahead(Sasterisk)){par[0]=0;skipOverExtension(par);tag=par[1];
    err=par[3];if(err){;}else{par[0]=tag;extension(par);}}
  else{peekAfterSource(par);tag=par[0];err=par[1];
    if(err){;}
    else if(tag){par[0]=tag;specialAffixForm(par);}
    else{affixForm();}}
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - */
static void peekLabel(int *a){ /* label> */
  int par[2];
  initRestore();a[0]=0;if(isTag(par)){a[0]=par[0];
    if(ahead(Scolon)||ahead(Sminus)){;}else{a[0]=0;}}
  makeRestore();
}
static void skipLabel(int *a){ /* >label */
  int par[1];
  if(a[0]){par[0]=a[0];Rskip(par);par[0]=Scolon;Rskip(par);}
}
static void addLocalAffixes(void){
  int par[2];int tag;
  initRestore();par[0]=Sminus;if(R(par) && isTag(par)){
    makeRestore();par[0]=Dlocal;D(par);nxt:par[0]=Sminus;
    if(R(par)){if(isTag(par)){tag=par[0];Dtag(par);par[0]=tag;
      addLocalAffix(par);goto nxt;}
        else{par[0]=tag_expected_after;par[1]=Sminus;Error(2,par);
          skipAll();}}
    else if(par[0]=Scolon,R(par)){par[0]=Dcolon;D(par);}
    else{par[0]=expected;par[1]=Scolon;Error(2,par);skipAll();}}
  else{makeRestore();}
}
static void compoundMember(void){
  int par[2];int label,loc;
  par[0]=Dopen;D(par);peekLabel(par);label=par[0];par[0]=label;
  openNewLocalRange(par);loc=par[1];par[0]=label;skipLabel(par);
  addLocalAffixes();par[0]=Sbox;
  if(R(par)){classification();}else{alternativeSeries();}
  par[0]=Sclose;if(R(par)){;}else{par[0]=expected;par[1]=Sclose;
    Error(2,par);skipAll();}
  par[0]=Dclose;D(par);par[0]=loc;closeLocalRange(par);  
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - */
static void alternative(void){
  int par[2];nxt:
  if(terminator()){;}
  else if(lookingAtaMember()){member();par[0]=Scomma;
    if(R(par)){par[0]=Dcomma;D(par);goto nxt;}}
  else{par[0]=member_expected;par[1]=ruleTag;Error(2,par);}
}
static void alternativeSeries(void){
  int par[1];nxt:
  alternative();par[0]=Ssemicolon;if(R(par)){par[0]=Dsemicolon;
    D(par);goto nxt;}
}
static void classifier(void){
  int par[2];int x,empty; nxt:
  empty=0;if(isTag(par)){x=par[0];Dtag(par);par[0]=x;useTag(par);}
  else if(isCons(par)){Dcons(par);}
  else{empty=1;}par[0]=Scolon;
  if(R(par)){empty=0;par[0]=Dcolon;D(par);
    if(isTag(par)){x=par[0];Dtag(par);par[0]=x;useTag(par);}
    else if(isCons(par)){Dcons(par);}}
  if(empty){par[0]=wrong_zone;par[1]=ruleTag;Error(2,par);}
  par[0]=Ssemicolon;if(R(par)){par[0]=Dsemicolon;D(par);goto nxt;}
  else{par[0]=Sbus;must(par);}
}
static void area(int *a){/* >err> + last> */
  int par[2];int va[2];
  par[0]=Ssub;if(R(par)){a[1]=0;par[0]=Darea;D(par);
    classifier();par[0]=Darea;D(par);par[0]=Dcomma;D(par);
    par[0]=Scomma;if(R(par)){;}else{par[0]=a[0];va[0]=expected;
      va[1]=Scomma;Eerror(par,2,va);}
    alternative();}
  else{a[1]=1;par[0]=Darea;D(par);par[0]=Dcolon;D(par);
    par[0]=Darea;D(par);par[0]=Dcomma;D(par);alternative();}
}
static void classification(void){
  int par[2];int va[2];int err,last,cnt;
  par[0]=Dbox;D(par);err=cnt=0;par[0]=Sbox;par[1]=err;source(par);
  err=par[1];par[0]=Dbox;D(par);par[0]=Sbox;
  if(R(par)){;}else{par[0]=err;va[0]=expected;va[1]=Sbox;
    Eerror(par,2,va);}nxt: par[0]=err;area(par);last=par[1];err=par[0];
  if(last){;}else if(par[0]=Ssemicolon,R(par)){par[0]=Dsemicolon;
   D(par);cnt++;goto nxt;}
  if(err){skipAll();}
  else if(last==0){;}
  else if(cnt==0){par[0]=empty_classification;Error(1,par);}
}
/* ================================================== */
static void rulePragmats(int *a){ /* >tag */
  int par[2];
  par[0]=pgtTrace;if(isPragmatValue(par)){par[0]=a[0];par[1]=rtrace;setTagFlag(par);}
  par[0]=pgtCount;if(isPragmatValue(par)){par[0]=a[0];par[1]=rcount;setTagFlag(par);}
  par[0]=pgtBounds;if(isPragmatValue(par)){par[0]=a[0];par[1]=rbounds,setTagFlag(par);}
}
void ruleBody(int *a){ /* >tag+>repaffix */
  int par[2];int loc;
  ruleTag=a[0];formalRepeatAffix=a[1];
  par[0]=Drule;D(par);par[0]=ruleTag;Dtag(par);
  par[0]=ruleTag;rulePragmats(par);
  par[0]=a[0];setupLocalStack(par);loc=par[1];
  if(ahead(Sminus)){addLocalAffixes();}
  else if(par[0]=Scolon,R(par)){;}
  else{par[0]=expected;par[1]=Scolon;Error(2,par);skipAll();}
  par[0]=Sbox;if(R(par)){classification();}else{alternativeSeries();}
  par[0]=Dpoint;D(par);par[0]=loc;closeLocalRange(par);ruleTag=0;
  par[0]=Spoint;if(R(par)){;}else{par[0]=expected;par[1]=Spoint;
   Error(2,par);skipToPoint();}
}

void rootBody(void){
  int par[2];int loc;
  ruleTag=Xroot;formalRepeatAffix=0;
  par[0]=Droot;D(par);par[0]=Xroot;Dtag(par);
  par[0]=Xroot;rulePragmats(par);
  par[0]=Xroot;setupLocalStack(par);loc=par[1];
  addLocalAffixes();par[0]=Sbox;if(R(par)){classification();}
  else{alternativeSeries();}
  par[0]=Dpoint;D(par);par[0]=loc;closeLocalRange(par);ruleTag=0;
  par[0]=Spoint;if(R(par)){;}else{par[0]=expected;par[1]=Spoint;
    Error(2,par);skipToPoint();}
}

void initialize_rulebody(void){
  add_messages();
}


/* EOF */
