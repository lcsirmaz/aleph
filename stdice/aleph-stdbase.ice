$ ICE file, produced by ALEPH compiler v2.0
'module' "stdlib" "stdlib base" 32 
3 241 "../../stdlib/aleph-stdbase.ale"
242 273 "stdlib"
274 512 "aleph-stdbase"
513 542 "aleph-stdwordsize"
543 576 "aleph-stdarg"
577 622 "aleph-stdputint"
623 656 "aleph-stdputline"
657 690 "aleph-stdputstring"
691 727 "aleph-stdputasstring"
728 776 "aleph-stdgetint"
777 819 "aleph-stdgetline"
820 854 "aleph-stdwait"
855 888 "aleph-stdin"
889 922 "aleph-stdout"
.
<rule> I1 532 172 2 <formal in> <formal in> "stdlib" "@equal"
<rule> I2 1044 235 1 <formal in> "stdlib" "@exit"
<rule> I3 532 176 2 <formal in> <formal in> "stdlib" "@less"
<rule> I4 532 178 2 <formal in> <formal in> "stdlib" "@lseq"
<rule> I5 98324 184 3 <formal in> <formal anchor> <formal out> "stdlib" "@make"
<rule> I6 532 180 2 <formal in> <formal in> "stdlib" "@more"
<rule> I7 532 182 2 <formal in> <formal in> "stdlib" "@mreq"
<rule> I8 532 174 2 <formal in> <formal in> "stdlib" "@noteq"
<rule> I9 16640 239 0 "stdlib" "@root"
<rule> I10 20 159 3 <formal in> <formal in> <formal out> "stdlib" "add"
<rule> I11 20 162 4 <formal in> <formal in> <formal in> <formal out> "stdlib" "addmult"
<rule> I12 788 228 2 <formal file> <formal out> "stdlib" "aheadchar"
<rule> I13 276 237 0 "stdlib" "backtrack"
<rule> I14 20 218 3 <formal table> 1 1 <formal in> <formal out> "stdlib" "blockhash"
<rule> I15 20 190 3 <formal in> <formal in> <formal out> "stdlib" "booland"
<rule> I16 20 189 2 <formal in> <formal out> "stdlib" "boolinvert"
<rule> I17 20 191 3 <formal in> <formal in> <formal out> "stdlib" "boolor"
<rule> I18 20 192 3 <formal in> <formal in> <formal out> "stdlib" "boolxor"
<rule> I19 276 222 1 <formal file> "stdlib" "closefile"
<rule> I20 20 209 5 <formal table> 1 1 <formal in> <formal table> 1 1 <formal in> <formal out> "stdlib" "comparestring"
<rule> I21 20 210 6 <formal table> 1 1 <formal in> <formal table> 1 1 <formal in> <formal in> <formal out> "stdlib" "comparestringn"
<rule> I22 276 215 3 <formal table> 1 1 <formal in> <formal stack> 1 1 "stdlib" "copystring"
<rule> I23 20 166 1 <formal inout> "stdlib" "decr"
<rule> I24 20 163 3 <formal in> <formal in> <formal out> "stdlib" "div"
<rule> I25 20 164 4 <formal in> <formal in> <formal out> <formal out> "stdlib" "divrem"
<rule> I26 532 171 2 <formal in> <formal in> "stdlib" "equal"
<rule> I27 1044 234 1 <formal in> "stdlib" "exit"
<rule> I28 20 167 2 <formal in> <formal out> "stdlib" "getabs"
<rule> I29 788 227 2 <formal file> <formal out> "stdlib" "getchar"
<rule> I30 788 230 3 <formal file> <formal out> <formal out> "stdlib" "getdata"
<rule> I31 20 224 2 <formal file> <formal out> "stdlib" "getfileerror"
<rule> I32 20 225 2 <formal file> <formal out> "stdlib" "getfilepos"
<rule> I33 20 165 1 <formal inout> "stdlib" "incr"
<rule> I34 532 186 1 <formal in> "stdlib" "is"
<rule> I35 532 188 1 <formal in> "stdlib" "isfalse"
<rule> I36 532 187 1 <formal in> "stdlib" "istrue"
<rule> I37 20 193 2 <formal inout> <formal in> "stdlib" "leftclear"
<rule> I38 532 175 2 <formal in> <formal in> "stdlib" "less"
<rule> I39 20 199 2 <formal table> 1 1 <formal out> "stdlib" "listlength"
<rule> I40 532 177 2 <formal in> <formal in> "stdlib" "lseq"
<rule> I41 20 168 2 <formal in> <formal inout> "stdlib" "max"
<constant> I42 0 537 "stdlib" "maxint"
<rule> I43 20 169 2 <formal in> <formal inout> "stdlib" "min"
<rule> I44 532 179 2 <formal in> <formal in> "stdlib" "more"
<rule> I45 532 181 2 <formal in> <formal in> "stdlib" "mreq"
<rule> I46 20 161 3 <formal in> <formal in> <formal out> "stdlib" "mult"
<rule> I47 20 197 2 <formal table> 1 1 <formal inout> "stdlib" "next"
<rule> I48 532 173 2 <formal in> <formal in> "stdlib" "notequal"
<rule> I49 788 220 4 <formal file> <formal in> <formal table> 1 1 <formal in> "stdlib" "openfile"
<rule> I50 788 221 3 <formal file> <formal stack> 1 1 <formal in> "stdlib" "opentempfile"
<rule> I51 276 213 3 <formal table> 1 1 <formal in> <formal stack> 1 1 "stdlib" "packstring"
<rule> I52 20 198 2 <formal table> 1 1 <formal inout> "stdlib" "previous"
<rule> I53 20 208 2 <formal table> 1 1 <formal inout> "stdlib" "previousstring"
<rule> I54 276 229 2 <formal file> <formal in> "stdlib" "putchar"
<rule> I55 276 231 3 <formal file> <formal in> <formal in> "stdlib" "putdata"
<rule> I56 788 232 3 <formal file> <formal in> <formal in> "stdlib" "putdatap"
<rule> I57 276 203 1 <formal stack> 1 1 "stdlib" "release"
<rule> I58 788 204 2 <formal stack> 1 1 <formal in> "stdlib" "requestspace"
<rule> I59 20 194 2 <formal inout> <formal in> "stdlib" "rightclear"
<rule> I60 276 202 1 <formal stack> 1 1 "stdlib" "scratch"
<rule> I61 276 226 2 <formal file> <formal in> "stdlib" "setfilepos"
<rule> I62 532 211 4 <formal table> 1 1 <formal in> <formal in> <formal out> "stdlib" "stringelem"
<rule> I63 20 217 3 <formal table> 1 1 <formal in> <formal out> "stdlib" "stringhash"
<rule> I64 20 206 3 <formal table> 1 1 <formal in> <formal out> "stdlib" "stringlength"
<rule> I65 20 207 3 <formal table> 1 1 <formal in> <formal out> "stdlib" "stringwidth"
<rule> I66 20 160 3 <formal in> <formal in> <formal out> "stdlib" "subtr"
<rule> I67 276 223 2 <formal table> 1 1 <formal in> "stdlib" "unlinkfile"
<rule> I68 276 214 3 <formal table> 1 1 <formal in> <formal stack> 1 1 "stdlib" "unpackstring"
<rule> I69 276 200 1 <formal stack> 1 1 "stdlib" "unstack"
<rule> I70 276 212 1 <formal stack> 1 1 "stdlib" "unstackstring"
<rule> I71 276 201 2 <formal stack> 1 1 <formal in> "stdlib" "unstackto"
<rule> I72 532 196 2 <formal table> 1 1 <formal in> "stdlib" "was"
.
'front'"#include ""aleph_stdlib.h""".
'external'I10 "_a_add".
'external'I66 "_a_subtr".
'external'I46 "_a_mult".
'external'I11 "_a_addmult".
'external'I24 "_a_div".
'external'I25 "@a_divrem".
'external'I33 "_a_incr".
'external'I23 "_a_decr".
'external'I28 "_a_getabs".
'external'I41 "_a_max".
'external'I43 "_a_min".
'external'I26 "_a_equal".
'external'I1 "_a_equal".
'external'I48 "_a_noteq".
'external'I8 "_a_noteq".
'external'I38 "_a_less".
'external'I3 "_a_less".
'external'I40 "_a_lseq".
'external'I4 "_a_lseq".
'external'I44 "_a_more".
'external'I6 "_a_more".
'external'I45 "_a_mreq".
'external'I7 "_a_mreq".
'external'I5 "@@make".
'external'I34 "_a_is".
'external'I36 "_a_istrue".
'external'I35 "_a_isfalse".
'external'I16 "_a_boolinvert".
'external'I15 "_a_booland".
'external'I17 "_a_boolor".
'external'I18 "_a_boolxor".
'external'I37 "_a_leftclear".
'external'I59 "_a_rightclear".
'external'I72 "_a_was".
'external'I47 "_a_next".
'external'I52 "_a_previous".
'external'I39 "_a_listlength".
'external'I69 "_a_unstack".
'external'I71 "_a_unstackto".
'external'I60 "_a_scratch".
'external'I57 "a_release".
'external'I58 "a_requestspace".
'external'I64 "_a_stringlength".
'external'I65 "_a_stringwidth".
'external'I53 "_a_previousstring".
'external'I20 "a_comparestring".
'external'I21 "a_comparestringn".
'external'I62 "a_stringelem".
'external'I70 "_a_unstackstring".
'external'I51 "a_packstring".
'external'I68 "a_unpackstring".
'external'I22 "a_copystring".
'external'I63 "a_stringhash".
'external'I14 "a_blockhash".
'external'I49 "a_openfile".
'external'I50 "a_opentempfile".
'external'I19 "a_closefile".
'external'I67 "a_unlinkfile".
'external'I31 "_a_getfileerror".
'external'I32 "a_getfilepos".
'external'I61 "a_setfilepos".
'external'I29 "a_getchar".
'external'I12 "a_aheadchar".
'external'I54 "a_putchar".
'external'I30 "a_getdata".
'external'I55 "a_putdata".
'external'I56 "a_putdatap".
'external'I27 "_a_exit".
'external'I2 "_a_exit".
'external'I13 "_a_xbacktrack".
'expression'I42 X2147483647 .
'rule'I9 0 0 0 .
