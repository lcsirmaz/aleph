/* ALEPH ice linker v2.1, word size=32 */

// linked modules:
// number "js linker number v1.0"
// arithmetic "js linker arithmetic v1.0"
// rule "js linker rule, v1.0"
// target "js linker target, v1.0"
// expression "js linker expression, v1.0"
// data "js linker data, v1.0"
// item "js linker item, v1.0"
// config "js linker config, v1.0"
// input "js linker input, v1.0"
// error "error, v2.1"
// lexical "js linker lexical, v1.0"
// @main "ALEPH js linker, v1.0"
// stdlib "stdlib base"
// stdlib "stdlib put string"
// stdlib "stdlib wait for"
// stdlib "stdlib stdarg"
// stdlib "stdlib stdhash"
#include "aleph_core.h"
static void a_stringhash(int,int,int[1]);static void a_blockhash(int,int,int[1]);
static void a_setup_stdarg(int,const char*,int);
#include "aleph_stdlib.h"
#define a_1001 (0) /* @StringTable */
#define a_1005 (a_1001+sizeof_LIST) /* NUMBER */
static void a_1006(a_word a_F1,a_word a_F2,a_word a_A[1]); /* enterconststring */
static void a_1007(a_word a_F1,a_word a_A[2]); /* entertargetstring */
static void a_1008(a_word a_F1); /* getnumberrepr */
static void a_1009(a_word a_A[1]); /* getnumberzero */
static void a_1010(a_word a_F1,a_word a_A[1]); /* gettargetnumbervalue */
static void a_1011(a_word a_F1,a_word a_F2,a_word a_A[1]); /* loadregister */
static a_word a_1012(a_word a_F1,a_word a_F2); /* minmaxregisters */
static void a_1013(a_word a_A[2]); /* nexttargetstringvalue */
static a_word a_1014=0; /* rtargetmax */
static a_word a_1015=0; /* rtargetmin */
static a_word a_1016(a_word a_F1,a_word a_F2); /* samenumberblock */
static void a_1017(a_word a_F1,a_word a_A[1]); /* storeregister */
static a_word a_1018=0; /* targetmaxint */
static a_word a_1019=0; /* targetminint */
static a_word a_1020=0; /* zeroptr */
#define a_1022 (a_1005+sizeof_LIST) /* REGISTER */
static void a_1023(a_word a_F1); /* freeregister */
static void a_1024(a_word a_F1); /* freeregistersfrommark */
static void a_1025(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]); /* getdecimalform */
static void a_1026(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]); /* getregister */
static void a_1027(a_word a_A[1]); /* markregisters */
static void a_1028(a_word a_F1,a_word a_F2,a_word a_A[2]); /* packstringtoregisters */
static void a_1029(a_word a_F2,a_word a_A[1]); /* popregister */
static void a_1030(a_word a_F1,a_word a_F2); /* putdecimalform */
static void a_1031(a_word a_F1,a_word a_F2); /* putint1 */
static void a_1032(a_word a_F1,a_word a_F2); /* putregister */
static void a_1033(a_word a_F1,a_word a_A[1]); /* putregistervalue */
static a_word a_1034(a_word a_F1,a_word a_F2); /* regcompare */
static a_word a_1035(a_word a_F1,a_word a_F2,a_word a_F3); /* regcompare2 */
static void a_1036(a_word a_F1,a_word a_F2,a_word a_F3); /* regoperator */
static a_word a_1038=0; /* C1 */
static a_word a_1039=0; /* C2 */
static a_word a_1040=0; /* C3 */
#define a_1041 (a_1022+sizeof_LIST) /* NODE */
#define a_1042 (a_1041+sizeof_LIST) /* ZONE */
static void a_1043(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]); /* addinterval */
static void a_1044(void); /* advancenode */
static void a_1045(void); /* arealabels */
static void a_1046(a_word a_F1,a_word a_A[1]); /* checkarea */
static void a_1047(void); /* checkareas */
static void a_1048(void); /* checknodehash */
static void a_1049(a_word a_F1,a_word a_F2); /* clearnodeflag */
static void a_1050(void); /* clearstacksize */
static void a_1051(a_word a_F1); /* comparetostoredaffixes */
static a_word a_1052(a_word a_F1); /* completezone */
static void a_1053(void); /* computeruleaffixhash */
static void a_1054(void); /* createnodes */
static a_word a_1055=0; /* dolocalaffixcheck */
static a_word a_1056(a_word a_F1,a_word a_F2); /* equalaffixes */
static void a_1057(void); /* extensionlabel */
static void a_1058(void); /* findequalnodes */
static void a_1059(a_word a_F1,a_word a_F2); /* findintervalpair */
static void a_1060(a_word a_A[1]); /* findnextnode */
static void a_1061(a_word a_F1,a_word a_A[1]); /* findreallabel */
static void a_1062(void); /* generatearea */
static void a_1063(void); /* generateareas */
static void a_1064(void); /* generatebox */
static void a_1065(void); /* generateextension */
static void a_1066(void); /* generatelabel */
static void a_1067(void); /* generaterulecall */
static void a_1068(a_word a_A[1]); /* getitemdef */
static void a_1069(a_word a_F1,a_word a_A[1]); /* getnodeindex */
static a_word a_1070=0; /* haslabels */
static a_word a_1071(a_word a_F1); /* hasoutaffix */
static a_word a_1072=0; /* indexedaffix */
static void a_1073(a_word a_F1,a_word a_A[1]); /* indextonode */
static a_word a_1074(void); /* islimit */
static a_word a_1075(a_word a_F1); /* isnodediscarded */
static a_word a_1076=0; /* localaffixptr */
static a_word a_1077=0; /* loopfound */
static void a_1078(void); /* makerule */
static void a_1079(a_word a_F1); /* marklocalaffix */
static void a_1080(a_word a_F1,a_word a_F2); /* marknode */
static void a_1081(a_word a_F1); /* mergeintervals */
static a_word a_1082(void); /* nodehashdifferent */
static a_word a_1083(a_word a_F1); /* nodewithsamehash */
static void a_1084(void); /* omitemptynodes */
static void a_1085(a_word a_C,a_word *a_V); /* pushBUFFER */
static void a_1086(a_word a_F1,a_word a_F2); /* putnodeflag */
static void a_1087(a_word a_A[2]); /* readareainterval */
static void a_1088(a_word a_F1,a_word a_F2); /* replacelabels */
static void a_1089(a_word a_F1,a_word a_F2); /* replacenlabels */
static void a_1090(void); /* rulelabel */
static void a_1091(void); /* rulesection */
static a_word a_1092(a_word a_F1,a_word a_F2); /* samenodes */
static void a_1093(void); /* scani */
static void a_1094(void); /* scanii */
static void a_1095(void); /* scaniii */
static void a_1096(void); /* scaniv */
static void a_1097(a_word a_F1); /* setnodeflag */
static void a_1098(void); /* setrulehead */
static void a_1099(void); /* skipaffix */
static void a_1100(void); /* skiplist */
static void a_1101(void); /* skiprule */
static void a_1102(void); /* skiprulehead */
static void a_1103(void); /* skiptocomma */
static void a_1104(a_word a_A[1]); /* skiptolabel */
static void a_1105(a_word a_F1,a_word a_F2); /* startlocalaffixcheck */
static void a_1106(void); /* storeaffix */
static void a_1107(void); /* storelimit */
static void a_1108(a_word a_F1); /* storelist */
static void a_1109(a_word a_A[1]); /* storeruleaffix */
static void a_1110(void); /* storeruleaffixes */
static a_word a_1111=0; /* storerulename */
static a_word a_1112=0; /* thisnode */
static void a_1114(a_word a_F1,a_word a_C,a_word *a_V); /* T */
#define a_1115 (a_1042+sizeof_LIST) /* TARGET */
static void a_1116(a_word a_F1); /* Taffix */
static void a_1117(a_word a_A[1]); /* Taffixinner */
static void a_1118(a_word a_F1,a_word a_F2); /* Tbox */
static void a_1119(a_word a_F1,a_word a_F2); /* Textension */
static void a_1120(a_word a_F1,a_word a_F2); /* Tifcondition */
static void a_1121(a_word a_A[1]); /* Tindex */
static void a_1122(a_word a_F1,a_word a_F2); /* Tjumptoareas */
static void a_1123(a_word a_F1,a_word a_F2); /* Tlabel */
static void a_1124(a_word a_F1,a_word a_A[1]); /* Tlimittail */
static void a_1125(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4,a_word a_F5,a_word a_F6,a_word a_F7); /* Trulecall */
static void a_1126(a_word a_F1,a_word a_F2,a_word a_F3); /* Tsingleifcondition */
static void a_1127(a_word a_F1); /* addcallstack */
static void a_1128(void); /* addprofilingcount */
static void a_1129(void); /* addprofilingdef */
static void a_1130(a_word a_F1); /* addrulename */
static void a_1131(void); /* addtracing */
static void a_1132(a_word a_A[1]); /* argsep */
static void a_1133(a_word a_F1,a_word a_A[2]); /* assignmentsource */
static void a_1134(a_word a_F1,a_word a_A[1]); /* boxclassifier */
static a_word a_1135=0; /* calledrule */
static a_word a_1136=0; /* callstack */
static void a_1137(a_word a_A[1]); /* calltracearg */
static void a_1138(a_word a_A[1]); /* calltracecall */
static void a_1139(a_word a_F1); /* charfiledeclaration */
static void a_1140(a_word a_F1); /* charfileinitialization */
static a_word a_1141(a_word a_F1,a_word a_A[1]); /* checkBUFFERno */
static void a_1142(void); /* closetarget */
static void a_1143(void); /* constitem */
static void a_1144(a_word a_F1,a_word a_F2,a_word a_F3); /* copyaffix */
static void a_1145(a_word a_F1,a_word a_F2,a_word a_F3); /* copytextfromBUFFER */
static void a_1146(a_word a_F1,a_word a_A[1]); /* countfilearea */
static void a_1147(void); /* createrulenametable */
static void a_1148(void); /* datadeclaration */
static void a_1149(a_word a_F1); /* datafiledeclaration */
static void a_1150(a_word a_F1); /* datafileinitialization */
static void a_1151(void); /* datainitialization */
static void a_1152(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4); /* declarecallargs */
static void a_1153(a_word a_F1,a_word a_F2,a_word a_F3); /* declarelocals */
static void a_1154(void); /* deletetarget */
static void a_1155(a_word a_F1,a_word a_F2,a_word a_F3); /* extensionblock */
static void a_1156(a_word a_A[1]); /* fillitem */
static a_word a_1157(a_word a_A[1]); /* fillrepeater */
static void a_1158(void); /* filltablehead */
static void a_1159(void); /* filltabletail */
static a_word a_1160=0; /* filltotal */
static void a_1161(a_word a_A[1]); /* findBUFFERalternative */
static void a_1162(a_word a_F1,a_word a_A[1]); /* findBUFFERversion */
static void a_1163(a_word a_F1,a_word a_F2,a_word a_F3); /* flushbuffer */
static void a_1164(a_word a_F1); /* formalargument */
static void a_1165(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4); /* genassignment */
static void a_1166(void); /* generatefillentries */
static void a_1167(a_word a_F1,a_word a_F2,a_word a_F3); /* gengetaffixno */
static void a_1168(a_word a_F1,a_word a_F2); /* genshiftaffix */
static void a_1169(a_word a_F1,a_word a_F2); /* genwaitfor */
static a_word a_1170(a_word a_F1); /* hasoutaffix */
static a_word a_1171(a_word a_F1); /* iscompletearea */
static a_word a_1172(a_word a_F1); /* isdummyaffix */
static a_word a_1173(a_word a_F1,a_word a_F2,a_word a_F3); /* isrulediscarded */
static void a_1174(a_word a_F1); /* jumptolabel */
static a_word a_1175=0; /* lastprofile */
static void a_1176(a_word a_F1,a_word a_F2); /* listdeclaration */
static void a_1177(a_word a_F1); /* listinitialization */
static void a_1178(a_word a_F1); /* localargument */
static a_word a_1179=0; /* moduleroots */
static void a_1180(a_word a_A[1]); /* nextaffix */
static a_word a_1181=0; /* nextnodeidx */
static a_word a_1182(a_word a_F1,a_word a_F2); /* numbersequal */
static void a_1183(void); /* opentarget */
static void a_1184(a_word a_F1,a_word a_A[1]); /* outargs */
static void a_1185(a_word a_F1,a_word a_A[1]); /* pidginalttagtailtype */
static void a_1186(a_word a_F1,a_word a_F2); /* pidginrulecall */
static void a_1187(a_word a_F1); /* printBUFFER */
static void a_1188(a_word a_F1); /* printGOTO */
static void a_1189(a_word a_F1); /* printexternalrepr */
static void a_1190(a_word a_F1); /* printgoto */
static void a_1191(a_word a_F1); /* printint */
static void a_1192(a_word a_F1,a_word a_F2); /* printint1 */
static void a_1193(a_word a_F1,a_word a_F2); /* printintindex */
static void a_1194(a_word a_F1); /* printnlptr */
static void a_1195(a_word a_F1); /* printnumber */
static void a_1196(a_word a_F1); /* printptr */
static void a_1197(a_word a_F1); /* printrepr */
static void a_1198(void); /* procwaitfor */
static void a_1199(void); /* profilingdeclaration */
static void a_1200(a_word a_F1); /* pushBUFFER */
static void a_1201(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]); /* regularcalld1 */
static void a_1202(a_word a_F1,a_word a_F2); /* regularcalld2 */
static void a_1203(a_word a_F1,a_word a_F2,a_word a_F3); /* regularcalld3 */
static void a_1204(a_word a_F1); /* regularcallpostload */
static void a_1205(a_word a_F1); /* regularcallpreload */
static void a_1206(a_word a_F1); /* regularrulecall */
static void a_1207(a_word a_F1,a_word a_F2,a_word a_F3); /* repeatblockcall */
static void a_1208(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4); /* repeatblockpostload */
static void a_1209(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4); /* repeatblockpreload */
static void a_1210(a_word a_F1); /* rootprototype */
static void a_1211(a_word a_F1,a_word a_F2); /* ruleargs */
static void a_1212(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4,a_word a_F5,a_word a_F6,a_word a_F7,a_word a_F8); /* ruledeclarationhead */
static void a_1213(a_word a_F1); /* ruledeclarationtail */
static void a_1214(a_word a_F1); /* ruleprototype */
static void a_1215(a_word a_F1,a_word a_A[1]); /* ruletyper */
static void a_1216(a_word a_F1); /* showformalsascomment */
static void a_1217(void); /* skipfillinitializer */
static void a_1218(a_word a_F1); /* startrulebody */
static void a_1219(a_word a_F1,a_word a_A[2]); /* storerulename */
static void a_1220(void); /* targetmain */
static a_word a_1221=0; /* targetopened */
static void a_1222(void); /* targetpostlude */
static void a_1223(void); /* targetprelude */
static a_word a_1224=0; /* thisrule */
static void a_1225(a_word a_A[1]); /* untilnextcomma */
static void a_1226(void); /* usecallstack */
static void a_1227(a_word a_F1); /* vardeclaration */
static a_word a_1228=0; /* waitforused */
static a_word a_1230(a_word a_F1); /* E */
#define a_1231 (a_1115+sizeof_CHFILE) /* EXPRESSION */
static a_word a_1232(a_word a_A[1]); /* Eitem */
static a_word a_1233(a_word a_F1,a_word a_A[2]); /* Eop */
static a_word a_1234=0; /* Raddr */
static a_word a_1235=0; /* Rby */
static void a_1236(a_word a_F1); /* checkcalibretype */
static void a_1237(a_word a_F1,a_word a_F2); /* checkconstanttype */
static void a_1238(a_word a_F1); /* checklisttype */
static void a_1239(void); /* clearvirtualspace */
static a_word a_1240=0; /* eptr */
static void a_1241(a_word a_A[1]); /* finalbase */
static void a_1242(a_word a_F1); /* finaleval */
static void a_1243(void); /* finalevaluation */
static void a_1244(a_word a_F1,a_word a_A[1]); /* finalexpr */
static void a_1245(a_word a_F1,a_word a_F2,a_word a_A[1]); /* getexprlimit */
static void a_1246(a_word a_A[1]); /* getitemdef */
static a_word a_1247=0; /* linkexpr */
static a_word a_1248(a_word a_A[1]); /* loosebase */
static void a_1249(a_word a_F1); /* looseeval */
static void a_1250(void); /* looseevaluation */
static a_word a_1251(a_word a_F1,a_word a_A[1]); /* looseexpr */
static void a_1252(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[2]); /* nextvirtualblock */
static void a_1253(a_word a_F1,a_word a_F2,a_word a_F3); /* optor */
static void a_1254(a_word a_F1); /* pushEXPR */
static void a_1255(void); /* readexpression */
static void a_1256(a_word a_F1,a_word a_F2); /* setfinalvalue */
static a_word a_1257(a_word a_F1,a_word a_F2); /* splitvirtualspace */
static void a_1258(a_word a_F1,a_word a_A[1]); /* storenumstring */
static void a_1259(a_word a_F1,a_word a_F2,a_word a_A[1]); /* virtualaddressoffset */
static void a_1261(void); /* assignreprnumbers */
static void a_1262(a_word a_F1,a_word a_F2); /* checkconstanttype */
static void a_1263(a_word a_F1); /* checkfiletype */
static void a_1264(a_word a_F1); /* checkfillconstanttype */
static void a_1265(void); /* checkfillitem */
static void a_1266(a_word a_F1); /* checklisttype */
static void a_1267(a_word a_A[2]); /* collectlistsizeclaims */
static void a_1268(void); /* computepointerconstants */
static void a_1269(void); /* datasectioni */
static void a_1270(void); /* datasectionii */
static void a_1271(void); /* datasectioniii */
static void a_1272(void); /* distributevirtualaddress */
static void a_1273(void); /* externalentry */
static void a_1274(void); /* fileentry */
static a_word a_1275=0; /* filltablesize */
static void a_1276(a_word a_F1,a_word a_F2); /* fixsize */
static a_word a_1277(a_word a_F1,a_word a_A[1]); /* getconstvalue */
static void a_1278(a_word a_F1,a_word a_F2,a_word a_A[1]); /* getestimator */
static void a_1279(a_word a_A[1]); /* getitemdef */
static a_word a_1280=-1; /* linklists */
static void a_1281(void); /* listentry */
static void a_1282(void); /* loosebounds */
static void a_1283(void); /* loosefill */
static void a_1284(a_word a_A[1]); /* loosefillitem */
static void a_1285(a_word a_F1); /* looseinitializer */
static void a_1286(a_word a_F1,a_word a_F2,a_word a_F3); /* looserepeater */
static a_word a_1287=1000; /* nextreprno */
static void a_1288(a_word a_F1); /* readmatter */
static void a_1289(a_word a_F1,a_word a_F2); /* relativesize */
static void a_1290(a_word a_F1); /* rememberlist */
static void a_1291(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]); /* repeatervalue */
static void a_1292(void); /* setlistbounds */
static void a_1293(a_word a_F1); /* setpointervalue */
static void a_1294(a_word a_F1); /* setreprnumber */
static void a_1295(void); /* skipdatasection */
static void a_1296(void); /* skipentry */
static void a_1297(void); /* skipfill */
static void a_1298(a_word a_F1); /* skipfillinitializer */
static void a_1299(void); /* skipfillitem */
static void a_1300(a_word a_F1); /* skipfillrepeater */
#define a_1302 (a_1231+sizeof_LIST) /* AUX */
#define a_1303 (a_1302+sizeof_LIST) /* ITEM */
static void a_1304(void); /* addbuiltinformals */
static void a_1305(a_word a_F2,a_word a_A[1],a_word a_C,a_word *a_V); /* addformalaffixes */
static void a_1306(a_word a_F1,a_word a_F2); /* addmatter */
static void a_1307(void); /* addshiftaffixrules */
static void a_1308(void); /* addstdstring */
static void a_1309(a_word a_A[1]); /* advancemodbase */
static void a_1310(a_word a_F1); /* checkitemID */
static void a_1311(void); /* checkmainmodule */
static void a_1312(void); /* cleanupitems */
static void a_1313(a_word a_F1,a_word a_F2); /* clearitemflag */
static a_word a_1314(a_word a_F1,a_word a_F2); /* compareformals */
static void a_1315(a_word a_A[1]); /* converttoitem */
static a_word a_1316=0; /* doreport */
static void a_1317(void); /* enteritem */
static void a_1318(void); /* expandITEM */
static void a_1319(a_word a_F1,a_word a_A[1]); /* finditemdef */
static void a_1320(a_word a_F1,a_word a_A[3]); /* finditemlineno */
static void a_1321(a_word a_F1,a_word a_A[2]); /* findlineno */
static a_word a_1322=0; /* firstmodule */
static void a_1323(a_word a_F1,a_word a_F2); /* formalaffixes */
static void a_1324(a_word a_F1,a_word a_A[1]); /* getanchorcount */
static void a_1325(a_word a_F1,a_word a_A[1]); /* getcalibre */
static void a_1326(a_word a_F1,a_word a_F2,a_word a_A[1]); /* getfilearea */
static void a_1327(a_word a_F1,a_word a_A[2]); /* getfiledata */
static void a_1328(a_word a_F1,a_word a_A[1]); /* getfill */
static void a_1329(a_word a_F1,a_word a_F2,a_word a_A[1]); /* getformal */
static void a_1330(a_word a_F1,a_word a_A[1]); /* getlistlink */
static a_word a_1331(a_word a_F2,a_word a_A[2]); /* getmatter */
static void a_1332(a_word a_A[1]); /* getnextmodulehead */
static void a_1333(a_word a_F1,a_word a_A[1]); /* getnumberofformals */
static void a_1334(a_word a_F1,a_word a_A[1]); /* getssel */
static void a_1335(a_word a_F1,a_word a_A[1]); /* getvlwb */
static void a_1336(a_word a_F1,a_word a_A[1]); /* getvupb */
static void a_1337(a_word a_F1); /* headsection */
static a_word a_1338(a_word a_F1,a_word a_F2); /* incompatibletypes */
static a_word a_1339(a_word a_F1); /* isassignitem */
static a_word a_1340(a_word a_F1,a_word a_A[1]); /* isbuiltinrule */
static a_word a_1341(a_word a_F1,a_word a_F2); /* isitemflag */
static a_word a_1342(a_word a_F1); /* isrootitem */
static a_word a_1343(a_word a_F1); /* iswaitforitem */
static void a_1344(void); /* itemsection */
static a_word a_1345=0; /* lastmodule */
static a_word a_1346=0; /* linkformals */
static void a_1347(void); /* linkmoduleheader */
static a_word a_1348=0; /* mainmodule */
static a_word a_1349=0; /* makeformals */
static a_word a_1350=0; /* matterlink */
static a_word a_1351=0; /* maxlineno */
static a_word a_1352=0; /* modbase */
static void a_1353(a_word a_A[1]); /* opennextmodule */
static void a_1354(a_word a_F1); /* pushAUX */
static void a_1355(a_word a_F1,a_word a_F2); /* putfill */
static void a_1356(a_word a_F1,a_word a_F2); /* putlistlink */
static void a_1357(a_word a_F1,a_word a_F2); /* putvlwb */
static void a_1358(a_word a_F1,a_word a_F2); /* putvupb */
static void a_1359(void); /* readdefinitionlist */
static void a_1360(a_word a_F1); /* readfileinfo */
static void a_1361(void); /* readitem */
static void a_1362(a_word a_F1); /* reportitem */
static void a_1363(void); /* reportnotusedpublicitems */
static a_word a_1364=0; /* rootformals */
static void a_1365(a_word a_A[1]); /* scanfordefinitions */
static void a_1366(void); /* scanfordoubledefinitions */
static void a_1367(a_word a_F1); /* scanitem */
static void a_1368(a_word a_F1); /* scanitemfordbledef */
static void a_1369(void); /* scanlinkedmodules */
static void a_1370(a_word a_F1,a_word a_F2,a_word a_A[2]); /* searchforline */
static void a_1371(a_word a_F1,a_word a_A[1]); /* searchformals */
static void a_1372(a_word a_F1,a_word a_F2); /* setitemflag */
static void a_1373(void); /* skipheadsection */
static void a_1374(void); /* skipitemsection */
static a_word a_1375(a_word a_F1,a_word a_F2); /* stacksizemismatch */
static void a_1376(a_word a_A[1]); /* storeformalaffixes */
static void a_1377(a_word a_A[1]); /* storelistbounds */
static a_word a_1378(a_word a_F1,a_word a_F2); /* unequaltypes */
static a_word a_1379=0; /* waitforformals */
#define a_1382 (a_1303+sizeof_LIST) /* FILES */
static a_word a_1383=0; /* actualptr */
static void a_1384(void); /* adddirseparator */
static void a_1385(void); /* addextension */
static void a_1386(a_word a_F1); /* addincludedicefiles */
static a_word a_1387=1; /* addstdlib */
static a_word a_1388=0; /* argtop */
static void a_1389(void); /* checkcommandlinearguments */
static void a_1390(a_word a_F1); /* extendBUFFER */
static void a_1391(a_word a_F1); /* extendFILES */
static a_word a_1392=0; /* fileno */
static void a_1393(a_word a_A[1]); /* geticefile */
static a_word a_1394(a_word a_A[1]); /* getnextsource */
static void a_1395(void); /* gettargetfile */
static void a_1396(a_word a_F1,a_word a_A[1]); /* handlesourcefile */
static a_word a_1397(a_word a_F1,a_word a_F2); /* isfileflag */
static a_word a_1398(a_word a_F1,a_word a_F2); /* isfirstarg */
static a_word a_1399=0; /* libdir */
static a_word a_1400=0; /* libfile */
static a_word a_1401=0; /* mainfile */
static a_word a_1402(void); /* notstdlibsource */
static a_word a_1403(a_word a_F1,a_word a_A[1]); /* nthpath */
static void a_1404(a_word a_A[1]); /* openBUFFER */
static void a_1405(a_word a_F1); /* openfileaslast */
static void a_1406(a_word a_F1,a_word a_A[1]); /* openfilefirst */
static void a_1407(a_word a_F1); /* opensource */
static a_word a_1408(a_word a_F1); /* selectpath */
static void a_1409(a_word a_F1,a_word a_F2); /* setfileflag */
static void a_1410(a_word a_F1); /* setsource */
static void a_1411(a_word a_F1); /* stringtoBUFFER */
static a_word a_1412=0; /* targetfile */
static void a_1413(a_word a_F1,a_word a_A[1]); /* tryfilefirst */
static void a_1414(a_word a_F1,a_word a_A[1]); /* tryopen */
static void a_1415(a_word a_F1,a_word a_F2,a_word a_A[1]); /* tryopenwithpath */
static a_word a_1416(a_word a_F1,a_word a_A[1]); /* wasicesource */
#define a_1418 (a_1382+sizeof_LIST) /* MESSAGE */
#define a_1419 (a_1418+sizeof_LIST) /* PRINTFILE */
static void a_1420(a_word a_F1,a_word a_F2); /* corrupticefile */
static void a_1421(a_word a_C,a_word *a_V); /* error */
static a_word a_1422=0; /* errorno */
static void a_1423(a_word a_C,a_word *a_V); /* fatalerror */
static void a_1424(a_word a_C,a_word *a_V); /* formatprint */
static void a_1425(a_word a_F1,a_word a_F2); /* internalerror */
static void a_1426(a_word a_C,a_word *a_V); /* message */
static void a_1427(a_word a_F1); /* messagehead */
static void a_1428(void); /* nlcr */
static void a_1429(a_word a_F1,a_word a_F2); /* print */
static void a_1430(a_word a_F1); /* printbase */
static void a_1431(a_word a_F1); /* printchar */
static void a_1432(a_word a_F1); /* printform */
static void a_1433(a_word a_F1,a_word a_F2); /* printform1 */
static void a_1434(a_word a_F1); /* printint */
static void a_1435(a_word a_F1,a_word a_F2); /* printint1 */
static void a_1436(a_word a_F1); /* printitem */
static void a_1437(a_word a_F1); /* printline */
static void a_1438(a_word a_F1); /* printpointer */
static a_word a_1439=0; /* prpos */
static void a_1440(a_word a_F1); /* tabline */
static void a_1441(a_word a_C,a_word *a_V); /* warning */
static a_word a_1442(void); /* waserror */
#define a_1444 (a_1419+sizeof_CHFILE) /* BOLD */
#define a_1445 (a_1444+sizeof_LIST) /* BUFFER */
#define a_1446 (a_1445+sizeof_LIST) /* HASH */
static a_word a_1447=1; /* HASHentries */
static a_word a_1448=1023; /* HASHsize */
#define a_1449 (a_1446+sizeof_LIST) /* LEXT */
#define a_1450 (a_1449+sizeof_LIST) /* SOURCE */
static void a_1451(a_word a_A[1]); /* addLEXTentry */
static a_word a_1452=32; /* char */
static void a_1453(void); /* closesource */
static void a_1454(void); /* comment */
static void a_1455(a_word a_F1,a_word a_A[1]); /* enterstring */
static void a_1456(a_word a_F1); /* extendBUFFER */
static void a_1457(a_word a_F1,a_word a_A[1]); /* gettagdata */
static void a_1458(a_word a_F1,a_word a_A[1]); /* gettagimage */
static a_word a_1459=0; /* inpt */
static a_word a_1460=0; /* inptvalue */
static a_word a_1461=0; /* lastchar */
static a_word a_1462=0; /* lastfilepos */
static a_word a_1463=0; /* lastinpt */
static a_word a_1464=0; /* lastinptvalue */
static void a_1465(void); /* nextchar */
static void a_1466(void); /* nextsymbol */
static void a_1467(a_word a_F1,a_word a_F2); /* puttagdata */
static void a_1468(a_word a_A[1]); /* readbold */
static void a_1469(a_word a_A[1]); /* readdestination */
static void a_1470(a_word a_A[1]); /* readstring */
static void a_1471(a_word a_A[1]); /* readtargetnumber */
static void a_1472(a_word a_A[2]); /* readtargetstring */
static void a_1473(a_word a_A[1]); /* readtype */
static void a_1474(void); /* rehash */
static void a_1475(void); /* restoreinputposition */
static void a_1476(void); /* saveinputposition */
static a_word a_1477=1; /* sourceline */
static void a_1478(a_word a_A[1]); /* trytoopensource */
static a_word a_1479=0; /* xnumber */
static void a_1481(void); /* pass1 */
static void a_1482(void); /* pass2 */
static void a_1483(void); /* pass3 */
static void a_1484(void); /* pass4 */
static void a_1485(void); /* pass5 */
static void a_1488(a_word a_F1,a_word a_F2,a_word a_F3); /* putstring */
#define a_1491 (a_1450+sizeof_CHFILE) /* STDARG */
static void a_1480(void); /* @main root */
static void a_1443(void); /* lexical root */
static void a_1301(void); /* item root */
static void a_1004(void); /* number root */
#define BLOCK_TOTAL (a_1491+sizeof_LIST)
a_word a_DATABLOCK[BLOCK_TOTAL];
static a_word a_FILL[]={ /* fill table */
a_1001,/* @StringTable */
18,1953723757,0,4,4,1651340654,1630433893,540697964,1852797559,1044127847,1112364366,21061,26,9,1953067617,1952804200,25449,10,5,0,
a_1001,/* @StringTable */
36,1953723757,0,4,4,1885956979,1768318561,120,9,5,1885956979,1634496372,7103842,11,5,1885956979,1868787572,6385005,11,5,1635148897,1852138350,6644847,11,5,1684104562,1634038369,1702129257,1818326642,0,16,7,1701606770,1952671091,7237481,11,5,0,
a_1418,/* MESSAGE */
67,1634038369,544497952,540699685,1702326124,1868701810,543452789,1696625701,1701143416,1965060964,1919250544,1970233888,622879854,116,49,15,1634038369,544497952,540699685,1936287860,1953259808,1634628197,1702259060,1986358816,1931506277,1701012341,7562341,43,13,1953718636,1701994784,1952522337,980165920,1953459744,1819042080,1935762208,1629516645,1663067506,1919252079,25701,42,13,1935764579,1768319347,1769234787,1629515375,1814372468,1818304570,1937334647,1668641568,1684366691,115,37,12,1701606770,544220448,622883937,1763719788,1852401262,543519849,1886351212,1668180256,1768191340,1914726254,543517813,28709,46,14,0,
a_1001,/* @StringTable */
971,1953723757,0,4,4,1684957542,1179014466,1818317381,1852990836,1986622561,101,21,8,628967205,7218503,7,4,1193638697,125,5,4,31529,2,3,2647657,3,3,556295785,0,4,4,678588262,544499052,809333345,1014128955,709058401,1631282213,690695026,1449091451,1449091419,728131183,1029534305,1531207521,1630233637,2101042546,0,56,17,1147101501,1566844251,59,9,5,1348428093,1566844251,59,9,5,693133153,0,4,4,2650661,3,3,623666213,1600203876,10576,10,5,808215589,1348428076,41,9,5,725835617,808215589,1147101484,41,13,6,5267297,3,3,678588262,544499052,809333345,1014128955,709058401,1631282213,690695026,1147101563,727983451,1029534305,1532387169,1867931489,1630234214,2101042546,0,56,17,1531207521,1029530661,0,8,5,1531993953,1029530661,0,8,5,678588262,544499052,809332773,1013982523,994271073,724267045,1600224041,1600215894,1717989206,1567630635,997205309,125,45,14,997205309,0,4,4,1852793723,622883955,15728,10,5,622869289,71,5,4,1130324285,625419579,110,9,5,1847936805,0,4,4,1735288167,1717662821,1853385062,111,13,6,1630037609,1027359583,628828465,1629519207,757941087,1449091387,728131183,996418877,28197,34,11,1630037609,826164063,1600224041,992816451,1867931489,1026254438,624649253,622886215,7218503,35,11,622864943,791289968,625419579,110,13,6,123,1,3,1730509609,7218557,7,4,622885673,1847950695,0,8,5,677800224,0,4,4,628828457,1847950695,0,8,5,6759712,3,3,628964137,110,5,4,1968332641,1632527724,25965,10,5,1968332641,1632527724,1534289261,6120485,15,6,1635461417,1701986655,1767982689,677668204,2912293,19,7,677800224,10273,6,4,31868,2,3,1014244648,544220477,622863910,624770160,10612,18,7,1027502117,29733,6,4,1027371045,29733,6,4,1027436581,29733,6,4,7218491,3,3,1936617315,1881481332,61,9,5,1630433317,727871605,996418877,7218557,15,6,15145,2,3,1852793723,622883955,1881488752,1954047278,1769172581,623406703,100,25,9,1680764965,1533113441,623603749,4021604,15,6,1566844205,0,4,4,93,1,3,1680764965,1533113441,1865314341,728983142,0,16,7,1281319212,1562997364,59,9,5,23849,2,3,6563116,3,3,6563117,3,3,1680764965,1533113441,1663987749,1801676136,678978665,0,20,8,1835625556,1635021929,27753,10,5,623800357,112,5,4,28709,2,3,627516704,110,5,4,1702060387,979641632,32,9,5,1852793632,1629516915,1819628127,1835093605,623000933,624632432,110,25,9,1847933737,0,4,4,1415536928,1701011826,1701606738,744760616,25637,18,7,1179672417,624649253,110,9,5,1819047278,7218491,7,4,1936617315,1600200820,1179603536,1027951689,0,16,7,1348428064,778315078,1853189987,992684916,28197,18,7,1847933821,0,4,4,1179672417,25637,6,4,1819047278,0,4,4,1936617315,1600200820,1680164432,1970436925,624584044,1868770404,980708981,1701719088,3830904,35,11,796753277,1881481263,28197,10,5,539963261,1847947301,0,8,5,1952803872,1885954336,624636221,1768453998,1948804460,694515058,1769436027,677929844,695232865,1668162939,543519585,2112049,47,14,28197,2,3,791617659,7349536,7,4,1936617315,1600200820,1701723460,1916870775,679043442,623600677,1600203364,3877187,31,10,1936617315,1600200820,1701723472,1916870775,679043442,992568357,0,24,9,544499052,625762145,15204,10,5,16427,2,3,1713513003,0,4,4,1935498027,6118260,7,4,1566274603,0,4,4,1046560299,0,4,4,4088107,3,3,6372907,3,3,625368929,100,5,4,742612833,1867931489,1630299750,2709087,15,6,4284257,3,3,1668183398,1852795252,678569248,0,12,6,1735549300,1634563173,28265,10,5,1847933737,7218557,7,4,678569248,0,4,4,691022896,7218491,7,4,2002739488,1718905185,2650735,11,5,1852793632,1629516915,1920224351,1970436925,758801772,1701719089,1849324664,2104257653,7218491,35,11,1668183398,1852795252,1381982496,676613967,1847950121,0,20,8,7218557,3,3,2105359145,28197,6,4,1281319212,29300,6,4,1600207657,1953063287,1131573094,1936485473,1881481819,826105122,1847950651,1696604192,543519596,1630037609,1767995231,1919903348,1819042115,623008627,559751792,2066297149,1632001889,1164730740,1919906418,573321256,2256933,83,23,677800224,843472737,2083536189,1667195260,1867804781,678589523,826695521,1180655916,622996530,2066293360,538996261,677800224,2002739489,1718905185,1631810159,1534291052,577774882,1635461469,1767995231,1919903348,1819042115,623008627,1029513840,1915042610,40,97,27,1918132065,1180655916,1600203825,2066297414,1663069733,1953721967,1281319200,2067624564,1701606770,1848389690,980711525,1918132065,1847933821,0,52,16,826695521,1180655916,628828466,110,13,6,1668183398,1852795252,2002739488,1718905185,2650735,19,7,1936617315,1600200820,1953063287,1131573094,1936485473,995973949,28197,26,9,1180655904,1282174057,1937011561,1180655912,1416391785,1701601889,1600207657,1819044166,1818386772,1970158949,624651372,110,45,14,29221,2,3,792406365,628106543,110,9,5,779232544,1635018099,677471602,91,13,6,779232544,1953066601,624634152,110,13,6,678438176,992571941,1881485103,28197,14,6,1847929904,0,4,4,744760621,28197,6,4,791441957,1881481263,28197,10,5,2909221,3,3,1769238133,2019913324,1836016500,24941,14,6,995963181,539963168,1819044198,1650553888,1931502956,543521385,1847944229,0,28,10,544499052,1766219617,1632922732,1030057058,7218523,19,7,577774882,0,4,4,1847933789,0,4,4,1767995170,1919903348,34,9,5,1936617315,1600200820,1701606738,1701667150,5979507,19,7,1936617315,1914970228,2003136061,1147101472,1180791905,677735529,577774882,744760620,623669797,1680157810,1847933737,0,44,14,1936617315,1915035764,2003136061,1147101472,1180791905,677735529,577774882,808203308,808202284,1847933737,0,40,13,1936617315,1915035764,2003136061,1130324256,1181901160,677735529,577774882,744760620,623669797,624634226,110,41,13,1936617315,1915035764,2003136061,1130324256,1181901160,677735529,577774882,808203308,992555052,28197,38,12,1936617315,1915035764,2003136061,1096769824,2036429426,744760616,577774882,744760620,623670309,1680157812,1847933737,0,44,14,1936617315,1915035764,2003136061,1096769824,2036429426,744760616,577774882,744760620,741354544,624634160,110,41,13,544499052,624783909,790641524,1881481263,28197,18,7,1936617315,1600200820,1953655126,1298948469,624782953,1701591920,1600200820,1953655126,1298948469,624785505,1847933808,0,44,14,1936617315,1600200820,1130722133,1399614561,1801675124,996418877,807415599,1847602464,824192111,1702436909,7218547,43,13,1847948069,0,4,4,622866223,622993520,1847927408,0,12,6,1075851055,1852399981,1881481760,7218466,15,6,1092626991,1213220172,544175136,1635148138,1769104243,1814066288,1701539433,628498546,1680158308,623847968,795747694,1768693807,1684368238,1685024032,1936026741,7218490,63,18,1852793632,1629516915,1920224351,1970436925,624584044,1701719140,1631220856,2104644703,7218491,35,11,1951162209,114,5,4,1918132065,0,4,4,774778459,93,5,4,1870094177,25714,6,4,1852404336,1920233588,0,8,5,1819635291,23916,6,4,1852404336,1179992692,5391686,11,5,1852793659,1970170228,15205,10,5,1030777185,0,4,4,1952805408,544109173,15152,10,5,1952805408,997094005,0,8,5,1952805408,544109173,15153,10,5,1532387169,1867931489,2844262,11,5,1532387169,1867931489,6121062,11,5,1885695073,6499944,7,4,0,
a_1418,/* MESSAGE */
14,1852727651,1663071343,1952540018,1635000421,1952802674,1818846752,2015699045,1919229996,544370546,1701080931,1680154682,0,44,14,0,
a_1418,/* MESSAGE */
15,1701606770,1767995168,1919903348,1852776506,1696627052,2037674093,1685024032,543517813,1953460082,1847602291,1847620719,1701078373,100,49,15,0,
a_1418,/* MESSAGE */
28,1768710499,6648418,7,4,1651993697,0,4,4,1651537249,0,4,4,1651993718,0,4,4,1651537270,0,4,4,829579105,0,4,4,846356321,0,4,4,0,
a_1418,/* MESSAGE */
31,1702131813,1818324594,1819636256,1953701989,1735289202,1881481760,623386658,1830824297,1702065001,1818304627,1852990836,1986622561,1680154725,0,52,16,1702131813,1818324594,1819636256,1953701989,1735289202,1881481760,623386658,1830824297,1769173865,1629513582,2020173414,544173600,25637,50,15,0,
a_1001,/* @StringTable */
45,1953723757,0,4,4,1634625894,1635149164,108,9,5,1634625894,1935762028,101,9,5,1936682860,1635149157,108,9,5,1684104562,1919973477,1769173861,28271,14,6,1667590243,1852793707,1851880563,1887007860,101,17,7,1667590243,1818321771,1701995113,1701869940,0,16,7,1667590243,1936288875,1887007860,101,13,6,0,
a_1418,/* MESSAGE */
14,540700709,1936617315,1953390964,1717920800,1953066601,544108393,1701209458,1948283762,1953046639,1718379891,1764042784,41,45,14,0,
a_1001,/* @StringTable */
84,1953723757,0,4,4,1920230771,1852993637,1700949365,114,13,6,1635017060,1952671091,1768845161,26985,14,6,1702131813,1818324594,1920233061,121,13,6,1635017060,1952671091,1768845161,105,13,6,1953720684,1920233061,121,9,5,1885956979,1819044198,1953066601,1768710505,7497082,19,7,1667590243,1818846827,1887007845,101,13,6,1667590243,1818846827,1852793708,1851880563,1887007860,101,21,8,1667590243,1852793707,1851880563,1887007860,101,17,7,1667590243,1936288875,1887007860,101,13,6,1635017060,1952671091,1768845161,0,12,6,1885956979,1635017060,1952671091,7237481,15,6,1885956979,1920233061,121,9,5,0,
a_1418,/* MESSAGE */
16,1713401893,980184169,1885696544,1702125925,1868767346,1635021678,622883950,1936269412,1953853216,543584032,1735287154,1831346277,622884961,10596,54,16,0,
a_1418,/* MESSAGE */
40,540700709,1634493810,1702259060,2053731104,1936007269,1634560372,544370548,1763730469,1970217075,1718558836,1851879968,673211751,2713893,51,15,540700709,1702521203,1953719584,1952542057,622883439,1936269412,1953853216,544370464,1735287154,623386725,10601,42,13,540700709,1702521203,1953719584,1952542057,622883439,1634214000,1869488243,1818326560,673211765,2713893,39,12,0,
a_1418,/* MESSAGE */
33,1819044198,543649385,540700709,622883937,1701978220,1952540016,622883429,1936269424,1953459744,1717920800,1684369001,0,44,14,1819044198,543649385,1629515813,1814372468,1635131450,543520108,1864393765,1701978214,1952540016,622883429,1936269424,1953853216,543584032,1735287154,1831346277,622884961,10596,66,19,0,
a_1418,/* MESSAGE */
9,1970499177,1667851878,1953391977,1919514144,1818326388,1634759456,25955,26,9,0,
a_1001,/* @StringTable */
37,1953723757,0,4,4,1851876211,1835365481,0,8,5,1684104552,1952671091,7237481,11,5,1684104562,1768318308,1769236846,1768713839,29811,18,7,1684104562,1835365481,0,8,5,1667590243,1702127979,4475245,11,5,1836216166,1717660769,1702390118,115,13,6,0,
a_1449,/* LEXT */
43,1920226112,1416064617,1701601889,0,12,6,0,0,1718184051,1717985652,1818392681,7037807,15,6,0,0,1635018087,2020173414,1668246626,7302763,15,6,0,0,1635205184,1868985449,114,9,5,0,0,1634549824,25963,6,4,0,0,1869574720,116,5,4,0,0,0,
a_1418,/* MESSAGE */
22,1701998445,1634235424,1852776558,1634541669,1830841961,1819632751,622869093,112,29,10,1886220131,1684368489,1919903264,1718182944,1701995878,1948284014,1701278305,1870078068,1931502706,6650473,39,12,0,
a_1418,/* MESSAGE */
43,1830842222,544106849,1969516397,25964,14,6,540700709,544501614,1768318308,543450478,622883937,105,21,8,540700709,1868787305,1952542829,1701601897,1887007776,1629516645,1764040820,1684955424,6890784,35,11,540700709,1651863396,1679849836,1852401253,1629512805,1764040820,1684955424,6890784,31,10,540700709,544501614,1701209458,1668179314,622879845,105,21,8,0,
a_1449,/* LEXT */
52,1818308398,795373669,1667855210,1966029413,1815048819,1818321775,1701601583,1781491824,1701013875,0,36,12,0,0,1818522739,25193,6,4,0,0,926365233,909193783,0,8,5,0,0,808661298,875966519,12851,10,5,0,0,1869639017,1666413682,1953524082,1629628531,1752196460,1781417298,992551539,0,28,10,0,0,1159737135,17999,6,4,0,0,0,
a_1418,/* MESSAGE */
184,1802398028,1162625312,1294813264,1667837472,1768300645,544433516,1629515636,1986095648,1919120225,544501865,1735357040,778920306,1934978597,979724129,1936351520,1802398060,757947168,1886152040,757955616,1936876918,1567518569,538996261,980578080,1936351520,1802398060,1886346016,1852795252,1713397107,828730473,1818846752,773861989,1847930414,1769238607,980643439,538996261,1008758573,1735549300,540963941,538976288,1701344288,1953853216,544503152,544434734,1701603686,538996261,1008749613,1047685476,538976288,538976288,1986095648,1768125281,1931506800,1768711284,1768169570,1952671090,628716143,757080174,1932357486,1768711284,538976354,538976288,661548900,1684086900,1953701988,1633971809,1814062194,1634886249,1847949682,1462575136,538976288,538976288,538976288,1914708000,1919905893,1869488244,1937055860,1881171045,1768710773,1953046627,628321637,543574382,1864396654,1970304117,1936269428,1701868320,1768319331,539780197,543516788,1701667182,543584032,543516788,1852399981,1667837472,1768300645,1763730796,1970152819,543450483,1752459639,1936338464,1954047264,1769172581,1629515375,1730176110,1919250021,1684370529,544106784,543516788,1920103779,544501349,1701996900,1919906915,11897,446,114,1346718785,541928776,1635148138,1769104243,1814066288,1701539433,1702240370,1869181810,1680154734,627320110,1886339950,1734963833,673215592,840968515,758395440,892481586,1935756320,544173178,1919513411,628777325,1768445038,1936269427,1713398048,543516018,1952870259,1701994871,1702043692,1752440933,1869815909,1701016181,544497952,1886680168,791624307,1752459623,1663984245,1815047535,1919513443,796549485,1885695073,1718494568,1663070831,1920561263,1952999273,1718511904,1634562671,1852795252,1750343726,543519333,1310749545,1096228943,1312903762,540760404,544501614,1852143205,1667591456,1953390952,1818845801,544830569,1847947887,1853122918,544437093,544370534,1634738273,1667855474,1918987381,1920299040,1702063984,46,269,70,0,
a_1001,/* @StringTable */
42,1953723757,0,4,4,1852141679,1701603686,1634497377,29811,14,6,1769108595,1869899630,1179014466,21061,14,6,26413,2,3,22317,2,3,19501,2,3,28461,2,3,762277421,1818522739,25193,10,5,1702243629,1869181810,110,9,5,1701326125,28780,6,4,0,
a_1418,/* MESSAGE */
57,1763733358,1953853550,1818846752,1886593125,1718182757,744777065,1702065440,1747791136,544238693,544370534,1752375393,544502383,1886152040,0,52,16,1936943469,543649385,1969713761,1953391981,1952866592,757101157,25381,26,9,1769496941,544044397,1651340654,1864397413,1869815910,1701016181,623386739,1696606564,1701143416,6579556,39,12,1869771365,1886330994,1852403301,1764630631,1713399139,543517801,2125861,27,9,1700949349,1684366436,1852385056,1685417059,1763714917,1713399139,1936026729,544106784,28709,34,11,0,
a_1001,/* @StringTable */
36,1953723757,0,4,4,774778459,93,5,4,6111067,3,3,1685024040,543517813,0,8,5,1852404336,1935762036,101,9,5,1852404336,1768910964,1919251566,0,12,6,1280659035,23884,6,4,1953709116,1953853284,15934,10,5,0,
a_1418,/* MESSAGE */
41,544173940,2037277037,1920099616,745763439,1920296480,1919248500,1936026912,1701273971,1918967923,1970479205,1701998704,1684370291,0,48,15,1702129257,1818324594,1920099616,1629516399,1970413684,2123116,23,8,1650532396,1702130287,100,9,5,540700709,1920102243,544501877,1701013806,1818846752,2629733,23,8,1629498409,1953656674,25701,10,5,0,
a_1001,/* @StringTable */
51,1954047342,1651341683,27759,10,5,1684104562,1701869940,0,8,5,1684104562,1684828002,0,8,5,1684104562,1735549300,1953723493,1735289202,0,16,7,1684104562,1769108595,26478,10,5,1634231666,26739,6,4,1684104562,1953719652,1952542313,7237481,15,6,1684104562,1701080681,120,9,5,1885695073,1667837544,101,9,5,1953723757,0,4,4,0,
a_1449,/* LEXT */
5,0,0,3,0,0,0,
a_1444,/* BOLD */
270,1634038369,0,4,4,1801675106,0,4,4,7892834,3,3,1768710499,6648418,7,4,1919973477,1769173861,28271,10,5,1702131813,1869181806,110,9,5,1702131813,1818324594,0,8,5,1701603686,0,4,4,1819044198,0,4,4,1852797542,116,5,4,1818455657,6644853,7,4,1953720684,0,4,4,6453100,3,3,1852399981,0,4,4,1969516397,25964,6,4,1701080942,0,4,4,1701606770,0,4,4,28532,2,3,6451317,3,3,1651993718,0,4,4,1651537270,0,4,4,1936617315,1953390964,0,8,5,1769103734,1701601889,0,8,5,1952543859,1981834089,29281,10,5,1818386804,101,5,4,1667331187,107,5,4,1952543859,1931502441,1801675124,0,12,6,1852403568,544367988,1936617315,1953390964,0,16,7,1918986339,1701603686,0,8,5,1635017060,1701603686,0,8,5,1701606770,0,4,4,1836216166,1931504737,1801675124,0,12,6,1836216166,1948281953,1701601889,0,12,6,1836216166,1713400929,6646889,11,5,1836216166,1763732577,110,9,5,1836216166,1864395873,29813,10,5,1836216166,1763732577,1953853294,0,12,6,1836216166,1629514849,1869112174,114,13,6,1836216166,1931504737,1952868712,0,12,6,64,1,3,38,1,3,93,1,3,41,1,3,58,1,3,44,1,3,126,1,3,47,1,3,45,1,3,35,1,3,40,1,3,124,1,3,62,1,3,43,1,3,46,1,3,59,1,3,42,1,3,91,1,3,94,1,3,1936617315,116,5,4,1651340654,29285,6,4,1701869940,0,4,4,1701080942,0,4,4,1835365481,0,4,4,1836216166,27745,6,4,1633906540,108,5,4,1769108595,26478,6,4,2763306,3,3,0,
-1}; /* fill table size 2388 */
static void a_data_setup(void){
 a_virtual_min=16777216;a_virtual_max=2130706432;
 a_setup_list(0,a_1001,"@StringTable",1,2130705088,2130706407,1320); /* @StringTable */
 a_setup_list(1,a_1005,"NUMBER",1,2075075433,2130705086,0); /* NUMBER */
 a_setup_list(1,a_1022,"REGISTER",1,2047260605,2075075431,0); /* REGISTER */
 a_setup_list(1,a_1041,"NODE",6,1741296889,2019445153,0); /* NODE */
 a_setup_list(1,a_1042,"ZONE",3,2019445777,2047260601,0); /* ZONE */
 a_setup_list(1,a_1231,"EXPRESSION",1,1546593094,1741296882,0); /* EXPRESSION */
 a_setup_list(1,a_1302,"AUX",6,712148275,990296539,0); /* AUX */
 a_setup_list(1,a_1303,"ITEM",8,990296553,1546593085,0); /* ITEM */
 a_setup_list(1,a_1382,"FILES",3,128036800,155851624,0); /* FILES */
 a_setup_list(0,a_1418,"MESSAGE",1,2019445160,2019445773,614); /* MESSAGE */
 a_setup_list(0,a_1444,"BOLD",1,16777217,16777486,270); /* BOLD */
 a_setup_list(1,a_1445,"BUFFER",1,72407143,128036796,0); /* BUFFER */
 a_setup_list(1,a_1446,"HASH",1,16777488,72407141,0); /* HASH */
 a_setup_list(1,a_1449,"LEXT",2,155851629,712148267,100); /* LEXT */
 a_setup_stdarg(a_1491,"STDARG",1);
 a_setup_charfile(a_1115,"TARGET",2,a_1001,2130706112); /* TARGET */
 a_setup_charfile(a_1419,"PRINTFILE",2,a_1001,2130706356); /* PRINTFILE */
 a_setup_charfile(a_1450,"SOURCE",1,a_1001,2130706403); /* SOURCE */
 a_list_fill(a_FILL);
}
static void a_waitfor(a_word a_F1,a_word a_F2){
 a_MODROOT(a_1443,"lexical")
 a_MODROOT(a_1301,"item")
 a_MODROOT(a_1004,"number")
}
void a_ROOT(void){
 a_data_setup();
 a_waitfor(0,0);
 a_1480();
}
static void a_1011(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* loadregister+>a+>a+a> */
a_word a_P[1];
a_1026(a_F1,a_1005,a_F2,a_P);a_A[0]=a_P[0]; return;
} /* loadregister */
static a_word a_1016(a_word a_F1,a_word a_F2){ /* samenumberblock+>a+>a */
a_word a_L3;a_word a_P[1];
a_1026(0,a_1005,a_F2,a_P);a_L3=a_P[0];
if(!a_1035(23,a_F1,a_L3)){ goto a_G4;}
a_1023(a_L3); return 1;
a_G4:a_1023(a_L3); return 0;
} /* samenumberblock */
static void a_1017(a_word a_F1,a_word a_A[1]){ /* storeregister+>a+a> */
a_word a_L3;
a_A[0]=to_LIST(a_1005)->alwb;
a_L3=0;
a_G3:if(a_more(a_L3,100)){ goto a_G5;}
if(!a_more(a_A[0],to_LIST(a_1005)->aupb)){ goto a_G7;}
a_G5:a_1032(a_F1,a_1005);
a_A[0]=to_LIST(a_1005)->aupb; return;
a_G7:if(!a_1016(a_F1,a_A[0])){ goto a_G9;}
a_1023(a_F1); return;
a_G9:a_incr(a_L3);
a_next(a_1005,a_A[0]); goto a_G3;
} /* storeregister */
static void a_1009(a_word a_A[1]){ /* getnumberzero+a> */

a_A[0]=a_1020; return;
} /* getnumberzero */
static void a_1010(a_word a_F1,a_word a_A[1]){ /* gettargetnumbervalue+>a+a> */
a_word a_L3;a_word a_P[1];
a_1026(0,a_1005,a_F1,a_P);a_L3=a_P[0];
a_1033(a_L3,a_P);a_A[0]=a_P[0]; return;
} /* gettargetnumbervalue */
static void a_1006(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* enterconststring+>a+>a+a> */
a_word a_L4;a_word a_P[1];
a_1025(a_1445,a_F2,a_F1,a_P);a_L4=a_P[0];
a_1017(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* enterconststring */
static void a_1008(a_word a_F1){ /* getnumberrepr+>a */
a_word a_L2;a_word a_P[1];
a_1026(0,a_1005,a_F1,a_P);a_L2=a_P[0];
a_1030(a_L2,a_1445); return;
} /* getnumberrepr */
static a_word a_1012(a_word a_F1,a_word a_F2){ /* minmaxregisters+>a+>a */

if(!a_1035(23,a_F1,a_1015)){ return 0;}
if(!a_1035(23,a_F2,a_1014)){ return 0;} return 1;
} /* minmaxregisters */
static void a_1007(a_word a_F1,a_word a_A[2]){ /* entertargetstring+>a+a>+a> */
a_word a_L4;a_word a_L5;a_word a_P[2];
a_1028(a_1445,a_F1,a_P);a_A[0]=a_P[0];a_L4=a_P[1];
a_L5=a_A[0];
a_G3:if(a_less(a_L5,1)){ goto a_G6;}
a_decr(a_L5);
a_P[0]=a_L4;a_1029(a_1005,a_P);a_L4=a_P[0]; goto a_G3;
a_G6:a_A[1]=to_LIST(a_1005)->aupb; return;
} /* entertargetstring */
static void a_1013(a_word a_A[2]){ /* nexttargetstringvalue+>a>+a> */
a_word a_L3;
if(!a_more(a_A[0],1)){ goto a_G7;}
a_decr(a_A[0]);
a_L3=to_LIST(a_1005)->aupb;
a_previous(a_1005,a_L3);
a_unstackto(a_1005,a_L3);
a_A[1]=to_LIST(a_1005)->aupb; return;
a_G7:if(!a_equal(a_A[0],1)){ goto a_G12;}
a_decr(a_A[0]);
a_L3=to_LIST(a_1005)->aupb;
a_previous(a_1005,a_L3);
a_unstackto(a_1005,a_L3);
a_G12:a_A[1]=0; return;
} /* nexttargetstringvalue */
static void a_1004(void){ /* @root */
a_word a_L1;a_word a_P[1];
 a_waitfor(a_1001,2130705105); a_1026(1,a_1005,0,a_P);a_L1=a_P[0];
a_1017(a_L1,a_P);a_1020=a_P[0];
if(a_equal(to_LIST(a_1005)->alwb,to_LIST(a_1005)->aupb)){ goto a_G6;}
a_1425(a_1001,2130705100); return;
a_G6:a_1026(3,a_1005,0,a_P);a_1014=a_P[0];
a_1026(4,a_1005,0,a_P);a_1015=a_P[0];
a_1026(2,a_1005,a_1014,a_P);a_L1=a_P[0];
a_1017(a_L1,a_P);a_1018=a_P[0];
a_1026(2,a_1005,a_1015,a_P);a_L1=a_P[0];
a_1017(a_L1,a_P);a_1019=a_P[0]; return;
} /* @root */
static void a_1026(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]){ /* getregister+>a+t[]+>a+a> */

 static const char *a_rulename="getregister";
{register a_word *a_r1=a_extension(a_1022,1);a_r1[0]=0;to_LIST(a_1022)->aupb+=1;}
a_A[0]=to_LIST(a_1022)->aupb;
{ if(a_F1==0){ goto a_G4;}
 if(a_F1==1){ goto a_G5;}
 if(a_F1==2){ goto a_G6;}
 if(a_F1==3){ goto a_G7;}
 if(!(a_F1==4)){a_area_failed(a_rulename,a_F1);}
  goto a_G8;}
a_G4:to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb]=to_LIST(a_F2)->offset[a_F3]; return;
a_G5:to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb]=a_F3; return;
a_G6:to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb]=to_LIST(a_1022)->offset[a_F3]; return;
a_G7:to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb]=2147483647; return;
a_G8:to_LIST(a_1022)->offset[to_LIST(a_1022)->aupb]=(-1-2147483647); return;
} /* getregister */
static void a_1032(a_word a_F1,a_word a_F2){ /* putregister+>a+[]st[] */

{register a_word *a_r1=a_extension(a_F2,1);a_r1[0]=to_LIST(a_1022)->offset[a_F1];to_LIST(a_F2)->aupb+=1;}
if(a_noteq(a_F1,to_LIST(a_1022)->aupb)){ return;}
a_unstack(a_1022); return;
} /* putregister */
static void a_1029(a_word a_F2,a_word a_A[1]){ /* popregister+>a>+[]st[] */

{register a_word *a_r1=a_extension(a_F2,1);a_r1[0]=to_LIST(a_1022)->offset[a_A[0]];to_LIST(a_F2)->aupb+=1;}
if(a_noteq(a_A[0],to_LIST(a_1022)->aupb)){ goto a_G4;}
a_unstack(a_1022);
a_G4:a_A[0]=to_LIST(a_1022)->aupb; return;
} /* popregister */
static void a_1033(a_word a_F1,a_word a_A[1]){ /* putregistervalue+>a+a> */

a_A[0]=to_LIST(a_1022)->offset[a_F1];
if(a_noteq(a_F1,to_LIST(a_1022)->aupb)){ return;}
a_unstack(a_1022); return;
} /* putregistervalue */
static void a_1023(a_word a_F1){ /* freeregister+>a */

if(a_noteq(a_F1,to_LIST(a_1022)->aupb)){ return;}
a_unstack(a_1022); return;
} /* freeregister */
static void a_1027(a_word a_A[1]){ /* markregisters+a> */

a_A[0]=to_LIST(a_1022)->aupb; return;
} /* markregisters */
static void a_1024(a_word a_F1){ /* freeregistersfrommark+>a */

a_unstackto(a_1022,a_F1); return;
} /* freeregistersfrommark */
static void a_1036(a_word a_F1,a_word a_F2,a_word a_F3){ /* regoperator+>a+>a+>a */

 static const char *a_rulename="regoperator";
{ if(a_F1==1){ goto a_G2;}
 if(a_F1==2){ goto a_G5;}
 if(a_F1==3){ goto a_G6;}
 if(a_F1==6){ goto a_G7;}
 if(a_F1==7){ goto a_G8;}
 if(a_F1==8){ goto a_G9;}
 if(a_F1==9){ goto a_G10;}
 if(a_F1==4){ goto a_G11;}
 if(!(a_F1==5)){a_area_failed(a_rulename,a_F1);}
  goto a_G12;}
a_G2:a_boolxor(to_LIST(a_1022)->offset[a_F3],to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3]);
a_G3:if(a_noteq(a_F2,to_LIST(a_1022)->aupb)){ return;}
a_unstack(a_1022); return;
a_G5:a_booland(to_LIST(a_1022)->offset[a_F3],to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3]); goto a_G3;
a_G6:a_boolor(to_LIST(a_1022)->offset[a_F3],to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3]); goto a_G3;
a_G7:a_add(to_LIST(a_1022)->offset[a_F3],to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3]); goto a_G3;
a_G8:a_subtr(to_LIST(a_1022)->offset[a_F3],to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3]); goto a_G3;
a_G9:a_mult(to_LIST(a_1022)->offset[a_F3],to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3]); goto a_G3;
a_G10:a_div(to_LIST(a_1022)->offset[a_F3],to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3]); goto a_G3;
a_G11:a_boolinvert(to_LIST(a_1022)->offset[a_F3],to_LIST(a_1022)->offset[a_F3]); return;
a_G12:a_subtr(0,to_LIST(a_1022)->offset[a_F3],to_LIST(a_1022)->offset[a_F3]); return;
} /* regoperator */
static a_word a_1034(a_word a_F1,a_word a_F2){ /* regcompare+>a+>a */

 static const char *a_rulename="regcompare";
{ if(a_F1==10){ goto a_G2;}
 if(a_F1==11){ goto a_G3;}
 if(!(a_F1==12)){a_area_failed(a_rulename,a_F1);}
  goto a_G4;}
a_G2:if(!a_equal(to_LIST(a_1022)->offset[a_F2],0)){ return 0;} return 1;
a_G3:if(!a_less(to_LIST(a_1022)->offset[a_F2],0)){ return 0;} return 1;
a_G4:if(!a_more(to_LIST(a_1022)->offset[a_F2],0)){ return 0;} return 1;
} /* regcompare */
static a_word a_1035(a_word a_F1,a_word a_F2,a_word a_F3){ /* regcompare2+>a+>a+>a */
a_word a_L4;
 static const char *a_rulename="regcompare2";
{ if(a_F1==20){ goto a_G2;}
 if(a_F1==21){ goto a_G5;}
 if(a_F1==22){ goto a_G6;}
 if(!(a_F1==23)){a_area_failed(a_rulename,a_F1);}
  goto a_G7;}
a_G2:a_L4=to_LIST(a_1022)->offset[a_F2];
a_incr(a_L4);
if(!a_equal(a_L4,to_LIST(a_1022)->offset[a_F3])){ return 0;} return 1;
a_G5:if(!a_less(to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3])){ return 0;} return 1;
a_G6:if(!a_lseq(to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3])){ return 0;} return 1;
a_G7:if(!a_equal(to_LIST(a_1022)->offset[a_F2],to_LIST(a_1022)->offset[a_F3])){ return 0;} return 1;
} /* regcompare2 */
static void a_1030(a_word a_F1,a_word a_F2){ /* putdecimalform+>a+[]st[] */
a_word a_L2;
a_L2=to_LIST(a_1022)->offset[a_F1];
if(a_noteq(a_F1,to_LIST(a_1022)->aupb)){ goto a_G4;}
a_unstack(a_1022);
a_G4:if(!a_equal(a_L2,(-1-2147483647))){ goto a_G10;}
{register a_word *a_r1=a_extension(a_F2,1);a_r1[0]=40;to_LIST(a_F2)->aupb+=1;}
a_1031(-1,a_F2);
a_incr(a_L2);
a_1031(a_L2,a_F2);
{register a_word *a_r1=a_extension(a_F2,1);a_r1[0]=41;to_LIST(a_F2)->aupb+=1;}
  return;
a_G10:a_1031(a_L2,a_F2); return;
} /* putdecimalform */
static void a_1031(a_word a_F1,a_word a_F2){ /* putint1+>a+[]st[] */
a_word a_L2;a_word a_L3;
a_G1:if(!a_less(a_F1,0)){ goto a_G4;}
{register a_word *a_r1=a_extension(a_F2,1);a_r1[0]=45;to_LIST(a_F2)->aupb+=1;}
a_subtr(0,a_F1,a_F1); goto a_G1;
a_G4:a_divrem11(a_F1,10,a_L2,a_L3);
if(a_equal(a_L2,0)){ goto a_G7;}
a_1031(a_L2,a_F2);
a_G7:a_add(48,a_L3,a_L3);
{register a_word *a_r1=a_extension(a_F2,1);a_r1[0]=a_L3;to_LIST(a_F2)->aupb+=1;}
  return;
} /* putint1 */
static void a_1025(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]){ /* getdecimalform+t[]+>a+>a+a> */
a_word a_L4;a_word a_L5;a_word a_P[1];
a_incr(a_F2);
a_L4=0;
a_G3:if(a_more(a_F2,to_LIST(a_F1)->aupb)){ goto a_G7;}
a_subtr(to_LIST(a_F1)->offset[a_F2],48,a_L5);
a_addmult(a_L4,10,a_L5,a_L4);
a_incr(a_F2); goto a_G3;
a_G7:if(!a_is(a_F3)){ goto a_G9;}
a_subtr(0,a_L4,a_L4);
a_G9:a_1026(1,a_F1,a_L4,a_P);a_A[0]=a_P[0]; return;
} /* getdecimalform */
static void a_1028(a_word a_F1,a_word a_F2,a_word a_A[2]){ /* packstringtoregisters+t[]+>a+a>+a> */
a_word a_L4;a_word a_L5;
a_L4=to_LIST(a_1022)->aupb;
a_subtr(to_LIST(a_F1)->aupb,a_F2,a_L5);
a_packstring(a_F1,a_L5,a_1022);
a_A[1]=to_LIST(a_1022)->aupb;
a_subtr(a_A[1],a_L4,a_A[0]); return;
} /* packstringtoregisters */
static void a_1091(void){ /* rulesection */

a_G1:if(!a_equal(16777285,a_1459)){ goto a_G4;}
a_1466();
a_1078(); goto a_G1;
a_G4:if(!a_equal(16777486,a_1459)){ goto a_G6;}
a_1466(); return;
a_G6:a_1420(a_1001,2130705141); return;
} /* rulesection */
static void a_1101(void){ /* skiprule */

a_G1:if(!a_equal(16777439,a_1459)){ goto a_G3;}
a_G2:a_1466(); return;
a_G3:if(a_equal(16777486,a_1459)){ goto a_G2;}
a_1466(); goto a_G1;
} /* skiprule */
static void a_1068(a_word a_A[1]){ /* getitemdef+>a> */

if(!a_1341(a_A[0],8)){ return;}
a_A[0]=to_LIST(a_1303)->offset[a_A[0]]; return;
} /* getitemdef */
static void a_1059(a_word a_F1,a_word a_F2){ /* findintervalpair+>a+>a */
a_word a_L3;
if(a_1035(22,a_F2,to_LIST(a_1042)->offset[a_F1-1])){ return;}
a_L3=to_LIST(a_1042)->offset[a_F1];
to_LIST(a_1042)->offset[a_F1-1]=a_F2;
a_G4:if(!a_equal(a_L3,0)){ goto a_G6;}
to_LIST(a_1042)->offset[a_F1]=0; return;
a_G6:if(!a_1035(21,a_F2,to_LIST(a_1042)->offset[a_L3-2])){ goto a_G8;}
to_LIST(a_1042)->offset[a_F1]=a_L3; return;
a_G8:if(!a_1035(22,a_F2,to_LIST(a_1042)->offset[a_L3-1])){ goto a_G11;}
to_LIST(a_1042)->offset[a_F1-1]=to_LIST(a_1042)->offset[a_L3-1];
to_LIST(a_1042)->offset[a_F1]=to_LIST(a_1042)->offset[a_L3]; return;
a_G11:a_L3=to_LIST(a_1042)->offset[a_L3]; goto a_G4;
} /* findintervalpair */
static void a_1043(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]){ /* addinterval+>a+>a+>a+>a> */
a_word a_L5;
a_G1:a_L5=to_LIST(a_1042)->offset[a_F1];
if(!a_equal(a_L5,0)){ goto a_G6;}
a_A[0]=1;
{register a_word *a_r1=a_extension(a_1042,3);a_r1[0]=a_F2;a_r1[1]=a_F3;a_r1[2]=0;to_LIST(a_1042)->aupb+=3;}
a_G5:to_LIST(a_1042)->offset[a_F1]=to_LIST(a_1042)->aupb; return;
a_G6:if(!a_1035(21,a_F2,to_LIST(a_1042)->offset[a_L5-2])){ goto a_G12;}
a_A[0]=1;
if(!a_1035(21,a_F3,to_LIST(a_1042)->offset[a_L5-2])){ goto a_G10;}
{register a_word *a_r1=a_extension(a_1042,3);a_r1[0]=a_F2;a_r1[1]=a_F3;a_r1[2]=a_L5;to_LIST(a_1042)->aupb+=3;}
  goto a_G5;
a_G10:to_LIST(a_1042)->offset[a_L5-2]=a_F2;
a_G11:a_1059(a_L5,a_F3); return;
a_G12:if(!a_1035(22,a_F2,to_LIST(a_1042)->offset[a_L5-1])){ goto a_G15;}
if(a_1035(22,a_F3,to_LIST(a_1042)->offset[a_L5-1])){ return;}
a_A[0]=1; goto a_G11;
a_G15:a_F1=a_L5; goto a_G1;
} /* addinterval */
static void a_1081(a_word a_F1){ /* mergeintervals+>a */
a_word a_L2;
a_G1:if(a_equal(to_LIST(a_1042)->offset[a_F1],0)){ return;}
a_F1=to_LIST(a_1042)->offset[a_F1];
a_L2=to_LIST(a_1042)->offset[a_F1];
a_G4:if(!a_noteq(a_L2,0)){ goto a_G1;}
if(!a_1035(20,to_LIST(a_1042)->offset[a_F1-1],to_LIST(a_1042)->offset[a_L2-2])){ goto a_G1;}
to_LIST(a_1042)->offset[a_F1-1]=to_LIST(a_1042)->offset[a_L2-1];
{register a_word a_r1=to_LIST(a_1042)->offset[a_L2];to_LIST(a_1042)->offset[a_F1]=a_r1;a_L2=a_r1;} goto a_G4;
} /* mergeintervals */
static a_word a_1052(a_word a_F1){ /* completezone+>a */

a_F1=to_LIST(a_1042)->offset[a_F1];
if(!a_is(a_F1)){ return 0;}
if(!a_1012(to_LIST(a_1042)->offset[a_F1-2],to_LIST(a_1042)->offset[a_F1-1])){ return 0;} return 1;
} /* completezone */
static void a_1087(a_word a_A[2]){ /* readareainterval+a>+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[1];
if(!a_equal(16777459,a_1459)){ goto a_G6;}
a_A[0]=a_1460;
a_1466();
a_G4:a_A[1]=a_A[0];
a_L4=1; goto a_G26;
a_G6:if(!a_equal(16777471,a_1459)){ goto a_G23;}
a_L3=a_1460;
a_1466();
a_P[0]=a_L3;a_1068(a_P);a_L3=a_P[0];
{register a_word a_r1=to_LIST(a_1303)->offset[a_L3-6];
 if(a_r1==16777304||a_r1==16777335){ goto a_G11;}
 if(a_r1==16777322||a_r1==16777318||a_r1==16777328){  goto a_G12;}
  goto a_G22;}
a_G11:a_A[0]=to_LIST(a_1303)->offset[a_L3]; goto a_G4;
a_G12:a_1335(a_L3,a_P);a_A[0]=a_P[0];
a_1011(0,a_A[0],a_P);a_L5=a_P[0];
a_1325(a_L3,a_P);a_A[1]=a_P[0];
a_1011(1,a_A[1],a_P);a_L6=a_P[0];
a_1036(7,a_L6,a_L5);
a_1011(1,1,a_P);a_L6=a_P[0];
a_1036(6,a_L6,a_L5);
a_1017(a_L5,a_P);a_A[0]=a_P[0];
a_1336(a_L3,a_P);a_A[1]=a_P[0];
a_L4=2; goto a_G26;
a_G22:a_1420(a_1001,2130705136); return;
a_G23:a_1009(a_P);a_A[0]=a_P[0];
a_1009(a_P);a_A[1]=a_P[0];
a_L4=0;
a_G26:if(!a_equal(16777409,a_1459)){ goto a_G41;}
a_1466();
if(!a_equal(a_L4,0)){ goto a_G30;}
a_A[0]=a_1019; goto a_G31;
a_G30:if(!a_equal(a_L4,1)){ goto a_G22;}
a_G31:if(!a_equal(16777459,a_1459)){ goto a_G34;}
a_A[1]=a_1460;
a_1466(); return;
a_G34:if(!a_equal(16777471,a_1459)){ goto a_G40;}
a_L3=a_1460;
a_1466();
a_P[0]=a_L3;a_1068(a_P);a_L3=a_P[0];
{register a_word a_r1=to_LIST(a_1303)->offset[a_L3-6];
 if(!(a_r1==16777304||a_r1==16777335)){ goto a_G22;}
}
a_A[1]=to_LIST(a_1303)->offset[a_L3]; return;
a_G40:a_A[1]=a_1018; return;
a_G41:if(!a_equal(a_L4,0)){ return;} goto a_G22;
} /* readareainterval */
static void a_1046(a_word a_F1,a_word a_A[1]){ /* checkarea+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_L7;a_word a_P[4];
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_A[0]=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130705109); return;
a_G5:a_L3=0;
a_G6:a_1087(a_P);a_L4=a_P[0];a_L5=a_P[1];
a_1011(0,a_L4,a_P);a_L6=a_P[0];
a_1011(0,a_L5,a_P);a_L7=a_P[0];
if(!a_1035(22,a_L6,a_L7)){ goto a_G11;}
a_P[0]=a_L3;a_1043(a_F1,a_L6,a_L7,a_P);a_L3=a_P[0]; goto a_G12;
a_G11:a_P[0]=2019445174;a_P[1]=a_A[0];a_P[2]=a_L4;a_P[3]=a_L5;a_1421(4,a_P);
a_G12:if(!a_equal(16777442,a_1459)){ goto a_G14;}
a_1466(); goto a_G6;
a_G14:a_1081(a_F1);
if(a_is(a_L3)){ return;}
a_P[0]=2019445187;a_P[1]=a_A[0];a_1421(2,a_P); return;
} /* checkarea */
static void a_1047(void){ /* checkareas */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[2];
a_scratch(a_1042);
{register a_word *a_r1=a_extension(a_1042,3);a_r1[0]=a_r1[1]=a_r1[2]=0;to_LIST(a_1042)->aupb+=3;}
a_L1=to_LIST(a_1042)->aupb;
a_1027(a_P);a_L4=a_P[0];
a_L2=0;a_L3=0;
a_G6:if(!a_equal(16777220,a_1459)){ goto a_G14;}
a_1466();
a_incr(a_L3);
a_1046(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(16777433,a_1459)){ goto a_G13;}

a_1466(); goto a_G6;
a_G13:a_1420(a_1001,2130705109); return;
a_G14:if(!a_1052(a_L1)){ goto a_G18;}
a_1097(2048);
if(a_more(a_L3,1)){ goto a_G20;}
a_P[0]=2019445212;a_P[1]=a_L2;a_1421(2,a_P); goto a_G20;
a_G18:a_P[0]=2019445200;a_P[1]=a_L2;a_1441(2,a_P);
a_1111=1;
a_G20:a_1024(a_L4); return;
} /* checkareas */
static void a_1097(a_word a_F1){ /* setnodeflag+>a */

a_boolor(a_F1,to_LIST(a_1041)->offset[a_1112-4],to_LIST(a_1041)->offset[a_1112-4]); return;
} /* setnodeflag */
static void a_1086(a_word a_F1,a_word a_F2){ /* putnodeflag+>a+>a */

a_boolor(a_F2,to_LIST(a_1041)->offset[a_F1-4],to_LIST(a_1041)->offset[a_F1-4]); return;
} /* putnodeflag */
static void a_1049(a_word a_F1,a_word a_F2){ /* clearnodeflag+>a+>a */

a_boolinvert(a_F2,a_F2);
a_booland(a_F2,to_LIST(a_1041)->offset[a_F1-4],to_LIST(a_1041)->offset[a_F1-4]); return;
} /* clearnodeflag */
static void a_1054(void){ /* createnodes */
a_word a_L1;
a_scratch(a_1041);
if(!a_equal(16777455,a_1459)){ goto a_G5;}
a_L1=a_1460;
a_1466(); goto a_G6;
a_G5:a_1420(a_1001,2130705109); return;
a_G6:if(a_equal(a_L1,0)){ return;}
{register a_word *a_r1=a_extension(a_1041,6);a_r1[0]=a_r1[1]=a_r1[2]=a_r1[3]=a_r1[4]=a_r1[5]=0;to_LIST(a_1041)->aupb+=6;}
a_decr(a_L1); goto a_G6;
} /* createnodes */
static void a_1044(void){ /* advancenode */

if(!a_equal(16777467,a_1459)){ goto a_G4;}

a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130705109); return;
a_G5:if(!a_equal(a_1112,0)){ goto a_G7;}
a_1112=to_LIST(a_1041)->alwb; goto a_G8;
a_G7:a_next(a_1041,a_1112);
a_G8:if(a_lseq(a_1112,to_LIST(a_1041)->aupb)){ return;}
a_1420(a_1001,2130705129); return;
} /* advancenode */
static void a_1069(a_word a_F1,a_word a_A[1]){ /* getnodeindex+>a+a> */

a_subtr(a_F1,to_LIST(a_1041)->alwb,a_A[0]);
a_div(a_A[0],6,a_A[0]);
a_incr(a_A[0]); return;
} /* getnodeindex */
static void a_1073(a_word a_F1,a_word a_A[1]){ /* indextonode+>a+a> */

a_decr(a_F1);
a_addmult(a_F1,6,to_LIST(a_1041)->alwb,a_A[0]); return;
} /* indextonode */
static void a_1098(void){ /* setrulehead */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130705109); return;
a_G5:a_P[0]=a_L1;a_1068(a_P);a_L1=a_P[0];
to_LIST(a_1041)->offset[a_1112-3]=a_L1;
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L2=a_1460;
a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L3=a_1460;
a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L4=a_1460;
a_1466();
if(a_1341(a_L1,12288)){ return;}
if(!a_1341(a_L1,16384)){ goto a_G19;}
a_1097(8); return;
a_G19:a_max(a_L2,a_1038);
a_max(a_L3,a_1039);
a_max(a_L4,a_1040); return;
} /* setrulehead */
static void a_1102(void){ /* skiprulehead */

a_1466();
a_1466();
a_1466();
a_1466(); return;
} /* skiprulehead */
static void a_1050(void){ /* clearstacksize */

a_1038=0;a_1039=0;a_1040=0; return;
} /* clearstacksize */
static void a_1079(a_word a_F1){ /* marklocalaffix+>a */

if(a_equal(a_1055,0)){ return;}
a_add(a_1076,a_F1,a_F1);
to_LIST(a_1445)->offset[a_F1]=1; return;
} /* marklocalaffix */
static void a_1105(a_word a_F1,a_word a_F2){ /* startlocalaffixcheck+>a+>a */
a_word a_P[1];
if(!a_equal(a_F1,0)){ goto a_G3;}
a_1055=0; return;
a_G3:a_1055=1;
a_subtr(to_LIST(a_1445)->aupb,a_F1,a_1076);
a_incr(a_1076);
a_G6:if(a_more(a_F1,a_F2)){ return;}
a_P[0]=0;a_1085(1,a_P);
a_incr(a_F1); goto a_G6;
} /* startlocalaffixcheck */
static void a_1103(void){ /* skiptocomma */
a_word a_L1;
a_G1:if(!a_equal(16777412,a_1459)){ goto a_G3;}
a_1466(); return;
a_G3:if(!a_equal(16777479,a_1459)){ goto a_G7;}
a_L1=a_1460;
a_1466();
a_1079(a_L1); goto a_G1;
a_G7:if(!a_equal(16777448,a_1459)){ goto a_G10;}
a_1466();
a_1072=1; goto a_G1;
a_G10:if(!a_equal(16777486,a_1459)){ goto a_G13;}
a_1466();
a_1420(a_1001,2130705124); return;
a_G13:a_1466(); goto a_G1;
} /* skiptocomma */
static void a_1104(a_word a_A[1]){ /* skiptolabel+a> */

a_G1:if(!a_equal(16777433,a_1459)){ goto a_G4;}
a_A[0]=a_1460;
a_1466(); return;
a_G4:if(!a_equal(16777486,a_1459)){ goto a_G7;}
a_1466();
a_1420(a_1001,2130705119); return;
a_G7:a_1466(); goto a_G1;
} /* skiptolabel */
static a_word a_1074(void){ /* islimit */

if(!a_equal(16777231,a_1459)){ goto a_G3;}
a_G2:a_1466(); return 1;
a_G3:if(a_equal(16777269,a_1459)){ goto a_G2;}
if(a_equal(16777291,a_1459)){ goto a_G2;}
if(a_equal(16777295,a_1459)){ goto a_G2;}
if(!a_equal(16777299,a_1459)){ return 0;} goto a_G2;
} /* islimit */
static void a_1100(void){ /* skiplist */

if(!a_equal(16777475,a_1459)){ goto a_G3;}
a_G2:a_1466(); return;
a_G3:if(!a_equal(16777471,a_1459)){ goto a_G5;}
 goto a_G2;
a_G5:a_1420(a_1001,2130705109); return;
} /* skiplist */
static void a_1099(void){ /* skipaffix */
a_word a_L1;
if(!a_equal(16777409,a_1459)){ goto a_G3;}
a_1466();
a_G3:if(!a_equal(16777475,a_1459)){ goto a_G5;}
a_G4:a_1466(); return;
a_G5:if(!a_equal(16777479,a_1459)){ goto a_G9;}
a_L1=a_1460;
a_1466();
a_1079(a_L1); return;
a_G9:if(a_equal(16777471,a_1459)){ goto a_G4;}
if(a_equal(16777424,a_1459)){ goto a_G4;}
if(a_equal(16777459,a_1459)){ goto a_G4;}
if(!a_1074()){ goto a_G14;}
a_1100(); return;
a_G14:if(!a_equal(16777448,a_1459)){ goto a_G25;}
a_1466();
a_1072=1;
a_1100();
a_1099();
if(!a_equal(16777403,a_1459)){ goto a_G22;}

a_1466(); goto a_G23;
a_G22:a_1420(a_1001,2130705109); return;
a_G23:if(!a_equal(16777455,a_1459)){ goto a_G22;}
 goto a_G4;
a_G25:a_1420(a_1001,2130705114); return;
} /* skipaffix */
static void a_1085(a_word a_C,a_word *a_V){ /* pushBUFFER+@+>a */

a_G1:{register a_word *a_r1=a_extension(a_1445,1);a_r1[0]=a_V[0];to_LIST(a_1445)->aupb+=1;}
if(a_C>1){a_C--;a_V+=1; goto a_G1;}  return;
} /* pushBUFFER */
static void a_1108(a_word a_F1){ /* storelist+>a */
a_word a_L2;a_word a_P[3];
if(!a_equal(16777475,a_1459)){ goto a_G5;}
a_L2=a_1460;
a_1466();
a_P[0]=a_F1;a_P[1]=16777475;a_P[2]=a_L2;a_1085(3,a_P); return;
a_G5:if(!a_equal(16777471,a_1459)){ goto a_G8;}
a_L2=a_1460;
a_1466(); goto a_G9;
a_G8:a_1420(a_1001,2130705109); return;
a_G9:a_P[0]=a_L2;a_1068(a_P);a_L2=a_P[0];
a_P[0]=a_F1;a_P[1]=16777471;a_P[2]=a_L2;a_1085(3,a_P); return;
} /* storelist */
static void a_1107(void){ /* storelimit */

if(!a_equal(16777269,a_1459)){ goto a_G4;}
a_1466();
a_1108(16777269); return;
a_G4:if(!a_equal(16777291,a_1459)){ goto a_G7;}
a_1466();
a_1108(16777291); return;
a_G7:if(!a_equal(16777295,a_1459)){ goto a_G10;}
a_1466();
a_1108(16777295); return;
a_G10:if(!a_equal(16777299,a_1459)){ goto a_G13;}
a_1466();
a_1108(16777299); return;
a_G13:if(!a_equal(16777231,a_1459)){ goto a_G16;}

a_1466(); goto a_G17;
a_G16:a_1420(a_1001,2130705109); return;
a_G17:a_1108(16777231); return;
} /* storelimit */
static void a_1106(void){ /* storeaffix */
a_word a_L1;a_word a_P[2];
if(!a_equal(16777475,a_1459)){ goto a_G5;}
a_L1=a_1460;
a_1466();
a_P[0]=16777475;a_P[1]=a_L1;a_1085(2,a_P); return;
a_G5:if(!a_equal(16777479,a_1459)){ goto a_G9;}
a_L1=a_1460;
a_1466();
a_P[0]=16777479;a_P[1]=a_L1;a_1085(2,a_P); return;
a_G9:if(!a_equal(16777471,a_1459)){ goto a_G14;}
a_L1=a_1460;
a_1466();
a_P[0]=a_L1;a_1068(a_P);a_L1=a_P[0];
a_P[0]=16777471;a_P[1]=a_L1;a_1085(2,a_P); return;
a_G14:if(!a_equal(16777459,a_1459)){ goto a_G18;}
a_L1=a_1460;
a_1466();
a_P[0]=16777459;a_P[1]=a_L1;a_1085(2,a_P); return;
a_G18:if(!a_equal(16777448,a_1459)){ goto a_G30;}
a_1466();
a_1108(16777448);
a_1106();
if(!a_equal(16777403,a_1459)){ goto a_G25;}

a_1466(); goto a_G26;
a_G25:a_1420(a_1001,2130705109); return;
a_G26:if(!a_equal(16777455,a_1459)){ goto a_G25;}
a_L1=a_1460;
a_1466();
a_P[0]=16777403;a_P[1]=a_L1;a_1085(2,a_P); return;
a_G30:a_1107(); return;
} /* storeaffix */
static void a_1109(a_word a_A[1]){ /* storeruleaffix+a> */
a_word a_L2;a_word a_P[2];
if(!a_equal(16777409,a_1459)){ goto a_G6;}
a_1466();
a_A[0]=16777409;
a_P[0]=16777409;a_1085(1,a_P);
a_G5:a_1106(); return;
a_G6:if(!a_equal(16777424,a_1459)){ goto a_G10;}
a_1466();
a_A[0]=16777424;
a_P[0]=16777424;a_1085(1,a_P); return;
a_G10:if(!a_equal(16777397,a_1459)){ goto a_G18;}
a_1466();
a_A[0]=16777397;
if(!a_equal(16777455,a_1459)){ goto a_G16;}
a_L2=a_1460;
a_1466(); goto a_G17;
a_G16:a_L2=0;
a_G17:a_P[0]=16777397;a_P[1]=a_L2;a_1085(2,a_P); return;
a_G18:a_A[0]=0; goto a_G5;
} /* storeruleaffix */
static void a_1110(void){ /* storeruleaffixes */
a_word a_L1;a_word a_P[2];
a_G1:{ if(a_1459==16777479){ goto a_G2;}
 if(a_1459==16777471){ goto a_G5;}
 if(a_1459==16777475||a_1459==16777459||a_1459==16777455){ goto a_G3;}
 if(a_1459==16777448){ goto a_G6;}
 if(a_1459==16777269||a_1459==16777291||a_1459==16777295||a_1459==16777299||a_1459==16777231||a_1459==16777424||a_1459==16777403||a_1459==16777397||a_1459==16777409){  goto a_G11;}
  goto a_G12;}
a_G2:a_1079(a_1460);
a_G3:a_P[0]=a_1459;a_P[1]=a_1460;a_1085(2,a_P);
a_G4:a_1466(); goto a_G1;
a_G5:a_P[0]=a_1460;a_1068(a_P);a_1460=a_P[0]; goto a_G3;
a_G6:a_P[0]=a_1459;a_1085(1,a_P);
a_1466();
a_booland(to_LIST(a_1041)->offset[a_1112-4],8,a_L1);
if(a_noteq(a_L1,0)){ goto a_G1;}
a_1072=1; goto a_G1;
a_G11:a_P[0]=a_1459;a_1085(1,a_P); goto a_G4;
a_G12:if(!a_equal(16777433,a_1459)){ goto a_G15;}
to_LIST(a_1041)->offset[a_1112-1]=a_1460;
a_1466(); goto a_G16;
a_G15:a_1420(a_1001,2130705109); return;
a_G16:if(!a_equal(16777433,a_1459)){ goto a_G15;}
to_LIST(a_1041)->offset[a_1112]=a_1460;
a_1466();
if(!a_equal(16777412,a_1459)){ goto a_G15;}

a_1466(); return;
} /* storeruleaffixes */
static void a_1053(void){ /* computeruleaffixhash */
a_word a_L1;a_word a_P[1];
a_L1=to_LIST(a_1445)->aupb;
a_1110();
a_blockhash(a_1445,a_L1,a_P);to_LIST(a_1041)->offset[a_1112-5]=a_P[0];
a_unstackto(a_1445,a_L1); return;
} /* computeruleaffixhash */
static a_word a_1083(a_word a_F1){ /* nodewithsamehash+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;
a_booland(to_LIST(a_1041)->offset[a_F1-4],8,a_L5);
if(a_noteq(a_L5,0)){ return 0;}
a_L2=to_LIST(a_1041)->offset[a_F1-5];
a_L3=to_LIST(a_1041)->offset[a_F1-3];
a_L4=to_LIST(a_1041)->alwb;
a_G6:if(a_more(a_L4,to_LIST(a_1041)->aupb)){ return 0;}
a_booland(to_LIST(a_1041)->offset[a_L4-4],8,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G10;}
a_G9:a_next(a_1041,a_L4); goto a_G6;
a_G10:if(!a_noteq(a_L4,a_F1)){ goto a_G9;}
a_booland(to_LIST(a_1041)->offset[a_L4-4],1,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G9;}
if(!a_equal(to_LIST(a_1041)->offset[a_L4-5],a_L2)){ goto a_G9;}
if(a_equal(to_LIST(a_1041)->offset[a_L4-3],a_L3)){ return 1;} goto a_G9;
} /* nodewithsamehash */
static a_word a_1082(void){ /* nodehashdifferent */
a_word a_L1;a_word a_L2;
a_L1=to_LIST(a_1041)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1041)->aupb)){ return 1;}
a_booland(to_LIST(a_1041)->offset[a_L1-4],1,a_L2);
if(!a_noteq(a_L2,0)){ goto a_G6;}
if(a_1083(a_L1)){ return 0;}
a_G6:a_next(a_1041,a_L1); goto a_G2;
} /* nodehashdifferent */
static a_word a_1056(a_word a_F1,a_word a_F2){ /* equalaffixes+>a+>a */

a_G1:if(!a_equal(to_LIST(a_1445)->offset[a_F1],to_LIST(a_1445)->offset[a_F2])){ return 0;}
if(a_equal(to_LIST(a_1445)->offset[a_F1],16777412)){ return 1;}
a_decr(a_F1);
a_decr(a_F2); goto a_G1;
} /* equalaffixes */
static void a_1051(a_word a_F1){ /* comparetostoredaffixes+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;
a_L3=to_LIST(a_1041)->offset[a_1112-5];
a_L4=1;
a_L2=to_LIST(a_1041)->alwb;
a_G4:if(a_mreq(a_L2,a_1112)){ goto a_G13;}
a_booland(to_LIST(a_1041)->offset[a_L2-4],4096,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G12;}
if(!a_equal(to_LIST(a_1041)->offset[a_L2-5],a_L3)){ goto a_G12;}
if(!a_1056(to_LIST(a_1041)->offset[a_1112-2],to_LIST(a_1041)->offset[a_L2-2])){ goto a_G12;}
a_L4=0;
to_LIST(a_1041)->offset[a_1112-2]=a_L2;
a_1097(8192); goto a_G13;
a_G12:a_next(a_1041,a_L2); goto a_G4;
a_G13:if(a_equal(a_L4,0)){ goto a_G21;}
a_L4=0;
a_G15:a_next(a_1041,a_L2);
if(a_more(a_L2,to_LIST(a_1041)->aupb)){ goto a_G21;}
a_booland(to_LIST(a_1041)->offset[a_L2-4],1,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G15;}
if(!a_equal(to_LIST(a_1041)->offset[a_L2-5],a_L3)){ goto a_G15;}
a_L4=1;
a_G21:if(!a_equal(a_L4,0)){ goto a_G23;}
a_unstackto(a_1445,a_F1); return;
a_G23:a_1097(4096); return;
} /* comparetostoredaffixes */
static void a_1048(void){ /* checknodehash */
a_word a_L1;a_word a_P[1];
if(!a_1083(a_1112)){ goto a_G7;}
a_L1=to_LIST(a_1445)->aupb;
a_P[0]=16777412;a_1085(1,a_P);
a_1110();
to_LIST(a_1041)->offset[a_1112-2]=to_LIST(a_1445)->aupb;
a_1051(a_L1); return;
a_G7:a_1103(); return;
} /* checknodehash */
static a_word a_1092(a_word a_F1,a_word a_F2){ /* samenodes+>a+>a */
a_word a_L3;
a_booland(to_LIST(a_1041)->offset[a_F1-4],1,a_L3);
if(!a_noteq(a_L3,0)){ return 0;}
a_booland(to_LIST(a_1041)->offset[a_F2-4],1,a_L3);
if(!a_noteq(a_L3,0)){ return 0;}
if(!a_equal(to_LIST(a_1041)->offset[a_F1-3],to_LIST(a_1041)->offset[a_F2-3])){ return 0;}
if(!a_equal(to_LIST(a_1041)->offset[a_F1-5],to_LIST(a_1041)->offset[a_F2-5])){ return 0;}
if(!a_equal(to_LIST(a_1041)->offset[a_F1-1],to_LIST(a_1041)->offset[a_F2-1])){ return 0;}
if(!a_equal(to_LIST(a_1041)->offset[a_F1],to_LIST(a_1041)->offset[a_F2])){ return 0;}
a_G9:a_booland(to_LIST(a_1041)->offset[a_F1-4],8192,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G12;}
a_F1=to_LIST(a_1041)->offset[a_F1-2]; goto a_G9;
a_G12:a_booland(to_LIST(a_1041)->offset[a_F2-4],8192,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G15;}
a_F2=to_LIST(a_1041)->offset[a_F2-2]; goto a_G12;
a_G15:if(!a_equal(a_F1,a_F2)){ return 0;} return 1;
} /* samenodes */
static a_word a_1071(a_word a_F1){ /* hasoutaffix+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1333(a_F1,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_mreq(a_L3,a_L2)){ return 0;}
a_1329(a_F1,a_L3,a_P);a_L4=a_P[0];
if(a_equal(a_L4,16777376)){ return 1;}
if(a_equal(a_L4,16777382)){ return 1;}
if(a_equal(a_L4,16777388)){ return 1;}
a_incr(a_L3); goto a_G3;
} /* hasoutaffix */
static a_word a_1075(a_word a_F1){ /* isnodediscarded+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_booland(to_LIST(a_1041)->offset[a_F1-4],1,a_L2);
if(!a_noteq(a_L2,0)){ return 0;}
a_1061(to_LIST(a_1041)->offset[a_F1-1],a_P);a_L2=a_P[0];
a_1061(to_LIST(a_1041)->offset[a_F1],a_P);a_L3=a_P[0];
if(!a_equal(a_L2,a_L3)){ return 0;}
a_F1=to_LIST(a_1041)->offset[a_F1-3];
if(a_1341(a_F1,256)){ return 0;}
if(a_1341(a_F1,1024)){ return 0;}
if(a_1341(a_F1,32768)){ return 0;}
if(!a_1071(a_F1)){ return 1;} return 0;
} /* isnodediscarded */
static void a_1088(a_word a_F1,a_word a_F2){ /* replacelabels+>a+>a */
a_word a_L3;
a_L3=to_LIST(a_1041)->alwb;
a_G2:if(a_more(a_L3,to_LIST(a_1041)->aupb)){ return;}
if(!a_equal(to_LIST(a_1041)->offset[a_L3-1],a_F1)){ goto a_G5;}
to_LIST(a_1041)->offset[a_L3-1]=a_F2;
a_G5:if(!a_equal(to_LIST(a_1041)->offset[a_L3],a_F1)){ goto a_G7;}
to_LIST(a_1041)->offset[a_L3]=a_F2;
a_G7:a_next(a_1041,a_L3); goto a_G2;
} /* replacelabels */
static void a_1089(a_word a_F1,a_word a_F2){ /* replacenlabels+>a+>a */
a_word a_P[1];
to_LIST(a_1041)->offset[a_F2-2]=a_F1;
a_1086(a_F2,16384);
a_1069(a_F1,a_P);a_F1=a_P[0];
a_1069(a_F2,a_P);a_F2=a_P[0];
a_1088(a_F2,a_F1); return;
} /* replacenlabels */
static void a_1058(void){ /* findequalnodes */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_G1:a_L1=0;
a_L2=to_LIST(a_1041)->alwb;
a_G3:if(a_more(a_L2,to_LIST(a_1041)->aupb)){ goto a_G24;}
a_booland(to_LIST(a_1041)->offset[a_L2-4],16384,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G7;}
a_G6:a_next(a_1041,a_L2); goto a_G3;
a_G7:a_booland(to_LIST(a_1041)->offset[a_L2-4],8,a_L4);
if(a_noteq(a_L4,0)){ goto a_G6;}
if(!a_1075(a_L2)){ goto a_G14;}
a_1086(a_L2,8);
a_1069(a_L2,a_P);a_L3=a_P[0];
a_1088(a_L3,to_LIST(a_1041)->offset[a_L2]);
a_L1=1; goto a_G6;
a_G14:a_L3=a_L2;
a_G15:a_next(a_1041,a_L3);
if(a_more(a_L3,to_LIST(a_1041)->aupb)){ goto a_G6;}
a_booland(to_LIST(a_1041)->offset[a_L3-4],16384,a_L4);
if(a_noteq(a_L4,0)){ goto a_G15;}
a_booland(to_LIST(a_1041)->offset[a_L3-4],8,a_L4);
if(a_noteq(a_L4,0)){ goto a_G15;}
if(!a_1092(a_L2,a_L3)){ goto a_G15;}
a_L1=1;
a_1089(a_L2,a_L3); goto a_G15;
a_G24:if(a_equal(a_L1,0)){ return;}
if(a_is(a_1077)){ return;} goto a_G1;
} /* findequalnodes */
static void a_1084(void){ /* omitemptynodes */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
a_L1=to_LIST(a_1041)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1041)->aupb)){ return;}
a_booland(to_LIST(a_1041)->offset[a_L1-4],8,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G9;}
a_1069(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,to_LIST(a_1041)->offset[a_L1])){ goto a_G8;}
a_1077=to_LIST(a_1041)->offset[a_L1-3]; goto a_G9;
a_G8:a_1088(a_L2,to_LIST(a_1041)->offset[a_L1]);
a_G9:a_next(a_1041,a_L1); goto a_G2;
} /* omitemptynodes */
static void a_1061(a_word a_F1,a_word a_A[1]){ /* findreallabel+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[1];
if(!a_lseq(a_F1,0)){ goto a_G3;}
a_G2:a_A[0]=a_F1; return;
a_G3:if(a_is(a_1077)){ goto a_G2;}
a_1073(a_F1,a_P);a_F1=a_P[0];
a_listlength(a_1041,a_L4);
a_L3=0;
a_G7:a_booland(to_LIST(a_1041)->offset[a_F1-4],16384,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G10;}
a_F1=to_LIST(a_1041)->offset[a_F1-2]; goto a_G7;
a_G10:if(!a_more(a_L3,a_L4)){ goto a_G13;}
a_1049(a_F1,8);
a_1077=to_LIST(a_1041)->offset[a_F1-3]; goto a_G17;
a_G13:a_booland(to_LIST(a_1041)->offset[a_F1-4],8,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G17;}
a_1073(to_LIST(a_1041)->offset[a_F1],a_P);a_F1=a_P[0];
a_incr(a_L3); goto a_G7;
a_G17:a_1069(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* findreallabel */
static void a_1060(a_word a_A[1]){ /* findnextnode+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_A[0]=0;
a_L2=a_1112;
a_G3:a_next(a_1041,a_L2);
if(a_more(a_L2,to_LIST(a_1041)->aupb)){ return;}
a_booland(to_LIST(a_1041)->offset[a_L2-4],16384,a_L3);
if(a_noteq(a_L3,0)){ goto a_G3;}
a_booland(to_LIST(a_1041)->offset[a_L2-4],8,a_L3);
if(a_noteq(a_L3,0)){ goto a_G3;}
a_1069(a_L2,a_P);a_A[0]=a_P[0]; return;
} /* findnextnode */
static void a_1080(a_word a_F1,a_word a_F2){ /* marknode+>a+>a */
a_word a_P[1];
a_1061(a_F2,a_P);a_F2=a_P[0];
if(a_lseq(a_F2,0)){ return;}
if(a_equal(a_F2,a_F1)){ return;}
a_1073(a_F2,a_P);a_F2=a_P[0];
a_1086(a_F2,16);
a_1070=1; return;
} /* marknode */
static void a_1090(void){ /* rulelabel */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_booland(to_LIST(a_1041)->offset[a_1112-4],16384,a_L2);
if(a_noteq(a_L2,0)){ return;}
a_booland(to_LIST(a_1041)->offset[a_1112-4],8,a_L2);
if(a_noteq(a_L2,0)){ return;}
a_1060(a_P);a_L1=a_P[0];
a_1080(a_L1,to_LIST(a_1041)->offset[a_1112-1]);
a_1080(a_L1,to_LIST(a_1041)->offset[a_1112]); return;
} /* rulelabel */
static void a_1045(void){ /* arealabels */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1060(a_P);a_L1=a_P[0];
a_L2=0;a_L3=0;
a_G3:if(!a_equal(16777220,a_1459)){ goto a_G8;}
a_1466();
a_1080(0,a_L2);
a_L2=a_L3;
a_1104(a_P);a_L3=a_P[0]; goto a_G3;
a_G8:a_booland(to_LIST(a_1041)->offset[a_1112-4],2048,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G12;}
a_1080(a_L1,a_L2);
a_G11:a_1080(a_L1,a_L3); return;
a_G12:a_1080(0,a_L2); goto a_G11;
} /* arealabels */
static void a_1057(void){ /* extensionlabel */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_1060(a_P);a_L1=a_P[0];
a_1104(a_P);a_L2=a_P[0];
a_1080(a_L1,a_L2); return;
} /* extensionlabel */
static void a_1066(void){ /* generatelabel */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
a_1044();
a_booland(to_LIST(a_1041)->offset[a_1112-4],16384,a_L3);
if(a_noteq(a_L3,0)){ return;}
a_booland(to_LIST(a_1041)->offset[a_1112-4],8,a_L3);
if(a_noteq(a_L3,0)){ return;}
a_1060(a_P);a_L2=a_P[0];
a_booland(to_LIST(a_1041)->offset[a_1112-4],16,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G10;}
a_1069(a_1112,a_P);a_L1=a_P[0]; goto a_G11;
a_G10:a_L1=0;
a_G11:a_1123(a_L1,a_L2); return;
} /* generatelabel */
static void a_1067(void){ /* generaterulecall */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_L7;a_word a_P[1];
if(!a_equal(16777471,a_1459)){ goto a_G4;}

a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130705109); return;
a_G5:if(!a_equal(16777455,a_1459)){ goto a_G4;}

a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G4;}

a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G4;}

a_1466();
a_L7=to_LIST(a_1445)->aupb;
a_L2=0;a_L5=0;a_L6=0;
a_G16:if(!a_equal(16777433,a_1459)){ goto a_G21;}
a_1466();
if(!a_equal(16777433,a_1459)){ goto a_G4;}

a_1466(); goto a_G30;
a_G21:a_1109(a_P);a_L1=a_P[0];
a_P[0]=16777436;a_1085(1,a_P);
a_incr(a_L2);
if(!a_is(a_L5)){ goto a_G26;}
a_incr(a_L5);
a_G26:if(!a_equal(a_L1,16777397)){ goto a_G16;}
if(!a_is(a_L5)){ goto a_G29;}
a_L6=1; goto a_G16;
a_G29:a_L5=1; goto a_G16;
a_G30:a_1061(to_LIST(a_1041)->offset[a_1112-1],a_P);a_L3=a_P[0];
a_1061(to_LIST(a_1041)->offset[a_1112],a_P);a_L4=a_P[0];
a_1125(to_LIST(a_1041)->offset[a_1112-3],a_L2,a_L3,a_L4,a_L5,a_L6,a_L7);
a_unstackto(a_1445,a_L7); return;
} /* generaterulecall */
static void a_1065(void){ /* generateextension */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[2];
a_L1=to_LIST(a_1445)->aupb;
a_1108(0);
if(!a_equal(16777455,a_1459)){ goto a_G6;}
a_L2=a_1460;
a_1466(); goto a_G7;
a_G6:a_1420(a_1001,2130705109); return;
a_G7:a_add(a_L1,1,a_L3);
to_LIST(a_1445)->offset[a_L3]=a_L2;
a_P[0]=0;a_1085(1,a_P);
a_L3=to_LIST(a_1445)->aupb;
a_G11:a_1106();
a_P[0]=16777436;a_1085(1,a_P);
a_G13:if(!a_equal(16777288,a_1459)){ goto a_G19;}
a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G6;}
a_L2=a_1460;
a_1466();
a_P[0]=a_L2;a_1085(1,a_P); goto a_G13;
a_G19:if(!a_equal(16777433,a_1459)){ goto a_G25;}
a_L4=a_1460;
a_1466();
a_1061(a_L4,a_P);a_L4=a_P[0];
a_P[0]=-1;a_1085(1,a_P);
a_1119(a_L1,a_L4); goto a_G27;
a_G25:a_P[0]=-1;a_P[1]=0;a_1085(2,a_P);
{register a_word a_r1=to_LIST(a_1445)->aupb;to_LIST(a_1445)->offset[a_L3]=a_r1;a_L3=a_r1;} goto a_G11;
a_G27:a_unstackto(a_1445,a_L1); return;
} /* generateextension */
static void a_1062(void){ /* generatearea */
a_word a_L1;a_word a_L2;a_word a_P[2];
a_G1:a_1087(a_P);a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=a_L1;a_P[1]=a_L2;a_1085(2,a_P);
if(!a_equal(16777442,a_1459)){ return;}
a_1466();
a_P[0]=16777442;a_1085(1,a_P); goto a_G1;
} /* generatearea */
static void a_1063(void){ /* generateareas */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[3];
a_L1=0;
if(!a_equal(16777220,a_1459)){ goto a_G5;}

a_1466(); goto a_G6;
a_G5:a_1420(a_1001,2130705109); return;
a_G6:if(!a_equal(16777455,a_1459)){ goto a_G5;}

a_1466();
a_P[0]=0;a_1085(1,a_P);
if(a_equal(a_L1,0)){ goto a_G12;}
to_LIST(a_1445)->offset[a_L1]=to_LIST(a_1445)->aupb;
a_G12:a_L1=to_LIST(a_1445)->aupb;
a_P[0]=0;a_1085(1,a_P);
a_L2=to_LIST(a_1445)->aupb;
a_1062();
if(!a_equal(16777433,a_1459)){ goto a_G5;}
a_L3=a_1460;
a_1466();
a_1061(a_L3,a_P);to_LIST(a_1445)->offset[a_L2]=a_P[0];
if(!a_equal(16777220,a_1459)){ goto a_G23;}
a_1466();
a_P[0]=16777436;a_1085(1,a_P); goto a_G6;
a_G23:a_booland(to_LIST(a_1041)->offset[a_1112-4],2048,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G27;}
a_unstackto(a_1445,a_L2);
a_P[0]=a_1019;a_P[1]=a_1018;a_P[2]=16777436;a_1085(3,a_P); return;
a_G27:a_P[0]=16777436;a_1085(1,a_P); return;
} /* generateareas */
static void a_1064(void){ /* generatebox */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_L1=to_LIST(a_1445)->aupb;
a_1106();
a_P[0]=16777436;a_1085(1,a_P);
a_L2=to_LIST(a_1445)->aupb;
a_1063();
a_1118(a_L1,a_L2);
a_unstackto(a_1445,a_L1); return;
} /* generatebox */
static void a_1093(void){ /* scani */

a_G1:if(!a_equal(16777227,a_1459)){ goto a_G11;}
a_1466();
a_1044();
a_1097(4);
a_1099();
a_1047();
if(!a_equal(16777412,a_1459)){ goto a_G10;}

a_1466(); goto a_G1;
a_G10:a_1420(a_1001,2130705109); return;
a_G11:if(!a_equal(16777241,a_1459)){ goto a_G16;}
a_1466();
a_1044();
a_1097(2);
a_1103(); goto a_G1;
a_G16:if(!a_equal(16777281,a_1459)){ goto a_G22;}
a_1466();
a_1044();
a_1097(1);
a_1098();
a_1053(); goto a_G1;
a_G22:if(!a_equal(16777439,a_1459)){ goto a_G10;}

a_1466(); return;
} /* scani */
static void a_1094(void){ /* scanii */
a_word a_L1;
a_L1=to_LIST(a_1445)->aupb;
a_G2:if(!a_equal(16777227,a_1459)){ goto a_G6;}
a_G3:a_1466();
a_1044();
a_1103(); goto a_G2;
a_G6:if(a_equal(16777241,a_1459)){ goto a_G3;}
if(!a_equal(16777281,a_1459)){ goto a_G12;}
a_1466();
a_1044();
a_1102();
a_1048(); goto a_G2;
a_G12:if(!a_equal(16777439,a_1459)){ goto a_G15;}

a_1466(); goto a_G16;
a_G15:a_1420(a_1001,2130705109); return;
a_G16:a_unstackto(a_1445,a_L1); return;
} /* scanii */
static void a_1095(void){ /* scaniii */

a_G1:if(!a_equal(16777227,a_1459)){ goto a_G10;}
a_1466();
a_1044();
a_1099();
a_1045();
a_G6:if(!a_equal(16777412,a_1459)){ goto a_G9;}

a_1466(); goto a_G1;
a_G9:a_1420(a_1001,2130705109); return;
a_G10:if(!a_equal(16777241,a_1459)){ goto a_G14;}
a_1466();
a_1044();
a_1057(); goto a_G6;
a_G14:if(!a_equal(16777281,a_1459)){ goto a_G19;}
a_1466();
a_1044();
a_1090();
a_1103(); goto a_G1;
a_G19:if(!a_equal(16777439,a_1459)){ goto a_G9;}

a_1466(); return;
} /* scaniii */
static void a_1096(void){ /* scaniv */
a_word a_L1;
a_G1:if(!a_equal(16777227,a_1459)){ goto a_G9;}
a_1466();
a_1066();
a_1064();
a_G5:if(!a_equal(16777412,a_1459)){ goto a_G8;}

a_1466(); goto a_G1;
a_G8:a_1420(a_1001,2130705109); return;
a_G9:if(!a_equal(16777241,a_1459)){ goto a_G13;}
a_1466();
a_1066();
a_1065(); goto a_G5;
a_G13:if(!a_equal(16777281,a_1459)){ goto a_G22;}
a_1466();
a_1066();
a_booland(to_LIST(a_1041)->offset[a_1112-4],16384,a_L1);
if(!a_noteq(a_L1,0)){ goto a_G19;}
a_G18:a_1103(); goto a_G1;
a_G19:a_booland(to_LIST(a_1041)->offset[a_1112-4],8,a_L1);
if(a_noteq(a_L1,0)){ goto a_G18;}
a_1067(); goto a_G5;
a_G22:if(!a_equal(16777439,a_1459)){ goto a_G8;}

a_1466(); return;
} /* scaniv */
static void a_1078(void){ /* makerule */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[4];
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130705109); return;
a_G5:if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L3=a_1460;
a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L4=a_1460;
a_1466();
if(!a_1341(a_L1,16384)){ goto a_G13;}
a_1101(); return;
a_G13:a_1054();
a_1072=0;a_1070=0;
if(!a_1341(a_L1,16777216)){ goto a_G17;}
a_1111=1; goto a_G18;
a_G17:a_1111=0;
a_G18:a_L2=to_LIST(a_1445)->aupb;
a_1050();
a_1105(a_L3,a_L4);
a_1476();
a_1112=0;
a_1093();
a_1055=0;
a_1077=0;
a_1084();
if(a_is(a_1111)){ goto a_G30;}
if(!a_1341(a_L1,67108864)){ goto a_G30;}
a_1111=a_1072;
a_G30:if(a_1082()){ goto a_G34;}
a_1475();
a_1112=0;
a_1094();
a_G34:a_1058();
a_1212(a_L1,a_1038,a_1039,a_1040,a_1111,a_L3,a_L4,a_1076);
a_unstackto(a_1445,a_L2);
a_1475();
a_1112=0;
a_1095();
if(!a_is(a_1077)){ goto a_G42;}
a_P[0]=2019445226;a_P[1]=to_LIST(a_1303)->offset[a_L1-4];a_P[2]=to_LIST(a_1303)->offset[a_L1-3];a_P[3]=to_LIST(a_1303)->offset[a_1077-4];a_1421(4,a_P); return;
a_G42:a_1218(a_1070);
a_1475();
a_1112=0;
a_1096();
a_1213(a_1070); return;
} /* makerule */
static void a_1183(void){ /* opentarget */
a_word a_L1;a_word a_P[3];
a_1395();
if(!a_openfile(a_1115,119,a_1449,to_LIST(a_1449)->aupb)){ goto a_G5;}
a_unstackstring(a_1449);
a_1221=1; return;
a_G5:a_getfileerror(a_1115,a_L1);
a_P[0]=2019445240;a_P[1]=to_LIST(a_1449)->aupb;a_P[2]=a_L1;a_1421(3,a_P); return;
} /* opentarget */
static void a_1142(void){ /* closetarget */

if(a_equal(a_1221,0)){ return;}
a_closefile(a_1115);
a_1221=0; return;
} /* closetarget */
static void a_1154(void){ /* deletetarget */

if(a_equal(a_1221,0)){ return;}
a_1142();
a_1395();
a_unlinkfile(a_1449,to_LIST(a_1449)->aupb);
a_unstackstring(a_1449); return;
} /* deletetarget */
static void a_1191(a_word a_F1){ /* printint+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G8;}
a_putchar(a_1115,40);
a_putchar(a_1115,45);
a_1191(2147483647);
a_putchar(a_1115,45);
a_putchar(a_1115,49);
a_putchar(a_1115,41); return;
a_G8:if(!a_less(a_F1,0)){ goto a_G11;}
a_putchar(a_1115,45);
a_getabs(a_F1,a_F1);
a_G11:a_1192(a_F1,48); return;
} /* printint */
static void a_1192(a_word a_F1,a_word a_F2){ /* printint1+>a+>a */
a_word a_L3;a_word a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1192(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_putchar(a_1115,a_L4); return;
} /* printint1 */
static void a_1178(a_word a_F1){ /* localargument+>a */

a_putchar(a_1115,97);
a_putchar(a_1115,95);
a_putchar(a_1115,76);
a_1191(a_F1); return;
} /* localargument */
static void a_1193(a_word a_F1,a_word a_F2){ /* printintindex+>a+>a */

a_putchar(a_1115,97);
a_putchar(a_1115,95);
a_putchar(a_1115,a_F1);
a_putchar(a_1115,91);
a_1191(a_F2);
a_putchar(a_1115,93); return;
} /* printintindex */
static void a_1164(a_word a_F1){ /* formalargument+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_L2=0;a_L4=0;
a_G2:a_1329(a_1224,a_L2,a_P);a_L3=a_P[0];
a_incr(a_L2);
if(a_equal(a_L3,16777376)){ goto a_G6;}
if(!a_equal(a_L3,16777382)){ goto a_G9;}
a_G6:if(!a_equal(a_L2,a_F1)){ goto a_G8;}
a_1193(65,a_L4); return;
a_G8:a_incr(a_L4); goto a_G2;
a_G9:if(!a_equal(a_L3,16777388)){ goto a_G21;}
a_incr(a_L2);
a_subtr(a_F1,a_L2,a_L2);
if(!a_less(a_L2,0)){ goto a_G16;}
a_putchar(a_1115,97);
a_putchar(a_1115,95);
a_putchar(a_1115,67); return;
a_G16:if(!a_equal(a_L2,0)){ goto a_G18;}
a_1488(a_1115,a_1001,2130706108); return;
a_G18:a_1488(a_1115,a_1001,2130706103);
a_1191(a_L2);
a_putchar(a_1115,93); return;
a_G21:if(!a_equal(a_L2,a_F1)){ goto a_G2;}
a_putchar(a_1115,97);
a_putchar(a_1115,95);
a_putchar(a_1115,70);
a_1191(a_F1); return;
} /* formalargument */
static void a_1189(a_word a_F1){ /* printexternalrepr+>a */

{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(a_r1==16777304||a_r1==16777309){ goto a_G2;}
 if(!(a_r1==16777349)){ goto a_G3;}
}
a_G2:a_1196(to_LIST(a_1303)->offset[a_F1]); return;
a_G3:a_putchar(a_1115,97);
a_putchar(a_1115,95);
a_1191(to_LIST(a_1303)->offset[a_F1]); return;
} /* printexternalrepr */
static void a_1197(a_word a_F1){ /* printrepr+>a */

if(!a_was(a_1303,a_F1)){ goto a_G9;}
if(!a_1341(a_F1,16)){ goto a_G4;}
a_1189(a_F1); return;
a_G4:{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(!(a_r1==16777304||a_r1==16777335)){ goto a_G6;}
}
a_1195(to_LIST(a_1303)->offset[a_F1]); return;
a_G6:a_putchar(a_1115,97);
a_putchar(a_1115,95);
a_1191(to_LIST(a_1303)->offset[a_F1]); return;
a_G9:a_1196(a_F1); return;
} /* printrepr */
static void a_1190(a_word a_F1){ /* printgoto+>a */

{ if(a_F1==0||a_F1==-1){ goto a_G2;}
 if(a_F1==-2){  goto a_G5;}
  goto a_G6;}
a_G2:if(!a_1341(a_1224,512)){ goto a_G4;}
a_1488(a_1115,a_1001,2130706098); return;
a_G4:a_1488(a_1115,a_1001,2130706093); return;
a_G5:a_1488(a_1115,a_1001,2130706088); return;
a_G6:a_1488(a_1115,a_1001,2130706083);
a_1191(a_F1);
a_1488(a_1115,a_1001,2130706079); return;
} /* printgoto */
static void a_1188(a_word a_F1){ /* printGOTO+>a */

if(!a_equal(a_F1,a_1181)){ goto a_G3;}
if(a_noteq(a_1181,0)){ return;}
a_G3:a_1190(a_F1); return;
} /* printGOTO */
static void a_1187(a_word a_F1){ /* printBUFFER+>a */

{register a_word a_r1=to_LIST(a_1445)->offset[a_F1];
 if(a_r1==16777471){ goto a_G2;}
 if(a_r1==16777455){ goto a_G4;}
 if(a_r1==16777479){ goto a_G6;}
 if(a_r1==16777459){ goto a_G8;}
 if(a_r1==16777475){  goto a_G10;}
  goto a_G12;}
a_G2:a_incr(a_F1);
a_1197(to_LIST(a_1445)->offset[a_F1]); return;
a_G4:a_incr(a_F1);
a_1191(to_LIST(a_1445)->offset[a_F1]); return;
a_G6:a_incr(a_F1);
a_1178(to_LIST(a_1445)->offset[a_F1]); return;
a_G8:a_incr(a_F1);
a_1195(to_LIST(a_1445)->offset[a_F1]); return;
a_G10:a_incr(a_F1);
a_1164(to_LIST(a_1445)->offset[a_F1]); return;
a_G12:a_1425(a_1001,2130706074); return;
} /* printBUFFER */
static void a_1196(a_word a_F1){ /* printptr+>a */
a_word a_P[1];
a_G1:if(!a_was(a_1303,a_F1)){ goto a_G3;}
a_F1=to_LIST(a_1303)->offset[a_F1-4]; goto a_G1;
a_G3:if(!a_was(a_1449,a_F1)){ goto a_G6;}
a_1458(a_F1,a_P);a_F1=a_P[0];
a_1488(a_1115,a_1449,a_F1); return;
a_G6:if(!a_was(a_1418,a_F1)){ goto a_G8;}
a_1488(a_1115,a_1418,a_F1); return;
a_G8:if(!a_was(a_1445,a_F1)){ goto a_G10;}
a_1187(a_F1); return;
a_G10:if(!a_equal(a_F1,0)){ goto a_G12;}
a_1488(a_1115,a_1001,2130706069); return;
a_G12:a_1425(a_1001,2130706065); return;
} /* printptr */
static void a_1194(a_word a_F1){ /* printnlptr+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_was(a_1449,a_F1)){ goto a_G15;}
a_1458(a_F1,a_P);a_F1=a_P[0];
{register a_word a_r1=to_LIST(a_1445)->aupb;a_L2=a_r1;a_L3=a_r1;}
a_unpackstring(a_1449,a_F1,a_1445);
a_G5:if(!a_lseq(to_LIST(a_1445)->aupb,a_L3)){ goto a_G7;}
a_unstackto(a_1445,a_L2); return;
a_G7:a_incr(a_L3);
if(!a_noteq(to_LIST(a_1445)->offset[a_L3],37)){ goto a_G10;}
a_G9:a_putchar(a_1115,to_LIST(a_1445)->offset[a_L3]); goto a_G5;
a_G10:a_incr(a_L3);
if(a_less(to_LIST(a_1445)->aupb,a_L3)){ goto a_G5;}
if(!a_equal(to_LIST(a_1445)->offset[a_L3],110)){ goto a_G14;}
a_putchar(a_1115,10); goto a_G5;
a_G14:a_putchar(a_1115,37); goto a_G9;
a_G15:a_1196(a_F1); return;
} /* printnlptr */
static void a_1195(a_word a_F1){ /* printnumber+>a */
a_word a_L2;a_word a_L3;
{register a_word a_r1=to_LIST(a_1445)->aupb;a_L2=a_r1;a_L3=a_r1;}
a_1008(a_F1);
a_G3:if(!a_lseq(to_LIST(a_1445)->aupb,a_L3)){ goto a_G5;}
a_unstackto(a_1445,a_L2); return;
a_G5:a_incr(a_L3);
a_putchar(a_1115,to_LIST(a_1445)->offset[a_L3]); goto a_G3;
} /* printnumber */
static void a_1114(a_word a_F1,a_word a_C,a_word *a_V){ /* T+t[]+@+>a */
a_word a_L2;a_word a_L3;
a_L3=to_LIST(a_1445)->aupb;
a_unpackstring(a_F1,a_V[0],a_1445);
a_add(a_L3,1,a_L2);
a_G4:if(a_less(to_LIST(a_1445)->aupb,a_L2)){ goto a_G29;}
if(!a_noteq(to_LIST(a_1445)->offset[a_L2],37)){ goto a_G8;}
a_G6:a_putchar(a_1115,to_LIST(a_1445)->offset[a_L2]);
a_G7:a_incr(a_L2); goto a_G4;
a_G8:a_incr(a_L2);
if(!a_more(a_L2,to_LIST(a_1445)->aupb)){ goto a_G11;}
a_putchar(a_1115,37); goto a_G29;
a_G11:{register a_word a_r1=to_LIST(a_1445)->offset[a_L2];
 if(a_r1==114){ goto a_G12;}
 if(a_r1==103){ goto a_G15;}
 if(a_r1==71){ goto a_G17;}
 if(a_r1==119){ goto a_G19;}
 if(a_r1==110){ goto a_G20;}
 if(a_r1==100){ goto a_G21;}
 if(a_r1==112){ goto a_G23;}
 if(a_r1==115){ goto a_G25;}
 if(a_r1==116){  goto a_G27;}
  goto a_G6;}
a_G12:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1197(a_V[0]); goto a_G7;
a_G14:a_putchar(a_1115,63); goto a_G7;
a_G15:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1190(a_V[0]); goto a_G7;
a_G17:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1188(a_V[0]); goto a_G7;
a_G19:a_1488(a_1115,a_1001,2130706060); goto a_G7;
a_G20:a_putchar(a_1115,10); goto a_G7;
a_G21:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1191(a_V[0]); goto a_G7;
a_G23:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1196(a_V[0]); goto a_G7;
a_G25:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1194(a_V[0]); goto a_G7;
a_G27:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1195(a_V[0]); goto a_G7;
a_G29:if(a_C<=1){ goto a_G31;} a_C--;a_V+=1;
a_1488(a_1115,a_1001,2130706056);
a_G31:a_unstackto(a_1445,a_L3); return;
} /* T */
static void a_1137(a_word a_A[1]){ /* calltracearg+a> */
a_word a_P[1];
if(!a_equal(a_1136,0)){ goto a_G3;}
a_A[0]=0; return;
a_G3:a_P[0]=2130706052;a_1114(a_1001,1,a_P);
a_A[0]=1; return;
} /* calltracearg */
static void a_1138(a_word a_A[1]){ /* calltracecall+a> */
a_word a_P[1];
if(!a_equal(a_1136,0)){ goto a_G3;}
a_A[0]=0; return;
a_G3:a_P[0]=2130706048;a_1114(a_1001,1,a_P);
a_A[0]=1; return;
} /* calltracecall */
static void a_1127(a_word a_F1){ /* addcallstack+>a */
a_word a_P[2];
if(a_equal(a_1136,0)){ return;}
a_P[0]=2130706044;a_P[1]=to_LIST(a_1303)->offset[a_F1-2];a_1114(a_1001,2,a_P); return;
} /* addcallstack */
static void a_1226(void){ /* usecallstack */

a_1136=1; return;
} /* usecallstack */
static void a_1223(void){ /* targetprelude */
a_word a_L1;a_word a_L2;a_word a_P[3];
a_P[0]=2130706033;a_P[1]=1;a_P[2]=0;a_1114(a_1001,3,a_P);
a_G2:a_1332(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ goto a_G8;}
if(!a_equal(to_LIST(a_1303)->offset[a_L1-4],0)){ goto a_G7;}
if(a_equal(to_LIST(a_1303)->offset[a_L1-5],0)){ goto a_G2;}
a_P[0]=2130706015;a_P[1]=to_LIST(a_1303)->offset[a_L1-5];a_1114(a_1001,2,a_P); goto a_G2;
a_G7:a_P[0]=2130706009;a_P[1]=a_L1;a_P[2]=to_LIST(a_1303)->offset[a_L1-5];a_1114(a_1001,3,a_P); goto a_G2;
a_G8:a_P[0]=2130706003;a_P[1]=155851716;a_1114(a_1001,2,a_P);
a_P[0]=2130705999;a_P[1]=a_1136;a_1114(a_1001,2,a_P);
a_L1=0;
a_G11:a_P[0]=a_L1;if(!a_1331(1,a_P)){ goto a_G13;}a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=2130706003;a_P[1]=a_L2;a_1114(a_1001,2,a_P); goto a_G11;
a_G13:a_P[0]=2130705986;a_P[1]=155851697;a_P[2]=155851704;a_1114(a_1001,3,a_P); return;
} /* targetprelude */
static void a_1222(void){ /* targetpostlude */
a_word a_L1;a_word a_L2;a_word a_P[2];
a_L1=0;
a_G2:a_P[0]=a_L1;if(!a_1331(0,a_P)){ goto a_G4;}a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=2130706003;a_P[1]=a_L2;a_1114(a_1001,2,a_P); goto a_G2;
a_G4:a_P[0]=2130706003;a_P[1]=155851722;a_1114(a_1001,2,a_P); return;
} /* targetpostlude */
static void a_1227(a_word a_F1){ /* vardeclaration+>a */
a_word a_P[4];
if(a_1341(a_F1,16)){ return;}
a_P[0]=2130705972;a_P[1]=a_F1;a_P[2]=to_LIST(a_1303)->offset[a_F1-1];a_P[3]=a_F1;a_1114(a_1001,4,a_P); return;
} /* vardeclaration */
static void a_1176(a_word a_F1,a_word a_F2){ /* listdeclaration+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[8];
if(!a_1341(a_F2,16)){ goto a_G4;}
a_1325(a_F2,a_P);a_L3=a_P[0];
a_P[0]=2130705965;a_P[1]=a_F2;a_P[2]=a_F1;a_P[3]=a_F2;a_P[4]=a_L3;a_1114(a_1001,5,a_P); return;
a_G4:a_1325(a_F2,a_P);a_L3=a_P[0];
a_1336(a_F2,a_P);a_L5=a_P[0];
a_1335(a_F2,a_P);a_L4=a_P[0];
a_1328(a_F2,a_P);a_L6=a_P[0];
a_P[0]=2130705952;a_P[1]=a_F2;a_P[2]=a_F1;a_P[3]=a_F2;a_P[4]=a_L3;a_P[5]=a_L4;a_P[6]=a_L5;a_P[7]=a_L6;a_1114(a_1001,8,a_P); return;
} /* listdeclaration */
static void a_1139(a_word a_F1){ /* charfiledeclaration+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[6];
if(!a_1341(a_F1,16)){ goto a_G3;}
a_P[0]=2130705938;a_P[1]=a_F1;a_P[2]=a_F1;a_1114(a_1001,3,a_P); return;
a_G3:if(!a_1341(a_F1,64)){ goto a_G5;}
a_L2=2; goto a_G6;
a_G5:a_L2=0;
a_G6:if(!a_1341(a_F1,32)){ goto a_G8;}
a_incr(a_L2);
a_G8:a_1327(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
if(!a_1341(a_L3,8)){ goto a_G11;}
a_L3=to_LIST(a_1303)->offset[a_L3];
a_G11:a_P[0]=2130705926;a_P[1]=a_F1;a_P[2]=a_F1;a_P[3]=a_L2;a_P[4]=a_L3;a_P[5]=a_L4;a_1114(a_1001,6,a_P); return;
} /* charfiledeclaration */
static void a_1149(a_word a_F1){ /* datafiledeclaration+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[7];
if(!a_1341(a_F1,16)){ goto a_G3;}
a_P[0]=2130705913;a_P[1]=a_F1;a_P[2]=a_F1;a_1114(a_1001,3,a_P); return;
a_G3:if(!a_1341(a_F1,64)){ goto a_G5;}
a_L2=2; goto a_G6;
a_G5:a_L2=0;
a_G6:if(!a_1341(a_F1,32)){ goto a_G8;}
a_incr(a_L2);
a_G8:a_1327(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1146(a_F1,a_P);a_L5=a_P[0];
if(!a_1341(a_L3,8)){ goto a_G12;}
a_L3=to_LIST(a_1303)->offset[a_L3];
a_G12:a_P[0]=2130705900;a_P[1]=a_F1;a_P[2]=a_F1;a_P[3]=a_L2;a_P[4]=a_L3;a_P[5]=a_L4;a_P[6]=a_L5;a_1114(a_1001,7,a_P); return;
} /* datafiledeclaration */
static void a_1214(a_word a_F1){ /* ruleprototype+>a */
a_word a_P[1];
if(!a_1341(a_F1,12288)){ goto a_G4;}
if(!a_1343(a_F1)){ return;}
a_1228=1; return;
a_G4:if(a_1340(a_F1,a_P)){ return;}
if(a_1341(a_F1,16384)){ return;}
if(!a_1342(a_F1)){ return;}
a_1306(2,a_F1); return;
} /* ruleprototype */
static void a_1210(a_word a_F1){ /* rootprototype+>a */

if(a_equal(to_LIST(a_1303)->offset[a_F1-5],155851727)){ return;}
a_incr(a_1179); return;
} /* rootprototype */
static void a_1147(void){ /* createrulenametable */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[2];
a_P[0]=2130705886;a_1114(a_1001,1,a_P);
a_L1=to_LIST(a_1303)->alwb;
a_L2=0;a_L3=0;
if(!a_is(a_1136)){ goto a_G9;}
if(!a_more(a_1179,0)){ goto a_G9;}
if(!a_is(a_1228)){ goto a_G9;}
a_P[0]=2130705879;a_1114(a_1001,1,a_P);
a_L2=1;a_L3=1;
a_G9:if(a_more(a_L1,to_LIST(a_1303)->aupb)){ goto a_G14;}
if(!a_1341(a_L1,8)){ goto a_G12;}
a_G11:a_next(a_1303,a_L1); goto a_G9;
a_G12:if(!a_equal(to_LIST(a_1303)->offset[a_L1-6],16777349)){ goto a_G11;}
a_P[0]=a_L2;a_P[1]=a_L3;a_1219(a_L1,a_P);a_L2=a_P[0];a_L3=a_P[1]; goto a_G11;
a_G14:a_P[0]=2130705874;a_1114(a_1001,1,a_P); return;
} /* createrulenametable */
static void a_1219(a_word a_F1,a_word a_A[2]){ /* storerulename+>a+>a>+>a> */
a_word a_P[2];
if(a_1341(a_F1,16)){ return;}
if(a_1340(a_F1,a_P)){ return;}
if(a_1341(a_F1,16384)){ return;}
if(a_is(a_1136)){ goto a_G6;}
if(!a_1341(a_F1,117440512)){ return;}
a_G6:a_P[0]=a_A[0];a_1132(a_P);a_A[0]=a_P[0];
a_P[0]=2130705870;a_P[1]=a_F1;a_1114(a_1001,2,a_P);
to_LIST(a_1303)->offset[a_F1-2]=a_A[1];
a_incr(a_A[1]); return;
} /* storerulename */
static void a_1148(void){ /* datadeclaration */
a_word a_L1;a_word a_L2;a_word a_P[2];
a_L1=to_LIST(a_1303)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1303)->aupb)){ goto a_G12;}
if(!a_1341(a_L1,8)){ goto a_G5;}
a_G4:a_next(a_1303,a_L1); goto a_G2;
a_G5:{register a_word a_r1=to_LIST(a_1303)->offset[a_L1-6];
 if(a_r1==16777309||a_r1==16777314){ goto a_G6;}
 if(a_r1==16777318){ goto a_G7;}
 if(a_r1==16777322||a_r1==16777328){ goto a_G8;}
 if(a_r1==16777340){ goto a_G9;}
 if(a_r1==16777345){ goto a_G10;}
 if(a_r1==16777349){  goto a_G11;}
  goto a_G4;}
a_G6:a_1227(a_L1); goto a_G4;
a_G7:a_1176(0,a_L1); goto a_G4;
a_G8:a_1176(1,a_L1); goto a_G4;
a_G9:a_1139(a_L1); goto a_G4;
a_G10:a_1149(a_L1); goto a_G4;
a_G11:a_1214(a_L1); goto a_G4;
a_G12:a_L2=0;
a_G13:a_P[0]=a_L2;if(!a_1331(2,a_P)){ goto a_G15;}a_L2=a_P[0];a_L1=a_P[1];
a_1210(a_L1); goto a_G13;
a_G15:a_1147(); return;
} /* datadeclaration */
static void a_1200(a_word a_F1){ /* pushBUFFER+>a */

{register a_word *a_r1=a_extension(a_1445,1);a_r1[0]=a_F1;to_LIST(a_1445)->aupb+=1;}
  return;
} /* pushBUFFER */
static void a_1158(void){ /* filltablehead */
a_word a_P[1];
a_P[0]=2130705866;a_1114(a_1001,1,a_P);
a_1160=0; return;
} /* filltablehead */
static void a_1159(void){ /* filltabletail */
a_word a_P[2];
a_P[0]=2130705859;a_P[1]=a_1160;a_1114(a_1001,2,a_P); return;
} /* filltabletail */
static void a_1225(a_word a_A[1]){ /* untilnextcomma+>a> */

a_G1:if(!a_more(a_A[0],to_LIST(a_1445)->aupb)){ goto a_G3;}
a_1425(a_1001,2130705849); return;
a_G3:if(!a_equal(to_LIST(a_1445)->offset[a_A[0]],44)){ goto a_G6;}
a_putchar(a_1115,44);
a_incr(a_A[0]); return;
a_G6:a_putchar(a_1115,to_LIST(a_1445)->offset[a_A[0]]);
a_incr(a_A[0]); goto a_G1;
} /* untilnextcomma */
static void a_1143(void){ /* constitem */
a_word a_L1;
if(!a_equal(a_1459,16777459)){ goto a_G4;}
a_1008(a_1460);
a_1466(); return;
a_G4:if(!a_equal(16777471,a_1459)){ goto a_G7;}
a_L1=a_1460;
a_1466(); goto a_G8;
a_G7:a_1420(a_1001,2130705145); return;
a_G8:if(!a_1341(a_L1,8)){ goto a_G10;}
a_L1=to_LIST(a_1303)->offset[a_L1];
a_G10:a_1008(to_LIST(a_1303)->offset[a_L1]); return;
} /* constitem */
static void a_1156(a_word a_A[1]){ /* fillitem+a> */

if(!a_equal(16777427,a_1459)){ goto a_G9;}
a_1466();
a_A[0]=0;
a_G4:if(!a_equal(16777406,a_1459)){ goto a_G6;}
a_1466(); return;
a_G6:a_incr(a_A[0]);
a_1143();
a_1200(44); goto a_G4;
a_G9:a_A[0]=1;
a_1143();
a_1200(44); return;
} /* fillitem */
static a_word a_1157(a_word a_A[1]){ /* fillrepeater+a> */
a_word a_L2;a_word a_P[1];
if(!a_equal(16777445,a_1459)){ return 0;}
a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G6;}
a_A[0]=a_1460;
a_1466(); return 1;
a_G6:if(!a_equal(16777471,a_1459)){ goto a_G9;}
a_L2=a_1460;
a_1466(); goto a_G10;
a_G9:a_1420(a_1001,2130705145); return 1;
a_G10:if(!a_1341(a_L2,8)){ goto a_G12;}
a_L2=to_LIST(a_1303)->offset[a_L2];
a_G12:a_1010(to_LIST(a_1303)->offset[a_L2],a_P);a_A[0]=a_P[0]; return 1;
} /* fillrepeater */
static void a_1163(a_word a_F1,a_word a_F2,a_word a_F3){ /* flushbuffer+>a+>a+>a */
a_word a_P[2];
a_add(a_F1,a_1160,a_1160);
a_add(a_F2,a_1160,a_1160);
a_incr(a_F3);
if(a_equal(a_F1,0)){ goto a_G7;}
a_P[0]=2130705843;a_P[1]=a_F1;a_1114(a_1001,2,a_P);
a_incr(a_1160);
a_G7:if(a_equal(a_F1,0)){ goto a_G10;}
a_P[0]=a_F3;a_1225(a_P);a_F3=a_P[0];
a_decr(a_F1); goto a_G7;
a_G10:if(a_equal(a_F2,0)){ goto a_G13;}
a_P[0]=2130705843;a_P[1]=a_F2;a_1114(a_1001,2,a_P);
a_incr(a_1160);
a_G13:if(a_equal(a_F2,0)){ return;}
a_P[0]=a_F3;a_1225(a_P);a_F3=a_P[0];
a_decr(a_F2); goto a_G13;
} /* flushbuffer */
static void a_1217(void){ /* skipfillinitializer */

a_G1:if(!a_equal(16777409,a_1459)){ return;}
a_1466();
if(!a_equal(16777471,a_1459)){ goto a_G6;}

a_1466(); goto a_G1;
a_G6:a_1420(a_1001,2130705145); return;
} /* skipfillinitializer */
static void a_1166(void){ /* generatefillentries */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[3];
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130705145); return;
a_G5:if(!a_1341(a_L1,8)){ goto a_G7;}
a_L1=to_LIST(a_1303)->offset[a_L1];
a_G7:if(!a_equal(16777455,a_1459)){ goto a_G4;}

a_1466();
a_incr(a_1160);
a_P[0]=2130705840;a_P[1]=a_L1;a_P[2]=a_L1;a_1114(a_1001,3,a_P);
a_L2=to_LIST(a_1445)->aupb;
a_L3=0;
a_G14:if(!a_equal(16777439,a_1459)){ goto a_G16;}
a_1466(); goto a_G25;
a_G16:a_1156(a_P);a_L4=a_P[0];
if(!a_1157(a_P)){ goto a_G23;}a_L5=a_P[0];
a_1163(a_L3,a_L4,a_L2);
a_P[0]=2130705835;a_P[1]=a_L5;a_1114(a_1001,2,a_P);
a_incr(a_1160);
a_unstackto(a_1445,a_L2);
a_L3=0; goto a_G24;
a_G23:a_add(a_L3,a_L4,a_L3);
a_G24:a_1217(); goto a_G14;
a_G25:a_1163(a_L3,0,a_L2);
a_unstackto(a_1445,a_L2);
a_incr(a_1160);
a_P[0]=2130705831;a_1114(a_1001,1,a_P); return;
} /* generatefillentries */
static void a_1177(a_word a_F1){ /* listinitialization+>a */
a_word a_L2;a_word a_P[4];
if(!a_1341(a_F1,16)){ return;}
a_1335(a_F1,a_P);a_L2=a_P[0];
a_P[0]=2130705827;a_P[1]=a_L2;a_P[2]=a_F1;a_P[3]=a_F1;a_1114(a_1001,4,a_P); return;
} /* listinitialization */
static void a_1140(a_word a_F1){ /* charfileinitialization+>a */
a_word a_P[4];
if(!a_1341(a_F1,16)){ goto a_G3;}
a_P[0]=2130705827;a_P[1]=to_LIST(a_1303)->offset[a_F1-1];a_P[2]=a_F1;a_P[3]=a_F1;a_1114(a_1001,4,a_P); return;
a_G3:a_P[0]=2130705821;a_P[1]=a_F1;a_1114(a_1001,2,a_P); return;
} /* charfileinitialization */
static void a_1146(a_word a_F1,a_word a_A[1]){ /* countfilearea+>a+a> */
a_word a_L3;a_word a_P[1];
a_A[0]=1;
a_G2:a_1326(a_F1,a_A[0],a_P);a_L3=a_P[0];
if(!a_equal(a_L3,0)){ goto a_G5;}
a_decr(a_A[0]); return;
a_G5:a_incr(a_A[0]); goto a_G2;
} /* countfilearea */
static void a_1150(a_word a_F1){ /* datafileinitialization+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[4];
if(!a_1341(a_F1,16)){ goto a_G3;}
a_P[0]=2130705827;a_P[1]=to_LIST(a_1303)->offset[a_F1-1];a_P[2]=a_F1;a_P[3]=a_F1;a_1114(a_1001,4,a_P); return;
a_G3:a_P[0]=2130705815;a_P[1]=a_F1;a_1114(a_1001,2,a_P);
a_L4=0;
a_L3=1;
a_G6:a_1326(a_F1,a_L3,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ goto a_G9;}
a_P[0]=2130705809;a_P[1]=a_F1;a_1114(a_1001,2,a_P); return;
a_G9:if(!a_1341(a_L2,8)){ goto a_G11;}
a_L2=to_LIST(a_1303)->offset[a_L2];
a_G11:a_P[0]=a_L4;a_1132(a_P);a_L4=a_P[0];
a_P[0]=2130705804;a_P[1]=a_L2;a_1114(a_1001,2,a_P);
a_incr(a_L3); goto a_G6;
} /* datafileinitialization */
static void a_1151(void){ /* datainitialization */
a_word a_L1;a_word a_P[1];
a_P[0]=2130705801;a_1114(a_1001,1,a_P);
a_L1=to_LIST(a_1303)->alwb;
a_G3:if(a_more(a_L1,to_LIST(a_1303)->aupb)){ goto a_G8;}
if(!a_1341(a_L1,8)){ goto a_G6;}
a_G5:a_next(a_1303,a_L1); goto a_G3;
a_G6:{register a_word a_r1=to_LIST(a_1303)->offset[a_L1-6];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G5;}
}
a_1177(a_L1); goto a_G5;
a_G8:a_L1=to_LIST(a_1303)->alwb;
a_G9:if(a_more(a_L1,to_LIST(a_1303)->aupb)){ return;}
if(!a_1341(a_L1,8)){ goto a_G12;}
a_G11:a_next(a_1303,a_L1); goto a_G9;
a_G12:{register a_word a_r1=to_LIST(a_1303)->offset[a_L1-6];
 if(a_r1==16777340){ goto a_G13;}
 if(a_r1==16777345){  goto a_G14;}
  goto a_G11;}
a_G13:a_1140(a_L1); goto a_G11;
a_G14:a_1150(a_L1); goto a_G11;
} /* datainitialization */
static void a_1198(void){ /* procwaitfor */
a_word a_L1;a_word a_L2;a_word a_L4;a_word a_P[5];
a_P[0]=2130705787;a_1114(a_1001,1,a_P);
a_P[0]=2130705778;a_1114(a_1001,1,a_P);
if(!a_equal(a_1136,0)){ goto a_G5;}
a_P[0]=2130705771;a_1114(a_1001,1,a_P); goto a_G6;
a_G5:a_P[0]=2130705765;a_1114(a_1001,1,a_P);
a_G6:a_L1=0;
a_G7:a_P[0]=a_L1;if(!a_1331(2,a_P)){ goto a_G16;}a_L1=a_P[0];a_L2=a_P[1];
a_L4=to_LIST(a_1303)->offset[a_L2-5];
if(a_equal(a_L4,155851727)){ goto a_G7;}
a_P[0]=2130705749;a_P[1]=a_L4;a_P[2]=a_L4;a_P[3]=a_L4;a_P[4]=a_L2;a_1114(a_1001,5,a_P);
a_1138(a_P);
a_P[0]=2130705722;a_P[1]=a_L4;a_P[2]=a_L4;a_P[3]=a_L4;a_1114(a_1001,4,a_P);
if(a_equal(a_1136,0)){ goto a_G15;}
a_P[0]=2130705699;a_1114(a_1001,1,a_P);
a_G15:a_P[0]=2130705695;a_1114(a_1001,1,a_P); goto a_G7;
a_G16:a_P[0]=2130705691;a_1114(a_1001,1,a_P); return;
} /* procwaitfor */
static void a_1220(void){ /* targetmain */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[2];
if(a_equal(a_1228,0)){ goto a_G4;}
if(a_more(a_1179,0)){ goto a_G4;}
a_P[0]=2019445255;a_1441(1,a_P);
a_G4:if(!a_equal(a_1228,0)){ goto a_G6;}
if(a_equal(a_1179,0)){ goto a_G7;}
a_G6:a_1198();
a_G7:a_P[0]=2130705688;a_1114(a_1001,1,a_P);
if(a_equal(a_1136,0)){ goto a_G10;}
a_P[0]=2130705680;a_1114(a_1001,1,a_P);
a_G10:a_1151();
a_L1=0;a_L4=0;
a_G12:a_P[0]=a_L1;if(!a_1331(2,a_P)){ goto a_G15;}a_L1=a_P[0];a_L2=a_P[1];
if(!a_equal(to_LIST(a_1303)->offset[a_L2-5],155851727)){ goto a_G12;}
a_L4=a_L2; goto a_G12;
a_G15:if(a_equal(a_1179,0)){ goto a_G20;}
a_P[0]=2130705669;a_1114(a_1001,1,a_P);
a_1138(a_P);a_L3=a_P[0];
a_P[0]=a_L3;a_1132(a_P);
a_P[0]=2130705664;a_1114(a_1001,1,a_P);
a_G20:if(!a_is(a_L4)){ goto a_G24;}
a_P[0]=2130705660;a_P[1]=a_L4;a_1114(a_1001,2,a_P);
a_1138(a_P);
a_P[0]=2130705656;a_1114(a_1001,1,a_P); return;
a_G24:a_1420(a_1001,2130705652); return;
} /* targetmain */
static void a_1215(a_word a_F1,a_word a_A[1]){ /* ruletyper+>a+a> */
a_word a_P[2];
a_P[0]=2130705647;a_P[1]=a_F1;a_1114(a_1001,2,a_P);
a_1137(a_P);a_A[0]=a_P[0]; return;
} /* ruletyper */
static void a_1132(a_word a_A[1]){ /* argsep+>a> */

if(!a_equal(a_A[0],0)){ goto a_G3;}
a_A[0]=1; return;
a_G3:a_putchar(a_1115,44); return;
} /* argsep */
static void a_1184(a_word a_F1,a_word a_A[1]){ /* outargs+>a+>a> */
a_word a_P[1];
if(a_equal(a_F1,0)){ return;}
a_P[0]=a_A[0];a_1132(a_P);a_A[0]=a_P[0];
a_P[0]=2130705641;a_1114(a_1001,1,a_P); return;
} /* outargs */
static void a_1211(a_word a_F1,a_word a_F2){ /* ruleargs+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[2];
a_1333(a_F1,a_P);a_L3=a_P[0];
a_L4=0;a_L6=0;
a_G3:if(!a_less(a_L4,a_L3)){ goto a_G15;}
a_1329(a_F1,a_L4,a_P);a_L5=a_P[0];
a_incr(a_L4);
if(a_equal(a_L5,16777376)){ goto a_G8;}
if(!a_equal(a_L5,16777382)){ goto a_G9;}
a_G8:a_incr(a_L6); goto a_G3;
a_G9:if(!a_equal(a_L5,16777388)){ goto a_G13;}
a_P[0]=a_F2;a_1184(a_L6,a_P);a_F2=a_P[0];
a_P[0]=a_F2;a_1132(a_P);
a_P[0]=2130705638;a_1114(a_1001,1,a_P); return;
a_G13:a_P[0]=a_F2;a_1132(a_P);a_F2=a_P[0];
a_P[0]=2130705632;a_P[1]=a_L4;a_1114(a_1001,2,a_P); goto a_G3;
a_G15:a_P[0]=a_F2;a_1184(a_L6,a_P);
a_putchar(a_1115,41); return;
} /* ruleargs */
static void a_1216(a_word a_F1){ /* showformalsascomment+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
 static const char *a_rulename="showformalsascomment";
a_1333(a_F1,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_mreq(a_L3,a_L2)){ return;}
a_1329(a_F1,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
{ if(a_L4==16777371){ goto a_G7;}
 if(a_L4==16777376){ goto a_G8;}
 if(a_L4==16777382){ goto a_G9;}
 if(a_L4==16777361){ goto a_G10;}
 if(a_L4==16777355){ goto a_G11;}
 if(a_L4==16777366){ goto a_G12;}
 if(!(a_L4==16777388)){a_area_failed(a_rulename,a_L4);}
  goto a_G13;}
a_G7:a_P[0]=2130705628;a_1114(a_1001,1,a_P); goto a_G3;
a_G8:a_P[0]=2130705625;a_1114(a_1001,1,a_P); goto a_G3;
a_G9:a_P[0]=2130705622;a_1114(a_1001,1,a_P); goto a_G3;
a_G10:a_P[0]=2130705618;a_1114(a_1001,1,a_P); goto a_G3;
a_G11:a_P[0]=2130705614;a_1114(a_1001,1,a_P); goto a_G3;
a_G12:a_P[0]=2130705610;a_1114(a_1001,1,a_P); goto a_G3;
a_G13:a_P[0]=2130705606;a_1114(a_1001,1,a_P); goto a_G3;
} /* showformalsascomment */
static void a_1153(a_word a_F1,a_word a_F2,a_word a_F3){ /* declarelocals+>a+>a+>a */
a_word a_P[2];
a_G1:if(a_equal(a_F1,0)){ return;}
if(a_more(a_F1,a_F2)){ return;}
if(!a_equal(to_LIST(a_1445)->offset[a_F3],0)){ goto a_G6;}
a_G4:a_incr(a_F1);
a_incr(a_F3); goto a_G1;
a_G6:a_P[0]=2130705603;a_P[1]=a_F1;a_1114(a_1001,2,a_P); goto a_G4;
} /* declarelocals */
static void a_1152(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4){ /* declarecallargs+>a+>a+>a+>a */
a_word a_L5;a_word a_P[3];
if(a_equal(a_F3,0)){ goto a_G3;}
a_P[0]=2130705598;a_P[1]=a_F3;a_1114(a_1001,2,a_P);
a_G3:if(a_equal(a_F4,0)){ goto a_G6;}
a_1324(a_F1,a_P);a_L5=a_P[0];
a_P[0]=2130705589;a_P[1]=a_F4;a_P[2]=a_L5;a_1114(a_1001,3,a_P);
a_G6:a_putchar(a_1115,10); return;
} /* declarecallargs */
static void a_1212(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4,a_word a_F5,a_word a_F6,a_word a_F7,a_word a_F8){ /* ruledeclarationhead+>a+>a+>a+>a+>a+>a+>a+>a */
a_word a_L9;a_word a_P[2];
a_1224=a_F1;
a_1129();
a_1215(a_F1,a_P);a_L9=a_P[0];
a_1211(a_F1,a_L9);
a_P[0]=2130705579;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_1114(a_1001,2,a_P);
a_1216(a_F1);
a_P[0]=2130705575;a_1114(a_1001,1,a_P);
a_add(a_F6,a_F8,a_F8);
a_1153(a_F6,a_F7,a_F8);
a_1152(a_F1,a_F2,a_F3,a_F4);
a_1127(a_F1);
a_1130(a_F5);
a_1128();
a_1131(); return;
} /* ruledeclarationhead */
static void a_1218(a_word a_F1){ /* startrulebody+>a */
a_word a_P[1];
if(a_equal(a_F1,0)){ return;}
a_P[0]=2130705572;a_1114(a_1001,1,a_P); return;
} /* startrulebody */
static void a_1213(a_word a_F1){ /* ruledeclarationtail+>a */
a_word a_P[2];
if(!a_equal(a_F1,0)){ goto a_G3;}
a_P[0]=2130705558;a_P[1]=a_1224;a_1114(a_1001,2,a_P); return;
a_G3:a_P[0]=2130705553;a_P[1]=a_1224;a_1114(a_1001,2,a_P); return;
} /* ruledeclarationtail */
static void a_1129(void){ /* addprofilingdef */
a_word a_L1;a_word a_L2;a_word a_P[3];
if(!a_1341(a_1224,33554432)){ return;}
a_L1=to_LIST(a_1303)->offset[a_1224-2];
if(!a_mreq(a_L1,0)){ return;}
a_L2=to_LIST(a_1303)->offset[a_1224];
a_P[0]=2130705548;a_P[1]=a_L2;a_P[2]=a_L1;a_1114(a_1001,3,a_P);
if(!a_equal(a_1175,0)){ goto a_G8;}
a_P[0]=2130705537;a_1114(a_1001,1,a_P); goto a_G9;
a_G8:a_P[0]=2130705533;a_P[1]=a_1175;a_1114(a_1001,2,a_P);
a_G9:a_P[0]=2130705529;a_1114(a_1001,1,a_P);
a_1175=a_L2; return;
} /* addprofilingdef */
static void a_1128(void){ /* addprofilingcount */
a_word a_P[2];
if(!a_1341(a_1224,33554432)){ return;}
if(!a_mreq(to_LIST(a_1303)->offset[a_1224-2],0)){ return;}
a_P[0]=2130705525;a_P[1]=to_LIST(a_1303)->offset[a_1224];a_1114(a_1001,2,a_P); return;
} /* addprofilingcount */
static void a_1199(void){ /* profilingdeclaration */
a_word a_P[2];
a_P[0]=2130705518;a_1114(a_1001,1,a_P);
if(!a_equal(a_1175,0)){ goto a_G4;}
a_P[0]=2130705511;a_1114(a_1001,1,a_P); return;
a_G4:a_P[0]=2130705507;a_P[1]=a_1175;a_1114(a_1001,2,a_P); return;
} /* profilingdeclaration */
static void a_1131(void){ /* addtracing */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[3];
if(!a_1341(a_1224,16777216)){ return;}
if(!a_mreq(to_LIST(a_1303)->offset[a_1224-2],0)){ return;}
a_1333(a_1224,a_P);a_L1=a_P[0];
a_L3=0;a_L2=0;
a_G5:if(a_mreq(a_L3,a_L1)){ goto a_G10;}
a_1329(a_1224,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
if(a_equal(a_L4,16777376)){ goto a_G5;}
a_incr(a_L2); goto a_G5;
a_G10:a_P[0]=2130705502;a_P[1]=to_LIST(a_1303)->offset[a_1224-2];a_P[2]=a_L2;a_1114(a_1001,3,a_P);
a_L3=0;
a_G12:if(a_mreq(a_L3,a_L1)){ goto a_G18;}
a_1329(a_1224,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
if(a_equal(a_L4,16777376)){ goto a_G12;}
a_putchar(a_1115,44);
a_1164(a_L3); goto a_G12;
a_G18:a_P[0]=2130705495;a_1114(a_1001,1,a_P); return;
} /* addtracing */
static void a_1130(a_word a_F1){ /* addrulename+>a */
a_word a_P[2];
if(a_equal(a_F1,0)){ return;}
if(a_mreq(to_LIST(a_1303)->offset[a_1224-2],0)){ return;}
a_P[0]=2130705491;a_P[1]=a_1224;a_1114(a_1001,2,a_P); return;
} /* addrulename */
static void a_1123(a_word a_F1,a_word a_F2){ /* Tlabel+>a+>a */
a_word a_P[2];
a_1181=a_F2;
if(a_equal(a_F1,0)){ return;}
if(a_equal(a_F1,1)){ return;}
a_P[0]=2130705482;a_P[1]=a_F1;a_1114(a_1001,2,a_P); return;
} /* Tlabel */
static void a_1174(a_word a_F1){ /* jumptolabel+>a */
a_word a_P[2];
if(a_equal(a_F1,a_1181)){ return;}
a_P[0]=2130705477;a_P[1]=a_F1;a_1114(a_1001,2,a_P); return;
} /* jumptolabel */
static void a_1116(a_word a_F1){ /* Taffix+>a */
a_word a_P[1];
{register a_word a_r1=to_LIST(a_1445)->offset[a_F1];
 if(a_r1==16777409){ goto a_G2;}
 if(a_r1==16777424){  return;}
  goto a_G3;}
a_G2:a_incr(a_F1);
a_G3:a_P[0]=a_F1;a_1117(a_P); return;
} /* Taffix */
static void a_1117(a_word a_A[1]){ /* Taffixinner+>a> */
a_word a_L2;a_word a_P[3];
{register a_word a_r1=to_LIST(a_1445)->offset[a_A[0]];
 if(a_r1==16777475||a_r1==16777479||a_r1==16777471){ goto a_G2;}
 if(a_r1==16777459){ goto a_G2;}
 if(a_r1==16777448){  goto a_G5;}
  goto a_G7;}
a_G2:a_P[0]=2130705473;a_P[1]=a_A[0];a_1114(a_1001,2,a_P);
a_G3:a_incr(a_A[0]);
a_incr(a_A[0]); return;
a_G5:a_incr(a_A[0]);
a_P[0]=a_A[0];a_1121(a_P);a_A[0]=a_P[0]; return;
a_G7:a_1124(to_LIST(a_1445)->offset[a_A[0]],a_P);a_L2=a_P[0];
a_incr(a_A[0]);
a_P[0]=2130705470;a_P[1]=a_A[0];a_P[2]=a_L2;a_1114(a_1001,3,a_P); goto a_G3;
} /* Taffixinner */
static void a_1124(a_word a_F1,a_word a_A[1]){ /* Tlimittail+>a+a> */

{ if(a_F1==16777231){ goto a_G2;}
 if(a_F1==16777269){ goto a_G3;}
 if(a_F1==16777291){ goto a_G4;}
 if(a_F1==16777295){ goto a_G5;}
 if(a_F1==16777299){  goto a_G6;}
  goto a_G7;}
a_G2:a_A[0]=2019445259; return;
a_G3:a_A[0]=2019445263; return;
a_G4:a_A[0]=2019445267; return;
a_G5:a_A[0]=2019445271; return;
a_G6:a_A[0]=2019445275; return;
a_G7:a_1425(a_1001,2130705466); return;
} /* Tlimittail */
static void a_1121(a_word a_A[1]){ /* Tindex+>a> */
a_word a_L2;a_word a_P[3];
if(!a_1341(a_1224,67108864)){ goto a_G15;}
a_P[0]=2130705461;a_P[1]=a_A[0];a_P[2]=a_A[0];a_1114(a_1001,3,a_P);
a_incr(a_A[0]);
a_incr(a_A[0]);
a_P[0]=a_A[0];a_1117(a_P);a_A[0]=a_P[0];
a_incr(a_A[0]);
a_subtr(to_LIST(a_1445)->offset[a_A[0]],1,a_L2);
a_incr(a_A[0]);
if(a_equal(a_L2,0)){ goto a_G11;}
a_P[0]=2130705453;a_P[1]=a_L2;a_1114(a_1001,2,a_P);
a_G11:a_P[0]=2130705450;a_P[1]=to_LIST(a_1303)->offset[a_1224-2];a_1114(a_1001,2,a_P);
if(!a_equal(a_1136,0)){ goto a_G14;}
a_P[0]=2130705447;a_1114(a_1001,1,a_P); return;
a_G14:a_P[0]=2130705444;a_1114(a_1001,1,a_P); return;
a_G15:a_P[0]=2130705439;a_P[1]=a_A[0];a_P[2]=a_A[0];a_1114(a_1001,3,a_P);
a_incr(a_A[0]);
a_incr(a_A[0]);
a_P[0]=a_A[0];a_1117(a_P);a_A[0]=a_P[0];
a_incr(a_A[0]);
a_subtr(to_LIST(a_1445)->offset[a_A[0]],1,a_L2);
a_incr(a_A[0]);
if(!a_equal(a_L2,0)){ goto a_G24;}
a_P[0]=2130705432;a_1114(a_1001,1,a_P); return;
a_G24:a_P[0]=2130705429;a_P[1]=a_L2;a_1114(a_1001,2,a_P); return;
} /* Tindex */
static void a_1155(a_word a_F1,a_word a_F2,a_word a_F3){ /* extensionblock+>a+>a+>a */
a_word a_L4;a_word a_L5;a_word a_P[4];
a_incr(a_F3);
a_L4=a_F3;
a_G3:if(a_equal(to_LIST(a_1445)->offset[a_L4],16777436)){ goto a_G5;}
a_incr(a_L4); goto a_G3;
a_G5:a_incr(a_L4);
a_G6:if(a_less(to_LIST(a_1445)->offset[a_L4],0)){ goto a_G10;}
a_subtr(a_F2,to_LIST(a_1445)->offset[a_L4],a_L5);
a_incr(a_L4);
a_P[0]=2130705425;a_P[1]=a_F1;a_P[2]=2019445279;a_P[3]=a_L5;a_1114(a_1001,4,a_P); goto a_G6;
a_G10:a_1116(a_F3);
a_putchar(a_1115,59); return;
} /* extensionblock */
static void a_1119(a_word a_F1,a_word a_F2){ /* Textension+>a+>a */
a_word a_L3;a_word a_L4;a_word a_P[4];
a_incr(a_F1);
a_L4=to_LIST(a_1445)->offset[a_F1];
a_incr(a_F1);
a_L3=a_F1;
a_P[0]=2130705419;a_P[1]=2019445279;a_P[2]=a_L3;a_P[3]=a_L4;a_1114(a_1001,4,a_P);
if(a_equal(a_1136,0)){ goto a_G8;}
a_P[0]=2130705699;a_1114(a_1001,1,a_P);
a_G8:a_P[0]=2130705410;a_1114(a_1001,1,a_P);
a_add(2,a_F1,a_F1);
a_G10:a_1155(a_L3,a_L4,a_F1);
a_F1=to_LIST(a_1445)->offset[a_F1];
if(!a_equal(a_F1,0)){ goto a_G10;}
a_P[0]=2130705407;a_P[1]=a_L3;a_P[2]=a_L4;a_1114(a_1001,3,a_P);
a_1174(a_F2); return;
} /* Textension */
static a_word a_1182(a_word a_F1,a_word a_F2){ /* numbersequal+>a+>a */
a_word a_L3;a_word a_P[1];
a_1011(0,a_F1,a_P);a_F1=a_P[0];
a_1011(0,a_F2,a_P);a_F2=a_P[0];
if(!a_1035(23,a_F1,a_F2)){ goto a_G5;}
a_L3=1; goto a_G6;
a_G5:a_L3=0;
a_G6:a_1023(a_F1);
a_1023(a_F2);
if(!a_is(a_L3)){ return 0;} return 1;
} /* numbersequal */
static void a_1134(a_word a_F1,a_word a_A[1]){ /* boxclassifier+>a+a> */
a_word a_P[2];
{register a_word a_r1=to_LIST(a_1445)->offset[a_F1];
 if(!(a_r1==16777471||a_r1==16777479||a_r1==16777475||a_r1==16777459)){ goto a_G3;}
}
a_A[0]=a_F1; return;
a_G3:a_A[0]=2019445279;
a_P[0]=2130705401;a_P[1]=a_A[0];a_1114(a_1001,2,a_P);
a_1116(a_F1);
a_P[0]=2130705396;a_1114(a_1001,1,a_P); return;
} /* boxclassifier */
static a_word a_1171(a_word a_F1){ /* iscompletearea+>a */

if(!a_equal(to_LIST(a_1445)->offset[a_F1],0)){ return 0;}
a_incr(a_F1);
a_incr(a_F1);
if(!a_equal(to_LIST(a_1445)->offset[a_F1],a_1019)){ return 0;}
a_incr(a_F1);
if(!a_equal(to_LIST(a_1445)->offset[a_F1],a_1018)){ return 0;} return 1;
} /* iscompletearea */
static void a_1126(a_word a_F1,a_word a_F2,a_word a_F3){ /* Tsingleifcondition+>a+>a+>a */
a_word a_P[5];
if(!a_1182(a_F1,a_F2)){ goto a_G3;}
a_P[0]=2130705393;a_P[1]=a_F3;a_P[2]=a_F1;a_1114(a_1001,3,a_P); return;
a_G3:if(!a_1182(a_F1,a_1019)){ goto a_G5;}
a_P[0]=2130705389;a_P[1]=a_F3;a_P[2]=a_F2;a_1114(a_1001,3,a_P); return;
a_G5:if(!a_1182(a_F2,a_1018)){ goto a_G7;}
a_P[0]=2130705385;a_P[1]=a_F3;a_P[2]=a_F1;a_1114(a_1001,3,a_P); return;
a_G7:a_P[0]=2130705381;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_F3;a_P[4]=a_F2;a_1114(a_1001,5,a_P); return;
} /* Tsingleifcondition */
static void a_1120(a_word a_F1,a_word a_F2){ /* Tifcondition+>a+>a */
a_word a_L3;a_word a_L4;a_word a_P[1];
a_G1:a_incr(a_F1);
a_L3=to_LIST(a_1445)->offset[a_F1];
a_incr(a_F1);
a_L4=to_LIST(a_1445)->offset[a_F1];
a_1126(a_L3,a_L4,a_F2);
a_incr(a_F1);
if(!a_equal(to_LIST(a_1445)->offset[a_F1],16777442)){ return;}
a_P[0]=2130705374;a_1114(a_1001,1,a_P); goto a_G1;
} /* Tifcondition */
static void a_1122(a_word a_F1,a_word a_F2){ /* Tjumptoareas+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
a_G1:a_L5=to_LIST(a_1445)->offset[a_F1];
if(!a_equal(a_L5,0)){ goto a_G16;}
a_incr(a_F1);
a_L3=to_LIST(a_1445)->offset[a_F1];
a_P[0]=2130705371;a_1114(a_1001,1,a_P);
a_1120(a_F1,a_F2);
a_P[0]=2130705367;a_P[1]=a_F2;a_1114(a_1001,2,a_P);
if(!a_mreq(to_LIST(a_1303)->offset[a_1224-2],0)){ goto a_G10;}
a_P[0]=2130705360;a_P[1]=to_LIST(a_1303)->offset[a_1224-2];a_1114(a_1001,2,a_P); goto a_G11;
a_G10:a_P[0]=2130705354;a_1114(a_1001,1,a_P);
a_G11:if(a_equal(a_1136,0)){ goto a_G13;}
a_P[0]=2130705699;a_1114(a_1001,1,a_P);
a_G13:a_P[0]=2130705349;a_1114(a_1001,1,a_P);
if(a_equal(a_L3,a_1181)){ return;}
a_P[0]=2130705345;a_P[1]=to_LIST(a_1445)->offset[a_F1];a_1114(a_1001,2,a_P); return;
a_G16:if(!a_1171(a_L5)){ goto a_G31;}
a_incr(a_F1);
a_L3=to_LIST(a_1445)->offset[a_F1];
a_incr(a_L5);
a_L4=to_LIST(a_1445)->offset[a_L5];
if(!a_equal(a_L3,a_1181)){ goto a_G26;}
if(a_equal(a_L3,a_L4)){ return;}
a_P[0]=2130705371;a_1114(a_1001,1,a_P);
a_1120(a_F1,a_F2);
a_P[0]=2130705342;a_P[1]=a_L4;a_1114(a_1001,2,a_P); return;
a_G26:a_P[0]=2130705337;a_1114(a_1001,1,a_P);
a_1120(a_F1,a_F2);
a_P[0]=2130705333;a_P[1]=a_L3;a_1114(a_1001,2,a_P);
if(a_equal(a_L4,a_1181)){ return;}
a_P[0]=2130705345;a_P[1]=a_L4;a_1114(a_1001,2,a_P); return;
a_G31:a_incr(a_F1);
a_P[0]=2130705337;a_1114(a_1001,1,a_P);
a_1120(a_F1,a_F2);
a_P[0]=2130705328;a_P[1]=to_LIST(a_1445)->offset[a_F1];a_1114(a_1001,2,a_P);
a_F1=a_L5; goto a_G1;
} /* Tjumptoareas */
static void a_1118(a_word a_F1,a_word a_F2){ /* Tbox+>a+>a */
a_word a_L3;a_word a_P[1];
a_P[0]=2130705324;a_1114(a_1001,1,a_P);
a_incr(a_F1);
a_1134(a_F1,a_P);a_L3=a_P[0];
a_incr(a_F2);
a_1122(a_F2,a_L3);
a_P[0]=2130705691;a_1114(a_1001,1,a_P); return;
} /* Tbox */
static void a_1125(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4,a_word a_F5,a_word a_F6,a_word a_F7){ /* Trulecall+>a+>a+>a+>a+>a+>a+>a */
a_word a_L8;a_word a_L9;a_word a_P[3];
a_1135=a_F1;
a_incr(a_F7);
if(!a_1173(a_F7,a_F3,a_F4)){ goto a_G5;}
a_P[0]=2130705321;a_P[1]=a_F1;a_P[2]=a_F4;a_1114(a_1001,3,a_P); return;
a_G5:if(!a_1343(a_F1)){ goto a_G7;}
a_1169(a_F7,a_F4); return;
a_G7:if(!a_1339(a_F1)){ goto a_G9;}
a_1165(a_F5,a_F6,a_F7,a_F4); return;
a_G9:if(!a_1340(a_F1,a_P)){ goto a_G13;}a_L8=a_P[0];
if(!a_equal(a_L8,1)){ goto a_G12;}
a_1168(a_F3,a_F4); return;
a_G12:a_1167(a_F2,a_F7,a_F4); return;
a_G13:if(!a_1341(a_F1,12288)){ goto a_G18;}
a_1201(1,a_F3,a_F4,a_P);a_L9=a_P[0];
a_1186(a_L9,a_F7);
a_1202(a_L9,a_F3);
a_G17:a_1203(a_L9,a_F3,a_F4); return;
a_G18:a_1205(a_F7);
a_1201(0,a_F3,a_F4,a_P);a_L9=a_P[0];
a_1206(a_F7);
a_1202(a_L9,a_F3);
a_1204(a_F7); goto a_G17;
} /* Trulecall */
static void a_1180(a_word a_A[1]){ /* nextaffix+>a> */

a_G1:if(!a_equal(to_LIST(a_1445)->offset[a_A[0]],16777436)){ goto a_G3;}
a_incr(a_A[0]); return;
a_G3:a_incr(a_A[0]); goto a_G1;
} /* nextaffix */
static a_word a_1172(a_word a_F1){ /* isdummyaffix+>a */

{register a_word a_r1=to_LIST(a_1445)->offset[a_F1];
 if(a_r1==16777424||a_r1==16777409){  return 1;}
  return 0;}
} /* isdummyaffix */
static a_word a_1170(a_word a_F1){ /* hasoutaffix+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1333(a_1135,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_mreq(a_L3,a_L2)){ return 0;}
if(!a_1172(a_F1)){ goto a_G7;}
a_G5:a_incr(a_L3);
a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0]; goto a_G3;
a_G7:a_1329(a_1135,a_L3,a_P);a_L4=a_P[0];
if(a_equal(a_L4,16777376)){ return 1;}
if(a_equal(a_L4,16777382)){ return 1;}
if(a_equal(a_L4,16777388)){ return 1;} goto a_G5;
} /* hasoutaffix */
static a_word a_1173(a_word a_F1,a_word a_F2,a_word a_F3){ /* isrulediscarded+>a+>a+>a */

if(a_1341(a_1135,256)){ return 0;}
if(a_1341(a_1135,1024)){ return 0;}
if(a_1341(a_1135,32768)){ return 0;}
if(a_1170(a_F1)){ return 0;}
if(!a_1341(a_1135,512)){ return 1;}
if(!a_equal(a_F2,a_F3)){ return 0;} return 1;
} /* isrulediscarded */
static void a_1168(a_word a_F1,a_word a_F2){ /* genshiftaffix+>a+>a */
a_word a_L3;a_word a_P[4];
a_1324(a_1224,a_P);a_L3=a_P[0];
if(a_equal(a_F1,a_1181)){ goto a_G6;}
if(!a_equal(a_F1,a_F2)){ goto a_G5;}
a_F2=a_1181; goto a_G6;
a_G5:if(!a_noteq(a_F2,a_1181)){ goto a_G7;}
a_G6:a_P[0]=2130705315;a_P[1]=a_L3;a_P[2]=a_F2;a_P[3]=a_F1;a_1114(a_1001,4,a_P); return;
a_G7:a_P[0]=2130705304;a_P[1]=a_F1;a_P[2]=a_L3;a_1114(a_1001,3,a_P); return;
} /* genshiftaffix */
static void a_1167(a_word a_F1,a_word a_F2,a_word a_F3){ /* gengetaffixno+>a+>a+>a */
a_word a_P[2];
if(!a_noteq(a_F1,2)){ goto a_G3;}
a_1420(a_1001,2130705293); return;
a_G3:if(!a_1172(a_F2)){ goto a_G5;}
a_P[0]=2130705287;a_P[1]=a_F3;a_1114(a_1001,2,a_P); return;
a_G5:a_1116(a_F2);
a_P[0]=2130705283;a_P[1]=a_F3;a_1114(a_1001,2,a_P); return;
} /* gengetaffixno */
static void a_1169(a_word a_F1,a_word a_F2){ /* genwaitfor+>a+>a */
a_word a_L3;a_word a_P[2];
a_P[0]=2130705669;a_1114(a_1001,1,a_P);
a_1138(a_P);a_L3=a_P[0];
a_P[0]=a_L3;a_1132(a_P);a_L3=a_P[0];
a_1116(a_F1);
a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0];
a_P[0]=a_L3;a_1132(a_P);
a_1116(a_F1);
a_P[0]=2130705278;a_P[1]=a_F2;a_1114(a_1001,2,a_P); return;
} /* genwaitfor */
static void a_1133(a_word a_F1,a_word a_A[2]){ /* assignmentsource+>a+a>+a> */
a_word a_P[2];
{register a_word a_r1=to_LIST(a_1445)->offset[a_F1];
 if(!(a_r1==16777471||a_r1==16777479||a_r1==16777475||a_r1==16777459)){ goto a_G4;}
}
a_A[0]=a_F1;
a_A[1]=0; return;
a_G4:a_A[0]=2019445279;
a_P[0]=2130705274;a_P[1]=a_A[0];a_1114(a_1001,2,a_P);
a_1116(a_F1);
a_putchar(a_1115,59);
a_A[1]=1; return;
} /* assignmentsource */
static void a_1165(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4){ /* genassignment+>a+>a+>a+>a */
a_word a_L5;a_word a_L6;a_word a_L7;a_word a_L8;a_word a_L9;a_word a_P[6];
a_L5=a_F3;
a_P[0]=a_F3;a_1180(a_P);a_F3=a_P[0];
a_L8=0;
a_L9=1;
a_G5:if(a_mreq(a_L9,a_F1)){ goto a_G10;}
a_incr(a_L9);
a_P[0]=a_F3;a_1180(a_P);a_F3=a_P[0];
{register a_word a_r1=to_LIST(a_1445)->offset[a_F3];
 if(a_r1==16777397||a_r1==16777424||a_r1==16777409){  goto a_G5;}
}
a_incr(a_L8); goto a_G5;
a_G10:if(a_more(a_L8,1)){ goto a_G12;}
if(!a_is(a_F2)){ goto a_G13;}
a_G12:a_1133(a_L5,a_P);a_L6=a_P[0];a_L7=a_P[1]; goto a_G14;
a_G13:a_L6=0;a_L7=0;
a_G14:a_F3=a_L5;
a_P[0]=a_F3;a_1180(a_P);a_F3=a_P[0];
a_L9=1;
a_G17:if(a_mreq(a_L9,a_F1)){ goto a_G27;}
a_incr(a_L9);
a_P[0]=a_F3;a_1180(a_P);a_F3=a_P[0];
{register a_word a_r1=to_LIST(a_1445)->offset[a_F3];
 if(a_r1==16777397||a_r1==16777424||a_r1==16777409){  goto a_G17;}
}
a_1116(a_F3);
if(!a_equal(a_L6,0)){ goto a_G26;}
a_putchar(a_1115,61);
a_1116(a_L5);
a_putchar(a_1115,59); goto a_G17;
a_G26:a_P[0]=2130705269;a_P[1]=a_L6;a_1114(a_1001,2,a_P); goto a_G17;
a_G27:if(a_equal(a_F2,0)){ goto a_G29;}
a_P[0]=2130705265;a_P[1]=2019445283;a_P[2]=2019445283;a_P[3]=2019445283;a_P[4]=2019445283;a_P[5]=a_L6;a_1114(a_1001,6,a_P);
a_G29:if(a_equal(a_L7,0)){ goto a_G31;}
a_putchar(a_1115,125);
a_G31:a_P[0]=2130705287;a_P[1]=a_F4;a_1114(a_1001,2,a_P); return;
} /* genassignment */
static void a_1209(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4){ /* repeatblockpreload+>a+>a+>a+>a */
a_word a_L5;a_word a_L6;a_word a_L7;a_word a_L8;a_word a_L9;a_word a_P[3];
a_incr(a_F1);
a_L5=to_LIST(a_1445)->offset[a_F1];
a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0];
a_L9=a_F3;
if(!a_less(a_L5,0)){ goto a_G8;}
a_F4=0;
a_subtr(0,a_L5,a_L7); goto a_G9;
a_G8:a_L7=a_L5;
a_G9:a_1324(a_1135,a_P);a_L6=a_P[0];
a_mult(a_L7,a_L6,a_L7);
a_G11:if(a_equal(a_L7,0)){ goto a_G25;}
a_1329(a_1135,a_L9,a_P);a_L8=a_P[0];
if(a_equal(a_L8,16777376)){ goto a_G19;}
if(!a_more(a_L5,0)){ goto a_G18;}
a_P[0]=2130705251;a_P[1]=a_F4;a_1114(a_1001,2,a_P);
a_G16:a_1116(a_F1);
a_putchar(a_1115,59); goto a_G19;
a_G18:a_P[0]=2130705246;a_P[1]=a_F4;a_1114(a_1001,2,a_P); goto a_G16;
a_G19:a_incr(a_L9);
if(a_less(a_L9,a_F2)){ goto a_G22;}
a_L9=a_F3;
a_G22:a_decr(a_L7);
a_incr(a_F4);
a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0]; goto a_G11;
a_G25:if(a_mreq(a_L5,0)){ return;}
a_P[0]=2130705241;a_P[1]=a_L6;a_P[2]=a_F4;a_1114(a_1001,3,a_P); return;
} /* repeatblockpreload */
static void a_1205(a_word a_F1){ /* regularcallpreload+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
a_1333(a_1135,a_P);a_L2=a_P[0];
a_L3=0;a_L4=0;
a_G3:if(a_equal(a_L3,a_L2)){ return;}
a_1329(a_1135,a_L3,a_P);a_L5=a_P[0];
a_incr(a_L3);
if(!a_equal(a_L5,16777376)){ goto a_G9;}
a_incr(a_L4);
a_G8:a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0]; goto a_G3;
a_G9:if(!a_equal(a_L5,16777382)){ goto a_G14;}
a_P[0]=2130705251;a_P[1]=a_L4;a_1114(a_1001,2,a_P);
a_incr(a_L4);
a_1116(a_F1);
a_putchar(a_1115,59); goto a_G8;
a_G14:if(!a_equal(a_L5,16777388)){ goto a_G8;}
a_1209(a_F1,a_L2,a_L3,a_L4); return;
} /* regularcallpreload */
static void a_1207(a_word a_F1,a_word a_F2,a_word a_F3){ /* repeatblockcall+>a+>a+>a */
a_word a_L4;a_word a_P[3];
if(a_equal(a_F2,0)){ goto a_G4;}
a_P[0]=a_F3;a_1132(a_P);a_F3=a_P[0];
a_P[0]=2130705224;a_1114(a_1001,1,a_P);
a_G4:a_incr(a_F1);
a_L4=to_LIST(a_1445)->offset[a_F1];
a_P[0]=a_F3;a_1132(a_P);
if(!a_equal(a_L4,0)){ goto a_G9;}
a_P[0]=2130705638;a_1114(a_1001,1,a_P); return;
a_G9:if(!a_less(a_L4,0)){ goto a_G12;}
a_subtr(0,a_L4,a_L4);
a_P[0]=2130705221;a_P[1]=a_L4;a_1114(a_1001,2,a_P); return;
a_G12:if(!a_equal(a_F2,0)){ goto a_G14;}
a_P[0]=2130705215;a_P[1]=a_L4;a_1114(a_1001,2,a_P); return;
a_G14:a_P[0]=2130705210;a_P[1]=a_L4;a_P[2]=a_F2;a_1114(a_1001,3,a_P); return;
} /* repeatblockcall */
static void a_1206(a_word a_F1){ /* regularrulecall+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[2];
a_1333(a_1135,a_P);a_L2=a_P[0];
a_P[0]=2130705205;a_P[1]=a_1135;a_1114(a_1001,2,a_P);
a_L3=0;a_L4=0;
if(!a_1341(a_1135,16)){ goto a_G6;}
a_L5=0; goto a_G7;
a_G6:a_1138(a_P);a_L5=a_P[0];
a_G7:if(!a_equal(a_L3,a_L2)){ goto a_G12;}
if(!a_equal(a_L4,0)){ goto a_G10;}
a_putchar(a_1115,41); return;
a_G10:a_P[0]=a_L5;a_1132(a_P);
a_P[0]=2130705202;a_1114(a_1001,1,a_P); return;
a_G12:a_1329(a_1135,a_L3,a_P);a_L6=a_P[0];
a_incr(a_L3);
if(a_equal(a_L6,16777376)){ goto a_G16;}
if(!a_equal(a_L6,16777382)){ goto a_G18;}
a_G16:a_incr(a_L4);
a_G17:a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0]; goto a_G7;
a_G18:if(!a_equal(a_L6,16777388)){ goto a_G20;}
a_1207(a_F1,a_L4,a_L5); return;
a_G20:a_P[0]=a_L5;a_1132(a_P);a_L5=a_P[0];
a_1116(a_F1); goto a_G17;
} /* regularrulecall */
static void a_1208(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4){ /* repeatblockpostload+>a+>a+>a+>a */
a_word a_L5;a_word a_L6;a_word a_L7;a_word a_L8;a_word a_L9;a_word a_P[3];
a_incr(a_F1);
a_L5=to_LIST(a_1445)->offset[a_F1];
a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0];
a_L7=a_F3;
if(!a_less(a_L5,0)){ goto a_G8;}
a_F4=0;
a_subtr(0,a_L5,a_L8); goto a_G9;
a_G8:a_L8=a_L5;
a_G9:a_1324(a_1135,a_P);a_L6=a_P[0];
a_mult(a_L8,a_L6,a_L8);
a_G11:if(a_equal(a_L8,0)){ goto a_G26;}
a_1329(a_1135,a_L7,a_P);a_L9=a_P[0];
if(a_1172(a_F1)){ goto a_G20;}
if(a_equal(a_L9,16777376)){ goto a_G16;}
if(!a_equal(a_L9,16777382)){ goto a_G20;}
a_G16:a_1116(a_F1);
if(!a_more(a_L5,0)){ goto a_G19;}
a_P[0]=2130705198;a_P[1]=a_F4;a_1114(a_1001,2,a_P); goto a_G20;
a_G19:a_P[0]=2130705193;a_P[1]=a_F4;a_1114(a_1001,2,a_P);
a_G20:a_incr(a_L7);
if(a_less(a_L7,a_F2)){ goto a_G23;}
a_L7=a_F3;
a_G23:a_decr(a_L8);
a_incr(a_F4);
a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0]; goto a_G11;
a_G26:if(a_mreq(a_L5,0)){ return;}
a_P[0]=2130705188;a_P[1]=a_L6;a_P[2]=a_F4;a_1114(a_1001,3,a_P); return;
} /* repeatblockpostload */
static void a_1204(a_word a_F1){ /* regularcallpostload+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
a_1333(a_1135,a_P);a_L2=a_P[0];
a_L3=0;a_L4=0;
a_G3:if(a_equal(a_L3,a_L2)){ return;}
a_1329(a_1135,a_L3,a_P);a_L5=a_P[0];
a_incr(a_L3);
if(a_equal(a_L5,16777376)){ goto a_G8;}
if(!a_equal(a_L5,16777382)){ goto a_G13;}
a_G8:if(a_1172(a_F1)){ goto a_G11;}
a_1116(a_F1);
a_P[0]=2130705198;a_P[1]=a_L4;a_1114(a_1001,2,a_P);
a_G11:a_incr(a_L4);
a_G12:a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0]; goto a_G3;
a_G13:if(!a_equal(a_L5,16777388)){ goto a_G12;}
a_1208(a_F1,a_L2,a_L3,a_L4); return;
} /* regularcallpostload */
static void a_1201(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]){ /* regularcalld1+>a+>a+>a+a> */
a_word a_P[1];
if(!a_1341(a_1135,512)){ goto a_G10;}
if(!a_noteq(a_F2,a_1181)){ goto a_G9;}
if(a_equal(a_F3,a_1181)){ goto a_G5;}
if(!a_lseq(a_F2,0)){ goto a_G9;}
a_G5:a_A[0]=2;
if(!a_equal(a_F1,0)){ goto a_G8;}
a_P[0]=2130705171;a_1114(a_1001,1,a_P); return;
a_G8:a_P[0]=2130705167;a_1114(a_1001,1,a_P); return;
a_G9:a_A[0]=1; goto a_G8;
a_G10:a_A[0]=0; return;
} /* regularcalld1 */
static void a_1202(a_word a_F1,a_word a_F2){ /* regularcalld2+>a+>a */
a_word a_P[2];
if(!a_equal(a_F1,1)){ goto a_G3;}
a_P[0]=2130705164;a_1114(a_1001,1,a_P); return;
a_G3:if(!a_equal(a_F1,2)){ goto a_G5;}
a_P[0]=2130705161;a_P[1]=a_F2;a_1114(a_1001,2,a_P); return;
a_G5:a_putchar(a_1115,59); return;
} /* regularcalld2 */
static void a_1203(a_word a_F1,a_word a_F2,a_word a_F3){ /* regularcalld3+>a+>a+>a */
a_word a_P[3];
if(!a_equal(a_F1,1)){ goto a_G4;}
a_P[0]=2130705157;a_P[1]=a_F3;a_P[2]=a_F2;a_1114(a_1001,3,a_P); return;
a_G4:a_P[0]=2130705287;a_P[1]=a_F3;a_1114(a_1001,2,a_P); return;
} /* regularcalld3 */
static void a_1185(a_word a_F1,a_word a_A[1]){ /* pidginalttagtailtype+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[1];
a_1333(a_1135,a_P);a_L3=a_P[0];
a_L4=0;a_A[0]=0;
a_G3:if(a_equal(a_L4,a_L3)){ return;}
a_1329(a_1135,a_L4,a_P);a_L5=a_P[0];
a_incr(a_L4);
if(!a_equal(a_L5,16777376)){ goto a_G10;}
a_leftclear(a_A[0],1);
if(a_equal(to_LIST(a_1445)->offset[a_F1],16777424)){ goto a_G10;}
a_incr(a_A[0]);
a_G10:if(a_equal(a_L5,16777388)){ return;}
a_P[0]=a_F1;a_1180(a_P);a_F1=a_P[0]; goto a_G3;
} /* pidginalttagtailtype */
static a_word a_1141(a_word a_F1,a_word a_A[1]){ /* checkBUFFERno+>a+>a> */
a_word a_L3;
a_subtr(to_LIST(a_1445)->offset[a_A[0]],48,a_L3);
a_incr(a_A[0]);
a_G3:if(!a_equal(to_LIST(a_1445)->offset[a_A[0]],48)){ goto a_G6;}
a_incr(a_A[0]);
a_leftclear(a_L3,1); goto a_G3;
a_G6:if(!a_equal(to_LIST(a_1445)->offset[a_A[0]],49)){ goto a_G10;}
a_incr(a_A[0]);
a_leftclear(a_L3,1);
a_incr(a_L3); goto a_G3;
a_G10:if(!a_equal(a_L3,a_F1)){ return 0;} return 1;
} /* checkBUFFERno */
static void a_1162(a_word a_F1,a_word a_A[1]){ /* findBUFFERversion+>a+>a> */
a_word a_P[4];
a_G1:if(!a_mreq(a_A[0],to_LIST(a_1445)->aupb)){ goto a_G4;}
a_decr(a_A[0]);
a_P[0]=2019445299;a_P[1]=to_LIST(a_1303)->offset[a_1135];a_P[2]=a_1135;a_P[3]=a_F1;a_1421(4,a_P); return;
a_G4:if(!a_equal(to_LIST(a_1445)->offset[a_A[0]],64)){ goto a_G8;}
a_incr(a_A[0]);
if(!a_equal(to_LIST(a_1445)->offset[a_A[0]],48)){ goto a_G9;}
a_G7:a_P[0]=a_A[0];if(a_1141(a_F1,a_P)){a_A[0]=a_P[0]; return;}
a_G8:a_incr(a_A[0]); goto a_G1;
a_G9:if(a_equal(to_LIST(a_1445)->offset[a_A[0]],49)){ goto a_G7;} goto a_G1;
} /* findBUFFERversion */
static void a_1161(a_word a_A[1]){ /* findBUFFERalternative+>a> */

a_G1:if(!a_equal(to_LIST(a_1445)->offset[a_A[0]],64)){ goto a_G3;}
a_incr(a_A[0]); return;
a_G3:if(!a_less(a_A[0],to_LIST(a_1445)->aupb)){ goto a_G5;}
a_incr(a_A[0]); goto a_G1;
a_G5:a_1425(a_1001,2130705153); return;
} /* findBUFFERalternative */
static void a_1145(a_word a_F1,a_word a_F2,a_word a_F3){ /* copytextfromBUFFER+>a+>a+>a */
a_word a_L4;
a_G1:if(a_more(a_F1,to_LIST(a_1445)->aupb)){ return;}
if(a_equal(to_LIST(a_1445)->offset[a_F1],64)){ return;}
if(!a_equal(to_LIST(a_1445)->offset[a_F1],35)){ goto a_G15;}
a_incr(a_F1);
{register a_word a_r1=to_LIST(a_1445)->offset[a_F1];
 if((49<=a_r1 && a_r1<=57)){ goto a_G6;}
 if((97<=a_r1 && a_r1<=122)){ goto a_G9;}
 if(a_r1==44){ goto a_G11;}
 if(a_r1==48){  goto a_G13;}
  goto a_G15;}
a_G6:a_subtr(to_LIST(a_1445)->offset[a_F1],48,a_L4);
a_G7:a_1144(a_F2,a_F3,a_L4);
a_G8:a_incr(a_F1); goto a_G1;
a_G9:a_subtr(to_LIST(a_1445)->offset[a_F1],97,a_L4);
a_add(10,a_L4,a_L4); goto a_G7;
a_G11:if(a_equal(a_1136,0)){ goto a_G1;}
a_1488(a_1115,a_1001,2130705699); goto a_G1;
a_G13:if(a_equal(a_1136,0)){ goto a_G1;}
a_1488(a_1115,a_1001,2130706048); goto a_G1;
a_G15:a_putchar(a_1115,to_LIST(a_1445)->offset[a_F1]); goto a_G8;
} /* copytextfromBUFFER */
static void a_1144(a_word a_F1,a_word a_F2,a_word a_F3){ /* copyaffix+>a+>a+>a */
a_word a_P[4];
if(!a_more(a_F3,a_F1)){ goto a_G3;}
a_P[0]=2019445314;a_P[1]=to_LIST(a_1303)->offset[a_1135];a_P[2]=a_1135;a_P[3]=a_F3;a_1421(4,a_P); return;
a_G3:if(a_equal(a_F3,1)){ goto a_G6;}
a_decr(a_F3);
a_P[0]=a_F2;a_1180(a_P);a_F2=a_P[0]; goto a_G3;
a_G6:a_1116(a_F2); return;
} /* copyaffix */
static void a_1186(a_word a_F1,a_word a_F2){ /* pidginrulecall+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[1];
a_L3=to_LIST(a_1445)->aupb;
a_1458(to_LIST(a_1303)->offset[a_1135],a_P);a_L5=a_P[0];
a_unpackstring(a_1449,a_L5,a_1445);
a_1200(64);
a_L5=a_L3;
a_incr(a_L5);
if(!a_1341(a_1135,8192)){ goto a_G10;}
a_1185(a_F2,a_P);a_L4=a_P[0];
a_P[0]=a_L5;a_1162(a_L4,a_P);a_L5=a_P[0];
a_G10:if(a_noteq(a_F1,2)){ goto a_G12;}
a_P[0]=a_L5;a_1161(a_P);a_L5=a_P[0];
a_G12:a_1333(a_1135,a_P);a_L4=a_P[0];
a_1145(a_L5,a_L4,a_F2);
a_unstackto(a_1445,a_L3); return;
} /* pidginrulecall */
static void a_1254(a_word a_F1){ /* pushEXPR+>a */

{register a_word *a_r1=a_extension(a_1231,1);a_r1[0]=a_F1;to_LIST(a_1231)->aupb+=1;}
  return;
} /* pushEXPR */
static void a_1246(a_word a_A[1]){ /* getitemdef+>a> */

if(!a_1341(a_A[0],8)){ return;}
a_A[0]=to_LIST(a_1303)->offset[a_A[0]]; return;
} /* getitemdef */
static void a_1238(a_word a_F1){ /* checklisttype+>a */

{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G3;}
}
if(!a_1341(a_F1,24)){ return;}
a_G3:a_1420(a_1001,2130706157); return;
} /* checklisttype */
static void a_1236(a_word a_F1){ /* checkcalibretype+>a */

{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G3;}
}
if(!a_1341(a_F1,8)){ return;}
a_G3:a_1420(a_1001,2130706151); return;
} /* checkcalibretype */
static void a_1237(a_word a_F1,a_word a_F2){ /* checkconstanttype+>a+>a */

{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(a_r1==16777335){ goto a_G2;}
 if(a_r1==16777304){ goto a_G3;}
 if(a_r1==16777309||a_r1==16777314){  goto a_G4;}
  goto a_G5;}
a_G2:if(a_equal(a_F2,1)){ goto a_G5;}
a_G3:if(!a_1341(a_F1,24)){ return;} goto a_G5;
a_G4:if(!a_equal(a_F2,0)){ goto a_G3;}
a_G5:a_1420(a_1001,2130706144); return;
} /* checkconstanttype */
static void a_1255(void){ /* readexpression */
a_word a_L1;a_word a_L2;a_word a_P[1];
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706116); return;
a_G5:a_1237(a_L1,1);
if(a_equal(to_LIST(a_1303)->offset[a_L1-1],0)){ goto a_G8;}
a_G7:a_1420(a_1001,2130706137); return;
a_G8:a_1254(a_L1);
a_L2=to_LIST(a_1231)->aupb;
a_1254(a_1247);
a_1247=a_L2;
to_LIST(a_1303)->offset[a_L1-1]=to_LIST(a_1231)->aupb;
a_G13:{ if(a_1459==16777439){ goto a_G14;}
 if(a_1459==16777459){ goto a_G16;}
 if(a_1459==16777471){ goto a_G19;}
 if(a_1459==16777269||a_1459==16777291){ goto a_G23;}
 if(a_1459==16777231){ goto a_G31;}
 if(a_1459==16777436||a_1459==16777421||a_1459==16777445||a_1459==16777418||a_1459==16777400||a_1459==16777430||a_1459==16777451||a_1459==16777415||a_1459==16777427||a_1459==16777406){  goto a_G39;}
  goto a_G7;}
a_G14:a_1466();
a_1254(16777439); return;
a_G16:a_1254(16777459);
a_1254(a_1460);
a_G18:a_1466(); goto a_G13;
a_G19:a_L1=a_1460;
a_P[0]=a_L1;a_1246(a_P);a_L1=a_P[0];
a_1254(a_L1);
a_1237(a_L1,0); goto a_G18;
a_G23:a_1254(a_1459);
a_1466();
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466();
a_P[0]=a_L1;a_1246(a_P);a_L1=a_P[0];
a_1254(a_L1);
a_1238(a_L1); goto a_G13;
a_G31:a_1254(a_1459);
a_1466();
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466();
a_P[0]=a_L1;a_1246(a_P);a_L1=a_P[0];
a_1254(a_L1);
a_1236(a_L1); goto a_G13;
a_G39:a_1254(a_1459); goto a_G18;
} /* readexpression */
static a_word a_1230(a_word a_F1){ /* E+>a */

if(!a_equal(to_LIST(a_1231)->offset[a_1240],a_F1)){ return 0;}
a_incr(a_1240); return 1;
} /* E */
static a_word a_1232(a_word a_A[1]){ /* Eitem+a> */

a_A[0]=to_LIST(a_1231)->offset[a_1240];
if(!a_was(a_1303,a_A[0])){ return 0;}
a_incr(a_1240); return 1;
} /* Eitem */
static a_word a_1233(a_word a_F1,a_word a_A[2]){ /* Eop+>a+a>+a> */

a_A[0]=to_LIST(a_1231)->offset[a_1240];
{ if(a_A[0]==16777451){ goto a_G3;}
 if(a_A[0]==16777400){ goto a_G6;}
 if(a_A[0]==16777430){ goto a_G8;}
 if(a_A[0]==16777436||a_A[0]==16777421){ goto a_G10;}
 if(a_A[0]==16777418||a_A[0]==16777445){  goto a_G12;}
  return 0;}
a_G3:if(!a_equal(a_F1,0)){ return 0;}
a_A[1]=1;
a_G5:a_incr(a_1240); return 1;
a_G6:if(!a_lseq(a_F1,1)){ return 0;}
a_A[1]=2; goto a_G5;
a_G8:if(!a_lseq(a_F1,2)){ return 0;}
a_A[1]=3; goto a_G5;
a_G10:if(!a_lseq(a_F1,3)){ return 0;}
a_A[1]=4; goto a_G5;
a_G12:if(!a_lseq(a_F1,4)){ return 0;}
a_A[1]=5; goto a_G5;
} /* Eop */
static void a_1253(a_word a_F1,a_word a_F2,a_word a_F3){ /* optor+>a+>a+>a */

 static const char *a_rulename="optor";
{ if(a_F1==16777451){ goto a_G2;}
 if(a_F1==16777400){ goto a_G3;}
 if(a_F1==16777430){ goto a_G4;}
 if(a_F1==16777436){ goto a_G5;}
 if(a_F1==16777421){ goto a_G6;}
 if(a_F1==16777445){ goto a_G7;}
 if(!(a_F1==16777418)){a_area_failed(a_rulename,a_F1);}
  goto a_G8;}
a_G2:a_1036(1,a_F2,a_F3); return;
a_G3:a_1036(2,a_F2,a_F3); return;
a_G4:a_1036(3,a_F2,a_F3); return;
a_G5:a_1036(6,a_F2,a_F3); return;
a_G6:a_1036(7,a_F2,a_F3); return;
a_G7:a_1036(8,a_F2,a_F3); return;
a_G8:a_1036(9,a_F2,a_F3); return;
} /* optor */
static a_word a_1248(a_word a_A[1]){ /* loosebase+a> */
a_word a_P[1];
if(!a_1230(16777427)){ goto a_G4;}
if(!a_1251(0,a_P)){ return 0;}a_A[0]=a_P[0];
if(!a_1230(16777406)){ return 0;} return 1;
a_G4:if(!a_1230(16777459)){ goto a_G7;}
a_1011(0,to_LIST(a_1231)->offset[a_1240],a_P);a_A[0]=a_P[0];
a_G6:a_incr(a_1240); return 1;
a_G7:if(!a_1230(16777415)){ goto a_G10;}
if(!a_1248(a_P)){ return 0;}a_A[0]=a_P[0];
a_1036(4,a_A[0],a_A[0]); return 1;
a_G10:if(!a_1230(16777421)){ goto a_G13;}
if(!a_1248(a_P)){ return 0;}a_A[0]=a_P[0];
a_1036(5,a_A[0],a_A[0]); return 1;
a_G13:if(!a_1230(16777231)){ goto a_G16;}
a_1325(to_LIST(a_1231)->offset[a_1240],a_P);a_A[0]=a_P[0];
a_1011(1,a_A[0],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G16:if(!a_1232(a_P)){ return 0;}a_A[0]=a_P[0];
a_P[0]=a_A[0];a_1246(a_P);a_A[0]=a_P[0];
if(!a_equal(to_LIST(a_1303)->offset[a_A[0]-6],16777304)){ return 0;}
a_1249(a_A[0]);
if(!a_1341(a_A[0],32)){ return 0;}
a_1011(0,to_LIST(a_1303)->offset[a_A[0]],a_P);a_A[0]=a_P[0]; return 1;
} /* loosebase */
static a_word a_1251(a_word a_F1,a_word a_A[1]){ /* looseexpr+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
if(!a_1248(a_P)){ return 0;}a_A[0]=a_P[0];
a_G2:if(!a_1233(a_F1,a_P)){ return 1;}a_L3=a_P[0];a_L4=a_P[1];
if(!a_1251(a_L4,a_P)){ goto a_G5;}a_L5=a_P[0];
a_1253(a_L3,a_L5,a_A[0]); goto a_G2;
a_G5:a_1023(a_A[0]); return 0;
} /* looseexpr */
static void a_1256(a_word a_F1,a_word a_F2){ /* setfinalvalue+>a+>a */

a_1313(a_F2,64);
to_LIST(a_1303)->offset[a_F2]=a_F1;
a_1372(a_F2,32); return;
} /* setfinalvalue */
static void a_1249(a_word a_F1){ /* looseeval+>a */
a_word a_L2;a_word a_L3;a_word a_P[3];
if(!a_1341(a_F1,8)){ goto a_G3;}
a_1425(a_1001,2130706131); return;
a_G3:if(a_1341(a_F1,32)){ return;}
if(!a_1341(a_F1,64)){ goto a_G8;}
a_P[0]=2019445328;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_P[2]=a_F1;a_1421(3,a_P);
a_1009(a_P);a_L3=a_P[0];
a_1256(a_L3,a_F1); return;
a_G8:a_1372(a_F1,64);
a_L2=a_1240;
a_1240=to_LIST(a_1303)->offset[a_F1-1];
a_incr(a_1240);
if(a_was(a_1231,a_1240)){ goto a_G14;}
a_1420(a_1001,2130706131); return;
a_G14:if(!a_1251(0,a_P)){ goto a_G17;}a_L3=a_P[0];
a_1017(a_L3,a_P);a_L3=a_P[0];
a_1256(a_L3,a_F1); goto a_G18;
a_G17:a_1313(a_F1,64);
a_G18:a_1240=a_L2; return;
} /* looseeval */
static void a_1250(void){ /* looseevaluation */
a_word a_L1;
if(a_1442()){ return;}
a_L1=a_1247;
a_G3:if(a_equal(a_L1,0)){ return;}
a_1249(to_LIST(a_1231)->offset[a_L1]);
a_incr(a_L1);
a_L1=to_LIST(a_1231)->offset[a_L1]; goto a_G3;
} /* looseevaluation */
static void a_1245(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* getexprlimit+>a+>a+a> */
a_word a_P[1];
a_P[0]=a_F2;a_1246(a_P);a_F2=a_P[0];
if(!a_equal(a_F1,16777269)){ goto a_G4;}
a_1335(a_F2,a_P);a_A[0]=a_P[0]; goto a_G5;
a_G4:a_1336(a_F2,a_P);a_A[0]=a_P[0];
a_G5:a_1011(0,a_A[0],a_P);a_A[0]=a_P[0]; return;
} /* getexprlimit */
static void a_1241(a_word a_A[1]){ /* finalbase+a> */
a_word a_P[1];
if(!a_1230(16777427)){ goto a_G4;}
a_1244(0,a_P);a_A[0]=a_P[0];
if(!a_1230(16777406)){ return;} return;
a_G4:if(!a_1230(16777459)){ goto a_G7;}
a_1011(0,to_LIST(a_1231)->offset[a_1240],a_P);a_A[0]=a_P[0];
a_G6:a_incr(a_1240); return;
a_G7:if(!a_1230(16777415)){ goto a_G10;}
a_1241(a_P);a_A[0]=a_P[0];
a_1036(4,a_A[0],a_A[0]); return;
a_G10:if(!a_1230(16777421)){ goto a_G13;}
a_1241(a_P);a_A[0]=a_P[0];
a_1036(5,a_A[0],a_A[0]); return;
a_G13:if(!a_1230(16777231)){ goto a_G16;}
a_1325(to_LIST(a_1231)->offset[a_1240],a_P);a_A[0]=a_P[0];
a_1011(1,a_A[0],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G16:if(!a_1230(16777269)){ goto a_G18;}
a_1245(16777269,to_LIST(a_1231)->offset[a_1240],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G18:if(!a_1230(16777291)){ goto a_G20;}
a_1245(16777291,to_LIST(a_1231)->offset[a_1240],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G20:if(!a_1232(a_P)){ goto a_G24;}a_A[0]=a_P[0];
a_P[0]=a_A[0];a_1246(a_P);a_A[0]=a_P[0];
a_1242(a_A[0]);
a_1011(0,to_LIST(a_1303)->offset[a_A[0]],a_P);a_A[0]=a_P[0]; return;
a_G24:a_1420(a_1001,2130706126); return;
} /* finalbase */
static void a_1244(a_word a_F1,a_word a_A[1]){ /* finalexpr+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
a_1241(a_P);a_A[0]=a_P[0];
a_G2:if(!a_1233(a_F1,a_P)){ return;}a_L3=a_P[0];a_L4=a_P[1];
a_1244(a_L4,a_P);a_L5=a_P[0];
a_1253(a_L3,a_L5,a_A[0]); goto a_G2;
} /* finalexpr */
static void a_1242(a_word a_F1){ /* finaleval+>a */
a_word a_L2;a_word a_L3;a_word a_P[3];
if(!a_1341(a_F1,8)){ goto a_G3;}
a_1425(a_1001,2130706121); return;
a_G3:if(a_1341(a_F1,32)){ return;}
if(!a_1341(a_F1,64)){ goto a_G8;}
a_P[0]=2019445328;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_P[2]=a_F1;a_1421(3,a_P);
a_1009(a_P);a_L2=a_P[0];
a_1256(a_L2,a_F1); return;
a_G8:a_1372(a_F1,64);
a_L3=a_1240;
a_1240=to_LIST(a_1303)->offset[a_F1-1];
a_incr(a_1240);
if(a_was(a_1231,a_1240)){ goto a_G14;}
a_1420(a_1001,2130706121); return;
a_G14:a_1244(0,a_P);a_L2=a_P[0];
a_1017(a_L2,a_P);a_L2=a_P[0];
a_1256(a_L2,a_F1);
a_1240=a_L3; return;
} /* finaleval */
static void a_1243(void){ /* finalevaluation */
a_word a_L1;
a_L1=a_1247;
a_G2:if(a_equal(a_L1,0)){ goto a_G6;}
a_1242(to_LIST(a_1231)->offset[a_L1]);
a_incr(a_L1);
a_L1=to_LIST(a_1231)->offset[a_L1]; goto a_G2;
a_G6:a_1247=0;
a_release(a_1231); return;
} /* finalevaluation */
static void a_1258(a_word a_F1,a_word a_A[1]){ /* storenumstring+>a+a> */
a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1445)->aupb;
a_previous(a_1449,a_F1);
a_unpackstring(a_1449,a_F1,a_1445);
a_1006(0,a_L3,a_P);a_A[0]=a_P[0];
a_unstackto(a_1445,a_L3); return;
} /* storenumstring */
static a_word a_1257(a_word a_F1,a_word a_F2){ /* splitvirtualspace+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[1];
a_1258(155851697,a_P);a_L3=a_P[0];
a_1258(155851704,a_P);a_L4=a_P[0];
a_1011(0,a_L3,a_P);a_1234=a_P[0];
a_1011(0,a_L4,a_P);a_1235=a_P[0];
a_1011(0,a_L3,a_P);a_L5=a_P[0];
a_1036(7,a_L5,a_1235);
a_1011(1,a_F1,a_P);a_L5=a_P[0];
a_1036(7,a_L5,a_1235);
a_1011(1,a_F2,a_P);a_L5=a_P[0];
a_1036(9,a_L5,a_1235);
if(!a_1034(12,a_1235)){ return 0;} return 1;
} /* splitvirtualspace */
static void a_1252(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[2]){ /* nextvirtualblock+>a+>a+>a+a>+a> */
a_word a_L6;a_word a_L7;a_word a_P[1];
a_1011(1,a_F1,a_P);a_L6=a_P[0];
a_1011(2,a_1234,a_P);a_L7=a_P[0];
a_1036(6,a_L7,a_L6);
a_1017(a_L6,a_P);a_A[0]=a_P[0];
a_1011(1,a_F2,a_P);a_L6=a_P[0];
a_1036(6,a_L6,a_1234);
a_1011(2,a_1235,a_P);a_L7=a_P[0];
a_1011(1,a_F3,a_P);a_L6=a_P[0];
a_1036(8,a_L7,a_L6);
a_1036(6,a_L6,a_1234);
a_1011(2,a_1234,a_P);a_L6=a_P[0];
a_1017(a_L6,a_P);a_A[1]=a_P[0];
a_1011(1,a_F1,a_P);a_L6=a_P[0];
a_1036(6,a_L6,a_1234); return;
} /* nextvirtualblock */
static void a_1239(void){ /* clearvirtualspace */

a_1023(a_1234);
a_1234=0;
a_1023(a_1235);
a_1235=0; return;
} /* clearvirtualspace */
static void a_1259(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* virtualaddressoffset+>a+>a+a> */
a_word a_L4;a_word a_L5;a_word a_P[1];
a_1011(1,a_F2,a_P);a_L5=a_P[0];
a_1011(0,a_F1,a_P);a_L4=a_P[0];
a_1036(6,a_L5,a_L4);
a_1017(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* virtualaddressoffset */
static void a_1279(a_word a_A[1]){ /* getitemdef+>a> */

if(!a_1341(a_A[0],8)){ return;}
a_A[0]=to_LIST(a_1303)->offset[a_A[0]]; return;
} /* getitemdef */
static void a_1296(void){ /* skipentry */

a_G1:if(!a_equal(16777439,a_1459)){ goto a_G3;}
a_1466(); return;
a_G3:if(!a_equal(16777486,a_1459)){ goto a_G6;}
a_1466();
a_1420(a_1001,2130706241); return;
a_G6:a_1466(); goto a_G1;
} /* skipentry */
static void a_1295(void){ /* skipdatasection */

a_G1:if(!a_equal(16777254,a_1459)){ goto a_G4;}
a_G2:a_1466();
a_1296(); goto a_G1;
a_G4:if(a_equal(16777236,a_1459)){ goto a_G2;}
if(a_equal(16777266,a_1459)){ goto a_G2;}
if(a_equal(16777250,a_1459)){ goto a_G2;}
if(a_equal(16777224,a_1459)){ goto a_G2;}
if(a_equal(16777258,a_1459)){ goto a_G2;}
if(a_equal(16777246,a_1459)){ goto a_G2;}
if(a_equal(a_1459,16777285)){ return;}
a_1420(a_1001,2130706236); return;
} /* skipdatasection */
static void a_1269(void){ /* datasectioni */

if(a_1442()){ return;}
a_G2:if(!a_equal(16777254,a_1459)){ goto a_G5;}
a_1466();
a_1297(); goto a_G2;
a_G5:if(!a_equal(16777236,a_1459)){ goto a_G8;}
a_1466();
a_1255(); goto a_G2;
a_G8:if(!a_equal(16777266,a_1459)){ goto a_G11;}
a_1466();
a_1281(); goto a_G2;
a_G11:if(!a_equal(16777250,a_1459)){ goto a_G14;}
a_1466();
a_1274(); goto a_G2;
a_G14:if(!a_equal(16777224,a_1459)){ goto a_G17;}
a_G15:a_1466();
a_1296(); goto a_G2;
a_G17:if(a_equal(16777258,a_1459)){ goto a_G15;}
if(a_equal(16777246,a_1459)){ goto a_G15;}
if(a_equal(a_1459,16777285)){ return;}
a_1420(a_1001,2130706230); return;
} /* datasectioni */
static void a_1266(a_word a_F1){ /* checklisttype+>a */

{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G3;}
}
if(!a_1341(a_F1,24)){ return;}
a_G3:a_1420(a_1001,2130706224); return;
} /* checklisttype */
static void a_1262(a_word a_F1,a_word a_F2){ /* checkconstanttype+>a+>a */

{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(a_r1==16777335){ goto a_G2;}
 if(a_r1==16777304){  goto a_G3;}
  goto a_G4;}
a_G2:if(a_equal(a_F2,1)){ goto a_G4;}
a_G3:if(!a_1341(a_F1,24)){ return;}
a_G4:a_1420(a_1001,2130706218); return;
} /* checkconstanttype */
static void a_1264(a_word a_F1){ /* checkfillconstanttype+>a */

{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(a_r1==16777335){ goto a_G2;}
 if(a_r1==16777304){  return;}
  goto a_G3;}
a_G2:if(!a_1341(a_F1,24)){ return;}
a_G3:a_1420(a_1001,2130706211); return;
} /* checkfillconstanttype */
static void a_1263(a_word a_F1){ /* checkfiletype+>a */

{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(!(a_r1==16777340||a_r1==16777345)){ goto a_G3;}
}
if(!a_1341(a_F1,24)){ return;}
a_G3:a_1420(a_1001,2130706203); return;
} /* checkfiletype */
static void a_1274(void){ /* fileentry */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706161); return;
a_G5:a_1263(a_L1);
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L2=a_1460;
a_1466();
if(a_equal(a_L2,1)){ goto a_G11;}
if(!a_equal(a_L2,3)){ goto a_G12;}
a_G11:a_1372(a_L1,32);
a_G12:if(a_equal(a_L2,2)){ goto a_G14;}
if(!a_equal(a_L2,3)){ goto a_G15;}
a_G14:a_1372(a_L1,64);
a_G15:a_1360(a_L1);
if(!a_equal(16777439,a_1459)){ goto a_G4;}

a_1466();
a_L3=0;
a_G20:a_incr(a_L3);
a_1326(a_L1,a_L3,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
a_P[0]=a_L2;a_1279(a_P);a_L2=a_P[0];
a_1266(a_L2); goto a_G20;
} /* fileentry */
static void a_1297(void){ /* skipfill */
a_word a_L1;a_word a_P[1];
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706161); return;
a_G5:a_P[0]=a_L1;a_1279(a_P);a_L1=a_P[0];
a_1266(a_L1);
if(!a_equal(16777455,a_1459)){ goto a_G4;}

a_1466();
a_1290(a_L1);
a_G11:if(!a_equal(16777439,a_1459)){ goto a_G13;}
a_1466(); return;
a_G13:a_1299();
a_1300(a_L1);
a_1298(a_L1); goto a_G11;
} /* skipfill */
static void a_1265(void){ /* checkfillitem */
a_word a_L1;
if(!a_equal(16777459,a_1459)){ goto a_G3;}
a_1466(); return;
a_G3:if(!a_equal(16777471,a_1459)){ goto a_G6;}
a_L1=a_1460;
a_1466(); goto a_G7;
a_G6:a_1420(a_1001,2130706161); return;
a_G7:a_1264(a_L1); return;
} /* checkfillitem */
static void a_1299(void){ /* skipfillitem */

if(!a_equal(16777427,a_1459)){ goto a_G6;}
a_1466();
a_G3:if(!a_equal(16777406,a_1459)){ goto a_G5;}
a_1466(); return;
a_G5:a_1265(); goto a_G3;
a_G6:a_1265(); return;
} /* skipfillitem */
static void a_1300(a_word a_F1){ /* skipfillrepeater+>a */
a_word a_L2;a_word a_L3;a_word a_P[4];
if(!a_equal(16777445,a_1459)){ return;}
a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G9;}
a_L3=a_1460;
a_1466();
if(!a_lseq(1,a_L3)){ goto a_G8;}
if(a_lseq(a_L3,1000)){ return;}
a_G8:a_P[0]=2019445344;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_P[2]=a_L3;a_P[3]=1000;a_1421(4,a_P); return;
a_G9:if(!a_equal(16777471,a_1459)){ goto a_G12;}
a_L2=a_1460;
a_1466(); goto a_G13;
a_G12:a_1420(a_1001,2130706161); return;
a_G13:a_1262(a_L2,1); return;
} /* skipfillrepeater */
static void a_1298(a_word a_F1){ /* skipfillinitializer+>a */
a_word a_L2;
a_G1:if(!a_equal(16777409,a_1459)){ return;}
a_1466();
if(!a_equal(16777471,a_1459)){ goto a_G6;}
a_L2=a_1460;
a_1466(); goto a_G7;
a_G6:a_1420(a_1001,2130706161); return;
a_G7:if(a_1341(a_L2,16)){ goto a_G10;}
if(a_noteq(to_LIST(a_1303)->offset[a_L2-6],16777335)){ goto a_G10;}
if(!a_is(to_LIST(a_1303)->offset[a_L2-1])){ goto a_G11;}
a_G10:a_1420(a_1001,2130706197); return;
a_G11:to_LIST(a_1303)->offset[a_L2-1]=a_F1; goto a_G1;
} /* skipfillinitializer */
static void a_1290(a_word a_F1){ /* rememberlist+>a */
a_word a_L2;a_word a_P[1];
a_1330(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return;}
a_1356(a_F1,a_1280);
a_1280=a_F1; return;
} /* rememberlist */
static void a_1281(void){ /* listentry */
a_word a_L1;a_word a_L2;a_word a_L3;
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706161); return;
a_G5:a_1266(a_L1);
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L2=a_1460;
a_1466();
{ if(a_L2==0||a_L2==1||a_L2==2){ goto a_G10;}
 if(a_L2==3||a_L2==4){  goto a_G13;}
  goto a_G17;}
a_G10:if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L3=a_1460;
a_1466(); goto a_G18;
a_G13:if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L3=a_1460;
a_1466();
a_1262(a_L3,1); goto a_G18;
a_G17:a_1420(a_1001,2130706190); return;
a_G18:a_1358(a_L1,a_L2);
a_1357(a_L1,a_L3);
a_1290(a_L1);
if(!a_equal(16777439,a_1459)){ goto a_G4;}

a_1466(); return;
} /* listentry */
static void a_1282(void){ /* loosebounds */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_L1=a_1280;
a_G2:if(a_equal(a_L1,-1)){ return;}
a_1336(a_L1,a_P);a_L2=a_P[0];
a_1335(a_L1,a_P);a_L3=a_P[0];
a_1357(a_L1,0);
{ if(a_L2==1){ goto a_G7;}
 if(a_L2==2){ goto a_G8;}
 if(a_L2==3){ goto a_G9;}
 if(a_L2==4){  goto a_G11;}
  goto a_G13;}
a_G7:a_1289(a_L3,a_L1); goto a_G14;
a_G8:a_1276(a_L3,a_L1); goto a_G14;
a_G9:a_1278(a_L3,a_L1,a_P);a_L4=a_P[0];
a_1289(a_L4,a_L1); goto a_G14;
a_G11:a_1278(a_L3,a_L1,a_P);a_L4=a_P[0];
a_1276(a_L4,a_L1); goto a_G14;
a_G13:a_1358(a_L1,0);
a_G14:a_1330(a_L1,a_P);a_L1=a_P[0]; goto a_G2;
} /* loosebounds */
static void a_1289(a_word a_F1,a_word a_F2){ /* relativesize+>a+>a */
a_word a_P[4];
if(a_less(a_F1,1)){ goto a_G3;}
if(!a_more(a_F1,100)){ goto a_G4;}
a_G3:a_P[0]=2019445359;a_P[1]=to_LIST(a_1303)->offset[a_F2-4];a_P[2]=a_F1;a_P[3]=a_F2;a_1441(4,a_P);
a_G4:a_min(100,a_F1);
a_max(1,a_F1);
a_subtr(0,a_F1,a_F1);
a_1358(a_F2,a_F1); return;
} /* relativesize */
static void a_1276(a_word a_F1,a_word a_F2){ /* fixsize+>a+>a */
a_word a_P[4];
if(a_less(a_F1,1)){ goto a_G3;}
if(!a_more(a_F1,100000)){ goto a_G4;}
a_G3:a_P[0]=2019445372;a_P[1]=to_LIST(a_1303)->offset[a_F2-4];a_P[2]=a_F1;a_P[3]=a_F2;a_1441(4,a_P);
a_G4:a_min(100000,a_F1);
a_max(1,a_F1);
a_1358(a_F2,a_F1); return;
} /* fixsize */
static a_word a_1277(a_word a_F1,a_word a_A[1]){ /* getconstvalue+>a+a> */
a_word a_P[1];
a_P[0]=a_F1;a_1279(a_P);a_F1=a_P[0];
if(!a_1341(a_F1,32)){ return 0;}
a_1010(to_LIST(a_1303)->offset[a_F1],a_P);a_A[0]=a_P[0]; return 1;
} /* getconstvalue */
static void a_1278(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* getestimator+>a+>a+a> */
a_word a_P[4];
if(a_1277(a_F1,a_P)){a_A[0]=a_P[0]; return;}
a_A[0]=1;
a_P[0]=2019445384;a_P[1]=to_LIST(a_1303)->offset[a_F2-4];a_P[2]=to_LIST(a_1303)->offset[a_F1-4];a_P[3]=a_F2;a_1421(4,a_P); return;
} /* getestimator */
static void a_1270(void){ /* datasectionii */

if(a_1442()){ return;}
a_G2:if(!a_equal(16777254,a_1459)){ goto a_G5;}
a_1466();
a_1283(); goto a_G2;
a_G5:if(!a_equal(16777236,a_1459)){ goto a_G8;}
a_G6:a_1466();
a_1296(); goto a_G2;
a_G8:if(a_equal(16777266,a_1459)){ goto a_G6;}
if(a_equal(16777250,a_1459)){ goto a_G6;}
if(!a_equal(16777224,a_1459)){ goto a_G13;}
a_1466();
a_1288(0); goto a_G2;
a_G13:if(!a_equal(16777258,a_1459)){ goto a_G16;}
a_1466();
a_1288(1); goto a_G2;
a_G16:if(!a_equal(16777246,a_1459)){ goto a_G19;}
a_1466();
a_1273(); goto a_G2;
a_G19:if(a_equal(a_1459,16777285)){ return;}
a_1425(a_1001,2130706185); return;
} /* datasectionii */
static void a_1273(void){ /* externalentry */
a_word a_L1;a_word a_L2;
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706161); return;
a_G5:if(!a_equal(16777483,a_1459)){ goto a_G4;}
a_L2=a_1460;
a_1466();
if(!a_equal(16777439,a_1459)){ goto a_G4;}

a_1466();
if(a_1341(a_L1,16)){ goto a_G13;}
a_G12:a_1420(a_1001,2130706179); return;
a_G13:if(a_1341(a_L1,8)){ goto a_G12;}
{register a_word a_r1=to_LIST(a_1303)->offset[a_L1-6];
 if(a_r1==16777349||a_r1==16777304||a_r1==16777309){ goto a_G15;}
 if(a_r1==16777340||a_r1==16777345){ goto a_G16;}
 if(a_r1==16777318||a_r1==16777322){  goto a_G17;}
  goto a_G12;}
a_G15:to_LIST(a_1303)->offset[a_L1]=a_L2; return;
a_G16:to_LIST(a_1303)->offset[a_L1-1]=a_L2; return;
a_G17:a_1357(a_L1,a_L2); return;
} /* externalentry */
static void a_1288(a_word a_F1){ /* readmatter+>a */
a_word a_L2;
if(!a_equal(16777483,a_1459)){ goto a_G4;}
a_L2=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706161); return;
a_G5:if(!a_equal(16777439,a_1459)){ goto a_G4;}

a_1466();
a_1306(a_F1,a_L2); return;
} /* readmatter */
static void a_1283(void){ /* loosefill */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706161); return;
a_G5:a_P[0]=a_L1;a_1279(a_P);a_L1=a_P[0];
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L2=a_1460;
a_1466();
a_G9:if(!a_equal(16777439,a_1459)){ goto a_G11;}
a_1466(); return;
a_G11:a_1284(a_P);a_L3=a_P[0];
a_add(a_L3,a_1275,a_1275);
a_1286(a_L1,a_L2,a_L3);
a_1285(a_L1); goto a_G9;
} /* loosefill */
static void a_1284(a_word a_A[1]){ /* loosefillitem+a> */

if(!a_equal(16777427,a_1459)){ goto a_G12;}
a_1466();
a_A[0]=0;
a_G4:if(!a_equal(16777406,a_1459)){ goto a_G6;}
a_1466(); return;
a_G6:if(!a_equal(16777459,a_1459)){ goto a_G9;}
a_G7:a_1466();
a_incr(a_A[0]); goto a_G4;
a_G9:if(!a_equal(16777471,a_1459)){ goto a_G11;}
 goto a_G7;
a_G11:a_1420(a_1001,2130706161); return;
a_G12:if(!a_equal(16777459,a_1459)){ goto a_G15;}
a_G13:a_1466();
a_A[0]=1; return;
a_G15:if(!a_equal(16777471,a_1459)){ goto a_G11;}
 goto a_G13;
} /* loosefillitem */
static void a_1291(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]){ /* repeatervalue+>a+>a+>a+a> */
a_word a_P[6];
if(!a_1277(a_F3,a_P)){ goto a_G6;}a_A[0]=a_P[0];
if(!a_lseq(1,a_A[0])){ goto a_G4;}
if(a_lseq(a_A[0],1000)){ return;}
a_G4:a_P[0]=2019445417;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_P[2]=a_F2;a_P[3]=a_A[0];a_P[4]=to_LIST(a_1303)->offset[a_F3-4];a_P[5]=1000;a_1421(6,a_P);
a_A[0]=1; return;
a_G6:a_A[0]=1;
a_P[0]=2019445398;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_P[2]=a_F2;a_P[3]=to_LIST(a_1303)->offset[a_F3-4];a_1421(4,a_P); return;
} /* repeatervalue */
static void a_1286(a_word a_F1,a_word a_F2,a_word a_F3){ /* looserepeater+>a+>a+>a */
a_word a_L4;a_word a_L5;a_word a_P[1];
if(!a_equal(16777445,a_1459)){ goto a_G15;}
a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G6;}
a_L5=a_1460;
a_1466(); goto a_G12;
a_G6:if(!a_equal(16777471,a_1459)){ goto a_G9;}
a_L4=a_1460;
a_1466(); goto a_G10;
a_G9:a_1420(a_1001,2130706161); return;
a_G10:a_P[0]=a_L4;a_1279(a_P);a_L4=a_P[0];
a_1291(a_F1,a_F2,a_L4,a_P);a_L5=a_P[0];
a_G12:if(a_equal(a_L5,1)){ goto a_G14;}
a_add(2,a_1275,a_1275);
a_G14:a_mult(a_F3,a_L5,a_F3);
a_G15:a_1328(a_F1,a_P);a_L5=a_P[0];
a_add(a_F3,a_L5,a_L5);
a_1355(a_F1,a_L5); return;
} /* looserepeater */
static void a_1285(a_word a_F1){ /* looseinitializer+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_G1:if(!a_equal(16777409,a_1459)){ return;}
a_1466();
if(!a_equal(16777471,a_1459)){ goto a_G6;}
a_L2=a_1460;
a_1466(); goto a_G7;
a_G6:a_1420(a_1001,2130706161); return;
a_G7:a_1328(a_F1,a_P);a_L3=a_P[0];
to_LIST(a_1303)->offset[a_L2]=a_L3; goto a_G1;
} /* looseinitializer */
static void a_1271(void){ /* datasectioniii */

a_G1:if(!a_equal(16777254,a_1459)){ goto a_G4;}
a_1466();
a_1166(); goto a_G1;
a_G4:if(!a_equal(16777236,a_1459)){ goto a_G7;}
a_G5:a_1466();
a_1296(); goto a_G1;
a_G7:if(a_equal(16777266,a_1459)){ goto a_G5;}
if(a_equal(16777250,a_1459)){ goto a_G5;}
if(a_equal(16777224,a_1459)){ goto a_G5;}
if(a_equal(16777258,a_1459)){ goto a_G5;}
if(a_equal(16777246,a_1459)){ goto a_G5;}
if(a_equal(a_1459,16777285)){ return;}
a_1420(a_1001,2130706173); return;
} /* datasectioniii */
static void a_1267(a_word a_A[2]){ /* collectlistsizeclaims+a>+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[1];
a_A[0]=0;a_A[1]=0;
a_L3=a_1280;
a_G3:if(a_equal(a_L3,-1)){ return;}
a_1325(a_L3,a_P);a_L4=a_P[0];
a_add(a_L4,a_A[0],a_A[0]);
a_1328(a_L3,a_P);a_L4=a_P[0];
a_1336(a_L3,a_P);a_L5=a_P[0];
if(!a_mreq(a_L5,0)){ goto a_G11;}
a_max(a_L5,a_L4);
a_G10:a_add(a_L4,a_A[0],a_A[0]); goto a_G12;
a_G11:a_subtr(a_A[1],a_L5,a_A[1]); goto a_G10;
a_G12:a_1330(a_L3,a_P);a_L3=a_P[0]; goto a_G3;
} /* collectlistsizeclaims */
static void a_1292(void){ /* setlistbounds */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[2];
a_L1=a_1280;
a_G2:if(a_equal(a_L1,-1)){ return;}
a_1325(a_L1,a_P);a_L2=a_P[0];
a_1328(a_L1,a_P);a_L3=a_P[0];
a_1336(a_L1,a_P);a_L4=a_P[0];
if(!a_mreq(a_L4,0)){ goto a_G9;}
a_max(a_L4,a_L3);
a_L4=0; goto a_G10;
a_G9:a_subtr(0,a_L4,a_L4);
a_G10:a_1252(a_L2,a_L3,a_L4,a_P);a_L5=a_P[0];a_L6=a_P[1];
a_1357(a_L1,a_L5);
a_1358(a_L1,a_L6);
a_1330(a_L1,a_P);a_L1=a_P[0]; goto a_G2;
} /* setlistbounds */
static void a_1272(void){ /* distributevirtualaddress */
a_word a_L1;a_word a_L2;a_word a_P[2];
a_1267(a_P);a_L1=a_P[0];a_L2=a_P[1];
if(a_more(a_L2,0)){ goto a_G4;}
a_L2=1;
a_G4:if(!a_1257(a_L1,a_L2)){ goto a_G8;}
a_1292();
a_1239();
a_1268(); return;
a_G8:a_P[0]=2019445426;a_1421(1,a_P); return;
} /* distributevirtualaddress */
static void a_1268(void){ /* computepointerconstants */
a_word a_L1;
a_L1=to_LIST(a_1303)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1303)->aupb)){ return;}
if(!a_equal(to_LIST(a_1303)->offset[a_L1-6],16777335)){ goto a_G5;}
a_1293(a_L1);
a_G5:a_next(a_1303,a_L1); goto a_G2;
} /* computepointerconstants */
static void a_1293(a_word a_F1){ /* setpointervalue+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_L2=to_LIST(a_1303)->offset[a_F1-1];
a_P[0]=a_L2;a_1279(a_P);a_L2=a_P[0];
a_1325(a_L2,a_P);a_L3=a_P[0];
a_1335(a_L2,a_P);a_L4=a_P[0];
a_subtr(to_LIST(a_1303)->offset[a_F1],a_L3,a_L3);
a_1259(a_L4,a_L3,a_P);to_LIST(a_1303)->offset[a_F1]=a_P[0];
a_1372(a_F1,32); return;
} /* setpointervalue */
static void a_1294(a_word a_F1){ /* setreprnumber+>a */
a_word a_L2;a_word a_P[1];
if(!a_1341(a_F1,16)){ goto a_G11;}
{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(a_r1==16777309||a_r1==16777304){ return;}
 if(a_r1==16777349){ goto a_G3;}
 if(a_r1==16777340||a_r1==16777345||a_r1==16777318||a_r1==16777322){  goto a_G8;}
  goto a_G10;}
a_G3:a_1458(to_LIST(a_1303)->offset[a_F1],a_P);a_L2=a_P[0];
if(!a_stringelem(a_1449,a_L2,0,a_P)){ return;}a_L2=a_P[0];
{ if(a_L2==64){ goto a_G6;}
 if((97<=a_L2 && a_L2<=122)||(65<=a_L2 && a_L2<=90)){  return;}
  goto a_G7;}
a_G6:a_1372(a_F1,8192); return;
a_G7:a_1372(a_F1,4096); return;
a_G8:a_incr(a_1287);
to_LIST(a_1303)->offset[a_F1]=a_1287; return;
a_G10:a_1425(a_1001,2130706167); return;
a_G11:{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-6];
 if(a_r1==16777304||a_r1==16777335){ return;}
 if(a_r1==16777309||a_r1==16777314){ goto a_G12;}
 if(a_r1==16777349||a_r1==16777318||a_r1==16777322||a_r1==16777328||a_r1==16777340||a_r1==16777345){  goto a_G8;}
  return;}
a_G12:to_LIST(a_1303)->offset[a_F1-1]=to_LIST(a_1303)->offset[a_F1]; goto a_G8;
} /* setreprnumber */
static void a_1261(void){ /* assignreprnumbers */
a_word a_L1;
a_L1=to_LIST(a_1303)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1303)->aupb)){ return;}
if(!a_1341(a_L1,8)){ goto a_G5;}
a_G4:a_next(a_1303,a_L1); goto a_G2;
a_G5:{register a_word a_r1=to_LIST(a_1303)->offset[a_L1-6];
 if(!(a_r1==16777304||a_r1==16777335||a_r1==16777309||a_r1==16777314||a_r1==16777349||a_r1==16777318||a_r1==16777322||a_r1==16777328||a_r1==16777340||a_r1==16777345)){ goto a_G4;}
}
a_1294(a_L1); goto a_G4;
} /* assignreprnumbers */
static void a_1318(void){ /* expandITEM */

{register a_word *a_r1=a_extension(a_1303,8);a_r1[0]=a_r1[1]=a_r1[2]=a_r1[3]=a_r1[4]=a_r1[6]=a_r1[7]=0;a_r1[5]=-1;to_LIST(a_1303)->aupb+=8;}
  return;
} /* expandITEM */
static a_word a_1341(a_word a_F1,a_word a_F2){ /* isitemflag+>a+>a */
a_word a_L3;
a_booland(to_LIST(a_1303)->offset[a_F1-7],a_F2,a_L3);
if(!a_is(a_L3)){ return 0;} return 1;
} /* isitemflag */
static void a_1372(a_word a_F1,a_word a_F2){ /* setitemflag+>a+>a */

a_boolor(to_LIST(a_1303)->offset[a_F1-7],a_F2,to_LIST(a_1303)->offset[a_F1-7]); return;
} /* setitemflag */
static void a_1313(a_word a_F1,a_word a_F2){ /* clearitemflag+>a+>a */
a_word a_L3;
a_boolinvert(a_F2,a_L3);
a_booland(a_L3,to_LIST(a_1303)->offset[a_F1-7],to_LIST(a_1303)->offset[a_F1-7]); return;
} /* clearitemflag */
static void a_1315(a_word a_A[1]){ /* converttoitem+>a> */

a_addmult(a_A[0],8,a_1352,a_A[0]); return;
} /* converttoitem */
static void a_1354(a_word a_F1){ /* pushAUX+>a */

{register a_word *a_r1=a_extension(a_1302,1);a_r1[0]=a_F1;to_LIST(a_1302)->aupb+=1;}
  return;
} /* pushAUX */
static void a_1325(a_word a_F1,a_word a_A[1]){ /* getcalibre+>a+a> */

a_A[0]=to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]-2]; return;
} /* getcalibre */
static void a_1334(a_word a_F1,a_word a_A[1]){ /* getssel+>a+a> */

a_A[0]=to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]-1]; return;
} /* getssel */
static void a_1336(a_word a_F1,a_word a_A[1]){ /* getvupb+>a+a> */

a_A[0]=to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]-4]; return;
} /* getvupb */
static void a_1335(a_word a_F1,a_word a_A[1]){ /* getvlwb+>a+a> */

a_A[0]=to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]-5]; return;
} /* getvlwb */
static void a_1328(a_word a_F1,a_word a_A[1]){ /* getfill+>a+a> */

a_A[0]=to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]-3]; return;
} /* getfill */
static void a_1330(a_word a_F1,a_word a_A[1]){ /* getlistlink+>a+a> */

a_A[0]=to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]]; return;
} /* getlistlink */
static void a_1357(a_word a_F1,a_word a_F2){ /* putvlwb+>a+>a */

to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]-5]=a_F2; return;
} /* putvlwb */
static void a_1358(a_word a_F1,a_word a_F2){ /* putvupb+>a+>a */

to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]-4]=a_F2; return;
} /* putvupb */
static void a_1355(a_word a_F1,a_word a_F2){ /* putfill+>a+>a */

to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]-3]=a_F2; return;
} /* putfill */
static void a_1356(a_word a_F1,a_word a_F2){ /* putlistlink+>a+>a */

to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]]=a_F2; return;
} /* putlistlink */
static void a_1333(a_word a_F1,a_word a_A[1]){ /* getnumberofformals+>a+a> */

a_A[0]=to_LIST(a_1302)->offset[to_LIST(a_1303)->offset[a_F1-1]-2]; return;
} /* getnumberofformals */
static void a_1329(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* getformal+>a+>a+a> */
a_word a_L4;
a_L4=to_LIST(a_1303)->offset[a_F1-1];
if(!a_mreq(a_F2,to_LIST(a_1302)->offset[a_L4-2])){ goto a_G4;}
a_A[0]=0; return;
a_G4:a_incr(a_L4);
a_add(a_F2,a_L4,a_L4);
a_A[0]=to_LIST(a_1302)->offset[a_L4]; return;
} /* getformal */
static void a_1324(a_word a_F1,a_word a_A[1]){ /* getanchorcount+>a+a> */
a_word a_L3;a_word a_L4;
a_A[0]=0;
a_L3=to_LIST(a_1303)->offset[a_F1-1];
a_L4=to_LIST(a_1302)->offset[a_L3-2];
a_G4:if(a_equal(a_L4,0)){ return;}
a_decr(a_L4);
a_incr(a_L3);
if(!a_equal(to_LIST(a_1302)->offset[a_L3],16777388)){ goto a_G4;}
a_A[0]=a_L4; return;
} /* getanchorcount */
static void a_1306(a_word a_F1,a_word a_F2){ /* addmatter+>a+>a */

{register a_word *a_r1=a_extension(a_1302,3);a_r1[0]=a_F1;a_r1[1]=a_F2;a_r1[2]=a_1350;to_LIST(a_1302)->aupb+=3;}
a_1350=to_LIST(a_1302)->aupb; return;
} /* addmatter */
static a_word a_1331(a_word a_F2,a_word a_A[2]){ /* getmatter+>a>+>a+a> */

if(!a_equal(a_A[0],0)){ goto a_G3;}
a_A[0]=a_1350; goto a_G4;
a_G3:a_A[0]=to_LIST(a_1302)->offset[a_A[0]];
a_G4:if(!a_was(a_1302,a_A[0])){ return 0;}
if(!a_equal(to_LIST(a_1302)->offset[a_A[0]-2],a_F2)){ goto a_G3;}
a_A[1]=to_LIST(a_1302)->offset[a_A[0]-1]; return 1;
} /* getmatter */
static a_word a_1314(a_word a_F1,a_word a_F2){ /* compareformals+>a+>a */
a_word a_L3;
if(!a_equal(to_LIST(a_1302)->offset[a_F1-2],to_LIST(a_1302)->offset[a_F2-2])){ return 0;}
a_L3=to_LIST(a_1302)->offset[a_F1-1];
if(!a_equal(to_LIST(a_1302)->offset[a_F2-1],a_L3)){ return 0;}
a_G4:if(a_equal(a_L3,0)){ return 1;}
a_incr(a_F1);
a_incr(a_F2);
if(!a_equal(to_LIST(a_1302)->offset[a_F1],to_LIST(a_1302)->offset[a_F2])){ return 0;}
a_decr(a_L3); goto a_G4;
} /* compareformals */
static void a_1371(a_word a_F1,a_word a_A[1]){ /* searchformals+>a+>a> */
a_word a_L3;
a_L3=a_1346;
a_G2:if(!a_equal(a_L3,0)){ goto a_G5;}
to_LIST(a_1302)->offset[a_A[0]]=a_1346;
a_1346=a_A[0]; return;
a_G5:if(!a_1314(a_L3,a_A[0])){ goto a_G8;}
a_unstackto(a_1302,a_F1);
a_A[0]=a_L3; return;
a_G8:a_L3=to_LIST(a_1302)->offset[a_L3]; goto a_G2;
} /* searchformals */
static void a_1323(a_word a_F1,a_word a_F2){ /* formalaffixes+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;
a_G1:if(a_equal(a_F2,0)){ return;}
a_decr(a_F2);
if(!a_equal(16777463,a_1459)){ goto a_G6;}
a_L5=a_1460;
a_1466(); goto a_G7;
a_G6:a_1420(a_1001,2130706245); return;
a_G7:a_1354(a_L5);
{ if(a_L5==16777355||a_L5==16777361){ goto a_G9;}
 if(a_L5==16777371||a_L5==16777376||a_L5==16777382||a_L5==16777366||a_L5==16777388||a_L5==16777394){  goto a_G1;}
  goto a_G20;}
a_G9:if(!a_equal(16777455,a_1459)){ goto a_G6;}
a_L3=a_1460;
a_1466();
if(!a_equal(16777455,a_1459)){ goto a_G6;}
a_L4=a_1460;
a_1466();
a_1323(a_F1,a_F2);
a_incr(to_LIST(a_1302)->offset[a_F1-1]);
a_1354(a_L3);
a_incr(to_LIST(a_1302)->offset[a_F1-1]);
a_1354(a_L4); return;
a_G20:a_1420(a_1001,2130706278); return;
} /* formalaffixes */
static void a_1376(a_word a_A[1]){ /* storeformalaffixes+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L2=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706245); return;
a_G5:a_L3=to_LIST(a_1302)->aupb;
{register a_word *a_r1=a_extension(a_1302,3);a_r1[0]=a_r1[1]=a_L2;a_r1[2]=0;to_LIST(a_1302)->aupb+=3;}
a_A[0]=to_LIST(a_1302)->aupb;
a_1323(a_A[0],a_L2);
a_P[0]=a_A[0];a_1371(a_L3,a_P);a_A[0]=a_P[0]; return;
} /* storeformalaffixes */
static void a_1377(a_word a_A[1]){ /* storelistbounds+a> */
a_word a_L2;a_word a_L3;
if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L2=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706245); return;
a_G5:if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L3=a_1460;
a_1466();
{register a_word *a_r1=a_extension(a_1302,6);a_r1[0]=a_r1[1]=a_r1[2]=0;a_r1[3]=a_L2;a_r1[4]=a_L3;a_r1[5]=0;to_LIST(a_1302)->aupb+=6;}
a_A[0]=to_LIST(a_1302)->aupb; return;
} /* storelistbounds */
static void a_1310(a_word a_F1){ /* checkitemID+>a */

if(a_equal(a_F1,to_LIST(a_1303)->aupb)){ return;}
a_1420(a_1001,2130706272); return;
} /* checkitemID */
static void a_1317(void){ /* enteritem */
a_word a_L1;a_word a_P[1];
if(!a_1341(to_LIST(a_1303)->aupb,4)){ return;}
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb]=a_1352;
{register a_word *a_r1=a_extension(a_1302,3);a_r1[0]=to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-5];a_r1[1]=to_LIST(a_1303)->aupb;a_r1[2]=0;to_LIST(a_1302)->aupb+=3;}
a_1457(to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-4],a_P);a_L1=a_P[0];
a_G5:if(!a_equal(a_L1,0)){ goto a_G7;}
a_1467(to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-4],to_LIST(a_1302)->aupb); return;
a_G7:if(!a_equal(to_LIST(a_1302)->offset[a_L1],0)){ goto a_G9;}
to_LIST(a_1302)->offset[a_L1]=to_LIST(a_1302)->aupb; return;
a_G9:a_L1=to_LIST(a_1302)->offset[a_L1]; goto a_G5;
} /* enteritem */
static void a_1361(void){ /* readitem */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
a_1318();
if(!a_equal(16777463,a_1459)){ goto a_G5;}
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-6]=a_1460;
a_1466(); goto a_G6;
a_G5:a_1420(a_1001,2130706245); return;
a_G6:if(!a_equal(16777471,a_1459)){ goto a_G5;}
a_L1=a_1460;
a_1466();
a_1310(a_L1);
if(!a_equal(16777455,a_1459)){ goto a_G5;}
a_L2=a_1460;
a_1466();
a_booland(a_L2,117557020,to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-7]);
if(!a_equal(16777455,a_1459)){ goto a_G5;}
a_L3=a_1460;
a_1466();
if(a_lseq(a_L3,0)){ goto a_G21;}
if(!a_more(a_L3,a_1351)){ goto a_G20;}
a_G19:a_1420(a_1001,2130706267); return;
a_G20:to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-3]=a_L3;
a_G21:{register a_word a_r1=to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-6];
 if(a_r1==16777349){ goto a_G22;}
 if(a_r1==16777322||a_r1==16777318||a_r1==16777328){ goto a_G23;}
 if(a_r1==16777304||a_r1==16777309||a_r1==16777314||a_r1==16777335||a_r1==16777340||a_r1==16777345){  goto a_G24;}
  goto a_G19;}
a_G22:a_1376(a_P);to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-1]=a_P[0]; goto a_G24;
a_G23:a_1377(a_P);to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-1]=a_P[0];
a_G24:if(!a_equal(16777483,a_1459)){ goto a_G5;}
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-5]=a_1460;
a_1466();
if(!a_equal(16777483,a_1459)){ goto a_G5;}
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-4]=a_1460;
a_1466();
a_1317(); return;
} /* readitem */
static void a_1344(void){ /* itemsection */

if(a_1442()){ return;}
a_G2:if(!a_equal(16777439,a_1459)){ goto a_G4;}
a_1466(); return;
a_G4:a_1361(); goto a_G2;
} /* itemsection */
static void a_1374(void){ /* skipitemsection */

a_G1:if(!a_equal(16777439,a_1459)){ goto a_G3;}
a_G2:a_1466(); return;
a_G3:if(a_equal(16777486,a_1459)){ goto a_G2;}
a_1466(); goto a_G1;
} /* skipitemsection */
static void a_1308(void){ /* addstdstring */

a_1337(0);
a_1318();
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-6]=16777318;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-7]=4;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-5]=155851727;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-4]=155851635;
{register a_word *a_r1=a_extension(a_1302,6);a_r1[0]=a_r1[1]=a_r1[2]=0;a_r1[3]=a_r1[4]=1;a_r1[5]=0;to_LIST(a_1302)->aupb+=6;}
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-1]=to_LIST(a_1302)->aupb;
a_1317(); return;
} /* addstdstring */
static void a_1307(void){ /* addshiftaffixrules */
a_word a_P[3];
a_1337(0);
a_1318();
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-7]=33284;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-6]=16777349;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-5]=155851727;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-4]=155851643;
a_P[1]=16777394;a_1305(1,a_P,1,a_P+1);to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-1]=a_P[0];
a_1317();
a_1318();
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-7]=32772;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-6]=16777349;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-5]=155851727;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-4]=155851651;
a_P[1]=16777376;a_P[2]=16777394;a_1305(2,a_P,2,a_P+1);to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-1]=a_P[0];
a_1317(); return;
} /* addshiftaffixrules */
static void a_1305(a_word a_F2,a_word a_A[1],a_word a_C,a_word *a_V){ /* addformalaffixes+a>+>a+@+>a */
a_word a_L4;a_word a_P[1];
a_L4=to_LIST(a_1302)->aupb;
{register a_word *a_r1=a_extension(a_1302,3);a_r1[0]=a_F2;a_r1[1]=a_r1[2]=0;to_LIST(a_1302)->aupb+=3;}
a_A[0]=to_LIST(a_1302)->aupb;
if(a_equal(a_F2,0)){ goto a_G8;}
a_G5:a_1354(a_V[0]);
a_incr(to_LIST(a_1302)->offset[a_A[0]-1]);
if(a_C>1){a_C--;a_V+=1; goto a_G5;} 
a_G8:a_P[0]=a_A[0];a_1371(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* addformalaffixes */
static void a_1304(void){ /* addbuiltinformals */
a_word a_P[5];
a_P[1]=16777361;a_P[2]=16777371;a_P[3]=1;a_P[4]=1;a_1305(2,a_P,4,a_P+1);a_1379=a_P[0];
a_P[1]=16777371;a_P[2]=16777388;a_P[3]=16777376;a_1305(3,a_P,3,a_P+1);a_1349=a_P[0];
a_P[1]=0;a_1305(0,a_P,1,a_P+1);a_1364=a_P[0]; return;
} /* addbuiltinformals */
static a_word a_1343(a_word a_F1){ /* iswaitforitem+>a */

if(!a_equal(to_LIST(a_1303)->offset[a_F1],155851658)){ return 0;}
if(!a_equal(to_LIST(a_1303)->offset[a_F1-6],16777349)){ return 0;}
if(!a_equal(to_LIST(a_1303)->offset[a_F1-1],a_1379)){ return 0;} return 1;
} /* iswaitforitem */
static a_word a_1339(a_word a_F1){ /* isassignitem+>a */

if(!a_equal(to_LIST(a_1303)->offset[a_F1],155851664)){ return 0;}
if(!a_1341(a_F1,16)){ return 0;}
if(!a_equal(to_LIST(a_1303)->offset[a_F1-6],16777349)){ return 0;}
if(!a_equal(to_LIST(a_1303)->offset[a_F1-1],a_1349)){ return 0;} return 1;
} /* isassignitem */
static a_word a_1342(a_word a_F1){ /* isrootitem+>a */

if(!a_equal(to_LIST(a_1303)->offset[a_F1-4],155851670)){ return 0;}
if(!a_equal(to_LIST(a_1303)->offset[a_F1-6],16777349)){ return 0;}
if(!a_equal(to_LIST(a_1303)->offset[a_F1-1],a_1364)){ return 0;}
if(!a_1341(a_F1,16)){ return 1;} return 0;
} /* isrootitem */
static a_word a_1340(a_word a_F1,a_word a_A[1]){ /* isbuiltinrule+>a+a> */

{register a_word a_r1=to_LIST(a_1303)->offset[a_F1-4];
 if(a_r1==155851643){ goto a_G2;}
 if(a_r1==155851651){  goto a_G3;}
  return 0;}
a_G2:a_A[0]=1; return 1;
a_G3:a_A[0]=2; return 1;
} /* isbuiltinrule */
static void a_1360(a_word a_F1){ /* readfileinfo+>a */
a_word a_L2;a_word a_L3;a_word a_L4;
if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L3=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706245); return;
a_G5:if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L4=a_1460;
a_1466();
{register a_word *a_r1=a_extension(a_1302,3);a_r1[0]=0;a_r1[1]=a_L3;a_r1[2]=a_L4;to_LIST(a_1302)->aupb+=3;}
{register a_word a_r1=to_LIST(a_1302)->aupb;a_L2=a_r1;to_LIST(a_1303)->offset[a_F1-1]=a_r1;}
if(!a_equal(16777448,a_1459)){ return;}
a_1466();
a_G12:if(!a_equal(16777403,a_1459)){ goto a_G14;}
a_1466(); return;
a_G14:if(!a_equal(16777471,a_1459)){ goto a_G4;}
a_L3=a_1460;
a_1466();
a_1354(a_L3);
a_incr(to_LIST(a_1302)->offset[a_L2-2]); goto a_G12;
} /* readfileinfo */
static void a_1327(a_word a_F1,a_word a_A[2]){ /* getfiledata+>a+a>+a> */
a_word a_L4;
a_L4=to_LIST(a_1303)->offset[a_F1-1];
a_A[0]=to_LIST(a_1302)->offset[a_L4-1];
a_A[1]=to_LIST(a_1302)->offset[a_L4]; return;
} /* getfiledata */
static void a_1326(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* getfilearea+>a+>a+a> */
a_word a_L4;
a_L4=to_LIST(a_1303)->offset[a_F1-1];
if(!a_more(a_F2,to_LIST(a_1302)->offset[a_L4-2])){ goto a_G4;}
a_A[0]=0; return;
a_G4:a_add(a_L4,a_F2,a_L4);
a_A[0]=to_LIST(a_1302)->offset[a_L4]; return;
} /* getfilearea */
static void a_1311(void){ /* checkmainmodule */
a_word a_P[2];
if(!a_is(a_1348)){ goto a_G3;}
a_P[0]=2019445436;a_P[1]=to_LIST(a_1303)->offset[a_1348-6];a_1421(2,a_P); return;
a_G3:a_1348=to_LIST(a_1303)->aupb; return;
} /* checkmainmodule */
static void a_1359(void){ /* readdefinitionlist */
a_word a_L1;a_word a_L2;a_word a_L3;
a_G1:if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L1=a_1460;
a_1466(); goto a_G5;
a_G4:a_1420(a_1001,2130706245); return;
a_G5:if(!a_equal(16777455,a_1459)){ goto a_G4;}
a_L2=a_1460;
a_1466();
if(!a_mreq(a_L2,a_1351)){ goto a_G10;}
a_1351=a_L2; goto a_G11;
a_G10:a_1420(a_1001,2130706262); return;
a_G11:if(!a_equal(16777483,a_1459)){ goto a_G4;}
a_L3=a_1460;
a_1466();
{register a_word *a_r1=a_extension(a_1302,3);a_r1[0]=a_L1;a_r1[1]=a_L2;a_r1[2]=a_L3;to_LIST(a_1302)->aupb+=3;}
if(!a_equal(to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-1],0)){ goto a_G17;}
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-1]=to_LIST(a_1302)->aupb;
a_G17:if(!a_equal(16777439,a_1459)){ goto a_G1;}
a_1466(); return;
} /* readdefinitionlist */
static void a_1347(void){ /* linkmoduleheader */

if(!a_equal(a_1352,0)){ goto a_G3;}
a_1322=to_LIST(a_1303)->aupb; goto a_G4;
a_G3:to_LIST(a_1303)->offset[a_1352]=to_LIST(a_1303)->aupb;
a_G4:a_1352=to_LIST(a_1303)->aupb; return;
} /* linkmoduleheader */
static void a_1337(a_word a_F1){ /* headsection+>a */
a_word a_L2;a_word a_P[1];
if(!a_equal(a_F1,0)){ goto a_G5;}
a_1318();
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-7]=3;
a_1347(); return;
a_G5:a_1318();
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-6]=a_F1;
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-7]=1;
if(!a_equal(16777277,a_1459)){ goto a_G18;}
a_1466();
a_1372(to_LIST(a_1303)->aupb,2);
if(!a_equal(16777483,a_1459)){ goto a_G14;}
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-4]=a_1460;
a_1466(); goto a_G15;
a_G14:a_1420(a_1001,2130706245); return;
a_G15:if(!a_equal(16777483,a_1459)){ goto a_G14;}
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-5]=a_1460;
a_1466(); goto a_G26;
a_G18:if(!a_equal(16777273,a_1459)){ goto a_G25;}
a_1466();
a_1372(to_LIST(a_1303)->aupb,4);
if(!a_equal(16777483,a_1459)){ goto a_G14;}
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-5]=a_1460;
a_1466();
a_1311(); goto a_G26;
a_G25:a_1420(a_1001,2130706255); return;
a_G26:a_1347();
if(!a_equal(16777455,a_1459)){ goto a_G14;}
a_L2=a_1460;
a_1466();
if(a_equal(a_L2,32)){ goto a_G32;}
a_P[0]=2019445448;a_1421(1,a_P);
a_G32:a_1351=0;
a_1359();
to_LIST(a_1303)->offset[to_LIST(a_1303)->aupb-3]=a_1351; return;
} /* headsection */
static void a_1373(void){ /* skipheadsection */

a_G1:if(!a_equal(16777439,a_1459)){ goto a_G3;}
a_1466(); return;
a_G3:a_1466(); goto a_G1;
} /* skipheadsection */
static void a_1370(a_word a_F1,a_word a_F2,a_word a_A[2]){ /* searchforline+>a+>a+a>+a> */

if(a_lseq(a_F2,1)){ goto a_G4;}
if(a_more(a_F2,to_LIST(a_1303)->offset[a_F1-3])){ goto a_G4;}
if(!a_equal(to_LIST(a_1303)->offset[a_F1-1],0)){ goto a_G6;}
a_G4:a_A[0]=0;
a_A[1]=155851727; return;
a_G6:a_F1=to_LIST(a_1303)->offset[a_F1-1];
a_G7:if(!a_lseq(a_F2,to_LIST(a_1302)->offset[a_F1-1])){ goto a_G11;}
a_subtr(a_F2,to_LIST(a_1302)->offset[a_F1-2],a_A[0]);
a_incr(a_A[0]);
a_A[1]=to_LIST(a_1302)->offset[a_F1]; return;
a_G11:a_add(a_F1,3,a_F1); goto a_G7;
} /* searchforline */
static void a_1321(a_word a_F1,a_word a_A[2]){ /* findlineno+>a+a>+a> */
a_word a_P[2];
if(!a_equal(a_1352,0)){ goto a_G4;}
a_A[0]=a_F1;
a_A[1]=155851727; return;
a_G4:a_1370(a_1352,a_F1,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1]; return;
} /* findlineno */
static void a_1320(a_word a_F1,a_word a_A[3]){ /* finditemlineno+>a+a>+a>+a> */
a_word a_L5;a_word a_L6;a_word a_P[2];
a_L5=a_1322;
a_G2:a_L6=to_LIST(a_1303)->offset[a_L5];
if(!a_is(a_L6)){ goto a_G6;}
if(!a_less(a_L6,a_F1)){ goto a_G6;}
a_L5=a_L6; goto a_G2;
a_G6:a_A[2]=to_LIST(a_1303)->offset[a_L5-4];
a_1370(a_L5,to_LIST(a_1303)->offset[a_F1-3],a_P);a_A[0]=a_P[0];a_A[1]=a_P[1]; return;
} /* finditemlineno */
static a_word a_1375(a_word a_F1,a_word a_F2){ /* stacksizemismatch+>a+>a */
a_word a_L3;a_word a_L4;a_word a_P[1];
a_1334(a_F1,a_P);a_L3=a_P[0];
a_1334(a_F2,a_P);a_L4=a_P[0];
if(a_noteq(a_L3,a_L4)){ return 1;}
a_1325(a_F1,a_P);a_L3=a_P[0];
a_1325(a_F2,a_P);a_L4=a_P[0];
if(!a_noteq(a_L3,a_L4)){ return 0;} return 1;
} /* stacksizemismatch */
static a_word a_1378(a_word a_F1,a_word a_F2){ /* unequaltypes+>a+>a */

if(a_equal(a_F1,a_F2)){ return 0;}
if(!a_equal(a_F1,16777335)){ return 1;}
if(!a_equal(a_F2,16777304)){ return 1;} return 0;
} /* unequaltypes */
static a_word a_1338(a_word a_F1,a_word a_F2){ /* incompatibletypes+>a+>a */
a_word a_L3;
a_L3=to_LIST(a_1303)->offset[a_F1-6];
if(a_1378(a_L3,to_LIST(a_1303)->offset[a_F2-6])){ return 1;}
if(!a_equal(a_L3,16777349)){ goto a_G5;}
if(!a_noteq(to_LIST(a_1303)->offset[a_F1-1],to_LIST(a_1303)->offset[a_F2-1])){ return 0;} return 1;
a_G5:if(a_equal(a_L3,16777322)){ goto a_G8;}
if(a_equal(a_L3,16777318)){ goto a_G8;}
if(!a_equal(a_L3,16777328)){ return 0;}
a_G8:if(!a_1375(a_F1,a_F2)){ return 0;} return 1;
} /* incompatibletypes */
static void a_1319(a_word a_F1,a_word a_A[1]){ /* finditemdef+>a+a> */
a_word a_L3;a_word a_L4;a_word a_P[1];
a_L3=to_LIST(a_1303)->offset[a_F1-5];
a_1457(to_LIST(a_1303)->offset[a_F1-4],a_P);a_L4=a_P[0];
a_G3:if(!a_equal(a_L4,0)){ goto a_G5;}
a_A[0]=0; return;
a_G5:if(!a_noteq(to_LIST(a_1302)->offset[a_L4-2],a_L3)){ goto a_G7;}
a_G6:a_L4=to_LIST(a_1302)->offset[a_L4]; goto a_G3;
a_G7:a_A[0]=to_LIST(a_1302)->offset[a_L4-1];
if(!a_1341(a_A[0],4)){ goto a_G6;}
to_LIST(a_1303)->offset[a_F1]=a_A[0]; return;
} /* finditemdef */
static void a_1367(a_word a_F1){ /* scanitem+>a */
a_word a_L2;a_word a_P[4];
if(!a_1341(a_F1,8)){ return;}
a_1319(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ goto a_G5;}
a_P[0]=2019445462;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_P[2]=a_F1;a_1421(3,a_P); return;
a_G5:if(!a_1338(a_L2,a_F1)){ goto a_G7;}
a_P[0]=2019445473;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_P[2]=a_L2;a_P[3]=a_F1;a_1421(4,a_P); return;
a_G7:if(!a_was(a_1303,to_LIST(a_1303)->offset[a_L2])){ goto a_G10;}
a_1372(a_L2,128);
a_1372(to_LIST(a_1303)->offset[a_L2],4); return;
a_G10:a_1425(a_1001,2130706250); return;
} /* scanitem */
static void a_1365(a_word a_A[1]){ /* scanfordefinitions+>a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_G1:a_1309(a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ return;}
if(!a_1341(a_1352,4)){ goto a_G1;}
if(a_1341(a_1352,8)){ goto a_G1;}
a_1372(a_1352,8);
a_A[0]=1;
a_L2=a_1352;
a_G8:a_next(a_1303,a_L2);
if(a_1341(a_L2,1)){ goto a_G1;}
a_1367(a_L2); goto a_G8;
} /* scanfordefinitions */
static void a_1368(a_word a_F1){ /* scanitemfordbledef+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[4];
a_L2=to_LIST(a_1303)->offset[a_F1-5];
a_1457(to_LIST(a_1303)->offset[a_F1-4],a_P);a_L3=a_P[0];
a_G3:if(a_equal(a_L3,0)){ return;}
if(!a_noteq(to_LIST(a_1302)->offset[a_L3-2],a_L2)){ goto a_G6;}
a_G5:a_L3=to_LIST(a_1302)->offset[a_L3]; goto a_G3;
a_G6:a_L4=to_LIST(a_1302)->offset[a_L3-1];
if(a_equal(a_L4,to_LIST(a_1303)->offset[a_F1])){ goto a_G5;}
if(!a_1341(a_L4,4)){ goto a_G5;}
if(!a_1341(to_LIST(a_1303)->offset[a_L4],4)){ goto a_G5;}
a_P[0]=2019445483;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_P[2]=to_LIST(a_1303)->offset[a_F1];a_P[3]=a_L4;a_1421(4,a_P); return;
} /* scanitemfordbledef */
static void a_1366(void){ /* scanfordoubledefinitions */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_G1:a_1309(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(!a_1341(a_1352,4)){ goto a_G1;}
a_L1=a_1352;
a_G5:a_next(a_1303,a_L1);
if(a_1341(a_L1,1)){ goto a_G1;}
if(!a_1341(a_L1,8)){ goto a_G5;}
a_1368(a_L1); goto a_G5;
} /* scanfordoubledefinitions */
static void a_1312(void){ /* cleanupitems */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_G1:a_1309(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(a_1341(a_1352,4)){ goto a_G1;}
a_L1=a_1352;
a_G5:a_next(a_1303,a_L1);
if(a_1341(a_L1,1)){ goto a_G1;}
to_LIST(a_1303)->offset[a_L1-6]=0; goto a_G5;
} /* cleanupitems */
static void a_1369(void){ /* scanlinkedmodules */
a_word a_L1;a_word a_P[1];
if(!a_equal(a_1348,0)){ goto a_G3;}
a_P[0]=2019445454;a_1421(1,a_P); return;
a_G3:a_1337(0);
a_1345=a_1352;
a_G5:a_L1=0;
a_P[0]=a_L1;a_1365(a_P);a_L1=a_P[0];
if(a_is(a_L1)){ goto a_G5;}
if(a_1442()){ goto a_G10;}
a_1366();
a_G10:if(a_1442()){ return;}
a_1312(); return;
} /* scanlinkedmodules */
static void a_1362(a_word a_F1){ /* reportitem+>a */
a_word a_P[3];
if(a_1341(a_F1,128)){ return;}
if(a_1340(a_F1,a_P)){ return;}
if(!a_1341(a_F1,4)){ return;}
a_P[0]=2019445491;a_P[1]=to_LIST(a_1303)->offset[a_F1-4];a_P[2]=a_F1;a_1441(3,a_P); return;
} /* reportitem */
static void a_1363(void){ /* reportnotusedpublicitems */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_G1:if(!a_equal(a_1316,0)){ goto a_G3;}
a_incr(a_1316); return;
a_G3:a_1309(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(!a_1341(a_1352,4)){ goto a_G1;}
a_1410(to_LIST(a_1303)->offset[a_1352-6]);
if(!a_1402()){ goto a_G1;}
a_L1=a_1352;
a_G9:a_next(a_1303,a_L1);
if(a_1341(a_L1,1)){ goto a_G1;}
a_1362(a_L1); goto a_G9;
} /* reportnotusedpublicitems */
static void a_1309(a_word a_A[1]){ /* advancemodbase+a> */

if(!a_equal(a_1352,a_1345)){ goto a_G3;}
a_1352=a_1322; goto a_G4;
a_G3:a_1352=to_LIST(a_1303)->offset[a_1352];
a_G4:if(!a_equal(a_1352,a_1345)){ goto a_G6;}
a_A[0]=0; return;
a_G6:a_1351=to_LIST(a_1303)->offset[a_1352-3];
a_A[0]=1; return;
} /* advancemodbase */
static void a_1353(a_word a_A[1]){ /* opennextmodule+a> */
a_word a_L2;a_word a_P[1];
a_G1:a_1309(a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
if(!a_1341(a_1352,4)){ goto a_G1;}
a_L2=to_LIST(a_1303)->offset[a_1352-6];
a_1407(a_L2);
if(!a_equal(a_L2,0)){ goto a_G8;}
a_A[0]=2; return;
a_G8:a_A[0]=1; return;
} /* opennextmodule */
static void a_1332(a_word a_A[1]){ /* getnextmodulehead+a> */
a_word a_P[1];
a_G1:a_1309(a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
if(!a_1341(a_1352,4)){ goto a_G1;}
a_A[0]=a_1352; return;
} /* getnextmodulehead */
static void a_1301(void){ /* @root */

a_1308();
a_1307();
a_1304(); return;
} /* @root */
static a_word a_1397(a_word a_F1,a_word a_F2){ /* isfileflag+>a+>a */
a_word a_L3;
a_booland(to_LIST(a_1382)->offset[a_F1-2],a_F2,a_L3);
if(!a_is(a_L3)){ return 0;} return 1;
} /* isfileflag */
static void a_1409(a_word a_F1,a_word a_F2){ /* setfileflag+>a+>a */

a_boolor(to_LIST(a_1382)->offset[a_F1-2],a_F2,to_LIST(a_1382)->offset[a_F1-2]); return;
} /* setfileflag */
static void a_1390(a_word a_F1){ /* extendBUFFER+>a */

{register a_word *a_r1=a_extension(a_1445,1);a_r1[0]=a_F1;to_LIST(a_1445)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1391(a_word a_F1){ /* extendFILES+>a */
a_word a_P[2];
a_incr(a_1392);
if(!a_less(a_1392,200)){ goto a_G4;}
{register a_word *a_r1=a_extension(a_1382,3);a_r1[0]=a_r1[1]=0;a_r1[2]=a_F1;to_LIST(a_1382)->aupb+=3;}
  return;
a_G4:a_P[0]=2019445712;a_P[1]=200;a_1423(2,a_P); return;
} /* extendFILES */
static a_word a_1398(a_word a_F1,a_word a_F2){ /* isfirstarg+t[]+>a */
a_word a_L2;a_word a_P[1];
a_comparestring(a_1491,a_1388,a_F1,a_F2,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return 0;} return 1;
} /* isfirstarg */
static void a_1389(void){ /* checkcommandlinearguments */
a_word a_P[3];
a_1388=to_LIST(a_1491)->aupb;
a_1387=1;
a_G3:if(!a_less(a_1388,to_LIST(a_1491)->alwb)){ goto a_G5;}
a_P[0]=2019445691;a_1421(1,a_P); return;
a_G5:if(!a_1398(a_1001,2130706320)){ goto a_G7;}
a_P[0]=2019445605;a_1426(1,a_P); return;
a_G7:if(!a_1398(a_1001,2130706316)){ goto a_G9;}
a_P[0]=2019445675;a_P[1]=1;a_P[2]=0;a_1426(3,a_P); return;
a_G9:if(!a_1398(a_1001,2130706311)){ goto a_G12;}
a_1387=0;
a_G11:a_previousstring(a_1491,a_1388); goto a_G3;
a_G12:if(!a_1398(a_1001,2130706306)){ goto a_G17;}
a_previousstring(a_1491,a_1388);
if(!a_less(a_1388,to_LIST(a_1491)->alwb)){ goto a_G16;}
a_P[0]=2019445700;a_P[1]=111;a_1421(2,a_P); return;
a_G16:a_1412=a_1388; goto a_G11;
a_G17:if(!a_1398(a_1001,2130706303)){ goto a_G22;}
a_previousstring(a_1491,a_1388);
if(!a_less(a_1388,to_LIST(a_1491)->alwb)){ goto a_G21;}
a_P[0]=2019445700;a_P[1]=76;a_1421(2,a_P); return;
a_G21:a_1399=a_1388; goto a_G11;
a_G22:if(!a_1398(a_1001,2130706300)){ goto a_G24;}
a_1363(); goto a_G11;
a_G24:if(!a_1398(a_1001,2130706297)){ return;}
a_1226(); goto a_G11;
} /* checkcommandlinearguments */
static a_word a_1394(a_word a_A[1]){ /* getnextsource+a> */
a_word a_L2;a_word a_P[1];
if(!a_equal(a_1383,0)){ goto a_G3;}
a_1383=to_LIST(a_1382)->alwb; goto a_G4;
a_G3:a_next(a_1382,a_1383);
a_G4:a_A[0]=a_1383;
a_G5:if(!a_lseq(a_A[0],to_LIST(a_1382)->aupb)){ goto a_G8;}
a_G6:a_1396(a_A[0],a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return 1;} goto a_G5;
a_G8:if(!a_lseq(to_LIST(a_1491)->alwb,a_1388)){ goto a_G11;}
a_1391(a_1388);
a_previousstring(a_1491,a_1388); goto a_G6;
a_G11:if(!a_is(a_1387)){ return 0;}
a_1391(155851690);
a_1400=to_LIST(a_1382)->aupb;
a_1387=0; goto a_G6;
} /* getnextsource */
static a_word a_1402(void){ /* notstdlibsource */

if(a_equal(a_1400,0)){ return 1;}
if(a_equal(a_1383,0)){ return 1;}
if(!a_less(a_1383,a_1400)){ return 0;} return 1;
} /* notstdlibsource */
static void a_1393(a_word a_A[1]){ /* geticefile+a> */
a_word a_P[1];
if(a_1416(a_1383,a_P)){a_A[0]=a_P[0]; return;}
a_A[0]=0; return;
} /* geticefile */
static a_word a_1416(a_word a_F1,a_word a_A[1]){ /* wasicesource+>a+a> */

if(!a_was(a_1382,a_F1)){ return 0;}
a_A[0]=to_LIST(a_1382)->offset[a_F1]; return 1;
} /* wasicesource */
static void a_1385(void){ /* addextension */

a_1390(46);
a_1390(105);
a_1390(99);
a_1390(101); return;
} /* addextension */
static void a_1384(void){ /* adddirseparator */

if(a_equal(to_LIST(a_1445)->offset[to_LIST(a_1445)->aupb],47)){ return;}
a_1390(47); return;
} /* adddirseparator */
static void a_1404(a_word a_A[1]){ /* openBUFFER+a> */
a_word a_L2;a_word a_P[1];
a_listlength(a_1445,a_L2);
if(!a_lseq(a_L2,0)){ goto a_G4;}
a_A[0]=1; return;
a_G4:a_packstring(a_1445,a_L2,a_1449);
a_scratch(a_1445);
a_1453();
a_1478(a_P);a_A[0]=a_P[0]; return;
} /* openBUFFER */
static void a_1411(a_word a_F1){ /* stringtoBUFFER+>a */
a_word a_P[1];
if(!a_was(a_1449,a_F1)){ goto a_G4;}
a_1458(a_F1,a_P);a_F1=a_P[0];
a_unpackstring(a_1449,a_F1,a_1445); return;
a_G4:if(!a_was(a_1491,a_F1)){ goto a_G6;}
a_unpackstring(a_1491,a_F1,a_1445); return;
a_G6:a_1425(a_1001,2130706294); return;
} /* stringtoBUFFER */
static a_word a_1403(a_word a_F1,a_word a_A[1]){ /* nthpath+>a+a> */
a_word a_L3;
a_A[0]=to_LIST(a_1445)->alwb;
a_L3=to_LIST(a_1382)->offset[a_F1-1];
if(!a_lseq(a_A[0],to_LIST(a_1445)->aupb)){ return 0;}
a_G4:if(a_lseq(a_L3,1)){ return 1;}
if(!a_lseq(a_A[0],to_LIST(a_1445)->aupb)){ return 0;}
if(!a_equal(to_LIST(a_1445)->offset[a_A[0]],58)){ goto a_G8;}
a_decr(a_L3);
a_G8:a_incr(a_A[0]); goto a_G4;
} /* nthpath */
static a_word a_1408(a_word a_F1){ /* selectpath+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_1403(a_F1,a_P)){ return 0;}a_L2=a_P[0];
if(!a_equal(to_LIST(a_1445)->offset[a_L2],58)){ goto a_G4;}
a_scratch(a_1445); return 1;
a_G4:a_L3=to_LIST(a_1445)->alwb;
a_G5:to_LIST(a_1445)->offset[a_L3]=to_LIST(a_1445)->offset[a_L2];
a_incr(a_L2);
if(a_more(a_L2,to_LIST(a_1445)->aupb)){ goto a_G10;}
if(a_equal(to_LIST(a_1445)->offset[a_L2],58)){ goto a_G10;}
a_incr(a_L3); goto a_G5;
a_G10:a_unstackto(a_1445,a_L3);
a_1384(); return 1;
} /* selectpath */
static void a_1406(a_word a_F1,a_word a_A[1]){ /* openfilefirst+>a+a> */
a_word a_P[1];
a_scratch(a_1445);
if(!a_1397(a_F1,2)){ goto a_G4;}
a_1415(a_F1,a_1399,a_P);a_A[0]=a_P[0]; return;
a_G4:if(!a_1397(a_F1,4)){ goto a_G6;}
a_1415(a_F1,155851684,a_P);a_A[0]=a_P[0]; return;
a_G6:a_1414(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* openfilefirst */
static void a_1415(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* tryopenwithpath+>a+>a+a> */
a_word a_P[1];
to_LIST(a_1382)->offset[a_F1-1]=1;
a_G2:a_1411(a_F2);
if(!a_1408(a_F1)){ goto a_G7;}
a_1414(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_incr(to_LIST(a_1382)->offset[a_F1-1]); goto a_G2;
a_G7:a_A[0]=1; return;
} /* tryopenwithpath */
static void a_1414(a_word a_F1,a_word a_A[1]){ /* tryopen+>a+a> */
a_word a_P[2];
a_1411(to_LIST(a_1382)->offset[a_F1]);
if(!a_1397(a_F1,1)){ goto a_G4;}
a_1385();
a_G4:a_1404(a_P);a_A[0]=a_P[0];
if(!a_equal(a_A[0],0)){ goto a_G7;}
a_1409(a_F1,8); return;
a_G7:if(a_more(a_A[0],0)){ return;}
a_P[0]=2019445721;a_P[1]=a_F1;a_1423(2,a_P); return;
} /* tryopen */
static void a_1405(a_word a_F1){ /* openfileaslast+>a */
a_word a_L2;a_word a_P[2];
if(a_1397(a_F1,8)){ goto a_G3;}
a_1425(a_1001,2130706288); return;
a_G3:a_scratch(a_1445);
if(!a_1397(a_F1,2)){ goto a_G7;}
a_1411(a_1399);
if(a_1408(a_F1)){}
a_G7:if(!a_1397(a_F1,4)){ goto a_G10;}
a_1411(155851684);
if(a_1408(a_F1)){}
a_G10:a_1411(to_LIST(a_1382)->offset[a_F1]);
if(!a_1397(a_F1,1)){ goto a_G13;}
a_1385();
a_G13:a_1404(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
a_P[0]=2019445721;a_P[1]=a_F1;a_1423(2,a_P); return;
} /* openfileaslast */
static void a_1410(a_word a_F1){ /* setsource+>a */

a_1383=a_F1; return;
} /* setsource */
static void a_1407(a_word a_F1){ /* opensource+>a */

if(!a_equal(a_F1,0)){ goto a_G3;}
a_1383=0; return;
a_G3:a_1383=a_F1;
a_1405(a_F1); return;
} /* opensource */
static void a_1413(a_word a_F1,a_word a_A[1]){ /* tryfilefirst+>a+a> */
a_word a_P[1];
to_LIST(a_1382)->offset[a_F1-2]=0;
a_1406(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1409(a_F1,1);
a_1406(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
if(!a_is(a_1399)){ goto a_G14;}
to_LIST(a_1382)->offset[a_F1-2]=2;
a_1406(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1409(a_F1,1);
a_1406(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_G14:to_LIST(a_1382)->offset[a_F1-2]=4;
a_1406(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1409(a_F1,1);
a_1406(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* tryfilefirst */
static void a_1396(a_word a_F1,a_word a_A[1]){ /* handlesourcefile+>a+a> */
a_word a_P[2];
if(!a_1397(a_F1,8)){ goto a_G4;}
a_1405(a_F1);
a_A[0]=0; return;
a_G4:a_1413(a_F1,a_P);a_A[0]=a_P[0];
if(!a_is(a_A[0])){ goto a_G7;}
a_P[0]=2019445721;a_P[1]=a_F1;a_1423(2,a_P); return;
a_G7:if(!a_equal(a_1459,16777273)){ goto a_G9;}
a_1401=a_F1; return;
a_G9:if(!a_equal(a_1459,16777262)){ return;}
a_1386(a_F1);
a_A[0]=1; return;
} /* handlesourcefile */
static void a_1386(a_word a_F1){ /* addincludedicefiles+>a */
a_word a_L2;a_word a_P[2];
if(!a_noteq(a_F1,to_LIST(a_1382)->aupb)){ goto a_G3;}
a_P[0]=2019445732;a_P[1]=a_F1;a_1423(2,a_P); return;
a_G3:a_unstack(a_1382);
a_G4:if(!a_equal(16777262,a_1459)){ goto a_G11;}
a_1466();
if(!a_equal(16777483,a_1459)){ goto a_G9;}
a_L2=a_1460;
a_1466(); goto a_G10;
a_G9:a_1420(a_1001,2130706282); return;
a_G10:a_1391(a_L2); goto a_G4;
a_G11:a_1453(); return;
} /* addincludedicefiles */
static void a_1395(void){ /* gettargetfile */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;
if(!a_is(a_1412)){ goto a_G4;}
a_L5=0;
a_L2=a_1412; goto a_G6;
a_G4:a_L5=1;
a_L2=to_LIST(a_1382)->offset[a_1401];
a_G6:a_L1=to_LIST(a_1445)->aupb;
a_1411(a_L2);
a_L4=to_LIST(a_1445)->aupb;
a_L6=1;
a_G10:if(a_lseq(a_L4,a_L1)){ goto a_G21;}
{register a_word a_r1=to_LIST(a_1445)->offset[a_L4];
 if(a_r1==46){ goto a_G12;}
 if(a_r1==47||a_r1==92||a_r1==58){  goto a_G19;}
  goto a_G20;}
a_G12:if(!a_equal(a_L5,0)){ goto a_G15;}
a_L5=2;
a_G14:a_L4=a_L1; goto a_G21;
a_G15:a_decr(a_L4);
if(!a_is(a_L6)){ goto a_G10;}
a_L6=0;
a_unstackto(a_1445,a_L4); goto a_G10;
a_G19:if(a_equal(a_L5,1)){ goto a_G21;} goto a_G14;
a_G20:a_decr(a_L4); goto a_G10;
a_G21:if(a_equal(a_L5,2)){ goto a_G25;}
a_1390(46);
a_1390(106);
a_1390(115);
a_G25:a_subtr(to_LIST(a_1445)->aupb,a_L4,a_L3);
a_packstring(a_1445,a_L3,a_1449);
a_unstackto(a_1445,a_L1); return;
} /* gettargetfile */
static void a_1431(a_word a_F1){ /* printchar+>a */

a_incr(a_1439);
a_putchar(a_1419,a_F1); return;
} /* printchar */
static void a_1428(void){ /* nlcr */

if(!a_lseq(a_1439,1)){ goto a_G3;}
a_1439=1; return;
a_G3:a_1439=0;
a_1431(10); return;
} /* nlcr */
static void a_1440(a_word a_F1){ /* tabline+>a */

a_G1:if(a_equal(a_1439,a_F1)){ return;}
if(!a_more(a_1439,a_F1)){ goto a_G4;}
a_1428(); goto a_G1;
a_G4:a_1431(32); goto a_G1;
} /* tabline */
static void a_1434(a_word a_F1){ /* printint+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G5;}
a_1431(45);
a_subtr(-1,a_F1,a_F1);
a_1435(a_F1,49); return;
a_G5:if(!a_less(a_F1,0)){ goto a_G8;}
a_1431(45);
a_getabs(a_F1,a_F1);
a_G8:a_1435(a_F1,48); return;
} /* printint */
static void a_1435(a_word a_F1,a_word a_F2){ /* printint1+>a+>a */
a_word a_L3;a_word a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1435(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_1431(a_L4); return;
} /* printint1 */
static void a_1432(a_word a_F1){ /* printform+>a */

a_1433(a_F1,4); return;
} /* printform */
static void a_1433(a_word a_F1,a_word a_F2){ /* printform1+>a+>a */
a_word a_L3;a_word a_L4;
if(a_equal(a_F2,0)){ return;}
a_decr(a_F2);
a_divrem11(a_F1,10,a_L3,a_L4);
a_1433(a_L3,a_F2);
a_add(a_L4,48,a_L4);
a_1431(a_L4); return;
} /* printform1 */
static void a_1429(a_word a_F1,a_word a_F2){ /* print+t[]+>a */
a_word a_L2;
if(!a_was(a_F1,a_F2)){ return;}
a_1488(a_1419,a_F1,a_F2);
a_stringlength(a_F1,a_F2,a_L2);
a_add(a_1439,a_L2,a_1439); return;
} /* print */
static void a_1438(a_word a_F1){ /* printpointer+>a */
a_word a_P[1];
a_G1:if(!a_equal(a_F1,0)){ goto a_G3;}
a_1429(a_1001,2130706351); return;
a_G3:if(a_1416(a_F1,a_P)){a_F1=a_P[0]; goto a_G1;}
if(!a_was(a_1418,a_F1)){ goto a_G6;}
a_1429(a_1418,a_F1); return;
a_G6:if(!a_was(a_1491,a_F1)){ goto a_G8;}
a_1429(a_1491,a_F1); return;
a_G8:if(!a_was(a_1449,a_F1)){ goto a_G11;}
a_1458(a_F1,a_P);a_F1=a_P[0];
a_1429(a_1449,a_F1); return;
a_G11:a_1425(a_1001,2130706347); return;
} /* printpointer */
static void a_1430(a_word a_F1){ /* printbase+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_L2=to_LIST(a_1445)->aupb;
if(!a_was(a_1449,a_F1)){ goto a_G5;}
a_1458(a_F1,a_P);a_F1=a_P[0];
a_unpackstring(a_1449,a_F1,a_1445); goto a_G9;
a_G5:if(!a_was(a_1491,a_F1)){ goto a_G7;}
a_unpackstring(a_1491,a_F1,a_1445); goto a_G9;
a_G7:if(a_equal(a_F1,0)){ goto a_G9;}
a_1425(a_1001,2130706341); return;
a_G9:a_L3=to_LIST(a_1445)->aupb;
a_L4=0;
a_G11:if(a_lseq(a_L3,a_L2)){ goto a_G18;}
if(!a_equal(to_LIST(a_1445)->offset[a_L3],46)){ goto a_G15;}
a_incr(a_L4);
a_G14:a_decr(a_L3); goto a_G11;
a_G15:if(a_equal(to_LIST(a_1445)->offset[a_L3],47)){ goto a_G18;}
if(a_equal(to_LIST(a_1445)->offset[a_L3],92)){ goto a_G18;}
if(!a_equal(to_LIST(a_1445)->offset[a_L3],58)){ goto a_G14;}
a_G18:a_incr(a_L3);
if(a_more(a_L3,to_LIST(a_1445)->aupb)){ goto a_G25;}
if(!a_equal(to_LIST(a_1445)->offset[a_L3],46)){ goto a_G24;}
if(a_lseq(a_L4,1)){ goto a_G25;}
a_decr(a_L4);
a_1431(46); goto a_G18;
a_G24:a_1431(to_LIST(a_1445)->offset[a_L3]); goto a_G18;
a_G25:a_unstackto(a_1445,a_L2); return;
} /* printbase */
static void a_1436(a_word a_F1){ /* printitem+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[3];
a_1320(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];
if(a_lseq(a_L2,0)){ goto a_G4;}
a_1432(a_L2);
a_G4:if(a_equal(a_L3,155851727)){ goto a_G7;}
a_1431(47);
a_1430(a_L3);
a_G7:if(a_equal(a_L4,0)){ return;}
a_1431(32);
a_1429(a_1001,2130706336);
a_1438(a_L4);
a_1431(41); return;
} /* printitem */
static void a_1437(a_word a_F1){ /* printline+>a */
a_word a_L2;a_word a_L3;a_word a_P[2];
a_1321(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];
if(a_lseq(a_L2,0)){ goto a_G4;}
a_1432(a_L2);
a_G4:if(a_equal(a_L3,155851727)){ return;}
a_1431(47);
a_1430(a_L3); return;
} /* printline */
static void a_1424(a_word a_C,a_word *a_V){ /* formatprint+@+>a */
a_word a_L2;a_word a_L3;
a_L2=to_LIST(a_1445)->aupb;
a_unpackstring(a_1418,a_V[0],a_1445);
a_add(a_L2,1,a_L3);
a_G4:if(a_less(to_LIST(a_1445)->aupb,a_L3)){ goto a_G26;}
if(!a_noteq(to_LIST(a_1445)->offset[a_L3],37)){ goto a_G8;}
a_G6:a_1431(to_LIST(a_1445)->offset[a_L3]);
a_G7:a_incr(a_L3); goto a_G4;
a_G8:a_incr(a_L3);
if(!a_less(to_LIST(a_1445)->aupb,a_L3)){ goto a_G11;}
a_1431(37); goto a_G26;
a_G11:{register a_word a_r1=to_LIST(a_1445)->offset[a_L3];
 if(a_r1==112){ goto a_G12;}
 if(a_r1==120){ goto a_G15;}
 if(a_r1==105){ goto a_G17;}
 if(a_r1==99){ goto a_G19;}
 if(a_r1==108){ goto a_G21;}
 if(a_r1==100){ goto a_G23;}
 if(a_r1==110){  goto a_G25;}
  goto a_G6;}
a_G12:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1438(a_V[0]); goto a_G7;
a_G14:a_1429(a_1001,2130706331); goto a_G7;
a_G15:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1429(a_1449,a_V[0]); goto a_G7;
a_G17:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1436(a_V[0]); goto a_G7;
a_G19:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1431(a_V[0]); goto a_G7;
a_G21:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1437(a_V[0]); goto a_G7;
a_G23:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1434(a_V[0]); goto a_G7;
a_G25:a_1431(10); goto a_G7;
a_G26:if(a_C<=1){ goto a_G28;} a_C--;a_V+=1;
a_1429(a_1001,2130706328);
a_G28:a_unstackto(a_1445,a_L2); return;
} /* formatprint */
static a_word a_1442(void){ /* waserror */

if(!a_more(a_1422,0)){ return 0;} return 1;
} /* waserror */
static void a_1427(a_word a_F1){ /* messagehead+>a */
a_word a_L2;a_word a_P[1];
a_1428();
a_1431(a_F1);
a_1431(32);
a_1393(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G7;}
a_1430(a_L2);
a_G7:if(!a_equal(a_F1,70)){ goto a_G10;}
a_1431(47);
a_1432(a_1477);
a_G10:a_1431(32);
a_1440(16); return;
} /* messagehead */
static void a_1421(a_word a_C,a_word *a_V){ /* error+@+>a */
a_word a_P[1];
if(a_mreq(a_1422,51)){ return;}
a_1427(69);
a_1424(a_C,a_V);
a_1428();
a_incr(a_1422);
if(a_less(a_1422,51)){ return;}
a_1427(70);
a_P[0]=2019445747;a_1424(1,a_P);
a_1428(); return;
} /* error */
static void a_1441(a_word a_C,a_word *a_V){ /* warning+@+>a */

if(a_mreq(a_1422,51)){ return;}
a_1427(87);
a_1424(a_C,a_V);
a_1428(); return;
} /* warning */
static void a_1426(a_word a_C,a_word *a_V){ /* message+@+>a */

a_1424(a_C,a_V);
a_1428();
a_incr(a_1422); return;
} /* message */
static void a_1423(a_word a_C,a_word *a_V){ /* fatalerror+@+>a */

a_1427(70);
a_1424(a_C,a_V);
a_1428();
a_1154();
a_exit(15); return;
} /* fatalerror */
static void a_1420(a_word a_F1,a_word a_F2){ /* corrupticefile+t[]+>a */
a_word a_L2;a_word a_P[2];
a_1427(70);
a_1393(a_P);a_L2=a_P[0];
a_P[0]=2019445768;a_P[1]=a_L2;a_1424(2,a_P);
a_1429(a_F1,a_F2);
a_P[0]=2019445773;a_1424(1,a_P);
a_1428();
a_exit(3); return;
} /* corrupticefile */
static void a_1425(a_word a_F1,a_word a_F2){ /* internalerror+t[]+>a */
a_word a_P[1];
a_1427(70);
a_P[0]=2019445755;a_1424(1,a_P);
a_1429(a_F1,a_F2);
a_P[0]=2019445760;a_1424(1,a_P);
a_1428();
a_exit(15); return;
} /* internalerror */
static void a_1456(a_word a_F1){ /* extendBUFFER+>a */

{register a_word *a_r1=a_extension(a_1445,1);a_r1[0]=a_F1;to_LIST(a_1445)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1478(a_word a_A[1]){ /* trytoopensource+a> */
a_word a_L2;
if(!a_openfile(a_1450,114,a_1449,to_LIST(a_1449)->aupb)){ goto a_G8;}
a_A[0]=0;
a_unstackstring(a_1449);
a_1477=1;
a_1452=32;
a_1465();
a_1466(); return;
a_G8:a_unstackstring(a_1449);
a_getfileerror(a_1450,a_L2);
if(!a_equal(a_L2,2)){ goto a_G12;}
a_A[0]=1; return;
a_G12:a_A[0]=-1; return;
} /* trytoopensource */
static void a_1453(void){ /* closesource */

a_closefile(a_1450); return;
} /* closesource */
static void a_1465(void){ /* nextchar */
a_word a_P[1];
a_G1:if(!a_getchar(a_1450,a_P)){ goto a_G4;}a_1452=a_P[0];
{ if(a_1452==10){ goto a_G3;}
 if(a_1452<=31){  goto a_G1;}
  return;}
a_G3:a_incr(a_1477); return;
a_G4:a_1452=1; return;
} /* nextchar */
static void a_1476(void){ /* saveinputposition */
a_word a_P[1];
a_getfilepos(a_1450,a_P);a_1462=a_P[0];
a_1461=a_1452;
a_1463=a_1459;
a_1464=a_1460; return;
} /* saveinputposition */
static void a_1475(void){ /* restoreinputposition */

a_setfilepos(a_1450,a_1462);
a_1452=a_1461;
a_1459=a_1463;
a_1460=a_1464; return;
} /* restoreinputposition */
static void a_1454(void){ /* comment */

a_G1:if(a_equal(a_1452,10)){ return;}
if(a_equal(a_1452,1)){ return;}
a_1465(); goto a_G1;
} /* comment */
static void a_1469(a_word a_A[1]){ /* readdestination+a> */
a_word a_L2;
{ if(a_1452==78){ goto a_G2;}
 if(a_1452==48){ goto a_G15;}
 if(a_1452==45){  goto a_G17;}
  goto a_G28;}
a_G2:a_1465();
{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G8;}
}
a_subtr(a_1452,48,a_A[0]);
a_1465();
if(a_more(a_A[0],0)){ goto a_G9;}
if(a_equal(0,0)){ goto a_G9;}
a_G8:a_1420(a_1001,2130706398); return;
a_G9:{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G13;}
}
a_subtr(a_1452,48,a_L2);
a_1465();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G9;
a_G13:if(!a_is(0)){ return;}
a_G14:a_subtr(0,a_A[0],a_A[0]); return;
a_G15:a_1465();
a_A[0]=0; return;
a_G17:a_1465();
{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G8;}
}
a_subtr(a_1452,48,a_A[0]);
a_1465();
if(a_more(a_A[0],0)){ goto a_G23;}
if(!a_equal(1,0)){ goto a_G8;}
a_G23:{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G27;}
}
a_subtr(a_1452,48,a_L2);
a_1465();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G23;
a_G27:if(!a_is(1)){ return;} goto a_G14;
a_G28:a_1420(a_1001,2130706393); return;
} /* readdestination */
static void a_1471(a_word a_A[1]){ /* readtargetnumber+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L2=to_LIST(a_1445)->aupb;
a_L3=0;
a_G3:{ if(a_1452==45){ goto a_G4;}
 if((48<=a_1452 && a_1452<=57)){  goto a_G6;}
  goto a_G7;}
a_G4:a_L3=1;
a_G5:a_1465(); goto a_G3;
a_G6:a_1456(a_1452); goto a_G5;
a_G7:a_1006(a_L3,a_L2,a_P);a_A[0]=a_P[0];
a_unstackto(a_1445,a_L2); return;
} /* readtargetnumber */
static void a_1457(a_word a_F1,a_word a_A[1]){ /* gettagdata+>a+a> */

a_A[0]=to_LIST(a_1449)->offset[a_F1]; return;
} /* gettagdata */
static void a_1458(a_word a_F1,a_word a_A[1]){ /* gettagimage+>a+a> */

a_subtr(a_F1,2,a_A[0]); return;
} /* gettagimage */
static void a_1467(a_word a_F1,a_word a_F2){ /* puttagdata+>a+>a */

to_LIST(a_1449)->offset[a_F1]=a_F2; return;
} /* puttagdata */
static void a_1451(a_word a_A[1]){ /* addLEXTentry+a> */
a_word a_P[1];
{register a_word *a_r1=a_extension(a_1449,2);a_r1[0]=a_r1[1]=0;to_LIST(a_1449)->aupb+=2;}
a_1455(to_LIST(a_1449)->aupb,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],to_LIST(a_1449)->aupb)){ return;}
a_unstack(a_1449);
a_unstackstring(a_1449); return;
} /* addLEXTentry */
static void a_1455(a_word a_F1,a_word a_A[1]){ /* enterstring+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_L7;a_word a_P[1];
a_subtr(a_F1,2,a_L3);
a_stringhash(a_1449,a_L3,a_P);a_L4=a_P[0];
a_booland(a_L4,2147483647,a_L4);
a_divrem01(a_L4,a_1448,a_L4);
a_add(a_L4,to_LIST(a_1446)->alwb,a_L4);
a_L5=to_LIST(a_1446)->offset[a_L4];
a_G7:if(!a_equal(a_L5,0)){ goto a_G14;}
to_LIST(a_1449)->offset[a_F1-1]=to_LIST(a_1446)->offset[a_L4];
to_LIST(a_1446)->offset[a_L4]=a_F1;a_A[0]=a_F1;
a_incr(a_1447);
if(a_less(a_1447,a_1448)){ return;}
a_add(a_1448,1024,a_1448);
a_1474(); return;
a_G14:a_subtr(a_L5,2,a_L6);
a_comparestring(a_1449,a_L3,a_1449,a_L6,a_P);a_L7=a_P[0];
if(!a_equal(a_L7,0)){ goto a_G18;}
a_A[0]=a_L5; return;
a_G18:a_L5=to_LIST(a_1449)->offset[a_L5-1]; goto a_G7;
} /* enterstring */
static void a_1474(void){ /* rehash */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_1447=0;
a_L1=to_LIST(a_1446)->aupb;
a_G3:if(a_less(a_L1,to_LIST(a_1446)->alwb)){ goto a_G6;}
to_LIST(a_1446)->offset[a_L1]=0;
a_previous(a_1446,a_L1); goto a_G3;
a_G6:a_subtr(to_LIST(a_1446)->aupb,to_LIST(a_1446)->alwb,a_L2);
a_G7:a_incr(a_L2);
if(a_mreq(a_L2,a_1448)){ goto a_G10;}
{register a_word *a_r1=a_extension(a_1446,1);a_r1[0]=0;to_LIST(a_1446)->aupb+=1;}
  goto a_G7;
a_G10:a_L1=to_LIST(a_1449)->aupb;
a_G11:if(a_less(a_L1,to_LIST(a_1449)->alwb)){ return;}
a_1455(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,a_L1)){ goto a_G16;}
a_previous(a_1449,a_L1);
a_previousstring(a_1449,a_L1); goto a_G11;
a_G16:a_1425(a_1001,2130706387); return;
} /* rehash */
static void a_1470(a_word a_A[1]){ /* readstring+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1445)->aupb;
a_L2=0;
a_G3:a_1465();
{ if(a_1452==34){ goto a_G5;}
 if(a_1452==10||a_1452==1){  goto a_G14;}
  goto a_G7;}
a_G5:a_1465();
if(!a_equal(a_1452,34)){ goto a_G9;}
a_G7:a_1456(a_1452);
a_incr(a_L2); goto a_G3;
a_G9:if(!a_equal(a_L2,0)){ goto a_G11;}
a_A[0]=155851727; return;
a_G11:a_packstring(a_1445,a_L2,a_1449);
a_unstackto(a_1445,a_L3);
a_1451(a_P);a_A[0]=a_P[0]; return;
a_G14:a_1420(a_1001,2130706383); return;
} /* readstring */
static void a_1472(a_word a_A[2]){ /* readtargetstring+a>+a> */
a_word a_L3;a_word a_P[2];
a_L3=to_LIST(a_1445)->aupb;
if(a_equal(a_1452,34)){ goto a_G4;}
a_G3:a_1420(a_1001,2130706378); return;
a_G4:a_1465();
{ if(a_1452==34){ goto a_G6;}
 if(a_1452==10||a_1452==1){  goto a_G3;}
  goto a_G8;}
a_G6:a_1465();
if(!a_equal(a_1452,34)){ goto a_G9;}
a_G8:a_1456(a_1452); goto a_G4;
a_G9:a_1007(a_L3,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];
a_unstackto(a_1445,a_L3); return;
} /* readtargetstring */
static void a_1468(a_word a_A[1]){ /* readbold+a> */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1465();
a_L3=to_LIST(a_1445)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1452 && a_1452<=122))){ goto a_G9;}
}
a_L4=a_1452;
a_1465();
a_1456(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1452,39)){ goto a_G11;}
a_1465(); goto a_G12;
a_G11:a_1420(a_1001,2130706371); return;
a_G12:a_packstring(a_1445,a_L2,a_1449);
a_unstackto(a_1445,a_L3);
a_A[0]=16777299;
a_G15:a_comparestring(a_1444,a_A[0],a_1449,to_LIST(a_1449)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G19;}
if(a_equal(a_A[0],16777220)){ goto a_G11;}
a_previousstring(a_1444,a_A[0]); goto a_G15;
a_G19:a_unstackstring(a_1449); return;
} /* readbold */
static void a_1473(a_word a_A[1]){ /* readtype+a> */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1465();
a_L3=to_LIST(a_1445)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1452 && a_1452<=122))){ goto a_G9;}
}
a_L4=a_1452;
a_1465();
a_1456(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1452,32)){ goto a_G13;}
a_1456(32);
a_incr(a_L2);
a_1465(); goto a_G4;
a_G13:if(!a_equal(a_1452,62)){ goto a_G15;}
a_1465(); goto a_G16;
a_G15:a_1420(a_1001,2130706366); return;
a_G16:a_packstring(a_1445,a_L2,a_1449);
a_unstackto(a_1445,a_L3);
a_A[0]=16777394;
a_G19:a_comparestring(a_1444,a_A[0],a_1449,to_LIST(a_1449)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G23;}
if(a_equal(a_A[0],16777304)){ goto a_G15;}
a_previousstring(a_1444,a_A[0]); goto a_G19;
a_G23:a_unstackstring(a_1449); return;
} /* readtype */
static void a_1466(void){ /* nextsymbol */
a_word a_L1;a_word a_P[2];
a_G1:a_P[0]=a_1479;a_1013(a_P);a_1479=a_P[0];a_1460=a_P[1];
if(!a_more(a_1479,0)){ goto a_G4;}
a_1459=16777459; return;
a_G4:{ if(a_1452==32||a_1452==10){ goto a_G5;}
 if(a_1452==36){ goto a_G6;}
 if(a_1452==48){ goto a_G7;}
 if((49<=a_1452 && a_1452<=57)){ goto a_G10;}
 if(a_1452==70){ goto a_G23;}
 if(a_1452==73){ goto a_G34;}
 if(a_1452==76){ goto a_G48;}
 if(a_1452==78){ goto a_G59;}
 if(a_1452==88){ goto a_G70;}
 if(a_1452==84){ goto a_G73;}
 if(a_1452==39){ goto a_G76;}
 if(a_1452==60){ goto a_G77;}
 if(a_1452==34){ goto a_G79;}
 if(a_1452==38){ goto a_G81;}
 if(a_1452==93){ goto a_G82;}
 if(a_1452==41){ goto a_G83;}
 if(a_1452==58){ goto a_G84;}
 if(a_1452==44){ goto a_G85;}
 if(a_1452==126){ goto a_G86;}
 if(a_1452==47){ goto a_G87;}
 if(a_1452==45){ goto a_G88;}
 if(a_1452==35){ goto a_G103;}
 if(a_1452==40){ goto a_G104;}
 if(a_1452==124){ goto a_G105;}
 if(a_1452==62){ goto a_G106;}
 if(a_1452==43){ goto a_G109;}
 if(a_1452==46){ goto a_G110;}
 if(a_1452==59){ goto a_G111;}
 if(a_1452==42){ goto a_G112;}
 if(a_1452==91){ goto a_G113;}
 if(a_1452==94){ goto a_G114;}
 if(a_1452==64){ goto a_G115;}
 if(a_1452==1){  goto a_G116;}
  goto a_G117;}
a_G5:a_1465(); goto a_G1;
a_G6:a_1454(); goto a_G1;
a_G7:a_1459=16777455;
a_1460=0;
a_G9:a_1465(); return;
a_G10:a_1459=16777455;
{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G16;}
}
a_subtr(a_1452,48,a_1460);
a_1465();
if(a_more(a_1460,0)){ goto a_G17;}
if(a_equal(0,0)){ goto a_G17;}
a_G16:a_1420(a_1001,2130706398); return;
a_G17:{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G21;}
}
a_subtr(a_1452,48,a_L1);
a_1465();
a_addmult(a_1460,10,a_L1,a_1460); goto a_G17;
a_G21:if(!a_is(0)){ return;}
a_G22:a_subtr(0,a_1460,a_1460); return;
a_G23:a_1459=16777475;
a_1465();
{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G16;}
}
a_subtr(a_1452,48,a_1460);
a_1465();
if(a_more(a_1460,0)){ goto a_G30;}
if(!a_equal(0,0)){ goto a_G16;}
a_G30:{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G21;}
}
a_subtr(a_1452,48,a_L1);
a_1465();
a_addmult(a_1460,10,a_L1,a_1460); goto a_G30;
a_G34:a_1459=16777471;
a_1465();
{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G16;}
}
a_subtr(a_1452,48,a_1460);
a_1465();
if(a_more(a_1460,0)){ goto a_G41;}
if(!a_equal(0,0)){ goto a_G16;}
a_G41:{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G45;}
}
a_subtr(a_1452,48,a_L1);
a_1465();
a_addmult(a_1460,10,a_L1,a_1460); goto a_G41;
a_G45:if(!a_is(0)){ goto a_G47;}
a_subtr(0,a_1460,a_1460);
a_G47:a_P[0]=a_1460;a_1315(a_P);a_1460=a_P[0]; return;
a_G48:a_1459=16777479;
a_1465();
{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G16;}
}
a_subtr(a_1452,48,a_1460);
a_1465();
if(a_more(a_1460,0)){ goto a_G55;}
if(!a_equal(0,0)){ goto a_G16;}
a_G55:{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G21;}
}
a_subtr(a_1452,48,a_L1);
a_1465();
a_addmult(a_1460,10,a_L1,a_1460); goto a_G55;
a_G59:a_1459=16777467;
a_1465();
{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G16;}
}
a_subtr(a_1452,48,a_1460);
a_1465();
if(a_more(a_1460,0)){ goto a_G66;}
if(!a_equal(0,0)){ goto a_G16;}
a_G66:{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G21;}
}
a_subtr(a_1452,48,a_L1);
a_1465();
a_addmult(a_1460,10,a_L1,a_1460); goto a_G66;
a_G70:a_1459=16777459;
a_1465();
a_1471(a_P);a_1460=a_P[0]; return;
a_G73:a_1459=16777459;
a_1465();
a_1472(a_P);a_1479=a_P[0];a_1460=a_P[1]; return;
a_G76:a_1468(a_P);a_1459=a_P[0]; return;
a_G77:a_1459=16777463;
a_1473(a_P);a_1460=a_P[0]; return;
a_G79:a_1459=16777483;
a_1470(a_P);a_1460=a_P[0]; return;
a_G81:a_1459=16777400; goto a_G9;
a_G82:a_1459=16777403; goto a_G9;
a_G83:a_1459=16777406; goto a_G9;
a_G84:a_1459=16777409; goto a_G9;
a_G85:a_1459=16777412; goto a_G9;
a_G86:a_1459=16777415; goto a_G9;
a_G87:a_1459=16777418; goto a_G9;
a_G88:a_1465();
{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G101;}
}
a_1459=16777455;
{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G16;}
}
a_subtr(a_1452,48,a_1460);
a_1465();
if(a_more(a_1460,0)){ goto a_G96;}
if(!a_equal(1,0)){ goto a_G16;}
a_G96:{ if(!((48<=a_1452 && a_1452<=57))){ goto a_G100;}
}
a_subtr(a_1452,48,a_L1);
a_1465();
a_addmult(a_1460,10,a_L1,a_1460); goto a_G96;
a_G100:if(!a_is(1)){ return;} goto a_G22;
a_G101:a_1459=16777421;
a_1460=0; return;
a_G103:a_1459=16777424; goto a_G9;
a_G104:a_1459=16777427; goto a_G9;
a_G105:a_1459=16777430; goto a_G9;
a_G106:a_1459=16777433;
a_1465();
a_1469(a_P);a_1460=a_P[0]; return;
a_G109:a_1459=16777436; goto a_G9;
a_G110:a_1459=16777439; goto a_G9;
a_G111:a_1459=16777442; goto a_G9;
a_G112:a_1459=16777445; goto a_G9;
a_G113:a_1459=16777448; goto a_G9;
a_G114:a_1459=16777451; goto a_G9;
a_G115:a_1459=16777397; goto a_G9;
a_G116:a_1459=16777486; return;
a_G117:a_1420(a_1001,2130706361); return;
} /* nextsymbol */
static void a_1443(void){ /* @root */

a_1474(); return;
} /* @root */
static void a_1481(void){ /* pass1 */
a_word a_L1;a_word a_P[1];
a_G1:if(a_1442()){ return;}
if(!a_1394(a_P)){ return;}a_L1=a_P[0];
a_1337(a_L1);
a_1344();
a_1453(); goto a_G1;
} /* pass1 */
static void a_1482(void){ /* pass2 */
a_word a_L1;a_word a_P[1];
a_G1:if(a_1442()){ return;}
a_1353(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_equal(a_L1,2)){ goto a_G1;}
a_1373();
a_1374();
a_1269(); goto a_G1;
} /* pass2 */
static void a_1483(void){ /* pass3 */
a_word a_L1;a_word a_P[1];
a_G1:if(a_1442()){ return;}
a_1353(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_equal(a_L1,2)){ goto a_G1;}
a_1373();
a_1374();
a_1270(); goto a_G1;
} /* pass3 */
static void a_1484(void){ /* pass4 */
a_word a_L1;a_word a_P[1];
a_1158();
a_G2:a_1353(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ goto a_G8;}
if(a_equal(a_L1,2)){ goto a_G2;}
a_1373();
a_1374();
a_1271(); goto a_G2;
a_G8:a_1159(); return;
} /* pass4 */
static void a_1485(void){ /* pass5 */
a_word a_L1;a_word a_P[1];
a_G1:if(a_1442()){ return;}
a_1353(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_equal(a_L1,2)){ goto a_G1;}
a_1373();
a_1374();
a_1295();
a_1091(); goto a_G1;
} /* pass5 */
static void a_1480(void){ /* @root */

a_1389();
if(!a_1442()){ goto a_G4;}
a_exit(1); return;
a_G4:a_1481();
if(!a_1442()){ goto a_G8;}
a_G6:a_1453();
a_G7:a_exit(2); return;
a_G8:a_1369();
a_1363();
a_1482();
if(a_1442()){ goto a_G6;}
a_1250();
a_1282();
a_1483();
if(a_1442()){ goto a_G6;}
a_1272();
if(a_1442()){ goto a_G7;}
a_1243();
if(a_1442()){ goto a_G7;}
a_1261();
a_1183();
if(!a_1442()){ goto a_G24;}
a_exit(4); return;
a_G24:a_1223();
a_1148();
a_1484();
a_1220();
a_1485();
a_1199();
a_1222();
a_1142();
if(!a_1442()){ return;}
a_1154(); goto a_G7;
} /* @root */
static void a_1488(a_word a_F1,a_word a_F2,a_word a_F3){ /* putstring+""f+t[]+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L2=0;
a_G2:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){ return;}a_L3=a_P[0];
a_incr(a_L2);
a_putchar(a_F1,a_L3); goto a_G2;
} /* putstring */
a_PROFILE *a_profiles=NULL;
static void a_stringhash(int F1,int F2,int A[1]){ int *ptr=to_LIST(F1)->offset+F2; unsigned char *v=(unsigned char*)&ptr[1-ptr[0]]; unsigned v1=0x135345+47u*(*v), v2=0xeca864+856u*(*v); while(*v){  v1=(29*v1+17*v2+1259u*(((unsigned)*v)^v2)) % 0x1010309;  v2=(23*v2+257*v1+1237u*(((unsigned)*v)^v1)) % 0x1010507;  v++; } A[0]=(int)((v1<<16)^v2);}
void a_blockhash(int F1,int F2,int A[1]){ unsigned char *v=(unsigned char*)(to_LIST(F1)->offset+F2+1); unsigned v1=0x135345+47u*(*v), v2=0xeca864+856u*(*v); int cnt=sizeof(int)*(to_LIST(F1)->aupb-F2); for(;cnt>0;cnt--){  v1=(29*v1+17*v2+1259u*(((unsigned)*v)^v2)) % 0x1010309;  v2=(23*v2+257*v1+1237u*(((unsigned)*v)^v1)) % 0x1010507;  v++; } A[0]=(int)((v1<<16)^v2);}
extern int a_argc; extern char **a_argv;
static int a_push_string_to(int F1,const char*ptr){
 int n,w;int*goal;char*to;
 #define st to_LIST(F1)
 n=strlen(ptr);if(a_requestspace(F1,3+(n/4))==0){return 0;}
 n=0;goal=&(st->offset[1+st->aupb]);to=(char*)goal;
 while(*ptr){if((*ptr&0x80)==0){*to++=*ptr++;n++;}
  else if((*ptr&0xC0)!=0xC0){ptr++;}
  else if((*ptr&0xE0)==0xC0){*to++=*ptr++;n++;
   if((*ptr&0xC0)!=0x80){n--;to--;}else{*to++=*ptr++;}}
  else if((*ptr&0xF0)==0xE0){*to++=*ptr++;n++;
   if((*ptr&0xC0)!=0x80){n--;to--;}else{*to++=*ptr++;
    if((*ptr&0xC0)!=0x80){n--;to-=2;}else{*to++=*ptr++;}}}
  else if((*ptr&0xF8)==0xF0){*to++=*ptr++;n++;
   if((*ptr&0xC0)!=0x80){n--;to--;}else{*to++=*ptr++;
    if((*ptr&0xC0)!=0x80){n--;to-=2;}else{*to++=*ptr++;
     if((*ptr&0xC0)!=0x80){n--;to-=3;}else {*to++=*ptr++;}}}}
  else{ptr++;}}
 *to=0;w=1+(to-((char*)goal))/4;goal[w]=n;goal[w+1]=w+2;st->aupb+=w+2;
 #undef st
 return 1;
}
static void a_setup_stdarg(int F1,const char*name,int F2){
 int i;
 #define st to_LIST(F1)
 st->name=name;st->offset=st->p=0;st->length=0;
 st->vlwb=a_virtual_max+16;a_virtual_max+=65436;
 if(a_virtual_max<=0){fprintf(stderr,"Out of virtual space\n");
  a_fatal(a_FATAL_memory);}
 st->vupb=a_virtual_max-1;st->calibre=F2;
 st->alwb=st->vlwb;st->aupb=st->alwb-st->calibre;
  for(i=a_argc-1;i>0;i--){
   if(a_push_string_to(F1,a_argv[i])==0){
    fprintf(stderr,"out of memory\n");a_fatal(a_FATAL_memory);}
 }
 #undef st
}
/* EOF */
