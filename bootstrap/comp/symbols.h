/* symbols.ale header file */

#ifndef SYMBOLS_H
#define SYMBOLS_H

extern int inpt;
void nextSymbol(void);

/* restore facility */
void initRestore(void),makeRestore(void),forgetRestore(void);


#define ahead(x)	((x)==inpt)
int R(int *a);
void Rskip(int *a);
void must(int *a);
void skipSilently(void);
void skipToPoint(void);
void skipAll(void);

int isRawTag(int *a),isTag(int *a),isTagdl(int *a);
int isCons(int *a),aheadCons(void);
int isString(int *a);
void getLinenum(int *a),setLinenum(int *a);
void advanceLinenum(void);

/*---------------------------- */
void initialize_symbols(void);

#endif /* SYMBOLS_H */

/* EOF */
