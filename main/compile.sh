echo "Executando nasm -f elf -o calc_nasm.o calc_nasm.asm ...."
nasm -f elf -o calc_nasm.o calc_nasm.asm
echo "Executado!"
echo "Executando gcc -m32 main.c calc_nasm.o -o main.out"
gcc -m32 main.c calc_nasm.o -o main.out
echo "Executado! Para rodar: ./main.out"

