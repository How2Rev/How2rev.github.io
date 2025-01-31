---
layout: default
---

# How Computers Are Architected

> Original lesson from https://cpu.land/the-basics

The central processing unit (`CPU`) of a computer is in charge of all computation. It’s the big cheese. The shazam alakablam. It starts chugging as soon as you start your computer, executing instruction after instruction after instruction.

The first mass-produced `CPU` was the `Intel 4004`, designed in the late 60s by an Italian physicist and engineer named Federico Faggin. It was a 4-bit architecture instead of the 64-bit systems we use today, and it was far less complex than modern processors, but a lot of its simplicity does still remain.

The “instructions” that CPUs execute are just binary data: a byte or two to represent what instruction is being run (the opcode), followed by whatever data is needed to run the instruction. What we call machine code is nothing but a series of these binary instructions in a row. Assembly is a helpful syntax for reading and writing machine code that’s easier for humans to read and write than raw bits; it is always compiled to the binary that your CPU knows how to read.

![assembly-to-machine-code-translation](/pages/C02/img/cpu/assembly-to-machine-code-translation.png)

> An aside: instructions aren’t always represented 1:1 in machine code as in the above example. For example, `add eax, 512` translates to `05 00 02 00 00`.  
The first byte (05) is an opcode specifically representing adding the `EAX` register to a 32-bit number. The remaining bytes are 512 (0x200) in little-endian byte order.  

RAM is your computer’s main memory bank, a large multi-purpose space which stores all the data used by programs running on your computer. That includes the program code itself as well as the code at the core of the operating system. The CPU always reads machine code directly from RAM, and code can’t be run if it isn’t loaded into RAM.

The CPU stores an instruction pointer which points to the location in RAM where it’s going to fetch the next instruction. After executing each instruction, the CPU moves the pointer and repeats. This is the `fetch-execute cycle`.

![fetch-execute-cycle](/pages/C02/img/cpu/fetch-execute-cycle.png)

After executing an instruction, the pointer moves forward to immediately after the instruction in RAM so that it now points to the next instruction. That’s why code runs! The instruction pointer just keeps chugging forward, executing machine code in the order in which it has been stored in memory. Some instructions can tell the instruction pointer to jump somewhere else instead, or jump different places depending on a certain condition; this makes reusable code and conditional logic possible.

This instruction pointer is stored in a register. Registers are small storage buckets that are extremely fast for the CPU to read and write to. Each CPU architecture has a fixed set of registers, used for everything from storing temporary values during computations to configuring the processor.

Some registers are directly accessible from machine code, like `ebx` in the earlier diagram.

Other registers are only used internally by the CPU, but can often be updated or read using specialized instructions. One example is the instruction pointer, which can’t be read directly but can be updated with, for example, a jump instruction.

## Processors Are Naive

Let’s go back to the original question: what happens when you run an executable program on your computer? First, a bunch of magic happens to get ready to run it — we’ll work through all of this later — but at the end of the process there’s machine code in a file somewhere. The operating system loads this into RAM and instructs the CPU to jump the instruction pointer to that position in RAM. The CPU continues running its fetch-execute cycle as usual, so the program begins executing!

![instruction-pointer](/pages/C02/img/cpu/instruction-pointer.png)

It turns out CPUs have a super basic worldview; they only see the current instruction pointer and a bit of internal state. Processes are entirely operating system abstractions, not something CPUs natively understand or keep track of.

-----------------------------

# C02-02: Understanding and emulating a custom CPU instruction set (Medium+)

This challenge come from x3.ctf
> There is a typo from original documentation : The encrypted key is 16bytes, not 16bits.

## Description

I found an old game cartridge for an obscure video game console at a yard sale. I don't have the console, but I found a PDF online describing the hardware. Could you help me get the game running?

[C02-02: ominbius-document-reference.pdf](/assets/module/c02/02/519814-omnibious-pocket-computer-rev1-0.pdf)  
[C02-02: dump.rom](/assets/module/c02/02/dump.rom)  