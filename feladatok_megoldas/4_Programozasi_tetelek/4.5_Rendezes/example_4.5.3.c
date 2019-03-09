/********************************************************************************************
* 4.5.3 Feladat                                                                             *
*   Olvasson be egy tízelemű tömböt                                                         *
*   Olvasson be egy számot                                                                  *
*   Rendezze a tömb elemeit a beolvasott számtól való távolságuk szerinti növekvő sorrendbe *
*   Írassa ki a tömb elemeit                                                                *
********************************************************************************************/

#include <stdio.h>
#include <math.h> // az abszolutertek szamolasahoz

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
	int ertek;
	printf("Kerem a referencia erteket:\n");
	scanf("%d", &ertek);
	int min_idx;
	int csere;
	for (i=0; i<N-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (fabs(tomb[j]-ertek)<fabs(tomb[min_idx]-ertek))
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
