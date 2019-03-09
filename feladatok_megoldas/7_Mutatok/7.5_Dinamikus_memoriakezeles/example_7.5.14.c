/*************************************************************************************
* 7.5.14 Feladat                                                                     *
*   Készítsen egy programot, ami számokat kér be addig, amíg a bekért szám nem nulla *
*   A bekért számokat (a nulla kivételével) tárolja el egy tömbben                   *
*   A tömb mérete mindig pontosan akkora legyen, amennyi beolvasott számot tárol     *
*   A beolvasás után irassa ki a tömb elemeit                                        *
*   Keresse meg és közölje a tömb legkisebb elemét                                   *
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int szam;
	int i, meret=0;
	int *tomb=0;
	do
	{
		printf("Kerem az ujabb szamot:\n");
		scanf("%d", &szam);
		if (szam!=0)
		{
			if (meret==0)
			{
				tomb=(int*)malloc(sizeof(int));
				tomb[0]=szam;
				meret++;
			}
			else
			{
				int *seged=(int*)malloc(sizeof(int)*(meret+1));
				for (i=0; i<meret; i++)
				{
					seged[i]=tomb[i];
				}
				seged[meret]=szam;
				free(tomb);
				tomb=seged;
				meret++;
			}
		}
	} while (szam!=0);
	
	//kiiras
	printf("A tomb elemei:\n");
	for (i=0; i<meret; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	
	//minimum
	int min_idx=0;
	for (i=1; i<meret; i++)
	{
		if (tomb[min_idx]>tomb[i])
		{
			min_idx=i;
		}
	}
	printf("A tomb legkisebb eleme: %d (index: %d).\n", tomb[min_idx], min_idx);
	
	free(tomb);
	return 0;
}
