/* A_lice.h */

/********************************************************************
*  This code is part of ALEPH-M (Modular ALEPH)
* 
*  (C) 2020, L.Csirmaz, Hungary.
*
*  ALEPH-M is free software: you can redistribute and/or modify it
*  under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  ALEPH-M is distributed in the hope that it will be useful, but
*  WITHOUT ANY WARRANTY; without even the implied warranty of 
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
*  General Public License for more details.
*
********************************************************************/

#ifndef ALICE_H
#define ALICE_H

#include <stdio.h>
#include <stdlib.h>	// abs

/********************************************************************
*  Basic ALEPH data structures
*
*  A list, character and datafile is an index to the integer array
*  a_DATABLOCK[], consisting of structures a_LIST, a_CHARFILE,
*  a_DATAFILE, correspondingly. Use the macros 
*      to_LIST(), to_CHFILE(), to_DFILE()
*  to get the structure from the a_DATABLOCK index (the ALEPH value).
*
*  Charater input/output
*   uses standard character stream fopen, fclose, getc, putc, fseek
*
*  Data input/output
*   an indicator bit is added to each item; this is stored in an
*   internal buffer. File area is identified by the hash of the list
*   name, and not by its position in the list.
* 
********************************************************************/

/* ALEPH stack and table */
typedef struct {
  int *offset;		// offset for virtual index
  int *p;		// pointer to the beginning
  int *top;		// pointer to the top
  int length;		// length of the block
  int alwb,aupb;	// actual lower an upper bound
  int vlwb,vupb;	// virtual lower and upped bound
  int calibre;
} a_LIST;

/* ALEPH character file */
typedef struct {
  unsigned openflag;	// how was it opened
  int fileError;	// last file error
  int st1,st2;		// string pointers
  FILE *f;		// stream handle
  int aheadchar;	// look ahead char
} a_CHARFILE;

/* ALEPH data file */
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

/* list, charfile, datafile structures are in */
extern int a_DATABLOCK[];

#define sizeof_LIST	(sizeof(a_LIST)/sizeof(int))
#define sizeof_DFILE	(sizeof(a_DATAFILE)/sizeof(int))
#define sizeof_CHFILE	(sizeof(a_CHARFILE)/sizeof(int))

#define to_LIST(x)	((a_LIST*)(a_DATABLOCK+(x)))
#define to_DFILE(x)	((a_DATAFILE*)(a_DATABLOCK+(x)))
#define to_CHFILE(x)	((a_CHARFILE*)(a_DATABLOCK+(x)))

/********************************************************************
*  Data structure initialization
*
*  void a_setup_list(kind,ID,calibre,lwb,upb,fill_size)
*    kind     0 for table, 1 for stack
*    ID       index in a_DATABLOCK, use to_LIST(ID) to get the 
*             pointer to the corresponding structure
*    calibre  calibre (1 or more)
*    lwb,upb  virtual lower and upper bound for this list
*    fill_size  allocate at least that much space (can be zero)
*
*  void a_list_fill(int *T)
*    T        pointer to the integer array containing description
*             of all table and stack filling
*
*  void a_setup_charfile(ID,dir,sID,soff)
*    ID       index in a_DATABLOCK, use to_CHFILE(ID) to get the
*             pointer to the corresponding structure
*    dir      0,1: input, 2,3: output direction
*    sID,soff list and pointer (ALEPH values) to the string in
*             the declaration, giving the file name and direction
*             if not opened explicitly
*
*  void a_set_dfile(ID,die,sID,soff,narea)
*    ID       index in a_DATABLOCK, use to_DFILE(ID) to get the
*             pointer to the corresponding structure
*    dir      0,1: input, 2,3: output direction
*    sID,soff list and pointer (ALEPH values) to the string in
*             the declataion
*    narea    number of lists in file area (can be zero)
*
*  void a_add_filearea(ID,list_ID,hash)
*    ID       index of the datafile
*    list_ID  index of the list to be added to the list of areas
*    hash     the hash of the list name, to identify lists
*
********************************************************************/
void a_setup_list(int kind,int ID,int cal,int lb,int up,int fill);
void a_setup_charfile(int ID,int dir,int sID,int soff);
void a_setup_dfile(int ID,int dir,int sID,int soff,int narea);
void a_add_filearea(int ID,int aID,int hash);
void a_list_fill(int *fill);

/********************************************************************
*  auxiliary functions
*
* compare an ALEPH atring and a C string for equality
*  int a_extstrcmp(sID,soff,char *str)
*    sID,soff list and pointer the an ALEPH string
*    str      a C string
*  return value: 1 - equal, 0 - not equal
*
* abort the ALEPH program
*  void a_fatal(char *mess1, char *mess2)
*    messages to be printed to stderr before aborting the program
*
* none of the cases in a classification succeeded
*  void a_area_failed(char *rule,int v)
*    rule     the rule, or NULL if the rule name is not avaialable
*    v        the offending value
********************************************************************/
int a_extstrcmp(int table,int off,const char *str);
void a_fatal(const char *m1,const char* m2);
void a_area_failed(const char *rule,int v);

/********************************************************************
* waitfor("module") rule
*
*  During initialization all module roots are called. The waitfor rule
*  makes sure that the root of the module in the argument was executed. 
*  The macro
*            a_MROOT(module_root,"modulename")
*  creates the procedure which is called by waitfor(): it checks if
*  the request is for this module, and if yes, the module root has
*  been executed, is under execution (which is fatal), or can be
*  executed, when executes it.
********************************************************************/
#define a_MROOT(x,y)					\
int a_R##x(int table,int off){				\
 static int working=0;					\
 if(off!=0 && a_extstrcmp(table,off,y)!=0){ return 0;}	\
 if(working==0){working=2; x(); working=1;}		\
 else if(working!=1){a_fatal("recursive call",y);}	\
 return 1;						\
}

/********************************************************************
* profile and trace
*
*  If the count / trace option is set, the rule name is stored as
*  a_rulename (static char*).
* a_PROFILING(profile_struct,rulename)
*  adds the code, which, at each entry, increases a counter, and
*  links the static profile structure.
* a_trace_rule(rulename,argno,args,...)
*  is called for tracing; argno is the number of traced arguments
*  all not out arguments up to the first dynamic block.
********************************************************************/
typedef struct a_PROFILE_ {
  unsigned long int count;
  const char        *rulename;
  struct a_PROFILE_ *link;
} a_PROFILE;
extern a_PROFILE *a_profiles;
#define a_PROFILING(x,y)				\
  if(0ul==x.count++){x.link=a_profiles;			\
            x.rulename=y;a_profiles=&x;}

void a_trace_rule(const char*name,int affixno,...);

/********************************************************************
* include standard external head files
********************************************************************/
#include "A_xternal.h"

#endif
/* EOF */
