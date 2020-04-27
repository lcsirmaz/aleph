/* item.ale header */

void getItem(int *a),getCalibre(int *a),
  getSsel(int *a),getVupb(int *a),getVlwb(int *a);
void putVupb(int *a),putVlwb(int *a);

int isItemFlag(int *a);
void setItemFlag(int *a),clearItemFlag(int *a);

void headSection(void),skipHeadSection(void);
void itemSection(void),skipItemSection(void);
void checkAllItems(void);

void findItemLineno(int *a),findLineno(int*a);

#define tpublic		0x0004
#define timported	0x0008
#define texternsl	0x0010
#define tvalue		0x0020
#define teval		0x0040
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



/* EOF */

