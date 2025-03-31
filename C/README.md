## Aleph compiler and linker in C

The result of compiling the modules of the [compiler](../comp),
[optimizer](../opt), 
and [linker](../link) to C are the programs [acomp.c](acomp.c) 
and [alink.c](alink.c), respectively.

These programs can be compiled and then used to *recompile* the three
parts of the compiler again. The results should be the same C programs.
