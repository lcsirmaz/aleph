$ ICE file, produced by ALEPH compiler v2.1
'module' "stdlib" "stdlib put line" 32 
3 38 "aleph-stdputline"
39 128 "stdlib"
.
<rule> I1 520 72 2 <formal in> <formal in> "stdlib" "@equal"
<rule> I2 520 72 2 <formal in> <formal in> "stdlib" "@lseq"
<rule> I3 98312 74 3 <formal in> <formal anchor> <formal out> "stdlib" "@make"
<rule> I4 16640 35 0 "stdlib" "@root"
<rule> I5 8 68 1 <formal inout> "stdlib" "incr"
<constant> I6 0 113 "stdlib" "maxint"
<rule> I7 8 81 2 <formal table> 1 1 <formal inout> "stdlib" "previous"
<rule> I8 264 104 2 <formal file> <formal in> "stdlib" "putchar"
<rule> I9 260 31 3 <formal file> <formal table> 1 1 <formal in> "stdlib" "putline"
<constant> I10 0 95 "stdlib" "restline"
.
'expression'I10 X-2 .
'expression'I6 X2147483647 .
'rule'I9 2 2 8 'node'N1 I3 2 1 0 'lwb'F2 @1 L2 >0 >N2 ,'node'N2 I7 2 1 0 F2 L2 >0 >N3 ,'node'N3 I5 1 1 0 L2 >0 >N4 ,'node'N4 I2 2 0 0 L2 'upb'F2 >N7 >N5 ,'node'N5 I8 2 0 0 F1 [F2 L2 ]1 >0 >N6 ,'node'N6 I5 1 1 0 L2 >0 >N4 ,'node'N7 I1 2 0 0 F3 I10 >N8 >-1 ,'node'N8 I8 2 0 0 F1 F3 >0 >-1 ,.
'rule'I4 0 0 0 .