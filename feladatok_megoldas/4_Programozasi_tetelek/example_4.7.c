/*********************************************************************************************
* 4.7 Feladat                                                                                *
*   Hozzon létre egy tízelemű tömböt és töltse fel értékekkel                                *
*   Olvasson be egy számot, majd írassa ki, hogy a szám szerepel-e a tömbben                 *
*   Amennyiben az előző szám szerepelt a tömbben, írassa ki az összes előfordulásának helyét *
*********************************************************************************************/

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
	int ertek;
	printf("Kerem a keresett szamot:\n");
	scanf("%d", &ertek);
	i=0;
	while (i<N && tomb[i]!=ertek)
		i++;
	if (i<N)
	{
		printf("AZ ertek szerepel a tombben, az alabbi indexeken: ");
		int j;
		for (j=0; j<N; j++)
		{
			if (tomb[j]==ertek)
				printf("%d ", j);
		}
		printf("\n");
	}
	else
	{
		printf("Az ertek nem szerepel a tombben.\n");
	}
	return 0;
}
