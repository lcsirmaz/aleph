/* ALEPH TARGET FILE
 * modules: data error input item lexical *link rule target version
 */
#include "A_lice.h"

#define a_1001 (0) /* @StringTable */
static void a_1009(void); /* @root */
static int a_1011(int a_F1); /* E */
#define a_1012 (a_1001+sizeof_LIST) /* EXPRESSION */
static int a_1013(int a_A[1]); /* Eitem */
static int a_1014(int a_F1,int a_A[2]); /* Eop */
static void a_1019(int a_F1); /* assign */
static void a_1020(void); /* assignreprnumbers */
static void a_1025(int a_F1); /* checkconstanttype */
static void a_1026(int a_F1); /* checklisttype */
static void a_1028(int a_F1); /* clearreprfield */
static void a_1029(int a_A[2]); /* collectlistsizeclaims */
static void a_1031(void); /* datasection */
static void a_1032(void); /* datasectionii */
static void a_1033(void); /* distributevirtualaddress */
static int a_1035=0; /* eptr */
static void a_1038(int a_F1); /* fillinitializer */
static void a_1039(void); /* fillitem */
static void a_1040(void); /* fillrepeater */
static int a_1041=0; /* filltablesize */
static void a_1042(int a_A[1]); /* finalbase */
static void a_1043(int a_F1); /* finaleval */
static void a_1044(void); /* finalevaluation */
static void a_1045(int a_F1,int a_A[1]); /* finalexpr */
static void a_1046(void); /* finalizepointerconstants */
static void a_1047(int a_F1,int a_F2); /* fixsize */
static int a_1049(int a_F1,int a_A[1]); /* getconstvalue */
static void a_1050(int a_F1,int a_F2,int a_A[1]); /* getestimator */
static void a_1051(int a_F1,int a_F2,int a_A[1]); /* getexprlimit */
static int a_1061=0; /* linkexpr */
static int a_1062=0; /* linklists */
static void a_1063(void); /* listentry */
static int a_1064(int a_A[1]); /* loosebase */
static void a_1065(void); /* loosebounds */
static void a_1066(int a_F1); /* looseeval */
static void a_1067(void); /* looseevaluation */
static int a_1068(int a_F1,int a_A[1]); /* looseexpr */
static void a_1069(void); /* loosefill */
static void a_1070(int a_A[1]); /* loosefillitem */
static void a_1071(int a_F1); /* looseinitializer */
static void a_1072(int a_F1,int a_F2,int a_F3); /* looserepeater */
static int a_1077=1000; /* nextreprno */
static void a_1079(int a_F1,int a_F2,int a_A[1]); /* optor */
static void a_1080(int a_F1); /* pushEXPR */
static void a_1085(void); /* readexpression */
static void a_1086(int a_F1,int a_F2); /* relativesize */
extern void a_release(int a_F1);
static void a_1088(int a_F1); /* rememberlist */
static void a_1089(int a_F1,int a_F2,int a_F3,int a_A[1]); /* repeatervalue */
static void a_1090(int a_F1,int a_F2,int a_F3); /* setfinalvalue */
static void a_1092(int a_F1); /* setlistbounds */
static void a_1093(int a_F1); /* setpointervalue */
static void a_1094(void); /* skipentry */
static void a_1095(void); /* skipfill */
static void a_1102(void); /* @root */
#define a_1017 (a_1012+sizeof_LIST) /* MESSAGE */
#define a_1103 (a_1017+sizeof_LIST) /* PRINTFILE */
#define a_1104 (a_1103+sizeof_CHFILE) /* a_setup_stdarg */
extern void a_setup_stdarg(int,int);
static void a_1030(int a_F1,int a_F2,int a_F3); /* corruptedicefile */
static void a_1036(int a_C,int *a_V); /* error */
static int a_1108=0; /* errorno */
extern void exit(int a_F1);
static void a_1110(int a_C,int *a_V); /* fatalerror */
static void a_1113(int a_C,int *a_V); /* formatprint */
static void a_1117(int a_F1,int a_F2,int a_F3); /* internalerror */
static void a_1118(int a_C,int *a_V); /* message */
static void a_1119(int a_F1); /* messagehead */
static void a_1120(void); /* nlcr */
static void a_1121(int a_F1,int a_F2); /* print */
static void a_1122(int a_F1); /* printbase */
static void a_1123(int a_F1); /* printchar */
static void a_1124(int a_F1); /* printform */
static void a_1125(int a_F1,int a_F2); /* printform1 */
static void a_1126(int a_F1); /* printint */
static void a_1127(int a_F1,int a_F2); /* printint1 */
static void a_1128(int a_F1); /* printitem */
static void a_1129(int a_F1); /* printline */
static void a_1130(int a_F1); /* printpointer */
static int a_1131=0; /* prpos */
extern void a_putchar(int a_F1,int a_F2);
static void a_1133(int a_F1,int a_F2,int a_F3); /* putstring */
extern int a_stringelem(int a_F1,int a_F2,int a_F3,int a_A[1]);
static void a_1137(int a_F1); /* tabline */
extern void a_unpackstring(int a_F1,int a_F2,int a_F3);
static void a_1097(int a_C,int *a_V); /* warning */
static int a_1099(void); /* waserror */
static void a_1140(void); /* @root */
static void a_1141(void); /* addextension */
static int a_1142=0; /* argptr */
static int a_1143=0; /* argtop */
static void a_1144(void); /* checkarguments */
extern void a_comparestring(int a_F1,int a_F2,int a_F3,int a_F4,int a_A[1]);
extern void a_copystring(int a_F1,int a_F2,int a_F3);
static void a_1148(int a_F1); /* extendBUFFER */
static void a_1115(int a_A[1]); /* geticefile */
static void a_1149(void); /* gettargetfile */
static int a_1151(int a_F1,int a_F2); /* isfirstarg */
static int a_1153=0; /* mainfile */
static int a_1154(void); /* nextargument */
static int a_1155(int a_F1,int a_A[1]); /* nextsource */
static void a_1156(int a_F1); /* openargument */
static void a_1157(int a_A[1]); /* openasitis */
static void a_1158(int a_A[1]); /* openwithextension */
extern void a_packstring(int a_F1,int a_F2,int a_F3);
static void a_1162(void); /* settargetfile */
static int a_1163=0; /* targetfile */
static int a_1166=0; /* withextension */
static void a_1167(void); /* @root */
#define a_1168 (a_1104+sizeof_LIST) /* AUX */
#define a_1015 (a_1168+sizeof_LIST) /* ITEM */
static void a_1169(void); /* addassignmentexternal */
static void a_1170(void); /* addgetaffixnoexternal */
static void a_1172(void); /* addshiftaffixexternal */
static void a_1173(void); /* addstdstring */
static void a_1174(int a_A[1]); /* advancebaseitem */
static int a_1175=0; /* baseitem */
static void a_1176(void); /* checkallitems */
static void a_1177(int a_F1,int a_F2,int a_F3); /* checkcompatibility */
static void a_1178(void); /* checkicecompat */
static void a_1179(int a_F1); /* checkitemID */
static void a_1180(void); /* checkmoduletitle */
static void a_1181(int a_F1,int a_F2); /* checktype */
static void a_1027(int a_F1,int a_F2); /* clearitemflag */
static int a_1182(int a_F1,int a_F2); /* compareformals */
static void a_1183(void); /* converttoitem */
static void a_1184(int a_F1); /* enteritem */
static void a_1185(void); /* expandITEM */
static void a_1186(int a_F1); /* filearea */
static void a_1037(void); /* fileentry */
static void a_1111(int a_F1,int a_A[3]); /* finditemlineno */
static void a_1112(int a_F1,int a_A[2]); /* findlineno */
static int a_1187=0; /* firstitem */
static void a_1188(int a_F1,int a_F2); /* formalaffixes */
static void a_1048(int a_F1,int a_A[1]); /* getcalibre */
static void a_1189(int a_F1,int a_A[3]); /* getfiledata */
static void a_1190(int a_A[3]); /* getfilelink */
static void a_1052(int a_F1,int a_A[1]); /* getfill */
static void a_1191(int a_F1,int a_F2,int a_A[1]); /* getformal */
static int a_1053(int a_F1,int a_A[1]); /* getitemdef */
static void a_1054(int a_F1,int a_A[1]); /* getlistlink */
static void a_1192(int a_F1,int a_A[1]); /* getnumberofformals */
static void a_1193(int a_F1,int a_A[1]); /* getrepeatcount */
static void a_1194(int a_F1,int a_A[1]); /* getssel */
static void a_1055(int a_F1,int a_A[1]); /* getvlwb */
static void a_1056(int a_F1,int a_A[1]); /* getvupb */
static void a_1196(int a_F1); /* headsection */
static int a_1197(int a_F1,int a_F2); /* incompatibletypes */
static int a_1198(int a_F1,int a_A[1]); /* isbuiltinrule */
static int a_1060(int a_F1,int a_F2); /* isitemflag */
static void a_1199(void); /* itemsection */
static int a_1200=0; /* linkformals */
static int a_1201=0; /* maxlineno */
static void a_1202(int a_F1); /* pushAUX */
static void a_1081(int a_F1,int a_F2); /* putfill */
static void a_1082(int a_F1,int a_F2); /* putlistlink */
static void a_1083(int a_F1,int a_F2); /* putvlwb */
static void a_1084(int a_F1,int a_F2); /* putvupb */
static void a_1204(void); /* readdefinitionlist */
static void a_1205(void); /* readitem */
static void a_1206(int a_F1,int a_F2,int a_A[2]); /* searchforline */
static void a_1207(int a_F1,int a_A[1]); /* searchformals */
static void a_1091(int a_F1,int a_F2); /* setitemflag */
static void a_1208(void); /* skipheadsection */
static void a_1209(void); /* skipitemsection */
static int a_1210(int a_F1,int a_F2); /* stacksizemismatch */
static void a_1211(int a_A[1]); /* storeformalaffixes */
static void a_1212(int a_A[1]); /* storelistbounds */
static int a_1213(int a_F1,int a_F2); /* unequaltypes */
static void a_1214(void); /* @root */
#define a_1215 (a_1015+sizeof_LIST) /* BOLD */
#define a_1010 (a_1215+sizeof_LIST) /* BUFFER */
#define a_1216 (a_1010+sizeof_LIST) /* HASH */
static int a_1217=1; /* HASHentries */
static int a_1218=511; /* HASHsize */
#define a_1016 (a_1216+sizeof_LIST) /* LEXT */
#define a_1219 (a_1016+sizeof_LIST) /* SOURCE */
static void a_1220(int a_A[1]); /* addLEXTentry */
static int a_1221=32; /* char */
extern void a_closefile(int a_F1);
static void a_1145(void); /* closesource */
static void a_1223(void); /* comment */
static void a_1224(int a_F1,int a_A[1]); /* enterstring */
static void a_1225(int a_F1); /* extendBUFFER */
extern int a_getchar(int a_F1,int a_A[1]);
extern void a_getfilepos(int a_F1,int a_A[1]);
static void a_1195(int a_F1,int a_A[1]); /* gettagdata */
static void a_1116(int a_F1,int a_A[1]); /* gettagimage */
static int a_1229(int a_A[1]); /* hexdigit */
static int a_1058=0; /* inpt */
static int a_1059=0; /* inptvalue */
static int a_1230=0; /* lastchar */
static int a_1231=0; /* lastfilepos */
static int a_1232=0; /* lastinpt */
static int a_1233=0; /* lastinptvalue */
static void a_1235(void); /* nextchar */
static void a_1078(void); /* nextsymbol */
extern int a_openfile(int a_F1,int a_F2,int a_F3,int a_F4);
static void a_1203(int a_F1,int a_F2); /* puttagdata */
static void a_1238(int a_A[1]); /* readbold */
static void a_1239(int a_A[1]); /* readdestination */
static void a_1240(int a_A[1]); /* readhex */
static void a_1241(int a_A[1]); /* readstring */
static void a_1242(int a_A[1]); /* readtype */
static void a_1243(void); /* rehash */
static void a_1244(void); /* restoreinputposition */
static void a_1245(void); /* saveinputposition */
extern void a_setfilepos(int a_F1,int a_F2);
extern void a_simplehash(int a_F1,int a_F2,int a_A[1]);
static int a_1134=1; /* sourceline */
static void a_1164(int a_A[1]); /* trytoopensource */
static void a_1249(void); /* @root */
static void a_1258(void); /* passi */
static void a_1259(void); /* passii */
static void a_1260(void); /* passiii */
static void a_1261(void); /* passiv */
static void a_1264(void); /* @root */
static int a_1265=0; /* C1 */
static int a_1266=0; /* C2 */
static int a_1267=0; /* C3 */
#define a_1268 (a_1219+sizeof_CHFILE) /* NODE */
#define a_1273 (a_1268+sizeof_LIST) /* ZONE */
static void a_1274(int a_F1,int a_F2,int a_F3,int a_A[1]); /* addinterval */
static void a_1275(void); /* advancenode */
static void a_1276(void); /* arealabels */
extern void a_blockhash(int a_F1,int a_F2,int a_A[1]);
static void a_1278(int a_F1,int a_A[1]); /* checkarea */
static void a_1279(void); /* checkareas */
static void a_1280(void); /* checknodehash */
static void a_1281(void); /* clearstacksize */
static void a_1282(int a_F1); /* comparetostoredaffixes */
static int a_1283(int a_F1); /* completezone */
static void a_1284(void); /* computeruleaffixhash */
static void a_1285(void); /* createnodes */
static int a_1286(int a_F1,int a_F2); /* diff1 */
static int a_1287=0; /* dolocalaffixcheck */
static int a_1288(int a_F1,int a_F2); /* equalaffixes */
static void a_1289(void); /* extensionlabel */
static void a_1290(void); /* findequalnodes */
static void a_1291(int a_F1,int a_F2); /* findintervalpair */
static void a_1292(int a_A[1]); /* findnextnode */
static void a_1293(int a_F1,int a_A[1]); /* findreallabel */
static void a_1294(void); /* generatearea */
static void a_1295(void); /* generateareas */
static void a_1296(void); /* generatebox */
static void a_1297(void); /* generateextension */
static void a_1298(void); /* generatelabel */
static void a_1299(void); /* generaterulecall */
static void a_1300(int a_F1,int a_A[1]); /* getnodeindex */
static int a_1301(void); /* islimit */
static int a_1303=0; /* localaffixptr */
static void a_1304(void); /* makerule */
static void a_1305(int a_F1); /* marklocalaffix */
static void a_1306(int a_F1,int a_F2); /* marknode */
static void a_1307(int a_F1); /* mergeintervals */
static int a_1308(void); /* nodehashdifferent */
static int a_1309(int a_F1); /* nodewithsamehash */
static void a_1310(int a_C,int *a_V); /* pushBUFFER */
static void a_1311(int a_F1,int a_F2); /* putnodeflag */
static void a_1312(int a_A[2]); /* readareainterval */
static void a_1313(int a_F1,int a_F2); /* replacelabels */
static void a_1316(void); /* rulelabel */
static int a_1317(int a_F1,int a_F2); /* samenodes */
static void a_1318(void); /* scani */
static void a_1319(void); /* scanii */
static void a_1320(void); /* scaniii */
static void a_1321(void); /* scaniv */
static void a_1322(int a_F1); /* setnodeflag */
static void a_1323(void); /* setrulehead */
static void a_1324(void); /* skipaffix */
static void a_1325(void); /* skiplist */
static void a_1326(void); /* skiprulehead */
static void a_1327(void); /* skiptocomma */
static void a_1328(int a_A[1]); /* skiptolabel */
static void a_1329(int a_F1,int a_F2); /* startlocalaffixcheck */
static void a_1330(void); /* storeaffix */
static void a_1331(void); /* storelimit */
static void a_1332(int a_F1); /* storelist */
static void a_1333(int a_A[1]); /* storeruleaffix */
static void a_1334(void); /* storeruleaffixes */
static int a_1335=0; /* storerulename */
static int a_1336=0; /* thisnode */
static void a_1337(void); /* @root */
static void a_1338(int a_F1,int a_C,int *a_V); /* T */
#define a_1339 (a_1273+sizeof_LIST) /* TARGET */
static void a_1340(int a_F1); /* Taffix */
static void a_1341(int a_A[1]); /* Taffixinner */
static void a_1269(int a_F1,int a_F2); /* Tbox */
static void a_1270(int a_F1,int a_F2); /* Textension */
static void a_1342(int a_F1,int a_F2); /* Tifcondition */
static void a_1343(int a_A[1]); /* Tindex */
static void a_1344(int a_F1,int a_F2); /* Tjumptoareas */
static void a_1271(int a_F1,int a_F2); /* Tlabel */
static void a_1345(int a_F1,int a_A[1]); /* Tlimittail */
static void a_1272(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6,int a_F7); /* Trulecall */
static void a_1346(int a_F1,int a_F2,int a_F3); /* Tsingleifcondition */
static void a_1347(void); /* addprofiling */
static void a_1348(void); /* addrulenameasstatic */
static void a_1349(void); /* addtracing */
static void a_1350(int a_A[1]); /* argsep */
static void a_1351(int a_F1,int a_F2,int a_A[2]); /* assignmentsource */
static void a_1352(int a_F1,int a_F2,int a_F3); /* blockdeclaration */
static void a_1353(int a_F1,int a_A[1]); /* boxclassifier */
static int a_1354=0; /* calledrule */
static void a_1355(int a_F1); /* charfileinitialization */
static void a_1250(void); /* closetarget */
static void a_1356(int a_A[1]); /* constitem */
static void a_1357(int a_F1,int a_A[1]); /* countfilearea */
static void a_1251(void); /* datadeclaration */
static void a_1358(int a_F1); /* datafileinitialization */
static void a_1252(void); /* datainitialization */
static void a_1253(void); /* datasectioniii */
static void a_1254(void); /* datasectioniv */
static void a_1359(int a_F1,int a_F2,int a_F3,int a_F4); /* declarecallargs */
static void a_1360(int a_F1,int a_F2,int a_F3); /* declarelocals */
static void a_1106(void); /* deletetarget */
static void a_1361(int a_F1,int a_F2,int a_F3); /* extensionblock */
static int a_1362(int a_F1); /* externalplaindeclaration */
static void a_1363(int a_F1); /* externalruletyper */
static void a_1364(void); /* fillentries */
static void a_1365(int a_A[1]); /* fillitem */
static int a_1366(int a_A[1]); /* fillrepeater */
static void a_1255(void); /* filltablehead */
static void a_1256(void); /* filltabletail */
static int a_1367=0; /* filltotal */
static void a_1368(int a_F1,int a_F2,int a_F3); /* flushbuffer */
static void a_1369(int a_F1); /* formalargument */
static void a_1370(int a_F1,int a_F2,int a_F3,int a_F4); /* genassignment */
static void a_1371(int a_F1,int a_F2,int a_F3); /* gengetaffixno */
static void a_1372(int a_F1,int a_F2); /* genshiftaffix */
static int a_1373(int a_F1); /* iscompletearea */
static int a_1374(int a_F1); /* isdummyaffix */
static int a_1375(int a_F1); /* ispidginalt */
static int a_1376(int a_F1); /* ispidgindiscarded */
static int a_1302(int a_F1); /* ispidginrule */
static void a_1377(int a_F1,int a_A[1]); /* iswaitfor */
static void a_1378(int a_F1); /* jumptolabel */
static void a_1379(int a_F1,int a_F2); /* listinitialization */
static void a_1380(int a_F1); /* localargument */
static void a_1381(int a_A[1]); /* nextaffix */
static int a_1382=0; /* nextnodeidx */
static void a_1257(void); /* opentarget */
static void a_1383(int a_F1,int a_A[1]); /* outargs */
static void a_1384(int a_F1); /* pidginalttagtail */
static void a_1385(int a_F1); /* pidginrepeatblock */
static void a_1386(int a_F1,int a_F2); /* pidginruleargs */
static void a_1387(int a_F1); /* pidginrulecall */
static void a_1388(int a_F1); /* printBUFFER */
static void a_1389(int a_F1); /* printGOTO */
static void a_1390(int a_F1); /* printexternalrepr */
static void a_1391(int a_F1); /* printgoto */
static void a_1392(int a_F1); /* printint */
static void a_1393(int a_F1,int a_F2); /* printint1 */
static void a_1394(int a_F1,int a_F2); /* printintindex */
static void a_1395(void); /* printlabelprefix */
static void a_1396(int a_F1); /* printlocallabel */
static void a_1397(int a_F1); /* printpidginrepr */
static void a_1398(int a_F1); /* printptr */
static void a_1399(int a_F1); /* printrepr */
static void a_1400(void); /* procwaitfor */
static void a_1401(int a_F1); /* pushBUFFER */
static void a_1402(int a_F1,int a_F2,int a_F3); /* putstring */
static void a_1403(int a_F1,int a_F2,int a_A[1]); /* regularcalld1 */
static void a_1404(int a_F1,int a_F2); /* regularcalld2 */
static void a_1405(int a_F1,int a_F2,int a_F3); /* regularcalld3 */
static void a_1406(int a_F1); /* regularcallpostload */
static void a_1407(int a_F1); /* regularcallpreload */
static void a_1408(int a_F1); /* regularrulecall */
static void a_1409(int a_F1,int a_F2,int a_F3); /* repeatblockcall */
static void a_1410(int a_F1,int a_F2,int a_F3,int a_F4); /* repeatblockpostload */
static void a_1411(int a_F1,int a_F2,int a_F3,int a_F4); /* repeatblockpreload */
static void a_1412(int a_F1); /* ruleargs */
static void a_1314(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6,int a_F7,int a_F8); /* ruledeclarationhead */
static void a_1315(void); /* ruledeclarationtail */
static void a_1413(int a_F1); /* ruleprototype */
static void a_1414(int a_F1); /* ruletyper */
static void a_1415(int a_F1); /* showformalsascomment */
static void a_1416(void); /* skipentry */
static void a_1417(void); /* skipfillinitializer */
static int a_1418=0; /* storename */
static void a_1262(void); /* targetmain */
static int a_1419=0; /* targetopened */
static void a_1263(void); /* targetprelude */
static int a_1420=0; /* thisrule */
extern void a_unlinkfile(int a_F1,int a_F2);
static void a_1422(int a_F1); /* vardeclaration */
extern int a_waitfor(int a_F1,int a_F2);
static void a_1424(void); /* @root */
#define BLOCK_TOTAL (a_1339+sizeof_CHFILE)
int a_DATABLOCK[BLOCK_TOTAL];
static int a_FILL[]={ /* fill table */
a_1001,/* @StringTable */
52,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,1635017060,7627008,4,4,0,
a_1017,/* MESSAGE */
83,540700709,1634493810,1702259060,2053731104,1936007269,1634560372,544370548,1763730469,1970217075,1718558836,1851879968,673211751,2713893,51,15,540700709,544762214,1702521203,1953719584,1952542057,622883439,1936269412,1953853216,544370464,1735287154,623386725,10601,46,14,540700709,1702521203,1953719584,1952542057,622883439,1634214000,1869488243,1818326560,673211765,2713893,39,12,1819044198,543649385,1629515813,1814372468,1701978170,1952540016,544220448,544432488,1970037110,1680154725,1953853216,543584032,1735287154,824713317,539897376,2712613,63,18,1819044198,543649385,1629515813,1814372468,1701978170,1952540016,1852793632,1851880563,1881481332,544434464,544501614,1768318308,6579566,51,15,1970499177,1667851878,1953391977,1919514144,1818326388,1634759456,25955,26,9,0,
a_1017,/* MESSAGE */
14,540700709,1936617315,1953390964,1717920800,1953066601,544108393,1701209458,1948283762,1953046639,1718379891,1764042784,41,45,14,0,
a_1001,/* @StringTable */
39,1869771365,7602290,5,4,774778459,93,5,4,6111067,3,3,6111067,3,3,6111067,3,3,6111067,3,3,1852404336,1935762036,1869742181,9,5,1852404336,1768910964,1919251566,0,12,6,1280659035,23884,6,4,1868854387,1694528629,6,4,0,
a_1017,/* MESSAGE */
44,544173940,2037277037,1920099616,745763439,1920296480,1919248500,1936026912,1701273971,1918967923,1970479205,1701998704,1684370291,0,48,15,1702129257,1818324594,1920099616,1629516399,1970413684,2123116,23,8,1852402720,1680154725,1650532396,1702130287,100,17,7,1701013806,1818846752,1881481317,1919902496,1953527154,1680156704,47,25,9,1629498409,1953656674,25701,10,5,0,
a_1001,/* @StringTable */
16,1970302569,7602292,5,4,28461,2,3,1702243629,1869181810,110,9,5,1701326125,28780,6,4,0,
a_1017,/* MESSAGE */
35,1763733358,1953853550,1818846752,1886593125,1718182757,744777065,1702065440,1747791136,544238693,544370534,1752375393,544502383,1886152040,0,52,16,1936943469,543649385,1735549300,1629516901,1919251558,7286048,23,8,1869771365,1886330994,1852403301,1764630631,1713399139,543517801,539783205,1919902305,6579572,35,11,0,
a_1001,/* @StringTable */
40,1835365481,7627008,4,4,1835365481,7627008,4,4,1835365481,7627008,4,4,1835365481,7627008,4,4,1835365481,7627008,4,4,1835365481,7627008,4,4,1835365481,7627008,4,4,1835365481,7627008,4,4,1835365481,7627008,4,4,1835365481,7627008,4,4,0,
a_1017,/* MESSAGE */
43,540700709,1868787305,1952542829,1701601897,1887007776,1629516645,1764040820,1684955424,6890784,35,11,540700709,1769498989,1696622446,1919251576,543973742,622883937,1851859049,1764040804,0,32,11,540700709,1651863396,1679849836,1852401253,1629512805,1764040820,1684955424,6890784,31,10,540700709,1679847278,1852401253,1869182057,1914711150,1702195557,1684370547,544497952,26917,34,11,0,
a_1016,/* LEXT */
30,1920226112,1416064617,1701601889,0,12,6,0,0,1634549824,25963,6,4,0,0,1718184051,1717985652,1818392681,7037807,15,6,0,0,1635018087,2020173414,1668246626,7302763,15,6,0,0,0,
a_1017,/* MESSAGE */
35,1969516397,1998611820,543716457,543516788,1701667187,1953068064,572548460,2256933,31,10,544175988,1852399981,1685024032,1936026741,622993466,1629495920,572548206,2256933,31,10,1830842222,544106849,1969516397,25964,14,6,1868787305,1952542829,1701601897,1667837472,1868963941,1952542066,0,24,9,0,
a_1001,/* @StringTable */
44,1769497964,7102819,7,4,1769497964,7102819,7,4,1769497964,7102819,7,4,1769497964,7102819,7,4,1769497964,7102819,7,4,1769497964,7102819,7,4,1634231666,1694525555,6,4,1769497964,7102819,7,4,1769497964,7102819,7,4,1885695073,1701576808,5,4,1769497964,7102819,7,4,0,
a_1016,/* LEXT */
5,0,0,3,0,0,0,
a_1215,/* BOLD */
246,1634038369,0,4,4,7892834,3,3,1768710499,6648418,7,4,1919973477,1769173861,28271,10,5,1702131813,1869181806,110,9,5,1701603686,0,4,4,1819044198,0,4,4,1953720684,0,4,4,6453100,3,3,1969516397,25964,6,4,1701080942,0,4,4,1701606770,0,4,4,1819568500,101,5,4,28532,2,3,6451317,3,3,1651993718,0,4,4,1651537270,0,4,4,1936617315,1953390964,0,8,5,1769103734,1701601889,0,8,5,1952543859,1981834089,29281,10,5,1818386804,101,5,4,1667331187,107,5,4,1952543859,1931502441,1801675124,0,12,6,1852403568,544367988,1936617315,1953390964,0,16,7,1918986339,1701603686,0,8,5,1635017060,1701603686,0,8,5,1701606770,0,4,4,1836216166,1931504737,1801675124,0,12,6,1836216166,1948281953,1701601889,0,12,6,1836216166,1713400929,6646889,11,5,1836216166,1763732577,110,9,5,1836216166,1864395873,29813,10,5,1836216166,1763732577,1953853294,0,12,6,1836216166,1914727521,1634037861,116,13,6,1836216166,1931504737,1952868712,0,12,6,38,1,3,93,1,3,41,1,3,58,1,3,44,1,3,126,1,3,47,1,3,45,1,3,35,1,3,40,1,3,124,1,3,62,1,3,43,1,3,46,1,3,59,1,3,42,1,3,91,1,3,94,1,3,1936617315,116,5,4,1701869940,0,4,4,1701080942,0,4,4,1835365481,0,4,4,1836216166,27745,6,4,1633906540,108,5,4,1769108595,26478,6,4,2763306,3,3,0,
a_1001,/* @StringTable */
28,1701606770,7627008,4,4,1701606770,7627008,4,4,1701606770,7627008,4,4,1701606770,7627008,4,4,1701606770,7627008,4,4,1701606770,7627008,4,4,1701606770,7627008,4,4,0,
a_1017,/* MESSAGE */
53,1634038369,544497952,540699685,1702326124,1868701810,543452789,1696621605,1701143416,1965060964,1919250544,1970233888,622879854,100,49,15,1634038369,544497952,540699685,1936287860,1953259808,1634628197,1702259060,1986358816,1931506277,1701012341,7562341,43,13,1953718636,1701994784,1952522337,980165920,1953459744,1819042080,1935762208,1629516645,1663067506,1919252079,25701,42,13,1935764579,1768319347,1769234787,1629515375,1814372468,1818304570,1937334647,1668641568,1684366691,115,37,12,0,
a_1001,/* @StringTable */
872,1735549300,29797,6,4,1769497964,7102819,7,4,1818190112,1601467241,1819044198,1180655912,692866121,2104370491,28197,26,9,1985962272,1970565737,1834970209,624782953,1600207716,1953655158,1600938357,1031299437,624649253,110,37,12,1952543859,1981834089,543451503,1633967969,1935630708,1886745701,1768912424,628828516,110,33,11,1629495328,1684300127,1818846815,1701994853,1915037793,745678124,992568357,28197,30,10,1935630624,1886745701,1768318047,623404396,1680157810,745678124,623669797,540748132,622864943,791289968,28197,42,13,678438176,992571941,28197,10,5,1935630624,1886745701,1634231135,1818846834,1915037797,744760620,623669797,540748146,622864943,791289968,28197,42,13,678438176,992571941,28197,10,5,1935630624,1886745701,1936288863,1680156788,745678124,623666213,1680157796,694428972,707731515,544220448,1847930666,0,44,14,678438176,623669797,624634212,110,13,6,7218557,3,3,123,1,3,1730509609,7218557,7,4,677800224,0,4,4,6759712,3,3,622885673,1847950695,0,8,5,677800224,0,4,4,628828457,1847950695,0,8,5,677800224,10273,6,4,6759712,3,3,1635461417,1701994847,1634099041,1684368489,1918853416,1852140661,744844641,992571429,7218557,35,11,677800224,10273,6,4,31868,2,3,1013196072,544220477,622863910,624770160,10596,18,7,1027502117,25637,6,4,1027371045,25637,6,4,1027436581,25637,6,4,7218491,3,3,1768383858,1919251571,1953392928,1030759712,0,16,7,1281322868,676614985,757690405,1886740798,624765794,1847933796,0,24,9,1700749600,1852142712,1852795251,745547048,992568357,0,20,8,1281322868,676614985,757690405,1886352446,1566844251,61,21,8,29221,2,3,1130324268,1449091372,0,8,5,1847936805,0,4,4,1847936805,0,4,4,628967205,7218503,7,4,1193638697,125,5,4,31529,2,3,2647657,3,3,556295785,0,4,4,1348428093,1566844251,59,9,5,1668113773,1630042480,1630295647,623592543,1600203876,1680157251,2053731114,677801829,695496297,15145,38,12,1147101501,1566844251,59,9,5,1348428093,1566844251,59,9,5,693133153,0,4,4,2650661,3,3,1630299173,623595615,10596,10,5,1630299173,2707551,7,4,725835617,1630299173,2704479,11,5,742612833,693526369,0,8,5,5267297,3,3,1531993953,1029530661,0,8,5,1668113773,1630042480,623592543,1600203876,1600203862,1680157251,2053731114,677801829,695496297,15145,38,12,1531207521,1029530661,0,8,5,1531993953,1029530661,0,8,5,1847936805,0,4,4,678588262,809332773,1013982523,994271073,724267045,1449091369,1567630683,997205309,0,32,11,997205309,0,4,4,7349548,3,3,1734701691,1702130537,1852383346,1881481332,61,17,7,1734701691,1702130537,1852383346,1881481332,59,17,7,1130324285,625419579,110,9,5,1735549300,29797,6,4,1630037609,1027359583,628828465,1629519207,757941087,1449091387,1680162091,7218491,31,10,1630037609,826164063,1600224041,992816451,727080801,996418877,545081125,1847936805,0,32,11,1281322868,676614985,757690405,7349566,15,6,28709,2,3,1566844205,0,4,4,93,1,3,1281322868,676614985,757690405,1717989182,1534354803,0,20,8,744760620,1970429793,1634624876,1562994029,0,16,7,1281322868,676614985,757690405,1717989182,1534354803,1768709985,1818588275,623406437,11376,34,11,1735549300,29797,6,4,627516704,110,5,4,1735549300,29797,6,4,1847929904,0,4,4,744760621,28197,6,4,791441957,1881481258,623847968,110,13,6,2909221,3,3,2909221,3,3,2909221,3,3,2909221,3,3,1936617315,1702127988,109,9,5,998060333,539635488,1819044198,1650553888,1931502956,543521385,706765861,7218479,31,10,1952543859,1763730281,1629516910,1279870559,1029528396,707731579,1818846752,1635000428,543517794,1847930666,0,40,13,544501353,1094999905,1279410516,1531659087,995979301,28197,22,8,1717920803,543518313,673214501,623604261,1847929200,0,20,8,1717920803,543518313,807432229,28197,14,6,707731515,544220448,1847930666,0,12,6,7218491,3,3,1702131813,1981836914,543451503,1764257829,1764521070,992572526,28197,26,9,707731497,544220448,1847930666,0,12,6,623604261,112,5,4,48,1,3,1717920803,543518313,673215013,0,12,6,1952543859,1763730281,622883950,1680162162,707731515,544220448,1847930666,0,28,10,1702131813,1763733106,622883950,1847933808,0,16,7,707731581,544220448,1847930666,0,12,6,623847968,110,5,4,707731579,7349536,7,4,1847933737,0,4,4,1952407840,1701011826,1819636319,1600202853,1701606770,1701667182,6563116,27,9,1635021600,543385972,1380999009,1279870543,1600200773,1718579824,1030057065,1819619451,1280658988,1431186508,998067276,1629515301,1330794591,1229736262,1630029646,1869770847,1701603686,1918853420,1852140661,694512993,7218491,83,23,1635021600,543385972,1918986339,1600203296,1701606770,1701667182,1881481789,1847933730,0,32,11,544501353,1147101482,1819042109,677471087,1702521203,1764255343,707359854,727983400,1630168101,690570079,59,41,13,544501353,1531993953,995976229,0,12,6,544501353,625762145,15204,10,5,10795,2,3,1713513003,0,4,4,1935498027,6118260,7,4,1566274603,0,4,4,1046560299,0,4,4,4088107,3,3,6372907,3,3,1684631414,0,4,4,544501353,625368929,100,9,5,544501353,742612833,544501353,1449091370,41,17,7,544501353,1531010913,6120485,11,5,1702131813,1981836914,543451503,2650149,15,6,1702131813,1763733106,622883950,10352,14,6,1952543859,1981834089,543451503,2650661,15,6,1952543859,1763730281,622883950,10354,14,6,7218557,3,3,678569248,790641449,1881481258,623847968,110,17,7,1381982496,807957029,992555052,539635488,706768933,7218479,23,8,1684631414,1381982496,676613967,1684631414,1847950121,1683972384,1600222305,1970562419,992553072,28197,38,12,1380802401,676613967,573338149,690122789,28197,18,7,1952805408,544109173,1847933744,7218557,15,6,677800224,626155361,1600202866,1630286150,691160671,1702001449,1852994932,2101031200,28197,34,11,544501353,1635213153,1868985449,1852385394,1600200820,1764503878,1629516910,691160671,7218555,35,11,706768421,594421039,1818455657,543515765,1818181922,778396521,1847927400,28197,30,10,7349536,3,3,1881483808,0,4,4,1092626991,1213220172,1380013088,542393671,1162627398,539323941,1869422634,1701606756,14963,34,11,774778459,93,5,4,1852404336,1920233588,0,8,5,1852404336,1179992692,5391686,11,5,1953457952,8303,6,4,1952805408,544109173,15152,10,5,1970562418,3894898,7,4,1952805408,544109173,15153,10,5,1852404336,1953458036,111,9,5,1885695073,6499944,7,4,0,
a_1017,/* MESSAGE */
14,1852727651,1663071343,1952540018,1635000421,1952802674,1818846752,1881481317,1919229996,544370546,1701080931,1680154682,0,44,14,0,
a_1016,/* LEXT */
13,1869574720,116,5,4,0,0,1635213153,1868985449,114,9,5,0,0,0,
a_1017,/* MESSAGE */
22,1702521203,1281320559,5526345,11,5,1702521203,1130325615,1279870536,69,13,6,1702521203,1147102831,1162627398,0,12,6,1129270338,1330929483,4997460,11,5,0,
a_1017,/* MESSAGE */
28,1768710499,6648418,7,4,1651993697,0,4,4,1651537249,0,4,4,1651993718,0,4,4,1651537270,0,4,4,829579105,0,4,4,846356321,0,4,4,0,
a_1017,/* MESSAGE */
116,1734439765,1629502053,1802398060,757947168,1886152040,757955616,1936876918,1567518569,538996261,980578080,1768710432,1528851310,1948282669,1701278305,1713397108,543517801,623783470,1852394606,1279336555,759713861,1764630605,1713399139,1936026729,544175136,541270113,1735357040,778920306,1884253733,1852795252,1847933555,757932064,1886152040,538976288,538976288,1948262432,544434536,1886152040,538996261,1702243629,1869181810,538976366,538976288,1919252000,1852795251,1718511904,544089455,544156960,1918989372,1047815527,538976288,1752440864,1970217061,1953853556,543370784,1701603686,0,220,58,1346718785,541928776,1802398060,1981837925,1769173605,622882415,1680158308,1866690085,1769109872,544499815,539575080,808595506,842019373,1632378930,1869380211,1769161504,2053205362,1750363685,1763734377,543236211,1701147238,1718580000,1918990196,1931488357,1948280165,1931502952,1668445551,1868963941,1868767346,1769109872,544499815,1868983913,1952542066,778989417,1701336096,1763730802,1315841395,1096228943,1312903762,540760404,544501614,1852143205,1667591456,1953390952,1818845801,544830569,1713402479,1701737577,1713402739,1629516399,1918988320,1969449332,544366956,1886549360,778400623,0,220,58,0,
-1}; /* fill table size 1938 */
static void a_data_setup(void){
 a_virtual_min=16777216;a_virtual_max=2130706432;
 a_setup_list(0,a_1001,1,16777217,16778307,1091); /* @StringTable */
 a_setup_list(1,a_1012,1,1922291005,2130706372,0); /* EXPRESSION */
 a_setup_list(0,a_1017,1,1922290517,1922291003,487); /* MESSAGE */
 a_setup_stdarg(a_1104,1);
 a_setup_list(1,a_1168,6,1029081790,1326818024,0); /* AUX */
 a_setup_list(1,a_1015,6,1326818036,1922290510,0); /* ITEM */
 a_setup_list(0,a_1215,1,344288182,344288427,246); /* BOLD */
 a_setup_list(1,a_1010,1,969534536,1029081783,0); /* BUFFER */
 a_setup_list(1,a_1216,1,344288429,374062052,0); /* HASH */
 a_setup_list(1,a_1016,2,374062055,969534533,48); /* LEXT */
 a_setup_list(1,a_1268,6,16778314,314514548,0); /* NODE */
 a_setup_list(1,a_1273,3,314514557,344288178,0); /* ZONE */
 a_setup_charfile(a_1103,2,a_1001,16777307); /* PRINTFILE */
 a_setup_charfile(a_1219,1,a_1001,16777403); /* SOURCE */
 a_setup_charfile(a_1339,2,a_1001,16778307); /* TARGET */
 a_list_fill(a_FILL);
}
a_MROOT(a_1009,"data")
a_MROOT(a_1102,"error")
a_MROOT(a_1140,"input")
a_MROOT(a_1167,"item")
a_MROOT(a_1214,"lexical")
a_MROOT(a_1264,"rule")
a_MROOT(a_1337,"target")
a_MROOT(a_1424,"version")
int a_waitfor(int a_F1,int a_F2){
 if(a_Ra_1009(a_F1,a_F2)){return 1;}
 if(a_Ra_1102(a_F1,a_F2)){return 1;}
 if(a_Ra_1140(a_F1,a_F2)){return 1;}
 if(a_Ra_1167(a_F1,a_F2)){return 1;}
 if(a_Ra_1214(a_F1,a_F2)){return 1;}
 if(a_Ra_1264(a_F1,a_F2)){return 1;}
 if(a_Ra_1337(a_F1,a_F2)){return 1;}
 if(a_Ra_1424(a_F1,a_F2)){return 1;}
 return 0;
}
void a_ROOT(void){
 a_data_setup();
 a_Ra_1009(0,0); /* data */
 a_Ra_1102(0,0); /* error */
 a_Ra_1140(0,0); /* input */
 a_Ra_1167(0,0); /* item */
 a_Ra_1214(0,0); /* lexical */
 a_Ra_1264(0,0); /* rule */
 a_Ra_1337(0,0); /* target */
 a_Ra_1424(0,0); /* version */
 a_1249(); /* link */
}
static void a_1080(int a_F1){ /* pushEXPR+>a */

 a_extension(a_1012,1);to_LIST(a_1012)->top[1]=a_F1;to_LIST(a_1012)->aupb+=1;
 return;
} /* pushEXPR */
static void a_1026(int a_F1){ /* checklisttype+>a */

{register int a_r1=to_LIST(a_1015)->offset[a_F1-4];
 if(a_r1==344288266||a_r1==344288270||a_r1==344288276){ return;}
}
a_1030(a_1001,16777268,47);return;
} /* checklisttype */
static void a_1025(int a_F1){ /* checkconstanttype+>a */

{register int a_r1=to_LIST(a_1015)->offset[a_F1-4];
 if(a_r1==344288252||a_r1==344288283){ return;}
}
a_1030(a_1001,16777264,51);return;
} /* checkconstanttype */
static void a_1088(int a_F1){ /* rememberlist+>a */
int a_L2;int a_P[1];
a_1054(a_F1,a_P);a_L2=a_P[0];
if(!__less(a_L2,0)){return;}
a_1082(a_F1,a_1062);
a_1062=a_F1;return;
} /* rememberlist */
static void a_1063(void){ /* listentry */
int a_L1;int a_L2;int a_L3;
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777220,44);return;
a_G5:a_1026(a_L1);
if(!a_1060(a_L1,8)){ goto a_G8;}
a_1030(a_1001,16777260,66);return;
a_G8:if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L2=a_1059;
a_1078();
{ if(a_L2==1||a_L2==2){ goto a_G13;}
 if(a_L2==3||a_L2==4){  goto a_G17;}
  goto a_G22;}
