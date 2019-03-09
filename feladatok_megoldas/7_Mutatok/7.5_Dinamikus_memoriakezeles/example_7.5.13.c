/******************************************************************************************************************************************************************************************
* 7.5.13 Feladat(!)                                                                                                                                                                       *
*   Készítsen egy struktúrát, amely egy mozi ülésrendjét tárolja, és a következő adattagokkal rendelkezik:                                                                                *
*     Különböző hosszúságú sorok (minden elem egy személy memóriacíme)                                                                                                                    *
*   Készítsen egy személy struktúrát, amely a következő adatokat tárolja:                                                                                                                 *
*     Keresztnév: legfeljebb 20 karakter hosszú                                                                                                                                           *
*     A foglalt hely (sor, ülés)                                                                                                                                                          *
*   Írjon függvényt, amely egy mozi sorainak számát kapja paraméterül, majd lefoglalja neki a helyet, beállítja annak paramétereit és visszatér memóriacímével.                           *
*     Olvassa be az egyes sorok szélességét és ennek megfelelően foglalja le nekik a helyet                                                                                               *
*   Írjon függvényt, amely egy mozi és egy személy memóriacímét kapja paraméterül és megpróbálja lefoglalni számára a helyet. Amennyiben sikerült, 1-el tér vissza, különben 0-val.       *
*   Írjon függvényt, amely egy mozi memóriacímét és egy karaktert kap paraméterül és visszaadja, hogy hány olyan személy foglalt helyet a moziban, akiknek a nevében szerepel a karakter. *
*   Hozzon létre egy mozi példányt és egy tízelemű tömböt, amely személyeket tárol                                                                                                        *
*   Olvassa be a személyek adatait a következőképpen: Miután beolvasta a személy nevét (hossznak megfelelő méreten tárolva), olvassa be a foglalni kívánt helyet (sor, oszlop).           *
*   Amennyiben a hely foglalt, úgy jelenítse meg a széken ülő személy nevét és kérjen be újabb helyet.                                                                                    *
*   Írja ki a képernyőre azt a karaktert, amely a moziban helyet foglalók közül a legtöbb személy nevében szerepel (ha több ilyen is van, akkor mindet)                                   *
******************************************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct person
{
	char nev[21];
	int sor, ules;
} Person;

typedef struct places
{
	int sorok_szama; // el kell tarolni, hogy hany sor van
	int *ulesszam; // minden sorhoz el kell tarolni a benne levo ulesek szamat, mert nem tudjuk elore
	Person ***sorok;
} Places;

Places* mozitLefoglal(int sorok_szama)
{
	Places *mozi=(Places*)malloc(sizeof(Places));
	mozi->sorok_szama=sorok_szama;
	mozi->sorok=(Person***)malloc(sizeof(Person**)*sorok_szama);
	mozi->ulesszam=(int*)malloc(sizeof(int)*sorok_szama);
	int i, j;
	for (i=0; i<sorok_szama; i++)
	{
		printf("Hany szek legyen a(z) %d. sorban?\n", i);
		scanf("%d", &(mozi->ulesszam[i]));
		mozi->sorok[i]=(Person**)malloc(sizeof(Person*)*mozi->ulesszam[i]);
		for (j=0; j<mozi->ulesszam[i]; j++)
			mozi->sorok[i][j]=0;
	}
	return mozi;
}

int lefoglal(Places *mozi, Person *szemely)
{
	int siker=0;
	if (szemely->sor<0 || szemely->sor>=mozi->sorok_szama)
	{
		printf("A megadott hely ervenytelen.\n");
	}
	else
	{
		if (szemely->ules<0 || szemely->ules>=mozi->ulesszam[szemely->sor])
		{
			printf("A megadott hely ervenytelen.\n");
		}
		else
		{
			if (mozi->sorok[szemely->sor][szemely->ules]!=0)
			{
				printf("A megadott hely foglalt %s altal.\n", mozi->sorok[szemely->sor][szemely->ules]->nev);
			}
			else
			{
				siker=1;
				mozi->sorok[szemely->sor][szemely->ules]=szemely;
			}
		}
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
	int i, j;
	int darab=0;
	for (i=0; i<mozi->sorok_szama; i++)
	{
		for (j=0; j<mozi->ulesszam[i]; j++)
		{
			if (mozi->sorok[i][j]!=0)
				darab+=karakterNevben(mozi->sorok[i][j]->nev, karakter);
		}
	}
	return darab;
}

int main()
{
	Person szemelyek[N];
	Places *mozi;
	int i, j;
	
	int sorok;
	printf("Hany sor van a moziban?\n");
	scanf("%d", &sorok);
	mozi=mozitLefoglal(sorok);
	
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
			siker=lefoglal(mozi, &szemelyek[i]);
		} while (siker==0);
	}
	
	printf("A szabad helyek:\n");
	for (i=0; i<mozi->sorok_szama; i++)
	{
		printf("%d. sor\n\t", i);
		for (j=0; j<mozi->ulesszam[i]; j++)
		{
			if (mozi->sorok[i][j]==0)
				printf("%d ", j);
		}
		printf("\n");
	}
	
	int karakter_darab[128]; // egy tomb, amiben eltaroljuk minden karakter elofordulasat, habar ebbol sokat nem fogunk hasznalni
	for (i=0; i<128; i++)
	{
		karakter_darab[i]=karakterNevekben(mozi, i); // a karakter is egy szam
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
	
	for (i=0; i<mozi->sorok_szama; i++)
	{
		free(mozi->sorok[i]);
	}
	free(mozi->sorok);
	free(mozi->ulesszam);
	free(mozi);
	
	return 0;
}
