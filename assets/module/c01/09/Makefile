CC = clang
CFLAGS = -Wall -O2 
OUT="crypto01"

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c
	strip $(OUT)
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f challenge
