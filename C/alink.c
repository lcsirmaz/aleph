/* ALEPH ice linker v2.1, word size=32 */

// linked modules:
// number "number v2.0"
// rule "rule, v2.0"
// target "target, v2.1"
// expression "expression, v2.0"
// data "data, v2.0"
// item "item, v2.0"
// arithmetic "arithmetic v2.0"
// config "config, v2.1"
// input "input, v2.1"
// error "error, v2.1"
// lexical "lexical, v2.0"
// @main "ALEPH linker, v2.0"
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
static void a_1006(a_word a_F1,a_word a_F2); /* adddigit */
static void a_1007(a_word a_F1,a_word a_F2,a_word a_A[1]); /* enterconststring */
static void a_1008(a_word a_F1,a_word a_A[2]); /* entertargetstring */
static void a_1009(a_word a_F1); /* extendBUFFER */
static void a_1010(a_word a_F1,a_word a_A[1]); /* getdigit */
static void a_1011(a_word a_F1); /* getnumberrepr */
static void a_1012(a_word a_A[1]); /* getnumberzero */
static void a_1013(a_word a_F1); /* getregisterrepr */
static void a_1014(a_word a_F1,a_word a_A[1]); /* gettargetnumbervalue */
static void a_1015(void); /* initializenumbers */
static a_word a_1016=0; /* lastdigit */
static void a_1017(a_word a_F1,a_word a_F2,a_word a_A[1]); /* loadregister */
static a_word a_1018=0; /* maxdecimal */
static a_word a_1019(a_word a_F1,a_word a_F2); /* minmaxregisters */
static void a_1020(a_word a_A[2]); /* nexttargetstringvalue */
static a_word a_1021=0; /* rtargetmax */
static a_word a_1022=0; /* rtargetmin */
static a_word a_1023(a_word a_F1); /* samenumberblock */
static void a_1024(a_word a_F1,a_word a_A[1]); /* storeregister */
static a_word a_1025=0; /* targetmaxint */
static a_word a_1026=0; /* targetminint */
static a_word a_1027=0; /* zeroptr */
static a_word a_1029=0; /* C1 */
static a_word a_1030=0; /* C2 */
static a_word a_1031=0; /* C3 */
#define a_1032 (a_1005+sizeof_LIST) /* NODE */
#define a_1033 (a_1032+sizeof_LIST) /* ZONE */
static a_word a_1034=0; /* addcs */
static void a_1035(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]); /* addinterval */
static void a_1036(void); /* advancenode */
static void a_1037(void); /* arealabels */
static void a_1038(a_word a_F1,a_word a_A[1]); /* checkarea */
static void a_1039(void); /* checkareas */
static void a_1040(void); /* checknodehash */
static void a_1041(a_word a_F1,a_word a_F2); /* clearnodeflag */
static void a_1042(void); /* clearstacksize */
static void a_1043(a_word a_F1); /* comparetostoredaffixes */
static a_word a_1044(a_word a_F1); /* completezone */
static void a_1045(void); /* computeruleaffixhash */
static void a_1046(void); /* createnodes */
static a_word a_1047=0; /* dolocalaffixcheck */
static a_word a_1048(a_word a_F1,a_word a_F2); /* equalaffixes */
static void a_1049(void); /* extensionlabel */
static void a_1050(void); /* findequalnodes */
static void a_1051(a_word a_F1,a_word a_F2); /* findintervalpair */
static void a_1052(a_word a_A[1]); /* findnextnode */
static void a_1053(a_word a_F1,a_word a_A[1]); /* findreallabel */
static void a_1054(void); /* generatearea */
static void a_1055(void); /* generateareas */
static void a_1056(void); /* generatebox */
static void a_1057(void); /* generateextension */
static void a_1058(void); /* generatelabel */
static void a_1059(void); /* generaterulecall */
static void a_1060(a_word a_A[1]); /* getitemdef */
static void a_1061(a_word a_F1,a_word a_A[1]); /* getnodeindex */
static a_word a_1062(a_word a_F1); /* hasoutaffix */
static a_word a_1063=0; /* indexedaffix */
static void a_1064(a_word a_F1,a_word a_A[1]); /* indextonode */
static a_word a_1065(void); /* islimit */
static a_word a_1066(a_word a_F1); /* isnodediscarded */
static a_word a_1067=0; /* localaffixptr */
static a_word a_1068=0; /* loopfound */
static void a_1069(void); /* makerule */
static void a_1070(a_word a_F1); /* marklocalaffix */
static void a_1071(a_word a_F1,a_word a_F2); /* marknode */
static void a_1072(a_word a_F1); /* mergeintervals */
static a_word a_1073(void); /* nodehashdifferent */
static a_word a_1074(a_word a_F1); /* nodewithsamehash */
static void a_1075(void); /* omitemptynodes */
static void a_1076(a_word a_C,a_word *a_V); /* pushBUFFER */
static void a_1077(a_word a_F1,a_word a_F2); /* putnodeflag */
static void a_1078(a_word a_A[2]); /* readareainterval */
static void a_1079(a_word a_F1,a_word a_F2); /* replacelabels */
static void a_1080(a_word a_F1,a_word a_F2); /* replacenlabels */
static void a_1081(void); /* rulelabel */
static void a_1082(void); /* rulesection */
static a_word a_1083(a_word a_F1,a_word a_F2); /* samenodes */
static void a_1084(void); /* scani */
static void a_1085(void); /* scanii */
static void a_1086(void); /* scaniii */
static void a_1087(void); /* scaniv */
static void a_1088(a_word a_F1); /* setnodeflag */
static void a_1089(void); /* setrulehead */
static void a_1090(void); /* skipaffix */
static void a_1091(void); /* skiplist */
static void a_1092(void); /* skiprule */
static void a_1093(void); /* skiprulehead */
static void a_1094(void); /* skiptocomma */
static void a_1095(a_word a_A[1]); /* skiptolabel */
static void a_1096(a_word a_F1,a_word a_F2); /* startlocalaffixcheck */
static void a_1097(void); /* storeaffix */
static void a_1098(void); /* storelimit */
static void a_1099(a_word a_F1); /* storelist */
static void a_1100(a_word a_A[1]); /* storeruleaffix */
static void a_1101(void); /* storeruleaffixes */
static a_word a_1102=0; /* storerulename */
static a_word a_1103=0; /* thisnode */
static void a_1105(a_word a_F1,a_word a_C,a_word *a_V); /* T */
#define a_1106 (a_1033+sizeof_LIST) /* TARGET */
static void a_1107(a_word a_F1); /* Taffix */
static void a_1108(a_word a_A[1]); /* Taffixinner */
static void a_1109(a_word a_F1,a_word a_F2); /* Tbox */
static void a_1110(a_word a_F1,a_word a_F2); /* Textension */
static void a_1111(a_word a_F1,a_word a_F2); /* Tifcondition */
static void a_1112(a_word a_A[1]); /* Tindex */
static void a_1113(a_word a_F1,a_word a_F2); /* Tjumptoareas */
static void a_1114(a_word a_F1,a_word a_F2); /* Tlabel */
static void a_1115(a_word a_F1,a_word a_A[1]); /* Tlimittail */
static void a_1116(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4,a_word a_F5,a_word a_F6,a_word a_F7); /* Trulecall */
static void a_1117(a_word a_F1,a_word a_F2,a_word a_F3); /* Tsingleifcondition */
static void a_1118(a_word a_F1); /* addcallstack */
static void a_1119(void); /* addprofilingcount */
static void a_1120(void); /* addprofilingdef */
static void a_1121(void); /* addtracing */
static void a_1122(a_word a_A[1]); /* argsep */
static void a_1123(a_word a_F1,a_word a_F2,a_word a_A[2]); /* assignmentsource */
static void a_1124(a_word a_F1,a_word a_F2,a_word a_F3); /* blockdeclaration */
static void a_1125(a_word a_F1,a_word a_A[1]); /* boxclassifier */
static a_word a_1126=0; /* calledrule */
static a_word a_1127=0; /* callstack */
static void a_1128(a_word a_A[1]); /* calltracearg */
static void a_1129(a_word a_A[1]); /* calltracecall */
static void a_1130(a_word a_F1); /* charfileinitialization */
static void a_1131(void); /* closetarget */
static void a_1132(void); /* constitem */
static void a_1133(a_word a_F1,a_word a_A[1]); /* countfilearea */
static void a_1134(void); /* datadeclaration */
static void a_1135(a_word a_F1); /* datafileinitialization */
static void a_1136(void); /* datainitialization */
static void a_1137(a_word a_F1,a_word a_F2,a_word a_F3); /* declarecallargs */
static void a_1138(a_word a_F1,a_word a_F2,a_word a_F3); /* declarelocals */
static void a_1139(void); /* deletetarget */
static void a_1140(a_word a_F1,a_word a_F2); /* extensionblock */
static void a_1141(a_word a_A[1]); /* fillitem */
static a_word a_1142(a_word a_A[1]); /* fillrepeater */
static void a_1143(void); /* filltablehead */
static void a_1144(void); /* filltabletail */
static a_word a_1145=0; /* filltotal */
static void a_1146(a_word a_F1,a_word a_F2,a_word a_F3); /* flushbuffer */
static void a_1147(a_word a_F1); /* formalargument */
static void a_1148(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4); /* genassignment */
static void a_1149(void); /* generatefillentries */
static void a_1150(a_word a_F1,a_word a_F2,a_word a_F3); /* gengetaffixno */
static void a_1151(a_word a_F1,a_word a_F2); /* genshiftaffix */
static void a_1152(a_word a_F1,a_word a_F2); /* genwaitfor */
static a_word a_1153(a_word a_F1); /* hasoutaffix */
static a_word a_1154(a_word a_F1); /* iscompletearea */
static a_word a_1155(a_word a_F1); /* isdummyaffix */
static a_word a_1156(a_word a_F1,a_word a_F2,a_word a_F3); /* isrulediscarded */
static void a_1157(a_word a_F1); /* jumptolabel */
static a_word a_1158=0; /* lastprofile */
static void a_1159(a_word a_F1,a_word a_F2); /* listinitialization */
static void a_1160(a_word a_F1); /* localargument */
static a_word a_1161=0; /* moduleroots */
static void a_1162(a_word a_A[1]); /* nextaffix */
static a_word a_1163=0; /* nextnodeidx */
static a_word a_1164(a_word a_F1,a_word a_F2); /* numbersequal */
static void a_1165(void); /* opentarget */
static void a_1166(a_word a_F1,a_word a_A[1]); /* outargs */
static void a_1167(a_word a_F1); /* pidginalttagtail */
static void a_1168(a_word a_F1); /* pidginrepeatblock */
static void a_1169(a_word a_F1,a_word a_F2); /* pidginruleargs */
static void a_1170(a_word a_F1); /* pidginrulecall */
static void a_1171(a_word a_F1); /* printBUFFER */
static void a_1172(a_word a_F1); /* printGOTO */
static void a_1173(a_word a_F1); /* printexternalrepr */
static void a_1174(a_word a_F1); /* printgoto */
static void a_1175(a_word a_F1); /* printint */
static void a_1176(a_word a_F1,a_word a_F2); /* printint1 */
static void a_1177(a_word a_F1,a_word a_F2); /* printintindex */
static void a_1178(void); /* printlabelprefix */
static void a_1179(a_word a_F1); /* printlocallabel */
static void a_1180(a_word a_F1); /* printnlptr */
static void a_1181(a_word a_F1); /* printnumber */
static void a_1182(a_word a_F1); /* printpidginrepr */
static void a_1183(a_word a_F1); /* printptr */
static void a_1184(a_word a_F1); /* printrepr */
static void a_1185(void); /* procwaitfor */
static void a_1186(void); /* profilingdeclaration */
static void a_1187(a_word a_F1); /* pushBUFFER */
static void a_1188(a_word a_F1,a_word a_F2,a_word a_A[1]); /* regularcalld1 */
static void a_1189(a_word a_F1,a_word a_F2); /* regularcalld2 */
static void a_1190(a_word a_F1,a_word a_F2,a_word a_F3); /* regularcalld3 */
static void a_1191(a_word a_F1); /* regularcallpostload */
static void a_1192(a_word a_F1); /* regularcallpreload */
static void a_1193(a_word a_F1); /* regularrulecall */
static void a_1194(a_word a_F1,a_word a_F2,a_word a_F3); /* repeatblockcall */
static void a_1195(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4); /* repeatblockpostload */
static void a_1196(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4); /* repeatblockpreload */
static void a_1197(a_word a_F1); /* rootprototype */
static void a_1198(a_word a_F1,a_word a_F2); /* ruleargs */
static void a_1199(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4,a_word a_F5,a_word a_F6,a_word a_F7,a_word a_F8); /* ruledeclarationhead */
static void a_1200(void); /* ruledeclarationtail */
static void a_1201(a_word a_F1); /* ruleprototype */
static void a_1202(a_word a_F1,a_word a_A[1]); /* ruletyper */
static void a_1203(a_word a_F1); /* showformalsascomment */
static void a_1204(void); /* skipfillinitializer */
static void a_1205(void); /* targetmain */
static a_word a_1206=0; /* targetopened */
static void a_1207(void); /* targetpostlude */
static void a_1208(void); /* targetprelude */
static a_word a_1209=0; /* thisrule */
static void a_1210(a_word a_A[1]); /* untilnextcomma */
static void a_1211(void); /* usecallstack */
static void a_1212(a_word a_F1); /* vardeclaration */
static a_word a_1213=0; /* waitforused */
static a_word a_1215(a_word a_F1); /* E */
#define a_1216 (a_1106+sizeof_CHFILE) /* EXPRESSION */
static a_word a_1217(a_word a_A[1]); /* Eitem */
static a_word a_1218(a_word a_F1,a_word a_A[2]); /* Eop */
static a_word a_1219=0; /* Raddr */
static a_word a_1220=0; /* Rby */
static void a_1221(a_word a_F1); /* checkcalibretype */
static void a_1222(a_word a_F1,a_word a_F2); /* checkconstanttype */
static void a_1223(a_word a_F1); /* checklisttype */
static void a_1224(void); /* clearvirtualspace */
static a_word a_1225=0; /* eptr */
static void a_1226(a_word a_A[1]); /* finalbase */
static void a_1227(a_word a_F1); /* finaleval */
static void a_1228(void); /* finalevaluation */
static void a_1229(a_word a_F1,a_word a_A[1]); /* finalexpr */
static void a_1230(a_word a_F1,a_word a_F2,a_word a_A[1]); /* getexprlimit */
static void a_1231(a_word a_A[1]); /* getitemdef */
static a_word a_1232=0; /* linkexpr */
static a_word a_1233(a_word a_A[1]); /* loosebase */
static void a_1234(a_word a_F1); /* looseeval */
static void a_1235(void); /* looseevaluation */
static a_word a_1236(a_word a_F1,a_word a_A[1]); /* looseexpr */
static void a_1237(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[2]); /* nextvirtualblock */
static void a_1238(a_word a_F1,a_word a_F2,a_word a_F3); /* optor */
static void a_1239(a_word a_F1); /* pushEXPR */
static void a_1240(void); /* readexpression */
static void a_1241(a_word a_F1,a_word a_F2); /* setfinalvalue */
static a_word a_1242(a_word a_F1,a_word a_F2); /* splitvirtualspace */
static void a_1243(a_word a_F1,a_word a_A[1]); /* storenumstring */
static void a_1244(a_word a_F1,a_word a_F2,a_word a_A[1]); /* virtualaddressoffset */
static void a_1246(void); /* assignreprnumbers */
static void a_1247(a_word a_F1,a_word a_F2); /* checkconstanttype */
static void a_1248(a_word a_F1); /* checkfiletype */
static void a_1249(a_word a_F1); /* checkfillconstanttype */
static void a_1250(void); /* checkfillitem */
static void a_1251(a_word a_F1); /* checklisttype */
static void a_1252(a_word a_A[2]); /* collectlistsizeclaims */
static void a_1253(void); /* computepointerconstants */
static void a_1254(void); /* datasectioni */
static void a_1255(void); /* datasectionii */
static void a_1256(void); /* datasectioniii */
static void a_1257(void); /* distributevirtualaddress */
static void a_1258(void); /* externalentry */
static void a_1259(void); /* fileentry */
static a_word a_1260=0; /* filltablesize */
static void a_1261(a_word a_F1,a_word a_F2); /* fixsize */
static a_word a_1262(a_word a_F1,a_word a_A[1]); /* getconstvalue */
static void a_1263(a_word a_F1,a_word a_F2,a_word a_A[1]); /* getestimator */
static void a_1264(a_word a_A[1]); /* getitemdef */
static a_word a_1265=-1; /* linklists */
static void a_1266(void); /* listentry */
static void a_1267(void); /* loosebounds */
static void a_1268(void); /* loosefill */
static void a_1269(a_word a_A[1]); /* loosefillitem */
static void a_1270(a_word a_F1); /* looseinitializer */
static void a_1271(a_word a_F1,a_word a_F2,a_word a_F3); /* looserepeater */
static a_word a_1272=1000; /* nextreprno */
static void a_1273(a_word a_F1); /* readmatter */
static void a_1274(a_word a_F1,a_word a_F2); /* relativesize */
static void a_1275(a_word a_F1); /* rememberlist */
static void a_1276(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]); /* repeatervalue */
static void a_1277(void); /* setlistbounds */
static void a_1278(a_word a_F1); /* setpointervalue */
static void a_1279(a_word a_F1); /* setreprnumber */
static void a_1280(void); /* skipdatasection */
static void a_1281(void); /* skipentry */
static void a_1282(void); /* skipfill */
static void a_1283(a_word a_F1); /* skipfillinitializer */
static void a_1284(void); /* skipfillitem */
static void a_1285(a_word a_F1); /* skipfillrepeater */
#define a_1287 (a_1216+sizeof_LIST) /* AUX */
#define a_1288 (a_1287+sizeof_LIST) /* ITEM */
static void a_1289(void); /* addbuiltinformals */
static void a_1290(a_word a_F2,a_word a_A[1],a_word a_C,a_word *a_V); /* addformalaffixes */
static void a_1291(a_word a_F1,a_word a_F2); /* addmatter */
static void a_1292(void); /* addshiftaffixrules */
static void a_1293(void); /* addstdstring */
static void a_1294(a_word a_A[1]); /* advancemodbase */
static void a_1295(a_word a_F1); /* checkitemID */
static void a_1296(void); /* checkmainmodule */
static void a_1297(void); /* cleanupitems */
static void a_1298(a_word a_F1,a_word a_F2); /* clearitemflag */
static a_word a_1299(a_word a_F1,a_word a_F2); /* compareformals */
static void a_1300(a_word a_A[1]); /* converttoitem */
static a_word a_1301=0; /* doreport */
static void a_1302(void); /* enteritem */
static void a_1303(void); /* expandITEM */
static void a_1304(a_word a_F1,a_word a_A[1]); /* finditemdef */
static void a_1305(a_word a_F1,a_word a_A[3]); /* finditemlineno */
static void a_1306(a_word a_F1,a_word a_A[2]); /* findlineno */
static a_word a_1307=0; /* firstmodule */
static void a_1308(a_word a_F1,a_word a_F2); /* formalaffixes */
static void a_1309(a_word a_F1,a_word a_A[1]); /* getanchorcount */
static void a_1310(a_word a_F1,a_word a_A[1]); /* getcalibre */
static void a_1311(a_word a_F1,a_word a_F2,a_word a_A[1]); /* getfilearea */
static void a_1312(a_word a_F1,a_word a_A[2]); /* getfiledata */
static void a_1313(a_word a_F1,a_word a_A[1]); /* getfill */
static void a_1314(a_word a_F1,a_word a_F2,a_word a_A[1]); /* getformal */
static void a_1315(a_word a_F1,a_word a_A[1]); /* getlistlink */
static a_word a_1316(a_word a_F2,a_word a_A[2]); /* getmatter */
static void a_1317(a_word a_A[1]); /* getnextmodulehead */
static void a_1318(a_word a_F1,a_word a_A[1]); /* getnumberofformals */
static void a_1319(a_word a_F1,a_word a_A[1]); /* getssel */
static void a_1320(a_word a_F1,a_word a_A[1]); /* getvlwb */
static void a_1321(a_word a_F1,a_word a_A[1]); /* getvupb */
static void a_1322(a_word a_F1); /* headsection */
static a_word a_1323(a_word a_F1,a_word a_F2); /* incompatibletypes */
static a_word a_1324(a_word a_F1); /* isassignitem */
static a_word a_1325(a_word a_F1,a_word a_A[1]); /* isbuiltinrule */
static a_word a_1326(a_word a_F1,a_word a_F2); /* isitemflag */
static a_word a_1327(a_word a_F1); /* isrootitem */
static a_word a_1328(a_word a_F1); /* iswaitforitem */
static void a_1329(void); /* itemsection */
static a_word a_1330=0; /* lastmodule */
static a_word a_1331=0; /* linkformals */
static void a_1332(void); /* linkmoduleheader */
static a_word a_1333=0; /* mainmodule */
static a_word a_1334=0; /* makeformals */
static a_word a_1335=0; /* matterlink */
static a_word a_1336=0; /* maxlineno */
static a_word a_1337=0; /* modbase */
static a_word a_1338(a_word a_F1); /* nocallstackrule */
static void a_1339(a_word a_A[1]); /* opennextmodule */
static void a_1340(a_word a_F1); /* pushAUX */
static void a_1341(a_word a_F1,a_word a_F2); /* putfill */
static void a_1342(a_word a_F1,a_word a_F2); /* putlistlink */
static void a_1343(a_word a_F1,a_word a_F2); /* putvlwb */
static void a_1344(a_word a_F1,a_word a_F2); /* putvupb */
static void a_1345(void); /* readdefinitionlist */
static void a_1346(a_word a_F1); /* readfileinfo */
static void a_1347(void); /* readitem */
static void a_1348(a_word a_F1); /* reportitem */
static void a_1349(void); /* reportnotusedpublicitems */
static a_word a_1350=0; /* rootformals */
static void a_1351(a_word a_A[1]); /* scanfordefinitions */
static void a_1352(void); /* scanfordoubledefinitions */
static void a_1353(a_word a_F1); /* scanitem */
static void a_1354(a_word a_F1); /* scanitemfordbledef */
static void a_1355(void); /* scanlinkedmodules */
static void a_1356(a_word a_F1,a_word a_F2,a_word a_A[2]); /* searchforline */
static void a_1357(a_word a_F1,a_word a_A[1]); /* searchformals */
static void a_1358(a_word a_F1,a_word a_F2); /* setitemflag */
static void a_1359(void); /* skipheadsection */
static void a_1360(void); /* skipitemsection */
static a_word a_1361(a_word a_F1,a_word a_F2); /* stacksizemismatch */
static void a_1362(a_word a_A[1]); /* storeformalaffixes */
static void a_1363(a_word a_A[1]); /* storelistbounds */
static a_word a_1364(a_word a_F1,a_word a_F2); /* unequaltypes */
static a_word a_1365=0; /* waitforformals */
#define a_1367 (a_1288+sizeof_LIST) /* REGISTER */
static void a_1368(a_word a_F1,a_word a_A[1]); /* duplregister */
static void a_1369(a_word a_F1); /* freeregister */
static void a_1370(a_word a_F1); /* freeregistersfrommark */
static void a_1371(a_word a_F1,a_word a_A[1]); /* getcstregister */
static void a_1372(a_word a_A[1]); /* getregister */
static a_word a_1373(a_word a_F1); /* istargetconst */
static void a_1374(a_word a_A[1]); /* markregisters */
static void a_1375(a_word a_F1,a_word a_A[1]); /* putcstregister */
static void a_1376(a_word a_F1,a_word a_F2,a_word a_A[1]); /* readregister */
static a_word a_1377(a_word a_F1,a_word a_F2); /* regcompare */
static a_word a_1378(a_word a_F1,a_word a_F2,a_word a_F3); /* regcompare2 */
static void a_1379(a_word a_F1,a_word a_F2,a_word a_F3); /* regoperator */
static a_word a_1380=1; /* targetwordwidth */
static void a_1381(a_word a_F1,a_word a_F2); /* writeregister */
#define a_1384 (a_1367+sizeof_LIST) /* FILES */
static a_word a_1385=0; /* actualptr */
static void a_1386(void); /* adddirseparator */
static void a_1387(void); /* addextension */
static void a_1388(a_word a_F1); /* addincludedicefiles */
static a_word a_1389=1; /* addstdlib */
static a_word a_1390=0; /* argtop */
static void a_1391(void); /* checkcommandlinearguments */
static void a_1392(a_word a_F1); /* extendBUFFER */
static void a_1393(a_word a_F1); /* extendFILES */
static a_word a_1394=0; /* fileno */
static void a_1395(a_word a_A[1]); /* geticefile */
static a_word a_1396(a_word a_A[1]); /* getnextsource */
static void a_1397(void); /* gettargetfile */
static void a_1398(a_word a_F1,a_word a_A[1]); /* handlesourcefile */
static a_word a_1399(a_word a_F1,a_word a_F2); /* isfileflag */
static a_word a_1400(a_word a_F1,a_word a_F2); /* isfirstarg */
static a_word a_1401=0; /* libdir */
static a_word a_1402=0; /* libfile */
static a_word a_1403=0; /* mainfile */
static a_word a_1404(void); /* notstdlibsource */
static a_word a_1405(a_word a_F1,a_word a_A[1]); /* nthpath */
static void a_1406(a_word a_A[1]); /* openBUFFER */
static void a_1407(a_word a_F1); /* openfileaslast */
static void a_1408(a_word a_F1,a_word a_A[1]); /* openfilefirst */
static void a_1409(a_word a_F1); /* opensource */
static a_word a_1410(a_word a_F1); /* selectpath */
static void a_1411(a_word a_F1,a_word a_F2); /* setfileflag */
static void a_1412(a_word a_F1); /* setsource */
static void a_1413(a_word a_F1); /* stringtoBUFFER */
static a_word a_1414=0; /* targetfile */
static void a_1415(a_word a_F1,a_word a_A[1]); /* tryfilefirst */
static void a_1416(a_word a_F1,a_word a_A[1]); /* tryopen */
static void a_1417(a_word a_F1,a_word a_F2,a_word a_A[1]); /* tryopenwithpath */
static a_word a_1418(a_word a_F1,a_word a_A[1]); /* wasicesource */
#define a_1420 (a_1384+sizeof_LIST) /* MESSAGE */
#define a_1421 (a_1420+sizeof_LIST) /* PRINTFILE */
static void a_1422(a_word a_F1,a_word a_F2); /* corrupticefile */
static void a_1423(a_word a_C,a_word *a_V); /* error */
static a_word a_1424=0; /* errorno */
static void a_1425(a_word a_C,a_word *a_V); /* fatalerror */
static void a_1426(a_word a_C,a_word *a_V); /* formatprint */
static void a_1427(a_word a_F1,a_word a_F2); /* internalerror */
static void a_1428(a_word a_C,a_word *a_V); /* message */
static void a_1429(a_word a_F1); /* messagehead */
static void a_1430(void); /* nlcr */
static void a_1431(a_word a_F1,a_word a_F2); /* print */
static void a_1432(a_word a_F1); /* printbase */
static void a_1433(a_word a_F1); /* printchar */
static void a_1434(a_word a_F1); /* printform */
static void a_1435(a_word a_F1,a_word a_F2); /* printform1 */
static void a_1436(a_word a_F1); /* printint */
static void a_1437(a_word a_F1,a_word a_F2); /* printint1 */
static void a_1438(a_word a_F1); /* printitem */
static void a_1439(a_word a_F1); /* printline */
static void a_1440(a_word a_F1); /* printpointer */
static a_word a_1441=0; /* prpos */
static void a_1442(a_word a_F1); /* tabline */
static void a_1443(a_word a_C,a_word *a_V); /* warning */
static a_word a_1444(void); /* waserror */
#define a_1446 (a_1421+sizeof_CHFILE) /* BOLD */
#define a_1447 (a_1446+sizeof_LIST) /* BUFFER */
#define a_1448 (a_1447+sizeof_LIST) /* HASH */
static a_word a_1449=1; /* HASHentries */
static a_word a_1450=1023; /* HASHsize */
#define a_1451 (a_1448+sizeof_LIST) /* LEXT */
#define a_1452 (a_1451+sizeof_LIST) /* SOURCE */
static void a_1453(a_word a_A[1]); /* addLEXTentry */
static a_word a_1454=32; /* char */
static void a_1455(void); /* closesource */
static void a_1456(void); /* comment */
static void a_1457(a_word a_F1,a_word a_A[1]); /* enterstring */
static void a_1458(a_word a_F1); /* extendBUFFER */
static void a_1459(a_word a_F1,a_word a_A[1]); /* gettagdata */
static void a_1460(a_word a_F1,a_word a_A[1]); /* gettagimage */
static a_word a_1461=0; /* inpt */
static a_word a_1462=0; /* inptvalue */
static a_word a_1463=0; /* lastchar */
static a_word a_1464=0; /* lastfilepos */
static a_word a_1465=0; /* lastinpt */
static a_word a_1466=0; /* lastinptvalue */
static void a_1467(void); /* nextchar */
static void a_1468(void); /* nextsymbol */
static void a_1469(a_word a_F1,a_word a_F2); /* puttagdata */
static void a_1470(a_word a_A[1]); /* readbold */
static void a_1471(a_word a_A[1]); /* readdestination */
static void a_1472(a_word a_A[1]); /* readstring */
static void a_1473(a_word a_A[1]); /* readtargetnumber */
static void a_1474(a_word a_A[2]); /* readtargetstring */
static void a_1475(a_word a_A[1]); /* readtype */
static void a_1476(void); /* rehash */
static void a_1477(void); /* restoreinputposition */
static void a_1478(void); /* saveinputposition */
static a_word a_1479=1; /* sourceline */
static void a_1480(a_word a_A[1]); /* trytoopensource */
static a_word a_1481=0; /* xnumber */
static void a_1483(void); /* pass1 */
static void a_1484(void); /* pass2 */
static void a_1485(void); /* pass3 */
static void a_1486(void); /* pass4 */
static void a_1487(void); /* pass5 */
static void a_1490(a_word a_F1,a_word a_F2,a_word a_F3); /* putstring */
#define a_1493 (a_1452+sizeof_CHFILE) /* STDARG */
static void a_1482(void); /* @main root */
static void a_1445(void); /* lexical root */
static void a_1366(void); /* arithmetic root */
static void a_1286(void); /* item root */
static void a_1004(void); /* number root */
#define BLOCK_TOTAL (a_1493+sizeof_LIST)
a_word a_DATABLOCK[BLOCK_TOTAL];
static a_word a_FILL[]={ /* fill table */
a_1001,/* @StringTable */
21,1953723757,0,4,4,1953067617,1952804200,25449,10,5,1702129253,1852793714,1953723507,1735289202,0,16,7,1685349735,1953064809,0,8,5,0,
a_1001,/* @StringTable */
36,1953723757,0,4,4,1885956979,1768318561,120,9,5,1885956979,1634496372,7103842,11,5,1885956979,1868787572,6385005,11,5,1635148897,1852138350,6644847,11,5,1684104562,1634038369,1702129257,1818326642,0,16,7,1701606770,1952671091,7237481,11,5,0,
a_1420,/* MESSAGE */
67,1634038369,544497952,540699685,1702326124,1868701810,543452789,1696625701,1701143416,1965060964,1919250544,1970233888,622879854,116,49,15,1634038369,544497952,540699685,1936287860,1953259808,1634628197,1702259060,1986358816,1931506277,1701012341,7562341,43,13,1953718636,1701994784,1952522337,980165920,1953459744,1819042080,1935762208,1629516645,1663067506,1919252079,25701,42,13,1935764579,1768319347,1769234787,1629515375,1814372468,1818304570,1937334647,1668641568,1684366691,115,37,12,1701606770,544220448,622883937,1763719788,1852401262,543519849,1886351212,1668180256,1768191340,1914726254,543517813,28709,46,14,0,
a_1001,/* @StringTable */
923,1953723757,0,4,4,29221,2,3,1130324268,1449091372,0,8,5,628967205,7218503,7,4,1193638697,125,5,4,31529,2,3,2647657,3,3,556295785,0,4,4,1668113773,1630042480,1630295647,623592543,1600203876,1680157251,2053731114,677801829,690583333,59,37,12,1147101501,1566844251,59,9,5,1348428093,1566844251,59,9,5,693133153,0,4,4,2650661,3,3,1630299173,623595615,10596,10,5,1630299173,2707551,7,4,725835617,1630299173,2704479,11,5,742612833,693526369,0,8,5,5267297,3,3,1668113773,1630042480,623592543,1600203876,1600203862,1680157251,2053731114,677801829,690583333,59,37,12,1531207521,1029530661,0,8,5,1531993953,1029530661,0,8,5,678588262,809332773,1013982523,994271073,724267045,1449091369,1567630683,997205309,0,32,11,997205309,0,4,4,7349548,3,3,1734701691,1702130537,1998921842,1030759712,0,16,7,1734701691,1702130537,1998921842,997205280,0,16,7,622869289,71,5,4,1130324285,625419579,110,9,5,1847936805,0,4,4,1735288167,1717662821,1853385062,111,13,6,1630037609,1027359583,628828465,1629519207,757941087,1449091387,1680162091,7218491,31,10,1630037609,826164063,1600224041,992816451,727080801,996418877,545081125,1847936805,0,32,11,622864943,791289968,625419579,110,13,6,123,1,3,1730509609,7218557,7,4,622885673,1847950695,0,8,5,677800224,0,4,4,628828457,1847950695,0,8,5,6759712,3,3,1635461417,1701994847,1634099041,1684368489,1918853416,1852140661,744844641,992571429,7218557,35,11,677800224,10273,6,4,31868,2,3,1014244648,544220477,622863910,624770160,10612,18,7,1027502117,29733,6,4,1027371045,29733,6,4,1027436581,29733,6,4,7218491,3,3,1768383858,1919251571,544679200,4026405,15,6,1281322868,676614985,757690405,1886740798,624765794,628964196,110,25,9,1734701691,1702130537,1998921842,1881483808,1700749629,1852142712,1852795251,745547048,992568357,0,36,12,626749477,4021604,7,4,1566844205,0,4,4,93,1,3,1281322868,676614985,757690405,1717989182,1534354803,0,20,8,744760620,1970429793,1634624876,1562994029,0,16,7,2912293,3,3,1281322868,676614985,757690405,1717989182,1534354803,1768709985,1818588275,2649445,31,10,1835625556,1635021929,27753,10,5,1281322868,676614985,757690405,7349566,15,6,28709,2,3,627516704,110,5,4,1847933737,0,4,4,1952407840,1701011826,1819636319,1600202853,1701606770,1701667182,6563116,27,9,1348428070,996418886,28197,10,5,1280070990,7218491,7,4,1380999009,1279870543,1630150725,1869770847,1701603686,15731,22,8,1885298976,1768320882,1735289196,1348428072,694428998,7218491,23,8,1919967073,1818846831,1701076837,1600202854,1680164432,1881481772,1629891618,625365087,624634212,110,37,12,1919967073,1818846831,1701076837,1600202854,1680164432,1881481772,1431186466,992562252,28197,34,11,707731581,544220448,1847930666,0,12,6,1635021600,543385972,1936617315,1751326836,706769505,1970429793,1634624876,574449005,992112677,28197,38,12,623847968,110,5,4,707731579,7349536,7,4,706770725,1027891041,1869376609,1932026211,1868921449,1998923878,623389225,1680157540,1130324266,3877161,39,12,1629517605,626741343,3890532,11,5,1629517605,1680165983,59,9,5,16427,2,3,1713513003,0,4,4,1935498027,6118260,7,4,1566274603,0,4,4,1046560299,0,4,4,4088107,3,3,6372907,3,3,1735549300,1634563173,28265,10,5,1847933737,7218557,7,4,678569248,0,4,4,691022896,7218491,7,4,2002739488,1718905185,2650735,11,5,1683972384,1600222305,1970562419,992553072,28197,18,7,1633640736,1869898852,1818321759,1635021676,1650420579,1869902959,992553069,28197,30,10,1684631414,1381982496,676613967,1684631414,1847950121,0,20,8,7218557,3,3,1298096416,1330791503,623400015,622996594,623452784,110,21,8,1633640736,1869898852,1818321759,1635021676,573074275,1953063287,577924966,1847933737,0,32,11,1629517605,741426783,1629517605,691160671,7218555,19,7,1952543859,1981834089,543451503,1635213153,1868985449,10354,22,8,1818190112,1601467241,1819044198,1180655912,692866121,2104370491,28197,26,9,1985962272,1970565737,1834970209,624782953,1600207728,1953655158,1600938357,1031299437,624652325,110,37,12,1952543859,1981834089,543451503,1633967969,1935630708,1886745701,1768912424,628828516,110,33,11,1629495328,1684300127,1818846815,1701994853,1915037793,745678124,992568357,539635488,706768933,7218479,39,12,1935630624,1886745701,1768318047,623404396,622996594,623649392,1915038820,745678124,992568357,539635488,706768933,7218479,47,14,1935630624,1886745701,1634231135,1818846834,1915037797,1881481772,1680157730,745678124,992571941,539635488,706768933,7218479,47,14,678438176,573338149,690122789,7218491,15,6,1935630624,1886745701,1936288863,1680156788,745678124,577774882,744760620,623670309,1680157812,790641449,1881481258,623847968,110,49,15,678438176,573338149,740454437,992568357,28197,18,7,1847929904,0,4,4,744760621,28197,6,4,791441957,1881481258,623847968,110,13,6,2909221,3,3,1769238133,2019913324,1836016500,24941,14,6,998060333,539635488,1819044198,1650553888,1931502956,543521385,706765861,7218479,31,10,1952543859,622879593,1600200823,1280067910,2067619163,539635488,1819044198,1650553888,706766188,7218479,39,12,1629517605,1413563487,1330397761,626740035,624647536,110,21,8,1717920803,543518313,673214501,623604261,1847929200,0,20,8,1717920803,543518313,807432229,28197,14,6,707731515,544220448,1953460082,623847968,110,17,7,707731515,1634549792,1914728041,544501615,1847930666,0,20,8,707731515,544220448,1847930666,0,12,6,707731497,544220448,1847930666,0,12,6,623604261,112,5,4,48,1,3,1717920803,543518313,673215013,0,12,6,1952543859,622879593,1915035767,997467453,539635488,706768933,7218479,27,9,1684631414,0,4,4,1629517605,1680164447,0,8,5,1629517605,623657823,1630150775,2709087,15,6,1629517605,626737503,23908,10,5,1952543859,1981834089,543451503,2650661,15,6,1952543859,622879593,1915035767,40,13,6,1159735855,706758223,7218479,11,5,1847948069,0,4,4,1717920803,543518313,1094934369,1398754380,1262698836,1130324256,1598835777,1128354899,7218507,35,11,622866223,622993520,1847927408,0,12,6,1075851055,1852399981,1881481760,7218466,15,6,1092626991,1213220172,1701013792,1852402720,544367979,778315126,539780133,1685221239,2053731104,1680162149,623847968,795747694,1768693807,1684368238,1685024032,1936026741,7218490,67,19,1633640736,1869898852,1818321759,1635021676,1630038883,1819636319,1835101797,624634213,110,33,11,1969185056,1702065518,1633902436,1953721452,678126433,1970429793,1634624876,992568685,28197,34,11,1281319206,29300,6,4,1094934369,544230476,1920229217,0,12,6,774778459,93,5,4,1870094177,25714,6,4,1852404336,1920233588,0,8,5,1819635291,23916,6,4,1852404336,1179992692,5391686,11,5,1953457952,8303,6,4,1952805408,544109173,15152,10,5,1952805408,997094005,0,8,5,1952805408,544109173,15153,10,5,1885695073,6499944,7,4,0,
a_1420,/* MESSAGE */
14,1852727651,1663071343,1952540018,1635000421,1952802674,1818846752,2015699045,1919229996,544370546,1701080931,1680154682,0,44,14,0,
a_1420,/* MESSAGE */
22,1702521203,1281320559,5526345,11,5,1702521203,1130325615,1279870536,69,13,6,1702521203,1147102831,1162627398,0,12,6,1129270338,1330929483,4997460,11,5,0,
a_1420,/* MESSAGE */
15,1701606770,1767995168,1919903348,1852776506,1696627052,2037674093,1685024032,543517813,1953460082,1847602291,1847620719,1701078373,100,49,15,0,
a_1420,/* MESSAGE */
28,1768710499,6648418,7,4,1651993697,0,4,4,1651537249,0,4,4,1651993718,0,4,4,1651537270,0,4,4,829579105,0,4,4,846356321,0,4,4,0,
a_1001,/* @StringTable */
45,1953723757,0,4,4,1634625894,1635149164,108,9,5,1634625894,1935762028,101,9,5,1936682860,1635149157,108,9,5,1684104562,1919973477,1769173861,28271,14,6,1667590243,1852793707,1851880563,1887007860,101,17,7,1667590243,1818321771,1701995113,1701869940,0,16,7,1667590243,1936288875,1887007860,101,13,6,0,
a_1420,/* MESSAGE */
14,540700709,1936617315,1953390964,1717920800,1953066601,544108393,1701209458,1948283762,1953046639,1718379891,1764042784,41,45,14,0,
a_1001,/* @StringTable */
84,1953723757,0,4,4,1920230771,1852993637,1700949365,114,13,6,1635017060,1952671091,1768845161,26985,14,6,1702131813,1818324594,1920233061,121,13,6,1635017060,1952671091,1768845161,105,13,6,1953720684,1920233061,121,9,5,1885956979,1819044198,1953066601,1768710505,7497082,19,7,1667590243,1818846827,1887007845,101,13,6,1667590243,1818846827,1852793708,1851880563,1887007860,101,21,8,1667590243,1852793707,1851880563,1887007860,101,17,7,1667590243,1936288875,1887007860,101,13,6,1635017060,1952671091,1768845161,0,12,6,1885956979,1635017060,1952671091,7237481,15,6,1885956979,1920233061,121,9,5,0,
a_1420,/* MESSAGE */
16,1713401893,980184169,1885696544,1702125925,1868767346,1635021678,622883950,1936269412,1953853216,543584032,1735287154,1831346277,622884961,10596,54,16,0,
a_1420,/* MESSAGE */
40,540700709,1634493810,1702259060,2053731104,1936007269,1634560372,544370548,1763730469,1970217075,1718558836,1851879968,673211751,2713893,51,15,540700709,1702521203,1953719584,1952542057,622883439,1936269412,1953853216,544370464,1735287154,623386725,10601,42,13,540700709,1702521203,1953719584,1952542057,622883439,1634214000,1869488243,1818326560,673211765,2713893,39,12,0,
a_1420,/* MESSAGE */
33,1819044198,543649385,540700709,622883937,1701978220,1952540016,622883429,1936269424,1953459744,1717920800,1684369001,0,44,14,1819044198,543649385,1629515813,1814372468,1635131450,543520108,1864393765,1701978214,1952540016,622883429,1936269424,1953853216,543584032,1735287154,1831346277,622884961,10596,66,19,0,
a_1420,/* MESSAGE */
9,1970499177,1667851878,1953391977,1919514144,1818326388,1634759456,25955,26,9,0,
a_1001,/* @StringTable */
37,1953723757,0,4,4,1851876211,1835365481,0,8,5,1684104552,1952671091,7237481,11,5,1684104562,1768318308,1769236846,1768713839,29811,18,7,1684104562,1835365481,0,8,5,1667590243,1702127979,4475245,11,5,1836216166,1717660769,1702390118,115,13,6,0,
a_1451,/* LEXT */
50,1920226112,1416064617,1701601889,0,12,6,0,0,1718184051,1717985652,1818392681,7037807,15,6,0,0,1635018087,2020173414,1668246626,7302763,15,6,0,0,1635205184,1868985449,114,9,5,0,0,1634549824,25963,6,4,0,0,1869574720,116,5,4,0,0,1801675106,1667330676,107,9,5,0,0,0,
a_1420,/* MESSAGE */
22,1701998445,1634235424,1852776558,1634541669,1830841961,1819632751,622869093,112,29,10,1886220131,1684368489,1919903264,1718182944,1701995878,1948284014,1701278305,1870078068,1931502706,6650473,39,12,0,
a_1420,/* MESSAGE */
43,1830842222,544106849,1969516397,25964,14,6,540700709,544501614,1768318308,543450478,622883937,105,21,8,540700709,1868787305,1952542829,1701601897,1887007776,1629516645,1764040820,1684955424,6890784,35,11,540700709,1651863396,1679849836,1852401253,1629512805,1764040820,1684955424,6890784,31,10,540700709,544501614,1701209458,1668179314,622879845,105,21,8,0,
a_1001,/* @StringTable */
9,1953067617,1952804200,25449,10,5,1869771365,114,5,4,0,
a_1451,/* LEXT */
44,1818308398,795373669,1768191091,792356195,796029813,1633906540,1818308460,795373669,1768191091,25955,38,12,0,0,1818522739,25193,6,4,0,0,926365233,909193783,0,8,5,0,0,808661298,875966519,12851,10,5,0,0,1668180259,1701082476,1818305056,1600680037,1701998435,2254894,23,8,0,0,0,
a_1420,/* MESSAGE */
188,1802398028,1162625312,1294813264,1667837472,1768300645,544433516,1629515636,1881162528,1919381362,623799649,1634948462,540697959,1852402785,760946795,1818585133,763109488,1919252013,1852795251,544089437,1919885344,1818304570,543911529,1953525595,1936617321,1768300637,540108140,1701603686,774774834,1332618542,1869182064,624587630,757080174,1950097519,1701278305,538984052,538976288,543516788,1886680431,773878901,1768300643,1847944556,1278025760,1768176672,538984050,538976288,1931485216,1768711284,1768169570,1952671090,628716143,757080174,1932357486,1768711284,538976354,538976288,661548900,1684086900,1953701988,1633971809,1814062194,1634886249,1847949682,1462575136,538976288,538976288,538976288,1914708000,1919905893,1869488244,1937055860,1881171045,1768710773,1953046627,628321637,757080174,538976359,538976288,538976288,538976288,1802398060,1953068832,1633886312,1931504748,1801675124,1718511904,1634562671,1852795252,1716088357,544173600,1886680431,1763734645,1886593139,1718182757,744777065,1701344288,1835101728,1718558821,1701344288,1767992608,1764630638,1713399139,543517801,1847948137,1684370293,1953068832,1663967336,1954047264,1769172581,1629515375,1730176110,1919250021,1684370529,544106784,543516788,1920103779,544501349,1701996900,1919906915,11897,474,121,1346718785,541928776,1802398060,1981837925,1769173605,622882415,1680158308,1866690085,1769109872,544499815,539575080,808595506,842019373,1632378932,1869380211,1769161504,2053205362,1750363685,1763734377,543236211,1701147238,1718580000,1918990196,1931488357,1948280165,1931502952,1668445551,1952522341,1953785888,792359792,1953064751,778204520,795701091,1769169772,2053205362,1701601583,1847945328,544370534,2037411683,1751607666,1852383348,1836216166,1869182049,1411395182,1701995880,544434464,1461735246,1095914049,995710030,1953459744,1702257952,1701650542,1851877475,1768057204,2037672300,628256544,1953064558,1936942446,1919903264,1881170208,1769239137,1634497891,1970282610,1936683122,11877,258,67,0,
a_1001,/* @StringTable */
42,1953723757,0,4,4,1852141679,1701603686,1634497377,29811,14,6,1769108595,1869899630,1179014466,21061,14,6,26413,2,3,22317,2,3,19501,2,3,28461,2,3,762277421,1818522739,25193,10,5,1702243629,1869181810,110,9,5,1701326125,28780,6,4,0,
a_1420,/* MESSAGE */
57,1763733358,1953853550,1818846752,1886593125,1718182757,744777065,1702065440,1747791136,544238693,544370534,1752375393,544502383,1886152040,0,52,16,1936943469,543649385,1969713761,1953391981,1952866592,757101157,25381,26,9,1769496941,544044397,1651340654,1864397413,1869815910,1701016181,623386739,1696606564,1701143416,6579556,39,12,1869771365,1886330994,1852403301,1764630631,1713399139,543517801,2125861,27,9,1700949349,1684366436,1852385056,1685417059,1763714917,1713399139,1936026729,544106784,28709,34,11,0,
a_1001,/* @StringTable */
36,1953723757,0,4,4,774778459,93,5,4,6111067,3,3,1685024040,543517813,0,8,5,1852404336,1935762036,101,9,5,1852404336,1768910964,1919251566,0,12,6,1280659035,23884,6,4,1953709116,1953853284,15934,10,5,0,
a_1420,/* MESSAGE */
41,544173940,2037277037,1920099616,745763439,1920296480,1919248500,1936026912,1701273971,1918967923,1970479205,1701998704,1684370291,0,48,15,1702129257,1818324594,1920099616,1629516399,1970413684,2123116,23,8,1650532396,1702130287,100,9,5,540700709,1920102243,544501877,1701013806,1818846752,2629733,23,8,1629498409,1953656674,25701,10,5,0,
a_1001,/* @StringTable */
51,1954047342,1651341683,27759,10,5,1684104562,1701869940,0,8,5,1684104562,1684828002,0,8,5,1684104562,1735549300,1953723493,1735289202,0,16,7,1684104562,1769108595,26478,10,5,1634231666,26739,6,4,1684104562,1953719652,1952542313,7237481,15,6,1684104562,1701080681,120,9,5,1885695073,1667837544,101,9,5,1953723757,0,4,4,0,
a_1451,/* LEXT */
5,0,0,3,0,0,0,
a_1446,/* BOLD */
270,1634038369,0,4,4,1801675106,0,4,4,7892834,3,3,1768710499,6648418,7,4,1919973477,1769173861,28271,10,5,1702131813,1869181806,110,9,5,1702131813,1818324594,0,8,5,1701603686,0,4,4,1819044198,0,4,4,1852797542,116,5,4,1818455657,6644853,7,4,1953720684,0,4,4,6453100,3,3,1852399981,0,4,4,1969516397,25964,6,4,1701080942,0,4,4,1701606770,0,4,4,28532,2,3,6451317,3,3,1651993718,0,4,4,1651537270,0,4,4,1936617315,1953390964,0,8,5,1769103734,1701601889,0,8,5,1952543859,1981834089,29281,10,5,1818386804,101,5,4,1667331187,107,5,4,1952543859,1931502441,1801675124,0,12,6,1852403568,544367988,1936617315,1953390964,0,16,7,1918986339,1701603686,0,8,5,1635017060,1701603686,0,8,5,1701606770,0,4,4,1836216166,1931504737,1801675124,0,12,6,1836216166,1948281953,1701601889,0,12,6,1836216166,1713400929,6646889,11,5,1836216166,1763732577,110,9,5,1836216166,1864395873,29813,10,5,1836216166,1763732577,1953853294,0,12,6,1836216166,1629514849,1869112174,114,13,6,1836216166,1931504737,1952868712,0,12,6,64,1,3,38,1,3,93,1,3,41,1,3,58,1,3,44,1,3,126,1,3,47,1,3,45,1,3,35,1,3,40,1,3,124,1,3,62,1,3,43,1,3,46,1,3,59,1,3,42,1,3,91,1,3,94,1,3,1936617315,116,5,4,1651340654,29285,6,4,1701869940,0,4,4,1701080942,0,4,4,1835365481,0,4,4,1836216166,27745,6,4,1633906540,108,5,4,1769108595,26478,6,4,2763306,3,3,0,
-1}; /* fill table size 2349 */
static void a_data_setup(void){
 a_virtual_min=16777216;a_virtual_max=2130706432;
 a_setup_list(0,a_1001,"@StringTable",1,2130705081,2130706364,1284); /* @StringTable */
 a_setup_list(1,a_1005,"NUMBER",1,2075075426,2130705079,0); /* NUMBER */
 a_setup_list(1,a_1032,"NODE",6,1769111715,2047259979,0); /* NODE */
 a_setup_list(1,a_1033,"ZONE",3,2047260598,2075075422,0); /* ZONE */
 a_setup_list(1,a_1216,"EXPRESSION",1,1574407920,1769111708,0); /* EXPRESSION */
 a_setup_list(1,a_1287,"AUX",6,739963102,1018111366,0); /* AUX */
 a_setup_list(1,a_1288,"ITEM",7,1018111379,1574407912,0); /* ITEM */
 a_setup_list(1,a_1367,"REGISTER",1,155851628,183666454,0); /* REGISTER */
 a_setup_list(1,a_1384,"FILES",3,128036800,155851624,0); /* FILES */
 a_setup_list(0,a_1420,"MESSAGE",1,2047259986,2047260594,609); /* MESSAGE */
 a_setup_list(0,a_1446,"BOLD",1,16777217,16777486,270); /* BOLD */
 a_setup_list(1,a_1447,"BUFFER",1,72407143,128036796,0); /* BUFFER */
 a_setup_list(1,a_1448,"HASH",1,16777488,72407141,0); /* HASH */
 a_setup_list(1,a_1451,"LEXT",2,183666457,739963094,99); /* LEXT */
 a_setup_stdarg(a_1493,"STDARG",1);
 a_setup_charfile(a_1106,"TARGET",2,a_1001,2130706060); /* TARGET */
 a_setup_charfile(a_1421,"PRINTFILE",2,a_1001,2130706313); /* PRINTFILE */
 a_setup_charfile(a_1452,"SOURCE",1,a_1001,2130706360); /* SOURCE */
 a_list_fill(a_FILL);
}
static void a_waitfor(a_word a_F1,a_word a_F2){
 a_MODROOT(a_1445,"lexical")
 a_MODROOT(a_1366,"arithmetic")
 a_MODROOT(a_1286,"item")
 a_MODROOT(a_1004,"number")
}
void a_ROOT(void){
 a_data_setup();
 a_waitfor(0,0);
 a_1482();
}
static void a_1009(a_word a_F1){ /* extendBUFFER+>a */

{register a_word *a_r1=a_extension(a_1447,1);a_r1[0]=a_F1;to_LIST(a_1447)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1017(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* loadregister+>a+>a+a> */
a_word a_P[1];
if(!a_equal(a_F1,0)){ goto a_G3;}
a_1376(a_1005,a_F2,a_P);a_A[0]=a_P[0]; return;
a_G3:if(!a_equal(a_F1,2)){ goto a_G5;}
a_1368(a_F2,a_P);a_A[0]=a_P[0]; return;
a_G5:a_1375(a_F2,a_P);a_A[0]=a_P[0]; return;
} /* loadregister */
static a_word a_1023(a_word a_F1){ /* samenumberblock+>a */
a_word a_L2;a_word a_L3;
a_L2=to_LIST(a_1005)->aupb;
a_L3=0;
a_G3:if(a_mreq(a_L3,a_1380)){ return 1;}
if(!a_equal(to_LIST(a_1005)->offset[a_F1],to_LIST(a_1005)->offset[a_L2])){ return 0;}
a_incr(a_L3);
a_decr(a_F1);
a_decr(a_L2); goto a_G3;
} /* samenumberblock */
static void a_1024(a_word a_F1,a_word a_A[1]){ /* storeregister+>a+a> */
a_word a_L3;a_word a_L4;
a_L3=to_LIST(a_1005)->aupb;
a_A[0]=a_1027;
a_L4=0;
a_1381(a_F1,a_1005);
a_G5:if(a_more(a_A[0],a_L3)){ return;}
if(!a_1023(a_A[0])){ goto a_G8;}
a_unstackto(a_1005,a_L3); return;
a_G8:if(!a_more(a_L4,100)){ goto a_G10;}
a_A[0]=to_LIST(a_1005)->aupb; return;
a_G10:a_incr(a_L4);
a_add(a_A[0],a_1380,a_A[0]); goto a_G5;
} /* storeregister */
static void a_1012(a_word a_A[1]){ /* getnumberzero+a> */

a_A[0]=a_1027; return;
} /* getnumberzero */
static void a_1014(a_word a_F1,a_word a_A[1]){ /* gettargetnumbervalue+>a+a> */
a_word a_L3;a_word a_P[1];
a_1376(a_1005,a_F1,a_P);a_L3=a_P[0];
a_1371(a_L3,a_P);a_A[0]=a_P[0]; return;
} /* gettargetnumbervalue */
static void a_1010(a_word a_F1,a_word a_A[1]){ /* getdigit+>a+a> */

{register a_word a_r1=to_LIST(a_1447)->offset[a_F1];
 if(!((48<=a_r1 && a_r1<=57))){ goto a_G3;}
}
a_subtr(to_LIST(a_1447)->offset[a_F1],48,a_A[0]); return;
a_G3:a_1427(a_1001,2130705101); return;
} /* getdigit */
static void a_1006(a_word a_F1,a_word a_F2){ /* adddigit+>a+>a */
a_word a_L3;a_word a_P[1];
a_1375(10,a_P);a_L3=a_P[0];
a_1379(8,a_L3,a_F1);
a_1375(a_F2,a_P);a_L3=a_P[0];
a_1379(6,a_L3,a_F1); return;
} /* adddigit */
static void a_1007(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* enterconststring+>a+>a+a> */
a_word a_L4;a_word a_L5;a_word a_P[1];
a_1375(0,a_P);a_L4=a_P[0];
a_G2:a_incr(a_F2);
if(a_more(a_F2,to_LIST(a_1447)->aupb)){ goto a_G13;}
a_1010(a_F2,a_P);a_L5=a_P[0];
if(!a_1378(21,a_L4,a_1018)){ goto a_G7;}
a_G6:a_1006(a_L4,a_L5); goto a_G2;
a_G7:if(!a_1378(21,a_L4,a_1018)){ goto a_G9;}
a_G8:a_1422(a_1001,2130705096); return;
a_G9:if(a_less(a_L5,a_1016)){ goto a_G6;}
if(a_less(a_L5,a_1016)){ goto a_G8;}
if(!a_is(a_F1)){ goto a_G8;}
if(a_equal(a_F2,to_LIST(a_1447)->aupb)){ goto a_G6;} goto a_G8;
a_G13:if(!a_is(a_F1)){ goto a_G15;}
a_1379(5,a_L4,a_L4);
a_G15:a_1024(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* enterconststring */
static void a_1011(a_word a_F1){ /* getnumberrepr+>a */
a_word a_L2;a_word a_P[1];
a_1376(a_1005,a_F1,a_P);a_L2=a_P[0];
if(!a_1378(23,a_1022,a_L2)){ goto a_G11;}
a_1369(a_L2);
a_1009(40);
a_1009(45);
a_1009(49);
a_1009(45);
a_1368(a_1021,a_P);a_L2=a_P[0];
a_1013(a_L2);
a_1009(41); return;
a_G11:if(!a_1377(11,a_L2)){ goto a_G14;}
a_1379(5,a_L2,a_L2);
a_1009(45);
a_G14:a_1013(a_L2); return;
} /* getnumberrepr */
static void a_1013(a_word a_F1){ /* getregisterrepr+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_1368(a_F1,a_P);a_L2=a_P[0];
a_1375(10,a_P);a_L3=a_P[0];
a_1379(9,a_L3,a_L2);
if(a_1377(10,a_L2)){ goto a_G7;}
a_1368(a_L2,a_P);a_L3=a_P[0];
a_1013(a_L3);
a_G7:a_1375(10,a_P);a_L3=a_P[0];
a_1379(8,a_L3,a_L2);
a_1379(7,a_L2,a_F1);
a_1371(a_F1,a_P);a_L3=a_P[0];
a_add(a_L3,48,a_L3);
a_1009(a_L3); return;
} /* getregisterrepr */
static a_word a_1019(a_word a_F1,a_word a_F2){ /* minmaxregisters+>a+>a */

if(!a_1378(23,a_F1,a_1022)){ return 0;}
if(!a_1378(23,a_F2,a_1021)){ return 0;} return 1;
} /* minmaxregisters */
static void a_1008(a_word a_F1,a_word a_A[2]){ /* entertargetstring+>a+a>+a> */
a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[1];
a_subtr(to_LIST(a_1447)->aupb,a_F1,a_L4);
a_packstring(a_1447,a_L4,a_1451);
a_copystring(a_1451,to_LIST(a_1451)->aupb,a_1447);
a_unstackstring(a_1451);
a_stringwidth(a_1447,to_LIST(a_1447)->aupb,a_A[0]);
a_L5=a_A[0];
a_G7:if(!a_less(a_L5,1)){ goto a_G9;}
a_A[1]=to_LIST(a_1005)->aupb; return;
a_G9:a_1017(1,to_LIST(a_1447)->offset[to_LIST(a_1447)->aupb],a_P);a_L6=a_P[0];
a_1381(a_L6,a_1005);
a_decr(a_L5);
a_unstack(a_1447); goto a_G7;
} /* entertargetstring */
static void a_1020(a_word a_A[2]){ /* nexttargetstringvalue+>a>+a> */
a_word a_L3;
if(!a_more(a_A[0],1)){ goto a_G7;}
a_decr(a_A[0]);
a_L3=to_LIST(a_1005)->aupb;
a_subtr(a_L3,a_1380,a_L3);
a_unstackto(a_1005,a_L3);
a_A[1]=to_LIST(a_1005)->aupb; return;
a_G7:if(!a_equal(a_A[0],1)){ goto a_G12;}
a_decr(a_A[0]);
a_L3=to_LIST(a_1005)->aupb;
a_subtr(a_L3,a_1380,a_L3);
a_unstackto(a_1005,a_L3);
a_G12:a_A[1]=0; return;
} /* nexttargetstringvalue */
static void a_1015(void){ /* initializenumbers */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
a_1375(0,a_P);a_L1=a_P[0];
a_1381(a_L1,a_1005);
a_1027=to_LIST(a_1005)->aupb;
a_1375(0,a_P);a_1021=a_P[0];
a_1375(1,a_P);a_L1=a_P[0];
a_L3=1;
a_G7:if(a_mreq(a_L3,32)){ goto a_G13;}
a_1368(a_L1,a_P);a_L2=a_P[0];
a_1379(3,a_L2,a_1021);
a_1368(a_L1,a_P);a_L2=a_P[0];
a_1379(6,a_L2,a_L1);
a_incr(a_L3); goto a_G7;
a_G13:a_1368(a_L1,a_P);a_1022=a_P[0];
a_1369(a_L1);
a_1368(a_1021,a_P);a_1018=a_P[0];
a_1375(10,a_P);a_L2=a_P[0];
a_1379(9,a_L2,a_1018);
a_1368(a_1018,a_P);a_L2=a_P[0];
a_1375(10,a_P);a_L1=a_P[0];
a_1379(8,a_L1,a_L2);
a_1368(a_1021,a_P);a_L1=a_P[0];
a_1379(7,a_L2,a_L1);
a_1371(a_L1,a_P);a_1016=a_P[0];
a_incr(a_1016);
a_1024(a_1022,a_P);a_1026=a_P[0];
a_1024(a_1021,a_P);a_1025=a_P[0]; return;
} /* initializenumbers */
static void a_1004(void){ /* @root */

 a_waitfor(a_1001,2130705089); a_1015(); return;
} /* @root */
static void a_1082(void){ /* rulesection */

a_G1:if(!a_equal(16777285,a_1461)){ goto a_G4;}
a_1468();
a_1069(); goto a_G1;
a_G4:if(!a_equal(16777486,a_1461)){ goto a_G6;}
a_1468(); return;
a_G6:a_1422(a_1001,2130705137); return;
} /* rulesection */
static void a_1092(void){ /* skiprule */

a_G1:if(!a_equal(16777439,a_1461)){ goto a_G3;}
a_G2:a_1468(); return;
a_G3:if(a_equal(16777486,a_1461)){ goto a_G2;}
a_1468(); goto a_G1;
} /* skiprule */
static void a_1060(a_word a_A[1]){ /* getitemdef+>a> */

if(!a_1326(a_A[0],8)){ return;}
a_A[0]=to_LIST(a_1288)->offset[a_A[0]]; return;
} /* getitemdef */
static void a_1051(a_word a_F1,a_word a_F2){ /* findintervalpair+>a+>a */
a_word a_L3;
if(a_1378(22,a_F2,to_LIST(a_1033)->offset[a_F1-1])){ return;}
a_L3=to_LIST(a_1033)->offset[a_F1];
to_LIST(a_1033)->offset[a_F1-1]=a_F2;
a_G4:if(!a_equal(a_L3,0)){ goto a_G6;}
to_LIST(a_1033)->offset[a_F1]=0; return;
a_G6:if(!a_1378(21,a_F2,to_LIST(a_1033)->offset[a_L3-2])){ goto a_G8;}
to_LIST(a_1033)->offset[a_F1]=a_L3; return;
a_G8:if(!a_1378(22,a_F2,to_LIST(a_1033)->offset[a_L3-1])){ goto a_G11;}
to_LIST(a_1033)->offset[a_F1-1]=to_LIST(a_1033)->offset[a_L3-1];
to_LIST(a_1033)->offset[a_F1]=to_LIST(a_1033)->offset[a_L3]; return;
a_G11:a_L3=to_LIST(a_1033)->offset[a_L3]; goto a_G4;
} /* findintervalpair */
static void a_1035(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]){ /* addinterval+>a+>a+>a+>a> */
a_word a_L5;
a_G1:a_L5=to_LIST(a_1033)->offset[a_F1];
if(!a_equal(a_L5,0)){ goto a_G6;}
a_A[0]=1;
{register a_word *a_r1=a_extension(a_1033,3);a_r1[0]=a_F2;a_r1[1]=a_F3;a_r1[2]=0;to_LIST(a_1033)->aupb+=3;}
a_G5:to_LIST(a_1033)->offset[a_F1]=to_LIST(a_1033)->aupb; return;
a_G6:if(!a_1378(21,a_F2,to_LIST(a_1033)->offset[a_L5-2])){ goto a_G12;}
a_A[0]=1;
if(!a_1378(21,a_F3,to_LIST(a_1033)->offset[a_L5-2])){ goto a_G10;}
{register a_word *a_r1=a_extension(a_1033,3);a_r1[0]=a_F2;a_r1[1]=a_F3;a_r1[2]=a_L5;to_LIST(a_1033)->aupb+=3;}
  goto a_G5;
a_G10:to_LIST(a_1033)->offset[a_L5-2]=a_F2;
a_G11:a_1051(a_L5,a_F3); return;
a_G12:if(!a_1378(22,a_F2,to_LIST(a_1033)->offset[a_L5-1])){ goto a_G15;}
if(a_1378(22,a_F3,to_LIST(a_1033)->offset[a_L5-1])){ return;}
a_A[0]=1; goto a_G11;
a_G15:a_F1=a_L5; goto a_G1;
} /* addinterval */
static void a_1072(a_word a_F1){ /* mergeintervals+>a */
a_word a_L2;
a_G1:if(a_equal(to_LIST(a_1033)->offset[a_F1],0)){ return;}
a_F1=to_LIST(a_1033)->offset[a_F1];
a_L2=to_LIST(a_1033)->offset[a_F1];
a_G4:if(!a_noteq(a_L2,0)){ goto a_G1;}
if(!a_1378(20,to_LIST(a_1033)->offset[a_F1-1],to_LIST(a_1033)->offset[a_L2-2])){ goto a_G1;}
to_LIST(a_1033)->offset[a_F1-1]=to_LIST(a_1033)->offset[a_L2-1];
{register a_word a_r1=to_LIST(a_1033)->offset[a_L2];to_LIST(a_1033)->offset[a_F1]=a_r1;a_L2=a_r1;} goto a_G4;
} /* mergeintervals */
static a_word a_1044(a_word a_F1){ /* completezone+>a */

a_F1=to_LIST(a_1033)->offset[a_F1];
if(!a_is(a_F1)){ return 0;}
if(!a_1019(to_LIST(a_1033)->offset[a_F1-2],to_LIST(a_1033)->offset[a_F1-1])){ return 0;} return 1;
} /* completezone */
static void a_1078(a_word a_A[2]){ /* readareainterval+a>+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[1];
if(!a_equal(16777459,a_1461)){ goto a_G6;}
a_A[0]=a_1462;
a_1468();
a_G4:a_A[1]=a_A[0];
a_L4=1; goto a_G26;
a_G6:if(!a_equal(16777471,a_1461)){ goto a_G23;}
a_L3=a_1462;
a_1468();
a_P[0]=a_L3;a_1060(a_P);a_L3=a_P[0];
{register a_word a_r1=to_LIST(a_1288)->offset[a_L3-5];
 if(a_r1==16777304||a_r1==16777335){ goto a_G11;}
 if(a_r1==16777322||a_r1==16777318||a_r1==16777328){  goto a_G12;}
  goto a_G22;}
a_G11:a_A[0]=to_LIST(a_1288)->offset[a_L3]; goto a_G4;
a_G12:a_1320(a_L3,a_P);a_A[0]=a_P[0];
a_1017(0,a_A[0],a_P);a_L5=a_P[0];
a_1310(a_L3,a_P);a_A[1]=a_P[0];
a_1017(1,a_A[1],a_P);a_L6=a_P[0];
a_1379(7,a_L6,a_L5);
a_1017(1,1,a_P);a_L6=a_P[0];
a_1379(6,a_L6,a_L5);
a_1024(a_L5,a_P);a_A[0]=a_P[0];
a_1321(a_L3,a_P);a_A[1]=a_P[0];
a_L4=2; goto a_G26;
a_G22:a_1422(a_1001,2130705132); return;
a_G23:a_1012(a_P);a_A[0]=a_P[0];
a_1012(a_P);a_A[1]=a_P[0];
a_L4=0;
a_G26:if(!a_equal(16777409,a_1461)){ goto a_G41;}
a_1468();
if(!a_equal(a_L4,0)){ goto a_G30;}
a_A[0]=a_1026; goto a_G31;
a_G30:if(!a_equal(a_L4,1)){ goto a_G22;}
a_G31:if(!a_equal(16777459,a_1461)){ goto a_G34;}
a_A[1]=a_1462;
a_1468(); return;
a_G34:if(!a_equal(16777471,a_1461)){ goto a_G40;}
a_L3=a_1462;
a_1468();
a_P[0]=a_L3;a_1060(a_P);a_L3=a_P[0];
{register a_word a_r1=to_LIST(a_1288)->offset[a_L3-5];
 if(!(a_r1==16777304||a_r1==16777335)){ goto a_G22;}
}
a_A[1]=to_LIST(a_1288)->offset[a_L3]; return;
a_G40:a_A[1]=a_1025; return;
a_G41:if(!a_equal(a_L4,0)){ return;} goto a_G22;
} /* readareainterval */
static void a_1038(a_word a_F1,a_word a_A[1]){ /* checkarea+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_L7;a_word a_P[4];
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_A[0]=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130705105); return;
a_G5:a_L3=0;
a_G6:a_1078(a_P);a_L4=a_P[0];a_L5=a_P[1];
a_1017(0,a_L4,a_P);a_L6=a_P[0];
a_1017(0,a_L5,a_P);a_L7=a_P[0];
if(!a_1378(22,a_L6,a_L7)){ goto a_G11;}
a_P[0]=a_L3;a_1035(a_F1,a_L6,a_L7,a_P);a_L3=a_P[0]; goto a_G12;
a_G11:a_P[0]=2047260000;a_P[1]=a_A[0];a_P[2]=a_L4;a_P[3]=a_L5;a_1423(4,a_P);
a_G12:if(!a_equal(16777442,a_1461)){ goto a_G14;}
a_1468(); goto a_G6;
a_G14:a_1072(a_F1);
if(a_is(a_L3)){ return;}
a_P[0]=2047260013;a_P[1]=a_A[0];a_1423(2,a_P); return;
} /* checkarea */
static void a_1039(void){ /* checkareas */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[2];
a_scratch(a_1033);
{register a_word *a_r1=a_extension(a_1033,3);a_r1[0]=a_r1[1]=a_r1[2]=0;to_LIST(a_1033)->aupb+=3;}
a_L1=to_LIST(a_1033)->aupb;
a_1374(a_P);a_L4=a_P[0];
a_L2=0;a_L3=0;
a_G6:if(!a_equal(16777220,a_1461)){ goto a_G14;}
a_1468();
a_incr(a_L3);
a_1038(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(16777433,a_1461)){ goto a_G13;}

a_1468(); goto a_G6;
a_G13:a_1422(a_1001,2130705105); return;
a_G14:if(!a_1044(a_L1)){ goto a_G18;}
a_1088(2048);
if(a_more(a_L3,1)){ goto a_G20;}
a_P[0]=2047260038;a_P[1]=a_L2;a_1423(2,a_P); goto a_G20;
a_G18:a_P[0]=2047260026;a_P[1]=a_L2;a_1443(2,a_P);
a_1102=1;
a_G20:a_1370(a_L4); return;
} /* checkareas */
static void a_1088(a_word a_F1){ /* setnodeflag+>a */

a_boolor(a_F1,to_LIST(a_1032)->offset[a_1103-4],to_LIST(a_1032)->offset[a_1103-4]); return;
} /* setnodeflag */
static void a_1077(a_word a_F1,a_word a_F2){ /* putnodeflag+>a+>a */

a_boolor(a_F2,to_LIST(a_1032)->offset[a_F1-4],to_LIST(a_1032)->offset[a_F1-4]); return;
} /* putnodeflag */
static void a_1041(a_word a_F1,a_word a_F2){ /* clearnodeflag+>a+>a */

a_boolinvert(a_F2,a_F2);
a_booland(a_F2,to_LIST(a_1032)->offset[a_F1-4],to_LIST(a_1032)->offset[a_F1-4]); return;
} /* clearnodeflag */
static void a_1046(void){ /* createnodes */
a_word a_L1;
a_scratch(a_1032);
if(!a_equal(16777455,a_1461)){ goto a_G5;}
a_L1=a_1462;
a_1468(); goto a_G6;
a_G5:a_1422(a_1001,2130705105); return;
a_G6:if(a_equal(a_L1,0)){ return;}
{register a_word *a_r1=a_extension(a_1032,6);a_r1[0]=a_r1[1]=a_r1[2]=a_r1[3]=a_r1[4]=a_r1[5]=0;to_LIST(a_1032)->aupb+=6;}
a_decr(a_L1); goto a_G6;
} /* createnodes */
static void a_1036(void){ /* advancenode */

if(!a_equal(16777467,a_1461)){ goto a_G4;}

a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130705105); return;
a_G5:if(!a_equal(a_1103,0)){ goto a_G7;}
a_1103=to_LIST(a_1032)->alwb; goto a_G8;
a_G7:a_next(a_1032,a_1103);
a_G8:if(a_lseq(a_1103,to_LIST(a_1032)->aupb)){ return;}
a_1422(a_1001,2130705125); return;
} /* advancenode */
static void a_1061(a_word a_F1,a_word a_A[1]){ /* getnodeindex+>a+a> */

a_subtr(a_F1,to_LIST(a_1032)->alwb,a_A[0]);
a_div(a_A[0],6,a_A[0]);
a_incr(a_A[0]); return;
} /* getnodeindex */
static void a_1064(a_word a_F1,a_word a_A[1]){ /* indextonode+>a+a> */

a_decr(a_F1);
a_addmult(a_F1,6,to_LIST(a_1032)->alwb,a_A[0]); return;
} /* indextonode */
static void a_1089(void){ /* setrulehead */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[1];
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130705105); return;
a_G5:a_P[0]=a_L1;a_1060(a_P);a_L1=a_P[0];
to_LIST(a_1032)->offset[a_1103-3]=a_L1;
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L2=a_1462;
a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L3=a_1462;
a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L4=a_1462;
a_1468();
if(a_1326(a_L1,12288)){ goto a_G22;}
if(!a_1326(a_L1,16384)){ goto a_G19;}
a_1088(8); goto a_G22;
a_G19:a_max(a_L2,a_1029);
a_max(a_L3,a_1030);
a_max(a_L4,a_1031);
a_G22:a_booland(to_LIST(a_1032)->offset[a_1103-4],8,a_L5);
if(a_noteq(a_L5,0)){ return;}
if(a_1338(a_L1)){ return;}
a_1034=1; return;
} /* setrulehead */
static void a_1093(void){ /* skiprulehead */

a_1468();
a_1468();
a_1468();
a_1468(); return;
} /* skiprulehead */
static void a_1042(void){ /* clearstacksize */

a_1029=0;a_1030=0;a_1031=0; return;
} /* clearstacksize */
static void a_1070(a_word a_F1){ /* marklocalaffix+>a */

if(a_equal(a_1047,0)){ return;}
a_add(a_1067,a_F1,a_F1);
to_LIST(a_1447)->offset[a_F1]=1; return;
} /* marklocalaffix */
static void a_1096(a_word a_F1,a_word a_F2){ /* startlocalaffixcheck+>a+>a */
a_word a_P[1];
if(!a_equal(a_F1,0)){ goto a_G3;}
a_1047=0; return;
a_G3:a_1047=1;
a_subtr(to_LIST(a_1447)->aupb,a_F1,a_1067);
a_incr(a_1067);
a_G6:if(a_more(a_F1,a_F2)){ return;}
a_P[0]=0;a_1076(1,a_P);
a_incr(a_F1); goto a_G6;
} /* startlocalaffixcheck */
static void a_1094(void){ /* skiptocomma */
a_word a_L1;
a_G1:if(!a_equal(16777412,a_1461)){ goto a_G3;}
a_1468(); return;
a_G3:if(!a_equal(16777479,a_1461)){ goto a_G7;}
a_L1=a_1462;
a_1468();
a_1070(a_L1); goto a_G1;
a_G7:if(!a_equal(16777448,a_1461)){ goto a_G10;}
a_1468();
a_1063=1; goto a_G1;
a_G10:if(!a_equal(16777486,a_1461)){ goto a_G13;}
a_1468();
a_1422(a_1001,2130705120); return;
a_G13:a_1468(); goto a_G1;
} /* skiptocomma */
static void a_1095(a_word a_A[1]){ /* skiptolabel+a> */

a_G1:if(!a_equal(16777433,a_1461)){ goto a_G4;}
a_A[0]=a_1462;
a_1468(); return;
a_G4:if(!a_equal(16777486,a_1461)){ goto a_G7;}
a_1468();
a_1422(a_1001,2130705115); return;
a_G7:a_1468(); goto a_G1;
} /* skiptolabel */
static a_word a_1065(void){ /* islimit */

if(!a_equal(16777231,a_1461)){ goto a_G3;}
a_G2:a_1468(); return 1;
a_G3:if(a_equal(16777269,a_1461)){ goto a_G2;}
if(a_equal(16777291,a_1461)){ goto a_G2;}
if(a_equal(16777295,a_1461)){ goto a_G2;}
if(!a_equal(16777299,a_1461)){ return 0;} goto a_G2;
} /* islimit */
static void a_1091(void){ /* skiplist */

if(!a_equal(16777475,a_1461)){ goto a_G3;}
a_G2:a_1468(); return;
a_G3:if(!a_equal(16777471,a_1461)){ goto a_G5;}
 goto a_G2;
a_G5:a_1422(a_1001,2130705105); return;
} /* skiplist */
static void a_1090(void){ /* skipaffix */
a_word a_L1;
if(!a_equal(16777409,a_1461)){ goto a_G3;}
a_1468();
a_G3:if(!a_equal(16777475,a_1461)){ goto a_G5;}
a_G4:a_1468(); return;
a_G5:if(!a_equal(16777479,a_1461)){ goto a_G9;}
a_L1=a_1462;
a_1468();
a_1070(a_L1); return;
a_G9:if(a_equal(16777471,a_1461)){ goto a_G4;}
if(a_equal(16777424,a_1461)){ goto a_G4;}
if(a_equal(16777459,a_1461)){ goto a_G4;}
if(!a_1065()){ goto a_G14;}
a_1091(); return;
a_G14:if(!a_equal(16777448,a_1461)){ goto a_G25;}
a_1468();
a_1063=1;
a_1091();
a_1090();
if(!a_equal(16777403,a_1461)){ goto a_G22;}

a_1468(); goto a_G23;
a_G22:a_1422(a_1001,2130705105); return;
a_G23:if(!a_equal(16777455,a_1461)){ goto a_G22;}
 goto a_G4;
a_G25:a_1422(a_1001,2130705110); return;
} /* skipaffix */
static void a_1076(a_word a_C,a_word *a_V){ /* pushBUFFER+@+>a */

a_G1:{register a_word *a_r1=a_extension(a_1447,1);a_r1[0]=a_V[0];to_LIST(a_1447)->aupb+=1;}
if(a_C>1){a_C--;a_V+=1; goto a_G1;}  return;
} /* pushBUFFER */
static void a_1099(a_word a_F1){ /* storelist+>a */
a_word a_L2;a_word a_P[3];
if(!a_equal(16777475,a_1461)){ goto a_G5;}
a_L2=a_1462;
a_1468();
a_P[0]=a_F1;a_P[1]=16777475;a_P[2]=a_L2;a_1076(3,a_P); return;
a_G5:if(!a_equal(16777471,a_1461)){ goto a_G8;}
a_L2=a_1462;
a_1468(); goto a_G9;
a_G8:a_1422(a_1001,2130705105); return;
a_G9:a_P[0]=a_L2;a_1060(a_P);a_L2=a_P[0];
a_P[0]=a_F1;a_P[1]=16777471;a_P[2]=a_L2;a_1076(3,a_P); return;
} /* storelist */
static void a_1098(void){ /* storelimit */

if(!a_equal(16777269,a_1461)){ goto a_G4;}
a_1468();
a_1099(16777269); return;
a_G4:if(!a_equal(16777291,a_1461)){ goto a_G7;}
a_1468();
a_1099(16777291); return;
a_G7:if(!a_equal(16777295,a_1461)){ goto a_G10;}
a_1468();
a_1099(16777295); return;
a_G10:if(!a_equal(16777299,a_1461)){ goto a_G13;}
a_1468();
a_1099(16777299); return;
a_G13:if(!a_equal(16777231,a_1461)){ goto a_G16;}

a_1468(); goto a_G17;
a_G16:a_1422(a_1001,2130705105); return;
a_G17:a_1099(16777231); return;
} /* storelimit */
static void a_1097(void){ /* storeaffix */
a_word a_L1;a_word a_P[2];
if(!a_equal(16777475,a_1461)){ goto a_G5;}
a_L1=a_1462;
a_1468();
a_P[0]=16777475;a_P[1]=a_L1;a_1076(2,a_P); return;
a_G5:if(!a_equal(16777479,a_1461)){ goto a_G9;}
a_L1=a_1462;
a_1468();
a_P[0]=16777479;a_P[1]=a_L1;a_1076(2,a_P); return;
a_G9:if(!a_equal(16777471,a_1461)){ goto a_G14;}
a_L1=a_1462;
a_1468();
a_P[0]=a_L1;a_1060(a_P);a_L1=a_P[0];
a_P[0]=16777471;a_P[1]=a_L1;a_1076(2,a_P); return;
a_G14:if(!a_equal(16777459,a_1461)){ goto a_G18;}
a_L1=a_1462;
a_1468();
a_P[0]=16777459;a_P[1]=a_L1;a_1076(2,a_P); return;
a_G18:if(!a_equal(16777448,a_1461)){ goto a_G30;}
a_1468();
a_1099(16777448);
a_1097();
if(!a_equal(16777403,a_1461)){ goto a_G25;}

a_1468(); goto a_G26;
a_G25:a_1422(a_1001,2130705105); return;
a_G26:if(!a_equal(16777455,a_1461)){ goto a_G25;}
a_L1=a_1462;
a_1468();
a_P[0]=16777403;a_P[1]=a_L1;a_1076(2,a_P); return;
a_G30:a_1098(); return;
} /* storeaffix */
static void a_1100(a_word a_A[1]){ /* storeruleaffix+a> */
a_word a_L2;a_word a_P[2];
if(!a_equal(16777409,a_1461)){ goto a_G6;}
a_1468();
a_A[0]=16777409;
a_P[0]=16777409;a_1076(1,a_P);
a_G5:a_1097(); return;
a_G6:if(!a_equal(16777424,a_1461)){ goto a_G10;}
a_1468();
a_A[0]=16777424;
a_P[0]=16777424;a_1076(1,a_P); return;
a_G10:if(!a_equal(16777397,a_1461)){ goto a_G18;}
a_1468();
a_A[0]=16777397;
if(!a_equal(16777455,a_1461)){ goto a_G16;}
a_L2=a_1462;
a_1468(); goto a_G17;
a_G16:a_L2=0;
a_G17:a_P[0]=16777397;a_P[1]=a_L2;a_1076(2,a_P); return;
a_G18:a_A[0]=0; goto a_G5;
} /* storeruleaffix */
static void a_1101(void){ /* storeruleaffixes */
a_word a_L1;a_word a_P[2];
a_G1:{ if(a_1461==16777479){ goto a_G2;}
 if(a_1461==16777471){ goto a_G5;}
 if(a_1461==16777475||a_1461==16777459||a_1461==16777455){ goto a_G3;}
 if(a_1461==16777448){ goto a_G6;}
 if(a_1461==16777269||a_1461==16777291||a_1461==16777295||a_1461==16777299||a_1461==16777231||a_1461==16777424||a_1461==16777403||a_1461==16777397||a_1461==16777409){  goto a_G11;}
  goto a_G12;}
a_G2:a_1070(a_1462);
a_G3:a_P[0]=a_1461;a_P[1]=a_1462;a_1076(2,a_P);
a_G4:a_1468(); goto a_G1;
a_G5:a_P[0]=a_1462;a_1060(a_P);a_1462=a_P[0]; goto a_G3;
a_G6:a_P[0]=a_1461;a_1076(1,a_P);
a_1468();
a_booland(to_LIST(a_1032)->offset[a_1103-4],8,a_L1);
if(a_noteq(a_L1,0)){ goto a_G1;}
a_1063=1; goto a_G1;
a_G11:a_P[0]=a_1461;a_1076(1,a_P); goto a_G4;
a_G12:if(!a_equal(16777433,a_1461)){ goto a_G15;}
to_LIST(a_1032)->offset[a_1103-1]=a_1462;
a_1468(); goto a_G16;
a_G15:a_1422(a_1001,2130705105); return;
a_G16:if(!a_equal(16777433,a_1461)){ goto a_G15;}
to_LIST(a_1032)->offset[a_1103]=a_1462;
a_1468();
if(!a_equal(16777412,a_1461)){ goto a_G15;}

a_1468(); return;
} /* storeruleaffixes */
static void a_1045(void){ /* computeruleaffixhash */
a_word a_L1;a_word a_P[1];
a_L1=to_LIST(a_1447)->aupb;
a_1101();
a_blockhash(a_1447,a_L1,a_P);to_LIST(a_1032)->offset[a_1103-5]=a_P[0];
a_unstackto(a_1447,a_L1); return;
} /* computeruleaffixhash */
static a_word a_1074(a_word a_F1){ /* nodewithsamehash+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;
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
static a_word a_1073(void){ /* nodehashdifferent */
a_word a_L1;a_word a_L2;
a_L1=to_LIST(a_1032)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1032)->aupb)){ return 1;}
a_booland(to_LIST(a_1032)->offset[a_L1-4],1,a_L2);
if(!a_noteq(a_L2,0)){ goto a_G6;}
if(a_1074(a_L1)){ return 0;}
a_G6:a_next(a_1032,a_L1); goto a_G2;
} /* nodehashdifferent */
static a_word a_1048(a_word a_F1,a_word a_F2){ /* equalaffixes+>a+>a */

a_G1:if(!a_equal(to_LIST(a_1447)->offset[a_F1],to_LIST(a_1447)->offset[a_F2])){ return 0;}
if(a_equal(to_LIST(a_1447)->offset[a_F1],16777412)){ return 1;}
a_decr(a_F1);
a_decr(a_F2); goto a_G1;
} /* equalaffixes */
static void a_1043(a_word a_F1){ /* comparetostoredaffixes+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;
a_L3=to_LIST(a_1032)->offset[a_1103-5];
a_L4=1;
a_L2=to_LIST(a_1032)->alwb;
a_G4:if(a_mreq(a_L2,a_1103)){ goto a_G13;}
a_booland(to_LIST(a_1032)->offset[a_L2-4],4096,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G12;}
if(!a_equal(to_LIST(a_1032)->offset[a_L2-5],a_L3)){ goto a_G12;}
if(!a_1048(to_LIST(a_1032)->offset[a_1103-2],to_LIST(a_1032)->offset[a_L2-2])){ goto a_G12;}
a_L4=0;
to_LIST(a_1032)->offset[a_1103-2]=a_L2;
a_1088(8192); goto a_G13;
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
a_unstackto(a_1447,a_F1); return;
a_G23:a_1088(4096); return;
} /* comparetostoredaffixes */
static void a_1040(void){ /* checknodehash */
a_word a_L1;a_word a_P[1];
if(!a_1074(a_1103)){ goto a_G7;}
a_L1=to_LIST(a_1447)->aupb;
a_P[0]=16777412;a_1076(1,a_P);
a_1101();
to_LIST(a_1032)->offset[a_1103-2]=to_LIST(a_1447)->aupb;
a_1043(a_L1); return;
a_G7:a_1094(); return;
} /* checknodehash */
static a_word a_1083(a_word a_F1,a_word a_F2){ /* samenodes+>a+>a */
a_word a_L3;
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
static a_word a_1062(a_word a_F1){ /* hasoutaffix+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1318(a_F1,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_mreq(a_L3,a_L2)){ return 0;}
a_1314(a_F1,a_L3,a_P);a_L4=a_P[0];
if(a_equal(a_L4,16777376)){ return 1;}
if(a_equal(a_L4,16777382)){ return 1;}
if(a_equal(a_L4,16777388)){ return 1;}
a_incr(a_L3); goto a_G3;
} /* hasoutaffix */
static a_word a_1066(a_word a_F1){ /* isnodediscarded+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_booland(to_LIST(a_1032)->offset[a_F1-4],1,a_L2);
if(!a_noteq(a_L2,0)){ return 0;}
a_1053(to_LIST(a_1032)->offset[a_F1-1],a_P);a_L2=a_P[0];
a_1053(to_LIST(a_1032)->offset[a_F1],a_P);a_L3=a_P[0];
if(!a_equal(a_L2,a_L3)){ return 0;}
a_F1=to_LIST(a_1032)->offset[a_F1-3];
if(a_1326(a_F1,256)){ return 0;}
if(a_1326(a_F1,1024)){ return 0;}
if(a_1326(a_F1,32768)){ return 0;}
if(!a_1062(a_F1)){ return 1;} return 0;
} /* isnodediscarded */
static void a_1079(a_word a_F1,a_word a_F2){ /* replacelabels+>a+>a */
a_word a_L3;
a_L3=to_LIST(a_1032)->alwb;
a_G2:if(a_more(a_L3,to_LIST(a_1032)->aupb)){ return;}
if(!a_equal(to_LIST(a_1032)->offset[a_L3-1],a_F1)){ goto a_G5;}
to_LIST(a_1032)->offset[a_L3-1]=a_F2;
a_G5:if(!a_equal(to_LIST(a_1032)->offset[a_L3],a_F1)){ goto a_G7;}
to_LIST(a_1032)->offset[a_L3]=a_F2;
a_G7:a_next(a_1032,a_L3); goto a_G2;
} /* replacelabels */
static void a_1080(a_word a_F1,a_word a_F2){ /* replacenlabels+>a+>a */
a_word a_P[1];
to_LIST(a_1032)->offset[a_F2-2]=a_F1;
a_1077(a_F2,16384);
a_1061(a_F1,a_P);a_F1=a_P[0];
a_1061(a_F2,a_P);a_F2=a_P[0];
a_1079(a_F2,a_F1); return;
} /* replacenlabels */
static void a_1050(void){ /* findequalnodes */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_G1:a_L1=0;
a_L2=to_LIST(a_1032)->alwb;
a_G3:if(a_more(a_L2,to_LIST(a_1032)->aupb)){ goto a_G24;}
a_booland(to_LIST(a_1032)->offset[a_L2-4],16384,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G7;}
a_G6:a_next(a_1032,a_L2); goto a_G3;
a_G7:a_booland(to_LIST(a_1032)->offset[a_L2-4],8,a_L4);
if(a_noteq(a_L4,0)){ goto a_G6;}
if(!a_1066(a_L2)){ goto a_G14;}
a_1077(a_L2,8);
a_1061(a_L2,a_P);a_L3=a_P[0];
a_1079(a_L3,to_LIST(a_1032)->offset[a_L2]);
a_L1=1; goto a_G6;
a_G14:a_L3=a_L2;
a_G15:a_next(a_1032,a_L3);
if(a_more(a_L3,to_LIST(a_1032)->aupb)){ goto a_G6;}
a_booland(to_LIST(a_1032)->offset[a_L3-4],16384,a_L4);
if(a_noteq(a_L4,0)){ goto a_G15;}
a_booland(to_LIST(a_1032)->offset[a_L3-4],8,a_L4);
if(a_noteq(a_L4,0)){ goto a_G15;}
if(!a_1083(a_L2,a_L3)){ goto a_G15;}
a_L1=1;
a_1080(a_L2,a_L3); goto a_G15;
a_G24:if(a_equal(a_L1,0)){ return;}
if(a_is(a_1068)){ return;} goto a_G1;
} /* findequalnodes */
static void a_1075(void){ /* omitemptynodes */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
a_L1=to_LIST(a_1032)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1032)->aupb)){ return;}
a_booland(to_LIST(a_1032)->offset[a_L1-4],8,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G9;}
a_1061(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,to_LIST(a_1032)->offset[a_L1])){ goto a_G8;}
a_1068=to_LIST(a_1032)->offset[a_L1-3]; goto a_G9;
a_G8:a_1079(a_L2,to_LIST(a_1032)->offset[a_L1]);
a_G9:a_next(a_1032,a_L1); goto a_G2;
} /* omitemptynodes */
static void a_1053(a_word a_F1,a_word a_A[1]){ /* findreallabel+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[1];
if(!a_lseq(a_F1,0)){ goto a_G3;}
a_G2:a_A[0]=a_F1; return;
a_G3:if(a_is(a_1068)){ goto a_G2;}
a_1064(a_F1,a_P);a_F1=a_P[0];
a_listlength(a_1032,a_L4);
a_L3=0;
a_G7:a_booland(to_LIST(a_1032)->offset[a_F1-4],16384,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G10;}
a_F1=to_LIST(a_1032)->offset[a_F1-2]; goto a_G7;
a_G10:if(!a_more(a_L3,a_L4)){ goto a_G13;}
a_1041(a_F1,8);
a_1068=to_LIST(a_1032)->offset[a_F1-3]; goto a_G17;
a_G13:a_booland(to_LIST(a_1032)->offset[a_F1-4],8,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G17;}
a_1064(to_LIST(a_1032)->offset[a_F1],a_P);a_F1=a_P[0];
a_incr(a_L3); goto a_G7;
a_G17:a_1061(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* findreallabel */
static void a_1052(a_word a_A[1]){ /* findnextnode+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_A[0]=0;
a_L2=a_1103;
a_G3:a_next(a_1032,a_L2);
if(a_more(a_L2,to_LIST(a_1032)->aupb)){ return;}
a_booland(to_LIST(a_1032)->offset[a_L2-4],16384,a_L3);
if(a_noteq(a_L3,0)){ goto a_G3;}
a_booland(to_LIST(a_1032)->offset[a_L2-4],8,a_L3);
if(a_noteq(a_L3,0)){ goto a_G3;}
a_1061(a_L2,a_P);a_A[0]=a_P[0]; return;
} /* findnextnode */
static void a_1071(a_word a_F1,a_word a_F2){ /* marknode+>a+>a */
a_word a_P[1];
a_1053(a_F2,a_P);a_F2=a_P[0];
if(a_lseq(a_F2,0)){ return;}
if(a_equal(a_F2,a_F1)){ return;}
a_1064(a_F2,a_P);a_F2=a_P[0];
a_1077(a_F2,16); return;
} /* marknode */
static void a_1081(void){ /* rulelabel */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_booland(to_LIST(a_1032)->offset[a_1103-4],16384,a_L2);
if(a_noteq(a_L2,0)){ return;}
a_booland(to_LIST(a_1032)->offset[a_1103-4],8,a_L2);
if(a_noteq(a_L2,0)){ return;}
a_1052(a_P);a_L1=a_P[0];
a_1071(a_L1,to_LIST(a_1032)->offset[a_1103-1]);
a_1071(a_L1,to_LIST(a_1032)->offset[a_1103]); return;
} /* rulelabel */
static void a_1037(void){ /* arealabels */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1052(a_P);a_L1=a_P[0];
a_L2=0;a_L3=0;
a_G3:if(!a_equal(16777220,a_1461)){ goto a_G8;}
a_1468();
a_1071(0,a_L2);
a_L2=a_L3;
a_1095(a_P);a_L3=a_P[0]; goto a_G3;
a_G8:a_booland(to_LIST(a_1032)->offset[a_1103-4],2048,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G12;}
a_1071(a_L1,a_L2);
a_G11:a_1071(a_L1,a_L3); return;
a_G12:a_1071(0,a_L2); goto a_G11;
} /* arealabels */
static void a_1049(void){ /* extensionlabel */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_1052(a_P);a_L1=a_P[0];
a_1095(a_P);a_L2=a_P[0];
a_1071(a_L1,a_L2); return;
} /* extensionlabel */
static void a_1058(void){ /* generatelabel */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
a_1036();
a_booland(to_LIST(a_1032)->offset[a_1103-4],16384,a_L3);
if(a_noteq(a_L3,0)){ return;}
a_booland(to_LIST(a_1032)->offset[a_1103-4],8,a_L3);
if(a_noteq(a_L3,0)){ return;}
a_1052(a_P);a_L2=a_P[0];
a_booland(to_LIST(a_1032)->offset[a_1103-4],16,a_L3);
if(!a_noteq(a_L3,0)){ goto a_G10;}
a_1061(a_1103,a_P);a_L1=a_P[0]; goto a_G11;
a_G10:a_L1=0;
a_G11:a_1114(a_L1,a_L2); return;
} /* generatelabel */
static void a_1059(void){ /* generaterulecall */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_L7;a_word a_P[1];
if(!a_equal(16777471,a_1461)){ goto a_G4;}

a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130705105); return;
a_G5:if(!a_equal(16777455,a_1461)){ goto a_G4;}

a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G4;}

a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G4;}

a_1468();
a_L7=to_LIST(a_1447)->aupb;
a_L2=0;a_L5=0;a_L6=0;
a_G16:if(!a_equal(16777433,a_1461)){ goto a_G21;}
a_1468();
if(!a_equal(16777433,a_1461)){ goto a_G4;}

a_1468(); goto a_G30;
a_G21:a_1100(a_P);a_L1=a_P[0];
a_P[0]=16777436;a_1076(1,a_P);
a_incr(a_L2);
if(!a_is(a_L5)){ goto a_G26;}
a_incr(a_L5);
a_G26:if(!a_equal(a_L1,16777397)){ goto a_G16;}
if(!a_is(a_L5)){ goto a_G29;}
a_L6=1; goto a_G16;
a_G29:a_L5=1; goto a_G16;
a_G30:a_1053(to_LIST(a_1032)->offset[a_1103-1],a_P);a_L3=a_P[0];
a_1053(to_LIST(a_1032)->offset[a_1103],a_P);a_L4=a_P[0];
a_1116(to_LIST(a_1032)->offset[a_1103-3],a_L2,a_L3,a_L4,a_L5,a_L6,a_L7);
a_unstackto(a_1447,a_L7); return;
} /* generaterulecall */
static void a_1057(void){ /* generateextension */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[2];
a_L1=to_LIST(a_1447)->aupb;
a_1099(0);
if(!a_equal(16777455,a_1461)){ goto a_G6;}
a_L2=a_1462;
a_1468(); goto a_G7;
a_G6:a_1422(a_1001,2130705105); return;
a_G7:a_add(a_L1,1,a_L3);
to_LIST(a_1447)->offset[a_L3]=a_L2;
a_P[0]=0;a_1076(1,a_P);
a_L3=to_LIST(a_1447)->aupb;
a_G11:a_1097();
a_P[0]=16777436;a_1076(1,a_P);
a_G13:if(!a_equal(16777288,a_1461)){ goto a_G19;}
a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G6;}
a_L2=a_1462;
a_1468();
a_P[0]=a_L2;a_1076(1,a_P); goto a_G13;
a_G19:if(!a_equal(16777433,a_1461)){ goto a_G25;}
a_L4=a_1462;
a_1468();
a_1053(a_L4,a_P);a_L4=a_P[0];
a_P[0]=-1;a_1076(1,a_P);
a_1110(a_L1,a_L4); goto a_G27;
a_G25:a_P[0]=-1;a_P[1]=0;a_1076(2,a_P);
{register a_word a_r1=to_LIST(a_1447)->aupb;to_LIST(a_1447)->offset[a_L3]=a_r1;a_L3=a_r1;} goto a_G11;
a_G27:a_unstackto(a_1447,a_L1); return;
} /* generateextension */
static void a_1054(void){ /* generatearea */
a_word a_L1;a_word a_L2;a_word a_P[2];
a_G1:a_1078(a_P);a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=a_L1;a_P[1]=a_L2;a_1076(2,a_P);
if(!a_equal(16777442,a_1461)){ return;}
a_1468();
a_P[0]=16777442;a_1076(1,a_P); goto a_G1;
} /* generatearea */
static void a_1055(void){ /* generateareas */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[3];
a_L1=0;
if(!a_equal(16777220,a_1461)){ goto a_G5;}

a_1468(); goto a_G6;
a_G5:a_1422(a_1001,2130705105); return;
a_G6:if(!a_equal(16777455,a_1461)){ goto a_G5;}

a_1468();
a_P[0]=0;a_1076(1,a_P);
if(a_equal(a_L1,0)){ goto a_G12;}
to_LIST(a_1447)->offset[a_L1]=to_LIST(a_1447)->aupb;
a_G12:a_L1=to_LIST(a_1447)->aupb;
a_P[0]=0;a_1076(1,a_P);
a_L2=to_LIST(a_1447)->aupb;
a_1054();
if(!a_equal(16777433,a_1461)){ goto a_G5;}
a_L3=a_1462;
a_1468();
a_1053(a_L3,a_P);to_LIST(a_1447)->offset[a_L2]=a_P[0];
if(!a_equal(16777220,a_1461)){ goto a_G23;}
a_1468();
a_P[0]=16777436;a_1076(1,a_P); goto a_G6;
a_G23:a_booland(to_LIST(a_1032)->offset[a_1103-4],2048,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G27;}
a_unstackto(a_1447,a_L2);
a_P[0]=a_1026;a_P[1]=a_1025;a_P[2]=16777436;a_1076(3,a_P); return;
a_G27:a_P[0]=16777436;a_1076(1,a_P); return;
} /* generateareas */
static void a_1056(void){ /* generatebox */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_L1=to_LIST(a_1447)->aupb;
a_1097();
a_P[0]=16777436;a_1076(1,a_P);
a_L2=to_LIST(a_1447)->aupb;
a_1055();
a_1109(a_L1,a_L2);
a_unstackto(a_1447,a_L1); return;
} /* generatebox */
static void a_1084(void){ /* scani */

a_G1:if(!a_equal(16777227,a_1461)){ goto a_G11;}
a_1468();
a_1036();
a_1088(4);
a_1090();
a_1039();
if(!a_equal(16777412,a_1461)){ goto a_G10;}

a_1468(); goto a_G1;
a_G10:a_1422(a_1001,2130705105); return;
a_G11:if(!a_equal(16777241,a_1461)){ goto a_G16;}
a_1468();
a_1036();
a_1088(2);
a_1094(); goto a_G1;
a_G16:if(!a_equal(16777281,a_1461)){ goto a_G22;}
a_1468();
a_1036();
a_1088(1);
a_1089();
a_1045(); goto a_G1;
a_G22:if(!a_equal(16777439,a_1461)){ goto a_G10;}

a_1468(); return;
} /* scani */
static void a_1085(void){ /* scanii */
a_word a_L1;
a_L1=to_LIST(a_1447)->aupb;
a_G2:if(!a_equal(16777227,a_1461)){ goto a_G6;}
a_G3:a_1468();
a_1036();
a_1094(); goto a_G2;
a_G6:if(a_equal(16777241,a_1461)){ goto a_G3;}
if(!a_equal(16777281,a_1461)){ goto a_G12;}
a_1468();
a_1036();
a_1093();
a_1040(); goto a_G2;
a_G12:if(!a_equal(16777439,a_1461)){ goto a_G15;}

a_1468(); goto a_G16;
a_G15:a_1422(a_1001,2130705105); return;
a_G16:a_unstackto(a_1447,a_L1); return;
} /* scanii */
static void a_1086(void){ /* scaniii */

a_G1:if(!a_equal(16777227,a_1461)){ goto a_G10;}
a_1468();
a_1036();
a_1090();
a_1037();
a_G6:if(!a_equal(16777412,a_1461)){ goto a_G9;}

a_1468(); goto a_G1;
a_G9:a_1422(a_1001,2130705105); return;
a_G10:if(!a_equal(16777241,a_1461)){ goto a_G14;}
a_1468();
a_1036();
a_1049(); goto a_G6;
a_G14:if(!a_equal(16777281,a_1461)){ goto a_G19;}
a_1468();
a_1036();
a_1081();
a_1094(); goto a_G1;
a_G19:if(!a_equal(16777439,a_1461)){ goto a_G9;}

a_1468(); return;
} /* scaniii */
static void a_1087(void){ /* scaniv */
a_word a_L1;
a_G1:if(!a_equal(16777227,a_1461)){ goto a_G9;}
a_1468();
a_1058();
a_1056();
a_G5:if(!a_equal(16777412,a_1461)){ goto a_G8;}

a_1468(); goto a_G1;
a_G8:a_1422(a_1001,2130705105); return;
a_G9:if(!a_equal(16777241,a_1461)){ goto a_G13;}
a_1468();
a_1058();
a_1057(); goto a_G5;
a_G13:if(!a_equal(16777281,a_1461)){ goto a_G22;}
a_1468();
a_1058();
a_booland(to_LIST(a_1032)->offset[a_1103-4],16384,a_L1);
if(!a_noteq(a_L1,0)){ goto a_G19;}
a_G18:a_1094(); goto a_G1;
a_G19:a_booland(to_LIST(a_1032)->offset[a_1103-4],8,a_L1);
if(a_noteq(a_L1,0)){ goto a_G18;}
a_1059(); goto a_G5;
a_G22:if(!a_equal(16777439,a_1461)){ goto a_G8;}

a_1468(); return;
} /* scaniv */
static void a_1069(void){ /* makerule */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[4];
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130705105); return;
a_G5:if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L3=a_1462;
a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L4=a_1462;
a_1468();
if(!a_1326(a_L1,16384)){ goto a_G13;}
a_1092(); return;
a_G13:a_1046();
a_1034=0;a_1063=0;
if(!a_1326(a_L1,16777216)){ goto a_G17;}
a_1102=1; goto a_G18;
a_G17:a_1102=0;
a_G18:a_L2=to_LIST(a_1447)->aupb;
a_1042();
a_1096(a_L3,a_L4);
a_1478();
a_1103=0;
a_1084();
a_1047=0;
a_1068=0;
a_1075();
if(a_is(a_1102)){ goto a_G30;}
if(!a_1326(a_L1,67108864)){ goto a_G30;}
a_1102=a_1063;
a_G30:if(a_1073()){ goto a_G34;}
a_1477();
a_1103=0;
a_1085();
a_G34:a_1050();
a_1199(a_L1,a_1030,a_1031,a_1102,a_L3,a_L4,a_1067,a_1034);
a_unstackto(a_1447,a_L2);
a_1477();
a_1103=0;
a_1086();
if(!a_is(a_1068)){ goto a_G42;}
a_P[0]=2047260052;a_P[1]=to_LIST(a_1288)->offset[a_L1-3];a_P[2]=to_LIST(a_1288)->offset[a_L1-2];a_P[3]=to_LIST(a_1288)->offset[a_1068-3];a_1423(4,a_P); return;
a_G42:a_1477();
a_1103=0;
a_1087();
a_1200(); return;
} /* makerule */
static void a_1165(void){ /* opentarget */
a_word a_L1;a_word a_P[3];
a_1397();
if(!a_openfile(a_1106,119,a_1451,to_LIST(a_1451)->aupb)){ goto a_G5;}
a_unstackstring(a_1451);
a_1206=1; return;
a_G5:a_getfileerror(a_1106,a_L1);
a_P[0]=2047260066;a_P[1]=to_LIST(a_1451)->aupb;a_P[2]=a_L1;a_1423(3,a_P); return;
} /* opentarget */
static void a_1131(void){ /* closetarget */

if(a_equal(a_1206,0)){ return;}
a_closefile(a_1106);
a_1206=0; return;
} /* closetarget */
static void a_1139(void){ /* deletetarget */

if(a_equal(a_1206,0)){ return;}
a_1131();
a_1397();
a_unlinkfile(a_1451,to_LIST(a_1451)->aupb);
a_unstackstring(a_1451); return;
} /* deletetarget */
static void a_1175(a_word a_F1){ /* printint+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G8;}
a_putchar(a_1106,40);
a_putchar(a_1106,45);
a_1175(2147483647);
a_putchar(a_1106,45);
a_putchar(a_1106,49);
a_putchar(a_1106,41); return;
a_G8:if(!a_less(a_F1,0)){ goto a_G11;}
a_putchar(a_1106,45);
a_getabs(a_F1,a_F1);
a_G11:a_1176(a_F1,48); return;
} /* printint */
static void a_1176(a_word a_F1,a_word a_F2){ /* printint1+>a+>a */
a_word a_L3;a_word a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1176(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_putchar(a_1106,a_L4); return;
} /* printint1 */
static void a_1178(void){ /* printlabelprefix */

a_putchar(a_1106,97);
a_putchar(a_1106,95);
a_putchar(a_1106,71); return;
} /* printlabelprefix */
static void a_1160(a_word a_F1){ /* localargument+>a */

a_putchar(a_1106,97);
a_putchar(a_1106,95);
a_putchar(a_1106,76);
a_1175(a_F1); return;
} /* localargument */
static void a_1177(a_word a_F1,a_word a_F2){ /* printintindex+>a+>a */

a_putchar(a_1106,97);
a_putchar(a_1106,95);
a_putchar(a_1106,a_F1);
a_putchar(a_1106,91);
a_1175(a_F2);
a_putchar(a_1106,93); return;
} /* printintindex */
static void a_1147(a_word a_F1){ /* formalargument+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_L2=0;a_L4=0;
a_G2:a_1314(a_1209,a_L2,a_P);a_L3=a_P[0];
a_incr(a_L2);
if(a_equal(a_L3,16777376)){ goto a_G6;}
if(!a_equal(a_L3,16777382)){ goto a_G9;}
a_G6:if(!a_equal(a_L2,a_F1)){ goto a_G8;}
a_1177(65,a_L4); return;
a_G8:a_incr(a_L4); goto a_G2;
a_G9:if(!a_equal(a_L3,16777388)){ goto a_G17;}
a_incr(a_L2);
a_subtr(a_F1,a_L2,a_L2);
if(!a_less(a_L2,0)){ goto a_G16;}
a_putchar(a_1106,97);
a_putchar(a_1106,95);
a_putchar(a_1106,67); return;
a_G16:a_1177(86,a_L2); return;
a_G17:if(!a_equal(a_L2,a_F1)){ goto a_G2;}
a_putchar(a_1106,97);
a_putchar(a_1106,95);
a_putchar(a_1106,70);
a_1175(a_F1); return;
} /* formalargument */
static void a_1182(a_word a_F1){ /* printpidginrepr+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1460(to_LIST(a_1288)->offset[a_F1],a_P);a_L2=a_P[0];
a_L4=1;
a_G3:if(!a_stringelem(a_1451,a_L2,a_L4,a_P)){ return;}a_L3=a_P[0];
a_putchar(a_1106,a_L3);
a_incr(a_L4); goto a_G3;
} /* printpidginrepr */
static void a_1173(a_word a_F1){ /* printexternalrepr+>a */

{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(a_r1==16777304||a_r1==16777309){ goto a_G2;}
 if(a_r1==16777349){  goto a_G3;}
  goto a_G5;}
a_G2:a_1183(to_LIST(a_1288)->offset[a_F1]); return;
a_G3:if(!a_1326(a_F1,12288)){ goto a_G2;}
a_1182(a_F1); return;
a_G5:a_putchar(a_1106,97);
a_putchar(a_1106,95);
a_1175(to_LIST(a_1288)->offset[a_F1]); return;
} /* printexternalrepr */
static void a_1184(a_word a_F1){ /* printrepr+>a */

if(!a_was(a_1288,a_F1)){ goto a_G9;}
if(!a_1326(a_F1,16)){ goto a_G4;}
a_1173(a_F1); return;
a_G4:{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(!(a_r1==16777304||a_r1==16777335)){ goto a_G6;}
}
a_1181(to_LIST(a_1288)->offset[a_F1]); return;
a_G6:a_putchar(a_1106,97);
a_putchar(a_1106,95);
a_1175(to_LIST(a_1288)->offset[a_F1]); return;
a_G9:a_1183(a_F1); return;
} /* printrepr */
static void a_1179(a_word a_F1){ /* printlocallabel+>a */

a_1178();
a_1175(a_F1); return;
} /* printlocallabel */
static void a_1174(a_word a_F1){ /* printgoto+>a */

{ if(a_F1==0||a_F1==-1){ goto a_G2;}
 if(a_F1==-2){  goto a_G5;}
  goto a_G6;}
a_G2:if(!a_1326(a_1209,512)){ goto a_G4;}
a_1490(a_1106,a_1001,2130706056); return;
a_G4:a_1490(a_1106,a_1001,2130706051); return;
a_G5:a_1490(a_1106,a_1001,2130706046); return;
a_G6:a_1490(a_1106,a_1001,2130706041);
a_1179(a_F1);
a_putchar(a_1106,59); return;
} /* printgoto */
static void a_1172(a_word a_F1){ /* printGOTO+>a */

if(!a_equal(a_F1,a_1163)){ goto a_G3;}
if(a_noteq(a_1163,0)){ return;}
a_G3:a_1174(a_F1); return;
} /* printGOTO */
static void a_1171(a_word a_F1){ /* printBUFFER+>a */

{register a_word a_r1=to_LIST(a_1447)->offset[a_F1];
 if(a_r1==16777471){ goto a_G2;}
 if(a_r1==16777455){ goto a_G4;}
 if(a_r1==16777479){ goto a_G6;}
 if(a_r1==16777459){ goto a_G8;}
 if(a_r1==16777475){  goto a_G10;}
  goto a_G12;}
a_G2:a_incr(a_F1);
a_1184(to_LIST(a_1447)->offset[a_F1]); return;
a_G4:a_incr(a_F1);
a_1175(to_LIST(a_1447)->offset[a_F1]); return;
a_G6:a_incr(a_F1);
a_1160(to_LIST(a_1447)->offset[a_F1]); return;
a_G8:a_incr(a_F1);
a_1181(to_LIST(a_1447)->offset[a_F1]); return;
a_G10:a_incr(a_F1);
a_1147(to_LIST(a_1447)->offset[a_F1]); return;
a_G12:a_1427(a_1001,2130706037); return;
} /* printBUFFER */
static void a_1183(a_word a_F1){ /* printptr+>a */
a_word a_P[1];
a_G1:if(!a_was(a_1288,a_F1)){ goto a_G3;}
a_F1=to_LIST(a_1288)->offset[a_F1-3]; goto a_G1;
a_G3:if(!a_was(a_1451,a_F1)){ goto a_G6;}
a_1460(a_F1,a_P);a_F1=a_P[0];
a_1490(a_1106,a_1451,a_F1); return;
a_G6:if(!a_was(a_1420,a_F1)){ goto a_G8;}
a_1490(a_1106,a_1420,a_F1); return;
a_G8:if(!a_was(a_1447,a_F1)){ goto a_G10;}
a_1171(a_F1); return;
a_G10:if(!a_equal(a_F1,0)){ goto a_G12;}
a_1490(a_1106,a_1001,2130706032); return;
a_G12:a_1427(a_1001,2130706028); return;
} /* printptr */
static void a_1180(a_word a_F1){ /* printnlptr+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_was(a_1451,a_F1)){ goto a_G15;}
a_1460(a_F1,a_P);a_F1=a_P[0];
{register a_word a_r1=to_LIST(a_1447)->aupb;a_L2=a_r1;a_L3=a_r1;}
a_unpackstring(a_1451,a_F1,a_1447);
a_G5:if(!a_lseq(to_LIST(a_1447)->aupb,a_L3)){ goto a_G7;}
a_unstackto(a_1447,a_L2); return;
a_G7:a_incr(a_L3);
if(!a_noteq(to_LIST(a_1447)->offset[a_L3],37)){ goto a_G10;}
a_G9:a_putchar(a_1106,to_LIST(a_1447)->offset[a_L3]); goto a_G5;
a_G10:a_incr(a_L3);
if(a_less(to_LIST(a_1447)->aupb,a_L3)){ goto a_G5;}
if(!a_equal(to_LIST(a_1447)->offset[a_L3],110)){ goto a_G14;}
a_putchar(a_1106,10); goto a_G5;
a_G14:a_putchar(a_1106,37); goto a_G9;
a_G15:a_1183(a_F1); return;
} /* printnlptr */
static void a_1181(a_word a_F1){ /* printnumber+>a */
a_word a_L2;a_word a_L3;
{register a_word a_r1=to_LIST(a_1447)->aupb;a_L2=a_r1;a_L3=a_r1;}
a_1011(a_F1);
a_G3:if(!a_lseq(to_LIST(a_1447)->aupb,a_L3)){ goto a_G5;}
a_unstackto(a_1447,a_L2); return;
a_G5:a_incr(a_L3);
a_putchar(a_1106,to_LIST(a_1447)->offset[a_L3]); goto a_G3;
} /* printnumber */
static void a_1105(a_word a_F1,a_word a_C,a_word *a_V){ /* T+t[]+@+>a */
a_word a_L2;a_word a_L3;
a_L3=to_LIST(a_1447)->aupb;
a_unpackstring(a_F1,a_V[0],a_1447);
a_add(a_L3,1,a_L2);
a_G4:if(a_less(to_LIST(a_1447)->aupb,a_L2)){ goto a_G29;}
if(!a_noteq(to_LIST(a_1447)->offset[a_L2],37)){ goto a_G8;}
a_G6:a_putchar(a_1106,to_LIST(a_1447)->offset[a_L2]);
a_G7:a_incr(a_L2); goto a_G4;
a_G8:a_incr(a_L2);
if(!a_more(a_L2,to_LIST(a_1447)->aupb)){ goto a_G11;}
a_putchar(a_1106,37); goto a_G29;
a_G11:{register a_word a_r1=to_LIST(a_1447)->offset[a_L2];
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
a_1184(a_V[0]); goto a_G7;
a_G14:a_putchar(a_1106,63); goto a_G7;
a_G15:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1174(a_V[0]); goto a_G7;
a_G17:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1172(a_V[0]); goto a_G7;
a_G19:a_1490(a_1106,a_1001,2130706023); goto a_G7;
a_G20:a_putchar(a_1106,10); goto a_G7;
a_G21:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1175(a_V[0]); goto a_G7;
a_G23:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1183(a_V[0]); goto a_G7;
a_G25:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1180(a_V[0]); goto a_G7;
a_G27:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1181(a_V[0]); goto a_G7;
a_G29:if(a_C<=1){ goto a_G31;} a_C--;a_V+=1;
a_1490(a_1106,a_1001,2130706019);
a_G31:a_unstackto(a_1447,a_L3); return;
} /* T */
static void a_1128(a_word a_A[1]){ /* calltracearg+a> */
a_word a_P[1];
if(!a_equal(a_1127,0)){ goto a_G3;}
a_A[0]=0; return;
a_G3:a_P[0]=2130706015;a_1105(a_1001,1,a_P);
a_A[0]=1; return;
} /* calltracearg */
static void a_1129(a_word a_A[1]){ /* calltracecall+a> */
a_word a_P[1];
if(!a_equal(a_1127,0)){ goto a_G3;}
a_A[0]=0; return;
a_G3:a_P[0]=2130706009;a_1105(a_1001,1,a_P);
a_A[0]=1; return;
} /* calltracecall */
static void a_1118(a_word a_F1){ /* addcallstack+>a */
a_word a_P[1];
if(a_equal(a_1127,0)){ return;}
if(!a_equal(a_F1,0)){ goto a_G4;}
a_P[0]=2130706005;a_1105(a_1001,1,a_P); return;
a_G4:a_P[0]=2130705994;a_1105(a_1001,1,a_P); return;
} /* addcallstack */
static void a_1211(void){ /* usecallstack */

a_1127=1; return;
} /* usecallstack */
static void a_1208(void){ /* targetprelude */
a_word a_L1;a_word a_L2;a_word a_P[4];
a_P[0]=2130705983;a_P[1]=2;a_P[2]=1;a_P[3]=32;a_1105(a_1001,4,a_P);
a_G2:a_1317(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ goto a_G8;}
if(!a_equal(to_LIST(a_1288)->offset[a_L1-3],0)){ goto a_G7;}
if(a_equal(to_LIST(a_1288)->offset[a_L1-4],0)){ goto a_G2;}
a_P[0]=2130705964;a_P[1]=to_LIST(a_1288)->offset[a_L1-4];a_1105(a_1001,2,a_P); goto a_G2;
a_G7:a_P[0]=2130705958;a_P[1]=a_L1;a_P[2]=to_LIST(a_1288)->offset[a_L1-4];a_1105(a_1001,3,a_P); goto a_G2;
a_G8:if(a_equal(a_1127,0)){ goto a_G10;}
a_P[0]=2130705952;a_1105(a_1001,1,a_P);
a_G10:a_P[0]=2130705941;a_P[1]=183666549;a_1105(a_1001,2,a_P);
a_L1=0;
a_G12:a_P[0]=a_L1;if(!a_1316(1,a_P)){ return;}a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=2130705941;a_P[1]=a_L2;a_1105(a_1001,2,a_P); goto a_G12;
} /* targetprelude */
static void a_1207(void){ /* targetpostlude */
a_word a_L1;a_word a_L2;a_word a_P[2];
a_L1=0;
a_G2:a_P[0]=a_L1;if(!a_1316(0,a_P)){ goto a_G4;}a_L1=a_P[0];a_L2=a_P[1];
a_P[0]=2130705941;a_P[1]=a_L2;a_1105(a_1001,2,a_P); goto a_G2;
a_G4:a_P[0]=2130705937;a_1105(a_1001,1,a_P); return;
} /* targetpostlude */
static void a_1202(a_word a_F1,a_word a_A[1]){ /* ruletyper+>a+a> */
a_word a_P[2];
if(!a_1326(a_F1,512)){ goto a_G3;}
a_P[0]=2130705932;a_P[1]=a_F1;a_1105(a_1001,2,a_P); goto a_G4;
a_G3:a_P[0]=2130705926;a_P[1]=a_F1;a_1105(a_1001,2,a_P);
a_G4:a_1128(a_P);a_A[0]=a_P[0]; return;
} /* ruletyper */
static void a_1122(a_word a_A[1]){ /* argsep+>a> */

if(!a_equal(a_A[0],0)){ goto a_G3;}
a_A[0]=1; return;
a_G3:a_putchar(a_1106,44); return;
} /* argsep */
static void a_1166(a_word a_F1,a_word a_A[1]){ /* outargs+>a+>a> */
a_word a_P[2];
if(a_equal(a_F1,0)){ return;}
a_P[0]=a_A[0];a_1122(a_P);a_A[0]=a_P[0];
a_P[0]=2130705920;a_P[1]=a_F1;a_1105(a_1001,2,a_P); return;
} /* outargs */
static void a_1198(a_word a_F1,a_word a_F2){ /* ruleargs+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[2];
a_1318(a_F1,a_P);a_L3=a_P[0];
a_L4=0;a_L6=0;
a_G3:if(!a_less(a_L4,a_L3)){ goto a_G15;}
a_1314(a_F1,a_L4,a_P);a_L5=a_P[0];
a_incr(a_L4);
if(a_equal(a_L5,16777376)){ goto a_G8;}
if(!a_equal(a_L5,16777382)){ goto a_G9;}
a_G8:a_incr(a_L6); goto a_G3;
a_G9:if(!a_equal(a_L5,16777388)){ goto a_G13;}
a_P[0]=a_F2;a_1166(a_L6,a_P);a_F2=a_P[0];
a_P[0]=a_F2;a_1122(a_P);
a_P[0]=2130705915;a_1105(a_1001,1,a_P); return;
a_G13:a_P[0]=a_F2;a_1122(a_P);a_F2=a_P[0];
a_P[0]=2130705909;a_P[1]=a_L4;a_1105(a_1001,2,a_P); goto a_G3;
a_G15:a_P[0]=a_F2;a_1166(a_L6,a_P);a_F2=a_P[0];
if(a_is(a_F2)){ goto a_G18;}
a_P[0]=2130705904;a_1105(a_1001,1,a_P);
a_G18:a_putchar(a_1106,41); return;
} /* ruleargs */
static void a_1212(a_word a_F1){ /* vardeclaration+>a */
a_word a_P[4];
if(a_1326(a_F1,16)){ return;}
a_P[0]=2130705900;a_P[1]=a_F1;a_P[2]=to_LIST(a_1288)->offset[a_F1-1];a_P[3]=a_F1;a_1105(a_1001,4,a_P); return;
} /* vardeclaration */
static void a_1124(a_word a_F1,a_word a_F2,a_word a_F3){ /* blockdeclaration+>a+>a+>a */
a_word a_P[3];
a_P[0]=2130705891;a_P[1]=a_F1;a_1105(a_1001,2,a_P);
if(!a_equal(a_F2,0)){ goto a_G4;}
a_P[0]=2130705885;a_1105(a_1001,1,a_P); goto a_G5;
a_G4:a_P[0]=2130705882;a_P[1]=a_F2;a_P[2]=a_F3;a_1105(a_1001,3,a_P);
a_G5:a_P[0]=2130705878;a_P[1]=a_F1;a_1105(a_1001,2,a_P); return;
} /* blockdeclaration */
static void a_1201(a_word a_F1){ /* ruleprototype+>a */
a_word a_L2;a_word a_P[2];
if(!a_1326(a_F1,12288)){ goto a_G4;}
if(!a_1328(a_F1)){ return;}
a_1213=1; return;
a_G4:if(a_1325(a_F1,a_P)){ return;}
if(a_1326(a_F1,16384)){ return;}
if(!a_1327(a_F1)){ goto a_G8;}
a_1291(2,a_F1); return;
a_G8:if(a_1326(a_F1,16)){ return;}
a_1202(a_F1,a_P);a_L2=a_P[0];
a_1198(a_F1,a_L2);
a_P[0]=2130705872;a_P[1]=a_F1;a_1105(a_1001,2,a_P); return;
} /* ruleprototype */
static void a_1197(a_word a_F1){ /* rootprototype+>a */
a_word a_L2;a_word a_P[2];
a_1202(a_F1,a_P);a_L2=a_P[0];
a_1198(a_F1,a_L2);
if(!a_equal(to_LIST(a_1288)->offset[a_F1-4],183666554)){ goto a_G5;}
a_P[0]=2130705866;a_1105(a_1001,1,a_P); return;
a_G5:a_incr(a_1161);
a_P[0]=2130705858;a_P[1]=to_LIST(a_1288)->offset[a_F1-4];a_1105(a_1001,2,a_P); return;
} /* rootprototype */
static void a_1134(void){ /* datadeclaration */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[4];
a_L1=to_LIST(a_1288)->alwb;
a_L2=0;a_L3=0;
a_G3:if(a_more(a_L1,to_LIST(a_1288)->aupb)){ goto a_G18;}
if(!a_1326(a_L1,8)){ goto a_G6;}
a_G5:a_next(a_1288,a_L1); goto a_G3;
a_G6:{register a_word a_r1=to_LIST(a_1288)->offset[a_L1-5];
 if(a_r1==16777309||a_r1==16777314){ goto a_G7;}
 if(a_r1==16777318||a_r1==16777322||a_r1==16777328){ goto a_G8;}
 if(a_r1==16777340){ goto a_G11;}
 if(a_r1==16777345){ goto a_G14;}
 if(a_r1==16777349){  goto a_G17;}
  goto a_G5;}
a_G7:a_1212(a_L1); goto a_G5;
a_G8:a_1124(a_L1,a_L2,a_L3);
a_L2=a_L1;
a_L3=2047260071; goto a_G5;
a_G11:a_1124(a_L1,a_L2,a_L3);
a_L2=a_L1;
a_L3=2047260077; goto a_G5;
a_G14:a_1124(a_L1,a_L2,a_L3);
a_L2=a_L1;
a_L3=2047260083; goto a_G5;
a_G17:a_1201(a_L1); goto a_G5;
a_G18:a_L4=0;
a_G19:a_P[0]=a_L4;if(!a_1316(2,a_P)){ goto a_G21;}a_L4=a_P[0];a_L1=a_P[1];
a_1197(a_L1); goto a_G19;
a_G21:if(!a_equal(a_L2,0)){ goto a_G23;}
a_P[0]=2130705851;a_P[1]=2047260088;a_1105(a_1001,2,a_P); goto a_G24;
a_G23:a_P[0]=2130705845;a_P[1]=2047260088;a_P[2]=a_L2;a_P[3]=a_L3;a_1105(a_1001,4,a_P);
a_G24:a_P[0]=2130705837;a_P[1]=2047260088;a_1105(a_1001,2,a_P); return;
} /* datadeclaration */
static void a_1187(a_word a_F1){ /* pushBUFFER+>a */

{register a_word *a_r1=a_extension(a_1447,1);a_r1[0]=a_F1;to_LIST(a_1447)->aupb+=1;}
  return;
} /* pushBUFFER */
static void a_1143(void){ /* filltablehead */
a_word a_P[1];
a_P[0]=2130705829;a_1105(a_1001,1,a_P);
a_1145=0; return;
} /* filltablehead */
static void a_1144(void){ /* filltabletail */
a_word a_P[2];
a_P[0]=2130705817;a_P[1]=a_1145;a_1105(a_1001,2,a_P); return;
} /* filltabletail */
static void a_1210(a_word a_A[1]){ /* untilnextcomma+>a> */

a_G1:if(!a_more(a_A[0],to_LIST(a_1447)->aupb)){ goto a_G3;}
a_1427(a_1001,2130705807); return;
a_G3:if(!a_equal(to_LIST(a_1447)->offset[a_A[0]],44)){ goto a_G6;}
a_putchar(a_1106,44);
a_incr(a_A[0]); return;
a_G6:a_putchar(a_1106,to_LIST(a_1447)->offset[a_A[0]]);
a_incr(a_A[0]); goto a_G1;
} /* untilnextcomma */
static void a_1132(void){ /* constitem */
a_word a_L1;
if(!a_equal(a_1461,16777459)){ goto a_G4;}
a_1011(a_1462);
a_1468(); return;
a_G4:if(!a_equal(16777471,a_1461)){ goto a_G7;}
a_L1=a_1462;
a_1468(); goto a_G8;
a_G7:a_1422(a_1001,2130705141); return;
a_G8:if(!a_1326(a_L1,8)){ goto a_G10;}
a_L1=to_LIST(a_1288)->offset[a_L1];
a_G10:a_1011(to_LIST(a_1288)->offset[a_L1]); return;
} /* constitem */
static void a_1141(a_word a_A[1]){ /* fillitem+a> */

if(!a_equal(16777427,a_1461)){ goto a_G9;}
a_1468();
a_A[0]=0;
a_G4:if(!a_equal(16777406,a_1461)){ goto a_G6;}
a_1468(); return;
a_G6:a_incr(a_A[0]);
a_1132();
a_1187(44); goto a_G4;
a_G9:a_A[0]=1;
a_1132();
a_1187(44); return;
} /* fillitem */
static a_word a_1142(a_word a_A[1]){ /* fillrepeater+a> */
a_word a_L2;a_word a_P[1];
if(!a_equal(16777445,a_1461)){ return 0;}
a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G6;}
a_A[0]=a_1462;
a_1468(); return 1;
a_G6:if(!a_equal(16777471,a_1461)){ goto a_G9;}
a_L2=a_1462;
a_1468(); goto a_G10;
a_G9:a_1422(a_1001,2130705141); return 1;
a_G10:if(!a_1326(a_L2,8)){ goto a_G12;}
a_L2=to_LIST(a_1288)->offset[a_L2];
a_G12:a_1014(to_LIST(a_1288)->offset[a_L2],a_P);a_A[0]=a_P[0]; return 1;
} /* fillrepeater */
static void a_1146(a_word a_F1,a_word a_F2,a_word a_F3){ /* flushbuffer+>a+>a+>a */
a_word a_P[2];
a_add(a_F1,a_1145,a_1145);
a_add(a_F2,a_1145,a_1145);
a_incr(a_F3);
if(a_equal(a_F1,0)){ goto a_G7;}
a_P[0]=2130705801;a_P[1]=a_F1;a_1105(a_1001,2,a_P);
a_incr(a_1145);
a_G7:if(a_equal(a_F1,0)){ goto a_G10;}
a_P[0]=a_F3;a_1210(a_P);a_F3=a_P[0];
a_decr(a_F1); goto a_G7;
a_G10:if(a_equal(a_F2,0)){ goto a_G13;}
a_P[0]=2130705801;a_P[1]=a_F2;a_1105(a_1001,2,a_P);
a_incr(a_1145);
a_G13:if(a_equal(a_F2,0)){ return;}
a_P[0]=a_F3;a_1210(a_P);a_F3=a_P[0];
a_decr(a_F2); goto a_G13;
} /* flushbuffer */
static void a_1204(void){ /* skipfillinitializer */

a_G1:if(!a_equal(16777409,a_1461)){ return;}
a_1468();
if(!a_equal(16777471,a_1461)){ goto a_G6;}

a_1468(); goto a_G1;
a_G6:a_1422(a_1001,2130705141); return;
} /* skipfillinitializer */
static void a_1149(void){ /* generatefillentries */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[3];
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130705141); return;
a_G5:if(!a_1326(a_L1,8)){ goto a_G7;}
a_L1=to_LIST(a_1288)->offset[a_L1];
a_G7:if(!a_equal(16777455,a_1461)){ goto a_G4;}

a_1468();
a_incr(a_1145);
a_P[0]=2130705798;a_P[1]=a_L1;a_P[2]=a_L1;a_1105(a_1001,3,a_P);
a_L2=to_LIST(a_1447)->aupb;
a_L3=0;
a_G14:if(!a_equal(16777439,a_1461)){ goto a_G16;}
a_1468(); goto a_G25;
a_G16:a_1141(a_P);a_L4=a_P[0];
if(!a_1142(a_P)){ goto a_G23;}a_L5=a_P[0];
a_1146(a_L3,a_L4,a_L2);
a_P[0]=2130705792;a_P[1]=a_L5;a_1105(a_1001,2,a_P);
a_incr(a_1145);
a_unstackto(a_1447,a_L2);
a_L3=0; goto a_G24;
a_G23:a_add(a_L3,a_L4,a_L3);
a_G24:a_1204(); goto a_G14;
a_G25:a_1146(a_L3,0,a_L2);
a_unstackto(a_1447,a_L2);
a_incr(a_1145);
a_P[0]=2130705788;a_1105(a_1001,1,a_P); return;
} /* generatefillentries */
static void a_1159(a_word a_F1,a_word a_F2){ /* listinitialization+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[9];
if(!a_1326(a_F2,16)){ goto a_G5;}
a_1310(a_F2,a_P);a_L3=a_P[0];
a_1320(a_F2,a_P);a_L4=a_P[0];
a_P[0]=2130705784;a_P[1]=a_L4;a_P[2]=a_F2;a_P[3]=a_F2;a_P[4]=a_L3;a_1105(a_1001,5,a_P); return;
a_G5:a_1310(a_F2,a_P);a_L3=a_P[0];
a_1321(a_F2,a_P);a_L5=a_P[0];
a_1320(a_F2,a_P);a_L4=a_P[0];
a_1313(a_F2,a_P);a_L6=a_P[0];
a_P[0]=2130705777;a_P[1]=a_F1;a_P[2]=a_F2;a_P[3]=a_F2;a_P[4]=a_L3;a_P[5]=a_L4;a_P[6]=a_L5;a_P[7]=a_L6;a_P[8]=a_F2;a_1105(a_1001,9,a_P); return;
} /* listinitialization */
static void a_1130(a_word a_F1){ /* charfileinitialization+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[7];
if(!a_1326(a_F1,16)){ goto a_G3;}
a_P[0]=2130705762;a_P[1]=to_LIST(a_1288)->offset[a_F1-1];a_P[2]=a_F1;a_P[3]=a_F1;a_1105(a_1001,4,a_P); return;
a_G3:if(!a_1326(a_F1,64)){ goto a_G5;}
a_L2=2; goto a_G6;
a_G5:a_L2=0;
a_G6:if(!a_1326(a_F1,32)){ goto a_G8;}
a_incr(a_L2);
a_G8:a_1312(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
if(!a_1326(a_L3,8)){ goto a_G11;}
a_L3=to_LIST(a_1288)->offset[a_L3];
a_G11:a_P[0]=2130705756;a_P[1]=a_F1;a_P[2]=a_F1;a_P[3]=a_L2;a_P[4]=a_L3;a_P[5]=a_L4;a_P[6]=a_F1;a_1105(a_1001,7,a_P); return;
} /* charfileinitialization */
static void a_1133(a_word a_F1,a_word a_A[1]){ /* countfilearea+>a+a> */
a_word a_L3;a_word a_P[1];
a_A[0]=1;
a_G2:a_1311(a_F1,a_A[0],a_P);a_L3=a_P[0];
if(!a_equal(a_L3,0)){ goto a_G5;}
a_decr(a_A[0]); return;
a_G5:a_incr(a_A[0]); goto a_G2;
} /* countfilearea */
static void a_1135(a_word a_F1){ /* datafileinitialization+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[8];
if(!a_1326(a_F1,16)){ goto a_G3;}
a_P[0]=2130705762;a_P[1]=to_LIST(a_1288)->offset[a_F1-1];a_P[2]=a_F1;a_P[3]=a_F1;a_1105(a_1001,4,a_P); return;
a_G3:if(!a_1326(a_F1,64)){ goto a_G5;}
a_L2=2; goto a_G6;
a_G5:a_L2=0;
a_G6:if(!a_1326(a_F1,32)){ goto a_G8;}
a_incr(a_L2);
a_G8:a_1312(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1133(a_F1,a_P);a_L6=a_P[0];
if(!a_1326(a_L3,8)){ goto a_G12;}
a_L3=to_LIST(a_1288)->offset[a_L3];
a_G12:a_P[0]=2130705742;a_P[1]=a_F1;a_P[2]=a_F1;a_P[3]=a_L2;a_P[4]=a_L3;a_P[5]=a_L4;a_P[6]=a_L6;a_P[7]=a_F1;a_1105(a_1001,8,a_P);
a_L6=1;
a_G14:a_1311(a_F1,a_L6,a_P);a_L5=a_P[0];
if(a_equal(a_L5,0)){ return;}
if(!a_1326(a_L5,8)){ goto a_G18;}
a_L5=to_LIST(a_1288)->offset[a_L5];
a_G18:a_P[0]=2130705728;a_P[1]=a_F1;a_P[2]=a_L5;a_P[3]=a_L6;a_P[4]=a_L5;a_1105(a_1001,5,a_P);
a_incr(a_L6); goto a_G14;
} /* datafileinitialization */
static void a_1136(void){ /* datainitialization */
a_word a_L1;a_word a_P[3];
a_P[0]=2130705716;a_1105(a_1001,1,a_P);
a_P[0]=2130705705;a_P[1]=183666532;a_P[2]=183666539;a_1105(a_1001,3,a_P);
a_L1=to_LIST(a_1288)->alwb;
a_G4:if(a_more(a_L1,to_LIST(a_1288)->aupb)){ goto a_G10;}
if(!a_1326(a_L1,8)){ goto a_G7;}
a_G6:a_next(a_1288,a_L1); goto a_G4;
a_G7:{register a_word a_r1=to_LIST(a_1288)->offset[a_L1-5];
 if(a_r1==16777318){ goto a_G8;}
 if(a_r1==16777322||a_r1==16777328){  goto a_G9;}
  goto a_G6;}
a_G8:a_1159(0,a_L1); goto a_G6;
a_G9:a_1159(1,a_L1); goto a_G6;
a_G10:a_L1=to_LIST(a_1288)->alwb;
a_G11:if(a_more(a_L1,to_LIST(a_1288)->aupb)){ goto a_G17;}
if(!a_1326(a_L1,8)){ goto a_G14;}
a_G13:a_next(a_1288,a_L1); goto a_G11;
a_G14:{register a_word a_r1=to_LIST(a_1288)->offset[a_L1-5];
 if(a_r1==16777340){ goto a_G15;}
 if(a_r1==16777345){  goto a_G16;}
  goto a_G13;}
a_G15:a_1130(a_L1); goto a_G13;
a_G16:a_1135(a_L1); goto a_G13;
a_G17:a_P[0]=2130705693;a_1105(a_1001,1,a_P); return;
} /* datainitialization */
static void a_1185(void){ /* procwaitfor */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[3];
a_P[0]=2130705684;a_1105(a_1001,1,a_P);
a_1128(a_P);a_L3=a_P[0];
a_P[0]=a_L3;a_1122(a_P);
a_P[0]=2130705676;a_1105(a_1001,1,a_P);
if(a_equal(a_1127,0)){ goto a_G7;}
a_P[0]=2130705669;a_1105(a_1001,1,a_P);
a_G7:a_L1=0;
a_G8:a_P[0]=a_L1;if(!a_1316(2,a_P)){ goto a_G11;}a_L1=a_P[0];a_L2=a_P[1];
if(a_equal(to_LIST(a_1288)->offset[a_L2-4],183666554)){ goto a_G8;}
a_P[0]=2130705658;a_P[1]=a_L2;a_P[2]=to_LIST(a_1288)->offset[a_L2-4];a_1105(a_1001,3,a_P); goto a_G8;
a_G11:a_P[0]=2130705650;a_1105(a_1001,1,a_P); return;
} /* procwaitfor */
static void a_1205(void){ /* targetmain */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[2];
if(a_equal(a_1213,0)){ goto a_G4;}
if(a_more(a_1161,0)){ goto a_G4;}
a_P[0]=2047260103;a_1443(1,a_P);
a_G4:if(!a_equal(a_1213,0)){ goto a_G6;}
if(a_equal(a_1161,0)){ goto a_G7;}
a_G6:a_1185();
a_G7:a_P[0]=2130705647;a_1105(a_1001,1,a_P);
if(a_equal(a_1127,0)){ goto a_G10;}
a_P[0]=2130705639;a_1105(a_1001,1,a_P);
a_G10:a_P[0]=2130705629;a_1105(a_1001,1,a_P);
a_L1=0;a_L4=0;
a_G12:a_P[0]=a_L1;if(!a_1316(2,a_P)){ goto a_G15;}a_L1=a_P[0];a_L2=a_P[1];
if(!a_equal(to_LIST(a_1288)->offset[a_L2-4],183666554)){ goto a_G12;}
a_L4=a_L2; goto a_G12;
a_G15:if(a_equal(a_1161,0)){ goto a_G20;}
a_P[0]=2130705622;a_1105(a_1001,1,a_P);
a_1129(a_P);a_L3=a_P[0];
a_P[0]=a_L3;a_1122(a_P);
a_P[0]=2130705617;a_1105(a_1001,1,a_P);
a_G20:if(!a_is(a_L4)){ goto a_G24;}
a_P[0]=2130705613;a_P[1]=a_L4;a_1105(a_1001,2,a_P);
a_1129(a_P);
a_P[0]=2130705609;a_1105(a_1001,1,a_P); return;
a_G24:a_1422(a_1001,2130705605); return;
} /* targetmain */
static void a_1203(a_word a_F1){ /* showformalsascomment+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
 static const char *a_rulename="showformalsascomment";
a_1318(a_F1,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_mreq(a_L3,a_L2)){ return;}
a_1314(a_F1,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
{ if(a_L4==16777371){ goto a_G7;}
 if(a_L4==16777376){ goto a_G8;}
 if(a_L4==16777382){ goto a_G9;}
 if(a_L4==16777361){ goto a_G10;}
 if(a_L4==16777355){ goto a_G11;}
 if(a_L4==16777366){ goto a_G12;}
 if(!(a_L4==16777388)){a_area_failed(a_rulename,a_L4);}
  goto a_G13;}
a_G7:a_P[0]=2130705600;a_1105(a_1001,1,a_P); goto a_G3;
a_G8:a_P[0]=2130705597;a_1105(a_1001,1,a_P); goto a_G3;
a_G9:a_P[0]=2130705594;a_1105(a_1001,1,a_P); goto a_G3;
a_G10:a_P[0]=2130705590;a_1105(a_1001,1,a_P); goto a_G3;
a_G11:a_P[0]=2130705586;a_1105(a_1001,1,a_P); goto a_G3;
a_G12:a_P[0]=2130705582;a_1105(a_1001,1,a_P); goto a_G3;
a_G13:a_P[0]=2130705578;a_1105(a_1001,1,a_P); goto a_G3;
} /* showformalsascomment */
static void a_1138(a_word a_F1,a_word a_F2,a_word a_F3){ /* declarelocals+>a+>a+>a */
a_word a_P[2];
a_G1:if(a_equal(a_F1,0)){ return;}
if(a_more(a_F1,a_F2)){ return;}
if(!a_equal(to_LIST(a_1447)->offset[a_F3],0)){ goto a_G6;}
a_G4:a_incr(a_F1);
a_incr(a_F3); goto a_G1;
a_G6:a_P[0]=2130705575;a_P[1]=a_F1;a_1105(a_1001,2,a_P); goto a_G4;
} /* declarelocals */
static void a_1137(a_word a_F1,a_word a_F2,a_word a_F3){ /* declarecallargs+>a+>a+>a */
a_word a_L4;a_word a_P[3];
if(a_equal(a_F2,0)){ goto a_G3;}
a_P[0]=2130705570;a_P[1]=a_F2;a_1105(a_1001,2,a_P);
a_G3:if(a_equal(a_F3,0)){ goto a_G6;}
a_1309(a_F1,a_P);a_L4=a_P[0];
a_P[0]=2130705565;a_P[1]=a_F3;a_P[2]=a_L4;a_1105(a_1001,3,a_P);
a_G6:a_putchar(a_1106,10); return;
} /* declarecallargs */
static void a_1199(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4,a_word a_F5,a_word a_F6,a_word a_F7,a_word a_F8){ /* ruledeclarationhead+>a+>a+>a+>a+>a+>a+>a+>a */
a_word a_L9;a_word a_P[2];
a_1209=a_F1;
a_1120();
a_1202(a_F1,a_P);a_L9=a_P[0];
a_1198(a_F1,a_L9);
a_P[0]=2130705553;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_1105(a_1001,2,a_P);
a_1203(a_F1);
a_P[0]=2130705549;a_1105(a_1001,1,a_P);
a_add(a_F5,a_F7,a_F7);
a_1138(a_F5,a_F6,a_F7);
a_1137(a_F1,a_F2,a_F3);
if(a_equal(a_1127,0)){ goto a_G13;}
a_F4=1;
a_G13:if(a_equal(a_F4,0)){ goto a_G15;}
a_P[0]=2130705545;a_P[1]=a_F1;a_1105(a_1001,2,a_P);
a_G15:a_1118(a_F8);
a_1119();
a_1121(); return;
} /* ruledeclarationhead */
static void a_1200(void){ /* ruledeclarationtail */
a_word a_P[2];
a_P[0]=2130705533;a_P[1]=a_1209;a_1105(a_1001,2,a_P); return;
} /* ruledeclarationtail */
static void a_1120(void){ /* addprofilingdef */
a_word a_P[4];
if(!a_1326(a_1209,33554432)){ return;}
if(!a_equal(a_1158,0)){ goto a_G4;}
a_P[0]=2130705527;a_P[1]=to_LIST(a_1288)->offset[a_1209];a_P[2]=a_1209;a_1105(a_1001,3,a_P); goto a_G5;
a_G4:a_P[0]=2130705516;a_P[1]=to_LIST(a_1288)->offset[a_1209];a_P[2]=a_1209;a_P[3]=to_LIST(a_1288)->offset[a_1158];a_1105(a_1001,4,a_P);
a_G5:a_1158=a_1209; return;
} /* addprofilingdef */
static void a_1119(void){ /* addprofilingcount */
a_word a_P[2];
if(!a_1326(a_1209,33554432)){ return;}
a_P[0]=2130705504;a_P[1]=to_LIST(a_1288)->offset[a_1209];a_1105(a_1001,2,a_P); return;
} /* addprofilingcount */
static void a_1186(void){ /* profilingdeclaration */
a_word a_P[2];
a_P[0]=2130705496;a_1105(a_1001,1,a_P);
if(!a_equal(a_1158,0)){ goto a_G4;}
a_P[0]=2130705488;a_1105(a_1001,1,a_P); return;
a_G4:a_P[0]=2130705484;a_P[1]=to_LIST(a_1288)->offset[a_1158];a_1105(a_1001,2,a_P); return;
} /* profilingdeclaration */
static void a_1121(void){ /* addtracing */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[2];
if(!a_1326(a_1209,16777216)){ return;}
a_1318(a_1209,a_P);a_L1=a_P[0];
a_L3=0;a_L2=0;
a_G4:if(a_mreq(a_L3,a_L1)){ goto a_G9;}
a_1314(a_1209,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
if(a_equal(a_L4,16777376)){ goto a_G4;}
a_incr(a_L2); goto a_G4;
a_G9:a_P[0]=2130705479;a_P[1]=a_L2;a_1105(a_1001,2,a_P);
a_L3=0;
a_G11:if(a_mreq(a_L3,a_L1)){ goto a_G17;}
a_1314(a_1209,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
if(a_equal(a_L4,16777376)){ goto a_G11;}
a_putchar(a_1106,44);
a_1147(a_L3); goto a_G11;
a_G17:a_P[0]=2130705470;a_1105(a_1001,1,a_P); return;
} /* addtracing */
static void a_1114(a_word a_F1,a_word a_F2){ /* Tlabel+>a+>a */

a_1163=a_F2;
if(a_equal(a_F1,0)){ return;}
a_1179(a_F1);
a_putchar(a_1106,58); return;
} /* Tlabel */
static void a_1157(a_word a_F1){ /* jumptolabel+>a */
a_word a_P[2];
if(a_equal(a_F1,a_1163)){ return;}
a_P[0]=2130705466;a_P[1]=a_F1;a_1105(a_1001,2,a_P); return;
} /* jumptolabel */
static void a_1107(a_word a_F1){ /* Taffix+>a */
a_word a_P[1];
{register a_word a_r1=to_LIST(a_1447)->offset[a_F1];
 if(a_r1==16777409){ goto a_G2;}
 if(a_r1==16777424){  return;}
  goto a_G3;}
a_G2:a_incr(a_F1);
a_G3:a_P[0]=a_F1;a_1108(a_P); return;
} /* Taffix */
static void a_1108(a_word a_A[1]){ /* Taffixinner+>a> */
a_word a_L2;a_word a_P[3];
{register a_word a_r1=to_LIST(a_1447)->offset[a_A[0]];
 if(a_r1==16777475||a_r1==16777479||a_r1==16777471){ goto a_G2;}
 if(a_r1==16777459){ goto a_G2;}
 if(a_r1==16777448){  goto a_G5;}
  goto a_G7;}
a_G2:a_P[0]=2130705462;a_P[1]=a_A[0];a_1105(a_1001,2,a_P);
a_G3:a_incr(a_A[0]);
a_incr(a_A[0]); return;
a_G5:a_incr(a_A[0]);
a_P[0]=a_A[0];a_1112(a_P);a_A[0]=a_P[0]; return;
a_G7:a_1115(to_LIST(a_1447)->offset[a_A[0]],a_P);a_L2=a_P[0];
a_incr(a_A[0]);
a_P[0]=2130705459;a_P[1]=a_A[0];a_P[2]=a_L2;a_1105(a_1001,3,a_P); goto a_G3;
} /* Taffixinner */
static void a_1115(a_word a_F1,a_word a_A[1]){ /* Tlimittail+>a+a> */

{ if(a_F1==16777231){ goto a_G2;}
 if(a_F1==16777269){ goto a_G3;}
 if(a_F1==16777291){ goto a_G4;}
 if(a_F1==16777295){ goto a_G5;}
 if(a_F1==16777299){  goto a_G6;}
  goto a_G7;}
a_G2:a_A[0]=2047260107; return;
a_G3:a_A[0]=2047260111; return;
a_G4:a_A[0]=2047260115; return;
a_G5:a_A[0]=2047260119; return;
a_G6:a_A[0]=2047260123; return;
a_G7:a_1427(a_1001,2130705453); return;
} /* Tlimittail */
static void a_1112(a_word a_A[1]){ /* Tindex+>a> */
a_word a_L2;a_word a_P[2];
if(!a_1326(a_1209,67108864)){ goto a_G13;}
a_P[0]=2130705448;a_P[1]=a_A[0];a_1105(a_1001,2,a_P);
a_1129(a_P);a_L2=a_P[0];
a_P[0]=a_L2;a_1122(a_P);
a_P[0]=2130705438;a_P[1]=a_A[0];a_1105(a_1001,2,a_P);
a_incr(a_A[0]);
a_incr(a_A[0]);
a_P[0]=a_A[0];a_1108(a_P);a_A[0]=a_P[0];
a_incr(a_A[0]);
a_subtr(to_LIST(a_1447)->offset[a_A[0]],1,a_L2);
a_incr(a_A[0]);
a_P[0]=2130705435;a_P[1]=a_L2;a_1105(a_1001,2,a_P); return;
a_G13:a_P[0]=2130705428;a_P[1]=a_A[0];a_1105(a_1001,2,a_P);
a_incr(a_A[0]);
a_incr(a_A[0]);
a_P[0]=a_A[0];a_1108(a_P);a_A[0]=a_P[0];
a_incr(a_A[0]);
a_subtr(to_LIST(a_1447)->offset[a_A[0]],1,a_L2);
a_incr(a_A[0]);
if(!a_equal(a_L2,0)){ goto a_G22;}
a_P[0]=2130705420;a_1105(a_1001,1,a_P); return;
a_G22:a_P[0]=2130705417;a_P[1]=a_L2;a_1105(a_1001,2,a_P); return;
} /* Tindex */
static void a_1140(a_word a_F1,a_word a_F2){ /* extensionblock+>a+>a */
a_word a_L3;a_word a_L4;a_word a_P[3];
a_incr(a_F2);
a_L3=a_F2;
a_G3:if(a_equal(to_LIST(a_1447)->offset[a_L3],16777436)){ goto a_G5;}
a_incr(a_L3); goto a_G3;
a_G5:a_incr(a_L3);
a_G6:if(a_less(to_LIST(a_1447)->offset[a_L3],0)){ goto a_G10;}
a_subtr(a_F1,to_LIST(a_1447)->offset[a_L3],a_L4);
a_incr(a_L3);
a_P[0]=2130705413;a_P[1]=2047260127;a_P[2]=a_L4;a_1105(a_1001,3,a_P); goto a_G6;
a_G10:a_1107(a_F2);
a_putchar(a_1106,59); return;
} /* extensionblock */
static void a_1110(a_word a_F1,a_word a_F2){ /* Textension+>a+>a */
a_word a_L3;a_word a_L4;a_word a_P[4];
a_incr(a_F1);
a_L4=to_LIST(a_1447)->offset[a_F1];
a_incr(a_F1);
a_L3=a_F1;
a_P[0]=2130705409;a_P[1]=2047260127;a_P[2]=a_L3;a_P[3]=a_L4;a_1105(a_1001,4,a_P);
a_add(2,a_F1,a_F1);
a_G7:a_1140(a_L4,a_F1);
a_F1=to_LIST(a_1447)->offset[a_F1];
if(!a_equal(a_F1,0)){ goto a_G7;}
a_P[0]=2130705397;a_P[1]=a_L3;a_P[2]=a_L4;a_1105(a_1001,3,a_P);
a_1157(a_F2); return;
} /* Textension */
static a_word a_1164(a_word a_F1,a_word a_F2){ /* numbersequal+>a+>a */
a_word a_L3;a_word a_P[1];
a_1017(0,a_F1,a_P);a_F1=a_P[0];
a_1017(0,a_F2,a_P);a_F2=a_P[0];
if(!a_1378(23,a_F1,a_F2)){ goto a_G5;}
a_L3=1; goto a_G6;
a_G5:a_L3=0;
a_G6:a_1369(a_F1);
a_1369(a_F2);
if(!a_is(a_L3)){ return 0;} return 1;
} /* numbersequal */
static void a_1125(a_word a_F1,a_word a_A[1]){ /* boxclassifier+>a+a> */
a_word a_P[2];
{register a_word a_r1=to_LIST(a_1447)->offset[a_F1];
 if(!(a_r1==16777471||a_r1==16777479||a_r1==16777475||a_r1==16777459)){ goto a_G3;}
}
a_A[0]=a_F1; return;
a_G3:a_A[0]=2047260127;
a_P[0]=2130705388;a_P[1]=a_A[0];a_1105(a_1001,2,a_P);
a_1107(a_F1);
a_P[0]=2130705382;a_1105(a_1001,1,a_P); return;
} /* boxclassifier */
static a_word a_1154(a_word a_F1){ /* iscompletearea+>a */

if(!a_equal(to_LIST(a_1447)->offset[a_F1],0)){ return 0;}
a_incr(a_F1);
a_incr(a_F1);
if(!a_equal(to_LIST(a_1447)->offset[a_F1],a_1026)){ return 0;}
a_incr(a_F1);
if(!a_equal(to_LIST(a_1447)->offset[a_F1],a_1025)){ return 0;} return 1;
} /* iscompletearea */
static void a_1117(a_word a_F1,a_word a_F2,a_word a_F3){ /* Tsingleifcondition+>a+>a+>a */
a_word a_P[5];
if(!a_1164(a_F1,a_F2)){ goto a_G3;}
a_P[0]=2130705379;a_P[1]=a_F3;a_P[2]=a_F1;a_1105(a_1001,3,a_P); return;
a_G3:if(!a_1164(a_F1,a_1026)){ goto a_G5;}
a_P[0]=2130705375;a_P[1]=a_F3;a_P[2]=a_F2;a_1105(a_1001,3,a_P); return;
a_G5:if(!a_1164(a_F2,a_1025)){ goto a_G7;}
a_P[0]=2130705371;a_P[1]=a_F3;a_P[2]=a_F1;a_1105(a_1001,3,a_P); return;
a_G7:a_P[0]=2130705367;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_F3;a_P[4]=a_F2;a_1105(a_1001,5,a_P); return;
} /* Tsingleifcondition */
static void a_1111(a_word a_F1,a_word a_F2){ /* Tifcondition+>a+>a */
a_word a_L3;a_word a_L4;a_word a_P[1];
a_G1:a_incr(a_F1);
a_L3=to_LIST(a_1447)->offset[a_F1];
a_incr(a_F1);
a_L4=to_LIST(a_1447)->offset[a_F1];
a_1117(a_L3,a_L4,a_F2);
a_incr(a_F1);
if(!a_equal(to_LIST(a_1447)->offset[a_F1],16777442)){ return;}
a_P[0]=2130705360;a_1105(a_1001,1,a_P); goto a_G1;
} /* Tifcondition */
static void a_1113(a_word a_F1,a_word a_F2){ /* Tjumptoareas+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
a_G1:a_L5=to_LIST(a_1447)->offset[a_F1];
if(!a_equal(a_L5,0)){ goto a_G10;}
a_incr(a_F1);
a_L3=to_LIST(a_1447)->offset[a_F1];
a_P[0]=2130705357;a_1105(a_1001,1,a_P);
a_1111(a_F1,a_F2);
a_P[0]=2130705353;a_P[1]=a_F2;a_1105(a_1001,2,a_P);
if(a_equal(a_L3,a_1163)){ return;}
a_P[0]=2130705342;a_P[1]=to_LIST(a_1447)->offset[a_F1];a_1105(a_1001,2,a_P); return;
a_G10:if(!a_1154(a_L5)){ goto a_G25;}
a_incr(a_F1);
a_L3=to_LIST(a_1447)->offset[a_F1];
a_incr(a_L5);
a_L4=to_LIST(a_1447)->offset[a_L5];
if(!a_equal(a_L3,a_1163)){ goto a_G20;}
if(a_equal(a_L3,a_L4)){ return;}
a_P[0]=2130705357;a_1105(a_1001,1,a_P);
a_1111(a_F1,a_F2);
a_P[0]=2130705339;a_P[1]=a_L4;a_1105(a_1001,2,a_P); return;
a_G20:a_P[0]=2130705334;a_1105(a_1001,1,a_P);
a_1111(a_F1,a_F2);
a_P[0]=2130705330;a_P[1]=a_L3;a_1105(a_1001,2,a_P);
if(a_equal(a_L4,a_1163)){ return;}
a_P[0]=2130705342;a_P[1]=a_L4;a_1105(a_1001,2,a_P); return;
a_G25:a_incr(a_F1);
a_P[0]=2130705334;a_1105(a_1001,1,a_P);
a_1111(a_F1,a_F2);
a_P[0]=2130705325;a_P[1]=to_LIST(a_1447)->offset[a_F1];a_1105(a_1001,2,a_P);
a_F1=a_L5; goto a_G1;
} /* Tjumptoareas */
static void a_1109(a_word a_F1,a_word a_F2){ /* Tbox+>a+>a */
a_word a_L3;a_word a_P[1];
a_P[0]=2130705321;a_1105(a_1001,1,a_P);
a_incr(a_F1);
a_1125(a_F1,a_P);a_L3=a_P[0];
a_incr(a_F2);
a_1113(a_F2,a_L3);
a_P[0]=2130705650;a_1105(a_1001,1,a_P); return;
} /* Tbox */
static void a_1116(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4,a_word a_F5,a_word a_F6,a_word a_F7){ /* Trulecall+>a+>a+>a+>a+>a+>a+>a */
a_word a_L8;a_word a_L9;a_word a_P[3];
a_1126=a_F1;
a_incr(a_F7);
if(!a_1156(a_F7,a_F3,a_F4)){ goto a_G5;}
a_P[0]=2130705318;a_P[1]=a_F1;a_P[2]=a_F4;a_1105(a_1001,3,a_P); return;
a_G5:if(!a_1328(a_F1)){ goto a_G7;}
a_1152(a_F7,a_F4); return;
a_G7:if(!a_1324(a_F1)){ goto a_G9;}
a_1148(a_F5,a_F6,a_F7,a_F4); return;
a_G9:if(!a_1325(a_F1,a_P)){ goto a_G13;}a_L8=a_P[0];
if(!a_equal(a_L8,1)){ goto a_G12;}
a_1151(a_F3,a_F4); return;
a_G12:a_1150(a_F2,a_F7,a_F4); return;
a_G13:if(!a_1326(a_F1,12288)){ goto a_G18;}
a_1188(a_F3,a_F4,a_P);a_L9=a_P[0];
a_1170(a_F7);
a_1189(a_L9,a_F3);
a_G17:a_1190(a_L9,a_F3,a_F4); return;
a_G18:a_1192(a_F7);
a_1188(a_F3,a_F4,a_P);a_L9=a_P[0];
a_1193(a_F7);
a_1189(a_L9,a_F3);
a_1191(a_F7); goto a_G17;
} /* Trulecall */
static void a_1162(a_word a_A[1]){ /* nextaffix+>a> */

a_G1:if(!a_equal(to_LIST(a_1447)->offset[a_A[0]],16777436)){ goto a_G3;}
a_incr(a_A[0]); return;
a_G3:a_incr(a_A[0]); goto a_G1;
} /* nextaffix */
static a_word a_1155(a_word a_F1){ /* isdummyaffix+>a */

{register a_word a_r1=to_LIST(a_1447)->offset[a_F1];
 if(a_r1==16777424||a_r1==16777409){  return 1;}
  return 0;}
} /* isdummyaffix */
static a_word a_1153(a_word a_F1){ /* hasoutaffix+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1318(a_1126,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_mreq(a_L3,a_L2)){ return 0;}
if(!a_1155(a_F1)){ goto a_G7;}
a_G5:a_incr(a_L3);
a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0]; goto a_G3;
a_G7:a_1314(a_1126,a_L3,a_P);a_L4=a_P[0];
if(a_equal(a_L4,16777376)){ return 1;}
if(a_equal(a_L4,16777382)){ return 1;}
if(a_equal(a_L4,16777388)){ return 1;} goto a_G5;
} /* hasoutaffix */
static a_word a_1156(a_word a_F1,a_word a_F2,a_word a_F3){ /* isrulediscarded+>a+>a+>a */

if(a_1326(a_1126,256)){ return 0;}
if(a_1326(a_1126,1024)){ return 0;}
if(a_1326(a_1126,32768)){ return 0;}
if(a_1153(a_F1)){ return 0;}
if(!a_1326(a_1126,512)){ return 1;}
if(!a_equal(a_F2,a_F3)){ return 0;} return 1;
} /* isrulediscarded */
static void a_1151(a_word a_F1,a_word a_F2){ /* genshiftaffix+>a+>a */
a_word a_L3;a_word a_P[4];
a_1309(a_1209,a_P);a_L3=a_P[0];
if(a_equal(a_F1,a_1163)){ goto a_G6;}
if(!a_equal(a_F1,a_F2)){ goto a_G5;}
a_F2=a_1163; goto a_G6;
a_G5:if(!a_noteq(a_F2,a_1163)){ goto a_G7;}
a_G6:a_P[0]=2130705312;a_P[1]=a_L3;a_P[2]=a_F2;a_P[3]=a_F1;a_1105(a_1001,4,a_P); return;
a_G7:a_P[0]=2130705301;a_P[1]=a_F1;a_P[2]=a_L3;a_1105(a_1001,3,a_P); return;
} /* genshiftaffix */
static void a_1150(a_word a_F1,a_word a_F2,a_word a_F3){ /* gengetaffixno+>a+>a+>a */
a_word a_P[2];
if(!a_noteq(a_F1,2)){ goto a_G3;}
a_1422(a_1001,2130705291); return;
a_G3:if(!a_1155(a_F2)){ goto a_G5;}
a_P[0]=2130705285;a_P[1]=a_F3;a_1105(a_1001,2,a_P); return;
a_G5:a_1107(a_F2);
a_P[0]=2130705281;a_P[1]=a_F3;a_1105(a_1001,2,a_P); return;
} /* gengetaffixno */
static void a_1152(a_word a_F1,a_word a_F2){ /* genwaitfor+>a+>a */
a_word a_L3;a_word a_P[2];
a_P[0]=2130705622;a_1105(a_1001,1,a_P);
a_1129(a_P);a_L3=a_P[0];
a_P[0]=a_L3;a_1122(a_P);a_L3=a_P[0];
a_1107(a_F1);
a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0];
a_P[0]=a_L3;a_1122(a_P);
a_1107(a_F1);
a_P[0]=2130705276;a_P[1]=a_F2;a_1105(a_1001,2,a_P); return;
} /* genwaitfor */
static void a_1123(a_word a_F1,a_word a_F2,a_word a_A[2]){ /* assignmentsource+>a+>a+a>+a> */
a_word a_P[2];
{register a_word a_r1=to_LIST(a_1447)->offset[a_F1];
 if(!(a_r1==16777471||a_r1==16777479||a_r1==16777475||a_r1==16777459)){ goto a_G7;}
}
a_A[0]=a_F1;
if(!a_is(a_F2)){ goto a_G6;}
a_P[0]=2130705272;a_P[1]=2047260131;a_1105(a_1001,2,a_P);
a_G5:a_A[1]=1; return;
a_G6:a_A[1]=0; return;
a_G7:a_A[0]=2047260127;
a_P[0]=2130705265;a_P[1]=a_A[0];a_1105(a_1001,2,a_P);
a_1107(a_F1);
if(!a_is(a_F2)){ goto a_G12;}
a_P[0]=2130705258;a_P[1]=2047260131;a_1105(a_1001,2,a_P);
a_G12:a_putchar(a_1106,59); goto a_G5;
} /* assignmentsource */
static void a_1148(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4){ /* genassignment+>a+>a+>a+>a */
a_word a_L5;a_word a_L6;a_word a_L7;a_word a_L8;a_word a_L9;a_word a_P[6];
a_L5=a_F3;
a_P[0]=a_F3;a_1162(a_P);a_F3=a_P[0];
a_L8=0;
a_L9=1;
a_G5:if(a_mreq(a_L9,a_F1)){ goto a_G10;}
a_incr(a_L9);
a_P[0]=a_F3;a_1162(a_P);a_F3=a_P[0];
{register a_word a_r1=to_LIST(a_1447)->offset[a_F3];
 if(a_r1==16777397||a_r1==16777424||a_r1==16777409){  goto a_G5;}
}
a_incr(a_L8); goto a_G5;
a_G10:if(a_more(a_L8,1)){ goto a_G12;}
if(!a_is(a_F2)){ goto a_G13;}
a_G12:a_1123(a_L5,a_F2,a_P);a_L6=a_P[0];a_L7=a_P[1]; goto a_G14;
a_G13:a_L6=0;a_L7=0;
a_G14:a_F3=a_L5;
a_P[0]=a_F3;a_1162(a_P);a_F3=a_P[0];
a_L9=1;
a_G17:if(a_mreq(a_L9,a_F1)){ goto a_G27;}
a_incr(a_L9);
a_P[0]=a_F3;a_1162(a_P);a_F3=a_P[0];
{register a_word a_r1=to_LIST(a_1447)->offset[a_F3];
 if(a_r1==16777397||a_r1==16777424||a_r1==16777409){  goto a_G17;}
}
a_1107(a_F3);
if(!a_equal(a_L6,0)){ goto a_G26;}
a_putchar(a_1106,61);
a_1107(a_L5);
a_putchar(a_1106,59); goto a_G17;
a_G26:a_P[0]=2130705255;a_P[1]=a_L6;a_1105(a_1001,2,a_P); goto a_G17;
a_G27:if(a_equal(a_F2,0)){ goto a_G29;}
a_P[0]=2130705251;a_P[1]=2047260131;a_P[2]=2047260131;a_P[3]=2047260131;a_P[4]=2047260131;a_P[5]=a_L6;a_1105(a_1001,6,a_P);
a_G29:if(a_equal(a_L7,0)){ goto a_G31;}
a_putchar(a_1106,125);
a_G31:a_P[0]=2130705285;a_P[1]=a_F4;a_1105(a_1001,2,a_P); return;
} /* genassignment */
static void a_1196(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4){ /* repeatblockpreload+>a+>a+>a+>a */
a_word a_L5;a_word a_L6;a_word a_L7;a_word a_L8;a_word a_L9;a_word a_P[3];
a_incr(a_F1);
a_L5=to_LIST(a_1447)->offset[a_F1];
a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0];
a_L9=a_F3;
if(!a_less(a_L5,0)){ goto a_G8;}
a_F4=0;
a_subtr(0,a_L5,a_L7); goto a_G9;
a_G8:a_L7=a_L5;
a_G9:a_1309(a_1126,a_P);a_L6=a_P[0];
a_mult(a_L7,a_L6,a_L7);
a_G11:if(a_equal(a_L7,0)){ goto a_G25;}
a_1314(a_1126,a_L9,a_P);a_L8=a_P[0];
if(a_equal(a_L8,16777376)){ goto a_G19;}
if(!a_more(a_L5,0)){ goto a_G18;}
a_P[0]=2130705240;a_P[1]=a_F4;a_1105(a_1001,2,a_P);
a_G16:a_1107(a_F1);
a_putchar(a_1106,59); goto a_G19;
a_G18:a_P[0]=2130705235;a_P[1]=a_F4;a_1105(a_1001,2,a_P); goto a_G16;
a_G19:a_incr(a_L9);
if(a_less(a_L9,a_F2)){ goto a_G22;}
a_L9=a_F3;
a_G22:a_decr(a_L7);
a_incr(a_F4);
a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0]; goto a_G11;
a_G25:if(a_mreq(a_L5,0)){ return;}
a_P[0]=2130705230;a_P[1]=a_F4;a_P[2]=a_L6;a_1105(a_1001,3,a_P); return;
} /* repeatblockpreload */
static void a_1192(a_word a_F1){ /* regularcallpreload+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
a_1318(a_1126,a_P);a_L2=a_P[0];
a_L3=0;a_L4=0;
a_G3:if(a_equal(a_L3,a_L2)){ return;}
a_1314(a_1126,a_L3,a_P);a_L5=a_P[0];
a_incr(a_L3);
if(!a_equal(a_L5,16777376)){ goto a_G9;}
a_incr(a_L4);
a_G8:a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0]; goto a_G3;
a_G9:if(!a_equal(a_L5,16777382)){ goto a_G14;}
a_P[0]=2130705240;a_P[1]=a_L4;a_1105(a_1001,2,a_P);
a_incr(a_L4);
a_1107(a_F1);
a_putchar(a_1106,59); goto a_G8;
a_G14:if(!a_equal(a_L5,16777388)){ goto a_G8;}
a_1196(a_F1,a_L2,a_L3,a_L4); return;
} /* regularcallpreload */
static void a_1194(a_word a_F1,a_word a_F2,a_word a_F3){ /* repeatblockcall+>a+>a+>a */
a_word a_L4;a_word a_P[3];
if(a_equal(a_F2,0)){ goto a_G4;}
a_P[0]=a_F3;a_1122(a_P);a_F3=a_P[0];
a_P[0]=2130705218;a_1105(a_1001,1,a_P);
a_G4:a_incr(a_F1);
a_L4=to_LIST(a_1447)->offset[a_F1];
a_P[0]=a_F3;a_1122(a_P);
if(!a_equal(a_L4,0)){ goto a_G9;}
a_P[0]=2130705215;a_1105(a_1001,1,a_P); return;
a_G9:if(!a_less(a_L4,0)){ goto a_G12;}
a_subtr(0,a_L4,a_L4);
a_P[0]=2130705210;a_P[1]=a_L4;a_1105(a_1001,2,a_P); return;
a_G12:if(!a_equal(a_F2,0)){ goto a_G14;}
a_P[0]=2130705205;a_P[1]=a_L4;a_1105(a_1001,2,a_P); return;
a_G14:a_P[0]=2130705201;a_P[1]=a_L4;a_P[2]=a_F2;a_1105(a_1001,3,a_P); return;
} /* repeatblockcall */
static void a_1193(a_word a_F1){ /* regularrulecall+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[2];
a_1318(a_1126,a_P);a_L2=a_P[0];
a_P[0]=2130705196;a_P[1]=a_1126;a_1105(a_1001,2,a_P);
a_L3=0;a_L4=0;
if(!a_1326(a_1126,16)){ goto a_G6;}
a_L5=0; goto a_G7;
a_G6:a_1129(a_P);a_L5=a_P[0];
a_G7:if(!a_equal(a_L3,a_L2)){ goto a_G12;}
if(!a_equal(a_L4,0)){ goto a_G10;}
a_putchar(a_1106,41); return;
a_G10:a_P[0]=a_L5;a_1122(a_P);
a_P[0]=2130705193;a_1105(a_1001,1,a_P); return;
a_G12:a_1314(a_1126,a_L3,a_P);a_L6=a_P[0];
a_incr(a_L3);
if(a_equal(a_L6,16777376)){ goto a_G16;}
if(!a_equal(a_L6,16777382)){ goto a_G18;}
a_G16:a_incr(a_L4);
a_G17:a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0]; goto a_G7;
a_G18:if(!a_equal(a_L6,16777388)){ goto a_G20;}
a_1194(a_F1,a_L4,a_L5); return;
a_G20:a_P[0]=a_L5;a_1122(a_P);a_L5=a_P[0];
a_1107(a_F1); goto a_G17;
} /* regularrulecall */
static void a_1195(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_F4){ /* repeatblockpostload+>a+>a+>a+>a */
a_word a_L5;a_word a_L6;a_word a_L7;a_word a_L8;a_word a_L9;a_word a_P[3];
a_incr(a_F1);
a_L5=to_LIST(a_1447)->offset[a_F1];
a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0];
a_L7=a_F3;
if(!a_less(a_L5,0)){ goto a_G8;}
a_F4=0;
a_subtr(0,a_L5,a_L8); goto a_G9;
a_G8:a_L8=a_L5;
a_G9:a_1309(a_1126,a_P);a_L6=a_P[0];
a_mult(a_L8,a_L6,a_L8);
a_G11:if(a_equal(a_L8,0)){ goto a_G26;}
a_1314(a_1126,a_L7,a_P);a_L9=a_P[0];
if(a_1155(a_F1)){ goto a_G20;}
if(a_equal(a_L9,16777376)){ goto a_G16;}
if(!a_equal(a_L9,16777382)){ goto a_G20;}
a_G16:a_1107(a_F1);
if(!a_more(a_L5,0)){ goto a_G19;}
a_P[0]=2130705189;a_P[1]=a_F4;a_1105(a_1001,2,a_P); goto a_G20;
a_G19:a_P[0]=2130705184;a_P[1]=a_F4;a_1105(a_1001,2,a_P);
a_G20:a_incr(a_L7);
if(a_less(a_L7,a_F2)){ goto a_G23;}
a_L7=a_F3;
a_G23:a_decr(a_L8);
a_incr(a_F4);
a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0]; goto a_G11;
a_G26:if(a_mreq(a_L5,0)){ return;}
a_P[0]=2130705179;a_P[1]=a_F4;a_P[2]=a_L6;a_1105(a_1001,3,a_P); return;
} /* repeatblockpostload */
static void a_1191(a_word a_F1){ /* regularcallpostload+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
a_1318(a_1126,a_P);a_L2=a_P[0];
a_L3=0;a_L4=0;
a_G3:if(a_equal(a_L3,a_L2)){ return;}
a_1314(a_1126,a_L3,a_P);a_L5=a_P[0];
a_incr(a_L3);
if(a_equal(a_L5,16777376)){ goto a_G8;}
if(!a_equal(a_L5,16777382)){ goto a_G13;}
a_G8:if(a_1155(a_F1)){ goto a_G11;}
a_1107(a_F1);
a_P[0]=2130705189;a_P[1]=a_L4;a_1105(a_1001,2,a_P);
a_G11:a_incr(a_L4);
a_G12:a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0]; goto a_G3;
a_G13:if(!a_equal(a_L5,16777388)){ goto a_G12;}
a_1195(a_F1,a_L2,a_L3,a_L4); return;
} /* regularcallpostload */
static void a_1188(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* regularcalld1+>a+>a+a> */
a_word a_P[1];
if(!a_1326(a_1126,512)){ goto a_G9;}
if(!a_noteq(a_F1,a_1163)){ goto a_G7;}
if(a_equal(a_F2,a_1163)){ goto a_G5;}
if(!a_lseq(a_F1,0)){ goto a_G7;}
a_G5:a_A[0]=2;
a_P[0]=2130705167;a_1105(a_1001,1,a_P); return;
a_G7:a_A[0]=1;
a_P[0]=2130705163;a_1105(a_1001,1,a_P); return;
a_G9:a_A[0]=0; return;
} /* regularcalld1 */
static void a_1189(a_word a_F1,a_word a_F2){ /* regularcalld2+>a+>a */
a_word a_P[2];
if(!a_equal(a_F1,1)){ goto a_G3;}
a_P[0]=2130705160;a_1105(a_1001,1,a_P); return;
a_G3:if(!a_equal(a_F1,2)){ goto a_G5;}
a_P[0]=2130705157;a_P[1]=a_F2;a_1105(a_1001,2,a_P); return;
a_G5:a_putchar(a_1106,59); return;
} /* regularcalld2 */
static void a_1190(a_word a_F1,a_word a_F2,a_word a_F3){ /* regularcalld3+>a+>a+>a */
a_word a_P[3];
if(!a_equal(a_F1,1)){ goto a_G4;}
a_P[0]=2130705153;a_P[1]=a_F3;a_P[2]=a_F2;a_1105(a_1001,3,a_P); return;
a_G4:a_P[0]=2130705285;a_P[1]=a_F3;a_1105(a_1001,2,a_P); return;
} /* regularcalld3 */
static void a_1167(a_word a_F1){ /* pidginalttagtail+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1318(a_1126,a_P);a_L2=a_P[0];
a_L3=0;
a_G3:if(a_equal(a_L3,a_L2)){ return;}
a_1314(a_1126,a_L3,a_P);a_L4=a_P[0];
a_incr(a_L3);
if(!a_equal(a_L4,16777376)){ goto a_G10;}
if(!a_equal(to_LIST(a_1447)->offset[a_F1],16777424)){ goto a_G9;}
a_putchar(a_1106,48); goto a_G10;
a_G9:a_putchar(a_1106,49);
a_G10:if(a_equal(a_L4,16777388)){ return;}
a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0]; goto a_G3;
} /* pidginalttagtail */
static void a_1168(a_word a_F1){ /* pidginrepeatblock+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_incr(a_F1);
a_L2=to_LIST(a_1447)->offset[a_F1];
a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0];
a_1175(a_L2);
if(!a_less(a_L2,0)){ goto a_G7;}
a_subtr(0,a_L2,a_L3); goto a_G8;
a_G7:a_L3=a_L2;
a_G8:a_1309(a_1126,a_P);a_L4=a_P[0];
a_mult(a_L3,a_L4,a_L3);
a_G10:if(a_equal(a_L3,0)){ goto a_G15;}
a_putchar(a_1106,44);
a_1107(a_F1);
a_decr(a_L3);
a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0]; goto a_G10;
a_G15:if(a_more(a_L2,0)){ return;}
a_P[0]=2130705149;a_1105(a_1001,1,a_P); return;
} /* pidginrepeatblock */
static void a_1169(a_word a_F1,a_word a_F2){ /* pidginruleargs+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[1];
a_1318(a_1126,a_P);a_L3=a_P[0];
a_L4=0;a_L5=0;
a_G3:if(a_equal(a_L4,a_L3)){ return;}
a_1314(a_1126,a_L4,a_P);a_L6=a_P[0];
a_incr(a_L4);
if(!a_equal(a_L6,16777388)){ goto a_G9;}
a_P[0]=a_L5;a_1122(a_P);
a_1168(a_F1); return;
a_G9:if(!a_equal(a_L6,16777376)){ goto a_G12;}
if(!a_is(a_F2)){ goto a_G12;}
if(a_equal(to_LIST(a_1447)->offset[a_F1],16777424)){ goto a_G14;}
a_G12:a_P[0]=a_L5;a_1122(a_P);a_L5=a_P[0];
a_1107(a_F1);
a_G14:a_P[0]=a_F1;a_1162(a_P);a_F1=a_P[0]; goto a_G3;
} /* pidginruleargs */
static void a_1170(a_word a_F1){ /* pidginrulecall+>a */
a_word a_L2;a_word a_P[2];
a_P[0]=2130705144;a_P[1]=a_1126;a_1105(a_1001,2,a_P);
if(!a_1326(a_1126,8192)){ goto a_G5;}
a_L2=1;
a_1167(a_F1); goto a_G6;
a_G5:a_L2=0;
a_G6:a_putchar(a_1106,40);
a_1169(a_F1,a_L2);
a_putchar(a_1106,41); return;
} /* pidginrulecall */
static void a_1239(a_word a_F1){ /* pushEXPR+>a */

{register a_word *a_r1=a_extension(a_1216,1);a_r1[0]=a_F1;to_LIST(a_1216)->aupb+=1;}
  return;
} /* pushEXPR */
static void a_1231(a_word a_A[1]){ /* getitemdef+>a> */

if(!a_1326(a_A[0],8)){ return;}
a_A[0]=to_LIST(a_1288)->offset[a_A[0]]; return;
} /* getitemdef */
static void a_1223(a_word a_F1){ /* checklisttype+>a */

{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G3;}
}
if(!a_1326(a_F1,24)){ return;}
a_G3:a_1422(a_1001,2130706105); return;
} /* checklisttype */
static void a_1221(a_word a_F1){ /* checkcalibretype+>a */

{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G3;}
}
if(!a_1326(a_F1,8)){ return;}
a_G3:a_1422(a_1001,2130706099); return;
} /* checkcalibretype */
static void a_1222(a_word a_F1,a_word a_F2){ /* checkconstanttype+>a+>a */

{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(a_r1==16777335){ goto a_G2;}
 if(a_r1==16777304){ goto a_G3;}
 if(a_r1==16777309||a_r1==16777314){  goto a_G4;}
  goto a_G5;}
a_G2:if(a_equal(a_F2,1)){ goto a_G5;}
a_G3:if(!a_1326(a_F1,24)){ return;} goto a_G5;
a_G4:if(!a_equal(a_F2,0)){ goto a_G3;}
a_G5:a_1422(a_1001,2130706092); return;
} /* checkconstanttype */
static void a_1240(void){ /* readexpression */
a_word a_L1;a_word a_L2;a_word a_P[1];
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706064); return;
a_G5:a_1222(a_L1,1);
if(a_equal(to_LIST(a_1288)->offset[a_L1-1],0)){ goto a_G8;}
a_G7:a_1422(a_1001,2130706085); return;
a_G8:a_1239(a_L1);
a_L2=to_LIST(a_1216)->aupb;
a_1239(a_1232);
a_1232=a_L2;
to_LIST(a_1288)->offset[a_L1-1]=to_LIST(a_1216)->aupb;
a_G13:{ if(a_1461==16777439){ goto a_G14;}
 if(a_1461==16777459){ goto a_G16;}
 if(a_1461==16777471){ goto a_G19;}
 if(a_1461==16777269||a_1461==16777291){ goto a_G23;}
 if(a_1461==16777231){ goto a_G31;}
 if(a_1461==16777436||a_1461==16777421||a_1461==16777445||a_1461==16777418||a_1461==16777400||a_1461==16777430||a_1461==16777451||a_1461==16777415||a_1461==16777427||a_1461==16777406){  goto a_G39;}
  goto a_G7;}
a_G14:a_1468();
a_1239(16777439); return;
a_G16:a_1239(16777459);
a_1239(a_1462);
a_G18:a_1468(); goto a_G13;
a_G19:a_L1=a_1462;
a_P[0]=a_L1;a_1231(a_P);a_L1=a_P[0];
a_1239(a_L1);
a_1222(a_L1,0); goto a_G18;
a_G23:a_1239(a_1461);
a_1468();
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468();
a_P[0]=a_L1;a_1231(a_P);a_L1=a_P[0];
a_1239(a_L1);
a_1223(a_L1); goto a_G13;
a_G31:a_1239(a_1461);
a_1468();
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468();
a_P[0]=a_L1;a_1231(a_P);a_L1=a_P[0];
a_1239(a_L1);
a_1221(a_L1); goto a_G13;
a_G39:a_1239(a_1461); goto a_G18;
} /* readexpression */
static a_word a_1215(a_word a_F1){ /* E+>a */

if(!a_equal(to_LIST(a_1216)->offset[a_1225],a_F1)){ return 0;}
a_incr(a_1225); return 1;
} /* E */
static a_word a_1217(a_word a_A[1]){ /* Eitem+a> */

a_A[0]=to_LIST(a_1216)->offset[a_1225];
if(!a_was(a_1288,a_A[0])){ return 0;}
a_incr(a_1225); return 1;
} /* Eitem */
static a_word a_1218(a_word a_F1,a_word a_A[2]){ /* Eop+>a+a>+a> */

a_A[0]=to_LIST(a_1216)->offset[a_1225];
{ if(a_A[0]==16777451){ goto a_G3;}
 if(a_A[0]==16777400){ goto a_G6;}
 if(a_A[0]==16777430){ goto a_G8;}
 if(a_A[0]==16777436||a_A[0]==16777421){ goto a_G10;}
 if(a_A[0]==16777418||a_A[0]==16777445){  goto a_G12;}
  return 0;}
a_G3:if(!a_equal(a_F1,0)){ return 0;}
a_A[1]=1;
a_G5:a_incr(a_1225); return 1;
a_G6:if(!a_lseq(a_F1,1)){ return 0;}
a_A[1]=2; goto a_G5;
a_G8:if(!a_lseq(a_F1,2)){ return 0;}
a_A[1]=3; goto a_G5;
a_G10:if(!a_lseq(a_F1,3)){ return 0;}
a_A[1]=4; goto a_G5;
a_G12:if(!a_lseq(a_F1,4)){ return 0;}
a_A[1]=5; goto a_G5;
} /* Eop */
static void a_1238(a_word a_F1,a_word a_F2,a_word a_F3){ /* optor+>a+>a+>a */

 static const char *a_rulename="optor";
{ if(a_F1==16777451){ goto a_G2;}
 if(a_F1==16777400){ goto a_G3;}
 if(a_F1==16777430){ goto a_G4;}
 if(a_F1==16777436){ goto a_G5;}
 if(a_F1==16777421){ goto a_G6;}
 if(a_F1==16777445){ goto a_G7;}
 if(!(a_F1==16777418)){a_area_failed(a_rulename,a_F1);}
  goto a_G8;}
a_G2:a_1379(1,a_F2,a_F3); return;
a_G3:a_1379(2,a_F2,a_F3); return;
a_G4:a_1379(3,a_F2,a_F3); return;
a_G5:a_1379(6,a_F2,a_F3); return;
a_G6:a_1379(7,a_F2,a_F3); return;
a_G7:a_1379(8,a_F2,a_F3); return;
a_G8:a_1379(9,a_F2,a_F3); return;
} /* optor */
static a_word a_1233(a_word a_A[1]){ /* loosebase+a> */
a_word a_P[1];
if(!a_1215(16777427)){ goto a_G4;}
if(!a_1236(0,a_P)){ return 0;}a_A[0]=a_P[0];
if(!a_1215(16777406)){ return 0;} return 1;
a_G4:if(!a_1215(16777459)){ goto a_G7;}
a_1017(0,to_LIST(a_1216)->offset[a_1225],a_P);a_A[0]=a_P[0];
a_G6:a_incr(a_1225); return 1;
a_G7:if(!a_1215(16777415)){ goto a_G10;}
if(!a_1233(a_P)){ return 0;}a_A[0]=a_P[0];
a_1379(4,a_A[0],a_A[0]); return 1;
a_G10:if(!a_1215(16777421)){ goto a_G13;}
if(!a_1233(a_P)){ return 0;}a_A[0]=a_P[0];
a_1379(5,a_A[0],a_A[0]); return 1;
a_G13:if(!a_1215(16777231)){ goto a_G16;}
a_1310(to_LIST(a_1216)->offset[a_1225],a_P);a_A[0]=a_P[0];
a_1017(1,a_A[0],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G16:if(!a_1217(a_P)){ return 0;}a_A[0]=a_P[0];
a_P[0]=a_A[0];a_1231(a_P);a_A[0]=a_P[0];
if(!a_equal(to_LIST(a_1288)->offset[a_A[0]-5],16777304)){ return 0;}
a_1234(a_A[0]);
if(!a_1326(a_A[0],32)){ return 0;}
a_1017(0,to_LIST(a_1288)->offset[a_A[0]],a_P);a_A[0]=a_P[0]; return 1;
} /* loosebase */
static a_word a_1236(a_word a_F1,a_word a_A[1]){ /* looseexpr+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
if(!a_1233(a_P)){ return 0;}a_A[0]=a_P[0];
a_G2:if(!a_1218(a_F1,a_P)){ return 1;}a_L3=a_P[0];a_L4=a_P[1];
if(!a_1236(a_L4,a_P)){ goto a_G5;}a_L5=a_P[0];
a_1238(a_L3,a_L5,a_A[0]); goto a_G2;
a_G5:a_1369(a_A[0]); return 0;
} /* looseexpr */
static void a_1241(a_word a_F1,a_word a_F2){ /* setfinalvalue+>a+>a */

a_1298(a_F2,64);
to_LIST(a_1288)->offset[a_F2]=a_F1;
a_1358(a_F2,32); return;
} /* setfinalvalue */
static void a_1234(a_word a_F1){ /* looseeval+>a */
a_word a_L2;a_word a_L3;a_word a_P[3];
if(!a_1326(a_F1,8)){ goto a_G3;}
a_1427(a_1001,2130706079); return;
a_G3:if(a_1326(a_F1,32)){ return;}
if(!a_1326(a_F1,64)){ goto a_G8;}
a_P[0]=2047260145;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_P[2]=a_F1;a_1423(3,a_P);
a_1012(a_P);a_L3=a_P[0];
a_1241(a_L3,a_F1); return;
a_G8:a_1358(a_F1,64);
a_L2=a_1225;
a_1225=to_LIST(a_1288)->offset[a_F1-1];
a_incr(a_1225);
if(a_was(a_1216,a_1225)){ goto a_G14;}
a_1422(a_1001,2130706079); return;
a_G14:if(!a_1236(0,a_P)){ goto a_G17;}a_L3=a_P[0];
a_1024(a_L3,a_P);a_L3=a_P[0];
a_1241(a_L3,a_F1); goto a_G18;
a_G17:a_1298(a_F1,64);
a_G18:a_1225=a_L2; return;
} /* looseeval */
static void a_1235(void){ /* looseevaluation */
a_word a_L1;
if(a_1444()){ return;}
a_L1=a_1232;
a_G3:if(a_equal(a_L1,0)){ return;}
a_1234(to_LIST(a_1216)->offset[a_L1]);
a_incr(a_L1);
a_L1=to_LIST(a_1216)->offset[a_L1]; goto a_G3;
} /* looseevaluation */
static void a_1230(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* getexprlimit+>a+>a+a> */
a_word a_P[1];
a_P[0]=a_F2;a_1231(a_P);a_F2=a_P[0];
if(!a_equal(a_F1,16777269)){ goto a_G4;}
a_1320(a_F2,a_P);a_A[0]=a_P[0]; goto a_G5;
a_G4:a_1321(a_F2,a_P);a_A[0]=a_P[0];
a_G5:a_1017(0,a_A[0],a_P);a_A[0]=a_P[0]; return;
} /* getexprlimit */
static void a_1226(a_word a_A[1]){ /* finalbase+a> */
a_word a_P[1];
if(!a_1215(16777427)){ goto a_G4;}
a_1229(0,a_P);a_A[0]=a_P[0];
if(!a_1215(16777406)){ return;} return;
a_G4:if(!a_1215(16777459)){ goto a_G7;}
a_1017(0,to_LIST(a_1216)->offset[a_1225],a_P);a_A[0]=a_P[0];
a_G6:a_incr(a_1225); return;
a_G7:if(!a_1215(16777415)){ goto a_G10;}
a_1226(a_P);a_A[0]=a_P[0];
a_1379(4,a_A[0],a_A[0]); return;
a_G10:if(!a_1215(16777421)){ goto a_G13;}
a_1226(a_P);a_A[0]=a_P[0];
a_1379(5,a_A[0],a_A[0]); return;
a_G13:if(!a_1215(16777231)){ goto a_G16;}
a_1310(to_LIST(a_1216)->offset[a_1225],a_P);a_A[0]=a_P[0];
a_1017(1,a_A[0],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G16:if(!a_1215(16777269)){ goto a_G18;}
a_1230(16777269,to_LIST(a_1216)->offset[a_1225],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G18:if(!a_1215(16777291)){ goto a_G20;}
a_1230(16777291,to_LIST(a_1216)->offset[a_1225],a_P);a_A[0]=a_P[0]; goto a_G6;
a_G20:if(!a_1217(a_P)){ goto a_G24;}a_A[0]=a_P[0];
a_P[0]=a_A[0];a_1231(a_P);a_A[0]=a_P[0];
a_1227(a_A[0]);
a_1017(0,to_LIST(a_1288)->offset[a_A[0]],a_P);a_A[0]=a_P[0]; return;
a_G24:a_1422(a_1001,2130706074); return;
} /* finalbase */
static void a_1229(a_word a_F1,a_word a_A[1]){ /* finalexpr+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[2];
a_1226(a_P);a_A[0]=a_P[0];
a_G2:if(!a_1218(a_F1,a_P)){ return;}a_L3=a_P[0];a_L4=a_P[1];
a_1229(a_L4,a_P);a_L5=a_P[0];
a_1238(a_L3,a_L5,a_A[0]); goto a_G2;
} /* finalexpr */
static void a_1227(a_word a_F1){ /* finaleval+>a */
a_word a_L2;a_word a_L3;a_word a_P[3];
if(!a_1326(a_F1,8)){ goto a_G3;}
a_1427(a_1001,2130706069); return;
a_G3:if(a_1326(a_F1,32)){ return;}
if(!a_1326(a_F1,64)){ goto a_G8;}
a_P[0]=2047260145;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_P[2]=a_F1;a_1423(3,a_P);
a_1012(a_P);a_L2=a_P[0];
a_1241(a_L2,a_F1); return;
a_G8:a_1358(a_F1,64);
a_L3=a_1225;
a_1225=to_LIST(a_1288)->offset[a_F1-1];
a_incr(a_1225);
if(a_was(a_1216,a_1225)){ goto a_G14;}
a_1422(a_1001,2130706069); return;
a_G14:a_1229(0,a_P);a_L2=a_P[0];
a_1024(a_L2,a_P);a_L2=a_P[0];
a_1241(a_L2,a_F1);
a_1225=a_L3; return;
} /* finaleval */
static void a_1228(void){ /* finalevaluation */
a_word a_L1;
a_L1=a_1232;
a_G2:if(a_equal(a_L1,0)){ goto a_G6;}
a_1227(to_LIST(a_1216)->offset[a_L1]);
a_incr(a_L1);
a_L1=to_LIST(a_1216)->offset[a_L1]; goto a_G2;
a_G6:a_1232=0;
a_release(a_1216); return;
} /* finalevaluation */
static void a_1243(a_word a_F1,a_word a_A[1]){ /* storenumstring+>a+a> */
a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1447)->aupb;
a_previous(a_1451,a_F1);
a_unpackstring(a_1451,a_F1,a_1447);
a_1007(0,a_L3,a_P);a_A[0]=a_P[0];
a_unstackto(a_1447,a_L3); return;
} /* storenumstring */
static a_word a_1242(a_word a_F1,a_word a_F2){ /* splitvirtualspace+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[1];
if(!a_1373(a_F1)){ return 0;}
if(!a_1373(a_F2)){ return 0;}
a_1243(183666532,a_P);a_L3=a_P[0];
a_1243(183666539,a_P);a_L4=a_P[0];
a_1017(0,a_L3,a_P);a_1219=a_P[0];
a_1017(0,a_L4,a_P);a_1220=a_P[0];
a_1017(0,a_L3,a_P);a_L5=a_P[0];
a_1379(7,a_L5,a_1220);
a_1017(1,a_F1,a_P);a_L5=a_P[0];
a_1379(7,a_L5,a_1220);
a_1017(1,a_F2,a_P);a_L5=a_P[0];
a_1379(9,a_L5,a_1220);
if(!a_1377(12,a_1220)){ return 0;} return 1;
} /* splitvirtualspace */
static void a_1237(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[2]){ /* nextvirtualblock+>a+>a+>a+a>+a> */
a_word a_L6;a_word a_L7;a_word a_P[1];
a_1017(1,a_F1,a_P);a_L6=a_P[0];
a_1017(2,a_1219,a_P);a_L7=a_P[0];
a_1379(6,a_L7,a_L6);
a_1024(a_L6,a_P);a_A[0]=a_P[0];
a_1017(1,a_F2,a_P);a_L6=a_P[0];
a_1379(6,a_L6,a_1219);
a_1017(2,a_1220,a_P);a_L7=a_P[0];
a_1017(1,a_F3,a_P);a_L6=a_P[0];
a_1379(8,a_L7,a_L6);
a_1379(6,a_L6,a_1219);
a_1017(2,a_1219,a_P);a_L6=a_P[0];
a_1024(a_L6,a_P);a_A[1]=a_P[0];
a_1017(1,a_F1,a_P);a_L6=a_P[0];
a_1379(6,a_L6,a_1219); return;
} /* nextvirtualblock */
static void a_1224(void){ /* clearvirtualspace */

a_1369(a_1219);
a_1219=0;
a_1369(a_1220);
a_1220=0; return;
} /* clearvirtualspace */
static void a_1244(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* virtualaddressoffset+>a+>a+a> */
a_word a_L4;a_word a_L5;a_word a_P[1];
a_1017(1,a_F2,a_P);a_L5=a_P[0];
a_1017(0,a_F1,a_P);a_L4=a_P[0];
a_1379(6,a_L5,a_L4);
a_1024(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* virtualaddressoffset */
static void a_1264(a_word a_A[1]){ /* getitemdef+>a> */

if(!a_1326(a_A[0],8)){ return;}
a_A[0]=to_LIST(a_1288)->offset[a_A[0]]; return;
} /* getitemdef */
static void a_1281(void){ /* skipentry */

a_G1:if(!a_equal(16777439,a_1461)){ goto a_G3;}
a_1468(); return;
a_G3:if(!a_equal(16777486,a_1461)){ goto a_G6;}
a_1468();
a_1422(a_1001,2130706189); return;
a_G6:a_1468(); goto a_G1;
} /* skipentry */
static void a_1280(void){ /* skipdatasection */

a_G1:if(!a_equal(16777254,a_1461)){ goto a_G4;}
a_G2:a_1468();
a_1281(); goto a_G1;
a_G4:if(a_equal(16777236,a_1461)){ goto a_G2;}
if(a_equal(16777266,a_1461)){ goto a_G2;}
if(a_equal(16777250,a_1461)){ goto a_G2;}
if(a_equal(16777224,a_1461)){ goto a_G2;}
if(a_equal(16777258,a_1461)){ goto a_G2;}
if(a_equal(16777246,a_1461)){ goto a_G2;}
if(a_equal(a_1461,16777285)){ return;}
a_1422(a_1001,2130706184); return;
} /* skipdatasection */
static void a_1254(void){ /* datasectioni */

if(a_1444()){ return;}
a_G2:if(!a_equal(16777254,a_1461)){ goto a_G5;}
a_1468();
a_1282(); goto a_G2;
a_G5:if(!a_equal(16777236,a_1461)){ goto a_G8;}
a_1468();
a_1240(); goto a_G2;
a_G8:if(!a_equal(16777266,a_1461)){ goto a_G11;}
a_1468();
a_1266(); goto a_G2;
a_G11:if(!a_equal(16777250,a_1461)){ goto a_G14;}
a_1468();
a_1259(); goto a_G2;
a_G14:if(!a_equal(16777224,a_1461)){ goto a_G17;}
a_G15:a_1468();
a_1281(); goto a_G2;
a_G17:if(a_equal(16777258,a_1461)){ goto a_G15;}
if(a_equal(16777246,a_1461)){ goto a_G15;}
if(a_equal(a_1461,16777285)){ return;}
a_1422(a_1001,2130706178); return;
} /* datasectioni */
static void a_1251(a_word a_F1){ /* checklisttype+>a */

{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(!(a_r1==16777318||a_r1==16777322||a_r1==16777328)){ goto a_G3;}
}
if(!a_1326(a_F1,24)){ return;}
a_G3:a_1422(a_1001,2130706172); return;
} /* checklisttype */
static void a_1247(a_word a_F1,a_word a_F2){ /* checkconstanttype+>a+>a */

{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(a_r1==16777335){ goto a_G2;}
 if(a_r1==16777304){  goto a_G3;}
  goto a_G4;}
a_G2:if(a_equal(a_F2,1)){ goto a_G4;}
a_G3:if(!a_1326(a_F1,24)){ return;}
a_G4:a_1422(a_1001,2130706166); return;
} /* checkconstanttype */
static void a_1249(a_word a_F1){ /* checkfillconstanttype+>a */

{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(a_r1==16777335){ goto a_G2;}
 if(a_r1==16777304){  return;}
  goto a_G3;}
a_G2:if(!a_1326(a_F1,24)){ return;}
a_G3:a_1422(a_1001,2130706159); return;
} /* checkfillconstanttype */
static void a_1248(a_word a_F1){ /* checkfiletype+>a */

{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(!(a_r1==16777340||a_r1==16777345)){ goto a_G3;}
}
if(!a_1326(a_F1,24)){ return;}
a_G3:a_1422(a_1001,2130706151); return;
} /* checkfiletype */
static void a_1259(void){ /* fileentry */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706109); return;
a_G5:a_1248(a_L1);
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L2=a_1462;
a_1468();
if(a_equal(a_L2,1)){ goto a_G11;}
if(!a_equal(a_L2,3)){ goto a_G12;}
a_G11:a_1358(a_L1,32);
a_G12:if(a_equal(a_L2,2)){ goto a_G14;}
if(!a_equal(a_L2,3)){ goto a_G15;}
a_G14:a_1358(a_L1,64);
a_G15:a_1346(a_L1);
if(!a_equal(16777439,a_1461)){ goto a_G4;}

a_1468();
a_L3=0;
a_G20:a_incr(a_L3);
a_1311(a_L1,a_L3,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
a_P[0]=a_L2;a_1264(a_P);a_L2=a_P[0];
a_1251(a_L2); goto a_G20;
} /* fileentry */
static void a_1282(void){ /* skipfill */
a_word a_L1;a_word a_P[1];
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706109); return;
a_G5:a_P[0]=a_L1;a_1264(a_P);a_L1=a_P[0];
a_1251(a_L1);
if(!a_equal(16777455,a_1461)){ goto a_G4;}

a_1468();
a_1275(a_L1);
a_G11:if(!a_equal(16777439,a_1461)){ goto a_G13;}
a_1468(); return;
a_G13:a_1284();
a_1285(a_L1);
a_1283(a_L1); goto a_G11;
} /* skipfill */
static void a_1250(void){ /* checkfillitem */
a_word a_L1;
if(!a_equal(16777459,a_1461)){ goto a_G3;}
a_1468(); return;
a_G3:if(!a_equal(16777471,a_1461)){ goto a_G6;}
a_L1=a_1462;
a_1468(); goto a_G7;
a_G6:a_1422(a_1001,2130706109); return;
a_G7:a_1249(a_L1); return;
} /* checkfillitem */
static void a_1284(void){ /* skipfillitem */

if(!a_equal(16777427,a_1461)){ goto a_G6;}
a_1468();
a_G3:if(!a_equal(16777406,a_1461)){ goto a_G5;}
a_1468(); return;
a_G5:a_1250(); goto a_G3;
a_G6:a_1250(); return;
} /* skipfillitem */
static void a_1285(a_word a_F1){ /* skipfillrepeater+>a */
a_word a_L2;a_word a_L3;a_word a_P[4];
if(!a_equal(16777445,a_1461)){ return;}
a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G9;}
a_L3=a_1462;
a_1468();
if(!a_lseq(1,a_L3)){ goto a_G8;}
if(a_lseq(a_L3,1000)){ return;}
a_G8:a_P[0]=2047260161;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_P[2]=a_L3;a_P[3]=1000;a_1423(4,a_P); return;
a_G9:if(!a_equal(16777471,a_1461)){ goto a_G12;}
a_L2=a_1462;
a_1468(); goto a_G13;
a_G12:a_1422(a_1001,2130706109); return;
a_G13:a_1247(a_L2,1); return;
} /* skipfillrepeater */
static void a_1283(a_word a_F1){ /* skipfillinitializer+>a */
a_word a_L2;
a_G1:if(!a_equal(16777409,a_1461)){ return;}
a_1468();
if(!a_equal(16777471,a_1461)){ goto a_G6;}
a_L2=a_1462;
a_1468(); goto a_G7;
a_G6:a_1422(a_1001,2130706109); return;
a_G7:if(a_1326(a_L2,16)){ goto a_G10;}
if(a_noteq(to_LIST(a_1288)->offset[a_L2-5],16777335)){ goto a_G10;}
if(!a_is(to_LIST(a_1288)->offset[a_L2-1])){ goto a_G11;}
a_G10:a_1422(a_1001,2130706145); return;
a_G11:to_LIST(a_1288)->offset[a_L2-1]=a_F1; goto a_G1;
} /* skipfillinitializer */
static void a_1275(a_word a_F1){ /* rememberlist+>a */
a_word a_L2;a_word a_P[1];
a_1315(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return;}
a_1342(a_F1,a_1265);
a_1265=a_F1; return;
} /* rememberlist */
static void a_1266(void){ /* listentry */
a_word a_L1;a_word a_L2;a_word a_L3;
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706109); return;
a_G5:a_1251(a_L1);
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L2=a_1462;
a_1468();
{ if(a_L2==0||a_L2==1||a_L2==2){ goto a_G10;}
 if(a_L2==3||a_L2==4){  goto a_G13;}
  goto a_G17;}
a_G10:if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L3=a_1462;
a_1468(); goto a_G18;
a_G13:if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L3=a_1462;
a_1468();
a_1247(a_L3,1); goto a_G18;
a_G17:a_1422(a_1001,2130706138); return;
a_G18:a_1344(a_L1,a_L2);
a_1343(a_L1,a_L3);
a_1275(a_L1);
if(!a_equal(16777439,a_1461)){ goto a_G4;}

a_1468(); return;
} /* listentry */
static void a_1267(void){ /* loosebounds */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_L1=a_1265;
a_G2:if(a_equal(a_L1,-1)){ return;}
a_1321(a_L1,a_P);a_L2=a_P[0];
a_1320(a_L1,a_P);a_L3=a_P[0];
a_1343(a_L1,0);
{ if(a_L2==1){ goto a_G7;}
 if(a_L2==2){ goto a_G8;}
 if(a_L2==3){ goto a_G9;}
 if(a_L2==4){  goto a_G11;}
  goto a_G13;}
a_G7:a_1274(a_L3,a_L1); goto a_G14;
a_G8:a_1261(a_L3,a_L1); goto a_G14;
a_G9:a_1263(a_L3,a_L1,a_P);a_L4=a_P[0];
a_1274(a_L4,a_L1); goto a_G14;
a_G11:a_1263(a_L3,a_L1,a_P);a_L4=a_P[0];
a_1261(a_L4,a_L1); goto a_G14;
a_G13:a_1344(a_L1,0);
a_G14:a_1315(a_L1,a_P);a_L1=a_P[0]; goto a_G2;
} /* loosebounds */
static void a_1274(a_word a_F1,a_word a_F2){ /* relativesize+>a+>a */
a_word a_P[4];
if(a_less(a_F1,1)){ goto a_G3;}
if(!a_more(a_F1,100)){ goto a_G4;}
a_G3:a_P[0]=2047260176;a_P[1]=to_LIST(a_1288)->offset[a_F2-3];a_P[2]=a_F1;a_P[3]=a_F2;a_1443(4,a_P);
a_G4:a_min(100,a_F1);
a_max(1,a_F1);
a_subtr(0,a_F1,a_F1);
a_1344(a_F2,a_F1); return;
} /* relativesize */
static void a_1261(a_word a_F1,a_word a_F2){ /* fixsize+>a+>a */
a_word a_P[4];
if(a_less(a_F1,1)){ goto a_G3;}
if(!a_more(a_F1,100000)){ goto a_G4;}
a_G3:a_P[0]=2047260189;a_P[1]=to_LIST(a_1288)->offset[a_F2-3];a_P[2]=a_F1;a_P[3]=a_F2;a_1443(4,a_P);
a_G4:a_min(100000,a_F1);
a_max(1,a_F1);
a_1344(a_F2,a_F1); return;
} /* fixsize */
static a_word a_1262(a_word a_F1,a_word a_A[1]){ /* getconstvalue+>a+a> */
a_word a_P[1];
a_P[0]=a_F1;a_1264(a_P);a_F1=a_P[0];
if(!a_1326(a_F1,32)){ return 0;}
a_1014(to_LIST(a_1288)->offset[a_F1],a_P);a_A[0]=a_P[0]; return 1;
} /* getconstvalue */
static void a_1263(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* getestimator+>a+>a+a> */
a_word a_P[4];
if(a_1262(a_F1,a_P)){a_A[0]=a_P[0]; return;}
a_A[0]=1;
a_P[0]=2047260201;a_P[1]=to_LIST(a_1288)->offset[a_F2-3];a_P[2]=to_LIST(a_1288)->offset[a_F1-3];a_P[3]=a_F2;a_1423(4,a_P); return;
} /* getestimator */
static void a_1255(void){ /* datasectionii */

if(a_1444()){ return;}
a_G2:if(!a_equal(16777254,a_1461)){ goto a_G5;}
a_1468();
a_1268(); goto a_G2;
a_G5:if(!a_equal(16777236,a_1461)){ goto a_G8;}
a_G6:a_1468();
a_1281(); goto a_G2;
a_G8:if(a_equal(16777266,a_1461)){ goto a_G6;}
if(a_equal(16777250,a_1461)){ goto a_G6;}
if(!a_equal(16777224,a_1461)){ goto a_G13;}
a_1468();
a_1273(0); goto a_G2;
a_G13:if(!a_equal(16777258,a_1461)){ goto a_G16;}
a_1468();
a_1273(1); goto a_G2;
a_G16:if(!a_equal(16777246,a_1461)){ goto a_G19;}
a_1468();
a_1258(); goto a_G2;
a_G19:if(a_equal(a_1461,16777285)){ return;}
a_1427(a_1001,2130706133); return;
} /* datasectionii */
static void a_1258(void){ /* externalentry */
a_word a_L1;a_word a_L2;
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706109); return;
a_G5:if(!a_equal(16777483,a_1461)){ goto a_G4;}
a_L2=a_1462;
a_1468();
if(!a_equal(16777439,a_1461)){ goto a_G4;}

a_1468();
if(a_1326(a_L1,16)){ goto a_G13;}
a_G12:a_1422(a_1001,2130706127); return;
a_G13:if(a_1326(a_L1,8)){ goto a_G12;}
{register a_word a_r1=to_LIST(a_1288)->offset[a_L1-5];
 if(a_r1==16777349||a_r1==16777304||a_r1==16777309){ goto a_G15;}
 if(a_r1==16777340||a_r1==16777345){ goto a_G16;}
 if(a_r1==16777318||a_r1==16777322){  goto a_G17;}
  goto a_G12;}
a_G15:to_LIST(a_1288)->offset[a_L1]=a_L2; return;
a_G16:to_LIST(a_1288)->offset[a_L1-1]=a_L2; return;
a_G17:a_1343(a_L1,a_L2); return;
} /* externalentry */
static void a_1273(a_word a_F1){ /* readmatter+>a */
a_word a_L2;
if(!a_equal(16777483,a_1461)){ goto a_G4;}
a_L2=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706109); return;
a_G5:if(!a_equal(16777439,a_1461)){ goto a_G4;}

a_1468();
a_1291(a_F1,a_L2); return;
} /* readmatter */
static void a_1268(void){ /* loosefill */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706109); return;
a_G5:a_P[0]=a_L1;a_1264(a_P);a_L1=a_P[0];
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L2=a_1462;
a_1468();
a_G9:if(!a_equal(16777439,a_1461)){ goto a_G11;}
a_1468(); return;
a_G11:a_1269(a_P);a_L3=a_P[0];
a_add(a_L3,a_1260,a_1260);
a_1271(a_L1,a_L2,a_L3);
a_1270(a_L1); goto a_G9;
} /* loosefill */
static void a_1269(a_word a_A[1]){ /* loosefillitem+a> */

if(!a_equal(16777427,a_1461)){ goto a_G12;}
a_1468();
a_A[0]=0;
a_G4:if(!a_equal(16777406,a_1461)){ goto a_G6;}
a_1468(); return;
a_G6:if(!a_equal(16777459,a_1461)){ goto a_G9;}
a_G7:a_1468();
a_incr(a_A[0]); goto a_G4;
a_G9:if(!a_equal(16777471,a_1461)){ goto a_G11;}
 goto a_G7;
a_G11:a_1422(a_1001,2130706109); return;
a_G12:if(!a_equal(16777459,a_1461)){ goto a_G15;}
a_G13:a_1468();
a_A[0]=1; return;
a_G15:if(!a_equal(16777471,a_1461)){ goto a_G11;}
 goto a_G13;
} /* loosefillitem */
static void a_1276(a_word a_F1,a_word a_F2,a_word a_F3,a_word a_A[1]){ /* repeatervalue+>a+>a+>a+a> */
a_word a_P[6];
if(!a_1262(a_F3,a_P)){ goto a_G6;}a_A[0]=a_P[0];
if(!a_lseq(1,a_A[0])){ goto a_G4;}
if(a_lseq(a_A[0],1000)){ return;}
a_G4:a_P[0]=2047260234;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_P[2]=a_F2;a_P[3]=a_A[0];a_P[4]=to_LIST(a_1288)->offset[a_F3-3];a_P[5]=1000;a_1423(6,a_P);
a_A[0]=1; return;
a_G6:a_A[0]=1;
a_P[0]=2047260215;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_P[2]=a_F2;a_P[3]=to_LIST(a_1288)->offset[a_F3-3];a_1423(4,a_P); return;
} /* repeatervalue */
static void a_1271(a_word a_F1,a_word a_F2,a_word a_F3){ /* looserepeater+>a+>a+>a */
a_word a_L4;a_word a_L5;a_word a_P[1];
if(!a_equal(16777445,a_1461)){ goto a_G15;}
a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G6;}
a_L5=a_1462;
a_1468(); goto a_G12;
a_G6:if(!a_equal(16777471,a_1461)){ goto a_G9;}
a_L4=a_1462;
a_1468(); goto a_G10;
a_G9:a_1422(a_1001,2130706109); return;
a_G10:a_P[0]=a_L4;a_1264(a_P);a_L4=a_P[0];
a_1276(a_F1,a_F2,a_L4,a_P);a_L5=a_P[0];
a_G12:if(a_equal(a_L5,1)){ goto a_G14;}
a_add(2,a_1260,a_1260);
a_G14:a_mult(a_F3,a_L5,a_F3);
a_G15:a_1313(a_F1,a_P);a_L5=a_P[0];
a_add(a_F3,a_L5,a_L5);
a_1341(a_F1,a_L5); return;
} /* looserepeater */
static void a_1270(a_word a_F1){ /* looseinitializer+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_G1:if(!a_equal(16777409,a_1461)){ return;}
a_1468();
if(!a_equal(16777471,a_1461)){ goto a_G6;}
a_L2=a_1462;
a_1468(); goto a_G7;
a_G6:a_1422(a_1001,2130706109); return;
a_G7:a_1313(a_F1,a_P);a_L3=a_P[0];
to_LIST(a_1288)->offset[a_L2]=a_L3; goto a_G1;
} /* looseinitializer */
static void a_1256(void){ /* datasectioniii */

a_G1:if(!a_equal(16777254,a_1461)){ goto a_G4;}
a_1468();
a_1149(); goto a_G1;
a_G4:if(!a_equal(16777236,a_1461)){ goto a_G7;}
a_G5:a_1468();
a_1281(); goto a_G1;
a_G7:if(a_equal(16777266,a_1461)){ goto a_G5;}
if(a_equal(16777250,a_1461)){ goto a_G5;}
if(a_equal(16777224,a_1461)){ goto a_G5;}
if(a_equal(16777258,a_1461)){ goto a_G5;}
if(a_equal(16777246,a_1461)){ goto a_G5;}
if(a_equal(a_1461,16777285)){ return;}
a_1422(a_1001,2130706121); return;
} /* datasectioniii */
static void a_1252(a_word a_A[2]){ /* collectlistsizeclaims+a>+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_P[1];
a_A[0]=0;a_A[1]=0;
a_L3=a_1265;
a_G3:if(a_equal(a_L3,-1)){ return;}
a_1310(a_L3,a_P);a_L4=a_P[0];
a_add(a_L4,a_A[0],a_A[0]);
a_1313(a_L3,a_P);a_L4=a_P[0];
a_1321(a_L3,a_P);a_L5=a_P[0];
if(!a_mreq(a_L5,0)){ goto a_G11;}
a_max(a_L5,a_L4);
a_G10:a_add(a_L4,a_A[0],a_A[0]); goto a_G12;
a_G11:a_subtr(a_A[1],a_L5,a_A[1]); goto a_G10;
a_G12:a_1315(a_L3,a_P);a_L3=a_P[0]; goto a_G3;
} /* collectlistsizeclaims */
static void a_1277(void){ /* setlistbounds */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_P[2];
a_L1=a_1265;
a_G2:if(a_equal(a_L1,-1)){ return;}
a_1310(a_L1,a_P);a_L2=a_P[0];
a_1313(a_L1,a_P);a_L3=a_P[0];
a_1321(a_L1,a_P);a_L4=a_P[0];
if(!a_mreq(a_L4,0)){ goto a_G9;}
a_max(a_L4,a_L3);
a_L4=0; goto a_G10;
a_G9:a_subtr(0,a_L4,a_L4);
a_G10:a_1237(a_L2,a_L3,a_L4,a_P);a_L5=a_P[0];a_L6=a_P[1];
a_1343(a_L1,a_L5);
a_1344(a_L1,a_L6);
a_1315(a_L1,a_P);a_L1=a_P[0]; goto a_G2;
} /* setlistbounds */
static void a_1257(void){ /* distributevirtualaddress */
a_word a_L1;a_word a_L2;a_word a_P[2];
a_1252(a_P);a_L1=a_P[0];a_L2=a_P[1];
if(a_more(a_L2,0)){ goto a_G4;}
a_L2=1;
a_G4:if(!a_1242(a_L1,a_L2)){ goto a_G8;}
a_1277();
a_1224();
a_1253(); return;
a_G8:a_P[0]=2047260243;a_1423(1,a_P); return;
} /* distributevirtualaddress */
static void a_1253(void){ /* computepointerconstants */
a_word a_L1;
a_L1=to_LIST(a_1288)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1288)->aupb)){ return;}
if(!a_equal(to_LIST(a_1288)->offset[a_L1-5],16777335)){ goto a_G5;}
a_1278(a_L1);
a_G5:a_next(a_1288,a_L1); goto a_G2;
} /* computepointerconstants */
static void a_1278(a_word a_F1){ /* setpointervalue+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_L2=to_LIST(a_1288)->offset[a_F1-1];
a_P[0]=a_L2;a_1264(a_P);a_L2=a_P[0];
a_1310(a_L2,a_P);a_L3=a_P[0];
a_1320(a_L2,a_P);a_L4=a_P[0];
a_subtr(to_LIST(a_1288)->offset[a_F1],a_L3,a_L3);
a_1244(a_L4,a_L3,a_P);to_LIST(a_1288)->offset[a_F1]=a_P[0];
a_1358(a_F1,32); return;
} /* setpointervalue */
static void a_1279(a_word a_F1){ /* setreprnumber+>a */
a_word a_L2;a_word a_P[1];
if(!a_1326(a_F1,16)){ goto a_G12;}
{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(a_r1==16777309||a_r1==16777304){ return;}
 if(a_r1==16777349){ goto a_G3;}
 if(a_r1==16777340||a_r1==16777345||a_r1==16777318||a_r1==16777322){  goto a_G9;}
  goto a_G11;}
a_G3:a_1460(to_LIST(a_1288)->offset[a_F1],a_P);a_L2=a_P[0];
if(!a_stringelem(a_1451,a_L2,0,a_P)){ goto a_G7;}a_L2=a_P[0];
if(!a_equal(a_L2,95)){ goto a_G7;}
a_1358(a_F1,4096); return;
a_G7:if(!a_equal(a_L2,64)){ return;}
a_1358(a_F1,8192); return;
a_G9:a_incr(a_1272);
to_LIST(a_1288)->offset[a_F1]=a_1272; return;
a_G11:a_1427(a_1001,2130706115); return;
a_G12:{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-5];
 if(a_r1==16777304||a_r1==16777335){ return;}
 if(a_r1==16777309||a_r1==16777314){ goto a_G13;}
 if(a_r1==16777349||a_r1==16777318||a_r1==16777322||a_r1==16777328||a_r1==16777340||a_r1==16777345){  goto a_G9;}
  return;}
a_G13:to_LIST(a_1288)->offset[a_F1-1]=to_LIST(a_1288)->offset[a_F1]; goto a_G9;
} /* setreprnumber */
static void a_1246(void){ /* assignreprnumbers */
a_word a_L1;
a_L1=to_LIST(a_1288)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1288)->aupb)){ return;}
if(!a_1326(a_L1,8)){ goto a_G5;}
a_G4:a_next(a_1288,a_L1); goto a_G2;
a_G5:{register a_word a_r1=to_LIST(a_1288)->offset[a_L1-5];
 if(!(a_r1==16777304||a_r1==16777335||a_r1==16777309||a_r1==16777314||a_r1==16777349||a_r1==16777318||a_r1==16777322||a_r1==16777328||a_r1==16777340||a_r1==16777345)){ goto a_G4;}
}
a_1279(a_L1); goto a_G4;
} /* assignreprnumbers */
static void a_1303(void){ /* expandITEM */

{register a_word *a_r1=a_extension(a_1288,7);a_r1[0]=a_r1[1]=a_r1[2]=a_r1[3]=a_r1[4]=a_r1[5]=a_r1[6]=0;to_LIST(a_1288)->aupb+=7;}
  return;
} /* expandITEM */
static a_word a_1326(a_word a_F1,a_word a_F2){ /* isitemflag+>a+>a */
a_word a_L3;
a_booland(to_LIST(a_1288)->offset[a_F1-6],a_F2,a_L3);
if(!a_is(a_L3)){ return 0;} return 1;
} /* isitemflag */
static void a_1358(a_word a_F1,a_word a_F2){ /* setitemflag+>a+>a */

a_boolor(to_LIST(a_1288)->offset[a_F1-6],a_F2,to_LIST(a_1288)->offset[a_F1-6]); return;
} /* setitemflag */
static void a_1298(a_word a_F1,a_word a_F2){ /* clearitemflag+>a+>a */
a_word a_L3;
a_boolinvert(a_F2,a_L3);
a_booland(a_L3,to_LIST(a_1288)->offset[a_F1-6],to_LIST(a_1288)->offset[a_F1-6]); return;
} /* clearitemflag */
static void a_1300(a_word a_A[1]){ /* converttoitem+>a> */

a_addmult(a_A[0],7,a_1337,a_A[0]); return;
} /* converttoitem */
static void a_1340(a_word a_F1){ /* pushAUX+>a */

{register a_word *a_r1=a_extension(a_1287,1);a_r1[0]=a_F1;to_LIST(a_1287)->aupb+=1;}
  return;
} /* pushAUX */
static void a_1310(a_word a_F1,a_word a_A[1]){ /* getcalibre+>a+a> */

a_A[0]=to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]-2]; return;
} /* getcalibre */
static void a_1319(a_word a_F1,a_word a_A[1]){ /* getssel+>a+a> */

a_A[0]=to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]-1]; return;
} /* getssel */
static void a_1321(a_word a_F1,a_word a_A[1]){ /* getvupb+>a+a> */

a_A[0]=to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]-4]; return;
} /* getvupb */
static void a_1320(a_word a_F1,a_word a_A[1]){ /* getvlwb+>a+a> */

a_A[0]=to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]-5]; return;
} /* getvlwb */
static void a_1313(a_word a_F1,a_word a_A[1]){ /* getfill+>a+a> */

a_A[0]=to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]-3]; return;
} /* getfill */
static void a_1315(a_word a_F1,a_word a_A[1]){ /* getlistlink+>a+a> */

a_A[0]=to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]]; return;
} /* getlistlink */
static void a_1343(a_word a_F1,a_word a_F2){ /* putvlwb+>a+>a */

to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]-5]=a_F2; return;
} /* putvlwb */
static void a_1344(a_word a_F1,a_word a_F2){ /* putvupb+>a+>a */

to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]-4]=a_F2; return;
} /* putvupb */
static void a_1341(a_word a_F1,a_word a_F2){ /* putfill+>a+>a */

to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]-3]=a_F2; return;
} /* putfill */
static void a_1342(a_word a_F1,a_word a_F2){ /* putlistlink+>a+>a */

to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]]=a_F2; return;
} /* putlistlink */
static void a_1318(a_word a_F1,a_word a_A[1]){ /* getnumberofformals+>a+a> */

a_A[0]=to_LIST(a_1287)->offset[to_LIST(a_1288)->offset[a_F1-1]-2]; return;
} /* getnumberofformals */
static void a_1314(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* getformal+>a+>a+a> */
a_word a_L4;
a_L4=to_LIST(a_1288)->offset[a_F1-1];
if(!a_mreq(a_F2,to_LIST(a_1287)->offset[a_L4-2])){ goto a_G4;}
a_A[0]=0; return;
a_G4:a_incr(a_L4);
a_add(a_F2,a_L4,a_L4);
a_A[0]=to_LIST(a_1287)->offset[a_L4]; return;
} /* getformal */
static void a_1309(a_word a_F1,a_word a_A[1]){ /* getanchorcount+>a+a> */
a_word a_L3;a_word a_L4;
a_A[0]=0;
a_L3=to_LIST(a_1288)->offset[a_F1-1];
a_L4=to_LIST(a_1287)->offset[a_L3-2];
a_G4:if(a_equal(a_L4,0)){ return;}
a_decr(a_L4);
a_incr(a_L3);
if(!a_equal(to_LIST(a_1287)->offset[a_L3],16777388)){ goto a_G4;}
a_A[0]=a_L4; return;
} /* getanchorcount */
static void a_1291(a_word a_F1,a_word a_F2){ /* addmatter+>a+>a */

{register a_word *a_r1=a_extension(a_1287,3);a_r1[0]=a_F1;a_r1[1]=a_F2;a_r1[2]=a_1335;to_LIST(a_1287)->aupb+=3;}
a_1335=to_LIST(a_1287)->aupb; return;
} /* addmatter */
static a_word a_1316(a_word a_F2,a_word a_A[2]){ /* getmatter+>a>+>a+a> */

if(!a_equal(a_A[0],0)){ goto a_G3;}
a_A[0]=a_1335; goto a_G4;
a_G3:a_A[0]=to_LIST(a_1287)->offset[a_A[0]];
a_G4:if(!a_was(a_1287,a_A[0])){ return 0;}
if(!a_equal(to_LIST(a_1287)->offset[a_A[0]-2],a_F2)){ goto a_G3;}
a_A[1]=to_LIST(a_1287)->offset[a_A[0]-1]; return 1;
} /* getmatter */
static a_word a_1299(a_word a_F1,a_word a_F2){ /* compareformals+>a+>a */
a_word a_L3;
if(!a_equal(to_LIST(a_1287)->offset[a_F1-2],to_LIST(a_1287)->offset[a_F2-2])){ return 0;}
a_L3=to_LIST(a_1287)->offset[a_F1-1];
if(!a_equal(to_LIST(a_1287)->offset[a_F2-1],a_L3)){ return 0;}
a_G4:if(a_equal(a_L3,0)){ return 1;}
a_incr(a_F1);
a_incr(a_F2);
if(!a_equal(to_LIST(a_1287)->offset[a_F1],to_LIST(a_1287)->offset[a_F2])){ return 0;}
a_decr(a_L3); goto a_G4;
} /* compareformals */
static void a_1357(a_word a_F1,a_word a_A[1]){ /* searchformals+>a+>a> */
a_word a_L3;
a_L3=a_1331;
a_G2:if(!a_equal(a_L3,0)){ goto a_G5;}
to_LIST(a_1287)->offset[a_A[0]]=a_1331;
a_1331=a_A[0]; return;
a_G5:if(!a_1299(a_L3,a_A[0])){ goto a_G8;}
a_unstackto(a_1287,a_F1);
a_A[0]=a_L3; return;
a_G8:a_L3=to_LIST(a_1287)->offset[a_L3]; goto a_G2;
} /* searchformals */
static void a_1308(a_word a_F1,a_word a_F2){ /* formalaffixes+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;
a_G1:if(a_equal(a_F2,0)){ return;}
a_decr(a_F2);
if(!a_equal(16777463,a_1461)){ goto a_G6;}
a_L5=a_1462;
a_1468(); goto a_G7;
a_G6:a_1422(a_1001,2130706193); return;
a_G7:a_1340(a_L5);
{ if(a_L5==16777355||a_L5==16777361){ goto a_G9;}
 if(a_L5==16777371||a_L5==16777376||a_L5==16777382||a_L5==16777366||a_L5==16777388||a_L5==16777394){  goto a_G1;}
  goto a_G20;}
a_G9:if(!a_equal(16777455,a_1461)){ goto a_G6;}
a_L3=a_1462;
a_1468();
if(!a_equal(16777455,a_1461)){ goto a_G6;}
a_L4=a_1462;
a_1468();
a_1308(a_F1,a_F2);
a_incr(to_LIST(a_1287)->offset[a_F1-1]);
a_1340(a_L3);
a_incr(to_LIST(a_1287)->offset[a_F1-1]);
a_1340(a_L4); return;
a_G20:a_1422(a_1001,2130706226); return;
} /* formalaffixes */
static void a_1362(a_word a_A[1]){ /* storeformalaffixes+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L2=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706193); return;
a_G5:a_L3=to_LIST(a_1287)->aupb;
{register a_word *a_r1=a_extension(a_1287,3);a_r1[0]=a_r1[1]=a_L2;a_r1[2]=0;to_LIST(a_1287)->aupb+=3;}
a_A[0]=to_LIST(a_1287)->aupb;
a_1308(a_A[0],a_L2);
a_P[0]=a_A[0];a_1357(a_L3,a_P);a_A[0]=a_P[0]; return;
} /* storeformalaffixes */
static void a_1363(a_word a_A[1]){ /* storelistbounds+a> */
a_word a_L2;a_word a_L3;
if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L2=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706193); return;
a_G5:if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L3=a_1462;
a_1468();
{register a_word *a_r1=a_extension(a_1287,6);a_r1[0]=a_r1[1]=a_r1[2]=0;a_r1[3]=a_L2;a_r1[4]=a_L3;a_r1[5]=0;to_LIST(a_1287)->aupb+=6;}
a_A[0]=to_LIST(a_1287)->aupb; return;
} /* storelistbounds */
static void a_1295(a_word a_F1){ /* checkitemID+>a */

if(a_equal(a_F1,to_LIST(a_1288)->aupb)){ return;}
a_1422(a_1001,2130706220); return;
} /* checkitemID */
static void a_1302(void){ /* enteritem */
a_word a_L1;a_word a_P[1];
if(!a_1326(to_LIST(a_1288)->aupb,4)){ return;}
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb]=a_1337;
{register a_word *a_r1=a_extension(a_1287,3);a_r1[0]=to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-4];a_r1[1]=to_LIST(a_1288)->aupb;a_r1[2]=0;to_LIST(a_1287)->aupb+=3;}
a_1459(to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-3],a_P);a_L1=a_P[0];
a_G5:if(!a_equal(a_L1,0)){ goto a_G7;}
a_1469(to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-3],to_LIST(a_1287)->aupb); return;
a_G7:if(!a_equal(to_LIST(a_1287)->offset[a_L1],0)){ goto a_G9;}
to_LIST(a_1287)->offset[a_L1]=to_LIST(a_1287)->aupb; return;
a_G9:a_L1=to_LIST(a_1287)->offset[a_L1]; goto a_G5;
} /* enteritem */
static void a_1347(void){ /* readitem */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_P[1];
a_1303();
if(!a_equal(16777463,a_1461)){ goto a_G5;}
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-5]=a_1462;
a_1468(); goto a_G6;
a_G5:a_1422(a_1001,2130706193); return;
a_G6:if(!a_equal(16777471,a_1461)){ goto a_G5;}
a_L1=a_1462;
a_1468();
a_1295(a_L1);
if(!a_equal(16777455,a_1461)){ goto a_G5;}
a_L2=a_1462;
a_1468();
a_booland(a_L2,117557020,to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-6]);
if(!a_equal(16777455,a_1461)){ goto a_G5;}
a_L3=a_1462;
a_1468();
if(a_lseq(a_L3,0)){ goto a_G21;}
if(!a_more(a_L3,a_1336)){ goto a_G20;}
a_G19:a_1422(a_1001,2130706215); return;
a_G20:to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-2]=a_L3;
a_G21:{register a_word a_r1=to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-5];
 if(a_r1==16777349){ goto a_G22;}
 if(a_r1==16777322||a_r1==16777318||a_r1==16777328){ goto a_G23;}
 if(a_r1==16777304||a_r1==16777309||a_r1==16777314||a_r1==16777335||a_r1==16777340||a_r1==16777345){  goto a_G24;}
  goto a_G19;}
