/* lexical.ale  main file */

#include "stddata.h" // stacks, files, etc
#include "lexical.h"
#include "display.h"
#include "pragmats.h"
#include "tags.h"

/* exported variables */
int // pointers to SPECIAL
  Saction,      Sarrow,         Sasterisk,      Sbooland,
  Sboolor,      Sboolxor,       Sbox,           Sbus,
  Scalibre,     Scharfile,      Sclose,
  Scolon,       Scomplement,    Scomma,
  Sconssymb,    Sdatafile,      Sdummysymb,	Sendsymb,
  Senquiry,     Seol,           Sequals,        Sexit,
  Sextsymb,     Sfunction,      Sless,          Slseq,
  Slwb,         Sminus,         Smore,          Smreq,
  Snoarg,       Snotequal,      Sopen,
  Splus,        Spoint,         Spredicate,     Spragsymb,
  Squestion,    Sright,         Srootsymb,
  Ssemicolon,   Sslash,         Sstacksymb,     Sstatic,
  Ssub,         Stablesymb,
  Supb,         Svarsymb,       Svlwb,		Svupb;
int // pointer to LEXT, empty string; linking string
  Squoteimage;

/* initalization */
#define addSPEC(x,y)	add_new_string(x,SPECIAL);y=SPECIAL->aupb
static void init_SPECIAL_table(void){
  addSPEC("<dummy>",Sdummysymb);
  addSPEC("'end'",Sendsymb);
  addSPEC("'action'",Saction);
  addSPEC("->",Sarrow);
  addSPEC("*",Sasterisk);
// Sboolor,Sbooland,Sboolxor must come in this order for priority
  addSPEC("|",Sboolor);
  addSPEC("&",Sbooland);
  addSPEC("^",Sboolxor);
  addSPEC("=",Sbox=Sequals);
  addSPEC("]",Sbus);
  addSPEC("<>",Scalibre);
  addSPEC("'charfile'",Scharfile);
  addSPEC(")",Sclose);
  addSPEC(":",Scolon);
  addSPEC("~",Scomplement);
  addSPEC(",",Scomma);
  addSPEC("'constant'",Sconssymb);
  addSPEC("'datafile'",Sdatafile);
  addSPEC("?",Senquiry);
  addSPEC("\\n",Seol);
  addSPEC("'exit'",Sexit);
  addSPEC("'external'",Sextsymb);
  addSPEC("'function'",Sfunction);
  addSPEC("<",Sless=Svlwb);
  addSPEC("<=",Slseq);
  addSPEC("<<",Slwb);
  addSPEC("-",Sminus);
  addSPEC(">",Smore=Sright=Svupb);
  addSPEC(">=",Smreq);
  addSPEC("#",Snoarg);
  addSPEC("!-",Snotequal);
  addSPEC("(",Sopen);
  addSPEC("+",Splus);
  addSPEC(".",Spoint);
  addSPEC("'predicate'",Spredicate);
  addSPEC("'pragmat'",Spragsymb);
  addSPEC("'question'",Squestion);
  addSPEC("'root'",Srootsymb);
  addSPEC(";",Ssemicolon);
  addSPEC("/",Sslash);
  addSPEC("'stack'",Sstacksymb);
  addSPEC("'static'",Sstatic);
  addSPEC("[",Ssub);
  addSPEC("'table'",Stablesymb);
  addSPEC(">>",Supb);
  addSPEC("'variable'",Svarsymb);
}
#undef addSPEC

static int constZero;
static void init_CONST_stack(void){
   int par[3];
   par[0]=STACKpar(CONST);par[1]=1;
   par[2]=0;expandstack(par);constZero=CONST->aupb;
   par[2]=1;expandstack(par);
}
static void init_BOLD_table(void); // to be defined later
static void init_LEXT_stack(void){
   add_new_string("",LEXT); Squoteimage=LEXT->aupb;
}

