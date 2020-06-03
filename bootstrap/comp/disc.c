/* disc.ale */

#include "stddata.h"
#include "disc.h"
#include "display.h" /* error, Xerror */
#include "types.h"   /* hasFormalType */
#include "symbols.h" /* advanceLinenum */
#include "lexical.h" /* createIceName,forgetString */
#include "tags.h"    /* getRepr */

int
  Dand,   Dbox,   Dbus, Dcalibre, Dclose, Dcolon,
  Dcomma, Dcompl, Dconst, Ddiv, Dend, Dexpression,
  Dextension, Dfile, Dfill, Dinput, Djump,
  Dlabel, Dline, Dlist, Dlocal, Dlwb, Dminus, Dnoarg, Dnode,
  Dopen, Dor, Dout, Dplus, Dpoint, Dpragmat,
  Droot, Drule, Dsemicolon, Dstack, Dmodule,
  Dstar, Dsub, Dtitle, Dto, Dupb, Dvlwb, Dvupb, 
  Dxor, Darea;

static int discFile=0;
static int cannot_open_disc_file,disc_type_error,dtag_error;
#define addtoDSYMB(x,y) add_new_string(x,DSYMB);y=DSYMB->aupb
static void init_DSYMB(void){
   addtoDSYMB("&",Dand);
   addtoDSYMB("'area'",Darea);
   addtoDSYMB("'box'",Dbox);
   addtoDSYMB("]",Dbus);
   addtoDSYMB("'calibre'",Dcalibre);
//   addtoDSYMB("'charfile'",Dcharfile);
   addtoDSYMB(")",Dclose);
   addtoDSYMB(":",Dcolon);
   addtoDSYMB(",",Dcomma);
   addtoDSYMB("~",Dcompl);
//   addtoDSYMB("'constant'",Dconstant);
//   addtoDSYMB("'datafile'",Ddatafile);
   addtoDSYMB("/",Ddiv);
   addtoDSYMB("'end'",Dend);
   addtoDSYMB("'expression'",Dexpression);
   addtoDSYMB("'extension'",Dextension);
//   addtoDSYMB("'external'",Dexternal);
   addtoDSYMB("'file'",Dfile);
   addtoDSYMB("'fill'",Dfill);
//   addtoDSYMB("'import'",Dimport);
   addtoDSYMB("'input'",Dinput);
   addtoDSYMB("'jump'",Djump);
   addtoDSYMB("'label'",Dlabel);
   addtoDSYMB("\\n",Dline);
   addtoDSYMB("'list'",Dlist);
   addtoDSYMB("'local'",Dlocal);
   addtoDSYMB("'lwb'",Dlwb);
   addtoDSYMB("-",Dminus);
   addtoDSYMB("'module'",Dmodule);
   addtoDSYMB("# ",Dnoarg);
   addtoDSYMB("'node'",Dnode);
   addtoDSYMB("(",Dopen);
   addtoDSYMB("|",Dor);
   addtoDSYMB(">",Dout);
   addtoDSYMB("+",Dplus);
   addtoDSYMB(".",Dpoint);
   addtoDSYMB("'pragmat'",Dpragmat);
//   addtoDSYMB("'public'",Dpublic);
   addtoDSYMB("'root'",Droot);
   addtoDSYMB("'rule'",Drule);
   addtoDSYMB(";",Dsemicolon);
//   addtoDSYMB("'stack'",Dstack);
//   addtoDSYMB("'ststack'",DstaticStack);
//   addtoDSYMB("'stvar'",DstaticVar);
   addtoDSYMB("*",Dstar);
   addtoDSYMB("[",Dsub);
//   addtoDSYMB("'table'",Dtable);
   addtoDSYMB("'title'",Dtitle);
   addtoDSYMB("'to'",Dto);
   addtoDSYMB("'upb'",Dupb);
//   addtoDSYMB("'var'",Dvariable);
   addtoDSYMB("'vlwb'",Dvlwb);
   addtoDSYMB("'vupb'",Dvupb);
   addtoDSYMB("^",Dxor);
   /* local */
   addtoDSYMB("'const'",Dconst);
   /* --- LEXT     ---- */
   add_new_string("/tmp/aleph.tmp",LEXT);discFile=LEXT->aupb;
   /* --- MESSAGES --- */
   add_new_string("cannot open disc file %p, error=%d",MESSAGE);
     cannot_open_disc_file=MESSAGE->aupb;
   add_new_string("disc type error for %p, error=%d",MESSAGE);
     disc_type_error=MESSAGE->aupb;
   add_new_string("disc dtag type error for %p",MESSAGE);
     dtag_error=MESSAGE->aupb;
}
#undef addtoDSYMB
/* add lists to the DISC list 
  'datafile'DISC[DSYMB,LADM,LLOC,TTAG,LEXT]
*/
static int compute_hash(char *v){
  int par[5]; int oldupb,res;
  oldupb=TTAG->aupb;
  add_new_string(v,TTAG);
  par[0]=STACKpar(TTAG);par[1]=TTAG->aupb;simplehash(par);
  res=par[2];
  par[0]=STACKpar(TTAG);par[1]=oldupb;unstackto(par);
  return res;
}

