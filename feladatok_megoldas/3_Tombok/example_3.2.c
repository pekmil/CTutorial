/**************************************************************
* 3.2 Feladat                                                 *
*   Hozzon létre egy hételemű tömböt                          *
*   Töltse fel a tömböt billentyűzetről beolvasott értékekkel *
*   Szorozza meg a tömb minden elemét annak indexével         *
*   Írassa ki a tömb elemeit                                  *
**************************************************************/

#include <stdio.h>

int main()
{
	int tomb[7];
	int i;
	for (i=0; i<7; i++)
	{
		scanf("%d", &tomb[i]);
	}
	for (i=0; i<7; i++)
	{
		tomb[i]*=i;
	}
	for (i=0; i<7; i++)
	{
		printf("%d  ", tomb[i]);
	}
	printf("\n");
	return 0;
}
