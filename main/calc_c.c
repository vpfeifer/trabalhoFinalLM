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
  // printf("\nMatriz A");
  // PrintMatriz(tamanho, matrizA);
  // printf("\nMatriz B");
  // PrintMatriz(tamanho, matrizB);

  int i = 0;
  int j = 0;
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

    // printf("%d ", auxSoma);

    if(auxSoma < menorValor)
    {
      menorValor = auxSoma;
    }
  }

  return menorValor;
}