/* ---------------------------------------------- */
//'a' enter const+>v+ptr>
static void enterConst(int *a){
  int par[3];int cnt;
  cnt=0;a[1]=CONST->alwb;a[1]++;nxt:
  if(CONST->aupb>a[1]){par[0]=STACKpar(CONST);par[1]=a[0];extend(par);a[1]=CONST->aupb;}
  else if(CONST->offset[a[1]]==a[0]){;}
  else if(cnt>100){par[0]=STACKpar(CONST);par[1]=a[0];extend(par);a[1]=CONST->aupb;}
  else{cnt++;a[1]++;goto nxt;}
}
//'p'was lexical pointer+>ptr+[]st[] 
int wasLexicalPointer(int *a){
  int par[3];
  par[0]=STACKpar(SPECIAL);par[1]=a[0];if(was(par)){
    par[0]=STACKpar(SPECIAL);par[1]=a[0];par[2]=a[1];copystring(par); return 1;}
  else{par[0]=STACKpar(LEXT);if(was(par)){
//printf("was LEXT pointer: %d, copy to %d",par[1],a[1]);
    par[0]=STACKpar(LEXT);par[1]=a[0];par[2]=a[1];copystring(par);return 1;}}
  return 0;
}
//'q'was lexical integer+>ptr+x>
int wasLexicalInteger(int *a){
  int par[2];par[0]=STACKpar(CONST);par[1]=a[0];if(was(par)){
    a[1]=CONST->offset[a[0]]; return 1;}
  return 0;
}
/* -------------------------------------------------------- */
/* local MESSAGEs */
static int hex_digit_expected,wrong_character_denotation,unterminated_string,
   unrecognized_bold,missing_bold_delimiter,illegal_character;

#define addMSG(x,y)	add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void init_MESSAGE_table(void){
  addMSG("hex digit expected after 0x",hex_digit_expected);
  addMSG("wrong character denotation",wrong_character_denotation);
  addMSG("unterminated string",unterminated_string);
  addMSG("unknown bold word '%p'",unrecognized_bold);
  addMSG("missing ' after '%p'",missing_bold_delimiter);
  addMSG("illegal character: %c",illegal_character);
}

void initialize_lexical(void){
   init_SPECIAL_table();
   init_CONST_stack();
   init_LEXT_stack();
   init_BOLD_table();  // uses values from SPECIAL table, should come later
   init_MESSAGE_table(); // each module adds its own messages
}

/* =========================================== */
static int tabWidth=8;		// tab width
static int giveText=0;		// text should be printed
static int LEXTptr=-1,LEXTcnt=0,LEXTlen=0;
static int Achar=' ';		// holds the next character
static int pchar=0;		// character position in this line
static int ppline=0;		// posponed fron string denoters
static int wasTab=0;		// tabular read
static int exhausted=-4;	// EOF indicator
static int optor=0;		// after ),],tag,digit,char denotation

#define tabChar	9
#define endChar	0x1234567