a_G13:if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L3=a_1059;
a_1078(); goto a_G23;
a_G17:if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L3=a_1059;
a_1078();
a_1025(a_L3); goto a_G23;
a_G22:a_1030(a_1001,16777256,70);return;
a_G23:a_1084(a_L1,a_L2);
a_1083(a_L1,a_L3);
a_1088(a_L1);
if(!__equal(344288384,a_1058)){ goto a_G4;}

a_1078();return;
} /* listentry */
static void a_1039(void){ /* fillitem */
int a_L1;
if(!__equal(344288372,a_1058)){ goto a_G12;}
a_G2:a_1078();
a_G3:if(!__equal(344288351,a_1058)){ goto a_G5;}
a_G4:a_1078();return;
a_G5:if(__equal(344288400,a_1058)){ goto a_G2;}
if(!__equal(344288412,a_1058)){ goto a_G10;}
a_L1=a_1059;
a_1078(); goto a_G11;
a_G10:a_1030(a_1001,16777220,44);return;
a_G11:a_1025(a_L1); goto a_G3;
a_G12:if(__equal(344288400,a_1058)){ goto a_G4;}
if(!__equal(344288412,a_1058)){ goto a_G10;}
a_L1=a_1059;
a_1078();
a_1025(a_L1);return;
} /* fillitem */
static void a_1040(void){ /* fillrepeater */
int a_L1;
if(!__equal(344288390,a_1058)){return;}
a_1078();
if(!__equal(344288400,a_1058)){ goto a_G5;}
a_1078();return;
a_G5:if(!__equal(344288412,a_1058)){ goto a_G8;}
a_L1=a_1059;
a_1078(); goto a_G9;
a_G8:a_1030(a_1001,16777220,44);return;
a_G9:a_1025(a_L1);return;
} /* fillrepeater */
static void a_1038(int a_F1){ /* fillinitializer+>a */
int a_L2;
a_G1:if(!__equal(344288354,a_1058)){return;}
a_1078();
if(!__equal(344288412,a_1058)){ goto a_G6;}
a_L2=a_1059;
a_1078(); goto a_G7;
a_G6:a_1030(a_1001,16777220,44);return;
a_G7:if(!__equal(to_LIST(a_1015)->offset[a_L2-4],344288283)){ goto a_G9;}
if(__equal(to_LIST(a_1015)->offset[a_L2-1],0)){ goto a_G10;}
a_G9:a_1030(a_1001,16777252,86);return;
a_G10:to_LIST(a_1015)->offset[a_L2-1]=a_F1; goto a_G1;
} /* fillinitializer */
static void a_1095(void){ /* skipfill */
int a_L1;
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777220,44);return;
a_G5:a_1026(a_L1);
if(!__equal(344288400,a_1058)){ goto a_G4;}

