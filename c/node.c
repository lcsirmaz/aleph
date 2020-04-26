/* node.ale */
#include "stddata.h"
#include "node.h"
#include "disc.h"
#include "tags.h"
#include "types.h"
#include "display.h"
#include "obj.h"
#include "symbols.h"
/* ======================================= */

static int local_affix_set_only,out_affix_not_used,
original_value_not_used,formal_can_be_in;
#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_msg(void){
   addMSG("rule %p: value of local affix %p not used",local_affix_set_only);
   addMSG("rule %p: affix %p set but not used",out_affix_not_used);
   addMSG("rule %p: original value of formal affix %p not used",original_value_not_used);
   addMSG("rule %p: formal affix %p does not change, can be in",formal_can_be_in);
}
#undef addMSG
static int ruleCompiled,ruleCalled;

static void diagnoseOutAffix(int *a),diagnoseLocal(int *a);

/* ======================================= */
#define Umark	0x1000
#define Uopen	0x1001
#define Uclose	0x1002
#define Uhead	0x1003
#define Unode	0x1004
#define Utrue	0x1005
#define Ufalse	0x1006
#define Usink	0x1007
#define Uplus	0x1008
#define Uminus	0x1009
#define Ujump	0x100a
#define Ubox	0x100b
#define Uuse	0x1011
#define Uset	0x1012
#define Uspare	0x1013
#define Usemicolon 0x100f
/* ------------------------------- */
static int expandFlag=0,addRULEflag=3,RULEtop=0;
static void pushRULE(int flag,int data){
  int par[4];RULEtop+=RULE_CALIBRE;
  if(addRULEflag==3){
     par[0]=STACKpar(RULE);par[1]=2;par[3-RULE_flag]=flag;
     par[3-RULE_data]=data;expandstack(par);}
}
static void extendBUFFER(int *a){
  int par[2];par[0]=STACKpar(BUFFER);par[1]=a[0];extend(par);}
static void pushBUFFER(int n,int *a){
  int par[2];while(n>0){par[0]=STACKpar(BUFFER);par[1]=a[0];extend(par);a++;n--;}
}
/* ------------------------------------ */
static void setupFormalStack(int *a){/* >rtag */
  int par[8];int formal,type;
  par[0]=STACKpar(LLOC);scratch(par);par[0]=a[0];getAdm(par);formal=par[1];
  nxt:if(formal==0){;}
  else{par[0]=formal;getType(par);type=par[1];
  par[0]=STACKpar(LLOC);par[1]=6;par[7-LLOC_repr]=-1;
  par[7-LLOC_type]=type;par[7-LLOC_tag]=formal;
  par[7-LLOC_flag]=par[7-LLOC_calibre]=par[7-LLOC_ssel]=0;expandstack(par);
  if(type==IformalStack||type==IformalTable){par[0]=formal;
    getFormalCalibre(par);LLOC->offset[LLOC->aupb-LLOC_calibre]=par[1];
    par[0]=formal;getFormalSsel(par);LLOC->offset[LLOC->aupb-LLOC_ssel]=par[1];}
  par[0]=formal;getAdm(par);formal=par[1];goto nxt;}
}
static void setupLabel(int *a){/* label> */
  int par[8];
  par[0]=Dlabel;if(Q(par)){mustQtag(par);a[0]=par[0];
   par[0]=STACKpar(LLOC);par[1]=6;par[7-LLOC_repr]=0;par[7-LLOC_type]=Ilabel;
   par[7-LLOC_tag]=a[0];par[7-LLOC_flag]=par[7-LLOC_orepr]=par[7-LLOC_otype]=0;
   expandstack(par);a[0]=LLOC->aupb;}
  else{a[0]=0;}
}
static void setupLocals(void){
  int par[8];int local;
  par[0]=Dlocal;if(Q(par)){nxt:par[0]=Dcolon;if(Q(par)){;}
   else{mustQtag(par);local=par[0];par[0]=STACKpar(LLOC);par[1]=6;par[7-LLOC_repr]=-1;
     par[7-LLOC_type]=Ilocal;par[7-LLOC_tag]=local;par[7-LLOC_flag]=
     par[7-LLOC_orepr]=par[7-LLOC_otype]=0;expandstack(par);goto nxt;}}
  else{;}
}
/* ============================ */
static int minLocal=0,maxLocal=0;
inline static void countLocal(int *a){/* >cnt + >loc */
  if(addRULEflag!=3){ return; }
  if(Ilocal!=LLOC->offset[a[1]-LLOC_type]){ return; }
  if(minLocal==0){minLocal=a[0];}
  if(maxLocal<a[0]){maxLocal=a[0];}
}

static void startRange(int *a){/* >label + rloc> */
  int par[4];int loc,cnt;
  pushRULE(Uopen,0);a[1]=RULEtop;
  if(a[0]){LLOC->offset[a[0]-LLOC_repr]=a[1];}
  loc=LLOC->alwb;cnt=0;nxt:if(loc>LLOC->aupb){;}
  else{int t=LLOC->offset[loc-LLOC_type];if(t==IformalIn||t==IformalOut||
    t==IformalInout||t==Ilocal){cnt++;pushRULE(0,loc);t=LLOC->offset[loc-LLOC_repr];
    if(t<0){LLOC->offset[loc-LLOC_repr]=cnt;
      par[0]=cnt;par[1]=loc;countLocal(par);
      par[0]=a[1];par[1]=cnt;par[2]=loc;diagnoseLocal(par);}}
//    else if(t==cnt){;}else{printf("startRange: cnt=%d, repr=%d, loc=%d\n",cnt,t,loc);exit(23);}}
    par[0]=STACKpar(LLOC);par[1]=loc;next(par);loc=par[1];goto nxt;}
}
static void closeRange(int *a){ /* >rloc */
  pushRULE(Uclose,a[0]);
}
/* =========================================== */
#define Uin	0x234501
#define Uout	0x234502
#define Uinout	0x234503
#define Uslicein    0x234511
#define Usliceout   0x234512
#define Usliceinout 0x234513

static void utypeToSlice(int *a){/* >in + out> */
  a[1]=a[0]+0x10;
}
static int inUtype(int *a){ /* >utype */
  if((a[0]&1)!=0){ return 1; }else{return 0;}
}
static int outUtype(int *a){ /* utype */
  if((a[0]&2)!=0){return 1;}else{return 0;}
}
/* optimization ================================= */
static void gsimpleAffix(int *a),galtTail(void),gmember(void),
  gruleBody(void),wruleBody(void);

static void expandMacro(int *a){/* >tag */
  int par[4];int loc,Qa,Qb,dpos,dnum;
// printf("start expanding ");printPointer(a);printf("\n");
  loc=LLOC->aupb;par[0]=a[0];macroCallHead(par);Qa=par[1];Qb=par[2];
  saveDiscPosition(par);dpos=par[0];dnum=par[1];
  par[0]=a[0];searchMacroRule(par);par[0]=par[1];par[1]=par[2];
  restoreDiscPosition(par);
  if(addRULEflag==2){wruleBody();}else{gruleBody();}
  par[0]=Dpoint;mustQ(par);
  par[0]=dpos;par[1]=dnum;restoreDiscPosition(par);par[0]=Qa;par[1]=Qb;
  macroCallTail(par);
  par[0]=STACKpar(LLOC);par[1]=loc;unstackto(par);
}

/* ------------------------------------------------- */

