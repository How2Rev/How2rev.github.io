#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/stat.h>
#include <elf.h>

#define SHARED_MEM_SIZE 100
#define SHARED_MEM_ADDR 0x13000000

void *shm_addr;

struct crem {
    uint32_t l1;
    uint8_t l2;
    char c3[20];
};

char flag[] = "LRCTF{Shar3d_M3m0r1_Handl3r}";

void create_shared_memory() {

    shm_addr = mmap((void*)SHARED_MEM_ADDR, SHARED_MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
}

void execute_shellcode(const char *file_path) {
    int fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        exit(-1);
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("Failed to get file size");
        exit(-1);
    }
    size_t file_size = st.st_size;
    void *file_mem = mmap(NULL, file_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE, fd, 0);
    if (file_mem == MAP_FAILED) {
        perror("Failed to map file");
        exit(-1);
    }

    close(fd);
    void (*entry)() = (void (*)())file_mem;
    entry();
}

void check_shared_memory() {
    struct crem *shared_struct = (struct crem *)shm_addr;

    for (int i=0; i < SHARED_MEM_SIZE; i++) {
        printf("%02x", *((uint8_t*)shm_addr + i));
    }
    printf("\n");

    printf("l1 = %d\n", shared_struct->l1);
    printf("l2 = %d\n", shared_struct->l2);
    printf("c3 = %s\n", shared_struct->c3);

    if (shared_struct->l1 == 1337 && shared_struct->l2 == 65 && strcmp(shared_struct->c3, "sharedmemory") == 0) {
        printf("%s\n", flag);
    } else {
        printf("Nop.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    create_shared_memory();
    int pid = fork();
    if (pid > 0) {
        execute_shellcode(argv[1]);
    }
    sleep(1);
    check_shared_memory();
    munmap(shm_addr, SHARED_MEM_SIZE);

    return 0;
}
