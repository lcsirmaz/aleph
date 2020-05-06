/* target.ale */
#include "stddata.h"
#include "target.h"
#include "error.h"
#include "item.h"
#include "lexical.h"

static int target_file_name,cannot_open_target;
static int sizeof_list,sizeof_chfile,sizeof_dfile,block_total;

#define addMSG(x,y)	 add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_MSG(void){
  addMSG("aleph.cc",target_file_name);
  addMSG("cannot create target file %p",cannot_open_target);
  addMSG("sizeof_LIST",sizeof_list);
  addMSG("sizeof_CHFILE",sizeof_chfile);
  addMSG("sizeof_DFILE",sizeof_dfile);
  addMSG("BLOCK_TOTAL",block_total);
}

static int extWaitfor;

#define addLEXT(x,y)	add_new_string(x,LEXT);expandstack(par);y=LEXT->aupb
static void init_LEXT(void){
  int par[4];
  par[0]=STACKpar(LEXT);par[1]=2;par[2]=par[3]=0;
  addLEXT("@waitfor",extWaitfor);
}

/* ------------------------------------------------ */
void openTarget(void){
  int par[4];
  par[0]=CHFILEpar(TARGET);par[1]='w';par[2]=STACKpar(MESSAGE);par[3]=target_file_name;
  if(openFile(par)){return;}
  par[0]=cannot_open_target;Ferror(1,par);
}
void closeTarget(void){
  int par[1];
  par[0]=CHFILEpar(TARGET);closeFile(par);
}
void deleteTarget(void){
  int par[2];
  par[0]=CHFILEpar(TARGET);closeFile(par);par[0]=STACKpar(MESSAGE);
  par[1]=target_file_name;unlinkFile(par);
}
/* ================================================= */
static void printInt(int),printInt1(int n,int c),printPtr(int);
static void printChar(int ch){
  int par[2];par[0]=CHFILEpar(TARGET);par[1]=ch;Aputchar(par);
}
static void printRepr(int item){
  int par[3];int t;
  par[0]=STACKpar(ITEM);par[1]=item;if(was(par)){
    par[0]=item;if(getItemDef(par)){item=par[1];}
    t=ITEM->offset[item-ITEM_type];
    if(t==Iconstant||t==IpointerConstant){;}else{printChar('S');}
    printInt(ITEM->offset[item-ITEM_repr]);}
  else{printPtr(item);}
}
#include <limits.h>
static void printInt(int n){
  if(n==INT_MIN){printChar('-');n=-1-n;printInt1(n,'1');}
  else if(n<0){printChar('-');printInt1(-n,'0');}
  else{printInt1(n,'0');}
}
static void printInt1(int n,int c){
  int q,r;
  r=n%10,q=(n-r)/10;if(q==0){;}else{printInt1(q,'0');}
  printChar(r+c);
}
static void printStr(int T,int ptr){
  int par[3];
  par[0]=CHFILEpar(TARGET);par[1]=T;par[2]=ptr;Aputstring(par);
}
static void printPtr(int p){
  int par[3];nxt:
  par[0]=STACKpar(ITEM);par[1]=p;if(was(par)){p=ITEM->offset[p-ITEM_tag];goto nxt;}
  par[0]=STACKpar(LEXT);par[1]=p;if(was(par)){par[0]=p;getTagImage(par);p=par[1];
    printStr(STACKpar(LEXT),p);return;}
  par[0]=STACKpar(MESSAGE);par[1]=p;if(was(par)){printStr(STACKpar(MESSAGE),p);return;}
//DEBUG
  par[0]=STACKpar(BOLD);par[1]=p;if(was(par)){printStr(STACKpar(BOLD),p);return;}  
  printf("[printPtr: p=%d]",p);
}
#define SHIFT  n--;a++
static void T(char *fmt,int n,int *a){/* printf */
  nxt:if(*fmt==0){;}
  else if(*fmt!='%'){printChar(*fmt);fmt++;goto nxt;}
  else {fmt++;if(*fmt==0){printChar('%');}
    else if(*fmt=='r'){if(n>0){printRepr(*a);SHIFT;}else{printChar('?');}fmt++;goto nxt;}
    else if(*fmt=='n'){printChar('\n');fmt++;goto nxt;}
    else if(*fmt=='d'){if(n>0){printInt(*a);SHIFT;}else{printChar('?');}fmt++;goto nxt;}
    else if(*fmt=='p'){if(n>0){printPtr(*a);SHIFT;}else{printChar('?');}fmt++;goto nxt;}
    else{printChar(*fmt);fmt++;goto nxt;}}
  if(n>0){printChar('[');printChar('.');printChar('.');printChar('.');printChar(']');}
}
/* ------------------------------------------------ */
void targetPrelude(void){
  int par[4];int ptr,t;
  T("/* ALEPH TARGET FILE%n * modules: ",0,par);
  ptr=ITEM->alwb;nxt:if(ptr>ITEM->aupb){;}
  else{t=ITEM->offset[ptr-ITEM_type];
    if(t==Dtitle){par[0]=ITEM->offset[ptr-ITEM_tag];T(" *%p,",1,par);}
    else if(t==Dmodule){par[0]=ITEM->offset[ptr-ITEM_tag];
       T(" %p",1,par);}
    ptr+=ITEM_CALIBRE;goto nxt;}
  T("%n */%n#include \"A_lice.h\"%n%n",0,par);
}
static void isWaitfor(int *a){/* >ptr + >w> */
  int par[2];
  if(a[1]){return;}
  par[0]=a[0];if(getItemDef(par)){a[0]=par[1];
    par[0]=a[0];par[1]=texternal;if(isItemFlag(par)){
      if(ITEM->offset[a[0]-ITEM_tag]==extWaitfor){a[1]=1;}}}
}
void targetMain(void){
  int par[4];int ptr,head,t,w;
  ptr=ITEM->alwb;head=0;w=0;nxt:if(ptr>ITEM->aupb){;}
  else{t=ITEM->offset[ptr-ITEM_type];
   if(t==Dmodule){head=ITEM->offset[ptr-ITEM_tag];}
   else if(t==Dtitle){head=0;}
   else if(t==Irule){par[0]=ptr;par[1]=w;isWaitfor(par);w=par[1];
     if(head==0){;}
     else if(Sroot!=ITEM->offset[ptr-ITEM_tag]){;}
     else{par[0]=ptr;par[1]=head;T("a_MROOT(%r,\"%p\")%n",2,par);}}
   ptr+=ITEM_CALIBRE;goto nxt;}
  T("/* ********* */%n",0,par);
  if(w){T("a_waitfor(int ID,int ptr){%n /* ... */%n}%n",0,par); }
  T("void a_ROOT(void){%n",0,par);
  ptr=ITEM->alwb;head=0;nxt2:if(ptr>ITEM->aupb){;}
  else{t=ITEM->offset[ptr-ITEM_type];
    if(t==Dmodule){head=ITEM->offset[ptr-ITEM_tag];}
    else if(t==Dtitle){head=0;}
    else if(t==Irule){if(head==0){;}
      else if(Sroot!=ITEM->offset[ptr-ITEM_tag]){;}
      else{par[0]=ptr;par[1]=head;T(" R%r(0,0); /* %p */%n",2,par);}}
    ptr+=ITEM_CALIBRE;goto nxt2;}
  ptr=ITEM->alwb;head=0;nxt3:if(ptr>ITEM->aupb){;}
  else{t=ITEM->offset[ptr-ITEM_type];
    if(t==Dmodule){head=0;}
    else if(t==Dtitle){head=ITEM->offset[ptr-ITEM_tag];}
    else if(t==Irule){if(head==0){;}
      else if(Sroot!=ITEM->offset[ptr-ITEM_tag]){;}
      else{par[0]=ptr;par[1]=head;T(" %r(); /* %p */%n",2,par);}}
   ptr+=ITEM_CALIBRE;goto nxt3;}
  T("}%n",0,par);
}
/* ************************************************ */
static void ruleTyper(int item){
  int par[2];
  par[0]=item;par[1]=rcanfail;
  if(isItemFlag(par)){par[0]=item;T("int %r(",1,par);}
  else{par[0]=item;T("void %r(",1,par);}
}
static void argSep(int *a){ /* >sep> */
  if(a[0]==0){a[0]=1;}else{printChar(',');}
}
static void outArgs(int *a){/* >out + >sep> */
  int par[1];
  if(a[0]==0){;}
  else{par[0]=a[1];argSep(par);a[1]=par[0];par[0]=a[0];T("int A[%d]",1,par);}
}
static void ruleArgs(int item){
  int par[3];int n,cnt,type,out,sep;
  par[0]=item;getNumberOfFormals(par);n=par[1];cnt=out=sep=0;nxt:
  if(cnt<n){par[0]=item;par[1]=cnt;getFormal(par);type=par[2];cnt++;
    if(type==IformalOut||type==IformalInout){out++;goto nxt;}
    else if(type==IformalRepeat){par[0]=out;par[1]=sep;outArgs(par);sep=par[1];
       par[0]=sep;argSep(par);sep=par[0];T("int C,int V[])",0,par);}
    else{par[0]=sep;argSep(par);sep=par[0];par[0]=cnt;T("int F%d",1,par);goto nxt;}}
  else{par[0]=out;par[1]=sep;outArgs(par);sep=par[1];printChar(')');}
}
/* ------------------------------------------------ */
static void varDeclaration(int item){
  int par[3];
  par[0]=item;par[1]=ITEM->offset[item-ITEM_adm];par[2]=ITEM->offset[item-ITEM_tag];
  T("int %r=%d; /* %p */%n",3,par);
}
static void blockDeclaration(int item,int prev,int sf){
  int par[3];
  par[0]=item;T("#define %r (",1,par);
  if(prev==0){T("0",0,par);}else {par[0]=prev;par[1]=sf;T("%r+%p",2,par);}
  par[0]=ITEM->offset[item-ITEM_tag];T(") /* %p */%n",1,par);
}
static void ruleDeclaration(int item){
  int par[2];
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){;}
  else{ ruleTyper(item);ruleArgs(item);par[0]=ITEM->offset[item-ITEM_tag];
    T("; /* %p */%n",1,par);}
}

