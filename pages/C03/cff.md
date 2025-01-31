---
layout: default
---

# Recommended Ressource:

- [EN][ CFF Deobfuscation](https://github.com/obfuscator-llvm/obfuscator/wiki/Control-Flow-Flattening)
- [EN][ D810 - CFF Deobfuscation plugins](https://eshard.com/posts/D810-a-journey-into-control-flow-unflattening)

# Control Flow Flattening Obfuscation

Control Flow Flattening (CFF) is a technique used to obfuscate the control flow of a program, making it harder to understand and reverse engineer. Here's a simple example to illustrate how it works.

### Original C Program

```c
#include <stdio.h>
#include <string.h>

int check_key(const char *key) {
    if (strcmp(key, "secret") == 0) {
        return 1; // Correct key
    } else {
        return 0; // Incorrect key
    }
}

int main() {
    char key[20];
    printf("Enter the key: ");
    scanf("%19s", key);

    if (check_key(key)) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}
```

> We are assuming we have a decompiler that will decode correctly the obfuscation

### Obfuscated Pseudo Code with Control Flow Flattening 

```c
int check_key(const char *key) {
    int state = 0;
    int result = 0;

    while (1) {
        switch (state) {
            case 0:
                if (strcmp(key, "secret") == 0) {
                    state = 1;
                } else {
                    state = 2;
                }
                break;
            case 1:
                result = 1; // Correct key
                state = 3;
                break;
            case 2:
                result = 0; // Incorrect key
                state = 3;
                break;
            case 3:
                return result;
        }
    }
}

int main() {
    char key[20];
    int state = 0;

    while (1) {
        switch (state) {
            case 0:
                printf("Enter the key: ");
                scanf("%19s", key);
                state = 1;
                break;
            case 1:
                if (check_key(key)) {
                    state = 2;
                } else {
                    state = 3;
                }
                break;
            case 2:
                printf("Access granted.\n");
                state = 4;
                break;
            case 3:
                printf("Access denied.\n");
                state = 4;
                break;
            case 4:
                return 0;
        }
    }
}
```

In the obfuscated version, the control flow is flattened using a `while` loop and a `switch` statement, making it harder to follow the program's logic.

In practice, this obfuscation technique is quite annoying as it prevents us from quickly understanding a function. The lot of handler and state handling make decompilers a lot of errors on stack frame and variables.

### Removing Control Flow Flattening

To unflatten a function:

1. Identify the dispatcher blocks and the state variable.
2. For each block jumping to the dispatcher:
   - Find the state variable's value at the end of the block.
   - Determine the next block to execute based on the dispatcher and state variable.
   - Replace the jump to the dispatcher with a jump to the next block.

Challenges include computing the state variable dynamically and handling dispatcher side effects. Multiple dispatchers may also be used within a single function.

# C03 - 02 : Statical CFF flattening

In this challenge, you will be given a C program that has been obfuscated using Control Flow Flattening (CFF). Your task is to reverse the obfuscation and restore the original control flow of the program. This will involve identifying the state variables and dispatcher blocks, and then reconstructing the original sequence of operations.

The dispatcher is statical.

Flag format is LRCTF{WASD SEQUENCE}

[C03-02: cff01.bin](/assets/module/c03/02/cff01.bin)  

# C03 - 03 : Dynamic CFF flattening

Now dispatcher is dynamically computed. More fun, more tryhard. 
This challenge originally come from `root-me.org` website.
As this challenge give points on website, no solution will be saved on website github site. 

[C03-03: ch38.bin](/assets/module/c03/03/ch38.bin)  
