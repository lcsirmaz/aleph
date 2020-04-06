/* disc.ale */

#include "stddata.h"
#include "disc.h"
#include "display.h" /* error, Xerror */
#include "types.h"   /* hasFormalType */
#include "symbols.h" /* advanceLinenum */
#include "lexical.h" /* createObjName,forgetString */
#include "tags.h"    /* getRepr */

int
  Dand,   Dbox,   Dbus, Dcalibre, Dclose, Dcolon,
  Dcomma, Dcompl, Ddiv, Dend, Dexpression,
  Dextension, Dfile, Dfill, Dinput, Djump,
  Dlabel, Dline, Dlist, Dlocal, Dlwb, Dminus, Dnoarg,
  Dopen, Dor, Dplus, Dpoint, Dpragmat,
  Droot, Drule, Dsemicolon, Dstack, Dmodule,
  Dstar, Dsub, Dtitle, Dto, Dupb, Dvlwb, Dvupb, 
  Dxor, Dzone;


static int discFile=0;
static int cannot_open_disc_file,disc_type_error,dtag_error;
#define addtoDSYMB(x,y) add_new_string(x,DSYMB);y=DSYMB->aupb
static void init_DSYMB(void){
   addtoDSYMB("&",Dand);
   addtoDSYMB("=",Dbox);
   addtoDSYMB("]",Dbus);
   addtoDSYMB("<>",Dcalibre);
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
   addtoDSYMB("#",Dnoarg);
   addtoDSYMB("(",Dopen);
   addtoDSYMB("|",Dor);
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
   addtoDSYMB("'zone'",Dzone);
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

static void nextDiscSymbol(void);

void openDisc(int *a){ /* >mode */
  int par[4]; int err;
  par[0]=DFILEpar(DISC);par[1]=a[0];par[2]=STACKpar(LEXT);
  par[3]=discFile;if(!openFile(par)){
    par[0]=DFILEpar(DISC);getFileError(par);err=par[1];
    par[0]=cannot_open_disc_file;par[1]=discFile;par[2]=err;Xerror(0,3,par);
    exit(4);
  }
  if(a[0]=='r'){nextDiscSymbol();}
}
void closeDisc(void){
  int par[2];par[0]=DFILEpar(DISC);closeFile(par);
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
static int Qsymbol=0,Qtype=0,Qposition,Qlinenum,linenum;

static void nextDiscSymbol(void){
  int par[4];nxt:
  par[0]=DFILEpar(DISC);getFilePos(par);Qposition=par[1];Qlinenum=linenum;
  if(getData(par)){Qsymbol=par[1];Qtype=par[2];
    if(Qsymbol==Dline && Qtype==1){linenum++;par[0]=linenum;setLinenum(par);goto nxt;}}
  else{Qsymbol=Dend;Qtype=1;}
}
void saveDiscPosition(int *a){/* pos> + lineno> */
   a[0]=Qposition;a[1]=Qlinenum;
}
void restoreDiscPosition(int *a){ /* >pos + >lineno */
  int par[2];
  par[0]=DFILEpar(DISC);par[1]=a[0];setFilePos(par);
  par[0]=DFILEpar(DISC);getFileError(par);if(par[1]){
   printf("restoreDiscPosition error=%d, pos=%d, linenum=%d\n",par[1],a[0],a[1]); exit(23);}
  linenum=a[1];par[0]=linenum;setLinenum(par);nextDiscSymbol();
}

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
  printf("mustQ: lineno=%d, expected symbol %d, got %d: ",Qlinenum,a[0],Qsymbol);printPointer(a);printf(" ==> ");a[0]=Qsymbol;printPointer(a);printf("\n");LLOC->offset[a[0]]=0;exit(23);}}
void mustQtag(int *a){if(Qtag(a)){;}else{
  printf("mustQtag failed: (%d,%d), got ",Qsymbol,Qtype);a[0]=Qsymbol;printPointer(a);printf("\n");LLOC->offset[a[0]]=0;;exit(23);}}
void mustQcons(int *a){if(Qcons(a)){;}else{
  printf("mustQcons failed: (%d,%d)\n",Qsymbol,Qtype);exit(23);}}
void Qskip(int *a){/* >to */
  int par[1];nxt:
  par[0]=Dend;if(Qahead(par)){;}
  else{par[0]=a[0];if(Q(par)){;}
   else{nextDiscSymbol();goto nxt;}}
}
/* ======================================================= */

void initialize_disc(void){
  init_DSYMB(); prepare_DISC();
}


/* EOF */

