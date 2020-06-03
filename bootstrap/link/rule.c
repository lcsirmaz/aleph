/* rule.ale */
#include "stddata.h"
#include "rule.h"
#include "error.h"
#include "item.h"
#include "lexical.h"
#include "target.h"

/* ------------------------------------------------ */
static void findIntervalPair(int set,int up){
  int ni;
  if(up<=ZONE->offset[set-ZONE_up]){return;}
  ni=ZONE->offset[set-ZONE_next];ZONE->offset[set-ZONE_up]=up;
  nxt:if(ni==0){ZONE->offset[set-ZONE_next]=0;}
  else if(up<ZONE->offset[ni-ZONE_lw]){ZONE->offset[set-ZONE_next]=ni;}
  else if(up<=ZONE->offset[ni-ZONE_up]){ZONE->offset[set-ZONE_up]=
     ZONE->offset[ni-ZONE_up];ZONE->offset[set-ZONE_next]=
     ZONE->offset[ni-ZONE_next];}
  else{ni=ZONE->offset[ni-ZONE_next];goto nxt;}
}
static void addInterval(int *a){/* >set + >lw + >up + >new> */
  int ni;int par[6];             /*   0      1    2      3   */
  again:ni=ZONE->offset[a[0]-ZONE_next];
  if(ni==0){a[3]=1;par[0]=STACKpar(ZONE);par[1]=3;par[4-ZONE_lw]=a[1];
    par[4-ZONE_up]=a[2];par[4-ZONE_next]=0;expandstack(par);
    ZONE->offset[a[0]-ZONE_next]=ZONE->aupb;}
  else if(a[1]<ZONE->offset[ni-ZONE_lw]){a[3]=1;
    if(a[2]<ZONE->offset[ni-ZONE_lw]){par[0]=STACKpar(ZONE);par[1]=3;
      par[4-ZONE_lw]=a[1];par[4-ZONE_up]=a[2];par[4-ZONE_next]=ni;
      expandstack(par);ZONE->offset[a[0]-ZONE_next]=ZONE->aupb;}
    else{ZONE->offset[ni-ZONE_lw]=a[1];findIntervalPair(ni,a[2]);}}
  else if(a[1]<=ZONE->offset[ni-ZONE_up]){
    if(a[2]<=ZONE->offset[ni-ZONE_up]){;}
    else{a[3]=1;findIntervalPair(ni,a[2]);}}
  else{a[0]=ni;goto again;}
}
static int diff1(int x,int y){if(y==x+1){return 1;}else{return 0;}}
static void mergeIntervals(int set){
  int ni;
  again:if(ZONE->offset[set-ZONE_next]==0){return;}
  set=ZONE->offset[set-ZONE_next];ni=ZONE->offset[set-ZONE_next];
  nxt:if(ni!=0 && diff1(ZONE->offset[set-ZONE_up],ZONE->offset[ni-ZONE_lw])){
    ZONE->offset[set-ZONE_up]=ZONE->offset[ni-ZONE_up];
    ZONE->offset[set-ZONE_next]=ZONE->offset[ni-ZONE_next];goto nxt;}
  else{goto again;}
}
#include <limits.h>
static int completeZone(int set){
  set=ZONE->offset[set-ZONE_next];if(set!=0
    &&ZONE->offset[set-ZONE_lw]==INT_MIN && ZONE->offset[set-ZONE_up]==INT_MAX){
      return 1;}else{return 0;}
}
static void readAreaInterval(int *a){/* lw> + up> */
  int par[3];int t,tag,count;
  par[0]=Tconst;if(RR(par)){a[0]=par[1];a[1]=a[0];count=1;}
  else if(par[0]=Titem,RR(par)){tag=par[1];par[0]=tag;
    if(getItemDef(par)){tag=par[1];}t=ITEM->offset[tag-ITEM_type];
    if(t==Iconstant||t==IpointerConstant){a[0]=ITEM->offset[tag-ITEM_repr];
      a[1]=a[0];count=1;}
    else if(t==Istack||t==Itable||t==IstaticStack){par[0]=tag;
      getVlwb(par);a[0]=par[1];getCalibre(par);a[1]=par[1];
      a[0]-=a[1];a[0]++;getVupb(par);a[1]=par[1];count=2;}
    else{corruptedIceFile(__FILE__,__LINE__);count=0;}}
  else{a[0]=a[1]=count=0;}
  par[0]=Dcolon;if(R(par)){
   if(count==0){a[0]=INT_MIN;}else if(count==1){;}
   else{corruptedIceFile(__FILE__,__LINE__);}
   par[0]=Tconst;if(RR(par)){a[1]=par[1];}
   else if(par[0]=Titem,RR(par)){tag=par[1];par[0]=tag;
     if(getItemDef(par)){tag=par[1];}t=ITEM->offset[tag-ITEM_type];
     if(t==Iconstant||t==IpointerConstant){a[1]=ITEM->offset[tag-ITEM_repr];}
     else{corruptedIceFile(__FILE__,__LINE__);}}
   else{a[1]=INT_MAX;}}
  else if(count==0){corruptedIceFile(__FILE__,__LINE__);}
}
/* ------------------------------------------------ */
static int larger_lower_bound,cannot_succeed,area_may_fail,
  classification_succeeds;

