#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InicializaMatriz(int tamanho, int * matriz)
{
	while(tamanho >= 0)
	{
		matriz[tamanho] = rand() % 2;
		tamanho--;
	}
}

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

int main()
{
    srand(time(NULL)); //inicializa seed para gerar numeros random

	int L = 2; //tamanho matriz

	int matrizA[ L * L ];
	int matrizB[ L * L ];
	int * matrizC;

	InicializaMatriz(L*L, matrizA);
	InicializaMatriz(L*L, matrizB);
	//InicializaMatriz(L*L, matrizC);

    //MultiplicaMatrizPorEscalar(L * L, 5, matrizA);

    PrintMatriz(L, matrizA);

    printf("\n\n");

    PrintMatriz(L, matrizB);

    printf("\n\n");

    matrizC = MultiplicaMatrizPorMatriza(L, matrizA, matrizB);

    printf("\n\n");

    PrintMatriz(L, matrizC);
//	printf("%d", matrizA[]);


	return 0;
}

}
"\n\n");

    PrintMatriz(L, matrizC);
//	printf("%d", matrizA[]);


	return 0;
}
");

    PrintMatriz(L, matrizC);
//	printf("%d", matrizA[]);


	return 0;
}