/* =========================================== */
// 'p' read char+char>
static int Areadchar(int *a){
  int par[4];
  if(LEXTptr>0){nxt:if(LEXTcnt==LEXTlen){a[0]='.';LEXTcnt++; return 1;}
       if(LEXTcnt>=LEXTlen){return 0; }
       par[0]=STACKpar(LEXT);par[1]=LEXTptr;par[2]=LEXTcnt;
            stringelem(par);a[0]=par[3];LEXTcnt++;if(a[0]==newline){goto nxt;}return 1;}
  else if(LEXTptr==0){par[0]=CHFILEpar(SOURCE); if(Agetchar(par)){a[0]=par[1]; return 1;}}
  return 0;
}
// 'a' next char
static void nextChar(void){
  int par[4]; int show;
  if(giveText!=0 && exhausted<-2){show=1;}else{show=0;}
  par[0]=Achar;par[1]=show;displayChar(par);
nxt:
  if(wasTab>0){wasTab--;Achar=' ';pchar++;}
  else if(Areadchar(par)){Achar=par[0];pchar++;
    if(Achar==newline){pchar=0;par[0]=pgtText;getPragmatValue(par);
       giveText=par[1];par[0]=pgtTabwidth;getPragmatValue(par);
       tabWidth=par[1];}
    else if(Achar==tabChar){Achar=' ';wasTab=tabWidth-1-((pchar-1)%tabWidth);}
    else if(Achar<=31){goto nxt;}}  
  else if(exhausted<-2){exhausted++; Achar=newline;}
  else{Achar=endChar;}
}
//'p/ bold letter +x>:
static int boldLetter(int *a){
  if('a'<=Achar && Achar<='z'){a[0]=Achar;nextChar(); return 1;}
  return 0;
}
// 'p' digit+x>
static int digit(int *a){int par[3];
again:
  if(Achar==' '){nextChar(); goto again; }
  else if('0'<=Achar && Achar<='9'){par[0]=Achar;par[1]='0';subtr(par);a[0]=par[2];
    nextChar(); return 1;}
  return 0;
}
//'p'hex digit+x>
static int hexdigit(int *a){
again:
  if(Achar==' '){nextChar(); goto again;}
  else if('0'<=Achar&& Achar<='9'){a[0]=Achar-'0'; nextChar(); }
  else if('a'<=Achar && Achar<='f'){a[0]=Achar-'a'+10; nextChar(); }
  else if('A'<=Achar && Achar<='F'){a[0]=Achar-'A'+10; nextChar(); }
  else { return 0; }
  return 1;
}
//'p'letgit+x>
static int letgit(int *a){int par[1];
again:
  if(Achar==' '){nextChar(); goto again;}
  if(('A'<=Achar && Achar<='Z')||('a'<=Achar && Achar<='z') || ('0'<=Achar && Achar<='9')){
     a[0]=Achar;nextChar(); }
  else if(Achar=='@'){par[0]=pgtLibrary;if(isPragmatValue(par)){a[0]=Achar;nextChar();}
        else{return 0;}}
  else{return 0;}
  return 1;
}
//'a' next visible char
static void nextVisibleChar(void){
again:
  if(Achar==' '){nextChar();goto again;}
  else if(Achar==newline){ppline++;nextChar();goto again;}
}
/******************************************************************/
//'a'try opening+>str+res>
static void tryOpening(int *a){
   int par[4];
//printf("try open: ");par[0]=a[0];printPointer(par);printf("\n");
   par[0]=CHFILEpar(SOURCE);par[1]='r';par[2]=STACKpar(LEXT);par[3]=a[0];
   if(openFile(par)){a[1]=0;return;}
   par[0]=CHFILEpar(SOURCE);getFileError(par);if(par[1]==2){a[1]=1;}
     else{a[0]=-1;}
}
//'a'add extension
static void addExtension(void){
  int par[2];
  par[0]=STACKpar(BUFFER);par[1]='.';extend(par);par[1]='a';extend(par);
  par[1]='l';extend(par);par[1]='e';extend(par);
}
//'a'try next path+>ptr>+>str+>res>
static void tryNextPath(int *a){
  int par[4];int n,nn,last;
//printf("try next path %d, %d, %d\n",a[0],a[1],a[2]);
  n=BUFFER->aupb;last=':';nxt:if(BUFFER->offset[a[0]]==':'){;}
  else{last=BUFFER->offset[a[0]];a[0]++;par[0]=STACKpar(BUFFER);
    par[1]=last;extend(par);goto nxt;}
  if(last==':'){return;}
  if(last=='/'){;}else{par[0]=STACKpar(BUFFER);par[1]='/';extend(par);}
  par[0]=STACKpar(LEXT);par[1]=a[1];par[2]=STACKpar(BUFFER);unpackstring(par);
  nn=BUFFER->aupb-n;par[0]=STACKpar(BUFFER);par[1]=nn;par[2]=STACKpar(LEXT);
  packstring(par);par[0]=LEXT->aupb;tryOpening(par);a[2]=par[1];
  par[0]=LEXT->aupb;forgetString(par);if(a[2]<=0){par[0]=STACKpar(BUFFER);
   par[1]=n;unstackto(par);}else{addExtension();nn=BUFFER->aupb-n;
   par[0]=STACKpar(BUFFER);par[1]=nn;par[2]=STACKpar(LEXT);packstring(par);
   par[0]=LEXT->aupb;tryOpening(par);a[2]=par[1];par[0]=LEXT->aupb;
   forgetString(par);par[0]=STACKpar(BUFFER);par[1]=n;unstackto(par);}
}
//'a' try path+>str+>res>
static void tryPath(int *a){
  int par[4];int path,ptr,end;
  par[0]=pgtPath;getPragmatValue(par);path=par[1];
  if(path==0){return;}
//printf("tryPath (%d): ",a[1]);par[0]=path;printPointer(par);printf("\n");
  par[0]=STACKpar(BUFFER);scratch(par);par[0]=STACKpar(LEXT);
  par[1]=path;par[2]=STACKpar(BUFFER);unpackstring(par);
  par[0]=STACKpar(BUFFER);par[1]=':';extend(par);
  ptr=BUFFER->alwb;end=BUFFER->aupb;nxt:if(ptr>=end){;}
  else{par[0]=ptr;par[1]=a[0];par[2]=a[1];tryNextPath(par);ptr=par[0];a[1]=par[2];
  if(a[1]==1){ptr++;goto nxt;}} par[0]=STACKpar(BUFFER);scratch(par);
}
//'p'open source file+>type+>str
static int openSourceFile(int *a){ /* >type * >str */
  int par[4];int res,n;
  par[0]=a[1];tryOpening(par);res=par[1];
  if(res==1){par[0]=STACKpar(BUFFER);scratch(par);
    par[0]=STACKpar(LEXT);par[1]=a[1];par[2]=STACKpar(BUFFER);unpackstring(par);
    addExtension();par[0]=STACKpar(BUFFER);listlength(par);n=par[1];
    par[0]=STACKpar(BUFFER);par[1]=n;par[2]=STACKpar(LEXT);packstring(par);
    par[0]=STACKpar(BUFFER);scratch(par);par[0]=LEXT->aupb;tryOpening(par);
    res=par[1];par[0]=LEXT->aupb;forgetString(par);
    if(res==1 && a[0]==2){par[0]=a[1];par[1]=res;tryPath(par);res=par[1];}
  }
  if(res==0){return 1;}return 0;
}

