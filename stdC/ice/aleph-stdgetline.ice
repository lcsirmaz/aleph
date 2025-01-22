$ ICE file, produced by ALEPH compiler v2.2
'module' "stdlib" "stdlib get line" 32 
4 48 "aleph-stdgetline"
49 129 "stdlib"
.
<rule> I1 98312 81 3<formal in><formal anchor><formal out> "stdlib" "@make"
<rule> I2 16640 46 0 "stdlib" "@root"
<rule> I3 776 105 2<formal file><formal out> "stdlib" "aheadchar"
<rule> I4 776 105 2<formal file><formal out> "stdlib" "getchar"
<rule> I5 772 37 3<formal file><formal stack> 1 1<formal out> "stdlib" "getline"
<constant> I6 0 103 "stdlib" "newline"
<constant> I7 0 103 "stdlib" "newpage"
<constant> I8 0 103 "stdlib" "restline"
.
'expression'I6 X10.
'expression'I7 X12.
'expression'I8 X-2.
'rule'I5 2 2 9'node'N1 I4 2 1 0 F1 L2 >-2 >N2,'box'N2 L2'area'39 I6;I7 >N3'area'40:>N4,'node'N3 I1 2 1 0 L2@1 F3 >0 >N6,'node'N4 I1 2 1 0 I8@1 F3 >0 >N5,'extension'N5 F2 1 L2'to'1 >N6,'node'N6 I3 2 1 0 F1 L2 >-1 >N7,'box'N7 L2'area'42 I6;I7 >-1'area'43:>N8,'extension'N8 F2 1 L2'to'1 >N9,'node'N9 I4 2 1 0 F1#>N6 >N6,.
'rule'I2 0 0 0.
