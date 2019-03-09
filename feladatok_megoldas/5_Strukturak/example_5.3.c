/******************************************************************************************************************************************************************
* 5.3 Feladat                                                                                                                                                     *
*   Készítsen programot, amely személyek születési évét, hónapját, napját képes tárolni, valamint a személy lakhelyének fővárostól való távolságát km-ben (float) *
*   Olvassa be 5 személy adatait                                                                                                                                  *
*   Rendezze a tömböt a személyek kora szerinti növekvő sorrendbe, majd jelenítse meg az elemeit                                                                  *
*   Rendezze a tömböt a fővárostól való távolságok szerinti csökkenő sorrendbe, majd jelenítse meg az elemeit                                                     *
******************************************************************************************************************************************************************/

#include <stdio.h>

#define N 5

typedef struct person
{
	int ev, honap, nap;
	float tavolsag;
} Person;

int main()
{
	Person szemelyek[N];
	int i, j;
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. szemely adatait: ev, honap, nap, tavolsag\n", i+1);
		scanf("%d %d %d %f", &szemelyek[i].ev, &szemelyek[i].honap, &szemelyek[i].nap, &szemelyek[i].tavolsag);
	}
	printf("\nRendezes kor szerint\n");
	int min_idx;
	Person csere;
	for (i=0; i<N-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<N; j++)
		{
			if ( (szemelyek[j].ev<szemelyek[min_idx].ev) ||
					 (szemelyek[j].ev==szemelyek[min_idx].ev && szemelyek[j].honap<szemelyek[min_idx].honap) ||
					 (szemelyek[j].ev==szemelyek[min_idx].ev && szemelyek[j].honap==szemelyek[min_idx].honap && szemelyek[j].nap<szemelyek[min_idx].nap) ) // az eletkor osszehasonlitasa szuletesi ido alapjan osszetett feltetelt igenyel
				min_idx=j;
		}
		if (min_idx!=i)
		{
			csere=szemelyek[i];
			szemelyek[i]=szemelyek[min_idx];
			szemelyek[min_idx]=csere;
		}
	}
	for (i=0; i<N; i++)
	{
		printf("A(z) %d. szemely adatai: ev: %d, honap: %d, nap: %d, tavolsag: %f.\n", i+1, szemelyek[i].ev, szemelyek[i].honap, szemelyek[i].nap, szemelyek[i].tavolsag);
	}
	printf("\nRendezes tavolsag szerint\n");
	int max_idx;
	for (i=0; i<N-1; i++)
	{
		max_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (szemelyek[j].tavolsag>szemelyek[max_idx].tavolsag)
				max_idx=j;
		}
		if (max_idx!=i)
		{
			csere=szemelyek[i];
			szemelyek[i]=szemelyek[max_idx];
			szemelyek[max_idx]=csere;
		}
	}
	for (i=0; i<N; i++)
	{
		printf("A(z) %d. szemely adatai: ev: %d, honap: %d, nap: %d, tavolsag: %f.\n", i+1, szemelyek[i].ev, szemelyek[i].honap, szemelyek[i].nap, szemelyek[i].tavolsag);
	}
	return 0;
}
