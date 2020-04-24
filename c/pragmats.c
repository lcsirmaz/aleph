/* pragmats.ale main file */

#include "stddata.h"
#include "pragmats.h"
#include "input.h"
#include "lexical.h"
#include "display.h"
#include "disc.h"
#include "symbols.h"
#include "tags.h"
#include "passi.h"
#include "types.h"

#define default_warning_level	4
#define soft_warning_level	3
#define lib_default_warning_level 5
#define lib_soft_warning_level	5

static int tabWidth=8,giveText=0,inLibrary=0,inCompile=0,inModule=0,
  dictOn=0,useStdlib=1,protoLevel=2,programTitle=0,warningLevel=default_warning_level,
  trace=0,count=0,bounds=0,rightMargin=120,includePath=0;

/* forward declarations */
static void setLibrary(void);
static void clearLibrary(void);
static void discPragmat(int *a);
static int pgmtag,pgmstate,pgmskip,pgmiftag;

void getPragmatValue(int *a){/* >what + to> */
  if(a[0]==pgtTabwidth){a[1]=tabWidth;}
  else if(a[0]==pgtText){a[1]=giveText;}
  else if(a[0]==pgtLibrary){a[1]=inLibrary;}
  else if(a[0]==pgtCompile){a[1]=inCompile;}
  else if(a[0]==pgtModule){a[1]=inModule;}
  else if(a[0]==pgtDict){a[1]=dictOn;}
  else if(a[0]==pgtWarningLevel){a[1]=warningLevel;}
  else if(a[0]==pgtStdlib){a[1]=useStdlib;}
  else if(a[0]==pgtProto){a[1]=protoLevel;}
  else if(a[0]==pgtTitle){a[1]=programTitle;}
  else if(a[0]==pgtPath){a[1]=includePath;}
  else if(a[0]==pgtMargin){a[1]=rightMargin;}
  else{printf("getPragmatValue: internal error, what=%d\n",a[0]); exit(28); }
}
int isPragmatValue(int *a){ /* >what */
  if(a[0]==pgtLibrary){ return inLibrary>0;}
  if(a[0]==pgtCompile){ return inCompile>0;}
  if(a[0]==pgtModule){ return inModule>0;}
  if(a[0]==pgtText){ return giveText>0;}
  if(a[0]==pgtSkip){ return pgmskip!=0?1 : 0;}
  if(a[0]==pgtDict){ return dictOn!=0?1 : 0;}
  if(a[0]==pgtTrace){return trace!=0?1 : 0;}
  if(a[0]==pgtCount){return count!=0?1:0;}
  if(a[0]==pgtBounds){return bounds!=0?1:0;}
  else{printf("isPragmatValue: internal error what=%d\n",a[0]); exit(28);}
  return 0;
}
void setPragmatValue(int *a){ /* >what + >to */
  if(a[0]==pgtTabwidth){tabWidth=a[1];}
  else if(a[0]==pgtText){giveText=a[1];}
  else if(a[0]==pgtLibrary){if(a[1]){setLibrary();} else{clearLibrary();}}
  else if(a[0]==pgtCompile){inCompile=a[1];}
  else if(a[0]==pgtModule){if(a[1]){inModule=1;protoLevel=2;}else{inModule=0;}}
  else if(a[0]==pgtDict){dictOn=a[1];}
  else if(a[0]==pgtWarningLevel){
         if(a[1]==warningLevel){;}
         else if(a[1]<0){;}
         else if(a[1]>10){;}
         else{warningLevel=a[1];}}
  else if(a[0]==pgtStdlib){useStdlib=a[1];}
  else if(a[0]==pgtProto){protoLevel=a[1];}
  else if(a[0]==pgtTitle){programTitle=a[1];}
  else if(a[0]==pgtPath){includePath=a[1];}
  else{printf("setPragatValue: internal error: what=%d\n",a[0]); exit(28); }
}
/* initialize */
static int
  Pon,Poff,Pall,Pno,Pnone,Ptitle,Plist,Ptabwidth,Pmargin,
  Pwarninglevel,Pdict,Pstdlib,Pcompile,Plibrary,Pimport,
  Prequire,Pinclude,Pmodule,Pmacro,Pinline,Ppublic,Pproto,
  Pexternal,Pexport,Ptrace,Pbounds,Pcount,Pif,Pifnot,
  Pifdef,Pifndef,Pelse,Pendif;

static int
  wrong_pragmat,unknown_pragmat,wrong_pragmat_value,wrong_cons_pragmat_value,
  missing_endif_pragmat,misplaced_if_pragmat,pragmat_has_no_effect,macro_ignored;