static void gtransportList(void){
  int par[3];again:
  par[0]=Uin;gsimpleAffix(par);nxt:
  par[0]=Dto;if(Q(par)){if(Qcons(par)){;}else{mustQtag(par);}goto nxt;}
  par[0]=Dextension;if(Q(par)){;}else if((par[0]=Dend,Qahead(par))){;}
  else{goto again;}
}
static void gextension(void){
  int par[3];
  mustQtag(par);pushRULE(Unode,0);gtransportList();pushRULE(Utrue,0);  
}
/* classification */
static void greadBox(void){
  int par[2];
  pushRULE(Unode,0);par[0]=Uin;gsimpleAffix(par);pushRULE(Utrue,0);
  pushRULE(Ubox,0);par[0]=Dbox;mustQ(par);
}
static void garea(int *a){ /* buff> */
   int par[3];int x;
   if(addRULEflag!=3){par[0]=Darea;Qskip(par);a[0]=0;return; }
   a[0]=BUFFER->aupb;getLinenum(par);x=par[0];par[0]=Dconst;par[1]=x;pushBUFFER(2,par);
   nxt:par[0]=Darea;if(Q(par)){par[0]=Dplus;extendBUFFER(par);return;}
   par[0]=Dcolon;if(Q(par)){extendBUFFER(par);goto nxt;}
   par[0]=Dsemicolon;if(Q(par)){extendBUFFER(par);goto nxt;}
   if(Qcons(par)){x=par[0];par[0]=Dconst;par[1]=x;pushBUFFER(2,par);
      goto nxt;}
   mustQtag(par);extendBUFFER(par);goto nxt;
}
static void gclassification(void){
  int par[2];int last,buff;again:
  par[0]=Darea;mustQ(par);garea(par);buff=par[0];
  pushRULE(Unode,buff);pushRULE(Ufalse,0);last=RULEtop;
  pushRULE(Utrue,0);pushRULE(Uhead,0);galtTail();par[0]=Dsemicolon;
  if(Q(par)){pushRULE(Usemicolon,0);goto again;}
  else{RULE->offset[last-RULE_flag]=Umark;}
}
/* actual rule */
static void ghandleAffix(int *a){ /* >tag + >utype */
  int par[3];
  par[0]=a[1];if(inUtype(par)){pushRULE(Uuse,LLOC->offset[a[0]-LLOC_repr]);}
  par[0]=a[1];if(outUtype(par)){par[0]=a[1];extendBUFFER(par);
    if(a[1]>=Uslicein){par[0]=Uuse;extendBUFFER(par);}
    else{par[0]=Uset;extendBUFFER(par);}
    par[0]=a[0];extendBUFFER(par);}
}
static void ghandleVarargBlock(int *a){ /*> ptr + >formal */
  int par[3];int ftype;
//DEBUG !!!
if(LLOC->offset[a[0]-LLOC_type]!=IformalRepeat){printf("ghandle: ptr=%d, type!=*\n",a[0]);exit(99);}
  nxt:par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];
  par[0]=a[1];getType(par);ftype=par[1];getAdm(par);a[1]=par[1];
  if(ftype==IformalIn){par[0]=a[0];par[1]=Uin;ghandleAffix(par);}
  else if(ftype==IformalOut){par[0]=a[0];par[1]=Uout;ghandleAffix(par);}
  else if(ftype==IformalInout){par[0]=a[0];par[1]=Uinout;ghandleAffix(par);}
  if(a[1]==0){;}else{goto nxt;}
}
static void ghandleShiftRule(int *a){/* > ptr */
  int par[3];int t; nxt:
  par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];
  t=LLOC->offset[a[0]-LLOC_type];
  if(t==Ilabel){;}
  else if(t==IformalIn){par[0]=a[0];par[1]=Uin;ghandleAffix(par);goto nxt;}
  else if(t==IformalOut){par[0]=a[0];par[1]=Uout;ghandleAffix(par);goto nxt;}
  else if(t==IformalInout){par[0]=a[0];par[1]=Uinout;ghandleAffix(par);goto nxt;}
  else{goto nxt;}
}

static int glimit(void){
  int par[1];
  par[0]=Dvlwb;if(Q(par)){return 1;}
  par[0]=Dvupb;if(Q(par)){return 1;}
  par[0]=Dlwb;if(Q(par)){return 1;}
  par[0]=Dupb;if(Q(par)){return 1;}
  par[0]=Dcalibre;if(Q(par)){return 1;}
  return 0;
}
static void gsimpleAffix(int *a){/* >utype + repeat> */
  int par[3];int tag,type;
  a[1]=0;if(Qcons(par)){;}
  else if(glimit()){mustQtag(par);}
  else if((par[0]=Dsub,Q(par))){par[0]=a[0];utypeToSlice(par);type=par[1];
    par[0]=type;gsimpleAffix(par);par[0]=Dbus;mustQ(par);
    mustQtag(par);if(Qcons(par)){;}else{mustQtag(par);}}
  else if((par[0]=Dnoarg,Q(par))){;}
  else{mustQtag(par);tag=par[0];getType(par);type=par[1];
    if(type==IformalRepeat){a[1]=tag;}
    else if(type==IformalIn||type==IformalOut||type==IformalInout||
      type==Ilocal){par[0]=tag;par[1]=a[0];ghandleAffix(par);}}
}
static void gmatchFormalActual(int *a){/*>ftype + repeat> */
  int par[3];int tag,type;
  if(a[0]==IformalFile||a[0]==IformalTable||a[0]==IformalStack){
    mustQtag(par);tag=par[0];getType(par);type=par[1];
    if(type==IformalRepeat){a[1]=tag;}else{a[1]=0;}}
  else if(a[0]==IformalShift){mustQtag(par);a[1]=par[0];}
  else if(a[0]==IformalIn){par[0]=Uin;gsimpleAffix(par);a[1]=par[1];}
  else if(a[0]==IformalOut){par[0]=Uout;gsimpleAffix(par);a[1]=par[1];}
  else if(a[0]==IformalInout){par[0]=Uinout;gsimpleAffix(par);a[1]=par[1];}
  else{printf("Internal error: gmatchFormalActual, ftype=%d\n",a[0]); exit(3);}
//if(a[1]!=0){printf("gmatch, f=%d,rep=%d ",a[0],a[1]);par[0]=a[0];printPointer(par);printf("\n");}
}
static void gactualRule(int *a){/*> tag */
   int par[3];int oldBUFF,formal,ftype,repeat,frep;
   pushRULE(Unode,0);oldBUFF=BUFFER->aupb;repeat=frep=0;
   par[0]=a[0];getAdm(par);formal=par[1];nxt:
   par[0]=Dplus;if(Q(par)){par[0]=formal;getType(par);ftype=par[1];
     if(ftype==IformalRepeat){par[0]=formal;getAdm(par);formal=par[1];
       repeat=formal;par[0]=formal;getType(par);ftype=par[1];}
     par[0]=ftype;gmatchFormalActual(par);frep=par[1];
     par[0]=formal;getAdm(par);formal=par[1];if(formal==0){formal=repeat;}
     goto nxt;}
   if(frep==0){;}
   else if(a[0]==Xshiftaffix){par[0]=frep;ghandleShiftRule(par);}
   else if((par[0]=a[0],par[1]=rshiftrule,isTagFlag(par))){;}
   else{
//DEBUF !!!
if(formal!=repeat){printf("gactualRULE, formal=%d,repeat=%d different\n",formal,repeat);exit(99);}
      par[0]=frep;par[1]=repeat;ghandleVarargBlock(par);}
   par[0]=a[0];par[1]=rcanFail;if(isTagFlag(par)){pushRULE(Ufalse,0);}
   frep=oldBUFF;nxt2:if(frep>=BUFFER->aupb){;}
   else{int flag,utype; frep++;utype=BUFFER->offset[frep];
     frep++;flag=BUFFER->offset[frep];frep++;
     pushRULE(flag,LLOC->offset[BUFFER->offset[frep]-LLOC_repr]);
     par[0]=utype;par[1]=BUFFER->offset[frep];diagnoseOutAffix(par);goto nxt2;}
   par[0]=STACKpar(BUFFER);par[1]=oldBUFF;unstackto(par);
   par[0]=a[0];par[1]=rnoReturn;if(isTagFlag(par)){
     pushRULE(Usink,0);}else{pushRULE(Utrue,0);}
}
/* ================= */
static void gcompound(void){
  int loc;int par[2];
  loc=LLOC->aupb;gruleBody();par[0]=STACKpar(LLOC);par[1]=loc;unstackto(par);
}
static void galtSequence(void){
  int par[1];again:
  gmember();pushRULE(Uhead,0);galtTail();par[0]=Dsemicolon;
  if(Q(par)){pushRULE(Usemicolon,0);goto again;}
}
static void galtTail(void){
  int par[1];again:
  par[0]=Dcomma;if(Q(par)){gmember();goto again;}
}
static void gmember(void){
  int par[2];int tag;
  par[0]=Dopen;if(Q(par)){gcompound();par[0]=Dclose;mustQ(par);return;}
  par[0]=Dextension;if(Q(par)){gextension();return;}
  par[0]=Djump;if(Q(par)){mustQtag(par);tag=par[0];
    pushRULE(Ujump,LLOC->offset[tag-LLOC_repr]); return;}
  par[0]=Dplus;if(Q(par)){pushRULE(Uplus,0);return;}
  par[0]=Dminus;if(Q(par)){pushRULE(Uminus,0);return;}
  mustQtag(par);tag=par[0];ruleCalled=tag;par[1]=rmacro;
    if(expandFlag!=0 && isTagFlag(par)){par[0]=tag;expandMacro(par);}
    else{par[0]=tag;gactualRule(par);}
//printf(" --- C1=%d,C2=%d,C3=%d, rule=",C1,C2,C3);par[0]=tag;printPointer(par);printf("\n");
}
static void gruleBody(void){
  int par[2];int label,rloc;
  setupLabel(par);label=par[0];
  setupLocals();
  par[0]=label;startRange(par);rloc=par[1];
  par[0]=Dbox;if(Q(par)){greadBox();gclassification();}
  else{galtSequence();}
  par[0]=rloc;closeRange(par);
}
/* ======================================================== */
/* traversing the RULE stack */
#define Ufinal	0x01
#define UTused	0x02
#define UFused	0x04
#define Uflag	0x08
#define Ualt	0x10
#define Uzero	0x20

