/*****************************************************************************************************
* 7.1.3 Feladat                                                                                      *
*   Hozzon létre három, egész számokat tároló változót és mindegyikhez egy-egy mutatót               *
*   Hajtsa végre az alábbi műveleteket kizárólag a mutatók segítségével:                             *
*     Olvasson be billentyűzetről két számot                                                         *
*     Jelenítse meg a képernyőn a két szám összegét                                                  *
*     A harmadik változóban tárolja el, és jelenítse meg a képernyőn a két szám szorzatát            *
*     Jelenítse meg a képernyőn a két szám hányadosát                                                *
*     Jelenítse meg a képernyőn az egyik szám kétszeresének és a másik szám háromszorosának összegét *
*****************************************************************************************************/

#include <stdio.h>

int main()
{
	int a, b, c;
	int *pa=&a, *pb=&b, *pc=&c;
	printf("Kerem a ket szam erteket:\n");
	scanf("%d %d", pa, pb);
	printf("Az osszeguk: %d.\n", *pa+*pb);
	*pc=(*pa)*(*pb);
	printf("A szorzatuk: %d.\n", *pc);
	printf("A hanyadusok: %d.\n", (*pa)/(*pb));
	printf("2*a+3*b=%d.\n", 2*(*pa)+3*(*pb));
	return 0;
}
