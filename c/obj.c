/* obj.ale */

#include "stddata.h"
#include "obj.h"
#include "lexical.h"
#include "display.h"
#include "disc.h"
#include "input.h"
#include "lists.h"
#include "pragmats.h"
#include "tags.h"
#include "types.h"

/* ================================== */
/* messages */
static int 
tag_not_defined,type_tag_not_defined,
tag_type_error,tag_list_type_error,cannot_be_external,
type_tag_not_used,cannot_have_filling,undefined_selector,wrong_filling_block,
double_selector,
large_block_size,small_block_size,opening_OBJ,wrong_Wtag_argument,
wrong_Wstring_argument;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void add_messages(void){
 addMSG("%p: not defined",tag_not_defined);
 addMSG("%p %p: not defined",type_tag_not_defined);
 addMSG("%p %p: should be %p",tag_type_error);
 addMSG("%p %p: should be a list",tag_list_type_error);
 addMSG("%p %p: not used",type_tag_not_used);
 addMSG("%p %p: not used, cannot have filling",cannot_have_filling);
 addMSG("%p %p: cannot be external (%l)",cannot_be_external);
 addMSG("filling %p: undefined selector %p",undefined_selector);
 addMSG("filling %p: field %p duplicated",double_selector);
 addMSG("filling %p: not consecutive block",wrong_filling_block);
/* warning */
 addMSG("filling %p: block size %d is bigger than calibre (%d)",large_block_size);
 addMSG("filling %p: block size %d is smaller than calibre (%d)",small_block_size);
/* internal error */
 addMSG("cannot open obj file %p, error code: %p",opening_OBJ);
 addMSG("Wtag: wrong argument %p",wrong_Wtag_argument);
 addMSG("Wstring: wrong argument %p",wrong_Wstring_argument);
}
#undef addMSG
/* ----------------------------------------------------------- */
void openObjFile(void){
   int par[5];
   createObjName();par[0]=CHFILEpar(OBJ);par[1]='w';
   par[2]=STACKpar(LEXT);par[3]=LEXT->aupb;
   if(openFile(par)){par[0]=LEXT->aupb;forgetString(par);}
   else{par[0]=CHFILEpar(OBJ);getFileError(par);par[2]=par[1];
     par[0]=opening_OBJ,par[1]=LEXT->aupb;internalError(2,par);}
}
void closeObjFile(void){
  int par[1];par[0]=CHFILEpar(OBJ);closeFile(par);
}
void deleteObjFile(void){
  int par[3];
  closeObjFile();
  createObjName();par[0]=STACKpar(LEXT);par[1]=LEXT->aupb;
  unlinkFile(par);par[0]=LEXT->aupb;forgetString(par);
}
/* ----------------------------------------------------------- */
/* writing to OBJ */
static void printInt1(int *a);
static void separator(void){
  int par[2];par[0]=CHFILEpar(OBJ);par[1]=' ';Aputchar(par);
}
static void nlcr(void){
  int par[2];par[0]=CHFILEpar(OBJ);par[1]=newline;Aputchar(par);
}
#include <values.h> /* MININT */
static void printInt(int *a){ /* >n */
  int par[3];
  if(a[0]==MININT){par[0]=CHFILEpar(OBJ);par[1]='-';Aputchar(par);
    par[0]=-1;par[1]=a[0];subtr(par);a[0]=par[2];par[0]=a[0];
    par[1]='1';printInt1(par);}
  else if(a[0]<0){par[0]=CHFILEpar(OBJ);par[1]='-';Aputchar(par);
    par[0]=-a[0];par[1]='0';printInt1(par);}
  else{par[0]=a[0];par[1]='0';printInt1(par);}
}
static void printInt1(int *a){ /* +>n + >c */
  int par[4];int q,r;
  par[0]=a[0];par[1]=10;divrem(par);q=par[2];r=par[3];
  if(q==0){;}else{par[0]=q;par[1]='0';printInt1(par);}
  par[0]=CHFILEpar(OBJ);par[1]=r+a[1];Aputchar(par);
}
void W(int *a){ /* +>x */
  int par[3];
  if(DSYMB->vlwb<=a[0]&&a[0]<=DSYMB->vupb){par[0]=CHFILEpar(OBJ);
     par[1]=STACKpar(DSYMB);par[2]=a[0];Aputstring(par);
     if(a[0]==Dpoint){par[1]='\n';Aputchar(par);}}
//  else if(INDICATOR->vlwb<=a[0]&&a[0]<=INDICATOR->vupb){par[0]=CHFILEpar(OBJ);
//     par[1]='\'';Aputchar(par);
//     par[1]=STACKpar(INDICATOR);par[2]=a[0];Aputstring(par);
//     par[1]='\'';Aputchar(par);}
  else if(ITEM->vlwb<=a[0]&&a[0]<=ITEM->vupb){par[0]=CHFILEpar(OBJ);
     par[1]='I';Aputchar(par);par[0]=a[0]-ITEM->alwb;printInt(par);
     separator();}
  else { printf("ERROR: W(%d) with unknown pointer (%d -- %d)\n",a[0],DSYMB->vlwb,DSYMB->vupb); exit(88);}
}
void Wcons(int *a){ /* >x */
  printInt(a);separator();
}
void Wtag(int *a){/* >tag */
  int par[2];
  par[0]=STACKpar(LADM);par[1]=a[0];if(was(par)){par[0]=a[0];
    getRepr(par);par[0]=par[1];if(par[0]!=0){W(par);}
    else{printf("\n *** Wtag repr=0 ***");par[0]=a[0];printPointer(par);printf(" ***\n");}}
  else{par[0]=wrong_Wtag_argument;par[1]=a[0];internalError(2,par);}
}
static void Wstring(int *a){ /* >str */
  int par[3];
  if(LEXT->vlwb<=a[0]&&a[0]<=LEXT->vupb){par[0]=CHFILEpar(OBJ);
    par[1]=STACKpar(LEXT);par[2]=a[0];Aputasstring(par);nlcr();}
  else if(TTAG->vlwb<=a[0]&&a[0]<=TTAG->vupb){par[0]=CHFILEpar(OBJ);
    par[1]=STACKpar(TTAG);par[2]=a[0]-TTAG->calibre;Aputasstring(par);
    nlcr();}
  else{par[0]=wrong_Wstring_argument;par[1]=a[0];internalError(2,par);}
}
static void Wtype(int *a){ /* >type */
  int par[3];
  par[0]=CHFILEpar(OBJ);par[1]='<';Aputchar(par);
  par[0]=CHFILEpar(OBJ);par[1]=STACKpar(INDICATOR);par[2]=a[0];
  Aputstring(par);par[0]=CHFILEpar(OBJ);par[1]='>';Aputchar(par);
  separator();
}
/* ----------------------------------------------------------- */
void createObjHeader(void){
   int par[3];int ptr,n,str;
   par[0]=pgtModule;if(isPragmatValue(par)){par[0]=Dmodule;W(par);}
   else{par[0]=Dtitle;W(par);}
   par[0]=pgtTitle;getPragmatValue(par);par[0]=par[1];Wstring(par);
   ptr=0;nxt:par[0]=ptr;if(nextInputEntry(par)){ptr=par[0];n=par[1];str=par[2];
    par[0]=n;Wcons(par);par[0]=str;Wstring(par);goto nxt;}
   else{par[0]=Dpoint;W(par);}
   assignItems();par[0]=Dpoint;W(par);
   if(XstringTableFilling()){par[0]=Dpoint;W(par);}
}
/* ---------------------------------- */
/* call back routines for objHeader */
static int nextItem=0;
static void getNewItem(int *a){ /* item> */
  if(nextItem==0){nextItem=ITEM->alwb; a[0]=nextItem;}
  else{nextItem+=ITEM->calibre;a[0]=nextItem;}
}
static int isItemTag(int *a){ /* >tag+>type */
  int par[2];
  if(a[1]==Itable){par[0]=a[0];par[1]=tfill;if(isTagFlag(par)){return 1;}
     par[1]=tused;if(isTagFlag(par)){return 1;}return 0;}
  par[0]=a[0];par[1]=tdefined;if(!isTagFlag(par)){return 0;}
  par[0]=a[0];par[1]=tused;if(!isTagFlag(par)){return 0;}
  if(a[1]==Iempty){printf("**** ERROR ****, defined/used and Iempty\n");exit(28);}
  if(a[1]==Irule){
    par[0]=a[0];par[1]=tpublic;if(isTagFlag(par)){return 1;}
    par[0]=a[0];par[1]=rmacro;if(isTagFlag(par)){return 0;}}
  return 1;
}
//static int notDefinedTag(int *a){ /* >tag */
//  int par[2];
//  par[0]=a[0];par[1]=tused;if(isTagFlag(par)){par[0]=a[0];
//    par[1]=tdefined;if(isTagFlag(par)){;}else{ return 1;}
//  }
//  return 0;
//}
static void listData(int *a){ /* >tag */
  int par[2];
  par[0]=a[0];getCalibre(par);par[0]=par[1];Wcons(par);
  par[0]=a[0];getSsel(par);par[0]=par[1];Wcons(par);
}
static void formalAffixes(int *a){ /* >tag */
  int par[3]; int n,formal,type;
  par[0]=a[0];getAdm(par);formal=par[1];n=0;nxt:
  if(formal==0){;}else{n++;par[0]=formal;getAdm(par);formal=par[1];goto nxt;}
  par[0]=a[0];getAdm(par);formal=par[1];par[0]=n;Wcons(par);nxt2:
  if(formal==0){;}else{par[0]=formal;getType(par);type=par[1];par[0]=type;
    Wtype(par);if(type==IformalStack||type==IformalTable){par[0]=formal;
      getFormalCalibre(par);par[0]=par[1];Wcons(par);par[0]=formal;
      getFormalSsel(par);par[0]=par[1];Wcons(par);}
    par[0]=formal;getAdm(par);formal=par[1];goto nxt2;}
}
void defineObjTag(int *a){ /* >tag */
  int par[3];int item,type,raw,flag,dl;
  if(a[0]==0){return;}
//printf("++");par[0]=a[0];printPointer(par);par[0]=a[0];par[1]=tused;printf(" used=%d ++\n",isTagFlag(par)?1:0);
  par[0]=a[0];fixListUsage(par);
  par[0]=a[0];getType(par);type=par[1];par[0]=a[0];getDefline(par);dl=par[1];
  par[0]=a[0];par[1]=type;if(!isItemTag(par)){
       par[0]=a[0];par[1]=tpublic;if(isTagFlag(par)){
       par[0]=type_tag_not_defined;par[1]=a[0];par[2]=type;
       Xerror(dl,3,par);par[0]=a[0];par[1]=tpublic;clearTagFlag(par);}
    return; 
  }
  getNewItem(par);item=par[0];
  par[0]=a[0];par[1]=texternal;if(isTagFlag(par)){getRepr(par);raw=par[1];}
  else{getTag(par);raw=par[1];}
  par[0]=a[0];par[1]=objflags;getTagFlag(par);flag=par[2];
  par[0]=a[0];par[1]=item;putRepr(par);
//  par[0]=type;if(isPlainType(par)){par[0]=par[1];W(par);
  par[0]=type;Wtype(par);par[0]=item;W(par);
  par[0]=flag;Wcons(par);par[0]=dl;Wcons(par);
  if(type==Iconstant||type==Ivariable||type==IstaticVar||type==IpointerConstant
   ||type==Icharfile||type==Idatafile){;}
  else if(type==Itable||type==Istack||type==IstaticStack){par[0]=a[0];
   listData(par);}
  else if(type==Irule){par[0]=a[0];formalAffixes(par);}
  else{printf("*** defineObj: unknown type=");par[0]=type;printPointer(par);printf(" ***");}
  par[0]=raw; Wstring(par);
}
/* ----------------------------------------- */
/* call back routines for XstringTableFill */
void XstringTableFillingHead(int *a){
   int par[1];
   par[0]=Dfill;W(par);par[0]=a[0];Wtag(par);
}
void XstringTableItem(int *a){/* >tag + >str */
   int par[3];int x;
   par[0]=Dopen;W(par);par[0]=STACKpar(LEXT);par[1]=a[1];
   stringwidth(par);x=a[1]-par[2];nxt:
   if(x<a[1]){x++;par[0]=LEXT->offset[x];Wcons(par);goto nxt;}
   par[0]=Dclose;W(par);par[0]=Dcolon;W(par);par[0]=a[0];
   Wtag(par);
}
/* ------------------------------------------------------ */
/* general error messages */
static void wrongType(int *a){/* >tag+>expected */
  int par[4];int type;
  par[0]=a[0];getType(par);type=par[1];
  if(type==Iempty){par[0]=tag_not_defined;par[1]=a[0];Error(2,par);}
  else if(par[1]==0){par[0]=tag_list_type_error;par[2]=a[0];par[1]=type;Error(3,par);}
  else{par[0]=tag_type_error,par[2]=a[0];par[1]=type;par[2]=a[1];Error(3,par);}
}
static void noExternal(int *a){/* >tag */
  int par[4];int dl,type;
  par[0]=a[0];getType(par);type=par[1];par[0]=a[0];par[1]=texternal;
  if(isTagFlag(par)){par[0]=a[0];getDefline(par);dl=par[1];
    par[0]=cannot_be_external;par[1]=type;par[2]=a[0];par[3]=dl;Error(4,par);}
  else if(type==Iempty){par[0]=tag_not_defined;par[1]=a[0];Error(2,par);}
}
/* ======================= */
/* lists */
//static int isListUsed(int *a){ /* >tag */
//  int par[3];
//  par[0]=a[0];par[1]=tused;if(isTagFlag(par)){return 1;}
//  par[0]=a[0];par[1]=tfill;if(isTagFlag(par)){return 1;}
//  par[0]=a[0];getType(par);/* type=par[1]; */par[0]=type_tag_not_used;
//  par[2]=a[0];Warning(3,3,par);
//  return 0;
//}
void dListSize(void){
  int par[3];int tag,etype,esize,type;
  mustQtag(par);tag=par[0];par[1]=tused;if(isTagFlag(par)){
    mustQcons(par);etype=par[0];
    par[0]=Dlist;W(par);par[0]=tag;Wtag(par);par[0]=etype;Wcons(par);
    if(etype<=2){mustQcons(par);Wcons(par);}
    else{mustQtag(par);esize=par[0];getType(par);type=par[1];
      if(type==Iconstant){par[0]=esize;noExternal(par);par[0]=esize;Wtag(par);}
      else{par[0]=esize;par[1]=Iconstant;wrongType(par);}}
    par[0]=Dpoint;W(par);par[0]=Dpoint;mustQ(par);}
  else if((par[1]=tfill,isTagFlag(par))){par[0]=Dpoint;Qskip(par);}
  else{par[0]=tag;getType(par);type=par[1];par[0]=type_tag_not_used;
    par[1]=type;par[2]=tag;Warning(3,3,par);par[0]=Dpoint;Qskip(par);}
}
/* filling ================= */
static void repeater(void){
  int par[2];int x,type;
  par[0]=Dstar;if(Q(par)){par[0]=Dstar;W(par);
//printf("\n *** repeater ***\n");
   if(Qcons(par)){Wcons(par);}
   else{mustQtag(par);x=par[0];getType(par);type=par[1];
     if(type==Iconstant){par[0]=x;noExternal(par);par[0]=x;Wtag(par);}
     else{par[0]=x;par[1]=Iconstant;wrongType(par);}}
}}
static void initializer(void){
  int par[3];int tag;nxt:
  par[0]=Dcolon;if(Q(par)){mustQtag(par);tag=par[0];
    par[0]=tag;par[1]=tused;if(isTagFlag(par)){
     par[0]=Dcolon;W(par);par[0]=tag;Wtag(par);}
    else{par[0]=type_tag_not_used;par[1]=IpointerConstant;par[2]=tag;
    Warning(3,3,par);} goto nxt;}
}
static void checkListItemType(int *a){/* >tag */
  int par[2];int type;
  par[0]=a[0];getType(par);type=par[1];
  if(type==Iconstant){par[0]=a[0];noExternal(par);}
  else if(type==IpointerConstant){par[0]=a[0];noExternal(par);}
  else{par[0]=a[0];par[1]=Iconstant;wrongType(par);}
}
static void countBlockItems(int *a){ /* cnt> + rep> */
  int par[2];int pos,lnum;
  a[0]=a[1]=0;saveDiscPosition(par);pos=par[0];lnum=par[1];nxt:
  par[0]=Dclose;if(Q(par)){par[0]=pos;par[1]=lnum;restoreDiscPosition(par);}
  else if((par[0]=Dstar,Q(par))){a[1]=1;goto nxt;}
  else if(Qtag(par)){a[0]++; goto nxt;}
  else{mustQcons(par);a[0]++;goto nxt;}
}
static void block(int *a){/* >tag */
  int par[5];int calibre,cnt,rep,x,y;
  par[0]=a[0];getCalibre(par);calibre=par[1];countBlockItems(par);
  cnt=par[0];rep=par[1];
//printf("\n ***fill block, count=%d, rep=%d, calibre=%d\n",cnt,rep,calibre);
  if(cnt==calibre){;}
  else if(cnt>calibre){par[0]=large_block_size;par[1]=a[0];par[2]=cnt;
    par[3]=calibre;Warning(6,4,par);}
  else if(rep!=0){rep=calibre-cnt;}
  else{par[0]=small_block_size;par[1]=a[0];par[2]=cnt;par[3]=calibre;
    Warning(3,4,par);}
  x=y=0;nxt:par[0]=Dclose;
  if(Q(par)){;}
  else if(Qtag(par)){x=par[0];Wtag(par);par[0]=x;checkListItemType(par);
    y=1;goto nxt;}
  else if((par[0]=Dstar,Q(par))){nxt2:if(rep<=0){;}else{rep--;
    if(y==1){par[0]=0;Wtag(par);}else{par[0]=x;Wcons(par);}goto nxt2;}
    goto nxt;}
  else{mustQcons(par);x=par[0];Wcons(par);y=0;goto nxt;}    
}
/* - - - - - - - - - - - - - - - - - - - - */
static void checkBlock2Extension(int *a){/* >tag+>calibre */
  int par[5]; int ptr,cnt1,cnt ;          /*   0     1     */
  cnt=0;ptr=BUFFER->aupb;ptr--;
  if(BUFFER->offset[ptr]==0){par[0]=wrong_filling_block;par[1]=a[0];
    par[2]=a[0];Error(2,par);}
  else{nxt:if(a[1]<=cnt){;}
    else if(BUFFER->offset[ptr]==0){;}
    else{cnt++;ptr-=2;goto nxt;}
    cnt1=cnt;nxt2:if(a[1]<=cnt){;}
    else if(BUFFER->offset[ptr]==0){ptr-=2;cnt++;goto nxt2;}
    if(cnt<a[1]){par[0]=wrong_filling_block;par[1]=a[0];Error(2,par);}
    else if(cnt1<cnt){par[0]=small_block_size;par[1]=a[0];
      par[2]=cnt1;par[3]=a[1];Warning(3,4,par);}}
}
static void block2Selector(int *a){ /* >tag + x>  */
  int par[5];int sel,ptr;
  par[0]=Dstar;if(Q(par)){a[1]=-1; return;}
  mustQtag(par);sel=par[0];getRepr(par);a[1]=par[1];
//printf("blck2Selector,sel=%d, aupb=%d ",a[1],BUFFER->aupb);printPointer(par);
  if(a[1]>0){a[1]--;par[0]=a[1];par[1]=-2;par[2]=BUFFER->aupb;addmult(par);
    ptr=par[3];ptr--;
//printf(" checking=%d, v=%d\n",ptr,BUFFER->offset[ptr]);
    if(BUFFER->offset[ptr]==0){;}
    else{par[0]=double_selector;par[1]=a[0];par[2]=sel;Error(3,par);}}
  else{par[0]=undefined_selector;par[1]=a[0];par[2]=sel,Error(3,par);a[1]=-1;}
}
static void block2(int *a){ /* >tag */
  int par[5];int optr,calibre,x,y,rx,ry,ptr,sel;
  optr=BUFFER->aupb;par[0]=a[0];getCalibre(par);calibre=par[1];x=calibre;
  nxt1:par[0]=STACKpar(BUFFER);par[1]=0;extend(par);extend(par);x--;
  if(x==0){;}else{goto nxt1;}
//printf("block2, bloc start=%d, cal=%d, v=%d,\n",optr+1,calibre,BUFFER->offset[optr+1]);
  rx=ry=0;nxt2:
  if(Qtag(par)){x=par[0];checkListItemType(par);y=2;}
  else{mustQcons(par);x=par[0];y=1;}
  dest:par[0]=Dto;if(Q(par)){par[0]=a[0];block2Selector(par);sel=par[1];
    if(sel<0){rx=x;ry=y;}
    else{par[0]=sel;par[1]=-2;par[2]=BUFFER->aupb;addmult(par);ptr=par[3];
      BUFFER->offset[ptr]=x;ptr--;BUFFER->offset[ptr]=y;}
    goto dest;}
  else if((par[0]=Dextension,Q(par))){;}
  else{goto nxt2;}
  ptr=optr;nxt3:if(ry==0){;}else if(ptr>=BUFFER->aupb){;}
  else{ptr++;if(BUFFER->offset[ptr]==0){BUFFER->offset[ptr]=ry;ptr++;
     BUFFER->offset[ptr]=rx;}else{ptr++;} goto nxt3;}
  par[0]=a[0];par[1]=calibre;checkBlock2Extension(par);
  ptr=optr;nxt4:
  if(ptr>=BUFFER->aupb){;}
  else{ptr++;y=BUFFER->offset[ptr];ptr++;x=BUFFER->offset[ptr];
    if(y==1){par[0]=x;Wcons(par);}else if(y==2){par[0]=x;Wtag(par);}
    goto nxt4;}
  par[0]=STACKpar(BUFFER);par[1]=optr;unstackto(par);
}
/* - - - - - - - - - - - - - - - - - - - - */
static void writeString(int *a){ /* >str */
   int par[3];int x;
   par[0]=Dopen;W(par);
   par[0]=STACKpar(LEXT);par[1]=a[0];stringwidth(par);x=par[2];
   x=a[0]-x;nxt:if(x<a[0]){x++;par[0]=LEXT->offset[x];Wcons(par);goto nxt;}
   par[0]=Dclose;W(par);
}
static void listItem(int *a){ /* >tag */
  int par[3];int x;
  if(Qtag(par)){x=par[0];Wtag(par);par[0]=x;checkListItemType(par);}
  else if(Qcons(par)){Wcons(par);}
  else if(Qstring(par)){writeString(par);}
  else if(par[0]=Dopen,Q(par)){par[0]=Dopen;W(par);par[0]=a[0];block(par);
    par[0]=Dclose;W(par);}
  else{par[0]=Dextension;mustQ(par);par[0]=Dopen;W(par);par[0]=a[0];block2(par);
    par[0]=Dclose;W(par);}
}
static int isFillTagUsed(int *a){ /* >tag */
  int par[3]; int type;
  par[0]=a[0];par[1]=tused;if(isTagFlag(par)){return 1;}
  par[0]=a[0];getType(par);type=par[1];if(type==Itable){
    par[0]=type_tag_not_used;par[1]=type;par[2]=a[0];Warning(3,3,par);return 1;}
  par[0]=cannot_have_filling;par[1]=type;par[2]=a[0];Error(3,par); return 0;
}

