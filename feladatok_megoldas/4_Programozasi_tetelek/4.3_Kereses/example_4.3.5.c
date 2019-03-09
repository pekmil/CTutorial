/***********************************************************************************************************************************************************
* 4.3.5 Feladat(!)                                                                                                                                         *
*   Olvasson be egy tízelemű tömböt                                                                                                                        *
*   Írassa ki a képernyőre a tömbben szereplő értékek legelső előfordulásának helyét. Minden értékhez csak egyszer jelenítse meg az előfordulásának helyét *
***********************************************************************************************************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb[N];
	int i, j;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	for (i=0; i<N; i++)
	{
		// megkeressuk az elso elofordulast, ha az nem a mostani, akkor nem irjuk ki
		j=0;
		while (j<i && tomb[j]!=tomb[i]) // lehetne j<N is, de ha j==i, akkor a feltetel masodik resze miatt ugyis megall
			j++;
		if (j==i)
			printf("A(z) %d szam elso elofordulasi helye a tombben a(z) %d indexen talalhato.\n", tomb[i], i);
	}
	return 0;
}
