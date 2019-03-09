/***********************************************************************************************************************
* 4.2.4 Feladat                                                                                                        *
*   Olvasson be egy hételemű tömböt                                                                                    *
*   Írassa ki a képernyőre minden, a tömbben szereplő szomszédos szám összegére, hogy az hányszor fordul elő a tömbben *
***********************************************************************************************************************/

#include <stdio.h>

#define N 7

int main()
{
	int tomb[N];
	int i, j;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	for (i=0; i<N-1; i++)
	{
		int darab=0;
		for (j=0; j<N; j++)
		{
			if (tomb[j]==tomb[i]+tomb[i+1])
				darab++;
		}
		printf("A(z) %d, es a(z) %d osszege (%d) %d-szer szerepel a tombben.\n", tomb[i], tomb[i+1], tomb[i]+tomb[i+1], darab);
	}
	return 0;
}
