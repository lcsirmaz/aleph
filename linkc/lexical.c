/* lexical.ale main file */
#include "stddata.h"
#include "lexical.h"
#include "error.h"
#include "item.h"
#include <limits.h> /* INT_MAX */

/* exported variables */
int inpt=0,inptValue=0,sourceLine=1;

/* prototypes */
static void nextChar(void),enterString(int *a),rehash(void);
/* other stuff */
static void extendBUFFER(int *a){
  int par[3];par[0]=STACKpar(BUFFER);par[1]=1;par[2]=a[0];
  expandstack(par);
}
void tryToOpenSource(int *a){/* >res */
  int par[4];
  par[0]=CHFILEpar(SOURCE);par[1]='r';par[2]=STACKpar(LEXT);
  par[3]=LEXT->aupb;if(openFile(par)){a[0]=0;sourceLine=1;nextChar();nextSymbol();return;}
  par[0]=CHFILEpar(SOURCE);getFileError(par);if(par[1]==2){a[0]=1;}else{a[0]=-1;}
}
void closeSource(void){
  int par[2];
  par[0]=CHFILEpar(SOURCE);closeFile(par);
}

static int Achar=' ';
#define endChar	1
static void nextChar(void){
  int par[2];nxt:
  par[0]=CHFILEpar(SOURCE);
  if(Agetchar(par)){Achar=par[1];
    if(Achar==newline){sourceLine++;}
    else if(Achar<=31){goto nxt;}}
  else{Achar=endChar;}
}
/* ----------------------------------------- */
static int lastFilepos,lastChar,lastInpt,lastInptValue;
void saveInputPosition(void){
  int par[2];par[0]=CHFILEpar(SOURCE);getFilePos(par);lastFilepos=par[1];
  lastChar=Achar;lastInpt=inpt;lastInptValue=inptValue;
}
void restoreInputPosition(void){
  int par[2];par[0]=CHFILEpar(SOURCE);par[1]=lastFilepos;setFilePos(par);
  Achar=lastChar;inpt=lastInpt;inptValue=lastInptValue;
}
/* ----------------------------------------- */
static int boldLetter(int *a){
  if('a'<=Achar&&Achar<='z'){a[0]=Achar;nextChar();return 1;}
  else{return 0;}
}
static int digit(int *a){
  if('0'<=Achar&&Achar<='9'){a[0]=Achar-'0';nextChar();return 1;}
  return 0;
}
static int hexDigit(int *a){
  if('0'<=Achar&&Achar<='9'){a[0]=Achar-'0';nextChar();return 1;}
  else if('a'<=Achar&&Achar<='f'){a[0]=Achar-'a'+10;nextChar();return 1;}
  else if('A'<=Achar&&Achar<='F'){a[0]=Achar-'A'+10;nextChar();return 1;}
  else return 0;
}
static void comment(void){
  nxt:if(Achar==newline||Achar==endChar){;}
  else{nextChar();goto nxt;}
}
/* ------------------------------------------ */
static void readIndex(int *a){/* >sign+x> */
  int par[3];
  if(digit(par) && (par[0]>0||a[1]==0)){a[1]=par[0];}
  else{corruptedIceFile(__FILE__,__LINE__);}
  nxt:if(digit(par)){a[1]=a[1]*10+par[0];goto nxt;}
  else if(a[0]){a[1]=0-a[1];}
}
static void readMinus(int *a){/* x> + y> */
  int par[2];
  if('0'<Achar&&Achar<='9'){a[0]=Tconst;
    par[0]=1;readIndex(par);a[1]=par[1];}
  else{a[0]=Dminus;a[1]=0;}
}
static void readHex(int *a){ /* x> */
  int par[1]; a[0]=0;
  nxt:if(hexDigit(par)){a[0]<<=4;a[0]|=par[0];goto nxt;}
}
static void readZero(int *a){/* x> */
   int par[2];
   nextChar();if('0'<=Achar&&Achar<='9'){par[0]=0;readIndex(par);a[0]=par[1];}
   else if(Achar=='x'||Achar=='X'){readHex(a);}
   else{a[0]=0;}
}
static void readDestination(int *a){ /* x> */
   int par[2];
   if(Achar=='N'){nextChar();par[0]=0;readIndex(par);a[0]=par[1];}
   else if(Achar=='0'){nextChar();a[0]=0;}
   else if(Achar=='-'){nextChar();par[0]=1;readIndex(par);a[0]=par[1];}
   else{corruptedIceFile(__FILE__,__LINE__);}
}
/* strings */
int Squoteimage;
#define HASHincrement	512
static int HASHsize=(HASHincrement-1),
           HASHentries=1;

