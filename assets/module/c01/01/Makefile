CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O0 -Wno-unused-but-set-variable -Wl,-Tlinker.ld 

OUT="introduction1.bin"

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f challenge
