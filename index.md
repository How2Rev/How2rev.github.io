---
layout: default
---

# How2Rev

In this website, you will learn the path to reverse engineering. I will provide challenges that are essential for understanding reverse engineering concepts.

CTF-style challenges are a great way to grasp basic concepts and master them.  
With each concept, you will have different resources to help you understand it, along with an associated challenge.

If you have questions or difficulties, you can ask for help on the Discord server: https://discord.gg/t6DDyUxA4H

> Note: This website does not host lessons. All lessons are external resources. My goal is to gather all the best resources for understanding concepts and mastering them. Only self-created challenges and past CTF event binaries are hosted.

# Disclaimer & Information

This website does not check if you follow the correct path. My purpose is to provide an intended way to solve the challenges. You might be able to solve them by patching or using unintended methods, but that’s not the goal of this website.

Each flag will be saved as LRCTF{} (or as otherwise mentioned).
You can check if you have the correct flag with the provided md5sum for each challenge:  
`echo -n "LRCTF{theFlag}" | md5sum`

Modules aren't sorted by difficulty but by theme. Only C01 will be easier as an introduction, while the rest of the modules will have a linear complexity in the challenge list.

Also, only C01 will contain challenge sources.
For the other modules, you will need to work hard.

Many challenges come from past CTF events or are self-made. I recommend not searching for write-ups until you have made a solid attempt at a challenge—it’s much better to learn by trying hard to solve a difficult challenge.

# C01 - Entry Point to the Reverse Engineering Path

In this module, you will learn the basics of reverse engineering:
 
[C01: Decompilation & Basic Reversing](/pages/C01/introduction.md).  
[C01: The ELF Format](/pages/C01/elf.md).  
[C01: Function Diffing & Symbol Reconstruction](/pages/C01/diffing.md)

# C02 - Low level reversing

In this module, we dive deep into low-level reversing, dealing with binaries that are difficult to emulate or debug. Here we will work with bootloaders, firmware, shellcode, etc.

[C02: Emulation & Custom Loaders](/pages/C02/loaders-and-emulation.md)  
[C02: CPU Introduction](/pages/C02/cpu.md)  

