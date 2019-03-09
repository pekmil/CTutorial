/****************************************************************************************************************************
* 7.2.3 Feladat(!)                                                                                                          *
*   Olvasson be egy tízelemű tömböt, amely egész számokat tárol és töltse fel értékekkel                                    *
*   Hozzon létre egy 10 elemű tömböt, amely mutatókat tárol az előző tömb megfelelő elemeire                                *
*   Rendezze az első tömböt növekvő sorrendbe úgy, hogy a mutató tömb elemei továbbra is ugyanazon értékre mutassanak       *
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
	int csere, scsere;
	int seged[N]; // kell egy segedtomb, ami megmondja, hogy melyik helyre honnan kerult oda az ertek
	for (i=0; i<N; i++)
	{
		seged[i]=i;
	}
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
			scsere=seged[i];
			seged[i]=seged[min_idx];
			seged[min_idx]=scsere;
		}
	}
	for (i=0; i<N; i++)
	{
		ptomb[seged[i]]=&tomb[i];
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
