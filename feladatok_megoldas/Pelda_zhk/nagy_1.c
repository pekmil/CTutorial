/*************************************************************************************************************************************************************************
* 1. Nagy zárthelyi példa                                                                                                                                                *
* Alapfeladat                                                                                                                                                            *
*   Hozza létre a következő struktúrát:                                                                                                                                  *
*     Hűtőszekrény                                                                                                                                                       *
*       Energiajele: A, B, C, D, vagy E (karakter)                                                                                                                       *
*       Térfogat: lebegőpontos szám                                                                                                                                      *
*       Tárolt ételek száma: előjel nélküli egész szám                                                                                                                   *
*   Olvassa be 7 hűtő adatait.                                                                                                                                           *
*   Jelenítse meg a beolvasott hűtők adatait.                                                                                                                            *
*                                                                                                                                                                        *
* Feladat (1 pont)                                                                                                                                                       *
*   Olvasson be egy energiajelet, és írassa ki azon hűtők számát, amelyek azonos energiabesorolásúak.                                                                    *
*                                                                                                                                                                        *
* Feladat (1 pont)                                                                                                                                                       *
*   Olvasson be egy energiajelet és mondja meg, van-e azonos energiajelű hűtő.                                                                                           *
*                                                                                                                                                                        *
* Feladat (1 pont)                                                                                                                                                       *
*   Egészítse ki a struktúrát egy ötelemű tömbbel, amely tárolja, hogy a hűtő polcain hány ételt tárolunk. (egészítse ki az alapfeladathoz írt beolvasást és kiírást is) *
*   Jelenítse meg azon hűtő adatait, melynek harmadik polcán a legkevesebb étel található. (ha több van, akkor csak az egyikét).                                         *
*                                                                                                                                                                        *
* Feladat (1 pont)                                                                                                                                                       *
*   Rendezze a hűtőket térfogatuk szerinti növekvő sorrendbe.                                                                                                            *
*                                                                                                                                                                        *
* Feladat (1 pont)                                                                                                                                                       *
*   Hozza létre a következő struktúrát:                                                                                                                                  *
*     Fagyasztó                                                                                                                                                          *
*       Hőfok: lebegőpontos szám                                                                                                                                         *
*       Tárolt ételek száma: egész szám                                                                                                                                  *
*   Egészítse ki a hűtő struktúrát úgy, hogy tárolja a hűtőben lévő fagyasztó adatait (egészítse ki az alapfeladathoz írt beolvasást és kiírást is)                      *
*   Olvasson be egy számot, és írassa ki azon hűtők térfogatát, amelyek fagyasztójában ennél több ételt tárolunk.                                                        *
*************************************************************************************************************************************************************************/

#include <stdio.h>

#define N 7
#define M 5

// Ötödik feladathoz
typedef struct _fagyaszto
{
	float hofok;
	int etelek;
} Fagyaszto;

typedef struct _huto
{
	char energiajel;
	float terfogat;
	unsigned int etelek_szama;
	unsigned int polcok[M]; // Harmadik feladathoz
	Fagyaszto fagy; // Ötödik feladathoz
} Huto;

