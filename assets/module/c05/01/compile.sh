#!/bin/sh

if [[ -f "challenge.o" ]]; then
    rm -rf "challenge.o"
fi

/usr/lib/llvm-16/bin/clang -cc1 -triple bpf -emit-obj -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name challenge.c -mrelocation-model static -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -mllvm -treat-scalable-fixed-error-as-warning -debugger-tuning=gdb -v -fcoverage-compilation-dir=/home/titi/Desktop/learn-reverse.com/challenges/reverse-easy/epbf-intro-01 -resource-dir /usr/lib/llvm-16/lib/clang/16 -O2 -Wall -fdebug-compilation-dir=/home/titi/Desktop/learn-reverse.com/challenges/reverse-easy/epbf-intro-01 -ferror-limit 19 -fgnuc-version=4.2.1 -fcolor-diagnostics -vectorize-loops -vectorize-slp -faddrsig -o challenge.o -x c challenge.c

echo "Done compiling"