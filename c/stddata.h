/* standard data: stacks, tables, files */

/* list and files are pointers to __STATIC[]. */
#ifndef STDDATA_H
#define STDDATA_H

#include "stdlib.h"

/* tables and stacks */
#define aa_TTAG         0
#define aa_LEXT         (sizeof_STACK)
#define aa_LADM         (2*sizeof_STACK)
#define aa_SPECIAL      (3*sizeof_STACK)
#define aa_CONST	(4*sizeof_STACK)
#define aa_BOLD         (5*sizeof_STACK)
#define aa_BUFFER       (6*sizeof_STACK)
#define aa_RESTORE      (7*sizeof_STACK)
#define aa_MESSAGE      (8*sizeof_STACK)
#define aa_INDICATOR    (9*sizeof_STACK)
#define aa_LLOC         (10*sizeof_STACK)
#define aa_DSYMB        (11*sizeof_STACK)
#define aa_INPUT        (13*sizeof_STACK)
#define aa_RETAG        (14*sizeof_STACK)
#define aa_NODE         (15*sizeof_STACK)
#define aa_RULE         (16*sizeof_STACK)
#define aa_DICT         (17*sizeof_STACK)
#define aa_ITEM         (18*sizeof_STACK)
#define aa_QBUFFER      (19*sizeof_STACK)
#define aa_STDARG       (20*sizeof_STACK)  /* arguments */

/* files */
#define aa_DISC         (21*sizeof_STACK)
//#define aa_OBJ          (aa_DISC+sizeof_DFILE)
#define aa_SOURCE       (aa_DISC+2*sizeof_DFILE)
#define aa_PRINTFILE    (aa_SOURCE+sizeof_CHFILE)
#define aa_OBJ          (aa_SOURCE+2*sizeof_CHFILE)

/* total */
#define aa_TOTAL        (aa_SOURCE+3*sizeof_CHFILE)
/*--------------------------------------------------------*/
/* stacks and files as pointers */
#define TTAG            parSTACK(aa_TTAG)
#define LEXT            parSTACK(aa_LEXT)
#define LADM            parSTACK(aa_LADM)
#define SPECIAL         parSTACK(aa_SPECIAL)
#define CONST		parSTACK(aa_CONST)
#define BOLD            parSTACK(aa_BOLD)
#define BUFFER          parSTACK(aa_BUFFER)
#define RESTORE         parSTACK(aa_RESTORE)
#define MESSAGE         parSTACK(aa_MESSAGE)
#define INDICATOR       parSTACK(aa_INDICATOR)
#define LLOC            parSTACK(aa_LLOC)
#define DSYMB           parSTACK(aa_DSYMB)
#define INPUT           parSTACK(aa_INPUT)
#define RETAG           parSTACK(aa_RETAG)
#define NODE            parSTACK(aa_NODE)
#define RULE            parSTACK(aa_RULE)
#define DICT            parSTACK(aa_DICT)
#define ITEM            parSTACK(aa_ITEM)
#define QBUFFER         parSTACK(aa_QBUFFER)
#define STDARG          parSTACK(aa_STDARG)

#define DISC            parDFILE(aa_DISC)
#define SOURCE          parCHFILE(aa_SOURCE)
#define PRINTFILE       parCHFILE(aa_PRINTFILE)
#define OBJ             parCHFILE(aa_OBJ)
//#define TARGET          parCHFILE(aa_TARGET)
/*--------------------------------------------------------*/
/* selector offsets and calibre  for each list */
/* tags.ale (left, right, adm, lastline, text) TTAG */
#define TTAG_text	0
#define TTAG_lastline	1
#define TTAG_adm	2
#define TTAG_right	3
#define TTAG_left	4
#define TTAG_CALIBRE	5

/* tags.ale (defined,flag,type,repr,adm,tag) LADM */
#define LADM_tag	0
#define LADM_ssel	0
#define LADM_link	0
#define LADM_adm	1
#define LADM_calibre	1
#define LADM_repr	2
#define LADM_dnum	2
#define LADM_type	3
#define LADM_dpos	3
#define LADM_flag	4
#define LADM_fssel	4
#define LADM_defline	5
#define LADM_fcalibre	5
#define LADM_CALIBRE	6

/* tags.ale ()LLOC */
#define LLOC_orepr	5
#define LLOC_calibre	5
#define LLOC_otype	4
#define LLOC_ssel	4
#define LLOC_flag	3
#define LLOC_type	2
#define LLOC_repr	1
#define LLOC_tag	0
#define LLOC_CALIBRE	6
/* lexical.ale LEXT, CONST, SPECIAL */
#define LEXT_CALIBRE	1
#define CONST_CALIBRE	1
#define SPECIAL_CALIBRE	1
/* display.ale, lexical.ale, tags.ale  ()BUFFER */
#define BUFFER_CALIBRE	1
/* lexical.ale  (left,right,adm)BOLD */
#define BOLD_left	2
#define BOLD_right	1
#define BOLD_adm	0
#define BOLD_CALIBRE	3
/* tags.ale (tag,adm)RETAG */
#define RETAG_adm	0
#define RETAG_tag	1
#define RETAG_CALIBRE	2
/* tags.ale ()DICT */
#define DICT_CALIBRE	1
/* input.ale (flag,n,string)INPUT */
#define INPUT_flag	2
#define INPUT_n		1
#define INPUT_string	0
#define INPUT_CALIBRE	3
/* symbols.ale ()RESTORE */
#define RESTORE_CALIBRE	1
/* display.ale */
#define MESSAGE_CALIBRE	1
/* types.ale */
#define INDICATOR_CALIBRE 1
/* disc, obj */
#define ITEM_CALIBRE	6 /* selectors in the linker only */

/* disc */
#define QBUFFER_CALIBRE 1

//#define ZONE_lb		2
//#define ZONE_up		1
//#define ZONE_next	0
//#define ZONE_CALIBRE	3

#define RULE_flag	1
#define RULE_data	0
#define RULE_CALIBRE	2
#define NODE_CALIBRE	6
#define DSYMB_CALIBRE	1
#define STDARG_CALIBRE	1
/*--------------------------------------------------------*/
/* add lwb,upb,calibre for all stacks */
void initialize_stdstacks(int argc,char* argv[]);
/* open PRINTFILE as stdout; set the openflag to zero in all others */
void initialize_stdfiles(void);
/* pack the string given in what to stack st.
   Uses BUFFER as an auxiliary stact, so st cannot be BUFFER */
void add_new_string(char *what, aSTACK *st);

#endif

/* EOF */


