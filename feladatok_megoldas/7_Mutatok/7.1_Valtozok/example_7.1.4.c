/****************************************************************************************
* 7.1.4 Feladat                                                                         *
*   Hozzon létre egy egész számot tároló változót és hozzá egy mutatót                  *
*   Olvassa be a szám értékét a mutatón keresztül                                       *
*   Írassa ki a képernyőre a szám értékét és memóriacímét az első változó segítségével  *
*   Írassa ki a képernyőre a szám értékét és memóriacímét a mutató változó segítségével *
*   Írassa ki a képernyőre a mutató címét                                               *
****************************************************************************************/

#include <stdio.h>

int main()
{
	int ertek;
	int *mutato=&ertek;
	printf("Kerem a valtozo erteket:\n");
	scanf("%d", mutato);
	printf("A valtozo erteke es memoriacime: %d, %p.\n", ertek, &ertek);
	printf("A valtozo erteke es memoriacime: %d, %p.\n", *mutato, mutato);
	printf("A mutato memoriacime: %p.\n", &mutato);
	return 0;
}
