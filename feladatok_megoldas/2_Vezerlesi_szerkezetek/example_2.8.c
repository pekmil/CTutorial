/*********************************************************************************************
* 2.8 Feladat                                                                                *
*   Olvasson be egy számot addig, amíg nem kap 3-mal osztható, de 6-tal nem osztható értéket *
*********************************************************************************************/

#include <stdio.h>

int main()
{
	int ertek;
	do
	{
		scanf("%d", &ertek);
	} while (!(ertek%3==0 && ertek%6!=0));
	return 0;
}
