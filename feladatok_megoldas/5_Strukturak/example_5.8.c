/***********************************************************************************************************************************
* 5.8 Feladat                                                                                                                      *
*   Készítsen programot, amely háromszögek tárolására alkalmas. Egy háromszög három térbeli pontot tartalmaz (x, y és z komponens) *
*   Olvassa be billentyűzetről három háromszöget                                                                                   *
*   Írassa ki a beolvasott adatokat                                                                                                *
*   Keresse meg és írassa ki a legkisebb kerületű háromszög csúcsait                                                               *
***********************************************************************************************************************************/

#include <stdio.h>
#include <math.h> // a gyokvonas kell az oldalak hosszanak kiszamolasahoz

#define N 3

typedef struct coord
{
	float x, y, z;
} Coord;

typedef struct triangle
{
	Coord csucs[3]; // ezt tudjuk, hogy mindenkepp 3, felesleges define-t hasznalni
} Triangle;

int main()
{
	Triangle haromszogek[N];
	int i, j;
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. haromszog adatait.\n", i+1);
		for (j=0; j<3; j++)
		{
			printf("%d. csucs (x, y, z):\n", j+1);
			scanf("%f %f %f", &haromszogek[i].csucs[j].x, &haromszogek[i].csucs[j].y, &haromszogek[i].csucs[j].z);
		}
	}
	for (i=0; i<N; i++)
	{
		printf("A(z) %d. haromszog adatai:\n", i+1);
		for (j=0; j<3; j++)
		{
			printf("%d. csucs: x: %f, y: %f, z: %f.\n", j+1, haromszogek[i].csucs[j].x, haromszogek[i].csucs[j].y, haromszogek[i].csucs[j].z);
		}
	}
	float keruletek[N];
	for (i=0; i<N; i++)
	{
		keruletek[i]=0.0;
		float oldal=sqrt((haromszogek[i].csucs[0].x-haromszogek[i].csucs[1].x)*(haromszogek[i].csucs[0].x-haromszogek[i].csucs[1].x)+
										 (haromszogek[i].csucs[0].y-haromszogek[i].csucs[1].y)*(haromszogek[i].csucs[0].y-haromszogek[i].csucs[1].y)+
										 (haromszogek[i].csucs[0].z-haromszogek[i].csucs[1].z)*(haromszogek[i].csucs[0].z-haromszogek[i].csucs[1].z));
		keruletek[i]+=oldal;
		oldal=sqrt((haromszogek[i].csucs[1].x-haromszogek[i].csucs[2].x)*(haromszogek[i].csucs[1].x-haromszogek[i].csucs[2].x)+
							 (haromszogek[i].csucs[1].y-haromszogek[i].csucs[2].y)*(haromszogek[i].csucs[1].y-haromszogek[i].csucs[2].y)+
							 (haromszogek[i].csucs[1].z-haromszogek[i].csucs[2].z)*(haromszogek[i].csucs[1].z-haromszogek[i].csucs[2].z));
		keruletek[i]+=oldal;
		oldal=sqrt((haromszogek[i].csucs[2].x-haromszogek[i].csucs[0].x)*(haromszogek[i].csucs[2].x-haromszogek[i].csucs[0].x)+
							 (haromszogek[i].csucs[2].y-haromszogek[i].csucs[0].y)*(haromszogek[i].csucs[2].y-haromszogek[i].csucs[0].y)+
							 (haromszogek[i].csucs[2].z-haromszogek[i].csucs[0].z)*(haromszogek[i].csucs[2].z-haromszogek[i].csucs[0].z));
		keruletek[i]+=oldal;
	}
	int min_idx=0;
	for (i=1; i<N; i++)
	{
		if (keruletek[i]<keruletek[min_idx])
			min_idx=i;
	}
	printf("A legkisebb keruletu haromszog a %d.\n", min_idx+1);
	return 0;
}
