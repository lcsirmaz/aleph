$ ICE file, produced by ALEPH compiler v2.0
'module' "stdlib" "stdlib putstring" 32 
3 36 "aleph-stdputstring"
37 68 "stdlib"
69 307 "aleph-stdbase"
308 337 "aleph-stdwordsize"
338 371 "aleph-stdarg"
372 417 "aleph-stdputint"
418 451 "aleph-stdputline"
452 485 "aleph-stdputstring"
486 522 "aleph-stdputasstring"
523 571 "aleph-stdgetint"
572 614 "aleph-stdgetline"
615 649 "aleph-stdwait"
650 683 "aleph-stdin"
684 717 "aleph-stdout"
.
<rule> I1 98312 106 3 <formal in> <formal anchor> <formal out> "stdlib" "@make"
<rule> I2 16640 33 0 "stdlib" "@root"
<rule> I3 8 94 1 <formal inout> "stdlib" "incr"
<constant> I4 0 332 "stdlib" "maxint"
<rule> I5 264 187 2 <formal file> <formal in> "stdlib" "putchar"
<rule> I6 260 30 3 <formal file> <formal table> 1 1 <formal in> "stdlib" "putstring"
<rule> I7 520 154 4 <formal table> 1 1 <formal in> <formal in> <formal out> "stdlib" "stringelem"
.
'expression'I4 X2147483647 .
'rule'I6 2 3 4 'node'N1 I1 2 1 0 X0 @1 L2 >0 >N2 ,'node'N2 I7 4 1 0 F2 F3 L2 L3 >-1 >N3 ,'node'N3 I3 1 1 0 L2 >0 >N4 ,'node'N4 I5 2 0 0 F1 L3 >0 >N2 ,.
'rule'I2 0 0 0 .
