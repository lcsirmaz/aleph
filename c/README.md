## Aleph compiler and linker

The result of compiling the modules of the [compiler](../comp) 
and of the [linker](../link) to C are the programs [acomp.c](acomp.c) 
and [alink.c](alink.c), respectively.

These programs can be compiled by a C compiler, and then
they can be used to *recompile* the two parts of the compiler again.
The results should be the same C programs as here.

This "bootstrap" process was started by doing the first compilation 
by hand; those hand-written C programs are in [bootstrap](../bootstrap),
they are for the earliest version.