a_1078();
a_1088(a_L1);
a_G11:if(!__equal(344288384,a_1058)){ goto a_G13;}
a_1078();return;
a_G13:a_1039();
a_1040();
a_1038(a_L1); goto a_G11;
} /* skipfill */
static void a_1086(int a_F1,int a_F2){ /* relativesize+>a+>a */
int a_P[4];
if(__less(a_F1,1)){ goto a_G3;}
if(!__more(a_F1,100)){ goto a_G4;}
a_G3:a_P[0]=1922290531;a_P[1]=to_LIST(a_1015)->offset[a_F2-3];a_P[2]=a_F1;a_P[3]=a_F2;a_1097(4,a_P);
a_G4:__min(100,a_F1);
__max(1,a_F1);
a_1084(a_F2,a_F1);return;
} /* relativesize */
static void a_1047(int a_F1,int a_F2){ /* fixsize+>a+>a */
int a_P[4];
if(__less(a_F1,1)){ goto a_G3;}
if(!__more(a_F1,1000000)){ goto a_G4;}
a_G3:a_P[0]=1922290545;a_P[1]=to_LIST(a_1015)->offset[a_F2-3];a_P[2]=a_F1;a_P[3]=a_F2;a_1097(4,a_P);
a_G4:__min(1000000,a_F1);
__max(1,a_F1);
__subtr(0,a_F1,a_F1);
a_1084(a_F2,a_F1);return;
} /* fixsize */
static int a_1049(int a_F1,int a_A[1]){ /* getconstvalue+>a+a> */
int a_L3;int a_P[1];
if(!a_1060(a_F1,32)){ goto a_G3;}
a_A[0]=to_LIST(a_1015)->offset[a_F1]; return 1;
a_G3:if(!a_1053(a_F1,a_P)){ return 0;}a_L3=a_P[0];
if(!a_1060(a_L3,32)){ return 0;}
a_1091(a_F1,32);
{register int a_r1=to_LIST(a_1015)->offset[a_L3];to_LIST(a_1015)->offset[a_F1]=a_r1;a_A[0]=a_r1;} return 1;
} /* getconstvalue */
static void a_1050(int a_F1,int a_F2,int a_A[1]){ /* getestimator+>a+>a+a> */
int a_P[4];
if(a_1049(a_F1,a_P)){a_A[0]=a_P[0];return;}
a_A[0]=1;
a_P[0]=1922290557;a_P[1]=to_LIST(a_1015)->offset[a_F2-3];a_P[2]=to_LIST(a_1015)->offset[a_F1-3];a_P[3]=a_F2;a_1036(4,a_P);return;
} /* getestimator */
static void a_1065(void){ /* loosebounds */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
a_L1=a_1062;
a_G2:if(__equal(a_L1,0)){return;}
if(!a_1053(a_L1,a_P)){ goto a_G6;}
a_1083(a_L1,0);
a_G5:a_1084(a_L1,0); goto a_G17;
a_G6:a_1056(a_L1,a_P);a_L2=a_P[0];
a_1055(a_L1,a_P);a_L3=a_P[0];
a_1083(a_L1,0);
{ if(a_L2==1){ goto a_G10;}
 if(a_L2==2){ goto a_G11;}
 if(a_L2==3){ goto a_G12;}
 if(a_L2==4){  goto a_G14;}
  goto a_G5;}
a_G10:a_1086(a_L3,a_L1); goto a_G17;
a_G11:a_1047(a_L3,a_L1); goto a_G17;
a_G12:a_1050(a_L3,a_L1,a_P);a_L4=a_P[0];
a_1086(a_L4,a_L1); goto a_G17;
a_G14:a_1050(a_L3,a_L1,a_P);a_L4=a_P[0];
a_1047(a_L4,a_L1);
a_G17:a_1054(a_L1,a_P);a_L1=a_P[0]; goto a_G2;
} /* loosebounds */
static void a_1070(int a_A[1]){ /* loosefillitem+a> */

if(!__equal(344288372,a_1058)){ goto a_G14;}
a_1078();
a_A[0]=0;
a_G4:if(!__equal(344288351,a_1058)){ goto a_G6;}
a_1078();return;
a_G6:if(!__equal(344288400,a_1058)){ goto a_G9;}
a_G7:a_1078();
__incr(a_A[0]); goto a_G4;
a_G9:if(!__equal(344288412,a_1058)){ goto a_G12;}
 goto a_G7;
a_G12:a_1030(a_1001,16777220,44);return;
a_G14:if(!__equal(344288400,a_1058)){ goto a_G17;}
a_G15:a_1078();
a_A[0]=1;return;
a_G17:if(!__equal(344288412,a_1058)){ goto a_G12;}
 goto a_G15;
} /* loosefillitem */
static void a_1089(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* repeatervalue+>a+>a+>a+a> */
int a_P[6];
if(!a_1049(a_F3,a_P)){ goto a_G6;}a_A[0]=a_P[0];
if(!__lseq(1,a_A[0])){ goto a_G4;}
if(__lseq(a_A[0],10000)){return;}
a_G4:a_P[0]=1922290575;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_P[2]=a_F2;a_P[3]=to_LIST(a_1015)->offset[a_F3-3];a_P[4]=a_A[0];a_P[5]=10000;a_1036(6,a_P);
a_A[0]=1;return;
a_G6:a_A[0]=1;
a_P[0]=1922290590;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_P[2]=a_F2;a_P[3]=to_LIST(a_1015)->offset[a_F3-3];a_1036(4,a_P);return;
} /* repeatervalue */
static void a_1072(int a_F1,int a_F2,int a_F3){ /* looserepeater+>a+>a+>a */
int a_L4;int a_L5;int a_P[1];
if(!__equal(344288390,a_1058)){ goto a_G15;}
a_1078();
if(!__equal(344288400,a_1058)){ goto a_G6;}
a_L5=a_1059;
a_1078(); goto a_G12;
a_G6:if(!__equal(344288412,a_1058)){ goto a_G9;}
a_L4=a_1059;
a_1078(); goto a_G10;
a_G9:a_1030(a_1001,16777220,44);return;
a_G10:if(a_1053(a_L4,a_P)){a_L4=a_P[0];}
a_1089(a_F1,a_F2,a_L4,a_P);a_L5=a_P[0];
a_G12:if(__equal(a_L5,1)){ goto a_G14;}
__add(2,a_1041,a_1041);
a_G14:__mult(a_F3,a_L5,a_F3);
a_G15:a_1052(a_F1,a_P);a_L5=a_P[0];
__add(a_F3,a_L5,a_L5);
a_1081(a_F1,a_L5);return;
} /* looserepeater */
static void a_1071(int a_F1){ /* looseinitializer+>a */
int a_L2;int a_L3;int a_P[1];
a_G1:if(!__equal(344288354,a_1058)){return;}
a_1078();
if(!__equal(344288412,a_1058)){ goto a_G6;}
a_L2=a_1059;
a_1078(); goto a_G7;
a_G6:a_1030(a_1001,16777220,44);return;
a_G7:if(!a_1053(a_L2,a_P)){ goto a_G9;}
a_1030(a_1001,16777248,172);return;
a_G9:a_1052(a_F1,a_P);a_L3=a_P[0];
to_LIST(a_1015)->offset[a_L2]=a_L3;
to_LIST(a_1015)->offset[a_L2-1]=a_F1; goto a_G1;
} /* looseinitializer */
static void a_1069(void){ /* loosefill */
int a_L1;int a_L2;int a_L3;int a_P[1];
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777220,44);return;
a_G5:if(!a_1053(a_L1,a_P)){ goto a_G7;}a_L1=a_P[0];
a_1088(a_L1);
a_G7:if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L2=a_1059;
a_1078();
a_G11:if(!__equal(344288384,a_1058)){ goto a_G13;}
a_1078();return;
a_G13:a_1070(a_P);a_L3=a_P[0];
__add(a_L3,a_1041,a_1041);
a_1072(a_L1,a_L2,a_L3);
a_1071(a_L1); goto a_G11;
} /* loosefill */
static void a_1029(int a_A[2]){ /* collectlistsizeclaims+a>+a> */
int a_L3;int a_L4;int a_L5;int a_P[1];
a_A[0]=0;a_A[1]=0;
a_L3=a_1062;
a_G3:if(__equal(a_L3,0)){return;}
if(!a_1053(a_L3,a_P)){ goto a_G6;}
a_G5:a_1054(a_L3,a_P);a_L3=a_P[0]; goto a_G3;
a_G6:a_1048(a_L3,a_P);a_L4=a_P[0];
__add(a_L4,a_A[0],a_A[0]);
a_1052(a_L3,a_P);a_L4=a_P[0];
a_1056(a_L3,a_P);a_L5=a_P[0];
if(!__lseq(a_L5,0)){ goto a_G14;}
__subtr(0,a_L5,a_L5);
__max(a_L5,a_L4);
a_G13:__add(a_L4,a_A[0],a_A[0]); goto a_G5;
a_G14:__add(a_L5,a_A[1],a_A[1]); goto a_G13;
} /* collectlistsizeclaims */
static void a_1092(int a_F1){ /* setlistbounds+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[1];
a_L2=16777216;
a_L3=a_1062;
a_G3:if(__equal(a_L3,0)){return;}
if(!a_1053(a_L3,a_P)){ goto a_G6;}
a_G5:a_1054(a_L3,a_P);a_L3=a_P[0]; goto a_G3;
a_G6:a_1052(a_L3,a_P);a_L5=a_P[0];
a_1056(a_L3,a_P);a_L6=a_P[0];
if(!__lseq(a_L6,0)){ goto a_G10;}
__subtr(0,a_L6,a_L6); goto a_G11;
a_G10:__mult(a_L6,a_F1,a_L6);
a_G11:__max(a_L6,a_L5);
a_1048(a_L3,a_P);a_L4=a_P[0];
__add(a_L4,a_L2,a_L6);
a_1083(a_L3,a_L6);
__add(a_L5,a_L2,a_L2);
a_1084(a_L3,a_L2);
__add(a_L2,a_L4,a_L2); goto a_G5;
} /* setlistbounds */
static void a_1033(void){ /* distributevirtualaddress */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_1029(a_P);a_L1=a_P[0];a_L2=a_P[1];
if(__more(a_L2,0)){ goto a_G4;}
a_L2=1;
a_G4:__subtr(2130706432,16777216,a_L3);
if(__less(a_L1,0)){ goto a_G10;}
if(__less(a_L3,a_L1)){ goto a_G10;}
__subtr(a_L3,a_L1,a_L3);
__div(a_L3,a_L2,a_L3);
if(!__lseq(a_L3,0)){ goto a_G11;}
a_G10:a_P[0]=1922290599;a_1036(1,a_P);return;
a_G11:a_1092(a_L3);return;
} /* distributevirtualaddress */
static void a_1093(int a_F1){ /* setpointervalue+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_L2=to_LIST(a_1015)->offset[a_F1-1];
a_1048(a_L2,a_P);a_L3=a_P[0];
a_1055(a_L2,a_P);a_L4=a_P[0];
__subtr(a_L4,a_L3,a_L4);
__add(a_L4,to_LIST(a_1015)->offset[a_F1],to_LIST(a_1015)->offset[a_F1]);
a_1091(a_F1,32);return;
} /* setpointervalue */
static void a_1046(void){ /* finalizepointerconstants */
int a_L1;int a_P[1];
a_L1=to_LIST(a_1015)->alwb;
a_G2:if(__more(a_L1,to_LIST(a_1015)->aupb)){return;}
if(!__equal(to_LIST(a_1015)->offset[a_L1-4],344288283)){ goto a_G7;}
if(!a_1053(a_L1,a_P)){ goto a_G6;}
a_1030(a_1001,16777244,226);return;
a_G6:a_1093(a_L1);
a_G7:__next(a_1015,a_L1); goto a_G2;
} /* finalizepointerconstants */
static void a_1085(void){ /* readexpression */
int a_L1;int a_L2;
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777220,44);return;
a_G5:{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288252||a_r1==344288257||a_r1==344288262){  goto a_G7;}
}
a_1030(a_1001,16777240,238);return;
a_G7:a_1080(a_L1);
a_L2=to_LIST(a_1012)->aupb;
a_1080(a_1061);
a_1061=a_L2;
to_LIST(a_1015)->offset[a_L1-1]=to_LIST(a_1012)->aupb;
a_G12:{ if(a_1058==344288384){ goto a_G13;}
 if(a_1058==344288400){ goto a_G15;}
 if(a_1058==344288412){ goto a_G18;}
 if(a_1058==344288217||a_1058==344288239||a_1058==344288192){ goto a_G21;}
 if(a_1058==344288381||a_1058==344288366||a_1058==344288390||a_1058==344288363||a_1058==344288345||a_1058==344288375||a_1058==344288396||a_1058==344288360||a_1058==344288372||a_1058==344288351){  goto a_G29;}
  goto a_G31;}
a_G13:a_1078();
a_1080(344288384);return;
a_G15:a_1080(344288400);
a_G16:a_1080(a_1059);
a_G17:a_1078(); goto a_G12;
a_G18:a_1025(a_1059); goto a_G16;
a_G21:a_1080(a_1058);
a_1078();
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078();
a_1080(a_L1);
a_1026(a_L1); goto a_G12;
a_G29:a_1080(a_1058); goto a_G17;
a_G31:a_1030(a_1001,16777236,248);return;
} /* readexpression */
static void a_1031(void){ /* datasection */

if(a_1099()){return;}
a_G2:if(!__equal(344288210,a_1058)){ goto a_G5;}
a_1078();
a_1095(); goto a_G2;
a_G5:if(!__equal(344288197,a_1058)){ goto a_G8;}
a_1078();
a_1085(); goto a_G2;
a_G8:if(!__equal(344288214,a_1058)){ goto a_G11;}
a_1078();
a_1063(); goto a_G2;
a_G11:if(!__equal(344288206,a_1058)){return;}
a_1078();
a_1037(); goto a_G2;
} /* datasection */
static void a_1094(void){ /* skipentry */

a_G1:if(!__equal(344288384,a_1058)){ goto a_G3;}
a_1078();return;
a_G3:a_1078(); goto a_G1;
} /* skipentry */
static void a_1032(void){ /* datasectionii */

a_G1:if(!__equal(344288197,a_1058)){ goto a_G4;}
a_G2:a_1078();
a_1094(); goto a_G1;
a_G4:if(__equal(344288214,a_1058)){ goto a_G2;}
if(__equal(344288206,a_1058)){ goto a_G2;}
if(!__equal(344288210,a_1058)){return;}
a_1078();
a_1069(); goto a_G1;
} /* datasectionii */
static int a_1011(int a_F1){ /* E+>a */

if(!__equal(to_LIST(a_1012)->offset[a_1035],a_F1)){ return 0;}
__incr(a_1035); return 1;
} /* E */
static int a_1013(int a_A[1]){ /* Eitem+a> */

a_A[0]=to_LIST(a_1012)->offset[a_1035];
if(!__was(a_1015,a_A[0])){ return 0;}
__incr(a_1035); return 1;
} /* Eitem */
static int a_1014(int a_F1,int a_A[2]){ /* Eop+>a+a>+a> */

a_A[0]=to_LIST(a_1012)->offset[a_1035];
{ if(a_A[0]==344288396){ goto a_G3;}
 if(a_A[0]==344288345){ goto a_G6;}
 if(a_A[0]==344288375){ goto a_G9;}
 if(a_A[0]==344288381||a_A[0]==344288366){ goto a_G12;}
 if(a_A[0]==344288363||a_A[0]==344288390){  goto a_G15;}
  return 0;}
a_G3:if(!__equal(a_F1,0)){ return 0;}
a_A[1]=1;
a_G5:__incr(a_1035); return 1;
a_G6:if(!__lseq(a_F1,1)){ return 0;}
a_A[1]=2; goto a_G5;
a_G9:if(!__lseq(a_F1,2)){ return 0;}
a_A[1]=3; goto a_G5;
a_G12:if(!__lseq(a_F1,3)){ return 0;}
a_A[1]=4; goto a_G5;
a_G15:if(!__lseq(a_F1,4)){ return 0;}
a_A[1]=5; goto a_G5;
} /* Eop */
static void a_1079(int a_F1,int a_F2,int a_A[1]){ /* optor+>a+>a+>a> */

 static char *a_rulename="optor";
{ if(a_F1==344288396){ goto a_G2;}
 if(a_F1==344288345){ goto a_G3;}
 if(a_F1==344288375){ goto a_G4;}
 if(a_F1==344288381){ goto a_G5;}
 if(a_F1==344288366){ goto a_G6;}
 if(a_F1==344288390){ goto a_G7;}
 if(!(a_F1==344288363)){a_area_failed(a_rulename,a_F1);}
  goto a_G8;}
a_G2:__boolxor(a_A[0],a_F2,a_A[0]);return;
a_G3:__booland(a_A[0],a_F2,a_A[0]);return;
a_G4:__boolor(a_A[0],a_F2,a_A[0]);return;
a_G5:__add(a_A[0],a_F2,a_A[0]);return;
a_G6:__subtr(a_A[0],a_F2,a_A[0]);return;
a_G7:__mult(a_A[0],a_F2,a_A[0]);return;
a_G8:__div(a_A[0],a_F2,a_A[0]);return;
} /* optor */
static int a_1064(int a_A[1]){ /* loosebase+a> */
int a_P[1];
if(!a_1011(344288372)){ goto a_G4;}
if(!a_1068(0,a_P)){ return 0;}a_A[0]=a_P[0];
if(!a_1011(344288351)){ return 0;} return 1;
a_G4:if(!a_1011(344288400)){ goto a_G7;}
a_A[0]=to_LIST(a_1012)->offset[a_1035];
a_G6:__incr(a_1035); return 1;
a_G7:if(!a_1011(344288360)){ goto a_G10;}
if(!a_1064(a_P)){ return 0;}a_A[0]=a_P[0];
__boolinvert(a_A[0],a_A[0]); return 1;
a_G10:if(!a_1011(344288366)){ goto a_G13;}
if(!a_1064(a_P)){ return 0;}a_A[0]=a_P[0];
__subtr(0,a_A[0],a_A[0]); return 1;
a_G13:if(!a_1011(344288192)){ goto a_G16;}
a_1048(to_LIST(a_1012)->offset[a_1035],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G16:if(!a_1013(a_P)){ return 0;}a_A[0]=a_P[0];
if(!__equal(to_LIST(a_1015)->offset[a_A[0]-4],344288252)){ return 0;}
a_1066(a_A[0]);
if(!a_1060(a_A[0],32)){ return 0;}
a_A[0]=to_LIST(a_1015)->offset[a_A[0]]; return 1;
} /* loosebase */
static int a_1068(int a_F1,int a_A[1]){ /* looseexpr+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[2];
if(!a_1064(a_P)){ return 0;}a_A[0]=a_P[0];
a_G2:if(!a_1014(a_F1,a_P)){ return 1;}a_L3=a_P[0];a_L4=a_P[1];
if(!a_1068(a_L4,a_P)){ return 0;}a_L5=a_P[0];
a_P[0]=a_A[0];a_1079(a_L3,a_L5,a_P);a_A[0]=a_P[0]; goto a_G2;
} /* looseexpr */
static void a_1090(int a_F1,int a_F2,int a_F3){ /* setfinalvalue+>a+>a+>a */

a_1027(a_F2,64);
to_LIST(a_1015)->offset[a_F2]=a_F1;
a_1091(a_F2,32);
if(__equal(a_F2,a_F3)){return;}
to_LIST(a_1015)->offset[a_F3]=a_F1;
a_1091(a_F3,32);return;
} /* setfinalvalue */
static void a_1066(int a_F1){ /* looseeval+>a */
int a_L2;int a_L3;int a_L4;int a_P[3];
if(a_1060(a_F1,32)){return;}
if(a_1053(a_F1,a_P)){a_L2=a_P[0]; goto a_G4;}
a_L2=a_F1;
a_G4:if(!a_1060(a_L2,64)){ goto a_G7;}
a_P[0]=1922290613;a_P[1]=to_LIST(a_1015)->offset[a_L2-3];a_P[2]=a_L2;a_1036(3,a_P);
a_1090(0,a_L2,a_F1);return;
a_G7:a_1091(a_L2,64);
a_L3=a_1035;
a_1035=to_LIST(a_1015)->offset[a_L2-1];
__incr(a_1035);
if(__was(a_1012,a_1035)){ goto a_G13;}
a_1030(a_1001,16777232,321);return;
a_G13:if(!a_1068(0,a_P)){ goto a_G15;}a_L4=a_P[0];
a_1090(a_L4,a_L2,a_F1); goto a_G16;
a_G15:a_1027(a_L2,64);
a_G16:a_1035=a_L3;return;
} /* looseeval */
static void a_1067(void){ /* looseevaluation */
int a_L1;
if(a_1099()){return;}
a_L1=a_1061;
a_G3:if(__equal(a_L1,0)){return;}
a_1066(to_LIST(a_1012)->offset[a_L1]);
__incr(a_L1);
a_L1=to_LIST(a_1012)->offset[a_L1]; goto a_G3;
} /* looseevaluation */
static void a_1051(int a_F1,int a_F2,int a_A[1]){ /* getexprlimit+>a+>a+a> */
int a_P[1];
if(a_1053(a_F2,a_P)){a_F2=a_P[0];}
if(!__equal(a_F1,344288217)){ goto a_G4;}
a_1055(a_F2,a_P);a_A[0]=a_P[0];return;
a_G4:a_1056(a_F2,a_P);a_A[0]=a_P[0];return;
} /* getexprlimit */
static void a_1042(int a_A[1]){ /* finalbase+a> */
int a_P[1];
if(!a_1011(344288372)){ goto a_G4;}
a_1045(0,a_P);a_A[0]=a_P[0];
if(!a_1011(344288351)){return;}return;
a_G4:if(!a_1011(344288400)){ goto a_G7;}
a_A[0]=to_LIST(a_1012)->offset[a_1035];
a_G6:__incr(a_1035);return;
a_G7:if(!a_1011(344288360)){ goto a_G10;}
a_1042(a_P);a_A[0]=a_P[0];
__boolinvert(a_A[0],a_A[0]);return;
a_G10:if(!a_1011(344288366)){ goto a_G13;}
a_1042(a_P);a_A[0]=a_P[0];
__subtr(0,a_A[0],a_A[0]);return;
a_G13:if(!a_1011(344288192)){ goto a_G17;}
a_A[0]=to_LIST(a_1012)->offset[a_1035];
a_1048(a_A[0],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G17:if(!a_1011(344288217)){ goto a_G20;}
a_1051(344288217,to_LIST(a_1012)->offset[a_1035],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G20:if(!a_1011(344288239)){ goto a_G23;}
a_1051(344288239,to_LIST(a_1012)->offset[a_1035],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G23:if(!a_1013(a_P)){ goto a_G26;}a_A[0]=a_P[0];
a_1043(a_A[0]);
a_A[0]=to_LIST(a_1015)->offset[a_A[0]];return;
a_G26:a_1030(a_1001,16777228,346);return;
} /* finalbase */
static void a_1045(int a_F1,int a_A[1]){ /* finalexpr+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[2];
a_1042(a_P);a_A[0]=a_P[0];
a_G2:if(!a_1014(a_F1,a_P)){return;}a_L3=a_P[0];a_L4=a_P[1];
a_1045(a_L4,a_P);a_L5=a_P[0];
a_P[0]=a_A[0];a_1079(a_L3,a_L5,a_P);a_A[0]=a_P[0]; goto a_G2;
} /* finalexpr */
static void a_1043(int a_F1){ /* finaleval+>a */
int a_L2;int a_L3;int a_L4;int a_P[3];
if(a_1060(a_F1,32)){return;}
if(a_1053(a_F1,a_P)){a_L2=a_P[0]; goto a_G4;}
a_L2=a_F1;
a_G4:if(!a_1060(a_L2,32)){ goto a_G7;}
to_LIST(a_1015)->offset[a_F1]=to_LIST(a_1015)->offset[a_L2];
a_1091(a_F1,32);return;
a_G7:if(!a_1060(a_L2,64)){ goto a_G10;}
a_P[0]=1922290613;a_P[1]=to_LIST(a_1015)->offset[a_L2-3];a_P[2]=a_F1;a_1036(3,a_P);
a_1090(0,a_L2,a_F1);return;
a_G10:a_1091(a_L2,64);
a_L4=a_1035;
a_1035=to_LIST(a_1015)->offset[a_L2-1];
__incr(a_1035);
if(__was(a_1012,a_1035)){ goto a_G16;}
a_1030(a_1001,16777224,358);return;
a_G16:a_1045(0,a_P);a_L3=a_P[0];
a_1035=a_L4;
a_1090(a_L3,a_L2,a_F1);return;
} /* finaleval */
static void a_1044(void){ /* finalevaluation */
int a_L1;
a_L1=a_1061;
a_G2:if(__equal(a_L1,0)){ goto a_G6;}
a_1043(to_LIST(a_1012)->offset[a_L1]);
__incr(a_L1);
a_L1=to_LIST(a_1012)->offset[a_L1]; goto a_G2;
a_G6:a_1061=0;
a_release(a_1012);return;
} /* finalevaluation */
static void a_1028(int a_F1){ /* clearreprfield+>a */
int a_L2;int a_P[1];
if(a_1053(a_F1,a_P)){a_L2=a_P[0]; goto a_G3;}
a_L2=a_F1;
a_G3:if(!a_1060(a_L2,32)){return;}
a_1027(a_L2,32);
a_1027(a_F1,32);
to_LIST(a_1015)->offset[a_L2-1]=to_LIST(a_1015)->offset[a_L2];
to_LIST(a_1015)->offset[a_L2]=0;to_LIST(a_1015)->offset[a_F1]=0;return;
} /* clearreprfield */
static void a_1019(int a_F1){ /* assign+>a */
int a_L2;int a_L3;int a_P[1];
if(a_1053(a_F1,a_P)){a_L2=a_P[0]; goto a_G3;}
a_L2=a_F1;
a_G3:a_L3=to_LIST(a_1015)->offset[a_L2];
if(__more(a_L3,0)){ goto a_G7;}
__incr(a_1077);
a_L3=a_1077;to_LIST(a_1015)->offset[a_L2]=a_1077;
a_G7:if(__equal(a_F1,a_L2)){return;}
to_LIST(a_1015)->offset[a_F1]=a_L3;return;
} /* assign */
static void a_1020(void){ /* assignreprnumbers */
int a_L1;
a_L1=to_LIST(a_1015)->alwb;
a_G2:if(__more(a_L1,to_LIST(a_1015)->aupb)){return;}
{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288257||a_r1==344288262){ goto a_G4;}
 if(a_r1==344288297||a_r1==344288266||a_r1==344288270||a_r1==344288276||a_r1==344288288||a_r1==344288293){  goto a_G5;}
  goto a_G7;}
a_G4:a_1028(a_L1);
a_G5:a_1019(a_L1);
a_G7:__next(a_1015,a_L1); goto a_G2;
} /* assignreprnumbers */
static void a_1009(void){ /* @root */

} /* @root */
static void a_1123(int a_F1){ /* printchar+>a */

__incr(a_1131);
a_putchar(a_1103,a_F1);return;
} /* printchar */
static void a_1120(void){ /* nlcr */

if(!__lseq(a_1131,1)){ goto a_G3;}
a_1131=1;return;
a_G3:a_1131=0;
a_1123(10);return;
} /* nlcr */
static void a_1137(int a_F1){ /* tabline+>a */

a_G1:if(__equal(a_1131,a_F1)){return;}
if(!__more(a_1131,a_F1)){ goto a_G4;}
a_1120(); goto a_G1;
a_G4:a_1123(32); goto a_G1;
} /* tabline */
static void a_1126(int a_F1){ /* printint+>a */

if(!__equal(a_F1,(-2147483647-1))){ goto a_G5;}
a_1123(45);
__subtr(-1,a_F1,a_F1);
a_1127(a_F1,49);return;
a_G5:if(!__less(a_F1,0)){ goto a_G8;}
a_1123(45);
__getabs(a_F1,a_F1);
a_G8:a_1127(a_F1,48);return;
} /* printint */
static void a_1127(int a_F1,int a_F2){ /* printint1+>a+>a */
int a_L3;int a_L4;
_divrem11(a_F1,10,a_L3,a_L4);
if(__equal(a_L3,0)){ goto a_G4;}
a_1127(a_L3,48);
a_G4:__add(a_L4,a_F2,a_L4);
a_1123(a_L4);return;
} /* printint1 */
static void a_1124(int a_F1){ /* printform+>a */

a_1125(a_F1,4);return;
} /* printform */
static void a_1125(int a_F1,int a_F2){ /* printform1+>a+>a */
int a_L3;int a_L4;
if(__equal(a_F2,0)){return;}
__decr(a_F2);
_divrem11(a_F1,10,a_L3,a_L4);
a_1125(a_L3,a_F2);
__add(a_L4,48,a_L4);
a_1123(a_L4);return;
} /* printform1 */
static void a_1121(int a_F1,int a_F2){ /* print+t[]+>a */
int a_L2;
if(!__was(a_F1,a_F2)){return;}
a_1133(a_1103,a_F1,a_F2);
__stringlength(a_F1,a_F2,a_L2);
__add(a_1131,a_L2,a_1131);return;
} /* print */
static void a_1130(int a_F1){ /* printpointer+>a */
int a_P[1];
if(!__equal(a_F1,0)){ goto a_G3;}
a_1121(a_1001,16777303);return;
a_G3:if(!__was(a_1017,a_F1)){ goto a_G5;}
a_1121(a_1017,a_F1);return;
a_G5:if(!__was(a_1104,a_F1)){ goto a_G7;}
a_1121(a_1104,a_F1);return;
a_G7:if(!__was(a_1016,a_F1)){ goto a_G10;}
a_1116(a_F1,a_P);a_F1=a_P[0];
a_1121(a_1016,a_F1);return;
a_G10:a_1117(a_1001,16777299,81);return;
} /* printpointer */
static void a_1122(int a_F1){ /* printbase+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=to_LIST(a_1010)->aupb;
if(!__was(a_1016,a_F1)){ goto a_G5;}
a_1116(a_F1,a_P);a_F1=a_P[0];
a_unpackstring(a_1016,a_F1,a_1010); goto a_G8;
a_G5:if(!__was(a_1104,a_F1)){ goto a_G7;}
a_unpackstring(a_1104,a_F1,a_1010); goto a_G8;
a_G7:a_1117(a_1001,16777293,88);return;
a_G8:a_L3=to_LIST(a_1010)->aupb;
a_G9:if(__lseq(a_L3,a_L2)){ goto a_G14;}
if(__equal(to_LIST(a_1010)->offset[a_L3],47)){ goto a_G14;}
if(__equal(to_LIST(a_1010)->offset[a_L3],92)){ goto a_G14;}
if(__equal(to_LIST(a_1010)->offset[a_L3],58)){ goto a_G14;}
__decr(a_L3); goto a_G9;
a_G14:__incr(a_L3);
if(__more(a_L3,to_LIST(a_1010)->aupb)){ goto a_G19;}
if(__equal(to_LIST(a_1010)->offset[a_L3],46)){ goto a_G19;}
a_1123(to_LIST(a_1010)->offset[a_L3]); goto a_G14;
a_G19:__unstackto(a_1010,a_L2);return;
} /* printbase */
static void a_1128(int a_F1){ /* printitem+>a */
int a_L2;int a_L3;int a_L4;int a_P[3];
a_1111(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];
if(__lseq(a_L2,0)){ goto a_G4;}
a_1124(a_L2);
a_G4:if(__equal(a_L3,374062088)){ goto a_G7;}
a_1123(47);
a_1122(a_L3);
a_G7:a_1123(32);
a_1123(40);
a_1130(a_L4);
a_1123(41);return;
} /* printitem */
static void a_1129(int a_F1){ /* printline+>a */
int a_L2;int a_L3;int a_P[2];
a_1112(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];
if(__lseq(a_L2,0)){ goto a_G4;}
a_1124(a_L2);
a_G4:if(__equal(a_L3,374062088)){return;}
a_1123(47);
a_1122(a_L3);return;
} /* printline */
static void a_1113(int a_C,int *a_V){ /* formatprint+*+>a */
int a_L2;int a_L3;
a_L2=to_LIST(a_1010)->aupb;
a_unpackstring(a_1017,a_V[0],a_1010);
__add(a_L2,1,a_L3);
a_G4:if(__less(to_LIST(a_1010)->aupb,a_L3)){ goto a_G32;}
if(!__noteq(to_LIST(a_1010)->offset[a_L3],37)){ goto a_G8;}
a_G6:a_1123(to_LIST(a_1010)->offset[a_L3]);
a_G7:__incr(a_L3); goto a_G4;
a_G8:__incr(a_L3);
if(!__less(to_LIST(a_1010)->aupb,a_L3)){ goto a_G11;}
a_1123(37); goto a_G32;
a_G11:{register int a_r1=to_LIST(a_1010)->offset[a_L3];
 if(a_r1==112){ goto a_G12;}
 if(a_r1==105){ goto a_G16;}
 if(a_r1==108){ goto a_G20;}
 if(a_r1==100){ goto a_G24;}
 if(a_r1==110){  goto a_G28;}
  goto a_G6;}
a_G12:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1130(a_V[0]); goto a_G7;
a_G14:a_1121(a_1001,16777288); goto a_G7;
a_G16:if(a_C<=1){ goto a_G18;} a_C--;a_V+=1;
a_1128(a_V[0]); goto a_G7;
a_G18:a_1121(a_1001,16777285); goto a_G7;
a_G20:if(a_C<=1){ goto a_G22;} a_C--;a_V+=1;
a_1129(a_V[0]); goto a_G7;
a_G22:a_1121(a_1001,16777282); goto a_G7;
a_G24:if(a_C<=1){ goto a_G26;} a_C--;a_V+=1;
a_1126(a_V[0]); goto a_G7;
a_G26:a_1121(a_1001,16777279); goto a_G7;
a_G28:a_1123(10); goto a_G7;
a_G32:if(a_C<=1){ goto a_G34;} a_C--;a_V+=1;
a_1121(a_1001,16777276);
a_G34:__unstackto(a_1010,a_L2);return;
} /* formatprint */
static int a_1099(void){ /* waserror */

if(!__more(a_1108,0)){ return 0;} return 1;
} /* waserror */
static void a_1119(int a_F1){ /* messagehead+>a */
int a_L2;int a_P[1];
a_1120();
a_1123(a_F1);
a_1123(32);
a_1115(a_P);a_L2=a_P[0];
if(__equal(a_L2,0)){ goto a_G7;}
a_1122(a_L2);
a_G7:if(!__equal(a_F1,70)){ goto a_G10;}
a_1123(47);
a_1124(a_1134);
a_G10:a_1123(32);
a_1137(16);return;
} /* messagehead */
static void a_1036(int a_C,int *a_V){ /* error+*+>a */
int a_P[1];
if(__mreq(a_1108,51)){return;}
a_1119(69);
a_1113(a_C,a_V);
a_1120();
__incr(a_1108);
if(__less(a_1108,51)){return;}
a_1119(70);
a_P[0]=1922290628;a_1113(1,a_P);
a_1120();return;
} /* error */
static void a_1097(int a_C,int *a_V){ /* warning+*+>a */

if(__mreq(a_1108,51)){return;}
a_1119(87);
a_1113(a_C,a_V);
a_1120();return;
} /* warning */
static void a_1118(int a_C,int *a_V){ /* message+*+>a */

a_1113(a_C,a_V);
a_1120();
__incr(a_1108);return;
} /* message */
static void a_1110(int a_C,int *a_V){ /* fatalerror+*+>a */

a_1119(70);
a_1113(a_C,a_V);
a_1120();
a_1106();
exit(3);return;
} /* fatalerror */
static void a_1030(int a_F1,int a_F2,int a_F3){ /* corruptedicefile+t[]+>a+>a */
int a_L3;int a_P[3];
a_1119(70);
a_1115(a_P);a_L3=a_P[0];
a_P[0]=1922290652;a_P[1]=a_L3;a_P[2]=a_F3;a_1113(3,a_P);
a_1121(a_F1,a_F2);
a_P[0]=1922290657;a_1113(1,a_P);
a_1120();
a_1106();
exit(3);return;
} /* corruptedicefile */
static void a_1117(int a_F1,int a_F2,int a_F3){ /* internalerror+t[]+>a+>a */
int a_P[2];
a_1119(70);
a_P[0]=1922290636;a_1113(1,a_P);
a_1121(a_F1,a_F2);
a_P[0]=1922290643;a_P[1]=a_F3;a_1113(2,a_P);
a_1120();
a_1106();
exit(64);return;
} /* internalerror */
static void a_1102(void){ /* @root */

} /* @root */
static void a_1133(int a_F1,int a_F2,int a_F3){ /* putstring+""f+t[]+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=0;
a_G2:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){return;}a_L3=a_P[0];
__incr(a_L2);
a_putchar(a_F1,a_L3); goto a_G2;
} /* putstring */
static void a_1148(int a_F1){ /* extendBUFFER+>a */

 a_extension(a_1010,1);to_LIST(a_1010)->top[1]=a_F1;to_LIST(a_1010)->aupb+=1;
 return;
} /* extendBUFFER */
static void a_1141(void){ /* addextension */
int a_L1;
__scratch(a_1010);
a_unpackstring(a_1104,a_1142,a_1010);
a_1148(46);
a_1148(105);
a_1148(99);
a_1148(101);
__listlength(a_1010,a_L1);
a_packstring(a_1010,a_L1,a_1016);
__scratch(a_1010);return;
} /* addextension */
static int a_1154(void){ /* nextargument */

if(!__equal(a_1142,0)){ goto a_G3;}
a_1142=a_1143; return 1;
a_G3:if(!__mreq(a_1142,to_LIST(a_1104)->alwb)){ return 0;}
__previousstring(a_1104,a_1142);
if(!__mreq(a_1142,to_LIST(a_1104)->alwb)){ return 0;} return 1;
} /* nextargument */
static void a_1157(int a_A[1]){ /* openasitis+a> */
int a_P[1];
a_1166=1;
a_copystring(a_1104,a_1142,a_1016);
a_1164(a_P);a_A[0]=a_P[0];
__unstackstring(a_1016);return;
} /* openasitis */
static void a_1158(int a_A[1]){ /* openwithextension+a> */
int a_P[1];
a_1166=2;
a_1141();
a_1164(a_P);a_A[0]=a_P[0];
__unstackstring(a_1016);return;
} /* openwithextension */
static void a_1156(int a_F1){ /* openargument+>a */
int a_L2;int a_P[2];
if(!__equal(a_F1,1)){ goto a_G3;}
a_1157(a_P);a_L2=a_P[0]; goto a_G8;
a_G3:if(!__equal(a_F1,2)){ goto a_G5;}
a_G4:a_1158(a_P);a_L2=a_P[0]; goto a_G8;
a_G5:a_1157(a_P);a_L2=a_P[0];
if(!__noteq(a_L2,1)){ goto a_G4;}
a_G8:if(__equal(a_L2,0)){return;}
a_P[0]=1922290692;a_P[1]=a_1142;a_1110(2,a_P);return;
} /* openargument */
static int a_1151(int a_F1,int a_F2){ /* isfirstarg+t[]+>a */
int a_L2;int a_P[1];
a_comparestring(a_1104,to_LIST(a_1104)->aupb,a_F1,a_F2,a_P);a_L2=a_P[0];
if(!__equal(a_L2,0)){ return 0;} return 1;
} /* isfirstarg */
static void a_1144(void){ /* checkarguments */
int a_P[3];
if(!__less(to_LIST(a_1104)->aupb,to_LIST(a_1104)->alwb)){ goto a_G3;}
a_G2:a_P[0]=1922290673;a_1036(1,a_P);return;
a_G3:if(!a_1151(a_1001,16777323)){ goto a_G5;}
a_P[0]=1922290945;a_1118(1,a_P);return;
a_G5:if(!a_1151(a_1001,16777319)){ goto a_G7;}
a_P[0]=1922291003;a_P[1]=1;a_P[2]=0;a_1118(3,a_P);return;
a_G7:if(!a_1151(a_1001,16777314)){ goto a_G16;}
a_1143=to_LIST(a_1104)->aupb;
__previousstring(a_1104,a_1143);
if(!__less(a_1143,to_LIST(a_1104)->alwb)){ goto a_G12;}
a_P[0]=1922290681;a_1036(1,a_P);return;
a_G12:a_1163=a_1143;
__previousstring(a_1104,a_1143);
if(!__less(a_1143,to_LIST(a_1104)->alwb)){return;} goto a_G2;
a_G16:a_1143=to_LIST(a_1104)->aupb;return;
} /* checkarguments */
static void a_1162(void){ /* settargetfile */

a_1153=a_1142;return;
} /* settargetfile */
static void a_1149(void){ /* gettargetfile */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;
if(!__is(a_1163)){ goto a_G4;}
a_L5=0;
a_L2=a_1163; goto a_G6;
a_G4:a_L5=1;
a_L2=a_1153;
a_G6:a_L1=to_LIST(a_1010)->aupb;
a_unpackstring(a_1104,a_L2,a_1010);
a_L4=to_LIST(a_1010)->aupb;
a_G9:if(__lseq(a_L4,a_L1)){ goto a_G19;}
{register int a_r1=to_LIST(a_1010)->offset[a_L4];
 if(a_r1==46){ goto a_G11;}
 if(a_r1==47||a_r1==92||a_r1==58){  goto a_G16;}
  goto a_G18;}
a_G11:if(!__equal(a_L5,0)){ goto a_G14;}
a_L5=2;
a_G13:a_L4=a_L1; goto a_G19;
a_G14:__decr(a_L4);
__unstackto(a_1010,a_L4); goto a_G9;
a_G16:if(__equal(a_L5,1)){ goto a_G19;} goto a_G13;
a_G18:__decr(a_L4); goto a_G9;
a_G19:if(__equal(a_L5,2)){ goto a_G22;}
a_1148(46);
a_1148(99);
a_G22:__subtr(to_LIST(a_1010)->aupb,a_L4,a_L3);
a_packstring(a_1010,a_L3,a_1016);
__unstackto(a_1010,a_L1);return;
} /* gettargetfile */
static int a_1155(int a_F1,int a_A[1]){ /* nextsource+>a+a> */

if(!a_1154()){ goto a_G5;}
a_1145();
a_1156(a_F1);
a_A[0]=a_1166; return 1;
a_G5:a_1145();
a_1142=0; return 0;
} /* nextsource */
static void a_1115(int a_A[1]){ /* geticefile+a> */

a_A[0]=a_1142;return;
} /* geticefile */
static void a_1140(void){ /* @root */

} /* @root */
static void a_1185(void){ /* expandITEM */

 a_extension(a_1015,6);to_LIST(a_1015)->top[1]=to_LIST(a_1015)->top[2]=to_LIST(a_1015)->top[3]=to_LIST(a_1015)->top[4]=to_LIST(a_1015)->top[5]=to_LIST(a_1015)->top[6]=0;to_LIST(a_1015)->aupb+=6;
 return;
} /* expandITEM */
static int a_1060(int a_F1,int a_F2){ /* isitemflag+>a+>a */
int a_L3;
__booland(to_LIST(a_1015)->offset[a_F1-5],a_F2,a_L3);
if(!__is(a_L3)){ return 0;} return 1;
} /* isitemflag */
static void a_1091(int a_F1,int a_F2){ /* setitemflag+>a+>a */

__boolor(to_LIST(a_1015)->offset[a_F1-5],a_F2,to_LIST(a_1015)->offset[a_F1-5]);return;
} /* setitemflag */
static void a_1027(int a_F1,int a_F2){ /* clearitemflag+>a+>a */
int a_L3;
__boolinvert(a_F2,a_L3);
__booland(a_L3,to_LIST(a_1015)->offset[a_F1-5],to_LIST(a_1015)->offset[a_F1-5]);return;
} /* clearitemflag */
static int a_1053(int a_F1,int a_A[1]){ /* getitemdef+>a+a> */
int a_P[1];
if(!a_1060(a_F1,24)){ return 0;}
a_1195(to_LIST(a_1015)->offset[a_F1-3],a_P);a_A[0]=a_P[0]; return 1;
} /* getitemdef */
static void a_1183(void){ /* converttoitem */

__addmult(a_1059,6,a_1175,a_1059);return;
} /* converttoitem */
static void a_1202(int a_F1){ /* pushAUX+>a */

 a_extension(a_1168,1);to_LIST(a_1168)->top[1]=a_F1;to_LIST(a_1168)->aupb+=1;
 return;
} /* pushAUX */
static int a_1210(int a_F1,int a_F2){ /* stacksizemismatch+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_1194(a_F1,a_P);a_L3=a_P[0];
a_1194(a_F2,a_P);a_L4=a_P[0];
if(__noteq(a_L3,a_L4)){ return 1;}
a_1048(a_F1,a_P);a_L3=a_P[0];
a_1048(a_F2,a_P);a_L4=a_P[0];
if(!__noteq(a_L3,a_L4)){ return 0;} return 1;
} /* stacksizemismatch */
static int a_1213(int a_F1,int a_F2){ /* unequaltypes+>a+>a */

if(__equal(a_F1,a_F2)){ return 0;}
if(!__equal(a_F1,344288252)){ goto a_G4;}
if(!__equal(a_F2,344288283)){ return 0;} return 0;
a_G4:if(!__equal(a_F1,344288283)){ return 1;}
if(!__equal(a_F2,344288252)){ return 0;} return 0;
} /* unequaltypes */
static int a_1197(int a_F1,int a_F2){ /* incompatibletypes+>a+>a */
int a_L3;
a_L3=to_LIST(a_1015)->offset[a_F1-4];
if(a_1213(a_L3,to_LIST(a_1015)->offset[a_F2-4])){ return 1;}
if(!__equal(a_L3,344288297)){ goto a_G5;}
if(!__noteq(to_LIST(a_1015)->offset[a_F1-1],to_LIST(a_1015)->offset[a_F2-1])){ return 0;} return 1;
a_G5:if(__equal(a_L3,344288270)){ goto a_G8;}
if(__equal(a_L3,344288266)){ goto a_G8;}
if(!__equal(a_L3,344288276)){ return 0;}
a_G8:if(!a_1210(a_F1,a_F2)){ return 0;} return 1;
} /* incompatibletypes */
static void a_1177(int a_F1,int a_F2,int a_F3){ /* checkcompatibility+>a+>a+>a */
int a_P[4];
if(!a_1197(a_F2,a_F3)){ goto a_G3;}
a_P[0]=1922290703;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_F3;a_1036(4,a_P);return;
a_G3:if(!a_1060(a_F2,16)){ goto a_G6;}
if(a_1060(a_F3,16)){return;}
a_P[0]=1922290714;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_F3;a_1036(4,a_P);return;
a_G6:if(!a_1060(a_F3,16)){ goto a_G8;}
a_P[0]=1922290714;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_F2;a_1036(4,a_P);return;
a_G8:if(!a_1060(a_F2,4)){ goto a_G11;}
if(!a_1060(a_F3,4)){return;}
a_P[0]=1922290724;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_F3;a_1036(4,a_P);return;
a_G11:if(!a_1060(a_F3,4)){return;}
a_1203(a_F1,a_F3);return;
} /* checkcompatibility */
static void a_1184(int a_F1){ /* enteritem+>a */
int a_L2;int a_L3;int a_P[1];
if(!a_1060(a_F1,28)){return;}
a_L2=to_LIST(a_1015)->offset[a_F1-3];
a_1195(a_L2,a_P);a_L3=a_P[0];
if(!__equal(a_L3,0)){ goto a_G6;}
a_1203(a_L2,a_F1);return;
a_G6:a_1177(a_L2,a_L3,a_F1);return;
} /* enteritem */
static void a_1048(int a_F1,int a_A[1]){ /* getcalibre+>a+a> */

a_A[0]=to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]-2];return;
} /* getcalibre */
static void a_1194(int a_F1,int a_A[1]){ /* getssel+>a+a> */

a_A[0]=to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]-1];return;
} /* getssel */
static void a_1056(int a_F1,int a_A[1]){ /* getvupb+>a+a> */

a_A[0]=to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]-4];return;
} /* getvupb */
static void a_1055(int a_F1,int a_A[1]){ /* getvlwb+>a+a> */

a_A[0]=to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]-5];return;
} /* getvlwb */
static void a_1052(int a_F1,int a_A[1]){ /* getfill+>a+a> */

a_A[0]=to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]-3];return;
} /* getfill */
static void a_1054(int a_F1,int a_A[1]){ /* getlistlink+>a+a> */

a_A[0]=to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]];return;
} /* getlistlink */
static void a_1083(int a_F1,int a_F2){ /* putvlwb+>a+>a */

to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]-5]=a_F2;return;
} /* putvlwb */
static void a_1084(int a_F1,int a_F2){ /* putvupb+>a+>a */

to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]-4]=a_F2;return;
} /* putvupb */
static void a_1081(int a_F1,int a_F2){ /* putfill+>a+>a */

to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]-3]=a_F2;return;
} /* putfill */
static void a_1082(int a_F1,int a_F2){ /* putlistlink+>a+>a */

to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]]=a_F2;return;
} /* putlistlink */
static void a_1192(int a_F1,int a_A[1]){ /* getnumberofformals+>a+a> */

a_A[0]=to_LIST(a_1168)->offset[to_LIST(a_1015)->offset[a_F1-1]-2];return;
} /* getnumberofformals */
static void a_1191(int a_F1,int a_F2,int a_A[1]){ /* getformal+>a+>a+a> */
int a_L4;
a_L4=to_LIST(a_1015)->offset[a_F1-1];
if(!__mreq(a_F2,to_LIST(a_1168)->offset[a_L4-2])){ goto a_G4;}
a_A[0]=0;return;
a_G4:__incr(a_L4);
__add(a_F2,a_L4,a_L4);
a_A[0]=to_LIST(a_1168)->offset[a_L4];return;
} /* getformal */
static void a_1193(int a_F1,int a_A[1]){ /* getrepeatcount+>a+a> */
int a_L3;int a_L4;
a_A[0]=0;
a_L3=to_LIST(a_1015)->offset[a_F1-1];
a_L4=to_LIST(a_1168)->offset[a_L3-2];
a_G4:if(__equal(a_L4,0)){return;}
__decr(a_L4);
__incr(a_L3);
if(!__equal(to_LIST(a_1168)->offset[a_L3],344288336)){ goto a_G4;}
a_A[0]=a_L4;return;
} /* getrepeatcount */
static void a_1189(int a_F1,int a_A[3]){ /* getfiledata+>a+a>+a>+a> */
int a_L5;
a_L5=to_LIST(a_1015)->offset[a_F1-1];
a_A[0]=to_LIST(a_1168)->offset[a_L5-1];
a_A[1]=to_LIST(a_1168)->offset[a_L5-2];
a_A[2]=to_LIST(a_1168)->offset[a_L5];return;
} /* getfiledata */
static void a_1190(int a_A[3]){ /* getfilelink+>a>+a>+a> */

if(!__equal(a_A[0],0)){ goto a_G3;}
a_A[2]=0;a_A[1]=0;return;
a_G3:a_A[1]=to_LIST(a_1168)->offset[a_A[0]-2];
a_A[2]=to_LIST(a_1168)->offset[a_A[0]-1];
a_A[0]=to_LIST(a_1168)->offset[a_A[0]];return;
} /* getfilelink */
static int a_1182(int a_F1,int a_F2){ /* compareformals+>a+>a */
int a_L3;
if(!__equal(to_LIST(a_1168)->offset[a_F1-2],to_LIST(a_1168)->offset[a_F2-2])){ return 0;}
a_L3=to_LIST(a_1168)->offset[a_F1-1];
if(!__equal(to_LIST(a_1168)->offset[a_F2-1],a_L3)){ return 0;}
a_G4:if(__equal(a_L3,0)){ return 1;}
__incr(a_F1);
__incr(a_F2);
if(!__equal(to_LIST(a_1168)->offset[a_F1],to_LIST(a_1168)->offset[a_F2])){ return 0;}
__decr(a_L3); goto a_G4;
} /* compareformals */
static void a_1207(int a_F1,int a_A[1]){ /* searchformals+>a+>a> */
int a_L3;
a_L3=a_1200;
a_G2:if(!__equal(a_L3,0)){ goto a_G5;}
to_LIST(a_1168)->offset[a_A[0]]=a_1200;
a_1200=a_A[0];return;
a_G5:if(!a_1182(a_L3,a_A[0])){ goto a_G8;}
__unstackto(a_1168,a_F1);
a_A[0]=a_L3;return;
a_G8:a_L3=to_LIST(a_1168)->offset[a_L3]; goto a_G2;
} /* searchformals */
static void a_1188(int a_F1,int a_F2){ /* formalaffixes+>a+>a */
int a_L3;int a_L4;int a_L5;
a_G1:if(__equal(a_F2,0)){return;}
__decr(a_F2);
if(!__equal(344288404,a_1058)){ goto a_G6;}
a_L5=a_1059;
a_1078(); goto a_G7;
a_G6:a_1030(a_1001,16777327,44);return;
a_G7:a_1202(a_L5);
if(__equal(a_L5,344288303)){ goto a_G10;}
if(!__equal(a_L5,344288309)){ goto a_G1;}
a_G10:if(!__equal(344288400,a_1058)){ goto a_G6;}
a_L3=a_1059;
a_1078();
if(!__equal(344288400,a_1058)){ goto a_G6;}
a_L4=a_1059;
a_1078();
a_1188(a_F1,a_F2);
__incr(to_LIST(a_1168)->offset[a_F1-1]);
a_1202(a_L3);
__incr(to_LIST(a_1168)->offset[a_F1-1]);
a_1202(a_L4);return;
} /* formalaffixes */
static void a_1211(int a_A[1]){ /* storeformalaffixes+a> */
int a_L2;int a_L3;int a_P[1];
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L2=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777327,44);return;
a_G5:a_L3=to_LIST(a_1168)->aupb;
 a_extension(a_1168,3);to_LIST(a_1168)->top[1]=to_LIST(a_1168)->top[2]=a_L2;to_LIST(a_1168)->top[3]=0;to_LIST(a_1168)->aupb+=3;
