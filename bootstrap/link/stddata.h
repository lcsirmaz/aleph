/* standard data: stacks, tables, files */

/* list and files are pointers to __STATIC[]. */
#ifndef STDDATA_H
#define STDDATA_H

#include "STDlib.h"

/* tables and stacks */
#define aa_LEXT         0
#define aa_BOLD         (sizeof_STACK)
#define aa_BUFFER       (2*sizeof_STACK)
#define aa_MESSAGE      (3*sizeof_STACK)
#define aa_EXPRESSION   (4*sizeof_STACK)
#define aa_HASH         (5*sizeof_STACK)
//#define aa_DSYMB        (11*sizeof_STACK)
//#define aa_INPUT        (13*sizeof_STACK)
//#define aa_RETAG        (14*sizeof_STACK)
#define aa_NODE         (6*sizeof_STACK)
//#define aa_RULE         (16*sizeof_STACK)
//#define aa_DICT         (17*sizeof_STACK)
#define aa_ITEM         (7*sizeof_STACK)
#define aa_AUX		(8*sizeof_STACK)
#define aa_ZONE         (9*sizeof_STACK)
#define aa_STDARG       (10*sizeof_STACK)  /* arguments */

/* files */
#define aa_PRINTFILE    (21*sizeof_STACK)
#define aa_TARGET       (aa_PRINTFILE+sizeof_CHFILE)
#define aa_SOURCE       (aa_PRINTFILE+2*sizeof_CHFILE)

/* total */
#define aa_TOTAL        (aa_SOURCE+sizeof_CHFILE)
/*--------------------------------------------------------*/
/* stacks and files as pointers */
#define LEXT            parSTACK(aa_LEXT)
#define HASH		parSTACK(aa_HASH)
#define BOLD            parSTACK(aa_BOLD)
#define BUFFER          parSTACK(aa_BUFFER)
#define MESSAGE         parSTACK(aa_MESSAGE)
#define EXPRESSION	parSTACK(aa_EXPRESSION)
#define NODE            parSTACK(aa_NODE)
#define ITEM            parSTACK(aa_ITEM)
#define AUX		parSTACK(aa_AUX)
#define ZONE		parSTACK(aa_ZONE)
#define STDARG          parSTACK(aa_STDARG)

#define TARGET          parCHFILE(aa_TARGET)
#define PRINTFILE       parCHFILE(aa_PRINTFILE)
#define SOURCE          parCHFILE(aa_SOURCE)
/*--------------------------------------------------------*/
/* selector offsets and calibre  for each list */
#define LEXT_next	1
#define LEXT_def	0
#define LEXT_CALIBRE	2

#define BUFFER_CALIBRE	1
#define BOLD_CALIBRE	1
#define HASH_CALIBRE	1

#define MESSAGE_CALIBRE	1
#define EXPRESSION_CALIBRE 1

#define ZONE_lw		2
#define ZONE_up		1
#define ZONE_next	0
#define ZONE_CALIBRE	3


#define ITEM_flag	5
#define ITEM_type	4
#define ITEM_tag	3
#define ITEM_lineno	2
#define ITEM_adm	1
#define ITEM_repr	0
#define ITEM_CALIBRE	6 /* selectors in the linker only */

#define NODE_hash	5
#define NODE_flag	4
#define NODE_tag	3
#define NODE_adm	2
#define NODE_tnext	1
#define NODE_fnext	0
#define NODE_CALIBRE	6

#define STDARG_CALIBRE	1

#define AUX_vlwb	5
#define AUX_vupb	4
#define AUX_fill	3
#define AUX_count	2
#define AUX_calibre	2
#define AUX_width	1
#define AUX_item	1
#define AUX_ssel	1
#define AUX_link	0
#define AUX_data	0
#define AUX_CALIBRE	6

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


