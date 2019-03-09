/***********************************************************
* 2.2 Feladat                                              *
*   Olvasson be két számot                                 *
*   Számolja ki a két szám hányadosának felső egész részét *
***********************************************************/

#include <stdio.h>

int main()
{
	int x, y, result;
	scanf("%d %d", &x, &y);
	if (x%y==0) // ha x oszthato y-nal, akkor az eredmeny maga a hanyados
	{
		result=x/y;
	}
	else // egyebkent a maradekos osztas eredmenye (az also egesz resz) +1
	{
		result=x/y+1;
	}
	printf("a hanyados felso egesz resze: %d\n", result);
	return 0;
}

// Megjegyzes: A fenti kod csak pozitiv szamokra mukodik helyesen. Negativ szamok kezelese eseten a kovetkezo kod a helyes:
/*int main()
{
	int x, y, result;
	scanf("%d %d", &x, &y);
	if (x%y==0 || x*y<0) // ha x oszthato y-nal, vagy az egyik pozitiv es a masik negativ, akkor az eredmeny maga a hanyados
	{
		result=x/y;
	}
	else // egyebkent a maradekos osztas eredmenye +1
	{
		result=x/y+1;
	}
	printf("a hanyados felso egesz resze: %d\n", result);
	return 0;
}*/