#define addMSG(x,y)	 add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_MSG(void){
 addMSG("area at %l: lower bound %d exceeds upper bound %d",larger_lower_bound);
 addMSG("area at %l: this alternative never succeeds",cannot_succeed);
 addMSG("last area at %l: not all cases are covered",area_may_fail);
 addMSG("classification at %l: always succeeds",classification_succeeds);
}
#undef addMSG
/* ------------------------------------------------ */
#define nrule		0x0001
#define nextension	0x0002
#define nbox		0x0004
#define npidgin		0x0008
#define nlabel		0x0010
#define nzone		0x0800
#define nstored		0x1000
#define nargsame	0x2000
#define nsame		0x4000

static int thisNode=0;

static int isNodeFlag(int flag){
  if((NODE->offset[thisNode-NODE_flag]&flag)!=0){return 1;}
  return 0;
}
static int hasNodeFlag(int node,int flag){
  if((NODE->offset[node-NODE_flag]&flag)!=0){return 1;}
  return 0;
}
static void setNodeFlag(int flag){
  NODE->offset[thisNode-NODE_flag]|=flag;
}
static void putNodeFlag(int node,int flag){
   NODE->offset[node-NODE_flag]|=flag;
}
/* ------------ */
static void checkArea(int *a){/* >set + dl> */
  int par[4];int nnew,lw,up;
  par[0]=Tconst;must(par);a[1]=par[1];nnew=0;nxt:
  readAreaInterval(par);lw=par[0];up=par[1];
  if(lw<=up){par[0]=a[0];par[1]=lw;par[2]=up;par[3]=nnew;
     addInterval(par);nnew=par[3];}
  else{par[0]=larger_lower_bound;par[1]=a[1];par[2]=lw;par[3]=up;
     error(4,par);}
  par[0]=Dsemicolon;if(R(par)){goto nxt;}
  mergeIntervals(a[0]);
  if(nnew){;}else{par[0]=cannot_succeed;par[1]=a[1];error(2,par);}
}
static void checkAreas(void){
  int par[5];int set,dl,cnt;
  par[0]=STACKpar(ZONE);scratch(par);par[0]=STACKpar(ZONE);par[1]=3;
  par[2]=par[3]=par[4]=0;expandstack(par);set=ZONE->aupb;dl=cnt=0;nxt:
  par[0]=Darea;if(R(par)){cnt++;par[0]=set;checkArea(par);dl=par[1];
  par[0]=Dout;must(par);goto nxt;}
  if(completeZone(set)){setNodeFlag(nzone);
    if(cnt>1){;}else{par[0]=classification_succeeds;par[1]=dl;error(2,par);}}
  else{par[0]=area_may_fail;par[1]=dl;warning(2,par);}
}
/* ------------------------------------------------ */
static void createNodes(void){
  int par[8];int n;
  par[0]=STACKpar(NODE);scratch(par);par[0]=Tconst;must(par);n=par[1];
  nxt:if(n==0){;}
  else{par[0]=STACKpar(NODE);par[1]=6;par[2]=par[3]=par[4]=par[5]=
    par[6]=par[7]=0;expandstack(par);n--;goto nxt;}
}
static void advanceNode(void){
  int par[3];
  par[0]=Tnode;must(par);
  if(thisNode==0){thisNode=NODE->alwb;}
  else{thisNode+=NODE_CALIBRE;}
  if(thisNode<=NODE->aupb){;}else{printf(" **** advanceNode failed!!!\n");exit(23);}
}
/* ================================ */
static int C1=0,C2=0,C3=0;
static int localAffixPtr=0,doLocalAffixcheck=0;