a_A[0]=to_LIST(a_1168)->aupb;
a_1188(a_A[0],a_L2);
a_P[0]=a_A[0];a_1207(a_L3,a_P);a_A[0]=a_P[0];return;
} /* storeformalaffixes */
static void a_1212(int a_A[1]){ /* storelistbounds+a> */
int a_L2;int a_L3;
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L2=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777327,44);return;
a_G5:if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L3=a_1059;
a_1078();
 a_extension(a_1168,6);to_LIST(a_1168)->top[1]=to_LIST(a_1168)->top[2]=to_LIST(a_1168)->top[3]=0;to_LIST(a_1168)->top[4]=a_L2;to_LIST(a_1168)->top[5]=a_L3;to_LIST(a_1168)->top[6]=-1;to_LIST(a_1168)->aupb+=6;
a_A[0]=to_LIST(a_1168)->aupb;return;
} /* storelistbounds */
static void a_1179(int a_F1){ /* checkitemID+>a */

if(__equal(a_F1,to_LIST(a_1015)->aupb)){return;}
a_1030(a_1001,16777363,253);return;
} /* checkitemID */
static void a_1205(void){ /* readitem */
int a_L1;int a_L2;int a_L3;int a_P[1];
a_1185();
if(!__equal(344288404,a_1058)){ goto a_G5;}
to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-4]=a_1059;
a_1078(); goto a_G6;
a_G5:a_1030(a_1001,16777327,44);return;
a_G6:if(!__equal(344288412,a_1058)){ goto a_G5;}
a_L1=a_1059;
a_1078();
a_1179(a_L1);
if(!__equal(344288400,a_1058)){ goto a_G5;}
a_L2=a_1059;
a_1078();
__booland(a_L2,117540636,to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-5]);
if(!__equal(344288400,a_1058)){ goto a_G5;}
a_L3=a_1059;
a_1078();
if(__lseq(a_L3,0)){ goto a_G24;}
if(!__more(a_L3,a_1201)){ goto a_G23;}
a_1030(a_1001,16777359,261);return;
a_G23:to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-2]=a_L3;
a_G24:{register int a_r1=to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-4];
 if(a_r1==344288297){ goto a_G25;}
 if(a_r1==344288270||a_r1==344288266||a_r1==344288276){ goto a_G26;}
 if(a_r1==344288252||a_r1==344288257||a_r1==344288262||a_r1==344288283||a_r1==344288288||a_r1==344288293){  goto a_G28;}
  goto a_G27;}
a_G25:a_1211(a_P);to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1]=a_P[0]; goto a_G28;
a_G26:a_1212(a_P);to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1]=a_P[0]; goto a_G28;
a_G27:a_1030(a_1001,16777355,268);return;
a_G28:if(!__equal(344288424,a_1058)){ goto a_G5;}
to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-3]=a_1059;
a_1078();
a_1184(to_LIST(a_1015)->aupb);return;
} /* readitem */
static void a_1199(void){ /* itemsection */

if(a_1099()){return;}
a_G2:if(!__equal(344288384,a_1058)){ goto a_G4;}
a_1078();return;
a_G4:a_1205(); goto a_G2;
} /* itemsection */
static void a_1209(void){ /* skipitemsection */

a_G1:if(!__equal(344288384,a_1058)){ goto a_G3;}
a_1078();return;
a_G3:a_1078(); goto a_G1;
} /* skipitemsection */
static void a_1181(int a_F1,int a_F2){ /* checktype+>a+>a */

{register int a_r1=to_LIST(a_1015)->offset[a_F1-4];
 if(a_r1==344288288||a_r1==344288293){ goto a_G2;}
 if(a_r1==344288266||a_r1==344288270||a_r1==344288276){  goto a_G3;}
  goto a_G4;}
a_G2:if(!__noteq(a_F2,344288206)){return;} goto a_G4;
a_G3:if(!__noteq(a_F2,344288214)){return;}
a_G4:a_1030(a_1001,16777351,283);return;
} /* checktype */
static void a_1186(int a_F1){ /* filearea+>a */
int a_L2;int a_L3;
if(!__equal(344288393,a_1058)){return;}
a_1078();
a_G3:if(!__equal(344288348,a_1058)){ goto a_G5;}
a_1078();return;
a_G5:if(!__equal(344288412,a_1058)){ goto a_G8;}
a_L2=a_1059;
a_1078(); goto a_G9;
a_G8:a_1030(a_1001,16777327,44);return;
a_G9:a_1181(a_L2,344288214);
if(!__equal(344288400,a_1058)){ goto a_G8;}
a_L3=a_1059;
a_1078();
 a_extension(a_1168,3);to_LIST(a_1168)->top[1]=a_L3;to_LIST(a_1168)->top[2]=a_L2;to_LIST(a_1168)->top[3]=0;to_LIST(a_1168)->aupb+=3;
to_LIST(a_1168)->offset[a_F1]=to_LIST(a_1168)->aupb;
a_F1=to_LIST(a_1168)->aupb; goto a_G3;
} /* filearea */
static void a_1037(void){ /* fileentry */
int a_L1;int a_L2;int a_L3;
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777327,44);return;
a_G5:a_1181(a_L1,344288206);
 a_extension(a_1168,3);to_LIST(a_1168)->top[1]=to_LIST(a_1168)->top[2]=to_LIST(a_1168)->top[3]=0;to_LIST(a_1168)->aupb+=3;
{register int a_r1=to_LIST(a_1168)->aupb;a_L2=a_r1;to_LIST(a_1015)->offset[a_L1-1]=a_r1;}
a_1186(a_L2);
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L3=a_1059;
a_1078();
if(__equal(a_L3,1)){ goto a_G15;}
if(!__equal(a_L3,3)){ goto a_G16;}
a_G15:a_1091(a_L1,32);
a_G16:if(__equal(a_L3,2)){ goto a_G18;}
if(!__equal(a_L3,3)){ goto a_G19;}
a_G18:a_1091(a_L1,64);
a_G19:if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L3=a_1059;
a_1078();
to_LIST(a_1168)->offset[a_L2-1]=a_L3;
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L3=a_1059;
a_1078();
to_LIST(a_1168)->offset[a_L2-2]=a_L3;
if(!__equal(344288384,a_1058)){ goto a_G4;}

a_1078();return;
} /* fileentry */
static void a_1173(void){ /* addstdstring */

 a_extension(a_1168,6);to_LIST(a_1168)->top[1]=to_LIST(a_1168)->top[2]=to_LIST(a_1168)->top[3]=0;to_LIST(a_1168)->top[4]=to_LIST(a_1168)->top[5]=1;to_LIST(a_1168)->top[6]=-1;to_LIST(a_1168)->aupb+=6;
 a_extension(a_1015,6);to_LIST(a_1015)->top[1]=4;to_LIST(a_1015)->top[2]=344288266;to_LIST(a_1015)->top[4]=0;to_LIST(a_1015)->top[3]=374062061;to_LIST(a_1015)->top[5]=to_LIST(a_1168)->aupb;to_LIST(a_1015)->top[6]=0;to_LIST(a_1015)->aupb+=6;
a_1203(374062061,to_LIST(a_1015)->aupb);return;
} /* addstdstring */
static void a_1169(void){ /* addassignmentexternal */
int a_L1;int a_P[1];
a_L1=to_LIST(a_1168)->aupb;
 a_extension(a_1168,3);to_LIST(a_1168)->top[1]=to_LIST(a_1168)->top[2]=3;to_LIST(a_1168)->top[3]=0;to_LIST(a_1168)->aupb+=3;
 a_extension(a_1015,6);to_LIST(a_1015)->top[1]=98320;to_LIST(a_1015)->top[2]=344288297;to_LIST(a_1015)->top[4]=0;to_LIST(a_1015)->top[3]=374062067;to_LIST(a_1015)->top[5]=to_LIST(a_1168)->aupb;to_LIST(a_1015)->top[6]=0;to_LIST(a_1015)->aupb+=6;
a_1202(344288319);
a_1202(344288336);
a_1202(344288324);
a_P[0]=to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1];a_1207(a_L1,a_P);to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1]=a_P[0];
a_1203(374062067,to_LIST(a_1015)->aupb);return;
} /* addassignmentexternal */
static void a_1172(void){ /* addshiftaffixexternal */
int a_L1;int a_P[1];
a_L1=to_LIST(a_1168)->aupb;
 a_extension(a_1168,3);to_LIST(a_1168)->top[1]=to_LIST(a_1168)->top[2]=1;to_LIST(a_1168)->top[3]=0;to_LIST(a_1168)->aupb+=3;
 a_extension(a_1015,6);to_LIST(a_1015)->top[1]=772;to_LIST(a_1015)->top[2]=344288297;to_LIST(a_1015)->top[4]=0;to_LIST(a_1015)->top[3]=374062075;to_LIST(a_1015)->top[5]=to_LIST(a_1168)->aupb;to_LIST(a_1015)->top[6]=0;to_LIST(a_1015)->aupb+=6;
a_1202(344288342);
a_P[0]=to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1];a_1207(a_L1,a_P);to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1]=a_P[0];
a_1203(374062075,to_LIST(a_1015)->aupb);return;
} /* addshiftaffixexternal */
static void a_1170(void){ /* addgetaffixnoexternal */
int a_L1;int a_P[1];
a_L1=to_LIST(a_1168)->aupb;
 a_extension(a_1168,3);to_LIST(a_1168)->top[1]=to_LIST(a_1168)->top[2]=2;to_LIST(a_1168)->top[3]=0;to_LIST(a_1168)->aupb+=3;
 a_extension(a_1015,6);to_LIST(a_1015)->top[1]=4;to_LIST(a_1015)->top[2]=344288297;to_LIST(a_1015)->top[4]=0;to_LIST(a_1015)->top[3]=374062083;to_LIST(a_1015)->top[5]=to_LIST(a_1168)->aupb;to_LIST(a_1015)->top[6]=0;to_LIST(a_1015)->aupb+=6;
a_1202(344288324);
a_1202(344288342);
a_P[0]=to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1];a_1207(a_L1,a_P);to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1]=a_P[0];
a_1203(374062083,to_LIST(a_1015)->aupb);return;
} /* addgetaffixnoexternal */
static int a_1198(int a_F1,int a_A[1]){ /* isbuiltinrule+>a+a> */

{register int a_r1=to_LIST(a_1015)->offset[a_F1-3];
 if(a_r1==374062067){ goto a_G2;}
 if(a_r1==374062075){ goto a_G3;}
 if(a_r1==374062083){  goto a_G4;}
  return 0;}
a_G2:a_A[0]=1; return 1;
a_G3:a_A[0]=2; return 1;
a_G4:a_A[0]=3; return 1;
} /* isbuiltinrule */
static void a_1180(void){ /* checkmoduletitle */
int a_L1;int a_P[3];
a_L1=a_1187;
a_G2:if(__equal(a_L1,0)){return;}
if(!__equal(to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-4],344288233)){ goto a_G6;}
if(!__equal(to_LIST(a_1015)->offset[a_L1-4],344288233)){ goto a_G6;}
a_P[0]=1922290755;a_P[1]=to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-3];a_P[2]=to_LIST(a_1015)->offset[a_L1-3];a_1036(3,a_P);return;
a_G6:if(!__equal(to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-3],to_LIST(a_1015)->offset[a_L1-3])){ goto a_G8;}
a_P[0]=1922290745;a_P[1]=to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-3];a_1097(2,a_P);return;
a_G8:a_L1=to_LIST(a_1015)->offset[a_L1]; goto a_G2;
} /* checkmoduletitle */
static void a_1178(void){ /* checkicecompat */
int a_L1;int a_P[1];
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777327,44);return;
a_G5:if(__equal(a_L1,32)){ goto a_G8;}
a_P[0]=1922290770;a_1036(1,a_P);
a_1030(a_1001,16777347,370);return;
a_G8:if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078();
if(__equal(a_L1,1000000)){ goto a_G15;}
a_P[0]=1922290770;a_1036(1,a_P);
a_1030(a_1001,16777343,373);return;
a_G15:if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078();
if(__equal(a_L1,10000)){return;}
a_P[0]=1922290770;a_1036(1,a_P);
a_1030(a_1001,16777339,376);return;
} /* checkicecompat */
static void a_1204(void){ /* readdefinitionlist */
int a_L1;int a_L2;
a_G1:if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777327,44);return;
a_G5:if(!__mreq(a_L1,a_1201)){ goto a_G7;}
a_1201=a_L1; goto a_G8;
a_G7:a_1030(a_1001,16777335,380);return;
a_G8:if(!__equal(344288424,a_1058)){ goto a_G4;}
a_L2=a_1059;
a_1078();
 a_extension(a_1168,2);to_LIST(a_1168)->top[1]=a_L1;to_LIST(a_1168)->top[2]=a_L2;to_LIST(a_1168)->aupb+=2;
