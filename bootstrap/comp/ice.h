/* ice.ale header file */

void openIceFile(void),closeIceFile(void),deleteIceFile(void);
void W(int *a),Wtag(int *a),Wcons(int *a);

void createIceHeader(void),defineIceTag(int *a);
void XstringTableFillingHead(int *a),XstringTableItem(int *a);

void dListFilling(void),dListSize(void),dFileData(void),
     dExpression(void);

/* ------------------------ */
void initialize_ice(void);

/* EOF */
