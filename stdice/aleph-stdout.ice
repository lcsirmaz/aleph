$ ICE file, produced by ALEPH compiler v2.0
'module' "stdlib" "charfile stdout" 32 
3 36 "../../stdlib/aleph-stdout.ale"
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
<table> I1 8 -2 1 1 "" "@StringTable"
<rule> I2 16640 34 0 "stdlib" "@root"
<charfile> I3 4 32 "stdlib" "STDOUT"
<constant> I4 0 332 "stdlib" "maxint"
<pointer constant> I5 0 32 "stdlib" "@"
.
'fill'I1 -2 T"<<stdout>>":I5 .
'file'I3 2 I1 I5 .
'expression'I4 X2147483647 .
'rule'I2 0 0 0 .
