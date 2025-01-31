CC = clang
CFLAGS = -std=c99 -I . 
OUT = babyvm.bin

default: challenge

challenge:
	$(CC) $(CFLAGS) -o $(OUT) vm.c challenge.c
	strip $(OUT)
	rm -rf *.i64

.PHONY: clean
clean:
	rm -f $(OUT)
