/**********************************************************************************
* 4.3.3 Feladat                                                                   *
*   Hozzon létre egy tízelemű tömböt és töltse fel értékekkel                     *
*   Írassa ki a képernyőre, hogy szerepel-e a tömbben bármely elemének a négyzete *
**********************************************************************************/

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
	for (i=0; i<N; i++)
	{
		j=0;
		while (j<N && tomb[j]!=tomb[i]*tomb[i])
		{
			j++;
		}
		if (j!=N)
			printf("A(z) %d szam negyzete megtalalhato a tombben, a(z) %d. indexen.\n", tomb[i], j);
	}
	return 0;
}
