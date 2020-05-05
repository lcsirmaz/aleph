/* data.ale */
#include "stddata.h"
#include "data.h"
#include "error.h"
#include "item.h"
#include "lexical.h"

static int constant_refers_to_itself,relative_size_estimator,
fix_size_estimator,unknown_estimator,repeat_constant_out_of_range,
repeat_constant_not_defined,insufficient_virtual_space;

#define addMSG(x,y)	add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_MSG(void){
  addMSG("%p: constant definition refers to itself (%i)",constant_refers_to_itself);
  addMSG("%p: relative size estimator %d is out of range (%i)",relative_size_estimator);
  addMSG("%p: fix size estimator %d is out or range (%i)",fix_size_estimator);
  addMSG("%p: size estimator %p has no value (%i)",unknown_estimator);
  addMSG("filling %p at %l: repeat %p has value %d out of range (1 .. 10000)",
     repeat_constant_out_of_range);
  addMSG("filling %p at %l: repeat constant %p is not defined",repeat_constant_not_defined);
  addMSG("insufficient virtual space",insufficient_virtual_space);
}
#undef addMSG
#define maxStackSize	1000000

static void pushEXPR(int v){
  int par[4];par[0]=STACKpar(EXPRESSION);par[1]=1;par[2]=v;expandstack(par);
}

static void checkListType(int item){
  int t=ITEM->offset[item-ITEM_type];
  if(t==Itable||t==Istack||t==IstaticStack){;}
  else{corruptedObjFile(__FILE__,__LINE__);}
}
static void checkConstantType(int item){
  int t=ITEM->offset[item-ITEM_type];
  if(t==Iconstant||t==IpointerConstant){;}
  else{corruptedObjFile(__FILE__,__LINE__);}
}
/* lists */
static int linkLists=0;
static void rememberList(int item){
  int par[2];
  par[0]=item;getListLink(par);if(par[1]>=0){return;}
  par[0]=item;par[1]=linkLists;putListLink(par);linkLists=item;
}

