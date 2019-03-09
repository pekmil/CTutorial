/************************************************************************************************
* 4.2.1 Feladat                                                                                 *
*   Hozzon létre egy hatelemű tömböt                                                            *
*   Töltse fel a tömböt billentyűzetről beolvasott értékekkel                                   *
*   Olvasson be egy számot, majd számolja össze, hogy az adott szám hányszor szerepel a tömbben *
*   Írja ki az eredményt                                                                        *
************************************************************************************************/

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
		if (tomb[i]==ertek)
			darab++;
	}
	printf("Az ertek a tombben %d-szer szerepel.\n", darab);
	return 0;
}
