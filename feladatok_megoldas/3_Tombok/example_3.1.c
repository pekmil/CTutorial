/**************************************************************
* 3.1 Feladat                                                 *
*   Hozzon létre egy ötelemű tömböt                           *
*   Olvasson be egymás után öt számot és tárolja el a tömbben *
*   Írassa ki a tömb elemeit                                  *
**************************************************************/

#include <stdio.h>

int main()
{
	int tomb[5];
	int i;
	for (i=0; i<5; i++)
	{
		scanf("%d", &tomb[i]);
	}
	for (i=0; i<5; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	return 0;
}