void dataDeclaration(void){
  int par[3];int ptr,prev,sf,t;
  prev=sf=0;ptr=ITEM->alwb;nxt:if(ptr>ITEM->aupb){;}
  else{par[0]=ptr;if(getItemDef(par)&& ptr!=par[1]){ptr+=ITEM_CALIBRE;goto nxt;}
   t=ITEM->offset[ptr-ITEM_type];
   if(t==Ivariable||t==IstaticVar){varDeclaration(ptr);}
   else if(t==Istack||t==Itable||t==IstaticStack){
     blockDeclaration(ptr,prev,sf);prev=ptr;sf=sizeof_list;}
   else if(t==Icharfile){blockDeclaration(ptr,prev,sf);prev=ptr;sf=sizeof_chfile;}
   else if(t==Idatafile){blockDeclaration(ptr,prev,sf);prev=ptr,sf=sizeof_dfile;}
   else if(t==Irule){ruleDeclaration(ptr);}
   ptr+=ITEM_CALIBRE;goto nxt;}
  if(prev==0){par[0]=block_total;T("#define %p 0%n",1,par);}
  else{par[0]=block_total;par[1]=prev;par[2]=sf;T("#define %p (%r+%p)%n",3,par);}
  par[0]=block_total;T("int a_DATABLOCK[%p];%n"
    "int FILL[]={%n",1,par);
}
/* ------------------------------------------------ */
static void pushBUFFER(int x){
  int par[3];par[0]=STACKpar(BUFFER);par[1]=1;par[2]=x;expandstack(par);
}
static void constItem(int *a){/* v> */
  int par[3];int t;
  par[0]=Tconst;if(RR(par)){a[0]=par[1];return;}
  par[0]=Titem;must(par);a[0]=par[1];
  par[0]=a[0];if(getItemDef(par)){a[0]=par[1];}
  t=ITEM->offset[a[0]-ITEM_type];
  if(t==Iconstant||t==IpointerConstant){a[0]=ITEM->offset[a[0]-ITEM_repr];}
  else{printf("constantItem, wrong type=%d\n",t);exit(23);}
}
static void fillItem(int *a){/* size> */
  int par[3];par[0]=Dopen;if(R(par)){a[0]=0;nxt:
    par[0]=Dclose;if(R(par)){;}
    else{a[0]++;constItem(par);pushBUFFER(par[0]);goto nxt;}}
  else{a[0]=1;constItem(par);pushBUFFER(par[0]);}
}
static int fillRepeater(int *a){/* rep> */
  int par[2];par[0]=Dstar;if(R(par)){constItem(a);return 1;}
  return 0;
}
static void flushBuffer(int size,int last,int ptr){
  int par[3];
  ptr++;if(size==0){;}else{par[0]=size;T("%d,",1,par);}nxt1:
  if(size==0){;}else{par[0]=BUFFER->offset[ptr];T("%d,",1,par);
    ptr++;size--;goto nxt1;}
  if(last==0){;}else{par[0]=last;T("%d,",1,par);}nxt2:
  if(last==0){;}else{par[0]=BUFFER->offset[ptr];T("%d,",1,par);
   ptr++;last--;goto nxt2;}
}
static void skipFillInitializer(void){
  int par[3];
  nxt:par[0]=Dcolon;if(R(par)){par[0]=Titem;must(par);goto nxt;}
}
static void fillEntries(void){
  int par[3];int list,obuff,size,last,rep;
  par[0]=Titem;must(par);list=par[1];par[0]=Tconst;must(par);
  par[0]=list;par[1]=ITEM->offset[list-ITEM_tag];T("%r, /* %p */%n",2,par);
  obuff=BUFFER->aupb;size=0;nxt:
  par[0]=Dpoint;if(R(par)){;}
  else{fillItem(par);last=par[0];if(fillRepeater(par)){
    rep=par[1];flushBuffer(size,last,obuff);par[0]=rep;
    T("-%d,%n",1,par);par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
    size=0;}
    else{size+=last;}
    skipFillInitializer();goto nxt;}
  flushBuffer(size,0,obuff);par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
  T("0,%n",0,par);
}
static void skipEntry(void){
  int par[3];
  nxt:par[0]=Dpoint;if(R(par)){;}else{nextSymbol();goto nxt;}
}
void dataSectionIII(void){
  int par[3];
  nxt:par[0]=Dexpression;if(R(par)){skipEntry();goto nxt;}
  par[0]=Dlist;if(R(par)){skipEntry();goto nxt;}
  par[0]=Dfile;if(R(par)){skipEntry();goto nxt;}
  par[0]=Dfill;if(R(par)){fillEntries();goto nxt;}
}
/* ------------------------------------------------ */
static void listInitialization(int kind,int item){
  int par[6];int cal,lb,up,fill;
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){par[0]=item;
    getCalibre(par);cal=par[1];par[0]=kind;par[1]=item;par[2]=cal;
    par[3]=ITEM->offset[item-ITEM_tag];
    T(" setup_external_list(%d,%r,%d,\"%p\");%n",4,par);}
  else{ par[0]=item;getCalibre(par);cal=par[1];getVupb(par);up=par[1];
    getVlwb(par);lb=par[1];getFill(par);fill=par[1];par[0]=kind,
    par[1]=item;par[2]=cal;par[3]=lb;par[4]=up;par[5]=fill;
    T(" setup_list(%d,%r,%d,%d,%d,%d);%n",6,par);}
}
static void charfileInitialization(int item){
  int par[4];int dir,id,ptr;
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){par[0]=item;
    par[1]=ITEM->offset[item-ITEM_tag];
    T(" setup_external_charfile(%r,\"%p\");%n",2,par);}
  else{par[0]=item;par[1]=toutfile;if(isItemFlag(par)){dir=2;}else{dir=0;}
    par[1]=tinfile;if(isItemFlag(par)){dir++;}
    par[0]=item;getFileData(par);id=par[1];ptr=par[2];
    par[0]=item;par[1]=dir;par[2]=id;par[3]=ptr;
    T(" setup_charfile(%r,%d,%r,%r);%n",4,par);}
}
static void countFileArea(int *a){/* >p + cnt> */
  int par[3];
  a[1]=0;nxt:if(a[0]==0){return;}
  a[1]++;par[0]=a[0];getFileLink(par);a[0]=par[0];goto nxt;
}
static void datafileInitialization(int item){
  int par[5];int dir,id,ptr,link,cnt;
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){par[0]=item;
    par[1]=ITEM->offset[item-ITEM_tag];
    T(" setup_external_dfile(%r,\"%p\");%n",2,par);}
  else{par[0]=item;par[1]=toutfile;if(isItemFlag(par)){dir=2;}else{dir=0;}
    par[1]=tinfile;if(isItemFlag(par)){dir++;}
    par[0]=item;getFileData(par);id=par[1];ptr=par[2];link=par[3];
    par[0]=link;countFileArea(par);cnt=par[1];
    par[0]=item;par[1]=dir;par[2]=id;par[3]=ptr;par[4]=cnt;
    T(" setup_dfile(%r,%d,%r,%r,%d);%n",5,par);
    nxt:if(link==0){;}
    else{par[0]=link;getFileLink(par);link=par[0];cnt=par[1];
     id=par[2];par[0]=item;par[1]=id;par[2]=cnt;
     T("   add_filearea(%r,%r,%d);%n",3,par);goto nxt;}}
}

