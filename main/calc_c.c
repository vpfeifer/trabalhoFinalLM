#include <limits.h>
/*
  int novaMatriz[tamanho * tamanho];

  for (i = 0; i < tamanho; i++)
  {
    for (j = 0; j < tamanho; j++)
    {
      novaMatriz[i * tamanho + j] = 0;

      for (k = 0; k < tamanho; k++)
      {
        novaMatriz[i * tamanho + j] += escalar * matrizA[i * tamanho + k] * matrizB[k * tamanho + j];
      }
    }
  }
*/

int calc_c(int tamanho, int escalar, int * matrizA, int * matrizB)
{
   printf("\nMatriz A");
   PrintMatriz(tamanho, matrizA);
   printf("\n\nMatriz B");
   PrintMatriz(tamanho, matrizB);
   printf("\n\n");
   printf("diagonal principal resultante : \n");

  int i = 0;
  int k = 0;

  int menorValor = INT_MAX;
  int auxSoma;

  for (i = 0; i < tamanho; i++)
  {
    auxSoma = 0;

    for (k = 0; k < tamanho; k++)
    {
      auxSoma += escalar * matrizA[i * tamanho + k] * matrizB[k * tamanho + i];
    }

     printf("[%d]", auxSoma);

    if(auxSoma < menorValor)
    {
      menorValor = auxSoma;
    }
  }

  return menorValor;
}