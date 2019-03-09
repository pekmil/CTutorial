/*****************************************************************************
* 4.1.3 Feladat                                                              *
*   Olvasson be egy hatelemű tömböt                                          *
*   Újabb tömb felhasználása nélkül fordítsa meg a tömb elemeinek sorrendjét *
*   Írassa ki a tömb elemeit                                                 *
*****************************************************************************/

#include <stdio.h>

int main()
{
	int tomb[6];
	int i;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<6; i++)
	{
		scanf("%d", &tomb[i]);
	}
	int temp;
	for (i=0; i<3; i++)
	{
		temp=tomb[i];
		tomb[i]=tomb[5-i];
		tomb[5-i]=temp;
	}
	printf("A tomb elemei forditva: ");
	for (i=0; i<6; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	return 0;
}
