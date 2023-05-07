/* aleph core files */

/**************************************************************
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
***************************************************************/

#include "aleph_core.h"

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************
* ALEPH target standard procedures
*
* LISTS: allocation, initialization, standard rules
*
*  a_requestspace(stack,size)
*     makes sure that that the stack has at least size words of 
*     additional allocated space above its actual upper bound. 
*     Called for tables during initialization.
*/
int a_requestspace(int ID,int n){
  #define st    to_LIST(ID)
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
  #define st    to_LIST(ID)
  if(a_requestspace(ID,n)){
     st->top=st->offset+st->aupb;
     return;
  }
  fprintf(stderr,"list %s: extension by %d words, "
                 "out of %s\n",st->name,n,
                 st->aupb+n>st->vupb ?
                       "virtual space" : "memory");
  a_fatal(a_FATAL_memory);
  #undef st
}
/* auxiliary functions */

/* int a_extstrcmp(ID,off,str)
 *     compare the ALEPH string at ID[off] to a C string.
 *     used by a_waitfor() to compare requested module names
 */
int a_extstrcmp(int ID,int off,const char *str){
  #define st    to_LIST(ID)
  int *ptr=st->offset+off; 
  return strcmp((char*)(ptr+1-*ptr),str);
  #undef  st
}
/* a_area_failed(char *rule,int v)
 *   last area in a classification failed
 */
void a_area_failed(const char *rule,int v){
  fprintf(stderr,"rule %s: classification failed for value %d\n",
     rule,v);
  a_fatal(a_FATAL_area);
}
/*******************************************************************
*  Data structure initialization
*
* setup a list structure
*   a_setup_list(kind,list,name,calibre,vlwb,vupb,fill size)
*      kind        0 - table, 1 - stack (ignored)
*      ID          index in a_DATABLOCK, use to_LIST(ID) to get the 
*                  pointer  to the corresponding structure
*      name        name of the list
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
void a_setup_list(int kind __attribute__((unused)),int ID,
             const char*name,int cal,int lb,int up,int fill){
  #define st    to_LIST(ID)
  st->name=name;
  st->offset=0; st->p=0; st->length=0;
  st->vlwb=lb; st->vupb=up; st->calibre=cal;
  st->alwb=lb; st->aupb=st->alwb-cal;
  a_requestspace(ID,fill);
  #undef st
}

/* a_list_fill(int *fill)
 *    filling is collected in the integer array 'fill'
 *    after this call 'fill' can be discarded; the
 *    content could also come from an external file
 */
void a_list_fill(int *fill){
  int ID,x,i,cnt,*idx;
  #define st    to_LIST(ID)
  while((ID=*fill)>=0){
    fill++; idx=&(st->offset[st->aupb+1]);cnt=0;
      while((x=*fill)!=0){
        fill++;if(x>0){cnt=x;st->aupb+=cnt;
               while(x>0){*idx=*fill;idx++;fill++;x--;}}
        else{while(x<-1){x++;st->aupb+=cnt;
           for(i=0;i<cnt;i++){*idx=idx[-cnt];idx++;}}}
      } fill++;
  }
  #undef st
}

/* void a_index_error(int L,int idx,char *rname)
 *  index error message
 */
void a_index_error(int L,int idx,const char*rname){
    fprintf(stderr,"rule %s: index %d of list %s is "
     "out of bounds (%d,%d)\n",
     rname,idx,to_LIST(L)->name,to_LIST(L)->alwb,to_LIST(L)->aupb);
}

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

/* flag manipulating macros  */
#define setflag_general(x,y,flag) \
        if(y){(x)->openflag|=(flag);}else{(x)->openflag&=~(flag);}

#define setfl_data(x,y)         setflag_general(x,y,1)
#define setfl_in(x,y)           setflag_general(x,y,0x20)
#define setfl_out(x,y)          setflag_general(x,y,0x40)

/* a_setup_charfile(ID,name,dir,dd,off)
 *    setup a charfile structure
 *      ID      structure index
 *      name    file name
 *      dir     1,3: in, 2,3: out
 *      dd,off  init string for implicit open
 */
void a_setup_charfile(int ID,const char*name,int dir,int dd,int off){
  #define ch    to_CHFILE(ID)
  ch->name=name;
  ch->openflag=0;ch->fileError=0;ch->st1=dd;ch->st2=off;
  ch->f=NULL; 
  if(dir&1){setfl_in(ch,1);}
  if(dir&3){setfl_out(ch,1);}
  #undef ch
}
/* a_setup_dfile(ID,name,dir,dd,off,cnt)
 *   setup datafile structure
 *      ID      structure index
 *      name    file name
 *      dir     1,3: in, 2,3: out
 *      dd,off  init string for implicit open
 *      cnt     number of lists in file area
 */