if(!__equal(to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1],0)){ goto a_G15;}
to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-1]=to_LIST(a_1168)->aupb;
a_G15:if(!__equal(344288384,a_1058)){ goto a_G1;}
a_1078();return;
} /* readdefinitionlist */
static void a_1196(int a_F1){ /* headsection+>a */

a_1185();
to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-5]=a_F1;
if(!__equal(344288221,a_1058)){ goto a_G6;}
a_1078();
to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-4]=344288221; goto a_G11;
a_G6:if(!__equal(344288233,a_1058)){ goto a_G10;}
a_1078();
to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-4]=344288233;
a_1162(); goto a_G11;
a_G10:a_1030(a_1001,16777331,390);return;
a_G11:if(!__equal(344288424,a_1058)){ goto a_G14;}
to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-3]=a_1059;
a_1078(); goto a_G15;
a_G14:a_1030(a_1001,16777327,44);return;
a_G15:a_1180();
a_1178();
a_1201=0;
a_1204();
to_LIST(a_1015)->offset[to_LIST(a_1015)->aupb-2]=a_1201;
if(!__equal(a_1175,0)){ goto a_G22;}
a_1187=to_LIST(a_1015)->aupb; goto a_G23;
a_G22:to_LIST(a_1015)->offset[a_1175]=to_LIST(a_1015)->aupb;
a_G23:a_1175=to_LIST(a_1015)->aupb;return;
} /* headsection */
static void a_1174(int a_A[1]){ /* advancebaseitem+a> */

if(!__equal(a_1175,0)){ goto a_G3;}
a_1175=a_1187; goto a_G4;
a_G3:a_1175=to_LIST(a_1015)->offset[a_1175];
a_G4:if(!__equal(a_1175,0)){ goto a_G6;}
a_A[0]=0;return;
a_G6:a_1201=to_LIST(a_1015)->offset[a_1175-2];
a_A[0]=to_LIST(a_1015)->offset[a_1175-5];return;
} /* advancebaseitem */
static void a_1208(void){ /* skipheadsection */

a_G1:if(!__equal(344288384,a_1058)){ goto a_G3;}
a_1078();return;
a_G3:a_1078(); goto a_G1;
} /* skipheadsection */
static void a_1206(int a_F1,int a_F2,int a_A[2]){ /* searchforline+>a+>a+a>+a> */

if(__lseq(a_F2,1)){ goto a_G3;}
if(!__more(a_F2,to_LIST(a_1015)->offset[a_F1-2])){ goto a_G5;}
a_G3:a_A[0]=0;
a_A[1]=374062088;return;
a_G5:a_F1=to_LIST(a_1015)->offset[a_F1-1];
a_A[0]=a_F2;
a_G7:if(!__more(a_F2,to_LIST(a_1168)->offset[a_F1-1])){ goto a_G10;}
__subtr(a_F2,to_LIST(a_1168)->offset[a_F1-1],a_A[0]);
__add(a_F1,2,a_F1); goto a_G7;
a_G10:a_A[1]=to_LIST(a_1168)->offset[a_F1];return;
} /* searchforline */
static void a_1112(int a_F1,int a_A[2]){ /* findlineno+>a+a>+a> */
int a_P[2];
if(!__equal(a_1175,0)){ goto a_G4;}
a_A[0]=a_F1;
a_A[1]=374062088;return;
a_G4:a_1206(a_1175,a_F1,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
} /* findlineno */
static void a_1111(int a_F1,int a_A[3]){ /* finditemlineno+>a+a>+a>+a> */
int a_L5;int a_L6;int a_P[2];
a_L5=a_1187;
a_G2:a_L6=to_LIST(a_1015)->offset[a_L5];
if(!__is(a_L6)){ goto a_G6;}
if(!__less(a_L6,a_F1)){ goto a_G6;}
a_L5=a_L6; goto a_G2;
a_G6:a_A[2]=to_LIST(a_1015)->offset[a_L5-3];
a_1206(a_L5,to_LIST(a_1015)->offset[a_F1-2],a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];return;
} /* finditemlineno */
static void a_1176(void){ /* checkallitems */
int a_L1;int a_L2;int a_L3;int a_P[3];
a_L1=to_LIST(a_1015)->alwb;
a_L3=0;
a_G3:if(__more(a_L1,to_LIST(a_1015)->aupb)){ goto a_G14;}
if(!__equal(to_LIST(a_1015)->offset[a_L1-4],344288233)){ goto a_G6;}
a_L3=1; goto a_G7;
a_G6:if(!__equal(to_LIST(a_1015)->offset[a_L1-4],344288221)){ goto a_G8;}
a_G7:__next(a_1015,a_L1); goto a_G3;
a_G8:if(!a_1053(a_L1,a_P)){ goto a_G7;}a_L2=a_P[0];
if(a_1060(a_L2,4)){ goto a_G7;}
if(a_1060(a_L2,16)){ goto a_G7;}
a_P[0]=1922290735;a_P[1]=to_LIST(a_1015)->offset[a_L1-3];a_P[2]=a_L1;a_1036(3,a_P); goto a_G7;
a_G14:if(__equal(a_L3,1)){return;}
a_P[0]=1922290761;a_1036(1,a_P);return;
} /* checkallitems */
static void a_1167(void){ /* @root */

a_1173();
a_1169();
a_1172();
a_1170();return;
} /* @root */
static void a_1225(int a_F1){ /* extendBUFFER+>a */

 a_extension(a_1010,1);to_LIST(a_1010)->top[1]=a_F1;to_LIST(a_1010)->aupb+=1;
 return;
} /* extendBUFFER */
static void a_1164(int a_A[1]){ /* trytoopensource+a> */
int a_L2;
if(!a_openfile(a_1219,114,a_1016,to_LIST(a_1016)->aupb)){ goto a_G6;}
a_A[0]=0;
a_1134=1;
a_1235();
a_1078();return;
a_G6:__getfileerror(a_1219,a_L2);
if(!__equal(a_L2,2)){ goto a_G9;}
a_A[0]=1;return;
a_G9:a_A[0]=-1;return;
} /* trytoopensource */
static void a_1145(void){ /* closesource */

a_closefile(a_1219);return;
} /* closesource */
static void a_1235(void){ /* nextchar */
int a_P[1];
a_G1:if(!a_getchar(a_1219,a_P)){ goto a_G4;}a_1221=a_P[0];
{ if(a_1221==10){ goto a_G3;}
 if(a_1221<=31){  goto a_G1;}
 return;}
a_G3:__incr(a_1134);return;
a_G4:a_1221=1;return;
} /* nextchar */
static void a_1245(void){ /* saveinputposition */
int a_P[1];
a_getfilepos(a_1219,a_P);a_1231=a_P[0];
a_1230=a_1221;
a_1232=a_1058;
a_1233=a_1059;return;
} /* saveinputposition */
static void a_1244(void){ /* restoreinputposition */

a_setfilepos(a_1219,a_1231);
a_1221=a_1230;
a_1058=a_1232;
a_1059=a_1233;return;
} /* restoreinputposition */
static int a_1229(int a_A[1]){ /* hexdigit+a> */

{ if((48<=a_1221 && a_1221<=57)){ goto a_G2;}
 if((97<=a_1221 && a_1221<=102)){ goto a_G4;}
 if((65<=a_1221 && a_1221<=70)){  goto a_G7;}
  return 0;}
a_G2:__subtr(a_1221,48,a_A[0]);
a_G3:a_1235(); return 1;
a_G4:__subtr(a_1221,97,a_A[0]);
__add(a_A[0],10,a_A[0]); goto a_G3;
a_G7:__subtr(a_1221,65,a_A[0]);
__add(a_A[0],10,a_A[0]);
a_1235(); return 1;
} /* hexdigit */
static void a_1223(void){ /* comment */

a_G1:if(__equal(a_1221,10)){return;}
if(__equal(a_1221,1)){return;}
a_1235(); goto a_G1;
} /* comment */
static void a_1240(int a_A[1]){ /* readhex+a> */
int a_L2;int a_P[1];
a_A[0]=0;
a_G2:if(!a_1229(a_P)){return;}a_L2=a_P[0];
__leftclear(a_A[0],4);
__boolor(a_A[0],a_L2,a_A[0]); goto a_G2;
} /* readhex */
static void a_1239(int a_A[1]){ /* readdestination+a> */
int a_L2;
{ if(a_1221==78){ goto a_G2;}
 if(a_1221==48){ goto a_G15;}
 if(a_1221==45){  goto a_G17;}
  goto a_G30;}
a_G2:a_1235();
{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G8;}
}
__subtr(a_1221,48,a_A[0]);
a_1235();
if(__more(a_A[0],0)){ goto a_G9;}
if(__equal(0,0)){ goto a_G9;}
a_G8:a_1030(a_1001,16777399,127);return;
a_G9:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G13;}
}
__subtr(a_1221,48,a_L2);
a_1235();
__addmult(a_A[0],10,a_L2,a_A[0]); goto a_G9;
a_G13:if(!__is(0)){return;}
a_G14:__subtr(0,a_A[0],a_A[0]);return;
a_G15:a_1235();
a_A[0]=0;return;
a_G17:a_1235();
{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G8;}
}
__subtr(a_1221,48,a_A[0]);
a_1235();
if(__more(a_A[0],0)){ goto a_G24;}
if(!__equal(1,0)){ goto a_G8;}
a_G24:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G28;}
}
__subtr(a_1221,48,a_L2);
a_1235();
__addmult(a_A[0],10,a_L2,a_A[0]); goto a_G24;
a_G28:if(!__is(1)){return;} goto a_G14;
a_G30:a_1030(a_1001,16777395,145);return;
} /* readdestination */
static void a_1195(int a_F1,int a_A[1]){ /* gettagdata+>a+a> */

a_A[0]=to_LIST(a_1016)->offset[a_F1];return;
} /* gettagdata */
static void a_1116(int a_F1,int a_A[1]){ /* gettagimage+>a+a> */

__subtr(a_F1,2,a_A[0]);return;
} /* gettagimage */
static void a_1203(int a_F1,int a_F2){ /* puttagdata+>a+>a */

to_LIST(a_1016)->offset[a_F1]=a_F2;return;
} /* puttagdata */
static void a_1220(int a_A[1]){ /* addLEXTentry+a> */
int a_P[1];
 a_extension(a_1016,2);to_LIST(a_1016)->top[1]=to_LIST(a_1016)->top[2]=0;to_LIST(a_1016)->aupb+=2;
a_1224(to_LIST(a_1016)->aupb,a_P);a_A[0]=a_P[0];
if(__equal(a_A[0],to_LIST(a_1016)->aupb)){return;}
__unstack(a_1016);
__unstackstring(a_1016);return;
} /* addLEXTentry */
static void a_1224(int a_F1,int a_A[1]){ /* enterstring+>a+a> */
int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_P[1];
__subtr(a_F1,2,a_L3);
a_simplehash(a_1016,a_L3,a_P);a_L4=a_P[0];
__booland(a_L4,2147483647,a_L4);
_divrem01(a_L4,a_1218,a_L4);
__add(a_L4,to_LIST(a_1216)->alwb,a_L4);
a_L5=to_LIST(a_1216)->offset[a_L4];
a_G7:if(!__equal(a_L5,0)){ goto a_G14;}
to_LIST(a_1016)->offset[a_F1-1]=to_LIST(a_1216)->offset[a_L4];
to_LIST(a_1216)->offset[a_L4]=a_F1;a_A[0]=a_F1;
__incr(a_1217);
if(__less(a_1217,a_1218)){return;}
__add(a_1218,512,a_1218);
a_1243();return;
a_G14:__subtr(a_L5,2,a_L6);
a_comparestring(a_1016,a_L3,a_1016,a_L6,a_P);a_L7=a_P[0];
if(!__equal(a_L7,0)){ goto a_G18;}
a_A[0]=a_L5;return;
a_G18:a_L5=to_LIST(a_1016)->offset[a_L5-1]; goto a_G7;
} /* enterstring */
static void a_1243(void){ /* rehash */
int a_L1;int a_L2;int a_P[1];
a_1217=0;
a_L1=to_LIST(a_1216)->aupb;
a_G3:if(__less(a_L1,to_LIST(a_1216)->alwb)){ goto a_G6;}
to_LIST(a_1216)->offset[a_L1]=0;
__previous(a_1216,a_L1); goto a_G3;
a_G6:__subtr(to_LIST(a_1216)->aupb,to_LIST(a_1216)->alwb,a_L2);
a_G7:__incr(a_L2);
if(__mreq(a_L2,a_1218)){ goto a_G11;}
 a_extension(a_1216,1);to_LIST(a_1216)->top[1]=0;to_LIST(a_1216)->aupb+=1;
  goto a_G7;
a_G11:a_L1=to_LIST(a_1016)->aupb;
a_G12:if(__less(a_L1,to_LIST(a_1016)->alwb)){return;}
a_1224(a_L1,a_P);a_L2=a_P[0];
if(!__equal(a_L2,a_L1)){ goto a_G17;}
__previous(a_1016,a_L1);
__previousstring(a_1016,a_L1); goto a_G12;
a_G17:a_1117(a_1001,16777391,193);return;
} /* rehash */
static void a_1241(int a_A[1]){ /* readstring+a> */
int a_L2;int a_L3;int a_P[1];
a_L3=to_LIST(a_1010)->aupb;
a_L2=0;
a_G3:a_1235();
{ if(a_1221==34){ goto a_G5;}
 if(a_1221==10||a_1221==1){  goto a_G14;}
  goto a_G7;}
a_G5:a_1235();
if(!__equal(a_1221,34)){ goto a_G9;}
a_G7:a_1225(a_1221);
__incr(a_L2); goto a_G3;
a_G9:if(!__equal(a_L2,0)){ goto a_G11;}
a_A[0]=374062088;return;
a_G11:a_packstring(a_1010,a_L2,a_1016);
__unstackto(a_1010,a_L3);
a_1220(a_P);a_A[0]=a_P[0];return;
a_G14:a_1030(a_1001,16777387,202);return;
} /* readstring */
static void a_1238(int a_A[1]){ /* readbold+a> */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1235();
a_L3=to_LIST(a_1010)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1221 && a_1221<=122))){ goto a_G9;}
}
a_L4=a_1221;
a_1235();
a_1225(a_L4);
__incr(a_L2); goto a_G4;
a_G9:if(!__equal(a_1221,39)){ goto a_G11;}
a_1235(); goto a_G12;
a_G11:a_1030(a_1001,16777383,280);return;
a_G12:a_packstring(a_1010,a_L2,a_1016);
__unstackto(a_1010,a_L3);
a_A[0]=344288247;
a_G15:a_comparestring(a_1215,a_A[0],a_1016,to_LIST(a_1016)->aupb,a_P);a_L2=a_P[0];
if(__equal(a_L2,0)){ goto a_G20;}
if(!__equal(a_A[0],344288185)){ goto a_G19;}
a_1030(a_1001,16777379,284);return;
a_G19:__previousstring(a_1215,a_A[0]); goto a_G15;
a_G20:__unstackstring(a_1016);return;
} /* readbold */
static void a_1242(int a_A[1]){ /* readtype+a> */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1235();
a_L3=to_LIST(a_1010)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1221 && a_1221<=122))){ goto a_G9;}
}
a_L4=a_1221;
a_1235();
a_1225(a_L4);
__incr(a_L2); goto a_G4;
a_G9:if(!__equal(a_1221,32)){ goto a_G13;}
a_1225(32);
__incr(a_L2);
a_1235(); goto a_G4;
a_G13:if(!__equal(a_1221,62)){ goto a_G15;}
a_1235(); goto a_G16;
a_G15:a_1030(a_1001,16777375,294);return;
a_G16:a_packstring(a_1010,a_L2,a_1016);
__unstackto(a_1010,a_L3);
a_A[0]=344288342;
a_G19:a_comparestring(a_1215,a_A[0],a_1016,to_LIST(a_1016)->aupb,a_P);a_L2=a_P[0];
if(__equal(a_L2,0)){ goto a_G24;}
if(!__equal(a_A[0],344288252)){ goto a_G23;}
a_1030(a_1001,16777371,298);return;
a_G23:__previousstring(a_1215,a_A[0]); goto a_G19;
a_G24:__unstackstring(a_1016);return;
} /* readtype */
static void a_1078(void){ /* nextsymbol */
int a_L1;int a_P[1];
a_G1:{ if(a_1221==32||a_1221==10){ goto a_G2;}
 if(a_1221==36){ goto a_G3;}
 if(a_1221==48){ goto a_G4;}
 if((49<=a_1221 && a_1221<=57)){ goto a_G21;}
 if(a_1221==70){ goto a_G34;}
 if(a_1221==73){ goto a_G48;}
 if(a_1221==76){ goto a_G63;}
 if(a_1221==78){ goto a_G77;}
 if(a_1221==39){ goto a_G91;}
 if(a_1221==60){ goto a_G92;}
 if(a_1221==34){ goto a_G94;}
 if(a_1221==38){ goto a_G96;}
 if(a_1221==93){ goto a_G98;}
 if(a_1221==41){ goto a_G100;}
 if(a_1221==58){ goto a_G102;}
 if(a_1221==44){ goto a_G104;}
 if(a_1221==126){ goto a_G106;}
 if(a_1221==47){ goto a_G108;}
 if(a_1221==45){ goto a_G110;}
 if(a_1221==35){ goto a_G127;}
 if(a_1221==40){ goto a_G129;}
 if(a_1221==124){ goto a_G131;}
 if(a_1221==62){ goto a_G133;}
 if(a_1221==43){ goto a_G136;}
 if(a_1221==46){ goto a_G138;}
 if(a_1221==59){ goto a_G140;}
 if(a_1221==42){ goto a_G142;}
 if(a_1221==91){ goto a_G144;}
 if(a_1221==94){ goto a_G146;}
 if(a_1221==1){  goto a_G148;}
  goto a_G149;}
a_G2:a_1235(); goto a_G1;
a_G3:a_1223(); goto a_G1;
a_G4:a_1058=344288400;
a_1235();
{ if((48<=a_1221 && a_1221<=57)){ goto a_G7;}
 if(a_1221==120||a_1221==88){  goto a_G19;}
  goto a_G20;}
a_G7:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G12;}
}
__subtr(a_1221,48,a_1059);
a_1235();
if(__more(a_1059,0)){ goto a_G13;}
if(__equal(0,0)){ goto a_G13;}
a_G12:a_1030(a_1001,16777399,127);return;
a_G13:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G17;}
}
__subtr(a_1221,48,a_L1);
a_1235();
__addmult(a_1059,10,a_L1,a_1059); goto a_G13;
a_G17:if(!__is(0)){return;}
a_G18:__subtr(0,a_1059,a_1059);return;
a_G19:a_1240(a_P);a_1059=a_P[0];return;
a_G20:a_1059=0;return;
a_G21:a_1058=344288400;
{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G12;}
}
__subtr(a_1221,48,a_1059);
a_1235();
if(__more(a_1059,0)){ goto a_G28;}
if(!__equal(0,0)){ goto a_G12;}
a_G28:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G17;}
}
__subtr(a_1221,48,a_L1);
a_1235();
__addmult(a_1059,10,a_L1,a_1059); goto a_G28;
a_G34:a_1058=344288416;
a_1235();
{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G12;}
}
__subtr(a_1221,48,a_1059);
a_1235();
if(__more(a_1059,0)){ goto a_G42;}
if(!__equal(0,0)){ goto a_G12;}
a_G42:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G17;}
}
__subtr(a_1221,48,a_L1);
a_1235();
__addmult(a_1059,10,a_L1,a_1059); goto a_G42;
a_G48:a_1058=344288412;
a_1235();
{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G12;}
}
__subtr(a_1221,48,a_1059);
a_1235();
if(__more(a_1059,0)){ goto a_G56;}
if(!__equal(0,0)){ goto a_G12;}
a_G56:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G60;}
}
__subtr(a_1221,48,a_L1);
a_1235();
__addmult(a_1059,10,a_L1,a_1059); goto a_G56;
a_G60:if(!__is(0)){ goto a_G62;}
__subtr(0,a_1059,a_1059);
a_G62:a_1183();return;
a_G63:a_1058=344288420;
a_1235();
{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G12;}
}
__subtr(a_1221,48,a_1059);
a_1235();
if(__more(a_1059,0)){ goto a_G71;}
if(!__equal(0,0)){ goto a_G12;}
a_G71:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G17;}
}
__subtr(a_1221,48,a_L1);
a_1235();
__addmult(a_1059,10,a_L1,a_1059); goto a_G71;
a_G77:a_1058=344288408;
a_1235();
{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G12;}
}
__subtr(a_1221,48,a_1059);
a_1235();
if(__more(a_1059,0)){ goto a_G85;}
if(!__equal(0,0)){ goto a_G12;}
a_G85:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G17;}
}
__subtr(a_1221,48,a_L1);
a_1235();
__addmult(a_1059,10,a_L1,a_1059); goto a_G85;
a_G91:a_1238(a_P);a_1058=a_P[0];return;
a_G92:a_1058=344288404;
a_1242(a_P);a_1059=a_P[0];return;
a_G94:a_1058=344288424;
a_1241(a_P);a_1059=a_P[0];return;
a_G96:a_1058=344288345;
a_G97:a_1235();return;
a_G98:a_1058=344288348; goto a_G97;
a_G100:a_1058=344288351; goto a_G97;
a_G102:a_1058=344288354; goto a_G97;
a_G104:a_1058=344288357; goto a_G97;
a_G106:a_1058=344288360; goto a_G97;
a_G108:a_1058=344288363; goto a_G97;
a_G110:a_1235();
{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G125;}
}
a_1058=344288400;
{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G12;}
}
__subtr(a_1221,48,a_1059);
a_1235();
if(__more(a_1059,0)){ goto a_G119;}
if(!__equal(1,0)){ goto a_G12;}
a_G119:{ if(!((48<=a_1221 && a_1221<=57))){ goto a_G123;}
}
__subtr(a_1221,48,a_L1);
a_1235();
__addmult(a_1059,10,a_L1,a_1059); goto a_G119;
a_G123:if(!__is(1)){return;} goto a_G18;
a_G125:a_1058=344288366; goto a_G20;
a_G127:a_1058=344288369; goto a_G97;
a_G129:a_1058=344288372; goto a_G97;
a_G131:a_1058=344288375; goto a_G97;
a_G133:a_1058=344288378;
a_1235();
a_1239(a_P);a_1059=a_P[0];return;
a_G136:a_1058=344288381; goto a_G97;
a_G138:a_1058=344288384; goto a_G97;
a_G140:a_1058=344288387; goto a_G97;
a_G142:a_1058=344288390; goto a_G97;
a_G144:a_1058=344288393; goto a_G97;
a_G146:a_1058=344288396; goto a_G97;
a_G148:a_1058=344288427;return;
a_G149:a_1030(a_1001,16777367,334);return;
} /* nextsymbol */
static void a_1214(void){ /* @root */

a_1243();return;
} /* @root */
static void a_1258(void){ /* passi */
int a_L1;int a_P[1];
a_G1:if(a_1099()){return;}
if(!a_1155(0,a_P)){ goto a_G6;}a_L1=a_P[0];
a_1196(a_L1);
a_1199();
a_1031(); goto a_G1;
a_G6:a_1174(a_P);
a_1176();
a_1067();
a_1065();return;
} /* passi */
static void a_1259(void){ /* passii */
int a_L1;int a_P[1];
a_G1:if(a_1099()){return;}
a_1174(a_P);a_L1=a_P[0];
if(!a_1155(a_L1,a_P)){ goto a_G7;}
a_1208();
a_1209();
a_1032(); goto a_G1;
a_G7:if(a_1099()){return;}
a_1033();
a_1046();
a_1044();
a_1020();return;
} /* passii */
static void a_1260(void){ /* passiii */
int a_L1;int a_P[1];
a_1263();
a_1251();
a_1255();
a_G4:a_1174(a_P);a_L1=a_P[0];
if(!a_1155(a_L1,a_P)){ goto a_G9;}
a_1208();
a_1209();
a_1253(); goto a_G4;
a_G9:a_1256();
a_1252();
a_1262();return;
} /* passiii */
static void a_1261(void){ /* passiv */
int a_L1;int a_P[1];
a_G1:if(a_1099()){return;}
a_1174(a_P);a_L1=a_P[0];
if(!a_1155(a_L1,a_P)){ goto a_G7;}
a_1208();
a_1209();
a_1254(); goto a_G1;
a_G7:a_1250();return;
} /* passiv */
static void a_1249(void){ /* @root */

a_1144();
if(!a_1099()){ goto a_G4;}
exit(1);return;
a_G4:a_1258();
a_1259();
if(!a_1099()){ goto a_G8;}
a_G7:exit(2);return;
a_G8:a_1257();
if(!a_1099()){ goto a_G11;}
exit(4);return;
a_G11:a_1260();
a_1261();
if(!a_1099()){return;}
a_1106(); goto a_G7;
} /* @root */
static void a_1291(int a_F1,int a_F2){ /* findintervalpair+>a+>a */
int a_L3;
if(__lseq(a_F2,to_LIST(a_1273)->offset[a_F1-1])){return;}
a_L3=to_LIST(a_1273)->offset[a_F1];
to_LIST(a_1273)->offset[a_F1-1]=a_F2;
a_G4:if(!__equal(a_L3,0)){ goto a_G6;}
to_LIST(a_1273)->offset[a_F1]=0;return;
a_G6:if(!__less(a_F2,to_LIST(a_1273)->offset[a_L3-2])){ goto a_G8;}
to_LIST(a_1273)->offset[a_F1]=a_L3;return;
a_G8:if(!__lseq(a_F2,to_LIST(a_1273)->offset[a_L3-1])){ goto a_G11;}
to_LIST(a_1273)->offset[a_F1-1]=to_LIST(a_1273)->offset[a_L3-1];
to_LIST(a_1273)->offset[a_F1]=to_LIST(a_1273)->offset[a_L3];return;
a_G11:a_L3=to_LIST(a_1273)->offset[a_L3]; goto a_G4;
} /* findintervalpair */
static void a_1274(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* addinterval+>a+>a+>a+>a> */
int a_L5;
a_G1:a_L5=to_LIST(a_1273)->offset[a_F1];
if(!__equal(a_L5,0)){ goto a_G6;}
a_A[0]=1;
 a_extension(a_1273,3);to_LIST(a_1273)->top[1]=a_F2;to_LIST(a_1273)->top[2]=a_F3;to_LIST(a_1273)->top[3]=0;to_LIST(a_1273)->aupb+=3;
a_G5:to_LIST(a_1273)->offset[a_F1]=to_LIST(a_1273)->aupb;return;
a_G6:if(!__less(a_F2,to_LIST(a_1273)->offset[a_L5-2])){ goto a_G13;}
a_A[0]=1;
if(!__less(a_F3,to_LIST(a_1273)->offset[a_L5-2])){ goto a_G11;}
 a_extension(a_1273,3);to_LIST(a_1273)->top[1]=a_F2;to_LIST(a_1273)->top[2]=a_F3;to_LIST(a_1273)->top[3]=a_L5;to_LIST(a_1273)->aupb+=3;
  goto a_G5;
a_G11:to_LIST(a_1273)->offset[a_L5-2]=a_F2;
a_G12:a_1291(a_L5,a_F3);return;
a_G13:if(!__lseq(a_F2,to_LIST(a_1273)->offset[a_L5-1])){ goto a_G17;}
if(__lseq(a_F3,to_LIST(a_1273)->offset[a_L5-1])){return;}
a_A[0]=1; goto a_G12;
a_G17:a_F1=a_L5; goto a_G1;
} /* addinterval */
static int a_1286(int a_F1,int a_F2){ /* diff1+>a+>a */
int a_L3;
__subtr(a_F2,a_F1,a_L3);
if(!__equal(a_L3,1)){ return 0;} return 1;
} /* diff1 */
static void a_1307(int a_F1){ /* mergeintervals+>a */
int a_L2;
a_G1:if(__equal(to_LIST(a_1273)->offset[a_F1],0)){return;}
a_F1=to_LIST(a_1273)->offset[a_F1];
a_L2=to_LIST(a_1273)->offset[a_F1];
a_G4:if(!__noteq(a_L2,0)){ goto a_G1;}
if(!a_1286(to_LIST(a_1273)->offset[a_F1-1],to_LIST(a_1273)->offset[a_L2-2])){ goto a_G1;}
to_LIST(a_1273)->offset[a_F1-1]=to_LIST(a_1273)->offset[a_L2-1];
{register int a_r1=to_LIST(a_1273)->offset[a_L2];to_LIST(a_1273)->offset[a_F1]=a_r1;a_L2=a_r1;} goto a_G4;
} /* mergeintervals */
static int a_1283(int a_F1){ /* completezone+>a */

a_F1=to_LIST(a_1273)->offset[a_F1];
if(!__is(a_F1)){ return 0;}
if(!__equal(to_LIST(a_1273)->offset[a_F1-2],(-2147483647-1))){ return 0;}
if(!__equal(to_LIST(a_1273)->offset[a_F1-1],2147483647)){ return 0;} return 1;
} /* completezone */
static void a_1312(int a_A[2]){ /* readareainterval+a>+a> */
int a_L3;int a_L4;int a_P[1];
if(!__equal(344288400,a_1058)){ goto a_G6;}
a_A[0]=a_1059;
a_1078();
a_G4:a_A[1]=a_A[0];
a_L4=1; goto a_G22;
a_G6:if(!__equal(344288412,a_1058)){ goto a_G21;}
a_L3=a_1059;
a_1078();
if(a_1053(a_L3,a_P)){a_L3=a_P[0];}
{register int a_r1=to_LIST(a_1015)->offset[a_L3-4];
 if(a_r1==344288252||a_r1==344288283){ goto a_G11;}
 if(a_r1==344288270||a_r1==344288266||a_r1==344288276){  goto a_G14;}
  goto a_G20;}
a_G11:a_A[0]=to_LIST(a_1015)->offset[a_L3]; goto a_G4;
a_G14:a_1055(a_L3,a_P);a_A[0]=a_P[0];
a_1048(a_L3,a_P);a_A[1]=a_P[0];
__subtr(a_A[0],a_A[1],a_A[0]);
__incr(a_A[0]);
a_1056(a_L3,a_P);a_A[1]=a_P[0];
a_L4=2; goto a_G22;
a_G20:a_1030(a_1001,16777435,79);return;
a_G21:a_A[0]=0;a_A[1]=0;a_L4=0;
a_G22:if(!__equal(344288354,a_1058)){ goto a_G39;}
a_1078();
if(!__equal(a_L4,0)){ goto a_G26;}
a_A[0]=(-2147483647-1); goto a_G28;
a_G26:if(__equal(a_L4,1)){ goto a_G28;}
a_1030(a_1001,16777431,81);return;
a_G28:if(!__equal(344288400,a_1058)){ goto a_G31;}
a_A[1]=a_1059;
a_1078();return;
a_G31:if(!__equal(344288412,a_1058)){ goto a_G38;}
a_L3=a_1059;
a_1078();
if(a_1053(a_L3,a_P)){a_L3=a_P[0];}
{register int a_r1=to_LIST(a_1015)->offset[a_L3-4];
 if(!(a_r1==344288252||a_r1==344288283)){ goto a_G37;}
}
a_A[1]=to_LIST(a_1015)->offset[a_L3];return;
a_G37:a_1030(a_1001,16777427,86);return;
a_G38:a_A[1]=2147483647;return;
a_G39:if(!__equal(a_L4,0)){return;}
a_1030(a_1001,16777423,88);return;
} /* readareainterval */
static void a_1278(int a_F1,int a_A[1]){ /* checkarea+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[4];
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_A[0]=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777411,44);return;
a_G5:a_L3=0;
a_G6:a_1312(a_P);a_L4=a_P[0];a_L5=a_P[1];
if(!__lseq(a_L4,a_L5)){ goto a_G9;}
a_P[0]=a_L3;a_1274(a_F1,a_L4,a_L5,a_P);a_L3=a_P[0]; goto a_G10;
a_G9:a_P[0]=1922290785;a_P[1]=a_A[0];a_P[2]=a_L4;a_P[3]=a_L5;a_1036(4,a_P);
a_G10:if(!__equal(344288387,a_1058)){ goto a_G12;}
a_1078(); goto a_G6;
a_G12:a_1307(a_F1);
if(__is(a_L3)){return;}
a_P[0]=1922290798;a_P[1]=a_A[0];a_1036(2,a_P);return;
} /* checkarea */
static void a_1279(void){ /* checkareas */
int a_L1;int a_L2;int a_L3;int a_P[2];
__scratch(a_1273);
 a_extension(a_1273,3);to_LIST(a_1273)->top[1]=to_LIST(a_1273)->top[2]=to_LIST(a_1273)->top[3]=0;to_LIST(a_1273)->aupb+=3;
a_L1=to_LIST(a_1273)->aupb;
a_L2=0;a_L3=0;
a_G5:if(!__equal(344288185,a_1058)){ goto a_G13;}
a_1078();
__incr(a_L3);
a_1278(a_L1,a_P);a_L2=a_P[0];
if(!__equal(344288378,a_1058)){ goto a_G12;}

a_1078(); goto a_G5;
a_G12:a_1030(a_1001,16777411,44);return;
a_G13:if(!a_1283(a_L1)){ goto a_G17;}
a_1322(2048);
if(__more(a_L3,1)){return;}
a_P[0]=1922290823;a_P[1]=a_L2;a_1036(2,a_P);return;
a_G17:a_P[0]=1922290811;a_P[1]=a_L2;a_1097(2,a_P);
a_1335=1;return;
} /* checkareas */
static void a_1322(int a_F1){ /* setnodeflag+>a */

__boolor(a_F1,to_LIST(a_1268)->offset[a_1336-4],to_LIST(a_1268)->offset[a_1336-4]);return;
} /* setnodeflag */
static void a_1311(int a_F1,int a_F2){ /* putnodeflag+>a+>a */

__boolor(a_F2,to_LIST(a_1268)->offset[a_F1-4],to_LIST(a_1268)->offset[a_F1-4]);return;
} /* putnodeflag */
static void a_1285(void){ /* createnodes */
int a_L1;
__scratch(a_1268);
if(!__equal(344288400,a_1058)){ goto a_G5;}
a_L1=a_1059;
a_1078(); goto a_G6;
a_G5:a_1030(a_1001,16777411,44);return;
a_G6:if(__equal(a_L1,0)){return;}
 a_extension(a_1268,6);to_LIST(a_1268)->top[1]=to_LIST(a_1268)->top[2]=to_LIST(a_1268)->top[3]=to_LIST(a_1268)->top[4]=to_LIST(a_1268)->top[5]=to_LIST(a_1268)->top[6]=0;to_LIST(a_1268)->aupb+=6;
__decr(a_L1); goto a_G6;
} /* createnodes */
static void a_1275(void){ /* advancenode */

if(!__equal(344288408,a_1058)){ goto a_G4;}

a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777411,44);return;
a_G5:if(!__equal(a_1336,0)){ goto a_G7;}
a_1336=to_LIST(a_1268)->alwb; goto a_G8;
a_G7:__next(a_1268,a_1336);
a_G8:if(__lseq(a_1336,to_LIST(a_1268)->aupb)){return;}
a_1030(a_1001,16777419,158);return;
} /* advancenode */
static void a_1323(void){ /* setrulehead */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777411,44);return;
a_G5:if(a_1053(a_L1,a_P)){a_L1=a_P[0];}
to_LIST(a_1268)->offset[a_1336-3]=a_L1;
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L2=a_1059;
a_1078();
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L3=a_1059;
a_1078();
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L4=a_1059;
a_1078();
if(!a_1302(a_L1)){ goto a_G21;}
a_1322(8);return;
a_G21:__max(a_L2,a_1265);
__max(a_L3,a_1266);
__max(a_L4,a_1267);return;
} /* setrulehead */
static void a_1326(void){ /* skiprulehead */

a_1078();
a_1078();
a_1078();
a_1078();return;
} /* skiprulehead */
static void a_1281(void){ /* clearstacksize */

a_1265=0;a_1266=0;a_1267=0;return;
} /* clearstacksize */
static void a_1305(int a_F1){ /* marklocalaffix+>a */

if(__equal(a_1287,0)){return;}
__add(a_1303,a_F1,a_F1);
to_LIST(a_1010)->offset[a_F1]=1;return;
} /* marklocalaffix */
static void a_1329(int a_F1,int a_F2){ /* startlocalaffixcheck+>a+>a */
int a_P[1];
if(!__equal(a_F1,0)){ goto a_G3;}
a_1287=0;return;
a_G3:a_1287=1;
__subtr(to_LIST(a_1010)->aupb,a_F1,a_1303);
__incr(a_1303);
a_G6:if(__more(a_F1,a_F2)){return;}
a_P[0]=0;a_1310(1,a_P);
__incr(a_F1); goto a_G6;
} /* startlocalaffixcheck */
static void a_1327(void){ /* skiptocomma */
int a_L1;
a_G1:if(!__equal(344288357,a_1058)){ goto a_G3;}
a_1078();return;
a_G3:if(!__equal(344288420,a_1058)){ goto a_G7;}
a_L1=a_1059;
a_1078();
a_1305(a_L1); goto a_G1;
a_G7:a_1078(); goto a_G1;
} /* skiptocomma */
static void a_1328(int a_A[1]){ /* skiptolabel+a> */

a_G1:if(!__equal(344288378,a_1058)){ goto a_G4;}
a_A[0]=a_1059;
a_1078();return;
a_G4:a_1078(); goto a_G1;
} /* skiptolabel */
static int a_1301(void){ /* islimit */

if(!__equal(344288192,a_1058)){ goto a_G3;}
a_G2:a_1078(); return 1;
a_G3:if(__equal(344288217,a_1058)){ goto a_G2;}
if(__equal(344288239,a_1058)){ goto a_G2;}
if(__equal(344288243,a_1058)){ goto a_G2;}
if(!__equal(344288247,a_1058)){ return 0;}
a_1078(); return 1;
} /* islimit */
static void a_1325(void){ /* skiplist */

if(!__equal(344288416,a_1058)){ goto a_G3;}
a_G2:a_1078();return;
a_G3:if(!__equal(344288412,a_1058)){ goto a_G6;}
 goto a_G2;
a_G6:a_1030(a_1001,16777411,44);return;
} /* skiplist */
static void a_1324(void){ /* skipaffix */
int a_L1;
if(!__equal(344288354,a_1058)){ goto a_G3;}
a_1078();
a_G3:if(!__equal(344288416,a_1058)){ goto a_G5;}
a_G4:a_1078();return;
a_G5:if(!__equal(344288420,a_1058)){ goto a_G9;}
a_L1=a_1059;
a_1078();
a_1305(a_L1);return;
a_G9:if(__equal(344288412,a_1058)){ goto a_G4;}
if(__equal(344288369,a_1058)){ goto a_G4;}
if(__equal(344288400,a_1058)){ goto a_G4;}
if(!a_1301()){ goto a_G17;}
a_1325();return;
a_G17:if(!__equal(344288393,a_1058)){ goto a_G29;}
a_1078();
a_1325();
a_1324();
if(!__equal(344288348,a_1058)){ goto a_G24;}

a_1078(); goto a_G25;
a_G24:a_1030(a_1001,16777411,44);return;
a_G25:if(!__equal(344288400,a_1058)){ goto a_G24;}
 goto a_G4;
a_G29:a_1030(a_1001,16777415,224);return;
} /* skipaffix */
static void a_1310(int a_C,int *a_V){ /* pushBUFFER+*+>a */

a_G1: a_extension(a_1010,1);to_LIST(a_1010)->top[1]=a_V[0];to_LIST(a_1010)->aupb+=1;
if(a_C>1){a_C--;a_V+=1; goto a_G1;} return;
} /* pushBUFFER */
static void a_1332(int a_F1){ /* storelist+>a */
int a_L2;int a_P[3];
if(!__equal(344288416,a_1058)){ goto a_G5;}
a_L2=a_1059;
a_1078();
a_P[0]=a_F1;a_P[1]=344288416;a_P[2]=a_L2;a_1310(3,a_P);return;
a_G5:if(!__equal(344288412,a_1058)){ goto a_G8;}
a_L2=a_1059;
a_1078(); goto a_G9;
a_G8:a_1030(a_1001,16777411,44);return;
a_G9:a_P[0]=a_F1;a_P[1]=344288412;a_P[2]=a_L2;a_1310(3,a_P);return;
} /* storelist */
static void a_1331(void){ /* storelimit */

if(!__equal(344288217,a_1058)){ goto a_G4;}
a_1078();
a_1332(344288217);return;
a_G4:if(!__equal(344288239,a_1058)){ goto a_G7;}
a_1078();
a_1332(344288239);return;
a_G7:if(!__equal(344288243,a_1058)){ goto a_G10;}
a_1078();
a_1332(344288243);return;
a_G10:if(!__equal(344288247,a_1058)){ goto a_G13;}
a_1078();
a_1332(344288247);return;
a_G13:if(!__equal(344288192,a_1058)){ goto a_G16;}

a_1078(); goto a_G17;
a_G16:a_1030(a_1001,16777411,44);return;
a_G17:a_1332(344288192);return;
} /* storelimit */
static void a_1330(void){ /* storeaffix */
int a_L1;int a_P[2];
if(!__equal(344288416,a_1058)){ goto a_G5;}
a_L1=a_1059;
a_1078();
a_P[0]=344288416;a_P[1]=a_L1;a_1310(2,a_P);return;
a_G5:if(!__equal(344288420,a_1058)){ goto a_G9;}
a_L1=a_1059;
a_1078();
a_P[0]=344288420;a_P[1]=a_L1;a_1310(2,a_P);return;
a_G9:if(!__equal(344288412,a_1058)){ goto a_G13;}
a_L1=a_1059;
a_1078();
a_P[0]=344288412;a_P[1]=a_L1;a_1310(2,a_P);return;
a_G13:if(!__equal(344288400,a_1058)){ goto a_G17;}
a_L1=a_1059;
a_1078();
a_P[0]=344288400;a_P[1]=a_L1;a_1310(2,a_P);return;
a_G17:if(!__equal(344288393,a_1058)){ goto a_G30;}
a_1078();
a_1332(344288393);
a_1330();
if(!__equal(344288348,a_1058)){ goto a_G24;}

a_1078(); goto a_G25;
a_G24:a_1030(a_1001,16777411,44);return;
a_G25:if(!__equal(344288400,a_1058)){ goto a_G24;}
a_L1=a_1059;
a_1078();
a_P[0]=344288348;a_P[1]=a_L1;a_1310(2,a_P);return;
a_G30:a_1331();return;
} /* storeaffix */
static void a_1333(int a_A[1]){ /* storeruleaffix+a> */
int a_L2;int a_P[2];
if(!__equal(344288354,a_1058)){ goto a_G6;}
a_1078();
a_A[0]=344288354;
a_P[0]=344288354;a_1310(1,a_P);
a_1330();return;
a_G6:if(!__equal(344288369,a_1058)){ goto a_G10;}
a_1078();
a_A[0]=344288369;
a_P[0]=344288369;a_1310(1,a_P);return;
a_G10:if(!__equal(344288390,a_1058)){ goto a_G18;}
a_1078();
a_A[0]=344288390;
if(!__equal(344288400,a_1058)){ goto a_G16;}
a_L2=a_1059;
a_1078(); goto a_G17;
a_G16:a_L2=0;
a_G17:a_P[0]=344288390;a_P[1]=a_L2;a_1310(2,a_P);return;
a_G18:a_A[0]=0;
a_1330();return;
} /* storeruleaffix */
static void a_1334(void){ /* storeruleaffixes */
int a_P[2];
a_G1:{ if(a_1058==344288420){ goto a_G2;}
 if(a_1058==344288416||a_1058==344288412||a_1058==344288400){ goto a_G3;}
 if(a_1058==344288217||a_1058==344288239||a_1058==344288243||a_1058==344288247||a_1058==344288192||a_1058==344288369||a_1058==344288393||a_1058==344288348||a_1058==344288390||a_1058==344288354){  goto a_G7;}
  goto a_G9;}
a_G2:a_1305(a_1059);
a_G3:a_P[0]=a_1058;a_P[1]=a_1059;a_1310(2,a_P);
a_G4:a_1078(); goto a_G1;
a_G7:a_P[0]=a_1058;a_1310(1,a_P); goto a_G4;
a_G9:if(!__equal(344288378,a_1058)){ goto a_G12;}
to_LIST(a_1268)->offset[a_1336-1]=a_1059;
a_1078(); goto a_G13;
a_G12:a_1030(a_1001,16777411,44);return;
a_G13:if(!__equal(344288378,a_1058)){ goto a_G12;}
to_LIST(a_1268)->offset[a_1336]=a_1059;
a_1078();
if(!__equal(344288357,a_1058)){ goto a_G12;}

a_1078();return;
} /* storeruleaffixes */
static void a_1284(void){ /* computeruleaffixhash */
int a_L1;int a_P[1];
a_L1=to_LIST(a_1010)->aupb;
a_1334();
a_blockhash(a_1010,a_L1,a_P);to_LIST(a_1268)->offset[a_1336-5]=a_P[0];
__unstackto(a_1010,a_L1);return;
} /* computeruleaffixhash */
static int a_1309(int a_F1){ /* nodewithsamehash+>a */
int a_L2;int a_L3;int a_L4;int a_L5;
a_L2=to_LIST(a_1268)->offset[a_F1-5];
a_L3=to_LIST(a_1268)->offset[a_F1-3];
a_L4=to_LIST(a_1268)->alwb;
a_G4:if(__more(a_L4,to_LIST(a_1268)->aupb)){ return 0;}
if(!__noteq(a_L4,a_F1)){ goto a_G10;}
__booland(to_LIST(a_1268)->offset[a_L4-4],1,a_L5);
if(!__noteq(a_L5,0)){ goto a_G10;}
if(!__equal(to_LIST(a_1268)->offset[a_L4-5],a_L2)){ goto a_G10;}
if(__equal(to_LIST(a_1268)->offset[a_L4-3],a_L3)){ return 1;}
a_G10:__next(a_1268,a_L4); goto a_G4;
} /* nodewithsamehash */
static int a_1308(void){ /* nodehashdifferent */
int a_L1;int a_L2;
a_L1=to_LIST(a_1268)->alwb;
a_G2:if(__more(a_L1,to_LIST(a_1268)->aupb)){ return 1;}
__booland(to_LIST(a_1268)->offset[a_L1-4],1,a_L2);
if(!__noteq(a_L2,0)){ goto a_G6;}
if(a_1309(a_L1)){ return 0;}
a_G6:__next(a_1268,a_L1); goto a_G2;
} /* nodehashdifferent */
static int a_1288(int a_F1,int a_F2){ /* equalaffixes+>a+>a */

a_G1:if(!__equal(to_LIST(a_1010)->offset[a_F1],to_LIST(a_1010)->offset[a_F2])){ return 0;}
if(__equal(to_LIST(a_1010)->offset[a_F1],344288357)){ return 1;}
__decr(a_F1);
__decr(a_F2); goto a_G1;
} /* equalaffixes */
static void a_1282(int a_F1){ /* comparetostoredaffixes+>a */
int a_L2;int a_L3;int a_L4;int a_L5;
a_L3=to_LIST(a_1268)->offset[a_1336-5];
a_L4=1;
a_L2=to_LIST(a_1268)->alwb;
a_G4:if(__mreq(a_L2,a_1336)){ goto a_G13;}
__booland(to_LIST(a_1268)->offset[a_L2-4],4096,a_L5);
if(!__noteq(a_L5,0)){ goto a_G12;}
if(!__equal(to_LIST(a_1268)->offset[a_L2-5],a_L3)){ goto a_G12;}
if(!a_1288(to_LIST(a_1268)->offset[a_1336-2],to_LIST(a_1268)->offset[a_L2-2])){ goto a_G12;}
a_L4=0;
to_LIST(a_1268)->offset[a_1336-2]=a_L2;
a_1322(8192); goto a_G13;
a_G12:__next(a_1268,a_L2); goto a_G4;
a_G13:if(__equal(a_L4,0)){ goto a_G22;}
a_L4=0;
a_G15:__next(a_1268,a_L2);
if(__more(a_L2,to_LIST(a_1268)->aupb)){ goto a_G22;}
__booland(to_LIST(a_1268)->offset[a_L2-4],1,a_L5);
if(!__noteq(a_L5,0)){ goto a_G15;}
if(!__equal(to_LIST(a_1268)->offset[a_L2-5],a_L3)){ goto a_G15;}
a_L4=1;
a_G22:if(!__equal(a_L4,0)){ goto a_G24;}
__unstackto(a_1010,a_F1);return;
a_G24:a_1322(4096);return;
} /* comparetostoredaffixes */
static void a_1280(void){ /* checknodehash */
int a_L1;int a_P[1];
if(!a_1309(a_1336)){ goto a_G7;}
a_L1=to_LIST(a_1010)->aupb;
a_P[0]=344288357;a_1310(1,a_P);
a_1334();
to_LIST(a_1268)->offset[a_1336-2]=to_LIST(a_1010)->aupb;
a_1282(a_L1);return;
a_G7:a_1327();return;
} /* checknodehash */
static int a_1317(int a_F1,int a_F2){ /* samenodes+>a+>a */
int a_L3;
if(!__equal(to_LIST(a_1268)->offset[a_F1-3],to_LIST(a_1268)->offset[a_F2-3])){ return 0;}
if(!__equal(to_LIST(a_1268)->offset[a_F1-5],to_LIST(a_1268)->offset[a_F2-5])){ return 0;}
if(!__equal(to_LIST(a_1268)->offset[a_F1-1],to_LIST(a_1268)->offset[a_F2-1])){ return 0;}
if(!__equal(to_LIST(a_1268)->offset[a_F1],to_LIST(a_1268)->offset[a_F2])){ return 0;}
a_G5:__booland(to_LIST(a_1268)->offset[a_F1-4],8192,a_L3);
if(!__noteq(a_L3,0)){ goto a_G8;}
a_F1=to_LIST(a_1268)->offset[a_F1-2]; goto a_G5;
a_G8:__booland(to_LIST(a_1268)->offset[a_F2-4],8192,a_L3);
if(!__noteq(a_L3,0)){ goto a_G11;}
a_F2=to_LIST(a_1268)->offset[a_F2-2]; goto a_G8;
a_G11:if(!__equal(a_F1,a_F2)){ return 0;} return 1;
} /* samenodes */
static void a_1300(int a_F1,int a_A[1]){ /* getnodeindex+>a+a> */

__subtr(a_F1,to_LIST(a_1268)->alwb,a_A[0]);
__div(a_A[0],6,a_A[0]);
__incr(a_A[0]);return;
} /* getnodeindex */
static void a_1313(int a_F1,int a_F2){ /* replacelabels+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_G1:__booland(to_LIST(a_1268)->offset[a_F1-4],16384,a_L4);
if(!__noteq(a_L4,0)){ goto a_G4;}
a_F1=to_LIST(a_1268)->offset[a_F1-2]; goto a_G1;
a_G4:to_LIST(a_1268)->offset[a_F2-2]=a_F1;
a_1311(a_F2,16384);
a_1300(a_F1,a_P);a_F1=a_P[0];
a_1300(a_F2,a_P);a_F2=a_P[0];
a_L3=to_LIST(a_1268)->alwb;
a_G9:if(__more(a_L3,to_LIST(a_1268)->aupb)){return;}
if(!__equal(to_LIST(a_1268)->offset[a_L3-1],a_F2)){ goto a_G12;}
to_LIST(a_1268)->offset[a_L3-1]=a_F1;
a_G12:if(!__equal(to_LIST(a_1268)->offset[a_L3],a_F2)){ goto a_G14;}
to_LIST(a_1268)->offset[a_L3]=a_F1;
a_G14:__next(a_1268,a_L3); goto a_G9;
} /* replacelabels */
static void a_1290(void){ /* findequalnodes */
int a_L1;int a_L2;int a_L3;int a_L4;
a_G1:a_L1=0;
a_L2=to_LIST(a_1268)->alwb;
a_G3:if(__mreq(a_L2,to_LIST(a_1268)->aupb)){ goto a_G18;}
__booland(to_LIST(a_1268)->offset[a_L2-4],16384,a_L4);
if(!__noteq(a_L4,0)){ goto a_G7;}
a_G6:__next(a_1268,a_L2); goto a_G3;
a_G7:a_L3=a_L2;
a_G8:__next(a_1268,a_L3);
if(__more(a_L3,to_LIST(a_1268)->aupb)){ goto a_G6;}
__booland(to_LIST(a_1268)->offset[a_L3-4],16384,a_L4);
if(__noteq(a_L4,0)){ goto a_G8;}
if(!a_1317(a_L2,a_L3)){ goto a_G8;}
a_L1=1;
a_1313(a_L2,a_L3); goto a_G8;
a_G18:if(__equal(a_L1,0)){return;} goto a_G1;
} /* findequalnodes */
static void a_1293(int a_F1,int a_A[1]){ /* findreallabel+>a+a> */
int a_L3;
if(!__lseq(a_F1,0)){ goto a_G3;}
a_A[0]=a_F1;return;
a_G3:__decr(a_F1);
__addmult(a_F1,6,to_LIST(a_1268)->alwb,a_F1);
a_G5:__booland(to_LIST(a_1268)->offset[a_F1-4],16384,a_L3);
if(!__noteq(a_L3,0)){ goto a_G8;}
a_F1=to_LIST(a_1268)->offset[a_F1-2]; goto a_G5;
a_G8:__subtr(a_F1,to_LIST(a_1268)->alwb,a_A[0]);
__div(a_A[0],6,a_A[0]);
__incr(a_A[0]);return;
} /* findreallabel */
static void a_1292(int a_A[1]){ /* findnextnode+a> */
int a_L2;int a_L3;
a_A[0]=0;
a_L2=a_1336;
a_G3:__next(a_1268,a_L2);
if(__more(a_L2,to_LIST(a_1268)->aupb)){return;}
__booland(to_LIST(a_1268)->offset[a_L2-4],16384,a_L3);
if(__noteq(a_L3,0)){ goto a_G3;}
__subtr(a_L2,to_LIST(a_1268)->alwb,a_A[0]);
__div(a_A[0],6,a_A[0]);
__incr(a_A[0]);return;
} /* findnextnode */
static void a_1306(int a_F1,int a_F2){ /* marknode+>a+>a */
int a_P[1];
a_1293(a_F2,a_P);a_F2=a_P[0];
if(__lseq(a_F2,0)){return;}
if(__equal(a_F2,a_F1)){return;}
__decr(a_F2);
__addmult(a_F2,6,to_LIST(a_1268)->alwb,a_F2);
a_1311(a_F2,16);return;
} /* marknode */
static void a_1316(void){ /* rulelabel */
int a_L1;int a_L2;int a_P[1];
__booland(to_LIST(a_1268)->offset[a_1336-4],16384,a_L2);
if(__noteq(a_L2,0)){return;}
a_1292(a_P);a_L1=a_P[0];
a_1306(a_L1,to_LIST(a_1268)->offset[a_1336-1]);
a_1306(a_L1,to_LIST(a_1268)->offset[a_1336]);return;
} /* rulelabel */
static void a_1276(void){ /* arealabels */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
a_1292(a_P);a_L1=a_P[0];
a_L2=0;a_L3=0;
a_G3:if(!__equal(344288185,a_1058)){ goto a_G8;}
a_1078();
a_1306(0,a_L2);
a_L2=a_L3;
a_1328(a_P);a_L3=a_P[0]; goto a_G3;
a_G8:__booland(to_LIST(a_1268)->offset[a_1336-4],2048,a_L4);
if(!__noteq(a_L4,0)){ goto a_G12;}
a_1306(a_L1,a_L2);
a_G11:a_1306(a_L1,a_L3);return;
a_G12:a_1306(0,a_L2); goto a_G11;
} /* arealabels */
static void a_1289(void){ /* extensionlabel */
int a_L1;int a_L2;int a_P[1];
a_1292(a_P);a_L1=a_P[0];
a_1328(a_P);a_L2=a_P[0];
a_1306(a_L1,a_L2);return;
} /* extensionlabel */
static void a_1298(void){ /* generatelabel */
int a_L1;int a_L2;int a_L3;int a_P[1];
a_1275();
__booland(to_LIST(a_1268)->offset[a_1336-4],16384,a_L3);
if(__noteq(a_L3,0)){return;}
a_1292(a_P);a_L2=a_P[0];
__booland(to_LIST(a_1268)->offset[a_1336-4],16,a_L3);
if(!__noteq(a_L3,0)){ goto a_G10;}
__subtr(a_1336,to_LIST(a_1268)->alwb,a_L1);
__div(a_L1,6,a_L1);
__incr(a_L1); goto a_G11;
a_G10:a_L1=0;
a_G11:a_1271(a_L1,a_L2);return;
} /* generatelabel */
static void a_1299(void){ /* generaterulecall */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_P[1];
if(!__equal(344288412,a_1058)){ goto a_G4;}

a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777411,44);return;
a_G5:if(!__equal(344288400,a_1058)){ goto a_G4;}

a_1078();
if(!__equal(344288400,a_1058)){ goto a_G4;}

a_1078();
if(!__equal(344288400,a_1058)){ goto a_G4;}

a_1078();
a_L7=to_LIST(a_1010)->aupb;
a_L2=0;a_L5=0;a_L6=0;
a_G19:if(!__equal(344288378,a_1058)){ goto a_G25;}
a_1078();
if(!__equal(344288378,a_1058)){ goto a_G4;}

a_1078(); goto a_G34;
a_G25:a_1333(a_P);a_L1=a_P[0];
a_P[0]=344288381;a_1310(1,a_P);
__incr(a_L2);
if(!__is(a_L5)){ goto a_G30;}
__incr(a_L5);
a_G30:if(!__equal(a_L1,344288390)){ goto a_G19;}
if(!__is(a_L5)){ goto a_G33;}
a_L6=1; goto a_G19;
a_G33:a_L5=1; goto a_G19;
a_G34:a_1293(to_LIST(a_1268)->offset[a_1336-1],a_P);a_L3=a_P[0];
a_1293(to_LIST(a_1268)->offset[a_1336],a_P);a_L4=a_P[0];
a_1272(to_LIST(a_1268)->offset[a_1336-3],a_L2,a_L3,a_L4,a_L5,a_L6,a_L7);
__unstackto(a_1010,a_L7);return;
} /* generaterulecall */
static void a_1297(void){ /* generateextension */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[2];
a_L1=to_LIST(a_1010)->aupb;
a_1332(0);
if(!__equal(344288400,a_1058)){ goto a_G6;}
a_L2=a_1059;
a_1078(); goto a_G7;
a_G6:a_1030(a_1001,16777411,44);return;
a_G7:__add(a_L1,1,a_L3);
to_LIST(a_1010)->offset[a_L3]=a_L2;
a_P[0]=0;a_1310(1,a_P);
a_L3=to_LIST(a_1010)->aupb;
a_G11:a_1330();
a_P[0]=344288381;a_1310(1,a_P);
a_G13:if(!__equal(344288236,a_1058)){ goto a_G20;}
a_1078();
if(!__equal(344288400,a_1058)){ goto a_G6;}
a_L2=a_1059;
a_1078();
a_P[0]=a_L2;a_1310(1,a_P); goto a_G13;
a_G20:if(!__equal(344288378,a_1058)){ goto a_G26;}
a_L4=a_1059;
a_1078();
a_1293(a_L4,a_P);a_L4=a_P[0];
a_P[0]=-1;a_1310(1,a_P);
a_1270(a_L1,a_L4); goto a_G28;
a_G26:a_P[0]=-1;a_P[1]=0;a_1310(2,a_P);
{register int a_r1=to_LIST(a_1010)->aupb;to_LIST(a_1010)->offset[a_L3]=a_r1;a_L3=a_r1;} goto a_G11;
a_G28:__unstackto(a_1010,a_L1);return;
} /* generateextension */
static void a_1294(void){ /* generatearea */
int a_L1;int a_L2;int a_P[2];
a_G1:a_1312(a_P);a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=a_L1;a_P[1]=a_L2;a_1310(2,a_P);
if(!__equal(344288387,a_1058)){return;}
a_1078();
a_P[0]=344288387;a_1310(1,a_P); goto a_G1;
} /* generatearea */
static void a_1295(void){ /* generateareas */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
a_L1=0;
if(!__equal(344288185,a_1058)){ goto a_G5;}

a_1078(); goto a_G6;
a_G5:a_1030(a_1001,16777411,44);return;
a_G6:if(!__equal(344288400,a_1058)){ goto a_G5;}

a_1078();
a_P[0]=0;a_1310(1,a_P);
if(__equal(a_L1,0)){ goto a_G13;}
to_LIST(a_1010)->offset[a_L1]=to_LIST(a_1010)->aupb;
a_G13:a_L1=to_LIST(a_1010)->aupb;
a_P[0]=0;a_1310(1,a_P);
a_L2=to_LIST(a_1010)->aupb;
a_1294();
if(!__equal(344288378,a_1058)){ goto a_G5;}
a_L3=a_1059;
a_1078();
a_1293(a_L3,a_P);to_LIST(a_1010)->offset[a_L2]=a_P[0];
if(!__equal(344288185,a_1058)){ goto a_G25;}
a_1078();
a_P[0]=344288381;a_1310(1,a_P); goto a_G6;
a_G25:__booland(to_LIST(a_1268)->offset[a_1336-4],2048,a_L4);
if(!__noteq(a_L4,0)){ goto a_G29;}
__unstackto(a_1010,a_L2);
a_P[0]=(-2147483647-1);a_P[1]=2147483647;a_P[2]=344288381;a_1310(3,a_P);return;
a_G29:a_P[0]=344288381;a_1310(1,a_P);return;
} /* generateareas */
static void a_1296(void){ /* generatebox */
int a_L1;int a_L2;int a_P[1];
a_L1=to_LIST(a_1010)->aupb;
a_1330();
a_P[0]=344288381;a_1310(1,a_P);
a_L2=to_LIST(a_1010)->aupb;
a_1295();
a_1269(a_L1,a_L2);
__unstackto(a_1010,a_L1);return;
} /* generatebox */
static void a_1318(void){ /* scani */

a_G1:if(!__equal(344288188,a_1058)){ goto a_G11;}
a_1078();
a_1275();
a_1322(4);
a_1324();
a_1279();
if(!__equal(344288357,a_1058)){ goto a_G10;}

a_1078(); goto a_G1;
a_G10:a_1030(a_1001,16777411,44);return;
a_G11:if(!__equal(344288202,a_1058)){ goto a_G16;}
a_1078();
a_1275();
a_1322(2);
a_1327(); goto a_G1;
a_G16:if(!__equal(344288225,a_1058)){ goto a_G22;}
a_1078();
a_1275();
a_1322(1);
a_1323();
a_1284(); goto a_G1;
a_G22:if(!__equal(344288384,a_1058)){ goto a_G10;}

a_1078();return;
} /* scani */
static void a_1319(void){ /* scanii */
int a_L1;
a_L1=to_LIST(a_1010)->aupb;
a_G2:if(!__equal(344288188,a_1058)){ goto a_G6;}
a_G3:a_1078();
a_1275();
a_1327(); goto a_G2;
a_G6:if(__equal(344288202,a_1058)){ goto a_G3;}
if(!__equal(344288225,a_1058)){ goto a_G15;}
a_1078();
a_1275();
a_1326();
a_1280(); goto a_G2;
a_G15:if(!__equal(344288384,a_1058)){ goto a_G18;}

a_1078(); goto a_G19;
a_G18:a_1030(a_1001,16777411,44);return;
a_G19:__unstackto(a_1010,a_L1);
a_1290();return;
} /* scanii */
static void a_1320(void){ /* scaniii */

a_G1:if(!__equal(344288188,a_1058)){ goto a_G10;}
a_1078();
a_1275();
a_1324();
a_1276();
a_G6:if(!__equal(344288357,a_1058)){ goto a_G9;}

a_1078(); goto a_G1;
a_G9:a_1030(a_1001,16777411,44);return;
a_G10:if(!__equal(344288202,a_1058)){ goto a_G18;}
a_1078();
a_1275();
a_1289(); goto a_G6;
a_G18:if(!__equal(344288225,a_1058)){ goto a_G23;}
a_1078();
a_1275();
a_1316();
a_1327(); goto a_G1;
a_G23:if(!__equal(344288384,a_1058)){ goto a_G9;}

a_1078();return;
} /* scaniii */
static void a_1321(void){ /* scaniv */
int a_L1;
a_G1:if(!__equal(344288188,a_1058)){ goto a_G9;}
a_1078();
a_1298();
a_1296();
a_G5:if(!__equal(344288357,a_1058)){ goto a_G8;}

a_1078(); goto a_G1;
a_G8:a_1030(a_1001,16777411,44);return;
a_G9:if(!__equal(344288202,a_1058)){ goto a_G17;}
a_1078();
a_1298();
a_1297(); goto a_G5;
a_G17:if(!__equal(344288225,a_1058)){ goto a_G28;}
a_1078();
a_1298();
__booland(to_LIST(a_1268)->offset[a_1336-4],16384,a_L1);
if(!__noteq(a_L1,0)){ goto a_G23;}
a_1327(); goto a_G1;
a_G23:a_1299(); goto a_G5;
a_G28:if(!__equal(344288384,a_1058)){ goto a_G8;}

a_1078();return;
} /* scaniv */
static void a_1304(void){ /* makerule */
int a_L1;int a_L2;int a_L3;int a_L4;
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777411,44);return;
a_G5:if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L3=a_1059;
a_1078();
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_L4=a_1059;
a_1078();
a_1285();
a_1245();
if(!a_1060(a_L1,117440512)){ goto a_G17;}
a_1335=1; goto a_G18;
a_G17:a_1335=0;
a_G18:a_1336=0;
a_L2=to_LIST(a_1010)->aupb;
a_1281();
a_1329(a_L3,a_L4);
a_1318();
a_1287=0;
if(a_1308()){ goto a_G28;}
a_1244();
a_1336=0;
a_1319();
a_G28:a_1314(a_L1,a_1265,a_1266,a_1267,a_1335,a_L3,a_L4,a_1303);
__unstackto(a_1010,a_L2);
a_1244();
a_1336=0;
a_1320();
a_1244();
a_1336=0;
a_1321();
a_1315();return;
} /* makerule */
static void a_1264(void){ /* @root */

} /* @root */
static void a_1257(void){ /* opentarget */
int a_L1;int a_P[3];
a_1149();
if(!a_openfile(a_1339,119,a_1016,to_LIST(a_1016)->aupb)){ goto a_G5;}
__unstackstring(a_1016);
a_1419=1;return;
a_G5:__getfileerror(a_1339,a_L1);
a_P[0]=1922290837;a_P[1]=to_LIST(a_1016)->aupb;a_P[2]=a_L1;a_1036(3,a_P);return;
} /* opentarget */
static void a_1250(void){ /* closetarget */

a_closefile(a_1339);return;
} /* closetarget */
static void a_1106(void){ /* deletetarget */

if(__equal(a_1419,0)){return;}
a_1250();
a_1149();
a_unlinkfile(a_1016,to_LIST(a_1016)->aupb);
__unstackstring(a_1016);
a_1419=0;return;
} /* deletetarget */
static void a_1392(int a_F1){ /* printint+>a */

if(!__equal(a_F1,(-2147483647-1))){ goto a_G8;}
a_putchar(a_1339,40);
a_putchar(a_1339,45);
a_1392(2147483647);
a_putchar(a_1339,45);
a_putchar(a_1339,49);
a_putchar(a_1339,41);return;
a_G8:if(!__less(a_F1,0)){ goto a_G11;}
a_putchar(a_1339,45);
__getabs(a_F1,a_F1);
a_G11:a_1393(a_F1,48);return;
} /* printint */
static void a_1393(int a_F1,int a_F2){ /* printint1+>a+>a */
int a_L3;int a_L4;
_divrem11(a_F1,10,a_L3,a_L4);
if(__equal(a_L3,0)){ goto a_G4;}
a_1393(a_L3,48);
a_G4:__add(a_L4,a_F2,a_L4);
a_putchar(a_1339,a_L4);return;
} /* printint1 */
static void a_1395(void){ /* printlabelprefix */

a_putchar(a_1339,97);
a_putchar(a_1339,95);
a_putchar(a_1339,71);return;
} /* printlabelprefix */
static void a_1380(int a_F1){ /* localargument+>a */

a_putchar(a_1339,97);
a_putchar(a_1339,95);
a_putchar(a_1339,76);
a_1392(a_F1);return;
} /* localargument */
static void a_1394(int a_F1,int a_F2){ /* printintindex+>a+>a */

a_putchar(a_1339,97);
a_putchar(a_1339,95);
a_putchar(a_1339,a_F1);
a_putchar(a_1339,91);
a_1392(a_F2);
a_putchar(a_1339,93);return;
} /* printintindex */
static void a_1369(int a_F1){ /* formalargument+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_L2=0;a_L4=0;
a_G2:a_1191(a_1420,a_L2,a_P);a_L3=a_P[0];
__incr(a_L2);
if(__equal(a_L3,344288324)){ goto a_G6;}
if(!__equal(a_L3,344288330)){ goto a_G9;}
a_G6:if(!__equal(a_L2,a_F1)){ goto a_G8;}
a_1394(65,a_L4);return;
a_G8:__incr(a_L4); goto a_G2;
a_G9:if(!__equal(a_L3,344288336)){ goto a_G17;}
__incr(a_L2);
__subtr(a_F1,a_L2,a_L2);
if(!__less(a_L2,0)){ goto a_G16;}
a_putchar(a_1339,97);
a_putchar(a_1339,95);
a_putchar(a_1339,67);return;
a_G16:a_1394(86,a_L2);return;
a_G17:if(!__equal(a_L2,a_F1)){ goto a_G2;}
a_putchar(a_1339,97);
a_putchar(a_1339,95);
a_putchar(a_1339,70);
a_1392(a_F1);return;
} /* formalargument */
static void a_1397(int a_F1){ /* printpidginrepr+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
if(!a_1375(a_F1)){ goto a_G8;}
a_putchar(a_1339,95);
a_1116(to_LIST(a_1015)->offset[a_F1-3],a_P);a_L2=a_P[0];
a_L4=1;
a_G5:if(!a_stringelem(a_1016,a_L2,a_L4,a_P)){return;}a_L3=a_P[0];
a_putchar(a_1339,a_L3);
__incr(a_L4); goto a_G5;
a_G8:a_1398(a_F1);return;
} /* printpidginrepr */
static void a_1390(int a_F1){ /* printexternalrepr+>a */

{register int a_r1=to_LIST(a_1015)->offset[a_F1-4];
 if(a_r1==344288252||a_r1==344288257){ goto a_G2;}
 if(a_r1==344288297){  goto a_G3;}
  goto a_G6;}
a_G2:a_1398(a_F1);return;
a_G3:if(!a_1302(a_F1)){ goto a_G2;}
a_1397(a_F1);return;
a_G6:a_putchar(a_1339,97);
a_putchar(a_1339,95);
a_1392(to_LIST(a_1015)->offset[a_F1]);return;
} /* printexternalrepr */
static void a_1399(int a_F1){ /* printrepr+>a */
int a_P[1];
if(!__was(a_1015,a_F1)){ goto a_G9;}
if(a_1053(a_F1,a_P)){a_F1=a_P[0];}
if(!a_1060(a_F1,16)){ goto a_G5;}
a_1390(a_F1);return;
a_G5:{register int a_r1=to_LIST(a_1015)->offset[a_F1-4];
 if(a_r1==344288252||a_r1==344288283){  goto a_G8;}
}
a_putchar(a_1339,97);
a_putchar(a_1339,95);
a_G8:a_1392(to_LIST(a_1015)->offset[a_F1]);return;
a_G9:a_1398(a_F1);return;
} /* printrepr */
static void a_1396(int a_F1){ /* printlocallabel+>a */

a_1395();
a_1392(a_F1);return;
} /* printlocallabel */
static void a_1391(int a_F1){ /* printgoto+>a */

a_G1:{ if(a_F1==0){ goto a_G2;}
 if(a_F1==-1){ goto a_G5;}
 if(a_F1==-2){  goto a_G8;}
  goto a_G9;}
a_G2:if(!a_1060(a_1354,1024)){ goto a_G4;}
a_F1=-1; goto a_G1;
a_G4:a_1117(a_1001,16778303,152);return;
a_G5:if(!a_1060(a_1420,512)){ goto a_G7;}
a_1402(a_1339,a_1001,16778298);return;
a_G7:a_1402(a_1339,a_1001,16778293);return;
a_G8:a_1402(a_1339,a_1001,16778289);return;
a_G9:a_1402(a_1339,a_1001,16778284);
a_1396(a_F1);
a_putchar(a_1339,59);return;
} /* printgoto */
static void a_1389(int a_F1){ /* printGOTO+>a */

if(!__equal(a_F1,a_1382)){ goto a_G3;}
if(__noteq(a_1382,0)){return;}
a_G3:a_1391(a_F1);return;
} /* printGOTO */
static void a_1388(int a_F1){ /* printBUFFER+>a */

{register int a_r1=to_LIST(a_1010)->offset[a_F1];
 if(a_r1==344288412){ goto a_G2;}
 if(a_r1==344288400){ goto a_G4;}
 if(a_r1==344288420){ goto a_G6;}
 if(a_r1==344288416){  goto a_G8;}
  goto a_G10;}
a_G2:__incr(a_F1);
a_1399(to_LIST(a_1010)->offset[a_F1]);return;
a_G4:__incr(a_F1);
a_1392(to_LIST(a_1010)->offset[a_F1]);return;
a_G6:__incr(a_F1);
a_1380(to_LIST(a_1010)->offset[a_F1]);return;
a_G8:__incr(a_F1);
a_1369(to_LIST(a_1010)->offset[a_F1]);return;
a_G10:a_1117(a_1001,16778280,169);return;
} /* printBUFFER */
static void a_1398(int a_F1){ /* printptr+>a */
int a_P[1];
a_G1:if(!__was(a_1015,a_F1)){ goto a_G3;}
a_F1=to_LIST(a_1015)->offset[a_F1-3]; goto a_G1;
a_G3:if(!__was(a_1016,a_F1)){ goto a_G6;}
a_1116(a_F1,a_P);a_F1=a_P[0];
a_1402(a_1339,a_1016,a_F1);return;
a_G6:if(!__was(a_1017,a_F1)){ goto a_G8;}
a_1402(a_1339,a_1017,a_F1);return;
a_G8:if(!__was(a_1010,a_F1)){ goto a_G10;}
a_1388(a_F1);return;
a_G10:a_1117(a_1001,16778275,175);return;
} /* printptr */
static void a_1338(int a_F1,int a_C,int *a_V){ /* T+t[]+*+>a */
int a_L2;int a_L3;
a_L3=to_LIST(a_1010)->aupb;
a_unpackstring(a_F1,a_V[0],a_1010);
__add(a_L3,1,a_L2);
a_G4:if(__less(to_LIST(a_1010)->aupb,a_L2)){ goto a_G36;}
if(!__noteq(to_LIST(a_1010)->offset[a_L2],37)){ goto a_G8;}
a_G6:a_putchar(a_1339,to_LIST(a_1010)->offset[a_L2]);
a_G7:__incr(a_L2); goto a_G4;
a_G8:__incr(a_L2);
if(!__more(a_L2,to_LIST(a_1010)->aupb)){ goto a_G11;}
a_putchar(a_1339,37); goto a_G36;
a_G11:{register int a_r1=to_LIST(a_1010)->offset[a_L2];
 if(a_r1==114){ goto a_G12;}
 if(a_r1==103){ goto a_G16;}
 if(a_r1==71){ goto a_G20;}
 if(a_r1==110){ goto a_G24;}
 if(a_r1==100){ goto a_G26;}
 if(a_r1==112){  goto a_G30;}
  goto a_G6;}
a_G12:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1399(a_V[0]); goto a_G7;
a_G14:a_putchar(a_1339,63); goto a_G7;
a_G16:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1391(a_V[0]); goto a_G7;
a_G20:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1389(a_V[0]); goto a_G7;
a_G24:a_putchar(a_1339,10); goto a_G7;
a_G26:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1392(a_V[0]); goto a_G7;
a_G30:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1398(a_V[0]); goto a_G7;
a_G36:if(a_C<=1){ goto a_G38;} a_C--;a_V+=1;
a_1402(a_1339,a_1001,16778270);
a_G38:__unstackto(a_1010,a_L3);return;
} /* T */
static void a_1263(void){ /* targetprelude */
int a_L1;int a_P[2];
a_P[0]=16778266;a_1338(a_1001,1,a_P);
a_L1=to_LIST(a_1015)->alwb;
a_G3:if(__more(a_L1,to_LIST(a_1015)->aupb)){ goto a_G8;}
{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288233){ goto a_G5;}
 if(a_r1==344288221){  goto a_G6;}
  goto a_G7;}
a_G5:a_P[0]=16778255;a_P[1]=to_LIST(a_1015)->offset[a_L1-3];a_1338(a_1001,2,a_P); goto a_G7;
a_G6:a_P[0]=16778251;a_P[1]=to_LIST(a_1015)->offset[a_L1-3];a_1338(a_1001,2,a_P);
a_G7:__next(a_1015,a_L1); goto a_G3;
a_G8:a_P[0]=16778248;a_1338(a_1001,1,a_P);return;
} /* targetprelude */
static void a_1377(int a_F1,int a_A[1]){ /* iswaitfor+>a+>a> */
int a_P[1];
if(__is(a_A[0])){return;}
if(!a_1053(a_F1,a_P)){return;}a_F1=a_P[0];
if(!a_1060(a_F1,16)){return;}
if(!__equal(to_LIST(a_1015)->offset[a_F1-3],374062101)){return;}
a_A[0]=1;return;
} /* iswaitfor */
static void a_1400(void){ /* procwaitfor */
int a_L1;int a_L2;int a_P[2];
a_P[0]=16778238;a_1338(a_1001,1,a_P);
a_L1=to_LIST(a_1015)->alwb;
a_L2=0;
a_G4:if(__more(a_L1,to_LIST(a_1015)->aupb)){ goto a_G12;}
{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288221){ goto a_G6;}
 if(a_r1==344288233){ goto a_G7;}
 if(a_r1==344288297){  goto a_G8;}
  goto a_G11;}
a_G6:a_L2=to_LIST(a_1015)->offset[a_L1-3]; goto a_G11;
a_G7:a_L2=0; goto a_G11;
a_G8:if(__equal(a_L2,0)){ goto a_G11;}
if(__noteq(374062094,to_LIST(a_1015)->offset[a_L1-3])){ goto a_G11;}
a_P[0]=16778227;a_P[1]=a_L1;a_1338(a_1001,2,a_P);
a_G11:__next(a_1015,a_L1); goto a_G4;
a_G12:a_P[0]=16778216;a_1338(a_1001,1,a_P);return;
} /* procwaitfor */
static void a_1262(void){ /* targetmain */
int a_L1;int a_L2;int a_L3;int a_P[3];
a_L1=to_LIST(a_1015)->alwb;
a_L2=0;
a_L3=0;
a_G4:if(__more(a_L1,to_LIST(a_1015)->aupb)){ goto a_G13;}
{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288221){ goto a_G6;}
 if(a_r1==344288233){ goto a_G7;}
 if(a_r1==344288297){  goto a_G8;}
  goto a_G12;}
