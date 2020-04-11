/* drules.ale */

#include "stddata.h"
#include "drules.h"
#include "disc.h"
#include "tags.h"
#include "display.h"
#include "types.h"
#include "obj.h"

/* messages */
static int
repeat_block_out_formal_not_set,in_none,in_extension,in_rule,in_macro,
not_defined,
must_be_list,undefined_standard_selector,undefined_selector,syntax_error,
wrong_affix_type,affix_no_value,cannot_be_constant,limit_cannot_be_used,
provides_wrong_type,wrong_dummy_affix,maybe_wrong_index,unshielded_jump,
actual_calibre_different,actual_ssel_different,no_pending_repeat_block,
missing_repeat_affix,cannot_modify_read_only_macro,
cannot_modify_read_only_vararg,wrong_formal_type;


#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_msg1(void){
   addMSG("rule %p: formal out affix %p was not set",repeat_block_out_formal_not_set);
   addMSG("rule %p: no pending repeat affixes",no_pending_repeat_block);
   addMSG("label %p: infinite loop",unshielded_jump);
   addMSG("%*",in_none);
   addMSG("extension %p: ",in_extension);
   addMSG("rule %p: ",in_rule);
   addMSG("macro %p: ",in_macro);
   addMSG("%p: not defined",not_defined);
   addMSG("%m\"%p\" must be a table or stack (%l)",must_be_list);
   addMSG("%mno standard selector for \"%p\"",undefined_standard_selector);
   addMSG("%mselector %p not defined",undefined_selector);
/* ------------- */
   addMSG("%maffix type error",syntax_error);
   addMSG("%m\"%p\" has wrong type %p",wrong_affix_type);
   addMSG("%m\"%p\" unitialized",affix_no_value);
   addMSG("%mcannot be a constant",cannot_be_constant);
   addMSG("%mlimit with \"%p\" cannot be used",limit_cannot_be_used);
   addMSG("%m\"%p\" has incompatible type (%l)",provides_wrong_type);
   addMSG("%mdummy affix cannot be used here",wrong_dummy_affix);
   addMSG("%m""%p"" maybe wrong index",maybe_wrong_index);
   addMSG("%maffix \"%p\" has calibre different from %d",actual_calibre_different);
   addMSG("%mstandard selector of \"%p\" is different",actual_ssel_different);
   addMSG("rule %p: the last actual affix must be *",missing_repeat_affix);
   addMSG("rule %p: cannot modify in affix %p in a macro rule",cannot_modify_read_only_macro);
   addMSG("rule %p: cannot modify in affix %p in variable block",cannot_modify_read_only_vararg);
   addMSG("FATAL: match formal actual: wrong formal type %p",wrong_formal_type);
}
#undef addMSG

static int compoundLevel,ruleCompiled;


/* constants */
#define Lused	0x0001
#define LTset	0x0002
#define LFset	0x0004
#define LTmod	0x0008
#define LFmod	0x0010
#define Lvararg	0x1000

static int isLocalFlag(int *a){ /* >loc + >flag */
  if((LLOC->offset[a[0]-LLOC_flag]&a[1])!=0){return 1;}
  return 0;
}
static void setLocalFlag(int *a){/* >loc+>flag */
  LLOC->offset[a[0]-LLOC_flag]|=a[1];
}
static void clearLocalFlag(int *a){ /* >loc+>flag */
  LLOC->offset[a[0]-LLOC_flag] &= ~a[1];
}
static void copyLocalTflagtoF(void){
  int par[3];int ptr;
  ptr=LLOC->aupb;nxt:if(ptr<LLOC->alwb){;}
  else{par[0]=ptr;par[1]=LTset;if(isLocalFlag(par)){par[0]=ptr;
    par[1]=LFset;setLocalFlag(par);}else{par[0]=ptr;par[1]=LFset;
    clearLocalFlag(par);} par[0]=ptr;par[1]=LTmod;
    if(isLocalFlag(par)){par[0]=ptr;par[1]=LFmod;setLocalFlag(par);}
    else{par[0]=ptr;par[1]=LFmod;clearLocalFlag(par);}
    par[0]=STACKpar(LLOC);par[1]=ptr;previous(par);ptr=par[1];goto nxt;
}}
/* ------------------------- */
static void resetAffixBlockFlags(int *a){/* >rtag */
   int par[3];int ptr,clear;
   ptr=LLOC->alwb;clear=1;nxt:if(ptr>LLOC->aupb){;}
   else if(LLOC->offset[ptr-LLOC_type]==Ilabel){;}
   else{if(LLOC->offset[ptr-LLOC_type]==IformalRepeat){
     par[0]=ptr;par[1]=LTmod;if(isLocalFlag(par)){;}else{
     par[0]=no_pending_repeat_block;par[1]=a[0];Warning(4,2,par);}
     par[0]=ptr;par[1]=LTset;if(isLocalFlag(par)){clear=0;}
     par[0]=ptr;par[1]=LFmod;clearLocalFlag(par);par[1]=LFset;setLocalFlag(par);}
   else if((par[0]=ptr,par[1]=LFmod,isLocalFlag(par))&&clear 
      && LLOC->offset[ptr-LLOC_type]==IformalOut){
     if((par[0]=ptr,par[1]=LTset,isLocalFlag(par))){par[0]=ptr;
        par[1]=LTset;clearLocalFlag(par);}
     else{par[0]=repeat_block_out_formal_not_set;par[1]=a[0];
        par[2]=LLOC->offset[ptr-LLOC_tag];Error(3,par);}}
   par[0]=STACKpar(LLOC);par[1]=ptr;next(par);ptr=par[1];goto nxt;
}}
static int Ltag(int *a){ /* tag> */
   int par[2];if(Qtag(a)){par[0]=STACKpar(LLOC);par[1]=a[0];
     if(was(par)){par[0]=a[0];par[1]=Lused;setLocalFlag(par);}
     return 1;}
   return 0;
}
static void mustLtag(int *a){ /* tag> */
  int par[2];mustQtag(a);par[0]=STACKpar(LLOC);par[1]=a[0];
  if(was(par)){par[0]=a[0];par[1]=Lused;setLocalFlag(par);}
}
/* ----------------------------------- */
static void setFormalAffix(int *a);

