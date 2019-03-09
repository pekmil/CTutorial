/**************************************************************************************************************
* 4.4.2 Feladat                                                                                               *
*   Hozzon létre egy tízelemű tömböt és töltse fel értékekkel                                                 *
*   Keresse meg és írassa ki a legkisebb érték helyét a tömbben                                               *
*   Amennyiben a legkisebb érték többször is szerepel a tömbben, az utolsó előfordulásának a helyét írassa ki *
**************************************************************************************************************/

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
		if (tomb[i]<=tomb[min_idx])
			min_idx=i;
	}
	printf("A tomb legkisebb eleme: %d (index: %d).\n", tomb[min_idx], min_idx);
	return 0;
}
