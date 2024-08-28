---
layout: default
---

# The C Language

The C language is essential for understanding how a program works. A good reverser must learn and understand the C language and its basic concepts. Here is a list of good resources to help you understand the C language: 

- [EN] [C Language (Beginner Level)](https://www.w3schools.com/c/)
- [FR] [C Language (Beginner Level)](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c)

If you've read all of these, congratulations! Now you are familiar with the C language. Let's start with some basic challenges to see what you've learned.

# ASM x64

Assembly (ASM) is the machine code that is directly executed by the CPU. This is a must-have skill for any reverser. Here is a list of resources you can use to learn the basics of ASM.

- [EN] [ASM Lesson x64](https://web.stanford.edu/class/cs107/guide/x86-64.html)
- [EN] [ASM x64 Exercises](https://github.com/yds12/x64-roadmap)
- [Godbolt: See how a language's code transforms to ASM](https://godbolt.org/)

# C01-03: Shared Memory (Easy+)

Can you try to understand what this program is doing with the shared memory and internal structure? 

A shared memory segment has been created at address `0x13000000`. The program maps and executes the shellcode given in `argv[1]`.

> It is strongly recommended to complete the ASM x64 Exercises listed in the resources before attempting this challenge. The goal here is to learn how to write basic shellcode with NASM.

`flag md5sum: b130cdd87480917a1b2a75ad4bc177c6`

[C01-03: introduction3.bin](/assets/module/c01/03/introduction3.bin).

# C01-04: IPC (Easy)

In this challenge, an IPC is created and waits for a specific message.
However, there is a random event that occurs after receiving your message...

Your goal here is to write a solver that sends the correct message and patches the original program to remove the unfortunate byte swap. 

`flag md5sum: f3985e9117865f5696182b17b973e822`

[C01-04: introduction4.bin](/assets/module/c01/04/introduction4.bin).