static void setRuleHead(void){
   int par[3];int tag,x1,x2,x3;
   par[0]=Titem;must(par);tag=par[1];
   par[0]=tag;if(getItemDef(par)){tag=par[1];}
   NODE->offset[thisNode-NODE_tag]=tag;par[0]=Tconst;must(par);
   x1=par[1];par[0]=Tconst;must(par);x2=par[1];must(par);x3=par[1];
   if(isPidginRule(tag)){setNodeFlag(npidgin);}
   else{if(C1<x1){C1=x1;}if(C2<x2){C2=x2;}if(C3<x3){C3=x3;}}
}
static void skipRuleHead(void){
  nextSymbol();nextSymbol();nextSymbol();nextSymbol();
}
static void clearStackSize(void){C1=C2=C3=0;}
static void markLocalAffix(int idx){
  if(doLocalAffixcheck==0){;}
  else{BUFFER->offset[localAffixPtr+idx]=1;}
}
static void pushBUFFER(int,int*);
static void startLocalAffixcheck(int minloc,int maxloc){
  int par[1];
  if(minloc==0){doLocalAffixcheck=0;}
  else{doLocalAffixcheck=1;localAffixPtr=BUFFER->aupb-minloc+1;
    nxt:if(minloc>maxloc){;}else{minloc++;par[0]=0;pushBUFFER(1,par);goto nxt;}}
}
/* ================================== */
/* skip */
static void skipToComma(void){
  int par[2];nxt:
  par[0]=Dcomma;
  if(R(par)){;}else{par[0]=Tlocal;
    if(RR(par)){markLocalAffix(par[1]);goto nxt;}
           else{nextSymbol();goto nxt;}}
}
static void skipToLabel(int *a){ /* label> */
  int par[2];nxt:
  par[0]=Dout;if(RR(par)){a[0]=par[1];}
  else{nextSymbol();goto nxt;}
}
static int isLimit(void){
  int par[1];
  par[0]=Dcalibre;if(R(par)){return 1;}
  par[0]=Dlwb;if(R(par)){return 1;}
  par[0]=Dupb;if(R(par)){return 1;}
  par[0]=Dvlwb;if(R(par)){return 1;}
  par[0]=Dvupb;if(R(par)){return 1;}
  return 0;
}
static void skipList(void){
  int par[3];
  par[0]=Tformal;if(R(par)){;}
  else{par[0]=Titem;must(par);}
}
static void skipAffix(void){
  int par[3];
  par[0]=Dcolon;if(R(par)){;}
  par[0]=Tformal;if(R(par)){return;}
  par[0]=Tlocal;if(RR(par)){markLocalAffix(par[1]);return;}
  par[0]=Titem;if(R(par)){return;}
  par[0]=Dnoarg;if(R(par)){return;}
  par[0]=Tconst;if(R(par)){return;}
  if(isLimit()){skipList();return;}
  par[0]=Dsub;if(R(par)){skipList();skipAffix();par[0]=Dbus;must(par);
     par[0]=Tconst;must(par);return;}
  corruptedIceFile(__FILE__,__LINE__);
}
/* ======================================================= */
static void pushBUFFER(int n,int *a){
  int par[3];
  par[0]=STACKpar(BUFFER);par[1]=1;nxt:if(n==0){;}
  else{par[2]=a[0];expandstack(par);n--;a++;goto nxt;}
}
static void storeList(int symb){
  int par[3];int x;
  par[0]=Tformal;if(RR(par)){x=par[1];
     par[0]=symb;par[1]=Tformal;par[2]=x;pushBUFFER(3,par);return;}
  par[0]=Titem;must(par);x=par[1];
     par[0]=symb;par[1]=Titem;par[2]=x;pushBUFFER(3,par);
}
static void storeLimit(void){
  int par[3];
  par[0]=Dlwb;if(R(par)){storeList(Dlwb);return;}
  par[0]=Dupb;if(R(par)){storeList(Dupb);return;}
  par[0]=Dvlwb;if(R(par)){storeList(Dvlwb);return;}
  par[0]=Dvupb;if(R(par)){storeList(Dvupb);return;}
  par[0]=Dcalibre;must(par);storeList(Dcalibre);
}
static void storeAffix(void){
  int par[3];
  par[0]=Tformal;if(RR(par)){pushBUFFER(2,par);return;}
  par[0]=Tlocal;if(RR(par)){pushBUFFER(2,par);return;}
  par[0]=Titem;if(RR(par)){pushBUFFER(2,par);return;}
  par[0]=Tconst;if(RR(par)){pushBUFFER(2,par);return;}
  par[0]=Dsub;if(R(par)){storeList(Dsub);storeAffix();par[0]=Dbus;must(par);
    par[0]=Tconst;must(par);par[0]=Dbus;pushBUFFER(2,par);return;}
  storeLimit();
}
static void storeRuleAffix(int *a){/* type> */
  int par[3];
  par[0]=Dcolon;if(R(par)){a[0]=Dcolon;pushBUFFER(1,par);storeAffix();return;}
  par[0]=Dnoarg;if(R(par)){a[0]=Dnoarg;pushBUFFER(1,par);return;}
  par[0]=Dstar;if(R(par)){a[0]=Dstar;par[0]=Tconst;if(RR(par)){;}else{par[1]=0;}
     par[0]=Dstar;pushBUFFER(2,par);return;}
  a[0]=0;storeAffix();
}
static void storeRuleAffixes(void){
  int par[3]; nxt:
  if(inpt==Tlocal){markLocalAffix(inptValue);
    par[0]=inpt;par[1]=inptValue;pushBUFFER(2,par);nextSymbol();goto nxt;}
  else if(inpt==Tformal||inpt==Titem||inpt==Tconst){
    par[0]=inpt;par[1]=inptValue;pushBUFFER(2,par);nextSymbol();goto nxt;}
  else if(inpt==Dlwb||inpt==Dupb||inpt==Dvlwb||inpt==Dvupb||inpt==Dcalibre||
    inpt==Dnoarg||inpt==Dsub||inpt==Dbus||inpt==Dcolon||inpt==Dstar){
    par[0]=inpt;pushBUFFER(1,par);nextSymbol();goto nxt;}
  par[0]=Dout;must(par);NODE->offset[thisNode-NODE_fnext]=par[1];
  must(par);NODE->offset[thisNode-NODE_tnext]=par[1];
  par[0]=Dcomma;must(par);
}
static void computeRuleAffixHash(void){
  int par[3];int old;
  old=BUFFER->aupb;storeRuleAffixes();
  par[0]=STACKpar(BUFFER);par[1]=old;blockhash(par);
  NODE->offset[thisNode-NODE_hash]=par[2];par[0]=STACKpar(BUFFER);
  par[1]=old;unstackto(par);
}
static int nodeWithSameHash(int nn){
  int t,h,n;
  h=NODE->offset[nn-NODE_hash];t=NODE->offset[nn-NODE_tag];
  n=NODE->alwb;nxt:if(n>NODE->aupb){return 0;}
  if(n!=nn && hasNodeFlag(n,nrule) && NODE->offset[n-NODE_hash]==h
     && NODE->offset[n-NODE_tag]==t){return 1;}
  n+=NODE_CALIBRE;goto nxt;
}
static int nodeHashDifferent(void){
  int n=NODE->alwb;nxt:if(n>NODE->aupb){return 1;}
  if(hasNodeFlag(n,nrule) && nodeWithSameHash(n)){return 0;}
  n+=NODE_CALIBRE;goto nxt;
}
static int equalAffixes(int p1,int p2){
  nxt:if(BUFFER->offset[p1]==BUFFER->offset[p2]){
    if(BUFFER->offset[p1]==Dcomma){return 1;}
    p1--;p2--;goto nxt;}
  return 0;
}
static void compareToStoredAffixes(int oldbuffer){
  int n,h,keep;int par[2];
  h=NODE->offset[thisNode-NODE_hash];keep=1;n=NODE->alwb;
  nxt:if(n>=thisNode){;}
  else if(hasNodeFlag(n,nstored)&& NODE->offset[n-NODE_hash]==h
    && equalAffixes(NODE->offset[thisNode-NODE_adm],NODE->offset[n-NODE_adm])){
    keep=0;NODE->offset[thisNode-NODE_adm]=n;setNodeFlag(nargsame);}
  else{n+=NODE_CALIBRE;goto nxt;}
  if(keep==0){;}else{keep=0;n+=NODE_CALIBRE;nxt2:
    if(n>NODE->aupb){;}
    else if(hasNodeFlag(n,nrule)&&NODE->offset[n-NODE_hash]==h){keep=1;}
    else{n+=NODE_CALIBRE;goto nxt2;}}
  if(keep==0){par[0]=STACKpar(BUFFER);par[1]=oldbuffer;unstackto(par);}
  else{setNodeFlag(nstored);}
}
static void checkNodeHash(void){
  int old;int par[2];
  if(nodeWithSameHash(thisNode)){old=BUFFER->aupb;
   par[0]=Dcomma;pushBUFFER(1,par);storeRuleAffixes();
   NODE->offset[thisNode-NODE_adm]=BUFFER->aupb;
   compareToStoredAffixes(old);}
  else{skipToComma();}
}
/* ======================================== */
static int sameNodes(int n1,int n2){
  if(NODE->offset[n1-NODE_tag]!=NODE->offset[n2-NODE_tag]){ return 0;}
  if(NODE->offset[n1-NODE_hash]!=NODE->offset[n2-NODE_hash]){ return 0; }
  if(NODE->offset[n1-NODE_fnext]!=NODE->offset[n2-NODE_fnext]){return 0;}
  if(NODE->offset[n1-NODE_tnext]!=NODE->offset[n2-NODE_tnext]){return 0;}
  nxt1:if(hasNodeFlag(n1,nargsame)){n1=NODE->offset[n1-NODE_adm];goto nxt1;}
  nxt2:if(hasNodeFlag(n2,nargsame)){n2=NODE->offset[n2-NODE_adm];goto nxt2;}
  if(n1==n2){return 1;}
  return 0;
}
static void getNodeIndex(int *a){ /* >node + idx> */
  a[1]=a[0]-NODE->alwb;a[1] /= NODE_CALIBRE;a[1]++;
}
static void replaceLabels(int n1,int n2){
  int par[3];int n;
//DEBUG
  if(hasNodeFlag(n1,nsame)){printf("replaceLabels: impossible ...\n");exit(14);}
  NODE->offset[n2-NODE_adm]=n1;putNodeFlag(n2,nsame);
  par[0]=n1;getNodeIndex(par);n1=par[1];par[0]=n2;
  getNodeIndex(par);n2=par[1];
  n=NODE->alwb;nxt:
  if(n>NODE->aupb){;}
  else{if(NODE->offset[n-NODE_fnext]==n2){NODE->offset[n-NODE_fnext]=n1;}
    if(NODE->offset[n-NODE_tnext]==n2){NODE->offset[n-NODE_tnext]=n1;}
    n+=NODE_CALIBRE;goto nxt;}
}
static void findEqualNodes(void){
  int yes,n1,n2;again:
  yes=0;n1=NODE->alwb;nxt:if(n1>=NODE->aupb){;}
  else if(hasNodeFlag(n1,nsame)){n1+=NODE_CALIBRE;goto nxt;}
  else{n2=n1+NODE_CALIBRE;nxt2:
    if(n2>NODE->aupb){n1+=NODE_CALIBRE;goto nxt;}
    if(hasNodeFlag(n2,nsame)){n2+=NODE_CALIBRE;goto nxt2;}
    if(sameNodes(n1,n2)){yes=1;replaceLabels(n1,n2);}
    n2+=NODE_CALIBRE;goto nxt2;}
  if(yes==0){;}else{goto again;}
}
/* ------------------------------------------------------ */
static void findRealLabel(int *a){/* >old + new> */
  if(a[0]<=0){a[1]=a[0];return;}
  a[0]=(a[0]-1)*NODE_CALIBRE+NODE->alwb;nxt:
  if(hasNodeFlag(a[0],nsame)){a[0]=NODE->offset[a[0]-NODE_adm];goto nxt;}
  a[1]=(a[0]-NODE->alwb)/NODE_CALIBRE+1;
}
static void findNextNode(int *a){/* idx> */
   int n;
   a[0]=0;n=thisNode+NODE_CALIBRE;nxt:
   if(n>NODE->aupb){return;}
   if(hasNodeFlag(n,nsame)){n+=NODE_CALIBRE;goto nxt;}
   a[0]=1+(n-NODE->alwb)/NODE_CALIBRE;
}
static void markNode(int nxt,int label){
  int par[2];par[0]=label;findRealLabel(par);label=par[1];
  if(label<=0||label==nxt){ return;}
  label=(label-1)*NODE_CALIBRE+NODE->alwb;putNodeFlag(label,nlabel);
}
static void ruleLabel(void){
  int idx;int par[2];
  if(isNodeFlag(nsame)){;}
  else{findNextNode(par);idx=par[0];
    markNode(idx,NODE->offset[thisNode-NODE_fnext]);
    markNode(idx,NODE->offset[thisNode-NODE_tnext]);}
}
static void areaLabels(void){
  int nxt,l1,l2;int par[2];
  findNextNode(par);nxt=par[0];l1=l2=0;nxt:par[0]=Darea;
  if(R(par)){markNode(0,l1);l1=l2;skipToLabel(par);l2=par[0];goto nxt;}
  if(isNodeFlag(nzone)){markNode(nxt,l1);markNode(nxt,l2);}
  else{markNode(0,l1);markNode(nxt,l2);}
}
static void extensionLabel(void){
  int nxt,label;int par[1];
  findNextNode(par);nxt=par[0];skipToLabel(par);label=par[0];
  markNode(nxt,label);
}
static void generateLabel(void){
  int par[3];int label,nextnode;
  advanceNode();if(isNodeFlag(nsame)){return;}
  findNextNode(par);nextnode=par[0];
  if(isNodeFlag(nlabel)){label=thisNode-NODE->alwb;
    label=label/NODE_CALIBRE+1;}
  else{label=0;}
  par[0]=label;par[1]=nextnode;Tlabel(par);
}
/* ====================================================== */
static void generateRuleCall(void){
  int par[14];int type,tag,C1,C2,C3,n,rep,star,odummy,idummy,ptr,
                  fnext,tnext;
  par[0]=Titem;must(par);tag=par[1];
  par[0]=tag;if(getItemDef(par)){tag=par[1];}
  if(NODE->offset[thisNode-NODE_tag]!=tag){printf("ERROR: not same tag\n");exit(28);}
  par[0]=Tconst;must(par);C1=par[1];must(par);C2=par[1];must(par);C3=par[1];
  ptr=BUFFER->aupb,n=idummy=odummy=rep=star=0;nxt:
  par[0]=Dout;if(R(par)){must(par);}
  else{storeRuleAffix(par);type=par[0];par[0]=Dplus;pushBUFFER(1,par);
    n++;if(rep){rep++;}if(type==Dcolon){idummy=1;}
    else if(type==Dnoarg){odummy=1;}
    else if(type==Dstar){if(rep){star=1;}else{rep=1;}}
    goto nxt;}
  par[0]=NODE->offset[thisNode-NODE_fnext];findRealLabel(par);fnext=par[1];
  par[0]=NODE->offset[thisNode-NODE_tnext];findRealLabel(par);tnext=par[1];
  par[0]=tag;par[1]=C1;par[2]=C2;par[3]=C3;par[4]=n;par[5]=fnext;par[6]=tnext;
  par[7]=rep;par[8]=star;par[9]=odummy;par[10]=idummy;par[11]=ptr;
  TruleCall(par);par[0]=STACKpar(BUFFER);par[1]=ptr;unstackto(par);
}
/* ====================================================== */
static void generateExtension(void){
  int par[3];int obuff,x,ptr,label;
  obuff=BUFFER->aupb;storeList(0);par[0]=Tconst;must(par);x=par[1];
  BUFFER->offset[obuff+1]=x;par[0]=0;pushBUFFER(1,par);ptr=BUFFER->aupb;
  nxt:storeAffix();par[0]=Dplus;pushBUFFER(1,par);nxt2:
    par[0]=Dto;if(R(par)){par[0]=Tconst;must(par);x=par[1];
    par[0]=x;pushBUFFER(1,par);goto nxt2;}
    else if(par[0]=Dout,RR(par)){par[0]=par[1];findRealLabel(par);
      label=par[1];par[0]=-1;pushBUFFER(1,par);par[0]=obuff;par[1]=label;
      Textension(par);}
    else{par[0]=-1;par[1]=0;pushBUFFER(2,par);BUFFER->offset[ptr]=BUFFER->aupb;
       ptr=BUFFER->aupb;goto nxt;}
  par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
}
/* ====================================================== */
static void generateArea(void){
  int par[3];nxt:
  readAreaInterval(par);pushBUFFER(2,par);
  par[0]=Dsemicolon;if(R(par)){pushBUFFER(1,par);goto nxt;}
}
static void generateAreas(void){
  int par[3];int last,out,idx;
  last=0;par[0]=Darea;must(par);nxt:
  par[0]=Tconst;must(par);par[0]=0;pushBUFFER(1,par);
  if(last==0){;}else{BUFFER->offset[last]=BUFFER->aupb;}last=BUFFER->aupb;
  par[0]=0;pushBUFFER(1,par);out=BUFFER->aupb;generateArea();
  par[0]=Dout;must(par);idx=par[1];par[0]=idx;findRealLabel(par);
  BUFFER->offset[out]=par[1];par[0]=Darea;if(R(par)){par[0]=Dplus;
    pushBUFFER(1,par);goto nxt;}
  if(isNodeFlag(nzone)){par[0]=STACKpar(BUFFER);par[1]=out;unstackto(par);
    par[0]=INT_MIN;par[1]=INT_MAX;par[2]=Dplus;pushBUFFER(3,par);}
  else{par[0]=Dplus;pushBUFFER(1,par);}
}
static void generateBox(void){
  int par[2];int obuff,area;
  obuff=BUFFER->aupb;storeAffix();par[0]=Dplus;pushBUFFER(1,par);
  area=BUFFER->aupb;generateAreas();
  par[0]=obuff;par[1]=area;Tbox(par);
  par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
}
/* ====================================================== */
static void scanI(void){
  int par[3];again:
  par[0]=Dbox;if(R(par)){advanceNode();setNodeFlag(nbox);
    skipAffix();checkAreas();par[0]=Dcomma;must(par);goto again;}
  par[0]=Dextension;if(R(par)){advanceNode();setNodeFlag(nextension);
    skipToComma();goto again;}
  par[0]=Dnode;if(R(par)){advanceNode();setNodeFlag(nrule);
    setRuleHead();computeRuleAffixHash();goto again;}
  par[0]=Dpoint;must(par);
}
static void scanII(void){
  int par[3];int obuff;
  obuff=BUFFER->aupb;nxt:
  par[0]=Dbox;if(R(par)){advanceNode();skipToComma();goto nxt;}
  par[0]=Dextension;if(R(par)){advanceNode();skipToComma();goto nxt;}
  par[0]=Dnode;if(R(par)){advanceNode();skipRuleHead();checkNodeHash();goto nxt;}
  par[0]=Dpoint;must(par);
  par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
  findEqualNodes();
}
static void scanIII(void){
  int par[3];again:
  par[0]=Dbox;if(R(par)){advanceNode();skipAffix();areaLabels();
    par[0]=Dcomma;must(par);goto again;}
  par[0]=Dextension;if(R(par)){advanceNode();extensionLabel();
    par[0]=Dcomma;must(par);goto again;}
  par[0]=Dnode;if(R(par)){advanceNode();ruleLabel();skipToComma();goto again;}
  par[0]=Dpoint;must(par);
}
static void scanIV(void){
   int par[3];again:
   par[0]=Dbox;if(R(par)){generateLabel();generateBox();par[0]=Dcomma;
     must(par);goto again;}
   par[0]=Dextension;if(R(par)){generateLabel();generateExtension();
     par[0]=Dcomma;must(par);goto again;}
   par[0]=Dnode;if(R(par)){generateLabel();
       if(isNodeFlag(nsame)){skipToComma();goto again;}
       else{generateRuleCall();par[0]=Dcomma;must(par);goto again;}}
   par[0]=Dpoint;must(par);
}
/* ------------------------------------------------------ */
void makeRule(void){
   int par[7];int tag,minloc,maxloc,obuff;
   par[0]=Titem;must(par);tag=par[1];
   par[0]=Tconst;must(par);minloc=par[1];
   par[0]=Tconst;must(par);maxloc=par[1];
   createNodes();
   saveInputPosition();
   thisNode=0;obuff=BUFFER->aupb;clearStackSize();
     startLocalAffixcheck(minloc,maxloc);scanI();doLocalAffixcheck=0;
   if(nodeHashDifferent()){;}
   else{restoreInputPosition();thisNode=0;scanII();}
   par[0]=tag;par[1]=C1;par[2]=C2;par[3]=C3;par[4]=minloc;par[5]=maxloc;
   par[6]=localAffixPtr;ruleDeclarationHead(par);
   par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
   restoreInputPosition();thisNode=0;scanIII();
   restoreInputPosition();thisNode=0;scanIV();
   ruleDeclarationTail();
//printf("rule ");par[0]=tag;printPointer(par);printf(" C2=%d,C3=%d, nodes=%d\n",C2,C3,1+(NODE->aupb-NODE->alwb)/NODE_CALIBRE);
//printf("nodes: ");{int n;for(n=NODE->alwb;n<=NODE->aupb;n+=NODE_CALIBRE){printf(" (%d,%x,%d|%d,%d) ",1+(n-NODE->alwb)/NODE_CALIBRE,(nlabel|nsame)&NODE->offset[n-NODE_flag],nsame&NODE->offset[n-NODE_flag]?(1+(NODE->offset[n-NODE_adm]-NODE->alwb)/NODE_CALIBRE):-1,NODE->offset[n-NODE_fnext],NODE->offset[n-NODE_tnext]);} printf("\n");}
}
/* ------------------------------------------------------ */
void initialize_rule(void){
  init_MSG();
}

/* EOF */

