/* target.ale */
#include "stddata.h"
#include "target.h"
#include "error.h"
#include "item.h"
#include "lexical.h"
#include "rule.h"

static int target_file_name,cannot_open_target;
static int sizeof_list,sizeof_chfile,sizeof_dfile,block_total;
static int Tcalibre,Tlwb,Tupb,Tvlwb,Tvupb,r1,r2;
static int stdlab0,stdlabM1,stdlabM2,stdgoto;

#define addMSG(x,y)	 add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_MSG(void){
  addMSG("aleph.cc",target_file_name);
  addMSG("cannot create target file %p",cannot_open_target);
  addMSG("sizeof_LIST",sizeof_list);
  addMSG("sizeof_CHFILE",sizeof_chfile);
  addMSG("sizeof_DFILE",sizeof_dfile);
  addMSG("BLOCK_TOTAL",block_total);
  addMSG("calibre",Tcalibre);
  addMSG("alwb",Tlwb);
  addMSG("aupb",Tupb);
  addMSG("vlwb",Tvlwb);
  addMSG("vupb",Tvupb);
  addMSG("a_r1",r1);
  addMSG("a_r2",r2);
  addMSG("return;",stdlab0);
  addMSG("return 1;",stdlabM1);
  addMSG("return 0;",stdlabM2);
  addMSG("goto ",stdgoto);
}

static int extWaitfor,Sroot;

