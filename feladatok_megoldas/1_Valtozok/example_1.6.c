/**********************************************************
* 1.6 Feladat                                             *
*   Olvasson be négy számot egymástól ponttal elválasztva *
*   Írassa ki a négy számot                               *
*   Írassa ki a szomszédos számok szorzatainak összegét    *
**********************************************************/

#include <stdio.h>

int main()
{
	int d1, d2, d3, d4;
	scanf("%d.%d.%d.%d", &d1, &d2, &d3, &d4);
	printf("a negy szam: %d, %d, %d, %d\n", d1, d2, d3, d4);
	printf("a szomszedosok szorzatainak osszege: %d\n", d1*d2+d2*d3+d3*d4);
	return 0;
}
