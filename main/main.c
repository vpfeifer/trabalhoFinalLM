#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

//Auxiliares
void PrintMatriz(int tamanho, int * matriz);
void InicializaMatriz(int tamanho, int * matriz, int rangeMin, int rangeMax);
void obtem_estatistica(int tamanho, int escalar, int * matrizA, int * matrizB, int stress, char func[], int (*calc_generico)(int, int, int *, int *));

//Funcao para calculo em c
int calc_c(int tamanho, int escalar, int * matrizA, int * matrizB);
#include "calc_c.c" 

//Funcao para calculo em GAS
extern int calc_gas(int tamanho, int escalar, int * matrizA, int * matrizB);

//Funcao para calculo em NASM
extern int calc_nasm(int tamanho, int escalar, int * matrizA, int * matrizB);

//Funcao principal
int main(int argc, char **argv)
{
  printf("Trabalho Final de LM (Noturno) - Grupo 4\n");

  srand(time(NULL)); //inicializa seed para gerar numeros random

  int lMax = 500; //tamanho maximo lado matriz
  int escalar = 5; //escalar da multiplicacao

  int matrizA[lMax*lMax];
  int matrizB[lMax*lMax];

  InicializaMatriz(lMax*lMax, matrizA, 1, 10);
  InicializaMatriz(lMax*lMax, matrizB, 1, 10);

  int stress = 100;
  int l;
  for (l = 5; l <= lMax; l += 5)
  {
    obtem_estatistica(l, escalar, matrizA, matrizB, stress, "c   ", &calc_c);
    obtem_estatistica(l, escalar, matrizA, matrizB, stress, "nasm", &calc_nasm);
    obtem_estatistica(l, escalar, matrizA, matrizB, stress, "gas ", &calc_gas);
    // printf("[%d]", calc_c(l, escalar, matrizA, matrizB));
    // printf("[%d]", calc_nasm(l, escalar, matrizA, matrizB));
    // printf("[%d]", calc_gas(l, escalar, matrizA, matrizB));
    // printf("\n");
  }

  return 0;
}

void InicializaMatriz(int tamanho, int * matriz, int rangeMin, int rangeMax)
{
  tamanho--;
  while(tamanho >= 0)
  {
    matriz[tamanho] = rand() % rangeMax + rangeMin;
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

  printf("Calculo em %s (tamanho %3d / %d x): %lf segundos.\n", func, tamanho, stress,
    (double) (fim.tv_usec - inicio.tv_usec) / 1000000 + (double) (fim.tv_sec - inicio.tv_sec));
}