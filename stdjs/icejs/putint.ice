$ ICE file, produced by ALEPH compiler v2.4
'module' "stdlib" "jslib put int" 32 
4 50 "putint"
51 132 "stdlib"
.
<rule> I1 520 81 2<formal in><formal in> "stdlib" "@equal"
<rule> I2 520 81 2<formal in><formal in> "stdlib" "@less"
<rule> I3 520 82 2<formal in><formal in> "stdlib" "@more"
<rule> I4 16640 48 0 "stdlib" "@root"
<rule> I5 8 75 3<formal in><formal in><formal out> "stdlib" "add"
<rule> I6 8 86 3<formal in><formal in><formal out> "stdlib" "boolor"
<rule> I7 8 77 1<formal inout> "stdlib" "decr"
<rule> I8 8 77 4<formal in><formal in><formal out><formal out> "stdlib" "divrem"
<rule> I9 8 78 2<formal in><formal out> "stdlib" "getabs"
<constant> I10 0 73 "stdlib" "intsize"
<constant> I11 0 73 "stdlib" "maxint"
<constant> I12 0 73 "stdlib" "minint"
<rule> I13 264 109 2<formal file><formal in> "stdlib" "putchar"
<rule> I14 260 33 2<formal file><formal in> "stdlib" "putint"
<rule> I15 256 39 4<formal file><formal in><formal in><formal in> "stdlib" "putint1"
.
'expression'I11 X2147483647.
'expression'I12-I11+X-1.
'expression'I10 X10.
'rule'I14 0 0 8'node'N1 I6 3 1 0 F2 X0 F2 >0 >N2,'node'N2 I3 2 0 0 F2 X0 >N4 >N3,'node'N3 I15 4 0 0 F1 F2 X32 I10 >0 >-1,'node'N4 I1 2 0 0 F2 X0 >N6 >N5,'node'N5 I15 4 0 0 F1 F2 X48 I10 >0 >-1,'node'N6 I1 2 0 0 F2 I12 >N8 >N7,'node'N7 I15 4 0 0 F1 F2 X45 I10 >0 >-1,'node'N8 I9 2 1 0 F2 F2 >0 >N7,.
'rule'I15 4 5 15'node'N1 I2 2 0 0 F4 X0 >N2 >-1,'node'N2 I1 2 0 0 F2 X0 >N6 >N3,'node'N3 I7 1 1 0 F4 >0 >N4,'node'N4 I15 4 0 0 F1 X0 X32 F4 >0 >N5,'node'N5 I13 2 0 0 F1 F3 >0 >-1,'node'N6 I3 2 0 0 F2 X0 >N12 >N7,'node'N7 I7 1 1 0 F4 >0 >N8,'node'N8 I8 4 2 0 F2 X10 L4 L5 >0 >N9,'node'N9 I15 4 0 0 F1 L4 F3 F4 >0 >N10,'node'N10 I5 3 1 0 L5 X48 L5 >0 >N11,'node'N11 I13 2 0 0 F1 L5 >0 >-1,'node'N12 I7 1 1 0 F4 >0 >N13,'node'N13 I8 4 2 0 I11 X10 L4 L5 >0 >N14,'node'N14 I15 4 0 0 F1 L4 F3 F4 >0 >N15,'node'N15 I5 3 1 0 L5 X49 L5 >0 >N11,.
'rule'I4 0 0 0.