void a_setup_dfile(int ID,const char*name,int dir, int dd, int off,int cnt){
  #define df    to_DFILE(ID)
  df->name=name;
  df->openflag=0;df->fileError=0; df->st1=dd;df->st2=off;
  df->fhandle=0; df->iflag=0; df->inarea=df->outarea=0;
  setfl_data(df,1); // this is a datafile
  if(dir&1){setfl_in(df,1);}
  if(dir&3){setfl_out(df,1);}
  if(cnt>=a_MAXIMAL_AREA){
    fprintf(stderr,"datafile %s: too many file areas\n",df->name);
    a_fatal(a_FATAL_datafile);
  }
  #undef df
}
/* a_add_filearea(ID,list,num)
 *   add a filearea; it is called exactly cnt many times for each list
 *      ID     structure index
 *      list   index of the list
 *      num    list position starting from 1
 *             no check is made if the same list is added twice
 */
void a_add_filearea(int ID,int list,int num){
  int i,tmp;
  #define df    to_DFILE(ID)
  i=df->outarea;
  if(i>=a_MAXIMAL_AREA){
    fprintf(stderr,"datafile %s: too many file areas\n",df->name);
    a_fatal(a_FATAL_datafile);
  }
  if(i+1!=num){
    fprintf(stderr,"datafile %s: inconsistent data\n",df->name);
    a_fatal(a_FATAL_datafile);
  }
  df->out[i].lwb=to_LIST(list)->vlwb-to_LIST(list)->calibre+1;
  df->out[i].upb=to_LIST(list)->vupb;
  df->out[i].data=num;
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
* trace and profile
*
*  rules with trace=on start with an
*          a_trace_rule("rule",cnt,F1,F2,...)
*   call with the rule name, number of printed arguments, and the
*   values of the arguments. Depending on the value of "do_trace",
*   it is printed on stderr.
*  rules with count=on have a PROFILE structure linked from 
*   variable a_profiiles.
*
*******************************************************************/
#define TRACE_SIZE      30
static const char *a_traced_rules[TRACE_SIZE];
static int a_traced_index=-1;

#include <stdarg.h>
static int do_trace=0;
void a_trace_rule(const char *name,int affixno,...){
  va_list args; int affix; char *sep="";
  if(a_traced_index<=0){a_traced_index=TRACE_SIZE;}
  a_traced_rules[--a_traced_index]=name;
  if(do_trace==0){return;}
  fprintf(stderr," %s (",name);
  va_start(args,affixno);
  while(affixno>0){
     affix=va_arg(args,int);fprintf(stderr,"%s%d",sep,affix);
     sep=",";affixno--;}
  va_end(args);
  fprintf(stderr,")\n");  
}

/* -------------------------------------------------------------- */
extern a_PROFILE *a_profiles;

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

/*****************************************************************
* the call stack
*  the call stack is at the linked a_CALL block, print this list.
******************************************************************/
#undef a_backtrack
void a_backtrack(a_CALLp tr,int code){
int i=1;
   if(code){fprintf(stderr,"exit with code %d\n",code);}
   while(tr && tr->rule){
      fprintf(stderr,"#%-2d %s ()\n",i,tr->rule);
      i++;tr=tr->next;}
}

/******************************************************************
* a_fatal(code)
*    abort the program; print trace information, if any
*******************************************************************/

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

/******************************************************************
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
   a_traced_index=-1;
   a_ROOT();
   if(a_traced_index>=0 && do_trace==0){
     int i=a_traced_index;
     fprintf(stderr,"Last %d traced rules:\n%s ()\n",
             TRACE_SIZE,a_traced_rules[i]);
     i++;if(i==TRACE_SIZE){i=0;}
     while(i!=a_traced_index){
        if(a_traced_rules[i]){fprintf(stderr,"%s ()\n",a_traced_rules[i]);}
        i++;if(i==TRACE_SIZE){i=0;}
     }
   }
   if(a_profiles){
     fprintf(stderr,"Counted rule calls:\n");
     a_sort_profiles();
     while(a_profiles){
       fprintf(stderr," %-20s => %7lu\n",a_profiles->rulename,a_profiles->count);
       a_profiles=a_profiles->link;
     }
   }
   return 0;
}


/* EOF */