static int UfinalChanged=0;

static void setRULEflag(int *a){/* >base + >off + >v */
  int ptr=a[1]*RULE_CALIBRE+a[0];
//if(a[2]&0x20){printf("setRULEflag %x\n",a[2]);RULE->offset[0]=1;}
  RULE->offset[ptr-RULE_flag]|=a[2];
}
static void clearRULEflag(int *a){/* >base + >off + >v */
  int ptr=a[1]*RULE_CALIBRE+a[0];
  RULE->offset[ptr-RULE_flag] &=~a[2];
}
static int isRULEflag(int *a){/* >base +>off+>v */
  int ptr=a[1]*RULE_CALIBRE+a[0];
  if((RULE->offset[ptr-RULE_flag]&a[2])!=0){ return 1;}
  return 0;
}

static void copyUf1ToUf2(int *a){/* >base+>Uf1 + >Uf2 */
  int par[3];int off;
  off=1;nxt:par[0]=a[0];par[1]=off;par[2]=Umark;if(isRULEflag(par)){;}
  else{par[0]=a[0];par[1]=off;par[2]=a[1];if(isRULEflag(par)){
    par[2]=a[2];setRULEflag(par);}else{par[2]=a[2];clearRULEflag(par);}
    off++;goto nxt;}
}
static void mergeUf1ToUf2(int *a){/* >base+>Uf1 + >Uf2 */
  int par[3];int off;
  off=1;nxt:par[0]=a[0];par[1]=off;par[2]=Umark;if(isRULEflag(par)){;}
  else{par[0]=a[0];par[1]=off;par[2]=a[1];if(isRULEflag(par)){
    if(a[2]!=Ufinal){;}else if((par[2]=a[2],isRULEflag(par))){;}
    else{UfinalChanged=1;}
    par[2]=a[2];setRULEflag(par);}off++;goto nxt;}
}
static void copyJumpUf(int *a){/* >from + >to */
  int par[3];int off;
  off=1;nxt1:par[0]=a[0];par[1]=off;par[2]=Umark;if(isRULEflag(par)){;}
  else{par[0]=a[0];par[1]=off;par[2]=Ufinal;if(isRULEflag(par)){
    par[0]=a[1];par[1]=off;par[2]=Uflag;setRULEflag(par);}
    else{par[0]=a[1];par[1]=off;par[2]=Uflag;clearRULEflag(par);}
    off++;goto nxt1;}
  nxt2:par[0]=a[1];par[1]=off;par[2]=Umark;if(isRULEflag(par)){;}
  else{par[0]=a[1];par[1]=off;par[2]=Uflag;clearRULEflag(par);off++;goto nxt2;}
}
static void setFlagsForRegion(int *a){/* >base+>region+>head */
  int par[3];int off;
  off=1;nxt:par[0]=a[0];par[1]=off;par[2]=Umark;if(isRULEflag(par)){;}
  else{par[0]=a[0];par[1]=off;par[2]=Uflag;if(isRULEflag(par)){
      par[0]=a[1];par[1]=off;par[2]=UTused;setRULEflag(par);}
    par[0]=a[0];par[1]=off;par[2]=a[2];if(isRULEflag(par)){
      par[0]=a[1];par[1]=off;par[2]=UFused;setRULEflag(par);}
    par[0]=a[1];par[1]=off;par[2]=Uflag;clearRULEflag(par);
    off++;goto nxt;}
}
static void recoverFlagsFromRegion(int *a){ /* >base+>region */
  int par[3];int off;
  off=1;nxt:par[0]=a[0];par[1]=off;par[2]=Umark;if(isRULEflag(par)){;}
  else{par[0]=a[1];par[1]=off;par[2]=Uflag;if(isRULEflag(par)){par[0]=a[0];
    par[1]=off;par[2]=Uflag;setRULEflag(par);}else{par[0]=a[0];par[1]=off;
    par[2]=Uflag;clearRULEflag(par);}off++;goto nxt;}
}

