/******************************************************************************************************************************************************
* 6.4 Feladat                                                                                                                                         *
*   Írjon függvényt, amely két számot vár paraméterül és eredményül 1-et ad vissza, ha az első nagyobb, vagy egyenlő, mint a második, máskülönben 0-t *
*   Olvasson be egy tízelemű tömböt, majd rendezze az elemeit csökkenő számsorrendbe. A rendezéshez használja fel az előzőleg megírt függvényt.       *
******************************************************************************************************************************************************/

#include <stdio.h>

#define N 10

int nagyobb(int egyik, int masik)
{
	if (egyik>=masik)
		return 1;
	else
		return 0;
}

int main()
{
	int tomb[N];
	int i, j;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	int max_idx;
	int csere;
	for (i=0; i<N-1; i++)
	{
		max_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (nagyobb(tomb[j], tomb[max_idx]))
				max_idx=j;
		}
		if (max_idx!=i)
		{
			csere=tomb[i];
			tomb[i]=tomb[max_idx];
			tomb[max_idx]=csere;
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
