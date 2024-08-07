CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O0 -Wno-unused-but-set-variable -I/usr/include/openssl

OUT="introduction2.bin"

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c -lssl -lcrypto
	strip $(OUT)
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f challenge
