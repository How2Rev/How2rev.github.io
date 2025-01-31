---
layout: default
---

# ELF Loader

ELF (Executable and Linkable Format) is the most common binary format for Linux/Unix distributions. Its primary purpose is to contain essential information that allows the kernel to launch processes. Here is a list of good resources to help you understand how it works:

- [EN] [ELF Format](https://www.gabriel.urdhr.fr/2015/09/28/elf-file-format/)
- [FR] [ELF Format](https://sysblog.informatique.univ-paris-diderot.fr/2024/04/01/le-format-elf-executable-and-linkable-format/)
- [EN] [Elf Explained](https://cpu.land/becoming-an-elf-lord)


## How ELF Loader Works

The ELF loader is responsible for loading ELF (Executable and Linkable Format) files into memory and preparing them for execution. Here is a high-level overview of how it works:

1. **Reading the ELF Header**: The loader starts by reading the ELF header, which contains metadata about the file, such as the type (executable, shared object, etc.), architecture, entry point, and program header table location.

2. **Parsing Program Headers**: The program headers describe the segments to be loaded into memory. Each segment has information about its location in the file, its destination in memory, size, and permissions (read, write, execute).

3. **Loading Segments into Memory**: The loader maps the segments into the process's address space. This involves copying data from the file to the appropriate memory locations and setting up memory protections based on the segment permissions.

4. **Relocation**: If the ELF file contains relocations, the loader applies them to adjust addresses in the code and data sections. This step is crucial for shared libraries and position-independent code.

5. **Jumping to the Entry Point**: Finally, the loader transfers control to the entry point specified in the ELF header, starting the execution of the program.

Understanding these steps is essential for debugging, reverse engineering, and developing low-level software that interacts with the operating system at a granular level.

Now that you are more familiar with the ELF executable format, let's try some fun challenges.

# C01-05: Some Unknown Handlers (Easy)

This program is weird. I reversed the main function, and the only thing I found is an integer divided by another integer. With your understanding of the ELF format, try to inspect all the important data linked to an ELF file, and you might discover some hidden things!

`flag md5sum: 868b752cd2a517f9db545c4c744aa13c`

[C01-05: introduction5](/assets/module/c01/05/introduction5.bin).

# C01-06: Weird Relocation (Hard++)

Dawn, this binary is performing some strange relocations.
Could there be some hidden data?

This challenge comes from FCSC 2024 (author: **quanthor_ic**).

> Completing the VM obfuscation module is recommended before attempting this challenge.

`flag md5sum: 5efcd59ad62c337d807adbd412040ba1`

[C01-06: svartalfheim](/assets/module/c01/06/svartalfheim).
