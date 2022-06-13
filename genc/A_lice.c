/* A_lice.c */

/********************************************************************
*  This code is part of ALEPH-M (Modular ALEPH)
* 
*  (C) 2020-2022, L.Csirmaz
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

#include "A_lice.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************
* ALEPH target standard procedures
*
* LISTS: allocation, initialization, standard rules
*
*  a_requestspace(stack,size)
*     makes sure that that the stack has at leastsize words of 
*     additional allocated space above its actual upper bound. 
*     Called for tables during initialization.
*/
int a_requestspace(int ID,int n){
  #define st	to_LIST(ID)
  if(n<=0){if(st->p){return 1;} // OK
           else{n=1;}}
  if(st->aupb+n>st->vupb) return 0;
        // not enough virtual space
  int newsize=st->aupb-st->vlwb+st->calibre+n;
        // one more than the size
  if(newsize<=st->length) return 1;
  newsize= (newsize+1023)&~1023; //round it
  int *ptr = realloc(st->p,sizeof(int)*newsize );
  if(!ptr) return 0; // no memory
  st->p=ptr;st->length=newsize;
  st->offset=ptr-st->alwb-1+st->calibre;
  #undef st
  return 1;
}
/* a_extension(stack,size)
 *     calls a_requestspace and abort if no more space.
 *     set stack->top to be used in extension to fill the new
 *     block.
 */
void a_extension(int ID,int n){
  if(a_requestspace(ID,n)){
  #define st	to_LIST(ID)
     st->top=st->offset+st->aupb;
     return;
  #undef st
  }
  fprintf(stderr,"in an extension of list %d by %d words, "
                 "out of %s\n",ID,n,
                 to_LIST(ID)->aupb+n>to_LIST(ID)->vupb ?
                       "virtual space" : "memory");
  a_fatal(a_FATAL_memory);
}
/* auxiliary functions */

/* int a_extstrcmp(ID,off,str)
 *     compare the ALEPH string at ID[off] to a C string.
 *     used by a_waitfor() to compare requested module names
 */
int a_extstrcmp(int ID,int off,const char *str){
  #define st	to_LIST(ID)
  int *ptr=st->offset+off; 
  return strcmp((char*)(ptr+1-*ptr),str);
  #undef  st
}
/* a_area_failed(int v)
 *   last area in a classification failed
 */
void a_area_failed(const char *rule,int v){
  fprintf(stderr,"classification in rule %s failed for value %d\n",
     rule,v);
  a_fatal(a_FATAL_area);
}
/*******************************************************************
*  Data structure initialization
*
* setup a list structure
*   a_setup_list(kind,list,calibre,vlwb,vupb,fill size)
*      kind        0 - table, 1 - stack (ignored)
*      ID          index in a_DATABLOCK, use to_LIST(ID) to get the 
*                  pointer  to the corresponding structure
*      calibre     calibre
*      vlwb,vupb   virtual lower and upper bounds
*      fill        fill size
*   after the call, calibre, virtual and actual bounds must be set,
*   other fields should be empty. Call a_requestspace() to allocate
*   physical memory.
*
*   a_list_fill(int *fill)
*      fill        integer array with the description of all list fill.
*
*******************************************************************/
void a_setup_list(int kind __attribute__((unused)),
               int ID,int cal,int lb,int up,int fill){
  #define st	to_LIST(ID)
  st->offset=0; st->p=0; st->length=0;
  st->vlwb=lb; st->vupb=up; st->calibre=cal;
  st->alwb=lb; st->aupb=st->alwb-cal;
  a_requestspace(ID,fill);
  #undef st
}

/* a_list_fill(int *fill)
*    filling is collected in the integer array 'fill'
*     after this call 'fill' can be discarded; the
*     content could come from an external file
*/
void a_list_fill(int *fill){
  int ID,x,i,cnt,*idx;
  #define st	to_LIST(ID)
  while((ID=*fill)>=0){
    fill++; idx=&(st->offset[st->aupb+1]);cnt=0;
      while((x=*fill)!=0){
        fill++;if(x>0){cnt=x;st->aupb+=cnt;
               while(x>0){*idx=*fill;idx++;fill++;x--;}}
        else{while(x<0){x++;st->aupb+=cnt;
           for(i=0;i<cnt;i++){*idx=idx[-cnt];idx++;}}}
      } fill++;
  }
  #undef st
}

/*******************************************************************
*  External lists and files
*
*    the string in the external declaration gives the initialization
*    routine. For lists it is called as
*  INIT_ROUTINE(int ID, int clb)
*       ID    offset in a_DATABLOCK, use to_LIST(ID) to get the pointer
*             to the structure
*       clb   calibre
*  the rountine must set the calibre, virtual and actual bounds; for
*  tables it should also set the content. Virtual address space starts
*  at a_virtual_max, and cannot exceed max int; a_virtual_max
*  should be adjusted.
*
*******************************************************************/

/*  a_push_string_to(list,char *chr)
 *     internal routine used by a_setup_stdarg()
 *     stores a C text string as an ALEPH list with check for correct
 *     UTF-8 encoding
 *  return value: 1: OK, 0: out of memory
 */
