/************************************************************************************
* 5.5 Feladat                                                                       *
*   Készítsen programot, amely térbeli pontokat képes tárolni (x, y és z komponens) *
*   Olvassa be billentyűzetről tíz pont koordinátáját                               *
*   Írassa ki a beolvasott adatokat                                                 *
*   Írassa ki az origótól legtávolabb elhelyezkedő pontot                           *
************************************************************************************/

#include <stdio.h>

#define N 10

typedef struct coord
{
	float x, y, z; // terbeli pontoknal mar azert erdemes lebegopontos szamokkal dolgozni, de nem ezen van a hangsuly
} Coord;

int main()
{
	Coord koordinatak[N];
	int i;
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. pont adatait: x, y, z\n", i+1);
		scanf("%f %f %f", &koordinatak[i].x, &koordinatak[i].y, &koordinatak[i].z);
	}
	for (i=0; i<N; i++)
	{
		printf("A(z) %d. pont adatai: x: %f, y: %f, z: %f.\n", i+1, koordinatak[i].x, koordinatak[i].y, koordinatak[i].z);
	}
	int max_idx=0;
	for (i=1; i<N; i++)
	{
		if (koordinatak[i].x*koordinatak[i].x+koordinatak[i].y*koordinatak[i].y+koordinatak[i].z*koordinatak[i].z >
				koordinatak[max_idx].x*koordinatak[max_idx].x+koordinatak[max_idx].y*koordinatak[max_idx].y+koordinatak[max_idx].z*koordinatak[max_idx].z) // mivel csak a relacio iranya a fontos, eleg a tavolsag negyzetevel szamolni
			max_idx=i;
	}
	printf("Az origotol legtavolabbi pont: x: %f, y: %f, z: %f.\n", koordinatak[max_idx].x, koordinatak[max_idx].y, koordinatak[max_idx].z);
	return 0;
	
}
