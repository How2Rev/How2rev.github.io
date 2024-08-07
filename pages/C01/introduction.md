---
layout: default
---

# Introduction

As an introduction to reverse, here a list of good ressources to understand basic concepts and introduction : 

- [EN] [Lessons to reversing (Begginer Level)](https://0xinfection.github.io/reversing/)
- [FR] [Lessons to reversing (Begginer Level)](https://reverse.zip/categories/introduction-au-reverse/)

If you readed all, congratz ! 
Now you are familiar with reversing, let's start with basic challenges to see what's you learned.

# C01-01 : A basic reversing problem

Let's begin with a reverse engineering introduction.

The primary goal of this initial challenge is to gain a comprehensive understanding of various perspectives and basics within a basic disassembler. The flag is distributed across different locations, requiring you to explore a disassembler of your preference (such as IDA, Ghidra, BinaryNinja, etc.) to locate and piece together the complete flag.

For this challenge, the flag format is LRCTF{firstpart:secondpart:thirdpart:fourthpart}.

> You can find a lot of the flag by using `string` but i recommend to use a decompiler (ghidra/binaryninja/ida) to open the binary and understand where the flag part come from.

md5sum : 9d3b71756ae18f4133ea930f779f0bdf

[C01-01 : introduction1.bin](/assets/module/c01/01/introduction1.bin).

# C01-02 : Encoding

After introduction1, I eliminated plaintext passwords stored in memory. Now, my flags will be safeguarded by a highly secure algorithm!

In this new exercise, you will delve into basic encodings and text manipulation within the memory. The program has been stripped (no symbols for functions). Can you uncover the original library employed?

In reverse engineering, when encountering an end program value (transformed from start to end with a user password, for example), you will confront two choices:

- Find a method to retrieve this value with the correct password by manipulating the data.
- Reverse the program from end to start: invert all algorithms, cryptographic functions, and so forth.

Which approach will you take?

md5sum : 2e3d9f4dc5d118cb8abaab1d8b22ea4e

[C01-02 : introduction2.bin](/assets/module/c01/02/introduction2.bin).