a_G6:a_L2=to_LIST(a_1015)->offset[a_L1-3]; goto a_G12;
a_G7:a_L2=0; goto a_G12;
a_G8:a_P[0]=a_L3;a_1377(a_L1,a_P);a_L3=a_P[0];
if(__equal(a_L2,0)){ goto a_G12;}
if(__noteq(374062094,to_LIST(a_1015)->offset[a_L1-3])){ goto a_G12;}
a_P[0]=16778210;a_P[1]=a_L1;a_P[2]=a_L2;a_1338(a_1001,3,a_P);
a_G12:__next(a_1015,a_L1); goto a_G4;
a_G13:if(__equal(a_L3,0)){ goto a_G15;}
a_1400();
a_G15:a_P[0]=16778203;a_1338(a_1001,1,a_P);
a_L1=to_LIST(a_1015)->alwb;
a_L2=0;
a_G18:if(__more(a_L1,to_LIST(a_1015)->aupb)){ goto a_G26;}
{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288221){ goto a_G20;}
 if(a_r1==344288233){ goto a_G21;}
 if(a_r1==344288297){  goto a_G22;}
  goto a_G25;}
a_G20:a_L2=to_LIST(a_1015)->offset[a_L1-3]; goto a_G25;
a_G21:a_L2=0; goto a_G25;
a_G22:if(__equal(a_L2,0)){ goto a_G25;}
if(__noteq(374062094,to_LIST(a_1015)->offset[a_L1-3])){ goto a_G25;}
a_P[0]=16778191;a_P[1]=a_L1;a_P[2]=a_L2;a_1338(a_1001,3,a_P);
a_G25:__next(a_1015,a_L1); goto a_G18;
a_G26:a_L1=to_LIST(a_1015)->alwb;
a_L2=0;
a_G28:if(__more(a_L1,to_LIST(a_1015)->aupb)){ goto a_G36;}
{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288221){ goto a_G30;}
 if(a_r1==344288233){ goto a_G31;}
 if(a_r1==344288297){  goto a_G32;}
  goto a_G35;}
