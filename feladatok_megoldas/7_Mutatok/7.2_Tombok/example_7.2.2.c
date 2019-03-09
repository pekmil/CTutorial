/****************************************************************************************************************************
* 7.2.2 Feladat                                                                                                             *
*   Olvasson be egy tízelemű tömböt, amely egész számokat tárol és töltse fel értékekkel                                    *
*   Hozzon létre egy 10 elemű tömböt, amely mutatókat tárol az előző tömb megfelelő elemeire                                *
*   Rendezze a mutató tömböt a mutatott értékek szerinti növekvő sorrendbe                                                  *
*   Jelenítse meg a két tömb értékeit (a mutató tömb kiíratásakor jelenítse meg a címeket és a mutatott értékeket egyaránt) *
****************************************************************************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb[N], *ptomb[N];
	int i, j;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	for (i=0; i<N; i++)
	{
		ptomb[i]=&tomb[i];
	}
	int min_idx;
	int *csere;
	for (i=0; i<N-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (*ptomb[j]<*ptomb[min_idx])
				min_idx=j;
		}
		if (min_idx!=i)
		{
			csere=ptomb[i];
			ptomb[i]=ptomb[min_idx];
			ptomb[min_idx]=csere;
		}
	}
	printf("Az eredeti tomb:\n");
	for (i=0; i<N; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\nA mutato tomb ertekei:\n");
	for (i=0; i<N; i++)
	{
		printf("A tarolt cim: %p, a mutatott ertek: %d.\n", ptomb[i], *ptomb[i]);
	}
	return 0;
}