#define addTTAG(x,y) add_new_string(x,TTAG);addTTAGblock();y=TTAG->aupb
static void addTTAGblock(void){
  int par[1];
  par[0]=STACKpar(TTAG);extendStack(par);
//  TTAG->offset[TTAG->aupb-TTAG_lastline]=-1;
}
#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
void initialize_pragmats(void){
  /* add tags to TTAG */
  addTTAG("on"        ,Pon);
  addTTAG("off"       ,Poff);
  addTTAG("all"       ,Pall);
  addTTAG("no"        ,Pno);
  addTTAG("none"      ,Pnone);
  addTTAG("title"     ,Ptitle);
  addTTAG("list"      ,Plist);
  addTTAG("tabwidth"  ,Ptabwidth);
  addTTAG("rightmargin",Pmargin);
  addTTAG("warninglevel",Pwarninglevel);
  addTTAG("dictionary",Pdict);
  addTTAG("stdlib"    ,Pstdlib);
  addTTAG("compile"   ,Pcompile);
  addTTAG("library"   ,Plibrary);
  addTTAG("require"   ,Prequire);
  addTTAG("include"   ,Pinclude);
  addTTAG("module"    ,Pmodule);
  addTTAG("import"    ,Pimport);
  addTTAG("inline"    ,Pinline);
  addTTAG("macro"     ,Pmacro);
  addTTAG("public"    ,Ppublic);
  addTTAG("prototype" ,Pproto);
  addTTAG("external"  ,Pexternal);
  addTTAG("export"    ,Pexport);
  addTTAG("trace"     ,Ptrace);
  addTTAG("bounds"    ,Pbounds);
  addTTAG("count"     ,Pcount);
  addTTAG("if"        ,Pif);
  addTTAG("ifnot"     ,Pifnot);
  addTTAG("ifdef"     ,Pifdef);
  addTTAG("ifndef"    ,Pifndef);
  addTTAG("else"      ,Pelse);
  addTTAG("endif"     ,Pendif);
  /* --------------------------- */
  addMSG("wrong pragmat syntax",wrong_pragmat);
  addMSG("unknown pragmat %p",unknown_pragmat);
  addMSG("pragmat %p: wrong value %p",wrong_pragmat_value);
  addMSG("pragmat %p: out of range value %d",wrong_cons_pragmat_value);
  addMSG("pragmat endif=%p missing",missing_endif_pragmat);
  addMSG("pragmat %p=%p has no matching part",misplaced_if_pragmat);
  addMSG("pragmat %p has no effect (compile=off)",pragmat_has_no_effect);
  addMSG("pragmat macro=%p is ignored",macro_ignored);
  /* ---------------------------- */
  add_new_string("aleph",LEXT);programTitle=LEXT->aupb;
}
#undef addMSG
#undef addTTAG

/* forward declarations */
static void discPragmat(int *a);
static void pragmatItem(int *a);
static void tagPragmat2(int *a);
static void consPragmat2(int *a);
static void stringPragmat2(int *a);
static void programPragmatItem(int *a);
static void programTagPragmat2(int *a);



