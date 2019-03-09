/***************************************************************
* 4.1.6 Feladat(!)                                             *
*   Olvasson be két számot                                     *
*   Cserélje meg a két számot újabb változó létrehozása nélkül *
***************************************************************/

#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("%d %d\n", a, b);
	return 0;
}
