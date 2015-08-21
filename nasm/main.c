#include <stdio.h>

int mulMatrizes(int tamanho, int escalar, int * matrizA , int * matrizB);

int main(int argc, char **argv)
{

  int L = 2;
  int escalar = 5;
  int matrizA[L * L];
  int matrizB[L * L];

  matrizA[0] = 4;
  matrizA[1] = 3;
  matrizA[2] = 2;
  matrizA[3] = 1;

  matrizB[0] = 1;
  matrizB[1] = 1;
  matrizB[2] = 1;
  matrizB[3] = 1;

  printf("%d\n", mulMatrizes(L, 5,matrizA,matrizB));
  return 0;
}