static int a_push_string_to(int F1,const char *ptr){
  int n,w; int *goal; char *to;
  #define st	to_LIST(F1)
  n=strlen(ptr);if(a_requestspace(F1,3+(n/4))==0){ return 0; }
  n=0;goal=&(st->offset[1+st->aupb]);to=(char*)goal;
  while(*ptr){ if((*ptr & 0x80)==0){ *to++=*ptr++;n++;}
      else if((*ptr&0xC0)!=0xC0){ ptr++; } // ignore
      else if((*ptr&0xE0)==0xC0){ /* two byte */
        *to++=*ptr++;n++;if((*ptr&0xC0)!=0x80){n--;to--;}
        else{*to++=*ptr++;}}
      else if((*ptr&0xF0)==0xE0){ /* three byte */
        *to++=*ptr++;n++;if((*ptr&0xC0)!=0x80){n--;to--;}
        else{*to++=*ptr++;if((*ptr&0xC0)!=0x80){to-=2;}
        else{*to++=*ptr++;}}}
      else if((*ptr&0xF8)==0xF0){ /* four byte */
        *to++=*ptr++;n++;if((*ptr&0xC0)!=0x80){n--;to--;}
        else{*to++=*ptr++;if((*ptr&0xC0)!=0x80){to-=2;}
        else{*to++=*ptr++;if((*ptr&0xC0)!=0x80){to-=3;}
        else{*to++=*ptr++;}}}}
      else{ptr++;}}
  *to=0;w=1+(to-((char*)goal))/4;goal[w]=n;goal[w+1]=w+2;st->aupb+=w+2;
  return 1;
}

extern int a_argc; extern char **a_argv;
extern int a_virtual_max,a_virtual_min;

/* a_setup_stdarg(ID,calibre)
 *    setup routine for the standard external table STDARG, fills the
 *    table with the comomand line arguments found at a_argc,a_argv
 */
void a_setup_stdarg(int F1,int F2){
  int i;
  #define st	to_LIST(F1)
  st->offset=0;st->p=0;st->length=0;
  st->vlwb=a_virtual_max+16;a_virtual_max+=64536;
  if(a_virtual_max<=0){
      fprintf(stderr,"our of virtual space of command line arguments\n");
      a_fatal(a_FATAL_memory); 
  }
  st->vupb=a_virtual_max-1;st->calibre=F2;
  st->alwb=st->vlwb;st->aupb=st->alwb-st->calibre;
  for(i=a_argc-1;i>0;i--){ /* add string a_argv[i] */
    if(a_push_string_to(F1,a_argv[i])==0){
      fprintf(stderr,"out of memory for command line arguments\n");
      a_fatal(a_FATAL_memory);}
  }
  #undef st
}
/*******************************************************************
* some inline'd standard list routines
*
*******************************************************************/
/* 'q'was+t[]+>p */
//int a_was(int F1,int F2){
//# define st to_LIST(F1)
//   return (st->alwb-st->calibre<F2 && F2<= st->aupb)?1 : 0;
//# undef  st
//}
/* 'f'next+t[]+>p> */
//void a_next(int F1, int A[1]){
//   A[0]+=to_LIST(F1)->calibre;
//}
/* 'f'previous+t[]+>p> */
//void a_previous(int F1,int A[1]){
//   A[0]-=to_LIST(F1)->calibre;
//}
/* 'a'unstack+[]st[] */
//void a_unstack(int F1){
//   to_LIST(F1)->aupb -= to_LIST(F1)->calibre;
//}
/* 'a'unstack to+[]st[]+>p */
//void a_unstackto(int F1,int F2){
//   to_LIST(F1)->aupb=F2;
//}
/* 'f'list length+t[]+len> */
//void a_listlength(int F1,int A[1]){
//#  define st	to_LIST(F1)
//   A[0]=st->aupb-st->alwb+st->calibre;
//#  undef st
//}
/* 'a'scratch+[]st[] */
//void a_scratch(int F1){
//#  define st	to_LIST(F1)
//   st->aupb=st->alwb-st->calibre;
//#  undef st
//}
/* 'a'release+[]st[] */
void a_release(int F1){
#  define st	to_LIST(F1)
   st->aupb=st->alwb-st->calibre;
   free(st->p);st->p=0;st->length=0;
#  undef st
}
/*******************************************************************
* string routines
*
*  string are stored utf-8 encoded ending with a zero character.
*  Proper character values are between 1 and 0x10FFFF, with 'newline'
*  as character 10.
*  Each integer contains four bytes; the string (ending with zero)
*  is followed by the string length, then by the width. For example,
*  the empty string has width 3 with contents (0,0,3).
*
*  Packing and unpacking, as well as searching for a string element
*  means parsing the string from the beginning for proper uft-8
*  encoding. The routines behave erratically when values are outside
*  the allowed range, or if the string is not a proper utf-8 string.
*
*******************************************************************/
/* strings */
/* 'f'string length+t[]+>p+len> */
//void a_stringlength(int F1,int F2,int A[1]){
//   A[0]=to_LIST(F1)->offset[-1+F2];
//}
/* 'f'string width+t[]+>p+len> */
//void a_stringwidth(int F1,int F2,int A[1]){
//   A[0]=to_LIST(F1)->offset[F2];
//}
/* 'f'previous string+t[]+>p> */
//void a_previousstring(int F1,int A[1]){
//   A[0]-=to_LIST(F1)->offset[A[0]];
//}
/* 'f'compare string+t1[]+>p1+t2[]+>p2+res> 
 *    compare two strings sight of res indicates relationship
 */
void a_comparestring(int F1,int F2,int F3,int F4,int A[1]){
  int *ptr1=to_LIST(F1)->offset+F2,
      *ptr2=to_LIST(F3)->offset+F4;
  A[0]=strcmp((char*)(ptr1+1-*ptr1),(char*)(ptr2+1-*ptr2));
}
/* 'f'compare string n+t1[]+>p1+t2[]+>p2+>n+res>
 *    compare first n characters of two strings
 */
void a_comparestringn(int F1,int F2,int F3,int F4,int F5,int A[1]){
  int *ptr1=to_LIST(F1)->offset+F2,
      *ptr2=to_LIST(F3)->offset+F4;
  const unsigned char*chr1=(unsigned char*)(ptr1+1-*ptr1),
                     *chr2=(unsigned char*)(ptr2+1-*ptr2);
  while(F5>0){
    A[0]=*chr1-*chr2;if(A[0]!=0){ return; }
    if(*chr1==0){ return; }
    if((*chr1&0xC0)!=0x80){F5--;}
    chr1++; chr2++;
  }
  A[0]=0; return;
}
/* 'q' string elem+t[]+>p+>n+c> 
 *    find the n-th element of the string; do an utf-8 encoding on
 *    the fly
 */