static void setFlagsForRule(int *a){/* >rtag */
  int par[3];int base,formal,type,cnt;
  par[0]=a[0];getAdm(par);formal=par[1];cnt=0;base=RULE->offset[RULE->aupb-RULE_data];
  nxt:if(formal==0){;}
  else{par[0]=formal;getType(par);type=par[1];
    if(type==IformalIn){cnt++;}
    else if(type==IformalOut||type==IformalInout){cnt++;
      par[0]=base;par[1]=cnt;par[2]=UTused;setRULEflag(par);}
    par[0]=formal;getAdm(par);formal=par[1];goto nxt;}
}
/* - - - - - - - - - - - - - - - - - */
static int Uptr=0;
static int B(int *a){/* >x */
  if(RULE->offset[Uptr-RULE_flag]==a[0]){Uptr-=RULE_CALIBRE;return 1;}
  return 0;
}
static int Bdata(int *a){/* >x + d> */
  if(RULE->offset[Uptr-RULE_flag]==a[0]){a[1]=RULE->offset[Uptr-RULE_data];
     Uptr-=RULE_CALIBRE;return 1;}
  return 0;
}
static void BsetFlag(int *a){/* >new */
  RULE->offset[Uptr+RULE_CALIBRE-RULE_flag]=a[0];
}
static void BsetData(int *a){/* >new */
  RULE->offset[Uptr+RULE_CALIBRE-RULE_data]=a[0];
}
static void Bback(void){Uptr-=RULE_CALIBRE;}
static void BgetPtr(int *a){ /* ptr> */
   a[0]=Uptr+RULE_CALIBRE;
}
/* ---------------------------------- */
static void Ualternative(int *a);
static int UactualRule(int *a),Umember(int *a);
static void Uregion(int *a){/* >base */
  int par[3]; 
  par[0]=a[0];par[1]=UFused;par[2]=Ualt;copyUf1ToUf2(par);
//printf("Uregion start at %d (%d)\n",(a[0]-RULE->alwb)/2,a[0]);
  again:
  par[0]=a[0];Ualternative(par);par[0]=a[0];par[1]=Uflag;par[2]=Ualt;
  copyUf1ToUf2(par);
//printf("ALT at %d ",(Uptr-RULE->alwb)/2);{int x=a[0]+2;while((RULE->offset[x-RULE_flag]&Umark)==0){printf("%02x ",RULE->offset[x-RULE_flag]);x+=2;}printf("\n");}
  par[0]=Usemicolon;if(B(par)){goto again;}
  par[0]=Ubox;if(B(par)){par[0]=a[0];par[1]=UFused;
    if(UactualRule(par)){;}else{printf("Uregion: box wrong\n");exit(4);}}
  /* skip the storage area */
  nxt:par[0]=Uopen;if(B(par)){;}else{Uptr-=BUFFER_CALIBRE;goto nxt;}
  par[0]=a[0];par[1]=Uflag;par[2]=Ufinal;mergeUf1ToUf2(par);
//printf("MRG at %d ",(Uptr-RULE->alwb)/2);{int x=a[0]+2;while((RULE->offset[x-RULE_flag]&Umark)==0){printf("%02x ",RULE->offset[x-RULE_flag]);x+=2;}printf("\n");}
}
static int UactualRule(int *a){/* >base+ >Uf */
  int par[3];int cnt;
  par[0]=Utrue;if(B(par)){;}else if((par[0]=Usink,B(par))){
    par[0]=a[0];par[1]=Uzero;par[2]=Uflag;copyUf1ToUf2(par);}
  else{return 0;}
  nxt:par[0]=Uuse;if(Bdata(par)){cnt=par[1];par[0]=a[0];par[1]=cnt;
    par[2]=Uflag;setRULEflag(par);
//printf("USE: cnt=%d,base=%d, flag=%x\n",cnt,(a[0]-RULE->alwb)/2,RULE->offset[a[0]+2*cnt-RULE_flag]);
    goto nxt;}
  par[0]=Uset;if(Bdata(par)){cnt=par[1];par[0]=a[0];par[1]=cnt;par[2]=Uflag;
     if(isRULEflag(par)){;}else{par[0]=Uspare;BsetFlag(par);}
     par[0]=a[0];par[1]=cnt;par[2]=Uflag;clearRULEflag(par);goto nxt;}
  par[0]=Uspare;if(Bdata(par)){cnt=par[1];par[0]=a[0];par[1]=cnt;par[2]=Uflag;
     if(isRULEflag(par)){par[0]=Uset;BsetFlag(par);}
     par[0]=a[0];par[1]=cnt;par[2]=Uflag;clearRULEflag(par);goto nxt;}
  par[0]=Umark;if(B(par)){goto nxt;}
  par[0]=Ufalse;if(B(par)){par[0]=a[0];par[1]=a[1];par[2]=Uflag;mergeUf1ToUf2(par);
     goto nxt;}
  par[0]=Unode;if(B(par)){;}
  else{printf("FATAL: Uactual node looking at unexpected\n");exit(4);}
  return 1;
}

static int Umember(int *a){/* >base+ >Uf */
  int par[3];int ptr;
  par[0]=Ujump;if(Bdata(par)){par[0]=par[1];par[1]=a[0];copyJumpUf(par);return 1;}
  par[0]=Uplus;if(B(par)){par[0]=a[0];par[1]=UTused;par[2]=Uflag;
    copyUf1ToUf2(par);return 1;}
  par[0]=Uminus;if(B(par)){par[0]=a[0];par[1]=a[1];par[2]=Uflag;
    copyUf1ToUf2(par);return 1;}
  par[0]=a[0];par[1]=a[1];if(UactualRule(par)){return 1;}
  par[0]=Uclose;if(Bdata(par)){ptr=par[1];par[0]=a[0];par[1]=ptr;
    par[2]=a[1];setFlagsForRegion(par);par[0]=ptr;Uregion(par);
    par[0]=a[0];par[1]=ptr;recoverFlagsFromRegion(par);return 1;}
  return 0;
}
static void Ualternative(int *a){/* >base */
  int par[3];
  par[0]=a[0];par[1]=UTused;par[2]=Uflag;copyUf1ToUf2(par);nxt:
  par[0]=Uhead;if(B(par)){par[0]=a[0];par[1]=Ualt;
   if(Umember(par)){;}else{printf("FATAL: Ualternativewrong member\n");exit(4);}
   return;}
  par[0]=a[0];par[1]=UFused;if(Umember(par)){goto nxt;}
}
static void traverseRULE(int *a){ /* >tag */
  int par[2];int ptr;
  setFlagsForRule(a);nxt:Uptr=RULE->aupb;par[0]=Uclose;
  if(Bdata(par)){ptr=par[1];}else{printf("traverseRULE:not Uclose\n");exit(8);}
  UfinalChanged=0;par[0]=ptr;Uregion(par);if(UfinalChanged){goto nxt;}
}
/* -------------------------------------------------------------------- */
#define LtrueLabel	-1
#define LfalseLabel	-2

