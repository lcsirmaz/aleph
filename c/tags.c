/* tags.ale main file */

#include "stddata.h"
#include "tags.h"
#include "display.h"
#include "pragmats.h"
#include "lexical.h"
#include "lists.h"
#include "types.h"
#include "ice.h"

/* =================================== */
// 'a'extend+[]st[]+>x is defined in cstdlib

#define rshiftarg	(rque|rshiftrule|tdefined|timported|rvararg|tpermanent|raffixes)
#define rgetarg		(rfunc|rshiftrule|tdefined|timported|rvararg|tpermanent|raffixes)
#define rrootfl		(rexit|tdefined|tused|tpermanent|raffixes)

/* ------------------------------------ */
/* messages */
static int preamble_doubly_defined,tag_doubly_defined,tag_is_external,cannot_be_public,
  permanent_not_public,cannot_be_external,tag_cannot_be_redefined;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void add_messages(void){
  addMSG("%p: doubly defined in the preamble (fatal)",
        preamble_doubly_defined);
  addMSG("%p: was defined at %l",tag_doubly_defined);
  addMSG("%p: is external (%l), cannot be redefined",tag_is_external);
  addMSG("%p: is external (%l), cannot be public",cannot_be_public);
  addMSG("%p: cannot be public",permanent_not_public);
  addMSG("%p: is public (%l), cannot be external",cannot_be_external);
  addMSG("%p: cannot be redefined",tag_cannot_be_redefined);
}
#undef addMSG

/*---------------------------------------------------*/
static int firstTag,Pstar,Pshiftaffx,Pgetaffx,Proot,Pexit,Pstdstr,
   Parrow,Pmreq,Pequal,Pnotequal,Pmore,Pless,Plseq,PParrow,PPmreq,PPequal,
   PPnotequal,PPmore,PPless,PPlseq;
static int notagFrom,notagTo;
int Xstar,Xarrow,Xroot,Xstringtable,Xexit,Xshiftaffix;
static int Xgetaffix;

/* initialize standard stuff */
/* standard tags 
   extendStack extends the stack with an empty block (should be filled later)
*/ 
#define addTTAG(x,y) add_new_string(x,TTAG);extendStack(par);y=TTAG->aupb
#define addTTAG2(x,z,y) add_new_string(x,TTAG);z=TTAG->aupb;extendStack(par);y=TTAG->aupb
static void initialize_TTAG(void){
   int par[1]; par[0]=STACKpar(TTAG);
   add_new_string("",TTAG);firstTag=TTAG->aupb;extendStack(par);
   addTTAG("shiftaffixblock",Pshiftaffx);
   addTTAG("getaffixblockno",Pgetaffx);
   addTTAG("@root",Proot);
   addTTAG("exit",Pexit);
   addTTAG("@StringTable",Pstdstr);
   addTTAG("@make",Parrow);
   addTTAG("@mreq",Pmreq);
   addTTAG("@equal",Pequal);
   addTTAG("@noteq",Pnotequal);
   addTTAG("@more",Pmore);
   addTTAG("@less",Pless);
   addTTAG("@lseq",Plseq);
   // these won't be found
   addTTAG2("*",notagFrom,Pstar);
   addTTAG("->",PParrow);
   addTTAG(">=",PPmreq);
   addTTAG("=",PPequal);
   addTTAG("!=",PPnotequal);
   addTTAG(">",PPmore);
   addTTAG("<",PPless);
   addTTAG2("<=",notagTo,PPlseq);
   add_messages();
}
#undef addTTAG