int a_stringelem(int F1,int F2,int F3,int A[1]){
  int *ptr=to_LIST(F1)->offset+F2;
  const char *chr=(char*)(ptr+1-*ptr);
  int c;
  if(F3<0 || F3>=ptr[-1]) return 0;
  for(;F3>=0;F3--){
    c=*chr;chr++;if(c==0) return 0;
    if((c&0x80)==0) continue;
    if((c&0xE0)==0xC0){ // two byte
       c &= 0x1F; goto out1;}
    if((c&0xF0)==0xE0){ // three byte
       c &= 0x0F; goto out2;}
    if((c&0xF8)==0xF0){ // four byte
       if((*chr&0xC0)!=0x80) return 0;
       c<<=6; c|= *chr&0x3F; chr++;
out2:  if((*chr&0xC0)!=0x80) return 0;
       c<<=6; c|= *chr&0x3F; chr++;
out1:  if((*chr&0xC0)!=0x80) return 0;
       c<<=6; c|= *chr &0x3F; chr++;
       continue;
    } 
    return 0; // some error
  }
  A[0]=c;return 1;
}
/* 'a' unstack string+[]st[] */
//void a_unstackstring(int F1){
//#  define st	to_LIST(F1)
//  st->aupb-= st->offset[st->aupb];
//#  undef st
//}
/* 'a' pack string+t[]+>p+[]st[]
 *     pack utf-8 characters to a string; ignore invalid code values
 */
void a_packstring(int F1,int F2,int F3){
   int len,i;
   int *ptr=to_LIST(F1)->offset+to_LIST(F1)->aupb-F2+1; // start
   int width=3*sizeof(int);for(i=0;i<F2;i++){
     width += ptr[i]<=0 ? 0 : ptr[i]<0x80?1 :
            ptr[i]<0x800 ? 2 : ptr[i]<0x10000 ? 3 :
            ptr[i]<0x110000 ? 4 : 0;
   }
   width /= sizeof(int);a_extension(F3,width);
   int *goal=to_LIST(F3)->offset+1+to_LIST(F3)->aupb;
   char *chr=(char*)goal;len=0;
   for(i=0;i<F2;i++){
     if(ptr[i]<0||ptr[i]>0x110000) continue;
     len++;
     if(ptr[i]<0x80){ *chr=ptr[i]; chr++; continue; }
     if(ptr[i]<0x800){ *chr = 0xC0|(ptr[i]>>6);chr++;
                       *chr = 0x80|(ptr[i]&0x3F); chr++;
                       continue; }
     if(ptr[i]<0x10000){ *chr = 0xE0|(ptr[i]>>12);chr++;
                       *chr = 0x80|((ptr[i]>>6)&0x3F); chr++;
                       *chr = 0x80|(ptr[i]&0x3F); chr++;
                       continue; }
            *chr = 0xF0|(ptr[i]>>18); chr++;
            *chr = 0x80|((ptr[i]>>12)&0x3F); chr++;
            *chr = 0x80|((ptr[i]>>6)&0x3F); chr++;
            *chr = 0x80|(ptr[i]&0x3F); chr++;
   }
   *chr=0;
   goal[width-2]=len;goal[width-1]=width;
   to_LIST(F3)->aupb+=width;
}
/* 'a' unpack string+t[]+>p+[]st[]
       unpack an utf-8 encoded string. Comes with some sanity check;
       aborts for invalid utf-8 code.
 */
void a_unpackstring(int F1,int F2,int F3){
   int i;
   int *ptr=to_LIST(F1)->offset+F2;
   int n=ptr[-1]; // number of characters
   //some sanity check
   if(n<0 || n>99000 || ptr[0]<3 || n>4*ptr[0] ||
     F2-ptr[0]<to_LIST(F1)->alwb-to_LIST(F1)->calibre){
      fprintf(stderr,"unpackstring: list %d, index %d, not a string\n",
                      F1,F2);
      a_fatal(a_FATAL_string);
   }
   a_extension(F3,n);
   unsigned *goal=(unsigned*)(to_LIST(F3)->offset+1+to_LIST(F3)->aupb);
   char *chr=(char*)(ptr+1-*ptr);
   for(i=0;i<n;i++,goal++){
     *goal=*chr;chr++;if(*goal==0){
       fprintf(stderr,"unpackstring: list %d, index %d, wrong encoding\n",
                       F1,F2);
       a_fatal(a_FATAL_string);
     }
     if((*goal&0x80)==0) continue;
     if((*goal&0xE0)==0xC0){ // two byte
       *goal &=0x1F; goto out1; }
     if((*goal&0xF0)==0xE0){ // three byte
       *goal &=0x0F; goto out2; }
     if((*goal&0xF8)==0xF0){ // four byte 
       if((*chr&0xC0)!=0x80) return;
       *goal<<=6; *goal |= *chr&0x3F; chr++;
out2:  if((*chr&0xC0)!=0x80) return;
       *goal<<=6; *goal |= *chr&0x3F; chr++;
out1:  if((*chr&0xC0)!=0x80) return;
       *goal<<=6; *goal |= *chr&0x3F; chr++;
       continue;
     }
     return; // some error
   }
   to_LIST(F3)->aupb += n;
}
/* 'a'copy string+t1[]+>p+[]st[]
 *    copy a string to the end of another stack
 */