static void setupFormalStack(int *a){ /* >rtag */
  int par[8];int formal,repeatBlock;
  par[0]=STACKpar(LLOC);scratch(par);repeatBlock=0;par[0]=a[0];
  getAdm(par);formal=par[1];
  nxt:if(formal==0){;}
  else{par[0]=STACKpar(LLOC);par[1]=6;par[7-LLOC_flag]=LTset;
    par[7-LLOC_repr]=0;par[7-LLOC_type]=LADM->offset[formal-LADM_type];
    par[7-LLOC_tag]=formal;par[7-LLOC_calibre]=par[7-LLOC_ssel]=0;
    expandstack(par);par[0]=repeatBlock;setFormalAffix(par);repeatBlock=par[0];
    par[0]=formal;getAdm(par);formal=par[1];goto nxt;}
}
static void setupLabel(int *a){ /* label> */
  int par[8];
  par[0]=Dlabel;if(Q(par)){mustQtag(par);a[0]=par[0];par[0]=STACKpar(LLOC);
   par[1]=6;par[7-LLOC_repr]=0;par[7-LLOC_type]=Ilabel;par[7-LLOC_tag]=a[0];
   par[7-LLOC_flag]=par[7-LLOC_orepr]=par[7-LLOC_otype]=0;
   expandstack(par);a[0]=LLOC->aupb;}
  else{a[0]=0;}
}
static void setupLocals(void){
  int par[8];int local;
  par[0]=Dlocal;if(Q(par)){nxt:par[0]=Dcolon;if(Q(par)){;}else{
    mustQtag(par);local=par[0];par[0]=STACKpar(LLOC);par[1]=6;
    par[7-LLOC_flag]=0;par[7-LLOC_repr]=compoundLevel;par[7-LLOC_type]=Ilocal;
    par[7-LLOC_tag]=local;par[7-LLOC_orepr]=par[7-LLOC_otype]=0;
    expandstack(par);goto nxt;}}
}
static void setFormalAffix(int *a){ /* >flag> */
  int par[2];int x;
  x=LLOC->offset[LLOC->aupb-LLOC_type];
//printf("<formal affix %d: ",LLOC->aupb);par[0]=LLOC->offset[LLOC->aupb-LLOC_tag];printPointer(par);printf("|");par[0]=LLOC->aupb;printPointer(par);printf(">");
  if(x==IformalStack||x==IformalTable){par[0]=LLOC->offset[LLOC->aupb-LLOC_tag];
    getFormalCalibre(par);LLOC->offset[LLOC->aupb-LLOC_calibre]=par[1];
    par[0]=LLOC->offset[LLOC->aupb-LLOC_tag];getFormalSsel(par);
    LLOC->offset[LLOC->aupb-LLOC_ssel]=par[1];}
  else if(x==IformalRepeat){par[0]=LLOC->aupb;par[1]=LTset;clearLocalFlag(par);
    par[0]=LLOC->aupb;par[1]=LTmod;setLocalFlag(par);a[0]=1;}
  else if(x==IformalOut){par[0]=LLOC->aupb;par[1]=LTset;clearLocalFlag(par);
    if(a[0]){par[0]=LLOC->aupb;par[1]=Lvararg;setLocalFlag(par);}}
  else{if(a[0]){par[0]=LLOC->aupb;par[1]=Lvararg;setLocalFlag(par);}}
}
static void getLocalCalibre(int *a){ /* >tag + x> */
  a[1]=LLOC->offset[a[0]-LLOC_calibre];
}
static void getLocalSsel(int *a){ /* >tag + x> */
  a[1]=LLOC->offset[a[0]-LLOC_ssel];
}
/* ============================== */
/* RULE flags */
#define UTset		0x0001
#define UFset		0x0002
#define UTmod		0x0004
#define UFmod		0x0008
#define UETset		0x0010
#define UETmod		0x0020
#define Ualtset		0x0100
#define Ualtmod		0x0200
#define UtailFset	0x0400
#define UtailFmod	0x0800
#define Ujump		0x1000
#define UTcan		0x2000
#define UFcan		0x4000
#define Uredo		0x8000
#define Ushield		0x10000
#define Uallset		(UETset|Ualtset)
#define Uallmod		(UETmod|Ualtmod)
#define UtailBits	(UtailFset|UtailFmod)
/* ------------- */
static void pushRULE(int *a){ /* >data */
  int par[5];
  par[0]=STACKpar(RULE);par[1]=2;par[3-RULE_flag]=0;par[3-RULE_data]=a[0];
  expandstack(par);
}
static void setRULEflag(int *a){ /* >ptr+>flag */
  RULE->offset[a[0]-RULE_flag] |= a[1];
}
static int isRULEflag(int *a){ /* >ptr+>flag */
  if((RULE->offset[a[0]-RULE_flag]&a[1])!=0){ return 1;}
  return 0;
}
static void clearRULEflag(int *a){ /* >ptr + >flag */
  RULE->offset[a[0]-RULE_flag] &= ~a[1];
}
/* --------------------------- */
static void openRegion(int *a){ /* >modT */
   int par[3];int ptr;
   ptr=LLOC->alwb;par[0]=0;pushRULE(par); /* separator */
   if(a[0]){par[0]=RULE->aupb;par[1]=UETmod;setRULEflag(par);}
   nxt:if(ptr>LLOC->aupb){;}else{if(LLOC->offset[ptr-LLOC_type]==Ilabel){;}
   else{par[0]=ptr;pushRULE(par);par[0]=ptr;par[1]=LTset;
     if(isLocalFlag(par)){par[0]=RULE->aupb;par[1]=Uallset;setRULEflag(par);}
     par[0]=ptr;par[1]=LTmod;if(isLocalFlag(par)){par[0]=RULE->aupb;
       par[1]=Uallmod;setRULEflag(par);}}
   par[0]=STACKpar(LLOC);par[1]=ptr;next(par);ptr=par[1];goto nxt;}
}
static void recomputeRULEflags(int *a){/* >ptr */
   int par[3];int set,mod,loc;
   par[0]=a[0];par[1]=UETset;if(isRULEflag(par)){set=1;}else{set=0;}
   par[0]=a[0];par[1]=UETmod;if(isRULEflag(par)){mod=1;}else{mod=0;}
   RULE->offset[a[0]-RULE_flag]=0;loc=RULE->offset[a[0]-RULE_data];
   if(set){par[0]=a[0];par[1]=Uallset;setRULEflag(par);par[0]=loc;
     par[1]=LTset;setLocalFlag(par);}
   else{par[0]=loc;par[1]=LTset;clearLocalFlag(par);}
   if(mod){par[0]=a[0];par[1]=Uallmod;setRULEflag(par);par[0]=loc;
     par[1]=LTmod;setLocalFlag(par);}
   else{par[0]=loc;par[1]=LTmod;clearLocalFlag(par);}
}
static void addLabel(int *a){ /* >label + >ptr */
   int par[3];
   if(a[0]){par[0]=LLOC->offset[a[0]-LLOC_tag];pushRULE(par);
     LLOC->offset[a[0]-LLOC_repr]=a[1];}
}
static int redoRegion(int *a){ /* >optr + >canT+>canF+ modT> */
  int par[3];int ptr;          /*   0       1     2      3   */
  ptr=a[0];nxt:if(RULE->offset[ptr-RULE_data]==0){;}
  else{par[0]=STACKpar(RULE);par[1]=ptr;previous(par);ptr=par[1];goto nxt;}
//printf("redoRegion, canT=%d,canF=%d,ptr=%d,flag=%x\n",a[1],a[2],ptr,RULE->offset[ptr-RULE_flag]);
  if(a[1]==0){;}else{par[0]=ptr;par[1]=UTcan;if(isRULEflag(par)){;}else{
    par[0]=ptr;par[1]=UTcan;setRULEflag(par);par[1]=Ujump;if(isRULEflag(par)){
    par[1]=Uredo;setRULEflag(par);}}}
  if(a[2]==0){;}else{par[0]=ptr;par[1]=UFcan;if(isRULEflag(par)){;}else{
    par[0]=ptr;par[1]=UFcan;setRULEflag(par);par[1]=Ujump;if(isRULEflag(par)){
    par[1]=Uredo;setRULEflag(par);}}}
  par[0]=ptr;par[1]=Uredo;if(isRULEflag(par)){
    par[0]=ptr;par[1]=Uredo;clearRULEflag(par);par[1]=UETmod;
    if(isRULEflag(par)){a[3]=1;}else{a[3]=0;}
    nxt2:if(a[0]<=ptr){;}else{par[0]=STACKpar(RULE);par[1]=ptr;next(par);
      ptr=par[1];par[0]=ptr;recomputeRULEflags(par);goto nxt2;}
    return 1;}
  return 0;
}
static void checkLabelShield(int *a){ /* >label */
  int par[2];int ptr;
  ptr=LLOC->offset[a[0]-LLOC_repr];nxt:
  par[0]=ptr;par[1]=Ushield;if(isRULEflag(par)){;}
  else if(ptr>=RULE->aupb){par[0]=unshielded_jump;par[1]=a[0];Error(2,par);}
  else{par[0]=STACKpar(RULE);par[1]=ptr;next(par);ptr=par[1];goto nxt;}
}
static void setRuleJump(int *a){ /* >modT + >ptr +jumpT> + jumpF> */
  int par[3];int loc,redo;       /*   0       1    2         3    */
//printf("setRuleJump, modT=%d\n",a[0]);
  redo=0;a[2]=a[3]=a[1];nxt:loc=RULE->offset[a[1]-RULE_data];if(loc==0){
    par[0]=a[1];par[1]=Ujump;setRULEflag(par);
    par[0]=a[1];par[1]=UTcan;if(isRULEflag(par)){a[2]=0;}
    par[0]=a[1];par[1]=UFcan;if(isRULEflag(par)){a[3]=0;}
    par[0]=a[1];par[1]=UETmod;if(isRULEflag(par)){;}else if(a[0]){
      par[0]=a[1];par[1]=UETmod;setRULEflag(par);redo=1;}
//printf("  .. end, redo=%d,modT=%d\n",redo,a[0]);
    if(redo){par[0]=a[1];par[1]=Uredo;setRULEflag(par);}}
  else{par[0]=loc;par[1]=LTmod;
    if(isLocalFlag(par)){par[0]=a[1];par[1]=UETmod;
      if(isRULEflag(par)){;}else{par[0]=a[1];par[1]=UETmod;
         setRULEflag(par);redo=1;}}
    par[0]=loc;par[1]=LTset;if(isLocalFlag(par)){;}
      else if((par[0]=a[1],par[1]=UETset,isRULEflag(par))){
        par[0]=a[1];par[1]=UETset;clearRULEflag(par);redo=1;}
    par[0]=STACKpar(RULE);par[1]=a[1];previous(par);a[1]=par[1];goto nxt;
}}
static void setupAltHeadFlags(int *a){ /* >ptr */
  int par[2];int loc; again:
  loc=RULE->offset[a[0]-RULE_data];if(loc==0){;}
  else{ par[0]=a[0];par[1]=Ualtset;if(isRULEflag(par)){par[0]=loc;
      par[1]=LTset;setLocalFlag(par);}else{par[0]=loc;par[1]=LTset;
      clearLocalFlag(par);}
   par[0]=a[0];par[1]=Ualtmod;if(isRULEflag(par)){par[0]=loc;
      par[1]=LTmod;setLocalFlag(par);}else{par[0]=loc;par[1]=LTmod;
      clearLocalFlag(par);}
   par[0]=STACKpar(RULE);par[1]=a[0];previous(par);a[0]=par[1];goto again;
}}
static void storeAltHeadFlags(int *a){ /* >ptr */
  int par[2];again:
  if(RULE->offset[a[0]-RULE_data]==0){;}
  else{par[0]=RULE->offset[a[0]-RULE_data];par[1]=LFset;
    if(isLocalFlag(par)){par[0]=a[0];par[1]=Ualtset;setRULEflag(par);}
    else{par[0]=a[0];par[1]=Ualtset;clearRULEflag(par);}
    par[0]=RULE->offset[a[0]-RULE_data];par[1]=LFmod;
    if(isLocalFlag(par)){par[0]=a[0];par[1]=Ualtmod;setRULEflag(par);}
    else{par[0]=a[0];par[1]=Ualtmod;clearRULEflag(par);}
    par[0]=STACKpar(RULE);par[1]=a[0];previous(par);a[0]=par[1];goto again;
}}
static void closeRegion(int *a){ /* >ptr */
  int par[2];int loc;
//printf(">>closeRegion: ");
  again:
  loc=RULE->offset[a[0]-RULE_data];if(loc==0){par[0]=STACKpar(RULE);par[1]=a[0];
//printf("\n");
    previous(par);a[0]=par[1];par[0]=STACKpar(RULE);par[1]=a[0];unstackto(par);}
  else{par[0]=a[0];par[1]=UTset;if(isRULEflag(par)){par[0]=loc;par[1]=LTset;
      clearLocalFlag(par);}else{par[0]=loc;par[1]=LTset;setLocalFlag(par);}
    par[0]=a[0];par[1]=UFset;if(isRULEflag(par)){par[0]=loc;par[1]=LFset;
      clearLocalFlag(par);}else{par[0]=loc;par[1]=LFset;setLocalFlag(par);}
   par[0]=a[0];par[1]=UTmod;if(isRULEflag(par)){par[0]=loc;par[1]=LTmod;
      setLocalFlag(par);}else{par[0]=loc;par[1]=LTmod;clearLocalFlag(par);}
   par[0]=a[0];par[1]=UFmod;if(isRULEflag(par)){par[0]=loc;par[1]=LFmod;
      setLocalFlag(par);}else{par[0]=loc;par[1]=LFmod;clearLocalFlag(par);}
//printf("%02x,",LLOC->offset[loc-LLOC_flag]);
   par[0]=STACKpar(RULE);par[1]=a[0];previous(par);a[0]=par[1];goto again;
}}
static void mergeAltSequenceFlags(int *a){ /* >ptr + >canT + >canF */
  int par[2];int loc; again:
  loc=RULE->offset[a[0]-RULE_data];if(loc==0){;}
  else{if(a[1]){par[0]=loc;par[1]=LTset;if(isLocalFlag(par)){;}
      else{par[0]=a[0];par[1]=UTset;setRULEflag(par);}
      par[0]=loc;par[1]=LTmod;if(isLocalFlag(par)){par[0]=a[0];par[1]=UTmod;
        setRULEflag(par);}}
   if(a[2]){par[0]=loc;par[1]=LFset;if(isLocalFlag(par)){;}
      else{par[0]=a[0];par[1]=UFset;setRULEflag(par);}
      par[0]=loc;par[1]=LFmod;if(isLocalFlag(par)){par[0]=a[0];par[1]=UFmod;
        setRULEflag(par);}}
   par[0]=STACKpar(RULE);par[1]=a[0];previous(par);a[0]=par[1];goto again;
}}
static void clearTailFbits(int *a){/* >ptr */
  int par[3]; again:
  if(RULE->offset[a[0]-RULE_data]==0){;}
  else{par[0]=a[0];par[1]=UtailBits;clearRULEflag(par);par[0]=STACKpar(RULE);
    par[1]=a[0];previous(par);a[0]=par[1];goto again;}
}
static void mergeTailFbits(int *a){/* >ptr */
  int par[3]; again:
  if(RULE->offset[a[0]-RULE_data]==0){;}
  else{par[0]=RULE->offset[a[0]-RULE_data];par[1]=LFset;if(isLocalFlag(par)){;}
    else{par[0]=a[0];par[1]=UtailFset;setRULEflag(par);}
       par[0]=RULE->offset[a[0]-RULE_data];par[1]=LFmod;if(isLocalFlag(par)){
       par[0]=a[0];par[1]=UtailFmod;setRULEflag(par);}
    par[0]=STACKpar(RULE);par[1]=a[0];previous(par);a[0]=par[1];goto again;}
}
static void useTailFbits(int *a){ /* >ptr */
  int par[3]; int loc; again:
  loc=RULE->offset[a[0]-RULE_data];if(loc==0){;}
  else{par[0]=a[0];par[1]=UtailFset;if(isRULEflag(par)){par[0]=loc;
    par[1]=LFset;clearLocalFlag(par);}else{par[0]=loc;par[1]=LFset;
    setLocalFlag(par);}
    par[0]=a[0];par[1]=UtailFmod;if(isRULEflag(par)){par[0]=loc;
    par[1]=LFmod;setLocalFlag(par);}else{par[0]=loc;par[1]=LFmod;
    clearLocalFlag(par);}
    par[0]=STACKpar(RULE);par[1]=a[0];previous(par);a[0]=par[1];goto again;
}}
/* ============================================= */
static void where(int *a){/* >rtag+>cnt+w> */
  if(a[0]==0){a[2]=in_none;}
  else if(a[1]==0){a[2]=in_extension;}
  else{a[2]=in_rule;}
}
static int hasListType(int *a){/* >tag */
  int par[2];
  par[0]=a[0];getType(par);if(par[1]==Itable||par[1]==Istack||
    par[1]==IformalTable||par[1]==IformalStack){return 1;}
  return 0;
}
static void mustBeOfListType(int *a){ /* >rtag+>cnt+>atag */
  int par[5];int type,w;
  par[0]=a[2];getType(par);type=par[1];
  if(type==Iempty){par[0]=not_defined;par[1]=a[2];Error(2,par);}
  else{par[0]=a[0];par[1]=a[1];where(par);w=par[2];
    par[0]=must_be_list;par[1]=w;par[2]=a[0];par[3]=a[2];par[4]=type;
    Error(5,par);}
}
static void checkSsel(int *a){/* >rtag+>cnt+>tag */
  int par[4];int x;par[0]=a[2];getType(par);if(par[1]==Itable||
    par[1]==Istack||par[1]==IstaticStack){par[0]=a[2];getSsel(par);
    x=par[1];}else{par[0]=a[2];getLocalSsel(par);x=par[1];}
   if(x>0){;}else{par[0]=a[0];par[1]=a[1];where(par);x=par[2];
      par[0]=undefined_standard_selector;par[1]=x;par[2]=a[0];
      par[3]=a[2];Error(4,par);}
}
static void readSelector(int *a){/* >rtag+>cnt+x> */
  int par[4];int tag,w;
  if(Qcons(par)){a[2]=par[0];}
  else{mustQtag(par);tag=par[0];getRepr(par);a[2]=par[1];if(a[2]>0){;}
   else{par[0]=a[0];par[1]=a[1];where(par);w=par[2];
   par[0]=undefined_selector;par[1]=w;par[2]=a[0];par[3]=tag;Error(4,par);}}
}
static void skipSource(void){
  int par[1];
  if(Qcons(par)){;}
  else if((par[0]=Dlwb,Q(par))||(par[0]=Dupb,Q(par))||
    (par[0]=Dvlwb,Q(par))||(par[0]=Dvupb,Q(par))||(par[0]=Dcalibre,Q(par))){
    mustQtag(par);}
  else if((par[0]=Dsub,Q(par))){skipSource();par[0]=Dbus;mustQ(par);
    mustQtag(par);if(Qcons(par)){;}else{mustQtag(par);}}
  else if((par[0]=Dnoarg,Q(par))){;}
  else{mustQtag(par);}
}
static void skipAffixes(void){
  int par[1];again:
  par[0]=Dplus;if(Q(par)){skipSource();goto again;}
}
/* ================================================== */
static void affixTypeError(int *a){/* >rtag+ >cnt + >atag */
  int par[5];int atype,w;
  if(a[2]==0){par[0]=a[0];par[1]=a[1];where(par);w=par[2];
    par[0]=syntax_error;par[1]=w;par[2]=a[0];Error(3,par);}
  else{par[0]=a[2];getType(par);atype=par[1];if(atype==Iempty){par[0]=not_defined;
    par[1]=a[2];Error(2,par);}else{par[0]=a[0];par[1]=a[1];
    where(par);w=par[2];
    par[0]=wrong_affix_type;par[1]=w;par[2]=a[0];par[3]=a[2];par[4]=atype;
    Error(5,par);}}
}
static void affixUninitializedError(int *a){/* >rtag+>cnt+>atag */
  int par[4];
  par[0]=a[0];par[1]=a[1];where(par);par[0]=affix_no_value;par[1]=par[2];
  par[2]=a[0];par[3]=a[2];Error(4,par);
}
static void constantAffixError(int *a){/* >rtag+>cnt */
 int par[3];par[0]=a[0];par[1]=a[1];where(par);
 par[0]=cannot_be_constant;par[1]=par[2];par[2]=a[0];Error(3,par);
}
static void destListTypeError(int *a){/* >rtag+>cnt+>atag */
  int par[4];par[0]=a[0];par[1]=a[1];where(par);par[0]=
  limit_cannot_be_used;par[1]=par[2];par[2]=a[0];par[3]=a[2];
  Error(4,par);
}
static void destTypeError(int *a){/* >rtag+>cnt+>atag */
  int par[5];int w,dl;
  par[0]=a[0];par[1]=a[1];where(par);w=par[2];par[0]=a[2];
  getDefline(par);dl=par[1];par[0]=provides_wrong_type;par[1]=w;
  par[2]=a[0];par[3]=a[2];par[4]=dl;Error(5,par);
}
static void dummyAffixError(int *a){ /* >rtag+>cnt */
  int par[3];
  par[0]=a[0];par[1]=a[1];where(par);par[0]=wrong_dummy_affix;
  par[1]=par[2];par[2]=a[0];Error(3,par);
}
/* ----------------------------------------------------- */
static void ffileAffix(int *a){ /* >rtag + >cnt */
  int par[3];int atag,type;
  if(Ltag(par)){atag=par[0];getType(par);type=par[1];
   if(type==IformalFile||type==Icharfile||type==Idatafile){;}
   else{par[0]=a[0];par[1]=a[1];par[2]=atag;affixTypeError(par);}}
  else{par[0]=a[0];par[1]=a[1];par[2]=0;affixTypeError(par);
       skipSource();}
}
static void checkCalibre(int *a){ /* >rtag+>formal+>actual */
  int par[5];int x,atype,acalibre,assel;
  par[0]=a[1];getFormalCalibre(par);x=par[1];if(x<0){return;}
  par[0]=a[2];getType(par);atype=par[1];
  if(atype==IformalTable||atype==IformalStack){par[0]=a[2];
    getLocalCalibre(par);acalibre=par[1];if(acalibre>=0){;}else{acalibre=1;}
    par[0]=a[2];getLocalSsel(par);assel=par[1];}
  else{par[0]=a[2];getCalibre(par);acalibre=par[1];par[0]=a[2];
    getSsel(par);assel=par[1];}
  if(x==acalibre){;}else{par[0]=a[0];par[1]=rmacro;if(isTagFlag(par)){
    par[0]=actual_calibre_different;par[1]=in_macro;par[2]=a[0];
    par[3]=a[2];par[4]=x;Error(5,par);}else{
    par[0]=actual_calibre_different;par[1]=in_rule;
    par[2]=a[0];par[3]=a[2];par[4]=x;Warning(7,5,par);}}
  par[0]=a[1];getFormalSsel(par);x=par[1];if(x==assel){;}
  else{par[0]=a[0];par[1]=rmacro;if(isTagFlag(par)){
     par[0]=actual_ssel_different;par[1]=in_macro;par[2]=a[0];
     par[3]=a[2];Error(4,par);}else{
     par[0]=actual_ssel_different;par[1]=in_rule;par[2]=a[0];
     par[3]=a[2];Warning(7,4,par);}}
}
static void ftableAffix(int *a){/* >rtag + >cnt + >formal */
  int par[3]; int atag;
  if(Ltag(par)){atag=par[0];if(hasListType(par)){par[0]=a[0];par[1]=a[2];
    par[2]=atag;checkCalibre(par);}
    else{par[0]=a[0];par[1]=a[1];par[2]=atag;affixTypeError(par);}}
  else{par[0]=a[0];par[1]=a[1];par[2]=0;affixTypeError(par);
      skipSource();}
}
static void fstackAffix(int *a){/* >rtag + >cnt +>formal */
  int par[3];int atag,type;
  if(Ltag(par)){atag=par[0];getType(par);type=par[1];
   if(type==IstaticStack){par[0]=atag;par[1]=timported;
     if(isTagFlag(par)){par[0]=a[0];par[1]=a[1];par[2]=atag;affixTypeError(par);}
     else{par[0]=a[0];par[1]=a[2];par[2]=atag;checkCalibre(par);}}
   else if(type==IformalStack){par[0]=atag;par[1]=LTmod;setLocalFlag(par);
     par[0]=a[0];par[1]=a[2];par[2]=atag;checkCalibre(par);}
   else if(type==Istack){par[0]=a[0];par[1]=a[2];par[2]=atag;checkCalibre(par);}
   else{par[0]=a[0];par[1]=a[1];par[2]=atag;affixTypeError(par);}}
  else{par[0]=a[0];par[1]=a[1];par[2]=0;affixTypeError(par);skipSource();}
}
static void fshiftAffix(int *a){ /* >rtag+>cnt */
  int par[2];
  if(Ltag(par)){getType(par);if(par[1]==IformalRepeat){;}
    else{par[0]=missing_repeat_affix;par[1]=a[0];Error(2,par);}}
  else{par[0]=missing_repeat_affix;par[1]=a[0];Error(2,par);skipSource();}
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#define Uout	0x452300
#define Uinout	0x452301
#define Uin	0x452302
#define Uslice	0x452303

inline static int uReadOnly(int *a){
  if(a[0]>=Uin){ return 1;} else {return 0;}
}
static void getFtype(int *a){/* >tag + type> */
  int par[2];
  getType(a);if(a[1]==IstaticStack){par[0]=a[0];par[1]=timported;
    if(isTagFlag(par)){a[1]=Itable;}else{a[1]=Istack;}}
  else if(a[1]==IstaticVar){par[0]=a[0];par[1]=timported;
    if(isTagFlag(par)){a[1]=Iconstant;}else{a[1]=Ivariable;}}
}

static void fsimpleAffix(int *a){ /* >rtag+ >cnt+ >utype + mod> */
  int par[4];int atag,type;       /*   0      1      2      3    */
//printf("\nsimple affix, cnt=%d,ut=%x\n",a[1],a[2]);
  if(Qcons(par)){a[3]=0;if(a[2]==Uin){;}else{par[0]=a[0];par[1]=a[1];
    constantAffixError(par);}}
  else if((par[0]=Dvlwb,Q(par))||(par[0]=Dvupb,Q(par))||(par[0]=Dlwb,
    Q(par))||(par[0]=Dupb,Q(par))){a[3]=0;mustLtag(par);atag=par[0];
    if(hasListType(par)){;}else{par[0]=a[0];par[1]=a[1];par[2]=atag;
      mustBeOfListType(par);}
    par[0]=a[2];if(uReadOnly(par)){;}else{par[0]=a[0];par[1]=a[1];
      par[2]=atag;destListTypeError(par);}}
  else if((par[0]=Dcalibre,Q(par))){a[3]=0;mustLtag(par);atag=par[0];
    if(hasListType(par)){;}else{par[0]=a[0];par[1]=a[1];par[2]=atag;
      mustBeOfListType(par);}
    if(a[2]==Uin){;}else{par[0]=a[0];par[1]=a[1];par[2]=atag;
      destListTypeError(par);}}
  else if(par[0]=Dsub,Q(par)){par[0]=a[0];par[1]=a[1];par[2]=Uslice;
    fsimpleAffix(par);a[3]=par[3];par[0]=Dbus;mustQ(par);mustLtag(par);
//printf("\nindex utan, tag=%d\n",par[0]);
    atag=par[0];par[0]=a[0];par[1]=a[1];readSelector(par);par[0]=atag;
    getFtype(par);type=par[1];
     if(type==Itable||type==IformalTable){par[0]=a[2];
       if(uReadOnly(par)){;}else{par[0]=a[0];par[1]=a[1];par[2]=atag;
         destTypeError(par);}}
     else if(type==Istack){par[0]=a[2];if(uReadOnly(par)){;}else{a[3]=1;}}
     else if(type==IformalStack){par[0]=a[2];if(uReadOnly(par)){;}
       else{a[3]=1;par[0]=atag;par[1]=LTmod;setLocalFlag(par);}}
     else{par[0]=a[0];par[1]=a[1];par[2]=atag;mustBeOfListType(par);}}
  else if(par[0]=Dnoarg,Q(par)){a[3]=0;if(a[2]==Uout){;}else{
    par[0]=a[0];par[1]=a[1];dummyAffixError(par);}}
  else{a[3]=0;mustQtag(par);atag=par[0];par[0]=STACKpar(LLOC);par[1]=atag;
    if(was(par)&&a[1]!=Uout){par[0]=atag;par[1]=Lused;setLocalFlag(par);}
    par[0]=atag;getFtype(par);type=par[1];
    if(type==Itable||type==IformalTable){par[0]=a[0];par[1]=a[1];
       par[2]=atag;checkSsel(par);par[0]=a[2];if(uReadOnly(par)){;}
       else{par[0]=a[0];par[1]=a[1];par[2]=atag;destTypeError(par);}}
    else if(type==Istack){par[0]=a[0];par[1]=a[1];par[2]=atag;
       checkSsel(par);par[0]=a[2];if(uReadOnly(par)){;}else{a[3]=1;}}
    else if(type==IformalStack){par[0]=a[0];par[1]=a[1];par[2]=atag;
       checkSsel(par);par[0]=a[2];if(uReadOnly(par)){;}else{a[3]=1;
         par[0]=atag;par[1]=LTmod;setLocalFlag(par);}}
    else if(type==Iconstant){if(a[2]==Uin){;}
       else if(a[2]==Uslice){par[0]=a[0];par[1]=a[1];where(par);
         par[0]=maybe_wrong_index;par[1]=par[2];par[2]=a[0];par[3]=atag;
         Warning(2,4,par);}
       else{par[0]=a[0];par[1]=a[1];par[2]=atag;destTypeError(par);}}
   else if(type==IpointerConstant){par[0]=a[2];if(uReadOnly(par)){;}
       else{par[0]=a[0];par[1]=a[1];par[2]=atag;destTypeError(par);}}
   else if(type==Ivariable){par[0]=a[2];if(uReadOnly(par)){;}else{a[3]=1;}}
   else if(type==IformalIn){par[0]=a[2];if(uReadOnly(par)){;}
       else{par[0]=atag;par[1]=LTmod;setLocalFlag(par);par[0]=ruleCompiled;
         par[1]=rmacro;if(isTagFlag(par)){par[0]=cannot_modify_read_only_macro;
          par[1]=a[0];par[2]=atag;Error(3,par);}
          else{par[0]=atag;par[1]=Lvararg;if(isLocalFlag(par)){
            par[0]=cannot_modify_read_only_vararg;par[1]=a[0];
            par[1]=atag;Error(3,par);}}}}
   else if(type==IformalInout){par[0]=a[2];if(uReadOnly(par)){;}
       else{par[0]=atag;par[1]=LTmod;setLocalFlag(par);}}
   else if(type==IformalOut||type==Ilocal){if(a[2]==Uout){par[0]=atag;
       par[1]=LTset;setLocalFlag(par);}else if((par[0]=atag,par[1]=LTset,
       isLocalFlag(par))){;}else{par[0]=a[0];par[1]=a[1];par[2]=atag;
       affixUninitializedError(par);}par[0]=a[2];if(uReadOnly(par)){;}
       else if(type==Ilocal){;}else{par[0]=atag;par[1]=LTmod;setLocalFlag(par);}}
   else{par[0]=a[0];par[1]=a[1];par[2]=atag;affixTypeError(par);}
}}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */
static void matchFormalActual(int *a){/* >tag + >cnt + >formal + mod> */
  int par[4];int ftype;
  par[0]=a[2];getType(par);ftype=par[1];
  if(ftype==IformalFile){par[0]=a[0];par[1]=a[1];ffileAffix(par);a[3]=0;}
  else if(ftype==IformalTable){par[0]=a[0];par[1]=a[1];par[2]=a[2];ftableAffix(par);a[3]=0;}
  else if(ftype==IformalStack){par[0]=a[0];par[1]=a[1];par[2]=a[2];fstackAffix(par);a[3]=1;}
  else if(ftype==IformalShift){par[0]=a[0];par[1]=a[1];fshiftAffix(par);a[3]=0;}
  else if(ftype==IformalIn){par[0]=a[0];par[1]=a[1];par[2]=Uin;
      fsimpleAffix(par);a[3]=par[3];}
  else if(ftype==IformalOut){par[0]=a[0];par[1]=a[1];par[2]=Uout;
      fsimpleAffix(par);a[3]=par[3];}
  else if(ftype==IformalInout){par[0]=a[0];par[1]=a[1];par[2]=Uinout;
      fsimpleAffix(par);a[3]=par[3];}
  else{par[0]=wrong_formal_type;par[1]=ftype;internalError(2,par);}
}
/* ================================================== */
static int 
repeat_block_size_mismatch,repeat_block_type_mismatch,recursive_macro,
macro_cannot_call,undefined_rule,additional_affix,missing_affix;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_msg2(void){
   addMSG("rule %p: repeat block size mismatch (%l)",repeat_block_size_mismatch);
   addMSG("rule %p: repeat block type mismatch for affix %p, required: %p, given: %p (%l)",
               repeat_block_type_mismatch);
   addMSG("rule %p: a macro rule cannot call itself",recursive_macro);
   addMSG("a macro rule cannot call \"%p\"",macro_cannot_call);
   addMSG("\"%p\" is is %p, not a rule (%l)",undefined_rule);
   addMSG("rule %p: additional actual affixes (%l)",additional_affix);
   addMSG("rule %p: missing actual affixes (%l)",missing_affix);
//   addMSG("",);
//   addMSG("",);
}
#undef addMSG

/* ------------------------------------------------- */
static int compatibleRepeatBlockType(int *a){/* >provide + >require */
  if(a[1]==a[0]){return 1;}
  if(a[1]==IformalTable && a[0]==IformalStack){return 1;}
  if(a[1]==IformalIn && a[0]==IformalInout){return 1;}
  if(a[1]==IformalOut && a[0]==IformalInout){return 1;}
  return 0;
}
static void matchRepeatAffixes(int *a){/* >rtag + >actual + >formal + >modT> */
  int par[6];int type,ftype,dl;        /*   0         1         2        3   */
  par[0]=a[0];getDefline(par);dl=par[1];nxt:
  par[0]=a[2];getAdm(par);a[2]=par[1];par[0]=STACKpar(LLOC);par[1]=a[1];
  next(par);a[1]=par[1];par[0]=a[1];getType(par);type=par[1];
  if(a[2]==0){if(type==Ilabel){;}else{par[0]=repeat_block_size_mismatch;
     par[1]=a[0];par[2]=dl;Error(3,par);}}
  else if(type==Ilabel){par[0]=repeat_block_size_mismatch;par[1]=a[0];
     par[2]=dl;Error(3,par);}
  else{par[0]=a[2];getType(par);ftype=par[1];par[0]=type;par[1]=ftype;
    if(compatibleRepeatBlockType(par)){par[0]=a[1];par[1]=Lused;setLocalFlag(par);
       if(ftype==IformalStack){a[3]=1;par[0]=a[1];par[1]=LTmod;setLocalFlag(par);}
       else if(type==IformalOut){par[0]=a[1];par[1]=LTmod;setLocalFlag(par);
          par[0]=a[1];par[1]=LTset;setLocalFlag(par);}
       else if(ftype==IformalOut){par[0]=a[1];par[1]=LTmod;setLocalFlag(par);}
       else if(ftype==IformalInout){par[0]=a[1];par[1]=LTmod;setLocalFlag(par);}
       goto nxt;}
    else{par[0]=repeat_block_type_mismatch;par[1]=a[0];par[2]=a[1];par[3]=type;
        par[4]=ftype;par[5]=dl;Error(6,par);}}
}
static int actualRepeatAffix(int *a){/* >rtag + >fml + >modT> */
  int par[4];int dpos,dline,tag,type;
  saveDiscPosition(par);dpos=par[0];dline=par[1];par[0]=Dplus;
  if(Q(par) && Qtag(par)){tag=par[0];getType(par);type=par[1];
    if(type==IformalRepeat){par[0]=tag;par[1]=Lused;setLocalFlag(par);
      par[0]=tag;par[1]=LTset;setLocalFlag(par);par[0]=tag;par[1]=LTmod;
      if(isLocalFlag(par)){;}else{par[0]=no_pending_repeat_block;par[1]=a[0];
        par[2]=tag;Warning(4,3,par);}
      par[0]=a[0];par[1]=tag;par[2]=a[1];par[3]=a[2];
      matchRepeatAffixes(par);a[2]=par[3]; return 1;}}
  par[0]=dpos;par[1]=dline;restoreDiscPosition(par);return 0;
}
static void checkMacroRule(int *a){ /* >rtag */
  int par[3];
  par[0]=ruleCompiled;par[1]=rmacro;if(isTagFlag(par)){
    if(a[0]==ruleCompiled){par[0]=recursive_macro;par[1]=a[0];Error(2,par);}
    else if((par[0]=a[0],par[1]=rshiftrule,isTagFlag(par))){
      par[0]=macro_cannot_call,par[1]=a[0],Error(2,par);}}
}
/* ----------------- */
// DEBUG !!!!!
//static void printLocal(void){
//  int loc;
//  printf("LLOC: ");
//  loc=LLOC->alwb;while(loc<LLOC->aupb){printf("%x ",LLOC->offset[loc-LLOC_flag]);loc+=LLOC_CALIBRE;}
//  printf("\n");
//}
// DEBUG !!!!!!!!!!!
static void actualRule(int *a){ /* canT> + canF> + >modT> */
  int par[5];int rtag,type,formal,repeat,cnt,dl;
  a[0]=a[1]=1;mustQtag(par);rtag=par[0];getType(par);type=par[1];
  getDefline(par);dl=par[1];
  if(type==Iempty){par[0]=not_defined;par[1]=rtag;Error(2,par);skipAffixes();}
  else if(type!=Irule){par[0]=undefined_rule;par[1]=rtag;par[2]=type;par[3]=dl;
     Error(4,par);skipAffixes();}
  else{par[0]=rtag;checkMacroRule(par);
  if(rtag==Xshiftaffix){par[0]=rtag;resetAffixBlockFlags(par);}
  par[0]=rtag;par[1]=rnoReturn;if(isTagFlag(par)){a[0]=0;}
  par[0]=rtag;par[1]=rcanFail;if(isTagFlag(par)){;}else{a[1]=0;}
  par[0]=rtag;par[1]=rsideEffect;if(isTagFlag(par)){a[2]=1;}
  par[0]=rtag;getAdm(par);formal=par[1];repeat=0;cnt=1;nxt:
  if(formal==0){par[0]=Dplus;if(Qahead(par)){
      if(repeat==0){par[0]=additional_affix;par[1]=rtag;par[2]=dl;
            Error(3,par);skipAffixes();}
      else if((par[0]=rtag,par[1]=repeat,par[2]=a[2],actualRepeatAffix(par))){a[2]=par[2];}
      else{par[0]=repeat;getAdm(par);formal=par[1];goto nxt;}}}
  else{par[0]=formal;getType(par);type=par[1];
// printf("<next formal affix(%d),type=%d,",formal,type);par[0]=formal;printPointer(par);printf("-");par[0]=type;printPointer(par);printf(">\n");
    if(type==IformalRepeat){par[0]=rtag;par[1]=formal;par[2]=a[2];
        if(actualRepeatAffix(par)){a[2]=par[2];}
        else{repeat=formal;par[0]=formal;getAdm(par);formal=par[1];goto nxt;}}
    else if((par[0]=Dplus,Q(par))){par[0]=rtag;par[1]=cnt;par[2]=formal;
        matchFormalActual(par);if(par[3]){a[2]=1;}cnt++;par[0]=formal;
        getAdm(par);formal=par[1];goto nxt;}
    else{par[0]=missing_affix;par[1]=rtag;par[2]=dl;Error(3,par);}}
//printf("act.rule ");par[0]=rtag;printPointer(par);printf(" ");printLocal();//(%d,%d),(%d,0)\n",a[0],a[1],a[2]);
}}
/* extension -------------------------- */
static int
stack_expected,field_doubly_filled,wrong_extension_block,
short_extension_block,wrong_selector_in_transport,
no_external_in_zone,zone_type,cannot_reach_this_alternative,
cannot_reach_this_member,wrong_jump_to,
local_affix_not_used,label_not_used;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_msg3(void){
  addMSG("extension %p: must be a stack (%p)",stack_expected);
  addMSG("extension %p: field #%d defined twice",field_doubly_filled);
  addMSG("extension %p: wrong field list",wrong_extension_block);
  addMSG("extension %p: field list (%d) shorter than calibre (%d)",short_extension_block);
  addMSG("Fatal: transport dest, calibre=%d < selector=%d",wrong_selector_in_transport);
/* ------------------ */
  addMSG("%p: no external constant or list in zone",no_external_in_zone);
  addMSG("%p: has wrong type %p in zone (%l)",zone_type);
  addMSG("cannot reach this alternative",cannot_reach_this_alternative);
  addMSG("cannot reach this member",cannot_reach_this_member);
  addMSG("wrong jump to label %p",wrong_jump_to);
  addMSG("local affix %p: not used",local_affix_not_used);
  addMSG("label %p: not used",label_not_used);
}
#undef addMSG

static void checkExtensionBlock(int *a){ /* >tag+>calibre */
  int par[4];int ptr,cnt1,cnt;
  ptr=BUFFER->aupb;cnt=0;
//printf("check extension; calibre=%d, ptr=%d,off=%d\n",a[1],ptr,BUFFER->offset[ptr]);
  if(BUFFER->offset[ptr]==0){par[0]=wrong_extension_block;par[1]=a[0];
     Error(2,par);}
  else{nxt1:if(a[1]<=cnt){;}else if(BUFFER->offset[ptr]==0){;}
            else{ptr--;cnt++;goto nxt1;}
       cnt1=cnt;nxt2:if(a[1]<=cnt){;}else if(BUFFER->offset[ptr]==0){
              ptr--;cnt++;goto nxt2;}
      if(cnt<a[1]){par[0]=wrong_extension_block;par[1]=a[0];Error(2,par);}
      else if(cnt1<cnt){par[0]=short_extension_block;par[1]=a[0];
        par[2]=cnt1;par[3]=a[1];Warning(3,4,par);}}
}
static void transportDest(int *a){/* >tag+>calibre */
  int par[3];int x,ptr;again:
  par[0]=Dto;if(Q(par)){par[0]=a[0];par[1]=0;readSelector(par);x=par[2];
   if(x<=0){;}
   else if(a[1]<x){par[0]=wrong_selector_in_transport;par[1]=a[1];par[2]=x;
     internalError(2,par);}
   else{ptr=BUFFER->aupb-x;ptr++;if(BUFFER->offset[ptr]==0){;}
      else{par[0]=field_doubly_filled;par[1]=a[0];par[2]=x;Error(3,par);}
      BUFFER->offset[ptr]=1;}
   goto again;
}}
static void transport(int *a){/* >tag + >calibre */
  int par[4];int rptr,cnt;
  rptr=BUFFER->aupb;cnt=a[1];nxt: par[0]=STACKpar(BUFFER);par[1]=0;extend(par);
    cnt--;if(cnt>0){goto nxt;}nxt2:
    par[0]=a[0];par[1]=0;par[2]=Uin;
    fsimpleAffix(par);par[0]=a[0];par[1]=a[1];transportDest(par); par[0]=Dend;
    if(Q(par) || (par[0]=Dextension,Q(par))){;}else{goto nxt2;}
    par[0]=a[0];par[1]=a[1];checkExtensionBlock(par);
    par[0]=STACKpar(BUFFER);par[1]=rptr;unstackto(par);
}
static void extension(void){
  int par[3];int tag,type,calibre;
  mustLtag(par);tag=par[0];getType(par);type=par[1];
  if(type==IstaticStack){par[0]=tag;par[1]=timported;if(isTagFlag(par)){
     par[0]=stack_expected;par[1]=tag;par[2]=type;Error(3,par);}
     else{par[0]=tag;getCalibre(par);calibre=par[1];par[0]=tag;
       par[1]=calibre;transport(par);}}
  if(type==Istack){par[0]=tag;getCalibre(par);calibre=par[1];
     par[0]=tag;par[1]=calibre;transport(par);}
  else if(type==IformalStack){par[0]=tag;getLocalCalibre(par);
     calibre=par[1];if(calibre<=0){calibre=1;}
     par[0]=tag;par[1]=calibre;transport(par);
     par[0]=tag;par[1]=LTmod;setLocalFlag(par);}
  else if(type==Iempty){par[0]=not_defined;par[1]=tag;Error(2,par);
    par[0]=Dextension;Qskip(par);}
  else{par[0]=stack_expected;par[1]=tag;par[2]=type;Error(3,par);
    par[0]=Dextension;Qskip(par);}
}
/* classification ----------------------------------- */
static void readBox(void){
   int par[4];
   par[0]=par[1]=0;par[2]=Uin;fsimpleAffix(par);par[0]=Dbox;mustQ(par);
}
static void checkZoneMember(int *a){/* >tag + >list */
  int par[4];int type,dl;
  if(a[0]==0){return;}
  par[0]=a[0];getType(par);type=par[1];par[0]=a[0];getDefline(par);
  dl=par[1];if(type==Iempty){par[0]=not_defined;par[1]=a[0];Error(2,par);return;}
  par[0]=a[0];par[1]=texternal;if(isTagFlag(par)){par[0]=no_external_in_zone;
    par[1]=a[0];Error(2,par);return;}
 if(type==Iconstant||type==IpointerConstant){return;}
 if(a[1] &&(type==Itable||type==Istack||type==IstaticStack)){return;}
 par[0]=zone_type;par[1]=a[0];par[2]=type;par[3]=dl;Error(4,par);
}
static void checkZoneInterval(int *a){ /* >l + >r */
  int par[2];par[0]=a[0];par[1]=0;checkZoneMember(par);
  par[0]=a[1];par[1]=0;checkZoneMember(par);
}
static void classifier(int *a){ /* >empy> */
  int par[3];int tag1,tag2,cnt;again:
  tag1=tag2=cnt=0;
  if(Qcons(par)){;}else if(Qtag(par)){tag1=par[0];}else {cnt++;}
  par[0]=Dcolon;if(Q(par)){
    if(Qcons(par)){;}else if(Qtag(par)){tag2=par[0];}else{cnt++;}
    par[0]=tag1;par[1]=tag2;checkZoneInterval(par);}
  else{par[0]=tag1;par[1]=1;checkZoneMember(par);}
  if(cnt<2){;}else{a[0]=1;}
  par[0]=Dsemicolon;if(Q(par)){goto again;}
  par[0]=Darea;mustQ(par);
}
static void ruleBody(int *a);       /*        canT>+canF>+>modT>+modF>+ jumpT>+ jumpF> */
static void altTail(int *a);        /* >rloc+>canT>+canF>+>modT>+modF>+>jumpT>+ jumpF> */
static void classification(int *a){ /* >rloc +canT>+canF>+>modT>+modF>+ jumpT>+ jumpF> */
  int par[7];int lT,lF,mT,mF;       /*  0      1     2      3     4      5       6*/
  int empty,nextMod,jT,jF;
  a[1]=a[2]=a[5]=a[6]=0;a[4]=0;nextMod=a[3];nxt:
//printf("\nCLASSIFICATION, next\n");
  empty=0;par[0]=Darea;mustQ(par);par[0]=empty;classifier(par);empty=par[0];
   lT=1;jT=0;mT=nextMod;par[0]=a[0];par[1]=Ushield;clearRULEflag(par);
   par[0]=a[0];par[1]=lT;par[3]=mT;par[5]=jT;
   altTail(par);lT=par[1];lF=par[2];mT=par[3];mF=par[4];jT=par[5];jF=par[6];
   if(lT){a[1]=1;if(mT){a[3]=1;}}if(lF){a[2]=1;if(mF){a[4]=1;}}
   if(jT==0){;}else if(a[0]<=jT){;}else if(a[5]==0){a[5]=jT;}else if(jT<a[5]){a[5]=jT;}
   if(jF==0){;}else if(a[0]<=jF){;}else if(a[6]==0){a[6]=jF;}else if(jF<a[6]){a[6]=jF;}
   par[0]=a[0];par[1]=lT;par[2]=lF;mergeAltSequenceFlags(par);
//printf("CLASSIFICATION end, lT=%d, lF=%d, expecting semicolon?\n",lT,lF);
   par[0]=Dsemicolon;if(Q(par)){par[0]=a[0];setupAltHeadFlags(par);
     if(empty){par[0]=cannot_reach_this_alternative;Error(1,par);}
     goto nxt;}
}
static void compoundMember(int *a){/* canT> + canF> + >modT> + modF>+ jumpT> +jumpF> */
  int par[6];                     /* 0        1         2       3      4        5   */
  compoundLevel++;par[2]=a[2];par[4]=a[4];ruleBody(par);
  a[0]=par[0];a[1]=par[1];a[2]=par[2];a[3]=par[3];a[4]=par[4];a[5]=par[5];
//DEBUG!!!
if(a[5]==1){RULE->offset[0]=1;}
  par[0]=Dclose;mustQ(par);
  compoundLevel--;
}
/* member ----------------------------------------- */
static void member(int *a){/* >rloc+canT>+canF>+>modT>+modF>+jumpT>+jumpF>*/
  int par[6]; int label;   /*   0     1     2      3      4      5    6   */
  a[5]=a[6]=a[2]=0;a[1]=1;a[4]=a[3];par[0]=Dopen;
  if(Q(par)){par[2]=a[3];par[4]=a[5];compoundMember(par);
      a[1]=par[0];a[2]=par[1];a[3]=par[2];a[4]=par[3];a[5]=par[4];a[6]=par[5];}
  else if((par[0]=Dextension,Q(par))){extension();a[3]=1;par[0]=a[0];
      par[1]=Ushield;setRULEflag(par);}
  else if((par[0]=Djump,Q(par))){mustLtag(par);label=par[0];a[1]=0;
     par[0]=label;checkLabelShield(par);
     par[0]=a[3];par[1]=LLOC->offset[label-LLOC_repr];
     setRuleJump(par);a[5]=par[2];a[6]=par[3];}
  else if((par[0]=Dplus,Q(par))){;}
  else if((par[0]=Dminus,Q(par))){copyLocalTflagtoF();a[2]=1;a[1]=0;}
  else{copyLocalTflagtoF();par[2]=a[3];actualRule(par);a[1]=par[0];
        a[2]=par[1];a[3]=par[2];par[0]=a[0];par[1]=Ushield;setRULEflag(par);}
//printf("member: (%d,%d),(%d,%d),%d\n",a[0],a[1],a[2],a[3],a[4]);
//printf("member:jump=(%d,%d)\n",a[4],a[5]);if(a[5]==1){LLOC->offset[0]=2;}
}
static void altTail(int *a){ /* +>rloc+>canT>+canF>+>modT>+modF>+>jumpT>+jumpF> */
  int par[7];int lF,mT,mF,jF;/*   0       1      2     3      4     5       6   */
//printf("alttail in: ");printLocal();
  a[2]=a[4]=0;mT=a[3];a[6]=0;par[0]=a[0];clearTailFbits(par);
  nxt:par[0]=Dcomma;if(Q(par)){
    if(a[1]==0){mT=0;par[0]=cannot_reach_this_member;Error(1,par);}
    if(a[5]==0){;}else if(a[0]<a[5]){;}
    else{par[0]=STACKpar(RULE);par[1]=a[5];next(par);a[5]=par[1];
      par[0]=wrong_jump_to;par[1]=RULE->offset[a[5]-RULE_data];
      Error(2,par);}
    par[0]=a[0];par[3]=mT;member(par);a[1]=par[1];lF=par[2];
    mT=par[3];mF=par[4];a[5]=par[5];jF=par[6];
//DEBUG
//if(jF==1){RULE->offset[0]=1;}
    if(a[1]!=0 && mT!=0){a[3]=1;}
    if(lF!=0){if(mF){a[4]=1;}par[0]=a[0];mergeTailFbits(par);a[2]=1;}
    if(jF==0){;}else if(a[0]<jF){;}else if(a[6]==0){a[6]=jF;}
    else if(jF<a[6]){a[6]=jF;}
//if(a[6]==1){RULE->offset[0]=1;}
    goto nxt;}
  if(a[2]!=0){par[0]=a[0];useTailFbits(par);}
//printf("alttail out:");printLocal();
//printf("alt tail: (%d,%d),(%d,%d),%d\n",a[1],a[2],a[3],a[4],a[5]);
}
static void altSequence(int *a){ /* +>rloc+canT>+canF>+>modT>+modF>+jumpT>+jumpF> */
  int par[7];                    /*    0    1       2    3      4      5     6    */
  int lT,lF,mT,mF,jT,jF,nextAlt,nextMod,nextJump;
  a[1]=a[2]=a[5]=a[6]=0;a[4]=0;nextMod=a[3]; nxt:
  mT=nextMod;par[0]=a[0];par[3]=mT;member(par);lT=par[1];nextAlt=par[2];mT=par[3];
  mF=par[4];jT=par[5];nextJump=par[6];
  if(nextAlt!=0){nextMod=mF;par[0]=a[0];storeAltHeadFlags(par);}
  
  par[0]=a[0];par[1]=lT;par[3]=mT;par[5]=jT;altTail(par);
  lT=par[1];lF=par[2];mT=par[3];mF=par[4];jT=par[5];jF=par[6];
//DEBUG
if(jF==1){RULE->offset[0]=1;}
  if(lT){a[1]=1;if(mT){a[3]=1;}}if(lF){a[2]=1;if(mF){a[4]=1;}}
  if(jT==0){;}else if(a[0]<=jT){;}else if(a[5]==0||jT<a[5]){a[5]=jT;}
  if(jF==0){;}else if(a[0]<=jF){;}else if(a[6]==0||jF<a[6]){a[6]=jF;}
  par[0]=a[0];par[1]=lT;par[2]=lF;mergeAltSequenceFlags(par);
  if(nextAlt!=0){par[0]=a[0];setupAltHeadFlags(par);}
  par[0]=Dsemicolon;if(Q(par)){if(nextAlt!=0){;}else{
      par[0]=cannot_reach_this_alternative;Error(1,par);}
    if(nextJump==0){;}else if(a[0]<nextJump){;}else{par[0]=STACKpar(RULE);
      par[1]=nextJump;next(par);nextJump=par[1];par[0]=wrong_jump_to;
      par[1]=RULE->offset[nextJump-RULE_data];Error(2,par);}
    goto nxt;}
  if(nextJump==0){;}else if(a[0]<=nextJump){;}
  else if(a[6]==0||nextJump<a[6]){a[6]=nextJump;}
  if(nextAlt!=0){a[2]=1;if(nextMod){a[4]=1;}copyLocalTflagtoF();
    par[0]=a[0];par[1]=0;par[2]=1;mergeAltSequenceFlags(par);}
//printf("alt sequence: (%d,%d),(%d,%d),%d\n",a[1],a[2],a[3],a[4],a[5]);
//printf("altSequence out: ");printLocal();
}
/* ------------------ */
//DEBUG !!!!
//static void sRf(int ptr){
//  int loc=RULE->offset[ptr-RULE_data];
//  printf("%03x/%02x,",RULE->offset[ptr-RULE_flag],loc==0?0:LLOC->offset[loc-LLOC_flag]);
//}

static void ruleBody(int *a){ /* canT>+canF>+>modT>+modF>+jumpT+jumpF> */
  int par[7];                 /*  0     1       2     3     4     5    */
  int loc,label,rloc,dpos,dnum,old;
  loc=LLOC->aupb;setupLabel(par);label=par[0];setupLocals();
  par[0]=a[2];openRegion(par);rloc=RULE->aupb;par[0]=label;par[1]=rloc;
  addLabel(par);saveDiscPosition(par);dpos=par[0];dnum=par[1];again:
//printf("<<rulebody again (%d): ",rloc);par[0]=rloc;b:sRf(par[0]);if(RULE->offset[par[0]-RULE_data]!=0){par[0]-=2;goto b;}printf(">>\n");
  clearLocalError(par);old=par[0];par[0]=Dbox;
  if(Q(par)){readBox();par[0]=rloc;par[3]=a[2];classification(par);
      a[0]=par[1];a[1]=par[2];a[2]=par[3];a[3]=par[4];a[4]=par[5];a[5]=par[6];}
  else{par[0]=rloc;par[3]=a[2];altSequence(par);
      a[0]=par[1];a[1]=par[2];a[2]=par[3];a[3]=par[4];a[4]=par[5];a[5]=par[6];}
//printf("*** ");par[0]=ruleCompiled;printPointer(par);if(RULE->aupb!=rloc){printf("[%d]",RULE->aupb);}printf(" %d flags (%d,%d)-(%d,%d),%d\n",rloc,a[0],a[1],a[2],a[3],a[4]);
  par[0]=old;if(wasLocalError(par)){;}
  else if((par[0]=rloc,par[1]=a[0],par[2]=a[1],redoRegion(par))){a[2]=par[3];
//printf(">>>");
    par[0]=dpos;par[1]=dnum;restoreDiscPosition(par);goto again;}
//printf("<<rulebody end   (%d): ",rloc);par[0]=rloc;b2:sRf(par[0]);if(RULE->offset[par[0]-RULE_data]!=0){par[0]-=2;goto b2;}printf(">>\n");
  par[0]=rloc;closeRegion(par);
  if(a[0]){;}else{a[2]=0;} if(a[1]){;}else{a[3]=0;} nxt:
  if(LLOC->aupb<=loc){;}
  else{par[0]=LLOC->aupb;par[1]=Lused;if(isLocalFlag(par)){;}
     else if(LLOC->offset[LLOC->aupb-LLOC_type]==Ilabel){
       if(compoundLevel==0){;}else{par[0]=label_not_used;
         par[1]=LLOC->offset[LLOC->aupb-LLOC_tag];Warning(4,2,par);}}
     else{par[0]=local_affix_not_used;
       par[1]=LLOC->offset[LLOC->aupb-LLOC_tag];Warning(4,2,par);}
     par[0]=STACKpar(LLOC);unstack(par);goto nxt;}
//printf("rulebody exit: (%d,%d),(%d,%d),%d\n",a[0],a[1],a[2],a[3],a[4]);
}
/* ================================================== */
static int
ruletag_not_used,exit_rule_can_return,rule_cannot_succeed,
rule_can_fail,rule_cannot_fail,rule_has_global_side_effect,
rule_has_no_side_effect,fail_and_rule_side_effect,
local_not_used,formal_not_used,repeat_block_visited,
stack_formal_not_set,formal_might_change_on_true,out_formal_not_set,
out_formal_in_repeat_block,formal_does_not_change,
formal_might_change_on_false;


#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_msg4(void){
  addMSG("rule %p: not used",ruletag_not_used);
  addMSG("rule %p: exit rule can return",exit_rule_can_return);
  addMSG("rule %p: cannot succeed",rule_cannot_succeed);
  addMSG("rule %p: can fail",rule_can_fail);
  addMSG("rule %p: cannot fail",rule_cannot_fail);
  addMSG("rule %p: has global side effect",rule_has_global_side_effect);
  addMSG("rule %p: has no global side effect",rule_has_no_side_effect);
  addMSG("rule %p: can have global side effect when fails",fail_and_rule_side_effect);
  addMSG("rule %p: local affix %p not used",local_not_used);
  addMSG("rule %p: formal affix %p not used",formal_not_used);
  addMSG("rule %p: not all repeat blocks might be visited",repeat_block_visited);
  addMSG("rule %p: formal stack affix %p can be a table",stack_formal_not_set);
  addMSG("rule %p: formal affix %p might change on true exit",formal_might_change_on_true);
  addMSG("rule %p: out formal affix %p can be uninitialized",out_formal_not_set);
  addMSG("rule %p: out formal affix in repeat block unitialized",out_formal_in_repeat_block);
  addMSG("rule %p: formal affix %p does not change",formal_does_not_change);
  addMSG("rule %p: formal affix %p might change on false exit",formal_might_change_on_false);
//  addMSG("",);
}
#undef addMSG

