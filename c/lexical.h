/* lexical.ale header file */

extern int // pointers to SPECIAL
  Saction,	Sarrow,		Sasterisk,	Sbooland,
  Sboolor,	Sboolxor,	Sbox,		Sbus,
  Scalibre,	Scharfile,	Sclose,		Scolon,
  Scomplement,	Scomma,		Sconssymb,	Sdatafile,
  Sdummysymb,	Sendsymb,	Senquiry,	Seol,
  Sequals,	Sexit,		Sextsymb,	Sfunction,
  Sless,	Slseq,		Slwb,		Sminus,
  Smore,	Smreq,		Snoarg,		Snotequal,
  Sopen,	Splus,		Spoint,
  Spredicate,	Spragsymb,	Squestion,	Sright,
  Srootsymb,	Ssemicolon,	Sslash,		Sstacksymb,
  Sstatic,	Ssub,		Stablesymb,	Supb,
  Svarsymb,	Svlwb,		Svupb;
extern int  // pointer to LEXT, the empty string
  Squoteimage;


int nextSource(int *a);
/* 'p' next source + >type + >ptr:
 *  type=0: the string provided is a file name
 *  type=1: the string starts with --, start reading from the third character
 *     fails if cannot open the file */
void closeSource(void);
/* 'a'close source
 *  clean up; close open files */
void createObjName(void);
/* 'a'create obj name 
 *  add the ".o" extension to the title */

/* 'a' read+x>:
 *   get next symbol into x. It is a pointer to TTAG (tag), LEXT (string),
 *   CONST (constant) or SPECIAL (other). When source is exhausted, sends
 *   Sendsymb */
void Aread(int *a);
/* 'a' skip+x>:
 *  skip until eol, point, or Sendsymb */
void skip(int *a);
/* 'a'forget string+>ptr */
void forgetString(int *a);
/* 'p'was lexical pointer + >p+[]st[]:
   in reporting, printable version of a known pointer */
int wasLexicalPointer(int *a);
/* 'q'was lexical integer+>ptr+x> */
int wasLexicalInteger(int *a);


void initialize_lexical(void);
/* initialize lists SPECIAL, LEXT and CONST; add MESSAGES */



/* EOF */

  
