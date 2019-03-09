/****************************************************
* 7.5.5 Feladat                                     *
*   Készítsen egy koordinátát tároló struktúrát     *
*   Foglaljon memóriát egy koordináta struktúrának  *
*   Olvasson be és tároljon el egy koordinátát      *
*   Írassa ki a képernyőre a beolvasott koordinátát *
*   Szabadítsa fel a lefoglalt memóriaterületet     *
****************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct coord
{
	float x, y, z;
} Coord;

int main()
{
	Coord *mutato=(Coord*)malloc(sizeof(Coord));
	printf("Kerem a koordinatat (x, y, z):\n");
	scanf("%f %f %f", &(mutato->x), &(mutato->y), &(mutato->z));
	printf("A megadott koordinata: (%f, %f, %f).\n", mutato->x, mutato->y, mutato->z);
	free(mutato);
	return 0;
}
