
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "vm.h"

typedef struct {
    uint8_t name[15];
    uint32_t nargs;
} VM_INSTRUCTION;

static VM_INSTRUCTION vm_instructions[] = {
    { "exit",     0 },    // 0
    { "cprint",   0 },    // 1
    { "rprint",   0 },    // 2
    { "iconst",   1 },    // 3
    { "scanf",    0 },    // 4
    { "rloada",   0 },    // 5
    { "rloadspa", 0 },    // 6
    { "rstorec",  0 },    // 7
    { "rcinc",    0 },    // 8
    { "rtesteq",  2 },    // 9
    { "jump_tf_ip",   1 },    // 10
    { "jump_ip",  1 },    // 11
    { "rxor",     0 },    // 12
    { "radd",     1 },    // 13
    { "rloadspb", 0 },    // 14
    { "testexit", 0 },    // 15

};

void vm_init(VM *vm, int *code, int code_size, int nglobals)
{
    vm->code = code;
    vm->code_size = code_size;
    vm->globals = calloc(nglobals, sizeof(int));
    vm->nglobals = nglobals;
}

void vm_free(VM *vm)
{
    free(vm->globals);
    free(vm);
}

VM *vm_create(int *code, int code_size, int nglobals)
{
    VM *vm = calloc(1, sizeof(VM));
    vm_init(vm, code, code_size, nglobals);
    return vm;
}

void vm_exec(VM *vm, int startip, bool trace)
{
    // registers
    uint32_t ip;         // instruction pointer register
    uint32_t sp;         // stack pointer register

    uint32_t a = 0;      //register a
    uint32_t b = 0;      //register b
    uint32_t counter = 0;
    uint32_t tflag = 0;  // test flags
    uint32_t addr = 0; // addr to jump

    uint8_t xor_key[] = {0xf1, 0xa2, 0x4, 0x17, 0x45};

    uint32_t * sreg_t[] = {&a,&b,&counter};

    ip = startip;
    sp = -1;
    uint32_t opcode = vm->code[ip];

    while (opcode != EXIT && ip < vm->code_size) {
        ip++;
        switch (opcode) {
           case CONST_INT:
                vm->stack[++sp] = vm->code[ip++];  // push operand
                break;
            case PRINT_CHAR:
                printf("%c", vm->stack[sp--]);
                break;
            case PRINT_RET:
                printf("\n");
                break;
            case SCAN_CHAR:
                scanf("%c", &a);
                a = (int)a & 0xff;
                if (b >= vm->nglobals) {
                    printf("[Critical] OutOfBounds VM Globals args");
                    return;
                }
                vm->globals[counter] = a;
                break;
            case REG_LOAD_A:
                if (counter > vm->nglobals) {
                    printf("[Critical] OutOfBounds VM Globals args");
                    return;
                }
                a = vm->globals[counter];
                break;
            case REG_STORE_COUNTER:
                counter = vm->stack[sp--];
                break;
            case REG_INC_COUNTER:
                counter++;
                break;
            case REG_LOAD_SP_A:
                a = vm->stack[sp--];
                break;
            case TEST_REG:
                tflag = 0;
                if (*(sreg_t[vm->code[ip++]]) == *(sreg_t[vm->code[ip++]])) {
                    tflag = 1;
                }
                break;
            case JUMP_TFLAG_IP:
                addr = vm->code[ip++];
                if (addr > vm->code_size) {
                    printf("[Critical] OutOfMapped IP");
                    return;
                }
                if (tflag) {
                    ip = addr;
                }
                break;
            case JUMP_IP:
                addr = vm->code[ip++];
                if (addr > vm->code_size) {
                    printf("[Critical] OutOfMapped IP");
                    return;
                }
                ip = addr;
                break;
            case REG_ADD:
                b = vm->code[ip++];
                a += b;    
                break;
            case REG_XOR:
                b = xor_key[counter % sizeof(xor_key)];
                a ^= b;
                break;
            case REG_LOAD_SP_B:
                b = vm->stack[sp--];
                break;
            case TEST_EXIT:
                if (a != b) {
                    printf("Nah");
                    return;
                }
                break;
            default:
                printf("invalid opcode: %d at ip=%d\n", opcode, (ip - 1));
                exit(1);
        }
        if (trace) vm_print_state(vm, sp, a, b, counter, tflag, ip);
        opcode = vm->code[ip];
    }
    if (trace) vm_print_data(vm->globals, vm->nglobals);
}

void vm_print_state(VM *vm, int sp, int a, int b, int counter, int tflag, int ip) {
    int * code = vm->code;
    int opcode = code[ip];
    VM_INSTRUCTION *inst = &vm_instructions[opcode];

    switch (inst->nargs) {
        case 0:
            printf("%04d:  %-20s -> ", ip, inst->name);
            break;
        case 1:
            printf("%04d:  %-10s%-10d -> ", ip, inst->name, code[ip + 1]);
            break;
    }

    printf("a=%02d|b=%02d|counter=%02d|tflag=%02d|ip=%02d --> ", a, b, counter, tflag, ip);

    int * stack = vm->stack;
    printf("stack=[");
    for (int i = 0; i <= sp; i++) {
        printf(" %02d", stack[i]);
    }
    printf(" ]\n");
}

void vm_print_data(int *globals, int count)
{
    printf("Data memory:\n");
    for (int i = 0; i < count; i++) {
        printf("[%d:%d]", i, globals[i]);
    }
    printf("\n"); 
}

