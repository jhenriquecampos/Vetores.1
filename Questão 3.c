#include <stdio.h>
#include <locale.h>
#define tam 20

void preencherVINT(int vet[])//preenchimento dos vetores de inteiros
{
	int i;
	for (i = 0; i<tam; i++)
	{
		printf("N�mero %d: ", i+1);
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
	printf("%d � o menor elemento do vetor e sua posi��o � %d\n\n", m, pos+1);
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
	printf("%d � o maior elemento do vetor e sua posi��o � %d\n\n", M, pos+1);
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
		printf("1- Exibir vetor N�meros\n");
		printf("2- Exibir menor valor do vetor N�meros\n");
		printf("3- Exibir maior valor do vetor N�meros\n");
		printf("4- Buscar um valor no vetor N�meros\n");
		printf("0- Sair\n");
		printf("Informe sua op��o: ");
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
				printf("Valor n�o encontrado\n\n");
			else
				printf("%d est� localizado no �ndice %d\n\n", val, bus+1);
			break;
		case '0':
			break;
		default:
			printf("Op��o inv�lida\n\n");
		}
	}while(op != '0');
}

int main () 
{
	int vet[tam];
	setlocale(LC_ALL, "");
	printf("Preenchimento do vetor N�meros:\n\n");
	preencherVINT(vet);
	menu(vet);
	return 0;
}