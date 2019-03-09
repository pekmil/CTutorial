/******************************************************************
* 7.2.5 Feladat                                                   *
*   Hozzon létre egy tízelemű tömböt                              *
*   Hozzon létre egy mutatót, amely a tömbre mutat                *
*   Olvassa be a tömb elemeit billentyűzetről a mutatón keresztül *
*   Jelenítse meg a tömb elemeit a mutatón keresztül              *
******************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb[N];
	int i, *tombp=tomb;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", tombp+i); // persze lehetne &tombp[i] is
	}
	printf("A tomb elemei:\n");
	for (i=0; i<N; i++)
	{
		printf("%d ", *(tombp+i)); // persze lehetne tombp[i] is
	}
	printf("\n");
	return 0;
}
