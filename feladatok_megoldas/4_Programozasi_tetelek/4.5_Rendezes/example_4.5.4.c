/********************************************************************************************
* 4.5.4 Feladat                                                                             *
*   Olvasson be egy tízelemű tömböt                                                         *
*   Egy ötelemű tömbben tárolja el a tízelemű tömb öt legkisebb elemét növekvő sorrendben   *
*   Egy ötelemű tömbben tárolja el a tízelemű tömb öt legnagyobb elemét csökkenő sorrendben *
*   Írassa ki a képernyőre a tömböket                                                       *
********************************************************************************************/

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
	int kicsi[N/2], nagy[(N+1)/2];
	for (i=0; i<N/2; i++)
	{
		kicsi[i]=tomb[i];
	}
	for (i=0; i<(N+1)/2; i++)
	{
		nagy[i]=tomb[N-i-1];
	}
	printf("A kisebb elemek:\n");
	for (i=0; i<N/2; i++)
	{
		printf("%d ", kicsi[i]);
	}
	printf("\nA nagyobb elemek:\n");
	for (i=0; i<(N+1)/2; i++)
	{
		printf("%d ", nagy[i]);
	}
	printf("\n");
	return 0;
}
