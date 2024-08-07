CC = gcc
CFLAGS = -Wall -Wextra -O0 -Wno-unused-but-set-variable

OUT="introduction4.bin"

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c
	strip $(OUT)
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f challenge

solve:
	$(CC) $(CFLAGS) -o solve solve.c