CC=./obfuscator/build/bin/clang
CFLAGS = -Wall -Wextra -std=c99 -O0 -mllvm -sub -fla -bcf
OUT = cff01.bin

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c
	strip $(OUT)
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f $(OUT)
