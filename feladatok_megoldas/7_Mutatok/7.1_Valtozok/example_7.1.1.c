/****************************************************************************
* 7.1.1 Feladat                                                             *
*   Hozzon létre egy egész számot tároló változót                           *
*   Hozzon létre egy mutatót, amely az előzőleg létrehozott változóra mutat *
*   Olvasson be billentyűzetről egy számot a mutatón keresztül              *
*   Írassa ki a képernyőre a szám értékét                                   *
****************************************************************************/

#include <stdio.h>

int main()
{
	int ertek;
	int *mutato=&ertek;
	printf("Kerem a szamot:\n");
	scanf("%d", mutato);
	printf("A szam erteke: %d.\n", ertek);
	return 0;
}
