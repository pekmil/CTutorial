/******************************************************************
* 7.3.2 Feladat                                                   *
*   Készítsen egy struktúrát, amely koordinátákat tárol (x, y, z) *
*   Hozzon létre egy tízelemű tömböt, amely koordinátákat tárol   *
*   Egy mutató segítségével töltse fel a tömböt értékekkel        *
*   A mutatón keresztül jelenítse meg a tömb elemeit              *
******************************************************************/

#include <stdio.h>

#define N 10

typedef struct coord
{
	float x, y, z;
} Coord;

int main()
{
	Coord tomb[N];
	int i;
	Coord *mutato;
	Coord *ptomb=tomb; // csak hogy tobb modon is elerhessuk
	for (i=0, mutato=&tomb[i]; i<N; i++, mutato++)
	{
		printf("Kerem a(z) %d. pont adatait:\n", i+1);
		//scanf("%f %f %f", &(ptomb+i)->x, &(ptomb+i)->y, &(ptomb+i)->z);
		scanf("%f %f %f", &mutato->x, &mutato->y, &mutato->z);
	}
	printf("A tomb elemei:\n");
	for (i=0; i<N; i++)
	{
		printf("%f %f %f\n", (ptomb+i)->x, (ptomb+i)->y, (ptomb+i)->z);
	}
	return 0;
}
