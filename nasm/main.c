#include <stdio.h>

int mulEscalar(int tamanho, int escalar, int * matrizA, int * matrizB);

int main(int argc, char **argv)
{

  int L = 2;
  int escalar = 5;
  int matrizA[L * L];
  int matrizB[L * L];

  matrizA[0] = 1;
  matrizA[1] = 2;
  matrizA[2] = 3;
  matrizA[3] = 4;

  matrizB[0] = 4;
  matrizB[1] = 3;
  matrizB[2] = 2;
  matrizB[3] = 1;

  printf("%d\n", mulEscalar(L, 5,matrizA,matrizB));
  return 0;
}