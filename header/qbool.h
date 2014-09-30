#ifndef QBOOL
#define QBOOL
enum Qbool{ F=0, T=1
};

typedef enum Qbool qbool;
typedef qbool * const qboolP;

qboolP qnand(qboolP a, qboolP b, qboolP out);
//This header file will be included in all programs that need to use the boolean data type.
//This file also declares a nand function that will be defined in a shared library.
// any program wishing to use the nand function defined here should be linked with the the shared libary 
//called libnand.so
// gcc -Lpath/to/sharedlib -Wall -o outfile infile.c -lnand
void printqbool(qboolP a);
 

#endif
