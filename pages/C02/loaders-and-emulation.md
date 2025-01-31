---
layout: default
---
## Recommended Ressource

- [EN] [Loader Explained](https://www.naukri.com/code360/library/what-is-loader)
- [EN] [Analysing a malformated ELF with unicorn](https://binaryresearch.github.io/2019/09/17/Analyzing-ELF-Binaries-with-Malformed-Headers-Part-1-Emulating-Tiny-Programs.html)

# Loaders

## What is a Loader?

A loader is a part of an operating system that is responsible for loading programs and libraries. It places programs into memory and prepares them for execution. The loader is an essential component in the process of starting a program.

## Key Functions of a Loader

1. **Loading**: The loader reads the executable file from disk into memory.
2. **Relocation**: Adjusts the addresses in the program so that it can be loaded at an address different from the one originally specified.
3. **Linking**: Resolves addresses for any external symbols or libraries that the program depends on.
4. **Initialization**: Sets up the initial program state, including stack and heap, and transfers control to the program's entry point.

## Types of Loaders

- **Absolute Loader**: Loads the program into a specific memory location.
- **Relocating Loader**: Loads the program into any available memory location and adjusts addresses accordingly.
- **Dynamic Linking Loader**: Loads and links shared libraries at runtime.

## Common Loaders

### PE (Portable Executable)
The PE format is used in Windows operating systems. It includes headers and sections that describe the executable code, data, and resources. The loader reads the PE file, maps it into memory, resolves imports, and prepares the program for execution.

### ELF (Executable and Linkable Format)
ELF is commonly used in Unix-like operating systems, including Linux. It supports multiple architectures and includes headers that describe how the file should be loaded into memory. The loader handles loading, dynamic linking, and relocation.

See [C01-Elf format](/pages/C01/elf.md)

### Mach-O (Mach Object)
Mach-O is used in macOS and iOS. It supports both 32-bit and 64-bit architectures. The Mach-O loader reads the file, maps segments into memory, resolves symbols, and handles dynamic linking.

These loaders are essential for executing programs on their respective operating systems, each with unique features and capabilities tailored to their environments.

-----------------------------

# C02-01: Understanding a custom loader (Medium--)

### Challenge Description

In this challenge, you are tasked with emulating a custom C0FF loader (this format does not exists). The loader initialize the necessary registers and decrypt an x86 shellcode embedded within the C0FF file.

As a reverse engineer, you will encounter custom architectures, unique binary formats, or files that not even Google is familiar with. In this initial exercise, your task is to comprehend a basic loader, and the structure of the binary format is provided. However, I won't provide you with the virtual machine that runs the binary.

One of the most crucial tools that can aid you in reverse engineering is Unicorn.

https://github.com/unicorn-engine/unicorn

Unicorn allows you to emulate numerous custom architectures or establish your own binary format!
For this exercise, I recommend using Unicorn to familiar with the emulation of custom files.

Best of luck. The flag format is LRCTF{PrintableAscii}.

### Objectives

1. **COFF Parsing**: Write a parser to read the COFF file format and extract the relevant informations.
2. **Register Initialization**: Properly initialize the CPU registers required for the execution of the shellcode.
3. **Shellcode Decryption**: Implement a decryption routine to decode the encrypted x86 shellcode.
4. **Execution**: Transfer control to the decrypted shellcode and ensure it executes correctly.

### C0FF format

The C0FF file structure includes:
- A magic header (4 bytes)
- An encryption shellcode flag (1 byte) (0 : no encryption | 1 : shellcode encrypted)  
- RAX register pre-execution value (C0FF_SET_VM_REG_RAX : 8bytes)
- RDI register pre-execution value (C0FF_SET_VM_REG_RDI : 8bytes)
- An encryption key (16 bytes)
- pad (3bytes)
- The actual shellcode (encrypted or not)  

`flag md5sum: 3b8b9e5e6f8e4c8a9d8e4b8e6f8e4c8a`

[C02-01: program.c0ff](/assets/module/c02/01/program.c0ff)  

