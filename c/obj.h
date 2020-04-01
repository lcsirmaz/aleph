/* obj.ale header file */

void openObjFile(void),closeObjFile(void);
void W(int *a),Wtag(int *a),Wcons(int *a);

void createObjHeader(void),defineObjTag(int *a);
void XstringTableFillingHead(int *a),XstringTableItem(int *a);

void dListFilling(void),dListSize(void),dFileData(void),
     dExpression(void);

/* ------------------------ */
void initialize_obj(void);

/* EOF */
