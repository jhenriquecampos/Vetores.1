//8. 	Faça um programa para controlar o estoque de mercadorias de uma empresa. Inicialmente o programa deverá ler dois
//	vetores com dez posições cada, onde o primeiro corresponde ao código do produto e o segundo corresponde ao total
//	desse produto em estoque. Logo após, o programa deverá ler um conjunto indeterminado de dados contendo o código
//	de um cliente, o código do produto que este deseja comprar juntamente com a quantidade. Código do cliente igual à
//	zero indica fim do programa. O programa deverá verificar:
//	• Se o código do produto solicitado existe. Se existir, tentar atender ao pedido; caso contrário, exibir mensagem
//	“Código Inexistente”.
//	• Cada pedido feito por um cliente só pode ser atendido integralmente. Caso isso não seja possível, escrever a
//	mensagem “Não tem estoque suficiente dessa mercadoria”. Se puder atendê-lo, escrever a mensagem “Pedido
//	atendido. Obrigado e volte sempre”.
//	• Efetuar a atualização do estoque somente se o pedido for atendido integralmente;
//	• No final do programa, escrever os códigos dos produtos com seus respectivos estoques já atualizados.

#include <stdio.h>
#include <locale.h>
#define tam 10

void Preencher(int vet1[], int vet2[])
{
	int i;
	for (i = 0; i<tam; i++)
	{
		printf("Informe o código do produto: ");
		scanf("%d", &vet1[i]);
		fflush(stdin);
		printf("Informe a quantidade do produto em estoque: ");
		scanf("%d", &vet2[i]);
		fflush(stdin);
		while(vet2[i] < 0)
		{
			printf("Quantidade inválida, digite novamente: ");
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
	printf("Informe o código do produto: ");
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
		printf("Inválido, digite novamente: ");
		scanf("%d", &qt);
		fflush(stdin);
	}
	if(vet2[verif] < qt)
		printf("Não tem estoque suficiente dessa mercadoria!\n"); 
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
		printf("Código do cliente: ");
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
			printf("Inválido\n");
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
