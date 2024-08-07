---
layout: default
---

# The C language

The C language is essential to understand a program.
A good reverser must learn and understand the C language and it's basic concepts, here a list of good ressources to understand C language : 

- [EN] [C language (Begginer Level)](https://www.w3schools.com/c/)
- [FR] [C language (Begginer Level)](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c)

If you readed all, congratz ! 
Now you are familiar with the c language, let's start with basic challenges to see what's you learned.

# ASM x64

Asm is the machine code that are directly executed by the cpu.
This is the must have skill for any reverser. 
Here a list of ressource you can work on to learn the basic of ASM.

- [EN] [ASM lesson x64](https://web.stanford.edu/class/cs107/guide/x86-64.html)
- [EN] [ASM x64 Exercices](https://github.com/yds12/x64-roadmap)
- [Godbolt : See how a language code transform to ASM](https://godbolt.org/)

# C01-03 : Shared memory

Can you try to understand what's this program doing with the shared memory and internal structure ? 

A shared memory has been created at address 0x13000000. The program map and execute the shellcode given in argv[1].

> It is strongly recommended to do the ASM x64 Exercices just before in ressources to do this challenge. The goal here is to learn with nasm how to write a basic shellcode.

md5sum : b130cdd87480917a1b2a75ad4bc177c6

[C01-03 : introduction3.bin](/assets/module/c01/03/introduction3.bin).

# C01-04 : IPC

In this challenge, a IPC is created and wait for a specific message.
Horewer, there is a random event which is happening after receiving our message...

Your goal here is to write a solver that send the right message, and patch the original program to remove the unfortunate byte swap. 

md5sum : f3985e9117865f5696182b17b973e822

[C01-04 : introduction4.bin](/assets/module/c01/04/introduction4.bin).
