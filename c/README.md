## Compiler and linker

The result of compiling the aleph [compiler](../comp) and the [linker](../link) to C 
are the C programs [comp.c](comp.c) and [link.c](link.c).

These programs can be compiled by a C compiler, and then
they can be used to *recompile* the compiler again. Results 
should be the C programs here.

This bootstrap process was started by making the compilations 
by hand; those hand-written programs are in [bootstrap](../bootstrap).
