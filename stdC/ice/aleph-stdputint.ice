$ ICE file, produced by ALEPH compiler v2.2
'module' "stdlib" "stdlib put int" 32 
4 49 "aleph-stdputint"
50 130 "stdlib"
.
<rule> I1 520 80 2<formal in><formal in> "stdlib" "@equal"
<rule> I2 520 80 2<formal in><formal in> "stdlib" "@less"
<rule> I3 520 81 2<formal in><formal in> "stdlib" "@more"
<rule> I4 16640 47 0 "stdlib" "@root"
<rule> I5 8 74 3<formal in><formal in><formal out> "stdlib" "add"
<rule> I6 8 76 1<formal inout> "stdlib" "decr"
<rule> I7 8 76 4<formal in><formal in><formal out><formal out> "stdlib" "divrem"
<rule> I8 8 77 2<formal in><formal out> "stdlib" "getabs"
<constant> I9 0 72 "stdlib" "intsize"
<constant> I10 0 72 "stdlib" "maxint"
<constant> I11 0 72 "stdlib" "minint"
<rule> I12 264 108 2<formal file><formal in> "stdlib" "putchar"
<rule> I13 260 33 2<formal file><formal in> "stdlib" "putint"
<rule> I14 256 38 4<formal file><formal in><formal in><formal in> "stdlib" "putint1"
.
'expression'I10 X2147483647.
'expression'I11-I10+X-1.
'expression'I9 X10.
'rule'I13 0 0 7'node'N1 I3 2 0 0 F2 X0 >N3 >N2,'node'N2 I14 4 0 0 F1 F2 X32 I9 >0 >-1,'node'N3 I1 2 0 0 F2 X0 >N5 >N4,'node'N4 I14 4 0 0 F1 F2 X48 I9 >0 >-1,'node'N5 I1 2 0 0 F2 I11 >N7 >N6,'node'N6 I14 4 0 0 F1 F2 X45 I9 >0 >-1,'node'N7 I8 2 1 0 F2 F2 >0 >N6,.
'rule'I14 4 5 15'node'N1 I2 2 0 0 F4 X0 >N2 >-1,'node'N2 I1 2 0 0 F2 X0 >N6 >N3,'node'N3 I6 1 1 0 F4 >0 >N4,'node'N4 I14 4 0 0 F1 X0 X32 F4 >0 >N5,'node'N5 I12 2 0 0 F1 F3 >0 >-1,'node'N6 I3 2 0 0 F2 X0 >N12 >N7,'node'N7 I6 1 1 0 F4 >0 >N8,'node'N8 I7 4 2 0 F2 X10 L4 L5 >0 >N9,'node'N9 I14 4 0 0 F1 L4 F3 F4 >0 >N10,'node'N10 I5 3 1 0 L5 X48 L5 >0 >N11,'node'N11 I12 2 0 0 F1 L5 >0 >-1,'node'N12 I6 1 1 0 F4 >0 >N13,'node'N13 I7 4 2 0 I10 X10 L4 L5 >0 >N14,'node'N14 I14 4 0 0 F1 L4 F3 F4 >0 >N15,'node'N15 I5 3 1 0 L5 X49 L5 >0 >N11,.
'rule'I4 0 0 0.
