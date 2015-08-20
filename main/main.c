#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Auxiliares
void PrintMatriz(int tamanho, int * matriz);
void InicializaMatriz(int tamanho, int * matriz);

//Funcao para calculo em c
int calc_c(int tamanho, int escalar, int * matrizA, int * matrizB);
#include "calc_c.c" 

//Funcao para calculo em GAS
int calc_gas(int tamanho, int escalar, int * matrizA, int * matrizB);
#include "calc_gas.c"

//Funcao para calculo em NASM
extern int calc_nams(int tamanho, int escalar, int * matrizA, int * matrizB);

int main(int argc, char **argv)
{
  int L = 2; //tamanho matriz

  int matrizA[L * L];
  int matrizB[L * L];
  int escalar = 5;

  srand(time(NULL)); //inicializa seed para gerar numeros random

  InicializaMatriz(L*L, matrizA);
  InicializaMatriz(L*L, matrizB);

  //TODO Medir tempo

  printf("Trabalho Final de LM (Noturno) - Grupo \n");

  //printf("%d\n", calc_c(L*L, escalar, matrizA, matrizB));
  //printf("%d\n", calc_gas(L*L, escalar, matrizA, matrizB));

  return 0;
}

void InicializaMatriz(int tamanho, int * matriz)
{
  while(tamanho >= 0)
  {
    matriz[tamanho] = rand() % 2;
    tamanho--;
  }
}

void PrintMatriz(int tamanho, int * matriz)
{
  int i = 0;

  for (i = 0; i < (tamanho * tamanho); i++)
  {
    if(i % tamanho == 0)
    {
        printf("\n");
    }

    printf("[%d]", matriz[i]);
  }
}