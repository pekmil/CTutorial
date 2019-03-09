/********************************************************************************************************************
* 4.5.5 Feladat(!)                                                                                                  *
*   Olvass be egy tízelemű tömböt                                                                                   *
*   Tárold el maxden elemhez a prímtényezős felbontásában szereplő legkisebb prímszámot                             * 
*   Rendezd a beolvasott tömböt a prímtényezős felbontásban szereplő legkisebb prímszám szerinti csökkenő sorrendbe *
********************************************************************************************************************/

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
	int primek[N];
	for (i=0; i<N; i++)
	{
		if (tomb[i]<=1)
		{
			primek[i]=tomb[i];
		}
		else
		{
			int oszto=2;
			while (tomb[i]%oszto!=0)
				oszto++;
			primek[i]=oszto;
		}
	}
	printf("A legkisebb primteyezok:\n");
	for (i=0; i<N; i++)
	{
		printf("%d ", primek[i]);
	}
	printf("\n");
	int max_idx;
	int csere;
	for (i=0; i<N-1; i++)
	{
		max_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (primek[j]>primek[max_idx])
				max_idx=j;
		}
		if (max_idx!=i)
		{
			csere=tomb[i];
			tomb[i]=tomb[max_idx];
			tomb[max_idx]=csere;
			csere=primek[i];
			primek[i]=primek[max_idx];
			primek[max_idx]=csere;
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
