/**********************************************************************************************
* 7.5.2 Feladat                                                                               *
*   Olvasson be egy egész számot billentyűzetről                                              *
*   Foglaljon helyet annyi egész számnak, amennyi az előzőleg beolvasott szám értéke          *
*   Olvasson be és tároljon el annyi egész számot, amennyi az előzőleg beolvasott szám értéke *
*   Írassa ki a beolvasott számokat                                                           *
*   Szabadítsa fel a lefoglalt memóriaterületet                                               *
**********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int meret;
	int *tomb;
	printf("Kerem a tomb meretet:\n");
	scanf("%d", &meret);
	tomb=(int*)malloc(sizeof(int)*meret);
	printf("Kerek %d darab szamot:\n", meret);
	int i;
	for (i=0; i<meret; i++)
	{
		scanf("%d", &tomb[i]);
	}
	printf("A beolvasott szamok\n");
	for (i=0; i<meret; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	free(tomb);
	return 0;
}

