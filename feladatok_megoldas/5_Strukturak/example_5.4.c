/**********************************************************************************************************************************************
* 5.4 Feladat                                                                                                                                 *
*   Készítsen programot, amely hallgatók neptunkódját,és a félévben írt öt zárthelyi dolgozatának eredményét                                  *
*   tárolja (0-5 érdemjegy, ha 0, akkor nem írta meg)                                                                                         *
*   Olvassa be 10 hallgató adatát                                                                                                             *
*   Rendezze az adatokat a hallgatók átlaga szerinti csökkenő sorrendbe, jelenítse meg a hallgatók neptunkódját és a megírt dolgozatok számát *
*     Az átlagba a nem megírt dolgozatok nem számítanak bele                                                                                  *
**********************************************************************************************************************************************/

#include <stdio.h>

#define N 10
#define M 5

typedef struct student
{
	char neptunkod[7]; // mivel szoveg, kell egy hely a lezaro '\0'-nak
	int eredmeny[M];
} Student;

int main()
{
	Student hallgatok[10];
	int i, j;
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. hallgato adatait: neptunkod, erdemjegyek.\n", i+1);
		scanf("%s", hallgatok[i].neptunkod);
		for (j=0; j<M; j++)
		{
			scanf("%d", &hallgatok[i].eredmeny[j]);
		}
	}
	float atlagok[N]; // a feladat nem irta, hogy nem lehet az atlagokat eltarolni, es igy egyszerubb, mint mindig helyben szamolni
	int darab; // annak tarolasara, hogy mennyi dolgozatot irt meg
	for (i=0; i<N; i++)
	{
		atlagok[i]=0.0;
		darab=0;
		for (j=0; j<M; j++)
		{
			if (hallgatok[i].eredmeny[j]!=0)
			{
				atlagok[i]+=hallgatok[i].eredmeny[j];
				darab++;
			}
		}
		atlagok[i]/=darab;
	}
	printf("Az atlagok:\n");
	for (i=0; i<N; i++)
	{
		printf("%f ", atlagok[i]);
	}
	printf("\nRendezes atlag szerint.\n");
	int max_idx;
	Student csere;
	float atlag_csere; // mert ha az atlagokat kulon eltaroljuk, akkor viszont azokat is cserelgetni kell
	for (i=0; i<N-1; i++)
	{
		max_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (atlagok[j]>atlagok[max_idx])
				max_idx=j;
		}
		if (max_idx!=i)
		{
			csere=hallgatok[i];
			hallgatok[i]=hallgatok[max_idx];
			hallgatok[max_idx]=csere;
			atlag_csere=atlagok[i];
			atlagok[i]=atlagok[max_idx];
			atlagok[max_idx]=atlag_csere;
		}
	}
	for (i=0; i<N; i++)
	{
		printf("%s", hallgatok[i].neptunkod);
		for (j=0; j<M; j++)
		{
			printf(" %d", hallgatok[i].eredmeny[j]);
		}
		printf("\n");
	}
	return 0;
}
