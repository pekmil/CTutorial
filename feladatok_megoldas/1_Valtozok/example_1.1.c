/********************************************************************
* 1.1 Feladat                                                       *
*   'x’ legyen ’a’ negyedik hatványa osztva 3-mal.                  *
*   ’y’ legyen ’b’ háromszorosának és ’c’ kétszeresének különbsége. *
*   ’z’ legyen az előbb kiszámolt ’x’ és ’y’ összege.               *
********************************************************************/




#include <stdio.h>

int main()
{
	int a, b, c, x, y, z;
	scanf("%d %d %d", &a, &b, &c);
	x=a*a*a*a/3;
	y=3*b-2*c;
	z=x+y;
	printf("%d %d %d\n", x, y, z);
	return 0;
}
