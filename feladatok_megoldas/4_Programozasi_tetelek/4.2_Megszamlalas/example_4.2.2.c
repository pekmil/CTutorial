/**********************************************************************************************
* 4.2.2 Feladat                                                                               *
*   Hozzon létre egy hatelemű tömböt                                                          *
*   Töltse fel a tömböt billentyűzetről beolvasott értékekkel                                 *
*   Olvasson be egy számot billentyűzetről és tárolja el                                      *
*   Írassa ki, hogy hány, az utoljára beolvasott számnál nem nagyobb érték szerepel a tömbben *
**********************************************************************************************/

#include <stdio.h>

#define N 6

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
	printf("Kerem a szamot: ");
	scanf("%d", &ertek);
	int darab=0;
	for (i=0; i<N; i++)
	{
		if (tomb[i]<=ertek)
			darab++;
	}
	printf("A tombben %d, a(z) %d-nel nem nagyobb ertek szerepel.\n", darab, ertek);
	return 0;
}
