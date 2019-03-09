/***************************************************************************************************************
* 5.1 Feladat                                                                                                  *
*   Készítsen programot, amely egy számítógép adatait képes tárolni (órajel, memória mérete, háttértár mérete) *
*   Billentyűzetről töltse fel a struktúra adatait                                                             *
*   Írassa ki a számítógép adatait                                                                             *
*                                                                                                              *
* 5.2 Feladat                                                                                                  *
*   Módosítsa az előző feladatot úgy, hogy a program három számítógép adatait tárolja                          *
***************************************************************************************************************/

#include <stdio.h>

struct computer
{
	int orajel, memoria, hattertar;
};

int main()
{
	struct computer gepek[3];
	int i;
	for (i=0; i<3; i++)
	{
		printf("Kerem az adatokat a(z) %d. gephez: orajel, memoria, hattertar\n", i+1);
		scanf("%d %d %d", &gepek[i].orajel, &gepek[i].memoria, &gepek[i].hattertar);
	}
	for (i=0; i<3; i++)
	{
		printf("A(z) %d. gep adatai: orajel: %d, memoria: %d, hattertar: %d\n", i+1, gepek[i].orajel, gepek[i].memoria, gepek[i].hattertar);
	}
	return 0;
}