static void init_LEXT(void){
  int par[4];
  add_new_string("",LEXT);par[0]=STACKpar(LEXT);par[1]=2;par[2]=par[3]=0;
  expandstack(par);Squoteimage=LEXT->aupb;
}
/* ------------- */
void getTagData(int *a){/* >tag+def> */
  a[1]=LEXT->offset[a[0]-LEXT_def];
}
void getTagImage(int *a){ /* >tag+ptr> */
  a[1]=a[0]-LEXT_CALIBRE;
}
void putTagData(int *a){/* >tag +>def */
  LEXT->offset[a[0]-LEXT_def]=a[1];
}
void addLEXTentry(int *a){/* x> */
 int par[4];
 par[0]=STACKpar(LEXT);par[1]=2;par[2]=par[3]=0;expandstack(par);
 par[0]=LEXT->aupb;enterString(par);a[0]=par[1];if(a[0]==LEXT->aupb){;}
 else{par[0]=STACKpar(LEXT);unstack(par);unstackstring(par);}
}
static void enterString(int *a){/* >ptr + out> */
  int par[5];int string,hash,ptr2,string2;
  string=a[0]-LEXT_CALIBRE;par[0]=STACKpar(LEXT);par[1]=string;
  simplehash(par);hash=par[2]&INT_MAX;hash=hash % HASHsize;
  if(hash<0){printf(" *** mod =%d<0",hash);exit(7);}
  hash+=HASH->alwb;ptr2=HASH->offset[hash];nxt:
  if(ptr2==0){LEXT->offset[a[0]-LEXT_next]=HASH->offset[hash];
     a[1]=HASH->offset[hash]=a[0];HASHentries++;
     if(HASHentries<HASHsize){;}
     else{HASHsize+=HASHincrement;rehash();}}
  else{string2=ptr2-LEXT_CALIBRE;par[0]=STACKpar(LEXT);par[1]=string;
//if(LEXT->offset[string2]>30){printf("%d=(%d,%d), HASH=%d\n",ptr2,LEXT->offset[ptr2],LEXT->offset[ptr2-1],HASH->offset[hash]);exit(88);}
     par[2]=STACKpar(LEXT);par[3]=string2;comparestring(par);
     if(par[4]==0){a[1]=ptr2;}
     else{ptr2=LEXT->offset[ptr2-LEXT_next];goto nxt;}}
}
static void rehash(void){
  int par[4];int ptr,block;
  HASHentries=0;ptr=HASH->aupb;nxt1:if(ptr<HASH->alwb){;}
  else{HASH->offset[ptr]=0;ptr-=HASH_CALIBRE;goto nxt1;}
  block=HASH->aupb-HASH->alwb+1;
  nxt2:if(block>=HASHsize){;}
  else{par[0]=STACKpar(HASH);par[1]=1;par[2]=0;expandstack(par);
    block++;goto nxt2;}
  ptr=LEXT->aupb;nxt3:if(ptr<=LEXT->alwb){;}
  else{par[0]=ptr;enterString(par);block=par[1];
   if(block==ptr){par[0]=STACKpar(LEXT);par[1]=ptr;previous(par);
      previousstring(par);ptr=par[1];goto nxt3;}
   else{printf("rehash: block!=ptr, aborting\n");exit(10);}}
}
static void readString(int *a){/* x> */
  int par[3];int n,obuff;
  obuff=BUFFER->aupb;n=0;nxt:
  nextChar();if(Achar=='"'){nextChar();if(Achar=='"'){
     par[0]=Achar;extendBUFFER(par);n++;goto nxt;}
     else if(n==0){a[0]=Squoteimage;}
     else{par[0]=STACKpar(BUFFER);par[1]=n;par[2]=STACKpar(LEXT);
       packstring(par);par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
       addLEXTentry(par);a[0]=par[0];}}
  else if(Achar==newline||Achar==endChar){corruptedIceFile(__FILE__,__LINE__);}
  else{par[0]=Achar;extendBUFFER(par);n++;goto nxt;}
}
/* BOLD ---------------------------------------- */
static int firstBOLD,lastBOLD,firstTYPE,lastTYPE;
int Darea,Dbox,Dcalibre,Dexpression,Dextension,Dfile,Dfill,
   Dlist,Dlwb,Dnode,Drule,Dto,Dupb,Dvlwb,Dvupb,
   Dmodule,Dtitle,
   Dand,Dbus,Dclose,Dcolon,Dcomma,Dcompl,Ddiv,Dminus,Dnoarg,
   Dopen,Dor,Dout,Dplus,Dpoint,Dsemicolon,Dstar,Dsub,Dxor,
   Dend,Tconst,Ttype,Tnode,Titem,Tformal,Tlocal,Tstring,
   Iconstant,Ivariable,IstaticVar,Itable,Istack,IstaticStack,
   IpointerConstant,Icharfile,Idatafile,Irule,
   IformalStack,IformalTable,IformalFile,IformalIn,
   IformalOut,IformalInout,IformalRepeat,IformalShift;

