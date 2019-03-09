/***************************************************************************************************************************************
* 6.6 Feladat                                                                                                                          *
*   Írjon függvényt, amely két számot vár paraméterül és eredményül visszaadja a két szám maximumát                                    *
*   Írjon programot, amely beolvas egy hatelemű tömböt és az előzőleg megírt függvény segítségével megkeresi a tömb legnagyobb elemét. *
***************************************************************************************************************************************/

#include <stdio.h>

#define N 6

int max(int egyik, int masik)
{
	if (egyik>masik)
		return egyik;
	else
		return masik;
}

int main()
{
	int tomb[N];
	int i;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	int legnagyobb=tomb[0];
	for (i=1; i<N; i++)
	{
		legnagyobb=max(legnagyobb, tomb[i]);
	}
	printf("A tomb legnagyobb eleme: %d.\n", legnagyobb); // itt most szandekosan nem torodunk az index-szel
	return 0;
}