int main()
{
	// Alapfealadat
	Huto hutok[N];
	int i=0, j=0;
	for (i=0; i<N; i++)
	{
		printf("Kerem az %d. huto adatait (energia, terfogat, etelek):\n", i);
		scanf(" %c %f %u", &hutok[i].energiajel, &hutok[i].terfogat, &hutok[i].etelek_szama); // A scanf esetében a %c trükkösen működik, hiszen bármilyen karakter, mint a szóköz, \n, \t, mind bele tartozik.
																																													// Szerencsére a %c elé tett szóköz segítségével az előző beolvasás végéről maradt whitespace karakterek figyelmen kívül hagyahatóak.
		// Beolvasás a harmadik feladathoz
		printf("%d. huto polcai?\n", i);
		for (j=0; j<M; j++)
		{
			scanf("%u", &hutok[i].polcok[j]);
		}
		
		// Beolvasás az ötödik feladathoz
		printf("Fagyaszto adatai? (hofok, etelek)\n");
		scanf("%f %d", &hutok[i].fagy.hofok, &hutok[i].fagy.etelek);
	}
	for (i=0; i<N; i++)
	{
		printf("Az %d. huto energiajele: %c, tefogata: %f, etelek szama: %u\n", i, hutok[i].energiajel, hutok[i].terfogat, hutok[i].etelek_szama);
		// Kiírás a harmadik feladathoz
		printf("\tA polcok adatai:");
		for (j=0; j<M; j++)
		{
			printf(" %d", hutok[i].polcok[j]);
		}
		printf("\n");
		// Kiírás az ötödik feladathoz
		printf("A fagyaszto adatai: hofoK: %f, etelek: %d\n", hutok[i].fagy.hofok, hutok[i].fagy.etelek);
	}
	
	// Első feladat
	char ejel;
	printf("Kerek egy energiajelet:\n");
	scanf(" %c", &ejel); // A %c előtt itt is látható a szóköz, hogy előző beolvasásból megmaradt whitespace (szóköz, \n, \t) karakterek ne zavarjanak.
	int szamol=0;
	for (i=0; i<N; i++)
	{
		if (hutok[i].energiajel==ejel)
		{
			szamol++;
		}
	}
	printf("%d darab ilyen energiajelu huto van.\n", szamol);
	
	// Második feladat
	char ejel2;
	printf("Kerek egy energiajelet:\n");
	scanf(" %c", &ejel2);
	i=0;
	while (i<N && hutok[i].energiajel!=ejel2)
	{
		i++;
	}
	if (i==N)
	{
		printf("Nincs ilyen energiajelu huto.\n");
	}
	else
	{
		printf("Van ilyen energiajelu huto.\n");
	}
	
	// Harmadik feladat
	int min_idx=0;
	for (i=1; i<N; i++)
	{
		if (hutok[i].polcok[2]<hutok[min_idx].polcok[2])	// Igen a feladat megfogalmazása nem feltétlenül egyértelmű. A harmadik polc jelentheti a 2. indexet, mert az sorrendben a harmadik.
																											// De jelenthei a 3. indexet is, mert az szó szerint a harmadik. Jelenleg bármelyik elfogadható, jelen megoldásban a 2. indexet jelenti.
		{
			min_idx=i;
		}
	}
	printf("A huto a legkevesebb etelt tartalmazo harmadik polccal:\n");
	printf("energia: %c, terfogat: %f, etelek: %u\n", hutok[min_idx].energiajel, hutok[min_idx].terfogat, hutok[min_idx].etelek_szama);
	printf("A polcok adatai:");
	for (j=0; j<M; j++)
	{
		printf(" %d", hutok[min_idx].polcok[j]);
	}
	printf("\n");
	
	// Negyedik feladat
	for (i=0; i<N-1; i++)
	{
		int mini=i;
		for (j=i+1; j<N; j++)
		{
			if (hutok[j].terfogat<hutok[mini].terfogat)
			{
				mini=j;
			}
		}
		if (mini!=i)
		{
			Huto csere=hutok[i];
			hutok[i]=hutok[mini];
			hutok[mini]=csere;
		}
	}
	for (i=0; i<N; i++)
	{
		printf("Az %d. huto energiajele: %c, tefogata: %f, etelek szama: %u\n", i, hutok[i].energiajel, hutok[i].terfogat, hutok[i].etelek_szama);
		// Kiírás a harmadik feladathoz
		printf("\tA polcok adatai:");
		for (j=0; j<M; j++)
		{
			printf(" %d", hutok[i].polcok[j]);
		}
		printf("\n");
		// Kiírás az ötödik feladathoz
		printf("A fagyaszto adatai: hofoK: %f, etelek: %d\n", hutok[i].fagy.hofok, hutok[i].fagy.etelek);
	}
	
	// Ötödik feladat
	int etelek;
	printf("Kerem az etelek szamat:\n");
	scanf("%d", &etelek);
	for (i=0; i<N; i++)
	{
		if (hutok[i].fagy.etelek>etelek)
		{
			printf("Tobb etelt tarolunk, terfogat: %f\n", hutok[i].terfogat);
		}
	}
	
	return 0;
}
