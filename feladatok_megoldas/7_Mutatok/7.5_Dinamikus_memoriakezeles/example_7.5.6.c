/*****************************************************************************************************
* 7.5.6 Feladat                                                                                      *
*   Készítsen egy koordinátát tároló struktúrát                                                      *
*   Írjon függvényt, amely koordinátát olvas be billentyűzetről                                      *
*   Olvasson be egy egész számot és foglaljon memóriát ennek megfelelő mennyiségű koordináta számára *
*   A függvény segítségével olvasson be ennyi koordinátát                                            *
*   Jelenítse meg a tárolt koordinátákat                                                             *
*   Szabadítsa fel a lefoglalt memóriaterületet                                                      *
*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct coord
{
	float x, y, z;
} Coord;

void beolvas(Coord * koordinata)
{
	printf("Kerem a koordinata erteket:\n");
	scanf("%f %f %f", &(koordinata->x), &(koordinata->y), &(koordinata->z));
}

int main()
{
	int meret;
	int i;
	Coord *tomb;
	printf("Kerem a meretet:\n");
	scanf("%d", &meret);
	tomb=(Coord*)malloc(sizeof(Coord)*meret);
	for (i=0; i<meret; i++)
		beolvas(&tomb[i]);
	printf("A beolvasott koordinatak:\n");
	for (i=0; i<meret; i++)
		printf("(%f, %f, %f)\n", tomb[i].x, tomb[i].y, tomb[i].z);
	free(tomb);
	return 0;
}
