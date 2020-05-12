/* aleph standard library header file */

#ifndef __STDLIB_H
#define __STDLIB_H

/* calling convention:
  predicate, question:  int PROC( int *arg), or int PROC(void)
  action, function:     void PROC( int *arg), or void PROC(void)

argument: arg[0],arg[1],...arg[n], both for input and output

stack: 
typedef struct{
   int *offset;
   int *p;          // pointer to the beginning
   int length;      // length of the allocated block
   int alwb,aupb;   // actual lwer and upper bound
   int vlwb,vupb;   // virtual lower, upper bound
   int calibre;     // calibre of the stack
} aSTACK;

file: charfile: standard FILE* structure

*/

/* exit prototype */
void exit(int);

/* standard local routines */

#define UNUSED	__attribute__((unused));
static void add() UNUSED
static void subtr() UNUSED
static void mult() UNUSED
static void addmult() UNUSED
static void div() UNUSED
static void divrem() UNUSED
static void incr() UNUSED
static void decr() UNUSED
static void getabs() UNUSED
static void max() UNUSED
static void min() UNUSED
static int false UNUSED static int true UNUSED
static int is() UNUSED
static void boolinvert() UNUSED
static void booland() UNUSED
static void boolor() UNUSED
static void boolxor() UNUSED
static int istrue() UNUSED
static int isfalse() UNUSED
static void extractbits() UNUSED
static void leftclear() UNUSED
static void rightclear() UNUSED
#undef UNUSED

static void add(int *a){ a[2]=a[0]+a[1]; }
static void subtr(int *a){ a[2]=a[0]-a[1]; }
static void mult(int *a){ a[2]=a[0]*a[1]; }
static void addmult(int *a){a[3]=a[0]*a[1]+a[2]; }
static void div(int *a){ a[2]=a[0]/a[1]; }
static void divrem(int *a){ a[2]=a[0]/a[1]; a[3]=a[0]%a[1]; }
static void incr(int *a){ a[0]++; }
static void decr(int *a){ a[0]--; }
static void getabs(int *a){ a[1]=((a[0]<0)?(-a[0]):a[0]); }
static void max(int *a){ if(a[0]>a[1]) a[1]=a[0]; }
static void min(int *a){ if(a[0]<a[1]) a[1]=a[0]; }
static int false=0, true=1;
static int is(int *a){ return a[0]?1:0; }
static void boolinvert(int *a){a[1]=~a[0]; }
static void booland(int *a){a[2]=a[0]&a[1]; }
static void boolor(int *a){a[2]=a[0]|a[1]; }
static void boolxor(int *a){a[2]=a[0]^a[1]; }
static int istrue(int *a){ return a[0]?1:0; }
static int isfalse(int *a){ return a[0]?0:1; }
static void extractbits(int *a){a[2]=((1<<a[1])-1)&a[0]; }
static void leftclear(int *a){((unsigned*)a)[0]<<=a[1];}
static void rightclear(int *a){((unsigned*)a)[0]>>=a[1];}


extern int __STATIC[];

#define parSTACK(x)     ((aSTACK*)(__STATIC+(x)))
#define STACKpar(x)     ((int*)(x)-__STATIC)
#define parDFILE(x)     ((aDATAFILE*)(__STATIC+(x)))
#define DFILEpar(x)     ((int*)(x)-__STATIC)
#define parCHFILE(x)    ((aCHARFILE*)(__STATIC+(x)))
#define CHFILEpar(x)    ((int*)(x)-__STATIC)

#define sizeof_STACK    (sizeof(aSTACK)/sizeof(int))
#define sizeof_DFILE    (sizeof(aDATAFILE)/sizeof(int))
#define sizeof_CHFILE   (sizeof(aCHARFILE)/sizeof(int))

/*===============================================================*/
typedef struct {
   int *offset;			// offset[idx] is the value
   int *p;			// pointer to the beginning
   int length;			// length of the allocated block
   int alwb,aupb;		// actual lower and upper bound
   int vlwb,vupb;		// virtual lower, upper bound
   int calibre;			// calibre of the stack
} aSTACK;

