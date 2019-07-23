# How to Compile
>*$ gcc -m32 -fno-pic -nostdlib -fno-asynchronous-unwind-tables -g -fno-stack-protector -c any_code.c*  
>*$ nasm -f elf ../asm/call_main.asm*  
>*$ ld -m elf_i386 --entry=start --oformat=binary -Ttext 0x7c00 -o ../bin/any_code.bin call_main.o any_code.o*  
