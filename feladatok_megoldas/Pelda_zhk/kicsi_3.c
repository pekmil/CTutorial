/***********************************************************************************************************
* 3. Kis zárthelyi példa                                                                                   *
*   Hozzon létre egy struktúrát, amely egy sportoló adatait tárolja:                                       *
*     Magasság centiméterben (előjel nélküli egész)                                                        *
*     Mez száma (előjel nélküli egész)                                                                     *
*     Dobóátlag százalékban (lebegőpontos szám)                                                            *
*   Hozzon létre egy tízelemű, sportolókat tároló tömböt, és olvassa be az elemeit.                        *
*   Olvasson be egy újabb előjel nélküli egész számot (mezszám).                                           *
*   Állapítsa meg, hogy a beolvasott mezszám  szerepel-e a tömbben, és ha igen, írja ki a játékos adatait. *
*   Írja ki a tömb elemeit.                                                                                *
***********************************************************************************************************/

#include <stdio.h>

#define N 10 // Itt már tényleg jó, ha könnyen szeretnénk kevesebb elemmel tesztelni

typedef struct _jatekos
{
	unsigned int magassag, mezszam;
	float doboatlag;
} Jatekos;

int main()
{
	Jatekos tomb[N];
	int i=0;
	for (i=0; i<N; i++)
	{
		printf("%d. jatekos magassag:\n", i);
		scanf("%u", &tomb[i].magassag);
		printf("%d. jatekos mezszam:\n", i);
		scanf("%u", &tomb[i].mezszam);
		printf("%d. jatekos doboatlag:\n", i);
		scanf("%f", &tomb[i].doboatlag);
	}
	
	unsigned int keresett_mez;
	printf("Kerem a keresett mezszamot:\n");
	scanf("%u", &keresett_mez);
	
	i=0;
	while (i<N && keresett_mez!=tomb[i].mezszam)
	{
		i++;
	}
	if (i==N)
	{
		printf("A keresett mez nem szerepel a tombben\n");
	}
	else
	{
		printf("A keresett mez a %d. szamu jatekoson talalhato\n", i);
	}
	
	for (i=0; i<N; i++)
	{
		printf("%d. jatekos magassaga: %u\n", i, tomb[i].magassag);
		printf("\tmezszama: %u\n", tomb[i].mezszam);
		printf("\tdoboatlaga: %.3f\n", tomb[i].doboatlag);
	}
	
	return 0;
}
