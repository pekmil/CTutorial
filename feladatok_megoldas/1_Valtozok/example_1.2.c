/********************************************************************************************************************************************************
* 1.2 Feladat                                                                                                                                           *
*   Egy új változóba (’ab’) tárolja el ’a’ és ’b’ szorzatát, egy másikba (’bc’) ’b’ és ’c’ szorzatát, egy harmadikba pedig (’ac’) ’a’ és ’c’ szorzatát. *
*   ’x’ legyen a három szorzat összege                                                                                                                  *
*   ’y’ legyen a három szorzat szorzata                                                                                                                 *
*   ’z’ legyen ’ab’ és ’ac’ különbsége                                                                                                                  *
********************************************************************************************************************************************************/



#include <stdio.h>

int main()
{
	int a, b, c, x, y, z;
	scanf("%d %d %d", &a, &b, &c);
	int ab=a*b;
	int ac=a*c;
	int bc=b*c;
	x=ab+ac+bc;
	y=ab*ac*bc;
	z=ab-ac;
	printf("%d %d %d\n", x, y, z);
	return 0;
}