void a_copystring(int F1,int F2,int F3){
   int i;
   int *ptr=to_LIST(F1)->offset+F2; int n=ptr[0]; // width
   // some sanity check
   if(n<3 || n>25000 || ptr[-1]>4*n ||
       F2-n<to_LIST(F1)->alwb-to_LIST(F1)->calibre){
       fprintf(stderr,"copy string: list %d, index %d, not a string\n",
                      F1,F2);
       a_fatal(a_FATAL_string);
   }
   a_extension(F3,n);
   int *goal=to_LIST(F3)->offset+n+to_LIST(F3)->aupb;
   for(i=0;i<n;i++) goal[-i]=ptr[-i];
   to_LIST(F3)->aupb+=n;
}
/*******************************************************************
* input / output
*
*  for character input use character stream, for data use direct read
*  and write. ALEPH specific error values are defined below
*
*******************************************************************/

#define EWASOPENED	10001	// file was already open 
#define EBADARG		10002	// mode is not /r/ or /w/ or /a/
#define ETRUNCATED	10003   // file is truncated (end is missing)
#define EWRONGALEPH	10004	// input datafile is not an aleph file
#define EWRONGTYPE	10005	// getdata,putdata on char file
#define ENOTOPENED	10006	// getdata,putdata on unopened file
				// getchar, putchar on unopened file
#define EWRONGVALUE	10007	// putdata/getdata pointer not in any area
				// putchar with invalid value
#define ENODATAFILE	10008	// get data with not a data file
#define ENOCHARFILE	10009	// character input/output on data file
#define EREADEOF	10010	// getdata, getchar reads EOF
#define ESEEKERROR	10011	// set file pos
#define ELARGEFILE	10012	// set file pos

/*******************************************************************
* file structures
*   the openflag field stores status bits:
*     0x0001      datafile
*     0x0004      opened for write
*     0x0008      eof indicator (datafile only)
*     0x0010      ahead character read (chfile only)
*     0x0020      in direction is defined
*     0x0040      out direction is defined
*   the fileError field contains the last error code which can be
*     retrieved by 'get file error"
*   (st1,st2) fields store the ALEPH string given inthe declaration;
*     it is used as the default file name when attempting a file
*     operation on an unopened file
*
*******************************************************************/

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/* flag manipulating macros 
 */
#define getflag_general(x,flag)	((x)->openflag&(flag))
#define setflag_general(x,y,flag) \
	if(y){(x)->openflag|=(flag);}else{(x)->openflag&=~(flag);}

#define getfl_data(x)		getflag_general(x,1)
#define setfl_data(x,y)		setflag_general(x,y,1)

#define getfl_rw(x)		getflag_general(x,4)
#define setfl_rw(x,y)		setflag_general(x,y,4)

#define getfl_eof(x)    	getflag_general(x,8)
#define setfl_eof(x,y)		setflag_general(x,y,8)

#define getfl_ahead(x)          getflag_general(x,0x10)
#define setfl_ahead(x,y)        setflag_general(x,y,0x10)

#define getfl_in(x)		getflag_general(x,0x20)
#define setfl_in(x,y)		setflag_general(x,y,0x20)

#define getfl_out(x)		getflag_general(x,0x40)
#define setfl_out(x,y)		setflag_general(x,y,0x40)

/* a_setup_charfile(ID,dir,dd,off)
 *    setup a charfile structure
 *      ID      structure index
 *      dir     1,3: in, 2,3: out
 *      dd,off  init string for implicit open
 */
void a_setup_charfile(int ID,int dir,int dd,int off){
  #define ch	to_CHFILE(ID)
  ch->openflag=0;ch->fileError=0;ch->st1=dd;ch->st2=off;
  ch->f=NULL; 
  if(dir&1){setfl_in(ch,1);}
  if(dir&3){setfl_out(ch,1);}
  #undef ch
}
/* a_setup_dfile(ID,dir,dd,off,cnt)
 *   setup datafile structure
 *      ID      structure index
 *      dir     1,3: in, 2,3: out
 *      dd,off  init string for implicit open
 *      cnt     number of lists in file area
 */
void a_setup_dfile(int ID,int dir, int dd, int off,int cnt){
  #define df	to_DFILE(ID)
  df->openflag=0;df->fileError=0; df->st1=dd;df->st2=off;
  df->fhandle=0; df->iflag=0; df->inarea=df->outarea=0;
  setfl_data(df,1); // this is a datafile
  if(dir&1){setfl_in(df,1);}
  if(dir&3){setfl_out(df,1);}
  if(cnt>=a_MAXIMAL_AREA){
    fprintf(stderr,"setup datafile: too many file areas\n");
    a_fatal(a_FATAL_datafile);
  }
  #undef df
}
/* a_add_fileared(ID,list,hash)
 *   add a filearea; it is called exactly cnt many times for each list
 *      ID     structure index
 *      list   index of the list
 *      hash   hash value for the list ID
 *             no check is made if the same list is added twice
 */
void a_add_filearea(int ID,int list,int hash){
  int i,tmp;
  #define df	to_DFILE(ID)
  i=df->outarea;
  if(i>=a_MAXIMAL_AREA){
    fprintf(stderr,"setup datafile: too many file areas\n");
    a_fatal(a_FATAL_datafile);
  }
  df->out[i].lwb=to_LIST(list)->vlwb-to_LIST(list)->calibre+1;
  df->out[i].upb=to_LIST(list)->vupb;
  df->out[i].data=hash;
  df->outarea++;
  while(i>0 && df->out[i-1].lwb>df->out[i].lwb){
    tmp=df->out[i].lwb;df->out[i].lwb=df->out[i-1].lwb;df->out[i-1].lwb=tmp;
    tmp=df->out[i].upb;df->out[i].upb=df->out[i-1].upb;df->out[i-1].upb=tmp;
    tmp=df->out[i].data;df->out[i].data=df->out[i-1].data;df->out[i-1].data=tmp;
    i--;
  }
  #undef df
}

/*******************************************************************
* character file input/output
*
*******************************************************************/

/* a_tryopen(ID,mode)
 *   try to open the path given in the structure
 *   check if the mode is compatible with the declared direction
 */
