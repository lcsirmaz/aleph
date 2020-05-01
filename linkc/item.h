/* item.ale header */

void convertToItem(void),getCalibre(int *a),getListLink(int *a),
  getSsel(int *a),getVupb(int *a),getVlwb(int *a);
void putVupb(int *a),putVlwb(int *a),putListLink(int *a);

int isItemFlag(int *a),getItemDef(int *a);
void setItemFlag(int *a),clearItemFlag(int *a);

void headSection(int *a),skipHeadSection(void),advanceBaseItem(int *a);
void itemSection(void),skipItemSection(void);
void fileEntry(void);
void checkAllItems(void);

void findItemLineno(int *a),findLineno(int*a);

#define tpublic		0x0004
#define timported	0x0008
#define texternal	0x0010
#define tvalue		0x0020
#define teval		0x0040
#define tinfile		0x0020
#define toutfile	0x0040
#define rsideeffect	0x0100
#define rcanfail	0x0200
#define rnoreturn	0x0400
#define rvararg		0x8000
#define routvararg	0x10000
#define rtrace		0x1000000
#define rcount		0x2000000
#define rbounds		0x4000000
#define rfunc		0
#define raction		rsideeffect
#define rque		rcanfail
#define rpred		(rsideeffect|rcanfail)
#define rexit		rnoreturn
#define rtype		(rsideeffect|rcanfail|rnoreturn)

/* -------------------------------------------- */
void initialize_item(void);

/* EOF */

