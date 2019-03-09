/***************************************************************************************************************************************************************************************************
* 8.2.1 Feladat                                                                                                                                                                                    *
*   Készítsen egy CyberMedic struktúrát a következő adattagokkal:                                                                                                                                  *
*     IP-cím (sztring, maximum15 karakter)                                                                                                                                                         *
*     Név (sztring, maximum 30 karakter)                                                                                                                                                           *
*   Készítsen egy számítógép struktúrát a következő adattagokkal:                                                                                                                                  *
*     Felhasználó azonosító (előjel néküli egész szám)                                                                                                                                             *
*     Gyártási év (egész szám)                                                                                                                                                                     *
*     Eddig szerelések száma (előjel néküli egész szám)                                                                                                                                            *
*     A géphez rendelt CyberMedic memóriacíme                                                                                                                                                      *
*   Hozzon létre egy ötelemű, CyberMedic-eket tároló tömböt, és tölste fel értékekkel.                                                                                                             *
*   Rendezze a tömb elemeit név szerinti növekvő sorrendbe.                                                                                                                                        *
*   Készítsen függvényt, amely egy méretet vár paraméterül, és visszatér egy megfelelő méretű, dinamikusan lefoglalt számítógép-tömb címével.                                                      *
*   Olvasson be egy egész számot, és hozzon létre egy ekkora méretű, számítógépeket tároló tömböt, az előző függvény segítségével.                                                                 *
*   Kérje be a számítógép tömb elemeit. A géphez rendelt CyberMedic-et IP-cím alapján határozza meg.                                                                                               *
*   Írja ki a számítógépek adatait, a géphez tartozó CyberMedic adataival együtt.                                                                                                                  *
*   Készítsen függvényt, amely megkeresi a legidősebb számítógépet, és visszatér a memóriacímével.                                                                                                 *
*   Használja az előbbi függvényt, és írja ki a megkeresett számítógép adatait.                                                                                                                    *
*   Készítsen függvényt, amely megkapja a számítógép tömbjét, és egy CyberMedic memóriacímét paraméterül. A CyberMedic szerelje meg az összes számítógépet, és ezt jelezze az adatszerkezetben is. *
*        Térjen vissza a megszerelt számítógépek számával.                                                                                                                                         *
*   Kérjen be egy IP-címet. Az adott címen lévő CyberMedic-re hívja meg az előző függvényt.                                                                                                        *
*   Ne használjon globális változókat, és figyeljen a helyes memóriakezelésre.                                                                                                                     *
***************************************************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct cybermedic
{
	char ip_cim[16]; //15+1 a \0 miatt
	char nev[31]; //30+1 a \0 miatt
} CyberMedic;

typedef struct computer
{
	unsigned int id;
	int gyartasi_ev;
	unsigned int szereles_szam;
	CyberMedic *szerelo;
} Computer;

Computer* gepeketFoglal(int meret)
{
	return (Computer*)malloc(sizeof(Computer)*meret);
}

Computer* legidosebbGep(Computer *tomb, int meret)
{
	Computer *visszateres=0;
	if (meret>0) //csak akkor kell szamolni, ha van a tombnek eleme
	{
		int i, min_idx=0; //legidosebb gep, vagyis legkisebb gyartasi ev
		for (i=1; i<meret; i++)
		{
			if (tomb[i].gyartasi_ev<tomb[min_idx].gyartasi_ev)
			{
				min_idx=i;
			}
		}
		visszateres=&tomb[min_idx];
	}
	return visszateres;
}

int szerel(Computer *tomb, int meret, CyberMedic *szerelo)
{
	int szamol=0;
	int i;
	for (i=0; i<meret; i++)
	{
		if (tomb[i].szerelo==szerelo)
		{
			tomb[i].szereles_szam++;
			szamol++;
		}
	}
	return szamol;
}

int main()
{
	CyberMedic szerelok[N];
	int i, j;
	
	//szerelok bekerese
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. szerelo adatait (cim, nev):\n", i);
		scanf("%s %s", szerelok[i].ip_cim, szerelok[i].nev);
	}
	
	//szerelok rendezese
	for (i=0; i<N-1; i++)
	{
		int min_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (strcmp(szerelok[min_idx].nev, szerelok[j].nev)>0) // ha a min_idx. nagyobb az j.-nel
			{
				min_idx=j;
			}
		}
		if (min_idx!=i)
		{
			CyberMedic csere=szerelok[i];
			szerelok[i]=szerelok[min_idx];
			szerelok[min_idx]=csere;
		}
	}
	
	//kiiras ellenorzes celjabol
	for (i=0; i<N; i++)
	{
		printf("%d. szerelo: %s, %s\n", i, szerelok[i].ip_cim, szerelok[i].nev);
	}
	
	//gepek bekerese
	int gepek_szama;
	printf("Mennyi szamitogepet taroljunk?\n");
	scanf("%d", &gepek_szama);
	
	Computer *gepek=gepeketFoglal(gepek_szama);
	char ip[16];
	for (i=0; i<gepek_szama; i++)
	{
		printf("Kerem a(z) %d. gep adatait (id, ev, szerelesek, medic ip):\n", i);
		scanf("%u %d %u %s", &gepek[i].id, &gepek[i].gyartasi_ev, &gepek[i].szereles_szam, ip);
		j=0;
		while (j<N && strcmp(ip, szerelok[j].ip_cim)!=0)
		{
			j++;
		}
		if (j==N)
		{
			gepek[i].szerelo=0;
		}
		else
		{
			gepek[i].szerelo=&szerelok[j];
		}
	}
	
	//gepek kiirasa
	for (i=0; i<gepek_szama; i++)
	{
		printf("A(z) %d. gep:\n", i);
		printf("\tId: %u, gyartasi ev: %d, szerelesek: %u.\n", gepek[i].id, gepek[i].gyartasi_ev, gepek[i].szereles_szam);
		if (gepek[i].szerelo!=0)
		{
			printf("\tA szerelo: IP: %s, nev: %s\n", gepek[i].szerelo->ip_cim, gepek[i].szerelo->nev);
		}
		else
		{
			printf("Nincs hozzarendelt szerelo.\n");
		}
	}
	
	//legidosebb gep
	Computer *legidosebb=legidosebbGep(gepek, gepek_szama);
	if (legidosebb!=0)
	{
		printf("\nA legidosebb gep adatai:\n");
		printf("\tId: %u, gyartasi ev: %d, szerelesek: %u.\n", legidosebb->id, legidosebb->gyartasi_ev, legidosebb->szereles_szam);
		if (legidosebb->szerelo!=0)
		{
			printf("\tA szerelo: IP: %s, nev: %s\n", legidosebb->szerelo->ip_cim, legidosebb->szerelo->nev);
		}
		else
		{
			printf("Nincs hozzarendelt szerelo.\n");
		}
	}
	else
	{
		printf("Problema: mintha nem lenne elem a tombben.\n");
	}
	
	//szereles
	printf("\nKerek egy IP-cimet:\n");
	scanf("%s", ip);
	i=0;
	while (i<N && strcmp(ip, szerelok[i].ip_cim)!=0)
	{
		i++;
	}
	if (i==N)
	{
		printf("Nincs szerelo a megadott cimen.\n");
	}
	else
	{
		int szamol=szerel(gepek, gepek_szama, &szerelok[i]);
		printf("A szerelo megszerelt %d darab gepet.\n", szamol);
	}
	
	free(gepek);
	return 0;
}