static int saveWarning=0,saveProto=0;
static void setLibLevel(void){
  saveWarning=warningLevel;saveProto=protoLevel;protoLevel=0;
  if(warningLevel<soft_warning_level){warningLevel=lib_soft_warning_level;}
  else{warningLevel=lib_default_warning_level;}
}
static void restoreLibLevel(void){
  warningLevel=saveWarning;protoLevel=saveProto;
}
static void setLibrary(void){
  int par[2];
  if(inLibrary){return;}
  inLibrary=1;protoLevel=2;setLibLevel();
  par[0]=pgtWarningLevel;par[1]=warningLevel;discPragmat(par);
}
static void clearLibrary(void){
  int par[2];
  if(!inLibrary){return;}
  restoreLibLevel();inLibrary=0;par[0]=pgtWarningLevel;
  par[1]=warningLevel;discPragmat(par);
}
void resetPragmats(void){
  clearLibrary();
  dictOn=0;tabWidth=8;giveText=0;protoLevel=0;
  inCompile=1;trace=count=bounds=0;pgmskip=pgmiftag=0;
}
void cmdlinePragmat(void){
  int par[3];int x; again:
  if(isRawTag(par)){x=par[0];par[0]=Sequals;must(par);par[0]=x;pragmatItem(par);
    if((par[0]=Spoint,R(par))){;}
    else if((par[0]=Scomma,R(par))){goto again;}
    else{par[0]=Spoint,must(par);skipToPoint();}}
  else{par[0]=wrong_pragmat;Error(1,par);skipToPoint();}
}
static void pragmatItem(int *a){ /* >x */
  int par[3];int y;
  par[0]=Sopen;if(R(par)){nxt:par[0]=a[0];pragmatItem(par);
    par[0]=Scomma;if(R(par)){goto nxt;}else{par[0]=Sclose;must(par);}}
  else if(isRawTag(par)){y=par[0];par[0]=a[0];par[1]=y;par[2]=0;tagPragmat2(par);}
  else if(isCons(par)){y=par[0];par[0]=a[0];par[1]=y;consPragmat2(par);}
  else if(isString(par)){y=par[0];par[0]=a[0];par[1]=y;stringPragmat2(par);}
  else{par[0]=unknown_pragmat;par[1]=a[0];Error(2,par);skipAll();}
}
/* ========================================== */
static void markRawTagAsMacro(int *a){ /* >x+>dl */
   int par[3];int va[3];int tag,type;
   if(a[1]<=0){;}else{par[0]=a[0];par[1]=a[1];addDICT(par);}
   par[0]=a[0];getTagEntry(par);tag=par[1]; par[0]=tag;getType(par);type=par[1];
   par[0]=tag;par[1]=tnomacro;if(isTagFlag(par)){va[0]=macro_ignored;
     va[1]=tag;Warning(2,2,va);}
   else if(type==Iempty||type==Irule){par[0]=tag;par[1]=rmacro,setTagFlag(par);
     par[0]=Dpragmat;D(par);par[0]=pgtMacro;Dcons(par);par[0]=tag;Dtag(par);}
   else{va[0]=macro_ignored;va[1]=tag;Warning(3,2,va);}
}
static void markRawTagAsPublic(int *a){ /* >x+>dl */
   int par[3];int tag;
   if(a[1]<=0){;}else{par[0]=a[0];par[1]=a[1];addDICT(par);}
   par[0]=a[0];getTagEntry(par);tag=par[1];par[0]=tag;par[1]=0;par[2]=0;
   addTagPublic(par);par[0]=Dpragmat;D(par);par[0]=pgtPublic;Dcons(par);
   par[0]=tag;Dtag(par);
}
/* ========================================== */
static int aheadRawTag(int *a){/* x> */
  int par[2];
  par[1]=inpt;par[0]=STACKpar(TTAG);
  if(was(par)){a[0]=inpt;
  return 1;}
  return 0;
}
#define insertSymbol(x) inpt=(x)

