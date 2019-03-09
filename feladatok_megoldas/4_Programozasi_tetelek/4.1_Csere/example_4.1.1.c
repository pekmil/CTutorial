/*************************************************************************
* 4.1.1 Feladat                                                          *
*   Olvasson be két számot a billentyűzetről és tárolja el két változóba *
*   Cserélje meg a két változó értékét                                   *
*************************************************************************/

#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int temp; // atmeneti valtozo a csere lebonyolitasara
	temp=a;
	a=b;
	b=temp;
	printf("%d %d\n", a, b);
	return 0;
}
