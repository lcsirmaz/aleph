/* tags.ale header file */

#ifndef TAGS_H
#define TAGS_H

 /* 'a'enter tag+bu[]+tag> returns a pointer in TTAG */
void enterTag(int *a); 
 /* 'a'find raw usage+>rawtag+usage> returns whether defined, used, not seen. */
void findRawUsage(int *a);

 /* 'a'get tag adm+>rawtag+tag> */
void getTagEntry(int *a);
 /* 'p'was tag pointer+>ptr+[]st[]. */
int wasTagPointer(int *a);
 /* 'a'pack selector+>sel+>tag+x> */
void packSelector(int *a);
void newListEntry(int *a), newFormalTag(int *a);
 /* 'a'redefine tag+>old+>new */
void redefineTag(int *a);
 /* 'a'restore tags */
void restoreTags(void);
void newStdstring(int *a);
void getTagHash(int *a);
 /* 'a'init tags. adds all tags into the search tree */
void initTags(void);
/* dictionary printing */
void addDICT(int *a); /* 'a'add DICT+>rawtag+>line. */
void printDictionary(void);
 /* get tag fields */
void getTag(int *a),getRepr(int *a),getAdm(int *a),getType(int *a),
     getDefline(int*a),getCalibre(int*a),getSsel(int *a),
     getFormalCalibre(int *a),getFormalSsel(int*a);
void putRepr(int *a),putAdm(int *a),putType(int *a),putDefline(int *a),
     putCalibre(int *a),putSsel(int *a),
     putFormalCalibre(int *a),putFormalSsel(int *a);

int isTagFlag(int *a);
void getTagFlag(int *a);
void setTagFlag(int *a),clearTagFlag(int *a),useTag(int *a);

void addTagDefinition(int *a),addTagExternal(int*a),
     addTagImport(int *a),addTagPublic(int *a),addTagPrototype(int *a);

int isSpecialRule(int *a);

/* constants in flag*LADM */
#define tused		0x0001
#define tdefined	0x0002
#define tpublic		0x0004
#define timported	0x0008
#define texternal	0x0010
#define tpermanent	0x0020
#define rmacro		0x0080
#define tnomacro	(timported|texternal|tpermanent)
#define tfill		0x0100
#define toffset		0x0100
// rule flags
#define rsideEffect	0x0100
#define rcanFail	0x0200
#define rnoReturn	0x0400
#define rcallExit	0x2000
#define raffixes	0x4000
#define rvararg		0x8000
#define routvararg	0x10000
#define rshiftrule	0x20000
#define rmchecking	0x40000
#define rmchecked	0x80000
#define rtrace	      0x1000000
#define rcount	      0x2000000
#define rbounds       0x4000000
// rule types
#define rfunc		0
#define raction		rsideEffect
#define rque		rcanFail
#define rpred		(rsideEffect|rcanFail)
#define rexit		rnoReturn
#define rtype		(rsideEffect|rcanFail|rnoReturn)

#define objflags	(tpublic|timported|texternal|rtype|rvararg|routvararg\
                         |rtrace|rcount|rbounds)

extern int Xstar,Xarrow,Xroot,Xexit,Xstringtable,Xshiftaffix;
/* assigning items */
void assignItems(void);
int XstringTableFilling(void);
/* macro */
void linkMacroRule(int *a),searchMacroRule(int *a);
int nextMacroRule(int *a);

   /* fill MESSAGE, TTAG */
void initialize_tags(void);

#endif /* TAGS_H */

/* EOF */

