/* aleph C runtime environemnt header */

/*******************************************************************
*  This code is part of ALEPH-M (Modular ALEPH-v2.3)
*
*  (C) 2020-2025, L.Csirmaz
*
*  ALEPH-M is a free software, your can redistribute and/or
*  modify it under the terms of the GNU General Public License
*  as published by the Free Software Foundation, either version
*  3 of the License, or (at your option) any later version.
*
*  ALEPH-M is distributed in the hope that it will be useful,
*  but  WITHOUT ANY WARRANTY; without even the implied warranty
*  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
*  the GNU General Public License for more details.
*
********************************************************************/
#ifndef ALEPH_CORE_H
#define ALEPH_CORE_H

#include <stdio.h>
#include <string.h> /* memcpy */

/*******************************************************************
*  Basic ALEPH data structures
*
*  A list, character and datafile is an index to the integer array
*  a_DATABLOCK[], which stores structures a_LIST, a_CHARFILE, and
*  a_DATAFILE. Macros 
*      to_LIST(), to_CHFILE(), to_DFILE()
*  generate a pointer to the structure from the index (the ALEPH value).
*
*  Charater input/output
*   standard character stream fopen, fclose, getc, putc, fseek,
*   converting UTF-8 representation on the fly.
*
*  Data input/output
*   buffered direct input in 1024*sizeof(int) blocks; the current
*   block is stored as a buffer.
* 
********************************************************************/

/* ALEPH stack and table */
typedef struct {
  const char *name;	// list name
  int *offset;		// offset for virtual index
  int *p;		// pointer to the beginning
  int length;		// length of the block
  int alwb,aupb;	// actual lower an upper bound
  int vlwb,vupb;	// virtual lower and upped bound
  int calibre;
} a_LIST;

/* ALEPH character file */
typedef struct {
  const char *name;	// character file ALEPH name
  unsigned openflag;	// several file flags
  int fileError;	// last file error
  int st1,st2;		// string pointers
  FILE *f;              // stream handle
  int aheadchar;        // look ahead char
  int aheadpos;		// if read ahead, the last position
} a_CHARFILE;

/* ALEPH data file */
typedef struct {
  int lwb,upb,data;	// lower, upper bound, data
} a_AREA;
#define a_MAXIMAL_AREA  32
typedef struct {
  const char *name;	// data file ALEPH name
  unsigned openflag;	// several file flags
  int fileError;	// last file error
  int st1,st2;		// string pointers
  int fhandle;		// zero if not opened
  int fpos;		// filepos
  unsigned iflag;	// pointer/numerical flag for 32 items
  int inarea,outarea;	// number of areas
  a_AREA in[a_MAXIMAL_AREA];
  a_AREA out[a_MAXIMAL_AREA];
  int buffer[1024];
} a_DATAFILE;

/* list, charfile, datafile structures are in */
extern int a_DATABLOCK[];

#define sizeof_LIST     (int)(sizeof(a_LIST)/sizeof(int))
#define sizeof_DFILE    (int)(sizeof(a_DATAFILE)/sizeof(int))
#define sizeof_CHFILE   (int)(sizeof(a_CHARFILE)/sizeof(int))

#define to_LIST(x)      ((a_LIST*)(a_DATABLOCK+(x)))
#define to_DFILE(x)     ((a_DATAFILE*)(a_DATABLOCK+(x)))
#define to_CHFILE(x)    ((a_CHARFILE*)(a_DATABLOCK+(x)))

/********************************************************************
*  Memory management
*  int *a_extension(ID,n)
*    ID       index in a_DATABLOCK for a stack
*    n        check, and if necessary add more memory to the list ID
*             so it has at lest n more words at the top, return the
*             address of the first empty slot
*
*  int a_requestspace(ID,n)
*    ID       index in a_DATABLOCK for a stack
*    n        make sure ID has n more words at the top
*
********************************************************************/
extern int *a_extension(int ID,int n);
extern int a_requestspace(int ID,int n);

/********************************************************************
*  Data structure initialization
*
*  void a_setup_list(kind,ID,name,calibre,lwb,upb,fill_size)
*    kind     0 for table, 1 for stack
*    ID       index in a_DATABLOCK, use to_LIST(ID) to get the 
*             pointer to the corresponding structure
*    name     name of the list
*    calibre  calibre (1 or more)
*    lwb,upb  virtual lower and upper bound for this list
*    fill_size  allocate at least that much space (can be zero)
*
*  void a_list_fill(int *T)
*    T        pointer to the integer array containing description
*             of all table and stack filling
*
*  void a_setup_charfile(ID,name,dir,sID,soff)
*    ID       index in a_DATABLOCK, use to_CHFILE(ID) to get the
*             pointer to the corresponding structure
*    name     name of the file
*    dir      0,1: input, 2,3: output direction
*    sID,soff list and pointer (ALEPH values) to the string in
*             the declaration, giving the file name and direction
*             if not opened explicitly
*
*  void a_setup_dfile(ID,name,dir,sID,soff,narea)
*    ID       index in a_DATABLOCK, use to_DFILE(ID) to get the
*             pointer to the corresponding structure
*    name     name of the file
*    dir      0,1: input, 2,3: output direction
*    sID,soff list and pointer (ALEPH values) to the string in
*             the declataion
*    narea    number of lists in file area (can be zero)
*
*  void a_add_filearea(ID,list_ID,count)
*    ID       index of the datafile
*    list_ID  index of the list to be added to the list of areas
*    count    position starting from 1
*
********************************************************************/
extern int a_virtual_min,a_virtual_max;
extern void a_setup_list(int kind,int ID,const char*name,
                             int cal,int lb,int up,int fill);
extern void a_setup_charfile(int ID,const char*name,
                             int dir,int sID,int soff);
