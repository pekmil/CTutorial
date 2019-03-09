/*******************************************************************************************************************************************
* 7.3.5 Feladat(!)                                                                                                                         *
*   Készítsen egy struktúrát, amely egy mozi ülésrendjét tárolja, és a következő adattagokkal rendelkezik:                                 *
*     Első sor: 3 elemű tömb, amely személyek memóriacímét tárolja                                                                         *
*     Második sor: 5 elemű tömb, amely személyek memóriacímét tárolja                                                                      *
*     Harmadik sor: 7 elemű tömb, amely személyek memóriacímét tárolja                                                                     *
*   Készítsen egy személy struktúrát, amely a következő adatokat tárolja:                                                                  *
*     Keresztnév: legfeljebb 20 karakter hosszú                                                                                            *
*     A foglalt hely (sor, ülés)                                                                                                           *
*   Hozzon létre egy mozi példányt és egy tízelemű tömböt, amely személyeket tárol                                                         *
*   Olvassa be a személyek adatait a következőképpen: Miután beolvasta a személy nevét, olvassa be a foglalni kívánt helyet (sor, oszlop). *
*   Amennyiben a hely foglalt, úgy jelenítse meg a széken ülő személy nevét és kérjen be újabb helyet.                                     *
*   Írja ki a képernyőre a szabad helyeket                                                                                                 *
*******************************************************************************************************************************************/

#include <stdio.h>

#define ELSO 3
#define MASODIK 5
#define HARMADIK 7
#define N 10

typedef struct person
{
	char nev[21];
	int sor, ules;
} Person;

typedef struct places
{
	Person *elso[ELSO], *masodik[MASODIK], *harmadik[HARMADIK];
} Places;

int main()
{
	Person szemelyek[N];
	Places mozi;
	int i;
	for (i=0; i<ELSO; i++)
		mozi.elso[i]=0;
	for (i=0; i<MASODIK; i++)
		mozi.masodik[i]=0;
	for (i=0; i<HARMADIK; i++)
		mozi.harmadik[i]=0;
	
	int siker;
	for (i=0; i<N; i++)
	{
		siker=0;
		printf("Kerem a(z) %d. szemely nevet:\n", i+1);
		scanf("%s", szemelyek[i].nev);
		do
		{
			printf("Hova szeretne ulni (sor, ules; a szamozas 0-val kezdodik):\n");
			scanf("%d %d", &szemelyek[i].sor, &szemelyek[i].ules);
			if (szemelyek[i].sor==0)
			{
				if (szemelyek[i].ules>=0 && szemelyek[i].ules<ELSO)
				{
					if (mozi.elso[szemelyek[i].ules]==0)
					{
						siker=1;
						mozi.elso[szemelyek[i].ules]=&szemelyek[i];
						printf("Hely lefoglalva.\n");
					}
					else
					{
						printf("A hely mar foglalt %s altal.\n", mozi.elso[szemelyek[i].ules]->nev);
					}
				}
				else
				{
					printf("Az igenyelt hely ervenytelen.\n");
				}
			}
			else if (szemelyek[i].sor==1)
			{
				if (szemelyek[i].ules>=0 && szemelyek[i].ules<MASODIK)
				{
					if (mozi.masodik[szemelyek[i].ules]==0)
					{
						siker=1;
						mozi.masodik[szemelyek[i].ules]=&szemelyek[i];
						printf("Hely lefoglalva.\n");
					}
					else
					{
						printf("A hely mar foglalt %s altal.\n", mozi.masodik[szemelyek[i].ules]->nev);
					}
				}
				else
				{
					printf("Az igenyelt hely ervenytelen.\n");
				}
			}
			else if (szemelyek[i].sor==2)
			{
				if (szemelyek[i].ules>=0 && szemelyek[i].ules<HARMADIK)
				{
					if (mozi.harmadik[szemelyek[i].ules]==0)
					{
						siker=1;
						mozi.harmadik[szemelyek[i].ules]=&szemelyek[i];
						printf("Hely lefoglalva.\n");
					}
					else
					{
						printf("A hely mar foglalt %s altal.\n", mozi.harmadik[szemelyek[i].ules]->nev);
					}
				}
				else
				{
					printf("Az igenyelt hely ervenytelen.\n");
				}
			}
			else
			{
				printf("Az igenyelt hely ervenytelen.\n");
			}
		} while (siker==0);
	}
	printf("A szabad helyek:\n");
	printf("Elso sor:");
	for (i=0; i<ELSO; i++)
	{
		if (mozi.elso[i]==0)
			printf(" %d", i);
	}
	printf("\n");
	printf("Masodik sor:");
	for (i=0; i<MASODIK; i++)
	{
		if (mozi.masodik[i]==0)
			printf(" %d", i);
	}
	printf("\n");
	printf("Harmadik sor:");
	for (i=0; i<HARMADIK; i++)
	{
		if (mozi.harmadik[i]==0)
			printf(" %d", i);
	}
	printf("\n");
	return 0;
}
