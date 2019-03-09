/*****************************************************************
* 6.5 Feladat                                                    *
*   Írjon függvényt, amely egy tömb elemeit írja ki a képernyőre *
*   Készítsen egy tízelemű, koordinátákat (x, y) tároló tömböt   *
*   Olvasson be 10 koordinátát                                   *
*   Jelenítse meg a koordinátákat                                *
*   Rendezze a tömböt x komponens szerint növekvő sorrendbe      *
*   Jelenítse meg a tömböt                                       *
*   Rendezze a tömböt y komponens szerint növekvő sorrendbe      *
*   Jelenítse meg a tömböt                                       *
*****************************************************************/

#include <stdio.h>

#define N 10

typedef struct coord
{
	float x, y;
} Coord;

void kiir(Coord tomb[], int meret)
{
	int i;
	for (i=0; i<meret; i++)
	{
		printf("A(z) %d. pont adatai: x: %f, y: %f.\n", i+1, tomb[i].x, tomb[i].y);
	}
}

int main()
{
	Coord koordinatak[N];
	int i, j;
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. pont adatait: x, y\n", i+1);
		scanf("%f %f", &koordinatak[i].x, &koordinatak[i].y);
	}
	kiir(koordinatak, N);
	printf("\nRendezes x szerint.\n");
	Coord csere;
	int min_idx;
	for (i=0; i<N-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (koordinatak[j].x<koordinatak[min_idx].x)
				min_idx=j;
		}
		if (min_idx!=i)
		{
			csere=koordinatak[i];
			koordinatak[i]=koordinatak[min_idx];
			koordinatak[min_idx]=csere;
		}
	}
	kiir(koordinatak, N);
	printf("\nRendezes y szerint.\n");
	for (i=0; i<N-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (koordinatak[j].y<koordinatak[min_idx].y)
				min_idx=j;
		}
		if (min_idx!=i)
		{
			csere=koordinatak[i];
			koordinatak[i]=koordinatak[min_idx];
			koordinatak[min_idx]=csere;
		}
	}
	kiir(koordinatak, N);
	return 0;
}
