#include <stdio.h>
#include <locale.h>
#define tam 10

void Preencher(float vet[])
{
	int i;
	for (i = 0; i<tam; i++)
	{
		printf("Número %d: ", i+1);
		scanf("%f", &vet[i]);
	}
	printf("\n\n");
}

float Media(float vet[])
{
	int i;
	float total = 0;
	for (i = 0; i<tam; i++)
	{
		total = total + vet[i];
	}
	return total/tam;
}

void BuscarMaisProx(float vet[])
{
	int i, pos = 0;
	float med = Media(vet), dif, compara;
	if(med < 0)
		med = med*(-1);
	if(vet[0] < 0)
		dif = med - (vet[0]*(-1));
	else
		dif = med - vet[0];
	for (i = 1; i<tam; i++)
	{
		if(vet[i] < 0)
			compara = med - (vet[i]*(-1));
		else
			compara = med - vet[i];
		//
		if(compara < 0)
			compara = compara*(-1);
		//
		if(dif < 0)
			dif = dif*(-1);
		//
		if(vet[i] < 0)
		{
			if(dif > compara)
			{
				dif = compara;
				pos = i;
			}
		}
		else
		{
			if(dif > compara)
			{
				dif = compara;
				pos = i;
			}
		}
	}//Fim do for
	printf("%.2f\n", med);
	printf("O valor mais próximo da média é %.2f\n\n", vet[pos]);
}

int main ()
{
	float vet[tam];
	setlocale(LC_ALL, "");
	printf("Preenchimento do vetor:\n\n");
	Preencher(vet);
	BuscarMaisProx(vet);
	return 0;
}