void dataInitialization(void){
  int par[4];int ptr,t;
  T("-1};%nvoid data_setup(void){%n",0,par);
  ptr=ITEM->alwb;nxt:if(ptr>ITEM->aupb){;}
  else{par[0]=ptr;if(getItemDef(par)&& ptr!=par[1]){ptr+=ITEM_CALIBRE;goto nxt;}
    t=ITEM->offset[ptr-ITEM_type];
    if(t==Itable){listInitialization(0,ptr);}
    else if(t==Istack||t==IstaticStack){listInitialization(1,ptr);}
    ptr+=ITEM_CALIBRE;goto nxt;}
  ptr=ITEM->alwb;nxt2:if(ptr>ITEM->aupb){;}
  else{par[0]=ptr;if(getItemDef(par)&& ptr!=par[1]){ptr+=ITEM_CALIBRE;goto nxt2;}
    t=ITEM->offset[ptr-ITEM_type];
    if(t==Icharfile){charfileInitialization(ptr);}
    else if(t==Idatafile){datafileInitialization(ptr);}
    ptr+=ITEM_CALIBRE;goto nxt2;}
  T(" list_fill(FILL);%n}%n",0,par);
}
/* ------------------------------------------------ */

void initialize_target(void){
  init_MSG();
  init_LEXT();
}

/* EOF */