static void Lscani(int *a){/* >tlab+>flab+nlab> */
  int par[3];int alab,ulab;
  ulab=alab=a[1];a[2]=a[0];nxt:
  par[0]=Usemicolon;if(B(par)){alab=a[2];a[2]=a[0];ulab=a[1];goto nxt;}
  par[0]=Uplus;if(B(par)){par[0]=a[2];BsetData(par);goto nxt;}
  par[0]=Uminus;if(B(par)){par[0]=ulab;BsetData(par);a[2]=ulab;goto nxt;}
  par[0]=Uhead;if(B(par)){ulab=alab; goto nxt;}
  par[0]=Utrue;if(B(par)){par[0]=a[2];BsetData(par);goto nxt;}
  par[0]=Ufalse;if(B(par)){par[0]=ulab;BsetData(par);a[2]=ulab;goto nxt;}
  par[0]=Unode;if(B(par)){BgetPtr(par);a[2]=par[0];goto nxt;}
  par[0]=Ujump;if(Bdata(par)){a[2]=par[1];goto nxt;}
  par[0]=Uclose;if(B(par)){par[0]=a[2];par[1]=ulab;Lscani(par);a[2]=par[2];
    goto nxt;}
  par[0]=Uopen;if(B(par)){par[0]=a[2];BsetData(par);}
  else{Bback(); goto nxt;}
}
static void Lunroll(int *a){/* >ptr */
  int par[3];int data;
  data=RULE->offset[a[0]-RULE_data];
  if(data==LtrueLabel){;}
  else if(data==LfalseLabel){;}
  else if(data==0){printf("Lunroll: internal error, ptr=%d\n",a[0]);exit(24);}
  else if(RULE->offset[data-RULE_flag]==Unode){;}
  else{RULE->offset[a[0]-RULE_data]=0;par[0]=data;Lunroll(par);
     RULE->offset[a[0]-RULE_data]=RULE->offset[data-RULE_data];}
}
static void Lscanii(void){
  int par[2];int ptr;
  ptr=RULE->alwb;nxt:if(ptr>RULE->aupb){;}
  else{ if(RULE->offset[ptr-RULE_flag]==Utrue||RULE->offset[ptr-RULE_flag]==Ufalse){
     par[0]=ptr;Lunroll(par);}ptr+=RULE_CALIBRE;goto nxt;}
}
static void LfindLabels(void){
  int par[3];
  Uptr=RULE->aupb;par[0]=Uclose;B(par);
  par[0]=LtrueLabel;par[1]=LfalseLabel;Lscani(par);
  Lscanii();
}
/* ==================================================================== */
/* disgnostic bits */
#define UDuse	0x100
#define UDset	0x200
static void mergeDUflags(int *a){/* >base + >region */
  int par[3];int off;
  off=1;nxt:par[0]=a[0];par[1]=off;par[2]=Umark;
  if(isRULEflag(par)){;}
  else{par[0]=a[1];par[1]=off;par[2]=UDuse;if(isRULEflag(par)){
      par[0]=a[0];setRULEflag(par);}
    par[0]=a[1];par[1]=off;par[2]=UDset;if(isRULEflag(par)){ 
      par[0]=a[0];setRULEflag(par);}
   off++;goto nxt;}
}
static int DUrule(int *a){/* >base */
  int par[3];int cnt;
  par[0]=Utrue;if(B(par) || (par[0]=Usink,B(par))){nxt:
    par[0]=Uuse;if(Bdata(par)){cnt=par[1];par[0]=a[0];par[1]=cnt;
       par[2]=UDuse;setRULEflag(par);goto nxt;}
    par[0]=Uset;if(Bdata(par)){par[0]=a[0];par[2]=UDset;
       setRULEflag(par);goto nxt;}
    par[0]=Uspare;if(B(par)){goto nxt;}
    par[0]=Umark;if(B(par)){goto nxt;}
    par[0]=Ufalse;if(B(par)){goto nxt;}
    par[0]=Unode;if(B(par)){;}
    return 1;}
  return 0;
}
static void DUregion(int *a);
static int DUmember(int *a){ /* >base */
  int par[3];int ptr;
  par[0]=Ujump;if(B(par)){return 1;}
  par[0]=Uplus;if(B(par)){return 1;}
  par[0]=Uminus;if(B(par)){return 1;}
  par[0]=a[0];if(DUrule(par)){return 1;}
  par[0]=Uclose;if(Bdata(par)){ptr=par[1];
     par[0]=ptr;DUregion(par);par[0]=a[0];par[1]=ptr;mergeDUflags(par);
     return 1;}
  return 0;
}
static void DUalternative(int *a){/* >base */
  int par[3];again:
  par[0]=Uhead;if(B(par)){par[0]=a[0];DUmember(par);}
  par[0]=a[0];if(DUmember(par)){goto again;}
}
static void DUregion(int *a){/* >base */
  int par[3];nxt:
  DUalternative(a);par[0]=Usemicolon;if(B(par)){goto nxt;}
  par[0]=Ubox;if(B(par)){DUrule(a);}
  nxt2:par[0]=Uopen;if(B(par)){;}else{Uptr-=RULE_CALIBRE;goto nxt2;}
}
static void computeDUflags(void){
  int par[2];int ptr;
  Uptr=RULE->aupb;par[0]=Uclose;Bdata(par);ptr=par[1];
  par[0]=ptr;DUregion(par);
}
/* ================================================================= */
static void diagnoseLocal(int *a){/* >base + >off+ >loc */
   int par[3];
   if(addRULEflag!=1){ return;}
   if(LLOC->offset[a[2]-LLOC_type]!=Ilocal){return;}
   par[0]=a[0];par[1]=a[1];par[2]=UDuse;if(isRULEflag(par)){return;}
   par[2]=UDset;if(isRULEflag(par)){
     par[0]=local_affix_set_only;par[1]=ruleCompiled;
     par[2]=LLOC->offset[a[2]-LLOC_tag];Warning(4,3,par);}
}
static void printRULEstack(int *a);

