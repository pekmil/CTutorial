/*************************************************************************
* 1.5 Feladat                                                            *
*   Olvass be a billentyűzetről két számot két scanf segítségével (x, y) *
*   Írassa ki a két számot                                               *
*************************************************************************/

#include <stdio.h>

int main()
{
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);
	printf("x erteke: %d, y erteke: %d\n", x, y);
	return 0;
}
