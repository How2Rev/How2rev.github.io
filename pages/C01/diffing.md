---
layout: default
---

# Diffing

Diffing is an essential concept when working with binaries and frameworks. It allows you to quickly identify modifications between new binaries or recover symbols in stripped binaries.

Here is a list of resources you can read to understand this concept:  
- [EN] [Introduction to binary diffing](https://www.orangecyberdefense.com/be/blog/introduction-to-binary-diffing-part-2)
- [EN] [Blackhat Talk: Issues with CVE patches & the easy introduction of 1-day exploits](https://www.blackhat.com/presentations/bh-usa-09/OH/BHUSA09-Oh-DiffingBinaries-SLIDES.pdf)
- [FR] [En Bref #01 - Diffing & Symbols recuperation](https://www.youtube.com/watch?v=owDu_ULlzfk)

To assist you in binary diffing, here are some commonly used tools:
- **BinDiff**: A popular tool used for comparing binaries.
- **Diaphora**: An open-source tool that offers similar features to BinDiff.

Let's start with a basic challenge to apply this concept.

## Types of Diffing

Diffing heuristics are techniques used to identify differences between binaries. These heuristics can be broadly categorized into several types:

1. **Syntax-based Diffing**: This method compares the syntactic structure of code, such as instructions and control flow graphs, to find differences.
2. **Semantic-based Diffing**: This approach focuses on the meaning and behavior of the code, comparing the effects of instructions and functions.
3. **Pattern-based Diffing**: This technique uses predefined patterns or signatures to detect known changes or vulnerabilities.
4. **Statistical Diffing**: This method employs statistical analysis to identify anomalies or significant changes in the binary data.
5. **Hybrid Diffing**: Combines multiple heuristics to improve accuracy and effectiveness in identifying differences.

Each type of heuristic has its strengths and weaknesses, and the choice of heuristic depends on the specific requirements and context of the diffing task.

# C01-07: Finding the Vulnerable Function

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

# C01-08: Recovering Symbols of a Stripped Static Simple C Program

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