static int a_tryopen(int F1,int dir){
   #define df	to_DFILE(F1)
   if((dir=='r' && getfl_in(df)) || (dir=='w' && getfl_out(df))){
      return a_openfile(F1,dir,df->st1,df->st2);
   }
   df->fileError=ENOTOPENED; return 0;
   #undef df
}

/* 'p'get char+""f+char>.  
 *    read a utf-8 encoded character from f
 */
int a_getchar(int F1,int A[1]){
   int c;
   #define ch	to_CHFILE(F1)
   if(getfl_data(ch)){ ch->fileError=ENOCHARFILE; return 0; }
   if(!ch->f){ if(!a_tryopen(F1,'r')) return 0; }
   if(getfl_rw(ch)){ch->fileError=EWRONGTYPE; return 0; }
   if(getfl_ahead(ch)){A[0]=ch->aheadchar;setfl_ahead(ch,0);return 1; }
again:
   A[0]=getc(ch->f);if(A[0]<0){ch->fileError=EREADEOF;return 0;} // EOF
   if((A[0]&0x80)==0) return 1; // single character
   if((A[0]&0xE0)==0xC0){ // two byte sequence 
        A[0] &= 0x1F; goto out1; }
   if((A[0]&0xF0)==0xE0){ // three byte sequence
        A[0] &=0x0F; goto out2; }
   if((A[0]&0xF8)==0xF0){ // four byte sequence
        A[0] &=0x07;
        c=getc(ch->f); if(c<0){ ch->fileError=EREADEOF; return 0; }
        if((c&0xC0)!=0x80) goto again;
        A[0]<<=6; A[0]|= c&0x3F;
out2:
        c=getc(ch->f); if(c<0){ch->fileError=EREADEOF; return 0;}
        if((c&0xC0)!=0x80) goto again;
        A[0]<<=6; A[0] |= c&0x3F;
out1:
        c=getc(ch->f); if(c<0){ch->fileError=EREADEOF; return 0;}
        if((c&0xC0)!=0x80) goto again;
        A[0]<<=6; A[0] |= c&0x3F; return 1; }
   goto again;
   #undef ch
}
/* 'a'ahead char+""f+char>.
 *   look ahead for the next character
 */
void a_aheadchar(int F1,int A[1]){
   #define ch to_CHFILE(F1)
   A[0]=-1;if(getfl_data(ch)){ch->fileError=ENOCHARFILE; return; }
   if(!ch->f){ if(!a_tryopen(F1,'r')) return; }
   if(getfl_rw(ch)){ch->fileError=EWRONGTYPE; return; }
   if(getfl_ahead(ch)){A[1]=ch->aheadchar; return; }
   if(a_getchar(F1,A)){ch->aheadchar=A[0];setfl_ahead(ch,1);}
   #undef ch
}
#define a_maxchar	0x10ffff
/* 'a'put char+""f + >char. 
 *   write a character to the char file
 */
void a_putchar(int F1,int F2){
   #define ch to_CHFILE(F1)
   if(getfl_data(ch)){ch->fileError=ENOCHARFILE; return;}
   if(!ch->f){ if(!a_tryopen(F1,'w')) return; }
   if(!getfl_rw(ch)){ch->fileError=EWRONGTYPE; return; }
   if(F2<0||F2>a_maxchar){ch->fileError=EWRONGVALUE; return; }
   ch->fileError=0; // assume no error
   if(F2<0x80){ if(putc(F2,ch->f)<0) ch->fileError=errno; return; }
   if(F2<0x800){ if(putc(0xC0|(F2>>6),ch->f)<0 ||
                    putc(0x80|(F2&0x3F),ch->f)<0) ch->fileError=errno; return; }
   if(F2<0x10000){ if(putc(0xE0|(F2>>12),ch->f)<0 ||
                      putc(0x80|((F2>>6)&0x3F),ch->f)<0 ||
                      putc(0x80|(F2&0x3F),ch->f)<0) ch->fileError=errno; return; }
   if(putc(0xF0|(F2>>18),ch->f)<0 ||
      putc(((F2>>12)&0x3F)|0x80,ch->f)<0 ||
      putc(((F2>>6)&0x3F)|0x80,ch->f)<0 ||
      putc((F2&0x3F)|0x80,ch->f)<0) ch->fileError=errno;
   #undef ch
}
/* 'a'put string+""f+T[]+>ptr. 
 *      write a string to a character file
 */
void a_putstring(int F1,int F2,int F3){
  #define ch	to_CHFILE(F1)
  if(getfl_data(ch)){ch->fileError=EWRONGTYPE; return;}
  if(!ch->f){ if(!a_tryopen(F1,'w')) return; }
  ch->fileError=0;
  int *ptr=&(to_LIST(F2)->offset[F3]);
  char *chr=(char*)(ptr+1-*ptr);
  while(*chr){ if(putc(*chr,ch->f)<0){ch->fileError=errno; return;} chr++;}
  #undef ch
}
/*******************************************************************
* binary file input/output
*
*******************************************************************/

/* a_read_databuffer 
 *    fill the databuffer
 * a_write_databuffer
 *    flush databuffer
 */
static int a_read_databuffer(a_DATAFILE *df){
   int cnt,i;char *b;
   cnt=1024*sizeof(int);b=(char*)(df->buffer);
   while(cnt>0){
     i=read(df->fhandle,b,cnt);
     if(i==0){ // EOF
       df->fileError=ETRUNCATED; return 1;
     } else if(i<0){ // read error
       df->fileError=errno; return 1;
     }
     cnt-=i; b+=i;
   }
   return 0; // got it
}
static int a_write_databuffer(a_DATAFILE *df){
   int cnt,i;char *b;
   cnt=1024*sizeof(int);b=(char*)(df->buffer);
   while(cnt>0){
      i=write(df->fhandle,b,cnt);
      if(i<=0){df->fileError=errno;return 1; }
      cnt-=i; b+=i;
   }
   return 0;
}
/* 'p'put datap + ""f + >data+>type 
 *    add the next data
 */