int was(int *a);		// 'q' was + a[] + >p
void next(int *a);		// 'f' next + a[] + >p>
void previous(int *a);		// 'f' previous + a[] + >p>
void unstack(int *a);		// 'a' unstack + []st[]
void unstackto(int *a);		// 'a' unstack to + []st[] + >ptr
void listlength(int *a);	// 'f' list length + a[] + len>
void scratch(int *a);		// 'a' scratch + []st[]
void release(int *a);		// 'a' release + []st[]
int requestspace(int *a);	// 'p' request space + []st[] + >size
void expandstack(int *a);	// 'a' expand stack + []st[] + >n + >f1 + ... + >fn
//void extend(int *a);		// 'a' extend + []st[] + >v
//void extendStack(int *a);	// 'a' extend stack + []st[]

#define maxchar	0x10FFFF
void stringlength(int *a);	// 'f' string length + text[] + >p + len>
void stringwidth(int *a);	// 'f' string width + text[] + >p + width>
void comparestring(int *a); 	// 'f' compare string + t1[]+ >p1 + t2[] + >p2 + comp>
void comparestringn(int *a);	// 'f' compare stringn + t1[]+>p1 + t2[]+>p2 + >n + comp>
int stringelem(int *a);		// 'q' string elem + t[] + >p + >n + char>
void unstackstring(int *a);	// 'a' unstack string+ []stack[]
void packstring(int *a);	// 'a' pack string + from[] + >n + []to[]
void unpackstring(int *a);	// 'a' unpack string + from[] + >p + []to[]
void copystring(int *a);	// 'a' copy string + from[]+>p + []to[]
void previousstring(int *a);	// 'a' previous string + t[] + >ptr>
/*===============================================================*/
/* charfile */
#include <stdio.h>
typedef struct {
   unsigned openflag; // how was it opened, r/w
   int fileError;
   FILE *f;
   int aheadchar;     // look ahead char
} aCHARFILE;

#define newline	'\n'

int Agetchar(int *a);		// 'p' get char + ""f + char>
void Aaheadchar(int *a);	// 'a' ahead char + ""f + char>
void Aputchar(int *a);		// 'a' put char + ""f + >char
void Aputstring(int *a);	// 'a' put string + ""f + t[] + >p
void Aputasstring(int *a);	// 'a' put as string + ""f + t[] + >p

/*===============================================================*/
/* data file input/output */
typedef struct {        // an area for a datafile
  int lwb,upb,data;     // lower,upper bound; offset or hash value
} aAREA;

#define MAXIMAL_AREA    32
typedef struct {
   unsigned openflag;   // how it was opened, EOF reached, etc.
   int fileError;       // last file error
   int fhandle;         // handle, zero if not opened
   int fpos;            // filepos
   unsigned iflag;      // pointer/numerical flag
   int inarea,outarea;  // number of areas, <=MAXIMAL_AREA
   aAREA in[MAXIMAL_AREA];      // input area
   aAREA out[MAXIMAL_AREA];     // output area
   int buffer[1024];    // buffer
} aDATAFILE;

void simplehash(int *a);	// 'f'simplehash + st[] + >ptr + res>
void fillDatafile(int *a);	// 'a'fill data file + ""f + >n + >lwb1 + >upb1 + >hash1+ ...
int openFile(int *a);		// 'p' open file + ""f + >mode + t[] + >ptr
int closeFile(int *a);		// 'p' close file + ""f
void unlinkFile(int *a);	// 'a'unlink file+t[]+>ptr
int putDataP(int *a);		// 'p' put datap + ""f + >data + >type
void putData(int *a);		// 'a' put data + ""f + >data + >type
int getData(int *a);		// 'p' get data + ""f + data> + type>
void getFileError(int *a);	// 'f' get file error + ""f + err>
void getFilePos(int *a);	// 'f' get file post + ""f + pos>
void setFilePos(int *a);	// 'a' set file pos + ""f + >pos

#endif

/* EOF */


