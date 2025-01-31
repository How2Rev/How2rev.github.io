---
layout: default
---
# CPU

A CPU (Central Processing Unit) is the primary component of a computer that performs most of the processing inside the computer. It interprets and executes instructions from the computer's memory, performing basic arithmetic, logic, control, and input/output operations specified by the instructions.

The CPU consists of several key parts:

1. **Arithmetic Logic Unit (ALU)**: This part of the CPU handles all arithmetic and logical operations, such as addition, subtraction, and comparison.

2. **Control Unit (CU)**: The control unit directs the operation of the processor. It tells the computer's memory, ALU, and input/output devices how to respond to the instructions that have been sent to the processor.

3. **Registers**: These are small, fast storage locations within the CPU that hold data and instructions temporarily during processing.

4. **Cache**: A smaller, faster type of volatile computer memory that provides high-speed data access to the CPU and improves processing speed.

The CPU operates in a cycle known as the fetch-decode-execute cycle:

1. **Fetch**: The CPU retrieves an instruction from the computer's memory.
2. **Decode**: The CPU interprets the instruction to determine what action is required.
3. **Execute**: The CPU performs the action required by the instruction.

Understanding how a CPU works is fundamental to understanding how computers process information and perform tasks.

# Ressource

- [EN] [CPU and kernel communication Explained](https://cpu.land/the-basics)

-----------------------------

# C02-02: Understanding and emulating a custom CPU instruction set (Medium+)

This challenge come from x3.ctf
> There is a typo from original documentation : The encrypted key is 16bytes, not 16bits.

## Description

I found an old game cartridge for an obscure video game console at a yard sale. I don't have the console, but I found a PDF online describing the hardware. Could you help me get the game running?

[C02-02: ominbius-document-reference.pdf](/assets/module/c02/02/519814-omnibious-pocket-computer-rev1-0.pdf)  
[C02-02: dump.rom](/assets/module/c02/02/dump.rom)  