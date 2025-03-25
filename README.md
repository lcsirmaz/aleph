## aleph
Modular ALEPH programming language v2.2

Aleph is a historical programming language; its name is an abbreviation for
**A** **L**anguage **E**ncouraging **P**rogram **H**iearachy.
This is an Aleph complier written in Aleph. The language is described
in the [Aleph Manual](https://lcsirmaz.github.io/aleph/).
The implemented Aleph language is described in
[Aleph Compiler 2.2](https://lcsirmaz.github.io/aleph/alephcomp.html).

Files with extension `.ale` are Aleph source files.

* [C](C) The C code of the compiler, optimizer and the linker as generated by the Aleph compiler
* [comp](comp) Aleph compiler modules (source)
* [link](link) Linker producing C target (source)
* [jslink](jslink) Linker producing javascript target (source)
* [opt](opt) Module optimizer (source)
* [stdlib](stdlib) Aleph standard library
* [stdC](stdC) Library files for C
* [stdjs](stdjs) Library files for javascript
* [stdcore](stdcore) C running environment (programs and headers)
* [doc](doc) Aleph Manual and some implementation details
* [sample](sample) Sample Aleph programs
* [joe](joe) Joe syntax highlighter for Aleph programs with .ale extension

## Compiling the Aleph &xrarr; C compiler

Compile the `acomp.c` and `alink.c` files in the [C](C) directory:

    gcc -W -O3 -I ../stdcore -o acomp acomp.c ../stdcore/*.c
    gcc -W -O3 -I ../stdcore -o aopt  aopt.c ../stdcore/*.c
    gcc -W -O3 -I ../stdcore -o alink alink.c ../stdcore/*.c
   
## Compiling, linking and running aleph files

The `acomp` program produces `.ice` files from Aleph modules and the main Aleph file.
The `aopt` program performs some optimization on the `.ice` file.
Linking '.ice' files is done by `alink`, which also generates a C program.
The additional header and C files needed to compile the generated C program
are in the directory `stdcore`.

The directory containing standard library files can be given after the `-L`
argument; these are `stdlib` and `stdC` for the compiler and the linker,
respectively. The following commands, given in the main directory, compile, link,
and run the `ex2.ale` sample program from the [sample](sample) directory.

    C/acomp -L stdlib sample/ex2  # generate ex2.ice
    C/aopt --replace sample/ex2   # optimize ex2.ice
    C/alink -o ex2 -L stdC  ex2   # generate ex2.c
    gcc -W -I stdcore -o ex2 ex2.c stdcore/*.c
    ./ex2                         # run it

