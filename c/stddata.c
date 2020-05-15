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
  init_stack(TTAG,     1000000,2000000,TTAG_CALIBRE);
  init_stack(LEXT,     2000000,3000000,LEXT_CALIBRE);
  init_stack(LADM,     3000000,4000000,LADM_CALIBRE);
  init_stack(SPECIAL,  4000000,5000000,SPECIAL_CALIBRE);
  init_stack(CONST,    6500000,7000000,CONST_CALIBRE);
  init_stack(BOLD,     5200000,5300000,BOLD_CALIBRE);
  init_stack(BUFFER,   5000000,5100000,BUFFER_CALIBRE);
  init_stack(RESTORE,  5100000,5101000,RESTORE_CALIBRE); // 5200000
  init_stack(MESSAGE,  5300000,5400000,MESSAGE_CALIBRE);
  init_stack(INDICATOR,5400000,5500000,INDICATOR_CALIBRE);
  init_stack(LLOC,     5500000,5600000,LLOC_CALIBRE);
  init_stack(DSYMB,    5600000,5700000,DSYMB_CALIBRE);
//  init_stack(EXPRESSION,5700000,5800000,EXPRESSION_CALIBRE);
  init_stack(INPUT,    5800000,5900000,INPUT_CALIBRE);
  init_stack(RETAG,    5900000,6000000,RETAG_CALIBRE);
  init_stack(NODE,     6000000,6100000,NODE_CALIBRE);
  init_stack(RULE,     6100000,6200000,RULE_CALIBRE);
  init_stack(DICT,     7000000,9900000,DICT_CALIBRE);
  init_stack(ITEM,     6300000,6400000,ITEM_CALIBRE);
  init_stack(QBUFFER,  6400000,6500000,QBUFFER_CALIBRE);
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

// DISC, ICE, PRINTFILE, SOURCE

void initialize_stdfiles(void){
  int par[5]; int oldupb;
  SOURCE->openflag=0;		// charfile
  PRINTFILE->openflag=0;	// charfile
  DISC->openflag=0;		// datafile
  ICE->openflag=0;		// charfile
// open file(PRINTFILE,stdstring,"stdout")
  oldupb=TTAG->aupb; add_new_string("stdout",TTAG);
  par[0]=CHFILEpar(PRINTFILE); par[1]='w';par[2]=STACKpar(TTAG);
  par[3]=TTAG->aupb; 
  if(!openFile(par)){fprintf(stderr,"Cannot open PRINTFILE\n"); exit(11); }
  par[0]=STACKpar(TTAG); par[1]=oldupb; unstackto(par);
}

/* this is not used ... */
#if 0

/* return the simple hash of the given string */
static int compute_hash(char *v){ // compute the hash
   int par[5]; int oldupb,res;
   oldupb=TTAG->aupb;
   add_new_string(v,TTAG);
   par[0]=STACKpar(TTAG); par[1]=TTAG->aupb; simplehash(par);
   res=par[2];
   par[0]=STACKpar(TTAG); par[1]=oldupb; unstackto(par);
   return res;
}

/* collect (list,string) pairs, and then add to the given datafile */
/* add a new list to a datafile area; collect while d==NULL */
void init_datafile(aDATAFILE *d,aSTACK *st, char *name){
  static int cnt=0; static int par[50];
  if(st){ /* add new item to the list */
     if(cnt>15){fprintf(stderr,"init_datafile: count=%d too large\n",cnt); exit(99);}
     par[2+3*cnt]=st->vlwb-st->calibre;
     par[3+3*cnt]=st->vupb;
     par[4+3*cnt]=compute_hash(name);
     cnt++;
  }
  if(d){ /* initialize datafile */
     par[0]=DFILEpar(d); par[1]=cnt; fillDatafile(par);
     cnt=0;
  }
}
#endif

/* EOF */
