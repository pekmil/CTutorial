/*********************************************************************************************************************
* 4.4.4 Feladat                                                                                                      *
*   Olvasson be egy tízelemű tömböt                                                                                  *
*   Olvasson be egy számot                                                                                           *
*   Keresse meg a tömbben a beolvasott számtól legtávolabbi elemet és írassa ki a képernyőre annak helyét és értékét *
*********************************************************************************************************************/

#include <stdio.h>
#include <math.h> // hasznalhatjuk az itt levo abszolutertek szamolast

#define N 10

int main()
{
	int tomb[N];
	int i;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	int ertek;
	printf("Kerem a szamot: \n");
	scanf("%d", &ertek);
	int max_idx=0;
	for (i=1; i<N; i++)
	{
		if (fabs(tomb[i]-ertek)>fabs(tomb[max_idx]-ertek))
			max_idx=i;
	}
	printf("A legtavolabbi ertek: %d (index: %d).\n", tomb[max_idx], max_idx);
	return 0;
}
