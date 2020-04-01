/* input.ale header file */

void readSources(void);
void readStdlib(void);
void addRequiredSource(int *a);
void addIncludedSource(int *a);
void findLinenum(int *a); /* >n+line>+str> */
/* line numbers */
int nextInputEntry(int *a);
/* initialization */
void initialize_input(void);

/* EOF */