static void initialize_LADM(void){
  int par[8];
  par[0]=STACKpar(LADM);par[1]=6;par[7-LADM_defline]=-2;
  par[7-LADM_type]=Iempty;par[7-LADM_repr]=par[7-LADM_adm]=0;
  par[7-LADM_flag]=0;par[7-LADM_tag]=Pstar;expandstack(par);Xstar=LADM->aupb;
  par[7-LADM_flag]=tpermanent;par[7]=Pstdstr;expandstack(par);Xstringtable=LADM->aupb;
  par[7]=Proot;expandstack(par);Xroot=LADM->aupb;
  par[7]=Pshiftaffx;expandstack(par);Xshiftaffix=LADM->aupb;
  par[7]=Pgetaffx;expandstack(par);Xgetaffix=LADM->aupb;
  par[7-LADM_flag]=0;par[7]=PParrow;expandstack(par);Xarrow=LADM->aupb;
  par[7]=Pexit;expandstack(par);Xexit=LADM->aupb;
}
/* --------------------------------------------------- */
/* return yes if the pointer is recognized */
int wasTagPointer(int *a){ /* >ptr+[]st[] */
   int par[3];again:
   if((par[0]=STACKpar(TTAG),par[1]=a[0],was(par))){par[0]=STACKpar(TTAG);par[1]=a[0];
     previous(par);a[0]=par[1];par[0]=STACKpar(TTAG);
     par[1]=a[0];par[2]=a[1];copystring(par);}
   else if((par[0]=STACKpar(LADM),par[1]=a[0],was(par))){
     a[0]=LADM->offset[a[0]-LADM_tag];
     goto again;}
   else if((par[0]=STACKpar(LLOC),par[1]=a[0],was(par))){
     a[0]=LLOC->offset[a[0]-LLOC_tag];goto again;}
   else{return 0;}
   return 1;
}
/* **************************************************** */
/* prototypes */
static void newTagEntry(int *a);
static void initStdstringTable(void);
static void initRules(void);
static void initStdstringTable(void);

/* **************************************************** */
/* get/set fields */
void getTag(int *a)    {a[1]=LADM->offset[a[0]-LADM_tag]; }
void getRepr(int *a)   {a[1]=LADM->offset[a[0]-LADM_repr];}
void getAdm(int *a)    {a[1]=LADM->offset[a[0]-LADM_adm]; }
void getType(int *a)
   {if(LADM->vlwb<=a[0]&&a[0]<=LADM->vupb){a[1]=LADM->offset[a[0]-LADM_type];}
    else{a[1]=LLOC->offset[a[0]-LLOC_type];}}
void getDefline(int *a){a[1]=LADM->offset[a[0]-LADM_defline];}
void getCalibre(int *a){a[1]=LADM->offset[LADM->offset[a[0]-LADM_adm]-LADM_calibre];}
void getSsel(int *a)   {a[1]=LADM->offset[LADM->offset[a[0]-LADM_adm]-LADM_ssel];}
void getFormalCalibre(int *a){a[1]=LADM->offset[a[0]-LADM_fcalibre];}
void getFormalSsel(int *a)   {a[1]=LADM->offset[a[0]-LADM_fssel];}
//
void putRepr(int *a)   {LADM->offset[a[0]-LADM_repr]=a[1];}
void putAdm(int *a)    {LADM->offset[a[0]-LADM_adm]=a[1];}
void putType(int *a)   {LADM->offset[a[0]-LADM_type]=a[1];}
void putDefline(int *a){LADM->offset[a[0]-LADM_defline]=a[1];}
void putCalibre(int *a){LADM->offset[LADM->offset[a[0]-LADM_adm]-LADM_calibre]=a[1];}
void putSsel(int *a)   {LADM->offset[LADM->offset[a[0]-LADM_adm]-LADM_ssel]=a[1];}
void putFormalCalibre(int *a) {LADM->offset[a[0]-LADM_fcalibre]=a[1];}
void putFormalSsel(int *a)    {LADM->offset[a[0]-LADM_fssel]=a[1];}
/* ---- */
/* flags */
void setTagFlag(int *a){ LADM->offset[a[0]-LADM_flag]|= a[1];}
int isTagFlag(int *a){ return (LADM->offset[a[0]-LADM_flag]&a[1])? 1 : 0 ; }
void getTagFlag(int *a){a[2]=a[1]&LADM->offset[a[0]-LADM_flag]; }
void clearTagFlag(int *a){LADM->offset[a[0]-LADM_flag] &= ~a[1]; }
void useTag(int *a){
  if(LADM->offset[a[0]-LADM_type]>=IfirstFormalType){;}
  else{LADM->offset[a[0]-LADM_flag]|=tused;}
}
/* ************************************************************ */

