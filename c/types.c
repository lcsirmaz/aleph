/* types.c */

#include "stddata.h"
#include "types.h"
#include "tags.h"

/* --------------------------------------------- */

int
  Iempty,		Iconstant,		Ivariable,
  IstaticVar,		IstaticConst,		Itable,
  Istack,		IstaticStack,
  Iselector,		IpointerConstant,	Icharfile,
  Idatafile,		Irule,			IfirstFormalType,
  IformalSelector,	IformalStack,		IformalTable,
  IformalFile,		IformalIn,		IformalOut,
  IformalInout,		IformalRepeat,		IformalShift,
  Imacro,		Inoarg,			Ilocal,
  Ilabel;

#define addtoIND(x,y)	add_new_string(x,INDICATOR);y=INDICATOR->aupb
void initialize_types(void){
  addtoIND("undefined",Iempty);
  addtoIND("constant",Iconstant);
  addtoIND("variable",Ivariable);
  addtoIND("static var",IstaticVar);
  addtoIND("static const",IstaticConst);
  addtoIND("table",Itable);
  addtoIND("stack",Istack);
  addtoIND("static stack",IstaticStack);
//  addtoIND("static table",IstaticTable);
  addtoIND("selector",Iselector);
  addtoIND("pointer constant",IpointerConstant);
  addtoIND("charfile",Icharfile);
  addtoIND("datafile",Idatafile);
  addtoIND("rule",Irule);
/* forma types come at the end */
  addtoIND("formal",IfirstFormalType);
  addtoIND("formal selector",IformalSelector);
  addtoIND("formal stack",IformalStack);
  addtoIND("formal table",IformalTable);
  addtoIND("formal file",IformalFile);
  addtoIND("formal in",IformalIn);
  addtoIND("formal out",IformalOut);
  addtoIND("formal inout",IformalInout);
  addtoIND("formal repeat",IformalRepeat);
  addtoIND("formal shift",IformalShift);
  addtoIND("macro parameter",Imacro);
  addtoIND("dummy argument",Inoarg);
  addtoIND("local",Ilocal);
  addtoIND("label",Ilabel);
}
#undef addtoIND

int wasTypePointer(int *a){/* >ptr + []st[] */
  int par[3];
  par[0]=STACKpar(INDICATOR);par[1]=a[0];
  if(was(par)){par[2]=a[1];copystring(par);return 1;}
  return 0;
}
int hasFormalType(int *a){/* >tag */
  int par[2];
  par[0]=a[0];getType(par);if(par[1]>=IfirstFormalType){return 1;}
  return 0;
}

/* EOF */


