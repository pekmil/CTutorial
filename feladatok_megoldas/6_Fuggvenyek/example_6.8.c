/*********************************************************************************************************
* 6.8 Feladat                                                                                            *
*   Írjon rekurzív függvényt, amely kiszámolja egy szám faktoriálisát                                    *
*   Olvasson be számot mindaddig, amíg az nem nulla. Írja ki a képernyőre a szám faktoriálisának értékét *
*********************************************************************************************************/

#include <stdio.h>

long long int faktorialis(int n) // azert, hogy nagyobb szamokra is mukodjon
{
	if (n>1)
		return n*faktorialis(n-1);
	else
		return 1;
}

int main()
{
	int n;
	do
	{
		printf("Kerem a szamot:\n");
		scanf("%d", &n);
		if (n>0)
		{
			printf("A szam faktorialisa: %lld.\n", faktorialis(n));
		}
	} while (n!=0);
	return 0;
}
