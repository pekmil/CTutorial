/******************************************************************************************************************************************************
* 7.3.1 Feladat                                                                                                                                       *
*   Hozzon létre egy struktúrát, amely négy memóriacímet tárol:                                                                                       *
*     Minimum                                                                                                                                         *
*     Maximum                                                                                                                                         *
*     Első előfordulás                                                                                                                                *
*     Utolsó előfordulás                                                                                                                              *
*   Olvasson be egy tízelemű tömböt                                                                                                                   *
*   Olvasson be egy számot                                                                                                                            *
*   Tárolja el a struktúrában a tömb legkisebb, legnagyobb elemének a címét és a beolvasott szám első és utolsó előfordulásának a címét (vagy nullát) *
*   Jelenítse meg a struktúrában tárolt címeket és a címeken tárolt értékeket                                                                         *
******************************************************************************************************************************************************/

#include <stdio.h>

#define N 10

typedef struct data
{
	int *min, *max, *elso, *utolso;
} Data;

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
	printf("Kerem a szamot:\n");
	scanf("%d", &ertek);
	Data statisztika;
	int min_idx=0, max_idx=0;
	for (i=1; i<N; i++)
	{
		if (tomb[i]<tomb[min_idx])
			min_idx=i;
		if (tomb[i]>tomb[max_idx])
			max_idx=i;
	}
	statisztika.min=&tomb[min_idx];
	statisztika.max=&tomb[max_idx];
	
	i=0;
	while (i<N && tomb[i]!=ertek)
		i++;
	if (i<N)
		statisztika.elso=&tomb[i];
	else
		statisztika.elso=0;
	
	i=N-1;
	while (i>=0 && tomb[i]!=ertek)
		i--;
	if (i>=0)
		statisztika.utolso=&tomb[i];
	else
		statisztika.utolso=0;
	
	printf("A legkisebb ertek cime es erteke: %p, %d.\n", statisztika.min, *statisztika.min);
	printf("A legnagyobb ertek cime es erteke: %p, %d.\n", statisztika.max, *statisztika.max);
	if (statisztika.elso==0)
	{
		printf("Az ertekm nem szerepel a tombben.\n");
	}
	else
	{
		printf("Az ertek elso elofordulasi helye (na meg erteke): %p (%d).\n", statisztika.elso, *statisztika.elso);
		printf("Az ertek elso elofordulasi helye (na meg erteke): %p (%d).\n", statisztika.utolso, *statisztika.utolso);
	}
	return 0;
}
