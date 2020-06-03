/* display.ale header file */

/* enquire about error messages */
int wasError(void);
void getErrorNo(int *a);
void clearLocalError(int *a);
int wasLocalError(int *a);
/* issue error/warning messages */
void Error(int n,int *v);
void Xerror(int line,int n,int *v);
void Warning(int level,int n,int *v);
void Xwarning(int level,int line,int n,int *v);
void message(int n,int *v);
/* this routine never returns */
void internalError(int,int *a);
/* 'a'display char+>char+>show */
void displayChar(int *a);
/* 'a' reset pr line. */
void resetPrLine(void);
/* dictionary printing */
void DICTheader(int *a),DICTitem(int *a),DICTtail(void);

/* initialization ******************* */
/* add new strings to MESSAGE */
void initialize_display(void);

/* DEBUGGING */
void printPointer(int *a),print(int *a);


/* EOF */

