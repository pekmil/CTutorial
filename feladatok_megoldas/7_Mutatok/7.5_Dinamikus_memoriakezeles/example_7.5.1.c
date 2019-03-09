/**************************************************
* 7.5.1 Feladat                                   *
*   Hozzon létre egy egész számra mutató pointert *
*   Foglalja le az egész számnak szükséges helyet *
*   Olvasson be egy számot a memóriaterületre     *
*   Írassa ki a képernyőre a beolvasott számot    *
*   Szabadítsa fel a használt memóriaterületet    *
**************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *mutato=(int*)malloc(sizeof(int));
	printf("Kerem a szamot:\n");
	scanf("%d", mutato);
	printf("A szam: %d.\n", *mutato);
	free(mutato);
	return 0;
}
