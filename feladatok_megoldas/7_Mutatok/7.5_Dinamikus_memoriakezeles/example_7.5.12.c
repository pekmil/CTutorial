/*********************************************************************************************************************
* 7.5.11 Feladat                                                                                                     *
*   Írjon függvényt, amely vár paraméterben három számot és visszatér egy általa lefoglalt koordináta memóriacímével *
*   Írjon egy függvényt, amely paraméterül egy koordináta memóriacímet kap és felszabadítja a memóriaterületet       *
*   Olvasson be egy számot, majd ennek megfelelő mennyiségű koordinátát. Használja az előzőleg megírt függvényt      *
*   Jelenítse meg a koordinátákat                                                                                    *
*   Szabadítsa fel a lefoglalt memóriaterületeket a megírt függvény segítségével                                     *
*                                                                                                                    *
* 7.5.12 Feladat                                                                                                     *
*   Módosítsa az előző feladatot úgy, hogy háromszögek tárolására legyen alkalmas:                                   *
*     A függvények egy háromszög struktúrát kezelnek, amely három koordináta memóriacímét tárolja                    *
*     A háromszög csúcsainak koordinátáit a függvényen belül olvassa be                                              *
*     A koordináták beolvasásakor jelenítse meg, hogy az hányadik háromszög (sorszám) mely csúcsa (A, B, vagy C)     *
*   Ügyeljen a megfelelő memóriakezelésre                                                                            *
*********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct coord
{
	float x, y, z;
} Coord;

typedef struct triangle
{
	Coord *csucsok[3];
} Triangle;

Triangle* lefoglalTriangle()
{
	Triangle *atmeneti=(Triangle*)malloc(sizeof(Triangle));
	int i;
	for (i=0; i<3; i++)
	{
		atmeneti->csucsok[i]=(Coord*)malloc(sizeof(Coord));
		printf("Kerem a(z) %c csucs adatait:\n", 'A'+i);
		scanf("%f %f %f", &(atmeneti->csucsok[i]->x), &(atmeneti->csucsok[i]->y), &(atmeneti->csucsok[i]->z));
	}
	return atmeneti;
}

void felszabaditTriangle(Triangle **mutato) // ha ilyet irunk, celszeru ugy csinalni, hogy a megkapott cimet allitsa is be 0-ra
{
	int i;
	for (i=0; i<3; i++)
		free((*mutato)->csucsok[i]);
	free(*mutato);
	*mutato=0;
}

int main()
{
	int darab, i, j;
	printf("Kerem a darabszamot:\n");
	scanf("%d", &darab);
	Triangle** tomb=(Triangle**)malloc(sizeof(Triangle*)*darab);
	for (i=0; i<darab; i++)
	{
		printf("Kerem a(z) %d indexu haromszog csucsait:\n", i);
		tomb[i]=lefoglalTriangle();
	}
	printf("A haromszogek:\n");
	for (i=0; i<darab; i++)
	{
		for (j=0; j<3; j++)
		{
			printf("(%f, %f, %f)", tomb[i]->csucsok[j]->x, tomb[i]->csucsok[j]->y, tomb[i]->csucsok[j]->z);
			if (j<2)
				printf(";");
			else
				printf("\n");
		}
	}
	for (i=0; i<darab; i++)
	{
		felszabaditTriangle(&tomb[i]);
	}
	free(tomb);
	return 0;
}