void enterTag(int *a){/* +buf[]+tag> */
  int par[8];int n,y;
  par[0]=a[0];listlength(par);n=par[1];par[0]=a[0];par[1]=n;
  par[2]=STACKpar(TTAG);packstring(par);y=firstTag;nxt:
  par[0]=y;par[1]=TTAG->calibre;add(par);a[1]=par[2];
  par[0]=STACKpar(TTAG);par[1]=y;par[2]=STACKpar(TTAG);par[3]=TTAG->aupb;
  comparestring(par);n=par[4];
  if(n==0){par[0]=STACKpar(TTAG);unstackstring(par);}
  else if(n>0){y=TTAG->offset[a[1]-TTAG_left];if(y>0){goto nxt;}
    TTAG->offset[a[1]-TTAG_left]=TTAG->aupb;
    par[0]=STACKpar(TTAG);par[1]=TTAG_CALIBRE;par[6-TTAG_lastline]=-1;
    par[6-TTAG_left]=par[6-TTAG_right]=par[6-TTAG_adm]=par[6-TTAG_text]=0;expandstack(par);a[1]=TTAG->aupb;}
  else{y=TTAG->offset[a[1]-TTAG_right];if(y>0){goto nxt;}
    TTAG->offset[a[1]-TTAG_right]=TTAG->aupb;
    par[0]=STACKpar(TTAG);par[1]=TTAG_CALIBRE;par[6-TTAG_lastline]=-1;
    par[6-TTAG_left]=par[6-TTAG_right]=par[6-TTAG_adm]=par[6-TTAG_text]=0;expandstack(par);a[1]=TTAG->aupb;}
}
void packSelector(int *a){ /* >sel + >tag + x> */
  int par[4];int sel,tag;
//printf("packSelector, in=%d,%d\n",a[0],a[1]);
//printf("strings: [");par[0]=sel;printPointer(par);printf(" * ");par[0]=tag;printPointer(par);printf("]\n");
  par[0]=STACKpar(BUFFER);scratch(par);par[0]=a[0];getTag(par);sel=par[1];
  par[0]=a[1];getTag(par);tag=par[1];par[0]=STACKpar(TTAG);par[1]=sel;
  previous(par);sel=par[1];par[0]=STACKpar(TTAG);par[1]=tag;previous(par);
  tag=par[1];
  par[0]=STACKpar(TTAG);par[1]=sel;par[2]=STACKpar(BUFFER);
  unpackstring(par);par[0]=STACKpar(BUFFER);par[1]='*';extend(par);
  par[0]=STACKpar(TTAG);par[1]=tag;par[2]=STACKpar(BUFFER);unpackstring(par);
  par[0]=STACKpar(BUFFER);enterTag(par);a[2]=par[1];par[0]=a[2];getTagEntry(par);
  a[2]=par[1];
//printf("result: %d\n",a[2]);
}