void dCheckRule(int *a){ /* >rtag */
  int par[7];int canT,canF,modT,modF,level;
  par[0]=a[0];par[1]=tused;if(isTagFlag(par)){;}
//   par[0]=Drule;W(par);par[0]=a[0];Wtag(par);par[0]=Dpoint;W(par);}
  else{par[0]=ruletag_not_used;par[1]=a[0];Warning(3,2,par);}
//printf("****** NEW RULE ");par[0]=a[0];printPointer(par);printf(" ****\n");
  par[0]=STACKpar(RULE);scratch(par);compoundLevel=0;ruleCompiled=a[0];
  par[0]=a[0];setupFormalStack(par);modT=0;
  par[2]=modT;ruleBody(par);canT=par[0];canF=par[1];modT=par[2];modF=par[3];
  if(a[0]==Xroot){;}
  else if((par[0]=a[0],par[1]=rexit,isTagFlag(par))){
    if(canT!=0 || canF!=0 ){par[0]=exit_rule_can_return;par[1]=a[0];Error(2,par);}}
  else{if(canT){;}else{modT=0;par[0]=rule_cannot_succeed;par[1]=a[0];Error(2,par);}
    if(canF){par[0]=a[0];par[1]=rcanFail;if(isTagFlag(par)){;}
      else{par[0]=rule_can_fail;par[1]=a[0];Error(2,par);}}
    else{modF=0;par[0]=a[0];par[1]=rcanFail;if(isTagFlag(par)){
      par[0]=rule_cannot_fail;par[1]=a[0];Error(2,par);}}
    if(modT){par[0]=a[0];par[1]=rsideEffect;if(isTagFlag(par)){;}
      else{par[0]=rule_has_global_side_effect;par[1]=a[0];Error(2,par);}}
    else if(canT==0){;}
    else{par[0]=a[0];par[1]=rsideEffect;if(isTagFlag(par)){
      par[0]=rule_has_no_side_effect;par[1]=a[0];Warning(6,2,par);}}
    if(modF){par[0]=a[0];par[1]=rsideEffect;if(isTagFlag(par)){ 
      par[0]=fail_and_rule_side_effect;par[1]=a[0];Warning(5,2,par);}
      else{par[0]=fail_and_rule_side_effect;par[1]=a[0];Error(2,par);}}}
  /* check usage */
  nxt: if(LLOC->aupb<LLOC->alwb){;}
  else{int check,tag,type; type=LLOC->offset[LLOC->aupb-LLOC_type];
     if(type==Ilabel){;}
     else if(type==IformalShift){;}
     else{tag=LLOC->offset[LLOC->aupb-LLOC_tag];par[0]=LLOC->aupb;
       par[1]=Lused;if(isLocalFlag(par)){;}
       else if(LLOC->offset[LLOC->aupb-LLOC_type]==Ilocal){
           par[0]=local_not_used;par[1]=a[0];par[2]=tag;Warning(4,3,par);}
       else{par[0]=formal_not_used;par[1]=a[0];par[2]=tag;
           Warning(4,3,par);}
       if(type==IformalRepeat){check=0;par[0]=LLOC->aupb;par[1]=LTset;
         if(isLocalFlag(par)){;}
         else if((par[0]=LLOC->aupb,par[1]=LTmod,isLocalFlag(par))){
           par[0]=repeat_block_visited;par[1]=a[0];Warning(4,2,par);
           par[0]=a[0];par[1]=routvararg;if(isTagFlag(par)){par[0]=
             out_formal_in_repeat_block;par[1]=a[0];Error(2,par);}}}
       else if(type==IformalStack){check=0;par[0]=LLOC->aupb;par[1]=LTmod;
           if(isLocalFlag(par)){;}else{par[0]=stack_formal_not_set;
             par[1]=a[0];par[2]=tag;Warning(3,3,par);}}
       else if(type==IformalIn){check=canF;par[0]=LLOC->aupb;par[1]=LTmod;
           if(isLocalFlag(par)){par[0]=formal_might_change_on_true;
             par[1]=a[0];par[2]=tag;Warning(2,3,par);}}
       else if(type==IformalOut){check=canF;par[0]=LLOC->aupb;par[1]=LTset;
           if(isLocalFlag(par)){;}else{par[0]=out_formal_not_set;
             par[1]=a[0];par[2]=tag;Error(3,par);}}
       else if(type==IformalInout){check=canF;par[0]=LLOC->aupb;par[1]=LTmod;
           if(isLocalFlag(par)){;}else{par[0]=formal_does_not_change;
             par[1]=a[0];par[2]=tag;Warning(3,3,par);}}
       else{check=0;}
       par[0]=LLOC->aupb;par[1]=LFmod;if(check!=0&&isLocalFlag(par)){
          par[0]=a[0];par[1]=rmacro;if(isTagFlag(par)){level=9;}else{level=2;}
          par[0]=formal_might_change_on_false;par[1]=a[0];par[2]=tag;
          Warning(level,3,par);}}
   par[0]=STACKpar(LLOC);unstack(par);goto nxt;}
   par[0]=Dpoint;mustQ(par);
}

void initialize_drules(void){
   init_msg1();init_msg2();init_msg3();init_msg4();
}

/* EOF */
