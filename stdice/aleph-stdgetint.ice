$ ICE file, produced by ALEPH compiler v2.0
'module' "stdlib" "stdlib getint" 32 
3 51 "aleph-stdgetint"
52 83 "stdlib"
84 322 "aleph-stdbase"
323 352 "aleph-stdwordsize"
353 386 "aleph-stdarg"
387 432 "aleph-stdputint"
433 466 "aleph-stdputline"
467 500 "aleph-stdputstring"
501 537 "aleph-stdputasstring"
538 586 "aleph-stdgetint"
587 629 "aleph-stdgetline"
630 664 "aleph-stdwait"
665 698 "aleph-stdin"
699 732 "aleph-stdout"
.
<rule> I1 520 117 2 <formal in> <formal in> "stdlib" "@equal"
<rule> I2 98312 121 3 <formal in> <formal anchor> <formal out> "stdlib" "@make"
<rule> I3 520 118 2 <formal in> <formal in> "stdlib" "@more"
<rule> I4 16640 49 0 "stdlib" "@root"
<rule> I5 8 108 4 <formal in> <formal in> <formal in> <formal out> "stdlib" "addmult"
<rule> I6 776 201 2 <formal file> <formal out> "stdlib" "aheadchar"
<rule> I7 776 201 2 <formal file> <formal out> "stdlib" "getchar"
<rule> I8 772 32 2 <formal file> <formal out> "stdlib" "getint"
<constant> I9 0 347 "stdlib" "maxint"
<constant> I10 0 179 "stdlib" "newline"
<constant> I11 0 179 "stdlib" "newpage"
<rule> I12 8 107 3 <formal in> <formal in> <formal out> "stdlib" "subtr"
.
'expression'I10 X10 .
'expression'I11 X12 .
'expression'I9 X2147483647 .
'rule'I8 2 4 18 'node'N1 I6 2 1 0 F1 L2 >-2 >N2 ,'box'N2 L2 'area'34 I10 ;I11 ;X32 >N3 'area'35 X43 >N4 'area'36 X45 >N6 'area'37 X48 :X57 >N8 'area'38 :>-2 ,'node'N3 I7 2 1 0 F1 # >N1 >N1 ,'node'N4 I2 2 1 0 X1 @1 L3 >0 >N5 ,'node'N5 I7 2 1 0 F1 # >N9 >N9 ,'node'N6 I2 2 1 0 X-1 @1 L3 >0 >N7 ,'node'N7 I7 2 1 0 F1 # >N9 >N9 ,'node'N8 I2 2 1 0 X1 @1 L3 >0 >N9 ,'node'N9 I2 3 2 0 X0 @2 F2 L4 >0 >N10 ,'node'N10 I6 2 1 0 F1 L2 >N16 >N11 ,'box'N11 L2 'area'42 X48 :X57 >N12 'area'44 :>N16 ,'node'N12 I2 2 1 0 X1 @1 L4 >0 >N13 ,'node'N13 I12 3 1 0 L2 X48 L2 >0 >N14 ,'node'N14 I5 4 1 0 F2 X10 L2 F2 >0 >N15 ,'node'N15 I7 2 1 0 F1 # >N10 >N10 ,'node'N16 I1 2 0 0 L4 X1 >-2 >N17 ,'node'N17 I3 2 0 0 L3 X0 >N18 >-1 ,'node'N18 I12 3 1 0 X0 F2 F2 >0 >-1 ,.
'rule'I4 0 0 0 .
