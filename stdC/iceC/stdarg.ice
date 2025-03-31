$ ICE file, produced by ALEPH compiler v2.4
'module' "stdlib" "libC stdarg" 32 
4 64 "stdarg"
65 145 "stdlib"
.
<rule> I1 16640 61 0 "stdlib" "@root"
<table> I2 20 32 1 1 "stdlib" "STDARG"
.
'back'"extern int a_argc; extern char **a_argv;%nstatic int a_push_string_to(int F1,char*ptr){ int n,w;int*goal;char*to;%n #define st to_LIST(F1)%n w=0;n=12;for(to=ptr;*to;to++){n++;if((*to&0xC0)!=0x80)w++;} n/=4;if(!a_requestspace(F1,n))return 0;%n goal=&(st->offset[1+st->aupb]);to=(char*)goal; goal[n-1]=n;goal[n-2]=w;goal[n-3]=0;st->aupb+=n; while(*ptr)*to++=*ptr++;%n #undef st%n return 1;}%nstatic void a_setup_stdarg(int F1,const char*name,int F2){%n int i;%n #define st to_LIST(F1)%n st->name=name;st->offset=st->p=0;st->length=0; st->vlwb=a_virtual_max+16;a_virtual_max+=65436; if(a_virtual_max<=0) a_fatal(a_FATAL_memory);%n st->vupb=a_virtual_max-1;st->calibre=F2; st->alwb=st->vlwb;st->aupb=st->alwb-st->calibre;%n  for(i=a_argc-1;i>0;i--){   if(a_push_string_to(F1,a_argv[i])==0)a_fatal(a_FATAL_memory); }%n #undef st%n}".
'front'"static void a_setup_stdarg(int,const char*,int);".
'external'I2 "a_setup_stdarg".
'rule'I1 0 0 0.
