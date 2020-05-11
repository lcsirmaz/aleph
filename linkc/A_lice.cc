/* A_lice.c
 * ALEPH target standard procedures
 * (C) 2020, L.Csirmaz
 */
#include "A_lice.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/* ALEPH global names typically have form a_XXXXXX, but not always
 *  rule parameters are:
 *    int F1,int F2,  -- incoming parameters
 *    int A[]         -- outgoing parameters
 *    int C,int V[]   -- variable affix block
 *  so avoid these idenitifers as well.
 */

/* 'p'request space+[]st[]+>n:
    make sure the list has a least as much allocated space
 */
int a_requestspace(int ID,int n){
  if(n<=0) return 1; /* OK */
  #define st	to_LIST(ID)
  if(st->aupb+n>st->vupb) return 0;
        // not enough virtual space
  int newsize=st->aupb-st->vlwb+st->calibre+n;
        // one more than the size
  if(newsize<=st->length) return 0;
  newsize= (newsize+1023)&~1023; //round it
  int *ptr = realloc(st->p,sizeof(int)*newsize );
  if(!ptr) return 0; // no memory
  st->p=ptr;st->length=newsize;
  st->offset=ptr-st->alwb-1+st->calibre;
  #undef st
  return 1;
}
/* setup routines to set up lists and files */

/* compare an ALEPH string to a C string */
int a_extstrcmp(int ID,int off,const char *str){
  #define st	to_LIST(ID)
  int *ptr=st->offset+off; 
  return strcmp((char*)(ptr+1-*ptr),str);
  #undef  st
}
/* fatal with messages */
void a_fatal(const char*m1,const char *m2){
  fputs(m1,stderr);fputc(' ',stderr);fputs(m2,stderr);
  fputs("\nFatal error, aborting\n",stderr);
  exit(256);
}
/* setup a list structure
   kind:  0 - table, 1- stack (ignored)
   cal:   calibre
   lb,up: virtual lower and upper bound (corrected for calibre)
   fill:  fill size
 */
void setup_list(int kind __attribute__((unused)),
               int ID,int cal,int lb,int up,int fill){
  #define st	to_LIST(ID)
  st->offset=0; st->p=0; st->length=0;
  st->vlwb=lb; st->vupb=up; st->calibre=cal;
  st->alwb=lb; st->aupb=st->alwb-cal;
  a_requestspace(ID,fill);
  #undef st
}
/* add list filling 
   filling is collected in the integer array 'fill'
   after usage it can be discarder; the same routing
   can read an external file and fill the lists
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
static int a_push_string_to(int F1,const char *ptr){
  /* push string ptr; check that it is correct UTF-8
     return 0 if cannot get memory; 1 otherwise   */
  int n,w; int *goal; char *to;
  #define st	to_LIST(F1)
  n=strlen(ptr);if(a_requestspace(F1,3+(n/4))==0){ return 0; }
  n=0;goal=&(st->offset[1+st->aupb]);to=(char*)goal;
  while(*ptr){ if((*ptr & 0x80)==0){ *to++=*ptr++;n++; }
      else if((*ptr&0xC0)!=0xC0){ ptr++; } // ignore
      else if((*ptr&0xE0)==0xC0){ /* two byte */
        *to++=*ptr++;n++;if((*ptr&0xC0)!=0x80){n--;to--;}
        else{*to++=*ptr++;n++;}}
      else if((*ptr&0xF0)==0xE0){ /* three byte */
        *to++=*ptr++;n++;if((*ptr&0xC0)!=0x80){n--;to--;}
        else{*to++=*ptr++;n++;if((*ptr&0xC0)!=0x80){n-=2;to-=2;}
        else{*to++=*ptr++;n++;}}}
      else if((*ptr&0xF8)==0xF0){ /* four byte */
        *to++=*ptr++;n++;if((*ptr&0xC0)!=0x80){n--;to--;}
        else{*to++=*ptr++;n++;if((*ptr&0xC0)!=0x80){n-=2;to-=2;}
        else{*to++=*ptr++;n++;if((*ptr&0xC0)!=0x80){n-=3;to-=3;}
        else{*to++=*ptr++;n++;}}}}
      else{ptr++;}}
  *to=0;w=1+(n/4);goal[w]=n;goal[w+1]=w+2;st->aupb+=w+2;
  return 1;
}
void setup_stdarg(int F1,int F2 __attribute__((unused))){
  /* create a table of command line arguments
     virtual address space:  a_exlist_virtual
     command line arguments: a_argc,a_argv */
  int i;
  #define st	to_LIST(F1)
  st->offset=0;st->p=0;st->length=0;
  st->vlwb=a_extlist_virtual+1;a_extlist_virtual+=64536; 
  st->vupb=a_extlist_virtual-1;st->calibre=1;
  st->alwb=st->vlwb;st->aupb=st->alwb-st->calibre;
  for(i=a_argc-1;i>=0;i--){ /* add string a_argv[i] */
    if(a_push_string_to(F1,a_argv[i])==0){
      a_fatal("setup_stdarg","out of memory");}
  }
  #undef st
}
/* ------------------------------------------------------ */
/* input / output */
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define EWASOPENED	10001	// file was open in openFile+f 
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

