/*******************************************
* 1.8 Feladat                              *
*   Olvasson be billentyűzetről két számot *
*   Írassa ki az első szám négyzetét       *
*   Írassa ki a második szám ötszörösét    *
*******************************************/

#include <stdio.h>

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("x negyzete: %d\n", x*x);
	printf("y otszorose: %d\n", y*5);
	return 0;
}
