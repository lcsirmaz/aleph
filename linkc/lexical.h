/* lexical.ale header file */

#include "error.h"

extern int
   Darea,Dbox,Dcalibre,Dexpression,Dextension,Dfile,Dfill,
   Dlist,Dlwb,Dnode,Drule,Dto,Dupb,Dvlwb,Dvupb,
   Dmodule,Dtitle,
   Dand,Dbus,Dclose,Dcolon,Dcompl,Ddiv,Dminus,Dnoarg,Dopen,Dor,
   Dout,Dplus,Dpoint,Dsemicolon,Dstar,Dsub,Dxor,
   Dend,Tconst,Ttype,Tnode,Titem,Tformal,Tlocal,Tstring,
   Iconstant,Ivariable,IstaticVar,Itable,Istack,IstaticStack,
   IpointerConstant,Icharfile,Idatafile,Irule,
   IformalStack,IformalTable,IformalFile,IformalIn,
   IformalOut,IformalInout,IformalRepeat,IformalShift;
extern int Squoteimage;

extern int inpt,inptValue;

void nextSymbol(void);
#define UNUSED	__attribute__((unused));
static int R() UNUSED
static int RR() UNUSED
static void must() UNUSED
#undef UNUSED

static int R(int *a){if(inpt==a[0]){nextSymbol(); return 1;}return 0;}
static int RR(int *a){if(inpt==a[0]){a[1]=inptValue;nextSymbol();return 1;}return 0;}
static void must(int *a){if(inpt==a[0]){a[1]=inptValue;nextSymbol();}
  else{printf("** must() failed, a[0]=%d ",a[0]);printPointer(a); printf(" got=%d ",inpt);a[0]=inpt;printPointer(a);printf("\n");exit(8);}}

void nextSymbol(void);
void saveInputPoistion(void),restoreInputPosition(void);

void getTagData(int *a),getTagImage(int *a),
     putTagData(int *a),addLEXTentry(int *a);
void tryToOpenSource(int *a),closeSource(void);

/* ------------------------- */
void rehash_lexical(void);
void initialize_lexical(void);

/* EOF */
