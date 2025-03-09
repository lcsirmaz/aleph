/* ALEPH ice linker v2.2, word size=32 */

// linked modules:
// number "number v2.0"
// rule "rule, v2.1"
// target "target, v2.2"
// expression "expression, v2.0"
// data "data, v2.0"
// item "item, v2.1"
// arithmetic "arithmetic v2.1"
// config "config, v2.2"
// input "input, v2.1"
// error "error, v2.1"
// lexical "lexical, v2.0"
// @main "ALEPH linker, v2.0"
// stdlib "libC base"
// stdlib "libC put string"
// stdlib "libC wait for"
// stdlib "libC stdarg"
// stdlib "libC simple hash"
#include "aleph_core.h"
static void a_stringhash(int,int,int[1]);static void a_blockhash(int,int,int[1]);
static void a_setup_stdarg(int,const char*,int);
#include "aleph_stdlib.h"
#define a_1001 (0) /* @StringTable */
#define a_1005 (a_1001+sizeof_LIST) /* NUMBER */
static void a_1006(int a_F1,int a_F2); /* adddigit */
static void a_1007(int a_F1,int a_F2,int a_A[1]); /* enterconststring */
static void a_1008(int a_F1,int a_A[2]); /* entertargetstring */
static void a_1009(int a_F1); /* extendBUFFER */
static void a_1010(int a_F1,int a_A[1]); /* getdigit */
static void a_1011(int a_F1); /* getnumberrepr */
static void a_1012(int a_A[1]); /* getnumberzero */
static void a_1013(int a_F1); /* getregisterrepr */
static void a_1014(int a_F1,int a_A[1]); /* gettargetnumbervalue */
static void a_1015(void); /* initializenumbers */
static int a_1016=0; /* lastdigit */
static void a_1017(int a_F1,int a_F2,int a_A[1]); /* loadregister */
static int a_1018=0; /* maxdecimal */
static int a_1019(int a_F1,int a_F2); /* minmaxregisters */
static void a_1020(int a_A[2]); /* nexttargetstringvalue */
static int a_1021=0; /* rtargetmax */
static int a_1022=0; /* rtargetmin */
static int a_1023(int a_F1); /* samenumberblock */
static void a_1024(int a_F1,int a_A[1]); /* storeregister */
static int a_1025=0; /* targetmaxint */
static int a_1026=0; /* targetminint */
static int a_1027=0; /* zeroptr */
static int a_1029=0; /* C1 */
static int a_1030=0; /* C2 */
static int a_1031=0; /* C3 */
#define a_1032 (a_1005+sizeof_LIST) /* NODE */
#define a_1033 (a_1032+sizeof_LIST) /* ZONE */
static void a_1034(int a_F1,int a_F2,int a_F3,int a_A[1]); /* addinterval */
static void a_1035(void); /* advancenode */
static void a_1036(void); /* arealabels */
static void a_1037(int a_F1,int a_A[1]); /* checkarea */
static void a_1038(void); /* checkareas */
static void a_1039(void); /* checknodehash */
static void a_1040(int a_F1,int a_F2); /* clearnodeflag */
static void a_1041(void); /* clearstacksize */
static void a_1042(int a_F1); /* comparetostoredaffixes */
static int a_1043(int a_F1); /* completezone */
static void a_1044(void); /* computeruleaffixhash */
static void a_1045(void); /* createnodes */
static int a_1046=0; /* dolocalaffixcheck */
static int a_1047(int a_F1,int a_F2); /* equalaffixes */
static void a_1048(void); /* extensionlabel */
static void a_1049(void); /* findequalnodes */
static void a_1050(int a_F1,int a_F2); /* findintervalpair */
static void a_1051(int a_A[1]); /* findnextnode */
static void a_1052(int a_F1,int a_A[1]); /* findreallabel */
static void a_1053(void); /* generatearea */
static void a_1054(void); /* generateareas */
static void a_1055(void); /* generatebox */
static void a_1056(void); /* generateextension */
static void a_1057(void); /* generatelabel */
static void a_1058(void); /* generaterulecall */
static void a_1059(int a_A[1]); /* getitemdef */
static void a_1060(int a_F1,int a_A[1]); /* getnodeindex */
static int a_1061(int a_F1); /* hasoutaffix */
static void a_1062(int a_F1,int a_A[1]); /* indextonode */
static int a_1063(void); /* islimit */
static int a_1064(int a_F1); /* isnodediscarded */
static int a_1065=0; /* localaffixptr */
static int a_1066=0; /* loopfound */
static void a_1067(void); /* makerule */
static void a_1068(int a_F1); /* marklocalaffix */
static void a_1069(int a_F1,int a_F2); /* marknode */
static void a_1070(int a_F1); /* mergeintervals */
static int a_1071(void); /* nodehashdifferent */
static int a_1072(int a_F1); /* nodewithsamehash */
static void a_1073(void); /* omitemptynodes */
static void a_1074(int a_C,int *a_V); /* pushBUFFER */
static void a_1075(int a_F1,int a_F2); /* putnodeflag */
static void a_1076(int a_A[2]); /* readareainterval */
static void a_1077(int a_F1,int a_F2); /* replacelabels */
static void a_1078(int a_F1,int a_F2); /* replacenlabels */
static void a_1079(void); /* rulelabel */
static void a_1080(void); /* rulesection */
static int a_1081(int a_F1,int a_F2); /* samenodes */
static void a_1082(void); /* scani */
static void a_1083(void); /* scanii */
static void a_1084(void); /* scaniii */
static void a_1085(void); /* scaniv */
static void a_1086(int a_F1); /* setnodeflag */
static void a_1087(void); /* setrulehead */
static void a_1088(void); /* skipaffix */
static void a_1089(void); /* skiplist */
static void a_1090(void); /* skiprule */
static void a_1091(void); /* skiprulehead */
static void a_1092(void); /* skiptocomma */
static void a_1093(int a_A[1]); /* skiptolabel */
static void a_1094(int a_F1,int a_F2); /* startlocalaffixcheck */
static void a_1095(void); /* storeaffix */
static void a_1096(void); /* storelimit */
static void a_1097(int a_F1); /* storelist */
static void a_1098(int a_A[1]); /* storeruleaffix */
static void a_1099(void); /* storeruleaffixes */
static int a_1100=0; /* thisnode */
static void a_1102(int a_F1,int a_C,int *a_V); /* T */
#define a_1103 (a_1033+sizeof_LIST) /* TARGET */
static void a_1104(int a_F1); /* Taffix */
static void a_1105(int a_A[1]); /* Taffixinner */
static void a_1106(int a_F1,int a_F2); /* Tbox */
static void a_1107(int a_F1,int a_F2); /* Textension */
static void a_1108(int a_F1,int a_F2); /* Tifcondition */
static void a_1109(int a_A[1]); /* Tindex */
static void a_1110(int a_F1,int a_F2); /* Tjumptoareas */
static void a_1111(int a_F1,int a_F2); /* Tlabel */
static void a_1112(int a_F1,int a_A[1]); /* Tlimittail */
static void a_1113(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6,int a_F7); /* Trulecall */
static void a_1114(int a_F1,int a_F2,int a_F3); /* Tsingleifcondition */
static void a_1115(int a_F1); /* addcallstack */
static void a_1116(void); /* addprofilingcount */
static void a_1117(void); /* addprofilingdef */
static void a_1118(void); /* addtracing */
static void a_1119(int a_A[1]); /* argsep */
static void a_1120(int a_F1,int a_A[2]); /* assignmentsource */
static void a_1121(int a_F1,int a_F2,int a_F3); /* blockdeclaration */
static void a_1122(int a_F1,int a_A[1]); /* boxclassifier */
static int a_1123=0; /* calledrule */
static int a_1124=0; /* callstack */
static void a_1125(int a_F1); /* charfileinitialization */
static void a_1126(void); /* closetarget */
static void a_1127(void); /* constitem */
static void a_1128(int a_F1,int a_A[1]); /* countfilearea */
static void a_1129(void); /* datadeclaration */
static void a_1130(int a_F1); /* datafileinitialization */
static void a_1131(void); /* datainitialization */
static void a_1132(int a_F1,int a_F2,int a_F3); /* declarecallargs */
static void a_1133(int a_F1,int a_F2,int a_F3); /* declarelocals */
static void a_1134(void); /* deletetarget */
static void a_1135(int a_F1,int a_F2); /* extensionblock */
static void a_1136(int a_A[1]); /* fillitem */
static int a_1137(int a_A[1]); /* fillrepeater */
static void a_1138(void); /* filltablehead */
static void a_1139(void); /* filltabletail */
static int a_1140=0; /* filltotal */
static void a_1141(int a_F1,int a_F2,int a_F3); /* flushbuffer */
static void a_1142(int a_F1); /* formalargument */
static void a_1143(int a_F1,int a_F2,int a_F3,int a_F4); /* genassignment */
static void a_1144(void); /* generatefillentries */
static void a_1145(int a_F1,int a_F2,int a_F3); /* gengetaffixno */
static void a_1146(int a_F1,int a_F2); /* genshiftaffix */
static void a_1147(int a_F1,int a_F2); /* genwaitfor */
static int a_1148(int a_F1); /* hasoutaffix */
static int a_1149(int a_F1); /* iscompletearea */
static int a_1150(int a_F1); /* isdummyaffix */
static int a_1151(int a_F1,int a_F2,int a_F3); /* isrulediscarded */
static void a_1152(int a_F1); /* jumptolabel */
static int a_1153=0; /* lastprofile */
static void a_1154(int a_F1,int a_F2); /* listinitialization */
static void a_1155(int a_F1); /* localargument */
static int a_1156=0; /* moduleroots */
static void a_1157(int a_A[1]); /* nextaffix */
static int a_1158=0; /* nextnodeidx */
static int a_1159(int a_F1,int a_F2); /* numbersequal */
static void a_1160(void); /* opentarget */
static void a_1161(int a_F1,int a_A[1]); /* outargs */
static void a_1162(int a_F1); /* pidginalttagtail */
static void a_1163(int a_F1); /* pidginrepeatblock */
static void a_1164(int a_F1,int a_F2); /* pidginruleargs */
static void a_1165(int a_F1); /* pidginrulecall */
static void a_1166(int a_F1); /* printBUFFER */
static void a_1167(int a_F1); /* printGOTO */
static void a_1168(int a_F1); /* printexternalrepr */
static void a_1169(int a_F1); /* printgoto */
static void a_1170(int a_F1); /* printint */
static void a_1171(int a_F1,int a_F2); /* printint1 */
static void a_1172(int a_F1,int a_F2); /* printintindex */
static void a_1173(void); /* printlabelprefix */
static void a_1174(int a_F1); /* printlocallabel */
static void a_1175(int a_F1); /* printnlptr */
static void a_1176(int a_F1); /* printnumber */
static void a_1177(int a_F1); /* printpidginrepr */
static void a_1178(int a_F1); /* printptr */
static void a_1179(int a_F1); /* printrepr */
static void a_1180(void); /* procwaitfor */
static void a_1181(void); /* profilingdeclaration */
static void a_1182(int a_F1); /* pushBUFFER */
static void a_1183(int a_F1,int a_F2,int a_A[1]); /* regularcalld1 */
static void a_1184(int a_F1,int a_F2); /* regularcalld2 */
static void a_1185(int a_F1,int a_F2,int a_F3); /* regularcalld3 */
static void a_1186(int a_F1); /* regularcallpostload */
static void a_1187(int a_F1); /* regularcallpreload */
static void a_1188(int a_F1,int a_F2,int a_F3); /* regularrulecall */
static void a_1189(int a_F1,int a_F2,int a_F3); /* repeatblockcall */
static void a_1190(int a_F1,int a_F2,int a_F3,int a_F4); /* repeatblockpostload */
static void a_1191(int a_F1,int a_F2,int a_F3,int a_F4); /* repeatblockpreload */
static void a_1192(int a_F1); /* rootprototype */
static void a_1193(int a_F1); /* ruleargs */
static void a_1194(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6); /* ruledeclarationhead */
static void a_1195(void); /* ruledeclarationtail */
static void a_1196(int a_F1); /* ruleprototype */
static void a_1197(int a_F1); /* ruletyper */
static void a_1198(int a_F1); /* showformalsascomment */
static void a_1199(void); /* skipfillinitializer */
static void a_1200(void); /* targetmain */
static int a_1201=0; /* targetopened */
static void a_1202(void); /* targetpostlude */
static void a_1203(void); /* targetprelude */
static int a_1204=0; /* thisrule */
static void a_1205(int a_F1,int a_F2); /* tracepost */
static void a_1206(int a_F1); /* tracepre */
static void a_1207(int a_A[1]); /* untilnextcomma */
static void a_1208(void); /* usecallstack */
static void a_1209(int a_F1); /* vardeclaration */
static int a_1210=0; /* waitforused */
static int a_1212(int a_F1); /* E */
#define a_1213 (a_1103+sizeof_CHFILE) /* EXPRESSION */
static int a_1214(int a_A[1]); /* Eitem */
static int a_1215(int a_F1,int a_A[2]); /* Eop */
static int a_1216=0; /* Raddr */
static int a_1217=0; /* Rby */
static void a_1218(int a_F1); /* checkcalibretype */
static void a_1219(int a_F1,int a_F2); /* checkconstanttype */
static void a_1220(int a_F1); /* checklisttype */
static void a_1221(void); /* clearvirtualspace */
static int a_1222=0; /* eptr */
static void a_1223(int a_A[1]); /* finalbase */
static void a_1224(int a_F1); /* finaleval */
static void a_1225(void); /* finalevaluation */
static void a_1226(int a_F1,int a_A[1]); /* finalexpr */
static void a_1227(int a_F1,int a_F2,int a_A[1]); /* getexprlimit */
static void a_1228(int a_A[1]); /* getitemdef */
static int a_1229=0; /* linkexpr */
static int a_1230(int a_A[1]); /* loosebase */
static void a_1231(int a_F1); /* looseeval */
static void a_1232(void); /* looseevaluation */
static int a_1233(int a_F1,int a_A[1]); /* looseexpr */
static void a_1234(int a_F1,int a_F2,int a_F3,int a_A[2]); /* nextvirtualblock */
static void a_1235(int a_F1,int a_F2,int a_F3); /* optor */
static void a_1236(int a_F1); /* pushEXPR */
static void a_1237(void); /* readexpression */
static void a_1238(int a_F1,int a_F2); /* setfinalvalue */
static int a_1239(int a_F1,int a_F2); /* splitvirtualspace */
static void a_1240(int a_F1,int a_A[1]); /* storenumstring */
static void a_1241(int a_F1,int a_F2,int a_A[1]); /* virtualaddressoffset */
static void a_1243(void); /* assignreprnumbers */
static void a_1244(int a_F1,int a_F2); /* checkconstanttype */
static void a_1245(int a_F1); /* checkfiletype */
static void a_1246(int a_F1); /* checkfillconstanttype */
static void a_1247(void); /* checkfillitem */
static void a_1248(int a_F1); /* checklisttype */
static void a_1249(int a_A[2]); /* collectlistsizeclaims */
static void a_1250(void); /* computepointerconstants */
static void a_1251(void); /* datasectioni */
static void a_1252(void); /* datasectionii */
static void a_1253(void); /* datasectioniii */
static void a_1254(void); /* distributevirtualaddress */
static void a_1255(void); /* externalentry */
static void a_1256(void); /* fileentry */
static int a_1257=0; /* filltablesize */
static void a_1258(int a_F1,int a_F2); /* fixsize */
static int a_1259(int a_F1,int a_A[1]); /* getconstvalue */
static void a_1260(int a_F1,int a_F2,int a_A[1]); /* getestimator */
static void a_1261(int a_A[1]); /* getitemdef */
static int a_1262=-1; /* linklists */
static void a_1263(void); /* listentry */
static void a_1264(void); /* loosebounds */
static void a_1265(void); /* loosefill */
static void a_1266(int a_A[1]); /* loosefillitem */
static void a_1267(int a_F1); /* looseinitializer */
static void a_1268(int a_F1,int a_F2,int a_F3); /* looserepeater */
static int a_1269=1000; /* nextreprno */
static void a_1270(int a_F1); /* readmatter */
static void a_1271(int a_F1,int a_F2); /* relativesize */
static void a_1272(int a_F1); /* rememberlist */
static void a_1273(int a_F1,int a_F2,int a_F3,int a_A[1]); /* repeatervalue */
static void a_1274(void); /* setlistbounds */
static void a_1275(int a_F1); /* setpointervalue */
static void a_1276(int a_F1); /* setreprnumber */
static void a_1277(void); /* skipdatasection */
static void a_1278(void); /* skipentry */
static void a_1279(void); /* skipfill */
static void a_1280(int a_F1); /* skipfillinitializer */
static void a_1281(void); /* skipfillitem */
static void a_1282(int a_F1); /* skipfillrepeater */
#define a_1284 (a_1213+sizeof_LIST) /* AUX */
#define a_1285 (a_1284+sizeof_LIST) /* ITEM */
static void a_1286(void); /* addbuiltinformals */
static void a_1287(int a_F2,int a_A[1],int a_C,int *a_V); /* addformalaffixes */
static void a_1288(int a_F1,int a_F2); /* addmatter */
static void a_1289(void); /* addshiftaffixrules */
static void a_1290(void); /* addstdstring */
static void a_1291(int a_A[1]); /* advancemodbase */
static void a_1292(int a_F1); /* checkitemID */
static void a_1293(void); /* checkmainmodule */
static void a_1294(void); /* cleanupitems */
static void a_1295(int a_F1,int a_F2); /* clearitemflag */
static int a_1296(int a_F1,int a_F2); /* compareformals */
static void a_1297(int a_A[1]); /* converttoitem */
static int a_1298=0; /* doreport */
static void a_1299(void); /* enteritem */
static void a_1300(void); /* expandITEM */
static void a_1301(int a_F1,int a_A[1]); /* finditemdef */
static void a_1302(int a_F1,int a_A[3]); /* finditemlineno */
static void a_1303(int a_F1,int a_A[2]); /* findlineno */
static int a_1304=0; /* firstmodule */
static void a_1305(int a_F1,int a_F2); /* formalaffixes */
static void a_1306(int a_F1,int a_A[1]); /* getanchorcount */
static void a_1307(int a_F1,int a_A[1]); /* getcalibre */
static void a_1308(int a_F1,int a_F2,int a_A[1]); /* getfilearea */
static void a_1309(int a_F1,int a_A[2]); /* getfiledata */
static void a_1310(int a_F1,int a_A[1]); /* getfill */
static void a_1311(int a_F1,int a_F2,int a_A[1]); /* getformal */
static void a_1312(int a_F1,int a_A[1]); /* getlistlink */
static int a_1313(int a_F2,int a_A[2]); /* getmatter */
static void a_1314(int a_A[1]); /* getnextmodulehead */
static void a_1315(int a_F1,int a_A[1]); /* getnumberofformals */
static void a_1316(int a_F1,int a_A[1]); /* getssel */
static void a_1317(int a_F1,int a_A[1]); /* getvlwb */
static void a_1318(int a_F1,int a_A[1]); /* getvupb */
static void a_1319(int a_F1); /* headsection */
static int a_1320(int a_F1,int a_F2); /* incompatibletypes */
static int a_1321(int a_F1); /* isassignitem */
static int a_1322(int a_F1,int a_A[1]); /* isbuiltinrule */
static int a_1323(int a_F1,int a_F2); /* isitemflag */
static int a_1324(int a_F1); /* isrootitem */
static int a_1325(int a_F1); /* iswaitforitem */
static void a_1326(void); /* itemsection */
static int a_1327=0; /* lastmodule */
static int a_1328=0; /* linkformals */
static void a_1329(void); /* linkmoduleheader */
static int a_1330=0; /* mainmodule */
static int a_1331=0; /* makeformals */
static int a_1332=0; /* matterlink */
static int a_1333=0; /* maxlineno */
static int a_1334=0; /* modbase */
static void a_1335(int a_A[1]); /* opennextmodule */
static void a_1336(int a_F1); /* pushAUX */
static void a_1337(int a_F1,int a_F2); /* putfill */
static void a_1338(int a_F1,int a_F2); /* putlistlink */
static void a_1339(int a_F1,int a_F2); /* putvlwb */
static void a_1340(int a_F1,int a_F2); /* putvupb */
static void a_1341(void); /* readdefinitionlist */
static void a_1342(int a_F1); /* readfileinfo */
static void a_1343(void); /* readitem */
static void a_1344(int a_F1); /* reportitem */
static void a_1345(void); /* reportnotusedpublicitems */
static int a_1346=0; /* rootformals */
static void a_1347(int a_A[1]); /* scanfordefinitions */
static void a_1348(void); /* scanfordoubledefinitions */
static void a_1349(int a_F1); /* scanitem */
static void a_1350(int a_F1); /* scanitemfordbledef */
static void a_1351(void); /* scanlinkedmodules */
static void a_1352(int a_F1,int a_F2,int a_A[2]); /* searchforline */
static void a_1353(int a_F1,int a_A[1]); /* searchformals */
static void a_1354(int a_F1,int a_F2); /* setitemflag */
static void a_1355(void); /* skipheadsection */
static void a_1356(void); /* skipitemsection */
static int a_1357(int a_F1,int a_F2); /* stacksizemismatch */
static void a_1358(int a_A[1]); /* storeformalaffixes */
static void a_1359(int a_A[1]); /* storelistbounds */
static int a_1360(int a_F1,int a_F2); /* unequaltypes */
static int a_1361=0; /* waitforformals */
#define a_1363 (a_1285+sizeof_LIST) /* REGISTER */
static void a_1364(int a_F1,int a_A[1]); /* duplregister */
static void a_1365(int a_F1); /* freeregister */
static void a_1366(int a_F1); /* freeregistersfrommark */
static void a_1367(int a_F1,int a_A[1]); /* getcstregister */
static void a_1368(int a_A[1]); /* getregister */
static int a_1369(int a_F1); /* istargetconst */
static void a_1370(int a_A[1]); /* markregisters */
static void a_1371(int a_F1,int a_A[1]); /* putcstregister */
static void a_1372(int a_F1,int a_F2,int a_A[1]); /* readregister */
static int a_1373(int a_F1,int a_F2); /* regcompare */
static int a_1374(int a_F1,int a_F2,int a_F3); /* regcompare2 */
static void a_1375(int a_F1,int a_F2,int a_F3); /* regoperator */
static int a_1376=1; /* targetwordwidth */
static void a_1377(int a_F1,int a_F2); /* writeregister */
#define a_1380 (a_1363+sizeof_LIST) /* FILES */
static int a_1381=0; /* actualptr */
static void a_1382(void); /* adddirseparator */
static void a_1383(void); /* addextension */
static void a_1384(int a_F1); /* addincludedicefiles */
static int a_1385=1; /* addstdlib */
static int a_1386=0; /* argtop */
static void a_1387(void); /* checkcommandlinearguments */
static void a_1388(int a_F1); /* extendBUFFER */
static void a_1389(int a_F1); /* extendFILES */
static int a_1390=0; /* fileno */
static void a_1391(int a_A[1]); /* geticefile */
static int a_1392(int a_A[1]); /* getnextsource */
static void a_1393(void); /* gettargetfile */
static void a_1394(int a_F1,int a_A[1]); /* handlesourcefile */
static int a_1395(int a_F1,int a_F2); /* isfileflag */
static int a_1396(int a_F1,int a_F2); /* isfirstarg */
static int a_1397=0; /* libdir */
static int a_1398=0; /* libfile */
static int a_1399=0; /* mainfile */
static int a_1400(void); /* notstdlibsource */
static int a_1401(int a_F1,int a_A[1]); /* nthpath */
static void a_1402(int a_A[1]); /* openBUFFER */
static void a_1403(int a_F1); /* openfileaslast */
static void a_1404(int a_F1,int a_A[1]); /* openfilefirst */
static void a_1405(int a_F1); /* opensource */
static int a_1406(int a_F1); /* selectpath */
static void a_1407(int a_F1,int a_F2); /* setfileflag */
static void a_1408(int a_F1); /* setsource */
static void a_1409(int a_F1); /* stringtoBUFFER */
static int a_1410=0; /* targetfile */
static void a_1411(int a_F1,int a_A[1]); /* tryfilefirst */
static void a_1412(int a_F1,int a_A[1]); /* tryopen */
static void a_1413(int a_F1,int a_F2,int a_A[1]); /* tryopenwithpath */
static int a_1414(int a_F1,int a_A[1]); /* wasicesource */
#define a_1416 (a_1380+sizeof_LIST) /* MESSAGE */
#define a_1417 (a_1416+sizeof_LIST) /* PRINTFILE */
static void a_1418(int a_F1,int a_F2); /* corrupticefile */
static void a_1419(int a_C,int *a_V); /* error */
static int a_1420=0; /* errorno */
static void a_1421(int a_C,int *a_V); /* fatalerror */
static void a_1422(int a_C,int *a_V); /* formatprint */
static void a_1423(int a_F1,int a_F2); /* internalerror */
static void a_1424(int a_C,int *a_V); /* message */
static void a_1425(int a_F1); /* messagehead */
static void a_1426(void); /* nlcr */
static void a_1427(int a_F1,int a_F2); /* print */
static void a_1428(int a_F1); /* printbase */
static void a_1429(int a_F1); /* printchar */
static void a_1430(int a_F1); /* printform */
static void a_1431(int a_F1,int a_F2); /* printform1 */
static void a_1432(int a_F1); /* printint */
static void a_1433(int a_F1,int a_F2); /* printint1 */
static void a_1434(int a_F1); /* printitem */
static void a_1435(int a_F1); /* printline */
static void a_1436(int a_F1); /* printpointer */
static int a_1437=0; /* prpos */
static void a_1438(int a_F1); /* tabline */
static void a_1439(int a_C,int *a_V); /* warning */
static int a_1440(void); /* waserror */
#define a_1442 (a_1417+sizeof_CHFILE) /* BOLD */
#define a_1443 (a_1442+sizeof_LIST) /* BUFFER */
#define a_1444 (a_1443+sizeof_LIST) /* HASH */
static int a_1445=1; /* HASHentries */
static int a_1446=1023; /* HASHsize */
#define a_1447 (a_1444+sizeof_LIST) /* LEXT */
#define a_1448 (a_1447+sizeof_LIST) /* SOURCE */
static void a_1449(int a_A[1]); /* addLEXTentry */
static int a_1450=32; /* char */
static void a_1451(void); /* closesource */
static void a_1452(void); /* comment */
static void a_1453(int a_F1,int a_A[1]); /* enterstring */
static void a_1454(int a_F1); /* extendBUFFER */
static void a_1455(int a_F1,int a_A[1]); /* gettagdata */
static void a_1456(int a_F1,int a_A[1]); /* gettagimage */
static int a_1457=0; /* inpt */
static int a_1458=0; /* inptvalue */
static int a_1459=0; /* lastchar */
static int a_1460=0; /* lastfilepos */
static int a_1461=0; /* lastinpt */
static int a_1462=0; /* lastinptvalue */
static void a_1463(void); /* nextchar */
static void a_1464(void); /* nextsymbol */
static void a_1465(int a_F1,int a_F2); /* puttagdata */
static void a_1466(int a_A[1]); /* readbold */
static void a_1467(int a_A[1]); /* readdestination */
static void a_1468(int a_A[1]); /* readstring */
static void a_1469(int a_A[1]); /* readtargetnumber */
static void a_1470(int a_A[2]); /* readtargetstring */
static void a_1471(int a_A[1]); /* readtype */
static void a_1472(void); /* rehash */
static void a_1473(void); /* restoreinputposition */
static void a_1474(void); /* saveinputposition */
static int a_1475=1; /* sourceline */
static void a_1476(int a_A[1]); /* trytoopensource */
static int a_1477=0; /* xnumber */
static void a_1479(void); /* pass1 */
static void a_1480(void); /* pass2 */
static void a_1481(void); /* pass3 */
static void a_1482(void); /* pass4 */
static void a_1483(void); /* pass5 */
static void a_1486(int a_F1,int a_F2,int a_F3); /* putstring */
#define a_1489 (a_1448+sizeof_CHFILE) /* STDARG */
static void a_1478(void); /* @main root */
static void a_1441(void); /* lexical root */
static void a_1362(void); /* arithmetic root */
static void a_1283(void); /* item root */
static void a_1004(void); /* number root */
#define BLOCK_TOTAL (a_1489+sizeof_LIST)
int a_DATABLOCK[BLOCK_TOTAL];
static int a_FILL[]={ /* fill table */
a_1001,/* @StringTable */
21,1953723757,0,4,4,1953067617,1952804200,25449,10,5,1702129253,1852793714,1953723507,1735289202,0,16,7,1685349735,1953064809,0,8,5,0,
a_1001,/* @StringTable */
36,1953723757,0,4,4,1885956979,1768318561,120,9,5,1885956979,1634496372,7103842,11,5,1885956979,1868787572,6385005,11,5,1635148897,1852138350,6644847,11,5,1684104562,1634038369,1702129257,1818326642,0,16,7,1701606770,1952671091,7237481,11,5,0,
a_1416,/* MESSAGE */
67,1634038369,544497952,540699685,1702326124,1868701810,543452789,1696625701,1701143416,1965060964,1919250544,1970233888,622879854,116,49,15,1634038369,544497952,540699685,1936287860,1953259808,1634628197,1702259060,1986358816,1931506277,1701012341,7562341,43,13,1953718636,1701994784,1952522337,980165920,1953459744,1819042080,1935762208,1629516645,1663067506,1919252079,25701,42,13,1935764579,1768319347,1769234787,1629515375,1814372468,1818304570,1937334647,1668641568,1684366691,115,37,12,1701606770,544220448,622883937,1763719788,1852401262,543519849,1886351212,1668180256,1768191340,1914726254,543517813,28709,46,14,0,
a_1001,/* @StringTable */
880,1953723757,0,4,4,29221,2,3,1130324268,1449091372,0,8,5,628967205,7218503,7,4,1193638697,125,5,4,31529,2,3,2647657,3,3,556295785,0,4,4,1668113773,1630042480,1630295647,623592543,1600203876,1680157251,2053731114,677801829,690583333,59,37,12,1147101501,1566844251,59,9,5,1348428093,1566844251,59,9,5,693133153,0,4,4,2650661,3,3,21541,2,3,1718181729,2650740,7,4,1630299173,623595615,10596,10,5,1630299173,2707551,7,4,725835617,1630299173,2704479,11,5,742612833,693526369,0,8,5,5267297,3,3,1668113773,1630042480,623592543,1600203876,1600203862,1680157251,2053731114,677801829,690583333,59,37,12,1531207521,1029530661,0,8,5,1531993953,1029530661,0,8,5,678588262,1768383858,1919251571,544679200,809332773,1013982523,994271073,724267045,1449091369,1567630683,997205309,28197,46,14,997205309,0,4,4,1734701691,1702130537,1998921842,1030759712,0,16,7,995370281,18213,6,4,1635213153,1868985449,10354,10,5,1130324285,625419579,110,9,5,1847936805,0,4,4,1735288167,1717662821,1853385062,111,13,6,1630037609,1027359583,628828465,1629519207,757941087,1449091387,1680162091,7218491,31,10,1630037609,826164063,1600224041,992816451,727080801,996418877,545081125,1847936805,0,32,11,622864943,791289968,625419579,110,13,6,123,1,3,6759712,3,3,1730509609,7218557,7,4,677800224,0,4,4,628828457,1847950695,0,8,5,26405,2,3,1635461417,1701994847,1634099041,1684368489,1881481768,1881484322,628964137,110,29,10,677800224,10273,6,4,31868,2,3,1014244648,544220477,622863910,624770160,10612,18,7,1027502117,29733,6,4,1027371045,29733,6,4,1027436581,29733,6,4,7218491,3,3,1768383858,1919251571,544679200,4026405,15,6,1281322868,676614985,757690405,1886740798,624765794,628964196,110,25,9,1734701691,1702130537,1998921842,1881483808,1700749629,1852142712,1852795251,745547048,992568357,0,36,12,626749477,4021604,7,4,1566844205,0,4,4,93,1,3,1281322868,676614985,757690405,1717989182,1534354803,0,20,8,1881481772,6105378,7,4,6563117,3,3,1281322868,676614985,757690405,1717989182,1534354803,1768709985,1818588275,623406437,11376,34,11,1835625556,1635021929,27753,10,5,1281322868,676614985,757690405,7349566,15,6,28709,2,3,627516704,110,5,4,1847933737,0,4,4,1952407840,1701011826,1819636319,622995557,623649392,100,21,8,1348428070,996418886,28197,10,5,1280070990,7218491,7,4,1380999009,1279870543,1629515845,1869770847,1701603686,15731,22,8,1885298976,1768320882,1735289196,1348428072,694428998,7218491,23,8,1348428070,694428998,7218491,11,5,1280070990,1847933737,0,8,5,1919967073,1818846831,1701076837,1600202854,1680164432,1881481772,11298,26,9,707731581,544220448,1847930666,0,12,6,623847968,110,5,4,707731579,7349536,7,4,706770725,1027891041,1869376609,1932026211,1868921449,1998923878,623389225,1680157540,1130324266,3877161,39,12,1629517605,626741343,3890532,11,5,1629517605,1680165983,59,9,5,16427,2,3,1713513003,0,4,4,1935498027,6118260,7,4,1566274603,0,4,4,1046560299,0,4,4,4088107,3,3,6372907,3,3,1735549300,1634563173,28265,10,5,678569248,1847933737,7218557,11,5,2002739488,1718905185,807957103,623456300,15188,18,7,678569248,995370281,0,8,5,1683972384,1600222305,1970562419,992553072,28197,18,7,1684631414,1381982496,676613967,1684631414,1847950121,0,20,8,7218557,3,3,1298096416,1330791503,623400015,622996594,623452784,110,21,8,1952543859,1981834089,543451503,1635213153,1868985449,1998923890,1180655904,1998924849,1180655904,628828466,110,41,13,1818190112,1601467241,1819044198,1180655912,692866121,2104370491,28197,26,9,1985962272,1970565737,1834970209,624782953,1600207728,1953655158,1600938357,1031299437,624652325,110,37,12,1952543859,1981834089,543451503,1633967969,1935630708,1886745701,1768912424,628828516,110,33,11,1629495328,1684300127,1818846815,1701994853,1915037793,745678124,992568357,539635488,706768933,7218479,39,12,1935630624,1886745701,1768318047,623404396,622996594,623649392,1915038820,745678124,992568357,539635488,706768933,7218479,47,14,1935630624,1886745701,1634231135,1818846834,1915037797,1881481772,1680157730,745678124,992571941,539635488,706768933,7218479,47,14,678438176,573338149,690122789,7218491,15,6,1935630624,1886745701,1936288863,1680156788,745678124,577774882,744760620,623670309,1680157812,790641449,1881481258,623847968,110,49,15,678438176,573338149,740454437,992568357,28197,18,7,1847929904,0,4,4,744760621,28197,6,4,791441957,1881481258,623847968,110,13,6,2909221,3,3,1769238133,2019913324,1836016500,24941,14,6,998060333,539635488,1819044198,1650553888,1931502956,543521385,706765861,7218479,31,10,1952543859,622879593,1600200823,1280067910,2067619163,539635488,1819044198,1650553888,706766188,7218479,39,12,1629517605,1413563487,1330397761,626740035,624647536,110,21,8,1717920803,543518313,673214501,623604261,1847929200,0,20,8,1717920803,543518313,807432229,28197,14,6,707731515,544220448,1953460082,623847968,110,17,7,707731515,1634549792,1914728041,544501615,1847930666,0,20,8,707731515,544220448,1847930666,0,12,6,707731497,544220448,1847930666,0,12,6,623604261,112,5,4,48,1,3,1717920803,543518313,673215013,0,12,6,1952543859,622879593,1915035767,997467453,539635488,706768933,7218479,27,9,1684631414,0,4,4,1629517605,1680164447,0,8,5,1629517605,623657823,1630150775,2709087,15,6,1629517605,626737503,23908,10,5,1952543859,1981834089,543451503,2650661,15,6,1952543859,622879593,1915035767,40,13,6,1159735855,706758223,7218479,11,5,1847948069,0,4,4,1717920803,543518313,1094934369,1398754380,1262698836,1130324256,1598835777,1128354899,7218507,35,11,622866223,622993520,1847927408,0,12,6,1075851055,1852399981,1881481760,7218466,15,6,1092626991,1213220172,1701013792,1852402720,544367979,778315126,539780133,1685221239,2053731104,1680162149,623847968,795747694,1768693807,1684368238,1685024032,1936026741,7218490,67,19,577774882,995370281,28197,10,5,1767995170,1919903348,1411721506,7218491,15,6,1280070990,995370281,28197,10,5,1633640736,1869898852,1818321759,1635021676,2648931,19,7,774778459,93,5,4,1415536955,1634027634,1629896036,1920224351,0,16,7,7630441,3,3,1852404336,1920233588,0,8,5,1819635291,23916,6,4,1852404336,1179992692,5391686,11,5,1953457952,8303,6,4,1952805408,544109173,15152,10,5,1952805408,997094005,0,8,5,1952805408,544109173,15153,10,5,1885695073,6499944,7,4,0,
a_1416,/* MESSAGE */
14,1852727651,1663071343,1952540018,1635000421,1952802674,1818846752,2015699045,1919229996,544370546,1701080931,1680154682,0,44,14,0,
a_1416,/* MESSAGE */
22,1702521203,1281320559,5526345,11,5,1702521203,1130325615,1279870536,69,13,6,1702521203,1147102831,1162627398,0,12,6,1129270338,1330929483,4997460,11,5,0,
a_1416,/* MESSAGE */
15,1701606770,1767995168,1919903348,1852776506,1696627052,2037674093,1685024032,543517813,1953460082,1847602291,1847620719,1701078373,100,49,15,0,
a_1416,/* MESSAGE */
28,1768710499,6648418,7,4,1651993697,0,4,4,1651537249,0,4,4,1651993718,0,4,4,1651537270,0,4,4,829579105,0,4,4,846356321,0,4,4,0,
a_1001,/* @StringTable */
45,1953723757,0,4,4,1634625894,1635149164,108,9,5,1634625894,1935762028,101,9,5,1936682860,1635149157,108,9,5,1684104562,1919973477,1769173861,28271,14,6,1667590243,1852793707,1851880563,1887007860,101,17,7,1667590243,1818321771,1701995113,1701869940,0,16,7,1667590243,1936288875,1887007860,101,13,6,0,
a_1416,/* MESSAGE */
14,540700709,1936617315,1953390964,1717920800,1953066601,544108393,1701209458,1948283762,1953046639,1718379891,1764042784,41,45,14,0,
a_1001,/* @StringTable */
84,1953723757,0,4,4,1920230771,1852993637,1700949365,114,13,6,1635017060,1952671091,1768845161,26985,14,6,1702131813,1818324594,1920233061,121,13,6,1635017060,1952671091,1768845161,105,13,6,1953720684,1920233061,121,9,5,1885956979,1819044198,1953066601,1768710505,7497082,19,7,1667590243,1818846827,1887007845,101,13,6,1667590243,1818846827,1852793708,1851880563,1887007860,101,21,8,1667590243,1852793707,1851880563,1887007860,101,17,7,1667590243,1936288875,1887007860,101,13,6,1635017060,1952671091,1768845161,0,12,6,1885956979,1635017060,1952671091,7237481,15,6,1885956979,1920233061,121,9,5,0,
a_1416,/* MESSAGE */
16,1713401893,980184169,1885696544,1702125925,1868767346,1635021678,622883950,1936269412,1953853216,543584032,1735287154,1831346277,622884961,10596,54,16,0,
a_1416,/* MESSAGE */
40,540700709,1634493810,1702259060,2053731104,1936007269,1634560372,544370548,1763730469,1970217075,1718558836,1851879968,673211751,2713893,51,15,540700709,1702521203,1953719584,1952542057,622883439,1936269412,1953853216,544370464,1735287154,623386725,10601,42,13,540700709,1702521203,1953719584,1952542057,622883439,1634214000,1869488243,1818326560,673211765,2713893,39,12,0,
a_1416,/* MESSAGE */
33,1819044198,543649385,540700709,622883937,1701978220,1952540016,622883429,1936269424,1953459744,1717920800,1684369001,0,44,14,1819044198,543649385,1629515813,1814372468,1635131450,543520108,1864393765,1701978214,1952540016,622883429,1936269424,1953853216,543584032,1735287154,1831346277,622884961,10596,66,19,0,
a_1416,/* MESSAGE */
9,1970499177,1667851878,1953391977,1919514144,1818326388,1634759456,25955,26,9,0,
a_1001,/* @StringTable */
37,1953723757,0,4,4,1851876211,1835365481,0,8,5,1684104552,1952671091,7237481,11,5,1684104562,1768318308,1769236846,1768713839,29811,18,7,1684104562,1835365481,0,8,5,1667590243,1702127979,4475245,11,5,1836216166,1717660769,1702390118,115,13,6,0,
a_1447,/* LEXT */
50,1920226112,1416064617,1701601889,0,12,6,0,0,1718184051,1717985652,1818392681,7037807,15,6,0,0,1635018087,2020173414,1668246626,7302763,15,6,0,0,1635205184,1868985449,114,9,5,0,0,1634549824,25963,6,4,0,0,1869574720,116,5,4,0,0,1801675106,1667330676,107,9,5,0,0,0,
a_1416,/* MESSAGE */
22,1701998445,1634235424,1852776558,1634541669,1830841961,1819632751,622869093,112,29,10,1886220131,1684368489,1919903264,1718182944,1701995878,1948284014,1701278305,1870078068,1931502706,6650473,39,12,0,
a_1416,/* MESSAGE */
43,1830842222,544106849,1969516397,25964,14,6,540700709,544501614,1768318308,543450478,622883937,105,21,8,540700709,1868787305,1952542829,1701601897,1887007776,1629516645,1764040820,1684955424,6890784,35,11,540700709,1651863396,1679849836,1852401253,1629512805,1764040820,1684955424,6890784,31,10,540700709,544501614,1701209458,1668179314,622879845,105,21,8,0,
a_1001,/* @StringTable */
9,1953067617,1952804200,25449,10,5,1869771365,114,5,4,0,
a_1447,/* LEXT */
43,1818308398,795373669,1768191091,792356195,796029813,1633906540,1818308460,6844517,31,10,0,0,1130656883,1701013806,0,8,5,0,0,926365233,909193783,0,8,5,0,0,808661298,875966519,12851,10,5,0,0,1668180259,1701082476,1818305056,1600680037,1701998435,2254894,23,8,0,0,0,
a_1416,/* MESSAGE */
188,1802398028,1162625312,1294813264,1667837472,1768300645,544433516,1629515636,1881162528,1919381362,623799649,1634948462,540697959,1852402785,760946795,1818585133,763109488,1919252013,1852795251,544089437,1919885344,1818304570,543911529,1953525595,1936617321,1768300637,540108140,1701603686,774774834,1332618542,1869182064,624587630,757080174,1950097519,1701278305,538984052,538976288,543516788,1886680431,773878901,1768300643,1847944556,1278025760,1768176672,538984050,538976288,1931485216,1768711284,1768169570,1952671090,628716143,757080174,1932357486,1768711284,538976354,538976288,661548900,1684086900,1953701988,1633971809,1814062194,1634886249,1847949682,1462575136,538976288,538976288,538976288,1914708000,1919905893,1869488244,1937055860,1881171045,1768710773,1953046627,628321637,757080174,538976359,538976288,538976288,538976288,1802398060,1953068832,1633886312,1931504748,1801675124,1718511904,1634562671,1852795252,1716088357,544173600,1886680431,1763734645,1886593139,1718182757,744777065,1701344288,1835101728,1718558821,1701344288,1767992608,1764630638,1713399139,543517801,1847948137,1684370293,1953068832,1663967336,1954047264,1769172581,1629515375,1730176110,1919250021,1684370529,544106784,543516788,1920103779,544501349,1701996900,1919906915,11897,474,121,1346718785,541928776,1802398060,1981837925,1769173605,622882415,1680158308,1866690085,1769109872,544499815,539575080,808595506,842019373,1632378932,1869380211,1769161504,2053205362,1750363685,1763734377,543236211,1701147238,1718580000,1918990196,1931488357,1948280165,1931502952,1668445551,1952522341,1953785888,792359792,1953064751,778204520,795701091,1769169772,2053205362,1701601583,1847945328,544370534,2037411683,1751607666,1852383348,1836216166,1869182049,1411395182,1701995880,544434464,1461735246,1095914049,995710030,1953459744,1702257952,1701650542,1851877475,1768057204,2037672300,628256544,1953064558,1936942446,1919903264,1881170208,1769239137,1634497891,1970282610,1936683122,11877,258,67,0,
a_1001,/* @StringTable */
42,1953723757,0,4,4,1852141679,1701603686,1634497377,29811,14,6,1769108595,1869899630,1179014466,21061,14,6,26413,2,3,22317,2,3,19501,2,3,28461,2,3,762277421,1818522739,25193,10,5,1702243629,1869181810,110,9,5,1701326125,28780,6,4,0,
a_1416,/* MESSAGE */
57,1763733358,1953853550,1818846752,1886593125,1718182757,744777065,1702065440,1747791136,544238693,544370534,1752375393,544502383,1886152040,0,52,16,1936943469,543649385,1969713761,1953391981,1952866592,757101157,25381,26,9,1769496941,544044397,1651340654,1864397413,1869815910,1701016181,623386739,1696606564,1701143416,6579556,39,12,1869771365,1886330994,1852403301,1764630631,1713399139,543517801,2125861,27,9,1700949349,1684366436,1852385056,1685417059,1763714917,1713399139,1936026729,544106784,28709,34,11,0,
a_1001,/* @StringTable */
36,1953723757,0,4,4,774778459,93,5,4,6111067,3,3,1685024040,543517813,0,8,5,1852404336,1935762036,101,9,5,1852404336,1768910964,1919251566,0,12,6,1280659035,23884,6,4,1953709116,1953853284,15934,10,5,0,
a_1416,/* MESSAGE */
41,544173940,2037277037,1920099616,745763439,1920296480,1919248500,1936026912,1701273971,1918967923,1970479205,1701998704,1684370291,0,48,15,1702129257,1818324594,1920099616,1629516399,1970413684,2123116,23,8,1650532396,1702130287,100,9,5,540700709,1920102243,544501877,1701013806,1818846752,2629733,23,8,1629498409,1953656674,25701,10,5,0,
a_1001,/* @StringTable */
51,1954047342,1651341683,27759,10,5,1684104562,1701869940,0,8,5,1684104562,1684828002,0,8,5,1684104562,1735549300,1953723493,1735289202,0,16,7,1684104562,1769108595,26478,10,5,1634231666,26739,6,4,1684104562,1953719652,1952542313,7237481,15,6,1684104562,1701080681,120,9,5,1885695073,1667837544,101,9,5,1953723757,0,4,4,0,
a_1447,/* LEXT */
5,0,0,3,0,0,0,
a_1442,/* BOLD */
270,1634038369,0,4,4,1801675106,0,4,4,7892834,3,3,1768710499,6648418,7,4,1919973477,1769173861,28271,10,5,1702131813,1869181806,110,9,5,1702131813,1818324594,0,8,5,1701603686,0,4,4,1819044198,0,4,4,1852797542,116,5,4,1818455657,6644853,7,4,1953720684,0,4,4,6453100,3,3,1852399981,0,4,4,1969516397,25964,6,4,1701080942,0,4,4,1701606770,0,4,4,28532,2,3,6451317,3,3,1651993718,0,4,4,1651537270,0,4,4,1936617315,1953390964,0,8,5,1769103734,1701601889,0,8,5,1952543859,1981834089,29281,10,5,1818386804,101,5,4,1667331187,107,5,4,1952543859,1931502441,1801675124,0,12,6,1852403568,544367988,1936617315,1953390964,0,16,7,1918986339,1701603686,0,8,5,1635017060,1701603686,0,8,5,1701606770,0,4,4,1836216166,1931504737,1801675124,0,12,6,1836216166,1948281953,1701601889,0,12,6,1836216166,1713400929,6646889,11,5,1836216166,1763732577,110,9,5,1836216166,1864395873,29813,10,5,1836216166,1763732577,1953853294,0,12,6,1836216166,1629514849,1869112174,114,13,6,1836216166,1931504737,1952868712,0,12,6,64,1,3,38,1,3,93,1,3,41,1,3,58,1,3,44,1,3,126,1,3,47,1,3,45,1,3,35,1,3,40,1,3,124,1,3,62,1,3,43,1,3,46,1,3,59,1,3,42,1,3,91,1,3,94,1,3,1936617315,116,5,4,1651340654,29285,6,4,1701869940,0,4,4,1701080942,0,4,4,1835365481,0,4,4,1836216166,27745,6,4,1633906540,108,5,4,1769108595,26478,6,4,2763306,3,3,0,
-1}; /* fill table size 2305 */
static void a_data_setup(void){
 a_virtual_min=16777216;a_virtual_max=2130706432;
 a_setup_list(0,a_1001,"@StringTable",1,2130705156,2130706396,1241); /* @StringTable */
 a_setup_list(1,a_1005,"NUMBER",1,2075075499,2130705154,0); /* NUMBER */
 a_setup_list(1,a_1032,"NODE",6,1769111777,2047260051,0); /* NODE */
 a_setup_list(1,a_1033,"ZONE",3,2047260670,2075075495,0); /* ZONE */
 a_setup_list(1,a_1213,"EXPRESSION",1,1574407975,1769111770,0); /* EXPRESSION */
 a_setup_list(1,a_1284,"AUX",6,739963127,1018111401,0); /* AUX */
 a_setup_list(1,a_1285,"ITEM",7,1018111414,1574407967,0); /* ITEM */
 a_setup_list(1,a_1363,"REGISTER",1,155851633,183666460,0); /* REGISTER */
 a_setup_list(1,a_1380,"FILES",3,128036804,155851629,0); /* FILES */
 a_setup_list(0,a_1416,"MESSAGE",1,2047260058,2047260666,609); /* MESSAGE */
 a_setup_list(0,a_1442,"BOLD",1,16777217,16777486,270); /* BOLD */
 a_setup_list(1,a_1443,"BUFFER",1,72407145,128036800,0); /* BUFFER */
 a_setup_list(1,a_1444,"HASH",1,16777488,72407143,0); /* HASH */
 a_setup_list(1,a_1447,"LEXT",2,183666463,739963119,98); /* LEXT */
 a_setup_stdarg(a_1489,"STDARG",1);
 a_setup_charfile(a_1103,"TARGET",2,a_1001,2130706092); /* TARGET */
 a_setup_charfile(a_1417,"PRINTFILE",2,a_1001,2130706345); /* PRINTFILE */
 a_setup_charfile(a_1448,"SOURCE",1,a_1001,2130706392); /* SOURCE */
 a_list_fill(a_FILL);
}
static void a_waitfor(int a_F1,int a_F2){
 a_MODROOT(a_1441,"lexical")
 a_MODROOT(a_1362,"arithmetic")
 a_MODROOT(a_1283,"item")
 a_MODROOT(a_1004,"number")
}
void a_ROOT(void){
 a_data_setup();
 a_waitfor(0,0); a_1478();
}
static void a_1009(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1443,1);a_r1[0]=a_F1;to_LIST(a_1443)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1017(int a_F1,int a_F2,int a_A[1]){ /* loadregister+>a+>a+a> */
int a_P[1];
if(!a_equal(a_F1,0)){ goto a_G3;}
a_1372(a_1005,a_F2,a_P);a_A[0]=a_P[0]; return;
a_G3:if(!a_equal(a_F1,2)){ goto a_G5;}
a_1364(a_F2,a_P);a_A[0]=a_P[0]; return;
a_G5:a_1371(a_F2,a_P);a_A[0]=a_P[0]; return;
} /* loadregister */
static int a_1023(int a_F1){ /* samenumberblock+>a */
int a_L2;int a_L3;
a_L2=to_LIST(a_1005)->aupb;
a_L3=0;
a_G3:if(a_mreq(a_L3,a_1376)){ return 1;}
if(!a_equal(to_LIST(a_1005)->offset[a_F1],to_LIST(a_1005)->offset[a_L2])){ return 0;}
a_incr(a_L3);
a_decr(a_F1);
a_decr(a_L2); goto a_G3;
} /* samenumberblock */
static void a_1024(int a_F1,int a_A[1]){ /* storeregister+>a+a> */
int a_L3;int a_L4;
a_L3=to_LIST(a_1005)->aupb;
a_A[0]=a_1027;
a_L4=0;
a_1377(a_F1,a_1005);
a_G5:if(a_more(a_A[0],a_L3)){ return;}
if(!a_1023(a_A[0])){ goto a_G8;}
a_unstackto(a_1005,a_L3); return;
a_G8:if(!a_more(a_L4,100)){ goto a_G10;}
a_A[0]=to_LIST(a_1005)->aupb; return;
a_G10:a_incr(a_L4);
a_add(a_A[0],a_1376,a_A[0]); goto a_G5;
} /* storeregister */
static void a_1012(int a_A[1]){ /* getnumberzero+a> */

a_A[0]=a_1027; return;
} /* getnumberzero */
static void a_1014(int a_F1,int a_A[1]){ /* gettargetnumbervalue+>a+a> */
int a_L3;int a_P[1];
a_1372(a_1005,a_F1,a_P);a_L3=a_P[0];
a_1367(a_L3,a_P);a_A[0]=a_P[0]; return;
} /* gettargetnumbervalue */
static void a_1010(int a_F1,int a_A[1]){ /* getdigit+>a+a> */

{register int a_r1=to_LIST(a_1443)->offset[a_F1];
 if(!((48<=a_r1 && a_r1<=57))){ goto a_G3;}
}
a_subtr(to_LIST(a_1443)->offset[a_F1],48,a_A[0]); return;
a_G3:a_1423(a_1001,2130705176); return;
} /* getdigit */
static void a_1006(int a_F1,int a_F2){ /* adddigit+>a+>a */
int a_L3;int a_P[1];
a_1371(10,a_P);a_L3=a_P[0];
a_1375(8,a_L3,a_F1);
a_1371(a_F2,a_P);a_L3=a_P[0];
a_1375(6,a_L3,a_F1); return;
} /* adddigit */
static void a_1007(int a_F1,int a_F2,int a_A[1]){ /* enterconststring+>a+>a+a> */
int a_L4;int a_L5;int a_P[1];
a_1371(0,a_P);a_L4=a_P[0];
a_G2:a_incr(a_F2);
if(a_more(a_F2,to_LIST(a_1443)->aupb)){ goto a_G13;}
a_1010(a_F2,a_P);a_L5=a_P[0];
if(!a_1374(21,a_L4,a_1018)){ goto a_G7;}
a_G6:a_1006(a_L4,a_L5); goto a_G2;
a_G7:if(!a_1374(21,a_L4,a_1018)){ goto a_G9;}
a_G8:a_1418(a_1001,2130705171); return;
a_G9:if(a_less(a_L5,a_1016)){ goto a_G6;}
if(a_less(a_L5,a_1016)){ goto a_G8;}
if(!a_is(a_F1)){ goto a_G8;}
if(a_equal(a_F2,to_LIST(a_1443)->aupb)){ goto a_G6;} goto a_G8;
a_G13:if(!a_is(a_F1)){ goto a_G15;}
a_1375(5,a_L4,a_L4);
a_G15:a_1024(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* enterconststring */
static void a_1011(int a_F1){ /* getnumberrepr+>a */
int a_L2;int a_P[1];
a_1372(a_1005,a_F1,a_P);a_L2=a_P[0];
if(!a_1374(23,a_1022,a_L2)){ goto a_G11;}
a_1365(a_L2);
a_1009(40);
a_1009(45);
a_1009(49);
a_1009(45);
a_1364(a_1021,a_P);a_L2=a_P[0];
a_1013(a_L2);
a_1009(41); return;
a_G11:if(!a_1373(11,a_L2)){ goto a_G14;}
a_1375(5,a_L2,a_L2);
a_1009(45);
a_G14:a_1013(a_L2); return;
} /* getnumberrepr */
static void a_1013(int a_F1){ /* getregisterrepr+>a */
int a_L2;int a_L3;int a_P[1];
a_1364(a_F1,a_P);a_L2=a_P[0];
a_1371(10,a_P);a_L3=a_P[0];
a_1375(9,a_L3,a_L2);
if(a_1373(10,a_L2)){ goto a_G7;}
a_1364(a_L2,a_P);a_L3=a_P[0];
a_1013(a_L3);
a_G7:a_1371(10,a_P);a_L3=a_P[0];
a_1375(8,a_L3,a_L2);
a_1375(7,a_L2,a_F1);
a_1367(a_F1,a_P);a_L3=a_P[0];
a_add(a_L3,48,a_L3);
a_1009(a_L3); return;
} /* getregisterrepr */
static int a_1019(int a_F1,int a_F2){ /* minmaxregisters+>a+>a */

if(!a_1374(23,a_F1,a_1022)){ return 0;}
if(!a_1374(23,a_F2,a_1021)){ return 0;} return 1;
} /* minmaxregisters */
static void a_1008(int a_F1,int a_A[2]){ /* entertargetstring+>a+a>+a> */
int a_L4;int a_L5;int a_L6;int a_P[1];
a_subtr(to_LIST(a_1443)->aupb,a_F1,a_L4);
a_packstring(a_1443,a_L4,a_1447);
a_copystring(a_1447,to_LIST(a_1447)->aupb,a_1443);
a_unstackstring(a_1447);
a_stringwidth(a_1443,to_LIST(a_1443)->aupb,a_A[0]);
a_L5=a_A[0];
a_G7:if(!a_less(a_L5,1)){ goto a_G9;}
a_A[1]=to_LIST(a_1005)->aupb; return;
a_G9:a_1017(1,to_LIST(a_1443)->offset[to_LIST(a_1443)->aupb],a_P);a_L6=a_P[0];
a_1377(a_L6,a_1005);
a_decr(a_L5);
a_unstack(a_1443); goto a_G7;
} /* entertargetstring */
static void a_1020(int a_A[2]){ /* nexttargetstringvalue+>a>+a> */
int a_L3;
if(!a_more(a_A[0],1)){ goto a_G7;}
a_decr(a_A[0]);
a_L3=to_LIST(a_1005)->aupb;
a_subtr(a_L3,a_1376,a_L3);
a_unstackto(a_1005,a_L3);
a_A[1]=to_LIST(a_1005)->aupb; return;
a_G7:if(!a_equal(a_A[0],1)){ goto a_G12;}
a_decr(a_A[0]);
a_L3=to_LIST(a_1005)->aupb;
a_subtr(a_L3,a_1376,a_L3);
a_unstackto(a_1005,a_L3);
a_G12:a_A[1]=0; return;
} /* nexttargetstringvalue */
static void a_1015(void){ /* initializenumbers */
int a_L1;int a_L2;int a_L3;int a_P[1];
a_1371(0,a_P);a_L1=a_P[0];
a_1377(a_L1,a_1005);
a_1027=to_LIST(a_1005)->aupb;
a_1371(0,a_P);a_1021=a_P[0];
a_1371(1,a_P);a_L1=a_P[0];
a_L3=1;
a_G7:if(a_mreq(a_L3,32)){ goto a_G13;}
a_1364(a_L1,a_P);a_L2=a_P[0];
a_1375(3,a_L2,a_1021);
a_1364(a_L1,a_P);a_L2=a_P[0];
a_1375(6,a_L2,a_L1);
a_incr(a_L3); goto a_G7;
a_G13:a_1364(a_L1,a_P);a_1022=a_P[0];
a_1365(a_L1);
a_1364(a_1021,a_P);a_1018=a_P[0];
a_1371(10,a_P);a_L2=a_P[0];
a_1375(9,a_L2,a_1018);
a_1364(a_1018,a_P);a_L2=a_P[0];
a_1371(10,a_P);a_L1=a_P[0];
a_1375(8,a_L1,a_L2);
a_1364(a_1021,a_P);a_L1=a_P[0];
a_1375(7,a_L2,a_L1);
a_1367(a_L1,a_P);a_1016=a_P[0];
a_incr(a_1016);
a_1024(a_1022,a_P);a_1026=a_P[0];
a_1024(a_1021,a_P);a_1025=a_P[0]; return;
} /* initializenumbers */
static void a_1004(void){ /* @root */

a_waitfor(a_1001,2130705164);a_1015(); return;
} /* @root */
static void a_1080(void){ /* rulesection */

a_G1:if(!a_equal(16777285,a_1457)){ goto a_G4;}
a_1464();
a_1067(); goto a_G1;
a_G4:if(!a_equal(16777486,a_1457)){ goto a_G6;}
a_1464(); return;
a_G6:a_1418(a_1001,2130705212); return;
} /* rulesection */
static void a_1090(void){ /* skiprule */

a_G1:if(!a_equal(16777439,a_1457)){ goto a_G3;}
a_G2:a_1464(); return;
a_G3:if(a_equal(16777486,a_1457)){ goto a_G2;}
a_1464(); goto a_G1;
} /* skiprule */
static void a_1059(int a_A[1]){ /* getitemdef+>a> */

if(!a_1323(a_A[0],8)){ return;}
a_A[0]=to_LIST(a_1285)->offset[a_A[0]]; return;
} /* getitemdef */
static void a_1050(int a_F1,int a_F2){ /* findintervalpair+>a+>a */
int a_L3;
if(a_1374(22,a_F2,to_LIST(a_1033)->offset[a_F1-1])){ return;}
a_L3=to_LIST(a_1033)->offset[a_F1];
to_LIST(a_1033)->offset[a_F1-1]=a_F2;
a_G4:if(!a_equal(a_L3,0)){ goto a_G6;}
to_LIST(a_1033)->offset[a_F1]=0; return;
a_G6:if(!a_1374(21,a_F2,to_LIST(a_1033)->offset[a_L3-2])){ goto a_G8;}
to_LIST(a_1033)->offset[a_F1]=a_L3; return;
a_G8:if(!a_1374(22,a_F2,to_LIST(a_1033)->offset[a_L3-1])){ goto a_G11;}
to_LIST(a_1033)->offset[a_F1-1]=to_LIST(a_1033)->offset[a_L3-1];
to_LIST(a_1033)->offset[a_F1]=to_LIST(a_1033)->offset[a_L3]; return;
a_G11:a_L3=to_LIST(a_1033)->offset[a_L3]; goto a_G4;
} /* findintervalpair */
static void a_1034(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* addinterval+>a+>a+>a+>a> */
int a_L5;
a_G1:a_L5=to_LIST(a_1033)->offset[a_F1];
if(!a_equal(a_L5,0)){ goto a_G6;}
a_A[0]=1;
{register int *a_r1=a_extension(a_1033,3);a_r1[0]=a_F2;a_r1[1]=a_F3;a_r1[2]=0;to_LIST(a_1033)->aupb+=3;}
a_G5:to_LIST(a_1033)->offset[a_F1]=to_LIST(a_1033)->aupb; return;
a_G6:if(!a_1374(21,a_F2,to_LIST(a_1033)->offset[a_L5-2])){ goto a_G12;}
a_A[0]=1;
if(!a_1374(21,a_F3,to_LIST(a_1033)->offset[a_L5-2])){ goto a_G10;}
{register int *a_r1=a_extension(a_1033,3);a_r1[0]=a_F2;a_r1[1]=a_F3;a_r1[2]=a_L5;to_LIST(a_1033)->aupb+=3;}
  goto a_G5;
a_G10:to_LIST(a_1033)->offset[a_L5-2]=a_F2;
a_G11:a_1050(a_L5,a_F3); return;
a_G12:if(!a_1374(22,a_F2,to_LIST(a_1033)->offset[a_L5-1])){ goto a_G15;}
if(a_1374(22,a_F3,to_LIST(a_1033)->offset[a_L5-1])){ return;}
a_A[0]=1; goto a_G11;
a_G15:a_F1=a_L5; goto a_G1;
} /* addinterval */
static void a_1070(int a_F1){ /* mergeintervals+>a */
int a_L2;
a_G1:if(a_equal(to_LIST(a_1033)->offset[a_F1],0)){ return;}
a_F1=to_LIST(a_1033)->offset[a_F1];
a_L2=to_LIST(a_1033)->offset[a_F1];
a_G4:if(!a_noteq(a_L2,0)){ goto a_G1;}
if(!a_1374(20,to_LIST(a_1033)->offset[a_F1-1],to_LIST(a_1033)->offset[a_L2-2])){ goto a_G1;}
to_LIST(a_1033)->offset[a_F1-1]=to_LIST(a_1033)->offset[a_L2-1];
{register int a_r1=to_LIST(a_1033)->offset[a_L2];to_LIST(a_1033)->offset[a_F1]=a_r1;a_L2=a_r1;} goto a_G4;
} /* mergeintervals */
static int a_1043(int a_F1){ /* completezone+>a */

a_F1=to_LIST(a_1033)->offset[a_F1];
if(!a_is(a_F1)){ return 0;}
if(!a_1019(to_LIST(a_1033)->offset[a_F1-2],to_LIST(a_1033)->offset[a_F1-1])){ return 0;} return 1;
} /* completezone */
static void a_1076(int a_A[2]){ /* readareainterval+a>+a> */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[1];
if(!a_equal(16777459,a_1457)){ goto a_G6;}
a_A[0]=a_1458;
a_1464();
a_G4:a_A[1]=a_A[0];
a_L4=1; goto a_G26;
a_G6:if(!a_equal(16777471,a_1457)){ goto a_G23;}
a_L3=a_1458;
a_1464();
a_P[0]=a_L3;a_1059(a_P);a_L3=a_P[0];
{register int a_r1=to_LIST(a_1285)->offset[a_L3-5];
 if(a_r1==16777304||a_r1==16777335){ goto a_G11;}
 if(a_r1==16777322||a_r1==16777318||a_r1==16777328){ goto a_G12;}
  goto a_G22;}
a_G11:a_A[0]=to_LIST(a_1285)->offset[a_L3]; goto a_G4;
a_G12:a_1317(a_L3,a_P);a_A[0]=a_P[0];
a_1017(0,a_A[0],a_P);a_L5=a_P[0];
a_1307(a_L3,a_P);a_A[1]=a_P[0];
a_1017(1,a_A[1],a_P);a_L6=a_P[0];
a_1375(7,a_L6,a_L5);
a_1017(1,1,a_P);a_L6=a_P[0];
a_1375(6,a_L6,a_L5);
a_1024(a_L5,a_P);a_A[0]=a_P[0];
a_1318(a_L3,a_P);a_A[1]=a_P[0];
a_L4=2; goto a_G26;
a_G22:a_1418(a_1001,2130705207); return;
a_G23:a_1012(a_P);a_A[0]=a_P[0];
a_1012(a_P);a_A[1]=a_P[0];
a_L4=0;
a_G26:if(!a_equal(16777409,a_1457)){ goto a_G41;}
a_1464();
if(!a_equal(a_L4,0)){ goto a_G30;}
a_A[0]=a_1026; goto a_G31;
a_G30:if(!a_equal(a_L4,1)){ goto a_G22;}
a_G31:if(!a_equal(16777459,a_1457)){ goto a_G34;}
a_A[1]=a_1458;
a_1464(); return;
a_G34:if(!a_equal(16777471,a_1457)){ goto a_G40;}
a_L3=a_1458;
a_1464();
a_P[0]=a_L3;a_1059(a_P);a_L3=a_P[0];
{register int a_r1=to_LIST(a_1285)->offset[a_L3-5];
 if(!(a_r1==16777304||a_r1==16777335)){ goto a_G22;}
}
a_A[1]=to_LIST(a_1285)->offset[a_L3]; return;
a_G40:a_A[1]=a_1025; return;
a_G41:if(!a_equal(a_L4,0)){ return;} goto a_G22;
} /* readareainterval */
static void a_1037(int a_F1,int a_A[1]){ /* checkarea+>a+a> */
int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_P[4];
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_A[0]=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130705180); return;
a_G5:a_L3=0;
a_G6:a_1076(a_P);a_L4=a_P[0];a_L5=a_P[1];
a_1017(0,a_L4,a_P);a_L6=a_P[0];
a_1017(0,a_L5,a_P);a_L7=a_P[0];
if(!a_1374(22,a_L6,a_L7)){ goto a_G11;}
a_P[0]=a_L3;a_1034(a_F1,a_L6,a_L7,a_P);a_L3=a_P[0]; goto a_G12;
a_G11:a_P[0]=2047260072;a_P[1]=a_A[0];a_P[2]=a_L4;a_P[3]=a_L5;a_1419(4,a_P);
a_G12:if(!a_equal(16777442,a_1457)){ goto a_G14;}
a_1464(); goto a_G6;
a_G14:a_1070(a_F1);
if(a_is(a_L3)){ return;}
a_P[0]=2047260085;a_P[1]=a_A[0];a_1419(2,a_P); return;
} /* checkarea */
static void a_1038(void){ /* checkareas */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[2];
a_scratch(a_1033);
{register int *a_r1=a_extension(a_1033,3);a_r1[0]=a_r1[1]=a_r1[2]=0;to_LIST(a_1033)->aupb+=3;}
a_L1=to_LIST(a_1033)->aupb;
a_1370(a_P);a_L4=a_P[0];
a_L2=0;a_L3=0;
a_G6:if(!a_equal(16777220,a_1457)){ goto a_G14;}
a_1464();
a_incr(a_L3);
a_1037(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(16777433,a_1457)){ goto a_G13;}

a_1464(); goto a_G6;
a_G13:a_1418(a_1001,2130705180); return;
a_G14:if(!a_1043(a_L1)){ goto a_G18;}
a_1086(2048);
if(a_more(a_L3,1)){ goto a_G19;}
a_P[0]=2047260110;a_P[1]=a_L2;a_1419(2,a_P); goto a_G19;
a_G18:a_P[0]=2047260098;a_P[1]=a_L2;a_1439(2,a_P);
a_G19:a_1366(a_L4); return;
} /* checkareas */
static void a_1086(int a_F1){ /* setnodeflag+>a */

a_boolor(a_F1,to_LIST(a_1032)->offset[a_1100-4],to_LIST(a_1032)->offset[a_1100-4]); return;
} /* setnodeflag */
static void a_1075(int a_F1,int a_F2){ /* putnodeflag+>a+>a */

a_boolor(a_F2,to_LIST(a_1032)->offset[a_F1-4],to_LIST(a_1032)->offset[a_F1-4]); return;
} /* putnodeflag */
static void a_1040(int a_F1,int a_F2){ /* clearnodeflag+>a+>a */

a_boolinvert(a_F2,a_F2);
a_booland(a_F2,to_LIST(a_1032)->offset[a_F1-4],to_LIST(a_1032)->offset[a_F1-4]); return;
} /* clearnodeflag */
static void a_1045(void){ /* createnodes */
int a_L1;
a_scratch(a_1032);
if(!a_equal(16777455,a_1457)){ goto a_G5;}
a_L1=a_1458;
a_1464(); goto a_G6;
a_G5:a_1418(a_1001,2130705180); return;
a_G6:if(a_equal(a_L1,0)){ return;}
{register int *a_r1=a_extension(a_1032,6);a_r1[0]=a_r1[1]=a_r1[2]=a_r1[3]=a_r1[4]=a_r1[5]=0;to_LIST(a_1032)->aupb+=6;}
a_decr(a_L1); goto a_G6;
} /* createnodes */
static void a_1035(void){ /* advancenode */

if(!a_equal(16777467,a_1457)){ goto a_G4;}

a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130705180); return;
a_G5:if(!a_equal(a_1100,0)){ goto a_G7;}
a_1100=to_LIST(a_1032)->alwb; goto a_G8;
a_G7:a_next(a_1032,a_1100);
a_G8:if(a_lseq(a_1100,to_LIST(a_1032)->aupb)){ return;}
a_1418(a_1001,2130705200); return;
} /* advancenode */
static void a_1060(int a_F1,int a_A[1]){ /* getnodeindex+>a+a> */

a_subtr(a_F1,to_LIST(a_1032)->alwb,a_A[0]);
a_div(a_A[0],6,a_A[0]);
a_incr(a_A[0]); return;
} /* getnodeindex */
static void a_1062(int a_F1,int a_A[1]){ /* indextonode+>a+a> */

a_decr(a_F1);
a_addmult(a_F1,6,to_LIST(a_1032)->alwb,a_A[0]); return;
} /* indextonode */
static void a_1087(void){ /* setrulehead */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130705180); return;
a_G5:a_P[0]=a_L1;a_1059(a_P);a_L1=a_P[0];
to_LIST(a_1032)->offset[a_1100-3]=a_L1;
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L2=a_1458;
a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L3=a_1458;
a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L4=a_1458;
a_1464();
if(a_1323(a_L1,12288)){ return;}
if(!a_1323(a_L1,16384)){ goto a_G19;}
a_1086(8); return;
a_G19:a_max(a_L2,a_1029);
a_max(a_L3,a_1030);
a_max(a_L4,a_1031); return;
} /* setrulehead */
static void a_1091(void){ /* skiprulehead */

a_1464();
a_1464();
a_1464();
a_1464(); return;
} /* skiprulehead */
static void a_1041(void){ /* clearstacksize */

a_1029=0;a_1030=0;a_1031=0; return;
} /* clearstacksize */
static void a_1068(int a_F1){ /* marklocalaffix+>a */

if(a_equal(a_1046,0)){ return;}
a_add(a_1065,a_F1,a_F1);
to_LIST(a_1443)->offset[a_F1]=1; return;
} /* marklocalaffix */
static void a_1094(int a_F1,int a_F2){ /* startlocalaffixcheck+>a+>a */
int a_P[1];
if(!a_equal(a_F1,0)){ goto a_G3;}
a_1046=0; return;
a_G3:a_1046=1;
a_subtr(to_LIST(a_1443)->aupb,a_F1,a_1065);
a_incr(a_1065);
a_G6:if(a_more(a_F1,a_F2)){ return;}
a_P[0]=0;a_1074(1,a_P);
a_incr(a_F1); goto a_G6;
} /* startlocalaffixcheck */
static void a_1092(void){ /* skiptocomma */
int a_L1;
a_G1:if(!a_equal(16777412,a_1457)){ goto a_G3;}
a_1464(); return;
a_G3:if(!a_equal(16777479,a_1457)){ goto a_G7;}
a_L1=a_1458;
a_1464();
a_1068(a_L1); goto a_G1;
a_G7:if(!a_equal(16777448,a_1457)){ goto a_G9;}
a_G8:a_1464(); goto a_G1;
a_G9:if(!a_equal(16777486,a_1457)){ goto a_G8;}
a_1464();
a_1418(a_1001,2130705195); return;
} /* skiptocomma */
static void a_1093(int a_A[1]){ /* skiptolabel+a> */

a_G1:if(!a_equal(16777433,a_1457)){ goto a_G4;}
a_A[0]=a_1458;
a_1464(); return;
a_G4:if(!a_equal(16777486,a_1457)){ goto a_G7;}
a_1464();
a_1418(a_1001,2130705190); return;
a_G7:a_1464(); goto a_G1;
} /* skiptolabel */
static int a_1063(void){ /* islimit */

if(!a_equal(16777231,a_1457)){ goto a_G3;}
a_G2:a_1464(); return 1;
a_G3:if(a_equal(16777269,a_1457)){ goto a_G2;}
if(a_equal(16777291,a_1457)){ goto a_G2;}
if(a_equal(16777295,a_1457)){ goto a_G2;}
if(!a_equal(16777299,a_1457)){ return 0;} goto a_G2;
} /* islimit */
static void a_1089(void){ /* skiplist */

if(!a_equal(16777475,a_1457)){ goto a_G3;}
a_G2:a_1464(); return;
a_G3:if(!a_equal(16777471,a_1457)){ goto a_G5;}
 goto a_G2;
a_G5:a_1418(a_1001,2130705180); return;
} /* skiplist */
static void a_1088(void){ /* skipaffix */
int a_L1;
if(!a_equal(16777409,a_1457)){ goto a_G3;}
a_1464();
a_G3:if(!a_equal(16777475,a_1457)){ goto a_G5;}
a_G4:a_1464(); return;
a_G5:if(!a_equal(16777479,a_1457)){ goto a_G9;}
a_L1=a_1458;
a_1464();
a_1068(a_L1); return;
a_G9:if(a_equal(16777471,a_1457)){ goto a_G4;}
if(a_equal(16777424,a_1457)){ goto a_G4;}
if(a_equal(16777459,a_1457)){ goto a_G4;}
if(!a_1063()){ goto a_G14;}
a_1089(); return;
a_G14:if(!a_equal(16777448,a_1457)){ goto a_G24;}
a_1464();
a_1089();
a_1088();
if(!a_equal(16777403,a_1457)){ goto a_G21;}

a_1464(); goto a_G22;
a_G21:a_1418(a_1001,2130705180); return;
a_G22:if(!a_equal(16777455,a_1457)){ goto a_G21;}
 goto a_G4;
a_G24:a_1418(a_1001,2130705185); return;
} /* skipaffix */
static void a_1074(int a_C,int *a_V){ /* pushBUFFER+@+>a */

a_G1:{register int *a_r1=a_extension(a_1443,1);a_r1[0]=a_V[0];to_LIST(a_1443)->aupb+=1;}
if(a_C>1){a_C--;a_V+=1; goto a_G1;}  return;
} /* pushBUFFER */
static void a_1097(int a_F1){ /* storelist+>a */
int a_L2;int a_P[3];
if(!a_equal(16777475,a_1457)){ goto a_G5;}
a_L2=a_1458;
a_1464();
a_P[0]=a_F1;a_P[1]=16777475;a_P[2]=a_L2;a_1074(3,a_P); return;
a_G5:if(!a_equal(16777471,a_1457)){ goto a_G8;}
a_L2=a_1458;
a_1464(); goto a_G9;
a_G8:a_1418(a_1001,2130705180); return;
a_G9:a_P[0]=a_L2;a_1059(a_P);a_L2=a_P[0];
a_P[0]=a_F1;a_P[1]=16777471;a_P[2]=a_L2;a_1074(3,a_P); return;
} /* storelist */
static void a_1096(void){ /* storelimit */

if(!a_equal(16777269,a_1457)){ goto a_G4;}
a_1464();
a_1097(16777269); return;
a_G4:if(!a_equal(16777291,a_1457)){ goto a_G7;}
a_1464();
a_1097(16777291); return;
a_G7:if(!a_equal(16777295,a_1457)){ goto a_G10;}
a_1464();
a_1097(16777295); return;
a_G10:if(!a_equal(16777299,a_1457)){ goto a_G13;}
a_1464();
a_1097(16777299); return;
a_G13:if(!a_equal(16777231,a_1457)){ goto a_G16;}

a_1464(); goto a_G17;
a_G16:a_1418(a_1001,2130705180); return;
a_G17:a_1097(16777231); return;
} /* storelimit */
static void a_1095(void){ /* storeaffix */
int a_L1;int a_P[2];
if(!a_equal(16777475,a_1457)){ goto a_G5;}
a_L1=a_1458;
a_1464();
a_P[0]=16777475;a_P[1]=a_L1;a_1074(2,a_P); return;
a_G5:if(!a_equal(16777479,a_1457)){ goto a_G9;}
a_L1=a_1458;
a_1464();
a_P[0]=16777479;a_P[1]=a_L1;a_1074(2,a_P); return;
a_G9:if(!a_equal(16777471,a_1457)){ goto a_G14;}
a_L1=a_1458;
a_1464();
a_P[0]=a_L1;a_1059(a_P);a_L1=a_P[0];
a_P[0]=16777471;a_P[1]=a_L1;a_1074(2,a_P); return;
a_G14:if(!a_equal(16777459,a_1457)){ goto a_G18;}
a_L1=a_1458;
a_1464();
a_P[0]=16777459;a_P[1]=a_L1;a_1074(2,a_P); return;
a_G18:if(!a_equal(16777448,a_1457)){ goto a_G30;}
a_1464();
a_1097(16777448);
a_1095();
if(!a_equal(16777403,a_1457)){ goto a_G25;}

a_1464(); goto a_G26;
a_G25:a_1418(a_1001,2130705180); return;
a_G26:if(!a_equal(16777455,a_1457)){ goto a_G25;}
a_L1=a_1458;
a_1464();
a_P[0]=16777403;a_P[1]=a_L1;a_1074(2,a_P); return;
a_G30:a_1096(); return;
} /* storeaffix */
static void a_1098(int a_A[1]){ /* storeruleaffix+a> */
int a_L2;int a_P[2];
if(!a_equal(16777409,a_1457)){ goto a_G6;}
a_1464();
a_A[0]=16777409;
a_P[0]=16777409;a_1074(1,a_P);
a_G5:a_1095(); return;
a_G6:if(!a_equal(16777424,a_1457)){ goto a_G10;}
a_1464();
a_A[0]=16777424;
a_P[0]=16777424;a_1074(1,a_P); return;
a_G10:if(!a_equal(16777397,a_1457)){ goto a_G18;}
a_1464();
a_A[0]=16777397;
if(!a_equal(16777455,a_1457)){ goto a_G16;}
a_L2=a_1458;
a_1464(); goto a_G17;
a_G16:a_L2=0;
a_G17:a_P[0]=16777397;a_P[1]=a_L2;a_1074(2,a_P); return;
a_G18:a_A[0]=0; goto a_G5;
} /* storeruleaffix */
static void a_1099(void){ /* storeruleaffixes */
int a_P[2];
a_G1:{ if(a_1457==16777479){ goto a_G2;}
 if(a_1457==16777471){ goto a_G5;}
 if(a_1457==16777475||a_1457==16777459||a_1457==16777455){ goto a_G3;}
 if(a_1457==16777448){ goto a_G6;}
 if(a_1457==16777269||a_1457==16777291||a_1457==16777295||a_1457==16777299||a_1457==16777231||a_1457==16777424||a_1457==16777403||a_1457==16777397||a_1457==16777409){ goto a_G6;}
  goto a_G7;}
a_G2:a_1068(a_1458);
a_G3:a_P[0]=a_1457;a_P[1]=a_1458;a_1074(2,a_P);
a_G4:a_1464(); goto a_G1;
a_G5:a_P[0]=a_1458;a_1059(a_P);a_1458=a_P[0]; goto a_G3;
a_G6:a_P[0]=a_1457;a_1074(1,a_P); goto a_G4;
a_G7:if(!a_equal(16777433,a_1457)){ goto a_G10;}
to_LIST(a_1032)->offset[a_1100-1]=a_1458;
a_1464(); goto a_G11;
a_G10:a_1418(a_1001,2130705180); return;
a_G11:if(!a_equal(16777433,a_1457)){ goto a_G10;}
to_LIST(a_1032)->offset[a_1100]=a_1458;
a_1464();
if(!a_equal(16777412,a_1457)){ goto a_G10;}

a_1464(); return;
} /* storeruleaffixes */
static void a_1044(void){ /* computeruleaffixhash */
int a_L1;int a_P[1];
a_L1=to_LIST(a_1443)->aupb;
a_1099();
a_blockhash(a_1443,a_L1,a_P);to_LIST(a_1032)->offset[a_1100-5]=a_P[0];
a_unstackto(a_1443,a_L1); return;
} /* computeruleaffixhash */
static int a_1072(int a_F1){ /* nodewithsamehash+>a */
int a_L2;int a_L3;int a_L4;int a_L5;
a_booland(to_LIST(a_1032)->offset[a_F1-4],8,a_L5);
if(a_noteq(a_L5,0)){ return 0;}
a_L2=to_LIST(a_1032)->offset[a_F1-5];
a_L3=to_LIST(a_1032)->offset[a_F1-3];
a_L4=to_LIST(a_1032)->alwb;
a_G6:if(a_more(a_L4,to_LIST(a_1032)->aupb)){ return 0;}
a_booland(to_LIST(a_1032)->offset[a_L4-4],8,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G10;}
a_G9:a_next(a_1032,a_L4); goto a_G6;
a_G10:if(!a_noteq(a_L4,a_F1)){ goto a_G9;}
a_booland(to_LIST(a_1032)->offset[a_L4-4],1,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G9;}
if(!a_equal(to_LIST(a_1032)->offset[a_L4-5],a_L2)){ goto a_G9;}
if(a_equal(to_LIST(a_1032)->offset[a_L4-3],a_L3)){ return 1;} goto a_G9;
} /* nodewithsamehash */
static int a_1071(void){ /* nodehashdifferent */
int a_L1;int a_L2;
a_L1=to_LIST(a_1032)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1032)->aupb)){ return 1;}
a_booland(to_LIST(a_1032)->offset[a_L1-4],1,a_L2);
if(!a_noteq(a_L2,0)){ goto a_G6;}
if(a_1072(a_L1)){ return 0;}
a_G6:a_next(a_1032,a_L1); goto a_G2;
} /* nodehashdifferent */
static int a_1047(int a_F1,int a_F2){ /* equalaffixes+>a+>a */

a_G1:if(!a_equal(to_LIST(a_1443)->offset[a_F1],to_LIST(a_1443)->offset[a_F2])){ return 0;}
if(a_equal(to_LIST(a_1443)->offset[a_F1],16777412)){ return 1;}
a_decr(a_F1);
a_decr(a_F2); goto a_G1;
} /* equalaffixes */
static void a_1042(int a_F1){ /* comparetostoredaffixes+>a */
int a_L2;int a_L3;int a_L4;int a_L5;
a_L3=to_LIST(a_1032)->offset[a_1100-5];
a_L4=1;
a_L2=to_LIST(a_1032)->alwb;
a_G4:if(a_mreq(a_L2,a_1100)){ goto a_G13;}
a_booland(to_LIST(a_1032)->offset[a_L2-4],4096,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G12;}
if(!a_equal(to_LIST(a_1032)->offset[a_L2-5],a_L3)){ goto a_G12;}
if(!a_1047(to_LIST(a_1032)->offset[a_1100-2],to_LIST(a_1032)->offset[a_L2-2])){ goto a_G12;}
a_L4=0;
to_LIST(a_1032)->offset[a_1100-2]=a_L2;
a_1086(8192); goto a_G13;
a_G12:a_next(a_1032,a_L2); goto a_G4;
a_G13:if(a_equal(a_L4,0)){ goto a_G21;}
a_L4=0;
a_G15:a_next(a_1032,a_L2);
if(a_more(a_L2,to_LIST(a_1032)->aupb)){ goto a_G21;}
a_booland(to_LIST(a_1032)->offset[a_L2-4],1,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G15;}
if(!a_equal(to_LIST(a_1032)->offset[a_L2-5],a_L3)){ goto a_G15;}
a_L4=1;
a_G21:if(!a_equal(a_L4,0)){ goto a_G23;}
a_unstackto(a_1443,a_F1); return;
a_G23:a_1086(4096); return;
} /* comparetostoredaffixes */
static void a_1039(void){ /* checknodehash */
int a_L1;int a_P[1];
if(!a_1072(a_1100)){ goto a_G7;}
a_L1=to_LIST(a_1443)->aupb;
a_P[0]=16777412;a_1074(1,a_P);
a_1099();
to_LIST(a_1032)->offset[a_1100-2]=to_LIST(a_1443)->aupb;
a_1042(a_L1); return;
a_G7:a_1092(); return;
} /* checknodehash */
static int a_1081(int a_F1,int a_F2){ /* samenodes+>a+>a */
int a_L3;
a_booland(to_LIST(a_1032)->offset[a_F1-4],1,a_L3);
if(!a_noteq(a_L3,0)){ return 0;}
a_booland(to_LIST(a_1032)->offset[a_F2-4],1,a_L3);
if(!a_noteq(a_L3,0)){ return 0;}
if(!a_equal(to_LIST(a_1032)->offset[a_F1-3],to_LIST(a_1032)->offset[a_F2-3])){ return 0;}
if(!a_equal(to_LIST(a_1032)->offset[a_F1-5],to_LIST(a_1032)->offset[a_F2-5])){ return 0;}
if(!a_equal(to_LIST(a_1032)->offset[a_F1-1],to_LIST(a_1032)->offset[a_F2-1])){ return 0;}
if(!a_equal(to_LIST(a_1032)->offset[a_F1],to_LIST(a_1032)->offset[a_F2])){ return 0;}
a_G9:a_booland(to_LIST(a_1032)->offset[a_F1-4],8192,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G12;}
a_F1=to_LIST(a_1032)->offset[a_F1-2]; goto a_G9;
a_G12:a_booland(to_LIST(a_1032)->offset[a_F2-4],8192,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G15;}
a_F2=to_LIST(a_1032)->offset[a_F2-2]; goto a_G12;
a_G15:if(!a_equal(a_F1,a_F2)){ return 0;} return 1;
} /* samenodes */
static int a_1061(int a_F1){ /* hasoutaffix+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1315(a_F1,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_mreq(a_L3,a_L2)){ return 0;}
a_1311(a_F1,a_L3,a_P);a_L4=a_P[0];
if(a_equal(a_L4,16777376)){ return 1;}
if(a_equal(a_L4,16777382)){ return 1;}
if(a_equal(a_L4,16777388)){ return 1;}
a_incr(a_L3); goto a_G3;
} /* hasoutaffix */
static int a_1064(int a_F1){ /* isnodediscarded+>a */
int a_L2;int a_L3;int a_P[1];
a_booland(to_LIST(a_1032)->offset[a_F1-4],1,a_L2);
if(!a_noteq(a_L2,0)){ return 0;}
a_1052(to_LIST(a_1032)->offset[a_F1-1],a_P);a_L2=a_P[0];
a_1052(to_LIST(a_1032)->offset[a_F1],a_P);a_L3=a_P[0];
if(!a_equal(a_L2,a_L3)){ return 0;}
a_F1=to_LIST(a_1032)->offset[a_F1-3];
if(a_1323(a_F1,256)){ return 0;}
if(a_1323(a_F1,1024)){ return 0;}
if(a_1323(a_F1,32768)){ return 0;}
if(!a_1061(a_F1)){ return 1;} return 0;
} /* isnodediscarded */
static void a_1077(int a_F1,int a_F2){ /* replacelabels+>a+>a */
int a_L3;
a_L3=to_LIST(a_1032)->alwb;
a_G2:if(a_more(a_L3,to_LIST(a_1032)->aupb)){ return;}
if(!a_equal(to_LIST(a_1032)->offset[a_L3-1],a_F1)){ goto a_G5;}
to_LIST(a_1032)->offset[a_L3-1]=a_F2;
a_G5:if(!a_equal(to_LIST(a_1032)->offset[a_L3],a_F1)){ goto a_G7;}
to_LIST(a_1032)->offset[a_L3]=a_F2;
a_G7:a_next(a_1032,a_L3); goto a_G2;
} /* replacelabels */
static void a_1078(int a_F1,int a_F2){ /* replacenlabels+>a+>a */
int a_P[1];
to_LIST(a_1032)->offset[a_F2-2]=a_F1;
a_1075(a_F2,16384);
a_1060(a_F1,a_P);a_F1=a_P[0];
a_1060(a_F2,a_P);a_F2=a_P[0];
a_1077(a_F2,a_F1); return;
} /* replacenlabels */
static void a_1049(void){ /* findequalnodes */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
a_G1:a_L1=0;
a_L2=to_LIST(a_1032)->alwb;
a_G3:if(a_more(a_L2,to_LIST(a_1032)->aupb)){ goto a_G24;}
a_booland(to_LIST(a_1032)->offset[a_L2-4],16384,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G7;}
a_G6:a_next(a_1032,a_L2); goto a_G3;
a_G7:a_booland(to_LIST(a_1032)->offset[a_L2-4],8,a_L4);
if(a_noteq(a_L4,0)){ goto a_G6;}
if(!a_1064(a_L2)){ goto a_G14;}
a_1075(a_L2,8);
a_1060(a_L2,a_P);a_L3=a_P[0];
a_1077(a_L3,to_LIST(a_1032)->offset[a_L2]);
a_L1=1; goto a_G6;
a_G14:a_L3=a_L2;
a_G15:a_next(a_1032,a_L3);
if(a_more(a_L3,to_LIST(a_1032)->aupb)){ goto a_G6;}
a_booland(to_LIST(a_1032)->offset[a_L3-4],16384,a_L4);
if(a_noteq(a_L4,0)){ goto a_G15;}
a_booland(to_LIST(a_1032)->offset[a_L3-4],8,a_L4);
if(a_noteq(a_L4,0)){ goto a_G15;}
if(!a_1081(a_L2,a_L3)){ goto a_G15;}
a_L1=1;
a_1078(a_L2,a_L3); goto a_G15;
a_G24:if(a_equal(a_L1,0)){ return;}
if(a_is(a_1066)){ return;} goto a_G1;
} /* findequalnodes */
static void a_1073(void){ /* omitemptynodes */
int a_L1;int a_L2;int a_L3;int a_P[1];
a_L1=to_LIST(a_1032)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1032)->aupb)){ return;}
a_booland(to_LIST(a_1032)->offset[a_L1-4],8,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G9;}
a_1060(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,to_LIST(a_1032)->offset[a_L1])){ goto a_G8;}
a_1066=to_LIST(a_1032)->offset[a_L1-3]; goto a_G9;
a_G8:a_1077(a_L2,to_LIST(a_1032)->offset[a_L1]);
a_G9:a_next(a_1032,a_L1); goto a_G2;
} /* omitemptynodes */
static void a_1052(int a_F1,int a_A[1]){ /* findreallabel+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[1];
if(!a_lseq(a_F1,0)){ goto a_G3;}
a_G2:a_A[0]=a_F1; return;
a_G3:if(a_is(a_1066)){ goto a_G2;}
a_1062(a_F1,a_P);a_F1=a_P[0];
a_listlength(a_1032,a_L4);
a_L3=0;
a_G7:a_booland(to_LIST(a_1032)->offset[a_F1-4],16384,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G10;}
a_F1=to_LIST(a_1032)->offset[a_F1-2]; goto a_G7;
a_G10:if(!a_more(a_L3,a_L4)){ goto a_G13;}
a_1040(a_F1,8);
a_1066=to_LIST(a_1032)->offset[a_F1-3]; goto a_G17;
a_G13:a_booland(to_LIST(a_1032)->offset[a_F1-4],8,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G17;}
a_1062(to_LIST(a_1032)->offset[a_F1],a_P);a_F1=a_P[0];
a_incr(a_L3); goto a_G7;
a_G17:a_1060(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* findreallabel */
static void a_1051(int a_A[1]){ /* findnextnode+a> */
int a_L2;int a_L3;int a_P[1];
a_A[0]=0;
a_L2=a_1100;
a_G3:a_next(a_1032,a_L2);
if(a_more(a_L2,to_LIST(a_1032)->aupb)){ return;}
a_booland(to_LIST(a_1032)->offset[a_L2-4],16384,a_L3);
if(a_noteq(a_L3,0)){ goto a_G3;}
a_booland(to_LIST(a_1032)->offset[a_L2-4],8,a_L3);
if(a_noteq(a_L3,0)){ goto a_G3;}
a_1060(a_L2,a_P);a_A[0]=a_P[0]; return;
} /* findnextnode */
static void a_1069(int a_F1,int a_F2){ /* marknode+>a+>a */
int a_P[1];
a_1052(a_F2,a_P);a_F2=a_P[0];
if(a_lseq(a_F2,0)){ return;}
if(a_equal(a_F2,a_F1)){ return;}
a_1062(a_F2,a_P);a_F2=a_P[0];
a_1075(a_F2,16); return;
} /* marknode */
static void a_1079(void){ /* rulelabel */
int a_L1;int a_L2;int a_P[1];
a_booland(to_LIST(a_1032)->offset[a_1100-4],16384,a_L2);
if(a_noteq(a_L2,0)){ return;}
a_booland(to_LIST(a_1032)->offset[a_1100-4],8,a_L2);
if(a_noteq(a_L2,0)){ return;}
a_1051(a_P);a_L1=a_P[0];
a_1069(a_L1,to_LIST(a_1032)->offset[a_1100-1]);
a_1069(a_L1,to_LIST(a_1032)->offset[a_1100]); return;
} /* rulelabel */
static void a_1036(void){ /* arealabels */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
a_1051(a_P);a_L1=a_P[0];
a_L2=0;a_L3=0;
a_G3:if(!a_equal(16777220,a_1457)){ goto a_G8;}
a_1464();
a_1069(0,a_L2);
a_L2=a_L3;
a_1093(a_P);a_L3=a_P[0]; goto a_G3;
a_G8:a_booland(to_LIST(a_1032)->offset[a_1100-4],2048,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G12;}
a_1069(a_L1,a_L2);
a_G11:a_1069(a_L1,a_L3); return;
a_G12:a_1069(0,a_L2); goto a_G11;
} /* arealabels */
static void a_1048(void){ /* extensionlabel */
int a_L1;int a_L2;int a_P[1];
a_1051(a_P);a_L1=a_P[0];
a_1093(a_P);a_L2=a_P[0];
a_1069(a_L1,a_L2); return;
} /* extensionlabel */
static void a_1057(void){ /* generatelabel */
int a_L1;int a_L2;int a_L3;int a_P[1];
a_1035();
a_booland(to_LIST(a_1032)->offset[a_1100-4],16384,a_L3);
if(a_noteq(a_L3,0)){ return;}
a_booland(to_LIST(a_1032)->offset[a_1100-4],8,a_L3);
if(a_noteq(a_L3,0)){ return;}
a_1051(a_P);a_L2=a_P[0];
a_booland(to_LIST(a_1032)->offset[a_1100-4],16,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G10;}
a_1060(a_1100,a_P);a_L1=a_P[0]; goto a_G11;
a_G10:a_L1=0;
a_G11:a_1111(a_L1,a_L2); return;
} /* generatelabel */
static void a_1058(void){ /* generaterulecall */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_P[1];
if(!a_equal(16777471,a_1457)){ goto a_G4;}

a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130705180); return;
a_G5:if(!a_equal(16777455,a_1457)){ goto a_G4;}

a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G4;}

