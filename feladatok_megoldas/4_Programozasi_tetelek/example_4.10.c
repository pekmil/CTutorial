/*****************************************************************************************************************************************
* 4.10 Feladat(!)                                                                                                                        *
*   Készítsen programot, amely képes eltárolni 10 komplex szám értékét (a valós és képzetes részt külön lebegőpontos változóban tárolja) *
*   Töltse fel a tömböt billentyűzetről beolvasott értékekkel                                                                            *
*   Rendezze a tömb elemeit origótól való távolságuk szerinti növekvő sorrendbe                                                          *
*   Írassa ki a tömb elemeit                                                                                                             *
*****************************************************************************************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	double valos[N], kepzetes[N];
	int i, j;
	printf("Kerem a szamok erteket (valos kepzetes formaban minden szamot kulon):\n");
	for (i=0; i<N; i++)
	{
		scanf("%lf %lf", &valos[i], &kepzetes[i]);
	}
	int min_idx;
	double csere;
	for (i=0; i<N-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (valos[j]*valos[j]+kepzetes[j]*kepzetes[j]<valos[min_idx]*valos[min_idx]+kepzetes[min_idx]*kepzetes[min_idx]) // nem kell a gyokvonas, mert a konkret ertek nem fontos, csak az, melyik a nagyobb
				min_idx=j;
		}
		if (min_idx!=i)
		{
			csere=valos[i];
			valos[i]=valos[min_idx];
			valos[min_idx]=csere;
			csere=kepzetes[i];
			kepzetes[i]=kepzetes[min_idx];
			kepzetes[min_idx]=csere;
		}
	}
	printf("A rendezett tomb:\n");
	for (i=0; i<N; i++)
	{
		printf("%lf+%lfi ", valos[i], kepzetes[i]);
	}
	printf("\n");
	return 0;
}
