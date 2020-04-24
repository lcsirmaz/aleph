/* aleph standard library functions */

#include "stdlib.h"
#include <malloc.h>

int was(int *a){		// 'a' was + a[] + >p
   return parSTACK(a[0])->alwb -parSTACK(a[0])->calibre<a[1] &&
          a[1] <= parSTACK(a[0])->aupb ? 1 : 0;
};
void next(int *a){ a[1] += parSTACK(a[0])->calibre; }
void previous(int *a){ a[1]-= parSTACK(a[0])->calibre; }
void unstack(int *a){ parSTACK(a[0])->aupb -= parSTACK(a[0])->calibre; }
void unstackto(int *a){ parSTACK(a[0])->aupb = a[1]; }
void listlength(int *a){ a[1]= parSTACK(a[0])->aupb - parSTACK(a[0])->alwb
                          +parSTACK(a[0])->calibre; }
void scratch(int *a){ parSTACK(a[0])->aupb =
  parSTACK(a[0])->alwb - parSTACK(a[0])->calibre; }
void release(int *a){ parSTACK(a[0])->aupb =
  parSTACK(a[0])->alwb - parSTACK(a[0])->calibre;
  free(parSTACK(a[0])->p);parSTACK(a[0])->p=0;parSTACK(a[0])->length=0;
}