static void nextPragmatSymbol(void){
  int par[2];again:
  if(pgmstate==0){nextSymbol();if(ahead(Scomma)){pgmstate=1;}
          else {pgmstate=100;}}
  else if(pgmstate==1){nextSymbol();if(aheadRawTag(par)){pgmtag=par[0];pgmstate=2;}
          else{pgmstate=100;}}
  else if(pgmstate==2){nextSymbol();if(ahead(Sequals)){pgmstate=3;}
          else{pgmstate=100;}}
  else if(pgmstate==3){nextSymbol();
    if(inpt==Sopen){pgmstate=4;goto again;}
    else if((CONST->alwb<=inpt&& inpt<=CONST->aupb)
          ||(LEXT->alwb<=inpt&&inpt<=LEXT->aupb)
          ||(TTAG->alwb<=inpt&&inpt<=TTAG->aupb)){pgmstate=0;}
    else{pgmstate=100;}}
  else if(pgmstate==4){nextSymbol();
    if((CONST->alwb<=inpt&&inpt<=CONST->aupb)
       ||(LEXT->alwb<=inpt&&inpt<=LEXT->aupb)
       ||(TTAG->alwb<=inpt&&inpt<=TTAG->aupb)){pgmstate=5;}
    else{pgmstate=100;}}
  else if(pgmstate==5){nextSymbol();
    if(inpt==Scomma){pgmstate=6;}
    else if(inpt==Sclose){pgmstate=0;goto again;}
    else{pgmstate=100;}}
  else if(pgmstate==6){insertSymbol(pgmtag);pgmstate=7;}
  else if(pgmstate==7){insertSymbol(Sequals);pgmstate=4;}
  else{ if(ahead(Sendsymb)){;}else{nextSymbol();}}
}
static void programPragmat2(int *a){ /* err> */
  int par[3]; int tag;
  a[0]=0;nxt:if(aheadRawTag(par)){tag=par[0];
    if(pgmstate==100){pgmtag=tag;pgmstate=2;} nextPragmatSymbol();
    if(ahead(Sequals)){nextPragmatSymbol();par[0]=pgmtag;par[1]=a[0];
      programPragmatItem(par);a[0]=par[1];if(a[0]!=0){;}
      else if((par[0]=Spoint,R(par))){;}
      else if(ahead(Scomma)){nextPragmatSymbol();goto nxt;}
      else{par[0]=wrong_pragmat;Error(1,par);a[0]=1;}}
    else{par[0]=wrong_pragmat;Error(1,par);a[0]=1;}}
  else{par[0]=wrong_pragmat;Error(1,par);a[0]=1;}
}
void programPragmat(int *a){ /* err> */
  pgmstate=100;programPragmat2(a);
}
static void programPragmatItem(int *a){ /* >x + >err> */
  int par[4];int y,dl;
  if(CONST->alwb<=inpt&&inpt<=CONST->aupb){
    y=CONST->offset[inpt];nextPragmatSymbol();
    if(pgmskip!=0){;}else{par[0]=a[0];par[1]=y;consPragmat2(par);}}
  else if(LEXT->alwb<inpt&&inpt<=LEXT->aupb){y=inpt;nextPragmatSymbol();
    if(pgmskip!=0){;}else{par[0]=a[0];par[1]=y;stringPragmat2(par);}}
  else if(TTAG->alwb<inpt&&inpt<=TTAG->aupb){y=inpt;getLinenum(par);dl=par[0];
    nextPragmatSymbol();par[0]=a[0];par[1]=y;par[2]=dl;par[3]=a[1];
    programTagPragmat2(par);a[1]=par[3];}
  else{par[0]=unknown_pragmat;par[1]=a[0];Error(2,par);a[1]=1;}
}
static void findIfCondition(int *a){ /* >x + >y +z> */
  int par[3];
  if(a[1]==Plist){a[2]=giveText;}
  else if(a[1]==Pdict){a[2]=dictOn;}
  else if(a[1]==Pcompile){a[2]=inCompile;}
  else if(a[1]==Pmodule){a[2]=inModule;}
  else if(a[1]==Plibrary){a[2]=inLibrary;}
  else{par[0]=wrong_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);
    a[2]=0;}
}
static void findMatchingEndif(void){
  int par[2];int err;
  par[0]=Spoint;if(R(par)){err=0;}
  else if(ahead(Scomma)){nextPragmatSymbol();
    programPragmat2(par);err=par[0];}
  else{par[0]=wrong_pragmat;Error(1,par);err=1;}
  if(err==1){skipToPoint();}
  if(err==2){;}else{passI();if(ahead(Sendsymb)){
     par[0]=missing_endif_pragmat;par[1]=pgmiftag;Error(2,par);}}
}
static void doPragmatSkip(int *a){ /* >iftag + >z */
  int oldif,oldskip;
  oldif=pgmiftag;pgmiftag=a[0];oldskip=pgmskip;
  if(a[1]){pgmskip++;}findMatchingEndif();
  pgmskip=oldskip;pgmiftag=oldif;
}
static void programTagPragmat2(int *a){/* >x+>y+>dl+>err> */
  int par[4];
  if(a[0]==Pif){par[0]=a[0];par[1]=a[1];findIfCondition(par);
    if(par[2]){par[0]=a[1];par[1]=0;doPragmatSkip(par);}
    else{par[0]=a[1];par[1]=1;doPragmatSkip(par);}}
  else if(a[0]==Pifnot){par[0]=a[0];par[1]=a[1];findIfCondition(par);
    if(par[2]){par[0]=a[1];par[1]=1;doPragmatSkip(par);}
    else{par[0]=a[1];par[1]=0;doPragmatSkip(par);}}
  else if(a[0]==Pifdef){par[0]=a[1];findRawUsage(par);
    if(par[1]==2){par[0]=a[1];par[1]=0;doPragmatSkip(par);}
    else{par[0]=a[1];par[1]=1;doPragmatSkip(par);}}
  else if(a[0]==Pifndef){par[0]=a[1];findRawUsage(par);
    if(par[1]!=2){par[0]=a[1];par[1]=1;doPragmatSkip(par);}
    else{par[0]=a[1];par[1]=0;doPragmatSkip(par);}}
  else if(a[0]==Pelse){if(pgmiftag==a[1]){if(pgmskip==0){pgmskip=1;}
    else if(pgmskip==1){pgmskip=0;}}
    else{par[0]=misplaced_if_pragmat;par[1]=a[0];par[2]=a[1];Error(3,par);
      if(pgmskip>0){;}else{pgmskip=1;}}}
  else if(a[0]==Pendif){if(pgmiftag==a[1]){a[3]=2;}
    else{par[0]=misplaced_if_pragmat;par[1]=a[0];par[2]=a[1];Error(3,par);
      if(pgmiftag==0){;}else{a[3]=2;}}}
  else{ if(pgmskip){;}else{par[0]=a[0];par[1]=a[1];par[2]=a[2];tagPragmat2(par);}}
}

