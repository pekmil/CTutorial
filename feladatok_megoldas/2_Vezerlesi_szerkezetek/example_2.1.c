/*************************************
* 2.1 Feladat                        *
*   Olvasson be egy számot           *
*   Írassa ki a szám abszolútértékét *
*************************************/

#include <stdio.h>

int main()
{
	int x, abs_x;
	scanf("%d", &x);
	if (x>=0)
	{
		abs_x=x;
	}
	else
	{
		abs_x=-x;
	}
	printf("az abszolut ertek: %d\n", abs_x);
	return 0;
}
