/**************************************************************************************************************************
* 7.4.1 Feladat                                                                                                           *
*   Írjon függvényt, amely két memóriacímet kap paraméterül és megcseréli az értékeiket, amennyiben az első számé nagyobb *
*   Olvasson be egy tízelemű tömböt                                                                                       *
*   Rendezze a tömböt növekvő sorrendbe az előzőleg megírt függvény segítségével                                          *
*   Jelenítse meg a tömböt                                                                                                *
**************************************************************************************************************************/

#include <stdio.h>

#define N 10

void csereHaNagyobb(int *a, int *b)
{
	if ((*a)>(*b))
	{
		int csere=*a;
		*a=*b;
		*b=csere;
	}
}

int main()
{
	int tomb[N];
	int i, j;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	for (i=0; i<N-1; i++)
	{
		for (j=i+1; j<N; j++)
		{
			csereHaNagyobb(&tomb[i], &tomb[j]); // egy kicsit masfajta rendezes, de a lenyeg itt is az, hogy az elso ciklus utan a legkisebb szam lesz az elso, stb
		}
	}
	printf("A tomb rendezes utan:\n");
	for (i=0; i<N; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	return 0;
}
