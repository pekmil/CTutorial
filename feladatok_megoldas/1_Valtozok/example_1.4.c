/*********************************************************************************
* 1.4 Feladat                                                                    *
*   Olvass be a billentyűzetről két karaktert egyetlen scanf segítségével (x, y) *
*   Írassa ki a két karakter ASCII kódját                                        *
*********************************************************************************/

#include <stdio.h>

int main()
{
	char c1, c2;
	scanf("%c %c", &c1, &c2);
	printf("c1 kodja: %d, c2 kodja: %d\n", c1, c2);
	return 0;
}
