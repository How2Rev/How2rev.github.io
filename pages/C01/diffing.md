---
layout: default
---

# Recommended Ressource

Diffing is an essential concept when working with binaries and frameworks. It allows you to quickly identify modifications between new binaries or recover symbols in stripped binaries.

Here is a list of resources you can read to understand this concept:  
- [Post EN] [Blackhat Talk: Issues with CVE patches & the easy introduction of 1-day exploits](https://www.blackhat.com/presentations/bh-usa-09/OH/BHUSA09-Oh-DiffingBinaries-SLIDES.pdf)
- [Video FR] [En Bref #01 - Diffing & Symbols recuperation : https://www.youtube.com/watch?v=owDu_ULlzfk](https://www.youtube.com/watch?v=owDu_ULlzfk)

# Binary Diffing

> Original lesson from https://www.orangecyberdefense.com/be/blog/introduction-to-binary-diffing-part-2

Binary diffing is a way to visualize and spot differences between two binaries. It presents us with a set of non-trivial challenges. Usually if you want to compare two files it’s more often than not if they are identical. If that’s the case you can just do a byte by byte comparison; this will however not suffice when it comes to binary diffing. One of the core challenges we need to solve is to be able to find the functions within the binary. This might sound like a trivial problem but if you take into account the challenges that come with indirect calls, virtual function tables, jump tables, exception handling and different calling conventions you quickly realize it might not be trivial, and in fact there is no perfect solution. 

On top of that we have to overcome the fact that functions might not reside on the same offsets within the file, functions might not have the same amount of basic blocks, basic blocks might have changed in size and instructions might have been removed/swapped/changed within the basic blocks.

As these tools parse the binary they collect features such as functions, `CFG (Call Flow Graph)` and function flow charts. In addition, there is detailed information collected on the basic blocks, their edges and what instructions they contain. In some cases binary diffing tools also make use of – or are incorporated into – other tools such as `IDA Pro`, `Ghidra`, or `Binaryninja`. This gives easy access to a higher abstraction level with their respective intermediate languages and has the benefit of removing a lot of the low-level noise that doesn’t actually explain what the function is doing, such as stack operations, function prologue, and epilogue.

Here are some strategies that may be deployed: 

- Function based hashing which matches identical functions
- Function name based hashing which matches the actual function names
MD-index – basically a “hash function” for CFGs in which the algorithm is based on the graph and in which the topological order and in- and out-degree are a part of the algorithm used to calculate a hash that can be easily matched. This algorithm is then used in multiple ways.
- Small prime product in which the matching is calculated by giving each mnemonic a corresponding prime number, and then all mnemonics are multiplied to give us a value that is independent from the position of each of the mnemonics.
- Matching back edges of loops using the `Lengauer-Tarjan` algorithm – an algorithm used to quickly find dominators in a flowgraph.
- String references
- Constants used
- Call sequences
- Edge prime product in which the source and destination basic block prime product matches

This is in no way a comprehensive list, but it shows some of the strategies used and that it’s way more complex than a naive byte-by-byte comparison. It should also be noted that none of these techniques are relied on in isolation but are instead combined together to ultimately provide you with a sufficient confidence level in the matches it ends up with.

##  Are there any actual real-world uses?

In malware analysis it’s a good way to get a quick start on a new version of a family you’ve previously reverse engineered. If you’ve already spent days reverse engineering a sample and all of a sudden a new version is released then the question becomes – what changed? Without binary diffing this is tedious manual work in which you are pretty much left trying to figure out which functions are the same before manually transferring function signatures, types and names to the new binary.

This is where binary diffing tools such as `Diaphora` and `BinDiff` really shine as they can provide you with an easy way to match the majority of functions and to transfer their names over to the new sample. You will also get a quick overview of what has changed and which functions were added/removed as well as some indication of the confidence of those matches.

In vulnerability research/red teaming it’s a good way to develop 1-days. If you want to show the impact of not keeping your system up to date, there is no better way to show the cost of not maintaining a decent patch management than owning the network.

Binary diffing also provides researchers with a hint of a module/system that contains vulnerabilities, and where there is one there might also be others. Or perhaps a patch was based on a bad root-cause analysis which in turn makes it possible to bypass the patch entirely.

## What tools can we use?
### BinDiff

We have multiple tools to choose from, but the most well-known of them is `BinDiff` – developed by `Zynamics and Halvar Flake’s` team and later bought by Google. Today it might not get new killer features all the time, but it’s been made available for both `Ghidra` and `Binaryninja`, It has been the unparalleled champion of binary diffing for years, and became the industry standard.

`BinDiff` is a comparison tool for binary files, that assists vulnerability researchers and engineers to quickly find differences and similarities in disassembled code.

With BinDiff you can identify and isolate fixes for vulnerabilities in vendor-supplied patches. You can also port symbols and comments between disassemblies of multiple versions of the same binary or use `BinDiff` to gather evidence for code theft or patent infringement.

`Bindiff` comes with its own UI where we can diff files we want to compare:

![bindiff_diff_gui](/pages/C01/img/diffing/bindiff_diff_gui.png)

We can then pick and compare a function directly in their UI. This is also accessible from the context menu inside of IDA.

![bindiff_diff](/pages/C01/img/diffing/bindiff_diff.png)

As the results are presented we get a number of tabs which give you some statistics. The Primary Unmatched tab shows functions that exist in the currently opened IDB that were not found in the other file, while the Secondary Unmatched and Matched Functions tabs should be self-explanatory.

![bindiff_ida_result](/pages/C01/img/diffing/bindiff_ida_result.png)

As we can see, the Matched Function tab also provides us with a measurement on the similarities as well as the confidence of the match, the algorithm that was used and the names of the respective files. From the context menu we can now import symbols.

### Diaphora

We also have Diaphora, which is being actively developed and maintained and has both new features added as well as additional features planned for the future.

It also has some really interesting features such as:

- Parallel diffing
- Pseudo-code based heuristics
- Pseudo-code patches generation
- Ability to port structs, enums and typedefs
- Diffing pseudo-codes (with syntax highlighting!)
- Scripting support (for both the exporting and diffing processes) 

Diaphora is a plugin to IDA and it exports all necessary metadata into a sqlite-database. It then gives you a bunch of options as you can see below.

We first open a file in IDA and export all the necessary metadata into a sqlite-database before then opening the second file and comparing the sqlite files:

![diaphora_export](/pages/C01/img/diffing/diaphora_export.png)

The UI after the comparison finishes is pretty much the same as BinDiff.
However when comparing functions side-by-side it’s all done in IDA with the option to get an assembly, a pseudo-code and a patch-style comparison.

![pseudo_diff](/pages/C01/img/diffing/pseudo_diff.png)

In summary, they are both potent tools and in the context of diffing Windows patches it won’t really matter which you choose. As we have seen, the technique of binary diffing is useful for visualizing the difference between two binaries and is useful for purposes including variant analysis, vulnerability research and patch validation.

In the final part of this blog series, we will step through the process of diffing a Windows patch using the BinDiff tool.

# C01-07: Finding the Vulnerable Function (Medium--)

In this challenge, we have 2 binaries: 
- `v8_AFHXc8001.bin`: The old kernel of an IT company that was recently 0day'd...
- `v8_AFHXc8002.bin`: The newest kernel found in the update package.

> The kernel used is `tiny-linux`. The vulnerable function was introduced specifically for this challenge.

It seems some functions are lacking proper security...
Your goal is to diff the binaries and find what has been patched!

The flag format is LRCTF{f1}, where

f1: The function that was patched. It should be a poorly secured buffer that results in an overflow.

> This challenge does not require finding an actual OOB. You must use a diffing tool to search the patched functions and identify where the vulnerabilities are.

`flag md5sum: d2a8c400c6b13499fd6a95368ea6064f`

[C01-07: v8_AFHXc8001.bin](/assets/module/c01/07/v8_AFHXc8001.bin)  
[C01-07: v8_AFHXc8002.bin](/assets/module/c01/07/v8_AFHXc8002.bin)  

# C01-08: Recovering Symbols of a Stripped Static Simple C Program (Easy)

In this challenge, we have 2 binaries:
- `my_first_c_program`: A simple C program that performs some basic libc calls and then exits.
- `libc.so.6`: The libc used to compile the program.

The flag format is LRCTF{f1:f2:f3}, where

f1/f2/f3: The recovered libc functions in lowercase. Your goal is to diff the program with libc to recover the actual libc calls made in `main()`. But where is `main`?

> Please do not manually reverse engineer stripped libc calls in the main. You can find some string references that might provide the correct answer, but this isn't the intended way to solve the challenge.

`flag md5sum: 6246faf35e407dce56c2cbd8d0d666d0`

Example:

```c
#include <stdio.h>
int main() {
    unsigned char buf[4];
    FILE *file = fopen("file.bin", "rb");
    size_t bytesRead = fread(buf, 1, 4, file);
    fclose(file);
    return 0;
}
```

=> flag = LRCTF{fopen:fread:fclose}

[C01-08: my_first_c_program](/assets/module/c01/08/my_first_c_program)  
[C01-08: libc.so.6](/assets/module/c01/08/libc.so.6)  