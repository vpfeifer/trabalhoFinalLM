nasm -f elf -o mulMatrizes.o mulMatrizes.asm
gcc -m32 main.c mulMatrizes.o