/* item.ale */
#include "stddata.h"
#include "lexical.h"
#include "item.h"
#include "error.h"

/* -------------------------------------------*/
#define tglobal	(tpublic|timported|texternal)
#define titemMask ~(tglobal|rtype|rvararg|routvararg|rtrace|rcount|rbounds)

static int incompatible_global_types,incompatible_external,
  doubly_defined,not_defined,same_title;
#define addMSG(x,y)	add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_MSG(void){
  addMSG("%p: incompatible types at %i and %i",incompatible_global_types);
  addMSG("%p: mixing external at %i and %i",incompatible_external);
  addMSG("%p: doubly defined at %i and %i",doubly_defined);
  addMSG("%p: no definition, requested at %i",not_defined);
  addMSG("module with the same title %p",same_title);
}
#undef addMSG
/* ------------------------------------------- */
static int baseItem=0,maxLineno=0;

int isItemFlag(int *a){/* >item + >flag */
  if((ITEM->offset[a[0]-ITEM_flag]&a[1])!=0){return 1;}
  return 0;
}
void setItemFlag(int *a){/* >item + >flag */
  ITEM->offset[a[0]-ITEM_flag] |= a[1];
}
void clearItemFlag(int *a){/* >item + >flag */
  ITEM->offset[a[0]-ITEM_flag] &= ~a[1];
}
int getItemDef(int *a){/* >item + def> */
  int par[2];par[0]=a[0];par[1]=timported;if(isItemFlag(par)){
    par[0]=ITEM->offset[a[0]-ITEM_tag];getTagData(par);a[1]=par[1];
    return 1;}
  return 0;
}
void convertToItem(void){
  inptValue=inptValue*ITEM_CALIBRE+baseItem;
}
/* ------------------------------------------- */
static void pushAUX(int v){
  int par[3];par[0]=STACKpar(AUX);par[1]=1;par[2]=v;expandstack(par);
}
static int stackSizeMismatch(int *a){/* >item1 + >item2 */
  int par[2];int x1;
  par[0]=a[0];getSsel(par);x1=par[1];par[0]=a[1];getSsel(par);
  if(x1!=par[1]){return 1;}
  par[0]=a[0];getCalibre(par);x1=par[1];par[0]=a[1];getCalibre(par);
  if(x1!=par[1]){return 1;}
  return 0;
}
static int incompatibleTypes(int *a){/* >item1 + >item2 */
  int type;
  type=ITEM->offset[a[0]-ITEM_type];
  if(type!=ITEM->offset[a[1]-ITEM_type]){return 1;}
  if(type==Irule && ITEM->offset[a[0]-ITEM_adm]!=ITEM->offset[a[1]-ITEM_adm]){return 1;}
  if(type==Istack||type==Itable||type==IstaticStack){
    return stackSizeMismatch(a);}
  return 0;
}
static void checkCompatibility(int *a){/* >tag+>item1+>item2 */
  int par[4];
  par[0]=a[1];par[1]=a[2];if(incompatibleTypes(par)){
    par[0]=incompatible_global_types;par[1]=a[0];par[2]=a[1];par[3]=a[2];
    error(4,par);}
  else if((par[0]=a[1],par[1]=texternal,isItemFlag(par))){
    par[0]=a[2];par[1]=texternal;if(isItemFlag(par)){;}
    else{par[0]=incompatible_external;par[1]=a[0];par[2]=a[1];par[3]=a[2];
    error(4,par);}}
  else if((par[0]=a[2],par[1]=texternal,isItemFlag(par))){
    par[0]=incompatible_external;par[1]=a[0];par[2]=a[2];par[3]=a[1];
    error(4,par);}
  else if((par[0]=a[1],par[1]=tpublic,isItemFlag(par))){
    par[0]=a[2];par[1]=tpublic;if(isItemFlag(par)){par[0]=doubly_defined;
      par[1]=a[0];par[2]=a[1];par[3]=a[2];error(4,par);}}
  else if((par[0]=a[2],par[1]=tpublic,isItemFlag(par))){
    par[0]=a[0];par[1]=a[2];putTagData(par);}
}
static void enterItem(int *a){/* >item */
  int par[3];int tag,def;
  par[0]=a[0];par[1]=tglobal;if(isItemFlag(par)){;}else{return;}
  tag=ITEM->offset[a[0]-ITEM_tag];par[0]=tag;getTagData(par);def=par[1];
  if(def==0){par[0]=tag;par[1]=a[0];putTagData(par);}
  else{par[0]=tag;par[1]=def;par[2]=a[0];checkCompatibility(par);}
}
/* ------------------------------------------- */
/* module header */
static int linkFormals=0;
void getCalibre(int *a){/* > item+ x> */
  a[1]=AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_calibre];
}
void getSsel(int *a){/* >item + x> */
  a[1]=AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_ssel];
}
void getVupb(int *a){/* >item + x> */
  a[1]=AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_vupb];
}
void getVlwb(int *a){/* >item + x> */
  a[1]=AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_vlwb];
}
void putVupb(int *a){/* >item + >x */
  AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_vupb]=a[1];
}
void putVlwb(int *a){/* >item + >x */
  AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_vlwb]=a[1];
}
/* ------------------------------------------- */
static int compareFormals(int *a){/* >p1+>p2 */
  int w;
  if(AUX->offset[a[0]-AUX_count]!=AUX->offset[a[1]-AUX_count]){return 0;}
  w=AUX->offset[a[0]-AUX_width];
  if(w!=AUX->offset[a[0]-AUX_width]){return 0;}
  nxt:if(w==0){return 1;}
  a[0]++;a[1]++;if(AUX->offset[a[0]-AUX_data]!=AUX->offset[a[1]-AUX_data]){return 0;}
  w--;goto nxt;
}
static void searchFormals(int *a){ /* +>old+ >ptr> */
  int par[3];int link;
  link=linkFormals;nxt:if(link==0){AUX->offset[a[1]-AUX_link]=linkFormals;
    linkFormals=a[1];}
  else{par[0]=link;par[1]=a[1];if(compareFormals(par)){
    par[0]=STACKpar(AUX);par[1]=a[0];unstackto(par);a[1]=link;}
    else{link=AUX->offset[link-AUX_link];goto nxt;}}
}
static void storeFormalAffixes(int *a){ /* formals> */
  int par[5];int cnt,old,type;
  par[0]=Tconst;must(par);cnt=par[1];old=AUX->aupb;
  par[0]=STACKpar(AUX);par[1]=3;par[4-AUX_count]=par[4-AUX_width]=cnt;
  par[4-AUX_link]=0;expandstack(par);a[0]=AUX->aupb;nxt:
  if(cnt==0){;}
  else{cnt--;par[0]=Ttype;must(par);type=par[1];par[0]=type;pushAUX(type);
    if(type==IformalStack||type==IformalTable){
      AUX->offset[a[0]-AUX_width]++;par[0]=Tconst;must(par);pushAUX(par[1]);
      AUX->offset[a[0]-AUX_width]++;par[0]=Tconst;must(par);pushAUX(par[1]);}
    goto nxt;}
  par[0]=old;par[1]=a[0];searchFormals(par);a[0]=par[1];
}
static void storeListBounds(int *a){/* bounds> */
  int par[6];int cal,ssel;
  par[0]=Tconst;must(par);cal=par[1];must(par);ssel=par[1];
  par[0]=STACKpar(AUX);par[1]=4;par[5-AUX_vlwb]=par[5-AUX_vupb]=0;
  par[5-AUX_calibre]=cal;par[5-AUX_ssel]=ssel;expandstack(par);
  a[0]=AUX->aupb;
}
static void checkItemID(int *a){ /* >n */
  if(a[0]==ITEM->aupb){;}
  else{printf("inpt=%d, baseITEM=%d, aupb=%d\n",a[0],baseItem,ITEM->aupb);
  corruptedObjFile(__FILE__,__LINE__);}
}
static void readItem(void){
  int par[8];int flag,lineno,type;
  par[0]=STACKpar(ITEM);par[1]=6;par[2]=par[3]=par[4]=par[5]=par[6]=par[7]=0;
  expandstack(par);par[0]=Ttype;must(par);type=par[1];
  ITEM->offset[ITEM->aupb-ITEM_type]=type;
  par[0]=Titem;must(par);par[0]=par[1];checkItemID(par);
  par[0]=Tconst;must(par);flag=par[1];ITEM->offset[ITEM->aupb-ITEM_flag]=(flag&titemMask);
  par[0]=Tconst;must(par);lineno=par[1];
  if(lineno<=0){;}
  else if(lineno>maxLineno){corruptedObjFile(__FILE__,__LINE__);}
  else{ITEM->offset[ITEM->aupb-ITEM_lineno]=lineno;}
printf("type=%d,table=%d\n",type,Itable);  
  if(type==Irule){storeFormalAffixes(par);ITEM->offset[ITEM->aupb-ITEM_adm]=par[0];}
  else if(type==Istack||type==IstaticStack||type==Itable){
    storeListBounds(par);ITEM->offset[ITEM->aupb-ITEM_adm]=par[0];}
  else if(type==Iconstant||type==Ivariable||type==IstaticVar||
    type==IpointerConstant||type==Icharfile||type==Idatafile){;}
  else{corruptedObjFile(__FILE__,__LINE__);}
  par[0]=Tstring;must(par);ITEM->offset[ITEM->aupb-ITEM_tag]=par[1];
  par[0]=ITEM->aupb;enterItem(par);
}
void itemSection(void){
  int par[1];
  if(wasError()){return;}
  nxt:par[0]=Dpoint;if(R(par)){;}
  else{readItem();goto nxt;}
}
void skipItemSection(void){
  int par[1];
  nxt:par[0]=Dpoint;if(R(par)){;}
  else{nextSymbol();;goto nxt;}
}
/* =========================================== */
static void checkModuleTitle(void){
  int par[3]; int ptr;
  ptr=baseItem;nxt:if(ptr==0){;}
  else if(ITEM->offset[ITEM->aupb-ITEM_tag]==ITEM->offset[ptr-ITEM_tag]){
    par[0]=same_title;par[1]=ITEM->offset[ITEM->aupb-ITEM_tag];
    warning(2,par);}
  else{ptr=ITEM->offset[ptr-ITEM_repr];goto nxt;}
}
static void readDefinitionList(void){
  int par[4];int n,str;nxt:
  par[0]=Tconst;must(par);n=par[1];if(n>maxLineno){maxLineno=n;}
  else{corruptedObjFile(__FILE__,__LINE__);}
  par[0]=Tstring;must(par);str=par[1];
  par[0]=STACKpar(AUX);par[1]=2;par[3-AUX_width]=n;par[3-AUX_data]=str;
  expandstack(par);if(ITEM->offset[ITEM->aupb-ITEM_adm]==0){
    ITEM->offset[ITEM->aupb-ITEM_adm]=AUX->aupb;}
  par[0]=Dpoint;if(R(par)){;}else{goto nxt;}
}
void headSection(int *a){
  int par[8];
  par[0]=STACKpar(ITEM);par[1]=6;par[2]=par[3]=par[4]=par[5]=par[6]=par[7]=0;
  expandstack(par);ITEM->offset[ITEM->aupb-ITEM_flag]=a[0];
  par[0]=Dmodule;if(R(par)){ITEM->offset[ITEM->aupb-ITEM_type]=Dmodule;}
  else if((par[0]=Dtitle,R(par))){ITEM->offset[ITEM->aupb-ITEM_type]=Dtitle;}
  else if((par[0]=Dlibrary,R(par))){ITEM->offset[ITEM->aupb-ITEM_type]=Dlibrary;}
  else{corruptedObjFile(__FILE__,__LINE__);}
  par[0]=Tstring;must(par);ITEM->offset[ITEM->aupb-ITEM_tag]=par[1];
  checkModuleTitle();maxLineno=0;
  if(ITEM->offset[ITEM->aupb-ITEM_type]==Dlibrary){par[0]=Dpoint;must(par);}
  else{readDefinitionList();}
  ITEM->offset[ITEM->aupb-ITEM_lineno]=maxLineno;
  if(baseItem==0){;}else{ITEM->offset[baseItem-ITEM_repr]=ITEM->aupb;}
  baseItem=ITEM->aupb;
}
void skipHeadSection(void){
  int par[3];
  nxt:par[0]=Dpoint;if(R(par)){;}else{nextSymbol();goto nxt;}
  if(baseItem==0){baseItem=ITEM->alwb;}
  else{baseItem=ITEM->offset[baseItem-ITEM_repr];}
  maxLineno=ITEM->offset[baseItem-ITEM_lineno];
}
/* ------------------------------------------- */
/* find positions */
static void searchForLine(int*a){/* >ptr+>old+line>+str> */
                                 /*  0     1    2    3   */
  if(a[1]<=0||a[1]>ITEM->offset[a[0]-ITEM_lineno]){
    a[2]=0;a[3]=Squoteimage;return;}
  a[0]=ITEM->offset[a[0]-ITEM_adm];a[2]=a[1];nxt:
  if(a[1]>AUX->offset[a[0]-AUX_width]){
    a[2]=a[1]-AUX->offset[a[0]-AUX_width];a[0]+=2;goto nxt;}
  a[3]=AUX->offset[a[0]-AUX_data];
}
void findLineno(int *a){/* >old + line> + str> */
  int par[4];
  if(baseItem==0){a[1]=a[0];a[2]=Squoteimage; return;}
  par[0]=baseItem;par[1]=a[0];searchForLine(par);
  a[1]=par[2];a[2]=par[3];
}
void findItemLineno(int *a){/* >item + line> + str> + module> */
  int par[4];int ptr,nptr;
  ptr=ITEM->alwb;nxt:
  nptr=ITEM->offset[ptr-ITEM_repr];if(nptr && nptr<a[0]){ptr=nptr;goto nxt;}
  a[3]=ITEM->offset[ptr-ITEM_tag];par[0]=ptr;par[0]=ITEM->offset[a[0]-ITEM_lineno];
  searchForLine(par);a[1]=par[2];a[2]=par[3];
}
/* ------------------------------------------- */
void checkAllItems(void){
  int par[3];int ptr,def,t;
  ptr=ITEM->alwb;nxt:if(ptr>ITEM->aupb){return;}
  t=ITEM->offset[ptr-ITEM_type];
  if(t==Dtitle||t==Dmodule||t==Dlibrary){ptr+=ITEM_CALIBRE;goto nxt;}
  par[0]=ptr;if(getItemDef(par)){def=par[1];
    par[0]=def;par[1]=tpublic;if(isItemFlag(par)){;}
    else{par[0]=not_defined;par[1]=ITEM->offset[ptr-ITEM_tag];par[2]=ptr;
        error(3,par);}
    ptr+=ITEM_CALIBRE;goto nxt;}
}
/* ------------------------------------------- */

void initialize_item(void){
  init_MSG();baseItem=0;
}

/* EOF */