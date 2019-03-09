/***********************************************************************************
* 7.5.3 Feladat                                                                    *
*   Olvasson be két egész számot billentyűzetről                                   *
*   Foglaljon helyet egy mátrixnak, amely dimenziói az előzőleg beolvasott értékek *
*   Töltse fel a mátrixot billentyűzetről olvasott értékekkel                      *
*   Jelenítse meg a mátrix tartalmát                                               *
*   Szabadítsa fel a lefoglalt memóriaterületet                                    *
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sorok, oszlopok;
	int i, j;
	int **matrix;
	printf("Kerem a matrix mereteit (sor, oszlop):\n");
	scanf("%d %d", &sorok, &oszlopok);
	matrix=(int**)malloc(sizeof(int*)*sorok); // a soroknak foglalunk eloszor helyet, azon belul lesznek az oszlopok
	for (i=0; i<sorok; i++)
	{
		matrix[i]=(int*)malloc(sizeof(int)*oszlopok);
	}
	for (i=0; i<sorok; i++)
	{
		printf("Kerem a(z) %d indexu sor elemeit (%d darab):\n", i, oszlopok);
		for (j=0; j<oszlopok; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("A matrix:\n");
	for (i=0; i<sorok; i++)
	{
		for (j=0; j<oszlopok; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	for (i=0; i<sorok; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
