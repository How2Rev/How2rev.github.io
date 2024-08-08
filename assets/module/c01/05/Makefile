CC = gcc
CFLAGS = -Wall -Wextra -O0 -Wno-div-by-zero

OUT="introduction5.bin"

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c
	strip $(OUT)
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f $(OUT)

solve:
	$(CC) $(CFLAGS) -o solve solve.c