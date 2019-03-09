/**************************************************************
* 3.6 Feladat                                                 *
*   Olvasson be egy legfeljebb 30 karakter hosszú város nevet *
*   Jelenítse meg a beolvasott városnevet                     *
**************************************************************/

#include <stdio.h>

int main()
{
	char varosnev[31]; // 30 hosszu sztringnek 31 hely kell
	scanf("%s", varosnev);
	printf("A varosnev: %s\n", varosnev);
	return 0;
}
