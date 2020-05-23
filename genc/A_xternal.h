/* A_xternal.h  */

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

#ifndef AXTERNAL_H
#define AXTERNAL_H

/********************************************************************
* standard externals
*
* External rules starting with a  non-letter. 
*  Functions with no repeat block are discarder if no out/inout affix
*  is used later.
*  The external string starts with @: it is replaced by underscore,
*  and a 0/1 is appended for each out affixe (see divrem below) as
*   0  -  dummy actual affix, affix skipped
*   1  -  not a dummy affix
*  Affixes are added as arguments:
*     dummy actual affix - empty
*     formal block start: number of pending affixes (not blocks);
*         if zero or negative then * is the last affix and ,a_C,a_V)
*         closes the argument list
*     the affix.
*
*   function,action:    closing ; added automatically
*   question,pradicate: possibly preceded by ! to negate (should be
*     bracketed)
********************************************************************/

#define __add(x,y,z)		z=x+y
#define __subtr(x,y,z)		z=x-y
#define __mult(x,y,z)		z=x*y
#define __addmult(x,y,z,u)	u=x*y+z
#define __div(x,y,z)		z=x/y
#define __incr(x)		x++
#define __decr(x)		x--
#define __getabs(x,y)		y=abs(x)
#define __max(x,y)		if(x>y){y=x;}
#define __min(x,y)		if(x<y){y=x;}
#define _divrem11(x,y,u,v)	{register int a_r=x%y;u=x/y;v=a_r;}
#define _divrem00(x,y)		{}
#define _divrem01(x,y,v)	v=x%y
#define _divrem10(x,y,u)	u=x/y

#define __is(x)			(x)
#define __boolinvert(x,y)	y=~x
#define __booland(x,y,z)	z=(x)&(y)
#define __boolor(x,y,z)		z=(x)|(y)
#define __boolxor(x,y,z)	z=(x)^(y)
#define __istrue(x)		(x!=0)
#define __isfalse(x)		(x==0)
#define __leftclear(x,n)	x<<=n
#define __rightclear(x,n)	x>>=n

#define __was(t,x)		(to_LIST(t)->alwb<=x&&x<=to_LIST(t)->aupb)
#define __next(t,p)		p+=to_LIST(t)->calibre
#define __previous(t,p)		p-=to_LIST(t)->calibre
#define __listlength(t,x)	x=to_LIST(t)->aupb-to_LIST(t)->alwb+to_LIST(t)->calibre
#define __unstackto(t,p)	to_LIST(t)->aupb=p
#define __unstack(t)		to_LIST(t)->aupb-=to_LIST(t)->calibre
#define __scratch(t)		to_LIST(t)->aupb=to_LIST(t)->alwb-to_LIST(t)->calibre

#define __stringlength(t,p,n)	n=to_LIST(t)->offset[p-1]
#define __stringwidth(t,p,n)	n=to_LIST(t)->offset[p]
#define __previousstring(t,p)	p-=to_LIST(t)->offset[p]
#define __unstackstring(t)	to_LIST(t)->aupb-=to_LIST(t)->offset[to_LIST(t)->aupb]

#define __getfileerror(f,x)	x=to_DFILE(f)->fileError

#define __equal(x,y)		(x==y)
#define __noteq(x,y)		(x!=y)
#define __more(x,y)		(x>y)
#define __lseq(x,y)		(x<=y)
#define __less(x,y)		(x<y)
#define __mreq(x,y)		(x>=y)

/********************************************************************
* External rules starting with a letter
*  are called as other ALEPH rules: out and input affixes are added
*  as int * at the end
********************************************************************/

/* list space allocation
*  'p' request space+[]st[]+>n
*    allocate additional n slots to the list st; fail if
*    no more virtual or physical space is available
*  'a' extension+[]st[]+>n
*    call request space and set pointer top; abort if fails.
*  'a' release+[]st[]
*    free all spaces allocated to the list st
*/
int a_requestspace(int ID,int n);
void a_extension(int ID,int n);
void a_release(int ID);

/* input/output */
/* 'p' open file+""f+>mode+t[]+>ptr
*    mode is /r/, /w/, or /a/, open the file as specified by the
*    string in list t and pointer ptr. Only character files can
*    be opened for append, data files cannot.
*/
int a_openfile(int F1,int F2,int F3,int F4);
/* 'p' close filep+""f
*    close the open file,
*/
int a_closefilep(int F1);
/* 'a' close file+""f
*    close file, abort if fails
*/
void a_closefile(int F1);
/* 'f' get file error+""f+errno>
*    retrieve the error code for the last operation on the file
*/
void a_getfileerror(int F1,int A[1]);
/* 'p' get char+""f+char>
*    read the next character from the character file f
*/
int a_getchar(int F1,int A[1]);
/* 'a' ahead char+""f+char>
*    look ahead; the next character to be returned by get char.
*    As the character is actually read, get file position returns
*    the next character position
*/
void a_aheadchar(int F1,int A[1]);
/* 'a'put char+""f+>char
*     put the utf-8 encoded character to the character file  */
void a_putchar(int F1,int F2);
/* 'a'put string+""f+t[]+>p
*     put the string to the file
*/
void a_putstring(int F1,int F2,int F3);
/* 'p'put datap+""f+>data+>type
      put the data of type 0/1 to the datafile. Fail if there was
      a problem, see get file error
*/
int a_putdatap(int F1,int F2,int F3);
/* 'a'put data+""f+>data+>type
*     put data of type 0/1 to the datafile. Abort if fails.
*/
void a_putdata(int F1,int F2,int F3);


#endif

/* EOF */

