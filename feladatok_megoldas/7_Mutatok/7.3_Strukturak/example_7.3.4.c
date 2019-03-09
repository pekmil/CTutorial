/************************************************************************************************************************************************
* 7.3.4 Feladat                                                                                                                                 *
*   Készítsen programot, amely háromszögeket tárol a következő formában:                                                                        *
*     Tároljunk 10 koordinátát (struktúrák)                                                                                                     *
*     Tároljunk 5 háromszöget (struktúrák)                                                                                                      *
*     A háromszöget három mutató segítségével határozunk meg (a 10 elemű koordináta tömb elemeire mutatnak)                                     *
*   Olvassa be billentyűzetről tíz koordinátát                                                                                                  *
*   Olvassa be billentyűzetről a háromszögek indexeit. Minden háromszög beolvasása előtt jelenítse meg a tíz koordinátát azok indexeivel együtt *
*   Jelenítse meg a beolvasott adatokat                                                                                                         *
************************************************************************************************************************************************/

#include <stdio.h>

#define N 10
#define M 5

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
	Coord koordinatak[N];
	Triangle haromszogek[M];
	int i, j, k;
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. koordinatat (x, y, z): \n", i+1);
		scanf("%f %f %f", &koordinatak[i].x, &koordinatak[i].y, &koordinatak[i].z);
	}
	int index;
	for (j=0; j<M; j++)
	{
		printf("A koordinatak (index, x, y, z): \n");
		for (i=0; i<N; i++)
		{
			printf("%d: (%f, %f, %f)\n", i, koordinatak[i].x, koordinatak[i].y, koordinatak[i].z);
		}
		printf("Kerem a harom indexet a(z) %d. haromszoghoz:\n", j+1);
		for (k=0; k<3; k++)
		{
			scanf("%d", &index); // a hibakezelessel most nem foglalkozunk, feltetelezzuk, hogy minden index valid
			haromszogek[j].csucsok[k]=&koordinatak[index];
		}
	}
	for (j=0; j<M; j++)
	{
		printf("A(z) %d. haromszog:\n", j+1);
		for (k=0; k<3; k++)
		{
			printf("(%f,%f,%f)", haromszogek[j].csucsok[k]->x, haromszogek[j].csucsok[k]->y, haromszogek[j].csucsok[k]->z);
			if (k<2)
				printf(";");
			else
				printf("\n");
		}
	}
	return 0;
}
