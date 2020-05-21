/* A_xternal.h 
 * ALEPH target def header file
 * (C) 2020, L.Csirmaz
 */

#ifndef AXTERNAL_H
#define AXTERNAL_H
/* arithmetical operators */
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
#define _divrem11(x,y,u,v)	u=x/y;v=x%y
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

#endif

/* EOF */

