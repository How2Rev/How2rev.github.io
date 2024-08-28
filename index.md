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
[C01: Reversing & Understanding C/ASM Concepts](/pages/C01/c.md).  
[C01: The ELF Format](/pages/C01/elf.md).  
[C01: The Mach-O Format](/pages/C01/mach0.md). (todo)  
[C01: The PE Format](/pages/C01/pe.md). (todo)  
[C01: Function Diffing & Symbol Reconstruction](/pages/C01/diffing.md)

# C02 - Language-Specific Reversing

In this module, we will start with language-specific reversing challenges that will set up our journey:

[C02: Understanding Rust Reversing](/pages/C02/rust.md). (todo)   
[C02: Understanding C++ Reversing](/pages/C02/c++.md). (todo)  
[C02: Understanding Haskell Reversing](/pages/C02/haskell.md). (todo)  

# C03 - Mobile Reversing

In this module, you will understand concepts related to the mobile world:

[C03: Understanding Android Reversing](/pages/C03/apk.md). (todo)  
[C03: Understanding iOS Reversing](/pages/C03/ios.md).(todo)  

# C04 - Obfuscation World

In this module, you will face obfuscation challenges. These challenges are not a reference for real-world problems but an introduction to methodologies and efficiency in dealing with such problems.

[C04: How to Reverse Virtual Machine Obfuscation](/pages/C04/vm.md).(todo)  
[C04: Mixed Boolean Arithmetic Obfuscation Reversing](/pages/C04/mba.md).(todo)  
[C04: Control Flow Flattening Obfuscation Reversing](/pages/C04/cff.md).(todo)  

# C05 - Low-Level Reversing

In this module, we dive deep into low-level reversing, dealing with binaries that are difficult to emulate or debug. Here we will work with bootloaders, firmware, shellcode, etc.

[C05: Custom Loader and How to Approach the Problem](/pages/C05/custom-loader.md).(todo)  
[C05: Reversing Bootloaders](/pages/C05/bootloader.md).(todo)  
[C05: Reversing Firmware](/pages/C05/firmware.md). (todo)  

# C06 - Kernel Reversing

In this module, we will explore resources associated with kernel reversing, concepts, and more:

[C06: Rust Raspberry Pi Custom Kernel Challenge](/pages/C06/rust-custom-kernel.md).(todo)  

# C07 - Cryptography Reversing

This module will contain cryptography challenges. The goal here is not to become a master of crypto (Cryptohack is better for that) but to learn how to reverse and identify cryptographic code in binaries and how to deal with it.

[C07: Search and Understand a Cryptographic Implementation in Code](/page/C07/crypto-basic-implem.md) (todo)
