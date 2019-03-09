/**************************************************************************************************
* 7.5.15 Feladat                                                                                  *
*   Készítsen egy programot, ami számokat kér be addig, amíg a bekért szám nem nulla              *
*   A bekért számokat (a nulla kivételével) tárolja el egy tömbben                                *
*   A tömb mérete kezdetben 5                                                                     *
*   Ha a beolvasott számok száma bármikor meghaladja a tömb méretét, növelje a tömb méretét öttel *
*   A beolvasás után irassa ki a tömb elemeit                                                     *
**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int szam;
	int i, meret=5, darab=0;
	int *tomb=(int*)malloc(sizeof(int)*meret);
	do
	{
		printf("Kerem az ujabb szamot:\n");
		scanf("%d", &szam);
		if (szam!=0)
		{
			if (darab<meret)
			{
				tomb[darab]=szam;
				darab++;
			}
			else
			{
				int *seged=(int*)malloc(sizeof(int)*(meret+5));
				for (i=0; i<darab; i++)
				{
					seged[i]=tomb[i];
				}
				seged[darab]=szam;
				free(tomb);
				tomb=seged;
				darab++;
				meret+=5;
			}
		}
	} while (szam!=0);
	
	//kiiras
	printf("A tomb elemei:\n");
	for (i=0; i<darab; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	
	free(tomb);
	return 0;
}
