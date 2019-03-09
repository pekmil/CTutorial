/***************************************************************************************************************************************************************
* 7.2.1 Feladat                                                                                                                                                *
*   Olvasson be egy hatelemű tömböt, amely egész számokat tárol és töltse fel értékekkel                                                                       *
*   Hozzon létre egy 10 elemű tömböt, amely mutatókat tárol                                                                                                    *
*   Olvasson be tíz számot a képernyőről. Ha a szám szerepel a hatelemű tömbben, tárolja el annak a címét, ellenkező esetben tároljon el egy nullaértékű címet *
*   Jelenítse meg a 10 elemű tömb által mutatott értékeket és hozzájuk tartozó memóriacímeket                                                                  *
***************************************************************************************************************************************************************/

#include <stdio.h>

#define N 6
#define M 10

int main()
{
	int tomb[N], *ptomb[M];
	int i, j;
	int ertek;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	printf("Kerek meg %d szamot:\n", M);
	for (j=0; j<M; j++)
	{
		scanf("%d", &ertek);
		i=0;
		while (i<N && tomb[i]!=ertek)
			i++;
		if (i<N) // az elem szerepel a tombben, ekkor a cimet taroljuk
			ptomb[j]=&tomb[i];
		else // ha nem szerepel, akkor nullat
			ptomb[j]=0;
	}
	printf("A memoriatomb elemei:\n");
	for (j=0; j<M; j++)
	{
		printf("A cim: %p, ", ptomb[j]);
		if (ptomb[j]==0)
			printf("NULLPOINTER.\n");
		else
			printf("a mutatott ertek: %d.\n", *ptomb[j]);
	}
	return 0;
}
