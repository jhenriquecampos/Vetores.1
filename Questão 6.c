#include <stdio.h>
#include <locale.h>
#define tam 12

void Preencher(float vet[])
{
	int i;
	for (i = 0; i<tam; i++)
	{
		printf("Temperatura %d: ", i+1);
		scanf("%f", &vet[i]);
	}
}

void Exibir(float vet[])
{
	int i = 0, posM = 0, posm = 0;
	float maior = vet[0], menor = vet[0];
	for (i = 1; i<tam; i++)
	{
		if(maior < vet[i])
		{
			maior = vet[i];
			posM = i;
		}
		if(menor > vet[i])
		{
			menor = vet[i];
			posm = i;
		}
	}
	switch(posM)
	{
	case 0:
		printf("A maior temperatura � %.2f�C do m�s de Janeiro\n", vet[posM]);
		break;
	case 1:
		printf("A maior temperatura � %.2f�C do m�s de Fevereiro\n", vet[posM]);
		break;
	case 2:
		printf("A maior temperatura � %.2f�C do m�s de Mar�o\n", vet[posM]);
		break;
	case 3:
		printf("A maior temperatura � %.2f�C do m�s de Abril\n", vet[posM]);
		break;
	case 4:
		printf("A maior temperatura � %.2f�C do m�s de Maio\n", vet[posM]);
		break;
	case 5:
		printf("A maior temperatura � %.2f�C do m�s de Junho\n", vet[posM]);
		break;
	case 6:
		printf("A maior temperatura � %.2f�C do m�s de Julho\n", vet[posM]);
		break;
	case 7:
		printf("A maior temperatura � %.2f�C do m�s de Agosto\n", vet[posM]);
		break;
	case 8:
		printf("A maior temperatura � %.2f�C do m�s de Setembro\n", vet[posM]);
		break;
	case 9:
		printf("A maior temperatura � %.2f�C do m�s de Outubro\n", vet[posM]);
		break;
	case 10:
		printf("A maior temperatura � %.2f�C do m�s de Novembro\n", vet[posM]);
		break;
	case 11:
		printf("A maior temperatura � %.2f�C do m�s de Dezembro\n", vet[posM]);
		break;
	}//Fim do switch da maior temperatura
	printf("\n");
	switch(posm)
	{
	case 0:
		printf("A menor temperatura � %.2f�C do m�s de Janeiro\n", vet[posm]);
		break;
	case 1:
		printf("A menor temperatura � %.2f�C do m�s de Fevereiro\n", vet[posm]);
		break;
	case 2:
		printf("A menor temperatura � %.2f�C do m�s de Mar�o\n", vet[posm]);
		break;
	case 3:
		printf("A menor temperatura � %.2f�C do m�s de Abril\n", vet[posm]);
		break;
	case 4:
		printf("A menor temperatura � %.2f�C do m�s de Maio\n", vet[posm]);
		break;
	case 5:
		printf("A menor temperatura � %.2f�C do m�s de Junho\n", vet[posm]);
		break;
	case 6:
		printf("A menor temperatura � %.2f�C do m�s de Julho\n", vet[posm]);
		break;
	case 7:
		printf("A menor temperatura � %.2f�C do m�s de Agosto\n", vet[posm]);
		break;
	case 8:
		printf("A menor temperatura � %.2f�C do m�s de Setembro\n", vet[posm]);
		break;
	case 9:
		printf("A menor temperatura � %.2f�C do m�s de Outubro\n", vet[posm]);
		break;
	case 10:
		printf("A menor temperatura � %.2f�C do m�s de Novembro\n", vet[posm]);
		break;
	case 11:
		printf("A menor temperatura � %.2f�C do m�s de Dezembro\n", vet[posm]);
		break;
	}//Fim do switch da menor temperatura
	printf("\n");
}

int main ()
{
	float vet[tam];
	setlocale(LC_ALL, "");
	printf("Preenchimento das Temperaturas\n\n");
	Preencher(vet);
	printf("\n");
	Exibir(vet);
	return 0;
}


