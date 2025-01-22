/* aleph external routines */

/*******************************************************************
*  This code is part of ALEPH-M (Modular ALEPH-v2.1)
*
*  (C) 2020-2024, L.Csirmaz
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

#include "aleph_core.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/*******************************************************************
* ALEPH standard external rules
*
* a_release, a_requestspace, a_comparestring, a_comparestringn
* a_stringelem, a_packstring, a_unpackstring, a_copystring,
* a_opentempfile, a_closefile, a_unlinkfile, a_getfilepos,
* a_setfilepos, a_getchar,a_aheadchar,a_putchar,
* a_getdata, a_putdata, a_putdatap, a_setup_stdarg, 
*/

/* imported from aleph_core */
int a_requestspace(a_word ID,a_word n);
a_word *a_extension(a_word ID,a_word n);
/* forward prototype */
int a_openfile(a_word F1,a_word F2,a_word F3,a_word F4);

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

/*******************************************************************
* release memory allocated by a stack
*
*******************************************************************/
/* 'a'release+[]st[] */
void a_release(int F1){
#  define st    to_LIST(F1)
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
/* 'f'compare string+t1[]+>p1+t2[]+>p2+res> */
void a_comparestring(int F1,int F2,int F3,int F4,int A[1]){
  int *ptr1=to_LIST(F1)->offset+F2,
      *ptr2=to_LIST(F3)->offset+F4;
  A[0]=strcmp((char*)(ptr1+1-*ptr1),(char*)(ptr2+1-*ptr2));
}
/* 'f'compare string n+t1[]+>p1+t2[]+>p2+>n+res> */
void a_comparestringn(int F1,int F2,int F3,int F4,int F5,int A[1]){
  int *ptr1=to_LIST(F1)->offset+F2,
      *ptr2=to_LIST(F3)->offset+F4;
  const char*chr1=(char*)(ptr1+1-*ptr1),
            *chr2=(char*)(ptr2+1-*ptr2);
  while(F5>0){
    A[0]=*chr1-*chr2;if(A[0]!=0){ return; }
    if(*chr1==0){ return; }
    if((*chr1&0xC0)!=0x80){F5--;}
    chr1++; chr2++;
  }
  A[0]=0; return;
}
/* 'q' string elem+t[]+>p+>n+c> */
int a_stringelem(int F1,int F2,int F3,int A[1]){
  int *ptr=to_LIST(F1)->offset+F2;
  const unsigned char *chr=(unsigned char*)(ptr+1-*ptr);
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
       c &= 0x0F;
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
//#  define st  to_LIST(F1)
//  st->aupb-= st->offset[st->aupb];
//#  undef st
//}
/* 'a' pack string+t[]+>p+[]st[] */
void a_packstring(int F1,int F2,int F3){
   int len,i;
   int *ptr=to_LIST(F1)->offset+to_LIST(F1)->aupb-F2+1; // start
   int width=3*sizeof(int);for(i=0;i<F2;i++){
     width += ptr[i]<=0 ? 0 : ptr[i]<0x80?1 :
            ptr[i]<0x800 ? 2 : ptr[i]<0x10000 ? 3 :
            ptr[i]<0x110000 ? 4 : 0;
   }
   width /= sizeof(int);
   int *goal=a_extension(F3,width);
   char *chr=(char*)goal;goal[width-3]=0;len=0;
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
/* 'a' unpack string+t[]+>p+[]st[] */
void a_unpackstring(int F1,int F2,int F3){
   int i;
   int *ptr=to_LIST(F1)->offset+F2;
   int n=ptr[-1]; // number of characters
   //some sanity check
   if(n<0 || n>99000 || ptr[0]<3 || n>4*ptr[0] ||
     F2-ptr[0]<to_LIST(F1)->alwb-to_LIST(F1)->calibre){
      fprintf(stderr,"unpackstring: list %s index %d: not a string\n",
                  to_LIST(F1)->name,F2);
      a_fatal(a_FATAL_string);
   }
   unsigned *goal=(unsigned*)a_extension(F3,n);
   char *chr=(char*)(ptr+1-*ptr);
   for(i=0;i<n;i++,goal++){
     *goal=*chr;chr++;if(*goal==0){
       fprintf(stderr,"unpackstring: list %s index %d: wrong encoding\n",
                    to_LIST(F1)->name,F2);
       a_fatal(a_FATAL_string);
     }
     if((*goal&0x80)==0) continue;
     if((*goal&0xE0)==0xC0){ // two byte
       *goal &=0x1F; goto out1; }
     if((*goal&0xF0)==0xE0){ // three byte
       *goal &=0x0F; goto out2; }
     if((*goal&0xF8)==0xF0){ // four byte 
       *goal &=0x0F;
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
/* 'a'copy string+t1[]+>p+[]st[] */
void a_copystring(int F1,int F2,int F3){
   int i;
   int *ptr=to_LIST(F1)->offset+F2; int n=ptr[0]; // width
   // some sanity check
   if(n<3 || n>25000 || ptr[-1]>4*n ||
       F2-n<to_LIST(F1)->alwb-to_LIST(F1)->calibre){
       fprintf(stderr,"copy string: list %s index %d: not a string\n",
                   to_LIST(F1)->name,F2);
       a_fatal(a_FATAL_string);
   }
   int *goal=a_extension(F3,n)+(n-1);
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

#define EWASOPENED      10001   // file was already open 
#define EBADARG         10002   // mode is not /r/ or /w/ or /a/
#define ETRUNCATED      10003   // file is truncated (end is missing)
#define EWRONGALEPH     10004   // input datafile is not an aleph file
#define EWRONGTYPE      10005   // getdata,putdata on char file
#define ENOTOPENED      10006   // getdata,putdata on unopened file
                                // getchar, putchar on unopened file
#define EWRONGVALUE     10007   // putdata/getdata pointer not in any area
                                // putchar with invalid value
#define ENODATAFILE     10008   // get data with not a data file
#define ENOCHARFILE     10009   // character input/output on data file
#define EREADEOF        10010   // getdata, getchar reads EOF
#define ESEEKERROR      10011   // set file pos
#define ELARGEFILE      10012   // set file pos, put data

/*******************************************************************
* file structures
*   the openflag field stores status bits:
*     0x0001      datafile
*     0x0004      opened for write
*     0x0008      eof indicator (datafile only)
*     0x0010      ahead character read (chfile only)
*     0x0020      in direction is defined
*     0x0040      out direction is defined
*     0x0080      std stream, do not close
*   the fileError field contains the last error code which can be
*     retrieved by 'get file error"
*   (st1,st2) fields store the ALEPH string given in the declaration;
*     it is used as the default file name when attempting a file
*     operation on an unopened file
*
*******************************************************************/

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/* flag manipulating macros 
 */
#define getflag_general(x,flag) ((x)->openflag&(flag))
#define setflag_general(x,y,flag) \
        if(y){(x)->openflag|=(flag);}else{(x)->openflag&=~(flag);}

#define getfl_data(x)           getflag_general(x,1)
#define setfl_data(x,y)         setflag_general(x,y,1)

#define getfl_rw(x)             getflag_general(x,4)
#define setfl_rw(x,y)           setflag_general(x,y,4)

#define getfl_eof(x)            getflag_general(x,8)
#define setfl_eof(x,y)          setflag_general(x,y,8)

#define getfl_ahead(x)          getflag_general(x,0x10)
#define setfl_ahead(x,y)        setflag_general(x,y,0x10)

#define getfl_in(x)             getflag_general(x,0x20)
#define setfl_in(x,y)           setflag_general(x,y,0x20)

#define getfl_out(x)            getflag_general(x,0x40)
#define setfl_out(x,y)          setflag_general(x,y,0x40)

#define getfl_std(x)		getflag_general(x,0x80)
#define setfl_std(x,y)		setflag_general(x,y,0x80)

/*******************************************************************
* character file input/output
*
*******************************************************************/
/* a_tryopen(ID,mode)
 *   try to open the path given in the structure
 *   check if the mode is compatible with the declared direction
 */

static int a_tryopen(int F1,int dir){
   #define df   to_DFILE(F1)
   if((dir=='r' && getfl_in(df)) || (dir=='w' && getfl_out(df))){
      return a_openfile(F1,dir,df->st1,df->st2);
   }
   df->fileError=ENOTOPENED; return 0;
   #undef df
}

/* 'p'get char+""f+char>
 *    read a utf-8 encoded character from f
 */
int a_getchar(int F1,int A[1]){
   int c;
   #define ch   to_CHFILE(F1)
   if(getfl_data(ch)){ ch->fileError=ENOCHARFILE; return 0; }
   if(!ch->f){ if(!a_tryopen(F1,'r')) return 0; }
   if(getfl_rw(ch)){ch->fileError=EWRONGTYPE; return 0; }
   ch->fileError=0;
   if(getfl_ahead(ch)){A[0]=ch->aheadchar;setfl_ahead(ch,0);return 1; }
again:
   A[0]=getc(ch->f);if(A[0]<0){ch->fileError=EREADEOF;return 0;} // EOF
   if((A[0]&0x80)==0) return 1; // single character
   if((A[0]&0xE0)==0xC0){ // two byte sequence 
        A[0] &= 0x1F; goto out1; }
   if((A[0]&0xF0)==0xE0){ // three byte sequence
        A[0] &=0x0F; goto out2; }
   if((A[0]&0xF8)==0xF0){ // four byte sequence
        A[0] &=0x0F;
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
int a_aheadchar(int F1,int A[1]){
   #define ch to_CHFILE(F1)
   A[0]=-1;if(getfl_data(ch)){ch->fileError=ENOCHARFILE; return 0; }
   if(!ch->f){ if(!a_tryopen(F1,'r')) return 0; }
   if(getfl_rw(ch)){ch->fileError=EWRONGTYPE; return 0; }
   if(getfl_ahead(ch)){A[0]=ch->aheadchar;ch->fileError=0; return 1; }
   if(a_getchar(F1,A)){ch->aheadchar=A[0];setfl_ahead(ch,1);return 1;}
   return 0;
   #undef ch
}
#define a_maxchar       0x10ffff
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
   if(F2<0x80){ if(putc(F2,ch->f)<0) ch->fileError=errno; }
   else if(F2<0x800){ if(putc(0xC0|(F2>>6),ch->f)<0 ||
                    putc(0x80|(F2&0x3F),ch->f)<0) ch->fileError=errno; }
   else if(F2<0x10000){ if(putc(0xE0|(F2>>12),ch->f)<0 ||
                      putc(0x80|((F2>>6)&0x3F),ch->f)<0 ||
                      putc(0x80|(F2&0x3F),ch->f)<0) ch->fileError=errno; }
   else if(putc(0xF0|(F2>>18),ch->f)<0 ||
      putc(((F2>>12)&0x3F)|0x80,ch->f)<0 ||
      putc(((F2>>6)&0x3F)|0x80,ch->f)<0 ||
      putc((F2&0x3F)|0x80,ch->f)<0) ch->fileError=errno;
   #undef ch
}

/*******************************************************************
* binary file input/output
*
*******************************************************************/

/* a_read_databuffer       fill the databuffer
 * a_write_databuffer      flush databuffer
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
   #define df   to_DFILE(F1)
   if(!getfl_data(df)){ df->fileError=ENODATAFILE; return 0;}
   if(df->fhandle<=0){ if(!a_tryopen(F1,'w')) return 0;}
   if(!getfl_rw(df)){ df->fileError=EWRONGTYPE; return 0; }
   if(df->fpos>0x7FFF0000){ df->fileError=ELARGEFILE; return 0; }
   if(F3!=0 && F2!=0 && F2!=-1 ){ // pointer
      // check if F2 is within the bounds
      for(cnt=0;cnt<df->outarea &&
         (F2<df->out[cnt].lwb || df->out[cnt].upb<F2);cnt++);
      if(cnt>=df->outarea){
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
 *         w - writing, created, chopped if exist
 *         t - create temp file, overwrite file name
 *         a - append; charfile only
 */
#define ALEPH_BINARY_MAGIC      (int)0xAB0347DE
int a_openfile(int F1,int F2,int F3,int F4){
  int *arg3;int cnt,j;int *buf;
  #define df    to_DFILE(F1)
  if(F3<0||F3>0x10000||F4==0){df->fileError=EBADARG; return 0;}
  arg3=to_LIST(F3)->offset+F4;
  if(!getfl_data(df)){ // not a datafile
  #define ch    to_CHFILE(F1)
    if(ch->f){ch->fileError=EWASOPENED; return 0; }
    ch->fileError=0;
    // special cases: <<stdin>>, <<stdout>>, <<stderr>>
    if(strcmp((char*)(arg3+1-*arg3),"<<stdin>>")==0){
      if(F2!='r'){ch->fileError=EBADARG; return 0; }
      ch->f=stdin;setfl_rw(ch,0); setfl_std(ch,1); return 1;
    } else if(strcmp((char*)(arg3+1-*arg3),"<<stdout>>")==0){
      if(F2!='w'&& F2!='a'){ch->fileError=EBADARG; return 0;}
      ch->f=stdout; setfl_rw(ch,1); setfl_std(ch,1); return 1;
    } else if(strcmp((char*)(arg3+1-*arg3),"<<stderr>>")==0){
      if(F2!='w'&& F2!='a'){ch->fileError=EBADARG; return 0;}
      ch->f=stderr; setfl_rw(ch,1); setfl_std(ch,1); return 1;
    } else if(F2=='w'||F2=='a'){
      ch->f=fopen((char*)(arg3+1-*arg3),F2=='w'?"w":"a");
      if(!ch->f){ch->fileError=errno; return 0; }
      setfl_rw(ch,1); return 1;
    } else if(F2=='r'){struct stat STAT;
      ch->f=fopen((char*)(arg3+1-*arg3),"r");
      if(!ch->f){ch->fileError=errno; return 0;}
      // check if it is a directory
      if(fstat(fileno(ch->f),&STAT)){
         fclose(ch->f);ch->f=0;ch->fileError=errno;return 0;}
      if(S_ISDIR(STAT.st_mode)){
         fclose(ch->f);ch->f=0;ch->fileError=ENOENT;return 0;}
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
/* 'p'open temp file+""f+[]st[]+>ptr */
int a_opentempfile(a_word F1,a_word F3,a_word F4){
   int *arg3;int fd,cnt,j;int *buf;
   #define df	to_DFILE(F1)
   if(F3<0||F3>0x10000||F4==0){df->fileError=EBADARG; return 0;}
   arg3=to_LIST(F3)->offset+F4;
   if(!getfl_data(df)){ // not a datafile
   #define ch	to_CHFILE(F1)
     if(ch->f){ch->fileError=EWASOPENED; return 0;}
     ch->fileError=0;
     fd=mkstemp((char*)(arg3+1-*arg3));
     if(fd<0){ch->fileError=errno;return 0;}
     ch->f=fdopen(fd,"a");
     if(!ch->f){ch->fileError=errno; return 0;}
     setfl_rw(ch,1); return 1;
   #undef ch
   }
   if(df->fhandle>0){df->fileError=EWASOPENED; return 0;}
   df->fileError=0;
   setfl_rw(df,1);setfl_eof(df,0);
   df->fhandle=mkstemp((char*)(arg3+1-*arg3));
   if(df->fhandle<0){df->fileError=errno;return 0;}
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
    setfl_ahead(ch,0);
    if(getfl_std(ch)){setfl_std(ch,0);ch->fileError=0;ch->f=0; return 1;}
    if(fclose(ch->f)){ch->fileError=errno;ch->f=0;return 0; }
    ch->fileError=0;ch->f=0; return 1;
  #undef ch
  }
  if(df->fhandle<=0){df->fileError=ENOTOPENED; return 1; } // not opened
  if(getfl_rw(df)){ // opened for write
    ret=a_putdatap(F1,-1,1); // clears fileError
    while(ret && (df->fpos&31)!=31){ret = a_putdatap(F1,-1,1);}
    df->buffer[(df->fpos>>5)&31]=df->iflag;
    if(ret && a_write_databuffer(df)){ ret=0; }
    if(close(df->fhandle)){df->fileError=errno; ret=0;}
    df->fhandle=0;
  } else{ // opened for read
    if(close(df->fhandle)!=0){;}
    df->fileError=0;df->fhandle=0;setfl_eof(df,0); ret=1;
  }
  return ret;
  #undef df
}
/* 'a'put data+""f+>data+>flag. */
void a_putdata(int F1,int F2,int F3){
   if(!a_putdatap(F1,F2,F3)){
     fprintf(stderr,"datafile %s: put data failed with code %d\n",
        to_DFILE(F1)->name,to_DFILE(F1)->fileError);
     a_fatal(a_FATAL_datafile);
   }
}
/* 'a'close file+"". */
void a_closefile(int F1){
   if(!a_closefilep(F1)){
     fprintf(stderr,"file %s: close file failed with code %d\n",
       to_DFILE(F1)->name,to_DFILE(F1)->fileError);
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
#   define df   to_DFILE(F1)
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
    df->fileError=0;
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
//void a_getfileerror(int F1,int A[1]){ 
//   A[0]=to_DFILE(F1)->fileError; }

/* 'f'get file pos + ""f + pos> */
void a_getfilepos(int F1,int A[1]){
#   define df   to_DFILE(F1)
    A[0]=-1;
    if(!getfl_data(df)){ // charfile
#   define ch   to_CHFILE(F1)
      long offset;
      if(!ch->f){ch->fileError=ENOTOPENED; return;}
      offset=ftell(ch->f);
      if(offset<=-1l){ ch->fileError=errno; }
      else if( offset>0x7fff0000l){ ch->fileError=ELARGEFILE; }
      else { ch->fileError=0;A[0]=(int)offset; }
    return;
#   undef ch
    }
    if(df->fhandle<=0 ){df->fileError=ENOTOPENED; return;}
    A[0]=df->fpos;df->fileError=0;
    return;
#   undef df
}
/* 'a'set file pos + ""f + >pos */
void a_setfilepos(int F1,int F2){
    off_t offset;
#   define ch   to_CHFILE(F1)
    if(!getfl_data(ch)){ // charfile
       if(F2<0 || !ch->f){ch->fileError=ESEEKERROR; return;}
       if(fseek(ch->f,(long)F2,SEEK_SET)){
         ch->fileError=errno;
       } else {setfl_ahead(ch,0);ch->fileError=0;}
       return;
    }
#   undef ch
#   define df   to_DFILE(F1)
    df->fileError=ESEEKERROR;
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
         df->fileError=errno; return;
      }
      if((F2&1023)==1023){ // done
          df->fpos=F2;df->fileError=0; return;
      }
      if(a_read_databuffer(df)){ // i/o error
         return;
      }
    } // we have the current block
    df->fpos=F2;
    df->iflag=(unsigned)(df->buffer[(df->fpos>>5)&31]) << (df->fpos&31);
    df->fileError=0;
#   undef df
}

/* EOF */
