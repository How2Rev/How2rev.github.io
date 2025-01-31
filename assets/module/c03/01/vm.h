
#ifndef VM_H_
#define VM_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DEFAULT_STACK_SIZE      1000
#define DEFAULT_CALL_STACK_SIZE 100
#define DEFAULT_NUM_LOCALS      10

typedef enum {
    EXIT = 0, //exit opcode
    PRINT_CHAR = 1, // print a char
    PRINT_RET = 2, // print a return line
    CONST_INT = 3, // store a integer
    SCAN_CHAR = 4, //take a input from stdin
    REG_LOAD_A = 5 ,//load a value from globals[counter] to A
    REG_LOAD_SP_A = 6 ,//load a value from stack to register A
    REG_STORE_COUNTER = 7, //store a value from stack to counter
    REG_INC_COUNTER = 8, //counter++
    TEST_REG = 9, //test X == Y, TFLAG=1 if true
    JUMP_TFLAG_IP = 10, //jump to IP if tflags=1
    JUMP_IP = 11, //jump to IP
    REG_XOR = 12, //xor a = a^xor_key[counter % len(xor_key)]
    REG_ADD = 13, //add a= a+b
    REG_LOAD_SP_B = 14, //load a value from stack to register B
    TEST_EXIT = 15, // test a==b, exit if not
    
} VM_CODE;

typedef struct {
    int returnip;
    int locals[DEFAULT_NUM_LOCALS];
} Context;

typedef struct {
    int *code;
    int code_size;

    // global variable space
    int *globals;
    int nglobals;

    // Operand stack, grows upwards
    int stack[DEFAULT_STACK_SIZE];
} VM;

VM *vm_create(int *code, int code_size, int nglobals);
void vm_free(VM *vm);
void vm_init(VM *vm, int *code, int code_size, int nglobals);
void vm_exec(VM *vm, int startip, bool trace);
void vm_print_state(VM *vm, int sp, int a, int b, int counter,  int tflag, int ip);
void vm_print_data(int *globals, int count);

#ifdef __cplusplus
}
#endif

#endif
