$ ICE file, produced by ALEPH compiler v2.0
'module' "stdlib" "stdlib arguments" 32 
3 36 "aleph-stdarg"
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
<rule> I1 16640 34 0 "stdlib" "@root"
<table> I2 20 32 1 1 "stdlib" "STDARG"
<constant> I3 0 332 "stdlib" "maxint"
.
'front'"#include ""aleph_stdarg.h""".
'external'I2 "a_setup_stdarg".
'expression'I3 X2147483647 .
'rule'I1 0 0 0 .
