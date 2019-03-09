/*****************************************************************************
* 4.1.5 Feladat                                                              *
*   Olvasson be egy N tömböt                                                 *
*   Újabb tömb felhasználása nélkül fordítsa meg a tömb elemeinek sorrendjét *
*   Írassa ki a tömb elemeit                                                 *
*****************************************************************************/

#include <stdio.h>

#define N 7

int main()
{
	int tomb[N];
	int i;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	int temp;
	for (i=0; i<N/2; i++) // a kozepso elemet nem kell megcserelni onmagaval
	{
		temp=tomb[i];
		tomb[i]=tomb[N-1-i];
		tomb[N-1-i]=temp;
	}
	printf("A tomb elemei forditva: ");
	for (i=0; i<N; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	return 0;
}
