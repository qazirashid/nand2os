nand2os
=======

nand2os is a small project that I am trying today. The idea is inspired from the 'nandtotetris' project. I want to start from a NAND gate and build a basic computer from it and then write a basic OS for this computer.  I am trying to do things in C programming. My motivation is to learn and improve C Programming and in the process of learning, understand some fundamentals about computers.

I am using Linux (Ubuntu 14.04) and gcc tool chain for this project. 

The project organisation is not final. I am not sure how to best organise it. I will create some directories and put code and notes in those directories. A directory will meet some functional need of the project.

For example, today, I wrote code for a NAND gate. I started by defining a new data type called qbool which is same as a boolean. I did not use already defined boolean type because I wanted to make everything from scratch to make sure that I understand everything that needs to be understood.
I wrote a header for for 'qbool' type called 'qbool.h'. In this file I defined the type 'qbool' and I declared two functions namely 1) void printqbool(qbool a), which prints the value of a 'qbool' type.
2) qbool nand( qbool a, qbool b), which takes two 'qbools' and returns the nand of the two.

Then I wrote a shared library called 'libnand.so' that implements the above two funcitons. The source code of the shared library 'nand.c' is in the same folder as 'qbool.h'. An excellent tutorial on building and using shared libararies is given in the link below.

http://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html

I used this link to sucessfully build and test 'libnand.so'.

All these files and accompanying notes will be places in a folder called 'nand'. If you want to read in detail in order to replicate this project, please refer to the notes in each directory. I'll update this README when I have got some better organization or something more to say.

