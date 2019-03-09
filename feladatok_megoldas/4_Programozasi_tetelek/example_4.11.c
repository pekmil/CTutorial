/*******************************************************************************************************
* 4.11 Feladat(!)                                                                                      *
*   Írjon programot, amely létrehoz egy tízelemű tömböt, majd elindít egy menüt a következő opciókkal: *
*     Következő szám beolvasása (10 szám után nem csinál semmit)                                       *
*     Eddig beírt számok minimumának kiírása                                                           *
*     Kilépés                                                                                          *
*******************************************************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb[N];
	int i, darab_eddig=0;
	int menupont;
	do
	{
		printf("Kerem valasszon opciot:\n");
		printf("  1. Uj szam bevitele\n");
		printf("  2. Minimum keresese az eddigi szamokra\n");
		printf("  3. Kilepes\n");
		scanf("%d", &menupont);
		if (menupont==1)
		{
			if (darab_eddig<N)
			{
				printf("Kerem adja meg a szamot: ");
				scanf("%d", &tomb[darab_eddig++]);
			}
			else
			{
				printf("A tomb mar tele van.\n");
			}
			printf("A tomb jelenlegi elemei:\n");
			for (i=0; i<darab_eddig; i++)
			{
				printf("%d ", tomb[i]);
			}
			printf("\n");
		}
		else if (menupont==2)
		{
			if (darab_eddig==0)
			{
				printf("Meg nincs szam a tombben.\n");
			}
			else
			{
				int min_idx=0;
				for (i=1; i<darab_eddig; i++)
				{
					if (tomb[i]<tomb[min_idx])
						min_idx=i;
				}
				printf("A legkisebb elem: %d (index: %d).\n", tomb[min_idx], min_idx);
			}
		}
	} while (menupont!=3);
	return 0;
}