static void listEntry(void){ /* just after the 'list' keyword */
  int par[3];int item,etype,esize;
  par[0]=Titem;must(par);item=par[1];checkListType(item);
  par[0]=Tconst;must(par);etype=par[1];
  if(etype==1||etype==2){par[0]=Tconst;must(par);esize=par[1];}
  else if(etype==3||etype==4){par[0]=Titem;must(par);esize=par[1];
    checkConstantType(esize);}
  else{corruptedObjFile(__FILE__,__LINE__);esize=0;}
  par[0]=item;par[1]=etype;putVupb(par);par[0]=item;par[1]=esize;putVlwb(par);
  rememberList(item);par[0]=Dpoint;must(par);
}
/* ------------------------------------------- */
static void fillItem(void){
  int par[2];
  par[0]=Dopen;if(R(par)){nxt: par[0]=Dclose;if(R(par)){;}
    else if((par[0]=Tconst,R(par))){goto nxt;}
    else{par[0]=Titem;must(par);checkConstantType(par[1]);goto nxt;}}
  else if((par[0]=Tconst,R(par))){;}
  else{par[0]=Titem;must(par);checkConstantType(par[1]);}
}
static void fillRepeater(void){
  int par[2];
  par[0]=Dstar;if(R(par)){par[0]=Tconst;if(R(par)){;}
    else{par[0]=Titem;must(par);checkConstantType(par[1]);}}
}
static void fillInitializer(int list){/* >list */
  int par[2];
  nxt:par[0]=Dcolon;if(R(par)){par[0]=Titem;must(par);
    if(ITEM->offset[par[1]-ITEM_type]==IpointerConstant
       && ITEM->offset[par[1]-ITEM_adm]==0){;}
    else{corruptedObjFile(__FILE__,__LINE__);}
    ITEM->offset[par[1]-ITEM_adm]=list;
    goto nxt;}
}
static void skipFill(void){
  int par[2];int item;
  par[0]=Titem;must(par);item=par[1];checkListType(item);par[0]=Tconst;must(par);
  rememberList(item);
  nxt:par[0]=Dpoint;if(R(par)){;}
  else{fillItem();fillRepeater();fillInitializer(item);goto nxt;}
}
static void relativeSize(int *a){/* >x+ >item */
  int par[4];
  if(a[0]<1||a[0]>100){par[0]=relative_size_estimator;
    par[1]=ITEM->offset[a[1]-ITEM_tag];par[2]=a[0];par[3]=a[1];warning(4,par);}
  if(a[0]>100){a[0]=100;}if(a[0]<1){a[0]=1;};
  par[0]=a[1];par[1]=a[0];putVupb(par);
}
static void fixSize(int *a){/* >x + >item */
  int par[4];
  if(a[0]<1||a[0]>maxStackSize){par[0]=fix_size_estimator;
    par[1]=ITEM->offset[a[1]-ITEM_tag];par[2]=a[0];par[3]=a[1];warning(4,par);}
  if(a[0]>maxStackSize){a[0]=maxStackSize;}if(a[0]<1){a[0]=1;}
  par[0]=a[1];par[1]=-a[0];putVupb(par);
}
static int getConstValue(int *a){/* >tag + x> */
  int par[3];int def;
  par[0]=a[0];par[1]=tvalue;if(isItemFlag(par)){a[1]=ITEM->offset[a[0]-ITEM_repr];}
  else if(getItemDef(par) && (def=par[1],par[0]=def,par[1]=tvalue,isItemFlag(par))){
    a[1]=ITEM->offset[def-ITEM_repr];ITEM->offset[a[0]-ITEM_repr]=a[1];
    par[0]=a[0];par[1]=tvalue;setItemFlag(par);}
  else{return 0;}
  return 1;
}
static void getEstimator(int *a){/* >tag + >list + x> */
  int par[4];
  par[0]=a[0];if(getConstValue(par)){a[2]=par[1];}
  else{a[2]=1;par[0]=unknown_estimator;par[1]=ITEM->offset[a[1]-ITEM_tag];
    par[2]=ITEM->offset[a[0]-ITEM_tag];par[3]=a[1];error(4,par);}
}
void looseBounds(void){
  int par[3];int item,etype,esize;
  item=linkLists;nxt: if(item==0){return;}
  par[0]=item;if(getItemDef(par)){par[1]=0;putVlwb(par);putVupb(par);}
  else{par[0]=item;getVupb(par);etype=par[1];getVlwb(par);esize=par[1];
    par[1]=0;putVlwb(par);if(etype==1){par[0]=esize;par[1]=item;relativeSize(par);}
    else if(etype==2){par[0]=esize;par[1]=item;fixSize(par);}
    else if(etype==3){par[0]=esize;par[1]=item;getEstimator(par);
      par[0]=par[2];par[1]=item;relativeSize(par);}
    else if(etype==4){par[0]=esize;par[1]=item;getEstimator(par);
      par[0]=par[2];par[1]=item;fixSize(par);}
    else{par[0]=item;par[1]=0;putVupb(par);}}
  par[0]=item;getListLink(par);item=par[1];goto nxt;
}
static int filltableSize=0;

