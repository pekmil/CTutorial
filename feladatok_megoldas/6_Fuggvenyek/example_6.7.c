/*****************************************************************************************************************************************
* 6.6 Feladat                                                                                                                            *
*   Írjon függvényt, amely két számot vár paraméterül és eredményül visszaadja a két szám maximumát                                      *
*   Írjon programot, amely beolvas egy hatelemű tömböt és az előzőleg megírt függvény segítségével megkeresi a tömb legnagyobb elemét.   *
*                                                                                                                                        *
* 6.7 Feladat                                                                                                                            *
*   Módosítsa az előző feladatot úgy, hogy a függvény egy tömböt és egy méretet várjon paraméterül, majd térjen vissza annak maximumával *
*****************************************************************************************************************************************/

#include <stdio.h>

#define N 6

int tomb_max(int tomb[], int meret)
{
	int legnagyobb=tomb[0];
	int i;
	for (i=1; i<meret; i++)
	{
		if (legnagyobb<tomb[i])
			legnagyobb=tomb[i];
	}
	return legnagyobb;
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
	printf("A tomb legnagyobb eleme: %d.\n", tomb_max(tomb, N));
	return 0;
}
