---
layout: default
---

# Introduction

As an introduction to reverse engineering, here is a list of good resources to help you understand basic concepts and get started:

- [EN] [Lessons in Reversing (Beginner Level)](https://0xinfection.github.io/reversing/)
- [FR] [Lessons in Reversing (Beginner Level)](https://reverse.zip/categories/introduction-au-reverse/)
- [EN] [C Language (Beginner Level)](https://www.w3schools.com/c/)
- [FR] [C Language (Beginner Level)](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c)
- [Godbolt: See how a language's code transforms to ASM](https://godbolt.org/)


If you've read all of these, congratulations! Now that you are familiar with reversing, let's start with some basic challenges to see what you've learned.

# C01-01: A Basic Reversing Problem (Easy)

Let's begin with an introduction to reverse engineering.

The primary goal of this initial challenge is to gain a comprehensive understanding of various perspectives and basics within a basic disassembler. The flag is a password checker distributed across different locations, requiring you to explore a disassembler of your preference (such as IDA, Ghidra, BinaryNinja, etc.) to locate and piece together the complete flag.

For this challenge, the flag format is LRCTF{flag}.  
You can validate with the password checker

[C01-01: introduction1.bin](/assets/module/c01/01/introduction1.bin).

# C01-02: Encoding (Easy)

After introduction1, I eliminated plaintext passwords stored in memory. Now, my flags will be safeguarded by a highly secure algorithm!

In this new exercise, you will delve into basic encodings and text manipulation within memory. The program has been stripped (no symbols for functions). Can you uncover the original library employed?

In reverse engineering, when encountering an end program value (transformed from start to end with a user password, for example), you will face two choices:

- Find a method to retrieve this value with the correct password by manipulating the data.
- Reverse the program from end to start: invert all algorithms, cryptographic functions, and so forth.

Which approach will you take?

You can validate with the password checker

[C01-02: introduction2.bin](/assets/module/c01/02/introduction2.bin).

Now that you're familiar with basic C reversing, let's see if you can understand more advanced C concepts!

# C01-03: Shared Memory (Easy+)

Can you try to understand what this program is doing with the shared memory and internal structure? 

A shared memory segment has been created at address `0x13000000`. The program maps and executes the shellcode given in `argv[1]`.

> It is strongly recommended to complete the ASM x64 Exercises listed in the resources before attempting this challenge. The goal here is to learn how to write basic shellcode with NASM.

`flag md5sum: b130cdd87480917a1b2a75ad4bc177c6`

[C01-03: introduction3.bin](/assets/module/c01/03/introduction3.bin).

# C01-04: IPC & Patching binary (Easy)

In this challenge, an IPC is created and waits for a specific message.
However, there is a random event that occurs after receiving your message...

Your goal here is to write a solver that sends the correct message and patches the original program to remove the unfortunate byte swap. 

`flag md5sum: f3985e9117865f5696182b17b973e822`

[C01-04: introduction4.bin](/assets/module/c01/04/introduction4.bin).