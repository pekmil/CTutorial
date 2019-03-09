/******************************************************************************
* 1.3 Feladat                                                                 *
*   Olvass be a billentyűzetről két számot egyetlen scanf segítségével (x, y) *
*   Írassa ki a két számot                                                    *
******************************************************************************/

#include <stdio.h>

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("x erteke: %d, y erteke: %d\n", x, y);
	return 0;
}
