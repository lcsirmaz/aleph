/* item.ale */
#include "stddata.h"
#include "lexical.h"
#include "item.h"
#include "error.h"

/* -------------------------------------------*/
#define tglobal	(tpublic|timported|texternal)
#define touter  (timported|texternal)
#define titemMask (tglobal|rtype|rvararg|routvararg|rtrace|rcount|rbounds)

static int incompatible_global_types,incompatible_external,
  doubly_defined,not_defined,same_title,two_main_modules,
  no_main_module;
#define addMSG(x,y)	add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_MSG(void){
  addMSG("%p: incompatible types at %i and %i",incompatible_global_types);
  addMSG("%p: mixing external at %i and %i",incompatible_external);
  addMSG("%p: doubly defined at %i and %i",doubly_defined);
  addMSG("%p: no definition, requested at %i",not_defined);
  addMSG("module with the same title %p",same_title);
  addMSG("two main modules: %p and %p",two_main_modules);
  addMSG("no main module",no_main_module);
}
#undef addMSG
static int StdString;

#define addLEXT(x,y)	add_new_string(x,LEXT);expandstack(par);y=LEXT->aupb
static void init_LEXT(void){
  int par[4];
  par[0]=STACKpar(LEXT);par[1]=2;par[2]=par[3]=0;
  addLEXT("@StringTable",StdString);
}
#undef addLEXT

/* ------------------------------------------- */
static int baseItem=0,maxLineno=0,firstItem=0;

