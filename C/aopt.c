/* ALEPH ice linker v2.1, word size=32 */

// linked modules:
// error "optimizer error v2.2"
// item "optimizer item v2.2"
// lexical "optimizer lexical v2.2"
// @main "ALEPH optimizer, v2.2"
// stdlib "stdlib base"
// stdlib "stdlib put as string"
// stdlib "stdlib put string"
// stdlib "stdlib stdarg"
#include "aleph_core.h"
#include "aleph_stdarg.h"
#include "aleph_stdlib.h"
#define a_1001 (0) /* @StringTable */
#define a_1005 (a_1001+sizeof_LIST) /* ERRFILE */
#define a_1006 (a_1005+sizeof_CHFILE) /* MESSAGE */
static void a_1007(a_word a_F1,a_word a_F2); /* corrupticefile */
static void a_1008(a_word a_F1,a_word a_C,a_word *a_V); /* error */
static void a_1009(a_word a_F1,a_word a_C,a_word *a_V); /* formatprint */
static void a_1010(a_word a_F1,a_word a_F2); /* internalerror */
static void a_1011(void); /* nlcr */
static void a_1012(a_word a_F1,a_word a_F2); /* print */
static void a_1013(a_word a_F1); /* printchar */
static void a_1014(a_word a_F1); /* printnum */
static void a_1015(a_word a_F1,a_word a_F2); /* printnum1 */
#define a_1017 (a_1006+sizeof_LIST) /* AUX */
#define a_1018 (a_1017+sizeof_LIST) /* ITEM */
static void a_1019(a_word a_F1,a_word a_F2); /* addpull */
static void a_1020(a_word a_A[1]); /* converttoitem */
static void a_1021(void); /* copydatasection */
static void a_1022(a_word a_F1); /* copyexpression */
static void a_1023(a_word a_F1); /* copyexternal */
static void a_1024(void); /* copyfileareas */
static void a_1025(a_word a_F1); /* copyfileentry */
static void a_1026(a_word a_F1); /* copyfillentry */
static void a_1027(void); /* copyfillitem */
static void a_1028(void); /* copyfillitempack */
static void a_1029(void); /* copyfillrepeater */
static void a_1030(void); /* copyformalaffixes */
static void a_1031(void); /* copyheadsection */
static void a_1032(void); /* copyinitializers */
static void a_1033(a_word a_F1); /* copyitem */
static void a_1034(void); /* copyitemsection */
static void a_1035(void); /* copylistbounds */
static void a_1036(a_word a_F1); /* copylistentry */
static void a_1037(a_word a_F1); /* copymatter */
static void a_1038(void); /* copynode */
static void a_1039(a_word a_F1); /* copyrule */
static void a_1040(void); /* copyrulesection */
static void a_1041(void); /* datasection */
static void a_1042(void); /* expandITEM */
static void a_1043(a_word a_F1); /* fileareas */
static void a_1044(void); /* fileentry */
static void a_1045(void); /* fillentry */
static void a_1046(a_word a_F1); /* fillinitializers */
static void a_1047(a_word a_F1); /* fillitem */
static void a_1048(a_word a_F1); /* fillitempack */
static void a_1049(a_word a_F1); /* fillrepeater */
static void a_1050(a_word a_F1,a_word a_A[1]); /* getitemrepr */
static void a_1051(void); /* headsection */
static a_word a_1052(a_word a_F1,a_word a_F2); /* isitemflag */
static a_word a_1053(a_word a_F1,a_word a_F2); /* ispulleditem */
static void a_1054(void); /* itemsection */
static void a_1055(void); /* listentry */
static void a_1056(a_word a_F1); /* markifrequested */
static a_word a_1057=0; /* nextitem */
static void a_1058(void); /* readexpression */
static void a_1059(void); /* readitem */
static void a_1060(a_word a_F1); /* readnode */
static void a_1061(void); /* readrule */
static void a_1062(void); /* rulesection */
static void a_1063(a_word a_F1,a_word a_F2); /* setitemflag */
static void a_1064(void); /* skipentry */
static void a_1065(void); /* skipformalaffixes */
static void a_1066(a_word a_F1); /* skipitem */
static void a_1067(void); /* skiplistbounds */
static void a_1068(a_word a_F1,a_word a_A[1]); /* traverseitem */
static void a_1069(void); /* traverseitems */
static void a_1070(a_word a_A[1]); /* traverseonce */
#define a_1072 (a_1018+sizeof_LIST) /* BOLD */
#define a_1073 (a_1072+sizeof_LIST) /* BUFFER */
#define a_1074 (a_1073+sizeof_LIST) /* HASH */
static a_word a_1075=1; /* HASHentries */
static a_word a_1076=1023; /* HASHsize */
#define a_1077 (a_1074+sizeof_LIST) /* LEXT */
#define a_1078 (a_1077+sizeof_LIST) /* RESULT */
#define a_1079 (a_1078+sizeof_CHFILE) /* SOURCE */
static void a_1080(a_word a_F1); /* W */
static void a_1081(a_word a_F1,a_word a_F2); /* WW */
static void a_1082(a_word a_A[1]); /* addLEXTentry */
static a_word a_1083=32; /* char */
static void a_1084(void); /* closesource */
static void a_1085(void); /* comment */
static void a_1086(void); /* copysourcetoresult */
static void a_1087(a_word a_F1,a_word a_A[1]); /* enterstring */
static void a_1088(a_word a_F1); /* extendBUFFER */
static void a_1089(a_word a_F1,a_word a_A[1]); /* gettagimage */
static a_word a_1090=0; /* inf */
static a_word a_1091=0; /* inpt */
static a_word a_1092=0; /* inptvalue */
static void a_1093(void); /* movetempfile */
static void a_1094(void); /* nextchar */
static void a_1095(void); /* nextsymbol */
static void a_1096(a_word a_F1); /* opensource */
static void a_1097(a_word a_F1); /* opensourcefile */
static a_word a_1098=0; /* outf */
static a_word a_1099=0; /* output */
static void a_1100(a_word a_A[1]); /* readbold */
static void a_1101(a_word a_A[1]); /* readdestination */
static void a_1102(a_word a_A[1]); /* readstring */
static void a_1103(a_word a_A[1]); /* readtargetnumber */
static void a_1104(a_word a_A[1]); /* readtargetstring */
static void a_1105(a_word a_A[1]); /* readtype */
static void a_1106(void); /* rehash */
static void a_1107(a_word a_F1,a_word a_F2); /* rewindsource */
static a_word a_1108=1; /* sourceline */
static void a_1109(a_word a_F1); /* toggleout */
static void a_1110(a_word a_A[1]); /* trytoopen */
static void a_1111(a_word a_F1,a_word a_F2); /* wnum1 */
static void a_1112(a_word a_F1); /* writenum */
static a_word a_1113=1; /* wsep */
static void a_1114(void); /* wspace */
static a_word a_1116=0; /* argtop */
static void a_1117(void); /* checkcommandlinearguments */
static void a_1118(void); /* firstpass */
static a_word a_1119=0; /* ifile */
static a_word a_1120(a_word a_F1,a_word a_F2); /* isfirstarg */
static a_word a_1121=1; /* nextID */
static a_word a_1122=0; /* ofile */
static void a_1123(void); /* parseSTDARG */
static void a_1124(void); /* renumberitems */
static a_word a_1125=0; /* replacearg */
static void a_1126(void); /* secondpass */
static void a_1127(a_word a_F1); /* setrepr */
static void a_1130(a_word a_F1,a_word a_F2,a_word a_F3); /* putasstring */
static void a_1132(a_word a_F1,a_word a_F2,a_word a_F3); /* putstring */
#define a_1134 (a_1079+sizeof_CHFILE) /* STDARG */
static void a_1115(void); /* @main root */
static void a_1071(void); /* lexical root */
#define BLOCK_TOTAL (a_1134+sizeof_LIST)
a_word a_DATABLOCK[BLOCK_TOTAL];
static a_word a_FILL[]={ /* fill table */
a_1001,/* @StringTable */
9,1953723757,0,4,4,1953709116,1953853284,15934,10,5,0,
a_1006,/* MESSAGE */
28,1920102211,544501877,1920298867,773875043,543515497,1701603686,1768693804,622880110,1915232356,543517813,2715685,43,13,1702129257,1818324594,1920099616,1629516399,1768693876,622880110,1718558820,1970238240,543515506,1701013806,1970415648,622880108,10608,50,15,0,
a_1001,/* @StringTable */
53,1953723757,0,4,4,2037411683,1701606770,1952671091,7237481,15,6,1701606770,1952671091,7237481,11,5,1635017060,1952671091,7237481,11,5,1684104562,1919973477,1769173861,28271,14,6,1885956979,1920233061,121,9,5,2037411683,1835365481,0,8,5,1885956979,1835365481,0,8,5,1684104562,1835365481,0,8,5,1885956979,1836216166,1717660769,1702390118,115,17,7,0,
a_1077,/* LEXT */
6,1869574720,116,5,4,0,0,0,
a_1001,/* @StringTable */
63,22359,2,3,87,1,3,1954047342,1651341683,27759,10,5,1684104562,1701869940,0,8,5,1684104562,1684828002,0,8,5,1684104562,1735549300,1953723493,1735289202,0,16,7,1684104562,1769108595,26478,10,5,1634231666,26739,6,4,1684104562,1953719652,1952542313,7237481,15,6,1684104562,1701080681,120,9,5,1769238639,1702521197,2020879972,116,13,6,1885695073,1667837544,101,9,5,1953723757,0,4,4,0,
a_1006,/* MESSAGE */
46,1852727619,1864397935,544105840,1970302569,1768300660,622880108,115,25,9,1852727619,1663071343,1952540018,1970217061,1953853556,1818846752,1931812965,0,28,10,1852727619,1663071343,1952540018,1702109285,1919905901,544830049,1701603686,0,28,10,1869771333,1701978226,1667329136,543649385,1701603686,746071328,1936028192,544500853,1629516649,2015699060,0,40,13,1701013806,0,4,4,0,
a_1077,/* LEXT */
5,0,0,3,0,0,0,
a_1072,/* BOLD */
273,1634038369,0,4,4,1801675106,0,4,4,7892834,3,3,1768710499,6648418,7,4,1919973477,1769173861,28271,10,5,1702131813,1869181806,110,9,5,1702131813,1818324594,0,8,5,1701603686,0,4,4,1819044198,0,4,4,1852797542,116,5,4,1953720684,0,4,4,6453100,3,3,1852399981,0,4,4,1969516397,25964,6,4,1701080942,0,4,4,1701606770,0,4,4,28532,2,3,6451317,3,3,1651993718,0,4,4,1651537270,0,4,4,1936617315,1953390964,0,8,5,1769103734,1701601889,0,8,5,1952543859,1981834089,29281,10,5,1818386804,101,5,4,1667331187,107,5,4,1952543859,1931502441,1801675124,0,12,6,1852403568,544367988,1936617315,1953390964,0,16,7,1918986339,1701603686,0,8,5,1635017060,1701603686,0,8,5,1701606770,0,4,4,1836216166,1931504737,1801675124,0,12,6,1836216166,1948281953,1701601889,0,12,6,1836216166,1713400929,6646889,11,5,1836216166,1763732577,110,9,5,1836216166,1864395873,29813,10,5,1836216166,1763732577,1953853294,0,12,6,1836216166,1629514849,1869112174,114,13,6,1836216166,1931504737,1952868712,0,12,6,64,1,3,38,1,3,93,1,3,41,1,3,58,1,3,44,1,3,126,1,3,47,1,3,45,1,3,28197,2,3,35,1,3,40,1,3,124,1,3,62,1,3,43,1,3,46,1,3,59,1,3,42,1,3,91,1,3,94,1,3,1936617315,116,5,4,1651340654,29285,6,4,1920234356,0,4,4,1701869940,0,4,4,1701080942,0,4,4,1835365481,0,4,4,1836216166,27745,6,4,1633906540,108,5,4,1769108595,26478,6,4,2763306,3,3,0,
a_1001,/* @StringTable */
18,1953723757,0,4,4,1701981485,1667329136,101,9,5,1702243629,1869181810,110,9,5,1701326125,28780,6,4,0,
a_1006,/* MESSAGE */
168,1769238607,1702521197,544104736,1346718785,541928776,1701013806,1818846752,1433281893,1701273971,1868636218,1528853616,1701326125,2082500716,1982672160,1769173605,626880111,538976366,540701295,1953525601,1915563296,1634496613,1008756067,1970302569,1847934580,1864376352,1629502066,544501871,1886284092,540963957,1953853244,1047819632,1767337509,572549236,1701981485,1667329136,1008738917,1970302569,1763720820,1701978227,1667329136,1998611557,543716457,543516788,1769238639,1702521197,1702240356,1869181810,11886,190,50,1346718785,541928776,1701013806,1953525536,2053729641,1981837925,1769173605,622882415,1680158308,1866690085,1769109872,544499815,539575080,808595506,842019373,1632378933,1869380211,1769161504,2053205362,1750363685,1763734377,543236211,1701147238,1718580000,1918990196,1931488357,1948280165,1931502952,1668445551,1952522341,1953785888,792359792,1953064751,778204520,795701091,1769169772,2053205362,1701601583,1847945328,544370534,2037411683,1751607666,1852383348,1836216166,1869182049,1411395182,1701995880,544434464,1461735246,1095914049,995710030,1953459744,1702257952,1701650542,1851877475,1768057204,2037672300,628256544,1953064558,1936942446,1919903264,1881170208,1769239137,1634497891,1970282610,1936683122,11877,266,69,1936943437,543649385,1969713761,1953391981,1937055788,757932133,1886152040,1919903264,1931501856,1953656680,1818585120,112,45,14,1936943437,543649385,1953853244,1047819632,1937055788,757932133,1886152040,1919903264,1931501856,1953656680,1818585120,112,45,14,544173908,2037277037,1735549216,1852140917,539784052,543519605,1701326125,1713401964,1629516399,1869116192,1746957426,7367781,47,14,1886221359,1701601583,1479370864,1482184792,88,17,7,0,
-1}; /* fill table size 699 */
static void a_data_setup(void){
 a_virtual_min=16777216;a_virtual_max=2130706432;
 a_setup_list(0,a_1001,"@StringTable",1,2130706254,2130706396,143); /* @StringTable */
 a_setup_list(0,a_1006,"MESSAGE",1,2130706011,2130706252,242); /* MESSAGE */
 a_setup_list(1,a_1017,"AUX",2,956301283,1347769521,0); /* AUX */
 a_setup_list(1,a_1018,"ITEM",7,1347769530,2130706003,0); /* ITEM */
 a_setup_list(0,a_1072,"BOLD",1,16777217,16777489,273); /* BOLD */
 a_setup_list(1,a_1073,"BUFFER",1,95071140,173364787,0); /* BUFFER */
 a_setup_list(1,a_1074,"HASH",1,16777491,95071138,0); /* HASH */
 a_setup_list(1,a_1077,"LEXT",2,173364790,956301279,11); /* LEXT */
 a_setup_stdarg(a_1134,"STDARG",1);
 a_setup_charfile(a_1005,"ERRFILE",2,a_1001,2130706262); /* ERRFILE */
 a_setup_charfile(a_1078,"RESULT",2,a_1001,2130706369); /* RESULT */
 a_setup_charfile(a_1079,"SOURCE",1,a_1001,2130706374); /* SOURCE */
 a_list_fill(a_FILL);
}
static void a_waitfor(a_word a_F1,a_word a_F2){
 a_MODROOT(a_1071,"lexical")
}
void a_ROOT(void){
 a_data_setup();
 a_waitfor(0,0);
 a_1115();
}
static void a_1013(a_word a_F1){ /* printchar+>a */

a_putchar(a_1005,a_F1); return;
} /* printchar */
static void a_1011(void){ /* nlcr */

a_1013(10); return;
} /* nlcr */
static void a_1014(a_word a_F1){ /* printnum+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G5;}
a_1013(45);
a_subtr(-1,a_F1,a_F1);
a_1015(a_F1,49); return;
a_G5:if(!a_less(a_F1,0)){ goto a_G9;}
a_1013(45);
a_getabs(a_F1,a_F1);
a_1015(a_F1,48); return;
a_G9:a_1015(a_F1,48); return;
} /* printnum */
static void a_1015(a_word a_F1,a_word a_F2){ /* printnum1+>a+>a */
a_word a_L3;a_word a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1015(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_1013(a_L4); return;
} /* printnum1 */
static void a_1012(a_word a_F1,a_word a_F2){ /* print+t[]+>a */

a_1132(a_1005,a_F1,a_F2); return;
} /* print */
static void a_1009(a_word a_F1,a_word a_C,a_word *a_V){ /* formatprint+t[]+@+>a */
a_word a_L2;a_word a_L3;
a_L2=to_LIST(a_1073)->aupb;
a_unpackstring(a_1006,a_V[0],a_1073);
a_add(a_L2,1,a_L3);
a_G4:if(a_less(to_LIST(a_1073)->aupb,a_L3)){ goto a_G28;}
if(!a_noteq(to_LIST(a_1073)->offset[a_L3],37)){ goto a_G8;}
a_G6:a_1013(to_LIST(a_1073)->offset[a_L3]);
a_G7:a_incr(a_L3); goto a_G4;
a_G8:a_incr(a_L3);
if(!a_less(to_LIST(a_1073)->aupb,a_L3)){ goto a_G11;}
a_1013(37); goto a_G28;
a_G11:{register a_word a_r1=to_LIST(a_1073)->offset[a_L3];
 if(a_r1==112){ goto a_G12;}
 if(a_r1==115){ goto a_G15;}
 if(a_r1==120){ goto a_G18;}
 if(a_r1==100){ goto a_G21;}
 if(a_r1==110){  goto a_G24;}
  goto a_G6;}
a_G12:if(a_C<=1){ goto a_G7;} a_C--;a_V+=1;
a_1012(a_F1,a_V[0]); goto a_G7;
a_G15:if(a_C<=1){ goto a_G7;} a_C--;a_V+=1;
a_1012(a_1134,a_V[0]); goto a_G7;
a_G18:if(a_C<=1){ goto a_G7;} a_C--;a_V+=1;
a_1012(a_1077,a_V[0]); goto a_G7;
a_G21:if(a_C<=1){ goto a_G7;} a_C--;a_V+=1;
a_1014(a_V[0]); goto a_G7;
a_G24:a_1011(); goto a_G7;
a_G28:a_unstackto(a_1073,a_L2); return;
} /* formatprint */
static void a_1008(a_word a_F1,a_word a_C,a_word *a_V){ /* error+>a+@+>a */

a_1009(a_1006,a_C,a_V);
a_1011();
a_exit(a_F1); return;
} /* error */
static void a_1007(a_word a_F1,a_word a_F2){ /* corrupticefile+t[]+>a */
a_word a_P[3];
a_P[0]=2130706023;a_P[1]=a_1108;a_P[2]=a_F2;a_1009(a_F1,3,a_P);
a_1011();
a_exit(1); return;
} /* corrupticefile */
static void a_1010(a_word a_F1,a_word a_F2){ /* internalerror+t[]+>a */
a_word a_P[3];
a_P[0]=2130706038;a_P[1]=a_1108;a_P[2]=a_F2;a_1009(a_F1,3,a_P);
a_1011();
a_exit(15); return;
} /* internalerror */
static a_word a_1053(a_word a_F1,a_word a_F2){ /* ispulleditem+>a+>a */
a_word a_L3;
a_L3=to_LIST(a_1018)->offset[a_F1-1];
a_G2:if(a_equal(a_L3,0)){ return 0;}
if(a_equal(to_LIST(a_1017)->offset[a_L3-1],a_F2)){ return 1;}
a_L3=to_LIST(a_1017)->offset[a_L3]; goto a_G2;
} /* ispulleditem */
static void a_1019(a_word a_F1,a_word a_F2){ /* addpull+>a+>a */

if(a_1053(a_F1,a_F2)){ return;}
{register a_word *a_r1=a_extension(a_1017,2);a_r1[0]=a_F2;a_r1[1]=to_LIST(a_1018)->offset[a_F1-1];to_LIST(a_1017)->aupb+=2;}
to_LIST(a_1018)->offset[a_F1-1]=to_LIST(a_1017)->aupb; return;
} /* addpull */
static void a_1042(void){ /* expandITEM */

a_incr(a_1057);
{register a_word *a_r1=a_extension(a_1018,7);a_r1[0]=a_r1[1]=a_r1[2]=a_r1[3]=a_r1[4]=a_r1[5]=0;a_r1[6]=a_1057;to_LIST(a_1018)->aupb+=7;}
  return;
} /* expandITEM */
static a_word a_1052(a_word a_F1,a_word a_F2){ /* isitemflag+>a+>a */
a_word a_L3;
a_booland(to_LIST(a_1018)->offset[a_F1-6],a_F2,a_L3);
if(!a_is(a_L3)){ return 0;} return 1;
} /* isitemflag */
static void a_1063(a_word a_F1,a_word a_F2){ /* setitemflag+>a+>a */

a_boolor(to_LIST(a_1018)->offset[a_F1-6],a_F2,to_LIST(a_1018)->offset[a_F1-6]); return;
} /* setitemflag */
static void a_1020(a_word a_A[1]){ /* converttoitem+>a> */

a_addmult(a_A[0],7,1347769523,a_A[0]); return;
} /* converttoitem */
static void a_1050(a_word a_F1,a_word a_A[1]){ /* getitemrepr+>a+a> */

a_A[0]=to_LIST(a_1018)->offset[a_F1]; return;
} /* getitemrepr */
static void a_1051(void){ /* headsection */

a_G1:if(!a_equal(16777438,a_1091)){ goto a_G3;}
a_1095(); return;
a_G3:a_1095(); goto a_G1;
} /* headsection */
static void a_1031(void){ /* copyheadsection */

a_G1:if(!a_equal(16777438,a_1091)){ goto a_G5;}
a_1080(16777420);
a_1109(0);
a_1095(); return;
a_G5:a_1095(); goto a_G1;
} /* copyheadsection */
static void a_1056(a_word a_F1){ /* markifrequested+>a */

if(!a_1052(a_F1,4)){ goto a_G3;}
a_G2:a_1063(a_F1,128); return;
a_G3:if(!a_equal(to_LIST(a_1018)->offset[a_F1-5],16777345)){ return;}
if(!a_equal(to_LIST(a_1018)->offset[a_F1-3],173364794)){ return;} goto a_G2;
} /* markifrequested */
static void a_1065(void){ /* skipformalaffixes */
a_word a_L1;a_word a_L2;
if(!a_equal(16777454,a_1091)){ goto a_G4;}
a_L1=a_1092;
a_G3:a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:if(a_equal(a_L1,0)){ return;}
a_decr(a_L1);
if(!a_equal(16777466,a_1091)){ goto a_G4;}
a_L2=a_1092;
a_1095();
{ if(a_L2==16777351||a_L2==16777357){ goto a_G12;}
 if(a_L2==16777367||a_L2==16777372||a_L2==16777378||a_L2==16777362||a_L2==16777384||a_L2==16777390){  goto a_G5;}
  goto a_G20;}
a_G12:if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095();
if(!a_equal(16777454,a_1091)){ goto a_G4;}
 goto a_G3;
a_G20:a_1007(a_1001,2130706315); return;
} /* skipformalaffixes */
static void a_1067(void){ /* skiplistbounds */

if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095(); return;
} /* skiplistbounds */
static void a_1059(void){ /* readitem */
a_word a_L1;a_word a_L2;
a_1042();
if(!a_equal(16777466,a_1091)){ goto a_G5;}
to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-5]=a_1092;
a_1095(); goto a_G6;
a_G5:a_1007(a_1001,2130706266); return;
a_G6:if(!a_equal(16777474,a_1091)){ goto a_G5;}
a_L1=a_1092;
a_1095();
if(a_equal(a_L1,to_LIST(a_1018)->aupb)){ goto a_G12;}
a_1007(a_1001,2130706308); return;
a_G12:if(!a_equal(16777454,a_1091)){ goto a_G5;}
a_L2=a_1092;
a_1095();
a_booland(a_L2,117557020,to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-6]);
if(!a_equal(16777454,a_1091)){ goto a_G5;}
to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-2]=a_1092;
a_1095();
{register a_word a_r1=to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-5];
 if(a_r1==16777345){ goto a_G22;}
 if(a_r1==16777318||a_r1==16777314||a_r1==16777324){  goto a_G23;}
  goto a_G24;}
