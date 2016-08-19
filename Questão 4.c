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
