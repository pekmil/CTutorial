/********************************************************************************************
* 2.9 Feladat                                                                               *
*   Olvasson be számokat addig, amíg a beolvasott számok értékének összege kisebb, mint 100 *
*   Ha a beolvasott szám osztható kettővel, de hárommal nem, írassa ki az értékét           *
********************************************************************************************/

#include <stdio.h>

int main()
{
	int ertek, osszeg=0;
	do
	{
		scanf("%d", &ertek);
		if (ertek%2==0 && ertek%3!=0)
		{
			printf("ez egy megfelelo szam: %d\n", ertek);
		}
		osszeg+=ertek;
	} while (osszeg<100);
	return 0;
}
