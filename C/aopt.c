/* ALEPH ice linker v2.1, word size=32 */

// linked modules:
// error "optimizer error v2.2"
// item "optimizer item v2.2"
// lexical "optimizer lexical v2.2"
// @main "ALEPH optimizer, v2.2"
// item "optimizer node v2.2"
// stdlib "stdlib base"
// stdlib "stdlib put as string"
// stdlib "stdlib put string"
// stdlib "stdlib stdarg"
// stdlib "stdlib stdhash"
#include "aleph_core.h"
static void a_stringhash(int,int,int[1]);static void a_blockhash(int,int,int[1]);
static void a_setup_stdarg(int,const char*,int);
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
static void a_1041(void); /* copyruleswithoptimization */
static void a_1042(void); /* copyruleswithoutoptimization */
static void a_1043(void); /* datasection */
static void a_1044(void); /* expandITEM */
static void a_1045(a_word a_F1); /* fileareas */
static void a_1046(void); /* fileentry */
static void a_1047(void); /* fillentry */
static void a_1048(a_word a_F1); /* fillinitializers */
static void a_1049(a_word a_F1); /* fillitem */
static void a_1050(a_word a_F1); /* fillitempack */
static void a_1051(a_word a_F1); /* fillrepeater */
static void a_1052(a_word a_F1,a_word a_A[1]); /* getitemrepr */
static void a_1053(void); /* handlenode */
static void a_1054(a_word a_F1); /* handlerule */
static void a_1055(void); /* headsection */
static a_word a_1056(a_word a_F1,a_word a_F2); /* isitemflag */
static a_word a_1057(a_word a_F1,a_word a_F2); /* ispulleditem */
static void a_1058(void); /* itemsection */
static void a_1059(void); /* listentry */
static void a_1060(a_word a_F1); /* markifrequested */
static a_word a_1061=0; /* nextitem */
static a_word a_1062=1; /* nodeoptimization */
static void a_1063(void); /* readexpression */
static void a_1064(void); /* readitem */
static void a_1065(a_word a_F1); /* readnode */
static void a_1066(void); /* readrule */
static void a_1067(void); /* rulesection */
static void a_1068(a_word a_F1,a_word a_F2); /* setitemflag */
static void a_1069(void); /* skipentry */
static void a_1070(void); /* skipformalaffixes */
static void a_1071(a_word a_F1); /* skipitem */
static void a_1072(void); /* skiplistbounds */
static void a_1073(a_word a_F1,a_word a_A[1]); /* traverseitem */
static void a_1074(void); /* traverseitems */
static void a_1075(a_word a_A[1]); /* traverseonce */
#define a_1077 (a_1018+sizeof_LIST) /* BOLD */
#define a_1078 (a_1077+sizeof_LIST) /* BUFFER */
#define a_1079 (a_1078+sizeof_LIST) /* HASH */
static a_word a_1080=1; /* HASHentries */
static a_word a_1081=1023; /* HASHsize */
#define a_1082 (a_1079+sizeof_LIST) /* LEXT */
#define a_1083 (a_1082+sizeof_LIST) /* RESULT */
#define a_1084 (a_1083+sizeof_CHFILE) /* SOURCE */
static void a_1085(a_word a_F1); /* W */
static void a_1086(a_word a_F1,a_word a_F2); /* WW */
static void a_1087(a_word a_A[1]); /* addLEXTentry */
static a_word a_1088=32; /* char */
static void a_1089(void); /* closesource */
static void a_1090(void); /* comment */
static void a_1091(void); /* copysourcetoresult */
static void a_1092(a_word a_F1,a_word a_A[1]); /* enterstring */
static void a_1093(a_word a_F1); /* extendBUFFER */
static void a_1094(a_word a_F1,a_word a_A[1]); /* gettagimage */
static a_word a_1095=0; /* inf */
static a_word a_1096=0; /* inpt */
static a_word a_1097=0; /* inptvalue */
static void a_1098(void); /* movetempfile */
static void a_1099(void); /* nextchar */
static void a_1100(void); /* nextsymbol */
static void a_1101(a_word a_F1); /* opensource */
static void a_1102(a_word a_F1); /* opensourcefile */
static a_word a_1103=0; /* outf */
static a_word a_1104=0; /* output */
static void a_1105(a_word a_A[1]); /* readbold */
static void a_1106(a_word a_A[1]); /* readdestination */
static void a_1107(a_word a_A[1]); /* readstring */
static void a_1108(a_word a_A[1]); /* readtargetnumber */
static void a_1109(a_word a_A[1]); /* readtargetstring */
static void a_1110(a_word a_A[1]); /* readtype */
static void a_1111(void); /* rehash */
static void a_1112(a_word a_F1,a_word a_F2); /* rewindsource */
static a_word a_1113=1; /* sourceline */
static void a_1114(a_word a_F1); /* toggleout */
static void a_1115(a_word a_A[1]); /* trytoopen */
static void a_1116(a_word a_F1,a_word a_F2); /* wnum1 */
static void a_1117(a_word a_F1); /* writenum */
static a_word a_1118=1; /* wsep */
static void a_1119(void); /* wspace */
static a_word a_1121=0; /* argtop */
static void a_1122(void); /* checkcommandlinearguments */
static void a_1123(void); /* firstpass */
static a_word a_1124=0; /* ifile */
static a_word a_1125(a_word a_F1,a_word a_F2); /* isfirstarg */
static a_word a_1126=1; /* nextID */
static a_word a_1127=0; /* ofile */
static void a_1128(void); /* parseSTDARG */
static void a_1129(void); /* renumberitems */
static a_word a_1130=0; /* replacearg */
static void a_1131(void); /* secondpass */
static void a_1132(a_word a_F1); /* setrepr */
#define a_1134 (a_1084+sizeof_CHFILE) /* AUX */
static void a_1135(a_word a_F1); /* N */
static void a_1136(a_word a_F1,a_word a_F2); /* NN */
#define a_1137 (a_1134+sizeof_LIST) /* NODE */
static a_word a_1138(a_word a_F1); /* checknode */
static void a_1139(a_word a_F1,a_word a_F2); /* dumpAUX */
static void a_1140(void); /* dumprule */
static void a_1141(void); /* enternode */
static void a_1142(a_word a_F1,a_word a_A[1]); /* getnoderepr */
static a_word a_1143=0; /* nnode */
static void a_1144(a_word a_F1); /* pushAUX */
static void a_1145(void); /* renumbernodes */
static void a_1146(void); /* replaceall */
static void a_1147(a_word a_F1,a_word a_F2); /* replacenode */
static a_word a_1148(a_word a_F1,a_word a_F2); /* samecontent */
static void a_1149(a_word a_F1,a_word a_F2); /* startnode */
static void a_1150(a_word a_F1); /* startrule */
static a_word a_1151=0; /* thisnode */
static a_word a_1152=0; /* xnode */
static void a_1155(a_word a_F1,a_word a_F2,a_word a_F3); /* putasstring */
static void a_1157(a_word a_F1,a_word a_F2,a_word a_F3); /* putstring */
#define a_1159 (a_1137+sizeof_LIST) /* STDARG */
static void a_1120(void); /* @main root */
static void a_1076(void); /* lexical root */
#define BLOCK_TOTAL (a_1159+sizeof_LIST)
a_word a_DATABLOCK[BLOCK_TOTAL];
static a_word a_FILL[]={ /* fill table */
a_1001,/* @StringTable */
9,1953723757,0,4,4,1953709116,1953853284,15934,10,5,0,
a_1006,/* MESSAGE */
28,1920102211,544501877,1920298867,773875043,543515497,1701603686,1768693804,622880110,1915232356,543517813,2715685,43,13,1702129257,1818324594,1920099616,1629516399,1768693876,622880110,1718558820,1970238240,543515506,1701013806,1970415648,622880108,10608,50,15,0,
a_1001,/* @StringTable */
66,1953723757,0,4,4,2037411683,1701606770,1953068915,1953525608,2053729641,1869182049,110,25,9,2037411683,1701606770,1953068915,1953853288,1769238639,1635412333,1852795252,0,28,10,1701606770,1952671091,7237481,11,5,1635017060,1952671091,7237481,11,5,1684104562,1919973477,1769173861,28271,14,6,1885956979,1920233061,121,9,5,2037411683,1835365481,0,8,5,1885956979,1835365481,0,8,5,1684104562,1835365481,0,8,5,1885956979,1836216166,1717660769,1702390118,115,17,7,0,
a_1082,/* LEXT */
6,1869574720,116,5,4,0,0,0,
a_1001,/* @StringTable */
63,22359,2,3,87,1,3,1954047342,1651341683,27759,10,5,1684104562,1701869940,0,8,5,1684104562,1684828002,0,8,5,1684104562,1735549300,1953723493,1735289202,0,16,7,1684104562,1769108595,26478,10,5,1634231666,26739,6,4,1684104562,1953719652,1952542313,7237481,15,6,1684104562,1701080681,120,9,5,1769238639,1702521197,2020879972,116,13,6,1885695073,1667837544,101,9,5,1953723757,0,4,4,0,
a_1006,/* MESSAGE */
46,1852727619,1864397935,544105840,1970302569,1768300660,622880108,115,25,9,1852727619,1663071343,1952540018,1970217061,1953853556,1818846752,1931812965,0,28,10,1852727619,1663071343,1952540018,1702109285,1919905901,544830049,1701603686,0,28,10,1869771333,1701978226,1667329136,543649385,1701603686,746071328,1936028192,544500853,1629516649,2015699060,0,40,13,1701013806,0,4,4,0,
a_1082,/* LEXT */
5,0,0,3,0,0,0,
a_1077,/* BOLD */
273,1634038369,0,4,4,1801675106,0,4,4,7892834,3,3,1768710499,6648418,7,4,1919973477,1769173861,28271,10,5,1702131813,1869181806,110,9,5,1702131813,1818324594,0,8,5,1701603686,0,4,4,1819044198,0,4,4,1852797542,116,5,4,1953720684,0,4,4,6453100,3,3,1852399981,0,4,4,1969516397,25964,6,4,1701080942,0,4,4,1701606770,0,4,4,28532,2,3,6451317,3,3,1651993718,0,4,4,1651537270,0,4,4,1936617315,1953390964,0,8,5,1769103734,1701601889,0,8,5,1952543859,1981834089,29281,10,5,1818386804,101,5,4,1667331187,107,5,4,1952543859,1931502441,1801675124,0,12,6,1852403568,544367988,1936617315,1953390964,0,16,7,1918986339,1701603686,0,8,5,1635017060,1701603686,0,8,5,1701606770,0,4,4,1836216166,1931504737,1801675124,0,12,6,1836216166,1948281953,1701601889,0,12,6,1836216166,1713400929,6646889,11,5,1836216166,1763732577,110,9,5,1836216166,1864395873,29813,10,5,1836216166,1763732577,1953853294,0,12,6,1836216166,1629514849,1869112174,114,13,6,1836216166,1931504737,1952868712,0,12,6,64,1,3,38,1,3,93,1,3,41,1,3,58,1,3,44,1,3,126,1,3,47,1,3,45,1,3,28197,2,3,35,1,3,40,1,3,124,1,3,62,1,3,43,1,3,46,1,3,59,1,3,42,1,3,91,1,3,94,1,3,1936617315,116,5,4,1651340654,29285,6,4,1920234356,0,4,4,1701869940,0,4,4,1701080942,0,4,4,1835365481,0,4,4,1836216166,27745,6,4,1633906540,108,5,4,1769108595,26478,6,4,2763306,3,3,0,
a_1001,/* @StringTable */
24,1953723757,0,4,4,1869491501,1819636269,1953525605,0,12,6,1701981485,1667329136,101,9,5,1702243629,1869181810,110,9,5,1701326125,28780,6,4,0,
a_1006,/* MESSAGE */
189,1769238607,1702521197,544104736,1346718785,541928776,1701013806,1818846752,1433281893,1701273971,1868636218,1528853616,1701326125,2082500716,1982672160,1769173605,626880111,538976366,540701295,1953525601,757947168,1915580270,1868917877,542995568,1701981485,1667329136,1765548133,1953853550,544089406,1919885344,1868636218,1528853616,1869491501,1819636269,1953525605,1765548125,1953853550,1866211390,1970304117,1847934580,1752459607,757932576,1819305330,577069921,1852390432,1047819632,544434464,1819305330,1684366177,1953068832,1752440936,1886330981,1768778100,543450490,1936876918,778989417,1750363685,1818632293,572548961,1869491501,1819636269,1953525605,1852383266,1768057192,1914729332,543517813,1886220131,1936942450,778989417,0,272,71,1346718785,541928776,1701013806,1953525536,2053729641,1981837925,1769173605,622882415,1680158308,1866690085,1769109872,544499815,539575080,808595506,842019373,1632378933,1869380211,1769161504,2053205362,1750363685,1763734377,543236211,1701147238,1718580000,1918990196,1931488357,1948280165,1931502952,1668445551,1952522341,1953785888,792359792,1953064751,778204520,795701091,1769169772,2053205362,1701601583,1847945328,544370534,2037411683,1751607666,1852383348,1836216166,1869182049,1411395182,1701995880,544434464,1461735246,1095914049,995710030,1953459744,1702257952,1701650542,1851877475,1768057204,2037672300,628256544,1953064558,1936942446,1919903264,1881170208,1769239137,1634497891,1970282610,1936683122,11877,266,69,1936943437,543649385,1969713761,1953391981,1937055788,757932133,1886152040,1919903264,1931501856,1953656680,1818585120,112,45,14,1936943437,543649385,1953853244,1047819632,1937055788,757932133,1886152040,1919903264,1931501856,1953656680,1818585120,112,45,14,544173908,2037277037,1735549216,1852140917,539784052,543519605,1701326125,1713401964,1629516399,1869116192,1746957426,7367781,47,14,1886221359,1701601583,1479370864,1482184792,88,17,7,0,
a_1001,/* @StringTable */
22,1953723757,0,4,4,1819305330,1852138337,6644847,11,5,1702129253,1685024370,101,9,5,20046,2,3,1918989427,1685024372,101,9,5,0,
-1}; /* fill table size 764 */
static void a_data_setup(void){
 a_virtual_min=16777216;a_virtual_max=2130706432;
 a_setup_list(0,a_1001,"@StringTable",1,2130706188,2130706371,184); /* @StringTable */
 a_setup_list(0,a_1006,"MESSAGE",1,2130705924,2130706186,263); /* MESSAGE */
 a_setup_list(1,a_1017,"AUX",2,1273707916,1559373914,0); /* AUX */
 a_setup_list(1,a_1018,"ITEM",7,1559373923,2130705916,0); /* ITEM */
 a_setup_list(0,a_1077,"BOLD",1,588109226,588109498,273); /* BOLD */
 a_setup_list(1,a_1078,"BUFFER",1,645242701,702375900,0); /* BUFFER */
 a_setup_list(1,a_1079,"HASH",1,588109500,645242699,0); /* HASH */
 a_setup_list(1,a_1082,"LEXT",2,702375903,1273707912,11); /* LEXT */
 a_setup_list(1,a_1134,"AUX",1,16777217,302443216,0); /* AUX */
 a_setup_list(1,a_1137,"NODE",8,302443225,588109217,0); /* NODE */
 a_setup_stdarg(a_1159,"STDARG",1);
 a_setup_charfile(a_1005,"ERRFILE",2,a_1001,2130706196); /* ERRFILE */
 a_setup_charfile(a_1083,"RESULT",2,a_1001,2130706316); /* RESULT */
 a_setup_charfile(a_1084,"SOURCE",1,a_1001,2130706321); /* SOURCE */
 a_list_fill(a_FILL);
}
static void a_waitfor(a_word a_F1,a_word a_F2){
 a_MODROOT(a_1076,"lexical")
}
void a_ROOT(void){
 a_data_setup();
 a_waitfor(0,0);
 a_1120();
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
a_G5:if(!a_less(a_F1,0)){ goto a_G8;}
a_1013(45);
a_getabs(a_F1,a_F1);
a_G8:a_1015(a_F1,48); return;
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

a_1157(a_1005,a_F1,a_F2); return;
} /* print */
static void a_1009(a_word a_F1,a_word a_C,a_word *a_V){ /* formatprint+t[]+@+>a */
a_word a_L2;a_word a_L3;
a_L2=to_LIST(a_1078)->aupb;
a_unpackstring(a_1006,a_V[0],a_1078);
a_add(a_L2,1,a_L3);
a_G4:if(a_less(to_LIST(a_1078)->aupb,a_L3)){ goto a_G21;}
if(!a_noteq(to_LIST(a_1078)->offset[a_L3],37)){ goto a_G8;}
a_G6:a_1013(to_LIST(a_1078)->offset[a_L3]);
a_G7:a_incr(a_L3); goto a_G4;
a_G8:a_incr(a_L3);
if(!a_less(to_LIST(a_1078)->aupb,a_L3)){ goto a_G11;}
a_1013(37); goto a_G21;
a_G11:{register a_word a_r1=to_LIST(a_1078)->offset[a_L3];
 if(a_r1==112){ goto a_G12;}
 if(a_r1==115){ goto a_G14;}
 if(a_r1==120){ goto a_G16;}
 if(a_r1==100){ goto a_G18;}
 if(a_r1==110){  goto a_G20;}
  goto a_G6;}
a_G12:if(a_C<=1){ goto a_G7;} a_C--;a_V+=1;
a_1012(a_F1,a_V[0]); goto a_G7;
a_G14:if(a_C<=1){ goto a_G7;} a_C--;a_V+=1;
a_1012(a_1159,a_V[0]); goto a_G7;
a_G16:if(a_C<=1){ goto a_G7;} a_C--;a_V+=1;
a_1012(a_1082,a_V[0]); goto a_G7;
a_G18:if(a_C<=1){ goto a_G7;} a_C--;a_V+=1;
a_1014(a_V[0]); goto a_G7;
a_G20:a_1011(); goto a_G7;
a_G21:a_unstackto(a_1078,a_L2); return;
} /* formatprint */
static void a_1008(a_word a_F1,a_word a_C,a_word *a_V){ /* error+>a+@+>a */

a_1009(a_1006,a_C,a_V);
a_1011();
a_exit(a_F1); return;
} /* error */
static void a_1007(a_word a_F1,a_word a_F2){ /* corrupticefile+t[]+>a */
a_word a_P[3];
a_P[0]=2130705936;a_P[1]=a_1113;a_P[2]=a_F2;a_1009(a_F1,3,a_P);
a_1011();
a_exit(1); return;
} /* corrupticefile */
static void a_1010(a_word a_F1,a_word a_F2){ /* internalerror+t[]+>a */
a_word a_P[3];
a_P[0]=2130705951;a_P[1]=a_1113;a_P[2]=a_F2;a_1009(a_F1,3,a_P);
a_1011();
a_exit(15); return;
} /* internalerror */
static a_word a_1057(a_word a_F1,a_word a_F2){ /* ispulleditem+>a+>a */
a_word a_L3;
a_L3=to_LIST(a_1018)->offset[a_F1-1];
a_G2:if(a_equal(a_L3,0)){ return 0;}
if(a_equal(to_LIST(a_1017)->offset[a_L3-1],a_F2)){ return 1;}
a_L3=to_LIST(a_1017)->offset[a_L3]; goto a_G2;
} /* ispulleditem */
static void a_1019(a_word a_F1,a_word a_F2){ /* addpull+>a+>a */

if(a_1057(a_F1,a_F2)){ return;}
{register a_word *a_r1=a_extension(a_1017,2);a_r1[0]=a_F2;a_r1[1]=to_LIST(a_1018)->offset[a_F1-1];to_LIST(a_1017)->aupb+=2;}
to_LIST(a_1018)->offset[a_F1-1]=to_LIST(a_1017)->aupb; return;
} /* addpull */
static void a_1044(void){ /* expandITEM */

a_incr(a_1061);
{register a_word *a_r1=a_extension(a_1018,7);a_r1[0]=a_r1[1]=a_r1[2]=a_r1[3]=a_r1[4]=a_r1[5]=0;a_r1[6]=a_1061;to_LIST(a_1018)->aupb+=7;}
  return;
} /* expandITEM */
static a_word a_1056(a_word a_F1,a_word a_F2){ /* isitemflag+>a+>a */
a_word a_L3;
a_booland(to_LIST(a_1018)->offset[a_F1-6],a_F2,a_L3);
if(!a_is(a_L3)){ return 0;} return 1;
} /* isitemflag */
static void a_1068(a_word a_F1,a_word a_F2){ /* setitemflag+>a+>a */

a_boolor(to_LIST(a_1018)->offset[a_F1-6],a_F2,to_LIST(a_1018)->offset[a_F1-6]); return;
} /* setitemflag */
static void a_1020(a_word a_A[1]){ /* converttoitem+>a> */

a_addmult(a_A[0],7,1559373916,a_A[0]); return;
} /* converttoitem */
static void a_1052(a_word a_F1,a_word a_A[1]){ /* getitemrepr+>a+a> */

a_A[0]=to_LIST(a_1018)->offset[a_F1]; return;
} /* getitemrepr */
static void a_1055(void){ /* headsection */

a_G1:if(!a_equal(588109447,a_1096)){ goto a_G3;}
a_1100(); return;
a_G3:a_1100(); goto a_G1;
} /* headsection */
static void a_1031(void){ /* copyheadsection */

a_G1:if(!a_equal(588109447,a_1096)){ goto a_G5;}
a_1085(588109429);
a_1114(0);
a_1100(); return;
a_G5:a_1100(); goto a_G1;
} /* copyheadsection */
static void a_1060(a_word a_F1){ /* markifrequested+>a */

if(!a_1056(a_F1,4)){ goto a_G3;}
a_G2:a_1068(a_F1,128); return;
a_G3:if(!a_equal(to_LIST(a_1018)->offset[a_F1-5],588109354)){ return;}
if(!a_equal(to_LIST(a_1018)->offset[a_F1-3],702375907)){ return;} goto a_G2;
} /* markifrequested */
static void a_1070(void){ /* skipformalaffixes */
a_word a_L1;a_word a_L2;
if(!a_equal(588109463,a_1096)){ goto a_G4;}
a_L1=a_1097;
a_G3:a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:if(a_equal(a_L1,0)){ return;}
a_decr(a_L1);
if(!a_equal(588109475,a_1096)){ goto a_G4;}
a_L2=a_1097;
a_1100();
{ if(a_L2==588109360||a_L2==588109366){ goto a_G11;}
 if(a_L2==588109376||a_L2==588109381||a_L2==588109387||a_L2==588109371||a_L2==588109393||a_L2==588109399){  goto a_G5;}
  goto a_G16;}
a_G11:if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100();
if(!a_equal(588109463,a_1096)){ goto a_G4;}
 goto a_G3;
a_G16:a_1007(a_1001,2130706262); return;
} /* skipformalaffixes */
static void a_1072(void){ /* skiplistbounds */

if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100(); return;
} /* skiplistbounds */
static void a_1064(void){ /* readitem */
a_word a_L1;a_word a_L2;
a_1044();
if(!a_equal(588109475,a_1096)){ goto a_G5;}
to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-5]=a_1097;
a_1100(); goto a_G6;
a_G5:a_1007(a_1001,2130706200); return;
a_G6:if(!a_equal(588109483,a_1096)){ goto a_G5;}
a_L1=a_1097;
a_1100();
if(a_equal(a_L1,to_LIST(a_1018)->aupb)){ goto a_G11;}
a_1007(a_1001,2130706255); return;
a_G11:if(!a_equal(588109463,a_1096)){ goto a_G5;}
a_L2=a_1097;
a_1100();
a_booland(a_L2,117557020,to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-6]);
if(!a_equal(588109463,a_1096)){ goto a_G5;}
to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-2]=a_1097;
a_1100();
{register a_word a_r1=to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-5];
 if(a_r1==588109354){ goto a_G19;}
 if(a_r1==588109327||a_r1==588109323||a_r1==588109333){  goto a_G20;}
  goto a_G21;}
