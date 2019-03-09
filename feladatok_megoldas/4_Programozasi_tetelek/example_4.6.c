/*****************************************************************
* 4.6 Feladat                                                    *
*   Hozzon létre egy tízelemű tömböt és töltse fel értékekkel    *
*   Írassa ki a tömb legkisebb elemét                            *
*   Írassa ki, hogy a legkisebb elem hányszor szerepel a tömbben *
*****************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb[N];
	int i;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	int min_idx=0;
	for (i=1; i<N; i++)
	{
		if (tomb[i]<tomb[min_idx])
			min_idx=i;
	}
	printf("A tomb legkisebb eleme: %d (index: %d).\n", tomb[min_idx], min_idx);
	int darab=0;
	for (i=0; i<N; i++)
	{
		if (tomb[i]==tomb[min_idx])
			darab++;
	}
	printf("Az ertek %d-szer szerepel a tombben.\n", darab);
	return 0;
}
