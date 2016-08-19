//3. 	Escrever um programa, em C, que lê um vetor chamado Numeros de 20 números inteiros e exibe os seus elementos.
//	Encontre, a seguir, o menor elemento do vetor e a sua posição no vetor, o maior elemento do vetor e a sua posição no
//	vetor, e exiba estas informações. Escreva também função que receba o vetor e um valor e retorne o índice onde o
//	valor está localizado, caso o valor não seja encontrado retorne -1.
//	Exemplo:
//	Lido:
//	5 18 2 15 3 13 20 14 1 12 6 16 9 17 8 11 7 19 10 4
//	Exibido:
//	5 18 2 15 3 13 20 14 1 12 6 16 9 17 8 11 7 19 10 4
//	1 e o menor elemento do vetor e sua posição no vetor e 8
//	20 e o maior elemento do vetor e sua posição no vetor e 6
//	14 está localizado no índice 7

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

void Exibir(int vet[])
{
	int i;
	for (i = 0; i<tam; i++)
	{
		printf("%d ", vet[i]);
	}
	printf("\n\n");
}

void ExibirMenor(int vet[])
{
	int i, m = vet[0], pos = 0;
	for (i = 0; i<tam; i++)
	{
		if(vet[i] < m)
		{
			m = vet[i];
			pos = i;
		}
	}
	printf("%d é o menor elemento do vetor e sua posição é %d\n\n", m, pos+1);
}

void ExibirMaior(int vet[])
{
	int i, M = vet[0], pos = 0;
	for (i = 0; i<tam; i++)
	{
		if(vet[i] > M)
		{
			M = vet[i];
			pos = i;
		}
	}
	printf("%d é o maior elemento do vetor e sua posição é %d\n\n", M, pos+1);
}

int BuscarValor(int vet[], int val)
{
	int i;
	for (i = 0; i<tam; i++)
	{
		if(vet[i] == val)
			return i;
	}
	return -1;
}

void menu(int vet[])
{
	int bus, val;
	char op;
	do
	{
		printf("Menu:\n\n");
		printf("1- Exibir vetor Números\n");
		printf("2- Exibir menor valor do vetor Números\n");
		printf("3- Exibir maior valor do vetor Números\n");
		printf("4- Buscar um valor no vetor Números\n");
		printf("0- Sair\n");
		printf("Informe sua opção: ");
		op = getchar();
		fflush(stdin);
		printf("\n");
		switch(op)
		{
		case '1':
			Exibir(vet);
			break;
		case '2':
			ExibirMenor(vet);
			break;
		case '3':
			ExibirMaior(vet);
			break;
		case '4':
			printf("Informe o valor a ser buscado: ");
			scanf("%d", &val);
			fflush(stdin);
			bus = BuscarValor(vet, val);
			if(bus == -1)
				printf("Valor não encontrado\n\n");
			else
				printf("%d está localizado no índice %d\n\n", val, bus+1);
			break;
		case '0':
			break;
		default:
			printf("Opção inválida\n\n");
		}
	}while(op != '0');
}

int main () 
{
	int vet[tam];
	setlocale(LC_ALL, "");
	printf("Preenchimento do vetor Números:\n\n");
	preencherVINT(vet);
	menu(vet);
	return 0;
}
