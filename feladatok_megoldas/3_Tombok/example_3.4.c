/********************************************************************************
* 3.4 Feladat                                                                   *
*   Olvasson be egy ötelemű tömböt                                              *
*   Egy másik tömbben tárolja el a beolvasott tömb elemeit fordított sorrendben *
*   Írassa ki a második tömböt                                                  *
********************************************************************************/

#include <stdio.h>

int main()
{
	int tomb[5], forditott[5];
	int i;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<5; i++)
	{
		scanf("%d", &tomb[i]);
	}
	for (i=0; i<5; i++)
	{
		forditott[4-i]=tomb[i];
	}
	printf("Forditott sorrendben: ");
	for (i=0; i<5; i++)
	{
		printf("%d ", forditott[i]);
	}
	printf("\n");
	return 0;
}
