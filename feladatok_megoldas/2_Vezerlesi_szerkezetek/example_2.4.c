/******************************************************************
* 2.4 Feladat                                                     *
*   Olvasson be három számot                                      *
*   Tárolja el egy új változóban a három szám közül a legkisebbet *
*   Írassa ki ezt a számot                                        *
******************************************************************/

#include <stdio.h>

int main()
{
	int x, y, z, min;
	scanf("%d %d %d", &x, &y, &z);
	min=x; // a min legyen az elso szam
	if (y<min) // ha a masodik kisebb, akkor legyen inkabb az a min
	{
		min=y;
	}
	if (z<min) // ha a harmadik kisebb, mint az eddigiek minimuma, akkor ez a min
	{
		min=z;
	}
	printf("a legkisebb ertek: %d\n", min);
	return 0;
}