/* ========================================================== */
static void enterPredefinedTag(int *a){/* >tag */
  int par[5];int n,x,y;
  if(a[0]==firstTag){;}
  else if(notagFrom<=a[0]&&a[0]<=notagTo){;}
  else{y=firstTag;nxt:x=y+TTAG->calibre;par[0]=STACKpar(TTAG);par[1]=y;
    par[2]=STACKpar(TTAG);par[3]=a[0];comparestring(par);n=par[4];
    if(n==0){par[0]=STACKpar(TTAG);par[1]=a[0];next(par);a[0]=par[1];
      par[0]=preamble_doubly_defined;par[1]=a[0];Xerror(0,2,par);exit(99);}
    else if(n>0){y=TTAG->offset[x-TTAG_left];if(y>0){goto nxt;}
       TTAG->offset[x-TTAG_left]=a[0];}
    else{y=TTAG->offset[x-TTAG_right];if(y>0){goto nxt;}
       TTAG->offset[x-TTAG_right]=a[0];}
}}
static void addSpecialRule(int *a){ /* >tag+>alt */
  int par[2];
  par[0]=a[1];newTagEntry(par);
  TTAG->offset[a[0]-TTAG_adm]=TTAG->offset[a[1]-TTAG_adm]=par[1];
}
/* initialize this module */
void initTags(void){
  int par[5]; int tag;
  tag=TTAG->aupb;nxt:if(tag<=TTAG->alwb){;}
  else{par[0]=STACKpar(TTAG);par[1]=tag;previous(par);tag=par[1];par[0]=tag;
    enterPredefinedTag(par);par[0]=STACKpar(TTAG);par[1]=tag;stringwidth(par);
    tag-=par[2];goto nxt;}
  TTAG->offset[Pexit-TTAG_adm]=Xexit;
  TTAG->offset[Pshiftaffx-TTAG_adm]=Xshiftaffix;
  TTAG->offset[Pgetaffx-TTAG_adm]=Xgetaffix;
  TTAG->offset[Proot-TTAG_adm]=Xroot;
  TTAG->offset[Pstdstr-TTAG_adm]=Xstringtable;
  TTAG->offset[Parrow-TTAG_adm]=TTAG->offset[PParrow-TTAG_adm]=Xarrow;
  par[0]=Pmreq;par[1]=PPmreq;addSpecialRule(par);
  par[0]=Pequal;par[1]=PPequal;addSpecialRule(par);
  par[0]=Pnotequal;par[1]=PPnotequal;addSpecialRule(par);
  par[0]=Pmore;par[1]=PPmore;addSpecialRule(par);
  par[0]=Pless;par[1]=PPless;addSpecialRule(par);
  par[0]=Plseq;par[1]=PPlseq;addSpecialRule(par);
  initStdstringTable();initRules();
}

static int stdEmptyPointer=0, /* the empty string in the stdstring table */
           stdstrings=0;      /* strings are linked throught this one */