static void diagnoseOutAffix(int *a){/* >utype+>loc */
  int par[3];
  if(addRULEflag!=1){ return;}
  if(Uspare!=RULE->offset[RULEtop-RULE_flag]){return;}
//printf("RULEtop=%d, flag=%x\n",RULEtop,RULE->offset[RULEtop-RULE_flag]);printRULEstack(NULL);RULE->offset[0]=1;
  par[0]=out_affix_not_used;par[1]=ruleCalled;
  par[2]=LLOC->offset[a[1]-LLOC_tag];
  Warning(a[0]==Uinout?1:4,3,par);
}
static void diagnoseFormals(void){
  int par[3];int loc,base,off;int t;
  loc=LLOC->alwb;base=RULE->alwb;off=1;nxt:
  if(loc>LLOC->aupb){;}
  else{t=LLOC->offset[loc-LLOC_type];
    if(t==IformalIn){par[0]=base;par[1]=off;par[2]=Ufinal;
      if(isRULEflag(par)){;}
      else if((par[2]=UDset,isRULEflag(par))){
           par[0]=original_value_not_used;par[1]=ruleCompiled;
           par[2]=LLOC->offset[loc-LLOC_tag];Warning(4,3,par);};off++;}
    else if(t==IformalInout){par[0]=base;par[1]=off;par[2]=Ufinal;
      if(isRULEflag(par)){;}
      else if((par[2]=UDset,isRULEflag(par))){
         par[0]=original_value_not_used;par[1]=ruleCompiled;
            par[2]=LLOC->offset[loc-LLOC_tag];Warning(4,3,par);}
      else{par[0]=formal_can_be_in;par[1]=ruleCompiled;par[2]=
           LLOC->offset[loc-LLOC_tag];Warning(4,3,par);};off++;}
    else if(t==IformalOut){off++;}
    par[0]=STACKpar(LLOC);par[1]=loc;next(par);loc=par[1];
    goto nxt;}
}
/* ---------------------------------------------------- */
static void diagnoseRule(int *a){/* + >tag */
  int par[3];int dpos,dnum,rptr;
  ruleCompiled=a[0];saveDiscPosition(par);dpos=par[0];dnum=par[1];
  expandFlag=0;addRULEflag=3;par[0]=STACKpar(RULE);scratch(par);
  par[0]=STACKpar(BUFFER);scratch(par);
  RULEtop=rptr=RULE->aupb;par[0]=a[0];setupFormalStack(par);
  gruleBody();par[0]=Dpoint;mustQ(par);
  par[0]=a[0];traverseRULE(par);
  computeDUflags();
//printf("*** diagnose *** ");printRULEstack(a);
  par[0]=dpos;par[1]=dnum;restoreDiscPosition(par);
  addRULEflag=1;RULEtop=rptr;par[0]=a[0];setupFormalStack(par);
  diagnoseFormals();gruleBody();par[0]=Dpoint;mustQ(par);
  par[0]=dpos;par[1]=dnum;restoreDiscPosition(par);
}
/* ============================================================ */
/* code generation */
static int nodeCount,C1,C2,C3;
inline static void resetRuleCount(void){C1=C2=C3=0;}
inline static void countRuleAffix(int ftype,int repeat){
  if(repeat!=0){C3++;}
  else{C1++;if(ftype==IformalOut||ftype==IformalInout){C2++;}}
}
inline static void countStarAffix(int rep){
  if(rep==0){C1+=C3;C2+=C3;C3=0;}
  else if(C3>0){C3--;}
}
inline static void assignNodes(void){
   int node,ptr;
   node=NODE->vlwb;nodeCount=0;ptr=RULE->alwb;nxt:
   if(ptr>RULE->aupb){;}
   else{if(RULE->offset[ptr-RULE_flag]==Unode && RULE->offset[ptr-RULE_data]==0){
     RULE->offset[ptr-RULE_data]=node;nodeCount++;node+=NODE_CALIBRE;}
     ptr+=RULE_CALIBRE;goto nxt;}
}
/* ----------------------------------------------------- */
static void wsimpleAffix(int *a),wcopyAffixFromBUFFER(int *a);
/* - - - - - - - - - - - - */
static void wlabel(int *a){/* >ptr */
  int par[3];int label,j;
  par[0]=Dout;W(par);if(a[0]==0){par[0]=0;Wcons(par);}
  else{label=RULE->offset[a[0]-RULE_data];j=RULE->offset[a[0]-RULE_flag];
    if(j!=Utrue && j!=Ufalse &&j!=Usink){printf("wlabel: wrong flag %x, ptr=%d\n",j,a[0]);exit(31);}
    if(j==Usink){par[0]=0;Wcons(par);}
    else if(label==-1){par[0]=-1;Wcons(par);}
    else if(label==-2){par[0]=-2;Wcons(par);}
    else{par[0]=RULE->offset[label-RULE_data];W(par);}}
}
static void wtransportList(int *a){/* cnt> */
  int par[3];a[0]=0;nxt:
  par[0]=Uin;wsimpleAffix(par);nxt2:par[0]=Dto;if(Q(par)){
     par[0]=Dto;extendBUFFER(par);a[0]++;if(Qcons(par)){par[1]=par[0];}
     else{mustQtag(par);getRepr(par);}
     par[0]=Dconst;pushBUFFER(2,par);goto nxt2;}
  par[0]=Dextension;if(Q(par)){;}else if((par[0]=Dend,Q(par))){;}
  else{goto nxt;}
}
static void wextension(void){
  int par[3];int tag,optr;
  mustQtag(par);tag=par[0];pushRULE(Unode,0);
  par[0]=Dextension;W(par);par[0]=RULE->offset[RULEtop-RULE_data];W(par);
  par[0]=tag;Wtag(par);optr=BUFFER->aupb;wtransportList(par);Wcons(par);
  par[0]=0;par[1]=optr+1;wcopyAffixFromBUFFER(par);par[0]=STACKpar(BUFFER);
  par[1]=optr;unstackto(par);pushRULE(Utrue,0);
  par[0]=RULEtop;wlabel(par);
}
static int wlimit(int *a){/* x> */
  int par[1];
  par[0]=Dupb;if(Q(par)){a[0]=Dupb; return 1;}
  par[0]=Dlwb;if(Q(par)){a[0]=Dlwb;return 1;}
  par[0]=Dvupb;if(Q(par)){a[0]=Dvupb;return 1 ;}
  par[0]=Dvlwb;if(Q(par)){a[0]=Dvlwb;return 1;}
  return 0;
}
static void finalSsel(int *a){/* >tag+>loc+x> */
  int par[2];
  if(a[1]){a[2]=LLOC->offset[a[1]-LLOC_ssel];}
  else if(LLOC->alwb<=a[0] && a[0]<=LLOC->aupb){a[2]=LLOC->offset[a[0]-LLOC_ssel];}
  else{par[0]=a[0];getSsel(par);a[2]=par[1];}
}
static void whandleAffix(int *a){/* >utype */
  int par[2];
  par[0]=a[0];if(inUtype(par)){pushRULE(Uuse,0);}
  par[0]=a[0];if(outUtype(par)){par[0]=Dminus;pushBUFFER(1,par);}
}
static void wbeforeVarargBlock(int *a){/* >ptr + >formal */
  int par[3];int ftype;
  nxt:par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];
  par[0]=a[1];getType(par);ftype=par[1];getAdm(par);a[1]=par[1];
  if(ftype==IformalIn||ftype==IformalInout){pushRULE(Uuse,0);}
  if(a[1]==0){;}else{goto nxt;}
}
static void wbeforeShiftRule(int *a){/* >ptr */
  int par[3];int t;nxt:
  par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];
  t=LLOC->offset[a[0]-LLOC_type];if(t==Ilabel){;}
  else if(t==IformalIn||t==IformalInout){pushRULE(Uuse,0);goto nxt;}
  else{goto nxt;}
}
static void wafterVarargBlock(int *a){/* >ptr+>formal */
  int par[3];int ftype; nxt:
  par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];
  par[0]=a[1];getType(par);ftype=par[1];getAdm(par);a[1]=par[1];
  if(ftype==IformalOut||ftype==IformalInout){pushRULE(Uset,0);}
  if(a[1]==0){;}else{goto nxt;}
}
static void wafterShiftRule(int *a){/*>ptr */
  int par[3];int t;nxt:
  par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];
  t=LLOC->offset[a[0]-LLOC_type];if(t==Ilabel){;}
  else if(t==IformalOut||t==IformalInout){pushRULE(Uset,0);goto nxt;}
  else{goto nxt;}
}

