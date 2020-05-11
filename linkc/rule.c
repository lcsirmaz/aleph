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
static void add_interval(int *a){/* >set + >lw + >up + >new> */
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
  set=ZONE->offset[ZONE_next];ni=ZONE->offset[set-ZONE_next];
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
/* ------------------------------------------------ */
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
    else{corruptedObjFile(__FILE__,__LINE__);}}
  else{a[0]=a[1]=count=0;}
  par[0]=Dcolon;if(R(par)){
   if(count==0){a[0]=INT_MIN;}else if(count==1){;}
   else{corruptedObjFile(__FILE__,__LINE__);}
   par[0]=Tconst;if(RR(par)){a[1]=par[2];}
   else if(par[0]=Titem,RR(par)){tag=par[1];par[0]=tag;
     if(getItemDef(par)){tag=par[1];}t=ITEM->offset[tag-ITEM_type];
     if(t==Iconstant||t==IpointerConstant){a[1]=ITEM->offset[tag-ITEM_repr];}
     else{corruptedObjFile(__FILE__,__LINE__);}}
   else{a[1]=INT_MAX;}}
  else if(count==0){corruptedObjFile(__FILE__,__LINE__);}
}
/* ------------------------------------------------ */
static int isLimit(void){
  int par[1];
  par[0]=Dcalibre;if(R(par)){return 1;}
  par[0]=Dlwb;if(R(par)){return 1;}
  par[0]=Dupb;if(R(par)){return 1;}
  par[0]=Dvlwb;if(R(par)){return 1;}
  par[0]=Dvupb;if(R(par)){return 1;}
  return 0;
}
static void skipAffix(void){
  int par[3];
  par[0]=Tformal;if(R(par)){return;}
  par[0]=Tlocal;if(R(par)){return;}
  par[0]=Titem;if(R(par)){return;}
  par[0]=Dnoarg;if(R(par)){return;}
  par[0]=Tconst;if(R(par)){return;}
  if(isLimit()){par[0]=Tformal;if(R(par)){;}else{par[0]=Titem;must(par);} return;}
  par[0]=Dsub;if(R(par)){skipAffix();par[0]=Dbus;must(par);
     par[0]=Tformal;if(R(par)){;}else{par[0]=Titem;must(par);}
     par[0]=Tconst;must(par);return;}
printf("skip affix, inpt=%d ",inpt);par[0]=inpt;printPointer(par);printf("\n");
  corruptedObjFile(__FILE__,__LINE__);
}
static void skipZone(void){
  int par[3];
  par[0]=Tconst;if(R(par)){return; }
  par[0]=Titem;if(R(par)){return;}
}
static void skipArea(void){
  int par[3];nxt:
  skipZone();par[0]=Dcolon;if(R(par)){goto nxt;}
  par[0]=Dsemicolon;if(R(par)){goto nxt;}
  par[0]=Dout;must(par);
}
static void skipBox(void){
  int par[3];
  par[0]=Tnode;must(par);skipAffix();nxt:
  par[0]=Darea;if(R(par)){par[0]=Tconst;must(par);skipArea();goto nxt;}
  par[0]=Dcomma;must(par);
}
static void skipExtension(void){
  int par[3];
  par[0]=Tnode;must(par);
  par[0]=Tformal;if(R(par)){;}else{par[0]=Titem;must(par);}
  par[0]=Tconst;must(par);nxt2:skipAffix();nxt:par[0]=Dto;
  if(R(par)){par[0]=Tconst;must(par);goto nxt;}
  par[0]=Dout;if(R(par)){par[0]=Dcomma;must(par);}
  else{ goto nxt2;}
}
static void skipInAffix(int type){
  if(type==IformalOut){;}else{skipAffix();}
}
static void skipOutAffix(int type){
  if(type==IformalOut||type==IformalInout){skipAffix();}
}
static void skipInAffixes(int *a){/* >tag + >rep> */
  int par[3];int n,i,type;
  par[0]=a[0];getNumberOfFormals(par);n=par[1];i=a[1]; nxt:
  if(i>=n){;}else{par[0]=a[0];par[1]=i;getFormal(par);type=par[2];
  i++;if(type==IformalRepeat){a[1]=i;}
  else{skipInAffix(type);goto nxt;}}
}
static void skipBlockInAffixes(int tag,int rep,int cnt){
  int par[3];
  nxt:if(cnt==0){return;}
  if(cnt<0){cnt++;}else{cnt--;}
  par[0]=tag;par[1]=rep;skipInAffixes(par);rep=par[1];goto nxt;
}
static void skipOutAffixes(int tag,int rep){
  int par[3];int n,i,type;
  par[0]=tag;getNumberOfFormals(par);n=par[1];i=rep;nxt:
  if(i>=n){;}else{par[0]=tag;par[1]=i;getFormal(par);type=par[2];
  i++;if(type==IformalRepeat){;}else{skipOutAffix(type);goto nxt;}}
}
static void skipBlockOutAffixes(int tag,int rep,int cnt){
  nxt:if(cnt==0){return;}
  if(cnt<0){cnt++;}else{cnt--;}skipOutAffixes(tag,rep);goto nxt;
}
static void readNode(void){
  int par[3];int tag,rep,cnt;
  par[0]=Tnode;must(par);
  par[0]=Titem;must(par);tag=par[1];par[0]=Tconst;must(par);must(par);must(par);
  rep=cnt=0;par[0]=tag;par[1]=rep;skipInAffixes(par);rep=par[1];
  if(rep==0){;}
  else{par[0]=Dstar;must(par);par[0]=Tconst;must(par);cnt=par[1];
    skipBlockInAffixes(tag,rep,cnt);if(cnt>0){;}else{par[0]=Dstar;must(par);}}
  par[0]=Dout;must(par);
  skipOutAffixes(tag,0);
  if(rep==0){;}else{skipBlockOutAffixes(tag,rep,cnt);}
  par[0]=Dout;must(par);
  par[0]=Dcomma;must(par);
}

void makeRule(void){
  int par[3];int rtag;
  saveInputPosition();
  par[0]=Titem;must(par);rtag=par[1];
  par[0]=Tconst;must(par);must(par);
  must(par);
  nxt:
  par[0]=Dpoint;if(R(par)){return;}
  par[0]=Dnode;if(R(par)){readNode();goto nxt;}
  par[0]=Dbox;if(R(par)){skipBox();goto nxt;}
  par[0]=Dextension;if(R(par)){skipExtension();goto nxt;}
  corruptedObjFile(__FILE__,__LINE__);
}

/* EOF */

