/* node.ale */
#include "stddata.h"
#include "node.h"
#include "disc.h"
#include "tags.h"
#include "types.h"
#include "display.h"
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
static void pushRULE(int flag,int data){
  int par[4];
  par[0]=STACKpar(RULE);par[1]=2,par[3-RULE_flag]=flag;par[3-RULE_data]=data;
  expandstack(par);
}
static void extendBUFFER(int *a){int par[2];par[0]=STACKpar(BUFFER);par[1]=a[0];extend(par);}
/* ------------------------------------ */
static void setupFormalStack(int *a){/* >rtag */
  int par[8];int formal,type;
  par[0]=STACKpar(LLOC);scratch(par);par[0]=a[0];getAdm(par);formal=par[1];
  nxt:if(formal==0){;}
  else{par[0]=formal;getType(par);type=par[1];par[0]=STACKpar(LLOC);
  par[1]=6;par[7-LLOC_repr]=-1;par[7-LLOC_type]=type;par[7-LLOC_tag]=formal;
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
static void startRange(int *a){/* >label + rloc> */
  int par[4];int loc,cnt;
  pushRULE(Uopen,0);a[1]=RULE->aupb;
  if(a[0]){LLOC->offset[a[0]-LLOC_repr]=a[1];}
  loc=LLOC->alwb;cnt=0;nxt:if(loc>LLOC->aupb){;}
  else{int t=LLOC->offset[loc-LLOC_type];if(t==IformalIn||t==IformalOut||
    t==IformalInout||t==Ilocal){cnt++;pushRULE(0,loc);t=LLOC->offset[loc-LLOC_repr];
    if(t<0){LLOC->offset[loc-LLOC_repr]=cnt;}
    else if(t==cnt){;}else{printf("startRange: cnt=%d, repr=%d, loc=%d\n",cnt,t,loc);exit(23);}}
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
  gruleBody(void);

static void gexpandMacro(int *a){/* >tag */
  int par[4];int loc,Qa,Qb,dpos,dnum;
// printf("start expanding ");printPointer(a);printf("\n");
  loc=LLOC->aupb;par[0]=a[0];macroCallHead(par);Qa=par[1];Qb=par[2];
  saveDiscPosition(par);dpos=par[0];dnum=par[1];
  par[0]=a[0];searchMacroRule(par);par[0]=par[1];par[1]=par[2];
  restoreDiscPosition(par);
  gruleBody();par[0]=Dpoint;mustQ(par);
  par[0]=dpos;par[1]=dnum;restoreDiscPosition(par);par[0]=Qa;par[1]=Qb;
  macroCallTail(par);
  par[0]=STACKpar(LLOC);par[1]=loc;unstackto(par);
}
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
static void gclassification(void){
  int par[2];int last;again:
  par[0]=Darea;mustQ(par);par[0]=Darea;Qskip(par);
  pushRULE(Unode,0);pushRULE(Ufalse,0);last=RULE->aupb;
  pushRULE(Utrue,0);pushRULE(Uhead,0);galtTail();par[0]=Dsemicolon;
  if(Q(par)){pushRULE(Usemicolon,0);goto again;}
  else{RULE->offset[last-RULE_flag]=Umark;}
}
/* actual rule */
static void ghandleAffix(int *a){ /* >tag + >utype */
  int par[3];
  par[0]=a[1];if(inUtype(par)){pushRULE(Uuse,LLOC->offset[a[0]-LLOC_repr]);}
  par[0]=a[1];if(outUtype(par)){if(a[1]>=Uslicein){par[0]=Uuse;
    extendBUFFER(par);}else{par[0]=Uset;extendBUFFER(par);}
    par[0]=LLOC->offset[a[0]-LLOC_repr];extendBUFFER(par);}
}
static void ghandleVarargBlock(int *a){ /*> ptr */
  int par[3];int t;nxt:t=LLOC->offset[a[0]-LLOC_type];
  if(t==Ilabel){;}
//  else if(t==IformalIn){par[0]=a[0];par[1]=Uin;ghandleAffix(par);
//    par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];goto nxt;}
  else if(t==IformalOut||t==IformalInout){par[0]=a[0];par[1]=Uout;ghandleAffix(par);
    par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];goto nxt;}
//  else if(t==IformalInout){par[0]=a[0];par[1]=Uinout;ghandleAffix(par);
//    par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];goto nxt;}
  else{par[0]=STACKpar(LLOC);par[1]=a[0];next(par);a[0]=par[1];goto nxt;}
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
  if(Qcons(par)){a[1]=0;}
  else if(glimit()){mustQtag(par);a[1]=0;}
  else if((par[0]=Dsub,Q(par))){par[0]=a[0];utypeToSlice(par);type=par[1];
    par[0]=type;gsimpleAffix(par);a[1]=par[1];par[0]=Dbus;mustQ(par);
    mustQtag(par);if(Qcons(par)){;}else{mustQtag(par);}}
  else if((par[0]=Dnoarg,Q(par))){a[1]=0;}
  else{mustQtag(par);tag=par[0];getType(par);type=par[1];
    if(type==IformalRepeat){a[1]=tag;}
    else if(type==IformalIn||type==IformalOut||type==IformalInout||
      type==Ilocal){par[0]=tag;par[1]=a[0];ghandleAffix(par);a[1]=0;}
    else{a[1]=0;}}
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
   int par[3];int formal,ftype,repeat,frep;
   pushRULE(Unode,0);par[0]=STACKpar(BUFFER);scratch(par);repeat=frep=0;
   par[0]=a[0];getAdm(par);formal=par[1];nxt:
   par[0]=Dplus;if(Q(par)){par[0]=formal;getType(par);ftype=par[1];
     if(ftype==IformalRepeat){par[0]=formal;getAdm(par);formal=par[1];
       repeat=formal;par[0]=formal;getType(par);ftype=par[1];}
     par[0]=ftype;gmatchFormalActual(par);frep=par[1];
     par[0]=formal;getAdm(par);formal=par[1];if(formal==0){formal=repeat;}
     goto nxt;}
   if(frep==0){;}
   else if((par[0]=a[0],par[1]=rshiftrule,isTagFlag(par))&&(a[0]!=Xshiftaffix)){;}
   else{par[0]=frep;ghandleVarargBlock(par);}
   par[0]=a[0];par[1]=rcanFail;if(isTagFlag(par)){pushRULE(Ufalse,0);}
   frep=BUFFER->alwb;nxt2:if(frep>=BUFFER->aupb){;}
   else{int flag=BUFFER->offset[frep];frep++;pushRULE(flag,BUFFER->offset[frep]);
     frep++;goto nxt2;}
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
  mustQtag(par);tag=par[0];par[1]=rmacro;if(isTagFlag(par)){
    par[0]=tag;gexpandMacro(par);}
    else{par[0]=tag;gactualRule(par);}
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
static void Breplace(int *a){/* >new */
  RULE->offset[Uptr+RULE_CALIBRE-RULE_flag]=a[0];
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
     if(isRULEflag(par)){;}else{par[0]=Uspare;Breplace(par);}
     par[0]=a[0];par[1]=cnt;par[2]=Uflag;clearRULEflag(par);goto nxt;}
  par[0]=Uspare;if(Bdata(par)){cnt=par[1];par[0]=a[0];par[1]=cnt;par[2]=Uflag;
     if(isRULEflag(par)){par[0]=Uset;Breplace(par);}
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
/* -------------------------------- */
static void traverseRULE(int *a){ /* >tag */
  int par[2];int ptr;
  setFlagsForRule(a);nxt:Uptr=RULE->aupb;par[0]=Uclose;
  if(Bdata(par)){ptr=par[1];}else{printf("not Uclose\n");exit(8);}
  UfinalChanged=0;par[0]=ptr;Uregion(par);if(UfinalChanged){goto nxt;}
}

static void goptimizeRule(int *a){/* >tag */
  int par[3];
  par[0]=STACKpar(RULE);scratch(par);par[0]=a[0];setupFormalStack(par);
  gruleBody();par[0]=Dpoint;mustQ(par);
}
//DEBUG !!
static void printRULEstack(int *a){
  static char*C[]={"mark ","open ","close","head ","node ","true ","false","sink ",
              "plus ","minus","jump ","box  ","","","",               "scol ",
                   "","--use","--set","--spr"};
  int i,cnt;int f,d;
  printf("RULE stack (");printPointer(a);printf(")\n");
  i=RULE->alwb;cnt=-1;while(i<=RULE->aupb){
    cnt++; if(cnt==5){cnt=0;printf("\n");}
    d=RULE->offset[i];f=RULE->offset[i-1];i+=2;
    if(0x1000<=f&&f<=0x1013){printf("(%s",C[f-Umark]);}
    else {printf("(%-5x",f);}
    if(RULE->alwb<=d && d<=RULE->aupb){printf(",R+%-3d) ",(d-RULE->alwb)/2);}
    else if(LLOC->alwb<=d && d<=RULE->aupb){printf(",L+%-3d) ",(d-LLOC->alwb)/6);}
    else if(f==0){printf(",x%-4x) ",d);}else{ printf(",%-5d) ",d);}
  }
  printf("\n");
}
//DEBUG

static int skipRuleGeneration(int *a){/* >tag */
  int par[2];
  par[0]=a[0];par[1]=tpublic;if(isTagFlag(par)){return 0;}
  par[1]=rmacro;if(isTagFlag(par)){return 1;}
  par[1]=tused;if(isTagFlag(par)){return 0;}
  return 1;
}

void generateRule(int *a){/* >tag */
  int par[3]; //int dpos,dnum;
//  saveDiscPosition(par);dpos=par[0];dnum=par[1];
  par[0]=a[0];if(skipRuleGeneration(par)){par[0]=Dpoint;Qskip(par);}
  else{goptimizeRule(a);
       traverseRULE(a);
       computeDUflags();
       
printRULEstack(a);printf("******************\n");
}}


/* EOF */
