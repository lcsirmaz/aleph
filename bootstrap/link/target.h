/* target.ale header file */

void openTarget(void),closeTarget(void),deleteTarget(void);

void dataDeclaration(void),dataInitialization(void);
void fillTableHead(void),dataSectionIII(void),fillTableTail(void);
void dataSectionIV(void);

void ruleDeclarationHead(int *a),ruleDeclarationTail(void);
void targetPrelude(void),targetMain(void);

int isPidginRule(int item);

void Tlabel(int *a),Tbox(int *a),Textension(int *a);
void TruleCall(int *a);
/* ----------------------- */

void initialize_target(void);

/* EOF */