a_G30:a_L2=0; goto a_G35;
a_G31:a_L2=to_LIST(a_1015)->offset[a_L1-3]; goto a_G35;
a_G32:if(__equal(a_L2,0)){ goto a_G35;}
if(__noteq(374062094,to_LIST(a_1015)->offset[a_L1-3])){ goto a_G35;}
a_P[0]=16778183;a_P[1]=a_L1;a_P[2]=a_L2;a_1338(a_1001,3,a_P);
a_G35:__next(a_1015,a_L1); goto a_G28;
a_G36:a_P[0]=16778176;a_1338(a_1001,1,a_P);return;
} /* targetmain */
static void a_1414(int a_F1){ /* ruletyper+>a */
int a_P[2];
if(!a_1060(a_F1,512)){ goto a_G3;}
a_P[0]=16778173;a_P[1]=a_F1;a_1338(a_1001,2,a_P);return;
a_G3:a_P[0]=16778167;a_P[1]=a_F1;a_1338(a_1001,2,a_P);return;
} /* ruletyper */
static void a_1363(int a_F1){ /* externalruletyper+>a */
int a_P[2];
if(!a_1060(a_F1,512)){ goto a_G3;}
a_P[0]=16778161;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,2,a_P);return;
a_G3:a_P[0]=16778155;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,2,a_P);return;
} /* externalruletyper */
static void a_1350(int a_A[1]){ /* argsep+>a> */

if(!__equal(a_A[0],0)){ goto a_G3;}
a_A[0]=1;return;
a_G3:a_putchar(a_1339,44);return;
} /* argsep */
static void a_1383(int a_F1,int a_A[1]){ /* outargs+>a+>a> */
int a_P[2];
if(__equal(a_F1,0)){return;}
a_P[0]=a_A[0];a_1350(a_P);a_A[0]=a_P[0];
a_P[0]=16778149;a_P[1]=a_F1;a_1338(a_1001,2,a_P);return;
} /* outargs */
static void a_1412(int a_F1){ /* ruleargs+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
a_1192(a_F1,a_P);a_L2=a_P[0];
a_L3=0;a_L5=0;a_L6=0;
a_G3:if(!__less(a_L3,a_L2)){ goto a_G15;}
a_1191(a_F1,a_L3,a_P);a_L4=a_P[0];
__incr(a_L3);
if(__equal(a_L4,344288324)){ goto a_G8;}
if(!__equal(a_L4,344288330)){ goto a_G9;}
a_G8:__incr(a_L5); goto a_G3;
a_G9:if(!__equal(a_L4,344288336)){ goto a_G13;}
a_P[0]=a_L6;a_1383(a_L5,a_P);a_L6=a_P[0];
a_P[0]=a_L6;a_1350(a_P);
a_P[0]=16778144;a_1338(a_1001,1,a_P);return;
a_G13:a_P[0]=a_L6;a_1350(a_P);a_L6=a_P[0];
a_P[0]=16778137;a_P[1]=a_L3;a_1338(a_1001,2,a_P); goto a_G3;
a_G15:if(!__equal(a_L2,0)){ goto a_G17;}
a_P[0]=16778132;a_1338(a_1001,1,a_P); goto a_G18;
a_G17:a_P[0]=a_L6;a_1383(a_L5,a_P);
a_G18:a_putchar(a_1339,41);return;
} /* ruleargs */
static int a_1302(int a_F1){ /* ispidginrule+>a */
int a_L2;int a_P[1];
if(!a_1060(a_F1,16)){ return 0;}
a_1116(to_LIST(a_1015)->offset[a_F1-3],a_P);a_L2=a_P[0];
if(!a_stringelem(a_1016,a_L2,0,a_P)){ return 0;}a_L2=a_P[0];
{ if((97<=a_L2 && a_L2<=122)||(65<=a_L2 && a_L2<=90)){  return 0;}
  return 1;}
} /* ispidginrule */
static int a_1375(int a_F1){ /* ispidginalt+>a */
int a_L2;int a_P[1];
a_1116(to_LIST(a_1015)->offset[a_F1-3],a_P);a_L2=a_P[0];
if(!a_stringelem(a_1016,a_L2,0,a_P)){ return 0;}a_L2=a_P[0];
if(!__equal(a_L2,64)){ return 0;} return 1;
} /* ispidginalt */
static void a_1415(int a_F1){ /* showformalsascomment+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
 static char *a_rulename="showformalsascomment";
a_1192(a_F1,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(__mreq(a_L3,a_L2)){return;}
a_1191(a_F1,a_L3,a_P);a_L4=a_P[0];
__incr(a_L3);
{ if(a_L4==344288319){ goto a_G7;}
 if(a_L4==344288324){ goto a_G8;}
 if(a_L4==344288330){ goto a_G9;}
 if(a_L4==344288309){ goto a_G10;}
 if(a_L4==344288303){ goto a_G11;}
 if(a_L4==344288314){ goto a_G12;}
 if(!(a_L4==344288336)){a_area_failed(a_rulename,a_L4);}
  goto a_G13;}
a_G7:a_P[0]=16778128;a_1338(a_1001,1,a_P); goto a_G3;
a_G8:a_P[0]=16778125;a_1338(a_1001,1,a_P); goto a_G3;
a_G9:a_P[0]=16778122;a_1338(a_1001,1,a_P); goto a_G3;
a_G10:a_P[0]=16778118;a_1338(a_1001,1,a_P); goto a_G3;
a_G11:a_P[0]=16778114;a_1338(a_1001,1,a_P); goto a_G3;
a_G12:a_P[0]=16778110;a_1338(a_1001,1,a_P); goto a_G3;
a_G13:a_P[0]=16778106;a_1338(a_1001,1,a_P); goto a_G3;
} /* showformalsascomment */
static void a_1360(int a_F1,int a_F2,int a_F3){ /* declarelocals+>a+>a+>a */
int a_P[2];
a_G1:if(__equal(a_F1,0)){return;}
if(__more(a_F1,a_F2)){return;}
if(!__equal(to_LIST(a_1010)->offset[a_F3],0)){ goto a_G6;}
a_G4:__incr(a_F1);
__incr(a_F3); goto a_G1;
a_G6:a_P[0]=16778103;a_P[1]=a_F1;a_1338(a_1001,2,a_P); goto a_G4;
} /* declarelocals */
static void a_1359(int a_F1,int a_F2,int a_F3,int a_F4){ /* declarecallargs+>a+>a+>a+>a */
int a_L5;int a_P[3];
if(__equal(a_F3,0)){ goto a_G3;}
a_P[0]=16778098;a_P[1]=a_F3;a_1338(a_1001,2,a_P);
a_G3:if(__equal(a_F4,0)){ goto a_G6;}
a_1193(a_F1,a_P);a_L5=a_P[0];
a_P[0]=16778092;a_P[1]=a_F4;a_P[2]=a_L5;a_1338(a_1001,3,a_P);
a_G6:a_putchar(a_1339,10);return;
} /* declarecallargs */
static void a_1348(void){ /* addrulenameasstatic */
int a_P[2];
if(!__is(a_1418)){return;}
a_P[0]=16778079;a_P[1]=a_1420;a_1338(a_1001,2,a_P);return;
} /* addrulenameasstatic */
static void a_1347(void){ /* addprofiling */
int a_P[1];
if(!a_1060(a_1420,33554432)){return;}
a_P[0]=16778068;a_1338(a_1001,1,a_P);return;
} /* addprofiling */
static void a_1349(void){ /* addtracing */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[2];
if(!a_1060(a_1420,16777216)){return;}
a_1192(a_1420,a_P);a_L1=a_P[0];
a_L3=0;a_L2=0;
a_G4:if(__mreq(a_L3,a_L1)){ goto a_G9;}
a_1191(a_1420,a_L3,a_P);a_L4=a_P[0];
__incr(a_L3);
if(__equal(a_L4,344288324)){ goto a_G4;}
__incr(a_L2); goto a_G4;
a_G9:a_P[0]=16778045;a_P[1]=a_L2;a_1338(a_1001,2,a_P);
a_L3=0;
a_G11:if(__mreq(a_L3,a_L1)){ goto a_G17;}
a_1191(a_1420,a_L3,a_P);a_L4=a_P[0];
__incr(a_L3);
if(__equal(a_L4,344288324)){ goto a_G11;}
a_putchar(a_1339,44);
a_1369(a_L3); goto a_G11;
a_G17:a_P[0]=16778036;a_1338(a_1001,1,a_P);return;
} /* addtracing */
static void a_1314(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6,int a_F7,int a_F8){ /* ruledeclarationhead+>a+>a+>a+>a+>a+>a+>a+>a */
int a_P[2];
a_1420=a_F1;
a_1418=a_F5;
a_1414(a_F1);
a_1412(a_F1);
a_P[0]=16778032;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,2,a_P);
a_1415(a_F1);
a_P[0]=16778028;a_1338(a_1001,1,a_P);
__add(a_F6,a_F8,a_F8);
a_1360(a_F6,a_F7,a_F8);
a_1359(a_F1,a_F2,a_F3,a_F4);
a_1348();
a_1347();
a_1349();return;
} /* ruledeclarationhead */
static void a_1315(void){ /* ruledeclarationtail */
int a_P[2];
a_P[0]=16778024;a_P[1]=a_1420;a_1338(a_1001,2,a_P);return;
} /* ruledeclarationtail */
static int a_1362(int a_F1){ /* externalplaindeclaration+>a */
int a_P[2];
if(!a_1060(a_F1,16)){ return 0;}
a_P[0]=16778018;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,2,a_P); return 1;
} /* externalplaindeclaration */
static void a_1422(int a_F1){ /* vardeclaration+>a */
int a_P[4];
if(a_1362(a_F1)){return;}
a_P[0]=16778011;a_P[1]=a_F1;a_P[2]=to_LIST(a_1015)->offset[a_F1-1];a_P[3]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,4,a_P);return;
} /* vardeclaration */
static void a_1352(int a_F1,int a_F2,int a_F3){ /* blockdeclaration+>a+>a+>a */
int a_P[3];
a_P[0]=16778001;a_P[1]=a_F1;a_1338(a_1001,2,a_P);
if(!__equal(a_F2,0)){ goto a_G4;}
a_P[0]=16777995;a_1338(a_1001,1,a_P); goto a_G5;
a_G4:a_P[0]=16777992;a_P[1]=a_F2;a_P[2]=a_F3;a_1338(a_1001,3,a_P);
a_G5:a_P[0]=16777988;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,2,a_P);
if(!a_1060(a_F1,16)){return;}
a_P[0]=16777982;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,2,a_P);return;
} /* blockdeclaration */
static void a_1413(int a_F1){ /* ruleprototype+>a */
int a_P[2];
if(a_1302(a_F1)){return;}
if(a_1198(a_F1,a_P)){return;}
if(!a_1060(a_F1,16)){ goto a_G7;}
a_1363(a_F1);
a_1412(a_F1);
a_P[0]=16777973;a_1338(a_1001,1,a_P);return;
a_G7:a_1414(a_F1);
a_1412(a_F1);
a_P[0]=16777970;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,2,a_P);return;
} /* ruleprototype */
static void a_1251(void){ /* datadeclaration */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[4];
a_L3=0;a_L4=0;
a_L1=to_LIST(a_1015)->alwb;
a_G3:if(__more(a_L1,to_LIST(a_1015)->aupb)){ goto a_G20;}
if(!a_1053(a_L1,a_P)){ goto a_G7;}a_L2=a_P[0];
if(!__noteq(a_L1,a_L2)){ goto a_G7;}
a_G6:__next(a_1015,a_L1); goto a_G3;
a_G7:{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288252){ goto a_G6;}
 if(a_r1==344288257||a_r1==344288262){ goto a_G8;}
 if(a_r1==344288270||a_r1==344288266||a_r1==344288276){ goto a_G9;}
 if(a_r1==344288288){ goto a_G12;}
 if(a_r1==344288293){ goto a_G15;}
 if(a_r1==344288297){  goto a_G18;}
  goto a_G6;}