static void wsimpleAffix(int *a){/* >utype+ repeat> */
  int par[7];int tag,type,local,x;
  a[1]=0;if(Qcons(par)){par[1]=par[0];par[0]=Dconst,pushBUFFER(2,par);return;}
  par[0]=Dcalibre;if(Q(par)){mustQtag(par);tag=par[0];
    if(hasFormalType(par)){par[0]=Dcalibre;par[1]=tag;pushBUFFER(2,par);}
    else{par[0]=tag;getCalibre(par);par[0]=Dconst;pushBUFFER(2,par);}
    return;}
  if(wlimit(par)){x=par[0];mustQtag(par);par[1]=par[0];par[0]=x;
    pushBUFFER(2,par);return;}
  par[0]=Dnoarg;if(Q(par)){pushBUFFER(1,par);return;}
  par[0]=Dsub;if(Q(par)){pushBUFFER(1,par);par[0]=a[0];utypeToSlice(par);
    type=par[1];par[0]=type;wsimpleAffix(par);par[0]=Dbus;mustQ(par);
    mustQtag(par);tag=par[0];if(Qcons(par)){x=par[0];}
    else{mustQtag(par);getRepr(par);x=par[1];}
    par[0]=Dbus;par[1]=tag;par[2]=Dconst;par[3]=x;pushBUFFER(4,par);
    return;}
  mustQlist(par);tag=par[0];local=par[1];getType(par);type=par[1];
    if(type==IformalRepeat){par[0]=Dstar;pushBUFFER(1,par);a[1]=tag;}
    else if(type==Istack||type==IstaticStack||type==IformalStack
      ||type==IformalTable){par[0]=tag;par[1]=local;finalSsel(par);x=par[2];
        par[0]=Dsub;par[1]=Dupb;par[2]=tag;par[3]=Dbus;par[4]=tag;
        par[5]=Dconst;par[6]=x;pushBUFFER(7,par);}
    else if(type==IformalIn||type==IformalOut||type==IformalInout||type==Ilocal){
      par[0]=a[0];whandleAffix(par);par[0]=tag;pushBUFFER(1,par);}
    else{par[0]=tag;pushBUFFER(1,par);}
}
static void wmatchFormalActual(int *a){/* >ftype+repeat> */
  int par[3];int tag,type;
  if(a[0]==IformalFile||a[0]==IformalTable||a[0]==IformalStack){
    mustQtag(par);tag=par[0];getType(par);type=par[1];
    if(type==IformalRepeat){par[0]=Dstar;extendBUFFER(par);a[1]=tag;}
    else{par[0]=tag;extendBUFFER(par);a[1]=0;}}
  else if(a[0]==IformalShift){mustQtag(par);a[1]=par[0];extendBUFFER(par);}
  else if(a[0]==IformalIn){par[0]=Uin;wsimpleAffix(par);a[1]=par[1];}
  else if(a[0]==IformalOut){par[0]=Uout;wsimpleAffix(par);a[1]=par[1];}
  else if(a[0]==IformalInout){par[0]=Uinout;wsimpleAffix(par);a[1]=par[1];}
  else{printf("wmatchFormalActual: wrong ftype=%d\n",a[0]);exit(24);}
}
static void wskipAffixInBUFFER(int *a){/* >pr + >b> */
  int t;
//printf("wskip from=%d\n",a[1]);
  nxt:
  if(a[1]>BUFFER->aupb){return;}
  t=BUFFER->offset[a[1]];
  if(t==Dplus){return;}
  else if(t==Dminus){a[1]++;if(a[0]==0){;}else{pushRULE(Uuse,0);} goto nxt;}
  else if(t==Dconst){a[1]++;a[1]++;goto nxt;}
  else{a[1]++;goto nxt;}
}
static void wcopyAffixFromBUFFER(int *a){/* >pr + >b> */
  int par[2];int t;
//printf("bc(%d):",a[1]);
  nxt:
  if(a[1]>BUFFER->aupb){
//printf("\n");
    return;}
  t=BUFFER->offset[a[1]];
//printf(" "),par[0]=t;printPointer(par);
  if(t==Dplus){return;}
  if(t==Dminus){a[1]++;if(a[0]==0){;}else{pushRULE(Uuse,0);}goto nxt;}
  if(t==Dconst){a[1]++;par[0]=BUFFER->offset[a[1]];Wcons(par);a[1]++;goto nxt;}
  else if(LLOC->alwb<=t && t<=LLOC->aupb){par[0]=t;Wtag(par);a[1]++;goto nxt;}
  else if(LADM->alwb<=t && t<=LADM->aupb){par[0]=t;Wtag(par);a[1]++;goto nxt;}
  else{par[0]=t;W(par);a[1]++;goto nxt;}
}
static void wbeforeAffixes(int *a){/*>tag + >b + >cnt + >rep */
  int par[3];int formal,ftype,repeat;/* 0     1     2      3  */
  a[1]++;par[0]=a[0];getAdm(par);formal=par[1];repeat=0;nxt:
  if(a[1]>BUFFER->aupb){return;}
  par[0]=formal;getType(par);ftype=par[1];
  if(ftype==IformalRepeat){par[0]=Dstar;W(par);par[0]=a[2];Wcons(par);
    if(a[3]){par[0]=1;Wcons(par);}else{par[0]=0;Wcons(par);}
    par[0]=formal;getAdm(par);formal=par[1];repeat=formal;goto nxt;}
  else{a[1]++;
    par[0]=formal;getAdm(par);formal=par[1];if(formal==0){formal=repeat;}}
    if(BUFFER->offset[a[1]]==Dstar){par[0]=Dstar;W(par);}
    else if(ftype==IformalOut){/* par[0]=Dnoarg;W(par);*/ par[0]=0;
      par[1]=a[1];wskipAffixInBUFFER(par);a[1]=par[1];goto nxt;}
    else{par[0]=0;par[1]=a[1];wcopyAffixFromBUFFER(par);a[1]=par[1];goto nxt;}
}
static void wafterAffixes(int *a){/* >tag + >b */
  int par[3];int formal,ftype,repeat;
  a[1]++;par[0]=a[0];getAdm(par);formal=par[1];repeat=0;nxt:
//printf("next after affix, ptr=%d\n",a[1]);
  if(a[1]>BUFFER->aupb){return;}
  par[0]=formal;getType(par);ftype=par[1];
  if(ftype==IformalRepeat){par[0]=formal;getAdm(par);formal=par[1];repeat=formal;
    goto nxt;}
//if(BUFFER->offset[a[1]]!=Dplus){printf("off=%d,v=%d, expected %d\n",a[1],BUFFER->offset[a[1]],Dplus);exit(88);}
  a[1]++;if(BUFFER->offset[a[1]]==Dstar){a[1]++;}
  else if(ftype==IformalOut||ftype==IformalInout){
    if(BUFFER->offset[a[1]]==Dminus){a[1]++;pushRULE(Uuse,0);
      if(RULE->offset[RULEtop-RULE_flag]==Uspare){par[0]=Dnoarg;W(par);
        par[0]=1;par[1]=a[1];wskipAffixInBUFFER(par);a[1]=par[1];}
      else if(RULE->offset[RULEtop-RULE_flag]!=Uset){
          printf("wafterAffixes: RULEtop=%d, should be Uset (%x)\n",RULEtop,RULE->offset[RULEtop-RULE_flag]);exit(35);}
      else{par[0]=1;par[1]=a[1];wcopyAffixFromBUFFER(par);a[1]=par[1];}}
    else{par[0]=1;par[1]=a[1];wcopyAffixFromBUFFER(par);a[1]=par[1];}}
  else{/*par[0]=Dnoarg;W(par);*/par[0]=1;par[1]=a[1];wskipAffixInBUFFER(par);a[1]=par[1];}
  par[0]=formal;getAdm(par);formal=par[1];if(formal==0){formal=repeat;}
  goto nxt;
}
static void wactualRule(int *a){/* >tag */
  int par[4];int oldBUFF,formal,ftype,repeat,count,frep;
  pushRULE(Unode,0);par[0]=Dnode;W(par);
//printf("rule RULE=%d (%x,%d) ",RULEtop,RULE->offset[RULEtop-RULE_flag],RULE->offset[RULEtop-RULE_data]);printPointer(a);printf("\n");
  par[0]=RULE->offset[RULEtop-RULE_data];W(par);par[0]=a[0];Wtag(par);
  oldBUFF=BUFFER->aupb;resetRuleCount();repeat=frep=count=0; 
  par[0]=a[0];getAdm(par);formal=par[1];nxt:
  par[0]=Dplus;if(Q(par)){extendBUFFER(par);par[0]=formal;getType(par);
    ftype=par[1];if(ftype==IformalRepeat){par[0]=formal;
      getAdm(par);formal=par[1];repeat=formal;par[0]=formal;getType(par);
      ftype=par[1];}
    countRuleAffix(ftype,repeat);par[0]=ftype;
    wmatchFormalActual(par);frep=par[1];par[0]=formal;getAdm(par);
    formal=par[1];if(formal==0){count++;formal=repeat;}goto nxt;}
  countStarAffix(frep);par[0]=C1;Wcons(par);par[0]=C2;
  Wcons(par);par[0]=C3;Wcons(par);
//printf("BUFFER (%d--%d): ",oldBUFF+1,BUFFER->aupb);{int i=oldBUFF+1;while(i<=BUFFER->aupb){par[0]=BUFFER->offset[i];if(par[0]==Dconst){printf("%d ",BUFFER->offset[i+1]);i+=2;}else{printPointer(par);printf(" ");i++;}}}printf("***\n");
  par[0]=a[0];par[1]=oldBUFF;par[2]=count;par[3]=frep;wbeforeAffixes(par);
  if(frep==0){;}
  else if(a[0]==Xshiftaffix){par[0]=frep;wbeforeShiftRule(par);}
  else if((par[0]=a[0],par[1]=rshiftrule,isTagFlag(par))){;}
  else{par[0]=frep;par[1]=repeat;wbeforeVarargBlock(par);}
  par[0]=a[0];par[1]=rcanFail;
  if(isTagFlag(par)){pushRULE(Ufalse,0);par[0]=RULEtop;wlabel(par);}
  else{par[0]=0;wlabel(par);}
//printf("BUFFER2 %d--%d\n",oldBUFF+1,BUFFER->aupb);
  par[0]=a[0];par[1]=oldBUFF;wafterAffixes(par);
  if(frep==0){;}
  else if(a[0]==Xshiftaffix){par[0]=frep;wafterShiftRule(par);}
  else if((par[0]=a[0],par[1]=rshiftrule,isTagFlag(par))){;}
  else{par[0]=frep;par[1]=repeat;wafterVarargBlock(par);}
  pushRULE(Utrue,0);par[0]=RULEtop;wlabel(par);
  par[0]=STACKpar(BUFFER);par[1]=oldBUFF;unstackto(par);
}
/* - - - - - - - - - - - - - - - - - - */
static void waltTail(void),wruleBody(void),wmember(void);
/* - - - - - - - - - - - - - - - - - - */
static void warea(int *a){/* >buff */
  int par[3];
  par[0]=Darea;W(par);par[0]=0;par[1]=a[0]+1;wcopyAffixFromBUFFER(par);
}
static void wreadBox(void){
  int par[3];int ptr,buff,fptr;
  pushRULE(Unode,0);par[0]=Dbox;W(par);par[0]=RULE->offset[RULEtop-RULE_data];
  W(par);buff=BUFFER->aupb;par[0]=Uin;wsimpleAffix(par);
  par[0]=0;par[1]=buff+1;wcopyAffixFromBUFFER(par);par[0]=STACKpar(BUFFER);
  par[1]=buff;unstackto(par);
  pushRULE(Utrue,0);
  ptr=RULE->offset[RULEtop-RULE_data];pushRULE(Ubox,0);par[0]=Dbox;mustQ(par);
  nxt:if(ptr==0){;}
  else{buff=RULE->offset[ptr-RULE_data];ptr+=RULE_CALIBRE;
    fptr=RULE->offset[ptr-RULE_data];ptr+=RULE_CALIBRE;
    par[0]=buff;warea(par);par[0]=ptr;wlabel(par);ptr=fptr;goto nxt;}
}
static void wclassification(void){
  int par[2]; nxt:
  par[0]=Darea;mustQ(par);par[0]=Darea;Qskip(par);pushRULE(Unode,0);
  pushRULE(Ufalse,0);pushRULE(Utrue,0);pushRULE(Uhead,0);
  waltTail();par[0]=Dsemicolon;if(Q(par)){
   pushRULE(Usemicolon,0);goto nxt;}
}
/* ----------------------------------------- */
static void wcompound(void){
  int par[2];int loc;
  loc=LLOC->aupb;wruleBody();par[0]=STACKpar(LLOC);par[1]=loc;
  unstackto(par);
}
static void waltSequence(void){
  int par[1];
  nxt: wmember();pushRULE(Uhead,0),waltTail();
  par[0]=Dsemicolon;if(Q(par)){pushRULE(Usemicolon,0);goto nxt;}
}
static void waltTail(void){
  int par[1];
  nxt:par[0]=Dcomma;if(Q(par)){wmember();goto nxt;}
}
static void wmember(void){
  int par[3];int tag;
  par[0]=Dopen;if(Q(par)){wcompound();par[0]=Dclose;mustQ(par);return;}
  par[0]=Dextension;if(Q(par)){wextension();return;}
  par[0]=Djump;if(Q(par)){mustQtag(par);pushRULE(Ujump,0);return;}
  par[0]=Dplus;if(Q(par)){pushRULE(Uplus,0); return;}
  par[0]=Dminus;if(Q(par)){pushRULE(Uminus,0);return;}
  mustQtag(par);tag=par[0];par[1]=rmacro;
  if(isTagFlag(par)){par[0]=tag;expandMacro(par);}
  else{par[0]=tag;wactualRule(par);}
}
static void wruleBody(void){
  int par[3];int label,rloc;
  setupLabel(par);label=par[0];
  setupLocals();
  par[0]=label;startRange(par);rloc=par[1];
  par[0]=Dbox;if(Q(par)){wreadBox();wclassification();}
  else{waltSequence();}
  par[0]=rloc;closeRange(par);
}
/* ================================ */

