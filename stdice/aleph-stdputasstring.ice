$ ICE file, produced by ALEPH compiler v2.1
'module' "stdlib" "stdlib put as string" 32 
3 40 "aleph-stdputasstring"
41 130 "stdlib"
.
<rule> I1 520 74 2 <formal in> <formal in> "stdlib" "@equal"
<rule> I2 98312 76 3 <formal in> <formal anchor> <formal out> "stdlib" "@make"
<rule> I3 16640 38 0 "stdlib" "@root"
<rule> I4 8 70 1 <formal inout> "stdlib" "incr"
<constant> I5 0 115 "stdlib" "maxint"
<rule> I6 260 32 3 <formal file> <formal table> 1 1 <formal in> "stdlib" "putasstring"
<rule> I7 264 106 2 <formal file> <formal in> "stdlib" "putchar"
<rule> I8 520 91 4 <formal table> 1 1 <formal in> <formal in> <formal out> "stdlib" "stringelem"
.
'expression'I5 X2147483647 .
'rule'I6 2 3 8 'node'N1 I2 2 1 0 X0 @1 L2 >0 >N2 ,'node'N2 I7 2 0 0 F1 X34 >0 >N3 ,'node'N3 I8 4 1 0 F2 F3 L2 L3 >N8 >N4 ,'node'N4 I4 1 1 0 L2 >0 >N5 ,'node'N5 I1 2 0 0 L3 X34 >N7 >N6 ,'node'N6 I7 2 0 0 F1 L3 >0 >N7 ,'node'N7 I7 2 0 0 F1 L3 >0 >N3 ,'node'N8 I7 2 0 0 F1 X34 >0 >-1 ,.
'rule'I3 0 0 0 .