int requestspace(int *a){
   if(a[1]<=0) return 1;
   if(parSTACK(a[0])->aupb + a[1] > parSTACK(a[0])->vupb)
       return 0; // not enough virtual space
   int newsize= parSTACK(a[0])->aupb - parSTACK(a[0])->vlwb
      + parSTACK(a[0])->calibre+a[1]; // one more than the size
   if(newsize <= parSTACK(a[0])->length) return 1;
   newsize = (newsize+1023)& ~1023; // round it
   int *ptr = realloc( parSTACK(a[0])->p, sizeof(int)*newsize );
   if(!ptr) return 0; // no memory
   parSTACK(a[0])->p=ptr; parSTACK(a[0])->length=newsize;
   parSTACK(a[0])->offset = ptr - 
       parSTACK(a[0])->alwb-1+parSTACK(a[0])->calibre;
   return 1;
}
void expandstack(int *a){
   int i;
//printf("Expandstack stack=%d,req=%d\n",a[0],a[1]);
   if(a[1]==0){a[1]=1;}
//if(a[1]<0){*(int*)(a[1])=0;}
   if(! requestspace(a) ){
      fprintf(stderr, "expandstack %0x n=%d, out of memory\n",a[0],a[1]);
      exit(12);
   }
   int *ptr=&(parSTACK(a[0])->offset)[1+parSTACK(a[0])->aupb];
   for(i=0;i<a[1];i++){
      ptr[i]=a[i+2];
   }
   parSTACK(a[0])->aupb += a[1];
}
void extend(int *a){
   int par[2];par[0]=a[0];par[1]=1;
   if(! requestspace(par)){fprintf(stderr,"extend: out of memory for %d, v=%d\n",a[0],a[1]);exit(23);}
   parSTACK(a[0])->aupb++;
   parSTACK(a[0])->offset[parSTACK(a[0])->aupb]=a[1];
}
void extendStack(int *a){
   int par[2];int cnt;
   cnt=parSTACK(a[0])->calibre;nxt:if(cnt<=0){;}
   else{par[0]=a[0];par[1]=0;extend(par);cnt--;goto nxt;}
}
/*============================================================*/
/* string */
#include <string.h>
void stringlength(int *a){ 
  a[2]=(parSTACK(a[0])->offset)[-1+a[1]];
}
void stringwidth(int *a){
  a[2]=(parSTACK(a[0])->offset)[a[1]];
}
void previousstring(int *a){
  a[1]-=(parSTACK(a[0])->offset)[a[1]];
}
void comparestring(int *a){
  int *ptr1=parSTACK(a[0])->offset+a[1],
      *ptr2=parSTACK(a[2])->offset+a[3];
  a[4]=strcmp((char*)(ptr1+1-*ptr1),(char*)(ptr2+1-*ptr2));
}
void comparestringn(int *a){
  int *ptr1=parSTACK(a[0])->offset+a[1],
      *ptr2=parSTACK(a[2])->offset+a[3];
  a[5]=strncmp((char*)(ptr1+1-*ptr1),(char*)(ptr2+1-*ptr2),a[4]);
}
int stringelem(int *a){
  int *ptr=&(parSTACK(a[0])->offset)[a[1]];
  char *chr=(char*)&ptr[1-ptr[0]];
  int i=a[2];
  if(i<0 || i>=ptr[-1]) return 0;
  for(;i>=0;i--){
     a[3]=*chr; chr++; if(a[3]==0) return 0;
     if((a[3]&0x80)==0) continue;
     if((a[3]&0xE0)==0xC0){ // two byte
        a[3] &= 0x1F; goto out1; }
     if((a[3]&0xF0)==0xE0){ // tree byte
        a[3] &= 0x0F; goto out2; }
     if((a[3]&0xF8)==0xF0){ // four byte
        if((*chr&0xC0)!=0x80) return 0;
        a[3] <<=6; a[3] |= *chr & 0x3F; chr++;
out2:   if((*chr&0xC0)!=0x80) return 0;
        a[3] <<=6; a[3] |= *chr &0x3F; chr++;
out1:   if((*chr&0xC0)!=0x80) return 0;
        a[3] <<=6; a[3] |= *chr & 0x3F; chr++;
        continue;
     }
     return 0; // some error
  }
  return 1;
}
void unstackstring(int *a){
   parSTACK(a[0])->aupb -= (parSTACK(a[0])->offset)[parSTACK(a[0])->aupb];
}
void packstring(int *a){
  int par[2]; int len;
  int *ptr=parSTACK(a[0])->offset+
           parSTACK(a[0])->aupb -a[1]+1; // start
  int i; // pack 4 chars in a word
  int width=3*sizeof(int); for(i=0;i<a[1];i++){
      width += ptr[i]<=0 ? 0 : ptr[i]<0x80 ? 1 :
            ptr[i]<0x800 ? 2 : ptr[i]<0x10000 ? 3 :
            ptr[i]<0x110000 ? 4 : 0;
  }
  width /= sizeof(int);
  par[0]=a[2]; par[1]=width;
  if(! requestspace(&par[0]) ) return; // not enough space
  int *goal=& (parSTACK(a[2])->offset)[1+parSTACK(a[2])->aupb];
  char *chr=(char*)goal; len=0;
  for(i=0;i<a[1];i++){
    if(ptr[i]<=0 || ptr[i]>=0x110000) continue;
    len++;
    if(ptr[i]<0x80){ *chr=ptr[i]; chr++; continue; }
    if(ptr[i]<0x800){ *chr = 0xC0|(ptr[i]>>6); chr++;
                      *chr = 0x80|(ptr[i]&0x3F); chr++;
                      continue; }
    if(ptr[i]<0x10000){ *chr = 0xE0|(ptr[i]>>12); chr++;
                      *chr = ((ptr[i]>>6)&0x3F)|0x80; chr++;
                      *chr = 0x80 | (ptr[i]&0x3F); chr++;
                      continue; }
        *chr=0xF0|(ptr[i]>>18); chr++;
        *chr=((ptr[i]>>12)&0x3F)|0x80; chr++;
        *chr=((ptr[i]>>6)&0x3F)|0x80; chr++;
        *chr=0x80|(ptr[i]&0x3F); chr++;
  }
  *chr=0;
  goal[width-2]=len; goal[width-1]=width;
  // expand a[2] by width
  parSTACK(a[2])->aupb += width;
}
void unpackstring(int *a){
  int par[2]; int i;
  int *ptr=&(parSTACK(a[0])->offset)[a[1]];
  int n=ptr[-1]; // number of characters
  par[0]=a[2]; par[1]=n;
  // some sanity check
  if(n<=0 || n>99000 || ptr[0]<=0 || n>4*ptr[0])
      return;
  if(! requestspace(&par[0])) return; // not enough space
  unsigned *goal=(unsigned*)&(parSTACK(a[2])->offset)[1+parSTACK(a[2])->aupb];
  char *chr=(char*)&ptr[1-ptr[0]];
  for(i=0;i<n;i++,goal++){
     *goal=*chr; chr++; if(*goal==0) return;
     if((*goal&0x80)==0) continue;
     if((*goal&0xE0)==0xC0){ // two byte
        *goal &= 0x1F; goto out1; }
     if((*goal&0xF0)==0xE0){ // tree byte
        *goal &= 0x0F; goto out2; }
     if((*goal&0xF8)==0xF0){ // four byte
        if((*chr&0xC0)!=0x80) return;
        *goal <<=6; *goal |= *chr & 0x3F; chr++;
out2:   if((*chr&0xC0)!=0x80) return;
        *goal <<=6; *goal |= *chr &0x3F; chr++;
out1:   if((*chr&0xC0)!=0x80) return;
        *goal <<=6; *goal |= *chr & 0x3F; chr++;
        continue;
     }
     return; // some error
  }
  // if we are here then all is well
  parSTACK(a[2])->aupb += n;
}
void copystring(int *a){
  int par[2]; int i;
  int *ptr=&(parSTACK(a[0])->offset)[a[1]]; int n=ptr[0]; // width
  par[0]=a[2];par[1]=n;
  if(n<=0 || n>25000 || ptr[-1]>4*n) return;
  if(! requestspace(&par[0])) return; // not enough space
  int *goal=(int*)&(parSTACK(a[2])->offset)[n+parSTACK(a[2])->aupb];
  for(i=0;i<n;i++){
    goal[-i]=ptr[-i];
  }
  parSTACK(a[2])->aupb += n;
}

