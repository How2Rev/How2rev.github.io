---
layout: default
---

# ELF Loader

ELF (Executable and Linkable Format) is the most common binary format for Linux/Unix distributions. Its primary purpose is to contain essential information that allows the kernel to launch processes. Here is a list of good resources to help you understand how it works:

- [EN] [ELF Format](https://www.gabriel.urdhr.fr/2015/09/28/elf-file-format/)
- [FR] [ELF Format](https://sysblog.informatique.univ-paris-diderot.fr/2024/04/01/le-format-elf-executable-and-linkable-format/)

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
