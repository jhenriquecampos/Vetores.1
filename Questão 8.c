#include <stdio.h>
#include <locale.h>
#define tam 10

void Preencher(int vet1[], int vet2[])
{
	int i;
	for (i = 0; i<tam; i++)
	{
		printf("Informe o c�digo do produto: ");
		scanf("%d", &vet1[i]);
		fflush(stdin);
		printf("Informe a quantidade do produto em estoque: ");
		scanf("%d", &vet2[i]);
		fflush(stdin);
		while(vet2[i] < 0)
		{
			printf("Quantidade inv�lida, digite novamente: ");
			scanf("%d", &vet2[i]);
			fflush(stdin);
		}
	}
	printf("\n");
}

int Verificar(int vet1[], int prod)
{
	int i;
	for (i = 0; i<tam; i++)
	{
		if(prod == vet1[i])
			return i;
	}
	return -1;
}

void Pedido(int vet1[], int vet2[])
{
	int prod, verif, qt;
	printf("Informe o c�digo do produto: ");
	scanf("%d", &prod);
	fflush(stdin);
	verif = Verificar(vet1, prod);
	if(verif == -1)
	{
		printf("Produto inexistente\n");
		return;
	}
	printf("Produto %d\nQuantidade em estoque: %d\n", vet1[verif], vet2[verif]);
	printf("Informe a quantidade desejada do produto: ");
	scanf("%d", &qt);
	fflush(stdin);
	while(qt < 0)
	{
		printf("Inv�lido, digite novamente: ");
		scanf("%d", &qt);
		fflush(stdin);
	}
	if(vet2[verif] < qt)
		printf("N�o tem estoque suficiente dessa mercadoria!\n"); 
	else
	{
		vet2[verif] = vet2[verif] - qt;
		printf("Pedido atendido. Obrigado e volte sempre!\n");
	}
}

void Atendimento(int vet1[], int vet2[])
{
	char cod;
	do
	{
		printf("1- Fazer pedido\n");
		printf("0- Encerrar\n");
		printf("C�digo do cliente: ");
		cod = getchar();
		fflush(stdin);
		switch(cod)
		{
		case '1':
			Pedido(vet1, vet2);
			break;
		case '0':
			break;
		default:
			printf("Inv�lido\n");
		}
		printf("\n");
	}while(cod != '0');
}

int main () 
{
	int vet1[tam], vet2[tam];
	setlocale(LC_ALL, "");
	Preencher(vet1, vet2);
	Atendimento(vet1, vet2);
	return 0;
}