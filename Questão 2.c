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
		fflush(stdin);
	}
	printf("\n");
}

void inverter(int vet[])
{
	int i, f = tam-1, aux;
	for (i = 0; i<tam/2; i++)
	{
		aux = vet[i];
		vet[i] = vet[f];
		vet[f] = aux;
		f--;
	}
}

void Exibir(int vet[])
{
	int i;
	printf("Vetor invetido:\n");
	for (i = 0; i<tam; i++)
	{
		printf("%d ", vet[i]);
	}
	printf("\n");
}

int main () 
{
	int vet[tam];
	setlocale(LC_ALL, "");
	printf("Preenchimento do vetor:\n\n");
	preencherVINT(vet);
	inverter(vet);
	Exibir(vet);
	return 0;
}