extern void a_setup_dfile(int ID,const char*name,int dir,
                             int sID,int soff,int narea);
extern void a_add_filearea(int ID,int aID,int hash);
extern void a_list_fill(int *fill);

/********************************************************************
*  auxiliary functions
*
* int a_extstrcmp(sID,soff,char *str)
*  compare an ALEPH atring and a C string for equality
*    sID,soff list and pointer the an ALEPH string
*    str      a C string
*  return value: 1 - equal, 0 - not equal
*
* void a_fatal(int code)
*  abort the ALEPH program after an error
*
* void a_area_failed(char *rule,int v)
*  none of the cases in a classification succeeds
*    rule     the rule, or NULL if no rule name (root)
*    v        the offending value
*
* void a_index_error(int L,int idx,char*rule)
*  index is out of range, give an error message
*    L        index of list
*    idx      the index
*    rule     rule where the error happened
********************************************************************/
/* fatal error values */
typedef enum{
  a_FATAL_waitfor=1,	/* circular waitfor call */
  a_FATAL_string,	/* string manipulating error */
  a_FATAL_area,		/* classification area */
  a_FATAL_datafile,	/* datafile problem */
  a_FATAL_memory,	/* memory problem */
  a_FATAL_index		/* index error */
} ErrorCodes;

extern int a_extstrcmp(int table,int off,const char *str);
extern void a_fatal(int code);
extern void a_area_failed(const char *rule,int v);
extern void a_index_error(int L,int idx,const char*rule);


/********************************************************************
* call stack,
*
* a_CALL STACK
*  is defined when linked with the -g option. The first parameter
*  of each rule is a_tr of type a_CALLp; the first argument of
*  each rule call is &a_Ltr.
* a_addto_callstack(rulename)
* a_unused_callstack(rulename)
*  create the local call block a_Ltr; suppress "not used" warning
* a_addto_callstack_bottom()
*  create the bottom call stack element in the main @root
* a_backtrack(top,code)
*  print the call stack starting at top; if code!=0 it is from exit
********************************************************************/

typedef struct a_CALL{
  const char *rule;struct a_CALL *next; } a_CALL;
typedef a_CALL *a_CALLp;

#define a_addto_callstack(rulename)			\
   a_CALL a_Ltr={rulename,a_tr}
#define a_unused_callstack(rulename)			\
   a_CALL __attribute__((unused)) a_Ltr={rulename,a_tr}
#define a_addto_callstack_bottom()			\
   a_CALL a_Ltr={NULL,NULL}

extern void a_backtrack(a_CALLp tr,int);

/********************************************************************
* Profile and trace
*
* a_profile_def(thispf,rulename,prevpf)
*  creates thispf profile and links to prevpf. The rule must contain
* a_profiling(thispf)
*  which increases the counter value in the specified profile
*
* a_trace_rule(rulename,argno,arg1,...)
*  is called; argno is the number of traced arguments
*  (all not out arguments including the first variable block)
********************************************************************/

typedef struct a_PROFILE_ {
  unsigned long int count;
  const char        *rulename;
  struct a_PROFILE_ *link;
} a_PROFILE;

#define a_profile_def(thispf,rulename,prevpf)		\
  static a_PROFILE thispf={0uL,rulename,prevpf}
#define a_profiling(thispf)				\
  thispf.count++

void a_trace_rule(const char*rname,int affixno,...);

/********************************************************************
* waitfor+t[]+>ptr rule
*
*  During initialization all module roots are called. The waitfor rule
*  makes sure that the root of the argument module is executed. 
*  The macro
*            a_MODROOT(module_root,"modulename")
*  creates the snippet which is included in a_waitfor(a_F1,a_F2) for
*  all modules with non-empty root. The snippet checks if the request
*  is for this module, and then executes the  module root. Circular
*  request is fatal.
********************************************************************/

#ifdef a_CALL_STACK
#define a_MODROOT(x,name)				\
  if(a_F2==0 || a_extstrcmp(a_F1,a_F2,name)==0){	\
    static int working=0;				\
    if(working==0){working=2;x(&a_Ltr);working=1;}	\
    else if(working!=1){				\
      a_backtrack(&a_Ltr,-1);a_fatal(a_FATAL_waitfor);}	\
  }
#else  /* no CALL_STACK */
#define a_MODROOT(x,name)				\
  if(a_F2==0 || a_extstrcmp(a_F1,a_F2,name)==0){	\
    static int working=0;				\
    if(working==0){working=2;x();working=1;}		\
    else if(working!=1){a_fatal(a_FATAL_waitfor);}	\
  }
#endif /* CALL_STACK */

/********************************************************************
* list access with bound check
*
*  With bound checking enabled, list access is translated to
*    to_LIST(L)->offset[a_listelem(L,idx,selector,rulename)]
*  the procedure a_listelem() is defined here to be inlined
*
********************************************************************/

#ifdef a_CALL_STACK
inline static int a_listelem(a_CALLp bt,int L,register int idx,
         const int off,const char *rname)
{   if(idx-off<=to_LIST(L)->alwb-to_LIST(L)->calibre ||
       idx > to_LIST(L)->aupb){
         a_index_error(L,idx,rname),a_backtrack(bt,-1);
         a_fatal(a_FATAL_index);}
    return idx-off;
}
#else /* no CALL_STACK */
inline static int a_listelem(int L,register int idx,int off,
             const char *rname)
{   if(idx-off<=to_LIST(L)->alwb-to_LIST(L)->calibre ||
       idx > to_LIST(L)->aupb){
         a_index_error(L,idx,rname);a_fatal(a_FATAL_index); }
    return idx-off;
}
#endif /* CALL_STACK */

#endif /* ALEPH_CORE_H */

/* EOF */
