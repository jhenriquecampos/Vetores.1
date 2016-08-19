#include <stdio.h>
#include <locale.h>
#define tam 24

int VerificarDisp(int vet[])
{
	int i;
	for (i = 0; i<tam; i++)
	{
		if(vet[i] == 0)
			return 0;
	}
	return 1;
}

void Disponiveis(int vet[])
{
	int i;
	for (i = 0; i<tam; i++)
	{
		if(vet[i] == 0)
			printf("%d ", i+1);
	}
	printf("\n\n");
}

void Remover(int vet[], int lugar)
{
	char op;
	if(vet[lugar-1] == 1)
	{
		printf("Remover cliente?\n");
		printf("1- Sim\n");
		printf("2- N�o\n");
		printf("Op��o: ");
		op = getchar();
		fflush(stdin);
		while(op < '1' || op > '2')
		{
			printf("Inv�lido, digite novamente: ");
			op = getchar();
			fflush(stdin);
		}
		switch(op)
		{
		case '1':
			vet[lugar-1] = 0;
			printf("\nCliente removido com sucesso\n");
			break;
		case '2':
			break;
		}
	}//Fim do if
	else
		printf("\nLugar j� vazio\n");
}

void Cadastrar(int vet[], int lugar)
{
	if(vet[lugar-1] == 0)
	{
		vet[lugar-1] = 1;
		printf("\nCliente cadastrado com sucesso\n");
	}
	else
		printf("\nLugar j� ocupado\n");
}


void menu(int vetc[], int vetj[])
{
	int lugar, dispC, dispJ;
	char op, pref, sn;
	do
	{
		printf("Menu principal:\n");
		printf("1- Cadastrar cliente\n");
		printf("2- Remover cliente\n");
		printf("0- Sair\n");
		printf("Informe a op��o: ");
		op = getchar();
		fflush(stdin);
		printf("\n");
		switch(op)
		{
		case '1':
			dispC = VerificarDisp(vetc);
			dispJ = VerificarDisp(vetj);
			if(dispC == 1 && dispJ == 1)
			{
				printf("�nibus lotado\n");
				break;
			}
			printf("1- Corredor\n2- Janela\n");
			printf("Informe a prefer�ncia: ");
			pref = getchar();
			fflush(stdin);
			switch(pref)
			{
			case '1':
				dispC = VerificarDisp(vetc);
				if(dispC == 1)
				{
					printf("Corredor lotado\n");
					break;
				}
				printf("Lugares dispon�veis no corredor:\n");
				Disponiveis(vetc);
				printf("Informe o lugar desejado: ");
				scanf("%d", &lugar);
				fflush(stdin);
				printf("Deseja cadastrar o cliente no lugar %d corredor?\n", lugar);
				printf("1- Sim\n2- N�o\nOp��o: ");
				sn = getchar();
				fflush(stdin);
				while(sn < '1' || sn > '2')
				{
					printf("Inv�lido, digite novamente: ");
					sn = getchar();
					fflush(stdin);
				}
				if(sn == '1')
					Cadastrar(vetc, lugar);
				else
					printf("Cliente n�o cadastrado\n");
				break;
			case '2':
				dispJ = VerificarDisp(vetj);
				if(dispJ == 1)
				{
					printf("Janelas lotadas\n");
					break;
				}
				printf("Lugares dispon�veis na janela:\n");
				Disponiveis(vetj);
				printf("Informe o lugar desejado: ");
				scanf("%d", &lugar);
				fflush(stdin);
				printf("Deseja cadastrar o cliente no lugar %d janela?\n", lugar);
				printf("1- Sim\n2- N�o\nOp��o: ");
				sn = getchar();
				fflush(stdin);
				while(sn < '1' || sn > '2')
				{
					printf("Inv�lido, digite novamente: ");
					sn = getchar();
					fflush(stdin);
				}
				if(sn == '1')
					Cadastrar(vetj, lugar);
				else
					printf("Cliente n�o cadastrado\n");
				break;
			default:
				printf("Dado inv�lido\n");
			}
			break;
		case '2':
			printf("1- Corredor\n2- Janela\n");
			printf("Informe a op��o: ");
			pref = getchar();
			fflush(stdin);
			switch(pref)
			{
			case '1':
				printf("Informe o lugar a ser descadastrado: ");
				scanf("%d", &lugar);
				fflush(stdin);
				Remover(vetc, lugar);
				break;
			case '2':
				printf("Informe o lugar a ser descadastrado: ");
				scanf("%d", &lugar);
				fflush(stdin);
				Remover(vetj, lugar);
				break;
			default:
				printf("Dado Inv�lido\n");
			}
			break;
		case '0':
			break;
		default:
			printf("Op��o Inv�lida\n");
		}//Fim do switch
		printf("\n");
	}while(op != '0');
}

int main ()
{
	int vetc[tam] = {{0}}, vetj[tam] = {{0}};
	setlocale(LC_ALL, "");
	menu(vetc, vetj);
	printf("\n");
	return 0;
}