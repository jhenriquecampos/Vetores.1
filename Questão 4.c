//4. 	Faça um algoritmo, em C, que leia dois vetores A e B de tamanho 10. Depois gere, a partir deles, um vetor C, o qual
//	corresponde a intercalação dos elementos dos vetores A e B. Ou seja, você deve colocar em C um elemento de A,
//	depois um elemento de B, outro elemento de A, outro elemento de B e assim sucessivamente. Todos os elementos de
//	A e B devem estar em C.
//	Exemplo:
//	A:
//	5 2 3 4 1 6 9 8 7 10
//	B:
//	18 15 13 14 12 16 17 11 19 20
//	C:
//	5 18 2 15 3 13 4 14 1 12 6 16 9 17 8 11 7 19 10 20

#include <stdio.h>
#include <locale.h>
#define tam 20

void preencherVINT(int vet[])//preenchimento dos vetores de inteiros
{
	int i;
	for (i = 0; i<tam; i++)
	{
		printf("Número %d: ", i+1);
		scanf("%d", &vet[i]);
	}
	printf("\n");
}

void Intercal(int vetA[], int vetB[], int vetC[])
{
	int i, contC = 0;
	for (i = 0; i<tam; i++)
	{
		vetC[contC] = vetA[i];
		contC++;
		vetC[contC] = vetB[i];
		contC++;
	}
}

void Exibir(int vetA[], int vetB[], int vetC[])
{
	int i;
	printf("Vetor A:\n");
	for (i = 0; i<tam; i++)
	{
		printf("%d ", vetA[i]);
	}
	printf("\nVetor B:\n");
	for (i = 0; i<tam; i++)
	{
		printf("%d ", vetB[i]);
	}
	printf("\nVetor C:\n");
	for (i = 0; i<tam*2; i++)
	{
		printf("%d ", vetC[i]);
	}
	printf("\n");
}
int main () 
{
	int vetA[tam], vetB[tam], vetC[tam*2];
	setlocale(LC_ALL, "");
	printf("Preenchimento do vetor A:\n\n");
	preencherVINT(vetA);
	printf("Preenchimento do vetor B:\n\n");
	preencherVINT(vetB);
	Intercal(vetA, vetB, vetC);
	Exibir(vetA, vetB, vetC);
	return 0;
}