/* openflags: r/w, char/data, EOF */
#define getflag_general(x,flag)	((x)->openflag&(flag))
#define setflag_general(x,y,flag) \
	if(y){(x)->openflag|=(flag);}else{(x)->openflag&=~(flag);}
// character / datafile
#define getfl_data(x)		getflag_general(x,1)
#define setfl_data(x,y)		setflag_general(x,y,1)
// read/write
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

/* character file:
    dir     0,1,2,3 1/3: in, 2,2: out
    dd,off  init string
 */
void setup_charfile(int ID,int dir,int dd,int off){
  #define ch	to_CHFILE(ID)
  ch->openflag=0;ch->fileError=0;ch->st1=dd;ch->st2=off;
  ch->f=NULL; 
  if(dir&1){setfl_in(ch,1);}
  if(dir&3){setfl_out(ch,1);}
  #undef ch
}
/* data file 
    dir     0,1,2,3 direction
    dd,off  init string
    cnt     number of items in file area
*/
void setup_dfile(int ID,int dir, int dd, int off,int cnt){
  #define df	to_DFILE(ID)
  df->openflag=0;df->fileError=0; df->st1=dd;df->st2=off;
  df->fhandle=0; df->iflag=0; df->inarea=df->outarea=0;
  setfl_data(df,1); // this is a datafile
  if(dir&1){setfl_in(df,1);}
  if(dir&3){setfl_out(df,1);}
  if(cnt>=a_MAXIMAL_AREA){a_fatal("datafile area number","error");}
  #undef df
}
/* add filearea
     list: the list
     hash: hash value for the list
     do not check if the same list is added again
*/
void add_filearea(int ID,int list,int hash){
  int i,tmp;
  #define df	to_DFILE(ID)
  i=df->outarea;
  if(i>=a_MAXIMAL_AREA){a_fatal("add filearea number","error");}
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

/* char file input/output */

static int a_tryopen(int F1,int dir);

/* 'p'get char+""f+char>.  read an utf-8 encoded character  */
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
/* 'a'ahead char+""f+char>. look ahead for the next character */
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
/* 'a'put char+""f + >char. write a char to the file */
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
/* 'a'put string+""f+T[]+>ptr. */
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
/* ------------------------------------------------- */
/* static: read/write databuffer */
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
/* 'p'put datap + ""f + >data+>type */
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
      if(cnt>=df->outarea){df->fileError=EWRONGVALUE; return 0; }
   }
   df->fileError=0;
   if((df->fpos*1023)==1023){ // buffer is full, flush
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
    mode: r - reading, must exist
          w - writing, created, chopeed if exist
          a - append; charfile only
 */
#define ALEPH_BINARY_MAGIC	(int)0xAB0347DE
int a_openfile(int F1,int F2,int F3,int F4){
  int *arg3; 
    int cnt,j;int *buf;
  if(F3==0||F4==0){ch->fileError=EBADARG; return 0;}
  arg3=to_LIST(F3)->offset+F4;
  #define df	to_DFILE(F1)
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
/* try open the supplied file */
static int a_tryopen(int F1,int dir){
   #define df	to_DFILE(F1)
   if((dir=='r' && getfl_in(df))|| (dir=='w' && getfl_out(df))){
      return a_openfile(F1,dir,df->st1,df->st2);
   }
   df->fileError=ENOTOPENED; return 0;
   #undef df
}

/* 'p'close filep+""f. */
int a_closefilep(int F1){
  int ret;
  #define df to_DFILE(F1)
  if(!getfl_data(df)){ // not a datafile
  #define ch to_CHFILE(F1)
    if(!ch->f){ return 1; } // not opened
    if(fclose(ch->f)){ch->fileError=errno;ch->f=0;return 0; }
    ch->f=0; return 1;
  #undef ch
  }
  if(df->fhandle<=0){ return 1; } // not opened
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
   if(!a_putdatap(F1,F2,F3)){a_fatal("put data","error");}
}
/* 'a'close file+"". */
void a_closefile(int F1){
   if(!a_closefilep(F1)){a_fatal("close file","error");}
}

/* 'a' unlink file+t[]+>ptr */
void a_unlinkfile(int F1,int F2){
   int *arg=to_LIST(F1)->offset+F2;
   if(unlink((char*)(arg+1-*arg))<0){;}
}
// 'p' get data + ""f + data> + type >
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
    if(!getfl_data(df) || df->fhandle<=0 ) return;
    A[0]=df->fpos;
    return;
#   undef df
}
//'a'set file pos + ""f + >pos
void a_setfilepos(int F1,int F2){
    off_t offset;
#   define df	to_DFILE(F1)
    df->fileError=ESEEKERROR;
    if(!getfl_data(df) || df->fhandle<=0 || getfl_rw(df)
      || F2<0 ) return;
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



/* EOF */