int a_putdatap(int F1,int F2,int F3)
{  int cnt;
   #define df	to_DFILE(F1)
   if(!getfl_data(df)){ df->fileError=ENODATAFILE; return 0;}
   if(df->fhandle<=0){ if(!a_tryopen(F1,'w')) return 0;}
   if(!getfl_rw(df)){ df->fileError=EWRONGTYPE; return 0; }
   if(F3!=0 && F2!=0 && F2!=-1 ){ // pointer
      // check if F2 is within the bounds
      for(cnt=0;cnt<df->outarea &&
         (F2<df->out[cnt].lwb || df->out[cnt].upb<F2);cnt++);
      if(cnt>=df->outarea){
fprintf(stderr,"put data: pointer %d not among areas\n",F1); exit(23);
         df->fileError=EWRONGVALUE; return 0; }
   }
   df->fileError=0;
   if((df->fpos & 1023)==1023){ // buffer is full, flush
     df->buffer[31]=df->iflag;
     if(a_write_databuffer(df)){return 0;}
     for(cnt=1;cnt<32;cnt++)df->buffer[cnt]=0;
     df->fpos+=33;df->iflag=0u;
   } else if((df->fpos&31)==31){ // next 32 values
     df->buffer[(df->fpos>>5)&31]=df->iflag;
     df->iflag=0; df->fpos++;
   } else { // make room for the next flag
     df->iflag<<=1;df->fpos++;
   }
   df->buffer[(df->fpos)&1023]=F2; // store data
   if(F3){df->iflag|=1;}
   return 1;
   #undef df
}
/* 'p'open file + ""f + >mode + T[]+>ptr.
 *  open a file
 *   mode: r - reading, must exist
 *         w - writing, created, chopeed if exist
 *         a - append; charfile only
 */
#define ALEPH_BINARY_MAGIC	(int)0xAB0347DE
int a_openfile(int F1,int F2,int F3,int F4){
  int *arg3;int cnt,j;int *buf;
  #define df	to_DFILE(F1)
  if(F3<0||F3>0x10000||F4==0){df->fileError=EBADARG; return 0;}
  arg3=to_LIST(F3)->offset+F4;
  if(!getfl_data(df)){ // not a datafile
  #define ch	to_CHFILE(F1)
    if(ch->f){ch->fileError=EWASOPENED; return 0; }
    ch->fileError=0;
    // special cases: stdin//stdout//stderr
    if(strcmp((char*)(arg3+1-*arg3),"stdin")==0){
      if(F2!='r'){ch->fileError=EBADARG; return 0; }
      ch->f=stdin;setfl_rw(ch,0); return 1;
    } else if(strcmp((char*)(arg3+1-*arg3),"stdout")==0){
      if(F2!='w'&& F2!='a'){ch->fileError=EBADARG; return 0;}
      ch->f=stdout; setfl_rw(ch,1); return 1;
    } else if(strcmp((char*)(arg3+1-*arg3),"stderr")==0){
      if(F2!='w'&& F2!='a'){ch->fileError=EBADARG; return 0;}
      ch->f=stderr; setfl_rw(ch,1); return 1;
    } else if(F2=='w'||F2=='a'){
      ch->f=fopen((char*)(arg3+1-*arg3),F2=='w'?"w":"a");
      if(!ch->f){ch->fileError=errno; return 0; }
      setfl_rw(ch,1); return 1;
    } else if(F2=='r'){
      ch->f=fopen((char*)(arg3+1-*arg3),"r");
      if(!ch->f){ch->fileError=errno; return 0;}
      setfl_rw(ch,0);
    } else {ch->fileError=EBADARG; return 0;}
    #undef ch
    return 1;
  }
  if(df->fhandle>0){df->fileError=EWASOPENED; return 0; }
  df->fileError=0;
  if(F2=='w'){ // writing
    setfl_rw(df,1);setfl_eof(df,0);
    df->fhandle=creat((char*)(arg3+1-*arg3),0644);
    if(df->fhandle<0){df->fileError=errno; return 0; }
    for(j=0;j<1024;j++){df->buffer[j]=0;}
    df->buffer[0]=ALEPH_BINARY_MAGIC;
    buf=&(df->buffer[32]);
    *buf=df->outarea;buf++;
    df->fpos=32+3*df->outarea; // last filepos
    df->iflag=0u;              // all numerical so far
    for(cnt=0;cnt<df->outarea;cnt++){
      *buf = df->out[cnt].lwb; buf++;
      *buf = df->out[cnt].upb; buf++;
      *buf = df->out[cnt].data; buf++;
    }
  } else if(F2=='r'){ // open for reading 
    int ins=0;
    setfl_rw(df,0);setfl_eof(df,0); // clear EOF flag
    df->fhandle=open((char*)(arg3+1-*arg3),O_RDONLY);
    if(df->fhandle<0){df->fileError=errno;return 0;}
    if(a_read_databuffer(df)){ // read first block
      close(df->fhandle);df->fhandle=0; return 0;
    }
    if(df->buffer[0]!=ALEPH_BINARY_MAGIC
       ||df->buffer[32]<0 || df->buffer[32]>=a_MAXIMAL_AREA ){
       df->fileError=EWRONGALEPH;
       close(df->fhandle);df->fhandle=0; return 0;
    }
    buf=&(df->buffer[32]);
    df->inarea=*buf;buf++;
    df->fpos=32+3*df->inarea; // previous filepos
    df->iflag=(unsigned)(df->buffer[(df->fpos>>5)&31]) << (df->fpos&31);
    for(cnt=ins=0;cnt<df->inarea;cnt++){ // ins'th input area
      df->in[ins].lwb=*buf;buf++;
      df->in[ins].upb=*buf;buf++;
      // locate ID in the out section
      for(j=0;j<df->outarea && df->out[j].data!=*buf;j++);
      buf++;
      if(j!=df->outarea){ // area found, set offset difference
        df->in[ins].data=df->out[j].lwb-df->in[ins].lwb;
        ins++;
      }
    }
    df->inarea=ins;
  } else {
    df->fileError=EBADARG; return 0;
  }
  return 1;
  #undef df
}
/* 'p'close filep+""f */
int a_closefilep(int F1){
  int ret;
  #define df to_DFILE(F1)
  if(!getfl_data(df)){ // not a datafile
  #define ch to_CHFILE(F1)
    if(!ch->f){ch->fileError=ENOTOPENED;return 1; } // not opened
    if(fclose(ch->f)){ch->fileError=errno;ch->f=0;return 0; }
    ch->f=0; return 1;
  #undef ch
  }
  if(df->fhandle<=0){df->fileError=ENOTOPENED; return 1; } // not opened
  if(getfl_rw(df)){ // opened for write
    ret=a_putdatap(F1,-1,1);
    while(ret && (df->fpos&31)!=31){ret = a_putdatap(F1,-1,1);}
    df->buffer[(df->fpos>>5)&31]=df->iflag;
    if(ret && a_write_databuffer(df)){ ret=0; }
    if(close(df->fhandle)){df->fileError=errno; ret=0;}
    df->fhandle=0;
  } else{ // opened for read
    close(df->fhandle);
    df->fhandle=0;setfl_eof(df,0); ret=1;
  }
  return ret;
  #undef df
}
/* 'a'put data+""f+>data+>flag. */
void a_putdata(int F1,int F2,int F3){
   if(!a_putdatap(F1,F2,F3)){
     fprintf(stderr,"put data to file %d failed with code %d\n",
        F1,to_DFILE(F1)->fileError);
     a_fatal(a_FATAL_datafile);
   }
}
/* 'a'close file+"". */
void a_closefile(int F1){
   if(!a_closefilep(F1)){
     fprintf(stderr,"close file for file %d failed widh code %d\n",
       F1,to_DFILE(F1)->fileError);
     a_fatal(a_FATAL_datafile);
   }
}

