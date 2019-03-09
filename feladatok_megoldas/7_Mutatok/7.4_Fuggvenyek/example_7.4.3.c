/**********************************************************************************************************************
* 7.4.3 Feladat                                                                                                       *
*   Készítsen egy koordináta struktúrát                                                                               *
*   Készítsen egy háromszög struktúrát, amely három koordinátát tárol                                                 *
*   Írjon függvényt, amely egy háromszög struktúra címét kapja meg és felölti azt billentyűzetről olvasott értékekkel *
*   Írjon függvényt, amely egy háromszög struktúra címét kapja és megjeleníti azt a képernyőn                         *
*   Olvasson be egy ötelemű tömbbe háromszögeket az előbb megírt függvény segítségével                                *
*   Írassa ki a tömb elemeit                                                                                          *
**********************************************************************************************************************/

#include <stdio.h>

#define N 5

typedef struct coord
{
	float x, y, z;
} Coord;

typedef struct triangle
{
	Coord csucsok[3];
} Triangle;

void beolvas(Triangle *haromszog)
{
	printf("Kerem a haromszog adatait:\n");
	int i;
	for (i=0; i<3; i++)
	{
		printf("A(z) %d. csucs (x, y, z):\n", i+1);
		scanf("%f %f %f", &(haromszog->csucsok[i].x), &(haromszog->csucsok[i].y), &(haromszog->csucsok[i].z));
	}
}

void kiir(Triangle *haromszog)
{
	printf("A haromszog adatai:\n");
	int i;
	for (i=0; i<3; i++)
	{
		printf("(%f,%f,%f)", haromszog->csucsok[i].x, haromszog->csucsok[i].y, haromszog->csucsok[i].z);
		if (i<2)
			printf(";");
		else
			printf("\n");
	}
}

int main()
{
	Triangle haromszogek[N];
	int i;
	for (i=0; i<N; i++)
	{
		beolvas(&haromszogek[i]);
	}
	for (i=0; i<N; i++)
	{
		kiir(&haromszogek[i]);
	}
	return 0;
}