#define addBOLD(x,y)	add_new_string(x,BOLD);y=BOLD->aupb
static void init_BOLD(void){
  addBOLD("area",Darea);firstBOLD=Darea;
  addBOLD("box",Dbox);
  addBOLD("calibre",Dcalibre);
  addBOLD("expression",Dexpression);
  addBOLD("extension",Dextension);
  addBOLD("file",Dfile);
  addBOLD("fill",Dfill);
  addBOLD("list",Dlist);
  addBOLD("lwb",Dlwb);
  addBOLD("module",Dmodule);
  addBOLD("node",Dnode);
  addBOLD("rule",Drule);
  addBOLD("title",Dtitle);
  addBOLD("to",Dto);
  addBOLD("upb",Dupb);
  addBOLD("vlwb",Dvlwb);
  addBOLD("vupb",Dvupb);lastBOLD=Dvupb;
/* types */
  addBOLD("constant",Iconstant);firstTYPE=Iconstant;
  addBOLD("variable",Ivariable);
  addBOLD("static var",IstaticVar);
  addBOLD("table",Itable);
  addBOLD("stack",Istack);
  addBOLD("static stack",IstaticStack);
  addBOLD("pointer constant",IpointerConstant);
  addBOLD("charfile",Icharfile);
  addBOLD("datafile",Idatafile);
  addBOLD("rule",Irule);
  addBOLD("formal stack",IformalStack);
  addBOLD("formal table",IformalTable);
  addBOLD("formal file",IformalFile);
  addBOLD("formal in",IformalIn);
  addBOLD("formal out",IformalOut);
  addBOLD("formal inout",IformalInout);
  addBOLD("formal repeat",IformalRepeat);
  addBOLD("formal shift",IformalShift);lastTYPE=IformalShift;
/* chars */
  addBOLD("&",Dand);
  addBOLD("]",Dbus);
  addBOLD(")",Dclose);
  addBOLD(":",Dcolon);
  addBOLD(",",Dcomma);
  addBOLD("~",Dcompl);
  addBOLD("/",Ddiv);
  addBOLD("-",Dminus);
  addBOLD("#",Dnoarg);
  addBOLD("(",Dopen);
  addBOLD("|",Dor);
  addBOLD(">",Dout);
  addBOLD("+",Dplus);
  addBOLD(".",Dpoint);
  addBOLD(";",Dsemicolon);
  addBOLD("*",Dstar);
  addBOLD("[",Dsub);
  addBOLD("^",Dxor);
/* internal */
  addBOLD("const",Tconst);
  addBOLD("type",Ttype);
  addBOLD("node",Tnode);
  addBOLD("item",Titem);
  addBOLD("formal",Tformal);
  addBOLD("local",Tlocal);
  addBOLD("string",Tstring);
  addBOLD("***",Dend);
}

