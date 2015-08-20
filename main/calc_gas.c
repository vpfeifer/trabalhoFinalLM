int calc_gas(int tamanho, int escalar, int * matrizA, int * matrizB)
{
  asm("mov 12(%ebp),%ebx");
  asm("mov 8(%ebp),%eax");
  asm("add %ebx,%eax");
}