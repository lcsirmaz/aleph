/* types.ale header file */
#ifndef TYPES_H
#define TYPES_H

/* types */
extern int
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

  /* 'p'was type pointer+>ptr+[]st[]. */
int wasTypePointer(int *a); 
int hasFormalType(int *a);

void initialize_types(void);

#endif /* TYPES_H */
/* EOF */

