/******************************************************************************************************************************************************************************
* 2. Nagy zárthelyi példa                                                                                                                                                     *
* Alapfeladat                                                                                                                                                                 *
*   Hozza létre a következő struktúrát:                                                                                                                                       *
*     Ablak típus                                                                                                                                                             *
*       Szélesség: lebegőpontos szám                                                                                                                                          *
*       Magasság: lebegőpontos szám                                                                                                                                           *
*       Megnevezés: szöveg (maximum 20 karakter)                                                                                                                              *
*       Ablak tömege: lebegőpontos szám                                                                                                                                       *
*   Készítsen egy függvényt, amely egy darabszámot kap paraméterül, foglal memóriát a megadott számú ablaknak, majd visszatér a lefoglalt memóriaterület címével.             *
*   Kérje be, hogy mennyi ablak típus adatait tároljuk, és foglaljon nekik helyet az előbbi függvény segítségével.                                                            *
*   Olvassa be a ablakok adatait.                                                                                                                                             *
*   Jelenítse meg a beolvasott ablakok adatait.                                                                                                                               *
*                                                                                                                                                                             *
* Feladat (1 pont)                                                                                                                                                            *
*   Rendezze az ablakok tömbjét csökkenő sorrendbe szélesség szerint. Ha több ablak szélessége is megegyezik, akkor a megnevezés szerint abc-ben hátrébb lévő legyen előrébb. *
*   Jelenítse meg a rendezett sorrendet.                                                                                                                                      *
*                                                                                                                                                                             *
* Feladat (1 pont)                                                                                                                                                            *
*   Olvasson be egy lebegőpontos számot (terület) és egy szöveget (megnevezés).                                                                                               *
*   Keresse meg és közölje, hogy van-e olyan ablak, amelynek megnevezése a bekért szöveg, területe nagyobb a bekért számnál.                                                  *
*   Ha igen, írja ki az összes találat adatait.                                                                                                                               *
*                                                                                                                                                                             *
* Feladat (1 pont)                                                                                                                                                            *
*   Készítsen egy függvényt, amely egy ablak memóriacímét kapja paraméterül, és kiírja az ablak adatait.                                                                      *
*   Készítsen egy függvényt, amely egy ablak memóriacímét kapja paraméterül, és beolvassa az ablak adatait.                                                                   *
*   Az ablakok beolvasását és kiírását ezen függvények segítségével oldja meg a program során.                                                                                *
*                                                                                                                                                                             *
* Feladat (1 pont)                                                                                                                                                            *
*   Írjon egy függvényt, amely az ablakok tömbjében megkeresi a legnagyobb tömegű ablakot, és visszatér a memóriacímével.                                                     *
*   Keresse meg, és közölje a legnehezebb ablak adatait az előbbi függvényt felhasználva                                                                                      *
*                                                                                                                                                                             *
* Feladat (1 pont)                                                                                                                                                            *
*   Az ablakgyár újabb típusok gyártását tervezi, de úgy, hogy a régiek is megmaradnak. Olvassa be, hogy mennyivel nő a gyártandó típusok száma.                              *
*   Foglalja újra a tömböt az alapfeladatban megírt függvény felhasználásával akkora méretűre, hogy a régi és új ablakok is elférjenek benne.                                 *
*   Biztosítsa, hogy a régi ablakok megmaradjanak az új tömbben.                                                                                                              *
*   Olvassa be az új ablakok adatait.                                                                                                                                         *
*   Írja ki az összes ablak adatait.                                                                                                                                          *
******************************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ablak
{
	float szelesseg, magassag, tomeg;
	char megnevezes[21]; // 20 + 1 a lezáró '\0'-nak
} Ablak;

Ablak *ablakokatLefoglal(int meret)
{
	Ablak *tomb=(Ablak*)malloc(sizeof(Ablak)*meret);
	return tomb;
}

// Függvények a harmadik feladathoz
void ablakKiir(Ablak *ablak)
{
		printf("ablak adatai:\n");
		printf("szelesseg: %.3f, magassag: %.3f, tomeg: %.3f, megnevezes: %s\n", ablak->szelesseg, ablak->magassag, ablak->tomeg, ablak->megnevezes);
}

void ablakBeolvas(Ablak *ablak)
{
		printf("ablak adatai: (szelesseg, magassag, tomeg, megnevezes)\n");
		scanf("%f %f %f %s", &ablak->szelesseg, &ablak->magassag, &ablak->tomeg, ablak->megnevezes);
}

// Függvény a negyedik feladathoz
Ablak *legnehezebb(Ablak *tomb, int meret)
{
	int i=0;
	int max_idx=0;
	for (i=1; i<meret; i++)
	{
		if (tomb[max_idx].tomeg<tomb[i].tomeg)
		{
			max_idx=i;
		}
	}
	return &tomb[max_idx];
}

int main()
{
	int ablakok_szama;
	printf("Mennyi ablakot taroljunk?\n");
	scanf("%d", &ablakok_szama);
	Ablak *ablakok=ablakokatLefoglal(ablakok_szama);
	int i=0;
	for (i=0; i<ablakok_szama; i++)
	{
		printf("%d. ", i);
		ablakBeolvas(&ablakok[i]);
	}
	
	for (i=0; i<ablakok_szama; i++)
	{
		printf("%d. ", i);
		ablakKiir(&ablakok[i]);
	}
	
	// Első feladat
	printf("Rendezes:\n");
	for (i=0; i<ablakok_szama-1; i++)
	{
		int max_idx=i, j;
		for (j=i+1; j<ablakok_szama; j++)
		{
			if ( ablakok[max_idx].szelesseg<ablakok[j].szelesseg || (ablakok[max_idx].szelesseg==ablakok[j].szelesseg && strcmp(ablakok[max_idx].megnevezes, ablakok[j].megnevezes)<0) )
			{
				max_idx=j;
			}
		}
		if (max_idx!=i)
		{
			Ablak csere=ablakok[i];
			ablakok[i]=ablakok[max_idx];
			ablakok[max_idx]=csere;
		}
	}
	for (i=0; i<ablakok_szama; i++)
	{
		printf("%d. ", i);
		ablakKiir(&ablakok[i]);
	}
	
	// Második feladat
	float terulet;
	char megnevezes[21];
	printf("Kerem a teruletet es a megnevezest:\n");
	scanf("%f %s", &terulet, megnevezes);
	// Meg lehetne oldani először egy keresés segítségével, majd végigmenni még egyszer, de így gyorsabb. A legelső találatnál kiírjuk, hogy találtunk.
	char talalat=0;
	for (i=0; i<ablakok_szama; i++)
	{
		if (strcmp(ablakok[i].megnevezes, megnevezes)==0 && ablakok[i].szelesseg*ablakok[i].magassag>terulet)
		{
			// Ha ez az első találat, akkor el kell menteni, hogy van
			if (talalat==0)
			{
				talalat=1;
				printf("Van ilyen ablak. Ezek:\n");
			}
			printf("%d. ", i);
			ablakKiir(&ablakok[i]);
		}
	}
	if (talalat==0)
	{
		printf("Nincs ilyen ablak\n");
	}
	
	// Negyedik feladat
	Ablak *nehez=legnehezebb(ablakok, ablakok_szama);
	printf("A legnehezebb ");
	ablakKiir(nehez);
	
	// Ötödik feladat
	int noveles;
	printf("Mennyivel noveljuk a meretet?\n");
	scanf("%d", &noveles);
	Ablak *novelt=ablakokatLefoglal(ablakok_szama+noveles);
	for (i=0; i<ablakok_szama; i++)
	{
		novelt[i]=ablakok[i];
	}
	for (i=ablakok_szama; i<ablakok_szama+noveles; i++)
	{
		printf("%d. ", i);
		ablakBeolvas(&novelt[i]);
	}
	ablakok_szama+=noveles;
	free(ablakok);
	ablakok=novelt;
	for (i=0; i<ablakok_szama; i++)
	{
		printf("%d. ", i);
		ablakKiir(&ablakok[i]);
	}
	
	free(ablakok);
	return 0;
}
