$ ICE file, produced by ALEPH compiler v2.2
'module' "stdlib" "stdlib stdarg" 32 
4 76 "aleph-stdarg"
77 157 "stdlib"
.
<rule> I1 16640 73 0 "stdlib" "@root"
<table> I2 20 32 1 1 "stdlib" "STDARG"
.
'back'"extern int a_argc; extern char **a_argv;%nstatic int a_push_string_to(int F1,const char*ptr){ int n,w;int*goal;char*to;%n #define st to_LIST(F1)%n n=strlen(ptr);if(a_requestspace(F1,3+(n/4))==0){return 0;}%n n=0;goal=&(st->offset[1+st->aupb]);to=(char*)goal;%n while(*ptr){if((*ptr&0x80)==0){*to++=*ptr++;n++;}  else if((*ptr&0xC0)!=0xC0){ptr++;}  else if((*ptr&0xE0)==0xC0){*to++=*ptr++;n++;   if((*ptr&0xC0)!=0x80){n--;to--;}else{*to++=*ptr++;}}  else if((*ptr&0xF0)==0xE0){*to++=*ptr++;n++;   if((*ptr&0xC0)!=0x80){n--;to--;}else{*to++=*ptr++;    if((*ptr&0xC0)!=0x80){n--;to-=2;}else{*to++=*ptr++;}}}  else if((*ptr&0xF8)==0xF0){*to++=*ptr++;n++;   if((*ptr&0xC0)!=0x80){n--;to--;}else{*to++=*ptr++;    if((*ptr&0xC0)!=0x80){n--;to-=2;}else{*to++=*ptr++;     if((*ptr&0xC0)!=0x80){n--;to-=3;}else {*to++=*ptr++;}}}}  else{ptr++;}}%n *to=0;w=1+(to-((char*)goal))/4;goal[w]=n;goal[w+1]=w+2;st->aupb+=w+2;%n #undef st%n return 1;}%nstatic void a_setup_stdarg(int F1,const char*name,int F2){%n int i;%n #define st to_LIST(F1)%n st->name=name;st->offset=st->p=0;st->length=0; st->vlwb=a_virtual_max+16;a_virtual_max+=65436; if(a_virtual_max<=0){fprintf(stderr,""Out of virtual space\n"");  a_fatal(a_FATAL_memory);}%n st->vupb=a_virtual_max-1;st->calibre=F2; st->alwb=st->vlwb;st->aupb=st->alwb-st->calibre;%n  for(i=a_argc-1;i>0;i--){   if(a_push_string_to(F1,a_argv[i])==0){    fprintf(stderr,""out of memory\n"");a_fatal(a_FATAL_memory);} }%n #undef st%n}".
'front'"static void a_setup_stdarg(int,const char*,int);".
'external'I2 "a_setup_stdarg".
'rule'I1 0 0 0.
