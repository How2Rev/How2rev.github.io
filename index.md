---
layout: default
---

# WEBSITE IN CONSTRUCTION
Module ready:
- C01

# Introduction

In this website, you will learn the reverse path.
I will provide challenges that are essentials to understand reverse concepts. 

CTF-style challenge are a good way to understand basic concepts and masteries them. 
With every concept, you will have differents ressources to understand it and an associated challenge.
For each concepts, you will face differents types of difficulties, which can be from easy to very complex challenge.

IF you have questions, or difficulties, you can ask help on the discord server : https://discord.gg/t6DDyUxA4H

> Note : This website do not host lessons. All lessons are external hosted ressources. My goal is to catch up all good ressources for understand concepts and masteries them.
Only self-created challenges and past CTF event binaries are hosted.

# Disclaimer & Informations

This website does not check if you do the right path, my purpose is to provide you a intended way to solve the challenge. You can probably solve by patching, or doing unintended solve but that's not the goal of this website.

Each flag will be saved as LRCTF{} (or contrary mention)
You can check if you get the right flag with a md5sum provided with each challenge :   
`echo -n "LRCTF{theFlag}" | md5sum`

You can find all the sources and challenges ressources on the github, but i would recommend to do the challenge before looking sources if you don't want to be spoiled.

# C01 - EntryPoint to reverse path

In this module, you will learn the very basic of reverse : 

- decompilation  
[C01 : decompilation & basic reversing](/pages/C01/introduction.md).
- The C language  
[C01 : Reversing C and essential concepts](/pages/C01/c.md).

- understanding elf/mach0/PE format  
[C01 : the Elf format](/pages/C01/elf.md).  
[C01 : the mach0 format](/pages/C01/mach0.md).  
[C01 : the PE format](/pages/C01/pe.md).  

# C02 - Begginer Path

In this module, we will start with basic reversing challenge that setup our journey

- basic cryptography essentials :   
[C02 : Learning how to recognize and understand cryptography in reverse](/pages/C02/crypto-intro.md).


- languages specific decompilation and associated problems (rust, c++, ...)  
[C02 : Understanding Rust reversing](/pages/C02/rust.md).  
[C02 : Understanding C++ reversing](/pages/C02/c++.md).


# C03 - Mobile Reversing

In this module, you will understand concepts linked to the mobile world.

- The Android path  
[C03 : Understanding APK reversing](/pages/C03/apk.md).

- The IOS Path  
[C03 : Understanding IOS reversing](/pages/C03/ios.md).

# C04 - Obfuscation world

In this module, you will face obfuscation challenge. This isn't a reference for real world problems but an introduction to methodology and efficiency to deal with problems like this.

- Virtual Machine obfuscation
[C04 : How to reverse a VM](/pages/C04/vm.md).

- MBA based obfuscation
[C04 : MBA reversing](/pages/C04/mba.md).

- Control flow flattening obfuscation
[C04 : CFF reversing](/pages/C04/cff.md).


# C05 - Low level Reversing

In this module, we deep dive into low level reversing, with binaries that are difficult to emulate, to debug. Here we will work with bootloader, firmware, shellcode...

- Custom loader reversing   
[C05 : Custom loader and how to approach the problem](/pages/C05/custom-loader.md).

- Bootloader (UEFI/Custom code entrypoint/...)  
[C05 : Reversing bootloader](/pages/C05/bootloader.md).

- Firmware  
[C05 : Reversing Firmware](/pages/C05/firmware.md).


# TODO, next module

C06 - Kernel reversing  
C07 - Malware Reversing