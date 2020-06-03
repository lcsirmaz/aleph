/* input.ale main file */

#include "stddata.h"
#include "input.h"
#include "lexical.h"
#include "display.h"
#include "pragmats.h"
#include "symbols.h"
#include "disc.h"
#include "passi.h"
  
/* initialization */

/* local messages */
static int missing_argument_for_pragmat,added_as_cmdline_source,
  source_included_differently,no_input_file,error_opening_source;
static int stdlibFile=0;

#define addMSG(x,y)     add_new_string(x,MESSAGE);y=MESSAGE->aupb
void initialize_input(void){
  addMSG("missing argument for cmdline pragmat \"-o\"",
          missing_argument_for_pragmat);
  addMSG("source file \"%p\" is in command line, ignored",
          added_as_cmdline_source);
  addMSG("source file \"%p\" included/required differently",
          source_included_differently);
  addMSG("no input file was specified",no_input_file);
  addMSG("error opening file \"%p\"",error_opening_source);
/* standard library */
  add_new_string("alib",LEXT);stdlibFile=LEXT->aupb;
}
#undef addMSG

/* ----------------------------------------------------------- */
/* values for flag*INPUT */
#define cpragmat	0x1301
#define csource		0x1302
#define required	0x1303
#define library		0x1304
#define included	0x13f0
#define cmp_flag	0x0008
#define proto_mask	0x0007
#define req_flag	1
//#define source_flags	(cmp_flag|2)

/* ----------------------------------------------- */
/* forward declarations */
static int isCmdlinePragmat(int *a);

