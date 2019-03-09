/*****************************************************************************************************
* 4. Kis zárthelyi példa                                                                             *
*   Készítsen egy függvényt amely egy számokat tartalmazó tömböt és annak méretét kapja paraméterül. *
*     A függvényben keresse meg a tömbben található legkisebb értéket.                               *
*     A függvény eredményül adja vissza a megtalált értéket.                                         *
*   Hozzon létre egy tízelemű, számokat tároló tömböt, és olvassa be az elemeit.                     *
*   Használja a függvényt a feltöltött tömbön, majd jelenítse meg az eredményt.                      *
*****************************************************************************************************/

#include <stdio.h>

#define N 10

int legkisebb(int tomb[], int meret)
{
	int i=0;
	int min_idx=0;
	for (i=1; i<meret; i++)
	{
		if (tomb[i]<tomb[min_idx])
		{
			min_idx=i;
		}
	}
	return tomb[min_idx];
}

int main()
{
	int tomb[N];
	int i=0;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	printf("A tomb legkisebb eleme: %d\n", legkisebb(tomb, N));
	return 0;
}
