/**************************************************************************************************************************************************************
* 8.2.2 Feladat                                                                                                                                               *
*   Készítsen egy struktúrát, amely egy ajtó paramétereit tárolja:                                                                                            *
*     Szélesség (lebegőpontos szám)                                                                                                                           *
*     Magasság (lebegőpontos szám)                                                                                                                            *
*     Nyikorgási érték (egész szám)                                                                                                                           *
*   Készítsen egy struktúrát, amely egy ház adatait tárolja:                                                                                                  *
*     Ajtók száma (egész szám)                                                                                                                                *
*     A házban található ajtók tömbje                                                                                                                         *
*   Készítsen egy programot, amely három házat tárol.                                                                                                         *
*   Minden házhoz                                                                                                                                             *
*     Kérje be, hogy a házban hány ajtó található                                                                                                             *
*     Foglaljon helyet a megadott számú ajtónak a házban                                                                                                      *
*     Olvassa be az ajtók adatait                                                                                                                             *
*   Írja ki a beolvasott adatokat.                                                                                                                            *
*   Keresse meg és írja ki a legtöbb ajtóval rendelkező házat.                                                                                                *
*   Írjon egy függvényt, amely egy ajtót kap paraméterül, és visszatér a területével.                                                                         *
*   Írjon egy függvényt, amely egy ház memóriacímét kapja meg paraméterül, valamint egy lebegőpontos számot, és visszatér egy egész számmal, amely megmondja, *
*        az adott házban hány ajtó területe nagyobb az adott számnál. A függvény használja fel az előbbi függvényt.                                           *
*   Kérjen be egy lebegőpontos számot, és az előző függvények segítségével számolja meg, összesen hány ajtó területe nagyobb a számnál.                       *
*   Készítsen egy dátumot ábrázoló struktúrát a következő adattagokkal:                                                                                       *
*     Év                                                                                                                                                      *
*     Hónap                                                                                                                                                   *
*     Nap                                                                                                                                                     *
*   A házellenőrző bizottság rendszeresen ellenőrzéseket tart, amiket nyomon szeretnénk követni                                                               *
*     Implementáljon egy dinamikusan változó méretű, dátumokat tartalmazó tömböt.                                                                             *
*     Készítsen egy függvényt, amely ehhez a tömbhöz egy új dátumot fűz hozzá.                                                                                *
*     Kérje be néhány dátum adatát, és az előbbi függvénnyel fűzze hozzá a tömbhöz.                                                                           *
*     Írja ki a házellenőrzések időpontjait.                                                                                                                  *
*   Ne használjon globális változókat, és figyeljen a helyes memóriakezelésre.                                                                                *
**************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct door
{
	float szelesseg, magassag;
	int nyikorgas;
} Door;

typedef struct house
{
	int ajtok_szama;
	Door *ajtok;
} House;

typedef struct date
{
	int ev, honap, nap;
} Date;

float ajtoTerulet(Door ajto) //lehetne ez is mutato a hatekonysag miatt, de a feladat azt irta, hogy ajtot, tehat jo igy is
{
	return ajto.szelesseg*ajto.magassag;
}

int nagyobbAjto(House *haz, float terulet)
{
	int szamol=0;
	int i;
	for (i=0; i<haz->ajtok_szama; i++)
	{
		if (terulet<ajtoTerulet(haz->ajtok[i]))
		{
			szamol++;
		}
	}
	return szamol;
}

void ujEllenorzes(Date **datumok, int *meret, Date uj_datum) //Date**, mert a mutato erteke valtozni fog, int*, mert a meretet is frissiteni kell
{
	if (*meret==0)
	{
		*datumok=(Date*)malloc(sizeof(Date)*(*meret+1));
		(*datumok)[0]=uj_datum; //csak ez az egy eleme van, attol meg lehet indexelni; a zarojel a precedencia miatt kell
		(*meret)++;
	}
	else
	{
		Date *atmeneti=(Date*)malloc(sizeof(Date)*(*meret+1));
		int i;
		for (i=0; i<*meret; i++)
		{
			atmeneti[i]=(*datumok)[i];
		}
		atmeneti[*meret]=uj_datum;
		free(*datumok);
		*datumok=atmeneti;
		(*meret)++;
	}
}

int main()
{
	House hazak[N];
	int i, j;
	
	//beolvasas
	for (i=0; i<N; i++)
	{
		printf("Mennyi ajto van a(z) %d. hazban?\n", i);
		scanf("%d", &hazak[i].ajtok_szama);
		hazak[i].ajtok=(Door*)malloc(sizeof(Door)*hazak[i].ajtok_szama);
		for (j=0; j<hazak[i].ajtok_szama; j++)
		{
			printf("\tKerem a haz %d. ajtojanak adatait: (szelesseg, magassag, nyikorgas)\n", j);
			scanf("%f %f %d", &hazak[i].ajtok[j].szelesseg, &hazak[i].ajtok[j].magassag, &hazak[i].ajtok[j].nyikorgas);
		}
	}
	
	//kiiras
	for (i=0; i<N; i++)
	{
		printf("A(z) %d. hazban %d ajto van, ezek adatai:\n", i, hazak[i].ajtok_szama);
		for (j=0; j<hazak[i].ajtok_szama; j++)
		{
			printf("\tszelesseg: %f, magassag: %f, nyikorgas: %d\n", hazak[i].ajtok[j].szelesseg, hazak[i].ajtok[j].magassag, hazak[i].ajtok[j].nyikorgas);
		}
	}
	
	//ajtok terulete
	float terulet;
	printf("Kerem a referencia teruletet:\n");
	scanf("%f", &terulet);
	int szamol=0;
	for (i=0; i<N; i++)
	{
		szamol+=nagyobbAjto(&hazak[i], terulet);
	}
	printf("Osszesen %d ajto terulete nagyobb a szamnal.\n", szamol);
	
	//datumok dinamikusan
	Date *datumok=0;
	int datumok_szama=0;
	
	for (i=0; i<4; i++) //a feladat nem ir konkretumot, ugyhogy legyen mondjuk 4 ellenorzes; lehetne akar kerdes alapu is (ad meg meg ellenorzest?)
	{
		Date datum;
		printf("Kerem a datumot: (ev, honap, nap)\n");
		scanf("%d %d %d", &datum.ev, &datum.honap, &datum.nap);
		ujEllenorzes(&datumok, &datumok_szama, datum);
	}
	
	printf("Az ellenorzesek:\n");
	for (i=0; i<datumok_szama; i++) //itt mar a datumok eltarolt szamat kell mindenkepp hasznalni
	{
		printf("\t%d.%d.%d\n", datumok[i].ev, datumok[i].honap, datumok[i].nap);
	}
	
	
	if (datumok) //nem muszaj, mert ha 0, akkor nem csinal semmit a free, de igy szebb
	{
		free(datumok);
	}
	for (i=0; i<N; i++)
	{
		free(hazak[i].ajtok);
	}
	return 0;
}
