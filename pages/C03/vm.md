---
layout: default
---

# Recommended Ressource:

[Post EN][ Vm Based Deobfuscation](https://synthesis.to/2021/10/21/vm_based_obfuscation.html)

# Virutal Machine obfuscation

> Lesson from `https://www.hackcyom.com/2024/09/vm-obfuscation-overview/`

An introduction to `VM-based obfuscation`, focusing on design philosophy and future research.

`VM-based obfuscation` is a software security technique that alters code readability and structure to protect it from analysis. It transforms executable code into a format mimicking a CPU's instruction set, complicating reverse engineering.

The significance of `VM-based obfuscation` lies in its ability to protect intellectual property by complicating code analysis, requiring more time and resources from attackers.

This document covers the concept, implementation, and implications of `VM-based obfuscation`, assuming a basic understanding of software security principles. It spans foundational aspects to future research directions in secure software design.

## Basics of VM-based Obfuscation

### VM Entry/Exit
`VM entry` and `exit` manage transitions between the native execution environment and the VM context, preserving and restoring execution state.

```c
typedef struct {
    uint64_t registers[16]; // Example for x86_64 architecture
    uint64_t flags;
} VMContext;

void vm_entry(VMContext *vm_context, NativeContext *native_context) {
    memcpy(&vm_context->native_context, native_context, sizeof(NativeContext));
    memset(vm_context->registers, 0, sizeof(vm_context->registers));
    vm_context->flags = 0;
}

void vm_exit(VMContext *vm_context, NativeContext *native_context) {
    memcpy(native_context, &vm_context->native_context, sizeof(NativeContext));
}
```

### VM Dispatcher
The `VM Dispatcher` controls the fetch-decode-execute cycle, emulating a CPU's instruction cycle within the VM.

```c
void vm_dispatcher(VMContext *vm_context) {
    while (vm_context->running) {
        Instruction instr = vm_fetch(vm_context->ip, vm_context);
        DecodedInstruction decoded = vm_decode(instr, vm_context);
        vm_execute(decoded, vm_context);
        vm_context->ip += sizeof(Instruction);
    }
}
```

### Handler Table
The `Handler Table` defines the semantics of the VM's instruction set, with function pointers indexed by opcode.

```c
typedef void (*Handler)(Args);

Handler handler_table[256]; // Example for one-byte opcodes

void initialize_handlers() {
    handler_table[OP_ADD] = &handle_add;
    handler_table[OP_SUB] = &handle_sub;
}

void handle_add(VMContext *vm_context, DecodedInstruction instr) {
    vm_context->registers[instr.dest] = vm_context->registers[instr.src1] + vm_context->registers[instr.src2];
}
```

## Hardening Techniques of VM Systems
Enhance VM-based system security through various hardening techniques aimed at obfuscating the internal workings and structure.

### Obfuscating Individual VM Components
Handlers are conceptually simple. Apply various obfuscation techniques to the handlers, such as control flow flattening, instruction substitution, and the insertion of opaque predicates.

```c
void obfuscated_handler_addition(VMContext *vm_context, DecodedInstruction instr) {
    if ((time(NULL) & 1) == 0) {
        perform_dummy_operations(vm_context);
    }
    int result = some_calculation(vm_context->registers[instr.src1], vm_context->registers[instr.src2]);
    vm_context->registers[instr.dest] = result;
}
```

### Duplicating VM Handlers
Create multiple versions of the same handler, each differing slightly in its implementation, and randomly assign these when populating the handler table.

```c
void duplicate_handlers(Handler handler_table[]) {
    Handler original_handlers[] = {&handle_add, &handle_sub};
    for (int i = 0; i < 256; i++) {
        handler_table[i] = create_variant(original_handlers[i % NUM_ORIGINAL_HANDLERS]);
    }
}
```

### No Central VM Dispatcher
Avoid using a single central dispatcher. Instead, integrate dispatching logic directly into each handler, making the control flow more complex and less predictable.

### No Explicit Handler Table
Incorporate the next handler’s address within the VM instruction itself, complicating static analysis and understanding of the control flow.

```c
typedef struct {
    void* handler_map;
    uint64_t key;
} VMContext;

typedef enum {
    OP_ADD,
} Opcode;

typedef void (*Handler)(VMContext*, DecodedInstruction);

typedef struct {
    Opcode opcode;
    Handler handler;
} OpcodeHandlerMapping;

Handler dynamic_lookup(void* handler_map, Opcode opcode) {
    HashTable* ht = (HashTable*)handler_map;
    if (hash_table_contains(ht, opcode)) {
        return (Handler)hash_table_get(ht, opcode);
    } else {
        return &default_handler;
    }
}

void dynamic_handler_mapping(VMContext *vm_context, EncryptedInstruction enc_instr) {
    Opcode decrypted_opcode = decrypt_opcode(enc_instr.opcode, vm_context->key);
    Handler handler = dynamic_lookup(vm_context->handler_map, decrypted_opcode);
    DecodedInstruction decoded = decode_instruction(enc_instr);
    handler(vm_context, decoded);
}
```

### Blinding VM Bytecode
Use flow-sensitive instruction decoding mechanisms, such as instruction “decryption” that varies based on specific runtime conditions.

## Research Directions
Future research in `VM-based obfuscation` should focus on creating designs resilient against sophisticated attacks such as symbolic execution, program synthesis, and various forms of static and dynamic analysis. The future of `VM-based obfuscation` is filled with potential.

# C03 - 01 : Simple VM obfuscation

Have you heard of Virtual Machine obfuscation? 
This exercice introduce you a popular method for malware or program to hide inside a virtual machine. 

What will be your approach to this VM?

Flag format is LRCTF{PrintableAscii}

[C03-01: vm.bin](/assets/module/c03/01/babyvm.bin)  

`flag md5sum : b4ddd582fe66ad02bbee44f71a28a341`