static void expandITEM(void){
  int par[8];
  par[0]=STACKpar(ITEM);par[1]=6;par[2]=par[3]=par[4]=par[5]=par[6]=par[7]=0;
  expandstack(par);
}

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
  int par[2];par[0]=a[0];par[1]=touter;if(isItemFlag(par)){
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
//printf("stackSize %d -(",a[0]);par[0]=a[0];getSsel(par);printf("%d,",par[1]);getCalibre(par);printf("%d); %d -(",par[1],a[1]);par[0]=a[1];getSsel(par);printf("%d,",par[1]);getCalibre(par);printf("%d)\n",par[1]);
  par[0]=a[0];getSsel(par);x1=par[1];par[0]=a[1];getSsel(par);
  if(x1!=par[1]){return 1;}
  par[0]=a[0];getCalibre(par);x1=par[1];par[0]=a[1];getCalibre(par);
  if(x1!=par[1]){return 1;}
  return 0;
}
static int unequalTypes(int type1,int type2){
  if(type1==type2){return 0;}
  if(type1==Iconstant&&type2==IpointerConstant){return 0;}
  if(type1==IpointerConstant&&type2==Iconstant){return 0;}
  return 1;
}
static int incompatibleTypes(int *a){/* >item1 + >item2 */
  int type;
  type=ITEM->offset[a[0]-ITEM_type];
  if(unequalTypes(type,ITEM->offset[a[1]-ITEM_type])){return 1;}
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
void getFill(int *a){ /* >item+ x> */
  a[1]=AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_fill];
}
void getListLink(int *a){/* >item + x> */
  a[1]=AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_link];
}
void putVupb(int *a){/* >item + >x */
  AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_vupb]=a[1];
}
void putVlwb(int *a){/* >item + >x */
  AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_vlwb]=a[1];
}
void putFill(int *a){/* >item + >x */
  AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_fill]=a[1];
}
void putListLink(int *a){/* >item + >x */
  AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_link]=a[1];
}
void getNumberOfFormals(int *a){/* >item + n> */
  a[1]=AUX->offset[ITEM->offset[a[0]-ITEM_adm]-AUX_count];
}
void getFormal(int *a){/* >item + >i + type> */
  int p;
  p=ITEM->offset[a[0]-ITEM_adm];
  if(a[1]>=AUX->offset[p-AUX_count]){a[2]=0;return;}
  p++;a[2]=AUX->offset[p];nxt:if(a[1]<=0){return;}
  if(a[2]==IformalTable||a[2]==IformalStack){p+=2;}
  a[1]--;p++;a[2]=AUX->offset[p];goto nxt;
}
void getFormalCalibre(int *a){/* >item + >i + cal> */
  int p,type;
  p=ITEM->offset[a[0]-ITEM_adm];p++;type=AUX->offset[p];nxt:
  if(a[1]<=0){p++;a[2]=AUX->offset[p];if(a[2]<0){a[2]=-a[2];};return;}
  if(type==IformalTable||type==IformalStack){p+=2;}
  a[1]--;p++;type=AUX->offset[p];goto nxt;
}
void getFormalSsel(int *a){/* >item+>i>+ssel> */
  int p,type;
  p=ITEM->offset[a[0]-ITEM_adm];p++;type=AUX->offset[p];nxt:
  if(a[1]<=0){p+=2;a[2]=AUX->offset[p];return;}
  if(type==IformalTable||type==IformalStack){p+=2;}
  a[1]--;p++;type=AUX->offset[p];goto nxt;
}
void getFileData(int *a){/* >item+id>+ptr>+link> */
  int p;
  p=ITEM->offset[a[0]-ITEM_adm];a[1]=AUX->offset[p-AUX_item];
  a[2]=AUX->offset[p-AUX_count];a[3]=AUX->offset[p-AUX_link];
}
void getFileLink(int *a){/* >link> + hash> + id> */
  if(a[0]==0){a[1]=a[2]=0;}
  else{a[1]=AUX->offset[a[0]-AUX_count];a[2]=AUX->offset[a[0]-AUX_item];
    a[0]=AUX->offset[a[0]-AUX_link];}
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
  int par[8];int cal,ssel;
  par[0]=Tconst;must(par);cal=par[1];must(par);ssel=par[1];
  par[0]=STACKpar(AUX);par[1]=6;par[7-AUX_vlwb]=par[7-AUX_vupb]=
  par[7-AUX_fill]=0;
  par[7-AUX_calibre]=cal;par[7-AUX_ssel]=ssel;par[7-AUX_link]=-1;
  expandstack(par);a[0]=AUX->aupb;
}
static void checkItemID(int *a){ /* >n */
  if(a[0]==ITEM->aupb){;}
  else{printf("inpt=%d, baseITEM=%d, aupb=%d\n",a[0],baseItem,ITEM->aupb);
  corruptedObjFile(__FILE__,__LINE__);}
}
static void readItem(void){
  int par[3];int flag,lineno,type;
  expandITEM();par[0]=Ttype;must(par);type=par[1];
  ITEM->offset[ITEM->aupb-ITEM_type]=type;
  par[0]=Titem;must(par);par[0]=par[1];checkItemID(par);
  par[0]=Tconst;must(par);flag=par[1];ITEM->offset[ITEM->aupb-ITEM_flag]=(flag&titemMask);
  par[0]=Tconst;must(par);lineno=par[1];
  if(lineno<=0){;}
  else if(lineno>maxLineno){corruptedObjFile(__FILE__,__LINE__);}
  else{ITEM->offset[ITEM->aupb-ITEM_lineno]=lineno;}
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
static void checkType(int item,int type){
  int t=ITEM->offset[item-ITEM_type];
  if(t==Icharfile||t==Idatafile){if(type==Dfile){return;}}
  else if(t==Itable||t==Istack||t==IstaticStack){if(type==Dlist){return;}}
  corruptedObjFile(__FILE__,__LINE__);
}
static void fileArea(int *a){/* >ptr */
  int par[5];int list,hash;
  par[0]=Dsub;if(R(par)){nxt:par[0]=Dbus;if(R(par)){return;}
     par[0]=Titem;must(par);list=par[1];checkType(list,Dlist);
     par[0]=Tconst;must(par);hash=par[1];par[0]=STACKpar(AUX);
     par[1]=3;par[4-AUX_count]=hash;par[4-AUX_item]=list;par[4-AUX_link]=0;
     expandstack(par);AUX->offset[a[0]-AUX_link]=AUX->aupb;a[0]=AUX->aupb;
     goto nxt;}
}
void fileEntry(void){
  int par[5];int item,ptr,x;
  par[0]=Titem;must(par);item=par[1];checkType(item,Dfile);
  par[0]=STACKpar(AUX);par[1]=3;par[4-AUX_count]=par[4-AUX_item]=par[4-AUX_link]=0;
  expandstack(par);ptr=ITEM->offset[item-ITEM_adm]=AUX->aupb;
  par[0]=ptr;fileArea(par);par[0]=Tconst;must(par);x=par[1];
  if(x==1||x==3){par[0]=item;par[1]=tinfile;setItemFlag(par);}
  if(x==2||x==3){par[0]=item;par[1]=toutfile;setItemFlag(par);}
  par[0]=Titem;must(par);AUX->offset[ptr-AUX_item]=par[1];
  par[0]=Titem;must(par);AUX->offset[ptr-AUX_count]=par[1];
  par[0]=Dpoint;must(par);
}

/* =========================================== */
static void addStdstring(void){
  int par[8];
  par[0]=STACKpar(AUX);par[1]=6;par[7-AUX_vlwb]=par[7-AUX_vupb]=
  par[7-AUX_fill]=0;
  par[7-AUX_calibre]=par[7-AUX_ssel]=1;par[7-AUX_link]=-1;expandstack(par);
  par[0]=STACKpar(ITEM);par[1]=6;par[7-ITEM_flag]=tpublic;
  par[7-ITEM_type]=Itable;par[7-ITEM_lineno]=0;par[7-ITEM_tag]=StdString;
  par[7-ITEM_adm]=AUX->aupb;par[7-ITEM_repr]=0;expandstack(par);
  par[0]=StdString;par[1]=ITEM->aupb;putTagData(par);
}

/* =========================================== */
static void checkModuleTitle(void){
  int par[3]; int ptr;
  ptr=firstItem;nxt:if(ptr==0){;}
  else if(ITEM->offset[ITEM->aupb-ITEM_type]==Dtitle &&
          ITEM->offset[ptr-ITEM_type]==Dtitle){
    par[0]=two_main_modules;par[1]=ITEM->offset[ITEM->aupb-ITEM_tag];
    par[2]=ITEM->offset[ptr-ITEM_tag];error(3,par);}
  else if(ITEM->offset[ITEM->aupb-ITEM_tag]==ITEM->offset[ptr-ITEM_tag]){
    par[0]=same_title;par[1]=ITEM->offset[ITEM->aupb-ITEM_tag];
    warning(2,par);}
  else{ptr=ITEM->offset[ptr-ITEM_repr];goto nxt;}
}
static void readDefinitionList(void){
  int par[4];int n,str;nxt:
  par[0]=Tconst;must(par);n=par[1];if(n>=maxLineno){maxLineno=n;}
  else{corruptedObjFile(__FILE__,__LINE__);}
  par[0]=Tstring;must(par);str=par[1];
  par[0]=STACKpar(AUX);par[1]=2;par[3-AUX_width]=n;par[3-AUX_data]=str;
  expandstack(par);if(ITEM->offset[ITEM->aupb-ITEM_adm]==0){
    ITEM->offset[ITEM->aupb-ITEM_adm]=AUX->aupb;}
  par[0]=Dpoint;if(R(par)){;}else{goto nxt;}
}
void headSection(int *a){
  int par[2];
  expandITEM();ITEM->offset[ITEM->aupb-ITEM_flag]=a[0];
  par[0]=Dmodule;if(R(par)){ITEM->offset[ITEM->aupb-ITEM_type]=Dmodule;}
  else if((par[0]=Dtitle,R(par))){ITEM->offset[ITEM->aupb-ITEM_type]=Dtitle;}
  else{corruptedObjFile(__FILE__,__LINE__);}
  par[0]=Tstring;must(par);ITEM->offset[ITEM->aupb-ITEM_tag]=par[1];
  checkModuleTitle();maxLineno=0;readDefinitionList();
  ITEM->offset[ITEM->aupb-ITEM_lineno]=maxLineno;
  if(baseItem==0){firstItem=ITEM->aupb;}else{ITEM->offset[baseItem-ITEM_repr]=ITEM->aupb;}
  baseItem=ITEM->aupb;
}
void advanceBaseItem(int *a){/* flag> */
  if(baseItem==0){baseItem=firstItem;}else{baseItem=ITEM->offset[baseItem-ITEM_repr];}
  if(baseItem==0){a[0]=0;}
  else{ maxLineno=ITEM->offset[baseItem-ITEM_lineno];
    a[0]=ITEM->offset[baseItem-ITEM_flag];}
}
void skipHeadSection(void){
  int par[3];
  nxt:par[0]=Dpoint;if(R(par)){;}else{nextSymbol();goto nxt;}
}
/* ------------------------------------------- */
/* find positions */
static void searchForLine(int*a){/* >ptr+>old+line>+str> */
                                 /*  0     1    2    3   */
  if(a[1]<=1||a[1]>ITEM->offset[a[0]-ITEM_lineno]){
    a[2]=0;a[3]=Squoteimage;return;}
  a[0]=ITEM->offset[a[0]-ITEM_adm];a[2]=a[1]-1;a[1]++;nxt:
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
  ptr=firstItem;nxt:
  nptr=ITEM->offset[ptr-ITEM_repr];if(nptr && nptr<a[0]){ptr=nptr;goto nxt;}
  a[3]=ITEM->offset[ptr-ITEM_tag];par[0]=ptr;par[1]=ITEM->offset[a[0]-ITEM_lineno];
  searchForLine(par);a[1]=par[2];a[2]=par[3];
}
/* ------------------------------------------- */
void checkAllItems(void){
  int par[3];int ptr,def,t,mainm;
//printf("checking 2 starts from=%d to %d...\n",ITEM->alwb,ITEM->aupb);
  ptr=ITEM->alwb;mainm=0;nxt:if(ptr>ITEM->aupb){
    if(mainm==0){par[0]=no_main_module;error(1,par);}return;}
//printf(" ");par[0]=ITEM->offset[ptr-ITEM_tag];printPointer(par);printf(" %x\n",ITEM->offset[ptr-ITEM_flag]);
  t=ITEM->offset[ptr-ITEM_type];
  if(t==Dtitle){mainm=1;ptr+=ITEM_CALIBRE;goto nxt;}
  else if(t==Dmodule){ptr+=ITEM_CALIBRE;goto nxt;}
  par[0]=ptr;if(getItemDef(par)){def=par[1];
//printf("  def=%d,item=%d\n",def,ptr);
    par[0]=def;par[1]=tpublic;if(isItemFlag(par)){;}
    else if(par[1]=texternal,isItemFlag(par)){;}
    else{par[0]=not_defined;par[1]=ITEM->offset[ptr-ITEM_tag];par[2]=ptr;
        error(3,par);}}
  ptr+=ITEM_CALIBRE;goto nxt;
}
/* ------------------------------------------- */

void initialize_item(void){
  init_MSG();init_LEXT();
  baseItem=firstItem=0;
  addStdstring();
}

/* EOF */