/* 'a' unlink file+t[]+>ptr */
void a_unlinkfile(int F1,int F2){
   int *arg=to_LIST(F1)->offset+F2;
   if(unlink((char*)(arg+1-*arg))<0){;}
}
/* 'p' get data + ""f + data> + type> */
int a_getdata(int F1,int A[2]){
#   define df	to_DFILE(F1)
    if(!getfl_data(df)){ df->fileError=ENODATAFILE; return 0;}
    if(df->fhandle<=0){if(!a_tryopen(F1,'r')) return 0; }
    if(getfl_rw(df)){ df->fileError=ENOTOPENED; return 0; }
    if(getfl_eof(df)){df->fileError=EREADEOF; return 0;}
    // advance df->fpos
    if((df->fpos&1023)==1023){
      if(a_read_databuffer(df)){return 0; } // fileError set
      df->fpos+=33; df->iflag=df->buffer[1];
    } else if((df->fpos&31)==31){
      df->fpos++; df->iflag=(unsigned)df->buffer[(df->fpos>>5)&31];
    } else {
       df->fpos++; df->iflag<<=1;
    }
    A[0]=df->buffer[df->fpos&1023];
    A[1]=0; // numerical value
    if(df->iflag & 0x80000000u ){ // pointer
      int i; A[1]=1;
      if(A[0]==-1){ // EOF
        setfl_eof(df,1);
        df->fileError=EREADEOF;
        return 0;
      }
      if(A[0]==0){ return 1; } // nil
      for(i=0;i<df->inarea; i++){
        if(df->in[i].lwb<=A[0] && A[0]<=df->in[i].upb){
           A[0]+= df->in[i].data;
           return 1;
        }
      }
      df->fileError=EWRONGVALUE;return 0;
    }
    return 1;
#   undef df
}
/* 'f'get file error + ""f +err> */
void a_getfileerror(int F1,int A[1]){ 
   A[0]=to_DFILE(F1)->fileError; }

/* 'f'get file pos + ""f + pos> */
void a_getfilepos(int F1,int A[1]){
#   define df	to_DFILE(F1)
    A[0]=0;
    if(!getfl_data(df)){ // charfile
#   define ch	to_CHFILE(F1)
      long offset;
      if(!ch->f){ch->fileError=ENOTOPENED; return;}
      offset=ftell(ch->f);
      if(offset<=-1l){ ch->fileError=errno; }
      else if( offset>0x7fff0000l){ ch->fileError=ELARGEFILE; }
      else { A[0]=(int)offset; }
    return;
#   undef ch
    }
    if(df->fhandle<=0 ) return;
    A[0]=df->fpos;
    return;
#   undef df
}
//'a'set file pos + ""f + >pos
void a_setfilepos(int F1,int F2){
    off_t offset;
#   define df	to_DFILE(F1)
    df->fileError=ESEEKERROR;
#   define ch	to_CHFILE(F1)
    if(!getfl_data(df)){ // chafile
       if(F2<0 || !ch->f) return;
       if(fseek(ch->f,(long)F2,SEEK_SET)){
         ch->fileError=errno;
       }
       return;
    }
#   undef ch
    if(df->fhandle<=0 || getfl_rw(df) || F2<0 ) return;
    if(getfl_eof(df) && F2>= df->fpos) return;
    if(F2==0){F2=32+3*df->inarea; } // special case
    if((F2&1023)<32) return;
    df->fileError=0;
    if(F2==df->fpos) return; // we are there
    setfl_eof(df,0); // clear EOF indicator
    if((F2&~1023)!=(df->fpos & 1023)){ // read the block
      offset=(off_t)(F2 & ~1023)*sizeof(int);
      if((F2&1023)==1023) offset += 1024*sizeof(int);
      if(lseek(df->fhandle,offset,SEEK_SET)<0){ // error
         df->fileError=ESEEKERROR; return;
      }
      if((F2&1023)==1023){ // done
          df->fpos=F2; return; 
      }
      if(a_read_databuffer(df)){ // i/o error
         return;
      }
    } // we have the current block
    df->fpos=F2;
    df->iflag=(unsigned)(df->buffer[(df->fpos>>5)&31]) << (df->fpos&31);
#   undef df
}

