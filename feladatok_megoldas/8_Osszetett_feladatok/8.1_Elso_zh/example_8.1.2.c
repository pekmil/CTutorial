/**************************************************************************************************************
* 8.1.2 Feladat                                                                                               *
*   Készítsen egy struktúrát, amely egy focista adatait tárolja, és a következő adattagokkal rendelkezik:     *
*     Mez sorszáma                                                                                            *
*     Életkor                                                                                                 *
*     Testmagasság                                                                                            *
*     Összes gólok száma                                                                                      *
*     Összes lejátszott meccs száma                                                                           *
*   A program olvassa be és tárolja el 10 játékos adatait.                                                    *
*   Írja ki az összes adatot.                                                                                 *
*   Keresse meg a legidősebb játékost, és írja ki az adatait.                                                 *
*   Keresse meg az eddig legtöbb gólt szerző játékost, és írja ki az adatait.                                 *
*   Kérjen be egy újabb számot.                                                                               *
*   Jelenítse meg az adott mezszámmal rendelkező játékos adatait, feltéve, ha van ilyen.                      *
*   Kérjen be egy újabb számot, és írja ki, hogy hány olyan játékos van, aki legalább ennyi meccses játszott. *
*   Rendezze a játékosokat testmagasságuk szerinti csökkenő sorrendbe.                                        *
*   Írja ki az összes adatot.                                                                                 *
*   Rendezze a játékosokat a meccsenkénti átlagos rúgott gólok száma szerinti növekvő sorrendbe.              *
*   Írja ki az összes adatot.                                                                                 *
**************************************************************************************************************/

#include <stdio.h>

#define N 10

typedef struct player
{
	int mez;
	unsigned int kor, magas, golok, meccsek;
} Player;

int main()
{
	Player jatekosok[N];
	int i, j;
	
	// beolvasas
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. jatekos adatait (mez, kor, magassag, golok, meccsek):\n", i);
		scanf("%d %u %u %u %u", &jatekosok[i].mez, &jatekosok[i].kor, &jatekosok[i].magas, &jatekosok[i].golok, &jatekosok[i].meccsek);
	}
	
	//kiiras
	for (i=0; i<N; i++)
	{
		printf("A(z) %d. jatekos adatai: mez: %d, kor: %u, magassag: %u, golok: %u, meccsek: %u\n", i, jatekosok[i].mez, jatekosok[i].kor, jatekosok[i].magas, jatekosok[i].golok, jatekosok[i].meccsek);
	}
	
	// legidosebb jatekos
	int max_kor=0;
	for (i=1; i<N; i++)
	{
		if (jatekosok[i].kor>jatekosok[max_kor].kor)
		{
			max_kor=i;
		}
	}
	printf("A legidosebb jatekos: %d (eletkor: %u).\n", max_kor, jatekosok[max_kor].kor);
	
	// legtobb gol
	int max_gol=0;
	for (i=1; i<N; i++)
	{
		if (jatekosok[i].golok>jatekosok[max_gol].golok)
		{
			max_gol=i;
		}
	}
	printf("A legtobb golos jatekos: %d (golok: %u).\n", max_gol, jatekosok[max_gol].golok);
	
	// mezszam keresese
	int mez_szam;
	printf("Kerek egy mezszamot:\n");
	scanf("%d", &mez_szam);
	i=0;
	while (i<N && jatekosok[i].mez!=mez_szam)
	{
		i++;
	}
	if (i==N)
	{
		printf("A mezszam (%d) nem talalhato.\n", mez_szam);
	}
	else
	{
		printf("A keresett jatekos: %d.\n", i);
	}
	
	// meccsek szama
	unsigned int meccs;
	printf("Kerek egy szamot:\n");
	scanf("%u", &meccs);
	int szamol=0;
	for (i=0; i<N; i++)
	{
		if (jatekosok[i].meccsek>=meccs)
		{
			szamol++;
		}
	}
	printf("%d fo jatszott legalabb %d meccsen.\n", szamol, meccs);
	
	// rendezes magassag szerint
	Player csere;
	int max_magas;
	for (i=0; i<N-1; i++)
	{
		max_magas=i;
		for (j=i+1; j<N; j++)
		{
			if (jatekosok[j].magas>jatekosok[max_magas].magas)
			{
				max_magas=j;
			}
		}
		if (max_magas!=i)
		{
			csere=jatekosok[i];
			jatekosok[i]=jatekosok[max_magas];
			jatekosok[max_magas]=csere;
		}
	}
	
	//kiiras
	printf("\n\nMagassak szerint csokkeno:\n");
	for (i=0; i<N; i++)
	{
		printf("A(z) %d. jatekos adatai: mez: %d, kor: %u, magassag: %u, golok: %u, meccsek: %u\n", i, jatekosok[i].mez, jatekosok[i].kor, jatekosok[i].magas, jatekosok[i].golok, jatekosok[i].meccsek);
	}
	
	// rendezes atlag gol szerint
	int min_gol;
	for (i=0; i<N-1; i++)
	{
		min_gol=i;
		for (j=i+1; j<N; j++)
		{
			if ((float)(jatekosok[j].golok)/jatekosok[j].meccsek<(float)(jatekosok[min_gol].golok)/jatekosok[min_gol].meccsek) // a float-ta konvertalas kell, mert kulonben az osztas maradekos, ez az nem megfelelo
			{
				min_gol=j;
			}
		}
		if (min_gol!=i)
		{
			csere=jatekosok[i];
			jatekosok[i]=jatekosok[min_gol];
			jatekosok[min_gol]=csere;
		}
	}
	
	//kiiras
	printf("\n\nAtlagos gol szerint novekvo:\n");
	for (i=0; i<N; i++)
	{
		printf("A(z) %d. jatekos adatai: mez: %d, kor: %u, magassag: %u, golok: %u, meccsek: %u, atlagos golok: %f\n", i, jatekosok[i].mez, jatekosok[i].kor, jatekosok[i].magas, jatekosok[i].golok, jatekosok[i].meccsek, (float)(jatekosok[i].golok)/jatekosok[i].meccsek);
	}
	
	
	return 0;
}