#define listB(x)	(x->vlwb-x->calibre)
static void prepare_DISC(void){
  int par[17];
  par[0]=DFILEpar(DISC); par[1]=4; /* number of lists in the area */
  par[2]=listB(DSYMB);   par[3]=DSYMB->vupb; par[4]=compute_hash("DSYMB");
  par[5]=listB(LADM);    par[6]=LADM->vupb;  par[7]=compute_hash("LADM");
  par[8]=listB(LLOC);    par[9]=LLOC->vupb;  par[10]=compute_hash("LLOC");
  par[11]=listB(LEXT);   par[12]=LEXT->vupb; par[13]=compute_hash("LEXT");
//  par[11]=listB(TTAG);   par[12]=TTAG->vupb; par[13]=compute_hash("TTAG");
//  par[14]=listB(LEXT);   par[15]=LEXT->vupb; par[16]=compute_hash("LEXT");
  fillDatafile(par);
}
#undef listB

/* ------------------------------------------------------------ */
static int Qsymbol=0,Qtype=0,Qposition,Qlinenum,linenum;

static int QbufferPtr=0,Qshift=0,Qlocal=0;

/* ------------------------------------------------------------ */

static void nextDiscSymbol(void);

void openDisc(int *a){ /* >mode */
  int par[4]; int err;
  par[0]=DFILEpar(DISC);par[1]=a[0];par[2]=STACKpar(LEXT);
  par[3]=discFile;if(!openFile(par)){
    par[0]=DFILEpar(DISC);getFileError(par);err=par[1];
    par[0]=cannot_open_disc_file;par[1]=discFile;par[2]=err;Xerror(0,3,par);
    exit(4);
  }
  if(a[0]=='r'){QbufferPtr=Qshift=0;linenum=0;nextDiscSymbol();}
}
void closeDisc(void){
  int par[2];par[0]=DFILEpar(DISC);closeFile(par);
}
void deleteDisc(void){
  int par[2];closeDisc();par[0]=STACKpar(LEXT);par[1]=discFile;unlinkFile(par);
}
void rewindDisc(void){
  int par[2];
  QbufferPtr=Qshift=0;par[0]=par[1]=0;restoreDiscPosition(par);
}

