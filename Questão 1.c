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

void preencherVOP(char vet[])//preenchimento do vetor de operações
{
	int i;
	for (i = 0; i<tam; i++)
	{
		printf("Informe a operação %d: ", i+1);
		vet[i] = getchar();
		fflush(stdin);
		while(vet[i] != '/' && vet[i] != '*' && vet[i] != '-' && vet[i] != '+')
		{
			printf("Operação inválida, digite novamente: ");
			vet[i] = getchar();
			fflush(stdin);
		}
	}
}

void Vetor4(int vet1[], int vet2[], char vet3[], int vet4[])//preenchimento do vetor resultado
{
	int i;
	for(i = 0; i<tam; i++)
	{
		switch(vet3[i])
		{
		case '+':
			vet4[i] = vet1[i] + vet2[i];
			break;
		case '-':
			vet4[i] = vet1[i] - vet2[i];
			break;
		case '*':
			vet4[i] = vet1[i] * vet2[i];
			break;
		case '/':
			if(vet2[i] != 0)
				vet4[i] = vet1[i] / vet2[i];
			break;
		}
	}
}

void Exibir(int vet1[], int vet2[], char vet3[], int vet4[])//Exibição das operações, operandos e resultados
{
	int i;
	printf("Resultados das operações:\n");
	for(i = 0; i<tam; i++)
	{
		printf("\nOperação realizada %d: ", i+1);
		switch(vet3[i])
		{
		case '+':
			printf("Adição\n");
			break;
		case '-':
			printf("Subtração\n");
			break;
		case '*':
			printf("Multiplicação\n");
			break;
		case '/':
			printf("Divisão\n");
			break;
		}
		printf("\nOperandos envolvidos:\n");
		printf("Operando 1: %d\n", vet1[i]);
		printf("Operando 2: %d\n", vet2[i]);
		printf("\nResultado: ");
		if(vet3[i] == '/' && vet2[i] == 0)
			printf("Infinito\n");
		else
			printf("%d\n", vet4[i]);
		printf("\n");
	}
}

int main () 
{
	int vet1[tam], vet2[tam], vet4[tam];
	char vet3[tam];
	setlocale(LC_ALL, "");
	printf("Preenchimento do vetor 1:\n\n");
	preencherVINT(vet1);
	printf("Preenchimento do vetor 2:\n\n");
	preencherVINT(vet2);
	preencherVOP(vet3);
	Vetor4(vet1, vet2, vet3, vet4);
	Exibir(vet1, vet2, vet3, vet4);
	return 0;
}
