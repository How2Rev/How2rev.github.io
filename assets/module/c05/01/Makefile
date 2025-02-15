CC = clang -v
CFLAGS = -Wall -O2 -target bpf

OUT="ebpf01.bin"

challenge: challenge.c
	$(CC) $(CFLAGS) -o $(OUT) challenge.c
	strip $(OUT)
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f challenge
