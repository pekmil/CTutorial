/**********************************************************************************************************************************************************************************
* 6.10 Feladat                                                                                                                                                                    *
*   Írja meg a következő függvényeket:                                                                                                                                            *
*   Készítsen egy függvényt, amely egy tömböt és egy méretet kap paraméterül és feltölti a billentyűzetről beolvasott számokkal                                                   *
*   Készítsen egy függvényt, amely egy tömböt és egy méretet kap paraméterül és megjeleníti a tömbben lévő értékeket                                                              *
*   Készítsen egy függvényt, amely egy számot, egy tömböt és egy pozíciót kap paraméterül és az értéket a tömb megfelelő pozíciójában tárolja                                     *
*   Készítsen egy függvényt, amely egy tömböt és egy méretet kap paraméterül és visszaadja eredményül a tömb legnagyobb elemét                                                    *
*   Készítsen egy függvényt, amely egy tömböt és egy méretet kap paraméterül és visszaadja eredményül a tömb legkisebb elemét                                                     *
*   Készítsen egy függvényt, amely egy tömböt és egy méretet kap paraméterül és növekvő sorrendbe rendezi a tömb elemeit                                                          *
*   Készítsen egy függvényt, amely egy tömböt és egy méretet kap paraméterül és csökkenő sorrendbe rendezi a tömb elemeit                                                         *
*   Írjon egy programot, amely beolvas egy tízelemű tömböt, majd egy menüt jelenít meg. A menü biztosítsa a fenti függvényekben biztosított funkcionalitásokat a következőképpen: *
*     1 Új érték                                                                                                                                                                  *
*     2 Tömb minden elemének újra beolvasása                                                                                                                                      *
*     3 Szélsőérték                                                                                                                                                               *
*     4 Rendezés                                                                                                                                                                  *
*     5 Kilépés                                                                                                                                                                   *
*   A kettes és hármas menüpontok választása után biztosítson egy újabb választást a maximum/minimum kereséshez, valamint a növekvő vagy csökkenő sorrendbe történő rendezéshez   *
**********************************************************************************************************************************************************************************/

#include <stdio.h>

#define N 10

void beolvas(int tomb[], int meret)
{
	printf("Kerem az elemeket (%d darab):\n", meret);
	int i;
	for (i=0; i<meret; i++)
	{
		scanf("%d", &tomb[i]);
	}
}

void kiir(int tomb[], int meret)
{
	printf("A tomb elemei:\n");
	int i;
	for (i=0; i<meret; i++)
	{
		printf("%d", tomb[i]);
		if (i<meret-1)
			printf(" ");
		else
			printf("\n");
	}
}

void elemet_beir(int tomb[], int index, int szam) // ez a fuggveny jelenleg feltetelezi, hogy a megadott index helyes
{
	tomb[index]=szam;
}

int legnagyobb(int tomb[], int meret)
{
	int max=tomb[0];
	int i;
	for (i=1; i<meret; i++)
	{
		if (max<tomb[i])
			max=tomb[i];
	}
	return max;
}

int legkisebb(int tomb[], int meret)
{
	int min=tomb[0];
	int i;
	for (i=1; i<meret; i++)
	{
		if (min>tomb[i])
			min=tomb[i];
	}
	return min;
}

void novekvo(int tomb[], int meret)
{
	int min_idx;
	int i, j;
	int csere;
	for (i=0; i<meret-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<meret; j++)
		{
			if (tomb[min_idx]>tomb[j])
				min_idx=j;
		}
		if (min_idx!=i)
		{
			csere=tomb[i];
			tomb[i]=tomb[min_idx];
			tomb[min_idx]=csere;
		}
	}
}

void csokkeno(int tomb[], int meret)
{
	int max_idx;
	int i, j;
	int csere;
	for (i=0; i<meret-1; i++)
	{
		max_idx=i;
		for (j=i+1; j<meret; j++)
		{
			if (tomb[max_idx]<tomb[j])
				max_idx=j;
		}
		if (max_idx!=i)
		{
			csere=tomb[i];
			tomb[i]=tomb[max_idx];
			tomb[max_idx]=csere;
		}
	}
}

int main()
{
	int tomb[N];
	beolvas(tomb, N);
	int menupont;
	int almenupont;
	do
	{
		printf("Valasszon menupontot:\n");
		printf("  1 Uj ertek\n");
		printf("  2 Minden elem bekerese ujra\n");
		printf("  3 Szelsoertek keresese\n");
		printf("  4 Rendezes\n");
		printf("  5 Kilepes\n");
		scanf("%d", &menupont);
		if (menupont==1)
		{
			int ertek, index;
			printf("Adja meg az uj erteket:\n");
			scanf("%d", &ertek);
			printf("Melyik indexre keruljon?\n");
			scanf("%d", &index);
			if (0<=index && index<N) // mivel a fuggvenyben nem ellenorizzuk, itt lehet hogy nem artana
			{
				elemet_beir(tomb, index, ertek);
				kiir(tomb, N);
			}
			else
			{
				printf("Az index ervenytelen.\n");
			}
		}
		else if (menupont==2)
		{
			beolvas(tomb, N);
		}
		else if (menupont==3)
		{
			printf("Minimumot vagy maximumot szeretne keresni?\n");
			printf("  1. Minimum\n");
			printf("  2. Maximum\n");
			scanf("%d", &almenupont);
			if (almenupont==1)
			{
				printf("A tomb legkisebb eleme: %d.\n", legkisebb(tomb, N));
			}
			else if (almenupont==2)
			{
				printf("A tomb legnagyobb eleme: %d.\n", legnagyobb(tomb, N));
			}
		}
		else if (menupont==4)
		{
			printf("Csokkeno vagy novekvo sorrendbe szeretne rendezni?\n");
			printf("  1. Csokkeno\n");
			printf("  2. Novekvo\n");
			scanf("%d", &almenupont);
			if (almenupont==1)
			{
				csokkeno(tomb, N);
				kiir(tomb, N);
			}
			else if (almenupont==2)
			{
				novekvo(tomb, N);
				kiir(tomb, N);
			}
		}
	} while (menupont!=5);
	return 0;
}
