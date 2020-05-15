/* pragmats.ale header file */
#ifndef PRAGMATS_H
#define PRAGMATS_H

#define pgtTabwidth	0x345600
#define pgtWarningLevel	0x345601
#define pgtProto	0x345602
#define pgtTitle	0x345603
#define pgtModule	0x34560f
#define pgtText		0x345604
#define pgtLibrary	0x345605
#define pgtCompile	0x345606
#define pgtDict         0x345607
#define pgtBounds	0x345608
#define pgtTrace	0x345609
#define pgtCount	0x34560a
#define pgtStdlib	0x34560b
#define pgtMargin       0x34560c
#define pgtMacro	0x345610
#define pgtPublic	0x345611
#define pgtPath		0x345612
#define pgtIce		0x345613
#define pgtSkip         0x34560d

/* 'f'get pragmat value+>id+val> */
void getPragmatValue(int *a);
/* 'q'is pragmat value+>id */
int isPragmatValue(int *a);
void setPragmatValue(int *a);
/* ------------- */
void cmdlinePragmat(void);
void programPragmat(int *a);
void resetPragmats(void);

void initialize_pragmats(void);
/* add pragmat tags to TTAG */

#endif /* PRAGMATS_H */

/* EOF */

