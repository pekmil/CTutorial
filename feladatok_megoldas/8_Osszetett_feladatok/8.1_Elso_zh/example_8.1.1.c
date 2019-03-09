/*************************************************************************************************************************************
* 8.1.1 Feladat                                                                                                                      *
*   Írjon egy programot, amely társasházak adatait tudja tárolni                                                                     *
*   Készítsen egy struktúrát, amely egy lakás adatait tárolja, és a következő adattagokkal rendelkezik:                              *
*     Alapterület                                                                                                                    *
*     Szobák száma                                                                                                                   *
*     Átlagos gázfogyasztás                                                                                                          *
*   Készítsen egy társasházat reprezentáló struktúrát a következő adattagokkal:                                                      *
*     A társasházban található 6 lakás                                                                                               *
*     Kényelmi besorolás                                                                                                             *
*     Gondnok életkora                                                                                                               *
*   A program olvassa be és tárolja el három társasház adatait.                                                                      *
*   Keresse meg, és közölje a legidősebb gondnok által felügyelt társasházat                                                         *
*   Írja ki, hogy az előbb megkeresett társasházban melyik a legkisebb alapterületű lakás                                            *
*   Kérjen be egy újabb számot, majd minden társasházhoz írassa ki, az adott társasházban mennyi lakásnak van legalább ennyi szobája *
*   Keresse meg, hogy az összes társasház összes lakása közül melyik a legnagyobb alapterületű.                                      *
*   Minden társasházon belül rendezze a lakásokat szobák száma szerinti növekvő sorrendbe.                                           *
*   Írja ki az összes adatot.                                                                                                        *
*************************************************************************************************************************************/

#include <stdio.h>

#define N 6
#define M 3

typedef struct flat
{
	unsigned int terulet, szobak;
	float gazfogy;
} Flat;

typedef struct house
{
	Flat lakasok[N];
	int kenyelem;
	unsigned int gondnok;
} House;

int main()
{
	House hazak[M];
	int i, j;
	
	// bekeres
	for (i=0; i<M; i++)
	{
		printf("Kerem a(z) %d. haz adatait:\n", i);
		for (j=0; j<N; j++)
		{
			printf("Kerem a(z) %d. lakas adatait (terulet, szobak, gazfogy):\n", j);
			scanf("%u %u %f", &hazak[i].lakasok[j].terulet, &hazak[i].lakasok[j].szobak, &hazak[i].lakasok[j].gazfogy);
		}
		printf("Kerem a kenyelmi besorolast es a gondnok eletkorat:\n");
		scanf("%d %u", &hazak[i].kenyelem, &hazak[i].gondnok);
	}
	
	// kiiras
	for (i=0; i<M; i++)
	{
		printf("A(z) %d. haz adatait:\n", i);
		for (j=0; j<N; j++)
		{
			printf("\tA(z) %d. lakas adatait: t: %u, sz: %u, g: %.2f\n", j, hazak[i].lakasok[j].terulet, hazak[i].lakasok[j].szobak, hazak[i].lakasok[j].gazfogy);
		}
		printf("Kenyelem: %d, gondnok: %u\n", hazak[i].kenyelem, hazak[i].gondnok);
	}
	
	// legidosebb gondnok
	int max_gond=0;
	for (i=1; i<M; i++)
	{
		if (hazak[i].gondnok>hazak[max_gond].gondnok)
		{
			max_gond=i;
		}
	}
	printf("A legidosebb gondnok altal felugyelt lakas: %d (eletkor: %u)\n", max_gond, hazak[max_gond].gondnok);
	
	// itt a legkisebb lakas
	int min_ter=0;
	for (i=1; i<N; i++)
	{
		if (hazak[max_gond].lakasok[i].terulet<hazak[max_gond].lakasok[min_ter].terulet)
		{
			min_ter=i;
		}
	}
	printf("Itt a legkisebb lakas: %d (terulet: %u)\n", min_ter, hazak[max_gond].lakasok[min_ter].terulet);
	
	// szobak szama
	unsigned int sz_szam;
	printf("Kerek egy uj szamot:\n");
	scanf("%u", &sz_szam);
	for (i=0; i<M; i++)
	{
		int szamol=0;
		for (j=0; j<N; j++)
		{
			if (hazak[i].lakasok[j].szobak>=sz_szam)
			{
				szamol++;
			}
		}
		printf("A(z) %d. hazban %d lakas van legalabb ennyi szobaval.\n", i, szamol);
	}
	
	// legnagyobb lakas mind kozul
	int max_haz=0, max_lakas=0;
	for (i=0; i<M; i++) // mivel itt ket index van, itt nem lehet megcsinalni, hogy egytol indul, mert az nem csak a 0,0 esetet hagyna ki
	{
		for (j=0; j<N; j++)
		{
			if (hazak[i].lakasok[j].terulet>hazak[max_haz].lakasok[max_lakas].terulet)
			{
				max_haz=i;
				max_lakas=j;
			}
		}
	}
	printf("A legnagyobb teruletu lakas mind kozul: %d. haz, %d. lakas (terulet: %u)\n", max_haz, max_lakas, hazak[max_haz].lakasok[max_lakas].terulet);
	
	// lakasok rendezese
	for (i=0; i<M; i++)
	{
		int k;
		Flat csere;
		for (j=0; j<N-1; j++)
		{
			int min_szoba=j;
			for (k=j+1; k<N; k++)
			{
				if (hazak[i].lakasok[k].szobak<hazak[i].lakasok[min_szoba].szobak)
				{
					min_szoba=k;
				}
			}
			if (min_szoba!=j)
			{
				csere=hazak[i].lakasok[j];
				hazak[i].lakasok[j]=hazak[i].lakasok[min_szoba];
				hazak[i].lakasok[min_szoba]=csere;
			}
		}
	}
	
	// kiiras ismet
	for (i=0; i<M; i++)
	{
		printf("A(z) %d. haz adatait:\n", i);
		for (j=0; j<N; j++)
		{
			printf("\tA(z) %d. lakas adatait: t: %u, sz: %u, g: %.2f\n", j, hazak[i].lakasok[j].terulet, hazak[i].lakasok[j].szobak, hazak[i].lakasok[j].gazfogy);
		}
		printf("Kenyelem: %d, gondnok: %u\n", hazak[i].kenyelem, hazak[i].gondnok);
	}
	
	return 0;
}