void newStdstring(int *a){ /* >str + c> */
  int par[5];
  if(a[0]==Squoteimage && stdEmptyPointer!=0){a[1]=stdEmptyPointer;return;}
  par[0]=Pstar;newTagEntry(par);a[1]=par[1];
  par[0]=a[1];par[1]=IpointerConstant;putType(par);
  par[0]=a[1];par[1]=Xstringtable;putAdm(par);par[0]=Xstringtable;useTag(par);
  par[0]=Xstringtable;par[1]=tfill;setTagFlag(par);par[1]=timported;setTagFlag(par);
  par[0]=a[1];par[1]=tdefined;setTagFlag(par);par[1]=tused;setTagFlag(par);
  par[0]=STACKpar(LADM);par[1]=3;par[4-LADM_adm]=a[1];par[4-LADM_repr]=a[0];
  par[4-LADM_link]=stdstrings;expandstack(par);stdstrings=LADM->aupb;
  if(a[0]==Squoteimage){stdEmptyPointer=a[1];}
}
static void initStdstringTable(void){
  int par[2];
  TTAG->offset[Pstdstr-TTAG_adm]=Xstringtable;
  par[0]=Xstringtable;par[1]=Itable;newListEntry(par);
}
/* variable affix rules */
static void initRules(void){
  int par[3];int affix,affix2;
  TTAG->offset[Pshiftaffx-TTAG_adm]=Xshiftaffix;
  par[0]=Xshiftaffix;par[1]=Irule;putType(par);par[0]=Xshiftaffix;
  par[1]=rshiftarg;setTagFlag(par);par[0]=IformalShift;par[1]=Xstar;
  newFormalTag(par);affix=par[2];par[0]=Xshiftaffix;par[1]=affix;putAdm(par);
  /* get affix blockno +n>+* */
  TTAG->offset[Pgetaffx-TTAG_adm]=Xgetaffix;
  par[0]=Xgetaffix;par[1]=Irule;putType(par);par[0]=Xgetaffix;
  par[1]=rgetarg;setTagFlag(par);par[0]=IformalOut;par[1]=Xstar;
  newFormalTag(par);affix=par[2];par[0]=Xgetaffix;par[1]=affix;putAdm(par);
  par[0]=IformalShift;par[1]=Xstar;newFormalTag(par);affix2=par[2];
  par[0]=affix;par[1]=affix2;putAdm(par);
  /* root */
  TTAG->offset[Proot-TTAG_adm]=Xroot;par[0]=Xroot;par[1]=Irule;
  putType(par);par[0]=Xroot;par[1]=rrootfl;setTagFlag(par);
}
/* --------------------------------------------------------- */
void getTagHash(int *a){ /* >tag + hash> */
   int par[3];
   par[0]=a[0];getTag(par);a[0]=par[1]-TTAG->calibre;
   par[0]=STACKpar(TTAG);par[1]=a[0];simplehash(par);a[1]=par[2];
}
/* --------------------------------------------------------- */
static void newTagEntry(int *a){ /* >raw + x> */
  int par[8];
  par[0]=STACKpar(LADM);par[1]=LADM_CALIBRE;
  par[7-LADM_defline]=-1;par[7-LADM_flag]=0;par[7-LADM_type]=Iempty;
  par[7-LADM_repr]=par[7-LADM_adm]=0;par[7-LADM_tag]=a[0];
  expandstack(par);a[1]=LADM->aupb;
}
void getTagEntry(int *a){ /* >raw + x> */
  int par[3];
  a[1]=TTAG->offset[a[0]-TTAG_adm];if(a[1]==0){par[0]=a[0];
    newTagEntry(par);a[1]=par[1];TTAG->offset[a[0]-TTAG_adm]=a[1];}
}
void newFormalTag(int *a){ /* >type+>tag+ formal> */
  int par[8];
  if(a[0]==IformalTable||a[0]==IformalStack){
    par[0]=STACKpar(LADM);par[1]=6;par[7-LADM_fcalibre]=par[7-LADM_fssel]=0;
    par[7-LADM_type]=a[0];
    par[7-LADM_repr]=par[7-LADM_adm]=0;par[7-LADM_tag]=LADM->offset[a[1]-LADM_tag];expandstack(par);}
  else{par[0]=STACKpar(LADM);par[1]=4;par[5-LADM_type]=a[0];par[5-LADM_repr]=par[5-LADM_adm]=0;
    par[5-LADM_tag]=LADM->offset[a[1]-LADM_tag];expandstack(par);}
  a[2]=LADM->aupb;
}
void newListEntry(int *a){ /* >tag+>type */
  int par[4];
  par[0]=a[0];par[1]=a[1];putType(par);par[0]=STACKpar(LADM);
  par[1]=2;par[2]=par[3]=0;expandstack(par);
  par[0]=a[0];par[1]=LADM->aupb;putAdm(par);
}
/* -------------------------------------------- */
void findRawUsage(int *a){/* >tag + usage> */
  int par[2];int tag;
  if(a[0]==0){a[1]=0;}
  else{tag=TTAG->offset[a[0]-TTAG_adm];if(tag==0){a[1]=0;}
    else if(par[0]=tag,par[1]=tdefined,isTagFlag(par)){a[1]=2;}
    else if(par[0]=tag,par[1]=tused,isTagFlag(par)){a[1]=1;}
    else{a[1]=0;}}
//printf("findRawUsage: ");par[0]=a[0];printPointer(par);printf(" =>tag=%d, %d\n",tag,a[1]);
}
void addTagDefinition(int *a){ /* >tag + >line+>err> */
  int par[3];
  if(a[2]){return;}
  par[0]=a[0];
  if(par[1]=tpermanent,isTagFlag(par)){
    par[0]=tag_cannot_be_redefined;par[1]=a[0];Error(2,par);a[2]=1;}
  else if(par[1]=texternal,isTagFlag(par)){par[0]=tag_is_external;
    par[1]=a[0];par[2]=LADM->offset[a[0]-LADM_defline];Error(3,par);a[2]=1;}
  else if(par[1]=tdefined,isTagFlag(par)){par[0]=tag_doubly_defined;
    par[1]=a[0];par[2]=LADM->offset[a[0]-LADM_defline];Error(3,par);a[2]=1;
//printf("doubly defined error for tag=%d, line=%d\n",a[0],a[1]);
    }
  else{if(par[1]<=1){;}else{par[0]=a[0];par[1]=a[1];putDefline(par);}
       par[0]=a[0];par[1]=tdefined;setTagFlag(par);}
}
void addTagExternal(int *a){ /* >tag+>line+>err> */
  int par[3];
  par[0]=a[0];par[1]=texternal;
  if(isTagFlag(par)){;}
  else{par[0]=a[0];par[1]=a[1];par[2]=a[2];addTagDefinition(par);a[2]=par[2];}
  par[0]=a[0];par[1]=tpublic;if(isTagFlag(par)){par[0]=cannot_be_external;
    par[1]=a[0];par[2]=LADM->offset[a[0]-LADM_defline];Error(3,par);a[2]=1;}
  if(a[2]){;}else{par[0]=a[0];par[1]=texternal;setTagFlag(par);}
}
void addTagImport(int *a){ /* >tag+>line+>err> */
  int par[3];
  par[0]=a[0];par[1]=timported;if(isTagFlag(par)){;}
  else if(par[1]=tpublic,isTagFlag(par)){par[0]=cannot_be_public;
    par[1]=a[0];par[2]=LADM->offset[a[0]-LADM_defline];Error(3,par);a[2]=1;}
  else{par[0]=a[0];par[1]=a[1];par[2]=a[2];addTagDefinition(par);a[2]=par[2];
    if(a[2]){;}else{par[0]=a[0];par[1]=timported;setTagFlag(par);}}
}
void addTagPublic(int *a){ /* >tag+>line+>err> */
  int par[3];
  if(a[2]){return;}
  par[0]=a[0];par[1]=tpermanent;if(isTagFlag(par)){par[0]=permanent_not_public;
    par[1]=a[0];Error(2,par);a[2]=1;}
  else if(par[1]=texternal,isTagFlag(par)){par[0]=cannot_be_public;
    par[1]=a[0];par[2]=LADM->offset[a[0]-LADM_defline];Error(3,par);a[2]=1;}
  else if(par[1]=timported,isTagFlag(par)){par[0]=cannot_be_public;
    par[1]=a[0];par[2]=LADM->offset[a[0]-LADM_defline];Error(3,par);a[2]=1;}
  else{par[1]=tpublic;setTagFlag(par);par[0]=a[0];useTag(par);par[0]=a[0];
    par[1]=a[1];addTagPrototype(par);}
}
void addTagPrototype(int *a){ /* >tag+>line */
  int par[2];
//DEBUG
//printf("add defline, tag=%d, line=%d, was: %d\n",a[0],a[1],LADM->offset[a[0]-LADM_defline]);
//if(a[1]>100000){a[3]=LADM->offset[a[1]];}
  if(LADM->offset[a[0]-LADM_defline]>0){;}
  else if(a[1]<=1){;}
  else{par[0]=a[0];par[1]=a[1];putDefline(par);}
}

