/***********************************************************************************************************************
* 7.3.3 Feladat                                                                                                        *
*   Készítsen programot, amely háromszögek tárolására alkalmas. Egy háromszög három térbeli pont mutatóját tartalmazza *
*   Hozzon létre három koordinátát és egy háromszöget                                                                  *
*   A háromszög struktúrán keresztül töltse fel a koordinátákat a billentyűzetről olvasott adatokkal                   *
*   Írassa ki a háromszög adatait                                                                                      *
***********************************************************************************************************************/

#include <stdio.h>

typedef struct coord
{
	float x, y, z;
} Coord;

typedef struct triangle
{
	Coord *csucsok[3];
} Triangle;

int main()
{
	Coord a, b, c;
	Triangle haromszog;
	haromszog.csucsok[0]=&a;
	haromszog.csucsok[1]=&b;
	haromszog.csucsok[2]=&c;
	int i;
	for (i=0; i<3; i++)
	{
		printf("Kerem a(z) %d. csucs koordinatait:\n", i+1);
		scanf("%f %f %f", &haromszog.csucsok[i]->x, &haromszog.csucsok[i]->y, &haromszog.csucsok[i]->z);
	}
	printf("A megadott haromszog:\n");
	for (i=0; i<3; i++)
	{
		printf("(%f, %f, %f)\n", haromszog.csucsok[i]->x, haromszog.csucsok[i]->y, haromszog.csucsok[i]->z);
	}
	return 0;
}
