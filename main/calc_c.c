void MultiplicaMatrizPorEscalar(int tamanho, int valor, int * matriz)
{
  while(tamanho >= 0)
  {
    matriz[tamanho] *= 2;
    tamanho--;
  }
}

int* MultiplicaMatrizPorMatriza(int tamanho, int * matrizA, int * matrizB)
{
  int novaMatriz[tamanho];

  int posNovaMatriz = 0;
  int i = 0;
  int j = 0;
  int k = 0;

  int auxLinha = 0;
  int auxColuna = 0;
  int auxSoma = 0;


  for (i = 0; i <= 2; i++)
  {
    for (j = 0; j <= 2; j++)
    {
      auxSoma = 0;

      for (k = 0; k <= 2; k++)
      {
        auxSoma = auxSoma + matrizA[i * tamanho + k] * matrizB[k * tamanho + j];
      }

      novaMatriz[i * tamanho + j] = auxSoma;
    }
  }

  return novaMatriz;
}

int calc_c(int tamanho, int escalar, int * matrizA, int * matrizB)
{
  int * matrizC;

  //MultiplicaMatrizPorEscalar(tamanho * tamanho, 5, matrizA);

  PrintMatriz(tamanho, matrizA);

  printf("\n\n");

  PrintMatriz(tamanho, matrizB);

  printf("\n\n");

  matrizC = MultiplicaMatrizPorMatriza(tamanho, matrizA, matrizB);

  printf("\n\n");

  PrintMatriz(tamanho, matrizC);

  return 0;
}