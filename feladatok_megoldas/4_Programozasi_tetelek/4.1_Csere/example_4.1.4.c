/*****************************************************************************
* 4.1.4 Feladat                                                              *
*   Olvasson be egy hételemű tömböt                                          *
*   Újabb tömb felhasználása nélkül fordítsa meg a tömb elemeinek sorrendjét *
*   Írassa ki a tömb elemeit                                                 *
*****************************************************************************/

#include <stdio.h>

int main()
{
	int tomb[7];
	int i;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<7; i++)
	{
		scanf("%d", &tomb[i]);
	}
	int temp;
	for (i=0; i<3; i++) // a kozepso elemet nem kell megcserelni onmagaval
	{
		temp=tomb[i];
		tomb[i]=tomb[6-i];
		tomb[6-i]=temp;
	}
	printf("A tomb elemei forditva: ");
	for (i=0; i<7; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	return 0;
}