/*==========================================================*/
/* input / output */
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define EWASOPENED	10001	// file was open in openFile+f 
#define EBADARG		10002	// mode is not /r/ or /w/
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
#define setflag_general(x,y,flag)	if(y){(x)->openflag|=(flag);}else{(x)->openflag&=~(flag);}
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

/* char file input/output */
int Agetchar(int *a){
   int c;
#  define ch	parCHFILE(a[0])
   if(getfl_data(ch)){ ch->fileError=ENOCHARFILE; return 0; }
   if(!ch->f){ ch->fileError=ENOTOPENED; return 0; }
   if(getfl_rw(ch)){ ch->fileError=EWRONGTYPE; return 0; }
   if(getfl_ahead(ch)){a[1]=ch->aheadchar;setfl_ahead(ch,0); return 1;}
again:
   a[1]=getc(ch->f); if(a[1]<0){ ch->fileError=EREADEOF; return 0; } // EOF
   if((a[1]&0x80)==0) return 1; // single character
   if((a[1]&0xE0)==0xC0){ // two byte sequence 
        a[1] &= 0x1F; goto out1; }
   if((a[1]&0xF0)==0xE0){ // three byte sequence
        a[1] &=0x0F; goto out2; }
   if((a[1]&0xF8)==0xF0){ // four byte sequence
        a[1] &=0x07;
        c=getc(ch->f); if(c<0){ ch->fileError=EREADEOF; return 0; }
        if((c&0xC0)!=0x80) goto again;
        a[1]<<=6; a[1]|= c&0x3F;
out2:
        c=getc(ch->f); if(c<0){ch->fileError=EREADEOF; return 0;}
        if((c&0xC0)!=0x80) goto again;
        a[1]<<=6; a[1] |= c&0x3F;
out1:
        c=getc(ch->f); if(c<0){ch->fileError=EREADEOF; return 0;}
        if((c&0xC0)!=0x80) goto again;
        a[1]<<=6; a[1] |= c&0x3F; return 1; }
   goto again;
#  undef ch
}
void Aaheadchar(int *a){
#define ch  parCHFILE(a[0])
   a[1]=-1;if(getfl_data(ch)){ ch->fileError=ENOCHARFILE; return; }
   if(!ch->f){ ch->fileError=ENOTOPENED; return; }
   if(getfl_rw(ch)){ ch->fileError=EWRONGTYPE; return; }
   if(getfl_ahead(ch)){ a[1]=ch->aheadchar; return; }
   if(Agetchar(a)){ch->aheadchar=a[1];setfl_ahead(ch,1);}
}
void Aputchar(int *a){
# define ch	parCHFILE(a[0])
  if(getfl_data(ch)){ch->fileError=ENOCHARFILE; return;}
  if(!ch->f){ ch->fileError=ENOTOPENED; return;}
  if(!getfl_rw(ch)){ ch->fileError=EWRONGTYPE; return; }
  if(a[1]<0 || a[0]>maxchar){ch->fileError=EWRONGVALUE; return; }
  ch->fileError=0; // assume no error
  if(a[1]<0x80){ if(putc(a[1],ch->f)<0)ch->fileError=errno; return; }
  if(a[1]<0x800){ if(putc(0xC0|(a[1]>>6),ch->f) <0 ||
                  putc((a[1]&0x3F)|0x80, ch->f) <0) ch->fileError=errno; return; }
  if(a[1]<0x10000){ if(putc(0xE0|(a[1]>>12),ch->f)<0 ||
                    putc(((a[1]>>6)&0x3F)|0x80,ch->f) <0 ||
                    putc((a[1]&0x3F)|0x80,ch->f)<0) ch->fileError=errno; return; }
  if(putc(0xF0|(a[1]>>18),ch->f)<0 ||
  putc(((a[1]>>12)&0x3F)|0x80,ch->f)<0 ||
  putc(((a[1]>>6)&0x3F)|0x80,ch->f)<0 ||
  putc((a[1]&0x3F)|0x80,ch->f)<0) ch->fileError=errno;
# undef ch
}
void Aputstring(int *a){
#  define ch	parCHFILE(a[0])
   if(getfl_data(ch)){ch->fileError=EWRONGTYPE; return;}
   if(!ch->f){ ch->fileError=ENOTOPENED; return;}
   ch->fileError=0;
   int *ptr=&(parSTACK(a[1])->offset)[a[2]];
   char *chr=(char*)(ptr+1-*ptr);
   while(*chr){ if(putc(*chr,ch->f)<0){ch->fileError=errno; return;}; chr++; }
# undef ch
}
inline static int writechar(int c,aCHARFILE *ch){
  if(putc(c,ch->f)<0){ch->fileError=errno;return 1;}
  return 0;
}

