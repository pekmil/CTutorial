/***************************************************************************************************************
* 3.8 Feladat                                                                                                  *
*   Készítsen programot, amely egy számítógép adatait képes tárolni (órajel, memória mérete, háttértár mérete) *
*   Billentyűzetről töltse fel az adatait                                                                      *
*   Írassa ki a számítógép adatait                                                                             *
*                                                                                                              *
* 3.9 Feladat                                                                                                  *
*   Módosítsa az előző feladatot úgy, hogy a program három számítógép adatait tárolja                          *
***************************************************************************************************************/

#include <stdio.h>

int main()
{
	int orajel[3], memoria[3], hattertar[3];
	int i;
	for (i=0; i<3; i++)
	{
		printf("Kerem az adatokat a(z) %d. gephez: orajel, memoria, hattertar\n", i+1);
		scanf("%d %d %d", &orajel[i], &memoria[i], &hattertar[i]);
	}
	for (i=0; i<3; i++)
	{
		printf("A(z) %d. gep adatai: orajel: %d, memoria: %d, hattertar: %d\n", i+1, orajel[i], memoria[i], hattertar[i]);
	}
	return 0;
}
