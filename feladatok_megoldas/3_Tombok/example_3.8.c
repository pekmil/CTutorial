/***************************************************************************************************************
* 3.8 Feladat                                                                                                  *
*   Készítsen programot, amely egy számítógép adatait képes tárolni (órajel, memória mérete, háttértár mérete) *
*   Billentyűzetről töltse fel az adatait                                                                      *
*   Írassa ki a számítógép adatait                                                                             *
***************************************************************************************************************/

#include <stdio.h>

int main()
{
	int orajel, memoria, hattertar;
	printf("Kerem az adatokat: orajel, memoria, hattertar\n");
	scanf("%d %d %d", &orajel, &memoria, &hattertar);
	printf("Orajel: %d, memoria: %d, hattertar: %d\n", orajel, memoria, hattertar);
	return 0;
}