void Aputasstring(int *a){ /* + ""f + t[] + >p */
#  define ch	parCHFILE(a[0])
   if(getfl_data(ch)){ch->fileError=EWRONGTYPE; return;}
   if(!ch->f){ ch->fileError=ENOTOPENED; return;}
   ch->fileError=0;
   int *ptr=&(parSTACK(a[1])->offset)[a[2]];
   if(writechar('"',ch)){return;}
   char *chr=(char*)(ptr+1-*ptr);
   while(*chr){
     if(0<=*chr&& *chr<32){fprintf(stderr,"put as string, control char=%d\n",*chr);chr++;}
     else{if(*chr=='"'){if(writechar('"',ch)){return;}}
          if(writechar(*chr,ch)){return;}; chr++; }}
   writechar('"',ch);
# undef ch
}

/*================================================================*/
/* data file input/output */

void simplehash(int *a){ /* a simple hash function */
  int *ptr=&(parSTACK(a[0])->offset)[a[1]];
  char *v=(char*)&ptr[1-ptr[0]];
  unsigned v1=0x135345+47*(*v), v2=0xeca864+107*(*v<<3);
  while(*v){
     v1=(29*v1+17*v2+1259*(*v)) % 0x1010309;
     v2=(23*v2+257*v1+1237*(*v)) % 0x1010507;
     v++;
  }
  a[2]=(int)(v1<<16|v2);
}
void fillDatafile(int *a){
int i,tmp,done;
#  define df	parDFILE(a[0])
   if(a[1]>=MAXIMAL_AREA){ fprintf(stderr,"fillData with %d (>31) areas\n",a[1]); exit(23); }
   df->outarea=a[1]; df->fhandle=0; df->openflag=0;
   setfl_data(df,1); // this is a datafile
   for(i=0;i<a[1];i++){
     df->out[i].lwb=a[2+3*i];
     df->out[i].upb=a[3+3*i];
     df->out[i].data=a[4+3*i];
   }
   if(a[1]>1){ do {done=1; // bubble sort
       for(i=0;i<a[1]-1;i++){
         if(df->out[i].lwb > df->out[i+1].lwb){
           done=0;
           tmp=df->out[i].lwb;df->out[i].lwb=df->out[i+1].lwb; df->out[i+1].lwb=tmp;
           tmp=df->out[i].upb;df->out[i].upb=df->out[i+1].upb; df->out[i+1].upb=tmp;
           tmp=df->out[i].data;df->out[i].data=df->out[i+1].data;df->out[i+1].data=tmp;
         }
       }
   } while(done==0); }
#  undef df
}
// fill the buffer
static int read_Databuffer(aDATAFILE *df){
    int cnt,i; char *b;
    cnt=1024*sizeof(int); b=(char*)(df->buffer);
    while(cnt>0){
       i=read(df->fhandle,b,cnt);
       if(i==0){ // EOF
         df->fileError=ETRUNCATED;
         return 1;
       } else if(i<0) { // read error
         df->fileError=errno;
         return 1;
       }
       cnt-=i; b+=i;
    }
    return 0; // it is there
}
static int write_Databuffer(aDATAFILE *df){
    int cnt,i; char *b;
    cnt=1024*sizeof(int); b=(char*)(df->buffer);
    while(cnt>0){
       i=write(df->fhandle,b,cnt);
       if(i<=0){
          df->fileError=errno;
          return 1; // write error
       }
       cnt-=i; b+=i;
    }
    return 0; // written
}
/* 'p' openFile + ""f + >flag + T[] + >ptr:
   mode: r - reading, must exist
         w - writing, created, chopped if exists
 */
