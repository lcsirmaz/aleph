/* passi.ale */

#include "stddata.h"
#include "passi.h"
#include "display.h"
#include "lexical.h"
#include "symbols.h"
#include "tags.h"
#include "pragmats.h"
#include "lists.h"
#include "rules.h"
#include "vars.h"
#include "files.h"
#include "rulebody.h"

/* ---------------------------------------------------- */
/* messages */
static int
wrong_symbol,external_in_library_mode,more_than_one_root,no_root,
library_item_redefined;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_messages(void){
  addMSG("misplaced symbol %p",wrong_symbol);
  addMSG("'external' can be used in library mode only",external_in_library_mode);
  addMSG("more than one 'root'",more_than_one_root);
  addMSG("no 'root'",no_root);
  addMSG("%p %p: library item redefined (%l)",library_item_redefined);
}
#undef addMSG

/* ---------------------------------------------------- */
static int declaration(int *a);
static void tagEnquiry(void);
static void externalDeclaration(void);
static void staticDeclaration(void);
static void root(void);

static int rootScanned=0;
void wasRootScanned(void){
  int par[2];
  if(rootScanned){;}else{par[0]=no_root;Xerror(0,1,par);}
}

void passI(void){
  int par[3];int err; nxt:
  if(ahead(Sendsymb)){return;}
  par[0]=Spragsymb;if(R(par)){programPragmat(par);err=par[0];
    if(err==2){return;}
    if(err==1){skipToPoint();}
    goto nxt;}
  par[0]=pgtSkip;if(isPragmatValue(par)){
    skipSilently();par[0]=Spoint;Rskip(par);goto nxt;}
  par[0]=0;if(declaration(par)){ goto nxt; }
  par[0]=Sstatic;if(R(par)){staticDeclaration(); goto nxt;}
  par[0]=Srootsymb;if(R(par)){root();goto nxt;}
  par[0]=Senquiry;if(R(par)){tagEnquiry();goto nxt;}
  par[0]=Sextsymb;if(R(par)){externalDeclaration();goto nxt;}
  par[0]=Sdummysymb;if(R(par)){skipToPoint(); goto nxt;}
  par[0]=wrong_symbol;par[1]=inpt;Error(2,par);skipToPoint();goto nxt;
}

static void tagEnquiry(void){
  int par[4];int tag,z,type;
  par[0]=pgtLibrary;if(isPragmatValue(par) && isRawTag(par)){
    tag=par[0];findRawUsage(par);
    if(par[1]==0){skipSilently();par[0]=Spoint;Rskip(par);}
    else if(par[1]==2){par[0]=tag;getTagEntry(par);tag=par[1];
      par[0]=tag;getDefline(par);z=par[1];par[0]=tag;getType(par);
      type=par[1];getLinenum(par);
      par[3]=par[0];par[0]=library_item_redefined;par[1]=type;
      par[2]=tag;Xwarning(8,z,4,par);skipSilently();par[0]=Spoint;
      Rskip(par);}}
  else{par[0]=wrong_symbol;par[1]=Senquiry;Error(2,par);
    skipToPoint();}
}
static int declaration(int *a){ /* >ext */
  int par[3];
  if(par[0]=Stablesymb,R(par)){par[0]=a[0];tableDeclaration(par);}
  else if(par[0]=Sstacksymb,R(par)){par[0]=a[0];stackDeclaration(par);}
  else if(par[0]=Svarsymb,R(par)){par[0]=a[0];variableDeclaration(par);}
  else if(par[0]=Sconssymb,R(par)){par[0]=a[0];constantDeclaration(par);}
  else if(par[0]=Scharfile,R(par)){par[0]=a[0];charfileDeclaration(par);}
  else if(par[0]=Sdatafile,R(par)){par[0]=a[0];datafileDeclaration(par);}
  else if(par[0]=Saction,R(par)){ par[0]=raction;par[1]=a[0];
    ruleDeclaration(par);}
  else if(par[0]=Sfunction,R(par)){par[0]=rfunc;par[1]=a[0];
    ruleDeclaration(par);}
  else if(par[0]=Squestion,R(par)){par[0]=rque;par[1]=a[0];
    ruleDeclaration(par);}
  else if(par[0]=Spredicate,R(par)){par[0]=rpred;par[1]=a[0];
    ruleDeclaration(par);}
  else if(par[0]=Sexit,R(par)){par[0]=rexit;par[1]=a[0];
    ruleDeclaration(par);}
  else{ return 0;}
//DEBUG
if(ahead(Spoint)){printf("declaration left trailing point\n");}
  return 1;
}
static void externalDeclaration(void){
  int par[2];
  par[0]=pgtLibrary;if(isPragmatValue(par)){par[0]=1;
    if(declaration(par)){;}
    else if(par[0]=Sdummysymb,R(par)){skipToPoint();}
    else{par[0]=wrong_symbol;par[1]=inpt;Error(2,par);skipToPoint();}}
  else{par[0]=external_in_library_mode;Error(1,par);skipToPoint();}
}
static void staticDeclaration(void){
  int par[2];
  if(par[0]=Svarsymb,R(par)){staticVariableDeclaration();}
  else if(par[0]=Sstacksymb,R(par)){staticStackDeclaration();}
  else if(par[0]=Sdummysymb,R(par)){skipToPoint();}
  else{par[0]=wrong_symbol;par[1]=inpt;Error(2,par);skipToPoint();}
}
static void root(void){
  int par[2];
  if(rootScanned){par[0]=more_than_one_root;Error(1,par);
    skipToPoint();}
  else{rootScanned=1;rootBody();}
}

/* ---------------------------------------------------- */
void initialize_passi(void){
  init_messages();
  rootScanned=0;
}

/* EOF */

