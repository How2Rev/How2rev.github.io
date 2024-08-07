section .text
global _start

_start:
    %define SHARED_MEM_ADDR 0x13000000
    mov rax, SHARED_MEM_ADDR
    
    ; Set l1 to 1337
    mov dword [rax], 1337

    ; Set l2 to 65
    mov byte [rax + 4], 65

    ; Set c3 to "sharedmemory"
    mov rdx, rax
    add rdx, 5  ; Point to c3

    ; Copy string "sharedmemory"
    mov byte [rdx], 's'
    mov byte [rdx + 1], 'h'
    mov byte [rdx + 2], 'a'
    mov byte [rdx + 3], 'r'
    mov byte [rdx + 4], 'e'
    mov byte [rdx + 5], 'd'
    mov byte [rdx + 6], 'm'
    mov byte [rdx + 7], 'e'
    mov byte [rdx + 8], 'm'
    mov byte [rdx + 9], 'o'
    mov byte [rdx + 10], 'r'
    mov byte [rdx + 11], 'y'
    mov byte [rdx + 12], 0

    mov rax, 60       ; syscall number for exit
    xor rdi, rdi     ; exit code 0
    syscall

section .data
