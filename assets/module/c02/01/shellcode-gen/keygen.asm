section .data
    hello db 'Hello, World!', 0

section .text
    global _start

_start:

    mov r8, 0x8f77186a9ecef630
    ;mov rdi, 0xF256394BF0A19F44
    xor r8, rdi
    push r8

    mov r8, 0x364b543b1b4d8d70
    ;mov rax, 0x432867435E12FF43
    xor r8, rax
    push r8

    mov r8, 0xb6175607afc2ae37
    ;mov rdi, 0xF256394BF0A19F44
    xor r8, rdi
    push r8

    mov r8, 0x226a1c050a51ad0f
    ;mov rax, 0x432867435E12FF43
    xor r8, rax
    push r8

    ; syscall write(fd, *buf, count)
    mov rax, 1             ; syscall number for sys_write
    mov rdi, 1             ; file descriptor 1 is stdout
    mov rsi, rsp
    mov rdx, 32           ; length of the message
    syscall

    ; syscall exit(status)
    mov rax, 60            ; syscall number for sys_exit
    xor rdi, rdi           ; exit code 0
    syscall
