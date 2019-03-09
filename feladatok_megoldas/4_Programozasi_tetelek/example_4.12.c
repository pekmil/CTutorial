/****************************************************************************************************************************
* 4.12 Feladat(!)                                                                                                           *
*   Írjon programot, amely létrehoz egy tízelemű tömböt, majd elindít egy menüt a következő opciókkal:                      *
*     Következő szám beolvasása (10 szám után nem csinál semmit)                                                            *
*     Egy szám törlése (ekkor egy érvényes index megadása után a program minden az utánit egyel kisebb indexű helyre másol) *
*     Kilépés                                                                                                               *
****************************************************************************************************************************/

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
		printf("  2. Egy szam torlese\n");
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
				int index;
				printf("A tombben levo elemek szama: %d. Kerem adja meg a torlendo indexet: ", darab_eddig);
				scanf("%d", &index);
				if (index<0 || index>=darab_eddig)
				{
					printf("A megadott index ervenytelen.\n");
				}
				else
				{
					// tovabbi elemek elore csusztatasa
					int j;
					for (j=index; j<darab_eddig-1; j++)
					{
						tomb[j]=tomb[j+1];
					}
					darab_eddig--; // csokkent az elemek szama
					printf("A tomb jelenlegi elemei:\n");
					for (i=0; i<darab_eddig; i++)
					{
						printf("%d ", tomb[i]);
					}
					printf("\n");
				}
			}
		}
	} while (menupont!=3);
	return 0;
}
