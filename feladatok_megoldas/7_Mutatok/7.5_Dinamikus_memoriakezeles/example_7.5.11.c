/*********************************************************************************************************************
* 7.5.11 Feladat                                                                                                     *
*   Írjon függvényt, amely vár paraméterben három számot és visszatér egy általa lefoglalt koordináta memóriacímével *
*   Írjon egy függvényt, amely paraméterül egy koordináta memóriacímet kap és felszabadítja a memóriaterületet       *
*   Olvasson be egy számot, majd ennek megfelelő mennyiségű koordinátát. Használja az előzőleg megírt függvényt      *
*   Jelenítse meg a koordinátákat                                                                                    *
*   Szabadítsa fel a lefoglalt memóriaterületeket a megírt függvény segítségével                                     *
*********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct coord
{
	float x, y, z;
} Coord;

Coord* lefoglalCoord(float x, float y, float z)
{
	Coord *atmeneti=(Coord*)malloc(sizeof(Coord));
	atmeneti->x=x;
	atmeneti->y=y;
	atmeneti->z=z;
	return atmeneti;
}

void felszabaditCoord(Coord **mutato) // ha ilyet irunk, celszeru ugy csinalni, hogy a megkapott cimet allitsa is be 0-ra
{
	free(*mutato);
	*mutato=0;
}

int main()
{
	int darab, i;
	printf("Kerem a darabszamot:\n");
	scanf("%d", &darab);
	Coord** tomb=(Coord**)malloc(sizeof(Coord*)*darab);
	float x, y, z;
	for (i=0; i<darab; i++)
	{
		printf("Kerem a kovetkezo koordinata adatait (x, y, z):\n");
		scanf("%f %f %f", &x, &y, &z);
		tomb[i]=lefoglalCoord(x, y, z);
	}
	printf("A korodinatak:\n");
	for (i=0; i<darab; i++)
	{
		printf("(%f, %f, %f)\n", tomb[i]->x, tomb[i]->y, tomb[i]->z);
	}
	for (i=0; i<darab; i++)
	{
		felszabaditCoord(&tomb[i]);
	}
	free(tomb);
	return 0;
}