void D(int *a){
  int par[3];int err;
  par[0]=DFILEpar(DISC);par[1]=a[0];par[2]=1;
//DEBUG
if(DSYMB->alwb>a[0] || a[0]>DSYMB->aupb){printf("\n*** using D(%d) not in DSYMB ***\n",a[0]);par[0]=DSYMB->offset[a[0]];}
  if(!putDataP(par)){par[0]=DFILEpar(DISC);getFileError(par);err=par[1];
    par[0]=disc_type_error;par[1]=a[0];par[2]=err;Error(3,par);
// DEBUG
par[0]=LEXT->offset[par[0]];
    exit(5);}
}
static void D0(int *a){
  int par[3];int err;
  par[0]=DFILEpar(DISC);par[1]=a[0];par[2]=1;
  if(!putDataP(par)){par[0]=DFILEpar(DISC);getFileError(par);err=par[1];
    par[0]=disc_type_error;par[1]=a[0];par[2]=err;Error(3,par);
// DEBUG
par[0]=LEXT->offset[par[0]];
    exit(5);}
}
void Dstring(int *a){
  int par[3];
  if(a[0]<LEXT->alwb||a[0]>LEXT->aupb){par[0]=LEXT->offset[a[0]]; exit(7);}
  par[0]=DFILEpar(DISC);par[1]=a[0];par[2]=1;
  if(!putDataP(par)){par[0]=DFILEpar(DISC);getFileError(par);par[2]=par[1];
    par[0]=disc_type_error;par[1]=a[0];Error(3,par);
// DEBUG
par[0]=LEXT->offset[par[0]];
    exit(5);}
}
void Dcons(int *a){
  int par[3];
  par[0]=DFILEpar(DISC);par[1]=a[0];par[2]=0;if(!putDataP(par)){
    par[0]=DFILEpar(DISC);getFileError(par);par[0]=disc_type_error;par[2]=par[1];
    par[1]=0;Error(3,par);exit(6);}
}
void Dtag(int *a){
  int par[3];nxt:
  par[0]=STACKpar(LADM); par[1]=a[0];if(was(par)){par[0]=a[0];
    if(hasFormalType(par)){a[0]=LADM->offset[a[0]-LADM_repr];goto nxt;}
    else{par[0]=a[0];D0(par);}}
  else{par[0]=STACKpar(LLOC);par[1]=a[0];if(was(par)){par[0]=a[0];D0(par);}
      else{par[0]=dtag_error;par[1]=a[0];Error(2,par);TTAG->offset[0]=7;exit(7);}
  }
}
/* ------------------------------------------------------- */
static void readFromQbuffer(void){
  QbufferPtr++;Qsymbol=QBUFFER->offset[QbufferPtr];
  if(Qsymbol==Dend){QbufferPtr=0;Qlocal=0;nextDiscSymbol();}
  else if(Qsymbol==Dconst){Qtype=0;QbufferPtr++;
    Qsymbol=QBUFFER->offset[QbufferPtr];}
  else{Qtype=1;}
}
static void substitute(void){
  int par[3];
  par[0]=STACKpar(LLOC);par[1]=Qsymbol;if(was(par)){Qsymbol+=Qshift;
    if(LLOC->offset[Qsymbol-LLOC_type]!=Imacro){;}
    else{Qlocal=Qsymbol,QbufferPtr=LLOC->offset[Qsymbol-LLOC_repr];
      readFromQbuffer();}}
}
static void nextDiscSymbol(void){
  int par[4];
//  par[0]=Dend;if(Qahead(par)){return;} /* exhausted */
  if(QbufferPtr!=0){Qlocal=0;readFromQbuffer();return;}
  par[0]=linenum;setLinenum(par);nxt:
  par[0]=DFILEpar(DISC);getFilePos(par);Qposition=par[1];Qlinenum=linenum;
  if(getData(par)){Qsymbol=par[1];Qtype=par[2];
    if(Qsymbol==Dline && Qtype==1){linenum++;goto nxt;}
    else if(Qshift!=0&&Qtype==1){substitute();}}
  else{Qsymbol=Dend;Qtype=1;}
}
void saveDiscPosition(int *a){/* pos> + lineno> */
   if(QbufferPtr){printf("Fatal: saveDiscPosition while QbufferPtr=%d\n",QbufferPtr); exit(31);}
   a[0]=Qposition;a[1]=Qlinenum;
}
void restoreDiscPosition(int *a){ /* >pos + >lineno */
  int par[2];
  if(QbufferPtr){printf("Fatal: restoreDiscPosition while QbufferPtr=%d\n",QbufferPtr);exit(31);}
  par[0]=DFILEpar(DISC);par[1]=a[0];setFilePos(par);
  par[0]=DFILEpar(DISC);getFileError(par);if(par[1]){
   printf("restoreDiscPosition error=%d, pos=%d, linenum=%d\n",par[1],a[0],a[1]); exit(23);}
  linenum=a[1];par[0]=linenum;nextDiscSymbol();
}
/* reading */
int Q(int *a){
  if(a[0]==Qsymbol&&1==Qtype){nextDiscSymbol();return 1;}
  return 0;
}
int Qahead(int *a){
  if(a[0]==Qsymbol&&1==Qtype){return 1;}
  return 0;
}
int Qcons(int *a){
  if(Qtype==0){a[0]=Qsymbol;nextDiscSymbol();return 1;}
  return 0;}