//'p'next source + >type +>ptr:
int nextSource(int *a){
  int par[4];
  if(a[0]==0){LEXTptr=a[1];par[0]=STACKpar(LEXT);par[1]=LEXTptr;
    stringlength(par);LEXTlen=par[2];LEXTcnt=2;giveText=0;}
  else{par[0]=a[0];par[1]=a[1];if(openSourceFile(par)){
    LEXTptr=0;par[0]=pgtText;getPragmatValue(par);giveText=par[1];}
    else{return 0;}}
  pchar=0;par[0]=pgtTabwidth;getPragmatValue(par);tabWidth=par[1];
  exhausted=-4;ppline=0;wasTab=0;optor=0;resetPrLine(); // in display
  Achar=newline;nextChar();nextVisibleChar(); return 1;
}
//'a' close source
void closeSource(void){
   int par[3];
   if(LEXTptr>0){LEXTptr=-1;}
   else if(LEXTptr==0){
     par[0]=CHFILEpar(SOURCE);closeFile(par);LEXTptr=-1;}
}
//'a'create obj name
void createObjName(void){
   int par[3]; int ptr,n,nn;
   par[0]=pgtTitle;getPragmatValue(par);ptr=par[1];n=BUFFER->aupb;
   par[0]=STACKpar(LEXT);par[1]=ptr;par[2]=STACKpar(BUFFER);
   unpackstring(par);par[0]=STACKpar(BUFFER);par[1]='.';extend(par);
   par[1]='i';extend(par);par[1]='c';extend(par);par[1]='e';extend(par);
   nn=BUFFER->aupb-n;par[0]=STACKpar(BUFFER);par[1]=nn;
   par[2]=STACKpar(LEXT);packstring(par);par[0]=STACKpar(BUFFER);
   par[1]=n;unstackto(par);
}

/*=========================================================================*/
/* special symbols */

static void readMinusWithSpaces(int *a);
static void readZero(int *a),readConst(int *a),readHex(int *a);
static void enterConst(int *a);

