/* A_lice.h
 * ALEPH target header file
 * (C) 2020, L.Csirmaz
 */

#ifndef ALICE_H
#define ALICE_H

/* list, char and datafile are structures stored in
   the array int a_DATABLOCK[] */

typedef struct {
  int *offset;		// offset[idx]
  int *p;		// pointer to the beginning
  int length;		// length of the block
  int alwb,aupb;
  int vlwb,vupb;
  int calibre;
} a_LIST;

#include <stdio.h>
typedef struct {
  unsigned openflag;	// how was it opened
  int fileError;	// last file error
  int st1,st2;		// string pointers
  FILE *f;		// stream handle
  int aheadchar;	// look ahead char
} a_CHARFILE;

typedef struct {
  int lwb,upb,data;	// lower, upper bound, data
} a_AREA;
#define a_MAXIMAL_AREA	32
typedef struct {
  unsigned openflag;	// how was it opened
  int fileError;	// last file error
  int st1,st2;		// string pointers
  int fhandle;		// zero if not opened
  int fpos;		// filepos
  unsigned iflag;	// pointer/numerical flag
  int inarea,outarea;	// number of areas
  a_AREA in[a_MAXIMAL_AREA];
  a_AREA out[a_MAXIMAL_AREA];
  int buffer[1024];
} a_DATAFILE;

extern int a_DATABLOCK[];

#define sizeof_LIST	(sizeof(a_LIST)/sizeof(int))
#define sizeof_DFILE	(sizeof(a_DATAFILE)/sizeof(int))
#define sizeof_CHFILE	(sizeof(a_CHARFILE)/sizeof(int))

#define to_LIST(x)	((a_LIST*)(a_DATABLOCK+(x)))
#define to_DFILE(x)	((a_DATAFILE*)(a_DATABLOCK+(x)))
#define to_CHFILE(x)	((a_CHARFILE*)(a_DATABLOCK+(x)))

/* routines handling initialization */
int a_extstrcmp(int table,int off,const char *str);
  /* compare the ALEPH string with the one given as the last argument */
void a_fatal(const char *m1,const char* m2);
  /* fatal error; print both strings to stderr and abort */
void a_setup_list(int kind,int ID,int cal,int lb,int up,int fill);
void setup_charfile(int ID,int dir,int sID,int soff);
void setup_dfile(int ID,int dir,int sID,int soff,int narea);
void add_filearea(int ID,int aID,int hash);
void a_list_fill(int *fill);

/* the waitfor() routine calls all roots to check if it finished
 * initialization. x is the ID, y is a string to be checked.
 * return 1 if OK and 0 if this was not for this module.
 */
#define a_MROOT(x,y)					\
int a_R##x(int table,int off){				\
 static int working=0;					\
 if(off!=0 && a_extstrcmp(table,off,y)!=0){ return 0;}	\
 if(working==0){working=2; x(); working=1;}		\
 else if(working!=1){a_fatal("recursive call",y);}	\
 return 1;						\
}
/* global variables: command-line arguments;
  virtual address for external lists */
extern int a_argc; extern char *a_argv[];
extern int a_extlist_virtual;

/* extension */

  /* 'p' request space+[]st[]+>n */
int a_requestspace(int ID,int n);
  /* 'a'extension+[]st[]+>n */
void a_extension(int ID,int n);
  /* 'a'release+[]st[] */
void a_release(int ID);

/* input/output */

  /* 'p'open file+""f+>mode+t[]+>ptr */
int a_openfile(int F1,int F2,int F3,int F4);
  /* 'p'close filep+""f */
int a_closefilep(int F1);
  /* 'a'close file+""f */
void a_closefile(int F1);
  /* 'p'get char+""f+char> */
int a_getchar(int F1,int A[1]);
  /* 'a'ahead char+""f+char> */
void a_aheadchar(int F1,int A[1]);
  /* 'a'put char+""f+>char */
void a_putchar(int F1,int F2);
  /* 'a'put string+""f+t[]+>p */
void a_putstring(int F1,int F2,int F3);
  /* 'p'put datap+""f+>data+>type */
int a_putdatap(int F1,int F2,int F3);
  /* 'a'put data+""f+>data+>type */
void a_putdata(int F1,int F2,int F3);

#endif
/* EOF */
