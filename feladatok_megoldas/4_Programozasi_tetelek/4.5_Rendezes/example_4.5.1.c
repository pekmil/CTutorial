/**************************************************************
* 4.5.1 Feladat                                               *
*   Hozzon létre egy tízelemű tömböt és töltse fel értékekkel *
*   Rendezze a tömb elemeit növekvő sorrendbe                 *
*   Írassa ki a tömb elemeit                                  *
**************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb[N];
	int i, j;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	int min_idx;
	int csere;
	for (i=0; i<N-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (tomb[j]<tomb[min_idx])
				min_idx=j;
		}
		if (min_idx!=i)
		{
			csere=tomb[i];
			tomb[i]=tomb[min_idx];
			tomb[min_idx]=csere;
		}
	}
	printf("A rendezett tomb:\n");
	for (i=0; i<N; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	return 0;
}
