CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O0 -Wno-parentheses

OUT="mba01.bin"

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c
	strip $(OUT)
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f mba01
