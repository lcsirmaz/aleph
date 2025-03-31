$ ICE file, produced by ALEPH compiler v2.4
'module' "stdlib" "libC put as string" 32 
4 41 "putasstring"
42 122 "stdlib"
.
<rule> I1 520 72 2<formal in><formal in> "stdlib" "@equal"
<rule> I2 98312 74 3<formal in><formal anchor><formal out> "stdlib" "@make"
<rule> I3 16640 39 0 "stdlib" "@root"
<rule> I4 8 68 1<formal inout> "stdlib" "incr"
<rule> I5 260 33 3<formal file><formal table> 1 1<formal in> "stdlib" "putasstring"
<rule> I6 264 100 2<formal file><formal in> "stdlib" "putchar"
<rule> I7 520 87 4<formal table> 1 1<formal in><formal in><formal out> "stdlib" "stringelem"
.
'rule'I5 2 3 8'node'N1 I2 2 1 0 X0@1 L2 >0 >N2,'node'N2 I6 2 0 0 F1 X34 >0 >N3,'node'N3 I7 4 1 0 F2 F3 L2 L3 >N8 >N4,'node'N4 I4 1 1 0 L2 >0 >N5,'node'N5 I1 2 0 0 L3 X34 >N7 >N6,'node'N6 I6 2 0 0 F1 L3 >0 >N7,'node'N7 I6 2 0 0 F1 L3 >0 >N3,'node'N8 I6 2 0 0 F1 X34 >0 >-1,.
'rule'I3 0 0 0.
