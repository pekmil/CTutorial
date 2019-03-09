/********************************************************************************************
* 1. Kis zárthelyi példa                                                                    *
*   Hozzon létre egy előjel nélküli egész típusú változót, melynek értéke: 42.              *
*   Olasson be egy egész számot és egy lebegőpontos számot                                  *
*   Tárolja el egy új változóba a beolvasott egész számnál kettővel nagyobb szám négyzetét. *
*   Jelenítse meg a beolvasott adatokat és az előjel nélküli egész értéket.                 *
*   Jelenítse meg a kiszámolt értéket.                                                      *
*   Jelenítse meg a lebegőpontos szám és az előjel nélküli egész szorzatát.                 *
********************************************************************************************/

#include <stdio.h>

int main()
{
	unsigned int u=42;
	int i;
	float f;
	printf("Kerem a ket szamot:\n"); // Nem kötelező
	scanf("%i %f", &i, &f);
	int i2=(i+2)*(i+2);
	printf("i=%d, f=%.3f, u=%u\n", i, f, u); // A lebegőpontos szám legyen max 3 tizedesjegyig kiírva. Nem kötelező, csak szebb a kimenet
	printf("i2=%d\n", i2);
	printf("f*u=%.3f\n", f*u);
	return 0;
}
