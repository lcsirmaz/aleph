/* error.ale header */

void internalError(const char*f,int a),corruptedIceFile(const char *f,int a);
void error(int n,int *a),warning(int n,int *a),Ferror(int n,int *a);
int wasError(void);
void printPointer(int*a); /* DEBUG only */


void initialize_error(void);

/* EOF */

