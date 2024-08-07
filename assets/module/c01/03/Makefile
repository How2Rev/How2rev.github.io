CC = gcc
CFLAGS = -Wall -Wextra -O0 -Wno-unused-but-set-variable 

OUT="introduction3.bin"

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c
	strip $(OUT)
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f challenge

solve:
	nasm -f elf64 -o solve.o solve.asm
