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
	printf("Tente acertar o n�mero gerado entre 0 e 100\n\n");
	for (i = 0; ; i++)
	{
		printf("Informe um n�mero: ");
		scanf("%d", &tent);
		if(tent == numg)
		{
			printf("Acertou!\n");
			printf("N�mero de tentativas: %d\n", i+1);
			break;
		}
		else if(tent < numg)
			printf("O n�mero gerado � maior do que %d!\n", tent);
		else
			printf("O n�mero gerado � menor do que %d!\n", tent);
		printf("\n");
	}
	return 0;
}