#define ALEPH_BINARY_MAGIC	(int)0xAB0347DE
int openFile(int *a){
int *arg3=parSTACK(a[2])->offset+a[3];
int cnt,j; int *buf;
    //path = (char*)(arg3+1-*arg3)
#   define df	parDFILE(a[0])
    if(!getfl_data(df)){ // not a datafile
#   define ch	parCHFILE(a[0])
       if(ch->f){ ch->fileError=EWASOPENED; return 0; }
       ch->fileError=0;
       // special cases ot stdin/stdout/stderr
       if(strcmp((char*)(arg3+1-*arg3),"stdin")==0){
          if(a[1]!='r'){ ch->fileError=EBADARG; return 0; }
          ch->f=stdin; setfl_rw(ch,0); return 1;
       } else if(strcmp((char*)(arg3+1-*arg3),"stdout")==0){
          if(a[1]!='w'){ ch->fileError=EBADARG; return 0; }
          ch->f=stdout; setfl_rw(ch,1); return 1;
       } else if(a[1]=='w'){
          ch->f=fopen((char*)(arg3+1-*arg3),"w");
          if(!ch->f){ ch->fileError=errno; return 0; }
          setfl_rw(ch,1);
          return 1;
       } else if(a[1]=='r'){
          ch->f=fopen((char*)(arg3+1-*arg3),"r");
          if(!ch->f){ ch->fileError=errno; return 0; }
          setfl_rw(ch,0);
       } else { ch->fileError=EBADARG; return 0; }
#   undef ch
       return 1;
    }
    if(df->fhandle>0){
        fprintf(stderr,"datafile not closed, close first\n");
        df->fileError=EWASOPENED;
        return 0; // fail
    }
    df->fileError=0;
    if(a[1]=='w'){ // writing, creating
       setfl_rw(df,1); setfl_eof(df,0);
       df->fhandle=creat((char*)(arg3+1-*arg3),0644);
       if(df->fhandle<0){
         fprintf(stderr,"error creating datafile %s\n",(char*)(arg3+1-*arg3));
         df->fileError=errno; // standard error
         return 0; 
       }
       // fill the data
       for(j=0;j<1024;j++)df->buffer[j]=0;
       df->buffer[0]=ALEPH_BINARY_MAGIC;
       buf=&(df->buffer[32]);
       *buf=df->outarea; buf++;
       df->fpos=32+3*df->outarea; // last filepos
       df->iflag=0u;              // all numerical so far
       for(cnt=0;cnt<df->outarea;cnt++){
         *buf = df->out[cnt].lwb; buf++;
         *buf = df->out[cnt].upb; buf++;
         *buf = df->out[cnt].data; buf++;
       }
    } else if(a[1]=='r') { // open for reading
       int ins=0;
       setfl_rw(df,0); setfl_eof(df,0); // clear EOF flag
       df->fhandle=open((char*)(arg3+1-*arg3),O_RDONLY);
       if(df->fhandle<0){
          fprintf(stderr,"cannot open datafile %s\n",(char*)(arg3+1-*arg3));
          df->fileError=errno;
          return 0; // fail
       }
       // read first block
       if(read_Databuffer(df)){
         close(df->fhandle); df->fhandle=0;
         return 0;
       }
       if(df->buffer[0]!= ALEPH_BINARY_MAGIC
          || df->buffer[32]<0 || df->buffer[32]>=MAXIMAL_AREA ){
          fprintf(stderr,"aleph datafile %s corrupted\n",(char*)(arg3+1-*arg3));
          df->fileError=EWRONGALEPH;
          close(df->fhandle); df->fhandle=0;
          return 0;
       }
       buf=&(df->buffer[32]);
       df->inarea=*buf; buf++;
       df->fpos=32+3*df->inarea; // previous filepos
       df->iflag=(unsigned)(df->buffer[(df->fpos>>5)&31]) << (df->fpos&31);
       for(cnt=ins=0;cnt<df->inarea;cnt++){ // i'th input area
          df->in[ins].lwb=*buf; buf++;  // lower, upper bound
          df->in[ins].upb=*buf; buf++;
          // locate the ID in the out section
          for(j=0;j<df->outarea && df->out[j].data!=*buf; j++);
          buf++;
          if(j==df->outarea){ // area not found
            fprintf(stderr,"for datafile %s area #%d not found (%d--%d)\n",
              (char*)(arg3+1-*arg3),cnt,buf[-3],buf[-2]);
//              df->in[cnt].data = -df->in[cnt].lwb;
          } else { // dataarea found, set offset difference
            df->in[ins].data=df->out[j].lwb - df->in[ins].lwb;
            ins++;
          }
       }
       df->inarea=ins;
    } else {
       df->fileError=EBADARG;
       fprintf(stderr,"wrong flag %c for datafile %s\n",a[1],(char*)(arg3+1-*arg3));
       return 0;
    }
    return 1;
#   undef df
}
int closeFile(int *a){
    int par[3]; int ret;
#   define df	parDFILE(a[0])
    if(!getfl_data(df)){ // not a datafile
#   define ch	parCHFILE(a[0])
       if(!ch->f){ return 1; } // not opened
       if(fclose(ch->f)){ ch->fileError=errno; ch->f=0; return 0; }
       ch->f=0; 
#   undef ch
       return 1; // OK
    }
    ret=1;
    if(df->fhandle<=0) return ret; // not opened, OK
    if(getfl_rw(df)){ // opened for write
       // write EOF
       par[0]=a[0]; par[1]=-1; par[2]=1; ret=putDataP(par);
       while(ret && (df->fpos &31)!=31){ ret = putDataP(par); }
       df->buffer[(df->fpos>>5)&31]=df->iflag;
       if(ret && write_Databuffer(df)){ // error writing
         fprintf(stderr,"close datafile: insufficient space\n");
         ret=0;
       }
       if(close(df->fhandle)){ 
         fprintf(stderr,"error closing datafile\n");
         df->fileError=errno;
         ret=0;
       }
       df->fhandle=0;
    } else { // opened for read
       close(df->fhandle);
       df->fhandle=0; setfl_eof(df,0); // clear eof flag
    }
    return ret;
#   undef  df
}
//unlink file+t[]+>ptr
void unlinkFile(int *a){
   int *arg=parSTACK(a[0])->offset+a[1];
   if(unlink((char*)(arg+1-*arg))<0){
      fprintf(stderr,"unlink file error: %s\n",(char*)(arg+1-*arg));
   }
}