a_G22:a_1065(); goto a_G24;
a_G23:a_1067();
a_G24:if(!a_equal(16777486,a_1091)){ goto a_G5;}
to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-4]=a_1092;
a_1095();
if(!a_equal(16777486,a_1091)){ goto a_G5;}
to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-3]=a_1092;
a_1095();
a_1056(a_L1); return;
} /* readitem */
static void a_1054(void){ /* itemsection */

a_G1:if(!a_equal(16777438,a_1091)){ goto a_G3;}
a_1095(); return;
a_G3:a_1059(); goto a_G1;
} /* itemsection */
static void a_1030(void){ /* copyformalaffixes */
a_word a_L1;a_word a_L2;a_word a_L3;
if(!a_equal(16777454,a_1091)){ goto a_G4;}
a_L1=a_1092;
a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:a_1081(16777454,a_L1);
a_G6:if(a_equal(a_L1,0)){ return;}
a_decr(a_L1);
if(!a_equal(16777466,a_1091)){ goto a_G4;}
a_L2=a_1092;
a_1095();
a_1081(16777466,a_L2);
{ if(!(a_L2==16777351||a_L2==16777357)){ goto a_G6;}
}
if(!a_equal(16777454,a_1091)){ goto a_G4;}
a_L3=a_1092;
a_1095();
a_1081(16777454,a_L3);
if(!a_equal(16777454,a_1091)){ goto a_G4;}
a_L3=a_1092;
a_1095();
a_1081(16777454,a_L3); goto a_G6;
} /* copyformalaffixes */
static void a_1035(void){ /* copylistbounds */
a_word a_L1;
if(!a_equal(16777454,a_1091)){ goto a_G4;}
a_L1=a_1092;
a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:a_1081(16777454,a_L1);
if(!a_equal(16777454,a_1091)){ goto a_G4;}
a_L1=a_1092;
a_1095();
a_1081(16777454,a_L1); return;
} /* copylistbounds */
static void a_1066(a_word a_F1){ /* skipitem+>a */
a_word a_L2;a_word a_L3;
if(!a_equal(16777466,a_1091)){ goto a_G4;}
a_L2=a_1092;
a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L3=a_1092;
a_1095();
if(a_equal(a_L3,a_F1)){ goto a_G11;}
a_1010(a_1001,2130706303); return;
a_G11:if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095();
if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095();
{ if(a_L2==16777345){ goto a_G20;}
 if(a_L2==16777318||a_L2==16777314||a_L2==16777324){  goto a_G21;}
  goto a_G22;}
a_G20:a_1065(); goto a_G22;
a_G21:a_1067();
a_G22:if(!a_equal(16777486,a_1091)){ goto a_G4;}

a_1095();
if(!a_equal(16777486,a_1091)){ goto a_G4;}

a_1095(); return;
} /* skipitem */
static void a_1033(a_word a_F1){ /* copyitem+>a */
a_word a_L2;a_word a_L3;a_word a_L4;
if(!a_equal(16777466,a_1091)){ goto a_G4;}
a_L2=a_1092;
a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:a_1081(16777466,a_L2);
if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L3=a_1092;
a_1095();
if(a_equal(a_L3,a_F1)){ goto a_G12;}
a_1010(a_1001,2130706298); return;
a_G12:a_1081(16777474,a_L3);
if(!a_equal(16777454,a_1091)){ goto a_G4;}
a_L4=a_1092;
a_1095();
a_1081(16777454,a_L4);
if(!a_equal(16777454,a_1091)){ goto a_G4;}
a_L4=a_1092;
a_1095();
a_1081(16777454,a_L4);
{ if(a_L2==16777345){ goto a_G24;}
 if(a_L2==16777318||a_L2==16777314||a_L2==16777324){  goto a_G25;}
  goto a_G26;}
a_G24:a_1030(); goto a_G26;
a_G25:a_1035();
a_G26:if(!a_equal(16777486,a_1091)){ goto a_G4;}
a_L4=a_1092;
a_1095();
a_1081(16777486,a_L4);
if(!a_equal(16777486,a_1091)){ goto a_G4;}
a_L4=a_1092;
a_1095();
a_1081(16777486,a_L4);
a_1080(16777420); return;
} /* copyitem */
static void a_1034(void){ /* copyitemsection */
a_word a_L1;
a_L1=to_LIST(a_1018)->alwb;
a_G2:if(!a_equal(16777438,a_1091)){ goto a_G6;}
a_1095();
a_1080(16777438);
a_1080(16777420); return;
a_G6:if(!a_1052(a_L1,128)){ goto a_G9;}
a_1033(a_L1);
a_G8:a_next(a_1018,a_L1); goto a_G2;
a_G9:a_1066(a_L1); goto a_G8;
} /* copyitemsection */
static void a_1064(void){ /* skipentry */

a_G1:if(!a_equal(16777438,a_1091)){ goto a_G3;}
a_1095(); return;
a_G3:if(!a_equal(16777489,a_1091)){ goto a_G6;}
a_1095();
a_1007(a_1001,2130706293); return;
a_G6:a_1095(); goto a_G1;
} /* skipentry */
static void a_1043(a_word a_F1){ /* fileareas+>a */
a_word a_L2;
if(!a_equal(16777447,a_1091)){ return;}
a_1095();
a_G3:if(!a_equal(16777399,a_1091)){ goto a_G5;}
a_1095(); return;
a_G5:if(!a_equal(16777474,a_1091)){ goto a_G8;}
a_L2=a_1092;
a_1095(); goto a_G9;
a_G8:a_1007(a_1001,2130706266); return;
a_G9:a_1019(a_F1,a_L2); goto a_G3;
} /* fileareas */
static void a_1044(void){ /* fileentry */
a_word a_L1;a_word a_L2;
if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L1=a_1092;
a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L2=a_1092;
a_1095();
a_1019(a_L1,a_L2);
if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L2=a_1092;
a_1095();
a_1019(a_L1,a_L2);
a_1043(a_L1);
if(!a_equal(16777438,a_1091)){ goto a_G4;}

a_1095(); return;
} /* fileentry */
static void a_1045(void){ /* fillentry */
a_word a_L1;
if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L1=a_1092;
a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095();
a_G9:if(!a_equal(16777438,a_1091)){ goto a_G11;}
a_1095(); return;
a_G11:a_1048(a_L1);
a_1049(a_L1);
a_1046(a_L1); goto a_G9;
} /* fillentry */
static void a_1048(a_word a_F1){ /* fillitempack+>a */

if(!a_equal(16777426,a_1091)){ goto a_G6;}
a_1095();
a_G3:if(!a_equal(16777402,a_1091)){ goto a_G5;}
a_1095(); return;
a_G5:a_1047(a_F1); goto a_G3;
a_G6:a_1047(a_F1); return;
} /* fillitempack */
static void a_1047(a_word a_F1){ /* fillitem+>a */
a_word a_L2;
if(!a_equal(16777458,a_1091)){ goto a_G3;}
a_G2:a_1095(); return;
a_G3:if(a_equal(16777462,a_1091)){ goto a_G2;}
if(!a_equal(16777474,a_1091)){ goto a_G8;}
a_L2=a_1092;
a_1095(); goto a_G9;
a_G8:a_1007(a_1001,2130706266); return;
a_G9:a_1019(a_F1,a_L2); return;
} /* fillitem */
static void a_1049(a_word a_F1){ /* fillrepeater+>a */
a_word a_L2;
if(!a_equal(16777444,a_1091)){ return;}
a_1095();
if(!a_equal(16777454,a_1091)){ goto a_G5;}
a_1095(); return;
a_G5:if(!a_equal(16777474,a_1091)){ goto a_G8;}
a_L2=a_1092;
a_1095(); goto a_G9;
a_G8:a_1007(a_1001,2130706266); return;
a_G9:a_1019(a_F1,a_L2); return;
} /* fillrepeater */
static void a_1046(a_word a_F1){ /* fillinitializers+>a */
a_word a_L2;
a_G1:if(!a_equal(16777405,a_1091)){ return;}
a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095(); goto a_G7;
a_G6:a_1007(a_1001,2130706266); return;
a_G7:a_1019(a_L2,a_F1); goto a_G1;
} /* fillinitializers */
static void a_1058(void){ /* readexpression */
a_word a_L1;a_word a_L2;
if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L1=a_1092;
a_G3:a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:{ if(a_1091==16777438){ goto a_G6;}
 if(a_1091==16777458){ goto a_G3;}
 if(a_1091==16777474){ goto a_G8;}
 if(a_1091==16777265||a_1091==16777287||a_1091==16777231){ goto a_G10;}
 if(a_1091==16777435||a_1091==16777417||a_1091==16777444||a_1091==16777414||a_1091==16777396||a_1091==16777429||a_1091==16777450||a_1091==16777411||a_1091==16777426||a_1091==16777402){  goto a_G3;}
  goto a_G17;}
a_G6:a_1095(); return;
a_G8:a_1019(a_L1,a_1092); goto a_G3;
a_G10:a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L2=a_1092;
a_1095();
a_1019(a_L1,a_L2); goto a_G5;
a_G17:a_1007(a_1001,2130706288); return;
} /* readexpression */
static void a_1055(void){ /* listentry */
a_word a_L1;a_word a_L2;
if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L1=a_1092;
a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095();
if(!a_equal(16777454,a_1091)){ goto a_G12;}

a_1095(); goto a_G17;
a_G12:if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L2=a_1092;
a_1095();
a_1019(a_L1,a_L2);
a_G17:if(!a_equal(16777438,a_1091)){ goto a_G4;}

a_1095(); return;
} /* listentry */
static void a_1041(void){ /* datasection */

a_G1:if(!a_equal(16777250,a_1091)){ goto a_G4;}
a_1095();
a_1044(); goto a_G1;
a_G4:if(!a_equal(16777254,a_1091)){ goto a_G7;}
a_1095();
a_1045(); goto a_G1;
a_G7:if(!a_equal(16777236,a_1091)){ goto a_G10;}
a_1095();
a_1058(); goto a_G1;
a_G10:if(!a_equal(16777262,a_1091)){ goto a_G13;}
a_1095();
a_1055(); goto a_G1;
a_G13:if(!a_equal(16777224,a_1091)){ goto a_G16;}
a_G14:a_1095();
a_1064(); goto a_G1;
a_G16:if(a_equal(16777258,a_1091)){ goto a_G14;}
if(a_equal(16777246,a_1091)){ goto a_G14;}
if(a_equal(a_1091,16777281)){ return;}
a_1007(a_1001,2130706282); return;
} /* datasection */
static void a_1025(a_word a_F1){ /* copyfileentry+>a */
a_word a_L2;
a_1080(16777250);
a_1081(16777474,a_F1);
if(!a_equal(16777454,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095(); goto a_G7;
a_G6:a_1007(a_1001,2130706266); return;
a_G7:a_1081(16777454,a_L2);
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095();
a_1081(16777474,a_L2);
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095();
a_1081(16777474,a_L2);
a_1024();
if(!a_equal(16777438,a_1091)){ goto a_G6;}

a_1095();
a_1080(16777438);
a_1080(16777420); return;
} /* copyfileentry */
static void a_1024(void){ /* copyfileareas */
a_word a_L1;
if(!a_equal(16777447,a_1091)){ return;}
a_1095();
a_1080(16777447);
a_G4:if(!a_equal(16777399,a_1091)){ goto a_G7;}
a_1095();
a_1080(16777399); return;
a_G7:if(!a_equal(16777474,a_1091)){ goto a_G10;}
a_L1=a_1092;
a_1095(); goto a_G11;
a_G10:a_1007(a_1001,2130706266); return;
a_G11:a_1081(16777474,a_L1); goto a_G4;
} /* copyfileareas */
static void a_1026(a_word a_F1){ /* copyfillentry+>a */
a_word a_L2;
a_1080(16777254);
a_1081(16777474,a_F1);
if(!a_equal(16777454,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095(); goto a_G7;
a_G6:a_1007(a_1001,2130706266); return;
a_G7:a_1081(16777454,a_L2);
a_G8:if(!a_equal(16777438,a_1091)){ goto a_G12;}
a_1095();
a_1080(16777438);
a_1080(16777420); return;
a_G12:a_1028();
a_1029();
a_1032(); goto a_G8;
} /* copyfillentry */
static void a_1028(void){ /* copyfillitempack */

if(!a_equal(16777426,a_1091)){ goto a_G8;}
a_1095();
a_1080(16777426);
a_G4:if(!a_equal(16777402,a_1091)){ goto a_G7;}
a_1095();
a_1080(16777402); return;
a_G7:a_1027(); goto a_G4;
a_G8:a_1027(); return;
} /* copyfillitempack */
static void a_1027(void){ /* copyfillitem */
a_word a_L1;
if(!a_equal(16777458,a_1091)){ goto a_G5;}
a_L1=a_1092;
a_1095();
a_1081(16777458,a_L1); return;
a_G5:if(!a_equal(16777462,a_1091)){ goto a_G9;}
a_L1=a_1092;
a_1095();
a_1081(16777462,a_L1); return;
a_G9:if(!a_equal(16777474,a_1091)){ goto a_G12;}
a_L1=a_1092;
a_1095(); goto a_G13;
a_G12:a_1007(a_1001,2130706266); return;
a_G13:a_1081(16777474,a_L1); return;
} /* copyfillitem */
static void a_1029(void){ /* copyfillrepeater */
a_word a_L1;
if(!a_equal(16777444,a_1091)){ return;}
a_1095();
a_1080(16777444);
if(!a_equal(16777454,a_1091)){ goto a_G8;}
a_L1=a_1092;
a_1095();
a_1081(16777454,a_L1); return;
a_G8:if(!a_equal(16777474,a_1091)){ goto a_G11;}
a_L1=a_1092;
a_1095(); goto a_G12;
a_G11:a_1007(a_1001,2130706266); return;
a_G12:a_1081(16777474,a_L1); return;
} /* copyfillrepeater */
static void a_1032(void){ /* copyinitializers */
a_word a_L1;
a_G1:if(!a_equal(16777405,a_1091)){ return;}
a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L1=a_1092;
a_1095(); goto a_G7;
a_G6:a_1007(a_1001,2130706266); return;
a_G7:if(!a_1052(a_L1,128)){ goto a_G1;}
a_1080(16777405);
a_1081(16777474,a_L1); goto a_G1;
} /* copyinitializers */
static void a_1022(a_word a_F1){ /* copyexpression+>a */
a_word a_L2;
a_1080(16777236);
a_1081(16777474,a_F1);
a_G3:{ if(a_1091==16777438){ goto a_G4;}
 if(a_1091==16777458){ goto a_G7;}
 if(a_1091==16777474){ goto a_G9;}
 if(a_1091==16777265||a_1091==16777287||a_1091==16777231){  goto a_G11;}
  goto a_G18;}
a_G4:a_1095();
a_1080(16777438);
a_1080(16777420); return;
a_G7:a_1081(16777458,a_1092);
a_G8:a_1095(); goto a_G3;
a_G9:a_1081(16777474,a_1092); goto a_G8;
a_G11:a_1080(a_1091);
a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G16;}
a_L2=a_1092;
a_1095(); goto a_G17;
a_G16:a_1007(a_1001,2130706266); return;
a_G17:a_1081(16777474,a_L2); goto a_G3;
a_G18:a_1080(a_1091);
a_1095(); goto a_G3;
} /* copyexpression */
static void a_1036(a_word a_F1){ /* copylistentry+>a */
a_word a_L2;
a_1080(16777262);
a_1081(16777474,a_F1);
if(!a_equal(16777454,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095(); goto a_G7;
a_G6:a_1007(a_1001,2130706266); return;
a_G7:a_1081(16777454,a_L2);
if(!a_equal(16777454,a_1091)){ goto a_G12;}
a_L2=a_1092;
a_1095();
a_1081(16777454,a_L2); goto a_G17;
a_G12:if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095();
a_1081(16777474,a_L2);
a_G17:if(!a_equal(16777438,a_1091)){ goto a_G6;}

a_1095();
a_1080(16777438);
a_1080(16777420); return;
} /* copylistentry */
static void a_1037(a_word a_F1){ /* copymatter+>a */
a_word a_L2;
a_1080(a_F1);
if(!a_equal(16777486,a_1091)){ goto a_G5;}
a_L2=a_1092;
a_1095(); goto a_G6;
a_G5:a_1007(a_1001,2130706266); return;
a_G6:a_1081(16777486,a_L2);
if(!a_equal(16777438,a_1091)){ goto a_G5;}

a_1095();
a_1080(16777438);
a_1080(16777420); return;
} /* copymatter */
static void a_1023(a_word a_F1){ /* copyexternal+>a */
a_word a_L2;
a_1080(16777246);
a_1081(16777474,a_F1);
if(!a_equal(16777486,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095(); goto a_G7;
a_G6:a_1007(a_1001,2130706266); return;
a_G7:if(!a_equal(16777438,a_1091)){ goto a_G6;}

a_1095();
a_1081(16777486,a_L2);
a_1080(16777438);
a_1080(16777420); return;
} /* copyexternal */
static void a_1021(void){ /* copydatasection */
a_word a_L1;
a_G1:if(!a_equal(16777250,a_1091)){ goto a_G10;}
a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L1=a_1092;
a_1095(); goto a_G7;
a_G6:a_1007(a_1001,2130706266); return;
a_G7:if(!a_1052(a_L1,128)){ goto a_G9;}
a_1025(a_L1); goto a_G1;
a_G9:a_1064(); goto a_G1;
a_G10:if(!a_equal(16777254,a_1091)){ goto a_G19;}
a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L1=a_1092;
a_1095();
if(!a_1052(a_L1,128)){ goto a_G9;}
a_1026(a_L1); goto a_G1;
a_G19:if(!a_equal(16777236,a_1091)){ goto a_G28;}
a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L1=a_1092;
a_1095();
if(!a_1052(a_L1,128)){ goto a_G9;}
a_1022(a_L1); goto a_G1;
a_G28:if(!a_equal(16777262,a_1091)){ goto a_G37;}
a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L1=a_1092;
a_1095();
if(!a_1052(a_L1,128)){ goto a_G9;}
a_1036(a_L1); goto a_G1;
a_G37:if(!a_equal(16777224,a_1091)){ goto a_G40;}
a_1095();
a_1037(16777224); goto a_G1;
a_G40:if(!a_equal(16777258,a_1091)){ goto a_G43;}
a_1095();
a_1037(16777258); goto a_G1;
a_G43:if(!a_equal(16777246,a_1091)){ return;}
a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L1=a_1092;
a_1095();
if(!a_1052(a_L1,128)){ goto a_G51;}
a_1023(a_L1); goto a_G1;
a_G51:a_1064(); goto a_G1;
} /* copydatasection */
static void a_1061(void){ /* readrule */
a_word a_L1;
if(!a_equal(16777474,a_1091)){ goto a_G4;}
a_L1=a_1092;
a_1095(); goto a_G5;
a_G4:a_1007(a_1001,2130706266); return;
a_G5:if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095();
if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095();
if(!a_equal(16777454,a_1091)){ goto a_G4;}

a_1095();
a_G17:if(!a_equal(16777227,a_1091)){ goto a_G20;}
a_G18:a_1095();
a_1060(a_L1); goto a_G17;
a_G20:if(a_equal(16777241,a_1091)){ goto a_G18;}
if(a_equal(16777277,a_1091)){ goto a_G18;}
if(!a_equal(16777438,a_1091)){ goto a_G4;}

a_1095(); return;
} /* readrule */
static void a_1060(a_word a_F1){ /* readnode+>a */

a_G1:{ if(a_1091==16777474){ goto a_G2;}
 if(a_1091==16777447||a_1091==16777399||a_1091==16777220||a_1091==16777405||a_1091==16777441||a_1091==16777393||a_1091==16777284||a_1091==16777423||a_1091==16777287||a_1091==16777265||a_1091==16777295||a_1091==16777291||a_1091==16777231){ goto a_G3;}
 if(a_1091==16777454||a_1091==16777482||a_1091==16777478||a_1091==16777470||a_1091==16777432||a_1091==16777458){  goto a_G3;}
  goto a_G6;}
a_G2:a_1019(a_F1,a_1092);
a_G3:a_1095(); goto a_G1;
a_G6:if(!a_equal(16777408,a_1091)){ goto a_G9;}

a_1095(); return;
a_G9:a_1007(a_1001,2130706266); return;
} /* readnode */
static void a_1062(void){ /* rulesection */

a_G1:if(!a_equal(16777281,a_1091)){ goto a_G4;}
a_1095();
a_1061(); goto a_G1;
a_G4:if(!a_equal(16777489,a_1091)){ goto a_G6;}
a_1095(); return;
a_G6:a_1007(a_1001,2130706277); return;
} /* rulesection */
static void a_1039(a_word a_F1){ /* copyrule+>a */
a_word a_L2;
a_1080(16777281);
a_1081(16777474,a_F1);
if(!a_equal(16777454,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095(); goto a_G7;
a_G6:a_1007(a_1001,2130706266); return;
a_G7:a_1081(16777454,a_L2);
if(!a_equal(16777454,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095();
a_1081(16777454,a_L2);
if(!a_equal(16777454,a_1091)){ goto a_G6;}
a_L2=a_1092;
a_1095();
a_1081(16777454,a_L2);
a_G18:if(!a_equal(16777227,a_1091)){ goto a_G22;}
a_1095();
a_1080(16777227);
a_G21:a_1038(); goto a_G18;
a_G22:if(!a_equal(16777241,a_1091)){ goto a_G26;}
a_1095();
a_1080(16777241); goto a_G21;
a_G26:if(!a_equal(16777277,a_1091)){ goto a_G30;}
a_1095();
a_1080(16777277); goto a_G21;
a_G30:if(!a_equal(16777438,a_1091)){ goto a_G6;}

a_1095();
a_1080(16777438);
a_1080(16777420); return;
} /* copyrule */
static void a_1038(void){ /* copynode */

a_G1:{ if(a_1091==16777474||a_1091==16777454||a_1091==16777482||a_1091==16777478||a_1091==16777470||a_1091==16777432||a_1091==16777458){ goto a_G2;}
 if(a_1091==16777447||a_1091==16777399||a_1091==16777220||a_1091==16777405||a_1091==16777441||a_1091==16777393||a_1091==16777284||a_1091==16777423||a_1091==16777287||a_1091==16777265||a_1091==16777295||a_1091==16777291||a_1091==16777231){  goto a_G4;}
  goto a_G6;}
a_G2:a_1081(a_1091,a_1092);
a_G3:a_1095(); goto a_G1;
a_G4:a_1080(a_1091); goto a_G3;
a_G6:if(!a_equal(16777408,a_1091)){ goto a_G9;}

a_1095(); goto a_G10;
a_G9:a_1007(a_1001,2130706266); return;
a_G10:a_1080(16777408); return;
} /* copynode */
static void a_1040(void){ /* copyrulesection */
a_word a_L1;
a_G1:if(!a_equal(16777281,a_1091)){ goto a_G10;}
a_1095();
if(!a_equal(16777474,a_1091)){ goto a_G6;}
a_L1=a_1092;
a_1095(); goto a_G7;
a_G6:a_1007(a_1001,2130706266); return;
a_G7:if(!a_1052(a_L1,128)){ goto a_G9;}
a_1039(a_L1); goto a_G1;
a_G9:a_1064(); goto a_G1;
a_G10:if(!a_equal(16777489,a_1091)){ goto a_G12;}
a_1095(); return;
a_G12:a_1007(a_1001,2130706272); return;
} /* copyrulesection */
static void a_1068(a_word a_F1,a_word a_A[1]){ /* traverseitem+>a+>a> */
a_word a_L3;
if(a_1052(a_F1,64)){ return;}
if(!a_1052(a_F1,128)){ return;}
a_1063(a_F1,64);
a_L3=to_LIST(a_1018)->offset[a_F1-1];
a_G5:if(a_equal(a_L3,0)){ return;}
if(!a_1052(to_LIST(a_1017)->offset[a_L3-1],128)){ goto a_G8;}
a_G7:a_L3=to_LIST(a_1017)->offset[a_L3]; goto a_G5;
a_G8:a_A[0]=1;
a_1063(to_LIST(a_1017)->offset[a_L3-1],128); goto a_G7;
} /* traverseitem */
static void a_1070(a_word a_A[1]){ /* traverseonce+a> */
a_word a_L2;a_word a_P[1];
a_A[0]=0;
a_L2=to_LIST(a_1018)->alwb;
a_G3:if(a_more(a_L2,to_LIST(a_1018)->aupb)){ return;}
a_P[0]=a_A[0];a_1068(a_L2,a_P);a_A[0]=a_P[0];
a_next(a_1018,a_L2); goto a_G3;
} /* traverseonce */
static void a_1069(void){ /* traverseitems */
a_word a_L1;a_word a_P[1];
a_G1:a_1070(a_P);a_L1=a_P[0];
if(a_equal(a_L1,0)){ return;} goto a_G1;
} /* traverseitems */
static void a_1088(a_word a_F1){ /* extendBUFFER+>a */

{register a_word *a_r1=a_extension(a_1073,1);a_r1[0]=a_F1;to_LIST(a_1073)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1110(a_word a_A[1]){ /* trytoopen+a> */

if(!a_openfile(a_1079,114,a_1077,to_LIST(a_1077)->aupb)){ goto a_G3;}
a_A[0]=0; return;
a_G3:a_getfileerror(a_1079,a_A[0]);
if(a_equal(a_A[0],2)){ return;}
a_A[0]=-1; return;
} /* trytoopen */
static void a_1097(a_word a_F1){ /* opensourcefile+>a */
a_word a_L2;a_word a_L3;a_word a_P[2];
a_copystring(a_1134,a_F1,a_1077);
a_1110(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(!a_less(a_L2,0)){ goto a_G6;}
a_G5:a_P[0]=2130706047;a_P[1]=a_F1;a_1008(2,2,a_P); return;
a_G6:a_unstackstring(a_1077);
a_scratch(a_1073);
a_L3=to_LIST(a_1073)->aupb;
a_unpackstring(a_1134,a_F1,a_1073);
a_unpackstring(a_1006,2130706084,a_1073);
a_subtr(to_LIST(a_1073)->aupb,a_L3,a_L3);
a_packstring(a_1073,a_L3,a_1077);
a_scratch(a_1073);
a_1110(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;} goto a_G5;
} /* opensourcefile */
static void a_1096(a_word a_F1){ /* opensource+>a */
a_word a_P[1];
a_1097(a_F1);
a_1082(a_P);a_1090=a_P[0];
a_1108=1;
a_1083=1;
a_1099=0;
a_1094();
a_1095(); return;
} /* opensource */
static void a_1107(a_word a_F1,a_word a_F2){ /* rewindsource+>a+>a */
a_word a_P[2];
if(!a_is(a_F1)){ goto a_G5;}
a_1098=0;
if(a_openfile(a_1078,119,a_1134,a_F1)){ goto a_G9;}
a_P[0]=2130706057;a_P[1]=a_F1;a_1008(2,2,a_P); return;
a_G5:a_copystring(a_1006,a_F2,a_1077);
if(!a_opentempfile(a_1078,a_1077,to_LIST(a_1077)->aupb)){ goto a_G8;}
a_1082(a_P);a_1098=a_P[0]; goto a_G9;
a_G8:a_P[0]=2130706067;a_1008(2,1,a_P); return;
a_G9:a_setfilepos(a_1079,0);
a_1108=1;
a_1083=1;
a_1099=1;
a_1094();
a_1095(); return;
} /* rewindsource */
static void a_1084(void){ /* closesource */

a_closefile(a_1079);
a_closefile(a_1078);
if(a_equal(a_1098,0)){ return;}
a_1093(); return;
} /* closesource */
static void a_1086(void){ /* copysourcetoresult */
a_word a_L1;a_word a_P[1];
a_G1:if(!a_getchar(a_1079,a_P)){ goto a_G3;}a_L1=a_P[0];
a_putchar(a_1078,a_L1); goto a_G1;
a_G3:a_closefile(a_1079);
a_closefile(a_1078); return;
} /* copysourcetoresult */
static void a_1093(void){ /* movetempfile */
a_word a_L1;a_word a_L2;a_word a_P[3];
a_1089(a_1098,a_P);a_L1=a_P[0];
a_1089(a_1090,a_P);a_L2=a_P[0];
if(!a_openfile(a_1079,114,a_1077,a_L1)){ goto a_G5;}
if(a_openfile(a_1078,119,a_1077,a_L2)){ goto a_G6;}
a_G5:a_P[0]=2130706080;a_P[1]=a_L2;a_P[2]=a_L1;a_1008(3,3,a_P); return;
a_G6:a_1086();
a_unlinkfile(a_1077,a_L1); return;
} /* movetempfile */
static void a_1109(a_word a_F1){ /* toggleout+>a */

a_1099=a_F1; return;
} /* toggleout */
static void a_1094(void){ /* nextchar */
a_word a_P[1];
a_G1:if(a_equal(a_1099,0)){ goto a_G4;}
if(a_equal(a_1083,1)){ goto a_G4;}
a_putchar(a_1078,a_1083);
a_G4:if(!a_getchar(a_1079,a_P)){ goto a_G7;}a_1083=a_P[0];
{ if(a_1083==10){ goto a_G6;}
 if(a_1083<=31){  goto a_G1;}
  return;}
a_G6:a_incr(a_1108); return;
a_G7:a_1083=1; return;
} /* nextchar */
static void a_1085(void){ /* comment */

a_G1:if(a_equal(a_1083,10)){ return;}
if(a_equal(a_1083,1)){ return;}
a_1094(); goto a_G1;
} /* comment */
static void a_1101(a_word a_A[1]){ /* readdestination+a> */
a_word a_L2;
{ if(a_1083==78){ goto a_G2;}
 if(a_1083==48){ goto a_G15;}
 if(a_1083==45){  goto a_G17;}
  goto a_G30;}
a_G2:a_1094();
{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G8;}
}
a_subtr(a_1083,48,a_A[0]);
a_1094();
if(a_more(a_A[0],0)){ goto a_G9;}
if(a_equal(0,0)){ goto a_G9;}
a_G8:a_1007(a_1001,2130706363); return;
a_G9:{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G13;}
}
a_subtr(a_1083,48,a_L2);
a_1094();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G9;
a_G13:if(!a_is(0)){ return;}
a_G14:a_subtr(0,a_A[0],a_A[0]); return;
a_G15:a_1094();
a_A[0]=0; return;
a_G17:a_1094();
{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G8;}
}
a_subtr(a_1083,48,a_A[0]);
a_1094();
if(a_more(a_A[0],0)){ goto a_G24;}
if(!a_equal(1,0)){ goto a_G8;}
a_G24:{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G28;}
}
a_subtr(a_1083,48,a_L2);
a_1094();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G24;
a_G28:if(!a_is(1)){ return;} goto a_G14;
a_G30:a_1007(a_1001,2130706358); return;
} /* readdestination */
static void a_1087(a_word a_F1,a_word a_A[1]){ /* enterstring+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_L7;a_word a_P[1];
a_subtr(a_F1,2,a_L3);
a_stringhash(a_1077,a_L3,a_P);a_L4=a_P[0];
a_booland(a_L4,2147483647,a_L4);
a_divrem01(a_L4,a_1076,a_L4);
a_add(a_L4,to_LIST(a_1074)->alwb,a_L4);
a_L5=to_LIST(a_1074)->offset[a_L4];
a_G7:if(!a_equal(a_L5,0)){ goto a_G14;}
to_LIST(a_1077)->offset[a_F1-1]=to_LIST(a_1074)->offset[a_L4];
to_LIST(a_1074)->offset[a_L4]=a_F1;a_A[0]=a_F1;
a_incr(a_1075);
if(a_less(a_1075,a_1076)){ return;}
a_add(a_1076,1024,a_1076);
a_1106(); return;
a_G14:a_subtr(a_L5,2,a_L6);
a_comparestring(a_1077,a_L3,a_1077,a_L6,a_P);a_L7=a_P[0];
if(!a_equal(a_L7,0)){ goto a_G18;}
a_A[0]=a_L5; return;
a_G18:a_L5=to_LIST(a_1077)->offset[a_L5-1]; goto a_G7;
} /* enterstring */
static void a_1106(void){ /* rehash */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_1075=0;
a_L1=to_LIST(a_1074)->aupb;
a_G3:if(a_less(a_L1,to_LIST(a_1074)->alwb)){ goto a_G6;}
to_LIST(a_1074)->offset[a_L1]=0;
a_previous(a_1074,a_L1); goto a_G3;
a_G6:a_subtr(to_LIST(a_1074)->aupb,to_LIST(a_1074)->alwb,a_L2);
a_G7:a_incr(a_L2);
if(a_mreq(a_L2,a_1076)){ goto a_G11;}
{register a_word *a_r1=a_extension(a_1074,1);a_r1[0]=0;to_LIST(a_1074)->aupb+=1;}
  goto a_G7;
a_G11:a_L1=to_LIST(a_1077)->aupb;
a_G12:if(a_less(a_L1,to_LIST(a_1077)->alwb)){ return;}
a_1087(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,a_L1)){ goto a_G17;}
a_previous(a_1077,a_L1);
a_previousstring(a_1077,a_L1); goto a_G12;
a_G17:a_1010(a_1001,2130706352); return;
} /* rehash */
static void a_1071(void){ /* @root */

a_1106(); return;
} /* @root */
static void a_1089(a_word a_F1,a_word a_A[1]){ /* gettagimage+>a+a> */

a_subtr(a_F1,2,a_A[0]); return;
} /* gettagimage */
static void a_1082(a_word a_A[1]){ /* addLEXTentry+a> */
a_word a_P[1];
{register a_word *a_r1=a_extension(a_1077,2);a_r1[0]=a_r1[1]=0;to_LIST(a_1077)->aupb+=2;}
a_1087(to_LIST(a_1077)->aupb,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],to_LIST(a_1077)->aupb)){ return;}
a_unstack(a_1077);
a_unstackstring(a_1077); return;
} /* addLEXTentry */
static void a_1102(a_word a_A[1]){ /* readstring+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1073)->aupb;
a_L2=0;
a_G3:a_1094();
{ if(a_1083==34){ goto a_G5;}
 if(a_1083==10||a_1083==1){  goto a_G14;}
  goto a_G7;}
a_G5:a_1094();
if(!a_equal(a_1083,34)){ goto a_G9;}
a_G7:a_1088(a_1083);
a_incr(a_L2); goto a_G3;
a_G9:if(!a_equal(a_L2,0)){ goto a_G11;}
a_A[0]=173364799; return;
a_G11:a_packstring(a_1073,a_L2,a_1077);
a_unstackto(a_1073,a_L3);
a_1082(a_P);a_A[0]=a_P[0]; return;
a_G14:a_1007(a_1001,2130706348); return;
} /* readstring */
static void a_1104(a_word a_A[1]){ /* readtargetstring+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1073)->aupb;
a_L2=0;
if(a_equal(a_1083,34)){ goto a_G5;}
a_G4:a_1007(a_1001,2130706343); return;
a_G5:a_1094();
{ if(a_1083==34){ goto a_G7;}
 if(a_1083==10||a_1083==1){  goto a_G4;}
  goto a_G9;}
a_G7:a_1094();
if(!a_equal(a_1083,34)){ goto a_G11;}
a_G9:a_1088(a_1083);
a_incr(a_L2); goto a_G5;
a_G11:if(!a_equal(a_L2,0)){ goto a_G13;}
a_A[0]=173364799; return;
a_G13:a_packstring(a_1073,a_L2,a_1077);
a_unstackto(a_1073,a_L3);
a_1082(a_P);a_A[0]=a_P[0]; return;
} /* readtargetstring */
static void a_1103(a_word a_A[1]){ /* readtargetnumber+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1073)->aupb;
a_L2=1;
a_1088(88);
if(!a_equal(a_1083,45)){ goto a_G8;}
a_1088(a_1083);
a_incr(a_L2);
a_1094();
a_G8:{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G12;}
}
a_1088(a_1083);
a_incr(a_L2);
a_1094(); goto a_G8;
a_G12:a_packstring(a_1073,a_L2,a_1077);
a_unstackto(a_1073,a_L3);
a_1082(a_P);a_A[0]=a_P[0]; return;
} /* readtargetnumber */
static void a_1100(a_word a_A[1]){ /* readbold+a> */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1094();
a_L3=to_LIST(a_1073)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1083 && a_1083<=122))){ goto a_G9;}
}
a_L4=a_1083;
a_1094();
a_1088(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1083,39)){ goto a_G11;}
a_1094(); goto a_G12;
a_G11:a_1007(a_1001,2130706336); return;
a_G12:a_packstring(a_1073,a_L2,a_1077);
a_unstackto(a_1073,a_L3);
a_A[0]=16777295;
a_G15:a_comparestring(a_1072,a_A[0],a_1077,to_LIST(a_1077)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G20;}
if(a_equal(a_A[0],16777220)){ goto a_G11;}
a_previousstring(a_1072,a_A[0]); goto a_G15;
a_G20:a_unstackstring(a_1077); return;
} /* readbold */
static void a_1105(a_word a_A[1]){ /* readtype+a> */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1094();
a_L3=to_LIST(a_1073)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1083 && a_1083<=122))){ goto a_G9;}
}
a_L4=a_1083;
a_1094();
a_1088(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1083,32)){ goto a_G13;}
a_1088(32);
a_incr(a_L2);
a_1094(); goto a_G4;
a_G13:if(!a_equal(a_1083,62)){ goto a_G15;}
a_1094(); goto a_G16;
a_G15:a_1007(a_1001,2130706331); return;
a_G16:a_packstring(a_1073,a_L2,a_1077);
a_unstackto(a_1073,a_L3);
a_A[0]=16777390;
a_G19:a_comparestring(a_1072,a_A[0],a_1077,to_LIST(a_1077)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G24;}
if(a_equal(a_A[0],16777300)){ goto a_G15;}
a_previousstring(a_1072,a_A[0]); goto a_G19;
a_G24:a_unstackstring(a_1077); return;
} /* readtype */
static void a_1095(void){ /* nextsymbol */
a_word a_L1;a_word a_P[1];
a_G1:{ if(a_1083==32||a_1083==10){ goto a_G2;}
 if(a_1083==36){ goto a_G3;}
 if(a_1083==48){ goto a_G4;}
 if((49<=a_1083 && a_1083<=57)){ goto a_G7;}
 if(a_1083==70){ goto a_G20;}
 if(a_1083==73){ goto a_G34;}
 if(a_1083==76){ goto a_G49;}
 if(a_1083==78){ goto a_G63;}
 if(a_1083==88){ goto a_G77;}
 if(a_1083==84){ goto a_G80;}
 if(a_1083==39){ goto a_G83;}
 if(a_1083==60){ goto a_G84;}
 if(a_1083==34){ goto a_G86;}
 if(a_1083==38){ goto a_G88;}
 if(a_1083==93){ goto a_G90;}
 if(a_1083==41){ goto a_G92;}
 if(a_1083==58){ goto a_G94;}
 if(a_1083==44){ goto a_G96;}
 if(a_1083==126){ goto a_G98;}
 if(a_1083==47){ goto a_G100;}
 if(a_1083==45){ goto a_G102;}
 if(a_1083==35){ goto a_G119;}
 if(a_1083==40){ goto a_G121;}
 if(a_1083==124){ goto a_G123;}
 if(a_1083==62){ goto a_G125;}
 if(a_1083==43){ goto a_G128;}
 if(a_1083==46){ goto a_G130;}
 if(a_1083==59){ goto a_G132;}
 if(a_1083==42){ goto a_G134;}
 if(a_1083==91){ goto a_G136;}
 if(a_1083==94){ goto a_G138;}
 if(a_1083==64){ goto a_G140;}
 if(a_1083==1){  goto a_G142;}
  goto a_G143;}
a_G2:a_1094(); goto a_G1;
a_G3:a_1085(); goto a_G1;
a_G4:a_1091=16777454;
a_1092=0;
a_G6:a_1094(); return;
a_G7:a_1091=16777454;
{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G13;}
}
a_subtr(a_1083,48,a_1092);
a_1094();
if(a_more(a_1092,0)){ goto a_G14;}
if(a_equal(0,0)){ goto a_G14;}
a_G13:a_1007(a_1001,2130706363); return;
a_G14:{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G18;}
}
a_subtr(a_1083,48,a_L1);
a_1094();
a_addmult(a_1092,10,a_L1,a_1092); goto a_G14;
a_G18:if(!a_is(0)){ return;}
a_G19:a_subtr(0,a_1092,a_1092); return;
a_G20:a_1091=16777478;
a_1094();
{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G13;}
}
a_subtr(a_1083,48,a_1092);
a_1094();
if(a_more(a_1092,0)){ goto a_G28;}
if(!a_equal(0,0)){ goto a_G13;}
a_G28:{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G18;}
}
a_subtr(a_1083,48,a_L1);
a_1094();
a_addmult(a_1092,10,a_L1,a_1092); goto a_G28;
a_G34:a_1091=16777474;
a_1094();
{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G13;}
}
a_subtr(a_1083,48,a_1092);
a_1094();
if(a_more(a_1092,0)){ goto a_G42;}
if(!a_equal(0,0)){ goto a_G13;}
a_G42:{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G46;}
}
a_subtr(a_1083,48,a_L1);
a_1094();
a_addmult(a_1092,10,a_L1,a_1092); goto a_G42;
a_G46:if(!a_is(0)){ goto a_G48;}
a_subtr(0,a_1092,a_1092);
a_G48:a_P[0]=a_1092;a_1020(a_P);a_1092=a_P[0]; return;
a_G49:a_1091=16777482;
a_1094();
{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G13;}
}
a_subtr(a_1083,48,a_1092);
a_1094();
if(a_more(a_1092,0)){ goto a_G57;}
if(!a_equal(0,0)){ goto a_G13;}
a_G57:{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G18;}
}
a_subtr(a_1083,48,a_L1);
a_1094();
a_addmult(a_1092,10,a_L1,a_1092); goto a_G57;
a_G63:a_1091=16777470;
a_1094();
{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G13;}
}
a_subtr(a_1083,48,a_1092);
a_1094();
if(a_more(a_1092,0)){ goto a_G71;}
if(!a_equal(0,0)){ goto a_G13;}
a_G71:{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G18;}
}
a_subtr(a_1083,48,a_L1);
a_1094();
a_addmult(a_1092,10,a_L1,a_1092); goto a_G71;
a_G77:a_1091=16777458;
a_1094();
a_1103(a_P);a_1092=a_P[0]; return;
a_G80:a_1091=16777462;
a_1094();
a_1104(a_P);a_1092=a_P[0]; return;
a_G83:a_1100(a_P);a_1091=a_P[0]; return;
a_G84:a_1091=16777466;
a_1105(a_P);a_1092=a_P[0]; return;
a_G86:a_1091=16777486;
a_1102(a_P);a_1092=a_P[0]; return;
a_G88:a_1091=16777396; goto a_G6;
a_G90:a_1091=16777399; goto a_G6;
a_G92:a_1091=16777402; goto a_G6;
a_G94:a_1091=16777405; goto a_G6;
a_G96:a_1091=16777408; goto a_G6;
a_G98:a_1091=16777411; goto a_G6;
a_G100:a_1091=16777414; goto a_G6;
a_G102:a_1094();
{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G117;}
}
a_1091=16777454;
{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G13;}
}
a_subtr(a_1083,48,a_1092);
a_1094();
if(a_more(a_1092,0)){ goto a_G111;}
if(!a_equal(1,0)){ goto a_G13;}
a_G111:{ if(!((48<=a_1083 && a_1083<=57))){ goto a_G115;}
}
a_subtr(a_1083,48,a_L1);
a_1094();
a_addmult(a_1092,10,a_L1,a_1092); goto a_G111;
a_G115:if(!a_is(1)){ return;} goto a_G19;
a_G117:a_1091=16777417;
a_1092=0; return;
a_G119:a_1091=16777423; goto a_G6;
a_G121:a_1091=16777426; goto a_G6;
a_G123:a_1091=16777429; goto a_G6;
a_G125:a_1091=16777432;
a_1094();
a_1101(a_P);a_1092=a_P[0]; return;
a_G128:a_1091=16777435; goto a_G6;
a_G130:a_1091=16777438; goto a_G6;
a_G132:a_1091=16777441; goto a_G6;
a_G134:a_1091=16777444; goto a_G6;
a_G136:a_1091=16777447; goto a_G6;
a_G138:a_1091=16777450; goto a_G6;
a_G140:a_1091=16777393; goto a_G6;
a_G142:a_1091=16777489; return;
a_G143:a_1007(a_1001,2130706326); return;
} /* nextsymbol */
static void a_1112(a_word a_F1){ /* writenum+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G5;}
a_putchar(a_1078,45);
a_subtr(-1,a_F1,a_F1);
a_1111(a_F1,49); return;
a_G5:if(!a_less(a_F1,0)){ goto a_G9;}
a_putchar(a_1078,45);
a_getabs(a_F1,a_F1);
a_1111(a_F1,48); return;
a_G9:a_1111(a_F1,48); return;
} /* writenum */
static void a_1111(a_word a_F1,a_word a_F2){ /* wnum1+>a+>a */
a_word a_L3;a_word a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1111(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_putchar(a_1078,a_L4); return;
} /* wnum1 */
static void a_1114(void){ /* wspace */

if(a_is(a_1113)){ return;}
a_putchar(a_1078,32);
a_1113=1; return;
} /* wspace */
static void a_1080(a_word a_F1){ /* W+>a */

if(!a_equal(a_F1,16777420)){ goto a_G4;}
a_1113=1;
a_putchar(a_1078,10); return;
a_G4:if(!a_lseq(16777220,a_F1)){ goto a_G10;}
if(!a_lseq(a_F1,16777295)){ goto a_G10;}
a_putchar(a_1078,39);
a_1132(a_1078,a_1072,a_F1);
a_putchar(a_1078,39);
a_G9:a_1113=1; return;
a_G10:if(!a_lseq(16777300,a_F1)){ goto a_G16;}
if(!a_lseq(a_F1,16777390)){ goto a_G16;}
a_putchar(a_1078,60);
a_1132(a_1078,a_1072,a_F1);
a_putchar(a_1078,62);
a_1113=0; return;
a_G16:if(!a_was(a_1072,a_F1)){ goto a_G19;}
a_1132(a_1078,a_1072,a_F1); goto a_G9;
a_G19:a_1010(a_1001,2130706321); return;
} /* W */
static void a_1081(a_word a_F1,a_word a_F2){ /* WW+>a+>a */
a_word a_P[1];
{ if(a_F1==16777454){ goto a_G2;}
 if(a_F1==16777466){ goto a_G5;}
 if(a_F1==16777486){ goto a_G6;}
 if(a_F1==16777432){ goto a_G10;}
 if(a_F1==16777478){ goto a_G16;}
 if(a_F1==16777482){ goto a_G20;}
 if(a_F1==16777470){ goto a_G24;}
 if(a_F1==16777458){ goto a_G27;}
 if(a_F1==16777462){ goto a_G31;}
 if(a_F1==16777474){  goto a_G35;}
  goto a_G40;}
a_G2:a_1114();
a_G3:a_1112(a_F2);
a_G4:a_1113=0; return;
a_G5:a_1080(a_F2); return;
a_G6:a_1114();
a_1089(a_F2,a_P);a_F2=a_P[0];
a_1130(a_1078,a_1077,a_F2); goto a_G4;
a_G10:a_1114();
a_putchar(a_1078,62);
if(a_lseq(a_F2,0)){ goto a_G3;}
a_putchar(a_1078,78); goto a_G3;
a_G16:a_1114();
a_putchar(a_1078,70); goto a_G3;
a_G20:a_1114();
a_putchar(a_1078,76); goto a_G3;
a_G24:a_putchar(a_1078,78); goto a_G3;
a_G27:a_1114();
a_1089(a_F2,a_P);a_F2=a_P[0];
a_1132(a_1078,a_1077,a_F2); goto a_G4;
a_G31:a_1114();
a_putchar(a_1078,84);
a_1113=1;
a_1081(16777486,a_F2); return;
a_G35:a_1114();
a_putchar(a_1078,73);
a_1050(a_F2,a_P);a_F2=a_P[0]; goto a_G3;
a_G40:a_1010(a_1001,2130706318); return;
} /* WW */
static a_word a_1120(a_word a_F1,a_word a_F2){ /* isfirstarg+t[]+>a */
a_word a_L2;a_word a_P[1];
a_comparestring(a_1134,a_1116,a_F1,a_F2,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return 0;} return 1;
} /* isfirstarg */
static void a_1123(void){ /* parseSTDARG */
a_word a_P[3];
a_1116=to_LIST(a_1134)->aupb;
a_G2:if(a_less(a_1116,to_LIST(a_1134)->alwb)){ return;}
if(!a_1120(a_1001,2130706396)){ goto a_G5;}
a_P[0]=2130706134;a_1008(1,1,a_P); return;
a_G5:if(!a_1120(a_1001,2130706392)){ goto a_G7;}
a_P[0]=2130706203;a_P[1]=1;a_P[2]=1;a_1008(1,3,a_P); return;
a_G7:if(!a_1120(a_1001,2130706387)){ goto a_G10;}
a_previousstring(a_1134,a_1116);
a_1125=1; goto a_G2;
a_G10:if(!a_is(a_1122)){ goto a_G12;}
a_P[0]=2130706245;a_1008(1,1,a_P); return;
a_G12:if(!a_is(a_1119)){ goto a_G15;}
a_1122=a_1116;
a_G14:a_previousstring(a_1134,a_1116); goto a_G2;
a_G15:a_1119=a_1116; goto a_G14;
} /* parseSTDARG */
static void a_1117(void){ /* checkcommandlinearguments */
a_word a_P[1];
a_1123();
if(!a_equal(a_1119,0)){ goto a_G4;}
a_P[0]=2130706217;a_1008(1,1,a_P); return;
a_G4:if(!a_equal(a_1122,0)){ goto a_G7;}
if(a_is(a_1125)){ return;}
a_P[0]=2130706231;a_1008(1,1,a_P); return;
a_G7:if(!a_is(a_1125)){ return;}
a_P[0]=2130706245;a_1008(1,1,a_P); return;
} /* checkcommandlinearguments */
static void a_1127(a_word a_F1){ /* setrepr+>a */

if(!a_1052(a_F1,128)){ return;}
to_LIST(a_1018)->offset[a_F1]=a_1121;
a_incr(a_1121); return;
} /* setrepr */
static void a_1124(void){ /* renumberitems */
a_word a_L1;
a_L1=to_LIST(a_1018)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1018)->aupb)){ return;}
a_1127(a_L1);
a_next(a_1018,a_L1); goto a_G2;
} /* renumberitems */
static void a_1118(void){ /* firstpass */

a_1051();
a_1054();
a_1041();
a_1062(); return;
} /* firstpass */
static void a_1126(void){ /* secondpass */

a_1031();
a_1034();
a_1021();
a_1040(); return;
} /* secondpass */
static void a_1115(void){ /* @root */

a_1117();
a_1096(a_1119);
a_1118();
a_1069();
a_1124();
a_1107(a_1122,2130706252);
a_1126();
a_1084(); return;
} /* @root */
static void a_1130(a_word a_F1,a_word a_F2,a_word a_F3){ /* putasstring+""f+t[]+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L2=0;
a_putchar(a_F1,34);
a_G3:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){ goto a_G8;}a_L3=a_P[0];
a_incr(a_L2);
if(!a_equal(a_L3,34)){ goto a_G7;}
a_putchar(a_F1,a_L3);
a_G7:a_putchar(a_F1,a_L3); goto a_G3;
a_G8:a_putchar(a_F1,34); return;
} /* putasstring */
static void a_1132(a_word a_F1,a_word a_F2,a_word a_F3){ /* putstring+""f+t[]+>a */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L2=0;
a_G2:if(!a_stringelem(a_F2,a_F3,a_L2,a_P)){ return;}a_L3=a_P[0];
a_incr(a_L2);
a_putchar(a_F1,a_L3); goto a_G2;
} /* putstring */
a_PROFILE *a_profiles=NULL;
/* EOF */