a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G4;}

a_1464();
a_L7=to_LIST(a_1443)->aupb;
a_L2=0;a_L5=0;a_L6=0;
a_G16:if(!a_equal(16777433,a_1457)){ goto a_G21;}
a_1464();
if(!a_equal(16777433,a_1457)){ goto a_G4;}

a_1464(); goto a_G30;
a_G21:a_1098(a_P);a_L1=a_P[0];
a_P[0]=16777436;a_1074(1,a_P);
a_incr(a_L2);
if(!a_is(a_L5)){ goto a_G26;}
a_incr(a_L5);
a_G26:if(!a_equal(a_L1,16777397)){ goto a_G16;}
if(!a_is(a_L5)){ goto a_G29;}
a_L6=1; goto a_G16;
a_G29:a_L5=1; goto a_G16;
a_G30:a_1052(to_LIST(a_1032)->offset[a_1100-1],a_P);a_L3=a_P[0];
a_1052(to_LIST(a_1032)->offset[a_1100],a_P);a_L4=a_P[0];
a_1113(to_LIST(a_1032)->offset[a_1100-3],a_L2,a_L3,a_L4,a_L5,a_L6,a_L7);
a_unstackto(a_1443,a_L7); return;
} /* generaterulecall */
static void a_1056(void){ /* generateextension */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[2];
a_L1=to_LIST(a_1443)->aupb;
a_1097(0);
if(!a_equal(16777455,a_1457)){ goto a_G6;}
a_L2=a_1458;
a_1464(); goto a_G7;
a_G6:a_1418(a_1001,2130705180); return;
a_G7:a_add(a_L1,1,a_L3);
to_LIST(a_1443)->offset[a_L3]=a_L2;
a_P[0]=0;a_1074(1,a_P);
a_L3=to_LIST(a_1443)->aupb;
a_G11:a_1095();
a_P[0]=16777436;a_1074(1,a_P);
a_G13:if(!a_equal(16777288,a_1457)){ goto a_G19;}
a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G6;}
a_L2=a_1458;
a_1464();
a_P[0]=a_L2;a_1074(1,a_P); goto a_G13;
a_G19:if(!a_equal(16777433,a_1457)){ goto a_G25;}
a_L4=a_1458;
a_1464();
a_1052(a_L4,a_P);a_L4=a_P[0];
a_P[0]=-1;a_1074(1,a_P);
a_1107(a_L1,a_L4); goto a_G27;
a_G25:a_P[0]=-1;a_P[1]=0;a_1074(2,a_P);
{register int a_r1=to_LIST(a_1443)->aupb;to_LIST(a_1443)->offset[a_L3]=a_r1;a_L3=a_r1;} goto a_G11;
a_G27:a_unstackto(a_1443,a_L1); return;
} /* generateextension */
static void a_1053(void){ /* generatearea */
int a_L1;int a_L2;int a_P[2];
a_G1:a_1076(a_P);a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=a_L1;a_P[1]=a_L2;a_1074(2,a_P);
if(!a_equal(16777442,a_1457)){ return;}
a_1464();
a_P[0]=16777442;a_1074(1,a_P); goto a_G1;
} /* generatearea */
static void a_1054(void){ /* generateareas */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
a_L1=0;
if(!a_equal(16777220,a_1457)){ goto a_G5;}

a_1464(); goto a_G6;
a_G5:a_1418(a_1001,2130705180); return;
a_G6:if(!a_equal(16777455,a_1457)){ goto a_G5;}

a_1464();
a_P[0]=0;a_1074(1,a_P);
if(a_equal(a_L1,0)){ goto a_G12;}
to_LIST(a_1443)->offset[a_L1]=to_LIST(a_1443)->aupb;
a_G12:a_L1=to_LIST(a_1443)->aupb;
a_P[0]=0;a_1074(1,a_P);
a_L2=to_LIST(a_1443)->aupb;
a_1053();
if(!a_equal(16777433,a_1457)){ goto a_G5;}
a_L3=a_1458;
a_1464();
a_1052(a_L3,a_P);to_LIST(a_1443)->offset[a_L2]=a_P[0];
if(!a_equal(16777220,a_1457)){ goto a_G23;}
a_1464();
a_P[0]=16777436;a_1074(1,a_P); goto a_G6;
a_G23:a_booland(to_LIST(a_1032)->offset[a_1100-4],2048,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G27;}
a_unstackto(a_1443,a_L2);
a_P[0]=a_1026;a_P[1]=a_1025;a_P[2]=16777436;a_1074(3,a_P); return;
a_G27:a_P[0]=16777436;a_1074(1,a_P); return;
} /* generateareas */
static void a_1055(void){ /* generatebox */
int a_L1;int a_L2;int a_P[1];
a_L1=to_LIST(a_1443)->aupb;
a_1095();
a_P[0]=16777436;a_1074(1,a_P);
a_L2=to_LIST(a_1443)->aupb;
a_1054();
a_1106(a_L1,a_L2);
a_unstackto(a_1443,a_L1); return;
} /* generatebox */
static void a_1082(void){ /* scani */

a_G1:if(!a_equal(16777227,a_1457)){ goto a_G11;}
a_1464();
a_1035();
a_1086(4);
a_1088();
a_1038();
if(!a_equal(16777412,a_1457)){ goto a_G10;}

a_1464(); goto a_G1;
a_G10:a_1418(a_1001,2130705180); return;
a_G11:if(!a_equal(16777241,a_1457)){ goto a_G16;}
a_1464();
a_1035();
a_1086(2);
a_1092(); goto a_G1;
a_G16:if(!a_equal(16777281,a_1457)){ goto a_G22;}
a_1464();
a_1035();
a_1086(1);
a_1087();
a_1044(); goto a_G1;
a_G22:if(!a_equal(16777439,a_1457)){ goto a_G10;}

a_1464(); return;
} /* scani */
static void a_1083(void){ /* scanii */
int a_L1;
a_L1=to_LIST(a_1443)->aupb;
a_G2:if(!a_equal(16777227,a_1457)){ goto a_G6;}
a_G3:a_1464();
a_1035();
a_1092(); goto a_G2;
a_G6:if(a_equal(16777241,a_1457)){ goto a_G3;}
if(!a_equal(16777281,a_1457)){ goto a_G12;}
a_1464();
a_1035();
a_1091();
a_1039(); goto a_G2;
a_G12:if(!a_equal(16777439,a_1457)){ goto a_G15;}

a_1464(); goto a_G16;
a_G15:a_1418(a_1001,2130705180); return;
a_G16:a_unstackto(a_1443,a_L1); return;
} /* scanii */
static void a_1084(void){ /* scaniii */

a_G1:if(!a_equal(16777227,a_1457)){ goto a_G10;}
a_1464();
a_1035();
a_1088();
a_1036();
a_G6:if(!a_equal(16777412,a_1457)){ goto a_G9;}

a_1464(); goto a_G1;
a_G9:a_1418(a_1001,2130705180); return;
a_G10:if(!a_equal(16777241,a_1457)){ goto a_G14;}
a_1464();
a_1035();
a_1048(); goto a_G6;
a_G14:if(!a_equal(16777281,a_1457)){ goto a_G19;}
a_1464();
a_1035();
a_1079();
a_1092(); goto a_G1;
a_G19:if(!a_equal(16777439,a_1457)){ goto a_G9;}

a_1464(); return;
} /* scaniii */
static void a_1085(void){ /* scaniv */
int a_L1;
a_G1:if(!a_equal(16777227,a_1457)){ goto a_G9;}
a_1464();
a_1057();
a_1055();
a_G5:if(!a_equal(16777412,a_1457)){ goto a_G8;}

a_1464(); goto a_G1;
a_G8:a_1418(a_1001,2130705180); return;
a_G9:if(!a_equal(16777241,a_1457)){ goto a_G13;}
a_1464();
a_1057();
a_1056(); goto a_G5;
a_G13:if(!a_equal(16777281,a_1457)){ goto a_G22;}
a_1464();
a_1057();
a_booland(to_LIST(a_1032)->offset[a_1100-4],16384,a_L1);
if(!a_noteq(a_L1,0)){ goto a_G19;}
a_G18:a_1092(); goto a_G1;
a_G19:a_booland(to_LIST(a_1032)->offset[a_1100-4],8,a_L1);
if(a_noteq(a_L1,0)){ goto a_G18;}
a_1058(); goto a_G5;
a_G22:if(!a_equal(16777439,a_1457)){ goto a_G8;}

a_1464(); return;
} /* scaniv */
static void a_1067(void){ /* makerule */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[4];
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130705180); return;
a_G5:if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L3=a_1458;
a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L4=a_1458;
a_1464();
if(!a_1323(a_L1,16384)){ goto a_G13;}
a_1090(); return;
a_G13:a_1045();
a_L2=to_LIST(a_1443)->aupb;
a_1041();
a_1094(a_L3,a_L4);
a_1474();
a_1100=0;
a_1082();
a_1046=0;
a_1066=0;
a_1073();
if(a_1071()){ goto a_G27;}
a_1473();
a_1100=0;
a_1083();
a_G27:a_1049();
a_1194(a_L1,a_1030,a_1031,a_L3,a_L4,a_1065);
a_unstackto(a_1443,a_L2);
a_1473();
a_1100=0;
a_1084();
if(!a_is(a_1066)){ goto a_G35;}
a_P[0]=2047260124;a_P[1]=to_LIST(a_1285)->offset[a_L1-3];a_P[2]=to_LIST(a_1285)->offset[a_L1-2];a_P[3]=to_LIST(a_1285)->offset[a_1066-3];a_1419(4,a_P); return;
a_G35:a_1473();
a_1100=0;
a_1085();
a_1195(); return;
} /* makerule */
static void a_1160(void){ /* opentarget */
int a_L1;int a_P[3];
a_1393();
if(!a_openfile(a_1103,119,a_1447,to_LIST(a_1447)->aupb)){ goto a_G5;}
a_unstackstring(a_1447);
a_1201=1; return;
a_G5:a_getfileerror(a_1103,a_L1);
a_P[0]=2047260138;a_P[1]=to_LIST(a_1447)->aupb;a_P[2]=a_L1;a_1419(3,a_P); return;
} /* opentarget */
static void a_1126(void){ /* closetarget */

if(a_equal(a_1201,0)){ return;}
a_closefile(a_1103);
a_1201=0; return;
} /* closetarget */
static void a_1134(void){ /* deletetarget */

if(a_equal(a_1201,0)){ return;}
a_1126();
a_1393();
a_unlinkfile(a_1447,to_LIST(a_1447)->aupb);
a_unstackstring(a_1447); return;
} /* deletetarget */
static void a_1170(int a_F1){ /* printint+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G8;}
a_putchar(a_1103,40);
a_putchar(a_1103,45);
a_1170(2147483647);
a_putchar(a_1103,45);
a_putchar(a_1103,49);
a_putchar(a_1103,41); return;
a_G8:if(!a_less(a_F1,0)){ goto a_G11;}
a_putchar(a_1103,45);
a_getabs(a_F1,a_F1);
a_G11:a_1171(a_F1,48); return;
} /* printint */
static void a_1171(int a_F1,int a_F2){ /* printint1+>a+>a */
int a_L3;int a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1171(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_putchar(a_1103,a_L4); return;
} /* printint1 */
static void a_1173(void){ /* printlabelprefix */

a_putchar(a_1103,97);
a_putchar(a_1103,95);
a_putchar(a_1103,71); return;
} /* printlabelprefix */
static void a_1155(int a_F1){ /* localargument+>a */

a_putchar(a_1103,97);
a_putchar(a_1103,95);
a_putchar(a_1103,76);
a_1170(a_F1); return;
} /* localargument */
static void a_1172(int a_F1,int a_F2){ /* printintindex+>a+>a */

a_putchar(a_1103,97);
a_putchar(a_1103,95);
a_putchar(a_1103,a_F1);
a_putchar(a_1103,91);
a_1170(a_F2);
a_putchar(a_1103,93); return;
} /* printintindex */
static void a_1142(int a_F1){ /* formalargument+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_L2=0;a_L4=0;
a_G2:a_1311(a_1204,a_L2,a_P);a_L3=a_P[0];
a_incr(a_L2);
if(a_equal(a_L3,16777376)){ goto a_G6;}
if(!a_equal(a_L3,16777382)){ goto a_G9;}
a_G6:if(!a_equal(a_L2,a_F1)){ goto a_G8;}
a_1172(65,a_L4); return;
a_G8:a_incr(a_L4); goto a_G2;
a_G9:if(!a_equal(a_L3,16777388)){ goto a_G17;}
a_incr(a_L2);
a_subtr(a_F1,a_L2,a_L2);
if(!a_less(a_L2,0)){ goto a_G16;}
a_putchar(a_1103,97);
a_putchar(a_1103,95);
a_putchar(a_1103,67); return;
a_G16:a_1172(86,a_L2); return;
a_G17:if(!a_equal(a_L2,a_F1)){ goto a_G2;}
a_putchar(a_1103,97);
a_putchar(a_1103,95);
a_putchar(a_1103,70);
a_1170(a_F1); return;
} /* formalargument */
static void a_1177(int a_F1){ /* printpidginrepr+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1456(to_LIST(a_1285)->offset[a_F1],a_P);a_L2=a_P[0];
a_L4=1;
a_G3:if(!a_stringelem(a_1447,a_L2,a_L4,a_P)){ return;}a_L3=a_P[0];
a_putchar(a_1103,a_L3);
a_incr(a_L4); goto a_G3;
} /* printpidginrepr */
static void a_1168(int a_F1){ /* printexternalrepr+>a */

{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(a_r1==16777304||a_r1==16777309){ goto a_G2;}
 if(a_r1==16777349){ goto a_G3;}
  goto a_G5;}
a_G2:a_1178(to_LIST(a_1285)->offset[a_F1]); return;
a_G3:if(!a_1323(a_F1,12288)){ goto a_G2;}
a_1177(a_F1); return;
a_G5:a_putchar(a_1103,97);
a_putchar(a_1103,95);
a_1170(to_LIST(a_1285)->offset[a_F1]); return;
} /* printexternalrepr */
static void a_1179(int a_F1){ /* printrepr+>a */

if(!a_was(a_1285,a_F1)){ goto a_G9;}
if(!a_1323(a_F1,16)){ goto a_G4;}
a_1168(a_F1); return;
a_G4:{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(!(a_r1==16777304||a_r1==16777335)){ goto a_G6;}
}
a_1176(to_LIST(a_1285)->offset[a_F1]); return;
a_G6:a_putchar(a_1103,97);
a_putchar(a_1103,95);
a_1170(to_LIST(a_1285)->offset[a_F1]); return;
a_G9:a_1178(a_F1); return;
} /* printrepr */
static void a_1174(int a_F1){ /* printlocallabel+>a */

a_1173();
a_1170(a_F1); return;
} /* printlocallabel */
static void a_1169(int a_F1){ /* printgoto+>a */

{ if(a_F1==0||a_F1==-1){ goto a_G2;}
 if(a_F1==-2){ goto a_G5;}
  goto a_G6;}
a_G2:if(!a_1323(a_1204,512)){ goto a_G4;}
a_1486(a_1103,a_1001,2130706088); return;
a_G4:a_1486(a_1103,a_1001,2130706083); return;
a_G5:a_1486(a_1103,a_1001,2130706078); return;
a_G6:a_1486(a_1103,a_1001,2130706073);
a_1174(a_F1);
a_putchar(a_1103,59); return;
} /* printgoto */
static void a_1167(int a_F1){ /* printGOTO+>a */

if(!a_equal(a_F1,a_1158)){ goto a_G3;}
if(a_noteq(a_1158,0)){ return;}
a_G3:a_1169(a_F1); return;
} /* printGOTO */
static void a_1166(int a_F1){ /* printBUFFER+>a */

{register int a_r1=to_LIST(a_1443)->offset[a_F1];
 if(a_r1==16777471){ goto a_G2;}
 if(a_r1==16777455){ goto a_G4;}
 if(a_r1==16777479){ goto a_G6;}
 if(a_r1==16777459){ goto a_G8;}
 if(a_r1==16777475){ goto a_G10;}
  goto a_G12;}
a_G2:a_incr(a_F1);
a_1179(to_LIST(a_1443)->offset[a_F1]); return;
a_G4:a_incr(a_F1);
a_1170(to_LIST(a_1443)->offset[a_F1]); return;
a_G6:a_incr(a_F1);
a_1155(to_LIST(a_1443)->offset[a_F1]); return;
a_G8:a_incr(a_F1);
a_1176(to_LIST(a_1443)->offset[a_F1]); return;
a_G10:a_incr(a_F1);
a_1142(to_LIST(a_1443)->offset[a_F1]); return;
a_G12:a_1423(a_1001,2130706069); return;
} /* printBUFFER */
static void a_1178(int a_F1){ /* printptr+>a */
int a_P[1];
a_G1:if(!a_was(a_1285,a_F1)){ goto a_G3;}
a_F1=to_LIST(a_1285)->offset[a_F1-3]; goto a_G1;
a_G3:if(!a_was(a_1447,a_F1)){ goto a_G6;}
a_1456(a_F1,a_P);a_F1=a_P[0];
a_1486(a_1103,a_1447,a_F1); return;
a_G6:if(!a_was(a_1416,a_F1)){ goto a_G8;}
a_1486(a_1103,a_1416,a_F1); return;
a_G8:if(!a_was(a_1443,a_F1)){ goto a_G10;}
a_1166(a_F1); return;
a_G10:if(!a_equal(a_F1,0)){ goto a_G12;}
a_1486(a_1103,a_1001,2130706064); return;
a_G12:a_1423(a_1001,2130706060); return;
} /* printptr */
static void a_1175(int a_F1){ /* printnlptr+>a */
int a_L2;int a_L3;int a_P[1];
if(!a_was(a_1447,a_F1)){ goto a_G15;}
a_1456(a_F1,a_P);a_F1=a_P[0];
{register int a_r1=to_LIST(a_1443)->aupb;a_L2=a_r1;a_L3=a_r1;}
a_unpackstring(a_1447,a_F1,a_1443);
a_G5:if(!a_lseq(to_LIST(a_1443)->aupb,a_L3)){ goto a_G7;}
a_unstackto(a_1443,a_L2); return;
a_G7:a_incr(a_L3);
if(!a_noteq(to_LIST(a_1443)->offset[a_L3],37)){ goto a_G10;}
a_G9:a_putchar(a_1103,to_LIST(a_1443)->offset[a_L3]); goto a_G5;
a_G10:a_incr(a_L3);
if(a_less(to_LIST(a_1443)->aupb,a_L3)){ goto a_G5;}
if(!a_equal(to_LIST(a_1443)->offset[a_L3],110)){ goto a_G14;}
a_putchar(a_1103,10); goto a_G5;
a_G14:a_putchar(a_1103,37); goto a_G9;
a_G15:a_1178(a_F1); return;
} /* printnlptr */
static void a_1176(int a_F1){ /* printnumber+>a */
int a_L2;int a_L3;
{register int a_r1=to_LIST(a_1443)->aupb;a_L2=a_r1;a_L3=a_r1;}
a_1011(a_F1);
a_G3:if(!a_lseq(to_LIST(a_1443)->aupb,a_L3)){ goto a_G5;}
a_unstackto(a_1443,a_L2); return;
a_G5:a_incr(a_L3);
a_putchar(a_1103,to_LIST(a_1443)->offset[a_L3]); goto a_G3;
} /* printnumber */
static void a_1102(int a_F1,int a_C,int *a_V){ /* T+t[]+@+>a */
int a_L2;int a_L3;
a_L3=to_LIST(a_1443)->aupb;
a_unpackstring(a_F1,a_V[0],a_1443);
a_add(a_L3,1,a_L2);
a_G4:if(a_less(to_LIST(a_1443)->aupb,a_L2)){ goto a_G31;}
if(!a_noteq(to_LIST(a_1443)->offset[a_L2],37)){ goto a_G8;}
a_G6:a_putchar(a_1103,to_LIST(a_1443)->offset[a_L2]);
a_G7:a_incr(a_L2); goto a_G4;
a_G8:a_incr(a_L2);
if(!a_more(a_L2,to_LIST(a_1443)->aupb)){ goto a_G11;}
a_putchar(a_1103,37); goto a_G31;
a_G11:{register int a_r1=to_LIST(a_1443)->offset[a_L2];
 if(a_r1==114){ goto a_G12;}
 if(a_r1==103){ goto a_G15;}
 if(a_r1==71){ goto a_G17;}
 if(a_r1==119){ goto a_G19;}
 if(a_r1==110){ goto a_G20;}
 if(a_r1==84){ goto a_G21;}
 if(a_r1==100){ goto a_G23;}
 if(a_r1==112){ goto a_G25;}
 if(a_r1==115){ goto a_G27;}
 if(a_r1==116){ goto a_G29;}
  goto a_G6;}
a_G12:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1179(a_V[0]); goto a_G7;
a_G14:a_putchar(a_1103,63); goto a_G7;
a_G15:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1169(a_V[0]); goto a_G7;
a_G17:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1167(a_V[0]); goto a_G7;
a_G19:a_1486(a_1103,a_1001,2130706055); goto a_G7;
a_G20:a_putchar(a_1103,10); goto a_G7;
a_G21:if(a_equal(a_1124,0)){ goto a_G7;}
a_1486(a_1103,a_1001,2130706052); goto a_G7;
a_G23:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1170(a_V[0]); goto a_G7;
a_G25:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1178(a_V[0]); goto a_G7;
a_G27:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1175(a_V[0]); goto a_G7;
a_G29:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1176(a_V[0]); goto a_G7;
a_G31:if(a_C<=1){ goto a_G33;} a_C--;a_V+=1;
a_1486(a_1103,a_1001,2130706045);
a_G33:a_unstackto(a_1443,a_L3); return;
} /* T */
static void a_1115(int a_F1){ /* addcallstack+>a */
int a_P[2];
if(a_equal(a_1124,0)){ return;}
a_P[0]=2130706041;a_1102(a_1001,1,a_P);
if(!a_equal(a_F1,0)){ goto a_G5;}
a_P[0]=2130706034;a_1102(a_1001,1,a_P); return;
a_G5:if(!a_equal(a_F1,1)){ goto a_G7;}
a_P[0]=2130706029;a_1102(a_1001,1,a_P); return;
a_G7:a_P[0]=2130706023;a_P[1]=a_F1;a_1102(a_1001,2,a_P); return;
} /* addcallstack */
static void a_1208(void){ /* usecallstack */

a_1124=1; return;
} /* usecallstack */
static void a_1203(void){ /* targetprelude */
int a_L1;int a_L2;int a_P[4];
a_P[0]=2130706018;a_P[1]=2;a_P[2]=2;a_P[3]=32;a_1102(a_1001,4,a_P);
a_G2:a_1314(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ goto a_G8;}
if(!a_equal(to_LIST(a_1285)->offset[a_L1-3],0)){ goto a_G7;}
if(a_equal(to_LIST(a_1285)->offset[a_L1-4],0)){ goto a_G2;}
a_P[0]=2130705999;a_P[1]=to_LIST(a_1285)->offset[a_L1-4];a_1102(a_1001,2,a_P); goto a_G2;
a_G7:a_P[0]=2130705993;a_P[1]=a_L1;a_P[2]=to_LIST(a_1285)->offset[a_L1-4];a_1102(a_1001,3,a_P); goto a_G2;
a_G8:if(a_equal(a_1124,0)){ goto a_G10;}
a_P[0]=2130705987;a_1102(a_1001,1,a_P);
a_G10:a_P[0]=2130705976;a_P[1]=183666554;a_1102(a_1001,2,a_P);
a_L1=0;
a_G12:a_P[0]=a_L1;if(!a_1313(1,a_P)){ return;}a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=2130705976;a_P[1]=a_L2;a_1102(a_1001,2,a_P); goto a_G12;
} /* targetprelude */
static void a_1202(void){ /* targetpostlude */
int a_L1;int a_L2;int a_P[2];
a_L1=0;
a_G2:a_P[0]=a_L1;if(!a_1313(0,a_P)){ goto a_G4;}a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=2130705976;a_P[1]=a_L2;a_1102(a_1001,2,a_P); goto a_G2;
a_G4:a_P[0]=2130705972;a_1102(a_1001,1,a_P); return;
} /* targetpostlude */
static void a_1197(int a_F1){ /* ruletyper+>a */
int a_P[2];
if(!a_1323(a_F1,512)){ goto a_G3;}
a_P[0]=2130705967;a_P[1]=a_F1;a_1102(a_1001,2,a_P); return;
a_G3:a_P[0]=2130705961;a_P[1]=a_F1;a_1102(a_1001,2,a_P); return;
} /* ruletyper */
static void a_1119(int a_A[1]){ /* argsep+>a> */

if(!a_equal(a_A[0],0)){ goto a_G3;}
a_A[0]=1; return;
a_G3:a_putchar(a_1103,44); return;
} /* argsep */
static void a_1161(int a_F1,int a_A[1]){ /* outargs+>a+>a> */
int a_P[2];
if(a_equal(a_F1,0)){ return;}
a_P[0]=a_A[0];a_1119(a_P);a_A[0]=a_P[0];
a_P[0]=2130705955;a_P[1]=a_F1;a_1102(a_1001,2,a_P); return;
} /* outargs */
static void a_1193(int a_F1){ /* ruleargs+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
a_1315(a_F1,a_P);a_L3=a_P[0];
a_L4=0;a_L6=0;a_L2=0;
a_G3:if(!a_less(a_L4,a_L3)){ goto a_G15;}
a_1311(a_F1,a_L4,a_P);a_L5=a_P[0];
a_incr(a_L4);
if(a_equal(a_L5,16777376)){ goto a_G8;}
if(!a_equal(a_L5,16777382)){ goto a_G9;}
a_G8:a_incr(a_L6); goto a_G3;
a_G9:if(!a_equal(a_L5,16777388)){ goto a_G13;}
a_P[0]=a_L2;a_1161(a_L6,a_P);a_L2=a_P[0];
a_P[0]=a_L2;a_1119(a_P);
a_P[0]=2130705950;a_1102(a_1001,1,a_P); return;
a_G13:a_P[0]=a_L2;a_1119(a_P);a_L2=a_P[0];
a_P[0]=2130705944;a_P[1]=a_L4;a_1102(a_1001,2,a_P); goto a_G3;
a_G15:a_P[0]=a_L2;a_1161(a_L6,a_P);a_L2=a_P[0];
if(a_is(a_L2)){ goto a_G18;}
a_P[0]=2130705939;a_1102(a_1001,1,a_P);
a_G18:a_putchar(a_1103,41); return;
} /* ruleargs */
static void a_1209(int a_F1){ /* vardeclaration+>a */
int a_P[4];
if(a_1323(a_F1,16)){ return;}
a_P[0]=2130705935;a_P[1]=a_F1;a_P[2]=to_LIST(a_1285)->offset[a_F1-1];a_P[3]=a_F1;a_1102(a_1001,4,a_P); return;
} /* vardeclaration */
static void a_1121(int a_F1,int a_F2,int a_F3){ /* blockdeclaration+>a+>a+>a */
int a_P[3];
a_P[0]=2130705926;a_P[1]=a_F1;a_1102(a_1001,2,a_P);
if(!a_equal(a_F2,0)){ goto a_G4;}
a_P[0]=2130705920;a_1102(a_1001,1,a_P); goto a_G5;
a_G4:a_P[0]=2130705917;a_P[1]=a_F2;a_P[2]=a_F3;a_1102(a_1001,3,a_P);
a_G5:a_P[0]=2130705913;a_P[1]=a_F1;a_1102(a_1001,2,a_P); return;
} /* blockdeclaration */
static void a_1196(int a_F1){ /* ruleprototype+>a */
int a_P[2];
if(!a_1323(a_F1,12288)){ goto a_G4;}
if(!a_1325(a_F1)){ return;}
a_1210=1; return;
a_G4:if(a_1322(a_F1,a_P)){ return;}
if(a_1323(a_F1,16384)){ return;}
if(!a_1324(a_F1)){ goto a_G8;}
a_1288(2,a_F1); return;
a_G8:if(a_1323(a_F1,16)){ return;}
a_1197(a_F1);
a_1193(a_F1);
a_P[0]=2130705907;a_P[1]=a_F1;a_1102(a_1001,2,a_P); return;
} /* ruleprototype */
static void a_1192(int a_F1){ /* rootprototype+>a */
int a_P[2];
a_1197(a_F1);
a_1193(a_F1);
if(!a_equal(to_LIST(a_1285)->offset[a_F1-4],183666559)){ goto a_G5;}
a_P[0]=2130705901;a_1102(a_1001,1,a_P); return;
a_G5:a_incr(a_1156);
a_P[0]=2130705893;a_P[1]=to_LIST(a_1285)->offset[a_F1-4];a_1102(a_1001,2,a_P); return;
} /* rootprototype */
static void a_1129(void){ /* datadeclaration */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[4];
a_L1=to_LIST(a_1285)->alwb;
a_L2=0;a_L3=0;
a_G3:if(a_more(a_L1,to_LIST(a_1285)->aupb)){ goto a_G18;}
if(!a_1323(a_L1,8)){ goto a_G6;}
a_G5:a_next(a_1285,a_L1); goto a_G3;
a_G6:{register int a_r1=to_LIST(a_1285)->offset[a_L1-5];
 if(a_r1==16777309||a_r1==16777314){ goto a_G7;}
 if(a_r1==16777318||a_r1==16777322||a_r1==16777328){ goto a_G8;}
 if(a_r1==16777340){ goto a_G11;}
 if(a_r1==16777345){ goto a_G14;}
 if(a_r1==16777349){ goto a_G17;}
  goto a_G5;}
a_G7:a_1209(a_L1); goto a_G5;
a_G8:a_1121(a_L1,a_L2,a_L3);
a_L2=a_L1;
a_L3=2047260143; goto a_G5;
a_G11:a_1121(a_L1,a_L2,a_L3);
a_L2=a_L1;
a_L3=2047260149; goto a_G5;
a_G14:a_1121(a_L1,a_L2,a_L3);
a_L2=a_L1;
a_L3=2047260155; goto a_G5;
a_G17:a_1196(a_L1); goto a_G5;
a_G18:a_L4=0;
a_G19:a_P[0]=a_L4;if(!a_1313(2,a_P)){ goto a_G21;}a_L4=a_P[0];a_L1=a_P[1];
a_1192(a_L1); goto a_G19;
a_G21:if(!a_equal(a_L2,0)){ goto a_G23;}
a_P[0]=2130705886;a_P[1]=2047260160;a_1102(a_1001,2,a_P); goto a_G24;
a_G23:a_P[0]=2130705880;a_P[1]=2047260160;a_P[2]=a_L2;a_P[3]=a_L3;a_1102(a_1001,4,a_P);
a_G24:a_P[0]=2130705872;a_P[1]=2047260160;a_1102(a_1001,2,a_P); return;
} /* datadeclaration */
static void a_1182(int a_F1){ /* pushBUFFER+>a */

{register int *a_r1=a_extension(a_1443,1);a_r1[0]=a_F1;to_LIST(a_1443)->aupb+=1;}
  return;
} /* pushBUFFER */
static void a_1138(void){ /* filltablehead */
int a_P[1];
a_P[0]=2130705864;a_1102(a_1001,1,a_P);
a_1140=0; return;
} /* filltablehead */
static void a_1139(void){ /* filltabletail */
int a_P[2];
a_P[0]=2130705852;a_P[1]=a_1140;a_1102(a_1001,2,a_P); return;
} /* filltabletail */
static void a_1207(int a_A[1]){ /* untilnextcomma+>a> */

a_G1:if(!a_more(a_A[0],to_LIST(a_1443)->aupb)){ goto a_G3;}
a_1423(a_1001,2130705842); return;
a_G3:if(!a_equal(to_LIST(a_1443)->offset[a_A[0]],44)){ goto a_G6;}
a_putchar(a_1103,44);
a_incr(a_A[0]); return;
a_G6:a_putchar(a_1103,to_LIST(a_1443)->offset[a_A[0]]);
a_incr(a_A[0]); goto a_G1;
} /* untilnextcomma */
static void a_1127(void){ /* constitem */
int a_L1;
if(!a_equal(a_1457,16777459)){ goto a_G4;}
a_1011(a_1458);
a_1464(); return;
a_G4:if(!a_equal(16777471,a_1457)){ goto a_G7;}
a_L1=a_1458;
a_1464(); goto a_G8;
a_G7:a_1418(a_1001,2130705216); return;
a_G8:if(!a_1323(a_L1,8)){ goto a_G10;}
a_L1=to_LIST(a_1285)->offset[a_L1];
a_G10:a_1011(to_LIST(a_1285)->offset[a_L1]); return;
} /* constitem */
static void a_1136(int a_A[1]){ /* fillitem+a> */

if(!a_equal(16777427,a_1457)){ goto a_G9;}
a_1464();
a_A[0]=0;
a_G4:if(!a_equal(16777406,a_1457)){ goto a_G6;}
a_1464(); return;
a_G6:a_incr(a_A[0]);
a_1127();
a_1182(44); goto a_G4;
a_G9:a_A[0]=1;
a_1127();
a_1182(44); return;
} /* fillitem */
static int a_1137(int a_A[1]){ /* fillrepeater+a> */
int a_L2;int a_P[1];
if(!a_equal(16777445,a_1457)){ return 0;}
a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G6;}
a_A[0]=a_1458;
a_1464(); return 1;
a_G6:if(!a_equal(16777471,a_1457)){ goto a_G9;}
a_L2=a_1458;
a_1464(); goto a_G10;
a_G9:a_1418(a_1001,2130705216); return 1;
a_G10:if(!a_1323(a_L2,8)){ goto a_G12;}
a_L2=to_LIST(a_1285)->offset[a_L2];
a_G12:a_1014(to_LIST(a_1285)->offset[a_L2],a_P);a_A[0]=a_P[0]; return 1;
} /* fillrepeater */
static void a_1141(int a_F1,int a_F2,int a_F3){ /* flushbuffer+>a+>a+>a */
int a_P[2];
a_add(a_F1,a_1140,a_1140);
a_add(a_F2,a_1140,a_1140);
a_incr(a_F3);
if(a_equal(a_F1,0)){ goto a_G7;}
a_P[0]=2130705836;a_P[1]=a_F1;a_1102(a_1001,2,a_P);
a_incr(a_1140);
a_G7:if(a_equal(a_F1,0)){ goto a_G10;}
a_P[0]=a_F3;a_1207(a_P);a_F3=a_P[0];
a_decr(a_F1); goto a_G7;
a_G10:if(a_equal(a_F2,0)){ goto a_G13;}
a_P[0]=2130705836;a_P[1]=a_F2;a_1102(a_1001,2,a_P);
a_incr(a_1140);
a_G13:if(a_equal(a_F2,0)){ return;}
a_P[0]=a_F3;a_1207(a_P);a_F3=a_P[0];
a_decr(a_F2); goto a_G13;
} /* flushbuffer */
static void a_1199(void){ /* skipfillinitializer */

a_G1:if(!a_equal(16777409,a_1457)){ return;}
a_1464();
if(!a_equal(16777471,a_1457)){ goto a_G6;}

a_1464(); goto a_G1;
a_G6:a_1418(a_1001,2130705216); return;
} /* skipfillinitializer */
static void a_1144(void){ /* generatefillentries */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_P[3];
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130705216); return;
a_G5:if(!a_1323(a_L1,8)){ goto a_G7;}
a_L1=to_LIST(a_1285)->offset[a_L1];
a_G7:if(!a_equal(16777455,a_1457)){ goto a_G4;}

a_1464();
a_incr(a_1140);
a_P[0]=2130705833;a_P[1]=a_L1;a_P[2]=a_L1;a_1102(a_1001,3,a_P);
a_L2=to_LIST(a_1443)->aupb;
a_L3=0;
a_G14:if(!a_equal(16777439,a_1457)){ goto a_G16;}
a_1464(); goto a_G25;
a_G16:a_1136(a_P);a_L4=a_P[0];
if(!a_1137(a_P)){ goto a_G23;}a_L5=a_P[0];
a_1141(a_L3,a_L4,a_L2);
a_P[0]=2130705827;a_P[1]=a_L5;a_1102(a_1001,2,a_P);
a_incr(a_1140);
a_unstackto(a_1443,a_L2);
a_L3=0; goto a_G24;
a_G23:a_add(a_L3,a_L4,a_L3);
a_G24:a_1199(); goto a_G14;
a_G25:a_1141(a_L3,0,a_L2);
a_unstackto(a_1443,a_L2);
a_incr(a_1140);
a_P[0]=2130705823;a_1102(a_1001,1,a_P); return;
} /* generatefillentries */
static void a_1154(int a_F1,int a_F2){ /* listinitialization+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[9];
if(!a_1323(a_F2,16)){ goto a_G5;}
a_1307(a_F2,a_P);a_L3=a_P[0];
a_1317(a_F2,a_P);a_L4=a_P[0];
a_P[0]=2130705819;a_P[1]=a_L4;a_P[2]=a_F2;a_P[3]=a_F2;a_P[4]=a_L3;a_1102(a_1001,5,a_P); return;
a_G5:a_1307(a_F2,a_P);a_L3=a_P[0];
a_1318(a_F2,a_P);a_L5=a_P[0];
a_1317(a_F2,a_P);a_L4=a_P[0];
a_1310(a_F2,a_P);a_L6=a_P[0];
a_P[0]=2130705812;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_F2;a_P[4]=a_L3;a_P[5]=a_L4;a_P[6]=a_L5;a_P[7]=a_L6;a_P[8]=a_F2;a_1102(a_1001,9,a_P); return;
} /* listinitialization */
static void a_1125(int a_F1){ /* charfileinitialization+>a */
int a_L2;int a_L3;int a_L4;int a_P[7];
if(!a_1323(a_F1,16)){ goto a_G3;}
a_P[0]=2130705797;a_P[1]=to_LIST(a_1285)->offset[a_F1-1];a_P[2]=a_F1;a_P[3]=a_F1;a_1102(a_1001,4,a_P); return;
a_G3:if(!a_1323(a_F1,64)){ goto a_G5;}
a_L2=2; goto a_G6;
a_G5:a_L2=0;
a_G6:if(!a_1323(a_F1,32)){ goto a_G8;}
a_incr(a_L2);
a_G8:a_1309(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
if(!a_1323(a_L3,8)){ goto a_G11;}
a_L3=to_LIST(a_1285)->offset[a_L3];
a_G11:a_P[0]=2130705791;a_P[1]=a_F1;a_P[2]=a_F1;a_P[3]=a_L2;a_P[4]=a_L3;a_P[5]=a_L4;a_P[6]=a_F1;a_1102(a_1001,7,a_P); return;
} /* charfileinitialization */
static void a_1128(int a_F1,int a_A[1]){ /* countfilearea+>a+a> */
int a_L3;int a_P[1];
a_A[0]=1;
a_G2:a_1308(a_F1,a_A[0],a_P);a_L3=a_P[0];
if(!a_equal(a_L3,0)){ goto a_G5;}
a_decr(a_A[0]); return;
a_G5:a_incr(a_A[0]); goto a_G2;
} /* countfilearea */
static void a_1130(int a_F1){ /* datafileinitialization+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[8];
if(!a_1323(a_F1,16)){ goto a_G3;}
a_P[0]=2130705797;a_P[1]=to_LIST(a_1285)->offset[a_F1-1];a_P[2]=a_F1;a_P[3]=a_F1;a_1102(a_1001,4,a_P); return;
a_G3:if(!a_1323(a_F1,64)){ goto a_G5;}
a_L2=2; goto a_G6;
a_G5:a_L2=0;
a_G6:if(!a_1323(a_F1,32)){ goto a_G8;}
a_incr(a_L2);
a_G8:a_1309(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1128(a_F1,a_P);a_L6=a_P[0];
if(!a_1323(a_L3,8)){ goto a_G12;}
a_L3=to_LIST(a_1285)->offset[a_L3];
a_G12:a_P[0]=2130705777;a_P[1]=a_F1;a_P[2]=a_F1;a_P[3]=a_L2;a_P[4]=a_L3;a_P[5]=a_L4;a_P[6]=a_L6;a_P[7]=a_F1;a_1102(a_1001,8,a_P);
a_L6=1;
a_G14:a_1308(a_F1,a_L6,a_P);a_L5=a_P[0];
if(a_equal(a_L5,0)){ return;}
if(!a_1323(a_L5,8)){ goto a_G18;}
a_L5=to_LIST(a_1285)->offset[a_L5];
a_G18:a_P[0]=2130705763;a_P[1]=a_F1;a_P[2]=a_L5;a_P[3]=a_L6;a_P[4]=a_L5;a_1102(a_1001,5,a_P);
a_incr(a_L6); goto a_G14;
} /* datafileinitialization */
static void a_1131(void){ /* datainitialization */
int a_L1;int a_P[3];
a_P[0]=2130705751;a_1102(a_1001,1,a_P);
a_P[0]=2130705740;a_P[1]=183666537;a_P[2]=183666544;a_1102(a_1001,3,a_P);
a_L1=to_LIST(a_1285)->alwb;
a_G4:if(a_more(a_L1,to_LIST(a_1285)->aupb)){ goto a_G10;}
if(!a_1323(a_L1,8)){ goto a_G7;}
a_G6:a_next(a_1285,a_L1); goto a_G4;
a_G7:{register int a_r1=to_LIST(a_1285)->offset[a_L1-5];
 if(a_r1==16777318){ goto a_G8;}
 if(a_r1==16777322||a_r1==16777328){ goto a_G9;}
  goto a_G6;}
a_G8:a_1154(0,a_L1); goto a_G6;
a_G9:a_1154(1,a_L1); goto a_G6;
a_G10:a_L1=to_LIST(a_1285)->alwb;
a_G11:if(a_more(a_L1,to_LIST(a_1285)->aupb)){ goto a_G17;}
if(!a_1323(a_L1,8)){ goto a_G14;}
a_G13:a_next(a_1285,a_L1); goto a_G11;
a_G14:{register int a_r1=to_LIST(a_1285)->offset[a_L1-5];
 if(a_r1==16777340){ goto a_G15;}
 if(a_r1==16777345){ goto a_G16;}
  goto a_G13;}
a_G15:a_1125(a_L1); goto a_G13;
a_G16:a_1130(a_L1); goto a_G13;
a_G17:a_P[0]=2130705728;a_1102(a_1001,1,a_P); return;
} /* datainitialization */
static void a_1180(void){ /* procwaitfor */
int a_L1;int a_L2;int a_P[3];
a_P[0]=2130705719;a_1102(a_1001,1,a_P);
a_1115(1);
a_L1=0;
a_G4:a_P[0]=a_L1;if(!a_1313(2,a_P)){ goto a_G7;}a_L1=a_P[0];a_L2=a_P[1];
if(a_equal(to_LIST(a_1285)->offset[a_L2-4],183666559)){ goto a_G4;}
a_P[0]=2130705706;a_P[1]=a_L2;a_P[2]=to_LIST(a_1285)->offset[a_L2-4];a_1102(a_1001,3,a_P); goto a_G4;
a_G7:a_P[0]=2130705698;a_1102(a_1001,1,a_P); return;
} /* procwaitfor */
static void a_1200(void){ /* targetmain */
int a_L1;int a_L2;int a_L3;int a_P[2];
if(a_equal(a_1210,0)){ goto a_G4;}
if(a_more(a_1156,0)){ goto a_G4;}
a_P[0]=2047260175;a_1439(1,a_P);
a_G4:if(a_equal(a_1210,0)){ goto a_G6;}
a_1180();
a_G6:a_P[0]=2130705695;a_1102(a_1001,1,a_P);
a_1115(0);
a_P[0]=2130705687;a_1102(a_1001,1,a_P);
a_L1=0;a_L3=0;
a_G10:a_P[0]=a_L1;if(!a_1313(2,a_P)){ goto a_G15;}a_L1=a_P[0];a_L2=a_P[1];
if(!a_equal(to_LIST(a_1285)->offset[a_L2-4],183666559)){ goto a_G13;}
a_L3=a_L2; goto a_G10;
a_G13:if(a_is(a_1210)){ goto a_G10;}
a_P[0]=2130705680;a_P[1]=a_L2;a_1102(a_1001,2,a_P); goto a_G10;
a_G15:if(a_equal(a_1210,0)){ goto a_G17;}
a_P[0]=2130705675;a_1102(a_1001,1,a_P);
a_G17:if(!a_is(a_L3)){ goto a_G19;}
a_P[0]=2130705668;a_P[1]=a_L3;a_1102(a_1001,2,a_P); return;
a_G19:a_1418(a_1001,2130705663); return;
} /* targetmain */
static void a_1198(int a_F1){ /* showformalsascomment+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1315(a_F1,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_mreq(a_L3,a_L2)){ return;}
a_1311(a_F1,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
{ if(a_L4==16777371){ goto a_G7;}
 if(a_L4==16777376){ goto a_G8;}
 if(a_L4==16777382){ goto a_G9;}
 if(a_L4==16777361){ goto a_G10;}
 if(a_L4==16777355){ goto a_G11;}
 if(a_L4==16777366){ goto a_G12;}
 if(!(a_L4==16777388)){a_area_failed("showformalsascomment",a_L4);}
 goto a_G13;}
a_G7:a_P[0]=2130705658;a_1102(a_1001,1,a_P); goto a_G3;
a_G8:a_P[0]=2130705655;a_1102(a_1001,1,a_P); goto a_G3;
a_G9:a_P[0]=2130705652;a_1102(a_1001,1,a_P); goto a_G3;
a_G10:a_P[0]=2130705648;a_1102(a_1001,1,a_P); goto a_G3;
a_G11:a_P[0]=2130705644;a_1102(a_1001,1,a_P); goto a_G3;
a_G12:a_P[0]=2130705640;a_1102(a_1001,1,a_P); goto a_G3;
a_G13:a_P[0]=2130705636;a_1102(a_1001,1,a_P); goto a_G3;
} /* showformalsascomment */
static void a_1133(int a_F1,int a_F2,int a_F3){ /* declarelocals+>a+>a+>a */
int a_P[2];
a_G1:if(a_equal(a_F1,0)){ return;}
if(a_more(a_F1,a_F2)){ return;}
if(!a_equal(to_LIST(a_1443)->offset[a_F3],0)){ goto a_G6;}
a_G4:a_incr(a_F1);
a_incr(a_F3); goto a_G1;
a_G6:a_P[0]=2130705633;a_P[1]=a_F1;a_1102(a_1001,2,a_P); goto a_G4;
} /* declarelocals */
static void a_1132(int a_F1,int a_F2,int a_F3){ /* declarecallargs+>a+>a+>a */
int a_L4;int a_P[3];
if(a_equal(a_F2,0)){ goto a_G3;}
a_P[0]=2130705628;a_P[1]=a_F2;a_1102(a_1001,2,a_P);
a_G3:if(a_equal(a_F3,0)){ goto a_G6;}
a_1306(a_F1,a_P);a_L4=a_P[0];
a_P[0]=2130705623;a_P[1]=a_F3;a_P[2]=a_L4;a_1102(a_1001,3,a_P);
a_G6:a_putchar(a_1103,10); return;
} /* declarecallargs */
static void a_1194(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6){ /* ruledeclarationhead+>a+>a+>a+>a+>a+>a */
int a_P[2];
a_1204=a_F1;
a_1117();
a_1197(a_F1);
a_1193(a_F1);
a_P[0]=2130705611;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_1102(a_1001,2,a_P);
a_1198(a_F1);
a_P[0]=2130705607;a_1102(a_1001,1,a_P);
a_add(a_F4,a_F6,a_F6);
a_1133(a_F4,a_F5,a_F6);
a_1132(a_F1,a_F2,a_F3);
a_1115(a_F1);
a_1116();
a_1118(); return;
} /* ruledeclarationhead */
static void a_1195(void){ /* ruledeclarationtail */
int a_P[2];
a_P[0]=2130705603;a_P[1]=a_1204;a_1102(a_1001,2,a_P); return;
} /* ruledeclarationtail */
static void a_1117(void){ /* addprofilingdef */
int a_P[3];
if(!a_1323(a_1204,33554432)){ return;}
a_P[0]=2130705597;a_P[1]=to_LIST(a_1285)->offset[a_1204];a_P[2]=a_1204;a_1102(a_1001,3,a_P);
if(!a_equal(a_1153,0)){ goto a_G5;}
a_P[0]=2130705588;a_1102(a_1001,1,a_P); goto a_G6;
a_G5:a_P[0]=2130705583;a_P[1]=to_LIST(a_1285)->offset[a_1153];a_1102(a_1001,2,a_P);
a_G6:a_1153=a_1204; return;
} /* addprofilingdef */
static void a_1116(void){ /* addprofilingcount */
int a_P[2];
if(!a_1323(a_1204,33554432)){ return;}
a_P[0]=2130705578;a_P[1]=to_LIST(a_1285)->offset[a_1204];a_1102(a_1001,2,a_P); return;
} /* addprofilingcount */
static void a_1181(void){ /* profilingdeclaration */
int a_P[2];
a_P[0]=2130705570;a_1102(a_1001,1,a_P);
if(!a_equal(a_1153,0)){ goto a_G4;}
a_P[0]=2130705562;a_1102(a_1001,1,a_P); return;
a_G4:a_P[0]=2130705558;a_P[1]=to_LIST(a_1285)->offset[a_1153];a_1102(a_1001,2,a_P); return;
} /* profilingdeclaration */
static void a_1118(void){ /* addtracing */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
if(!a_1323(a_1204,16777216)){ return;}
a_1315(a_1204,a_P);a_L1=a_P[0];
a_L3=0;a_L2=0;
a_G4:if(a_mreq(a_L3,a_L1)){ goto a_G9;}
a_1311(a_1204,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
if(a_equal(a_L4,16777376)){ goto a_G4;}
a_incr(a_L2); goto a_G4;
a_G9:a_P[0]=2130705553;a_P[1]=a_1204;a_P[2]=a_L2;a_1102(a_1001,3,a_P);
a_L3=0;
a_G11:if(a_mreq(a_L3,a_L1)){ goto a_G17;}
a_1311(a_1204,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
if(a_equal(a_L4,16777376)){ goto a_G11;}
a_putchar(a_1103,44);
a_1142(a_L3); goto a_G11;
a_G17:a_P[0]=2130705545;a_1102(a_1001,1,a_P); return;
} /* addtracing */
static void a_1111(int a_F1,int a_F2){ /* Tlabel+>a+>a */

a_1158=a_F2;
if(a_equal(a_F1,0)){ return;}
a_1174(a_F1);
a_putchar(a_1103,58); return;
} /* Tlabel */
static void a_1152(int a_F1){ /* jumptolabel+>a */
int a_P[2];
if(a_equal(a_F1,a_1158)){ return;}
a_P[0]=2130705541;a_P[1]=a_F1;a_1102(a_1001,2,a_P); return;
} /* jumptolabel */
static void a_1104(int a_F1){ /* Taffix+>a */
int a_P[1];
{register int a_r1=to_LIST(a_1443)->offset[a_F1];
 if(a_r1==16777409){ goto a_G2;}
 if(a_r1==16777424){ return;}
  goto a_G3;}
a_G2:a_incr(a_F1);
a_G3:a_P[0]=a_F1;a_1105(a_P); return;
} /* Taffix */
static void a_1105(int a_A[1]){ /* Taffixinner+>a> */
int a_L2;int a_P[3];
{register int a_r1=to_LIST(a_1443)->offset[a_A[0]];
 if(a_r1==16777475||a_r1==16777479||a_r1==16777471){ goto a_G2;}
 if(a_r1==16777459){ goto a_G2;}
 if(a_r1==16777448){ goto a_G5;}
  goto a_G7;}
a_G2:a_P[0]=2130705537;a_P[1]=a_A[0];a_1102(a_1001,2,a_P);
a_G3:a_incr(a_A[0]);
a_incr(a_A[0]); return;
a_G5:a_incr(a_A[0]);
a_P[0]=a_A[0];a_1109(a_P);a_A[0]=a_P[0]; return;
a_G7:a_1112(to_LIST(a_1443)->offset[a_A[0]],a_P);a_L2=a_P[0];
a_incr(a_A[0]);
a_P[0]=2130705534;a_P[1]=a_A[0];a_P[2]=a_L2;a_1102(a_1001,3,a_P); goto a_G3;
} /* Taffixinner */
static void a_1112(int a_F1,int a_A[1]){ /* Tlimittail+>a+a> */

{ if(a_F1==16777231){ goto a_G2;}
 if(a_F1==16777269){ goto a_G3;}
 if(a_F1==16777291){ goto a_G4;}
 if(a_F1==16777295){ goto a_G5;}
 if(a_F1==16777299){ goto a_G6;}
  goto a_G7;}
a_G2:a_A[0]=2047260179; return;
a_G3:a_A[0]=2047260183; return;
a_G4:a_A[0]=2047260187; return;
a_G5:a_A[0]=2047260191; return;
a_G6:a_A[0]=2047260195; return;
a_G7:a_1423(a_1001,2130705528); return;
} /* Tlimittail */
static void a_1109(int a_A[1]){ /* Tindex+>a> */
int a_L2;int a_P[3];
if(!a_1323(a_1204,67108864)){ goto a_G12;}
a_P[0]=2130705523;a_P[1]=a_A[0];a_P[2]=a_A[0];a_1102(a_1001,3,a_P);
a_incr(a_A[0]);
a_incr(a_A[0]);
a_P[0]=a_A[0];a_1105(a_P);a_A[0]=a_P[0];
a_incr(a_A[0]);
a_subtr(to_LIST(a_1443)->offset[a_A[0]],1,a_L2);
a_incr(a_A[0]);
if(a_equal(a_L2,0)){ goto a_G11;}
a_P[0]=2130705512;a_P[1]=a_L2;a_1102(a_1001,2,a_P);
a_G11:a_P[0]=2130705509;a_P[1]=a_1204;a_1102(a_1001,2,a_P); return;
a_G12:a_P[0]=2130705505;a_P[1]=a_A[0];a_1102(a_1001,2,a_P);
a_incr(a_A[0]);
a_incr(a_A[0]);
a_P[0]=a_A[0];a_1105(a_P);a_A[0]=a_P[0];
a_incr(a_A[0]);
a_subtr(to_LIST(a_1443)->offset[a_A[0]],1,a_L2);
a_incr(a_A[0]);
if(!a_equal(a_L2,0)){ goto a_G21;}
a_P[0]=2130705497;a_1102(a_1001,1,a_P); return;
a_G21:a_P[0]=2130705494;a_P[1]=a_L2;a_1102(a_1001,2,a_P); return;
} /* Tindex */
static void a_1135(int a_F1,int a_F2){ /* extensionblock+>a+>a */
int a_L3;int a_L4;int a_P[3];
a_incr(a_F2);
a_L3=a_F2;
a_G3:if(a_equal(to_LIST(a_1443)->offset[a_L3],16777436)){ goto a_G5;}
a_incr(a_L3); goto a_G3;
a_G5:a_incr(a_L3);
a_G6:if(a_less(to_LIST(a_1443)->offset[a_L3],0)){ goto a_G10;}
a_subtr(a_F1,to_LIST(a_1443)->offset[a_L3],a_L4);
a_incr(a_L3);
a_P[0]=2130705490;a_P[1]=2047260199;a_P[2]=a_L4;a_1102(a_1001,3,a_P); goto a_G6;
a_G10:a_1104(a_F2);
a_putchar(a_1103,59); return;
} /* extensionblock */
static void a_1107(int a_F1,int a_F2){ /* Textension+>a+>a */
int a_L3;int a_L4;int a_P[4];
a_incr(a_F1);
a_L4=to_LIST(a_1443)->offset[a_F1];
a_incr(a_F1);
a_L3=a_F1;
a_P[0]=2130705486;a_P[1]=2047260199;a_P[2]=a_L3;a_P[3]=a_L4;a_1102(a_1001,4,a_P);
a_add(2,a_F1,a_F1);
a_G7:a_1135(a_L4,a_F1);
a_F1=to_LIST(a_1443)->offset[a_F1];
if(!a_equal(a_F1,0)){ goto a_G7;}
a_P[0]=2130705474;a_P[1]=a_L3;a_P[2]=a_L4;a_1102(a_1001,3,a_P);
a_1152(a_F2); return;
} /* Textension */
static int a_1159(int a_F1,int a_F2){ /* numbersequal+>a+>a */
int a_L3;int a_P[1];
a_1017(0,a_F1,a_P);a_F1=a_P[0];
a_1017(0,a_F2,a_P);a_F2=a_P[0];
if(!a_1374(23,a_F1,a_F2)){ goto a_G5;}
a_L3=1; goto a_G6;
a_G5:a_L3=0;
a_G6:a_1365(a_F1);
a_1365(a_F2);
if(!a_is(a_L3)){ return 0;} return 1;
} /* numbersequal */
static void a_1122(int a_F1,int a_A[1]){ /* boxclassifier+>a+a> */
int a_P[2];
{register int a_r1=to_LIST(a_1443)->offset[a_F1];
 if(!(a_r1==16777471||a_r1==16777479||a_r1==16777475||a_r1==16777459)){ goto a_G3;}
}
a_A[0]=a_F1; return;
a_G3:a_A[0]=2047260199;
a_P[0]=2130705465;a_P[1]=a_A[0];a_1102(a_1001,2,a_P);
a_1104(a_F1);
a_P[0]=2130705459;a_1102(a_1001,1,a_P); return;
} /* boxclassifier */
static int a_1149(int a_F1){ /* iscompletearea+>a */

if(!a_equal(to_LIST(a_1443)->offset[a_F1],0)){ return 0;}
a_incr(a_F1);
a_incr(a_F1);
if(!a_equal(to_LIST(a_1443)->offset[a_F1],a_1026)){ return 0;}
a_incr(a_F1);
if(!a_equal(to_LIST(a_1443)->offset[a_F1],a_1025)){ return 0;} return 1;
} /* iscompletearea */
static void a_1114(int a_F1,int a_F2,int a_F3){ /* Tsingleifcondition+>a+>a+>a */
int a_P[5];
if(!a_1159(a_F1,a_F2)){ goto a_G3;}
a_P[0]=2130705456;a_P[1]=a_F3;a_P[2]=a_F1;a_1102(a_1001,3,a_P); return;
a_G3:if(!a_1159(a_F1,a_1026)){ goto a_G5;}
a_P[0]=2130705452;a_P[1]=a_F3;a_P[2]=a_F2;a_1102(a_1001,3,a_P); return;
a_G5:if(!a_1159(a_F2,a_1025)){ goto a_G7;}
a_P[0]=2130705448;a_P[1]=a_F3;a_P[2]=a_F1;a_1102(a_1001,3,a_P); return;
a_G7:a_P[0]=2130705444;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_F3;a_P[4]=a_F2;a_1102(a_1001,5,a_P); return;
} /* Tsingleifcondition */
static void a_1108(int a_F1,int a_F2){ /* Tifcondition+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_G1:a_incr(a_F1);
a_L3=to_LIST(a_1443)->offset[a_F1];
a_incr(a_F1);
a_L4=to_LIST(a_1443)->offset[a_F1];
a_1114(a_L3,a_L4,a_F2);
a_incr(a_F1);
if(!a_equal(to_LIST(a_1443)->offset[a_F1],16777442)){ return;}
a_P[0]=2130705437;a_1102(a_1001,1,a_P); goto a_G1;
} /* Tifcondition */
static void a_1110(int a_F1,int a_F2){ /* Tjumptoareas+>a+>a */
int a_L3;int a_L4;int a_L5;int a_P[3];
a_G1:a_L5=to_LIST(a_1443)->offset[a_F1];
if(!a_equal(a_L5,0)){ goto a_G10;}
a_incr(a_F1);
a_L3=to_LIST(a_1443)->offset[a_F1];
a_P[0]=2130705434;a_1102(a_1001,1,a_P);
a_1108(a_F1,a_F2);
a_P[0]=2130705430;a_P[1]=a_1204;a_P[2]=a_F2;a_1102(a_1001,3,a_P);
if(a_equal(a_L3,a_1158)){ return;}
a_P[0]=2130705420;a_P[1]=to_LIST(a_1443)->offset[a_F1];a_1102(a_1001,2,a_P); return;
a_G10:if(!a_1149(a_L5)){ goto a_G25;}
a_incr(a_F1);
a_L3=to_LIST(a_1443)->offset[a_F1];
a_incr(a_L5);
a_L4=to_LIST(a_1443)->offset[a_L5];
if(!a_equal(a_L3,a_1158)){ goto a_G20;}
if(a_equal(a_L3,a_L4)){ return;}
a_P[0]=2130705434;a_1102(a_1001,1,a_P);
a_1108(a_F1,a_F2);
a_P[0]=2130705417;a_P[1]=a_L4;a_1102(a_1001,2,a_P); return;
a_G20:a_P[0]=2130705412;a_1102(a_1001,1,a_P);
a_1108(a_F1,a_F2);
a_P[0]=2130705408;a_P[1]=a_L3;a_1102(a_1001,2,a_P);
if(a_equal(a_L4,a_1158)){ return;}
a_P[0]=2130705404;a_P[1]=a_L4;a_1102(a_1001,2,a_P); return;
a_G25:a_incr(a_F1);
a_P[0]=2130705412;a_1102(a_1001,1,a_P);
a_1108(a_F1,a_F2);
a_P[0]=2130705408;a_P[1]=to_LIST(a_1443)->offset[a_F1];a_1102(a_1001,2,a_P);
a_F1=a_L5; goto a_G1;
} /* Tjumptoareas */
static void a_1106(int a_F1,int a_F2){ /* Tbox+>a+>a */
int a_L3;int a_P[1];
a_P[0]=2130705401;a_1102(a_1001,1,a_P);
a_incr(a_F1);
a_1122(a_F1,a_P);a_L3=a_P[0];
a_incr(a_F2);
a_1110(a_F2,a_L3);
a_P[0]=2130705698;a_1102(a_1001,1,a_P); return;
} /* Tbox */
static void a_1113(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5,int a_F6,int a_F7){ /* Trulecall+>a+>a+>a+>a+>a+>a+>a */
int a_L8;int a_L9;int a_P[3];
a_1123=a_F1;
a_incr(a_F7);
if(!a_1151(a_F7,a_F3,a_F4)){ goto a_G5;}
a_P[0]=2130705398;a_P[1]=a_F1;a_P[2]=a_F4;a_1102(a_1001,3,a_P); return;
a_G5:if(!a_1325(a_F1)){ goto a_G7;}
a_1147(a_F7,a_F4); return;
a_G7:if(!a_1321(a_F1)){ goto a_G9;}
a_1143(a_F5,a_F6,a_F7,a_F4); return;
a_G9:if(!a_1322(a_F1,a_P)){ goto a_G13;}a_L8=a_P[0];
if(!a_equal(a_L8,1)){ goto a_G12;}
a_1146(a_F3,a_F4); return;
a_G12:a_1145(a_F2,a_F7,a_F4); return;
a_G13:if(!a_1323(a_F1,12288)){ goto a_G18;}
a_1183(a_F3,a_F4,a_P);a_L9=a_P[0];
a_1165(a_F7);
a_1184(a_L9,a_F3);
a_G17:a_1185(a_L9,a_F3,a_F4); return;
a_G18:a_1187(a_F7);
a_1183(a_F3,a_F4,a_P);a_L9=a_P[0];
a_1188(a_F7,a_L9,a_F4);
a_1184(a_L9,a_F3);
a_1186(a_F7); goto a_G17;
} /* Trulecall */
static void a_1157(int a_A[1]){ /* nextaffix+>a> */

a_G1:if(!a_equal(to_LIST(a_1443)->offset[a_A[0]],16777436)){ goto a_G3;}
a_incr(a_A[0]); return;
a_G3:a_incr(a_A[0]); goto a_G1;
} /* nextaffix */
static int a_1150(int a_F1){ /* isdummyaffix+>a */

{register int a_r1=to_LIST(a_1443)->offset[a_F1];
 if(a_r1==16777424||a_r1==16777409){ return 1;}
  return 0;}
} /* isdummyaffix */
static int a_1148(int a_F1){ /* hasoutaffix+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1315(a_1123,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_mreq(a_L3,a_L2)){ return 0;}
if(!a_1150(a_F1)){ goto a_G7;}
a_G5:a_incr(a_L3);
a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0]; goto a_G3;
a_G7:a_1311(a_1123,a_L3,a_P);a_L4=a_P[0];
if(a_equal(a_L4,16777376)){ return 1;}
if(a_equal(a_L4,16777382)){ return 1;}
if(a_equal(a_L4,16777388)){ return 1;} goto a_G5;
} /* hasoutaffix */
static int a_1151(int a_F1,int a_F2,int a_F3){ /* isrulediscarded+>a+>a+>a */

if(a_1323(a_1123,256)){ return 0;}
if(a_1323(a_1123,1024)){ return 0;}
if(a_1323(a_1123,32768)){ return 0;}
if(a_1148(a_F1)){ return 0;}
if(!a_1323(a_1123,512)){ return 1;}
if(!a_equal(a_F2,a_F3)){ return 0;} return 1;
} /* isrulediscarded */
static void a_1146(int a_F1,int a_F2){ /* genshiftaffix+>a+>a */
int a_L3;int a_P[4];
a_1306(a_1204,a_P);a_L3=a_P[0];
if(a_equal(a_F1,a_1158)){ goto a_G6;}
if(!a_equal(a_F1,a_F2)){ goto a_G5;}
a_F2=a_1158; goto a_G6;
a_G5:if(!a_noteq(a_F2,a_1158)){ goto a_G7;}
a_G6:a_P[0]=2130705392;a_P[1]=a_L3;a_P[2]=a_F2;a_P[3]=a_F1;a_1102(a_1001,4,a_P); return;
a_G7:a_P[0]=2130705381;a_P[1]=a_F1;a_P[2]=a_L3;a_1102(a_1001,3,a_P); return;
} /* genshiftaffix */
static void a_1145(int a_F1,int a_F2,int a_F3){ /* gengetaffixno+>a+>a+>a */
int a_P[2];
if(!a_noteq(a_F1,2)){ goto a_G3;}
a_1418(a_1001,2130705371); return;
a_G3:if(!a_1150(a_F2)){ goto a_G5;}
a_P[0]=2130705365;a_P[1]=a_F3;a_1102(a_1001,2,a_P); return;
a_G5:a_1104(a_F2);
a_P[0]=2130705361;a_P[1]=a_F3;a_1102(a_1001,2,a_P); return;
} /* gengetaffixno */
static void a_1147(int a_F1,int a_F2){ /* genwaitfor+>a+>a */
int a_P[2];
a_P[0]=2130705356;a_1102(a_1001,1,a_P);
a_1104(a_F1);
a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0];
a_putchar(a_1103,44);
a_1104(a_F1);
a_P[0]=2130705351;a_P[1]=a_F2;a_1102(a_1001,2,a_P); return;
} /* genwaitfor */
static void a_1120(int a_F1,int a_A[2]){ /* assignmentsource+>a+a>+a> */
int a_P[2];
{register int a_r1=to_LIST(a_1443)->offset[a_F1];
 if(!(a_r1==16777471||a_r1==16777479||a_r1==16777475||a_r1==16777459)){ goto a_G4;}
}
a_A[0]=a_F1;
a_A[1]=0; return;
a_G4:a_A[0]=2047260199;
a_A[1]=1;
a_P[0]=2130705347;a_P[1]=a_A[0];a_1102(a_1001,2,a_P);
a_1104(a_F1);
a_putchar(a_1103,59); return;
} /* assignmentsource */
static void a_1143(int a_F1,int a_F2,int a_F3,int a_F4){ /* genassignment+>a+>a+>a+>a */
int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[6];
a_L5=a_F3;
a_P[0]=a_F3;a_1157(a_P);a_F3=a_P[0];
a_L8=0;
a_L9=1;
a_G5:if(a_mreq(a_L9,a_F1)){ goto a_G10;}
a_incr(a_L9);
a_P[0]=a_F3;a_1157(a_P);a_F3=a_P[0];
{register int a_r1=to_LIST(a_1443)->offset[a_F3];
 if(a_r1==16777397||a_r1==16777424||a_r1==16777409){ goto a_G5;}
}
a_incr(a_L8); goto a_G5;
a_G10:if(a_more(a_L8,1)){ goto a_G12;}
if(!a_is(a_F2)){ goto a_G13;}
a_G12:a_1120(a_L5,a_P);a_L6=a_P[0];a_L7=a_P[1]; goto a_G14;
a_G13:a_L6=0;a_L7=0;
a_G14:a_F3=a_L5;
a_P[0]=a_F3;a_1157(a_P);a_F3=a_P[0];
a_L9=1;
a_G17:if(a_mreq(a_L9,a_F1)){ goto a_G27;}
a_incr(a_L9);
a_P[0]=a_F3;a_1157(a_P);a_F3=a_P[0];
{register int a_r1=to_LIST(a_1443)->offset[a_F3];
 if(a_r1==16777397||a_r1==16777424||a_r1==16777409){ goto a_G17;}
}
a_1104(a_F3);
if(!a_equal(a_L6,0)){ goto a_G26;}
a_putchar(a_1103,61);
a_1104(a_L5);
a_putchar(a_1103,59); goto a_G17;
a_G26:a_P[0]=2130705340;a_P[1]=a_L6;a_1102(a_1001,2,a_P); goto a_G17;
a_G27:if(a_equal(a_F2,0)){ goto a_G29;}
a_P[0]=2130705336;a_P[1]=2047260203;a_P[2]=2047260203;a_P[3]=2047260203;a_P[4]=2047260203;a_P[5]=a_L6;a_1102(a_1001,6,a_P);
a_G29:if(a_equal(a_L7,0)){ goto a_G31;}
a_putchar(a_1103,125);
a_G31:a_P[0]=2130705365;a_P[1]=a_F4;a_1102(a_1001,2,a_P); return;
} /* genassignment */
static void a_1191(int a_F1,int a_F2,int a_F3,int a_F4){ /* repeatblockpreload+>a+>a+>a+>a */
int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[3];
a_incr(a_F1);
a_L5=to_LIST(a_1443)->offset[a_F1];
a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0];
a_L9=a_F3;
if(!a_less(a_L5,0)){ goto a_G8;}
a_F4=0;
a_subtr(0,a_L5,a_L7); goto a_G9;
a_G8:a_L7=a_L5;
a_G9:a_1306(a_1123,a_P);a_L6=a_P[0];
a_mult(a_L7,a_L6,a_L7);
a_G11:if(a_equal(a_L7,0)){ goto a_G25;}
a_1311(a_1123,a_L9,a_P);a_L8=a_P[0];
if(a_equal(a_L8,16777376)){ goto a_G19;}
if(!a_more(a_L5,0)){ goto a_G18;}
a_P[0]=2130705322;a_P[1]=a_F4;a_1102(a_1001,2,a_P);
a_G16:a_1104(a_F1);
a_putchar(a_1103,59); goto a_G19;
a_G18:a_P[0]=2130705317;a_P[1]=a_F4;a_1102(a_1001,2,a_P); goto a_G16;
a_G19:a_incr(a_L9);
if(a_less(a_L9,a_F2)){ goto a_G22;}
a_L9=a_F3;
a_G22:a_decr(a_L7);
a_incr(a_F4);
a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0]; goto a_G11;
a_G25:if(a_mreq(a_L5,0)){ return;}
a_P[0]=2130705312;a_P[1]=a_F4;a_P[2]=a_L6;a_1102(a_1001,3,a_P); return;
} /* repeatblockpreload */
static void a_1187(int a_F1){ /* regularcallpreload+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
a_1315(a_1123,a_P);a_L2=a_P[0];
a_L3=0;a_L4=0;
a_G3:if(a_equal(a_L3,a_L2)){ return;}
a_1311(a_1123,a_L3,a_P);a_L5=a_P[0];
a_incr(a_L3);
if(!a_equal(a_L5,16777376)){ goto a_G9;}
a_incr(a_L4);
a_G8:a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0]; goto a_G3;
a_G9:if(!a_equal(a_L5,16777382)){ goto a_G14;}
a_P[0]=2130705322;a_P[1]=a_L4;a_1102(a_1001,2,a_P);
a_incr(a_L4);
a_1104(a_F1);
a_putchar(a_1103,59); goto a_G8;
a_G14:if(!a_equal(a_L5,16777388)){ goto a_G8;}
a_1191(a_F1,a_L2,a_L3,a_L4); return;
} /* regularcallpreload */
static void a_1189(int a_F1,int a_F2,int a_F3){ /* repeatblockcall+>a+>a+>a */
int a_L4;int a_P[3];
if(a_equal(a_F2,0)){ goto a_G4;}
a_P[0]=a_F3;a_1119(a_P);a_F3=a_P[0];
a_P[0]=2130705300;a_1102(a_1001,1,a_P);
a_G4:a_incr(a_F1);
a_L4=to_LIST(a_1443)->offset[a_F1];
a_P[0]=a_F3;a_1119(a_P);
if(!a_equal(a_L4,0)){ goto a_G9;}
a_P[0]=2130705297;a_1102(a_1001,1,a_P); return;
a_G9:if(!a_less(a_L4,0)){ goto a_G12;}
a_subtr(0,a_L4,a_L4);
a_P[0]=2130705292;a_P[1]=a_L4;a_1102(a_1001,2,a_P); return;
a_G12:if(!a_equal(a_F2,0)){ goto a_G14;}
a_P[0]=2130705287;a_P[1]=a_L4;a_1102(a_1001,2,a_P); return;
a_G14:a_P[0]=2130705283;a_P[1]=a_L4;a_P[2]=a_F2;a_1102(a_1001,3,a_P); return;
} /* repeatblockcall */
static void a_1206(int a_F1){ /* tracepre+>a */
int a_P[1];
if(a_equal(a_1124,0)){ return;}
if(a_1323(a_1123,16)){ return;}
if(a_equal(a_F1,0)){ return;}
a_P[0]=2130705278;a_1102(a_1001,1,a_P); return;
} /* tracepre */
static void a_1205(int a_F1,int a_F2){ /* tracepost+>a+>a */
int a_P[1];
if(a_equal(a_1124,0)){ return;}
if(a_1323(a_1123,16)){ return;}
if(!a_equal(a_F1,0)){ goto a_G6;}
if(a_lseq(a_F2,0)){ return;}
a_P[0]=2130705274;a_1102(a_1001,1,a_P); return;
a_G6:a_putchar(a_1103,41); return;
} /* tracepost */
static void a_1188(int a_F1,int a_F2,int a_F3){ /* regularrulecall+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[2];
a_1315(a_1123,a_P);a_L4=a_P[0];
a_1206(a_F2);
a_P[0]=2130705271;a_P[1]=a_1123;a_1102(a_1001,2,a_P);
a_L5=0;a_L6=0;a_L7=0;
a_G5:if(!a_equal(a_L5,a_L4)){ goto a_G11;}
if(!a_equal(a_L6,0)){ goto a_G8;}
a_putchar(a_1103,41); goto a_G10;
a_G8:a_P[0]=a_L7;a_1119(a_P);
a_P[0]=2130705268;a_1102(a_1001,1,a_P);
a_G10:a_1205(a_F2,a_F3); return;
a_G11:a_1311(a_1123,a_L5,a_P);a_L8=a_P[0];
a_incr(a_L5);
if(a_equal(a_L8,16777376)){ goto a_G15;}
if(!a_equal(a_L8,16777382)){ goto a_G17;}
a_G15:a_incr(a_L6);
a_G16:a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0]; goto a_G5;
a_G17:if(!a_equal(a_L8,16777388)){ goto a_G19;}
a_1189(a_F1,a_L6,a_L7); return;
a_G19:a_P[0]=a_L7;a_1119(a_P);a_L7=a_P[0];
a_1104(a_F1); goto a_G16;
} /* regularrulecall */
static void a_1190(int a_F1,int a_F2,int a_F3,int a_F4){ /* repeatblockpostload+>a+>a+>a+>a */
int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[3];
a_incr(a_F1);
a_L5=to_LIST(a_1443)->offset[a_F1];
a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0];
a_L7=a_F3;
if(!a_less(a_L5,0)){ goto a_G8;}
a_F4=0;
a_subtr(0,a_L5,a_L8); goto a_G9;
a_G8:a_L8=a_L5;
a_G9:a_1306(a_1123,a_P);a_L6=a_P[0];
a_mult(a_L8,a_L6,a_L8);
a_G11:if(a_equal(a_L8,0)){ goto a_G26;}
a_1311(a_1123,a_L7,a_P);a_L9=a_P[0];
if(a_1150(a_F1)){ goto a_G20;}
if(a_equal(a_L9,16777376)){ goto a_G16;}
if(!a_equal(a_L9,16777382)){ goto a_G20;}
a_G16:a_1104(a_F1);
if(!a_more(a_L5,0)){ goto a_G19;}
a_P[0]=2130705264;a_P[1]=a_F4;a_1102(a_1001,2,a_P); goto a_G20;
a_G19:a_P[0]=2130705259;a_P[1]=a_F4;a_1102(a_1001,2,a_P);
a_G20:a_incr(a_L7);
if(a_less(a_L7,a_F2)){ goto a_G23;}
a_L7=a_F3;
a_G23:a_decr(a_L8);
a_incr(a_F4);
a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0]; goto a_G11;
a_G26:if(a_mreq(a_L5,0)){ return;}
a_P[0]=2130705254;a_P[1]=a_F4;a_P[2]=a_L6;a_1102(a_1001,3,a_P); return;
} /* repeatblockpostload */
static void a_1186(int a_F1){ /* regularcallpostload+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
a_1315(a_1123,a_P);a_L2=a_P[0];
a_L3=0;a_L4=0;
a_G3:if(a_equal(a_L3,a_L2)){ return;}
a_1311(a_1123,a_L3,a_P);a_L5=a_P[0];
a_incr(a_L3);
if(a_equal(a_L5,16777376)){ goto a_G8;}
if(!a_equal(a_L5,16777382)){ goto a_G13;}
a_G8:if(a_1150(a_F1)){ goto a_G11;}
a_1104(a_F1);
a_P[0]=2130705264;a_P[1]=a_L4;a_1102(a_1001,2,a_P);
a_G11:a_incr(a_L4);
a_G12:a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0]; goto a_G3;
a_G13:if(!a_equal(a_L5,16777388)){ goto a_G12;}
a_1190(a_F1,a_L2,a_L3,a_L4); return;
} /* regularcallpostload */
static void a_1183(int a_F1,int a_F2,int a_A[1]){ /* regularcalld1+>a+>a+a> */
int a_P[1];
if(!a_1323(a_1123,512)){ goto a_G9;}
if(!a_noteq(a_F1,a_1158)){ goto a_G7;}
if(a_equal(a_F2,a_1158)){ goto a_G5;}
if(!a_lseq(a_F1,0)){ goto a_G7;}
a_G5:a_A[0]=2;
a_P[0]=2130705242;a_1102(a_1001,1,a_P); return;
a_G7:a_A[0]=1;
a_P[0]=2130705238;a_1102(a_1001,1,a_P); return;
a_G9:a_A[0]=0; return;
} /* regularcalld1 */
static void a_1184(int a_F1,int a_F2){ /* regularcalld2+>a+>a */
int a_P[2];
if(!a_equal(a_F1,1)){ goto a_G3;}
a_P[0]=2130705235;a_1102(a_1001,1,a_P); return;
a_G3:if(!a_equal(a_F1,2)){ goto a_G5;}
a_P[0]=2130705232;a_P[1]=a_F2;a_1102(a_1001,2,a_P); return;
a_G5:a_putchar(a_1103,59); return;
} /* regularcalld2 */
static void a_1185(int a_F1,int a_F2,int a_F3){ /* regularcalld3+>a+>a+>a */
int a_P[3];
if(!a_equal(a_F1,1)){ goto a_G4;}
a_P[0]=2130705228;a_P[1]=a_F3;a_P[2]=a_F2;a_1102(a_1001,3,a_P); return;
a_G4:a_P[0]=2130705365;a_P[1]=a_F3;a_1102(a_1001,2,a_P); return;
} /* regularcalld3 */
static void a_1162(int a_F1){ /* pidginalttagtail+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1315(a_1123,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_equal(a_L3,a_L2)){ return;}
a_1311(a_1123,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
if(!a_equal(a_L4,16777376)){ goto a_G10;}
if(!a_equal(to_LIST(a_1443)->offset[a_F1],16777424)){ goto a_G9;}
a_putchar(a_1103,48); goto a_G10;
a_G9:a_putchar(a_1103,49);
a_G10:if(a_equal(a_L4,16777388)){ return;}
a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0]; goto a_G3;
} /* pidginalttagtail */
static void a_1163(int a_F1){ /* pidginrepeatblock+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_incr(a_F1);
a_L2=to_LIST(a_1443)->offset[a_F1];
a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0];
a_1170(a_L2);
if(!a_less(a_L2,0)){ goto a_G7;}
a_subtr(0,a_L2,a_L3); goto a_G8;
a_G7:a_L3=a_L2;
a_G8:a_1306(a_1123,a_P);a_L4=a_P[0];
a_mult(a_L3,a_L4,a_L3);
a_G10:if(a_equal(a_L3,0)){ goto a_G15;}
a_putchar(a_1103,44);
a_1104(a_F1);
a_decr(a_L3);
a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0]; goto a_G10;
a_G15:if(a_more(a_L2,0)){ return;}
a_P[0]=2130705224;a_1102(a_1001,1,a_P); return;
} /* pidginrepeatblock */
static void a_1164(int a_F1,int a_F2){ /* pidginruleargs+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[1];
a_1315(a_1123,a_P);a_L3=a_P[0];
a_L4=0;a_L5=0;
a_G3:if(a_equal(a_L4,a_L3)){ return;}
a_1311(a_1123,a_L4,a_P);a_L6=a_P[0];
a_incr(a_L4);
if(!a_equal(a_L6,16777388)){ goto a_G9;}
a_P[0]=a_L5;a_1119(a_P);
a_1163(a_F1); return;
a_G9:if(!a_equal(a_L6,16777376)){ goto a_G12;}
if(!a_is(a_F2)){ goto a_G12;}
if(a_equal(to_LIST(a_1443)->offset[a_F1],16777424)){ goto a_G14;}
a_G12:a_P[0]=a_L5;a_1119(a_P);a_L5=a_P[0];
a_1104(a_F1);
a_G14:a_P[0]=a_F1;a_1157(a_P);a_F1=a_P[0]; goto a_G3;
} /* pidginruleargs */
static void a_1165(int a_F1){ /* pidginrulecall+>a */
int a_L2;int a_P[2];
a_P[0]=2130705219;a_P[1]=a_1123;a_1102(a_1001,2,a_P);
if(!a_1323(a_1123,8192)){ goto a_G5;}
a_L2=1;
a_1162(a_F1); goto a_G6;
a_G5:a_L2=0;
a_G6:a_putchar(a_1103,40);
a_1164(a_F1,a_L2);
a_putchar(a_1103,41); return;
} /* pidginrulecall */
static void a_1236(int a_F1){ /* pushEXPR+>a */

{register int *a_r1=a_extension(a_1213,1);a_r1[0]=a_F1;to_LIST(a_1213)->aupb+=1;}
  return;
} /* pushEXPR */
static void a_1228(int a_A[1]){ /* getitemdef+>a> */

if(!a_1323(a_A[0],8)){ return;}
a_A[0]=to_LIST(a_1285)->offset[a_A[0]]; return;
} /* getitemdef */
static void a_1220(int a_F1){ /* checklisttype+>a */

{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G3;}
}
if(!a_1323(a_F1,24)){ return;}
a_G3:a_1418(a_1001,2130706137); return;
} /* checklisttype */
static void a_1218(int a_F1){ /* checkcalibretype+>a */

{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G3;}
}
if(!a_1323(a_F1,8)){ return;}
a_G3:a_1418(a_1001,2130706131); return;
} /* checkcalibretype */
static void a_1219(int a_F1,int a_F2){ /* checkconstanttype+>a+>a */

{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(a_r1==16777335){ goto a_G2;}
 if(a_r1==16777304){ goto a_G3;}
 if(a_r1==16777309||a_r1==16777314){ goto a_G4;}
  goto a_G5;}
a_G2:if(a_equal(a_F2,1)){ goto a_G5;}
a_G3:if(!a_1323(a_F1,24)){ return;} goto a_G5;
a_G4:if(!a_equal(a_F2,0)){ goto a_G3;}
a_G5:a_1418(a_1001,2130706124); return;
} /* checkconstanttype */
static void a_1237(void){ /* readexpression */
int a_L1;int a_L2;int a_P[1];
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706096); return;
a_G5:a_1219(a_L1,1);
if(a_equal(to_LIST(a_1285)->offset[a_L1-1],0)){ goto a_G8;}
a_G7:a_1418(a_1001,2130706117); return;
a_G8:a_1236(a_L1);
a_L2=to_LIST(a_1213)->aupb;
a_1236(a_1229);
a_1229=a_L2;
to_LIST(a_1285)->offset[a_L1-1]=to_LIST(a_1213)->aupb;
a_G13:{ if(a_1457==16777439){ goto a_G14;}
 if(a_1457==16777459){ goto a_G16;}
 if(a_1457==16777471){ goto a_G19;}
 if(a_1457==16777269||a_1457==16777291){ goto a_G23;}
 if(a_1457==16777231){ goto a_G31;}
 if(a_1457==16777436||a_1457==16777421||a_1457==16777445||a_1457==16777418||a_1457==16777400||a_1457==16777430||a_1457==16777451||a_1457==16777415||a_1457==16777427||a_1457==16777406){ goto a_G39;}
  goto a_G7;}
a_G14:a_1464();
a_1236(16777439); return;
a_G16:a_1236(16777459);
a_1236(a_1458);
a_G18:a_1464(); goto a_G13;
a_G19:a_L1=a_1458;
a_P[0]=a_L1;a_1228(a_P);a_L1=a_P[0];
a_1236(a_L1);
a_1219(a_L1,0); goto a_G18;
a_G23:a_1236(a_1457);
a_1464();
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464();
a_P[0]=a_L1;a_1228(a_P);a_L1=a_P[0];
a_1236(a_L1);
a_1220(a_L1); goto a_G13;
a_G31:a_1236(a_1457);
a_1464();
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464();
a_P[0]=a_L1;a_1228(a_P);a_L1=a_P[0];
a_1236(a_L1);
a_1218(a_L1); goto a_G13;
a_G39:a_1236(a_1457); goto a_G18;
} /* readexpression */
static int a_1212(int a_F1){ /* E+>a */

if(!a_equal(to_LIST(a_1213)->offset[a_1222],a_F1)){ return 0;}
a_incr(a_1222); return 1;
} /* E */
static int a_1214(int a_A[1]){ /* Eitem+a> */

a_A[0]=to_LIST(a_1213)->offset[a_1222];
if(!a_was(a_1285,a_A[0])){ return 0;}
a_incr(a_1222); return 1;
} /* Eitem */
static int a_1215(int a_F1,int a_A[2]){ /* Eop+>a+a>+a> */

a_A[0]=to_LIST(a_1213)->offset[a_1222];
{ if(a_A[0]==16777451){ goto a_G3;}
 if(a_A[0]==16777400){ goto a_G6;}
 if(a_A[0]==16777430){ goto a_G8;}
 if(a_A[0]==16777436||a_A[0]==16777421){ goto a_G10;}
 if(a_A[0]==16777418||a_A[0]==16777445){ goto a_G12;}
  return 0;}
a_G3:if(!a_equal(a_F1,0)){ return 0;}
a_A[1]=1;
a_G5:a_incr(a_1222); return 1;
a_G6:if(!a_lseq(a_F1,1)){ return 0;}
a_A[1]=2; goto a_G5;
a_G8:if(!a_lseq(a_F1,2)){ return 0;}
a_A[1]=3; goto a_G5;
a_G10:if(!a_lseq(a_F1,3)){ return 0;}
a_A[1]=4; goto a_G5;
a_G12:if(!a_lseq(a_F1,4)){ return 0;}
a_A[1]=5; goto a_G5;
} /* Eop */
static void a_1235(int a_F1,int a_F2,int a_F3){ /* optor+>a+>a+>a */

{ if(a_F1==16777451){ goto a_G2;}
 if(a_F1==16777400){ goto a_G3;}
 if(a_F1==16777430){ goto a_G4;}
 if(a_F1==16777436){ goto a_G5;}
 if(a_F1==16777421){ goto a_G6;}
 if(a_F1==16777445){ goto a_G7;}
 if(!(a_F1==16777418)){a_area_failed("optor",a_F1);}
 goto a_G8;}
a_G2:a_1375(1,a_F2,a_F3); return;
a_G3:a_1375(2,a_F2,a_F3); return;
a_G4:a_1375(3,a_F2,a_F3); return;
a_G5:a_1375(6,a_F2,a_F3); return;
a_G6:a_1375(7,a_F2,a_F3); return;
a_G7:a_1375(8,a_F2,a_F3); return;
a_G8:a_1375(9,a_F2,a_F3); return;
} /* optor */
static int a_1230(int a_A[1]){ /* loosebase+a> */
int a_P[1];
if(!a_1212(16777427)){ goto a_G4;}
if(!a_1233(0,a_P)){ return 0;}a_A[0]=a_P[0];
if(!a_1212(16777406)){ return 0;} return 1;
a_G4:if(!a_1212(16777459)){ goto a_G7;}
a_1017(0,to_LIST(a_1213)->offset[a_1222],a_P);a_A[0]=a_P[0];
a_G6:a_incr(a_1222); return 1;
a_G7:if(!a_1212(16777415)){ goto a_G10;}
if(!a_1230(a_P)){ return 0;}a_A[0]=a_P[0];
a_1375(4,a_A[0],a_A[0]); return 1;
a_G10:if(!a_1212(16777421)){ goto a_G13;}
if(!a_1230(a_P)){ return 0;}a_A[0]=a_P[0];
a_1375(5,a_A[0],a_A[0]); return 1;
a_G13:if(!a_1212(16777231)){ goto a_G16;}
a_1307(to_LIST(a_1213)->offset[a_1222],a_P);a_A[0]=a_P[0];
a_1017(1,a_A[0],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G16:if(!a_1214(a_P)){ return 0;}a_A[0]=a_P[0];
a_P[0]=a_A[0];a_1228(a_P);a_A[0]=a_P[0];
if(!a_equal(to_LIST(a_1285)->offset[a_A[0]-5],16777304)){ return 0;}
a_1231(a_A[0]);
if(!a_1323(a_A[0],32)){ return 0;}
a_1017(0,to_LIST(a_1285)->offset[a_A[0]],a_P);a_A[0]=a_P[0]; return 1;
} /* loosebase */
static int a_1233(int a_F1,int a_A[1]){ /* looseexpr+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[2];
if(!a_1230(a_P)){ return 0;}a_A[0]=a_P[0];
a_G2:if(!a_1215(a_F1,a_P)){ return 1;}a_L3=a_P[0];a_L4=a_P[1];
if(!a_1233(a_L4,a_P)){ goto a_G5;}a_L5=a_P[0];
a_1235(a_L3,a_L5,a_A[0]); goto a_G2;
a_G5:a_1365(a_A[0]); return 0;
} /* looseexpr */
static void a_1238(int a_F1,int a_F2){ /* setfinalvalue+>a+>a */

a_1295(a_F2,64);
to_LIST(a_1285)->offset[a_F2]=a_F1;
a_1354(a_F2,32); return;
} /* setfinalvalue */
static void a_1231(int a_F1){ /* looseeval+>a */
int a_L2;int a_L3;int a_P[3];
if(!a_1323(a_F1,8)){ goto a_G3;}
a_1423(a_1001,2130706111); return;
a_G3:if(a_1323(a_F1,32)){ return;}
if(!a_1323(a_F1,64)){ goto a_G8;}
a_P[0]=2047260217;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_P[2]=a_F1;a_1419(3,a_P);
a_1012(a_P);a_L3=a_P[0];
a_1238(a_L3,a_F1); return;
a_G8:a_1354(a_F1,64);
a_L2=a_1222;
a_1222=to_LIST(a_1285)->offset[a_F1-1];
a_incr(a_1222);
if(a_was(a_1213,a_1222)){ goto a_G14;}
a_1418(a_1001,2130706111); return;
a_G14:if(!a_1233(0,a_P)){ goto a_G17;}a_L3=a_P[0];
a_1024(a_L3,a_P);a_L3=a_P[0];
a_1238(a_L3,a_F1); goto a_G18;
a_G17:a_1295(a_F1,64);
a_G18:a_1222=a_L2; return;
} /* looseeval */
static void a_1232(void){ /* looseevaluation */
int a_L1;
if(a_1440()){ return;}
a_L1=a_1229;
a_G3:if(a_equal(a_L1,0)){ return;}
a_1231(to_LIST(a_1213)->offset[a_L1]);
a_incr(a_L1);
a_L1=to_LIST(a_1213)->offset[a_L1]; goto a_G3;
} /* looseevaluation */
static void a_1227(int a_F1,int a_F2,int a_A[1]){ /* getexprlimit+>a+>a+a> */
int a_P[1];
a_P[0]=a_F2;a_1228(a_P);a_F2=a_P[0];
if(!a_equal(a_F1,16777269)){ goto a_G4;}
a_1317(a_F2,a_P);a_A[0]=a_P[0]; goto a_G5;
a_G4:a_1318(a_F2,a_P);a_A[0]=a_P[0];
a_G5:a_1017(0,a_A[0],a_P);a_A[0]=a_P[0]; return;
} /* getexprlimit */
static void a_1223(int a_A[1]){ /* finalbase+a> */
int a_P[1];
if(!a_1212(16777427)){ goto a_G4;}
a_1226(0,a_P);a_A[0]=a_P[0];
if(!a_1212(16777406)){ return;} return;
a_G4:if(!a_1212(16777459)){ goto a_G7;}
a_1017(0,to_LIST(a_1213)->offset[a_1222],a_P);a_A[0]=a_P[0];
a_G6:a_incr(a_1222); return;
a_G7:if(!a_1212(16777415)){ goto a_G10;}
a_1223(a_P);a_A[0]=a_P[0];
a_1375(4,a_A[0],a_A[0]); return;
a_G10:if(!a_1212(16777421)){ goto a_G13;}
a_1223(a_P);a_A[0]=a_P[0];
a_1375(5,a_A[0],a_A[0]); return;
a_G13:if(!a_1212(16777231)){ goto a_G16;}
a_1307(to_LIST(a_1213)->offset[a_1222],a_P);a_A[0]=a_P[0];
a_1017(1,a_A[0],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G16:if(!a_1212(16777269)){ goto a_G18;}
a_1227(16777269,to_LIST(a_1213)->offset[a_1222],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G18:if(!a_1212(16777291)){ goto a_G20;}
a_1227(16777291,to_LIST(a_1213)->offset[a_1222],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G20:if(!a_1214(a_P)){ goto a_G24;}a_A[0]=a_P[0];
a_P[0]=a_A[0];a_1228(a_P);a_A[0]=a_P[0];
a_1224(a_A[0]);
a_1017(0,to_LIST(a_1285)->offset[a_A[0]],a_P);a_A[0]=a_P[0]; return;
a_G24:a_1418(a_1001,2130706106); return;
} /* finalbase */
static void a_1226(int a_F1,int a_A[1]){ /* finalexpr+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[2];
a_1223(a_P);a_A[0]=a_P[0];
a_G2:if(!a_1215(a_F1,a_P)){ return;}a_L3=a_P[0];a_L4=a_P[1];
a_1226(a_L4,a_P);a_L5=a_P[0];
a_1235(a_L3,a_L5,a_A[0]); goto a_G2;
} /* finalexpr */
static void a_1224(int a_F1){ /* finaleval+>a */
int a_L2;int a_L3;int a_P[3];
if(!a_1323(a_F1,8)){ goto a_G3;}
a_1423(a_1001,2130706101); return;
a_G3:if(a_1323(a_F1,32)){ return;}
if(!a_1323(a_F1,64)){ goto a_G8;}
a_P[0]=2047260217;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_P[2]=a_F1;a_1419(3,a_P);
a_1012(a_P);a_L2=a_P[0];
a_1238(a_L2,a_F1); return;
a_G8:a_1354(a_F1,64);
a_L3=a_1222;
a_1222=to_LIST(a_1285)->offset[a_F1-1];
a_incr(a_1222);
if(a_was(a_1213,a_1222)){ goto a_G14;}
a_1418(a_1001,2130706101); return;
a_G14:a_1226(0,a_P);a_L2=a_P[0];
a_1024(a_L2,a_P);a_L2=a_P[0];
a_1238(a_L2,a_F1);
a_1222=a_L3; return;
} /* finaleval */
static void a_1225(void){ /* finalevaluation */
int a_L1;
a_L1=a_1229;
a_G2:if(a_equal(a_L1,0)){ goto a_G6;}
a_1224(to_LIST(a_1213)->offset[a_L1]);
a_incr(a_L1);
a_L1=to_LIST(a_1213)->offset[a_L1]; goto a_G2;
a_G6:a_1229=0;
a_release(a_1213); return;
} /* finalevaluation */
static void a_1240(int a_F1,int a_A[1]){ /* storenumstring+>a+a> */
int a_L3;int a_P[1];
a_L3=to_LIST(a_1443)->aupb;
a_previous(a_1447,a_F1);
a_unpackstring(a_1447,a_F1,a_1443);
a_1007(0,a_L3,a_P);a_A[0]=a_P[0];
a_unstackto(a_1443,a_L3); return;
} /* storenumstring */
static int a_1239(int a_F1,int a_F2){ /* splitvirtualspace+>a+>a */
int a_L3;int a_L4;int a_L5;int a_P[1];
if(!a_1369(a_F1)){ return 0;}
if(!a_1369(a_F2)){ return 0;}
a_1240(183666537,a_P);a_L3=a_P[0];
a_1240(183666544,a_P);a_L4=a_P[0];
a_1017(0,a_L3,a_P);a_1216=a_P[0];
a_1017(0,a_L4,a_P);a_1217=a_P[0];
a_1017(0,a_L3,a_P);a_L5=a_P[0];
a_1375(7,a_L5,a_1217);
a_1017(1,a_F1,a_P);a_L5=a_P[0];
a_1375(7,a_L5,a_1217);
a_1017(1,a_F2,a_P);a_L5=a_P[0];
a_1375(9,a_L5,a_1217);
if(!a_1373(12,a_1217)){ return 0;} return 1;
} /* splitvirtualspace */
static void a_1234(int a_F1,int a_F2,int a_F3,int a_A[2]){ /* nextvirtualblock+>a+>a+>a+a>+a> */
int a_L6;int a_L7;int a_P[1];
a_1017(1,a_F1,a_P);a_L6=a_P[0];
a_1017(2,a_1216,a_P);a_L7=a_P[0];
a_1375(6,a_L7,a_L6);
a_1024(a_L6,a_P);a_A[0]=a_P[0];
a_1017(1,a_F2,a_P);a_L6=a_P[0];
a_1375(6,a_L6,a_1216);
a_1017(2,a_1217,a_P);a_L7=a_P[0];
a_1017(1,a_F3,a_P);a_L6=a_P[0];
a_1375(8,a_L7,a_L6);
a_1375(6,a_L6,a_1216);
a_1017(2,a_1216,a_P);a_L6=a_P[0];
a_1024(a_L6,a_P);a_A[1]=a_P[0];
a_1017(1,a_F1,a_P);a_L6=a_P[0];
a_1375(6,a_L6,a_1216); return;
} /* nextvirtualblock */
static void a_1221(void){ /* clearvirtualspace */

a_1365(a_1216);
a_1216=0;
a_1365(a_1217);
a_1217=0; return;
} /* clearvirtualspace */
static void a_1241(int a_F1,int a_F2,int a_A[1]){ /* virtualaddressoffset+>a+>a+a> */
int a_L4;int a_L5;int a_P[1];
a_1017(1,a_F2,a_P);a_L5=a_P[0];
a_1017(0,a_F1,a_P);a_L4=a_P[0];
a_1375(6,a_L5,a_L4);
a_1024(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* virtualaddressoffset */
static void a_1261(int a_A[1]){ /* getitemdef+>a> */

if(!a_1323(a_A[0],8)){ return;}
a_A[0]=to_LIST(a_1285)->offset[a_A[0]]; return;
} /* getitemdef */
static void a_1278(void){ /* skipentry */

a_G1:if(!a_equal(16777439,a_1457)){ goto a_G3;}
a_1464(); return;
a_G3:if(!a_equal(16777486,a_1457)){ goto a_G6;}
a_1464();
a_1418(a_1001,2130706221); return;
a_G6:a_1464(); goto a_G1;
} /* skipentry */
static void a_1277(void){ /* skipdatasection */

a_G1:if(!a_equal(16777254,a_1457)){ goto a_G4;}
a_G2:a_1464();
a_1278(); goto a_G1;
a_G4:if(a_equal(16777236,a_1457)){ goto a_G2;}
if(a_equal(16777266,a_1457)){ goto a_G2;}
if(a_equal(16777250,a_1457)){ goto a_G2;}
if(a_equal(16777224,a_1457)){ goto a_G2;}
if(a_equal(16777258,a_1457)){ goto a_G2;}
if(a_equal(16777246,a_1457)){ goto a_G2;}
if(a_equal(a_1457,16777285)){ return;}
a_1418(a_1001,2130706216); return;
} /* skipdatasection */
static void a_1251(void){ /* datasectioni */

if(a_1440()){ return;}
a_G2:if(!a_equal(16777254,a_1457)){ goto a_G5;}
a_1464();
a_1279(); goto a_G2;
a_G5:if(!a_equal(16777236,a_1457)){ goto a_G8;}
a_1464();
a_1237(); goto a_G2;
a_G8:if(!a_equal(16777266,a_1457)){ goto a_G11;}
a_1464();
a_1263(); goto a_G2;
a_G11:if(!a_equal(16777250,a_1457)){ goto a_G14;}
a_1464();
a_1256(); goto a_G2;
a_G14:if(!a_equal(16777224,a_1457)){ goto a_G17;}
a_G15:a_1464();
a_1278(); goto a_G2;
a_G17:if(a_equal(16777258,a_1457)){ goto a_G15;}
if(a_equal(16777246,a_1457)){ goto a_G15;}
if(a_equal(a_1457,16777285)){ return;}
a_1418(a_1001,2130706210); return;
} /* datasectioni */
static void a_1248(int a_F1){ /* checklisttype+>a */

{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G3;}
}
if(!a_1323(a_F1,24)){ return;}
a_G3:a_1418(a_1001,2130706204); return;
} /* checklisttype */
static void a_1244(int a_F1,int a_F2){ /* checkconstanttype+>a+>a */

{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(a_r1==16777335){ goto a_G2;}
 if(a_r1==16777304){ goto a_G3;}
  goto a_G4;}
a_G2:if(a_equal(a_F2,1)){ goto a_G4;}
a_G3:if(!a_1323(a_F1,24)){ return;}
a_G4:a_1418(a_1001,2130706198); return;
} /* checkconstanttype */
static void a_1246(int a_F1){ /* checkfillconstanttype+>a */

{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(a_r1==16777335){ goto a_G2;}
 if(a_r1==16777304){ return;}
  goto a_G3;}
a_G2:if(!a_1323(a_F1,24)){ return;}
a_G3:a_1418(a_1001,2130706191); return;
} /* checkfillconstanttype */
static void a_1245(int a_F1){ /* checkfiletype+>a */

{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(!(a_r1==16777340||a_r1==16777345)){ goto a_G3;}
}
if(!a_1323(a_F1,24)){ return;}
a_G3:a_1418(a_1001,2130706183); return;
} /* checkfiletype */
static void a_1256(void){ /* fileentry */
int a_L1;int a_L2;int a_L3;int a_P[1];
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706141); return;
a_G5:a_1245(a_L1);
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L2=a_1458;
a_1464();
if(a_equal(a_L2,1)){ goto a_G11;}
if(!a_equal(a_L2,3)){ goto a_G12;}
a_G11:a_1354(a_L1,32);
a_G12:if(a_equal(a_L2,2)){ goto a_G14;}
if(!a_equal(a_L2,3)){ goto a_G15;}
a_G14:a_1354(a_L1,64);
a_G15:a_1342(a_L1);
if(!a_equal(16777439,a_1457)){ goto a_G4;}

a_1464();
a_L3=0;
a_G20:a_incr(a_L3);
a_1308(a_L1,a_L3,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
a_P[0]=a_L2;a_1261(a_P);a_L2=a_P[0];
a_1248(a_L2); goto a_G20;
} /* fileentry */
static void a_1279(void){ /* skipfill */
int a_L1;int a_P[1];
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706141); return;
a_G5:a_P[0]=a_L1;a_1261(a_P);a_L1=a_P[0];
a_1248(a_L1);
if(!a_equal(16777455,a_1457)){ goto a_G4;}

a_1464();
a_1272(a_L1);
a_G11:if(!a_equal(16777439,a_1457)){ goto a_G13;}
a_1464(); return;
a_G13:a_1281();
a_1282(a_L1);
a_1280(a_L1); goto a_G11;
} /* skipfill */
static void a_1247(void){ /* checkfillitem */
int a_L1;
if(!a_equal(16777459,a_1457)){ goto a_G3;}
a_1464(); return;
a_G3:if(!a_equal(16777471,a_1457)){ goto a_G6;}
a_L1=a_1458;
a_1464(); goto a_G7;
a_G6:a_1418(a_1001,2130706141); return;
a_G7:a_1246(a_L1); return;
} /* checkfillitem */
static void a_1281(void){ /* skipfillitem */

if(!a_equal(16777427,a_1457)){ goto a_G6;}
a_1464();
a_G3:if(!a_equal(16777406,a_1457)){ goto a_G5;}
a_1464(); return;
a_G5:a_1247(); goto a_G3;
a_G6:a_1247(); return;
} /* skipfillitem */
static void a_1282(int a_F1){ /* skipfillrepeater+>a */
int a_L2;int a_L3;int a_P[4];
if(!a_equal(16777445,a_1457)){ return;}
a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G9;}
a_L3=a_1458;
a_1464();
if(!a_lseq(1,a_L3)){ goto a_G8;}
if(a_lseq(a_L3,1000)){ return;}
a_G8:a_P[0]=2047260233;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_P[2]=a_L3;a_P[3]=1000;a_1419(4,a_P); return;
a_G9:if(!a_equal(16777471,a_1457)){ goto a_G12;}
a_L2=a_1458;
a_1464(); goto a_G13;
a_G12:a_1418(a_1001,2130706141); return;
a_G13:a_1244(a_L2,1); return;
} /* skipfillrepeater */
static void a_1280(int a_F1){ /* skipfillinitializer+>a */
int a_L2;
a_G1:if(!a_equal(16777409,a_1457)){ return;}
a_1464();
if(!a_equal(16777471,a_1457)){ goto a_G6;}
a_L2=a_1458;
a_1464(); goto a_G7;
a_G6:a_1418(a_1001,2130706141); return;
a_G7:if(a_1323(a_L2,16)){ goto a_G10;}
if(a_noteq(to_LIST(a_1285)->offset[a_L2-5],16777335)){ goto a_G10;}
if(!a_is(to_LIST(a_1285)->offset[a_L2-1])){ goto a_G11;}
a_G10:a_1418(a_1001,2130706177); return;
a_G11:to_LIST(a_1285)->offset[a_L2-1]=a_F1; goto a_G1;
} /* skipfillinitializer */
static void a_1272(int a_F1){ /* rememberlist+>a */
int a_L2;int a_P[1];
a_1312(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return;}
a_1338(a_F1,a_1262);
a_1262=a_F1; return;
} /* rememberlist */
static void a_1263(void){ /* listentry */
int a_L1;int a_L2;int a_L3;
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706141); return;
a_G5:a_1248(a_L1);
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L2=a_1458;
a_1464();
{ if(a_L2==0||a_L2==1||a_L2==2){ goto a_G10;}
 if(a_L2==3||a_L2==4){ goto a_G13;}
  goto a_G17;}
a_G10:if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L3=a_1458;
a_1464(); goto a_G18;
a_G13:if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L3=a_1458;
a_1464();
a_1244(a_L3,1); goto a_G18;
a_G17:a_1418(a_1001,2130706170); return;
a_G18:a_1340(a_L1,a_L2);
a_1339(a_L1,a_L3);
a_1272(a_L1);
if(!a_equal(16777439,a_1457)){ goto a_G4;}

a_1464(); return;
} /* listentry */
static void a_1264(void){ /* loosebounds */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
a_L1=a_1262;
a_G2:if(a_equal(a_L1,-1)){ return;}
a_1318(a_L1,a_P);a_L2=a_P[0];
a_1317(a_L1,a_P);a_L3=a_P[0];
a_1339(a_L1,0);
{ if(a_L2==1){ goto a_G7;}
 if(a_L2==2){ goto a_G8;}
 if(a_L2==3){ goto a_G9;}
 if(a_L2==4){ goto a_G11;}
  goto a_G13;}
a_G7:a_1271(a_L3,a_L1); goto a_G14;
a_G8:a_1258(a_L3,a_L1); goto a_G14;
a_G9:a_1260(a_L3,a_L1,a_P);a_L4=a_P[0];
a_1271(a_L4,a_L1); goto a_G14;
a_G11:a_1260(a_L3,a_L1,a_P);a_L4=a_P[0];
a_1258(a_L4,a_L1); goto a_G14;
a_G13:a_1340(a_L1,0);
a_G14:a_1312(a_L1,a_P);a_L1=a_P[0]; goto a_G2;
} /* loosebounds */
static void a_1271(int a_F1,int a_F2){ /* relativesize+>a+>a */
int a_P[4];
if(a_less(a_F1,1)){ goto a_G3;}
if(!a_more(a_F1,100)){ goto a_G4;}
a_G3:a_P[0]=2047260248;a_P[1]=to_LIST(a_1285)->offset[a_F2-3];a_P[2]=a_F1;a_P[3]=a_F2;a_1439(4,a_P);
a_G4:a_min(100,a_F1);
a_max(1,a_F1);
a_subtr(0,a_F1,a_F1);
a_1340(a_F2,a_F1); return;
} /* relativesize */
static void a_1258(int a_F1,int a_F2){ /* fixsize+>a+>a */
int a_P[4];
if(a_less(a_F1,1)){ goto a_G3;}
if(!a_more(a_F1,100000)){ goto a_G4;}
a_G3:a_P[0]=2047260261;a_P[1]=to_LIST(a_1285)->offset[a_F2-3];a_P[2]=a_F1;a_P[3]=a_F2;a_1439(4,a_P);
a_G4:a_min(100000,a_F1);
a_max(1,a_F1);
a_1340(a_F2,a_F1); return;
} /* fixsize */
static int a_1259(int a_F1,int a_A[1]){ /* getconstvalue+>a+a> */
int a_P[1];
a_P[0]=a_F1;a_1261(a_P);a_F1=a_P[0];
if(!a_1323(a_F1,32)){ return 0;}
a_1014(to_LIST(a_1285)->offset[a_F1],a_P);a_A[0]=a_P[0]; return 1;
} /* getconstvalue */
static void a_1260(int a_F1,int a_F2,int a_A[1]){ /* getestimator+>a+>a+a> */
int a_P[4];
if(a_1259(a_F1,a_P)){a_A[0]=a_P[0]; return;}
a_A[0]=1;
a_P[0]=2047260273;a_P[1]=to_LIST(a_1285)->offset[a_F2-3];a_P[2]=to_LIST(a_1285)->offset[a_F1-3];a_P[3]=a_F2;a_1419(4,a_P); return;
} /* getestimator */
static void a_1252(void){ /* datasectionii */

if(a_1440()){ return;}
a_G2:if(!a_equal(16777254,a_1457)){ goto a_G5;}
a_1464();
a_1265(); goto a_G2;
a_G5:if(!a_equal(16777236,a_1457)){ goto a_G8;}
a_G6:a_1464();
a_1278(); goto a_G2;
a_G8:if(a_equal(16777266,a_1457)){ goto a_G6;}
if(a_equal(16777250,a_1457)){ goto a_G6;}
if(!a_equal(16777224,a_1457)){ goto a_G13;}
a_1464();
a_1270(0); goto a_G2;
a_G13:if(!a_equal(16777258,a_1457)){ goto a_G16;}
a_1464();
a_1270(1); goto a_G2;
a_G16:if(!a_equal(16777246,a_1457)){ goto a_G19;}
a_1464();
a_1255(); goto a_G2;
a_G19:if(a_equal(a_1457,16777285)){ return;}
a_1423(a_1001,2130706165); return;
} /* datasectionii */
static void a_1255(void){ /* externalentry */
int a_L1;int a_L2;
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706141); return;
a_G5:if(!a_equal(16777483,a_1457)){ goto a_G4;}
a_L2=a_1458;
a_1464();
if(!a_equal(16777439,a_1457)){ goto a_G4;}

a_1464();
if(a_1323(a_L1,16)){ goto a_G13;}
a_G12:a_1418(a_1001,2130706159); return;
a_G13:if(a_1323(a_L1,8)){ goto a_G12;}
{register int a_r1=to_LIST(a_1285)->offset[a_L1-5];
 if(a_r1==16777349||a_r1==16777304||a_r1==16777309){ goto a_G15;}
 if(a_r1==16777340||a_r1==16777345){ goto a_G16;}
 if(a_r1==16777318||a_r1==16777322){ goto a_G17;}
  goto a_G12;}
a_G15:to_LIST(a_1285)->offset[a_L1]=a_L2; return;
a_G16:to_LIST(a_1285)->offset[a_L1-1]=a_L2; return;
a_G17:a_1339(a_L1,a_L2); return;
} /* externalentry */
static void a_1270(int a_F1){ /* readmatter+>a */
int a_L2;
if(!a_equal(16777483,a_1457)){ goto a_G4;}
a_L2=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706141); return;
a_G5:if(!a_equal(16777439,a_1457)){ goto a_G4;}

a_1464();
a_1288(a_F1,a_L2); return;
} /* readmatter */
static void a_1265(void){ /* loosefill */
int a_L1;int a_L2;int a_L3;int a_P[1];
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706141); return;
a_G5:a_P[0]=a_L1;a_1261(a_P);a_L1=a_P[0];
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L2=a_1458;
a_1464();
a_G9:if(!a_equal(16777439,a_1457)){ goto a_G11;}
a_1464(); return;
a_G11:a_1266(a_P);a_L3=a_P[0];
a_add(a_L3,a_1257,a_1257);
a_1268(a_L1,a_L2,a_L3);
a_1267(a_L1); goto a_G9;
} /* loosefill */
static void a_1266(int a_A[1]){ /* loosefillitem+a> */

if(!a_equal(16777427,a_1457)){ goto a_G12;}
a_1464();
a_A[0]=0;
a_G4:if(!a_equal(16777406,a_1457)){ goto a_G6;}
a_1464(); return;
a_G6:if(!a_equal(16777459,a_1457)){ goto a_G9;}
a_G7:a_1464();
a_incr(a_A[0]); goto a_G4;
a_G9:if(!a_equal(16777471,a_1457)){ goto a_G11;}
 goto a_G7;
a_G11:a_1418(a_1001,2130706141); return;
a_G12:if(!a_equal(16777459,a_1457)){ goto a_G15;}
a_G13:a_1464();
a_A[0]=1; return;
a_G15:if(!a_equal(16777471,a_1457)){ goto a_G11;}
 goto a_G13;
} /* loosefillitem */
static void a_1273(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* repeatervalue+>a+>a+>a+a> */
int a_P[6];
if(!a_1259(a_F3,a_P)){ goto a_G6;}a_A[0]=a_P[0];
if(!a_lseq(1,a_A[0])){ goto a_G4;}
if(a_lseq(a_A[0],1000)){ return;}
a_G4:a_P[0]=2047260306;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_P[2]=a_F2;a_P[3]=a_A[0];a_P[4]=to_LIST(a_1285)->offset[a_F3-3];a_P[5]=1000;a_1419(6,a_P);
a_A[0]=1; return;
a_G6:a_A[0]=1;
a_P[0]=2047260287;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_P[2]=a_F2;a_P[3]=to_LIST(a_1285)->offset[a_F3-3];a_1419(4,a_P); return;
} /* repeatervalue */
static void a_1268(int a_F1,int a_F2,int a_F3){ /* looserepeater+>a+>a+>a */
int a_L4;int a_L5;int a_P[1];
if(!a_equal(16777445,a_1457)){ goto a_G15;}
a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G6;}
a_L5=a_1458;
a_1464(); goto a_G12;
a_G6:if(!a_equal(16777471,a_1457)){ goto a_G9;}
a_L4=a_1458;
a_1464(); goto a_G10;
a_G9:a_1418(a_1001,2130706141); return;
a_G10:a_P[0]=a_L4;a_1261(a_P);a_L4=a_P[0];
a_1273(a_F1,a_F2,a_L4,a_P);a_L5=a_P[0];
a_G12:if(a_equal(a_L5,1)){ goto a_G14;}
a_add(2,a_1257,a_1257);
a_G14:a_mult(a_F3,a_L5,a_F3);
a_G15:a_1310(a_F1,a_P);a_L5=a_P[0];
a_add(a_F3,a_L5,a_L5);
a_1337(a_F1,a_L5); return;
} /* looserepeater */
static void a_1267(int a_F1){ /* looseinitializer+>a */
int a_L2;int a_L3;int a_P[1];
a_G1:if(!a_equal(16777409,a_1457)){ return;}
a_1464();
if(!a_equal(16777471,a_1457)){ goto a_G6;}
a_L2=a_1458;
a_1464(); goto a_G7;
a_G6:a_1418(a_1001,2130706141); return;
a_G7:a_1310(a_F1,a_P);a_L3=a_P[0];
to_LIST(a_1285)->offset[a_L2]=a_L3; goto a_G1;
} /* looseinitializer */
static void a_1253(void){ /* datasectioniii */

a_G1:if(!a_equal(16777254,a_1457)){ goto a_G4;}
a_1464();
a_1144(); goto a_G1;
a_G4:if(!a_equal(16777236,a_1457)){ goto a_G7;}
a_G5:a_1464();
a_1278(); goto a_G1;
a_G7:if(a_equal(16777266,a_1457)){ goto a_G5;}
if(a_equal(16777250,a_1457)){ goto a_G5;}
if(a_equal(16777224,a_1457)){ goto a_G5;}
if(a_equal(16777258,a_1457)){ goto a_G5;}
if(a_equal(16777246,a_1457)){ goto a_G5;}
if(a_equal(a_1457,16777285)){ return;}
a_1418(a_1001,2130706153); return;
} /* datasectioniii */
static void a_1249(int a_A[2]){ /* collectlistsizeclaims+a>+a> */
int a_L3;int a_L4;int a_L5;int a_P[1];
a_A[0]=0;a_A[1]=0;
a_L3=a_1262;
a_G3:if(a_equal(a_L3,-1)){ return;}
a_1307(a_L3,a_P);a_L4=a_P[0];
a_add(a_L4,a_A[0],a_A[0]);
a_1310(a_L3,a_P);a_L4=a_P[0];
a_1318(a_L3,a_P);a_L5=a_P[0];
if(!a_mreq(a_L5,0)){ goto a_G11;}
a_max(a_L5,a_L4);
a_G10:a_add(a_L4,a_A[0],a_A[0]); goto a_G12;
a_G11:a_subtr(a_A[1],a_L5,a_A[1]); goto a_G10;
a_G12:a_1312(a_L3,a_P);a_L3=a_P[0]; goto a_G3;
} /* collectlistsizeclaims */
static void a_1274(void){ /* setlistbounds */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
a_L1=a_1262;
a_G2:if(a_equal(a_L1,-1)){ return;}
a_1307(a_L1,a_P);a_L2=a_P[0];
a_1310(a_L1,a_P);a_L3=a_P[0];
a_1318(a_L1,a_P);a_L4=a_P[0];
if(!a_mreq(a_L4,0)){ goto a_G9;}
a_max(a_L4,a_L3);
a_L4=0; goto a_G10;
a_G9:a_subtr(0,a_L4,a_L4);
a_G10:a_1234(a_L2,a_L3,a_L4,a_P);a_L5=a_P[0];a_L6=a_P[1];
a_1339(a_L1,a_L5);
a_1340(a_L1,a_L6);
a_1312(a_L1,a_P);a_L1=a_P[0]; goto a_G2;
} /* setlistbounds */
static void a_1254(void){ /* distributevirtualaddress */
int a_L1;int a_L2;int a_P[2];
a_1249(a_P);a_L1=a_P[0];a_L2=a_P[1];
if(a_more(a_L2,0)){ goto a_G4;}
a_L2=1;
a_G4:if(!a_1239(a_L1,a_L2)){ goto a_G8;}
a_1274();
a_1221();
a_1250(); return;
a_G8:a_P[0]=2047260315;a_1419(1,a_P); return;
} /* distributevirtualaddress */
static void a_1250(void){ /* computepointerconstants */
int a_L1;
a_L1=to_LIST(a_1285)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1285)->aupb)){ return;}
if(!a_equal(to_LIST(a_1285)->offset[a_L1-5],16777335)){ goto a_G5;}
a_1275(a_L1);
a_G5:a_next(a_1285,a_L1); goto a_G2;
} /* computepointerconstants */
static void a_1275(int a_F1){ /* setpointervalue+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_L2=to_LIST(a_1285)->offset[a_F1-1];
a_P[0]=a_L2;a_1261(a_P);a_L2=a_P[0];
a_1307(a_L2,a_P);a_L3=a_P[0];
a_1317(a_L2,a_P);a_L4=a_P[0];
a_subtr(to_LIST(a_1285)->offset[a_F1],a_L3,a_L3);
a_1241(a_L4,a_L3,a_P);to_LIST(a_1285)->offset[a_F1]=a_P[0];
a_1354(a_F1,32); return;
} /* setpointervalue */
static void a_1276(int a_F1){ /* setreprnumber+>a */
int a_L2;int a_P[1];
if(!a_1323(a_F1,16)){ goto a_G12;}
{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(a_r1==16777309||a_r1==16777304){ return;}
 if(a_r1==16777349){ goto a_G3;}
 if(a_r1==16777340||a_r1==16777345||a_r1==16777318||a_r1==16777322){ goto a_G9;}
  goto a_G11;}
a_G3:a_1456(to_LIST(a_1285)->offset[a_F1],a_P);a_L2=a_P[0];
if(!a_stringelem(a_1447,a_L2,0,a_P)){ goto a_G7;}a_L2=a_P[0];
if(!a_equal(a_L2,95)){ goto a_G7;}
a_1354(a_F1,4096); return;
a_G7:if(!a_equal(a_L2,64)){ return;}
a_1354(a_F1,8192); return;
a_G9:a_incr(a_1269);
to_LIST(a_1285)->offset[a_F1]=a_1269; return;
a_G11:a_1423(a_1001,2130706147); return;
a_G12:{register int a_r1=to_LIST(a_1285)->offset[a_F1-5];
 if(a_r1==16777304||a_r1==16777335){ return;}
 if(a_r1==16777309||a_r1==16777314){ goto a_G13;}
 if(a_r1==16777349||a_r1==16777318||a_r1==16777322||a_r1==16777328||a_r1==16777340||a_r1==16777345){ goto a_G9;}
  return;}
a_G13:to_LIST(a_1285)->offset[a_F1-1]=to_LIST(a_1285)->offset[a_F1]; goto a_G9;
} /* setreprnumber */
static void a_1243(void){ /* assignreprnumbers */
int a_L1;
a_L1=to_LIST(a_1285)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1285)->aupb)){ return;}
if(!a_1323(a_L1,8)){ goto a_G5;}
a_G4:a_next(a_1285,a_L1); goto a_G2;
a_G5:{register int a_r1=to_LIST(a_1285)->offset[a_L1-5];
 if(!(a_r1==16777304||a_r1==16777335||a_r1==16777309||a_r1==16777314||a_r1==16777349||a_r1==16777318||a_r1==16777322||a_r1==16777328||a_r1==16777340||a_r1==16777345)){ goto a_G4;}
}
a_1276(a_L1); goto a_G4;
} /* assignreprnumbers */
static void a_1300(void){ /* expandITEM */

{register int *a_r1=a_extension(a_1285,7);a_r1[0]=a_r1[1]=a_r1[2]=a_r1[3]=a_r1[4]=a_r1[5]=a_r1[6]=0;to_LIST(a_1285)->aupb+=7;}
  return;
} /* expandITEM */
static int a_1323(int a_F1,int a_F2){ /* isitemflag+>a+>a */
int a_L3;
a_booland(to_LIST(a_1285)->offset[a_F1-6],a_F2,a_L3);
if(!a_is(a_L3)){ return 0;} return 1;
} /* isitemflag */
static void a_1354(int a_F1,int a_F2){ /* setitemflag+>a+>a */

a_boolor(to_LIST(a_1285)->offset[a_F1-6],a_F2,to_LIST(a_1285)->offset[a_F1-6]); return;
} /* setitemflag */
static void a_1295(int a_F1,int a_F2){ /* clearitemflag+>a+>a */
int a_L3;
a_boolinvert(a_F2,a_L3);
a_booland(a_L3,to_LIST(a_1285)->offset[a_F1-6],to_LIST(a_1285)->offset[a_F1-6]); return;
} /* clearitemflag */
static void a_1297(int a_A[1]){ /* converttoitem+>a> */

a_addmult(a_A[0],7,a_1334,a_A[0]); return;
} /* converttoitem */
static void a_1336(int a_F1){ /* pushAUX+>a */

{register int *a_r1=a_extension(a_1284,1);a_r1[0]=a_F1;to_LIST(a_1284)->aupb+=1;}
  return;
} /* pushAUX */
static void a_1307(int a_F1,int a_A[1]){ /* getcalibre+>a+a> */

a_A[0]=to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]-2]; return;
} /* getcalibre */
static void a_1316(int a_F1,int a_A[1]){ /* getssel+>a+a> */

a_A[0]=to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]-1]; return;
} /* getssel */
static void a_1318(int a_F1,int a_A[1]){ /* getvupb+>a+a> */

a_A[0]=to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]-4]; return;
} /* getvupb */
static void a_1317(int a_F1,int a_A[1]){ /* getvlwb+>a+a> */

a_A[0]=to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]-5]; return;
} /* getvlwb */
static void a_1310(int a_F1,int a_A[1]){ /* getfill+>a+a> */

a_A[0]=to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]-3]; return;
} /* getfill */
static void a_1312(int a_F1,int a_A[1]){ /* getlistlink+>a+a> */

a_A[0]=to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]]; return;
} /* getlistlink */
static void a_1339(int a_F1,int a_F2){ /* putvlwb+>a+>a */

to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]-5]=a_F2; return;
} /* putvlwb */
static void a_1340(int a_F1,int a_F2){ /* putvupb+>a+>a */

to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]-4]=a_F2; return;
} /* putvupb */
static void a_1337(int a_F1,int a_F2){ /* putfill+>a+>a */

to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]-3]=a_F2; return;
} /* putfill */
static void a_1338(int a_F1,int a_F2){ /* putlistlink+>a+>a */

to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]]=a_F2; return;
} /* putlistlink */
static void a_1315(int a_F1,int a_A[1]){ /* getnumberofformals+>a+a> */

a_A[0]=to_LIST(a_1284)->offset[to_LIST(a_1285)->offset[a_F1-1]-2]; return;
} /* getnumberofformals */
static void a_1311(int a_F1,int a_F2,int a_A[1]){ /* getformal+>a+>a+a> */
int a_L4;
a_L4=to_LIST(a_1285)->offset[a_F1-1];
if(!a_mreq(a_F2,to_LIST(a_1284)->offset[a_L4-2])){ goto a_G4;}
a_A[0]=0; return;
a_G4:a_incr(a_L4);
a_add(a_F2,a_L4,a_L4);
a_A[0]=to_LIST(a_1284)->offset[a_L4]; return;
} /* getformal */
static void a_1306(int a_F1,int a_A[1]){ /* getanchorcount+>a+a> */
int a_L3;int a_L4;
a_A[0]=0;
a_L3=to_LIST(a_1285)->offset[a_F1-1];
a_L4=to_LIST(a_1284)->offset[a_L3-2];
a_G4:if(a_equal(a_L4,0)){ return;}
a_decr(a_L4);
a_incr(a_L3);
if(!a_equal(to_LIST(a_1284)->offset[a_L3],16777388)){ goto a_G4;}
a_A[0]=a_L4; return;
} /* getanchorcount */
static void a_1288(int a_F1,int a_F2){ /* addmatter+>a+>a */

{register int *a_r1=a_extension(a_1284,3);a_r1[0]=a_F1;a_r1[1]=a_F2;a_r1[2]=a_1332;to_LIST(a_1284)->aupb+=3;}
a_1332=to_LIST(a_1284)->aupb; return;
} /* addmatter */
static int a_1313(int a_F2,int a_A[2]){ /* getmatter+>a>+>a+a> */

if(!a_equal(a_A[0],0)){ goto a_G3;}
a_A[0]=a_1332; goto a_G4;
a_G3:a_A[0]=to_LIST(a_1284)->offset[a_A[0]];
a_G4:if(!a_was(a_1284,a_A[0])){ return 0;}
if(!a_equal(to_LIST(a_1284)->offset[a_A[0]-2],a_F2)){ goto a_G3;}
a_A[1]=to_LIST(a_1284)->offset[a_A[0]-1]; return 1;
} /* getmatter */
static int a_1296(int a_F1,int a_F2){ /* compareformals+>a+>a */
int a_L3;
if(!a_equal(to_LIST(a_1284)->offset[a_F1-2],to_LIST(a_1284)->offset[a_F2-2])){ return 0;}
a_L3=to_LIST(a_1284)->offset[a_F1-1];
if(!a_equal(to_LIST(a_1284)->offset[a_F2-1],a_L3)){ return 0;}
a_G4:if(a_equal(a_L3,0)){ return 1;}
a_incr(a_F1);
a_incr(a_F2);
if(!a_equal(to_LIST(a_1284)->offset[a_F1],to_LIST(a_1284)->offset[a_F2])){ return 0;}
a_decr(a_L3); goto a_G4;
} /* compareformals */
static void a_1353(int a_F1,int a_A[1]){ /* searchformals+>a+>a> */
int a_L3;
a_L3=a_1328;
a_G2:if(!a_equal(a_L3,0)){ goto a_G5;}
to_LIST(a_1284)->offset[a_A[0]]=a_1328;
a_1328=a_A[0]; return;
a_G5:if(!a_1296(a_L3,a_A[0])){ goto a_G8;}
a_unstackto(a_1284,a_F1);
a_A[0]=a_L3; return;
a_G8:a_L3=to_LIST(a_1284)->offset[a_L3]; goto a_G2;
} /* searchformals */
static void a_1305(int a_F1,int a_F2){ /* formalaffixes+>a+>a */
int a_L3;int a_L4;int a_L5;
a_G1:if(a_equal(a_F2,0)){ return;}
a_decr(a_F2);
if(!a_equal(16777463,a_1457)){ goto a_G6;}
a_L5=a_1458;
a_1464(); goto a_G7;
a_G6:a_1418(a_1001,2130706225); return;
a_G7:a_1336(a_L5);
{ if(a_L5==16777355||a_L5==16777361){ goto a_G9;}
 if(a_L5==16777371||a_L5==16777376||a_L5==16777382||a_L5==16777366||a_L5==16777388||a_L5==16777394){ goto a_G1;}
  goto a_G20;}
a_G9:if(!a_equal(16777455,a_1457)){ goto a_G6;}
a_L3=a_1458;
a_1464();
if(!a_equal(16777455,a_1457)){ goto a_G6;}
a_L4=a_1458;
a_1464();
a_1305(a_F1,a_F2);
a_incr(to_LIST(a_1284)->offset[a_F1-1]);
a_1336(a_L3);
a_incr(to_LIST(a_1284)->offset[a_F1-1]);
a_1336(a_L4); return;
a_G20:a_1418(a_1001,2130706258); return;
} /* formalaffixes */
static void a_1358(int a_A[1]){ /* storeformalaffixes+a> */
int a_L2;int a_L3;int a_P[1];
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L2=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706225); return;
a_G5:a_L3=to_LIST(a_1284)->aupb;
{register int *a_r1=a_extension(a_1284,3);a_r1[0]=a_r1[1]=a_L2;a_r1[2]=0;to_LIST(a_1284)->aupb+=3;}
a_A[0]=to_LIST(a_1284)->aupb;
a_1305(a_A[0],a_L2);
a_P[0]=a_A[0];a_1353(a_L3,a_P);a_A[0]=a_P[0]; return;
} /* storeformalaffixes */
static void a_1359(int a_A[1]){ /* storelistbounds+a> */
int a_L2;int a_L3;
if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L2=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706225); return;
a_G5:if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L3=a_1458;
a_1464();
{register int *a_r1=a_extension(a_1284,6);a_r1[0]=a_r1[1]=a_r1[2]=0;a_r1[3]=a_L2;a_r1[4]=a_L3;a_r1[5]=0;to_LIST(a_1284)->aupb+=6;}
a_A[0]=to_LIST(a_1284)->aupb; return;
} /* storelistbounds */
static void a_1292(int a_F1){ /* checkitemID+>a */

if(a_equal(a_F1,to_LIST(a_1285)->aupb)){ return;}
a_1418(a_1001,2130706252); return;
} /* checkitemID */
static void a_1299(void){ /* enteritem */
int a_L1;int a_P[1];
if(!a_1323(to_LIST(a_1285)->aupb,4)){ return;}
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb]=a_1334;
{register int *a_r1=a_extension(a_1284,3);a_r1[0]=to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-4];a_r1[1]=to_LIST(a_1285)->aupb;a_r1[2]=0;to_LIST(a_1284)->aupb+=3;}
a_1455(to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-3],a_P);a_L1=a_P[0];
a_G5:if(!a_equal(a_L1,0)){ goto a_G7;}
a_1465(to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-3],to_LIST(a_1284)->aupb); return;
a_G7:if(!a_equal(to_LIST(a_1284)->offset[a_L1],0)){ goto a_G9;}
to_LIST(a_1284)->offset[a_L1]=to_LIST(a_1284)->aupb; return;
a_G9:a_L1=to_LIST(a_1284)->offset[a_L1]; goto a_G5;
} /* enteritem */
static void a_1343(void){ /* readitem */
int a_L1;int a_L2;int a_L3;int a_P[1];
a_1300();
if(!a_equal(16777463,a_1457)){ goto a_G5;}
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-5]=a_1458;
a_1464(); goto a_G6;
a_G5:a_1418(a_1001,2130706225); return;
a_G6:if(!a_equal(16777471,a_1457)){ goto a_G5;}
a_L1=a_1458;
a_1464();
a_1292(a_L1);
if(!a_equal(16777455,a_1457)){ goto a_G5;}
a_L2=a_1458;
a_1464();
a_booland(a_L2,117557020,to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-6]);
if(!a_equal(16777455,a_1457)){ goto a_G5;}
a_L3=a_1458;
a_1464();
if(a_lseq(a_L3,0)){ goto a_G21;}
if(!a_more(a_L3,a_1333)){ goto a_G20;}
a_G19:a_1418(a_1001,2130706247); return;
a_G20:to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-2]=a_L3;
a_G21:{register int a_r1=to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-5];
 if(a_r1==16777349){ goto a_G22;}
 if(a_r1==16777322||a_r1==16777318||a_r1==16777328){ goto a_G23;}
 if(a_r1==16777304||a_r1==16777309||a_r1==16777314||a_r1==16777335||a_r1==16777340||a_r1==16777345){ goto a_G24;}
  goto a_G19;}
