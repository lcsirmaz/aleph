/* clists.c, globally define tables, stacks, files */

#include "stddata.h"

/* all lists and fiiles are offsets in this array defined here */
int __STATIC[ aa_TOTAL];

/* initialize an aSTACK structure */
static void init_stack(aSTACK *st, int lb, int ub, int cal)
{ st->offset=0; st->p=0; st->length=0;
  st->alwb=lb+cal; st->aupb=lb;
  st->vlwb=lb+cal; st->vupb=ub-1;
  st->calibre=cal;
}
void initialize_stdstacks(int argc,char *argv[]){
  init_stack(LEXT,     2000000,3000000,LEXT_CALIBRE);
  init_stack(HASH,     3000000,3500000,HASH_CALIBRE);
  init_stack(EXPRESSION,4000000,5000000,EXPRESSION_CALIBRE);
  init_stack(BOLD,     5200000,5300000,BOLD_CALIBRE);
  init_stack(BUFFER,   5000000,5100000,BUFFER_CALIBRE);
  init_stack(MESSAGE,  5300000,5400000,MESSAGE_CALIBRE);

//  init_stack(INPUT,    5800000,5900000,INPUT_CALIBRE);
  init_stack(NODE,     6000000,6100000,NODE_CALIBRE);
  init_stack(ITEM,     6300000,6400000,ITEM_CALIBRE);
  init_stack(AUX,      5500000,5600000,AUX_CALIBRE);
  init_stack(ZONE,     6400000,6500000,ZONE_CALIBRE);
  init_stack(STDARG,   6200000,6300000,STDARG_CALIBRE);
  /* add all arguments to STDARGS */
  while(argc>1){argc--;add_new_string(argv[argc],STDARG);}
}
/* pack the string given in what to stack st.
   Uses BUFFER as an auxiliary stact, st cannot be BUFFER */
void add_new_string(char *what, aSTACK *st){
   int par[510];
   int n; char *w; int oldupb;
   for(n=0,w=what;*w && n<500;n++,w++){par[n+2]=*w;}
   if(n>=500){printf("add new string too long (%s)\n",what); exit(12);}
   par[0]=STACKpar(BUFFER); par[1]=n;
   oldupb=BUFFER->aupb;
   expandstack(par);
   par[0]=STACKpar(BUFFER); par[1]=n; par[2]=STACKpar(st);
   packstring(par);
   par[0]=STACKpar(BUFFER); par[1]=oldupb; unstackto(par);
}

// DISC, SOURCE, PRINTFILE, SOURCE

void initialize_stdfiles(void){
  int par[5]; int oldupb;
  SOURCE->openflag=0;		// charfile
  PRINTFILE->openflag=0;	// charfile
  TARGET->openflag=0;		// charfile
// open file(PRINTFILE,stdstring,"stdout"), do not use BUFFER for LEXT
  oldupb=LEXT->aupb; add_new_string("stdout",LEXT);
  par[0]=CHFILEpar(PRINTFILE); par[1]='w';par[2]=STACKpar(LEXT);
  par[3]=LEXT->aupb; 
  if(!openFile(par)){fprintf(stderr,"Cannot open PRINTFILE\n"); exit(11); }
  par[0]=STACKpar(LEXT); par[1]=oldupb; unstackto(par);
}


/* EOF */
