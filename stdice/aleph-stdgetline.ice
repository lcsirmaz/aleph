$ ICE file, produced by ALEPH compiler v2.0
'module' "stdlib" "stdlib getline" 32 
3 45 "../../stdlib/aleph-stdgetline.ale"
46 77 "stdlib"
78 316 "aleph-stdbase"
317 346 "aleph-stdwordsize"
347 380 "aleph-stdarg"
381 426 "aleph-stdputint"
427 460 "aleph-stdputline"
461 494 "aleph-stdputstring"
495 531 "aleph-stdputasstring"
532 580 "aleph-stdgetint"
581 623 "aleph-stdgetline"
624 658 "aleph-stdwait"
659 692 "aleph-stdin"
693 726 "aleph-stdout"
.
<rule> I1 98312 115 3 <formal in> <formal anchor> <formal out> "stdlib" "@make"
<rule> I2 16640 43 0 "stdlib" "@root"
<rule> I3 776 195 2 <formal file> <formal out> "stdlib" "aheadchar"
<rule> I4 776 195 2 <formal file> <formal out> "stdlib" "getchar"
<rule> I5 772 35 3 <formal file> <formal stack> 1 1 <formal out> "stdlib" "getline"
<constant> I6 0 341 "stdlib" "maxint"
<constant> I7 0 173 "stdlib" "newline"
<constant> I8 0 173 "stdlib" "newpage"
<constant> I9 0 174 "stdlib" "restline"
.
'expression'I7 X10 .
'expression'I8 X12 .
'expression'I9 X-2 .
'expression'I6 X2147483647 .
'rule'I5 2 2 9 'node'N1 I4 2 1 0 F1 L2 >-2 >N2 ,'box'N2 L2 'area'37 I7 ;I8 >N3 'area'38 :>N4 ,'node'N3 I1 2 1 0 L2 @1 F3 >0 >N6 ,'node'N4 I1 2 1 0 I9 @1 F3 >0 >N5 ,'extension'N5 F2 1 L2 'to'1 >N6 ,'node'N6 I3 2 1 0 F1 L2 >-1 >N7 ,'box'N7 L2 'area'40 I7 ;I8 >-1 'area'41 :>N8 ,'extension'N8 F2 1 L2 'to'1 >N9 ,'node'N9 I4 2 1 0 F1 # >N6 >N6 ,.
'rule'I2 0 0 0 .