// 'a'put data + ""f + >data + >type
int putDataP(int *a){
int cnt;
#   define df parDFILE(a[0])
    if(!getfl_data(df)){ // not a data file
       fprintf(stderr,"put data on char file\n");
       df->fileError=ENODATAFILE;
       return 0;
    }
    if(df->fhandle<=0){
       df->fileError=ENOTOPENED;
       fprintf(stderr,"put data on closed file\n");
       return 0;
    }
    if(!getfl_rw(df)){
       fprintf(stderr,"put data on input file\n");
       df->fileError=EWRONGTYPE;
       return 0;
    }
    if(a[2]!=0 && a[1]!=0 && a[1]!=-1 ){ // pointer
      // check if a[1] is within the bounds
      for(cnt=0;cnt<df->outarea &&
        (a[1]< df->out[cnt].lwb || df->out[cnt].upb<a[1]);cnt++);
      if(cnt>=df->outarea){
        fprintf(stderr,"putData: pointer %d not among areas\n",a[1]);
        df->fileError=EWRONGVALUE;
        return 0;
      }
    }
    df->fileError=0;
    if((df->fpos & 1023)==1023){ // buffer is full, flush it out
       // repeat while cnt>=0 and the sum is smaller than requested
       df->buffer[31]=df->iflag;
       if(write_Databuffer(df)){ // error writing
         fprintf(stderr,"put data insufficient space\n");
         return 0;
       }
       // prepare next block
       for(cnt=1;cnt<32;cnt++) df->buffer[cnt]=0;
       // df->buffer[0]= ALEPH_BINARY_MAGIC;  // this is so ...
       df->fpos+=33; df->iflag=0u;
    } else if((df->fpos & 31)==31){ // next 32 values are written
       df->buffer[(df->fpos>>5)&31]=df->iflag;
       df->iflag=0;
       df->fpos++;
    } else { // make room for the next flag
       df->iflag <<= 1; df->fpos++;
    }
    df->buffer[(df->fpos)&1023]=a[1]; // store data
    if(a[2]){ df->iflag |= 1; }
    return 1;
#   undef df
}
void putData(int *a){ if(!putDataP(a)){
  fprintf(stderr,"putdata error: %d\n",parDFILE(a[0])->fileError);} }