/*******************************************************************
*  hash functions
*
*  simple (not cryptopgrahic) hash function which is fast and works
*  well. It can be used to compute hash of a string or a consecutive
*  block of integers.
*
*  'f'simple hash+T[]+>p+res> 
*      compute the hash of the string pointed by p
*  'f'block hash+T[]+>p+res>
*      compute the hash of the block T[p+1],...,T[T->aupb]
*
*******************************************************************/

void a_simplehash(int F1,int F2,int A[1]){
  int *ptr=to_LIST(F1)->offset+F2;
  unsigned char *v=(unsigned char*)&ptr[1-ptr[0]];
  unsigned v1=0x135345+47*(*v), v2=0xeca864+107*(*v<<3);
  while(*v){
     v1=(29*v1+17*v2+1259*(*v^v2)) % 0x1010309;
     v2=(23*v2+257*v1+1237*(*v^v1)) % 0x1010507;
     v++;
  }
  A[0]=(int)(v1<<16|v2);
}

void a_blockhash(int F1,int F2,int A[1]){
  unsigned char *v=(unsigned char*)(to_LIST(F1)->offset+F2+1);
  unsigned v1=0x135345+47*(*v), v2=0xeca864+107*(*v<<3);
  int cnt=sizeof(int)*(to_LIST(F1)->aupb-F2);
  for(;cnt>0;cnt--){
     v1=(29*v1+17*v2+1259*(*v^v2)) % 0x1010309;
     v2=(23*v2+257*v1+1237*(*v^v1)) % 0x1010507;
     v++;
  }
  A[0]=(int)(v1<<16|v2);
}

/*******************************************************************
* profile and trace
*
*  rules with count=on have a static a_PROFILE structure, and the
*   procedure a_PROFILING() is called. This procedure
*   links and counts how many times the rule has been called.
*  rules with trace=on start with an
*          a_trace_rule("rule",cnt,F1,F2,...)
*   call with the rule name, number of incoming arguments, and the
*   values of the arguments. Depending on the value of "do_trace",
*   it is printed on stderr
*
*******************************************************************/
a_PROFILE *a_profiles;
#define TRACE_SIZE	30
const char *a_traced_rules[TRACE_SIZE];
static int a_traced_index=-1;

#include <stdarg.h>
static int do_trace=0;
void a_trace_rule(const char *name,int affixno,...){
  va_list args; int affix; char *sep="";
  if(a_traced_index<=0){a_traced_index=TRACE_SIZE;}
  a_traced_rules[--a_traced_index]=name;
  if(do_trace==0){return;}
  fprintf(stderr," %s(",name);
  va_start(args,affixno);
  while(affixno>0){
     affix=va_arg(args,int);fprintf(stderr,"%s%d",sep,affix);
     sep=",";affixno--;}
  va_end(args);
  fprintf(stderr,")\n");  
}

/* a_sort_profiles()
*    sort profiles by their count
*/
static void a_sort_profiles(void){
a_PROFILE **p,*q; int done=1;
   while(done){
     done=0;p=&a_profiles;
     while(*p && (q=(*p)->link)){
       if((*p)->count < q->count){
          done=1; (*p)->link=q->link;q->link=*p;*p=q;p=&(q->link);
       }else{ p=&((*p)->link);}
     }
   }
}

/* void a_fatal(code)
*    abort the program; print trace information, if any
*/
void a_fatal(int code){
   int i;
   fprintf(stderr,"FATAL error %d\n",code);
   if(a_traced_index>=0){
     i=a_traced_index;
     fprintf(stderr,"Rules with trace on called:\n%s\n",a_traced_rules[i]);
     i++;if(i==TRACE_SIZE){i=0;}
     while(i!=a_traced_index){
        if(a_traced_rules[i]){fprintf(stderr,"%s\n",a_traced_rules[i]);}
        i++;if(i==TRACE_SIZE){i=0;}
     }
   }
   if(a_profiles){ fprintf(stderr,"Profiling:\n");}
   while(a_profiles){
     fprintf(stderr,"%s => %lu\n",a_profiles->rulename,a_profiles->count);
     a_profiles=a_profiles->link;
   }
   exit(64+code);
}
/*******************************************************************
* the main() routine
*
* set up the whole program; if the first command line argument 
* is '-T' then enable tracing.
*******************************************************************/
int a_argc;char **a_argv;
int a_virtual_min=0x01000000,a_virtual_max=0x7f000000;
extern void a_ROOT(void);

int main(int argc,char *argv[]){
   if(argc>1 && strcmp(argv[1],"-T")==0){do_trace=1;argc--,argv++;}
   a_argc=argc;a_argv=argv;
   memset(a_traced_rules,0,sizeof(const char *)*TRACE_SIZE);
   a_traced_index=-1;a_profiles=NULL;
   a_ROOT();
   a_sort_profiles();
   while(a_profiles){
     printf("%-20s => %7lu\n",a_profiles->rulename,a_profiles->count);
     a_profiles=a_profiles->link;
   }
   if(a_traced_index>=0 && do_trace==0){
     int i=a_traced_index;
     fprintf(stderr,"Last %d rules with trace on called:\n%s\n",
             TRACE_SIZE,a_traced_rules[i]);
     i++;if(i==TRACE_SIZE){i=0;}
     while(i!=a_traced_index){
        if(a_traced_rules[i]){fprintf(stderr,"%s\n",a_traced_rules[i]);}
        i++;if(i==TRACE_SIZE){i=0;}
     }
   }
   return 0;
}


/* EOF */