a_G22:a_1362(a_P);to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-1]=a_P[0]; goto a_G24;
a_G23:a_1363(a_P);to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-1]=a_P[0];
a_G24:if(!a_equal(16777483,a_1461)){ goto a_G5;}
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-4]=a_1462;
a_1468();
if(!a_equal(16777483,a_1461)){ goto a_G5;}
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-3]=a_1462;
a_1468();
a_1302(); return;
} /* readitem */
static void a_1329(void){ /* itemsection */

if(a_1444()){ return;}
a_G2:if(!a_equal(16777439,a_1461)){ goto a_G4;}
a_1468(); return;
a_G4:a_1347(); goto a_G2;
} /* itemsection */
static void a_1360(void){ /* skipitemsection */

a_G1:if(!a_equal(16777439,a_1461)){ goto a_G3;}
a_G2:a_1468(); return;
a_G3:if(a_equal(16777486,a_1461)){ goto a_G2;}
a_1468(); goto a_G1;
} /* skipitemsection */
static void a_1293(void){ /* addstdstring */

a_1322(0);
a_1303();
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-5]=16777318;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-6]=4;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-4]=183666554;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-3]=183666463;
{register a_word *a_r1=a_extension(a_1287,6);a_r1[0]=a_r1[1]=a_r1[2]=0;a_r1[3]=a_r1[4]=1;a_r1[5]=0;to_LIST(a_1287)->aupb+=6;}
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-1]=to_LIST(a_1287)->aupb;
a_1302(); return;
} /* addstdstring */
static void a_1292(void){ /* addshiftaffixrules */
a_word a_P[3];
a_1322(0);
a_1303();
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-6]=33284;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-5]=16777349;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-4]=183666554;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-3]=183666471;
a_P[1]=16777394;a_1290(1,a_P,1,a_P+1);to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-1]=a_P[0];
a_1302();
a_1303();
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-6]=32772;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-5]=16777349;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-4]=183666554;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-3]=183666479;
a_P[1]=16777376;a_P[2]=16777394;a_1290(2,a_P,2,a_P+1);to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-1]=a_P[0];
a_1302(); return;
} /* addshiftaffixrules */
static void a_1290(a_word a_F2,a_word a_A[1],a_word a_C,a_word *a_V){ /* addformalaffixes+a>+>a+@+>a */
a_word a_L4;a_word a_P[1];
a_L4=to_LIST(a_1287)->aupb;
{register a_word *a_r1=a_extension(a_1287,3);a_r1[0]=a_F2;a_r1[1]=a_r1[2]=0;to_LIST(a_1287)->aupb+=3;}
a_A[0]=to_LIST(a_1287)->aupb;
if(a_equal(a_F2,0)){ goto a_G8;}
a_G5:a_1340(a_V[0]);
a_incr(to_LIST(a_1287)->offset[a_A[0]-1]);
if(a_C>1){a_C--;a_V+=1; goto a_G5;} 
a_G8:a_P[0]=a_A[0];a_1357(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* addformalaffixes */
static void a_1289(void){ /* addbuiltinformals */
a_word a_P[5];
a_P[1]=16777361;a_P[2]=16777371;a_P[3]=1;a_P[4]=1;a_1290(2,a_P,4,a_P+1);a_1365=a_P[0];
a_P[1]=16777371;a_P[2]=16777388;a_P[3]=16777376;a_1290(3,a_P,3,a_P+1);a_1334=a_P[0];
a_P[1]=0;a_1290(0,a_P,1,a_P+1);a_1350=a_P[0]; return;
} /* addbuiltinformals */
static a_word a_1328(a_word a_F1){ /* iswaitforitem+>a */

if(!a_equal(to_LIST(a_1288)->offset[a_F1],183666486)){ return 0;}
if(!a_equal(to_LIST(a_1288)->offset[a_F1-5],16777349)){ return 0;}
if(!a_equal(to_LIST(a_1288)->offset[a_F1-1],a_1365)){ return 0;} return 1;
} /* iswaitforitem */
static a_word a_1324(a_word a_F1){ /* isassignitem+>a */

if(!a_equal(to_LIST(a_1288)->offset[a_F1],183666492)){ return 0;}
if(!a_1326(a_F1,16)){ return 0;}
if(!a_equal(to_LIST(a_1288)->offset[a_F1-5],16777349)){ return 0;}
if(!a_equal(to_LIST(a_1288)->offset[a_F1-1],a_1334)){ return 0;} return 1;
} /* isassignitem */
static a_word a_1327(a_word a_F1){ /* isrootitem+>a */

if(!a_equal(to_LIST(a_1288)->offset[a_F1-3],183666498)){ return 0;}
if(!a_equal(to_LIST(a_1288)->offset[a_F1-5],16777349)){ return 0;}
if(!a_equal(to_LIST(a_1288)->offset[a_F1-1],a_1350)){ return 0;}
if(!a_1326(a_F1,16)){ return 1;} return 0;
} /* isrootitem */
static a_word a_1325(a_word a_F1,a_word a_A[1]){ /* isbuiltinrule+>a+a> */

{register a_word a_r1=to_LIST(a_1288)->offset[a_F1-3];
 if(a_r1==183666471){ goto a_G2;}
 if(a_r1==183666479){  goto a_G3;}
  return 0;}
a_G2:a_A[0]=1; return 1;
a_G3:a_A[0]=2; return 1;
} /* isbuiltinrule */
static a_word a_1338(a_word a_F1){ /* nocallstackrule+>a */
a_word a_P[1];
if(a_1328(a_F1)){ return 0;}
if(a_1326(a_F1,1024)){ return 0;}
if(!a_1326(a_F1,16)){ goto a_G5;}
if(!a_noteq(to_LIST(a_1288)->offset[a_F1-3],183666505)){ return 0;} return 1;
a_G5:if(!a_1325(a_F1,a_P)){ return 0;} return 1;
} /* nocallstackrule */
static void a_1346(a_word a_F1){ /* readfileinfo+>a */
a_word a_L2;a_word a_L3;a_word a_L4;
if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L3=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706193); return;
a_G5:if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L4=a_1462;
a_1468();
{register a_word *a_r1=a_extension(a_1287,3);a_r1[0]=0;a_r1[1]=a_L3;a_r1[2]=a_L4;to_LIST(a_1287)->aupb+=3;}
{register a_word a_r1=to_LIST(a_1287)->aupb;a_L2=a_r1;to_LIST(a_1288)->offset[a_F1-1]=a_r1;}
if(!a_equal(16777448,a_1461)){ return;}
a_1468();
a_G12:if(!a_equal(16777403,a_1461)){ goto a_G14;}
a_1468(); return;
a_G14:if(!a_equal(16777471,a_1461)){ goto a_G4;}
a_L3=a_1462;
a_1468();
a_1340(a_L3);
a_incr(to_LIST(a_1287)->offset[a_L2-2]); goto a_G12;
} /* readfileinfo */
static void a_1312(a_word a_F1,a_word a_A[2]){ /* getfiledata+>a+a>+a> */
a_word a_L4;
a_L4=to_LIST(a_1288)->offset[a_F1-1];
a_A[0]=to_LIST(a_1287)->offset[a_L4-1];
a_A[1]=to_LIST(a_1287)->offset[a_L4]; return;
} /* getfiledata */
static void a_1311(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* getfilearea+>a+>a+a> */
a_word a_L4;
a_L4=to_LIST(a_1288)->offset[a_F1-1];
if(!a_more(a_F2,to_LIST(a_1287)->offset[a_L4-2])){ goto a_G4;}
a_A[0]=0; return;
a_G4:a_add(a_L4,a_F2,a_L4);
a_A[0]=to_LIST(a_1287)->offset[a_L4]; return;
} /* getfilearea */
static void a_1296(void){ /* checkmainmodule */
a_word a_P[2];
if(!a_is(a_1333)){ goto a_G3;}
a_P[0]=2047260253;a_P[1]=to_LIST(a_1288)->offset[a_1333-5];a_1423(2,a_P); return;
a_G3:a_1333=to_LIST(a_1288)->aupb; return;
} /* checkmainmodule */
static void a_1345(void){ /* readdefinitionlist */
a_word a_L1;a_word a_L2;a_word a_L3;
a_G1:if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L1=a_1462;
a_1468(); goto a_G5;
a_G4:a_1422(a_1001,2130706193); return;
a_G5:if(!a_equal(16777455,a_1461)){ goto a_G4;}
a_L2=a_1462;
a_1468();
if(!a_mreq(a_L2,a_1336)){ goto a_G10;}
a_1336=a_L2; goto a_G11;
a_G10:a_1422(a_1001,2130706210); return;
a_G11:if(!a_equal(16777483,a_1461)){ goto a_G4;}
a_L3=a_1462;
a_1468();
{register a_word *a_r1=a_extension(a_1287,3);a_r1[0]=a_L1;a_r1[1]=a_L2;a_r1[2]=a_L3;to_LIST(a_1287)->aupb+=3;}
if(!a_equal(to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-1],0)){ goto a_G17;}
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-1]=to_LIST(a_1287)->aupb;
a_G17:if(!a_equal(16777439,a_1461)){ goto a_G1;}
a_1468(); return;
} /* readdefinitionlist */
static void a_1332(void){ /* linkmoduleheader */

if(!a_equal(a_1337,0)){ goto a_G3;}
a_1307=to_LIST(a_1288)->aupb; goto a_G4;
a_G3:to_LIST(a_1288)->offset[a_1337]=to_LIST(a_1288)->aupb;
a_G4:a_1337=to_LIST(a_1288)->aupb; return;
} /* linkmoduleheader */
static void a_1322(a_word a_F1){ /* headsection+>a */
a_word a_L2;a_word a_P[1];
if(!a_equal(a_F1,0)){ goto a_G5;}
a_1303();
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-6]=3;
a_1332(); return;
a_G5:a_1303();
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-5]=a_F1;
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-6]=1;
if(!a_equal(16777277,a_1461)){ goto a_G18;}
a_1468();
a_1358(to_LIST(a_1288)->aupb,2);
if(!a_equal(16777483,a_1461)){ goto a_G14;}
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-3]=a_1462;
a_1468(); goto a_G15;
a_G14:a_1422(a_1001,2130706193); return;
a_G15:if(!a_equal(16777483,a_1461)){ goto a_G14;}
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-4]=a_1462;
a_1468(); goto a_G26;
a_G18:if(!a_equal(16777273,a_1461)){ goto a_G25;}
a_1468();
a_1358(to_LIST(a_1288)->aupb,4);
if(!a_equal(16777483,a_1461)){ goto a_G14;}
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-4]=a_1462;
a_1468();
a_1296(); goto a_G26;
a_G25:a_1422(a_1001,2130706203); return;
a_G26:a_1332();
if(!a_equal(16777455,a_1461)){ goto a_G14;}
a_L2=a_1462;
a_1468();
if(a_equal(a_L2,32)){ goto a_G32;}
a_P[0]=2047260265;a_1423(1,a_P);
a_G32:a_1336=0;
a_1345();
to_LIST(a_1288)->offset[to_LIST(a_1288)->aupb-2]=a_1336; return;
} /* headsection */
static void a_1359(void){ /* skipheadsection */

a_G1:if(!a_equal(16777439,a_1461)){ goto a_G3;}
a_1468(); return;
a_G3:a_1468(); goto a_G1;
} /* skipheadsection */
static void a_1356(a_word a_F1,a_word a_F2,a_word a_A[2]){ /* searchforline+>a+>a+a>+a> */

if(a_lseq(a_F2,1)){ goto a_G4;}
if(a_more(a_F2,to_LIST(a_1288)->offset[a_F1-2])){ goto a_G4;}
if(!a_equal(to_LIST(a_1288)->offset[a_F1-1],0)){ goto a_G6;}
a_G4:a_A[0]=0;
a_A[1]=183666554; return;
a_G6:a_F1=to_LIST(a_1288)->offset[a_F1-1];
a_G7:if(!a_lseq(a_F2,to_LIST(a_1287)->offset[a_F1-1])){ goto a_G11;}
a_subtr(a_F2,to_LIST(a_1287)->offset[a_F1-2],a_A[0]);
a_incr(a_A[0]);
a_A[1]=to_LIST(a_1287)->offset[a_F1]; return;
a_G11:a_add(a_F1,3,a_F1); goto a_G7;
} /* searchforline */
static void a_1306(a_word a_F1,a_word a_A[2]){ /* findlineno+>a+a>+a> */
a_word a_P[2];
if(!a_equal(a_1337,0)){ goto a_G4;}
a_A[0]=a_F1;
a_A[1]=183666554; return;
a_G4:a_1356(a_1337,a_F1,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1]; return;
} /* findlineno */
static void a_1305(a_word a_F1,a_word a_A[3]){ /* finditemlineno+>a+a>+a>+a> */
a_word a_L5;a_word a_L6;a_word a_P[2];
a_L5=a_1307;
a_G2:a_L6=to_LIST(a_1288)->offset[a_L5];
if(!a_is(a_L6)){ goto a_G6;}
if(!a_less(a_L6,a_F1)){ goto a_G6;}
a_L5=a_L6; goto a_G2;
a_G6:a_A[2]=to_LIST(a_1288)->offset[a_L5-3];
a_1356(a_L5,to_LIST(a_1288)->offset[a_F1-2],a_P);a_A[0]=a_P[0];a_A[1]=a_P[1]; return;
} /* finditemlineno */
static a_word a_1361(a_word a_F1,a_word a_F2){ /* stacksizemismatch+>a+>a */
a_word a_L3;a_word a_L4;a_word a_P[1];
a_1319(a_F1,a_P);a_L3=a_P[0];
a_1319(a_F2,a_P);a_L4=a_P[0];
if(a_noteq(a_L3,a_L4)){ return 1;}
a_1310(a_F1,a_P);a_L3=a_P[0];
a_1310(a_F2,a_P);a_L4=a_P[0];
if(!a_noteq(a_L3,a_L4)){ return 0;} return 1;
} /* stacksizemismatch */
static a_word a_1364(a_word a_F1,a_word a_F2){ /* unequaltypes+>a+>a */

if(a_equal(a_F1,a_F2)){ return 0;}
if(!a_equal(a_F1,16777335)){ return 1;}
if(!a_equal(a_F2,16777304)){ return 1;} return 0;
} /* unequaltypes */
static a_word a_1323(a_word a_F1,a_word a_F2){ /* incompatibletypes+>a+>a */
a_word a_L3;
a_L3=to_LIST(a_1288)->offset[a_F1-5];
if(a_1364(a_L3,to_LIST(a_1288)->offset[a_F2-5])){ return 1;}
if(!a_equal(a_L3,16777349)){ goto a_G5;}
if(!a_noteq(to_LIST(a_1288)->offset[a_F1-1],to_LIST(a_1288)->offset[a_F2-1])){ return 0;} return 1;
a_G5:if(a_equal(a_L3,16777322)){ goto a_G8;}
if(a_equal(a_L3,16777318)){ goto a_G8;}
if(!a_equal(a_L3,16777328)){ return 0;}
a_G8:if(!a_1361(a_F1,a_F2)){ return 0;} return 1;
} /* incompatibletypes */
static void a_1304(a_word a_F1,a_word a_A[1]){ /* finditemdef+>a+a> */
a_word a_L3;a_word a_L4;a_word a_P[1];
a_L3=to_LIST(a_1288)->offset[a_F1-4];
a_1459(to_LIST(a_1288)->offset[a_F1-3],a_P);a_L4=a_P[0];
a_G3:if(!a_equal(a_L4,0)){ goto a_G5;}
a_A[0]=0; return;
a_G5:if(!a_noteq(to_LIST(a_1287)->offset[a_L4-2],a_L3)){ goto a_G7;}
a_G6:a_L4=to_LIST(a_1287)->offset[a_L4]; goto a_G3;
a_G7:a_A[0]=to_LIST(a_1287)->offset[a_L4-1];
if(!a_1326(a_A[0],4)){ goto a_G6;}
to_LIST(a_1288)->offset[a_F1]=a_A[0]; return;
} /* finditemdef */
static void a_1353(a_word a_F1){ /* scanitem+>a */
a_word a_L2;a_word a_P[4];
if(!a_1326(a_F1,8)){ return;}
a_1304(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ goto a_G5;}
a_P[0]=2047260279;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_P[2]=a_F1;a_1423(3,a_P); return;
a_G5:if(!a_1323(a_L2,a_F1)){ goto a_G7;}
a_P[0]=2047260290;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_P[2]=a_L2;a_P[3]=a_F1;a_1423(4,a_P); return;
a_G7:if(!a_was(a_1288,to_LIST(a_1288)->offset[a_L2])){ goto a_G10;}
a_1358(a_L2,128);
a_1358(to_LIST(a_1288)->offset[a_L2],4); return;
a_G10:a_1427(a_1001,2130706198); return;
} /* scanitem */
static void a_1351(a_word a_A[1]){ /* scanfordefinitions+>a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_G1:a_1294(a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ return;}
if(!a_1326(a_1337,4)){ goto a_G1;}
if(a_1326(a_1337,8)){ goto a_G1;}
a_1358(a_1337,8);
a_A[0]=1;
a_L2=a_1337;
a_G8:a_next(a_1288,a_L2);
if(a_1326(a_L2,1)){ goto a_G1;}
a_1353(a_L2); goto a_G8;
} /* scanfordefinitions */
static void a_1354(a_word a_F1){ /* scanitemfordbledef+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[4];
a_L2=to_LIST(a_1288)->offset[a_F1-4];
a_1459(to_LIST(a_1288)->offset[a_F1-3],a_P);a_L3=a_P[0];
a_G3:if(a_equal(a_L3,0)){ return;}
if(!a_noteq(to_LIST(a_1287)->offset[a_L3-2],a_L2)){ goto a_G6;}
a_G5:a_L3=to_LIST(a_1287)->offset[a_L3]; goto a_G3;
a_G6:a_L4=to_LIST(a_1287)->offset[a_L3-1];
if(a_equal(a_L4,to_LIST(a_1288)->offset[a_F1])){ goto a_G5;}
if(!a_1326(a_L4,4)){ goto a_G5;}
if(!a_1326(to_LIST(a_1288)->offset[a_L4],4)){ goto a_G5;}
a_P[0]=2047260300;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_P[2]=to_LIST(a_1288)->offset[a_F1];a_P[3]=a_L4;a_1423(4,a_P); return;
} /* scanitemfordbledef */
static void a_1352(void){ /* scanfordoubledefinitions */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_G1:a_1294(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(!a_1326(a_1337,4)){ goto a_G1;}
a_L1=a_1337;
a_G5:a_next(a_1288,a_L1);
if(a_1326(a_L1,1)){ goto a_G1;}
if(!a_1326(a_L1,8)){ goto a_G5;}
a_1354(a_L1); goto a_G5;
} /* scanfordoubledefinitions */
static void a_1297(void){ /* cleanupitems */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_G1:a_1294(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(a_1326(a_1337,4)){ goto a_G1;}
a_L1=a_1337;
a_G5:a_next(a_1288,a_L1);
if(a_1326(a_L1,1)){ goto a_G1;}
to_LIST(a_1288)->offset[a_L1-5]=0; goto a_G5;
} /* cleanupitems */
static void a_1355(void){ /* scanlinkedmodules */
a_word a_L1;a_word a_P[1];
if(!a_equal(a_1333,0)){ goto a_G3;}
a_P[0]=2047260271;a_1423(1,a_P); return;
a_G3:a_1322(0);
a_1330=a_1337;
a_G5:a_L1=0;
a_P[0]=a_L1;a_1351(a_P);a_L1=a_P[0];
if(a_is(a_L1)){ goto a_G5;}
if(a_1444()){ goto a_G10;}
a_1352();
a_G10:if(a_1444()){ return;}
a_1297(); return;
} /* scanlinkedmodules */
static void a_1348(a_word a_F1){ /* reportitem+>a */
a_word a_P[3];
if(a_1326(a_F1,128)){ return;}
if(a_1325(a_F1,a_P)){ return;}
if(!a_1326(a_F1,4)){ return;}
a_P[0]=2047260308;a_P[1]=to_LIST(a_1288)->offset[a_F1-3];a_P[2]=a_F1;a_1443(3,a_P); return;
} /* reportitem */
static void a_1349(void){ /* reportnotusedpublicitems */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_G1:if(!a_equal(a_1301,0)){ goto a_G3;}
a_incr(a_1301); return;
a_G3:a_1294(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(!a_1326(a_1337,4)){ goto a_G1;}
a_1412(to_LIST(a_1288)->offset[a_1337-5]);
if(!a_1404()){ goto a_G1;}
a_L1=a_1337;
a_G9:a_next(a_1288,a_L1);
if(a_1326(a_L1,1)){ goto a_G1;}
a_1348(a_L1); goto a_G9;
} /* reportnotusedpublicitems */
static void a_1294(a_word a_A[1]){ /* advancemodbase+a> */

if(!a_equal(a_1337,a_1330)){ goto a_G3;}
a_1337=a_1307; goto a_G4;
a_G3:a_1337=to_LIST(a_1288)->offset[a_1337];
a_G4:if(!a_equal(a_1337,a_1330)){ goto a_G6;}
a_A[0]=0; return;
a_G6:a_1336=to_LIST(a_1288)->offset[a_1337-2];
a_A[0]=1; return;
} /* advancemodbase */
static void a_1339(a_word a_A[1]){ /* opennextmodule+a> */
a_word a_L2;a_word a_P[1];
a_G1:a_1294(a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
if(!a_1326(a_1337,4)){ goto a_G1;}
a_L2=to_LIST(a_1288)->offset[a_1337-5];
a_1409(a_L2);
if(!a_equal(a_L2,0)){ goto a_G8;}
a_A[0]=2; return;
a_G8:a_A[0]=1; return;
} /* opennextmodule */
static void a_1317(a_word a_A[1]){ /* getnextmodulehead+a> */
a_word a_P[1];
a_G1:a_1294(a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
if(!a_1326(a_1337,4)){ goto a_G1;}
a_A[0]=a_1337; return;
} /* getnextmodulehead */
static void a_1286(void){ /* @root */

a_1293();
a_1292();
a_1289(); return;
} /* @root */
static void a_1372(a_word a_A[1]){ /* getregister+a> */
a_word a_L2;
{register a_word *a_r1=a_extension(a_1367,1);a_r1[0]=0;to_LIST(a_1367)->aupb+=1;}
a_A[0]=to_LIST(a_1367)->aupb;
a_L2=a_1380;
a_G4:if(a_equal(a_L2,1)){ return;}
{register a_word *a_r1=a_extension(a_1367,1);a_r1[0]=0;to_LIST(a_1367)->aupb+=1;}
a_decr(a_L2); goto a_G4;
} /* getregister */
static void a_1369(a_word a_F1){ /* freeregister+>a */
a_word a_L2;
a_add(a_F1,a_1380,a_L2);
a_decr(a_L2);
if(a_noteq(a_L2,to_LIST(a_1367)->aupb)){ return;}
a_G4:if(!a_equal(a_F1,to_LIST(a_1367)->aupb)){ goto a_G6;}
a_unstack(a_1367); return;
a_G6:a_unstack(a_1367); goto a_G4;
} /* freeregister */
static void a_1374(a_word a_A[1]){ /* markregisters+a> */

a_A[0]=to_LIST(a_1367)->aupb; return;
} /* markregisters */
static void a_1370(a_word a_F1){ /* freeregistersfrommark+>a */

a_unstackto(a_1367,a_F1); return;
} /* freeregistersfrommark */
static void a_1368(a_word a_F1,a_word a_A[1]){ /* duplregister+>a+a> */
a_word a_L3;a_word a_L4;a_word a_P[1];
a_1372(a_P);a_A[0]=a_P[0];
a_L3=a_A[0];
a_L4=a_1380;
a_G4:if(!a_lseq(a_L4,1)){ goto a_G6;}
to_LIST(a_1367)->offset[a_L3]=to_LIST(a_1367)->offset[a_F1]; return;
a_G6:to_LIST(a_1367)->offset[a_L3]=to_LIST(a_1367)->offset[a_F1];
a_decr(a_L4);
a_incr(a_F1);
a_incr(a_L3); goto a_G4;
} /* duplregister */
static void a_1376(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* readregister+t[]+>a+a> */
a_word a_L3;a_word a_L4;a_word a_P[1];
a_1372(a_P);a_A[0]=a_P[0];
a_L3=a_A[0];
a_L4=a_1380;
a_subtr(a_F2,a_1380,a_F2);
a_incr(a_F2);
a_G6:if(!a_lseq(a_L4,1)){ goto a_G8;}
to_LIST(a_1367)->offset[a_L3]=to_LIST(a_F1)->offset[a_F2]; return;
a_G8:to_LIST(a_1367)->offset[a_L3]=to_LIST(a_F1)->offset[a_F2];
a_decr(a_L4);
a_incr(a_F2);
a_incr(a_L3); goto a_G6;
} /* readregister */
static void a_1381(a_word a_F1,a_word a_F2){ /* writeregister+>a+[]st[] */
a_word a_L2;a_word a_L3;
a_L2=a_1380;
a_L3=a_F1;
a_G3:if(a_less(a_L2,1)){ goto a_G7;}
{register a_word *a_r1=a_extension(a_F2,1);a_r1[0]=to_LIST(a_1367)->offset[a_L3];to_LIST(a_F2)->aupb+=1;}
a_decr(a_L2);
a_incr(a_L3); goto a_G3;
a_G7:a_1369(a_F1); return;
} /* writeregister */
static a_word a_1373(a_word a_F1){ /* istargetconst+>a */

if(!a_equal(a_F1,a_F1)){ return 0;} return 1;
} /* istargetconst */
static void a_1375(a_word a_F1,a_word a_A[1]){ /* putcstregister+>a+a> */
a_word a_P[1];
a_1372(a_P);a_A[0]=a_P[0];
to_LIST(a_1367)->offset[a_A[0]]=a_F1; return;
} /* putcstregister */
static void a_1371(a_word a_F1,a_word a_A[1]){ /* getcstregister+>a+a> */

a_A[0]=to_LIST(a_1367)->offset[a_F1];
a_1369(a_F1); return;
} /* getcstregister */
static void a_1379(a_word a_F1,a_word a_F2,a_word a_F3){ /* regoperator+>a+>a+>a */

{ if(a_F1==1){ goto a_G2;}
 if(a_F1==2){ goto a_G4;}
 if(a_F1==3){ goto a_G5;}
 if(a_F1==6){ goto a_G6;}
 if(a_F1==7){ goto a_G7;}
 if(a_F1==8){ goto a_G8;}
 if(a_F1==9){ goto a_G9;}
 if(a_F1==4){ goto a_G10;}
 if(a_F1==5){  goto a_G11;}
  return;}
a_G2:a_boolxor(to_LIST(a_1367)->offset[a_F3],to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3]);
a_G3:a_1369(a_F2); return;
a_G4:a_booland(to_LIST(a_1367)->offset[a_F3],to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3]); goto a_G3;
a_G5:a_boolor(to_LIST(a_1367)->offset[a_F3],to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3]); goto a_G3;
a_G6:a_add(to_LIST(a_1367)->offset[a_F3],to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3]); goto a_G3;
a_G7:a_subtr(to_LIST(a_1367)->offset[a_F3],to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3]); goto a_G3;
a_G8:a_mult(to_LIST(a_1367)->offset[a_F3],to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3]); goto a_G3;
a_G9:a_div(to_LIST(a_1367)->offset[a_F3],to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3]); goto a_G3;
a_G10:a_boolinvert(to_LIST(a_1367)->offset[a_F3],to_LIST(a_1367)->offset[a_F3]); return;
a_G11:a_subtr(0,to_LIST(a_1367)->offset[a_F3],to_LIST(a_1367)->offset[a_F3]); return;
} /* regoperator */
static a_word a_1377(a_word a_F1,a_word a_F2){ /* regcompare+>a+>a */

 static const char *a_rulename="regcompare";
{ if(a_F1==10){ goto a_G2;}
 if(a_F1==11){ goto a_G3;}
 if(!(a_F1==12)){a_area_failed(a_rulename,a_F1);}
  goto a_G4;}
a_G2:if(!a_equal(to_LIST(a_1367)->offset[a_F2],0)){ return 0;} return 1;
a_G3:if(!a_less(to_LIST(a_1367)->offset[a_F2],0)){ return 0;} return 1;
a_G4:if(!a_more(to_LIST(a_1367)->offset[a_F2],0)){ return 0;} return 1;
} /* regcompare */
static a_word a_1378(a_word a_F1,a_word a_F2,a_word a_F3){ /* regcompare2+>a+>a+>a */
a_word a_L4;
 static const char *a_rulename="regcompare2";
{ if(a_F1==20){ goto a_G2;}
 if(a_F1==21){ goto a_G5;}
 if(a_F1==22){ goto a_G6;}
 if(!(a_F1==23)){a_area_failed(a_rulename,a_F1);}
  goto a_G7;}
a_G2:a_L4=to_LIST(a_1367)->offset[a_F2];
a_incr(a_L4);
if(!a_equal(a_L4,to_LIST(a_1367)->offset[a_F3])){ return 0;} return 1;
a_G5:if(!a_less(to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3])){ return 0;} return 1;
a_G6:if(!a_lseq(to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3])){ return 0;} return 1;
a_G7:if(!a_equal(to_LIST(a_1367)->offset[a_F2],to_LIST(a_1367)->offset[a_F3])){ return 0;} return 1;
} /* regcompare2 */
static void a_1366(void){ /* @root */
a_word a_L1;
a_1380=1;
a_L1=32;
a_G3:if(a_mreq(a_L1,32)){ goto a_G6;}
a_add(a_L1,32,a_L1);
a_incr(a_1380); goto a_G3;
a_G6: a_waitfor(a_1001,2130706235); if(!a_equal(32,32)){ goto a_G9;}
if(a_equal(32,32)){ return;}
a_G9:a_1427(a_1001,2130706231); return;
} /* @root */
static a_word a_1399(a_word a_F1,a_word a_F2){ /* isfileflag+>a+>a */
a_word a_L3;
a_booland(to_LIST(a_1384)->offset[a_F1-2],a_F2,a_L3);
if(!a_is(a_L3)){ return 0;} return 1;
} /* isfileflag */
static void a_1411(a_word a_F1,a_word a_F2){ /* setfileflag+>a+>a */

a_boolor(to_LIST(a_1384)->offset[a_F1-2],a_F2,to_LIST(a_1384)->offset[a_F1-2]); return;
} /* setfileflag */
static void a_1392(a_word a_F1){ /* extendBUFFER+>a */

{register a_word *a_r1=a_extension(a_1447,1);a_r1[0]=a_F1;to_LIST(a_1447)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1393(a_word a_F1){ /* extendFILES+>a */
a_word a_P[2];
a_incr(a_1394);
if(!a_less(a_1394,200)){ goto a_G4;}
{register a_word *a_r1=a_extension(a_1384,3);a_r1[0]=a_r1[1]=0;a_r1[2]=a_F1;to_LIST(a_1384)->aupb+=3;}
  return;
a_G4:a_P[0]=2047260533;a_P[1]=200;a_1425(2,a_P); return;
} /* extendFILES */
static a_word a_1400(a_word a_F1,a_word a_F2){ /* isfirstarg+t[]+>a */
a_word a_L2;a_word a_P[1];
a_comparestring(a_1493,a_1390,a_F1,a_F2,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return 0;} return 1;
} /* isfirstarg */
static void a_1391(void){ /* checkcommandlinearguments */
a_word a_P[3];
a_1390=to_LIST(a_1493)->aupb;
a_1389=1;
a_G3:if(!a_less(a_1390,to_LIST(a_1493)->alwb)){ goto a_G5;}
a_P[0]=2047260512;a_1423(1,a_P); return;
a_G5:if(!a_1400(a_1001,2130706277)){ goto a_G7;}
a_P[0]=2047260429;a_1428(1,a_P); return;
a_G7:if(!a_1400(a_1001,2130706273)){ goto a_G9;}
a_P[0]=2047260496;a_P[1]=2;a_P[2]=1;a_1428(3,a_P); return;
a_G9:if(!a_1400(a_1001,2130706268)){ goto a_G12;}
a_1389=0;
a_G11:a_previousstring(a_1493,a_1390); goto a_G3;
a_G12:if(!a_1400(a_1001,2130706263)){ goto a_G17;}
a_previousstring(a_1493,a_1390);
if(!a_less(a_1390,to_LIST(a_1493)->alwb)){ goto a_G16;}
a_P[0]=2047260521;a_P[1]=111;a_1423(2,a_P); return;
a_G16:a_1414=a_1390; goto a_G11;
a_G17:if(!a_1400(a_1001,2130706260)){ goto a_G22;}
a_previousstring(a_1493,a_1390);
if(!a_less(a_1390,to_LIST(a_1493)->alwb)){ goto a_G21;}
a_P[0]=2047260521;a_P[1]=76;a_1423(2,a_P); return;
a_G21:a_1401=a_1390; goto a_G11;
a_G22:if(!a_1400(a_1001,2130706257)){ goto a_G24;}
a_1349(); goto a_G11;
a_G24:if(!a_1400(a_1001,2130706254)){ return;}
a_1211(); goto a_G11;
} /* checkcommandlinearguments */
static a_word a_1396(a_word a_A[1]){ /* getnextsource+a> */
a_word a_L2;a_word a_P[1];
if(!a_equal(a_1385,0)){ goto a_G3;}
a_1385=to_LIST(a_1384)->alwb; goto a_G4;
a_G3:a_next(a_1384,a_1385);
a_G4:a_A[0]=a_1385;
a_G5:if(!a_lseq(a_A[0],to_LIST(a_1384)->aupb)){ goto a_G8;}
a_G6:a_1398(a_A[0],a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return 1;} goto a_G5;
a_G8:if(!a_lseq(to_LIST(a_1493)->alwb,a_1390)){ goto a_G11;}
a_1393(a_1390);
a_previousstring(a_1493,a_1390); goto a_G6;
a_G11:if(!a_is(a_1389)){ return 0;}
a_1393(183666525);
a_1402=to_LIST(a_1384)->aupb;
a_1389=0; goto a_G6;
} /* getnextsource */
static a_word a_1404(void){ /* notstdlibsource */

if(a_equal(a_1402,0)){ return 1;}
if(a_equal(a_1385,0)){ return 1;}
if(!a_less(a_1385,a_1402)){ return 0;} return 1;
} /* notstdlibsource */
static void a_1395(a_word a_A[1]){ /* geticefile+a> */
a_word a_P[1];
if(a_1418(a_1385,a_P)){a_A[0]=a_P[0]; return;}
a_A[0]=0; return;
} /* geticefile */
static a_word a_1418(a_word a_F1,a_word a_A[1]){ /* wasicesource+>a+a> */

if(!a_was(a_1384,a_F1)){ return 0;}
a_A[0]=to_LIST(a_1384)->offset[a_F1]; return 1;
} /* wasicesource */
static void a_1387(void){ /* addextension */

a_1392(46);
a_1392(105);
a_1392(99);
a_1392(101); return;
} /* addextension */
static void a_1386(void){ /* adddirseparator */

if(a_equal(to_LIST(a_1447)->offset[to_LIST(a_1447)->aupb],47)){ return;}
a_1392(47); return;
} /* adddirseparator */
static void a_1406(a_word a_A[1]){ /* openBUFFER+a> */
a_word a_L2;a_word a_P[1];
a_listlength(a_1447,a_L2);
if(!a_lseq(a_L2,0)){ goto a_G4;}
a_A[0]=1; return;
a_G4:a_packstring(a_1447,a_L2,a_1451);
a_scratch(a_1447);
a_1455();
a_1480(a_P);a_A[0]=a_P[0]; return;
} /* openBUFFER */
static void a_1413(a_word a_F1){ /* stringtoBUFFER+>a */
a_word a_P[1];
if(!a_was(a_1451,a_F1)){ goto a_G4;}
a_1460(a_F1,a_P);a_F1=a_P[0];
a_unpackstring(a_1451,a_F1,a_1447); return;
a_G4:if(!a_was(a_1493,a_F1)){ goto a_G6;}
a_unpackstring(a_1493,a_F1,a_1447); return;
a_G6:a_1427(a_1001,2130706251); return;
} /* stringtoBUFFER */
static a_word a_1405(a_word a_F1,a_word a_A[1]){ /* nthpath+>a+a> */
a_word a_L3;
a_A[0]=to_LIST(a_1447)->alwb;
a_L3=to_LIST(a_1384)->offset[a_F1-1];
if(!a_lseq(a_A[0],to_LIST(a_1447)->aupb)){ return 0;}
a_G4:if(a_lseq(a_L3,1)){ return 1;}
if(!a_lseq(a_A[0],to_LIST(a_1447)->aupb)){ return 0;}
if(!a_equal(to_LIST(a_1447)->offset[a_A[0]],58)){ goto a_G8;}
a_decr(a_L3);
a_G8:a_incr(a_A[0]); goto a_G4;
} /* nthpath */
static a_word a_1410(a_word a_F1){ /* selectpath+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
if(!a_1405(a_F1,a_P)){ return 0;}a_L2=a_P[0];
if(!a_equal(to_LIST(a_1447)->offset[a_L2],58)){ goto a_G4;}
a_scratch(a_1447); return 1;
a_G4:a_L3=to_LIST(a_1447)->alwb;
a_G5:to_LIST(a_1447)->offset[a_L3]=to_LIST(a_1447)->offset[a_L2];
a_incr(a_L2);
if(a_more(a_L2,to_LIST(a_1447)->aupb)){ goto a_G10;}
if(a_equal(to_LIST(a_1447)->offset[a_L2],58)){ goto a_G10;}
a_incr(a_L3); goto a_G5;
a_G10:a_unstackto(a_1447,a_L3);
a_1386(); return 1;
} /* selectpath */
static void a_1408(a_word a_F1,a_word a_A[1]){ /* openfilefirst+>a+a> */
a_word a_P[1];
a_scratch(a_1447);
if(!a_1399(a_F1,2)){ goto a_G4;}
a_1417(a_F1,a_1401,a_P);a_A[0]=a_P[0]; return;
a_G4:if(!a_1399(a_F1,4)){ goto a_G6;}
a_1417(a_F1,183666519,a_P);a_A[0]=a_P[0]; return;
a_G6:a_1416(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* openfilefirst */
static void a_1417(a_word a_F1,a_word a_F2,a_word a_A[1]){ /* tryopenwithpath+>a+>a+a> */
a_word a_P[1];
to_LIST(a_1384)->offset[a_F1-1]=1;
a_G2:a_1413(a_F2);
if(!a_1410(a_F1)){ goto a_G7;}
a_1416(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_incr(to_LIST(a_1384)->offset[a_F1-1]); goto a_G2;
a_G7:a_A[0]=1; return;
} /* tryopenwithpath */
static void a_1416(a_word a_F1,a_word a_A[1]){ /* tryopen+>a+a> */
a_word a_P[2];
a_1413(to_LIST(a_1384)->offset[a_F1]);
if(!a_1399(a_F1,1)){ goto a_G4;}
a_1387();
a_G4:a_1406(a_P);a_A[0]=a_P[0];
if(!a_equal(a_A[0],0)){ goto a_G7;}
a_1411(a_F1,8); return;
a_G7:if(a_more(a_A[0],0)){ return;}
a_P[0]=2047260542;a_P[1]=a_F1;a_1425(2,a_P); return;
} /* tryopen */
static void a_1407(a_word a_F1){ /* openfileaslast+>a */
a_word a_L2;a_word a_P[2];
if(a_1399(a_F1,8)){ goto a_G3;}
a_1427(a_1001,2130706245); return;
a_G3:a_scratch(a_1447);
if(!a_1399(a_F1,2)){ goto a_G7;}
a_1413(a_1401);
if(a_1410(a_F1)){}
a_G7:if(!a_1399(a_F1,4)){ goto a_G10;}
a_1413(183666519);
if(a_1410(a_F1)){}
a_G10:a_1413(to_LIST(a_1384)->offset[a_F1]);
if(!a_1399(a_F1,1)){ goto a_G13;}
a_1387();
a_G13:a_1406(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
a_P[0]=2047260542;a_P[1]=a_F1;a_1425(2,a_P); return;
} /* openfileaslast */
static void a_1412(a_word a_F1){ /* setsource+>a */

a_1385=a_F1; return;
} /* setsource */
static void a_1409(a_word a_F1){ /* opensource+>a */

if(!a_equal(a_F1,0)){ goto a_G3;}
a_1385=0; return;
a_G3:a_1385=a_F1;
a_1407(a_F1); return;
} /* opensource */
static void a_1415(a_word a_F1,a_word a_A[1]){ /* tryfilefirst+>a+a> */
a_word a_P[1];
to_LIST(a_1384)->offset[a_F1-2]=0;
a_1408(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1411(a_F1,1);
a_1408(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
if(!a_is(a_1401)){ goto a_G14;}
to_LIST(a_1384)->offset[a_F1-2]=2;
a_1408(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1411(a_F1,1);
a_1408(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_G14:to_LIST(a_1384)->offset[a_F1-2]=4;
a_1408(a_F1,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1411(a_F1,1);
a_1408(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* tryfilefirst */
static void a_1398(a_word a_F1,a_word a_A[1]){ /* handlesourcefile+>a+a> */
a_word a_P[2];
if(!a_1399(a_F1,8)){ goto a_G4;}
a_1407(a_F1);
a_A[0]=0; return;
a_G4:a_1415(a_F1,a_P);a_A[0]=a_P[0];
if(!a_is(a_A[0])){ goto a_G7;}
a_P[0]=2047260542;a_P[1]=a_F1;a_1425(2,a_P); return;
a_G7:if(!a_equal(a_1461,16777273)){ goto a_G9;}
a_1403=a_F1; return;
a_G9:if(!a_equal(a_1461,16777262)){ return;}
a_1388(a_F1);
a_A[0]=1; return;
} /* handlesourcefile */
static void a_1388(a_word a_F1){ /* addincludedicefiles+>a */
a_word a_L2;a_word a_P[2];
if(!a_noteq(a_F1,to_LIST(a_1384)->aupb)){ goto a_G3;}
a_P[0]=2047260553;a_P[1]=a_F1;a_1425(2,a_P); return;
a_G3:a_unstack(a_1384);
a_G4:if(!a_equal(16777262,a_1461)){ goto a_G11;}
a_1468();
if(!a_equal(16777483,a_1461)){ goto a_G9;}
a_L2=a_1462;
a_1468(); goto a_G10;
a_G9:a_1422(a_1001,2130706239); return;
a_G10:a_1393(a_L2); goto a_G4;
a_G11:a_1455(); return;
} /* addincludedicefiles */
static void a_1397(void){ /* gettargetfile */
a_word a_L1;a_word a_L2;a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;
if(!a_is(a_1414)){ goto a_G4;}
a_L5=0;
a_L2=a_1414; goto a_G6;
a_G4:a_L5=1;
a_L2=to_LIST(a_1384)->offset[a_1403];
a_G6:a_L1=to_LIST(a_1447)->aupb;
a_1413(a_L2);
a_L4=to_LIST(a_1447)->aupb;
a_L6=1;
a_G10:if(a_lseq(a_L4,a_L1)){ goto a_G21;}
{register a_word a_r1=to_LIST(a_1447)->offset[a_L4];
 if(a_r1==46){ goto a_G12;}
 if(a_r1==47||a_r1==92||a_r1==58){  goto a_G19;}
  goto a_G20;}
a_G12:if(!a_equal(a_L5,0)){ goto a_G15;}
a_L5=2;
a_G14:a_L4=a_L1; goto a_G21;
a_G15:a_decr(a_L4);
if(!a_is(a_L6)){ goto a_G10;}
a_L6=0;
a_unstackto(a_1447,a_L4); goto a_G10;
a_G19:if(a_equal(a_L5,1)){ goto a_G21;} goto a_G14;
a_G20:a_decr(a_L4); goto a_G10;
a_G21:if(a_equal(a_L5,2)){ goto a_G24;}
a_1392(46);
a_1392(99);
a_G24:a_subtr(to_LIST(a_1447)->aupb,a_L4,a_L3);
a_packstring(a_1447,a_L3,a_1451);
a_unstackto(a_1447,a_L1); return;
} /* gettargetfile */
static void a_1433(a_word a_F1){ /* printchar+>a */

a_incr(a_1441);
a_putchar(a_1421,a_F1); return;
} /* printchar */
static void a_1430(void){ /* nlcr */

if(!a_lseq(a_1441,1)){ goto a_G3;}
a_1441=1; return;
a_G3:a_1441=0;
a_1433(10); return;
} /* nlcr */
static void a_1442(a_word a_F1){ /* tabline+>a */

a_G1:if(a_equal(a_1441,a_F1)){ return;}
if(!a_more(a_1441,a_F1)){ goto a_G4;}
a_1430(); goto a_G1;
a_G4:a_1433(32); goto a_G1;
} /* tabline */
static void a_1436(a_word a_F1){ /* printint+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G5;}
a_1433(45);
a_subtr(-1,a_F1,a_F1);
a_1437(a_F1,49); return;
a_G5:if(!a_less(a_F1,0)){ goto a_G8;}
a_1433(45);
a_getabs(a_F1,a_F1);
a_G8:a_1437(a_F1,48); return;
} /* printint */
static void a_1437(a_word a_F1,a_word a_F2){ /* printint1+>a+>a */
a_word a_L3;a_word a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1437(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_1433(a_L4); return;
} /* printint1 */
static void a_1434(a_word a_F1){ /* printform+>a */

a_1435(a_F1,4); return;
} /* printform */
static void a_1435(a_word a_F1,a_word a_F2){ /* printform1+>a+>a */
a_word a_L3;a_word a_L4;
if(a_equal(a_F2,0)){ return;}
a_decr(a_F2);
a_divrem11(a_F1,10,a_L3,a_L4);
a_1435(a_L3,a_F2);
a_add(a_L4,48,a_L4);
a_1433(a_L4); return;
} /* printform1 */
static void a_1431(a_word a_F1,a_word a_F2){ /* print+t[]+>a */
a_word a_L2;
if(!a_was(a_F1,a_F2)){ return;}
a_1490(a_1421,a_F1,a_F2);
a_stringlength(a_F1,a_F2,a_L2);
a_add(a_1441,a_L2,a_1441); return;
} /* print */
static void a_1440(a_word a_F1){ /* printpointer+>a */
a_word a_P[1];
a_G1:if(!a_equal(a_F1,0)){ goto a_G3;}
a_1431(a_1001,2130706308); return;
a_G3:if(a_1418(a_F1,a_P)){a_F1=a_P[0]; goto a_G1;}
if(!a_was(a_1420,a_F1)){ goto a_G6;}
a_1431(a_1420,a_F1); return;
a_G6:if(!a_was(a_1493,a_F1)){ goto a_G8;}
a_1431(a_1493,a_F1); return;
a_G8:if(!a_was(a_1451,a_F1)){ goto a_G11;}
a_1460(a_F1,a_P);a_F1=a_P[0];
a_1431(a_1451,a_F1); return;
a_G11:a_1427(a_1001,2130706304); return;
} /* printpointer */
static void a_1432(a_word a_F1){ /* printbase+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_L2=to_LIST(a_1447)->aupb;
if(!a_was(a_1451,a_F1)){ goto a_G5;}
a_1460(a_F1,a_P);a_F1=a_P[0];
a_unpackstring(a_1451,a_F1,a_1447); goto a_G9;
a_G5:if(!a_was(a_1493,a_F1)){ goto a_G7;}
a_unpackstring(a_1493,a_F1,a_1447); goto a_G9;
a_G7:if(a_equal(a_F1,0)){ goto a_G9;}
a_1427(a_1001,2130706298); return;
a_G9:a_L3=to_LIST(a_1447)->aupb;
a_L4=0;
a_G11:if(a_lseq(a_L3,a_L2)){ goto a_G18;}
if(!a_equal(to_LIST(a_1447)->offset[a_L3],46)){ goto a_G15;}
a_incr(a_L4);
a_G14:a_decr(a_L3); goto a_G11;
a_G15:if(a_equal(to_LIST(a_1447)->offset[a_L3],47)){ goto a_G18;}
if(a_equal(to_LIST(a_1447)->offset[a_L3],92)){ goto a_G18;}
if(!a_equal(to_LIST(a_1447)->offset[a_L3],58)){ goto a_G14;}
a_G18:a_incr(a_L3);
if(a_more(a_L3,to_LIST(a_1447)->aupb)){ goto a_G25;}
if(!a_equal(to_LIST(a_1447)->offset[a_L3],46)){ goto a_G24;}
if(a_lseq(a_L4,1)){ goto a_G25;}
a_decr(a_L4);
a_1433(46); goto a_G18;
a_G24:a_1433(to_LIST(a_1447)->offset[a_L3]); goto a_G18;
a_G25:a_unstackto(a_1447,a_L2); return;
} /* printbase */
static void a_1438(a_word a_F1){ /* printitem+>a */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[3];
a_1305(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];
if(a_lseq(a_L2,0)){ goto a_G4;}
a_1434(a_L2);
a_G4:if(a_equal(a_L3,183666554)){ goto a_G7;}
a_1433(47);
a_1432(a_L3);
a_G7:if(a_equal(a_L4,0)){ return;}
a_1433(32);
a_1431(a_1001,2130706293);
a_1440(a_L4);
a_1433(41); return;
} /* printitem */
static void a_1439(a_word a_F1){ /* printline+>a */
a_word a_L2;a_word a_L3;a_word a_P[2];
a_1306(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];
if(a_lseq(a_L2,0)){ goto a_G4;}
a_1434(a_L2);
a_G4:if(a_equal(a_L3,183666554)){ return;}
a_1433(47);
a_1432(a_L3); return;
} /* printline */
static void a_1426(a_word a_C,a_word *a_V){ /* formatprint+@+>a */
a_word a_L2;a_word a_L3;
a_L2=to_LIST(a_1447)->aupb;
a_unpackstring(a_1420,a_V[0],a_1447);
a_add(a_L2,1,a_L3);
a_G4:if(a_less(to_LIST(a_1447)->aupb,a_L3)){ goto a_G26;}
if(!a_noteq(to_LIST(a_1447)->offset[a_L3],37)){ goto a_G8;}
a_G6:a_1433(to_LIST(a_1447)->offset[a_L3]);
a_G7:a_incr(a_L3); goto a_G4;
a_G8:a_incr(a_L3);
if(!a_less(to_LIST(a_1447)->aupb,a_L3)){ goto a_G11;}
a_1433(37); goto a_G26;
a_G11:{register a_word a_r1=to_LIST(a_1447)->offset[a_L3];
 if(a_r1==112){ goto a_G12;}
 if(a_r1==120){ goto a_G15;}
 if(a_r1==105){ goto a_G17;}
 if(a_r1==99){ goto a_G19;}
 if(a_r1==108){ goto a_G21;}
 if(a_r1==100){ goto a_G23;}
 if(a_r1==110){  goto a_G25;}
  goto a_G6;}
a_G12:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1440(a_V[0]); goto a_G7;
a_G14:a_1431(a_1001,2130706288); goto a_G7;
a_G15:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1431(a_1451,a_V[0]); goto a_G7;
a_G17:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1438(a_V[0]); goto a_G7;
a_G19:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1433(a_V[0]); goto a_G7;
a_G21:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1439(a_V[0]); goto a_G7;
a_G23:if(a_C<=1){ goto a_G14;} a_C--;a_V+=1;
a_1436(a_V[0]); goto a_G7;
a_G25:a_1433(10); goto a_G7;
a_G26:if(a_C<=1){ goto a_G28;} a_C--;a_V+=1;
a_1431(a_1001,2130706285);
a_G28:a_unstackto(a_1447,a_L2); return;
} /* formatprint */
static a_word a_1444(void){ /* waserror */

if(!a_more(a_1424,0)){ return 0;} return 1;
} /* waserror */
static void a_1429(a_word a_F1){ /* messagehead+>a */
a_word a_L2;a_word a_P[1];
a_1430();
a_1433(a_F1);
a_1433(32);
a_1395(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G7;}
a_1432(a_L2);
a_G7:if(!a_equal(a_F1,70)){ goto a_G10;}
a_1433(47);
a_1434(a_1479);
a_G10:a_1433(32);
a_1442(16); return;
} /* messagehead */
static void a_1423(a_word a_C,a_word *a_V){ /* error+@+>a */
a_word a_P[1];
if(a_mreq(a_1424,51)){ return;}
a_1429(69);
a_1426(a_C,a_V);
a_1430();
a_incr(a_1424);
if(a_less(a_1424,51)){ return;}
a_1429(70);
a_P[0]=2047260568;a_1426(1,a_P);
a_1430(); return;
} /* error */
static void a_1443(a_word a_C,a_word *a_V){ /* warning+@+>a */

if(a_mreq(a_1424,51)){ return;}
a_1429(87);
a_1426(a_C,a_V);
a_1430(); return;
} /* warning */
static void a_1428(a_word a_C,a_word *a_V){ /* message+@+>a */

a_1426(a_C,a_V);
a_1430();
a_incr(a_1424); return;
} /* message */
static void a_1425(a_word a_C,a_word *a_V){ /* fatalerror+@+>a */

a_1429(70);
a_1426(a_C,a_V);
a_1430();
a_1139();
a_exit(15); return;
} /* fatalerror */
static void a_1422(a_word a_F1,a_word a_F2){ /* corrupticefile+t[]+>a */
a_word a_L2;a_word a_P[2];
a_1429(70);
a_1395(a_P);a_L2=a_P[0];
a_P[0]=2047260589;a_P[1]=a_L2;a_1426(2,a_P);
a_1431(a_F1,a_F2);
a_P[0]=2047260594;a_1426(1,a_P);
a_1430();
a_exit(3); return;
} /* corrupticefile */
static void a_1427(a_word a_F1,a_word a_F2){ /* internalerror+t[]+>a */
a_word a_P[1];
a_1429(70);
a_P[0]=2047260576;a_1426(1,a_P);
a_1431(a_F1,a_F2);
a_P[0]=2047260581;a_1426(1,a_P);
a_1430();
a_exit(15); return;
} /* internalerror */
static void a_1458(a_word a_F1){ /* extendBUFFER+>a */

{register a_word *a_r1=a_extension(a_1447,1);a_r1[0]=a_F1;to_LIST(a_1447)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1480(a_word a_A[1]){ /* trytoopensource+a> */
a_word a_L2;
if(!a_openfile(a_1452,114,a_1451,to_LIST(a_1451)->aupb)){ goto a_G8;}
a_A[0]=0;
a_unstackstring(a_1451);
a_1479=1;
a_1454=32;
a_1467();
a_1468(); return;
a_G8:a_unstackstring(a_1451);
a_getfileerror(a_1452,a_L2);
if(!a_equal(a_L2,2)){ goto a_G12;}
a_A[0]=1; return;
a_G12:a_A[0]=-1; return;
} /* trytoopensource */
static void a_1455(void){ /* closesource */

a_closefile(a_1452); return;
} /* closesource */
static void a_1467(void){ /* nextchar */
a_word a_P[1];
a_G1:if(!a_getchar(a_1452,a_P)){ goto a_G4;}a_1454=a_P[0];
{ if(a_1454==10){ goto a_G3;}
 if(a_1454<=31){  goto a_G1;}
  return;}
a_G3:a_incr(a_1479); return;
a_G4:a_1454=1; return;
} /* nextchar */
static void a_1478(void){ /* saveinputposition */
a_word a_P[1];
a_getfilepos(a_1452,a_P);a_1464=a_P[0];
a_1463=a_1454;
a_1465=a_1461;
a_1466=a_1462; return;
} /* saveinputposition */
static void a_1477(void){ /* restoreinputposition */

a_setfilepos(a_1452,a_1464);
a_1454=a_1463;
a_1461=a_1465;
a_1462=a_1466; return;
} /* restoreinputposition */
static void a_1456(void){ /* comment */

a_G1:if(a_equal(a_1454,10)){ return;}
if(a_equal(a_1454,1)){ return;}
a_1467(); goto a_G1;
} /* comment */
static void a_1471(a_word a_A[1]){ /* readdestination+a> */
a_word a_L2;
{ if(a_1454==78){ goto a_G2;}
 if(a_1454==48){ goto a_G15;}
 if(a_1454==45){  goto a_G17;}
  goto a_G28;}
a_G2:a_1467();
{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G8;}
}
a_subtr(a_1454,48,a_A[0]);
a_1467();
if(a_more(a_A[0],0)){ goto a_G9;}
if(a_equal(0,0)){ goto a_G9;}
a_G8:a_1422(a_1001,2130706355); return;
a_G9:{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G13;}
}
a_subtr(a_1454,48,a_L2);
a_1467();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G9;
a_G13:if(!a_is(0)){ return;}
a_G14:a_subtr(0,a_A[0],a_A[0]); return;
a_G15:a_1467();
a_A[0]=0; return;
a_G17:a_1467();
{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G8;}
}
a_subtr(a_1454,48,a_A[0]);
a_1467();
if(a_more(a_A[0],0)){ goto a_G23;}
if(!a_equal(1,0)){ goto a_G8;}
a_G23:{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G27;}
}
a_subtr(a_1454,48,a_L2);
a_1467();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G23;
a_G27:if(!a_is(1)){ return;} goto a_G14;
a_G28:a_1422(a_1001,2130706350); return;
} /* readdestination */
static void a_1473(a_word a_A[1]){ /* readtargetnumber+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L2=to_LIST(a_1447)->aupb;
a_L3=0;
a_G3:{ if(a_1454==45){ goto a_G4;}
 if((48<=a_1454 && a_1454<=57)){  goto a_G6;}
  goto a_G7;}
a_G4:a_L3=1;
a_G5:a_1467(); goto a_G3;
a_G6:a_1458(a_1454); goto a_G5;
a_G7:a_1007(a_L3,a_L2,a_P);a_A[0]=a_P[0];
a_unstackto(a_1447,a_L2); return;
} /* readtargetnumber */
static void a_1459(a_word a_F1,a_word a_A[1]){ /* gettagdata+>a+a> */

a_A[0]=to_LIST(a_1451)->offset[a_F1]; return;
} /* gettagdata */
static void a_1460(a_word a_F1,a_word a_A[1]){ /* gettagimage+>a+a> */

a_subtr(a_F1,2,a_A[0]); return;
} /* gettagimage */
static void a_1469(a_word a_F1,a_word a_F2){ /* puttagdata+>a+>a */

to_LIST(a_1451)->offset[a_F1]=a_F2; return;
} /* puttagdata */
static void a_1453(a_word a_A[1]){ /* addLEXTentry+a> */
a_word a_P[1];
{register a_word *a_r1=a_extension(a_1451,2);a_r1[0]=a_r1[1]=0;to_LIST(a_1451)->aupb+=2;}
a_1457(to_LIST(a_1451)->aupb,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],to_LIST(a_1451)->aupb)){ return;}
a_unstack(a_1451);
a_unstackstring(a_1451); return;
} /* addLEXTentry */
static void a_1457(a_word a_F1,a_word a_A[1]){ /* enterstring+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_L7;a_word a_P[1];
a_subtr(a_F1,2,a_L3);
a_stringhash(a_1451,a_L3,a_P);a_L4=a_P[0];
a_booland(a_L4,2147483647,a_L4);
a_divrem01(a_L4,a_1450,a_L4);
a_add(a_L4,to_LIST(a_1448)->alwb,a_L4);
a_L5=to_LIST(a_1448)->offset[a_L4];
a_G7:if(!a_equal(a_L5,0)){ goto a_G14;}
to_LIST(a_1451)->offset[a_F1-1]=to_LIST(a_1448)->offset[a_L4];
to_LIST(a_1448)->offset[a_L4]=a_F1;a_A[0]=a_F1;
a_incr(a_1449);
if(a_less(a_1449,a_1450)){ return;}
a_add(a_1450,1024,a_1450);
a_1476(); return;
a_G14:a_subtr(a_L5,2,a_L6);
a_comparestring(a_1451,a_L3,a_1451,a_L6,a_P);a_L7=a_P[0];
if(!a_equal(a_L7,0)){ goto a_G18;}
a_A[0]=a_L5; return;
a_G18:a_L5=to_LIST(a_1451)->offset[a_L5-1]; goto a_G7;
} /* enterstring */
static void a_1476(void){ /* rehash */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_1449=0;
a_L1=to_LIST(a_1448)->aupb;
a_G3:if(a_less(a_L1,to_LIST(a_1448)->alwb)){ goto a_G6;}
to_LIST(a_1448)->offset[a_L1]=0;
a_previous(a_1448,a_L1); goto a_G3;
a_G6:a_subtr(to_LIST(a_1448)->aupb,to_LIST(a_1448)->alwb,a_L2);
a_G7:a_incr(a_L2);
if(a_mreq(a_L2,a_1450)){ goto a_G10;}
{register a_word *a_r1=a_extension(a_1448,1);a_r1[0]=0;to_LIST(a_1448)->aupb+=1;}
  goto a_G7;
a_G10:a_L1=to_LIST(a_1451)->aupb;
a_G11:if(a_less(a_L1,to_LIST(a_1451)->alwb)){ return;}
a_1457(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,a_L1)){ goto a_G16;}
a_previous(a_1451,a_L1);
a_previousstring(a_1451,a_L1); goto a_G11;
a_G16:a_1427(a_1001,2130706344); return;
} /* rehash */
static void a_1472(a_word a_A[1]){ /* readstring+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1447)->aupb;
a_L2=0;
a_G3:a_1467();
{ if(a_1454==34){ goto a_G5;}
 if(a_1454==10||a_1454==1){  goto a_G14;}
  goto a_G7;}
a_G5:a_1467();
if(!a_equal(a_1454,34)){ goto a_G9;}
a_G7:a_1458(a_1454);
a_incr(a_L2); goto a_G3;
a_G9:if(!a_equal(a_L2,0)){ goto a_G11;}
a_A[0]=183666554; return;
a_G11:a_packstring(a_1447,a_L2,a_1451);
a_unstackto(a_1447,a_L3);
a_1453(a_P);a_A[0]=a_P[0]; return;
a_G14:a_1422(a_1001,2130706340); return;
} /* readstring */
static void a_1474(a_word a_A[2]){ /* readtargetstring+a>+a> */
a_word a_L3;a_word a_P[2];
a_L3=to_LIST(a_1447)->aupb;
if(a_equal(a_1454,34)){ goto a_G4;}
a_G3:a_1422(a_1001,2130706335); return;
a_G4:a_1467();
{ if(a_1454==34){ goto a_G6;}
 if(a_1454==10||a_1454==1){  goto a_G3;}
  goto a_G8;}
a_G6:a_1467();
if(!a_equal(a_1454,34)){ goto a_G9;}
a_G8:a_1458(a_1454); goto a_G4;
a_G9:a_1008(a_L3,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];
a_unstackto(a_1447,a_L3); return;
} /* readtargetstring */
static void a_1470(a_word a_A[1]){ /* readbold+a> */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1467();
a_L3=to_LIST(a_1447)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1454 && a_1454<=122))){ goto a_G9;}
}
a_L4=a_1454;
a_1467();
a_1458(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1454,39)){ goto a_G11;}
a_1467(); goto a_G12;
a_G11:a_1422(a_1001,2130706328); return;
a_G12:a_packstring(a_1447,a_L2,a_1451);
a_unstackto(a_1447,a_L3);
a_A[0]=16777299;
a_G15:a_comparestring(a_1446,a_A[0],a_1451,to_LIST(a_1451)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G19;}
if(a_equal(a_A[0],16777220)){ goto a_G11;}
a_previousstring(a_1446,a_A[0]); goto a_G15;
a_G19:a_unstackstring(a_1451); return;
} /* readbold */
static void a_1475(a_word a_A[1]){ /* readtype+a> */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1467();
a_L3=to_LIST(a_1447)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1454 && a_1454<=122))){ goto a_G9;}
}
a_L4=a_1454;
a_1467();
a_1458(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1454,32)){ goto a_G13;}
a_1458(32);
a_incr(a_L2);
a_1467(); goto a_G4;
a_G13:if(!a_equal(a_1454,62)){ goto a_G15;}
a_1467(); goto a_G16;
a_G15:a_1422(a_1001,2130706323); return;
a_G16:a_packstring(a_1447,a_L2,a_1451);
a_unstackto(a_1447,a_L3);
a_A[0]=16777394;
a_G19:a_comparestring(a_1446,a_A[0],a_1451,to_LIST(a_1451)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G23;}
if(a_equal(a_A[0],16777304)){ goto a_G15;}
a_previousstring(a_1446,a_A[0]); goto a_G19;
a_G23:a_unstackstring(a_1451); return;
} /* readtype */
static void a_1468(void){ /* nextsymbol */
a_word a_L1;a_word a_P[2];
a_G1:a_P[0]=a_1481;a_1020(a_P);a_1481=a_P[0];a_1462=a_P[1];
if(!a_more(a_1481,0)){ goto a_G4;}
a_1461=16777459; return;
a_G4:{ if(a_1454==32||a_1454==10){ goto a_G5;}
 if(a_1454==36){ goto a_G6;}
 if(a_1454==48){ goto a_G7;}
 if((49<=a_1454 && a_1454<=57)){ goto a_G10;}
 if(a_1454==70){ goto a_G23;}
 if(a_1454==73){ goto a_G34;}
 if(a_1454==76){ goto a_G48;}
 if(a_1454==78){ goto a_G59;}
 if(a_1454==88){ goto a_G70;}
 if(a_1454==84){ goto a_G73;}
 if(a_1454==39){ goto a_G76;}
 if(a_1454==60){ goto a_G77;}
 if(a_1454==34){ goto a_G79;}
 if(a_1454==38){ goto a_G81;}
 if(a_1454==93){ goto a_G82;}
 if(a_1454==41){ goto a_G83;}
 if(a_1454==58){ goto a_G84;}
 if(a_1454==44){ goto a_G85;}
 if(a_1454==126){ goto a_G86;}
 if(a_1454==47){ goto a_G87;}
 if(a_1454==45){ goto a_G88;}
 if(a_1454==35){ goto a_G103;}
 if(a_1454==40){ goto a_G104;}
 if(a_1454==124){ goto a_G105;}
 if(a_1454==62){ goto a_G106;}
 if(a_1454==43){ goto a_G109;}
 if(a_1454==46){ goto a_G110;}
 if(a_1454==59){ goto a_G111;}
 if(a_1454==42){ goto a_G112;}
 if(a_1454==91){ goto a_G113;}
 if(a_1454==94){ goto a_G114;}
 if(a_1454==64){ goto a_G115;}
 if(a_1454==1){  goto a_G116;}
  goto a_G117;}
a_G5:a_1467(); goto a_G1;
a_G6:a_1456(); goto a_G1;
a_G7:a_1461=16777455;
a_1462=0;
a_G9:a_1467(); return;
a_G10:a_1461=16777455;
{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G16;}
}
a_subtr(a_1454,48,a_1462);
a_1467();
if(a_more(a_1462,0)){ goto a_G17;}
if(a_equal(0,0)){ goto a_G17;}
a_G16:a_1422(a_1001,2130706355); return;
a_G17:{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G21;}
}
a_subtr(a_1454,48,a_L1);
a_1467();
a_addmult(a_1462,10,a_L1,a_1462); goto a_G17;
a_G21:if(!a_is(0)){ return;}
a_G22:a_subtr(0,a_1462,a_1462); return;
a_G23:a_1461=16777475;
a_1467();
{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G16;}
}
a_subtr(a_1454,48,a_1462);
a_1467();
if(a_more(a_1462,0)){ goto a_G30;}
if(!a_equal(0,0)){ goto a_G16;}
a_G30:{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G21;}
}
a_subtr(a_1454,48,a_L1);
a_1467();
a_addmult(a_1462,10,a_L1,a_1462); goto a_G30;
a_G34:a_1461=16777471;
a_1467();
{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G16;}
}
a_subtr(a_1454,48,a_1462);
a_1467();
if(a_more(a_1462,0)){ goto a_G41;}
if(!a_equal(0,0)){ goto a_G16;}
a_G41:{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G45;}
}
a_subtr(a_1454,48,a_L1);
a_1467();
a_addmult(a_1462,10,a_L1,a_1462); goto a_G41;
a_G45:if(!a_is(0)){ goto a_G47;}
a_subtr(0,a_1462,a_1462);
a_G47:a_P[0]=a_1462;a_1300(a_P);a_1462=a_P[0]; return;
a_G48:a_1461=16777479;
a_1467();
{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G16;}
}
a_subtr(a_1454,48,a_1462);
a_1467();
if(a_more(a_1462,0)){ goto a_G55;}
if(!a_equal(0,0)){ goto a_G16;}
a_G55:{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G21;}
}
a_subtr(a_1454,48,a_L1);
a_1467();
a_addmult(a_1462,10,a_L1,a_1462); goto a_G55;
a_G59:a_1461=16777467;
a_1467();
{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G16;}
}
a_subtr(a_1454,48,a_1462);
a_1467();
if(a_more(a_1462,0)){ goto a_G66;}
if(!a_equal(0,0)){ goto a_G16;}
a_G66:{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G21;}
}
a_subtr(a_1454,48,a_L1);
a_1467();
a_addmult(a_1462,10,a_L1,a_1462); goto a_G66;
a_G70:a_1461=16777459;
a_1467();
a_1473(a_P);a_1462=a_P[0]; return;
a_G73:a_1461=16777459;
a_1467();
a_1474(a_P);a_1481=a_P[0];a_1462=a_P[1]; return;
a_G76:a_1470(a_P);a_1461=a_P[0]; return;
a_G77:a_1461=16777463;
a_1475(a_P);a_1462=a_P[0]; return;
a_G79:a_1461=16777483;
a_1472(a_P);a_1462=a_P[0]; return;
a_G81:a_1461=16777400; goto a_G9;
a_G82:a_1461=16777403; goto a_G9;
a_G83:a_1461=16777406; goto a_G9;
a_G84:a_1461=16777409; goto a_G9;
a_G85:a_1461=16777412; goto a_G9;
a_G86:a_1461=16777415; goto a_G9;
a_G87:a_1461=16777418; goto a_G9;
a_G88:a_1467();
{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G101;}
}
a_1461=16777455;
{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G16;}
}
a_subtr(a_1454,48,a_1462);
a_1467();
if(a_more(a_1462,0)){ goto a_G96;}
if(!a_equal(1,0)){ goto a_G16;}
a_G96:{ if(!((48<=a_1454 && a_1454<=57))){ goto a_G100;}
}
a_subtr(a_1454,48,a_L1);
a_1467();
a_addmult(a_1462,10,a_L1,a_1462); goto a_G96;
a_G100:if(!a_is(1)){ return;} goto a_G22;
a_G101:a_1461=16777421;
a_1462=0; return;
a_G103:a_1461=16777424; goto a_G9;
a_G104:a_1461=16777427; goto a_G9;
a_G105:a_1461=16777430; goto a_G9;
a_G106:a_1461=16777433;
a_1467();
a_1471(a_P);a_1462=a_P[0]; return;
a_G109:a_1461=16777436; goto a_G9;
a_G110:a_1461=16777439; goto a_G9;
a_G111:a_1461=16777442; goto a_G9;
a_G112:a_1461=16777445; goto a_G9;
a_G113:a_1461=16777448; goto a_G9;
a_G114:a_1461=16777451; goto a_G9;
a_G115:a_1461=16777397; goto a_G9;
a_G116:a_1461=16777486; return;
a_G117:a_1422(a_1001,2130706318); return;
} /* nextsymbol */
static void a_1445(void){ /* @root */

a_1476(); return;
} /* @root */
static void a_1483(void){ /* pass1 */
a_word a_L1;a_word a_P[1];
a_G1:if(a_1444()){ return;}
if(!a_1396(a_P)){ return;}a_L1=a_P[0];
a_1322(a_L1);
a_1329();
a_1455(); goto a_G1;
} /* pass1 */
static void a_1484(void){ /* pass2 */
a_word a_L1;a_word a_P[1];
a_G1:if(a_1444()){ return;}
a_1339(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_equal(a_L1,2)){ goto a_G1;}
a_1359();
a_1360();
a_1254(); goto a_G1;
} /* pass2 */
static void a_1485(void){ /* pass3 */
a_word a_L1;a_word a_P[1];
a_G1:if(a_1444()){ return;}
a_1339(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_equal(a_L1,2)){ goto a_G1;}
a_1359();
a_1360();
a_1255(); goto a_G1;
} /* pass3 */
static void a_1486(void){ /* pass4 */
a_word a_L1;a_word a_P[1];
a_1143();
a_G2:a_1339(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ goto a_G8;}
if(a_equal(a_L1,2)){ goto a_G2;}
a_1359();
a_1360();
a_1256(); goto a_G2;
a_G8:a_1144(); return;
} /* pass4 */
static void a_1487(void){ /* pass5 */
a_word a_L1;a_word a_P[1];
a_G1:if(a_1444()){ return;}
a_1339(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_equal(a_L1,2)){ goto a_G1;}
a_1359();
a_1360();
a_1280();
a_1082(); goto a_G1;
} /* pass5 */
static void a_1482(void){ /* @root */

a_1391();
if(!a_1444()){ goto a_G4;}
a_exit(1); return;
a_G4:a_1483();
if(!a_1444()){ goto a_G8;}
a_G6:a_1455();
a_G7:a_exit(2); return;
a_G8:a_1355();
a_1349();
a_1484();
if(a_1444()){ goto a_G6;}
a_1235();
a_1267();
a_1485();
if(a_1444()){ goto a_G6;}
a_1257();
if(a_1444()){ goto a_G7;}
a_1228();
if(a_1444()){ goto a_G7;}
a_1246();
a_1165();
if(!a_1444()){ goto a_G24;}
a_exit(4); return;
a_G24:a_1208();
a_1134();
a_1486();
a_1136();
a_1205();
a_1487();
a_1186();
a_1207();
a_1131();
if(!a_1444()){ return;}
a_1139(); goto a_G7;
} /* @root */
static void a_1490(a_word a_F1,a_word a_F2,a_word a_F3){ /* putstring+""f+t[]+>a */
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
static int a_push_string_to(int F1,const char*ptr){ int n,w;int*goal;char*to;
 #define st to_LIST(F1)
 n=strlen(ptr);if(a_requestspace(F1,3+(n/4))==0){return 0;}
 n=0;goal=&(st->offset[1+st->aupb]);to=(char*)goal;
 while(*ptr){if((*ptr&0x80)==0){*to++=*ptr++;n++;}  else if((*ptr&0xC0)!=0xC0){ptr++;}  else if((*ptr&0xE0)==0xC0){*to++=*ptr++;n++;   if((*ptr&0xC0)!=0x80){n--;to--;}else{*to++=*ptr++;}}  else if((*ptr&0xF0)==0xE0){*to++=*ptr++;n++;   if((*ptr&0xC0)!=0x80){n--;to--;}else{*to++=*ptr++;    if((*ptr&0xC0)!=0x80){n--;to-=2;}else{*to++=*ptr++;}}}  else if((*ptr&0xF8)==0xF0){*to++=*ptr++;n++;   if((*ptr&0xC0)!=0x80){n--;to--;}else{*to++=*ptr++;    if((*ptr&0xC0)!=0x80){n--;to-=2;}else{*to++=*ptr++;     if((*ptr&0xC0)!=0x80){n--;to-=3;}else {*to++=*ptr++;}}}}  else{ptr++;}}
 *to=0;w=1+(to-((char*)goal))/4;goal[w]=n;goal[w+1]=w+2;st->aupb+=w+2;
 #undef st
 return 1;}
static void a_setup_stdarg(int F1,const char*name,int F2){
 int i;
 #define st to_LIST(F1)
 st->name=name;st->offset=st->p=0;st->length=0; st->vlwb=a_virtual_max+16;a_virtual_max+=65436; if(a_virtual_max<=0){fprintf(stderr,"Out of virtual space\n");  a_fatal(a_FATAL_memory);}
 st->vupb=a_virtual_max-1;st->calibre=F2; st->alwb=st->vlwb;st->aupb=st->alwb-st->calibre;
  for(i=a_argc-1;i>0;i--){   if(a_push_string_to(F1,a_argv[i])==0){    fprintf(stderr,"out of memory\n");a_fatal(a_FATAL_memory);} }
 #undef st
}
/* EOF */
