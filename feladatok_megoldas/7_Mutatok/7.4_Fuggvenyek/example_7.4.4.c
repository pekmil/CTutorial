/******************************************************************************************************************************************************************************************
* 7.4.4 Feladat(!)                                                                                                                                                                        *
*   Készítsen egy struktúrát, amely egy mozi ülésrendjét tárolja, és a következő adattagokkal rendelkezik:                                                                                *
*     Első sor: 3 elemű tömb, amely személyek memóriacímét tárolja                                                                                                                        *
*     Második sor: 5 elemű tömb, amely személyek memóriacímét tárolja                                                                                                                     *
*     Harmadik sor: 7 elemű tömb, amely személyek memóriacímét tárolja                                                                                                                    *
*   Készítsen egy személy struktúrát, amely a következő adatokat tárolja:                                                                                                                 *
*     Keresztnév: legfeljebb 20 karakter hosszú                                                                                                                                           *
*     A foglalt hely (sor, ülés)                                                                                                                                                          *
*   Írjon függvényt, amely egy mozi és egy személy memóriacímét kapja paraméterül és megpróbálja lefoglalni számára a helyet. Amennyiben sikerült, 1-el tér vissza, különben 0-val.       *
*   Írjon függvényt, amely egy mozi memóriacímét és egy karaktert kap paraméterül és visszaadja, hogy hány olyan személy foglalt helyet a moziban, akiknek a nevében szerepel a karakter. *
*   Hozzon létre egy mozi példányt és egy tízelemű tömböt, amely személyeket tárol                                                                                                        *
*   Olvassa be a személyek adatait a következőképpen: Miután beolvasta a személy nevét, olvassa be a foglalni kívánt helyet (sor, oszlop).                                                *
*   Amennyiben a hely foglalt, úgy jelenítse meg a széken ülő személy nevét és kérjen be újabb helyet.                                                                                    *
*   Írja ki a képernyőre a szabad helyeket                                                                                                                                                *
*   Írja ki a képernyőre azt a karaktert, amely a moziban helyet foglalók közül a legtöbb személy nevében szerepel (ha több ilyen is van, akkor mindet)                                   *
******************************************************************************************************************************************************************************************/

#include <stdio.h>
#include <string.h>

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

int lefoglal(Places *mozi, Person *szemely)
{
	int siker=0;
	if (szemely->sor==0)
	{
		if (szemely->ules>=0 && szemely->ules<ELSO)
		{
			if (mozi->elso[szemely->ules]==0)
			{
				siker=1;
				mozi->elso[szemely->ules]=szemely;
				printf("Hely lefoglalva.\n");
			}
			else
			{
				printf("A hely mar foglalt %s altal.\n", mozi->elso[szemely->ules]->nev);
			}
		}
		else
		{
			printf("Az igenyelt hely ervenytelen.\n");
		}
	}
	else if (szemely->sor==1)
	{
		if (szemely->ules>=0 && szemely->ules<MASODIK)
		{
			if (mozi->masodik[szemely->ules]==0)
			{
				siker=1;
				mozi->masodik[szemely->ules]=szemely;
				printf("Hely lefoglalva.\n");
			}
			else
			{
				printf("A hely mar foglalt %s altal.\n", mozi->masodik[szemely->ules]->nev);
			}
		}
		else
		{
			printf("Az igenyelt hely ervenytelen.\n");
		}
	}
	else if (szemely->sor==2)
	{
		if (szemely->ules>=0 && szemely->ules<HARMADIK)
		{
			if (mozi->harmadik[szemely->ules]==0)
			{
				siker=1;
				mozi->harmadik[szemely->ules]=szemely;
				printf("Hely lefoglalva.\n");
			}
			else
			{
				printf("A hely mar foglalt %s altal.\n", mozi->harmadik[szemely->ules]->nev);
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
	return siker;
}

int karakterNevben(char *nev, char karakter) // nem volt rola szo, hogy nem lehet masik fuggvenyt is irni
{
	int i=0;
	int hossz=strlen(nev);
	while (i<hossz && nev[i]!=karakter)
		i++;
	if (i<hossz) // benne van a karakter a nevben
		return 1;
	else // nincs benne
		return 0;
}

int karakterNevekben(Places *mozi, char karakter)
{
	int i;
	int darab=0;
	for (i=0; i<ELSO; i++)
	{
		if (mozi->elso[i]!=0)
		{
			darab+=karakterNevben(mozi->elso[i]->nev, karakter);
		}
	}
	for (i=0; i<MASODIK; i++)
	{
		if (mozi->masodik[i]!=0)
		{
			darab+=karakterNevben(mozi->masodik[i]->nev, karakter);
		}
	}
	for (i=0; i<HARMADIK; i++)
	{
		if (mozi->harmadik[i]!=0)
		{
			darab+=karakterNevben(mozi->harmadik[i]->nev, karakter);
		}
	}
	return darab;
}

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
			siker=lefoglal(&mozi, &szemelyek[i]);
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
	
	int karakter_darab[128]; // egy tomb, amiben eltaroljuk minden karakter elofordulasat, habar ebbol sokat nem fogunk hasznalni
	for (i=0; i<128; i++)
	{
		karakter_darab[i]=karakterNevekben(&mozi, i); // a karakter is egy szam
	}
	int max_darab=karakter_darab[0];
	for (i=0; i<128; i++)
	{
		if (max_darab<karakter_darab[i])
			max_darab=karakter_darab[i];
	}
	printf("A legtobbszor szereplo karakterek:\n");
	for (i=0; i<128; i++)
	{
		if (karakter_darab[i]==max_darab)
			printf("%c ", i); // a szam is ertelmezheto karakterent
	}
	printf("\n");
	return 0;
}