// 'a'close file + ""f:
// 'p' get data + ""f + data> + type >
int getData(int *a){
#   define df parDFILE(a[0])
    if(!getfl_data(df)){ // not a data file
       fprintf(stderr,"get data on char file\n");
       df->fileError=ENODATAFILE;
       return 0;
    }
    if(df->fhandle<=0 || getfl_rw(df)){
       fprintf(stderr,"get data on closed or input file\n");
       df->fileError=ENOTOPENED;
       return 0; 
    }
    if(getfl_eof(df)){
       df->fileError=EREADEOF;
       return 0;
    }
    // advance df->fpos
    if((df->fpos&1023)==1023){
      if(read_Databuffer(df)){
         fprintf(stderr,"getData: input error, filepos=%d\n",df->fpos);
         // fileError set
         return 0;
      }
      df->fpos+=33; df->iflag=df->buffer[1];
    } else if((df->fpos&31)==31){
      df->fpos++; df->iflag=(unsigned)df->buffer[(df->fpos>>5)&31];
    } else {
       df->fpos++; df->iflag<<=1;
    }
    a[1]=df->buffer[df->fpos&1023];
    a[2]=0; // numerical value
    if(df->iflag & 0x80000000u ){ // pointer
      int i; a[2]=1;
      if(a[1]==-1){ // EOF
        setfl_eof(df,1);
        df->fileError=EREADEOF;
        return 0;
      }
      if(a[1]==0){ return 1; } // nil
      for(i=0;i<df->inarea; i++){
        if(df->in[i].lwb<=a[1] && a[1]<=df->in[i].upb){
           a[1]+= df->in[i].data;
           return 1;
        }
      }
      fprintf(stderr,"getData: pointer with not matching file: %d\n",a[1]);
      df->fileError=EWRONGVALUE;
      return 0;
    }
    return 1;
#   undef df
}
// 'f' getFileError + ""f +err>
void getFileError(int *a){ a[1]=parDFILE(a[0])->fileError; }
//'f' getFilePos + ""f + pos>
void getFilePos(int *a){
#   define df	parDFILE(a[0])
    a[1]=0;
    if(!getfl_data(df) || df->fhandle<=0 ) return;
    a[1]=df->fpos;
    return;
#   undef df
}
//'a' setFilePos + ""f + >pos
void setFilePos(int *a){
    off_t offset;
#   define df	parDFILE(a[0])
    df->fileError=ESEEKERROR;
    if(!getfl_data(df) || df->fhandle<=0 || getfl_rw(df)
      || a[1]<0 ) return;
    if(getfl_eof(df) && a[1]>= df->fpos) return;
    if(a[1]==0){a[1]=32+3*df->inarea; } // special case
    if((a[1]&1023)<32) return;
    df->fileError=0;
    if(a[1]==df->fpos) return; // we are there
    setfl_eof(df,0); // clear EOF indicator
    if((a[1]&~1023)!=(df->fpos & 1023)){ // read the block
      offset=(off_t)(a[1] & ~1023)*sizeof(int);
      if((a[1]&1023)==1023) offset += 1024*sizeof(int);
      if(lseek(df->fhandle,offset,SEEK_SET)<0){ // error
         df->fileError=ESEEKERROR; return;
      }
      if((a[1]&1023)==1023){ // done
          df->fpos=a[1]; return; 
      }
      if(read_Databuffer(df)){ // i/o error
         return;
      }
    } // we have the current block
    df->fpos=a[1];
    df->iflag=(unsigned)(df->buffer[(df->fpos>>5)&31]) << (df->fpos&31);
#   undef df
}



/* EOF */