int Qtag(int *a){if(Qtype==0){return 0;}
  if((LADM->vlwb<=Qsymbol&&Qsymbol<=LADM->vupb)||
     (LLOC->vlwb<=Qsymbol&&Qsymbol<=LLOC->vupb)){
       a[0]=Qsymbol;
//printf("<Qtag %d ",Qsymbol);printPointer(a);printf(">");
       nextDiscSymbol();return 1;}
  return 0;}
int Qstring(int *a){if(Qtype==0){return 0;}
  if(LEXT->vlwb<=Qsymbol&&Qsymbol<=LEXT->vupb){a[0]=Qsymbol;
    nextDiscSymbol();return 1;}
  return 0;
}
void mustQ(int *a){if(Q(a)){;}else{
  printf("mustQ: lineno=%d, expected symbol %d, got %d: ",Qlinenum,a[0],Qsymbol);printPointer(a);printf(" ==> ");a[0]=Qsymbol;printPointer(a);printf("\n");LLOC->offset[0]=0;exit(23);}}
void mustQtag(int *a){if(Qtag(a)){;}else{
  printf("mustQtag failed: (%d,%d), got ",Qsymbol,Qtype);a[0]=Qsymbol;printPointer(a);printf("\n");LLOC->offset[a[0]]=0;;exit(23);}}
void mustQlist(int *a){a[1]=Qlocal;mustQtag(a);}
void mustQcons(int *a){if(Qcons(a)){;}else{
  printf("mustQcons failed: (%d,%d)\n",Qsymbol,Qtype);exit(23);}}
