/*******************************************************************************************************************************************************************
* 6.1 Feladat                                                                                                                                                      *
*   Írjon függvényt, amely két számot vár paraméterül és eredményül visszaadja a két szám összegét                                                                 *
*   Írjon programot, amely két számot olvas be mindaddi g, míg azok összege nem osztható 7-tel. A feladat megoldásához használja fel az előzőleg megírt függvényt. *
*******************************************************************************************************************************************************************/

#include <stdio.h>

int osszeg(int egyik, int masik)
{
	return egyik+masik;
}

int main()
{
	int a, b;
	do
	{
		printf("Kerem a ket szamot:\n");
		scanf("%d %d", &a, &b);
	} while (osszeg(a,b)%7!=0);
	return 0;
}
