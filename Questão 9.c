#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    int numg, i, tent;
	setlocale(LC_ALL, "");
    srand( (unsigned)time(NULL) );
	numg = rand() % 101;
	printf("Tente acertar o número gerado entre 0 e 100\n\n");
	for (i = 0; ; i++)
	{
		printf("Informe um número: ");
		scanf("%d", &tent);
		if(tent == numg)
		{
			printf("Acertou!\n");
			printf("Número de tentativas: %d\n", i+1);
			break;
		}
		else if(tent < numg)
			printf("O número gerado é maior do que %d!\n", tent);
		else
			printf("O número gerado é menor do que %d!\n", tent);
		printf("\n");
	}
	return 0;
}