a_G22:a_1358(a_P);to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-1]=a_P[0]; goto a_G24;
a_G23:a_1359(a_P);to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-1]=a_P[0];
a_G24:if(!a_equal(16777483,a_1457)){ goto a_G5;}
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-4]=a_1458;
a_1464();
if(!a_equal(16777483,a_1457)){ goto a_G5;}
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-3]=a_1458;
a_1464();
a_1299(); return;
} /* readitem */
static void a_1326(void){ /* itemsection */

if(a_1440()){ return;}
a_G2:if(!a_equal(16777439,a_1457)){ goto a_G4;}
a_1464(); return;
a_G4:a_1343(); goto a_G2;
} /* itemsection */
static void a_1356(void){ /* skipitemsection */

a_G1:if(!a_equal(16777439,a_1457)){ goto a_G3;}
a_G2:a_1464(); return;
a_G3:if(a_equal(16777486,a_1457)){ goto a_G2;}
a_1464(); goto a_G1;
} /* skipitemsection */
static void a_1290(void){ /* addstdstring */

a_1319(0);
a_1300();
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-5]=16777318;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-6]=4;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-4]=183666559;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-3]=183666469;
{register int *a_r1=a_extension(a_1284,6);a_r1[0]=a_r1[1]=a_r1[2]=0;a_r1[3]=a_r1[4]=1;a_r1[5]=0;to_LIST(a_1284)->aupb+=6;}
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-1]=to_LIST(a_1284)->aupb;
a_1299(); return;
} /* addstdstring */
static void a_1289(void){ /* addshiftaffixrules */
int a_P[3];
a_1319(0);
a_1300();
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-6]=33284;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-5]=16777349;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-4]=183666559;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-3]=183666477;
a_P[1]=16777394;a_1287(1,a_P,1,a_P+1);to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-1]=a_P[0];
a_1299();
a_1300();
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-6]=32772;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-5]=16777349;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-4]=183666559;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-3]=183666485;
a_P[1]=16777376;a_P[2]=16777394;a_1287(2,a_P,2,a_P+1);to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-1]=a_P[0];
a_1299(); return;
} /* addshiftaffixrules */
static void a_1287(int a_F2,int a_A[1],int a_C,int *a_V){ /* addformalaffixes+a>+>a+@+>a */
int a_L4;int a_P[1];
a_L4=to_LIST(a_1284)->aupb;
{register int *a_r1=a_extension(a_1284,3);a_r1[0]=a_F2;a_r1[1]=a_r1[2]=0;to_LIST(a_1284)->aupb+=3;}
a_A[0]=to_LIST(a_1284)->aupb;
if(a_equal(a_F2,0)){ goto a_G8;}
a_G5:a_1336(a_V[0]);
a_incr(to_LIST(a_1284)->offset[a_A[0]-1]);
if(a_C>1){a_C--;a_V+=1; goto a_G5;} 
a_G8:a_P[0]=a_A[0];a_1353(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* addformalaffixes */
static void a_1286(void){ /* addbuiltinformals */
int a_P[5];
a_P[1]=16777361;a_P[2]=16777371;a_P[3]=1;a_P[4]=1;a_1287(2,a_P,4,a_P+1);a_1361=a_P[0];
a_P[1]=16777371;a_P[2]=16777388;a_P[3]=16777376;a_1287(3,a_P,3,a_P+1);a_1331=a_P[0];
a_P[1]=0;a_1287(0,a_P,1,a_P+1);a_1346=a_P[0]; return;
} /* addbuiltinformals */
static int a_1325(int a_F1){ /* iswaitforitem+>a */

if(!a_equal(to_LIST(a_1285)->offset[a_F1],183666492)){ return 0;}
if(!a_equal(to_LIST(a_1285)->offset[a_F1-5],16777349)){ return 0;}
if(!a_equal(to_LIST(a_1285)->offset[a_F1-1],a_1361)){ return 0;} return 1;
} /* iswaitforitem */
static int a_1321(int a_F1){ /* isassignitem+>a */

if(!a_equal(to_LIST(a_1285)->offset[a_F1],183666498)){ return 0;}
if(!a_1323(a_F1,16)){ return 0;}
if(!a_equal(to_LIST(a_1285)->offset[a_F1-5],16777349)){ return 0;}
if(!a_equal(to_LIST(a_1285)->offset[a_F1-1],a_1331)){ return 0;} return 1;
} /* isassignitem */
static int a_1324(int a_F1){ /* isrootitem+>a */

if(!a_equal(to_LIST(a_1285)->offset[a_F1-3],183666504)){ return 0;}
if(!a_equal(to_LIST(a_1285)->offset[a_F1-5],16777349)){ return 0;}
if(!a_equal(to_LIST(a_1285)->offset[a_F1-1],a_1346)){ return 0;}
if(!a_1323(a_F1,16)){ return 1;} return 0;
} /* isrootitem */
static int a_1322(int a_F1,int a_A[1]){ /* isbuiltinrule+>a+a> */

{register int a_r1=to_LIST(a_1285)->offset[a_F1-3];
 if(a_r1==183666477){ goto a_G2;}
 if(a_r1==183666485){ goto a_G3;}
  return 0;}
a_G2:a_A[0]=1; return 1;
a_G3:a_A[0]=2; return 1;
} /* isbuiltinrule */
static void a_1342(int a_F1){ /* readfileinfo+>a */
int a_L2;int a_L3;int a_L4;
if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L3=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706225); return;
a_G5:if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L4=a_1458;
a_1464();
{register int *a_r1=a_extension(a_1284,3);a_r1[0]=0;a_r1[1]=a_L3;a_r1[2]=a_L4;to_LIST(a_1284)->aupb+=3;}
{register int a_r1=to_LIST(a_1284)->aupb;a_L2=a_r1;to_LIST(a_1285)->offset[a_F1-1]=a_r1;}
if(!a_equal(16777448,a_1457)){ return;}
a_1464();
a_G12:if(!a_equal(16777403,a_1457)){ goto a_G14;}
a_1464(); return;
a_G14:if(!a_equal(16777471,a_1457)){ goto a_G4;}
a_L3=a_1458;
a_1464();
a_1336(a_L3);
a_incr(to_LIST(a_1284)->offset[a_L2-2]); goto a_G12;
} /* readfileinfo */
static void a_1309(int a_F1,int a_A[2]){ /* getfiledata+>a+a>+a> */
int a_L4;
a_L4=to_LIST(a_1285)->offset[a_F1-1];
a_A[0]=to_LIST(a_1284)->offset[a_L4-1];
a_A[1]=to_LIST(a_1284)->offset[a_L4]; return;
} /* getfiledata */
static void a_1308(int a_F1,int a_F2,int a_A[1]){ /* getfilearea+>a+>a+a> */
int a_L4;
a_L4=to_LIST(a_1285)->offset[a_F1-1];
if(!a_more(a_F2,to_LIST(a_1284)->offset[a_L4-2])){ goto a_G4;}
a_A[0]=0; return;
a_G4:a_add(a_L4,a_F2,a_L4);
a_A[0]=to_LIST(a_1284)->offset[a_L4]; return;
} /* getfilearea */
static void a_1293(void){ /* checkmainmodule */
int a_P[2];
if(!a_is(a_1330)){ goto a_G3;}
a_P[0]=2047260325;a_P[1]=to_LIST(a_1285)->offset[a_1330-5];a_1419(2,a_P); return;
a_G3:a_1330=to_LIST(a_1285)->aupb; return;
} /* checkmainmodule */
static void a_1341(void){ /* readdefinitionlist */
int a_L1;int a_L2;int a_L3;
a_G1:if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L1=a_1458;
a_1464(); goto a_G5;
a_G4:a_1418(a_1001,2130706225); return;
a_G5:if(!a_equal(16777455,a_1457)){ goto a_G4;}
a_L2=a_1458;
a_1464();
if(!a_mreq(a_L2,a_1333)){ goto a_G10;}
a_1333=a_L2; goto a_G11;
a_G10:a_1418(a_1001,2130706242); return;
a_G11:if(!a_equal(16777483,a_1457)){ goto a_G4;}
a_L3=a_1458;
a_1464();
{register int *a_r1=a_extension(a_1284,3);a_r1[0]=a_L1;a_r1[1]=a_L2;a_r1[2]=a_L3;to_LIST(a_1284)->aupb+=3;}
if(!a_equal(to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-1],0)){ goto a_G17;}
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-1]=to_LIST(a_1284)->aupb;
a_G17:if(!a_equal(16777439,a_1457)){ goto a_G1;}
a_1464(); return;
} /* readdefinitionlist */
static void a_1329(void){ /* linkmoduleheader */

if(!a_equal(a_1334,0)){ goto a_G3;}
a_1304=to_LIST(a_1285)->aupb; goto a_G4;
a_G3:to_LIST(a_1285)->offset[a_1334]=to_LIST(a_1285)->aupb;
a_G4:a_1334=to_LIST(a_1285)->aupb; return;
} /* linkmoduleheader */
static void a_1319(int a_F1){ /* headsection+>a */
int a_L2;int a_P[1];
if(!a_equal(a_F1,0)){ goto a_G5;}
a_1300();
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-6]=3;
a_1329(); return;
a_G5:a_1300();
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-5]=a_F1;
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-6]=1;
if(!a_equal(16777277,a_1457)){ goto a_G18;}
a_1464();
a_1354(to_LIST(a_1285)->aupb,2);
if(!a_equal(16777483,a_1457)){ goto a_G14;}
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-3]=a_1458;
a_1464(); goto a_G15;
a_G14:a_1418(a_1001,2130706225); return;
a_G15:if(!a_equal(16777483,a_1457)){ goto a_G14;}
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-4]=a_1458;
a_1464(); goto a_G26;
a_G18:if(!a_equal(16777273,a_1457)){ goto a_G25;}
a_1464();
a_1354(to_LIST(a_1285)->aupb,4);
if(!a_equal(16777483,a_1457)){ goto a_G14;}
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-4]=a_1458;
a_1464();
a_1293(); goto a_G26;
a_G25:a_1418(a_1001,2130706235); return;
a_G26:a_1329();
if(!a_equal(16777455,a_1457)){ goto a_G14;}
a_L2=a_1458;
a_1464();
if(a_equal(a_L2,32)){ goto a_G32;}
a_P[0]=2047260337;a_1419(1,a_P);
a_G32:a_1333=0;
a_1341();
to_LIST(a_1285)->offset[to_LIST(a_1285)->aupb-2]=a_1333; return;
} /* headsection */
static void a_1355(void){ /* skipheadsection */

a_G1:if(!a_equal(16777439,a_1457)){ goto a_G3;}
a_1464(); return;
a_G3:a_1464(); goto a_G1;
} /* skipheadsection */
static void a_1352(int a_F1,int a_F2,int a_A[2]){ /* searchforline+>a+>a+a>+a> */

if(a_lseq(a_F2,1)){ goto a_G4;}
if(a_more(a_F2,to_LIST(a_1285)->offset[a_F1-2])){ goto a_G4;}
if(!a_equal(to_LIST(a_1285)->offset[a_F1-1],0)){ goto a_G6;}
a_G4:a_A[0]=0;
a_A[1]=183666559; return;
a_G6:a_F1=to_LIST(a_1285)->offset[a_F1-1];
a_G7:if(!a_lseq(a_F2,to_LIST(a_1284)->offset[a_F1-1])){ goto a_G11;}
a_subtr(a_F2,to_LIST(a_1284)->offset[a_F1-2],a_A[0]);
a_incr(a_A[0]);
a_A[1]=to_LIST(a_1284)->offset[a_F1]; return;
a_G11:a_add(a_F1,3,a_F1); goto a_G7;
} /* searchforline */
static void a_1303(int a_F1,int a_A[2]){ /* findlineno+>a+a>+a> */
int a_P[2];
if(!a_equal(a_1334,0)){ goto a_G4;}
a_A[0]=a_F1;
a_A[1]=183666559; return;
a_G4:a_1352(a_1334,a_F1,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1]; return;
} /* findlineno */
static void a_1302(int a_F1,int a_A[3]){ /* finditemlineno+>a+a>+a>+a> */
int a_L5;int a_L6;int a_P[2];
a_L5=a_1304;
a_G2:a_L6=to_LIST(a_1285)->offset[a_L5];
if(!a_is(a_L6)){ goto a_G6;}
if(!a_less(a_L6,a_F1)){ goto a_G6;}
a_L5=a_L6; goto a_G2;
a_G6:a_A[2]=to_LIST(a_1285)->offset[a_L5-3];
a_1352(a_L5,to_LIST(a_1285)->offset[a_F1-2],a_P);a_A[0]=a_P[0];a_A[1]=a_P[1]; return;
} /* finditemlineno */
static int a_1357(int a_F1,int a_F2){ /* stacksizemismatch+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_1316(a_F1,a_P);a_L3=a_P[0];
a_1316(a_F2,a_P);a_L4=a_P[0];
if(a_noteq(a_L3,a_L4)){ return 1;}
a_1307(a_F1,a_P);a_L3=a_P[0];
a_1307(a_F2,a_P);a_L4=a_P[0];
if(!a_noteq(a_L3,a_L4)){ return 0;} return 1;
} /* stacksizemismatch */
static int a_1360(int a_F1,int a_F2){ /* unequaltypes+>a+>a */

if(a_equal(a_F1,a_F2)){ return 0;}
if(!a_equal(a_F1,16777335)){ return 1;}
if(!a_equal(a_F2,16777304)){ return 1;} return 0;
} /* unequaltypes */
static int a_1320(int a_F1,int a_F2){ /* incompatibletypes+>a+>a */
int a_L3;
a_L3=to_LIST(a_1285)->offset[a_F1-5];
if(a_1360(a_L3,to_LIST(a_1285)->offset[a_F2-5])){ return 1;}
if(!a_equal(a_L3,16777349)){ goto a_G5;}
if(!a_noteq(to_LIST(a_1285)->offset[a_F1-1],to_LIST(a_1285)->offset[a_F2-1])){ return 0;} return 1;
a_G5:if(a_equal(a_L3,16777322)){ goto a_G8;}
if(a_equal(a_L3,16777318)){ goto a_G8;}
if(!a_equal(a_L3,16777328)){ return 0;}
a_G8:if(!a_1357(a_F1,a_F2)){ return 0;} return 1;
} /* incompatibletypes */
static void a_1301(int a_F1,int a_A[1]){ /* finditemdef+>a+a> */
int a_L3;int a_L4;int a_P[1];
a_L3=to_LIST(a_1285)->offset[a_F1-4];
a_1455(to_LIST(a_1285)->offset[a_F1-3],a_P);a_L4=a_P[0];
a_G3:if(!a_equal(a_L4,0)){ goto a_G5;}
a_A[0]=0; return;
a_G5:if(!a_noteq(to_LIST(a_1284)->offset[a_L4-2],a_L3)){ goto a_G7;}
a_G6:a_L4=to_LIST(a_1284)->offset[a_L4]; goto a_G3;
a_G7:a_A[0]=to_LIST(a_1284)->offset[a_L4-1];
if(!a_1323(a_A[0],4)){ goto a_G6;}
to_LIST(a_1285)->offset[a_F1]=a_A[0]; return;
} /* finditemdef */
static void a_1349(int a_F1){ /* scanitem+>a */
int a_L2;int a_P[4];
if(!a_1323(a_F1,8)){ return;}
a_1301(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ goto a_G5;}
a_P[0]=2047260351;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_P[2]=a_F1;a_1419(3,a_P); return;
a_G5:if(!a_1320(a_L2,a_F1)){ goto a_G7;}
a_P[0]=2047260362;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_P[2]=a_L2;a_P[3]=a_F1;a_1419(4,a_P); return;
a_G7:if(!a_was(a_1285,to_LIST(a_1285)->offset[a_L2])){ goto a_G10;}
a_1354(a_L2,128);
a_1354(to_LIST(a_1285)->offset[a_L2],4); return;
a_G10:a_1423(a_1001,2130706230); return;
} /* scanitem */
static void a_1347(int a_A[1]){ /* scanfordefinitions+>a> */
int a_L2;int a_L3;int a_P[1];
a_G1:a_1291(a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ return;}
if(!a_1323(a_1334,4)){ goto a_G1;}
if(a_1323(a_1334,8)){ goto a_G1;}
a_1354(a_1334,8);
a_A[0]=1;
a_L2=a_1334;
a_G8:a_next(a_1285,a_L2);
if(a_1323(a_L2,1)){ goto a_G1;}
a_1349(a_L2); goto a_G8;
} /* scanfordefinitions */
static void a_1350(int a_F1){ /* scanitemfordbledef+>a */
int a_L2;int a_L3;int a_L4;int a_P[4];
a_L2=to_LIST(a_1285)->offset[a_F1-4];
a_1455(to_LIST(a_1285)->offset[a_F1-3],a_P);a_L3=a_P[0];
a_G3:if(a_equal(a_L3,0)){ return;}
if(!a_noteq(to_LIST(a_1284)->offset[a_L3-2],a_L2)){ goto a_G6;}
a_G5:a_L3=to_LIST(a_1284)->offset[a_L3]; goto a_G3;
a_G6:a_L4=to_LIST(a_1284)->offset[a_L3-1];
if(a_equal(a_L4,to_LIST(a_1285)->offset[a_F1])){ goto a_G5;}
if(!a_1323(a_L4,4)){ goto a_G5;}
if(!a_1323(to_LIST(a_1285)->offset[a_L4],4)){ goto a_G5;}
a_P[0]=2047260372;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_P[2]=to_LIST(a_1285)->offset[a_F1];a_P[3]=a_L4;a_1419(4,a_P); return;
} /* scanitemfordbledef */
static void a_1348(void){ /* scanfordoubledefinitions */
int a_L1;int a_L2;int a_P[1];
a_G1:a_1291(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(!a_1323(a_1334,4)){ goto a_G1;}
a_L1=a_1334;
a_G5:a_next(a_1285,a_L1);
if(a_1323(a_L1,1)){ goto a_G1;}
if(!a_1323(a_L1,8)){ goto a_G5;}
a_1350(a_L1); goto a_G5;
} /* scanfordoubledefinitions */
static void a_1294(void){ /* cleanupitems */
int a_L1;int a_L2;int a_P[1];
a_G1:a_1291(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(a_1323(a_1334,4)){ goto a_G1;}
a_L1=a_1334;
a_G5:a_next(a_1285,a_L1);
if(a_1323(a_L1,1)){ goto a_G1;}
to_LIST(a_1285)->offset[a_L1-5]=0; goto a_G5;
} /* cleanupitems */
static void a_1351(void){ /* scanlinkedmodules */
int a_L1;int a_P[1];
if(!a_equal(a_1330,0)){ goto a_G3;}
a_P[0]=2047260343;a_1419(1,a_P); return;
a_G3:a_1319(0);
a_1327=a_1334;
a_G5:a_L1=0;
a_P[0]=a_L1;a_1347(a_P);a_L1=a_P[0];
if(a_is(a_L1)){ goto a_G5;}
if(a_1440()){ goto a_G10;}
a_1348();
a_G10:if(a_1440()){ return;}
a_1294(); return;
} /* scanlinkedmodules */
static void a_1344(int a_F1){ /* reportitem+>a */
int a_P[3];
if(a_1323(a_F1,128)){ return;}
if(a_1322(a_F1,a_P)){ return;}
if(!a_1323(a_F1,4)){ return;}
a_P[0]=2047260380;a_P[1]=to_LIST(a_1285)->offset[a_F1-3];a_P[2]=a_F1;a_1439(3,a_P); return;
} /* reportitem */
static void a_1345(void){ /* reportnotusedpublicitems */
int a_L1;int a_L2;int a_P[1];
a_G1:if(!a_equal(a_1298,0)){ goto a_G3;}
a_incr(a_1298); return;
a_G3:a_1291(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(!a_1323(a_1334,4)){ goto a_G1;}
a_1408(to_LIST(a_1285)->offset[a_1334-5]);
if(!a_1400()){ goto a_G1;}
a_L1=a_1334;
a_G9:a_next(a_1285,a_L1);
if(a_1323(a_L1,1)){ goto a_G1;}
a_1344(a_L1); goto a_G9;
} /* reportnotusedpublicitems */
static void a_1291(int a_A[1]){ /* advancemodbase+a> */

if(!a_equal(a_1334,a_1327)){ goto a_G3;}
a_1334=a_1304; goto a_G4;
a_G3:a_1334=to_LIST(a_1285)->offset[a_1334];
a_G4:if(!a_equal(a_1334,a_1327)){ goto a_G6;}
a_A[0]=0; return;
a_G6:a_1333=to_LIST(a_1285)->offset[a_1334-2];
a_A[0]=1; return;
} /* advancemodbase */
static void a_1335(int a_A[1]){ /* opennextmodule+a> */
int a_L2;int a_P[1];
a_G1:a_1291(a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
if(!a_1323(a_1334,4)){ goto a_G1;}
a_L2=to_LIST(a_1285)->offset[a_1334-5];
a_1405(a_L2);
if(!a_equal(a_L2,0)){ goto a_G8;}
a_A[0]=2; return;
a_G8:a_A[0]=1; return;
} /* opennextmodule */
static void a_1314(int a_A[1]){ /* getnextmodulehead+a> */
int a_P[1];
a_G1:a_1291(a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
if(!a_1323(a_1334,4)){ goto a_G1;}
a_A[0]=a_1334; return;
} /* getnextmodulehead */
static void a_1283(void){ /* @root */

a_1290();
a_1289();
a_1286(); return;
} /* @root */
static void a_1368(int a_A[1]){ /* getregister+a> */
int a_L2;
{register int *a_r1=a_extension(a_1363,1);a_r1[0]=0;to_LIST(a_1363)->aupb+=1;}
a_A[0]=to_LIST(a_1363)->aupb;
a_L2=a_1376;
a_G4:if(a_equal(a_L2,1)){ return;}
{register int *a_r1=a_extension(a_1363,1);a_r1[0]=0;to_LIST(a_1363)->aupb+=1;}
a_decr(a_L2); goto a_G4;
} /* getregister */
static void a_1365(int a_F1){ /* freeregister+>a */
int a_L2;
a_add(a_F1,a_1376,a_L2);
a_decr(a_L2);
if(a_noteq(a_L2,to_LIST(a_1363)->aupb)){ return;}
a_G4:if(!a_equal(a_F1,to_LIST(a_1363)->aupb)){ goto a_G6;}
a_unstack(a_1363); return;
a_G6:a_unstack(a_1363); goto a_G4;
} /* freeregister */
static void a_1370(int a_A[1]){ /* markregisters+a> */

a_A[0]=to_LIST(a_1363)->aupb; return;
} /* markregisters */
static void a_1366(int a_F1){ /* freeregistersfrommark+>a */

a_unstackto(a_1363,a_F1); return;
} /* freeregistersfrommark */
static void a_1364(int a_F1,int a_A[1]){ /* duplregister+>a+a> */
int a_L3;int a_L4;int a_P[1];
a_1368(a_P);a_A[0]=a_P[0];
a_L3=a_A[0];
a_L4=a_1376;
a_G4:if(!a_lseq(a_L4,1)){ goto a_G6;}
to_LIST(a_1363)->offset[a_L3]=to_LIST(a_1363)->offset[a_F1]; return;
a_G6:to_LIST(a_1363)->offset[a_L3]=to_LIST(a_1363)->offset[a_F1];
a_decr(a_L4);
a_incr(a_F1);
a_incr(a_L3); goto a_G4;
} /* duplregister */
static void a_1372(int a_F1,int a_F2,int a_A[1]){ /* readregister+t[]+>a+a> */
int a_L3;int a_L4;int a_P[1];
a_1368(a_P);a_A[0]=a_P[0];
a_L3=a_A[0];
a_L4=a_1376;
a_subtr(a_F2,a_1376,a_F2);
a_incr(a_F2);
a_G6:if(!a_lseq(a_L4,1)){ goto a_G8;}
to_LIST(a_1363)->offset[a_L3]=to_LIST(a_F1)->offset[a_F2]; return;
a_G8:to_LIST(a_1363)->offset[a_L3]=to_LIST(a_F1)->offset[a_F2];
a_decr(a_L4);
a_incr(a_F2);
a_incr(a_L3); goto a_G6;
} /* readregister */
static void a_1377(int a_F1,int a_F2){ /* writeregister+>a+[]st[] */
int a_L2;int a_L3;
a_L2=a_1376;
a_L3=a_F1;
a_G3:if(a_less(a_L2,1)){ goto a_G7;}
{register int *a_r1=a_extension(a_F2,1);a_r1[0]=to_LIST(a_1363)->offset[a_L3];to_LIST(a_F2)->aupb+=1;}
a_decr(a_L2);
a_incr(a_L3); goto a_G3;
a_G7:a_1365(a_F1); return;
} /* writeregister */
static int a_1369(int a_F1){ /* istargetconst+>a */

if(!a_equal(a_F1,a_F1)){ return 0;} return 1;
} /* istargetconst */
static void a_1371(int a_F1,int a_A[1]){ /* putcstregister+>a+a> */
int a_P[1];
a_1368(a_P);a_A[0]=a_P[0];
to_LIST(a_1363)->offset[a_A[0]]=a_F1; return;
} /* putcstregister */
static void a_1367(int a_F1,int a_A[1]){ /* getcstregister+>a+a> */

a_A[0]=to_LIST(a_1363)->offset[a_F1];
a_1365(a_F1); return;
} /* getcstregister */
static void a_1375(int a_F1,int a_F2,int a_F3){ /* regoperator+>a+>a+>a */

{ if(a_F1==1){ goto a_G2;}
 if(a_F1==2){ goto a_G4;}
 if(a_F1==3){ goto a_G5;}
 if(a_F1==6){ goto a_G6;}
 if(a_F1==7){ goto a_G7;}
 if(a_F1==8){ goto a_G8;}
 if(a_F1==9){ goto a_G9;}
 if(a_F1==4){ goto a_G10;}
 if(a_F1==5){ goto a_G11;}
  return;}
a_G2:a_boolxor(to_LIST(a_1363)->offset[a_F3],to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3]);
a_G3:a_1365(a_F2); return;
a_G4:a_booland(to_LIST(a_1363)->offset[a_F3],to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3]); goto a_G3;
a_G5:a_boolor(to_LIST(a_1363)->offset[a_F3],to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3]); goto a_G3;
a_G6:a_add(to_LIST(a_1363)->offset[a_F3],to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3]); goto a_G3;
a_G7:a_subtr(to_LIST(a_1363)->offset[a_F3],to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3]); goto a_G3;
a_G8:a_mult(to_LIST(a_1363)->offset[a_F3],to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3]); goto a_G3;
a_G9:a_div(to_LIST(a_1363)->offset[a_F3],to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3]); goto a_G3;
a_G10:a_boolinvert(to_LIST(a_1363)->offset[a_F3],to_LIST(a_1363)->offset[a_F3]); return;
a_G11:a_subtr(0,to_LIST(a_1363)->offset[a_F3],to_LIST(a_1363)->offset[a_F3]); return;
} /* regoperator */
static int a_1373(int a_F1,int a_F2){ /* regcompare+>a+>a */

{ if(a_F1==10){ goto a_G2;}
 if(a_F1==11){ goto a_G3;}
 if(!(a_F1==12)){a_area_failed("regcompare",a_F1);}
 goto a_G4;}
a_G2:if(!a_equal(to_LIST(a_1363)->offset[a_F2],0)){ return 0;} return 1;
a_G3:if(!a_less(to_LIST(a_1363)->offset[a_F2],0)){ return 0;} return 1;
a_G4:if(!a_more(to_LIST(a_1363)->offset[a_F2],0)){ return 0;} return 1;
} /* regcompare */
static int a_1374(int a_F1,int a_F2,int a_F3){ /* regcompare2+>a+>a+>a */
int a_L4;
{ if(a_F1==20){ goto a_G2;}
 if(a_F1==21){ goto a_G5;}
 if(a_F1==22){ goto a_G6;}
 if(!(a_F1==23)){a_area_failed("regcompare2",a_F1);}
 goto a_G7;}
a_G2:a_L4=to_LIST(a_1363)->offset[a_F2];
a_incr(a_L4);
if(!a_equal(a_L4,to_LIST(a_1363)->offset[a_F3])){ return 0;} return 1;
a_G5:if(!a_less(to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3])){ return 0;} return 1;
a_G6:if(!a_lseq(to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3])){ return 0;} return 1;
a_G7:if(!a_equal(to_LIST(a_1363)->offset[a_F2],to_LIST(a_1363)->offset[a_F3])){ return 0;} return 1;
} /* regcompare2 */
static void a_1362(void){ /* @root */
int a_L1;
a_1376=1;
a_L1=32;
a_G3:if(a_mreq(a_L1,32)){ goto a_G6;}
a_add(a_L1,32,a_L1);
a_incr(a_1376); goto a_G3;
a_G6:a_waitfor(a_1001,2130706267);if(!a_equal(32,32)){ goto a_G9;}
if(a_equal(32,32)){ return;}
a_G9:a_1423(a_1001,2130706263); return;
} /* @root */
static int a_1395(int a_F1,int a_F2){ /* isfileflag+>a+>a */
int a_L3;
a_booland(to_LIST(a_1380)->offset[a_F1-2],a_F2,a_L3);
if(!a_is(a_L3)){ return 0;} return 1;
} /* isfileflag */
static void a_1407(int a_F1,int a_F2){ /* setfileflag+>a+>a */

a_boolor(to_LIST(a_1380)->offset[a_F1-2],a_F2,to_LIST(a_1380)->offset[a_F1-2]); return;
} /* setfileflag */
static void a_1388(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1443,1);a_r1[0]=a_F1;to_LIST(a_1443)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1389(int a_F1){ /* extendFILES+>a */
int a_P[2];
a_incr(a_1390);
if(!a_less(a_1390,200)){ goto a_G4;}
{register int *a_r1=a_extension(a_1380,3);a_r1[0]=a_r1[1]=0;a_r1[2]=a_F1;to_LIST(a_1380)->aupb+=3;}
  return;
a_G4:a_P[0]=2047260605;a_P[1]=200;a_1421(2,a_P); return;
} /* extendFILES */
static int a_1396(int a_F1,int a_F2){ /* isfirstarg+t[]+>a */
int a_L2;int a_P[1];
a_comparestring(a_1489,a_1386,a_F1,a_F2,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return 0;} return 1;
} /* isfirstarg */
static void a_1387(void){ /* checkcommandlinearguments */
int a_P[3];
a_1386=to_LIST(a_1489)->aupb;
a_1385=1;
a_G3:if(!a_less(a_1386,to_LIST(a_1489)->alwb)){ goto a_G5;}
a_P[0]=2047260584;a_1419(1,a_P); return;
a_G5:if(!a_1396(a_1001,2130706309)){ goto a_G7;}
a_P[0]=2047260501;a_1424(1,a_P); return;
a_G7:if(!a_1396(a_1001,2130706305)){ goto a_G9;}
a_P[0]=2047260568;a_P[1]=2;a_P[2]=2;a_1424(3,a_P); return;
a_G9:if(!a_1396(a_1001,2130706300)){ goto a_G12;}
a_1385=0;
a_G11:a_previousstring(a_1489,a_1386); goto a_G3;
a_G12:if(!a_1396(a_1001,2130706295)){ goto a_G17;}
a_previousstring(a_1489,a_1386);
if(!a_less(a_1386,to_LIST(a_1489)->alwb)){ goto a_G16;}
a_P[0]=2047260593;a_P[1]=111;a_1419(2,a_P); return;
a_G16:a_1410=a_1386; goto a_G11;
a_G17:if(!a_1396(a_1001,2130706292)){ goto a_G22;}
a_previousstring(a_1489,a_1386);
if(!a_less(a_1386,to_LIST(a_1489)->alwb)){ goto a_G21;}
a_P[0]=2047260593;a_P[1]=76;a_1419(2,a_P); return;
a_G21:a_1397=a_1386; goto a_G11;
a_G22:if(!a_1396(a_1001,2130706289)){ goto a_G24;}
a_1345(); goto a_G11;
a_G24:if(!a_1396(a_1001,2130706286)){ return;}
a_1208(); goto a_G11;
} /* checkcommandlinearguments */
static int a_1392(int a_A[1]){ /* getnextsource+a> */
int a_L2;int a_P[1];
if(!a_equal(a_1381,0)){ goto a_G3;}
a_1381=to_LIST(a_1380)->alwb; goto a_G4;
a_G3:a_next(a_1380,a_1381);
a_G4:a_A[0]=a_1381;
a_G5:if(!a_lseq(a_A[0],to_LIST(a_1380)->aupb)){ goto a_G8;}
a_G6:a_1394(a_A[0],a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return 1;} goto a_G5;
a_G8:if(!a_lseq(to_LIST(a_1489)->alwb,a_1386)){ goto a_G11;}
a_1389(a_1386);
a_previousstring(a_1489,a_1386); goto a_G6;
a_G11:if(!a_is(a_1385)){ return 0;}
a_1389(183666530);
a_1398=to_LIST(a_1380)->aupb;
a_1385=0; goto a_G6;
} /* getnextsource */
static int a_1400(void){ /* notstdlibsource */

if(a_equal(a_1398,0)){ return 1;}
if(a_equal(a_1381,0)){ return 1;}
if(!a_less(a_1381,a_1398)){ return 0;} return 1;
} /* notstdlibsource */
static void a_1391(int a_A[1]){ /* geticefile+a> */
int a_P[1];
if(a_1414(a_1381,a_P)){a_A[0]=a_P[0]; return;}
a_A[0]=0; return;
} /* geticefile */
static int a_1414(int a_F1,int a_A[1]){ /* wasicesource+>a+a> */

if(!a_was(a_1380,a_F1)){ return 0;}
a_A[0]=to_LIST(a_1380)->offset[a_F1]; return 1;
} /* wasicesource */
static void a_1383(void){ /* addextension */

a_1388(46);
a_1388(105);
a_1388(99);
a_1388(101); return;
} /* addextension */
static void a_1382(void){ /* adddirseparator */

if(a_equal(to_LIST(a_1443)->offset[to_LIST(a_1443)->aupb],47)){ return;}
a_1388(47); return;
} /* adddirseparator */
static void a_1402(int a_A[1]){ /* openBUFFER+a> */
int a_L2;int a_P[1];
a_listlength(a_1443,a_L2);
if(!a_lseq(a_L2,0)){ goto a_G4;}
a_A[0]=1; return;
a_G4:a_packstring(a_1443,a_L2,a_1447);
a_scratch(a_1443);
a_1451();
a_1476(a_P);a_A[0]=a_P[0]; return;
} /* openBUFFER */
static void a_1409(int a_F1){ /* stringtoBUFFER+>a */
int a_P[1];
if(!a_was(a_1447,a_F1)){ goto a_G4;}
a_1456(a_F1,a_P);a_F1=a_P[0];
a_unpackstring(a_1447,a_F1,a_1443); return;
a_G4:if(!a_was(a_1489,a_F1)){ goto a_G6;}
a_unpackstring(a_1489,a_F1,a_1443); return;
a_G6:a_1423(a_1001,2130706283); return;
} /* stringtoBUFFER */
static int a_1401(int a_F1,int a_A[1]){ /* nthpath+>a+a> */
int a_L3;
a_A[0]=to_LIST(a_1443)->alwb;
a_L3=to_LIST(a_1380)->offset[a_F1-1];
if(!a_lseq(a_A[0],to_LIST(a_1443)->aupb)){ return 0;}
a_G4:if(a_lseq(a_L3,1)){ return 1;}
if(!a_lseq(a_A[0],to_LIST(a_1443)->aupb)){ return 0;}
if(!a_equal(to_LIST(a_1443)->offset[a_A[0]],58)){ goto a_G8;}
a_decr(a_L3);
a_G8:a_incr(a_A[0]); goto a_G4;
} /* nthpath */
static int a_1406(int a_F1){ /* selectpath+>a */
int a_L2;int a_L3;int a_P[1];
if(!a_1401(a_F1,a_P)){ return 0;}a_L2=a_P[0];
if(!a_equal(to_LIST(a_1443)->offset[a_L2],58)){ goto a_G4;}
a_scratch(a_1443); return 1;
a_G4:a_L3=to_LIST(a_1443)->alwb;
a_G5:to_LIST(a_1443)->offset[a_L3]=to_LIST(a_1443)->offset[a_L2];
a_incr(a_L2);
if(a_more(a_L2,to_LIST(a_1443)->aupb)){ goto a_G10;}
if(a_equal(to_LIST(a_1443)->offset[a_L2],58)){ goto a_G10;}
a_incr(a_L3); goto a_G5;
a_G10:a_unstackto(a_1443,a_L3);
a_1382(); return 1;
} /* selectpath */
static void a_1404(int a_F1,int a_A[1]){ /* openfilefirst+>a+a> */
int a_P[1];
a_scratch(a_1443);
if(!a_1395(a_F1,2)){ goto a_G4;}
a_1413(a_F1,a_1397,a_P);a_A[0]=a_P[0]; return;
a_G4:if(!a_1395(a_F1,4)){ goto a_G6;}
a_1413(a_F1,183666523,a_P);a_A[0]=a_P[0]; return;
a_G6:a_1412(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* openfilefirst */
static void a_1413(int a_F1,int a_F2,int a_A[1]){ /* tryopenwithpath+>a+>a+a> */
int a_P[1];
to_LIST(a_1380)->offset[a_F1-1]=1;
a_G2:a_1409(a_F2);
if(!a_1406(a_F1)){ goto a_G7;}
a_1412(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_incr(to_LIST(a_1380)->offset[a_F1-1]); goto a_G2;
a_G7:a_A[0]=1; return;
} /* tryopenwithpath */
static void a_1412(int a_F1,int a_A[1]){ /* tryopen+>a+a> */
int a_P[2];
a_1409(to_LIST(a_1380)->offset[a_F1]);
if(!a_1395(a_F1,1)){ goto a_G4;}
a_1383();
a_G4:a_1402(a_P);a_A[0]=a_P[0];
if(!a_equal(a_A[0],0)){ goto a_G7;}
a_1407(a_F1,8); return;
a_G7:if(a_more(a_A[0],0)){ return;}
a_P[0]=2047260614;a_P[1]=a_F1;a_1421(2,a_P); return;
} /* tryopen */
static void a_1403(int a_F1){ /* openfileaslast+>a */
int a_L2;int a_P[2];
if(a_1395(a_F1,8)){ goto a_G3;}
a_1423(a_1001,2130706277); return;
a_G3:a_scratch(a_1443);
if(!a_1395(a_F1,2)){ goto a_G7;}
a_1409(a_1397);
if(a_1406(a_F1)){}
a_G7:if(!a_1395(a_F1,4)){ goto a_G10;}
a_1409(183666523);
if(a_1406(a_F1)){}
a_G10:a_1409(to_LIST(a_1380)->offset[a_F1]);
if(!a_1395(a_F1,1)){ goto a_G13;}
a_1383();
a_G13:a_1402(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
a_P[0]=2047260614;a_P[1]=a_F1;a_1421(2,a_P); return;
} /* openfileaslast */
static void a_1408(int a_F1){ /* setsource+>a */

a_1381=a_F1; return;
} /* setsource */
static void a_1405(int a_F1){ /* opensource+>a */

if(!a_equal(a_F1,0)){ goto a_G3;}
a_1381=0; return;
a_G3:a_1381=a_F1;
a_1403(a_F1); return;
} /* opensource */
static void a_1411(int a_F1,int a_A[1]){ /* tryfilefirst+>a+a> */
int a_P[1];
to_LIST(a_1380)->offset[a_F1-2]=0;
a_1404(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1407(a_F1,1);
a_1404(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
if(!a_is(a_1397)){ goto a_G14;}
to_LIST(a_1380)->offset[a_F1-2]=2;
a_1404(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1407(a_F1,1);
a_1404(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_G14:to_LIST(a_1380)->offset[a_F1-2]=4;
a_1404(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1407(a_F1,1);
a_1404(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* tryfilefirst */
static void a_1394(int a_F1,int a_A[1]){ /* handlesourcefile+>a+a> */
int a_P[2];
if(!a_1395(a_F1,8)){ goto a_G4;}
a_1403(a_F1);
a_A[0]=0; return;
a_G4:a_1411(a_F1,a_P);a_A[0]=a_P[0];
if(!a_is(a_A[0])){ goto a_G7;}
a_P[0]=2047260614;a_P[1]=a_F1;a_1421(2,a_P); return;
a_G7:if(!a_equal(a_1457,16777273)){ goto a_G9;}
a_1399=a_F1; return;
a_G9:if(!a_equal(a_1457,16777262)){ return;}
a_1384(a_F1);
a_A[0]=1; return;
} /* handlesourcefile */
static void a_1384(int a_F1){ /* addincludedicefiles+>a */
int a_L2;int a_P[2];
if(!a_noteq(a_F1,to_LIST(a_1380)->aupb)){ goto a_G3;}
a_P[0]=2047260625;a_P[1]=a_F1;a_1421(2,a_P); return;
a_G3:a_unstack(a_1380);
a_G4:if(!a_equal(16777262,a_1457)){ goto a_G11;}
a_1464();
if(!a_equal(16777483,a_1457)){ goto a_G9;}
a_L2=a_1458;
a_1464(); goto a_G10;
a_G9:a_1418(a_1001,2130706271); return;
a_G10:a_1389(a_L2); goto a_G4;
a_G11:a_1451(); return;
} /* addincludedicefiles */
static void a_1393(void){ /* gettargetfile */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;
if(!a_is(a_1410)){ goto a_G4;}
a_L5=0;
a_L2=a_1410; goto a_G6;
a_G4:a_L5=1;
a_L2=to_LIST(a_1380)->offset[a_1399];
a_G6:a_L1=to_LIST(a_1443)->aupb;
a_1409(a_L2);
a_L4=to_LIST(a_1443)->aupb;
a_L6=1;
a_G10:if(a_lseq(a_L4,a_L1)){ goto a_G21;}
{register int a_r1=to_LIST(a_1443)->offset[a_L4];
 if(a_r1==46){ goto a_G12;}
 if(a_r1==47||a_r1==92||a_r1==58){ goto a_G19;}
  goto a_G20;}
a_G12:if(!a_equal(a_L5,0)){ goto a_G15;}
a_L5=2;
a_G14:a_L4=a_L1; goto a_G21;
a_G15:a_decr(a_L4);
if(!a_is(a_L6)){ goto a_G10;}
a_L6=0;
a_unstackto(a_1443,a_L4); goto a_G10;
a_G19:if(a_equal(a_L5,1)){ goto a_G21;} goto a_G14;
a_G20:a_decr(a_L4); goto a_G10;
a_G21:if(a_equal(a_L5,2)){ goto a_G24;}
a_1388(46);
a_1388(99);
a_G24:a_subtr(to_LIST(a_1443)->aupb,a_L4,a_L3);
a_packstring(a_1443,a_L3,a_1447);
a_unstackto(a_1443,a_L1); return;
} /* gettargetfile */
static void a_1429(int a_F1){ /* printchar+>a */

a_incr(a_1437);
a_putchar(a_1417,a_F1); return;
} /* printchar */
static void a_1426(void){ /* nlcr */

if(!a_lseq(a_1437,1)){ goto a_G3;}
a_1437=1; return;
a_G3:a_1437=0;
a_1429(10); return;
} /* nlcr */
static void a_1438(int a_F1){ /* tabline+>a */

a_G1:if(a_equal(a_1437,a_F1)){ return;}
if(!a_more(a_1437,a_F1)){ goto a_G4;}
a_1426(); goto a_G1;
a_G4:a_1429(32); goto a_G1;
} /* tabline */
static void a_1432(int a_F1){ /* printint+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G5;}
a_1429(45);
a_subtr(-1,a_F1,a_F1);
a_1433(a_F1,49); return;
a_G5:if(!a_less(a_F1,0)){ goto a_G8;}
a_1429(45);
a_getabs(a_F1,a_F1);
a_G8:a_1433(a_F1,48); return;
} /* printint */
static void a_1433(int a_F1,int a_F2){ /* printint1+>a+>a */
int a_L3;int a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1433(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_1429(a_L4); return;
} /* printint1 */
static void a_1430(int a_F1){ /* printform+>a */

a_1431(a_F1,4); return;
} /* printform */
static void a_1431(int a_F1,int a_F2){ /* printform1+>a+>a */
int a_L3;int a_L4;
if(a_equal(a_F2,0)){ return;}
a_decr(a_F2);
a_divrem11(a_F1,10,a_L3,a_L4);
a_1431(a_L3,a_F2);
a_add(a_L4,48,a_L4);
a_1429(a_L4); return;
} /* printform1 */
static void a_1427(int a_F1,int a_F2){ /* print+t[]+>a */
int a_L2;
if(!a_was(a_F1,a_F2)){ return;}
a_1486(a_1417,a_F1,a_F2);
a_stringlength(a_F1,a_F2,a_L2);
a_add(a_1437,a_L2,a_1437); return;
} /* print */
static void a_1436(int a_F1){ /* printpointer+>a */
int a_P[1];
a_G1:if(!a_equal(a_F1,0)){ goto a_G3;}
a_1427(a_1001,2130706340); return;
a_G3:if(a_1414(a_F1,a_P)){a_F1=a_P[0]; goto a_G1;}
if(!a_was(a_1416,a_F1)){ goto a_G6;}
a_1427(a_1416,a_F1); return;
a_G6:if(!a_was(a_1489,a_F1)){ goto a_G8;}
a_1427(a_1489,a_F1); return;
a_G8:if(!a_was(a_1447,a_F1)){ goto a_G11;}
a_1456(a_F1,a_P);a_F1=a_P[0];
a_1427(a_1447,a_F1); return;
a_G11:a_1423(a_1001,2130706336); return;
} /* printpointer */
static void a_1428(int a_F1){ /* printbase+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_L2=to_LIST(a_1443)->aupb;
if(!a_was(a_1447,a_F1)){ goto a_G5;}
a_1456(a_F1,a_P);a_F1=a_P[0];
a_unpackstring(a_1447,a_F1,a_1443); goto a_G9;
a_G5:if(!a_was(a_1489,a_F1)){ goto a_G7;}
a_unpackstring(a_1489,a_F1,a_1443); goto a_G9;
a_G7:if(a_equal(a_F1,0)){ goto a_G9;}
a_1423(a_1001,2130706330); return;
a_G9:a_L3=to_LIST(a_1443)->aupb;
a_L4=0;
a_G11:if(a_lseq(a_L3,a_L2)){ goto a_G18;}
if(!a_equal(to_LIST(a_1443)->offset[a_L3],46)){ goto a_G15;}
a_incr(a_L4);
a_G14:a_decr(a_L3); goto a_G11;
a_G15:if(a_equal(to_LIST(a_1443)->offset[a_L3],47)){ goto a_G18;}
if(a_equal(to_LIST(a_1443)->offset[a_L3],92)){ goto a_G18;}
if(!a_equal(to_LIST(a_1443)->offset[a_L3],58)){ goto a_G14;}
a_G18:a_incr(a_L3);
if(a_more(a_L3,to_LIST(a_1443)->aupb)){ goto a_G25;}
if(!a_equal(to_LIST(a_1443)->offset[a_L3],46)){ goto a_G24;}
if(a_lseq(a_L4,1)){ goto a_G25;}
a_decr(a_L4);
a_1429(46); goto a_G18;
a_G24:a_1429(to_LIST(a_1443)->offset[a_L3]); goto a_G18;
a_G25:a_unstackto(a_1443,a_L2); return;
} /* printbase */
static void a_1434(int a_F1){ /* printitem+>a */
int a_L2;int a_L3;int a_L4;int a_P[3];
a_1302(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];
if(a_lseq(a_L2,0)){ goto a_G4;}
a_1430(a_L2);
a_G4:if(a_equal(a_L3,183666559)){ goto a_G7;}
a_1429(47);
a_1428(a_L3);
a_G7:if(a_equal(a_L4,0)){ return;}
a_1429(32);
a_1427(a_1001,2130706325);
a_1436(a_L4);
a_1429(41); return;
} /* printitem */
static void a_1435(int a_F1){ /* printline+>a */
int a_L2;int a_L3;int a_P[2];
a_1303(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];
if(a_lseq(a_L2,0)){ goto a_G4;}
a_1430(a_L2);
a_G4:if(a_equal(a_L3,183666559)){ return;}
a_1429(47);
a_1428(a_L3); return;
} /* printline */
static void a_1422(int a_C,int *a_V){ /* formatprint+@+>a */
int a_L2;int a_L3;
a_L2=to_LIST(a_1443)->aupb;
a_unpackstring(a_1416,a_V[0],a_1443);
a_add(a_L2,1,a_L3);
a_G4:if(a_less(to_LIST(a_1443)->aupb,a_L3)){ goto a_G26;}
if(!a_noteq(to_LIST(a_1443)->offset[a_L3],37)){ goto a_G8;}
a_G6:a_1429(to_LIST(a_1443)->offset[a_L3]);
a_G7:a_incr(a_L3); goto a_G4;
a_G8:a_incr(a_L3);
if(!a_less(to_LIST(a_1443)->aupb,a_L3)){ goto a_G11;}
a_1429(37); goto a_G26;
a_G11:{register int a_r1=to_LIST(a_1443)->offset[a_L3];
 if(a_r1==112){ goto a_G12;}
 if(a_r1==120){ goto a_G15;}
 if(a_r1==105){ goto a_G17;}
 if(a_r1==99){ goto a_G19;}
 if(a_r1==108){ goto a_G21;}
 if(a_r1==100){ goto a_G23;}
 if(a_r1==110){ goto a_G25;}
  goto a_G6;}
a_G12:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1436(a_V[0]); goto a_G7;
a_G14:a_1427(a_1001,2130706320); goto a_G7;
a_G15:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1427(a_1447,a_V[0]); goto a_G7;
a_G17:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1434(a_V[0]); goto a_G7;
a_G19:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1429(a_V[0]); goto a_G7;
a_G21:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1435(a_V[0]); goto a_G7;
a_G23:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1432(a_V[0]); goto a_G7;
a_G25:a_1429(10); goto a_G7;
a_G26:if(a_C<=1){ goto a_G28;} a_C--;a_V+=1;
a_1427(a_1001,2130706317);
a_G28:a_unstackto(a_1443,a_L2); return;
} /* formatprint */
static int a_1440(void){ /* waserror */

if(!a_more(a_1420,0)){ return 0;} return 1;
} /* waserror */
static void a_1425(int a_F1){ /* messagehead+>a */
int a_L2;int a_P[1];
a_1426();
a_1429(a_F1);
a_1429(32);
a_1391(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G7;}
a_1428(a_L2);
a_G7:if(!a_equal(a_F1,70)){ goto a_G10;}
a_1429(47);
a_1430(a_1475);
a_G10:a_1429(32);
a_1438(16); return;
} /* messagehead */
static void a_1419(int a_C,int *a_V){ /* error+@+>a */
int a_P[1];
if(a_mreq(a_1420,51)){ return;}
a_1425(69);
a_1422(a_C,a_V);
a_1426();
a_incr(a_1420);
if(a_less(a_1420,51)){ return;}
a_1425(70);
a_P[0]=2047260640;a_1422(1,a_P);
a_1426(); return;
} /* error */
static void a_1439(int a_C,int *a_V){ /* warning+@+>a */

if(a_mreq(a_1420,51)){ return;}
a_1425(87);
a_1422(a_C,a_V);
a_1426(); return;
} /* warning */
static void a_1424(int a_C,int *a_V){ /* message+@+>a */

a_1422(a_C,a_V);
a_1426();
a_incr(a_1420); return;
} /* message */
static void a_1421(int a_C,int *a_V){ /* fatalerror+@+>a */

a_1425(70);
a_1422(a_C,a_V);
a_1426();
a_1134();
a_exit(15); return;
} /* fatalerror */
static void a_1418(int a_F1,int a_F2){ /* corrupticefile+t[]+>a */
int a_L2;int a_P[2];
a_1425(70);
a_1391(a_P);a_L2=a_P[0];
a_P[0]=2047260661;a_P[1]=a_L2;a_1422(2,a_P);
a_1427(a_F1,a_F2);
a_P[0]=2047260666;a_1422(1,a_P);
a_1426();
a_exit(3); return;
} /* corrupticefile */
static void a_1423(int a_F1,int a_F2){ /* internalerror+t[]+>a */
int a_P[1];
a_1425(70);
a_P[0]=2047260648;a_1422(1,a_P);
a_1427(a_F1,a_F2);
a_P[0]=2047260653;a_1422(1,a_P);
a_1426();
a_exit(15); return;
} /* internalerror */
static void a_1454(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1443,1);a_r1[0]=a_F1;to_LIST(a_1443)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1476(int a_A[1]){ /* trytoopensource+a> */
int a_L2;
if(!a_openfile(a_1448,114,a_1447,to_LIST(a_1447)->aupb)){ goto a_G8;}
a_A[0]=0;
a_unstackstring(a_1447);
a_1475=1;
a_1450=32;
a_1463();
a_1464(); return;
a_G8:a_unstackstring(a_1447);
a_getfileerror(a_1448,a_L2);
if(!a_equal(a_L2,2)){ goto a_G12;}
a_A[0]=1; return;
a_G12:a_A[0]=-1; return;
} /* trytoopensource */
static void a_1451(void){ /* closesource */

a_closefile(a_1448); return;
} /* closesource */
static void a_1463(void){ /* nextchar */
int a_P[1];
a_G1:if(!a_getchar(a_1448,a_P)){ goto a_G4;}a_1450=a_P[0];
{ if(a_1450==10){ goto a_G3;}
 if(a_1450<=31){ goto a_G1;}
  return;}
a_G3:a_incr(a_1475); return;
a_G4:a_1450=1; return;
} /* nextchar */
static void a_1474(void){ /* saveinputposition */
int a_P[1];
a_getfilepos(a_1448,a_P);a_1460=a_P[0];
a_1459=a_1450;
a_1461=a_1457;
a_1462=a_1458; return;
} /* saveinputposition */
static void a_1473(void){ /* restoreinputposition */

a_setfilepos(a_1448,a_1460);
a_1450=a_1459;
a_1457=a_1461;
a_1458=a_1462; return;
} /* restoreinputposition */
static void a_1452(void){ /* comment */

a_G1:if(a_equal(a_1450,10)){ return;}
if(a_equal(a_1450,1)){ return;}
a_1463(); goto a_G1;
} /* comment */
static void a_1467(int a_A[1]){ /* readdestination+a> */
int a_L2;
{ if(a_1450==78){ goto a_G2;}
 if(a_1450==48){ goto a_G15;}
 if(a_1450==45){ goto a_G17;}
  goto a_G28;}
a_G2:a_1463();
{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G8;}
}
a_subtr(a_1450,48,a_A[0]);
a_1463();
if(a_more(a_A[0],0)){ goto a_G9;}
if(a_equal(0,0)){ goto a_G9;}
a_G8:a_1418(a_1001,2130706387); return;
a_G9:{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G13;}
}
a_subtr(a_1450,48,a_L2);
a_1463();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G9;
a_G13:if(!a_is(0)){ return;}
a_G14:a_subtr(0,a_A[0],a_A[0]); return;
a_G15:a_1463();
a_A[0]=0; return;
a_G17:a_1463();
{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G8;}
}
a_subtr(a_1450,48,a_A[0]);
a_1463();
if(a_more(a_A[0],0)){ goto a_G23;}
if(!a_equal(1,0)){ goto a_G8;}
a_G23:{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G27;}
}
a_subtr(a_1450,48,a_L2);
a_1463();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G23;
a_G27:if(!a_is(1)){ return;} goto a_G14;
a_G28:a_1418(a_1001,2130706382); return;
} /* readdestination */
static void a_1469(int a_A[1]){ /* readtargetnumber+a> */
int a_L2;int a_L3;int a_P[1];
a_L2=to_LIST(a_1443)->aupb;
a_L3=0;
a_G3:{ if(a_1450==45){ goto a_G4;}
 if((48<=a_1450 && a_1450<=57)){ goto a_G6;}
  goto a_G7;}
a_G4:a_L3=1;
a_G5:a_1463(); goto a_G3;
a_G6:a_1454(a_1450); goto a_G5;
a_G7:a_1007(a_L3,a_L2,a_P);a_A[0]=a_P[0];
a_unstackto(a_1443,a_L2); return;
} /* readtargetnumber */
static void a_1455(int a_F1,int a_A[1]){ /* gettagdata+>a+a> */

a_A[0]=to_LIST(a_1447)->offset[a_F1]; return;
} /* gettagdata */
static void a_1456(int a_F1,int a_A[1]){ /* gettagimage+>a+a> */

a_subtr(a_F1,2,a_A[0]); return;
} /* gettagimage */
static void a_1465(int a_F1,int a_F2){ /* puttagdata+>a+>a */

to_LIST(a_1447)->offset[a_F1]=a_F2; return;
} /* puttagdata */
static void a_1449(int a_A[1]){ /* addLEXTentry+a> */
int a_P[1];
{register int *a_r1=a_extension(a_1447,2);a_r1[0]=a_r1[1]=0;to_LIST(a_1447)->aupb+=2;}
a_1453(to_LIST(a_1447)->aupb,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],to_LIST(a_1447)->aupb)){ return;}
a_unstack(a_1447);
a_unstackstring(a_1447); return;
} /* addLEXTentry */
static void a_1453(int a_F1,int a_A[1]){ /* enterstring+>a+a> */
int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_P[1];
a_subtr(a_F1,2,a_L3);
a_stringhash(a_1447,a_L3,a_P);a_L4=a_P[0];
a_booland(a_L4,2147483647,a_L4);
a_divrem01(a_L4,a_1446,a_L4);
a_add(a_L4,to_LIST(a_1444)->alwb,a_L4);
a_L5=to_LIST(a_1444)->offset[a_L4];
a_G7:if(!a_equal(a_L5,0)){ goto a_G14;}
to_LIST(a_1447)->offset[a_F1-1]=to_LIST(a_1444)->offset[a_L4];
to_LIST(a_1444)->offset[a_L4]=a_F1;a_A[0]=a_F1;
a_incr(a_1445);
if(a_less(a_1445,a_1446)){ return;}
a_add(a_1446,1024,a_1446);
a_1472(); return;
a_G14:a_subtr(a_L5,2,a_L6);
a_comparestring(a_1447,a_L3,a_1447,a_L6,a_P);a_L7=a_P[0];
if(!a_equal(a_L7,0)){ goto a_G18;}
a_A[0]=a_L5; return;
a_G18:a_L5=to_LIST(a_1447)->offset[a_L5-1]; goto a_G7;
} /* enterstring */
static void a_1472(void){ /* rehash */
int a_L1;int a_L2;int a_P[1];
a_1445=0;
a_L1=to_LIST(a_1444)->aupb;
a_G3:if(a_less(a_L1,to_LIST(a_1444)->alwb)){ goto a_G6;}
to_LIST(a_1444)->offset[a_L1]=0;
a_previous(a_1444,a_L1); goto a_G3;
a_G6:a_subtr(to_LIST(a_1444)->aupb,to_LIST(a_1444)->alwb,a_L2);
a_G7:a_incr(a_L2);
if(a_mreq(a_L2,a_1446)){ goto a_G10;}
{register int *a_r1=a_extension(a_1444,1);a_r1[0]=0;to_LIST(a_1444)->aupb+=1;}
  goto a_G7;
a_G10:a_L1=to_LIST(a_1447)->aupb;
a_G11:if(a_less(a_L1,to_LIST(a_1447)->alwb)){ return;}
a_1453(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,a_L1)){ goto a_G16;}
a_previous(a_1447,a_L1);
a_previousstring(a_1447,a_L1); goto a_G11;
a_G16:a_1423(a_1001,2130706376); return;
} /* rehash */
static void a_1468(int a_A[1]){ /* readstring+a> */
int a_L2;int a_L3;int a_P[1];
a_L3=to_LIST(a_1443)->aupb;
a_L2=0;
a_G3:a_1463();
{ if(a_1450==34){ goto a_G5;}
 if(a_1450==10||a_1450==1){ goto a_G14;}
  goto a_G7;}
a_G5:a_1463();
if(!a_equal(a_1450,34)){ goto a_G9;}
a_G7:a_1454(a_1450);
a_incr(a_L2); goto a_G3;
a_G9:if(!a_equal(a_L2,0)){ goto a_G11;}
a_A[0]=183666559; return;
a_G11:a_packstring(a_1443,a_L2,a_1447);
a_unstackto(a_1443,a_L3);
a_1449(a_P);a_A[0]=a_P[0]; return;
a_G14:a_1418(a_1001,2130706372); return;
} /* readstring */
static void a_1470(int a_A[2]){ /* readtargetstring+a>+a> */
int a_L3;int a_P[2];
a_L3=to_LIST(a_1443)->aupb;
if(a_equal(a_1450,34)){ goto a_G4;}
a_G3:a_1418(a_1001,2130706367); return;
a_G4:a_1463();
{ if(a_1450==34){ goto a_G6;}
 if(a_1450==10||a_1450==1){ goto a_G3;}
  goto a_G8;}
a_G6:a_1463();
if(!a_equal(a_1450,34)){ goto a_G9;}
a_G8:a_1454(a_1450); goto a_G4;
a_G9:a_1008(a_L3,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];
a_unstackto(a_1443,a_L3); return;
} /* readtargetstring */
static void a_1466(int a_A[1]){ /* readbold+a> */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1463();
a_L3=to_LIST(a_1443)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1450 && a_1450<=122))){ goto a_G9;}
}
a_L4=a_1450;
a_1463();
a_1454(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1450,39)){ goto a_G11;}
a_1463(); goto a_G12;
a_G11:a_1418(a_1001,2130706360); return;
a_G12:a_packstring(a_1443,a_L2,a_1447);
a_unstackto(a_1443,a_L3);
a_A[0]=16777299;
a_G15:a_comparestring(a_1442,a_A[0],a_1447,to_LIST(a_1447)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G19;}
if(a_equal(a_A[0],16777220)){ goto a_G11;}
a_previousstring(a_1442,a_A[0]); goto a_G15;
a_G19:a_unstackstring(a_1447); return;
} /* readbold */
static void a_1471(int a_A[1]){ /* readtype+a> */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1463();
a_L3=to_LIST(a_1443)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1450 && a_1450<=122))){ goto a_G9;}
}
a_L4=a_1450;
a_1463();
a_1454(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1450,32)){ goto a_G13;}
a_1454(32);
a_incr(a_L2);
a_1463(); goto a_G4;
a_G13:if(!a_equal(a_1450,62)){ goto a_G15;}
a_1463(); goto a_G16;
a_G15:a_1418(a_1001,2130706355); return;
a_G16:a_packstring(a_1443,a_L2,a_1447);
a_unstackto(a_1443,a_L3);
a_A[0]=16777394;
a_G19:a_comparestring(a_1442,a_A[0],a_1447,to_LIST(a_1447)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G23;}
if(a_equal(a_A[0],16777304)){ goto a_G15;}
a_previousstring(a_1442,a_A[0]); goto a_G19;
a_G23:a_unstackstring(a_1447); return;
} /* readtype */
static void a_1464(void){ /* nextsymbol */
int a_L1;int a_P[2];
a_G1:a_P[0]=a_1477;a_1020(a_P);a_1477=a_P[0];a_1458=a_P[1];
if(!a_more(a_1477,0)){ goto a_G4;}
a_1457=16777459; return;
a_G4:{ if(a_1450==32||a_1450==10){ goto a_G5;}
 if(a_1450==36){ goto a_G6;}
 if(a_1450==48){ goto a_G7;}
 if((49<=a_1450 && a_1450<=57)){ goto a_G10;}
 if(a_1450==70){ goto a_G23;}
 if(a_1450==73){ goto a_G34;}
 if(a_1450==76){ goto a_G48;}
 if(a_1450==78){ goto a_G59;}
 if(a_1450==88){ goto a_G70;}
 if(a_1450==84){ goto a_G73;}
 if(a_1450==39){ goto a_G76;}
 if(a_1450==60){ goto a_G77;}
 if(a_1450==34){ goto a_G79;}
 if(a_1450==38){ goto a_G81;}
 if(a_1450==93){ goto a_G82;}
 if(a_1450==41){ goto a_G83;}
 if(a_1450==58){ goto a_G84;}
 if(a_1450==44){ goto a_G85;}
 if(a_1450==126){ goto a_G86;}
 if(a_1450==47){ goto a_G87;}
 if(a_1450==45){ goto a_G88;}
 if(a_1450==35){ goto a_G103;}
 if(a_1450==40){ goto a_G104;}
 if(a_1450==124){ goto a_G105;}
 if(a_1450==62){ goto a_G106;}
 if(a_1450==43){ goto a_G109;}
 if(a_1450==46){ goto a_G110;}
 if(a_1450==59){ goto a_G111;}
 if(a_1450==42){ goto a_G112;}
 if(a_1450==91){ goto a_G113;}
 if(a_1450==94){ goto a_G114;}
 if(a_1450==64){ goto a_G115;}
 if(a_1450==1){ goto a_G116;}
  goto a_G117;}
a_G5:a_1463(); goto a_G1;
a_G6:a_1452(); goto a_G1;
a_G7:a_1457=16777455;
a_1458=0;
a_G9:a_1463(); return;
a_G10:a_1457=16777455;
{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G16;}
}
a_subtr(a_1450,48,a_1458);
a_1463();
if(a_more(a_1458,0)){ goto a_G17;}
if(a_equal(0,0)){ goto a_G17;}
a_G16:a_1418(a_1001,2130706387); return;
a_G17:{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G21;}
}
a_subtr(a_1450,48,a_L1);
a_1463();
a_addmult(a_1458,10,a_L1,a_1458); goto a_G17;
a_G21:if(!a_is(0)){ return;}
a_G22:a_subtr(0,a_1458,a_1458); return;
a_G23:a_1457=16777475;
a_1463();
{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G16;}
}
a_subtr(a_1450,48,a_1458);
a_1463();
if(a_more(a_1458,0)){ goto a_G30;}
if(!a_equal(0,0)){ goto a_G16;}
a_G30:{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G21;}
}
a_subtr(a_1450,48,a_L1);
a_1463();
a_addmult(a_1458,10,a_L1,a_1458); goto a_G30;
a_G34:a_1457=16777471;
a_1463();
{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G16;}
}
a_subtr(a_1450,48,a_1458);
a_1463();
if(a_more(a_1458,0)){ goto a_G41;}
if(!a_equal(0,0)){ goto a_G16;}
a_G41:{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G45;}
}
a_subtr(a_1450,48,a_L1);
a_1463();
a_addmult(a_1458,10,a_L1,a_1458); goto a_G41;
a_G45:if(!a_is(0)){ goto a_G47;}
a_subtr(0,a_1458,a_1458);
a_G47:a_P[0]=a_1458;a_1297(a_P);a_1458=a_P[0]; return;
a_G48:a_1457=16777479;
a_1463();
{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G16;}
}
a_subtr(a_1450,48,a_1458);
a_1463();
if(a_more(a_1458,0)){ goto a_G55;}
if(!a_equal(0,0)){ goto a_G16;}
a_G55:{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G21;}
}
a_subtr(a_1450,48,a_L1);
a_1463();
a_addmult(a_1458,10,a_L1,a_1458); goto a_G55;
a_G59:a_1457=16777467;
a_1463();
{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G16;}
}
a_subtr(a_1450,48,a_1458);
a_1463();
if(a_more(a_1458,0)){ goto a_G66;}
if(!a_equal(0,0)){ goto a_G16;}
a_G66:{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G21;}
}
a_subtr(a_1450,48,a_L1);
a_1463();
a_addmult(a_1458,10,a_L1,a_1458); goto a_G66;
a_G70:a_1457=16777459;
a_1463();
a_1469(a_P);a_1458=a_P[0]; return;
a_G73:a_1457=16777459;
a_1463();
a_1470(a_P);a_1477=a_P[0];a_1458=a_P[1]; return;
a_G76:a_1466(a_P);a_1457=a_P[0]; return;
a_G77:a_1457=16777463;
a_1471(a_P);a_1458=a_P[0]; return;
a_G79:a_1457=16777483;
a_1468(a_P);a_1458=a_P[0]; return;
a_G81:a_1457=16777400; goto a_G9;
a_G82:a_1457=16777403; goto a_G9;
a_G83:a_1457=16777406; goto a_G9;
a_G84:a_1457=16777409; goto a_G9;
a_G85:a_1457=16777412; goto a_G9;
a_G86:a_1457=16777415; goto a_G9;
a_G87:a_1457=16777418; goto a_G9;
a_G88:a_1463();
{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G101;}
}
a_1457=16777455;
{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G16;}
}
a_subtr(a_1450,48,a_1458);
a_1463();
if(a_more(a_1458,0)){ goto a_G96;}
if(!a_equal(1,0)){ goto a_G16;}
a_G96:{ if(!((48<=a_1450 && a_1450<=57))){ goto a_G100;}
}
a_subtr(a_1450,48,a_L1);
a_1463();
a_addmult(a_1458,10,a_L1,a_1458); goto a_G96;
a_G100:if(!a_is(1)){ return;} goto a_G22;
a_G101:a_1457=16777421;
a_1458=0; return;
a_G103:a_1457=16777424; goto a_G9;
a_G104:a_1457=16777427; goto a_G9;
a_G105:a_1457=16777430; goto a_G9;
a_G106:a_1457=16777433;
a_1463();
a_1467(a_P);a_1458=a_P[0]; return;
a_G109:a_1457=16777436; goto a_G9;
a_G110:a_1457=16777439; goto a_G9;
a_G111:a_1457=16777442; goto a_G9;
a_G112:a_1457=16777445; goto a_G9;
a_G113:a_1457=16777448; goto a_G9;
a_G114:a_1457=16777451; goto a_G9;
a_G115:a_1457=16777397; goto a_G9;
a_G116:a_1457=16777486; return;
a_G117:a_1418(a_1001,2130706350); return;
} /* nextsymbol */
static void a_1441(void){ /* @root */

a_1472(); return;
} /* @root */
static void a_1479(void){ /* pass1 */
int a_L1;int a_P[1];
a_G1:if(a_1440()){ return;}
if(!a_1392(a_P)){ return;}a_L1=a_P[0];
a_1319(a_L1);
a_1326();
a_1451(); goto a_G1;
} /* pass1 */
static void a_1480(void){ /* pass2 */
int a_L1;int a_P[1];
a_G1:if(a_1440()){ return;}
a_1335(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_equal(a_L1,2)){ goto a_G1;}
a_1355();
a_1356();
a_1251(); goto a_G1;
} /* pass2 */
static void a_1481(void){ /* pass3 */
int a_L1;int a_P[1];
a_G1:if(a_1440()){ return;}
a_1335(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_equal(a_L1,2)){ goto a_G1;}
a_1355();
a_1356();
a_1252(); goto a_G1;
} /* pass3 */
static void a_1482(void){ /* pass4 */
int a_L1;int a_P[1];
a_1138();
a_G2:a_1335(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ goto a_G8;}
if(a_equal(a_L1,2)){ goto a_G2;}
a_1355();
a_1356();
a_1253(); goto a_G2;
a_G8:a_1139(); return;
} /* pass4 */
static void a_1483(void){ /* pass5 */
int a_L1;int a_P[1];
a_G1:if(a_1440()){ return;}
a_1335(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_equal(a_L1,2)){ goto a_G1;}
a_1355();
a_1356();
a_1277();
a_1080(); goto a_G1;
} /* pass5 */
static void a_1478(void){ /* @root */

a_1387();
if(!a_1440()){ goto a_G4;}
a_exit(1); return;
a_G4:a_1479();
if(!a_1440()){ goto a_G8;}
a_G6:a_1451();
a_G7:a_exit(2); return;
a_G8:a_1351();
a_1345();
a_1480();
if(a_1440()){ goto a_G6;}
a_1232();
a_1264();
a_1481();
if(a_1440()){ goto a_G6;}
a_1254();
if(a_1440()){ goto a_G7;}
a_1225();
if(a_1440()){ goto a_G7;}
a_1243();
a_1160();
if(!a_1440()){ goto a_G24;}
a_exit(4); return;
a_G24:a_1203();
a_1129();
a_1482();
a_1131();
a_1200();
a_1483();
a_1181();
a_1202();
a_1126();
if(!a_1440()){ return;}
a_1134(); goto a_G7;
} /* @root */
static void a_1486(int a_F1,int a_F2,int a_F3){ /* putstring+""f+t[]+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=0;
a_G2:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){ return;}a_L3=a_P[0];
a_incr(a_L2);
a_putchar(a_F1,a_L3); goto a_G2;
} /* putstring */
a_PROFILEp a_profiles=NULL;
static void a_stringhash(int F1,int F2,int A[1]){ int *ptr=to_LIST(F1)->offset+F2; unsigned char *v=(unsigned char*)&ptr[1-ptr[0]]; unsigned v1=0x135345+47u*(*v),v2=0xeca864+856u*(*v); while(*v){  v1=(-29u*v1-17u*v2+1259u*((*v)^v2)) % 0x1010309;  v2=(-23u*v2-257u*v1+1237u*((*v)^v1)) % 0x1010507;  v++; } A[0]=(int)((v1<<16)^v2);}
void a_blockhash(int F1,int F2,int A[1]){ unsigned char *v=(unsigned char*)(to_LIST(F1)->offset+F2+1); unsigned v1=0x135345+47u*(*v), v2=0xeca864+856u*(*v); int cnt=sizeof(int)*(to_LIST(F1)->aupb-F2); for(;cnt>0;cnt--){  v1=(-29u*v1-17u*v2+1259u*((*v)^v2)) % 0x1010309;  v2=(-23u*v2-257u*v1+1237u*((*v)^v1)) % 0x1010507;  v++; } A[0]=(int)((v1<<16)^v2);}
extern int a_argc; extern char **a_argv;
static int a_push_string_to(int F1,char*ptr){ int n,w;int*goal;char*to;
 #define st to_LIST(F1)
 w=0;n=12;for(to=ptr;*to;to++){n++;if((*to&0xC0)!=0x80)w++;} n/=4;if(!a_requestspace(F1,n))return 0;
 goal=&(st->offset[1+st->aupb]);to=(char*)goal; goal[n-1]=n;goal[n-2]=w;goal[n-3]=0;st->aupb+=n; while(*ptr)*to++=*ptr++;
 #undef st
 return 1;}
static void a_setup_stdarg(int F1,const char*name,int F2){
 int i;
 #define st to_LIST(F1)
 st->name=name;st->offset=st->p=0;st->length=0; st->vlwb=a_virtual_max+16;a_virtual_max+=65436; if(a_virtual_max<=0) a_fatal(a_FATAL_memory);
 st->vupb=a_virtual_max-1;st->calibre=F2; st->alwb=st->vlwb;st->aupb=st->alwb-st->calibre;
  for(i=a_argc-1;i>0;i--){   if(a_push_string_to(F1,a_argv[i])==0)a_fatal(a_FATAL_memory); }
 #undef st
}
/* EOF */