/* redefine tags */
void redefineTag(int *a){ /* >old + >new */
  int par[5];int x;
  x=LADM->offset[a[0]-LADM_tag];LADM->offset[a[1]-LADM_tag]=x;
  par[0]=STACKpar(RETAG);par[1]=2;par[3-RETAG_adm]=a[0];
  par[3-RETAG_tag]=x;expandstack(par);
  TTAG->offset[x-TTAG_adm]=a[1];
}
void restoreTags(void){
  int par[1]; again:
  if(RETAG->aupb<RETAG->alwb){;}
  else{ TTAG->offset[RETAG->offset[RETAG->aupb-RETAG_tag]-TTAG_adm]=
   RETAG->offset[RETAG->aupb-RETAG_adm];par[0]=STACKpar(RETAG);unstack(par);
   goto again;
}}
int isSpecialRule(int *a){ /* >symb+tag> */
  if(a[0]==Sarrow){         a[1]=TTAG->offset[Parrow-TTAG_adm];}
  else if(a[0]==Sequals){   a[1]=TTAG->offset[Pequal-TTAG_adm];}
  else if(a[0]==Smore){     a[1]=TTAG->offset[Pmore-TTAG_adm];}
  else if(a[0]==Sless){     a[1]=TTAG->offset[Pless-TTAG_adm];}
  else if(a[0]==Snotequal){ a[1]=TTAG->offset[Pnotequal-TTAG_adm];}
  else if(a[0]==Slseq){     a[1]=TTAG->offset[Plseq-TTAG_adm];}
  else if(a[0]==Smreq){     a[1]=TTAG->offset[Pmreq-TTAG_adm];}
  else{return 0;}
  return 1;
}
/* ************************************************************************** */
/* dictionary stuff */
static void pack2(int *a){ /* >d + >n + x> */
  a[2]=((unsigned)a[0])<<11|a[1];
}
static void unpack2(int *a){ /* >x+d>+n> */
  a[2]=a[0]&0x7FFF;a[1]=(int)(((unsigned)a[0])>>11);
}
static void expandDict(int *a){ /* >ptr + >x */
  int par[2];int z;
  if(a[0]==0){z=0;}
  else{par[0]=DICT->aupb;par[1]=a[0];subtr(par);z=par[2];z++;}
  par[0]=z;par[1]=a[1];pack2(par);z=par[2];par[0]=STACKpar(DICT);
  par[1]=z;extend(par);
}
static void addLinetoDict(int *a){ /* >ptr +>n */
  int par[4];again:
  if(a[1]<2030){par[0]=a[0];par[1]=a[1];expandDict(par);}
  else{par[0]=a[0];par[1]=2047;expandDict(par);par[0]=a[1];
  par[1]=2000;subtr(par);a[1]=par[2];a[0]=DICT->aupb;goto again;}
}
void addDICT(int *a){ /* >tag + >line */
  int par[3];int l1;
  par[0]=pgtDict;if(isPragmatValue(par)){l1=TTAG->offset[a[0]-TTAG_lastline];
// printf("addDICT, l1=%d, line=%d\n",l1,a[1]);
    if(l1<0){TTAG->offset[a[0]-TTAG_lastline]=a[1];
      TTAG->offset[a[0]-TTAG_text]=0;}
    else{par[0]=a[1];par[1]=l1;subtr(par);l1=par[2];if(l1<=0){;}else{
     par[0]=TTAG->offset[a[0]-TTAG_text];par[1]=l1;addLinetoDict(par);
     TTAG->offset[a[0]-TTAG_lastline]=a[1];
     TTAG->offset[a[0]-TTAG_text]=DICT->aupb;}}
}}
static void reverseDICT(int *a){ /* >tag */
  int par[3];int ptr,l,n,d,d1;
  if(TTAG->offset[a[0]-TTAG_lastline]<0){;}
  else if(TTAG->offset[a[0]-TTAG_text]==0){;}
  else{l=TTAG->offset[a[0]-TTAG_lastline];ptr=TTAG->offset[a[0]-TTAG_text];
    d1=0;nxt: par[0]=DICT->offset[ptr];unpack2(par);d=par[1];n=par[2];
    par[0]=d1;par[1]=n;pack2(par);DICT->offset[ptr]=par[2];
    if(1<=n && n<=2019){par[0]=l;par[1]=n;subtr(par);l=par[2];}
    else if(n==2047){par[0]=l;par[1]=2000;subtr(par);l=par[2];}
    if(d==0){;}
    else{d1=d;par[0]=ptr;par[1]=d;subtr(par);ptr=par[2];goto nxt;}
    TTAG->offset[a[0]-TTAG_text]=ptr;TTAG->offset[a[0]-TTAG_lastline]=l;
}}
static int isSpecialTag(int *a){ /* >tag */
  int par[4];int ch;
  par[0]=STACKpar(TTAG);par[1]=a[0];previous(par);a[0]=par[1];
  par[0]=STACKpar(TTAG);par[1]=a[0];par[2]=0;if(stringelem(par)){ch=par[3];
   if(('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')){return 0;}}
  else{;}
  return 1;
}
static void DICTtag(int *a){ /* >tag */
  int par[3];int l,n,d,ptr;
//DEBUG
//printf("a[0]=%d, lastline=%d\n",a[0],TTAG->offset[a[0]-TTAG_lastline]);
  if(TTAG->offset[a[0]-TTAG_lastline]<=0){return;}
  par[0]=a[0];if(isSpecialTag(par)){return;}
  ptr=TTAG->offset[a[0]-TTAG_adm];
  if(ptr==0){n=0;}else{n=LADM->offset[ptr-LADM_defline];}
  par[0]=a[0];reverseDICT(par);l=TTAG->offset[a[0]-TTAG_lastline];
  ptr=TTAG->offset[a[0]-TTAG_text];par[0]=a[0];par[1]=n;
  DICTheader(par);
//DEBUG, remove ptr1 !!!!
//printf("<%x>",ptr1==0?0:(1&LADM->offset[ptr1-LADM_flag]));
  par[0]=l;DICTitem(par);
  nxt:if(ptr==0){DICTtail();}
  else{par[0]=DICT->offset[ptr];unpack2(par);d=par[1];n=par[2];
    if(1<=n&&n<=2019){l+=n;par[0]=l;DICTitem(par);}
    else if(n==2047){l+=2000;}
    if(d==0){DICTtail();}else{ptr+=d;goto nxt;}}
}
static void printDict(int *a){ /* >y */
   int par[3];int x;again:
   if(a[0]==0){ return; }
   par[0]=a[0];par[1]=TTAG->calibre;add(par);x=par[2];
   par[0]=TTAG->offset[x-TTAG_left];printDict(par);
   par[0]=x;DICTtag(par);a[0]=TTAG->offset[x-TTAG_right];goto again;
}
void printDictionary(void){
  int par[2];
  par[0]=firstTag;printDict(par);par[0]=STACKpar(DICT);release(par);
}
/* -------------------------------------------------------- */
static void assignTags(int *a){/* >y */
  int par[1]; int x; again:
  if(a[0]==0){return;}
  x=a[0]+TTAG->calibre;par[0]=TTAG->offset[x-TTAG_left];assignTags(par);
  par[0]=TTAG->offset[x-TTAG_adm];defineIceTag(par);
  a[0]=TTAG->offset[x-TTAG_right]; goto again;
}
void assignItems(void){
  /* this is for those in TTAG */
  int par[1];int stds;par[0]=firstTag;assignTags(par);
  /* this is for stdstrings */
  stds=stdstrings;while(stds){
//par[0]=LADM->offset[stds-LADM_repr];printf("\"");printPointer(par);printf("\" => ");
    par[0]=LADM->offset[stds-LADM_adm];defineIceTag(par);
    stds=LADM->offset[stds-LADM_link];
  }
}
int XstringTableFilling(void){
  int par[3];int str;
  if(!stdstrings){return 0;}
  str=stdstrings;par[0]=Xstringtable;XstringTableFillingHead(par);nxt:
  if(str==0){}
  else{par[0]=LADM->offset[str-LADM_adm];par[1]=LADM->offset[str-LADM_repr];
    XstringTableItem(par);str=LADM->offset[str-LADM_link];goto nxt;}
  return 1;
}
/* -------------------------------------------------------- */
static int macroPtr=0;
void linkMacroRule(int *a){/* >tag+>dpos+>dnum */
   int par[6];
   par[0]=STACKpar(LADM);par[1]=4;par[5-LADM_dnum]=a[2];par[5-LADM_dpos]=a[1];
   par[5-LADM_tag]=a[0];par[5-LADM_adm]=macroPtr;expandstack(par);
   macroPtr=LADM->aupb;
}
void searchMacroRule(int *a){ /* >tag+dpos>+dnum> */
  int link;
  link=macroPtr;nxt:if(link==0){printf("error search macro rule %d\n",a[0]); exit(7);}
  if(LADM->offset[link-LADM_tag]==a[0]){a[1]=LADM->offset[link-LADM_dpos];
    a[2]=LADM->offset[link-LADM_dnum];}
  else{link=LADM->offset[link-LADM_adm];goto nxt;}
}
int nextMacroRule(int *a){ /* >tag> */
  int link;
  link=macroPtr;if(a[0]==0){;}
  else{nxt:if(link==0){;}else if(LADM->offset[link-LADM_tag]==a[0]){
    link=LADM->offset[link-LADM_adm];}
    else{link=LADM->offset[link-LADM_adm];goto nxt;}}
  if(link==0){return 0;}
  else{a[0]=LADM->offset[link-LADM_tag];}
  return 1;
}
/* -------------------------------------------------------- */
// USES Iempty
void initialize_tags(void){
  initialize_TTAG();
  initialize_LADM();
  add_messages();
}


/* EOF */