static void discPragmat(int *a){ /* >x + >y */
  int par[1];
  par[0]=Dpragmat;D(par);par[0]=a[0];Dcons(par);
  par[0]=a[1];Dcons(par);
}
static void onOffPragmats(int *a){ /* +>tag+>x> + >y */
  int par[3];
  if(a[2]==Pon){a[1]=1;}
  else if(a[2]==Poff){a[1]=0;}
  else{par[0]=wrong_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}
}
static void tagPragmat2(int *a){ /* >x+>y+>dl */
  int par[3];
  if(a[0]==Plist){if(a[1]==Pon){giveText=1;}else if(a[1]==Poff){giveText=0;}
      else{par[0]=wrong_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}}
  else if(a[0]==Pdict){if(a[1]==Pon){dictOn=1;}else if(a[1]==Poff){dictOn=0;}
      else{par[0]=wrong_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}}
//  else if(a[0]==Pmodule){if(a[1]==Pon){inModule=1;}else if(a[1]==Poff){inModule=0;}
//      else{par[0]=wrong_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}}
  else if(a[0]==Plibrary){if(a[1]==Pon){setLibrary();}else if(a[1]==Poff){clearLibrary();}
      else{par[0]=wrong_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}}
  else if(a[0]==Pcompile){if(a[1]==Pon){inCompile=1;}else if(a[1]==Poff){inCompile=0;}
      else{par[0]=wrong_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}}
  else if(a[0]==Pproto){if(a[1]==Pno||a[1]==Pnone){protoLevel=0;}
      else if(a[1]==Ppublic){protoLevel=2;}else if(a[1]==Pimport){protoLevel=1;}
      else{par[0]=wrong_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}}
  else if(a[0]==Pmacro||a[0]==Pinline){par[0]=a[1];par[1]=a[2];markRawTagAsMacro(par);}
  else if(a[0]==Ppublic||a[0]==Pexport){par[0]=a[1];par[1]=a[2];markRawTagAsPublic(par);}
  else if(a[0]==Ptrace){par[0]=Ptrace;par[1]=trace;par[2]=a[1];onOffPragmats(par);trace=par[1];}
  else if(a[0]==Pcount){par[0]=Pcount;par[1]=count;par[2]=a[1];onOffPragmats(par);count=par[1];}
  else if(a[0]==Pbounds){par[0]=Pbounds;par[1]=bounds;par[2]=a[1];onOffPragmats(par);bounds=par[1];}
  else{par[0]=unknown_pragmat;par[1]=a[0];Error(2,par);}
}
static void consPragmat2(int *a){ /* >x + >y */
  int par[3];
  if(a[0]==Ptabwidth){if(1<=a[1]&&a[1]<=20){tabWidth=a[1];}
     else{par[0]=wrong_cons_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}}
  else if(a[0]==Pwarninglevel){if(0<=a[1]&&a[1]<=9){warningLevel=a[1];
     par[0]=pgtWarningLevel;par[1]=warningLevel;discPragmat(par);}
     else{par[0]=wrong_cons_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}}
  else if(a[0]==Pmargin){if(20<=a[1]&&a[1]<=1000){rightMargin=a[1];}
     else{par[0]=wrong_cons_pragmat_value;par[1]=a[0];par[2]=a[1];Error(3,par);}}
  else{par[0]=unknown_pragmat;par[1]=a[0];Error(2,par);}
}
static void stringPragmat2(int *a){ /* >x + >y */
  int par[2];
  if(a[0]==Pinclude){par[0]=a[1];addIncludedSource(par);}
  else if(a[0]==Prequire){par[0]=a[1];addRequiredSource(par);}
  else if(a[0]==Ptitle){if(inCompile){programTitle=a[1];}}
  else if(a[0]==Pmodule){if(inCompile){programTitle=a[1];inModule=1;protoLevel=2;}}
  else{par[0]=a[1];forgetString(par);par[0]=unknown_pragmat;par[1]=a[0];
    Error(2,par);}
}

/* EOF */