void Qskip(int *a){/* >to */
  int par[1];nxt:
  par[0]=Dend;if(Qahead(par)){;}
  else{par[0]=a[0];if(Q(par)){;}
   else{nextDiscSymbol();goto nxt;}}
}
/* ======================================================= */
static void putQ(int c,int *a){ /* +*+>v */
  int par[3];
  par[0]=STACKpar(QBUFFER);nxt:
  par[1]=a[0];extend(par);c--;a++;if(c>0){goto nxt;}
}
static void copyQbufferAffix(int *a){ /* >ptr> */
  int par[2];int v;nxt:
  v=QBUFFER->offset[a[0]];if(v==Dplus||v==Dend){a[0]++;par[0]=Dend;putQ(1,par);}
  else if(v==Dconst){a[0]++;par[0]=Dconst;par[1]=QBUFFER->offset[a[0]];
    putQ(2,par),a[0]++;goto nxt;}
  else{par[0]=v;putQ(1,par);a[0]++;goto nxt;}
}
/* - - - - - - - - - - - - - - */
static void readSelector(int *a){ /* x> */
  int par[2];
  if(Qcons(par)){a[0]=par[0];}
  else{mustQtag(par);getRepr(par);a[0]=par[1];}
}
static void finalSsel(int *a){/* >tag+>loc+x> */
  int par[2];
  if(a[1]){a[2]=LLOC->offset[a[1]-LLOC_ssel];}
  else if((par[0]=STACKpar(LLOC),par[1]=a[0],was(par))){
     a[2]=LLOC->offset[a[0]-LLOC_ssel];}
  else{par[0]=a[0];getSsel(par);a[2]=par[1];}
}
/* - - - - - - - - - - - */
static int limitOp(int *a){
  int par[1];a[0]=Qsymbol;
  if((par[0]=Dvlwb,Q(par))||(par[0]=Dvupb,Q(par))||
     (par[0]=Dlwb,Q(par))||(par[0]=Dupb,Q(par))||
     (par[0]=Dcalibre,Q(par))){return 1;} 
  return 0;
}
static void fsimpleAffix(int *a){/* atype> */
  int par[8];int x,tag,type,loc;
  if(Qcons(par)){x=par[0];par[0]=Dconst;par[1]=x;putQ(2,par);a[0]=0;}
  else if(limitOp(par)){x=par[0];mustQtag(par);tag=par[0];
    par[0]=x;par[1]=tag;putQ(2,par);a[0]=0;}
  else if((par[0]=Dsub,Q(par))){par[0]=Dsub;mustQtag(par);tag=par[1]=par[0];
    par[0]=Dsub;putQ(2,par);
    fsimpleAffix(a);par[0]=Dbus;mustQ(par);
    readSelector(par);x=par[0];par[0]=Dbus;par[1]=Dconst;
    par[2]=x;putQ(3,par);}
  else if((par[0]=Dnoarg,Q(par))){a[0]=Inoarg;}
  else{mustQlist(par);tag=par[0];loc=par[1];a[0]=0;par[0]=tag;getType(par);
    type=par[1];if(type==Iconstant||type==IpointerConstant||type==Ivariable
      ||type==IstaticVar||type==IformalIn||type==IformalOut
      ||type==IformalInout||type==Ilocal){par[0]=tag;putQ(1,par);}
    else if(type==Istack||type==Itable||type==IstaticStack||
      type==IformalTable||type==IformalStack){par[0]=tag;par[1]=loc;
      finalSsel(par);x=par[2];par[0]=Dsub;par[1]=tag;par[2]=Dupb;par[3]=tag;
      par[4]=Dbus;par[5]=Dconst;par[6]=x;putQ(7,par);}
    else if(type==IformalRepeat){par[0]=tag;putQ(1,par);a[0]=IformalRepeat;}
    else{printf("fsimpleAffix (disc), wrong formal type %d\n",type);exit(23);}}
}
static void matchFormalActual(int *a){ /* >ftype + atype> */
  int par[2];int tag;
  if(a[0]==IformalFile||a[0]==IformalTable||a[0]==IformalStack){
    mustQtag(par);tag=par[0];putQ(1,par);par[0]=tag;getType(par);a[1]=par[1];}
  else if(a[0]==IformalIn||a[0]==IformalOut||a[0]==IformalInout){
    fsimpleAffix(par);a[1]=par[0];}
  else{printf("matchFormalActual (disc), wrong ftype %d\n",a[0]); exit(23);}
}
static void handleFormalList(int *a){/* >formal+>type */
  int par[2];
  if(a[1]==IformalStack||a[1]==IformalTable){par[0]=a[0];
   getFormalCalibre(par);LLOC->offset[LLOC->aupb-LLOC_calibre]=par[1];
   getFormalSsel(par);LLOC->offset[LLOC->aupb-LLOC_ssel]=par[1];}
}
static void expandVarargs(int *a){/* >repeat */
  int par[8];int formal,ftype,atype,lrep,block;
  par[0]=a[0];getAdm(par);formal=par[1];lrep=LLOC->aupb;block=0;nxt:
  par[0]=formal;getType(par);ftype=par[1];par[0]=ftype;
  matchFormalActual(par);atype=par[1];
  if(atype==IformalRepeat){;}
  else{if(block==0){par[0]=STACKpar(LLOC);par[1]=6;par[7-LLOC_tag]=formal;
    par[7-LLOC_type]=Imacro;par[7-LLOC_repr]=par[7-LLOC_flag]=
    par[7-LLOC_calibre]=par[7-LLOC_ssel]=0;expandstack(par);
    par[0]=formal;par[1]=ftype;handleFormalList(par);}
    if(atype!=Inoarg){;}
    else if(block==0){LLOC->offset[LLOC->aupb-LLOC_repr]=-1;
      LLOC->offset[LLOC->aupb-LLOC_type]=Ilocal;par[0]=LLOC->aupb;putQ(1,par);}
    else{par[0]=Dnoarg;putQ(1,par);}
    par[0]=formal;getAdm(par);formal=par[1];
    if(formal==0){block=1;par[0]=a[0];getAdm(par);formal=par[1];}
    par[0]=Dplus;if(Q(par)){par[0]=Dplus;putQ(1,par); goto nxt;}}
  if(block==0){int aformal=QBUFFER->offset[QBUFFER->aupb];nxt2:
    if(formal==0){;}
    else{par[0]=STACKpar(LLOC);par[1]=6;par[7-LLOC_tag]=formal;
      par[7-LLOC_type]=Imacro;par[7-LLOC_repr]=QBUFFER->aupb;
      par[7-LLOC_flag]=par[7-LLOC_calibre]=par[7-LLOC_ssel]=0;
      expandstack(par);par[0]=formal;getType(par);handleFormalList(par);
      par[0]=LADM->offset[aformal-LADM_repr];par[1]=Dend;putQ(2,par);
      par[0]=formal;getAdm(par);formal=par[1];par[0]=aformal;
      getAdm(par);aformal=par[1];goto nxt2;}}
  else{int qptr=LLOC->offset[lrep-LLOC_repr];qptr++;nxt3:
    if(formal==0){;}
    else{par[0]=STACKpar(LLOC);par[1]=lrep;next(par);lrep=par[1];
      if(LLOC->offset[lrep-LLOC_type]==Imacro){LLOC->offset[
        lrep-LLOC_repr]=QBUFFER->aupb;}
      par[0]=qptr;copyQbufferAffix(par);qptr=par[0];par[0]=formal;
      getAdm(par);formal=par[1];goto nxt3;}}
}
static void macroArguments(int *a){/* >tag */
  int par[8];int formal,ftype,atype;
  par[0]=a[0];getAdm(par);formal=par[1];nxt:
  if(formal==0){;}
  else{par[0]=STACKpar(LLOC);par[1]=6;par[7-LLOC_repr]=QBUFFER->aupb;
    par[7-LLOC_tag]=formal;par[7-LLOC_type]=Imacro;par[7-LLOC_flag]=
    par[7-LLOC_calibre]=par[7-LLOC_ssel]=0;expandstack(par);par[0]=Dplus;
    mustQ(par);par[0]=formal;getType(par);ftype=par[1];handleFormalList(par);
    if(ftype==IformalRepeat){par[0]=formal;expandVarargs(par);}
    else{par[0]=ftype;matchFormalActual(par);atype=par[1];
      if(atype==Inoarg){LLOC->offset[LLOC->aupb-LLOC_repr]=-1;
        LLOC->offset[LLOC->aupb-LLOC_type]=Ilocal;}
      else{par[0]=Dend;putQ(1,par);}
      par[0]=formal;getAdm(par);formal=par[1];goto nxt;}}
}
/* ------------------------------------------------------= */
void macroCallHead(int *a){/* >tag + Qa> +Qb> */
  int par[2];int Lptr;
  a[1]=QBUFFER->aupb;a[2]=Qshift;Lptr=LLOC->aupb;
  par[0]=a[0];macroArguments(par);
  Qshift=Lptr-LLOC->alwb+LLOC->calibre;
}
void macroCallTail(int *a){ /* >Qa+>Qb */
  int par[2];
  Qshift=a[1];par[0]=STACKpar(QBUFFER);par[1]=a[0];
  unstackto(par);
}
/* ======================================================= */

void initialize_disc(void){
  init_DSYMB(); prepare_DISC();
}


/* EOF */