#define addLEXT(x,y)	add_new_string(x,LEXT);expandstack(par);y=LEXT->aupb
static void init_LEXT(void){
  int par[4];
  par[0]=STACKpar(LEXT);par[1]=2;par[2]=par[3]=0;
  addLEXT("@root",Sroot);
  addLEXT("a_waitfor",extWaitfor);
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
static int thisRule=0;
static int nextNodeIdx=0,calledRule=0;


static void printInt(int),printInt1(int n,int c),printPtr(int);
static void printChar(int ch){
  int par[2];par[0]=CHFILEpar(TARGET);par[1]=ch;Aputchar(par);
}
#include <limits.h>
static void printInt(int n){
  if(n==INT_MIN){
//     printChar('-');n=-1-n;printInt1(n,'1');}
     printChar('(');printChar('-');printInt(INT_MAX);printChar('-');printChar('1');printChar(')');}
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
static void printPrefix(void){printChar('a');printChar('_');}
static void printLabelPrefix(void){printPrefix();printChar('G');}
static void localArgument(int cnt){
  printPrefix();printChar('L');printInt(cnt);}
static void printIntIndex(int c,int idx){
  printPrefix();printChar(c);printChar('[');printInt(idx);printChar(']');}
static void formalArgument(int cnt){
  int par[3];int i,type,out;
  i=out=0;nxt:par[0]=thisRule;par[1]=i;getFormal(par);type=par[2];i++;
  if(type==IformalOut||type==IformalInout){
    if(i==cnt){printIntIndex('A',out);}else{out++;goto nxt;}}
  else if(type==IformalRepeat){i=cnt-i-1;par[0]=i;
       if(i<0){printPrefix();printChar('C');}else{printIntIndex('V',i);}}
  else if(i==cnt){printPrefix();printChar('F');printInt(cnt);}
  else{goto nxt;}
}
static int isPidginAlt(int item);
static void printPidginRepr(int item){
  int par[4];int ptr,x,y;
  if(isPidginAlt(item)){printChar('_');
    par[0]=ITEM->offset[item-ITEM_tag];getTagImage(par);ptr=par[1];y=1;
    nxt:par[0]=STACKpar(LEXT);par[1]=ptr;par[2]=y;
    if(stringelem(par)){x=par[3];printChar(x);y++;goto nxt;}}
  else{printPtr(item);}
}
static void printExternalRepr(int item){
  int t;
  t=ITEM->offset[item-ITEM_type];
  if(t==Iconstant||t==Ivariable){printPtr(item);}
  else if(t==Irule){if(isPidginRule(item)){printPidginRepr(item);}
                    else{printPtr(item);}}
  else{printPrefix();printInt(ITEM->offset[item-ITEM_repr]);}
} 
static void printRepr(int item){
  int par[3];int t;
  par[0]=STACKpar(ITEM);par[1]=item;if(was(par)){
    par[0]=item;if(getItemDef(par)){item=par[1];}
    par[0]=item;par[1]=texternal;if(isItemFlag(par)){printExternalRepr(item);}
    else{t=ITEM->offset[item-ITEM_type];
     if(t==Iconstant||t==IpointerConstant){;}else{printPrefix();}
     printInt(ITEM->offset[item-ITEM_repr]);}}
  else{printPtr(item);}
}
static void printLocalLabel(int label){
  printLabelPrefix();printInt(label);
}
static void printGoto(int label){
  int par[2];again:
  if(label==0){par[0]=calledRule;par[1]=rexit;
      if(isItemFlag(par)){label=-1;goto again;}
      else{printf("printGoto zero label\n");exit(8);}}
  else if(label==-1){par[0]=thisRule;par[1]=rcanfail;
      if(isItemFlag(par)){printPtr(stdlabM1);}else{printPtr(stdlab0);}}
  else if(label==-2){printPtr(stdlabM2);}
  else{printPtr(stdgoto);printLocalLabel(label);printChar(';');}
}
static void printGOTO(int label){
  if(label==nextNodeIdx){;}
  else{printGoto(label);}
}
static void printBUFFER(int p){
  int t=BUFFER->offset[p];
  if(t==Titem){p++;printRepr(BUFFER->offset[p]);return;}
  if(t==Tconst){p++;printInt(BUFFER->offset[p]);return;}
  if(t==Tlocal){p++;localArgument(BUFFER->offset[p]);return;}
  if(t==Tformal){p++;formalArgument(BUFFER->offset[p]); return;}
  printChar('?');printInt(BUFFER->offset[p]);printf("print BUFFER %d, ???\n",p);exit(88);
}
static void printPtr(int p){
  int par[3];nxt:
  par[0]=STACKpar(ITEM);par[1]=p;if(was(par)){p=ITEM->offset[p-ITEM_tag];goto nxt;}
  par[0]=STACKpar(LEXT);par[1]=p;if(was(par)){par[0]=p;getTagImage(par);p=par[1];
    printStr(STACKpar(LEXT),p);return;}
  par[0]=STACKpar(MESSAGE);par[1]=p;if(was(par)){printStr(STACKpar(MESSAGE),p);return;}
  par[0]=STACKpar(BUFFER);par[1]=p;if(was(par)){printBUFFER(p);return;}
//DEBUG
  par[0]=STACKpar(BOLD);par[1]=p;if(was(par)){printStr(STACKpar(BOLD),p);return;}  
  printf("[printPtr: p=%d]",p);exit(87);
}

#define SHIFT  n--;a++
static void T(char *fmt,int n,int *a){/* printf */
  nxt:if(*fmt==0){;}
  else if(*fmt!='%'){printChar(*fmt);fmt++;goto nxt;}
  else {fmt++;if(*fmt==0){printChar('%');}
    else if(*fmt=='r'){if(n>0){printRepr(*a);SHIFT;}else{printChar('?');exit(28);}fmt++;goto nxt;}
    else if(*fmt=='g'){if(n>0){printGoto(*a);SHIFT;}else{printChar('?');exit(28);}fmt++;goto nxt;}
    else if(*fmt=='G'){if(n>0){printGOTO(*a);SHIFT;}else{printChar('?');exit(28);}fmt++;goto nxt;}
    else if(*fmt=='n'){printChar('\n');fmt++;goto nxt;}
    else if(*fmt=='d'){if(n>0){printInt(*a);SHIFT;}else{printChar('?');exit(28);}fmt++;goto nxt;}
    else if(*fmt=='p'){if(n>0){printPtr(*a);SHIFT;}else{printChar('?');exit(28);}fmt++;goto nxt;}
    else{printChar(*fmt);fmt++;goto nxt;}}
  if(n>0){printChar('[');printChar('.');printChar('.');printChar('.');printChar(']');}
}
/* ------------------------------------------------ */
void targetPrelude(void){
  int par[4];int ptr,t;
  T("/* ALEPH TARGET FILE%n * modules: ",0,par);
  ptr=ITEM->alwb;nxt:if(ptr>ITEM->aupb){;}
  else{t=ITEM->offset[ptr-ITEM_type];
    if(t==Dtitle){par[0]=ITEM->offset[ptr-ITEM_tag];T(" *%p",1,par);}
    else if(t==Dmodule){par[0]=ITEM->offset[ptr-ITEM_tag];
       T(" %p",1,par);}
    ptr+=ITEM_CALIBRE;goto nxt;}
  T("%n */%n#include \"A_lice.h\"%n%n",0,par);
}
/*===========================================*/
static void isWaitfor(int *a){/* >ptr + >w> */
  int par[2];
  if(a[1]){return;}
  par[0]=a[0];if(getItemDef(par)){a[0]=par[1];
    par[0]=a[0];par[1]=texternal;if(isItemFlag(par)){
      if(ITEM->offset[a[0]-ITEM_tag]==extWaitfor){a[1]=1;}}}
}
void procWaitfor(void){
  int par[2];int ptr,head,t;
  par[0]=0;T("int a_waitfor(int a_F1,int a_F2){%n",0,par);
  ptr=ITEM->alwb;head=0;nxt:if(ptr>ITEM->aupb){;}
  else{t=ITEM->offset[ptr-ITEM_type];
   if(t==Dmodule){head=ITEM->offset[ptr-ITEM_tag];}
   else if(t==Dtitle){head=0;}
   else if(t==Irule){if(head==0){;}
     else if(Sroot!=ITEM->offset[ptr-ITEM_tag]){;}
     else{par[0]=ptr;T(" if(a_R%r(a_F1,a_F2)){return 1;}%n",1,par);}}
   ptr+=ITEM_CALIBRE;goto nxt;}
  T(" return 0;%n}%n",0,par);
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
  if(w){procWaitfor(); }
  T("void a_ROOT(void){%n a_data_setup();%n",0,par);
  ptr=ITEM->alwb;head=0;nxt2:if(ptr>ITEM->aupb){;}
  else{t=ITEM->offset[ptr-ITEM_type];
    if(t==Dmodule){head=ITEM->offset[ptr-ITEM_tag];}
    else if(t==Dtitle){head=0;}
    else if(t==Irule){if(head==0){;}
      else if(Sroot!=ITEM->offset[ptr-ITEM_tag]){;}
      else{par[0]=ptr;par[1]=head;T(" a_R%r(0,0); /* %p */%n",2,par);}}
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
  if(isItemFlag(par)){par[0]=item;T("static int %r(",1,par);}
  else{par[0]=item;T("static void %r(",1,par);}
}
static void externalRuleTyper(int item){
  int par[2];
  par[0]=item;par[1]=rcanfail;
  if(isItemFlag(par)){par[0]=ITEM->offset[item-ITEM_tag];
    T("extern int %p(",1,par);}
  else{par[0]=ITEM->offset[item-ITEM_tag];T("extern void %p(",1,par);}
}
static void argSep(int *a){ /* >sep> */
  if(a[0]==0){a[0]=1;}else{printChar(',');}
}
static void outArgs(int *a){/* >out + >sep> */
  int par[1];
  if(a[0]==0){;}
  else{par[0]=a[1];argSep(par);a[1]=par[0];par[0]=a[0];T("int a_A[%d]",1,par);}
}
static void ruleArgs(int item){
  int par[3];int n,cnt,type,out,sep;
  par[0]=item;getNumberOfFormals(par);n=par[1];cnt=out=sep=0;nxt:
  if(cnt<n){par[0]=item;par[1]=cnt;getFormal(par);type=par[2];cnt++;
    if(type==IformalOut||type==IformalInout){out++;goto nxt;}
    else if(type==IformalRepeat){par[0]=out;par[1]=sep;outArgs(par);sep=par[1];
       par[0]=sep;argSep(par);sep=par[0];T("int a_C,int *a_V)",0,par);}
    else{par[0]=sep;argSep(par);sep=par[0];par[0]=cnt;T("int a_F%d",1,par);goto nxt;}}
  else{if(n==0){T("void",0,par);}else{par[0]=out;par[1]=sep;outArgs(par);sep=par[1];}
    printChar(')');}
}
int isPidginRule(int item){
  int par[4];int x;
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){
    par[0]=ITEM->offset[item-ITEM_tag];getTagImage(par);x=par[1];
    par[0]=STACKpar(LEXT);par[1]=x;par[2]=0;if(stringelem(par)){
      x=par[3];
      if(('a'<=x&&x<='z')||('A'<=x&&x<='Z')){return 0;}else{return 1;}}}
  return 0;
}
static int isPidginAlt(int item){
  int par[4];int x;
  par[0]=ITEM->offset[item-ITEM_tag];getTagImage(par);x=par[1];
  par[0]=STACKpar(LEXT);par[1]=x;par[2]=0;if(stringelem(par)){
    if(par[3]=='@')return 1;}
  return 0;
}
/* ------------------------------------------------ */
static void showFormalsAsComment(int item){
  int par[3];int n,cnt,type;
  par[0]=item;getNumberOfFormals(par);n=par[1];cnt=0;nxt:
  if(cnt>=n){;}
  else{par[0]=item;par[1]=cnt;getFormal(par);type=par[2];cnt++;
    if(type==IformalIn){T("+>a",0,par);}
    else if(type==IformalOut){T("+a>",0,par);}
    else if(type==IformalInout){T("+>a>",0,par);}
    else if(type==IformalTable){T("+t[]",0,par);}
    else if(type==IformalStack){T("+[]st[]",0,par);}
    else if(type==IformalFile){T("+\"\"f",0,par);}
    else if(type==IformalRepeat){T("+*",0,par);}
    else{printf("unknown formal type %d\n",type);exit(33);}
    goto nxt;}
}
static void declareLocals(int minloc,int maxloc,int locptr){
  int par[2];
  nxt:if(minloc==0){return;}
  if(minloc>maxloc){;}
  else if(BUFFER->offset[locptr]==0){
//printf("local %d missing\n",minloc);
     minloc++;locptr++;goto nxt;}
  else{par[0]=minloc;T("int a_L%d;",1,par);minloc++;locptr++;goto nxt;}
}
static void declareCallargs(int item,int C1,int C2,int C3){
  int par[3];int cnt;
  if(C2==0){;}else{par[0]=C2;T("int a_P[%d];",1,par);}
  if(C3==0){;}else{par[0]=item;getRepeatCount(par);cnt=par[1];
    par[0]=C3;par[1]=cnt;T("int *a_D=alloca(sizeof(int)*(%d+%d*a_C));",2,par);}
  printChar('\n');
//  par[0]=C1;par[1]=C2;par[2]=C3;T("/* %d,%d,%d */%n",3,par);
}
/* trace and profiling */
static void addRuleNameAsStatic(void){
  int par[2];
  par[0]=thisRule;par[1]=rspecial;if(isItemFlag(par)){
    par[0]=thisRule;T(" static char *a_rulename=\"%p\";%n",1,par);}  
}
static void addProfiling(void){
  int par[2];
  par[0]=thisRule;par[1]=rcount;if(isItemFlag(par)){
   T(" static a_PROFILE a_profile={0ul,NULL,NULL};%n"
     " a_PROFILING(a_profile,a_rulename);%n",0,par);}
}
static void addTracing(void){
  int par[2]; int n,cnt;
  par[0]=thisRule;par[1]=rtrace;if(isItemFlag(par)){
    par[0]=thisRule;getNumberOfFormals(par);n=par[1];cnt=0;par[0]=n;
    T(" a_trace_rule(a_rulename,%d",1,par);nxt:
    if(cnt<n){printChar(',');cnt++;formalArgument(cnt);goto nxt;}
    T(");%n",0,par);}
}
void ruleDeclarationHead(int *a){/* item+C1+C2+C3+minloc+maxloc+locptr */
  int par[4];
  thisRule=a[0];
  ruleTyper(a[0]);ruleArgs(a[0]);par[0]=ITEM->offset[a[0]-ITEM_tag];
  T("{ /* %p",1,par);showFormalsAsComment(a[0]);
  T(" */%n",0,par);declareLocals(a[4],a[5],a[6]+a[4]);
  declareCallargs(a[0],a[1],a[2],a[3]);
  addRuleNameAsStatic();addProfiling();addTracing();
}  
void ruleDeclarationTail(void){
  int par[2];
  par[0]=thisRule;T("} /* %p */%n",1,par);
}
/* ------------------------------------------------ */
static int externalPlainDeclaration(int item){
  int par[2];
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){
    par[0]=ITEM->offset[item-ITEM_tag];T("extern int %p;%n",1,par);
    return 1;}
  else{ return 0;}
}

static void varDeclaration(int item){
  int par[3];
  if(externalPlainDeclaration(item)){;}
  else{par[0]=item;par[1]=ITEM->offset[item-ITEM_adm];par[2]=ITEM->offset[item-ITEM_tag];
    T("static int %r=%d; /* %p */%n",3,par);}
}
static void blockDeclaration(int item,int prev,int sf){
  int par[3];
  par[0]=item;T("#define %r (",1,par);
  if(prev==0){T("0",0,par);}else {par[0]=prev;par[1]=sf;T("%r+%p",2,par);}
  par[0]=ITEM->offset[item-ITEM_tag];T(") /* %p */%n",1,par);
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){
    par[0]=ITEM->offset[item-ITEM_tag];
    T("extern void %p(int,int);%n",1,par);}
}
static void rulePrototype(int item){
  int par[2];
  if(isPidginRule(item)){return;}
  par[0]=item;if(isBuiltinRule(par)){return;}
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){
     externalRuleTyper(item);ruleArgs(item);T(";%n",0,par);}
  else{ ruleTyper(item);ruleArgs(item);par[0]=ITEM->offset[item-ITEM_tag];
    T("; /* %p */%n",1,par);}
}
void dataDeclaration(void){
  int par[3];int ptr,prev,sf,t;
  prev=sf=0;ptr=ITEM->alwb;nxt:if(ptr>ITEM->aupb){;}
  else{par[0]=ptr;if(getItemDef(par)&& ptr!=par[1]){ptr+=ITEM_CALIBRE;goto nxt;}
   t=ITEM->offset[ptr-ITEM_type];
   if(t==Iconstant){externalPlainDeclaration(ptr);}
   else if(t==Ivariable||t==IstaticVar){varDeclaration(ptr);}
   else if(t==Istack||t==Itable||t==IstaticStack){
     blockDeclaration(ptr,prev,sf);prev=ptr;sf=sizeof_list;}
   else if(t==Icharfile){blockDeclaration(ptr,prev,sf);prev=ptr;sf=sizeof_chfile;}
   else if(t==Idatafile){blockDeclaration(ptr,prev,sf);prev=ptr,sf=sizeof_dfile;}
   else if(t==Irule){rulePrototype(ptr);}
   ptr+=ITEM_CALIBRE;goto nxt;}
  if(prev==0){par[0]=block_total;T("#define %p 0%n",1,par);}
  else{par[0]=block_total;par[1]=prev;par[2]=sf;T("#define %p (%r+%p)%n",3,par);}
  par[0]=block_total;T("int a_DATABLOCK[%p];%n",1,par);
}
/* ------------------------------------------------ */
static void pushBUFFER(int x){
  int par[3];par[0]=STACKpar(BUFFER);par[1]=1;par[2]=x;expandstack(par);
}
void fillTableHead(void){
  int par[1];T("static int a_FILL[]={ /* fill table */%n",0,par);
}
void fillTableTail(void){
  int par[1];T("-1}; /* fill table */%n",0,par);
}
static void constItem(int *a){/* v> */
  int par[3];int t;
  par[0]=Tconst;if(RR(par)){a[0]=par[1];return;}
  par[0]=Titem;must(par);a[0]=par[1];
  par[0]=a[0];if(getItemDef(par)){a[0]=par[1];}
  t=ITEM->offset[a[0]-ITEM_type];
  if(t==Iconstant||t==IpointerConstant){a[0]=ITEM->offset[a[0]-ITEM_repr];}
  else{printf("constItem, wrong type=%d\n",t);exit(23);}
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
    rep=par[0];flushBuffer(size,last,obuff);par[0]=rep;
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
void dataSectionIV(void){
  int par[3];
  nxt:par[0]=Dexpression;if(R(par)){skipEntry();goto nxt;}
  par[0]=Dlist;if(R(par)){skipEntry();goto nxt;}
  par[0]=Dfile;if(R(par)){skipEntry();goto nxt;}
  par[0]=Dfill;if(R(par)){skipEntry();goto nxt;}
  nxt2: par[0]=Drule;if(R(par)){makeRule();goto nxt2;}
  par[0]=Dend;if(R(par)){;}
  else{printf("datasection iv: wrong end of the file\n");exit(99);}
}
/*================================================= */
void Tlabel(int *a){/* >label + >nextidx */
  nextNodeIdx=a[1];if(a[0]==0){;}
  else{printLocalLabel(a[0]);printChar(':');}
}
static void jumpToLabel(int label){
  int par[1];
  if(nextNodeIdx==label){return;}
  par[0]=label;T(" %g%n",1,par);
}
/* classification */
static void TlimitTail(int *a){/* >what + code> */
  if(a[0]==Dcalibre){a[1]=Tcalibre;}
  else if(a[0]==Dlwb){a[1]=Tlwb;}
  else if(a[0]==Dupb){a[1]=Tupb;}
  else if(a[0]==Dvlwb){a[1]=Tvlwb;}
  else if(a[0]==Dvupb){a[1]=Tvupb;}
  else{ printf("TlimitTail: wrong item %d\n",a[0]);exit(8);}
}
static void TaffixInner(int *a);
static void Taffix(int ptr){
  int par[2];int t;
  t=BUFFER->offset[ptr];
  if(t==Dcolon){ptr++;par[0]=ptr;TaffixInner(par);}
  else if(t==Dnoarg){printf("Dnoarg\n");exit(38);}
  else{par[0]=ptr;TaffixInner(par);}
}
static void TaffixInner(int *a){/* >ptr> */
  int par[4];int x,t;
  t=BUFFER->offset[a[0]];
  if(t==Tformal||t==Tlocal||t==Titem||t==Tconst){
    par[0]=a[0];T("%p",1,par);a[0]+=2;}
  else if(t==Dsub){a[0]++;par[0]=a[0];T("to_LIST(%p)->offset[",1,par);
     a[0]++;a[0]++;par[0]=a[0];TaffixInner(par);a[0]=par[0];
     a[0]++;x=BUFFER->offset[a[0]]-1;a[0]++;if(x==0){T("]",0,par);}else{par[0]=x;
       T("-%d]",1,par);}}
  else{par[0]=BUFFER->offset[a[0]];TlimitTail(par);x=par[1];a[0]++;
    par[0]=a[0];par[1]=x;T("to_LIST(%p)->%p",2,par);a[0]++;a[0]++;}
}
/* ----------------------------------------- */
static void genShiftaffix(int fnext,int tnext){
  int par[3];int w;
  par[0]=thisRule;getRepeatCount(par);w=par[1];
  if(fnext==nextNodeIdx||fnext==tnext||tnext!=nextNodeIdx){
    if(fnext==tnext){tnext=nextNodeIdx;}
    par[0]=w;par[1]=tnext;par[2]=fnext;
    T("if(a_C>1){a_C--;a_V+=%d;%G} %G%n",3,par);}
  else{par[0]=fnext;par[1]=w;
    T("if(a_C<=1){%g} a_C--;a_V+=%d;%n",2,par);}
}
static void genGetaffixno(int n,int ptr,int tnext){
  int par[3];
  if(n!=2){printf("get repeat blockno wrong n=%d\n",n);exit(77);}
  if(BUFFER->offset[ptr]==Dnoarg||BUFFER->offset[ptr]==Dcolon){;}
  else{Taffix(ptr);par[0]=tnext;T("=a_C;%G%n",1,par);}
}
static void nextAffix(int *a){ /* >ptr> */
  nxt:if(BUFFER->offset[a[0]]==Dplus){a[0]++;}
  else{a[0]++;goto nxt;}
}
static void assignmentSource(int *a){/* >ptr + >star + v> + block> */
  int par[4];int t;                  /*  0       1      2     3    */
  t=BUFFER->offset[a[0]];if(t==Titem||t==Tlocal||t==Tformal||t==Tconst){
    a[2]=a[0];if(a[1]!=0){par[0]=r2;T("{register int %p;",1,par);a[3]=1;}
    else{a[3]=0;}}
  else{a[2]=r1;par[0]=a[2];T("{register int %p=",1,par);Taffix(a[0]);
    if(a[1]){par[0]=r2;T(",%p",1,par);}printChar(';');a[3]=1;}
}
static void genAssignment(int rep,int star,int ptr,int tnext){
  int par[5];int source,v,block,n,cnt;
  source=ptr;par[0]=ptr;nextAffix(par);ptr=par[0];n=0;cnt=1;nxt1:
  if(cnt>=rep){;}else{int t;cnt++;par[0]=ptr;nextAffix(par);ptr=par[0];
    t=BUFFER->offset[ptr];if(t==Dstar||t==Dnoarg||t==Dcolon){;}
    else{n++;}goto nxt1;}
  if(n>1||star!=0){par[0]=source;par[1]=star;assignmentSource(par);
     v=par[2];block=par[3];}
  else{block=v=0;}
  ptr=source;par[0]=ptr;nextAffix(par);ptr=par[0];cnt=1;nxt2:
  if(cnt>=rep){;}else{int t;cnt++;par[0]=ptr;nextAffix(par);ptr=par[0];
    t=BUFFER->offset[ptr];if(t==Dstar||t==Dnoarg||t==Dcolon){;}
    else{Taffix(ptr);if(v==0){printChar('=');Taffix(source);printChar(';');}
    else{par[0]=v;T("=%p;",1,par);}}
    goto nxt2;}
  if(star==0){;}else{par[0]=r2;par[1]=r2;par[2]=r2;par[3]=r2;par[4]=v;
    T("for(%p=0;%p<a_C;%p++)a_V[%p]=%p;",5,par);}     
  if(block==0){;}else{printChar('}');}
  par[0]=tnext;T("%G%n",1,par);
}

/* ---------------------------------------------------------------- */
static void repeatBlockPreload(int ptr,int n,int rep,int out){
  int par[4];int size,dn,cnt,type;
  ptr++;size=BUFFER->offset[ptr];par[0]=ptr;nextAffix(par);ptr=par[0];
  dn=rep;if(size<0){out=0;cnt=-size;}else{cnt=size;}nxt:
  if(cnt==0){;}
  else{par[0]=calledRule;par[1]=dn;getFormal(par);type=par[2];
    if(type==IformalOut){;}
    else if(size>0){par[0]=out;T("a_P[%d]=",1,par);Taffix(ptr);printChar(';');}
    else{par[0]=out;T("a_D[%d]=",1,par);Taffix(ptr);printChar(';');}
    if(dn==n){dn=rep;}else{dn++;}
    cnt--;out++;par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}
  if(size>=0){;}
  else{par[0]=calledRule;getRepeatCount(par);dn=par[1];
   // DEBUG
   par[0]=thisRule;getRepeatCount(par);if(dn!=par[1]){printf("* cnt different: %d, %d\n",dn,par[1]);exit(43);}
   par[0]=out;par[1]=dn;T("memcpy(a_D+%d,a_V,a_C*%d*sizeof(int));",2,par);}
}
static void regularCallPreload(int ptr){
  int par[3];int n,cnt,out,type;
  par[0]=calledRule;getNumberOfFormals(par);n=par[1];cnt=out=0;nxt:
  if(cnt==n){;}
  else{par[0]=calledRule;par[1]=cnt;getFormal(par);type=par[2];cnt++;
    if(type==IformalOut){out++;par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}
    if(type==IformalInout){par[0]=out;T("a_P[%d]=",1,par);out++;Taffix(ptr);
       printChar(';');par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}
    if(type==IformalRepeat){repeatBlockPreload(ptr,n,cnt,out);}
    else{par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}}
}
static void repeatBlockCall(int ptr,int out,int sep){
  int par[3]; int size,dn;
  if(out==0){;}else{par[0]=sep;argSep(par);sep=par[0];T("a_P",0,par);}
  par[0]=calledRule;getRepeatCount(par);dn=par[1];ptr++;size=BUFFER->offset[ptr];
  if(size==0){par[0]=sep;argSep(par);sep=par[0];T("a_C,a_V);",0,par);}
  else if(size<0){par[0]=sep;argSep(par);sep=par[0];
    par[0]=(-size)/dn;par[1]=-size;T("a_C+%d /*%d*/,a_D)",2,par);}
  else{par[0]=sep;argSep(par);sep=par[0];par[0]=size/dn;par[1]=out;par[2]=size;
    T("%d,a_P+%d)",2,par);}
}
static void regularRuleCall(int ptr){
  int par[3];int n,cnt,out,sep,type;
  par[0]=calledRule;getNumberOfFormals(par);n=par[1];
  par[0]=calledRule,T("%r(",1,par);cnt=out=sep=0;nxt:
  if(cnt==n){if(out==0){printChar(')');}
    else{par[0]=sep;argSep(par);sep=par[0];T("a_P)",0,par);}}
  else{par[0]=calledRule;par[1]=cnt;getFormal(par);type=par[2];cnt++;
    if(type==IformalOut||type==IformalInout){out++;par[0]=ptr;
        nextAffix(par);ptr=par[0];goto nxt;}
    else if(type==IformalRepeat){repeatBlockCall(ptr,out,sep);}
    else{par[0]=sep;argSep(par);sep=par[0];Taffix(ptr);par[0]=ptr;
      nextAffix(par);ptr=par[0];goto nxt;}}
}
static int isDummyAffix(int ptr){
  int t=BUFFER->offset[ptr];if(t==Dnoarg||t==Dcolon){return 1;}
  return 0;
}
static void repeatBlockPostload(int ptr,int n,int rep,int out){
  int par[3];int size,dn,cnt,type;
  ptr++;size=BUFFER->offset[ptr];par[0]=ptr;nextAffix(par);ptr=par[0];
  dn=rep;if(size<0){out=0;cnt=-size;}else{cnt=size;}nxt:
  if(cnt==0){;}
  else{par[0]=calledRule;par[1]=dn;getFormal(par);type=par[2];
    if(isDummyAffix(ptr)){;}
    else if(type==IformalOut||type==IformalInout){Taffix(ptr);
      if(size>0){par[0]=out;T("=a_P[%d];",1,par);}
      else{par[0]=out;T("=a_D[%d];",1,par);}}
    if(dn==n){dn=rep;}else{dn++;}
    cnt--;out++;par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}      
  if(size>=0){;}
  else{par[0]=calledRule;getRepeatCount(par);dn=par[1];par[0]=out;
    par[1]=dn;T("memcpy(a_V,a_D+%d,a_C*%d*sizeof(int));",2,par);}
}
static void regularCallPostload(int ptr){
  int par[3];int n,cnt,out,type;
  par[0]=calledRule;getNumberOfFormals(par);n=par[1];cnt=out=0;nxt:
  if(cnt==n){;}
  else{par[0]=calledRule;par[1]=cnt;getFormal(par);type=par[2];
    cnt++;if(type==IformalOut||type==IformalInout){
      if(isDummyAffix(ptr)){;}
      else{Taffix(ptr);par[0]=out;T("=a_P[%d];",1,par);}
      out++;par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}
    else if(type==IformalRepeat){repeatBlockPostload(ptr,n,cnt,out);}
    else{par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}}
}
static void regularCallD1(int *a){/* >fnext+>tnext+type> */
  int par[3];                     /*   0       1     2   */
  par[0]=calledRule;par[1]=rcanfail;if(isItemFlag(par)){
    if(a[0]!=nextNodeIdx &&(a[1]==nextNodeIdx||a[0]<=0)){
      a[2]=2;T("if(!",0,par);}
    else{a[2]=1;T("if(",0,par);}}
  else{a[2]=0;}
}
static void regularCallD2(int type,int fnext){
  int par[1];
  if(type==1){T("){",0,par);}
  else if(type==2){par[0]=fnext;T("){%G}",1,par);}
  else{printChar(';');}
}
static void regularCallD3(int type,int fnext,int tnext){
  int par[2];
  if(type==1){par[0]=tnext;par[1]=fnext;T("%G}%G%n",2,par);}
  else if(type==2){par[0]=tnext;T("%G%n",1,par);}
  else{par[0]=tnext;T("%G%n",1,par);}
}
/* ---------------------------------------------------------------- */
static int isPidginDiscarded(int ptr){
  int par[3];int n,cnt,type;
  par[0]=calledRule;par[1]=rtype;if(isItemFlag(par)){return 0;}
  par[0]=calledRule;getNumberOfFormals(par);n=par[1];cnt=0;nxt:
  if(cnt==n){return 1;}
  par[0]=calledRule;par[1]=cnt;getFormal(par);type=par[2];cnt++;
  if(isDummyAffix(ptr)){par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}
  else if(type==IformalOut||type==IformalInout||type==IformalRepeat){return 0;}
  else{par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}
}
static void pidginAltTagtail(int ptr){
  int par[3]; int n,cnt,type;
  par[0]=calledRule;getNumberOfFormals(par);n=par[1];cnt=0;nxt:
  if(cnt==n){;}
  else{par[0]=calledRule;par[1]=cnt;getFormal(par);type=par[2];cnt++;
    if(type==IformalOut){
       if(BUFFER->offset[ptr]==Dnoarg){printChar('0');}else{printChar('1');}}
    if(type==IformalRepeat){;}
    else{par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}}
}
static void pidginRepeatBlock(int ptr){
  int par[3];int size,cnt;
  ptr++;size=BUFFER->offset[ptr];par[0]=ptr;nextAffix(par);ptr=par[0];
  printInt(size);if(size<0){cnt=-size;}else{cnt=size;}nxt:
  if(cnt==0){;}
  else{printChar(',');Taffix(ptr);cnt--;par[0]=ptr;nextAffix(par);ptr=par[0];
    goto nxt;}
  if(size>0){;}else{T(",a_C,a_V",0,par);}
}
static void pidginRuleArgs(int ptr,int alt){
  int par[3];int n,cnt,sep,type;
  par[0]=calledRule;getNumberOfFormals(par);n=par[1];cnt=sep=0;nxt:
  if(cnt==n){;}
  else{par[0]=calledRule;par[1]=cnt;getFormal(par);type=par[2];cnt++;
    if(type==IformalRepeat){par[0]=sep;argSep(par);sep=par[0];
         pidginRepeatBlock(ptr);}
    else{if(type==IformalOut&&alt!=0&&BUFFER->offset[ptr]==Dnoarg){;}
         else{par[0]=sep;argSep(par);sep=par[0];Taffix(ptr);}
         par[0]=ptr;nextAffix(par);ptr=par[0];goto nxt;}}
}
static void pidginRuleCall(int ptr){
  int par[3];int alt;
  par[0]=calledRule;T("%r",1,par);
  if(isPidginAlt(calledRule)){alt=1;pidginAltTagtail(ptr);}else{alt=0;}
  printChar('(');pidginRuleArgs(ptr,alt);printChar(')');
}
/* ---------------------------------------------------------------- */

void TruleCall(int *a){
  /*>tag+>C1+>C2+>C3+>n+>fnext+>tnext+>rep+>star+>odummy+>idummy+>ptr */
  /*  0   1    2   3  4  5       6      7    8      9       10    11  */
  int par[8];int type;
  calledRule=a[0];a[11]++;
  par[0]=a[0];if(isBuiltinRule(par)){if(par[1]==2){genShiftaffix(a[5],a[6]);}
    else if(par[1]==3){genGetaffixno(a[4],a[11],a[6]);}
    else{genAssignment(a[7],a[8],a[11],a[6]);}}
  else if(isPidginRule(a[0])){
    if(isPidginDiscarded(a[11])){;}
    else{par[0]=a[5];par[1]=a[6];regularCallD1(par);type=par[2];
         pidginRuleCall(a[11]);
         regularCallD2(type,a[5]);
         regularCallD3(type,a[5],a[6]);}}
  else{
    regularCallPreload(a[11]);
    par[0]=a[5];par[1]=a[6];regularCallD1(par);type=par[2];
    regularRuleCall(a[11]);
    regularCallD2(type,a[5]);
    regularCallPostload(a[11]);
    regularCallD3(type,a[5],a[6]);}
//    par[0]=a[0];par[1]=a[4];par[2]=a[5];par[3]=a[6];par[4]=a[7];par[5]=a[8];
//    par[6]=a[9];par[7]=a[10];
//    T(" %r(n=%d,f=%d,t=%d,rep=%d,star=%d,od=%d,id=%d);%n",8,par);}

}
/* ----------------------------------------- */
static void extensionBlock(int w,int st,int ptr){
  int par[3];int offs,x;
  ptr++;offs=ptr;nxt1:if(BUFFER->offset[offs]==Dplus){;}else{offs++;goto nxt1;}
  offs++;nxt:if(BUFFER->offset[offs]<0){;}else{
   x=w-BUFFER->offset[offs];x++;offs++;par[0]=st;par[1]=x;
   T("to_LIST(%p)->top[%d]=",2,par);goto nxt;}
  Taffix(ptr);printChar(';');
}
void Textension(int *a){/* >ptr + >label */
  int par[3];int st,w;
  a[0]++;w=BUFFER->offset[a[0]];a[0]++;st=a[0];
  par[0]=st;par[1]=w;T(" a_extension(%p,%d);",2,par);
  a[0]+=2;nxt:extensionBlock(w,st,a[0]);a[0]=BUFFER->offset[a[0]];
  if(a[0]==0){;}else{goto nxt;}
  par[0]=st;par[1]=w;T("to_LIST(%p)->aupb+=%d;%n",2,par);
  jumpToLabel(a[1]);
}
/* ---------------------------------------------------- */
static void boxClassifier(int *a){/* >ptr + v> */
  int par[3];int t;
  t=BUFFER->offset[a[0]];
  if(t==Titem||t==Tlocal||t==Tformal||t==Tconst){a[1]=a[0];}
  else{a[1]=r1;par[0]=a[1];T("register int %p=",1,par);
    Taffix(a[0]);T(";%n",0,par);}
}
static int isCompleteArea(int ptr){
  if(BUFFER->offset[ptr]==0){ptr+=2;
    if(BUFFER->offset[ptr]==INT_MIN && BUFFER->offset[ptr+1]==INT_MAX){return 1;}}
  return 0;
}
static void TsingleIfCondition(int lw,int up,int v){
  int par[4];
  if(lw==up){par[0]=v;par[1]=lw;T("%p==%d",2,par);}
  else if(lw==INT_MIN){par[0]=v;par[1]=up;T("%p<=%d",2,par);}
  else if(up==INT_MAX){par[0]=v;par[1]=lw;T("%p>=%d",2,par);}
  else{par[0]=lw;par[1]=v;par[2]=v;par[3]=up;
     T("(%d<=%p && %p<=%d)",4,par);}
}
static void TifCondition(int ptr,int v){
  int par[3];int lw,up;again:
  ptr++;lw=BUFFER->offset[ptr];ptr++;up=BUFFER->offset[ptr];
  TsingleIfCondition(lw,up,v);ptr++;
  if(BUFFER->offset[ptr]==Dsemicolon){T("||",0,par);goto again;}
}
static void TjumpToAreas(int ptr,int v){
  int par[3];int goal,fgoal,nextptr; again:
  nextptr=BUFFER->offset[ptr];
  if(nextptr==0){ptr++;goal=BUFFER->offset[ptr];T(" if(!(",0,par);
    TifCondition(ptr,v);par[0]=v;T(")){a_area_failed(%p);}%n",1,par);
    if(goal==nextNodeIdx){;}
    else{par[0]=BUFFER->offset[ptr];T(" %g",1,par);}}
  else if(isCompleteArea(nextptr)){ptr++;goal=BUFFER->offset[ptr];
    nextptr++;fgoal=BUFFER->offset[nextptr];
    if(goal==nextNodeIdx){if(goal==fgoal){;}else{
      T(" if(!(",0,par);TifCondition(ptr,v);
      par[0]=fgoal;T(")){ %g}%n",1,par);}}
    else{T(" if(",0,par);TifCondition(ptr,v);par[0]=goal;
      T("){ %g}%n",1,par);
      if(fgoal==nextNodeIdx){;}else{par[0]=fgoal;T(" %g",1,par);}}}
  else{ptr++;T(" if(",0,par);TifCondition(ptr,v);par[0]=BUFFER->offset[ptr];
    T("){ %g}%n",1,par);ptr=nextptr;goto again;}
}
void Tbox(int *a){ /* >affix + >area */
  int par[3];int v;
  T("{",0,par);a[0]++;par[0]=a[0];boxClassifier(par);v=par[1];
  a[1]++;TjumpToAreas(a[1],v);T("}%n",0,par);
}
/* ------------------------------------------------ */
static void listInitialization(int kind,int item){
  int par[7];int cal,lb,up,fill;
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){par[0]=item;
    getCalibre(par);cal=par[1];
    par[0]=ITEM->offset[item-ITEM_tag];par[1]=item;par[2]=cal;
    T(" %p(%r,%d);%n",3,par);}
  else{ par[0]=item;getCalibre(par);cal=par[1];getVupb(par);up=par[1];
    getVlwb(par);lb=par[1];getFill(par);fill=par[1];par[0]=kind,
    par[1]=item;par[2]=cal;par[3]=lb;par[4]=up;par[5]=fill;
    par[6]=ITEM->offset[item-ITEM_tag];
    T(" a_setup_list(%d,%r,%d,%d,%d,%d); /* %p */%n",7,par);}
}
static void charfileInitialization(int item){
  int par[5];int dir,id,ptr;
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){par[1]=item;
    par[0]=ITEM->offset[item-ITEM_tag];T(" %p(%r);%n",2,par);}
  else{par[0]=item;par[1]=toutfile;if(isItemFlag(par)){dir=2;}else{dir=0;}
    par[1]=tinfile;if(isItemFlag(par)){dir++;}
    par[0]=item;getFileData(par);id=par[1];ptr=par[2];
    par[0]=item;par[1]=dir;par[2]=id;par[3]=ptr;
    par[4]=ITEM->offset[item-ITEM_tag];
    T(" a_setup_charfile(%r,%d,%r,%r); /* %p */%n",5,par);}
}
static void countFileArea(int *a){/* >p + cnt> */
  int par[3];
  a[1]=0;nxt:if(a[0]==0){return;}
  a[1]++;par[0]=a[0];getFileLink(par);a[0]=par[0];goto nxt;
}
static void datafileInitialization(int item){
  int par[6];int dir,id,ptr,link,cnt;
  par[0]=item;par[1]=texternal;if(isItemFlag(par)){par[1]=item;
    par[0]=ITEM->offset[item-ITEM_tag];
    T(" %p(%r);%n",2,par);}
  else{par[0]=item;par[1]=toutfile;if(isItemFlag(par)){dir=2;}else{dir=0;}
    par[1]=tinfile;if(isItemFlag(par)){dir++;}
    par[0]=item;getFileData(par);id=par[1];ptr=par[2];link=par[3];
    par[0]=link;countFileArea(par);cnt=par[1];
    par[0]=item;par[1]=dir;par[2]=id;par[3]=ptr;par[4]=cnt;
    par[5]=ITEM->offset[item-ITEM_tag];
    T(" a_setup_dfile(%r,%d,%r,%r,%d); /* %p */%n",6,par);
    nxt:if(link==0){;}
    else{par[0]=link;getFileLink(par);link=par[0];cnt=par[1];
     id=par[2];par[0]=item;par[1]=id;par[2]=cnt;
     T("   a_add_filearea(%r,%r,%d);%n",3,par);goto nxt;}}
}

void dataInitialization(void){
  int par[4];int ptr,t;
  T("static void a_data_setup(void){%n",0,par);
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
  T(" a_list_fill(a_FILL);%n}%n",0,par);
}
/* ------------------------------------------------ */

void initialize_target(void){
  init_MSG();
  init_LEXT();
}

/* EOF */

