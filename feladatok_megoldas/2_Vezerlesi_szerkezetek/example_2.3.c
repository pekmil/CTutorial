/*******************************************************************
* 2.3 Feladat                                                      *
*   Olvasson be három számot                                       *
*   Tárolja el egy új változóban a három szám közül a legnagyobbat *
*   Írassa ki ezt a számot                                         *
*******************************************************************/

#include <stdio.h>

int main()
{
	int x, y, z, max;
	scanf("%d %d %d", &x, &y, &z);
	max=x; // a max legyen az elso szam
	if (y>max) // ha a masodik nagyobb, akkor legyen inkabb az a max
	{
		max=y;
	}
	if (z>max) // ha a harmadik nagyobb, mint az eddigiek maximuma, akkor ez a max
	{
		max=z;
	}
	printf("a legnagyobb ertek: %d\n", max);
	return 0;
}