static void looseFillItem(int *a){/* size> */
  int par[2];
  par[0]=Dopen;if(R(par)){a[0]=0;nxt:par[0]=Dclose;if(R(par)){;}
   else if(par[0]=Tconst,R(par)){a[0]++;goto nxt;}
   else{par[0]=Titem;must(par);a[0]++;goto nxt;}}
  else if(par[0]=Tconst,R(par)){a[0]=1;}
  else{par[0]=Titem;must(par);a[0]=1;}
}
static void repeaterValue(int *a){/*>list+>lineno+item>+cnt>*/
  int par[5];                     /*  0       1     2    3  */
  par[0]=a[2];if(getConstValue(par)){a[3]=par[1];
    if(1<=a[3]&&a[3]<=10000){;}
    else{par[1]=ITEM->offset[a[0]-ITEM_tag];par[2]=a[1];
      par[3]=ITEM->offset[a[2]-ITEM_tag];par[4]=a[3];
      par[0]=repeat_constant_out_of_range;warning(5,par);
      a[3]=1;}}
  else{a[3]=0;par[0]=repeat_constant_not_defined;par[1]=
    ITEM->offset[a[0]-ITEM_tag];par[2]=a[1];par[3]=
    ITEM->offset[a[2]-ITEM_tag];error(4,par);}
}
static void looseRepeater(int *a){/* >list+>lineno+>size */
  int par[5];int item,cnt;
  par[0]=Dstar;if(R(par)){par[0]=Tconst;if(RR(par)){cnt=par[1];}
      else{par[0]=Titem;must(par);item=par[1];par[0]=item;
        if(getItemDef(par)){item=par[1];} par[0]=a[0];
        par[1]=a[1];par[2]=item;repeaterValue(par);cnt=par[3];}
    if(cnt==1){;}else{filltableSize+=2;}
    a[2]*=cnt;}
  par[0]=a[0];getFill(par);par[1]+=a[2];putFill(par);
}
static void looseInitializer(int *a){ /* >list */
  int par[2];int item;
  nxt:par[0]=Dcolon;if(R(par)){par[0]=Titem;must(par);item=par[1];
    par[0]=item;if(getItemDef(par)){printf("looseInitializer: after colon\n");exit(13);}
    par[0]=a[0];getFill(par);ITEM->offset[item-ITEM_repr]=par[1];
    ITEM->offset[item-ITEM_adm]=a[0];
    goto nxt;}
}
static void looseFill(void){
  int par[4];int list,lineno,size;
  par[0]=Titem;must(par);list=par[1];
  par[0]=list;if(getItemDef(par)){list=par[1];rememberList(list);}
  par[0]=Tconst;must(par);lineno=par[1];
  nxt:par[0]=Dpoint;if(R(par)){;}
  else{looseFillItem(par);size=par[0];filltableSize+=size;
    par[0]=list;par[1]=lineno;par[2]=size;looseRepeater(par);
    par[0]=list;looseInitializer(par);goto nxt;}
}
#define minVirtualAddress	0x01000000
#define maxVirtualAddress	0x77ffffff
static void collectListSizeClaims(int *a){/* abs> + rel> */
  int par[2];int ptr,x,y;
  a[0]=a[1]=0;ptr=linkLists;nxt:if(ptr==0){return;}
  par[0]=ptr;if(getItemDef(par)){getListLink(par);ptr=par[1];goto nxt;}
  par[0]=ptr;getCalibre(par);x=par[1];a[0]+=x;getFill(par);x=par[1];
  getVupb(par);y=par[1];if(y<=0){y=-y;if(x<y){x=y;}a[0]+=x;}
  else{a[1]+=y;a[0]+=x;}par[0]=ptr;getListLink(par);ptr=par[1];goto nxt;
}
static void setListBounds(int *a){/* >by */
  int par[2];int addr,ptr,cal,x,y;
  addr=minVirtualAddress;ptr=linkLists;nxt:if(ptr==0){return;}
  par[0]=ptr;if(getItemDef(par)){getListLink(par);ptr=par[1];goto nxt;}
  par[0]=ptr;getFill(par);x=par[1];getVupb(par);y=par[1];if(y<=0){y=-y;}
  else{y*=a[0];}if(x<y){x=y;} par[0]=ptr;getCalibre(par);cal=par[1];
  y=cal+addr;par[0]=ptr;par[1]=y;putVlwb(par);addr+=x;par[1]=addr;
  putVupb(par);addr+=cal;par[0]=ptr;getListLink(par);ptr=par[1];goto nxt;
}
void distributeVirtualAddress(void){
  int par[3];int abs,rel,by,y;
  collectListSizeClaims(par);abs=par[0];rel=par[1];if(rel>0){;}else{rel=1;}
  by=maxVirtualAddress-minVirtualAddress;y=0;if(abs<0){y=1;}
  else if(by<abs){y=1;}else{by=by-abs;by=by/rel;if(by<=0){y=1;}}
  if(y){par[0]=insufficient_virtual_space;error(1,par);}
  else{par[0]=by;setListBounds(par);}
}
/* ---------------------------------------------------------- */
static void setPointerValue(int ptr){
  int par[3];int list,cal,lwb;
  list=ITEM->offset[ptr-ITEM_adm];par[0]=list;getCalibre(par);
  cal=par[1];getVlwb(par);lwb=par[1];lwb-=cal;
  ITEM->offset[ptr-ITEM_repr]+=lwb;
  par[0]=ptr;par[1]=tvalue;setItemFlag(par);
}
void finalizePointerConstants(void){
  int par[2];int ptr;
  ptr=ITEM->alwb;nxt:if(ptr>ITEM->aupb){return;}
  if(ITEM->offset[ptr-ITEM_type]==IpointerConstant){
     par[0]=ptr;if(getItemDef(par)){corruptedObjFile(__FILE__,__LINE__);}
     setPointerValue(ptr);}
  ptr+=ITEM_CALIBRE;goto nxt;
}
/* ---------------------------------------------------------- */
/* DEBUG */
void printAll(void){
  int par[3];int ptr,type;
  printf("total fill: %d\n",filltableSize);
  ptr=ITEM->alwb;nxt:if(ptr>ITEM->aupb){return;}
  par[0]=ptr;if(getItemDef(par)&&par[1]!=ptr){ptr+=ITEM_CALIBRE;goto nxt;}
  type=ITEM->offset[ptr-ITEM_type];
  if(type==Irule||type==Iconstant||type==IpointerConstant){ptr+=ITEM_CALIBRE;goto nxt;}
  par[0]=ptr;par[1]=texternal;if(isItemFlag(par)){printf("**EX** ");}
  par[0]=type;printPointer(par); printf(" ");
  par[0]=ITEM->offset[ptr-ITEM_tag];printPointer(par);printf(": ");
  if(type==Iconstant||type==IpointerConstant||type==Ivariable){
     int v=0;par[0]=ptr;par[1]=tvalue;if(isItemFlag(par)){v=1;}
     printf(" v=%d %c",ITEM->offset[ptr-ITEM_repr],v==1?' ':'*');
         }
  if(type==Itable||type==Istack||type==IstaticStack){int lwb,upb,fill;
     par[0]=ptr;getVlwb(par);lwb=par[1];getVupb(par);upb=par[1];getFill(par);
     fill=par[1];
     printf(" [%d .. %d] fill=%d",lwb,upb,fill);}
  printf("\n");
  ptr+=ITEM_CALIBRE;goto nxt;
}
void printBounds(void){
  int par[3];int item,vlwb,vupb;int notdef;
  //printf("linkLists=%d\n",linkLists);
  printAll();return;
  item=linkLists;nxt:if(item==0){return;}
  notdef=0;par[0]=item;if(getItemDef(par)){notdef=1;}
  else{
    par[0]=ITEM->offset[item-ITEM_tag];printPointer(par);printf(": %c ",notdef?'*':' ');
    par[0]=item;getCalibre(par);vupb=par[1];getSsel(par);vlwb=par[1];
    printf("cal=%d, ssel=%d ",vupb,vlwb);
    par[0]=item;getVupb(par);vupb=par[1];getVlwb(par);vlwb=par[1];
    printf("lwb=%d, upb=%d\n",vlwb,vupb);}
  par[0]=item;getListLink(par);item=par[1];goto nxt;
}