static void readBold(int *a){ /* x> */
  int par[5];int n,obuff;
  nextChar();obuff=BUFFER->aupb;n=0;nxt:
  if(boldLetter(par)){extendBUFFER(par);n++;goto nxt;}
  else if(Achar=='\''){nextChar();}
  else{corruptedIceFile(__FILE__,__LINE__);}
  par[0]=STACKpar(BUFFER);par[1]=n;par[2]=STACKpar(LEXT);
  packstring(par);par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
  a[0]=lastBOLD;nxt2:
  par[0]=STACKpar(BOLD);par[1]=a[0];par[2]=STACKpar(LEXT);par[3]=LEXT->aupb;
  comparestring(par);if(par[4]==0){;}
  else if(a[0]==firstBOLD){corruptedIceFile(__FILE__,__LINE__);}
  else{par[0]=STACKpar(BOLD);par[1]=a[0];previousstring(par);a[0]=par[1];goto nxt2;}
  par[0]=STACKpar(LEXT);unstackstring(par);
}
/* types */
static void readType(int *a){ /* x> */
  int par[5];int n,obuff;
  nextChar();obuff=BUFFER->aupb;n=0;nxt:
  if(boldLetter(par)){extendBUFFER(par);n++;goto nxt;}
  else if(Achar==' '){par[0]=' ';extendBUFFER(par);n++;nextChar();goto nxt;}
  else if(Achar=='>'){nextChar();}
  else{corruptedIceFile(__FILE__,__LINE__);}
  par[0]=STACKpar(BUFFER);par[1]=n;par[2]=STACKpar(LEXT);
  packstring(par);par[0]=STACKpar(BUFFER);par[1]=obuff;unstackto(par);
  a[0]=lastTYPE;nxt2:
  par[0]=STACKpar(BOLD);par[1]=a[0];par[2]=STACKpar(LEXT);par[3]=LEXT->aupb,
  comparestring(par);if(par[4]==0){;}
  else if(a[0]==firstTYPE){
//printf("type: ");for(n=BUFFER->alwb;n<=BUFFER->aupb;n++){printf("%c",BUFFER->offset[n]);}printf("\n");
      corruptedIceFile(__FILE__,__LINE__);}
  else{par[0]=STACKpar(BOLD);par[1]=a[0];previousstring(par);a[0]=par[1];goto nxt2;}
  par[0]=STACKpar(LEXT);unstackstring(par);
}
/* READ ----------------------------------- */
int inpt,inptValue;

void nextSymbol(void){
  int par[3];
//printf("<%d,%d>\n",inpt,inptValue);
  nxt:
  if(Achar==' '||Achar==newline){nextChar();goto nxt;}
  if(Achar=='$'){comment();goto nxt;}
  if(Achar=='0'){inpt=Tconst;readZero(par);inptValue=par[0];}
  else if('1'<=Achar&&Achar<='9'){inpt=Tconst;par[0]=0;readIndex(par);inptValue=par[1];}
  else if(Achar=='F'){inpt=Tformal;nextChar();par[0]=0;readIndex(par);inptValue=par[1];}
  else if(Achar=='I'){inpt=Titem;nextChar();par[0]=0;readIndex(par);inptValue=par[1];convertToItem();}
  else if(Achar=='L'){inpt=Tlocal;nextChar();par[0]=0;readIndex(par);inptValue=par[1];}
  else if(Achar=='N'){inpt=Tnode;nextChar();par[0]=0;readIndex(par);inptValue=par[1];}
  else if(Achar=='\''){readBold(par);inpt=par[0];}
  else if(Achar=='<'){inpt=Ttype;readType(par);inptValue=par[0];}
  else if(Achar=='"'){inpt=Tstring;readString(par);inptValue=par[0];}
  else if(Achar=='&'){inpt=Dand;nextChar();}
  else if(Achar==']'){inpt=Dbus;nextChar();}
  else if(Achar==')'){inpt=Dclose;nextChar();}
  else if(Achar==':'){inpt=Dcolon;nextChar();}
  else if(Achar==','){inpt=Dcomma;nextChar();}
  else if(Achar=='~'){inpt=Dcompl;nextChar();}
  else if(Achar=='/'){inpt=Ddiv;nextChar();}
  else if(Achar=='-'){nextChar();readMinus(par);inpt=par[0];inptValue=par[1];}
  else if(Achar=='#'){inpt=Dnoarg;nextChar();}
  else if(Achar=='('){inpt=Dopen;nextChar();}
  else if(Achar=='|'){inpt=Dor;nextChar();}
  else if(Achar=='>'){inpt=Dout;nextChar();readDestination(par);inptValue=par[0];}
  else if(Achar=='+'){inpt=Dplus;nextChar();}
  else if(Achar=='.'){inpt=Dpoint;nextChar();}
  else if(Achar==';'){inpt=Dsemicolon;nextChar();}
  else if(Achar=='*'){inpt=Dstar;nextChar();}
  else if(Achar=='['){inpt=Dsub;nextChar();}
  else if(Achar=='^'){inpt=Dxor;nextChar();}
  else if(Achar==endChar){inpt=Dend;}
  else{corruptedIceFile(__FILE__,__LINE__);}
}


void initialize_lexical(void){
  init_LEXT();init_BOLD();
//  rehash();
}
void rehash_lexical(void){rehash();}


/* EOF */

