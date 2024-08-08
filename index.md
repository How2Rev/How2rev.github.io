---
layout: default
---

# How2rev

In this website, you will learn the reverse engineering path.
I will provide challenges that are essentials to understand reverse concepts. 

CTF-style challenge are a good way to understand basic concepts and masteries them.  
With every concepts, you will have differents ressources to understanding it with an associated challenge.  

If you have questions, or difficulties, you can ask help on the discord server : https://discord.gg/t6DDyUxA4H

> Note : This website do not host lessons. All lessons are external hosted ressources. My goal is to catch up all good ressources for understand concepts and masteries them.
Only self-created challenges and past CTF event binaries are hosted.

# Disclaimer & Informations

This website does not check if you do the right path, my purpose is to provide you a intended way to solve the challenge. You can probably solve by patching, or doing unintended solve but that's not the goal of this website.

Each flag will be saved as LRCTF{} (or contrary mention)
You can check if you get the right flag with a md5sum provided with each challenge :   
`echo -n "LRCTF{theFlag}" | md5sum`

Modules aren't sorted by difficulties but by theme. Only C01 will be easier for introduction, the rest of modules will have linear complexity in the challenge list.

Also, only C01 will contains challenges source.
For the other modules, you will need to work hard.

A lot of challenges come from Past CTF Event or are selfmade. I recommend to not search writeup until a solid try out on a challenge, that's really better to learn by tryharding a difficult challenge.

# C01 - EntryPoint to reverse path

In this module, you will learn the very basic of reverse : 

[C01 : decompilation & basic reversing](/pages/C01/introduction.md).  
[C01 : Reversing & Understanding C/ASM concepts](/pages/C01/c.md).  
[C01 : the Elf format](/pages/C01/elf.md).
[C01 : the mach0 format](/pages/C01/mach0.md). (todo)  
[C01 : the PE format](/pages/C01/pe.md). (todo)  

# C02 - Language specific reversing

In this module, we will start with language specific reversing challenge that setup our journey

[C02 : Understanding Rust reversing](/pages/C02/rust.md). (todo)   
[C02 : Understanding C++ reversing](/pages/C02/c++.md). (todo)  
[C02 : Understanding Haskell reversing](/pages/C02/haskell.md). (todo)  

# C03 - Mobile reversing

In this module, you will understand concepts linked to the mobile world.

[C03 : Understanding Android reversing](/pages/C03/apk.md). (todo)  
[C03 : Understanding IOS reversing](/pages/C03/ios.md).(todo)  

# C04 - Obfuscation world

In this module, you will face obfuscation challenge. This isn't a reference for real world problems but an introduction to methodology and efficiency to deal with problems like this.

[C04 : How to reverse a Virtual Machine obfuscation](/pages/C04/vm.md).(todo)  
[C04 : Mixed Boolean Arithmetic obfuscation reversing](/pages/C04/mba.md).(todo)  
[C04 : Control flow Flattening obfuscation reversing](/pages/C04/cff.md).(todo)  


# C05 - Low level reversing

In this module, we deep dive into low level reversing, with binaries that are difficult to emulate, to debug. Here we will work with bootloader, firmware, shellcode...

[C05 : Custom loader and how to approach the problem](/pages/C05/custom-loader.md).(todo)  
[C05 : Reversing bootloader](/pages/C05/bootloader.md).(todo)  
[C05 : Reversing Firmware](/pages/C05/firmware.md). (todo)  

# C06 - Kernel reversing

In this module, we will see ressources associated to kernel reversing, concepts and more...

[C06 : Rust Rasperry Pi custom kernel challenge ](/pages/C06/rust-custom-kernel.md).(todo)  

# C07 - Crytography reversing

This module will contain cryptography challenge, the goal here is not to become a master of crypto (cryptohack is better for that) but to learn how to reverse and search cryptographic code in binaries and how to deal with them.

[C07 : Search and Understand a cryptographic implementation in a code](/page/C07/crypto-basic-implem.md)

# C08 - Malware reversing

(todo)