a_G19:a_1070(); goto a_G21;
a_G20:a_1072();
a_G21:if(!a_equal(588109495,a_1096)){ goto a_G5;}
to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-4]=a_1097;
a_1100();
if(!a_equal(588109495,a_1096)){ goto a_G5;}
to_LIST(a_1018)->offset[to_LIST(a_1018)->aupb-3]=a_1097;
a_1100();
a_1060(a_L1); return;
} /* readitem */
static void a_1058(void){ /* itemsection */

a_G1:if(!a_equal(588109447,a_1096)){ goto a_G3;}
a_1100(); return;
a_G3:a_1064(); goto a_G1;
} /* itemsection */
static void a_1030(void){ /* copyformalaffixes */
a_word a_L1;a_word a_L2;a_word a_L3;
if(!a_equal(588109463,a_1096)){ goto a_G4;}
a_L1=a_1097;
a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:a_1086(588109463,a_L1);
a_G6:if(a_equal(a_L1,0)){ return;}
a_decr(a_L1);
if(!a_equal(588109475,a_1096)){ goto a_G4;}
a_L2=a_1097;
a_1100();
a_1086(588109475,a_L2);
{ if(!(a_L2==588109360||a_L2==588109366)){ goto a_G6;}
}
if(!a_equal(588109463,a_1096)){ goto a_G4;}
a_L3=a_1097;
a_1100();
a_1086(588109463,a_L3);
if(!a_equal(588109463,a_1096)){ goto a_G4;}
a_L3=a_1097;
a_1100();
a_1086(588109463,a_L3); goto a_G6;
} /* copyformalaffixes */
static void a_1035(void){ /* copylistbounds */
a_word a_L1;
if(!a_equal(588109463,a_1096)){ goto a_G4;}
a_L1=a_1097;
a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:a_1086(588109463,a_L1);
if(!a_equal(588109463,a_1096)){ goto a_G4;}
a_L1=a_1097;
a_1100();
a_1086(588109463,a_L1); return;
} /* copylistbounds */
static void a_1071(a_word a_F1){ /* skipitem+>a */
a_word a_L2;a_word a_L3;
if(!a_equal(588109475,a_1096)){ goto a_G4;}
a_L2=a_1097;
a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L3=a_1097;
a_1100();
if(a_equal(a_L3,a_F1)){ goto a_G10;}
a_1010(a_1001,2130706250); return;
a_G10:if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100();
if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100();
{ if(a_L2==588109354){ goto a_G17;}
 if(a_L2==588109327||a_L2==588109323||a_L2==588109333){  goto a_G18;}
  goto a_G19;}
a_G17:a_1070(); goto a_G19;
a_G18:a_1072();
a_G19:if(!a_equal(588109495,a_1096)){ goto a_G4;}

a_1100();
if(!a_equal(588109495,a_1096)){ goto a_G4;}

a_1100(); return;
} /* skipitem */
static void a_1033(a_word a_F1){ /* copyitem+>a */
a_word a_L2;a_word a_L3;a_word a_L4;
if(!a_equal(588109475,a_1096)){ goto a_G4;}
a_L2=a_1097;
a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:a_1086(588109475,a_L2);
if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L3=a_1097;
a_1100();
if(a_equal(a_L3,a_F1)){ goto a_G11;}
a_1010(a_1001,2130706245); return;
a_G11:a_1086(588109483,a_L3);
if(!a_equal(588109463,a_1096)){ goto a_G4;}
a_L4=a_1097;
a_1100();
a_1086(588109463,a_L4);
if(!a_equal(588109463,a_1096)){ goto a_G4;}
a_L4=a_1097;
a_1100();
a_1086(588109463,a_L4);
{ if(a_L2==588109354){ goto a_G21;}
 if(a_L2==588109327||a_L2==588109323||a_L2==588109333){  goto a_G22;}
  goto a_G23;}
a_G21:a_1030(); goto a_G23;
a_G22:a_1035();
a_G23:if(!a_equal(588109495,a_1096)){ goto a_G4;}
a_L4=a_1097;
a_1100();
a_1086(588109495,a_L4);
if(!a_equal(588109495,a_1096)){ goto a_G4;}
a_L4=a_1097;
a_1100();
a_1086(588109495,a_L4);
a_1085(588109429); return;
} /* copyitem */
static void a_1034(void){ /* copyitemsection */
a_word a_L1;
a_L1=to_LIST(a_1018)->alwb;
a_G2:if(!a_equal(588109447,a_1096)){ goto a_G6;}
a_1100();
a_1085(588109447);
a_1085(588109429); return;
a_G6:if(!a_1056(a_L1,128)){ goto a_G9;}
a_1033(a_L1);
a_G8:a_next(a_1018,a_L1); goto a_G2;
a_G9:a_1071(a_L1); goto a_G8;
} /* copyitemsection */
static void a_1069(void){ /* skipentry */

a_G1:if(!a_equal(588109447,a_1096)){ goto a_G3;}
a_1100(); return;
a_G3:if(!a_equal(588109498,a_1096)){ goto a_G6;}
a_1100();
a_1007(a_1001,2130706240); return;
a_G6:a_1100(); goto a_G1;
} /* skipentry */
static void a_1045(a_word a_F1){ /* fileareas+>a */
a_word a_L2;
if(!a_equal(588109456,a_1096)){ return;}
a_1100();
a_G3:if(!a_equal(588109408,a_1096)){ goto a_G5;}
a_1100(); return;
a_G5:if(!a_equal(588109483,a_1096)){ goto a_G8;}
a_L2=a_1097;
a_1100(); goto a_G9;
a_G8:a_1007(a_1001,2130706200); return;
a_G9:a_1019(a_F1,a_L2); goto a_G3;
} /* fileareas */
static void a_1046(void){ /* fileentry */
a_word a_L1;a_word a_L2;
if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L1=a_1097;
a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L2=a_1097;
a_1100();
a_1019(a_L1,a_L2);
if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L2=a_1097;
a_1100();
a_1019(a_L1,a_L2);
a_1045(a_L1);
if(!a_equal(588109447,a_1096)){ goto a_G4;}

a_1100(); return;
} /* fileentry */
static void a_1047(void){ /* fillentry */
a_word a_L1;
if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L1=a_1097;
a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100();
a_G8:if(!a_equal(588109447,a_1096)){ goto a_G10;}
a_1100(); return;
a_G10:a_1050(a_L1);
a_1051(a_L1);
a_1048(a_L1); goto a_G8;
} /* fillentry */
static void a_1050(a_word a_F1){ /* fillitempack+>a */

if(!a_equal(588109435,a_1096)){ goto a_G6;}
a_1100();
a_G3:if(!a_equal(588109411,a_1096)){ goto a_G5;}
a_1100(); return;
a_G5:a_1049(a_F1); goto a_G3;
a_G6:a_1049(a_F1); return;
} /* fillitempack */
static void a_1049(a_word a_F1){ /* fillitem+>a */
a_word a_L2;
if(!a_equal(588109467,a_1096)){ goto a_G3;}
a_G2:a_1100(); return;
a_G3:if(a_equal(588109471,a_1096)){ goto a_G2;}
if(!a_equal(588109483,a_1096)){ goto a_G7;}
a_L2=a_1097;
a_1100(); goto a_G8;
a_G7:a_1007(a_1001,2130706200); return;
a_G8:a_1019(a_F1,a_L2); return;
} /* fillitem */
static void a_1051(a_word a_F1){ /* fillrepeater+>a */
a_word a_L2;
if(!a_equal(588109453,a_1096)){ return;}
a_1100();
if(!a_equal(588109463,a_1096)){ goto a_G5;}
a_1100(); return;
a_G5:if(!a_equal(588109483,a_1096)){ goto a_G8;}
a_L2=a_1097;
a_1100(); goto a_G9;
a_G8:a_1007(a_1001,2130706200); return;
a_G9:a_1019(a_F1,a_L2); return;
} /* fillrepeater */
static void a_1048(a_word a_F1){ /* fillinitializers+>a */
a_word a_L2;
a_G1:if(!a_equal(588109414,a_1096)){ return;}
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:a_1019(a_L2,a_F1); goto a_G1;
} /* fillinitializers */
static void a_1063(void){ /* readexpression */
a_word a_L1;a_word a_L2;
if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L1=a_1097;
a_G3:a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:{ if(a_1096==588109447){ goto a_G6;}
 if(a_1096==588109467){ goto a_G3;}
 if(a_1096==588109483){ goto a_G7;}
 if(a_1096==588109274||a_1096==588109296||a_1096==588109240){ goto a_G8;}
 if(a_1096==588109444||a_1096==588109426||a_1096==588109453||a_1096==588109423||a_1096==588109405||a_1096==588109438||a_1096==588109459||a_1096==588109420||a_1096==588109435||a_1096==588109411){  goto a_G3;}
  goto a_G13;}
a_G6:a_1100(); return;
a_G7:a_1019(a_L1,a_1097); goto a_G3;
a_G8:a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L2=a_1097;
a_1100();
a_1019(a_L1,a_L2); goto a_G5;
a_G13:a_1007(a_1001,2130706235); return;
} /* readexpression */
static void a_1059(void){ /* listentry */
a_word a_L1;a_word a_L2;
if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L1=a_1097;
a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100();
if(!a_equal(588109463,a_1096)){ goto a_G11;}

a_1100(); goto a_G15;
a_G11:if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L2=a_1097;
a_1100();
a_1019(a_L1,a_L2);
a_G15:if(!a_equal(588109447,a_1096)){ goto a_G4;}

a_1100(); return;
} /* listentry */
static void a_1043(void){ /* datasection */

a_G1:if(!a_equal(588109259,a_1096)){ goto a_G4;}
a_1100();
a_1046(); goto a_G1;
a_G4:if(!a_equal(588109263,a_1096)){ goto a_G7;}
a_1100();
a_1047(); goto a_G1;
a_G7:if(!a_equal(588109245,a_1096)){ goto a_G10;}
a_1100();
a_1063(); goto a_G1;
a_G10:if(!a_equal(588109271,a_1096)){ goto a_G13;}
a_1100();
a_1059(); goto a_G1;
a_G13:if(!a_equal(588109233,a_1096)){ goto a_G16;}
a_G14:a_1100();
a_1069(); goto a_G1;
a_G16:if(a_equal(588109267,a_1096)){ goto a_G14;}
if(a_equal(588109255,a_1096)){ goto a_G14;}
if(a_equal(a_1096,588109290)){ return;}
a_1007(a_1001,2130706229); return;
} /* datasection */
static void a_1025(a_word a_F1){ /* copyfileentry+>a */
a_word a_L2;
a_1085(588109259);
a_1086(588109483,a_F1);
if(!a_equal(588109463,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:a_1086(588109463,a_L2);
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1086(588109483,a_L2);
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1086(588109483,a_L2);
a_1024();
if(!a_equal(588109447,a_1096)){ goto a_G6;}

a_1100();
a_1085(588109447);
a_1085(588109429); return;
} /* copyfileentry */
static void a_1024(void){ /* copyfileareas */
a_word a_L1;
if(!a_equal(588109456,a_1096)){ return;}
a_1100();
a_1085(588109456);
a_G4:if(!a_equal(588109408,a_1096)){ goto a_G7;}
a_1100();
a_1085(588109408); return;
a_G7:if(!a_equal(588109483,a_1096)){ goto a_G10;}
a_L1=a_1097;
a_1100(); goto a_G11;
a_G10:a_1007(a_1001,2130706200); return;
a_G11:a_1086(588109483,a_L1); goto a_G4;
} /* copyfileareas */
static void a_1026(a_word a_F1){ /* copyfillentry+>a */
a_word a_L2;
a_1085(588109263);
a_1086(588109483,a_F1);
if(!a_equal(588109463,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:a_1086(588109463,a_L2);
a_G8:if(!a_equal(588109447,a_1096)){ goto a_G12;}
a_1100();
a_1085(588109447);
a_1085(588109429); return;
a_G12:a_1028();
a_1029();
a_1032(); goto a_G8;
} /* copyfillentry */
static void a_1028(void){ /* copyfillitempack */

if(!a_equal(588109435,a_1096)){ goto a_G8;}
a_1100();
a_1085(588109435);
a_G4:if(!a_equal(588109411,a_1096)){ goto a_G7;}
a_1100();
a_1085(588109411); return;
a_G7:a_1027(); goto a_G4;
a_G8:a_1027(); return;
} /* copyfillitempack */
static void a_1027(void){ /* copyfillitem */
a_word a_L1;
if(!a_equal(588109467,a_1096)){ goto a_G5;}
a_L1=a_1097;
a_1100();
a_1086(588109467,a_L1); return;
a_G5:if(!a_equal(588109471,a_1096)){ goto a_G9;}
a_L1=a_1097;
a_1100();
a_1086(588109471,a_L1); return;
a_G9:if(!a_equal(588109483,a_1096)){ goto a_G12;}
a_L1=a_1097;
a_1100(); goto a_G13;
a_G12:a_1007(a_1001,2130706200); return;
a_G13:a_1086(588109483,a_L1); return;
} /* copyfillitem */
static void a_1029(void){ /* copyfillrepeater */
a_word a_L1;
if(!a_equal(588109453,a_1096)){ return;}
a_1100();
a_1085(588109453);
if(!a_equal(588109463,a_1096)){ goto a_G8;}
a_L1=a_1097;
a_1100();
a_1086(588109463,a_L1); return;
a_G8:if(!a_equal(588109483,a_1096)){ goto a_G11;}
a_L1=a_1097;
a_1100(); goto a_G12;
a_G11:a_1007(a_1001,2130706200); return;
a_G12:a_1086(588109483,a_L1); return;
} /* copyfillrepeater */
static void a_1032(void){ /* copyinitializers */
a_word a_L1;
a_G1:if(!a_equal(588109414,a_1096)){ return;}
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L1=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:if(!a_1056(a_L1,128)){ goto a_G1;}
a_1085(588109414);
a_1086(588109483,a_L1); goto a_G1;
} /* copyinitializers */
static void a_1022(a_word a_F1){ /* copyexpression+>a */
a_word a_L2;
a_1085(588109245);
a_1086(588109483,a_F1);
a_G3:{ if(a_1096==588109447){ goto a_G4;}
 if(a_1096==588109467){ goto a_G7;}
 if(a_1096==588109483){ goto a_G9;}
 if(a_1096==588109274||a_1096==588109296||a_1096==588109240){  goto a_G10;}
  goto a_G17;}
a_G4:a_1100();
a_1085(588109447);
a_1085(588109429); return;
a_G7:a_1086(588109467,a_1097);
a_G8:a_1100(); goto a_G3;
a_G9:a_1086(588109483,a_1097); goto a_G8;
a_G10:a_1085(a_1096);
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G15;}
a_L2=a_1097;
a_1100(); goto a_G16;
a_G15:a_1007(a_1001,2130706200); return;
a_G16:a_1086(588109483,a_L2); goto a_G3;
a_G17:a_1085(a_1096); goto a_G8;
} /* copyexpression */
static void a_1036(a_word a_F1){ /* copylistentry+>a */
a_word a_L2;
a_1085(588109271);
a_1086(588109483,a_F1);
if(!a_equal(588109463,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:a_1086(588109463,a_L2);
if(!a_equal(588109463,a_1096)){ goto a_G12;}
a_L2=a_1097;
a_1100();
a_1086(588109463,a_L2); goto a_G16;
a_G12:if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1086(588109483,a_L2);
a_G16:if(!a_equal(588109447,a_1096)){ goto a_G6;}

a_1100();
a_1085(588109447);
a_1085(588109429); return;
} /* copylistentry */
static void a_1037(a_word a_F1){ /* copymatter+>a */
a_word a_L2;
a_1085(a_F1);
if(!a_equal(588109495,a_1096)){ goto a_G5;}
a_L2=a_1097;
a_1100(); goto a_G6;
a_G5:a_1007(a_1001,2130706200); return;
a_G6:a_1086(588109495,a_L2);
if(!a_equal(588109447,a_1096)){ goto a_G5;}

a_1100();
a_1085(588109447);
a_1085(588109429); return;
} /* copymatter */
static void a_1023(a_word a_F1){ /* copyexternal+>a */
a_word a_L2;
a_1085(588109255);
a_1086(588109483,a_F1);
if(!a_equal(588109495,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:if(!a_equal(588109447,a_1096)){ goto a_G6;}

a_1100();
a_1086(588109495,a_L2);
a_1085(588109447);
a_1085(588109429); return;
} /* copyexternal */
static void a_1021(void){ /* copydatasection */
a_word a_L1;
a_G1:if(!a_equal(588109259,a_1096)){ goto a_G10;}
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L1=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:if(!a_1056(a_L1,128)){ goto a_G9;}
a_1025(a_L1); goto a_G1;
a_G9:a_1069(); goto a_G1;
a_G10:if(!a_equal(588109263,a_1096)){ goto a_G17;}
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L1=a_1097;
a_1100();
if(!a_1056(a_L1,128)){ goto a_G9;}
a_1026(a_L1); goto a_G1;
a_G17:if(!a_equal(588109245,a_1096)){ goto a_G24;}
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L1=a_1097;
a_1100();
if(!a_1056(a_L1,128)){ goto a_G9;}
a_1022(a_L1); goto a_G1;
a_G24:if(!a_equal(588109271,a_1096)){ goto a_G31;}
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L1=a_1097;
a_1100();
if(!a_1056(a_L1,128)){ goto a_G9;}
a_1036(a_L1); goto a_G1;
a_G31:if(!a_equal(588109233,a_1096)){ goto a_G34;}
a_1100();
a_1037(588109233); goto a_G1;
a_G34:if(!a_equal(588109267,a_1096)){ goto a_G37;}
a_1100();
a_1037(588109267); goto a_G1;
a_G37:if(!a_equal(588109255,a_1096)){ return;}
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L1=a_1097;
a_1100();
if(!a_1056(a_L1,128)){ goto a_G9;}
a_1023(a_L1); goto a_G1;
} /* copydatasection */
static void a_1066(void){ /* readrule */
a_word a_L1;
if(!a_equal(588109483,a_1096)){ goto a_G4;}
a_L1=a_1097;
a_1100(); goto a_G5;
a_G4:a_1007(a_1001,2130706200); return;
a_G5:if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100();
if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100();
if(!a_equal(588109463,a_1096)){ goto a_G4;}

a_1100();
a_G14:if(!a_equal(588109236,a_1096)){ goto a_G17;}
a_G15:a_1100();
a_1065(a_L1); goto a_G14;
a_G17:if(a_equal(588109250,a_1096)){ goto a_G15;}
if(a_equal(588109286,a_1096)){ goto a_G15;}
if(!a_equal(588109447,a_1096)){ goto a_G4;}

a_1100(); return;
} /* readrule */
static void a_1065(a_word a_F1){ /* readnode+>a */

a_G1:{ if(a_1096==588109483){ goto a_G2;}
 if(a_1096==588109456||a_1096==588109408||a_1096==588109229||a_1096==588109414||a_1096==588109450||a_1096==588109402||a_1096==588109293||a_1096==588109432||a_1096==588109296||a_1096==588109274||a_1096==588109304||a_1096==588109300||a_1096==588109240){ goto a_G3;}
 if(a_1096==588109463||a_1096==588109491||a_1096==588109487||a_1096==588109479||a_1096==588109441||a_1096==588109467){  goto a_G3;}
  goto a_G4;}
a_G2:a_1019(a_F1,a_1097);
a_G3:a_1100(); goto a_G1;
a_G4:if(!a_equal(588109417,a_1096)){ goto a_G7;}

a_1100(); return;
a_G7:a_1007(a_1001,2130706200); return;
} /* readnode */
static void a_1067(void){ /* rulesection */

a_G1:if(!a_equal(588109290,a_1096)){ goto a_G4;}
a_1100();
a_1066(); goto a_G1;
a_G4:if(!a_equal(588109498,a_1096)){ goto a_G6;}
a_1100(); return;
a_G6:a_1007(a_1001,2130706224); return;
} /* rulesection */
static void a_1040(void){ /* copyrulesection */

if(!a_is(a_1062)){ goto a_G3;}
a_1041(); return;
a_G3:a_1042(); return;
} /* copyrulesection */
static void a_1039(a_word a_F1){ /* copyrule+>a */
a_word a_L2;
a_1085(588109290);
a_1086(588109483,a_F1);
if(!a_equal(588109463,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:a_1086(588109463,a_L2);
if(!a_equal(588109463,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1086(588109463,a_L2);
if(!a_equal(588109463,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1086(588109463,a_L2);
a_G16:if(!a_equal(588109236,a_1096)){ goto a_G20;}
a_1100();
a_1085(588109236);
a_G19:a_1038(); goto a_G16;
a_G20:if(!a_equal(588109250,a_1096)){ goto a_G23;}
a_1100();
a_1085(588109250); goto a_G19;
a_G23:if(!a_equal(588109286,a_1096)){ goto a_G26;}
a_1100();
a_1085(588109286); goto a_G19;
a_G26:if(!a_equal(588109447,a_1096)){ goto a_G6;}

a_1100();
a_1085(588109447);
a_1085(588109429); return;
} /* copyrule */
static void a_1038(void){ /* copynode */

a_G1:{ if(a_1096==588109483||a_1096==588109463||a_1096==588109491||a_1096==588109487||a_1096==588109479||a_1096==588109441||a_1096==588109467){ goto a_G2;}
 if(a_1096==588109456||a_1096==588109408||a_1096==588109229||a_1096==588109414||a_1096==588109450||a_1096==588109402||a_1096==588109293||a_1096==588109432||a_1096==588109296||a_1096==588109274||a_1096==588109304||a_1096==588109300||a_1096==588109240){  goto a_G4;}
  goto a_G5;}
a_G2:a_1086(a_1096,a_1097);
a_G3:a_1100(); goto a_G1;
a_G4:a_1085(a_1096); goto a_G3;
a_G5:if(!a_equal(588109417,a_1096)){ goto a_G8;}

a_1100(); goto a_G9;
a_G8:a_1007(a_1001,2130706200); return;
a_G9:a_1085(588109417); return;
} /* copynode */
static void a_1042(void){ /* copyruleswithoutoptimization */
a_word a_L1;
a_G1:if(!a_equal(588109290,a_1096)){ goto a_G10;}
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L1=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:if(!a_1056(a_L1,128)){ goto a_G9;}
a_1039(a_L1); goto a_G1;
a_G9:a_1069(); goto a_G1;
a_G10:if(!a_equal(588109498,a_1096)){ goto a_G12;}
a_1100(); return;
a_G12:a_1007(a_1001,2130706219); return;
} /* copyruleswithoutoptimization */
static void a_1054(a_word a_F1){ /* handlerule+>a */
a_word a_L2;
a_1085(588109290);
a_1086(588109483,a_F1);
if(!a_equal(588109463,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:a_1086(588109463,a_L2);
if(!a_equal(588109463,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1086(588109463,a_L2);
if(!a_equal(588109463,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1150(a_L2);
a_G16:if(!a_equal(588109236,a_1096)){ goto a_G23;}
a_1100();
if(!a_equal(588109479,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1149(588109236,a_L2);
a_G22:a_1053(); goto a_G16;
a_G23:if(!a_equal(588109250,a_1096)){ goto a_G29;}
a_1100();
if(!a_equal(588109479,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1149(588109250,a_L2); goto a_G22;
a_G29:if(!a_equal(588109286,a_1096)){ goto a_G35;}
a_1100();
if(!a_equal(588109479,a_1096)){ goto a_G6;}
a_L2=a_1097;
a_1100();
a_1149(588109286,a_L2); goto a_G22;
a_G35:if(!a_equal(588109447,a_1096)){ goto a_G6;}

a_1100();
a_1140(); return;
} /* handlerule */
static void a_1053(void){ /* handlenode */

a_G1:{ if(a_1096==588109483||a_1096==588109463||a_1096==588109491||a_1096==588109487||a_1096==588109479||a_1096==588109441||a_1096==588109467){ goto a_G2;}
 if(a_1096==588109456||a_1096==588109408||a_1096==588109229||a_1096==588109414||a_1096==588109450||a_1096==588109402||a_1096==588109293||a_1096==588109432||a_1096==588109296||a_1096==588109274||a_1096==588109304||a_1096==588109300||a_1096==588109240){  goto a_G4;}
  goto a_G5;}
a_G2:a_1136(a_1096,a_1097);
a_G3:a_1100(); goto a_G1;
a_G4:a_1135(a_1096); goto a_G3;
a_G5:if(!a_equal(588109417,a_1096)){ goto a_G8;}

a_1100(); goto a_G9;
a_G8:a_1007(a_1001,2130706200); return;
a_G9:a_1141(); return;
} /* handlenode */
static void a_1041(void){ /* copyruleswithoptimization */
a_word a_L1;
a_G1:if(!a_equal(588109290,a_1096)){ goto a_G10;}
a_1100();
if(!a_equal(588109483,a_1096)){ goto a_G6;}
a_L1=a_1097;
a_1100(); goto a_G7;
a_G6:a_1007(a_1001,2130706200); return;
a_G7:if(!a_1056(a_L1,128)){ goto a_G9;}
a_1054(a_L1); goto a_G1;
a_G9:a_1069(); goto a_G1;
a_G10:if(!a_equal(588109498,a_1096)){ goto a_G12;}
a_1100(); return;
a_G12:a_1007(a_1001,2130706209); return;
} /* copyruleswithoptimization */
static void a_1073(a_word a_F1,a_word a_A[1]){ /* traverseitem+>a+>a> */
a_word a_L3;
if(a_1056(a_F1,64)){ return;}
if(!a_1056(a_F1,128)){ return;}
a_1068(a_F1,64);
a_L3=to_LIST(a_1018)->offset[a_F1-1];
a_G5:if(a_equal(a_L3,0)){ return;}
if(!a_1056(to_LIST(a_1017)->offset[a_L3-1],128)){ goto a_G8;}
a_G7:a_L3=to_LIST(a_1017)->offset[a_L3]; goto a_G5;
a_G8:a_A[0]=1;
a_1068(to_LIST(a_1017)->offset[a_L3-1],128); goto a_G7;
} /* traverseitem */
static void a_1075(a_word a_A[1]){ /* traverseonce+a> */
a_word a_L2;a_word a_P[1];
a_A[0]=0;
a_L2=to_LIST(a_1018)->alwb;
a_G3:if(a_more(a_L2,to_LIST(a_1018)->aupb)){ return;}
a_P[0]=a_A[0];a_1073(a_L2,a_P);a_A[0]=a_P[0];
a_next(a_1018,a_L2); goto a_G3;
} /* traverseonce */
static void a_1074(void){ /* traverseitems */
a_word a_L1;a_word a_P[1];
a_G1:a_1075(a_P);a_L1=a_P[0];
if(!a_equal(a_L1,0)){ goto a_G1;}
a_release(a_1017); return;
} /* traverseitems */
static void a_1093(a_word a_F1){ /* extendBUFFER+>a */

{register a_word *a_r1=a_extension(a_1078,1);a_r1[0]=a_F1;to_LIST(a_1078)->aupb+=1;}
  return;
} /* extendBUFFER */
static void a_1115(a_word a_A[1]){ /* trytoopen+a> */

if(!a_openfile(a_1084,114,a_1082,to_LIST(a_1082)->aupb)){ goto a_G3;}
a_A[0]=0; return;
a_G3:a_getfileerror(a_1084,a_A[0]);
if(a_equal(a_A[0],2)){ return;}
a_A[0]=-1; return;
} /* trytoopen */
static void a_1102(a_word a_F1){ /* opensourcefile+>a */
a_word a_L2;a_word a_L3;a_word a_P[2];
a_copystring(a_1159,a_F1,a_1082);
a_1115(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;}
if(!a_less(a_L2,0)){ goto a_G6;}
a_G5:a_P[0]=2130705960;a_P[1]=a_F1;a_1008(2,2,a_P); return;
a_G6:a_unstackstring(a_1082);
a_scratch(a_1078);
a_L3=to_LIST(a_1078)->aupb;
a_unpackstring(a_1159,a_F1,a_1078);
a_unpackstring(a_1006,2130705997,a_1078);
a_subtr(to_LIST(a_1078)->aupb,a_L3,a_L3);
a_packstring(a_1078,a_L3,a_1082);
a_scratch(a_1078);
a_1115(a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ return;} goto a_G5;
} /* opensourcefile */
static void a_1101(a_word a_F1){ /* opensource+>a */
a_word a_P[1];
a_1102(a_F1);
a_1087(a_P);a_1095=a_P[0];
a_1113=1;
a_1088=1;
a_1104=0;
a_1099();
a_1100(); return;
} /* opensource */
static void a_1112(a_word a_F1,a_word a_F2){ /* rewindsource+>a+>a */
a_word a_P[2];
if(!a_is(a_F1)){ goto a_G5;}
a_1103=0;
if(a_openfile(a_1083,119,a_1159,a_F1)){ goto a_G9;}
a_P[0]=2130705970;a_P[1]=a_F1;a_1008(2,2,a_P); return;
a_G5:a_copystring(a_1006,a_F2,a_1082);
if(!a_opentempfile(a_1083,a_1082,to_LIST(a_1082)->aupb)){ goto a_G8;}
a_1087(a_P);a_1103=a_P[0]; goto a_G9;
a_G8:a_P[0]=2130705980;a_1008(2,1,a_P); return;
a_G9:a_setfilepos(a_1084,0);
a_1113=1;
a_1088=1;
a_1104=1;
a_1099();
a_1100(); return;
} /* rewindsource */
static void a_1089(void){ /* closesource */

a_closefile(a_1084);
a_closefile(a_1083);
if(a_equal(a_1103,0)){ return;}
a_1098(); return;
} /* closesource */
static void a_1091(void){ /* copysourcetoresult */
a_word a_L1;a_word a_P[1];
a_G1:if(!a_getchar(a_1084,a_P)){ goto a_G3;}a_L1=a_P[0];
a_putchar(a_1083,a_L1); goto a_G1;
a_G3:a_closefile(a_1084);
a_closefile(a_1083); return;
} /* copysourcetoresult */
static void a_1098(void){ /* movetempfile */
a_word a_L1;a_word a_L2;a_word a_P[3];
a_1094(a_1103,a_P);a_L1=a_P[0];
a_1094(a_1095,a_P);a_L2=a_P[0];
if(!a_openfile(a_1084,114,a_1082,a_L1)){ goto a_G5;}
if(a_openfile(a_1083,119,a_1082,a_L2)){ goto a_G6;}
a_G5:a_P[0]=2130705993;a_P[1]=a_L2;a_P[2]=a_L1;a_1008(3,3,a_P); return;
a_G6:a_1091();
a_unlinkfile(a_1082,a_L1); return;
} /* movetempfile */
static void a_1114(a_word a_F1){ /* toggleout+>a */

a_1104=a_F1; return;
} /* toggleout */
static void a_1099(void){ /* nextchar */
a_word a_P[1];
a_G1:if(a_equal(a_1104,0)){ goto a_G4;}
if(a_equal(a_1088,1)){ goto a_G4;}
a_putchar(a_1083,a_1088);
a_G4:if(!a_getchar(a_1084,a_P)){ goto a_G7;}a_1088=a_P[0];
{ if(a_1088==10){ goto a_G6;}
 if(a_1088<=31){  goto a_G1;}
  return;}
a_G6:a_incr(a_1113); return;
a_G7:a_1088=1; return;
} /* nextchar */
static void a_1090(void){ /* comment */

a_G1:if(a_equal(a_1088,10)){ return;}
if(a_equal(a_1088,1)){ return;}
a_1099(); goto a_G1;
} /* comment */
static void a_1106(a_word a_A[1]){ /* readdestination+a> */
a_word a_L2;
{ if(a_1088==78){ goto a_G2;}
 if(a_1088==48){ goto a_G15;}
 if(a_1088==45){  goto a_G17;}
  goto a_G28;}
a_G2:a_1099();
{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G8;}
}
a_subtr(a_1088,48,a_A[0]);
a_1099();
if(a_more(a_A[0],0)){ goto a_G9;}
if(a_equal(0,0)){ goto a_G9;}
a_G8:a_1007(a_1001,2130706310); return;
a_G9:{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G13;}
}
a_subtr(a_1088,48,a_L2);
a_1099();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G9;
a_G13:if(!a_is(0)){ return;}
a_G14:a_subtr(0,a_A[0],a_A[0]); return;
a_G15:a_1099();
a_A[0]=0; return;
a_G17:a_1099();
{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G8;}
}
a_subtr(a_1088,48,a_A[0]);
a_1099();
if(a_more(a_A[0],0)){ goto a_G23;}
if(!a_equal(1,0)){ goto a_G8;}
a_G23:{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G27;}
}
a_subtr(a_1088,48,a_L2);
a_1099();
a_addmult(a_A[0],10,a_L2,a_A[0]); goto a_G23;
a_G27:if(!a_is(1)){ return;} goto a_G14;
a_G28:a_1007(a_1001,2130706305); return;
} /* readdestination */
static void a_1092(a_word a_F1,a_word a_A[1]){ /* enterstring+>a+a> */
a_word a_L3;a_word a_L4;a_word a_L5;a_word a_L6;a_word a_L7;a_word a_P[1];
a_subtr(a_F1,2,a_L3);
a_stringhash(a_1082,a_L3,a_P);a_L4=a_P[0];
a_booland(a_L4,2147483647,a_L4);
a_divrem01(a_L4,a_1081,a_L4);
a_add(a_L4,to_LIST(a_1079)->alwb,a_L4);
a_L5=to_LIST(a_1079)->offset[a_L4];
a_G7:if(!a_equal(a_L5,0)){ goto a_G14;}
to_LIST(a_1082)->offset[a_F1-1]=to_LIST(a_1079)->offset[a_L4];
to_LIST(a_1079)->offset[a_L4]=a_F1;a_A[0]=a_F1;
a_incr(a_1080);
if(a_less(a_1080,a_1081)){ return;}
a_add(a_1081,1024,a_1081);
a_1111(); return;
a_G14:a_subtr(a_L5,2,a_L6);
a_comparestring(a_1082,a_L3,a_1082,a_L6,a_P);a_L7=a_P[0];
if(!a_equal(a_L7,0)){ goto a_G18;}
a_A[0]=a_L5; return;
a_G18:a_L5=to_LIST(a_1082)->offset[a_L5-1]; goto a_G7;
} /* enterstring */
static void a_1111(void){ /* rehash */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_1080=0;
a_L1=to_LIST(a_1079)->aupb;
a_G3:if(a_less(a_L1,to_LIST(a_1079)->alwb)){ goto a_G6;}
to_LIST(a_1079)->offset[a_L1]=0;
a_previous(a_1079,a_L1); goto a_G3;
a_G6:a_subtr(to_LIST(a_1079)->aupb,to_LIST(a_1079)->alwb,a_L2);
a_G7:a_incr(a_L2);
if(a_mreq(a_L2,a_1081)){ goto a_G10;}
{register a_word *a_r1=a_extension(a_1079,1);a_r1[0]=0;to_LIST(a_1079)->aupb+=1;}
  goto a_G7;
a_G10:a_L1=to_LIST(a_1082)->aupb;
a_G11:if(a_less(a_L1,to_LIST(a_1082)->alwb)){ return;}
a_1092(a_L1,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,a_L1)){ goto a_G16;}
a_previous(a_1082,a_L1);
a_previousstring(a_1082,a_L1); goto a_G11;
a_G16:a_1010(a_1001,2130706299); return;
} /* rehash */
static void a_1076(void){ /* @root */

a_1111(); return;
} /* @root */
static void a_1094(a_word a_F1,a_word a_A[1]){ /* gettagimage+>a+a> */

a_subtr(a_F1,2,a_A[0]); return;
} /* gettagimage */
static void a_1087(a_word a_A[1]){ /* addLEXTentry+a> */
a_word a_P[1];
{register a_word *a_r1=a_extension(a_1082,2);a_r1[0]=a_r1[1]=0;to_LIST(a_1082)->aupb+=2;}
a_1092(to_LIST(a_1082)->aupb,a_P);a_A[0]=a_P[0];
if(a_equal(a_A[0],to_LIST(a_1082)->aupb)){ return;}
a_unstack(a_1082);
a_unstackstring(a_1082); return;
} /* addLEXTentry */
static void a_1107(a_word a_A[1]){ /* readstring+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1078)->aupb;
a_L2=0;
a_G3:a_1099();
{ if(a_1088==34){ goto a_G5;}
 if(a_1088==10||a_1088==1){  goto a_G14;}
  goto a_G7;}
a_G5:a_1099();
if(!a_equal(a_1088,34)){ goto a_G9;}
a_G7:a_1093(a_1088);
a_incr(a_L2); goto a_G3;
a_G9:if(!a_equal(a_L2,0)){ goto a_G11;}
a_A[0]=702375912; return;
a_G11:a_packstring(a_1078,a_L2,a_1082);
a_unstackto(a_1078,a_L3);
a_1087(a_P);a_A[0]=a_P[0]; return;
a_G14:a_1007(a_1001,2130706295); return;
} /* readstring */
static void a_1109(a_word a_A[1]){ /* readtargetstring+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1078)->aupb;
a_L2=0;
if(a_equal(a_1088,34)){ goto a_G5;}
a_G4:a_1007(a_1001,2130706290); return;
a_G5:a_1099();
{ if(a_1088==34){ goto a_G7;}
 if(a_1088==10||a_1088==1){  goto a_G4;}
  goto a_G9;}
a_G7:a_1099();
if(!a_equal(a_1088,34)){ goto a_G11;}
a_G9:a_1093(a_1088);
a_incr(a_L2); goto a_G5;
a_G11:if(!a_equal(a_L2,0)){ goto a_G13;}
a_A[0]=702375912; return;
a_G13:a_packstring(a_1078,a_L2,a_1082);
a_unstackto(a_1078,a_L3);
a_1087(a_P);a_A[0]=a_P[0]; return;
} /* readtargetstring */
static void a_1108(a_word a_A[1]){ /* readtargetnumber+a> */
a_word a_L2;a_word a_L3;a_word a_P[1];
a_L3=to_LIST(a_1078)->aupb;
a_L2=1;
a_1093(88);
if(!a_equal(a_1088,45)){ goto a_G8;}
a_G5:a_1093(a_1088);
a_incr(a_L2);
a_1099();
a_G8:{ if((48<=a_1088 && a_1088<=57)){  goto a_G5;}
}
a_packstring(a_1078,a_L2,a_1082);
a_unstackto(a_1078,a_L3);
a_1087(a_P);a_A[0]=a_P[0]; return;
} /* readtargetnumber */
static void a_1105(a_word a_A[1]){ /* readbold+a> */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1099();
a_L3=to_LIST(a_1078)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1088 && a_1088<=122))){ goto a_G9;}
}
a_L4=a_1088;
a_1099();
a_1093(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1088,39)){ goto a_G11;}
a_1099(); goto a_G12;
a_G11:a_1007(a_1001,2130706283); return;
a_G12:a_packstring(a_1078,a_L2,a_1082);
a_unstackto(a_1078,a_L3);
a_A[0]=588109304;
a_G15:a_comparestring(a_1077,a_A[0],a_1082,to_LIST(a_1082)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G19;}
if(a_equal(a_A[0],588109229)){ goto a_G11;}
a_previousstring(a_1077,a_A[0]); goto a_G15;
a_G19:a_unstackstring(a_1082); return;
} /* readbold */
static void a_1110(a_word a_A[1]){ /* readtype+a> */
a_word a_L2;a_word a_L3;a_word a_L4;a_word a_P[1];
a_1099();
a_L3=to_LIST(a_1078)->aupb;
a_L2=0;
a_G4:{ if(!((97<=a_1088 && a_1088<=122))){ goto a_G9;}
}
a_L4=a_1088;
a_1099();
a_1093(a_L4);
a_incr(a_L2); goto a_G4;
a_G9:if(!a_equal(a_1088,32)){ goto a_G13;}
a_1093(32);
a_incr(a_L2);
a_1099(); goto a_G4;
a_G13:if(!a_equal(a_1088,62)){ goto a_G15;}
a_1099(); goto a_G16;
a_G15:a_1007(a_1001,2130706278); return;
a_G16:a_packstring(a_1078,a_L2,a_1082);
a_unstackto(a_1078,a_L3);
a_A[0]=588109399;
a_G19:a_comparestring(a_1077,a_A[0],a_1082,to_LIST(a_1082)->aupb,a_P);a_L2=a_P[0];
if(a_equal(a_L2,0)){ goto a_G23;}
if(a_equal(a_A[0],588109309)){ goto a_G15;}
a_previousstring(a_1077,a_A[0]); goto a_G19;
a_G23:a_unstackstring(a_1082); return;
} /* readtype */
static void a_1100(void){ /* nextsymbol */
a_word a_L1;a_word a_P[1];
a_G1:{ if(a_1088==32||a_1088==10){ goto a_G2;}
 if(a_1088==36){ goto a_G3;}
 if(a_1088==48){ goto a_G4;}
 if((49<=a_1088 && a_1088<=57)){ goto a_G7;}
 if(a_1088==70){ goto a_G20;}
 if(a_1088==73){ goto a_G31;}
 if(a_1088==76){ goto a_G45;}
 if(a_1088==78){ goto a_G56;}
 if(a_1088==88){ goto a_G67;}
 if(a_1088==84){ goto a_G70;}
 if(a_1088==39){ goto a_G73;}
 if(a_1088==60){ goto a_G74;}
 if(a_1088==34){ goto a_G76;}
 if(a_1088==38){ goto a_G78;}
 if(a_1088==93){ goto a_G79;}
 if(a_1088==41){ goto a_G80;}
 if(a_1088==58){ goto a_G81;}
 if(a_1088==44){ goto a_G82;}
 if(a_1088==126){ goto a_G83;}
 if(a_1088==47){ goto a_G84;}
 if(a_1088==45){ goto a_G85;}
 if(a_1088==35){ goto a_G100;}
 if(a_1088==40){ goto a_G101;}
 if(a_1088==124){ goto a_G102;}
 if(a_1088==62){ goto a_G103;}
 if(a_1088==43){ goto a_G106;}
 if(a_1088==46){ goto a_G107;}
 if(a_1088==59){ goto a_G108;}
 if(a_1088==42){ goto a_G109;}
 if(a_1088==91){ goto a_G110;}
 if(a_1088==94){ goto a_G111;}
 if(a_1088==64){ goto a_G112;}
 if(a_1088==1){  goto a_G113;}
  goto a_G114;}
a_G2:a_1099(); goto a_G1;
a_G3:a_1090(); goto a_G1;
a_G4:a_1096=588109463;
a_1097=0;
a_G6:a_1099(); return;
a_G7:a_1096=588109463;
{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G13;}
}
a_subtr(a_1088,48,a_1097);
a_1099();
if(a_more(a_1097,0)){ goto a_G14;}
if(a_equal(0,0)){ goto a_G14;}
a_G13:a_1007(a_1001,2130706310); return;
a_G14:{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G18;}
}
a_subtr(a_1088,48,a_L1);
a_1099();
a_addmult(a_1097,10,a_L1,a_1097); goto a_G14;
a_G18:if(!a_is(0)){ return;}
a_G19:a_subtr(0,a_1097,a_1097); return;
a_G20:a_1096=588109487;
a_1099();
{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G13;}
}
a_subtr(a_1088,48,a_1097);
a_1099();
if(a_more(a_1097,0)){ goto a_G27;}
if(!a_equal(0,0)){ goto a_G13;}
a_G27:{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G18;}
}
a_subtr(a_1088,48,a_L1);
a_1099();
a_addmult(a_1097,10,a_L1,a_1097); goto a_G27;
a_G31:a_1096=588109483;
a_1099();
{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G13;}
}
a_subtr(a_1088,48,a_1097);
a_1099();
if(a_more(a_1097,0)){ goto a_G38;}
if(!a_equal(0,0)){ goto a_G13;}
a_G38:{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G42;}
}
a_subtr(a_1088,48,a_L1);
a_1099();
a_addmult(a_1097,10,a_L1,a_1097); goto a_G38;
a_G42:if(!a_is(0)){ goto a_G44;}
a_subtr(0,a_1097,a_1097);
a_G44:a_P[0]=a_1097;a_1020(a_P);a_1097=a_P[0]; return;
a_G45:a_1096=588109491;
a_1099();
{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G13;}
}
a_subtr(a_1088,48,a_1097);
a_1099();
if(a_more(a_1097,0)){ goto a_G52;}
if(!a_equal(0,0)){ goto a_G13;}
a_G52:{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G18;}
}
a_subtr(a_1088,48,a_L1);
a_1099();
a_addmult(a_1097,10,a_L1,a_1097); goto a_G52;
a_G56:a_1096=588109479;
a_1099();
{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G13;}
}
a_subtr(a_1088,48,a_1097);
a_1099();
if(a_more(a_1097,0)){ goto a_G63;}
if(!a_equal(0,0)){ goto a_G13;}
a_G63:{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G18;}
}
a_subtr(a_1088,48,a_L1);
a_1099();
a_addmult(a_1097,10,a_L1,a_1097); goto a_G63;
a_G67:a_1096=588109467;
a_1099();
a_1108(a_P);a_1097=a_P[0]; return;
a_G70:a_1096=588109471;
a_1099();
a_1109(a_P);a_1097=a_P[0]; return;
a_G73:a_1105(a_P);a_1096=a_P[0]; return;
a_G74:a_1096=588109475;
a_1110(a_P);a_1097=a_P[0]; return;
a_G76:a_1096=588109495;
a_1107(a_P);a_1097=a_P[0]; return;
a_G78:a_1096=588109405; goto a_G6;
a_G79:a_1096=588109408; goto a_G6;
a_G80:a_1096=588109411; goto a_G6;
a_G81:a_1096=588109414; goto a_G6;
a_G82:a_1096=588109417; goto a_G6;
a_G83:a_1096=588109420; goto a_G6;
a_G84:a_1096=588109423; goto a_G6;
a_G85:a_1099();
{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G98;}
}
a_1096=588109463;
{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G13;}
}
a_subtr(a_1088,48,a_1097);
a_1099();
if(a_more(a_1097,0)){ goto a_G93;}
if(!a_equal(1,0)){ goto a_G13;}
a_G93:{ if(!((48<=a_1088 && a_1088<=57))){ goto a_G97;}
}
a_subtr(a_1088,48,a_L1);
a_1099();
a_addmult(a_1097,10,a_L1,a_1097); goto a_G93;
a_G97:if(!a_is(1)){ return;} goto a_G19;
a_G98:a_1096=588109426;
a_1097=0; return;
a_G100:a_1096=588109432; goto a_G6;
a_G101:a_1096=588109435; goto a_G6;
a_G102:a_1096=588109438; goto a_G6;
a_G103:a_1096=588109441;
a_1099();
a_1106(a_P);a_1097=a_P[0]; return;
a_G106:a_1096=588109444; goto a_G6;
a_G107:a_1096=588109447; goto a_G6;
a_G108:a_1096=588109450; goto a_G6;
a_G109:a_1096=588109453; goto a_G6;
a_G110:a_1096=588109456; goto a_G6;
a_G111:a_1096=588109459; goto a_G6;
a_G112:a_1096=588109402; goto a_G6;
a_G113:a_1096=588109498; return;
a_G114:a_1007(a_1001,2130706273); return;
} /* nextsymbol */
static void a_1117(a_word a_F1){ /* writenum+>a */

if(!a_equal(a_F1,(-1-2147483647))){ goto a_G5;}
a_putchar(a_1083,45);
a_subtr(-1,a_F1,a_F1);
a_1116(a_F1,49); return;
a_G5:if(!a_less(a_F1,0)){ goto a_G8;}
a_putchar(a_1083,45);
a_getabs(a_F1,a_F1);
a_G8:a_1116(a_F1,48); return;
} /* writenum */
static void a_1116(a_word a_F1,a_word a_F2){ /* wnum1+>a+>a */
a_word a_L3;a_word a_L4;
a_divrem11(a_F1,10,a_L3,a_L4);
if(a_equal(a_L3,0)){ goto a_G4;}
a_1116(a_L3,48);
a_G4:a_add(a_L4,a_F2,a_L4);
a_putchar(a_1083,a_L4); return;
} /* wnum1 */
static void a_1119(void){ /* wspace */

if(a_is(a_1118)){ return;}
a_putchar(a_1083,32);
a_1118=1; return;
} /* wspace */
static void a_1085(a_word a_F1){ /* W+>a */

if(!a_equal(a_F1,588109429)){ goto a_G4;}
a_1118=1;
a_putchar(a_1083,10); return;
a_G4:if(!a_lseq(588109229,a_F1)){ goto a_G10;}
if(!a_lseq(a_F1,588109304)){ goto a_G10;}
a_putchar(a_1083,39);
a_1157(a_1083,a_1077,a_F1);
a_putchar(a_1083,39);
a_G9:a_1118=1; return;
a_G10:if(!a_lseq(588109309,a_F1)){ goto a_G16;}
if(!a_lseq(a_F1,588109399)){ goto a_G16;}
a_putchar(a_1083,60);
a_1157(a_1083,a_1077,a_F1);
a_putchar(a_1083,62);
a_1118=0; return;
a_G16:if(!a_was(a_1077,a_F1)){ goto a_G18;}
a_1157(a_1083,a_1077,a_F1); goto a_G9;
a_G18:a_1010(a_1001,2130706268); return;
} /* W */
static void a_1086(a_word a_F1,a_word a_F2){ /* WW+>a+>a */
a_word a_P[1];
{ if(a_F1==588109463){ goto a_G2;}
 if(a_F1==588109475){ goto a_G5;}
 if(a_F1==588109495){ goto a_G6;}
 if(a_F1==588109441){ goto a_G9;}
 if(a_F1==588109487){ goto a_G13;}
 if(a_F1==588109491){ goto a_G15;}
 if(a_F1==588109479){ goto a_G12;}
 if(a_F1==588109467){ goto a_G17;}
 if(a_F1==588109471){ goto a_G20;}
 if(a_F1==588109483){  goto a_G24;}
  goto a_G27;}
a_G2:a_1119();
a_G3:a_1117(a_F2);
a_G4:a_1118=0; return;
a_G5:a_1085(a_F2); return;
a_G6:a_1119();
a_1094(a_F2,a_P);a_F2=a_P[0];
a_1155(a_1083,a_1082,a_F2); goto a_G4;
a_G9:a_1119();
a_putchar(a_1083,62);
if(a_lseq(a_F2,0)){ goto a_G3;}
a_G12:a_putchar(a_1083,78); goto a_G3;
a_G13:a_1119();
a_putchar(a_1083,70); goto a_G3;
a_G15:a_1119();
a_putchar(a_1083,76); goto a_G3;
a_G17:a_1119();
a_1094(a_F2,a_P);a_F2=a_P[0];
a_1157(a_1083,a_1082,a_F2); goto a_G4;
a_G20:a_1119();
a_putchar(a_1083,84);
a_1118=1;
a_1086(588109495,a_F2); return;
a_G24:a_1119();
a_putchar(a_1083,73);
a_1052(a_F2,a_P);a_F2=a_P[0]; goto a_G3;
a_G27:a_1010(a_1001,2130706265); return;
} /* WW */
static a_word a_1125(a_word a_F1,a_word a_F2){ /* isfirstarg+t[]+>a */
a_word a_L2;a_word a_P[1];
a_comparestring(a_1159,a_1121,a_F1,a_F2,a_P);a_L2=a_P[0];
if(!a_equal(a_L2,0)){ return 0;} return 1;
} /* isfirstarg */
static void a_1128(void){ /* parseSTDARG */
a_word a_P[3];
a_1121=to_LIST(a_1159)->aupb;
a_G2:if(a_less(a_1121,to_LIST(a_1159)->alwb)){ return;}
if(!a_1125(a_1001,2130706349)){ goto a_G5;}
a_P[0]=2130706068;a_1008(1,1,a_P); return;
a_G5:if(!a_1125(a_1001,2130706345)){ goto a_G7;}
a_P[0]=2130706137;a_P[1]=1;a_P[2]=1;a_1008(1,3,a_P); return;
a_G7:if(!a_1125(a_1001,2130706340)){ goto a_G10;}
a_previousstring(a_1159,a_1121);
a_1130=1; goto a_G2;
a_G10:if(!a_1125(a_1001,2130706335)){ goto a_G13;}
a_previousstring(a_1159,a_1121);
a_1062=0; goto a_G2;
a_G13:if(!a_is(a_1127)){ goto a_G15;}
a_P[0]=2130706179;a_1008(1,1,a_P); return;
a_G15:if(!a_is(a_1124)){ goto a_G18;}
a_1127=a_1121;
a_G17:a_previousstring(a_1159,a_1121); goto a_G2;
a_G18:a_1124=a_1121; goto a_G17;
} /* parseSTDARG */
static void a_1122(void){ /* checkcommandlinearguments */
a_word a_P[1];
a_1128();
if(!a_equal(a_1124,0)){ goto a_G4;}
a_P[0]=2130706151;a_1008(1,1,a_P); return;
a_G4:if(!a_equal(a_1127,0)){ goto a_G7;}
if(a_is(a_1130)){ return;}
a_P[0]=2130706165;a_1008(1,1,a_P); return;
a_G7:if(!a_is(a_1130)){ return;}
a_P[0]=2130706179;a_1008(1,1,a_P); return;
} /* checkcommandlinearguments */
static void a_1132(a_word a_F1){ /* setrepr+>a */

if(!a_1056(a_F1,128)){ return;}
to_LIST(a_1018)->offset[a_F1]=a_1126;
a_incr(a_1126); return;
} /* setrepr */
static void a_1129(void){ /* renumberitems */
a_word a_L1;
a_L1=to_LIST(a_1018)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1018)->aupb)){ return;}
a_1132(a_L1);
a_next(a_1018,a_L1); goto a_G2;
} /* renumberitems */
static void a_1123(void){ /* firstpass */

a_1055();
a_1058();
a_1043();
a_1067(); return;
} /* firstpass */
static void a_1131(void){ /* secondpass */

a_1031();
a_1034();
a_1021();
a_1040(); return;
} /* secondpass */
static void a_1120(void){ /* @root */

a_1122();
a_1101(a_1124);
a_1123();
a_1074();
a_1129();
a_1112(a_1127,2130706186);
a_1131();
a_1089(); return;
} /* @root */
static void a_1144(a_word a_F1){ /* pushAUX+>a */

{register a_word *a_r1=a_extension(a_1134,1);a_r1[0]=a_F1;to_LIST(a_1134)->aupb+=1;}
  return;
} /* pushAUX */
static void a_1150(a_word a_F1){ /* startrule+>a */

a_scratch(a_1137);
a_scratch(a_1134);
a_1143=0;
a_1151=to_LIST(a_1137)->alwb;
a_G5:if(a_lseq(a_F1,0)){ return;}
{register a_word *a_r1=a_extension(a_1137,8);a_r1[0]=a_r1[1]=a_r1[2]=a_r1[3]=a_r1[4]=a_r1[5]=0;a_r1[6]=a_r1[7]=-1000;to_LIST(a_1137)->aupb+=8;}
a_decr(a_F1); goto a_G5;
} /* startrule */
static a_word a_1148(a_word a_F1,a_word a_F2){ /* samecontent+>a+>a */
a_word a_L3;
if(!a_equal(to_LIST(a_1137)->offset[a_F1-7],to_LIST(a_1137)->offset[a_F2-7])){ return 0;}
if(!a_equal(to_LIST(a_1137)->offset[a_F1-4],to_LIST(a_1137)->offset[a_F2-4])){ return 0;}
if(!a_equal(to_LIST(a_1137)->offset[a_F1-3],to_LIST(a_1137)->offset[a_F2-3])){ return 0;}
a_L3=to_LIST(a_1137)->offset[a_F1-4];
a_F1=to_LIST(a_1137)->offset[a_F1-2];
a_F2=to_LIST(a_1137)->offset[a_F2-2];
a_G7:if(a_less(a_L3,0)){ return 1;}
if(!a_equal(to_LIST(a_1134)->offset[a_F1],to_LIST(a_1134)->offset[a_F2])){ return 0;}
a_incr(a_F1);
a_incr(a_F2);
a_decr(a_L3); goto a_G7;
} /* samecontent */
static void a_1149(a_word a_F1,a_word a_F2){ /* startnode+>a+>a */

a_incr(a_1143);
if(a_equal(a_1143,a_F2)){ goto a_G4;}
a_G3:a_1007(a_1001,2130706371); return;
a_G4:if(!a_lseq(a_1151,to_LIST(a_1137)->aupb)){ goto a_G3;}
a_1144(0);
to_LIST(a_1137)->offset[a_1151-7]=a_F1;
to_LIST(a_1137)->offset[a_1151-6]=a_F2;
to_LIST(a_1137)->offset[a_1151-2]=to_LIST(a_1134)->aupb; return;
} /* startnode */
static void a_1136(a_word a_F1,a_word a_F2){ /* NN+>a+>a */

{ if(a_F1==588109483||a_F1==588109463||a_F1==588109491||a_F1==588109487||a_F1==588109467){ goto a_G2;}
 if(a_F1==588109479){ goto a_G4;}
 if(a_F1==588109441){  goto a_G5;}
  goto a_G4;}
a_G2:a_1144(a_F1);
a_1144(a_F2); return;
a_G4:a_1007(a_1001,2130706366); return;
a_G5:{register a_word a_r1=to_LIST(a_1137)->offset[a_1151-7];
 if(a_r1==588109236){ goto a_G2;}
 if(!(a_r1==588109250)){ goto a_G8;}
}
a_G6:if(!a_equal(to_LIST(a_1137)->offset[a_1151],-1000)){ goto a_G4;}
to_LIST(a_1137)->offset[a_1151]=a_F2; return;
a_G8:if(!a_equal(to_LIST(a_1137)->offset[a_1151-1],-1000)){ goto a_G6;}
to_LIST(a_1137)->offset[a_1151-1]=a_F2; return;
} /* NN */
static void a_1135(a_word a_F1){ /* N+>a */

a_1144(a_F1); return;
} /* N */
static void a_1141(void){ /* enternode */
a_word a_L1;a_word a_P[1];
if(a_equal(to_LIST(a_1137)->offset[a_1151-7],588109236)){ goto a_G4;}
if(a_noteq(to_LIST(a_1137)->offset[a_1151],-1000)){ goto a_G4;}
a_1007(a_1001,2130706363); return;
a_G4:a_subtr(to_LIST(a_1134)->aupb,to_LIST(a_1137)->offset[a_1151-2],to_LIST(a_1137)->offset[a_1151-4]);
a_blockhash(a_1134,to_LIST(a_1137)->offset[a_1151-2],a_P);to_LIST(a_1137)->offset[a_1151-3]=a_P[0];
a_L1=a_1151;
a_G7:a_previous(a_1137,a_L1);
if(a_less(a_L1,to_LIST(a_1137)->alwb)){ goto a_G16;}
if(!a_1148(a_L1,a_1151)){ goto a_G7;}
if(a_equal(to_LIST(a_1137)->offset[a_L1-5],0)){ goto a_G12;}
a_1010(a_1001,2130706363); return;
a_G12:to_LIST(a_1137)->offset[a_L1-5]=a_1151;
a_unstackto(a_1134,to_LIST(a_1137)->offset[a_1151-2]);
a_unstack(a_1134);
to_LIST(a_1137)->offset[a_1151-2]=to_LIST(a_1137)->offset[a_L1-2];
a_G16:a_next(a_1137,a_1151); return;
} /* enternode */
static void a_1142(a_word a_F1,a_word a_A[1]){ /* getnoderepr+>a+a> */

if(!a_lseq(a_F1,0)){ goto a_G3;}
a_A[0]=a_F1; return;
a_G3:a_decr(a_F1);
a_mult(a_F1,8,a_F1);
a_add(a_F1,to_LIST(a_1137)->alwb,a_F1);
a_A[0]=to_LIST(a_1137)->offset[a_F1-6]; return;
} /* getnoderepr */
static void a_1147(a_word a_F1,a_word a_F2){ /* replacenode+>a+>a */
a_word a_L3;a_word a_L4;a_word a_L5;
if(a_less(a_F1,a_F2)){ goto a_G3;}
a_G2:a_1010(a_1001,2130706358); return;
a_G3:a_L4=to_LIST(a_1137)->offset[a_F2-6];
{register a_word a_r1=to_LIST(a_1137)->offset[a_F1-6];a_L5=a_r1;to_LIST(a_1137)->offset[a_F2-6]=a_r1;}
to_LIST(a_1137)->offset[a_F2-3]=1;
a_L3=a_F1;
a_G7:if(a_equal(a_L3,0)){ goto a_G2;}
if(!a_equal(to_LIST(a_1137)->offset[a_L3-5],a_F2)){ goto a_G10;}
to_LIST(a_1137)->offset[a_L3-5]=to_LIST(a_1137)->offset[a_F2-5]; goto a_G11;
a_G10:a_L3=to_LIST(a_1137)->offset[a_L3-5]; goto a_G7;
a_G11:a_L3=to_LIST(a_1137)->alwb;
a_G12:if(a_more(a_L3,to_LIST(a_1137)->aupb)){ return;}
if(!a_equal(to_LIST(a_1137)->offset[a_L3-1],a_L4)){ goto a_G15;}
to_LIST(a_1137)->offset[a_L3-1]=a_L5;
a_G15:if(!a_equal(to_LIST(a_1137)->offset[a_L3],a_L4)){ goto a_G17;}
to_LIST(a_1137)->offset[a_L3]=a_L5;
a_G17:a_next(a_1137,a_L3); goto a_G12;
} /* replacenode */
static a_word a_1138(a_word a_F1){ /* checknode+>a */
a_word a_L2;
a_L2=to_LIST(a_1137)->offset[a_F1-5];
a_G2:if(a_equal(a_L2,0)){ return 0;}
if(!a_equal(to_LIST(a_1137)->offset[a_F1-1],to_LIST(a_1137)->offset[a_L2-1])){ goto a_G6;}
if(!a_equal(to_LIST(a_1137)->offset[a_F1],to_LIST(a_1137)->offset[a_L2])){ goto a_G6;}
a_1147(a_F1,a_L2); return 1;
a_G6:a_L2=to_LIST(a_1137)->offset[a_L2-5]; goto a_G2;
} /* checknode */
static void a_1146(void){ /* replaceall */
a_word a_L1;
a_G1:a_L1=to_LIST(a_1137)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1137)->aupb)){ return;}
if(a_1138(a_L1)){ goto a_G1;}
a_next(a_1137,a_L1); goto a_G2;
} /* replaceall */
static void a_1145(void){ /* renumbernodes */
a_word a_L1;a_word a_P[1];
a_L1=to_LIST(a_1137)->alwb;
a_1152=0;
a_G3:if(a_more(a_L1,to_LIST(a_1137)->aupb)){ return;}
if(!a_equal(to_LIST(a_1137)->offset[a_L1-3],0)){ goto a_G8;}
a_incr(a_1152);
to_LIST(a_1137)->offset[a_L1-6]=a_1152;
a_G7:a_next(a_1137,a_L1); goto a_G3;
a_G8:a_1142(to_LIST(a_1137)->offset[a_L1-6],a_P);to_LIST(a_1137)->offset[a_L1-6]=a_P[0]; goto a_G7;
} /* renumbernodes */
static void a_1139(a_word a_F1,a_word a_F2){ /* dumpAUX+>a+>a */
a_word a_L3;a_word a_P[1];
a_incr(a_F1);
a_G2:if(a_lseq(a_F2,0)){ return;}
a_L3=to_LIST(a_1134)->offset[a_F1];
a_incr(a_F1);
a_decr(a_F2);
{ if(a_L3==588109483||a_L3==588109463||a_L3==588109491||a_L3==588109487||a_L3==588109467){ goto a_G7;}
 if(a_L3==588109441){  goto a_G10;}
  goto a_G12;}
a_G7:a_1086(a_L3,to_LIST(a_1134)->offset[a_F1]);
a_G8:a_incr(a_F1);
a_decr(a_F2); goto a_G2;
a_G10:a_1142(to_LIST(a_1134)->offset[a_F1],a_P);a_L3=a_P[0];
a_1086(588109441,a_L3); goto a_G8;
a_G12:a_1085(a_L3); goto a_G2;
} /* dumpAUX */
static void a_1140(void){ /* dumprule */
a_word a_L1;a_word a_L2;a_word a_P[1];
a_L1=to_LIST(a_1137)->alwb;
a_G2:if(a_more(a_L1,to_LIST(a_1137)->aupb)){ goto a_G5;}
to_LIST(a_1137)->offset[a_L1-3]=0;
a_next(a_1137,a_L1); goto a_G2;
a_G5:a_1146();
a_1145();
a_1086(588109463,a_1152);
a_L1=to_LIST(a_1137)->alwb;
a_G9:if(!a_more(a_L1,to_LIST(a_1137)->aupb)){ goto a_G12;}
a_1085(588109447);
a_1085(588109429); return;
a_G12:if(!a_is(to_LIST(a_1137)->offset[a_L1-3])){ goto a_G14;}
a_G13:a_next(a_1137,a_L1); goto a_G9;
a_G14:a_1085(to_LIST(a_1137)->offset[a_L1-7]);
a_1086(588109479,to_LIST(a_1137)->offset[a_L1-6]);
a_1139(to_LIST(a_1137)->offset[a_L1-2],to_LIST(a_1137)->offset[a_L1-4]);
if(a_equal(to_LIST(a_1137)->offset[a_L1-1],-1000)){ goto a_G20;}
a_1142(to_LIST(a_1137)->offset[a_L1-1],a_P);a_L2=a_P[0];
a_1086(588109441,a_L2);
a_G20:if(a_equal(to_LIST(a_1137)->offset[a_L1],-1000)){ goto a_G23;}
a_1142(to_LIST(a_1137)->offset[a_L1],a_P);a_L2=a_P[0];
a_1086(588109441,a_L2);
a_G23:a_1085(588109417); goto a_G13;
} /* dumprule */
static void a_1155(a_word a_F1,a_word a_F2,a_word a_F3){ /* putasstring+""f+t[]+>a */
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
static void a_1157(a_word a_F1,a_word a_F2,a_word a_F3){ /* putstring+""f+t[]+>a */
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
