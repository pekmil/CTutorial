/************************************************************************
* 1.9 Feladat                                                           *
*   Olvass be a billentyűzetről három számot (x, y, z)                  *
*   Tárolja el és írassa ki 3*x – y*z értékét                           *
*   Újabb változó felhasználása nélkül írassa ki a három szám szorzatát *
************************************************************************/

#include <stdio.h>

int main()
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int result=3*x-y*z;
	printf("3*x-y*z erteke: %d\n", result);
	printf("a harom szam szorzata: %d\n", x*y*z);
	return 0;
}
