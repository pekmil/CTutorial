/******************************************************************
* 7.2.6 Feladat                                                   *
*   Hozzon létre egy tízelemű tömböt                              *
*   Hozzon létre egy mutatót, amely a tömbre mutat                *
*   Olvassa be a tömb elemeit billentyűzetről a mutatón keresztül *
*   Rendezze a tömb elemeit növekvő sorrendbe a mutatón keresztül *
*   Jelenítse meg a tömb elemeit a mutatón keresztül              *
******************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb[N];
	int i, j, *tombp=tomb;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", tombp+i); // persze lehetne &tombp[i] is
	}
	int min_idx;
	int csere;
	for (i=0; i<N-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<N; j++)
		{
			if (tombp[j]<tombp[min_idx])
				min_idx=j;
		}
		if (min_idx!=i)
		{
			csere=tombp[i];
			tombp[i]=tombp[min_idx];
			tombp[min_idx]=csere;
		}
	}
	printf("A tomb elemei:\n");
	for (i=0; i<N; i++)
	{
		printf("%d ", *(tombp+i)); // persze lehetne tombp[i] is
	}
	printf("\n");
	return 0;
}
