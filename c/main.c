/* main */

#include "stddata.h"
#include "disc.h"
#include "display.h"
#include "files.h"
#include "input.h"
#include "lexical.h"
#include "lists.h"
#include "mcheck.h"
#include "pragmats.h"
#include "passi.h"
#include "rulebody.h"
#include "rules.h"
#include "symbols.h"
#include "tags.h"
#include "types.h"
#include "vars.h"
#include "obj.h"
#include "passii.h"
#include "drules.h"

static void listDiscContent(void){
   int par[3];int d,type,cnt;
   par[0]=STACKpar(LLOC);scratch(par);
   par[0]='r';openDisc(par);cnt=0;nxt:
   par[0]=DFILEpar(DISC);if(getData(par)){
     d=par[1];type=par[2];
     if(type){if(d==0){printf("[nil]");}
       else if(DSYMB->vlwb<=d && d<DSYMB->vupb){
          par[0]=STACKpar(DSYMB);par[1]=d;print(par);}
       else if(LLOC->vlwb<=d && d<=LLOC->vupb){printf("#%d",(d-LLOC->alwb)/6+1);}
       else{par[0]=d;printPointer(par);}}
     else{printf("%d",d);}cnt++;
     if(cnt==8){cnt=0;printf("\n");}else{printf(" ");}
     goto nxt;
   }
   printf("\n\n");closeDisc();
   printf("*****************\n");
//   d=INPUT->alwb;while(d<=INPUT->aupb){
//     printf("  %04x, %d ",INPUT->offset[d-INPUT_flag],INPUT->offset[d-INPUT_n]);
//     par[0]=INPUT->offset[d-INPUT_string];printPointer(par);
//     printf("\n"); d+=INPUT_CALIBRE;
//   }
//   printf("*******************\n");
//   printDictionary();
}


int main(int argc, char *argv[]){
  int par[1];
  /* create all stacks, fill in STDARG */
  initialize_stdstacks(argc,argv);
  /* open PRINTFILE */
  initialize_stdfiles();
  /* go over all modules and call their initialization */
  initialize_disc();	/* Dxxxx values; DISC datafile area */
  initialize_display();	/* MESSAGE */
  initialize_files();	/* MESSAGE */
  initialize_lexical();	/* SPECIAL,CONST,LEXT,BOLD,MESSAGE */
  initialize_input();	/* MESSAGE,LEXT, after lexical */
  initialize_lists();	/* MESSAGE */
  initialize_mcheck();  /* MESSAGE */
  initialize_pragmats();/* TTAG,MESSAGE */
  initialize_passi();	/* MESSAGE, rootScanned=0 */
  initialize_rulebody();/* MESSAGE */
  initialize_rules();	/* MESSAGE */
  initialize_symbols();	/* MESSAGE, RESTORE */
  initialize_types();	/* INDICATOR */
  /* tags uses Iempty; should come after types */
  initialize_tags();	/* MESSAGE, TTAG, LADM */
  initialize_vars();	/* MESSAGE */
  initialize_passii();	/* MESSAGE */
  initialize_obj();	/* MESSAGE */
  initialize_drules();	/* MESSAGE */
  /* this adds standard TTAGs */
  initTags();

  par[0]='w';openDisc(par);
   readSources();readStdlib();
  closeDisc();
  if(wasError()){return 0;}
 
//  listDiscContent(); exit(7);
//  printf("\n**********************\n\n");
  openObjFile();
  createObjHeader();
  par[0]='r';openDisc(par); // including nextDiscSymbol()
  passII();
  if(wasError()){deleteDisc();deleteObjFile();return 1;}
  // check for root ????

  mCheckMacroRules(); // no recursive macro rules

  if(wasError()){deleteDisc();deleteObjFile();return 1;}
  closeObjFile();
  
  return 0;
}

/* EOF */

