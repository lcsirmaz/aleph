/* A_lice.c
 * ALEPH target standard procedures
 * (C) 2020, L.Csirmaz
 */
#include "A_lice.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>
/* set up lists; allocated memory is a multiple of 1024 */

int a_request_space(int ID,int n){
  if(n<=0) return 1; /* OK */
  #define st	to_LIST(ID)
  if(st->aupb+n>st->vupb) return 0;
        /* not enough virtual space */
  int newsize=st->aupb-st->vlwb+
              st->calibre+n; // one more than the size
  if(newsize<=st->length) return 0;
  newsize= (newsize+1023)&~1023; //round it
  int *ptr = realloc(st->p,sizeof(int)*newsize );
  if(!ptr) return 0; // no memory
  st->p=ptr;st->length=newsize;
  st->offset=ptr-st->alwb-1+st->calibre;
  return 1;
  #undef st
}

int a_extstrcmp(int ID,int off,const char *str){
  #define st	to_LIST(ID)
  int *ptr=st->offset+off; 
  return strcmp((char*)(ptr+1-*ptr),str);
  #undef  st
}

/* setup routines */
void setup_list(int kind __attribute__((unused)),
               int ID,int cal,int lb,int up,int fill){
  #define st	to_LIST(ID)
  st->offset=0; st->p=0; st->length=0;
  st->vlwb=lb; st->vupb=up; st->calibre=cal;
  st->alwb=lb; st->aupb=st->alwb-cal;
  a_request_space(ID,fill);
  #undef st
}
int ext_list_virtual_start=0x78000000;
void setup_external_list(int kind __attribute__((unused)),
          int ID,int cal, const char *name){
  int b=ext_list_virtual_start;
  #define st to_LIST(ID)
  if(strcmp(name,"@stdarg")==0){
    setup_list(0,ID,cal,b,b+32000,1024); ext_list_virtual_start+=32010;
  } else {
    a_fatal("unknown external list",name);
  }
  #undef st
}
void setup_charfile(int ID,int dir,int dd,int off){
  to_CHFILE(ID)->fileError=0;
}

void setup_external_charfile(int ID,const char *name){
  #define ch	to_CHFILE(ID)
  if(strcmp(name,"@stdin")==0){ch->f=stdin;}
  else if(strcmp(name,"@stdout")==0){ch->f=stdout;}
  #undef ch
}

void a_fatal(const char*m1,const char *m2){
  fputs(m1,stderr);fputc('\n',stderr);fputs(m2,stderr);
  fputs("\nFatal error, aborting\n",stderr);
  abort();
}
void list_fill(int *fill){
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


/* EOF */
