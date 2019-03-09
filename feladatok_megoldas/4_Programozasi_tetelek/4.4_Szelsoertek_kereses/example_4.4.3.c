/************************************************************************************************************
* 4.4.3 Feladat                                                                                             *
*   Hozzon létre egy tízelemű tömböt és töltse fel értékekkel                                               *
*   Keresse meg és írassa ki a legnagyobb érték helyét a tömbben                                            *
*   Amennyiben a legkisebb érték többször is szerepel a tömbben, az első előfordulásának a helyét írassa ki *
************************************************************************************************************/

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
	int max_idx=0;
	for (i=1; i<N; i++)
	{
		if (tomb[i]>tomb[max_idx])
			max_idx=i;
	}
	printf("A tomb legnagyobb eleme: %d (index: %d).\n", tomb[max_idx], max_idx);
	return 0;
}
