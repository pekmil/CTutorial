/*******************************************************************************************************************************
* 4.4.5 Feladat                                                                                                                *
*   Olvasson be egy tízelemű tömböt                                                                                            *
*   Keresse meg és írassa ki a képernyőre annak a két szomszédos elemnek a pozícióját és értékét, amelyek összege a legnagyobb *
*******************************************************************************************************************************/

#include <stdio.h>

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
	int max_idx=0;
	for (i=1; i<N-1; i++)
	{
		if (tomb[i]+tomb[i+1]>tomb[max_idx]+tomb[max_idx+1])
			max_idx=i;
	}
	printf("A legnagyobb osszegu szomszedok: %d es %d, (indexek: %d es %d).\n", tomb[max_idx], tomb[max_idx+1], max_idx, max_idx+1);
	return 0;
}
