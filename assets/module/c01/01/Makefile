CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O3 -Wl,-Tlinker.ld -ldl -Wno-pointer-to-int-cast

OUT="introduction1.bin"

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f challenge
