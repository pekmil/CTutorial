/****************************************************************************************************************************************************************
* 4.9 Feladat(!)                                                                                                                                                *
*   Olvasson be egy tízelemű tömböt                                                                                                                             *
*   Rendezze a tömböt a következőképpen: Első helyen szerepeljen a legnagyobb érték, majd a legkisebb, a második legnagyobb, második legkisebb és így tovább... *
*   Jelenítse meg a tömböt                                                                                                                                      *
****************************************************************************************************************************************************************/

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
	int minkeres=0; // 1 ha minimumot kell keresni, 0 ha maximumot
	int idx;
	int csere;
	for (i=0; i<N-1; i++)
	{
		idx=i;
		for (j=i+1; j<N; j++)
		{
			if ((minkeres==1 && tomb[j]<tomb[idx]) || (minkeres==0 && tomb[j]>tomb[idx])) // minimum keresesenel, a kisebb szam kell, maximumnal a nagyobb
				idx=j;
		}
		if (idx!=i)
		{
			csere=tomb[i];
			tomb[i]=tomb[idx];
			tomb[idx]=csere;
		}
		minkeres=1-minkeres; // valtas a minimum es maximum keresese kozott
	}
	printf("A rendezett tomb:\n");
	for (i=0; i<N; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	return 0;
}
