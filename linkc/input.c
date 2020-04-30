/* input.ale */
#include "stddata.h"
#include "input.h"
#include "error.h"
#include "lexical.h"

static int no_input,opening_source;

#define addMSG(x,y)  add_new_string(x,MESSAGE);y=MESSAGE->aupb
void init_MSG(void){
  addMSG("no input file was specified",no_input);
  addMSG("error opening file %p",opening_source);
}
#undef addMSG

static int argPtr=0,withExtension=0;
static void extendBUFFER(int x){
  int par[4];
  par[0]=STACKpar(BUFFER);par[1]=1;par[2]=x;expandstack(par);
}
static void addExtension(void){
  int par[3];
  par[0]=STACKpar(BUFFER);scratch(par);par[0]=STACKpar(STDARG);
  par[1]=argPtr;par[2]=STACKpar(BUFFER);unpackstring(par);
  extendBUFFER('.');extendBUFFER('i');
  extendBUFFER('c');extendBUFFER('e');
  par[0]=STACKpar(BUFFER);listlength(par);par[2]=STACKpar(LEXT);
  packstring(par);par[0]=STACKpar(BUFFER);scratch(par);
}
static int nextArgument(void){
  int par[3];
  if(argPtr==0){argPtr=STDARG->aupb;return 1;}
  else if(argPtr>=STDARG->alwb){par[0]=STACKpar(STDARG);par[1]=argPtr;
    previousstring(par);argPtr=par[1];
    if(argPtr>=STDARG->alwb){return 1;}else{return 0;}}
  return 0;
}  
static void openAsItIs(int *a){/* res> */
  int par[3];
  withExtension=1;par[0]=STACKpar(STDARG);par[1]=argPtr;par[2]=STACKpar(LEXT);
  copystring(par);tryToOpenSource(par);a[0]=par[0];par[0]=STACKpar(LEXT);
  unstackstring(par);
}
static void openWithExtension(int *a){/* res> */
  int par[2];
  withExtension=2;addExtension();tryToOpenSource(par);a[0]=par[0];
  par[0]=STACKpar(LEXT);unstackstring(par);
}
static void openArgument(int *a){/* >how */
  int par[2];int res;
//printf("opening ... ");par[0]=argPtr;printPointer(par);printf("\n");
  if(a[0]==1){openAsItIs(par);res=par[0];}
  else if(a[0]==2){openWithExtension(par);res=par[0];}
  else{openAsItIs(par);res=par[0];if(res!=0){openWithExtension(par);res=par[0];}}
  if(res==0){;}else{par[0]=opening_source;par[1]=argPtr;Ferror(2,par);}
}
int nextSource(int *a){/* >how + ext> */
  int par[3];
  if(STDARG->aupb<STDARG->alwb){par[0]=no_input;Ferror(1,par);return 0;}
  if(nextArgument()){closeSource();par[0]=a[0];openArgument(par);
    a[1]=withExtension;return 1;}
  closeSource();argPtr=0;return 0;
}
void getObjFile(int *a){ /* ptr> */
  a[0]=argPtr;
}
void cleanUp(void){
  closeSource();
}
/* ---------------------------------------------------------- */

void initialize_input(void){
  init_MSG();
}

/* EOF */

