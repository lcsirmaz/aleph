$ ICE file, produced by ALEPH compiler v2.3
'module' "stdlib" "libC format print" 32 
4 62 "formatprint"
63 143 "stdlib"
.
<rule> I1 520 93 2<formal in><formal in> "stdlib" "@equal"
<rule> I2 520 93 2<formal in><formal in> "stdlib" "@less"
<rule> I3 98312 95 3<formal in><formal anchor><formal out> "stdlib" "@make"
<rule> I4 520 93 2<formal in><formal in> "stdlib" "@noteq"
<rule> I5 16640 60 0 "stdlib" "@root"
<rule> I6 8 87 3<formal in><formal in><formal out> "stdlib" "add"
<rule> I7 8 98 3<formal in><formal in><formal out> "stdlib" "booland"
<rule> I8 8 89 4<formal in><formal in><formal out><formal out> "stdlib" "divrem"
<rule> I9 33028 49 4<formal file><formal table> 1 1<formal anchor><formal in> "stdlib" "fprintf"
<rule> I10 8 90 2<formal in><formal out> "stdlib" "getabs"
<constant> I11 0 34 "stdlib" "hexshift"
<rule> I12 8 89 1<formal inout> "stdlib" "incr"
<constant> I13 0 85 "stdlib" "maxint"
<constant> I14 0 85 "stdlib" "minint"
<constant> I15 0 117 "stdlib" "newline"
<rule> I16 256 43 2<formal file><formal in> "stdlib" "printhex"
<rule> I17 256 45 2<formal file><formal in> "stdlib" "printhex1"
<rule> I18 256 36 2<formal file><formal in> "stdlib" "printint"
<rule> I19 256 40 3<formal file><formal in><formal in> "stdlib" "printint1"
<rule> I20 264 121 2<formal file><formal in> "stdlib" "putchar"
<rule> I21 8 99 2<formal inout><formal in> "stdlib" "rightclear"
<rule> I22 33288 -2 1<formal shift> "" "shiftaffixblock"
<rule> I23 520 108 4<formal table> 1 1<formal in><formal in><formal out> "stdlib" "stringelem"
<rule> I24 8 87 3<formal in><formal in><formal out> "stdlib" "subtr"
.
'expression'I11 X97+X-10.
'expression'I13 X2147483647.
'expression'I14-I13+X-1.
'expression'I15 X10.
'rule'I18 0 0 8'node'N1 I1 2 0 0 F2 I14 >N5 >N2,'node'N2 I20 2 0 0 F1 X45 >0 >N3,'node'N3 I24 3 1 0 X-1 F2 F2 >0 >N4,'node'N4 I19 3 0 0 F1 F2 X49 >0 >-1,'node'N5 I2 2 0 0 F2 X0 >N8 >N6,'node'N6 I20 2 0 0 F1 X45 >0 >N7,'node'N7 I10 2 1 0 F2 F2 >0 >N8,'node'N8 I19 3 0 0 F1 F2 X48 >0 >-1,.
'rule'I19 3 4 5'node'N1 I8 4 2 0 F2 X10 L3 L4 >0 >N2,'node'N2 I1 2 0 0 L3 X0 >N3 >N4,'node'N3 I19 3 0 0 F1 L3 X48 >0 >N4,'node'N4 I6 3 1 0 L4 F3 L4 >0 >N5,'node'N5 I20 2 0 0 F1 L4 >0 >-1,.
'rule'I16 0 0 1'node'N1 I17 2 0 0 F1 F2 >0 >-1,.
'rule'I17 2 2 8'node'N1 I7 3 1 0 F2 X15 L2 >0 >N2,'node'N2 I21 2 1 0 F2 X4 >0 >N3,'node'N3 I1 2 0 0 F2 X0 >N4 >N5,'node'N4 I17 2 0 0 F1 F2 >0 >N5,'node'N5 I2 2 0 0 L2 X10 >N7 >N6,'node'N6 I6 3 1 0 X48 L2 L2 >0 >N8,'node'N7 I6 3 1 0 L2 I11 L2 >0 >N8,'node'N8 I20 2 0 0 F1 L2 >0 >-1,.
'rule'I9 2 4 16'node'N1 I3 2 1 0 F4@1 L2 >0 >N2,'node'N2 I3 2 1 0 X0@1 L3 >0 >N3,'node'N3 I23 4 1 0 F2 L2 L3 L4 >-1 >N4,'node'N4 I12 1 1 0 L3 >0 >N5,'node'N5 I4 2 0 0 L4 X37 >N7 >N6,'node'N6 I20 2 0 0 F1 L4 >0 >N3,'node'N7 I23 4 1 0 F2 L2 L3 L4 >N9 >N8,'node'N8 I12 1 1 0 L3 >0 >N9,'box'N9 L4'area'53 X110 >N10'area'54 X99 >N11'area'55 X100 >N13'area'56 X120 >N15'area'57:>N6,'node'N10 I20 2 0 0 F1 I15 >0 >N3,'node'N11 I22 1 0 0 F3 >-1 >N12,'node'N12 I20 2 0 0 F1 F4 >0 >N3,'node'N13 I22 1 0 0 F3 >-1 >N14,'node'N14 I18 2 0 0 F1 F4 >0 >N3,'node'N15 I22 1 0 0 F3 >-1 >N16,'node'N16 I16 2 0 0 F1 F4 >0 >N3,.
'rule'I5 0 0 0.
