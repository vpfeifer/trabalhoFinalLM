#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

//Auxiliares
void PrintMatriz(int tamanho, int * matriz);
void InicializaMatriz(int tamanho, int * matriz);
void obtem_estatistica(int tamanho, int escalar, int * matrizA, int * matrizB, int stress, char func[], int (*calc_generico)(int, int, int *, int *));

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

  int L = 4; //tamanho lado matriz
  int escalar = 5; //escalar da multiplicacao

  int matrizA[L * L];
  int matrizB[L * L];

  InicializaMatriz(L*L, matrizA);
  InicializaMatriz(L*L, matrizB);

  int stress = 10000000;

  obtem_estatistica(L, escalar, matrizA, matrizB, stress, "C", &calc_c);

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

void obtem_estatistica(int tamanho, int escalar, int * matrizA, int * matrizB, int stress, char func[], int (*calc_generico)(int, int, int *, int *))
{
  struct timeval  inicio, fim; //para medicao de tempo

  gettimeofday(&inicio, NULL);

  int i;
  for (i = 0; i < stress; ++i)
  {
    calc_generico(tamanho, escalar, matrizA, matrizB);
  }

  gettimeofday(&fim, NULL);

  printf("Calculo em %s (%d x): %lf segundos.\n", func, stress,
    (double) (fim.tv_usec - inicio.tv_usec) / 1000000 + (double) (fim.tv_sec - inicio.tv_sec));
}