//'a' read greater + >optor + x>
static void readGreater(int *a){
  if(a[0]){if(Achar=='='){nextChar(); a[1]=Smreq;}else{a[1]=Smore;}}
  else if(Achar=='>'){nextChar();a[1]=Supb;}
  else{a[1]=Svupb;}
}
//'a' read less+>optor+x>
static void readLess(int *a){
  if(a[0]){if(Achar=='='){nextChar();a[1]=Slseq;}else{a[1]=Sless;}}
  else if(Achar=='<'){nextChar();a[1]=Slwb;}
  else if(Achar=='>'){nextChar();a[1]=Scalibre;}
  else{a[1]=Svlwb;}
}
//'a' read minus+x>
static void readMinus(int *a){ int par[1];
  if(Achar=='>'){nextChar(); a[0]=Sarrow; }
  else if(Achar=='='){nextChar(); a[0]=Snotequal;}
  else{readMinusWithSpaces(par);a[0]=par[0];}
}
//'a' read minus with spaces+x>
static void readMinusWithSpaces(int *a){int par[3];
again:
  if(Achar==' '){nextChar(); goto again;}
  else if(Achar=='0'){nextChar();par[0]=1;readZero(par);a[0]=par[1];}
  else if('1'<=Achar && Achar<='9'){par[0]=1;readConst(par);a[0]=par[1];}
  else{a[0]=Sminus;}
}
//'a' read zero+>sign+x>
static void readZero(int *a){ /* >sign + x> */
  int par[2];
again:
  if(Achar==' '){nextChar(); goto again;}
  else if('0'<=Achar && Achar<='9'){par[0]=a[0];readConst(par);a[1]=par[1];}
  else if('x'==Achar||'X'==Achar){nextChar();par[0]=a[0];readHex(par);a[1]=par[1];}
  else {a[1]=constZero;}
}
//'a' read const+>sign+x>
static void readConst(int *a){
  int par[4]; int v,d;
  par[0]=Achar;par[1]='0';subtr(par);v=par[2];nextChar();
  nxt:if(digit(par)){d=par[0];par[0]=v;par[1]=10;par[2]=d;addmult(par);v=par[3];goto nxt;}
      else if(a[0]){par[0]=0;par[1]=v;subtr(par);v=par[2];}
      else {;}
      par[0]=v;enterConst(par);a[1]=par[1];
}
//'a'read hex + >sign + x>
static void readHex(int *a){
  int par[4]; int d,v;
  if(hexdigit(par)){v=par[0]; nxt:
     if(hexdigit(par)){d=par[0];par[0]=v;par[1]=4;leftclear(par);v=par[0];
        par[0]=v;par[1]=d;boolor(par);v=par[2];goto nxt;}
     else if(a[0]){par[0]=0;par[1]=v;subtr(par);v=par[2];}
     else{;}
     par[0]=v;enterConst(par);a[1]=par[1];}
  else{par[0]=hex_digit_expected;Error(1,par);a[1]=constZero;}
}
//'a' read char denotation+x>
static void readCharDenotation(int *a){
  int par[2]; int v;
  v=Achar; if(Achar==newline){par[0]=wrong_character_denotation;Error(1,par);}
    else{nextChar(); if(Achar=='/'){nextChar();}else{par[0]=wrong_character_denotation;Error(1,par);}}
  par[0]=v;enterConst(par);a[0]=par[1];
}
//'a' skip char denotation
static void skipCharDenotation(void){
  if(Achar==newline){;}
  else{nextChar(); if(Achar=='/'){nextChar();}}
}
//'a' read string+x>
static void readString(int *a){
  int n; int par[3];
  par[0]=STACKpar(BUFFER); scratch(par);n=0; nxt: nextChar();
  if(Achar=='"'){nextChar();
    if(Achar=='"'){par[0]=STACKpar(BUFFER);par[1]=Achar;extend(par);
      par[0]=n;incr(par);n=par[0];goto nxt;}
    else{nextVisibleChar();if(Achar=='"'){goto nxt;}
      else if(n==0){a[0]=Squoteimage;}
      else{par[0]=STACKpar(BUFFER);par[1]=n;par[2]=STACKpar(LEXT);
          packstring(par);a[0]=LEXT->aupb;}}}
  else if(Achar==newline||Achar==endChar){
    par[0]=unterminated_string;Error(1,par);a[0]=Squoteimage;}
  else{par[0]=STACKpar(BUFFER);par[1]=Achar;extend(par);par[0]=n;incr(par);n=par[0];goto nxt;}
}
//'a' skip string
static void skipString(void){
again:
  if(Achar=='"'){nextChar();}
  else if(Achar==newline||Achar==endChar){;}
  else{nextChar(); goto again; }
}
//'a' forget string
void forgetString(int *a){
  int par[1];
  if(a[0]==Squoteimage){;}
  else if(LEXT->aupb==a[0]){par[0]=STACKpar(LEXT); unstackstring(par);}
}
/* comments and layout */
//'a' long comment
static void longComment(void){
again:
  if(Achar==newline){;}
  else if(Achar=='$'){nextChar();}
  else{nextChar(); goto again;}
}
//'p' short comment
static int shortComment(void){
again:
  if(Achar==' '){nextChar(); goto again;}
  if(('A'<=Achar&&Achar<='Z')||('a'<=Achar&&Achar<='z')||('0'<=Achar&&Achar<='9')){
    nextChar();nxt:if(('A'<=Achar&&Achar<='Z')||('a'<=Achar&&Achar<='z')||
      ('0'<=Achar&&Achar<='9')||Achar==' '){nextChar(); goto nxt;}}
  else{return 0;}
  return 1;
}
/* -------------------------------------------------------------------*/
/* bold symbols */
static int B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11,B12,B13,B14,B15,firstBold,
  B17,B18,B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31;

