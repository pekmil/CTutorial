/*******************************************************************************************************************************************************
* 6.9 Feladat                                                                                                                                          *
*   Írjon rekurzív függvényt, amely visszaadja az n-edik fibonacci számot. A nulladik értéke 0, az elsőé 1, a továbbiaké pedig az előző kettő összege. *
*   Olvasson be számot mindaddig, amíg az nem nulla. Írja ki a képernyőre az annyiadik fibonacci számot                                                *
*******************************************************************************************************************************************************/

#include <stdio.h>

int fibonacci(int n)
{
	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else
		return fibonacci(n-2)+fibonacci(n-1);
}

int main()
{
	int n;
	do
	{
		printf("Kerem a szamot:\n");
		scanf("%d", &n);
		if (n>=0)
		{
			printf("Az ennyiedik fibonacci szam: %d.\n", fibonacci(n));
		}
	} while (n!=0);
	return 0;
}
