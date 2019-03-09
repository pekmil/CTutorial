/************************************************************************************
* 5.6 Feladat                                                                       *
*   Készítsen programot, amely térbeli pontokat képes tárolni (x, y és z komponens) *
*   Olvassa be billentyűzetről tíz pont koordinátáját                               *
*   Írassa ki a beolvasott adatokat                                                 *
*   Keresse meg és írassa ki a két, egymástól legtávolabb elhelyezkedő pontot       *
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
	int i, j;
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. pont adatait: x, y, z\n", i+1);
		scanf("%f %f %f", &koordinatak[i].x, &koordinatak[i].y, &koordinatak[i].z);
	}
	for (i=0; i<N; i++)
	{
		printf("A(z) %d. pont adatai: x: %f, y: %f, z: %f.\n", i+1, koordinatak[i].x, koordinatak[i].y, koordinatak[i].z);
	}
	int max_idx1=0, max_idx2=1; // most ket index kell, mivel egy pont part keresunk
	float max_tav=(koordinatak[max_idx1].x-koordinatak[max_idx2].x)*(koordinatak[max_idx1].x-koordinatak[max_idx2].x)+
								(koordinatak[max_idx1].y-koordinatak[max_idx2].y)*(koordinatak[max_idx1].y-koordinatak[max_idx2].y)+
								(koordinatak[max_idx1].z-koordinatak[max_idx2].z)*(koordinatak[max_idx1].z-koordinatak[max_idx2].z); // tul atlathatatlan lenne a feltetel, azert ezeket elore kiszamoljuk (termeszetesen itt is a tavolsag negyzetevel szamolunk)
	for (i=0; i<N-1; i++)
	{
		for (j=i+1; j<N; j++) // ennek megfeleloen a pont parokon kell vegigmenni
		{
			float uj_tav=(koordinatak[i].x-koordinatak[j].x)*(koordinatak[i].x-koordinatak[j].x)+
									 (koordinatak[i].y-koordinatak[j].y)*(koordinatak[i].y-koordinatak[j].y)+
									 (koordinatak[i].z-koordinatak[j].z)*(koordinatak[i].z-koordinatak[j].z);
			if (uj_tav>max_tav)
			{
				max_tav=uj_tav;
				max_idx1=i;
				max_idx2=j;
			}
		}
	}
	printf("Az ket legtavolabbi pont: x: %f, y: %f, z: %f es x: %f, y: %f, z: %f.\n", koordinatak[max_idx1].x, koordinatak[max_idx1].y, koordinatak[max_idx1].z, koordinatak[max_idx2].x, koordinatak[max_idx2].y, koordinatak[max_idx2].z);
	return 0;
	
}