a_G8:a_1422(a_L1); goto a_G6;
a_G9:a_1352(a_L1,a_L3,a_L4);
a_L3=a_L1;
a_L4=1922290842; goto a_G6;
a_G12:a_1352(a_L1,a_L3,a_L4);
a_L3=a_L1;
a_L4=1922290848; goto a_G6;
a_G15:a_1352(a_L1,a_L3,a_L4);
a_L3=a_L1;
a_L4=1922290854; goto a_G6;
a_G18:a_1413(a_L1); goto a_G6;
a_G20:if(!__equal(a_L3,0)){ goto a_G22;}
a_P[0]=16777964;a_P[1]=1922290859;a_1338(a_1001,2,a_P); goto a_G23;
a_G22:a_P[0]=16777958;a_P[1]=1922290859;a_P[2]=a_L3;a_P[3]=a_L4;a_1338(a_1001,4,a_P);
a_G23:a_P[0]=16777950;a_P[1]=1922290859;a_1338(a_1001,2,a_P);return;
} /* datadeclaration */
static void a_1401(int a_F1){ /* pushBUFFER+>a */

 a_extension(a_1010,1);to_LIST(a_1010)->top[1]=a_F1;to_LIST(a_1010)->aupb+=1;
 return;
} /* pushBUFFER */
static void a_1255(void){ /* filltablehead */
int a_P[1];
a_P[0]=16777942;a_1338(a_1001,1,a_P);
a_1367=0;return;
} /* filltablehead */
static void a_1256(void){ /* filltabletail */
int a_P[2];
a_P[0]=16777929;a_P[1]=a_1367;a_1338(a_1001,2,a_P);return;
} /* filltabletail */
static void a_1356(int a_A[1]){ /* constitem+a> */
int a_P[1];
if(!__equal(344288400,a_1058)){ goto a_G4;}
a_A[0]=a_1059;
a_1078();return;
a_G4:if(!__equal(344288412,a_1058)){ goto a_G7;}
a_A[0]=a_1059;
a_1078(); goto a_G8;
a_G7:a_1030(a_1001,16777439,44);return;
a_G8:if(a_1053(a_A[0],a_P)){a_A[0]=a_P[0];}
{register int a_r1=to_LIST(a_1015)->offset[a_A[0]-4];
 if(!(a_r1==344288252||a_r1==344288283)){ goto a_G11;}
}
a_A[0]=to_LIST(a_1015)->offset[a_A[0]];return;
a_G11:a_1117(a_1001,16777919,439);return;
} /* constitem */
static void a_1365(int a_A[1]){ /* fillitem+a> */
int a_L2;int a_P[1];
if(!__equal(344288372,a_1058)){ goto a_G9;}
a_1078();
a_A[0]=0;
a_G4:if(!__equal(344288351,a_1058)){ goto a_G6;}
a_1078();return;
a_G6:__incr(a_A[0]);
a_1356(a_P);a_L2=a_P[0];
a_1401(a_L2); goto a_G4;
a_G9:a_A[0]=1;
a_1356(a_P);a_L2=a_P[0];
a_1401(a_L2);return;
} /* fillitem */
static int a_1366(int a_A[1]){ /* fillrepeater+a> */
int a_P[1];
if(!__equal(344288390,a_1058)){ return 0;}
a_1078();
a_1356(a_P);a_A[0]=a_P[0]; return 1;
} /* fillrepeater */
static void a_1368(int a_F1,int a_F2,int a_F3){ /* flushbuffer+>a+>a+>a */
int a_P[2];
__add(a_F1,a_1367,a_1367);
__add(a_F2,a_1367,a_1367);
__incr(a_F3);
if(__equal(a_F1,0)){ goto a_G7;}
a_P[0]=16777914;a_P[1]=a_F1;a_1338(a_1001,2,a_P);
__incr(a_1367);
a_G7:if(__equal(a_F1,0)){ goto a_G11;}
a_P[0]=16777911;a_P[1]=to_LIST(a_1010)->offset[a_F3];a_1338(a_1001,2,a_P);
__incr(a_F3);
__decr(a_F1); goto a_G7;
a_G11:if(__equal(a_F2,0)){ goto a_G14;}
a_P[0]=16777908;a_P[1]=a_F2;a_1338(a_1001,2,a_P);
__incr(a_1367);
a_G14:if(__equal(a_F2,0)){return;}
a_P[0]=16777905;a_P[1]=to_LIST(a_1010)->offset[a_F3];a_1338(a_1001,2,a_P);
__incr(a_F3);
__decr(a_F2); goto a_G14;
} /* flushbuffer */
static void a_1417(void){ /* skipfillinitializer */

a_G1:if(!__equal(344288354,a_1058)){return;}
a_1078();
if(!__equal(344288412,a_1058)){ goto a_G6;}

a_1078(); goto a_G1;
a_G6:a_1030(a_1001,16777439,44);return;
} /* skipfillinitializer */
static void a_1364(void){ /* fillentries */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_P[3];
if(!__equal(344288412,a_1058)){ goto a_G4;}
a_L1=a_1059;
a_1078(); goto a_G5;
a_G4:a_1030(a_1001,16777439,44);return;
a_G5:if(!__equal(344288400,a_1058)){ goto a_G4;}

a_1078();
__incr(a_1367);
a_P[0]=16777902;a_P[1]=a_L1;a_P[2]=to_LIST(a_1015)->offset[a_L1-3];a_1338(a_1001,3,a_P);
a_L2=to_LIST(a_1010)->aupb;
a_L3=0;
a_G13:if(!__equal(344288384,a_1058)){ goto a_G15;}
a_1078(); goto a_G24;
a_G15:a_1365(a_P);a_L4=a_P[0];
if(!a_1366(a_P)){ goto a_G22;}a_L5=a_P[0];
a_1368(a_L3,a_L4,a_L2);
a_P[0]=16777896;a_P[1]=a_L5;a_1338(a_1001,2,a_P);
__incr(a_1367);
__unstackto(a_1010,a_L2);
a_L3=0; goto a_G23;
a_G22:__add(a_L3,a_L4,a_L3);
a_G23:a_1417(); goto a_G13;
a_G24:a_1368(a_L3,0,a_L2);
__unstackto(a_1010,a_L2);
__incr(a_1367);
a_P[0]=16777892;a_1338(a_1001,1,a_P);return;
} /* fillentries */
static void a_1416(void){ /* skipentry */

a_G1:if(!__equal(344288384,a_1058)){ goto a_G3;}
a_1078();return;
a_G3:a_1078(); goto a_G1;
} /* skipentry */
static void a_1253(void){ /* datasectioniii */

a_G1:if(!__equal(344288197,a_1058)){ goto a_G4;}
a_G2:a_1078();
a_1416(); goto a_G1;
a_G4:if(__equal(344288214,a_1058)){ goto a_G2;}
if(__equal(344288206,a_1058)){ goto a_G2;}
if(!__equal(344288210,a_1058)){return;}
a_1078();
a_1364(); goto a_G1;
} /* datasectioniii */
static void a_1254(void){ /* datasectioniv */

a_G1:if(!__equal(344288197,a_1058)){ goto a_G4;}
a_G2:a_1078();
a_1416(); goto a_G1;
a_G4:if(__equal(344288214,a_1058)){ goto a_G2;}
if(__equal(344288206,a_1058)){ goto a_G2;}
if(__equal(344288210,a_1058)){ goto a_G2;}
a_G13:if(!__equal(344288229,a_1058)){ goto a_G16;}
a_1078();
a_1304(); goto a_G13;
a_G16:if(!__equal(344288427,a_1058)){ goto a_G18;}
a_1078();return;
a_G18:a_1030(a_1001,16777888,484);return;
} /* datasectioniv */
static void a_1271(int a_F1,int a_F2){ /* Tlabel+>a+>a */

a_1382=a_F2;
if(__equal(a_F1,0)){return;}
a_1396(a_F1);
a_putchar(a_1339,58);return;
} /* Tlabel */
static void a_1378(int a_F1){ /* jumptolabel+>a */
int a_P[2];
if(__equal(a_F1,a_1382)){return;}
a_P[0]=16777884;a_P[1]=a_F1;a_1338(a_1001,2,a_P);return;
} /* jumptolabel */
static void a_1345(int a_F1,int a_A[1]){ /* Tlimittail+>a+a> */

{ if(a_F1==344288192){ goto a_G2;}
 if(a_F1==344288217){ goto a_G3;}
 if(a_F1==344288239){ goto a_G4;}
 if(a_F1==344288243){ goto a_G5;}
 if(a_F1==344288247){  goto a_G6;}
  goto a_G7;}
a_G2:a_A[0]=1922290863;return;
a_G3:a_A[0]=1922290867;return;
a_G4:a_A[0]=1922290871;return;
a_G5:a_A[0]=1922290875;return;
a_G6:a_A[0]=1922290879;return;
a_G7:a_1030(a_1001,16777880,516);return;
} /* Tlimittail */
static void a_1340(int a_F1){ /* Taffix+>a */
int a_P[1];
{register int a_r1=to_LIST(a_1010)->offset[a_F1];
 if(a_r1==344288354){ goto a_G2;}
 if(a_r1==344288369){ return;}
  goto a_G3;}
a_G2:__incr(a_F1);
a_G3:a_P[0]=a_F1;a_1341(a_P);return;
} /* Taffix */
static void a_1343(int a_A[1]){ /* Tindex+>a> */
int a_L2;int a_P[3];
if(!a_1060(a_1420,67108864)){ goto a_G10;}
a_P[0]=16777876;a_P[1]=a_A[0];a_P[2]=a_A[0];a_1338(a_1001,3,a_P);
__incr(a_A[0]);
__incr(a_A[0]);
a_P[0]=a_A[0];a_1341(a_P);a_A[0]=a_P[0];
__incr(a_A[0]);
__subtr(to_LIST(a_1010)->offset[a_A[0]],1,a_L2);
__incr(a_A[0]);
a_P[0]=16777865;a_P[1]=a_L2;a_1338(a_1001,2,a_P);return;
a_G10:a_P[0]=16777858;a_P[1]=a_A[0];a_1338(a_1001,2,a_P);
__incr(a_A[0]);
__incr(a_A[0]);
a_P[0]=a_A[0];a_1341(a_P);a_A[0]=a_P[0];
__incr(a_A[0]);
__subtr(to_LIST(a_1010)->offset[a_A[0]],1,a_L2);
__incr(a_A[0]);
if(!__equal(a_L2,0)){ goto a_G19;}
a_P[0]=16777850;a_1338(a_1001,1,a_P);return;
a_G19:a_P[0]=16777847;a_P[1]=a_L2;a_1338(a_1001,2,a_P);return;
} /* Tindex */
static void a_1341(int a_A[1]){ /* Taffixinner+>a> */
int a_L2;int a_P[3];
{register int a_r1=to_LIST(a_1010)->offset[a_A[0]];
 if(a_r1==344288416||a_r1==344288420||a_r1==344288412||a_r1==344288400){ goto a_G2;}
 if(a_r1==344288393){  goto a_G5;}
  goto a_G7;}
a_G2:a_P[0]=16777843;a_P[1]=a_A[0];a_1338(a_1001,2,a_P);
a_G3:__incr(a_A[0]);
__incr(a_A[0]);return;
a_G5:__incr(a_A[0]);
a_P[0]=a_A[0];a_1343(a_P);a_A[0]=a_P[0];return;
a_G7:a_1345(to_LIST(a_1010)->offset[a_A[0]],a_P);a_L2=a_P[0];
__incr(a_A[0]);
a_P[0]=16777840;a_P[1]=a_A[0];a_P[2]=a_L2;a_1338(a_1001,3,a_P); goto a_G3;
} /* Taffixinner */
static void a_1372(int a_F1,int a_F2){ /* genshiftaffix+>a+>a */
int a_L3;int a_P[4];
a_1193(a_1420,a_P);a_L3=a_P[0];
if(__equal(a_F1,a_1382)){ goto a_G6;}
if(!__equal(a_F1,a_F2)){ goto a_G5;}
a_F2=a_1382; goto a_G6;
a_G5:if(!__noteq(a_F2,a_1382)){ goto a_G7;}
a_G6:a_P[0]=16777834;a_P[1]=a_L3;a_P[2]=a_F2;a_P[3]=a_F1;a_1338(a_1001,4,a_P);return;
a_G7:a_P[0]=16777823;a_P[1]=a_F1;a_P[2]=a_L3;a_1338(a_1001,3,a_P);return;
} /* genshiftaffix */
static void a_1371(int a_F1,int a_F2,int a_F3){ /* gengetaffixno+>a+>a+>a */
int a_P[2];
if(!__noteq(a_F1,2)){ goto a_G3;}
a_1030(a_1001,16777813,551);return;
a_G3:if(__equal(to_LIST(a_1010)->offset[a_F2],344288369)){return;}
if(__equal(to_LIST(a_1010)->offset[a_F2],344288354)){return;}
a_1340(a_F2);
a_P[0]=16777809;a_P[1]=a_F3;a_1338(a_1001,2,a_P);return;
} /* gengetaffixno */
static void a_1381(int a_A[1]){ /* nextaffix+>a> */

a_G1:if(!__equal(to_LIST(a_1010)->offset[a_A[0]],344288381)){ goto a_G3;}
__incr(a_A[0]);return;
a_G3:__incr(a_A[0]); goto a_G1;
} /* nextaffix */
static void a_1351(int a_F1,int a_F2,int a_A[2]){ /* assignmentsource+>a+>a+a>+a> */
int a_P[2];
{register int a_r1=to_LIST(a_1010)->offset[a_F1];
 if(!(a_r1==344288412||a_r1==344288420||a_r1==344288416||a_r1==344288400)){ goto a_G7;}
}
a_A[0]=a_F1;
if(!__is(a_F2)){ goto a_G6;}
a_P[0]=16777804;a_P[1]=1922290887;a_1338(a_1001,2,a_P);
a_G5:a_A[1]=1;return;
a_G6:a_A[1]=0;return;
a_G7:a_A[0]=1922290883;
a_P[0]=16777797;a_P[1]=a_A[0];a_1338(a_1001,2,a_P);
a_1340(a_F1);
if(!__is(a_F2)){ goto a_G12;}
a_P[0]=16777790;a_P[1]=1922290887;a_1338(a_1001,2,a_P);
a_G12:a_putchar(a_1339,59); goto a_G5;
} /* assignmentsource */
static void a_1370(int a_F1,int a_F2,int a_F3,int a_F4){ /* genassignment+>a+>a+>a+>a */
int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[6];
a_L5=a_F3;
a_P[0]=a_F3;a_1381(a_P);a_F3=a_P[0];
a_L8=0;
a_L9=1;
a_G5:if(__mreq(a_L9,a_F1)){ goto a_G10;}
__incr(a_L9);
a_P[0]=a_F3;a_1381(a_P);a_F3=a_P[0];
{register int a_r1=to_LIST(a_1010)->offset[a_F3];
 if(a_r1==344288390||a_r1==344288369||a_r1==344288354){  goto a_G5;}
}
__incr(a_L8); goto a_G5;
a_G10:if(__more(a_L8,1)){ goto a_G12;}
if(!__is(a_F2)){ goto a_G13;}
a_G12:a_1351(a_L5,a_F2,a_P);a_L6=a_P[0];a_L7=a_P[1]; goto a_G14;
a_G13:a_L6=0;a_L7=0;
a_G14:a_F3=a_L5;
a_P[0]=a_F3;a_1381(a_P);a_F3=a_P[0];
a_L9=1;
a_G17:if(__mreq(a_L9,a_F1)){ goto a_G27;}
__incr(a_L9);
a_P[0]=a_F3;a_1381(a_P);a_F3=a_P[0];
{register int a_r1=to_LIST(a_1010)->offset[a_F3];
 if(a_r1==344288390||a_r1==344288369||a_r1==344288354){  goto a_G17;}
}
a_1340(a_F3);
if(!__equal(a_L6,0)){ goto a_G26;}
a_putchar(a_1339,61);
a_1340(a_L5);
a_putchar(a_1339,59); goto a_G17;
a_G26:a_P[0]=16777787;a_P[1]=a_L6;a_1338(a_1001,2,a_P); goto a_G17;
a_G27:if(__equal(a_F2,0)){ goto a_G29;}
a_P[0]=16777783;a_P[1]=1922290887;a_P[2]=1922290887;a_P[3]=1922290887;a_P[4]=1922290887;a_P[5]=a_L6;a_1338(a_1001,6,a_P);
a_G29:if(__equal(a_L7,0)){ goto a_G31;}
a_putchar(a_1339,125);
a_G31:a_P[0]=16777772;a_P[1]=a_F4;a_1338(a_1001,2,a_P);return;
} /* genassignment */
static void a_1411(int a_F1,int a_F2,int a_F3,int a_F4){ /* repeatblockpreload+>a+>a+>a+>a */
int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[3];
__incr(a_F1);
a_L5=to_LIST(a_1010)->offset[a_F1];
a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0];
a_L9=a_F3;
if(!__less(a_L5,0)){ goto a_G8;}
a_F4=0;
__subtr(0,a_L5,a_L7); goto a_G9;
a_G8:a_L7=a_L5;
a_G9:a_1193(a_1354,a_P);a_L6=a_P[0];
__mult(a_L7,a_L6,a_L7);
a_G11:if(__equal(a_L7,0)){ goto a_G27;}
a_1191(a_1354,a_L9,a_P);a_L8=a_P[0];
if(__equal(a_L8,344288324)){ goto a_G21;}
if(!__more(a_L5,0)){ goto a_G18;}
a_P[0]=16777768;a_P[1]=a_F4;a_1338(a_1001,2,a_P);
a_G16:a_1340(a_F1);
a_putchar(a_1339,59); goto a_G21;
a_G18:a_P[0]=16777763;a_P[1]=a_F4;a_1338(a_1001,2,a_P); goto a_G16;
a_G21:__incr(a_L9);
if(__less(a_L9,a_F2)){ goto a_G24;}
a_L9=a_F3;
a_G24:__decr(a_L7);
__incr(a_F4);
a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0]; goto a_G11;
a_G27:if(__mreq(a_L5,0)){return;}
a_P[0]=16777758;a_P[1]=a_F4;a_P[2]=a_L6;a_1338(a_1001,3,a_P);return;
} /* repeatblockpreload */
static void a_1407(int a_F1){ /* regularcallpreload+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
a_1192(a_1354,a_P);a_L2=a_P[0];
a_L3=0;a_L4=0;
a_G3:if(__equal(a_L3,a_L2)){return;}
a_1191(a_1354,a_L3,a_P);a_L5=a_P[0];
__incr(a_L3);
if(!__equal(a_L5,344288324)){ goto a_G9;}
__incr(a_L4);
a_G8:a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0]; goto a_G3;
a_G9:if(!__equal(a_L5,344288330)){ goto a_G15;}
a_P[0]=16777746;a_P[1]=a_L4;a_1338(a_1001,2,a_P);
__incr(a_L4);
a_1340(a_F1);
a_putchar(a_1339,59); goto a_G8;
a_G15:if(!__equal(a_L5,344288336)){ goto a_G8;}
a_1411(a_F1,a_L2,a_L3,a_L4);return;
} /* regularcallpreload */
static void a_1409(int a_F1,int a_F2,int a_F3){ /* repeatblockcall+>a+>a+>a */
int a_L4;int a_P[3];
if(__equal(a_F2,0)){ goto a_G4;}
a_P[0]=a_F3;a_1350(a_P);a_F3=a_P[0];
a_P[0]=16777741;a_1338(a_1001,1,a_P);
a_G4:__incr(a_F1);
a_L4=to_LIST(a_1010)->offset[a_F1];
a_P[0]=a_F3;a_1350(a_P);
if(!__equal(a_L4,0)){ goto a_G9;}
a_P[0]=16777738;a_1338(a_1001,1,a_P);return;
a_G9:if(!__less(a_L4,0)){ goto a_G12;}
__subtr(0,a_L4,a_L4);
a_P[0]=16777733;a_P[1]=a_L4;a_1338(a_1001,2,a_P);return;
a_G12:if(!__equal(a_F2,0)){ goto a_G14;}
a_P[0]=16777728;a_P[1]=a_L4;a_1338(a_1001,2,a_P);return;
a_G14:a_P[0]=16777724;a_P[1]=a_L4;a_P[2]=a_F2;a_1338(a_1001,3,a_P);return;
} /* repeatblockcall */
static void a_1408(int a_F1){ /* regularrulecall+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
a_1192(a_1354,a_P);a_L2=a_P[0];
a_P[0]=16777719;a_P[1]=a_1354;a_1338(a_1001,2,a_P);
a_L3=0;a_L4=0;a_L5=0;
a_G4:if(!__equal(a_L3,a_L2)){ goto a_G9;}
if(!__equal(a_L4,0)){ goto a_G7;}
a_putchar(a_1339,41);return;
a_G7:a_P[0]=a_L5;a_1350(a_P);
a_P[0]=16777716;a_1338(a_1001,1,a_P);return;
a_G9:a_1191(a_1354,a_L3,a_P);a_L6=a_P[0];
__incr(a_L3);
if(__equal(a_L6,344288324)){ goto a_G13;}
if(!__equal(a_L6,344288330)){ goto a_G15;}
a_G13:__incr(a_L4);
a_G14:a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0]; goto a_G4;
a_G15:if(!__equal(a_L6,344288336)){ goto a_G17;}
a_1409(a_F1,a_L4,a_L5);return;
a_G17:a_P[0]=a_L5;a_1350(a_P);a_L5=a_P[0];
a_1340(a_F1); goto a_G14;
} /* regularrulecall */
static int a_1374(int a_F1){ /* isdummyaffix+>a */

{register int a_r1=to_LIST(a_1010)->offset[a_F1];
 if(a_r1==344288369||a_r1==344288354){  return 1;}
  return 0;}
} /* isdummyaffix */
static void a_1410(int a_F1,int a_F2,int a_F3,int a_F4){ /* repeatblockpostload+>a+>a+>a+>a */
int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[3];
__incr(a_F1);
a_L5=to_LIST(a_1010)->offset[a_F1];
a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0];
a_L7=a_F3;
if(!__less(a_L5,0)){ goto a_G8;}
a_F4=0;
__subtr(0,a_L5,a_L8); goto a_G9;
a_G8:a_L8=a_L5;
a_G9:a_1193(a_1354,a_P);a_L6=a_P[0];
__mult(a_L8,a_L6,a_L8);
a_G11:if(__equal(a_L8,0)){ goto a_G26;}
a_1191(a_1354,a_L7,a_P);a_L9=a_P[0];
if(a_1374(a_F1)){ goto a_G20;}
if(__equal(a_L9,344288324)){ goto a_G16;}
if(!__equal(a_L9,344288330)){ goto a_G20;}
a_G16:a_1340(a_F1);
if(!__more(a_L5,0)){ goto a_G19;}
a_P[0]=16777712;a_P[1]=a_F4;a_1338(a_1001,2,a_P); goto a_G20;
a_G19:a_P[0]=16777707;a_P[1]=a_F4;a_1338(a_1001,2,a_P);
a_G20:__incr(a_L7);
if(__less(a_L7,a_F2)){ goto a_G23;}
a_L7=a_F3;
a_G23:__decr(a_L8);
__incr(a_F4);
a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0]; goto a_G11;
a_G26:if(__mreq(a_L5,0)){return;}
a_P[0]=16777702;a_P[1]=a_F4;a_P[2]=a_L6;a_1338(a_1001,3,a_P);return;
} /* repeatblockpostload */
static void a_1406(int a_F1){ /* regularcallpostload+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
a_1192(a_1354,a_P);a_L2=a_P[0];
a_L3=0;a_L4=0;
a_G3:if(__equal(a_L3,a_L2)){return;}
a_1191(a_1354,a_L3,a_P);a_L5=a_P[0];
__incr(a_L3);
if(__equal(a_L5,344288324)){ goto a_G8;}
if(!__equal(a_L5,344288330)){ goto a_G13;}
a_G8:if(a_1374(a_F1)){ goto a_G11;}
a_1340(a_F1);
a_P[0]=16777690;a_P[1]=a_L4;a_1338(a_1001,2,a_P);
a_G11:__incr(a_L4);
a_G12:a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0]; goto a_G3;
a_G13:if(!__equal(a_L5,344288336)){ goto a_G12;}
a_1410(a_F1,a_L2,a_L3,a_L4);return;
} /* regularcallpostload */
static void a_1403(int a_F1,int a_F2,int a_A[1]){ /* regularcalld1+>a+>a+a> */
int a_P[1];
if(!a_1060(a_1354,512)){ goto a_G9;}
if(!__noteq(a_F1,a_1382)){ goto a_G7;}
if(__equal(a_F2,a_1382)){ goto a_G5;}
if(!__lseq(a_F1,0)){ goto a_G7;}
a_G5:a_A[0]=2;
a_P[0]=16777685;a_1338(a_1001,1,a_P);return;
a_G7:a_A[0]=1;
a_P[0]=16777681;a_1338(a_1001,1,a_P);return;
a_G9:a_A[0]=0;return;
} /* regularcalld1 */
static void a_1404(int a_F1,int a_F2){ /* regularcalld2+>a+>a */
int a_P[2];
if(!__equal(a_F1,1)){ goto a_G3;}
a_P[0]=16777678;a_1338(a_1001,1,a_P);return;
a_G3:if(!__equal(a_F1,2)){ goto a_G5;}
a_P[0]=16777675;a_P[1]=a_F2;a_1338(a_1001,2,a_P);return;
a_G5:a_putchar(a_1339,59);return;
} /* regularcalld2 */
static void a_1405(int a_F1,int a_F2,int a_F3){ /* regularcalld3+>a+>a+>a */
int a_P[3];
if(!__equal(a_F1,1)){ goto a_G3;}
a_P[0]=16777671;a_P[1]=a_F3;a_P[2]=a_F2;a_1338(a_1001,3,a_P);return;
a_G3:if(!__equal(a_F1,2)){ goto a_G5;}
a_P[0]=16777667;a_P[1]=a_F3;a_1338(a_1001,2,a_P);return;
a_G5:a_P[0]=16777663;a_P[1]=a_F3;a_1338(a_1001,2,a_P);return;
} /* regularcalld3 */
static int a_1376(int a_F1){ /* ispidgindiscarded+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
if(a_1060(a_1354,1792)){ return 0;}
a_1192(a_1354,a_P);a_L2=a_P[0];
a_L3=0;
a_G4:if(__equal(a_L3,a_L2)){ return 1;}
a_1191(a_1354,a_L3,a_P);a_L4=a_P[0];
__incr(a_L3);
if(!a_1374(a_F1)){ goto a_G9;}
a_G8:a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0]; goto a_G4;
a_G9:if(__equal(a_L4,344288324)){ return 0;}
if(__equal(a_L4,344288330)){ return 0;}
if(__equal(a_L4,344288336)){ return 0;} goto a_G8;
} /* ispidgindiscarded */
static void a_1384(int a_F1){ /* pidginalttagtail+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1192(a_1354,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(__equal(a_L3,a_L2)){return;}
a_1191(a_1354,a_L3,a_P);a_L4=a_P[0];
__incr(a_L3);
if(!__equal(a_L4,344288324)){ goto a_G10;}
if(!__equal(to_LIST(a_1010)->offset[a_F1],344288369)){ goto a_G9;}
a_putchar(a_1339,48); goto a_G10;
a_G9:a_putchar(a_1339,49);
a_G10:if(__equal(a_L4,344288336)){return;}
a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0]; goto a_G3;
} /* pidginalttagtail */
static void a_1385(int a_F1){ /* pidginrepeatblock+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
__incr(a_F1);
a_L2=to_LIST(a_1010)->offset[a_F1];
a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0];
a_1392(a_L2);
if(!__less(a_L2,0)){ goto a_G7;}
__subtr(0,a_L2,a_L3); goto a_G8;
a_G7:a_L3=a_L2;
a_G8:a_1193(a_1354,a_P);a_L4=a_P[0];
__mult(a_L3,a_L4,a_L3);
a_G10:if(__equal(a_L3,0)){ goto a_G15;}
a_putchar(a_1339,44);
a_1340(a_F1);
__decr(a_L3);
a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0]; goto a_G10;
a_G15:if(__more(a_L2,0)){return;}
a_P[0]=16777659;a_1338(a_1001,1,a_P);return;
} /* pidginrepeatblock */
static void a_1386(int a_F1,int a_F2){ /* pidginruleargs+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[1];
a_1192(a_1354,a_P);a_L3=a_P[0];
a_L4=0;a_L5=0;
a_G3:if(__equal(a_L4,a_L3)){return;}
a_1191(a_1354,a_L4,a_P);a_L6=a_P[0];
__incr(a_L4);
if(!__equal(a_L6,344288336)){ goto a_G9;}
a_P[0]=a_L5;a_1350(a_P);
a_1385(a_F1);return;
a_G9:if(!__equal(a_L6,344288324)){ goto a_G12;}
if(!__is(a_F2)){ goto a_G12;}
if(__equal(to_LIST(a_1010)->offset[a_F1],344288369)){ goto a_G14;}
a_G12:a_P[0]=a_L5;a_1350(a_P);a_L5=a_P[0];
a_1340(a_F1);
a_G14:a_P[0]=a_F1;a_1381(a_P);a_F1=a_P[0]; goto a_G3;
} /* pidginruleargs */
static void a_1387(int a_F1){ /* pidginrulecall+>a */
int a_L2;int a_P[2];
a_P[0]=16777654;a_P[1]=a_1354;a_1338(a_1001,2,a_P);
if(!a_1375(a_1354)){ goto a_G5;}
a_L2=1;
a_1384(a_F1); goto a_G6;
a_G5:a_L2=0;
a_G6:a_putchar(a_1339,40);
a_1386(a_F1,a_L2);
a_putchar(a_1339,41);return;
} /* pidginrulecall */
static void a_1272(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6,int a_F7){ /* Trulecall+>a+>a+>a+>a+>a+>a+>a */
int a_L8;int a_L9;int a_P[1];
a_1354=a_F1;
__incr(a_F7);
if(!a_1198(a_F1,a_P)){ goto a_G9;}a_L8=a_P[0];
if(!__equal(a_L8,2)){ goto a_G6;}
a_1372(a_F3,a_F4);return;
a_G6:if(!__equal(a_L8,3)){ goto a_G8;}
a_1371(a_F2,a_F7,a_F4);return;
a_G8:a_1370(a_F5,a_F6,a_F7,a_F4);return;
a_G9:if(!a_1302(a_F1)){ goto a_G16;}
if(!a_1376(a_F7)){ goto a_G12;}
a_putchar(a_1339,59);return;
a_G12:a_1403(a_F3,a_F4,a_P);a_L9=a_P[0];
a_1387(a_F7);
a_1404(a_L9,a_F3);
a_G15:a_1405(a_L9,a_F3,a_F4);return;
a_G16:a_1407(a_F7);
a_1403(a_F3,a_F4,a_P);a_L9=a_P[0];
a_1408(a_F7);
a_1404(a_L9,a_F3);
a_1406(a_F7); goto a_G15;
} /* Trulecall */
static void a_1361(int a_F1,int a_F2,int a_F3){ /* extensionblock+>a+>a+>a */
int a_L4;int a_L5;int a_P[3];
__incr(a_F3);
a_L4=a_F3;
a_G3:if(__equal(to_LIST(a_1010)->offset[a_L4],344288381)){ goto a_G5;}
__incr(a_L4); goto a_G3;
a_G5:__incr(a_L4);
a_G6:if(__less(to_LIST(a_1010)->offset[a_L4],0)){ goto a_G11;}
__subtr(a_F1,to_LIST(a_1010)->offset[a_L4],a_L5);
__incr(a_L5);
__incr(a_L4);
a_P[0]=16777651;a_P[1]=a_F2;a_P[2]=a_L5;a_1338(a_1001,3,a_P); goto a_G6;
a_G11:a_1340(a_F3);
a_putchar(a_1339,59);return;
} /* extensionblock */
static void a_1270(int a_F1,int a_F2){ /* Textension+>a+>a */
int a_L3;int a_L4;int a_P[3];
__incr(a_F1);
a_L4=to_LIST(a_1010)->offset[a_F1];
__incr(a_F1);
a_L3=a_F1;
a_P[0]=16777643;a_P[1]=a_L3;a_P[2]=a_L4;a_1338(a_1001,3,a_P);
__add(2,a_F1,a_F1);
a_G7:a_1361(a_L4,a_L3,a_F1);
a_F1=to_LIST(a_1010)->offset[a_F1];
if(!__equal(a_F1,0)){ goto a_G7;}
a_P[0]=16777635;a_P[1]=a_L3;a_P[2]=a_L4;a_1338(a_1001,3,a_P);
a_1378(a_F2);return;
} /* Textension */
static void a_1353(int a_F1,int a_A[1]){ /* boxclassifier+>a+a> */
int a_P[2];
{register int a_r1=to_LIST(a_1010)->offset[a_F1];
 if(!(a_r1==344288412||a_r1==344288420||a_r1==344288416||a_r1==344288400)){ goto a_G3;}
}
a_A[0]=a_F1;return;
a_G3:a_A[0]=1922290883;
a_P[0]=16777626;a_P[1]=a_A[0];a_1338(a_1001,2,a_P);
a_1340(a_F1);
a_P[0]=16777619;a_1338(a_1001,1,a_P);return;
} /* boxclassifier */
static int a_1373(int a_F1){ /* iscompletearea+>a */

if(!__equal(to_LIST(a_1010)->offset[a_F1],0)){ return 0;}
__incr(a_F1);
__incr(a_F1);
if(!__equal(to_LIST(a_1010)->offset[a_F1],(-2147483647-1))){ return 0;}
__incr(a_F1);
if(!__equal(to_LIST(a_1010)->offset[a_F1],2147483647)){ return 0;} return 1;
} /* iscompletearea */
static void a_1346(int a_F1,int a_F2,int a_F3){ /* Tsingleifcondition+>a+>a+>a */
int a_P[5];
if(!__equal(a_F1,a_F2)){ goto a_G3;}
a_P[0]=16777616;a_P[1]=a_F3;a_P[2]=a_F1;a_1338(a_1001,3,a_P);return;
a_G3:if(!__equal(a_F1,(-2147483647-1))){ goto a_G5;}
a_P[0]=16777612;a_P[1]=a_F3;a_P[2]=a_F2;a_1338(a_1001,3,a_P);return;
a_G5:if(!__equal(a_F2,2147483647)){ goto a_G7;}
a_P[0]=16777608;a_P[1]=a_F3;a_P[2]=a_F1;a_1338(a_1001,3,a_P);return;
a_G7:a_P[0]=16777604;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_F3;a_P[4]=a_F2;a_1338(a_1001,5,a_P);return;
} /* Tsingleifcondition */
static void a_1342(int a_F1,int a_F2){ /* Tifcondition+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_G1:__incr(a_F1);
a_L3=to_LIST(a_1010)->offset[a_F1];
__incr(a_F1);
a_L4=to_LIST(a_1010)->offset[a_F1];
a_1346(a_L3,a_L4,a_F2);
__incr(a_F1);
if(!__equal(to_LIST(a_1010)->offset[a_F1],344288387)){return;}
a_P[0]=16777597;a_1338(a_1001,1,a_P); goto a_G1;
} /* Tifcondition */
static void a_1344(int a_F1,int a_F2){ /* Tjumptoareas+>a+>a */
int a_L3;int a_L4;int a_L5;int a_P[2];
a_G1:a_L5=to_LIST(a_1010)->offset[a_F1];
if(!__equal(a_L5,0)){ goto a_G10;}
__incr(a_F1);
a_L3=to_LIST(a_1010)->offset[a_F1];
a_P[0]=16777594;a_1338(a_1001,1,a_P);
a_1342(a_F1,a_F2);
a_P[0]=16777590;a_P[1]=a_F2;a_1338(a_1001,2,a_P);
if(__equal(a_L3,a_1382)){return;}
a_P[0]=16777579;a_P[1]=to_LIST(a_1010)->offset[a_F1];a_1338(a_1001,2,a_P);return;
a_G10:if(!a_1373(a_L5)){ goto a_G25;}
__incr(a_F1);
a_L3=to_LIST(a_1010)->offset[a_F1];
__incr(a_L5);
a_L4=to_LIST(a_1010)->offset[a_L5];
if(!__equal(a_L3,a_1382)){ goto a_G20;}
if(__equal(a_L3,a_L4)){return;}
a_P[0]=16777576;a_1338(a_1001,1,a_P);
a_1342(a_F1,a_F2);
a_P[0]=16777572;a_P[1]=a_L4;a_1338(a_1001,2,a_P);return;
a_G20:a_P[0]=16777567;a_1338(a_1001,1,a_P);
a_1342(a_F1,a_F2);
a_P[0]=16777563;a_P[1]=a_L3;a_1338(a_1001,2,a_P);
if(__equal(a_L4,a_1382)){return;}
a_P[0]=16777558;a_P[1]=a_L4;a_1338(a_1001,2,a_P);return;
a_G25:__incr(a_F1);
a_P[0]=16777555;a_1338(a_1001,1,a_P);
a_1342(a_F1,a_F2);
a_P[0]=16777551;a_P[1]=to_LIST(a_1010)->offset[a_F1];a_1338(a_1001,2,a_P);
a_F1=a_L5; goto a_G1;
} /* Tjumptoareas */
static void a_1269(int a_F1,int a_F2){ /* Tbox+>a+>a */
int a_L3;int a_P[1];
a_P[0]=16777547;a_1338(a_1001,1,a_P);
__incr(a_F1);
a_1353(a_F1,a_P);a_L3=a_P[0];
__incr(a_F2);
a_1344(a_F2,a_L3);
a_P[0]=16777544;a_1338(a_1001,1,a_P);return;
} /* Tbox */
static void a_1379(int a_F1,int a_F2){ /* listinitialization+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[8];
if(!a_1060(a_F2,16)){ goto a_G4;}
a_1048(a_F2,a_P);a_L3=a_P[0];
a_P[0]=16777541;a_P[1]=to_LIST(a_1015)->offset[a_F2-3];a_P[2]=a_F2;a_P[3]=a_L3;a_1338(a_1001,4,a_P);return;
a_G4:a_1048(a_F2,a_P);a_L3=a_P[0];
a_1056(a_F2,a_P);a_L5=a_P[0];
a_1055(a_F2,a_P);a_L4=a_P[0];
a_1052(a_F2,a_P);a_L6=a_P[0];
a_P[0]=16777535;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_L3;a_P[4]=a_L4;a_P[5]=a_L5;a_P[6]=a_L6;a_P[7]=to_LIST(a_1015)->offset[a_F2-3];a_1338(a_1001,8,a_P);return;
} /* listinitialization */
static void a_1355(int a_F1){ /* charfileinitialization+>a */
int a_L2;int a_L3;int a_L4;int a_P[6];
if(!a_1060(a_F1,16)){ goto a_G3;}
a_P[0]=16777521;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_P[2]=a_F1;a_1338(a_1001,3,a_P);return;
a_G3:if(!a_1060(a_F1,64)){ goto a_G5;}
a_L2=2; goto a_G6;
a_G5:a_L2=0;
a_G6:if(!a_1060(a_F1,32)){ goto a_G8;}
__incr(a_L2);
a_G8:a_1189(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
a_P[0]=16777516;a_P[1]=a_F1;a_P[2]=a_L2;a_P[3]=a_L3;a_P[4]=a_L4;a_P[5]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,6,a_P);return;
} /* charfileinitialization */
static void a_1357(int a_F1,int a_A[1]){ /* countfilearea+>a+a> */
int a_P[3];
a_A[0]=0;
a_G2:if(__equal(a_F1,0)){return;}
__incr(a_A[0]);
a_P[0]=a_F1;a_1190(a_P);a_F1=a_P[0]; goto a_G2;
} /* countfilearea */
static void a_1358(int a_F1){ /* datafileinitialization+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[7];
if(!a_1060(a_F1,16)){ goto a_G3;}
a_P[0]=16777503;a_P[1]=to_LIST(a_1015)->offset[a_F1-3];a_P[2]=a_F1;a_1338(a_1001,3,a_P);return;
a_G3:if(!a_1060(a_F1,64)){ goto a_G5;}
a_L2=2; goto a_G6;
a_G5:a_L2=0;
a_G6:if(!a_1060(a_F1,32)){ goto a_G8;}
__incr(a_L2);
a_G8:a_1189(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];a_L5=a_P[2];
a_1357(a_L5,a_P);a_L6=a_P[0];
a_P[0]=16777498;a_P[1]=a_F1;a_P[2]=a_L2;a_P[3]=a_L3;a_P[4]=a_L4;a_P[5]=a_L6;a_P[6]=to_LIST(a_1015)->offset[a_F1-3];a_1338(a_1001,7,a_P);
a_G11:if(__equal(a_L5,0)){return;}
a_P[0]=a_L5;a_1190(a_P);a_L5=a_P[0];a_L6=a_P[1];a_L3=a_P[2];
a_P[0]=16777485;a_P[1]=a_F1;a_P[2]=a_L3;a_P[3]=a_L6;a_1338(a_1001,4,a_P); goto a_G11;
} /* datafileinitialization */
static void a_1252(void){ /* datainitialization */
int a_L1;int a_L2;int a_P[3];
a_P[0]=16777475;a_1338(a_1001,1,a_P);
a_P[0]=16777464;a_P[1]=16777216;a_P[2]=2130706432;a_1338(a_1001,3,a_P);
a_L1=to_LIST(a_1015)->alwb;
a_G4:if(__more(a_L1,to_LIST(a_1015)->aupb)){ goto a_G12;}
if(!a_1053(a_L1,a_P)){ goto a_G8;}a_L2=a_P[0];
if(!__noteq(a_L1,a_L2)){ goto a_G8;}
a_G7:__next(a_1015,a_L1); goto a_G4;
a_G8:{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288266){ goto a_G9;}
 if(a_r1==344288270||a_r1==344288276){  goto a_G10;}
  goto a_G7;}
a_G9:a_1379(0,a_L1); goto a_G7;
a_G10:a_1379(1,a_L1); goto a_G7;
a_G12:a_L1=to_LIST(a_1015)->alwb;
a_G13:if(__more(a_L1,to_LIST(a_1015)->aupb)){ goto a_G21;}
if(!a_1053(a_L1,a_P)){ goto a_G17;}a_L2=a_P[0];
if(!__noteq(a_L1,a_L2)){ goto a_G17;}
a_G16:__next(a_1015,a_L1); goto a_G13;
a_G17:{register int a_r1=to_LIST(a_1015)->offset[a_L1-4];
 if(a_r1==344288288){ goto a_G18;}
 if(a_r1==344288293){  goto a_G19;}
  goto a_G16;}
a_G18:a_1355(a_L1); goto a_G16;
a_G19:a_1358(a_L1); goto a_G16;
a_G21:a_P[0]=16777452;a_1338(a_1001,1,a_P);return;
} /* datainitialization */
static void a_1337(void){ /* @root */

if(!a_waitfor(a_1001,16777443)){return;}return;
} /* @root */
static void a_1402(int a_F1,int a_F2,int a_F3){ /* putstring+""f+t[]+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=0;
a_G2:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){return;}a_L3=a_P[0];
__incr(a_L2);
a_putchar(a_F1,a_L3); goto a_G2;
} /* putstring */
static void a_1424(void){ /* @root */

} /* @root */