/* ----------------------------------------------- */
void findLinenum(int *a){ /* >from + n> + str> */
  int par[4];int ptr,nptr;
  if(a[0]>0){;}else{getLinenum(par);a[0]=par[0];}
  ptr=INPUT->alwb;nxt: nptr=ptr+INPUT->calibre;
  if(INPUT->aupb<nptr||INPUT->offset[nptr-INPUT_n]<0||a[0]<INPUT->offset[nptr-INPUT_n]){
    a[1]=a[0]-INPUT->offset[ptr-INPUT_n];a[1]++;
    if(INPUT->offset[ptr-INPUT_flag]==cpragmat){a[2]=Squoteimage;a[1]=0;}
    else{a[2]=INPUT->offset[ptr-INPUT_string];}}
  else{ ptr=nptr;goto nxt;}
}
static void addCommandLineArg(int *a){ /* >ptr+ >twoarg> */
  int par[6];int flag;
  par[0]=a[0];par[1]=a[1];if(isCmdlinePragmat(par)){a[1]=par[1];flag=cpragmat;}
  else{flag=csource;}
  par[0]=STACKpar(INPUT);extendStack(par);INPUT->offset[INPUT->aupb-INPUT_flag]=flag;
  INPUT->offset[INPUT->aupb-INPUT_n]=-1;INPUT->offset[INPUT->aupb-INPUT_string]=a[0];
}
int getFirstSource(int *a){ /* ptr> */
  int inpt;
  inpt=INPUT->alwb;nxt:
  if(inpt>INPUT->aupb){return 0;}
  if(INPUT->offset[inpt-INPUT_flag]==csource){a[0]=INPUT->offset[inpt-INPUT_string];
    return 1;}
  inpt+=INPUT_CALIBRE;goto nxt;
}
static int wasSourceAdded(int *a){ /* >ptr + inpt> */
  int par[5];
  a[1]=INPUT->aupb;nxt:
  if(a[1]<INPUT->alwb){return 0;}
  par[0]=STACKpar(LEXT);par[1]=INPUT->offset[a[1]-INPUT_string];
  par[2]=STACKpar(LEXT);par[3]=a[0];comparestring(par);
  if(par[4]==0 && INPUT->offset[a[1]-INPUT_flag]!=cpragmat){return 1;}
  else{par[0]=STACKpar(INPUT);par[1]=a[1];previous(par);a[1]=par[1];goto nxt;}
}
static void addSource(int *a){ /* >ptr + >flag */
  int par[2];int va[3]; int inpt;
  par[0]=a[0];if(wasSourceAdded(par)){inpt=par[1];
    if(INPUT->offset[inpt-INPUT_flag]==csource){va[0]=added_as_cmdline_source;
      va[1]=a[0];Warning(8,2,va);}
    else if(INPUT->offset[inpt-INPUT_flag]==a[1]){;}
    else{va[0]=source_included_differently;va[1]=a[0];Error(2,va);}}
  else{par[0]=STACKpar(INPUT);extendStack(par);INPUT->offset[INPUT->aupb-INPUT_flag]=a[1];
    INPUT->offset[INPUT->aupb-INPUT_n]=-1;INPUT->offset[INPUT->aupb-INPUT_string]=a[0];}
}
void addRequiredSource(int *a){/* >ptr */
  int par[2];par[0]=a[0];par[1]=required;addSource(par);
}
void addIncludedSource(int *a){/* >ptr */
  int par[2]; int flag;
  par[0]=pgtProto;getPragmatValue(par);flag=par[1];
  par[0]=pgtCompile;if(isPragmatValue(par)){flag+=cmp_flag;}
  flag+=included;par[0]=a[0];par[1]=flag;addSource(par);
}
static void setPragmats(int *a){ /* >flag */
  int par[2];
  par[0]=pgtProto;par[1]=a[0]&proto_mask;setPragmatValue(par);
  par[0]=pgtCompile;par[1]=a[0]&cmp_flag;if(par[1]){par[1]=1;}else{par[1]=0;}
  setPragmatValue(par);
}
/* -------------------------------- */
static int lastLinenum=0;
int nextInputEntry(int *a){ /* >ptr> + n> + str> */
  if(a[0]==0){a[0]=INPUT->alwb;}nxt:
  if(a[0]>INPUT->aupb){return 0;}
  if(INPUT->offset[a[0]-INPUT_flag]==cpragmat){a[0]+=INPUT->calibre;goto nxt;}
  a[2]=INPUT->offset[a[0]-INPUT_string];a[1]=lastLinenum,a[0]+=INPUT->calibre;
  nxt2:if(a[0]>INPUT->aupb){;}
  else if(INPUT->offset[a[0]-INPUT_flag]==cpragmat){a[0]+=INPUT->calibre;goto nxt2;}
  else{a[1]=INPUT->offset[a[0]-INPUT_n];}
  return 1;
}
/* -------------------------------- */
#include <string.h>
/* comparestringXXX + t[]+>ptr + res>, second argument: C string */
static void comparestringXXX(int *a,char *s2){
 int *ptr1=parSTACK(a[0])->offset+a[1];
 a[2]=strcmp((char*)(ptr1+1-*ptr1),s2);
}
static int isCmdlinePragmat(int *a){ /* >ptr+>twoarg>+pid>+value> */
  int par[4];
  if(a[1]){a[1]=0;a[2]=0;a[3]=0;return 1;}
  par[0]=STACKpar(LEXT);par[1]=a[0];
  comparestringXXX(par,"-L");if(par[2]==0){a[2]=pgtLibrary;a[3]=1;return 1;}
  comparestringXXX(par,"-M");if(par[2]==0){a[2]=pgtModule;a[3]=1;return 1;}
  comparestringXXX(par,"-d");if(par[2]==0){a[2]=pgtDict;a[3]=1;return 1;}
  comparestringXXX(par,"-l");if(par[2]==0){a[2]=pgtText;a[3]=1;return 1;}
  comparestringXXX(par,"-W");if(par[2]==0){a[2]=pgtWarningLevel;a[3]=3;return 1;}
  comparestringXXX(par,"-WW");if(par[2]==0){a[2]=pgtWarningLevel;a[3]=2;return 1;}
  comparestringXXX(par,"-Wall");if(par[2]==0){a[2]=pgtWarningLevel;a[3]=0;return 1;}
  comparestringXXX(par,"-o");if(par[2]==0){a[1]=1;a[2]=pgtIce;a[3]=0;return 1;}
  comparestringXXX(par,"-I");if(par[2]==0){a[1]=1;a[2]=pgtPath;a[3]=0;return 1;}
  par[0]=STACKpar(LEXT);par[1]=a[0];par[2]=0;stringelem(par);
  if(par[3]!='-'){return 0;}par[2]=1;stringelem(par);if(par[3]!='-'){return 0;}
  a[2]=-1;a[3]=0;return 1;
}
static void initProgramArgs(void){
  int par[4];int ptr,twoarg;
  ptr=STDARG->aupb;twoarg=0;nxt:
  if(ptr<STDARG->alwb){if(twoarg==0){;}else{par[0]=missing_argument_for_pragmat;
    Xerror(0,1,par);}}
  else{par[0]=STACKpar(STDARG);par[1]=ptr;par[2]=STACKpar(LEXT);copystring(par);
  par[0]=LEXT->aupb;par[1]=twoarg;addCommandLineArg(par);twoarg=par[1];
  par[0]=STACKpar(STDARG);par[1]=ptr;stringwidth(par);ptr=ptr-par[2];goto nxt;
}}
static int nextInput(int *a){ /* >ptr> */
  int par[5];int va[2];int twoarg,pid,value,flag,use_path;again:
  if(a[0]>INPUT->aupb){return 0; }
  twoarg=0;advanceLinenum();getLinenum(par);INPUT->offset[a[0]-INPUT_n]=par[0];
  flag=INPUT->offset[a[0]-INPUT_flag];
//printf("flag=%x az elejen\n",flag);
  if(flag==csource){use_path=1;}{use_path=2;}
  if(flag==cpragmat &&
    (par[0]=INPUT->offset[a[0]-INPUT_string],par[1]=twoarg,isCmdlinePragmat(par))){
    twoarg=par[1];pid=par[2];value=par[3];
    if(pid<0){par[0]=0;par[1]=INPUT->offset[a[0]-INPUT_string];if(nextSource(par)){
      nextSymbol();cmdlinePragmat();closeSource();}else{;}
      par[0]=STACKpar(INPUT);par[1]=a[0];next(par);a[0]=par[1];goto again;}
    else if(twoarg!=0){par[0]=STACKpar(INPUT);par[1]=a[0];next(par);a[0]=par[1];
      if(a[0]>INPUT->aupb){par[0]=missing_argument_for_pragmat;
        Xerror(0,1,par);return 0;}
      else{getLinenum(par);INPUT->offset[a[0]-INPUT_n]=par[0];par[0]=pid;
        par[1]=INPUT->offset[a[0]-INPUT_string];setPragmatValue(par);
        par[0]=STACKpar(INPUT);par[1]=a[0];next(par);a[0]=par[1];goto again;}}
    else{par[0]=pid;par[1]=value;setPragmatValue(par);
      par[0]=STACKpar(INPUT);
      par[1]=a[0];next(par);a[0]=par[1];goto again;}}     
  else if((par[0]=use_path,par[1]=INPUT->offset[a[0]-INPUT_string],nextSource(par))){
    par[0]=STACKpar(INPUT);par[1]=a[0];next(par);a[0]=par[1];
//printf("flag=%x (source=%x) p=",flag,csource);par[0]=pgtProto;getPragmatValue(par);printf("%d\n",par[1]);
    if(flag==csource){;}
    else if(flag==required){par[0]=req_flag;setPragmats(par);}
//    else if(flag==csource){par[0]=source_flags;setPragmats(par);}
    else {par[0]=flag;setPragmats(par);
//printf("now flag=%x\n",flag);
            }}
  else{va[0]=error_opening_source;va[1]=INPUT->offset[a[0]-INPUT_string];
    Xwarning(9,0,2,va);par[0]=STACKpar(INPUT);par[1]=a[0];next(par);
    a[0]=par[1];goto again;}
//printf("*** next input, p=");par[0]=pgtProto;getPragmatValue(par);printf("%d ***\n",par[1]);
  return 1;
}
void readSources(void){
  int par[4]; int ptr,cnt;
  initProgramArgs();ptr=INPUT->alwb;cnt=0;
  par[0]=pgtLibrary;par[1]=0;setPragmatValue(par);resetPragmats();
//printf(" *** readSources, p=");par[0]=pgtProto;getPragmatValue(par);printf("%d **\n",par[1]);
  nxt:
  par[0]=ptr;if(nextInput(par)){ptr=par[0];nextSymbol();
    passI();closeSource();resetPragmats();par[0]=pgtLibrary;
    par[1]=0;setPragmatValue(par);cnt++;goto nxt;}
  if(cnt>0){;}
  else{par[0]=no_input_file;Xerror(0,1,par);}
}
void readStdlib(void){
  int par[4];int ptr;
  par[0]=pgtStdlib;getPragmatValue(par);if(par[1]==0){;}
  else{
    par[1]=library;par[0]=stdlibFile;addSource(par);ptr=INPUT->aupb;
    resetPragmats();par[0]=pgtLibrary;par[1]=1;setPragmatValue(par);nxt:
    if((par[0]=ptr,nextInput(par))){ptr=par[0];nextSymbol();passI();
      closeSource();resetPragmats();par[0]=pgtLibrary;par[1]=1;
      setPragmatValue(par);goto nxt;}
    else{getLinenum(par);lastLinenum=par[0];resetPragmats();}}
}


/* EOF */
