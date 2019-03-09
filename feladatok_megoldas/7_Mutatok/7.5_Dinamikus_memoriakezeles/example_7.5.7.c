/****************************************************************************************************************************************************************************************
* 7.5.7 Feladat                                                                                                                                                                         *
*   Készítsen egy koordinátát tároló struktúrát                                                                                                                                         *
*   Hozzon létre egy 5 elemű, koordináta pointereket tároló tömböt                                                                                                                      *
*   Menjen végig a tömb elemein, kérdezzen rá, hogy olvasson-e be koordinátát, és ha igen, foglaljon neki helyet és olvassa be az értékét. Ellenkező esetben a memóriacím értéke nulla. *
*   Jelenítse meg a tömb koordinátára mutató elemeit                                                                                                                                    *
*   Szabadítsa fel a lefoglalt memóriaterületet                                                                                                                                         *
****************************************************************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct coord
{
	float x, y, z;
} Coord;

int main()
{
	int i;
	Coord **mutato_tomb;
	int beolvas;
	mutato_tomb=(Coord**)malloc(sizeof(Coord*)*N);
	for (i=0; i<N; i++)
	{
		printf("Szeretne a(z) %d. indexre koordinatat olvasni? (1/0)\n", i);
		scanf("%d", &beolvas);
		if (beolvas==1)
		{
			mutato_tomb[i]=(Coord*)malloc(sizeof(Coord));
			printf("Kerem a harom erteket (x, y, z):\n");
			scanf("%f %f %f", &(mutato_tomb[i]->x), &(mutato_tomb[i]->y), &(mutato_tomb[i]->z));
		}
		else
		{
			mutato_tomb[i]=0;
		}
	}
	
	for (i=0; i<N; i++)
	{
		if (mutato_tomb[i]!=0)
		{
			printf("A koordinata a(z) %d. indexen: (%f, %f, %f).\n", i, mutato_tomb[i]->x, mutato_tomb[i]->y, mutato_tomb[i]->z);
		}
	}
	for (i=0; i<N; i++)
	{
		if (mutato_tomb[i]!=0)
		{
			free(mutato_tomb[i]);
		}
	}
	free(mutato_tomb);
	return 0;
}
