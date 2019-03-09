/************************************************************************************
* 2.6 Feladat                                                                       *
*   Ciklus segítségével ötször olvasson be egy számot, majd írja ki annak négyzetét *
************************************************************************************/

#include <stdio.h>

int main()
{
	int ertek, i;
	for (i=0; i<5; i++)
	{
		scanf("%d", &ertek);
		printf("a(z) %d negyzete: %d\n", ertek, ertek*ertek);
	}
	return 0;
}
