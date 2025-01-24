$ ICE file, produced by ALEPH compiler v2.2
'module' "stdlib" "jslib put line" 32 
4 39 "putline"
40 120 "stdlib"
.
<rule> I1 520 70 2<formal in><formal in> "stdlib" "@equal"
<rule> I2 520 70 2<formal in><formal in> "stdlib" "@lseq"
<rule> I3 98312 72 3<formal in><formal anchor><formal out> "stdlib" "@make"
<rule> I4 16640 36 0 "stdlib" "@root"
<rule> I5 8 66 1<formal inout> "stdlib" "incr"
<rule> I6 8 79 2<formal table> 1 1<formal inout> "stdlib" "previous"
<rule> I7 264 98 2<formal file><formal in> "stdlib" "putchar"
<rule> I8 260 32 3<formal file><formal table> 1 1<formal in> "stdlib" "putline"
<constant> I9 0 94 "stdlib" "restline"
.
'expression'I9 X-2.
'rule'I8 2 2 7'node'N1 I3 2 1 0'lwb'F2@1 L2 >0 >N2,'node'N2 I6 2 1 0 F2 L2 >0 >N3,'node'N3 I5 1 1 0 L2 >0 >N4,'node'N4 I2 2 0 0 L2'upb'F2 >N6 >N5,'node'N5 I7 2 0 0 F1[F2 L2]1 >0 >N3,'node'N6 I1 2 0 0 F3 I9 >N7 >-1,'node'N7 I7 2 0 0 F1 F3 >0 >-1,.
'rule'I4 0 0 0.