void dListFilling(void){
  int par[3];int tag;
  mustQtag(par);tag=par[0];if(isFillTagUsed(par)){
    par[0]=Dfill;W(par);par[0]=tag;Wtag(par);
    nxt:par[0]=Dpoint;if(Q(par)){par[0]=Dpoint,W(par);}
    else{par[0]=tag;listItem(par);repeater();initializer();goto nxt;}}
  else{par[0]=Dpoint;Qskip(par);}
}
/* ====================================== */
/* files */
static void fileArea(void){ /* >tag */
  int par[3];int x,type;nxt:
  par[0]=Dbus;if(Q(par)){par[0]=Dbus;W(par);}
  else{mustQtag(par);x=par[0];getType(par);type=par[1];
    if(type==Itable||type==Istack||type==IstaticStack){par[0]=x;
      noExternal(par);}
    else{par[0]=x;par[1]=0;wrongType(par);}
    par[0]=x;Wtag(par);mustQcons(par);Wcons(par);
    goto nxt;}
}
void dFileData(void){
  int par[3];int tag;
  mustQtag(par);tag=par[0];par[1]=tused;if(isTagFlag(par)){
   par[0]=Dfile;W(par);par[0]=tag;Wtag(par);
   par[0]=Dsub;if(Q(par)){par[0]=Dsub;W(par);fileArea();}
   mustQcons(par);Wcons(par);mustQtag(par);Wtag(par);
   mustQtag(par);Wtag(par);par[0]=Dpoint;mustQ(par);par[0]=Dpoint;W(par);}
  else{
   par[0]=tag;getType(par);par[2]=tag;par[0]=type_tag_not_used;Warning(3,3,par);
   par[0]=Dpoint;Qskip(par);}
}
/* ====================================== */
/* expression */
static void checkConstantTag(int *a){ /* >tag */
  int par[3];int type;
  par[0]=a[0];getType(par);type=par[1];
  if(type==Iconstant){par[0]=a[0];noExternal(par);}
  else if(type==IpointerConstant){par[0]=a[0];noExternal(par);}
  else{par[0]=a[0];par[1]=Iconstant;wrongType(par);}
}
static void checkListTag(int *a){ /* >/tag */
  int par[3];int type;
  par[0]=a[0];getType(par);type=par[1];
  if(type==Itable){par[0]=a[0];noExternal(par);}
  else if(type==Istack){par[0]=a[0];noExternal(par);}
  else if(type==IstaticStack){par[0]=a[0];noExternal(par);}
  else{par[0]=a[0];par[1]=0;wrongType(par);}
}
static void exprbase(void);
static void expression(void){
  int par[2];
  par[0]=Dminus;if(Q(par)){par[0]=Dminus;W(par);}
  nxt:exprbase();if(par[0]=Dor,Q(par)){W(par);goto nxt;}
  else if(par[0]=Dand,Q(par)){W(par);goto nxt;}
  else if(par[0]=Dxor,Q(par)){W(par);goto nxt;}
  else if(par[0]=Dplus,Q(par)){W(par);goto nxt;}
  else if(par[0]=Dminus,Q(par)){W(par);goto nxt;}
  else if(par[0]=Dstar,Q(par)){W(par);goto nxt;}
  else if(par[0]=Ddiv,Q(par)){W(par);goto nxt;}
}
static void exprbase(void){
  int par[2];int x; nxt:
  if(Qcons(par)){Wcons(par);}
  else if(Qtag(par)){x=par[0];Wtag(par);par[0]=x;checkConstantTag(par);}
  else if(par[0]=Dcompl,Q(par)){W(par);goto nxt;}
  else if(par[0]=Dlwb,Q(par)){W(par);mustQtag(par);x=par[0];Wtag(par);par[0]=x;
     checkListTag(par);}
  else if(par[0]=Dupb,Q(par)){W(par);mustQtag(par);x=par[0];Wtag(par);par[0]=x;
     checkListTag(par);}
  else if(par[0]=Dcalibre,Q(par)){W(par);mustQtag(par);x=par[0];Wtag(par);par[0]=x;
     checkListTag(par);}
  else{par[0]=Dopen;mustQ(par);W(par);expression();par[0]=Dclose;mustQ(par);
    W(par);}
}
void dExpression(void){
  int par[3];int tag;
  mustQtag(par);tag=par[0];par[1]=tused;if(isTagFlag(par)){
     par[0]=Dexpression;W(par);par[0]=tag;Wtag(par);expression();
     par[0]=Dpoint;mustQ(par);W(par);}
  else{par[0]=tag;getType(par);par[0]=type_tag_not_used;par[2]=tag;
     if(par[1]==Iconstant){Warning(1,3,par);}else{Warning(3,3,par);}
     par[0]=Dpoint;Qskip(par);}
}
/* ------------------------------------------------------ */

void initialize_obj(void){
  add_messages();
}


/* EOF */

