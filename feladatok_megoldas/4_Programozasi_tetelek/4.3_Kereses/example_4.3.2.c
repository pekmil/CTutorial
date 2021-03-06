/****************************************************************************
* 4.3.2 Feladat                                                             *
*   Hozzon létre egy tízelemű tömböt és töltse fel értékekkel               *
*   Olvasson be egy számot és tárolja el                                    *
*   Írassa ki, hogy a tömb elemei közt szerepel-e a beolvasott szám         *
*   Amennyiben szerepel, írja ki az utolsó előfordulásának helyét (indexét) *
****************************************************************************/

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
	int ertek;
	printf("Keres a keresett szamot:\n");
	scanf("%d", &ertek);
	i=N-1;
	while (i>=0 && tomb[i]!=ertek)
	{
		i--;
	}
	if (i==-1)
		printf("A keresett ertek nem talalhato meg a tombben.\n");
	else
		printf("A keresett ertek a(z) %d. indexen talalhato.\n", i);
	return 0;
}
