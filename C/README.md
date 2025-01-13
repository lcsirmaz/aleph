## Aleph compiler and linker

The result of compiling the modules of the [compiler](../comp),
the [optimizer](../opt), 
and of the [linker](../link) to C are the programs [acomp.c](acomp.c) 
and [alink.c](alink.c), respectively.

These programs can be compiled and then used to *recompile* the two 
parts of the compiler again. The results should be the same C programs.