/* -------------------------------- */
//DEBUG !!
static void printRULEstack(int *a){
  static char*C[]={"mark ","open ","close","head ","node ","true ","false","sink ",
              "plus ","minus","jump ","box  ","","","",               "scol ",
                   "","--use","--set","--spr"};
  int i,cnt;int f,d;
  return;
  printf("RULE stack (");if(a){printPointer(a);}printf("), nodes=%d\n",nodeCount);
  i=RULE->alwb;cnt=-1;while(i<=RULE->aupb){
    cnt++; if(cnt==5){cnt=0;printf("\n");}
    d=RULE->offset[i];f=RULE->offset[i-1];i+=2;
    if(0x1000<=f&&f<=0x1013){printf("(%s",C[f-Umark]);}
    else {printf("(%-5x",f);}
    if(RULE->alwb<=d && d<=RULE->aupb){printf(",R+%-3d) ",(d-RULE->alwb)/RULE_CALIBRE);}
    else if(LLOC->alwb<=d && d<=LLOC->aupb){printf(",L+%-3d) ",(d-LLOC->alwb)/LLOC_CALIBRE);}
    else if(NODE->vlwb<=d && d<=NODE->vupb){printf(",N+%-3d) ",(d-NODE->alwb)/NODE_CALIBRE);}
    else if(BUFFER->alwb<=d+1 && d+1<=BUFFER->aupb){printf(",B+%-3d) ",d+1-BUFFER->alwb);}
    else if(f==0){printf(",x%-4x) ",d);}else{ printf(",%-5d) ",d);}
  }
  printf("\n");
//  printf("BUFFER: ");i=BUFFER->alwb;cnt=-1;while(i<=BUFFER->aupb){int par[1];
//    cnt++;if(cnt==10){cnt=0;printf("\n");}
//    d=BUFFER->offset[i];i++;par[0]=d;printPointer(par);printf(", ");
//  }
//  printf("\n");
}
//DEBUG

void generateRule(int *a){/* >tag */
  int par[3]; int rptr,dpos,dnum;
  par[0]=a[0];diagnoseRule(par);
  par[0]=a[0];getRepr(par);if(par[1]==0){par[0]=Dpoint;Qskip(par);return;}
  ruleCompiled=a[0];saveDiscPosition(par);dpos=par[0];dnum=par[1];
      expandFlag=1;addRULEflag=3;par[0]=STACKpar(RULE);scratch(par);
      par[0]=STACKpar(BUFFER);scratch(par);
      minLocal=maxLocal=0;
      rptr=RULEtop=RULE->aupb;par[0]=a[0];setupFormalStack(par);
      gruleBody();par[0]=Dpoint;mustQ(par);
      par[0]=a[0];traverseRULE(par);LfindLabels();assignNodes();
      par[0]=dpos;par[1]=dnum;restoreDiscPosition(par);
printRULEstack(a);
      par[0]=Drule;W(par);par[0]=a[0];Wtag(par);
      par[0]=minLocal;Wcons(par);par[0]=maxLocal;Wcons(par);
      par[0]=nodeCount;Wcons(par);
      addRULEflag=2;expandFlag=1;RULEtop=rptr;
      par[0]=a[0];setupFormalStack(par);wruleBody();
      par[0]=Dpoint;mustQ(par);W(par);
}

void initialize_node(void){
  init_msg();
}



/* EOF */
