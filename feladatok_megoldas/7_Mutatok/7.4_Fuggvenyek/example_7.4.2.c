/***********************************************************************************************************************
* 7.4.2 Feladat                                                                                                        *
*   Készítsen egy koordináta struktúrát                                                                                *
*   Írjon függvényt, amely egy koordináta struktúra címét kapja meg és felölti azt billentyűzetről olvasott értékekkel *
*   Írjon függvényt, amely egy koordináta struktúra címét kapja és megjeleníti azt a képernyőn                         *
*   Olvasson be egy tízelemű tömbbe koordinátákat az előbb megírt függvény segítségével                                *
*   Írassa ki a tömb elemeit                                                                                           *
***********************************************************************************************************************/

#include <stdio.h>

#define N 10

typedef struct coord
{
	float x, y, z;
} Coord;

void beolvas(Coord *pont)
{
	printf("Kerem a pont adatait (x, y, z):\n");
	scanf("%f %f %f", &(pont->x), &(pont->y), &(pont->z));
}

void kiir(Coord *pont)
{
	printf("A pont adatai: (%f, %f, %f).\n", pont->x, pont->y, pont->z);
}

int main()
{
	Coord tomb[N];
	int i;
	for (i=0; i<N; i++)
	{
		beolvas(&tomb[i]);
	}
	for (i=0; i<N; i++)
	{
		kiir(&tomb[i]);
	}
	return 0;
}
