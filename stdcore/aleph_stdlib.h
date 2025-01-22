/* aleph stdlib header file */

/*******************************************************************
*  This code is part of ALEPH-M (Modular ALEPH-v2)
*
*  (C) 2020-2023, L.Csirmaz
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
#ifndef ALEPH_STDLIB_H
#define ALEPH_STDLIB_H

/********************************************************************
* standard externals
*
* External rule string starting with underscore or @:
*  Functions with no no out/inout affix and no repeat affix block are
*  discarded.
* rule string starts with @ (macro):
*  0/1 is appended for each out affix (see divrem below) as
*     0  -  dummy actual affix, affix skipped
*     1  -  not a dummy affix
* rule string starts with underscore (macro):
*     dummy actual affix - empty
*     formal anchor: number of blocks;
*         if zero or negative then after that many blocks a_C,a_V
*         is added (that is, the actual affix list ends with +@)
*     otherwise the affix itself
*
* function,action:    closing semicolon is added automatically
* question,pradicate: possibly preceded by ! to negate
*
* External rule starting with a letter:
*  standard aleph calling syntax:
*   not out and inout affixes first, then an array
*   repeat affix block: other affixes followed by int a_C
*     (number of blocks, >=1), then an array containing all
*     affixes of the variable block
********************************************************************/
#include <stdlib.h> /* exit(), abs() */

/* macro externals */
#define a_add(x,y,z)            z=x+y
#define a_subtr(x,y,z)          z=x-y
#define a_mult(x,y,z)           z=x*y
#define a_addmult(x,y,z,u)      u=x*y+z
#define a_div(x,y,z)            z=x/y
#define a_incr(x)               x++
#define a_decr(x)               x--
#define a_getabs(x,y)           y=abs(x)
#define a_max(x,y)              if(x>y){y=x;}
#define a_min(x,y)              if(x<y){y=x;}
#define a_divrem11(x,y,u,v)     {register int a_r=x%y;u=x/y;v=a_r;}
#define a_divrem00(x,y)         {;}
#define a_divrem01(x,y,v)       v=x%y
#define a_divrem10(x,y,u)       u=x/y

#define a_is(x)                 (x)
#define a_boolinvert(x,y)       y=~x
#define a_booland(x,y,z)        z=(x)&(y)
#define a_boolor(x,y,z)         z=(x)|(y)
#define a_boolxor(x,y,z)        z=(x)^(y)
#define a_istrue(x)             (x!=0)
#define a_isfalse(x)            (x==0)
#define a_leftclear(x,n)        x<<=n
#define a_rightclear(x,n)       *(unsigned*)&(x)>>=n

#define a_was(t,x)              (to_LIST(t)->alwb<=x&&x<=to_LIST(t)->aupb)
#define a_next(t,p)             p+=to_LIST(t)->calibre
#define a_previous(t,p)         p-=to_LIST(t)->calibre
#define a_listlength(t,x)       x=to_LIST(t)->aupb-to_LIST(t)->alwb+to_LIST(t)->calibre
#define a_unstackto(t,p)        to_LIST(t)->aupb=p
#define a_unstack(t)            to_LIST(t)->aupb-=to_LIST(t)->calibre
#define a_scratch(t)            to_LIST(t)->aupb=to_LIST(t)->alwb-to_LIST(t)->calibre

#define a_stringlength(t,p,n)   n=to_LIST(t)->offset[p-1]
#define a_stringwidth(t,p,n)    n=to_LIST(t)->offset[p]
#define a_previousstring(t,p)   p-=to_LIST(t)->offset[p]
#define a_unstackstring(t)      to_LIST(t)->aupb-=to_LIST(t)->offset[to_LIST(t)->aupb]

#define a_getfileerror(f,x)     x=to_CHFILE(f)->fileError

#define a_equal(x,y)            (x==y)
#define a_noteq(x,y)            (x!=y)
#define a_more(x,y)             (x>y)
#define a_lseq(x,y)             (x<=y)
#define a_less(x,y)             (x<y)
#define a_mreq(x,y)             (x>=y)

#ifdef a_CALL_STACK
#define a_exit(x)		{a_backtrack(&a_Ltr,x);exit(x);}
#define a_xbacktrack()		a_backtrack(&a_Ltr,0)
#else
#define a_exit(x)		exit(x)
#define a_xbacktrack()		{;} /* ignore */
#endif

/* prototypes */
/* list */
extern void a_release(int a_F1); /* release */
extern int a_requestspace(int a_F1,int a_F2); /* requestspace */
/* string */
extern void a_comparestring(int a_F1,int a_F2,int a_F3,int a_F4,int a_A[1]); /* comparestring */
extern void a_comparestringn(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_A[1]); /* comparestringn */
extern int a_stringelem(int a_F1,int a_F2,int a_F3,int a_A[1]); /* stringelem */
extern void a_packstring(int a_F1,int a_F2,int a_F3); /* packstring */
extern void a_unpackstring(int a_F1,int a_F2,int a_F3); /* unpackstring */
extern void a_copystring(int a_F1,int a_F2,int a_F3); /* copystring */
/* file */
extern int a_openfile(int a_F1,int a_F2,int a_F3,int a_F4); /* openfile */
extern int a_opentempfile(int a_F1,int a_F2,int a_F3); /* opentempfile */
extern void a_closefile(int a_F1); /* closefile */
extern void a_unlinkfile(int a_F1,int a_F2); /* unlinkfile */
extern void a_getfilepos(int a_F1,int a_A[1]); /* getfilepos */
extern void a_setfilepos(int a_F1,int a_F2); /* setfilepos */
extern int a_getchar(int a_F1,int a_A[1]); /* getchar */
extern int a_aheadchar(int a_F1,int a_A[1]); /* aheadchar */
extern void a_putchar(int a_F1,int a_F2); /* putchar */
extern int a_getdata(int a_F1,int a_A[2]); /* getdata */
extern void a_putdata(int a_F1,int a_F2,int a_F3); /* putdata */
extern int a_putdatap(int a_F1,int a_F2,int a_F3); /* putdatap */

#endif /* ALEPH_STDLIB_H */

/* EOF */
