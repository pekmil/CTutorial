/***********************************************************************************
* 7.5.4 Feladat                                                                    *
*   Olvasson be két egész számot billentyűzetről                                   *
*   Foglaljon helyet egy mátrixnak, amely dimenziói az előzőleg beolvasott értékek *
*   Töltse fel a mátrixot billentyűzetről olvasott értékekkel                      *
*   Jelenítse meg a mátrix tartalmát                                               *
*   Keresse meg és írja ki a mátrix legnagyobb és legkisebb elemét                 *
*   Szabadítsa fel a lefoglalt memóriaterületet                                    *
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x, y, i, j;
	printf("Kerem a ket szamot (magassag, szelesseg):\n");
	scanf("%d %d", &x, &y);
	int **matrix=(int**)malloc(sizeof(int*)*x);
	for (i=0; i<x; i++)
	{
		matrix[i]=(int*)malloc(sizeof(int)*y);
		for (j=0; j<y; j++)
		{
			matrix[i][j]=0;
		}
	}
	
	for (i=0; i<x; i++)
	{
		for (j=0; j<y; j++)
		{
			printf("Kerem az %d. sor %d. erteket:\n", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	
	printf("A matrix:\n");
	for (i=0; i<x; i++)
	{
		for (j=0; j<y; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	int min_x=0, min_y=0, max_x=0, max_y=0; // a kettot egybe is meg lehet keresni
	for (i=0; i<x; i++)
	{
		for (j=0; j<y; j++)
		{
			if (matrix[min_x][min_y]>matrix[i][j])
			{
				min_x=i;
				min_y=j;
			}
			if (matrix[max_x][max_y]<matrix[i][j])
			{
				max_x=i;
				max_y=j;
			}
		}
	}
	printf("A legnagyobb elem: %d. sor, %d. oszlop, ertek: %d.\n", max_x, max_y, matrix[max_x][max_y]);
	printf("A legkisebb elem: %d. sor, %d. oszlop, ertek: %d.\n", min_x, min_y, matrix[min_x][min_y]);
	
	for (i=0; i<x; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
