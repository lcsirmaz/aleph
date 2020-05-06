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
  int fileError;
  FILE *f;
  int aheadchar;	// look ahead char
} a_CHARFILE;

typedef struct {
  int lwb,upb,hash;	// lower, upper bound, hash
} a_AREA;
#define a_MAXIMAL_AREA	32
typedef struct {
  unsigned openflag;	// how was it opened
  int fileError;	// last file error
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
extern int ext_list_virtual_start;
int a_extstrcmp(int table,int off,const char *str);
  /* compare the ALEPH string with the one given as the last argument */
void a_fatal(const char *m1,const char* m2);
  /* fatal error; print both strings before aborting */
void setup_list(int kind,int ID,int cal,int lb,int up,int fill);
void setup_external_list(int kind,int ID,int cal,const char *name);
void setup_charfile(int ID,int dir,int sID,int soff);
void setup_external_charfile(int ID,const char *name);
void setup_dfile(int ID,int dir,int sID,int soff,int narea);
void setup_external_dfile(int ID,const char*name);
void add_filearea(int ID,int aID,int hash);

void list_fill(int *fill);

/* the waitfor() routine calls all roots to check if it finished
 * initialization. x is the ID, y is a string to be checked.
 * return 0 if OK, 1 if this was not for it.
 */
#define a_MROOT(x,y)					\
int R##x(int table,int off){				\
 static int working=0;					\
 if(off!=0 && a_extstrcmp(table,off,y)!=0){ return 1;}	\
 if(working==0){working=2; x(); working=1;}		\
 else if(working!=1){a_fatal("recursive call",y);}	\
 return 0;						\
}

#endif
/* EOF */
