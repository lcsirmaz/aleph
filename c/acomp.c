/* ALEPH TARGET FILE
 * modules: buffer disc display drules files ice input lexical lists *compiler macros node passi passii pragmats rulebody rules symbols tags types variables version
 */
#include "A_lice.h"

#define a_1001 (0) /* @StringTable */
static void a_1005(void); /* @root */
#define a_1006 (a_1001+sizeof_LIST) /* BUFFER */
#define a_1007 (a_1006+sizeof_LIST) /* RULE */
static void a_1010(void); /* @root */
static void a_1012(int a_F1); /* D */
#define a_1013 (a_1007+sizeof_LIST) /* DISC */
#define a_1014 (a_1013+sizeof_DFILE) /* DSYMB */
static void a_1015(int a_F1); /* Dcons */
static void a_1016(int a_F1); /* Dstring */
static void a_1017(int a_F1); /* Dtag */
static int a_1025(int a_F1); /* Q */
#define a_1026 (a_1014+sizeof_LIST) /* QBUFFER */
static int a_1027(int a_F1); /* Qahead */
static int a_1028=0; /* Qbufferptr */
static int a_1029(int a_A[1]); /* Qcons */
static int a_1030=0; /* Qlinenum */
static int a_1031=0; /* Qlocal */
static int a_1032=0; /* Qposition */
static int a_1033=0; /* Qshift */
static void a_1034(int a_F1); /* Qskip */
static int a_1035(int a_A[1]); /* Qstring */
static int a_1036=0; /* Qsymbol */
static int a_1037(int a_A[1]); /* Qtag */
static int a_1038=0; /* Qtype */
static void a_1043(void); /* closedisc */
extern void a_closefile(int a_F1);
static void a_1045(int a_A[1]); /* copyQBUFFERaffix */
static void a_1046(void); /* deletedisc */
static void a_1047(int a_F1); /* expandvarargs */
static void a_1048(int a_F1,int a_F2,int a_A[1]); /* finalssel */
static void a_1049(int a_A[1]); /* fsimpleaffix */
extern int a_getdata(int a_F1,int a_A[2]);
extern void a_getfilepos(int a_F1,int a_A[1]);
static void a_1059(int a_F1,int a_F2); /* handleformallist */
static int a_1065(int a_A[1]); /* limitop */
static int a_1066=0; /* linenum */
static void a_1067(int a_F1); /* macroarguments */
static void a_1068(int a_F1,int a_A[2]); /* macrocallhead */
static void a_1069(int a_F1,int a_F2); /* macrocalltail */
static void a_1070(int a_F1,int a_A[1]); /* matchformalactual */
static void a_1071(int a_F1); /* mustQ */
static void a_1072(int a_A[1]); /* mustQcons */
static void a_1073(int a_A[2]); /* mustQlist */
static void a_1074(int a_A[1]); /* mustQtag */
static void a_1076(void); /* nextdiscsymbol */
static void a_1078(int a_F1); /* opendisc */
extern int a_openfile(int a_F1,int a_F2,int a_F3,int a_F4);
static void a_1080(int a_C,int *a_V); /* putQ */
extern void a_putdata(int a_F1,int a_F2,int a_F3);
static void a_1082(void); /* readfromQBUFFER */
static void a_1083(int a_A[1]); /* readselector */
static void a_1084(int a_F1,int a_F2); /* restorediscposition */
static void a_1085(void); /* rewinddisc */
static void a_1086(int a_A[2]); /* savediscposition */
extern void a_setfilepos(int a_F1,int a_F2);
static void a_1089(void); /* substitute */
extern void a_unlinkfile(int a_F1,int a_F2);
static void a_1097(void); /* @root */
static void a_1098(int a_F1,int a_F2); /* DICTheader */
static void a_1099(int a_F1); /* DICTitem */
static void a_1100(void); /* DICTtab */
static void a_1101(void); /* DICTtail */
#define a_1023 (a_1026+sizeof_LIST) /* MESSAGE */
#define a_1102 (a_1023+sizeof_LIST) /* PRINTFILE */
static void a_1040(int a_F1,int a_C,int *a_V); /* Xerror */
static void a_1103(int a_C,int *a_V); /* Xmessage */
static void a_1041(int a_F1,int a_F2,int a_C,int *a_V); /* Xwarning */
static void a_1104(int a_A[1]); /* clearlocalerror */
extern void a_copystring(int a_F1,int a_F2,int a_F3);
static void a_1107(int a_F1,int a_F2); /* displaychar */
static int a_1109=0; /* errorno */
extern void exit(int a_F1);
static void a_1112(int a_C,int *a_V); /* formatprint */
static void a_1063(int a_F1,int a_F2,int a_F3); /* internalerror */
static int a_1115=0; /* lastdictsrc */
static int a_1116=0; /* localerrorno */
static void a_1117(int a_C,int *a_V); /* message */
static void a_1118(int a_F1,int a_F2); /* messageheader */
static void a_1119(void); /* nlcr */
static int a_1120=1; /* oldprpos */
static void a_1121(int a_A[1]); /* popBUFFER */
static void a_1122(int a_F1,int a_F2); /* print */
static void a_1123(int a_F1); /* printbase */
static void a_1124(int a_F1); /* printchar */
static void a_1125(int a_F1); /* printform */
static void a_1126(int a_F1,int a_F2); /* printform1 */
static void a_1127(int a_F1); /* printint */
static void a_1128(int a_F1,int a_F2); /* printint1 */
static void a_1129(int a_F1); /* printlinehead */
static void a_1130(int a_F1); /* printpointer */
static void a_1131(int a_F1); /* printsourceline */
static int a_1132=0; /* prline */
static int a_1133=0; /* prpos */
static int a_1134=1; /* prposok */
static void a_1135(int a_F1); /* pushBUFFER */
extern void a_putchar(int a_F1,int a_F2);
static void a_1137(int a_F1,int a_F2,int a_F3); /* putstring */
static void a_1138(void); /* resetprline */
static int a_1139=120; /* righthandmargin */
static void a_1140(void); /* saveprpos */
extern int a_stringelem(int a_F1,int a_F2,int a_F3,int a_A[1]);
static void a_1143(int a_F1); /* tabline */
extern void a_unpackstring(int a_F1,int a_F2,int a_F3);
static int a_1147(void); /* waserror */
static int a_1150(int a_F1); /* waslocalerror */
static void a_1154(void); /* @root */
static int a_1155(int a_A[1]); /* Ltag */
static int a_1156(int a_F1,int a_F2,int a_A[1]); /* actualrepeataffix */
static void a_1157(int a_A[3]); /* actualrule */
static void a_1158(int a_F1,int a_F2); /* addlabel */
static void a_1159(int a_F1,int a_F2,int a_F3); /* affixtypeerror */
static void a_1160(int a_F1,int a_F2,int a_F3); /* affixuninitializederror */
static void a_1161(int a_F1,int a_A[6]); /* altsequence */
static void a_1162(int a_F1,int a_A[6]); /* alttail */
static void a_1166(int a_F1,int a_F2,int a_F3); /* checkcalibre */
static void a_1167(int a_F1,int a_F2); /* checkextensionblock */
static void a_1168(int a_F1); /* checklabelshield */
static void a_1169(int a_F1); /* checkmacrorule */
static void a_1170(int a_F1,int a_F2); /* checkoutaffixes */
static void a_1171(int a_F1,int a_F2,int a_F3); /* checkssel */
static void a_1172(int a_F1,int a_F2); /* checkzoneinterval */
static void a_1173(int a_F1,int a_F2); /* checkzonemember */
static void a_1174(int a_F1,int a_A[6]); /* classification */
static void a_1175(int a_A[1]); /* classifier */
static void a_1176(int a_F1,int a_F2); /* clearRULEflag */
static void a_1177(int a_F1,int a_F2); /* clearlocalflag */
static void a_1178(int a_F1); /* cleartailFbits */
static void a_1179(int a_F1); /* closerange */
static int a_1180(int a_F1,int a_F2); /* compatiblerepeatblocktypes */
static int a_1181=0; /* compoundlevel */
static void a_1182(int a_A[6]); /* compoundmember */
static void a_1183(int a_F1,int a_F2); /* constantaffixerror */
static void a_1184(void); /* copylocalTflagtoF */
static void a_1185(int a_F1); /* dcheckrule */
static void a_1186(int a_F1,int a_F2,int a_F3); /* destlisttypeerror */
static void a_1187(int a_F1,int a_F2,int a_F3); /* desttypeerror */
static void a_1188(int a_F1,int a_F2); /* dummyaffixerror */
static void a_1189(int a_F1); /* extendBUFFER */
static void a_1190(int a_F1,int a_F2); /* extendRULE */
static void a_1191(void); /* extension */
static void a_1192(int a_F1,int a_F2); /* ffileaffix */
static void a_1193(int a_F1); /* fshiftaffix */
static void a_1194(int a_F1,int a_F2,int a_F3,int a_A[1]); /* fsimpleaffix */
static void a_1195(int a_F1,int a_F2,int a_F3); /* fstackaffix */
static void a_1196(int a_F1,int a_F2,int a_F3); /* ftableaffix */
static void a_1199(int a_F1,int a_A[1]); /* getftype */
static void a_1200(int a_F1,int a_A[1]); /* getlocalcalibre */
static void a_1201(int a_F1,int a_A[1]); /* getlocalssel */
static int a_1202(int a_F1); /* haslisttype */
static int a_1203(int a_F1,int a_F2); /* isRULEflag */
static int a_1204(int a_F1,int a_F2); /* islocalflag */
static void a_1206(int a_F1,int a_F2,int a_F3,int a_A[1]); /* matchformalactual */
static void a_1207(int a_F1,int a_F2,int a_F3,int a_A[1]); /* matchrepeataffixes */
static void a_1209(int a_F1,int a_A[6]); /* member */
static void a_1210(int a_F1,int a_F2,int a_F3); /* mergealtsequenceflags */
static void a_1211(int a_F1); /* mergetailFbits */
static void a_1213(int a_A[1]); /* mustLtag */
static void a_1214(int a_F1,int a_F2,int a_F3); /* mustbeoflisttype */
static void a_1215(int a_F1); /* openrange */
static void a_1217(int a_F1,int a_F2,int a_F3); /* pushBUFFER */
static void a_1218(int a_F1); /* pushRULE */
static void a_1219(void); /* readbox */
static void a_1220(int a_F1,int a_F2,int a_A[1]); /* readselector */
static void a_1221(int a_F1); /* recomputeRULEflags */
static int a_1222(int a_F1,int a_F2,int a_F3,int a_A[1]); /* redoregion */
static void a_1223(int a_F1); /* resetaffixblockflags */
static void a_1224(int a_A[6]); /* rulebody */
static int a_1225=0; /* rulecompiled */
static void a_1227(int a_F1,int a_F2); /* setRULEflag */
static void a_1228(int a_A[1]); /* setformalaffix */
static void a_1229(int a_F1,int a_F2); /* setlocalflag */
static void a_1230(int a_F1,int a_F2,int a_A[2]); /* setrulejump */
static void a_1231(int a_F1); /* setupaltheadflags */
static void a_1232(int a_F1); /* setupformalstack */
static void a_1233(int a_A[1]); /* setuplabel */
static void a_1234(void); /* setuplocals */
static void a_1235(void); /* skipaffixes */
static void a_1236(void); /* skipsource */
static void a_1237(int a_F1); /* storealtheadflags */
static void a_1238(int a_F1,int a_F2); /* transport */
static void a_1239(int a_F1,int a_F2); /* transportdest */
static int a_1240(int a_F1); /* ureadonly */
static void a_1241(int a_F1); /* usetailFbits */
static void a_1242(int a_F1,int a_A[1]); /* uslicetype */
static void a_1243(int a_F1,int a_F2,int a_A[1]); /* where */
static void a_1244(void); /* @root */
static void a_1250(int a_F1); /* charfiledeclaration */
static void a_1251(int a_F1); /* datafiledeclaration */
static void a_1252(int a_F2,int a_A[1]); /* declaration */
static void a_1253(int a_F1,int a_F2); /* declarationseries */
static void a_1254(int a_F1,int a_F2,int a_F3); /* declarer */
static void a_1255(int a_F1,int a_A[2]); /* expectpath */
static void a_1256(int a_F1,int a_F2,int a_F3); /* externaldeclarer */
static void a_1257(void); /* filearea */
static void a_1258(int a_F1,int a_F2); /* fileareadeclarer */
static void a_1265(int a_F1,int a_F2,int a_F3); /* prototype */
static void a_1270(int a_F1,int a_F2); /* tagredefined */
static void a_1272(void); /* @root */
#define a_1273 (a_1102+sizeof_CHFILE) /* ICE */
#define a_1019 (a_1273+sizeof_CHFILE) /* ITEM */
#define a_1024 (a_1019+sizeof_LIST) /* NODE */
static void a_1274(int a_F1); /* W */
static void a_1275(int a_F1); /* Wcons */
static void a_1276(int a_F1); /* Wline */
static void a_1277(int a_F1); /* Wstring */
static void a_1278(int a_F1); /* Wtag */
static void a_1279(int a_F1); /* Wtype */
static void a_1281(int a_F1); /* Xstringtablefillinghead */
static void a_1282(int a_F1,int a_F2); /* Xstringtableitem */
static void a_1284(int a_A[1]); /* adjustlinenum */
static int a_1286=0; /* baseline */
static void a_1287(int a_F1); /* block */
static void a_1288(int a_F1); /* block2 */
static void a_1289(int a_F1,int a_A[1]); /* block2selector */
static void a_1290(int a_F1,int a_F2); /* checkblock2extension */
static void a_1291(int a_F1); /* checkconstanttag */
static void a_1292(int a_F1); /* checklistitemtype */
static void a_1293(int a_F1); /* checklisttag */
static void a_1295(void); /* closeicefile */
static void a_1296(int a_A[2]); /* countblockitems */
static void a_1297(void); /* createiceheader */
static void a_1299(int a_F1); /* defineicetag */
static void a_1300(void); /* deleteicefile */
static void a_1301(void); /* dexpression */
static void a_1302(void); /* dfiledata */
static void a_1304(void); /* dlistfilling */
static void a_1305(void); /* dlistsize */
static void a_1306(void); /* exprbase */
static void a_1307(void); /* expression */
static void a_1308(int a_F1); /* extendBUFFER */
static void a_1309(void); /* filearea */
static void a_1313(int a_F1); /* formalaffixes */
static void a_1315(int a_A[1]); /* getnewitem */
static void a_1318(void); /* initializer */
static int a_1319(int a_F1); /* isfilltagused */
static int a_1320(int a_F1,int a_F2); /* isitemtag */
static void a_1322(int a_F1); /* listdata */
static void a_1323(int a_F1); /* listitem */
static int a_1325=0; /* nextitem */
static void a_1326(void); /* nlcr */
static void a_1327(int a_F1); /* noexternal */
static void a_1328(void); /* openicefile */
static void a_1329(int a_F1); /* printint */
static void a_1330(int a_F1,int a_F2); /* printint1 */
static void a_1331(int a_F1,int a_F2,int a_F3); /* putasstring */
static void a_1332(int a_F1,int a_F2,int a_F3); /* putstring */
static void a_1333(void); /* repeater */
static void a_1334(void); /* separator */
static void a_1336(int a_F1); /* writestring */
static void a_1337(int a_F1,int a_F2); /* wrongtype */
static void a_1338(void); /* @root */
#define a_1339 (a_1024+sizeof_LIST) /* INPUT */
#define a_1340 (a_1339+sizeof_LIST) /* a_setup_stdarg */
extern void a_setup_stdarg(int,int);
static void a_1341(int a_F1,int a_A[1]); /* addcommandlinearg */
static void a_1342(int a_F1); /* addincludedsource */
static void a_1343(int a_F1); /* addrequiredsource */
static void a_1344(int a_F1,int a_F2); /* addsource */
extern void a_comparestring(int a_F1,int a_F2,int a_F3,int a_F4,int a_A[1]);
static void a_1111(int a_F1,int a_A[2]); /* findlinenum */
static void a_1310(int a_A[1]); /* firstlineoffset */
static int a_1349(int a_A[1]); /* getfirstsource */
static void a_1350(void); /* initprogramargs */
static int a_1351(int a_F1,int a_A[3]); /* iscmdlinepragmat */
static int a_1352(int a_F1); /* ishelpargument */
static int a_1353(int a_F1); /* isversionargument */
static int a_1354=0; /* lastlinenum */
static int a_1355(int a_A[1]); /* nextinput */
static int a_1324(int a_A[3]); /* nextinputentry */
static void a_1358(void); /* readarguments */
static void a_1359(void); /* readsources */
static void a_1360(void); /* readstdlib */
static void a_1362(int a_F1); /* setpragmats */
static int a_1364(int a_F1,int a_A[1]); /* wassourceadded */
static void a_1365(void); /* @root */
#define a_1366 (a_1340+sizeof_LIST) /* BOLD */
#define a_1011 (a_1366+sizeof_LIST) /* CONST */
#define a_1021 (a_1011+sizeof_LIST) /* LEXT */
static int a_1367=0; /* LEXTcnt */
static int a_1368=0; /* LEXTlen */
static int a_1369=-1; /* LEXTptr */
#define a_1370 (a_1021+sizeof_LIST) /* SOURCE */
#define a_1371 (a_1370+sizeof_CHFILE) /* SPECIAL */
static void a_1372(void); /* addextension */
static int a_1373(int a_A[1]); /* boldletter */
static int a_1374=32; /* char */
static void a_1346(void); /* closesource */
static void a_1298(void); /* createicename */
static void a_1375(int a_F2,int a_F3,int a_A[1]); /* decimaloverflow */
static int a_1376(int a_A[1]); /* digit */
static void a_1377(int a_F1,int a_A[1]); /* enterconst */
static int a_1379=-4; /* exhausted */
static void a_1380(int a_F1); /* extendBUFFER */
static void a_1312(int a_F1); /* forgetstring */
extern int a_getchar(int a_F1,int a_A[1]);
static int a_1383=0; /* givetext */
static int a_1384(int a_A[1]); /* hexdigit */
static void a_1385(int a_F2,int a_A[1]); /* hexoverflow */
static int a_1387(int a_A[1]); /* letgit */
static void a_1389(void); /* longcomment */
static void a_1390(void); /* nextchar */
static int a_1356(int a_F1,int a_F2); /* nextsource */
static void a_1391(void); /* nextvisiblechar */
static int a_1392(int a_F1,int a_F2); /* opensourcefile */
static int a_1393=0; /* optor */
extern void a_packstring(int a_F1,int a_F2,int a_F3);
static int a_1395=0; /* pchar */
static int a_1396=0; /* ppline */
static void a_1397(int a_A[1]); /* read */
static void a_1398(int a_A[1]); /* readbold */
static void a_1399(int a_A[1]); /* readbuiltin */
static void a_1400(int a_A[1]); /* readchardenotation */
static void a_1401(int a_F1,int a_A[1]); /* readconst */
static void a_1402(int a_F1,int a_A[1]); /* readgreater */
static void a_1403(int a_F1,int a_A[1]); /* readhex */
static void a_1404(int a_F1,int a_A[1]); /* readless */
static void a_1405(int a_A[1]); /* readminus */
static void a_1406(int a_A[1]); /* readminuswithspaces */
static void a_1407(int a_A[1]); /* readstring */
static void a_1408(int a_A[1]); /* readtag */
static void a_1409(int a_F1,int a_A[1]); /* readzero */
static int a_1411(void); /* shortcomment */
static void a_1412(int a_A[1]); /* skip */
static void a_1413(void); /* skipchardenotation */
static void a_1414(void); /* skipstring */
static int a_1415=8; /* tabwidth */
static void a_1416(int a_F2,int a_A[2]); /* trynextpath */
static void a_1417(int a_F1,int a_A[1]); /* trypath */
static void a_1418(int a_F1,int a_A[1]); /* trytoopen */
static int a_1148(int a_F1,int a_A[1]); /* waslexicalinteger */
static int a_1149(int a_F1,int a_F2); /* waslexicalpointer */
static int a_1419=0; /* wastab */
static void a_1420(void); /* @root */
static void a_1422(int a_F2,int a_A[1]); /* declaration */
static void a_1423(int a_F1,int a_F2); /* declarationseries */
static void a_1424(int a_F1,int a_F2,int a_F3,int a_F4); /* declarer */
static void a_1425(int a_F1); /* extendedblock */
static void a_1426(int a_F1,int a_F2); /* externaldeclarer */
static void a_1311(int a_F1); /* fixlistusage */
static void a_1428(int a_A[4]); /* getexternallisttag */
static void a_1429(int a_A[4]); /* getlisttag */
static void a_1430(int a_F1); /* initializer */
static int a_1433(void); /* isextendedblock */
static void a_1434(int a_F1,int a_F2,int a_F3,int a_F4); /* listdeclarationtail */
static void a_1435(int a_F1,int a_F2); /* listfill */
static void a_1436(int a_F1); /* listfillblock */
static void a_1439(int a_F1,int a_F2,int a_F3); /* noselectorlist */
static void a_1441(int a_F1,int a_F2,int a_A[1]); /* prototype */
static void a_1446(void); /* repeatcount */
static void a_1447(int a_F1,int a_F2,int a_F3); /* selectorlist */
static void a_1448(int a_F1,int a_A[1]); /* selectors */
static void a_1450(int a_A[2]); /* sizeestimator */
static void a_1451(int a_A[2]); /* skipfieldlist */
static void a_1452(int a_F1); /* stackdeclaration */
static void a_1453(void); /* staticstackdeclaration */
static void a_1454(int a_F1); /* tabledeclaration */
static void a_1455(int a_F1,int a_F2); /* tagredefined */
static void a_1456(void); /* @root */
static void a_1458(void); /* firstpass */
static void a_1462(void); /* secondpass */
static void a_1463(void); /* thirdpass */
static void a_1465(void); /* @root */
static void a_1466(void); /* alternative */
static void a_1467(void); /* altsequence */
static void a_1468(int a_F1); /* checkmacrorule */
static void a_1457(void); /* checkmacrorules */
static void a_1469(void); /* classification */
static void a_1470(void); /* member */
static void a_1472(void); /* rulebody */
static void a_1474(void); /* skipaffixes */
static void a_1475(void); /* skipsource */
static void a_1476(void); /* @root */
static void a_1477(void); /* Bback */
static int a_1478(int a_F1,int a_A[1]); /* Bdata */
static void a_1479(int a_A[1]); /* Bgetptr */
static void a_1480(int a_F1); /* Bsetdata */
static void a_1481(int a_F1); /* Bsetflag */
static int a_1482=0; /* C1 */
static int a_1483=0; /* C2 */
static int a_1484=0; /* C3 */
static void a_1485(int a_F1); /* DUalternative */
static int a_1486(int a_F1); /* DUmember */
static void a_1487(int a_F1); /* DUregion */
static int a_1488(int a_F1); /* DUrule */
static void a_1489(void); /* Lfindlabels */
static void a_1490(int a_F1,int a_F2,int a_A[1]); /* Lscani */
static void a_1491(void); /* Lscanii */
static void a_1492(int a_F1); /* Lunroll */
static int a_1493=0; /* RULEtop */
static int a_1494(int a_F1,int a_F2); /* Uactualrule */
static void a_1495(int a_F1); /* Ualternative */
static int a_1496=0; /* Ufinalchanged */
static int a_1497(int a_F1,int a_F2); /* Umember */
static int a_1498=0; /* Uptr */
static void a_1499(int a_F1); /* Uregion */
static int a_1500=3; /* addRULEflag */
static void a_1501(void); /* assignnodes */
static void a_1502(int a_F1,int a_F2,int a_F3); /* clearRULEflag */
static void a_1503(int a_F1); /* closerange */
static void a_1504(void); /* computeDUflags */
static void a_1505(int a_F1,int a_F2,int a_F3); /* copyUf1toUf2 */
static void a_1506(int a_F1,int a_F2); /* copyjumpUf */
static void a_1507(int a_F1,int a_A[1]); /* copyspareaffix */
static void a_1508(void); /* diagnoseformals */
static void a_1509(int a_F1,int a_F2,int a_F3); /* diagnoselocal */
static void a_1510(int a_F1,int a_F2); /* diagnoseoutaffix */
static void a_1511(int a_F1); /* diagnoserule */
static int a_1512=0; /* expandflag */
static void a_1513(int a_F1); /* expandmacro */
static void a_1514(int a_F1); /* extendBUFFER */
static void a_1515(int a_F1,int a_F2); /* extendRULE */
static void a_1516(int a_F1,int a_F2,int a_A[1]); /* finalssel */
static void a_1517(int a_F1); /* gactualrule */
static void a_1518(void); /* galtsequence */
static void a_1519(void); /* galttail */
static void a_1520(int a_A[1]); /* garea */
static void a_1521(void); /* gclassification */
static void a_1522(void); /* gcompound */
static void a_1523(int a_F1); /* generaterule */
static void a_1524(void); /* gextension */
static void a_1525(int a_F1,int a_F2); /* ghandleaffix */
static void a_1526(int a_F1); /* ghandleshiftrule */
static void a_1527(int a_F1,int a_F2); /* ghandlevarargblock */
static int a_1528(void); /* glimit */
static void a_1529(int a_F1,int a_A[1]); /* gmatchformalactual */
static void a_1530(void); /* gmember */
static void a_1531(void); /* greadbox */
static void a_1532(void); /* grulebody */
static void a_1533(int a_F1,int a_A[1]); /* gsimpleaffix */
static void a_1534(void); /* gtransportlist */
static int a_1535(int a_F1); /* inutype */
static int a_1536=0; /* maxlocal */
static void a_1537(int a_F1,int a_F2); /* mergeDUflags */
static void a_1538(int a_F1,int a_F2,int a_F3); /* mergeUf1toUf2 */
static int a_1539=0; /* minlocal */
static int a_1540=0; /* nodecount */
static int a_1541(int a_F1); /* oututype */
static void a_1542(int a_C,int *a_V); /* pushBUFFER */
static void a_1543(int a_F1,int a_F2); /* pushRULE */
static void a_1544(int a_F1,int a_F2); /* recoverflagsfromregion */
static int a_1545=0; /* rulecalled */
static int a_1546=0; /* rulecompiled */
static void a_1547(int a_F1,int a_F2,int a_F3); /* setRULEflag */
static void a_1548(int a_F1,int a_F2,int a_F3); /* setflagsforregion */
static void a_1549(int a_F1); /* setflagsforrule */
static void a_1550(int a_F1); /* setupformalstack */
static void a_1551(int a_A[1]); /* setuplabel */
static void a_1552(void); /* setuplocals */
static void a_1553(int a_F1,int a_A[1]); /* startrange */
static void a_1554(int a_F1); /* traverseRULE */
static void a_1555(int a_F1,int a_A[1]); /* utypetoslice */
static void a_1556(int a_F1); /* wactualrule */
static void a_1557(int a_F1,int a_F2,int a_F3,int a_F4); /* wafteraffixes */
static void a_1558(int a_F1); /* waftershiftrule */
static void a_1559(int a_F1,int a_F2); /* waftervarargblock */
static void a_1560(void); /* waltsequence */
static void a_1561(void); /* walttail */
static void a_1562(int a_F1); /* warea */
static void a_1563(int a_F1); /* wbeforeshiftrule */
static void a_1564(int a_F1,int a_F2); /* wbeforevarargblock */
static void a_1565(void); /* wclassification */
static void a_1566(void); /* wcompound */
static void a_1567(int a_A[1]); /* wcopyaffixfromBUFFER */
static void a_1568(void); /* wextension */
static void a_1569(int a_F1); /* whandleaffix */
static void a_1570(int a_F1); /* wlabel */
static int a_1571(int a_A[1]); /* wlimit */
static void a_1572(int a_F1,int a_A[1]); /* wmatchformalactual */
static void a_1573(void); /* wmember */
static void a_1574(void); /* wreadbox */
static void a_1575(void); /* wrulebody */
static void a_1576(int a_F1,int a_A[1]); /* wsimpleaffix */
static void a_1577(int a_A[1]); /* wtransportlist */
static void a_1578(void); /* @root */
static int a_1580(int a_F1); /* declaration */
static void a_1581(void); /* externaldeclaration */
static void a_1357(void); /* passI */
static void a_1586(void); /* root */
static int a_1588=0; /* rootscanned */
static void a_1591(void); /* staticdeclaration */
static void a_1593(void); /* tagenquiry */
static void a_1464(void); /* wasrootscanned */
static void a_1595(void); /* @root */
static void a_1596(int a_F1); /* checktagformacro */
static void a_1597(int a_F1); /* checktagforpublic */
static void a_1598(void); /* dreadpragmat */
static void a_1599(int a_F1); /* dstoremacro */
static void a_1459(void); /* passII */
static void a_1460(void); /* passIII */
static void a_1601(void); /* @root */
static int a_1603(int a_A[1]); /* aheadrawtag */
static int a_1604=0; /* bounds */
static void a_1605(void); /* clearlibrary */
static void a_1347(void); /* cmdlinepragmat */
static void a_1606(int a_F1,int a_F2); /* conspragmat2 */
static int a_1607=0; /* count */
static int a_1608=0; /* dicton */
static void a_1609(int a_F1,int a_F2); /* discpragmat */
static void a_1610(int a_F1,int a_F2); /* dopragmatskip */
static void a_1611(int a_F1,int a_F2,int a_A[1]); /* findifcondition */
static void a_1612(void); /* findmatchingendif */
static void a_1114(int a_F1,int a_A[1]); /* getpragmatvalue */
static int a_1613=0; /* givetext */
static int a_1614=0; /* icename */
static int a_1615=0; /* includepath */
static int a_1616=1; /* incompile */
static int a_1617=0; /* inlibrary */
static int a_1618=0; /* inmodule */
static void a_1619(int a_F1); /* insertsymbol */
static int a_1321(int a_F1); /* ispragmatvalue */
static void a_1620(int a_F1,int a_F2); /* markrawtagasmacro */
static void a_1621(int a_F1,int a_F2); /* markrawtagaspublic */
static void a_1622(void); /* nextpragmatsymbol */
static void a_1623(int a_F1,int a_F3,int a_A[1]); /* onoffpragmats */
static int a_1624=0; /* pgmiftag */
static int a_1625=0; /* pgmskip */
static int a_1626=0; /* pgmstate */
static int a_1627=0; /* pgmtag */
static void a_1628(int a_F1); /* pragmatitem */
static void a_1585(int a_A[1]); /* programpragmat */
static void a_1629(int a_A[1]); /* programpragmat2 */
static void a_1630(int a_F1,int a_A[1]); /* programpragmatitem */
static void a_1631(int a_F1,int a_F2,int a_F3,int a_A[1]); /* programtagpragmat2 */
static int a_1632=1516190322; /* programtitle */
static int a_1633=2; /* protolevel */
static void a_1361(void); /* resetpragmats */
static void a_1634(void); /* restoreliblevel */
static int a_1635=120; /* rightmargin */
static int a_1636=0; /* saveproto */
static int a_1637=0; /* savewarning */
static void a_1638(void); /* setliblevel */
static void a_1639(void); /* setlibrary */
static void a_1363(int a_F1,int a_F2); /* setpragmatvalue */
static void a_1640(int a_F1,int a_F2); /* stringpragmat2 */
static int a_1641=8; /* tabwidth */
static void a_1642(int a_F1,int a_F2,int a_F3); /* tagpragmat2 */
static int a_1643=0; /* trace */
static int a_1644=1; /* usestdlib */
static int a_1645=4; /* warninglevel */
static void a_1646(void); /* @root */
static void a_1647(int a_F1); /* addlocalaffix */
static void a_1648(void); /* addlocalaffixes */
static void a_1649(void); /* affixform */
static void a_1650(void); /* alternative */
static void a_1651(void); /* alternativeseries */
static void a_1652(int a_A[1]); /* area */
static void a_1653(void); /* classification */
static void a_1654(void); /* classifier */
static void a_1655(int a_F1); /* closelocalrange */
static void a_1656(void); /* compoundmember */
static void a_1657(int a_F1); /* extension */
static int a_1658=0; /* formalrepeataffix */
static void a_1382(int a_A[1]); /* getruletag */
static void a_1659(int a_F1); /* handleformallist */
static void a_1660(int a_F1); /* indexsource */
static void a_1662(int a_F1); /* listtag */
static int a_1663(void); /* lookingatamember */
static void a_1664(void); /* member */
static void a_1665(int a_F1,int a_A[1]); /* opennewlocalrange */
static void a_1666(int a_A[1]); /* peekaftersource */
static void a_1667(int a_A[1]); /* peeklabel */
static int a_1668(void); /* repeataffix */
static void a_1587(void); /* rootbody */
static void a_1669(int a_F1,int a_F2); /* rulebody */
static void a_1670(int a_F1); /* rulepragmats */
static int a_1671=0; /* ruletag */
static void a_1672(int a_F1); /* searchjump */
static void a_1673(int a_F1,int a_F2); /* selector */
static void a_1674(int a_F1,int a_A[1]); /* setuplocalstack */
static void a_1675(int a_F1); /* skiplabel */
static void a_1676(void); /* skipoveranindex */
static void a_1677(void); /* skipoverdestination */
static void a_1678(int a_F1,int a_A[2]); /* skipoverextension */
static void a_1679(int a_A[1]); /* skipoversource */
static void a_1680(int a_F1); /* source */
static void a_1681(int a_F1); /* sourceorstring */
static void a_1682(int a_F1); /* specialaffixform */
static int a_1683=0; /* suppressmessages */
static int a_1684(void); /* terminator */
static void a_1685(int a_F1); /* toselectors */
static void a_1686(void); /* @root */
static void a_1687(int a_F1,int a_F3,int a_F4,int a_A[2]); /* checkasformal */
static void a_1688(int a_F1,int a_F3,int a_F4,int a_F5,int a_A[2]); /* checkasformallist */
static void a_1689(int a_F1,int a_F2,int a_A[2]); /* checkasformaltableaffix */
static void a_1690(int a_F1,int a_F2,int a_A[1]); /* checkformalaffixes */
static void a_1691(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6,int a_A[1]); /* checkformallistdata */
static void a_1692(int a_F1,int a_F2); /* checkoutaffixes */
static void a_1693(int a_F1,int a_F2,int a_F3,int a_A[1]); /* checkruletype */
static void a_1694(int a_F1,int a_F2,int a_A[1]); /* checkselectorlist */
static void a_1695(int a_F1,int a_F2,int a_A[1]); /* createformalaffixes */
static void a_1696(int a_F1,int a_F2,int a_F3,int a_F4,int a_A[1]); /* createformalselector */
static void a_1697(int a_F1,int a_F3,int a_F4,int a_A[2]); /* defineasformal */
static void a_1698(int a_F1,int a_F3,int a_F4,int a_F5,int a_A[2]); /* defineasformallist */
static void a_1699(int a_F1,int a_F2,int a_A[2]); /* defineasformaltableaffix */
static void a_1700(int a_F1,int a_F2,int a_F3,int a_A[2]); /* defineselectorlist */
static void a_1701(int a_F1,int a_A[1]); /* expectformaltag */
static void a_1702(int a_F1,int a_F2,int a_A[2]); /* formalaffix */
static void a_1703(int a_F1,int a_F2,int a_F4,int a_F5,int a_A[2]); /* formalflataffix */
static void a_1704(int a_F1,int a_F2,int a_F4,int a_A[2]); /* formallistaffix */
static void a_1705(int a_F1,int a_F2,int a_F4,int a_A[2]); /* formaltableaffix */
static void a_1706(int a_A[3]); /* getlisttag */
static void a_1707(int a_A[1]); /* musttag */
static void a_1709(int a_F1,int a_A[2]); /* peekafterformalaffixes */
static int a_1713=0; /* repeatformalaffix */
static void a_1589(int a_F1,int a_F2); /* ruledeclaration */
static void a_1715(int a_F1,int a_F2); /* ruledeclarer */
static void a_1716(int a_F1,int a_F2,int a_F3); /* ruledefinition */
static void a_1717(int a_F1,int a_F2); /* ruledefinitionsequence */
static void a_1718(int a_F1,int a_F2); /* ruleexternaldeclarer */
static void a_1719(int a_F1,int a_F2); /* ruleprototype */
static void a_1720(int a_A[2]); /* skipfieldlist */
static void a_1721(int a_F1,int a_A[1]); /* skipformalaffix */
static void a_1722(int a_F1,int a_A[1]); /* subbus */
static void a_1723(void); /* @root */
#define a_1724 (a_1371+sizeof_LIST) /* RESTORE */
static void a_1421(int a_F1); /* Rskip */
static void a_1345(void); /* advancelinenum */
static int a_1725(void); /* aheadcons */
static void a_1726(int a_A[1]); /* countrestore */
static int a_1727=0; /* dorestore */
static void a_1427(void); /* forgetrestore */
static void a_1314(int a_A[1]); /* getlinenum */
static void a_1431(void); /* initrestore */
static int a_1062=0; /* inpt */
static int a_1728=1454738096; /* inrestore */
static int a_1432(int a_A[1]); /* iscons */
static int a_1584(int a_A[1]); /* israwtag */
static int a_1260(int a_A[1]); /* isstring */
static int a_1261(int a_A[1]); /* istag */
static int a_1262(int a_A[2]); /* istagdl */
static int a_1729=0; /* linenum */
static void a_1437(void); /* makerestore */
static void a_1263(int a_F1); /* must */
static void a_1077(void); /* nextsymbol */
static int a_1730=0; /* oldinpt */
static int a_1731=0; /* oldlinenum */
static int a_1732=0; /* oldrestore */
static int a_1733=1454738096; /* outrestore */
static int a_1734(void); /* readfromrestore */
static int a_1735=0; /* restorecount */
static void a_1736(void); /* savetorestore */
static void a_1088(int a_F1); /* setlinenum */
static void a_1737(void); /* setsymbolposition */
static void a_1268(void); /* skipall */
static void a_1590(void); /* skipsilently */
static void a_1738(void); /* skipsymbol */
static void a_1269(void); /* skiptopoint */
static void a_1739(void); /* @root */
#define a_1740 (a_1724+sizeof_LIST) /* DICT */
static void a_1741(int a_F1); /* DICTtag */
#define a_1020 (a_1740+sizeof_LIST) /* LADM */
#define a_1022 (a_1020+sizeof_LIST) /* LLOC */
#define a_1742 (a_1022+sizeof_LIST) /* RETAG */
#define a_1039 (a_1742+sizeof_LIST) /* TTAG */
static int a_1280(void); /* Xstringtablefilling */
static void a_1602(int a_F1,int a_F2); /* addDICT */
static void a_1743(int a_F1,int a_F2); /* addlinetoDICT */
static void a_1744(int a_F1,int a_F2); /* addspecialrule */
static void a_1245(int a_F1,int a_F2,int a_A[1]); /* addtagdefinition */
static void a_1246(int a_F1,int a_F2,int a_A[1]); /* addtagexternal */
static void a_1247(int a_F1,int a_F2,int a_A[1]); /* addtagimport */
static void a_1248(int a_F1,int a_F2); /* addtagprototype */
static void a_1249(int a_F1,int a_F2,int a_A[1]); /* addtagpublic */
static void a_1285(void); /* assignitems */
static void a_1745(int a_F1); /* assigntags */
static void a_1294(int a_F1,int a_F2); /* cleartagflag */
static void a_1746(int a_F1); /* enterpredefinedtag */
static void a_1378(int a_F1,int a_A[1]); /* entertag */
static void a_1747(int a_F1,int a_F2); /* expandDICT */
static void a_1748(int a_F1); /* extendBUFFER */
static void a_1749(int a_F1); /* extendDICT */
static void a_1582(int a_F1,int a_A[1]); /* findrawusage */
static void a_1050(int a_F1,int a_A[1]); /* getadm */
static void a_1197(int a_F1,int a_A[1]); /* getcalibre */
static void a_1198(int a_F1,int a_A[1]); /* getdefline */
static void a_1054(int a_F1,int a_A[1]); /* getformalcalibre */
static void a_1055(int a_F1,int a_A[1]); /* getformalssel */
static void a_1056(int a_F1,int a_A[1]); /* getrepr */
static void a_1057(int a_F1,int a_A[1]); /* getssel */
static void a_1316(int a_F1,int a_A[1]); /* gettag */
static void a_1583(int a_F1,int a_A[1]); /* gettagentry */
static void a_1317(int a_F1,int a_F2,int a_A[1]); /* gettagflag */
static void a_1259(int a_F1,int a_A[1]); /* gettaghash */
static void a_1058(int a_F1,int a_A[1]); /* gettype */
static void a_1750(void); /* initrules */
static void a_1751(void); /* initstdstringtable */
static void a_1752(void); /* inittags */
static int a_1661(int a_F1,int a_A[1]); /* isspecialrule */
static int a_1753(int a_F1); /* isspecialtag */
static int a_1205(int a_F1,int a_F2); /* istagflag */
static void a_1600(int a_F1,int a_F2,int a_F3); /* linkmacrorule */
static int a_1754=0; /* macroptr */
static void a_1708(int a_F1,int a_F2,int a_A[1]); /* newformaltag */
static void a_1438(int a_F1,int a_F2); /* newlistentry */
static void a_1264(int a_F1,int a_A[1]); /* newstdstring */
static void a_1755(int a_F1,int a_A[1]); /* newtagentry */
static int a_1471(int a_A[1]); /* nextmacrorule */
static void a_1756(int a_F1,int a_F2,int a_A[1]); /* pack2 */
static void a_1440(int a_F1,int a_F2,int a_A[1]); /* packselector */
static void a_1757(int a_F1); /* printdict */
static void a_1461(void); /* printdictionary */
static void a_1442(int a_F1,int a_F2); /* putadm */
static void a_1443(int a_F1,int a_F2); /* putcalibre */
static void a_1444(int a_F1,int a_F2); /* putdefline */
static void a_1710(int a_F1,int a_F2); /* putformalcalibre */
static void a_1711(int a_F1,int a_F2); /* putformalssel */
static void a_1266(int a_F1,int a_F2); /* putrepr */
static void a_1445(int a_F1,int a_F2); /* putssel */
static void a_1267(int a_F1,int a_F2); /* puttype */
static void a_1712(int a_F1,int a_F2); /* redefinetag */
extern void a_release(int a_F1);
static void a_1714(void); /* restoretags */
static void a_1759(int a_F1); /* reverseDICT */
static void a_1473(int a_F1,int a_A[2]); /* searchmacrorule */
static void a_1449(int a_F1,int a_F2); /* settagflag */
extern void a_simplehash(int a_F1,int a_F2,int a_A[1]);
static int a_1761=0; /* stdemptypointer */
static int a_1762=0; /* stdstrings */
static void a_1763(int a_F1,int a_A[2]); /* unpack2 */
static void a_1271(int a_F1); /* usetag */
static int a_1151(int a_F1,int a_F2); /* wastagpointer */
static void a_1764(void); /* @root */
#define a_1018 (a_1039+sizeof_LIST) /* INDICATOR */
static int a_1060(int a_F1); /* hasformaltype */
static int a_1152(int a_F1,int a_F2); /* wastypepointer */
static void a_1765(void); /* @root */
static void a_1579(int a_F1); /* constantdeclaration */
static void a_1766(int a_F2,int a_A[1]); /* declaration */
static void a_1767(int a_F1,int a_F2); /* declarationseries */
static void a_1768(int a_F1,int a_F2,int a_F3); /* declarer */
static void a_1769(int a_F1,int a_A[1]); /* expectconstanttag */
static void a_1770(int a_A[1]); /* expectexpression */
static void a_1771(int a_A[1]); /* expectlisttag */
static int a_1772(int a_A[1]); /* exprbase */
static void a_1773(int a_F1,int a_F2,int a_F3); /* externaldeclarer */
static int a_1774(int a_A[1]); /* isexpression */
static void a_1775(int a_F1,int a_F2,int a_F3); /* prototype */
static void a_1592(void); /* staticvariabledeclaration */
static void a_1776(int a_F1,int a_F2); /* tagredefined */
static void a_1594(int a_F1); /* variabledeclaration */
static void a_1777(void); /* @root */
#define BLOCK_TOTAL (a_1018+sizeof_LIST)
int a_DATABLOCK[BLOCK_TOTAL];
static int a_FILL[]={ /* fill table */
a_1001,/* @StringTable */
57,1634760805,1635148910,1735549298,115,13,6,1668571501,1919903336,1634492781,1635087459,108,17,7,1835627366,1634036848,2020173414,0,12,6,1953723757,1734440017,0,8,5,1953723757,1852793681,115,9,5,1953723757,81,5,4,1953719666,1684370031,1885565801,1953067887,7237481,19,7,1702257011,1668508004,1769172848,1852795252,0,16,7,1734440004,0,4,4,1886221359,1701601583,1949198448,28781,14,6,0,
a_1014,/* DSYMB */
159,1818361894,1,3,1701994791,10081,6,4,2020565543,39,5,4,93,1,3,1818321703,1701995113,39,9,5,41,1,3,58,1,3,44,1,3,126,1,3,1852793639,2585715,7,4,47,1,3,1684956455,39,5,4,1886938407,1936942450,661548905,0,12,6,1954047271,1769172581,2584175,11,5,1818846759,10085,6,4,1818846759,10092,6,4,1836411431,10096,6,4,1650551847,2583653,7,4,28252,2,3,1936288807,10100,6,4,1668246567,2583649,7,4,1651993639,39,5,4,1685024039,660958325,0,8,5,45,1,3,8227,2,3,1685024295,10085,6,4,40,1,3,124,1,3,62,1,3,43,1,3,46,1,3,1634889767,1952542055,39,9,5,1869574695,10100,6,4,1819636263,10085,6,4,59,1,3,42,1,3,91,1,3,1953068071,2581868,7,4,661615655,0,4,4,1651537191,39,5,4,2003596839,10082,6,4,1886746151,10082,6,4,94,1,3,0,
a_1023,/* MESSAGE */
15,1852727651,1663071343,1952540018,1702109285,1713401965,543517801,539783205,1869771365,1868767346,624780644,1629498468,1953656674,6778473,51,15,0,
a_1001,/* @StringTable */
41,774778459,93,5,4,1564437851,0,4,4,6111067,3,3,6111067,3,3,1564435291,0,4,4,2003136060,1701734764,62,9,5,1564435547,0,4,4,93,1,3,16219,2,3,1280659035,23884,6,4,1868854387,1694528629,6,4,0,
a_1023,/* MESSAGE */
43,544173940,2037277037,1920099616,745763439,1920296480,1919248500,1936026912,1701273971,1918967923,1970479205,1701998704,1684370291,0,48,15,1702129257,1818324594,1920099616,1763734127,1970413678,622880108,1814047856,543518313,1847944229,706748448,707406378,1701597216,543519585,1869636978,1948284018,1864394088,1852139110,1735289188,1869770784,1835102823,1684955424,1701344288,1920099616,539914863,707406378,7218474,103,28,0,
a_1001,/* @StringTable */
13,1851880052,1919905907,1936024692,116,13,6,1668571501,1919903336,1634492781,1635087459,108,17,7,0,
a_1023,/* MESSAGE */
32,1701606770,980428064,1919903264,543973741,544503151,1768318561,1881481336,1935767328,1953459744,1952805664,0,40,13,1701606770,980428064,544173600,1684956528,543649385,1701864818,1629516897,2020173414,29541,34,11,1700946284,1881481324,1852383290,1768843622,1814062452,7368559,23,8,0,
a_1023,/* MESSAGE */
56,1811950117,2,3,1702131813,1869181806,1881481326,8250,14,6,1701606770,980428064,32,9,5,1919115629,1881481327,8250,10,5,540700709,544501614,1768318308,6579566,15,6,623013157,1830822512,544502645,1629513058,1650553888,1864394092,1953702002,543908705,695215400,0,36,12,1869507877,1635021600,1918985326,1702043748,1952671084,1713402479,572551791,2256933,31,10,1702063397,1952671084,622883439,1869488240,1701060724,1701734758,100,25,9,0,
a_1023,/* MESSAGE */
144,1717660965,544762214,1701869940,1920099616,29295,18,7,623013157,1746936432,1998615393,1735290738,1887007776,1881481317,0,24,9,623013157,1965040240,1768843630,1818323316,1684372073,0,20,8,1633905957,1953459822,543515168,1868767329,1635021678,29806,22,8,1768713509,544500077,1752459639,1881481760,1633886242,1953459822,543515168,1684370293,0,32,11,623013157,1746936432,1763734369,1836016494,1769234800,543517794,1701869940,1814374432,41,33,11,1969515813,544828781,1768318561,1633886328,1953459822,543515168,1684370293,1919248416,101,33,11,623013157,1830822512,1700952417,1869772576,1763731310,2019910766,0,24,9,1717660965,544762214,577774882,1935763488,1818321696,1701995113,1718182944,1701995878,1713402990,544042866,25637,42,13,1953721637,1633971809,1931502706,1667591269,544370548,572548719,539127845,1679848297,1701209705,1953391986,0,40,13,1701606770,980428064,1701344288,1935764512,1667309684,1818326388,1717985568,1830844521,544502645,706766178,0,40,13,1701606770,980428064,1851876128,544501614,1768189805,1763735910,1717641326,544762214,1763733541,543236206,1919115629,1970413679,25964,50,15,1701606770,980428064,1851876128,544501614,1768189805,1763735910,1717641326,544762214,1763733541,1635131502,1650551154,1646290284,1801678700,0,52,16,0,
a_1023,/* MESSAGE */
91,1701606770,980428064,1885696544,544498021,1668246626,1769152619,1830839674,1634562921,543712116,694953256,0,40,13,1701606770,980428064,1885696544,544498021,1668246626,2037653611,1830839664,1634562921,543712116,544370534,1768318561,1881481336,1701978156,1919513969,540697701,539783205,1702259047,622869102,623386736,10604,78,22,1701606770,980428064,1830838560,1869767521,1819636256,1633886309,1953459822,1818321696,1953046636,1718379891,0,40,13,1634541665,544174691,1701606770,1851876128,544501614,1819042147,1881481760,34,29,10,577774882,544434464,539783205,544501614,1970413665,673211756,2714661,27,9,1701606770,980428064,1684300064,1869182057,543973742,1970561889,1629514849,2020173414,673215333,2714661,39,12,1701606770,980428064,1936289056,1735289203,1952669984,543973749,1768318561,544433528,694953256,0,36,12,0,
a_1023,/* MESSAGE */
50,1702131813,1869181806,1881481326,1970085946,1646294131,543236197,1667331187,623386731,10608,34,11,1702131813,1869181806,1881481326,1768300602,543452261,543434019,1768318308,543450478,1667856244,101,37,12,1702131813,1869181806,1881481326,1920409658,543649391,1818585446,1768693860,29811,30,10,1702131813,1869181806,1881481326,1768300602,543452261,1953720684,544434464,694428968,1869116192,1919251570,1634235424,1633886318,1919052140,623386725,10596,58,17,0,
a_1023,/* MESSAGE */
34,540700709,1696624494,1919251576,543973742,1936617315,1953390964,544370464,1953720684,544106784,1701736314,0,40,13,540700709,544432488,1852797559,2037653607,622880112,1852383344,1852799520,623386725,10604,34,11,1852727651,1914729583,1751343461,1768453152,1818304627,1852990836,1986622561,101,29,10,0,
a_1023,/* MESSAGE */
17,1852727651,1914729583,1751343461,1768453152,1701650547,1919246957,0,24,9,1852797559,1969889383,1948282989,1634476143,543974754,28709,22,8,0,
a_1023,/* MESSAGE */
16,1633906540,1717641324,544762214,540700709,544501614,1684370293,0,24,9,1700946284,1881481324,1869488186,1937055860,25701,18,7,0,
a_1023,/* MESSAGE */
188,1701606770,980428064,1953459744,1702065440,100,17,7,1701606770,980428064,1769497888,1970413684,1663067500,1914728033,1920300133,110,29,10,1701606770,980428064,1851876128,544501614,1667462515,6579557,23,8,1701606770,980428064,1851876128,1767990816,108,17,7,1701606770,980428064,1851876128,544501614,1818845542,0,20,8,1701606770,980428064,1935763488,1869375264,543973730,1701079411,1717986592,7627621,31,10,1701606770,980428064,1935763488,544173600,1651469415,1931504737,543515753,1701209701,29795,34,11,1701606770,980428064,1851876128,1986095136,1818697829,1818321519,1684632352,1717903461,1952671078,1701345056,1634082926,7564393,47,14,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1953459744,1702065440,100,33,11,1701606770,980428064,1953459744,1819042080,1885696544,544498021,1668246626,1830843243,1952999273,543515168,1769171318,6579572,47,14,1701606770,980428064,1919903264,543973741,1667331187,1717641323,544762214,1663070245,1646292577,543236197,1818386804,101,45,14,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1734962464,1663071336,1735287144,1852776549,1970435104,2019893349,29801,50,15,1701606770,980428064,1953853216,1919903264,543973741,1768318561,1881481336,1851876128,543515168,1852403317,1634301033,1702521196,100,49,15,1701606770,980428064,1953853216,1919903264,543973741,1768318561,1852383352,1885696544,544498021,1668246626,1853169771,1953066601,1768710505,6579578,55,16,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1701798944,1869488243,1751326836,1701277281,0,40,13,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1734962464,1663071336,1735287144,1852776549,1818322464,1696621939,7629176,51,15,0,
a_1023,/* MESSAGE */
118,1702131813,1818324594,544220448,1818453348,1952543329,980316009,1936289056,1735289203,1920234272,543649385,1702127201,1881481330,61,49,15,540700709,1701078386,1701734758,1935745124,544220448,1935767336,544220448,622883937,10604,34,11,540700709,1701078386,1701734758,1935745124,544220448,1935767336,695215392,0,28,10,1769498989,1679845230,1634493285,1769234802,1629515375,1881171054,1869901682,1701869940,544106784,1679847461,1634493285,1769234802,28271,50,15,1702131813,1818324594,544220448,1818453348,1952543329,980316009,1936289056,1735289203,1629502752,1919251558,7349536,43,13,1936943469,543649385,1752457584,544106784,1701603686,1667589152,1634885996,1852795252,0,32,11,1701603686,1701994784,544220448,1953723757,543515168,1814062703,544502633,1701869940,1881483296,41,37,12,1953720684,1734439968,544434464,1701869669,1684370531,544106784,1701603686,1701994784,97,33,11,544173940,2037277037,1952539680,1818846817,1918967909,673210725,544760173,2712613,31,10,1679847461,1634493285,1769234802,540700271,543646068,1701869669,1684370531,0,28,10,0,
a_1001,/* @StringTable */
22,1768318308,1667851630,1734440037,0,12,6,1920234327,6778473,7,4,1734440023,0,4,4,87,1,3,1885695073,1667837544,101,9,5,0,
a_1023,/* MESSAGE */
135,540700709,544501614,1768318308,6579566,15,6,622882853,1847605872,1679848559,1852401253,25701,18,7,622882853,1931491952,1819635560,1700929636,7349536,19,7,622882853,1931491952,1819635560,1700929636,1936288800,116,21,8,622882853,1847605872,1965061231,6579571,15,6,622882853,1847605872,1965061231,744777075,1851876128,544501614,1702257000,1818846752,1735289196,0,36,12,622882853,1663056496,1869508193,1700929652,1954047264,1634628197,623386732,10604,30,10,1819044198,543649385,540700709,1701080693,1701734758,1702043748,1952671084,622883439,112,33,11,1819044198,543649385,540700709,1818585446,1881481316,1886741536,1633905004,6579572,31,10,1819044198,543649385,540700709,544501614,1936617315,1953850213,543520361,1668246626,107,33,11,1819044198,543649385,540700709,1668246626,1769152619,622880122,1936269412,1734959648,544367975,1851877492,1818321696,1701995113,1680156704,41,53,16,1819044198,543649385,540700709,1668246626,1769152619,622880122,1936269412,1634562848,1919249516,1634235424,1633886318,1919052140,623386725,10596,54,16,1852727651,1864397935,544105840,543515497,1701603686,745547040,1920099616,1663070831,979723375,744760608,1868718368,1852404850,103,49,15,0,
a_1001,/* @StringTable */
34,1702243629,1869181810,110,9,5,1701326125,28780,6,4,18733,2,3,28461,2,3,1818318637,108,5,4,22317,2,3,27693,2,3,25645,2,3,19757,2,3,1761627181,2,3,0,
a_1023,/* MESSAGE */
63,1936943469,543649385,1969713761,1953391981,1919903264,1684890400,1701734764,1953525536,7237481,35,11,1920298867,1713399139,543517801,577774882,544434464,1663069801,1634561391,1814062190,744844905,1852270880,1684370031,0,44,14,1920298867,1713399139,543517801,577774882,1668180256,1701082476,1701982052,1919513969,1679844453,1701209705,1953391986,31084,46,14,1763733358,1953853550,1818846752,1886593125,1718182757,744777065,1702065440,1747791136,544238693,544370534,1752375393,544502383,1886152040,0,52,16,1869771365,1886330994,1852403301,1768300647,572548460,2256933,23,8,0,
a_1001,/* @StringTable */
10,1634038371,1667851636,1835101797,101,13,6,1768191091,1701576814,5,4,0,
a_1021,/* LEXT */
3,0,0,3,0,
a_1011,/* CONST */
2,0,1,0,
a_1371,/* SPECIAL */
166,1836409916,4094317,7,4,1684956455,39,5,4,1952669991,661548905,0,8,5,1853187623,1869182051,10094,10,5,1701998631,1633904996,2581876,11,5,1702195495,1869182067,10094,10,5,1769497895,10100,6,4,1869574695,10100,6,4,1954047271,1634628197,10092,10,5,1635021607,660826484,0,8,5,1634231079,1818846834,10085,10,5,1952539687,1818846817,10085,10,5,1852793639,1851880563,10100,10,5,1918989863,1818386793,10085,10,5,1650553895,2581868,7,4,1635021607,2583395,7,4,1634889767,1952542055,39,9,5,15917,2,3,61,1,3,60,1,3,62,1,3,15420,2,3,15934,2,3,91,1,3,93,1,3,15932,2,3,42,1,3,40,1,3,41,1,3,58,1,3,44,1,3,59,1,3,46,1,3,45,1,3,43,1,3,35,1,3,63,1,3,15649,2,3,47,1,3,15678,2,3,15676,2,3,126,1,3,124,1,3,38,1,3,94,1,3,28252,2,3,0,
a_1023,/* MESSAGE */
63,544173940,1735549292,1970151525,1919246957,0,16,7,544761192,1768384868,2019893364,1952671088,1629512805,1919251558,7876640,27,9,1852797559,1751326823,1667330657,544367988,1869505892,1769234804,28271,26,9,1702129269,1852403058,1684370529,1920234272,6778473,19,7,1852534389,544110447,544826731,1685221239,1881483040,39,21,8,1852797559,1969365095,762604649,622882409,112,17,7,1936943469,543649385,1717641255,544367988,661660967,0,20,8,1701604457,543973735,1918986339,1702126433,622869106,99,21,8,0,
a_1366,/* BOLD */
248,1818361953,1,3,0,0,1454738860,7627617,3,3,1454738599,1454738612,1454738860,1769235297,28271,6,4,0,0,1454738860,1918986339,1701603686,0,8,5,1454738605,1454738635,1454738898,1936617315,0,4,4,0,0,1454738908,1936617315,1953390964,0,8,5,1454738627,1454738641,1454738908,7631715,3,3,0,0,1454738908,1635017060,1701603686,0,8,5,1454738620,1454738676,1454738903,101,1,3,0,0,1454738879,6581861,3,3,1454738655,1454738668,1454738855,1953069157,0,4,4,0,0,1454738879,1702131813,1818324594,0,8,5,1454738661,1454738688,1454738888,102,1,3,0,0,1454738865,7627622,3,3,1454738682,1454738695,1454738865,1668183398,0,4,4,0,0,1454738865,1668183398,1852795252,0,8,5,1454738649,1454738757,1454738865,112,1,3,0,0,1454738870,1734439536,7627117,7,4,1454738709,1454738723,1454738926,1684370032,0,4,4,0,0,1454738870,1684370032,1952539497,101,9,5,1454738716,1454738743,1454738870,113,1,3,0,0,1454738875,30065,2,3,1454738737,1454738749,1454738875,6649201,3,3,0,0,1454738875,1936029041,1852795252,0,8,5,1454738731,1454738785,1454738875,1953460082,0,4,4,0,0,1454738883,1667331187,107,5,4,1454738764,1454738778,1454738921,1952543859,25449,6,4,0,0,1454738893,1818386804,101,5,4,1454738771,1454738799,1454738917,7496054,3,3,0,0,1454738913,1769103734,1701601889,0,8,5,1454738791,1454738805,1454738913,120,1,3,0,0,1454738888,1818846815,24421,6,4,0,0,1,1852402783,24421,6,4,1454738812,0,2,1819636319,24421,6,4,1454738819,1454738834,3,1970238303,1600480114,0,8,5,0,1454738841,4,1953068127,6251884,7,4,0,0,5,0,
a_1001,/* @StringTable */
6,1701602675,1919906915,1953720684,0,12,6,0,
a_1023,/* MESSAGE */
220,1701602675,1919906915,1853453088,7889268,15,6,1701602675,1919906915,1886938400,1702126437,100,17,7,1953720684,1734439968,544434464,1936943469,543649385,1702127201,1931944050,1801675124,1919885351,1635002144,660958306,0,44,14,622882853,1931491952,1667591269,544370548,1679847461,1701209705,1953391986,1814374432,41,33,11,622882853,1931491952,1684955508,543453793,1701602675,1919906915,544220448,1717987684,1852142181,623386740,10604,42,13,622882853,1663056496,1651076193,1830839666,544502645,622880098,623386724,2107756,31,10,1701864818,1663071329,1953721967,544501345,1701869669,1684370531,0,24,9,1701864818,1663071329,1953721967,544501345,1864393765,1864397941,1634869350,543516526,773861672,1680154670,41,41,13,1713401893,1768713321,540698478,2037149295,1701736224,1763715616,1752440942,1818370149,7037807,35,11,1713401893,1768713321,540698478,1701602675,1919906915,1886938400,1702126437,100,29,10,622882853,1663056496,1869508193,1634214004,1713399158,1768713321,26478,26,9,622882853,1768300656,1852402796,1931491943,1635020409,1919230072,7499634,27,9,1713401893,1768713321,540698478,1936943469,543649385,543646068,1702127201,3809394,31,10,1713401893,1768713321,540698478,1668246626,2019893355,1952671088,25701,26,9,622882853,1914714736,1717920869,1684369001,544432416,673214501,2714661,27,9,622882853,1914714736,1717920869,1684369001,544432416,28709,22,8,1702131813,1818324594,980428064,1936289056,1735289203,1920234272,543649385,1702127201,4006002,35,11,1931505518,543521385,1769239397,1869898093,1852383346,1954047264,1634628197,1701060716,1918987363,1869182049,110,41,13,1953397107,1696626785,1919906418,544106784,1702521203,1953719584,1952542057,29295,30,10,1769498989,1679845230,1634493285,1769234802,1629515375,1881171054,1869901682,1701869940,544106784,1679847461,1634493285,1769234802,28271,50,15,1702521203,1953719584,1952542057,572551791,539124773,544503151,1629513327,2003790956,1914725477,1701277281,0,40,13,0,
a_1023,/* MESSAGE */
12,1701606770,980428064,1651406112,1684960623,1830839397,1869767521,1651864352,1953068147,1869182069,110,37,12,0,
a_1001,/* @StringTable */
50,1952542071,1868982371,1818324338,1970561889,27745,18,7,1886220131,1147499637,1634494037,29543,14,6,1852401228,1650551908,7564389,11,5,1919841612,7105647,7,4,1986097780,1702064741,1162630482,0,12,6,1953259861,1634628197,1702259060,0,12,6,1952670037,1919705461,6646901,11,5,1734701653,7237481,7,4,1952542055,1868982371,1818324338,1970561889,27745,18,7,0,
a_1023,/* MESSAGE */
54,1701606770,980428064,1818326560,1864394101,1869357158,543973731,1768318561,1881481336,1953459744,1702065440,100,41,13,1701606770,980428064,1717985568,622884969,1702043760,1969365108,1869488244,1937055860,25701,34,11,1701606770,980428064,1769107232,1634625895,1635131500,543520108,1713399407,1634562671,1717641324,544762214,1847619621,1965061231,6579571,51,15,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1701798944,1869488243,1751326836,1701277281,1633886252,1700929646,7235872,51,15,0,
a_1023,/* MESSAGE */
44,1886611821,1701011820,2037588068,1819239021,7349536,19,7,1954047271,1634628197,1663051628,1646292577,1937055845,1763730533,1768693870,1918988898,1869422713,1864394084,7957614,43,13,1701998445,1634235424,1852776558,1915166821,661942127,0,20,8,656437102,1953460082,39,9,5,622882853,1814051440,1634886249,1763735922,544040308,1701078386,1701734758,623386724,10604,34,11,0,
a_1001,/* @StringTable */
14,1634038372,1634889828,1952542055,0,12,6,1936941424,4802889,7,4,1936941424,18761,6,4,0,
a_1023,/* MESSAGE */
47,540700709,544501614,1768318308,6579566,15,6,622882853,1663056496,1869508193,1700929652,1651863584,543385964,694953256,0,28,10,622882853,1663056496,1869508193,1700929652,1830838560,1869767521,1814374432,41,29,10,1702131813,1818324594,1819636256,8293,14,6,1869639017,1684370546,1819636256,8293,14,6,1734439536,544498029,1919115629,1881488751,1734942778,1701998446,100,25,9,0,
a_1001,/* @StringTable */
12,1886676339,1835491698,1635152993,6649196,15,6,1886676327,1835491698,1635152993,6649196,15,6,0,
a_1021,/* LEXT */
4,1885695073,104,5,4,0,
a_1039,/* TTAG */
281,1660972655,2,3,0,0,0,0,0,6710895,3,3,0,0,0,0,0,28526,2,3,0,0,0,0,0,1701736302,0,4,4,0,0,0,0,0,1819568500,101,5,4,0,0,0,0,0,1953720684,0,4,4,0,0,0,0,0,2002936180,1752458345,0,8,5,0,0,0,0,0,1751607666,1918987636,7235943,11,5,0,0,0,0,0,1852989815,1818717801,1818588773,0,12,6,0,0,0,0,0,1952672100,1634627433,31090,10,5,0,0,0,0,0,1818522739,25193,6,4,0,0,0,0,0,1886220131,6646889,7,4,0,0,0,0,0,1919052140,7959137,7,4,0,0,0,0,0,1970365810,6648425,7,4,0,0,0,0,0,1818455657,6644853,7,4,0,0,0,0,0,1969516397,25964,6,4,0,0,0,0,0,1919115629,111,5,4,0,0,0,0,0,1768713833,25966,6,4,0,0,0,0,0,1818391920,25449,6,4,0,0,0,0,0,1953460848,1887007855,101,9,5,0,0,0,0,0,1869639017,29810,6,4,0,0,0,0,0,1869641829,29810,6,4,0,0,0,0,0,1667330676,101,5,4,0,0,0,0,0,1853189986,29540,6,4,0,0,0,0,0,1853189987,116,5,4,0,0,0,0,0,26217,2,3,0,0,0,0,0,1869506153,116,5,4,0,0,0,0,0,1701078633,102,5,4,0,0,0,0,0,1684956777,26213,6,4,0,0,0,0,0,1702063205,0,4,4,0,0,0,0,0,1768189541,102,5,4,0,0,0,0,0,0,
a_1023,/* MESSAGE */
76,1852797559,1919950951,1634559841,2037588084,2019652718,0,20,8,1852534389,544110447,1734439536,544498029,28709,18,7,1734439536,544498029,540700709,1852797559,1635131495,543520108,28709,26,9,1734439536,544498029,540700709,544503151,1914725999,1701277281,1818326560,622880117,100,33,11,1734439536,544498029,1768189541,1881488742,1936289056,1735289203,0,24,9,1734439536,544498029,624783397,1634214000,1869488243,1952541984,1852401763,1634738279,29810,34,11,1734439536,544498029,1746956325,1847620449,1717903471,1952671078,1868769312,1818849389,1718566245,10598,38,12,1734439536,544498029,1919115629,1881488751,544434464,1869506409,6579570,27,9,0,
a_1023,/* MESSAGE */
147,1651341683,622881903,1936269424,1886938400,1702126437,1701322852,25970,26,9,1651341683,622881903,1936269424,1886938400,1702126437,1717641316,544367988,28709,30,10,543646068,1701869669,1684370531,1952866592,622883429,112,21,8,543646068,1701869669,1684370531,0,12,6,1920298867,1864394083,1635000434,2019893351,1952671088,25701,22,8,1696624233,1852142712,1852795251,1818587936,1869898597,2019893362,1952671088,25701,30,10,1702127201,2019893362,1936614772,544108393,543646068,1701869669,1684370531,0,28,10,1852797559,1717641319,544762214,1836216166,0,16,7,1701606770,980428064,1802401056,1853321070,1650551840,622881893,112,25,9,1920298867,1696621923,1667592312,543450484,1702127201,1881481330,0,24,9,1836216166,1931504737,1667591269,544370548,1847619621,1679848559,1852401253,25701,30,10,1701606770,980428064,1835363616,544367970,1701869669,1684370531,0,24,9,1836216166,1629514849,2020173414,544220448,1629516641,1667309678,1818588532,1819636256,101,33,11,1701606770,980428064,544173600,1836216166,1914727521,1634037861,1717641332,7891302,31,10,1701606770,980428064,1852799520,2037588069,2019652718,1633888288,1953459822,543515168,1953525093,10617,38,12,1935764579,1768319347,1769234787,1746955887,1847620449,1633886319,7562611,27,9,0,
a_1001,/* @StringTable */
4,1953723757,6775156,7,4,0,
a_1023,/* MESSAGE */
27,1836216166,1931504737,1667591269,544370548,1953397107,30817,22,8,1836216166,1931504737,1667591269,544370548,543646068,1701869669,1684370531,0,28,10,1836216166,1814064225,544502633,543646068,1830843241,1769173865,26478,26,9,0,
a_1023,/* MESSAGE */
140,1701606770,980428064,1836675872,543977314,1763733541,2019893363,1952671088,1746953317,6648421,35,11,1701606770,980428064,1819636256,1935745125,1919903264,543973741,1768318561,120,29,10,1701606770,980428064,1919903264,543973741,1768318561,2037588088,2019652718,0,28,10,1701606770,980428064,1920099616,1763734127,1970413678,1746953580,6578533,27,9,1701606770,1734439968,1886938400,1702126437,100,17,7,1701606770,980428064,1684369952,1852401253,1679844453,1701209705,1953391986,1952522361,7087392,35,11,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1935763488,1869772576,1948280686,543518841,1935767336,544220448,622883937,10604,54,16,1701606770,980428064,1919903264,543973741,1953720684,1717985568,622884969,1634214000,1768169587,1919247974,544501349,1768710499,543519330,544497960,2714661,59,17,1701606770,980428064,1919903264,543973741,1953720684,1717985568,622884969,1634214000,1768169587,1919247974,544501349,1851880563,1685217636,1818587936,1869898597,1630019698,1814372468,41,69,20,1701606770,980428064,1919903264,543973741,1953720684,1717985568,622884969,1702043760,1952671084,622883439,1868832880,2037146229,1717920800,1684369001,0,56,17,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1717920800,1684369001,1769436192,25955,38,12,0,
a_1023,/* MESSAGE */
90,543646068,1914728485,1717920869,1684369001,1635199008,1881481331,544497952,2714661,31,10,1701606770,980428064,1954047264,1713398130,1634562671,1717641324,544762214,694953256,0,32,11,1701606770,980428064,1936289056,1735289203,1919903264,543973741,1768318561,544433528,694953256,0,36,12,1701606770,980428064,1919905056,1752440933,1864396385,1914725742,1634037861,1717641332,7891302,35,11,1701606770,980428064,1885696544,544498021,1768318561,539631736,1948283753,1814062440,544502625,6647407,39,12,1701606770,980428064,1853187616,1869182051,1769414766,1970235508,1970217076,1717641332,1702390118,115,37,12,1701606770,980428064,1769497888,1970413684,1998611820,543716457,544503151,1768318561,7562616,35,11,1702131813,1818324594,1819636256,1881481317,1768759354,1852404595,1953701991,1735289202,0,32,11,0,
a_1001,/* @StringTable */
22,1684104562,1836020326,1953719666,6648431,15,6,1702257011,1701998452,1919906931,101,13,6,1701536109,1953719666,6648431,11,5,1953066601,1953719666,6648431,11,5,0,
a_1724,/* RESTORE */
1,0,-500,
0,
a_1023,/* MESSAGE */
34,1651341683,622881903,1936269424,1936615712,1702130277,100,21,8,1735357040,544039282,1954047348,1768649504,1684369520,1953396000,1948281961,1847616872,544503909,1852403568,116,41,13,1096040774,1830828620,1835628641,1914727521,1869902693,1931502962,543521385,1701017701,1684366437,1680156704,41,41,13,0,
a_1001,/* @StringTable */
13,1918985587,1634560099,1919906403,6646901,15,6,1702129253,1701998706,1768318308,1952736622,26465,18,7,0,
a_1023,/* MESSAGE */
74,540700709,1651863396,1679849836,1852401253,1763730533,1752440942,1919950949,1651335525,673211756,1635017062,10604,42,13,540700709,544432503,1768318308,543450478,622883937,108,21,8,540700709,1696625513,1919251576,543973742,694953256,1633886252,1953459822,543515168,1701078386,1701734758,100,41,13,540700709,1696625513,1919251576,543973742,694953256,1633886252,1953459822,543515168,1818391920,25449,38,12,540700709,1852727651,1646294127,1970282597,1667853410,0,20,8,540700709,1881174889,1768710773,623386723,539765100,1852727651,1646294127,2019893349,1852990836,27745,38,12,540700709,1852727651,1646294127,1701978213,1768318308,6579566,23,8,0,
a_1039,/* TTAG */
186,0,0,3,0,0,0,0,0,1718184051,1717985652,1818392681,7037807,15,6,0,0,0,0,0,1635018087,2020173414,1668246626,7302763,15,6,0,0,0,0,0,1869574720,116,5,4,0,0,0,0,0,1953069157,0,4,4,0,0,0,0,0,1920226112,1416064617,1701601889,0,12,6,0,0,0,0,0,1801547072,101,5,4,0,0,0,0,0,1701997888,113,5,4,0,0,0,0,0,1970365760,27745,6,4,0,0,0,0,0,1953459776,29029,6,4,0,0,0,0,0,1919905088,101,5,4,0,0,0,0,0,1936026688,115,5,4,0,0,0,0,0,1702063168,113,5,4,0,0,0,0,0,42,1,3,0,0,0,0,0,15917,2,3,0,0,0,0,0,15678,2,3,0,0,0,0,0,61,1,3,0,0,0,0,0,15649,2,3,0,0,0,0,0,62,1,3,0,0,0,0,0,60,1,3,0,0,0,0,0,15676,2,3,0,0,0,0,0,0,
a_1020,/* LADM */
42,-2,0,16777520,0,0,963128101,-2,32,16777520,0,0,963128030,-2,32,16777520,0,0,963128010,-2,32,16777520,0,0,963127990,-2,32,16777520,0,0,963128001,-2,0,16777520,0,0,963128109,-2,0,16777520,0,0,963128019,0,
a_1018,/* INDICATOR */
139,1701080693,1701734758,100,9,5,1936617315,1953390964,0,8,5,1936617315,1953390964,0,8,5,1769103734,1701601889,0,8,5,1952543859,1981834089,29281,10,5,1818386804,101,5,4,1667331187,107,5,4,1952543859,1931502441,1801675124,0,12,6,1701602675,1919906915,0,8,5,1852403568,544367988,1936617315,1953390964,0,16,7,1918986339,1701603686,0,8,5,1635017060,1701603686,0,8,5,1701606770,0,4,4,1836216166,27745,6,4,1836216166,1931504737,1667591269,7499636,15,6,1836216166,1931504737,1801675124,0,12,6,1836216166,1948281953,1701601889,0,12,6,1836216166,1713400929,6646889,11,5,1836216166,1763732577,110,9,5,1836216166,1864395873,29813,10,5,1836216166,1763732577,1953853294,0,12,6,1836216166,1914727521,1634037861,116,13,6,1836216166,1931504737,1952868712,0,12,6,1919115629,1634738287,1701667186,7497076,15,6,1629515630,1836410738,7630437,11,5,1633906540,108,5,4,1700946284,108,5,4,0,
a_1023,/* MESSAGE */
142,1852797559,2019893351,1936028272,1852795251,1853453088,7889268,23,8,1696624233,1701998712,1869181811,543236206,543646068,1696625513,1667592312,6579572,31,10,1852797559,1919885415,1936289056,1735289203,1886938400,1936942450,7237481,27,9,543646068,1701869669,1684370531,1919903264,1881483040,39,21,8,543646068,1830842405,544502645,1948280162,1701601889,544370464,1667331187,623386731,10608,34,11,543646068,1830842405,544502645,1629513058,1852793632,1851880563,623386740,10608,30,10,540700709,1696624494,1919251576,543973742,543646068,1696624233,1701998712,1869181811,110,33,11,1702131813,1818324594,544220448,1818453348,1952543329,980316009,1936289056,1735289203,1629502752,1919251558,7349536,43,13,1702131813,1818324594,544220448,1818453348,1952543329,980316009,1936289056,1735289203,1920234272,543649385,1702127201,1881481330,61,49,15,1769498989,1679845230,1634493285,1769234802,1629515375,1881171054,1869901682,1701869940,544106784,1679847461,1634493285,1769234802,28271,50,15,540700709,1701078386,1701734758,1935745124,544220448,1935767336,544220448,622883937,10604,34,11,540700709,1701078386,1701734758,1935745124,544220448,1935767336,695215392,0,28,10,2037149295,1919514144,1818326388,1970233888,544433262,1696624233,1701998712,1869181811,29550,34,11,0,
a_1021,/* LEXT */
10,1886221359,1701601583,1949198448,28781,14,6,1651076193,0,4,4,0,
a_1023,/* MESSAGE */
226,1734439765,1629502053,1886220131,757947168,1886152040,757955616,1936876918,1567518569,538996261,980578080,1868783904,1528852589,1769238639,1567845999,1818846752,774774885,1868242990,1869182064,542995310,1701603686,1918135845,1819504225,543519841,543516788,1668181859,1852142689,1869182049,1718558830,1162625312,1294813264,1970238240,543515506,1701603686,1869881459,1667837472,1847930469,1651469383,1864395873,1869182064,673215342,1819305330,543515489,1986359920,1937076073,1835627296,1918987369,1953525536,695103337,544089402,544156960,1818846780,538984037,538976288,1970216992,1953853556,1667837472,1768300645,1847944556,1227694112,1768176672,1768176242,538984050,1663049760,1852796015,1701868320,1952543329,1814062181,544502633,1931503215,1668440421,1768169576,1952671090,1701409391,1282286963,1818321775,1953525536,1936617321,1701980192,544499059,1702127201,1634017394,1931503715,1668445551,1768300645,975791468,538996261,538990381,538976288,538976288,538976288,1918990112,1735289198,1986358304,859663461,538996261,1818318637,538976364,538976288,538976288,1918990112,1735289198,1986358304,809331813,538996261,538995757,538976288,538976288,538976288,1936288800,1852783988,538996261,538993709,538976288,538976288,538976288,1667851296,1852795252,1031369313,1847946863,757932064,1482184792,1499020632,538976345,1881153568,1702064737,1935745124,1919952672,1634559841,1482172276,1029199960,777607513,1716088357,544173600,1886680431,1763734645,1886593139,1718182757,744777065,1701344288,1835101728,1718558821,1701344288,1667837472,1768300645,1763730796,1701060723,1702259058,1919295588,1847946607,543516788,1936877926,1869815924,1701016181,1818846752,1629498469,1730176110,1919250021,1684370529,544106784,543516788,1920103779,544501349,1701996900,1919906915,11897,658,167,1346718785,541928776,1226862452,1663059267,1819307375,544367977,1936876918,544108393,623797285,1131292004,1920561263,1952999273,692267040,842019360,1632378928,1869380211,1769161504,2053205362,1750363685,1763734377,543236211,1701147238,1718580000,1918990196,1931488357,1948280165,1931502952,1668445551,1868963941,1868767346,1769109872,544499815,1868983913,1952542066,778989417,1701336096,1763730802,1315841395,1096228943,1312903762,540760404,544501614,1852143205,1919249696,1851877475,1768057204,2037672300,544370464,1853122918,544437093,544370534,1634738273,1667855474,1918987381,1920299040,1702063984,46,225,59,0,
-1}; /* fill table size 4100 */
static void a_data_setup(void){
 a_virtual_min=16777216;a_virtual_max=2130706432;
 a_setup_list(0,a_1001,1,16777217,16777514,298); /* @StringTable */
 a_setup_list(1,a_1006,1,2118415633,2130705892,0); /* BUFFER */
 a_setup_list(1,a_1007,2,2106125372,2118415630,0); /* RULE */
 a_setup_list(0,a_1014,1,2106125211,2106125369,159); /* DSYMB */
 a_setup_list(1,a_1026,1,2093834950,2106125209,0); /* QBUFFER */
 a_setup_list(0,a_1023,1,2093832551,2093834948,2398); /* MESSAGE */
 a_setup_list(1,a_1019,6,1848027350,2093832544,0); /* ITEM */
 a_setup_list(1,a_1024,5,1725124744,1848027339,0); /* NODE */
 a_setup_list(1,a_1339,3,1712834479,1725124736,0); /* INPUT */
 a_setup_stdarg(a_1340,1);
 a_setup_list(0,a_1366,3,1454738599,1454738844,248); /* BOLD */
 a_setup_list(1,a_1011,1,1454739015,1516190314,2); /* CONST */
 a_setup_list(1,a_1021,1,1516190316,1712834475,17); /* LEXT */
 a_setup_list(0,a_1371,1,1454738848,1454739013,166); /* SPECIAL */
 a_setup_list(1,a_1724,1,1454738096,1454738595,500); /* RESTORE */
 a_setup_list(1,a_1740,1,16777656,446936755,0); /* DICT */
 a_setup_list(1,a_1020,6,483807550,963127684,42); /* LADM */
 a_setup_list(1,a_1022,6,459227024,483807538,0); /* LLOC */
 a_setup_list(1,a_1742,2,446936758,459227016,0); /* RETAG */
 a_setup_list(1,a_1039,5,963127695,1454738090,467); /* TTAG */
 a_setup_list(0,a_1018,1,16777516,16777654,139); /* INDICATOR */
 a_setup_dfile(a_1013,2,a_1001,16777273,4); /* DISC */
   a_add_filearea(a_1013,a_1014,-119605731);
   a_add_filearea(a_1013,a_1020,884185802);
   a_add_filearea(a_1013,a_1022,867655975);
   a_add_filearea(a_1013,a_1021,-2000851308);
 a_setup_charfile(a_1102,2,a_1001,16777314); /* PRINTFILE */
 a_setup_charfile(a_1273,2,a_1001,16777349); /* ICE */
 a_setup_charfile(a_1370,2,a_1001,16777393); /* SOURCE */
 a_list_fill(a_FILL);
}
a_MROOT(a_1005,"buffer")
a_MROOT(a_1010,"disc")
a_MROOT(a_1097,"display")
a_MROOT(a_1154,"drules")
a_MROOT(a_1244,"files")
a_MROOT(a_1272,"ice")
a_MROOT(a_1338,"input")
a_MROOT(a_1365,"lexical")
a_MROOT(a_1420,"lists")
a_MROOT(a_1465,"macros")
a_MROOT(a_1476,"node")
a_MROOT(a_1578,"passi")
a_MROOT(a_1595,"passii")
a_MROOT(a_1601,"pragmats")
a_MROOT(a_1646,"rulebody")
a_MROOT(a_1686,"rules")
a_MROOT(a_1723,"symbols")
a_MROOT(a_1739,"tags")
a_MROOT(a_1764,"types")
a_MROOT(a_1765,"variables")
a_MROOT(a_1777,"version")
void a_ROOT(void){
 a_data_setup();
 a_Ra_1005(0,0); /* buffer */
 a_Ra_1010(0,0); /* disc */
 a_Ra_1097(0,0); /* display */
 a_Ra_1154(0,0); /* drules */
 a_Ra_1244(0,0); /* files */
 a_Ra_1272(0,0); /* ice */
 a_Ra_1338(0,0); /* input */
 a_Ra_1365(0,0); /* lexical */
 a_Ra_1420(0,0); /* lists */
 a_Ra_1465(0,0); /* macros */
 a_Ra_1476(0,0); /* node */
 a_Ra_1578(0,0); /* passi */
 a_Ra_1595(0,0); /* passii */
 a_Ra_1601(0,0); /* pragmats */
 a_Ra_1646(0,0); /* rulebody */
 a_Ra_1686(0,0); /* rules */
 a_Ra_1723(0,0); /* symbols */
 a_Ra_1739(0,0); /* tags */
 a_Ra_1764(0,0); /* types */
 a_Ra_1765(0,0); /* variables */
 a_Ra_1777(0,0); /* version */
 a_1456(); /* compiler */
}
static void a_1005(void){ /* @root */

} /* @root */
static void a_1078(int a_F1){ /* opendisc+>a */
int a_L2;int a_P[3];
if(!a_openfile(a_1013,a_F1,a_1021,1516190328)){ goto a_G6;}
if(!__equal(a_F1,114)){return;}
a_1028=0;a_1033=0;
a_1066=0;
a_1076();return;
a_G6:__getfileerror(a_1013,a_L2);
a_P[0]=2093832565;a_P[1]=1516190328;a_P[2]=a_L2;a_1040(0,3,a_P);return;
} /* opendisc */
static void a_1043(void){ /* closedisc */

a_closefile(a_1013);return;
} /* closedisc */
static void a_1046(void){ /* deletedisc */

a_1043();
a_unlinkfile(a_1021,1516190328);return;
} /* deletedisc */
static void a_1085(void){ /* rewinddisc */

a_1028=0;a_1033=0;
a_1084(0,0);return;
} /* rewinddisc */
static void a_1012(int a_F1){ /* D+>a */

a_putdata(a_1013,a_F1,1);return;
} /* D */
static void a_1015(int a_F1){ /* Dcons+>a */

a_putdata(a_1013,a_F1,0);return;
} /* Dcons */
static void a_1016(int a_F1){ /* Dstring+>a */

a_putdata(a_1013,a_F1,1);return;
} /* Dstring */
static void a_1017(int a_F1){ /* Dtag+>a */

a_G1:if(!__was(a_1020,a_F1)){ goto a_G5;}
if(!a_1060(a_F1)){ goto a_G4;}
a_F1=to_LIST(a_1020)->offset[a_F1-2]; goto a_G1;
a_G4:a_1012(a_F1);return;
a_G5:if(__was(a_1022,a_F1)){ goto a_G4;}
a_1063(a_1001,16777267,112);return;
} /* Dtag */
static void a_1082(void){ /* readfromQBUFFER */

__incr(a_1028);
a_1036=to_LIST(a_1026)->offset[a_1028];
if(!__equal(a_1036,2106125252)){ goto a_G7;}
a_1028=0;
a_1031=0;
a_1076();return;
a_G7:if(!__equal(a_1036,2106125245)){ goto a_G11;}
a_1038=0;
__incr(a_1028);
a_1036=to_LIST(a_1026)->offset[a_1028];return;
a_G11:a_1038=1;return;
} /* readfromQBUFFER */
static void a_1089(void){ /* substitute */

if(!__was(a_1022,a_1036)){return;}
__add(a_1036,a_1033,a_1036);
if(__noteq(to_LIST(a_1022)->offset[a_1036-2],16777641)){return;}
a_1031=a_1036;
a_1028=to_LIST(a_1022)->offset[a_1036-1];
a_1082();return;
} /* substitute */
static void a_1076(void){ /* nextdiscsymbol */
int a_P[2];
if(!__is(a_1028)){ goto a_G4;}
a_1031=0;
a_1082();return;
a_G4:a_1088(a_1066);
a_G5:a_getfilepos(a_1013,a_P);a_1032=a_P[0];
a_1030=a_1066;
if(!a_getdata(a_1013,a_P)){ goto a_G14;}a_1036=a_P[0];a_1038=a_P[1];
if(!__equal(a_1036,2106125282)){ goto a_G11;}
if(!__equal(a_1038,1)){ goto a_G11;}
__incr(a_1066); goto a_G5;
a_G11:if(!__is(a_1033)){return;}
if(!__equal(a_1038,1)){return;}
a_1089();return;
a_G14:a_1036=2106125252;
a_1038=1;return;
} /* nextdiscsymbol */
static void a_1086(int a_A[2]){ /* savediscposition+a>+a> */

if(!__is(a_1028)){ goto a_G3;}
a_1063(a_1001,16777263,168);return;
a_G3:a_A[0]=a_1032;
a_A[1]=a_1030;return;
} /* savediscposition */
static void a_1084(int a_F1,int a_F2){ /* restorediscposition+>a+>a */

if(!__is(a_1028)){ goto a_G3;}
a_1063(a_1001,16777256,171);return;
a_G3:a_setfilepos(a_1013,a_F1);
a_1066=a_F2;
a_1076();return;
} /* restorediscposition */
static int a_1025(int a_F1){ /* Q+>a */

if(!__equal(a_F1,a_1036)){ return 0;}
if(!__is(a_1038)){ return 0;}
a_1076(); return 1;
} /* Q */
static int a_1027(int a_F1){ /* Qahead+>a */

if(!__equal(a_F1,a_1036)){ return 0;}
if(!__is(a_1038)){ return 0;} return 1;
} /* Qahead */
static void a_1071(int a_F1){ /* mustQ+>a */

if(a_1025(a_F1)){return;}
a_1063(a_1001,16777249,176);return;
} /* mustQ */
static int a_1029(int a_A[1]){ /* Qcons+a> */

if(!__equal(a_1038,0)){ return 0;}
a_A[0]=a_1036;
a_1076(); return 1;
} /* Qcons */
static void a_1072(int a_A[1]){ /* mustQcons+a> */

if(!__is(a_1038)){ goto a_G3;}
a_1063(a_1001,16777245,178);return;
a_G3:a_A[0]=a_1036;
a_1076();return;
} /* mustQcons */
static int a_1037(int a_A[1]){ /* Qtag+a> */

if(!__is(a_1038)){ return 0;}
{ if(!((483807545<=a_1036 && a_1036<=963127684)||(459227019<=a_1036 && a_1036<=483807538))){ return 0;}
}
a_A[0]=a_1036;
a_1076(); return 1;
} /* Qtag */
static int a_1035(int a_A[1]){ /* Qstring+a> */

if(!__is(a_1038)){ return 0;}
if(!__was(a_1021,a_1036)){ return 0;}
a_A[0]=a_1036;
a_1076(); return 1;
} /* Qstring */
static void a_1074(int a_A[1]){ /* mustQtag+a> */
int a_P[1];
if(a_1037(a_P)){a_A[0]=a_P[0];return;}
a_1063(a_1001,16777240,185);return;
} /* mustQtag */
static void a_1073(int a_A[2]){ /* mustQlist+a>+a> */
int a_P[1];
a_A[1]=a_1031;
a_1074(a_P);a_A[0]=a_P[0];return;
} /* mustQlist */
static void a_1034(int a_F1){ /* Qskip+>a */

a_G1:if(a_1027(2106125252)){return;}
if(a_1025(a_F1)){return;}
a_1076(); goto a_G1;
} /* Qskip */
static void a_1080(int a_C,int *a_V){ /* putQ+*+>a */

a_G1: a_extension(a_1026,1);to_LIST(a_1026)->top[1]=a_V[0];to_LIST(a_1026)->aupb+=1;
if(a_C>1){a_C--;a_V+=1; goto a_G1;} return;
} /* putQ */
static void a_1045(int a_A[1]){ /* copyQBUFFERaffix+>a> */
int a_P[2];
a_G1:{register int a_r1=to_LIST(a_1026)->offset[a_A[0]];
 if(a_r1==2106125321||a_r1==2106125252){ goto a_G2;}
 if(a_r1==2106125245){  goto a_G4;}
  goto a_G7;}
a_G2:__incr(a_A[0]);
a_P[0]=2106125252;a_1080(1,a_P);return;
a_G4:__incr(a_A[0]);
a_P[0]=2106125245;a_P[1]=to_LIST(a_1026)->offset[a_A[0]];a_1080(2,a_P);
a_G6:__incr(a_A[0]); goto a_G1;
a_G7:a_P[0]=to_LIST(a_1026)->offset[a_A[0]];a_1080(1,a_P); goto a_G6;
} /* copyQBUFFERaffix */
static void a_1083(int a_A[1]){ /* readselector+a> */
int a_L2;int a_P[1];
if(a_1029(a_P)){a_A[0]=a_P[0];return;}
a_1074(a_P);a_L2=a_P[0];
a_1056(a_L2,a_P);a_A[0]=a_P[0];return;
} /* readselector */
static void a_1048(int a_F1,int a_F2,int a_A[1]){ /* finalssel+>a+>a+a> */
int a_P[1];
if(!__is(a_F2)){ goto a_G3;}
a_A[0]=to_LIST(a_1022)->offset[a_F2-4];return;
a_G3:if(!__was(a_1022,a_F1)){ goto a_G5;}
a_A[0]=to_LIST(a_1022)->offset[a_F1-4];return;
a_G5:a_1057(a_F1,a_P);a_A[0]=a_P[0];return;
} /* finalssel */
static int a_1065(int a_A[1]){ /* limitop+a> */

a_A[0]=a_1036;
if(a_1025(2106125362)){ return 1;}
if(a_1025(2106125366)){ return 1;}
if(a_1025(2106125294)){ return 1;}
if(a_1025(2106125358)){ return 1;}
if(!a_1025(2106125229)){ return 0;} return 1;
} /* limitop */
static void a_1049(int a_A[1]){ /* fsimpleaffix+a> */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[7];
if(!a_1029(a_P)){ goto a_G4;}a_L2=a_P[0];
a_P[0]=2106125245;a_P[1]=a_L2;a_1080(2,a_P);
a_G3:a_A[0]=0;return;
a_G4:if(!a_1065(a_P)){ goto a_G8;}a_L2=a_P[0];
a_1074(a_P);a_L3=a_P[0];
a_P[0]=a_L2;a_P[1]=a_L3;a_1080(2,a_P); goto a_G3;
a_G8:if(!a_1025(2106125346)){ goto a_G15;}
a_1074(a_P);a_L3=a_P[0];
a_P[0]=2106125346;a_P[1]=a_L3;a_1080(2,a_P);
a_1049(a_P);a_A[0]=a_P[0];
a_1071(2106125224);
a_1083(a_P);a_L2=a_P[0];
a_P[0]=2106125224;a_P[1]=2106125245;a_P[2]=a_L2;a_1080(3,a_P);return;
a_G15:if(!a_1025(2106125305)){ goto a_G17;}
a_A[0]=16777646;return;
a_G17:a_1073(a_P);a_L3=a_P[0];a_L5=a_P[1];
a_A[0]=0;
a_1058(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777525||a_L4==16777566||a_L4==16777535||a_L4==16777540||a_L4==16777612||a_L4==16777617||a_L4==16777623||a_L4==16777650){ goto a_G21;}
 if(a_L4==16777548||a_L4==16777544||a_L4==16777554||a_L4==16777596||a_L4==16777602){ goto a_G22;}
 if(a_L4==16777629){  goto a_G24;}
  goto a_G26;}
a_G21:a_P[0]=a_L3;a_1080(1,a_P);return;
a_G22:a_1048(a_L3,a_L5,a_P);a_L2=a_P[0];
a_P[0]=2106125346;a_P[1]=a_L3;a_P[2]=2106125358;a_P[3]=a_L3;a_P[4]=2106125224;a_P[5]=2106125245;a_P[6]=a_L2;a_1080(7,a_P);return;
a_G24:a_P[0]=a_L3;a_1080(1,a_P);
a_A[0]=16777629;return;
a_G26:a_1063(a_1001,16777235,253);return;
} /* fsimpleaffix */
static void a_1070(int a_F1,int a_A[1]){ /* matchformalactual+>a+a> */
int a_L3;int a_P[1];
{ if(a_F1==16777607||a_F1==16777602||a_F1==16777596){ goto a_G2;}
 if(a_F1==16777612||a_F1==16777617||a_F1==16777623){  goto a_G5;}
  goto a_G6;}
a_G2:a_1074(a_P);a_L3=a_P[0];
a_P[0]=a_L3;a_1080(1,a_P);
a_1058(a_L3,a_P);a_A[0]=a_P[0];return;
a_G5:a_1049(a_P);a_A[0]=a_P[0];return;
a_G6:a_1063(a_1001,16777229,262);return;
} /* matchformalactual */
static void a_1059(int a_F1,int a_F2){ /* handleformallist+>a+>a */
int a_P[1];
{ if(!(a_F2==16777596||a_F2==16777602)){return;}
}
a_1054(a_F1,a_P);to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-5]=a_P[0];
a_1055(a_F1,a_P);to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-4]=a_P[0];return;
} /* handleformallist */
static void a_1047(int a_F1){ /* expandvarargs+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[2];
a_1050(a_F1,a_P);a_L2=a_P[0];
a_L5=to_LIST(a_1022)->aupb;
a_L6=0;
a_G4:a_1058(a_L2,a_P);a_L3=a_P[0];
a_1070(a_L3,a_P);a_L4=a_P[0];
if(__equal(a_L4,16777629)){ goto a_G22;}
if(!__equal(a_L6,0)){ goto a_G10;}
 a_extension(a_1022,6);to_LIST(a_1022)->top[5]=0;to_LIST(a_1022)->top[6]=a_L2;to_LIST(a_1022)->top[4]=16777641;to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
a_1059(a_L2,a_L3);
a_G10:if(__noteq(a_L4,16777646)){ goto a_G16;}
if(!__equal(a_L6,0)){ goto a_G15;}
to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-1]=-1;
to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2]=16777650;
a_P[0]=to_LIST(a_1022)->aupb;a_1080(1,a_P); goto a_G16;
a_G15:a_P[0]=2106125305;a_1080(1,a_P);
a_G16:a_1050(a_L2,a_P);a_L2=a_P[0];
if(!__equal(a_L2,0)){ goto a_G20;}
a_L6=1;
a_1050(a_F1,a_P);a_L2=a_P[0];
a_G20:if(!a_1025(2106125321)){ goto a_G22;}
a_P[0]=2106125321;a_1080(1,a_P); goto a_G4;
a_G22:if(!__equal(a_L6,0)){ goto a_G33;}
a_L7=to_LIST(a_1026)->offset[to_LIST(a_1026)->aupb];
a_G24:if(!__equal(a_L2,0)){ goto a_G27;}
if(__equal(a_L7,0)){return;}
a_1063(a_1001,16777222,292);return;
a_G27: a_extension(a_1022,6);to_LIST(a_1022)->top[5]=to_LIST(a_1026)->aupb;to_LIST(a_1022)->top[6]=a_L2;to_LIST(a_1022)->top[4]=16777641;to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
a_1058(a_L2,a_P);a_L3=a_P[0];
a_1059(a_L2,a_L3);
a_P[0]=to_LIST(a_1020)->offset[a_L7-2];a_P[1]=2106125252;a_1080(2,a_P);
a_1050(a_L2,a_P);a_L2=a_P[0];
a_1050(a_L7,a_P);a_L7=a_P[0]; goto a_G24;
a_G33:a_P[0]=2106125252;a_1080(1,a_P);
a_L8=to_LIST(a_1022)->offset[a_L5-1];
__incr(a_L8);
a_G36:if(__equal(a_L2,0)){return;}
__next(a_1022,a_L5);
if(!__equal(to_LIST(a_1022)->offset[a_L5-2],16777641)){ goto a_G40;}
to_LIST(a_1022)->offset[a_L5-1]=to_LIST(a_1026)->aupb;
a_G40:a_P[0]=a_L8;a_1045(a_P);a_L8=a_P[0];
a_1050(a_L2,a_P);a_L2=a_P[0]; goto a_G36;
} /* expandvarargs */
static void a_1067(int a_F1){ /* macroarguments+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1050(a_F1,a_P);a_L2=a_P[0];
a_G2:if(__equal(a_L2,0)){return;}
 a_extension(a_1022,6);to_LIST(a_1022)->top[5]=to_LIST(a_1026)->aupb;to_LIST(a_1022)->top[6]=a_L2;to_LIST(a_1022)->top[4]=16777641;to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
a_1071(2106125321);
a_1058(a_L2,a_P);a_L3=a_P[0];
a_1059(a_L2,a_L3);
if(!__equal(a_L3,16777629)){ goto a_G9;}
a_1047(a_L2);return;
a_G9:a_1070(a_L3,a_P);a_L4=a_P[0];
if(!__equal(a_L4,16777646)){ goto a_G13;}
to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-1]=-1;
to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2]=16777650; goto a_G14;
a_G13:a_P[0]=2106125252;a_1080(1,a_P);
a_G14:a_1050(a_L2,a_P);a_L2=a_P[0]; goto a_G2;
} /* macroarguments */
static void a_1068(int a_F1,int a_A[2]){ /* macrocallhead+>a+a>+a> */
int a_L4;
a_A[0]=to_LIST(a_1026)->aupb;
a_A[1]=a_1033;
a_L4=to_LIST(a_1022)->aupb;
a_1067(a_F1);
__subtr(a_L4,to_LIST(a_1022)->alwb,a_1033);
__next(a_1022,a_1033);return;
} /* macrocallhead */
static void a_1069(int a_F1,int a_F2){ /* macrocalltail+>a+>a */

a_1033=a_F2;
__unstackto(a_1026,a_F1);return;
} /* macrocalltail */
static void a_1010(void){ /* @root */

} /* @root */
static void a_1124(int a_F1){ /* printchar+>a */

__incr(a_1133);
a_putchar(a_1102,a_F1);return;
} /* printchar */
static void a_1119(void){ /* nlcr */

if(!__lseq(a_1133,1)){ goto a_G3;}
a_1133=1;return;
a_G3:a_1133=0;
a_1124(10);return;
} /* nlcr */
static void a_1143(int a_F1){ /* tabline+>a */

a_G1:if(__equal(a_1133,a_F1)){return;}
if(!__more(a_1133,a_F1)){ goto a_G4;}
a_1119(); goto a_G1;
a_G4:a_1124(32); goto a_G1;
} /* tabline */
static void a_1127(int a_F1){ /* printint+>a */

if(!__equal(a_F1,(-2147483647-1))){ goto a_G5;}
a_1124(45);
__subtr(-1,a_F1,a_F1);
a_1128(a_F1,49);return;
a_G5:if(!__less(a_F1,0)){ goto a_G8;}
a_1124(45);
__getabs(a_F1,a_F1);
a_G8:a_1128(a_F1,48);return;
} /* printint */
static void a_1128(int a_F1,int a_F2){ /* printint1+>a+>a */
int a_L3;int a_L4;
_divrem11(a_F1,10,a_L3,a_L4);
if(__equal(a_L3,0)){ goto a_G4;}
a_1128(a_L3,48);
a_G4:__add(a_L4,a_F2,a_L4);
a_1124(a_L4);return;
} /* printint1 */
static void a_1125(int a_F1){ /* printform+>a */

a_1126(a_F1,4);return;
} /* printform */
static void a_1126(int a_F1,int a_F2){ /* printform1+>a+>a */
int a_L3;int a_L4;
if(__equal(a_F2,0)){return;}
__decr(a_F2);
_divrem11(a_F1,10,a_L3,a_L4);
a_1126(a_L3,a_F2);
__add(a_L4,48,a_L4);
a_1124(a_L4);return;
} /* printform1 */
static void a_1122(int a_F1,int a_F2){ /* print+t[]+>a */
int a_L2;
if(!__was(a_F1,a_F2)){return;}
a_1137(a_1102,a_F1,a_F2);
__stringlength(a_F1,a_F2,a_L2);
__add(a_1133,a_L2,a_1133);return;
} /* print */
static void a_1138(void){ /* resetprline */

a_1132=0;
a_1119();return;
} /* resetprline */
static void a_1140(void){ /* saveprpos */

if(!__is(a_1134)){return;}
a_1134=0;
a_1120=a_1133;return;
} /* saveprpos */
static void a_1129(int a_F1){ /* printlinehead+>a */

if(!__is(a_F1)){return;}
a_1119();
a_1143(2);
a_1125(a_1132);
a_1143(9);return;
} /* printlinehead */
static void a_1107(int a_F1,int a_F2){ /* displaychar+>a+>a */

if(!__equal(a_F1,10)){ goto a_G5;}
__incr(a_1132);
a_1134=1;
a_1129(a_F2);return;
a_G5:if(!__is(a_F2)){return;}
if(__is(a_1134)){ goto a_G9;}
a_1134=1;
a_1143(a_1120);
a_G9:a_1124(a_F1);return;
} /* displaychar */
static void a_1123(int a_F1){ /* printbase+>a */
int a_L2;int a_L3;
a_L2=to_LIST(a_1006)->aupb;
a_unpackstring(a_1021,a_F1,a_1006);
a_L3=to_LIST(a_1006)->aupb;
a_G4:if(__lseq(a_L3,a_L2)){ goto a_G9;}
if(__equal(to_LIST(a_1006)->offset[a_L3],47)){ goto a_G9;}
if(__equal(to_LIST(a_1006)->offset[a_L3],92)){ goto a_G9;}
if(__equal(to_LIST(a_1006)->offset[a_L3],58)){ goto a_G9;}
__decr(a_L3); goto a_G4;
a_G9:__incr(a_L3);
if(__less(to_LIST(a_1006)->aupb,a_L3)){ goto a_G14;}
if(__equal(to_LIST(a_1006)->offset[a_L3],46)){ goto a_G14;}
a_1124(to_LIST(a_1006)->offset[a_L3]); goto a_G9;
a_G14:__unstackto(a_1006,a_L2);return;
} /* printbase */
static void a_1131(int a_F1){ /* printsourceline+>a */
int a_L2;int a_P[2];
if(!__equal(a_F1,0)){ goto a_G3;}
a_1124(48);return;
a_G3:a_1111(a_F1,a_P);a_F1=a_P[0];a_L2=a_P[1];
a_1125(a_F1);
a_1124(47);
a_1123(a_L2);return;
} /* printsourceline */
static void a_1130(int a_F1){ /* printpointer+>a */
int a_L2;int a_P[1];
if(!__equal(a_F1,0)){ goto a_G3;}
a_1122(a_1001,16777310);return;
a_G3:if(!__was(a_1023,a_F1)){ goto a_G5;}
a_1122(a_1023,a_F1);return;
a_G5:if(!__was(a_1006,a_F1)){ goto a_G7;}
a_1122(a_1006,a_F1);return;
a_G7:if(a_1149(a_F1,a_1006)){ goto a_G10;}
if(a_1151(a_F1,a_1006)){ goto a_G10;}
if(!a_1152(a_F1,a_1006)){ goto a_G12;}
a_G10:a_1122(a_1006,to_LIST(a_1006)->aupb);
__unstackstring(a_1006);return;
a_G12:if(!a_1148(a_F1,a_P)){ goto a_G14;}a_L2=a_P[0];
a_1127(a_L2);return;
a_G14:a_1122(a_1001,16777306);
a_1127(a_F1);
a_1122(a_1001,16777303);return;
} /* printpointer */
static void a_1135(int a_F1){ /* pushBUFFER+>a */

 a_extension(a_1006,1);to_LIST(a_1006)->top[1]=a_F1;to_LIST(a_1006)->aupb+=1;
 return;
} /* pushBUFFER */
static void a_1121(int a_A[1]){ /* popBUFFER+a> */

a_A[0]=to_LIST(a_1006)->offset[to_LIST(a_1006)->aupb];
__unstack(a_1006);return;
} /* popBUFFER */
static void a_1112(int a_C,int *a_V){ /* formatprint+*+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_L4=0;
a_G2:a_L2=to_LIST(a_1006)->aupb;
a_unpackstring(a_1023,a_V[0],a_1006);
a_L3=a_L2;
a_G5:__incr(a_L3);
a_G6:if(!__less(to_LIST(a_1006)->aupb,a_L3)){ goto a_G12;}
if(__equal(a_L4,0)){ goto a_G50;}
__decr(a_L4);
__unstackto(a_1006,a_L2);
a_1121(a_P);a_L2=a_P[0];
a_1121(a_P);a_L3=a_P[0]; goto a_G6;
a_G12:if(!__noteq(to_LIST(a_1006)->offset[a_L3],37)){ goto a_G15;}
a_G13:a_1124(to_LIST(a_1006)->offset[a_L3]); goto a_G5;
a_G15:__incr(a_L3);
if(!__less(to_LIST(a_1006)->aupb,a_L3)){ goto a_G18;}
a_1124(37); goto a_G50;
a_G18:{register int a_r1=to_LIST(a_1006)->offset[a_L3];
 if(a_r1==100){ goto a_G19;}
 if(a_r1==99){ goto a_G23;}
 if(a_r1==108){ goto a_G29;}
 if(a_r1==112){ goto a_G33;}
 if(a_r1==109){ goto a_G37;}
 if(a_r1==110){ goto a_G44;}
 if(a_r1==42){  goto a_G46;}
  goto a_G13;}
a_G19:if(a_C<=1){ goto a_G21;} a_C--;a_V+=1;
a_1127(a_V[0]); goto a_G5;
a_G21:a_1122(a_1001,16777300); goto a_G5;
a_G23:if(a_C<=1){ goto a_G27;} a_C--;a_V+=1;
if(!__equal(a_V[0],10)){ goto a_G26;}
a_1122(a_1001,16777296); goto a_G5;
a_G26:a_1124(a_V[0]); goto a_G5;
a_G27:a_1122(a_1001,16777291); goto a_G5;
a_G29:if(a_C<=1){ goto a_G31;} a_C--;a_V+=1;
a_1131(a_V[0]); goto a_G5;
a_G31:a_1122(a_1001,16777287); goto a_G5;
a_G33:if(a_C<=1){ goto a_G35;} a_C--;a_V+=1;
a_1130(a_V[0]); goto a_G5;
a_G35:a_1122(a_1001,16777284); goto a_G5;
a_G37:if(a_C<=1){ goto a_G42;} a_C--;a_V+=1;
__incr(a_L3);
a_1135(a_L3);
a_1135(a_L2);
__incr(a_L4); goto a_G2;
a_G42:a_1122(a_1001,16777281); goto a_G5;
a_G44:a_1124(10); goto a_G5;
a_G46:if(a_C>1){a_C--;a_V+=1;}  goto a_G5;
a_G50:if(a_C<=1){ goto a_G52;} a_C--;a_V+=1;
a_1122(a_1001,16777277);
a_G52:__unstackto(a_1006,a_L2);return;
} /* formatprint */
static void a_1100(void){ /* DICTtab */
int a_L1;
a_G1:if(!__more(a_1133,a_1139)){ goto a_G3;}
a_1143(8);return;
a_G3:a_1124(32);
_divrem01(a_1133,6,a_L1);
if(__equal(a_L1,1)){return;} goto a_G1;
} /* DICTtab */
static void a_1098(int a_F1,int a_F2){ /* DICTheader+>a+>a */
int a_L3;int a_P[2];
a_1119();
a_1115=0;
a_1114(3429900,a_P);a_1139=a_P[0];
a_1130(a_F1);
a_1124(32);
if(!__less(a_1133,8)){ goto a_G8;}
a_1143(8);
a_G8:if(__lseq(a_F2,0)){return;}
a_1111(a_F2,a_P);a_L3=a_P[0];a_1115=a_P[1];
a_1123(a_1115);
a_1124(58);
a_1125(a_L3);
a_1124(42);return;
} /* DICTheader */
static void a_1099(int a_F1){ /* DICTitem+>a */
int a_L2;int a_L3;int a_P[2];
a_1111(a_F1,a_P);a_L3=a_P[0];a_L2=a_P[1];
if(__equal(a_L2,a_1115)){ goto a_G7;}
a_1115=a_L2;
a_1100();
a_1123(a_1115);
a_1124(58);
a_G7:a_1100();
a_1125(a_L3);return;
} /* DICTitem */
static void a_1101(void){ /* DICTtail */

a_1119();return;
} /* DICTtail */
static int a_1147(void){ /* waserror */

if(!__more(a_1109,0)){ return 0;} return 1;
} /* waserror */
static void a_1104(int a_A[1]){ /* clearlocalerror+a> */

a_A[0]=a_1116;
a_1116=0;return;
} /* clearlocalerror */
static int a_1150(int a_F1){ /* waslocalerror+>a */
int a_L2;
a_L2=a_1116;
__add(a_F1,a_L2,a_1116);
if(!__more(a_L2,0)){ return 0;} return 1;
} /* waslocalerror */
static void a_1118(int a_F1,int a_F2){ /* messageheader+>a+>a */

a_1140();
a_1119();
if(!__less(a_F2,0)){ goto a_G5;}
a_1124(73); goto a_G10;
a_G5:if(!__less(a_F2,10)){ goto a_G9;}
a_1124(87);
__add(a_F2,48,a_F2);
a_1124(a_F2); goto a_G10;
a_G9:a_1124(69);
a_G10:if(__equal(a_F1,0)){ goto a_G13;}
a_1143(4);
a_1131(a_F1);
a_G13:a_1143(22);return;
} /* messageheader */
static void a_1040(int a_F1,int a_C,int *a_V){ /* Xerror+>a+*+>a */
int a_P[1];
__incr(a_1109);
__incr(a_1116);
if(__more(a_1109,51)){return;}
if(!__equal(a_1109,51)){ goto a_G8;}
a_1118(a_F1,10);
a_P[0]=2093832580;a_1112(1,a_P);
a_1119();return;
a_G8:a_1118(a_F1,10);
a_1112(a_C,a_V);
a_1119();return;
} /* Xerror */
static void a_1041(int a_F1,int a_F2,int a_C,int *a_V){ /* Xwarning+>a+>a+*+>a */
int a_L4;int a_P[1];
if(__more(a_1109,51)){return;}
a_1114(3429889,a_P);a_L4=a_P[0];
if(__less(a_F1,a_L4)){return;}
a_1118(a_F2,a_F1);
a_1112(a_C,a_V);
a_1119();return;
} /* Xwarning */
static void a_1117(int a_C,int *a_V){ /* message+*+>a */

if(__more(a_1109,51)){return;}
a_1118(-1,-1);
a_1112(a_C,a_V);
a_1119();return;
} /* message */
static void a_1103(int a_C,int *a_V){ /* Xmessage+*+>a */

__incr(a_1109);
a_1119();
a_1112(a_C,a_V);
a_1119();return;
} /* Xmessage */
static void a_1063(int a_F1,int a_F2,int a_F3){ /* internalerror+t[]+>a+>a */
int a_P[3];
a_1118(0,10);
a_copystring(a_F1,a_F2,a_1006);
a_P[0]=2093832608;a_P[1]=to_LIST(a_1006)->aupb;a_P[2]=a_F3;a_1112(3,a_P);
exit(64);return;
} /* internalerror */
static void a_1097(void){ /* @root */

} /* @root */
static void a_1137(int a_F1,int a_F2,int a_F3){ /* putstring+""f+t[]+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=0;
a_G2:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){return;}a_L3=a_P[0];
__incr(a_L2);
a_putchar(a_F1,a_L3); goto a_G2;
} /* putstring */
static int a_1204(int a_F1,int a_F2){ /* islocalflag+>a+>a */
int a_L3;
__booland(to_LIST(a_1022)->offset[a_F1-3],a_F2,a_L3);
if(!__noteq(a_L3,0)){ return 0;} return 1;
} /* islocalflag */
static void a_1229(int a_F1,int a_F2){ /* setlocalflag+>a+>a */

__boolor(to_LIST(a_1022)->offset[a_F1-3],a_F2,to_LIST(a_1022)->offset[a_F1-3]);return;
} /* setlocalflag */
static void a_1177(int a_F1,int a_F2){ /* clearlocalflag+>a+>a */

__boolinvert(a_F2,a_F2);
__booland(to_LIST(a_1022)->offset[a_F1-3],a_F2,to_LIST(a_1022)->offset[a_F1-3]);return;
} /* clearlocalflag */
static void a_1184(void){ /* copylocalTflagtoF */
int a_L1;
a_L1=to_LIST(a_1022)->aupb;
a_G2:if(__less(a_L1,to_LIST(a_1022)->alwb)){return;}
if(!a_1204(a_L1,2)){ goto a_G5;}
a_1229(a_L1,4); goto a_G6;
a_G5:a_1177(a_L1,4);
a_G6:if(!a_1204(a_L1,8)){ goto a_G8;}
a_1229(a_L1,16); goto a_G9;
a_G8:a_1177(a_L1,16);
a_G9:__previous(a_1022,a_L1); goto a_G2;
} /* copylocalTflagtoF */
static void a_1223(int a_F1){ /* resetaffixblockflags+>a */
int a_L2;int a_L3;int a_P[3];
a_L2=to_LIST(a_1022)->alwb;
a_L3=1;
a_G3:if(__more(a_L2,to_LIST(a_1022)->aupb)){return;}
if(__equal(to_LIST(a_1022)->offset[a_L2-2],16777654)){return;}
if(!__equal(to_LIST(a_1022)->offset[a_L2-2],16777629)){ goto a_G12;}
if(a_1204(a_L2,8)){ goto a_G8;}
a_P[0]=2093832632;a_P[1]=a_F1;a_1041(4,-1,2,a_P);
a_G8:if(!a_1204(a_L2,2)){ goto a_G10;}
a_L3=0;
a_G10:a_1177(a_L2,16);
a_1229(a_L2,4); goto a_G18;
a_G12:if(!a_1204(a_L2,4096)){ goto a_G18;}
if(!__is(a_L3)){ goto a_G18;}
if(!__equal(to_LIST(a_1022)->offset[a_L2-2],16777617)){ goto a_G18;}
if(!a_1204(a_L2,2)){ goto a_G17;}
a_1177(a_L2,2); goto a_G18;
a_G17:a_P[0]=2093832621;a_P[1]=a_F1;a_P[2]=to_LIST(a_1022)->offset[a_L2];a_1040(-1,3,a_P);
a_G18:__next(a_1022,a_L2); goto a_G3;
} /* resetaffixblockflags */
static int a_1155(int a_A[1]){ /* Ltag+a> */
int a_P[1];
if(!a_1037(a_P)){ return 0;}a_A[0]=a_P[0];
if(!__was(a_1022,a_A[0])){ return 1;}
a_1229(a_A[0],1); return 1;
} /* Ltag */
static void a_1213(int a_A[1]){ /* mustLtag+a> */
int a_P[1];
a_1074(a_P);a_A[0]=a_P[0];
if(!__was(a_1022,a_A[0])){return;}
a_1229(a_A[0],1);return;
} /* mustLtag */
static void a_1232(int a_F1){ /* setupformalstack+>a */
int a_L2;int a_L3;int a_P[1];
__scratch(a_1022);
a_L3=0;
a_1050(a_F1,a_P);a_L2=a_P[0];
a_G4:if(__equal(a_L2,0)){return;}
 a_extension(a_1022,6);to_LIST(a_1022)->top[3]=2;to_LIST(a_1022)->top[5]=0;to_LIST(a_1022)->top[4]=to_LIST(a_1020)->offset[a_L2-3];to_LIST(a_1022)->top[6]=a_L2;to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
a_P[0]=a_L3;a_1228(a_P);a_L3=a_P[0];
a_1050(a_L2,a_P);a_L2=a_P[0]; goto a_G4;
} /* setupformalstack */
static void a_1233(int a_A[1]){ /* setuplabel+a> */
int a_P[1];
if(!a_1025(2106125279)){ goto a_G5;}
a_1074(a_P);a_A[0]=a_P[0];
 a_extension(a_1022,6);to_LIST(a_1022)->top[5]=0;to_LIST(a_1022)->top[4]=16777654;to_LIST(a_1022)->top[6]=a_A[0];to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
a_A[0]=to_LIST(a_1022)->aupb;return;
a_G5:a_A[0]=0;return;
} /* setuplabel */
static void a_1234(void){ /* setuplocals */
int a_L1;int a_P[1];
if(!a_1025(2106125290)){return;}
a_G2:if(a_1025(2106125235)){return;}
a_1074(a_P);a_L1=a_P[0];
 a_extension(a_1022,6);to_LIST(a_1022)->top[3]=0;to_LIST(a_1022)->top[5]=a_1181;to_LIST(a_1022)->top[4]=16777650;to_LIST(a_1022)->top[6]=a_L1;to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
  goto a_G2;
} /* setuplocals */
static void a_1228(int a_A[1]){ /* setformalaffix+>a> */
int a_P[1];
{register int a_r1=to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2];
 if(a_r1==16777596||a_r1==16777602){ goto a_G2;}
 if(a_r1==16777629){ goto a_G4;}
 if(a_r1==16777617){  goto a_G7;}
  goto a_G8;}
a_G2:a_1054(to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb],a_P);to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-5]=a_P[0];
a_1055(to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb],a_P);to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-4]=a_P[0];return;
a_G4:a_1177(to_LIST(a_1022)->aupb,2);
a_1229(to_LIST(a_1022)->aupb,8);
a_A[0]=1;return;
a_G7:a_1177(to_LIST(a_1022)->aupb,2);
a_G8:if(!__is(a_A[0])){return;}
a_1229(to_LIST(a_1022)->aupb,4096);return;
} /* setformalaffix */
static void a_1200(int a_F1,int a_A[1]){ /* getlocalcalibre+>a+a> */

a_A[0]=to_LIST(a_1022)->offset[a_F1-5];return;
} /* getlocalcalibre */
static void a_1201(int a_F1,int a_A[1]){ /* getlocalssel+>a+a> */

a_A[0]=to_LIST(a_1022)->offset[a_F1-4];return;
} /* getlocalssel */
static void a_1218(int a_F1){ /* pushRULE+>a */

a_1190(0,a_F1);return;
} /* pushRULE */
static void a_1227(int a_F1,int a_F2){ /* setRULEflag+>a+>a */

__boolor(to_LIST(a_1007)->offset[a_F1-1],a_F2,to_LIST(a_1007)->offset[a_F1-1]);return;
} /* setRULEflag */
static int a_1203(int a_F1,int a_F2){ /* isRULEflag+>a+>a */
int a_L3;
__booland(to_LIST(a_1007)->offset[a_F1-1],a_F2,a_L3);
if(!__noteq(a_L3,0)){ return 0;} return 1;
} /* isRULEflag */
static void a_1176(int a_F1,int a_F2){ /* clearRULEflag+>a+>a */
int a_L3;
__boolinvert(a_F2,a_L3);
__booland(to_LIST(a_1007)->offset[a_F1-1],a_L3,to_LIST(a_1007)->offset[a_F1-1]);return;
} /* clearRULEflag */
static void a_1215(int a_F1){ /* openrange+>a */
int a_L2;
a_L2=to_LIST(a_1022)->alwb;
a_1218(0);
if(!__is(a_F1)){ goto a_G5;}
a_1227(to_LIST(a_1007)->aupb,32);
a_G5:if(__more(a_L2,to_LIST(a_1022)->aupb)){return;}
if(__equal(to_LIST(a_1022)->offset[a_L2-2],16777654)){ goto a_G12;}
a_1218(a_L2);
if(!a_1204(a_L2,2)){ goto a_G10;}
a_1227(to_LIST(a_1007)->aupb,272);
a_G10:if(!a_1204(a_L2,8)){ goto a_G12;}
a_1227(to_LIST(a_1007)->aupb,544);
a_G12:__next(a_1022,a_L2); goto a_G5;
} /* openrange */
static void a_1221(int a_F1){ /* recomputeRULEflags+>a */
int a_L2;int a_L3;int a_L4;
if(!a_1203(a_F1,16)){ goto a_G3;}
a_L2=1; goto a_G4;
a_G3:a_L2=0;
a_G4:if(!a_1203(a_F1,32)){ goto a_G6;}
a_L3=1; goto a_G7;
a_G6:a_L3=0;
a_G7:to_LIST(a_1007)->offset[a_F1-1]=0;
a_L4=to_LIST(a_1007)->offset[a_F1];
if(!__is(a_L2)){ goto a_G12;}
a_1227(a_F1,272);
a_1229(a_L4,2); goto a_G13;
a_G12:a_1177(a_L4,2);
a_G13:if(!__is(a_L3)){ goto a_G16;}
a_1227(a_F1,544);
a_1229(a_L4,8);return;
a_G16:a_1177(a_L4,8);return;
} /* recomputeRULEflags */
static void a_1158(int a_F1,int a_F2){ /* addlabel+>a+>a */

if(!__is(a_F1)){return;}
a_1218(to_LIST(a_1022)->offset[a_F1]);
to_LIST(a_1022)->offset[a_F1-1]=a_F2;return;
} /* addlabel */
static int a_1222(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* redoregion+>a+>a+>a+a> */
int a_L5;
a_L5=a_F1;
a_G2:if(__equal(to_LIST(a_1007)->offset[a_L5],0)){ goto a_G4;}
__previous(a_1007,a_L5); goto a_G2;
a_G4:if(__equal(a_F2,0)){ goto a_G9;}
if(a_1203(a_L5,8192)){ goto a_G9;}
a_1227(a_L5,8192);
if(!a_1203(a_L5,4096)){ goto a_G9;}
a_1227(a_L5,32768);
a_G9:if(__equal(a_F3,0)){ goto a_G14;}
if(a_1203(a_L5,16384)){ goto a_G14;}
a_1227(a_L5,16384);
if(!a_1203(a_L5,4096)){ goto a_G14;}
a_1227(a_L5,32768);
a_G14:if(!a_1203(a_L5,32768)){ return 0;}
a_1176(a_L5,32768);
if(!a_1203(a_L5,32)){ goto a_G18;}
a_A[0]=1; goto a_G19;
a_G18:a_A[0]=0;
a_G19:if(__lseq(a_F1,a_L5)){ return 1;}
__next(a_1007,a_L5);
a_1221(a_L5); goto a_G19;
} /* redoregion */
static void a_1168(int a_F1){ /* checklabelshield+>a */
int a_L2;int a_P[2];
a_L2=to_LIST(a_1022)->offset[a_F1-1];
a_G2:if(a_1203(a_L2,65536)){return;}
if(!__mreq(a_L2,to_LIST(a_1007)->aupb)){ goto a_G5;}
a_P[0]=2093832640;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G5:__next(a_1007,a_L2); goto a_G2;
} /* checklabelshield */
static void a_1230(int a_F1,int a_F2,int a_A[2]){ /* setrulejump+>a+>a+a>+a> */
int a_L5;int a_L6;
a_L6=0;
a_A[0]=a_F2;a_A[1]=a_F2;
a_G3:a_L5=to_LIST(a_1007)->offset[a_F2];
if(!__equal(a_L5,0)){ goto a_G16;}
a_1227(a_F2,4096);
if(a_1203(a_F2,8192)){ goto a_G8;}
a_A[0]=0;
a_G8:if(a_1203(a_F2,16384)){ goto a_G10;}
a_A[1]=0;
a_G10:if(a_1203(a_F2,32)){ goto a_G14;}
if(!__is(a_F1)){ goto a_G14;}
a_1227(a_F2,32);
a_L6=1;
a_G14:if(!__is(a_L6)){return;}
a_1227(a_F2,32768);return;
a_G16:if(!a_1204(a_L5,8)){ goto a_G20;}
if(a_1203(a_F2,32)){ goto a_G20;}
a_1227(a_F2,32);
a_L6=1;
a_G20:if(a_1204(a_L5,2)){ goto a_G24;}
if(!a_1203(a_F2,16)){ goto a_G24;}
a_1176(a_F2,16);
a_L6=1;
a_G24:__previous(a_1007,a_F2); goto a_G3;
} /* setrulejump */
static void a_1231(int a_F1){ /* setupaltheadflags+>a */
int a_L2;
a_G1:a_L2=to_LIST(a_1007)->offset[a_F1];
if(__equal(a_L2,0)){return;}
if(!a_1203(a_F1,256)){ goto a_G5;}
a_1229(a_L2,2); goto a_G6;
a_G5:a_1177(a_L2,2);
a_G6:if(!a_1203(a_F1,512)){ goto a_G8;}
a_1229(a_L2,8); goto a_G9;
a_G8:a_1177(a_L2,8);
a_G9:__previous(a_1007,a_F1); goto a_G1;
} /* setupaltheadflags */
static void a_1237(int a_F1){ /* storealtheadflags+>a */

a_G1:if(__equal(to_LIST(a_1007)->offset[a_F1],0)){return;}
if(!a_1204(to_LIST(a_1007)->offset[a_F1],4)){ goto a_G4;}
a_1227(a_F1,256); goto a_G5;
a_G4:a_1176(a_F1,256);
a_G5:if(!a_1204(to_LIST(a_1007)->offset[a_F1],16)){ goto a_G7;}
a_1227(a_F1,512); goto a_G8;
a_G7:a_1176(a_F1,512);
a_G8:__previous(a_1007,a_F1); goto a_G1;
} /* storealtheadflags */
static void a_1179(int a_F1){ /* closerange+>a */
int a_L2;
a_G1:a_L2=to_LIST(a_1007)->offset[a_F1];
if(!__equal(a_L2,0)){ goto a_G5;}
__previous(a_1007,a_F1);
__unstackto(a_1007,a_F1);return;
a_G5:if(!a_1203(a_F1,1)){ goto a_G7;}
a_1177(a_L2,2); goto a_G8;
a_G7:a_1229(a_L2,2);
a_G8:if(!a_1203(a_F1,2)){ goto a_G10;}
a_1177(a_L2,4); goto a_G11;
a_G10:a_1229(a_L2,4);
a_G11:if(!a_1203(a_F1,4)){ goto a_G13;}
a_1229(a_L2,8); goto a_G14;
a_G13:a_1177(a_L2,8);
a_G14:if(!a_1203(a_F1,8)){ goto a_G16;}
a_1229(a_L2,16); goto a_G17;
a_G16:a_1177(a_L2,16);
a_G17:__previous(a_1007,a_F1); goto a_G1;
} /* closerange */
static void a_1210(int a_F1,int a_F2,int a_F3){ /* mergealtsequenceflags+>a+>a+>a */
int a_L4;
a_G1:a_L4=to_LIST(a_1007)->offset[a_F1];
if(__equal(a_L4,0)){return;}
if(!__is(a_F2)){ goto a_G8;}
if(a_1204(a_L4,2)){ goto a_G6;}
a_1227(a_F1,1);
a_G6:if(!a_1204(a_L4,8)){ goto a_G8;}
a_1227(a_F1,4);
a_G8:if(!__is(a_F3)){ goto a_G13;}
if(a_1204(a_L4,4)){ goto a_G11;}
a_1227(a_F1,2);
a_G11:if(!a_1204(a_L4,16)){ goto a_G13;}
a_1227(a_F1,8);
a_G13:__previous(a_1007,a_F1); goto a_G1;
} /* mergealtsequenceflags */
static void a_1178(int a_F1){ /* cleartailFbits+>a */

a_G1:if(__equal(to_LIST(a_1007)->offset[a_F1],0)){return;}
a_1176(a_F1,3072);
__previous(a_1007,a_F1); goto a_G1;
} /* cleartailFbits */
static void a_1211(int a_F1){ /* mergetailFbits+>a */

a_G1:if(__equal(to_LIST(a_1007)->offset[a_F1],0)){return;}
if(a_1204(to_LIST(a_1007)->offset[a_F1],4)){ goto a_G4;}
a_1227(a_F1,1024);
a_G4:if(!a_1204(to_LIST(a_1007)->offset[a_F1],16)){ goto a_G6;}
a_1227(a_F1,2048);
a_G6:__previous(a_1007,a_F1); goto a_G1;
} /* mergetailFbits */
static void a_1241(int a_F1){ /* usetailFbits+>a */
int a_L2;
a_G1:a_L2=to_LIST(a_1007)->offset[a_F1];
if(__equal(a_L2,0)){return;}
if(!a_1203(a_F1,1024)){ goto a_G5;}
a_1177(a_L2,4); goto a_G6;
a_G5:a_1229(a_L2,4);
a_G6:if(!a_1203(a_F1,2048)){ goto a_G8;}
a_1229(a_L2,16); goto a_G9;
a_G8:a_1177(a_L2,16);
a_G9:__previous(a_1007,a_F1); goto a_G1;
} /* usetailFbits */
static void a_1243(int a_F1,int a_F2,int a_A[1]){ /* where+>a+>a+a> */

if(!__equal(a_F1,0)){ goto a_G3;}
a_A[0]=2093832643;return;
a_G3:if(!__equal(a_F2,0)){ goto a_G5;}
a_A[0]=2093832649;return;
a_G5:a_A[0]=2093832654;return;
} /* where */
static int a_1202(int a_F1){ /* haslisttype+>a */
int a_L2;int a_P[1];
a_1058(a_F1,a_P);a_L2=a_P[0];
{ if(a_L2==16777544||a_L2==16777548||a_L2==16777554||a_L2==16777602||a_L2==16777596){  return 1;}
  return 0;}
} /* haslisttype */
static void a_1214(int a_F1,int a_F2,int a_F3){ /* mustbeoflisttype+>a+>a+>a */
int a_L4;int a_L5;int a_P[5];
a_1058(a_F3,a_P);a_L4=a_P[0];
if(!__equal(a_L4,16777520)){ goto a_G4;}
a_P[0]=2093832665;a_P[1]=a_F3;a_1040(-1,2,a_P);return;
a_G4:a_1243(a_F1,a_F2,a_P);a_L5=a_P[0];
a_P[0]=2093832677;a_P[1]=a_L5;a_P[2]=a_F1;a_P[3]=a_F3;a_P[4]=a_L4;a_1040(-1,5,a_P);return;
} /* mustbeoflisttype */
static void a_1171(int a_F1,int a_F2,int a_F3){ /* checkssel+>a+>a+>a */
int a_L4;int a_L5;int a_P[4];
a_1058(a_F3,a_P);a_L4=a_P[0];
{ if(!(a_L4==16777544||a_L4==16777548||a_L4==16777554)){ goto a_G4;}
}
a_1057(a_F3,a_P);a_L4=a_P[0]; goto a_G5;
a_G4:a_1201(a_F3,a_P);a_L4=a_P[0];
a_G5:if(__more(a_L4,0)){return;}
a_1243(a_F1,a_F2,a_P);a_L5=a_P[0];
a_P[0]=2093832687;a_P[1]=a_L5;a_P[2]=a_F1;a_P[3]=a_F3;a_1040(-1,4,a_P);return;
} /* checkssel */
static void a_1220(int a_F1,int a_F2,int a_A[1]){ /* readselector+>a+>a+a> */
int a_L4;int a_L5;int a_P[4];
if(a_1029(a_P)){a_A[0]=a_P[0];return;}
a_1074(a_P);a_L4=a_P[0];
a_1056(a_L4,a_P);a_A[0]=a_P[0];
if(__more(a_A[0],0)){return;}
a_1243(a_F1,a_F2,a_P);a_L5=a_P[0];
a_P[0]=2093832696;a_P[1]=a_L5;a_P[2]=a_F1;a_P[3]=a_L4;a_1040(-1,4,a_P);return;
} /* readselector */
static void a_1236(void){ /* skipsource */
int a_P[1];
if(a_1029(a_P)){return;}
if(a_1025(2106125294)){ goto a_G7;}
if(a_1025(2106125358)){ goto a_G7;}
if(a_1025(2106125362)){ goto a_G7;}
if(a_1025(2106125366)){ goto a_G7;}
if(!a_1025(2106125229)){ goto a_G8;}
a_G7:a_1074(a_P);return;
a_G8:if(!a_1025(2106125346)){ goto a_G14;}
a_1074(a_P);
a_1236();
a_1071(2106125224);
if(a_1029(a_P)){return;} goto a_G7;
a_G14:if(a_1025(2106125305)){return;} goto a_G7;
} /* skipsource */
static void a_1235(void){ /* skipaffixes */

a_G1:if(!a_1025(2106125321)){return;}
a_1236(); goto a_G1;
} /* skipaffixes */
static void a_1159(int a_F1,int a_F2,int a_F3){ /* affixtypeerror+>a+>a+>a */
int a_L4;int a_L5;int a_P[5];
if(!__equal(a_F3,0)){ goto a_G4;}
a_1243(a_F1,a_F2,a_P);a_L5=a_P[0];
a_P[0]=2093832703;a_P[1]=a_L5;a_P[2]=a_F1;a_1040(-1,3,a_P);return;
a_G4:a_1058(a_F3,a_P);a_L4=a_P[0];
if(!__equal(a_L4,16777520)){ goto a_G7;}
a_P[0]=2093832665;a_P[1]=a_F3;a_1040(-1,2,a_P);return;
a_G7:a_1243(a_F1,a_F2,a_P);a_L5=a_P[0];
a_P[0]=2093832712;a_P[1]=a_L5;a_P[2]=a_F1;a_P[3]=a_F3;a_P[4]=a_L4;a_1040(-1,5,a_P);return;
} /* affixtypeerror */
static void a_1160(int a_F1,int a_F2,int a_F3){ /* affixuninitializederror+>a+>a+>a */
int a_L4;int a_P[4];
a_1243(a_F1,a_F2,a_P);a_L4=a_P[0];
a_P[0]=2093832720;a_P[1]=a_L4;a_P[2]=a_F1;a_P[3]=a_F3;a_1040(-1,4,a_P);return;
} /* affixuninitializederror */
static void a_1183(int a_F1,int a_F2){ /* constantaffixerror+>a+>a */
int a_L3;int a_P[3];
a_1243(a_F1,a_F2,a_P);a_L3=a_P[0];
a_P[0]=2093832728;a_P[1]=a_L3;a_P[2]=a_F1;a_1040(-1,3,a_P);return;
} /* constantaffixerror */
static void a_1186(int a_F1,int a_F2,int a_F3){ /* destlisttypeerror+>a+>a+>a */
int a_L4;int a_P[4];
a_1243(a_F1,a_F2,a_P);a_L4=a_P[0];
a_P[0]=2093832739;a_P[1]=a_L4;a_P[2]=a_F1;a_P[3]=a_F3;a_1040(-1,4,a_P);return;
} /* destlisttypeerror */
static void a_1187(int a_F1,int a_F2,int a_F3){ /* desttypeerror+>a+>a+>a */
int a_L4;int a_L5;int a_P[5];
a_1243(a_F1,a_F2,a_P);a_L4=a_P[0];
a_1198(a_F3,a_P);a_L5=a_P[0];
a_P[0]=2093832750;a_P[1]=a_L4;a_P[2]=a_F1;a_P[3]=a_F3;a_P[4]=a_L5;a_1040(-1,5,a_P);return;
} /* desttypeerror */
static void a_1188(int a_F1,int a_F2){ /* dummyaffixerror+>a+>a */
int a_L3;int a_P[3];
a_1243(a_F1,a_F2,a_P);a_L3=a_P[0];
a_P[0]=2093832761;a_P[1]=a_L3;a_P[2]=a_F1;a_1040(-1,3,a_P);return;
} /* dummyaffixerror */
static void a_1192(int a_F1,int a_F2){ /* ffileaffix+>a+>a */
int a_L3;int a_L4;int a_P[1];
if(!a_1155(a_P)){ goto a_G5;}a_L3=a_P[0];
a_1058(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777607||a_L4==16777571||a_L4==16777576){ return;}
}
a_1159(a_F1,a_F2,a_L3);return;
a_G5:a_1159(a_F1,a_F2,0);
a_1236();return;
} /* ffileaffix */
static void a_1166(int a_F1,int a_F2,int a_F3){ /* checkcalibre+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_L7;int a_P[5];
a_1054(a_F2,a_P);a_L4=a_P[0];
if(__less(a_L4,0)){return;}
a_1058(a_F3,a_P);a_L5=a_P[0];
if(__equal(a_L5,16777602)){ goto a_G6;}
if(!__equal(a_L5,16777596)){ goto a_G10;}
a_G6:a_1200(a_F3,a_P);a_L6=a_P[0];
if(__mreq(a_L6,0)){ goto a_G9;}
a_L6=1;
a_G9:a_1201(a_F3,a_P);a_L7=a_P[0]; goto a_G12;
a_G10:a_1197(a_F3,a_P);a_L6=a_P[0];
a_1057(a_F3,a_P);a_L7=a_P[0];
a_G12:if(__equal(a_L4,a_L6)){ goto a_G16;}
if(!a_1205(a_F1,128)){ goto a_G15;}
a_P[0]=2093832783;a_P[1]=2093832659;a_P[2]=a_F1;a_P[3]=a_F3;a_P[4]=a_L4;a_1040(-1,5,a_P); goto a_G16;
a_G15:a_P[0]=2093832783;a_P[1]=2093832654;a_P[2]=a_F1;a_P[3]=a_F3;a_P[4]=a_L4;a_1041(7,-1,5,a_P);
a_G16:a_1055(a_F2,a_P);a_L4=a_P[0];
if(__equal(a_L4,a_L7)){return;}
if(!a_1205(a_F1,128)){ goto a_G20;}
a_P[0]=2093832796;a_P[1]=2093832659;a_P[2]=a_F1;a_P[3]=a_F3;a_1040(-1,4,a_P);return;
a_G20:a_P[0]=2093832796;a_P[1]=2093832654;a_P[2]=a_F1;a_P[3]=a_F3;a_1041(7,-1,4,a_P);return;
} /* checkcalibre */
static void a_1196(int a_F1,int a_F2,int a_F3){ /* ftableaffix+>a+>a+>a */
int a_L4;int a_P[1];
if(!a_1155(a_P)){ goto a_G5;}a_L4=a_P[0];
if(!a_1202(a_L4)){ goto a_G4;}
a_1166(a_F1,a_F3,a_L4);return;
a_G4:a_1159(a_F1,a_F2,a_L4);return;
a_G5:a_1159(a_F1,a_F2,0);
a_1236();return;
} /* ftableaffix */
static void a_1195(int a_F1,int a_F2,int a_F3){ /* fstackaffix+>a+>a+>a */
int a_L4;int a_L5;int a_P[1];
if(!a_1155(a_P)){ goto a_G11;}a_L4=a_P[0];
a_1058(a_L4,a_P);a_L5=a_P[0];
{ if(a_L5==16777554){ goto a_G4;}
 if(a_L5==16777596){ goto a_G7;}
 if(a_L5==16777548){  goto a_G6;}
  goto a_G5;}
a_G4:if(!a_1205(a_L4,8)){ goto a_G6;}
a_G5:a_1159(a_F1,a_F2,a_L4);return;
a_G6:a_1166(a_F1,a_F3,a_L4);return;
a_G7:a_1229(a_L4,8); goto a_G6;
a_G11:a_1159(a_F1,a_F2,0);
a_1236();return;
} /* fstackaffix */
static void a_1193(int a_F1){ /* fshiftaffix+>a */
int a_L2;int a_L3;int a_P[2];
if(!a_1155(a_P)){ goto a_G5;}a_L2=a_P[0];
a_1058(a_L2,a_P);a_L3=a_P[0];
if(__equal(a_L3,16777629)){return;}
a_P[0]=2093832809;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G5:a_P[0]=2093832809;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_1236();return;
} /* fshiftaffix */
static int a_1240(int a_F1){ /* ureadonly+>a */

if(!__mreq(a_F1,4530946)){ return 0;} return 1;
} /* ureadonly */
static void a_1242(int a_F1,int a_A[1]){ /* uslicetype+>a+a> */

{ if(!(a_F1==4530944||a_F1==4530948)){ goto a_G3;}
}
a_A[0]=4530948;return;
a_G3:a_A[0]=4530947;return;
} /* uslicetype */
static void a_1217(int a_F1,int a_F2,int a_F3){ /* pushBUFFER+>a+>a+>a */

a_1189(a_F1);
a_1189(a_F2);
a_1189(a_F3);return;
} /* pushBUFFER */
static void a_1170(int a_F1,int a_F2){ /* checkoutaffixes+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[1];
a_G1:if(__mreq(a_F2,to_LIST(a_1006)->aupb)){return;}
__incr(a_F2);
a_L3=to_LIST(a_1006)->offset[a_F2];
__incr(a_F2);
a_L4=to_LIST(a_1006)->offset[a_F2];
__incr(a_F2);
a_L5=to_LIST(a_1006)->offset[a_F2];
if(!__equal(a_L3,4530948)){ goto a_G11;}
if(a_1204(a_L5,2)){ goto a_G1;}
a_1160(a_F1,a_L4,a_L5); goto a_G1;
a_G11:a_1229(a_L5,2);
a_1058(a_L5,a_P);a_L6=a_P[0];
if(__equal(a_L6,16777650)){ goto a_G1;}
a_1229(a_L5,8); goto a_G1;
} /* checkoutaffixes */
static void a_1199(int a_F1,int a_A[1]){ /* getftype+>a+a> */
int a_P[1];
a_1058(a_F1,a_P);a_A[0]=a_P[0];
if(!__equal(a_A[0],16777554)){ goto a_G6;}
if(!a_1205(a_F1,8)){ goto a_G5;}
a_A[0]=16777544;return;
a_G5:a_A[0]=16777548;return;
a_G6:if(!__equal(a_A[0],16777540)){return;}
if(!a_1205(a_F1,8)){ goto a_G9;}
a_A[0]=16777525;return;
a_G9:a_A[0]=16777535;return;
} /* getftype */
static void a_1194(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* fsimpleaffix+>a+>a+>a+a> */
int a_L5;int a_L6;int a_L7;int a_P[4];
if(!a_1029(a_P)){ goto a_G5;}
a_A[0]=0;
if(__equal(a_F3,4530946)){return;}
a_1183(a_F1,a_F2);return;
a_G5:if(a_1025(2106125362)){ goto a_G9;}
if(a_1025(2106125366)){ goto a_G9;}
if(a_1025(2106125294)){ goto a_G9;}
if(!a_1025(2106125358)){ goto a_G15;}
a_G9:a_A[0]=0;
a_1213(a_P);a_L5=a_P[0];
if(a_1202(a_L5)){ goto a_G13;}
a_1214(a_F1,a_F2,a_L5);
a_G13:if(a_1240(a_F3)){return;}
a_G14:a_1186(a_F1,a_F2,a_L5);return;
a_G15:if(!a_1025(2106125229)){ goto a_G22;}
a_A[0]=0;
a_1213(a_P);a_L5=a_P[0];
if(a_1202(a_L5)){ goto a_G20;}
a_1214(a_F1,a_F2,a_L5);
a_G20:if(__equal(a_F3,4530946)){return;} goto a_G14;
a_G22:if(!a_1025(2106125346)){ goto a_G38;}
a_1213(a_P);a_L5=a_P[0];
a_1242(a_F3,a_P);a_L6=a_P[0];
a_1194(a_F1,a_F2,a_L6,a_P);a_A[0]=a_P[0];
a_1071(2106125224);
a_1220(a_F1,a_F2,a_P);
a_1199(a_L5,a_P);a_L6=a_P[0];
{ if(a_L6==16777544||a_L6==16777602){ goto a_G30;}
 if(a_L6==16777548){ goto a_G32;}
 if(a_L6==16777596){  goto a_G34;}
  goto a_G37;}
a_G30:if(a_1240(a_F3)){return;}
a_G31:a_1187(a_F1,a_F2,a_L5);return;
a_G32:if(a_1240(a_F3)){return;}
a_A[0]=1;return;
a_G34:if(a_1240(a_F3)){return;}
a_A[0]=1;
a_G36:a_1229(a_L5,8);return;
a_G37:a_1214(a_F1,a_F2,a_L5);return;
a_G38:if(!a_1025(2106125305)){ goto a_G42;}
a_A[0]=0;
if(__equal(a_F3,4530944)){return;}
a_1188(a_F1,a_F2);return;
a_G42:a_A[0]=0;
a_1074(a_P);a_L5=a_P[0];
if(!__was(a_1022,a_L5)){ goto a_G47;}
if(__equal(a_F3,4530944)){ goto a_G47;}
a_1229(a_L5,1);
a_G47:a_1199(a_L5,a_P);a_L6=a_P[0];
{ if(a_L6==16777544||a_L6==16777602){ goto a_G49;}
 if(a_L6==16777548){ goto a_G52;}
 if(a_L6==16777596){ goto a_G55;}
 if(a_L6==16777525){ goto a_G59;}
 if(a_L6==16777566){ goto a_G30;}
 if(a_L6==16777535){ goto a_G32;}
 if(a_L6==16777612){ goto a_G68;}
 if(a_L6==16777623){ goto a_G74;}
 if(a_L6==16777617||a_L6==16777650){  goto a_G76;}
  goto a_G84;}
a_G49:a_1171(a_F1,a_F2,a_L5); goto a_G30;
a_G52:a_1171(a_F1,a_F2,a_L5); goto a_G32;
a_G55:a_1171(a_F1,a_F2,a_L5); goto a_G34;
a_G59:if(__equal(a_F3,4530946)){return;}
if(!a_1240(a_F3)){ goto a_G31;}
a_1243(a_F1,a_F2,a_P);a_L7=a_P[0];
a_P[0]=2093832770;a_P[1]=a_L7;a_P[2]=a_F1;a_P[3]=a_L5;a_1041(2,-1,4,a_P);return;
a_G68:if(a_1240(a_F3)){return;}
a_1229(a_L5,8);
if(!a_1205(a_1225,128)){ goto a_G72;}
a_P[0]=2093832824;a_P[1]=a_F1;a_P[2]=a_L5;a_1040(-1,3,a_P);return;
a_G72:if(!a_1204(a_L5,4096)){return;}
a_P[0]=2093832840;a_P[1]=a_F1;a_P[2]=a_L5;a_1040(-1,3,a_P);return;
a_G74:if(a_1240(a_F3)){return;} goto a_G36;
a_G76:if(__equal(a_F3,4530944)){ goto a_G78;}
if(!__equal(a_F3,4530948)){ goto a_G79;}
a_G78:a_1217(a_F3,a_F2,a_L5);return;
a_G79:if(a_1204(a_L5,2)){ goto a_G81;}
a_1160(a_F1,a_F2,a_L5);
a_G81:if(a_1240(a_F3)){return;}
if(__equal(a_L6,16777650)){return;} goto a_G36;
a_G84:a_1159(a_F1,a_F2,a_L5);return;
} /* fsimpleaffix */
static void a_1206(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* matchformalactual+>a+>a+>a+a> */
int a_L5;int a_P[1];
a_1058(a_F3,a_P);a_L5=a_P[0];
{ if(a_L5==16777607){ goto a_G3;}
 if(a_L5==16777602){ goto a_G5;}
 if(a_L5==16777596){ goto a_G7;}
 if(a_L5==16777635){ goto a_G9;}
 if(a_L5==16777612){ goto a_G11;}
 if(a_L5==16777617){ goto a_G12;}
 if(a_L5==16777623){  goto a_G13;}
  goto a_G14;}
a_G3:a_1192(a_F1,a_F2);
a_G4:a_A[0]=0;return;
a_G5:a_1196(a_F1,a_F2,a_F3); goto a_G4;
a_G7:a_1195(a_F1,a_F2,a_F3);
a_A[0]=1;return;
a_G9:a_1193(a_F1); goto a_G4;
a_G11:a_1194(a_F1,a_F2,4530946,a_P);a_A[0]=a_P[0];return;
a_G12:a_1194(a_F1,a_F2,4530944,a_P);a_A[0]=a_P[0];return;
a_G13:a_1194(a_F1,a_F2,4530945,a_P);a_A[0]=a_P[0];return;
a_G14:a_1063(a_1001,16777327,620);return;
} /* matchformalactual */
static int a_1180(int a_F1,int a_F2){ /* compatiblerepeatblocktypes+>a+>a */

if(__equal(a_F2,a_F1)){ return 1;}
if(!__equal(a_F2,16777602)){ goto a_G4;}
if(!__equal(a_F1,16777596)){ return 0;} return 1;
a_G4:if(!__equal(a_F2,16777612)){ goto a_G6;}
a_G5:if(!__equal(a_F1,16777623)){ return 0;} return 1;
a_G6:if(!__equal(a_F2,16777617)){ return 0;} goto a_G5;
} /* compatiblerepeatblocktypes */
static void a_1207(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* matchrepeataffixes+>a+>a+>a+>a> */
int a_L5;int a_L6;int a_L7;int a_P[6];
a_1198(a_F1,a_P);a_L7=a_P[0];
a_G2:a_1050(a_F3,a_P);a_F3=a_P[0];
__next(a_1022,a_F2);
a_1058(a_F2,a_P);a_L5=a_P[0];
if(!__equal(a_F3,0)){ goto a_G8;}
if(__equal(a_L5,16777654)){return;}
a_G7:a_P[0]=2093832853;a_P[1]=a_F1;a_P[2]=a_L7;a_1040(-1,3,a_P);return;
a_G8:if(__equal(a_L5,16777654)){ goto a_G7;}
a_1058(a_F3,a_P);a_L6=a_P[0];
if(!a_1180(a_L5,a_L6)){ goto a_G23;}
a_1229(a_F2,1);
if(!__equal(a_L6,16777596)){ goto a_G16;}
a_A[0]=1;
a_G15:a_1229(a_F2,8); goto a_G2;
a_G16:if(!__equal(a_L5,16777617)){ goto a_G19;}
a_1229(a_F2,8);
a_1229(a_F2,2); goto a_G2;
a_G19:if(__equal(a_L6,16777617)){ goto a_G15;}
if(__equal(a_L6,16777623)){ goto a_G15;} goto a_G2;
a_G23:a_P[0]=2093832875;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L5;a_P[4]=a_L6;a_P[5]=a_L7;a_1040(-1,6,a_P);return;
} /* matchrepeataffixes */
static int a_1156(int a_F1,int a_F2,int a_A[1]){ /* actualrepeataffix+>a+>a+>a> */
int a_L4;int a_L5;int a_L6;int a_L7;int a_P[3];
a_1086(a_P);a_L4=a_P[0];a_L5=a_P[1];
if(!a_1025(2106125321)){ goto a_G11;}
if(!a_1037(a_P)){ goto a_G11;}a_L6=a_P[0];
a_1058(a_L6,a_P);a_L7=a_P[0];
if(!__equal(a_L7,16777629)){ goto a_G11;}
a_1229(a_L6,1);
a_1229(a_L6,2);
if(a_1204(a_L6,8)){ goto a_G10;}
a_P[0]=2093832632;a_P[1]=a_F1;a_P[2]=a_L6;a_1041(4,-1,3,a_P);
a_G10:a_P[0]=a_A[0];a_1207(a_F1,a_L6,a_F2,a_P);a_A[0]=a_P[0]; return 1;
a_G11:a_1084(a_L4,a_L5); return 0;
} /* actualrepeataffix */
static void a_1169(int a_F1){ /* checkmacrorule+>a */
int a_P[2];
if(!a_1205(a_1225,128)){return;}
if(!__equal(a_F1,a_1225)){ goto a_G4;}
a_P[0]=2093832888;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G4:if(!a_1205(a_F1,131072)){return;}
a_P[0]=2093832898;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* checkmacrorule */
static void a_1157(int a_A[3]){ /* actualrule+a>+a>+>a> */
int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_L10;int a_L11;int a_P[4];
a_A[0]=1;a_A[1]=1;
a_1074(a_P);a_L4=a_P[0];
a_1058(a_L4,a_P);a_L5=a_P[0];
a_1198(a_L4,a_P);a_L10=a_P[0];
if(!__equal(a_L5,16777520)){ goto a_G8;}
a_P[0]=2093832665;a_P[1]=a_L4;a_1040(-1,2,a_P);
a_G7:a_1235();return;
a_G8:if(!__noteq(a_L5,16777580)){ goto a_G11;}
a_P[0]=2093832907;a_P[1]=a_L4;a_P[2]=a_L5;a_P[3]=a_L10;a_1040(-1,4,a_P); goto a_G7;
a_G11:a_1169(a_L4);
if(!__equal(a_L4,483807568)){ goto a_G14;}
a_1223(a_L4);
a_G14:if(!a_1205(a_L4,1024)){ goto a_G16;}
a_A[0]=0;
a_G16:if(a_1205(a_L4,512)){ goto a_G18;}
a_A[1]=0;
a_G18:if(!a_1205(a_L4,256)){ goto a_G20;}
a_A[2]=1;
a_G20:a_1050(a_L4,a_P);a_L6=a_P[0];
a_L7=0;
a_L8=1;
a_L11=to_LIST(a_1006)->aupb;
a_G24:if(!__equal(a_L6,0)){ goto a_G31;}
if(!a_1027(2106125321)){ goto a_G43;}
if(!__equal(a_L7,0)){ goto a_G29;}
a_P[0]=2093832919;a_P[1]=a_L4;a_P[2]=a_L10;a_1040(-1,3,a_P);
a_1235(); goto a_G43;
a_G29:a_P[0]=a_A[2];if(a_1156(a_L4,a_L7,a_P)){a_A[2]=a_P[0]; goto a_G43;}
a_1050(a_L7,a_P);a_L6=a_P[0]; goto a_G24;
a_G31:a_1058(a_L6,a_P);a_L5=a_P[0];
if(!__equal(a_L5,16777629)){ goto a_G36;}
a_P[0]=a_A[2];if(a_1156(a_L4,a_L6,a_P)){a_A[2]=a_P[0]; goto a_G43;}
a_L7=a_L6;
a_G35:a_1050(a_L6,a_P);a_L6=a_P[0]; goto a_G24;
a_G36:if(!a_1025(2106125321)){ goto a_G42;}
a_1206(a_L4,a_L8,a_L6,a_P);a_L9=a_P[0];
if(!__is(a_L9)){ goto a_G40;}
a_A[2]=1;
a_G40:__incr(a_L8); goto a_G35;
a_G42:a_P[0]=2093832931;a_P[1]=a_L4;a_P[2]=a_L10;a_1040(-1,3,a_P);
a_G43:a_1170(a_L4,a_L11);
__unstackto(a_1006,a_L11);return;
} /* actualrule */
static void a_1167(int a_F1,int a_F2){ /* checkextensionblock+>a+>a */
int a_L3;int a_L4;int a_L5;int a_P[4];
a_L3=to_LIST(a_1006)->aupb;
a_L5=0;
if(!__equal(to_LIST(a_1006)->offset[a_L3],0)){ goto a_G5;}
a_G4:a_P[0]=2093832964;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G5:if(__lseq(a_F2,a_L5)){ goto a_G9;}
if(__equal(to_LIST(a_1006)->offset[a_L3],0)){ goto a_G9;}
__decr(a_L3);
__incr(a_L5); goto a_G5;
a_G9:a_L4=a_L5;
a_G10:if(__lseq(a_F2,a_L5)){ goto a_G14;}
if(!__equal(to_LIST(a_1006)->offset[a_L3],0)){ goto a_G14;}
__decr(a_L3);
__incr(a_L5); goto a_G10;
a_G14:if(__less(a_L5,a_F2)){ goto a_G4;}
if(!__less(a_L4,a_L5)){return;}
a_P[0]=2093832981;a_P[1]=a_F1;a_P[2]=a_L4;a_P[3]=a_F2;a_1041(3,-1,4,a_P);return;
} /* checkextensionblock */
static void a_1239(int a_F1,int a_F2){ /* transportdest+>a+>a */
int a_L3;int a_L4;int a_P[3];
a_G1:if(!a_1025(2106125354)){return;}
a_1220(a_F1,0,a_P);a_L3=a_P[0];
if(__lseq(a_L3,0)){ goto a_G1;}
if(!__less(a_F2,a_L3)){ goto a_G6;}
a_1063(a_1001,16777320,754);return;
a_G6:__subtr(to_LIST(a_1006)->aupb,a_L3,a_L4);
__incr(a_L4);
if(__equal(to_LIST(a_1006)->offset[a_L4],0)){ goto a_G10;}
a_P[0]=2093832954;a_P[1]=a_F1;a_P[2]=a_L3;a_1040(-1,3,a_P);
a_G10:to_LIST(a_1006)->offset[a_L4]=1; goto a_G1;
} /* transportdest */
static void a_1238(int a_F1,int a_F2){ /* transport+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_L3=to_LIST(a_1006)->aupb;
a_L4=a_F2;
a_G3:a_1189(0);
__decr(a_L4);
if(__more(a_L4,0)){ goto a_G3;}
a_G6:a_1194(a_F1,0,4530946,a_P);
a_1239(a_F1,a_F2);
if(a_1025(2106125252)){ goto a_G10;}
if(!a_1025(2106125263)){ goto a_G6;}
a_G10:a_1167(a_F1,a_F2);
__unstackto(a_1006,a_L3);return;
} /* transport */
static void a_1191(void){ /* extension */
int a_L1;int a_L2;int a_L3;int a_P[3];
a_1213(a_P);a_L1=a_P[0];
a_1058(a_L1,a_P);a_L2=a_P[0];
{ if(a_L2==16777554){ goto a_G4;}
 if(a_L2==16777548){ goto a_G6;}
 if(a_L2==16777596){ goto a_G10;}
 if(a_L2==16777520){  goto a_G15;}
  goto a_G17;}
a_G4:if(!a_1205(a_L1,8)){ goto a_G6;}
a_P[0]=2093832942;a_P[1]=a_L1;a_P[2]=a_L2;a_1040(-1,3,a_P);return;
a_G6:a_1197(a_L1,a_P);a_L3=a_P[0];
a_1238(a_L1,a_L3);return;
a_G10:a_1200(a_L1,a_P);a_L3=a_P[0];
if(__more(a_L3,0)){ goto a_G13;}
a_L3=1;
a_G13:a_1238(a_L1,a_L3);
a_1229(a_L1,8);return;
a_G15:a_P[0]=2093832665;a_P[1]=a_L1;a_1040(-1,2,a_P);
a_G16:a_1034(2106125263);return;
a_G17:a_P[0]=2093832942;a_P[1]=a_L1;a_P[2]=a_L2;a_1040(-1,3,a_P); goto a_G16;
} /* extension */
static void a_1219(void){ /* readbox */
int a_P[1];
a_1194(0,0,4530946,a_P);
a_1071(2106125221);return;
} /* readbox */
static void a_1173(int a_F1,int a_F2){ /* checkzonemember+>a+>a */
int a_L3;int a_L4;int a_P[4];
if(__equal(a_F1,0)){return;}
a_1058(a_F1,a_P);a_L3=a_P[0];
a_1198(a_F1,a_P);a_L4=a_P[0];
if(!__equal(a_L3,16777520)){ goto a_G6;}
a_P[0]=2093832665;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G6:if(!a_1205(a_F1,16)){ goto a_G8;}
a_P[0]=2093832994;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G8:if(__equal(a_L3,16777525)){return;}
if(__equal(a_L3,16777566)){return;}
if(!__is(a_F2)){ goto a_G14;}
if(__equal(a_L3,16777544)){return;}
if(__equal(a_L3,16777548)){return;}
if(__equal(a_L3,16777554)){return;}
a_G14:a_P[0]=2093833005;a_P[1]=a_F1;a_P[2]=a_L3;a_P[3]=a_L4;a_1040(-1,4,a_P);return;
} /* checkzonemember */
static void a_1172(int a_F1,int a_F2){ /* checkzoneinterval+>a+>a */

a_1173(a_F1,0);
a_1173(a_F2,0);return;
} /* checkzoneinterval */
static void a_1175(int a_A[1]){ /* classifier+>a> */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_G1:a_L2=0;a_L3=0;a_L4=0;
if(a_1029(a_P)){ goto a_G5;}
if(a_1037(a_P)){a_L2=a_P[0]; goto a_G5;}
__incr(a_L4);
a_G5:if(!a_1025(2106125235)){ goto a_G10;}
if(a_1029(a_P)){ goto a_G9;}
if(a_1037(a_P)){a_L3=a_P[0]; goto a_G9;}
__incr(a_L4);
a_G9:a_1172(a_L2,a_L3); goto a_G11;
a_G10:a_1173(a_L2,1);
a_G11:if(__less(a_L4,2)){ goto a_G13;}
a_A[0]=1;
a_G13:if(a_1025(2106125340)){ goto a_G1;}
a_1071(2106125217);return;
} /* classifier */
static void a_1174(int a_F1,int a_A[6]){ /* classification+>a+a>+a>+>a>+a>+a>+a> */
int a_L8;int a_L9;int a_L10;int a_L11;int a_L12;int a_L13;int a_L14;int a_L15;int a_P[6];
a_A[0]=0;a_A[1]=0;a_A[4]=0;a_A[5]=0;
a_A[3]=0;
a_L15=a_A[2];
a_G4:a_L14=0;
a_1071(2106125217);
a_P[0]=a_L14;a_1175(a_P);a_L14=a_P[0];
a_L8=1;
a_L12=0;
a_L10=a_L15;
a_1176(a_F1,65536);
a_P[0]=a_L8;a_P[2]=a_L10;a_P[4]=a_L12;a_1162(a_F1,a_P);a_L8=a_P[0];a_L9=a_P[1];a_L10=a_P[2];a_L11=a_P[3];a_L12=a_P[4];a_L13=a_P[5];
if(!__is(a_L8)){ goto a_G15;}
a_A[0]=1;
__max(a_L10,a_A[2]);
a_G15:if(!__is(a_L9)){ goto a_G18;}
a_A[1]=1;
__max(a_L11,a_A[3]);
a_G18:if(__equal(a_L12,0)){ goto a_G23;}
if(__lseq(a_F1,a_L12)){ goto a_G23;}
if(!__equal(a_A[4],0)){ goto a_G22;}
a_A[4]=a_L12; goto a_G23;
a_G22:__min(a_L12,a_A[4]);
a_G23:if(__equal(a_L13,0)){ goto a_G28;}
if(__lseq(a_F1,a_L13)){ goto a_G28;}
if(!__equal(a_A[5],0)){ goto a_G27;}
a_A[5]=a_L13; goto a_G28;
a_G27:__min(a_L13,a_A[5]);
a_G28:a_1210(a_F1,a_L8,a_L9);
if(!a_1025(2106125340)){return;}
a_1231(a_F1);
if(!__is(a_L14)){ goto a_G4;}
a_P[0]=2093833015;a_1040(-1,1,a_P); goto a_G4;
} /* classification */
static void a_1182(int a_A[6]){ /* compoundmember+a>+a>+>a>+a>+a>+a> */
int a_P[6];
__incr(a_1181);
a_P[2]=a_A[2];a_1224(a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2];a_A[3]=a_P[3];a_A[4]=a_P[4];a_A[5]=a_P[5];
a_1071(2106125232);
__decr(a_1181);return;
} /* compoundmember */
static void a_1209(int a_F1,int a_A[6]){ /* member+>a+a>+a>+>a>+a>+a>+a> */
int a_L8;int a_P[6];
a_A[4]=0;a_A[5]=0;a_A[1]=0;
a_A[0]=1;
a_A[3]=a_A[2];
if(!a_1025(2106125312)){ goto a_G6;}
a_P[2]=a_A[2];a_1182(a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2];a_A[3]=a_P[3];a_A[4]=a_P[4];a_A[5]=a_P[5];return;
a_G6:if(!a_1025(2106125263)){ goto a_G10;}
a_1191();
a_A[2]=1;
a_G9:a_1227(a_F1,65536);return;
a_G10:if(!a_1025(2106125275)){ goto a_G15;}
a_1213(a_P);a_L8=a_P[0];
a_A[0]=0;
a_1168(a_L8);
a_1230(a_A[2],to_LIST(a_1022)->offset[a_L8-1],a_P);a_A[4]=a_P[0];a_A[5]=a_P[1];return;
a_G15:if(a_1025(2106125321)){return;}
if(!a_1025(2106125302)){ goto a_G20;}
a_1184();
a_A[1]=1;
a_A[0]=0;return;
a_G20:a_1184();
a_P[2]=a_A[2];a_1157(a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2]; goto a_G9;
} /* member */
static void a_1162(int a_F1,int a_A[6]){ /* alttail+>a+>a>+a>+>a>+a>+>a>+a> */
int a_L8;int a_L9;int a_L10;int a_L11;int a_P[6];
a_A[1]=0;a_A[3]=0;
a_L9=a_A[2];
a_A[5]=0;
a_1178(a_F1);
a_G5:if(!a_1025(2106125238)){ goto a_G26;}
if(!__equal(a_A[0],0)){ goto a_G9;}
a_L9=0;
a_P[0]=2093833024;a_1040(-1,1,a_P);
a_G9:if(__equal(a_A[4],0)){ goto a_G13;}
if(__less(a_F1,a_A[4])){ goto a_G13;}
__next(a_1007,a_A[4]);
a_P[0]=2093833032;a_P[1]=to_LIST(a_1007)->offset[a_A[4]];a_1040(-1,2,a_P);
a_G13:a_P[2]=a_L9;a_1209(a_F1,a_P);a_A[0]=a_P[0];a_L8=a_P[1];a_L9=a_P[2];a_L10=a_P[3];a_A[4]=a_P[4];a_L11=a_P[5];
if(!__is(a_A[0])){ goto a_G17;}
if(!__is(a_L9)){ goto a_G17;}
a_A[2]=1;
a_G17:if(!__is(a_L8)){ goto a_G21;}
__max(a_L10,a_A[3]);
a_1211(a_F1);
a_A[1]=1;
a_G21:if(__equal(a_L11,0)){ goto a_G5;}
if(__less(a_F1,a_L11)){ goto a_G5;}
if(!__equal(a_A[5],0)){ goto a_G25;}
a_A[5]=a_L11; goto a_G5;
a_G25:__min(a_L11,a_A[5]); goto a_G5;
a_G26:if(!__is(a_A[1])){return;}
a_1241(a_F1);return;
} /* alttail */
static void a_1161(int a_F1,int a_A[6]){ /* altsequence+>a+a>+a>+>a>+a>+a>+a> */
int a_L8;int a_L9;int a_L10;int a_L11;int a_L12;int a_L13;int a_L14;int a_L15;int a_L16;int a_P[6];
a_A[0]=0;a_A[1]=0;a_A[4]=0;a_A[5]=0;
a_A[3]=0;
a_L15=a_A[2];
a_G4:a_L10=a_L15;
a_P[2]=a_L10;a_1209(a_F1,a_P);a_L8=a_P[0];a_L14=a_P[1];a_L10=a_P[2];a_L11=a_P[3];a_L12=a_P[4];a_L16=a_P[5];
if(!__is(a_L14)){ goto a_G9;}
a_L15=a_L11;
a_1237(a_F1);
a_G9:a_P[0]=a_L8;a_P[2]=a_L10;a_P[4]=a_L12;a_1162(a_F1,a_P);a_L8=a_P[0];a_L9=a_P[1];a_L10=a_P[2];a_L11=a_P[3];a_L12=a_P[4];a_L13=a_P[5];
if(!__is(a_L8)){ goto a_G13;}
a_A[0]=1;
__max(a_L10,a_A[2]);
a_G13:if(!__is(a_L9)){ goto a_G16;}
a_A[1]=1;
__max(a_L11,a_A[3]);
a_G16:if(__equal(a_L12,0)){ goto a_G21;}
if(__lseq(a_F1,a_L12)){ goto a_G21;}
if(!__equal(a_A[4],0)){ goto a_G20;}
a_A[4]=a_L12; goto a_G21;
a_G20:__min(a_L12,a_A[4]);
a_G21:if(__equal(a_L13,0)){ goto a_G26;}
if(__lseq(a_F1,a_L13)){ goto a_G26;}
if(!__equal(a_A[5],0)){ goto a_G25;}
a_A[5]=a_L13; goto a_G26;
a_G25:__min(a_L13,a_A[5]);
a_G26:a_1210(a_F1,a_L8,a_L9);
if(!__is(a_L14)){ goto a_G29;}
a_1231(a_F1);
a_G29:if(!a_1025(2106125340)){ goto a_G36;}
if(__is(a_L14)){ goto a_G32;}
a_P[0]=2093833015;a_1040(-1,1,a_P);
a_G32:if(__equal(a_L16,0)){ goto a_G4;}
if(__less(a_F1,a_L16)){ goto a_G4;}
__next(a_1007,a_L16);
a_P[0]=2093833032;a_P[1]=to_LIST(a_1007)->offset[a_L16];a_1040(-1,2,a_P); goto a_G4;
a_G36:if(__equal(a_L16,0)){ goto a_G41;}
if(__lseq(a_F1,a_L16)){ goto a_G41;}
if(!__equal(a_A[5],0)){ goto a_G40;}
a_A[5]=a_L16; goto a_G41;
a_G40:__min(a_L16,a_A[5]);
a_G41:if(!__is(a_L14)){return;}
a_A[1]=1;
__max(a_L15,a_A[3]);
a_1184();
a_1210(a_F1,0,1);return;
} /* altsequence */
static void a_1224(int a_A[6]){ /* rulebody+a>+a>+>a>+a>+a>+a> */
int a_L7;int a_L8;int a_L9;int a_L10;int a_L11;int a_L12;int a_P[6];
a_L7=to_LIST(a_1022)->aupb;
a_1233(a_P);a_L8=a_P[0];
a_1234();
a_1215(a_A[2]);
a_L9=to_LIST(a_1007)->aupb;
a_1158(a_L8,a_L9);
a_1086(a_P);a_L10=a_P[0];a_L11=a_P[1];
a_G8:a_1104(a_P);a_L12=a_P[0];
if(!a_1025(2106125221)){ goto a_G12;}
a_1219();
a_P[2]=a_A[2];a_1174(a_L9,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2];a_A[3]=a_P[3];a_A[4]=a_P[4];a_A[5]=a_P[5]; goto a_G13;
a_G12:a_P[2]=a_A[2];a_1161(a_L9,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2];a_A[3]=a_P[3];a_A[4]=a_P[4];a_A[5]=a_P[5];
a_G13:if(a_1150(a_L12)){ goto a_G16;}
if(!a_1222(a_L9,a_A[0],a_A[1],a_P)){ goto a_G16;}a_A[2]=a_P[0];
a_1084(a_L10,a_L11); goto a_G8;
a_G16:a_1179(a_L9);
if(__is(a_A[0])){ goto a_G19;}
a_A[2]=0;
a_G19:if(__is(a_A[1])){ goto a_G21;}
a_A[3]=0;
a_G21:if(__lseq(to_LIST(a_1022)->aupb,a_L7)){return;}
if(a_1204(to_LIST(a_1022)->aupb,1)){ goto a_G27;}
if(!__equal(to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2],16777654)){ goto a_G26;}
if(__equal(a_1181,0)){ goto a_G27;}
a_P[0]=2093833048;a_P[1]=to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb];a_1041(4,-1,2,a_P); goto a_G27;
a_G26:a_P[0]=2093833041;a_P[1]=to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb];a_1041(4,-1,2,a_P);
a_G27:__unstack(a_1022); goto a_G21;
} /* rulebody */
static void a_1185(int a_F1){ /* dcheckrule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[6];
if(a_1205(a_F1,1)){ goto a_G3;}
a_P[0]=2093833055;a_P[1]=a_F1;a_1041(3,-1,2,a_P);
a_G3:__scratch(a_1007);
a_1181=0;
a_1225=a_F1;
a_1232(a_F1);
a_L4=0;
a_P[2]=a_L4;a_1224(a_P);a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];a_L5=a_P[3];
if(__equal(a_F1,483807562)){ goto a_G33;}
if(!a_1205(a_F1,1024)){ goto a_G14;}
if(__is(a_L2)){ goto a_G13;}
if(!__is(a_L3)){ goto a_G33;}
a_G13:a_P[0]=2093833065;a_P[1]=a_F1;a_1040(-1,2,a_P); goto a_G33;
a_G14:if(__is(a_L2)){ goto a_G17;}
a_L4=0;
a_P[0]=2093833073;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_G17:if(!__is(a_L3)){ goto a_G20;}
if(a_1205(a_F1,512)){ goto a_G23;}
a_P[0]=2093833080;a_P[1]=a_F1;a_1040(-1,2,a_P); goto a_G23;
a_G20:a_L5=0;
if(!a_1205(a_F1,512)){ goto a_G23;}
a_P[0]=2093833088;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_G23:if(!__is(a_L4)){ goto a_G26;}
if(a_1205(a_F1,256)){ goto a_G29;}
a_P[0]=2093833098;a_P[1]=a_F1;a_1040(-1,2,a_P); goto a_G29;
a_G26:if(__equal(a_L2,0)){ goto a_G29;}
if(!a_1205(a_F1,256)){ goto a_G29;}
a_P[0]=2093833109;a_P[1]=a_F1;a_1041(6,-1,2,a_P);
a_G29:if(!__is(a_L5)){ goto a_G33;}
if(!a_1205(a_F1,256)){ goto a_G32;}
a_P[0]=2093833123;a_P[1]=a_F1;a_1041(5,-1,2,a_P); goto a_G33;
a_G32:a_P[0]=2093833123;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_G33:if(__less(to_LIST(a_1022)->aupb,to_LIST(a_1022)->alwb)){ goto a_G68;}
if(__equal(to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2],16777635)){ goto a_G67;}
a_L7=to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb];
if(a_1204(to_LIST(a_1022)->aupb,1)){ goto a_G41;}
if(__equal(to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2],16777617)){ goto a_G41;}
if(!__equal(to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2],16777623)){ goto a_G40;}
a_P[0]=2093833134;a_P[1]=a_F1;a_P[2]=a_L7;a_1041(2,-1,3,a_P); goto a_G41;
a_G40:a_P[0]=2093833134;a_P[1]=a_F1;a_P[2]=a_L7;a_1041(5,-1,3,a_P);
a_G41:{register int a_r1=to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2];
 if(a_r1==16777629){ goto a_G42;}
 if(a_r1==16777596){ goto a_G48;}
 if(a_r1==16777612){ goto a_G51;}
 if(a_r1==16777617){ goto a_G54;}
 if(a_r1==16777623){  goto a_G57;}
  goto a_G60;}
a_G42:a_L6=0;
if(a_1204(to_LIST(a_1022)->aupb,2)){ goto a_G61;}
if(!a_1204(to_LIST(a_1022)->aupb,8)){ goto a_G61;}
a_P[0]=2093833148;a_P[1]=a_F1;a_1041(4,-1,2,a_P);
if(!a_1205(a_F1,65536)){ goto a_G61;}
a_P[0]=2093833208;a_P[1]=a_F1;a_1040(-1,2,a_P); goto a_G61;
a_G48:a_L6=0;
if(a_1204(to_LIST(a_1022)->aupb,8)){ goto a_G61;}
a_P[0]=2093833162;a_P[1]=a_F1;a_P[2]=a_L7;a_1041(3,-1,3,a_P); goto a_G61;
a_G51:a_L6=a_L3;
if(!a_1204(to_LIST(a_1022)->aupb,8)){ goto a_G61;}
a_P[0]=2093833177;a_P[1]=a_F1;a_P[2]=a_L7;a_1041(2,-1,3,a_P); goto a_G61;
a_G54:a_L6=a_L3;
if(a_1204(to_LIST(a_1022)->aupb,2)){ goto a_G61;}
a_P[0]=2093833192;a_P[1]=a_F1;a_P[2]=a_L7;a_1040(-1,3,a_P); goto a_G61;
a_G57:a_L6=a_L3;
if(a_1204(to_LIST(a_1022)->aupb,8)){ goto a_G61;}
a_P[0]=2093833221;a_P[1]=a_F1;a_P[2]=a_L7;a_1041(3,-1,3,a_P); goto a_G61;
a_G60:a_L6=0;
a_G61:if(!__is(a_L6)){ goto a_G67;}
if(!a_1204(to_LIST(a_1022)->aupb,16)){ goto a_G67;}
if(!a_1205(a_F1,128)){ goto a_G65;}
a_L8=9; goto a_G66;
a_G65:a_L8=2;
a_G66:a_P[0]=2093833236;a_P[1]=a_F1;a_P[2]=a_L7;a_1041(a_L8,-1,3,a_P);
a_G67:__unstack(a_1022); goto a_G33;
a_G68:a_1071(2106125324);return;
} /* dcheckrule */
static void a_1154(void){ /* @root */

} /* @root */
static void a_1189(int a_F1){ /* extendBUFFER+>a */

 a_extension(a_1006,1);to_LIST(a_1006)->top[1]=a_F1;to_LIST(a_1006)->aupb+=1;
 return;
} /* extendBUFFER */
static void a_1190(int a_F1,int a_F2){ /* extendRULE+>a+>a */

 a_extension(a_1007,2);to_LIST(a_1007)->top[1]=a_F1;to_LIST(a_1007)->top[2]=a_F2;to_LIST(a_1007)->aupb+=2;
 return;
} /* extendRULE */
static void a_1270(int a_F1,int a_F2){ /* tagredefined+>a+>a */
int a_L3;int a_L4;int a_P[5];
a_1198(a_F1,a_P);a_L3=a_P[0];
a_1058(a_F1,a_P);a_L4=a_P[0];
if(!__more(a_L3,0)){ goto a_G5;}
a_P[0]=2093833262;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L4;a_P[4]=a_L3;a_1040(-1,5,a_P);return;
a_G5:a_P[0]=2093833272;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L4;a_1040(-1,4,a_P);return;
} /* tagredefined */
static void a_1255(int a_F1,int a_A[2]){ /* expectpath+>a+a>+a> */
int a_P[2];
a_A[1]=0;
if(!__equal(1454738938,a_1062)){ goto a_G5;}
a_1077();
__incr(a_A[1]);
a_G5:if(a_1260(a_P)){a_A[0]=a_P[0]; goto a_G8;}
a_A[0]=1516190318;
a_P[0]=2093833311;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_G8:a_1264(a_A[0],a_P);a_A[0]=a_P[0];
if(!__equal(1454738938,a_1062)){return;}
a_1077();
__add(a_A[1],2,a_A[1]);return;
} /* expectpath */
static void a_1257(void){ /* filearea */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
a_L3=0;
a_G2:if(!a_1261(a_P)){ goto a_G11;}a_L1=a_P[0];
__incr(a_L3);
a_1017(a_L1);
a_1259(a_L1,a_P);a_L4=a_P[0];
a_1015(a_L4);
a_1058(a_L1,a_P);a_L2=a_P[0];
{ if(!(a_L2==16777520||a_L2==16777544||a_L2==16777548||a_L2==16777554)){ goto a_G10;}
}
a_1271(a_L1); goto a_G12;
a_G10:a_P[0]=2093833323;a_P[1]=a_L1;a_P[2]=a_L2;a_1040(-1,3,a_P); goto a_G12;
a_G11:a_P[0]=2093833334;a_1040(-1,1,a_P);
a_G12:if(!__equal(a_L3,32)){ goto a_G14;}
a_P[0]=2093833344;a_P[1]=32;a_1040(-1,2,a_P);
a_G14:if(!__equal(1454738971,a_1062)){ goto a_G16;}
a_1077(); goto a_G2;
a_G16:a_1263(1454738950);return;
} /* filearea */
static void a_1258(int a_F1,int a_F2){ /* fileareadeclarer+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
a_L3=0;
a_1058(a_F1,a_P);a_L4=a_P[0];
if(__equal(a_L4,16777520)){ goto a_G7;}
if(__equal(a_L4,16777576)){ goto a_G7;}
a_1270(a_F1,16777576);
a_L3=1;
a_G7:a_P[0]=a_L3;a_1245(a_F1,a_F2,a_P);a_L3=a_P[0];
if(__is(a_L3)){ goto a_G10;}
a_1267(a_F1,16777576);
a_G10:a_1012(2106125267);
a_1017(a_F1);
a_1012(2106125346);
a_1257();
a_1012(2106125224);
a_1263(1454738932);
a_1255(a_F1,a_P);a_L5=a_P[0];a_L6=a_P[1];
a_1015(a_L6);
a_1017(483807556);
a_1017(a_L5);
a_1012(2106125324);return;
} /* fileareadeclarer */
static void a_1254(int a_F1,int a_F2,int a_F3){ /* declarer+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_L7;int a_P[2];
a_L5=0;
a_1058(a_F1,a_P);a_L6=a_P[0];
if(__equal(a_L6,16777520)){ goto a_G7;}
if(__equal(a_L6,a_F2)){ goto a_G7;}
a_1270(a_F1,a_F2);
a_L5=1;
a_G7:a_P[0]=a_L5;a_1245(a_F1,a_F3,a_P);a_L5=a_P[0];
if(__is(a_L5)){ goto a_G10;}
a_1267(a_F1,a_F2);
a_G10:a_1255(a_F1,a_P);a_L4=a_P[0];a_L7=a_P[1];
a_1012(2106125267);
a_1017(a_F1);
a_1015(a_L7);
a_1017(483807556);
a_1017(a_L4);
a_1012(2106125324);return;
} /* declarer */
static void a_1256(int a_F1,int a_F2,int a_F3){ /* externaldeclarer+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_P[3];
a_L5=0;
a_1058(a_F1,a_P);a_L6=a_P[0];
if(__equal(a_L6,16777520)){ goto a_G7;}
if(__equal(a_L6,a_F2)){ goto a_G7;}
a_1270(a_F1,a_F2);
a_L5=1;
a_G7:if(a_1260(a_P)){a_L4=a_P[0]; goto a_G12;}
a_L4=0;
a_L5=1;
a_P[0]=2093833251;a_P[1]=a_F2;a_P[2]=a_F1;a_1040(-1,3,a_P);
a_1268();
a_G12:a_P[0]=a_L5;a_1246(a_F1,a_F3,a_P);a_L5=a_P[0];
if(__is(a_L5)){return;}
a_1267(a_F1,a_F2);
a_1266(a_F1,a_L4);return;
} /* externaldeclarer */
static void a_1265(int a_F1,int a_F2,int a_F3){ /* prototype+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_P[1];
a_1114(3429890,a_P);a_L4=a_P[0];
a_1058(a_F1,a_P);a_L5=a_P[0];
a_L6=0;
if(__equal(a_L5,16777520)){ goto a_G8;}
if(__equal(a_L5,a_F2)){ goto a_G8;}
a_1270(a_F1,a_F2);
a_L6=1;
a_G8:if(__is(a_L6)){ goto a_G14;}
if(!__equal(a_L4,1)){ goto a_G11;}
a_P[0]=a_L6;a_1247(a_F1,a_F3,a_P);a_L6=a_P[0]; goto a_G14;
a_G11:if(!__equal(a_L4,2)){ goto a_G13;}
a_P[0]=a_L6;a_1249(a_F1,a_F3,a_P);a_L6=a_P[0]; goto a_G14;
a_G13:a_1248(a_F1,a_F3);
a_G14:if(__is(a_L6)){return;}
a_1267(a_F1,a_F2);return;
} /* prototype */
static void a_1252(int a_F2,int a_A[1]){ /* declaration+>a>+>a */
int a_L3;int a_L4;int a_P[3];
if(!a_1262(a_P)){ goto a_G27;}a_L3=a_P[0];a_L4=a_P[1];
if(!__equal(1454738932,a_1062)){ goto a_G11;}
a_1077();
if(!__equal(a_A[0],3)){ goto a_G7;}
a_G5:a_P[0]=2093833287;a_P[1]=a_F2;a_1040(-1,2,a_P);
a_G6:a_1268();return;
a_G7:if(!__equal(a_A[0],1)){ goto a_G9;}
a_1256(a_L3,a_F2,a_L4);return;
a_G9:a_A[0]=2;
a_1254(a_L3,a_F2,a_L4);return;
a_G11:if(!__equal(a_A[0],1)){ goto a_G14;}
a_P[0]=2093833300;a_P[1]=a_F2;a_P[2]=a_L3;a_1040(-1,3,a_P); goto a_G6;
a_G14:if(!__equal(a_F2,16777576)){ goto a_G22;}
if(!__equal(1454738947,a_1062)){ goto a_G22;}
a_1077();
if(__equal(a_A[0],3)){ goto a_G5;}
a_A[0]=2;
a_1258(a_L3,a_L4);return;
a_G22:if(__equal(a_A[0],2)){ goto a_G5;}
a_A[0]=3;
a_1265(a_L3,a_F2,a_L4);return;
a_G27:a_P[0]=2093833354;a_P[1]=a_F2;a_1040(-1,2,a_P);
a_1268();return;
} /* declaration */
static void a_1253(int a_F1,int a_F2){ /* declarationseries+>a+>a */
int a_P[1];
a_G1:a_P[0]=a_F1;a_1252(a_F2,a_P);a_F1=a_P[0];
if(!__equal(1454738968,a_1062)){ goto a_G4;}
a_1077(); goto a_G1;
a_G4:if(!__equal(1454738974,a_1062)){ goto a_G6;}
a_1077();return;
a_G6:a_1263(1454738974);
a_1269();return;
} /* declarationseries */
static void a_1251(int a_F1){ /* datafiledeclaration+>a */

a_1253(a_F1,16777576);return;
} /* datafiledeclaration */
static void a_1250(int a_F1){ /* charfiledeclaration+>a */

a_1253(a_F1,16777571);return;
} /* charfiledeclaration */
static void a_1244(void){ /* @root */

} /* @root */
static void a_1328(void){ /* openicefile */
int a_L1;int a_P[3];
a_1298();
if(!a_openfile(a_1273,119,a_1021,to_LIST(a_1021)->aupb)){ goto a_G4;}
a_1312(to_LIST(a_1021)->aupb);return;
a_G4:__getfileerror(a_1273,a_L1);
a_P[0]=2093833489;a_P[1]=to_LIST(a_1021)->aupb;a_P[2]=a_L1;a_1040(-1,3,a_P);return;
} /* openicefile */
static void a_1295(void){ /* closeicefile */

a_closefile(a_1273);return;
} /* closeicefile */
static void a_1300(void){ /* deleteicefile */

a_1295();
a_1298();
a_unlinkfile(a_1021,to_LIST(a_1021)->aupb);
a_1312(to_LIST(a_1021)->aupb);return;
} /* deleteicefile */
static void a_1334(void){ /* separator */

a_putchar(a_1273,32);return;
} /* separator */
static void a_1326(void){ /* nlcr */

a_putchar(a_1273,10);return;
} /* nlcr */
static void a_1329(int a_F1){ /* printint+>a */

if(!__equal(a_F1,(-2147483647-1))){ goto a_G5;}
a_putchar(a_1273,45);
__subtr(-1,a_F1,a_F1);
a_1330(a_F1,49);return;
a_G5:if(!__less(a_F1,0)){ goto a_G8;}
a_putchar(a_1273,45);
__getabs(a_F1,a_F1);
a_G8:a_1330(a_F1,48);return;
} /* printint */
static void a_1330(int a_F1,int a_F2){ /* printint1+>a+>a */
int a_L3;int a_L4;
_divrem11(a_F1,10,a_L3,a_L4);
if(__equal(a_L3,0)){ goto a_G4;}
a_1330(a_L3,48);
a_G4:__add(a_L4,a_F2,a_L4);
a_putchar(a_1273,a_L4);return;
} /* printint1 */
static void a_1274(int a_F1){ /* W+>a */

{ if((2106125211<=a_F1 && a_F1<=2106125369)){ goto a_G2;}
 if((1848027345<=a_F1 && a_F1<=2093832544)){ goto a_G5;}
 if((1725124740<=a_F1 && a_F1<=1848027339)){  goto a_G11;}
  goto a_G17;}
a_G2:a_1332(a_1273,a_1014,a_F1);
if(!__equal(a_F1,2106125324)){return;}
a_putchar(a_1273,10);return;
a_G5:a_putchar(a_1273,73);
__subtr(a_F1,to_LIST(a_1019)->vlwb,a_F1);
__div(a_F1,6,a_F1);
a_G8:__incr(a_F1);
a_1329(a_F1);
a_1334();return;
a_G11:a_putchar(a_1273,78);
__subtr(a_F1,to_LIST(a_1024)->vlwb,a_F1);
__div(a_F1,5,a_F1); goto a_G8;
a_G17:a_1063(a_1001,16777344,154);return;
} /* W */
static void a_1275(int a_F1){ /* Wcons+>a */

a_1329(a_F1);
a_1334();return;
} /* Wcons */
static void a_1276(int a_F1){ /* Wline+>a */
int a_P[1];
a_P[0]=a_F1;a_1284(a_P);a_F1=a_P[0];
a_1329(a_F1);
a_1334();return;
} /* Wline */
static void a_1278(int a_F1){ /* Wtag+>a */
int a_L2;int a_P[1];
if(!__was(a_1020,a_F1)){ goto a_G5;}
a_1056(a_F1,a_P);a_L2=a_P[0];
if(__equal(a_L2,0)){return;}
a_1274(a_L2);return;
a_G5:if(!__was(a_1022,a_F1)){ goto a_G16;}
if(!__equal(to_LIST(a_1022)->offset[a_F1-2],16777650)){ goto a_G10;}
a_putchar(a_1273,76);
a_1329(to_LIST(a_1022)->offset[a_F1-1]);
a_G9:a_1334();return;
a_G10:a_putchar(a_1273,70);
__subtr(a_F1,to_LIST(a_1022)->alwb,a_L2);
__div(a_L2,6,a_L2);
__incr(a_L2);
a_1329(a_L2); goto a_G9;
a_G16:a_1063(a_1001,16777341,164);return;
} /* Wtag */
static void a_1277(int a_F1){ /* Wstring+>a */

{ if((1516190316<=a_F1 && a_F1<=1712834475)){ goto a_G2;}
 if((963127691<=a_F1 && a_F1<=1454738090)){  goto a_G4;}
  goto a_G7;}
a_G2:a_1331(a_1273,a_1021,a_F1);
a_G3:a_1326();return;
a_G4:__previous(a_1039,a_F1);
a_1331(a_1273,a_1039,a_F1); goto a_G3;
a_G7:a_1063(a_1001,16777337,170);return;
} /* Wstring */
static void a_1279(int a_F1){ /* Wtype+>a */

a_putchar(a_1273,60);
a_1332(a_1273,a_1018,a_F1);
a_putchar(a_1273,62);
a_1334();return;
} /* Wtype */
static void a_1284(int a_A[1]){ /* adjustlinenum+>a> */

if(__lseq(a_A[0],0)){return;}
__subtr(a_A[0],a_1286,a_A[0]);return;
} /* adjustlinenum */
static void a_1297(void){ /* createiceheader */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
if(!a_1321(3429903)){ goto a_G3;}
a_1274(2106125299); goto a_G4;
a_G3:a_1274(2106125350);
a_G4:a_1114(3429891,a_P);a_L1=a_P[0];
a_1277(a_L1);
a_1275(32);
a_1275(1000000);
a_1275(10000);
a_1326();
a_1310(a_P);a_1286=a_P[0];
__decr(a_1286);
a_L2=0;
a_G13:a_P[0]=a_L2;if(!a_1324(a_P)){ goto a_G16;}a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];
a_1276(a_L3);
a_1277(a_L4); goto a_G13;
a_G16:a_1274(2106125324);
a_1285();
a_1274(2106125324);
if(!a_1280()){return;}
a_1274(2106125324);return;
} /* createiceheader */
static void a_1315(int a_A[1]){ /* getnewitem+a> */

if(!__equal(a_1325,0)){ goto a_G3;}
{register int a_r1=to_LIST(a_1019)->alwb;a_1325=a_r1;a_A[0]=a_r1;}return;
a_G3:__next(a_1019,a_1325);
a_A[0]=a_1325;return;
} /* getnewitem */
static int a_1320(int a_F1,int a_F2){ /* isitemtag+>a+>a */

if(!__equal(a_F2,16777544)){ goto a_G4;}
if(a_1205(a_F1,256)){ return 1;}
if(!a_1205(a_F1,1)){ return 0;} return 1;
a_G4:if(!a_1205(a_F1,2)){ return 0;}
if(!a_1205(a_F1,1)){ return 0;}
if(!__equal(a_F2,16777580)){ return 1;}
if(a_1205(a_F1,4)){ return 1;}
if(!a_1205(a_F1,128)){ return 1;} return 0;
} /* isitemtag */
static void a_1322(int a_F1){ /* listdata+>a */
int a_L2;int a_P[1];
a_1197(a_F1,a_P);a_L2=a_P[0];
a_1275(a_L2);
a_1057(a_F1,a_P);a_L2=a_P[0];
a_1275(a_L2);return;
} /* listdata */
static void a_1313(int a_F1){ /* formalaffixes+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1050(a_F1,a_P);a_L3=a_P[0];
a_L2=0;
a_G3:if(__equal(a_L3,0)){ goto a_G6;}
__incr(a_L2);
a_1050(a_L3,a_P);a_L3=a_P[0]; goto a_G3;
a_G6:a_1050(a_F1,a_P);a_L3=a_P[0];
a_1275(a_L2);
a_G8:if(__equal(a_L3,0)){return;}
a_1058(a_L3,a_P);a_L4=a_P[0];
a_1279(a_L4);
if(__equal(a_L4,16777596)){ goto a_G13;}
if(!__equal(a_L4,16777602)){ goto a_G17;}
a_G13:a_1054(a_L3,a_P);a_L2=a_P[0];
a_1275(a_L2);
a_1055(a_L3,a_P);a_L2=a_P[0];
a_1275(a_L2);
a_G17:a_1050(a_L3,a_P);a_L3=a_P[0]; goto a_G8;
} /* formalaffixes */
static void a_1299(int a_F1){ /* defineicetag+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[3];
if(__equal(a_F1,0)){return;}
a_1311(a_F1);
a_1198(a_F1,a_P);a_L6=a_P[0];
a_1058(a_F1,a_P);a_L2=a_P[0];
if(!a_1320(a_F1,a_L2)){ goto a_G21;}
if(!a_1205(a_F1,16)){ goto a_G8;}
a_1056(a_F1,a_P);a_L5=a_P[0]; goto a_G9;
a_G8:a_1316(a_F1,a_P);a_L5=a_P[0];
a_G9:a_1317(a_F1,117540636,a_P);a_L4=a_P[0];
a_1315(a_P);a_L3=a_P[0];
a_1266(a_F1,a_L3);
a_1279(a_L2);
a_1274(a_L3);
a_1275(a_L4);
a_1276(a_L6);
{ if(a_L2==16777525||a_L2==16777535||a_L2==16777540||a_L2==16777566||a_L2==16777571||a_L2==16777576){ goto a_G20;}
 if(a_L2==16777544||a_L2==16777548||a_L2==16777554){ goto a_G17;}
 if(a_L2==16777580){  goto a_G18;}
  goto a_G19;}
a_G17:a_1322(a_F1); goto a_G20;
a_G18:a_1313(a_F1); goto a_G20;
a_G19:a_1063(a_1001,16777333,242);return;
a_G20:a_1277(a_L5);return;
a_G21:if(a_1205(a_F1,2)){return;}
if(!a_1205(a_F1,4)){ goto a_G25;}
a_P[0]=2093833367;a_P[1]=a_L2;a_P[2]=a_F1;a_1040(a_L6,3,a_P);
a_1294(a_F1,4);return;
a_G25:a_1267(a_F1,16777520);return;
} /* defineicetag */
static void a_1281(int a_F1){ /* Xstringtablefillinghead+>a */

a_1274(2106125271);
a_1278(a_F1);
a_1275(0);return;
} /* Xstringtablefillinghead */
static void a_1282(int a_F1,int a_F2){ /* Xstringtableitem+>a+>a */
int a_L3;
__stringwidth(a_1021,a_F2,a_L3);
__subtr(a_F2,a_L3,a_L3);
a_G3:if(!__less(a_L3,a_F2)){ goto a_G6;}
__incr(a_L3);
a_1275(to_LIST(a_1021)->offset[a_L3]); goto a_G3;
a_G6:a_1274(2106125235);
a_1278(a_F1);return;
} /* Xstringtableitem */
static void a_1337(int a_F1,int a_F2){ /* wrongtype+>a+>a */
int a_L3;int a_P[4];
a_1058(a_F1,a_P);a_L3=a_P[0];
if(!__equal(a_L3,16777520)){ goto a_G4;}
a_P[0]=2093833360;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G4:if(!__equal(a_F2,0)){ goto a_G6;}
a_P[0]=a_L3;a_P[1]=2093833382;a_P[2]=a_F1;a_1040(-1,3,a_P);return;
a_G6:a_P[0]=2093833374;a_P[1]=a_L3;a_P[2]=a_F1;a_P[3]=a_F2;a_1040(-1,4,a_P);return;
} /* wrongtype */
static void a_1327(int a_F1){ /* noexternal+>a */
int a_L2;int a_L3;int a_P[4];
a_1058(a_F1,a_P);a_L3=a_P[0];
if(!a_1205(a_F1,16)){ goto a_G5;}
a_1198(a_F1,a_P);a_L2=a_P[0];
a_P[0]=2093833410;a_P[1]=a_L3;a_P[2]=a_F1;a_P[3]=a_L2;a_1040(-1,4,a_P);return;
a_G5:if(!__equal(a_L3,16777520)){return;}
a_P[0]=2093833360;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* noexternal */
static void a_1305(void){ /* dlistsize */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
a_1074(a_P);a_L1=a_P[0];
if(!a_1205(a_L1,1)){ goto a_G18;}
a_1072(a_P);a_L2=a_P[0];
a_1274(2106125286);
a_1278(a_L1);
a_1275(a_L2);
if(!__lseq(a_L2,2)){ goto a_G10;}
a_1072(a_P);a_L3=a_P[0];
a_1275(a_L3); goto a_G16;
a_G10:a_1074(a_P);a_L3=a_P[0];
a_1058(a_L3,a_P);a_L4=a_P[0];
if(!__equal(a_L4,16777525)){ goto a_G15;}
a_1327(a_L3);
a_1278(a_L3); goto a_G16;
a_G15:a_1337(a_L3,16777525);
a_G16:a_1274(2106125324);
a_1071(2106125324);return;
a_G18:if(!a_1205(a_L1,256)){ goto a_G20;}
a_G19:a_1034(2106125324);return;
a_G20:a_1058(a_L1,a_P);a_L4=a_P[0];
a_P[0]=2093833388;a_P[1]=a_L4;a_P[2]=a_L1;a_1041(3,-1,3,a_P); goto a_G19;
} /* dlistsize */
static void a_1333(void){ /* repeater */
int a_L1;int a_L2;int a_P[1];
if(!a_1025(2106125343)){return;}
a_1274(2106125343);
if(!a_1029(a_P)){ goto a_G5;}a_L1=a_P[0];
a_1275(a_L1);return;
a_G5:a_1074(a_P);a_L1=a_P[0];
a_1058(a_L1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,16777525)){ goto a_G10;}
a_1327(a_L1);
a_1278(a_L1);return;
a_G10:a_1337(a_L1,16777525);return;
} /* repeater */
static void a_1318(void){ /* initializer */
int a_L1;int a_P[3];
a_G1:if(!a_1025(2106125235)){return;}
a_1074(a_P);a_L1=a_P[0];
if(!a_1205(a_L1,1)){ goto a_G6;}
a_1274(2106125235);
a_1278(a_L1); goto a_G1;
a_G6:a_P[0]=2093833388;a_P[1]=16777566;a_P[2]=a_L1;a_1041(3,-1,3,a_P); goto a_G1;
} /* initializer */
static void a_1292(int a_F1){ /* checklistitemtype+>a */
int a_L2;int a_P[1];
a_1058(a_F1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,16777525)){ goto a_G4;}
a_G3:a_1327(a_F1);return;
a_G4:if(__equal(a_L2,16777566)){ goto a_G3;}
a_1337(a_F1,16777525);return;
} /* checklistitemtype */
static void a_1296(int a_A[2]){ /* countblockitems+a>+a> */
int a_L3;int a_L4;int a_P[2];
a_A[0]=0;a_A[1]=0;
a_1086(a_P);a_L3=a_P[0];a_L4=a_P[1];
a_G3:if(!a_1025(2106125232)){ goto a_G5;}
a_1084(a_L3,a_L4);return;
a_G5:if(!a_1025(2106125343)){ goto a_G7;}
a_A[1]=1; goto a_G3;
a_G7:if(!a_1037(a_P)){ goto a_G9;}
a_G8:__incr(a_A[0]); goto a_G3;
a_G9:a_1072(a_P); goto a_G8;
} /* countblockitems */
static void a_1287(int a_F1){ /* block+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[4];
a_1197(a_F1,a_P);a_L2=a_P[0];
a_1296(a_P);a_L3=a_P[0];a_L4=a_P[1];
if(__equal(a_L3,a_L2)){ goto a_G9;}
if(!__more(a_L3,a_L2)){ goto a_G6;}
a_P[0]=2093833458;a_P[1]=a_F1;a_P[2]=a_L3;a_P[3]=a_L2;a_1041(6,-1,4,a_P); goto a_G9;
a_G6:if(!__noteq(a_L4,0)){ goto a_G8;}
__subtr(a_L2,a_L3,a_L4); goto a_G9;
a_G8:a_P[0]=2093833474;a_P[1]=a_F1;a_P[2]=a_L3;a_P[3]=a_L2;a_1041(4,-1,4,a_P);
a_G9:a_L5=0;a_L6=0;
a_G10:if(a_1025(2106125232)){return;}
if(!a_1037(a_P)){ goto a_G15;}a_L5=a_P[0];
a_1278(a_L5);
a_1292(a_L5);
a_L6=1; goto a_G10;
a_G15:if(!a_1025(2106125343)){ goto a_G21;}
a_G16:if(__lseq(a_L4,0)){ goto a_G10;}
__decr(a_L4);
if(!__equal(a_L6,1)){ goto a_G20;}
a_1278(a_L5); goto a_G16;
a_G20:a_1275(a_L5); goto a_G16;
a_G21:a_1072(a_P);a_L5=a_P[0];
a_1275(a_L5);
a_L6=0; goto a_G10;
} /* block */
static void a_1290(int a_F1,int a_F2){ /* checkblock2extension+>a+>a */
int a_L3;int a_L4;int a_L5;int a_P[4];
a_L5=0;
a_L3=to_LIST(a_1006)->aupb;
__decr(a_L3);
if(!__equal(to_LIST(a_1006)->offset[a_L3],0)){ goto a_G6;}
a_G5:a_P[0]=2093833442;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G6:if(__lseq(a_F2,a_L5)){ goto a_G10;}
if(__equal(to_LIST(a_1006)->offset[a_L3],0)){ goto a_G10;}
__incr(a_L5);
__subtr(a_L3,2,a_L3); goto a_G6;
a_G10:a_L4=a_L5;
a_G11:if(__lseq(a_F2,a_L5)){ goto a_G15;}
if(!__equal(to_LIST(a_1006)->offset[a_L3],0)){ goto a_G15;}
__subtr(a_L3,2,a_L3);
__incr(a_L5); goto a_G11;
a_G15:if(__less(a_L5,a_F2)){ goto a_G5;}
if(!__less(a_L4,a_L5)){return;}
a_P[0]=2093833474;a_P[1]=a_F1;a_P[2]=a_L4;a_P[3]=a_F2;a_1041(3,-1,4,a_P);return;
} /* checkblock2extension */
static void a_1289(int a_F1,int a_A[1]){ /* block2selector+>a+a> */
int a_L3;int a_L4;int a_P[3];
if(!a_1025(2106125343)){ goto a_G3;}
a_G2:a_A[0]=-1;return;
a_G3:a_1074(a_P);a_L3=a_P[0];
a_1056(a_L3,a_P);a_A[0]=a_P[0];
if(!__more(a_A[0],0)){ goto a_G11;}
__decr(a_A[0]);
__addmult(a_A[0],-2,to_LIST(a_1006)->aupb,a_L4);
__decr(a_L4);
if(__equal(to_LIST(a_1006)->offset[a_L4],0)){return;}
a_P[0]=2093833431;a_P[1]=a_F1;a_P[2]=a_L3;a_1040(-1,3,a_P);return;
a_G11:a_P[0]=2093833421;a_P[1]=a_F1;a_P[2]=a_L3;a_1040(-1,3,a_P); goto a_G2;
} /* block2selector */
static void a_1288(int a_F1){ /* block2+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[1];
a_L2=to_LIST(a_1006)->aupb;
a_1197(a_F1,a_P);a_L3=a_P[0];
a_L4=a_L3;
a_G4:a_1308(0);
a_1308(0);
__decr(a_L4);
if(!__equal(a_L4,0)){ goto a_G4;}
a_L6=0;a_L7=0;
a_G9:if(!a_1037(a_P)){ goto a_G12;}a_L4=a_P[0];
a_1292(a_L4);
a_L5=2; goto a_G14;
a_G12:a_1072(a_P);a_L4=a_P[0];
a_L5=1;
a_G14:if(!a_1025(2106125354)){ goto a_G23;}
a_1289(a_F1,a_P);a_L9=a_P[0];
if(!__less(a_L9,0)){ goto a_G19;}
a_L6=a_L4;
a_L7=a_L5; goto a_G14;
a_G19:__addmult(a_L9,-2,to_LIST(a_1006)->aupb,a_L8);
to_LIST(a_1006)->offset[a_L8]=a_L4;
__decr(a_L8);
to_LIST(a_1006)->offset[a_L8]=a_L5; goto a_G14;
a_G23:if(!a_1025(2106125263)){ goto a_G9;}
a_L8=a_L2;
a_G25:if(__equal(a_L7,0)){ goto a_G33;}
if(__mreq(a_L8,to_LIST(a_1006)->aupb)){ goto a_G33;}
__incr(a_L8);
if(!__equal(to_LIST(a_1006)->offset[a_L8],0)){ goto a_G32;}
to_LIST(a_1006)->offset[a_L8]=a_L7;
__incr(a_L8);
to_LIST(a_1006)->offset[a_L8]=a_L6; goto a_G25;
a_G32:__incr(a_L8); goto a_G25;
a_G33:a_1290(a_F1,a_L3);
a_L8=a_L2;
a_G35:if(__mreq(a_L8,to_LIST(a_1006)->aupb)){ goto a_G44;}
__incr(a_L8);
a_L5=to_LIST(a_1006)->offset[a_L8];
__incr(a_L8);
a_L4=to_LIST(a_1006)->offset[a_L8];
if(!__equal(a_L5,1)){ goto a_G42;}
a_1275(a_L4); goto a_G35;
a_G42:if(!__equal(a_L5,2)){ goto a_G35;}
a_1278(a_L4); goto a_G35;
a_G44:__unstackto(a_1006,a_L2);return;
} /* block2 */
static void a_1336(int a_F1){ /* writestring+>a */
int a_L2;
a_1274(2106125312);
__stringwidth(a_1021,a_F1,a_L2);
__subtr(a_F1,a_L2,a_L2);
a_G4:if(!__less(a_L2,a_F1)){ goto a_G7;}
__incr(a_L2);
a_1275(to_LIST(a_1021)->offset[a_L2]); goto a_G4;
a_G7:a_1274(2106125232);return;
} /* writestring */
static void a_1323(int a_F1){ /* listitem+>a */
int a_L2;int a_P[1];
if(!a_1037(a_P)){ goto a_G4;}a_L2=a_P[0];
a_1278(a_L2);
a_1292(a_L2);return;
a_G4:if(!a_1029(a_P)){ goto a_G6;}a_L2=a_P[0];
a_1275(a_L2);return;
a_G6:if(!a_1035(a_P)){ goto a_G8;}a_L2=a_P[0];
a_1336(a_L2);return;
a_G8:if(!a_1025(2106125312)){ goto a_G12;}
a_1274(2106125312);
a_1287(a_F1);
a_G11:a_1274(2106125232);return;
a_G12:a_1071(2106125263);
a_1274(2106125312);
a_1288(a_F1); goto a_G11;
} /* listitem */
static int a_1319(int a_F1){ /* isfilltagused+>a */
int a_L2;int a_P[3];
if(a_1205(a_F1,1)){ return 1;}
a_1058(a_F1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,16777544)){ goto a_G5;}
a_P[0]=2093833388;a_P[1]=a_L2;a_P[2]=a_F1;a_1041(3,-1,3,a_P); return 1;
a_G5:a_P[0]=2093833400;a_P[1]=a_L2;a_P[2]=a_F1;a_1040(-1,3,a_P); return 0;
} /* isfilltagused */
static void a_1304(void){ /* dlistfilling */
int a_L1;int a_L2;int a_P[1];
a_1074(a_P);a_L1=a_P[0];
if(!a_1319(a_L1)){ goto a_G13;}
a_1274(2106125271);
a_1278(a_L1);
a_1314(a_P);a_L2=a_P[0];
a_P[0]=a_L2;a_1284(a_P);a_L2=a_P[0];
a_1275(a_L2);
a_G8:if(!a_1025(2106125324)){ goto a_G10;}
a_1274(2106125324);return;
a_G10:a_1323(a_L1);
a_1333();
a_1318(); goto a_G8;
a_G13:a_1034(2106125324);return;
} /* dlistfilling */
static void a_1309(void){ /* filearea */
int a_L1;int a_L2;int a_P[1];
a_G1:if(!a_1025(2106125224)){ goto a_G3;}
a_1274(2106125224);return;
a_G3:a_1074(a_P);a_L1=a_P[0];
a_1058(a_L1,a_P);a_L2=a_P[0];
if(__equal(a_L2,16777544)){ goto a_G8;}
if(__equal(a_L2,16777548)){ goto a_G8;}
if(!__equal(a_L2,16777554)){ goto a_G9;}
a_G8:a_1327(a_L1); goto a_G10;
a_G9:a_1337(a_L1,0);
a_G10:a_1278(a_L1);
a_1072(a_P);a_L1=a_P[0];
a_1275(a_L1); goto a_G1;
} /* filearea */
static void a_1302(void){ /* dfiledata */
int a_L1;int a_L2;int a_P[3];
a_1074(a_P);a_L1=a_P[0];
if(!a_1205(a_L1,1)){ goto a_G16;}
a_1274(2106125267);
a_1278(a_L1);
if(!a_1025(2106125346)){ goto a_G8;}
a_1274(2106125346);
a_1309();
a_G8:a_1072(a_P);a_L2=a_P[0];
a_1275(a_L2);
a_1074(a_P);a_L2=a_P[0];
a_1278(a_L2);
a_1074(a_P);a_L2=a_P[0];
a_1278(a_L2);
a_1071(2106125324);
a_1274(2106125324);return;
a_G16:a_1058(a_L1,a_P);a_L2=a_P[0];
a_P[0]=2093833388;a_P[1]=a_L2;a_P[2]=a_L1;a_1041(3,-1,3,a_P);
a_1034(2106125324);return;
} /* dfiledata */
static void a_1291(int a_F1){ /* checkconstanttag+>a */
int a_L2;int a_P[1];
a_1058(a_F1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,16777525)){ goto a_G4;}
a_G3:a_1327(a_F1);return;
a_G4:if(__equal(a_L2,16777566)){ goto a_G3;}
a_1337(a_F1,16777525);return;
} /* checkconstanttag */
static void a_1293(int a_F1){ /* checklisttag+>a */
int a_L2;int a_P[1];
a_1058(a_F1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,16777544)){ goto a_G4;}
a_G3:a_1327(a_F1);return;
a_G4:if(__equal(a_L2,16777548)){ goto a_G3;}
if(__equal(a_L2,16777554)){ goto a_G3;}
a_1337(a_F1,0);return;
} /* checklisttag */
static void a_1307(void){ /* expression */

if(!a_1025(2106125302)){ goto a_G3;}
a_G2:a_1274(2106125302);
a_G3:a_1306();
if(!a_1025(2106125315)){ goto a_G6;}
a_1274(2106125315); goto a_G3;
a_G6:if(!a_1025(2106125213)){ goto a_G8;}
a_1274(2106125213); goto a_G3;
a_G8:if(!a_1025(2106125369)){ goto a_G10;}
a_1274(2106125369); goto a_G3;
a_G10:if(!a_1025(2106125321)){ goto a_G12;}
a_1274(2106125321); goto a_G3;
a_G12:if(a_1025(2106125302)){ goto a_G2;}
if(!a_1025(2106125343)){ goto a_G16;}
a_1274(2106125343); goto a_G3;
a_G16:if(!a_1025(2106125248)){return;}
a_1274(2106125248); goto a_G3;
} /* expression */
static void a_1306(void){ /* exprbase */
int a_L1;int a_P[1];
a_G1:if(!a_1029(a_P)){ goto a_G3;}a_L1=a_P[0];
a_1275(a_L1);return;
a_G3:if(!a_1037(a_P)){ goto a_G6;}a_L1=a_P[0];
a_1278(a_L1);
a_1291(a_L1);return;
a_G6:if(!a_1025(2106125241)){ goto a_G8;}
a_1274(2106125241); goto a_G1;
a_G8:if(!a_1025(2106125294)){ goto a_G13;}
a_1274(2106125294);
a_G10:a_1074(a_P);a_L1=a_P[0];
a_1278(a_L1);
a_1293(a_L1);return;
a_G13:if(!a_1025(2106125358)){ goto a_G18;}
a_1274(2106125358); goto a_G10;
a_G18:if(!a_1025(2106125229)){ goto a_G23;}
a_1274(2106125229); goto a_G10;
a_G23:a_1071(2106125312);
a_1274(2106125312);
a_1307();
a_1071(2106125232);
a_1274(2106125232);return;
} /* exprbase */
static void a_1301(void){ /* dexpression */
int a_L1;int a_L2;int a_P[3];
a_1074(a_P);a_L1=a_P[0];
if(!a_1205(a_L1,1)){ goto a_G8;}
a_1274(2106125258);
a_1278(a_L1);
a_1307();
a_1071(2106125324);
a_1274(2106125324);return;
a_G8:a_1058(a_L1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,16777525)){ goto a_G11;}
a_P[0]=2093833388;a_P[1]=a_L2;a_P[2]=a_L1;a_1041(1,-1,3,a_P); goto a_G12;
a_G11:a_P[0]=2093833388;a_P[1]=a_L2;a_P[2]=a_L1;a_1041(3,-1,3,a_P);
a_G12:a_1034(2106125324);return;
} /* dexpression */
static void a_1272(void){ /* @root */

} /* @root */
static void a_1308(int a_F1){ /* extendBUFFER+>a */

 a_extension(a_1006,1);to_LIST(a_1006)->top[1]=a_F1;to_LIST(a_1006)->aupb+=1;
 return;
} /* extendBUFFER */
static void a_1332(int a_F1,int a_F2,int a_F3){ /* putstring+""f+t[]+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=0;
a_G2:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){return;}a_L3=a_P[0];
__incr(a_L2);
a_putchar(a_F1,a_L3); goto a_G2;
} /* putstring */
static void a_1331(int a_F1,int a_F2,int a_F3){ /* putasstring+""f+t[]+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=0;
a_putchar(a_F1,34);
a_G3:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){ goto a_G8;}a_L3=a_P[0];
__incr(a_L2);
if(!__equal(a_L3,34)){ goto a_G7;}
a_putchar(a_F1,a_L3);
a_G7:a_putchar(a_F1,a_L3); goto a_G3;
a_G8:a_putchar(a_F1,34);return;
} /* putasstring */
static void a_1111(int a_F1,int a_A[2]){ /* findlinenum+>a+a>+a> */
int a_L4;int a_L5;int a_P[1];
if(__more(a_F1,0)){ goto a_G3;}
a_1314(a_P);a_F1=a_P[0];
a_G3:a_L4=to_LIST(a_1339)->alwb;
a_G4:__add(a_L4,3,a_L5);
if(__less(to_LIST(a_1339)->aupb,a_L5)){ goto a_G8;}
if(__less(to_LIST(a_1339)->offset[a_L5-1],0)){ goto a_G8;}
if(!__less(a_F1,to_LIST(a_1339)->offset[a_L5-1])){ goto a_G14;}
a_G8:__subtr(a_F1,to_LIST(a_1339)->offset[a_L4-1],a_A[0]);
__incr(a_A[0]);
if(!__equal(to_LIST(a_1339)->offset[a_L4-2],4865)){ goto a_G13;}
a_A[1]=1516190318;
a_A[0]=0;return;
a_G13:a_A[1]=to_LIST(a_1339)->offset[a_L4];return;
a_G14:a_L4=a_L5; goto a_G4;
} /* findlinenum */
static void a_1341(int a_F1,int a_A[1]){ /* addcommandlinearg+>a+>a> */
int a_L3;int a_P[3];
a_P[0]=a_A[0];if(!a_1351(a_F1,a_P)){ goto a_G3;}a_A[0]=a_P[0];
a_L3=4865; goto a_G4;
a_G3:a_L3=4866;
a_G4: a_extension(a_1339,3);to_LIST(a_1339)->top[1]=a_L3;to_LIST(a_1339)->top[2]=-1;to_LIST(a_1339)->top[3]=a_F1;to_LIST(a_1339)->aupb+=3;
 return;
} /* addcommandlinearg */
static int a_1349(int a_A[1]){ /* getfirstsource+a> */
int a_L2;
a_L2=to_LIST(a_1339)->alwb;
a_G2:if(__more(a_L2,to_LIST(a_1339)->aupb)){ return 0;}
if(!__equal(to_LIST(a_1339)->offset[a_L2-2],4866)){ goto a_G5;}
a_A[0]=to_LIST(a_1339)->offset[a_L2]; return 1;
a_G5:__next(a_1339,a_L2); goto a_G2;
} /* getfirstsource */
static int a_1364(int a_F1,int a_A[1]){ /* wassourceadded+>a+a> */
int a_L3;int a_P[1];
a_A[0]=to_LIST(a_1339)->aupb;
a_G2:if(__less(a_A[0],to_LIST(a_1339)->alwb)){ return 0;}
a_comparestring(a_1021,to_LIST(a_1339)->offset[a_A[0]],a_1021,a_F1,a_P);a_L3=a_P[0];
if(!__equal(a_L3,0)){ goto a_G6;}
if(__noteq(to_LIST(a_1339)->offset[a_A[0]-2],4865)){ return 1;}
a_G6:__previous(a_1339,a_A[0]); goto a_G2;
} /* wassourceadded */
static void a_1344(int a_F1,int a_F2){ /* addsource+>a+>a */
int a_L3;int a_P[2];
if(!a_1364(a_F1,a_P)){ goto a_G6;}a_L3=a_P[0];
if(!__equal(to_LIST(a_1339)->offset[a_L3-2],4866)){ goto a_G4;}
a_P[0]=2093833514;a_P[1]=a_F1;a_1041(8,-1,2,a_P);return;
a_G4:if(__equal(to_LIST(a_1339)->offset[a_L3-2],a_F2)){return;}
a_P[0]=2093833528;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G6: a_extension(a_1339,3);to_LIST(a_1339)->top[3]=a_F1;to_LIST(a_1339)->top[1]=a_F2;to_LIST(a_1339)->top[2]=-1;to_LIST(a_1339)->aupb+=3;
 return;
} /* addsource */
static void a_1343(int a_F1){ /* addrequiredsource+>a */

a_1344(a_F1,4867);return;
} /* addrequiredsource */
static void a_1342(int a_F1){ /* addincludedsource+>a */
int a_L2;int a_P[1];
a_1114(3429890,a_P);a_L2=a_P[0];
if(!a_1321(3429894)){ goto a_G4;}
__add(a_L2,8,a_L2);
a_G4:__add(a_L2,5104,a_L2);
a_1344(a_F1,a_L2);return;
} /* addincludedsource */
static void a_1362(int a_F1){ /* setpragmats+>a */
int a_L2;
__booland(a_F1,7,a_L2);
a_1363(3429890,a_L2);
__booland(a_F1,8,a_L2);
if(!__is(a_L2)){ goto a_G6;}
a_L2=1; goto a_G7;
a_G6:a_L2=0;
a_G7:a_1363(3429894,a_L2);return;
} /* setpragmats */
static int a_1324(int a_A[3]){ /* nextinputentry+>a>+a>+a> */

if(!__equal(a_A[0],0)){ goto a_G3;}
a_A[0]=to_LIST(a_1339)->alwb;
a_G3:if(__more(a_A[0],to_LIST(a_1339)->aupb)){ return 0;}
if(!__equal(to_LIST(a_1339)->offset[a_A[0]-2],4865)){ goto a_G6;}
__next(a_1339,a_A[0]); goto a_G3;
a_G6:a_A[2]=to_LIST(a_1339)->offset[a_A[0]];
a_A[1]=a_1354;
a_G8:__next(a_1339,a_A[0]);
if(__more(a_A[0],to_LIST(a_1339)->aupb)){ return 1;}
if(__equal(to_LIST(a_1339)->offset[a_A[0]-2],4865)){ goto a_G8;}
a_A[1]=to_LIST(a_1339)->offset[a_A[0]-1]; return 1;
} /* nextinputentry */
static void a_1310(int a_A[1]){ /* firstlineoffset+a> */
int a_L2;
a_L2=to_LIST(a_1339)->alwb;
a_G2:if(!__more(a_L2,to_LIST(a_1339)->vupb)){ goto a_G4;}
a_A[0]=1;return;
a_G4:if(!__equal(to_LIST(a_1339)->offset[a_L2-2],4865)){ goto a_G6;}
__next(a_1339,a_L2); goto a_G2;
a_G6:a_A[0]=to_LIST(a_1339)->offset[a_L2-1];return;
} /* firstlineoffset */
static int a_1351(int a_F1,int a_A[3]){ /* iscmdlinepragmat+>a+>a>+a>+a> */
int a_L5;int a_P[1];
if(!__is(a_A[0])){ goto a_G5;}
a_A[0]=0;
a_A[1]=0;
a_G4:a_A[2]=0; return 1;
a_G5:a_comparestring(a_1021,a_F1,a_1001,16777383,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G9;}
a_A[1]=3429893;
a_G8:a_A[2]=1; return 1;
a_G9:a_comparestring(a_1021,a_F1,a_1001,16777380,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G13;}
a_A[1]=3429903; goto a_G8;
a_G13:a_comparestring(a_1021,a_F1,a_1001,16777377,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G17;}
a_A[1]=3429895; goto a_G8;
a_G17:a_comparestring(a_1021,a_F1,a_1001,16777374,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G21;}
a_A[1]=3429892; goto a_G8;
a_G21:a_comparestring(a_1021,a_F1,a_1001,16777371,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G25;}
a_A[1]=3429889;
a_A[2]=3; return 1;
a_G25:a_comparestring(a_1021,a_F1,a_1001,16777368,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G29;}
a_A[1]=3429889; goto a_G4;
a_G29:a_comparestring(a_1021,a_F1,a_1001,16777364,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G34;}
a_A[0]=1;
a_A[1]=3429907; goto a_G4;
a_G34:a_comparestring(a_1021,a_F1,a_1001,16777361,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G39;}
a_A[0]=1;
a_A[1]=3429906; goto a_G4;
a_G39:if(!a_stringelem(a_1021,a_F1,0,a_P)){ return 0;}a_L5=a_P[0];
if(!__equal(a_L5,45)){ return 0;}
if(!a_stringelem(a_1021,a_F1,1,a_P)){ return 0;}a_L5=a_P[0];
if(!__equal(a_L5,45)){ return 0;}
a_A[1]=-1; goto a_G4;
} /* iscmdlinepragmat */
static void a_1350(void){ /* initprogramargs */
int a_L1;int a_L2;int a_L3;int a_P[1];
a_L1=to_LIST(a_1340)->aupb;
a_L3=0;
a_G3:if(!__less(a_L1,to_LIST(a_1340)->alwb)){ goto a_G6;}
if(__equal(a_L3,0)){return;}
a_P[0]=2093833500;a_1040(0,1,a_P);return;
a_G6:a_copystring(a_1340,a_L1,a_1021);
a_P[0]=a_L3;a_1341(to_LIST(a_1021)->aupb,a_P);a_L3=a_P[0];
__stringwidth(a_1340,a_L1,a_L2);
__subtr(a_L1,a_L2,a_L1); goto a_G3;
} /* initprogramargs */
static int a_1352(int a_F1){ /* ishelpargument+>a */
int a_L2;int a_P[1];
if(!__equal(to_LIST(a_1339)->offset[a_F1-2],4865)){ return 0;}
a_comparestring(a_1021,to_LIST(a_1339)->offset[a_F1],a_1001,16777358,a_P);a_L2=a_P[0];
if(!__equal(a_L2,0)){ return 0;}
a_P[0]=2093834889;a_1103(1,a_P); return 1;
} /* ishelpargument */
static int a_1353(int a_F1){ /* isversionargument+>a */
int a_L2;int a_P[3];
if(!__equal(to_LIST(a_1339)->offset[a_F1-2],4865)){ return 0;}
a_comparestring(a_1021,to_LIST(a_1339)->offset[a_F1],a_1001,16777354,a_P);a_L2=a_P[0];
if(!__equal(a_L2,0)){ return 0;}
a_P[0]=2093834948;a_P[1]=1;a_P[2]=0;a_1103(3,a_P); return 1;
} /* isversionargument */
static void a_1358(void){ /* readarguments */
int a_L1;int a_L2;int a_L3;int a_P[3];
a_1350();
if(a_1147()){return;}
a_L2=0;
a_L1=to_LIST(a_1339)->alwb;
a_G5:if(__more(a_L1,to_LIST(a_1339)->aupb)){ goto a_G19;}
if(!__equal(to_LIST(a_1339)->offset[a_L1-2],4866)){ goto a_G9;}
__incr(a_L2);
a_G8:__next(a_1339,a_L1); goto a_G5;
a_G9:a_L3=0;
a_P[0]=a_L3;if(a_1351(to_LIST(a_1339)->offset[a_L1],a_P)){a_L3=a_P[0];}
if(!__is(a_L3)){ goto a_G14;}
__next(a_1339,a_L1); goto a_G8;
a_G14:if(!a_1352(a_L1)){ goto a_G16;}
a_G15:__incr(a_L2); goto a_G19;
a_G16:if(a_1353(a_L1)){ goto a_G15;} goto a_G8;
a_G19:if(__more(a_L2,0)){return;}
a_P[0]=2093833544;a_1040(0,1,a_P);return;
} /* readarguments */
static int a_1355(int a_A[1]){ /* nextinput+>a> */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[3];
a_G1:if(__more(a_A[0],to_LIST(a_1339)->aupb)){ return 0;}
a_L2=0;
a_1345();
a_1314(a_P);to_LIST(a_1339)->offset[a_A[0]-1]=a_P[0];
a_L5=to_LIST(a_1339)->offset[a_A[0]-2];
if(!__equal(a_L5,4866)){ goto a_G8;}
a_L6=1; goto a_G9;
a_G8:a_L6=2;
a_G9:if(!__equal(a_L5,4865)){ goto a_G24;}
a_P[0]=a_L2;if(!a_1351(to_LIST(a_1339)->offset[a_A[0]],a_P)){ goto a_G24;}a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];
if(!__less(a_L3,0)){ goto a_G17;}
if(!a_1356(0,to_LIST(a_1339)->offset[a_A[0]])){ goto a_G16;}
a_1077();
a_1347();
a_1346();
a_G16:__next(a_1339,a_A[0]); goto a_G1;
a_G17:if(!__noteq(a_L2,0)){ goto a_G22;}
__next(a_1339,a_A[0]);
a_1314(a_P);to_LIST(a_1339)->offset[a_A[0]-1]=a_P[0];
a_1363(a_L3,to_LIST(a_1339)->offset[a_A[0]]); goto a_G16;
a_G22:a_1363(a_L3,a_L4); goto a_G16;
a_G24:if(!a_1356(a_L6,to_LIST(a_1339)->offset[a_A[0]])){ goto a_G29;}
__next(a_1339,a_A[0]);
{ if(a_L5==4866){ return 1;}
 if(!(a_L5==4867)){ goto a_G28;}
}
a_1362(1); return 1;
a_G28:a_1362(a_L5); return 1;
a_G29:a_P[0]=2093833552;a_P[1]=to_LIST(a_1339)->offset[a_A[0]];a_1041(9,0,2,a_P); goto a_G16;
} /* nextinput */
static void a_1359(void){ /* readsources */
int a_L1;int a_L2;int a_P[1];
a_L1=to_LIST(a_1339)->alwb;
a_L2=0;
a_1363(3429893,0);
a_1361();
a_G5:a_P[0]=a_L1;if(!a_1355(a_P)){ goto a_G12;}a_L1=a_P[0];
a_1077();
a_1357();
a_1346();
a_1361();
a_1363(3429893,0);
__incr(a_L2); goto a_G5;
a_G12:if(__more(a_L2,0)){return;}
a_P[0]=2093833544;a_1040(0,1,a_P);return;
} /* readsources */
static void a_1360(void){ /* readstdlib */
int a_L1;int a_L2;int a_P[1];
a_1114(3429899,a_P);a_L2=a_P[0];
if(!__equal(a_L2,0)){ goto a_G4;}
a_1314(a_P);a_1354=a_P[0];return;
a_G4:a_1344(1516190332,4868);
a_L1=to_LIST(a_1339)->aupb;
a_G6:a_1361();
a_1363(3429893,1);
a_P[0]=a_L1;if(!a_1355(a_P)){ goto a_G14;}a_L1=a_P[0];
a_1077();
a_1357();
a_1346(); goto a_G6;
a_G14:a_1314(a_P);a_1354=a_P[0];
a_1361();return;
} /* readstdlib */
static void a_1338(void){ /* @root */

} /* @root */
static void a_1377(int a_F1,int a_A[1]){ /* enterconst+>a+a> */
int a_L3;
a_L3=0;
a_A[0]=to_LIST(a_1011)->alwb;
a_G3:__incr(a_A[0]);
if(!__less(to_LIST(a_1011)->aupb,a_A[0])){ goto a_G7;}
 a_extension(a_1011,1);to_LIST(a_1011)->top[1]=a_F1;to_LIST(a_1011)->aupb+=1;
a_G6:a_A[0]=to_LIST(a_1011)->aupb;return;
a_G7:if(__equal(to_LIST(a_1011)->offset[a_A[0]],a_F1)){return;}
if(!__more(a_L3,100)){ goto a_G11;}
 a_extension(a_1011,1);to_LIST(a_1011)->top[1]=a_F1;to_LIST(a_1011)->aupb+=1;
  goto a_G6;
a_G11:__incr(a_L3); goto a_G3;
} /* enterconst */
static int a_1149(int a_F1,int a_F2){ /* waslexicalpointer+>a+[]st[] */

if(!__was(a_1371,a_F1)){ goto a_G3;}
a_copystring(a_1371,a_F1,a_F2); return 1;
a_G3:if(!__was(a_1021,a_F1)){ return 0;}
a_copystring(a_1021,a_F1,a_F2); return 1;
} /* waslexicalpointer */
static int a_1148(int a_F1,int a_A[1]){ /* waslexicalinteger+>a+a> */

if(!__was(a_1011,a_F1)){ return 0;}
a_A[0]=to_LIST(a_1011)->offset[a_F1]; return 1;
} /* waslexicalinteger */
static void a_1390(void){ /* nextchar */
int a_L1;int a_P[1];
if(!__equal(a_1374,10)){ goto a_G5;}
if(!__less(a_1379,-2)){ goto a_G5;}
a_1114(3429892,a_P);a_1383=a_P[0];
a_1114(3429888,a_P);a_1415=a_P[0];
a_G5:if(!__is(a_1383)){ goto a_G8;}
if(!__less(a_1379,-2)){ goto a_G8;}
a_1107(a_1374,1); goto a_G9;
a_G8:a_1107(a_1374,0);
a_G9:if(!__more(a_1419,0)){ goto a_G13;}
__decr(a_1419);
a_1374=32;
__incr(a_1395);return;
a_G13:if(!__more(a_1369,0)){ goto a_G21;}
a_G14:if(!__equal(a_1367,a_1368)){ goto a_G17;}
a_1374=46;
__incr(a_1367); goto a_G23;
a_G17:if(!__less(a_1367,a_1368)){ goto a_G31;}
if(!a_stringelem(a_1021,a_1369,a_1367,a_P)){ goto a_G31;}a_1374=a_P[0];
__incr(a_1367);
if(__equal(a_1374,10)){ goto a_G14;} goto a_G23;
a_G21:if(!__equal(a_1369,0)){ goto a_G31;}
if(!a_getchar(a_1370,a_P)){ goto a_G31;}a_1374=a_P[0];
a_G23:__incr(a_1395);
{ if(a_1374==10){ goto a_G25;}
 if(a_1374==9){ goto a_G26;}
 if(a_1374<=31){  goto a_G9;}
 return;}
a_G25:a_1395=0;return;
a_G26:a_1374=32;
__subtr(a_1395,1,a_L1);
_divrem01(a_L1,a_1415,a_1419);
__subtr(a_1415,a_1419,a_1419);
__decr(a_1419);return;
a_G31:if(!__less(a_1379,-2)){ goto a_G34;}
__incr(a_1379);
a_1374=10;return;
a_G34:a_1374=19088743;return;
} /* nextchar */
static int a_1373(int a_A[1]){ /* boldletter+a> */

{ if(!((97<=a_1374 && a_1374<=122))){ return 0;}
}
a_A[0]=a_1374;
a_1390(); return 1;
} /* boldletter */
static int a_1376(int a_A[1]){ /* digit+a> */

a_G1:{ if(a_1374==32){ goto a_G2;}
 if((48<=a_1374 && a_1374<=57)){  goto a_G3;}
  return 0;}
a_G2:a_1390(); goto a_G1;
a_G3:__subtr(a_1374,48,a_A[0]);
a_1390(); return 1;
} /* digit */
static int a_1384(int a_A[1]){ /* hexdigit+a> */

a_G1:{ if(a_1374==32){ goto a_G2;}
 if((48<=a_1374 && a_1374<=57)){ goto a_G3;}
 if((97<=a_1374 && a_1374<=102)){ goto a_G5;}
 if((65<=a_1374 && a_1374<=70)){  goto a_G8;}
  return 0;}
a_G2:a_1390(); goto a_G1;
a_G3:__subtr(a_1374,48,a_A[0]);
a_G4:a_1390(); return 1;
a_G5:__subtr(a_1374,97,a_A[0]);
__add(a_A[0],10,a_A[0]); goto a_G4;
a_G8:__subtr(a_1374,65,a_A[0]);
__add(a_A[0],10,a_A[0]);
a_1390(); return 1;
} /* hexdigit */
static int a_1387(int a_A[1]){ /* letgit+a> */

a_G1:{ if(a_1374==32){ goto a_G2;}
 if((65<=a_1374 && a_1374<=90)||(97<=a_1374 && a_1374<=122)||(48<=a_1374 && a_1374<=57)){ goto a_G3;}
 if(a_1374==64){  goto a_G5;}
  return 0;}
a_G2:a_1390(); goto a_G1;
a_G3:a_A[0]=a_1374;
a_1390(); return 1;
a_G5:if(!a_1321(3429893)){ return 0;}
a_A[0]=a_1374;
a_1390(); return 1;
} /* letgit */
static void a_1391(void){ /* nextvisiblechar */

a_G1:{ if(a_1374==32){ goto a_G2;}
 if(a_1374==10){  goto a_G3;}
 return;}
a_G2:a_1390(); goto a_G1;
a_G3:__incr(a_1396);
a_1390(); goto a_G1;
} /* nextvisiblechar */
static void a_1418(int a_F1,int a_A[1]){ /* trytoopen+>a+a> */
int a_L3;
if(!a_openfile(a_1370,114,a_1021,a_F1)){ goto a_G3;}
a_A[0]=0;return;
a_G3:__getfileerror(a_1370,a_L3);
if(!__equal(a_L3,2)){ goto a_G6;}
a_A[0]=1;return;
a_G6:a_A[0]=-1;return;
} /* trytoopen */
static void a_1372(void){ /* addextension */

a_1380(46);
a_1380(97);
a_1380(108);
a_1380(101);return;
} /* addextension */
static void a_1416(int a_F2,int a_A[2]){ /* trynextpath+>a>+>a+>a> */
int a_L4;int a_L5;int a_L6;int a_P[1];
a_L4=to_LIST(a_1006)->aupb;
a_L6=58;
a_G3:if(__equal(to_LIST(a_1006)->offset[a_A[0]],58)){ goto a_G7;}
a_L6=to_LIST(a_1006)->offset[a_A[0]];
__incr(a_A[0]);
a_1380(a_L6); goto a_G3;
a_G7:if(__equal(a_L6,58)){return;}
if(__equal(a_L6,47)){ goto a_G10;}
a_1380(47);
a_G10:a_unpackstring(a_1021,a_F2,a_1006);
__subtr(to_LIST(a_1006)->aupb,a_L4,a_L5);
a_packstring(a_1006,a_L5,a_1021);
a_1418(to_LIST(a_1021)->aupb,a_P);a_A[1]=a_P[0];
a_1312(to_LIST(a_1021)->aupb);
if(!__lseq(a_A[1],0)){ goto a_G17;}
a_G16:__unstackto(a_1006,a_L4);return;
a_G17:a_1372();
__subtr(to_LIST(a_1006)->aupb,a_L4,a_L5);
a_packstring(a_1006,a_L5,a_1021);
a_1418(to_LIST(a_1021)->aupb,a_P);a_A[1]=a_P[0];
a_1312(to_LIST(a_1021)->aupb); goto a_G16;
} /* trynextpath */
static void a_1417(int a_F1,int a_A[1]){ /* trypath+>a+>a> */
int a_L3;int a_L4;int a_L5;int a_P[2];
a_1114(3429906,a_P);a_L3=a_P[0];
if(__equal(a_L3,0)){return;}
__scratch(a_1006);
a_unpackstring(a_1021,a_L3,a_1006);
a_1380(58);
a_L4=to_LIST(a_1006)->alwb;
a_L5=to_LIST(a_1006)->aupb;
a_G8:if(__mreq(a_L4,a_L5)){ goto a_G12;}
a_P[0]=a_L4;a_P[1]=a_A[0];a_1416(a_F1,a_P);a_L4=a_P[0];a_A[0]=a_P[1];
if(!__equal(a_A[0],1)){ goto a_G12;}
__incr(a_L4); goto a_G8;
a_G12:__scratch(a_1006);return;
} /* trypath */
static int a_1392(int a_F1,int a_F2){ /* opensourcefile+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_1418(a_F2,a_P);a_L3=a_P[0];
if(!__equal(a_L3,1)){ goto a_G14;}
__scratch(a_1006);
a_unpackstring(a_1021,a_F2,a_1006);
a_1372();
__listlength(a_1006,a_L4);
a_packstring(a_1006,a_L4,a_1021);
__scratch(a_1006);
a_1418(to_LIST(a_1021)->aupb,a_P);a_L3=a_P[0];
a_1312(to_LIST(a_1021)->aupb);
if(!__equal(a_L3,1)){ goto a_G14;}
if(!__equal(a_F1,2)){ goto a_G14;}
a_P[0]=a_L3;a_1417(a_F2,a_P);a_L3=a_P[0];
a_G14:if(!__equal(a_L3,0)){ return 0;} return 1;
} /* opensourcefile */
static int a_1356(int a_F1,int a_F2){ /* nextsource+>a+>a */
int a_P[1];
if(!__equal(a_F1,0)){ goto a_G6;}
a_1369=a_F2;
__stringlength(a_1021,a_1369,a_1368);
a_1367=2;
a_1383=0; goto a_G9;
a_G6:if(!a_1392(a_F1,a_F2)){ return 0;}
a_1369=0;
a_1114(3429892,a_P);a_1383=a_P[0];
a_G9:a_1395=0;
a_1114(3429888,a_P);a_1415=a_P[0];
a_1379=-4;
a_1396=0;
a_1419=0;
a_1393=0;
a_1138();
a_1374=10;
a_1390();
a_1391(); return 1;
} /* nextsource */
static void a_1346(void){ /* closesource */

if(!__more(a_1369,0)){ goto a_G3;}
a_G2:a_1369=-1;return;
a_G3:if(!__equal(a_1369,0)){return;}
a_closefile(a_1370);
a_1138(); goto a_G2;
} /* closesource */
static void a_1298(void){ /* createicename */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_P[1];
a_L1=to_LIST(a_1006)->aupb;
a_1114(3429907,a_P);a_L2=a_P[0];
if(!__is(a_L2)){ goto a_G5;}
a_L5=0; goto a_G8;
a_G5:if(!a_1349(a_P)){ goto a_G7;}a_L2=a_P[0];
a_L5=1; goto a_G8;
a_G7:a_1063(a_1001,16777389,295);return;
a_G8:a_unpackstring(a_1021,a_L2,a_1006);
a_L4=to_LIST(a_1006)->aupb;
a_G10:if(__lseq(a_L4,a_L1)){ goto a_G20;}
{register int a_r1=to_LIST(a_1006)->offset[a_L4];
 if(a_r1==46){ goto a_G12;}
 if(a_r1==47||a_r1==92||a_r1==58){  goto a_G17;}
  goto a_G19;}
a_G12:if(!__equal(a_L5,0)){ goto a_G15;}
a_L5=2;
a_G14:a_L4=a_L1; goto a_G20;
a_G15:__decr(a_L4);
__unstackto(a_1006,a_L4); goto a_G10;
a_G17:if(__equal(a_L5,1)){ goto a_G20;} goto a_G14;
a_G19:__decr(a_L4); goto a_G10;
a_G20:if(__equal(a_L5,2)){ goto a_G25;}
a_1380(46);
a_1380(105);
a_1380(99);
a_1380(101);
a_G25:__subtr(to_LIST(a_1006)->aupb,a_L4,a_L3);
a_packstring(a_1006,a_L3,a_1021);
__unstackto(a_1006,a_L1);return;
} /* createicename */
static void a_1402(int a_F1,int a_A[1]){ /* readgreater+>a+a> */

if(!__is(a_F1)){ goto a_G6;}
if(!__equal(a_1374,61)){ goto a_G5;}
a_1390();
a_A[0]=1454738995;return;
a_G5:a_A[0]=1454738938;return;
a_G6:if(!__equal(a_1374,62)){ goto a_G9;}
a_1390();
a_A[0]=1454738944;return;
a_G9:a_A[0]=1454738938;return;
} /* readgreater */
static void a_1404(int a_F1,int a_A[1]){ /* readless+>a+a> */

if(!__is(a_F1)){ goto a_G6;}
if(!__equal(a_1374,61)){ goto a_G5;}
a_1390();
a_A[0]=1454738998;return;
a_G5:a_A[0]=1454738935;return;
a_G6:if(!__equal(a_1374,60)){ goto a_G9;}
a_1390();
a_A[0]=1454738941;return;
a_G9:if(!__equal(a_1374,62)){ goto a_G12;}
a_1390();
a_A[0]=1454738953;return;
a_G12:a_A[0]=1454738935;return;
} /* readless */
static void a_1405(int a_A[1]){ /* readminus+a> */
int a_P[1];
{ if(a_1374==62){ goto a_G2;}
 if(a_1374==61){  goto a_G4;}
  goto a_G6;}
a_G2:a_1390();
a_A[0]=1454738929;return;
a_G4:a_1390();
a_A[0]=1454738989;return;
a_G6:a_1406(a_P);a_A[0]=a_P[0];return;
} /* readminus */
static void a_1406(int a_A[1]){ /* readminuswithspaces+a> */
int a_P[1];
a_G1:{ if(a_1374==32){ goto a_G2;}
 if(a_1374==48){ goto a_G3;}
 if((49<=a_1374 && a_1374<=57)){  goto a_G5;}
  goto a_G6;}
a_G2:a_1390(); goto a_G1;
a_G3:a_1390();
a_1409(1,a_P);a_A[0]=a_P[0];return;
a_G5:a_1401(1,a_P);a_A[0]=a_P[0];return;
a_G6:a_A[0]=1454738977;return;
} /* readminuswithspaces */
static void a_1409(int a_F1,int a_A[1]){ /* readzero+>a+a> */
int a_P[1];
a_G1:{ if(a_1374==32){ goto a_G2;}
 if((48<=a_1374 && a_1374<=57)){ goto a_G3;}
 if(a_1374==120||a_1374==88){  goto a_G4;}
  goto a_G6;}
a_G2:a_1390(); goto a_G1;
a_G3:a_1401(a_F1,a_P);a_A[0]=a_P[0];return;
a_G4:a_1390();
a_1403(a_F1,a_P);a_A[0]=a_P[0];return;
a_G6:a_A[0]=1454739015;return;
} /* readzero */
static void a_1375(int a_F2,int a_F3,int a_A[1]){ /* decimaloverflow+>a>+>a+>a */

if(__mreq(a_F3,0)){return;}
if(!__is(a_F2)){ goto a_G4;}
if(__equal(a_F3,(-2147483647-1))){return;}
a_G4:a_A[0]=1;return;
} /* decimaloverflow */
static void a_1401(int a_F1,int a_A[1]){ /* readconst+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[1];
__subtr(a_1374,48,a_L3);
a_L4=0;
a_1390();
a_G4:if(!a_1376(a_P)){ goto a_G7;}a_L5=a_P[0];
__addmult(a_L3,10,a_L5,a_L3);
a_P[0]=a_L4;a_1375(a_F1,a_L3,a_P);a_L4=a_P[0]; goto a_G4;
a_G7:if(!__is(a_L4)){ goto a_G9;}
a_P[0]=2093833559;a_1040(-1,1,a_P); goto a_G11;
a_G9:if(!__is(a_F1)){ goto a_G11;}
__subtr(0,a_L3,a_L3);
a_G11:a_1377(a_L3,a_P);a_A[0]=a_P[0];return;
} /* readconst */
static void a_1385(int a_F2,int a_A[1]){ /* hexoverflow+>a>+>a */
int a_L3;
a_L3=a_F2;
__leftclear(a_L3,4);
__rightclear(a_L3,4);
if(__equal(a_F2,a_L3)){return;}
a_A[0]=1;return;
} /* hexoverflow */
static void a_1403(int a_F1,int a_A[1]){ /* readhex+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[1];
if(!a_1384(a_P)){ goto a_G12;}a_L4=a_P[0];
a_L5=0;
a_G3:if(!a_1384(a_P)){ goto a_G7;}a_L3=a_P[0];
a_P[0]=a_L5;a_1385(a_L4,a_P);a_L5=a_P[0];
__leftclear(a_L4,4);
__boolor(a_L4,a_L3,a_L4); goto a_G3;
a_G7:if(!__is(a_L5)){ goto a_G9;}
a_P[0]=2093833559;a_1040(-1,1,a_P); goto a_G11;
a_G9:if(!__is(a_F1)){ goto a_G11;}
__subtr(0,a_L4,a_L4);
a_G11:a_1377(a_L4,a_P);a_A[0]=a_P[0];return;
a_G12:a_P[0]=2093833568;a_1040(-1,1,a_P);
a_A[0]=1454739015;return;
} /* readhex */
static void a_1400(int a_A[1]){ /* readchardenotation+a> */
int a_L2;int a_P[1];
a_L2=a_1374;
if(!__equal(a_1374,10)){ goto a_G4;}
a_G3:a_P[0]=2093833577;a_1040(-1,1,a_P); goto a_G8;
a_G4:a_1390();
if(!__equal(a_1374,47)){ goto a_G3;}
a_1390();
a_G8:a_1377(a_L2,a_P);a_A[0]=a_P[0];return;
} /* readchardenotation */
static void a_1413(void){ /* skipchardenotation */

if(__equal(a_1374,10)){return;}
a_1390();
if(!__equal(a_1374,47)){return;}
a_1390();return;
} /* skipchardenotation */
static void a_1407(int a_A[1]){ /* readstring+a> */
int a_L2;int a_P[1];
__scratch(a_1006);
a_L2=0;
a_G3:a_1390();
{ if(a_1374==34){ goto a_G5;}
 if(a_1374==10||a_1374==19088743){  goto a_G15;}
  goto a_G7;}
a_G5:a_1390();
if(!__equal(a_1374,34)){ goto a_G9;}
a_G7:a_1380(a_1374);
__incr(a_L2); goto a_G3;
a_G9:a_1391();
if(__equal(a_1374,34)){ goto a_G3;}
if(!__equal(a_L2,0)){ goto a_G13;}
a_G12:a_A[0]=1516190318;return;
a_G13:a_packstring(a_1006,a_L2,a_1021);
a_A[0]=to_LIST(a_1021)->aupb;return;
a_G15:a_P[0]=2093833584;a_1040(-1,1,a_P); goto a_G12;
} /* readstring */
static void a_1414(void){ /* skipstring */

a_G1:{ if(a_1374==34){ goto a_G2;}
 if(a_1374==10||a_1374==19088743){ return;}
  goto a_G3;}
a_G2:a_1390();return;
a_G3:a_1390(); goto a_G1;
} /* skipstring */
static void a_1312(int a_F1){ /* forgetstring+>a */

if(__equal(a_F1,1516190318)){return;}
if(!__equal(a_F1,to_LIST(a_1021)->aupb)){return;}
__unstackstring(a_1021);return;
} /* forgetstring */
static void a_1389(void){ /* longcomment */

a_G1:{ if(a_1374==10){return;}
 if(!(a_1374==36)){ goto a_G3;}
}
a_1390();return;
a_G3:a_1390(); goto a_G1;
} /* longcomment */
static int a_1411(void){ /* shortcomment */

a_G1:{ if(a_1374==32){ goto a_G2;}
 if((65<=a_1374 && a_1374<=90)||(97<=a_1374 && a_1374<=122)||(48<=a_1374 && a_1374<=57)){  goto a_G3;}
  return 0;}
a_G2:a_1390(); goto a_G1;
a_G3:a_1390();
a_G4:{ if(!((65<=a_1374 && a_1374<=90)||(97<=a_1374 && a_1374<=122)||(48<=a_1374 && a_1374<=57)||a_1374==32)){ return 1;}
}
a_1390(); goto a_G4;
} /* shortcomment */
static void a_1398(int a_A[1]){ /* readbold+a> */
int a_L2;int a_L3;int a_P[2];
__scratch(a_1006);
a_L2=0;
a_G3:if(!a_1373(a_P)){ goto a_G6;}a_L3=a_P[0];
a_1380(a_L3);
__incr(a_L2); goto a_G3;
a_G6:if(!__equal(a_1374,39)){ goto a_G21;}
a_1390();
a_packstring(a_1006,a_L2,a_1021);
a_A[0]=1454738703;
a_G10:if(!__equal(a_A[0],0)){ goto a_G13;}
a_P[0]=2093833592;a_P[1]=to_LIST(a_1021)->aupb;a_1040(-1,2,a_P);
a_A[0]=1454738851; goto a_G20;
a_G13:a_comparestring(a_1366,a_A[0],a_1021,to_LIST(a_1021)->aupb,a_P);a_L2=a_P[0];
__next(a_1366,a_A[0]);
if(!__more(a_L2,0)){ goto a_G17;}
a_A[0]=to_LIST(a_1366)->offset[a_A[0]-2]; goto a_G10;
a_G17:if(!__less(a_L2,0)){ goto a_G19;}
a_A[0]=to_LIST(a_1366)->offset[a_A[0]-1]; goto a_G10;
a_G19:a_A[0]=to_LIST(a_1366)->offset[a_A[0]];
a_G20:__unstackstring(a_1021);return;
a_G21:a_packstring(a_1006,a_L2,a_1021);
a_P[0]=2093833607;a_P[1]=to_LIST(a_1021)->aupb;a_1040(-1,2,a_P);
__unstackstring(a_1021);
a_A[0]=1454738851;return;
} /* readbold */
static void a_1408(int a_A[1]){ /* readtag+a> */
int a_L2;int a_P[1];
__scratch(a_1006);
a_1380(a_1374);
a_1390();
a_G4:if(!a_1387(a_P)){ goto a_G6;}a_L2=a_P[0];
a_1380(a_L2); goto a_G4;
a_G6:a_1378(a_1006,a_P);a_A[0]=a_P[0];return;
} /* readtag */
static void a_1399(int a_A[1]){ /* readbuiltin+a> */
int a_L2;int a_L3;int a_P[2];
__scratch(a_1006);
a_1380(95);
a_L2=1;
a_G4:if(!a_1373(a_P)){ goto a_G7;}a_L3=a_P[0];
a_1380(a_L3);
__incr(a_L2); goto a_G4;
a_G7:if(!__equal(a_1374,95)){ goto a_G32;}
a_1380(95);
__incr(a_L2);
a_1390();
a_packstring(a_1006,a_L2,a_1021);
a_A[0]=1454738826;
a_G13:if(!__equal(a_A[0],0)){ goto a_G15;}
a_P[0]=2093833599;a_P[1]=to_LIST(a_1021)->aupb;a_1040(-1,2,a_P); goto a_G22;
a_G15:a_comparestring(a_1366,a_A[0],a_1021,to_LIST(a_1021)->aupb,a_P);a_L2=a_P[0];
__next(a_1366,a_A[0]);
if(!__more(a_L2,0)){ goto a_G19;}
a_A[0]=to_LIST(a_1366)->offset[a_A[0]-2]; goto a_G13;
a_G19:if(!__less(a_L2,0)){ goto a_G21;}
a_A[0]=to_LIST(a_1366)->offset[a_A[0]-1]; goto a_G13;
a_G21:a_A[0]=to_LIST(a_1366)->offset[a_A[0]];
a_G22:__unstackstring(a_1021);
{ if(a_A[0]==1||a_A[0]==4){ goto a_G24;}
 if(a_A[0]==2){ goto a_G25;}
 if(a_A[0]==3){ goto a_G27;}
 if(a_A[0]==5){  goto a_G28;}
  goto a_G31;}
a_G24:a_1111(0,a_P);a_A[0]=a_P[1];return;
a_G25:a_1111(0,a_P);a_A[0]=a_P[0];
a_1377(a_A[0],a_P);a_A[0]=a_P[0];return;
a_G27:a_1382(a_P);a_A[0]=a_P[0];return;
a_G28:a_1114(3429891,a_P);a_A[0]=a_P[0];
if(__is(a_A[0])){return;}
a_A[0]=1516190318;return;
a_G31:a_A[0]=1454738851;return;
a_G32:if(!__equal(a_L2,1)){ goto a_G35;}
a_P[0]=2093833615;a_P[1]=95;a_1040(-1,2,a_P); goto a_G31;
a_G35:a_packstring(a_1006,a_L2,a_1021);
a_P[0]=2093833599;a_P[1]=to_LIST(a_1021)->aupb;a_1040(-1,2,a_P);
__unstackstring(a_1021); goto a_G31;
} /* readbuiltin */
static void a_1397(int a_A[1]){ /* read+a> */
int a_L2;int a_P[2];
if(!__more(a_1396,0)){ goto a_G4;}
__decr(a_1396);
a_G3:a_A[0]=1454739013;return;
a_G4:a_L2=a_1393;
a_1393=0;
a_G6:{ if(a_1374==32){ goto a_G7;}
 if((65<=a_1374 && a_1374<=90)||(97<=a_1374 && a_1374<=122)){ goto a_G8;}
 if(a_1374==43){ goto a_G10;}
 if(a_1374==44){ goto a_G12;}
 if(a_1374==59){ goto a_G14;}
 if(a_1374==10){ goto a_G16;}
 if(a_1374==45){ goto a_G19;}
 if(a_1374==61){ goto a_G21;}
 if(a_1374==40){ goto a_G23;}
 if(a_1374==41){ goto a_G25;}
 if(a_1374==48){ goto a_G28;}
 if((49<=a_1374 && a_1374<=57)){ goto a_G31;}
 if(a_1374==39){ goto a_G33;}
 if(a_1374==60){ goto a_G35;}
 if(a_1374==62){ goto a_G37;}
 if(a_1374==42){ goto a_G39;}
 if(a_1374==58){ goto a_G41;}
 if(a_1374==47){ goto a_G43;}
 if(a_1374==46){ goto a_G48;}
 if(a_1374==64){ goto a_G50;}
 if(a_1374==63){ goto a_G55;}
 if(a_1374==36){ goto a_G57;}
 if(a_1374==91){ goto a_G59;}
 if(a_1374==93){ goto a_G61;}
 if(a_1374==35){ goto a_G64;}
 if(a_1374==34){ goto a_G67;}
 if(a_1374==33){ goto a_G68;}
 if(a_1374==126){ goto a_G73;}
 if(a_1374==124){ goto a_G75;}
 if(a_1374==38){ goto a_G77;}
 if(a_1374==94){ goto a_G79;}
 if(a_1374==95){ goto a_G81;}
 if(a_1374==19088743){  goto a_G83;}
  goto a_G85;}
a_G7:a_1390(); goto a_G6;
a_G8:a_1393=1;
a_1408(a_P);a_A[0]=a_P[0];return;
a_G10:a_1390();
a_A[0]=1454738980;return;
a_G12:a_1390();
a_A[0]=1454738968;return;
a_G14:a_1390();
a_A[0]=1454738971;return;
a_G16:a_1390();
a_1393=a_L2; goto a_G3;
a_G19:a_1390();
a_1405(a_P);a_A[0]=a_P[0];return;
a_G21:a_1390();
a_A[0]=1454738932;return;
a_G23:a_1390();
a_A[0]=1454738959;return;
a_G25:a_1390();
a_1393=1;
a_A[0]=1454738962;return;
a_G28:a_1390();
a_1393=1;
a_1409(0,a_P);a_A[0]=a_P[0];return;
a_G31:a_1393=1;
a_1401(0,a_P);a_A[0]=a_P[0];return;
a_G33:a_1390();
a_1398(a_P);a_A[0]=a_P[0];return;
a_G35:a_1390();
a_1404(a_L2,a_P);a_A[0]=a_P[0];return;
a_G37:a_1390();
a_1402(a_L2,a_P);a_A[0]=a_P[0];return;
a_G39:a_1390();
a_A[0]=1454738956;return;
a_G41:a_1390();
a_A[0]=1454738965;return;
a_G43:a_1390();
if(!__is(a_L2)){ goto a_G46;}
a_A[0]=1454738992;return;
a_G46:a_1393=1;
a_1400(a_P);a_A[0]=a_P[0];return;
a_G48:a_1390();
a_A[0]=1454738974;return;
a_G50:if(a_1321(3429893)){ goto a_G8;}
a_P[0]=2093833615;a_P[1]=a_1374;a_1040(-1,2,a_P); goto a_G7;
a_G55:a_1390();
a_A[0]=1454738986;return;
a_G57:a_1390();
a_1389(); goto a_G6;
a_G59:a_1390();
a_A[0]=1454738947;return;
a_G61:a_1390();
a_1393=1;
a_A[0]=1454738950;return;
a_G64:a_1390();
if(a_1411()){ goto a_G6;}
a_A[0]=1454738983;return;
a_G67:a_1407(a_P);a_A[0]=a_P[0];return;
a_G68:a_1390();
if(!__equal(a_1374,61)){ goto a_G72;}
a_1390();
a_A[0]=1454738989;return;
a_G72:a_P[0]=2093833615;a_P[1]=33;a_1040(-1,2,a_P); goto a_G6;
a_G73:a_1390();
a_A[0]=1454739001;return;
a_G75:a_1390();
a_A[0]=1454739004;return;
a_G77:a_1390();
a_A[0]=1454739007;return;
a_G79:a_1390();
a_A[0]=1454739010;return;
a_G81:a_1390();
a_1399(a_P);a_A[0]=a_P[0];return;
a_G83:a_1390();
a_A[0]=1454738855;return;
a_G85:a_P[0]=2093833615;a_P[1]=a_1374;a_1040(-1,2,a_P);
a_1390(); goto a_G6;
} /* read */
static void a_1412(int a_A[1]){ /* skip+a> */

if(!__more(a_1396,0)){ goto a_G4;}
__decr(a_1396);
a_G3:a_A[0]=1454739013;return;
a_G4:{ if(a_1374==10){ goto a_G5;}
 if(a_1374==47){ goto a_G7;}
 if(a_1374==46){ goto a_G9;}
 if(a_1374==34){ goto a_G11;}
 if(a_1374==35){ goto a_G13;}
 if(a_1374==36){ goto a_G15;}
 if(a_1374==19088743){  goto a_G17;}
  goto a_G18;}
a_G5:a_1390(); goto a_G3;
a_G7:a_1390();
a_1413(); goto a_G4;
a_G9:a_1390();
a_A[0]=1454738974;return;
a_G11:a_1390();
a_1414(); goto a_G4;
a_G13:a_1390();
if(a_1411()){ goto a_G4;} goto a_G4;
a_G15:a_1390();
a_1389(); goto a_G4;
a_G17:a_A[0]=1454738855;return;
a_G18:a_1390(); goto a_G4;
} /* skip */
static void a_1365(void){ /* @root */

} /* @root */
static void a_1380(int a_F1){ /* extendBUFFER+>a */

 a_extension(a_1006,1);to_LIST(a_1006)->top[1]=a_F1;to_LIST(a_1006)->aupb+=1;
 return;
} /* extendBUFFER */
static void a_1455(int a_F1,int a_F2){ /* tagredefined+>a+>a */
int a_L3;int a_L4;int a_P[5];
a_1198(a_F1,a_P);a_L3=a_P[0];
a_1058(a_F1,a_P);a_L4=a_P[0];
if(!__more(a_L3,0)){ goto a_G5;}
a_P[0]=2093833765;a_P[1]=a_L4;a_P[2]=a_F1;a_P[3]=a_F2;a_P[4]=a_L3;a_1040(-1,5,a_P);return;
a_G5:a_P[0]=2093833773;a_P[1]=a_L4;a_P[2]=a_F1;a_P[3]=a_F2;a_1040(-1,4,a_P);return;
} /* tagredefined */
static void a_1451(int a_A[2]){ /* skipfieldlist+a>+a> */
int a_P[1];
if(!__equal(1454738959,a_1062)){ goto a_G17;}
a_1077();
a_A[0]=1;
a_G4:if(!a_1261(a_P)){ goto a_G15;}
if(!__equal(1454738968,a_1062)){ goto a_G8;}
a_1077();
__incr(a_A[0]); goto a_G4;
a_G8:if(!__equal(1454738932,a_1062)){ goto a_G10;}
a_1077(); goto a_G4;
a_G10:if(!__equal(1454738962,a_1062)){ goto a_G13;}
a_1077();
a_A[1]=0;return;
a_G13:a_P[0]=2093833621;a_1040(-1,1,a_P);
a_G14:a_A[1]=1;return;
a_G15:a_P[0]=2093833628;a_1040(-1,1,a_P); goto a_G14;
a_G17:a_A[1]=0;
a_A[0]=-1;return;
} /* skipfieldlist */
static void a_1429(int a_A[4]){ /* getlisttag+a>+a>+a>+a> */
int a_P[2];
a_1431();
a_1451(a_P);a_A[1]=a_P[0];a_A[3]=a_P[1];
a_A[0]=0;a_A[2]=0;
if(__is(a_A[3])){ goto a_G10;}
if(!a_1261(a_P)){ goto a_G8;}a_A[0]=a_P[0];
if(!__equal(1454738932,a_1062)){ goto a_G10;}
a_A[2]=1; goto a_G10;
a_G8:a_P[0]=2093833642;a_1040(-1,1,a_P);
a_A[3]=1;
a_G10:if(!__is(a_A[3])){ goto a_G12;}
a_1427();return;
a_G12:a_1437();return;
} /* getlisttag */
static void a_1428(int a_A[4]){ /* getexternallisttag+a>+a>+a>+a> */
int a_P[2];
a_1431();
a_1451(a_P);a_A[1]=a_P[0];a_A[3]=a_P[1];
a_A[0]=0;a_A[2]=0;
if(__is(a_A[3])){ goto a_G13;}
if(!a_1261(a_P)){ goto a_G11;}a_A[0]=a_P[0];
if(!__equal(1454738932,a_1062)){ goto a_G9;}
a_1077();
if(a_1260(a_P)){a_A[2]=a_P[0]; goto a_G13;}
a_G9:a_P[0]=2093833784;a_P[1]=a_A[0];a_1040(-1,2,a_P);
a_G10:a_A[3]=1; goto a_G13;
a_G11:a_P[0]=2093833642;a_1040(-1,1,a_P); goto a_G10;
a_G13:if(!__is(a_A[3])){ goto a_G15;}
a_1427();return;
a_G15:a_1437();return;
} /* getexternallisttag */
static void a_1447(int a_F1,int a_F2,int a_F3){ /* selectorlist+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_L10;int a_L11;int a_P[5];
if(!__equal(1454738959,a_1062)){return;}
a_1077();
a_1314(a_P);a_L4=a_P[0];
a_1440(a_F2,a_F2,a_P);a_L7=a_P[0];
a_1056(a_L7,a_P);a_L6=a_P[0];
if(!__equal(a_L6,0)){ goto a_G11;}
a_1267(a_L7,16777559);
a_1442(a_L7,a_F2);
a_1248(a_L7,a_L4);
a_1449(a_L7,2);
a_G11:a_1266(a_L7,0);
a_L5=a_F3;
a_G13:if(!a_1261(a_P)){ goto a_G30;}a_L10=a_P[0];
a_1440(a_L10,a_F2,a_P);a_L10=a_P[0];
a_1058(a_L10,a_P);a_L11=a_P[0];
if(!__equal(a_L11,16777559)){ goto a_G25;}
a_1056(a_L10,a_P);a_L8=a_P[0];
if(__equal(a_L8,a_L5)){ goto a_G31;}
if(!__equal(a_L8,0)){ goto a_G23;}
a_1266(a_L10,a_L5);
a_1449(a_L10,2);
a_1444(a_L10,a_L4); goto a_G31;
a_G23:a_1198(a_L10,a_P);a_L9=a_P[0];
a_P[0]=2093833653;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L10;a_P[4]=a_L9;a_1040(-1,5,a_P); goto a_G31;
a_G25:a_1267(a_L10,16777559);
a_1444(a_L10,a_L4);
a_1449(a_L10,2);
a_1266(a_L10,a_L5);
a_1442(a_L10,a_F2); goto a_G31;
a_G30:a_1063(a_1001,16777399,153);return;
a_G31:if(!__equal(1454738968,a_1062)){ goto a_G34;}
a_1077();
__decr(a_L5); goto a_G13;
a_G34:if(!__equal(1454738932,a_1062)){ goto a_G36;}
a_1077(); goto a_G13;
a_G36:a_1263(1454738962);
a_1056(a_L7,a_P);a_L8=a_P[0];
if(!__equal(a_L8,0)){ goto a_G44;}
if(!__equal(a_L6,0)){ goto a_G41;}
a_L6=-1; goto a_G50;
a_G41:if(__equal(a_L6,-1)){ goto a_G50;}
a_G42:a_1198(a_L7,a_P);a_L9=a_P[0];
a_P[0]=2093833666;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L7;a_P[4]=a_L9;a_1040(-1,5,a_P); goto a_G50;
a_G44:if(__equal(a_L8,a_L6)){ goto a_G50;}
if(!__equal(a_L6,0)){ goto a_G42;}
a_L6=a_L8;
a_1444(a_L7,a_L4);
a_G50:a_1266(a_L7,a_L6);
a_1445(a_F2,a_L6);
a_1197(a_F2,a_P);a_L6=a_P[0];
if(__equal(a_L6,a_F3)){return;}
if(!__equal(a_L6,0)){ goto a_G57;}
a_1443(a_F2,a_F3);
a_1444(a_F2,a_L4);return;
a_G57:a_1198(a_F2,a_P);a_L9=a_P[0];
a_P[0]=2093833676;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L6;a_P[4]=a_L9;a_1040(-1,5,a_P);return;
} /* selectorlist */
static void a_1439(int a_F1,int a_F2,int a_F3){ /* noselectorlist+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_P[5];
if(__mreq(a_F3,0)){return;}
a_1440(a_F2,a_F2,a_P);a_L4=a_P[0];
a_1056(a_L4,a_P);a_L5=a_P[0];
if(__equal(a_L5,1)){ goto a_G14;}
if(!__more(a_L5,0)){ goto a_G8;}
a_1198(a_L4,a_P);a_L6=a_P[0];
a_P[0]=2093833666;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L4;a_P[4]=a_L6;a_1040(-1,5,a_P); goto a_G14;
a_G8:a_1267(a_L4,16777559);
a_1442(a_L4,a_F2);
a_1266(a_L4,1);
a_1445(a_F2,1);
a_1314(a_P);a_L6=a_P[0];
a_1248(a_L4,a_L6);
a_G14:a_1197(a_F2,a_P);a_L5=a_P[0];
if(__equal(a_L5,1)){return;}
if(!__more(a_L5,0)){ goto a_G19;}
a_1198(a_F2,a_P);a_L6=a_P[0];
a_P[0]=2093833676;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L5;a_P[4]=a_L6;a_1040(-1,5,a_P);return;
a_G19:a_1443(a_F2,1);return;
} /* noselectorlist */
static void a_1311(int a_F1){ /* fixlistusage+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1058(a_F1,a_P);a_L4=a_P[0];
if(__equal(a_L4,16777544)){ goto a_G5;}
if(__equal(a_L4,16777548)){ goto a_G5;}
if(!__equal(a_L4,16777554)){return;}
a_G5:if(!a_1205(a_F1,8)){ goto a_G7;}
a_1449(a_F1,1);
a_G7:if(a_1205(a_F1,2)){return;}
a_1449(a_F1,2);
a_1197(a_F1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,0)){return;}
a_1443(a_F1,1);
a_1445(a_F1,1);
a_1440(a_F1,a_F1,a_P);a_L3=a_P[0];
a_1267(a_L3,16777559);
a_1266(a_L3,1);
a_1449(a_L3,2);
a_1442(a_L3,a_F1);return;
} /* fixlistusage */
static void a_1450(int a_A[2]){ /* sizeestimator+a>+a> */
int a_P[2];
if(!__equal(1454738947,a_1062)){ goto a_G28;}
a_1077();
if(!__equal(1454738932,a_1062)){ goto a_G6;}
a_1077();
a_A[0]=1; goto a_G7;
a_G6:a_A[0]=0;
a_G7:if(!a_1432(a_P)){ goto a_G19;}a_A[1]=a_P[0];
__incr(a_A[0]);
{ if(a_A[1]<=0){ goto a_G10;}
 if(a_A[1]>=1000000){ goto a_G12;}
 if(a_A[1]>=101){  goto a_G16;}
  goto a_G26;}
a_G10:a_P[0]=2093833835;a_P[1]=a_A[1];a_1041(9,-1,2,a_P);
a_A[1]=1; goto a_G26;
a_G12:a_P[0]=2093833835;a_P[1]=a_A[1];a_1041(6,-1,2,a_P);
if(!__equal(a_A[0],1)){ goto a_G15;}
a_G14:a_A[1]=100; goto a_G26;
a_G15:a_A[1]=1000000; goto a_G26;
a_G16:if(!__equal(a_A[0],1)){ goto a_G26;}
a_P[0]=2093833835;a_P[1]=a_A[1];a_1041(6,-1,2,a_P); goto a_G14;
a_G19:if(!a_1261(a_P)){ goto a_G22;}a_A[1]=a_P[0];
__add(a_A[0],3,a_A[0]);
a_1271(a_A[1]); goto a_G26;
a_G22:if(!__equal(a_A[0],1)){ goto a_G24;}
a_P[0]=2093833807;a_1040(-1,1,a_P);
a_G24:a_A[1]=0;a_A[0]=0;
a_G26:a_1421(1454738932);
a_1263(1454738950);return;
a_G28:a_A[1]=-1;a_A[0]=-1;return;
} /* sizeestimator */
static void a_1446(void){ /* repeatcount */
int a_L1;int a_L2;int a_P[3];
a_L1=1;
a_L2=0;
if(!__equal(1454738956,a_1062)){ goto a_G13;}
a_1077();
if(!a_1432(a_P)){ goto a_G9;}a_L1=a_P[0];
{ if((1<=a_L1 && a_L1<=10000)){  goto a_G13;}
}
a_P[0]=2093833698;a_P[1]=a_L1;a_P[2]=10000;a_1040(-1,3,a_P);
a_L1=1; goto a_G13;
a_G9:if(!a_1261(a_P)){ goto a_G12;}a_L2=a_P[0];
a_L1=-1;
a_1271(a_L2); goto a_G13;
a_G12:a_P[0]=2093833685;a_1040(-1,1,a_P);
a_G13:if(__equal(a_L1,1)){return;}
a_1012(2106125343);
if(!__less(a_L1,0)){ goto a_G17;}
a_1017(a_L2);return;
a_G17:a_1015(a_L1);return;
} /* repeatcount */
static int a_1433(void){ /* isextendedblock */
int a_P[1];
a_1431();
if(a_1432(a_P)){ goto a_G4;}
if(!a_1261(a_P)){ goto a_G7;}
a_G4:if(!__equal(1454738929,a_1062)){ goto a_G7;}
a_1077();
a_1437(); return 1;
a_G7:a_1437(); return 0;
} /* isextendedblock */
static void a_1448(int a_F1,int a_A[1]){ /* selectors+>a+>a> */
int a_L3;int a_P[2];
if(!__equal(1454738929,a_1062)){ goto a_G17;}
a_G2:a_1077();
a_1012(2106125354);
if(!__equal(1454738956,a_1062)){ goto a_G10;}
a_1077();
if(!__equal(a_A[0],0)){ goto a_G9;}
a_A[0]=1;
a_1012(2106125343); goto a_G15;
a_G9:a_P[0]=2093833709;a_P[1]=a_F1;a_1040(-1,2,a_P); goto a_G15;
a_G10:if(!a_1261(a_P)){ goto a_G13;}a_L3=a_P[0];
a_1440(a_L3,a_F1,a_P);a_L3=a_P[0];
a_1017(a_L3); goto a_G15;
a_G13:a_P[0]=2093833719;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_1268();
a_G15:if(!__equal(1454738929,a_1062)){return;} goto a_G2;
a_G17:a_P[0]=2093833719;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_1268();return;
} /* selectors */
static void a_1425(int a_F1){ /* extendedblock+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
a_L2=0;a_L4=0;
a_1012(2106125263);
a_G3:if(!__equal(1454738968,a_1062)){ goto a_G5;}
a_1077(); goto a_G3;
a_G5:if(!a_1432(a_P)){ goto a_G9;}a_L3=a_P[0];
a_1015(a_L3);
a_G7:a_P[0]=a_L4;a_1448(a_F1,a_P);a_L4=a_P[0];
__incr(a_L2); goto a_G3;
a_G9:if(!a_1261(a_P)){ goto a_G14;}a_L3=a_P[0];
a_1271(a_L3);
a_1017(a_L3); goto a_G7;
a_G14:if(!__equal(a_L2,0)){ goto a_G17;}
a_P[0]=2093833756;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_1268();return;
a_G17:a_1263(1454738962);
a_1012(2106125263);return;
} /* extendedblock */
static void a_1436(int a_F1){ /* listfillblock+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
if(!a_1433()){ goto a_G3;}
a_1425(a_F1);return;
a_G3:a_L4=0;a_L3=0;
a_1012(2106125312);
a_G5:if(!__equal(1454738968,a_1062)){ goto a_G7;}
a_1077(); goto a_G5;
a_G7:if(!a_1432(a_P)){ goto a_G10;}a_L2=a_P[0];
a_1015(a_L2);
a_G9:__incr(a_L4); goto a_G5;
a_G10:if(!a_1261(a_P)){ goto a_G14;}a_L2=a_P[0];
a_1271(a_L2);
a_1017(a_L2); goto a_G9;
a_G14:if(!__equal(a_L4,0)){ goto a_G17;}
a_P[0]=2093833756;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_1268();return;
a_G17:if(!__equal(1454738956,a_1062)){ goto a_G23;}
a_1077();
if(!__equal(a_L3,0)){ goto a_G22;}
a_L3=1;
a_1012(2106125343); goto a_G5;
a_G22:a_P[0]=2093833709;a_P[1]=a_F1;a_1040(-1,2,a_P); goto a_G5;
a_G23:a_1263(1454738962);
a_1012(2106125232);return;
} /* listfillblock */
static void a_1430(int a_F1){ /* initializer+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
a_G1:if(!__equal(1454738965,a_1062)){return;}
a_1077();
a_L5=0;
if(!a_1262(a_P)){ goto a_G15;}a_L2=a_P[0];a_L4=a_P[1];
a_1058(a_L2,a_P);a_L3=a_P[0];
if(__equal(a_L3,16777520)){ goto a_G8;}
if(!__equal(a_L3,16777525)){ goto a_G14;}
a_G8:a_P[0]=a_L5;a_1245(a_L2,a_L4,a_P);a_L5=a_P[0];
if(__is(a_L5)){ goto a_G1;}
a_1267(a_L2,16777566);
a_1442(a_L2,a_F1);
a_1012(2106125235);
a_1017(a_L2); goto a_G1;
a_G14:a_1455(a_L2,16777566); goto a_G1;
a_G15:a_P[0]=2093833747;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* initializer */
static void a_1435(int a_F1,int a_F2){ /* listfill+>a+>a */
int a_L3;int a_P[3];
if(!__equal(1454738959,a_1062)){ goto a_G34;}
a_1077();
if(!__equal(1454738962,a_1062)){ goto a_G5;}
a_1077();return;
a_G5:if(!a_1205(a_F2,16)){ goto a_G7;}
a_P[0]=2093833728;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);
a_G7:a_1012(2106125271);
a_1017(a_F2);
a_G9:if(!a_1432(a_P)){ goto a_G12;}a_L3=a_P[0];
a_1015(a_L3);
a_G11:a_1446(); goto a_G25;
a_G12:if(!a_1261(a_P)){ goto a_G16;}a_L3=a_P[0];
a_1271(a_L3);
a_1017(a_L3); goto a_G11;
a_G16:if(!a_1260(a_P)){ goto a_G19;}a_L3=a_P[0];
a_1016(a_L3); goto a_G11;
a_G19:if(!__equal(1454738959,a_1062)){ goto a_G23;}
a_1077();
a_1436(a_F2); goto a_G11;
a_G23:a_P[0]=2093833737;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);
a_1268();
a_G25:a_1430(a_F2);
if(!__equal(1454738968,a_1062)){ goto a_G28;}
a_1077(); goto a_G9;
a_G28:if(!__equal(1454738962,a_1062)){ goto a_G32;}
a_1077();
a_1012(2106125324);
a_1449(a_F2,256);return;
a_G32:a_P[0]=2093833737;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);
a_1268();return;
a_G34:a_P[0]=2093833737;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);
a_1268();return;
} /* listfill */
static void a_1434(int a_F1,int a_F2,int a_F3,int a_F4){ /* listdeclarationtail+>a+>a+>a+>a */
int a_L5;int a_P[1];
a_1058(a_F2,a_P);a_L5=a_P[0];
if(!__equal(a_L5,16777520)){ goto a_G4;}
a_1438(a_F2,a_F1);
a_G4:if(__lseq(a_F3,0)){return;}
a_1012(2106125286);
a_1017(a_F2);
a_1015(a_F3);
if(!__less(a_F3,3)){ goto a_G10;}
a_1015(a_F4); goto a_G11;
a_G10:a_1017(a_F4);
a_G11:a_1012(2106125324);return;
} /* listdeclarationtail */
static void a_1426(int a_F1,int a_F2){ /* externaldeclarer+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_P[4];
a_1428(a_P);a_L3=a_P[0];a_L4=a_P[1];a_L5=a_P[2];a_L6=a_P[3];
if(!__is(a_L6)){ goto a_G4;}
a_G3:a_1268();return;
a_G4:a_1058(a_L3,a_P);a_L7=a_P[0];
if(__equal(a_L7,16777520)){ goto a_G9;}
if(__equal(a_L7,a_F1)){ goto a_G9;}
a_1455(a_L3,a_F1);
a_L6=1;
a_G9:a_P[0]=a_L6;a_1246(a_L3,a_F2,a_P);a_L6=a_P[0];
if(__is(a_L6)){ goto a_G3;}
a_1434(a_F1,a_L3,0,-1);
a_1447(a_F1,a_L3,a_L4);
a_1439(a_F1,a_L3,a_L4);
if(!a_1205(a_L3,256)){ goto a_G17;}
a_P[0]=2093833728;a_P[1]=a_F1;a_P[2]=a_L3;a_1040(-1,3,a_P);
a_G17:a_1266(a_L3,a_L5);
a_1421(a_L3);
a_1421(1454738932);
a_1421(a_L5);return;
} /* externaldeclarer */
static void a_1441(int a_F1,int a_F2,int a_A[1]){ /* prototype+>a+>a+>a> */
int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[4];
a_1114(3429890,a_P);a_L4=a_P[0];
a_1429(a_P);a_L5=a_P[0];a_L7=a_P[1];a_L6=a_P[2];a_L9=a_P[3];
if(__is(a_L9)){ goto a_G14;}
if(!__is(a_L6)){ goto a_G10;}
a_L4=0;
if(!__equal(a_A[0],3)){ goto a_G9;}
a_G7:a_P[0]=2093833822;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_L9=1; goto a_G14;
a_G9:a_A[0]=4; goto a_G14;
a_G10:if(__equal(a_A[0],4)){ goto a_G7;}
a_A[0]=3;
a_G14:if(!__is(a_L9)){ goto a_G16;}
a_G15:a_1268();return;
a_G16:a_1058(a_L5,a_P);a_L8=a_P[0];
if(__equal(a_L8,16777520)){ goto a_G21;}
if(__equal(a_L8,a_F1)){ goto a_G21;}
a_1455(a_L5,a_F1);
a_L9=1;
a_G21:if(__is(a_L9)){ goto a_G27;}
if(!__equal(a_L4,1)){ goto a_G24;}
a_P[0]=a_L9;a_1247(a_L5,a_F2,a_P);a_L9=a_P[0]; goto a_G27;
a_G24:if(!__equal(a_L4,2)){ goto a_G26;}
a_P[0]=a_L9;a_1249(a_L5,a_F2,a_P);a_L9=a_P[0]; goto a_G27;
a_G26:a_1248(a_L5,a_F2);
a_G27:if(__is(a_L9)){ goto a_G15;}
a_1434(a_F1,a_L5,0,-1);
a_1447(a_F1,a_L5,a_L7);
if(__equal(a_L4,0)){ goto a_G33;}
a_1439(a_F1,a_L5,a_L7);
a_G33:a_1421(a_L5);
if(!__equal(1454738932,a_1062)){return;}
a_1077();
a_1435(a_F1,a_L5);return;
} /* prototype */
static void a_1424(int a_F1,int a_F2,int a_F3,int a_F4){ /* declarer+>a+>a+>a+>a */
int a_L5;int a_L6;int a_L7;int a_L8;int a_P[4];
a_1429(a_P);a_L5=a_P[0];a_L6=a_P[1];a_L8=a_P[3];
if(!__is(a_L8)){ goto a_G4;}
a_G3:a_1268();return;
a_G4:a_1058(a_L5,a_P);a_L7=a_P[0];
if(__equal(a_L7,16777520)){ goto a_G9;}
if(__equal(a_L7,a_F1)){ goto a_G9;}
a_1455(a_L5,a_F1);
a_L8=1;
a_G9:a_P[0]=a_L8;a_1245(a_L5,a_F2,a_P);a_L8=a_P[0];
if(__is(a_L8)){ goto a_G3;}
a_1434(a_F1,a_L5,a_F3,a_F4);
a_1447(a_F1,a_L5,a_L6);
a_1439(a_F1,a_L5,a_L6);
a_1421(a_L5);
if(!__equal(1454738932,a_1062)){return;}
a_1077();
a_1435(a_F1,a_L5);return;
} /* declarer */
static void a_1422(int a_F2,int a_A[1]){ /* declaration+>a>+>a */
int a_L3;int a_L4;int a_L5;int a_P[2];
a_1314(a_P);a_L3=a_P[0];
if(!__noteq(a_F2,16777544)){ goto a_G13;}
a_1450(a_P);a_L4=a_P[0];a_L5=a_P[1];
if(!__mreq(a_L4,0)){ goto a_G13;}
if(!__mreq(a_A[0],3)){ goto a_G8;}
a_G6:a_P[0]=2093833822;a_P[1]=a_F2;a_1040(-1,2,a_P);
a_G7:a_1268();return;
a_G8:if(!__equal(a_A[0],1)){ goto a_G11;}
a_P[0]=2093833797;a_1040(-1,1,a_P); goto a_G7;
a_G11:a_A[0]=2;
a_1424(a_F2,a_L3,a_L4,a_L5);return;
a_G13:if(!__equal(a_A[0],1)){ goto a_G15;}
a_1426(a_F2,a_L3);return;
a_G15:if(__equal(a_A[0],2)){ goto a_G6;}
a_P[0]=a_A[0];a_1441(a_F2,a_L3,a_P);a_A[0]=a_P[0];return;
} /* declaration */
static void a_1423(int a_F1,int a_F2){ /* declarationseries+>a+>a */
int a_P[1];
a_G1:a_P[0]=a_F1;a_1422(a_F2,a_P);a_F1=a_P[0];
if(!__equal(1454738968,a_1062)){ goto a_G4;}
a_1077(); goto a_G1;
a_G4:if(!__equal(1454738974,a_1062)){ goto a_G6;}
a_1077();return;
a_G6:a_1263(1454738974);
a_1269();return;
} /* declarationseries */
static void a_1454(int a_F1){ /* tabledeclaration+>a */

a_1423(a_F1,16777544);return;
} /* tabledeclaration */
static void a_1452(int a_F1){ /* stackdeclaration+>a */

a_1423(a_F1,16777548);return;
} /* stackdeclaration */
static void a_1453(void){ /* staticstackdeclaration */

a_1423(0,16777554);return;
} /* staticstackdeclaration */
static void a_1420(void){ /* @root */

} /* @root */
static void a_1458(void){ /* firstpass */

a_1359();
if(a_1147()){ goto a_G4;}
a_1464();
a_G4:if(a_1147()){ goto a_G6;}
a_1360();
a_G6:a_1043();
if(!a_1147()){ goto a_G9;}
a_1046();
a_G9:a_1461();return;
} /* firstpass */
static void a_1462(void){ /* secondpass */

a_1297();
a_1078(114);
a_1459();
if(a_1147()){ goto a_G6;}
a_1457();
a_G6:if(!a_1147()){return;}
a_1046();
a_1300();return;
} /* secondpass */
static void a_1463(void){ /* thirdpass */

a_1085();
a_1460();
a_1046();
a_1295();return;
} /* thirdpass */
static void a_1456(void){ /* @root */

a_1358();
if(!a_1147()){ goto a_G4;}
exit(1);return;
a_G4:a_1078(119);
if(!a_1147()){ goto a_G7;}
a_G6:exit(4);return;
a_G7:a_1458();
if(!a_1147()){ goto a_G10;}
a_G9:exit(2);return;
a_G10:a_1328();
if(!a_1147()){ goto a_G14;}
a_1046(); goto a_G6;
a_G14:a_1462();
if(a_1147()){ goto a_G9;}
a_1463();
if(!a_1147()){return;} goto a_G9;
} /* @root */
static void a_1475(void){ /* skipsource */
int a_P[1];
if(a_1029(a_P)){return;}
if(a_1025(2106125294)){ goto a_G7;}
if(a_1025(2106125358)){ goto a_G7;}
if(a_1025(2106125362)){ goto a_G7;}
if(a_1025(2106125366)){ goto a_G7;}
if(!a_1025(2106125229)){ goto a_G8;}
a_G7:a_1074(a_P);return;
a_G8:if(!a_1025(2106125346)){ goto a_G14;}
a_1074(a_P);
a_1475();
a_1071(2106125224);
if(a_1037(a_P)){return;}
a_1072(a_P);return;
a_G14:if(a_1025(2106125305)){return;} goto a_G7;
} /* skipsource */
static void a_1474(void){ /* skipaffixes */

a_G1:if(!a_1025(2106125321)){return;}
a_1475(); goto a_G1;
} /* skipaffixes */
static void a_1472(void){ /* rulebody */
int a_P[1];
if(!a_1025(2106125279)){ goto a_G3;}
a_1074(a_P);
a_G3:if(!a_1025(2106125290)){ goto a_G5;}
a_1034(2106125235);
a_G5:if(!a_1025(2106125221)){ goto a_G8;}
a_1034(2106125221);
a_1469();return;
a_G8:a_1467();return;
} /* rulebody */
static void a_1469(void){ /* classification */

a_G1:a_1071(2106125217);
a_1034(2106125217);
a_1071(2106125238);
a_1466();
if(!a_1025(2106125340)){return;} goto a_G1;
} /* classification */
static void a_1466(void){ /* alternative */

a_G1:a_1470();
if(!a_1025(2106125238)){return;} goto a_G1;
} /* alternative */
static void a_1467(void){ /* altsequence */

a_G1:a_1466();
if(!a_1025(2106125340)){return;} goto a_G1;
} /* altsequence */
static void a_1470(void){ /* member */
int a_L1;int a_P[1];
if(!a_1025(2106125312)){ goto a_G4;}
a_1472();
a_1071(2106125232);return;
a_G4:if(!a_1025(2106125263)){ goto a_G6;}
a_1034(2106125263);return;
a_G6:if(!a_1025(2106125275)){ goto a_G8;}
a_1074(a_P);return;
a_G8:if(a_1025(2106125321)){return;}
if(a_1025(2106125302)){return;}
a_1074(a_P);a_L1=a_P[0];
if(!a_1205(a_L1,128)){ goto a_G13;}
a_1468(a_L1);
a_G13:a_1474();return;
} /* member */
static void a_1468(int a_F1){ /* checkmacrorule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
if(a_1205(a_F1,524288)){return;}
if(!a_1205(a_F1,262144)){ goto a_G6;}
a_P[0]=2093833847;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_1294(a_F1,262144);
a_1449(a_F1,524288);return;
a_G6:a_1449(a_F1,262144);
a_1086(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1473(a_F1,a_P);a_L4=a_P[0];a_L5=a_P[1];
a_1084(a_L4,a_L5);
a_1472();
a_1294(a_F1,262144);
a_1449(a_F1,524288);
a_1084(a_L2,a_L3);return;
} /* checkmacrorule */
static void a_1457(void){ /* checkmacrorules */
int a_L1;int a_P[1];
a_L1=0;
a_G2:a_P[0]=a_L1;if(!a_1471(a_P)){return;}a_L1=a_P[0];
a_1468(a_L1); goto a_G2;
} /* checkmacrorules */
static void a_1465(void){ /* @root */

} /* @root */
static void a_1543(int a_F1,int a_F2){ /* pushRULE+>a+>a */

__next(a_1007,a_1493);
if(!__equal(a_1500,3)){return;}
a_1515(a_F1,a_F2);return;
} /* pushRULE */
static void a_1550(int a_F1){ /* setupformalstack+>a */
int a_L2;int a_L3;int a_P[1];
__scratch(a_1022);
a_1050(a_F1,a_P);a_L2=a_P[0];
a_G3:if(__equal(a_L2,0)){return;}
a_1058(a_L2,a_P);a_L3=a_P[0];
 a_extension(a_1022,6);to_LIST(a_1022)->top[5]=-1;to_LIST(a_1022)->top[4]=a_L3;to_LIST(a_1022)->top[6]=a_L2;to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
if(__equal(a_L3,16777596)){ goto a_G8;}
if(!__equal(a_L3,16777602)){ goto a_G10;}
a_G8:a_1054(a_L2,a_P);to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-5]=a_P[0];
a_1055(a_L2,a_P);to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-4]=a_P[0];
a_G10:a_1050(a_L2,a_P);a_L2=a_P[0]; goto a_G3;
} /* setupformalstack */
static void a_1551(int a_A[1]){ /* setuplabel+a> */
int a_P[1];
if(!a_1025(2106125279)){ goto a_G5;}
a_1074(a_P);a_A[0]=a_P[0];
 a_extension(a_1022,6);to_LIST(a_1022)->top[5]=0;to_LIST(a_1022)->top[4]=16777654;to_LIST(a_1022)->top[6]=a_A[0];to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
a_A[0]=to_LIST(a_1022)->aupb;return;
a_G5:a_A[0]=0;return;
} /* setuplabel */
static void a_1552(void){ /* setuplocals */
int a_L1;int a_P[1];
if(!a_1025(2106125290)){return;}
a_G2:if(a_1025(2106125235)){return;}
a_1074(a_P);a_L1=a_P[0];
 a_extension(a_1022,6);to_LIST(a_1022)->top[5]=-1;to_LIST(a_1022)->top[4]=16777650;to_LIST(a_1022)->top[6]=a_L1;to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
  goto a_G2;
} /* setuplocals */
static void a_1553(int a_F1,int a_A[1]){ /* startrange+>a+a> */
int a_L3;int a_L4;
a_1543(1048577,0);
a_A[0]=a_1493;
if(!__is(a_F1)){ goto a_G5;}
to_LIST(a_1022)->offset[a_F1-1]=a_A[0];
a_G5:a_L3=to_LIST(a_1022)->alwb;
a_L4=0;
a_G7:if(__more(a_L3,to_LIST(a_1022)->aupb)){return;}
{register int a_r1=to_LIST(a_1022)->offset[a_L3-2];
 if(!(a_r1==16777612||a_r1==16777617||a_r1==16777623||a_r1==16777650)){ goto a_G19;}
}
__incr(a_L4);
a_1543(0,a_L3);
if(!__less(to_LIST(a_1022)->offset[a_L3-1],0)){ goto a_G19;}
to_LIST(a_1022)->offset[a_L3-1]=a_L4;
if(__noteq(a_1500,3)){ goto a_G18;}
if(__noteq(to_LIST(a_1022)->offset[a_L3-2],16777650)){ goto a_G18;}
if(!__equal(a_1539,0)){ goto a_G17;}
a_1539=a_L4;
a_G17:__max(a_L4,a_1536);
a_G18:a_1509(a_A[0],a_L4,a_L3);
a_G19:__next(a_1022,a_L3); goto a_G7;
} /* startrange */
static void a_1503(int a_F1){ /* closerange+>a */

a_1543(1048578,a_F1);return;
} /* closerange */
static void a_1555(int a_F1,int a_A[1]){ /* utypetoslice+>a+a> */

__boolor(a_F1,16,a_A[0]);return;
} /* utypetoslice */
static int a_1535(int a_F1){ /* inutype+>a */
int a_L2;
__booland(a_F1,1,a_L2);
if(!__noteq(a_L2,0)){ return 0;} return 1;
} /* inutype */
static int a_1541(int a_F1){ /* oututype+>a */
int a_L2;
__booland(a_F1,2,a_L2);
if(!__noteq(a_L2,0)){ return 0;} return 1;
} /* oututype */
static void a_1513(int a_F1){ /* expandmacro+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[2];
a_L2=to_LIST(a_1022)->aupb;
a_1068(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1086(a_P);a_L5=a_P[0];a_L6=a_P[1];
a_1473(a_F1,a_P);a_L7=a_P[0];a_L8=a_P[1];
a_1084(a_L7,a_L8);
if(!__equal(a_1500,2)){ goto a_G8;}
a_1575(); goto a_G9;
a_G8:a_1532();
a_G9:a_1071(2106125324);
a_1084(a_L5,a_L6);
a_1069(a_L3,a_L4);
__unstackto(a_1022,a_L2);return;
} /* expandmacro */
static void a_1542(int a_C,int *a_V){ /* pushBUFFER+*+>a */

a_G1:a_1514(a_V[0]);
if(a_C>1){a_C--;a_V+=1; goto a_G1;} return;
} /* pushBUFFER */
static void a_1534(void){ /* gtransportlist */
int a_P[1];
a_G1:a_1533(2311425,a_P);
a_G2:if(!a_1025(2106125354)){ goto a_G5;}
if(a_1029(a_P)){ goto a_G2;}
a_1074(a_P); goto a_G2;
a_G5:if(a_1025(2106125263)){return;}
if(a_1027(2106125252)){return;} goto a_G1;
} /* gtransportlist */
static void a_1524(void){ /* gextension */
int a_P[1];
a_1074(a_P);
a_1543(1048580,0);
a_1534();
a_1543(1048581,0);return;
} /* gextension */
static void a_1531(void){ /* greadbox */
int a_P[1];
a_1543(1048580,0);
a_1533(2311425,a_P);
a_1543(1048581,0);
a_1543(1048587,0);
a_1071(2106125221);return;
} /* greadbox */
static void a_1520(int a_A[1]){ /* garea+a> */
int a_L2;int a_P[2];
if(!__noteq(a_1500,3)){ goto a_G4;}
a_1034(2106125217);
a_A[0]=0;return;
a_G4:a_A[0]=to_LIST(a_1006)->aupb;
a_1314(a_P);a_L2=a_P[0];
a_P[0]=a_L2;a_1284(a_P);a_L2=a_P[0];
a_G7:a_P[0]=2106125245;a_P[1]=a_L2;a_1542(2,a_P);
a_G8:if(!a_1025(2106125217)){ goto a_G10;}
a_1514(2106125321);return;
a_G10:if(!a_1025(2106125235)){ goto a_G12;}
a_1514(2106125235); goto a_G8;
a_G12:if(!a_1025(2106125340)){ goto a_G14;}
a_1514(2106125340); goto a_G8;
a_G14:if(a_1029(a_P)){a_L2=a_P[0]; goto a_G7;}
a_1074(a_P);a_L2=a_P[0];
a_1514(a_L2); goto a_G8;
} /* garea */
static void a_1521(void){ /* gclassification */
int a_L1;int a_L2;int a_P[1];
a_G1:a_1071(2106125217);
a_1520(a_P);a_L2=a_P[0];
a_1543(1048580,a_L2);
a_1543(1048582,0);
a_L1=a_1493;
a_1543(1048581,0);
a_1543(1048579,0);
a_1519();
if(!a_1025(2106125340)){ goto a_G11;}
a_1543(1048591,0); goto a_G1;
a_G11:to_LIST(a_1007)->offset[a_L1-1]=1048576;return;
} /* gclassification */
static void a_1525(int a_F1,int a_F2){ /* ghandleaffix+>a+>a */

if(!a_1535(a_F2)){ goto a_G3;}
a_1543(1048593,to_LIST(a_1022)->offset[a_F1-1]);
a_G3:if(!a_1541(a_F2)){return;}
a_1514(a_F2);
if(!__mreq(a_F2,2311441)){ goto a_G7;}
a_1514(1048593); goto a_G8;
a_G7:a_1514(1048594);
a_G8:a_1514(a_F1);return;
} /* ghandleaffix */
static void a_1527(int a_F1,int a_F2){ /* ghandlevarargblock+>a+>a */
int a_L3;int a_P[1];
a_G1:__next(a_1022,a_F1);
a_1058(a_F2,a_P);a_L3=a_P[0];
a_1050(a_F2,a_P);a_F2=a_P[0];
{ if(a_L3==16777612){ goto a_G5;}
 if(a_L3==16777617){ goto a_G6;}
 if(a_L3==16777623){  goto a_G7;}
  goto a_G8;}
a_G5:a_1525(a_F1,2311425); goto a_G8;
a_G6:a_1525(a_F1,2311426); goto a_G8;
a_G7:a_1525(a_F1,2311427);
a_G8:if(__equal(a_F2,0)){return;} goto a_G1;
} /* ghandlevarargblock */
static void a_1526(int a_F1){ /* ghandleshiftrule+>a */

a_G1:__next(a_1022,a_F1);
{register int a_r1=to_LIST(a_1022)->offset[a_F1-2];
 if(a_r1==16777654){return;}
 if(a_r1==16777612){ goto a_G3;}
 if(a_r1==16777617){ goto a_G4;}
 if(a_r1==16777623){  goto a_G5;}
  goto a_G1;}
a_G3:a_1525(a_F1,2311425); goto a_G1;
a_G4:a_1525(a_F1,2311426); goto a_G1;
a_G5:a_1525(a_F1,2311427); goto a_G1;
} /* ghandleshiftrule */
static int a_1528(void){ /* glimit */

if(a_1025(2106125362)){ return 1;}
if(a_1025(2106125366)){ return 1;}
if(a_1025(2106125294)){ return 1;}
if(a_1025(2106125358)){ return 1;}
if(!a_1025(2106125229)){ return 0;} return 1;
} /* glimit */
static void a_1533(int a_F1,int a_A[1]){ /* gsimpleaffix+>a+a> */
int a_L3;int a_L4;int a_P[1];
a_A[0]=0;
if(a_1029(a_P)){return;}
if(!a_1528()){ goto a_G5;}
a_G4:a_1074(a_P);return;
a_G5:if(!a_1025(2106125346)){ goto a_G12;}
a_1074(a_P);
a_1555(a_F1,a_P);a_L4=a_P[0];
a_1533(a_L4,a_P);
a_1071(2106125224);
if(a_1029(a_P)){return;} goto a_G4;
a_G12:if(a_1025(2106125305)){return;}
a_1074(a_P);a_L3=a_P[0];
a_1058(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777629){ goto a_G16;}
 if(a_L4==16777612||a_L4==16777617||a_L4==16777623||a_L4==16777650){  goto a_G17;}
 return;}
a_G16:a_A[0]=a_L3;return;
a_G17:a_1525(a_L3,a_F1);return;
} /* gsimpleaffix */
static void a_1529(int a_F1,int a_A[1]){ /* gmatchformalactual+>a+a> */
int a_L3;int a_L4;int a_P[1];
{ if(a_F1==16777607||a_F1==16777602||a_F1==16777596){ goto a_G2;}
 if(a_F1==16777635){ goto a_G7;}
 if(a_F1==16777612){ goto a_G8;}
 if(a_F1==16777617){ goto a_G9;}
 if(a_F1==16777623){  goto a_G10;}
  goto a_G11;}
a_G2:a_1074(a_P);a_L3=a_P[0];
a_1058(a_L3,a_P);a_L4=a_P[0];
if(!__equal(a_L4,16777629)){ goto a_G6;}
a_A[0]=a_L3;return;
a_G6:a_A[0]=0;return;
a_G7:a_1074(a_P);a_A[0]=a_P[0];return;
a_G8:a_1533(2311425,a_P);a_A[0]=a_P[0];return;
a_G9:a_1533(2311426,a_P);a_A[0]=a_P[0];return;
a_G10:a_1533(2311427,a_P);a_A[0]=a_P[0];return;
a_G11:a_1063(a_1001,16777449,310);return;
} /* gmatchformalactual */
static void a_1517(int a_F1){ /* gactualrule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[1];
a_1543(1048580,0);
a_L2=to_LIST(a_1006)->aupb;
a_L5=0;a_L6=0;
a_1050(a_F1,a_P);a_L3=a_P[0];
a_G5:if(!a_1025(2106125321)){ goto a_G15;}
a_1058(a_L3,a_P);a_L4=a_P[0];
if(!__equal(a_L4,16777629)){ goto a_G11;}
a_1050(a_L3,a_P);a_L3=a_P[0];
a_L5=a_L3;
a_1058(a_L3,a_P);a_L4=a_P[0];
a_G11:a_1529(a_L4,a_P);a_L6=a_P[0];
a_1050(a_L3,a_P);a_L3=a_P[0];
if(!__equal(a_L3,0)){ goto a_G5;}
a_L3=a_L5; goto a_G5;
a_G15:if(__equal(a_L6,0)){ goto a_G20;}
if(!__equal(a_F1,483807568)){ goto a_G18;}
a_1526(a_L6); goto a_G20;
a_G18:if(a_1205(a_F1,131072)){ goto a_G20;}
a_1527(a_L6,a_L5);
a_G20:if(!a_1205(a_F1,512)){ goto a_G22;}
a_1543(1048582,0);
a_G22:a_L6=a_L2;
a_G23:if(__mreq(a_L6,to_LIST(a_1006)->aupb)){ goto a_G31;}
__incr(a_L6);
a_L8=to_LIST(a_1006)->offset[a_L6];
__incr(a_L6);
a_L7=to_LIST(a_1006)->offset[a_L6];
__incr(a_L6);
a_1543(a_L7,to_LIST(a_1022)->offset[to_LIST(a_1006)->offset[a_L6]-1]);
a_1510(a_L8,to_LIST(a_1006)->offset[a_L6]); goto a_G23;
a_G31:__unstackto(a_1006,a_L2);
if(!a_1205(a_F1,1024)){ goto a_G34;}
a_1543(1048583,0);return;
a_G34:a_1543(1048581,0);return;
} /* gactualrule */
static void a_1522(void){ /* gcompound */
int a_L1;
a_L1=to_LIST(a_1022)->aupb;
a_1532();
__unstackto(a_1022,a_L1);return;
} /* gcompound */
static void a_1518(void){ /* galtsequence */

a_G1:a_1530();
a_1543(1048579,0);
a_1519();
if(!a_1025(2106125340)){return;}
a_1543(1048591,0); goto a_G1;
} /* galtsequence */
static void a_1519(void){ /* galttail */

a_G1:if(!a_1025(2106125238)){return;}
a_1530(); goto a_G1;
} /* galttail */
static void a_1530(void){ /* gmember */
int a_L1;int a_P[1];
if(!a_1025(2106125312)){ goto a_G4;}
a_1522();
a_1071(2106125232);return;
a_G4:if(!a_1025(2106125263)){ goto a_G6;}
a_1524();return;
a_G6:if(!a_1025(2106125275)){ goto a_G9;}
a_1074(a_P);a_L1=a_P[0];
a_1543(1048586,to_LIST(a_1022)->offset[a_L1-1]);return;
a_G9:if(!a_1025(2106125321)){ goto a_G11;}
a_1543(1048584,0);return;
a_G11:if(!a_1025(2106125302)){ goto a_G13;}
a_1543(1048585,0);return;
a_G13:a_1074(a_P);a_L1=a_P[0];
a_1545=a_L1;
if(!__is(a_1512)){ goto a_G18;}
if(!a_1205(a_L1,128)){ goto a_G18;}
a_1513(a_L1);return;
a_G18:a_1517(a_L1);return;
} /* gmember */
static void a_1532(void){ /* grulebody */
int a_L1;int a_L2;int a_P[1];
a_1551(a_P);a_L1=a_P[0];
a_1552();
a_1553(a_L1,a_P);a_L2=a_P[0];
if(!a_1025(2106125221)){ goto a_G7;}
a_1531();
a_1521(); goto a_G8;
a_G7:a_1518();
a_G8:a_1503(a_L2);return;
} /* grulebody */
static void a_1547(int a_F1,int a_F2,int a_F3){ /* setRULEflag+>a+>a+>a */

__addmult(a_F2,2,a_F1,a_F1);
__boolor(to_LIST(a_1007)->offset[a_F1-1],a_F3,to_LIST(a_1007)->offset[a_F1-1]);return;
} /* setRULEflag */
static void a_1502(int a_F1,int a_F2,int a_F3){ /* clearRULEflag+>a+>a+>a */

__addmult(a_F2,2,a_F1,a_F1);
__boolinvert(a_F3,a_F3);
__booland(to_LIST(a_1007)->offset[a_F1-1],a_F3,to_LIST(a_1007)->offset[a_F1-1]);return;
} /* clearRULEflag */
static void a_1505(int a_F1,int a_F2,int a_F3){ /* copyUf1toUf2+>a+>a+>a */
int a_L4;int a_L5;
a_L4=1;
a_G2:__addmult(a_L4,2,a_F1,a_L5);
__booland(to_LIST(a_1007)->offset[a_L5-1],1048576,a_L5);
if(__noteq(a_L5,0)){return;}
__addmult(a_L4,2,a_F1,a_L5);
__booland(to_LIST(a_1007)->offset[a_L5-1],a_F2,a_L5);
if(!__noteq(a_L5,0)){ goto a_G9;}
a_1547(a_F1,a_L4,a_F3); goto a_G10;
a_G9:a_1502(a_F1,a_L4,a_F3);
a_G10:__incr(a_L4); goto a_G2;
} /* copyUf1toUf2 */
static void a_1538(int a_F1,int a_F2,int a_F3){ /* mergeUf1toUf2+>a+>a+>a */
int a_L4;int a_L5;
a_L4=1;
a_G2:__addmult(a_L4,2,a_F1,a_L5);
__booland(to_LIST(a_1007)->offset[a_L5-1],1048576,a_L5);
if(__noteq(a_L5,0)){return;}
__addmult(a_L4,2,a_F1,a_L5);
__booland(to_LIST(a_1007)->offset[a_L5-1],a_F2,a_L5);
if(!__noteq(a_L5,0)){ goto a_G14;}
if(__noteq(a_F3,1)){ goto a_G13;}
__addmult(a_L4,2,a_F1,a_L5);
__booland(to_LIST(a_1007)->offset[a_L5-1],a_F3,a_L5);
if(__noteq(a_L5,0)){ goto a_G13;}
a_1496=1;
a_G13:a_1547(a_F1,a_L4,a_F3);
a_G14:__incr(a_L4); goto a_G2;
} /* mergeUf1toUf2 */
static void a_1506(int a_F1,int a_F2){ /* copyjumpUf+>a+>a */
int a_L3;int a_L4;
a_L3=1;
a_G2:__addmult(a_L3,2,a_F1,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],1048576,a_L4);
if(__noteq(a_L4,0)){ goto a_G11;}
__addmult(a_L3,2,a_F1,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],1,a_L4);
if(!__noteq(a_L4,0)){ goto a_G9;}
a_1547(a_F2,a_L3,8); goto a_G10;
a_G9:a_1502(a_F2,a_L3,8);
a_G10:__incr(a_L3); goto a_G2;
a_G11:__addmult(a_L3,2,a_F2,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],1048576,a_L4);
if(__noteq(a_L4,0)){return;}
a_1502(a_F2,a_L3,8);
__incr(a_L3); goto a_G11;
} /* copyjumpUf */
static void a_1548(int a_F1,int a_F2,int a_F3){ /* setflagsforregion+>a+>a+>a */
int a_L4;int a_L5;
a_L4=1;
a_G2:__addmult(a_L4,2,a_F1,a_L5);
__booland(to_LIST(a_1007)->offset[a_L5-1],1048576,a_L5);
if(__noteq(a_L5,0)){return;}
__addmult(a_L4,2,a_F1,a_L5);
__booland(to_LIST(a_1007)->offset[a_L5-1],8,a_L5);
if(!__noteq(a_L5,0)){ goto a_G9;}
a_1547(a_F2,a_L4,2);
a_G9:__addmult(a_L4,2,a_F1,a_L5);
__booland(to_LIST(a_1007)->offset[a_L5-1],a_F3,a_L5);
if(!__noteq(a_L5,0)){ goto a_G13;}
a_1547(a_F2,a_L4,4);
a_G13:a_1502(a_F2,a_L4,8);
__incr(a_L4); goto a_G2;
} /* setflagsforregion */
static void a_1544(int a_F1,int a_F2){ /* recoverflagsfromregion+>a+>a */
int a_L3;int a_L4;
a_L3=1;
a_G2:__addmult(a_L3,2,a_F1,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],1048576,a_L4);
if(__noteq(a_L4,0)){return;}
__addmult(a_L3,2,a_F2,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],8,a_L4);
if(!__noteq(a_L4,0)){ goto a_G9;}
a_1547(a_F1,a_L3,8); goto a_G10;
a_G9:a_1502(a_F1,a_L3,8);
a_G10:__incr(a_L3); goto a_G2;
} /* recoverflagsfromregion */
static void a_1549(int a_F1){ /* setflagsforrule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[1];
a_1050(a_F1,a_P);a_L3=a_P[0];
a_L5=0;
a_L2=to_LIST(a_1007)->offset[to_LIST(a_1007)->aupb];
a_G4:if(__equal(a_L3,0)){return;}
a_1058(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777612){ goto a_G7;}
 if(a_L4==16777617||a_L4==16777623){  goto a_G8;}
  goto a_G10;}
a_G7:__incr(a_L5); goto a_G10;
a_G8:__incr(a_L5);
a_1547(a_L2,a_L5,2);
a_G10:a_1050(a_L3,a_P);a_L3=a_P[0]; goto a_G4;
} /* setflagsforrule */
static int a_1478(int a_F1,int a_A[1]){ /* Bdata+>a+a> */

if(!__equal(to_LIST(a_1007)->offset[a_1498-1],a_F1)){ return 0;}
a_A[0]=to_LIST(a_1007)->offset[a_1498];
__previous(a_1007,a_1498); return 1;
} /* Bdata */
static void a_1481(int a_F1){ /* Bsetflag+>a */
int a_L2;
a_L2=a_1498;
__next(a_1007,a_L2);
to_LIST(a_1007)->offset[a_L2-1]=a_F1;return;
} /* Bsetflag */
static void a_1480(int a_F1){ /* Bsetdata+>a */
int a_L2;
a_L2=a_1498;
__next(a_1007,a_L2);
to_LIST(a_1007)->offset[a_L2]=a_F1;return;
} /* Bsetdata */
static void a_1477(void){ /* Bback */

__previous(a_1007,a_1498);return;
} /* Bback */
static void a_1479(int a_A[1]){ /* Bgetptr+a> */

a_A[0]=a_1498;
__next(a_1007,a_A[0]);return;
} /* Bgetptr */
static void a_1499(int a_F1){ /* Uregion+>a */

a_1505(a_F1,4,16);
a_G2:a_1495(a_F1);
a_1505(a_F1,8,16);
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048591)){ goto a_G6;}
__previous(a_1007,a_1498); goto a_G2;
a_G6:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048587)){ goto a_G10;}
__previous(a_1007,a_1498);
if(a_1494(a_F1,4)){ goto a_G10;}
a_1063(a_1001,16777442,453);return;
a_G10:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048577)){ goto a_G12;}
__previous(a_1007,a_1498); goto a_G13;
a_G12:a_1477(); goto a_G10;
a_G13:a_1538(a_F1,8,1);return;
} /* Uregion */
static int a_1494(int a_F1,int a_F2){ /* Uactualrule+>a+>a */
int a_L3;int a_L4;int a_P[1];
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048581)){ goto a_G3;}
a_G2:__previous(a_1007,a_1498); goto a_G6;
a_G3:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048583)){ return 0;}
__previous(a_1007,a_1498);
a_1505(a_F1,32,8);
a_G6:if(!a_1478(1048593,a_P)){ goto a_G8;}a_L3=a_P[0];
a_1547(a_F1,a_L3,8); goto a_G6;
a_G8:if(!a_1478(1048594,a_P)){ goto a_G14;}a_L3=a_P[0];
__addmult(a_L3,2,a_F1,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],8,a_L4);
if(__noteq(a_L4,0)){ goto a_G13;}
a_1481(1048595);
a_G13:a_1502(a_F1,a_L3,8); goto a_G6;
a_G14:if(!a_1478(1048595,a_P)){ goto a_G20;}a_L3=a_P[0];
__addmult(a_L3,2,a_F1,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],8,a_L4);
if(!__noteq(a_L4,0)){ goto a_G13;}
a_1481(1048594); goto a_G13;
a_G20:if(__equal(to_LIST(a_1007)->offset[a_1498-1],1048576)){ goto a_G2;}
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048582)){ goto a_G25;}
__previous(a_1007,a_1498);
a_1538(a_F1,a_F2,8); goto a_G6;
a_G25:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048580)){ goto a_G27;}
__previous(a_1007,a_1498); return 1;
a_G27:a_1063(a_1001,16777438,474); return 1;
} /* Uactualrule */
static int a_1497(int a_F1,int a_F2){ /* Umember+>a+>a */
int a_L3;int a_P[1];
if(!a_1478(1048586,a_P)){ goto a_G3;}a_L3=a_P[0];
a_1506(a_L3,a_F1); return 1;
a_G3:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048584)){ goto a_G6;}
__previous(a_1007,a_1498);
a_1505(a_F1,2,8); return 1;
a_G6:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048585)){ goto a_G9;}
__previous(a_1007,a_1498);
a_1505(a_F1,a_F2,8); return 1;
a_G9:if(a_1494(a_F1,a_F2)){ return 1;}
if(!a_1478(1048578,a_P)){ return 0;}a_L3=a_P[0];
a_1548(a_F1,a_L3,a_F2);
a_1499(a_L3);
a_1544(a_F1,a_L3); return 1;
} /* Umember */
static void a_1495(int a_F1){ /* Ualternative+>a */

a_1505(a_F1,2,8);
a_G2:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048579)){ goto a_G6;}
__previous(a_1007,a_1498);
if(a_1497(a_F1,16)){return;}
a_1063(a_1001,16777433,486);return;
a_G6:if(!a_1497(a_F1,4)){return;} goto a_G2;
} /* Ualternative */
static void a_1554(int a_F1){ /* traverseRULE+>a */
int a_L2;int a_P[1];
a_1549(a_F1);
a_G2:a_1498=to_LIST(a_1007)->aupb;
if(a_1478(1048578,a_P)){a_L2=a_P[0]; goto a_G5;}
a_1063(a_1001,16777427,491);return;
a_G5:a_1496=0;
a_1499(a_L2);
if(__equal(a_1496,0)){return;} goto a_G2;
} /* traverseRULE */
static void a_1490(int a_F1,int a_F2,int a_A[1]){ /* Lscani+>a+>a+a> */
int a_L4;int a_L5;int a_P[1];
a_L4=a_F2;a_L5=a_F2;
a_A[0]=a_F1;
a_G3:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048591)){ goto a_G8;}
__previous(a_1007,a_1498);
a_L4=a_A[0];
a_A[0]=a_F1;
a_L5=a_F2; goto a_G3;
a_G8:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048584)){ goto a_G11;}
a_G9:__previous(a_1007,a_1498);
a_1480(a_A[0]); goto a_G3;
a_G11:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048585)){ goto a_G15;}
a_G12:__previous(a_1007,a_1498);
a_1480(a_L5);
a_A[0]=a_L5; goto a_G3;
a_G15:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048579)){ goto a_G18;}
__previous(a_1007,a_1498);
a_L5=a_L4; goto a_G3;
a_G18:if(__equal(to_LIST(a_1007)->offset[a_1498-1],1048581)){ goto a_G9;}
if(__equal(to_LIST(a_1007)->offset[a_1498-1],1048582)){ goto a_G12;}
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048580)){ goto a_G28;}
__previous(a_1007,a_1498);
a_1479(a_P);a_A[0]=a_P[0]; goto a_G3;
a_G28:if(a_1478(1048586,a_P)){a_A[0]=a_P[0]; goto a_G3;}
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048578)){ goto a_G32;}
__previous(a_1007,a_1498);
a_1490(a_A[0],a_L5,a_P);a_A[0]=a_P[0]; goto a_G3;
a_G32:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048577)){ goto a_G35;}
__previous(a_1007,a_1498);
a_1480(a_A[0]);return;
a_G35:a_1477(); goto a_G3;
} /* Lscani */
static void a_1492(int a_F1){ /* Lunroll+>a */
int a_L2;
a_L2=to_LIST(a_1007)->offset[a_F1];
if(__equal(a_L2,-1)){return;}
if(__equal(a_L2,-2)){return;}
if(!__equal(a_L2,0)){ goto a_G6;}
a_1063(a_1001,16777421,519);return;
a_G6:if(__equal(to_LIST(a_1007)->offset[a_L2-1],1048580)){return;}
to_LIST(a_1007)->offset[a_F1]=0;
a_1492(a_L2);
to_LIST(a_1007)->offset[a_F1]=to_LIST(a_1007)->offset[a_L2];return;
} /* Lunroll */
static void a_1491(void){ /* Lscanii */
int a_L1;
a_L1=to_LIST(a_1007)->alwb;
a_G2:if(__more(a_L1,to_LIST(a_1007)->aupb)){return;}
if(__equal(to_LIST(a_1007)->offset[a_L1-1],1048581)){ goto a_G5;}
if(!__equal(to_LIST(a_1007)->offset[a_L1-1],1048582)){ goto a_G6;}
a_G5:a_1492(a_L1);
a_G6:__next(a_1007,a_L1); goto a_G2;
} /* Lscanii */
static void a_1489(void){ /* Lfindlabels */
int a_P[1];
a_1498=to_LIST(a_1007)->aupb;
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048578)){ goto a_G4;}
__previous(a_1007,a_1498); goto a_G5;
a_G4:a_1063(a_1001,16777417,527);return;
a_G5:a_1490(-1,-2,a_P);
a_1491();return;
} /* Lfindlabels */
static void a_1537(int a_F1,int a_F2){ /* mergeDUflags+>a+>a */
int a_L3;int a_L4;
a_L3=1;
a_G2:__addmult(a_L3,2,a_F1,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],1048576,a_L4);
if(__noteq(a_L4,0)){return;}
__addmult(a_L3,2,a_F2,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],256,a_L4);
if(!__noteq(a_L4,0)){ goto a_G9;}
a_1547(a_F1,a_L3,256);
a_G9:__addmult(a_L3,2,a_F2,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],512,a_L4);
if(!__noteq(a_L4,0)){ goto a_G13;}
a_1547(a_F1,a_L3,512);
a_G13:__incr(a_L3); goto a_G2;
} /* mergeDUflags */
static int a_1488(int a_F1){ /* DUrule+>a */
int a_L2;int a_P[1];
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048581)){ goto a_G3;}
a_G2:__previous(a_1007,a_1498); goto a_G5;
a_G3:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048583)){ return 0;} goto a_G2;
a_G5:if(!a_1478(1048593,a_P)){ goto a_G7;}a_L2=a_P[0];
a_1547(a_F1,a_L2,256); goto a_G5;
a_G7:if(!a_1478(1048594,a_P)){ goto a_G9;}a_L2=a_P[0];
a_1547(a_F1,a_L2,512); goto a_G5;
a_G9:if(__equal(to_LIST(a_1007)->offset[a_1498-1],1048595)){ goto a_G2;}
if(__equal(to_LIST(a_1007)->offset[a_1498-1],1048576)){ goto a_G2;}
if(__equal(to_LIST(a_1007)->offset[a_1498-1],1048582)){ goto a_G2;}
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048580)){ return 1;}
__previous(a_1007,a_1498); return 1;
} /* DUrule */
static int a_1486(int a_F1){ /* DUmember+>a */
int a_L2;int a_P[1];
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048586)){ goto a_G3;}
a_G2:__previous(a_1007,a_1498); return 1;
a_G3:if(__equal(to_LIST(a_1007)->offset[a_1498-1],1048584)){ goto a_G2;}
if(__equal(to_LIST(a_1007)->offset[a_1498-1],1048585)){ goto a_G2;}
if(a_1488(a_F1)){ return 1;}
if(!a_1478(1048578,a_P)){ return 0;}a_L2=a_P[0];
a_1487(a_L2);
a_1537(a_F1,a_L2); return 1;
} /* DUmember */
static void a_1485(int a_F1){ /* DUalternative+>a */

a_G1:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048579)){ goto a_G4;}
__previous(a_1007,a_1498);
if(!a_1486(a_F1)){return;}return;
a_G4:if(!a_1486(a_F1)){return;} goto a_G1;
} /* DUalternative */
static void a_1487(int a_F1){ /* DUregion+>a */

a_G1:a_1485(a_F1);
if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048591)){ goto a_G4;}
__previous(a_1007,a_1498); goto a_G1;
a_G4:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048587)){ goto a_G7;}
__previous(a_1007,a_1498);
if(a_1488(a_F1)){}
a_G7:if(!__equal(to_LIST(a_1007)->offset[a_1498-1],1048577)){ goto a_G9;}
__previous(a_1007,a_1498);return;
a_G9:__previous(a_1007,a_1498); goto a_G7;
} /* DUregion */
static void a_1504(void){ /* computeDUflags */
int a_L1;int a_P[1];
a_1498=to_LIST(a_1007)->aupb;
if(a_1478(1048578,a_P)){a_L1=a_P[0]; goto a_G4;}
a_1063(a_1001,16777412,563);return;
a_G4:a_1487(a_L1);return;
} /* computeDUflags */
static void a_1509(int a_F1,int a_F2,int a_F3){ /* diagnoselocal+>a+>a+>a */
int a_L4;int a_P[3];
if(__noteq(a_1500,1)){return;}
if(__noteq(to_LIST(a_1022)->offset[a_F3-2],16777650)){return;}
__addmult(a_F2,2,a_F1,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],256,a_L4);
if(__noteq(a_L4,0)){return;}
__addmult(a_F2,2,a_F1,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],512,a_L4);
if(!__noteq(a_L4,0)){return;}
a_P[0]=2093833860;a_P[1]=a_1546;a_P[2]=to_LIST(a_1022)->offset[a_F3];a_1041(4,-1,3,a_P);return;
} /* diagnoselocal */
static void a_1510(int a_F1,int a_F2){ /* diagnoseoutaffix+>a+>a */
int a_P[3];
if(__noteq(a_1500,1)){return;}
if(__noteq(to_LIST(a_1007)->offset[a_1493-1],1048595)){return;}
if(!__equal(a_F1,2311427)){ goto a_G5;}
a_P[0]=2093833871;a_P[1]=a_1545;a_P[2]=to_LIST(a_1022)->offset[a_F2];a_1041(1,-1,3,a_P);return;
a_G5:a_P[0]=2093833871;a_P[1]=a_1545;a_P[2]=to_LIST(a_1022)->offset[a_F2];a_1041(4,-1,3,a_P);return;
} /* diagnoseoutaffix */
static void a_1508(void){ /* diagnoseformals */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
a_L1=to_LIST(a_1022)->alwb;
a_L2=to_LIST(a_1007)->alwb;
a_L3=1;
a_G4:if(__more(a_L1,to_LIST(a_1022)->aupb)){return;}
{register int a_r1=to_LIST(a_1022)->offset[a_L1-2];
 if(a_r1==16777612){ goto a_G6;}
 if(a_r1==16777623){ goto a_G14;}
 if(a_r1==16777617){  goto a_G13;}
  goto a_G24;}
a_G6:__addmult(a_L3,2,a_L2,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],1,a_L4);
if(__noteq(a_L4,0)){ goto a_G13;}
__addmult(a_L3,2,a_L2,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],512,a_L4);
if(!__noteq(a_L4,0)){ goto a_G13;}
a_G12:a_P[0]=2093833886;a_P[1]=a_1546;a_P[2]=to_LIST(a_1022)->offset[a_L1];a_1041(4,-1,3,a_P);
a_G13:__incr(a_L3); goto a_G24;
a_G14:__addmult(a_L3,2,a_L2,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],1,a_L4);
if(__noteq(a_L4,0)){ goto a_G13;}
__addmult(a_L3,2,a_L2,a_L4);
__booland(to_LIST(a_1007)->offset[a_L4-1],512,a_L4);
if(__noteq(a_L4,0)){ goto a_G12;}
a_P[0]=2093833901;a_P[1]=a_1546;a_P[2]=to_LIST(a_1022)->offset[a_L1];a_1041(4,-1,3,a_P); goto a_G13;
a_G24:__next(a_1022,a_L1); goto a_G4;
} /* diagnoseformals */
static void a_1511(int a_F1){ /* diagnoserule+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
a_1546=a_F1;
a_1086(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1512=0;
a_1500=3;
__scratch(a_1007);
__scratch(a_1006);
{register int a_r1=to_LIST(a_1007)->aupb;a_L4=a_r1;a_1493=a_r1;}
a_1550(a_F1);
a_1532();
a_1071(2106125324);
a_1554(a_F1);
a_1504();
a_1084(a_L2,a_L3);
a_1500=1;
a_1493=a_L4;
a_1550(a_F1);
a_1508();
a_1532();
a_1071(2106125324);
a_1084(a_L2,a_L3);return;
} /* diagnoserule */
static void a_1501(void){ /* assignnodes */
int a_L1;int a_L2;
a_L1=to_LIST(a_1024)->vlwb;
a_1540=0;
a_L2=to_LIST(a_1007)->alwb;
a_G4:if(__more(a_L2,to_LIST(a_1007)->aupb)){return;}
if(!__equal(to_LIST(a_1007)->offset[a_L2-1],1048580)){ goto a_G10;}
if(!__equal(to_LIST(a_1007)->offset[a_L2],0)){ goto a_G10;}
to_LIST(a_1007)->offset[a_L2]=a_L1;
__incr(a_1540);
__next(a_1024,a_L1);
a_G10:__next(a_1007,a_L2); goto a_G4;
} /* assignnodes */
static void a_1570(int a_F1){ /* wlabel+>a */
int a_L2;
a_1274(2106125318);
if(!__equal(a_F1,0)){ goto a_G4;}
a_G3:a_1275(0);return;
a_G4:a_L2=to_LIST(a_1007)->offset[a_F1];
if(__equal(to_LIST(a_1007)->offset[a_F1-1],1048583)){ goto a_G3;}
if(!__equal(a_L2,-1)){ goto a_G9;}
a_1275(-1);return;
a_G9:if(!__equal(a_L2,-2)){ goto a_G11;}
a_1275(-2);return;
a_G11:a_1274(to_LIST(a_1007)->offset[a_L2]);return;
} /* wlabel */
static void a_1577(int a_A[1]){ /* wtransportlist+a> */
int a_L2;int a_P[2];
a_A[0]=0;
a_G2:a_1576(2311425,a_P);
a_G3:if(!a_1025(2106125354)){ goto a_G10;}
a_1514(2106125354);
__incr(a_A[0]);
if(a_1029(a_P)){a_L2=a_P[0]; goto a_G9;}
a_1074(a_P);a_L2=a_P[0];
a_1056(a_L2,a_P);a_L2=a_P[0];
a_G9:a_P[0]=2106125245;a_P[1]=a_L2;a_1542(2,a_P); goto a_G3;
a_G10:if(a_1025(2106125263)){return;}
if(a_1025(2106125252)){return;} goto a_G2;
} /* wtransportlist */
static void a_1568(void){ /* wextension */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
a_1074(a_P);a_L1=a_P[0];
a_1543(1048580,0);
a_1274(2106125263);
a_1274(to_LIST(a_1007)->offset[a_1493]);
a_1278(a_L1);
a_L3=to_LIST(a_1006)->aupb;
a_1577(a_P);a_L2=a_P[0];
a_1275(a_L2);
a_L4=a_L3;
__incr(a_L4);
a_P[0]=a_L4;a_1567(a_P);
__unstackto(a_1006,a_L3);
a_1543(1048581,0);
a_1570(a_1493);
a_1274(2106125238);return;
} /* wextension */
static int a_1571(int a_A[1]){ /* wlimit+a> */

if(!a_1025(2106125358)){ goto a_G3;}
a_A[0]=2106125358; return 1;
a_G3:if(!a_1025(2106125294)){ goto a_G5;}
a_A[0]=2106125294; return 1;
a_G5:if(!a_1025(2106125366)){ goto a_G7;}
a_A[0]=2106125366; return 1;
a_G7:if(!a_1025(2106125362)){ return 0;}
a_A[0]=2106125362; return 1;
} /* wlimit */
static void a_1516(int a_F1,int a_F2,int a_A[1]){ /* finalssel+>a+>a+a> */
int a_P[1];
if(!__is(a_F2)){ goto a_G3;}
a_A[0]=to_LIST(a_1022)->offset[a_F2-4];return;
a_G3:if(!__was(a_1022,a_F1)){ goto a_G5;}
a_A[0]=to_LIST(a_1022)->offset[a_F1-4];return;
a_G5:a_1057(a_F1,a_P);a_A[0]=a_P[0];return;
} /* finalssel */
static void a_1569(int a_F1){ /* whandleaffix+>a */
int a_P[1];
if(!a_1535(a_F1)){ goto a_G3;}
a_1543(1048593,0);
a_G3:if(!a_1541(a_F1)){return;}
a_P[0]=2106125302;a_1542(1,a_P);return;
} /* whandleaffix */
static void a_1564(int a_F1,int a_F2){ /* wbeforevarargblock+>a+>a */
int a_L3;int a_P[1];
a_G1:__next(a_1022,a_F1);
a_1058(a_F2,a_P);a_L3=a_P[0];
a_1050(a_F2,a_P);a_F2=a_P[0];
{ if(!(a_L3==16777612||a_L3==16777623)){ goto a_G6;}
}
a_1543(1048593,0);
a_G6:if(__equal(a_F2,0)){return;} goto a_G1;
} /* wbeforevarargblock */
static void a_1563(int a_F1){ /* wbeforeshiftrule+>a */

a_G1:__next(a_1022,a_F1);
{register int a_r1=to_LIST(a_1022)->offset[a_F1-2];
 if(a_r1==16777654){return;}
 if(!(a_r1==16777612||a_r1==16777623)){ goto a_G1;}
}
a_1543(1048593,0); goto a_G1;
} /* wbeforeshiftrule */
static void a_1559(int a_F1,int a_F2){ /* waftervarargblock+>a+>a */
int a_L3;int a_P[1];
a_G1:__next(a_1022,a_F1);
a_1058(a_F2,a_P);a_L3=a_P[0];
a_1050(a_F2,a_P);a_F2=a_P[0];
{ if(!(a_L3==16777617||a_L3==16777623)){ goto a_G6;}
}
a_1543(1048594,0);
a_G6:if(__equal(a_F2,0)){return;} goto a_G1;
} /* waftervarargblock */
static void a_1558(int a_F1){ /* waftershiftrule+>a */

a_G1:__next(a_1022,a_F1);
{register int a_r1=to_LIST(a_1022)->offset[a_F1-2];
 if(a_r1==16777654){return;}
 if(!(a_r1==16777617||a_r1==16777623)){ goto a_G1;}
}
a_1543(1048594,0); goto a_G1;
} /* waftershiftrule */
static void a_1576(int a_F1,int a_A[1]){ /* wsimpleaffix+>a+a> */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[7];
a_A[0]=0;
if(!a_1029(a_P)){ goto a_G4;}a_L6=a_P[0];
a_G3:a_P[0]=2106125245;a_P[1]=a_L6;a_1542(2,a_P);return;
a_G4:if(!a_1025(2106125229)){ goto a_G10;}
a_1074(a_P);a_L3=a_P[0];
if(!a_1060(a_L3)){ goto a_G8;}
a_P[0]=2106125229;a_P[1]=a_L3;a_1542(2,a_P);return;
a_G8:a_1197(a_L3,a_P);a_L6=a_P[0]; goto a_G3;
a_G10:if(!a_1571(a_P)){ goto a_G13;}a_L6=a_P[0];
a_1074(a_P);a_L3=a_P[0];
a_P[0]=a_L6;a_P[1]=a_L3;a_1542(2,a_P);return;
a_G13:if(!a_1025(2106125305)){ goto a_G15;}
a_P[0]=2106125305;a_1542(1,a_P);return;
a_G15:if(!a_1025(2106125346)){ goto a_G25;}
a_1074(a_P);a_L3=a_P[0];
a_P[0]=2106125346;a_P[1]=a_L3;a_1542(2,a_P);
a_1555(a_F1,a_P);a_L4=a_P[0];
a_1576(a_L4,a_P);
a_1071(2106125224);
if(a_1029(a_P)){a_L6=a_P[0]; goto a_G24;}
a_1074(a_P);a_L6=a_P[0];
a_1056(a_L6,a_P);a_L6=a_P[0];
a_G24:a_P[0]=2106125224;a_P[1]=2106125245;a_P[2]=a_L6;a_1542(3,a_P);return;
a_G25:a_1073(a_P);a_L3=a_P[0];a_L5=a_P[1];
a_1058(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777629){ goto a_G28;}
 if(a_L4==16777548||a_L4==16777544||a_L4==16777554||a_L4==16777596||a_L4==16777602){ goto a_G30;}
 if(a_L4==16777612||a_L4==16777617||a_L4==16777623||a_L4==16777650){  goto a_G32;}
  goto a_G33;}
a_G28:a_P[0]=2106125343;a_1542(1,a_P);
a_A[0]=a_L3;return;
a_G30:a_1516(a_L3,a_L5,a_P);a_L6=a_P[0];
a_P[0]=2106125346;a_P[1]=a_L3;a_P[2]=2106125358;a_P[3]=a_L3;a_P[4]=2106125224;a_P[5]=2106125245;a_P[6]=a_L6;a_1542(7,a_P);return;
a_G32:a_1569(a_F1);
a_G33:a_P[0]=a_L3;a_1542(1,a_P);return;
} /* wsimpleaffix */
static void a_1572(int a_F1,int a_A[1]){ /* wmatchformalactual+>a+a> */
int a_L3;int a_L4;int a_P[1];
{ if(a_F1==16777607||a_F1==16777602||a_F1==16777596){ goto a_G2;}
 if(a_F1==16777635){ goto a_G9;}
 if(a_F1==16777612){ goto a_G11;}
 if(a_F1==16777617){ goto a_G12;}
 if(a_F1==16777623){  goto a_G13;}
  goto a_G14;}
a_G2:a_1074(a_P);a_L3=a_P[0];
a_1058(a_L3,a_P);a_L4=a_P[0];
if(!__equal(a_L4,16777629)){ goto a_G7;}
a_1514(2106125343);
a_A[0]=a_L3;return;
a_G7:a_1514(a_L3);
a_A[0]=0;return;
a_G9:a_1074(a_P);a_A[0]=a_P[0];
a_1514(a_A[0]);return;
a_G11:a_1576(2311425,a_P);a_A[0]=a_P[0];return;
a_G12:a_1576(2311426,a_P);a_A[0]=a_P[0];return;
a_G13:a_1576(2311427,a_P);a_A[0]=a_P[0];return;
a_G14:a_1063(a_1001,16777406,753);return;
} /* wmatchformalactual */
static void a_1567(int a_A[1]){ /* wcopyaffixfromBUFFER+>a> */

a_G1:if(__more(a_A[0],to_LIST(a_1006)->aupb)){return;}
if(__equal(to_LIST(a_1006)->offset[a_A[0]],2106125321)){return;}
if(!__equal(to_LIST(a_1006)->offset[a_A[0]],2106125302)){ goto a_G6;}
__incr(a_A[0]);
a_1543(1048593,0); goto a_G1;
a_G6:if(!__equal(to_LIST(a_1006)->offset[a_A[0]],2106125245)){ goto a_G10;}
__incr(a_A[0]);
a_1275(to_LIST(a_1006)->offset[a_A[0]]);
a_G9:__incr(a_A[0]); goto a_G1;
a_G10:if(!__was(a_1022,to_LIST(a_1006)->offset[a_A[0]])){ goto a_G13;}
a_G11:a_1278(to_LIST(a_1006)->offset[a_A[0]]); goto a_G9;
a_G13:if(__was(a_1020,to_LIST(a_1006)->offset[a_A[0]])){ goto a_G11;}
a_1274(to_LIST(a_1006)->offset[a_A[0]]); goto a_G9;
} /* wcopyaffixfromBUFFER */
static void a_1507(int a_F1,int a_A[1]){ /* copyspareaffix+>a+>a> */
int a_P[1];
if(!__equal(a_F1,16777617)){ goto a_G9;}
a_1274(2106125305);
a_G3:if(__more(a_A[0],to_LIST(a_1006)->aupb)){return;}
if(__equal(to_LIST(a_1006)->offset[a_A[0]],2106125321)){return;}
if(!__equal(to_LIST(a_1006)->offset[a_A[0]],2106125245)){ goto a_G7;}
__incr(a_A[0]);
a_G7:__incr(a_A[0]); goto a_G3;
a_G9:a_1274(2106125235);
a_P[0]=a_A[0];a_1567(a_P);a_A[0]=a_P[0];return;
} /* copyspareaffix */
static void a_1557(int a_F1,int a_F2,int a_F3,int a_F4){ /* wafteraffixes+>a+>a+>a+>a */
int a_L5;int a_L6;int a_L7;int a_P[1];
__incr(a_F2);
a_1050(a_F1,a_P);a_L5=a_P[0];
a_L7=0;
a_G4:if(__more(a_F2,to_LIST(a_1006)->aupb)){return;}
a_1058(a_L5,a_P);a_L6=a_P[0];
if(!__equal(a_L6,16777629)){ goto a_G13;}
a_1274(2106125343);
if(__equal(a_F4,0)){ goto a_G10;}
__subtr(1,a_F3,a_F3);
a_G10:a_1275(a_F3);
a_1050(a_L5,a_P);a_L5=a_P[0];
a_L7=a_L5; goto a_G4;
a_G13:__incr(a_F2);
if(!__equal(to_LIST(a_1006)->offset[a_F2],2106125343)){ goto a_G17;}
a_1274(2106125343);
__incr(a_F2); goto a_G26;
a_G17:if(__equal(a_L6,16777617)){ goto a_G19;}
if(!__equal(a_L6,16777623)){ goto a_G24;}
a_G19:if(!__equal(to_LIST(a_1006)->offset[a_F2],2106125302)){ goto a_G24;}
__incr(a_F2);
a_1543(1048593,0);
if(!__equal(to_LIST(a_1007)->offset[a_1493-1],1048595)){ goto a_G24;}
a_P[0]=a_F2;a_1507(a_L6,a_P);a_F2=a_P[0]; goto a_G26;
a_G24:a_P[0]=a_F2;a_1567(a_P);a_F2=a_P[0];
a_G26:a_1050(a_L5,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G4;}
a_L5=a_L7; goto a_G4;
} /* wafteraffixes */
static void a_1556(int a_F1){ /* wactualrule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[1];
a_1543(1048580,0);
a_1274(2106125309);
a_1274(to_LIST(a_1007)->offset[a_1493]);
a_1278(a_F1);
a_L2=to_LIST(a_1006)->aupb;
a_1482=0;a_1483=0;a_1484=0;
a_L5=0;a_L7=0;a_L6=0;
a_1050(a_F1,a_P);a_L3=a_P[0];
a_G9:if(!a_1025(2106125321)){ goto a_G26;}
a_1514(2106125321);
a_1058(a_L3,a_P);a_L4=a_P[0];
if(!__equal(a_L4,16777629)){ goto a_G16;}
a_1050(a_L3,a_P);a_L3=a_P[0];
a_L5=a_L3;
a_1058(a_L3,a_P);a_L4=a_P[0];
a_G16:if(!__is(a_L5)){ goto a_G18;}
__incr(a_1484); goto a_G21;
a_G18:__incr(a_1482);
{ if(!(a_L4==16777617||a_L4==16777623)){ goto a_G21;}
}
__incr(a_1483);
a_G21:a_1572(a_L4,a_P);a_L7=a_P[0];
a_1050(a_L3,a_P);a_L3=a_P[0];
if(!__equal(a_L3,0)){ goto a_G9;}
__incr(a_L6);
a_L3=a_L5; goto a_G9;
a_G26:if(!__equal(a_L7,0)){ goto a_G30;}
__add(a_1484,a_1482,a_1482);
__add(a_1484,a_1483,a_1483);
a_1484=0; goto a_G32;
a_G30:if(!__more(a_1484,0)){ goto a_G32;}
__decr(a_1484);
a_G32:a_1275(a_1482);
a_1275(a_1483);
a_1275(a_1484);
if(__equal(a_L7,0)){ goto a_G40;}
if(!__equal(a_F1,483807568)){ goto a_G38;}
a_1563(a_L7); goto a_G40;
a_G38:if(a_1205(a_F1,131072)){ goto a_G40;}
a_1564(a_L7,a_L5);
a_G40:if(!a_1205(a_F1,512)){ goto a_G43;}
a_1543(1048582,0);
a_L8=a_1493; goto a_G44;
a_G43:a_L8=0;
a_G44:a_1557(a_F1,a_L2,a_L6,a_L7);
if(__equal(a_L7,0)){ goto a_G50;}
if(!__equal(a_F1,483807568)){ goto a_G48;}
a_1558(a_L7); goto a_G50;
a_G48:if(a_1205(a_F1,131072)){ goto a_G50;}
a_1559(a_L7,a_L5);
a_G50:a_1543(1048581,0);
a_1570(a_L8);
a_1570(a_1493);
a_1274(2106125238);
__unstackto(a_1006,a_L2);return;
} /* wactualrule */
static void a_1562(int a_F1){ /* warea+>a */
int a_P[1];
a_1274(2106125217);
__incr(a_F1);
a_P[0]=a_F1;a_1567(a_P);return;
} /* warea */
static void a_1574(void){ /* wreadbox */
int a_L1;int a_L2;int a_L3;int a_P[1];
a_1543(1048580,0);
a_1274(2106125221);
a_1274(to_LIST(a_1007)->offset[a_1493]);
{register int a_r1=to_LIST(a_1006)->aupb;a_L2=a_r1;a_L1=a_r1;}
a_1576(2311425,a_P);
__incr(a_L1);
a_P[0]=a_L1;a_1567(a_P);
__unstackto(a_1006,a_L2);
a_1543(1048581,0);
a_L1=to_LIST(a_1007)->offset[a_1493];
a_1543(1048587,0);
a_1071(2106125221);
a_G13:if(__equal(a_L1,0)){ goto a_G21;}
a_L2=to_LIST(a_1007)->offset[a_L1];
__next(a_1007,a_L1);
a_L3=to_LIST(a_1007)->offset[a_L1];
__next(a_1007,a_L1);
a_1562(a_L2);
a_1570(a_L1);
a_L1=a_L3; goto a_G13;
a_G21:a_1274(2106125238);return;
} /* wreadbox */
static void a_1565(void){ /* wclassification */

a_G1:a_1071(2106125217);
a_1034(2106125217);
a_1543(1048580,0);
a_1543(1048582,0);
a_1543(1048581,0);
a_1543(1048579,0);
a_1561();
if(!a_1025(2106125340)){return;}
a_1543(1048591,0); goto a_G1;
} /* wclassification */
static void a_1566(void){ /* wcompound */
int a_L1;
a_L1=to_LIST(a_1022)->aupb;
a_1575();
__unstackto(a_1022,a_L1);return;
} /* wcompound */
static void a_1560(void){ /* waltsequence */

a_G1:a_1573();
a_1543(1048579,0);
a_1561();
if(!a_1025(2106125340)){return;}
a_1543(1048591,0); goto a_G1;
} /* waltsequence */
static void a_1561(void){ /* walttail */

a_G1:if(!a_1025(2106125238)){return;}
a_1573(); goto a_G1;
} /* walttail */
static void a_1573(void){ /* wmember */
int a_L1;int a_P[1];
if(!a_1025(2106125312)){ goto a_G4;}
a_1566();
a_1071(2106125232);return;
a_G4:if(!a_1025(2106125263)){ goto a_G6;}
a_1568();return;
a_G6:if(!a_1025(2106125275)){ goto a_G9;}
a_1074(a_P);
a_1543(1048586,0);return;
a_G9:if(!a_1025(2106125321)){ goto a_G11;}
a_1543(1048584,0);return;
a_G11:if(!a_1025(2106125302)){ goto a_G13;}
a_1543(1048585,0);return;
a_G13:a_1074(a_P);a_L1=a_P[0];
if(!a_1205(a_L1,128)){ goto a_G16;}
a_1513(a_L1);return;
a_G16:a_1556(a_L1);return;
} /* wmember */
static void a_1575(void){ /* wrulebody */
int a_L1;int a_L2;int a_P[1];
a_1551(a_P);a_L1=a_P[0];
a_1552();
a_1553(a_L1,a_P);a_L2=a_P[0];
if(!a_1025(2106125221)){ goto a_G7;}
a_1574();
a_1565(); goto a_G8;
a_G7:a_1560();
a_G8:a_1503(a_L2);return;
} /* wrulebody */
static void a_1523(int a_F1){ /* generaterule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
a_1511(a_F1);
a_1056(a_F1,a_P);a_L5=a_P[0];
if(!__equal(a_L5,0)){ goto a_G5;}
a_1034(2106125324);return;
a_G5:a_1546=a_F1;
a_1086(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1512=1;
a_1500=3;
__scratch(a_1007);
__scratch(a_1006);
{register int a_r1=to_LIST(a_1007)->aupb;a_L4=a_r1;a_1493=a_r1;}
a_1539=0;a_1536=0;
a_1550(a_F1);
a_1532();
a_1071(2106125324);
a_1554(a_F1);
a_1489();
a_1501();
a_1084(a_L2,a_L3);
a_1274(2106125337);
a_1278(a_F1);
a_1275(a_1539);
a_1275(a_1536);
a_1275(a_1540);
a_1500=2;
a_1512=1;
a_1493=a_L4;
a_1550(a_F1);
a_1575();
a_1071(2106125324);
a_1274(2106125324);return;
} /* generaterule */
static void a_1476(void){ /* @root */

} /* @root */
static void a_1514(int a_F1){ /* extendBUFFER+>a */

 a_extension(a_1006,1);to_LIST(a_1006)->top[1]=a_F1;to_LIST(a_1006)->aupb+=1;
 return;
} /* extendBUFFER */
static void a_1515(int a_F1,int a_F2){ /* extendRULE+>a+>a */

 a_extension(a_1007,2);to_LIST(a_1007)->top[1]=a_F1;to_LIST(a_1007)->top[2]=a_F2;to_LIST(a_1007)->aupb+=2;
 return;
} /* extendRULE */
static void a_1464(void){ /* wasrootscanned */
int a_P[1];
if(__is(a_1588)){return;}
a_P[0]=2093833934;a_1040(0,1,a_P);return;
} /* wasrootscanned */
static void a_1357(void){ /* passI */
int a_L1;int a_P[2];
a_G1:if(__equal(1454738855,a_1062)){return;}
if(!__equal(1454738926,a_1062)){ goto a_G8;}
a_1077();
a_1585(a_P);a_L1=a_P[0];
if(__equal(a_L1,2)){return;}
if(!__equal(a_L1,1)){ goto a_G1;}
a_G7:a_1269(); goto a_G1;
a_G8:if(!a_1321(3429901)){ goto a_G11;}
a_1590();
a_1421(1454738974); goto a_G1;
a_G11:if(a_1580(0)){ goto a_G1;}
if(!__equal(1454738893,a_1062)){ goto a_G15;}
a_1077();
a_1591(); goto a_G1;
a_G15:if(!__equal(1454738883,a_1062)){ goto a_G18;}
a_1077();
a_1586(); goto a_G1;
a_G18:if(!__equal(1454738986,a_1062)){ goto a_G21;}
a_1077();
a_1593(); goto a_G1;
a_G21:if(!__equal(1454738888,a_1062)){ goto a_G24;}
a_1077();
a_1581(); goto a_G1;
a_G24:if(!__equal(1454738851,a_1062)){ goto a_G27;}
a_1077(); goto a_G7;
a_G27:a_P[0]=2093833908;a_P[1]=a_1062;a_1040(-1,2,a_P);
a_1269(); goto a_G1;
} /* passI */
static void a_1593(void){ /* tagenquiry */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[4];
if(!a_1321(3429893)){ goto a_G15;}
if(!a_1584(a_P)){ goto a_G15;}a_L1=a_P[0];
a_1582(a_L1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,0)){ goto a_G7;}
a_G5:a_1590();
a_1421(1454738974);return;
a_G7:if(!__equal(a_L2,2)){return;}
a_1583(a_L1,a_P);a_L1=a_P[0];
a_1198(a_L1,a_P);a_L2=a_P[0];
a_1314(a_P);a_L3=a_P[0];
a_1058(a_L1,a_P);a_L4=a_P[0];
a_P[0]=2093833945;a_P[1]=a_L4;a_P[2]=a_L1;a_P[3]=a_L3;a_1041(8,a_L2,4,a_P); goto a_G5;
a_G15:a_P[0]=2093833908;a_P[1]=1454738986;a_1040(-1,2,a_P);
a_1269();return;
} /* tagenquiry */
static int a_1580(int a_F1){ /* declaration+>a */

if(!__equal(1454738917,a_1062)){ goto a_G4;}
a_1077();
a_1454(a_F1); return 1;
a_G4:if(!__equal(1454738921,a_1062)){ goto a_G7;}
a_1077();
a_1452(a_F1); return 1;
a_G7:if(!__equal(1454738913,a_1062)){ goto a_G10;}
a_1077();
a_1594(a_F1); return 1;
a_G10:if(!__equal(1454738908,a_1062)){ goto a_G13;}
a_1077();
a_1579(a_F1); return 1;
a_G13:if(!__equal(1454738898,a_1062)){ goto a_G16;}
a_1077();
a_1250(a_F1); return 1;
a_G16:if(!__equal(1454738903,a_1062)){ goto a_G19;}
a_1077();
a_1251(a_F1); return 1;
a_G19:if(!__equal(1454738860,a_1062)){ goto a_G22;}
a_1077();
a_1589(256,a_F1); return 1;
a_G22:if(!__equal(1454738865,a_1062)){ goto a_G25;}
a_1077();
a_1589(0,a_F1); return 1;
a_G25:if(!__equal(1454738875,a_1062)){ goto a_G28;}
a_1077();
a_1589(512,a_F1); return 1;
a_G28:if(!__equal(1454738870,a_1062)){ goto a_G31;}
a_1077();
a_1589(768,a_F1); return 1;
a_G31:if(!__equal(1454738879,a_1062)){ return 0;}
a_1077();
a_1589(1024,a_F1); return 1;
} /* declaration */
static void a_1581(void){ /* externaldeclaration */
int a_P[2];
if(!a_1321(3429893)){ goto a_G8;}
if(a_1580(1)){return;}
if(!__equal(1454738851,a_1062)){ goto a_G6;}
a_1077();
a_G5:a_1269();return;
a_G6:a_P[0]=2093833908;a_P[1]=a_1062;a_1040(-1,2,a_P); goto a_G5;
a_G8:a_P[0]=2093833921;a_1040(-1,1,a_P);
a_1269();return;
} /* externaldeclaration */
static void a_1591(void){ /* staticdeclaration */
int a_P[2];
if(!__equal(1454738913,a_1062)){ goto a_G4;}
a_1077();
a_1592();return;
a_G4:if(!__equal(1454738921,a_1062)){ goto a_G7;}
a_1077();
a_1453();return;
a_G7:if(!__equal(1454738851,a_1062)){ goto a_G10;}
a_1077();
a_1269();return;
a_G10:a_P[0]=2093833908;a_P[1]=a_1062;a_1040(-1,2,a_P);
a_1269();return;
} /* staticdeclaration */
static void a_1586(void){ /* root */
int a_P[1];
if(!__is(a_1588)){ goto a_G4;}
a_P[0]=2093833929;a_1040(-1,1,a_P);
a_1269();return;
a_G4:a_1588=1;
a_1587();return;
} /* root */
static void a_1578(void){ /* @root */

} /* @root */
static void a_1459(void){ /* passII */
int a_L1;int a_P[1];
a_G1:if(!a_1025(2106125337)){ goto a_G5;}
a_1074(a_P);a_L1=a_P[0];
a_1599(a_L1);
a_G4:a_1185(a_L1); goto a_G1;
a_G5:if(!a_1025(2106125333)){ goto a_G8;}
a_1074(a_P);a_L1=a_P[0]; goto a_G4;
a_G8:if(!a_1025(2106125329)){ goto a_G10;}
a_1598(); goto a_G1;
a_G10:if(!a_1025(2106125258)){ goto a_G12;}
a_1301(); goto a_G1;
a_G12:if(!a_1025(2106125267)){ goto a_G14;}
a_1302(); goto a_G1;
a_G14:if(!a_1025(2106125271)){ goto a_G16;}
a_1304(); goto a_G1;
a_G16:if(!a_1025(2106125286)){ goto a_G18;}
a_1305(); goto a_G1;
a_G18:if(a_1025(2106125252)){return;}
a_1063(a_1001,16777463,50);return;
} /* passII */
static void a_1460(void){ /* passIII */
int a_L1;int a_P[1];
a_G1:if(!a_1025(2106125337)){ goto a_G4;}
a_G2:a_1074(a_P);a_L1=a_P[0];
a_1523(a_L1); goto a_G1;
a_G4:if(a_1025(2106125333)){ goto a_G2;}
if(!a_1025(2106125329)){ goto a_G11;}
a_1072(a_P);
if(a_1029(a_P)){ goto a_G1;}
a_1074(a_P); goto a_G1;
a_G11:if(!a_1025(2106125258)){ goto a_G13;}
a_G12:a_1034(2106125324); goto a_G1;
a_G13:if(a_1025(2106125267)){ goto a_G12;}
if(a_1025(2106125271)){ goto a_G12;}
if(a_1025(2106125286)){ goto a_G12;}
if(a_1025(2106125252)){return;}
a_1063(a_1001,16777459,61);return;
} /* passIII */
static void a_1599(int a_F1){ /* dstoremacro+>a */
int a_L2;int a_L3;int a_P[2];
if(a_1147()){return;}
if(!a_1205(a_F1,128)){return;}
a_1086(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1600(a_F1,a_L2,a_L3);return;
} /* dstoremacro */
static void a_1597(int a_F1){ /* checktagforpublic+>a */
int a_L2;int a_L3;int a_P[4];
if(!a_1205(a_F1,2)){ goto a_G8;}
a_1198(a_F1,a_P);a_L3=a_P[0];
a_1058(a_F1,a_P);a_L2=a_P[0];
if(!a_1205(a_F1,16)){ goto a_G6;}
a_G5:a_P[0]=2093833961;a_P[1]=a_L2;a_P[2]=a_F1;a_P[3]=a_L3;a_1040(-1,4,a_P);return;
a_G6:if(!a_1205(a_F1,8)){return;} goto a_G5;
a_G8:if(!a_1205(a_F1,4)){return;}
a_P[0]=2093833951;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* checktagforpublic */
static void a_1596(int a_F1){ /* checktagformacro+>a */
int a_L2;int a_L3;int a_P[4];
if(!a_1205(a_F1,2)){ goto a_G13;}
a_1198(a_F1,a_P);a_L3=a_P[0];
a_1058(a_F1,a_P);a_L2=a_P[0];
if(!__noteq(a_L2,16777580)){ goto a_G7;}
a_1294(a_F1,128);
a_P[0]=2093833971;a_P[1]=a_L2;a_P[2]=a_F1;a_P[3]=a_L3;a_1041(3,-1,4,a_P);return;
a_G7:if(!a_1205(a_F1,16)){ goto a_G10;}
a_1294(a_F1,128);
a_P[0]=2093833971;a_P[1]=2093833977;a_P[2]=a_F1;a_P[3]=a_L3;a_1041(3,-1,4,a_P);return;
a_G10:if(!a_1205(a_F1,8)){return;}
a_1294(a_F1,128);
a_P[0]=2093833971;a_P[1]=2093833983;a_P[2]=a_F1;a_P[3]=a_L3;a_1041(3,-1,4,a_P);return;
a_G13:a_P[0]=2093833992;a_P[1]=a_F1;a_1041(3,-1,2,a_P);return;
} /* checktagformacro */
static void a_1598(void){ /* dreadpragmat */
int a_L1;int a_L2;int a_P[1];
a_1072(a_P);a_L1=a_P[0];
if(!__equal(a_L1,3429889)){ goto a_G5;}
a_1072(a_P);a_L2=a_P[0];
a_1363(a_L1,a_L2);return;
a_G5:if(!__equal(a_L1,3429904)){ goto a_G8;}
a_1074(a_P);a_L2=a_P[0];
a_1596(a_L2);return;
a_G8:if(!__equal(a_L1,3429905)){ goto a_G11;}
a_1074(a_P);a_L2=a_P[0];
a_1597(a_L2);return;
a_G11:a_1063(a_1001,16777455,98);return;
} /* dreadpragmat */
static void a_1595(void){ /* @root */

} /* @root */
static void a_1114(int a_F1,int a_A[1]){ /* getpragmatvalue+>a+a> */

{ if(a_F1==3429888){ goto a_G2;}
 if(a_F1==3429892){ goto a_G3;}
 if(a_F1==3429893){ goto a_G4;}
 if(a_F1==3429894){ goto a_G5;}
 if(a_F1==3429903){ goto a_G6;}
 if(a_F1==3429895){ goto a_G7;}
 if(a_F1==3429889){ goto a_G8;}
 if(a_F1==3429899){ goto a_G9;}
 if(a_F1==3429890){ goto a_G10;}
 if(a_F1==3429891){ goto a_G11;}
 if(a_F1==3429906){ goto a_G12;}
 if(a_F1==3429907){ goto a_G13;}
 if(a_F1==3429900){  goto a_G14;}
  goto a_G15;}
a_G2:a_A[0]=a_1641;return;
a_G3:a_A[0]=a_1613;return;
a_G4:a_A[0]=a_1617;return;
a_G5:a_A[0]=a_1616;return;
a_G6:a_A[0]=a_1618;return;
a_G7:a_A[0]=a_1608;return;
a_G8:a_A[0]=a_1645;return;
a_G9:a_A[0]=a_1644;return;
a_G10:a_A[0]=a_1633;return;
a_G11:a_A[0]=a_1632;return;
a_G12:a_A[0]=a_1615;return;
a_G13:a_A[0]=a_1614;return;
a_G14:a_A[0]=a_1635;return;
a_G15:a_1063(a_1001,16777475,124);return;
} /* getpragmatvalue */
static int a_1321(int a_F1){ /* ispragmatvalue+>a */

{ if(a_F1==3429893){ goto a_G2;}
 if(a_F1==3429894){ goto a_G3;}
 if(a_F1==3429903){ goto a_G4;}
 if(a_F1==3429892){ goto a_G5;}
 if(a_F1==3429901){ goto a_G6;}
 if(a_F1==3429895){ goto a_G7;}
 if(a_F1==3429897){ goto a_G8;}
 if(a_F1==3429898){ goto a_G9;}
 if(a_F1==3429896){  goto a_G10;}
  return 0;}
a_G2:if(!__equal(a_1617,1)){ return 0;} return 1;
a_G3:if(!__equal(a_1616,1)){ return 0;} return 1;
a_G4:if(!__equal(a_1618,1)){ return 0;} return 1;
a_G5:if(!__equal(a_1613,1)){ return 0;} return 1;
a_G6:if(!__is(a_1625)){ return 0;} return 1;
a_G7:if(!__is(a_1608)){ return 0;} return 1;
a_G8:if(!__is(a_1643)){ return 0;} return 1;
a_G9:if(!__is(a_1607)){ return 0;} return 1;
a_G10:if(!__is(a_1604)){ return 0;} return 1;
} /* ispragmatvalue */
static void a_1363(int a_F1,int a_F2){ /* setpragmatvalue+>a+>a */

{ if(a_F1==3429888){ goto a_G2;}
 if(a_F1==3429892){ goto a_G3;}
 if(a_F1==3429893){ goto a_G4;}
 if(a_F1==3429894){ goto a_G7;}
 if(a_F1==3429903){ goto a_G8;}
 if(a_F1==3429895){ goto a_G12;}
 if(a_F1==3429889){ goto a_G13;}
 if(a_F1==3429899){ goto a_G17;}
 if(a_F1==3429890){ goto a_G18;}
 if(a_F1==3429891){ goto a_G19;}
 if(a_F1==3429906){ goto a_G20;}
 if(a_F1==3429907){  goto a_G21;}
  goto a_G22;}
a_G2:a_1641=a_F2;return;
a_G3:a_1613=a_F2;return;
a_G4:if(!__is(a_F2)){ goto a_G6;}
a_1639();return;
a_G6:a_1605();return;
a_G7:a_1616=a_F2;return;
a_G8:if(!__is(a_F2)){ goto a_G11;}
a_1618=1;
a_1633=2;return;
a_G11:a_1618=0;return;
a_G12:a_1608=a_F2;return;
a_G13:if(__equal(a_F2,a_1645)){return;}
if(__less(a_F2,0)){return;}
if(__more(a_F2,9)){return;}
a_1645=a_F2;return;
a_G17:a_1644=a_F2;return;
a_G18:a_1633=a_F2;return;
a_G19:a_1632=a_F2;return;
a_G20:a_1615=a_F2;return;
a_G21:a_1614=a_F2;return;
a_G22:a_1063(a_1001,16777469,155);return;
} /* setpragmatvalue */
static void a_1638(void){ /* setliblevel */

a_1637=a_1645;
a_1636=a_1633;
a_1633=0;
if(!__less(a_1645,3)){ goto a_G6;}
a_1645=5;return;
a_G6:a_1645=5;return;
} /* setliblevel */
static void a_1634(void){ /* restoreliblevel */

a_1645=a_1637;
a_1633=a_1636;return;
} /* restoreliblevel */
static void a_1639(void){ /* setlibrary */

if(__is(a_1617)){return;}
a_1617=1;
a_1638();
a_1609(3429889,a_1645);return;
} /* setlibrary */
static void a_1605(void){ /* clearlibrary */

if(!__is(a_1617)){return;}
a_1634();
a_1617=0;
a_1609(3429889,a_1645);return;
} /* clearlibrary */
static void a_1361(void){ /* resetpragmats */

a_1605();
a_1608=0;
a_1641=8;
a_1613=0;
a_1633=0;
a_1616=1;
a_1643=0;a_1607=0;a_1604=0;
a_1625=0;a_1624=0;return;
} /* resetpragmats */
static void a_1347(void){ /* cmdlinepragmat */
int a_L1;int a_P[1];
a_G1:if(!a_1584(a_P)){ goto a_G10;}a_L1=a_P[0];
a_1263(1454738932);
a_1628(a_L1);
if(!__equal(1454738974,a_1062)){ goto a_G6;}
a_1077();return;
a_G6:if(!__equal(1454738968,a_1062)){ goto a_G8;}
a_1077(); goto a_G1;
a_G8:a_1263(1454738974);
a_1269();return;
a_G10:a_P[0]=2093834000;a_1040(-1,1,a_P);
a_1269();return;
} /* cmdlinepragmat */
static void a_1628(int a_F1){ /* pragmatitem+>a */
int a_L2;int a_P[2];
if(!__equal(1454738959,a_1062)){ goto a_G7;}
a_G2:a_1077();
a_1628(a_F1);
if(__equal(1454738968,a_1062)){ goto a_G2;}
a_1263(1454738962);return;
a_G7:if(!a_1584(a_P)){ goto a_G9;}a_L2=a_P[0];
a_1642(a_F1,a_L2,0);return;
a_G9:if(!a_1432(a_P)){ goto a_G11;}a_L2=a_P[0];
a_1606(a_F1,a_L2);return;
a_G11:if(!a_1260(a_P)){ goto a_G13;}a_L2=a_P[0];
a_1640(a_F1,a_L2);return;
a_G13:a_P[0]=2093834007;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_1268();return;
} /* pragmatitem */
static void a_1620(int a_F1,int a_F2){ /* markrawtagasmacro+>a+>a */
int a_L3;int a_L4;int a_P[2];
if(__lseq(a_F2,0)){ goto a_G3;}
a_1602(a_F1,a_F2);
a_G3:a_1583(a_F1,a_P);a_L3=a_P[0];
a_1058(a_L3,a_P);a_L4=a_P[0];
if(!a_1205(a_L3,56)){ goto a_G7;}
a_P[0]=2093834068;a_P[1]=a_L3;a_1041(2,-1,2,a_P);return;
a_G7:if(__equal(a_L4,16777520)){ goto a_G9;}
if(!__equal(a_L4,16777580)){ goto a_G13;}
a_G9:a_1449(a_L3,128);
a_1012(2106125329);
a_1015(3429904);
a_1017(a_L3);return;
a_G13:a_P[0]=2093834068;a_P[1]=a_L3;a_1041(3,-1,2,a_P);return;
} /* markrawtagasmacro */
static void a_1621(int a_F1,int a_F2){ /* markrawtagaspublic+>a+>a */
int a_L3;int a_L4;int a_P[1];
if(__lseq(a_F2,0)){ goto a_G3;}
a_1602(a_F1,a_F2);
a_G3:a_1583(a_F1,a_P);a_L3=a_P[0];
a_L4=0;
a_P[0]=a_L4;a_1249(a_L3,0,a_P);
a_1012(2106125329);
a_1015(3429905);
a_1017(a_L3);return;
} /* markrawtagaspublic */
static int a_1603(int a_A[1]){ /* aheadrawtag+a> */

if(!__was(a_1039,a_1062)){ return 0;}
a_A[0]=a_1062; return 1;
} /* aheadrawtag */
static void a_1619(int a_F1){ /* insertsymbol+>a */

a_1062=a_F1;return;
} /* insertsymbol */
static void a_1622(void){ /* nextpragmatsymbol */
int a_P[1];
a_G1:{ if(a_1626==0){ goto a_G2;}
 if(a_1626==1){ goto a_G6;}
 if(a_1626==2){ goto a_G10;}
 if(a_1626==3){ goto a_G14;}
 if(a_1626==4){ goto a_G20;}
 if(a_1626==5){ goto a_G24;}
 if(a_1626==6){ goto a_G30;}
 if(a_1626==7){  goto a_G32;}
  goto a_G34;}
a_G2:a_1077();
if(!__equal(1454738968,a_1062)){ goto a_G5;}
a_1626=1;return;
a_G5:a_1626=100;return;
a_G6:a_1077();
if(!a_1603(a_P)){ goto a_G5;}a_1627=a_P[0];
a_1626=2;return;
a_G10:a_1077();
if(!__equal(1454738932,a_1062)){ goto a_G5;}
a_1626=3;return;
a_G14:a_1077();
{ if(!((1454739015<=a_1062 && a_1062<=1516190314)||(1516190316<=a_1062 && a_1062<=1712834475)||(963127691<=a_1062 && a_1062<=1454738090))){ goto a_G17;}
}
a_1626=0;return;
a_G17:if(!__equal(1454738959,a_1062)){ goto a_G5;}
a_1626=4; goto a_G1;
a_G20:a_1077();
{ if(!((1454739015<=a_1062 && a_1062<=1516190314)||(1516190316<=a_1062 && a_1062<=1712834475)||(963127691<=a_1062 && a_1062<=1454738090))){ goto a_G5;}
}
a_1626=5;return;
a_G24:a_1077();
if(!__equal(1454738968,a_1062)){ goto a_G27;}
a_1626=6;return;
a_G27:if(!__equal(1454738962,a_1062)){ goto a_G5;}
a_1626=0; goto a_G1;
a_G30:a_1619(a_1627);
a_1626=7;return;
a_G32:a_1619(1454738932);
a_1626=4;return;
a_G34:if(__equal(1454738855,a_1062)){return;}
a_1077();return;
} /* nextpragmatsymbol */
static void a_1585(int a_A[1]){ /* programpragmat+a> */
int a_P[1];
a_1626=100;
a_1629(a_P);a_A[0]=a_P[0];return;
} /* programpragmat */
static void a_1629(int a_A[1]){ /* programpragmat2+a> */
int a_L2;int a_P[1];
a_A[0]=0;
a_G2:if(!a_1603(a_P)){ goto a_G15;}a_L2=a_P[0];
if(!__equal(a_1626,100)){ goto a_G6;}
a_1627=a_L2;
a_1626=2;
a_G6:a_1622();
if(!__equal(1454738932,a_1062)){ goto a_G15;}
a_1622();
a_P[0]=a_A[0];a_1630(a_1627,a_P);a_A[0]=a_P[0];
if(__is(a_A[0])){return;}
if(!__equal(1454738974,a_1062)){ goto a_G13;}
a_1077();return;
a_G13:if(!__equal(1454738968,a_1062)){ goto a_G15;}
a_1622(); goto a_G2;
a_G15:a_P[0]=2093834000;a_1040(-1,1,a_P);
a_A[0]=1;return;
} /* programpragmat2 */
static void a_1630(int a_F1,int a_A[1]){ /* programpragmatitem+>a+>a> */
int a_L3;int a_L4;int a_P[2];
{ if((1454739015<=a_1062 && a_1062<=1516190314)){ goto a_G2;}
 if((1516190316<=a_1062 && a_1062<=1712834475)){ goto a_G6;}
 if((963127691<=a_1062 && a_1062<=1454738090)){  goto a_G10;}
  goto a_G14;}
a_G2:a_L3=to_LIST(a_1011)->offset[a_1062];
a_1622();
if(__is(a_1625)){return;}
a_1606(a_F1,a_L3);return;
a_G6:a_L3=a_1062;
a_1622();
if(__is(a_1625)){return;}
a_1640(a_F1,a_L3);return;
a_G10:a_L3=a_1062;
a_1314(a_P);a_L4=a_P[0];
a_1622();
a_P[0]=a_A[0];a_1631(a_F1,a_L3,a_L4,a_P);a_A[0]=a_P[0];return;
a_G14:a_P[0]=2093834007;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_A[0]=1;return;
} /* programpragmatitem */
static void a_1611(int a_F1,int a_F2,int a_A[1]){ /* findifcondition+>a+>a+a> */
int a_P[3];
{ if(a_F2==963127741){ goto a_G2;}
 if(a_F2==963127782){ goto a_G3;}
 if(a_F2==963127800){ goto a_G4;}
 if(a_F2==963127836){ goto a_G5;}
 if(a_F2==963127809){  goto a_G6;}
  goto a_G7;}
a_G2:a_A[0]=a_1613;return;
a_G3:a_A[0]=a_1608;return;
a_G4:a_A[0]=a_1616;return;
a_G5:a_A[0]=a_1618;return;
a_G6:a_A[0]=a_1617;return;
a_G7:a_P[0]=2093834016;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);
a_A[0]=0;return;
} /* findifcondition */
static void a_1612(void){ /* findmatchingendif */
int a_L1;int a_P[2];
if(!__equal(1454738974,a_1062)){ goto a_G4;}
a_1077();
a_L1=0; goto a_G9;
a_G4:if(!__equal(1454738968,a_1062)){ goto a_G7;}
a_1622();
a_1629(a_P);a_L1=a_P[0]; goto a_G9;
a_G7:a_P[0]=2093834000;a_1040(-1,1,a_P);
a_L1=1;
a_G9:if(!__equal(a_L1,1)){ goto a_G11;}
a_1269();
a_G11:if(__equal(a_L1,2)){return;}
a_1357();
if(!__equal(1454738855,a_1062)){return;}
a_P[0]=2093834036;a_P[1]=a_1624;a_1040(-1,2,a_P);return;
} /* findmatchingendif */
static void a_1610(int a_F1,int a_F2){ /* dopragmatskip+>a+>a */
int a_L3;int a_L4;
a_L3=a_1624;
a_1624=a_F1;
a_L4=a_1625;
if(!__is(a_F2)){ goto a_G6;}
__incr(a_1625);
a_G6:a_1612();
a_1625=a_L4;
a_1624=a_L3;return;
} /* dopragmatskip */
static void a_1631(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* programtagpragmat2+>a+>a+>a+>a> */
int a_L5;int a_P[3];
{ if(a_F1==963127926){ goto a_G2;}
 if(a_F1==963127935){ goto a_G6;}
 if(a_F1==963127944){ goto a_G10;}
 if(a_F1==963127953){ goto a_G14;}
 if(a_F1==963127962){ goto a_G18;}
 if(a_F1==963127971){  goto a_G26;}
  goto a_G31;}
a_G2:a_1611(a_F1,a_F2,a_P);a_L5=a_P[0];
if(!__is(a_L5)){ goto a_G5;}
a_G4:a_1610(a_F2,0);return;
a_G5:a_1610(a_F2,1);return;
a_G6:a_1611(a_F1,a_F2,a_P);a_L5=a_P[0];
if(__is(a_L5)){ goto a_G5;} goto a_G4;
a_G10:a_1582(a_F2,a_P);a_L5=a_P[0];
if(__equal(a_L5,2)){ goto a_G4;} goto a_G5;
a_G14:a_1582(a_F2,a_P);a_L5=a_P[0];
if(__noteq(a_L5,2)){ goto a_G5;} goto a_G4;
a_G18:if(!__equal(a_1624,a_F2)){ goto a_G23;}
if(!__equal(a_1625,0)){ goto a_G21;}
a_G20:a_1625=1;return;
a_G21:if(!__equal(a_1625,1)){return;}
a_1625=0;return;
a_G23:a_P[0]=2093834047;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);
if(__more(a_1625,0)){return;} goto a_G20;
a_G26:if(!__equal(a_1624,a_F2)){ goto a_G28;}
a_G27:a_A[0]=2;return;
a_G28:a_P[0]=2093834047;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);
if(__equal(a_1624,0)){return;} goto a_G27;
a_G31:if(__is(a_1625)){return;}
a_1642(a_F1,a_F2,a_F3);return;
} /* programtagpragmat2 */
static void a_1609(int a_F1,int a_F2){ /* discpragmat+>a+>a */

a_1012(2106125329);
a_1015(a_F1);
a_1015(a_F2);return;
} /* discpragmat */
static void a_1623(int a_F1,int a_F3,int a_A[1]){ /* onoffpragmats+>a+>a>+>a */
int a_P[3];
if(!__equal(a_F3,963127698)){ goto a_G3;}
a_A[0]=1;return;
a_G3:if(!__equal(a_F3,963127706)){ goto a_G5;}
a_A[0]=0;return;
a_G5:a_P[0]=2093834016;a_P[1]=a_F1;a_P[2]=a_F3;a_1040(-1,3,a_P);return;
} /* onoffpragmats */
static void a_1642(int a_F1,int a_F2,int a_F3){ /* tagpragmat2+>a+>a+>a */
int a_P[3];
{ if(a_F1==963127741){ goto a_G2;}
 if(a_F1==963127782){ goto a_G7;}
 if(a_F1==963127809){ goto a_G12;}
 if(a_F1==963127800){ goto a_G17;}
 if(a_F1==963127873){ goto a_G22;}
 if(a_F1==963127791){ goto a_G30;}
 if(a_F1==963127845||a_F1==963127854){ goto a_G36;}
 if(a_F1==963127863||a_F1==963127891){ goto a_G37;}
 if(a_F1==963127900){ goto a_G38;}
 if(a_F1==963127918){ goto a_G39;}
 if(a_F1==963127909){  goto a_G40;}
  goto a_G41;}
a_G2:if(!__equal(a_F2,963127698)){ goto a_G4;}
a_1613=1;return;
a_G4:if(!__equal(a_F2,963127706)){ goto a_G6;}
a_1613=0;return;
a_G6:a_P[0]=2093834016;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);return;
a_G7:if(!__equal(a_F2,963127698)){ goto a_G9;}
a_1608=1;return;
a_G9:if(!__equal(a_F2,963127706)){ goto a_G6;}
a_1608=0;return;
a_G12:if(!__equal(a_F2,963127698)){ goto a_G14;}
a_1639();return;
a_G14:if(!__equal(a_F2,963127706)){ goto a_G6;}
a_1605();return;
a_G17:if(!__equal(a_F2,963127698)){ goto a_G19;}
a_1616=1;return;
a_G19:if(!__equal(a_F2,963127706)){ goto a_G6;}
a_1616=0;return;
a_G22:if(__equal(a_F2,963127714)){ goto a_G24;}
if(!__equal(a_F2,963127723)){ goto a_G25;}
a_G24:a_1633=0;return;
a_G25:if(!__equal(a_F2,963127863)){ goto a_G27;}
a_1633=2;return;
a_G27:if(!__equal(a_F2,963127882)){ goto a_G6;}
a_1633=1;return;
a_G30:if(!__equal(a_1616,0)){ goto a_G32;}
a_P[0]=2093834059;a_P[1]=a_F1;a_1041(2,-1,2,a_P);return;
a_G32:if(__equal(a_F2,963127714)){ goto a_G34;}
if(!__equal(a_F2,963127706)){ goto a_G6;}
a_G34:a_1644=0;return;
a_G36:a_1620(a_F2,a_F3);return;
a_G37:a_1621(a_F2,a_F3);return;
a_G38:a_P[0]=a_1643;a_1623(963127900,a_F2,a_P);a_1643=a_P[0];return;
a_G39:a_P[0]=a_1607;a_1623(963127918,a_F2,a_P);a_1607=a_P[0];return;
a_G40:a_P[0]=a_1604;a_1623(963127909,a_F2,a_P);a_1604=a_P[0];return;
a_G41:a_P[0]=2093834007;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* tagpragmat2 */
static void a_1606(int a_F1,int a_F2){ /* conspragmat2+>a+>a */
int a_P[3];
{ if(a_F1==963127751){ goto a_G2;}
 if(a_F1==963127772){ goto a_G5;}
 if(a_F1==963127761){  goto a_G9;}
  goto a_G12;}
a_G2:{ if(!((1<=a_F2 && a_F2<=20))){ goto a_G4;}
}
a_1641=a_F2;return;
a_G4:a_P[0]=2093834027;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);return;
a_G5:{ if(!((0<=a_F2 && a_F2<=9))){ goto a_G4;}
}
a_1645=a_F2;
a_1609(3429889,a_1645);return;
a_G9:{ if(!((20<=a_F2 && a_F2<=1000))){ goto a_G4;}
}
a_1635=a_F2;return;
a_G12:a_P[0]=2093834007;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* conspragmat2 */
static void a_1640(int a_F1,int a_F2){ /* stringpragmat2+>a+>a */
int a_P[2];
{ if(a_F1==963127827){ goto a_G2;}
 if(a_F1==963127818){ goto a_G3;}
 if(a_F1==963127732){ goto a_G4;}
 if(a_F1==963127836){  goto a_G6;}
  goto a_G10;}
a_G2:a_1342(a_F2);return;
a_G3:a_1343(a_F2);return;
a_G4:if(!__is(a_1616)){return;}
a_1632=a_F2;return;
a_G6:if(!__is(a_1616)){return;}
a_1632=a_F2;
a_1618=1;
a_1633=2;return;
a_G10:a_1312(a_F2);
a_P[0]=2093834007;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* stringpragmat2 */
static void a_1601(void){ /* @root */

} /* @root */
static void a_1659(int a_F1){ /* handleformallist+>a */
int a_P[1];
{register int a_r1=to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2];
 if(!(a_r1==16777596||a_r1==16777602)){return;}
}
a_1054(a_F1,a_P);to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-5]=a_P[0];
a_1055(a_F1,a_P);to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-4]=a_P[0];return;
} /* handleformallist */
static void a_1674(int a_F1,int a_A[1]){ /* setuplocalstack+>a+a> */
int a_L3;int a_P[1];
__scratch(a_1022);
a_1050(a_F1,a_P);a_L3=a_P[0];
a_G3:if(__equal(a_L3,0)){ goto a_G8;}
 a_extension(a_1022,6);to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[5]=0;to_LIST(a_1022)->top[4]=to_LIST(a_1020)->offset[a_L3-3];to_LIST(a_1022)->top[6]=a_L3;to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
a_1659(a_L3);
a_1266(a_L3,to_LIST(a_1022)->aupb);
a_1050(a_L3,a_P);a_L3=a_P[0]; goto a_G3;
a_G8:a_A[0]=to_LIST(a_1022)->aupb;
a_1012(2106125279);
a_1017(a_F1);
 a_extension(a_1022,6);to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[5]=0;to_LIST(a_1022)->top[4]=16777654;to_LIST(a_1022)->top[6]=a_F1;to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->aupb+=6;
 return;
} /* setuplocalstack */
static void a_1665(int a_F1,int a_A[1]){ /* opennewlocalrange+>a+a> */

a_A[0]=to_LIST(a_1022)->aupb;
if(__equal(a_F1,0)){return;}
 a_extension(a_1022,6);to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[5]=to_LIST(a_1022)->top[1]=to_LIST(a_1022)->top[2]=0;to_LIST(a_1022)->top[4]=16777654;to_LIST(a_1022)->top[6]=a_F1;to_LIST(a_1022)->aupb+=6;
a_1012(2106125279);
a_1017(a_F1);return;
} /* opennewlocalrange */
static void a_1647(int a_F1){ /* addlocalaffix+>a */
int a_L2;int a_L3;int a_P[1];
a_1056(a_F1,a_P);a_L2=a_P[0];
a_1058(a_F1,a_P);a_L3=a_P[0];
 a_extension(a_1022,6);to_LIST(a_1022)->top[3]=to_LIST(a_1022)->top[5]=0;to_LIST(a_1022)->top[4]=16777650;to_LIST(a_1022)->top[6]=a_F1;to_LIST(a_1022)->top[1]=a_L2;to_LIST(a_1022)->top[2]=a_L3;to_LIST(a_1022)->aupb+=6;
a_1267(a_F1,16777650);
a_1266(a_F1,to_LIST(a_1022)->aupb);return;
} /* addlocalaffix */
static void a_1655(int a_F1){ /* closelocalrange+>a */

a_G1:if(__lseq(to_LIST(a_1022)->aupb,a_F1)){return;}
if(!__equal(to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-2],16777650)){ goto a_G5;}
a_1266(to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb],to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-5]);
a_1267(to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb],to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb-4]);
a_G5:__unstack(a_1022); goto a_G1;
} /* closelocalrange */
static void a_1676(void){ /* skipoveranindex */
int a_P[2];
if(!__equal(1454738947,a_1062)){return;}
a_1077();
a_1679(a_P);
if(!__equal(1454738950,a_1062)){ goto a_G6;}
a_1077();return;
a_G6:if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834077;a_P[1]=1454738950;a_1040(-1,2,a_P);return;
} /* skipoveranindex */
static void a_1679(int a_A[1]){ /* skipoversource+a> */
int a_L2;int a_P[2];
a_A[0]=0;
a_L2=a_1062;
if(a_1432(a_P)){return;}
if(!a_1261(a_P)){ goto a_G15;}
if(!__equal(1454738956,a_1062)){ goto a_G12;}
a_1077();
if(!a_1261(a_P)){ goto a_G9;}
a_G8:a_1676();return;
a_G9:if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834095;a_P[1]=1454738956;a_1040(-1,2,a_P);return;
a_G12:if(__equal(1454738947,a_1062)){ goto a_G8;}
a_A[0]=1;return;
a_G15:if(!__equal(1454738941,a_1062)){ goto a_G17;}
a_G16:a_1077(); goto a_G25;
a_G17:if(__equal(1454738944,a_1062)){ goto a_G16;}
if(__equal(1454738935,a_1062)){ goto a_G16;}
if(__equal(1454738938,a_1062)){ goto a_G16;}
if(__equal(1454738953,a_1062)){ goto a_G16;} goto a_G29;
a_G25:if(a_1261(a_P)){return;}
if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834095;a_P[1]=a_L2;a_1040(-1,2,a_P);return;
a_G29:if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834109;a_1040(-1,1,a_P);return;
} /* skipoversource */
static void a_1677(void){ /* skipoverdestination */
int a_P[2];
if(!__equal(1454738929,a_1062)){ goto a_G9;}
a_G2:a_1077();
if(!a_1261(a_P)){ goto a_G6;}
if(!__equal(1454738929,a_1062)){return;} goto a_G2;
a_G6:if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834119;a_1040(-1,1,a_P);return;
a_G9:if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834077;a_P[1]=1454738929;a_1040(-1,2,a_P);return;
} /* skipoverdestination */
static void a_1678(int a_F1,int a_A[2]){ /* skipoverextension+>a+a>+a> */
int a_P[1];
a_1683=0;
a_A[0]=0;a_A[1]=0;
a_1431();
a_1421(1454738956);
a_G5:a_1679(a_P);
a_1677();
if(!__equal(1454738968,a_1062)){ goto a_G9;}
a_1077(); goto a_G5;
a_G9:a_1263(1454738956);
if(!__is(a_F1)){ goto a_G14;}
if(!__equal(1454738962,a_1062)){ goto a_G14;}
a_1077();
a_A[1]=1;
a_G14:if(a_1261(a_P)){a_A[0]=a_P[0]; goto a_G18;}
if(__is(a_1683)){ goto a_G18;}
a_1683=1;
a_P[0]=2093834129;a_1040(-1,1,a_P);
a_G18:if(!__is(a_1683)){ goto a_G21;}
a_1427();
a_1268();return;
a_G21:a_1437();return;
} /* skipoverextension */
static void a_1666(int a_A[1]){ /* peekaftersource+a> */
int a_L2;int a_P[1];
a_1683=0;
a_1431();
a_A[0]=0;
a_1679(a_P);a_L2=a_P[0];
if(a_1661(a_1062,a_P)){a_A[0]=a_P[0]; goto a_G10;}
if(__is(a_L2)){ goto a_G10;}
if(__is(a_1683)){ goto a_G10;}
a_1683=1;
a_P[0]=2093834136;a_1040(-1,1,a_P);
a_G10:if(!__is(a_1683)){ goto a_G13;}
a_1427();
a_1268();return;
a_G13:a_1437();return;
} /* peekaftersource */
static void a_1672(int a_F1){ /* searchjump+>a */
int a_L2;int a_P[3];
a_L2=to_LIST(a_1022)->aupb;
a_G2:if(!__less(a_L2,to_LIST(a_1022)->alwb)){ goto a_G4;}
a_P[0]=2093834145;a_P[1]=a_1671;a_P[2]=a_F1;a_1040(-1,3,a_P);return;
a_G4:if(!__equal(to_LIST(a_1022)->offset[a_L2-2],16777654)){ goto a_G8;}
if(!__equal(to_LIST(a_1022)->offset[a_L2],a_F1)){ goto a_G8;}
a_1012(2106125275);
a_1017(a_L2);return;
a_G8:__previous(a_1022,a_L2); goto a_G2;
} /* searchjump */
static int a_1684(void){ /* terminator */
int a_L1;int a_P[2];
if(!__equal(1454738980,a_1062)){ goto a_G4;}
a_1077();
a_1012(2106125321); return 1;
a_G4:if(!__equal(1454738977,a_1062)){ goto a_G7;}
a_1077();
a_1012(2106125302); return 1;
a_G7:if(!__equal(1454738879,a_1062)){ goto a_G14;}
a_1077();
a_1017(483807586);
a_1271(483807586);
a_1012(2106125321);
a_1683=0;
a_1680(483807586); return 1;
a_G14:if(!__equal(1454738965,a_1062)){ return 0;}
a_1077();
if(!a_1261(a_P)){ goto a_G18;}a_L1=a_P[0];
a_1672(a_L1); return 1;
a_G18:a_P[0]=2093834095;a_P[1]=1454738965;a_1040(-1,2,a_P); return 1;
} /* terminator */
static void a_1660(int a_F1){ /* indexsource+>a */
int a_P[3];
if(!__equal(1454738947,a_1062)){ goto a_G12;}
a_1077();
a_1012(2106125346);
a_1017(a_F1);
a_1680(a_F1);
a_1012(2106125224);
if(!__equal(1454738950,a_1062)){ goto a_G9;}
a_1077();return;
a_G9:if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834087;a_P[1]=1454738950;a_P[2]=a_F1;a_1040(-1,3,a_P);return;
a_G12:a_1012(2106125346);
a_1017(a_F1);
a_1012(2106125358);
a_1017(a_F1);
a_1012(2106125224);return;
} /* indexsource */
static void a_1673(int a_F1,int a_F2){ /* selector+>a+>a */
int a_L3;int a_L4;int a_P[2];
a_1440(a_F1,a_F2,a_P);a_F1=a_P[0];
if(!a_1060(a_F2)){ goto a_G10;}
a_1058(a_F1,a_P);a_L3=a_P[0];
if(!__equal(a_L3,16777590)){ goto a_G6;}
a_1056(a_F1,a_P);a_L4=a_P[0]; goto a_G7;
a_G6:a_L4=-1;
a_G7:if(!__more(a_L4,0)){ goto a_G9;}
a_1015(a_L4);return;
a_G9:a_P[0]=2093834164;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
a_G10:a_1017(a_F1);return;
} /* selector */
static void a_1662(int a_F1){ /* listtag+>a */
int a_L2;int a_P[2];
if(!a_1261(a_P)){ goto a_G4;}a_L2=a_P[0];
a_1271(a_L2);
a_1017(a_L2);return;
a_G4:if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834095;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* listtag */
static void a_1680(int a_F1){ /* source+>a */
int a_L2;int a_L3;int a_P[2];
if(!a_1432(a_P)){ goto a_G3;}a_L2=a_P[0];
a_1015(a_L2);return;
a_G3:if(!a_1261(a_P)){ goto a_G19;}a_L2=a_P[0];
if(!__equal(1454738956,a_1062)){ goto a_G13;}
a_1077();
if(!a_1261(a_P)){ goto a_G10;}a_L3=a_P[0];
a_1660(a_L3);
a_1271(a_L3);
a_1673(a_L2,a_L3);return;
a_G10:if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834095;a_P[1]=1454738956;a_1040(-1,2,a_P);return;
a_G13:if(!__equal(1454738947,a_1062)){ goto a_G17;}
a_1660(a_L2);
a_1271(a_L2);
a_1673(a_L2,a_L2);return;
a_G17:a_1271(a_L2);
a_1017(a_L2);return;
a_G19:if(!__equal(1454738941,a_1062)){ goto a_G23;}
a_1077();
a_1012(2106125294);
a_1662(1454738941);return;
a_G23:if(!__equal(1454738944,a_1062)){ goto a_G27;}
a_1077();
a_1012(2106125358);
a_1662(1454738944);return;
a_G27:if(!__equal(1454738935,a_1062)){ goto a_G31;}
a_1077();
a_1012(2106125362);
a_1662(1454738935);return;
a_G31:if(!__equal(1454738938,a_1062)){ goto a_G35;}
a_1077();
a_1012(2106125366);
a_1662(1454738938);return;
a_G35:if(!__equal(1454738953,a_1062)){ goto a_G39;}
a_1077();
a_1012(2106125229);
a_1662(1454738953);return;
a_G39:if(__is(a_1683)){ goto a_G42;}
a_1683=1;
a_P[0]=2093834154;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_G42:a_1268();return;
} /* source */
static void a_1681(int a_F1){ /* sourceorstring+>a */
int a_L2;int a_L3;int a_P[1];
if(!a_1260(a_P)){ goto a_G7;}a_L2=a_P[0];
a_1264(a_L2,a_P);a_L3=a_P[0];
a_1012(2106125321);
a_1017(483807556);
a_1012(2106125321);
a_1017(a_L3);return;
a_G7:if(!__equal(1454738983,a_1062)){ goto a_G11;}
a_G8:a_1077();
a_1012(2106125321);
a_1012(2106125305);return;
a_G11:if(__equal(1454738986,a_1062)){ goto a_G8;}
a_1012(2106125321);
a_1680(a_F1);return;
} /* sourceorstring */
static int a_1668(void){ /* repeataffix */
int a_P[2];
if(!__equal(1454738956,a_1062)){ return 0;}
a_1077();
if(!__is(a_1658)){ goto a_G6;}
a_1012(2106125321);
a_1017(a_1658); return 1;
a_G6:a_P[0]=2093834194;a_P[1]=a_1671;a_1040(-1,2,a_P); return 1;
} /* repeataffix */
static void a_1649(void){ /* affixform */
int a_L1;int a_P[2];
if(!a_1261(a_P)){ goto a_G12;}a_L1=a_P[0];
if(!a_1060(a_L1)){ goto a_G5;}
a_P[0]=2093834184;a_P[1]=a_L1;a_1040(-1,2,a_P);
a_1268();return;
a_G5:a_1017(a_L1);
a_1271(a_L1);
a_1683=0;
a_G8:if(!__equal(1454738980,a_1062)){return;}
a_1077();
if(a_1668()){return;}
a_1681(a_L1); goto a_G8;
a_G12:a_P[0]=2093834101;a_1040(-1,1,a_P);
a_1268();return;
} /* affixform */
static void a_1682(int a_F1){ /* specialaffixform+>a */

a_1017(a_F1);
a_1271(a_F1);
a_1012(2106125321);
a_1683=0;
a_1680(a_F1);
if(__is(a_1683)){ goto a_G8;}
a_1077();
a_G8:a_1012(2106125321);
a_1680(a_F1);
if(!__equal(a_F1,483807580)){return;}
a_G11:if(!__equal(1454738929,a_1062)){return;}
a_1077();
a_1012(2106125321);
a_1680(a_F1); goto a_G11;
} /* specialaffixform */
static void a_1685(int a_F1){ /* toselectors+>a */
int a_L2;int a_P[2];
if(!__equal(1454738929,a_1062)){ goto a_G12;}
a_G2:a_1077();
if(!a_1261(a_P)){ goto a_G8;}a_L2=a_P[0];
a_1012(2106125354);
a_1673(a_L2,a_F1);
if(!__equal(1454738929,a_1062)){return;} goto a_G2;
a_G8:if(__is(a_1683)){ goto a_G11;}
a_1683=1;
a_P[0]=2093834095;a_P[1]=1454738929;a_1040(-1,2,a_P);
a_G11:a_1268();return;
a_G12:if(__is(a_1683)){return;}
a_1683=1;
a_P[0]=2093834077;a_P[1]=1454738929;a_1040(-1,2,a_P);return;
} /* toselectors */
static void a_1657(int a_F1){ /* extension+>a */

a_1012(2106125263);
a_1271(a_F1);
a_1017(a_F1);
a_1421(1454738956);
a_1683=0;
a_G6:a_1680(a_F1);
a_1685(a_F1);
if(!__equal(1454738968,a_1062)){ goto a_G10;}
a_1077(); goto a_G6;
a_G10:a_1012(2106125263);
a_1421(1454738956);
a_1421(1454738962);
a_1421(a_F1);return;
} /* extension */
static int a_1663(void){ /* lookingatamember */

{ if(a_1062==1454738959||a_1062==1454738956||a_1062==1454738941||a_1062==1454738944||a_1062==1454738935||a_1062==1454738938||a_1062==1454738953||(1454739015<=a_1062 && a_1062<=1516190314)||(963127691<=a_1062 && a_1062<=1454738090)){  return 1;}
  return 0;}
} /* lookingatamember */
static void a_1664(void){ /* member */
int a_L1;int a_L2;int a_P[2];
if(!__equal(1454738959,a_1062)){ goto a_G10;}
a_1077();
if(!__equal(1454738956,a_1062)){ goto a_G8;}
a_1678(1,a_P);a_L1=a_P[0];a_L2=a_P[1];
if(__is(a_1683)){return;}
if(!__is(a_L2)){ goto a_G8;}
a_G7:a_1657(a_L1);return;
a_G8:a_1656();return;
a_G10:if(!__equal(1454738956,a_1062)){ goto a_G14;}
a_1678(0,a_P);a_L1=a_P[0];
if(__is(a_1683)){return;} goto a_G7;
a_G14:a_1666(a_P);a_L1=a_P[0];
if(__is(a_1683)){return;}
if(!__is(a_L1)){ goto a_G18;}
a_1682(a_L1);return;
a_G18:a_1649();return;
} /* member */
static void a_1667(int a_A[1]){ /* peeklabel+a> */
int a_P[1];
a_1431();
a_A[0]=0;
if(!a_1261(a_P)){ goto a_G7;}a_A[0]=a_P[0];
if(__equal(1454738965,a_1062)){ goto a_G7;}
if(__equal(1454738977,a_1062)){ goto a_G7;}
a_A[0]=0;
a_G7:a_1437();return;
} /* peeklabel */
static void a_1675(int a_F1){ /* skiplabel+>a */

if(!__is(a_F1)){return;}
a_1421(a_F1);
a_1421(1454738965);return;
} /* skiplabel */
static void a_1648(void){ /* addlocalaffixes */
int a_L1;int a_P[2];
a_1431();
if(!__equal(1454738977,a_1062)){ goto a_G19;}
a_1077();
if(!a_1261(a_P)){ goto a_G19;}
a_1437();
a_1012(2106125290);
a_G7:if(!__equal(1454738977,a_1062)){ goto a_G14;}
a_1077();
if(!a_1261(a_P)){ goto a_G12;}a_L1=a_P[0];
a_1017(a_L1);
a_1647(a_L1); goto a_G7;
a_G12:a_P[0]=2093834095;a_P[1]=1454738977;a_1040(-1,2,a_P);
a_G13:a_1268();return;
a_G14:if(!__equal(1454738965,a_1062)){ goto a_G17;}
a_1077();
a_1012(2106125235);return;
a_G17:a_P[0]=2093834077;a_P[1]=1454738965;a_1040(-1,2,a_P); goto a_G13;
a_G19:a_1437();return;
} /* addlocalaffixes */
static void a_1656(void){ /* compoundmember */
int a_L1;int a_L2;int a_P[2];
a_1012(2106125312);
a_1667(a_P);a_L1=a_P[0];
a_1665(a_L1,a_P);a_L2=a_P[0];
a_1675(a_L1);
a_1648();
if(!__equal(1454738932,a_1062)){ goto a_G9;}
a_1077();
a_1653(); goto a_G10;
a_G9:a_1651();
a_G10:if(!__equal(1454738962,a_1062)){ goto a_G12;}
a_1077(); goto a_G14;
a_G12:a_P[0]=2093834077;a_P[1]=1454738962;a_1040(-1,2,a_P);
a_1268();
a_G14:a_1012(2106125232);
a_1655(a_L2);return;
} /* compoundmember */
static void a_1650(void){ /* alternative */
int a_P[2];
a_G1:if(a_1684()){return;}
if(!a_1663()){ goto a_G7;}
a_1664();
if(!__equal(1454738968,a_1062)){return;}
a_1077();
a_1012(2106125238); goto a_G1;
a_G7:a_P[0]=2093834173;a_P[1]=a_1671;a_1040(-1,2,a_P);return;
} /* alternative */
static void a_1651(void){ /* alternativeseries */

a_G1:a_1650();
if(!__equal(1454738971,a_1062)){return;}
a_1077();
a_1012(2106125340); goto a_G1;
} /* alternativeseries */
static void a_1654(void){ /* classifier */
int a_L1;int a_L2;int a_P[2];
a_G1:a_L2=0;
if(!a_1261(a_P)){ goto a_G5;}a_L1=a_P[0];
a_1017(a_L1);
a_1271(a_L1); goto a_G8;
a_G5:if(!a_1432(a_P)){ goto a_G7;}a_L1=a_P[0];
a_1015(a_L1); goto a_G8;
a_G7:a_L2=1;
a_G8:if(!__equal(1454738965,a_1062)){ goto a_G17;}
a_1077();
a_L2=0;
a_1012(2106125235);
if(!a_1261(a_P)){ goto a_G15;}a_L1=a_P[0];
a_1017(a_L1);
a_1271(a_L1); goto a_G17;
a_G15:if(!a_1432(a_P)){ goto a_G17;}a_L1=a_P[0];
a_1015(a_L1);
a_G17:if(!__is(a_L2)){ goto a_G19;}
a_P[0]=2093834206;a_P[1]=a_1671;a_1040(-1,2,a_P);
a_G19:if(!__equal(1454738971,a_1062)){ goto a_G22;}
a_1077();
a_1012(2106125340); goto a_G1;
a_G22:a_1263(1454738950);return;
} /* classifier */
static void a_1652(int a_A[1]){ /* area+a> */
int a_P[2];
if(!__equal(1454738947,a_1062)){ goto a_G14;}
a_1077();
a_A[0]=0;
a_1012(2106125217);
a_1654();
a_1012(2106125217);
a_1012(2106125238);
if(!__equal(1454738968,a_1062)){ goto a_G10;}
a_1077(); goto a_G13;
a_G10:if(__is(a_1683)){ goto a_G13;}
a_1683=1;
a_P[0]=2093834077;a_P[1]=1454738968;a_1040(-1,2,a_P);
a_G13:a_1650();return;
a_G14:a_A[0]=1;
a_1012(2106125217);
a_1012(2106125235);
a_1012(2106125217);
a_1012(2106125238);
a_1650();return;
} /* area */
static void a_1653(void){ /* classification */
int a_L1;int a_L2;int a_P[2];
a_1012(2106125221);
a_1683=0;
a_L2=0;
a_1680(1454738932);
a_1012(2106125221);
if(!__equal(1454738932,a_1062)){ goto a_G8;}
a_1077(); goto a_G11;
a_G8:if(__is(a_1683)){ goto a_G11;}
a_1683=1;
a_P[0]=2093834077;a_P[1]=1454738932;a_1040(-1,2,a_P);
a_G11:a_1652(a_P);a_L1=a_P[0];
if(__is(a_L1)){ goto a_G17;}
if(!__equal(1454738971,a_1062)){ goto a_G17;}
a_1077();
a_1012(2106125340);
__incr(a_L2); goto a_G11;
a_G17:if(!__is(a_1683)){ goto a_G19;}
a_1268();return;
a_G19:if(__equal(a_L1,0)){return;}
if(!__equal(a_L2,0)){return;}
a_P[0]=2093834215;a_1040(-1,1,a_P);return;
} /* classification */
static void a_1382(int a_A[1]){ /* getruletag+a> */
int a_P[1];
if(!__is(a_1671)){ goto a_G6;}
a_1316(a_1671,a_P);a_A[0]=a_P[0];
__previous(a_1039,a_A[0]);
a_copystring(a_1039,a_A[0],a_1021);
a_A[0]=to_LIST(a_1021)->aupb;return;
a_G6:a_A[0]=1516190318;return;
} /* getruletag */
static void a_1670(int a_F1){ /* rulepragmats+>a */

if(!a_1321(3429897)){ goto a_G3;}
a_1449(a_F1,16777216);
a_G3:if(!a_1321(3429898)){ goto a_G5;}
a_1449(a_F1,33554432);
a_G5:if(!a_1321(3429896)){return;}
a_1449(a_F1,67108864);return;
} /* rulepragmats */
static void a_1669(int a_F1,int a_F2){ /* rulebody+>a+>a */
int a_L3;int a_P[2];
a_1671=a_F1;
a_1658=a_F2;
a_1012(2106125337);
a_1017(a_1671);
a_1670(a_1671);
a_1674(a_F1,a_P);a_L3=a_P[0];
if(!__equal(1454738977,a_1062)){ goto a_G9;}
a_1648(); goto a_G13;
a_G9:if(!__equal(1454738965,a_1062)){ goto a_G11;}
a_1077(); goto a_G13;
a_G11:a_P[0]=2093834077;a_P[1]=1454738965;a_1040(-1,2,a_P);
a_1268();
a_G13:if(!__equal(1454738932,a_1062)){ goto a_G16;}
a_1077();
a_1653(); goto a_G17;
a_G16:a_1651();
a_G17:a_1012(2106125324);
a_1655(a_L3);
a_1671=0;
if(!__equal(1454738974,a_1062)){ goto a_G22;}
a_1077();return;
a_G22:a_P[0]=2093834077;a_P[1]=1454738974;a_1040(-1,2,a_P);
a_1269();return;
} /* rulebody */
static void a_1587(void){ /* rootbody */
int a_L1;int a_P[2];
a_1671=483807562;
a_1658=0;
a_1012(2106125333);
a_1017(483807562);
a_1670(483807562);
a_1674(483807562,a_P);a_L1=a_P[0];
a_1648();
if(!__equal(1454738932,a_1062)){ goto a_G11;}
a_1077();
a_1653(); goto a_G12;
a_G11:a_1651();
a_G12:a_1012(2106125324);
a_1655(a_L1);
a_1671=0;
if(!__equal(1454738974,a_1062)){ goto a_G17;}
a_1077();return;
a_G17:a_P[0]=2093834077;a_P[1]=1454738974;a_1040(-1,2,a_P);
a_1269();return;
} /* rootbody */
static void a_1646(void){ /* @root */

} /* @root */
static void a_1707(int a_A[1]){ /* musttag+a> */
int a_P[1];
if(a_1261(a_P)){a_A[0]=a_P[0];return;}
a_1063(a_1001,16777479,53);return;
} /* musttag */
static void a_1720(int a_A[2]){ /* skipfieldlist+a>+>a> */
int a_P[1];
if(!__equal(1454738959,a_1062)){ goto a_G16;}
a_1077();
a_A[0]=1;
a_G4:if(!a_1261(a_P)){ goto a_G14;}
if(!__equal(1454738968,a_1062)){ goto a_G8;}
a_1077();
__incr(a_A[0]); goto a_G4;
a_G8:if(!__equal(1454738932,a_1062)){ goto a_G10;}
a_1077(); goto a_G4;
a_G10:if(!__equal(1454738962,a_1062)){ goto a_G12;}
a_1077();return;
a_G12:a_P[0]=2093834223;a_1040(-1,1,a_P);
a_G13:a_A[1]=1;return;
a_G14:a_P[0]=2093834233;a_1040(-1,1,a_P); goto a_G13;
a_G16:a_A[0]=-1;return;
} /* skipfieldlist */
static void a_1706(int a_A[3]){ /* getlisttag+a>+a>+>a> */
int a_P[2];
a_1431();
a_P[1]=a_A[2];a_1720(a_P);a_A[1]=a_P[0];a_A[2]=a_P[1];
a_A[0]=0;
if(a_1261(a_P)){a_A[0]=a_P[0]; goto a_G8;}
if(__is(a_A[2])){ goto a_G8;}
a_P[0]=2093834242;a_1040(-1,1,a_P);
a_A[2]=1;
a_G8:if(!__is(a_A[2])){ goto a_G10;}
a_1427();return;
a_G10:a_1437();return;
} /* getlisttag */
static void a_1722(int a_F1,int a_A[1]){ /* subbus+>a+>a> */
int a_P[3];
if(!__is(a_A[0])){ goto a_G4;}
a_1421(1454738947);
a_1421(1454738950);return;
a_G4:if(!__equal(1454738947,a_1062)){ goto a_G10;}
a_1077();
if(!__equal(1454738950,a_1062)){ goto a_G8;}
a_1077();return;
a_G8:a_A[0]=1;
a_P[0]=2093834253;a_P[1]=a_F1;a_P[2]=1454738950;a_1040(-1,3,a_P);return;
a_G10:a_A[0]=1;
a_P[0]=2093834253;a_P[1]=a_F1;a_P[2]=1454738947;a_1040(-1,3,a_P);return;
} /* subbus */
static void a_1701(int a_F1,int a_A[1]){ /* expectformaltag+>a+>a> */
int a_L3;int a_P[2];
if(!__is(a_A[0])){ goto a_G3;}
if(!a_1584(a_P)){return;}return;
a_G3:if(!a_1261(a_P)){ goto a_G7;}a_L3=a_P[0];
if(!__equal(a_L3,a_F1)){return;}
a_A[0]=1;
a_P[0]=2093834263;a_P[1]=a_L3;a_1040(-1,2,a_P);return;
a_G7:a_A[0]=1;
a_P[0]=2093834273;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* expectformaltag */
static void a_1721(int a_F1,int a_A[1]){ /* skipformalaffix+>a+>a> */
int a_P[3];
if(!__equal(1454738947,a_1062)){ goto a_G6;}
a_P[0]=a_A[0];a_1722(a_F1,a_P);a_A[0]=a_P[0];
a_G3:a_P[1]=a_A[0];a_1720(a_P);a_A[0]=a_P[1];
a_P[0]=a_A[0];a_1701(a_F1,a_P);a_A[0]=a_P[0];
a_G5:a_P[0]=a_A[0];a_1722(a_F1,a_P);a_A[0]=a_P[0];return;
a_G6:if(__equal(1454738959,a_1062)){ goto a_G3;}
if(!__equal(1516190318,a_1062)){ goto a_G13;}
a_1077();
a_P[0]=a_A[0];a_1701(a_F1,a_P);a_A[0]=a_P[0];return;
a_G13:if(!__equal(1454738938,a_1062)){ goto a_G17;}
a_1077();
a_P[0]=a_A[0];a_1701(a_F1,a_P);a_A[0]=a_P[0];
a_1421(1454738938);return;
a_G17:if(!__equal(1454738956,a_1062)){ goto a_G19;}
a_G18:a_1077();return;
a_G19:a_P[0]=a_A[0];a_1701(a_F1,a_P);a_A[0]=a_P[0];
if(__equal(1454738938,a_1062)){ goto a_G18;}
if(__equal(1454738947,a_1062)){ goto a_G5;}
if(__equal(1454738995,a_1062)){return;}
if(__is(a_A[0])){return;}
a_A[0]=1;
a_P[0]=2093834253;a_P[1]=a_F1;a_P[2]=1454738938;a_1040(-1,3,a_P);return;
} /* skipformalaffix */
static void a_1709(int a_F1,int a_A[2]){ /* peekafterformalaffixes+>a+a>+>a> */
int a_P[2];
if(!__is(a_A[1])){ goto a_G3;}
a_A[0]=0;return;
a_G3:a_1431();
a_A[0]=0;
a_G5:if(!__equal(1454738980,a_1062)){ goto a_G8;}
a_1077();
a_P[0]=a_A[1];a_1721(a_F1,a_P);a_A[1]=a_P[0]; goto a_G5;
a_G8:if(__is(a_A[1])){ goto a_G21;}
if(!__equal(1454738974,a_1062)){ goto a_G11;}
a_G10:a_A[0]=1; goto a_G21;
a_G11:if(__equal(1454738968,a_1062)){ goto a_G10;}
if(__equal(1454738932,a_1062)){ goto a_G10;}
if(__equal(1454738995,a_1062)){ goto a_G10;}
if(__equal(1454738977,a_1062)){ goto a_G21;}
if(__equal(1454738965,a_1062)){ goto a_G21;}
a_P[0]=2093834282;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_A[1]=1;
a_G21:if(!__is(a_A[1])){ goto a_G23;}
a_1427();return;
a_G23:a_1437();return;
} /* peekafterformalaffixes */
static void a_1687(int a_F1,int a_F3,int a_F4,int a_A[2]){ /* checkasformal+>a+>a>+>a+>a+>a> */
int a_L6;int a_L7;int a_P[5];
if(__is(a_A[1])){return;}
if(!__is(a_A[0])){ goto a_G8;}
a_1058(a_A[0],a_P);a_L6=a_P[0];
if(__equal(a_L6,a_F4)){return;}
a_1198(a_F1,a_P);a_L7=a_P[0];
a_P[0]=2093834316;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_L6;a_P[4]=a_L7;a_1040(-1,5,a_P);
a_A[1]=1;return;
a_G8:a_1708(a_F4,a_F3,a_P);a_A[0]=a_P[0];return;
} /* checkasformal */
static void a_1697(int a_F1,int a_F3,int a_F4,int a_A[2]){ /* defineasformal+>a+>a>+>a+>a+>a> */
int a_P[3];
if(__is(a_A[1])){return;}
if(!a_1060(a_F3)){ goto a_G5;}
a_A[1]=1;
a_P[0]=2093834382;a_P[1]=a_F1;a_P[2]=a_F3;a_1040(-1,3,a_P);return;
a_G5:a_P[0]=a_A[0];a_P[1]=a_A[1];a_1687(a_F1,a_F3,a_F4,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];
if(__is(a_A[1])){return;}
if(!__equal(a_F3,483807550)){ goto a_G9;}
a_1713=a_A[0];return;
a_G9:a_1712(a_F3,a_A[0]);return;
} /* defineasformal */
static void a_1694(int a_F1,int a_F2,int a_A[1]){ /* checkselectorlist+>a+>a+a> */
int a_L4;int a_P[1];
if(!__equal(1454738959,a_1062)){ goto a_G13;}
a_1077();
a_A[0]=-1;
a_G4:a_1707(a_P);a_L4=a_P[0];
if(!__equal(a_F1,a_L4)){ goto a_G7;}
a_A[0]=a_F2;
a_G7:if(!__equal(1454738968,a_1062)){ goto a_G10;}
a_1077();
__decr(a_F2); goto a_G4;
a_G10:if(!__equal(1454738932,a_1062)){ goto a_G12;}
a_1077(); goto a_G4;
a_G12:a_1263(1454738962);return;
a_G13:a_A[0]=1;return;
} /* checkselectorlist */
static void a_1696(int a_F1,int a_F2,int a_F3,int a_F4,int a_A[1]){ /* createformalselector+>a+>a+>a+>a+>a> */
int a_L6;int a_L7;int a_P[4];
if(__is(a_A[0])){return;}
a_1440(a_F3,a_F2,a_P);a_L6=a_P[0];
if(!a_1060(a_L6)){ goto a_G6;}
a_P[0]=2093834370;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_F3;a_1040(-1,4,a_P);
a_A[0]=1;return;
a_G6:a_1708(16777590,a_L6,a_P);a_L7=a_P[0];
a_1266(a_L7,a_F4);
a_1712(a_L6,a_L7);return;
} /* createformalselector */
static void a_1700(int a_F1,int a_F2,int a_F3,int a_A[2]){ /* defineselectorlist+>a+>a+>a+a>+>a> */
int a_L6;int a_P[1];
if(!__equal(1454738959,a_1062)){ goto a_G16;}
a_1077();
a_A[0]=-1;
a_G4:a_1707(a_P);a_L6=a_P[0];
if(!__equal(a_F2,a_L6)){ goto a_G7;}
a_A[0]=a_F3;
a_G7:a_P[0]=a_A[1];a_1696(a_F1,a_F2,a_L6,a_F3,a_P);a_A[1]=a_P[0];
if(!__equal(1454738968,a_1062)){ goto a_G11;}
a_1077();
__decr(a_F3); goto a_G4;
a_G11:if(!__equal(1454738932,a_1062)){ goto a_G13;}
a_1077(); goto a_G4;
a_G13:a_1263(1454738962);
if(__more(a_A[0],0)){return;}
a_P[0]=a_A[1];a_1696(a_F1,a_F2,a_F2,-1,a_P);a_A[1]=a_P[0];return;
a_G16:a_A[0]=1;
a_P[0]=a_A[1];a_1696(a_F1,a_F2,a_F2,1,a_P);a_A[1]=a_P[0];return;
} /* defineselectorlist */
static void a_1691(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6,int a_A[1]){ /* checkformallistdata+>a+>a+>a+>a+>a+>a+>a> */
int a_L8;int a_L9;int a_L10;int a_L11;int a_P[5];
a_1198(a_F1,a_P);a_L11=a_P[0];
a_1058(a_F2,a_P);a_L10=a_P[0];
a_1054(a_F2,a_P);a_L8=a_P[0];
a_1055(a_F2,a_P);a_L9=a_P[0];
if(!__noteq(a_F4,a_L10)){ goto a_G8;}
a_P[0]=2093834316;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_L10;a_P[4]=a_L11;a_1040(-1,5,a_P);
a_G7:a_A[0]=1;return;
a_G8:if(!__noteq(a_F5,a_L8)){ goto a_G11;}
a_P[0]=2093834333;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_L11;a_1040(-1,4,a_P); goto a_G7;
a_G11:if(!__noteq(a_F6,a_L9)){return;}
a_P[0]=2093834353;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_L11;a_1040(-1,4,a_P); goto a_G7;
} /* checkformallistdata */
static void a_1688(int a_F1,int a_F3,int a_F4,int a_F5,int a_A[2]){ /* checkasformallist+>a+>a>+>a+>a+>a+>a> */
int a_L7;int a_P[1];
a_1694(a_F3,a_F5,a_P);a_L7=a_P[0];
a_1421(a_F3);
a_P[0]=a_A[1];a_1722(a_F1,a_P);a_A[1]=a_P[0];
if(!__is(a_A[0])){ goto a_G6;}
a_P[0]=a_A[1];a_1691(a_F1,a_A[0],a_F3,a_F4,a_F5,a_L7,a_P);a_A[1]=a_P[0];return;
a_G6:a_1708(a_F4,a_F3,a_P);a_A[0]=a_P[0];
a_1710(a_A[0],a_F5);
a_1711(a_A[0],a_L7);return;
} /* checkasformallist */
static void a_1698(int a_F1,int a_F3,int a_F4,int a_F5,int a_A[2]){ /* defineasformallist+>a+>a>+>a+>a+>a+>a> */
int a_L7;int a_P[3];
if(!a_1060(a_F3)){ goto a_G4;}
a_A[1]=1;
a_P[0]=2093834382;a_P[1]=a_F1;a_P[2]=a_F3;a_1040(-1,3,a_P);return;
a_G4:a_P[1]=a_A[1];a_1700(a_F1,a_F3,a_F5,a_P);a_L7=a_P[0];a_A[1]=a_P[1];
a_1421(a_F3);
a_P[0]=a_A[1];a_1722(a_F1,a_P);a_A[1]=a_P[0];
if(__is(a_A[1])){ goto a_G13;}
if(!__is(a_A[0])){ goto a_G10;}
a_P[0]=a_A[1];a_1691(a_F1,a_A[0],a_F3,a_F4,a_F5,a_L7,a_P);a_A[1]=a_P[0]; goto a_G13;
a_G10:a_1708(a_F4,a_F3,a_P);a_A[0]=a_P[0];
a_1710(a_A[0],a_F5);
a_1711(a_A[0],a_L7);
a_G13:if(__is(a_A[1])){return;}
a_1712(a_F3,a_A[0]);return;
} /* defineasformallist */
static void a_1704(int a_F1,int a_F2,int a_F4,int a_A[2]){ /* formallistaffix+>a+>a+>a>+>a+>a> */
int a_L6;int a_L7;int a_P[3];
a_P[2]=a_A[1];a_1706(a_P);a_L6=a_P[0];a_L7=a_P[1];a_A[1]=a_P[2];
if(__is(a_A[1])){return;}
if(!__is(a_F2)){ goto a_G5;}
a_P[0]=a_A[0];a_P[1]=a_A[1];a_1688(a_F1,a_L6,a_F4,a_L7,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
a_G5:a_P[0]=a_A[0];a_P[1]=a_A[1];a_1698(a_F1,a_L6,a_F4,a_L7,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
} /* formallistaffix */
static void a_1689(int a_F1,int a_F2,int a_A[2]){ /* checkasformaltableaffix+>a+>a+>a>+>a> */
int a_P[1];
if(!__is(a_A[0])){ goto a_G3;}
a_P[0]=a_A[1];a_1691(a_F1,a_A[0],a_F2,16777602,-1,1,a_P);a_A[1]=a_P[0];return;
a_G3:a_1708(16777602,a_F2,a_P);a_A[0]=a_P[0];
a_1710(a_A[0],-1);
a_1711(a_A[0],1);return;
} /* checkasformaltableaffix */
static void a_1699(int a_F1,int a_F2,int a_A[2]){ /* defineasformaltableaffix+>a+>a+>a>+>a> */
int a_P[3];
if(__is(a_A[1])){return;}
if(!a_1060(a_F2)){ goto a_G5;}
a_A[1]=1;
a_P[0]=2093834382;a_P[1]=a_F1;a_P[2]=a_F2;a_1040(-1,3,a_P);return;
a_G5:a_P[0]=a_A[0];a_P[1]=a_A[1];a_1689(a_F1,a_F2,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];
if(__is(a_A[1])){return;}
a_P[0]=a_A[1];a_1696(a_F1,a_F2,a_F2,1,a_P);a_A[1]=a_P[0];
a_1712(a_F2,a_A[0]);return;
} /* defineasformaltableaffix */
static void a_1705(int a_F1,int a_F2,int a_F4,int a_A[2]){ /* formaltableaffix+>a+>a+>a>+>a+>a> */
int a_P[2];
if(!__is(a_F2)){ goto a_G3;}
a_P[0]=a_A[0];a_P[1]=a_A[1];a_1689(a_F1,a_F4,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
a_G3:a_P[0]=a_A[0];a_P[1]=a_A[1];a_1699(a_F1,a_F4,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
} /* formaltableaffix */
static void a_1703(int a_F1,int a_F2,int a_F4,int a_F5,int a_A[2]){ /* formalflataffix+>a+>a+>a>+>a+>a+>a> */
int a_P[2];
if(!__is(a_F2)){ goto a_G3;}
a_P[0]=a_A[0];a_P[1]=a_A[1];a_1687(a_F1,a_F4,a_F5,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
a_G3:a_P[0]=a_A[0];a_P[1]=a_A[1];a_1697(a_F1,a_F4,a_F5,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
} /* formalflataffix */
static void a_1702(int a_F1,int a_F2,int a_A[2]){ /* formalaffix+>a+>a+>a>+>a> */
int a_L5;int a_L6;int a_P[2];
if(__is(a_A[1])){return;}
if(!__equal(1454738947,a_1062)){ goto a_G6;}
a_1077();
a_1421(1454738950);
a_P[0]=a_A[0];a_P[1]=a_A[1];a_1704(a_F1,a_F2,16777596,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
a_G6:if(!__equal(1454738959,a_1062)){ goto a_G8;}
a_P[0]=a_A[0];a_P[1]=a_A[1];a_1704(a_F1,a_F2,16777602,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
a_G8:if(!__equal(1516190318,a_1062)){ goto a_G12;}
a_1077();
a_1707(a_P);a_L5=a_P[0];
a_P[0]=a_A[0];a_P[1]=a_A[1];a_1703(a_F1,a_F2,a_L5,16777607,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
a_G12:if(!__equal(1454738938,a_1062)){ goto a_G22;}
a_1077();
a_1707(a_P);a_L5=a_P[0];
if(!__equal(1454738938,a_1062)){ goto a_G18;}
a_1077();
a_G17:a_L6=16777623; goto a_G21;
a_G18:if(__equal(1454738938,a_1062)){ goto a_G17;}
a_L6=16777612;
a_G21:a_P[0]=a_A[0];a_P[1]=a_A[1];a_1703(a_F1,a_F2,a_L5,a_L6,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
a_G22:if(!__equal(1454738956,a_1062)){ goto a_G25;}
a_1077();
a_P[0]=a_A[0];a_P[1]=a_A[1];a_1703(a_F1,a_F2,483807550,16777629,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
a_G25:a_1707(a_P);a_L5=a_P[0];
if(!__equal(1454738938,a_1062)){ goto a_G29;}
a_1077();
a_G28:a_P[0]=a_A[0];a_P[1]=a_A[1];a_1703(a_F1,a_F2,a_L5,16777617,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
a_G29:if(__equal(1454738995,a_1062)){ goto a_G28;}
a_P[0]=a_A[1];a_1722(a_F1,a_P);a_A[1]=a_P[0];
a_P[0]=a_A[0];a_P[1]=a_A[1];a_1705(a_F1,a_F2,a_L5,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
} /* formalaffix */
static void a_1693(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* checkruletype+>a+>a+>a+a> */
int a_L5;int a_P[4];
a_A[0]=0;
a_1058(a_F2,a_P);a_L5=a_P[0];
if(!__equal(a_L5,16777520)){ goto a_G7;}
a_1267(a_F2,16777580);
a_1449(a_F2,a_F1);
a_1248(a_F2,a_F3);return;
a_G7:if(!__equal(a_L5,16777580)){ goto a_G13;}
a_1317(a_F2,1792,a_P);a_L5=a_P[0];
if(__equal(a_L5,a_F1)){return;}
a_1198(a_F2,a_P);a_F3=a_P[0];
a_P[0]=2093834300;a_P[1]=a_F2;a_P[2]=a_F3;a_1040(-1,3,a_P);
a_G12:a_A[0]=1;return;
a_G13:a_1198(a_F2,a_P);a_F3=a_P[0];
a_P[0]=2093834392;a_P[1]=a_F2;a_P[2]=a_L5;a_P[3]=a_F3;a_1040(-1,4,a_P); goto a_G12;
} /* checkruletype */
static void a_1690(int a_F1,int a_F2,int a_A[1]){ /* checkformalaffixes+>a+>a+a> */
int a_L4;int a_L5;int a_P[3];
a_A[0]=0;
a_1713=0;
a_1198(a_F2,a_P);a_L5=a_P[0];
a_1050(a_F2,a_P);a_L4=a_P[0];
a_G5:if(__is(a_A[0])){ goto a_G13;}
if(!__equal(1454738980,a_1062)){ goto a_G13;}
a_1077();
if(!__equal(a_L4,0)){ goto a_G11;}
a_P[0]=2093834403;a_P[1]=a_F2;a_P[2]=a_L5;a_1040(-1,3,a_P);
a_A[0]=1; goto a_G13;
a_G11:a_P[0]=a_L4;a_P[1]=a_A[0];a_1702(a_F2,a_F1,a_P);a_L4=a_P[0];a_A[0]=a_P[1];
a_1050(a_L4,a_P);a_L4=a_P[0]; goto a_G5;
a_G13:if(!__is(a_A[0])){ goto a_G15;}
a_1268();return;
a_G15:if(__equal(a_L4,0)){return;}
a_P[0]=2093834415;a_P[1]=a_F2;a_P[2]=a_L5;a_1040(-1,3,a_P);
a_A[0]=1;return;
} /* checkformalaffixes */
static void a_1692(int a_F1,int a_F2){ /* checkoutaffixes+>a+>a */
int a_L3;int a_P[2];
a_1317(a_F1,1792,a_P);a_L3=a_P[0];
if(!__equal(a_L3,0)){ goto a_G5;}
if(!__equal(a_F2,0)){ goto a_G5;}
a_P[0]=2093834450;a_P[1]=a_F1;a_1041(5,-1,2,a_P);return;
a_G5:if(!__equal(a_L3,1024)){return;}
if(!__noteq(a_F2,0)){return;}
a_P[0]=2093834461;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* checkoutaffixes */
static void a_1695(int a_F1,int a_F2,int a_A[1]){ /* createformalaffixes+>a+>a+a> */
int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[2];
a_A[0]=0;a_L7=0;a_L8=0;
a_1713=0;
a_L4=a_F2;
a_G4:if(__is(a_A[0])){ goto a_G28;}
if(!__equal(1454738980,a_1062)){ goto a_G23;}
a_1077();
a_L5=0;
a_P[0]=a_L5;a_P[1]=a_A[0];a_1702(a_F2,a_F1,a_P);a_L5=a_P[0];a_A[0]=a_P[1];
if(__is(a_A[0])){ goto a_G28;}
a_1058(a_L5,a_P);a_L6=a_P[0];
{ if(a_L6==16777629){ goto a_G12;}
 if(a_L6==16777617){ goto a_G17;}
 if(a_L6==16777623){  goto a_G20;}
  goto a_G21;}
a_G12:if(!__is(a_L7)){ goto a_G15;}
a_A[0]=1;
a_P[0]=2093834426;a_P[1]=a_F2;a_1040(-1,2,a_P); goto a_G21;
a_G15:a_L7=1;
a_1449(a_F2,32768); goto a_G21;
a_G17:a_L8=1;
if(!__is(a_L7)){ goto a_G21;}
a_1449(a_F2,65536); goto a_G21;
a_G20:a_L8=1;
a_G21:a_1442(a_L4,a_L5);
a_L4=a_L5; goto a_G4;
a_G23:if(__equal(a_L7,0)){ goto a_G28;}
a_1058(a_L4,a_P);a_L9=a_P[0];
if(!__equal(a_L9,16777629)){ goto a_G28;}
a_A[0]=1;
a_P[0]=2093834438;a_P[1]=a_F2;a_1040(-1,2,a_P);
a_G28:if(!__is(a_A[0])){ goto a_G31;}
a_1442(a_F2,0);
a_1268();return;
a_G31:a_1449(a_F2,16384);
a_1692(a_F2,a_L8);return;
} /* createformalaffixes */
static void a_1718(int a_F1,int a_F2){ /* ruleexternaldeclarer+>a+>a */
int a_L3;int a_L4;int a_P[2];
if(!__equal(1454738995,a_1062)){ goto a_G3;}
a_1077(); goto a_G4;
a_G3:a_1263(1454738932);
a_G4:a_L4=0;
if(a_1260(a_P)){a_L3=a_P[0]; goto a_G9;}
a_L3=0;
a_L4=1;
a_P[0]=2093834472;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_G9:a_P[0]=a_L4;a_1246(a_F1,a_F2,a_P);a_L4=a_P[0];
if(__is(a_L4)){return;}
a_1266(a_F1,a_L3);return;
} /* ruleexternaldeclarer */
static void a_1719(int a_F1,int a_F2){ /* ruleprototype+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_L4=0;
a_1114(3429890,a_P);a_L3=a_P[0];
if(!__equal(a_L3,1)){ goto a_G5;}
a_P[0]=a_L4;a_1247(a_F1,a_F2,a_P);return;
a_G5:if(!__equal(a_L3,2)){ goto a_G7;}
a_P[0]=a_L4;a_1249(a_F1,a_F2,a_P);return;
a_G7:a_1248(a_F1,a_F2);return;
} /* ruleprototype */
static void a_1716(int a_F1,int a_F2,int a_F3){ /* ruledefinition+>a+>a+>a */
int a_L4;int a_P[1];
if(!a_1205(a_F1,16384)){ goto a_G3;}
a_1690(1,a_F1,a_P);a_L4=a_P[0]; goto a_G4;
a_G3:a_1695(1,a_F1,a_P);a_L4=a_P[0];
a_G4:if(!__is(a_L4)){ goto a_G6;}
a_1268();return;
a_G6:if(!__is(a_F2)){ goto a_G8;}
a_1718(a_F1,a_F3);return;
a_G8:a_1719(a_F1,a_F3);return;
} /* ruledefinition */
static void a_1717(int a_F1,int a_F2){ /* ruledefinitionsequence+>a+>a */
int a_L3;int a_L4;int a_L5;int a_P[2];
a_G1:if(!__equal(1454738968,a_1062)){ goto a_G11;}
a_1077();
if(!a_1262(a_P)){ goto a_G9;}a_L3=a_P[0];a_L5=a_P[1];
a_1693(a_F1,a_L3,a_L5,a_P);a_L4=a_P[0];
a_P[1]=a_L4;a_1709(a_L3,a_P);a_L4=a_P[1];
if(!__is(a_L4)){ goto a_G8;}
a_G7:a_1268(); goto a_G1;
a_G8:a_1716(a_L3,a_F2,a_L5); goto a_G1;
a_G9:a_P[0]=2093834289;a_1040(-1,1,a_P); goto a_G7;
a_G11:if(!__equal(1454738974,a_1062)){ goto a_G13;}
a_1077();return;
a_G13:a_1263(1454738974);
a_1269();return;
} /* ruledefinitionsequence */
static void a_1715(int a_F1,int a_F2){ /* ruledeclarer+>a+>a */
int a_L3;int a_P[1];
if(!a_1205(a_F1,16384)){ goto a_G3;}
a_1690(0,a_F1,a_P);a_L3=a_P[0]; goto a_G4;
a_G3:a_1695(0,a_F1,a_P);a_L3=a_P[0];
a_G4:a_P[0]=a_L3;a_1245(a_F1,a_F2,a_P);a_L3=a_P[0];
if(!__is(a_L3)){ goto a_G7;}
a_1269();return;
a_G7:a_1669(a_F1,a_1713);return;
} /* ruledeclarer */
static void a_1589(int a_F1,int a_F2){ /* ruledeclaration+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
if(!a_1261(a_P)){ goto a_G13;}a_L3=a_P[0];
a_1314(a_P);a_L6=a_P[0];
a_1693(a_F1,a_L3,a_L6,a_P);a_L4=a_P[0];
a_P[1]=a_L4;a_1709(a_L3,a_P);a_L5=a_P[0];a_L4=a_P[1];
if(!__is(a_L4)){ goto a_G7;}
a_1269();return;
a_G7:if(__is(a_F2)){ goto a_G9;}
if(!__is(a_L5)){ goto a_G11;}
a_G9:a_1716(a_L3,a_F2,a_L6);
a_1717(a_F1,a_F2);return;
a_G11:a_1715(a_L3,a_L6);
a_1714();return;
a_G13:a_P[0]=2093834289;a_1040(-1,1,a_P);
a_1269();return;
} /* ruledeclaration */
static void a_1686(void){ /* @root */

} /* @root */
static void a_1431(void){ /* initrestore */

if(!__is(a_1727)){ goto a_G3;}
a_1063(a_1001,16777501,153);return;
a_G3:a_1732=a_1733;
a_1730=a_1062;
a_1731=a_1729;
a_1727=1;return;
} /* initrestore */
static void a_1437(void){ /* makerestore */
int a_P[2];
if(!__equal(a_1727,0)){ goto a_G3;}
a_1063(a_1001,16777496,158);return;
a_G3:if(!__more(a_1735,500)){ goto a_G7;}
a_P[0]=2093834506;a_P[1]=500;a_1040(-1,2,a_P);
a_1046();
exit(3);return;
a_G7:a_1733=a_1732;
a_1062=a_1730;
a_1729=a_1731;
a_1727=0;return;
} /* makerestore */
static void a_1427(void){ /* forgetrestore */

a_1437();
a_G2:if(!a_1734()){return;}
a_1737(); goto a_G2;
} /* forgetrestore */
static void a_1736(void){ /* savetorestore */
int a_P[1];
if(__equal(a_1727,0)){return;}
if(!__noteq(a_1733,a_1728)){ goto a_G4;}
a_1063(a_1001,16777491,171);return;
a_G4:__incr(a_1735);
a_P[0]=a_1728;a_1726(a_P);a_1728=a_P[0];
a_1733=a_1728;
to_LIST(a_1724)->offset[a_1728]=a_1062;return;
} /* savetorestore */
static int a_1734(void){ /* readfromrestore */
int a_P[1];
if(__equal(a_1728,a_1733)){ return 0;}
a_P[0]=a_1733;a_1726(a_P);a_1733=a_P[0];
a_1062=to_LIST(a_1724)->offset[a_1733];
if(__is(a_1727)){ goto a_G6;}
__decr(a_1735);
a_G6:if(__mreq(a_1735,0)){ return 1;}
a_1063(a_1001,16777485,179); return 1;
} /* readfromrestore */
static void a_1726(int a_A[1]){ /* countrestore+>a> */

if(!__mreq(a_A[0],to_LIST(a_1724)->aupb)){ goto a_G3;}
a_A[0]=to_LIST(a_1724)->alwb;return;
a_G3:__incr(a_A[0]);return;
} /* countrestore */
static void a_1737(void){ /* setsymbolposition */

if(!__equal(a_1062,1454739013)){return;}
__incr(a_1729);
if(__is(a_1727)){return;}
a_1012(2106125282);return;
} /* setsymbolposition */
static void a_1077(void){ /* nextsymbol */
int a_P[1];
a_G1:if(a_1734()){ goto a_G4;}
a_1397(a_P);a_1062=a_P[0];
a_1736();
a_G4:a_1737();
if(!__equal(a_1062,1454739013)){return;} goto a_G1;
} /* nextsymbol */
static void a_1421(int a_F1){ /* Rskip+>a */

if(!__equal(a_F1,a_1062)){ goto a_G3;}
a_1077();return;
a_G3:if(!__was(a_1020,a_F1)){return;}
if(!__equal(a_1062,to_LIST(a_1020)->offset[a_F1])){return;}
a_1077();return;
} /* Rskip */
static void a_1263(int a_F1){ /* must+>a */
int a_P[2];
if(!__equal(a_F1,a_1062)){ goto a_G3;}
a_1077();return;
a_G3:a_P[0]=2093834480;a_P[1]=a_F1;a_1040(-1,2,a_P);return;
} /* must */
static int a_1584(int a_A[1]){ /* israwtag+a> */

if(!__was(a_1039,a_1062)){ return 0;}
a_A[0]=a_1062;
a_1077(); return 1;
} /* israwtag */
static int a_1432(int a_A[1]){ /* iscons+a> */

if(!__was(a_1011,a_1062)){ return 0;}
a_A[0]=to_LIST(a_1011)->offset[a_1062];
a_1077(); return 1;
} /* iscons */
static int a_1725(void){ /* aheadcons */

if(!__was(a_1011,a_1062)){ return 0;} return 1;
} /* aheadcons */
static int a_1260(int a_A[1]){ /* isstring+a> */

if(!__was(a_1021,a_1062)){ return 0;}
a_A[0]=a_1062;
a_1077(); return 1;
} /* isstring */
static int a_1262(int a_A[2]){ /* istagdl+a>+a> */
int a_P[1];
if(!__was(a_1039,a_1062)){ return 0;}
if(!__equal(a_1728,a_1733)){ goto a_G4;}
a_1602(a_1062,a_1729);
a_G4:a_A[1]=a_1729;
a_1583(a_1062,a_P);a_A[0]=a_P[0];
a_1077(); return 1;
} /* istagdl */
static int a_1261(int a_A[1]){ /* istag+a> */
int a_P[1];
if(!__was(a_1039,a_1062)){ return 0;}
if(!__equal(a_1728,a_1733)){ goto a_G4;}
a_1602(a_1062,a_1729);
a_G4:a_1583(a_1062,a_P);a_A[0]=a_P[0];
a_1077(); return 1;
} /* istag */
static void a_1738(void){ /* skipsymbol */
int a_P[1];
a_G1:if(a_1734()){ goto a_G4;}
a_1412(a_P);a_1062=a_P[0];
a_1736();
a_G4:a_1737();
if(!__equal(a_1062,1454739013)){return;} goto a_G1;
} /* skipsymbol */
static void a_1590(void){ /* skipsilently */

a_G1:if(__equal(1454738974,a_1062)){return;}
if(__equal(1454738855,a_1062)){return;}
a_1738(); goto a_G1;
} /* skipsilently */
static void a_1268(void){ /* skipall */
int a_P[1];
if(__equal(1454738974,a_1062)){return;}
a_P[0]=2093834493;a_1117(1,a_P);
a_1590();return;
} /* skipall */
static void a_1269(void){ /* skiptopoint */

a_1268();
a_1421(1454738974);return;
} /* skiptopoint */
static void a_1314(int a_A[1]){ /* getlinenum+a> */

a_A[0]=a_1729;return;
} /* getlinenum */
static void a_1088(int a_F1){ /* setlinenum+>a */

a_1729=a_F1;return;
} /* setlinenum */
static void a_1345(void){ /* advancelinenum */

__incr(a_1729);
a_1012(2106125282);return;
} /* advancelinenum */
static void a_1723(void){ /* @root */

} /* @root */
static int a_1151(int a_F1,int a_F2){ /* wastagpointer+>a+[]st[] */

a_G1:if(!__was(a_1039,a_F1)){ goto a_G4;}
__previous(a_1039,a_F1);
a_copystring(a_1039,a_F1,a_F2); return 1;
a_G4:if(!__was(a_1020,a_F1)){ goto a_G6;}
a_F1=to_LIST(a_1020)->offset[a_F1]; goto a_G1;
a_G6:if(!__was(a_1022,a_F1)){ return 0;}
a_F1=to_LIST(a_1022)->offset[a_F1]; goto a_G1;
} /* wastagpointer */
static void a_1316(int a_F1,int a_A[1]){ /* gettag+>a+a> */

a_A[0]=to_LIST(a_1020)->offset[a_F1];return;
} /* gettag */
static void a_1056(int a_F1,int a_A[1]){ /* getrepr+>a+a> */

a_A[0]=to_LIST(a_1020)->offset[a_F1-2];return;
} /* getrepr */
static void a_1050(int a_F1,int a_A[1]){ /* getadm+>a+a> */

a_A[0]=to_LIST(a_1020)->offset[a_F1-1];return;
} /* getadm */
static void a_1058(int a_F1,int a_A[1]){ /* gettype+>a+a> */

{ if(!((483807545<=a_F1 && a_F1<=963127684))){ goto a_G3;}
}
a_A[0]=to_LIST(a_1020)->offset[a_F1-3];return;
a_G3:a_A[0]=to_LIST(a_1022)->offset[a_F1-2];return;
} /* gettype */
static void a_1198(int a_F1,int a_A[1]){ /* getdefline+>a+a> */

a_A[0]=to_LIST(a_1020)->offset[a_F1-5];return;
} /* getdefline */
static void a_1197(int a_F1,int a_A[1]){ /* getcalibre+>a+a> */

a_A[0]=to_LIST(a_1020)->offset[to_LIST(a_1020)->offset[a_F1-1]-1];return;
} /* getcalibre */
static void a_1057(int a_F1,int a_A[1]){ /* getssel+>a+a> */

a_A[0]=to_LIST(a_1020)->offset[to_LIST(a_1020)->offset[a_F1-1]];return;
} /* getssel */
static void a_1054(int a_F1,int a_A[1]){ /* getformalcalibre+>a+a> */

a_A[0]=to_LIST(a_1020)->offset[a_F1-5];return;
} /* getformalcalibre */
static void a_1055(int a_F1,int a_A[1]){ /* getformalssel+>a+a> */

a_A[0]=to_LIST(a_1020)->offset[a_F1-4];return;
} /* getformalssel */
static void a_1266(int a_F1,int a_F2){ /* putrepr+>a+>a */

to_LIST(a_1020)->offset[a_F1-2]=a_F2;return;
} /* putrepr */
static void a_1442(int a_F1,int a_F2){ /* putadm+>a+>a */

to_LIST(a_1020)->offset[a_F1-1]=a_F2;return;
} /* putadm */
static void a_1267(int a_F1,int a_F2){ /* puttype+>a+>a */

to_LIST(a_1020)->offset[a_F1-3]=a_F2;return;
} /* puttype */
static void a_1444(int a_F1,int a_F2){ /* putdefline+>a+>a */

to_LIST(a_1020)->offset[a_F1-5]=a_F2;return;
} /* putdefline */
static void a_1443(int a_F1,int a_F2){ /* putcalibre+>a+>a */

to_LIST(a_1020)->offset[to_LIST(a_1020)->offset[a_F1-1]-1]=a_F2;return;
} /* putcalibre */
static void a_1445(int a_F1,int a_F2){ /* putssel+>a+>a */

to_LIST(a_1020)->offset[to_LIST(a_1020)->offset[a_F1-1]]=a_F2;return;
} /* putssel */
static void a_1710(int a_F1,int a_F2){ /* putformalcalibre+>a+>a */

to_LIST(a_1020)->offset[a_F1-5]=a_F2;return;
} /* putformalcalibre */
static void a_1711(int a_F1,int a_F2){ /* putformalssel+>a+>a */

to_LIST(a_1020)->offset[a_F1-4]=a_F2;return;
} /* putformalssel */
static void a_1449(int a_F1,int a_F2){ /* settagflag+>a+>a */

__boolor(to_LIST(a_1020)->offset[a_F1-4],a_F2,to_LIST(a_1020)->offset[a_F1-4]);return;
} /* settagflag */
static int a_1205(int a_F1,int a_F2){ /* istagflag+>a+>a */
int a_L3;
__booland(to_LIST(a_1020)->offset[a_F1-4],a_F2,a_L3);
if(!__noteq(a_L3,0)){ return 0;} return 1;
} /* istagflag */
static void a_1317(int a_F1,int a_F2,int a_A[1]){ /* gettagflag+>a+>a+a> */

__booland(to_LIST(a_1020)->offset[a_F1-4],a_F2,a_A[0]);return;
} /* gettagflag */
static void a_1294(int a_F1,int a_F2){ /* cleartagflag+>a+>a */
int a_L3;
__boolinvert(a_F2,a_L3);
__booland(to_LIST(a_1020)->offset[a_F1-4],a_L3,to_LIST(a_1020)->offset[a_F1-4]);return;
} /* cleartagflag */
static void a_1271(int a_F1){ /* usetag+>a */

if(__mreq(to_LIST(a_1020)->offset[a_F1-3],16777584)){return;}
__boolor(to_LIST(a_1020)->offset[a_F1-4],1,to_LIST(a_1020)->offset[a_F1-4]);return;
} /* usetag */
static void a_1378(int a_F1,int a_A[1]){ /* entertag+t[]+a> */
int a_L2;int a_L3;int a_P[1];
__listlength(a_F1,a_L2);
a_packstring(a_F1,a_L2,a_1039);
a_L3=963127974;
a_G4:__add(a_L3,5,a_A[0]);
a_comparestring(a_1039,a_L3,a_1039,to_LIST(a_1039)->aupb,a_P);a_L2=a_P[0];
if(!__equal(a_L2,0)){ goto a_G8;}
__unstackstring(a_1039);return;
a_G8:if(!__more(a_L2,0)){ goto a_G14;}
a_L3=to_LIST(a_1039)->offset[a_A[0]-4];
if(__more(a_L3,0)){ goto a_G4;}
to_LIST(a_1039)->offset[a_A[0]-4]=to_LIST(a_1039)->aupb;
 a_extension(a_1039,5);to_LIST(a_1039)->top[4]=-1;to_LIST(a_1039)->top[1]=to_LIST(a_1039)->top[2]=to_LIST(a_1039)->top[3]=to_LIST(a_1039)->top[5]=0;to_LIST(a_1039)->aupb+=5;
a_G13:a_A[0]=to_LIST(a_1039)->aupb;return;
a_G14:a_L3=to_LIST(a_1039)->offset[a_A[0]-3];
if(__more(a_L3,0)){ goto a_G4;}
to_LIST(a_1039)->offset[a_A[0]-3]=to_LIST(a_1039)->aupb;
 a_extension(a_1039,5);to_LIST(a_1039)->top[4]=-1;to_LIST(a_1039)->top[1]=to_LIST(a_1039)->top[2]=to_LIST(a_1039)->top[3]=to_LIST(a_1039)->top[5]=0;to_LIST(a_1039)->aupb+=5;
  goto a_G13;
} /* entertag */
static void a_1440(int a_F1,int a_F2,int a_A[1]){ /* packselector+>a+>a+a> */
int a_P[1];
__scratch(a_1006);
a_1316(a_F1,a_P);a_F1=a_P[0];
a_1316(a_F2,a_P);a_F2=a_P[0];
__previous(a_1039,a_F1);
__previous(a_1039,a_F2);
a_unpackstring(a_1039,a_F1,a_1006);
a_1748(42);
a_unpackstring(a_1039,a_F2,a_1006);
a_1378(a_1006,a_P);a_A[0]=a_P[0];
a_1583(a_A[0],a_P);a_A[0]=a_P[0];return;
} /* packselector */
static void a_1746(int a_F1){ /* enterpredefinedtag+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
if(__equal(a_F1,963127974)){return;}
if(!__lseq(963128096,a_F1)){ goto a_G4;}
if(__lseq(a_F1,963128152)){return;}
a_G4:a_L4=963127974;
a_G5:__add(a_L4,5,a_L3);
a_comparestring(a_1039,a_L4,a_1039,a_F1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,0)){ goto a_G11;}
__next(a_1039,a_F1);
a_P[0]=2093834519;a_P[1]=a_F1;a_1040(0,2,a_P);
a_1063(a_1001,16777514,338);return;
a_G11:if(!__more(a_L2,0)){ goto a_G15;}
a_L4=to_LIST(a_1039)->offset[a_L3-4];
if(__more(a_L4,0)){ goto a_G5;}
to_LIST(a_1039)->offset[a_L3-4]=a_F1;return;
a_G15:a_L4=to_LIST(a_1039)->offset[a_L3-3];
if(__more(a_L4,0)){ goto a_G5;}
to_LIST(a_1039)->offset[a_L3-3]=a_F1;return;
} /* enterpredefinedtag */
static void a_1744(int a_F1,int a_F2){ /* addspecialrule+>a+>a */
int a_L3;int a_P[1];
a_1755(a_F2,a_P);a_L3=a_P[0];
to_LIST(a_1039)->offset[a_F1-2]=a_L3;to_LIST(a_1039)->offset[a_F2-2]=a_L3;return;
} /* addspecialrule */
static void a_1752(void){ /* inittags */
int a_L1;int a_L2;
a_L1=to_LIST(a_1039)->aupb;
a_G2:if(__lseq(a_L1,to_LIST(a_1039)->alwb)){ goto a_G7;}
__previous(a_1039,a_L1);
a_1746(a_L1);
__stringwidth(a_1039,a_L1,a_L2);
__subtr(a_L1,a_L2,a_L1); goto a_G2;
a_G7:to_LIST(a_1039)->offset[963128019-2]=483807586;
to_LIST(a_1039)->offset[963127990-2]=483807568;
to_LIST(a_1039)->offset[963128001-2]=483807574;
to_LIST(a_1039)->offset[963128010-2]=483807562;
to_LIST(a_1039)->offset[963128030-2]=483807556;
to_LIST(a_1039)->offset[963128039-2]=483807580;to_LIST(a_1039)->offset[963128109-2]=483807580;
a_1744(963128048,963128117);
a_1744(963128057,963128125);
a_1744(963128066,963128133);
a_1744(963128075,963128141);
a_1744(963128084,963128149);
a_1744(963128093,963128157);
a_1751();
a_1750();return;
} /* inittags */
static void a_1264(int a_F1,int a_A[1]){ /* newstdstring+>a+a> */
int a_P[1];
if(!__equal(a_F1,1516190318)){ goto a_G4;}
if(!__is(a_1761)){ goto a_G4;}
a_A[0]=a_1761;return;
a_G4:a_1755(963128101,a_P);a_A[0]=a_P[0];
a_1267(a_A[0],16777566);
a_1442(a_A[0],483807556);
a_1271(483807556);
a_1449(483807556,256);
a_1449(483807556,8);
a_1449(a_A[0],2);
a_1449(a_A[0],1);
 a_extension(a_1020,3);to_LIST(a_1020)->top[2]=a_A[0];to_LIST(a_1020)->top[1]=a_F1;to_LIST(a_1020)->top[3]=a_1762;to_LIST(a_1020)->aupb+=3;
a_1762=to_LIST(a_1020)->aupb;
if(!__equal(a_F1,1516190318)){return;}
a_1761=a_A[0];return;
} /* newstdstring */
static void a_1751(void){ /* initstdstringtable */

to_LIST(a_1039)->offset[963128030-2]=483807556;
a_1438(483807556,16777544);return;
} /* initstdstringtable */
static void a_1750(void){ /* initrules */
int a_L1;int a_L2;int a_P[1];
to_LIST(a_1039)->offset[963127990-2]=483807568;
a_1267(483807568,16777580);
a_1449(483807568,180778);
a_1708(16777635,483807550,a_P);a_L1=a_P[0];
a_1442(483807568,a_L1);
to_LIST(a_1039)->offset[963128001-2]=483807574;
a_1267(483807574,16777580);
a_1449(483807574,180266);
a_1708(16777617,483807550,a_P);a_L1=a_P[0];
a_1442(483807574,a_L1);
a_1708(16777635,483807550,a_P);a_L2=a_P[0];
a_1442(a_L1,a_L2);
to_LIST(a_1039)->offset[963128010-2]=483807562;
a_1267(483807562,16777580);
a_1449(483807562,17443);return;
} /* initrules */
static void a_1259(int a_F1,int a_A[1]){ /* gettaghash+>a+a> */
int a_P[1];
a_1316(a_F1,a_P);a_F1=a_P[0];
__previous(a_1039,a_F1);
a_simplehash(a_1039,a_F1,a_P);a_A[0]=a_P[0];return;
} /* gettaghash */
static void a_1755(int a_F1,int a_A[1]){ /* newtagentry+>a+a> */

 a_extension(a_1020,6);to_LIST(a_1020)->top[1]=-1;to_LIST(a_1020)->top[3]=16777520;to_LIST(a_1020)->top[2]=to_LIST(a_1020)->top[4]=to_LIST(a_1020)->top[5]=0;to_LIST(a_1020)->top[6]=a_F1;to_LIST(a_1020)->aupb+=6;
a_A[0]=to_LIST(a_1020)->aupb;return;
} /* newtagentry */
static void a_1583(int a_F1,int a_A[1]){ /* gettagentry+>a+a> */
int a_P[1];
a_A[0]=to_LIST(a_1039)->offset[a_F1-2];
if(!__equal(a_A[0],0)){return;}
a_1755(a_F1,a_P);a_A[0]=a_P[0];
to_LIST(a_1039)->offset[a_F1-2]=a_A[0];return;
} /* gettagentry */
static void a_1708(int a_F1,int a_F2,int a_A[1]){ /* newformaltag+>a+>a+a> */

{ if(!(a_F1==16777602||a_F1==16777596)){ goto a_G3;}
}
 a_extension(a_1020,6);to_LIST(a_1020)->top[1]=to_LIST(a_1020)->top[2]=0;to_LIST(a_1020)->top[3]=a_F1;to_LIST(a_1020)->top[4]=to_LIST(a_1020)->top[5]=0;to_LIST(a_1020)->top[6]=to_LIST(a_1020)->offset[a_F2];to_LIST(a_1020)->aupb+=6;
  goto a_G4;
a_G3: a_extension(a_1020,4);to_LIST(a_1020)->top[1]=a_F1;to_LIST(a_1020)->top[2]=to_LIST(a_1020)->top[3]=0;to_LIST(a_1020)->top[4]=to_LIST(a_1020)->offset[a_F2];to_LIST(a_1020)->aupb+=4;
a_G4:a_A[0]=to_LIST(a_1020)->aupb;return;
} /* newformaltag */
static void a_1438(int a_F1,int a_F2){ /* newlistentry+>a+>a */

a_1267(a_F1,a_F2);
 a_extension(a_1020,2);to_LIST(a_1020)->top[2]=to_LIST(a_1020)->top[1]=0;to_LIST(a_1020)->aupb+=2;
a_1442(a_F1,to_LIST(a_1020)->aupb);return;
} /* newlistentry */
static void a_1582(int a_F1,int a_A[1]){ /* findrawusage+>a+a> */

if(!__equal(a_F1,0)){ goto a_G3;}
a_G2:a_A[0]=0;return;
a_G3:a_F1=to_LIST(a_1039)->offset[a_F1-2];
if(__equal(a_F1,0)){ goto a_G2;}
if(!a_1205(a_F1,2)){ goto a_G8;}
a_A[0]=2;return;
a_G8:if(!a_1205(a_F1,1)){ goto a_G2;}
a_A[0]=1;return;
} /* findrawusage */
static void a_1245(int a_F1,int a_F2,int a_A[1]){ /* addtagdefinition+>a+>a+>a> */
int a_P[3];
if(__is(a_A[0])){return;}
if(!a_1205(a_F1,32)){ goto a_G5;}
a_P[0]=2093834580;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_G4:a_A[0]=1;return;
a_G5:if(!a_1205(a_F1,16)){ goto a_G8;}
a_P[0]=2093834540;a_P[1]=a_F1;a_P[2]=to_LIST(a_1020)->offset[a_F1-5];a_1040(-1,3,a_P); goto a_G4;
a_G8:if(!a_1205(a_F1,2)){ goto a_G11;}
a_P[0]=2093834527;a_P[1]=a_F1;a_P[2]=to_LIST(a_1020)->offset[a_F1-5];a_1040(-1,3,a_P); goto a_G4;
a_G11:if(__lseq(a_F2,1)){ goto a_G13;}
a_1444(a_F1,a_F2);
a_G13:a_1449(a_F1,2);return;
} /* addtagdefinition */
static void a_1246(int a_F1,int a_F2,int a_A[1]){ /* addtagexternal+>a+>a+>a> */
int a_P[3];
if(a_1205(a_F1,16)){ goto a_G3;}
a_P[0]=a_A[0];a_1245(a_F1,a_F2,a_P);a_A[0]=a_P[0];
a_G3:if(!a_1205(a_F1,4)){ goto a_G6;}
a_P[0]=2093834572;a_P[1]=a_F1;a_P[2]=to_LIST(a_1020)->offset[a_F1-5];a_1040(-1,3,a_P);
a_A[0]=1;
a_G6:if(__is(a_A[0])){return;}
a_1449(a_F1,16);return;
} /* addtagexternal */
static void a_1247(int a_F1,int a_F2,int a_A[1]){ /* addtagimport+>a+>a+>a> */
int a_P[3];
if(a_1205(a_F1,8)){return;}
if(!a_1205(a_F1,4)){ goto a_G5;}
a_P[0]=2093834552;a_P[1]=a_F1;a_P[2]=to_LIST(a_1020)->offset[a_F1-5];a_1040(-1,3,a_P);
a_A[0]=1;return;
a_G5:a_P[0]=a_A[0];a_1245(a_F1,a_F2,a_P);a_A[0]=a_P[0];
if(__is(a_A[0])){return;}
a_1449(a_F1,8);return;
} /* addtagimport */
static void a_1249(int a_F1,int a_F2,int a_A[1]){ /* addtagpublic+>a+>a+>a> */
int a_P[3];
if(__is(a_A[0])){return;}
if(!a_1205(a_F1,32)){ goto a_G5;}
a_P[0]=2093834560;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_G4:a_A[0]=1;return;
a_G5:if(!a_1205(a_F1,16)){ goto a_G8;}
a_G6:a_P[0]=2093834552;a_P[1]=a_F1;a_P[2]=to_LIST(a_1020)->offset[a_F1-5];a_1040(-1,3,a_P); goto a_G4;
a_G8:if(a_1205(a_F1,8)){ goto a_G6;}
a_1449(a_F1,4);
a_1271(a_F1);
a_1248(a_F1,a_F2);return;
} /* addtagpublic */
static void a_1248(int a_F1,int a_F2){ /* addtagprototype+>a+>a */

if(__more(to_LIST(a_1020)->offset[a_F1-5],0)){return;}
if(__lseq(a_F2,1)){return;}
a_1444(a_F1,a_F2);return;
} /* addtagprototype */
static void a_1712(int a_F1,int a_F2){ /* redefinetag+>a+>a */
int a_L3;
a_L3=to_LIST(a_1020)->offset[a_F1];
to_LIST(a_1020)->offset[a_F2]=a_L3;
 a_extension(a_1742,2);to_LIST(a_1742)->top[2]=a_F1;to_LIST(a_1742)->top[1]=a_L3;to_LIST(a_1742)->aupb+=2;
to_LIST(a_1039)->offset[a_L3-2]=a_F2;return;
} /* redefinetag */
static void a_1714(void){ /* restoretags */

a_G1:if(__less(to_LIST(a_1742)->aupb,to_LIST(a_1742)->alwb)){return;}
to_LIST(a_1039)->offset[to_LIST(a_1742)->offset[to_LIST(a_1742)->aupb-1]-2]=to_LIST(a_1742)->offset[to_LIST(a_1742)->aupb];
__unstack(a_1742); goto a_G1;
} /* restoretags */
static int a_1661(int a_F1,int a_A[1]){ /* isspecialrule+>a+a> */

if(!__equal(a_F1,1454738929)){ goto a_G3;}
a_A[0]=to_LIST(a_1039)->offset[963128039-2]; return 1;
a_G3:if(!__equal(a_F1,1454738932)){ goto a_G5;}
a_A[0]=to_LIST(a_1039)->offset[963128057-2]; return 1;
a_G5:if(!__equal(a_F1,1454738938)){ goto a_G7;}
a_A[0]=to_LIST(a_1039)->offset[963128075-2]; return 1;
a_G7:if(!__equal(a_F1,1454738935)){ goto a_G9;}
a_A[0]=to_LIST(a_1039)->offset[963128084-2]; return 1;
a_G9:if(!__equal(a_F1,1454738989)){ goto a_G11;}
a_A[0]=to_LIST(a_1039)->offset[963128066-2]; return 1;
a_G11:if(!__equal(a_F1,1454738998)){ goto a_G13;}
a_A[0]=to_LIST(a_1039)->offset[963128093-2]; return 1;
a_G13:if(!__equal(a_F1,1454738995)){ return 0;}
a_A[0]=to_LIST(a_1039)->offset[963128048-2]; return 1;
} /* isspecialrule */
static void a_1749(int a_F1){ /* extendDICT+>a */

 a_extension(a_1740,1);to_LIST(a_1740)->top[1]=a_F1;to_LIST(a_1740)->aupb+=1;
 return;
} /* extendDICT */
static void a_1756(int a_F1,int a_F2,int a_A[1]){ /* pack2+>a+>a+a> */

a_A[0]=a_F1;
__leftclear(a_A[0],11);
__boolor(a_A[0],a_F2,a_A[0]);return;
} /* pack2 */
static void a_1763(int a_F1,int a_A[2]){ /* unpack2+>a+a>+a> */

__booland(a_F1,2047,a_A[1]);
a_A[0]=a_F1;
__rightclear(a_A[0],11);return;
} /* unpack2 */
static void a_1747(int a_F1,int a_F2){ /* expandDICT+>a+>a */
int a_L3;int a_P[1];
if(!__equal(a_F1,0)){ goto a_G3;}
a_L3=0; goto a_G5;
a_G3:__subtr(to_LIST(a_1740)->aupb,a_F1,a_L3);
__incr(a_L3);
a_G5:a_1756(a_L3,a_F2,a_P);a_L3=a_P[0];
a_1749(a_L3);return;
} /* expandDICT */
static void a_1743(int a_F1,int a_F2){ /* addlinetoDICT+>a+>a */

a_G1:if(!__less(a_F2,2030)){ goto a_G3;}
a_1747(a_F1,a_F2);return;
a_G3:a_1747(a_F1,2047);
__subtr(a_F2,2000,a_F2);
a_F1=to_LIST(a_1740)->aupb; goto a_G1;
} /* addlinetoDICT */
static void a_1602(int a_F1,int a_F2){ /* addDICT+>a+>a */
int a_L3;
if(!a_1321(3429895)){return;}
a_L3=to_LIST(a_1039)->offset[a_F1-1];
if(!__less(a_L3,0)){ goto a_G6;}
to_LIST(a_1039)->offset[a_F1-1]=a_F2;
to_LIST(a_1039)->offset[a_F1]=0;return;
a_G6:__subtr(a_F2,a_L3,a_L3);
if(__lseq(a_L3,0)){return;}
a_1743(to_LIST(a_1039)->offset[a_F1],a_L3);
to_LIST(a_1039)->offset[a_F1-1]=a_F2;
to_LIST(a_1039)->offset[a_F1]=to_LIST(a_1740)->aupb;return;
} /* addDICT */
static void a_1759(int a_F1){ /* reverseDICT+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
if(__less(to_LIST(a_1039)->offset[a_F1-1],0)){return;}
if(__equal(to_LIST(a_1039)->offset[a_F1],0)){return;}
a_L3=to_LIST(a_1039)->offset[a_F1-1];
a_L2=to_LIST(a_1039)->offset[a_F1];
a_L6=0;
a_G6:a_1763(to_LIST(a_1740)->offset[a_L2],a_P);a_L5=a_P[0];a_L4=a_P[1];
a_1756(a_L6,a_L4,a_P);to_LIST(a_1740)->offset[a_L2]=a_P[0];
{ if((1<=a_L4 && a_L4<=2019)){ goto a_G9;}
 if(a_L4==2047){  goto a_G10;}
  goto a_G11;}
a_G9:__subtr(a_L3,a_L4,a_L3); goto a_G11;
a_G10:__subtr(a_L3,2000,a_L3);
a_G11:if(__equal(a_L5,0)){ goto a_G14;}
a_L6=a_L5;
__subtr(a_L2,a_L5,a_L2); goto a_G6;
a_G14:to_LIST(a_1039)->offset[a_F1]=a_L2;
to_LIST(a_1039)->offset[a_F1-1]=a_L3;return;
} /* reverseDICT */
static int a_1753(int a_F1){ /* isspecialtag+>a */
int a_L2;int a_P[1];
__previous(a_1039,a_F1);
if(!a_stringelem(a_1039,a_F1,0,a_P)){ return 0;}a_L2=a_P[0];
{ if((97<=a_L2 && a_L2<=122)||(65<=a_L2 && a_L2<=90)){  return 0;}
  return 1;}
} /* isspecialtag */
static void a_1741(int a_F1){ /* DICTtag+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
if(__lseq(to_LIST(a_1039)->offset[a_F1-1],0)){return;}
if(a_1753(a_F1)){return;}
a_L5=to_LIST(a_1039)->offset[a_F1-2];
if(!__equal(a_L5,0)){ goto a_G6;}
a_L3=0; goto a_G7;
a_G6:a_1198(a_L5,a_P);a_L3=a_P[0];
a_G7:a_1759(a_F1);
a_L2=to_LIST(a_1039)->offset[a_F1-1];
a_L5=to_LIST(a_1039)->offset[a_F1];
a_1098(a_F1,a_L3);
a_1099(a_L2);
a_G12:if(!__equal(a_L5,0)){ goto a_G14;}
a_G13:a_1101();return;
a_G14:a_1763(to_LIST(a_1740)->offset[a_L5],a_P);a_L4=a_P[0];a_L3=a_P[1];
{ if((1<=a_L3 && a_L3<=2019)){ goto a_G16;}
 if(a_L3==2047){  goto a_G18;}
  goto a_G19;}
a_G16:__add(a_L2,a_L3,a_L2);
a_1099(a_L2); goto a_G19;
a_G18:__add(a_L2,2000,a_L2);
a_G19:if(__equal(a_L4,0)){ goto a_G13;}
__add(a_L5,a_L4,a_L5); goto a_G12;
} /* DICTtag */
static void a_1757(int a_F1){ /* printdict+>a */
int a_L2;
a_G1:if(__equal(a_F1,0)){return;}
__add(a_F1,5,a_L2);
a_1757(to_LIST(a_1039)->offset[a_L2-4]);
a_1741(a_L2);
a_F1=to_LIST(a_1039)->offset[a_L2-3]; goto a_G1;
} /* printdict */
static void a_1461(void){ /* printdictionary */

a_1757(963127974);
a_release(a_1740);return;
} /* printdictionary */
static void a_1745(int a_F1){ /* assigntags+>a */
int a_L2;
a_G1:if(__equal(a_F1,0)){return;}
__add(a_F1,5,a_L2);
a_1745(to_LIST(a_1039)->offset[a_L2-4]);
a_1299(to_LIST(a_1039)->offset[a_L2-2]);
a_F1=to_LIST(a_1039)->offset[a_L2-3]; goto a_G1;
} /* assigntags */
static void a_1285(void){ /* assignitems */
int a_L1;
a_1745(963127974);
a_L1=a_1762;
a_G3:if(__equal(a_L1,0)){return;}
a_1299(to_LIST(a_1020)->offset[a_L1-1]);
a_L1=to_LIST(a_1020)->offset[a_L1]; goto a_G3;
} /* assignitems */
static int a_1280(void){ /* Xstringtablefilling */
int a_L1;
if(!__is(a_1762)){ return 0;}
a_L1=a_1762;
a_1281(483807556);
a_G4:if(__equal(a_L1,0)){ return 1;}
a_1282(to_LIST(a_1020)->offset[a_L1-1],to_LIST(a_1020)->offset[a_L1-2]);
a_L1=to_LIST(a_1020)->offset[a_L1]; goto a_G4;
} /* Xstringtablefilling */
static void a_1600(int a_F1,int a_F2,int a_F3){ /* linkmacrorule+>a+>a+>a */

 a_extension(a_1020,4);to_LIST(a_1020)->top[2]=a_F3;to_LIST(a_1020)->top[1]=a_F2;to_LIST(a_1020)->top[4]=a_F1;to_LIST(a_1020)->top[3]=a_1754;to_LIST(a_1020)->aupb+=4;
a_1754=to_LIST(a_1020)->aupb;return;
} /* linkmacrorule */
static void a_1473(int a_F1,int a_A[2]){ /* searchmacrorule+>a+a>+a> */
int a_L4;int a_P[1];
a_L4=a_1754;
a_G2:if(!__equal(a_L4,0)){ goto a_G4;}
a_1063(a_1001,16777507,584);return;
a_G4:if(!__equal(to_LIST(a_1020)->offset[a_L4],a_F1)){ goto a_G7;}
a_A[0]=to_LIST(a_1020)->offset[a_L4-3];
a_A[1]=to_LIST(a_1020)->offset[a_L4-2];return;
a_G7:a_1050(a_L4,a_P);a_L4=a_P[0]; goto a_G2;
} /* searchmacrorule */
static int a_1471(int a_A[1]){ /* nextmacrorule+>a> */
int a_L2;int a_P[1];
a_L2=a_1754;
if(__equal(a_A[0],0)){ goto a_G7;}
a_G3:if(__equal(a_L2,0)){ goto a_G7;}
if(!__equal(to_LIST(a_1020)->offset[a_L2],a_A[0])){ goto a_G6;}
a_1050(a_L2,a_P);a_L2=a_P[0]; goto a_G7;
a_G6:a_1050(a_L2,a_P);a_L2=a_P[0]; goto a_G3;
a_G7:if(!__is(a_L2)){ return 0;}
a_A[0]=to_LIST(a_1020)->offset[a_L2]; return 1;
} /* nextmacrorule */
static void a_1739(void){ /* @root */

a_1752();return;
} /* @root */
static void a_1748(int a_F1){ /* extendBUFFER+>a */

 a_extension(a_1006,1);to_LIST(a_1006)->top[1]=a_F1;to_LIST(a_1006)->aupb+=1;
 return;
} /* extendBUFFER */
static int a_1152(int a_F1,int a_F2){ /* wastypepointer+>a+[]st[] */

if(!__was(a_1018,a_F1)){ return 0;}
a_copystring(a_1018,a_F1,a_F2); return 1;
} /* wastypepointer */
static int a_1060(int a_F1){ /* hasformaltype+>a */
int a_L2;int a_P[1];
a_1058(a_F1,a_P);a_L2=a_P[0];
if(!__mreq(a_L2,16777584)){ return 0;} return 1;
} /* hasformaltype */
static void a_1764(void){ /* @root */

} /* @root */
static void a_1776(int a_F1,int a_F2){ /* tagredefined+>a+>a */
int a_L3;int a_L4;int a_P[5];
a_1198(a_F1,a_P);a_L3=a_P[0];
a_1058(a_F1,a_P);a_L4=a_P[0];
if(!__more(a_L3,0)){ goto a_G5;}
a_P[0]=2093834701;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L4;a_P[4]=a_L3;a_1040(-1,5,a_P);return;
a_G5:a_P[0]=2093834711;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L4;a_1040(-1,4,a_P);return;
} /* tagredefined */
static int a_1774(int a_A[1]){ /* isexpression+>a> */
int a_P[1];
if(!__equal(1454738977,a_1062)){ goto a_G4;}
a_G2:a_1077();
a_1012(2106125302);
a_G4:a_P[0]=a_A[0];if(!a_1772(a_P)){ return 0;}a_A[0]=a_P[0];
if(__is(a_A[0])){ return 1;}
if(!__equal(1454739004,a_1062)){ goto a_G9;}
a_1077();
a_1012(2106125315); goto a_G4;
a_G9:if(!__equal(1454739007,a_1062)){ goto a_G12;}
a_1077();
a_1012(2106125213); goto a_G4;
a_G12:if(!__equal(1454739010,a_1062)){ goto a_G15;}
a_1077();
a_1012(2106125369); goto a_G4;
a_G15:if(!__equal(1454738980,a_1062)){ goto a_G18;}
a_1077();
a_G17:a_1012(2106125321); goto a_G4;
a_G18:if(__equal(1454738977,a_1062)){ goto a_G2;}
if(a_1725()){ goto a_G17;}
if(!__equal(1454738956,a_1062)){ goto a_G26;}
a_1077();
a_1012(2106125343); goto a_G4;
a_G26:if(!__equal(1454738992,a_1062)){ return 1;}
a_1077();
a_1012(2106125248); goto a_G4;
} /* isexpression */
static void a_1771(int a_A[1]){ /* expectlisttag+>a> */
int a_L2;int a_L3;int a_P[3];
if(!a_1261(a_P)){ goto a_G15;}a_L2=a_P[0];
a_1058(a_L2,a_P);a_L3=a_P[0];
a_1017(a_L2);
if(__equal(a_L3,16777520)){ goto a_G10;}
if(__equal(a_L3,16777544)){ goto a_G10;}
if(__equal(a_L3,16777548)){ goto a_G10;}
if(__equal(a_L3,16777554)){ goto a_G10;}
a_P[0]=2093834626;a_P[1]=a_L2;a_P[2]=a_L3;a_1040(-1,3,a_P);
a_A[0]=1;
a_G10:if(!a_1205(a_L2,16)){ goto a_G13;}
a_A[0]=1;
a_P[0]=2093834647;a_P[1]=a_L2;a_1040(-1,2,a_P);
a_G13:if(__is(a_A[0])){return;}
a_1271(a_L2);return;
a_G15:a_A[0]=1;
a_P[0]=2093834598;a_1040(-1,1,a_P);return;
} /* expectlisttag */
static void a_1769(int a_F1,int a_A[1]){ /* expectconstanttag+>a+>a> */
int a_L3;int a_P[3];
a_1058(a_F1,a_P);a_L3=a_P[0];
a_1017(a_F1);
if(__equal(a_L3,16777520)){ goto a_G8;}
if(__equal(a_L3,16777525)){ goto a_G8;}
if(__equal(a_L3,16777566)){ goto a_G8;}
a_P[0]=2093834636;a_P[1]=a_F1;a_P[2]=a_L3;a_1040(-1,3,a_P);
a_A[0]=1;
a_G8:if(!a_1205(a_F1,16)){ goto a_G11;}
a_A[0]=1;
a_P[0]=2093834647;a_P[1]=a_F1;a_1040(-1,2,a_P);
a_G11:if(__is(a_A[0])){return;}
a_1271(a_F1);return;
} /* expectconstanttag */
static int a_1772(int a_A[1]){ /* exprbase+>a> */
int a_L2;int a_P[1];
if(!a_1432(a_P)){ goto a_G3;}a_L2=a_P[0];
a_1015(a_L2); return 1;
a_G3:if(!a_1261(a_P)){ goto a_G5;}a_L2=a_P[0];
a_P[0]=a_A[0];a_1769(a_L2,a_P);a_A[0]=a_P[0]; return 1;
a_G5:if(!__equal(1454739001,a_1062)){ goto a_G12;}
a_1077();
a_1012(2106125241);
a_P[0]=a_A[0];if(a_1772(a_P)){a_A[0]=a_P[0]; return 1;}
if(__is(a_A[0])){ return 1;}
a_A[0]=1;
a_P[0]=2093834588;a_1040(-1,1,a_P); return 1;
a_G12:if(!__equal(1454738935,a_1062)){ goto a_G16;}
a_1077();
a_G14:a_1012(2106125294);
a_G15:a_P[0]=a_A[0];a_1771(a_P);a_A[0]=a_P[0]; return 1;
a_G16:if(!__equal(1454738938,a_1062)){ goto a_G20;}
a_1077();
a_G18:a_1012(2106125358); goto a_G15;
a_G20:if(!__equal(1454738941,a_1062)){ goto a_G25;}
a_1077();
a_P[0]=2093834722;a_1041(1,-1,1,a_P); goto a_G14;
a_G25:if(!__equal(1454738944,a_1062)){ goto a_G30;}
a_1077();
a_P[0]=2093834722;a_1041(1,-1,1,a_P); goto a_G18;
a_G30:if(!__equal(1454738953,a_1062)){ goto a_G34;}
a_1077();
a_1012(2106125229); goto a_G15;
a_G34:if(!__equal(1454738959,a_1062)){ return 0;}
a_1077();
a_1012(2106125312);
a_P[0]=a_A[0];if(a_1774(a_P)){a_A[0]=a_P[0]; goto a_G41;}
if(__is(a_A[0])){ goto a_G41;}
a_A[0]=1;
a_P[0]=2093834588;a_1040(-1,1,a_P);
a_G41:a_1012(2106125232);
a_1263(1454738962); return 1;
} /* exprbase */
static void a_1770(int a_A[1]){ /* expectexpression+>a> */
int a_P[1];
a_P[0]=a_A[0];if(a_1774(a_P)){a_A[0]=a_P[0]; goto a_G4;}
a_A[0]=1;
a_P[0]=2093834607;a_1040(-1,1,a_P);
a_G4:if(!__is(a_A[0])){return;}
a_1268();return;
} /* expectexpression */
static void a_1768(int a_F1,int a_F2,int a_F3){ /* declarer+>a+>a+>a */
int a_L4;int a_L5;int a_P[1];
a_L4=0;
a_1058(a_F1,a_P);a_L5=a_P[0];
if(__equal(a_L5,16777520)){ goto a_G7;}
if(__equal(a_L5,a_F2)){ goto a_G7;}
a_1776(a_F1,a_F2);
a_L4=1;
a_G7:a_P[0]=a_L4;a_1245(a_F1,a_F3,a_P);a_L4=a_P[0];
if(__is(a_L4)){ goto a_G10;}
a_1267(a_F1,a_F2);
a_G10:a_1012(2106125258);
a_1017(a_F1);
a_P[0]=a_L4;a_1770(a_P);
a_1012(2106125324);return;
} /* declarer */
static void a_1773(int a_F1,int a_F2,int a_F3){ /* externaldeclarer+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_P[3];
a_L5=0;
a_1058(a_F1,a_P);a_L6=a_P[0];
if(__equal(a_L6,16777520)){ goto a_G7;}
if(__equal(a_L6,a_F2)){ goto a_G7;}
a_1776(a_F1,a_F2);
a_L5=1;
a_G7:if(a_1260(a_P)){a_L4=a_P[0]; goto a_G12;}
a_L4=0;
a_L5=1;
a_P[0]=2093834675;a_P[1]=a_F2;a_P[2]=a_F1;a_1040(-1,3,a_P);
a_1268();
a_G12:a_P[0]=a_L5;a_1246(a_F1,a_F3,a_P);a_L5=a_P[0];
if(__is(a_L5)){return;}
a_1267(a_F1,a_F2);
a_1266(a_F1,a_L4);return;
} /* externaldeclarer */
static void a_1775(int a_F1,int a_F2,int a_F3){ /* prototype+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_P[1];
a_1114(3429890,a_P);a_L4=a_P[0];
a_1058(a_F1,a_P);a_L5=a_P[0];
a_L6=0;
if(__equal(a_L5,16777520)){ goto a_G8;}
if(__equal(a_L5,a_F2)){ goto a_G8;}
a_1776(a_F1,a_F2);
a_L6=1;
a_G8:if(__is(a_L6)){ goto a_G14;}
if(!__equal(a_L4,1)){ goto a_G11;}
a_P[0]=a_L6;a_1247(a_F1,a_F3,a_P);a_L6=a_P[0]; goto a_G14;
a_G11:if(!__equal(a_L4,2)){ goto a_G13;}
a_P[0]=a_L6;a_1249(a_F1,a_F3,a_P);a_L6=a_P[0]; goto a_G14;
a_G13:a_1248(a_F1,a_F3);
a_G14:if(__is(a_L6)){return;}
a_1267(a_F1,a_F2);return;
} /* prototype */
static void a_1766(int a_F2,int a_A[1]){ /* declaration+>a>+>a */
int a_L3;int a_L4;int a_P[3];
if(!a_1262(a_P)){ goto a_G19;}a_L3=a_P[0];a_L4=a_P[1];
if(!__equal(1454738932,a_1062)){ goto a_G11;}
a_1077();
if(!__equal(a_A[0],3)){ goto a_G7;}
a_G5:a_P[0]=2093834690;a_P[1]=a_F2;a_1040(-1,2,a_P);
a_G6:a_1268();return;
a_G7:if(!__equal(a_A[0],1)){ goto a_G9;}
a_1773(a_L3,a_F2,a_L4);return;
a_G9:a_A[0]=2;
a_1768(a_L3,a_F2,a_L4);return;
a_G11:if(!__equal(a_A[0],1)){ goto a_G14;}
a_P[0]=2093834660;a_P[1]=a_F2;a_P[2]=a_L3;a_1040(-1,3,a_P); goto a_G6;
a_G14:if(__equal(a_A[0],2)){ goto a_G5;}
a_A[0]=3;
a_1775(a_L3,a_F2,a_L4);return;
a_G19:a_P[0]=2093834615;a_P[1]=a_F2;a_1040(-1,2,a_P);
a_1268();return;
} /* declaration */
static void a_1767(int a_F1,int a_F2){ /* declarationseries+>a+>a */
int a_P[1];
a_G1:a_P[0]=a_F1;a_1766(a_F2,a_P);a_F1=a_P[0];
if(!__equal(1454738968,a_1062)){ goto a_G4;}
a_1077(); goto a_G1;
a_G4:if(!__equal(1454738974,a_1062)){ goto a_G6;}
a_1077();return;
a_G6:a_1263(1454738974);
a_1269();return;
} /* declarationseries */
static void a_1579(int a_F1){ /* constantdeclaration+>a */

a_1767(a_F1,16777525);return;
} /* constantdeclaration */
static void a_1594(int a_F1){ /* variabledeclaration+>a */

a_1767(a_F1,16777535);return;
} /* variabledeclaration */
static void a_1592(void){ /* staticvariabledeclaration */

a_1767(0,16777540);return;
} /* staticvariabledeclaration */
static void a_1765(void){ /* @root */

} /* @root */
static void a_1777(void){ /* @root */

} /* @root */
