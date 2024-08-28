---
layout: default
---

# Introduction

As an introduction to reverse engineering, here is a list of good resources to help you understand basic concepts and get started:

- [EN] [Lessons in Reversing (Beginner Level)](https://0xinfection.github.io/reversing/)
- [FR] [Lessons in Reversing (Beginner Level)](https://reverse.zip/categories/introduction-au-reverse/)

If you've read all of these, congratulations! Now that you are familiar with reversing, let's start with some basic challenges to see what you've learned.

# C01-01: A Basic Reversing Problem (Easy)

Let's begin with an introduction to reverse engineering.

The primary goal of this initial challenge is to gain a comprehensive understanding of various perspectives and basics within a basic disassembler. The flag is distributed across different locations, requiring you to explore a disassembler of your preference (such as IDA, Ghidra, BinaryNinja, etc.) to locate and piece together the complete flag.

For this challenge, the flag format is LRCTF{firstpart:secondpart:thirdpart:fourthpart}.

> You can find much of the flag using `strings`, but I recommend using a decompiler (Ghidra/BinaryNinja/IDA) to open the binary and understand where each flag part comes from.

`flag md5sum: 9d3b71756ae18f4133ea930f779f0bdf`

[C01-01: introduction1.bin](/assets/module/c01/01/introduction1.bin).

# C01-02: Encoding (Easy)

After introduction1, I eliminated plaintext passwords stored in memory. Now, my flags will be safeguarded by a highly secure algorithm!

In this new exercise, you will delve into basic encodings and text manipulation within memory. The program has been stripped (no symbols for functions). Can you uncover the original library employed?

In reverse engineering, when encountering an end program value (transformed from start to end with a user password, for example), you will face two choices:

- Find a method to retrieve this value with the correct password by manipulating the data.
- Reverse the program from end to start: invert all algorithms, cryptographic functions, and so forth.

Which approach will you take?

`flag md5sum: 2e3d9f4dc5d118cb8abaab1d8b22ea4e`

[C01-02: introduction2.bin](/assets/module/c01/02/introduction2.bin).

Now that you're familiar with basic C reversing, let's see if you can understand more advanced C concepts!

Next: [C01: Reversing C and Essential Concepts](/pages/C01/c.html).
