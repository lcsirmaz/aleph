/* dics.ale header file */

extern int
  Darea, Dand,   Dbox,   Dbus, Dcalibre, Dclose, Dcolon,
  Dcomma, Dcompl, Dconst, Ddiv, Dend, Dexpression,
  Dextension, Dfile, Dfill, Dinput, Djump,
  Dlabel, Dline, Dlist, Dlocal, Dlwb, Dminus, Dnoarg,
  Dopen, Dor, Dplus, Dpoint, Dpragmat,
  Droot, Drule, Dsemicolon, Dstack, Dmodule,
  Dstar, Dsub, Dtitle, Dto, Dupb, Dvlwb, Dvupb, 
  Dxor;
            

void openDisc(int *a),closeDisc(void),deleteDisc(void),rewindDisc(void);

void D(int *a),Dcons(int *a),Dstring(int *a),Dtag(int *a);
int Q(int *a),Qahead(int*),Qcons(int *a),Qstring(int *a),Qtag(int *a);
void mustQ(int *a),mustQcons(int *a),mustQtag(int *a),Qskip(int *a);
void mustQList(int*a);
void saveDiscPosition(int *a),restoreDiscPosition(int *a);
void macroCallHead(int *a),macroCallTail(int *a);

void initialize_disc(void);

/* EOF */

