/************************************************************************************************************************************************
* 5.9 Feladat                                                                                                                                   *
*   Készítsen programot, amely háromszögeket tárol a következő formában:                                                                        *
*     Tároljunk 10 koordinátát (struktúrák)                                                                                                     *
*     Tároljunk 5 háromszöge (struktúrák)                                                                                                       *
*     A háromszöget három index segítségével határozunk meg (a 10 elemű koordináta tömb indexei)                                                *
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
	int indexek[3];
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
			scanf("%d", &haromszogek[j].indexek[k]); // a hibakezelessel most nem foglalkozunk, feltetelezzuk, hogy minden index valid
		}
	}
	for (j=0; j<M; j++)
	{
		printf("A(z) %d. haromszog:\n", j+1);
		for (k=0; k<3; k++)
		{
			printf("(%f,%f,%f)", koordinatak[haromszogek[j].indexek[k]].x, koordinatak[haromszogek[j].indexek[k]].y, koordinatak[haromszogek[j].indexek[k]].z);
			if (k<2)
				printf(";");
			else
				printf("\n");
		}
	}
	return 0;
}
