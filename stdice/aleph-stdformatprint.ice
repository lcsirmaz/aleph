$ ICE file, produced by ALEPH compiler v2.1
'module' "stdlib" "stdlib format print" 32 
3 61 "aleph-stdformatprint"
62 165 "stdlib"
.
<rule> I1 520 95 2<formal in><formal in> "stdlib" "@equal"
<rule> I2 520 95 2<formal in><formal in> "stdlib" "@less"
<rule> I3 98312 97 3<formal in><formal anchor><formal out> "stdlib" "@make"
<rule> I4 520 95 2<formal in><formal in> "stdlib" "@noteq"
<rule> I5 16640 59 0 "stdlib" "@root"
<charfile> I6 8 150 "stdlib" "STDOUT"
<rule> I7 8 89 3<formal in><formal in><formal out> "stdlib" "add"
<rule> I8 8 100 3<formal in><formal in><formal out> "stdlib" "booland"
<rule> I9 8 91 4<formal in><formal in><formal out><formal out> "stdlib" "divrem"
<rule> I10 33028 48 4<formal file><formal table> 1 1<formal anchor><formal in> "stdlib" "fprintf"
<rule> I11 8 92 2<formal in><formal out> "stdlib" "getabs"
<constant> I12 0 33 "stdlib" "hexshift"
<rule> I13 8 91 1<formal inout> "stdlib" "incr"
<constant> I14 0 136 "stdlib" "maxint"
<constant> I15 0 137 "stdlib" "minint"
<constant> I16 0 117 "stdlib" "newline"
<rule> I17 33028 34 3<formal table> 1 1<formal anchor><formal in> "stdlib" "printf"
<rule> I18 256 42 2<formal file><formal in> "stdlib" "printhex"
<rule> I19 256 44 2<formal file><formal in> "stdlib" "printhex1"
<rule> I20 256 35 2<formal file><formal in> "stdlib" "printint"
<rule> I21 256 39 3<formal file><formal in><formal in> "stdlib" "printint1"
<rule> I22 264 127 2<formal file><formal in> "stdlib" "putchar"
<rule> I23 8 101 2<formal inout><formal in> "stdlib" "rightclear"
<rule> I24 33288 -2 1<formal shift> "" "shiftaffixblock"
<rule> I25 520 112 4<formal table> 1 1<formal in><formal in><formal out> "stdlib" "stringelem"
<rule> I26 8 89 3<formal in><formal in><formal out> "stdlib" "subtr"
.
'expression'I12 X97+X-10.
'expression'I16 X10.
'expression'I14 X2147483647.
'expression'I15-I14+X-1.
'rule'I17 0 0 1'node'N1 I10 2 0 0 I6 F1@0@>0 >-1,.
'rule'I20 0 0 9'node'N1 I1 2 0 0 F2 I15 >N5 >N2,'node'N2 I22 2 0 0 F1 X45 >0 >N3,'node'N3 I26 3 1 0 X-1 F2 F2 >0 >N4,'node'N4 I21 3 0 0 F1 F2 X49 >0 >-1,'node'N5 I2 2 0 0 F2 X0 >N9 >N6,'node'N6 I22 2 0 0 F1 X45 >0 >N7,'node'N7 I11 2 1 0 F2 F2 >0 >N8,'node'N8 I21 3 0 0 F1 F2 X48 >0 >-1,'node'N9 I21 3 0 0 F1 F2 X48 >0 >-1,.
'rule'I21 3 4 5'node'N1 I9 4 2 0 F2 X10 L3 L4 >0 >N2,'node'N2 I1 2 0 0 L3 X0 >N3 >N4,'node'N3 I21 3 0 0 F1 L3 X48 >0 >N4,'node'N4 I7 3 1 0 L4 F3 L4 >0 >N5,'node'N5 I22 2 0 0 F1 L4 >0 >-1,.
'rule'I18 0 0 1'node'N1 I19 2 0 0 F1 F2 >0 >-1,.
'rule'I19 2 2 8'node'N1 I8 3 1 0 F2 X15 L2 >0 >N2,'node'N2 I23 2 1 0 F2 X4 >0 >N3,'node'N3 I1 2 0 0 F2 X0 >N4 >N5,'node'N4 I19 2 0 0 F1 F2 >0 >N5,'node'N5 I2 2 0 0 L2 X10 >N7 >N6,'node'N6 I7 3 1 0 X48 L2 L2 >0 >N8,'node'N7 I7 3 1 0 L2 I12 L2 >0 >N8,'node'N8 I22 2 0 0 F1 L2 >0 >-1,.
'rule'I10 2 4 17'node'N1 I3 2 1 0 F4@1 L2 >0 >N2,'node'N2 I3 2 1 0 X0@1 L3 >0 >N3,'node'N3 I25 4 1 0 F2 L2 L3 L4 >-1 >N4,'node'N4 I13 1 1 0 L3 >0 >N5,'node'N5 I4 2 0 0 L4 X37 >N7 >N6,'node'N6 I22 2 0 0 F1 L4 >0 >N3,'node'N7 I25 4 1 0 F2 L2 L3 L4 >N9 >N8,'node'N8 I13 1 1 0 L3 >0 >N9,'box'N9 L4'area'52 X110 >N10'area'53 X99 >N11'area'54 X100 >N13'area'55 X120 >N15'area'56:>N17,'node'N10 I22 2 0 0 F1 I16 >0 >N3,'node'N11 I24 1 0 0 F3 >-1 >N12,'node'N12 I22 2 0 0 F1 F4 >0 >N3,'node'N13 I24 1 0 0 F3 >-1 >N14,'node'N14 I20 2 0 0 F1 F4 >0 >N3,'node'N15 I24 1 0 0 F3 >-1 >N16,'node'N16 I18 2 0 0 F1 F4 >0 >N3,'node'N17 I22 2 0 0 F1 L4 >0 >N3,.
'rule'I5 0 0 0.
