/* lists.ale */

#include "stddata.h"
#include "lists.h"
#include "display.h"
#include "lexical.h"
#include "tags.h"
#include "symbols.h"
#include "types.h"
#include "disc.h"
#include "pragmats.h"

/* ------------------------------------------------------------- */
/* messages */
static int wrong_selector,selector_expected,list_tag_missing,
  doubly_defined_selector,standard_selector_different,different_calibre,
  repeat_constant_expected,repeat_constant_out_of_range,
  external_list_with_fill,error_in_filling,only_one_repeater,
  missing_tag_initializer,filling_list_expected,tag_redefined_at,
  tag_redefined_proto,no_external_string,no_external_size,
  wrong_size_estimator,mixing_proto,filling_selector_expected,
  size_estimator_range,list_tag_not_used;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void add_messages(void){
  addMSG("selector syntax",wrong_selector);
  addMSG("selector expected",selector_expected);
  addMSG("list tag is missing after 'stack' or 'table'",list_tag_missing);
  addMSG("%p %p: selector %p different (%l)",doubly_defined_selector);
  addMSG("%p %p: standard selector %p different (%l)",standard_selector_different);
  addMSG("%p %p: calibre must be %d (%l)",different_calibre);
  addMSG("repeat constant expected",repeat_constant_expected);
  addMSG("repeat constant %d out of range (1 .. 10000)",repeat_constant_out_of_range);
  addMSG("%p filling: only one * in the block",only_one_repeater);
  addMSG("%p filling: selector expected",filling_selector_expected);
  addMSG("%p %p: cannot have filling",external_list_with_fill);
  addMSG("%p %p filling: syntax error",error_in_filling);
  addMSG("%p filling: missing tag after :",missing_tag_initializer);
  addMSG("%p filling: block expected",filling_list_expected);
  addMSG("%p %p: redefined as %p ( %l)",tag_redefined_at);
  addMSG("%p %p: redefined as %p",tag_redefined_proto);
  addMSG("external %p: missing string after =",no_external_string);
  addMSG("no size estimator in external declaration",no_external_size);
  addMSG("syntax error in size estimator",wrong_size_estimator);
  addMSG("mixing declaration and prototype in %p declaration",mixing_proto);
  addMSG("size estimator ""%d"" out of allowed range",size_estimator_range);
  addMSG("%p %p: not used",list_tag_not_used);
}
#undef addMSG
/* ------------------------------------------------------------- */
#define maxStackSize	1000000
static void tagRedefined(int *a){/* >tag+>newtype */
  int par[5];int l,type;
  par[0]=a[0];getDefline(par);l=par[1];getType(par);type=par[1];
  if(l>0){par[0]=tag_redefined_at;par[1]=a[0];par[3]=a[1];par[2]=type;
    par[4]=l;Error(5,par);}
  else{par[0]=tag_redefined_proto;par[1]=a[0];par[3]=a[1];par[2]=type;
    Error(4,par);}
}
/* ------------------- */
static void skipFieldList(int *a){ /* calibre>+err> */
   int par[1];
   par[0]=Sopen;a[0]=1;if(R(par)){nxt: if(isTag(par)){par[0]=Scomma;
     if(R(par)){a[0]++; goto nxt;}
     else if(par[0]=Sequals,R(par)){goto nxt;}
     else if(par[0]=Sclose,R(par)){a[1]=0;}
     else{par[0]=wrong_selector;Error(1,par);a[1]=1;}}
    else{par[0]=selector_expected;Error(1,par);a[1]=1;}}
   else{a[1]=0;a[0]=-1;}
}
static void getListTag(int *a){ /* tag> + calibre>+fill> + err> */
  int par[2];                   /*   0      1        2       3  */
  initRestore();skipFieldList(par);a[1]=par[0];a[3]=par[1];a[0]=a[2]=0;
  if(a[3]){;}
  else if(isTag(par)){a[0]=par[0];if(ahead(Sequals)){a[2]=1;}}
  else{par[0]=list_tag_missing;Error(1,par);a[3]=1;}
  if(a[3]){forgetRestore();}else{makeRestore();}
}
static void getExternalListTag(int *a){ /* tag>+>calibre+str>+err> */
  int par[2];                           /*  0       1     2    3   */
  initRestore();skipFieldList(par);a[1]=par[0];a[3]=par[1];a[0]=a[2]=0;
  if(a[3]){;}
  else if(isTag(par)){a[0]=par[0];par[0]=Sequals;
    if(R(par)&&isString(par)){a[2]=par[0];}
    else{par[0]=no_external_string;par[1]=a[0];Error(2,par);a[3]=1;}}
  else{par[0]=list_tag_missing;Error(1,par);a[3]=1;}
  if(a[3]){forgetRestore();}else{makeRestore();}
}
/* ---------------------------------------- */
static void selectorList(int *a){ /* >typer+>tag+>calibre */
  int par[5];int lin,n,x,ssel,repr,l,sel,type;
  par[0]=Sopen;if(!R(par)){ return; }
  getLinenum(par);lin=par[0];par[0]=a[1];par[1]=a[1];
  packSelector(par);ssel=par[2];par[0]=ssel;getRepr(par);x=par[1];
  if(x==0){par[0]=ssel;par[1]=Iselector;putType(par);par[1]=a[1];
    putAdm(par);par[1]=lin;addTagPrototype(par);par[0]=ssel;
    par[1]=tdefined;setTagFlag(par);}
  par[0]=ssel;par[1]=0;putRepr(par);n=a[2];nxt:
  if(isTag(par)){sel=par[0];par[0]=sel;par[1]=a[1];packSelector(par);
    sel=par[2];par[0]=sel;getType(par);type=par[1];
    if(type==Iselector){par[0]=sel;getRepr(par);
      if(par[1]==n){;}
      else if(par[1]==0){par[0]=sel;par[1]=n;putRepr(par);par[0]=sel;
        par[1]=tdefined;setTagFlag(par);par[1]=lin;putDefline(par);}
      else{par[0]=sel;getDefline(par);l=par[1];par[0]=doubly_defined_selector;
        par[1]=a[0];par[2]=a[1];par[3]=sel;par[4]=l;Error(5,par);}}
    else if(type==Iempty){par[0]=sel;par[1]=Iselector;putType(par);
      par[1]=lin;putDefline(par);par[1]=tdefined;setTagFlag(par);par[1]=n;
      putRepr(par);par[1]=a[0];putAdm(par);}
    else{fprintf(stderr,"selectorList error:wrong selector type\n");exit(24);}}
  else{fprintf(stderr,"selectorList error: no selector tag\n");exit(24);}
  par[0]=Scomma;if(R(par)){n--;goto nxt;}
  par[0]=Sequals;if(R(par)){goto nxt;}
  par[0]=Sclose;must(par);par[0]=ssel;getRepr(par);repr=par[1];
  if(repr==0){if(x==0){x=-1;}else if(x==-1);
      else{par[0]=ssel;getDefline(par);l=par[1];
      par[0]=standard_selector_different;par[1]=a[0];par[2]=a[1];
      par[3]=ssel;par[4]=l;Error(5,par);}}
  else if(repr==x){;}
  else if(x==0){x=repr;par[0]=ssel;par[1]=lin;putDefline(par);}
  else{par[0]=ssel;getDefline(par);l=par[1];par[0]=standard_selector_different;
    par[1]=a[0];par[2]=a[1];par[3]=ssel;par[4]=l;Error(5,par);}
  par[0]=ssel;par[1]=x;putRepr(par);par[0]=a[1];par[1]=x;putSsel(par);
  par[0]=a[1];getCalibre(par);x=par[1];
  if(x==a[2]){;}
  else if(x==0){par[0]=a[1];par[1]=a[2];putCalibre(par);
//printf("put calibre for ");par[0]=a[1];printPointer(par);printf(" = %d\n",a[2]);
    par[0]=a[1];par[1]=lin;putDefline(par);}
  else{par[0]=a[1];getDefline(par);l=par[1];par[0]=different_calibre;
    par[1]=a[0];par[2]=a[1];par[3]=x;par[4]=l;Error(5,par);}
}
static void noSelectorList(int *a){ /* >typer+>tag + >calibre */
  int par[5];int ssel,x,dl;
  if(a[2]>=0){return;}
  par[0]=a[1];par[1]=a[1];packSelector(par);ssel=par[2];par[0]=ssel;
  getRepr(par);x=par[1];
  if(x==1){;}
  else if(x>0){par[0]=ssel;getDefline(par);dl=par[1];
    par[0]=standard_selector_different;par[1]=a[0];par[2]=a[1];par[3]=ssel;par[4]=dl;Error(5,par);}
  else{par[0]=ssel;par[1]=Iselector;putType(par);par[1]=a[1];putAdm(par);
    par[1]=1;putRepr(par);par[0]=a[1];par[1]=1;putSsel(par);
    getLinenum(par);dl=par[0];par[0]=ssel;par[1]=dl;addTagPrototype(par);}
  par[0]=a[1];getCalibre(par);x=par[1];
  if(x==1){;}
  else if(x>0){par[0]=a[1];getDefline(par);dl=par[1];
    par[0]=different_calibre;par[1]=a[0];par[2]=a[1];par[3]=x;par[4]=dl;Error(5,par);}
  else{par[0]=a[1];par[1]=1;putCalibre(par);}
}
void fixListUsage(int *a){ /* >tag */
  int par[4];int ssel,type;
  par[0]=a[0];getType(par);type=par[1];
  if(!(type==Itable ||type==Istack||type==IstaticStack)){return;}
  par[0]=a[0];par[1]=timported;if(isTagFlag(par)){par[0]=a[0];par[1]=tused;setTagFlag(par);}
//  par[0]=a[0];par[1]=tfill;if(isTagFlag(par)){par[0]=a[0];par[1]=tused;setTagFlag(par);}
//  par[0]=a[0];par[1]=tused;if(isTagFlag(par)){;}
//         else if((par[1]=tpermanent,isTagFlag(par))){;}else{
//         par[0]=a[0];getDefline(par);par[3]=par[1];par[1]=type;
//         par[0]=list_tag_not_used;par[2]=a[0];Xwarning(3,par[3],3,par);}
  par[0]=a[0];par[1]=tdefined;if(isTagFlag(par)){return;}
  par[0]=a[0];par[1]=tdefined;setTagFlag(par);par[0]=a[0];getCalibre(par);
  if(par[1]==0){par[0]=a[0];par[1]=1;putCalibre(par);par[0]=a[0];
    par[1]=1;putSsel(par);par[0]=par[1]=a[0];packSelector(par);ssel=par[2];
    par[0]=ssel;par[1]=Iselector;putType(par);par[1]=1;putRepr(par);
    par[0]=ssel;par[1]=tdefined;setTagFlag(par);par[0]=ssel;par[1]=a[0];
    putAdm(par);}
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
static void sizeEstimator(int *a){ /* etype> + esize> */
  int par[3];
  par[0]=Ssub;if(R(par)){par[0]=Sbox;if(R(par)){a[0]=1;}else{a[0]=0;}
   if(isCons(par)){a[1]=par[0];a[0]++;
     if(a[1]<=0){par[0]=size_estimator_range;par[1]=a[1];
       Warning(9,2,par);a[1]=1;}
     else if(maxStackSize<=a[1]){par[0]=size_estimator_range;
      par[1]=a[1];Warning(6,2,par);if(a[0]==1){a[1]=100;}
      else{a[1]=maxStackSize;}}
     else if(101<=a[1]){if(a[0]==1){
      par[0]=size_estimator_range;par[1]=a[1];Warning(6,2,par);a[1]=100;}}}
   else if(isTag(par)){a[1]=par[0];a[0]+=3;par[0]=a[1];useTag(par);}
   else if(a[0]==1){par[0]=wrong_size_estimator;Error(1,par);
     a[1]=a[0]=0;}
   else{a[1]=a[0]=0;}
   par[0]=Sbox;Rskip(par);par[0]=Sbus;must(par);}
  else{a[1]=a[0]=-1;}
}
/* ------------------------------------------------------------- */
/* filling list pack */
static void repeatCount(void){
  int par[3];int va[3];int n,tag;
  n=1;tag=0;par[0]=Sasterisk;if(R(par)){
    if(isCons(par)){n=par[0];if(1<=n&&n<=10000){;}
     else{va[0]=repeat_constant_out_of_range;va[1]=n;
       Warning(9,2,va);n=1;}}
    else if(isTag(par)){tag=par[0];n=-1;useTag(par);}
    else{par[0]=repeat_constant_expected;Error(1,par);}}
  if(n==1){;}else{par[0]=Dstar;D(par);if(n<0){par[0]=tag;Dtag(par);}
    else{par[0]=n;Dcons(par);}}
}
static int isExtendedBlock(void){
  int par[2];
  initRestore();if((isCons(par)||isTag(par)) && (par[0]=Sarrow,R(par))){
     makeRestore();return 1;}
  makeRestore(); return 0;
}
static void selectors(int *a){ /* >tag + >t> */ 
  int par[3];int sel;
  par[0]=Sarrow;if(R(par)){nxt:par[0]=Dto;D(par);par[0]=Sasterisk; 
    if(R(par)){if(a[1]==0){a[1]=1;par[0]=Dstar;D(par);}
      else{par[0]=only_one_repeater;par[1]=a[0];Error(2,par);}}
    else if(isTag(par)){sel=par[0];par[0]=sel;par[1]=a[0];packSelector(par);
      sel=par[2];par[0]=sel;Dtag(par);}
    else{par[0]=filling_selector_expected;par[1]=a[0];Error(2,par);skipAll();}
    par[0]=Sarrow;if(R(par)){goto nxt;}}
  else{par[0]=filling_selector_expected;par[1]=a[0];Error(2,par);skipAll();}
}
static void extendedBlock(int *a){/* >tag */
  int par[3];int t,cnt;
  cnt=t=0;par[0]=Dextension;D(par);nxt:
  par[0]=Scomma;
  if(R(par)){goto nxt;}
  else if(isCons(par)){Dcons(par);par[0]=a[0];par[1]=t;selectors(par);
    t=par[1];cnt++;goto nxt;}
  else if(isTag(par)){useTag(par);Dtag(par);par[0]=a[0];par[1]=t;
    selectors(par);t=par[1];cnt++;goto nxt;}
  else if(cnt==0){par[0]=filling_list_expected;par[1]=a[0];Error(2,par);
    skipAll();}
  else{par[0]=Sclose;must(par);par[0]=Dextension;D(par);}
}
static void listFillBlock(int *a){/* >tag */
  int par[3];int t,cnt;
  if(isExtendedBlock()){extendedBlock(a);return;}
  cnt=t=0;par[0]=Dopen;D(par);nxt:par[0]=Scomma;
  if(R(par)){goto nxt;}
  else if(isCons(par)){Dcons(par);cnt++;goto nxt;}
  else if(isTag(par)){useTag(par);Dtag(par);cnt++;goto nxt;}
  else if(cnt==0){par[0]=filling_list_expected;
    par[1]=a[0];Error(2,par);skipAll();}
  else if((par[0]=Sasterisk,R(par))){if(t==0){t=1;par[0]=Dstar;D(par);}
    else{par[0]=only_one_repeater;par[1]=a[0];Error(2,par);}goto nxt;}
  else{par[0]=Sclose;must(par);par[0]=Dclose;D(par);}
}
static void initializer(int *a){ /* >list */
  int par[3];int tag,type,dl,err; nxt:
  par[0]=Scolon;if(R(par)){err=0;
    if(isTagdl(par)){tag=par[0];dl=par[1];getType(par);type=par[1];
      if(type==Iempty||type==Iconstant){par[0]=tag;par[1]=dl;par[2]=err;
        addTagDefinition(par);err=par[2];
        if(err){;}
        else{par[0]=tag;par[1]=IpointerConstant;putType(par);
          par[1]=a[0];putAdm(par);par[0]=Dcolon;D(par);par[0]=tag;
          Dtag(par);}}
      else{par[0]=tag;par[1]=IpointerConstant;tagRedefined(par);}
      goto nxt;}
    else{par[0]=missing_tag_initializer;par[1]=a[0];Error(2,par);}}
}
static void listFill(int *a){ /* >typer  +>tag */
  int par[3];
//printf("ListFill, get in, inpt=%d, Sopen=%d\n",inpt,Sopen);
  par[0]=Sopen;if(R(par)){par[0]=Sclose;if(R(par)){return;}
   par[0]=a[1];par[1]=texternal;if(isTagFlag(par)){par[0]=external_list_with_fill;
     par[1]=a[0];par[2]=a[1];Error(2,par);}
//printf("ListFill, tag=%d, calibre=%d\n",a[0],calibre);
   par[0]=Dfill;D(par);par[0]=a[1];Dtag(par);nxt:
   if(isCons(par)){Dcons(par);repeatCount();}
   else if(isTag(par)){useTag(par);Dtag(par);repeatCount();}
   else if(isString(par)){Dstring(par);repeatCount();}
   else if(par[0]=Sopen,R(par)){par[0]=a[1];listFillBlock(par);repeatCount();}
   else{par[0]=error_in_filling;par[1]=a[0];par[2]=a[1];Error(3,par);skipAll();}
//printf("ListFill, after an entry\n");
   par[0]=a[1];initializer(par);par[0]=Scomma;
   if(R(par)){goto nxt;}
   par[0]=Sclose;if(R(par)){par[0]=Dpoint;D(par);//par[0]=a[0];useTag(par);
     par[0]=a[1];par[1]=tfill;setTagFlag(par);}
   else{par[0]=error_in_filling;par[1]=a[0];par[2]=a[1];Error(3,par);skipAll();}}
  else{par[0]=error_in_filling;par[1]=a[0];par[2]=a[1];Error(3,par);skipAll();}
//printf("ListFill, done\n");
}
/* ============================================================= */
static void listDeclarationTail(int *a){ /* >typer+>tag+>etype+>esize */
  int par[3];                            /*   0      1     2      3   */
  par[0]=a[1];getType(par);if(par[1]==Iempty){
    par[0]=a[1];par[1]=a[0];newListEntry(par);}
  if(a[2]<=0){;}
  else{par[0]=Dlist;D(par);par[0]=a[1];Dtag(par);par[0]=a[2];Dcons(par);
    if(a[2]<3){par[0]=a[3];Dcons(par);}else{par[0]=a[3];Dtag(par);}
    par[0]=Dpoint;D(par);}
}
static void externalDeclarer(int *a){ /* >typer+>dl */
  int par[5];int tag,calibre,str,err;
  getExternalListTag(par);tag=par[0];calibre=par[1];str=par[2];err=par[3];
  if(err){skipAll();}
  else{par[0]=tag;getType(par);if(par[1]==Iempty){;}
    else if(par[1]==a[0]){;}
    else{par[0]=tag;par[1]=a[0];tagRedefined(par);err=1;}
  par[0]=tag;par[1]=a[1];par[2]=err;addTagExternal(par);err=par[2];
  if(err){skipAll();}
  else{par[0]=a[0];par[1]=tag;par[2]=0;par[3]=-1;listDeclarationTail(par);
    par[0]=a[0];par[1]=tag;par[2]=calibre;selectorList(par);
    par[0]=a[0];par[1]=tag;par[2]=calibre;noSelectorList(par);
    par[0]=tag;par[1]=tfill;if(isTagFlag(par)){par[0]=external_list_with_fill;
      par[1]=a[0];par[2]=tag;Error(2,par);}
    par[0]=tag;par[1]=str;putRepr(par);Rskip(par);par[0]=Sequals;Rskip(par);
    par[0]=str;Rskip(par);}}
}
static void prototype(int *a){/* >typer + >dl + >ext> */
  int par[5];int proto,tag,fill,calibre,err;
  par[0]=pgtProto;getPragmatValue(par);proto=par[1];
  getListTag(par);tag=par[0];calibre=par[1];fill=par[2];err=par[3];
//printf("prototype; fill=%d, cal=%d, ext=%d\n",fill,calibre,a[2]);
  if(err){;}
  else if(fill){proto=0;if(a[2]==3){par[0]=mixing_proto;par[1]=a[0];Error(2,par);err=1;}
                   else{a[2]=4;}}
  else if(a[2]==4){par[0]=mixing_proto;par[1]=a[0];Error(2,par);err=1;}
  else{a[2]=3;}
  if(err){skipAll();}
  else{par[0]=tag;getType(par);if(par[1]==Iempty){;}
   else if(par[1]==a[0]){;}
   else{par[0]=tag;par[1]=a[0];tagRedefined(par);err=1;}
//printf("list prototype for ");par[0]=tag;printPointer(par);printf(" proto=%d, ext=%d\n",proto,a[2]);
   if(err){;}
//   else if(fill){par[0]=tag;par[1]=a[1];addTagPrototype(par);}
   else if(proto==1){par[0]=tag;par[1]=a[1];par[2]=err;
     addTagImport(par);err=par[2];}
   else if(proto==2){par[0]=tag;par[1]=a[1];par[2]=err;
     addTagPublic(par);err=par[2];}
   else{par[0]=tag;par[1]=a[1];addTagPrototype(par);}
   if(err){skipAll();}
   else{par[0]=a[0];par[1]=tag;par[2]=0;par[3]=-1;listDeclarationTail(par);
     par[0]=a[0];par[1]=tag;par[2]=calibre;selectorList(par);
     if(proto==0){;}else{par[0]=a[0];par[1]=tag;par[2]=calibre;noSelectorList(par);}
     par[0]=tag;Rskip(par);par[0]=Sequals;if(R(par)){
     par[0]=a[0];par[1]=tag;listFill(par);}}
}}
static void declarer(int *a){ /* >typer+>dl+>etype+>esize */
  int par[4];int tag,err,calibre;
  getListTag(par);tag=par[0];calibre=par[1];err=par[3];
//printf("declarer, tag=");par[0]=tag;printPointer(par);printf(", cal=%d\n",calibre);
  if(err){skipAll();}
  else{par[0]=tag;getType(par);if(par[1]==Iempty){;}
    else if(par[1]==a[0]){;}else{par[0]=tag;par[1]=a[0];
      tagRedefined(par);err=1;}
//printf("addTagDefinition: tag=%d, dl=%d, err=%d\n",tag,a[1],err);
    par[0]=tag;par[1]=a[1];par[2]=err;addTagDefinition(par);err=par[2];
    if(err){skipAll();}
    else{par[0]=a[0];par[1]=tag;par[2]=a[2];par[3]=a[3];
      listDeclarationTail(par);par[0]=a[0];par[1]=tag;par[2]=calibre;
      selectorList(par);par[0]=a[0];par[1]=tag;par[2]=calibre;
      noSelectorList(par);par[0]=tag;Rskip(par);
      par[0]=Sequals;if(R(par)){par[0]=a[0];par[1]=tag;listFill(par);}}
}}
static void declaration(int *a){ /* >ext> + >typer */
  int par[4];int l,esize,etype;
  getLinenum(par);l=par[0];
  if(a[1]!=Itable){sizeEstimator(par);etype=par[0];esize=par[1];if(etype>=0){
     if(a[0]>=3){par[0]=mixing_proto;par[1]=a[1];Error(2,par);skipAll();}
     else if(a[2]==1){par[0]=no_external_size;Error(1,par);skipAll();}
     else{a[0]=2;par[0]=a[1];par[1]=l;par[2]=etype;par[3]=esize;
       declarer(par);}return;}}
  if(a[0]==1){par[0]=a[1];par[1]=l;externalDeclarer(par);}
  else if(a[0]==2){par[0]=mixing_proto;par[1]=a[1];Error(2,par);
    skipAll();}
  else{par[0]=a[1];par[1]=l;par[2]=a[0];prototype(par);a[0]=par[2];}
}
static void declarationSeries(int *a){ /* >ext + >typer */
  int par[3];nxt:
  par[0]=a[0];par[1]=a[1];declaration(par);a[0]=par[0];
  par[0]=Scomma;if(R(par)){goto nxt; }
  par[0]=Spoint;if(R(par)){;}
  else{par[0]=Spoint;must(par);skipToPoint();}
}
void tableDeclaration(int *a){ /* >ext */
  int par[2];
  par[0]=a[0];par[1]=Itable;declarationSeries(par);
}
void stackDeclaration(int *a){ /* >ext */
  int par[2];
  par[0]=a[0];par[1]=Istack;declarationSeries(par);
}
void staticStackDeclaration(void){
  int par[2];
  par[0]=0;par[1]=IstaticStack;declarationSeries(par);
}
/* ------------------------------------------------------------- */
void initialize_lists(void){
  add_messages();
}

/* EOF */

