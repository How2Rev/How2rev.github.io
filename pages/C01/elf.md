---
layout: default
---

# Elf loader

ELF is the most common binary loader for linux/unix distribution.
It's main usage is to hold essentials informations to allow kernel to launch the process.
Here a list of good ressource to understand how it work : 

- [EN] [Elf Format](https://www.gabriel.urdhr.fr/2015/09/28/elf-file-format/)
- [FR] [Elf Format](https://sysblog.informatique.univ-paris-diderot.fr/2024/04/01/le-format-elf-executable-and-linkable-format/)

Now that's your more familiar with Elf executable format, let's try some fun challenge

# C01-05 : Some unknow handlers (Easy)

This program is weird. I reversed the main and the only thing i found is a int divided by a int.
With your understanding of ELF format, try to inspect all the importants data linked to an ELF, and you will see some hidden things!

flag md5sum : 868b752cd2a517f9db545c4c744aa13c

[C01-05 : introduction5](/assets/module/c01/05/introduction5.bin).

# C01-100 : Weird relocation (Hard++)

Dawn, this binary is doing some weird recolations.
Is there some hidden data maybe?

This challenge come from FCSC 2024 (author : **quanthor_ic**)

> VM obfuscation module is recommended before doing this challenge

flag md5sum : 5efcd59ad62c337d807adbd412040ba1

[C01-100 : svartalfheim](/assets/module/c01/100/svartalfheim).
