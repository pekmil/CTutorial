/*****************************************************************************************************************
* 2. Kis zárthelyi példa                                                                                         *
*   Hozzon létre egy tízelemű, egész számokat tároló tömböt, és olvassa be az elemeit.                           *
*   Olvasson be egy újabb egész számot.                                                                          *
*   Állapítsa meg, hogy az adott szám szerepel-e a tömbben, és ha igen, írja ki az első előfordulásának indexét. *
*   Ha a szám szerepel a tömbben, cserélje meg a tömb első elemével.                                             *
*   Írja ki a tömb elemeit.                                                                                      *
*****************************************************************************************************************/

#include <stdio.h>

#define N 10 // Nem kötelező, de szebb a kód, illetve könnyeben módosítható

int main()
{
	int tomb[N];
	int i=0;
	printf("Kerem az elemeket:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	
	int keresett;
	printf("Melyik szamot keressuk?\n");
	scanf("%d", &keresett);
	
	i=0;
	while (i<N && tomb[i]!=keresett)
	{
		i++;
	}
	if (i==N)
	{
		printf("A szam nem szerepel a tombben\n");
	}
	else
	{
		printf("A szam a %d. indexen talalhato\n", i);
		int csere=tomb[i];
		tomb[i]=tomb[0];
		tomb[0]=csere;
	}
	
	printf("A tomb elemei:\n");
	for (i=0; i<N; i++)
	{
		printf("%d ", tomb[i]);
	}
	printf("\n");
	
	return 0;
}
