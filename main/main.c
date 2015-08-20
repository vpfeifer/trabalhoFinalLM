#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

//Auxiliares
void PrintMatriz(int tamanho, int * matriz);
void InicializaMatriz(int tamanho, int * matriz);

//Funcao para calculo em c
int calc_c(int tamanho, int escalar, int * matrizA, int * matrizB);
#include "calc_c.c" 

//Funcao para calculo em GAS
int calc_gas(int tamanho, int escalar, int * matrizA, int * matrizB);

//Funcao para calculo em NASM
extern int calc_nams(int tamanho, int escalar, int * matrizA, int * matrizB);

//Funcao principal
int main(int argc, char **argv)
{
  printf("Trabalho Final de LM (Noturno) - Grupo 4\n");

  srand(time(NULL)); //inicializa seed para gerar numeros random

  struct timeval  inicio, fim; //para medicao de tempo
  int i;

  int L = 4; //tamanho lado matriz
  int escalar = 5; //escalar da multiplicacao

  int matrizA[L * L];
  int matrizB[L * L];

  InicializaMatriz(L*L, matrizA);
  InicializaMatriz(L*L, matrizB);

  int stress = 10000000;

  gettimeofday(&inicio, NULL);

  for (i = 0; i < stress; ++i)
  {
    calc_c(L, escalar, matrizA, matrizB);
  }

  gettimeofday(&fim, NULL);

  printf("Calculo em C (%d x): %lf segundos.\n", stress,
    (double) (fim.tv_usec - inicio.tv_usec) / 1000000 + (double) (fim.tv_sec - inicio.tv_sec));

  //printf("%d\n", calc_c(L, escalar, matrizA, matrizB));
  //printf("%d\n", calc_nams(L, escalar, matrizA, matrizB));
  //printf("%d\n", calc_gas(L, escalar, matrizA, matrizB));

  return 0;
}

void InicializaMatriz(int tamanho, int * matriz)
{
  while(tamanho >= 0)
  {
    matriz[tamanho] = rand() % 10 + 1;
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