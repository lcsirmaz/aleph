/* ALEPH ice linker v2.1, word size=32 */

// linked modules:
// dataflow "data flow, v2.1"
// ice "ice, v2.1"
// macros "macros v2.0"
// number "number v2.0"
// arithmetic "arithmetic v2.0"
// buffer "buffer v2.0"
// config "config v2.3"
// disc "disc v2.0"
// dictionary "dictionary v2.0"
// display "display v2.1"
// files "files v2.0"
// identifier "identifier v2.1"
// input "input, v2.1"
// lexical "lexical v2.0"
// lists "lists, v2.0"
// @main "ALEPH to ICE compiler, v2.0"
// pass1 "pass1, v2.1"
// path "path v2.0"
// pragmats "pragmats, v2.1"
// rules "rules v2.0"
// rulebody "rule body v2.1"
// pass2 "pass2, v2.1"
// pass3 "pass3, v2.0"
// pass4 "pass4, v2.0"
// selector "selector v2.0"
// symbols "symbols v2.0"
// tags "tags v2.0"
// types "types v2.0"
// variables "variables v2.0"
// node "node v2.0"
// stdlib "libC base"
// stdlib "libC put as string"
// stdlib "libC put string"
// stdlib "libC wait for"
// stdlib "libC stdarg"
#include "aleph_core.h"
static void a_setup_stdarg(int,const char*,int);
#include "aleph_stdlib.h"
#define a_1001 (0) /* @StringTable */
static int a_1005(int a_A[1]); /* Ltag */
static int a_1006(int a_F1,int a_F2,int a_A[1]); /* actualanchoraffix */
static void a_1007(int a_A[3]); /* actualrule */
static void a_1008(int a_F1,int a_F2); /* addlabel */
static void a_1009(int a_F1,int a_F2,int a_F3); /* affixtypeerror */
static void a_1010(int a_F1,int a_F2,int a_F3); /* affixuninitializederror */
static void a_1011(int a_F1,int a_A[6]); /* altsequence */
static void a_1012(int a_F1,int a_A[6]); /* alttail */
static void a_1013(int a_F1,int a_F2,int a_F3); /* checkcalibre */
static void a_1014(int a_F1,int a_F2); /* checkextensionblock */
static void a_1015(int a_F1); /* checklabelshield */
static void a_1016(int a_F1); /* checkmacrorule */
static void a_1017(int a_F1,int a_F2); /* checkoutaffixes */
static void a_1018(int a_F1); /* checkruledataflow */
static void a_1019(int a_F1,int a_F2,int a_F3); /* checkssel */
static void a_1020(int a_F1,int a_F2); /* checkzoneinterval */
static void a_1021(int a_F1,int a_F2); /* checkzonemember */
static void a_1022(int a_F1,int a_A[6]); /* classification */
static void a_1023(int a_A[1]); /* classifier */
static void a_1024(int a_F1,int a_F2); /* clearRULEflag */
static void a_1025(int a_F1,int a_F2); /* clearlocalflag */
static void a_1026(int a_F1); /* cleartailFbits */
static void a_1027(int a_F1); /* closerange */
static int a_1028(int a_F1,int a_F2); /* compatiblerepeatblocktypes */
static int a_1029=0; /* compoundlevel */
static void a_1030(int a_A[6]); /* compoundmember */
static void a_1031(int a_F1,int a_F2); /* constantaffixerror */
static void a_1032(void); /* copylocalTflagtoF */
static void a_1033(int a_F1,int a_F2,int a_F3); /* destlisttypeerror */
static void a_1034(int a_F1,int a_F2,int a_F3); /* desttypeerror */
static void a_1035(int a_F1,int a_F2); /* dummyaffixerror */
static void a_1036(int a_F1); /* extendBUFFER */
static void a_1037(int a_F1,int a_F2); /* extendRULE */
static void a_1038(void); /* extension */
static void a_1039(int a_F1,int a_F2); /* ffileaffix */
static void a_1040(int a_F1); /* fshiftaffix */
static void a_1041(int a_F1,int a_F2,int a_F3,int a_A[1]); /* fsimpleaffix */
static void a_1042(int a_F1,int a_F2); /* fstackaffix */
static void a_1043(int a_F1,int a_F2); /* ftableaffix */
static void a_1044(int a_F1,int a_A[1]); /* getftype */
static void a_1045(int a_F1,int a_A[1]); /* getlocalcalibre */
static void a_1046(int a_F1,int a_A[1]); /* getlocalssel */
static int a_1047(int a_F1); /* haslisttype */
static int a_1048(int a_F1,int a_F2); /* isRULEflag */
static int a_1049(int a_F1,int a_F2); /* islocalflag */
static void a_1050(int a_F1,int a_F2,int a_F3,int a_A[1]); /* matchformalactual */
static void a_1051(int a_F1,int a_F2,int a_F3,int a_A[1]); /* matchrepeataffixes */
static void a_1052(int a_F1,int a_A[6]); /* member */
static void a_1053(int a_F1,int a_F2,int a_F3); /* mergealtsequenceflags */
static void a_1054(int a_F1); /* mergetailFbits */
static void a_1055(int a_A[1]); /* mustLtag */
static void a_1056(int a_F1,int a_F2,int a_F3); /* mustbeoflisttype */
static void a_1057(int a_F1); /* openrange */
static void a_1058(int a_F1,int a_F2,int a_F3); /* pushBUFFER */
static void a_1059(int a_F1); /* pushRULE */
static void a_1060(void); /* readbox */
static void a_1061(int a_F1,int a_F2,int a_F3,int a_A[1]); /* readselector */
static void a_1062(int a_F1); /* recomputeRULEflags */
static int a_1063(int a_F1,int a_F2,int a_F3,int a_A[1]); /* redoregion */
static void a_1064(int a_F1); /* resetaffixblockflags */
static void a_1065(int a_A[6]); /* rulebody */
static int a_1066=0; /* rulecompiled */
static void a_1067(int a_F1,int a_F2); /* setRULEflag */
static void a_1068(int a_F1,int a_F2); /* setlocalflag */
static void a_1069(int a_F1,int a_F2,int a_A[2]); /* setrulejump */
static void a_1070(int a_F1); /* setupaltheadflags */
static void a_1071(int a_F1); /* setupformalstack */
static void a_1072(int a_A[1]); /* setuplabel */
static void a_1073(void); /* setuplocals */
static void a_1074(void); /* skipaffixes */
static void a_1075(void); /* skipsource */
static void a_1076(int a_F1); /* storealtheadflags */
static void a_1077(int a_F1); /* storemacro */
static void a_1078(int a_F1,int a_F2); /* transport */
static void a_1079(int a_F1,int a_F2); /* transportdest */
static int a_1080(int a_F1); /* ureadonly */
static void a_1081(int a_F1); /* usetailFbits */
static void a_1082(int a_F1,int a_A[1]); /* uslicetype */
static void a_1083(int a_F1,int a_F2,int a_A[1]); /* where */
#define a_1085 (a_1001+sizeof_LIST) /* ICE */
#define a_1086 (a_1085+sizeof_CHFILE) /* NODE */
static void a_1087(int a_F1); /* W */
static void a_1088(int a_F1); /* Wbase */
static void a_1089(int a_F1); /* Wcons */
static void a_1090(int a_F1); /* Wfstr */
static void a_1091(void); /* Wline */
static void a_1092(int a_F1); /* Wnumber */
static void a_1093(void); /* Wspace */
static void a_1094(int a_F1); /* Wstring */
static void a_1095(int a_F1); /* Wtag */
static void a_1096(int a_F1); /* Wtype */
static void a_1097(void); /* closeicefile */
static void a_1098(void); /* deleteicefile */
static void a_1099(void); /* openicefile */
static void a_1100(int a_F1); /* printint */
static void a_1101(int a_F1,int a_F2); /* printint1 */
static void a_1103(void); /* alternative */
static void a_1104(void); /* altsequence */
static void a_1105(int a_F1); /* checkmacrorule */
static void a_1106(void); /* checkmacrorules */
static void a_1107(void); /* classification */
static void a_1108(void); /* member */
static void a_1109(void); /* rulebody */
static void a_1110(void); /* skipaffixes */
static void a_1111(void); /* skipsource */
#define a_1113 (a_1086+sizeof_LIST) /* NUMBER */
static void a_1114(int a_F1,int a_F2); /* adddigit */
static void a_1115(int a_F1,int a_F2); /* addhexdigit */
static void a_1116(int a_F1,int a_F2,int a_A[1]); /* enterconststring */
static void a_1117(int a_F1,int a_A[1]); /* enterconstvalue */
static void a_1118(int a_F1,int a_F2,int a_A[1]); /* enterhexconststring */
static void a_1119(int a_F1); /* extendBUFFER */
static void a_1120(int a_F1,int a_A[1]); /* getdigit */
static void a_1121(int a_F1,int a_A[1]); /* gethexdigit */
static void a_1122(int a_F1); /* getnumberrepr */
static void a_1123(int a_A[1]); /* getnumberzero */
static void a_1124(int a_F1,int a_F2); /* getregisterrepr */
static void a_1125(int a_F1,int a_A[1]); /* gettargetnumbervalue */
static void a_1126(void); /* initializenumbers */
static int a_1127=0; /* lastdigit */
static int a_1128=0; /* maxdecimal */
static int a_1129=0; /* maxhex */
static int a_1130=0; /* rtargetmax */
static int a_1131=0; /* rtargetmin */
static int a_1132(int a_F1); /* samenumberblock */
static void a_1133(int a_F1,int a_A[1]); /* storeregister */
static int a_1134=0; /* zeroptr */
#define a_1136 (a_1113+sizeof_LIST) /* REGISTER */
static void a_1137(int a_F1,int a_A[1]); /* duplregister */
static void a_1138(int a_F1); /* freeregister */
static void a_1139(int a_F1,int a_A[1]); /* getcstregister */
static void a_1140(int a_A[1]); /* getregister */
static int a_1141(int a_F1); /* istargetconst */
static void a_1142(int a_F1,int a_A[1]); /* putcstregister */
static void a_1143(int a_F1,int a_F2,int a_A[1]); /* readregister */
static int a_1144(int a_F1,int a_F2); /* regcompare */
static int a_1145(int a_F1,int a_F2,int a_F3); /* regcompare2 */
static void a_1146(int a_F1,int a_F2,int a_F3); /* regoperator */
static int a_1147=1; /* targetwordwidth */
static void a_1148(int a_F1,int a_F2); /* writeregister */
#define a_1150 (a_1136+sizeof_LIST) /* BUFFER */
#define a_1151 (a_1150+sizeof_LIST) /* RULE */
static void a_1154(int a_F1); /* D */
#define a_1155 (a_1151+sizeof_LIST) /* DISCR */
#define a_1156 (a_1155+sizeof_DFILE) /* DISCW */
#define a_1157 (a_1156+sizeof_DFILE) /* DSYMB */
static void a_1158(int a_F1); /* Dcons */
static void a_1159(void); /* Dnlcr */
static void a_1160(int a_F1,int a_F2); /* Dqtag */
static void a_1161(int a_F1); /* Dstring */
static void a_1162(int a_F1); /* Dtag */
static void a_1163(int a_F1); /* Dttag */
static int a_1164(int a_F1); /* Q */
#define a_1165 (a_1157+sizeof_LIST) /* QBUFFER */
static int a_1166(int a_F1); /* Qahead */
static int a_1167=0; /* Qbufferptr */
static int a_1168(int a_A[1]); /* Qcons */
static int a_1169=0; /* Qlinenum */
static int a_1170=0; /* Qlocal */
static int a_1171(int a_A[1]); /* Qltag */
static int a_1172(int a_A[1]); /* Qnumber */
static int a_1173=0; /* Qposition */
static int a_1174(int a_A[2]); /* Qqtag */
static int a_1175=0; /* Qshift */
static void a_1176(int a_F1); /* Qskip */
static int a_1177(int a_A[1]); /* Qstring */
static int a_1178=0; /* Qsymbol */
static int a_1179(int a_A[1]); /* Qtag */
static int a_1180(int a_A[1]); /* Qttag */
static int a_1181=0; /* Qtype */
static void a_1182(void); /* closediscs */
static void a_1183(int a_A[1]); /* copyQBUFFERaffix */
static void a_1184(void); /* deletediscs */
static int a_1185=0; /* disc1 */
static int a_1186=0; /* disc2 */
static void a_1187(int a_F1,int a_F2,int a_F3); /* expandvarargs */
static void a_1188(int a_F1,int a_F2,int a_A[1]); /* finalssel */
static void a_1189(int a_A[1]); /* fsimpleaffix */
static void a_1190(int a_F1,int a_F2,int a_F3); /* handleformallist */
static int a_1191(int a_A[1]); /* limitop */
static void a_1192(int a_F1); /* macroarguments */
static void a_1193(int a_F1,int a_A[2]); /* macrocallhead */
static void a_1194(int a_F1,int a_F2); /* macrocalltail */
static void a_1195(int a_F1,int a_A[1]); /* matchformalactual */
static void a_1196(int a_F1); /* mustQ */
static void a_1197(int a_A[1]); /* mustQcons */
static void a_1198(int a_A[2]); /* mustQlist */
static void a_1199(int a_A[2]); /* mustQqtag */
static void a_1200(int a_A[1]); /* mustQtag */
static void a_1201(int a_A[1]); /* mustQttag */
static void a_1202(int a_A[1]); /* mustQtype */
static void a_1203(void); /* nextdiscsymbol */
static void a_1204(int a_F1,int a_F2); /* opendisc */
static void a_1205(int a_F1,int a_F3,int a_A[1]); /* openthisdisc */
static void a_1206(int a_C,int *a_V); /* putQ */
static void a_1207(void); /* readfromQBUFFER */
static void a_1208(int a_F1,int a_A[1]); /* readselector */
static void a_1209(int a_F1,int a_F2); /* restorediscposition */
static void a_1210(void); /* rewinddisc */
static void a_1211(int a_A[2]); /* savediscposition */
static void a_1212(void); /* substitute */
static int a_1213=0; /* wlinenum */
static void a_1214(int a_F1,int a_F2); /* writedisc */
static int a_1215=0; /* wwlinenum */
#define a_1217 (a_1165+sizeof_LIST) /* DICT */
static void a_1218(int a_F1); /* DICTtag */
static void a_1219(int a_F1,int a_F2); /* addDICT */
static void a_1220(int a_F1,int a_F2); /* addlinetoDICT */
static void a_1221(int a_F1,int a_F2); /* expandDICT */
static void a_1222(int a_F1); /* extendDICT */
static int a_1223(int a_F1); /* isspecialtag */
static void a_1224(int a_F1,int a_F2,int a_A[1]); /* pack2 */
static void a_1225(int a_F1); /* printdict */
static void a_1226(void); /* printdictionary */
static void a_1227(int a_F1); /* reverseDICT */
static void a_1228(int a_F1,int a_A[2]); /* unpack2 */
static void a_1230(int a_F1); /* DICTdeflines */
static void a_1231(int a_F1); /* DICTheader */
static void a_1232(int a_F1); /* DICTitem */
static void a_1233(void); /* DICTtab */
static void a_1234(void); /* DICTtail */
static void a_1235(int a_C,int *a_V); /* Error */
#define a_1236 (a_1217+sizeof_LIST) /* MESSAGE */
#define a_1237 (a_1236+sizeof_LIST) /* PRINTFILE */
static void a_1238(int a_F1,int a_C,int *a_V); /* Xerror */
static void a_1239(int a_C,int *a_V); /* Xmessage */
static void a_1240(int a_F1,int a_F2,int a_C,int *a_V); /* Xwarning */
static void a_1241(int a_A[1]); /* clearlocalerror */
static void a_1242(int a_F1,int a_F2); /* displaychar */
static int a_1243=0; /* errorno */
static void a_1244(int a_F1); /* extendBUFFER */
static void a_1245(int a_F1,int a_A[2]); /* findfilebase */
static void a_1246(int a_C,int *a_V); /* formatprint */
static int a_1247(int a_F1,int a_A[1]); /* hasaleextension */
static void a_1248(int a_F1,int a_F2); /* internalerror */
static int a_1249=0; /* lastdictsrc */
static void a_1250(int a_C,int *a_V); /* message */
static void a_1251(int a_F1,int a_F2); /* messageheader */
static void a_1252(void); /* nlcr */
static int a_1253=1; /* oldprpos */
static void a_1254(int a_A[1]); /* popBUFFER */
static void a_1255(int a_F1,int a_F2); /* print */
static void a_1256(int a_F1); /* printbase */
static void a_1257(int a_F1); /* printchar */
static void a_1258(int a_F1); /* printform */
static void a_1259(int a_F1,int a_F2); /* printform1 */
static void a_1260(int a_F1); /* printint */
static void a_1261(int a_F1,int a_F2); /* printint1 */
static void a_1262(int a_F1); /* printlinehead */
static void a_1263(int a_F1); /* printpointer */
static void a_1264(int a_F1); /* printsourceline */
static int a_1265=0; /* prline */
static int a_1266=0; /* prpos */
static int a_1267=1; /* prposok */
static void a_1268(void); /* resetprline */
static int a_1269=120; /* righthandmargin */
static void a_1270(void); /* saveprpos */
static void a_1271(int a_F1); /* suspendErrors */
static int a_1272=0; /* suspendno */
static void a_1273(int a_F1); /* tabline */
static int a_1274(void); /* waserror */
static int a_1275(int a_F1); /* waslocalerror */
static void a_1277(int a_F1); /* charfiledeclaration */
static void a_1278(int a_F1); /* datafiledeclaration */
static void a_1279(int a_A[1]); /* declaration */
static void a_1280(int a_F1); /* declarationseries */
static void a_1281(int a_F1); /* declarer */
static void a_1282(int a_F1,int a_A[2]); /* expectpath */
static void a_1283(int a_F1); /* externaldeclarer */
static void a_1284(void); /* filearea */
static void a_1285(int a_F1); /* fileareadeclarer */
static int a_1286=0; /* lqf */
static int a_1287=0; /* ltag */
static int a_1288=0; /* ltype */
static void a_1289(int a_F1); /* prototype */
static int a_1291=0; /* BASE0 */
static void a_1292(int a_F1); /* canonizedefs */
static void a_1293(int a_F1,int a_F2); /* canonizesingletag */
static void a_1294(void); /* checkallttags */
static void a_1295(int a_F1); /* checkdblettag */
static void a_1296(int a_F2,int a_A[1]); /* checkimported */
static void a_1297(int a_F1,int a_A[1]); /* checksingletag */
static void a_1298(int a_F1); /* checksinglettag */
static void a_1299(int a_A[1]); /* checktagdefinition */
static void a_1300(int a_F1,int a_F2,int a_F3,int a_F4,int a_A[1]); /* createtagdefinition */
static void a_1301(int a_F1,int a_F2); /* doublydefinederror */
static int a_1302(int a_F1,int a_F2,int a_F3,int a_A[1]); /* finddefinitionabove */
static int a_1303(int a_F1,int a_F2,int a_F3,int a_A[1]); /* finddefinitionbelow */
static void a_1304(int a_F1,int a_F2,int a_A[1]); /* findttagdefinition */
static void a_1305(int a_F1,int a_A[1]); /* getmodulerank */
static void a_1306(int a_F1,int a_A[2]); /* getqfb */
static int a_1307(int a_F1,int a_F2); /* havesametype */
static int a_1308(int a_F1,int a_F2,int a_F3); /* isonlevel */
static int a_1309(int a_F1); /* isttagdefined */
static int a_1310(int a_F1,int a_F2,int a_F3,int a_A[1]); /* matchqtagabove */
static int a_1311(int a_F1,int a_F2,int a_F3,int a_A[1]); /* matchtagabove */
static int a_1312(int a_F1,int a_F2,int a_F3,int a_A[1]); /* matchtagbelow */
static void a_1313(int a_F1,int a_F2); /* pragmatttagdefinition */
static void a_1314(int a_F1); /* reclaimtag */
static void a_1315(int a_F1); /* unlinktag */
#define a_1317 (a_1237+sizeof_CHFILE) /* INPUT */
#define a_1318 (a_1317+sizeof_LIST) /* RANK */
static void a_1319(int a_F1,int a_A[1]); /* addcommandlinearg */
static void a_1320(int a_F1,int a_F2); /* addedge */
static void a_1321(int a_F1); /* addincludedsource */
static void a_1322(int a_F1,int a_F2,int a_F3); /* addinputentry */
static void a_1323(int a_F1); /* addlibrarysource */
static void a_1324(int a_F1,int a_F2,int a_F3); /* addnewrank */
static void a_1325(int a_F1); /* addrequiredsource */
static void a_1326(int a_F1); /* checksamemoduletag */
static void a_1327(void); /* checksourcemodules */
static void a_1328(int a_F1,int a_F2,int a_F3); /* correctrank */
static void a_1329(int a_F1,int a_F2,int a_F3); /* correctranksfrom */
static int a_1330(void); /* dopragmat */
static int a_1331(int a_F1,int a_F2); /* dosource */
static void a_1332(void); /* endline */
static void a_1333(int a_F1,int a_A[2]); /* findlinenum */
static void a_1334(int a_F1,int a_F2,int a_A[1]); /* findlocalrank */
static void a_1335(int a_F1,int a_F2,int a_A[1]); /* findrankabove */
static void a_1336(int a_F1,int a_A[1]); /* findsourcefromlineno */
static void a_1337(int a_A[1]); /* firstlineoffset */
static void a_1338(int a_F1,int a_A[1]); /* getbasefromlineno */
static void a_1339(int a_F1,int a_A[1]); /* getbasename */
static void a_1340(int a_A[1]); /* getfirstsource */
static void a_1341(int a_F1,int a_A[1]); /* getinputbase */
static void a_1342(int a_F1,int a_A[1]); /* getinputhead */
static void a_1343(int a_A[1]); /* getmoduletag */
static void a_1344(int a_A[1]); /* getsourcebase */
static void a_1345(void); /* initprogramargs */
static int a_1346=3; /* inputsize */
static int a_1347(int a_F1,int a_A[3]); /* iscmdlinepragmat */
static int a_1348(int a_F1); /* ishelpargument */
static int a_1349(int a_F1); /* isinputflag */
static int a_1350(int a_F1,int a_F2); /* isinputtype */
static int a_1351(int a_F1); /* isversionargument */
static void a_1352(int a_F1,int a_F2); /* modulewarning */
static void a_1353(int a_F1); /* movelibrarysource */
static int a_1354(int a_A[4]); /* nextinputentry */
static void a_1355(int a_F1); /* preparestandardlibrary */
static void a_1356(void); /* preparethissource */
static void a_1357(void); /* prepareuserlibraries */
static void a_1358(int a_F1); /* processsources */
static void a_1359(int a_F1); /* putmoduletag */
static void a_1360(void); /* readcommandlinearguments */
static void a_1361(void); /* readsources */
static void a_1362(void); /* readstandardlibrary */
static void a_1363(void); /* readuserlibraries */
static void a_1364(int a_F1); /* setsourcefromlineno */
static void a_1365(int a_F1); /* setsrcpragmats */
static int a_1366=0; /* sourcewarning */
static void a_1367(void); /* startline */
static int a_1368=0; /* stdliboffset */
static int a_1369=0; /* thisbase */
static int a_1370=0; /* thishead */
static int a_1371=0; /* thissource */
#define a_1373 (a_1318+sizeof_LIST) /* BOLD */
#define a_1374 (a_1373+sizeof_LIST) /* LEXT */
static int a_1375=0; /* LEXTcnt */
static int a_1376=0; /* LEXTlen */
static int a_1377=-1; /* LEXTptr */
#define a_1378 (a_1374+sizeof_LIST) /* SOURCE */
#define a_1379 (a_1378+sizeof_CHFILE) /* SPECIAL */
static int a_1380(int a_A[1]); /* boldletter */
static int a_1381=32; /* char */
static void a_1382(void); /* closesource */
static int a_1383(int a_A[1]); /* digit */
static void a_1384(int a_F1,int a_A[1]); /* enterstringtag */
static int a_1385=-4; /* exhausted */
static void a_1386(int a_F1); /* extendBUFFER */
static void a_1387(int a_F1); /* forgetstring */
static int a_1388=0; /* givetext */
static int a_1389(int a_A[1]); /* hexdigit */
static void a_1390(int a_F1); /* initializesourcereading */
static int a_1391(int a_F1); /* isletgitchar */
static int a_1392(int a_A[1]); /* letgit */
static void a_1393(void); /* longcomment */
static void a_1394(void); /* nextchar */
static void a_1395(void); /* nextvisiblechar */
static int a_1396(int a_F1,int a_F2); /* opensource */
static int a_1397=0; /* optor */
static int a_1398=0; /* pchar */
static int a_1399=0; /* ppline */
static void a_1400(int a_A[1]); /* read */
static void a_1401(int a_A[1]); /* readbold */
static void a_1402(int a_A[1]); /* readchardenotation */
static void a_1403(int a_F1,int a_A[1]); /* readconst */
static void a_1404(int a_F1,int a_A[1]); /* readgreater */
static void a_1405(int a_F1,int a_A[1]); /* readhex */
static void a_1406(int a_F1,int a_A[1]); /* readless */
static void a_1407(int a_A[1]); /* readmanifest */
static void a_1408(int a_A[1]); /* readminus */
static void a_1409(int a_A[1]); /* readminuswithspaces */
static void a_1410(int a_A[1]); /* readstring */
static void a_1411(int a_F1,int a_A[1]); /* readtag */
static void a_1412(int a_F1,int a_A[1]); /* readzero */
static int a_1413(void); /* shortcomment */
static void a_1414(int a_A[1]); /* skip */
static void a_1415(void); /* skipchardenotation */
static void a_1416(void); /* skipstring */
static void a_1417(int a_F1,int a_A[1]); /* stringfromtag */
static int a_1418=8; /* tabwidth */
static void a_1419(int a_F1,int a_A[1]); /* trytoopen */
static int a_1420(int a_F1); /* waslexicalpointer */
static int a_1421=0; /* wastab */
static void a_1423(void); /* createlistfiller */
static void a_1424(int a_A[1]); /* declaration */
static void a_1425(int a_F1,int a_F2); /* declarationseries */
static void a_1426(int a_F1,int a_F2,int a_F3,int a_F4); /* declarer */
static void a_1427(int a_F1,int a_F2,int a_F3,int a_F4); /* declarerbody */
static void a_1428(void); /* extendedblock */
static void a_1429(int a_F1); /* externaldeclarer */
static void a_1430(int a_A[1]); /* filleritem */
static void a_1431(void); /* findssel */
static void a_1432(int a_A[1]); /* getlisttag */
static void a_1433(void); /* initializer */
static int a_1434(void); /* isextendedblock */
static int a_1435=0; /* lcalibre */
static void a_1436(void); /* listfill */
static void a_1437(void); /* listfillblock */
static void a_1438(int a_F1); /* listprototype */
static int a_1439=0; /* lqf */
static int a_1440=0; /* lssel */
static int a_1441=0; /* ltag */
static int a_1442=0; /* ltype */
static void a_1443(int a_F1,int a_A[1]); /* prototypeorfill */
static void a_1444(int a_F1,int a_A[1]); /* prototypeorfillbody */
static void a_1445(int a_A[2]); /* readfieldlist */
static void a_1446(int a_A[2]); /* readfieldlists */
static void a_1447(int a_F1); /* repeatcount */
static int a_1448(int a_A[3]); /* sizeestimator */
static void a_1449(int a_F1); /* stackdeclaration */
static void a_1450(void); /* staticstackdeclaration */
static void a_1451(int a_F1); /* tabledeclaration */
static void a_1452(int a_A[1]); /* toselectors */
static int a_1455(int a_F1); /* declaration */
static void a_1456(void); /* externaldeclaration */
static void a_1457(void); /* firstpass */
static void a_1458(void); /* pass1 */
static void a_1459(void); /* root */
static int a_1460=0; /* rootscanned */
static void a_1461(void); /* staticdeclaration */
static void a_1463(void); /* addaleextension */
static void a_1464(void); /* createicename */
static void a_1465(int a_F1); /* extendBUFFER */
static int a_1466(int a_F1,int a_F2); /* opensrcfile */
static void a_1467(int a_F1,int a_A[1]); /* trybuffer */
static void a_1468(int a_F2,int a_A[2]); /* trynextpath */
static void a_1469(int a_F1,int a_F2,int a_A[1]); /* trytoopenwithpath */
static int a_1471(int a_A[1]); /* aheadrawtag */
static int a_1472=0; /* bounds */
static void a_1473(void); /* cmdlinepragmat */
static void a_1474(int a_F1,int a_F2); /* conspragmat2 */
static int a_1475=0; /* count */
static int a_1476=0; /* dicton */
static void a_1477(int a_F1,int a_F2); /* discpragmat */
static void a_1478(int a_F1,int a_F2); /* dopragmatskip */
static void a_1479(int a_F1,int a_F2,int a_A[1]); /* findifcondition */
static void a_1480(void); /* findmatchingendif */
static void a_1481(int a_F1,int a_A[1]); /* getpragmatvalue */
static int a_1482=0; /* givetext */
static int a_1483=0; /* icename */
static int a_1484=0; /* includepath */
static int a_1485=1; /* incompile */
static int a_1486=0; /* inlibrary */
static int a_1487=0; /* inmodule */
static void a_1488(int a_F1); /* insertsymbol */
static int a_1489(int a_F1); /* ispragmatvalue */
static int a_1490=0; /* librarypath */
static void a_1491(void); /* nextpragmatsymbol */
static void a_1492(int a_F1,int a_F3,int a_A[1]); /* onoffpragmats */
static int a_1493=0; /* pgmiftag */
static int a_1494=0; /* pgmskip */
static int a_1495=0; /* pgmstate */
static int a_1496=0; /* pgmtag */
static void a_1497(int a_F1); /* pragmatitem */
static void a_1498(int a_A[1]); /* programpragmat */
static void a_1499(int a_A[1]); /* programpragmat2 */
static void a_1500(int a_F1,int a_A[1]); /* programpragmatitem */
static void a_1501(int a_F1,int a_F2,int a_F3,int a_A[1]); /* programtagpragmat2 */
static int a_1502=0; /* programtitle */
static int a_1503=0; /* protolevel */
static void a_1504(void); /* resetpragmats */
static int a_1505=120; /* rightmargin */
static void a_1506(int a_F1,int a_F2); /* setmoduletag */
static void a_1507(int a_F1,int a_F2); /* setpragmatvalue */
static void a_1508(int a_F1,int a_F2); /* setprogramtitle */
static void a_1509(int a_F1,int a_F2); /* stringpragmat2 */
static int a_1510=8; /* tabwidth */
static void a_1511(int a_F1,int a_F2,int a_F3); /* tagpragmat2 */
static int a_1512=0; /* trace */
static int a_1513=1; /* usestdlib */
static int a_1514=10; /* warninglevel */
static void a_1516(int a_F1,int a_F2,int a_A[1]); /* checkformalaffixes */
static void a_1517(int a_F1,int a_F2,int a_F3,int a_F4,int a_A[1]); /* createruledefinition */
static void a_1518(int a_F1,int a_F2,int a_F3,int a_F4); /* externalrule */
static void a_1519(int a_F1,int a_A[1]); /* fieldlist */
static void a_1520(int a_F1); /* fieldlists */
static void a_1521(void); /* findlocalssel */
static void a_1522(int a_F1,int a_A[1]); /* formalatag */
static int a_1523=0; /* hasoutvararg */
static int a_1524=0; /* hasvararg */
static void a_1525(int a_F1); /* nextformalaffix */
static void a_1526(int a_F1,int a_A[1]); /* readformalaffixes */
static void a_1527(int a_F1,int a_F2); /* ruledeclaration */
static void a_1528(int a_F1,int a_F2,int a_F3,int a_F4); /* ruledeclarer */
static void a_1529(int a_F1,int a_F2,int a_F3,int a_F4); /* ruleprototype */
static void a_1530(int a_F1,int a_F2,int a_F3,int a_F4); /* simpleexternalrule */
static void a_1531(int a_F1,int a_F2,int a_F3,int a_F4); /* simpleruleprototype */
static void a_1532(int a_F1); /* subbus */
static void a_1534(int a_F1,int a_F2,int a_F3); /* Dqloc */
static void a_1535(int a_F1); /* addlocalaffix */
static void a_1536(void); /* addlocalaffixes */
static void a_1537(void); /* affixform */
static void a_1538(void); /* alternative */
static void a_1539(void); /* alternativeseries */
static int a_1540(void); /* anchoraffix */
static void a_1541(void); /* area */
static void a_1542(int a_A[1]); /* class */
static void a_1543(void); /* classification */
static void a_1544(int a_F1); /* closelocalrange */
static void a_1545(void); /* closelocalstack */
static void a_1546(void); /* compoundmember */
static int a_1547=0; /* emptyrule */
static void a_1548(int a_F1,int a_F2); /* extension */
static int a_1549=0; /* formalanchoraffix */
static void a_1550(int a_F1,int a_F2,int a_A[1]); /* getformalaffix */
static void a_1551(int a_A[1]); /* getruletag */
static void a_1552(int a_F1,int a_F2,int a_F3); /* indexsource */
static int a_1553(int a_A[3]); /* isqltag */
static void a_1554(int a_F1); /* listtag */
static int a_1555(void); /* lookingatamember */
static void a_1556(void); /* member */
static void a_1557(int a_F1); /* mustformallist */
static void a_1558(int a_F1,int a_A[1]); /* openlocalrange */
static void a_1559(int a_A[2]); /* peekaftersource */
static void a_1560(int a_A[1]); /* peeklabel */
static void a_1561(int a_F1); /* restorelocalrepr */
static void a_1562(void); /* rootbody */
static void a_1563(int a_F1); /* rulebody */
static void a_1564(int a_F1); /* rulepragmats */
static int a_1565=0; /* ruletag */
static void a_1566(int a_F1); /* searchjump */
static void a_1567(int a_F1,int a_F2,int a_F3); /* selector */
static void a_1568(int a_F1); /* setlocalrepr */
static void a_1569(int a_F1); /* setuplocalstack */
static void a_1570(int a_F1); /* skiplabel */
static void a_1571(void); /* skipoveranindex */
static void a_1572(void); /* skipoverdestination */
static void a_1573(int a_F1,int a_A[4]); /* skipoverextension */
static void a_1574(int a_A[1]); /* skipoversource */
static void a_1575(int a_F1); /* source */
static void a_1576(int a_F1); /* sourceorstring */
static void a_1577(int a_F1); /* specialaffixform */
static int a_1578(void); /* terminator */
static void a_1579(int a_F1,int a_F2); /* toselectors */
static void a_1581(void); /* affixform */
static void a_1582(void); /* alternative */
static void a_1583(int a_F1); /* checkconstanttype */
static void a_1584(int a_F1); /* checklisttype */
static void a_1585(int a_F1,int a_A[1]); /* checkprototype */
static void a_1586(int a_A[1]); /* checkruletype */
static void a_1587(int a_F1); /* checkstrictconstanttype */
static void a_1588(int a_F1); /* checktagformacro */
static void a_1589(void); /* class */
static void a_1590(void); /* compoundmember */
static void a_1591(void); /* exportprototype */
static void a_1592(void); /* exprbase */
static void a_1593(void); /* expression */
static void a_1594(void); /* extension */
static void a_1595(void); /* externaldeclarer */
static void a_1596(void); /* filearea */
static void a_1597(void); /* filedeclarer */
static void a_1598(int a_F1); /* filler */
static void a_1599(void); /* fillerblock1 */
static void a_1600(void); /* fillerblock2 */
static void a_1601(int a_F1); /* fillerinitializer */
static void a_1602(void); /* filleritem */
static void a_1603(void); /* fillerrepeater */
static void a_1604(void); /* importprototype */
static void a_1605(void); /* isexpression */
static int a_1606(int a_F1); /* islisttype */
static void a_1607(void); /* limitlist */
static void a_1608(void); /* listdeclarer */
static void a_1609(void); /* listfill */
static void a_1610(int a_F1); /* noexternal */
static void a_1611(void); /* pragmat */
static void a_1612(void); /* prototype */
static void a_1613(int a_F1,int a_F2); /* readlistselectors */
static void a_1614(void); /* readqtloc */
static void a_1615(int a_F1); /* ruledeclarer */
static void a_1616(int a_A[1]); /* ruleprototype */
static int a_1617=0; /* rulescanned */
static void a_1618(void); /* secondpass */
static void a_1619(int a_F1,int a_F2); /* selectorerror */
static void a_1620(void); /* setsource */
static void a_1621(void); /* source */
static void a_1622(void); /* toselector */
static void a_1623(void); /* toselectors */
static int a_1624(int a_F1,int a_F2); /* typemismatch */
static void a_1625(void); /* zone */
static void a_1627(void); /* ICEheader */
static void a_1628(void); /* ICEitemlist */
static void a_1629(int a_F1); /* defineiceitems */
static void a_1630(int a_F1); /* emitfill */
static void a_1631(void); /* exprbase */
static void a_1632(void); /* expression */
static void a_1633(int a_F1); /* extendBUFFER */
static void a_1634(void); /* externaldeclarer */
static void a_1635(void); /* fbmatter */
static void a_1636(void); /* filearea */
static void a_1637(void); /* filedata */
static void a_1638(int a_F1); /* fillerblock1 */
static void a_1639(int a_F1); /* fillerblock2 */
static void a_1640(int a_F1); /* filleritem */
static void a_1641(int a_F1); /* formalaffixes */
static void a_1642(int a_F1,int a_A[1]); /* getqualifier */
static void a_1643(int a_F1); /* handletag */
static void a_1644(void); /* initializer */
static void a_1645(void); /* isexpression */
static int a_1646(int a_F1); /* isitemtag */
static void a_1647(int a_F1); /* listdata */
static void a_1648(void); /* listdeclarer */
static void a_1649(void); /* listfilling */
static int a_1650=0; /* nextnitem */
static void a_1651(void); /* pass3 */
static void a_1652(void); /* pragmat */
static void a_1653(void); /* repeater */
static void a_1654(void); /* setsource */
static void a_1655(void); /* stringtablecontent */
static void a_1656(void); /* thirdpass */
static void a_1657(int a_F1,int a_F3,int a_A[1]); /* toselectors */
static void a_1658(int a_F1); /* traversestdstringpointers */
static void a_1659(int a_F1); /* traversetags */
static void a_1660(int a_F1); /* warnnotused */
static void a_1661(int a_F1); /* writeICEitem */
static void a_1663(void); /* fourthpass */
static void a_1664(void); /* pass4 */
static void a_1665(void); /* pragmat */
static void a_1666(void); /* setsource */
#define a_1668 (a_1379+sizeof_LIST) /* TMPSEL */
static void a_1669(int a_F1,int a_F2,int a_F3,int a_F4); /* addlistselector */
static void a_1670(int a_F1,int a_F2,int a_F3); /* createlistextension */
static void a_1671(int a_F1,int a_F2,int a_F3,int a_A[1]); /* createselectorblock */
static void a_1672(int a_F1,int a_F2); /* dumptempselectors */
static int a_1673(int a_F1,int a_F2,int a_F3); /* entertempselector */
static int a_1674(int a_F1,int a_F2,int a_A[1]); /* findlistselector */
static int a_1675(int a_F1,int a_F2,int a_A[1]); /* findpermselector */
static int a_1676(int a_F1,int a_F2,int a_A[1]); /* findtempselector */
static void a_1677(int a_F1,int a_A[1]); /* getcalibre */
static void a_1678(int a_F1,int a_A[1]); /* getselectornext */
static void a_1679(int a_F1,int a_A[1]); /* getselectoroffs */
static void a_1680(int a_F1,int a_A[1]); /* getssel */
static void a_1681(void); /* resettempselectorstack */
#define a_1683 (a_1668+sizeof_LIST) /* RESTORE */
static void a_1684(int a_F1); /* Rskip */
static void a_1685(void); /* advancelinenum */
static int a_1686(void); /* aheadnumber */
static void a_1687(int a_A[1]); /* countrestore */
static int a_1688=0; /* dorestore */
static void a_1689(void); /* forgetrestore */
static void a_1690(int a_A[1]); /* getlinenum */
static void a_1691(void); /* initrestore */
static int a_1692=0; /* inpt */
static int a_1693=16777337; /* inrestore */
static int a_1694(int a_A[2]); /* isnumber */
static int a_1695(int a_A[2]); /* isqtag */
static int a_1696(int a_A[1]); /* israwttag */
static int a_1697(int a_A[1]); /* isstring */
static int a_1698(int a_A[1]); /* isttag */
static int a_1699=0; /* linenum */
static void a_1700(void); /* makerestore */
static void a_1701(int a_F1); /* must */
static void a_1702(void); /* nextsymbol */
static int a_1703=0; /* oldinpt */
static int a_1704=0; /* oldlinenum */
static int a_1705=0; /* oldrestore */
static int a_1706=16777337; /* outrestore */
static int a_1707(void); /* readfromrestore */
static int a_1708=0; /* restorecount */
static void a_1709(void); /* savetorestore */
static void a_1710(int a_F1); /* setlinenum */
static void a_1711(void); /* setsymbolposition */
static void a_1712(void); /* skipall */
static void a_1713(void); /* skipsilently */
static void a_1714(void); /* skipsymbol */
static void a_1715(void); /* skiptopoint */
static void a_1716(void); /* switchsource */
#define a_1718 (a_1683+sizeof_LIST) /* LADM */
#define a_1719 (a_1718+sizeof_LIST) /* LLOC */
#define a_1720 (a_1719+sizeof_LIST) /* TTAG */
static void a_1721(int a_F1,int a_F2); /* addpragmatmatter */
static void a_1722(int a_F1,int a_F2); /* cleartagflag */
static int a_1723(int a_F1,int a_F2); /* compareAFFS */
static void a_1724(int a_F1,int a_F2); /* createlocalaffix */
static void a_1725(int a_A[1]); /* enterformalaffixes */
static void a_1726(int a_F1); /* enterpredefinedtag */
static void a_1727(int a_F1,int a_A[1]); /* entertag */
static void a_1728(int a_F1); /* extendBUFFER */
static void a_1729(int a_F1,int a_A[1]); /* getadm */
static void a_1730(int a_F1,int a_A[1]); /* getdefline */
static void a_1731(int a_F1,int a_A[1]); /* getformalaffixno */
static void a_1732(int a_F1,int a_F2,int a_A[2]); /* getformallistext */
static void a_1733(int a_F1,int a_F2,int a_A[1]); /* getformaltype */
static int a_1734(int a_A[3]); /* getnextmatter */
static void a_1735(int a_F1,int a_A[1]); /* getnexttag */
static void a_1736(int a_F1,int a_A[1]); /* getrepr */
static void a_1737(int a_A[1]); /* getstdstringhead */
static void a_1738(int a_F1,int a_F2,int a_A[1]); /* gettagflag */
static void a_1739(int a_F1,int a_A[1]); /* getttag */
static void a_1740(int a_A[1]); /* getttaghead */
static void a_1741(int a_F1,int a_A[1]); /* gettype */
static void a_1742(void); /* inittags */
static void a_1743(int a_F2,int a_A[1]); /* inserttoAFFS */
static int a_1744(int a_F1,int a_A[1]); /* isspecialrule */
static int a_1745(int a_F1,int a_A[1]); /* isstdstringstored */
static int a_1746(int a_F1,int a_F2); /* istagflag */
static void a_1747(int a_F1,int a_F2,int a_F3); /* linkmacrorule */
static int a_1748=0; /* macroptr */
static int a_1749=0; /* matters */
static void a_1750(int a_F1,int a_F2,int a_A[1]); /* newstdstring */
static int a_1751(int a_A[1]); /* nextmacrorule */
static void a_1752(int a_F1); /* pushAFFS */
static void a_1753(int a_F1,int a_F2); /* putadm */
static void a_1754(int a_F1,int a_F2); /* putdefline */
static void a_1755(int a_F1,int a_F2); /* putrepr */
static void a_1756(int a_F1,int a_A[2]); /* searchmacrorule */
static void a_1757(int a_F1,int a_F2); /* settagflag */
static void a_1758(int a_F1); /* usetag */
static int a_1759(int a_F1); /* wastagpointer */
#define a_1761 (a_1720+sizeof_LIST) /* INDICATOR */
static int a_1762(int a_F1); /* wastypepointer */
static void a_1764(int a_F1); /* constantdeclaration */
static void a_1765(int a_A[1]); /* declaration */
static void a_1766(int a_F1); /* declarationseries */
static void a_1767(int a_F1); /* declarer */
static void a_1768(void); /* expectexpression */
static void a_1769(int a_A[1]); /* expectlisttag */
static int a_1770(int a_A[1]); /* exprbase */
static void a_1771(int a_F1); /* externaldeclarer */
static int a_1772(int a_A[1]); /* isexpression */
static int a_1773=0; /* lqf */
static int a_1774=0; /* ltag */
static int a_1775=0; /* ltype */
static void a_1776(int a_F1); /* prototype */
static void a_1777(void); /* staticvariabledeclaration */
static void a_1778(int a_F1); /* variabledeclaration */
static void a_1780(void); /* Bback */
static int a_1781(int a_F1,int a_A[1]); /* Bdata */
static void a_1782(int a_A[1]); /* Bgetptr */
static void a_1783(int a_F1); /* Bsetdata */
static void a_1784(int a_F1); /* Bsetflag */
static int a_1785=0; /* C1 */
static int a_1786=0; /* C2 */
static int a_1787=0; /* C3 */
static void a_1788(int a_F1); /* DUalternative */
static int a_1789(int a_F1); /* DUmember */
static void a_1790(int a_F1); /* DUregion */
static int a_1791(int a_F1); /* DUrule */
static void a_1792(void); /* Lfindlabels */
static void a_1793(int a_F1,int a_F2,int a_A[1]); /* Lscani */
static void a_1794(void); /* Lscanii */
static void a_1795(int a_F1); /* Lunroll */
static int a_1796=0; /* RULEtop */
static int a_1797(int a_F1,int a_F2); /* Uactualrule */
static void a_1798(int a_F1); /* Ualternative */
static int a_1799=0; /* Ufinalchanged */
static int a_1800(int a_F1,int a_F2); /* Umember */
static int a_1801=0; /* Uptr */
static void a_1802(int a_F1); /* Uregion */
static int a_1803=3; /* addRULEflag */
static void a_1804(void); /* assignnodes */
static void a_1805(int a_F1,int a_F2,int a_F3); /* clearRULEflag */
static void a_1806(int a_F1); /* closerange */
static void a_1807(void); /* computeDUflags */
static void a_1808(int a_F1,int a_F2,int a_F3); /* copyUf1toUf2 */
static void a_1809(int a_F1,int a_F2); /* copyjumpUf */
static void a_1810(int a_F1,int a_A[1]); /* copyspareaffix */
static void a_1811(int a_F1,int a_A[1]); /* correctselector */
static void a_1812(void); /* diagnoseformals */
static void a_1813(int a_F1,int a_F2,int a_F3); /* diagnoselocal */
static void a_1814(int a_F1,int a_F2); /* diagnoseoutaffix */
static void a_1815(int a_F1); /* diagnoserule */
static int a_1816=0; /* expandflag */
static void a_1817(int a_F1); /* expandmacro */
static void a_1818(int a_F1); /* extendBUFFER */
static void a_1819(int a_F1,int a_F2); /* extendRULE */
static void a_1820(int a_F1,int a_F2,int a_A[1]); /* finalssel */
static void a_1821(int a_F1); /* gactualrule */
static void a_1822(void); /* galtsequence */
static void a_1823(void); /* galttail */
static void a_1824(int a_A[1]); /* garea */
static void a_1825(void); /* gclassification */
static void a_1826(void); /* gcompound */
static void a_1827(int a_F1); /* generaterule */
static void a_1828(void); /* gextension */
static void a_1829(int a_F1,int a_F2); /* ghandleaffix */
static void a_1830(int a_F1); /* ghandleshiftrule */
static void a_1831(int a_F1,int a_F2,int a_F3,int a_F4); /* ghandlevarargblock */
static int a_1832(void); /* glimit */
static void a_1833(int a_F1,int a_A[1]); /* gmatchformalactual */
static void a_1834(void); /* gmember */
static void a_1835(void); /* greadbox */
static void a_1836(void); /* grulebody */
static void a_1837(int a_F1,int a_A[1]); /* gsimpleaffix */
static void a_1838(void); /* gtransportlist */
static int a_1839(int a_F1); /* inutype */
static int a_1840=0; /* maxlocal */
static void a_1841(int a_F1,int a_F2); /* mergeDUflags */
static void a_1842(int a_F1,int a_F2,int a_F3); /* mergeUf1toUf2 */
static int a_1843=0; /* minlocal */
static int a_1844=0; /* nodecount */
static int a_1845(int a_F1); /* oututype */
static void a_1846(int a_C,int *a_V); /* pushBUFFER */
static void a_1847(int a_F1,int a_F2); /* pushRULE */
static void a_1848(int a_F1,int a_F2); /* recoverflagsfromregion */
static int a_1849=0; /* rulecalled */
static int a_1850=0; /* rulecompiled */
static void a_1851(int a_F1,int a_F2,int a_F3); /* setRULEflag */
static void a_1852(int a_F1,int a_F2,int a_F3); /* setflagsforregion */
static void a_1853(int a_F1); /* setflagsforrule */
static void a_1854(int a_F1); /* setupformalstack */
static void a_1855(int a_A[1]); /* setuplabel */
static void a_1856(void); /* setuplocals */
static void a_1857(int a_F1,int a_A[1]); /* startrange */
static void a_1858(int a_F1); /* traverseRULE */
static void a_1859(int a_F1,int a_A[1]); /* utypetoslice */
static void a_1860(int a_F1); /* wactualrule */
static void a_1861(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5); /* wafteraffixes */
static void a_1862(int a_F1); /* waftershiftrule */
static void a_1863(int a_F1,int a_F2,int a_F3,int a_F4); /* waftervarargblock */
static void a_1864(void); /* waltsequence */
static void a_1865(void); /* walttail */
static void a_1866(int a_F1); /* warea */
static void a_1867(int a_F1); /* wbeforeshiftrule */
static void a_1868(int a_F1,int a_F2,int a_F3,int a_F4); /* wbeforevarargblock */
static void a_1869(void); /* wclassification */
static void a_1870(void); /* wcompound */
static void a_1871(int a_A[1]); /* wcopyaffixfromBUFFER */
static void a_1872(void); /* wextension */
static void a_1873(int a_F1); /* whandleaffix */
static void a_1874(int a_F1); /* wlabel */
static int a_1875(int a_A[1]); /* wlimit */
static void a_1876(int a_F1,int a_A[1]); /* wmatchformalactual */
static void a_1877(void); /* wmember */
static void a_1878(void); /* wreadbox */
static void a_1879(void); /* wrulebody */
static void a_1880(int a_F1,int a_A[1]); /* wsimpleaffix */
static void a_1881(int a_F1,int a_A[1]); /* wtransportlist */
static void a_1884(int a_F1,int a_F2,int a_F3); /* putasstring */
static void a_1886(int a_F1,int a_F2,int a_F3); /* putstring */
#define a_1889 (a_1761+sizeof_LIST) /* STDARG */
static void a_1717(void); /* tags root */
static void a_1453(void); /* @main root */
static void a_1290(void); /* identifier root */
static void a_1135(void); /* arithmetic root */
static void a_1112(void); /* number root */
#define BLOCK_TOTAL (a_1889+sizeof_LIST)
int a_DATABLOCK[BLOCK_TOTAL];
static int a_FILL[]={ /* fill table */
a_1001,/* @StringTable */
7,1668571501,1919903336,1634492781,1635087459,108,17,7,0,
a_1236,/* MESSAGE */
32,1701606770,980428064,1919903264,543973741,544503151,1768318561,1881481336,1935767328,1953459744,1952805664,0,40,13,1701606770,980428064,544173600,1684956528,543649385,1701864818,1629516897,2020173414,29541,34,11,1700946284,1881481324,1852383290,1768843622,1814062452,7368559,23,8,0,
a_1236,/* MESSAGE */
53,10789,2,3,1702131813,1869181806,1718558830,980428064,32,17,7,1701606770,980428064,32,9,5,1919115629,1881481327,8250,10,5,1881500965,544220448,1953723757,543515168,1635000417,543517794,1931506287,1801675124,0,32,11,1869507877,1635021600,1918985326,1702043748,1952671084,1713402479,622883439,1881481328,0,32,11,1853189413,1768318308,543450478,1701602675,1919906915,544220448,622880367,1881481328,0,32,11,0,
a_1236,/* MESSAGE */
147,1717660965,544762214,1701869940,1920099616,29295,18,7,623013157,1746936432,1998615393,1735290738,1887007776,1881481317,0,24,9,623013157,1965040240,1768843630,1818323316,1684372073,0,20,8,1717660965,544762214,543434019,1852727651,1646294127,543236197,1936617315,1953390964,0,32,11,1768713509,544500077,1752459639,1881481760,1633886242,1953459822,543515168,1684370293,0,32,11,1881500965,544220448,544432488,1868787305,1952542829,1701601897,1887007776,623386725,10604,34,11,1969515813,544828781,1768318561,1633886328,1953459822,543515168,1684370293,1919248416,101,33,11,623013157,1830822512,1700952417,1869772576,1763731310,2019910766,0,24,9,1717660965,544762214,577774882,1935763488,1818321696,1701995113,1718182944,1701995878,1713402990,544042866,25637,42,13,1953721637,1633971809,1931502706,1667591269,544370548,572548719,539127845,1679848297,1701209705,1953391986,0,40,13,1701606770,980428064,1701344288,1935764512,1667309684,1818326388,1717985568,1830844521,544502645,1075864930,0,40,13,1701606770,980428064,1851876128,544501614,1768189805,1763735910,1717641326,544762214,1763733541,543236206,1919115629,1970413679,25964,50,15,1701606770,980428064,1851876128,544501614,1768189805,1763735910,1717641326,544762214,1763733541,1635131502,1650551154,1646290284,1801678700,0,52,16,0,
a_1236,/* MESSAGE */
78,1701606770,980428064,1885696544,544498021,1668246626,1769152619,1830839674,1634562921,543712116,694953256,0,40,13,1701606770,980428064,1885696544,544498021,1668246626,2037653611,1830839664,1634562921,543712116,544370534,1629515813,2020173414,745547040,1986619168,540700261,673214501,2714661,67,19,1701606770,980428064,1830838560,1869767521,1819636256,1633886309,1953459822,1818321696,1953046636,1718379891,0,40,13,1634541665,544174691,1701606770,1851876128,544501614,1819042147,1881481760,34,29,10,1701606770,980428064,1684300064,1869182057,543973742,1970561889,1629514849,2020173414,1814374432,41,37,12,1701606770,980428064,1936289056,1735289203,1952669984,543973749,1768318561,623386744,10604,34,11,0,
a_1236,/* MESSAGE */
52,1702131813,1869181806,1881481326,1970085946,1646294131,543236197,1667331187,623386731,10608,34,11,1702131813,1869181806,1881481326,1768300602,543452261,543434019,1768318308,543450478,1667856244,101,37,12,1702131813,1869181806,1881481326,1869488186,1868767348,1667593070,1986622581,1768300645,1936483429,0,36,12,1702131813,1869181806,1881481326,1818370106,543908719,1702521203,543434016,1931506537,1819042157,1948283493,544104808,1768710499,543519330,694428968,0,56,17,0,
a_1236,/* MESSAGE */
34,540700709,1696624494,1919251576,543973742,1936617315,1953390964,544370464,1953720684,544106784,1701736314,0,40,13,540700709,544432488,1852797559,2037653607,622880112,1852383344,1852799520,623386725,10604,34,11,1852727651,1914729583,1751343461,1768453152,1818304627,1852990836,1986622561,101,29,10,0,
a_1236,/* MESSAGE */
17,1852727651,1914729583,1751343461,1768453152,1701650547,1919246957,0,24,9,1852797559,1969889383,1948282989,1634476143,543974754,28709,22,8,0,
a_1236,/* MESSAGE */
16,1633906540,1717641324,544762214,540700709,544501614,1684370293,0,24,9,1700946284,1881481324,1869488186,1937055860,25701,18,7,0,
a_1236,/* MESSAGE */
213,1953460082,1633886266,1953459822,543515168,1953525093,121,21,8,1953460082,1701716026,544367990,1970562418,7564914,19,7,1701606770,980428064,1769497888,1970413684,1663067500,1914728033,1920300133,110,29,10,1701606770,980428064,1851876128,544501614,1667462515,6579557,23,8,1701606770,980428064,1851876128,1767990816,108,17,7,1701606770,980428064,1851876128,544501614,1818845542,0,20,8,1701606770,980428064,1935763488,1869375264,543973730,1701079411,1717986592,7627621,31,10,1701606770,980428064,1935763488,1886217504,1646295412,7955567,23,8,1701606770,980428064,1935763488,544173600,1651469415,1931504737,543515753,1701209701,29795,34,11,1701606770,980428064,1818321696,1629516652,2019893358,1914729577,6646901,27,9,1701606770,980428064,1851876128,1986095136,1818697829,1818321519,1684632352,1717903461,1952671078,1701345056,1634082926,7564393,47,14,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1953459744,1702065440,100,33,11,1701606770,980428064,1953459744,1819042080,1885696544,544498021,1668246626,1830843243,1952999273,543515168,1769171318,6579572,47,14,1701606770,980428064,1919903264,543973741,1667331187,1717641323,544762214,1663070245,1646292577,543236197,1818386804,101,45,14,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1734962464,1663071336,1735287144,1852776549,1970435104,2019893349,29801,50,15,1701606770,980428064,1953853216,1919903264,543973741,1768318561,1881481336,1851876128,543515168,1852403317,1634301033,1702521196,100,49,15,1701606770,980428064,1953853216,1919903264,543973741,1768318561,1852383352,1885696544,544498021,1668246626,1853169771,1953066601,1768710505,6579578,55,16,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1701798944,1869488243,1751326836,1701277281,0,40,13,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1734962464,1663071336,1735287144,1852776549,1818322464,1696621939,7629176,51,15,0,
a_1001,/* @StringTable */
24,1935762007,101,5,4,1953719895,114,5,4,1920234327,6778473,7,4,1734440023,0,4,4,87,1,3,1885695073,1667837544,101,9,5,0,
a_1236,/* MESSAGE */
28,1852727651,1864397935,544105840,543515497,1701603686,745547040,1920099616,1663070831,979723375,744760608,1868718368,1852404850,103,49,15,1128865828,1768300613,539780460,1685025392,1684366197,544825888,1346718785,1868767304,1818849389,1981837925,0,40,13,0,
a_1236,/* MESSAGE */
12,1701606770,980428064,1651406112,1684960623,1830839397,1869767521,1651864352,1953068147,1869182069,110,37,12,0,
a_1001,/* @StringTable */
15,1953067617,1952804200,25449,10,5,1752458599,1768192101,7629159,11,5,1685349735,1953064809,0,8,5,0,
a_1236,/* MESSAGE */
22,1702129257,544367975,1869505892,1769234804,1763733103,1970217075,1718558836,1851879968,25959,34,11,1702129257,544367975,1970037110,1680154725,544434464,544503151,1914725999,1701277281,0,32,11,0,
a_1001,/* @StringTable */
9,1953067617,1952804200,25449,10,5,1886611812,7954796,7,4,0,
a_1374,/* LEXT */
25,1886221359,1701601583,1479370864,1482184792,88,17,7,1818308398,979923045,1920169263,1668246575,1630497889,1752196460,0,24,9,1818522739,1630429801,25964,10,5,1885695073,104,5,4,0,
a_1236,/* MESSAGE */
275,1886220099,543517801,1346718785,541928776,1920298867,1713399139,1936026729,544175136,773877345,543515497,1701603686,1433281838,1701273971,1667309626,544238959,1747791195,544238693,1982672252,1769173605,626880111,538976366,540701295,1836016481,1868243056,1869182064,542995310,1701603686,774778400,1886346016,1852795252,1713397107,627403881,1869367150,543973730,1769238639,544435823,1701998632,1970235766,1769152627,1634494829,1886330994,1852795252,544434464,1819305330,1684366177,1847933481,1865228320,1768307744,540960108,538976288,1864376352,1970304117,1764630644,1713399139,627403881,757080174,1681662025,624849513,1768176739,538984050,1936288800,1718558836,1634038560,543712114,1701996900,1919906915,544433513,1885696808,1952543329,1646290021,1663377529,544089385,541863200,1919509564,538976318,538976288,1953701920,1651076196,1919509536,1869898597,1847949682,1633906508,1886330988,1852795252,1915232371,1952805733,1952866592,1696625253,543712097,1920298867,1713399139,694512745,544089402,542584096,538976288,538976288,538976288,1635196960,1852403314,1701584999,1030514038,1847944229,1462575136,543976545,538976288,538976288,1998594080,1768845921,1814062958,1818588773,1847930941,1814896672,538976288,538976288,538976288,1814044704,1031041897,1847946863,1680678944,538976288,538976288,538976288,1679826976,1769235305,1918987887,1852783993,1951362597,544367976,1769238639,980643439,538996261,1008747565,1046962548,538976288,538976288,1717920800,1030057577,1734439996,544089406,544025888,1818846780,538984037,538976288,1701978144,1919513969,1008876901,1701603686,1847927358,2033000480,1768307744,540960108,538976288,1814044704,1634886249,574454130,1818846780,623001189,757080174,2021161005,2050848888,538999418,538976288,1936875888,1629512805,1881612403,1835491698,2015851617,2021161080,2054847037,1231955246,1869488230,1953853216,544503152,1931506537,1768121712,1684367718,1752440876,1634607205,1864394093,1752440934,1764630629,1713399139,543517801,1679848297,1986622053,1713398885,627928946,1701344366,1919510048,1931506803,1668445551,1768300645,1629513068,1730176110,1919250021,1684370529,544106784,543516788,1920103779,544501349,1701996900,1919906915,11897,810,205,1346718785,541928776,1226862452,1663059267,1819307375,544367977,1936876918,544108393,623797285,1131292004,1920561263,1952999273,692267040,842019360,808594736,1277178930,1819964257,1933779055,1634562665,1416504698,544434536,1629516649,1701996064,1869815909,1635218534,539780466,543516019,543516788,1920298867,1629513059,1952981108,980643956,1768369967,1651861620,1836016430,1935895599,1634562665,1818308474,627601509,1919903342,1886348064,1734963833,1763734632,1919903342,1769234797,539913839,1919248468,1936269413,542068256,1381122391,1498697281,1869488187,1986338932,1830841957,1751347813,1769238113,1768712546,1864399220,1718494578,1701737577,1713402739,1629516399,1918988320,1969449332,544366956,1886549360,778400623,0,268,70,0,
a_1001,/* @StringTable */
94,1668571501,1919903336,1634492781,1635087459,108,17,7,1835627366,1634036848,2020173414,0,12,6,1684104562,1701602675,1919906915,0,12,6,1953723757,1887007825,101,9,5,1953723757,1635021137,103,9,5,1953723757,1635021905,103,9,5,1953723757,1734440017,0,8,5,1953723757,1852793681,115,9,5,1953723757,81,5,4,1953719666,1684370031,1885565801,1953067887,7237481,19,7,1702257011,1668508004,1769172848,1852795252,0,16,7,1734440004,0,4,4,1635021892,103,5,4,1920234308,6778473,7,4,68,1,3,1852141679,1936287860,1668508004,0,12,6,1852141679,1668508004,0,8,5,1886221359,1701601583,1949198448,28781,14,6,0,
a_1157,/* DSYMB */
203,28197,2,3,1847946789,0,4,4,64,1,3,38,1,3,1701994791,10081,6,4,1667326503,10091,6,4,2020565543,39,5,4,93,1,3,1818321703,1701995113,39,9,5,126,1,3,41,1,3,58,1,3,1852793639,2585715,7,4,44,1,3,47,1,3,1684956455,39,5,4,1886938407,661942895,0,8,5,1886938407,1936942450,661548905,0,12,6,1954047271,1769172581,2584175,11,5,1954047271,1634628197,10092,10,5,1818846759,10085,6,4,1818846759,10092,6,4,1869768231,2585710,7,4,1886218535,661942895,0,8,5,1836411431,10096,6,4,1650551847,2583653,7,4,1936288807,10100,6,4,1668246567,2583649,7,4,1651993639,39,5,4,1767992615,10094,6,4,45,1,3,1685024039,660958325,0,8,5,8227,2,3,1685024295,10085,6,4,40,1,3,124,1,3,62,1,3,43,1,3,46,1,3,1634889767,1952542055,39,9,5,1869770791,2584436,7,4,1635086631,1768319340,2585189,11,5,1869574695,10100,6,4,1819636263,10085,6,4,59,1,3,1970238247,660956018,0,8,5,42,1,3,91,1,3,661615655,0,4,4,1651537191,39,5,4,2003596839,10082,6,4,1886746151,10082,6,4,94,1,3,0,
a_1236,/* MESSAGE */
45,1852727651,1663071343,1952540018,1702109285,1713401965,543517801,539783205,1869771365,1868767346,624780644,1629498468,1953656674,6778473,51,15,1852141679,1936286752,1919230051,745697138,1030712864,539780133,1701080941,744695101,1818846752,1881488741,1650532396,1769239151,26478,50,15,1931505518,1684955508,543453793,1701602675,1919906915,1919903264,544220448,1830841961,1869767521,1651864352,1953068147,1869182069,110,49,15,0,
a_1001,/* @StringTable */
51,774778459,93,5,4,1564437851,0,4,4,1564438875,0,4,4,14906,2,3,1564438619,0,4,4,1564437595,0,4,4,1564435291,0,4,4,2003136060,1701734764,62,9,5,1564435547,0,4,4,93,1,3,16219,2,3,1280659035,23884,6,4,1953709116,1953853284,15934,10,5,0,
a_1236,/* MESSAGE */
41,544173940,2037277037,1920099616,745763439,1920296480,1919248500,1936026912,1701273971,1918967923,1970479205,1701998704,1684370291,0,48,15,1702129257,1818324594,1920099616,1763734127,1970413678,622880108,544089456,707403808,539634218,1634036816,1914725747,1919905893,1752440948,1718558821,1684956518,543649385,1735357040,544039282,543452769,543516788,1869771365,706752114,707406378,28197,94,26,0,
a_1236,/* MESSAGE */
62,1702131813,1818324594,544220448,540700709,1936943469,543649385,1769108595,26478,30,10,1769498989,622880622,1701060720,1918987363,1869182049,1851859054,1919950948,1953461359,6647929,35,11,622882853,1830828656,1769173865,1713399662,543517801,1769108595,26478,26,9,622882853,1948269168,1763731297,2019893363,1952671088,1763730533,1768300654,1629513068,6382962,35,11,622882853,1814051440,1701278305,1952539680,1818846817,1918967909,673210725,544760173,2712613,35,11,1679847461,1634493285,1769234802,540700271,543646068,1701869669,1684370531,0,28,10,0,
a_1001,/* @StringTable */
5,1768713845,1635019630,103,9,5,0,
a_1236,/* MESSAGE */
16,540700709,1852727651,1646294127,1701978213,1768318308,6579566,23,8,540700709,544432503,1768318308,543450478,622883937,108,21,8,0,
a_1236,/* MESSAGE */
20,543646068,1881501989,1819634976,1819306356,1701060729,1701734758,623386724,1851859052,1814372452,41,37,12,543646068,1881501989,1953459744,1717920800,1684369001,0,20,8,0,
a_1001,/* @StringTable */
53,1702243629,1869181810,110,9,5,1701326125,28780,6,4,19501,2,3,18733,2,3,28461,2,3,31021,2,3,27949,2,3,17453,2,3,1818318637,108,5,4,22317,2,3,27693,2,3,25645,2,3,1651795303,1852142433,6647137,11,5,1684957542,1920298867,1919313251,1768713583,1869505902,0,20,8,0,
a_1236,/* MESSAGE */
47,1769496941,544044397,1651340654,1864397413,1869815910,1701016181,623386739,1696606564,1701143416,6579556,39,12,1936943469,543649385,1969713761,1953391981,1919903264,1663066400,1768711277,1864394094,1869182064,110,37,12,1763733358,1953853550,544434464,1667592307,1701406313,1965042788,757097843,1818585133,1868963952,543236210,1919903859,1701322868,28780,50,15,1869771365,1886330994,1852403301,1768300647,572548460,2256933,23,8,0,
a_1317,/* INPUT */
21,1,0,1178737320,0,-1,-1,0,2,0,1178737327,0,-1,-1,0,3,0,1178737334,0,-1,-1,0,0,
a_1236,/* MESSAGE */
35,1701603686,980428064,1936289056,1735289203,1685024032,543517813,1734439536,7627117,31,10,1701603686,1881481331,1684955424,544220448,1768318308,1948280174,1931502952,543518049,1969516397,656434540,2584613,43,13,1969516397,656434540,539455525,1629516649,544174956,1768318308,543450478,1713401449,543517801,28709,38,12,0,
a_1001,/* @StringTable */
5,1953709116,1047423332,62,9,5,0,
a_1374,/* LEXT */
3,0,0,3,0,
a_1379,/* SPECIAL */
169,1836409916,4094317,7,4,1684956455,39,5,4,1952669991,661548905,0,8,5,1853187623,1869182051,10094,10,5,1701998631,1633904996,2581876,11,5,1702195495,1869182067,10094,10,5,1769497895,10100,6,4,1869574695,10100,6,4,1954047271,1634628197,10092,10,5,1635021607,660826484,0,8,5,1634231079,1818846834,10085,10,5,1952539687,1818846817,10085,10,5,1852793639,1851880563,10100,10,5,1918989863,1818386793,10085,10,5,1650553895,2581868,7,4,1635021607,2583395,7,4,1634889767,1952542055,39,9,5,15917,2,3,61,1,3,60,1,3,62,1,3,15420,2,3,15934,2,3,91,1,3,93,1,3,64,1,3,35,1,3,15932,2,3,42,1,3,40,1,3,41,1,3,58,1,3,14906,2,3,44,1,3,59,1,3,46,1,3,45,1,3,43,1,3,15649,2,3,47,1,3,15678,2,3,15676,2,3,126,1,3,124,1,3,38,1,3,94,1,3,28252,2,3,0,
a_1236,/* MESSAGE */
77,544761192,1768384868,2019893364,1952671088,1629512805,1919251558,7876640,27,9,1852797559,1751326823,1667330657,544367988,1869505892,1769234804,28271,26,9,1769496941,543973741,1769108595,1814062958,1952935525,2019893352,1684366691,25701,30,10,1702129269,1852403058,1684370529,1920234272,6778473,19,7,1852534389,544110447,544826731,1685221239,1881483040,39,21,8,1852534389,544110447,1768841581,1953719654,2036689696,1685221239,7349536,27,9,1936943469,543649385,1717641255,544367988,661660967,0,20,8,544501614,1763733089,1953391972,1701406313,1717641330,544367988,17453,26,9,1701604457,543973735,1918986339,1702126433,622869106,99,21,8,0,
a_1373,/* BOLD */
256,97,1,3,0,0,1164737653,7627617,3,3,1164737384,1164737397,1164737653,1769235297,28271,6,4,0,0,1164737653,1918986339,1701603686,0,8,5,1164737390,1164737420,1164737691,1936617315,0,4,4,0,0,1164737701,1936617315,1953390964,0,8,5,1164737412,1164737426,1164737701,7631715,3,3,0,0,1164737701,1635017060,1701603686,0,8,5,1164737405,1164737461,1164737696,101,1,3,0,0,1164737672,6581861,3,3,1164737440,1164737453,1164737648,1953069157,0,4,4,0,0,1164737672,1702131813,1818324594,0,8,5,1164737446,1164737473,1164737681,102,1,3,0,0,1164737658,7627622,3,3,1164737467,1164737480,1164737658,1668183398,0,4,4,0,0,1164737658,1668183398,1852795252,0,8,5,1164737434,1164737542,1164737658,112,1,3,0,0,1164737663,1734439536,7627117,7,4,1164737494,1164737508,1164737719,1684370032,0,4,4,0,0,1164737663,1684370032,1952539497,101,9,5,1164737501,1164737528,1164737663,113,1,3,0,0,1164737668,30065,2,3,1164737522,1164737534,1164737668,6649201,3,3,0,0,1164737668,1936029041,1852795252,0,8,5,1164737516,1164737570,1164737668,1953460082,0,4,4,0,0,1164737676,1667331187,107,5,4,1164737549,1164737563,1164737714,1952543859,25449,6,4,0,0,1164737686,1818386804,101,5,4,1164737556,1164737584,1164737710,7496054,3,3,0,0,1164737706,1769103734,1701601889,0,8,5,1164737576,1164737590,1164737706,120,1,3,0,0,1164737681,1818846815,24421,6,4,0,0,1,1852402783,24421,6,4,1164737597,1164737612,2,1685024095,1600482421,0,8,5,0,0,3,1819636319,24421,6,4,1164737604,1164737627,4,1970238303,1600480114,0,8,5,0,1164737634,5,1953068127,6251884,7,4,0,0,6,0,
a_1236,/* MESSAGE */
178,540700709,1701602675,1919906915,1936288800,1663071092,1651076193,1830839666,1634562921,6841204,35,11,540700709,1701602675,1919906915,1936288800,2037588084,2019652718,1920099616,29295,30,10,540700709,1701602675,1919906915,1734439968,1886938400,1702126437,100,25,9,540700709,1953720684,1734439968,544434464,1936943469,6778473,23,8,540700709,1953397107,1696626785,1919906418,544106784,1702521203,1953719584,1952542057,29295,34,11,622882853,1864383088,544828526,543518319,1852383274,1713398048,1768713321,1646290798,1801678700,0,36,12,622882853,1763719792,1768300654,1852402796,1702043751,1952671084,1696625263,1667592312,6579572,35,11,622882853,1713388144,1768713321,1646290798,1801678700,1853453088,7889268,27,9,622882853,1931491952,1635020409,1919230072,544370546,1713401449,1768713321,26478,30,10,622882853,1914714736,1634037861,1868767348,1635021678,622883950,1970217060,1718558836,1851879968,673211751,623783473,10596,46,14,622882853,1847605872,1701978223,1952540016,1919903264,1931501856,1852404340,103,29,10,622882853,1914714736,1634037861,1868767348,1635021678,1696625774,1667592312,6579572,31,10,622882853,1830828656,1769173865,1948280686,1629513569,1919251558,14880,26,9,1702131813,1818324594,544220448,540700709,1936943469,543649385,1769108595,26478,30,10,1769498989,622880622,1701060720,1918987363,1869182049,1851859054,1919950948,1953461359,6647929,35,11,1679847461,1634493285,1769234802,1931505263,1635020409,1919230072,7499634,27,9,540700709,1702521203,1953719584,1952542057,622883439,1936269412,1953853216,543584032,1869376609,543450487,1735287154,101,45,14,0,
a_1236,/* MESSAGE */
33,1886611821,1701011820,2037588068,1819239021,7349536,19,7,1954047271,1634628197,1663051628,1646292577,1937055845,1763730533,1768693870,1918988898,1869422713,1864394084,7957614,43,13,1701998445,1634235424,1852776558,1915166821,661942127,0,20,8,656437102,1953460082,39,9,5,0,
a_1001,/* @StringTable */
12,1886676339,1835491698,1635152993,6649196,15,6,1886676327,1835491698,1635152993,6649196,15,6,0,
a_1720,/* TTAG */
348,28271,2,3,0,0,0,0,0,6710895,3,3,0,0,0,0,0,28526,2,3,0,0,0,0,0,1701736302,0,4,4,0,0,0,0,0,1819568500,101,5,4,0,0,0,0,0,1953720684,0,4,4,0,0,0,0,0,2002936180,1752458345,0,8,5,0,0,0,0,0,1751607666,1918987636,7235943,11,5,0,0,0,0,0,1852989815,1818717801,1818588773,0,12,6,0,0,0,0,0,1869771365,114,5,4,0,0,0,0,0,1852989815,6778473,7,4,0,0,0,0,0,1768318308,25966,6,4,0,0,0,0,0,1952672100,1634627433,31090,10,5,0,0,0,0,0,1818522739,1634886249,31090,10,5,0,0,0,0,0,1886220131,6646889,7,4,0,0,0,0,0,1970365810,6648425,7,4,0,0,0,0,0,1818455657,6644853,7,4,0,0,0,0,0,1969516397,25964,6,4,0,0,0,0,0,1919052140,7959137,7,4,0,0,0,0,0,1919052140,1836675681,6644847,11,5,0,0,0,0,0,1852797542,1952542068,7497076,11,5,0,0,0,0,0,1801675106,1953784173,29285,10,5,0,0,0,0,0,1919115629,111,5,4,0,0,0,0,0,1768713833,25966,6,4,0,0,0,0,0,1953460848,1887007855,101,9,5,0,0,0,0,0,1818391920,25449,6,4,0,0,0,0,0,1869639017,29810,6,4,0,0,0,0,0,1869641829,29810,6,4,0,0,0,0,0,1702258034,6648690,7,4,0,0,0,0,0,1667330676,101,5,4,0,0,0,0,0,1853189986,29540,6,4,0,0,0,0,0,1853189987,116,5,4,0,0,0,0,0,26217,2,3,0,0,0,0,0,1869506153,116,5,4,0,0,0,0,0,1701078633,102,5,4,0,0,0,0,0,1684956777,26213,6,4,0,0,0,0,0,1702063205,0,4,4,0,0,0,0,0,1768189541,102,5,4,0,0,0,0,0,0,
a_1236,/* MESSAGE */
91,1852797559,1919950951,1634559841,2037588084,2019652718,0,20,8,1734439536,544498029,1931505701,1635020409,1919230072,7499634,23,8,1734439536,544498029,624783397,1920409712,543649391,1734439536,544498029,1970037110,101,33,11,1734439536,544498029,624783397,1920409700,543649391,1734439536,544498029,1970037110,101,33,11,1734439536,544498029,574451749,539127845,1953723757,543515168,543516788,1701667187,0,32,11,1734439536,544498029,1768189541,1881488742,544434464,1936943469,6778473,27,9,1734439536,544498029,624783397,1634214000,1869488243,1952541984,1852401763,1634738279,29810,34,11,1734439536,544498029,1746956325,1847620449,1717903471,1952671078,0,24,9,1734439536,544498029,1763733541,1768693870,1918988898,1869422713,1864394084,7957614,31,10,28709,2,3,0,
a_1236,/* MESSAGE */
147,1701606770,980428064,1919903264,543973741,1701602675,1919906915,544220448,1701078386,1701734758,100,37,12,1701606770,980428064,1919903264,543973741,1953720684,1953068832,1768169576,1919247974,544501349,1768710499,6648418,43,13,1701606770,980428064,1919903264,543973741,1701602675,1919906915,1853453088,7889268,31,10,1701606770,980427808,1919903264,543973741,1701602675,1919906915,1734439968,1886938400,1702126437,100,37,12,1701606770,980428064,1919903264,543973741,1768318561,2037588088,2019652718,0,28,10,1701606770,980428064,1836675872,543977314,1763733541,2019893363,1952671088,1746953317,6648421,35,11,1701606770,980428064,1920099616,1763734127,1970413678,1746953580,6578533,27,9,1701606770,980428064,1819636256,1935745125,1919903264,543973741,1768318561,120,29,10,1701606770,980428064,1919905056,1752440933,1864396385,1075864942,1717985568,30825,30,10,1701606770,980428064,1668178208,544370536,1936269376,1701344288,1935764512,1717641332,7891302,35,11,1701606770,980428064,1769497888,1970413684,1998611820,543716457,544503151,1768318561,1881481336,0,36,12,1702131813,1818324594,1819636256,1881481317,1768759354,1852404595,1953701991,1735289202,0,32,11,1668183398,1852795252,980428064,1935763488,544173600,1701209701,29795,26,9,1701606770,1734439968,1886938400,1702126437,100,17,7,0,
a_1236,/* MESSAGE */
167,1651341683,622881903,1936269424,1886938400,1702126437,1701322852,25970,26,9,1651341683,622881903,1936269424,1886938400,1702126437,1717641316,544367988,28709,30,10,543646068,1701869669,1684370531,1952866592,622883429,112,21,8,543646068,1701869669,1684370531,0,12,6,1920298867,1864394083,1635000434,2019893351,1952671088,25701,22,8,543519605,773859880,690626606,1919903264,1954047264,1769172581,7564911,27,9,1696624233,1852142712,1852795251,1818587936,1869898597,2019893362,1952671088,25701,30,10,1702127201,2019893362,1936614772,544108393,543646068,1701869669,1684370531,0,28,10,1852797559,1717641319,544762214,1836216166,0,16,7,1701606770,980428064,1802401056,1853321070,1650551840,622881893,112,25,9,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1885696544,1702125925,100,33,11,1920298867,1696621923,1667592312,543450484,1702127201,1881481330,0,24,9,1836216166,1931504737,1667591269,544370548,623538213,1869488240,1701060724,1701734758,100,33,11,1768318561,1881481336,544434464,544501614,1818386804,1919885413,1635021600,27491,30,10,1701606770,980428064,1835363616,544367970,1701869669,1684370531,0,24,9,1701606770,980428064,544173600,1836216166,1629514849,1869112174,1717641330,7891302,31,10,1701606770,980428064,1852799520,2037588069,2019652718,1633888288,1953459822,543515168,1953525093,10617,38,12,1935764579,1768319347,1769234787,1746955887,1847620449,1633886319,7562611,27,9,0,
a_1719,/* LLOC */
0,
a_1001,/* @StringTable */
5,1868785011,1634755694,29555,10,5,0,
a_1236,/* MESSAGE */
139,622882853,1663056496,1869508193,1700929652,1954047264,1634628197,623386732,10604,30,10,622882853,1830828656,544502645,1931502946,1801675124,544370464,1818386804,623386725,10604,34,11,622882853,1679833712,1701209705,1953391986,1818321696,1701995113,1814374432,41,29,10,622882853,1679833712,1701209705,1953391986,1635021600,1918985326,1702043748,1952671084,673215087,2714661,39,12,622882853,1830828656,544502645,1864394082,2037653606,622880112,623386736,10604,30,10,1701606770,980428064,1702065440,1935745124,1717985568,673216617,2714661,27,9,1701606770,980428064,1718182944,1701995878,1914729582,543517813,1701869940,1814374432,41,33,11,1701606770,980428064,1718182944,1701995878,1713402990,1634562671,1717641324,1702390118,623386739,10604,38,12,622882853,1696610928,1919905912,543450484,543646068,1953723757,543515168,1818326385,1701406313,100,37,12,622882853,1763719792,1919905901,543450484,543646068,1953723757,543515168,1818326385,1701406313,100,37,12,622882853,1847605872,1679848559,1852401253,1763730533,1752440942,1830843241,1819632751,623386725,10604,38,12,622882853,1663056496,1869508193,1700929652,1667329312,673214322,2714661,27,9,1634889767,1952542055,1667329319,624783218,1763719792,1919905383,25701,26,9,0,
a_1001,/* @StringTable */
10,1936941424,51,5,4,1953067639,1162037605,1835365481,0,12,6,0,
a_1236,/* MESSAGE */
69,1819044198,543649385,540700709,1701080693,1701734758,1702043748,1952671084,622883439,112,33,11,1819044198,543649385,540700709,1818585446,1881481316,1886741536,1633905004,6579572,31,10,1819044198,543649385,540700709,1852797559,1768300647,1646292076,1801678700,0,28,10,622882853,1847605872,1965061231,6579571,15,6,1819044198,543649385,540700709,1668246626,1769152619,622880122,1936269412,1734959648,544367975,1851877492,1818321696,1701995113,1680156704,41,53,16,1819044198,543649385,540700709,1668246626,1769152619,622880122,1936269412,1634562848,1919249516,1634235424,1633886318,1919052140,623386725,10596,54,16,0,
a_1001,/* @StringTable */
4,1936941424,52,5,4,0,
a_1718,/* LADM */
0,
a_1236,/* MESSAGE */
14,622882853,1931491952,1667591269,544370548,1914728485,1717920869,1684369001,1718182944,1701995878,2037150830,1814374432,41,45,14,0,
a_1001,/* @StringTable */
22,1684104562,1836020326,1953719666,6648431,15,6,1702257011,1701998452,1919906931,101,13,6,1701536109,1953719666,6648431,11,5,1953066601,1953719666,6648431,11,5,0,
a_1683,/* RESTORE */
1,0,-500,
0,
a_1236,/* MESSAGE */
42,1651341683,622881903,1936269424,1936615712,1702130277,100,21,8,543646068,1701869669,1684370531,1952866592,975204965,58,21,8,1735357040,544039282,1954047348,1768649504,1684369520,1953396000,1948281961,1847616872,544503909,1852403568,116,41,13,1096040774,1830828620,1835628641,1914727521,1869902693,1931502962,543521385,1701017701,1684366437,1680156704,41,41,13,0,
a_1001,/* @StringTable */
13,1918985587,1634560099,1919906403,6646901,15,6,1702129253,1701998706,1768318308,1952736622,26465,18,7,0,
a_1236,/* MESSAGE */
13,540700709,1651863396,1679849836,1852401253,1763730533,1752440942,1919950949,1651335525,673211756,1635017062,10604,42,13,0,
a_1720,/* TTAG */
130,0,0,3,0,0,0,0,0,1718184051,1717985652,1818392681,7037807,15,6,0,0,0,0,0,1635018087,2020173414,1668246626,7302763,15,6,0,0,0,0,0,1869574720,116,5,4,0,0,0,0,0,1769497920,116,5,4,0,0,0,0,0,1920226112,1416064617,1701601889,0,12,6,0,0,0,0,0,1801547072,101,5,4,0,0,0,0,0,1701997888,113,5,4,0,0,0,0,0,1970365760,27745,6,4,0,0,0,0,0,1953459776,29029,6,4,0,0,0,0,0,1919905088,101,5,4,0,0,0,0,0,1936026688,115,5,4,0,0,0,0,0,1702063168,113,5,4,0,0,0,0,0,64,1,3,0,0,0,0,0,0,
a_1718,/* LADM */
32,0,0,-2,32,16777240,0,0,604757305,0,0,-2,32,16777271,0,0,604757285,0,0,-2,32,16777271,0,0,604757265,0,0,-2,32,16777271,0,0,604757276,0,
a_1718,/* LADM */
12,0,0,16777875,1,1,16777879,16777316,2,2,0,16777298,16777316,0,
a_1761,/* INDICATOR */
119,1701080693,1701734758,100,9,5,1936617315,1953390964,0,8,5,1769103734,1701601889,0,8,5,1952543859,1981834089,29281,10,5,1818386804,101,5,4,1667331187,107,5,4,1952543859,1931502441,1801675124,0,12,6,1852403568,544367988,1936617315,1953390964,0,16,7,1918986339,1701603686,0,8,5,1635017060,1701603686,0,8,5,1701606770,0,4,4,1836216166,1931504737,1801675124,0,12,6,1836216166,1948281953,1701601889,0,12,6,1836216166,1713400929,6646889,11,5,1836216166,1763732577,110,9,5,1836216166,1864395873,29813,10,5,1836216166,1763732577,1953853294,0,12,6,1836216166,1629514849,1869112174,114,13,6,1836216166,1931504737,1952868712,0,12,6,1919115629,1634738287,1701667186,7497076,15,6,1629515630,1836410738,7630437,11,5,1633906540,108,5,4,1700946284,108,5,4,0,
a_1236,/* MESSAGE */
61,622882853,1830828656,1769173865,1948280686,1763731297,2019893358,1936028272,1852795251,0,32,11,622882853,1696610928,1701998712,1869181811,2037588078,2019652718,0,24,9,540700709,543646068,1701869669,1684370531,0,16,7,1702131813,1818324594,544220448,540700709,1936943469,543649385,1769108595,26478,30,10,1769498989,622880622,1701060720,1918987363,1869182049,1851859054,1919950948,1953461359,6647929,35,11,622882853,1864383088,544828526,1953655158,543973749,1853189986,1763734372,2019893358,1936028272,1852795251,115,41,13,0,
a_1001,/* @StringTable */
62,1952542071,1868982371,1818324338,1970561889,27745,18,7,1835627383,1634036848,2020173414,0,12,6,1634890871,1869640558,1768715378,29811,14,6,1886220131,1147499637,1634494037,29543,14,6,1852401228,1650551908,7564389,11,5,1919841612,7105647,7,4,1986097780,1702064741,1162630482,0,12,6,1953259861,1634628197,1702259060,0,12,6,1952670037,1919705461,6646901,11,5,1734701653,7237481,7,4,1952542055,1868982371,1818324338,1970561889,27745,18,7,0,
a_1719,/* LLOC */
0,
a_1151,/* RULE */
0,
a_1236,/* MESSAGE */
54,1701606770,980428064,1818326560,1864394101,1869357158,543973731,1768318561,1881481336,1953459744,1702065440,100,41,13,1701606770,980428064,1717985568,622884969,1702043760,1969365108,1869488244,1937055860,25701,34,11,1701606770,980428064,1769107232,1634625895,1635131500,543520108,1713399407,1634562671,1717641324,544762214,1847619621,1965061231,6579571,51,15,1701606770,980428064,1919903264,543973741,1768318561,1881481336,1701798944,1869488243,1751326836,1701277281,1633886252,1700929646,7235872,51,15,0,
-1}; /* fill table size 4232 */
static void a_data_setup(void){
 a_virtual_min=16777216;a_virtual_max=2130706432;
 a_setup_list(0,a_1001,"@StringTable",1,2130705914,2130706304,391); /* @StringTable */
 a_setup_list(1,a_1086,"NODE",1,1990708582,2130703581,0); /* NODE */
 a_setup_list(1,a_1113,"NUMBER",1,1962709581,1990708580,0); /* NUMBER */
 a_setup_list(1,a_1136,"REGISTER",1,1948710080,1962709579,0); /* REGISTER */
 a_setup_list(1,a_1150,"BUFFER",1,1934710579,1948710078,0); /* BUFFER */
 a_setup_list(1,a_1151,"RULE",2,1920711078,1934710576,0); /* RULE */
 a_setup_list(0,a_1157,"DSYMB",1,1696718844,1696719046,203); /* DSYMB */
 a_setup_list(1,a_1165,"QBUFFER",1,1682719343,1696718842,0); /* QBUFFER */
 a_setup_list(1,a_1217,"DICT",1,1192736842,1682719341,0); /* DICT */
 a_setup_list(0,a_1236,"MESSAGE",1,2130703583,2130705912,2330); /* MESSAGE */
 a_setup_list(1,a_1317,"INPUT",7,1178737320,1192736834,21); /* INPUT */
 a_setup_list(1,a_1318,"RANK",3,1164737813,1178737310,0); /* RANK */
 a_setup_list(0,a_1373,"BOLD",3,1164737384,1164737637,256); /* BOLD */
 a_setup_list(1,a_1374,"LEXT",1,1696719048,1920711075,28); /* LEXT */
 a_setup_list(0,a_1379,"SPECIAL",1,1164737641,1164737809,169); /* SPECIAL */
 a_setup_list(1,a_1668,"TMPSEL",3,562758392,576757889,0); /* TMPSEL */
 a_setup_list(1,a_1683,"RESTORE",1,16777337,16777836,500); /* RESTORE */
 a_setup_list(1,a_1718,"LADM",8,16777845,562758381,44); /* LADM */
 a_setup_list(1,a_1719,"LLOC",6,576757898,604756892,0); /* LLOC */
 a_setup_list(1,a_1720,"TTAG",5,604756903,1164737376,478); /* TTAG */
 a_setup_list(0,a_1761,"INDICATOR",1,16777217,16777335,119); /* INDICATOR */
 a_setup_stdarg(a_1889,"STDARG",1);
 a_setup_charfile(a_1085,"ICE",2,a_1001,2130705944); /* ICE */
 a_setup_dfile(a_1155,"DISCR",1,a_1001,2130706062,7); /* DISCR */
   a_add_filearea(a_1155,a_1720,1); /* TTAG */
   a_add_filearea(a_1155,a_1157,2); /* DSYMB */
   a_add_filearea(a_1155,a_1718,3); /* LADM */
   a_add_filearea(a_1155,a_1719,4); /* LLOC */
   a_add_filearea(a_1155,a_1374,5); /* LEXT */
   a_add_filearea(a_1155,a_1113,6); /* NUMBER */
   a_add_filearea(a_1155,a_1761,7); /* INDICATOR */
 a_setup_dfile(a_1156,"DISCW",2,a_1001,2130706062,7); /* DISCW */
   a_add_filearea(a_1156,a_1720,1); /* TTAG */
   a_add_filearea(a_1156,a_1157,2); /* DSYMB */
   a_add_filearea(a_1156,a_1718,3); /* LADM */
   a_add_filearea(a_1156,a_1719,4); /* LLOC */
   a_add_filearea(a_1156,a_1374,5); /* LEXT */
   a_add_filearea(a_1156,a_1113,6); /* NUMBER */
   a_add_filearea(a_1156,a_1761,7); /* INDICATOR */
 a_setup_charfile(a_1237,"PRINTFILE",2,a_1001,2130706113); /* PRINTFILE */
 a_setup_charfile(a_1378,"SOURCE",1,a_1001,2130706176); /* SOURCE */
 a_list_fill(a_FILL);
}
static void a_waitfor(int a_F1,int a_F2){
 a_MODROOT(a_1717,"tags")
 a_MODROOT(a_1290,"identifier")
 a_MODROOT(a_1135,"arithmetic")
 a_MODROOT(a_1112,"number")
}
void a_ROOT(void){
 a_data_setup();
 a_waitfor(0,0);
 a_1453();
}
static int a_1049(int a_F1,int a_F2){ /* islocalflag+>a+>a */
int a_L3;
a_booland(to_LIST(a_1719)->offset[a_F1-3],a_F2,a_L3);
if(!a_noteq(a_L3,0)){ return 0;} return 1;
} /* islocalflag */
static void a_1068(int a_F1,int a_F2){ /* setlocalflag+>a+>a */

a_boolor(to_LIST(a_1719)->offset[a_F1-3],a_F2,to_LIST(a_1719)->offset[a_F1-3]); return;
} /* setlocalflag */
static void a_1025(int a_F1,int a_F2){ /* clearlocalflag+>a+>a */

a_boolinvert(a_F2,a_F2);
a_booland(to_LIST(a_1719)->offset[a_F1-3],a_F2,to_LIST(a_1719)->offset[a_F1-3]); return;
} /* clearlocalflag */
static void a_1032(void){ /* copylocalTflagtoF */
int a_L1;
a_L1=to_LIST(a_1719)->aupb;
a_G2:if(a_less(a_L1,to_LIST(a_1719)->alwb)){ return;}
if(!a_1049(a_L1,2)){ goto a_G5;}
a_1068(a_L1,4); goto a_G6;
a_G5:a_1025(a_L1,4);
a_G6:if(!a_1049(a_L1,8)){ goto a_G8;}
a_1068(a_L1,16); goto a_G9;
a_G8:a_1025(a_L1,16);
a_G9:a_previous(a_1719,a_L1); goto a_G2;
} /* copylocalTflagtoF */
static void a_1064(int a_F1){ /* resetaffixblockflags+>a */
int a_L2;int a_L3;int a_P[3];
a_L2=to_LIST(a_1719)->alwb;
a_L3=1;
a_G3:if(a_more(a_L2,to_LIST(a_1719)->aupb)){ return;}
if(a_equal(to_LIST(a_1719)->offset[a_L2-2],16777335)){ return;}
if(!a_equal(to_LIST(a_1719)->offset[a_L2-2],16777310)){ goto a_G12;}
if(a_1049(a_L2,8)){ goto a_G8;}
a_P[0]=2130703606;a_P[1]=a_F1;a_1240(4,-1,2,a_P);
a_G8:if(!a_1049(a_L2,2)){ goto a_G10;}
a_L3=0;
a_G10:a_1025(a_L2,16);
a_1068(a_L2,4); goto a_G18;
a_G12:if(!a_1049(a_L2,4096)){ goto a_G18;}
if(!a_is(a_L3)){ goto a_G18;}
if(!a_equal(to_LIST(a_1719)->offset[a_L2-2],16777298)){ goto a_G18;}
if(!a_1049(a_L2,2)){ goto a_G17;}
a_1025(a_L2,2); goto a_G18;
a_G17:a_P[0]=2130703595;a_P[1]=a_F1;a_P[2]=to_LIST(a_1719)->offset[a_L2];a_1238(-1,3,a_P);
a_G18:a_next(a_1719,a_L2); goto a_G3;
} /* resetaffixblockflags */
static int a_1005(int a_A[1]){ /* Ltag+a> */
int a_P[1];
if(!a_1171(a_P)){ goto a_G3;}a_A[0]=a_P[0];
a_1068(a_A[0],1); return 1;
a_G3:if(!a_1179(a_P)){ return 0;}a_A[0]=a_P[0]; return 1;
} /* Ltag */
static void a_1055(int a_A[1]){ /* mustLtag+a> */
int a_P[1];
a_1200(a_P);a_A[0]=a_P[0];
if(!a_was(a_1719,a_A[0])){ return;}
a_1068(a_A[0],1); return;
} /* mustLtag */
static void a_1045(int a_F1,int a_A[1]){ /* getlocalcalibre+>a+a> */

a_A[0]=to_LIST(a_1719)->offset[a_F1-5]; return;
} /* getlocalcalibre */
static void a_1046(int a_F1,int a_A[1]){ /* getlocalssel+>a+a> */

a_A[0]=to_LIST(a_1719)->offset[a_F1-4]; return;
} /* getlocalssel */
static void a_1071(int a_F1){ /* setupformalstack+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_P[2];
a_scratch(a_1719);
a_L7=0;
a_1731(a_F1,a_P);a_L5=a_P[0];
a_L6=1;
a_G5:if(a_more(a_L6,a_L5)){ return;}
a_1733(a_F1,a_L6,a_P);a_L2=a_P[0];
a_1201(a_P);a_L3=a_P[0];
a_1724(a_L2,a_L3);
{ if(a_L2==16777277||a_L2==16777283){ goto a_G10;}
 if(a_L2==16777310){ goto a_G14;}
 if(a_L2==16777298){ goto a_G16;}
  goto a_G18;}
a_G10:a_1732(a_F1,a_L6,a_P);a_L3=a_P[0];a_L4=a_P[1];
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-5]=a_L3;
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-4]=a_L4;
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-3]=2; goto a_G21;
a_G14:to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-3]=8;
a_L7=1; goto a_G21;
a_G16:if(a_equal(a_L7,0)){ goto a_G21;}
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-3]=4096; goto a_G21;
a_G18:to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-3]=2;
if(a_equal(a_L7,0)){ goto a_G21;}
a_1068(to_LIST(a_1719)->aupb,4096);
a_G21:a_incr(a_L6); goto a_G5;
} /* setupformalstack */
static void a_1072(int a_A[1]){ /* setuplabel+a> */
int a_P[1];
if(!a_1164(1696718945)){ goto a_G5;}
a_1201(a_P);a_A[0]=a_P[0];
a_1724(16777335,a_A[0]);
a_A[0]=to_LIST(a_1719)->aupb; return;
a_G5:a_A[0]=0; return;
} /* setuplabel */
static void a_1073(void){ /* setuplocals */
int a_L1;int a_P[1];
if(!a_1164(1696718953)){ return;}
a_G2:if(a_1164(1696718885)){ return;}
a_1201(a_P);a_L1=a_P[0];
a_1724(16777331,a_L1);
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-1]=a_1029; goto a_G2;
} /* setuplocals */
static void a_1059(int a_F1){ /* pushRULE+>a */

a_1037(0,a_F1); return;
} /* pushRULE */
static void a_1067(int a_F1,int a_F2){ /* setRULEflag+>a+>a */

a_boolor(to_LIST(a_1151)->offset[a_F1-1],a_F2,to_LIST(a_1151)->offset[a_F1-1]); return;
} /* setRULEflag */
static int a_1048(int a_F1,int a_F2){ /* isRULEflag+>a+>a */
int a_L3;
a_booland(to_LIST(a_1151)->offset[a_F1-1],a_F2,a_L3);
if(!a_noteq(a_L3,0)){ return 0;} return 1;
} /* isRULEflag */
static void a_1024(int a_F1,int a_F2){ /* clearRULEflag+>a+>a */
int a_L3;
a_boolinvert(a_F2,a_L3);
a_booland(to_LIST(a_1151)->offset[a_F1-1],a_L3,to_LIST(a_1151)->offset[a_F1-1]); return;
} /* clearRULEflag */
static void a_1057(int a_F1){ /* openrange+>a */
int a_L2;
a_L2=to_LIST(a_1719)->alwb;
a_1059(0);
if(!a_is(a_F1)){ goto a_G5;}
a_1067(to_LIST(a_1151)->aupb,32);
a_G5:if(a_more(a_L2,to_LIST(a_1719)->aupb)){ return;}
if(a_equal(to_LIST(a_1719)->offset[a_L2-2],16777335)){ goto a_G12;}
a_1059(a_L2);
if(!a_1049(a_L2,2)){ goto a_G10;}
a_1067(to_LIST(a_1151)->aupb,272);
a_G10:if(!a_1049(a_L2,8)){ goto a_G12;}
a_1067(to_LIST(a_1151)->aupb,544);
a_G12:a_next(a_1719,a_L2); goto a_G5;
} /* openrange */
static void a_1062(int a_F1){ /* recomputeRULEflags+>a */
int a_L2;int a_L3;int a_L4;
if(!a_1048(a_F1,16)){ goto a_G3;}
a_L2=1; goto a_G4;
a_G3:a_L2=0;
a_G4:if(!a_1048(a_F1,32)){ goto a_G6;}
a_L3=1; goto a_G7;
a_G6:a_L3=0;
a_G7:to_LIST(a_1151)->offset[a_F1-1]=0;
a_L4=to_LIST(a_1151)->offset[a_F1];
if(!a_is(a_L2)){ goto a_G12;}
a_1067(a_F1,272);
a_1068(a_L4,2); goto a_G13;
a_G12:a_1025(a_L4,2);
a_G13:if(!a_is(a_L3)){ goto a_G16;}
a_1067(a_F1,544);
a_1068(a_L4,8); return;
a_G16:a_1025(a_L4,8); return;
} /* recomputeRULEflags */
static void a_1008(int a_F1,int a_F2){ /* addlabel+>a+>a */

if(!a_is(a_F1)){ return;}
a_1059(to_LIST(a_1719)->offset[a_F1]);
to_LIST(a_1719)->offset[a_F1-1]=a_F2; return;
} /* addlabel */
static int a_1063(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* redoregion+>a+>a+>a+a> */
int a_L5;
a_L5=a_F1;
a_G2:if(a_equal(to_LIST(a_1151)->offset[a_L5],0)){ goto a_G4;}
a_previous(a_1151,a_L5); goto a_G2;
a_G4:if(a_equal(a_F2,0)){ goto a_G9;}
if(a_1048(a_L5,8192)){ goto a_G9;}
a_1067(a_L5,8192);
if(!a_1048(a_L5,4096)){ goto a_G9;}
a_1067(a_L5,32768);
a_G9:if(a_equal(a_F3,0)){ goto a_G14;}
if(a_1048(a_L5,16384)){ goto a_G14;}
a_1067(a_L5,16384);
if(!a_1048(a_L5,4096)){ goto a_G14;}
a_1067(a_L5,32768);
a_G14:if(!a_1048(a_L5,32768)){ return 0;}
a_1024(a_L5,32768);
if(!a_1048(a_L5,32)){ goto a_G18;}
a_A[0]=1; goto a_G19;
a_G18:a_A[0]=0;
a_G19:if(a_lseq(a_F1,a_L5)){ return 1;}
a_next(a_1151,a_L5);
a_1062(a_L5); goto a_G19;
} /* redoregion */
static void a_1015(int a_F1){ /* checklabelshield+>a */
int a_L2;int a_P[2];
a_L2=to_LIST(a_1719)->offset[a_F1-1];
a_G2:if(a_1048(a_L2,65536)){ return;}
if(!a_mreq(a_L2,to_LIST(a_1151)->aupb)){ goto a_G5;}
a_P[0]=2130703614;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
a_G5:a_next(a_1151,a_L2); goto a_G2;
} /* checklabelshield */
static void a_1069(int a_F1,int a_F2,int a_A[2]){ /* setrulejump+>a+>a+a>+a> */
int a_L5;int a_L6;
a_L6=0;
a_A[0]=a_F2;a_A[1]=a_F2;
a_G3:a_L5=to_LIST(a_1151)->offset[a_F2];
if(!a_equal(a_L5,0)){ goto a_G16;}
a_1067(a_F2,4096);
if(a_1048(a_F2,8192)){ goto a_G8;}
a_A[0]=0;
a_G8:if(a_1048(a_F2,16384)){ goto a_G10;}
a_A[1]=0;
a_G10:if(a_1048(a_F2,32)){ goto a_G14;}
if(!a_is(a_F1)){ goto a_G14;}
a_1067(a_F2,32);
a_L6=1;
a_G14:if(!a_is(a_L6)){ return;}
a_1067(a_F2,32768); return;
a_G16:if(!a_1049(a_L5,8)){ goto a_G20;}
if(a_1048(a_F2,32)){ goto a_G20;}
a_1067(a_F2,32);
a_L6=1;
a_G20:if(a_1049(a_L5,2)){ goto a_G24;}
if(!a_1048(a_F2,16)){ goto a_G24;}
a_1024(a_F2,16);
a_L6=1;
a_G24:a_previous(a_1151,a_F2); goto a_G3;
} /* setrulejump */
static void a_1070(int a_F1){ /* setupaltheadflags+>a */
int a_L2;
a_G1:a_L2=to_LIST(a_1151)->offset[a_F1];
if(a_equal(a_L2,0)){ return;}
if(!a_1048(a_F1,256)){ goto a_G5;}
a_1068(a_L2,2); goto a_G6;
a_G5:a_1025(a_L2,2);
a_G6:if(!a_1048(a_F1,512)){ goto a_G8;}
a_1068(a_L2,8); goto a_G9;
a_G8:a_1025(a_L2,8);
a_G9:a_previous(a_1151,a_F1); goto a_G1;
} /* setupaltheadflags */
static void a_1076(int a_F1){ /* storealtheadflags+>a */

a_G1:if(a_equal(to_LIST(a_1151)->offset[a_F1],0)){ return;}
if(!a_1049(to_LIST(a_1151)->offset[a_F1],4)){ goto a_G4;}
a_1067(a_F1,256); goto a_G5;
a_G4:a_1024(a_F1,256);
a_G5:if(!a_1049(to_LIST(a_1151)->offset[a_F1],16)){ goto a_G7;}
a_1067(a_F1,512); goto a_G8;
a_G7:a_1024(a_F1,512);
a_G8:a_previous(a_1151,a_F1); goto a_G1;
} /* storealtheadflags */
static void a_1027(int a_F1){ /* closerange+>a */
int a_L2;
a_G1:a_L2=to_LIST(a_1151)->offset[a_F1];
if(!a_equal(a_L2,0)){ goto a_G5;}
a_previous(a_1151,a_F1);
a_unstackto(a_1151,a_F1); return;
a_G5:if(!a_1048(a_F1,1)){ goto a_G7;}
a_1025(a_L2,2); goto a_G8;
a_G7:a_1068(a_L2,2);
a_G8:if(!a_1048(a_F1,2)){ goto a_G10;}
a_1025(a_L2,4); goto a_G11;
a_G10:a_1068(a_L2,4);
a_G11:if(!a_1048(a_F1,4)){ goto a_G13;}
a_1068(a_L2,8); goto a_G14;
a_G13:a_1025(a_L2,8);
a_G14:if(!a_1048(a_F1,8)){ goto a_G16;}
a_1068(a_L2,16); goto a_G17;
a_G16:a_1025(a_L2,16);
a_G17:a_previous(a_1151,a_F1); goto a_G1;
} /* closerange */
static void a_1053(int a_F1,int a_F2,int a_F3){ /* mergealtsequenceflags+>a+>a+>a */
int a_L4;
a_G1:a_L4=to_LIST(a_1151)->offset[a_F1];
if(a_equal(a_L4,0)){ return;}
if(!a_is(a_F2)){ goto a_G8;}
if(a_1049(a_L4,2)){ goto a_G6;}
a_1067(a_F1,1);
a_G6:if(!a_1049(a_L4,8)){ goto a_G8;}
a_1067(a_F1,4);
a_G8:if(!a_is(a_F3)){ goto a_G13;}
if(a_1049(a_L4,4)){ goto a_G11;}
a_1067(a_F1,2);
a_G11:if(!a_1049(a_L4,16)){ goto a_G13;}
a_1067(a_F1,8);
a_G13:a_previous(a_1151,a_F1); goto a_G1;
} /* mergealtsequenceflags */
static void a_1026(int a_F1){ /* cleartailFbits+>a */

a_G1:if(a_equal(to_LIST(a_1151)->offset[a_F1],0)){ return;}
a_1024(a_F1,3072);
a_previous(a_1151,a_F1); goto a_G1;
} /* cleartailFbits */
static void a_1054(int a_F1){ /* mergetailFbits+>a */

a_G1:if(a_equal(to_LIST(a_1151)->offset[a_F1],0)){ return;}
if(a_1049(to_LIST(a_1151)->offset[a_F1],4)){ goto a_G4;}
a_1067(a_F1,1024);
a_G4:if(!a_1049(to_LIST(a_1151)->offset[a_F1],16)){ goto a_G6;}
a_1067(a_F1,2048);
a_G6:a_previous(a_1151,a_F1); goto a_G1;
} /* mergetailFbits */
static void a_1081(int a_F1){ /* usetailFbits+>a */
int a_L2;
a_G1:a_L2=to_LIST(a_1151)->offset[a_F1];
if(a_equal(a_L2,0)){ return;}
if(!a_1048(a_F1,1024)){ goto a_G5;}
a_1025(a_L2,4); goto a_G6;
a_G5:a_1068(a_L2,4);
a_G6:if(!a_1048(a_F1,2048)){ goto a_G8;}
a_1068(a_L2,16); goto a_G9;
a_G8:a_1025(a_L2,16);
a_G9:a_previous(a_1151,a_F1); goto a_G1;
} /* usetailFbits */
static void a_1083(int a_F1,int a_F2,int a_A[1]){ /* where+>a+>a+a> */

if(!a_equal(a_F1,0)){ goto a_G3;}
a_A[0]=2130703617; return;
a_G3:if(!a_equal(a_F2,0)){ goto a_G5;}
a_A[0]=2130703624; return;
a_G5:a_A[0]=2130703629; return;
} /* where */
static int a_1047(int a_F1){ /* haslisttype+>a */
int a_L2;int a_P[1];
a_1741(a_F1,a_P);a_L2=a_P[0];
{ if(a_L2==16777240||a_L2==16777244||a_L2==16777250||a_L2==16777283||a_L2==16777277){ return 1;}
  return 0;}
} /* haslisttype */
static void a_1056(int a_F1,int a_F2,int a_F3){ /* mustbeoflisttype+>a+>a+>a */
int a_L4;int a_L5;int a_P[5];
a_1741(a_F3,a_P);a_L4=a_P[0];
a_1083(a_F1,a_F2,a_P);a_L5=a_P[0];
a_P[0]=2130703645;a_P[1]=a_L5;a_P[2]=a_F1;a_P[3]=a_L4;a_P[4]=a_F3;a_1238(-1,5,a_P); return;
} /* mustbeoflisttype */
static void a_1019(int a_F1,int a_F2,int a_F3){ /* checkssel+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_P[5];
a_1741(a_F3,a_P);a_L4=a_P[0];
{ if(!(a_L4==16777240||a_L4==16777244||a_L4==16777250)){ goto a_G4;}
}
a_1680(a_F3,a_P);a_L5=a_P[0]; goto a_G5;
a_G4:a_1046(a_F3,a_P);a_L5=a_P[0];
a_G5:if(a_more(a_L5,0)){ return;}
a_1083(a_F1,a_F2,a_P);a_L6=a_P[0];
a_P[0]=2130703656;a_P[1]=a_L6;a_P[2]=a_F1;a_P[3]=a_L4;a_P[4]=a_F3;a_1238(-1,5,a_P); return;
} /* checkssel */
static void a_1061(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* readselector+>a+>a+>a+a> */
int a_L5;int a_L6;int a_L7;int a_P[6];
if(a_1168(a_P)){a_A[0]=a_P[0]; return;}
a_1201(a_P);a_L6=a_P[0];
a_1741(a_F3,a_P);a_L5=a_P[0];
{ if(!(a_L5==16777240||(16777244<=a_L5 && a_L5<=16777250))){ goto a_G9;}
}
if(a_1674(a_F3,a_L6,a_P)){a_A[0]=a_P[0]; return;}
a_A[0]=0;
a_1083(a_F1,a_F2,a_P);a_L7=a_P[0];
a_P[0]=2130703667;a_P[1]=a_L7;a_P[2]=a_F1;a_P[3]=a_L6;a_P[4]=a_L5;a_P[5]=a_F3;a_1238(-1,6,a_P); return;
a_G9:a_A[0]=1; return;
} /* readselector */
static void a_1075(void){ /* skipsource */
int a_P[1];
if(a_1172(a_P)){ return;}
if(a_1164(1696718957)){ goto a_G7;}
if(a_1164(1696719035)){ goto a_G7;}
if(a_1164(1696719039)){ goto a_G7;}
if(a_1164(1696719043)){ goto a_G7;}
if(!a_1164(1696718876)){ goto a_G8;}
a_G7:a_1200(a_P); return;
a_G8:if(!a_1164(1696719027)){ goto a_G14;}
a_1200(a_P);
a_1075();
a_1196(1696718871);
if(a_1168(a_P)){ return;}
a_1201(a_P); return;
a_G14:if(a_1164(1696718972)){ return;} goto a_G7;
} /* skipsource */
static void a_1074(void){ /* skipaffixes */

a_G1:if(!a_1164(1696718988)){ return;}
a_1075(); goto a_G1;
} /* skipaffixes */
static void a_1009(int a_F1,int a_F2,int a_F3){ /* affixtypeerror+>a+>a+>a */
int a_L4;int a_L5;int a_P[5];
if(!a_equal(a_F3,0)){ goto a_G4;}
a_1083(a_F1,a_F2,a_P);a_L5=a_P[0];
a_P[0]=2130703674;a_P[1]=a_L5;a_P[2]=a_F1;a_1238(-1,3,a_P); return;
a_G4:a_1741(a_F3,a_P);a_L4=a_P[0];
a_1083(a_F1,a_F2,a_P);a_L5=a_P[0];
a_P[0]=2130703683;a_P[1]=a_L5;a_P[2]=a_F1;a_P[3]=a_F3;a_P[4]=a_L4;a_1238(-1,5,a_P); return;
} /* affixtypeerror */
static void a_1010(int a_F1,int a_F2,int a_F3){ /* affixuninitializederror+>a+>a+>a */
int a_L4;int a_P[4];
a_1083(a_F1,a_F2,a_P);a_L4=a_P[0];
a_P[0]=2130703691;a_P[1]=a_L4;a_P[2]=a_F1;a_P[3]=a_F3;a_1238(-1,4,a_P); return;
} /* affixuninitializederror */
static void a_1031(int a_F1,int a_F2){ /* constantaffixerror+>a+>a */
int a_L3;int a_P[4];
a_1083(a_F1,a_F2,a_P);a_L3=a_P[0];
a_P[0]=2130703702;a_P[1]=a_L3;a_P[2]=a_F1;a_P[3]=a_F2;a_1238(-1,4,a_P); return;
} /* constantaffixerror */
static void a_1033(int a_F1,int a_F2,int a_F3){ /* destlisttypeerror+>a+>a+>a */
int a_L4;int a_P[4];
a_1083(a_F1,a_F2,a_P);a_L4=a_P[0];
a_P[0]=2130703713;a_P[1]=a_L4;a_P[2]=a_F1;a_P[3]=a_F3;a_1238(-1,4,a_P); return;
} /* destlisttypeerror */
static void a_1034(int a_F1,int a_F2,int a_F3){ /* desttypeerror+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_P[6];
a_1083(a_F1,a_F2,a_P);a_L4=a_P[0];
a_1741(a_F3,a_P);a_L5=a_P[0];
a_1730(a_F1,a_P);a_L6=a_P[0];
a_P[0]=2130703724;a_P[1]=a_L4;a_P[2]=a_F1;a_P[3]=a_L5;a_P[4]=a_F3;a_P[5]=a_L6;a_1238(-1,6,a_P); return;
} /* desttypeerror */
static void a_1035(int a_F1,int a_F2){ /* dummyaffixerror+>a+>a */
int a_L3;int a_P[3];
a_1083(a_F1,a_F2,a_P);a_L3=a_P[0];
a_P[0]=2130703735;a_P[1]=a_L3;a_P[2]=a_F1;a_1238(-1,3,a_P); return;
} /* dummyaffixerror */
static void a_1039(int a_F1,int a_F2){ /* ffileaffix+>a+>a */
int a_L3;int a_L4;int a_P[1];
if(!a_1005(a_P)){ goto a_G5;}a_L3=a_P[0];
a_1741(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777288||a_L4==16777262||a_L4==16777267){ return;}
}
a_1009(a_F1,a_F2,a_L3); return;
a_G5:a_1009(a_F1,a_F2,0);
a_1075(); return;
} /* ffileaffix */
static void a_1013(int a_F1,int a_F2,int a_F3){ /* checkcalibre+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[5];
a_1732(a_F1,a_F2,a_P);a_L4=a_P[0];a_L5=a_P[1];
if(a_less(a_L4,0)){ return;}
a_1741(a_F3,a_P);a_L8=a_P[0];
if(a_equal(a_L8,16777283)){ goto a_G6;}
if(!a_equal(a_L8,16777277)){ goto a_G8;}
a_G6:a_1045(a_F3,a_P);a_L6=a_P[0];
a_1046(a_F3,a_P);a_L7=a_P[0]; goto a_G10;
a_G8:a_1677(a_F3,a_P);a_L6=a_P[0];
a_1680(a_F3,a_P);a_L7=a_P[0];
a_G10:if(a_mreq(a_L6,0)){ goto a_G12;}
a_L6=1;
a_G12:if(a_equal(a_L4,a_L6)){ goto a_G16;}
if(!a_1746(a_F1,128)){ goto a_G15;}
a_P[0]=2130703757;a_P[1]=2130703634;a_P[2]=a_F1;a_P[3]=a_F3;a_P[4]=a_L4;a_1238(-1,5,a_P); goto a_G16;
a_G15:a_P[0]=2130703757;a_P[1]=2130703629;a_P[2]=a_F1;a_P[3]=a_F3;a_P[4]=a_L4;a_1240(7,-1,5,a_P);
a_G16:if(a_equal(a_L5,a_L7)){ return;}
if(!a_1746(a_F1,128)){ goto a_G19;}
a_P[0]=2130703770;a_P[1]=2130703634;a_P[2]=a_F1;a_P[3]=a_F3;a_1238(-1,4,a_P); return;
a_G19:a_P[0]=2130703770;a_P[1]=2130703629;a_P[2]=a_F1;a_P[3]=a_F3;a_1240(7,-1,4,a_P); return;
} /* checkcalibre */
static void a_1043(int a_F1,int a_F2){ /* ftableaffix+>a+>a */
int a_L3;int a_P[1];
if(!a_1005(a_P)){ goto a_G5;}a_L3=a_P[0];
if(!a_1047(a_L3)){ goto a_G4;}
a_1013(a_F1,a_F2,a_L3); return;
a_G4:a_1009(a_F1,a_F2,a_L3); return;
a_G5:a_1009(a_F1,a_F2,0);
a_1075(); return;
} /* ftableaffix */
static void a_1042(int a_F1,int a_F2){ /* fstackaffix+>a+>a */
int a_L3;int a_L4;int a_P[1];
if(!a_1005(a_P)){ goto a_G8;}a_L3=a_P[0];
a_1741(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777250){ goto a_G4;}
 if(a_L4==16777277){ goto a_G7;}
 if(a_L4==16777244){ goto a_G6;}
  goto a_G5;}
a_G4:if(!a_1746(a_L3,8)){ goto a_G6;}
a_G5:a_1009(a_F1,a_F2,a_L3); return;
a_G6:a_1013(a_F1,a_F2,a_L3); return;
a_G7:a_1068(a_L3,8); goto a_G6;
a_G8:a_1009(a_F1,a_F2,0);
a_1075(); return;
} /* fstackaffix */
static void a_1040(int a_F1){ /* fshiftaffix+>a */
int a_L2;int a_L3;int a_P[2];
if(!a_1005(a_P)){ goto a_G5;}a_L2=a_P[0];
a_1741(a_L2,a_P);a_L3=a_P[0];
if(a_equal(a_L3,16777310)){ return;}
a_P[0]=2130703783;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
a_G5:a_P[0]=2130703783;a_P[1]=a_F1;a_1238(-1,2,a_P);
a_1075(); return;
} /* fshiftaffix */
static int a_1080(int a_F1){ /* ureadonly+>a */

if(!a_mreq(a_F1,4530946)){ return 0;} return 1;
} /* ureadonly */
static void a_1082(int a_F1,int a_A[1]){ /* uslicetype+>a+a> */

{ if(!(a_F1==4530944||a_F1==4530948)){ goto a_G3;}
}
a_A[0]=4530948; return;
a_G3:a_A[0]=4530947; return;
} /* uslicetype */
static void a_1058(int a_F1,int a_F2,int a_F3){ /* pushBUFFER+>a+>a+>a */

a_1036(a_F1);
a_1036(a_F2);
a_1036(a_F3); return;
} /* pushBUFFER */
static void a_1017(int a_F1,int a_F2){ /* checkoutaffixes+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[1];
a_G1:if(a_mreq(a_F2,to_LIST(a_1150)->aupb)){ return;}
a_incr(a_F2);
a_L3=to_LIST(a_1150)->offset[a_F2];
a_incr(a_F2);
a_L4=to_LIST(a_1150)->offset[a_F2];
a_incr(a_F2);
a_L5=to_LIST(a_1150)->offset[a_F2];
if(!a_equal(a_L3,4530948)){ goto a_G11;}
if(a_1049(a_L5,2)){ goto a_G1;}
a_1010(a_F1,a_L4,a_L5); goto a_G1;
a_G11:a_1068(a_L5,2);
a_1741(a_L5,a_P);a_L6=a_P[0];
if(a_equal(a_L6,16777331)){ goto a_G1;}
a_1068(a_L5,8); goto a_G1;
} /* checkoutaffixes */
static void a_1044(int a_F1,int a_A[1]){ /* getftype+>a+a> */
int a_P[1];
a_1741(a_F1,a_P);a_A[0]=a_P[0];
if(!a_equal(a_A[0],16777250)){ goto a_G6;}
if(!a_1746(a_F1,8)){ goto a_G5;}
a_A[0]=16777240; return;
a_G5:a_A[0]=16777244; return;
a_G6:if(!a_equal(a_A[0],16777236)){ return;}
if(!a_1746(a_F1,8)){ goto a_G9;}
a_A[0]=16777226; return;
a_G9:a_A[0]=16777231; return;
} /* getftype */
static void a_1041(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* fsimpleaffix+>a+>a+>a+a> */
int a_L5;int a_L6;int a_L7;int a_P[4];
if(!a_1172(a_P)){ goto a_G5;}
a_A[0]=0;
if(a_equal(a_F3,4530946)){ return;}
a_1031(a_F1,a_F2); return;
a_G5:if(a_1164(1696719039)){ goto a_G9;}
if(a_1164(1696719043)){ goto a_G9;}
if(a_1164(1696718957)){ goto a_G9;}
if(!a_1164(1696719035)){ goto a_G15;}
a_G9:a_A[0]=0;
a_1055(a_P);a_L5=a_P[0];
if(a_1047(a_L5)){ goto a_G13;}
a_1056(a_F1,a_F2,a_L5);
a_G13:if(a_1080(a_F3)){ return;}
a_G14:a_1033(a_F1,a_F2,a_L5); return;
a_G15:if(!a_1164(1696718876)){ goto a_G21;}
a_A[0]=0;
a_1055(a_P);a_L5=a_P[0];
if(a_1047(a_L5)){ goto a_G20;}
a_1056(a_F1,a_F2,a_L5);
a_G20:if(a_equal(a_F3,4530946)){ return;} goto a_G14;
a_G21:if(!a_1164(1696719027)){ goto a_G37;}
a_1055(a_P);a_L5=a_P[0];
a_1082(a_F3,a_P);a_L6=a_P[0];
a_1041(a_F1,a_F2,a_L6,a_P);a_A[0]=a_P[0];
a_1196(1696718871);
a_1061(a_F1,a_F2,a_L5,a_P);
a_1044(a_L5,a_P);a_L6=a_P[0];
{ if(a_L6==16777240||a_L6==16777283){ goto a_G29;}
 if(a_L6==16777244){ goto a_G31;}
 if(a_L6==16777277){ goto a_G33;}
  goto a_G36;}
a_G29:if(a_1080(a_F3)){ return;}
a_G30:a_1034(a_F1,a_F2,a_L5); return;
a_G31:if(a_1080(a_F3)){ return;}
a_A[0]=1; return;
a_G33:if(a_1080(a_F3)){ return;}
a_A[0]=1;
a_G35:a_1068(a_L5,8); return;
a_G36:a_1056(a_F1,a_F2,a_L5); return;
a_G37:if(!a_1164(1696718972)){ goto a_G41;}
a_A[0]=0;
if(a_equal(a_F3,4530944)){ return;}
a_1035(a_F1,a_F2); return;
a_G41:a_A[0]=0;
a_1200(a_P);a_L5=a_P[0];
a_1044(a_L5,a_P);a_L6=a_P[0];
if(!a_was(a_1719,a_L5)){ goto a_G47;}
if(a_equal(a_F3,4530944)){ goto a_G47;}
a_1068(a_L5,1);
a_G47:{ if(a_L6==16777240||a_L6==16777283){ goto a_G48;}
 if(a_L6==16777244){ goto a_G49;}
 if(a_L6==16777277){ goto a_G50;}
 if(a_L6==16777226){ goto a_G55;}
 if(a_L6==16777257){ goto a_G29;}
 if(a_L6==16777231){ goto a_G31;}
 if(a_L6==16777293){ goto a_G59;}
 if(a_L6==16777304){ goto a_G65;}
 if(a_L6==16777298||a_L6==16777331){ goto a_G66;}
  goto a_G73;}
a_G48:a_1019(a_F1,a_F2,a_L5); goto a_G29;
a_G49:a_1019(a_F1,a_F2,a_L5); goto a_G31;
a_G50:a_1019(a_F1,a_F2,a_L5);
if(a_1080(a_F3)){ return;}
a_A[0]=1;
a_1068(a_L5,8);
a_1068(a_L5,1); return;
a_G55:if(a_equal(a_F3,4530946)){ return;}
if(!a_1080(a_F3)){ goto a_G30;}
a_1083(a_F1,a_F2,a_P);a_L7=a_P[0];
a_P[0]=2130703744;a_P[1]=a_L7;a_P[2]=a_F1;a_P[3]=a_L5;a_1240(2,-1,4,a_P); return;
a_G59:if(a_1080(a_F3)){ return;}
a_1068(a_L5,8);
if(!a_1746(a_1066,128)){ goto a_G63;}
a_P[0]=2130703798;a_P[1]=a_F1;a_P[2]=a_L5;a_1238(-1,3,a_P); return;
a_G63:if(!a_1049(a_L5,4096)){ return;}
a_P[0]=2130703814;a_P[1]=a_F1;a_P[2]=a_L5;a_1238(-1,3,a_P); return;
a_G65:if(a_1080(a_F3)){ return;} goto a_G35;
a_G66:if(a_equal(a_F3,4530944)){ goto a_G68;}
if(!a_equal(a_F3,4530948)){ goto a_G69;}
a_G68:a_1058(a_F3,a_F2,a_L5); return;
a_G69:if(a_1049(a_L5,2)){ goto a_G71;}
a_1010(a_F1,a_F2,a_L5);
a_G71:if(a_1080(a_F3)){ return;}
if(a_equal(a_L6,16777331)){ return;} goto a_G35;
a_G73:a_1009(a_F1,a_F2,a_L5); return;
} /* fsimpleaffix */
static void a_1050(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* matchformalactual+>a+>a+>a+a> */
int a_P[1];
{ if(a_F3==16777288){ goto a_G2;}
 if(a_F3==16777283){ goto a_G4;}
 if(a_F3==16777277){ goto a_G5;}
 if(a_F3==16777316){ goto a_G7;}
 if(a_F3==16777293){ goto a_G8;}
 if(a_F3==16777298){ goto a_G9;}
 if(a_F3==16777304){ goto a_G10;}
  goto a_G11;}
a_G2:a_1039(a_F1,a_F2);
a_G3:a_A[0]=0; return;
a_G4:a_1043(a_F1,a_F2); goto a_G3;
a_G5:a_1042(a_F1,a_F2);
a_A[0]=1; return;
a_G7:a_1040(a_F1); goto a_G3;
a_G8:a_1041(a_F1,a_F2,4530946,a_P);a_A[0]=a_P[0]; return;
a_G9:a_1041(a_F1,a_F2,4530944,a_P);a_A[0]=a_P[0]; return;
a_G10:a_1041(a_F1,a_F2,4530945,a_P);a_A[0]=a_P[0]; return;
a_G11:a_1248(a_1001,2130705920); return;
} /* matchformalactual */
static int a_1028(int a_F1,int a_F2){ /* compatiblerepeatblocktypes+>a+>a */

if(a_equal(a_F2,a_F1)){ return 1;}
if(!a_equal(a_F2,16777283)){ goto a_G4;}
if(!a_equal(a_F1,16777277)){ return 0;} return 1;
a_G4:if(!a_equal(a_F2,16777293)){ goto a_G6;}
a_G5:if(!a_equal(a_F1,16777304)){ return 0;} return 1;
a_G6:if(!a_equal(a_F2,16777298)){ return 0;} goto a_G5;
} /* compatiblerepeatblocktypes */
static void a_1051(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* matchrepeataffixes+>a+>a+>a+>a> */
int a_L5;int a_L6;int a_L7;int a_L8;int a_P[6];
a_1731(a_F1,a_P);a_L5=a_P[0];
a_1730(a_F1,a_P);a_L8=a_P[0];
a_G3:a_incr(a_F3);
a_next(a_1719,a_F2);
a_1741(a_F2,a_P);a_L6=a_P[0];
if(!a_more(a_F3,a_L5)){ goto a_G9;}
if(a_equal(a_L6,16777335)){ return;}
a_G8:a_P[0]=2130703827;a_P[1]=a_F1;a_P[2]=a_L8;a_1238(-1,3,a_P); return;
a_G9:if(a_equal(a_L6,16777335)){ goto a_G8;}
a_1733(a_F1,a_F3,a_P);a_L7=a_P[0];
if(!a_1028(a_L6,a_L7)){ goto a_G21;}
a_1068(a_F2,1);
if(!a_equal(a_L7,16777277)){ goto a_G16;}
a_A[0]=1;
a_G15:a_1068(a_F2,8); goto a_G3;
a_G16:if(!a_equal(a_L6,16777298)){ goto a_G19;}
a_1068(a_F2,8);
a_1068(a_F2,2); goto a_G3;
a_G19:if(a_equal(a_L7,16777298)){ goto a_G15;}
if(a_equal(a_L7,16777304)){ goto a_G15;} goto a_G3;
a_G21:a_P[0]=2130703846;a_P[1]=a_F1;a_P[2]=a_L6;a_P[3]=a_F2;a_P[4]=a_L7;a_P[5]=a_L8;a_1238(-1,6,a_P); return;
} /* matchrepeataffixes */
static int a_1006(int a_F1,int a_F2,int a_A[1]){ /* actualanchoraffix+>a+>a+>a> */
int a_L4;int a_L5;int a_L6;int a_L7;int a_P[2];
a_1211(a_P);a_L4=a_P[0];a_L5=a_P[1];
if(!a_1164(1696718988)){ goto a_G11;}
if(!a_1171(a_P)){ goto a_G11;}a_L6=a_P[0];
a_1741(a_L6,a_P);a_L7=a_P[0];
if(!a_equal(a_L7,16777310)){ goto a_G11;}
a_1068(a_L6,1);
a_1068(a_L6,2);
if(a_1049(a_L6,8)){ goto a_G10;}
a_P[0]=2130703606;a_P[1]=a_F1;a_1240(6,-1,2,a_P);
a_G10:a_P[0]=a_A[0];a_1051(a_F1,a_L6,a_F2,a_P);a_A[0]=a_P[0]; return 1;
a_G11:a_1209(a_L4,a_L5); return 0;
} /* actualanchoraffix */
static void a_1016(int a_F1){ /* checkmacrorule+>a */
int a_P[2];
if(!a_1746(a_1066,128)){ return;}
if(!a_equal(a_F1,a_1066)){ goto a_G4;}
a_P[0]=2130703859;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
a_G4:if(!a_1746(a_F1,131072)){ return;}
a_P[0]=2130703869;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
} /* checkmacrorule */
static void a_1007(int a_A[3]){ /* actualrule+a>+a>+>a> */
int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_L10;int a_L11;int a_P[3];
a_A[0]=1;a_A[1]=1;
a_1200(a_P);a_L4=a_P[0];
a_1730(a_L4,a_P);a_L10=a_P[0];
a_1016(a_L4);
if(!a_equal(a_L4,16777861)){ goto a_G7;}
a_1064(a_L4);
a_G7:if(!a_1746(a_L4,1024)){ goto a_G9;}
a_A[0]=0;
a_G9:if(a_1746(a_L4,512)){ goto a_G11;}
a_A[1]=0;
a_G11:if(!a_1746(a_L4,256)){ goto a_G13;}
a_A[2]=1;
a_G13:a_1731(a_L4,a_P);a_L7=a_P[0];
a_L8=1;
a_L6=0;
a_L11=to_LIST(a_1150)->aupb;
a_G17:if(!a_more(a_L8,a_L7)){ goto a_G25;}
if(!a_1166(1696718988)){ goto a_G34;}
if(!a_equal(a_L6,0)){ goto a_G22;}
a_P[0]=2130703881;a_P[1]=a_L4;a_P[2]=a_L10;a_1238(-1,3,a_P);
a_1074(); goto a_G34;
a_G22:a_P[0]=a_A[2];if(a_1006(a_L4,a_L6,a_P)){a_A[2]=a_P[0]; goto a_G34;}
a_L8=a_L6;
a_G24:a_incr(a_L8); goto a_G17;
a_G25:a_1733(a_L4,a_L8,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,16777310)){ goto a_G29;}
a_P[0]=a_A[2];if(a_1006(a_L4,a_L8,a_P)){a_A[2]=a_P[0]; goto a_G34;}
a_L6=a_L8; goto a_G24;
a_G29:if(!a_1164(1696718988)){ goto a_G33;}
a_1050(a_L4,a_L8,a_L5,a_P);a_L9=a_P[0];
if(!a_is(a_L9)){ goto a_G24;}
a_A[2]=1; goto a_G24;
a_G33:a_P[0]=2130703892;a_P[1]=a_L4;a_P[2]=a_L10;a_1238(-1,3,a_P);
a_G34:a_1017(a_L4,a_L11);
a_unstackto(a_1150,a_L11); return;
} /* actualrule */
static void a_1014(int a_F1,int a_F2){ /* checkextensionblock+>a+>a */
int a_L3;int a_L4;int a_L5;int a_P[4];
a_L3=to_LIST(a_1150)->aupb;
a_L5=0;
if(!a_equal(to_LIST(a_1150)->offset[a_L3],0)){ goto a_G5;}
a_G4:a_P[0]=2130703927;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
a_G5:if(a_lseq(a_F2,a_L5)){ goto a_G9;}
if(a_equal(to_LIST(a_1150)->offset[a_L3],0)){ goto a_G9;}
a_decr(a_L3);
a_incr(a_L5); goto a_G5;
a_G9:a_L4=a_L5;
a_G10:if(a_lseq(a_F2,a_L5)){ goto a_G14;}
if(!a_equal(to_LIST(a_1150)->offset[a_L3],0)){ goto a_G14;}
a_decr(a_L3);
a_incr(a_L5); goto a_G10;
a_G14:if(a_less(a_L5,a_F2)){ goto a_G4;}
if(!a_less(a_L4,a_L5)){ return;}
a_P[0]=2130703944;a_P[1]=a_F1;a_P[2]=a_L4;a_P[3]=a_F2;a_1240(4,-1,4,a_P); return;
} /* checkextensionblock */
static void a_1079(int a_F1,int a_F2){ /* transportdest+>a+>a */
int a_L3;int a_L4;int a_P[3];
a_1061(a_F1,0,a_F1,a_P);a_L3=a_P[0];
if(a_lseq(a_L3,0)){ return;}
a_subtr(a_F2,a_L3,a_L3);
a_subtr(to_LIST(a_1150)->aupb,a_L3,a_L4);
if(!a_equal(to_LIST(a_1150)->offset[a_L4],0)){ goto a_G7;}
to_LIST(a_1150)->offset[a_L4]=1; return;
a_G7:a_P[0]=2130703915;a_P[1]=a_F1;a_P[2]=a_L3;a_1238(-1,3,a_P); return;
} /* transportdest */
static void a_1078(int a_F1,int a_F2){ /* transport+>a+>a */
int a_L3;int a_L4;int a_L5;int a_P[1];
if(a_more(a_F2,0)){ goto a_G3;}
a_F2=1;
a_G3:a_L3=to_LIST(a_1150)->aupb;
a_L4=a_F2;
a_G5:a_1036(0);
a_decr(a_L4);
if(a_more(a_L4,0)){ goto a_G5;}
a_1241(a_P);a_L5=a_P[0];
a_G9:a_1041(a_F1,0,4530946,a_P);
a_G10:if(!a_1164(1696719031)){ goto a_G12;}
a_1079(a_F1,a_F2); goto a_G10;
a_G12:if(a_1164(1696718892)){ goto a_G9;}
a_1196(1696718915);
if(a_1275(a_L5)){ goto a_G16;}
a_1014(a_F1,a_F2);
a_G16:a_unstackto(a_1150,a_L3); return;
} /* transport */
static void a_1038(void){ /* extension */
int a_L1;int a_L2;int a_L3;int a_P[3];
a_1055(a_P);a_L1=a_P[0];
a_1741(a_L1,a_P);a_L2=a_P[0];
{ if(a_L2==16777250){ goto a_G4;}
 if(a_L2==16777244){ goto a_G6;}
 if(a_L2==16777277){ goto a_G8;}
  goto a_G11;}
a_G4:if(!a_1746(a_L1,8)){ goto a_G6;}
a_P[0]=2130703903;a_P[1]=a_L1;a_P[2]=a_L2;a_1238(-1,3,a_P); return;
a_G6:a_1677(a_L1,a_P);a_L3=a_P[0];
a_1078(a_L1,a_L3); return;
a_G8:a_1045(a_L1,a_P);a_L3=a_P[0];
a_1078(a_L1,a_L3);
a_1068(a_L1,8); return;
a_G11:a_P[0]=2130703903;a_P[1]=a_L1;a_P[2]=a_L2;a_1238(-1,3,a_P);
a_1176(1696718915); return;
} /* extension */
static void a_1060(void){ /* readbox */
int a_P[1];
a_1041(0,0,4530946,a_P);
a_1196(1696718868); return;
} /* readbox */
static void a_1021(int a_F1,int a_F2){ /* checkzonemember+>a+>a */
int a_L3;int a_L4;int a_P[4];
if(a_equal(a_F1,0)){ return;}
a_1741(a_F1,a_P);a_L3=a_P[0];
a_1730(a_F1,a_P);a_L4=a_P[0];
if(!a_1746(a_F1,16)){ goto a_G6;}
a_P[0]=2130703957;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
a_G6:if(a_equal(a_L3,16777226)){ return;}
if(a_equal(a_L3,16777257)){ return;}
if(!a_is(a_F2)){ goto a_G12;}
if(a_equal(a_L3,16777240)){ return;}
if(a_equal(a_L3,16777244)){ return;}
if(a_equal(a_L3,16777250)){ return;}
a_G12:a_P[0]=2130703968;a_P[1]=a_F1;a_P[2]=a_L3;a_P[3]=a_L4;a_1238(-1,4,a_P); return;
} /* checkzonemember */
static void a_1020(int a_F1,int a_F2){ /* checkzoneinterval+>a+>a */

a_1021(a_F1,0);
a_1021(a_F2,0); return;
} /* checkzoneinterval */
static void a_1023(int a_A[1]){ /* classifier+>a> */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_G1:a_L2=0;a_L3=0;a_L4=0;
if(a_1172(a_P)){ goto a_G5;}
if(a_1179(a_P)){a_L2=a_P[0]; goto a_G5;}
a_incr(a_L4);
a_G5:if(!a_1164(1696718885)){ goto a_G10;}
if(a_1172(a_P)){ goto a_G9;}
if(a_1179(a_P)){a_L3=a_P[0]; goto a_G9;}
a_incr(a_L4);
a_G9:a_1020(a_L2,a_L3); goto a_G11;
a_G10:a_1021(a_L2,1);
a_G11:if(a_less(a_L4,2)){ goto a_G13;}
a_A[0]=1;
a_G13:if(a_1164(1696719016)){ goto a_G1;}
a_1196(1696718860); return;
} /* classifier */
static void a_1022(int a_F1,int a_A[6]){ /* classification+>a+a>+a>+>a>+a>+a>+a> */
int a_L8;int a_L9;int a_L10;int a_L11;int a_L12;int a_L13;int a_L14;int a_L15;int a_P[6];
a_A[0]=0;a_A[1]=0;a_A[4]=0;a_A[5]=0;
a_A[3]=0;
a_L15=a_A[2];
a_G4:a_L14=0;
a_1196(1696718860);
a_P[0]=a_L14;a_1023(a_P);a_L14=a_P[0];
a_L8=1;
a_L12=0;
a_L10=a_L15;
a_1024(a_F1,65536);
a_P[0]=a_L8;a_P[2]=a_L10;a_P[4]=a_L12;a_1012(a_F1,a_P);a_L8=a_P[0];a_L9=a_P[1];a_L10=a_P[2];a_L11=a_P[3];a_L12=a_P[4];a_L13=a_P[5];
if(!a_is(a_L8)){ goto a_G15;}
a_A[0]=1;
a_max(a_L10,a_A[2]);
a_G15:if(!a_is(a_L9)){ goto a_G18;}
a_A[1]=1;
a_max(a_L11,a_A[3]);
a_G18:if(a_equal(a_L12,0)){ goto a_G23;}
if(a_lseq(a_F1,a_L12)){ goto a_G23;}
if(!a_equal(a_A[4],0)){ goto a_G22;}
a_A[4]=a_L12; goto a_G23;
a_G22:a_min(a_L12,a_A[4]);
a_G23:if(a_equal(a_L13,0)){ goto a_G28;}
if(a_lseq(a_F1,a_L13)){ goto a_G28;}
if(!a_equal(a_A[5],0)){ goto a_G27;}
a_A[5]=a_L13; goto a_G28;
a_G27:a_min(a_L13,a_A[5]);
a_G28:a_1053(a_F1,a_L8,a_L9);
if(!a_1164(1696719016)){ return;}
a_1070(a_F1);
if(!a_is(a_L14)){ goto a_G4;}
a_P[0]=2130703978;a_1238(-1,1,a_P); goto a_G4;
} /* classification */
static void a_1030(int a_A[6]){ /* compoundmember+a>+a>+>a>+a>+a>+a> */
int a_P[6];
a_incr(a_1029);
a_P[2]=a_A[2];a_1065(a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2];a_A[3]=a_P[3];a_A[4]=a_P[4];a_A[5]=a_P[5];
a_1196(1696718882);
a_decr(a_1029); return;
} /* compoundmember */
static void a_1052(int a_F1,int a_A[6]){ /* member+>a+a>+a>+>a>+a>+a>+a> */
int a_L8;int a_P[6];
a_A[4]=0;a_A[5]=0;a_A[1]=0;
a_A[0]=1;
a_A[3]=a_A[2];
if(!a_1164(1696718979)){ goto a_G6;}
a_P[2]=a_A[2];a_1030(a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2];a_A[3]=a_P[3];a_A[4]=a_P[4];a_A[5]=a_P[5]; return;
a_G6:if(!a_1164(1696718915)){ goto a_G10;}
a_1038();
a_A[2]=1;
a_G9:a_1067(a_F1,65536); return;
a_G10:if(!a_1164(1696718941)){ goto a_G15;}
a_1055(a_P);a_L8=a_P[0];
a_A[0]=0;
a_1015(a_L8);
a_1069(a_A[2],to_LIST(a_1719)->offset[a_L8-1],a_P);a_A[4]=a_P[0];a_A[5]=a_P[1]; return;
a_G15:if(a_1164(1696718988)){ return;}
if(!a_1164(1696718964)){ goto a_G20;}
a_1032();
a_A[1]=1;
a_A[0]=0; return;
a_G20:a_1032();
a_P[2]=a_A[2];a_1007(a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2]; goto a_G9;
} /* member */
static void a_1012(int a_F1,int a_A[6]){ /* alttail+>a+>a>+a>+>a>+a>+>a>+a> */
int a_L8;int a_L9;int a_L10;int a_L11;int a_P[6];
a_A[1]=0;a_A[3]=0;
a_L9=a_A[2];
a_A[5]=0;
a_1026(a_F1);
a_G5:if(!a_1164(1696718892)){ goto a_G26;}
if(!a_equal(a_A[0],0)){ goto a_G9;}
a_L9=0;
a_P[0]=2130703987;a_1238(-1,1,a_P);
a_G9:if(a_equal(a_A[4],0)){ goto a_G13;}
if(a_less(a_F1,a_A[4])){ goto a_G13;}
a_next(a_1151,a_A[4]);
a_P[0]=2130703995;a_P[1]=to_LIST(a_1151)->offset[a_A[4]];a_1238(-1,2,a_P);
a_G13:a_P[2]=a_L9;a_1052(a_F1,a_P);a_A[0]=a_P[0];a_L8=a_P[1];a_L9=a_P[2];a_L10=a_P[3];a_A[4]=a_P[4];a_L11=a_P[5];
if(!a_is(a_A[0])){ goto a_G17;}
if(!a_is(a_L9)){ goto a_G17;}
a_A[2]=1;
a_G17:if(!a_is(a_L8)){ goto a_G21;}
a_max(a_L10,a_A[3]);
a_1054(a_F1);
a_A[1]=1;
a_G21:if(a_equal(a_L11,0)){ goto a_G5;}
if(a_less(a_F1,a_L11)){ goto a_G5;}
if(!a_equal(a_A[5],0)){ goto a_G25;}
a_A[5]=a_L11; goto a_G5;
a_G25:a_min(a_L11,a_A[5]); goto a_G5;
a_G26:if(!a_is(a_A[1])){ return;}
a_1081(a_F1); return;
} /* alttail */
static void a_1011(int a_F1,int a_A[6]){ /* altsequence+>a+a>+a>+>a>+a>+a>+a> */
int a_L8;int a_L9;int a_L10;int a_L11;int a_L12;int a_L13;int a_L14;int a_L15;int a_L16;int a_P[6];
a_A[0]=0;a_A[1]=0;a_A[4]=0;a_A[5]=0;
a_A[3]=0;
a_L15=a_A[2];
a_G4:a_L10=a_L15;
a_P[2]=a_L10;a_1052(a_F1,a_P);a_L8=a_P[0];a_L14=a_P[1];a_L10=a_P[2];a_L11=a_P[3];a_L12=a_P[4];a_L16=a_P[5];
if(!a_is(a_L14)){ goto a_G9;}
a_L15=a_L11;
a_1076(a_F1);
a_G9:a_P[0]=a_L8;a_P[2]=a_L10;a_P[4]=a_L12;a_1012(a_F1,a_P);a_L8=a_P[0];a_L9=a_P[1];a_L10=a_P[2];a_L11=a_P[3];a_L12=a_P[4];a_L13=a_P[5];
if(!a_is(a_L8)){ goto a_G13;}
a_A[0]=1;
a_max(a_L10,a_A[2]);
a_G13:if(!a_is(a_L9)){ goto a_G16;}
a_A[1]=1;
a_max(a_L11,a_A[3]);
a_G16:if(a_equal(a_L12,0)){ goto a_G21;}
if(a_lseq(a_F1,a_L12)){ goto a_G21;}
if(!a_equal(a_A[4],0)){ goto a_G20;}
a_A[4]=a_L12; goto a_G21;
a_G20:a_min(a_L12,a_A[4]);
a_G21:if(a_equal(a_L13,0)){ goto a_G26;}
if(a_lseq(a_F1,a_L13)){ goto a_G26;}
if(!a_equal(a_A[5],0)){ goto a_G25;}
a_A[5]=a_L13; goto a_G26;
a_G25:a_min(a_L13,a_A[5]);
a_G26:a_1053(a_F1,a_L8,a_L9);
if(!a_is(a_L14)){ goto a_G29;}
a_1070(a_F1);
a_G29:if(!a_1164(1696719016)){ goto a_G36;}
if(a_is(a_L14)){ goto a_G32;}
a_P[0]=2130703978;a_1238(-1,1,a_P);
a_G32:if(a_equal(a_L16,0)){ goto a_G4;}
if(a_less(a_F1,a_L16)){ goto a_G4;}
a_next(a_1151,a_L16);
a_P[0]=2130703995;a_P[1]=to_LIST(a_1151)->offset[a_L16];a_1238(-1,2,a_P); goto a_G4;
a_G36:if(a_equal(a_L16,0)){ goto a_G41;}
if(a_lseq(a_F1,a_L16)){ goto a_G41;}
if(!a_equal(a_A[5],0)){ goto a_G40;}
a_A[5]=a_L16; goto a_G41;
a_G40:a_min(a_L16,a_A[5]);
a_G41:if(!a_is(a_L14)){ return;}
a_A[1]=1;
a_max(a_L15,a_A[3]);
a_1032();
a_1053(a_F1,0,1); return;
} /* altsequence */
static void a_1065(int a_A[6]){ /* rulebody+a>+a>+>a>+a>+a>+a> */
int a_L7;int a_L8;int a_L9;int a_L10;int a_L11;int a_L12;int a_P[6];
a_L7=to_LIST(a_1719)->aupb;
a_1072(a_P);a_L8=a_P[0];
a_1073();
a_1057(a_A[2]);
a_L9=to_LIST(a_1151)->aupb;
a_1008(a_L8,a_L9);
a_1211(a_P);a_L10=a_P[0];a_L11=a_P[1];
a_G8:a_1241(a_P);a_L12=a_P[0];
if(!a_1164(1696718868)){ goto a_G12;}
a_1060();
a_P[2]=a_A[2];a_1022(a_L9,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2];a_A[3]=a_P[3];a_A[4]=a_P[4];a_A[5]=a_P[5]; goto a_G13;
a_G12:a_P[2]=a_A[2];a_1011(a_L9,a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];a_A[2]=a_P[2];a_A[3]=a_P[3];a_A[4]=a_P[4];a_A[5]=a_P[5];
a_G13:if(a_1275(a_L12)){ goto a_G16;}
if(!a_1063(a_L9,a_A[0],a_A[1],a_P)){ goto a_G16;}a_A[2]=a_P[0];
a_1209(a_L10,a_L11); goto a_G8;
a_G16:a_1027(a_L9);
if(a_is(a_A[0])){ goto a_G19;}
a_A[2]=0;
a_G19:if(a_is(a_A[1])){ goto a_G21;}
a_A[3]=0;
a_G21:if(a_lseq(to_LIST(a_1719)->aupb,a_L7)){ return;}
if(a_1049(to_LIST(a_1719)->aupb,1)){ goto a_G27;}
if(!a_equal(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2],16777335)){ goto a_G26;}
if(a_equal(a_1029,0)){ goto a_G27;}
a_P[0]=2130704011;a_P[1]=to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb];a_1240(4,-1,2,a_P); goto a_G27;
a_G26:a_P[0]=2130704004;a_P[1]=to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb];a_1240(4,-1,2,a_P);
a_G27:a_unstack(a_1719); goto a_G21;
} /* rulebody */
static void a_1018(int a_F1){ /* checkruledataflow+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[6];
a_scratch(a_1151);
a_1029=0;
a_1066=a_F1;
a_1071(a_F1);
a_1077(a_F1);
a_L4=0;
a_P[2]=a_L4;a_1065(a_P);a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];a_L5=a_P[3];
if(!a_equal(a_F1,16777853)){ goto a_G16;}
if(a_1489(22021)){ goto a_G42;}
if(!a_1746(a_F1,16384)){ goto a_G13;}
if(a_1489(22021)){ goto a_G42;}
a_P[0]=2130704019;a_1238(-1,1,a_P); goto a_G42;
a_G13:if(!a_equal(a_L2,0)){ goto a_G42;}
if(!a_equal(a_L3,0)){ goto a_G42;}
a_P[0]=2130704026;a_1240(4,-1,1,a_P); goto a_G42;
a_G16:if(!a_1746(a_F1,1024)){ goto a_G20;}
if(a_is(a_L2)){ goto a_G19;}
if(!a_is(a_L3)){ goto a_G42;}
a_G19:a_P[0]=2130704036;a_P[1]=a_F1;a_1238(-1,2,a_P); goto a_G42;
a_G20:if(a_is(a_L2)){ goto a_G23;}
a_L4=0;
a_P[0]=2130704044;a_P[1]=a_F1;a_1238(-1,2,a_P);
a_G23:if(!a_is(a_L3)){ goto a_G26;}
if(a_1746(a_F1,512)){ goto a_G29;}
a_P[0]=2130704051;a_P[1]=a_F1;a_1238(-1,2,a_P); goto a_G29;
a_G26:a_L5=0;
if(!a_1746(a_F1,512)){ goto a_G29;}
a_P[0]=2130704059;a_P[1]=a_F1;a_1240(6,-1,2,a_P);
a_G29:if(!a_is(a_L4)){ goto a_G32;}
if(a_1746(a_F1,256)){ goto a_G38;}
a_P[0]=2130704069;a_P[1]=a_F1;a_1238(-1,2,a_P); goto a_G38;
a_G32:if(a_equal(a_L2,0)){ goto a_G38;}
if(a_1746(a_F1,8192)){ goto a_G38;}
if(!a_1746(a_F1,16384)){ goto a_G36;}
a_P[0]=2130704077;a_P[1]=a_F1;a_1240(4,-1,2,a_P); goto a_G38;
a_G36:if(!a_1746(a_F1,256)){ goto a_G38;}
a_P[0]=2130704088;a_P[1]=a_F1;a_1240(6,-1,2,a_P);
a_G38:if(!a_is(a_L5)){ goto a_G42;}
if(!a_1746(a_F1,256)){ goto a_G41;}
a_P[0]=2130704111;a_P[1]=a_F1;a_1240(5,-1,2,a_P); goto a_G42;
a_G41:a_P[0]=2130704111;a_P[1]=a_F1;a_1238(-1,2,a_P);
a_G42:if(a_1746(a_F1,256)){ goto a_G46;}
if(a_1746(a_F1,1024)){ goto a_G46;}
if(!a_1746(a_F1,8192)){ goto a_G46;}
a_P[0]=2130704097;a_P[1]=a_F1;a_1240(5,-1,2,a_P);
a_G46:if(a_less(to_LIST(a_1719)->aupb,to_LIST(a_1719)->alwb)){ goto a_G81;}
if(a_equal(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2],16777316)){ goto a_G80;}
a_L7=to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb];
if(a_1049(to_LIST(a_1719)->aupb,1)){ goto a_G54;}
if(a_equal(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2],16777298)){ goto a_G54;}
if(!a_equal(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2],16777304)){ goto a_G53;}
a_P[0]=2130704122;a_P[1]=a_F1;a_P[2]=a_L7;a_1240(2,-1,3,a_P); goto a_G54;
a_G53:a_P[0]=2130704122;a_P[1]=a_F1;a_P[2]=a_L7;a_1240(5,-1,3,a_P);
a_G54:{register int a_r1=to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2];
 if(a_r1==16777310){ goto a_G55;}
 if(a_r1==16777277){ goto a_G61;}
 if(a_r1==16777293){ goto a_G64;}
 if(a_r1==16777298){ goto a_G67;}
 if(a_r1==16777304){ goto a_G70;}
  goto a_G73;}
a_G55:a_L6=0;
if(a_1049(to_LIST(a_1719)->aupb,2)){ goto a_G74;}
if(!a_1049(to_LIST(a_1719)->aupb,8)){ goto a_G74;}
a_P[0]=2130704136;a_P[1]=a_F1;a_1240(4,-1,2,a_P);
if(!a_1746(a_F1,65536)){ goto a_G74;}
a_P[0]=2130704196;a_P[1]=a_F1;a_1238(-1,2,a_P); goto a_G74;
a_G61:a_L6=0;
if(a_1049(to_LIST(a_1719)->aupb,8)){ goto a_G74;}
a_P[0]=2130704150;a_P[1]=a_F1;a_P[2]=a_L7;a_1240(3,-1,3,a_P); goto a_G74;
a_G64:a_L6=a_L3;
if(!a_1049(to_LIST(a_1719)->aupb,8)){ goto a_G74;}
a_P[0]=2130704165;a_P[1]=a_F1;a_P[2]=a_L7;a_1240(2,-1,3,a_P); goto a_G74;
a_G67:a_L6=a_L3;
if(a_1049(to_LIST(a_1719)->aupb,2)){ goto a_G74;}
a_P[0]=2130704180;a_P[1]=a_F1;a_P[2]=a_L7;a_1238(-1,3,a_P); goto a_G74;
a_G70:a_L6=a_L3;
if(a_1049(to_LIST(a_1719)->aupb,8)){ goto a_G74;}
a_P[0]=2130704209;a_P[1]=a_F1;a_P[2]=a_L7;a_1240(3,-1,3,a_P); goto a_G74;
a_G73:a_L6=0;
a_G74:if(!a_is(a_L6)){ goto a_G80;}
if(!a_1049(to_LIST(a_1719)->aupb,16)){ goto a_G80;}
if(!a_1746(a_F1,128)){ goto a_G78;}
a_L8=9; goto a_G79;
a_G78:a_L8=2;
a_G79:a_P[0]=2130704224;a_P[1]=a_F1;a_P[2]=a_L7;a_1240(a_L8,-1,3,a_P);
a_G80:a_unstack(a_1719); goto a_G46;
a_G81:a_1196(1696718991); return;
} /* checkruledataflow */
static void a_1077(int a_F1){ /* storemacro+>a */
int a_L2;int a_L3;int a_P[2];
if(!a_1746(a_F1,1)){ return;}
if(!a_1746(a_F1,128)){ return;}
a_1211(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1747(a_F1,a_L2,a_L3); return;
} /* storemacro */
static void a_1036(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1150,1);a_r1[0]=a_F1;to_LIST(a_1150)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1037(int a_F1,int a_F2){ /* extendRULE+>a+>a */

{register int *a_r1=a_extension(a_1151,2);a_r1[0]=a_F1;a_r1[1]=a_F2;to_LIST(a_1151)->aupb+=2;}
  return;
} /* extendRULE */
static void a_1099(void){ /* openicefile */
int a_L1;int a_P[3];
a_1464();
if(!a_openfile(a_1085,119,a_1374,to_LIST(a_1374)->aupb)){ goto a_G9;}
a_1387(to_LIST(a_1374)->aupb);
a_1886(a_1085,a_1236,2130704252);
a_1100(2);
a_putchar(a_1085,46);
a_1100(3);
a_1091(); return;
a_G9:a_getfileerror(a_1085,a_L1);
a_P[0]=2130704239;a_P[1]=to_LIST(a_1374)->aupb;a_P[2]=a_L1;a_1238(0,3,a_P); return;
} /* openicefile */
static void a_1097(void){ /* closeicefile */

a_closefile(a_1085); return;
} /* closeicefile */
static void a_1098(void){ /* deleteicefile */

a_1097();
a_1464();
a_unlinkfile(a_1374,to_LIST(a_1374)->aupb);
a_1387(to_LIST(a_1374)->aupb); return;
} /* deleteicefile */
static void a_1093(void){ /* Wspace */

a_putchar(a_1085,32); return;
} /* Wspace */
static void a_1091(void){ /* Wline */

a_putchar(a_1085,10); return;
} /* Wline */
static void a_1100(int a_F1){ /* printint+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G5;}
a_putchar(a_1085,45);
a_subtr(-1,a_F1,a_F1);
a_1101(a_F1,49); return;
a_G5:if(!a_less(a_F1,0)){ goto a_G8;}
a_putchar(a_1085,45);
a_getabs(a_F1,a_F1);
a_G8:a_1101(a_F1,48); return;
} /* printint */
static void a_1101(int a_F1,int a_F2){ /* printint1+>a+>a */
int a_L3;int a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1101(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_putchar(a_1085,a_L4); return;
} /* printint1 */
static void a_1087(int a_F1){ /* W+>a */

{ if((1696718844<=a_F1 && a_F1<=1696719046)){ goto a_G2;}
 if((1990708582<=a_F1 && a_F1<=2130703581)){ goto a_G5;}
 if((1962709581<=a_F1 && a_F1<=1990708580)){ goto a_G10;}
  goto a_G12;}
a_G2:a_1886(a_1085,a_1157,a_F1);
if(!a_equal(a_F1,1696718991)){ return;}
a_putchar(a_1085,10); return;
a_G5:a_putchar(a_1085,78);
a_subtr(a_F1,to_LIST(a_1086)->vlwb,a_F1);
a_incr(a_F1);
a_1100(a_F1);
a_1093(); return;
a_G10:a_putchar(a_1085,88);
a_1092(a_F1); return;
a_G12:a_1248(a_1001,2130705939); return;
} /* W */
static void a_1089(int a_F1){ /* Wcons+>a */

a_1100(a_F1);
a_1093(); return;
} /* Wcons */
static void a_1095(int a_F1){ /* Wtag+>a */
int a_L2;int a_P[1];
if(!a_was(a_1718,a_F1)){ goto a_G9;}
a_1736(a_F1,a_P);a_L2=a_P[0];
if(!a_is(a_L2)){ goto a_G7;}
a_putchar(a_1085,73);
a_G5:a_1100(a_L2);
a_G6:a_1093(); return;
a_G7:if(a_1274()){ return;}
a_G8:a_1248(a_1001,2130705936); return;
a_G9:if(!a_was(a_1719,a_F1)){ goto a_G8;}
if(!a_equal(to_LIST(a_1719)->offset[a_F1-2],16777331)){ goto a_G13;}
a_putchar(a_1085,76);
a_1100(to_LIST(a_1719)->offset[a_F1-1]); goto a_G6;
a_G13:a_putchar(a_1085,70);
a_subtr(a_F1,to_LIST(a_1719)->alwb,a_L2);
a_div(a_L2,6,a_L2);
a_incr(a_L2); goto a_G5;
} /* Wtag */
static void a_1094(int a_F1){ /* Wstring+>a */

{ if((1696719048<=a_F1 && a_F1<=1920711075)){ goto a_G2;}
 if((604756899<=a_F1 && a_F1<=1164737376)){ goto a_G3;}
  goto a_G5;}
a_G2:a_1884(a_1085,a_1374,a_F1); return;
a_G3:a_previous(a_1720,a_F1);
a_1884(a_1085,a_1720,a_F1); return;
a_G5:a_1248(a_1001,2130705932); return;
} /* Wstring */
static void a_1090(int a_F1){ /* Wfstr+>a */

if(!a_was(a_1374,a_F1)){ goto a_G4;}
a_putchar(a_1085,84);
a_1884(a_1085,a_1374,a_F1); return;
a_G4:a_1248(a_1001,2130705928); return;
} /* Wfstr */
static void a_1088(int a_F1){ /* Wbase+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
if(!a_was(a_1374,a_F1)){ goto a_G11;}
a_1245(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];
a_putchar(a_1085,34);
a_G4:if(a_mreq(a_L2,a_L3)){ goto a_G10;}
if(!a_stringelem(a_1374,a_F1,a_L2,a_P)){ goto a_G10;}a_L4=a_P[0];
a_incr(a_L2);
a_putchar(a_1085,a_L4);
if(a_noteq(a_L4,34)){ goto a_G4;}
a_putchar(a_1085,a_L4); goto a_G4;
a_G10:a_putchar(a_1085,34); return;
a_G11:a_1248(a_1001,2130705924); return;
} /* Wbase */
static void a_1092(int a_F1){ /* Wnumber+>a */
int a_L2;int a_L3;
{register int a_r1=to_LIST(a_1150)->aupb;a_L2=a_r1;a_L3=a_r1;}
a_1122(a_F1);
a_G3:if(!a_less(a_L3,to_LIST(a_1150)->aupb)){ goto a_G6;}
a_incr(a_L3);
a_putchar(a_1085,to_LIST(a_1150)->offset[a_L3]); goto a_G3;
a_G6:a_unstackto(a_1150,a_L2);
a_1093(); return;
} /* Wnumber */
static void a_1096(int a_F1){ /* Wtype+>a */

a_putchar(a_1085,60);
a_1886(a_1085,a_1761,a_F1);
a_putchar(a_1085,62);
a_1093(); return;
} /* Wtype */
static void a_1111(void){ /* skipsource */
int a_P[1];
if(a_1172(a_P)){ return;}
if(a_1164(1696718957)){ goto a_G7;}
if(a_1164(1696719035)){ goto a_G7;}
if(a_1164(1696719039)){ goto a_G7;}
if(a_1164(1696719043)){ goto a_G7;}
if(!a_1164(1696718876)){ goto a_G8;}
a_G7:a_1200(a_P); return;
a_G8:if(!a_1164(1696719027)){ goto a_G14;}
a_1200(a_P);
a_1111();
a_1196(1696718871);
if(a_1180(a_P)){ return;}
a_1197(a_P); return;
a_G14:if(a_1164(1696718972)){ return;} goto a_G7;
} /* skipsource */
static void a_1110(void){ /* skipaffixes */

a_G1:if(!a_1164(1696718988)){ return;}
a_1111(); goto a_G1;
} /* skipaffixes */
static void a_1109(void){ /* rulebody */
int a_P[1];
if(!a_1164(1696718945)){ goto a_G3;}
a_1201(a_P);
a_G3:if(!a_1164(1696718953)){ goto a_G5;}
a_1176(1696718885);
a_G5:if(!a_1164(1696718868)){ goto a_G8;}
a_1176(1696718868);
a_1107(); return;
a_G8:a_1104(); return;
} /* rulebody */
static void a_1107(void){ /* classification */

a_G1:a_1196(1696718860);
a_1176(1696718860);
a_1196(1696718892);
a_1103();
if(!a_1164(1696719016)){ return;} goto a_G1;
} /* classification */
static void a_1103(void){ /* alternative */

a_G1:a_1108();
if(!a_1164(1696718892)){ return;} goto a_G1;
} /* alternative */
static void a_1104(void){ /* altsequence */

a_G1:a_1103();
if(!a_1164(1696719016)){ return;} goto a_G1;
} /* altsequence */
static void a_1108(void){ /* member */
int a_L1;int a_P[1];
if(!a_1164(1696718979)){ goto a_G4;}
a_1109();
a_1196(1696718882); return;
a_G4:if(!a_1164(1696718915)){ goto a_G6;}
a_1176(1696718915); return;
a_G6:if(!a_1164(1696718941)){ goto a_G8;}
a_1200(a_P); return;
a_G8:if(a_1164(1696718988)){ return;}
if(a_1164(1696718964)){ return;}
a_1200(a_P);a_L1=a_P[0];
if(!a_1746(a_L1,128)){ goto a_G13;}
a_1105(a_L1);
a_G13:a_1110(); return;
} /* member */
static void a_1105(int a_F1){ /* checkmacrorule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
if(a_1746(a_F1,524288)){ return;}
if(!a_1746(a_F1,262144)){ goto a_G6;}
a_P[0]=2130704264;a_P[1]=a_F1;a_1238(-1,2,a_P);
a_1722(a_F1,262144);
a_1757(a_F1,524288); return;
a_G6:a_1757(a_F1,262144);
a_1211(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1756(a_F1,a_P);a_L4=a_P[0];a_L5=a_P[1];
a_1209(a_L4,a_L5);
a_1109();
a_1722(a_F1,262144);
a_1757(a_F1,524288);
a_1209(a_L2,a_L3); return;
} /* checkmacrorule */
static void a_1106(void){ /* checkmacrorules */
int a_L1;int a_P[1];
a_L1=0;
a_G2:a_P[0]=a_L1;if(!a_1751(a_P)){ return;}a_L1=a_P[0];
a_1105(a_L1); goto a_G2;
} /* checkmacrorules */
static int a_1132(int a_F1){ /* samenumberblock+>a */
int a_L2;int a_L3;
a_L2=to_LIST(a_1113)->aupb;
a_L3=0;
a_G3:if(a_mreq(a_L3,a_1147)){ return 1;}
if(!a_equal(to_LIST(a_1113)->offset[a_F1],to_LIST(a_1113)->offset[a_L2])){ return 0;}
a_incr(a_L3);
a_decr(a_F1);
a_decr(a_L2); goto a_G3;
} /* samenumberblock */
static void a_1133(int a_F1,int a_A[1]){ /* storeregister+>a+a> */
int a_L3;int a_L4;
a_L3=to_LIST(a_1113)->aupb;
a_A[0]=a_1134;
a_L4=0;
a_1148(a_F1,a_1113);
a_G5:if(a_more(a_A[0],a_L3)){ return;}
if(!a_1132(a_A[0])){ goto a_G8;}
a_unstackto(a_1113,a_L3); return;
a_G8:if(!a_more(a_L4,100)){ goto a_G10;}
a_A[0]=to_LIST(a_1113)->aupb; return;
a_G10:a_incr(a_L4);
a_add(a_A[0],a_1147,a_A[0]); goto a_G5;
} /* storeregister */
static void a_1123(int a_A[1]){ /* getnumberzero+a> */

a_A[0]=a_1134; return;
} /* getnumberzero */
static void a_1125(int a_F1,int a_A[1]){ /* gettargetnumbervalue+>a+a> */
int a_L3;int a_P[1];
a_1143(a_1113,a_F1,a_P);a_L3=a_P[0];
a_1139(a_L3,a_P);a_A[0]=a_P[0]; return;
} /* gettargetnumbervalue */
static void a_1120(int a_F1,int a_A[1]){ /* getdigit+>a+a> */

{register int a_r1=to_LIST(a_1150)->offset[a_F1];
 if(!((48<=a_r1 && a_r1<=57))){ goto a_G3;}
}
a_subtr(to_LIST(a_1150)->offset[a_F1],48,a_A[0]); return;
a_G3:a_1248(a_1001,2130705959); return;
} /* getdigit */
static void a_1121(int a_F1,int a_A[1]){ /* gethexdigit+>a+a> */

{register int a_r1=to_LIST(a_1150)->offset[a_F1];
 if((48<=a_r1 && a_r1<=57)){ goto a_G2;}
 if((65<=a_r1 && a_r1<=70)){ goto a_G3;}
 if((97<=a_r1 && a_r1<=102)){ goto a_G5;}
  goto a_G6;}
a_G2:a_subtr(to_LIST(a_1150)->offset[a_F1],48,a_A[0]); return;
a_G3:a_subtr(to_LIST(a_1150)->offset[a_F1],65,a_A[0]);
a_G4:a_add(a_A[0],10,a_A[0]); return;
a_G5:a_subtr(to_LIST(a_1150)->offset[a_F1],97,a_A[0]); goto a_G4;
a_G6:a_1248(a_1001,2130705954); return;
} /* gethexdigit */
static void a_1114(int a_F1,int a_F2){ /* adddigit+>a+>a */
int a_L3;int a_P[1];
a_1142(10,a_P);a_L3=a_P[0];
a_1146(8,a_L3,a_F1);
a_1142(a_F2,a_P);a_L3=a_P[0];
a_1146(6,a_L3,a_F1); return;
} /* adddigit */
static void a_1116(int a_F1,int a_F2,int a_A[1]){ /* enterconststring+>a+>a+a> */
int a_L4;int a_L5;int a_L6;int a_P[1];
a_L6=0;
a_1142(0,a_P);a_L4=a_P[0];
a_G3:a_incr(a_F2);
if(a_more(a_F2,to_LIST(a_1150)->aupb)){ goto a_G14;}
a_1120(a_F2,a_P);a_L5=a_P[0];
if(!a_1145(21,a_L4,a_1128)){ goto a_G8;}
a_G7:a_1114(a_L4,a_L5); goto a_G3;
a_G8:if(!a_1145(21,a_L4,a_1128)){ goto a_G10;}
a_G9:a_L6=1; goto a_G14;
a_G10:if(a_less(a_L5,a_1127)){ goto a_G7;}
if(a_less(a_L5,a_1127)){ goto a_G9;}
if(!a_is(a_F1)){ goto a_G9;}
if(a_equal(a_F2,to_LIST(a_1150)->aupb)){ goto a_G7;} goto a_G9;
a_G14:if(!a_is(a_F1)){ goto a_G16;}
a_1146(5,a_L4,a_L4);
a_G16:if(!a_is(a_L6)){ goto a_G20;}
a_P[0]=2130704275;a_1238(-1,1,a_P);
a_1138(a_L4);
a_A[0]=a_1134; return;
a_G20:a_1133(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* enterconststring */
static void a_1115(int a_F1,int a_F2){ /* addhexdigit+>a+>a */
int a_L3;int a_P[1];
a_1137(a_F1,a_P);a_L3=a_P[0];
a_1146(6,a_L3,a_F1);
a_1137(a_F1,a_P);a_L3=a_P[0];
a_1146(6,a_L3,a_F1);
a_1137(a_F1,a_P);a_L3=a_P[0];
a_1146(6,a_L3,a_F1);
a_1137(a_F1,a_P);a_L3=a_P[0];
a_1146(6,a_L3,a_F1);
a_1142(a_F2,a_P);a_L3=a_P[0];
a_1146(3,a_L3,a_F1); return;
} /* addhexdigit */
static void a_1118(int a_F1,int a_F2,int a_A[1]){ /* enterhexconststring+>a+>a+a> */
int a_L4;int a_L5;int a_L6;int a_P[1];
a_L6=0;
a_1142(0,a_P);a_L4=a_P[0];
a_G3:a_incr(a_F2);
if(a_more(a_F2,to_LIST(a_1150)->aupb)){ goto a_G10;}
if(!a_1144(11,a_L4)){ goto a_G7;}
a_G6:a_L6=1; goto a_G10;
a_G7:if(a_1145(22,a_1129,a_L4)){ goto a_G6;}
a_1121(a_F2,a_P);a_L5=a_P[0];
a_1115(a_L4,a_L5); goto a_G3;
a_G10:if(!a_is(a_F1)){ goto a_G12;}
a_1146(5,a_L4,a_L4);
a_G12:if(!a_is(a_L6)){ goto a_G16;}
a_P[0]=2130704275;a_1238(-1,1,a_P);
a_1138(a_L4);
a_A[0]=a_1134; return;
a_G16:a_1133(a_L4,a_P);a_A[0]=a_P[0]; return;
} /* enterhexconststring */
static void a_1117(int a_F1,int a_A[1]){ /* enterconstvalue+>a+a> */
int a_L3;int a_P[2];
if(!a_1141(a_F1)){ goto a_G4;}
a_1142(a_F1,a_P);a_L3=a_P[0];
a_1133(a_L3,a_P);a_A[0]=a_P[0]; return;
a_G4:a_P[0]=2130704286;a_P[1]=a_F1;a_1238(-1,2,a_P);
a_A[0]=a_1134; return;
} /* enterconstvalue */
static void a_1122(int a_F1){ /* getnumberrepr+>a */
int a_L2;int a_P[1];
a_1143(a_1113,a_F1,a_P);a_L2=a_P[0];
if(!a_1145(23,a_1131,a_L2)){ goto a_G7;}
a_1138(a_L2);
a_1119(45);
a_1137(a_1130,a_P);a_L2=a_P[0];
a_1124(a_L2,49); return;
a_G7:if(!a_1144(11,a_L2)){ goto a_G10;}
a_1146(5,a_L2,a_L2);
a_1119(45);
a_G10:a_1124(a_L2,48); return;
} /* getnumberrepr */
static void a_1124(int a_F1,int a_F2){ /* getregisterrepr+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_1137(a_F1,a_P);a_L3=a_P[0];
a_1142(10,a_P);a_L4=a_P[0];
a_1146(9,a_L4,a_L3);
if(a_1144(10,a_L3)){ goto a_G7;}
a_1137(a_L3,a_P);a_L4=a_P[0];
a_1124(a_L4,48);
a_G7:a_1142(10,a_P);a_L4=a_P[0];
a_1146(8,a_L4,a_L3);
a_1146(7,a_L3,a_F1);
a_1139(a_F1,a_P);a_L4=a_P[0];
a_add(a_L4,a_F2,a_L4);
a_1119(a_L4); return;
} /* getregisterrepr */
static void a_1126(void){ /* initializenumbers */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
a_1142(0,a_P);a_L1=a_P[0];
a_1148(a_L1,a_1113);
a_1134=to_LIST(a_1113)->aupb;
a_1142(0,a_P);a_1130=a_P[0];
a_1142(1,a_P);a_L1=a_P[0];
a_L3=1;
a_L4=5;
a_G8:if(a_mreq(a_L3,32)){ goto a_G17;}
a_1137(a_L1,a_P);a_L2=a_P[0];
a_1146(3,a_L2,a_1130);
a_1137(a_L1,a_P);a_L2=a_P[0];
a_1146(6,a_L2,a_L1);
if(!a_equal(a_L4,32)){ goto a_G15;}
a_1137(a_L1,a_P);a_1129=a_P[0];
a_G15:a_incr(a_L4);
a_incr(a_L3); goto a_G8;
a_G17:a_1137(a_L1,a_P);a_1131=a_P[0];
a_1138(a_L1);
a_1137(a_1130,a_P);a_1128=a_P[0];
a_1142(10,a_P);a_L2=a_P[0];
a_1146(9,a_L2,a_1128);
a_1137(a_1128,a_P);a_L2=a_P[0];
a_1142(10,a_P);a_L1=a_P[0];
a_1146(8,a_L1,a_L2);
a_1137(a_1130,a_P);a_L1=a_P[0];
a_1146(7,a_L2,a_L1);
a_1139(a_L1,a_P);a_1127=a_P[0];
a_incr(a_1127); return;
} /* initializenumbers */
static void a_1112(void){ /* @root */

 a_waitfor(a_1001,2130705949); a_1126(); return;
} /* @root */
static void a_1119(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1150,1);a_r1[0]=a_F1;to_LIST(a_1150)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1140(int a_A[1]){ /* getregister+a> */
int a_L2;
{register int *a_r1=a_extension(a_1136,1);a_r1[0]=0;to_LIST(a_1136)->aupb+=1;}
a_A[0]=to_LIST(a_1136)->aupb;
a_L2=a_1147;
a_G4:if(a_equal(a_L2,1)){ return;}
{register int *a_r1=a_extension(a_1136,1);a_r1[0]=0;to_LIST(a_1136)->aupb+=1;}
a_decr(a_L2); goto a_G4;
} /* getregister */
static void a_1138(int a_F1){ /* freeregister+>a */
int a_L2;
a_add(a_F1,a_1147,a_L2);
a_decr(a_L2);
if(a_noteq(a_L2,to_LIST(a_1136)->aupb)){ return;}
a_G4:if(!a_equal(a_F1,to_LIST(a_1136)->aupb)){ goto a_G6;}
a_unstack(a_1136); return;
a_G6:a_unstack(a_1136); goto a_G4;
} /* freeregister */
static void a_1137(int a_F1,int a_A[1]){ /* duplregister+>a+a> */
int a_L3;int a_L4;int a_P[1];
a_1140(a_P);a_A[0]=a_P[0];
a_L3=a_A[0];
a_L4=a_1147;
a_G4:if(!a_lseq(a_L4,1)){ goto a_G6;}
to_LIST(a_1136)->offset[a_L3]=to_LIST(a_1136)->offset[a_F1]; return;
a_G6:to_LIST(a_1136)->offset[a_L3]=to_LIST(a_1136)->offset[a_F1];
a_decr(a_L4);
a_incr(a_F1);
a_incr(a_L3); goto a_G4;
} /* duplregister */
static void a_1143(int a_F1,int a_F2,int a_A[1]){ /* readregister+t[]+>a+a> */
int a_L3;int a_L4;int a_P[1];
a_1140(a_P);a_A[0]=a_P[0];
a_L3=a_A[0];
a_L4=a_1147;
a_subtr(a_F2,a_1147,a_F2);
a_incr(a_F2);
a_G6:if(!a_lseq(a_L4,1)){ goto a_G8;}
to_LIST(a_1136)->offset[a_L3]=to_LIST(a_F1)->offset[a_F2]; return;
a_G8:to_LIST(a_1136)->offset[a_L3]=to_LIST(a_F1)->offset[a_F2];
a_decr(a_L4);
a_incr(a_F2);
a_incr(a_L3); goto a_G6;
} /* readregister */
static void a_1148(int a_F1,int a_F2){ /* writeregister+>a+[]st[] */
int a_L2;int a_L3;
a_L2=a_1147;
a_L3=a_F1;
a_G3:if(a_less(a_L2,1)){ goto a_G7;}
{register int *a_r1=a_extension(a_F2,1);a_r1[0]=to_LIST(a_1136)->offset[a_L3];to_LIST(a_F2)->aupb+=1;}
a_decr(a_L2);
a_incr(a_L3); goto a_G3;
a_G7:a_1138(a_F1); return;
} /* writeregister */
static int a_1141(int a_F1){ /* istargetconst+>a */

if(!a_equal(a_F1,a_F1)){ return 0;} return 1;
} /* istargetconst */
static void a_1142(int a_F1,int a_A[1]){ /* putcstregister+>a+a> */
int a_P[1];
a_1140(a_P);a_A[0]=a_P[0];
to_LIST(a_1136)->offset[a_A[0]]=a_F1; return;
} /* putcstregister */
static void a_1139(int a_F1,int a_A[1]){ /* getcstregister+>a+a> */

a_A[0]=to_LIST(a_1136)->offset[a_F1];
a_1138(a_F1); return;
} /* getcstregister */
static void a_1146(int a_F1,int a_F2,int a_F3){ /* regoperator+>a+>a+>a */

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
a_G2:a_boolxor(to_LIST(a_1136)->offset[a_F3],to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3]);
a_G3:a_1138(a_F2); return;
a_G4:a_booland(to_LIST(a_1136)->offset[a_F3],to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3]); goto a_G3;
a_G5:a_boolor(to_LIST(a_1136)->offset[a_F3],to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3]); goto a_G3;
a_G6:a_add(to_LIST(a_1136)->offset[a_F3],to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3]); goto a_G3;
a_G7:a_subtr(to_LIST(a_1136)->offset[a_F3],to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3]); goto a_G3;
a_G8:a_mult(to_LIST(a_1136)->offset[a_F3],to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3]); goto a_G3;
a_G9:a_div(to_LIST(a_1136)->offset[a_F3],to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3]); goto a_G3;
a_G10:a_boolinvert(to_LIST(a_1136)->offset[a_F3],to_LIST(a_1136)->offset[a_F3]); return;
a_G11:a_subtr(0,to_LIST(a_1136)->offset[a_F3],to_LIST(a_1136)->offset[a_F3]); return;
} /* regoperator */
static int a_1144(int a_F1,int a_F2){ /* regcompare+>a+>a */

 static const char *a_rulename="regcompare";
{ if(a_F1==10){ goto a_G2;}
 if(a_F1==11){ goto a_G3;}
 if(!(a_F1==12)){a_area_failed(a_rulename,a_F1);}
 goto a_G4;}
a_G2:if(!a_equal(to_LIST(a_1136)->offset[a_F2],0)){ return 0;} return 1;
a_G3:if(!a_less(to_LIST(a_1136)->offset[a_F2],0)){ return 0;} return 1;
a_G4:if(!a_more(to_LIST(a_1136)->offset[a_F2],0)){ return 0;} return 1;
} /* regcompare */
static int a_1145(int a_F1,int a_F2,int a_F3){ /* regcompare2+>a+>a+>a */
int a_L4;
 static const char *a_rulename="regcompare2";
{ if(a_F1==20){ goto a_G2;}
 if(a_F1==21){ goto a_G5;}
 if(a_F1==22){ goto a_G6;}
 if(!(a_F1==23)){a_area_failed(a_rulename,a_F1);}
 goto a_G7;}
a_G2:a_L4=to_LIST(a_1136)->offset[a_F2];
a_incr(a_L4);
if(!a_equal(a_L4,to_LIST(a_1136)->offset[a_F3])){ return 0;} return 1;
a_G5:if(!a_less(to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3])){ return 0;} return 1;
a_G6:if(!a_lseq(to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3])){ return 0;} return 1;
a_G7:if(!a_equal(to_LIST(a_1136)->offset[a_F2],to_LIST(a_1136)->offset[a_F3])){ return 0;} return 1;
} /* regcompare2 */
static void a_1135(void){ /* @root */
int a_L1;
a_1147=1;
a_L1=32;
a_G3:if(a_mreq(a_L1,32)){ goto a_G6;}
a_add(a_L1,32,a_L1);
a_incr(a_1147); goto a_G3;
a_G6: a_waitfor(a_1001,2130705968); if(!a_equal(32,32)){ goto a_G9;}
if(a_equal(32,32)){ return;}
a_G9:a_1248(a_1001,2130705964); return;
} /* @root */
static void a_1204(int a_F1,int a_F2){ /* opendisc+>a+>a */
int a_P[1];
if(!a_equal(a_F1,1)){ goto a_G3;}
a_P[0]=a_1185;a_1205(1,a_F2,a_P);a_1185=a_P[0]; return;
a_G3:if(!a_equal(a_F1,2)){ goto a_G5;}
a_P[0]=a_1186;a_1205(2,a_F2,a_P);a_1186=a_P[0]; return;
a_G5:a_1248(a_1001,2130706056); return;
} /* opendisc */
static void a_1205(int a_F1,int a_F3,int a_A[1]){ /* openthisdisc+>a+>a>+>a */
int a_L4;int a_P[4];
if(!a_equal(a_F3,116)){ goto a_G11;}
a_L4=a_A[0];
a_copystring(a_1374,1696719054,a_1374);
a_A[0]=to_LIST(a_1374)->aupb;
if(!a_is(a_L4)){ goto a_G7;}
a_P[0]=2130704591;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_L4;a_1238(0,4,a_P); return;
a_G7:if(!a_opentempfile(a_1156,a_1374,a_A[0])){ goto a_G9;}
a_1213=0;a_1215=0; return;
a_G9:a_getfileerror(a_1156,a_L4);
a_G10:a_P[0]=2130704576;a_P[1]=a_A[0];a_P[2]=a_L4;a_1238(0,3,a_P); return;
a_G11:if(!a_equal(a_F3,114)){ goto a_G19;}
if(!a_equal(a_A[0],0)){ goto a_G14;}
a_P[0]=2130704591;a_P[1]=a_F1;a_P[2]=a_F3;a_P[3]=a_A[0];a_1238(0,4,a_P); return;
a_G14:if(!a_openfile(a_1155,114,a_1374,a_A[0])){ goto a_G18;}
a_1167=0;
a_1169=0;
a_1203(); return;
a_G18:a_getfileerror(a_1155,a_L4); goto a_G10;
a_G19:a_1248(a_1001,2130706051); return;
} /* openthisdisc */
static void a_1182(void){ /* closediscs */

a_closefile(a_1155);
a_closefile(a_1156); return;
} /* closediscs */
static void a_1184(void){ /* deletediscs */

a_1182();
if(a_equal(a_1185,0)){ goto a_G4;}
a_unlinkfile(a_1374,a_1185);
a_G4:if(a_equal(a_1186,0)){ return;}
a_unlinkfile(a_1374,a_1186); return;
} /* deletediscs */
static void a_1210(void){ /* rewinddisc */

a_1167=0;a_1175=0;
a_1209(0,0); return;
} /* rewinddisc */
static void a_1159(void){ /* Dnlcr */

a_incr(a_1215); return;
} /* Dnlcr */
static void a_1214(int a_F1,int a_F2){ /* writedisc+>a+>a */

if(a_equal(a_1215,0)){ goto a_G6;}
if(!a_equal(a_1215,1)){ goto a_G4;}
a_putdata(a_1156,1696718846,1); goto a_G6;
a_G4:a_putdata(a_1156,1696718850,1);
a_putdata(a_1156,a_1215,0);
a_G6:a_1215=a_1213;
a_1213=0;
a_putdata(a_1156,a_F1,a_F2); return;
} /* writedisc */
static void a_1154(int a_F1){ /* D+>a */

if(a_was(a_1157,a_F1)){ goto a_G4;}
if(a_was(a_1113,a_F1)){ goto a_G4;}
if(!a_was(a_1761,a_F1)){ goto a_G5;}
a_G4:a_1214(a_F1,1); return;
a_G5:a_1248(a_1001,2130706045); return;
} /* D */
static void a_1158(int a_F1){ /* Dcons+>a */

a_1214(a_F1,0); return;
} /* Dcons */
static void a_1161(int a_F1){ /* Dstring+>a */

if(a_equal(a_F1,0)){ return;}
if(!a_was(a_1374,a_F1)){ goto a_G4;}
a_1214(a_F1,1); return;
a_G4:a_1248(a_1001,2130706042); return;
} /* Dstring */
static void a_1163(int a_F1){ /* Dttag+>a */

if(!a_was(a_1720,a_F1)){ goto a_G3;}
a_1214(a_F1,1); return;
a_G3:a_1248(a_1001,2130706038); return;
} /* Dttag */
static void a_1160(int a_F1,int a_F2){ /* Dqtag+>a+>a */

a_1163(a_F2);
if(!a_is(a_F1)){ return;}
a_1154(1696719005);
a_1163(a_F1); return;
} /* Dqtag */
static void a_1162(int a_F1){ /* Dtag+>a */

if(!a_was(a_1718,a_F1)){ goto a_G3;}
a_G2:a_1214(a_F1,1); return;
a_G3:if(!a_lseq(to_LIST(a_1719)->vlwb,a_F1)){ goto a_G5;}
if(a_less(a_F1,to_LIST(a_1719)->vupb)){ goto a_G2;}
a_G5:a_1248(a_1001,2130706034); return;
} /* Dtag */
static void a_1207(void){ /* readfromQBUFFER */

a_incr(a_1167);
a_1178=to_LIST(a_1165)->offset[a_1167];
if(!a_equal(a_1178,1696718899)){ goto a_G7;}
a_1167=0;
a_1170=0;
a_1203(); return;
a_G7:if(!a_equal(a_1178,1696718889)){ goto a_G11;}
a_1181=0;
a_incr(a_1167);
a_1178=to_LIST(a_1165)->offset[a_1167]; return;
a_G11:a_1181=1; return;
} /* readfromQBUFFER */
static void a_1212(void){ /* substitute */

if(!a_was(a_1719,a_1178)){ return;}
a_add(a_1178,a_1175,a_1178);
if(a_noteq(to_LIST(a_1719)->offset[a_1178-2],16777322)){ return;}
a_1170=a_1178;
a_1167=to_LIST(a_1719)->offset[a_1178-1];
a_1207(); return;
} /* substitute */
static void a_1203(void){ /* nextdiscsymbol */
int a_L1;int a_P[2];
if(!a_is(a_1167)){ goto a_G4;}
a_1170=0;
a_1207(); return;
a_G4:a_1710(a_1169);
a_G5:a_getfilepos(a_1155,a_P);a_1173=a_P[0];
if(!a_getdata(a_1155,a_P)){ goto a_G20;}a_1178=a_P[0];a_1181=a_P[1];
if(!a_equal(a_1178,1696718846)){ goto a_G11;}
if(!a_equal(a_1181,1)){ goto a_G11;}
a_incr(a_1169);
a_incr(a_1213); goto a_G5;
a_G11:if(!a_equal(a_1178,1696718850)){ goto a_G17;}
if(!a_equal(a_1181,1)){ goto a_G17;}
if(a_getdata(a_1155,a_P)){a_L1=a_P[0]; goto a_G15;}
a_L1=0;
a_G15:a_add(a_1169,a_L1,a_1169);
a_add(a_1213,a_L1,a_1213); goto a_G5;
a_G17:if(!a_is(a_1175)){ return;}
if(!a_equal(a_1181,1)){ return;}
a_1212(); return;
a_G20:a_1178=1696718899;
a_1181=1; return;
} /* nextdiscsymbol */
static void a_1211(int a_A[2]){ /* savediscposition+a>+a> */

if(!a_is(a_1167)){ goto a_G3;}
a_1248(a_1001,2130706030); return;
a_G3:a_A[0]=a_1173;
a_A[1]=a_1169; return;
} /* savediscposition */
static void a_1209(int a_F1,int a_F2){ /* restorediscposition+>a+>a */

if(!a_is(a_1167)){ goto a_G3;}
a_1248(a_1001,2130706023); return;
a_G3:a_setfilepos(a_1155,a_F1);
a_1169=a_F2;
a_1203(); return;
} /* restorediscposition */
static int a_1164(int a_F1){ /* Q+>a */

if(!a_equal(a_F1,a_1178)){ return 0;}
if(!a_is(a_1181)){ return 0;}
a_1203(); return 1;
} /* Q */
static int a_1168(int a_A[1]){ /* Qcons+a> */

if(!a_equal(a_1181,0)){ return 0;}
a_A[0]=a_1178;
a_1203(); return 1;
} /* Qcons */
static int a_1177(int a_A[1]){ /* Qstring+a> */

if(!a_is(a_1181)){ return 0;}
if(!a_was(a_1374,a_1178)){ return 0;}
a_A[0]=a_1178;
a_1203(); return 1;
} /* Qstring */
static int a_1179(int a_A[1]){ /* Qtag+a> */

{ if(!((16777838<=a_1178 && a_1178<=562758381)||(576757893<=a_1178 && a_1178<=604756892))){ return 0;}
}
if(!a_is(a_1181)){ return 0;}
a_A[0]=a_1178;
a_1203(); return 1;
} /* Qtag */
static int a_1180(int a_A[1]){ /* Qttag+a> */

if(!a_is(a_1181)){ return 0;}
if(!a_was(a_1720,a_1178)){ return 0;}
a_A[0]=a_1178;
a_1203(); return 1;
} /* Qttag */
static int a_1172(int a_A[1]){ /* Qnumber+a> */

if(!a_is(a_1181)){ return 0;}
if(!a_was(a_1113,a_1178)){ return 0;}
a_A[0]=a_1178;
a_1203(); return 1;
} /* Qnumber */
static int a_1174(int a_A[2]){ /* Qqtag+a>+a> */
int a_P[1];
if(!a_is(a_1181)){ return 0;}
if(!a_was(a_1720,a_1178)){ return 0;}
a_A[1]=a_1178;
a_1203();
if(!a_1164(1696719005)){ goto a_G7;}
a_1201(a_P);a_A[0]=a_P[0]; return 1;
a_G7:a_A[0]=0; return 1;
} /* Qqtag */
static int a_1171(int a_A[1]){ /* Qltag+a> */

{ if(!((576757893<=a_1178 && a_1178<=604756892))){ return 0;}
}
if(!a_is(a_1181)){ return 0;}
a_A[0]=a_1178;
a_1203(); return 1;
} /* Qltag */
static void a_1196(int a_F1){ /* mustQ+>a */

if(a_1164(a_F1)){ return;}
a_1248(a_1001,2130706016); return;
} /* mustQ */
static void a_1197(int a_A[1]){ /* mustQcons+a> */

if(!a_is(a_1181)){ goto a_G3;}
a_1248(a_1001,2130706012); return;
a_G3:a_A[0]=a_1178;
a_1203(); return;
} /* mustQcons */
static void a_1200(int a_A[1]){ /* mustQtag+a> */
int a_P[1];
if(a_1179(a_P)){a_A[0]=a_P[0]; return;}
a_1248(a_1001,2130706007); return;
} /* mustQtag */
static void a_1201(int a_A[1]){ /* mustQttag+a> */
int a_P[1];
if(a_1180(a_P)){a_A[0]=a_P[0]; return;}
a_1248(a_1001,2130706002); return;
} /* mustQttag */
static void a_1199(int a_A[2]){ /* mustQqtag+a>+a> */
int a_P[2];
if(a_1174(a_P)){a_A[0]=a_P[0];a_A[1]=a_P[1]; return;}
a_1248(a_1001,2130705997); return;
} /* mustQqtag */
static void a_1202(int a_A[1]){ /* mustQtype+a> */

if(!a_is(a_1181)){ goto a_G5;}
if(!a_was(a_1761,a_1178)){ goto a_G5;}
a_A[0]=a_1178;
a_1203(); return;
a_G5:a_1248(a_1001,2130705992); return;
} /* mustQtype */
static void a_1198(int a_A[2]){ /* mustQlist+a>+a> */
int a_P[1];
a_A[1]=a_1170;
a_1200(a_P);a_A[0]=a_P[0]; return;
} /* mustQlist */
static int a_1166(int a_F1){ /* Qahead+>a */

if(!a_equal(a_F1,a_1178)){ return 0;}
if(!a_is(a_1181)){ return 0;} return 1;
} /* Qahead */
static void a_1176(int a_F1){ /* Qskip+>a */

a_G1:if(a_1166(1696718899)){ return;}
if(a_1164(a_F1)){ return;}
a_1203(); goto a_G1;
} /* Qskip */
static void a_1206(int a_C,int *a_V){ /* putQ+@+>a */

a_G1:{register int *a_r1=a_extension(a_1165,1);a_r1[0]=a_V[0];to_LIST(a_1165)->aupb+=1;}
if(a_C>1){a_C--;a_V+=1; goto a_G1;}  return;
} /* putQ */
static void a_1183(int a_A[1]){ /* copyQBUFFERaffix+>a> */
int a_P[2];
a_G1:{register int a_r1=to_LIST(a_1165)->offset[a_A[0]];
 if(a_r1==1696718988||a_r1==1696718899){ goto a_G2;}
 if(a_r1==1696718889){ goto a_G4;}
  goto a_G7;}
a_G2:a_incr(a_A[0]);
a_P[0]=1696718899;a_1206(1,a_P); return;
a_G4:a_incr(a_A[0]);
a_P[0]=1696718889;a_P[1]=to_LIST(a_1165)->offset[a_A[0]];a_1206(2,a_P);
a_G6:a_incr(a_A[0]); goto a_G1;
a_G7:a_P[0]=to_LIST(a_1165)->offset[a_A[0]];a_1206(1,a_P); goto a_G6;
} /* copyQBUFFERaffix */
static void a_1208(int a_F1,int a_A[1]){ /* readselector+>a+a> */
int a_L3;int a_P[1];
if(a_1168(a_P)){a_A[0]=a_P[0]; return;}
a_1201(a_P);a_L3=a_P[0];
if(a_1674(a_F1,a_L3,a_P)){a_A[0]=a_P[0]; return;}
a_1248(a_1001,2130705987); return;
} /* readselector */
static void a_1188(int a_F1,int a_F2,int a_A[1]){ /* finalssel+>a+>a+a> */
int a_P[1];
if(!a_is(a_F2)){ goto a_G3;}
a_A[0]=to_LIST(a_1719)->offset[a_F2-4]; return;
a_G3:if(!a_was(a_1719,a_F1)){ goto a_G5;}
a_A[0]=to_LIST(a_1719)->offset[a_F1-4]; return;
a_G5:a_1680(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* finalssel */
static int a_1191(int a_A[1]){ /* limitop+a> */

a_A[0]=a_1178;
if(a_1164(1696719039)){ return 1;}
if(a_1164(1696719043)){ return 1;}
if(a_1164(1696718957)){ return 1;}
if(a_1164(1696719035)){ return 1;}
if(!a_1164(1696718876)){ return 0;} return 1;
} /* limitop */
static void a_1189(int a_A[1]){ /* fsimpleaffix+a> */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[7];
if(!a_1172(a_P)){ goto a_G4;}a_L2=a_P[0];
a_P[0]=a_L2;a_1206(1,a_P);
a_G3:a_A[0]=0; return;
a_G4:if(!a_1191(a_P)){ goto a_G7;}a_L2=a_P[0];
a_1200(a_P);a_L3=a_P[0];
a_P[0]=a_L2;a_P[1]=a_L3;a_1206(2,a_P); goto a_G3;
a_G7:if(!a_1164(1696719027)){ goto a_G14;}
a_1200(a_P);a_L3=a_P[0];
a_P[0]=1696719027;a_P[1]=a_L3;a_1206(2,a_P);
a_1189(a_P);a_A[0]=a_P[0];
a_1196(1696718871);
a_1208(a_L3,a_P);a_L2=a_P[0];
a_P[0]=1696718871;a_P[1]=1696718889;a_P[2]=a_L2;a_1206(3,a_P); return;
a_G14:if(!a_1164(1696718972)){ goto a_G16;}
a_A[0]=16777327; return;
a_G16:a_1198(a_P);a_L3=a_P[0];a_L5=a_P[1];
a_A[0]=0;
a_1741(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777226||a_L4==16777257||a_L4==16777231||a_L4==16777236||a_L4==16777293||a_L4==16777298||a_L4==16777304||a_L4==16777331){ goto a_G20;}
 if(a_L4==16777244||a_L4==16777240||a_L4==16777250||a_L4==16777277||a_L4==16777283){ goto a_G21;}
 if(a_L4==16777310){ goto a_G26;}
  goto a_G28;}
a_G20:a_P[0]=a_L3;a_1206(1,a_P); return;
a_G21:a_1188(a_L3,a_L5,a_P);a_L2=a_P[0];
if(a_more(a_L2,0)){ goto a_G25;}
a_L2=1;
a_P[0]=2130704606;a_P[1]=a_L3;a_1240(9,-1,2,a_P);
a_G25:a_P[0]=1696719027;a_P[1]=a_L3;a_P[2]=1696719035;a_P[3]=a_L3;a_P[4]=1696718871;a_P[5]=1696718889;a_P[6]=a_L2;a_1206(7,a_P); return;
a_G26:a_P[0]=a_L3;a_1206(1,a_P);
a_A[0]=16777310; return;
a_G28:a_1248(a_1001,2130705981); return;
} /* fsimpleaffix */
static void a_1195(int a_F1,int a_A[1]){ /* matchformalactual+>a+a> */
int a_L3;int a_P[1];
{ if(a_F1==16777288||a_F1==16777283||a_F1==16777277){ goto a_G2;}
 if(a_F1==16777293||a_F1==16777298||a_F1==16777304){ goto a_G5;}
  goto a_G6;}
a_G2:a_1200(a_P);a_L3=a_P[0];
a_P[0]=a_L3;a_1206(1,a_P);
a_1741(a_L3,a_P);a_A[0]=a_P[0]; return;
a_G5:a_1189(a_P);a_A[0]=a_P[0]; return;
a_G6:a_1248(a_1001,2130705975); return;
} /* matchformalactual */
static void a_1190(int a_F1,int a_F2,int a_F3){ /* handleformallist+>a+>a+>a */
int a_L4;int a_L5;int a_P[2];
{ if(!(a_F3==16777277||a_F3==16777283)){ return;}
}
a_1732(a_F1,a_F2,a_P);a_L4=a_P[0];a_L5=a_P[1];
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-5]=a_L4;
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-4]=a_L5; return;
} /* handleformallist */
static void a_1187(int a_F1,int a_F2,int a_F3){ /* expandvarargs+>a+>a+>a */
int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_L10;int a_P[2];
a_L4=a_F3;
a_L7=to_LIST(a_1719)->aupb;
a_L8=0;
a_G4:a_incr(a_L4);
a_1733(a_F1,a_L4,a_P);a_L5=a_P[0];
a_1195(a_L5,a_P);a_L6=a_P[0];
if(a_equal(a_L6,16777310)){ goto a_G22;}
if(a_noteq(a_L8,0)){ goto a_G11;}
a_1724(16777322,0);
a_1190(a_F1,a_L4,a_L5);
a_G11:if(a_noteq(a_L6,16777327)){ goto a_G17;}
if(!a_equal(a_L8,0)){ goto a_G16;}
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-1]=-1;
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2]=16777331;
a_P[0]=to_LIST(a_1719)->aupb;a_1206(1,a_P); goto a_G17;
a_G16:a_P[0]=1696718972;a_1206(1,a_P);
a_G17:if(!a_equal(a_L4,a_F2)){ goto a_G20;}
a_L8=1;
a_L4=a_F3;
a_G20:if(!a_1164(1696718988)){ goto a_G22;}
a_P[0]=1696718988;a_1206(1,a_P); goto a_G4;
a_G22:if(!a_equal(a_L8,0)){ goto a_G33;}
a_L9=to_LIST(a_1165)->offset[to_LIST(a_1165)->aupb];
a_P[0]=1696718899;a_1206(1,a_P);
a_G25:if(a_more(a_L4,a_F2)){ return;}
a_1733(a_F1,a_L4,a_P);a_L5=a_P[0];
a_1724(16777322,0);
a_1190(a_F1,a_L4,a_L5);
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-1]=to_LIST(a_1165)->aupb;
a_next(a_1719,a_L9);
a_P[0]=a_L9;a_P[1]=1696718899;a_1206(2,a_P);
a_incr(a_L4); goto a_G25;
a_G33:a_P[0]=1696718899;a_1206(1,a_P);
a_L10=to_LIST(a_1719)->offset[a_L7-1];
a_incr(a_L10);
a_L4=a_F3;
a_G37:if(a_mreq(a_L4,a_F2)){ return;}
a_next(a_1719,a_L7);
if(!a_equal(to_LIST(a_1719)->offset[a_L7-2],16777322)){ goto a_G41;}
to_LIST(a_1719)->offset[a_L7-1]=to_LIST(a_1165)->aupb;
a_G41:a_P[0]=a_L10;a_1183(a_P);a_L10=a_P[0];
a_incr(a_L4); goto a_G37;
} /* expandvarargs */
static void a_1192(int a_F1){ /* macroarguments+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[1];
a_1731(a_F1,a_P);a_L2=a_P[0];
a_L3=1;
a_G3:if(a_more(a_L3,a_L2)){ return;}
a_1724(16777322,0);
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-1]=to_LIST(a_1165)->aupb;
a_1196(1696718988);
a_1733(a_F1,a_L3,a_P);a_L4=a_P[0];
a_1190(a_F1,a_L3,a_L4);
if(!a_equal(a_L4,16777310)){ goto a_G11;}
a_1187(a_F1,a_L2,a_L3); return;
a_G11:a_1195(a_L4,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,16777327)){ goto a_G15;}
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-1]=-1;
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2]=16777331; goto a_G16;
a_G15:a_P[0]=1696718899;a_1206(1,a_P);
a_G16:a_incr(a_L3); goto a_G3;
} /* macroarguments */
static void a_1193(int a_F1,int a_A[2]){ /* macrocallhead+>a+a>+a> */
int a_L4;
a_A[0]=to_LIST(a_1165)->aupb;
a_A[1]=a_1175;
a_L4=to_LIST(a_1719)->aupb;
a_1192(a_F1);
a_subtr(a_L4,to_LIST(a_1719)->alwb,a_1175);
a_next(a_1719,a_1175); return;
} /* macrocallhead */
static void a_1194(int a_F1,int a_F2){ /* macrocalltail+>a+>a */

a_1175=a_F2;
a_unstackto(a_1165,a_F1); return;
} /* macrocalltail */
static void a_1222(int a_F1){ /* extendDICT+>a */

{register int *a_r1=a_extension(a_1217,1);a_r1[0]=a_F1;to_LIST(a_1217)->aupb+=1;}
  return;
} /* extendDICT */
static void a_1224(int a_F1,int a_F2,int a_A[1]){ /* pack2+>a+>a+a> */

a_A[0]=a_F1;
a_leftclear(a_A[0],11);
a_boolor(a_A[0],a_F2,a_A[0]); return;
} /* pack2 */
static void a_1228(int a_F1,int a_A[2]){ /* unpack2+>a+a>+a> */

a_booland(a_F1,2047,a_A[1]);
a_A[0]=a_F1;
a_rightclear(a_A[0],11); return;
} /* unpack2 */
static void a_1221(int a_F1,int a_F2){ /* expandDICT+>a+>a */
int a_L3;int a_P[1];
if(!a_equal(a_F1,0)){ goto a_G3;}
a_L3=0; goto a_G5;
a_G3:a_subtr(to_LIST(a_1217)->aupb,a_F1,a_L3);
a_incr(a_L3);
a_G5:a_1224(a_L3,a_F2,a_P);a_L3=a_P[0];
a_1222(a_L3); return;
} /* expandDICT */
static void a_1220(int a_F1,int a_F2){ /* addlinetoDICT+>a+>a */

a_G1:if(!a_less(a_F2,2030)){ goto a_G3;}
a_1221(a_F1,a_F2); return;
a_G3:a_1221(a_F1,2047);
a_subtr(a_F2,2000,a_F2);
a_F1=to_LIST(a_1217)->aupb; goto a_G1;
} /* addlinetoDICT */
static void a_1219(int a_F1,int a_F2){ /* addDICT+>a+>a */
int a_L3;
if(!a_1489(22025)){ return;}
a_L3=to_LIST(a_1720)->offset[a_F1-1];
if(!a_less(a_L3,0)){ goto a_G6;}
to_LIST(a_1720)->offset[a_F1-1]=a_F2;
to_LIST(a_1720)->offset[a_F1]=0; return;
a_G6:a_subtr(a_F2,a_L3,a_L3);
if(a_lseq(a_L3,0)){ return;}
a_1220(to_LIST(a_1720)->offset[a_F1],a_L3);
to_LIST(a_1720)->offset[a_F1-1]=a_F2;
to_LIST(a_1720)->offset[a_F1]=to_LIST(a_1217)->aupb; return;
} /* addDICT */
static void a_1227(int a_F1){ /* reverseDICT+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
if(a_less(to_LIST(a_1720)->offset[a_F1-1],0)){ return;}
if(a_equal(to_LIST(a_1720)->offset[a_F1],0)){ return;}
a_L3=to_LIST(a_1720)->offset[a_F1-1];
a_L2=to_LIST(a_1720)->offset[a_F1];
a_L6=0;
a_G6:a_1228(to_LIST(a_1217)->offset[a_L2],a_P);a_L5=a_P[0];a_L4=a_P[1];
a_1224(a_L6,a_L4,a_P);to_LIST(a_1217)->offset[a_L2]=a_P[0];
{ if((1<=a_L4 && a_L4<=2019)){ goto a_G9;}
 if(a_L4==2047){ goto a_G10;}
  goto a_G11;}
a_G9:a_subtr(a_L3,a_L4,a_L3); goto a_G11;
a_G10:a_subtr(a_L3,2000,a_L3);
a_G11:if(a_equal(a_L5,0)){ goto a_G14;}
a_L6=a_L5;
a_subtr(a_L2,a_L5,a_L2); goto a_G6;
a_G14:to_LIST(a_1720)->offset[a_F1]=a_L2;
to_LIST(a_1720)->offset[a_F1-1]=a_L3; return;
} /* reverseDICT */
static int a_1223(int a_F1){ /* isspecialtag+>a */
int a_L2;int a_P[1];
a_previous(a_1720,a_F1);
if(!a_stringelem(a_1720,a_F1,0,a_P)){ return 0;}a_L2=a_P[0];
{ if((97<=a_L2 && a_L2<=122)||(65<=a_L2 && a_L2<=90)){ return 0;}
  return 1;}
} /* isspecialtag */
static void a_1218(int a_F1){ /* DICTtag+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
if(a_lseq(to_LIST(a_1720)->offset[a_F1-1],0)){ return;}
if(a_1223(a_F1)){ return;}
a_1227(a_F1);
a_L2=to_LIST(a_1720)->offset[a_F1-1];
a_L5=to_LIST(a_1720)->offset[a_F1];
a_1231(a_F1);
a_1232(a_L2);
a_G8:if(!a_equal(a_L5,0)){ goto a_G10;}
a_G9:a_1234(); return;
a_G10:a_1228(to_LIST(a_1217)->offset[a_L5],a_P);a_L4=a_P[0];a_L3=a_P[1];
{ if((1<=a_L3 && a_L3<=2019)){ goto a_G12;}
 if(a_L3==2047){ goto a_G14;}
  goto a_G15;}
a_G12:a_add(a_L2,a_L3,a_L2);
a_1232(a_L2); goto a_G15;
a_G14:a_add(a_L2,2000,a_L2);
a_G15:if(a_equal(a_L4,0)){ goto a_G9;}
a_add(a_L5,a_L4,a_L5); goto a_G8;
} /* DICTtag */
static void a_1225(int a_F1){ /* printdict+>a */
int a_L2;
a_G1:if(a_equal(a_F1,0)){ return;}
a_add(a_F1,5,a_L2);
a_1225(to_LIST(a_1720)->offset[a_L2-4]);
a_1218(a_L2);
a_F1=to_LIST(a_1720)->offset[a_L2-3]; goto a_G1;
} /* printdict */
static void a_1226(void){ /* printdictionary */
int a_L1;int a_P[1];
a_1740(a_P);a_L1=a_P[0];
a_1225(a_L1);
a_release(a_1217); return;
} /* printdictionary */
static void a_1257(int a_F1){ /* printchar+>a */

a_incr(a_1266);
a_putchar(a_1237,a_F1); return;
} /* printchar */
static void a_1252(void){ /* nlcr */

if(!a_lseq(a_1266,1)){ goto a_G3;}
a_1266=1; return;
a_G3:a_1266=0;
a_1257(10); return;
} /* nlcr */
static void a_1273(int a_F1){ /* tabline+>a */

a_G1:if(a_equal(a_1266,a_F1)){ return;}
if(!a_more(a_1266,a_F1)){ goto a_G4;}
a_1252(); goto a_G1;
a_G4:a_1257(32); goto a_G1;
} /* tabline */
static void a_1260(int a_F1){ /* printint+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G5;}
a_1257(45);
a_subtr(-1,a_F1,a_F1);
a_1261(a_F1,49); return;
a_G5:if(!a_less(a_F1,0)){ goto a_G8;}
a_1257(45);
a_getabs(a_F1,a_F1);
a_G8:a_1261(a_F1,48); return;
} /* printint */
static void a_1261(int a_F1,int a_F2){ /* printint1+>a+>a */
int a_L3;int a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1261(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_1257(a_L4); return;
} /* printint1 */
static void a_1258(int a_F1){ /* printform+>a */

a_1259(a_F1,4); return;
} /* printform */
static void a_1259(int a_F1,int a_F2){ /* printform1+>a+>a */
int a_L3;int a_L4;
if(a_equal(a_F2,0)){ return;}
a_decr(a_F2);
a_divrem11(a_F1,10,a_L3,a_L4);
a_1259(a_L3,a_F2);
a_add(a_L4,48,a_L4);
a_1257(a_L4); return;
} /* printform1 */
static void a_1255(int a_F1,int a_F2){ /* print+t[]+>a */
int a_L2;
if(!a_was(a_F1,a_F2)){ return;}
a_1886(a_1237,a_F1,a_F2);
a_stringlength(a_F1,a_F2,a_L2);
a_add(a_1266,a_L2,a_1266); return;
} /* print */
static void a_1268(void){ /* resetprline */

a_1265=0;
a_1252(); return;
} /* resetprline */
static void a_1270(void){ /* saveprpos */

if(!a_is(a_1267)){ return;}
a_1267=0;
a_1253=a_1266; return;
} /* saveprpos */
static void a_1262(int a_F1){ /* printlinehead+>a */

if(!a_is(a_F1)){ return;}
a_1252();
a_1273(1);
a_1258(a_1265);
a_1273(9); return;
} /* printlinehead */
static void a_1242(int a_F1,int a_F2){ /* displaychar+>a+>a */

if(!a_equal(a_F1,10)){ goto a_G5;}
a_incr(a_1265);
a_1267=1;
a_1262(a_F2); return;
a_G5:if(!a_is(a_F2)){ return;}
if(a_is(a_1267)){ goto a_G9;}
a_1267=1;
a_1273(a_1253);
a_G9:a_1257(a_F1); return;
} /* displaychar */
static int a_1247(int a_F1,int a_A[1]){ /* hasaleextension+>a+>a> */
int a_L3;int a_P[1];
a_decr(a_A[0]);
if(!a_stringelem(a_1374,a_F1,a_A[0],a_P)){ return 0;}a_L3=a_P[0];
if(!a_equal(a_L3,101)){ return 0;}
a_decr(a_A[0]);
if(!a_stringelem(a_1374,a_F1,a_A[0],a_P)){ return 0;}a_L3=a_P[0];
if(!a_equal(a_L3,108)){ return 0;}
a_decr(a_A[0]);
if(!a_stringelem(a_1374,a_F1,a_A[0],a_P)){ return 0;}a_L3=a_P[0];
if(!a_equal(a_L3,97)){ return 0;}
a_decr(a_A[0]);
if(!a_stringelem(a_1374,a_F1,a_A[0],a_P)){ return 0;}a_L3=a_P[0];
if(!a_equal(a_L3,46)){ return 0;} return 1;
} /* hasaleextension */
static void a_1245(int a_F1,int a_A[2]){ /* findfilebase+>a+a>+a> */
int a_L4;int a_P[1];
a_stringlength(a_1374,a_F1,a_A[1]);
a_A[0]=a_A[1];
a_G3:a_decr(a_A[0]);
if(!a_stringelem(a_1374,a_F1,a_A[0],a_P)){ goto a_G8;}a_L4=a_P[0];
if(a_equal(a_L4,47)){ goto a_G8;}
if(a_equal(a_L4,92)){ goto a_G8;}
if(!a_equal(a_L4,58)){ goto a_G3;}
a_G8:a_incr(a_A[0]);
a_P[0]=a_A[1];if(!a_1247(a_F1,a_P)){ return;}a_A[1]=a_P[0]; return;
} /* findfilebase */
static void a_1256(int a_F1){ /* printbase+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
if(a_equal(a_F1,0)){ return;}
a_1245(a_F1,a_P);a_L2=a_P[0];a_L3=a_P[1];
a_G3:if(a_mreq(a_L2,a_L3)){ return;}
if(!a_stringelem(a_1374,a_F1,a_L2,a_P)){ return;}a_L4=a_P[0];
a_incr(a_L2);
a_1257(a_L4); goto a_G3;
} /* printbase */
static void a_1264(int a_F1){ /* printsourceline+>a */
int a_L2;int a_P[2];
if(!a_equal(a_F1,-2)){ goto a_G3;}
a_G2:a_1257(45); return;
a_G3:if(a_equal(a_F1,0)){ goto a_G2;}
a_1333(a_F1,a_P);a_F1=a_P[0];a_L2=a_P[1];
if(a_lseq(a_F1,0)){ goto a_G2;}
a_1258(a_F1);
a_1257(47);
a_1256(a_L2); return;
} /* printsourceline */
static void a_1263(int a_F1){ /* printpointer+>a */

if(!a_equal(a_F1,0)){ goto a_G3;}
a_1255(a_1001,2130706108); return;
a_G3:if(!a_was(a_1236,a_F1)){ goto a_G5;}
a_1255(a_1236,a_F1); return;
a_G5:if(!a_was(a_1150,a_F1)){ goto a_G7;}
a_1255(a_1150,a_F1); return;
a_G7:if(a_1420(a_F1)){ goto a_G10;}
if(a_1759(a_F1)){ goto a_G10;}
if(!a_1762(a_F1)){ goto a_G12;}
a_G10:a_1255(a_1150,to_LIST(a_1150)->aupb);
a_unstackstring(a_1150); return;
a_G12:a_1255(a_1001,2130706104);
a_1260(a_F1);
a_1255(a_1001,2130706101); return;
} /* printpointer */
static void a_1254(int a_A[1]){ /* popBUFFER+a> */

a_A[0]=to_LIST(a_1150)->offset[to_LIST(a_1150)->aupb];
a_unstack(a_1150); return;
} /* popBUFFER */
static void a_1246(int a_C,int *a_V){ /* formatprint+@+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_L4=0;
a_G2:a_L2=to_LIST(a_1150)->aupb;
a_unpackstring(a_1236,a_V[0],a_1150);
a_L3=a_L2;
a_G5:a_incr(a_L3);
a_G6:if(!a_less(to_LIST(a_1150)->aupb,a_L3)){ goto a_G12;}
if(a_equal(a_L4,0)){ goto a_G45;}
a_decr(a_L4);
a_unstackto(a_1150,a_L2);
a_1254(a_P);a_L2=a_P[0];
a_1254(a_P);a_L3=a_P[0]; goto a_G6;
a_G12:if(!a_noteq(to_LIST(a_1150)->offset[a_L3],37)){ goto a_G14;}
a_G13:a_1257(to_LIST(a_1150)->offset[a_L3]); goto a_G5;
a_G14:a_incr(a_L3);
if(!a_less(to_LIST(a_1150)->aupb,a_L3)){ goto a_G17;}
a_1257(37); goto a_G45;
a_G17:{register int a_r1=to_LIST(a_1150)->offset[a_L3];
 if(a_r1==100){ goto a_G18;}
 if(a_r1==99){ goto a_G21;}
 if(a_r1==108){ goto a_G26;}
 if(a_r1==112){ goto a_G29;}
 if(a_r1==113){ goto a_G32;}
 if(a_r1==109){ goto a_G37;}
 if(a_r1==110){ goto a_G43;}
 if(a_r1==42){ goto a_G44;}
  goto a_G13;}
a_G18:if(a_C<=1){ goto a_G20;} a_C--;a_V+=1;
a_1260(a_V[0]); goto a_G5;
a_G20:a_1255(a_1001,2130706098); goto a_G5;
a_G21:if(a_C<=1){ goto a_G25;} a_C--;a_V+=1;
if(!a_equal(a_V[0],10)){ goto a_G24;}
a_1255(a_1001,2130706094); goto a_G5;
a_G24:a_1257(a_V[0]); goto a_G5;
a_G25:a_1255(a_1001,2130706089); goto a_G5;
a_G26:if(a_C<=1){ goto a_G28;} a_C--;a_V+=1;
a_1264(a_V[0]); goto a_G5;
a_G28:a_1255(a_1001,2130706085); goto a_G5;
a_G29:if(a_C<=1){ goto a_G31;} a_C--;a_V+=1;
a_1263(a_V[0]); goto a_G5;
a_G31:a_1255(a_1001,2130706081); goto a_G5;
a_G32:if(a_C<=1){ goto a_G36;} a_C--;a_V+=1;
if(a_equal(a_V[0],0)){ goto a_G5;}
a_1263(a_V[0]);
a_1255(a_1001,2130706077); goto a_G5;
a_G36:a_1255(a_1001,2130706074); goto a_G5;
a_G37:if(a_C<=1){ goto a_G42;} a_C--;a_V+=1;
a_incr(a_L3);
a_1244(a_L3);
a_1244(a_L2);
a_incr(a_L4); goto a_G2;
a_G42:a_1255(a_1001,2130706070); goto a_G5;
a_G43:a_1257(10); goto a_G5;
a_G44:if(a_C>1){a_C--;a_V+=1;}  goto a_G5;
a_G45:if(a_C<=1){ goto a_G47;} a_C--;a_V+=1;
a_1255(a_1001,2130706066);
a_G47:a_unstackto(a_1150,a_L2); return;
} /* formatprint */
static void a_1233(void){ /* DICTtab */
int a_L1;
a_G1:if(!a_more(a_1266,a_1269)){ goto a_G3;}
a_1273(19); return;
a_G3:a_1257(32);
a_divrem01(a_1266,6,a_L1);
if(a_equal(a_L1,1)){ return;} goto a_G1;
} /* DICTtab */
static void a_1230(int a_F1){ /* DICTdeflines+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
a_L2=to_LIST(a_1720)->offset[a_F1-2];
a_G2:if(a_equal(a_L2,0)){ return;}
if(!a_1746(a_L2,2)){ goto a_G11;}
a_1730(a_L2,a_P);a_L3=a_P[0];
a_1333(a_L3,a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1256(a_L4);
a_1257(58);
a_1258(a_L3);
a_1257(42);
a_1257(32);
a_G11:a_1735(a_L2,a_P);a_L2=a_P[0]; goto a_G2;
} /* DICTdeflines */
static void a_1231(int a_F1){ /* DICTheader+>a */
int a_P[1];
a_1252();
a_1249=0;
a_1481(22030,a_P);a_1269=a_P[0];
if(a_more(a_1269,39)){ goto a_G6;}
a_1269=40;
a_G6:a_1263(a_F1);
a_1257(32);
if(a_mreq(a_1266,10)){ goto a_G10;}
a_1273(10);
a_G10:a_1230(a_F1);
if(!a_more(a_1266,10)){ return;}
a_1273(10); return;
} /* DICTheader */
static void a_1232(int a_F1){ /* DICTitem+>a */
int a_L2;int a_L3;int a_P[2];
a_1333(a_F1,a_P);a_L3=a_P[0];a_L2=a_P[1];
if(!a_equal(a_L2,a_1249)){ goto a_G4;}
a_1233(); goto a_G11;
a_G4:a_1249=a_L2;
a_1273(10);
a_1256(a_1249);
a_1257(58);
a_1257(32);
if(a_mreq(a_1266,19)){ goto a_G11;}
a_1273(19);
a_G11:a_1258(a_L3); return;
} /* DICTitem */
static void a_1234(void){ /* DICTtail */

a_1252(); return;
} /* DICTtail */
static int a_1274(void){ /* waserror */

if(!a_more(a_1243,0)){ return 0;} return 1;
} /* waserror */
static void a_1241(int a_A[1]){ /* clearlocalerror+a> */

a_A[0]=a_1243; return;
} /* clearlocalerror */
static int a_1275(int a_F1){ /* waslocalerror+>a */

if(!a_more(a_1243,a_F1)){ return 0;} return 1;
} /* waslocalerror */
static void a_1271(int a_F1){ /* suspendErrors+>a */

a_1272=a_F1;
if(a_equal(a_1272,0)){ return;}
a_incr(a_1272); return;
} /* suspendErrors */
static void a_1251(int a_F1,int a_F2){ /* messageheader+>a+>a */

a_1270();
a_1252();
if(!a_less(a_F2,0)){ goto a_G5;}
a_1257(73); goto a_G10;
a_G5:if(!a_less(a_F2,10)){ goto a_G9;}
a_1257(87);
a_add(a_F2,48,a_F2);
a_1257(a_F2); goto a_G10;
a_G9:a_1257(69);
a_G10:if(a_equal(a_F1,0)){ goto a_G14;}
a_1273(4);
a_1264(a_F1);
a_1257(32);
a_G14:a_1273(22); return;
} /* messageheader */
static void a_1238(int a_F1,int a_C,int *a_V){ /* Xerror+>a+@+>a */
int a_P[1];
a_incr(a_1243);
if(a_more(a_1243,51)){ return;}
if(!a_equal(a_1243,51)){ goto a_G7;}
a_1251(a_F1,10);
a_P[0]=2130704621;a_1246(1,a_P);
a_G6:a_1252(); return;
a_G7:a_1251(a_F1,10);
a_1246(a_C,a_V); goto a_G6;
} /* Xerror */
static void a_1235(int a_C,int *a_V){ /* Error+@+>a */
int a_P[1];
if(!a_equal(a_1272,1)){ goto a_G7;}
a_incr(a_1243);
if(!a_equal(a_1243,51)){ return;}
a_1251(-1,10);
a_P[0]=2130704621;a_1246(1,a_P);
a_1252(); return;
a_G7:if(a_equal(a_1272,0)){ goto a_G9;}
a_decr(a_1272);
a_G9:a_1238(-1,a_C,a_V); return;
} /* Error */
static void a_1240(int a_F1,int a_F2,int a_C,int *a_V){ /* Xwarning+>a+>a+@+>a */
int a_L4;int a_P[1];
if(a_more(a_1243,51)){ return;}
a_1481(22017,a_P);a_L4=a_P[0];
if(a_less(a_F1,a_L4)){ return;}
a_1251(a_F2,a_F1);
a_1246(a_C,a_V);
a_1252(); return;
} /* Xwarning */
static void a_1250(int a_C,int *a_V){ /* message+@+>a */

if(a_more(a_1243,51)){ return;}
a_1251(-1,-1);
a_1246(a_C,a_V);
a_1252(); return;
} /* message */
static void a_1239(int a_C,int *a_V){ /* Xmessage+@+>a */

a_incr(a_1243);
a_1252();
a_1246(a_C,a_V);
a_1252(); return;
} /* Xmessage */
static void a_1248(int a_F1,int a_F2){ /* internalerror+t[]+>a */
int a_P[2];
a_1251(0,10);
a_copystring(a_F1,a_F2,a_1150);
a_P[0]=2130704647;a_P[1]=to_LIST(a_1150)->aupb;a_1246(2,a_P);
a_exit(15); return;
} /* internalerror */
static void a_1244(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1150,1);a_r1[0]=a_F1;to_LIST(a_1150)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1282(int a_F1,int a_A[2]){ /* expectpath+>a+a>+a> */
int a_P[3];
a_A[1]=0;
if(!a_equal(1164737731,a_1692)){ goto a_G5;}
a_1702();
a_incr(a_A[1]);
a_G5:if(a_1697(a_P)){a_A[0]=a_P[0]; goto a_G8;}
a_A[0]=1696719075;
a_P[0]=2130704677;a_P[1]=a_1288;a_P[2]=a_1287;a_1238(-1,3,a_P);
a_G8:a_1750(a_A[0],a_F1,a_P);a_A[0]=a_P[0];
if(!a_equal(1164737731,a_1692)){ return;}
a_1702();
a_add(a_A[1],2,a_A[1]); return;
} /* expectpath */
static void a_1284(void){ /* filearea */
int a_L1;int a_L2;int a_L3;int a_P[4];
a_L3=0;
a_G2:if(!a_1695(a_P)){ goto a_G5;}a_L1=a_P[0];a_L2=a_P[1];
a_incr(a_L3);
a_1160(a_L1,a_L2); goto a_G6;
a_G5:a_P[0]=2130704688;a_P[1]=a_1288;a_P[2]=a_1287;a_1238(-1,3,a_P);
a_G6:if(!a_equal(a_L3,32)){ goto a_G8;}
a_P[0]=2130704699;a_P[1]=a_1288;a_P[2]=a_1287;a_P[3]=32;a_1238(-1,4,a_P);
a_G8:if(!a_equal(1164737773,a_1692)){ goto a_G10;}
a_1702(); goto a_G2;
a_G10:a_1701(1164737743); return;
} /* filearea */
static void a_1285(int a_F1){ /* fileareadeclarer+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
a_1300(a_1286,a_1287,16777267,a_F1,a_P);a_L2=a_P[0];
a_1757(a_L2,2);
a_P[0]=a_L2;a_1299(a_P);a_L2=a_P[0];
a_1154(1696718924);
a_1154(16777267);
a_1162(a_L2);
a_1154(1696719027);
a_1284();
a_1154(1696718871);
a_1701(1164737725);
a_1282(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1158(a_L4);
a_1162(16777845);
a_1162(a_L3);
a_1154(1696718991); return;
} /* fileareadeclarer */
static void a_1281(int a_F1){ /* declarer+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
a_1300(a_1286,a_1287,a_1288,a_F1,a_P);a_L2=a_P[0];
a_1757(a_L2,2);
a_P[0]=a_L2;a_1299(a_P);a_L2=a_P[0];
a_1282(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1154(1696718924);
a_1154(a_1288);
a_1162(a_L2);
a_1158(a_L4);
a_1162(16777845);
a_1162(a_L3);
a_1154(1696718991); return;
} /* declarer */
static void a_1283(int a_F1){ /* externaldeclarer+>a */
int a_L2;int a_L3;int a_P[3];
a_1300(a_1286,a_1287,a_1288,a_F1,a_P);a_L3=a_P[0];
a_1757(a_L3,16);
a_1757(a_L3,2);
a_P[0]=a_L3;a_1299(a_P);a_L3=a_P[0];
if(a_1697(a_P)){a_L2=a_P[0]; goto a_G8;}
a_L2=0;
a_P[0]=2130704657;a_P[1]=a_1288;a_P[2]=a_1287;a_1238(-1,3,a_P);
a_G8:a_1154(1696718920);
a_1162(a_L3);
a_1161(a_L2);
a_1154(1696718991); return;
} /* externaldeclarer */
static void a_1289(int a_F1){ /* prototype+>a */
int a_L2;int a_L3;int a_P[1];
a_1481(22019,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,1)){ goto a_G10;}
a_1300(a_1286,a_1287,a_1288,a_F1,a_P);a_L3=a_P[0];
a_1757(a_L3,2);
a_1757(a_L3,8);
a_P[0]=a_L3;a_1299(a_P);a_L3=a_P[0];
a_1154(1696718937);
a_1162(a_L3);
a_G9:a_1154(1696718991); return;
a_G10:if(!a_equal(a_L2,2)){ goto a_G12;}
a_1154(1696718904); goto a_G13;
a_G12:a_1154(1696719000);
a_G13:a_1154(a_1288);
a_1160(a_1286,a_1287); goto a_G9;
} /* prototype */
static void a_1279(int a_A[1]){ /* declaration+>a> */
int a_L2;int a_P[2];
if(!a_1695(a_P)){ goto a_G23;}a_1286=a_P[0];a_1287=a_P[1];
a_1690(a_P);a_L2=a_P[0];
if(!a_equal(1164737725,a_1692)){ goto a_G12;}
a_1702();
if(!a_equal(a_A[0],3)){ goto a_G8;}
a_G6:a_P[0]=2130704668;a_P[1]=a_1288;a_1238(-1,2,a_P);
a_G7:a_1712(); return;
a_G8:if(!a_equal(a_A[0],1)){ goto a_G10;}
a_G9:a_1283(a_L2); return;
a_G10:a_A[0]=2;
a_1281(a_L2); return;
a_G12:if(!a_equal(a_A[0],1)){ goto a_G14;}
a_1701(1164737725); goto a_G9;
a_G14:if(!a_equal(a_1288,16777267)){ goto a_G20;}
if(!a_equal(1164737740,a_1692)){ goto a_G20;}
a_1702();
if(a_equal(a_A[0],3)){ goto a_G6;}
a_A[0]=2;
a_1285(a_L2); return;
a_G20:if(a_equal(a_A[0],2)){ goto a_G6;}
a_A[0]=3;
a_1289(a_L2); return;
a_G23:a_P[0]=2130704709;a_P[1]=a_1288;a_1238(-1,2,a_P); goto a_G7;
} /* declaration */
static void a_1280(int a_F1){ /* declarationseries+>a */
int a_P[1];
a_G1:a_P[0]=a_F1;a_1279(a_P);a_F1=a_P[0];
if(!a_equal(1164737770,a_1692)){ goto a_G4;}
a_1702(); goto a_G1;
a_G4:if(!a_equal(1164737776,a_1692)){ goto a_G6;}
a_1702(); return;
a_G6:a_1701(1164737776);
a_1715(); return;
} /* declarationseries */
static void a_1278(int a_F1){ /* datafiledeclaration+>a */

a_1288=16777267;
a_1280(a_F1); return;
} /* datafiledeclaration */
static void a_1277(int a_F1){ /* charfiledeclaration+>a */

a_1288=16777262;
a_1280(a_F1); return;
} /* charfiledeclaration */
static void a_1300(int a_F1,int a_F2,int a_F3,int a_F4,int a_A[1]){ /* createtagdefinition+>a+>a+>a+>a+a> */
int a_L6;int a_P[2];
if(a_is(a_F1)){ goto a_G3;}
a_1344(a_P);a_F1=a_P[0];
a_G3:a_L6=to_LIST(a_1720)->offset[a_F2-2];
{register int *a_r1=a_extension(a_1718,8);a_r1[0]=a_L6;a_r1[1]=a_F1;a_r1[2]=a_F4;a_r1[3]=0;a_r1[4]=a_F3;a_r1[5]=a_r1[6]=0;a_r1[7]=a_F2;to_LIST(a_1718)->aupb+=8;}
a_A[0]=to_LIST(a_1718)->aupb;
if(!a_is(a_L6)){ goto a_G10;}
if(!a_1746(a_L6,32)){ goto a_G10;}
to_LIST(a_1718)->offset[to_LIST(a_1718)->aupb-7]=0;
a_P[0]=2130704717;a_P[1]=a_F2;a_1238(-1,2,a_P); return;
a_G10:to_LIST(a_1720)->offset[a_F2-2]=a_A[0]; return;
} /* createtagdefinition */
static void a_1313(int a_F1,int a_F2){ /* pragmatttagdefinition+>a+>a */
int a_L3;int a_P[1];
a_L3=to_LIST(a_1720)->offset[a_F1-2];
a_G2:if(!a_equal(a_L3,0)){ goto a_G5;}
a_1300(0,a_F1,16777221,a_F2,a_P);a_L3=a_P[0];
a_1757(a_L3,64); return;
a_G5:if(a_1746(a_L3,64)){ return;}
if(a_1746(a_L3,2)){ return;}
a_1735(a_L3,a_P);a_L3=a_P[0]; goto a_G2;
} /* pragmatttagdefinition */
static int a_1309(int a_F1){ /* isttagdefined+>a */
int a_L2;int a_P[1];
a_L2=to_LIST(a_1720)->offset[a_F1-2];
a_G2:if(a_equal(a_L2,0)){ return 0;}
if(a_1746(a_L2,64)){ return 1;}
if(a_1746(a_L2,2)){ return 1;}
a_1735(a_L2,a_P);a_L2=a_P[0]; goto a_G2;
} /* isttagdefined */
static void a_1306(int a_F1,int a_A[2]){ /* getqfb+>a+a>+a> */
int a_P[1];
a_A[0]=to_LIST(a_1718)->offset[a_F1-6];
if(!a_1746(a_F1,64)){ goto a_G4;}
a_A[0]=0;a_A[1]=0; return;
a_G4:if(!a_equal(a_A[0],0)){ goto a_G6;}
a_A[1]=0; return;
a_G6:if(!a_was(a_1720,a_A[0])){ goto a_G8;}
a_1338(to_LIST(a_1718)->offset[a_F1-5],a_P);a_A[1]=a_P[0]; return;
a_G8:a_A[1]=a_A[0];
a_1339(a_A[1],a_P);a_A[0]=a_P[0];
if(a_is(a_A[0])){ return;}
a_A[0]=a_A[1]; return;
} /* getqfb */
static void a_1299(int a_A[1]){ /* checktagdefinition+>a> */
int a_L2;int a_L3;int a_L4;int a_P[2];
a_1306(a_A[0],a_P);a_L3=a_P[0];a_L4=a_P[1];
if(a_equal(a_L3,0)){ return;}
a_1735(a_A[0],a_P);a_L2=a_P[0];
a_G4:if(a_equal(a_L2,0)){ return;}
if(!a_1308(a_L2,a_L3,a_L4)){ goto a_G10;}
if(!a_1307(a_A[0],a_L2)){ goto a_G8;}
a_P[0]=a_A[0];a_1296(a_L2,a_P);a_A[0]=a_P[0]; return;
a_G8:a_1301(a_A[0],a_L2);
a_1315(a_A[0]); return;
a_G10:a_1735(a_L2,a_P);a_L2=a_P[0]; goto a_G4;
} /* checktagdefinition */
static int a_1308(int a_F1,int a_F2,int a_F3){ /* isonlevel+>a+>a+>a */
int a_L4;int a_L5;int a_P[2];
a_1306(a_F1,a_P);a_L4=a_P[0];a_L5=a_P[1];
if(!a_equal(a_L4,a_F2)){ return 0;}
if(!a_equal(a_L5,a_F3)){ return 0;} return 1;
} /* isonlevel */
static int a_1307(int a_F1,int a_F2){ /* havesametype+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_1741(a_F1,a_P);a_L3=a_P[0];
a_1741(a_F2,a_P);a_L4=a_P[0];
if(!a_equal(a_L3,a_L4)){ return 0;}
{ if(a_L3==16777271){ goto a_G5;}
 if(a_L3==16777240||a_L3==16777244||a_L3==16777250){ goto a_G11;}
  return 1;}
a_G5:a_1738(a_F1,1792,a_P);a_L3=a_P[0];
a_1738(a_F2,1792,a_P);a_L4=a_P[0];
if(!a_equal(a_L3,a_L4)){ return 0;}
a_1729(a_F1,a_P);a_L3=a_P[0];
a_1729(a_F2,a_P);a_L4=a_P[0];
a_G10:if(!a_equal(a_L3,a_L4)){ return 0;} return 1;
a_G11:a_1677(a_F1,a_P);a_L3=a_P[0];
a_1677(a_F2,a_P);a_L4=a_P[0];
if(!a_equal(a_L3,a_L4)){ return 0;}
a_1680(a_F1,a_P);a_L3=a_P[0];
a_1680(a_F2,a_P);a_L4=a_P[0]; goto a_G10;
} /* havesametype */
static void a_1296(int a_F2,int a_A[1]){ /* checkimported+>a>+>a */

if(!a_1746(a_A[0],8)){ goto a_G6;}
if(!a_1746(a_F2,8)){ goto a_G6;}
a_1315(a_A[0]);
a_1314(a_A[0]);
a_A[0]=a_F2; return;
a_G6:a_1301(a_A[0],a_F2);
a_1315(a_A[0]); return;
} /* checkimported */
static void a_1301(int a_F1,int a_F2){ /* doublydefinederror+>a+>a */
int a_P[3];
a_P[0]=2130704725;a_P[1]=a_F1;a_P[2]=to_LIST(a_1718)->offset[a_F2-5];a_1238(to_LIST(a_1718)->offset[a_F1-5],3,a_P); return;
} /* doublydefinederror */
static void a_1315(int a_F1){ /* unlinktag+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_1739(a_F1,a_P);a_L2=a_P[0];
a_L4=to_LIST(a_1720)->offset[a_L2-2];
a_1735(a_F1,a_P);a_L3=a_P[0];
a_G4:if(!a_equal(a_L4,a_F1)){ goto a_G6;}
to_LIST(a_1720)->offset[a_L2-2]=a_L3; return;
a_G6:if(!a_equal(a_L4,0)){ goto a_G8;}
a_1248(a_1001,2130706118); return;
a_G8:if(!a_equal(to_LIST(a_1718)->offset[a_L4-7],a_F1)){ goto a_G10;}
to_LIST(a_1718)->offset[a_L4-7]=a_L3; return;
a_G10:a_1735(a_L4,a_P);a_L4=a_P[0]; goto a_G4;
} /* unlinktag */
static void a_1314(int a_F1){ /* reclaimtag+>a */

if(!a_equal(a_F1,to_LIST(a_1718)->aupb)){ return;}
a_unstack(a_1718); return;
} /* reclaimtag */
static void a_1294(void){ /* checkallttags */
int a_L1;int a_P[1];
a_1740(a_P);a_L1=a_P[0];
a_1295(a_L1); return;
} /* checkallttags */
static void a_1295(int a_F1){ /* checkdblettag+>a */
int a_L2;
a_G1:if(a_equal(a_F1,0)){ return;}
a_add(a_F1,5,a_L2);
a_1295(to_LIST(a_1720)->offset[a_L2-4]);
a_1298(a_L2);
a_1292(to_LIST(a_1720)->offset[a_L2-2]);
a_F1=to_LIST(a_1720)->offset[a_L2-3]; goto a_G1;
} /* checkdblettag */
static void a_1298(int a_F1){ /* checksinglettag+>a */
int a_L2;int a_L3;int a_P[1];
a_G1:a_L2=to_LIST(a_1720)->offset[a_F1-2];
a_G2:if(a_equal(a_L2,0)){ return;}
a_1297(a_L2,a_P);a_L3=a_P[0];
if(a_is(a_L3)){ goto a_G1;}
a_1735(a_L2,a_P);a_L2=a_P[0]; goto a_G2;
} /* checksinglettag */
static void a_1297(int a_F1,int a_A[1]){ /* checksingletag+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[2];
a_1306(a_F1,a_P);a_L4=a_P[0];a_L5=a_P[1];
a_1735(a_F1,a_P);a_L3=a_P[0];
a_G3:if(!a_equal(a_L3,0)){ goto a_G5;}
a_A[0]=0; return;
a_G5:if(!a_1308(a_L3,a_L4,a_L5)){ goto a_G11;}
a_A[0]=1;
if(!a_1307(a_F1,a_L3)){ goto a_G9;}
a_P[0]=a_F1;a_1296(a_L3,a_P); return;
a_G9:a_1301(a_F1,a_L3);
a_1315(a_F1); return;
a_G11:a_1735(a_L3,a_P);a_L3=a_P[0]; goto a_G3;
} /* checksingletag */
static void a_1292(int a_F1){ /* canonizedefs+>a */
int a_L2;int a_P[1];
a_G1:if(a_equal(a_F1,0)){ return;}
if(!a_1746(a_F1,2)){ goto a_G6;}
a_L2=to_LIST(a_1718)->offset[a_F1-6];
if(!a_was(a_1720,a_L2)){ goto a_G6;}
a_1293(a_F1,a_L2);
a_G6:a_1735(a_F1,a_P);a_F1=a_P[0]; goto a_G1;
} /* canonizedefs */
static void a_1293(int a_F1,int a_F2){ /* canonizesingletag+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_1338(to_LIST(a_1718)->offset[a_F1-5],a_P);a_L3=a_P[0];
a_1339(a_L3,a_P);a_L4=a_P[0];
if(!a_equal(a_L4,a_F2)){ return;}
to_LIST(a_1718)->offset[a_F1-6]=a_L3; return;
} /* canonizesingletag */
static int a_1312(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* matchtagbelow+>a+>a+>a+a> */
int a_L5;int a_L6;int a_P[1];
if(!a_1746(a_F3,2)){ return 0;}
a_L5=to_LIST(a_1718)->offset[a_F3-6];
if(!a_is(a_L5)){ return 0;}
if(!a_was(a_1720,a_L5)){ goto a_G7;}
if(!a_equal(a_L5,a_F2)){ return 0;}
a_1338(to_LIST(a_1718)->offset[a_F3-5],a_P);a_L5=a_P[0]; goto a_G9;
a_G7:a_1339(a_L5,a_P);a_L6=a_P[0];
if(!a_equal(a_L6,a_F2)){ return 0;}
a_G9:a_1335(a_L5,a_F1,a_P);a_A[0]=a_P[0];
if(!a_more(a_A[0],0)){ return 0;}
a_1335(a_1291,a_L5,a_P);a_A[0]=a_P[0]; return 1;
} /* matchtagbelow */
static int a_1311(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* matchtagabove+>a+>a+>a+a> */
int a_L5;int a_P[1];
if(!a_1746(a_F3,2)){ return 0;}
a_L5=to_LIST(a_1718)->offset[a_F3-6];
if(!a_equal(a_L5,0)){ goto a_G5;}
a_A[0]=0; return 1;
a_G5:if(!a_was(a_1720,a_L5)){ goto a_G8;}
if(!a_equal(a_L5,a_F2)){ return 0;}
a_1338(to_LIST(a_1718)->offset[a_F3-5],a_P);a_L5=a_P[0];
a_G8:a_1335(a_F1,a_L5,a_P);a_A[0]=a_P[0];
if(!a_mreq(a_A[0],0)){ return 0;} return 1;
} /* matchtagabove */
static int a_1310(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* matchqtagabove+>a+>a+>a+a> */
int a_L5;int a_L6;int a_P[1];
if(!a_1746(a_F3,2)){ return 0;}
a_L5=to_LIST(a_1718)->offset[a_F3-6];
if(!a_is(a_L5)){ return 0;}
if(!a_was(a_1720,a_L5)){ goto a_G7;}
if(!a_equal(a_L5,a_F2)){ return 0;}
a_1338(to_LIST(a_1718)->offset[a_F3-5],a_P);a_L5=a_P[0]; goto a_G9;
a_G7:a_1339(a_L5,a_P);a_L6=a_P[0];
if(!a_equal(a_L6,a_F2)){ return 0;}
a_G9:a_1335(a_F1,a_L5,a_P);a_A[0]=a_P[0];
if(!a_mreq(a_A[0],0)){ return 0;} return 1;
} /* matchqtagabove */
static int a_1303(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* finddefinitionbelow+>a+>a+>a+a> */
int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_L10;int a_P[5];
if(a_equal(a_F1,a_1291)){ return 0;}
a_L9=to_LIST(a_1720)->offset[a_F3-2];
a_L6=-1;a_L8=-1;
a_A[0]=0;a_L7=0;
if(!a_is(a_F2)){ goto a_G7;}
a_L10=a_F2; goto a_G8;
a_G7:a_1339(a_F1,a_P);a_L10=a_P[0];
a_G8:if(!a_equal(a_L9,0)){ goto a_G14;}
if(!a_mreq(a_L6,0)){ return 0;}
if(a_equal(a_L8,-1)){ return 1;}
if(a_less(a_L6,a_L8)){ return 1;}
a_P[0]=2130704737;a_P[1]=a_F2;a_P[2]=a_F3;a_P[3]=to_LIST(a_1718)->offset[a_A[0]-5];a_P[4]=to_LIST(a_1718)->offset[a_L7-5];a_1238(-1,5,a_P);
a_A[0]=0; return 1;
a_G14:if(!a_1312(a_F1,a_L10,a_L9,a_P)){ goto a_G21;}a_L5=a_P[0];
if(a_less(a_L6,0)){ goto a_G17;}
if(!a_lseq(a_L5,a_L6)){ goto a_G21;}
a_G17:a_L8=a_L6;
a_L7=a_A[0];
a_L6=a_L5;
a_A[0]=a_L9;
a_G21:a_1735(a_L9,a_P);a_L9=a_P[0]; goto a_G8;
} /* finddefinitionbelow */
static int a_1302(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* finddefinitionabove+>a+>a+>a+a> */
int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_L10;int a_P[5];
a_L9=to_LIST(a_1720)->offset[a_F3-2];
a_L6=-1;a_L8=-1;
a_A[0]=0;a_L7=0;
a_1339(a_F1,a_P);a_L10=a_P[0];
a_G5:if(!a_equal(a_L9,0)){ goto a_G11;}
if(!a_mreq(a_L6,0)){ return 0;}
if(a_equal(a_L8,-1)){ return 1;}
if(a_less(a_L6,a_L8)){ return 1;}
a_P[0]=2130704737;a_P[1]=a_F2;a_P[2]=a_F3;a_P[3]=to_LIST(a_1718)->offset[a_A[0]-5];a_P[4]=to_LIST(a_1718)->offset[a_L7-5];a_1238(-1,5,a_P);
a_A[0]=0; return 1;
a_G11:if(!a_is(a_F2)){ goto a_G13;}
if(a_1310(a_F1,a_F2,a_L9,a_P)){a_L5=a_P[0]; goto a_G14;} goto a_G20;
a_G13:if(!a_1311(a_F1,a_L10,a_L9,a_P)){ goto a_G20;}a_L5=a_P[0];
a_G14:if(a_less(a_L6,0)){ goto a_G16;}
if(!a_lseq(a_L5,a_L6)){ goto a_G20;}
a_G16:a_L8=a_L6;
a_L7=a_A[0];
a_L6=a_L5;
a_A[0]=a_L9;
a_G20:a_1735(a_L9,a_P);a_L9=a_P[0]; goto a_G5;
} /* finddefinitionabove */
static void a_1304(int a_F1,int a_F2,int a_A[1]){ /* findttagdefinition+>a+>a+a> */
int a_L4;int a_P[3];
a_1344(a_P);a_L4=a_P[0];
if(a_1303(a_L4,a_F1,a_F2,a_P)){a_A[0]=a_P[0]; return;}
if(a_1302(a_L4,a_F1,a_F2,a_P)){a_A[0]=a_P[0]; return;}
a_P[0]=2130704745;a_P[1]=a_F1;a_P[2]=a_F2;a_1238(-1,3,a_P);
a_A[0]=0; return;
} /* findttagdefinition */
static void a_1305(int a_F1,int a_A[1]){ /* getmodulerank+>a+a> */
int a_L3;int a_P[2];
a_1306(a_F1,a_P);a_L3=a_P[1];
if(!a_equal(a_L3,0)){ goto a_G4;}
a_A[0]=2; return;
a_G4:a_1335(a_1291,a_L3,a_P);a_A[0]=a_P[0]; return;
} /* getmodulerank */
static void a_1290(void){ /* @root */
int a_P[1];
a_1338(-1,a_P);a_1291=a_P[0]; return;
} /* @root */
static void a_1322(int a_F1,int a_F2,int a_F3){ /* addinputentry+>a+>a+>a */
int a_P[2];
if(a_more(a_1346,200)){ return;}
if(!a_equal(a_1346,200)){ goto a_G5;}
a_incr(a_1346);
a_P[0]=2130704757;a_P[1]=200;a_1238(0,2,a_P); return;
a_G5:a_incr(a_1346);
{register int *a_r1=a_extension(a_1317,7);a_r1[0]=a_F1;a_r1[2]=a_F2;a_r1[6]=a_F3;a_r1[1]=a_r1[3]=0;a_r1[4]=a_r1[5]=-1;to_LIST(a_1317)->aupb+=7;}
  return;
} /* addinputentry */
static int a_1350(int a_F1,int a_F2){ /* isinputtype+>a+>a */

if(!a_equal(to_LIST(a_1317)->offset[a_F1-6],a_F2)){ return 0;} return 1;
} /* isinputtype */
static void a_1336(int a_F1,int a_A[1]){ /* findsourcefromlineno+>a+a> */

if(!a_less(a_F1,0)){ goto a_G3;}
a_A[0]=1178737320; return;
a_G3:a_A[0]=to_LIST(a_1317)->alwb;
a_G4:if(!a_more(a_A[0],to_LIST(a_1317)->aupb)){ goto a_G6;}
a_1248(a_1001,2130706171); return;
a_G6:if(!a_lseq(to_LIST(a_1317)->offset[a_A[0]-2],a_F1)){ goto a_G8;}
if(a_lseq(a_F1,to_LIST(a_1317)->offset[a_A[0]-1])){ return;}
a_G8:a_next(a_1317,a_A[0]); goto a_G4;
} /* findsourcefromlineno */
static void a_1333(int a_F1,int a_A[2]){ /* findlinenum+>a+a>+a> */
int a_L4;int a_P[1];
if(a_more(a_F1,0)){ goto a_G3;}
a_1690(a_P);a_F1=a_P[0];
a_G3:a_1336(a_F1,a_P);a_L4=a_P[0];
if(!a_more(a_L4,to_LIST(a_1317)->aupb)){ goto a_G7;}
a_A[0]=0;
a_A[1]=1696719075; return;
a_G7:a_subtr(a_F1,to_LIST(a_1317)->offset[a_L4-2],a_A[0]);
a_incr(a_A[0]);
a_A[1]=to_LIST(a_1317)->offset[a_L4]; return;
} /* findlinenum */
static void a_1340(int a_A[1]){ /* getfirstsource+a> */
int a_L2;
a_L2=to_LIST(a_1317)->alwb;
a_G2:if(!a_more(a_L2,to_LIST(a_1317)->aupb)){ goto a_G4;}
a_A[0]=1696719075; return;
a_G4:if(!a_1350(a_L2,7)){ goto a_G6;}
a_A[0]=to_LIST(a_1317)->offset[a_L2]; return;
a_G6:a_next(a_1317,a_L2); goto a_G2;
} /* getfirstsource */
static void a_1337(int a_A[1]){ /* firstlineoffset+a> */
int a_L2;
a_L2=to_LIST(a_1317)->alwb;
a_G2:if(!a_more(a_L2,to_LIST(a_1317)->aupb)){ goto a_G4;}
a_A[0]=1; return;
a_G4:if(!a_1350(a_L2,7)){ goto a_G6;}
a_A[0]=to_LIST(a_1317)->offset[a_L2-2]; return;
a_G6:a_next(a_1317,a_L2); goto a_G2;
} /* firstlineoffset */
static int a_1354(int a_A[4]){ /* nextinputentry+>a>+a>+a>+a> */

if(a_is(a_A[0])){ goto a_G3;}
a_A[0]=to_LIST(a_1317)->alwb;
a_G3:if(a_more(a_A[0],to_LIST(a_1317)->aupb)){ return 0;}
if(!a_less(to_LIST(a_1317)->offset[a_A[0]-2],0)){ goto a_G6;}
a_G5:a_next(a_1317,a_A[0]); goto a_G3;
a_G6:if(a_1350(a_A[0],4)){ goto a_G5;}
if(a_1350(a_A[0],5)){ goto a_G5;}
a_A[1]=to_LIST(a_1317)->offset[a_A[0]-2];
a_A[2]=to_LIST(a_1317)->offset[a_A[0]-1];
a_A[3]=to_LIST(a_1317)->offset[a_A[0]];
a_next(a_1317,a_A[0]); return 1;
} /* nextinputentry */
static int a_1349(int a_F1){ /* isinputflag+>a */

if(!a_1350(a_1371,7)){ return 0;}
a_booland(a_F1,to_LIST(a_1317)->offset[a_1371-3],a_F1);
if(!a_is(a_F1)){ return 0;} return 1;
} /* isinputflag */
static void a_1341(int a_F1,int a_A[1]){ /* getinputbase+>a+a> */

if(!a_1350(a_F1,7)){ goto a_G3;}
a_G2:a_A[0]=to_LIST(a_1317)->offset[a_F1-4]; return;
a_G3:if(a_1350(a_F1,4)){ goto a_G2;}
a_A[0]=a_F1; return;
} /* getinputbase */
static void a_1342(int a_F1,int a_A[1]){ /* getinputhead+>a+a> */

a_G1:if(!a_1350(a_F1,6)){ goto a_G3;}
a_F1=to_LIST(a_1317)->offset[a_F1-4]; goto a_G1;
a_G3:a_A[0]=a_F1; return;
} /* getinputhead */
static void a_1356(void){ /* preparethissource */
int a_P[1];
a_1341(a_1371,a_P);a_1369=a_P[0];
a_1342(a_1369,a_P);a_1370=a_P[0]; return;
} /* preparethissource */
static void a_1364(int a_F1){ /* setsourcefromlineno+>a */
int a_P[1];
a_1336(a_F1,a_P);a_1371=a_P[0];
a_1356(); return;
} /* setsourcefromlineno */
static void a_1338(int a_F1,int a_A[1]){ /* getbasefromlineno+>a+a> */
int a_P[1];
a_1336(a_F1,a_P);a_A[0]=a_P[0];
a_1341(a_A[0],a_P);a_A[0]=a_P[0]; return;
} /* getbasefromlineno */
static void a_1339(int a_F1,int a_A[1]){ /* getbasename+>a+a> */

if(!a_was(a_1317,a_F1)){ goto a_G3;}
a_A[0]=to_LIST(a_1317)->offset[a_F1-3]; return;
a_G3:a_1248(a_1001,2130706163); return;
} /* getbasename */
static void a_1344(int a_A[1]){ /* getsourcebase+a> */

a_A[0]=a_1369; return;
} /* getsourcebase */
static void a_1343(int a_A[1]){ /* getmoduletag+a> */

a_A[0]=to_LIST(a_1317)->offset[a_1369-3]; return;
} /* getmoduletag */
static void a_1359(int a_F1){ /* putmoduletag+>a */

if(!a_equal(to_LIST(a_1317)->offset[a_1369-3],0)){ return;}
to_LIST(a_1317)->offset[a_1369-3]=a_F1; return;
} /* putmoduletag */
static void a_1320(int a_F1,int a_F2){ /* addedge+>a+>a */
int a_L3;int a_L4;int a_P[1];
if(a_equal(a_F1,a_F2)){ return;}
a_L3=to_LIST(a_1317)->alwb;
a_G3:if(a_more(a_L3,to_LIST(a_1317)->aupb)){ return;}
if(!a_1350(a_L3,6)){ goto a_G9;}
a_1334(a_F2,a_L3,a_P);a_L4=a_P[0];
if(a_less(a_L4,0)){ goto a_G9;}
a_incr(a_L4);
a_1329(a_F1,a_L3,a_L4);
a_G9:a_next(a_1317,a_L3); goto a_G3;
} /* addedge */
static void a_1334(int a_F1,int a_F2,int a_A[1]){ /* findlocalrank+>a+>a+a> */
int a_L4;
if(!a_equal(a_F2,a_F1)){ goto a_G3;}
a_A[0]=0; return;
a_G3:a_L4=to_LIST(a_1317)->offset[a_F2-5];
a_G4:if(!a_equal(a_L4,0)){ goto a_G6;}
a_A[0]=-1; return;
a_G6:if(!a_equal(to_LIST(a_1318)->offset[a_L4-1],a_F1)){ goto a_G8;}
a_A[0]=to_LIST(a_1318)->offset[a_L4]; return;
a_G8:a_L4=to_LIST(a_1318)->offset[a_L4-2]; goto a_G4;
} /* findlocalrank */
static void a_1329(int a_F1,int a_F2,int a_F3){ /* correctranksfrom+>a+>a+>a */
int a_L4;int a_L5;
a_1328(a_F1,a_F2,a_F3);
a_L4=to_LIST(a_1317)->offset[a_F1-5];
a_G3:if(a_equal(a_L4,0)){ return;}
a_add(a_F3,to_LIST(a_1318)->offset[a_L4],a_L5);
a_1328(to_LIST(a_1318)->offset[a_L4-1],a_F2,a_L5);
a_L4=to_LIST(a_1318)->offset[a_L4-2]; goto a_G3;
} /* correctranksfrom */
static void a_1328(int a_F1,int a_F2,int a_F3){ /* correctrank+>a+>a+>a */
int a_L4;int a_P[1];
a_1334(a_F1,a_F2,a_P);a_L4=a_P[0];
if(!a_less(a_L4,0)){ goto a_G4;}
a_G3:a_1324(a_F1,a_F2,a_F3); return;
a_G4:if(!a_less(a_F3,a_L4)){ return;} goto a_G3;
} /* correctrank */
static void a_1324(int a_F1,int a_F2,int a_F3){ /* addnewrank+>a+>a+>a */
int a_L4;
if(!a_equal(to_LIST(a_1317)->offset[a_F2-5],0)){ goto a_G4;}
{register int *a_r1=a_extension(a_1318,3);a_r1[0]=0;a_r1[1]=a_F1;a_r1[2]=a_F3;to_LIST(a_1318)->aupb+=3;}
to_LIST(a_1317)->offset[a_F2-5]=to_LIST(a_1318)->aupb; return;
a_G4:a_L4=to_LIST(a_1317)->offset[a_F2-5];
a_G5:if(!a_equal(to_LIST(a_1318)->offset[a_L4-1],a_F1)){ goto a_G7;}
to_LIST(a_1318)->offset[a_L4]=a_F3; return;
a_G7:if(!a_equal(to_LIST(a_1318)->offset[a_L4-2],0)){ goto a_G10;}
{register int *a_r1=a_extension(a_1318,3);a_r1[0]=0;a_r1[1]=a_F1;a_r1[2]=a_F3;to_LIST(a_1318)->aupb+=3;}
to_LIST(a_1318)->offset[a_L4-2]=to_LIST(a_1318)->aupb; return;
a_G10:a_L4=to_LIST(a_1318)->offset[a_L4-2]; goto a_G5;
} /* addnewrank */
static void a_1335(int a_F1,int a_F2,int a_A[1]){ /* findrankabove+>a+>a+a> */
int a_L4;int a_L5;int a_P[1];
a_1334(a_F1,a_F2,a_P);a_A[0]=a_P[0];
if(a_mreq(a_A[0],0)){ return;}
a_L5=201;
a_1342(a_F1,a_P);a_L4=a_P[0];
a_G5:a_next(a_1317,a_L4);
a_1334(a_L4,a_F2,a_P);a_A[0]=a_P[0];
if(!a_mreq(a_A[0],0)){ goto a_G9;}
a_add(a_A[0],a_L5,a_A[0]); return;
a_G9:if(a_mreq(a_L4,1178737334)){ return;}
a_add(201,a_L5,a_L5); goto a_G5;
} /* findrankabove */
static void a_1325(int a_F1){ /* addrequiredsource+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=to_LIST(a_1317)->alwb;
a_G2:if(!a_more(a_L2,to_LIST(a_1317)->aupb)){ goto a_G5;}
a_1322(6,a_1369,a_F1);
a_1320(a_1369,to_LIST(a_1317)->aupb); return;
a_G5:if(!a_1350(a_L2,6)){ goto a_G10;}
a_comparestring(a_1374,a_F1,a_1374,to_LIST(a_1317)->offset[a_L2],a_P);a_L3=a_P[0];
if(!a_equal(a_L3,0)){ goto a_G10;}
a_1387(a_F1);
a_1320(a_1369,a_L2); return;
a_G10:a_next(a_1317,a_L2); goto a_G2;
} /* addrequiredsource */
static void a_1321(int a_F1){ /* addincludedsource+>a */
int a_L2;int a_P[1];
a_1322(7,a_1369,a_F1);
a_1481(22019,a_P);a_L2=a_P[0];
if(!a_1489(22024)){ goto a_G5;}
a_add(a_L2,4,a_L2);
a_G5:to_LIST(a_1317)->offset[to_LIST(a_1317)->aupb-3]=a_L2; return;
} /* addincludedsource */
static void a_1323(int a_F1){ /* addlibrarysource+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=to_LIST(a_1317)->alwb;
a_G2:if(!a_more(a_L2,to_LIST(a_1317)->aupb)){ goto a_G4;}
a_1322(8,1178737327,a_F1); return;
a_G4:if(!a_1350(a_L2,8)){ goto a_G8;}
a_comparestring(a_1374,a_F1,a_1374,to_LIST(a_1317)->offset[a_L2],a_P);a_L3=a_P[0];
if(!a_equal(a_L3,0)){ goto a_G8;}
a_1387(a_F1); return;
a_G8:a_next(a_1317,a_L2); goto a_G2;
} /* addlibrarysource */
static void a_1357(void){ /* prepareuserlibraries */
int a_L1;
a_1371=1178737327;
a_1356();
a_L1=to_LIST(a_1317)->alwb;
a_G4:if(a_more(a_L1,to_LIST(a_1317)->aupb)){ return;}
if(!a_1350(a_L1,8)){ goto a_G7;}
a_1353(a_L1);
a_G7:a_next(a_1317,a_L1); goto a_G4;
} /* prepareuserlibraries */
static void a_1353(int a_F1){ /* movelibrarysource+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
a_L3=to_LIST(a_1317)->offset[a_F1];
a_L2=to_LIST(a_1317)->alwb;
a_G3:if(!a_more(a_L2,to_LIST(a_1317)->aupb)){ goto a_G6;}
to_LIST(a_1317)->offset[a_F1-6]=6;
a_1320(a_1369,a_F1); return;
a_G6:if(!a_1350(a_L2,6)){ goto a_G11;}
a_comparestring(a_1374,a_L3,a_1374,to_LIST(a_1317)->offset[a_L2],a_P);a_L4=a_P[0];
if(!a_equal(a_L4,0)){ goto a_G11;}
to_LIST(a_1317)->offset[a_F1-6]=9;
a_1320(a_1369,a_L2); return;
a_G11:a_next(a_1317,a_L2); goto a_G3;
} /* movelibrarysource */
static void a_1355(int a_F1){ /* preparestandardlibrary+>a */

a_1371=1178737334;
a_1356();
a_1325(a_F1); return;
} /* preparestandardlibrary */
static void a_1365(int a_F1){ /* setsrcpragmats+>a */
int a_L2;int a_L3;
if(!a_equal(a_F1,6)){ goto a_G4;}
a_1507(22024,0);
a_1507(22019,1); return;
a_G4:a_L2=to_LIST(a_1317)->offset[a_1371-3];
a_booland(a_L2,3,a_L3);
a_1507(22019,a_L3);
a_booland(a_L2,4,a_L3);
a_1507(22024,a_L3); return;
} /* setsrcpragmats */
static int a_1347(int a_F1,int a_A[3]){ /* iscmdlinepragmat+>a+a>+a>+a> */
int a_L5;int a_P[1];
a_comparestring(a_1374,a_F1,a_1001,2130706158,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G6;}
a_A[1]=22025;
a_G4:a_A[0]=0;
a_A[2]=1; return 1;
a_G6:a_comparestring(a_1374,a_F1,a_1001,2130706155,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G9;}
a_A[1]=22023; goto a_G4;
a_G9:a_comparestring(a_1374,a_F1,a_1001,2130706152,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G14;}
a_A[1]=22017;
a_A[0]=0;
a_A[2]=3; return 1;
a_G14:a_comparestring(a_1374,a_F1,a_1001,2130706149,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G19;}
a_A[1]=22017;
a_G17:a_A[0]=0;
a_G18:a_A[2]=0; return 1;
a_G19:a_comparestring(a_1374,a_F1,a_1001,2130706145,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G23;}
a_A[1]=22033;
a_G22:a_A[0]=1; goto a_G18;
a_G23:a_comparestring(a_1374,a_F1,a_1001,2130706142,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G26;}
a_A[1]=22037; goto a_G22;
a_G26:a_comparestring(a_1374,a_F1,a_1001,2130706139,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G29;}
a_A[1]=22038; goto a_G22;
a_G29:a_comparestring(a_1374,a_F1,a_1001,2130706136,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G32;}
a_A[1]=22036; goto a_G22;
a_G32:a_comparestring(a_1374,a_F1,a_1001,2130706133,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G35;}
a_A[1]=22034; goto a_G22;
a_G35:a_comparestring(a_1374,a_F1,a_1001,2130706130,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G38;}
a_A[1]=22035; goto a_G22;
a_G38:if(!a_stringelem(a_1374,a_F1,0,a_P)){ return 0;}a_L5=a_P[0];
if(!a_equal(a_L5,45)){ return 0;}
if(!a_stringelem(a_1374,a_F1,1,a_P)){ return 0;}a_L5=a_P[0];
if(!a_equal(a_L5,45)){ return 0;}
a_A[1]=-1; goto a_G17;
} /* iscmdlinepragmat */
static void a_1319(int a_F1,int a_A[1]){ /* addcommandlinearg+>a+>a> */
int a_P[3];
if(!a_is(a_A[0])){ goto a_G4;}
a_A[0]=0;
a_1322(5,0,a_F1); return;
a_G4:if(!a_1347(a_F1,a_P)){ goto a_G6;}a_A[0]=a_P[0];
a_1322(4,1178737320,a_F1); return;
a_G6:a_1322(7,a_1369,a_F1);
to_LIST(a_1317)->offset[to_LIST(a_1317)->aupb-3]=12; return;
} /* addcommandlinearg */
static void a_1345(void){ /* initprogramargs */
int a_L1;int a_L2;int a_P[1];
a_L1=to_LIST(a_1889)->aupb;
a_L2=0;
a_G3:if(!a_less(a_L1,to_LIST(a_1889)->alwb)){ goto a_G6;}
if(a_equal(a_L2,0)){ return;}
a_P[0]=2130704769;a_1238(0,1,a_P); return;
a_G6:a_copystring(a_1889,a_L1,a_1374);
a_P[0]=a_L2;a_1319(to_LIST(a_1374)->aupb,a_P);a_L2=a_P[0];
a_previousstring(a_1889,a_L1); goto a_G3;
} /* initprogramargs */
static int a_1348(int a_F1){ /* ishelpargument+>a */
int a_L2;int a_P[4];
a_comparestring(a_1374,to_LIST(a_1317)->offset[a_F1],a_1001,2130706127,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return 0;}
a_P[0]=2130704491;a_P[1]=58;a_P[2]=58;a_P[3]=3;a_1239(4,a_P); return 1;
} /* ishelpargument */
static int a_1351(int a_F1){ /* isversionargument+>a */
int a_L2;int a_P[3];
a_comparestring(a_1374,to_LIST(a_1317)->offset[a_F1],a_1001,2130706123,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return 0;}
a_P[0]=2130704561;a_P[1]=2;a_P[2]=3;a_1239(3,a_P); return 1;
} /* isversionargument */
static void a_1360(void){ /* readcommandlinearguments */
int a_L1;int a_L2;int a_P[1];
a_1371=1178737320;
a_1356();
a_1345();
if(a_1274()){ return;}
a_L1=0;
a_L2=to_LIST(a_1317)->alwb;
a_G7:if(a_more(a_L2,to_LIST(a_1317)->aupb)){ goto a_G15;}
if(!a_1350(a_L2,7)){ goto a_G11;}
a_incr(a_L1);
a_G10:a_next(a_1317,a_L2); goto a_G7;
a_G11:if(!a_1350(a_L2,4)){ goto a_G10;}
if(!a_1348(a_L2)){ goto a_G14;}
a_G13:a_incr(a_L1); goto a_G15;
a_G14:if(a_1351(a_L2)){ goto a_G13;} goto a_G10;
a_G15:if(a_more(a_L1,0)){ return;}
a_P[0]=2130704784;a_1238(0,1,a_P); return;
} /* readcommandlinearguments */
static void a_1367(void){ /* startline */
int a_P[1];
a_1690(a_P);to_LIST(a_1317)->offset[a_1371-2]=a_P[0];
to_LIST(a_1317)->offset[a_1371-1]=2147483647; return;
} /* startline */
static void a_1332(void){ /* endline */
int a_P[1];
a_1690(a_P);to_LIST(a_1317)->offset[a_1371-1]=a_P[0]; return;
} /* endline */
static int a_1330(void){ /* dopragmat */
int a_L1;int a_L2;int a_L3;int a_P[3];
if(!a_1350(a_1371,4)){ return 0;}
if(!a_less(to_LIST(a_1317)->offset[a_1371-2],0)){ return 0;}
if(!a_1347(to_LIST(a_1317)->offset[a_1371],a_P)){ return 0;}a_L1=a_P[0];a_L2=a_P[1];a_L3=a_P[2];
a_1685();
a_1367();
a_1356();
if(!a_less(a_L2,0)){ goto a_G13;}
if(!a_1396(0,to_LIST(a_1317)->offset[a_1371])){ goto a_G12;}
a_1702();
a_1473();
a_1382();
a_G12:a_1332(); return 1;
a_G13:if(!a_is(a_L1)){ goto a_G18;}
a_1332();
a_next(a_1317,a_1371);
a_1367();
a_1507(a_L2,to_LIST(a_1317)->offset[a_1371]); goto a_G12;
a_G18:a_1507(a_L2,a_L3); goto a_G12;
} /* dopragmat */
static int a_1331(int a_F1,int a_F2){ /* dosource+>a+>a */
int a_L3;int a_P[2];
if(!a_1350(a_1371,a_F1)){ return 0;}
if(!a_less(to_LIST(a_1317)->offset[a_1371-2],0)){ return 0;}
a_1685();
a_1367();
a_1356();
a_1365(a_F1);
if(!a_equal(a_F2,3)){ goto a_G9;}
a_L3=3; goto a_G12;
a_G9:if(!a_1349(8)){ goto a_G11;}
a_L3=1; goto a_G12;
a_G11:a_L3=2;
a_G12:if(!a_1396(a_L3,to_LIST(a_1317)->offset[a_1371])){ goto a_G17;}
a_1716();
a_1702();
a_1458();
a_1382(); goto a_G19;
a_G17:a_P[0]=2130704792;a_P[1]=to_LIST(a_1317)->offset[a_1371];a_1238(0,2,a_P);
to_LIST(a_1317)->offset[a_1371-6]=9;
a_G19:a_1332();
a_1504(); return 1;
} /* dosource */
static void a_1358(int a_F1){ /* processsources+>a */

a_1371=to_LIST(a_1317)->alwb;
a_1504();
a_G3:if(a_more(a_1371,to_LIST(a_1317)->aupb)){ return;}
if(!a_1331(6,a_F1)){ goto a_G6;}
a_G5:a_next(a_1317,a_1371); goto a_G3;
a_G6:if(a_1331(7,a_F1)){ goto a_G5;}
if(a_1330()){ goto a_G5;} goto a_G5;
} /* processsources */
static void a_1361(void){ /* readsources */
int a_P[1];
a_1507(22017,4);
a_1358(1);
a_1481(22017,a_P);a_1366=a_P[0]; return;
} /* readsources */
static void a_1363(void){ /* readuserlibraries */

a_1507(22017,6);
a_1357();
a_1358(2); return;
} /* readuserlibraries */
static void a_1362(void){ /* readstandardlibrary */

a_1368=to_LIST(a_1317)->aupb;
if(!a_1489(22029)){ goto a_G6;}
a_1507(22017,6);
a_1355(1696719068);
a_1358(3);
a_G6:a_1507(22017,a_1366); return;
} /* readstandardlibrary */
static void a_1352(int a_F1,int a_F2){ /* modulewarning+>a+>a */
int a_L3;int a_P[4];
if(!a_equal(a_1371,to_LIST(a_1317)->alwb)){ goto a_G4;}
a_1337(a_P);a_L3=a_P[0];
a_P[0]=2130704827;a_P[1]=a_F2;a_P[2]=to_LIST(a_1317)->offset[a_F1];a_1240(2,a_L3,3,a_P); return;
a_G4:if(a_mreq(a_1371,a_1368)){ return;}
a_P[0]=2130704815;a_P[1]=to_LIST(a_1317)->offset[a_1371];a_P[2]=to_LIST(a_1317)->offset[a_F1];a_P[3]=a_F2;a_1240(2,0,4,a_P); return;
} /* modulewarning */
static void a_1326(int a_F1){ /* checksamemoduletag+>a */
int a_L2;
a_L2=a_1371;
a_G2:a_next(a_1317,a_L2);
if(a_more(a_L2,to_LIST(a_1317)->aupb)){ return;}
if(!a_1350(a_L2,6)){ goto a_G2;}
if(!a_equal(a_F1,to_LIST(a_1317)->offset[a_L2-3])){ goto a_G2;}
a_1352(a_L2,a_F1); goto a_G2;
} /* checksamemoduletag */
static void a_1327(void){ /* checksourcemodules */
int a_L1;int a_P[2];
if(a_1489(22020)){ goto a_G3;}
a_1507(22020,1696719072);
a_G3:a_1371=to_LIST(a_1317)->alwb;
if(!a_1489(22021)){ goto a_G6;}
a_1326(to_LIST(a_1317)->offset[1178737320-3]);
a_G6:if(a_more(a_1371,to_LIST(a_1317)->aupb)){ return;}
if(!a_1350(a_1371,6)){ goto a_G13;}
a_1356();
a_1343(a_P);a_L1=a_P[0];
if(!a_is(a_L1)){ goto a_G12;}
a_1326(a_L1); goto a_G13;
a_G12:a_P[0]=2130704802;a_P[1]=to_LIST(a_1317)->offset[a_1371];a_1238(0,2,a_P);
a_G13:a_next(a_1317,a_1371); goto a_G6;
} /* checksourcemodules */
static int a_1420(int a_F1){ /* waslexicalpointer+>a */

if(!a_was(a_1379,a_F1)){ goto a_G3;}
a_copystring(a_1379,a_F1,a_1150); return 1;
a_G3:if(!a_was(a_1374,a_F1)){ goto a_G5;}
a_copystring(a_1374,a_F1,a_1150); return 1;
a_G5:if(!a_was(a_1113,a_F1)){ return 0;}
a_1122(a_F1); return 1;
} /* waslexicalpointer */
static int a_1396(int a_F1,int a_F2){ /* opensource+>a+>a */

if(!a_equal(a_F1,0)){ goto a_G3;}
a_1390(a_F2); return 1;
a_G3:if(!a_1466(a_F1,a_F2)){ return 0;}
a_1390(0); return 1;
} /* opensource */
static void a_1419(int a_F1,int a_A[1]){ /* trytoopen+>a+a> */
int a_L3;
if(!a_openfile(a_1378,114,a_1374,a_F1)){ goto a_G3;}
a_A[0]=0; return;
a_G3:a_getfileerror(a_1378,a_L3);
if(!a_equal(a_L3,2)){ goto a_G6;}
a_A[0]=1; return;
a_G6:a_A[0]=-1; return;
} /* trytoopen */
static void a_1382(void){ /* closesource */

if(!a_was(a_1374,a_1377)){ goto a_G3;}
a_G2:a_1377=-1; return;
a_G3:if(!a_equal(a_1377,0)){ return;}
a_closefile(a_1378);
a_1268(); goto a_G2;
} /* closesource */
static void a_1390(int a_F1){ /* initializesourcereading+>a */

a_1377=a_F1;
if(a_equal(a_F1,0)){ goto a_G5;}
a_stringlength(a_1374,a_F1,a_1376);
a_1375=2;
a_G5:a_1398=0;
a_1385=-4;
a_1399=0;
a_1421=0;
a_1397=0;
a_1268();
a_1381=10;
a_1394();
a_1395(); return;
} /* initializesourcereading */
static void a_1394(void){ /* nextchar */
int a_L1;int a_P[1];
if(!a_equal(a_1381,10)){ goto a_G5;}
if(!a_less(a_1385,-2)){ goto a_G5;}
a_1481(22023,a_P);a_1388=a_P[0];
a_1481(22016,a_P);a_1418=a_P[0];
a_G5:if(!a_is(a_1388)){ goto a_G8;}
if(!a_less(a_1385,-2)){ goto a_G8;}
a_1242(a_1381,1); goto a_G9;
a_G8:a_1242(a_1381,0);
a_G9:if(!a_more(a_1421,0)){ goto a_G13;}
a_decr(a_1421);
a_1381=32;
a_incr(a_1398); return;
a_G13:if(!a_more(a_1377,0)){ goto a_G21;}
a_G14:if(!a_equal(a_1375,a_1376)){ goto a_G17;}
a_1381=46;
a_incr(a_1375); goto a_G23;
a_G17:if(!a_less(a_1375,a_1376)){ goto a_G31;}
if(!a_stringelem(a_1374,a_1377,a_1375,a_P)){ goto a_G31;}a_1381=a_P[0];
a_incr(a_1375);
if(a_equal(a_1381,10)){ goto a_G14;} goto a_G23;
a_G21:if(!a_equal(a_1377,0)){ goto a_G31;}
if(!a_getchar(a_1378,a_P)){ goto a_G31;}a_1381=a_P[0];
a_G23:a_incr(a_1398);
{ if(a_1381==10){ goto a_G25;}
 if(a_1381==9){ goto a_G26;}
 if(a_1381<=31){ goto a_G9;}
  return;}
a_G25:a_1398=0; return;
a_G26:a_1381=32;
a_subtr(a_1398,1,a_L1);
a_divrem01(a_L1,a_1418,a_1421);
a_subtr(a_1418,a_1421,a_1421);
a_decr(a_1421); return;
a_G31:if(!a_less(a_1385,-2)){ goto a_G34;}
a_incr(a_1385);
a_1381=10; return;
a_G34:a_1381=19088743; return;
} /* nextchar */
static int a_1380(int a_A[1]){ /* boldletter+a> */

{ if(!((97<=a_1381 && a_1381<=122))){ return 0;}
}
a_A[0]=a_1381;
a_1394(); return 1;
} /* boldletter */
static int a_1383(int a_A[1]){ /* digit+a> */

a_G1:{ if(a_1381==32){ goto a_G2;}
 if((48<=a_1381 && a_1381<=57)){ goto a_G3;}
  return 0;}
a_G2:a_1394(); goto a_G1;
a_G3:a_A[0]=a_1381;
a_1394(); return 1;
} /* digit */
static int a_1389(int a_A[1]){ /* hexdigit+a> */

a_G1:{ if(a_1381==32){ goto a_G2;}
 if((48<=a_1381 && a_1381<=57)||(97<=a_1381 && a_1381<=102)||(65<=a_1381 && a_1381<=70)){ goto a_G3;}
  return 0;}
a_G2:a_1394(); goto a_G1;
a_G3:a_A[0]=a_1381;
a_1394(); return 1;
} /* hexdigit */
static int a_1391(int a_F1){ /* isletgitchar+>a */

{ if((65<=a_F1 && a_F1<=90)||(97<=a_F1 && a_F1<=122)||(48<=a_F1 && a_F1<=57)){ return 1;}
 if(!(a_F1==64)){ return 0;}
}
if(!a_1489(22022)){ return 0;} return 1;
} /* isletgitchar */
static int a_1392(int a_A[1]){ /* letgit+a> */

a_G1:if(!a_equal(a_1381,32)){ goto a_G3;}
a_1394(); goto a_G1;
a_G3:if(!a_1391(a_1381)){ return 0;}
a_A[0]=a_1381;
a_1394(); return 1;
} /* letgit */
static void a_1395(void){ /* nextvisiblechar */

a_G1:{ if(a_1381==32){ goto a_G2;}
 if(a_1381==10){ goto a_G3;}
  return;}
a_G2:a_1394(); goto a_G1;
a_G3:a_incr(a_1399); goto a_G2;
} /* nextvisiblechar */
static void a_1404(int a_F1,int a_A[1]){ /* readgreater+>a+a> */

if(!a_is(a_F1)){ goto a_G6;}
if(!a_equal(a_1381,61)){ goto a_G5;}
a_1394();
a_A[0]=1164737791; return;
a_G5:a_A[0]=1164737731; return;
a_G6:if(!a_equal(a_1381,62)){ goto a_G9;}
a_1394();
a_A[0]=1164737737; return;
a_G9:a_A[0]=1164737731; return;
} /* readgreater */
static void a_1406(int a_F1,int a_A[1]){ /* readless+>a+a> */

if(!a_is(a_F1)){ goto a_G6;}
if(!a_equal(a_1381,61)){ goto a_G5;}
a_1394();
a_A[0]=1164737794; return;
a_G5:a_A[0]=1164737728; return;
a_G6:if(!a_equal(a_1381,60)){ goto a_G9;}
a_1394();
a_A[0]=1164737734; return;
a_G9:if(!a_equal(a_1381,62)){ goto a_G12;}
a_1394();
a_A[0]=1164737752; return;
a_G12:a_A[0]=1164737728; return;
} /* readless */
static void a_1408(int a_A[1]){ /* readminus+a> */
int a_P[1];
{ if(!(a_1381==62)){ goto a_G4;}
}
a_1394();
a_A[0]=1164737722; return;
a_G4:a_1409(a_P);a_A[0]=a_P[0]; return;
} /* readminus */
static void a_1409(int a_A[1]){ /* readminuswithspaces+a> */
int a_P[1];
a_G1:{ if(a_1381==32){ goto a_G2;}
 if(a_1381==48){ goto a_G3;}
 if((49<=a_1381 && a_1381<=57)){ goto a_G5;}
  goto a_G6;}
a_G2:a_1394(); goto a_G1;
a_G3:a_1394();
a_1412(1,a_P);a_A[0]=a_P[0]; return;
a_G5:a_1403(1,a_P);a_A[0]=a_P[0]; return;
a_G6:a_A[0]=1164737779; return;
} /* readminuswithspaces */
static void a_1412(int a_F1,int a_A[1]){ /* readzero+>a+a> */
int a_P[1];
{ if((48<=a_1381 && a_1381<=57)){ goto a_G2;}
 if(a_1381==120||a_1381==88){ goto a_G3;}
  goto a_G5;}
a_G2:a_1403(a_F1,a_P);a_A[0]=a_P[0]; return;
a_G3:a_1394();
a_1405(a_F1,a_P);a_A[0]=a_P[0]; return;
a_G5:a_1123(a_P);a_A[0]=a_P[0]; return;
} /* readzero */
static void a_1403(int a_F1,int a_A[1]){ /* readconst+>a+a> */
int a_L3;int a_L4;int a_P[1];
a_L3=to_LIST(a_1150)->aupb;
a_1386(a_1381);
a_1394();
a_G4:if(!a_1383(a_P)){ goto a_G6;}a_L4=a_P[0];
a_1386(a_L4); goto a_G4;
a_G6:a_1116(a_F1,a_L3,a_P);a_A[0]=a_P[0];
a_unstackto(a_1150,a_L3); return;
} /* readconst */
static void a_1405(int a_F1,int a_A[1]){ /* readhex+>a+a> */
int a_L3;int a_L4;int a_P[1];
if(!a_1389(a_P)){ goto a_G7;}a_L3=a_P[0];
a_L4=to_LIST(a_1150)->aupb;
a_G3:a_1386(a_L3);
if(a_1389(a_P)){a_L3=a_P[0]; goto a_G3;}
a_1118(a_F1,a_L4,a_P);a_A[0]=a_P[0];
a_unstackto(a_1150,a_L4); return;
a_G7:a_P[0]=2130704836;a_1238(-1,1,a_P);
a_1123(a_P);a_A[0]=a_P[0]; return;
} /* readhex */
static void a_1402(int a_A[1]){ /* readchardenotation+a> */
int a_L2;int a_P[1];
a_L2=a_1381;
if(!a_equal(a_1381,10)){ goto a_G4;}
a_G3:a_P[0]=2130704845;a_1238(-1,1,a_P); goto a_G7;
a_G4:a_1394();
if(!a_equal(a_1381,47)){ goto a_G3;}
a_1394();
a_G7:a_1117(a_L2,a_P);a_A[0]=a_P[0]; return;
} /* readchardenotation */
static void a_1415(void){ /* skipchardenotation */

if(a_equal(a_1381,10)){ return;}
a_1394();
if(!a_equal(a_1381,47)){ return;}
a_1394(); return;
} /* skipchardenotation */
static void a_1410(int a_A[1]){ /* readstring+a> */
int a_L2;int a_L3;int a_P[1];
a_L2=to_LIST(a_1150)->aupb;
a_L3=0;
a_G3:a_1394();
{ if(a_1381==34){ goto a_G5;}
 if(a_1381==10||a_1381==19088743){ goto a_G19;}
  goto a_G7;}
a_G5:a_1394();
if(!a_equal(a_1381,34)){ goto a_G9;}
a_G7:a_1386(a_1381);
a_incr(a_L3); goto a_G3;
a_G9:a_1395();
if(a_equal(a_1381,34)){ goto a_G3;}
if(!a_equal(a_L3,0)){ goto a_G13;}
a_G12:a_A[0]=1696719075; return;
a_G13:if(a_less(a_L3,8192)){ goto a_G16;}
a_P[0]=2130704855;a_1238(-1,1,a_P);
a_L3=8192;
a_G16:a_packstring(a_1150,a_L3,a_1374);
a_unstackto(a_1150,a_L2);
a_A[0]=to_LIST(a_1374)->aupb; return;
a_G19:a_P[0]=2130704862;a_1238(-1,1,a_P);
a_unstackto(a_1150,a_L2); goto a_G12;
} /* readstring */
static void a_1416(void){ /* skipstring */

a_G1:{ if(a_1381==34){ goto a_G2;}
 if(a_1381==10||a_1381==19088743){ return;}
  goto a_G3;}
a_G2:a_1394(); return;
a_G3:a_1394(); goto a_G1;
} /* skipstring */
static void a_1387(int a_F1){ /* forgetstring+>a */

if(a_equal(a_F1,1696719075)){ return;}
if(!a_equal(a_F1,to_LIST(a_1374)->aupb)){ return;}
a_unstackstring(a_1374); return;
} /* forgetstring */
static void a_1393(void){ /* longcomment */

a_G1:{ if(a_1381==10){ return;}
 if(!(a_1381==36)){ goto a_G3;}
}
a_1394(); return;
a_G3:a_1394(); goto a_G1;
} /* longcomment */
static int a_1413(void){ /* shortcomment */

a_G1:{ if(a_1381==32){ goto a_G2;}
 if((65<=a_1381 && a_1381<=90)||(97<=a_1381 && a_1381<=122)||(48<=a_1381 && a_1381<=57)){ goto a_G3;}
  return 0;}
a_G2:a_1394(); goto a_G1;
a_G3:a_1394();
{ if((65<=a_1381 && a_1381<=90)||(97<=a_1381 && a_1381<=122)||(48<=a_1381 && a_1381<=57)||a_1381==32){ goto a_G3;}
  return 1;}
} /* shortcomment */
static void a_1401(int a_A[1]){ /* readbold+a> */
int a_L2;int a_L3;int a_L4;int a_P[2];
a_L2=to_LIST(a_1150)->aupb;
a_L3=0;
a_G3:if(!a_1380(a_P)){ goto a_G6;}a_L4=a_P[0];
a_1386(a_L4);
a_incr(a_L3); goto a_G3;
a_G6:if(!a_equal(a_1381,39)){ goto a_G22;}
a_1394();
a_packstring(a_1150,a_L3,a_1374);
a_A[0]=1164737488;
a_G10:if(!a_equal(a_A[0],0)){ goto a_G13;}
a_P[0]=2130704870;a_P[1]=to_LIST(a_1374)->aupb;a_1238(-1,2,a_P);
a_G12:a_A[0]=1164737644; goto a_G20;
a_G13:a_comparestring(a_1373,a_A[0],a_1374,to_LIST(a_1374)->aupb,a_P);a_L3=a_P[0];
a_next(a_1373,a_A[0]);
if(!a_more(a_L3,0)){ goto a_G17;}
a_A[0]=to_LIST(a_1373)->offset[a_A[0]-2]; goto a_G10;
a_G17:if(!a_less(a_L3,0)){ goto a_G19;}
a_A[0]=to_LIST(a_1373)->offset[a_A[0]-1]; goto a_G10;
a_G19:a_A[0]=to_LIST(a_1373)->offset[a_A[0]];
a_G20:a_unstackstring(a_1374);
a_unstackto(a_1150,a_L2); return;
a_G22:a_packstring(a_1150,a_L3,a_1374);
a_P[0]=2130704887;a_P[1]=to_LIST(a_1374)->aupb;a_1238(-1,2,a_P); goto a_G12;
} /* readbold */
static void a_1417(int a_F1,int a_A[1]){ /* stringfromtag+>a+a> */

if(!a_was(a_1720,a_F1)){ goto a_G5;}
a_previous(a_1720,a_F1);
a_copystring(a_1720,a_F1,a_1374);
a_A[0]=to_LIST(a_1374)->aupb; return;
a_G5:a_A[0]=1696719075; return;
} /* stringfromtag */
static void a_1407(int a_A[1]){ /* readmanifest+a> */
int a_L2;int a_L3;int a_L4;int a_P[2];
a_L2=to_LIST(a_1150)->aupb;
a_1386(95);
a_L3=1;
a_G4:if(!a_1380(a_P)){ goto a_G7;}a_L4=a_P[0];
a_1386(a_L4);
a_incr(a_L3); goto a_G4;
a_G7:if(!a_equal(a_1381,95)){ goto a_G35;}
a_1386(95);
a_incr(a_L3);
a_1394();
a_packstring(a_1150,a_L3,a_1374);
a_A[0]=1164737619;
a_G13:if(!a_equal(a_A[0],0)){ goto a_G15;}
a_P[0]=2130704879;a_P[1]=to_LIST(a_1374)->aupb;a_1238(-1,2,a_P); goto a_G22;
a_G15:a_comparestring(a_1373,a_A[0],a_1374,to_LIST(a_1374)->aupb,a_P);a_L3=a_P[0];
a_next(a_1373,a_A[0]);
if(!a_more(a_L3,0)){ goto a_G19;}
a_A[0]=to_LIST(a_1373)->offset[a_A[0]-2]; goto a_G13;
a_G19:if(!a_less(a_L3,0)){ goto a_G21;}
a_A[0]=to_LIST(a_1373)->offset[a_A[0]-1]; goto a_G13;
a_G21:a_A[0]=to_LIST(a_1373)->offset[a_A[0]];
a_G22:a_unstackstring(a_1374);
a_unstackto(a_1150,a_L2);
{ if(a_A[0]==1||a_A[0]==5){ goto a_G25;}
 if(a_A[0]==2){ goto a_G26;}
 if(a_A[0]==3){ goto a_G28;}
 if(a_A[0]==4){ goto a_G30;}
 if(a_A[0]==6){ goto a_G31;}
  goto a_G34;}
a_G25:a_1333(0,a_P);a_A[0]=a_P[1]; return;
a_G26:a_1333(0,a_P);a_A[0]=a_P[0];
a_1117(a_A[0],a_P);a_A[0]=a_P[0]; return;
a_G28:a_1343(a_P);a_A[0]=a_P[0];
a_G29:a_1417(a_A[0],a_P);a_A[0]=a_P[0]; return;
a_G30:a_1551(a_P);a_A[0]=a_P[0]; goto a_G29;
a_G31:a_1481(22020,a_P);a_A[0]=a_P[0];
if(a_is(a_A[0])){ return;}
a_A[0]=1696719075; return;
a_G34:a_A[0]=1164737644; return;
a_G35:if(!a_equal(a_L3,1)){ goto a_G38;}
a_P[0]=2130704904;a_P[1]=95;a_1238(-1,2,a_P);
a_G37:a_unstackto(a_1150,a_L2); goto a_G34;
a_G38:a_packstring(a_1150,a_L3,a_1374);
a_P[0]=2130704879;a_P[1]=to_LIST(a_1374)->aupb;a_1238(-1,2,a_P);
a_1387(to_LIST(a_1374)->aupb); goto a_G37;
} /* readmanifest */
static void a_1411(int a_F1,int a_A[1]){ /* readtag+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[1];
a_L3=to_LIST(a_1150)->aupb;
a_L4=1;
a_1386(a_1381);
a_1394();
a_G5:if(!a_1392(a_P)){ goto a_G9;}a_L5=a_P[0];
a_1386(a_L5);
a_F1=0;
a_incr(a_L4); goto a_G5;
a_G9:if(!a_is(a_F1)){ goto a_G11;}
a_A[0]=1164737746; goto a_G12;
a_G11:a_1727(a_L4,a_P);a_A[0]=a_P[0];
a_G12:a_unstackto(a_1150,a_L3); return;
} /* readtag */
static void a_1384(int a_F1,int a_A[1]){ /* enterstringtag+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[1];
a_L3=to_LIST(a_1150)->aupb;
a_unpackstring(a_1374,a_F1,a_1150);
a_subtr(to_LIST(a_1150)->aupb,a_L3,a_L5);
a_L4=a_L3;
a_G5:a_incr(a_L4);
if(!a_equal(a_L5,0)){ goto a_G10;}
a_L5=1;
a_1386(97);
a_G9:a_P[0]=2130704896;a_1238(-1,1,a_P); goto a_G12;
a_G10:if(a_more(a_L4,to_LIST(a_1150)->aupb)){ goto a_G12;}
if(a_1391(to_LIST(a_1150)->offset[a_L4])){ goto a_G5;} goto a_G9;
a_G12:a_1727(a_L5,a_P);a_A[0]=a_P[0];
a_unstackto(a_1150,a_L3); return;
} /* enterstringtag */
static void a_1400(int a_A[1]){ /* read+a> */
int a_L2;int a_P[2];
if(!a_more(a_1399,0)){ goto a_G4;}
a_decr(a_1399);
a_G3:a_A[0]=1164737809; return;
a_G4:a_L2=a_1397;
a_1397=0;
a_G6:{ if(a_1381==32){ goto a_G7;}
 if((65<=a_1381 && a_1381<=90)||(97<=a_1381 && a_1381<=122)){ goto a_G8;}
 if(a_1381==43){ goto a_G10;}
 if(a_1381==44){ goto a_G12;}
 if(a_1381==59){ goto a_G14;}
 if(a_1381==10){ goto a_G16;}
 if(a_1381==45){ goto a_G18;}
 if(a_1381==61){ goto a_G20;}
 if(a_1381==40){ goto a_G22;}
 if(a_1381==41){ goto a_G24;}
 if(a_1381==48){ goto a_G27;}
 if((49<=a_1381 && a_1381<=57)){ goto a_G30;}
 if(a_1381==39){ goto a_G32;}
 if(a_1381==60){ goto a_G34;}
 if(a_1381==62){ goto a_G36;}
 if(a_1381==42){ goto a_G38;}
 if(a_1381==58){ goto a_G40;}
 if(a_1381==47){ goto a_G45;}
 if(a_1381==46){ goto a_G50;}
 if(a_1381==64){ goto a_G52;}
 if(a_1381==63){ goto a_G57;}
 if(a_1381==36){ goto a_G59;}
 if(a_1381==91){ goto a_G61;}
 if(a_1381==93){ goto a_G63;}
 if(a_1381==35){ goto a_G66;}
 if(a_1381==34){ goto a_G68;}
 if(a_1381==33){ goto a_G69;}
 if(a_1381==126){ goto a_G74;}
 if(a_1381==124){ goto a_G76;}
 if(a_1381==38){ goto a_G78;}
 if(a_1381==94){ goto a_G80;}
 if(a_1381==95){ goto a_G82;}
 if(a_1381==19088743){ goto a_G84;}
  goto a_G86;}
a_G7:a_1394(); goto a_G6;
a_G8:a_1397=1;
a_1411(0,a_P);a_A[0]=a_P[0]; return;
a_G10:a_1394();
a_A[0]=1164737782; return;
a_G12:a_1394();
a_A[0]=1164737770; return;
a_G14:a_1394();
a_A[0]=1164737773; return;
a_G16:a_1394();
a_1397=a_L2; goto a_G3;
a_G18:a_1394();
a_1408(a_P);a_A[0]=a_P[0]; return;
a_G20:a_1394();
a_A[0]=1164737725; return;
a_G22:a_1394();
a_A[0]=1164737758; return;
a_G24:a_1394();
a_1397=1;
a_A[0]=1164737761; return;
a_G27:a_1394();
a_1397=1;
a_1412(0,a_P);a_A[0]=a_P[0]; return;
a_G30:a_1397=1;
a_1403(0,a_P);a_A[0]=a_P[0]; return;
a_G32:a_1394();
a_1401(a_P);a_A[0]=a_P[0]; return;
a_G34:a_1394();
a_1406(a_L2,a_P);a_A[0]=a_P[0]; return;
a_G36:a_1394();
a_1404(a_L2,a_P);a_A[0]=a_P[0]; return;
a_G38:a_1394();
a_A[0]=1164737755; return;
a_G40:a_1394();
if(!a_equal(a_1381,58)){ goto a_G44;}
a_1394();
a_A[0]=1164737767; return;
a_G44:a_A[0]=1164737764; return;
a_G45:a_1394();
if(!a_is(a_L2)){ goto a_G48;}
a_A[0]=1164737788; return;
a_G48:a_1397=1;
a_1402(a_P);a_A[0]=a_P[0]; return;
a_G50:a_1394();
a_A[0]=1164737776; return;
a_G52:if(!a_1489(22022)){ goto a_G55;}
a_1397=1;
a_1411(1,a_P);a_A[0]=a_P[0]; return;
a_G55:a_1394();
a_A[0]=1164737746; return;
a_G57:a_1394();
a_G58:a_A[0]=1164737749; return;
a_G59:a_1394();
a_1393(); goto a_G6;
a_G61:a_1394();
a_A[0]=1164737740; return;
a_G63:a_1394();
a_1397=1;
a_A[0]=1164737743; return;
a_G66:a_1394();
if(a_1413()){ goto a_G6;} goto a_G58;
a_G68:a_1410(a_P);a_A[0]=a_P[0]; return;
a_G69:a_1394();
if(!a_equal(a_1381,61)){ goto a_G73;}
a_1394();
a_A[0]=1164737785; return;
a_G73:a_P[0]=2130704904;a_P[1]=33;a_1238(-1,2,a_P); goto a_G6;
a_G74:a_1394();
a_A[0]=1164737797; return;
a_G76:a_1394();
a_A[0]=1164737800; return;
a_G78:a_1394();
a_A[0]=1164737803; return;
a_G80:a_1394();
a_A[0]=1164737806; return;
a_G82:a_1394();
a_1407(a_P);a_A[0]=a_P[0]; return;
a_G84:a_1394();
a_A[0]=1164737648; return;
a_G86:a_P[0]=2130704904;a_P[1]=a_1381;a_1238(-1,2,a_P); goto a_G7;
} /* read */
static void a_1414(int a_A[1]){ /* skip+a> */

if(!a_more(a_1399,0)){ goto a_G4;}
a_decr(a_1399);
a_G3:a_A[0]=1164737809; return;
a_G4:{ if(a_1381==10){ goto a_G5;}
 if(a_1381==47){ goto a_G6;}
 if(a_1381==46){ goto a_G8;}
 if(a_1381==34){ goto a_G10;}
 if(a_1381==35){ goto a_G12;}
 if(a_1381==36){ goto a_G14;}
 if(a_1381==19088743){ goto a_G16;}
  goto a_G17;}
a_G5:a_1394(); goto a_G3;
a_G6:a_1394();
a_1415(); goto a_G4;
a_G8:a_1394();
a_A[0]=1164737776; return;
a_G10:a_1394();
a_1416(); goto a_G4;
a_G12:a_1394();
if(a_1413()){ goto a_G4;} goto a_G4;
a_G14:a_1394();
a_1393(); goto a_G4;
a_G16:a_A[0]=1164737648; return;
a_G17:a_1394(); goto a_G4;
} /* skip */
static void a_1386(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1150,1);a_r1[0]=a_F1;to_LIST(a_1150)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1446(int a_A[2]){ /* readfieldlists+a>+a> */
int a_L3;int a_P[2];
if(!a_equal(1164737758,a_1692)){ goto a_G12;}
a_1702();
a_A[1]=0;
a_P[1]=a_A[1];a_1445(a_P);a_A[0]=a_P[0];a_A[1]=a_P[1];
a_G5:if(!a_equal(1164737758,a_1692)){ return;}
a_1702();
a_P[1]=a_A[1];a_1445(a_P);a_L3=a_P[0];a_A[1]=a_P[1];
if(a_is(a_A[1])){ goto a_G5;}
if(a_equal(a_L3,a_A[0])){ goto a_G5;}
a_A[1]=1;
a_P[0]=2130704915;a_P[1]=a_1442;a_1238(-1,2,a_P); goto a_G5;
a_G12:a_A[0]=-1;
a_A[1]=0; return;
} /* readfieldlists */
static void a_1445(int a_A[2]){ /* readfieldlist+a>+>a> */
int a_L3;int a_P[2];
a_A[0]=1;
a_G2:if(!a_1698(a_P)){ goto a_G4;}a_L3=a_P[0];
if(a_1673(a_L3,0,a_A[0])){ goto a_G6;} goto a_G15;
a_G4:if(!a_equal(1164737749,a_1692)){ goto a_G15;}
a_1702();
a_G6:if(!a_equal(1164737770,a_1692)){ goto a_G9;}
a_1702();
a_incr(a_A[0]); goto a_G2;
a_G9:if(!a_equal(1164737725,a_1692)){ goto a_G11;}
a_1702(); goto a_G2;
a_G11:if(!a_equal(1164737761,a_1692)){ goto a_G13;}
a_1702(); return;
a_G13:a_P[0]=2130704925;a_P[1]=a_1442;a_1238(-1,2,a_P);
a_G14:a_A[1]=1; return;
a_G15:a_P[0]=2130704934;a_P[1]=a_1442;a_1238(-1,2,a_P); goto a_G14;
} /* readfieldlist */
static void a_1431(void){ /* findssel */
int a_P[1];
if(!a_less(a_1435,0)){ goto a_G4;}
a_1440=1;
if(!a_1673(a_1441,0,1)){ return;} return;
a_G4:if(a_1676(a_1441,0,a_P)){a_1440=a_P[0]; return;}
a_1440=-1; return;
} /* findssel */
static void a_1432(int a_A[1]){ /* getlisttag+a> */
int a_P[2];
a_1681();
a_1446(a_P);a_1435=a_P[0];a_A[0]=a_P[1];
if(a_is(a_A[0])){ return;}
if(!a_1695(a_P)){ goto a_G6;}a_1439=a_P[0];a_1441=a_P[1];
a_1431(); return;
a_G6:a_P[0]=2130704942;a_P[1]=a_1442;a_1238(-1,2,a_P);
a_A[0]=1; return;
} /* getlisttag */
static int a_1448(int a_A[3]){ /* sizeestimator+a>+a>+a> */
int a_P[3];
if(!a_equal(1164737740,a_1692)){ return 0;}
a_1702();
if(!a_equal(a_1442,16777240)){ goto a_G7;}
a_A[0]=0;a_A[1]=0;a_A[2]=0;
a_1701(1164737743);
a_P[0]=2130705068;a_P[1]=a_1442;a_1238(-1,2,a_P); return 1;
a_G7:if(!a_equal(1164737725,a_1692)){ goto a_G10;}
a_1702();
a_A[0]=1; goto a_G11;
a_G10:a_A[0]=0;
a_G11:if(!a_1694(a_P)){ goto a_G23;}a_A[2]=a_P[1];
a_A[1]=0;
a_incr(a_A[0]);
{ if(a_A[2]<=0){ goto a_G15;}
 if(a_A[2]>=100000){ goto a_G17;}
 if(a_A[2]>=101){ goto a_G21;}
  goto a_G29;}
a_G15:a_P[0]=2130705082;a_P[1]=a_1442;a_P[2]=a_A[2];a_1240(9,-1,3,a_P);
a_A[2]=1; goto a_G29;
a_G17:a_P[0]=2130705082;a_P[1]=a_1442;a_P[2]=a_A[2];a_1240(6,-1,3,a_P);
if(!a_equal(a_A[0],1)){ goto a_G20;}
a_G19:a_A[2]=100; goto a_G29;
a_G20:a_A[2]=100000; goto a_G29;
a_G21:if(!a_equal(a_A[0],1)){ goto a_G29;}
a_P[0]=2130705082;a_P[1]=a_1442;a_P[2]=a_A[2];a_1240(6,-1,3,a_P); goto a_G19;
a_G23:if(!a_1695(a_P)){ goto a_G25;}a_A[1]=a_P[0];a_A[2]=a_P[1];
a_add(a_A[0],3,a_A[0]); goto a_G29;
a_G25:if(!a_equal(1164737743,a_1692)){ goto a_G27;}
a_A[2]=0;a_A[1]=0;a_A[0]=0; goto a_G29;
a_G27:a_P[0]=2130704953;a_P[1]=a_1442;a_1238(-1,2,a_P);
a_A[0]=0;a_A[1]=0;a_A[2]=0;
a_G29:a_1684(1164737725);
a_1701(1164737743); return 1;
} /* sizeestimator */
static int a_1434(void){ /* isextendedblock */
int a_P[2];
a_1691();
if(a_1694(a_P)){ goto a_G4;}
if(!a_1695(a_P)){ goto a_G6;}
a_G4:if(!a_equal(1164737722,a_1692)){ goto a_G6;}
a_1700(); return 1;
a_G6:a_1700(); return 0;
} /* isextendedblock */
static void a_1452(int a_A[1]){ /* toselectors+>a> */
int a_L2;int a_P[3];
if(!a_equal(1164737722,a_1692)){ goto a_G15;}
a_G2:a_1702();
a_1154(1696719031);
if(!a_equal(1164737755,a_1692)){ goto a_G10;}
a_1702();
if(!a_equal(a_A[0],0)){ goto a_G9;}
a_A[0]=1;
a_1154(1696719024); goto a_G14;
a_G9:a_P[0]=2130704965;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P); goto a_G14;
a_G10:if(!a_1698(a_P)){ goto a_G12;}a_L2=a_P[0];
a_1163(a_L2); goto a_G14;
a_G12:a_P[0]=2130704976;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P);
a_1712();
a_G14:if(!a_equal(1164737722,a_1692)){ return;} goto a_G2;
a_G15:a_P[0]=2130704976;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P);
a_1712(); return;
} /* toselectors */
static void a_1428(void){ /* extendedblock */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
a_L1=0;a_L4=0;
a_1154(1696718915);
a_G3:if(!a_equal(1164737770,a_1692)){ goto a_G5;}
a_1702(); goto a_G3;
a_G5:if(!a_1694(a_P)){ goto a_G9;}a_L2=a_P[0];
a_1154(a_L2);
a_G7:a_P[0]=a_L4;a_1452(a_P);a_L4=a_P[0];
a_incr(a_L1); goto a_G3;
a_G9:if(!a_1695(a_P)){ goto a_G11;}a_L2=a_P[0];a_L3=a_P[1];
a_1160(a_L2,a_L3); goto a_G7;
a_G11:if(!a_equal(a_L1,0)){ goto a_G14;}
a_P[0]=2130704985;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P);
a_1712(); return;
a_G14:a_1701(1164737761);
a_1154(1696718915); return;
} /* extendedblock */
static void a_1437(void){ /* listfillblock */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
if(!a_1434()){ goto a_G3;}
a_1428(); return;
a_G3:a_L4=0;a_L3=0;
a_1154(1696718979);
a_G5:if(!a_equal(1164737770,a_1692)){ goto a_G7;}
a_1702(); goto a_G5;
a_G7:if(!a_1694(a_P)){ goto a_G10;}a_L1=a_P[0];
a_1154(a_L1);
a_G9:a_incr(a_L4); goto a_G5;
a_G10:if(!a_1695(a_P)){ goto a_G12;}a_L1=a_P[0];a_L2=a_P[1];
a_1160(a_L1,a_L2); goto a_G9;
a_G12:if(!a_equal(a_L4,0)){ goto a_G15;}
a_P[0]=2130704985;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P);
a_1712(); return;
a_G15:if(!a_equal(1164737755,a_1692)){ goto a_G21;}
a_1702();
if(!a_equal(a_L3,0)){ goto a_G20;}
a_L3=1;
a_1154(1696719024); goto a_G5;
a_G20:a_P[0]=2130704965;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P); goto a_G5;
a_G21:a_1701(1164737761);
a_1154(1696718882); return;
} /* listfillblock */
static void a_1430(int a_A[1]){ /* filleritem+a> */
int a_L2;int a_L3;int a_P[3];
if(!a_1694(a_P)){ goto a_G4;}a_L2=a_P[0];
a_1154(a_L2);
a_G3:a_A[0]=0; return;
a_G4:if(!a_1695(a_P)){ goto a_G6;}a_L2=a_P[0];a_L3=a_P[1];
a_1160(a_L2,a_L3); goto a_G3;
a_G6:if(!a_1697(a_P)){ goto a_G9;}a_L2=a_P[0];
a_1161(a_L2);
a_A[0]=1; return;
a_G9:if(!a_equal(1164737758,a_1692)){ goto a_G12;}
a_1702();
a_1437(); goto a_G3;
a_G12:a_P[0]=2130704995;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P);
a_1712(); goto a_G3;
} /* filleritem */
static void a_1447(int a_F1){ /* repeatcount+>a */
int a_L2;int a_L3;int a_L4;int a_P[5];
if(!a_equal(1164737755,a_1692)){ return;}
a_1702();
if(a_equal(a_F1,0)){ goto a_G5;}
a_P[0]=2130705019;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P);
a_G5:if(!a_1694(a_P)){ goto a_G12;}a_L2=a_P[1];
{ if((1<=a_L2 && a_L2<=1000)){ goto a_G9;}
}
a_P[0]=2130705009;a_P[1]=a_1442;a_P[2]=a_1441;a_P[3]=a_L2;a_P[4]=1000;a_1238(-1,5,a_P);
a_L2=1;
a_G9:if(a_equal(a_L2,1)){ return;}
a_1154(1696719024);
a_1158(a_L2); return;
a_G12:if(!a_1695(a_P)){ goto a_G15;}a_L3=a_P[0];a_L4=a_P[1];
a_1154(1696719024);
a_1160(a_L3,a_L4); return;
a_G15:a_P[0]=2130705029;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P); return;
} /* repeatcount */
static void a_1433(void){ /* initializer */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
a_G1:if(!a_equal(1164737764,a_1692)){ return;}
a_1702();
if(!a_1695(a_P)){ goto a_G10;}a_L1=a_P[0];a_L2=a_P[1];
a_1690(a_P);a_L3=a_P[0];
a_1300(a_L1,a_L2,16777257,a_L3,a_P);a_L4=a_P[0];
a_1757(a_L4,2);
a_P[0]=a_L4;a_1299(a_P);a_L4=a_P[0];
a_1154(1696718885);
a_1162(a_L4); goto a_G1;
a_G10:a_P[0]=2130705038;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P); return;
} /* initializer */
static void a_1423(void){ /* createlistfiller */
int a_L1;int a_L2;int a_P[3];
if(!a_equal(1164737758,a_1692)){ goto a_G14;}
a_1702();
if(!a_equal(1164737761,a_1692)){ goto a_G5;}
a_G4:a_1702(); return;
a_G5:a_1241(a_P);a_L1=a_P[0];
a_1430(a_P);a_L2=a_P[0];
a_1447(a_L2);
a_1433();
if(!a_equal(1164737770,a_1692)){ goto a_G11;}
a_1702(); goto a_G5;
a_G11:if(a_equal(1164737761,a_1692)){ goto a_G4;}
if(!a_1275(a_L1)){ goto a_G14;}
a_G13:a_1712(); return;
a_G14:a_P[0]=2130704995;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P); goto a_G13;
} /* createlistfiller */
static void a_1436(void){ /* listfill */

a_1154(1696718928);
a_1154(a_1442);
a_1160(a_1439,a_1441);
a_1672(a_1435,a_1440);
a_1154(1696718885);
a_1423();
a_1154(1696718991); return;
} /* listfill */
static void a_1429(int a_F1){ /* externaldeclarer+>a */
int a_L2;int a_L3;int a_L4;int a_P[3];
a_1432(a_P);a_L2=a_P[0];
if(!a_is(a_L2)){ goto a_G4;}
a_1712(); return;
a_G4:a_1701(1164737725);
a_1300(a_1439,a_1441,a_1442,a_F1,a_P);a_L3=a_P[0];
a_1670(a_L3,a_1435,a_1440);
a_1757(a_L3,2);
a_1757(a_L3,16);
a_P[0]=a_L3;a_1299(a_P);a_L3=a_P[0];
if(a_1697(a_P)){a_L4=a_P[0]; goto a_G13;}
a_L4=0;
a_P[0]=2130705048;a_P[1]=a_1442;a_P[2]=a_1441;a_1238(-1,3,a_P);
a_G13:a_1154(1696718920);
a_1162(a_L3);
a_1161(a_L4);
a_1154(1696718991); return;
} /* externaldeclarer */
static void a_1438(int a_F1){ /* listprototype+>a */
int a_L2;int a_L3;int a_P[1];
a_1481(22019,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,1)){ goto a_G12;}
a_1300(a_1439,a_1441,a_1442,a_F1,a_P);a_L3=a_P[0];
a_1670(a_L3,a_1435,a_1440);
a_1757(a_L3,2);
a_1757(a_L3,8);
a_P[0]=a_L3;a_1299(a_P);a_L3=a_P[0];
a_1154(1696718937);
a_1162(a_L3);
a_G10:a_1672(a_1435,a_1440);
a_1154(1696718991); return;
a_G12:if(!a_equal(a_L2,2)){ goto a_G14;}
a_1154(1696718904); goto a_G15;
a_G14:a_1154(1696719000);
a_G15:a_1154(a_1442);
a_1160(a_1439,a_1441); goto a_G10;
} /* listprototype */
static void a_1443(int a_F1,int a_A[1]){ /* prototypeorfill+>a+>a> */
int a_L3;int a_P[1];
a_1432(a_P);a_L3=a_P[0];
if(!a_is(a_L3)){ goto a_G4;}
a_1712(); return;
a_G4:a_P[0]=a_A[0];a_1444(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* prototypeorfill */
static void a_1444(int a_F1,int a_A[1]){ /* prototypeorfillbody+>a+>a> */
int a_P[2];
if(!a_equal(1164737725,a_1692)){ goto a_G8;}
a_1702();
if(!a_equal(a_A[0],3)){ goto a_G6;}
a_P[0]=2130705059;a_P[1]=a_1442;a_1238(-1,2,a_P);
a_1712(); return;
a_G6:a_A[0]=4;
a_G7:a_1436(); return;
a_G8:if(!a_equal(a_A[0],4)){ goto a_G10;}
a_1701(1164737725); goto a_G7;
a_G10:a_A[0]=3;
a_1438(a_F1); return;
} /* prototypeorfillbody */
static void a_1426(int a_F1,int a_F2,int a_F3,int a_F4){ /* declarer+>a+>a+>a+>a */
int a_L5;int a_P[1];
a_1432(a_P);a_L5=a_P[0];
if(!a_is(a_L5)){ goto a_G4;}
a_1712(); return;
a_G4:a_1427(a_F1,a_F2,a_F3,a_F4); return;
} /* declarer */
static void a_1427(int a_F1,int a_F2,int a_F3,int a_F4){ /* declarerbody+>a+>a+>a+>a */
int a_L5;int a_P[2];
if(!a_equal(1164737740,a_1692)){ goto a_G4;}
a_1702();
a_1701(1164737743); goto a_G5;
a_G4:a_P[0]=2130705068;a_P[1]=a_1442;a_1238(-1,2,a_P);
a_G5:a_1300(a_1439,a_1441,a_1442,a_F1,a_P);a_L5=a_P[0];
a_1670(a_L5,a_1435,a_1440);
a_1757(a_L5,2);
a_P[0]=a_L5;a_1299(a_P);a_L5=a_P[0];
a_1154(1696718949);
a_1162(a_L5);
a_1158(a_F2);
{ if(a_F2==0){ goto a_G15;}
 if(!(a_F2==1||a_F2==2)){ goto a_G14;}
}
a_1158(a_F4); goto a_G15;
a_G14:a_1160(a_F3,a_F4);
a_G15:a_1672(a_1435,a_1440);
a_1154(1696718991);
if(!a_equal(1164737725,a_1692)){ return;}
a_1702();
a_1436(); return;
} /* declarerbody */
static void a_1424(int a_A[1]){ /* declaration+>a> */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[3];
a_1690(a_P);a_L2=a_P[0];
if(!a_equal(a_A[0],1)){ goto a_G4;}
a_1429(a_L2); return;
a_G4:if(!a_equal(a_A[0],2)){ goto a_G11;}
if(!a_1448(a_P)){ goto a_G7;}a_L3=a_P[0];a_L4=a_P[1];a_L5=a_P[2];
a_G6:a_1426(a_L2,a_L3,a_L4,a_L5); return;
a_G7:if(!a_equal(a_1442,16777240)){ goto a_G9;}
a_1426(a_L2,0,0,0); return;
a_G9:a_P[0]=2130705059;a_P[1]=a_1442;a_1238(-1,2,a_P);
a_G10:a_1712(); return;
a_G11:if(!a_1448(a_P)){ goto a_G14;}a_L3=a_P[0];a_L4=a_P[1];a_L5=a_P[2];
if(!a_equal(a_A[0],0)){ goto a_G9;}
a_A[0]=2; goto a_G6;
a_G14:if(!a_equal(a_A[0],0)){ goto a_G22;}
a_1432(a_P);a_L6=a_P[0];
if(a_is(a_L6)){ goto a_G10;}
if(!a_equal(a_1442,16777240)){ goto a_G21;}
if(!a_equal(1164737740,a_1692)){ goto a_G21;}
a_A[0]=2;
a_1427(a_L2,0,0,0); return;
a_G21:a_P[0]=a_A[0];a_1444(a_L2,a_P);a_A[0]=a_P[0]; return;
a_G22:a_P[0]=a_A[0];a_1443(a_L2,a_P);a_A[0]=a_P[0]; return;
} /* declaration */
static void a_1425(int a_F1,int a_F2){ /* declarationseries+>a+>a */
int a_P[1];
a_1442=a_F2;
a_G2:a_P[0]=a_F1;a_1424(a_P);a_F1=a_P[0];
if(!a_equal(1164737770,a_1692)){ goto a_G5;}
a_1702(); goto a_G2;
a_G5:if(!a_equal(1164737776,a_1692)){ goto a_G7;}
a_1702(); return;
a_G7:a_1701(1164737776);
a_1715(); return;
} /* declarationseries */
static void a_1451(int a_F1){ /* tabledeclaration+>a */

a_1425(a_F1,16777240); return;
} /* tabledeclaration */
static void a_1449(int a_F1){ /* stackdeclaration+>a */

a_1425(a_F1,16777244); return;
} /* stackdeclaration */
static void a_1450(void){ /* staticstackdeclaration */

a_1425(0,16777250); return;
} /* staticstackdeclaration */
static void a_1453(void){ /* @root */

a_1360();
if(!a_1274()){ goto a_G4;}
a_exit(1); return;
a_G4:a_1204(1,116);
if(!a_1274()){ goto a_G7;}
a_G6:a_exit(4); return;
a_G7:a_1457();
if(!a_1274()){ goto a_G11;}
a_G9:a_1184();
a_G10:a_exit(2); return;
a_G11:a_1182();
a_1204(1,114);
a_1204(2,116);
if(!a_1274()){ goto a_G16;}
a_G15:a_1184(); goto a_G6;
a_G16:a_1618();
if(a_1274()){ goto a_G9;}
a_1182();
a_1204(2,114);
a_1099();
if(a_1274()){ goto a_G15;}
a_1656();
if(a_1274()){ goto a_G25;}
a_1106();
a_G25:if(!a_1274()){ goto a_G28;}
a_1184();
a_1098(); goto a_G10;
a_G28:a_1663();
a_1097();
a_1184(); return;
} /* @root */
static void a_1457(void){ /* firstpass */
int a_P[1];
a_1361();
if(a_1274()){ goto a_G5;}
if(a_is(a_1460)){ goto a_G5;}
a_P[0]=2130705115;a_1238(0,1,a_P);
a_G5:if(a_1274()){ goto a_G11;}
a_1363();
if(a_1274()){ goto a_G11;}
a_1362();
a_1294();
a_1327();
a_G11:a_1226(); return;
} /* firstpass */
static void a_1458(void){ /* pass1 */
int a_L1;int a_P[2];
a_G1:if(a_equal(1164737648,a_1692)){ return;}
if(!a_equal(1164737719,a_1692)){ goto a_G8;}
a_1702();
a_1498(a_P);a_L1=a_P[0];
if(a_equal(a_L1,2)){ return;}
if(!a_equal(a_L1,1)){ goto a_G1;}
a_G7:a_1715(); goto a_G1;
a_G8:if(!a_1489(22031)){ goto a_G11;}
a_1713();
a_1684(1164737776); goto a_G1;
a_G11:if(a_1455(0)){ goto a_G1;}
if(!a_equal(1164737686,a_1692)){ goto a_G15;}
a_1702();
a_1461(); goto a_G1;
a_G15:if(!a_equal(1164737676,a_1692)){ goto a_G18;}
a_1702();
a_1459(); goto a_G1;
a_G18:if(!a_equal(1164737681,a_1692)){ goto a_G21;}
a_1702();
a_1456(); goto a_G1;
a_G21:if(!a_equal(1164737644,a_1692)){ goto a_G23;}
a_1702(); goto a_G7;
a_G23:a_P[0]=2130705089;a_P[1]=a_1692;a_1238(-1,2,a_P); goto a_G7;
} /* pass1 */
static int a_1455(int a_F1){ /* declaration+>a */

if(!a_equal(1164737710,a_1692)){ goto a_G4;}
a_1702();
a_1451(a_F1); return 1;
a_G4:if(!a_equal(1164737714,a_1692)){ goto a_G7;}
a_1702();
a_1449(a_F1); return 1;
a_G7:if(!a_equal(1164737706,a_1692)){ goto a_G10;}
a_1702();
a_1778(a_F1); return 1;
a_G10:if(!a_equal(1164737701,a_1692)){ goto a_G13;}
a_1702();
a_1764(a_F1); return 1;
a_G13:if(!a_equal(1164737691,a_1692)){ goto a_G16;}
a_1702();
a_1277(a_F1); return 1;
a_G16:if(!a_equal(1164737696,a_1692)){ goto a_G19;}
a_1702();
a_1278(a_F1); return 1;
a_G19:if(!a_equal(1164737653,a_1692)){ goto a_G22;}
a_1702();
a_1527(256,a_F1); return 1;
a_G22:if(!a_equal(1164737658,a_1692)){ goto a_G25;}
a_1702();
a_1527(0,a_F1); return 1;
a_G25:if(!a_equal(1164737668,a_1692)){ goto a_G28;}
a_1702();
a_1527(512,a_F1); return 1;
a_G28:if(!a_equal(1164737663,a_1692)){ goto a_G31;}
a_1702();
a_1527(768,a_F1); return 1;
a_G31:if(!a_equal(1164737672,a_1692)){ return 0;}
a_1702();
a_1527(1024,a_F1); return 1;
} /* declaration */
static void a_1456(void){ /* externaldeclaration */
int a_P[2];
if(!a_1489(22022)){ goto a_G7;}
if(a_1455(1)){ return;}
if(!a_equal(1164737644,a_1692)){ goto a_G6;}
a_1702();
a_G5:a_1715(); return;
a_G6:a_P[0]=2130705089;a_P[1]=a_1692;a_1238(-1,2,a_P); goto a_G5;
a_G7:a_P[0]=2130705102;a_1238(-1,1,a_P); goto a_G5;
} /* externaldeclaration */
static void a_1461(void){ /* staticdeclaration */
int a_P[2];
if(!a_equal(1164737706,a_1692)){ goto a_G4;}
a_1702();
a_1777(); return;
a_G4:if(!a_equal(1164737714,a_1692)){ goto a_G7;}
a_1702();
a_1450(); return;
a_G7:if(!a_equal(1164737644,a_1692)){ goto a_G10;}
a_1702();
a_G9:a_1715(); return;
a_G10:a_P[0]=2130705089;a_P[1]=a_1692;a_1238(-1,2,a_P); goto a_G9;
} /* staticdeclaration */
static void a_1459(void){ /* root */
int a_P[1];
if(!a_is(a_1460)){ goto a_G4;}
a_P[0]=2130705110;a_1238(-1,1,a_P);
a_1715(); return;
a_G4:a_1460=1;
a_1562(); return;
} /* root */
static void a_1463(void){ /* addaleextension */

a_1465(46);
a_1465(97);
a_1465(108);
a_1465(101); return;
} /* addaleextension */
static void a_1467(int a_F1,int a_A[1]){ /* trybuffer+>a+a> */
int a_L3;int a_L4;int a_P[1];
a_L3=0;
a_G2:a_subtr(to_LIST(a_1150)->aupb,a_F1,a_L4);
a_packstring(a_1150,a_L4,a_1374);
a_1419(to_LIST(a_1374)->aupb,a_P);a_A[0]=a_P[0];
a_1387(to_LIST(a_1374)->aupb);
if(a_lseq(a_A[0],0)){ return;}
if(a_is(a_L3)){ return;}
a_L3=1;
a_1463(); goto a_G2;
} /* trybuffer */
static void a_1468(int a_F2,int a_A[2]){ /* trynextpath+>a>+>a+a> */
int a_L4;int a_L5;int a_P[1];
a_L4=to_LIST(a_1150)->aupb;
a_L5=58;
a_G3:if(a_equal(to_LIST(a_1150)->offset[a_A[0]],58)){ goto a_G7;}
a_L5=to_LIST(a_1150)->offset[a_A[0]];
a_incr(a_A[0]);
a_1465(a_L5); goto a_G3;
a_G7:if(!a_equal(a_L5,58)){ goto a_G9;}
a_A[1]=1; return;
a_G9:if(a_equal(a_L5,47)){ goto a_G11;}
a_1465(47);
a_G11:a_unpackstring(a_1374,a_F2,a_1150);
a_1467(a_L4,a_P);a_A[1]=a_P[0];
a_unstackto(a_1150,a_L4); return;
} /* trynextpath */
static void a_1469(int a_F1,int a_F2,int a_A[1]){ /* trytoopenwithpath+>a+>a+a> */
int a_L4;int a_L5;int a_L6;int a_P[2];
if(!a_equal(a_F2,0)){ goto a_G3;}
a_A[0]=1; return;
a_G3:a_L4=to_LIST(a_1150)->aupb;
a_unpackstring(a_1374,a_F2,a_1150);
a_1465(58);
a_L5=a_L4;
a_incr(a_L5);
a_L6=to_LIST(a_1150)->aupb;
a_G9:if(!a_mreq(a_L5,a_L6)){ goto a_G11;}
a_A[0]=1; goto a_G14;
a_G11:a_P[0]=a_L5;a_1468(a_F1,a_P);a_L5=a_P[0];a_A[0]=a_P[1];
if(!a_equal(a_A[0],1)){ goto a_G14;}
a_incr(a_L5); goto a_G9;
a_G14:a_unstackto(a_1150,a_L4); return;
} /* trytoopenwithpath */
static int a_1466(int a_F1,int a_F2){ /* opensrcfile+>a+>a */
int a_L3;int a_L4;int a_P[1];
a_L3=to_LIST(a_1150)->aupb;
a_unpackstring(a_1374,a_F2,a_1150);
a_1467(a_L3,a_P);a_L4=a_P[0];
a_unstackto(a_1150,a_L3);
if(a_lseq(a_L4,0)){ goto a_G9;}
if(a_lseq(a_F1,1)){ goto a_G9;}
a_1481(22034,a_P);a_L3=a_P[0];
a_1469(a_F2,a_L3,a_P);a_L4=a_P[0];
a_G9:if(a_lseq(a_L4,0)){ goto a_G15;}
if(a_lseq(a_F1,2)){ goto a_G15;}
a_1481(22035,a_P);a_L3=a_P[0];
a_1469(a_F2,a_L3,a_P);a_L4=a_P[0];
if(a_lseq(a_L4,0)){ goto a_G15;}
a_1469(a_F2,1696719063,a_P);a_L4=a_P[0];
a_G15:if(!a_equal(a_L4,0)){ return 0;} return 1;
} /* opensrcfile */
static void a_1464(void){ /* createicename */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_P[1];
a_L1=to_LIST(a_1150)->aupb;
a_1481(22036,a_P);a_L2=a_P[0];
if(!a_is(a_L2)){ goto a_G5;}
a_L5=0; goto a_G7;
a_G5:a_1340(a_P);a_L2=a_P[0];
a_L5=1;
a_G7:a_unpackstring(a_1374,a_L2,a_1150);
a_L4=to_LIST(a_1150)->aupb;
a_G9:if(a_lseq(a_L4,a_L1)){ goto a_G18;}
{register int a_r1=to_LIST(a_1150)->offset[a_L4];
 if(a_r1==46){ goto a_G11;}
 if(a_r1==47||a_r1==92||a_r1==58){ goto a_G16;}
  goto a_G17;}
a_G11:if(!a_equal(a_L5,0)){ goto a_G14;}
a_L5=2;
a_G13:a_L4=a_L1; goto a_G18;
a_G14:a_decr(a_L4);
a_unstackto(a_1150,a_L4); goto a_G9;
a_G16:if(a_equal(a_L5,1)){ goto a_G18;} goto a_G13;
a_G17:a_decr(a_L4); goto a_G9;
a_G18:if(a_equal(a_L5,2)){ goto a_G23;}
a_1465(46);
a_1465(105);
a_1465(99);
a_1465(101);
a_G23:a_subtr(to_LIST(a_1150)->aupb,a_L4,a_L3);
a_packstring(a_1150,a_L3,a_1374);
a_unstackto(a_1150,a_L1); return;
} /* createicename */
static void a_1465(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1150,1);a_r1[0]=a_F1;to_LIST(a_1150)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1481(int a_F1,int a_A[1]){ /* getpragmatvalue+>a+a> */

{ if(a_F1==22016){ goto a_G2;}
 if(a_F1==22030){ goto a_G3;}
 if(a_F1==22023){ goto a_G4;}
 if(a_F1==22022){ goto a_G5;}
 if(a_F1==22024){ goto a_G6;}
 if(a_F1==22025){ goto a_G7;}
 if(a_F1==22017){ goto a_G8;}
 if(a_F1==22019){ goto a_G9;}
 if(a_F1==22020){ goto a_G10;}
 if(a_F1==22034){ goto a_G11;}
 if(a_F1==22035){ goto a_G12;}
 if(a_F1==22036){ goto a_G13;}
  goto a_G14;}
a_G2:a_A[0]=a_1510; return;
a_G3:a_A[0]=a_1505; return;
a_G4:a_A[0]=a_1482; return;
a_G5:a_A[0]=a_1486; return;
a_G6:a_A[0]=a_1485; return;
a_G7:a_A[0]=a_1476; return;
a_G8:a_A[0]=a_1514; return;
a_G9:a_A[0]=a_1503; return;
a_G10:a_A[0]=a_1502; return;
a_G11:a_A[0]=a_1484; return;
a_G12:a_A[0]=a_1490; return;
a_G13:a_A[0]=a_1483; return;
a_G14:a_1248(a_1001,2130706188); return;
} /* getpragmatvalue */
static int a_1489(int a_F1){ /* ispragmatvalue+>a */

{ if(a_F1==22022){ goto a_G2;}
 if(a_F1==22029){ goto a_G3;}
 if(a_F1==22024){ goto a_G4;}
 if(a_F1==22021){ goto a_G5;}
 if(a_F1==22023){ goto a_G6;}
 if(a_F1==22020){ goto a_G7;}
 if(a_F1==22031){ goto a_G8;}
 if(a_F1==22025){ goto a_G9;}
 if(a_F1==22027){ goto a_G10;}
 if(a_F1==22028){ goto a_G11;}
 if(a_F1==22017){ goto a_G12;}
  return 0;}
a_G2:if(!a_equal(a_1486,1)){ return 0;} return 1;
a_G3:if(!a_is(a_1513)){ return 0;} return 1;
a_G4:if(!a_equal(a_1485,1)){ return 0;} return 1;
a_G5:if(!a_equal(a_1487,1)){ return 0;} return 1;
a_G6:if(!a_equal(a_1482,1)){ return 0;} return 1;
a_G7:if(!a_is(a_1502)){ return 0;} return 1;
a_G8:if(!a_is(a_1494)){ return 0;} return 1;
a_G9:if(!a_is(a_1476)){ return 0;} return 1;
a_G10:if(!a_is(a_1512)){ return 0;} return 1;
a_G11:if(!a_is(a_1475)){ return 0;} return 1;
a_G12:if(!a_is(a_1472)){ return 0;} return 1;
} /* ispragmatvalue */
static void a_1507(int a_F1,int a_F2){ /* setpragmatvalue+>a+>a */
int a_P[1];
{ if(a_F1==22016){ goto a_G2;}
 if(a_F1==22023){ goto a_G3;}
 if(a_F1==22022){ goto a_G4;}
 if(a_F1==22024){ goto a_G7;}
 if(a_F1==22025){ goto a_G10;}
 if(a_F1==22033){ goto a_G11;}
 if(a_F1==22017){ goto a_G13;}
 if(a_F1==22018){ goto a_G18;}
 if(a_F1==22019){ goto a_G19;}
 if(a_F1==22020){ goto a_G20;}
 if(a_F1==22034){ goto a_G21;}
 if(a_F1==22035){ goto a_G22;}
 if(a_F1==22036){ goto a_G23;}
 if(a_F1==22037){ goto a_G24;}
 if(a_F1==22038){ goto a_G25;}
  goto a_G26;}
a_G2:a_1510=a_F2; return;
a_G3:a_1482=a_F2; return;
a_G4:if(!a_is(a_F2)){ goto a_G6;}
a_1486=1; return;
a_G6:a_1486=0; return;
a_G7:if(!a_is(a_F2)){ goto a_G9;}
a_1485=1; return;
a_G9:a_1485=0; return;
a_G10:a_1476=a_F2; return;
a_G11:a_1384(a_F2,a_P);a_F2=a_P[0];
a_1313(a_F2,-1); return;
a_G13:if(a_equal(a_F2,a_1514)){ return;}
if(a_less(a_F2,0)){ return;}
if(a_more(a_F2,9)){ return;}
a_1514=a_F2;
a_1477(22017,a_F2); return;
a_G18:a_1514=a_F2; return;
a_G19:a_1503=a_F2; return;
a_G20:a_1502=a_F2; return;
a_G21:a_1484=a_F2; return;
a_G22:a_1490=a_F2; return;
a_G23:a_1483=a_F2; return;
a_G24:a_1325(a_F2); return;
a_G25:a_1323(a_F2); return;
a_G26:a_1248(a_1001,2130706182); return;
} /* setpragmatvalue */
static void a_1504(void){ /* resetpragmats */

a_1486=0;
a_1476=0;
a_1510=8;
a_1482=0;
a_1503=0;
a_1485=1;
a_1512=0;a_1475=0;a_1472=0;
a_1494=0;a_1493=0; return;
} /* resetpragmats */
static void a_1473(void){ /* cmdlinepragmat */
int a_L1;int a_P[1];
a_G1:if(!a_1696(a_P)){ goto a_G10;}a_L1=a_P[0];
a_1701(1164737725);
a_1497(a_L1);
if(!a_equal(1164737776,a_1692)){ goto a_G6;}
a_1702(); return;
a_G6:if(!a_equal(1164737770,a_1692)){ goto a_G8;}
a_1702(); goto a_G1;
a_G8:a_1701(1164737776);
a_G9:a_1715(); return;
a_G10:a_P[0]=2130705123;a_1238(-1,1,a_P); goto a_G9;
} /* cmdlinepragmat */
static void a_1497(int a_F1){ /* pragmatitem+>a */
int a_L2;int a_P[2];
if(!a_equal(1164737758,a_1692)){ goto a_G6;}
a_G2:a_1702();
a_1497(a_F1);
if(a_equal(1164737770,a_1692)){ goto a_G2;}
a_1701(1164737761); return;
a_G6:if(!a_1696(a_P)){ goto a_G8;}a_L2=a_P[0];
a_1511(a_F1,a_L2,0); return;
a_G8:if(!a_1694(a_P)){ goto a_G10;}a_L2=a_P[1];
a_1474(a_F1,a_L2); return;
a_G10:if(!a_1697(a_P)){ goto a_G12;}a_L2=a_P[0];
a_1509(a_F1,a_L2); return;
a_G12:a_P[0]=2130705131;a_P[1]=a_F1;a_1238(-1,2,a_P);
a_1712(); return;
} /* pragmatitem */
static void a_1477(int a_F1,int a_F2){ /* discpragmat+>a+>a */

a_1154(1696718996);
a_1158(a_F1);
if(!a_equal(a_F1,22032)){ goto a_G5;}
a_1163(a_F2); return;
a_G5:a_1158(a_F2); return;
} /* discpragmat */
static int a_1471(int a_A[1]){ /* aheadrawtag+a> */

if(!a_was(a_1720,a_1692)){ return 0;}
a_A[0]=a_1692; return 1;
} /* aheadrawtag */
static void a_1488(int a_F1){ /* insertsymbol+>a */

a_1692=a_F1; return;
} /* insertsymbol */
static void a_1491(void){ /* nextpragmatsymbol */
int a_P[1];
a_G1:{ if(a_1495==0){ goto a_G2;}
 if(a_1495==1){ goto a_G6;}
 if(a_1495==2){ goto a_G9;}
 if(a_1495==3){ goto a_G12;}
 if(a_1495==4){ goto a_G17;}
 if(a_1495==5){ goto a_G20;}
 if(a_1495==6){ goto a_G25;}
 if(a_1495==7){ goto a_G27;}
  goto a_G29;}
a_G2:a_1702();
if(!a_equal(1164737770,a_1692)){ goto a_G5;}
a_1495=1; return;
a_G5:a_1495=100; return;
a_G6:a_1702();
if(!a_1471(a_P)){ goto a_G5;}a_1496=a_P[0];
a_1495=2; return;
a_G9:a_1702();
if(!a_equal(1164737725,a_1692)){ goto a_G5;}
a_1495=3; return;
a_G12:a_1702();
{ if(!((1962709581<=a_1692 && a_1692<=1990708580)||(1696719048<=a_1692 && a_1692<=1920711075)||(604756899<=a_1692 && a_1692<=1164737376))){ goto a_G15;}
}
a_1495=0; return;
a_G15:if(!a_equal(1164737758,a_1692)){ goto a_G5;}
a_1495=4; goto a_G1;
a_G17:a_1702();
{ if(!((1962709581<=a_1692 && a_1692<=1990708580)||(1696719048<=a_1692 && a_1692<=1920711075)||(604756899<=a_1692 && a_1692<=1164737376))){ goto a_G5;}
}
a_1495=5; return;
a_G20:a_1702();
if(!a_equal(1164737770,a_1692)){ goto a_G23;}
a_1495=6; return;
a_G23:if(!a_equal(1164737761,a_1692)){ goto a_G5;}
a_1495=0; goto a_G1;
a_G25:a_1488(a_1496);
a_1495=7; return;
a_G27:a_1488(1164737725);
a_1495=4; return;
a_G29:if(a_equal(1164737648,a_1692)){ return;}
a_1702(); return;
} /* nextpragmatsymbol */
static void a_1498(int a_A[1]){ /* programpragmat+a> */
int a_P[1];
a_1495=100;
a_1499(a_P);a_A[0]=a_P[0]; return;
} /* programpragmat */
static void a_1499(int a_A[1]){ /* programpragmat2+a> */
int a_L2;int a_P[1];
a_A[0]=0;
a_G2:if(!a_1471(a_P)){ goto a_G15;}a_L2=a_P[0];
if(!a_equal(a_1495,100)){ goto a_G6;}
a_1496=a_L2;
a_1495=2;
a_G6:a_1491();
if(!a_equal(1164737725,a_1692)){ goto a_G15;}
a_1491();
a_P[0]=a_A[0];a_1500(a_1496,a_P);a_A[0]=a_P[0];
if(a_is(a_A[0])){ return;}
if(!a_equal(1164737776,a_1692)){ goto a_G13;}
a_1702(); return;
a_G13:if(!a_equal(1164737770,a_1692)){ goto a_G15;}
a_1491(); goto a_G2;
a_G15:a_P[0]=2130705123;a_1238(-1,1,a_P);
a_A[0]=1; return;
} /* programpragmat2 */
static void a_1500(int a_F1,int a_A[1]){ /* programpragmatitem+>a+>a> */
int a_L3;int a_L4;int a_P[2];
{ if((1962709581<=a_1692 && a_1692<=1990708580)){ goto a_G2;}
 if((1696719048<=a_1692 && a_1692<=1920711075)){ goto a_G6;}
 if((604756899<=a_1692 && a_1692<=1164737376)){ goto a_G10;}
  goto a_G14;}
a_G2:a_1125(a_1692,a_P);a_L3=a_P[0];
a_1491();
if(a_is(a_1494)){ return;}
a_1474(a_F1,a_L3); return;
a_G6:a_L3=a_1692;
a_1491();
if(a_is(a_1494)){ return;}
a_1509(a_F1,a_L3); return;
a_G10:a_L3=a_1692;
a_1690(a_P);a_L4=a_P[0];
a_1491();
a_P[0]=a_A[0];a_1501(a_F1,a_L3,a_L4,a_P);a_A[0]=a_P[0]; return;
a_G14:a_P[0]=2130705131;a_P[1]=a_F1;a_1238(-1,2,a_P);
a_A[0]=1; return;
} /* programpragmatitem */
static void a_1479(int a_F1,int a_F2,int a_A[1]){ /* findifcondition+>a+>a+a> */
int a_P[3];
{ if(a_F2==604756949){ goto a_G2;}
 if(a_F2==604757017){ goto a_G3;}
 if(a_F2==604757036){ goto a_G4;}
 if(a_F2==604757063){ goto a_G5;}
 if(a_F2==604757072||a_F2==604757082){ goto a_G6;}
  goto a_G7;}
a_G2:a_A[0]=a_1482; return;
a_G3:a_A[0]=a_1476; return;
a_G4:a_A[0]=a_1485; return;
a_G5:a_A[0]=a_1487; return;
a_G6:a_A[0]=a_1486; return;
a_G7:a_P[0]=2130705142;a_P[1]=a_F1;a_P[2]=a_F2;a_1238(-1,3,a_P);
a_A[0]=0; return;
} /* findifcondition */
static void a_1480(void){ /* findmatchingendif */
int a_L1;int a_P[2];
if(!a_equal(1164737776,a_1692)){ goto a_G4;}
a_1702();
a_L1=0; goto a_G9;
a_G4:if(!a_equal(1164737770,a_1692)){ goto a_G7;}
a_1491();
a_1499(a_P);a_L1=a_P[0]; goto a_G9;
a_G7:a_P[0]=2130705123;a_1238(-1,1,a_P);
a_L1=1;
a_G9:if(!a_equal(a_L1,1)){ goto a_G11;}
a_1715();
a_G11:if(a_equal(a_L1,2)){ return;}
a_1458();
if(!a_equal(1164737648,a_1692)){ return;}
a_P[0]=2130705173;a_P[1]=a_1493;a_1238(-1,2,a_P); return;
} /* findmatchingendif */
static void a_1478(int a_F1,int a_F2){ /* dopragmatskip+>a+>a */
int a_L3;int a_L4;
a_L3=a_1493;
a_1493=a_F1;
a_L4=a_1494;
if(!a_is(a_1494)){ goto a_G6;}
a_G5:a_incr(a_1494); goto a_G7;
a_G6:if(a_is(a_F2)){ goto a_G5;}
a_G7:a_1480();
a_1494=a_L4;
a_1493=a_L3; return;
} /* dopragmatskip */
static void a_1501(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* programtagpragmat2+>a+>a+>a+>a> */
int a_L5;int a_P[3];
{ if(a_F1==604757201){ goto a_G2;}
 if(a_F1==604757210){ goto a_G6;}
 if(a_F1==604757219){ goto a_G8;}
 if(a_F1==604757228){ goto a_G9;}
 if(a_F1==604757237){ goto a_G10;}
 if(a_F1==604757246){ goto a_G17;}
  goto a_G21;}
a_G2:a_1479(a_F1,a_F2,a_P);a_L5=a_P[0];
if(!a_is(a_L5)){ goto a_G5;}
a_G4:a_1478(a_F2,0); return;
a_G5:a_1478(a_F2,1); return;
a_G6:a_1479(a_F1,a_F2,a_P);a_L5=a_P[0];
if(a_is(a_L5)){ goto a_G5;} goto a_G4;
a_G8:if(a_1309(a_F2)){ goto a_G4;} goto a_G5;
a_G9:if(a_1309(a_F2)){ goto a_G5;} goto a_G4;
a_G10:if(!a_equal(a_1493,a_F2)){ goto a_G15;}
if(!a_equal(a_1494,0)){ goto a_G13;}
a_G12:a_1494=1; return;
a_G13:if(!a_equal(a_1494,1)){ return;}
a_1494=0; return;
a_G15:a_P[0]=2130705184;a_P[1]=a_F1;a_P[2]=a_F2;a_1238(-1,3,a_P);
if(a_more(a_1494,0)){ return;} goto a_G12;
a_G17:if(!a_equal(a_1493,a_F2)){ goto a_G19;}
a_G18:a_A[0]=2; return;
a_G19:a_P[0]=2130705184;a_P[1]=a_F1;a_P[2]=a_F2;a_1238(-1,3,a_P);
if(a_equal(a_1493,0)){ return;} goto a_G18;
a_G21:if(a_is(a_1494)){ return;}
a_1511(a_F1,a_F2,a_F3); return;
} /* programtagpragmat2 */
static void a_1492(int a_F1,int a_F3,int a_A[1]){ /* onoffpragmats+>a+>a>+>a */
int a_P[3];
if(!a_equal(a_F3,604756906)){ goto a_G3;}
a_A[0]=1; return;
a_G3:if(!a_equal(a_F3,604756914)){ goto a_G5;}
a_A[0]=0; return;
a_G5:a_P[0]=2130705142;a_P[1]=a_F1;a_P[2]=a_F3;a_1238(-1,3,a_P); return;
} /* onoffpragmats */
static void a_1511(int a_F1,int a_F2,int a_F3){ /* tagpragmat2+>a+>a+>a */
int a_P[3];
{ if(a_F1==604756949){ goto a_G2;}
 if(a_F1==604757017){ goto a_G7;}
 if(a_F1==604757072||a_F1==604757082){ goto a_G11;}
 if(a_F1==604757130){ goto a_G15;}
 if(a_F1==604757027){ goto a_G25;}
 if(a_F1==604757007){ goto a_G30;}
 if(a_F1==604757111||a_F1==604757120){ goto a_G33;}
 if(a_F1==604757175){ goto a_G36;}
 if(a_F1==604757193){ goto a_G37;}
 if(a_F1==604757184){ goto a_G38;}
 if(a_F1==604757063){ goto a_G39;}
  goto a_G40;}
a_G2:if(!a_equal(a_F2,604756906)){ goto a_G4;}
a_1482=1; return;
a_G4:if(!a_equal(a_F2,604756914)){ goto a_G6;}
a_1482=0; return;
a_G6:a_P[0]=2130705142;a_P[1]=a_F1;a_P[2]=a_F2;a_1238(-1,3,a_P); return;
a_G7:if(!a_equal(a_F2,604756906)){ goto a_G9;}
a_1476=1; return;
a_G9:if(!a_equal(a_F2,604756914)){ goto a_G6;}
a_1476=0; return;
a_G11:if(!a_equal(a_F2,604756906)){ goto a_G13;}
a_1486=1; return;
a_G13:if(!a_equal(a_F2,604756914)){ goto a_G6;}
a_1486=0; return;
a_G15:if(!a_equal(a_F2,604756922)){ goto a_G17;}
a_G16:a_1503=0; return;
a_G17:if(a_equal(a_F2,604756931)){ goto a_G16;}
if(!a_equal(a_F2,604757148)){ goto a_G20;}
a_G19:a_1503=1; return;
a_G20:if(!a_equal(a_F2,604757139)){ goto a_G22;}
a_G21:a_1503=2; return;
a_G22:if(a_equal(a_F2,604757157)){ goto a_G21;}
if(!a_equal(a_F2,604757166)){ goto a_G6;}
{ if(a_1503==1){ goto a_G21;}
 if(a_1503==2){ goto a_G19;}
  return;}
a_G25:if(!a_equal(a_1485,0)){ goto a_G27;}
a_P[0]=2130705193;a_P[1]=a_F1;a_1240(4,-1,2,a_P); return;
a_G27:if(a_equal(a_F2,604756922)){ goto a_G29;}
if(!a_equal(a_F2,604756914)){ goto a_G6;}
a_G29:a_1513=0; return;
a_G30:if(a_lseq(a_F3,0)){ goto a_G32;}
a_1219(a_F2,a_F3);
a_G32:a_1313(a_F2,a_F3); return;
a_G33:if(a_lseq(a_F3,0)){ goto a_G35;}
a_1219(a_F2,a_F3);
a_G35:a_1477(22032,a_F2); return;
a_G36:a_P[0]=a_1512;a_1492(604757175,a_F2,a_P);a_1512=a_P[0]; return;
a_G37:a_P[0]=a_1475;a_1492(604757193,a_F2,a_P);a_1475=a_P[0]; return;
a_G38:a_P[0]=a_1472;a_1492(604757184,a_F2,a_P);a_1472=a_P[0]; return;
a_G39:a_1506(a_F1,a_F2); return;
a_G40:a_P[0]=2130705131;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
} /* tagpragmat2 */
static void a_1474(int a_F1,int a_F2){ /* conspragmat2+>a+>a */
int a_P[3];
{ if(a_F1==604756959){ goto a_G2;}
 if(a_F1==604756980){ goto a_G5;}
 if(a_F1==604756969){ goto a_G8;}
  goto a_G10;}
a_G2:{ if(!((1<=a_F2 && a_F2<=20))){ goto a_G4;}
}
a_1510=a_F2; return;
a_G4:a_P[0]=2130705153;a_P[1]=a_F1;a_P[2]=a_F2;a_1238(-1,3,a_P); return;
a_G5:{ if(!((0<=a_F2 && a_F2<=9))){ goto a_G4;}
}
a_1514=a_F2;
a_1477(22017,a_1514); return;
a_G8:{ if(!((20<=a_F2 && a_F2<=1000))){ goto a_G4;}
}
a_1505=a_F2; return;
a_G10:a_P[0]=2130705131;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
} /* conspragmat2 */
static void a_1509(int a_F1,int a_F2){ /* stringpragmat2+>a+>a */
int a_P[3];
if(!a_equal(a_F2,1696719075)){ goto a_G3;}
a_P[0]=2130705142;a_P[1]=a_F1;a_P[2]=a_F2;a_1238(-1,3,a_P); return;
a_G3:{ if(a_F1==604756989){ goto a_G4;}
 if(a_F1==604756998){ goto a_G6;}
 if(a_F1==604757092){ goto a_G7;}
 if(a_F1==604757102){ goto a_G10;}
 if(a_F1==604757054){ goto a_G12;}
 if(a_F1==604757045){ goto a_G13;}
 if(a_F1==604757072){ goto a_G14;}
 if(a_F1==604756940){ goto a_G17;}
  goto a_G18;}
a_G4:a_P[0]=2130705206;a_P[1]=a_F2;a_1238(-1,2,a_P);
a_G5:a_1387(a_F2); return;
a_G6:a_P[0]=2130705206;a_P[1]=a_F2;a_1240(9,-1,2,a_P); goto a_G5;
a_G7:if(!a_is(a_1486)){ goto a_G9;}
a_1721(1,a_F2); return;
a_G9:a_P[0]=2130705203;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
a_G10:if(!a_is(a_1486)){ goto a_G9;}
a_1721(2,a_F2); return;
a_G12:a_1321(a_F2); return;
a_G13:a_1325(a_F2); return;
a_G14:if(!a_equal(a_1485,0)){ goto a_G16;}
a_P[0]=2130705193;a_P[1]=a_F1;a_1240(4,-1,2,a_P); return;
a_G16:a_1323(a_F2); return;
a_G17:a_1508(a_F1,a_F2); return;
a_G18:a_1387(a_F2);
a_P[0]=2130705131;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
} /* stringpragmat2 */
static void a_1508(int a_F1,int a_F2){ /* setprogramtitle+>a+>a */
int a_L3;int a_P[3];
if(!a_equal(a_1485,0)){ goto a_G3;}
a_G2:a_1387(a_F2); return;
a_G3:if(!a_equal(a_1502,0)){ goto a_G5;}
a_1502=a_F2; return;
a_G5:a_comparestring(a_1374,a_1502,a_1374,a_F2,a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ goto a_G2;}
a_P[0]=2130705164;a_P[1]=a_F1;a_P[2]=a_1502;a_1238(-1,3,a_P); goto a_G2;
} /* setprogramtitle */
static void a_1506(int a_F1,int a_F2){ /* setmoduletag+>a+>a */
int a_L3;int a_P[3];
a_1359(a_F2);
a_1343(a_P);a_L3=a_P[0];
if(a_equal(a_L3,a_F2)){ goto a_G5;}
a_P[0]=2130705164;a_P[1]=a_F1;a_P[2]=a_L3;a_1238(-1,3,a_P);
a_G5:if(!a_is(a_1485)){ goto a_G8;}
a_1487=1;
a_1503=2; return;
a_G8:a_1503=1; return;
} /* setmoduletag */
static void a_1520(int a_F1){ /* fieldlists+>a */
int a_L2;int a_P[2];
if(!a_equal(1164737758,a_1692)){ return;}
a_1702();
a_1519(a_F1,a_P);to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-5]=a_P[0];
a_G4:if(!a_equal(1164737758,a_1692)){ return;}
a_1702();
a_1519(a_F1,a_P);a_L2=a_P[0];
if(a_equal(a_L2,to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-5])){ goto a_G4;}
a_P[0]=2130705231;a_P[1]=a_F1;a_1235(2,a_P); goto a_G4;
} /* fieldlists */
static void a_1519(int a_F1,int a_A[1]){ /* fieldlist+>a+a> */
int a_L3;int a_P[3];
a_A[0]=1;
a_G2:if(!a_equal(1164737749,a_1692)){ goto a_G4;}
a_1702(); goto a_G7;
a_G4:if(!a_1698(a_P)){ goto a_G15;}a_L3=a_P[0];
if(a_1673(a_L3,to_LIST(a_1719)->aupb,a_A[0])){ goto a_G7;}
a_P[0]=2130705218;a_P[1]=a_F1;a_P[2]=a_L3;a_1235(3,a_P);
a_G7:if(!a_equal(1164737770,a_1692)){ goto a_G10;}
a_1702();
a_incr(a_A[0]); goto a_G2;
a_G10:if(!a_equal(1164737725,a_1692)){ goto a_G12;}
a_1702(); goto a_G2;
a_G12:if(!a_equal(1164737761,a_1692)){ goto a_G14;}
a_1702(); return;
a_G14:a_P[0]=2130705241;a_P[1]=a_F1;a_1235(2,a_P); return;
a_G15:a_P[0]=2130705253;a_P[1]=a_F1;a_1235(2,a_P); return;
} /* fieldlist */
static void a_1521(void){ /* findlocalssel */
int a_L1;int a_P[1];
if(!a_equal(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-5],0)){ goto a_G5;}
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-5]=-1;
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-4]=1;
if(!a_1673(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb],to_LIST(a_1719)->aupb,1)){ return;} return;
a_G5:if(!a_1676(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb],to_LIST(a_1719)->aupb,a_P)){ goto a_G7;}a_L1=a_P[0];
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-4]=a_L1; return;
a_G7:to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-4]=-1; return;
} /* findlocalssel */
static void a_1522(int a_F1,int a_A[1]){ /* formalatag+>a+a> */
int a_P[2];
if(!a_1698(a_P)){ goto a_G4;}a_A[0]=a_P[0];
if(a_noteq(a_A[0],a_F1)){ return;}
a_P[0]=2130705293;a_P[1]=a_F1;a_1235(2,a_P); return;
a_G4:a_A[0]=a_F1;
a_P[0]=2130705263;a_P[1]=a_F1;a_1235(2,a_P); return;
} /* formalatag */
static void a_1532(int a_F1){ /* subbus+>a */
int a_P[3];
if(!a_equal(1164737740,a_1692)){ goto a_G6;}
a_1702();
if(!a_equal(1164737743,a_1692)){ goto a_G5;}
a_1702(); return;
a_G5:a_P[0]=2130705274;a_P[1]=1164737743;a_1235(2,a_P); return;
a_G6:a_P[0]=2130705274;a_P[1]=a_F1;a_P[2]=1164737740;a_1235(3,a_P); return;
} /* subbus */
static void a_1525(int a_F1){ /* nextformalaffix+>a */
int a_L2;int a_P[1];
if(!a_equal(1164737740,a_1692)){ goto a_G8;}
a_1532(a_F1);
a_1724(16777277,0);
a_G4:a_1520(a_F1);
a_1522(a_F1,a_P);to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb]=a_P[0];
a_1532(a_F1);
a_G7:a_1521(); return;
a_G8:if(!a_equal(1164737758,a_1692)){ goto a_G10;}
a_1724(16777283,0); goto a_G4;
a_G10:if(!a_equal(1696719075,a_1692)){ goto a_G14;}
a_1702();
a_1522(a_F1,a_P);a_L2=a_P[0];
a_1724(16777288,a_L2); return;
a_G14:if(!a_equal(1164737746,a_1692)){ goto a_G17;}
a_1702();
a_1724(16777310,604757376); return;
a_G17:if(!a_equal(1164737731,a_1692)){ goto a_G25;}
a_1702();
a_1522(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(1164737731,a_1692)){ goto a_G23;}
a_1702();
a_G22:a_1724(16777304,a_L2); return;
a_G23:if(a_equal(1164737791,a_1692)){ goto a_G22;}
a_1724(16777293,a_L2); return;
a_G25:a_1522(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(1164737731,a_1692)){ goto a_G29;}
a_1702();
a_G28:a_1724(16777298,a_L2); return;
a_G29:if(a_equal(1164737791,a_1692)){ goto a_G28;}
a_1532(a_F1);
a_1724(16777283,a_L2); goto a_G7;
} /* nextformalaffix */
static void a_1526(int a_F1,int a_A[1]){ /* readformalaffixes+>a+a> */
int a_L3;int a_P[2];
a_scratch(a_1719);
a_1681();
a_1241(a_P);a_L3=a_P[0];
a_G4:if(!a_1275(a_L3)){ goto a_G7;}
a_G5:a_A[0]=0;
a_scratch(a_1719); return;
a_G7:if(!a_equal(1164737782,a_1692)){ goto a_G12;}
a_1702();
a_1271(1);
a_1525(a_F1);
a_1271(0); goto a_G4;
a_G12:if(!a_equal(1164737776,a_1692)){ goto a_G14;}
a_G13:a_A[0]=1; return;
a_G14:if(a_equal(1164737770,a_1692)){ goto a_G13;}
if(!a_equal(1164737725,a_1692)){ goto a_G17;}
a_G16:a_A[0]=2; return;
a_G17:if(a_equal(1164737791,a_1692)){ goto a_G16;}
if(!a_equal(1164737779,a_1692)){ goto a_G20;}
a_G19:a_A[0]=3; return;
a_G20:if(a_equal(1164737764,a_1692)){ goto a_G19;}
a_P[0]=2130705283;a_P[1]=a_F1;a_1238(-1,2,a_P); goto a_G5;
} /* readformalaffixes */
static void a_1516(int a_F1,int a_F2,int a_A[1]){ /* checkformalaffixes+>a+>a+>a> */
int a_L4;int a_L5;int a_L6;int a_P[3];
a_L4=to_LIST(a_1719)->alwb;
a_L5=0;
a_1524=0;a_1523=0;
a_G4:if(a_more(a_L4,to_LIST(a_1719)->aupb)){ goto a_G18;}
if(!a_equal(to_LIST(a_1719)->offset[a_L4-2],16777310)){ goto a_G12;}
if(!a_equal(a_L5,0)){ goto a_G9;}
a_L5=1;
a_1524=1; goto a_G11;
a_G9:a_A[0]=0;
a_P[0]=2130705303;a_P[1]=a_F1;a_1238(-1,2,a_P);
a_G11:a_next(a_1719,a_L4); goto a_G4;
a_G12:if(!a_equal(to_LIST(a_1719)->offset[a_L4-2],16777298)){ goto a_G16;}
if(a_equal(a_L5,0)){ goto a_G11;}
a_L5=2;
a_1523=1; goto a_G11;
a_G16:if(!a_equal(a_L5,1)){ goto a_G11;}
a_L5=2; goto a_G11;
a_G18:if(!a_equal(a_L5,1)){ goto a_G21;}
a_A[0]=0;
a_P[0]=2130705314;a_P[1]=a_F1;a_1238(-1,2,a_P);
a_G21:a_L4=to_LIST(a_1719)->alwb;
a_L6=0;
a_G23:if(a_more(a_L4,to_LIST(a_1719)->aupb)){ goto a_G30;}
{register int a_r1=to_LIST(a_1719)->offset[a_L4-2];
 if(!(a_r1==16777298||a_r1==16777304)){ goto a_G27;}
}
if(!a_noteq(a_F2,1024)){ goto a_G28;}
a_L6=1;
a_G27:a_next(a_1719,a_L4); goto a_G23;
a_G28:a_A[0]=0;
a_P[0]=2130705326;a_P[1]=a_F1;a_P[2]=a_L4;a_1238(-1,3,a_P);
a_G30:if(a_equal(a_A[0],0)){ return;}
if(a_is(a_L6)){ return;}
if(a_noteq(a_F2,0)){ return;}
a_A[0]=0;
a_P[0]=2130705346;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
} /* checkformalaffixes */
static void a_1529(int a_F1,int a_F2,int a_F3,int a_F4){ /* ruleprototype+>a+>a+>a+>a */
int a_L5;int a_P[2];
a_G1:a_1531(a_F1,a_F2,a_F3,a_F4);
if(!a_equal(1164737770,a_1692)){ goto a_G13;}
a_1702();
if(!a_1695(a_P)){ goto a_G12;}a_F1=a_P[0];a_F2=a_P[1];
a_1690(a_P);a_F4=a_P[0];
a_1526(a_F2,a_P);a_L5=a_P[0];
a_P[0]=a_L5;a_1516(a_F2,a_F3,a_P);a_L5=a_P[0];
if(a_equal(a_L5,1)){ goto a_G1;}
if(!a_equal(a_L5,0)){ goto a_G11;}
a_G10:a_1715(); return;
a_G11:a_P[0]=2130705283;a_P[1]=a_F2;a_1238(-1,2,a_P); goto a_G10;
a_G12:a_P[0]=2130705353;a_1238(-1,1,a_P); goto a_G10;
a_G13:if(!a_equal(1164737776,a_1692)){ goto a_G15;}
a_1702(); return;
a_G15:a_1701(1164737776); goto a_G10;
} /* ruleprototype */
static void a_1531(int a_F1,int a_F2,int a_F3,int a_F4){ /* simpleruleprototype+>a+>a+>a+>a */
int a_L5;int a_L6;int a_P[1];
a_1481(22019,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,1)){ goto a_G9;}
a_1517(a_F1,a_F2,a_F3,a_F4,a_P);a_L6=a_P[0];
a_1757(a_L6,8);
a_P[0]=a_L6;a_1299(a_P);a_L6=a_P[0];
a_1154(1696718937);
a_G7:a_1162(a_L6);
a_1154(1696718991); return;
a_G9:if(!a_equal(a_L5,2)){ goto a_G11;}
a_1154(1696718904); goto a_G12;
a_G11:a_1154(1696719000);
a_G12:a_1154(1696719013);
a_1158(a_F3);
a_1160(a_F1,a_F2);
a_1725(a_P);a_L6=a_P[0]; goto a_G7;
} /* simpleruleprototype */
static void a_1518(int a_F1,int a_F2,int a_F3,int a_F4){ /* externalrule+>a+>a+>a+>a */
int a_L5;int a_P[2];
a_G1:a_1530(a_F1,a_F2,a_F3,a_F4);
if(!a_equal(1164737770,a_1692)){ goto a_G13;}
a_1702();
if(!a_1695(a_P)){ goto a_G12;}a_F1=a_P[0];a_F2=a_P[1];
a_1690(a_P);a_F4=a_P[0];
a_1526(a_F2,a_P);a_L5=a_P[0];
a_P[0]=a_L5;a_1516(a_F2,a_F3,a_P);a_L5=a_P[0];
if(a_equal(a_L5,2)){ goto a_G1;}
if(!a_equal(a_L5,0)){ goto a_G11;}
a_G10:a_1715(); return;
a_G11:a_P[0]=2130705283;a_P[1]=a_F2;a_1238(-1,2,a_P); goto a_G10;
a_G12:a_P[0]=2130705353;a_1238(-1,1,a_P); goto a_G10;
a_G13:if(!a_equal(1164737776,a_1692)){ goto a_G15;}
a_1702(); return;
a_G15:a_1701(1164737776); goto a_G10;
} /* externalrule */
static void a_1530(int a_F1,int a_F2,int a_F3,int a_F4){ /* simpleexternalrule+>a+>a+>a+>a */
int a_L5;int a_L6;int a_P[2];
a_1517(a_F1,a_F2,a_F3,a_F4,a_P);a_L5=a_P[0];
a_1757(a_L5,16);
a_P[0]=a_L5;a_1299(a_P);a_L5=a_P[0];
if(!a_equal(1164737791,a_1692)){ goto a_G6;}
a_1702(); goto a_G7;
a_G6:a_1701(1164737725);
a_G7:if(a_1697(a_P)){a_L6=a_P[0]; goto a_G10;}
a_L6=0;
a_P[0]=2130705337;a_P[1]=a_F2;a_1238(-1,2,a_P);
a_G10:a_1154(1696718920);
a_1162(a_L5);
a_1161(a_L6);
a_1154(1696718991); return;
} /* simpleexternalrule */
static void a_1517(int a_F1,int a_F2,int a_F3,int a_F4,int a_A[1]){ /* createruledefinition+>a+>a+>a+>a+a> */
int a_L6;int a_P[1];
a_1300(a_F1,a_F2,16777271,a_F4,a_P);a_A[0]=a_P[0];
a_1757(a_A[0],2);
a_1757(a_A[0],a_F3);
if(!a_is(a_1524)){ goto a_G6;}
a_1757(a_A[0],32768);
a_G6:if(!a_is(a_1523)){ goto a_G8;}
a_1757(a_A[0],65536);
a_G8:a_1725(a_P);a_L6=a_P[0];
a_1753(a_A[0],a_L6); return;
} /* createruledefinition */
static void a_1528(int a_F1,int a_F2,int a_F3,int a_F4){ /* ruledeclarer+>a+>a+>a+>a */
int a_L5;int a_L6;int a_P[1];
a_1517(a_F1,a_F2,a_F3,a_F4,a_P);a_L5=a_P[0];
a_P[0]=a_L5;a_1299(a_P);a_L5=a_P[0];
a_1154(1696719013);
a_1162(a_L5);
a_L6=to_LIST(a_1719)->alwb;
a_G6:if(!a_more(a_L6,to_LIST(a_1719)->aupb)){ goto a_G8;}
a_1563(a_L5); return;
a_G8:a_1163(to_LIST(a_1719)->offset[a_L6]);
a_next(a_1719,a_L6); goto a_G6;
} /* ruledeclarer */
static void a_1527(int a_F1,int a_F2){ /* ruledeclaration+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
if(!a_1695(a_P)){ goto a_G14;}a_L3=a_P[0];a_L4=a_P[1];
a_1690(a_P);a_L6=a_P[0];
a_1526(a_L4,a_P);a_L5=a_P[0];
a_P[0]=a_L5;a_1516(a_L4,a_F1,a_P);a_L5=a_P[0];
{ if(a_L5==1){ goto a_G6;}
 if(a_L5==2){ goto a_G10;}
 if(a_L5==3){ goto a_G12;}
  goto a_G8;}
a_G6:if(!a_is(a_F2)){ goto a_G9;}
a_G7:a_P[0]=2130705283;a_P[1]=a_L4;a_1238(-1,2,a_P);
a_G8:a_1715(); return;
a_G9:a_1529(a_L3,a_L4,a_F1,a_L6); return;
a_G10:if(!a_is(a_F2)){ goto a_G7;}
a_1518(a_L3,a_L4,a_F1,a_L6); return;
a_G12:if(a_is(a_F2)){ goto a_G7;}
a_1528(a_L3,a_L4,a_F1,a_L6); return;
a_G14:a_P[0]=2130705353;a_1238(-1,1,a_P); goto a_G8;
} /* ruledeclaration */
static void a_1568(int a_F1){ /* setlocalrepr+>a */
int a_L2;
a_L2=to_LIST(a_1719)->offset[a_F1];
to_LIST(a_1719)->offset[a_F1-1]=to_LIST(a_1720)->offset[a_L2-2];
to_LIST(a_1720)->offset[a_L2-2]=a_F1; return;
} /* setlocalrepr */
static void a_1561(int a_F1){ /* restorelocalrepr+>a */
int a_L2;
a_L2=to_LIST(a_1719)->offset[a_F1];
to_LIST(a_1720)->offset[a_L2-2]=to_LIST(a_1719)->offset[a_F1-1]; return;
} /* restorelocalrepr */
static void a_1569(int a_F1){ /* setuplocalstack+>a */
int a_L2;int a_L3;int a_P[3];
a_L2=to_LIST(a_1719)->alwb;
a_1549=0;
a_G3:if(a_more(a_L2,to_LIST(a_1719)->aupb)){ goto a_G10;}
if(!a_equal(to_LIST(a_1719)->offset[a_L2-2],16777310)){ goto a_G7;}
a_1549=a_L2;
a_G6:a_next(a_1719,a_L2); goto a_G3;
a_G7:a_1568(a_L2);
if(!a_was(a_1719,to_LIST(a_1719)->offset[a_L2-1])){ goto a_G6;}
a_P[0]=2130705450;a_P[1]=a_F1;a_P[2]=a_L2;a_1238(-1,3,a_P); goto a_G6;
a_G10:a_1739(a_F1,a_P);a_L3=a_P[0];
a_1724(16777335,a_L3);
a_1154(1696718945);
a_1163(a_L3); return;
} /* setuplocalstack */
static void a_1545(void){ /* closelocalstack */

a_G1:if(a_less(to_LIST(a_1719)->aupb,to_LIST(a_1719)->alwb)){ return;}
if(a_equal(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2],16777335)){ goto a_G5;}
if(a_equal(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2],16777310)){ goto a_G5;}
a_1561(to_LIST(a_1719)->aupb);
a_G5:a_unstack(a_1719); goto a_G1;
} /* closelocalstack */
static void a_1558(int a_F1,int a_A[1]){ /* openlocalrange+>a+a> */

a_A[0]=to_LIST(a_1719)->aupb;
if(a_equal(a_F1,0)){ return;}
a_1724(16777335,a_F1);
a_1154(1696718945);
a_1163(a_F1); return;
} /* openlocalrange */
static void a_1535(int a_F1){ /* addlocalaffix+>a */

a_1724(16777331,a_F1);
a_1568(to_LIST(a_1719)->aupb); return;
} /* addlocalaffix */
static void a_1544(int a_F1){ /* closelocalrange+>a */

a_G1:if(a_lseq(to_LIST(a_1719)->aupb,a_F1)){ return;}
if(!a_equal(to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-2],16777331)){ goto a_G4;}
a_1561(to_LIST(a_1719)->aupb);
a_G4:a_unstack(a_1719); goto a_G1;
} /* closelocalrange */
static void a_1550(int a_F1,int a_F2,int a_A[1]){ /* getformalaffix+>a+>a+a> */

if(!a_equal(a_F1,0)){ goto a_G4;}
a_A[0]=to_LIST(a_1720)->offset[a_F2-2];
if(a_was(a_1719,a_A[0])){ return;}
a_G4:a_A[0]=0; return;
} /* getformalaffix */
static int a_1553(int a_A[3]){ /* isqltag+a>+a>+a> */
int a_P[2];
if(!a_1695(a_P)){ return 0;}a_A[0]=a_P[0];a_A[1]=a_P[1];
a_1550(a_A[0],a_A[1],a_P);a_A[2]=a_P[0]; return 1;
} /* isqltag */
static void a_1534(int a_F1,int a_F2,int a_F3){ /* Dqloc+>a+>a+>a */

if(!a_equal(a_F3,0)){ goto a_G3;}
a_1160(a_F1,a_F2); return;
a_G3:a_1162(a_F3); return;
} /* Dqloc */
static void a_1557(int a_F1){ /* mustformallist+>a */
int a_P[2];
if(a_equal(a_F1,0)){ return;}
{register int a_r1=to_LIST(a_1719)->offset[a_F1-2];
 if(a_r1==16777283||a_r1==16777277){ return;}
}
a_P[0]=2130705480;a_P[1]=a_F1;a_1235(2,a_P); return;
} /* mustformallist */
static void a_1571(void){ /* skipoveranindex */
int a_P[2];
if(!a_equal(1164737740,a_1692)){ return;}
a_1702();
a_1574(a_P);
if(!a_equal(1164737743,a_1692)){ goto a_G6;}
a_1702(); return;
a_G6:a_P[0]=2130705362;a_P[1]=1164737743;a_1235(2,a_P); return;
} /* skipoveranindex */
static void a_1574(int a_A[1]){ /* skipoversource+a> */
int a_L2;int a_L3;int a_P[2];
a_A[0]=0;
a_L2=a_1692;
if(a_1694(a_P)){ return;}
if(!a_1695(a_P)){ goto a_G13;}a_L3=a_P[0];
if(!a_equal(a_L3,0)){ goto a_G11;}
if(!a_equal(1164737755,a_1692)){ goto a_G11;}
a_1702();
if(!a_1695(a_P)){ goto a_G10;}
a_G9:a_1571(); return;
a_G10:a_P[0]=2130705380;a_P[1]=1164737755;a_1235(2,a_P); return;
a_G11:if(a_equal(1164737740,a_1692)){ goto a_G9;}
a_A[0]=1; return;
a_G13:if(!a_equal(1164737734,a_1692)){ goto a_G15;}
a_G14:a_1702(); goto a_G19;
a_G15:if(a_equal(1164737737,a_1692)){ goto a_G14;}
if(a_equal(1164737728,a_1692)){ goto a_G14;}
if(a_equal(1164737731,a_1692)){ goto a_G14;}
if(a_equal(1164737752,a_1692)){ goto a_G14;} goto a_G21;
a_G19:if(a_1695(a_P)){ return;}
a_P[0]=2130705380;a_P[1]=a_L2;a_1235(2,a_P); return;
a_G21:a_P[0]=2130705394;a_1235(1,a_P); return;
} /* skipoversource */
static void a_1572(void){ /* skipoverdestination */
int a_P[2];
if(!a_equal(1164737722,a_1692)){ goto a_G6;}
a_G2:a_1702();
if(!a_1698(a_P)){ goto a_G5;}
if(!a_equal(1164737722,a_1692)){ return;} goto a_G2;
a_G5:a_P[0]=2130705413;a_1235(1,a_P); return;
a_G6:a_P[0]=2130705362;a_P[1]=1164737722;a_1235(2,a_P); return;
} /* skipoverdestination */
static void a_1573(int a_F1,int a_A[4]){ /* skipoverextension+>a+a>+a>+a>+a> */
int a_P[2];
a_1241(a_P);a_A[3]=a_P[0];
a_A[0]=0;a_A[1]=0;a_A[2]=0;
a_1691();
a_1271(3);
a_1684(1164737755);
a_G6:a_1574(a_P);
a_1572();
if(!a_equal(1164737770,a_1692)){ goto a_G10;}
a_1702(); goto a_G6;
a_G10:a_1701(1164737755);
if(!a_is(a_F1)){ goto a_G15;}
if(!a_equal(1164737761,a_1692)){ goto a_G15;}
a_1702();
a_A[2]=1;
a_G15:if(a_1695(a_P)){a_A[0]=a_P[0];a_A[1]=a_P[1]; goto a_G17;}
a_P[0]=2130705423;a_1235(1,a_P);
a_G17:a_1271(0);
if(!a_1275(a_A[3])){ goto a_G22;}
a_1689();
a_1712();
a_A[3]=1; return;
a_G22:a_1700();
a_A[3]=0; return;
} /* skipoverextension */
static void a_1559(int a_A[2]){ /* peekaftersource+a>+a> */
int a_L3;int a_P[1];
a_1241(a_P);a_A[1]=a_P[0];
a_1691();
a_A[0]=0;
a_1271(2);
a_1574(a_P);a_L3=a_P[0];
if(a_1744(a_1692,a_P)){a_A[0]=a_P[0]; goto a_G9;}
if(a_is(a_L3)){ goto a_G9;}
a_P[0]=2130705430;a_1235(1,a_P);
a_G9:a_1271(0);
if(!a_1275(a_A[1])){ goto a_G14;}
a_1689();
a_1712();
a_A[1]=1; return;
a_G14:a_1700();
a_A[1]=0; return;
} /* peekaftersource */
static void a_1566(int a_F1){ /* searchjump+>a */
int a_L2;int a_P[3];
a_L2=to_LIST(a_1719)->aupb;
a_G2:if(!a_less(a_L2,to_LIST(a_1719)->alwb)){ goto a_G4;}
a_P[0]=2130705439;a_P[1]=a_1565;a_P[2]=a_F1;a_1238(-1,3,a_P); return;
a_G4:if(!a_equal(to_LIST(a_1719)->offset[a_L2-2],16777335)){ goto a_G8;}
if(!a_equal(to_LIST(a_1719)->offset[a_L2],a_F1)){ goto a_G8;}
a_1154(1696718941);
a_1162(a_L2); return;
a_G8:a_previous(a_1719,a_L2); goto a_G2;
} /* searchjump */
static int a_1578(void){ /* terminator */
int a_L1;int a_P[2];
if(!a_equal(1164737782,a_1692)){ goto a_G4;}
a_1702();
a_1154(1696718988); return 1;
a_G4:if(!a_equal(1164737779,a_1692)){ goto a_G7;}
a_1702();
a_1154(1696718964); return 1;
a_G7:if(!a_equal(1164737672,a_1692)){ goto a_G12;}
a_1702();
a_1163(604757294);
a_1154(1696718988);
a_1575(604757294); return 1;
a_G12:if(!a_equal(1164737764,a_1692)){ return 0;}
a_1702();
if(!a_1698(a_P)){ goto a_G16;}a_L1=a_P[0];
a_1566(a_L1); return 1;
a_G16:a_P[0]=2130705380;a_P[1]=1164737764;a_1238(-1,2,a_P); return 1;
} /* terminator */
static void a_1552(int a_F1,int a_F2,int a_F3){ /* indexsource+>a+>a+>a */
int a_P[3];
a_1557(a_F3);
if(!a_equal(1164737740,a_1692)){ goto a_G11;}
a_1702();
a_1154(1696719027);
a_1534(a_F1,a_F2,a_F3);
a_1575(a_F2);
a_1154(1696718871);
if(!a_equal(1164737743,a_1692)){ goto a_G10;}
a_1702(); return;
a_G10:a_P[0]=2130705372;a_P[1]=1164737743;a_P[2]=a_F2;a_1235(3,a_P); return;
a_G11:a_1154(1696719027);
a_1534(a_F1,a_F2,a_F3);
a_1154(1696719035);
a_1534(a_F1,a_F2,a_F3);
a_1154(1696718871); return;
} /* indexsource */
static void a_1567(int a_F1,int a_F2,int a_F3){ /* selector+>a+>a+>a */
int a_L4;int a_P[3];
if(!a_equal(a_F3,0)){ goto a_G3;}
a_1163(a_F1); return;
a_G3:a_1557(a_F3);
if(!a_1676(a_F1,a_F3,a_P)){ goto a_G6;}a_L4=a_P[0];
a_1158(a_L4); return;
a_G6:a_P[0]=2130705470;a_P[1]=a_F1;a_P[2]=a_F2;a_1238(-1,3,a_P); return;
} /* selector */
static void a_1554(int a_F1){ /* listtag+>a */
int a_L2;int a_L3;int a_L4;int a_P[3];
if(!a_1553(a_P)){ goto a_G4;}a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];
a_1557(a_L4);
a_1534(a_L2,a_L3,a_L4); return;
a_G4:a_P[0]=2130705380;a_P[1]=a_F1;a_1235(2,a_P); return;
} /* listtag */
static void a_1575(int a_F1){ /* source+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[3];
if(!a_1694(a_P)){ goto a_G3;}a_L3=a_P[0];
a_1154(a_L3); return;
a_G3:if(!a_1553(a_P)){ goto a_G15;}a_L2=a_P[0];a_L3=a_P[1];a_L5=a_P[2];
if(!a_equal(a_L2,0)){ goto a_G11;}
if(!a_equal(1164737755,a_1692)){ goto a_G11;}
a_1702();
if(!a_1553(a_P)){ goto a_G10;}a_L2=a_P[0];a_L4=a_P[1];a_L5=a_P[2];
a_1552(a_L2,a_L4,a_L5);
a_1567(a_L3,a_L4,a_L5); return;
a_G10:a_P[0]=2130705380;a_P[1]=1164737755;a_1235(2,a_P); return;
a_G11:if(!a_equal(1164737740,a_1692)){ goto a_G14;}
a_1552(a_L2,a_L3,a_L5);
a_1567(a_L3,a_L3,a_L5); return;
a_G14:a_1534(a_L2,a_L3,a_L5); return;
a_G15:if(!a_equal(1164737734,a_1692)){ goto a_G19;}
a_1702();
a_1154(1696718957);
a_1554(1164737734); return;
a_G19:if(!a_equal(1164737737,a_1692)){ goto a_G23;}
a_1702();
a_1154(1696719035);
a_1554(1164737737); return;
a_G23:if(!a_equal(1164737728,a_1692)){ goto a_G27;}
a_1702();
a_1154(1696719039);
a_1554(1164737728); return;
a_G27:if(!a_equal(1164737731,a_1692)){ goto a_G31;}
a_1702();
a_1154(1696719043);
a_1554(1164737731); return;
a_G31:if(!a_equal(1164737752,a_1692)){ goto a_G35;}
a_1702();
a_1154(1696718876);
a_1554(1164737752); return;
a_G35:a_P[0]=2130705459;a_P[1]=a_F1;a_1235(2,a_P);
a_1712(); return;
} /* source */
static void a_1576(int a_F1){ /* sourceorstring+>a */
int a_L2;int a_L3;int a_L4;int a_P[1];
if(!a_1697(a_P)){ goto a_G8;}a_L2=a_P[0];
a_1690(a_P);a_L4=a_P[0];
a_1750(a_L2,a_L4,a_P);a_L3=a_P[0];
a_1154(1696718988);
a_1162(16777845);
a_1154(1696718988);
a_1162(a_L3); return;
a_G8:if(!a_equal(1164737749,a_1692)){ goto a_G12;}
a_1702();
a_1154(1696718988);
a_1154(1696718972); return;
a_G12:a_1154(1696718988);
a_1575(a_F1); return;
} /* sourceorstring */
static int a_1540(void){ /* anchoraffix */
int a_P[2];
if(!a_equal(1164737746,a_1692)){ return 0;}
a_1702();
if(!a_is(a_1549)){ goto a_G6;}
a_1154(1696718988);
a_1162(a_1549); return 1;
a_G6:a_P[0]=2130705499;a_P[1]=a_1565;a_1238(-1,2,a_P); return 1;
} /* anchoraffix */
static void a_1537(void){ /* affixform */
int a_L1;int a_L2;int a_P[2];
if(!a_1695(a_P)){ goto a_G8;}a_L1=a_P[0];a_L2=a_P[1];
a_1160(a_L1,a_L2);
a_1547=0;
a_G4:if(!a_equal(1164737782,a_1692)){ return;}
a_1702();
if(a_1540()){ return;}
a_1576(a_L2); goto a_G4;
a_G8:a_P[0]=2130705386;a_1238(-1,1,a_P);
a_1712(); return;
} /* affixform */
static void a_1577(int a_F1){ /* specialaffixform+>a */
int a_L2;int a_P[1];
a_1160(0,a_F1);
a_1154(1696718988);
a_1547=0;
a_1241(a_P);a_L2=a_P[0];
a_1575(a_F1);
if(a_1275(a_L2)){ goto a_G8;}
a_1702();
a_G8:if(!a_equal(a_F1,604757314)){ goto a_G14;}
a_G9:if(a_1540()){ return;}
a_1154(1696718988);
a_1575(a_F1);
if(!a_equal(1164737722,a_1692)){ return;}
a_1702(); goto a_G9;
a_G14:a_1154(1696718988);
a_1575(a_F1); return;
} /* specialaffixform */
static void a_1579(int a_F1,int a_F2){ /* toselectors+>a+>a */
int a_L3;int a_P[2];
if(!a_equal(1164737722,a_1692)){ goto a_G9;}
a_G2:a_1702();
if(!a_1698(a_P)){ goto a_G7;}a_L3=a_P[0];
a_1154(1696719031);
a_1567(a_L3,a_F1,a_F2);
if(!a_equal(1164737722,a_1692)){ return;} goto a_G2;
a_G7:a_P[0]=2130705380;a_P[1]=1164737722;a_1238(-1,2,a_P);
a_1712(); return;
a_G9:a_P[0]=2130705362;a_P[1]=1164737722;a_1238(-1,2,a_P); return;
} /* toselectors */
static void a_1548(int a_F1,int a_F2){ /* extension+>a+>a */
int a_L3;int a_P[1];
a_1550(a_F1,a_F2,a_P);a_L3=a_P[0];
a_1557(a_L3);
a_1547=0;
a_1154(1696718915);
a_1534(a_F1,a_F2,a_L3);
a_1684(1164737755);
a_G7:a_1575(a_F2);
a_1579(a_F2,a_L3);
if(!a_equal(1164737770,a_1692)){ goto a_G12;}
a_1702();
a_1154(1696718892); goto a_G7;
a_G12:a_1154(1696718915);
a_1684(1164737755);
a_1684(1164737761);
a_1684(a_F1);
a_1684(1164737767);
a_1684(a_F2); return;
} /* extension */
static int a_1555(void){ /* lookingatamember */

{ if(a_1692==1164737758||a_1692==1164737755||a_1692==1164737734||a_1692==1164737737||a_1692==1164737728||a_1692==1164737731||a_1692==1164737752||(1962709581<=a_1692 && a_1692<=1990708580)||(604756899<=a_1692 && a_1692<=1164737376)){ return 1;}
  return 0;}
} /* lookingatamember */
static void a_1556(void){ /* member */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[4];
if(!a_equal(1164737758,a_1692)){ goto a_G9;}
a_1702();
if(!a_equal(1164737755,a_1692)){ goto a_G8;}
a_1573(1,a_P);a_L1=a_P[0];a_L2=a_P[1];a_L3=a_P[2];a_L4=a_P[3];
if(a_is(a_L4)){ return;}
if(!a_is(a_L3)){ goto a_G8;}
a_G7:a_1548(a_L1,a_L2); return;
a_G8:a_1546(); return;
a_G9:if(!a_equal(1164737755,a_1692)){ goto a_G13;}
a_P[0]=2130705403;a_1240(8,-1,1,a_P);
a_1573(0,a_P);a_L1=a_P[0];a_L2=a_P[1];a_L4=a_P[3];
if(a_is(a_L4)){ return;} goto a_G7;
a_G13:a_1559(a_P);a_L2=a_P[0];a_L4=a_P[1];
if(a_is(a_L4)){ return;}
if(!a_is(a_L2)){ goto a_G17;}
a_1577(a_L2); return;
a_G17:a_1537(); return;
} /* member */
static void a_1560(int a_A[1]){ /* peeklabel+a> */
int a_P[1];
a_1691();
a_A[0]=0;
if(!a_1698(a_P)){ goto a_G7;}a_A[0]=a_P[0];
if(a_equal(1164737764,a_1692)){ goto a_G7;}
if(a_equal(1164737779,a_1692)){ goto a_G7;}
a_A[0]=0;
a_G7:a_1700(); return;
} /* peeklabel */
static void a_1570(int a_F1){ /* skiplabel+>a */

if(!a_is(a_F1)){ return;}
a_1684(a_F1);
a_1684(1164737764); return;
} /* skiplabel */
static void a_1536(void){ /* addlocalaffixes */
int a_L1;int a_P[2];
a_1691();
if(!a_equal(1164737779,a_1692)){ goto a_G18;}
a_1702();
if(!a_1698(a_P)){ goto a_G18;}
a_1700();
a_1154(1696718953);
a_G7:if(!a_equal(1164737779,a_1692)){ goto a_G14;}
a_1702();
if(!a_1698(a_P)){ goto a_G12;}a_L1=a_P[0];
a_1163(a_L1);
a_1535(a_L1); goto a_G7;
a_G12:a_P[0]=2130705380;a_P[1]=1164737779;a_1238(-1,2,a_P);
a_G13:a_1712(); return;
a_G14:if(!a_equal(1164737764,a_1692)){ goto a_G17;}
a_1702();
a_1154(1696718885); return;
a_G17:a_P[0]=2130705362;a_P[1]=1164737764;a_1238(-1,2,a_P); goto a_G13;
a_G18:a_1700(); return;
} /* addlocalaffixes */
static void a_1546(void){ /* compoundmember */
int a_L1;int a_L2;int a_P[2];
a_1154(1696718979);
a_1560(a_P);a_L1=a_P[0];
a_1558(a_L1,a_P);a_L2=a_P[0];
a_1570(a_L1);
a_1536();
if(!a_equal(1164737725,a_1692)){ goto a_G9;}
a_1702();
a_1543(); goto a_G10;
a_G9:a_1539();
a_G10:if(!a_equal(1164737761,a_1692)){ goto a_G12;}
a_1702(); goto a_G14;
a_G12:a_P[0]=2130705362;a_P[1]=1164737761;a_1238(-1,2,a_P);
a_1712();
a_G14:a_1154(1696718882);
a_1544(a_L2); return;
} /* compoundmember */
static void a_1538(void){ /* alternative */
int a_P[2];
a_G1:if(a_1578()){ return;}
if(!a_1555()){ goto a_G7;}
a_1556();
if(!a_equal(1164737770,a_1692)){ return;}
a_1702();
a_1154(1696718892); goto a_G1;
a_G7:a_P[0]=2130705489;a_P[1]=a_1565;a_1238(-1,2,a_P); return;
} /* alternative */
static void a_1539(void){ /* alternativeseries */

a_G1:a_1538();
if(!a_equal(1164737773,a_1692)){ return;}
a_1702();
a_1154(1696719016); goto a_G1;
} /* alternativeseries */
static void a_1541(void){ /* area */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_G1:a_L3=0;
if(!a_1695(a_P)){ goto a_G4;}a_L1=a_P[0];a_L2=a_P[1];
a_1160(a_L1,a_L2); goto a_G7;
a_G4:if(!a_1694(a_P)){ goto a_G6;}a_L2=a_P[0];
a_1154(a_L2); goto a_G7;
a_G6:a_L3=1;
a_G7:if(!a_equal(1164737764,a_1692)){ goto a_G15;}
a_1702();
a_L3=0;
a_1154(1696718885);
if(!a_1695(a_P)){ goto a_G13;}a_L1=a_P[0];a_L2=a_P[1];
a_1160(a_L1,a_L2); goto a_G15;
a_G13:if(!a_1694(a_P)){ goto a_G15;}a_L2=a_P[0];
a_1154(a_L2);
a_G15:if(!a_is(a_L3)){ goto a_G17;}
a_P[0]=2130705511;a_P[1]=a_1565;a_1238(-1,2,a_P);
a_G17:if(!a_equal(1164737773,a_1692)){ goto a_G20;}
a_1702();
a_1154(1696719016); goto a_G1;
a_G20:a_1701(1164737743); return;
} /* area */
static void a_1542(int a_A[1]){ /* class+a> */
int a_P[2];
if(!a_equal(1164737740,a_1692)){ goto a_G12;}
a_1702();
a_A[0]=0;
a_1154(1696718860);
a_1541();
a_1154(1696718860);
a_1154(1696718892);
if(!a_equal(1164737770,a_1692)){ goto a_G10;}
a_1702(); goto a_G11;
a_G10:a_P[0]=2130705362;a_P[1]=1164737770;a_1238(-1,2,a_P);
a_G11:a_1538(); return;
a_G12:a_A[0]=1;
a_1154(1696718860);
a_1154(1696718885);
a_1154(1696718860);
a_1154(1696718892); goto a_G11;
} /* class */
static void a_1543(void){ /* classification */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_1154(1696718868);
a_1547=0;
a_1241(a_P);a_L1=a_P[0];
a_L3=0;
a_1575(1164737725);
a_1154(1696718868);
if(!a_equal(1164737725,a_1692)){ goto a_G9;}
a_1702(); goto a_G10;
a_G9:a_P[0]=2130705362;a_P[1]=1164737725;a_1238(-1,2,a_P);
a_G10:a_1542(a_P);a_L2=a_P[0];
if(a_is(a_L2)){ goto a_G16;}
if(!a_equal(1164737773,a_1692)){ goto a_G16;}
a_1702();
a_1154(1696719016);
a_incr(a_L3); goto a_G10;
a_G16:if(!a_1275(a_L1)){ goto a_G18;}
a_1712(); return;
a_G18:if(a_equal(a_L2,0)){ return;}
if(!a_equal(a_L3,0)){ return;}
a_P[0]=2130705520;a_1238(-1,1,a_P); return;
} /* classification */
static void a_1551(int a_A[1]){ /* getruletag+a> */
int a_P[1];
if(!a_is(a_1565)){ goto a_G3;}
a_1739(a_1565,a_P);a_A[0]=a_P[0]; return;
a_G3:a_A[0]=0; return;
} /* getruletag */
static void a_1564(int a_F1){ /* rulepragmats+>a */

if(!a_1489(22027)){ goto a_G3;}
a_1757(a_F1,16777216);
a_G3:if(!a_1489(22028)){ goto a_G5;}
a_1757(a_F1,33554432);
a_G5:if(!a_1489(22017)){ return;}
a_1757(a_F1,67108864); return;
} /* rulepragmats */
static void a_1563(int a_F1){ /* rulebody+>a */
int a_P[2];
a_1565=a_F1;
a_1564(a_1565);
a_1569(a_F1);
a_1547=1;
if(!a_equal(1164737779,a_1692)){ goto a_G7;}
a_1536(); goto a_G11;
a_G7:if(!a_equal(1164737764,a_1692)){ goto a_G9;}
a_1702(); goto a_G11;
a_G9:a_P[0]=2130705362;a_P[1]=1164737764;a_1238(-1,2,a_P);
a_1712();
a_G11:if(!a_equal(1164737725,a_1692)){ goto a_G14;}
a_1702();
a_1543(); goto a_G15;
a_G14:a_1539();
a_G15:a_1154(1696718991);
a_1545();
a_1565=0;
if(!a_is(a_1547)){ goto a_G20;}
a_1757(a_F1,16384);
a_G20:if(!a_equal(1164737776,a_1692)){ goto a_G22;}
a_1702(); return;
a_G22:a_P[0]=2130705362;a_P[1]=1164737776;a_1238(-1,2,a_P);
a_1715(); return;
} /* rulebody */
static void a_1562(void){ /* rootbody */
int a_L1;int a_P[2];
a_1565=16777853;
a_1549=0;
a_1690(a_P);a_L1=a_P[0];
a_1754(16777853,a_L1);
a_1154(1696719009);
a_1162(16777853);
a_1564(16777853);
a_scratch(a_1719);
a_1569(16777853);
a_1547=1;
a_1536();
if(!a_equal(1164737725,a_1692)){ goto a_G15;}
a_1702();
a_1543(); goto a_G16;
a_G15:a_1539();
a_G16:a_1154(1696718991);
a_1545();
a_1565=0;
if(!a_is(a_1547)){ goto a_G21;}
a_1757(16777853,16384);
a_G21:if(!a_equal(1164737776,a_1692)){ goto a_G23;}
a_1702(); return;
a_G23:a_P[0]=2130705362;a_P[1]=1164737776;a_1238(-1,2,a_P);
a_1715(); return;
} /* rootbody */
static void a_1610(int a_F1){ /* noexternal+>a */
int a_L2;int a_P[4];
if(!a_1746(a_F1,16)){ return;}
a_1741(a_F1,a_P);a_L2=a_P[0];
a_P[0]=2130705530;a_P[1]=a_L2;a_P[2]=a_F1;a_P[3]=to_LIST(a_1718)->offset[a_F1-5];a_1238(-1,4,a_P); return;
} /* noexternal */
static void a_1583(int a_F1){ /* checkconstanttype+>a */
int a_L2;int a_P[5];
a_1741(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,16777226)){ goto a_G4;}
a_1610(a_F1); return;
a_G4:if(a_equal(a_L2,16777257)){ return;}
a_P[0]=2130705573;a_P[1]=a_L2;a_P[2]=a_F1;a_P[3]=16777226;a_P[4]=to_LIST(a_1718)->offset[a_F1-5];a_1238(-1,5,a_P); return;
} /* checkconstanttype */
static void a_1587(int a_F1){ /* checkstrictconstanttype+>a */
int a_L2;int a_P[5];
a_1741(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,16777226)){ goto a_G4;}
a_1610(a_F1); return;
a_G4:a_P[0]=2130705573;a_P[1]=a_L2;a_P[2]=a_F1;a_P[3]=16777226;a_P[4]=to_LIST(a_1718)->offset[a_F1-5];a_1238(-1,5,a_P); return;
} /* checkstrictconstanttype */
static void a_1584(int a_F1){ /* checklisttype+>a */
int a_L2;int a_P[4];
a_1741(a_F1,a_P);a_L2=a_P[0];
{ if(!(a_L2==16777240||a_L2==16777244||a_L2==16777250)){ goto a_G4;}
}
a_1610(a_F1); return;
a_G4:a_P[0]=2130705541;a_P[1]=a_L2;a_P[2]=a_F1;a_P[3]=to_LIST(a_1718)->offset[a_F1-5];a_1238(-1,4,a_P); return;
} /* checklisttype */
static int a_1606(int a_F1){ /* islisttype+>a */

{register int a_r1=to_LIST(a_1718)->offset[a_F1-3];
 if(a_r1==16777240||a_r1==16777244||a_r1==16777250){ return 1;}
  return 0;}
} /* islisttype */
static void a_1618(void){ /* secondpass */

a_G1:if(!a_1164(1696719013)){ goto a_G3;}
a_1615(1696719013); goto a_G1;
a_G3:if(!a_1164(1696719009)){ goto a_G5;}
a_1615(1696719009); goto a_G1;
a_G5:if(!a_1164(1696718924)){ goto a_G7;}
a_1597(); goto a_G1;
a_G7:if(!a_1164(1696718949)){ goto a_G9;}
a_1608(); goto a_G1;
a_G9:if(!a_1164(1696718928)){ goto a_G11;}
a_1609(); goto a_G1;
a_G11:if(!a_1164(1696718910)){ goto a_G13;}
a_1593(); goto a_G1;
a_G13:if(!a_1164(1696718920)){ goto a_G15;}
a_1595(); goto a_G1;
a_G15:if(!a_1164(1696718937)){ goto a_G17;}
a_1604(); goto a_G1;
a_G17:if(!a_1164(1696718904)){ goto a_G19;}
a_1591(); goto a_G1;
a_G19:if(!a_1164(1696719000)){ goto a_G21;}
a_1612(); goto a_G1;
a_G21:if(!a_1164(1696719021)){ goto a_G23;}
a_1620(); goto a_G1;
a_G23:if(!a_1164(1696718996)){ goto a_G25;}
a_1611(); goto a_G1;
a_G25:if(a_1164(1696718899)){ return;}
a_1248(a_1001,2130706193); return;
} /* secondpass */
static void a_1615(int a_F1){ /* ruledeclarer+>a */
int a_L2;int a_P[1];
a_1200(a_P);a_1617=a_P[0];
a_1154(a_F1);
a_1162(a_1617);
a_G4:if(!a_1180(a_P)){ goto a_G6;}a_L2=a_P[0];
a_1163(a_L2); goto a_G4;
a_G6:a_1590();
a_1176(1696718991);
a_1154(1696718991); return;
} /* ruledeclarer */
static void a_1590(void){ /* compoundmember */
int a_L1;int a_P[1];
if(!a_1164(1696718945)){ goto a_G5;}
a_1154(1696718945);
a_1201(a_P);a_L1=a_P[0];
a_1163(a_L1);
a_G5:if(!a_1164(1696718953)){ goto a_G11;}
a_1154(1696718953);
a_G7:if(!a_1164(1696718885)){ goto a_G9;}
a_1154(1696718885); goto a_G11;
a_G9:a_1201(a_P);a_L1=a_P[0];
a_1163(a_L1); goto a_G7;
a_G11:if(!a_1164(1696718868)){ goto a_G19;}
a_1154(1696718868);
a_1621();
a_1196(1696718868);
a_1154(1696718868);
a_G16:a_1589();
if(!a_1164(1696719016)){ return;}
a_1154(1696719016); goto a_G16;
a_G19:a_1582();
if(!a_1164(1696719016)){ return;}
a_1154(1696719016); goto a_G19;
} /* compoundmember */
static void a_1589(void){ /* class */

a_1196(1696718860);
a_1154(1696718860);
a_G3:a_1625();
if(!a_1164(1696719016)){ goto a_G6;}
a_1154(1696719016); goto a_G3;
a_G6:a_1196(1696718860);
a_1154(1696718860);
a_1196(1696718892);
a_1154(1696718892);
a_1582(); return;
} /* class */
static void a_1625(void){ /* zone */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_G1:if(!a_1172(a_P)){ goto a_G3;}a_L3=a_P[0];
a_1154(a_L3); goto a_G10;
a_G3:if(!a_1174(a_P)){ goto a_G10;}a_L1=a_P[0];a_L2=a_P[1];
a_1304(a_L1,a_L2,a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ goto a_G10;}
a_1162(a_L3);
a_1758(a_L3);
if(a_1606(a_L3)){ goto a_G10;}
a_1583(a_L3);
a_G10:if(!a_1164(1696718885)){ return;}
a_1154(1696718885); goto a_G1;
} /* zone */
static void a_1582(void){ /* alternative */
int a_L1;int a_P[1];
a_G1:if(!a_1164(1696718988)){ goto a_G3;}
a_1154(1696718988); return;
a_G3:if(!a_1164(1696718964)){ goto a_G5;}
a_1154(1696718964); return;
a_G5:if(!a_1164(1696718941)){ goto a_G9;}
a_1154(1696718941);
a_1200(a_P);a_L1=a_P[0];
a_1162(a_L1); return;
a_G9:if(!a_1164(1696718915)){ goto a_G13;}
a_1594();
a_G11:if(!a_1164(1696718892)){ return;}
a_1154(1696718892); goto a_G1;
a_G13:if(!a_1164(1696718979)){ goto a_G18;}
a_1154(1696718979);
a_1590();
a_1196(1696718882);
a_1154(1696718882); goto a_G11;
a_G18:a_1581(); goto a_G11;
} /* alternative */
static void a_1594(void){ /* extension */

a_1154(1696718915);
a_1614();
a_G3:a_1621();
a_G4:if(!a_1164(1696719031)){ goto a_G7;}
a_1154(1696719031);
a_1622(); goto a_G4;
a_G7:if(!a_1164(1696718892)){ goto a_G9;}
a_1154(1696718892); goto a_G3;
a_G9:a_1196(1696718915);
a_1154(1696718915); return;
} /* extension */
static void a_1622(void){ /* toselector */
int a_L1;int a_P[1];
if(!a_1168(a_P)){ goto a_G3;}a_L1=a_P[0];
a_1158(a_L1); return;
a_G3:a_1201(a_P);a_L1=a_P[0];
a_1163(a_L1); return;
} /* toselector */
static void a_1586(int a_A[1]){ /* checkruletype+>a> */
int a_L2;int a_P[5];
if(a_equal(a_A[0],0)){ return;}
a_1741(a_A[0],a_P);a_L2=a_P[0];
if(a_equal(a_L2,16777271)){ return;}
a_P[0]=2130705573;a_P[1]=a_L2;a_P[2]=a_A[0];a_P[3]=16777271;a_P[4]=to_LIST(a_1718)->offset[a_A[0]-5];a_1238(-1,5,a_P);
a_A[0]=0; return;
} /* checkruletype */
static void a_1581(void){ /* affixform */
int a_L1;int a_L2;int a_L3;int a_P[2];
if(a_1179(a_P)){a_L3=a_P[0]; goto a_G4;}
a_1199(a_P);a_L1=a_P[0];a_L2=a_P[1];
a_1304(a_L1,a_L2,a_P);a_L3=a_P[0];
a_G4:a_P[0]=a_L3;a_1586(a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ goto a_G10;}
a_1162(a_L3);
a_1758(a_L3);
if(!a_1746(a_L3,1024)){ goto a_G10;}
a_1757(a_1617,8192);
a_G10:if(!a_1164(1696718988)){ return;}
a_1154(1696718988);
a_1621(); goto a_G10;
} /* affixform */
static void a_1621(void){ /* source */
int a_L1;int a_P[1];
if(!a_1172(a_P)){ goto a_G3;}a_L1=a_P[0];
a_1154(a_L1); return;
a_G3:if(!a_1164(1696718957)){ goto a_G6;}
a_1154(1696718957);
a_G5:a_1614(); return;
a_G6:if(!a_1164(1696719035)){ goto a_G8;}
a_1154(1696719035); goto a_G5;
a_G8:if(!a_1164(1696719039)){ goto a_G10;}
a_1154(1696719039); goto a_G5;
a_G10:if(!a_1164(1696719043)){ goto a_G12;}
a_1154(1696719043); goto a_G5;
a_G12:if(!a_1164(1696718876)){ goto a_G14;}
a_1154(1696718876); goto a_G5;
a_G14:if(!a_1164(1696718972)){ goto a_G16;}
a_1154(1696718972); return;
a_G16:if(!a_1164(1696719027)){ goto a_G5;}
a_1154(1696719027);
a_1614();
a_1621();
a_1196(1696718871);
a_1154(1696718871);
if(!a_1168(a_P)){ goto a_G24;}a_L1=a_P[0];
a_1158(a_L1); return;
a_G24:a_1201(a_P);a_L1=a_P[0];
a_1163(a_L1); return;
} /* source */
static void a_1614(void){ /* readqtloc */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
if(!a_1171(a_P)){ goto a_G3;}a_L3=a_P[0];
a_1162(a_L3); return;
a_G3:if(!a_1179(a_P)){ goto a_G9;}a_L3=a_P[0];
a_G4:a_1162(a_L3);
a_1741(a_L3,a_P);a_L4=a_P[0];
if(!a_equal(a_L4,16777271)){ goto a_G8;}
a_P[0]=2130705582;a_P[1]=a_L3;a_P[2]=to_LIST(a_1718)->offset[a_L3-5];a_1238(-1,3,a_P); return;
a_G8:a_1758(a_L3); return;
a_G9:a_1199(a_P);a_L1=a_P[0];a_L2=a_P[1];
a_1304(a_L1,a_L2,a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ return;} goto a_G4;
} /* readqtloc */
static void a_1597(void){ /* filedeclarer */
int a_L1;int a_L2;int a_P[1];
a_1154(1696718924);
a_1202(a_P);
a_1200(a_P);a_L2=a_P[0];
a_1162(a_L2);
if(!a_1164(1696719027)){ goto a_G8;}
a_1154(1696719027);
a_1596();
a_G8:a_1197(a_P);a_L1=a_P[0];
a_1158(a_L1);
a_1200(a_P);a_L1=a_P[0];
a_1162(a_L1);
a_1200(a_P);a_L1=a_P[0];
a_1162(a_L1);
a_1196(1696718991);
a_1154(1696718991); return;
} /* filedeclarer */
static void a_1596(void){ /* filearea */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_G1:if(!a_1164(1696718871)){ goto a_G3;}
a_1154(1696718871); return;
a_G3:a_1199(a_P);a_L1=a_P[0];a_L2=a_P[1];
a_1304(a_L1,a_L2,a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ goto a_G1;}
a_1162(a_L3);
a_1584(a_L3);
a_1758(a_L3); goto a_G1;
} /* filearea */
static void a_1608(void){ /* listdeclarer */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
a_1154(1696718949);
a_1200(a_P);a_L4=a_P[0];
a_1162(a_L4);
a_1197(a_P);a_L1=a_P[0];
a_1158(a_L1);
{ if(a_L1==0){ goto a_G7;}
 if(a_L1==1||a_L1==2){ goto a_G8;}
  goto a_G10;}
a_G7:a_1158(0); goto a_G16;
a_G8:a_1197(a_P);a_L1=a_P[0];
a_1158(a_L1); goto a_G16;
a_G10:a_1199(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1304(a_L2,a_L3,a_P);a_L5=a_P[0];
if(a_equal(a_L5,0)){ goto a_G16;}
a_1162(a_L5);
a_1587(a_L5);
a_1758(a_L5);
a_G16:a_1613(0,a_L4);
a_1176(1696718991);
a_1154(1696718991); return;
} /* listdeclarer */
static void a_1613(int a_F1,int a_F2){ /* readlistselectors+>a+>a */
int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[1];
a_1690(a_P);a_L3=a_P[0];
a_1677(a_F2,a_P);a_L5=a_P[0];
a_1197(a_P);a_L4=a_P[0];
if(!a_equal(a_L4,a_L5)){ goto a_G6;}
a_L8=0; goto a_G7;
a_G6:a_L8=1;
a_G7:if(!a_equal(a_L4,-1)){ goto a_G12;}
a_1197(a_P);
if(a_equal(a_L4,a_L5)){ goto a_G20;}
if(a_equal(a_F1,0)){ goto a_G20;}
a_1619(a_F2,2130705551); goto a_G20;
a_G12:if(a_equal(a_L4,a_L5)){ goto a_G14;}
a_1619(a_F2,2130705551);
a_G14:a_1197(a_P);a_L4=a_P[0];
a_1680(a_F2,a_P);a_L5=a_P[0];
if(a_equal(a_L4,a_L5)){ goto a_G20;}
if(a_is(a_L8)){ goto a_G20;}
a_1619(a_F2,2130705563);
a_L8=1;
a_G20:if(!a_1180(a_P)){ return;}a_L6=a_P[0];
a_1197(a_P);a_L7=a_P[0];
if(a_is(a_L8)){ goto a_G20;}
a_1669(a_F2,a_L6,a_L7,a_L3); goto a_G20;
} /* readlistselectors */
static void a_1619(int a_F1,int a_F2){ /* selectorerror+>a+>a */
int a_L3;int a_P[4];
a_1741(a_F1,a_P);a_L3=a_P[0];
a_P[0]=a_F2;a_P[1]=a_L3;a_P[2]=a_F1;a_P[3]=to_LIST(a_1718)->offset[a_F1-5];a_1238(-1,4,a_P); return;
} /* selectorerror */
static void a_1609(void){ /* listfill */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_P[5];
a_1154(1696718928);
a_1202(a_P);a_L1=a_P[0];
a_1199(a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1304(a_L3,a_L4,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G7;}
a_G6:a_1176(1696718991); return;
a_G7:a_1162(a_L5);
a_1610(a_L5);
a_1757(a_L5,4096);
if(!a_1746(a_L5,8)){ goto a_G12;}
a_1757(a_L5,1);
a_G12:a_1741(a_L5,a_P);a_L2=a_P[0];
if(!a_noteq(a_L2,a_L1)){ goto a_G15;}
a_P[0]=2130705573;a_P[1]=a_L1;a_P[2]=a_L5;a_P[3]=a_L2;a_P[4]=to_LIST(a_1718)->offset[a_L5-5];a_1238(-1,5,a_P); goto a_G6;
a_G15:a_1613(0,a_L5);
a_1196(1696718885);
a_1598(a_L5);
a_1154(1696718991); return;
} /* listfill */
static void a_1598(int a_F1){ /* filler+>a */

a_G1:if(a_1164(1696718991)){ return;}
a_1602();
a_1603();
a_1601(a_F1); goto a_G1;
} /* filler */
static void a_1602(void){ /* filleritem */
int a_L1;int a_L2;int a_L3;int a_P[2];
if(!a_1177(a_P)){ goto a_G3;}a_L1=a_P[0];
a_1161(a_L1); return;
a_G3:if(!a_1172(a_P)){ goto a_G5;}a_L1=a_P[0];
a_1154(a_L1); return;
a_G5:if(!a_1164(1696718979)){ goto a_G9;}
a_1154(1696718979);
a_1599();
a_1154(1696718882); return;
a_G9:if(!a_1164(1696718915)){ goto a_G13;}
a_1154(1696718915);
a_1600();
a_1154(1696718915); return;
a_G13:a_1199(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1304(a_L2,a_L3,a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
a_1162(a_L1);
a_1758(a_L1);
a_1583(a_L1); return;
} /* filleritem */
static void a_1599(void){ /* fillerblock1 */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_G1:if(a_1164(1696718882)){ return;}
if(!a_1164(1696719024)){ goto a_G4;}
a_1154(1696719024); goto a_G1;
a_G4:if(!a_1172(a_P)){ goto a_G6;}a_L1=a_P[0];
a_1154(a_L1); goto a_G1;
a_G6:a_1199(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1304(a_L2,a_L3,a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ goto a_G1;}
a_1162(a_L1);
a_1758(a_L1);
a_1583(a_L1); goto a_G1;
} /* fillerblock1 */
static void a_1623(void){ /* toselectors */
int a_L1;int a_P[1];
a_G1:if(!a_1164(1696719031)){ return;}
a_1154(1696719031);
if(!a_1164(1696719024)){ goto a_G5;}
a_1154(1696719024); goto a_G1;
a_G5:a_1201(a_P);a_L1=a_P[0];
a_1163(a_L1); goto a_G1;
} /* toselectors */
static void a_1600(void){ /* fillerblock2 */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_G1:if(a_1164(1696718915)){ return;}
if(!a_1172(a_P)){ goto a_G5;}a_L1=a_P[0];
a_1154(a_L1);
a_G4:a_1623(); goto a_G1;
a_G5:a_1199(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1304(a_L2,a_L3,a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ goto a_G4;}
a_1162(a_L1);
a_1758(a_L1);
a_1583(a_L1); goto a_G4;
} /* fillerblock2 */
static void a_1603(void){ /* fillerrepeater */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_G1:if(!a_1164(1696719024)){ return;}
a_1154(1696719024);
if(!a_1168(a_P)){ goto a_G5;}a_L1=a_P[0];
a_1158(a_L1); goto a_G1;
a_G5:a_1199(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1304(a_L2,a_L3,a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ goto a_G1;}
a_1162(a_L1);
a_1758(a_L1);
a_1587(a_L1); goto a_G1;
} /* fillerrepeater */
static void a_1601(int a_F1){ /* fillerinitializer+>a */
int a_L2;int a_P[1];
a_G1:if(!a_1164(1696718885)){ return;}
a_1154(1696718885);
a_1200(a_P);a_L2=a_P[0];
a_1162(a_L2);
a_1753(a_L2,a_F1);
if(!a_1746(a_L2,1)){ goto a_G1;}
a_1758(a_F1); goto a_G1;
} /* fillerinitializer */
static void a_1593(void){ /* expression */
int a_L1;int a_P[1];
a_1154(1696718910);
a_1200(a_P);a_L1=a_P[0];
a_1162(a_L1);
a_1605();
a_1196(1696718991);
a_1154(1696718991); return;
} /* expression */
static void a_1605(void){ /* isexpression */

if(!a_1164(1696718964)){ goto a_G3;}
a_G2:a_1154(1696718964);
a_G3:a_1592();
if(!a_1164(1696718982)){ goto a_G6;}
a_1154(1696718982); goto a_G3;
a_G6:if(!a_1164(1696718856)){ goto a_G8;}
a_1154(1696718856); goto a_G3;
a_G8:if(!a_1164(1696719046)){ goto a_G10;}
a_1154(1696719046); goto a_G3;
a_G10:if(!a_1164(1696718988)){ goto a_G12;}
a_1154(1696718988); goto a_G3;
a_G12:if(a_1164(1696718964)){ goto a_G2;}
if(!a_1164(1696719024)){ goto a_G15;}
a_1154(1696719024); goto a_G3;
a_G15:if(!a_1164(1696718895)){ return;}
a_1154(1696718895); goto a_G3;
} /* isexpression */
static void a_1607(void){ /* limitlist */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_1199(a_P);a_L1=a_P[0];a_L2=a_P[1];
a_1304(a_L1,a_L2,a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ return;}
a_1162(a_L3);
a_1584(a_L3);
a_1758(a_L3); return;
} /* limitlist */
static void a_1592(void){ /* exprbase */
int a_L1;int a_L2;int a_L3;int a_P[2];
a_G1:if(!a_1164(1696718879)){ goto a_G3;}
a_1154(1696718879); goto a_G1;
a_G3:if(!a_1172(a_P)){ goto a_G5;}a_L2=a_P[0];
a_1154(a_L2); return;
a_G5:if(!a_1164(1696718957)){ goto a_G8;}
a_1154(1696718957);
a_G7:a_1607(); return;
a_G8:if(!a_1164(1696719035)){ goto a_G10;}
a_1154(1696719035); goto a_G7;
a_G10:if(!a_1164(1696718876)){ goto a_G12;}
a_1154(1696718876); goto a_G7;
a_G12:if(!a_1164(1696718979)){ goto a_G17;}
a_1154(1696718979);
a_1605();
a_1196(1696718882);
a_1154(1696718882); return;
a_G17:a_1199(a_P);a_L1=a_P[0];a_L2=a_P[1];
a_1304(a_L1,a_L2,a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ return;}
a_1162(a_L3);
a_1583(a_L3);
a_1758(a_L3); return;
} /* exprbase */
static void a_1595(void){ /* externaldeclarer */
int a_L1;int a_P[1];
a_1154(1696718920);
a_1200(a_P);a_L1=a_P[0];
a_1162(a_L1);
if(!a_1177(a_P)){ goto a_G6;}a_L1=a_P[0];
a_1161(a_L1);
a_G6:a_1196(1696718991);
a_1154(1696718991); return;
} /* externaldeclarer */
static void a_1591(void){ /* exportprototype */
int a_L1;int a_P[4];
a_1585(1,a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
if(a_1746(a_L1,32)){ return;}
if(!a_1746(a_L1,8)){ goto a_G6;}
a_P[0]=2130705641;a_P[1]=to_LIST(a_1718)->offset[a_L1-3];a_P[2]=a_L1;a_P[3]=to_LIST(a_1718)->offset[a_L1-5];a_1238(-1,4,a_P); return;
a_G6:if(a_1489(22021)){ goto a_G8;}
if(!a_was(a_1720,to_LIST(a_1718)->offset[a_L1-6])){ goto a_G10;}
a_G8:a_1758(a_L1);
a_1757(a_L1,4); return;
a_G10:a_P[0]=2130705617;a_P[1]=to_LIST(a_1718)->offset[a_L1-3];a_P[2]=a_L1;a_1238(-1,3,a_P); return;
} /* exportprototype */
static void a_1612(void){ /* prototype */
int a_P[1];
a_1585(0,a_P); return;
} /* prototype */
static int a_1624(int a_F1,int a_F2){ /* typemismatch+>a+>a */
int a_L3;int a_P[1];
a_1741(a_F2,a_P);a_L3=a_P[0];
if(!a_noteq(a_L3,a_F1)){ return 0;}
if(a_noteq(a_F1,16777226)){ return 1;}
if(!a_noteq(a_L3,16777257)){ return 0;} return 1;
} /* typemismatch */
static void a_1585(int a_F1,int a_A[1]){ /* checkprototype+>a+a> */
int a_L3;int a_L4;int a_L5;int a_P[5];
if(!a_1164(1696719013)){ goto a_G3;}
a_1616(a_P);a_A[0]=a_P[0]; return;
a_G3:a_1202(a_P);a_L3=a_P[0];
a_1199(a_P);a_L4=a_P[0];a_L5=a_P[1];
a_1304(a_L4,a_L5,a_P);a_A[0]=a_P[0];
if(!a_equal(a_A[0],0)){ goto a_G8;}
a_G7:a_1176(1696718991); return;
a_G8:if(!a_1624(a_L3,a_A[0])){ goto a_G11;}
a_P[0]=2130705573;a_P[1]=to_LIST(a_1718)->offset[a_A[0]-3];a_P[2]=a_A[0];a_P[3]=a_L3;a_P[4]=to_LIST(a_1718)->offset[a_A[0]-5];a_1238(-1,5,a_P);
a_A[0]=0; goto a_G7;
a_G11:if(!a_1606(a_A[0])){ goto a_G7;}
a_1613(a_F1,a_A[0]); goto a_G7;
} /* checkprototype */
static void a_1616(int a_A[1]){ /* ruleprototype+a> */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[5];
a_1197(a_P);a_L2=a_P[0];
a_1199(a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1200(a_P);a_L5=a_P[0];
a_1176(1696718991);
a_1304(a_L3,a_L4,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],0)){ return;}
a_1741(a_A[0],a_P);a_L6=a_P[0];
if(!a_noteq(a_L6,16777271)){ goto a_G11;}
a_P[0]=2130705573;a_P[1]=a_L6;a_P[2]=a_A[0];a_P[3]=16777271;a_P[4]=to_LIST(a_1718)->offset[a_A[0]-5];a_1238(-1,5,a_P);
a_G10:a_A[0]=0; return;
a_G11:a_1738(a_A[0],1792,a_P);a_L6=a_P[0];
if(!a_noteq(a_L6,a_L2)){ goto a_G14;}
a_P[0]=2130705593;a_P[1]=a_A[0];a_P[2]=to_LIST(a_1718)->offset[a_A[0]-5];a_1238(-1,3,a_P); goto a_G10;
a_G14:a_1729(a_A[0],a_P);a_L6=a_P[0];
if(!a_noteq(a_L6,a_L5)){ return;}
a_P[0]=2130705605;a_P[1]=a_A[0];a_P[2]=to_LIST(a_1718)->offset[a_A[0]-5];a_1238(-1,3,a_P); goto a_G10;
} /* ruleprototype */
static void a_1604(void){ /* importprototype */
int a_L1;int a_L2;int a_P[3];
a_1200(a_P);a_L1=a_P[0];
if(a_1489(22021)){ goto a_G7;}
if(a_was(a_1720,to_LIST(a_1718)->offset[a_L1-6])){ goto a_G7;}
a_1339(to_LIST(a_1718)->offset[a_L1-6],a_P);a_L2=a_P[0];
if(a_is(a_L2)){ goto a_G7;}
a_P[0]=2130705629;a_P[1]=to_LIST(a_1718)->offset[a_L1-3];a_P[2]=a_L1;a_1238(-1,3,a_P);
a_G7:if(a_1164(1696718991)){ return;}
if(!a_1606(a_L1)){ goto a_G11;}
a_1613(0,a_L1);
a_G10:a_1176(1696718991); return;
a_G11:a_1584(a_L1); goto a_G10;
} /* importprototype */
static void a_1620(void){ /* setsource */
int a_L1;int a_P[1];
a_1154(1696719021);
a_1197(a_P);a_L1=a_P[0];
a_1158(a_L1);
a_1364(a_L1); return;
} /* setsource */
static void a_1611(void){ /* pragmat */
int a_L1;int a_L2;int a_P[1];
a_1197(a_P);a_L1=a_P[0];
if(!a_equal(a_L1,22017)){ goto a_G8;}
a_1154(1696718996);
a_1158(22017);
a_1197(a_P);a_L1=a_P[0];
a_1158(a_L1);
a_1507(22018,a_L1); return;
a_G8:a_1201(a_P);a_L1=a_P[0];
a_1304(0,a_L1,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
a_1588(a_L2); return;
} /* pragmat */
static void a_1588(int a_F1){ /* checktagformacro+>a */
int a_L2;int a_L3;int a_P[4];
if(!a_1746(a_F1,2)){ goto a_G8;}
a_1730(a_F1,a_P);a_L3=a_P[0];
a_1741(a_F1,a_P);a_L2=a_P[0];
if(!a_noteq(a_L2,16777271)){ goto a_G6;}
a_G5:a_P[0]=2130705650;a_P[1]=a_L2;a_P[2]=a_F1;a_P[3]=a_L3;a_1240(3,-1,4,a_P); return;
a_G6:if(a_1746(a_F1,56)){ goto a_G5;}
a_1757(a_F1,128); return;
a_G8:a_P[0]=2130705659;a_P[1]=a_F1;a_1240(3,-1,2,a_P); return;
} /* checktagformacro */
static void a_1660(int a_F1){ /* warnnotused+>a */
int a_L2;int a_L3;int a_P[3];
a_1305(a_F1,a_P);a_L3=a_P[0];
if(a_more(a_L3,1)){ return;}
if(!a_equal(a_L3,0)){ goto a_G5;}
a_L3=3; goto a_G6;
a_G5:a_L3=1;
a_G6:a_1741(a_F1,a_P);a_L2=a_P[0];
a_P[0]=2130705696;a_P[1]=a_L2;a_P[2]=a_F1;a_1240(a_L3,-1,3,a_P); return;
} /* warnnotused */
static void a_1656(void){ /* thirdpass */

a_1627();
a_1628();
a_1635();
a_1655();
a_1651(); return;
} /* thirdpass */
static void a_1627(void){ /* ICEheader */
int a_L1;int a_L2;int a_L3;int a_L4;int a_L5;int a_P[4];
if(!a_1489(22021)){ goto a_G7;}
a_1087(1696718969);
a_1093();
a_1364(-1);
a_1343(a_P);a_L5=a_P[0];
a_1094(a_L5); goto a_G8;
a_G7:a_1087(1696718961);
a_G8:a_1481(22020,a_P);a_L1=a_P[0];
a_1093();
a_1094(a_L1);
a_1093();
a_1089(32);
a_1091();
a_L2=0;
a_G15:a_P[0]=a_L2;if(!a_1354(a_P)){ goto a_G20;}a_L2=a_P[0];a_L3=a_P[1];a_L4=a_P[2];a_L5=a_P[3];
a_1089(a_L3);
a_1089(a_L4);
a_1088(a_L5);
a_1091(); goto a_G15;
a_G20:a_1087(1696718991); return;
} /* ICEheader */
static void a_1628(void){ /* ICEitemlist */
int a_L1;int a_P[1];
a_1740(a_P);a_L1=a_P[0];
a_1659(a_L1);
a_1737(a_P);a_L1=a_P[0];
a_1658(a_L1);
a_1087(1696718991); return;
} /* ICEitemlist */
static void a_1661(int a_F1){ /* writeICEitem+>a */
int a_L2;int a_L3;int a_P[1];
a_1741(a_F1,a_P);a_L2=a_P[0];
a_1096(a_L2);
a_1095(a_F1);
a_1738(a_F1,117557020,a_P);a_L3=a_P[0];
a_1089(a_L3);
a_1730(a_F1,a_P);a_L3=a_P[0];
a_1089(a_L3);
{ if(a_L2==16777226||a_L2==16777231||a_L2==16777236||a_L2==16777257||a_L2==16777262||a_L2==16777267){ goto a_G12;}
 if(a_L2==16777240||a_L2==16777244||a_L2==16777250){ goto a_G9;}
 if(a_L2==16777271){ goto a_G10;}
  goto a_G11;}
a_G9:a_1647(a_F1); goto a_G12;
a_G10:a_1641(a_F1); goto a_G12;
a_G11:a_1248(a_1001,2130706203); return;
a_G12:a_1642(a_F1,a_P);a_L3=a_P[0];
if(!a_equal(a_L3,0)){ goto a_G15;}
a_1094(1696719075); goto a_G16;
a_G15:a_1094(a_L3);
a_G16:a_1093();
a_1739(a_F1,a_P);a_L3=a_P[0];
a_1094(a_L3);
a_1091(); return;
} /* writeICEitem */
static void a_1642(int a_F1,int a_A[1]){ /* getqualifier+>a+a> */
int a_P[1];
a_A[0]=to_LIST(a_1718)->offset[a_F1-6];
if(a_equal(a_A[0],0)){ return;}
if(a_was(a_1720,a_A[0])){ return;}
a_1339(a_A[0],a_P);a_A[0]=a_P[0]; return;
} /* getqualifier */
static void a_1647(int a_F1){ /* listdata+>a */
int a_L2;int a_P[1];
a_1677(a_F1,a_P);a_L2=a_P[0];
if(a_more(a_L2,0)){ goto a_G4;}
a_L2=1;
a_G4:a_1089(a_L2);
a_1680(a_F1,a_P);a_L2=a_P[0];
a_1089(a_L2); return;
} /* listdata */
static void a_1641(int a_F1){ /* formalaffixes+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
a_1731(a_F1,a_P);a_L2=a_P[0];
a_1089(a_L2);
a_L3=1;
a_G4:if(a_more(a_L3,a_L2)){ return;}
a_1733(a_F1,a_L3,a_P);a_L4=a_P[0];
a_1096(a_L4);
if(a_equal(a_L4,16777277)){ goto a_G9;}
if(!a_equal(a_L4,16777283)){ goto a_G14;}
a_G9:a_1732(a_F1,a_L3,a_P);a_L4=a_P[0];a_L5=a_P[1];
if(a_more(a_L4,0)){ goto a_G12;}
a_L4=1;
a_G12:a_1089(a_L4);
a_1089(a_L5);
a_G14:a_incr(a_L3); goto a_G4;
} /* formalaffixes */
static void a_1659(int a_F1){ /* traversetags+>a */
int a_L2;
a_G1:if(a_equal(a_F1,0)){ return;}
a_add(a_F1,5,a_L2);
a_1659(to_LIST(a_1720)->offset[a_L2-4]);
a_1629(to_LIST(a_1720)->offset[a_L2-2]);
a_F1=to_LIST(a_1720)->offset[a_L2-3]; goto a_G1;
} /* traversetags */
static void a_1629(int a_F1){ /* defineiceitems+>a */
int a_P[1];
a_G1:if(a_equal(a_F1,0)){ return;}
a_1643(a_F1);
a_1735(a_F1,a_P);a_F1=a_P[0]; goto a_G1;
} /* defineiceitems */
static int a_1646(int a_F1){ /* isitemtag+>a */
int a_L2;int a_P[1];
if(!a_1746(a_F1,2)){ return 0;}
if(!a_1746(a_F1,1)){ return 0;}
a_1741(a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,16777271)){ return 1;}
if(a_1746(a_F1,4)){ return 1;}
if(!a_1746(a_F1,128)){ return 1;} return 0;
} /* isitemtag */
static void a_1643(int a_F1){ /* handletag+>a */

if(!a_1646(a_F1)){ return;}
a_incr(a_1650);
a_1755(a_F1,a_1650);
a_1661(a_F1); return;
} /* handletag */
static void a_1658(int a_F1){ /* traversestdstringpointers+>a */
int a_P[1];
a_G1:if(a_equal(a_F1,0)){ return;}
a_incr(a_1650);
a_1755(a_F1,a_1650);
a_1661(a_F1);
a_1735(a_F1,a_P);a_F1=a_P[0]; goto a_G1;
} /* traversestdstringpointers */
static void a_1635(void){ /* fbmatter */
int a_L1;int a_L2;int a_L3;int a_P[3];
a_L1=0;
a_G2:a_P[0]=a_L1;if(!a_1734(a_P)){ return;}a_L1=a_P[0];a_L2=a_P[1];a_L3=a_P[2];
if(!a_equal(a_L2,1)){ goto a_G5;}
a_1087(1696718932); goto a_G6;
a_G5:a_1087(1696718864);
a_G6:a_1094(a_L3);
a_1087(1696718991); goto a_G2;
} /* fbmatter */
static void a_1655(void){ /* stringtablecontent */
int a_L1;int a_L2;int a_P[1];
a_1737(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;}
a_1087(1696718928);
a_1095(16777845);
a_1089(-2);
a_G6:if(!a_equal(a_L1,0)){ goto a_G8;}
a_1087(1696718991); return;
a_G8:a_1729(a_L1,a_P);a_L2=a_P[0];
a_1753(a_L1,16777845);
a_1090(a_L2);
a_1087(1696718885);
a_1095(a_L1);
a_1735(a_L1,a_P);a_L1=a_P[0]; goto a_G6;
} /* stringtablecontent */
static void a_1651(void){ /* pass3 */
int a_L1;int a_P[1];
a_G1:if(!a_1164(1696719013)){ goto a_G6;}
a_1200(a_P);a_L1=a_P[0];
if(a_1746(a_L1,1)){ goto a_G5;}
a_1660(a_L1);
a_G5:a_1018(a_L1); goto a_G1;
a_G6:if(!a_1164(1696719009)){ goto a_G8;}
a_1200(a_P);a_L1=a_P[0]; goto a_G5;
a_G8:if(!a_1164(1696718920)){ goto a_G10;}
a_1634(); goto a_G1;
a_G10:if(!a_1164(1696718996)){ goto a_G12;}
a_1652(); goto a_G1;
a_G12:if(!a_1164(1696719021)){ goto a_G14;}
a_1654(); goto a_G1;
a_G14:if(!a_1164(1696718910)){ goto a_G16;}
a_1632(); goto a_G1;
a_G16:if(!a_1164(1696718924)){ goto a_G18;}
a_1637(); goto a_G1;
a_G18:if(!a_1164(1696718949)){ goto a_G20;}
a_1648(); goto a_G1;
a_G20:if(!a_1164(1696718928)){ goto a_G22;}
a_1649(); goto a_G1;
a_G22:if(a_1164(1696718899)){ return;}
a_1248(a_1001,2130706197); return;
} /* pass3 */
static void a_1634(void){ /* externaldeclarer */
int a_L1;int a_L2;int a_P[1];
a_1200(a_P);a_L1=a_P[0];
if(!a_1746(a_L1,1)){ goto a_G10;}
a_1087(1696718920);
a_1095(a_L1);
if(a_1177(a_P)){a_L2=a_P[0]; goto a_G7;}
a_L2=0;
a_G7:a_1094(a_L2);
a_1087(1696718991);
a_G9:a_1176(1696718991); return;
a_G10:a_1660(a_L1); goto a_G9;
} /* externaldeclarer */
static void a_1652(void){ /* pragmat */
int a_L1;int a_P[1];
a_1197(a_P);
a_1197(a_P);a_L1=a_P[0];
a_1507(22018,a_L1); return;
} /* pragmat */
static void a_1654(void){ /* setsource */
int a_L1;int a_P[1];
a_1197(a_P);a_L1=a_P[0];
a_1364(a_L1); return;
} /* setsource */
static void a_1632(void){ /* expression */
int a_L1;int a_P[1];
a_1200(a_P);a_L1=a_P[0];
if(!a_1746(a_L1,1)){ goto a_G8;}
a_1087(1696718910);
a_1095(a_L1);
a_1645();
a_1196(1696718991);
a_1087(1696718991); return;
a_G8:a_1660(a_L1);
a_1176(1696718991); return;
} /* expression */
static void a_1645(void){ /* isexpression */

if(!a_1164(1696718964)){ goto a_G3;}
a_G2:a_1087(1696718964);
a_G3:a_1631();
if(!a_1164(1696718982)){ goto a_G6;}
a_1087(1696718982); goto a_G3;
a_G6:if(!a_1164(1696718856)){ goto a_G8;}
a_1087(1696718856); goto a_G3;
a_G8:if(!a_1164(1696719046)){ goto a_G10;}
a_1087(1696719046); goto a_G3;
a_G10:if(!a_1164(1696718988)){ goto a_G12;}
a_1087(1696718988); goto a_G3;
a_G12:if(a_1164(1696718964)){ goto a_G2;}
if(!a_1164(1696719024)){ goto a_G15;}
a_1087(1696719024); goto a_G3;
a_G15:if(!a_1164(1696718895)){ return;}
a_1087(1696718895); goto a_G3;
} /* isexpression */
static void a_1631(void){ /* exprbase */
int a_L1;int a_P[1];
a_G1:if(!a_1179(a_P)){ goto a_G3;}a_L1=a_P[0];
a_G2:a_1095(a_L1); return;
a_G3:if(!a_1172(a_P)){ goto a_G5;}a_L1=a_P[0];
a_1087(a_L1); return;
a_G5:if(!a_1164(1696718879)){ goto a_G7;}
a_1087(1696718879); goto a_G1;
a_G7:if(!a_1164(1696718957)){ goto a_G10;}
a_1087(1696718957);
a_G9:a_1200(a_P);a_L1=a_P[0]; goto a_G2;
a_G10:if(!a_1164(1696719035)){ goto a_G12;}
a_1087(1696719035); goto a_G9;
a_G12:if(!a_1164(1696718876)){ goto a_G14;}
a_1087(1696718876); goto a_G9;
a_G14:a_1196(1696718979);
a_1087(1696718979);
a_1645();
a_1196(1696718882);
a_1087(1696718882); return;
} /* exprbase */
static void a_1637(void){ /* filedata */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
a_1200(a_P);a_L1=a_P[0];
if(!a_1746(a_L1,1)){ goto a_G24;}
a_1087(1696718924);
a_1095(a_L1);
a_L3=to_LIST(a_1150)->aupb;
if(!a_1164(1696719027)){ goto a_G8;}
a_1636();
a_G8:a_1197(a_P);a_L2=a_P[0];
a_1089(a_L2);
a_1200(a_P);a_L2=a_P[0];
a_1095(a_L2);
a_1200(a_P);a_L2=a_P[0];
a_1095(a_L2);
if(a_equal(to_LIST(a_1150)->aupb,a_L3)){ goto a_G22;}
a_1087(1696719027);
a_L4=a_L3;
a_G17:if(!a_less(a_L4,to_LIST(a_1150)->aupb)){ goto a_G20;}
a_incr(a_L4);
a_1095(to_LIST(a_1150)->offset[a_L4]); goto a_G17;
a_G20:a_1087(1696718871);
a_unstackto(a_1150,a_L3);
a_G22:a_1196(1696718991);
a_1087(1696718991); return;
a_G24:a_1660(a_L1);
a_1176(1696718991); return;
} /* filedata */
static void a_1636(void){ /* filearea */
int a_L1;int a_P[1];
a_G1:if(a_1164(1696718871)){ return;}
a_1200(a_P);a_L1=a_P[0];
a_1633(a_L1); goto a_G1;
} /* filearea */
static void a_1648(void){ /* listdeclarer */
int a_L1;int a_L2;int a_P[1];
a_1200(a_P);a_L1=a_P[0];
if(!a_1746(a_L1,1)){ goto a_G14;}
a_1087(1696718949);
a_1095(a_L1);
a_1197(a_P);a_L2=a_P[0];
a_1089(a_L2);
if(!a_lseq(a_L2,2)){ goto a_G10;}
a_1197(a_P);a_L2=a_P[0];
a_1089(a_L2); goto a_G12;
a_G10:a_1200(a_P);a_L2=a_P[0];
a_1095(a_L2);
a_G12:a_1196(1696718991);
a_1087(1696718991); return;
a_G14:a_1660(a_L1);
a_1176(1696718991); return;
} /* listdeclarer */
static void a_1649(void){ /* listfilling */
int a_L1;int a_L2;int a_P[1];
a_1200(a_P);a_L1=a_P[0];
if(!a_1746(a_L1,1)){ goto a_G12;}
a_1087(1696718928);
a_1095(a_L1);
a_1690(a_P);a_L2=a_P[0];
a_1089(a_L2);
a_G7:if(!a_1164(1696718991)){ goto a_G9;}
a_1087(1696718991); return;
a_G9:a_1640(a_L1);
a_1653();
a_1644(); goto a_G7;
a_G12:a_1176(1696718991); return;
} /* listfilling */
static void a_1640(int a_F1){ /* filleritem+>a */
int a_L2;int a_P[1];
if(!a_1179(a_P)){ goto a_G3;}a_L2=a_P[0];
a_1095(a_L2); return;
a_G3:if(!a_1172(a_P)){ goto a_G5;}a_L2=a_P[0];
a_1087(a_L2); return;
a_G5:if(!a_1177(a_P)){ goto a_G8;}a_L2=a_P[0];
a_1090(a_L2);
a_1093(); return;
a_G8:if(!a_1164(1696718979)){ goto a_G12;}
a_1087(1696718979);
a_1638(a_F1);
a_G11:a_1087(1696718882); return;
a_G12:a_1196(1696718915);
a_1087(1696718979);
a_1639(a_F1); goto a_G11;
} /* filleritem */
static void a_1630(int a_F1){ /* emitfill+>a */

if(a_equal(a_F1,0)){ return;}
if(!a_was(a_1718,a_F1)){ goto a_G4;}
a_1095(a_F1); return;
a_G4:a_1087(a_F1); return;
} /* emitfill */
static void a_1638(int a_F1){ /* fillerblock1+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[4];
a_L2=to_LIST(a_1150)->aupb;
a_1677(a_F1,a_P);a_L4=a_P[0];
if(a_more(a_L4,0)){ goto a_G5;}
a_L4=1;
a_G5:a_L5=0;a_L6=0;a_L8=0;
a_G6:if(a_1164(1696718882)){ goto a_G13;}
if(!a_1164(1696719024)){ goto a_G9;}
a_L6=a_L5; goto a_G6;
a_G9:if(!a_1172(a_P)){ goto a_G12;}a_L7=a_P[0];
a_G10:a_1633(a_L7);
a_incr(a_L5); goto a_G6;
a_G12:a_1200(a_P);a_L7=a_P[0]; goto a_G10;
a_G13:if(a_equal(a_L5,a_L4)){ goto a_G19;}
if(!a_more(a_L5,a_L4)){ goto a_G16;}
a_P[0]=2130705712;a_P[1]=a_F1;a_P[2]=a_L5;a_P[3]=a_L4;a_1240(6,-1,4,a_P); goto a_G19;
a_G16:if(!a_more(a_L6,0)){ goto a_G18;}
a_subtr(a_L4,a_L5,a_L8); goto a_G19;
a_G18:a_P[0]=2130705728;a_P[1]=a_F1;a_P[2]=a_L5;a_P[3]=a_L4;a_1240(4,-1,4,a_P);
a_G19:a_L5=1;
a_L3=a_L2;
a_G21:a_incr(a_L3);
a_G22:if(a_more(a_L3,to_LIST(a_1150)->aupb)){ goto a_G28;}
a_1630(to_LIST(a_1150)->offset[a_L3]);
if(!a_equal(a_L5,a_L6)){ goto a_G27;}
if(!a_more(a_L8,0)){ goto a_G27;}
a_decr(a_L8); goto a_G22;
a_G27:a_incr(a_L5); goto a_G21;
a_G28:a_unstackto(a_1150,a_L2); return;
} /* fillerblock1 */
static void a_1657(int a_F1,int a_F3,int a_A[1]){ /* toselectors+>a+>a>+>a */
int a_L4;int a_L5;int a_L6;int a_P[3];
a_G1:if(!a_1164(1696719031)){ return;}
if(!a_1164(1696719024)){ goto a_G4;}
a_A[0]=a_F3; goto a_G1;
a_G4:a_1201(a_P);a_L4=a_P[0];
if(!a_1674(a_F1,a_L4,a_P)){ goto a_G11;}a_L5=a_P[0];
a_subtr(to_LIST(a_1150)->aupb,a_L5,a_L6);
a_incr(a_L6);
if(!a_equal(to_LIST(a_1150)->offset[a_L6],0)){ goto a_G10;}
to_LIST(a_1150)->offset[a_L6]=a_F3; goto a_G1;
a_G10:a_P[0]=2130705680;a_P[1]=a_F1;a_P[2]=a_L4;a_1238(-1,3,a_P); goto a_G1;
a_G11:a_P[0]=2130705670;a_P[1]=a_F1;a_P[2]=a_L4;a_1238(-1,3,a_P); goto a_G1;
} /* toselectors */
static void a_1639(int a_F1){ /* fillerblock2+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[4];
a_L2=to_LIST(a_1150)->aupb;
a_1677(a_F1,a_P);a_L4=a_P[0];
a_L5=0;
a_G4:a_1633(0);
a_incr(a_L5);
if(!a_equal(a_L5,a_L4)){ goto a_G4;}
a_1241(a_P);a_L8=a_P[0];
a_L6=0;
a_G9:if(a_1164(1696718915)){ goto a_G13;}
if(a_1172(a_P)){a_L5=a_P[0]; goto a_G12;}
a_1200(a_P);a_L5=a_P[0];
a_G12:a_P[0]=a_L6;a_1657(a_F1,a_L5,a_P);a_L6=a_P[0]; goto a_G9;
a_G13:a_L7=0;
a_L3=a_L2;
a_G15:a_incr(a_L3);
if(a_more(a_L3,to_LIST(a_1150)->aupb)){ goto a_G24;}
if(!a_equal(to_LIST(a_1150)->offset[a_L3],0)){ goto a_G21;}
if(!a_is(a_L6)){ goto a_G20;}
to_LIST(a_1150)->offset[a_L3]=a_L6; goto a_G15;
a_G20:a_incr(a_L7); goto a_G15;
a_G21:if(a_equal(a_L7,0)){ goto a_G15;}
if(a_1275(a_L8)){ goto a_G15;}
a_P[0]=2130705690;a_P[1]=a_F1;a_1238(-1,2,a_P); goto a_G15;
a_G24:if(a_equal(a_L7,0)){ goto a_G28;}
if(a_1275(a_L8)){ goto a_G28;}
a_subtr(a_L4,a_L7,a_L7);
a_P[0]=2130705728;a_P[1]=a_F1;a_P[2]=a_L7;a_P[3]=a_L4;a_1240(4,-1,4,a_P);
a_G28:a_L3=to_LIST(a_1150)->aupb;
a_G29:if(a_lseq(a_L3,a_L2)){ goto a_G32;}
a_1630(to_LIST(a_1150)->offset[a_L3]);
a_decr(a_L3); goto a_G29;
a_G32:a_unstackto(a_1150,a_L2); return;
} /* fillerblock2 */
static void a_1653(void){ /* repeater */
int a_L1;int a_P[1];
if(!a_1164(1696719024)){ return;}
a_1087(1696719024);
if(!a_1168(a_P)){ goto a_G5;}a_L1=a_P[0];
a_1089(a_L1); return;
a_G5:a_1200(a_P);a_L1=a_P[0];
a_1095(a_L1); return;
} /* repeater */
static void a_1644(void){ /* initializer */
int a_L1;int a_P[3];
a_G1:if(!a_1164(1696718885)){ return;}
a_1200(a_P);a_L1=a_P[0];
if(!a_1746(a_L1,1)){ goto a_G6;}
a_1087(1696718885);
a_1095(a_L1); goto a_G1;
a_G6:a_P[0]=2130705696;a_P[1]=16777257;a_P[2]=a_L1;a_1240(3,-1,3,a_P); goto a_G1;
} /* initializer */
static void a_1633(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1150,1);a_r1[0]=a_F1;to_LIST(a_1150)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1663(void){ /* fourthpass */

a_1210();
a_1664(); return;
} /* fourthpass */
static void a_1664(void){ /* pass4 */
int a_L1;int a_P[1];
a_G1:if(!a_1164(1696719013)){ goto a_G4;}
a_G2:a_1200(a_P);a_L1=a_P[0];
a_1827(a_L1); goto a_G1;
a_G4:if(a_1164(1696719009)){ goto a_G2;}
if(!a_1164(1696718996)){ goto a_G7;}
a_1665(); goto a_G1;
a_G7:if(!a_1164(1696719021)){ goto a_G9;}
a_1666(); goto a_G1;
a_G9:if(!a_1164(1696718910)){ goto a_G11;}
a_G10:a_1176(1696718991); goto a_G1;
a_G11:if(a_1164(1696718924)){ goto a_G10;}
if(a_1164(1696718920)){ goto a_G10;}
if(a_1164(1696718949)){ goto a_G10;}
if(a_1164(1696718928)){ goto a_G10;}
if(a_1164(1696718899)){ return;}
a_1248(a_1001,2130706207); return;
} /* pass4 */
static void a_1665(void){ /* pragmat */
int a_L1;int a_P[1];
a_1197(a_P);
a_1197(a_P);a_L1=a_P[0];
a_1507(22018,a_L1); return;
} /* pragmat */
static void a_1666(void){ /* setsource */
int a_L1;int a_P[1];
a_1197(a_P);a_L1=a_P[0];
a_1364(a_L1); return;
} /* setsource */
static void a_1681(void){ /* resettempselectorstack */

a_scratch(a_1668); return;
} /* resettempselectorstack */
static int a_1676(int a_F1,int a_F2,int a_A[1]){ /* findtempselector+>a+>a+a> */
int a_L4;
a_L4=to_LIST(a_1668)->aupb;
a_G2:if(a_less(a_L4,to_LIST(a_1668)->alwb)){ return 0;}
if(!a_noteq(to_LIST(a_1668)->offset[a_L4-1],a_F1)){ goto a_G5;}
a_G4:a_previous(a_1668,a_L4); goto a_G2;
a_G5:if(a_noteq(to_LIST(a_1668)->offset[a_L4-2],a_F2)){ goto a_G4;}
a_A[0]=to_LIST(a_1668)->offset[a_L4]; return 1;
} /* findtempselector */
static int a_1673(int a_F1,int a_F2,int a_F3){ /* entertempselector+>a+>a+>a */
int a_L4;int a_P[1];
if(!a_1676(a_F1,a_F2,a_P)){ goto a_G3;}a_L4=a_P[0];
if(!a_equal(a_L4,a_F3)){ return 0;} return 1;
a_G3:{register int *a_r1=a_extension(a_1668,3);a_r1[0]=a_F2;a_r1[1]=a_F1;a_r1[2]=a_F3;to_LIST(a_1668)->aupb+=3;}
  return 1;
} /* entertempselector */
static void a_1672(int a_F1,int a_F2){ /* dumptempselectors+>a+>a */
int a_L3;
a_1158(a_F1);
a_1158(a_F2);
a_L3=to_LIST(a_1668)->alwb;
a_G4:if(a_more(a_L3,to_LIST(a_1668)->aupb)){ return;}
a_1163(to_LIST(a_1668)->offset[a_L3-1]);
a_1158(to_LIST(a_1668)->offset[a_L3]);
a_next(a_1668,a_L3); goto a_G4;
} /* dumptempselectors */
static void a_1678(int a_F1,int a_A[1]){ /* getselectornext+>a+a> */

a_A[0]=to_LIST(a_1718)->offset[a_F1]; return;
} /* getselectornext */
static void a_1679(int a_F1,int a_A[1]){ /* getselectoroffs+>a+a> */

a_A[0]=to_LIST(a_1718)->offset[a_F1-2]; return;
} /* getselectoroffs */
static void a_1677(int a_F1,int a_A[1]){ /* getcalibre+>a+a> */

a_A[0]=to_LIST(a_1718)->offset[to_LIST(a_1718)->offset[a_F1-1]-3]; return;
} /* getcalibre */
static void a_1680(int a_F1,int a_A[1]){ /* getssel+>a+a> */

a_A[0]=to_LIST(a_1718)->offset[to_LIST(a_1718)->offset[a_F1-1]-2]; return;
} /* getssel */
static void a_1671(int a_F1,int a_F2,int a_F3,int a_A[1]){ /* createselectorblock+>a+>a+>a+a> */

{register int *a_r1=a_extension(a_1718,4);a_r1[0]=a_F3;a_r1[3]=0;a_r1[2]=a_F1;a_r1[1]=a_F2;to_LIST(a_1718)->aupb+=4;}
a_A[0]=to_LIST(a_1718)->aupb; return;
} /* createselectorblock */
static int a_1675(int a_F1,int a_F2,int a_A[1]){ /* findpermselector+>a+>a+a> */
int a_P[1];
a_G1:if(a_equal(a_F2,0)){ return 0;}
if(!a_equal(to_LIST(a_1718)->offset[a_F2-1],a_F1)){ goto a_G4;}
a_A[0]=a_F2; return 1;
a_G4:a_1678(a_F2,a_P);a_F2=a_P[0]; goto a_G1;
} /* findpermselector */
static void a_1670(int a_F1,int a_F2,int a_F3){ /* createlistextension+>a+>a+>a */
int a_L4;int a_P[1];
a_1671(0,a_F3,a_F2,a_P);a_L4=a_P[0];
a_1753(a_F1,a_L4); return;
} /* createlistextension */
static int a_1674(int a_F1,int a_F2,int a_A[1]){ /* findlistselector+>a+>a+a> */
int a_L4;int a_P[1];
a_1729(a_F1,a_P);a_L4=a_P[0];
if(!a_1675(a_F2,a_L4,a_P)){ return 0;}a_L4=a_P[0];
a_1679(a_L4,a_P);a_A[0]=a_P[0]; return 1;
} /* findlistselector */
static void a_1669(int a_F1,int a_F2,int a_F3,int a_F4){ /* addlistselector+>a+>a+>a+>a */
int a_L5;int a_L6;int a_L7;int a_P[5];
a_1729(a_F1,a_P);a_L5=a_P[0];
if(!a_1675(a_F2,a_L5,a_P)){ goto a_G6;}a_L6=a_P[0];
if(a_equal(to_LIST(a_1718)->offset[a_L6-2],a_F3)){ return;}
a_1741(a_F1,a_P);a_L7=a_P[0];
a_P[0]=2130705742;a_P[1]=a_L7;a_P[2]=a_F1;a_P[3]=a_F2;a_P[4]=to_LIST(a_1718)->offset[a_L6-3];a_1238(-1,5,a_P); return;
a_G6:a_1671(a_F2,a_F3,a_F4,a_P);a_L6=a_P[0];
to_LIST(a_1718)->offset[a_L6]=to_LIST(a_1718)->offset[a_L5];
to_LIST(a_1718)->offset[a_L5]=a_L6; return;
} /* addlistselector */
static void a_1691(void){ /* initrestore */

if(!a_is(a_1688)){ goto a_G3;}
a_1248(a_1001,2130706229); return;
a_G3:a_1705=a_1706;
a_1703=a_1692;
a_1704=a_1699;
a_1688=1; return;
} /* initrestore */
static void a_1700(void){ /* makerestore */
int a_P[2];
if(!a_equal(a_1688,0)){ goto a_G3;}
a_1248(a_1001,2130706224); return;
a_G3:if(!a_more(a_1708,500)){ goto a_G7;}
a_P[0]=2130705784;a_P[1]=500;a_1238(-1,2,a_P);
a_1184();
a_exit(3); return;
a_G7:a_1706=a_1705;
a_1692=a_1703;
a_1699=a_1704;
a_1688=0; return;
} /* makerestore */
static void a_1689(void){ /* forgetrestore */

a_1700();
a_G2:if(!a_1707()){ return;}
a_1711(); goto a_G2;
} /* forgetrestore */
static void a_1709(void){ /* savetorestore */
int a_P[1];
if(a_equal(a_1688,0)){ return;}
if(!a_noteq(a_1706,a_1693)){ goto a_G4;}
a_1248(a_1001,2130706219); return;
a_G4:a_incr(a_1708);
a_P[0]=a_1693;a_1687(a_P);a_1693=a_P[0];
a_1706=a_1693;
to_LIST(a_1683)->offset[a_1693]=a_1692; return;
} /* savetorestore */
static int a_1707(void){ /* readfromrestore */
int a_P[1];
if(a_equal(a_1693,a_1706)){ return 0;}
a_P[0]=a_1706;a_1687(a_P);a_1706=a_P[0];
a_1692=to_LIST(a_1683)->offset[a_1706];
if(a_is(a_1688)){ goto a_G6;}
a_decr(a_1708);
a_G6:if(a_mreq(a_1708,0)){ return 1;}
a_1248(a_1001,2130706213); return 1;
} /* readfromrestore */
static void a_1687(int a_A[1]){ /* countrestore+>a> */

if(!a_mreq(a_A[0],to_LIST(a_1683)->aupb)){ goto a_G3;}
a_A[0]=to_LIST(a_1683)->alwb; return;
a_G3:a_incr(a_A[0]); return;
} /* countrestore */
static void a_1711(void){ /* setsymbolposition */

if(!a_equal(a_1692,1164737809)){ return;}
a_incr(a_1699);
if(a_is(a_1688)){ return;}
a_1159(); return;
} /* setsymbolposition */
static void a_1702(void){ /* nextsymbol */
int a_P[1];
a_G1:if(a_1707()){ goto a_G4;}
a_1400(a_P);a_1692=a_P[0];
a_1709();
a_G4:a_1711();
if(!a_equal(a_1692,1164737809)){ return;} goto a_G1;
} /* nextsymbol */
static void a_1684(int a_F1){ /* Rskip+>a */

if(!a_equal(a_F1,a_1692)){ return;}
a_1702(); return;
} /* Rskip */
static void a_1701(int a_F1){ /* must+>a */
int a_P[2];
if(!a_equal(a_F1,a_1692)){ goto a_G3;}
a_1702(); return;
a_G3:a_P[0]=2130705750;a_P[1]=a_F1;a_1238(-1,2,a_P); return;
} /* must */
static int a_1696(int a_A[1]){ /* israwttag+a> */

if(!a_was(a_1720,a_1692)){ return 0;}
a_A[0]=a_1692;
a_1702(); return 1;
} /* israwttag */
static int a_1698(int a_A[1]){ /* isttag+a> */

if(!a_was(a_1720,a_1692)){ return 0;}
a_A[0]=a_1692;
if(!a_equal(a_1693,a_1706)){ goto a_G5;}
a_1219(a_1692,a_1699);
a_G5:a_1702(); return 1;
} /* isttag */
static int a_1695(int a_A[2]){ /* isqtag+a>+a> */
int a_L3;int a_P[1];
if(!a_was(a_1720,a_1692)){ return 0;}
a_A[1]=a_1692;
a_L3=a_1699;
a_1702();
if(!a_equal(1164737767,a_1692)){ goto a_G10;}
a_1702();
a_A[0]=a_A[1];
if(a_1698(a_P)){a_A[1]=a_P[0]; return 1;}
a_P[0]=2130705758;a_1238(-1,1,a_P); return 1;
a_G10:a_A[0]=0;
if(!a_equal(a_1693,a_1706)){ return 1;}
a_1219(a_A[1],a_L3); return 1;
} /* isqtag */
static int a_1694(int a_A[2]){ /* isnumber+a>+a> */
int a_P[1];
if(!a_was(a_1113,a_1692)){ return 0;}
a_A[0]=a_1692;
a_1125(a_1692,a_P);a_A[1]=a_P[0];
a_1702(); return 1;
} /* isnumber */
static int a_1686(void){ /* aheadnumber */

if(!a_was(a_1113,a_1692)){ return 0;} return 1;
} /* aheadnumber */
static int a_1697(int a_A[1]){ /* isstring+a> */

if(!a_was(a_1374,a_1692)){ return 0;}
a_A[0]=a_1692;
a_1702(); return 1;
} /* isstring */
static void a_1714(void){ /* skipsymbol */
int a_P[1];
a_G1:if(a_1707()){ goto a_G4;}
a_1414(a_P);a_1692=a_P[0];
a_1709();
a_G4:a_1711();
if(!a_equal(a_1692,1164737809)){ return;} goto a_G1;
} /* skipsymbol */
static void a_1713(void){ /* skipsilently */

a_G1:if(a_equal(1164737776,a_1692)){ return;}
if(a_equal(1164737648,a_1692)){ return;}
a_1714(); goto a_G1;
} /* skipsilently */
static void a_1712(void){ /* skipall */
int a_P[1];
if(a_equal(1164737776,a_1692)){ return;}
a_P[0]=2130705771;a_1250(1,a_P);
a_1713(); return;
} /* skipall */
static void a_1715(void){ /* skiptopoint */

a_1712();
a_1684(1164737776); return;
} /* skiptopoint */
static void a_1690(int a_A[1]){ /* getlinenum+a> */

a_A[0]=a_1699; return;
} /* getlinenum */
static void a_1710(int a_F1){ /* setlinenum+>a */

a_1699=a_F1; return;
} /* setlinenum */
static void a_1685(void){ /* advancelinenum */

a_incr(a_1699);
a_1159(); return;
} /* advancelinenum */
static void a_1716(void){ /* switchsource */

a_1154(1696719021);
a_1158(a_1699); return;
} /* switchsource */
static void a_1727(int a_F1,int a_A[1]){ /* entertag+>a+a> */
int a_L3;int a_P[1];
a_packstring(a_1150,a_F1,a_1720);
a_L3=604757249;
a_G3:a_add(a_L3,5,a_A[0]);
a_comparestring(a_1720,a_L3,a_1720,to_LIST(a_1720)->aupb,a_P);a_F1=a_P[0];
if(!a_equal(a_F1,0)){ goto a_G7;}
a_unstackstring(a_1720); return;
a_G7:if(!a_more(a_F1,0)){ goto a_G13;}
a_L3=to_LIST(a_1720)->offset[a_A[0]-4];
if(a_more(a_L3,0)){ goto a_G3;}
to_LIST(a_1720)->offset[a_A[0]-4]=to_LIST(a_1720)->aupb;
a_G11:{register int *a_r1=a_extension(a_1720,5);a_r1[3]=-1;a_r1[0]=a_r1[1]=a_r1[2]=a_r1[4]=0;to_LIST(a_1720)->aupb+=5;}
a_A[0]=to_LIST(a_1720)->aupb; return;
a_G13:a_L3=to_LIST(a_1720)->offset[a_A[0]-3];
if(a_more(a_L3,0)){ goto a_G3;}
to_LIST(a_1720)->offset[a_A[0]-3]=to_LIST(a_1720)->aupb; goto a_G11;
} /* entertag */
static void a_1740(int a_A[1]){ /* getttaghead+a> */

a_A[0]=604757249; return;
} /* getttaghead */
static void a_1724(int a_F1,int a_F2){ /* createlocalaffix+>a+>a */

{register int *a_r1=a_extension(a_1719,6);a_r1[3]=a_F1;a_r1[5]=a_F2;a_r1[0]=a_r1[1]=a_r1[2]=a_r1[4]=0;to_LIST(a_1719)->aupb+=6;}
  return;
} /* createlocalaffix */
static int a_1759(int a_F1){ /* wastagpointer+>a */

a_G1:if(!a_was(a_1720,a_F1)){ goto a_G4;}
a_previous(a_1720,a_F1);
a_copystring(a_1720,a_F1,a_1150); return 1;
a_G4:if(!a_was(a_1718,a_F1)){ goto a_G9;}
if(!a_1759(to_LIST(a_1718)->offset[a_F1-6])){ goto a_G8;}
a_1728(58);
a_1728(58);
a_G8:a_F1=to_LIST(a_1718)->offset[a_F1]; goto a_G1;
a_G9:if(!a_was(a_1719,a_F1)){ return 0;}
a_F1=to_LIST(a_1719)->offset[a_F1]; goto a_G1;
} /* wastagpointer */
static void a_1739(int a_F1,int a_A[1]){ /* getttag+>a+a> */

a_A[0]=to_LIST(a_1718)->offset[a_F1]; return;
} /* getttag */
static void a_1736(int a_F1,int a_A[1]){ /* getrepr+>a+a> */

a_A[0]=to_LIST(a_1718)->offset[a_F1-2]; return;
} /* getrepr */
static void a_1729(int a_F1,int a_A[1]){ /* getadm+>a+a> */

a_A[0]=to_LIST(a_1718)->offset[a_F1-1]; return;
} /* getadm */
static void a_1735(int a_F1,int a_A[1]){ /* getnexttag+>a+a> */

a_A[0]=to_LIST(a_1718)->offset[a_F1-7]; return;
} /* getnexttag */
static void a_1741(int a_F1,int a_A[1]){ /* gettype+>a+a> */

{ if(!((16777838<=a_F1 && a_F1<=562758381))){ goto a_G3;}
}
a_A[0]=to_LIST(a_1718)->offset[a_F1-3]; return;
a_G3:a_A[0]=to_LIST(a_1719)->offset[a_F1-2]; return;
} /* gettype */
static void a_1730(int a_F1,int a_A[1]){ /* getdefline+>a+a> */

a_A[0]=to_LIST(a_1718)->offset[a_F1-5]; return;
} /* getdefline */
static void a_1755(int a_F1,int a_F2){ /* putrepr+>a+>a */

to_LIST(a_1718)->offset[a_F1-2]=a_F2; return;
} /* putrepr */
static void a_1753(int a_F1,int a_F2){ /* putadm+>a+>a */

to_LIST(a_1718)->offset[a_F1-1]=a_F2; return;
} /* putadm */
static void a_1754(int a_F1,int a_F2){ /* putdefline+>a+>a */

to_LIST(a_1718)->offset[a_F1-5]=a_F2; return;
} /* putdefline */
static void a_1757(int a_F1,int a_F2){ /* settagflag+>a+>a */

a_boolor(to_LIST(a_1718)->offset[a_F1-4],a_F2,to_LIST(a_1718)->offset[a_F1-4]); return;
} /* settagflag */
static int a_1746(int a_F1,int a_F2){ /* istagflag+>a+>a */
int a_L3;
a_booland(to_LIST(a_1718)->offset[a_F1-4],a_F2,a_L3);
if(!a_noteq(a_L3,0)){ return 0;} return 1;
} /* istagflag */
static void a_1738(int a_F1,int a_F2,int a_A[1]){ /* gettagflag+>a+>a+a> */

a_booland(to_LIST(a_1718)->offset[a_F1-4],a_F2,a_A[0]); return;
} /* gettagflag */
static void a_1722(int a_F1,int a_F2){ /* cleartagflag+>a+>a */
int a_L3;
a_boolinvert(a_F2,a_L3);
a_booland(to_LIST(a_1718)->offset[a_F1-4],a_L3,to_LIST(a_1718)->offset[a_F1-4]); return;
} /* cleartagflag */
static void a_1758(int a_F1){ /* usetag+>a */

a_boolor(to_LIST(a_1718)->offset[a_F1-4],1,to_LIST(a_1718)->offset[a_F1-4]);
if(!a_equal(to_LIST(a_1718)->offset[a_F1-3],16777257)){ return;}
a_F1=to_LIST(a_1718)->offset[a_F1-1];
if(!a_was(a_1718,a_F1)){ return;}
a_boolor(to_LIST(a_1718)->offset[a_F1-4],1,to_LIST(a_1718)->offset[a_F1-4]); return;
} /* usetag */
static void a_1752(int a_F1){ /* pushAFFS+>a */

{register int *a_r1=a_extension(a_1718,1);a_r1[0]=a_F1;to_LIST(a_1718)->aupb+=1;}
  return;
} /* pushAFFS */
static int a_1723(int a_F1,int a_F2){ /* compareAFFS+>a+>a */
int a_L3;
if(!a_equal(to_LIST(a_1718)->offset[a_F1-2],to_LIST(a_1718)->offset[a_F2-2])){ return 0;}
if(!a_equal(to_LIST(a_1718)->offset[a_F1-1],to_LIST(a_1718)->offset[a_F2-1])){ return 0;}
a_L3=to_LIST(a_1718)->offset[a_F1-1];
a_G4:if(a_lseq(a_L3,0)){ return 1;}
a_incr(a_F1);
a_incr(a_F2);
if(!a_equal(to_LIST(a_1718)->offset[a_F1],to_LIST(a_1718)->offset[a_F2])){ return 0;}
a_decr(a_L3); goto a_G4;
} /* compareAFFS */
static void a_1743(int a_F2,int a_A[1]){ /* inserttoAFFS+>a>+>a */
int a_L3;
a_L3=16777872;
a_G2:if(!a_1723(a_L3,a_A[0])){ goto a_G5;}
a_A[0]=a_L3;
a_unstackto(a_1718,a_F2); return;
a_G5:if(!a_equal(to_LIST(a_1718)->offset[a_L3],0)){ goto a_G7;}
to_LIST(a_1718)->offset[a_L3]=a_A[0]; return;
a_G7:a_L3=to_LIST(a_1718)->offset[a_L3]; goto a_G2;
} /* inserttoAFFS */
static void a_1725(int a_A[1]){ /* enterformalaffixes+a> */
int a_L2;int a_L3;int a_P[1];
a_L2=to_LIST(a_1718)->aupb;
{register int *a_r1=a_extension(a_1718,3);a_r1[1]=a_r1[0]=a_r1[2]=0;to_LIST(a_1718)->aupb+=3;}
a_A[0]=to_LIST(a_1718)->aupb;
a_L3=to_LIST(a_1719)->alwb;
a_G5:if(a_more(a_L3,to_LIST(a_1719)->aupb)){ goto a_G10;}
{register int a_r1=to_LIST(a_1719)->offset[a_L3-2];
 if(a_r1==16777335||a_r1==16777331){ goto a_G9;}
}
a_1752(to_LIST(a_1719)->offset[a_L3-2]);
a_incr(to_LIST(a_1718)->offset[a_A[0]-2]);
a_G9:a_next(a_1719,a_L3); goto a_G5;
a_G10:a_L3=to_LIST(a_1719)->alwb;
a_G11:if(a_more(a_L3,to_LIST(a_1719)->aupb)){ goto a_G16;}
{register int a_r1=to_LIST(a_1719)->offset[a_L3-2];
 if(!(a_r1==16777283||a_r1==16777277)){ goto a_G15;}
}
a_1752(to_LIST(a_1719)->offset[a_L3-5]);
a_1752(to_LIST(a_1719)->offset[a_L3-4]);
a_G15:a_next(a_1719,a_L3); goto a_G11;
a_G16:a_subtr(to_LIST(a_1718)->aupb,a_A[0],to_LIST(a_1718)->offset[a_A[0]-1]);
a_P[0]=a_A[0];a_1743(a_L2,a_P);a_A[0]=a_P[0]; return;
} /* enterformalaffixes */
static void a_1731(int a_F1,int a_A[1]){ /* getformalaffixno+>a+a> */
int a_L3;int a_P[1];
a_1729(a_F1,a_P);a_L3=a_P[0];
a_A[0]=to_LIST(a_1718)->offset[a_L3-2]; return;
} /* getformalaffixno */
static void a_1733(int a_F1,int a_F2,int a_A[1]){ /* getformaltype+>a+>a+a> */
int a_L4;int a_P[1];
a_1729(a_F1,a_P);a_L4=a_P[0];
a_add(a_L4,a_F2,a_L4);
a_A[0]=to_LIST(a_1718)->offset[a_L4]; return;
} /* getformaltype */
static void a_1732(int a_F1,int a_F2,int a_A[2]){ /* getformallistext+>a+>a+a>+a> */
int a_L5;int a_L6;int a_P[1];
a_1729(a_F1,a_P);a_L5=a_P[0];
a_add(a_L5,to_LIST(a_1718)->offset[a_L5-2],a_L6);
a_G3:a_incr(a_L5);
if(a_equal(to_LIST(a_1718)->offset[a_L5],16777283)){ goto a_G6;}
if(!a_equal(to_LIST(a_1718)->offset[a_L5],16777277)){ goto a_G10;}
a_G6:a_decr(a_F2);
if(!a_more(a_F2,0)){ goto a_G11;}
a_incr(a_L6);
a_incr(a_L6); goto a_G3;
a_G10:a_decr(a_F2); goto a_G3;
a_G11:a_incr(a_L6);
a_A[0]=to_LIST(a_1718)->offset[a_L6];
a_incr(a_L6);
a_A[1]=to_LIST(a_1718)->offset[a_L6]; return;
} /* getformallistext */
static void a_1726(int a_F1){ /* enterpredefinedtag+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
if(a_equal(a_F1,604757249)){ return;}
if(a_equal(a_F1,604757371)){ return;}
a_L4=604757249;
a_G4:a_add(a_L4,5,a_L3);
a_comparestring(a_1720,a_L4,a_1720,a_F1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ goto a_G10;}
a_next(a_1720,a_F1);
a_P[0]=2130705797;a_P[1]=a_F1;a_1238(0,2,a_P);
a_1248(a_1001,2130706242); return;
a_G10:if(!a_more(a_L2,0)){ goto a_G14;}
a_L4=to_LIST(a_1720)->offset[a_L3-4];
if(a_more(a_L4,0)){ goto a_G4;}
to_LIST(a_1720)->offset[a_L3-4]=a_F1; return;
a_G14:a_L4=to_LIST(a_1720)->offset[a_L3-3];
if(a_more(a_L4,0)){ goto a_G4;}
to_LIST(a_1720)->offset[a_L3-3]=a_F1; return;
} /* enterpredefinedtag */
static void a_1742(void){ /* inittags */
int a_L1;int a_L2;int a_P[1];
a_L1=to_LIST(a_1720)->aupb;
a_G2:if(a_lseq(a_L1,to_LIST(a_1720)->alwb)){ goto a_G7;}
a_previous(a_1720,a_L1);
a_1726(a_L1);
a_stringwidth(a_1720,a_L1,a_L2);
a_subtr(a_L1,a_L2,a_L1); goto a_G2;
a_G7:to_LIST(a_1720)->offset[604757305-2]=16777845;
a_1757(16777845,32);
a_1670(16777845,-1,1);
to_LIST(a_1720)->offset[604757285-2]=16777853;
a_1757(16777853,291);
a_1338(-1,a_P);a_L2=a_P[0];
to_LIST(a_1718)->offset[16777853-6]=a_L2;
a_1753(16777853,16777872);
to_LIST(a_1720)->offset[604757265-2]=16777861;
a_1757(16777861,164394);
a_1753(16777861,16777875);
to_LIST(a_1720)->offset[604757276-2]=16777869;
a_1757(16777869,163882);
a_1753(16777869,16777879); return;
} /* inittags */
static int a_1745(int a_F1,int a_A[1]){ /* isstdstringstored+>a+a> */
int a_L3;int a_P[1];
a_1737(a_P);a_A[0]=a_P[0];
a_G2:if(a_equal(a_A[0],0)){ return 0;}
a_comparestring(a_1374,a_F1,a_1374,to_LIST(a_1718)->offset[a_A[0]-1],a_P);a_L3=a_P[0];
if(a_equal(a_L3,0)){ return 1;}
a_1735(a_A[0],a_P);a_A[0]=a_P[0]; goto a_G2;
} /* isstdstringstored */
static void a_1750(int a_F1,int a_F2,int a_A[1]){ /* newstdstring+>a+>a+a> */
int a_P[1];
if(!a_1745(a_F1,a_P)){ goto a_G3;}a_A[0]=a_P[0];
a_1387(a_F1); return;
a_G3:a_1300(0,604757376,16777257,a_F2,a_P);a_A[0]=a_P[0];
a_1753(a_A[0],a_F1);
a_1757(a_A[0],2);
a_1757(a_A[0],1);
a_1757(16777845,4139); return;
} /* newstdstring */
static void a_1737(int a_A[1]){ /* getstdstringhead+a> */

a_A[0]=to_LIST(a_1720)->offset[604757376-2]; return;
} /* getstdstringhead */
static void a_1721(int a_F1,int a_F2){ /* addpragmatmatter+>a+>a */

{register int *a_r1=a_extension(a_1718,3);a_r1[1]=a_F1;a_r1[0]=a_F2;a_r1[2]=a_1749;to_LIST(a_1718)->aupb+=3;}
a_1749=to_LIST(a_1718)->aupb; return;
} /* addpragmatmatter */
static int a_1734(int a_A[3]){ /* getnextmatter+>a>+a>+a> */

if(!a_equal(a_A[0],0)){ goto a_G3;}
a_A[0]=a_1749; goto a_G4;
a_G3:a_A[0]=to_LIST(a_1718)->offset[a_A[0]];
a_G4:if(!a_noteq(a_A[0],0)){ return 0;}
a_A[1]=to_LIST(a_1718)->offset[a_A[0]-1];
a_A[2]=to_LIST(a_1718)->offset[a_A[0]-2]; return 1;
} /* getnextmatter */
static int a_1744(int a_F1,int a_A[1]){ /* isspecialrule+>a+a> */

if(!a_equal(a_F1,1164737722)){ goto a_G3;}
a_A[0]=604757314; return 1;
a_G3:if(!a_equal(a_F1,1164737725)){ goto a_G5;}
a_A[0]=604757332; return 1;
a_G5:if(!a_equal(a_F1,1164737731)){ goto a_G7;}
a_A[0]=604757350; return 1;
a_G7:if(!a_equal(a_F1,1164737728)){ goto a_G9;}
a_A[0]=604757359; return 1;
a_G9:if(!a_equal(a_F1,1164737785)){ goto a_G11;}
a_A[0]=604757341; return 1;
a_G11:if(!a_equal(a_F1,1164737794)){ goto a_G13;}
a_A[0]=604757368; return 1;
a_G13:if(!a_equal(a_F1,1164737791)){ return 0;}
a_A[0]=604757323; return 1;
} /* isspecialrule */
static void a_1747(int a_F1,int a_F2,int a_F3){ /* linkmacrorule+>a+>a+>a */

{register int *a_r1=a_extension(a_1718,4);a_r1[1]=a_F3;a_r1[0]=a_F2;a_r1[3]=a_F1;a_r1[2]=a_1748;to_LIST(a_1718)->aupb+=4;}
a_1748=to_LIST(a_1718)->aupb; return;
} /* linkmacrorule */
static void a_1756(int a_F1,int a_A[2]){ /* searchmacrorule+>a+a>+a> */
int a_L4;int a_P[1];
a_L4=a_1748;
a_G2:if(!a_equal(a_L4,0)){ goto a_G4;}
a_1248(a_1001,2130706235); return;
a_G4:if(!a_equal(to_LIST(a_1718)->offset[a_L4],a_F1)){ goto a_G7;}
a_A[0]=to_LIST(a_1718)->offset[a_L4-3];
a_A[1]=to_LIST(a_1718)->offset[a_L4-2]; return;
a_G7:a_1729(a_L4,a_P);a_L4=a_P[0]; goto a_G2;
} /* searchmacrorule */
static int a_1751(int a_A[1]){ /* nextmacrorule+>a> */
int a_L2;int a_P[1];
a_L2=a_1748;
if(a_equal(a_A[0],0)){ goto a_G7;}
a_G3:if(a_equal(a_L2,0)){ goto a_G7;}
if(!a_equal(to_LIST(a_1718)->offset[a_L2],a_A[0])){ goto a_G6;}
a_1729(a_L2,a_P);a_L2=a_P[0]; goto a_G7;
a_G6:a_1729(a_L2,a_P);a_L2=a_P[0]; goto a_G3;
a_G7:if(!a_is(a_L2)){ return 0;}
a_A[0]=to_LIST(a_1718)->offset[a_L2]; return 1;
} /* nextmacrorule */
static void a_1717(void){ /* @root */

a_1742(); return;
} /* @root */
static void a_1728(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1150,1);a_r1[0]=a_F1;to_LIST(a_1150)->aupb+=1;}
  return;
} /* extendBUFFER */
static int a_1762(int a_F1){ /* wastypepointer+>a */

if(!a_was(a_1761,a_F1)){ return 0;}
a_copystring(a_1761,a_F1,a_1150); return 1;
} /* wastypepointer */
static int a_1772(int a_A[1]){ /* isexpression+>a> */
int a_P[1];
if(!a_equal(1164737779,a_1692)){ goto a_G4;}
a_G2:a_1702();
a_1154(1696718964);
a_G4:a_P[0]=a_A[0];if(!a_1770(a_P)){ return 0;}a_A[0]=a_P[0];
if(a_is(a_A[0])){ return 1;}
if(!a_equal(1164737800,a_1692)){ goto a_G9;}
a_1702();
a_1154(1696718982); goto a_G4;
a_G9:if(!a_equal(1164737803,a_1692)){ goto a_G12;}
a_1702();
a_1154(1696718856); goto a_G4;
a_G12:if(!a_equal(1164737806,a_1692)){ goto a_G15;}
a_1702();
a_1154(1696719046); goto a_G4;
a_G15:if(!a_equal(1164737782,a_1692)){ goto a_G18;}
a_1702();
a_G17:a_1154(1696718988); goto a_G4;
a_G18:if(a_equal(1164737779,a_1692)){ goto a_G2;}
if(a_1686()){ goto a_G17;}
if(!a_equal(1164737755,a_1692)){ goto a_G23;}
a_1702();
a_1154(1696719024); goto a_G4;
a_G23:if(!a_equal(1164737788,a_1692)){ return 1;}
a_1702();
a_1154(1696718895); goto a_G4;
} /* isexpression */
static void a_1769(int a_A[1]){ /* expectlisttag+>a> */
int a_L2;int a_L3;int a_P[3];
if(!a_1695(a_P)){ goto a_G3;}a_L2=a_P[0];a_L3=a_P[1];
a_1160(a_L2,a_L3); return;
a_G3:a_A[0]=1;
a_P[0]=2130705808;a_P[1]=a_1775;a_P[2]=a_1774;a_1238(-1,3,a_P); return;
} /* expectlisttag */
static int a_1770(int a_A[1]){ /* exprbase+>a> */
int a_L2;int a_L3;int a_P[3];
if(!a_1694(a_P)){ goto a_G3;}a_L3=a_P[0];
a_1154(a_L3); return 1;
a_G3:if(!a_1695(a_P)){ goto a_G5;}a_L2=a_P[0];a_L3=a_P[1];
a_1160(a_L2,a_L3); return 1;
a_G5:if(!a_equal(1164737797,a_1692)){ goto a_G12;}
a_1702();
a_1154(1696718879);
a_P[0]=a_A[0];if(a_1770(a_P)){a_A[0]=a_P[0]; return 1;}
if(a_is(a_A[0])){ return 1;}
a_A[0]=1;
a_P[0]=2130705817;a_P[1]=a_1775;a_P[2]=a_1774;a_1238(-1,3,a_P); return 1;
a_G12:if(!a_equal(1164737728,a_1692)){ goto a_G16;}
a_1702();
a_G14:a_1154(1696718957);
a_G15:a_P[0]=a_A[0];a_1769(a_P);a_A[0]=a_P[0]; return 1;
a_G16:if(!a_equal(1164737731,a_1692)){ goto a_G19;}
a_1702();
a_G18:a_1154(1696719035); goto a_G15;
a_G19:if(!a_equal(1164737734,a_1692)){ goto a_G22;}
a_1702();
a_P[0]=2130705858;a_P[1]=a_1775;a_P[2]=a_1774;a_1240(1,-1,3,a_P); goto a_G14;
a_G22:if(!a_equal(1164737737,a_1692)){ goto a_G25;}
a_1702();
a_P[0]=2130705858;a_P[1]=a_1775;a_P[2]=a_1774;a_1240(1,-1,3,a_P); goto a_G18;
a_G25:if(!a_equal(1164737752,a_1692)){ goto a_G28;}
a_1702();
a_1154(1696718876); goto a_G15;
a_G28:if(!a_equal(1164737758,a_1692)){ return 0;}
a_1702();
a_1154(1696718979);
a_P[0]=a_A[0];if(a_1772(a_P)){a_A[0]=a_P[0]; goto a_G35;}
if(a_is(a_A[0])){ goto a_G35;}
a_A[0]=1;
a_P[0]=2130705817;a_P[1]=a_1775;a_P[2]=a_1774;a_1238(-1,3,a_P);
a_G35:a_1154(1696718882);
a_1701(1164737761); return 1;
} /* exprbase */
static void a_1768(void){ /* expectexpression */
int a_L1;int a_P[3];
a_L1=0;
a_P[0]=a_L1;if(a_1772(a_P)){a_L1=a_P[0]; goto a_G5;}
a_L1=1;
a_P[0]=2130705817;a_P[1]=a_1775;a_P[2]=a_1774;a_1238(-1,3,a_P);
a_G5:if(!a_is(a_L1)){ return;}
a_1712(); return;
} /* expectexpression */
static void a_1767(int a_F1){ /* declarer+>a */
int a_L2;int a_P[1];
a_1300(a_1773,a_1774,a_1775,a_F1,a_P);a_L2=a_P[0];
a_1757(a_L2,2);
a_P[0]=a_L2;a_1299(a_P);a_L2=a_P[0];
a_1154(1696718910);
a_1162(a_L2);
a_1768();
a_1154(1696718991); return;
} /* declarer */
static void a_1771(int a_F1){ /* externaldeclarer+>a */
int a_L2;int a_L3;int a_P[3];
a_1300(a_1773,a_1774,a_1775,a_F1,a_P);a_L2=a_P[0];
a_1757(a_L2,2);
a_1757(a_L2,16);
a_P[0]=a_L2;a_1299(a_P);a_L2=a_P[0];
if(a_1697(a_P)){a_L3=a_P[0]; goto a_G8;}
a_L3=0;
a_P[0]=2130705834;a_P[1]=a_1775;a_P[2]=a_1774;a_1238(-1,3,a_P);
a_G8:a_1154(1696718920);
a_1162(a_L2);
a_1161(a_L3);
a_1154(1696718991); return;
} /* externaldeclarer */
static void a_1776(int a_F1){ /* prototype+>a */
int a_L2;int a_L3;int a_P[1];
a_1481(22019,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,1)){ goto a_G10;}
a_1300(a_1773,a_1774,a_1775,a_F1,a_P);a_L3=a_P[0];
a_1757(a_L3,2);
a_1757(a_L3,8);
a_P[0]=a_L3;a_1299(a_P);a_L3=a_P[0];
a_1154(1696718937);
a_1162(a_L3);
a_G9:a_1154(1696718991); return;
a_G10:if(!a_equal(a_L2,2)){ goto a_G12;}
a_1154(1696718904); goto a_G13;
a_G12:a_1154(1696719000);
a_G13:a_1154(a_1775);
a_1160(a_1773,a_1774); goto a_G9;
} /* prototype */
static void a_1765(int a_A[1]){ /* declaration+>a> */
int a_L2;int a_P[2];
if(!a_1695(a_P)){ goto a_G17;}a_1773=a_P[0];a_1774=a_P[1];
a_1690(a_P);a_L2=a_P[0];
if(!a_equal(1164737725,a_1692)){ goto a_G12;}
a_1702();
if(!a_equal(a_A[0],3)){ goto a_G8;}
a_G6:a_P[0]=2130705845;a_P[1]=a_1775;a_1238(-1,2,a_P);
a_G7:a_1712(); return;
a_G8:if(!a_equal(a_A[0],1)){ goto a_G10;}
a_G9:a_1771(a_L2); return;
a_G10:a_A[0]=2;
a_1767(a_L2); return;
a_G12:if(!a_equal(a_A[0],1)){ goto a_G14;}
a_1701(1164737725); goto a_G9;
a_G14:if(a_equal(a_A[0],2)){ goto a_G6;}
a_A[0]=3;
a_1776(a_L2); return;
a_G17:a_P[0]=2130705824;a_P[1]=a_1775;a_1238(-1,2,a_P); goto a_G7;
} /* declaration */
static void a_1766(int a_F1){ /* declarationseries+>a */
int a_P[1];
a_G1:a_P[0]=a_F1;a_1765(a_P);a_F1=a_P[0];
if(!a_equal(1164737770,a_1692)){ goto a_G4;}
a_1702(); goto a_G1;
a_G4:if(!a_equal(1164737776,a_1692)){ goto a_G6;}
a_1702(); return;
a_G6:a_1701(1164737776);
a_1715(); return;
} /* declarationseries */
static void a_1764(int a_F1){ /* constantdeclaration+>a */

a_1775=16777226;
a_1766(a_F1); return;
} /* constantdeclaration */
static void a_1778(int a_F1){ /* variabledeclaration+>a */

a_1775=16777231;
a_1766(a_F1); return;
} /* variabledeclaration */
static void a_1777(void){ /* staticvariabledeclaration */

a_1775=16777236;
a_1766(0); return;
} /* staticvariabledeclaration */
static void a_1847(int a_F1,int a_F2){ /* pushRULE+>a+>a */

a_next(a_1151,a_1796);
if(!a_equal(a_1803,3)){ return;}
a_1819(a_F1,a_F2); return;
} /* pushRULE */
static void a_1854(int a_F1){ /* setupformalstack+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[2];
a_scratch(a_1719);
a_1731(a_F1,a_P);a_L3=a_P[0];
a_L4=1;
a_G4:if(a_more(a_L4,a_L3)){ return;}
a_1733(a_F1,a_L4,a_P);a_L2=a_P[0];
a_1201(a_P);a_L5=a_P[0];
a_1724(a_L2,a_L5);
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-1]=-1;
if(a_equal(a_L2,16777277)){ goto a_G11;}
if(!a_equal(a_L2,16777283)){ goto a_G14;}
a_G11:a_1732(a_F1,a_L4,a_P);a_L5=a_P[0];a_L6=a_P[1];
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-5]=a_L5;
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-4]=a_L6;
a_G14:a_incr(a_L4); goto a_G4;
} /* setupformalstack */
static void a_1855(int a_A[1]){ /* setuplabel+a> */
int a_P[1];
if(!a_1164(1696718945)){ goto a_G5;}
a_1201(a_P);a_A[0]=a_P[0];
a_1724(16777335,a_A[0]);
a_A[0]=to_LIST(a_1719)->aupb; return;
a_G5:a_A[0]=0; return;
} /* setuplabel */
static void a_1856(void){ /* setuplocals */
int a_L1;int a_P[1];
if(!a_1164(1696718953)){ return;}
a_G2:if(a_1164(1696718885)){ return;}
a_1201(a_P);a_L1=a_P[0];
a_1724(16777331,a_L1);
to_LIST(a_1719)->offset[to_LIST(a_1719)->aupb-1]=-1; goto a_G2;
} /* setuplocals */
static void a_1857(int a_F1,int a_A[1]){ /* startrange+>a+a> */
int a_L3;int a_L4;
a_1847(1048577,0);
a_A[0]=a_1796;
if(!a_is(a_F1)){ goto a_G5;}
to_LIST(a_1719)->offset[a_F1-1]=a_A[0];
a_G5:a_L3=to_LIST(a_1719)->alwb;
a_L4=0;
a_G7:if(a_more(a_L3,to_LIST(a_1719)->aupb)){ return;}
{register int a_r1=to_LIST(a_1719)->offset[a_L3-2];
 if(!(a_r1==16777293||a_r1==16777298||a_r1==16777304||a_r1==16777331)){ goto a_G19;}
}
a_incr(a_L4);
a_1847(0,a_L3);
if(!a_less(to_LIST(a_1719)->offset[a_L3-1],0)){ goto a_G19;}
to_LIST(a_1719)->offset[a_L3-1]=a_L4;
if(a_noteq(a_1803,3)){ goto a_G18;}
if(a_noteq(to_LIST(a_1719)->offset[a_L3-2],16777331)){ goto a_G18;}
if(!a_equal(a_1843,0)){ goto a_G17;}
a_1843=a_L4;
a_G17:a_max(a_L4,a_1840);
a_G18:a_1813(a_A[0],a_L4,a_L3);
a_G19:a_next(a_1719,a_L3); goto a_G7;
} /* startrange */
static void a_1806(int a_F1){ /* closerange+>a */

a_1847(1048578,a_F1); return;
} /* closerange */
static void a_1859(int a_F1,int a_A[1]){ /* utypetoslice+>a+a> */

a_boolor(a_F1,16,a_A[0]); return;
} /* utypetoslice */
static int a_1839(int a_F1){ /* inutype+>a */
int a_L2;
a_booland(a_F1,1,a_L2);
if(!a_noteq(a_L2,0)){ return 0;} return 1;
} /* inutype */
static int a_1845(int a_F1){ /* oututype+>a */
int a_L2;
a_booland(a_F1,2,a_L2);
if(!a_noteq(a_L2,0)){ return 0;} return 1;
} /* oututype */
static void a_1817(int a_F1){ /* expandmacro+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_P[2];
a_L2=to_LIST(a_1719)->aupb;
a_1193(a_F1,a_P);a_L3=a_P[0];a_L4=a_P[1];
a_1211(a_P);a_L5=a_P[0];a_L6=a_P[1];
a_1756(a_F1,a_P);a_L7=a_P[0];a_L8=a_P[1];
a_1209(a_L7,a_L8);
if(!a_equal(a_1803,2)){ goto a_G8;}
a_1879(); goto a_G9;
a_G8:a_1836();
a_G9:a_1196(1696718991);
a_1209(a_L5,a_L6);
a_1194(a_L3,a_L4);
a_unstackto(a_1719,a_L2); return;
} /* expandmacro */
static void a_1846(int a_C,int *a_V){ /* pushBUFFER+@+>a */

a_G1:a_1818(a_V[0]);
if(a_C>1){a_C--;a_V+=1; goto a_G1;}  return;
} /* pushBUFFER */
static void a_1811(int a_F1,int a_A[1]){ /* correctselector+>a+>a> */
int a_L3;int a_P[1];
if(!a_was(a_1718,a_F1)){ goto a_G3;}
a_1677(a_F1,a_P);a_L3=a_P[0]; goto a_G4;
a_G3:a_L3=to_LIST(a_1719)->offset[a_F1-5];
a_G4:if(a_more(a_L3,0)){ goto a_G6;}
a_L3=1;
a_G6:a_subtr(a_L3,a_A[0],a_A[0]);
a_incr(a_A[0]); return;
} /* correctselector */
static void a_1838(void){ /* gtransportlist */
int a_P[1];
a_G1:a_1837(2311425,a_P);
a_G2:if(!a_1164(1696719031)){ goto a_G5;}
if(a_1168(a_P)){ goto a_G2;}
a_1201(a_P); goto a_G2;
a_G5:if(a_1164(1696718892)){ goto a_G1;}
a_1196(1696718915); return;
} /* gtransportlist */
static void a_1828(void){ /* gextension */
int a_P[1];
a_1200(a_P);
a_1847(1048580,0);
a_1838();
a_1847(1048581,0); return;
} /* gextension */
static void a_1835(void){ /* greadbox */
int a_P[1];
a_1847(1048580,0);
a_1837(2311425,a_P);
a_1847(1048581,0);
a_1847(1048587,0);
a_1196(1696718868); return;
} /* greadbox */
static void a_1824(int a_A[1]){ /* garea+a> */
int a_L2;int a_P[2];
if(!a_noteq(a_1803,3)){ goto a_G4;}
a_1176(1696718860);
a_A[0]=0; return;
a_G4:a_A[0]=to_LIST(a_1150)->aupb;
a_1690(a_P);a_L2=a_P[0];
a_P[0]=1696718889;a_P[1]=a_L2;a_1846(2,a_P);
a_G7:if(!a_1164(1696718860)){ goto a_G9;}
a_1818(1696718988); return;
a_G9:if(!a_1164(1696718885)){ goto a_G11;}
a_1818(1696718885); goto a_G7;
a_G11:if(!a_1164(1696719016)){ goto a_G13;}
a_1818(1696719016); goto a_G7;
a_G13:if(!a_1172(a_P)){ goto a_G15;}a_L2=a_P[0];
a_G14:a_1818(a_L2); goto a_G7;
a_G15:a_1200(a_P);a_L2=a_P[0]; goto a_G14;
} /* garea */
static void a_1825(void){ /* gclassification */
int a_L1;int a_L2;int a_P[1];
a_G1:a_1196(1696718860);
a_1824(a_P);a_L2=a_P[0];
a_1847(1048580,a_L2);
a_1847(1048582,0);
a_L1=a_1796;
a_1847(1048581,0);
a_1847(1048579,0);
a_1823();
if(!a_1164(1696719016)){ goto a_G11;}
a_1847(1048591,0); goto a_G1;
a_G11:to_LIST(a_1151)->offset[a_L1-1]=1048576; return;
} /* gclassification */
static void a_1829(int a_F1,int a_F2){ /* ghandleaffix+>a+>a */

if(!a_1839(a_F2)){ goto a_G3;}
a_1847(1048593,to_LIST(a_1719)->offset[a_F1-1]);
a_G3:if(!a_1845(a_F2)){ return;}
a_1818(a_F2);
if(!a_mreq(a_F2,2311441)){ goto a_G7;}
a_1818(1048593); goto a_G8;
a_G7:a_1818(1048594);
a_G8:a_1818(a_F1); return;
} /* ghandleaffix */
static void a_1831(int a_F1,int a_F2,int a_F3,int a_F4){ /* ghandlevarargblock+>a+>a+>a+>a */
int a_L5;int a_P[1];
a_G1:a_next(a_1719,a_F1);
a_1733(a_F2,a_F4,a_P);a_L5=a_P[0];
a_incr(a_F4);
{ if(a_L5==16777293){ goto a_G5;}
 if(a_L5==16777298){ goto a_G6;}
 if(a_L5==16777304){ goto a_G7;}
  goto a_G8;}
a_G5:a_1829(a_F1,2311425); goto a_G8;
a_G6:a_1829(a_F1,2311426); goto a_G8;
a_G7:a_1829(a_F1,2311427);
a_G8:if(a_more(a_F4,a_F3)){ return;} goto a_G1;
} /* ghandlevarargblock */
static void a_1830(int a_F1){ /* ghandleshiftrule+>a */

a_G1:a_next(a_1719,a_F1);
{register int a_r1=to_LIST(a_1719)->offset[a_F1-2];
 if(a_r1==16777335){ return;}
 if(a_r1==16777293){ goto a_G3;}
 if(a_r1==16777298){ goto a_G4;}
 if(a_r1==16777304){ goto a_G5;}
  goto a_G1;}
a_G3:a_1829(a_F1,2311425); goto a_G1;
a_G4:a_1829(a_F1,2311426); goto a_G1;
a_G5:a_1829(a_F1,2311427); goto a_G1;
} /* ghandleshiftrule */
static int a_1832(void){ /* glimit */

if(a_1164(1696719039)){ return 1;}
if(a_1164(1696719043)){ return 1;}
if(a_1164(1696718957)){ return 1;}
if(a_1164(1696719035)){ return 1;}
if(!a_1164(1696718876)){ return 0;} return 1;
} /* glimit */
static void a_1837(int a_F1,int a_A[1]){ /* gsimpleaffix+>a+a> */
int a_L3;int a_L4;int a_P[1];
a_A[0]=0;
if(a_1172(a_P)){ return;}
if(!a_1832()){ goto a_G5;}
a_1200(a_P); return;
a_G5:if(!a_1164(1696719027)){ goto a_G12;}
a_1200(a_P);
a_1859(a_F1,a_P);a_L4=a_P[0];
a_1837(a_L4,a_P);
a_1196(1696718871);
if(a_1168(a_P)){ return;}
a_1201(a_P); return;
a_G12:if(a_1164(1696718972)){ return;}
a_1200(a_P);a_L3=a_P[0];
a_1741(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777310){ goto a_G16;}
 if(a_L4==16777293||a_L4==16777298||a_L4==16777304||a_L4==16777331){ goto a_G17;}
  return;}
a_G16:a_A[0]=a_L3; return;
a_G17:a_1829(a_L3,a_F1); return;
} /* gsimpleaffix */
static void a_1833(int a_F1,int a_A[1]){ /* gmatchformalactual+>a+a> */
int a_L3;int a_L4;int a_P[1];
{ if(a_F1==16777288||a_F1==16777283||a_F1==16777277){ goto a_G2;}
 if(a_F1==16777316){ goto a_G7;}
 if(a_F1==16777293){ goto a_G8;}
 if(a_F1==16777298){ goto a_G9;}
 if(a_F1==16777304){ goto a_G10;}
  goto a_G11;}
a_G2:a_1200(a_P);a_L3=a_P[0];
a_1741(a_L3,a_P);a_L4=a_P[0];
if(!a_equal(a_L4,16777310)){ goto a_G6;}
a_A[0]=a_L3; return;
a_G6:a_A[0]=0; return;
a_G7:a_1200(a_P);a_A[0]=a_P[0]; return;
a_G8:a_1837(2311425,a_P);a_A[0]=a_P[0]; return;
a_G9:a_1837(2311426,a_P);a_A[0]=a_P[0]; return;
a_G10:a_1837(2311427,a_P);a_A[0]=a_P[0]; return;
a_G11:a_1248(a_1001,2130706304); return;
} /* gmatchformalactual */
static void a_1821(int a_F1){ /* gactualrule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[1];
a_1847(1048580,0);
a_L2=to_LIST(a_1150)->aupb;
a_L6=0;a_L7=0;
a_1731(a_F1,a_P);a_L3=a_P[0];
a_L4=1;
a_G6:if(!a_1164(1696718988)){ goto a_G16;}
a_1733(a_F1,a_L4,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,16777310)){ goto a_G12;}
a_incr(a_L4);
a_L6=a_L4;
a_1733(a_F1,a_L4,a_P);a_L5=a_P[0];
a_G12:a_1833(a_L5,a_P);a_L7=a_P[0];
a_incr(a_L4);
if(a_lseq(a_L4,a_L3)){ goto a_G6;}
a_L4=a_L6; goto a_G6;
a_G16:if(a_equal(a_L7,0)){ goto a_G21;}
if(!a_equal(a_F1,16777861)){ goto a_G19;}
a_1830(a_L7); goto a_G21;
a_G19:if(a_1746(a_F1,131072)){ goto a_G21;}
a_1831(a_L7,a_F1,a_L3,a_L6);
a_G21:if(!a_1746(a_F1,512)){ goto a_G23;}
a_1847(1048582,0);
a_G23:a_L7=a_L2;
a_G24:if(a_mreq(a_L7,to_LIST(a_1150)->aupb)){ goto a_G32;}
a_incr(a_L7);
a_L9=to_LIST(a_1150)->offset[a_L7];
a_incr(a_L7);
a_L8=to_LIST(a_1150)->offset[a_L7];
a_incr(a_L7);
a_1847(a_L8,to_LIST(a_1719)->offset[to_LIST(a_1150)->offset[a_L7]-1]);
a_1814(a_L9,to_LIST(a_1150)->offset[a_L7]); goto a_G24;
a_G32:a_unstackto(a_1150,a_L2);
if(!a_1746(a_F1,1024)){ goto a_G35;}
a_1847(1048583,0); return;
a_G35:a_1847(1048581,0); return;
} /* gactualrule */
static void a_1826(void){ /* gcompound */
int a_L1;
a_L1=to_LIST(a_1719)->aupb;
a_1836();
a_unstackto(a_1719,a_L1); return;
} /* gcompound */
static void a_1822(void){ /* galtsequence */

a_G1:a_1834();
a_1847(1048579,0);
a_1823();
if(!a_1164(1696719016)){ return;}
a_1847(1048591,0); goto a_G1;
} /* galtsequence */
static void a_1823(void){ /* galttail */

a_G1:if(!a_1164(1696718892)){ return;}
a_1834(); goto a_G1;
} /* galttail */
static void a_1834(void){ /* gmember */
int a_L1;int a_P[1];
if(!a_1164(1696718979)){ goto a_G4;}
a_1826();
a_1196(1696718882); return;
a_G4:if(!a_1164(1696718915)){ goto a_G6;}
a_1828(); return;
a_G6:if(!a_1164(1696718941)){ goto a_G9;}
a_1200(a_P);a_L1=a_P[0];
a_1847(1048586,to_LIST(a_1719)->offset[a_L1-1]); return;
a_G9:if(!a_1164(1696718988)){ goto a_G11;}
a_1847(1048584,0); return;
a_G11:if(!a_1164(1696718964)){ goto a_G13;}
a_1847(1048585,0); return;
a_G13:a_1200(a_P);a_L1=a_P[0];
a_1849=a_L1;
if(!a_is(a_1816)){ goto a_G18;}
if(!a_1746(a_L1,128)){ goto a_G18;}
a_1817(a_L1); return;
a_G18:a_1821(a_L1); return;
} /* gmember */
static void a_1836(void){ /* grulebody */
int a_L1;int a_L2;int a_P[1];
a_1855(a_P);a_L1=a_P[0];
a_1856();
a_1857(a_L1,a_P);a_L2=a_P[0];
if(!a_1164(1696718868)){ goto a_G7;}
a_1835();
a_1825(); goto a_G8;
a_G7:a_1822();
a_G8:a_1806(a_L2); return;
} /* grulebody */
static void a_1851(int a_F1,int a_F2,int a_F3){ /* setRULEflag+>a+>a+>a */

a_addmult(a_F2,2,a_F1,a_F1);
a_boolor(to_LIST(a_1151)->offset[a_F1-1],a_F3,to_LIST(a_1151)->offset[a_F1-1]); return;
} /* setRULEflag */
static void a_1805(int a_F1,int a_F2,int a_F3){ /* clearRULEflag+>a+>a+>a */

a_addmult(a_F2,2,a_F1,a_F1);
a_boolinvert(a_F3,a_F3);
a_booland(to_LIST(a_1151)->offset[a_F1-1],a_F3,to_LIST(a_1151)->offset[a_F1-1]); return;
} /* clearRULEflag */
static void a_1808(int a_F1,int a_F2,int a_F3){ /* copyUf1toUf2+>a+>a+>a */
int a_L4;int a_L5;
a_L4=1;
a_G2:a_addmult(a_L4,2,a_F1,a_L5);
a_booland(to_LIST(a_1151)->offset[a_L5-1],1048576,a_L5);
if(a_noteq(a_L5,0)){ return;}
a_addmult(a_L4,2,a_F1,a_L5);
a_booland(to_LIST(a_1151)->offset[a_L5-1],a_F2,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G9;}
a_1851(a_F1,a_L4,a_F3); goto a_G10;
a_G9:a_1805(a_F1,a_L4,a_F3);
a_G10:a_incr(a_L4); goto a_G2;
} /* copyUf1toUf2 */
static void a_1842(int a_F1,int a_F2,int a_F3){ /* mergeUf1toUf2+>a+>a+>a */
int a_L4;int a_L5;
a_L4=1;
a_G2:a_addmult(a_L4,2,a_F1,a_L5);
a_booland(to_LIST(a_1151)->offset[a_L5-1],1048576,a_L5);
if(a_noteq(a_L5,0)){ return;}
a_addmult(a_L4,2,a_F1,a_L5);
a_booland(to_LIST(a_1151)->offset[a_L5-1],a_F2,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G14;}
if(a_noteq(a_F3,1)){ goto a_G13;}
a_addmult(a_L4,2,a_F1,a_L5);
a_booland(to_LIST(a_1151)->offset[a_L5-1],a_F3,a_L5);
if(a_noteq(a_L5,0)){ goto a_G13;}
a_1799=1;
a_G13:a_1851(a_F1,a_L4,a_F3);
a_G14:a_incr(a_L4); goto a_G2;
} /* mergeUf1toUf2 */
static void a_1809(int a_F1,int a_F2){ /* copyjumpUf+>a+>a */
int a_L3;int a_L4;
a_L3=1;
a_G2:a_addmult(a_L3,2,a_F1,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],1048576,a_L4);
if(a_noteq(a_L4,0)){ goto a_G11;}
a_addmult(a_L3,2,a_F1,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],1,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G9;}
a_1851(a_F2,a_L3,8); goto a_G10;
a_G9:a_1805(a_F2,a_L3,8);
a_G10:a_incr(a_L3); goto a_G2;
a_G11:a_addmult(a_L3,2,a_F2,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],1048576,a_L4);
if(a_noteq(a_L4,0)){ return;}
a_1805(a_F2,a_L3,8);
a_incr(a_L3); goto a_G11;
} /* copyjumpUf */
static void a_1852(int a_F1,int a_F2,int a_F3){ /* setflagsforregion+>a+>a+>a */
int a_L4;int a_L5;
a_L4=1;
a_G2:a_addmult(a_L4,2,a_F1,a_L5);
a_booland(to_LIST(a_1151)->offset[a_L5-1],1048576,a_L5);
if(a_noteq(a_L5,0)){ return;}
a_addmult(a_L4,2,a_F1,a_L5);
a_booland(to_LIST(a_1151)->offset[a_L5-1],8,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G9;}
a_1851(a_F2,a_L4,2);
a_G9:a_addmult(a_L4,2,a_F1,a_L5);
a_booland(to_LIST(a_1151)->offset[a_L5-1],a_F3,a_L5);
if(!a_noteq(a_L5,0)){ goto a_G13;}
a_1851(a_F2,a_L4,4);
a_G13:a_1805(a_F2,a_L4,8);
a_incr(a_L4); goto a_G2;
} /* setflagsforregion */
static void a_1848(int a_F1,int a_F2){ /* recoverflagsfromregion+>a+>a */
int a_L3;int a_L4;
a_L3=1;
a_G2:a_addmult(a_L3,2,a_F1,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],1048576,a_L4);
if(a_noteq(a_L4,0)){ return;}
a_addmult(a_L3,2,a_F2,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],8,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G9;}
a_1851(a_F1,a_L3,8); goto a_G10;
a_G9:a_1805(a_F1,a_L3,8);
a_G10:a_incr(a_L3); goto a_G2;
} /* recoverflagsfromregion */
static void a_1853(int a_F1){ /* setflagsforrule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_P[1];
a_1731(a_F1,a_P);a_L3=a_P[0];
a_L4=0;a_L6=0;
a_L2=to_LIST(a_1151)->offset[to_LIST(a_1151)->aupb];
a_G4:if(a_mreq(a_L4,a_L3)){ return;}
a_incr(a_L4);
a_1733(a_F1,a_L4,a_P);a_L5=a_P[0];
{ if(a_L5==16777293){ goto a_G8;}
 if(a_L5==16777298||a_L5==16777304){ goto a_G9;}
  goto a_G4;}
a_G8:a_incr(a_L6); goto a_G4;
a_G9:a_incr(a_L6);
a_1851(a_L2,a_L6,2); goto a_G4;
} /* setflagsforrule */
static int a_1781(int a_F1,int a_A[1]){ /* Bdata+>a+a> */

if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],a_F1)){ return 0;}
a_A[0]=to_LIST(a_1151)->offset[a_1801];
a_previous(a_1151,a_1801); return 1;
} /* Bdata */
static void a_1784(int a_F1){ /* Bsetflag+>a */
int a_L2;
a_L2=a_1801;
a_next(a_1151,a_L2);
to_LIST(a_1151)->offset[a_L2-1]=a_F1; return;
} /* Bsetflag */
static void a_1783(int a_F1){ /* Bsetdata+>a */
int a_L2;
a_L2=a_1801;
a_next(a_1151,a_L2);
to_LIST(a_1151)->offset[a_L2]=a_F1; return;
} /* Bsetdata */
static void a_1780(void){ /* Bback */

a_previous(a_1151,a_1801); return;
} /* Bback */
static void a_1782(int a_A[1]){ /* Bgetptr+a> */

a_A[0]=a_1801;
a_next(a_1151,a_A[0]); return;
} /* Bgetptr */
static void a_1802(int a_F1){ /* Uregion+>a */

a_1808(a_F1,4,16);
a_G2:a_1798(a_F1);
a_1808(a_F1,8,16);
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048591)){ goto a_G6;}
a_previous(a_1151,a_1801); goto a_G2;
a_G6:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048587)){ goto a_G10;}
a_previous(a_1151,a_1801);
if(a_1797(a_F1,4)){ goto a_G10;}
a_1248(a_1001,2130706297); return;
a_G10:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048577)){ goto a_G12;}
a_previous(a_1151,a_1801); goto a_G13;
a_G12:a_1780(); goto a_G10;
a_G13:a_1842(a_F1,8,1); return;
} /* Uregion */
static int a_1797(int a_F1,int a_F2){ /* Uactualrule+>a+>a */
int a_L3;int a_L4;int a_P[1];
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048581)){ goto a_G3;}
a_G2:a_previous(a_1151,a_1801); goto a_G6;
a_G3:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048583)){ return 0;}
a_previous(a_1151,a_1801);
a_1808(a_F1,32,8);
a_G6:if(!a_1781(1048593,a_P)){ goto a_G8;}a_L3=a_P[0];
a_1851(a_F1,a_L3,8); goto a_G6;
a_G8:if(!a_1781(1048594,a_P)){ goto a_G14;}a_L3=a_P[0];
a_addmult(a_L3,2,a_F1,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],8,a_L4);
if(a_noteq(a_L4,0)){ goto a_G13;}
a_1784(1048595);
a_G13:a_1805(a_F1,a_L3,8); goto a_G6;
a_G14:if(!a_1781(1048595,a_P)){ goto a_G19;}a_L3=a_P[0];
a_addmult(a_L3,2,a_F1,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],8,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G13;}
a_1784(1048594); goto a_G13;
a_G19:if(a_equal(to_LIST(a_1151)->offset[a_1801-1],1048576)){ goto a_G2;}
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048582)){ goto a_G23;}
a_previous(a_1151,a_1801);
a_1842(a_F1,a_F2,8); goto a_G6;
a_G23:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048580)){ goto a_G25;}
a_previous(a_1151,a_1801); return 1;
a_G25:a_1248(a_1001,2130706293); return 1;
} /* Uactualrule */
static int a_1800(int a_F1,int a_F2){ /* Umember+>a+>a */
int a_L3;int a_P[1];
if(!a_1781(1048586,a_P)){ goto a_G3;}a_L3=a_P[0];
a_1809(a_L3,a_F1); return 1;
a_G3:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048584)){ goto a_G6;}
a_previous(a_1151,a_1801);
a_1808(a_F1,2,8); return 1;
a_G6:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048585)){ goto a_G9;}
a_previous(a_1151,a_1801);
a_1808(a_F1,a_F2,8); return 1;
a_G9:if(a_1797(a_F1,a_F2)){ return 1;}
if(!a_1781(1048578,a_P)){ return 0;}a_L3=a_P[0];
a_1852(a_F1,a_L3,a_F2);
a_1802(a_L3);
a_1848(a_F1,a_L3); return 1;
} /* Umember */
static void a_1798(int a_F1){ /* Ualternative+>a */

a_1808(a_F1,2,8);
a_G2:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048579)){ goto a_G6;}
a_previous(a_1151,a_1801);
if(a_1800(a_F1,16)){ return;}
a_1248(a_1001,2130706288); return;
a_G6:if(!a_1800(a_F1,4)){ return;} goto a_G2;
} /* Ualternative */
static void a_1858(int a_F1){ /* traverseRULE+>a */
int a_L2;int a_P[1];
a_1853(a_F1);
a_G2:a_1801=to_LIST(a_1151)->aupb;
if(a_1781(1048578,a_P)){a_L2=a_P[0]; goto a_G5;}
a_1248(a_1001,2130706282); return;
a_G5:a_1799=0;
a_1802(a_L2);
if(a_equal(a_1799,0)){ return;} goto a_G2;
} /* traverseRULE */
static void a_1793(int a_F1,int a_F2,int a_A[1]){ /* Lscani+>a+>a+a> */
int a_L4;int a_L5;int a_P[1];
a_L4=a_F2;a_L5=a_F2;
a_A[0]=a_F1;
a_G3:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048591)){ goto a_G8;}
a_previous(a_1151,a_1801);
a_L4=a_A[0];
a_A[0]=a_F1;
a_L5=a_F2; goto a_G3;
a_G8:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048584)){ goto a_G11;}
a_G9:a_previous(a_1151,a_1801);
a_1783(a_A[0]); goto a_G3;
a_G11:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048585)){ goto a_G15;}
a_G12:a_previous(a_1151,a_1801);
a_1783(a_L5);
a_A[0]=a_L5; goto a_G3;
a_G15:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048579)){ goto a_G18;}
a_previous(a_1151,a_1801);
a_L5=a_L4; goto a_G3;
a_G18:if(a_equal(to_LIST(a_1151)->offset[a_1801-1],1048581)){ goto a_G9;}
if(a_equal(to_LIST(a_1151)->offset[a_1801-1],1048582)){ goto a_G12;}
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048580)){ goto a_G23;}
a_previous(a_1151,a_1801);
a_1782(a_P);a_A[0]=a_P[0]; goto a_G3;
a_G23:if(a_1781(1048586,a_P)){a_A[0]=a_P[0]; goto a_G3;}
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048578)){ goto a_G27;}
a_previous(a_1151,a_1801);
a_1793(a_A[0],a_L5,a_P);a_A[0]=a_P[0]; goto a_G3;
a_G27:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048577)){ goto a_G30;}
a_previous(a_1151,a_1801);
a_1783(a_A[0]); return;
a_G30:a_1780(); goto a_G3;
} /* Lscani */
static void a_1795(int a_F1){ /* Lunroll+>a */
int a_L2;
a_L2=to_LIST(a_1151)->offset[a_F1];
if(a_equal(a_L2,-1)){ return;}
if(a_equal(a_L2,-2)){ return;}
if(!a_equal(a_L2,0)){ goto a_G6;}
a_1248(a_1001,2130706276); return;
a_G6:if(a_equal(to_LIST(a_1151)->offset[a_L2-1],1048580)){ return;}
to_LIST(a_1151)->offset[a_F1]=0;
a_1795(a_L2);
to_LIST(a_1151)->offset[a_F1]=to_LIST(a_1151)->offset[a_L2]; return;
} /* Lunroll */
static void a_1794(void){ /* Lscanii */
int a_L1;
a_L1=to_LIST(a_1151)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1151)->aupb)){ return;}
if(a_equal(to_LIST(a_1151)->offset[a_L1-1],1048581)){ goto a_G5;}
if(!a_equal(to_LIST(a_1151)->offset[a_L1-1],1048582)){ goto a_G6;}
a_G5:a_1795(a_L1);
a_G6:a_next(a_1151,a_L1); goto a_G2;
} /* Lscanii */
static void a_1792(void){ /* Lfindlabels */
int a_P[1];
a_1801=to_LIST(a_1151)->aupb;
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048578)){ goto a_G4;}
a_previous(a_1151,a_1801); goto a_G5;
a_G4:a_1248(a_1001,2130706272); return;
a_G5:a_1793(-1,-2,a_P);
a_1794(); return;
} /* Lfindlabels */
static void a_1841(int a_F1,int a_F2){ /* mergeDUflags+>a+>a */
int a_L3;int a_L4;
a_L3=1;
a_G2:a_addmult(a_L3,2,a_F1,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],1048576,a_L4);
if(a_noteq(a_L4,0)){ return;}
a_addmult(a_L3,2,a_F2,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],256,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G9;}
a_1851(a_F1,a_L3,256);
a_G9:a_addmult(a_L3,2,a_F2,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],512,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G13;}
a_1851(a_F1,a_L3,512);
a_G13:a_incr(a_L3); goto a_G2;
} /* mergeDUflags */
static int a_1791(int a_F1){ /* DUrule+>a */
int a_L2;int a_P[1];
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048581)){ goto a_G3;}
a_G2:a_previous(a_1151,a_1801); goto a_G4;
a_G3:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048583)){ return 0;} goto a_G2;
a_G4:if(!a_1781(1048593,a_P)){ goto a_G6;}a_L2=a_P[0];
a_1851(a_F1,a_L2,256); goto a_G4;
a_G6:if(!a_1781(1048594,a_P)){ goto a_G8;}a_L2=a_P[0];
a_1851(a_F1,a_L2,512); goto a_G4;
a_G8:if(a_equal(to_LIST(a_1151)->offset[a_1801-1],1048595)){ goto a_G2;}
if(a_equal(to_LIST(a_1151)->offset[a_1801-1],1048576)){ goto a_G2;}
if(a_equal(to_LIST(a_1151)->offset[a_1801-1],1048582)){ goto a_G2;}
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048580)){ return 1;}
a_previous(a_1151,a_1801); return 1;
} /* DUrule */
static int a_1789(int a_F1){ /* DUmember+>a */
int a_L2;int a_P[1];
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048586)){ goto a_G3;}
a_G2:a_previous(a_1151,a_1801); return 1;
a_G3:if(a_equal(to_LIST(a_1151)->offset[a_1801-1],1048584)){ goto a_G2;}
if(a_equal(to_LIST(a_1151)->offset[a_1801-1],1048585)){ goto a_G2;}
if(a_1791(a_F1)){ return 1;}
if(!a_1781(1048578,a_P)){ return 0;}a_L2=a_P[0];
a_1790(a_L2);
a_1841(a_F1,a_L2); return 1;
} /* DUmember */
static void a_1788(int a_F1){ /* DUalternative+>a */

a_G1:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048579)){ goto a_G4;}
a_previous(a_1151,a_1801);
if(!a_1789(a_F1)){ return;} return;
a_G4:if(!a_1789(a_F1)){ return;} goto a_G1;
} /* DUalternative */
static void a_1790(int a_F1){ /* DUregion+>a */

a_G1:a_1788(a_F1);
if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048591)){ goto a_G4;}
a_previous(a_1151,a_1801); goto a_G1;
a_G4:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048587)){ goto a_G7;}
a_previous(a_1151,a_1801);
if(a_1791(a_F1)){}
a_G7:if(!a_equal(to_LIST(a_1151)->offset[a_1801-1],1048577)){ goto a_G9;}
a_previous(a_1151,a_1801); return;
a_G9:a_previous(a_1151,a_1801); goto a_G7;
} /* DUregion */
static void a_1807(void){ /* computeDUflags */
int a_L1;int a_P[1];
a_1801=to_LIST(a_1151)->aupb;
if(a_1781(1048578,a_P)){a_L1=a_P[0]; goto a_G4;}
a_1248(a_1001,2130706267); return;
a_G4:a_1790(a_L1); return;
} /* computeDUflags */
static void a_1813(int a_F1,int a_F2,int a_F3){ /* diagnoselocal+>a+>a+>a */
int a_L4;int a_P[3];
if(a_noteq(a_1803,1)){ return;}
if(a_noteq(to_LIST(a_1719)->offset[a_F3-2],16777331)){ return;}
a_addmult(a_F2,2,a_F1,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],256,a_L4);
if(a_noteq(a_L4,0)){ return;}
a_addmult(a_F2,2,a_F1,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],512,a_L4);
if(!a_noteq(a_L4,0)){ return;}
a_P[0]=2130705871;a_P[1]=a_1850;a_P[2]=to_LIST(a_1719)->offset[a_F3];a_1240(4,-1,3,a_P); return;
} /* diagnoselocal */
static void a_1814(int a_F1,int a_F2){ /* diagnoseoutaffix+>a+>a */
int a_P[3];
if(a_noteq(a_1803,1)){ return;}
if(a_noteq(to_LIST(a_1151)->offset[a_1796-1],1048595)){ return;}
if(!a_equal(a_F1,2311427)){ goto a_G5;}
a_P[0]=2130705882;a_P[1]=a_1850;a_P[2]=to_LIST(a_1719)->offset[a_F2];a_1240(1,-1,3,a_P); return;
a_G5:a_P[0]=2130705882;a_P[1]=a_1850;a_P[2]=to_LIST(a_1719)->offset[a_F2];a_1240(4,-1,3,a_P); return;
} /* diagnoseoutaffix */
static void a_1812(void){ /* diagnoseformals */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[3];
a_L1=to_LIST(a_1719)->alwb;
a_L2=to_LIST(a_1151)->alwb;
a_L3=1;
a_G4:if(a_more(a_L1,to_LIST(a_1719)->aupb)){ return;}
{register int a_r1=to_LIST(a_1719)->offset[a_L1-2];
 if(a_r1==16777293){ goto a_G6;}
 if(a_r1==16777304){ goto a_G14;}
 if(a_r1==16777298){ goto a_G13;}
  goto a_G21;}
a_G6:a_addmult(a_L3,2,a_L2,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],1,a_L4);
if(a_noteq(a_L4,0)){ goto a_G13;}
a_addmult(a_L3,2,a_L2,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],512,a_L4);
if(!a_noteq(a_L4,0)){ goto a_G13;}
a_G12:a_P[0]=2130705897;a_P[1]=a_1850;a_P[2]=to_LIST(a_1719)->offset[a_L1];a_1240(4,-1,3,a_P);
a_G13:a_incr(a_L3); goto a_G21;
a_G14:a_addmult(a_L3,2,a_L2,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],1,a_L4);
if(a_noteq(a_L4,0)){ goto a_G13;}
a_addmult(a_L3,2,a_L2,a_L4);
a_booland(to_LIST(a_1151)->offset[a_L4-1],512,a_L4);
if(a_noteq(a_L4,0)){ goto a_G12;}
a_P[0]=2130705912;a_P[1]=a_1850;a_P[2]=to_LIST(a_1719)->offset[a_L1];a_1240(4,-1,3,a_P); goto a_G13;
a_G21:a_next(a_1719,a_L1); goto a_G4;
} /* diagnoseformals */
static void a_1815(int a_F1){ /* diagnoserule+>a */
int a_L2;int a_L3;int a_L4;int a_P[2];
a_1211(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1816=0;
a_1803=3;
a_scratch(a_1151);
a_scratch(a_1150);
{register int a_r1=to_LIST(a_1151)->aupb;a_L4=a_r1;a_1796=a_r1;}
a_1854(a_F1);
a_1836();
a_1196(1696718991);
a_1858(a_F1);
a_1807();
a_1209(a_L2,a_L3);
a_1803=1;
a_1796=a_L4;
a_1854(a_F1);
a_1812();
a_1836();
a_1196(1696718991);
a_1209(a_L2,a_L3); return;
} /* diagnoserule */
static void a_1804(void){ /* assignnodes */
int a_L1;int a_L2;
a_L1=to_LIST(a_1086)->vlwb;
a_1844=0;
a_L2=to_LIST(a_1151)->alwb;
a_G4:if(a_more(a_L2,to_LIST(a_1151)->aupb)){ return;}
if(!a_equal(to_LIST(a_1151)->offset[a_L2-1],1048580)){ goto a_G10;}
if(!a_equal(to_LIST(a_1151)->offset[a_L2],0)){ goto a_G10;}
to_LIST(a_1151)->offset[a_L2]=a_L1;
a_incr(a_1844);
a_next(a_1086,a_L1);
a_G10:a_next(a_1151,a_L2); goto a_G4;
} /* assignnodes */
static void a_1874(int a_F1){ /* wlabel+>a */
int a_L2;
a_1087(1696718985);
if(!a_equal(a_F1,0)){ goto a_G4;}
a_G3:a_1089(0); return;
a_G4:a_L2=to_LIST(a_1151)->offset[a_F1];
if(a_equal(to_LIST(a_1151)->offset[a_F1-1],1048583)){ goto a_G3;}
if(!a_equal(a_L2,-1)){ goto a_G9;}
if(a_equal(a_1850,16777853)){ goto a_G3;}
a_1089(-1); return;
a_G9:if(!a_equal(a_L2,-2)){ goto a_G12;}
if(a_equal(a_1850,16777853)){ goto a_G3;}
a_1089(-2); return;
a_G12:a_1087(to_LIST(a_1151)->offset[a_L2]); return;
} /* wlabel */
static void a_1881(int a_F1,int a_A[1]){ /* wtransportlist+>a+a> */
int a_L3;int a_P[2];
a_A[0]=0;
a_G2:a_1880(2311425,a_P);
a_G3:if(!a_1164(1696719031)){ goto a_G12;}
a_1818(1696719031);
a_incr(a_A[0]);
if(a_1168(a_P)){a_L3=a_P[0]; goto a_G10;}
a_1201(a_P);a_L3=a_P[0];
if(a_1674(a_F1,a_L3,a_P)){a_L3=a_P[0]; goto a_G10;}
a_1248(a_1001,2130706261); return;
a_G10:a_P[0]=a_L3;a_1811(a_F1,a_P);a_L3=a_P[0];
a_P[0]=1696718889;a_P[1]=a_L3;a_1846(2,a_P); goto a_G3;
a_G12:if(a_1164(1696718892)){ goto a_G2;}
a_1196(1696718915); return;
} /* wtransportlist */
static void a_1872(void){ /* wextension */
int a_L1;int a_L2;int a_L3;int a_L4;int a_P[1];
a_1200(a_P);a_L1=a_P[0];
a_1847(1048580,0);
a_1087(1696718915);
a_1087(to_LIST(a_1151)->offset[a_1796]);
a_1095(a_L1);
a_L3=to_LIST(a_1150)->aupb;
a_1881(a_L1,a_P);a_L2=a_P[0];
a_1089(a_L2);
a_L4=a_L3;
a_incr(a_L4);
a_P[0]=a_L4;a_1871(a_P);
a_unstackto(a_1150,a_L3);
a_1847(1048581,0);
a_1874(a_1796);
a_1087(1696718892); return;
} /* wextension */
static int a_1875(int a_A[1]){ /* wlimit+a> */

if(!a_1164(1696719035)){ goto a_G3;}
a_A[0]=1696719035; return 1;
a_G3:if(!a_1164(1696718957)){ goto a_G5;}
a_A[0]=1696718957; return 1;
a_G5:if(!a_1164(1696719043)){ goto a_G7;}
a_A[0]=1696719043; return 1;
a_G7:if(!a_1164(1696719039)){ return 0;}
a_A[0]=1696719039; return 1;
} /* wlimit */
static void a_1820(int a_F1,int a_F2,int a_A[1]){ /* finalssel+>a+>a+a> */
int a_P[1];
if(!a_is(a_F2)){ goto a_G3;}
a_A[0]=to_LIST(a_1719)->offset[a_F2-4]; return;
a_G3:if(!a_was(a_1719,a_F1)){ goto a_G5;}
a_A[0]=to_LIST(a_1719)->offset[a_F1-4]; return;
a_G5:a_1680(a_F1,a_P);a_A[0]=a_P[0]; return;
} /* finalssel */
static void a_1873(int a_F1){ /* whandleaffix+>a */
int a_P[1];
if(!a_1839(a_F1)){ goto a_G3;}
a_1847(1048593,0);
a_G3:if(!a_1845(a_F1)){ return;}
a_P[0]=1696718964;a_1846(1,a_P); return;
} /* whandleaffix */
static void a_1868(int a_F1,int a_F2,int a_F3,int a_F4){ /* wbeforevarargblock+>a+>a+>a+>a */
int a_L5;int a_P[1];
a_G1:a_next(a_1719,a_F1);
a_1733(a_F2,a_F4,a_P);a_L5=a_P[0];
a_incr(a_F4);
{ if(!(a_L5==16777293||a_L5==16777304)){ goto a_G6;}
}
a_1847(1048593,0);
a_G6:if(a_more(a_F4,a_F3)){ return;} goto a_G1;
} /* wbeforevarargblock */
static void a_1867(int a_F1){ /* wbeforeshiftrule+>a */

a_G1:a_next(a_1719,a_F1);
{register int a_r1=to_LIST(a_1719)->offset[a_F1-2];
 if(a_r1==16777335){ return;}
 if(!(a_r1==16777293||a_r1==16777304)){ goto a_G1;}
}
a_1847(1048593,0); goto a_G1;
} /* wbeforeshiftrule */
static void a_1863(int a_F1,int a_F2,int a_F3,int a_F4){ /* waftervarargblock+>a+>a+>a+>a */
int a_L5;int a_P[1];
a_G1:a_next(a_1719,a_F1);
a_1733(a_F2,a_F4,a_P);a_L5=a_P[0];
a_incr(a_F4);
{ if(!(a_L5==16777298||a_L5==16777304)){ goto a_G6;}
}
a_1847(1048594,0);
a_G6:if(a_more(a_F4,a_F3)){ return;} goto a_G1;
} /* waftervarargblock */
static void a_1862(int a_F1){ /* waftershiftrule+>a */

a_G1:a_next(a_1719,a_F1);
{register int a_r1=to_LIST(a_1719)->offset[a_F1-2];
 if(a_r1==16777335){ return;}
 if(!(a_r1==16777298||a_r1==16777304)){ goto a_G1;}
}
a_1847(1048594,0); goto a_G1;
} /* waftershiftrule */
static void a_1880(int a_F1,int a_A[1]){ /* wsimpleaffix+>a+a> */
int a_L3;int a_L4;int a_L5;int a_L6;int a_P[7];
a_A[0]=0;
if(!a_1172(a_P)){ goto a_G4;}a_L6=a_P[0];
a_G3:a_1818(a_L6); return;
a_G4:if(!a_1164(1696718876)){ goto a_G10;}
a_1200(a_P);a_L3=a_P[0];
if(!a_was(a_1718,a_L3)){ goto a_G9;}
a_1677(a_L3,a_P);a_L6=a_P[0];
a_1117(a_L6,a_P);a_L6=a_P[0]; goto a_G3;
a_G9:a_P[0]=1696718876;a_P[1]=a_L3;a_1846(2,a_P); return;
a_G10:if(!a_1875(a_P)){ goto a_G13;}a_L6=a_P[0];
a_1200(a_P);a_L3=a_P[0];
a_P[0]=a_L6;a_P[1]=a_L3;a_1846(2,a_P); return;
a_G13:if(!a_1164(1696718972)){ goto a_G15;}
a_1818(1696718972); return;
a_G15:if(!a_1164(1696719027)){ goto a_G27;}
a_1200(a_P);a_L3=a_P[0];
a_P[0]=1696719027;a_P[1]=a_L3;a_1846(2,a_P);
a_1859(a_F1,a_P);a_L4=a_P[0];
a_1880(a_L4,a_P);
a_1196(1696718871);
if(a_1168(a_P)){a_L6=a_P[0]; goto a_G25;}
a_1201(a_P);a_L6=a_P[0];
if(a_1674(a_L3,a_L6,a_P)){a_L6=a_P[0]; goto a_G25;}
a_1248(a_1001,2130706255); return;
a_G25:a_P[0]=a_L6;a_1811(a_L3,a_P);a_L6=a_P[0];
a_P[0]=1696718871;a_P[1]=1696718889;a_P[2]=a_L6;a_1846(3,a_P); return;
a_G27:a_1198(a_P);a_L3=a_P[0];a_L5=a_P[1];
a_1741(a_L3,a_P);a_L4=a_P[0];
{ if(a_L4==16777310){ goto a_G30;}
 if(a_L4==16777244||a_L4==16777240||a_L4==16777250||a_L4==16777277||a_L4==16777283){ goto a_G32;}
 if(a_L4==16777293||a_L4==16777298||a_L4==16777304||a_L4==16777331){ goto a_G34;}
  goto a_G35;}
a_G30:a_1818(1696718853);
a_A[0]=a_L3; return;
a_G32:a_1820(a_L3,a_L5,a_P);a_L6=a_P[0];
a_P[0]=1696719027;a_P[1]=a_L3;a_P[2]=1696719035;a_P[3]=a_L3;a_P[4]=1696718871;a_P[5]=1696718889;a_P[6]=a_L6;a_1846(7,a_P); return;
a_G34:a_1873(a_F1);
a_G35:a_1818(a_L3); return;
} /* wsimpleaffix */
static void a_1876(int a_F1,int a_A[1]){ /* wmatchformalactual+>a+a> */
int a_L3;int a_L4;int a_P[1];
{ if(a_F1==16777288||a_F1==16777283||a_F1==16777277){ goto a_G2;}
 if(a_F1==16777316){ goto a_G9;}
 if(a_F1==16777293){ goto a_G11;}
 if(a_F1==16777298){ goto a_G12;}
 if(a_F1==16777304){ goto a_G13;}
  goto a_G14;}
a_G2:a_1200(a_P);a_L3=a_P[0];
a_1741(a_L3,a_P);a_L4=a_P[0];
if(!a_equal(a_L4,16777310)){ goto a_G7;}
a_1818(1696718853);
a_A[0]=a_L3; return;
a_G7:a_1818(a_L3);
a_A[0]=0; return;
a_G9:a_1200(a_P);a_A[0]=a_P[0];
a_1818(a_A[0]); return;
a_G11:a_1880(2311425,a_P);a_A[0]=a_P[0]; return;
a_G12:a_1880(2311426,a_P);a_A[0]=a_P[0]; return;
a_G13:a_1880(2311427,a_P);a_A[0]=a_P[0]; return;
a_G14:a_1248(a_1001,2130706249); return;
} /* wmatchformalactual */
static void a_1871(int a_A[1]){ /* wcopyaffixfromBUFFER+>a> */

a_G1:if(a_more(a_A[0],to_LIST(a_1150)->aupb)){ return;}
if(a_equal(to_LIST(a_1150)->offset[a_A[0]],1696718988)){ return;}
if(!a_equal(to_LIST(a_1150)->offset[a_A[0]],1696718964)){ goto a_G6;}
a_incr(a_A[0]);
a_1847(1048593,0); goto a_G1;
a_G6:if(!a_equal(to_LIST(a_1150)->offset[a_A[0]],1696718889)){ goto a_G10;}
a_incr(a_A[0]);
a_1089(to_LIST(a_1150)->offset[a_A[0]]);
a_G9:a_incr(a_A[0]); goto a_G1;
a_G10:if(!a_was(a_1719,to_LIST(a_1150)->offset[a_A[0]])){ goto a_G12;}
a_G11:a_1095(to_LIST(a_1150)->offset[a_A[0]]); goto a_G9;
a_G12:if(a_was(a_1718,to_LIST(a_1150)->offset[a_A[0]])){ goto a_G11;}
a_1087(to_LIST(a_1150)->offset[a_A[0]]); goto a_G9;
} /* wcopyaffixfromBUFFER */
static void a_1810(int a_F1,int a_A[1]){ /* copyspareaffix+>a+>a> */
int a_P[1];
if(!a_equal(a_F1,16777298)){ goto a_G8;}
a_1087(1696718972);
a_G3:if(a_more(a_A[0],to_LIST(a_1150)->aupb)){ return;}
if(a_equal(to_LIST(a_1150)->offset[a_A[0]],1696718988)){ return;}
if(!a_equal(to_LIST(a_1150)->offset[a_A[0]],1696718889)){ goto a_G7;}
a_incr(a_A[0]);
a_G7:a_incr(a_A[0]); goto a_G3;
a_G8:a_1087(1696718885);
a_P[0]=a_A[0];a_1871(a_P);a_A[0]=a_P[0]; return;
} /* copyspareaffix */
static void a_1861(int a_F1,int a_F2,int a_F3,int a_F4,int a_F5){ /* wafteraffixes+>a+>a+>a+>a+>a */
int a_L6;int a_L7;int a_L8;int a_P[1];
a_incr(a_F3);
a_L6=1;
a_L8=0;
a_G4:if(a_more(a_F3,to_LIST(a_1150)->aupb)){ return;}
a_1733(a_F1,a_L6,a_P);a_L7=a_P[0];
if(!a_equal(a_L7,16777310)){ goto a_G13;}
a_1087(1696718853);
if(a_equal(a_F5,0)){ goto a_G10;}
a_subtr(0,a_F4,a_F4);
a_G10:a_1089(a_F4);
a_incr(a_L6);
a_L8=a_L6; goto a_G4;
a_G13:a_incr(a_F3);
if(!a_equal(to_LIST(a_1150)->offset[a_F3],1696718853)){ goto a_G17;}
a_1087(1696718853);
a_incr(a_F3); goto a_G25;
a_G17:if(a_equal(a_L7,16777298)){ goto a_G19;}
if(!a_equal(a_L7,16777304)){ goto a_G24;}
a_G19:if(!a_equal(to_LIST(a_1150)->offset[a_F3],1696718964)){ goto a_G24;}
a_incr(a_F3);
a_1847(1048593,0);
if(!a_equal(to_LIST(a_1151)->offset[a_1796-1],1048595)){ goto a_G24;}
a_P[0]=a_F3;a_1810(a_L7,a_P);a_F3=a_P[0]; goto a_G25;
a_G24:a_P[0]=a_F3;a_1871(a_P);a_F3=a_P[0];
a_G25:a_incr(a_L6);
if(a_lseq(a_L6,a_F2)){ goto a_G4;}
a_L6=a_L8; goto a_G4;
} /* wafteraffixes */
static void a_1860(int a_F1){ /* wactualrule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_L6;int a_L7;int a_L8;int a_L9;int a_P[1];
a_1847(1048580,0);
a_1087(1696718976);
a_1087(to_LIST(a_1151)->offset[a_1796]);
a_1095(a_F1);
a_L2=to_LIST(a_1150)->aupb;
a_1785=0;a_1786=0;a_1787=0;
a_L6=0;a_L8=0;a_L7=0;
a_1731(a_F1,a_P);a_L3=a_P[0];
a_L4=1;
a_G10:if(!a_1164(1696718988)){ goto a_G28;}
a_1818(1696718988);
a_1733(a_F1,a_L4,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,16777310)){ goto a_G17;}
a_incr(a_L4);
a_L6=a_L4;
a_1733(a_F1,a_L4,a_P);a_L5=a_P[0];
a_G17:if(!a_is(a_L6)){ goto a_G19;}
a_incr(a_1787); goto a_G22;
a_G19:a_incr(a_1785);
{ if(!(a_L5==16777298||a_L5==16777304)){ goto a_G22;}
}
a_incr(a_1786);
a_G22:a_1876(a_L5,a_P);a_L8=a_P[0];
a_incr(a_L4);
if(a_lseq(a_L4,a_L3)){ goto a_G10;}
if(a_is(a_L8)){ goto a_G10;}
a_L4=a_L6;
a_incr(a_L7); goto a_G10;
a_G28:if(!a_equal(a_L8,0)){ goto a_G32;}
a_add(a_1787,a_1785,a_1785);
a_add(a_1787,a_1786,a_1786);
a_1787=0; goto a_G34;
a_G32:if(!a_more(a_1787,0)){ goto a_G34;}
a_decr(a_1787);
a_G34:a_1089(a_1785);
a_1089(a_1786);
a_1089(a_1787);
if(a_equal(a_L8,0)){ goto a_G42;}
if(!a_equal(a_F1,16777861)){ goto a_G40;}
a_1867(a_L8); goto a_G42;
a_G40:if(a_1746(a_F1,131072)){ goto a_G42;}
a_1868(a_L8,a_F1,a_L3,a_L6);
a_G42:if(!a_1746(a_F1,512)){ goto a_G45;}
a_1847(1048582,0);
a_L9=a_1796; goto a_G46;
a_G45:a_L9=0;
a_G46:a_1861(a_F1,a_L3,a_L2,a_L7,a_L8);
if(a_equal(a_L8,0)){ goto a_G52;}
if(!a_equal(a_F1,16777861)){ goto a_G50;}
a_1862(a_L8); goto a_G52;
a_G50:if(a_1746(a_F1,131072)){ goto a_G52;}
a_1863(a_L8,a_F1,a_L3,a_L6);
a_G52:a_1847(1048581,0);
a_1874(a_L9);
a_1874(a_1796);
a_1087(1696718892);
a_unstackto(a_1150,a_L2); return;
} /* wactualrule */
static void a_1866(int a_F1){ /* warea+>a */
int a_P[1];
a_1087(1696718860);
a_incr(a_F1);
a_P[0]=a_F1;a_1871(a_P); return;
} /* warea */
static void a_1878(void){ /* wreadbox */
int a_L1;int a_L2;int a_L3;int a_P[1];
a_1847(1048580,0);
a_1087(1696718868);
a_1087(to_LIST(a_1151)->offset[a_1796]);
{register int a_r1=to_LIST(a_1150)->aupb;a_L2=a_r1;a_L1=a_r1;}
a_1880(2311425,a_P);
a_incr(a_L1);
a_P[0]=a_L1;a_1871(a_P);
a_unstackto(a_1150,a_L2);
a_1847(1048581,0);
a_L1=to_LIST(a_1151)->offset[a_1796];
a_1847(1048587,0);
a_1196(1696718868);
a_G13:if(a_equal(a_L1,0)){ goto a_G21;}
a_L2=to_LIST(a_1151)->offset[a_L1];
a_next(a_1151,a_L1);
a_L3=to_LIST(a_1151)->offset[a_L1];
a_next(a_1151,a_L1);
a_1866(a_L2);
a_1874(a_L1);
a_L1=a_L3; goto a_G13;
a_G21:a_1087(1696718892); return;
} /* wreadbox */
static void a_1869(void){ /* wclassification */

a_G1:a_1196(1696718860);
a_1176(1696718860);
a_1847(1048580,0);
a_1847(1048582,0);
a_1847(1048581,0);
a_1847(1048579,0);
a_1865();
if(!a_1164(1696719016)){ return;}
a_1847(1048591,0); goto a_G1;
} /* wclassification */
static void a_1870(void){ /* wcompound */
int a_L1;
a_L1=to_LIST(a_1719)->aupb;
a_1879();
a_unstackto(a_1719,a_L1); return;
} /* wcompound */
static void a_1864(void){ /* waltsequence */

a_G1:a_1877();
a_1847(1048579,0);
a_1865();
if(!a_1164(1696719016)){ return;}
a_1847(1048591,0); goto a_G1;
} /* waltsequence */
static void a_1865(void){ /* walttail */

a_G1:if(!a_1164(1696718892)){ return;}
a_1877(); goto a_G1;
} /* walttail */
static void a_1877(void){ /* wmember */
int a_L1;int a_P[1];
if(!a_1164(1696718979)){ goto a_G4;}
a_1870();
a_1196(1696718882); return;
a_G4:if(!a_1164(1696718915)){ goto a_G6;}
a_1872(); return;
a_G6:if(!a_1164(1696718941)){ goto a_G9;}
a_1200(a_P);
a_1847(1048586,0); return;
a_G9:if(!a_1164(1696718988)){ goto a_G11;}
a_1847(1048584,0); return;
a_G11:if(!a_1164(1696718964)){ goto a_G13;}
a_1847(1048585,0); return;
a_G13:a_1200(a_P);a_L1=a_P[0];
if(!a_1746(a_L1,128)){ goto a_G16;}
a_1817(a_L1); return;
a_G16:a_1860(a_L1); return;
} /* wmember */
static void a_1879(void){ /* wrulebody */
int a_L1;int a_L2;int a_P[1];
a_1855(a_P);a_L1=a_P[0];
a_1856();
a_1857(a_L1,a_P);a_L2=a_P[0];
if(!a_1164(1696718868)){ goto a_G7;}
a_1878();
a_1869(); goto a_G8;
a_G7:a_1864();
a_G8:a_1806(a_L2); return;
} /* wrulebody */
static void a_1827(int a_F1){ /* generaterule+>a */
int a_L2;int a_L3;int a_L4;int a_L5;int a_P[2];
a_1850=a_F1;
a_1815(a_F1);
a_1736(a_F1,a_P);a_L5=a_P[0];
if(!a_equal(a_L5,0)){ goto a_G6;}
a_1176(1696718991); return;
a_G6:a_1211(a_P);a_L2=a_P[0];a_L3=a_P[1];
a_1816=1;
a_1803=3;
a_scratch(a_1151);
a_scratch(a_1150);
{register int a_r1=to_LIST(a_1151)->aupb;a_L4=a_r1;a_1796=a_r1;}
a_1843=0;a_1840=0;
a_1854(a_F1);
a_1836();
a_1196(1696718991);
a_1858(a_F1);
a_1792();
a_1804();
a_1209(a_L2,a_L3);
a_1087(1696719013);
a_1095(a_F1);
a_1089(a_1843);
a_1089(a_1840);
a_1089(a_1844);
a_1803=2;
a_1816=1;
a_1796=a_L4;
a_1854(a_F1);
a_1879();
a_1196(1696718991);
a_1087(1696718991); return;
} /* generaterule */
static void a_1818(int a_F1){ /* extendBUFFER+>a */

{register int *a_r1=a_extension(a_1150,1);a_r1[0]=a_F1;to_LIST(a_1150)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1819(int a_F1,int a_F2){ /* extendRULE+>a+>a */

{register int *a_r1=a_extension(a_1151,2);a_r1[0]=a_F1;a_r1[1]=a_F2;to_LIST(a_1151)->aupb+=2;}
  return;
} /* extendRULE */
static void a_1884(int a_F1,int a_F2,int a_F3){ /* putasstring+""f+t[]+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=0;
a_putchar(a_F1,34);
a_G3:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){ goto a_G8;}a_L3=a_P[0];
a_incr(a_L2);
if(!a_equal(a_L3,34)){ goto a_G7;}
a_putchar(a_F1,a_L3);
a_G7:a_putchar(a_F1,a_L3); goto a_G3;
a_G8:a_putchar(a_F1,34); return;
} /* putasstring */
static void a_1886(int a_F1,int a_F2,int a_F3){ /* putstring+""f+t[]+>a */
int a_L2;int a_L3;int a_P[1];
a_L2=0;
a_G2:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){ return;}a_L3=a_P[0];
a_incr(a_L2);
a_putchar(a_F1,a_L3); goto a_G2;
} /* putstring */
a_PROFILE *a_profiles=NULL;
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
