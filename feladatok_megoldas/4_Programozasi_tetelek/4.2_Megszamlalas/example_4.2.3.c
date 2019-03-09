/**********************************************************************************************
* 4.2.3 Feladat                                                                               *
*   Olvasson be egy tízelemű tömböt                                                           *
*   Olvasson be egy négyelemű tömböt                                                          *
*   Írassa ki a négyelemű tömb minden értékéhez, hogy az hányszor szerepel a tízelemű tömbben *
**********************************************************************************************/

#include <stdio.h>

#define N 10
#define M 4

int main()
{
	int tomb1[N], tomb2[M];
	int i, j;
	printf("Kerem az elso tomb elemeit: \n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb1[i]);
	}
	printf("Kerem a masodik tomb elemeit: \n");
	for (j=0; j<M; j++)
	{
		scanf("%d", &tomb2[j]);
	}
	for (j=0; j<M; j++)
	{
		int darab=0;
		for (i=0; i<N; i++)
		{
			if (tomb1[i]==tomb2[j])
				darab++;
		}
		printf("A(z) %d ertek az elso tombben %d-szer szerepel.\n", tomb2[j], darab);
	}
	return 0;
}