/* ---------------------------------------------------------- */
static int linkExpr=0; /* link all expressions in EXPRESSION */

static void readExpression(void){
  int par[3];int item,ptr,t;
  par[0]=Titem;must(par);item=par[1];t=ITEM->offset[item-ITEM_type];
  if(t==Iconstant||t==Ivariable||t==IstaticVar){;}
  else{corruptedObjFile(__FILE__,__LINE__);}
  pushEXPR(item),ptr=EXPRESSION->aupb;pushEXPR(linkExpr);linkExpr=ptr;
  ITEM->offset[item-ITEM_adm]=EXPRESSION->aupb;nxt:
  if(inpt==Dpoint){nextSymbol();pushEXPR(Dpoint);}
  else if(inpt==Tconst){pushEXPR(Tconst);pushEXPR(inptValue);nextSymbol();goto nxt;}
  else if(inpt==Titem){checkConstantType(inptValue);pushEXPR(inptValue);
     nextSymbol();goto nxt;}
  else if(inpt==Dlwb||inpt==Dupb||inpt==Dcalibre){pushEXPR(inpt);nextSymbol();
     par[0]=Titem;must(par);item=par[1];pushEXPR(item);checkListType(item);goto nxt;}
  else if(inpt==Dplus||inpt==Dminus||inpt==Dstar||inpt==Ddiv||inpt==Dand||
    inpt==Dor||inpt==Dxor||inpt==Dcompl||inpt==Dopen||inpt==Dclose){
    pushEXPR(inpt);nextSymbol();goto nxt;}
  else{corruptedObjFile(__FILE__,__LINE__);}
}
/* =========================================================== */
/* data section */
static void skipEntry(void){
  int par[3];
  par[0]=Dpoint;nxt:if(R(par)){;}else{nextSymbol();goto nxt;}
}
void dataSection(void){
  int par[2];
  if(wasError()){return;}
  nxt:par[0]=Dfill;if(R(par)){skipFill();goto nxt;}
  par[0]=Dexpression;if(R(par)){readExpression();goto nxt;}
  par[0]=Dlist;if(R(par)){listEntry();goto nxt;}
  par[0]=Dfile;if(R(par)){fileEntry();goto nxt;}
}
void dataSectionII(void){
  int par[2];
  nxt:par[0]=Dexpression;if(R(par)){skipEntry();goto nxt;}
  par[0]=Dlist;if(R(par)){skipEntry();goto nxt;}
  par[0]=Dfile;if(R(par)){skipEntry();goto nxt;}
  par[0]=Dfill;if(R(par)){looseFill();goto nxt;}
}
/* =========================================================== */
static int eptr=0;
static int E(int x){
  if(EXPRESSION->offset[eptr]==x){eptr++;return 1;}
  return 0;
}
static int Eitem(int *a){ /* v> */
  int par[3];par[0]=STACKpar(ITEM);a[0]=par[1]=EXPRESSION->offset[eptr];
  if(was(par)){eptr++;return 1;}
  return 0;
}
static int Eop(int *a){ /* >prop+op>+p> */
  a[1]=EXPRESSION->offset[eptr];
  if(a[1]==Dxor && a[0]==0){a[2]=1;eptr++;return 1;}
  if(a[1]==Dand && a[0]<=1){a[2]=2;eptr++;return 1;}
  if(a[1]==Dor  && a[0]<=2){a[2]=3;eptr++;return 1;}
  if((a[1]==Dplus||a[1]==Dminus)&& a[0]<=3){a[2]=4;eptr++;return 1;}
  if((a[1]==Ddiv||a[1]==Dstar)&& a[0]<=4){a[3]=5;eptr++;return 1;}
  return 0;
}
static void optor(int *a){ /* >op + >w + >v> */
  if(a[0]==Dxor){a[2] ^=a[1];}
  else if(a[0]==Dand){a[2] &= a[1];}
  else if(a[0]==Dor) {a[2] |= a[1];}
  else if(a[0]==Dplus){ a[2]+=a[1];}
  else if(a[0]==Dminus){a[2]-=a[1];}
  else if(a[0]==Dstar){a[2] *= a[1];}
  else if(a[0]==Ddiv) {a[2] = a[2]/a[1];}
  else{ printf("unknown optor %d\n",a[0]);exit(23);}
}
static int looseExpr(int *a); static void looseEval(int item);
static int looseBase(int *a){ /* v> */
  int par[3];int v;
  if(E(Dopen)){par[0]=0;if(looseExpr(par)){a[0]=par[1];if(E(Dclose)){;}
     else{printf("looseBase: missing Dclose\n");exit(23);} return 1;}
     else{return 0;}}
  if(E(Tconst)){a[0]=EXPRESSION->offset[eptr];eptr++;return 1;}
  if(E(Dcompl)){if(looseBase(a)){a[0]=~a[0];return 1;} else{return 0;}}
  if(E(Dminus)){if(looseBase(a)){a[0]=-a[0];return 1;} else{return 0;}}
  if(E(Dcalibre)){par[0]=EXPRESSION->offset[eptr];getCalibre(par);a[0]=par[1];
     eptr++;return 1;}
  if(Eitem(par)){v=par[0];if(ITEM->offset[v-ITEM_type]!=Iconstant){return 0;}
    looseEval(v);par[0]=v;par[1]=tvalue;if(isItemFlag(par)){
      a[0]=ITEM->offset[v-ITEM_repr];return 1;}else{return 0;}}
  return 0;
}
static int looseExpr(int *a){ /* >prio + v> */
   int par[3];int op,p,w;
   if(looseBase(par)){a[1]=par[0];nxt:
     par[0]=a[0];if(Eop(par)){op=par[1];p=par[2];par[0]=p;
        if(looseExpr(par)){w=par[1];par[0]=op;par[1]=w;par[2]=a[1];optor(par);
          a[1]=par[2];goto nxt;}
        else{return 0;}}
     else{return 1;}}
   return 0;
}
static void setFinalValue(int *a){/* >v + >item1 + >item2 */
  int par[3];
  par[0]=a[1];par[1]=teval;clearItemFlag(par);
  ITEM->offset[a[1]-ITEM_repr]=a[0];par[0]=a[1];par[1]=tvalue;
  setItemFlag(par);if(a[1]==a[2]){;}else{
    ITEM->offset[a[2]-ITEM_repr]=a[0];par[0]=a[2];par[1]=tvalue;
    setItemFlag(par);}
}
static void looseEval(int item){
  int par[3];int def,oldptr;
  par[0]=item;par[1]=tvalue;if(isItemFlag(par)){return;}
  par[0]=item;if(getItemDef(par)){def=par[1];}else{def=item;}
  par[0]=def;par[1]=teval;if(isItemFlag(par)){
    par[0]=constant_refers_to_itself;par[1]=ITEM->offset[def-ITEM_tag];
    par[2]=def;error(3,par);par[0]=0;par[1]=def;par[2]=item;setFinalValue(par);
    return;}
  par[0]=def;par[1]=teval;setItemFlag(par);oldptr=eptr;
  eptr=ITEM->offset[def-ITEM_adm];eptr++;
  par[0]=STACKpar(EXPRESSION);par[1]=eptr;
  if(was(par)){;}else{corruptedObjFile(__FILE__,__LINE__);}
  par[0]=0;if(looseExpr(par)){par[0]=par[1];par[1]=def;par[2]=item;setFinalValue(par);}
  else{par[0]=def;par[1]=teval;clearItemFlag(par);}
  eptr=oldptr;
}
void looseEvaluation(void){
  int ptr;
  if(wasError()){return;}
  ptr=linkExpr;nxt:if(ptr==0){;}
  else{looseEval(EXPRESSION->offset[ptr]);ptr++;ptr=EXPRESSION->offset[ptr];goto nxt;}
}
/* ----------------------------------------------------------- */
/* final evaluation */
static void getExprLimit(int *a){/* >what + >item + x> */
  int par[3];
  par[0]=a[1];if(getItemDef(par)){a[1]=par[1];}
  if(a[0]==Dlwb){par[0]=a[1];getVlwb(par);a[2]=par[1];}
  else{par[0]=a[1];getVupb(par);a[2]=par[1];}
}
static void finalExpr(int *a),finalEval(int item);
static void finalBase(int *a){ /* v> */
  int par[3];int v;
  if(E(Dopen)){par[0]=0;finalExpr(par);a[0]=par[1];
     if(E(Dclose)){;}else{printf("Dclose expexted in finalBase\n");exit(23);}
     return;}
  if(E(Tconst)){a[0]=EXPRESSION->offset[eptr];eptr++;return;}
  if(E(Dcompl)){finalBase(a);a[0]=~a[0]; return; }
  if(E(Dminus)){finalBase(a);a[0]=-a[0]; return; }
  if(E(Dcalibre)){par[0]=EXPRESSION->offset[eptr];getCalibre(par);
    a[0]=par[1];eptr++;return;}
  if(E(Dlwb)){par[0]=Dlwb;par[1]=EXPRESSION->offset[eptr];
    getExprLimit(par);a[0]=par[2];eptr++;return;}
  if(E(Dupb)){par[0]=Dupb;par[0]=EXPRESSION->offset[eptr];
    getExprLimit(par);a[0]=par[2];eptr++;return;}
  if(Eitem(par)){v=par[0];finalEval(v);a[0]=ITEM->offset[v-ITEM_repr]; return;}
  corruptedObjFile(__FILE__,__LINE__);
}
static void finalExpr(int *a){ /* >prio + v> */
  int par[3];int op,p,w;
  finalBase(par);a[1]=par[0];nxt:par[0]=a[0];if(Eop(par)){
   op=par[1];p=par[2];par[0]=p;finalExpr(par);w=par[1];
   par[0]=op;par[1]=w;par[2]=a[1];optor(par);a[1]=par[2];goto nxt;}
}
static void finalEval(int item){
  int par[3];int def,v,oldptr;
  par[0]=item;par[1]=tvalue;if(isItemFlag(par)){return;}
  par[0]=item;if(getItemDef(par)){def=par[1];}else{def=item;}
  par[0]=def;par[1]=tvalue;if(isItemFlag(par)){
    ITEM->offset[item-ITEM_repr]=ITEM->offset[def-ITEM_repr];
    par[0]=item;par[1]=tvalue;setItemFlag(par);return;}
  par[0]=def;par[1]=teval;if(isItemFlag(par)){
    par[0]=constant_refers_to_itself;par[1]=ITEM->offset[def-ITEM_tag];
    par[2]=item;error(3,par);par[0]=0;par[1]=def;par[2]=item;
    setFinalValue(par);return;}
  par[0]=def;par[1]=teval;setItemFlag(par);oldptr=eptr;eptr=
  ITEM->offset[def-ITEM_adm];eptr++;par[0]=STACKpar(EXPRESSION);
  par[1]=eptr;if(was(par)){;}else{corruptedObjFile(__FILE__,__LINE__);}
  par[0]=0;finalExpr(par);v=par[1];eptr=oldptr;par[0]=v;par[1]=def;
  par[2]=item;setFinalValue(par);
}
void finalEvaluation(void){
  int ptr;
  ptr=linkExpr;nxt:if(ptr==0){;}
  else{finalEval(EXPRESSION->offset[ptr]);ptr++;ptr=EXPRESSION->offset[ptr];goto nxt;}
}
/* ----------------------------------------------------------- */
void initialize_data(void){
  init_MSG();
}


/* EOF */