#define addtoBOLD(x,y)	add_new_string(x,BOLD);y=BOLD->aupb

static void init_BOLD_table(void){
  int par[5];
  par[0]=STACKpar(BOLD);par[1]=3;par[2]=0;par[3]=0;par[4]=0;
  addtoBOLD("a",B1);		par[4]=Saction; expandstack(par);
  addtoBOLD("act",B2);		expandstack(par);
  addtoBOLD("action",B3);	expandstack(par);
  addtoBOLD("charfile",B4);	par[4]=Scharfile; expandstack(par);
  addtoBOLD("cons",B5);		par[4]=Sconssymb; expandstack(par);
  addtoBOLD("constant",B6);	expandstack(par);
  addtoBOLD("cst",B7);		expandstack(par);
  addtoBOLD("datafile",B8);	par[4]=Sdatafile; expandstack(par);
  addtoBOLD("e",B9);		par[4]=Sexit; expandstack(par);
  addtoBOLD("end",B10);		par[4]=Sendsymb; expandstack(par);
  addtoBOLD("exit",B11);	par[4]=Sexit; expandstack(par);
  addtoBOLD("external",B12);	par[4]=Sextsymb; expandstack(par);
  addtoBOLD("f",B13);		par[4]=Sfunction; expandstack(par);
  addtoBOLD("fct",B14);		expandstack(par);
  addtoBOLD("func",B15);	expandstack(par);
  addtoBOLD("function",firstBold);	expandstack(par);
  addtoBOLD("p",B17);		par[4]=Spredicate; expandstack(par);
  addtoBOLD("pragmat",B18);	par[4]=Spragsymb; expandstack(par);
  addtoBOLD("pred",B19);		par[4]=Spredicate; expandstack(par);
  addtoBOLD("predicate",B20);	expandstack(par);
  addtoBOLD("q",B21);		par[4]=Squestion; expandstack(par);
  addtoBOLD("qu",B22);		expandstack(par);
  addtoBOLD("que",B23);		expandstack(par);
  addtoBOLD("question",B24);	expandstack(par);
  addtoBOLD("root",B25);	par[4]=Srootsymb; expandstack(par);
  addtoBOLD("stack",B26);	par[4]=Sstacksymb; expandstack(par);
  addtoBOLD("static",B27);	par[4]=Sstatic; expandstack(par);
  addtoBOLD("table",B28);	par[4]=Stablesymb; expandstack(par);
  addtoBOLD("var",B29);		par[4]=Svarsymb; expandstack(par);
  addtoBOLD("variable",B30);	par[4]=Svarsymb; expandstack(par);
  addtoBOLD("x",B31);		par[4]=Sextsymb; expandstack(par);
  // links
  BOLD->offset[firstBold+1]=B8;	BOLD->offset[firstBold+2]=B24;
  BOLD->offset[B8+1]=B4;	BOLD->offset[B8+2]=B12;
  BOLD->offset[B4+1]=B2;	BOLD->offset[B4+2]=B6;
  BOLD->offset[B2+1]=B1;	BOLD->offset[B2+2]=B3;
  BOLD->offset[B6+1]=B5;	BOLD->offset[B6+2]=B7;
  BOLD->offset[B12+1]=B10;	BOLD->offset[B12+2]=B14;
  BOLD->offset[B10+1]=B9;	BOLD->offset[B10+2]=B11;
  BOLD->offset[B14+1]=B13;	BOLD->offset[B14+2]=B15;
  BOLD->offset[B24+1]=B20;	BOLD->offset[B24+2]=B28;
  BOLD->offset[B20+1]=B18;	BOLD->offset[B20+2]=B22;
  BOLD->offset[B18+1]=B17;	BOLD->offset[B18+2]=B19;
  BOLD->offset[B22+1]=B21;	BOLD->offset[B22+2]=B23;
  BOLD->offset[B28+1]=B26;	BOLD->offset[B28+2]=B30;
  BOLD->offset[B26+1]=B25;	BOLD->offset[B26+2]=B27;
  BOLD->offset[B30+1]=B29;	BOLD->offset[B30+2]=B31;
}
//'a' read bold+x>
static void readBold(int *a){
  int n,t,par[5];
  par[0]=STACKpar(BUFFER);scratch(par);n=0;nxt1:
  if(boldLetter(par)){t=par[0];par[0]=STACKpar(BUFFER);par[1]=t;extend(par);
     par[0]=n;incr(par);n=par[0];goto nxt1;}
  else if(Achar=='\''){nextChar();}
  else{par[0]=STACKpar(BUFFER);par[1]=n;par[2]=STACKpar(LEXT);packstring(par);
       par[0]=missing_bold_delimiter;par[1]=LEXT->aupb;Error(2,par);
       par[0]=STACKpar(LEXT);unstackstring(par);a[0]=Sdummysymb; return;}
  par[0]=STACKpar(BUFFER);par[1]=n;par[2]=STACKpar(LEXT);packstring(par);
  a[0]=firstBold;nxt2:
  if(a[0]==0){par[0]=unrecognized_bold;par[1]=LEXT->aupb;Error(2,par); a[0]=Sdummysymb;}
  else{par[0]=STACKpar(BOLD);par[1]=a[0];par[2]=STACKpar(LEXT);par[3]=LEXT->aupb;
    comparestring(par);n=par[4];par[0]=STACKpar(BOLD);par[1]=a[0];next(par);a[0]=par[1];
    if(n>0){a[0]=BOLD->offset[a[0]-BOLD_left];goto nxt2;}
    else if(n<0){a[0]=BOLD->offset[a[0]-BOLD_right]; goto nxt2;}
    else{a[0]=BOLD->offset[a[0]-BOLD_adm];}}
  par[0]=STACKpar(LEXT);unstackstring(par);
}
/* tags */
//'a' read tag+x>
static void readTag(int *a){
  int par[2];int t;
  par[0]=STACKpar(BUFFER); scratch(par);
  par[0]=STACKpar(BUFFER);par[1]=Achar;extend(par);nextChar();nxt:
  if(letgit(par)){t=par[0];par[0]=STACKpar(BUFFER);par[1]=t;extend(par);goto nxt;}
  par[0]=STACKpar(BUFFER);enterTag(par);a[0]=par[1];
}
/*--------------------------------------------------------------------*/
//'a' read+x>
void Aread(int *a){
  int ooptor; int par[4];
  if(ppline>0){ppline--;a[0]=Seol; return;}
  ooptor=optor;optor=0; nxt2:
  if(Achar==' '){nextChar(); goto nxt2;}
  else if(('A'<=Achar&&Achar<='Z')||('a'<=Achar&&Achar<='z')){
     optor=1;readTag(par);a[0]=par[0];}
  else if(Achar=='+'){nextChar();a[0]=Splus;}
  else if(Achar==','){nextChar();a[0]=Scomma;}
  else if(Achar==';'){nextChar();a[0]=Ssemicolon;}
  else if(Achar==newline){nextChar();optor=ooptor;a[0]=Seol;}
  else if(Achar=='-'){nextChar();readMinus(par);a[0]=par[0];}
  else if(Achar=='='){nextChar();a[0]=Sequals;}
  else if(Achar=='('){nextChar();a[0]=Sopen;}
  else if(Achar==')'){nextChar();optor=1;a[0]=Sclose;}
  else if(Achar=='0'){nextChar();optor=1;par[0]=0;readZero(par);a[0]=par[1];}
  else if('1'<=Achar && Achar<='9'){optor=1;par[0]=0;readConst(par);a[0]=par[1];}
  else if(Achar=='\''){nextChar();readBold(par);a[0]=par[0];}
  else if(Achar=='<'){nextChar();par[0]=ooptor;readLess(par);a[0]=par[1];}
  else if(Achar=='>'){nextChar();par[0]=ooptor;readGreater(par);a[0]=par[1];}
  else if(Achar=='*'){nextChar();a[0]=Sasterisk;}
  else if(Achar==':'){nextChar();a[0]=Scolon;}
  else if(Achar=='/'){nextChar();if(ooptor){a[0]=Sslash;}
                        else{optor=1;readCharDenotation(par);a[0]=par[0];}}
  else if(Achar=='.'){nextChar();a[0]=Spoint;}
  else if(Achar=='@'){par[0]=pgtLibrary;
           if(isPragmatValue(par)){optor=1;readTag(par);a[0]=par[0];}
           else{par[0]=illegal_character;par[1]=Achar;Error(2,par);nextChar();goto nxt2;}}
  else if(Achar=='?'){nextChar();a[0]=Senquiry;}
  else if(Achar=='$'){nextChar();longComment();goto nxt2;}
  else if(Achar=='['){nextChar();a[0]=Ssub;}
  else if(Achar==']'){nextChar();optor=1;a[0]=Sbus;}
  else if(Achar=='#'){nextChar();if(shortComment()){goto nxt2;}else{a[0]=Snoarg;}}
  else if(Achar=='\\'){nextChar();shortComment();goto nxt2;}
  else if(Achar=='"'){readString(par);a[0]=par[0];}
  else if(Achar=='!'){nextChar(); if(Achar=='='){nextChar();a[0]=Snotequal;}
           else{par[0]=illegal_character;par[1]='!';Error(2,par);goto nxt2;}}
  else if(Achar=='~'){nextChar();a[0]=Scomplement;}
  else if(Achar=='|'){nextChar();a[0]=Sboolor;}
  else if(Achar=='&'){nextChar();a[0]=Sbooland;}
  else if(Achar=='^'){nextChar();a[0]=Sboolxor;}
  else if(Achar==endChar){nextChar();a[0]=Sendsymb;}
  else{par[0]=illegal_character;par[1]=Achar;Error(2,par);nextChar();goto nxt2;}
}
//'a' skip+x>
void skip(int *a){
  if(ppline>0){ppline--;a[0]=Seol;return;}
  nxt:if(Achar==newline){nextChar();a[0]=Seol;}
  else if(Achar=='/'){nextChar();skipCharDenotation();goto nxt;}
  else if(Achar=='.'){nextChar();a[0]=Spoint;}
  else if(Achar=='"'){nextChar();skipString();goto nxt;}
  else if(Achar=='#'){nextChar();shortComment(); goto nxt;}
  else if(Achar=='\\'){nextChar();shortComment();goto nxt;}
  else if(Achar=='$'){nextChar();longComment();goto nxt;}
  else if(Achar==endChar){a[0]=Sendsymb;}
  else{nextChar(); goto nxt;}
}



/* EOF */

