$ ICE file, produced by ALEPH compiler v2.4
'module' "stdlib" "jslib format print" 32 
4 61 "formatprint"
62 142 "stdlib"
.
<rule> I1 520 92 2<formal in><formal in> "stdlib" "@equal"
<rule> I2 520 92 2<formal in><formal in> "stdlib" "@less"
<rule> I3 98312 94 3<formal in><formal anchor><formal out> "stdlib" "@make"
<rule> I4 520 92 2<formal in><formal in> "stdlib" "@noteq"
<rule> I5 16640 59 0 "stdlib" "@root"
<rule> I6 8 86 3<formal in><formal in><formal out> "stdlib" "add"
<rule> I7 8 97 3<formal in><formal in><formal out> "stdlib" "booland"
<rule> I8 8 97 3<formal in><formal in><formal out> "stdlib" "boolor"
<rule> I9 8 88 4<formal in><formal in><formal out><formal out> "stdlib" "divrem"
<rule> I10 33028 48 4<formal file><formal table> 1 1<formal anchor><formal in> "stdlib" "fprintf"
<rule> I11 8 89 2<formal in><formal out> "stdlib" "getabs"
<constant> I12 0 33 "stdlib" "hexshift"
<rule> I13 8 88 1<formal inout> "stdlib" "incr"
<constant> I14 0 84 "stdlib" "maxint"
<constant> I15 0 84 "stdlib" "minint"
<constant> I16 0 116 "stdlib" "newline"
<rule> I17 256 42 2<formal file><formal in> "stdlib" "printhex"
<rule> I18 256 44 2<formal file><formal in> "stdlib" "printhex1"
<rule> I19 256 34 2<formal file><formal in> "stdlib" "printint"
<rule> I20 256 39 3<formal file><formal in><formal in> "stdlib" "printint1"
<rule> I21 264 120 2<formal file><formal in> "stdlib" "putchar"
<rule> I22 8 98 2<formal inout><formal in> "stdlib" "rightclear"
<rule> I23 33288 -2 1<formal shift> "" "shiftaffixblock"
<rule> I24 520 107 4<formal table> 1 1<formal in><formal in><formal out> "stdlib" "stringelem"
<rule> I25 8 86 3<formal in><formal in><formal out> "stdlib" "subtr"
.
'expression'I12 X97+X-10.
'expression'I14 X2147483647.
'expression'I15-I14+X-1.
'expression'I16 X10.
'rule'I19 0 0 9'node'N1 I8 3 1 0 F2 X0 F2 >0 >N2,'node'N2 I1 2 0 0 F2 I15 >N6 >N3,'node'N3 I21 2 0 0 F1 X45 >0 >N4,'node'N4 I25 3 1 0 X-1 F2 F2 >0 >N5,'node'N5 I20 3 0 0 F1 F2 X49 >0 >-1,'node'N6 I2 2 0 0 F2 X0 >N9 >N7,'node'N7 I21 2 0 0 F1 X45 >0 >N8,'node'N8 I11 2 1 0 F2 F2 >0 >N9,'node'N9 I20 3 0 0 F1 F2 X48 >0 >-1,.
'rule'I20 3 4 5'node'N1 I9 4 2 0 F2 X10 L3 L4 >0 >N2,'node'N2 I1 2 0 0 L3 X0 >N3 >N4,'node'N3 I20 3 0 0 F1 L3 X48 >0 >N4,'node'N4 I6 3 1 0 L4 F3 L4 >0 >N5,'node'N5 I21 2 0 0 F1 L4 >0 >-1,.
'rule'I17 0 0 2'node'N1 I8 3 1 0 F2 X0 F2 >0 >N2,'node'N2 I18 2 0 0 F1 F2 >0 >-1,.
'rule'I18 2 2 8'node'N1 I7 3 1 0 F2 X15 L2 >0 >N2,'node'N2 I22 2 1 0 F2 X4 >0 >N3,'node'N3 I1 2 0 0 F2 X0 >N4 >N5,'node'N4 I18 2 0 0 F1 F2 >0 >N5,'node'N5 I2 2 0 0 L2 X10 >N7 >N6,'node'N6 I6 3 1 0 X48 L2 L2 >0 >N8,'node'N7 I6 3 1 0 L2 I12 L2 >0 >N8,'node'N8 I21 2 0 0 F1 L2 >0 >-1,.
'rule'I10 2 4 16'node'N1 I3 2 1 0 F4@1 L2 >0 >N2,'node'N2 I3 2 1 0 X0@1 L3 >0 >N3,'node'N3 I24 4 1 0 F2 L2 L3 L4 >-1 >N4,'node'N4 I13 1 1 0 L3 >0 >N5,'node'N5 I4 2 0 0 L4 X37 >N7 >N6,'node'N6 I21 2 0 0 F1 L4 >0 >N3,'node'N7 I24 4 1 0 F2 L2 L3 L4 >N9 >N8,'node'N8 I13 1 1 0 L3 >0 >N9,'box'N9 L4'area'52 X110 >N10'area'53 X99 >N11'area'54 X100 >N13'area'55 X120 >N15'area'56:>N6,'node'N10 I21 2 0 0 F1 I16 >0 >N3,'node'N11 I23 1 0 0 F3 >-1 >N12,'node'N12 I21 2 0 0 F1 F4 >0 >N3,'node'N13 I23 1 0 0 F3 >-1 >N14,'node'N14 I19 2 0 0 F1 F4 >0 >N3,'node'N15 I23 1 0 0 F3 >-1 >N16,'node'N16 I17 2 0 0 F1 F4 >0 >N3,.
'rule'I5 0 0 0.
