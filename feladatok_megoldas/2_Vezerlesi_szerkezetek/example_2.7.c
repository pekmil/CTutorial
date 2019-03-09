/***************************************************************
* 2.7 Feladat                                                  *
*   Olvasson be egy számot addig, amíg nem kap pozitív értéket *
***************************************************************/

#include <stdio.h>

int main()
{
	int ertek;
	do
	{
		scanf("%d", &ertek);
	} while (!(ertek>0));
	return 0;
}
