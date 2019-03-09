/***************************************************************************************************************
* 5.1 Feladat                                                                                                  *
*   Készítsen programot, amely egy számítógép adatait képes tárolni (órajel, memória mérete, háttértár mérete) *
*   Billentyűzetről töltse fel a struktúra adatait                                                             *
*   Írassa ki a számítógép adatait                                                                             *
***************************************************************************************************************/

#include <stdio.h>

struct computer
{
	int orajel, memoria, hattertar;
};

int main()
{
	struct computer c1;
	printf("Kerem az adatokat: orajel, memoria, hattertar\n");
	scanf("%d %d %d", &c1.orajel, &c1.memoria, &c1.hattertar);
	printf("Orajel: %d, memoria: %d, hattertar: %d\n", c1.orajel, c1.memoria, c1.hattertar);
	return 0;
}
