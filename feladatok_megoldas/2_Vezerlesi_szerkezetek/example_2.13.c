/**************************************************************************************************
* 2.13 Feladat(!)                                                                                 *
*   Írjon egy programot, amely egy egyszerű menüt képes kezelni:                                  *
*     A program kiírja a lehetőségeket, majd végrehajtja a kiválasztott műveletet                 *
*     A művelet végrehajtása után, amennyiben az nem kilépés volt, ismételten megjeleníti a menüt *
*     Lehetőségek:                                                                                *
*       1: Bekér két számot és kiírja a nagyobbat                                                 *
*       2: Bekér két számot és kiírja a kisebbet                                                  *
*       3: Kilép                                                                                  *
**************************************************************************************************/

#include <stdio.h>

int main()
{
	int menupont;
	do
	{
		printf("\nKerem valasszon meunpontot:\n");
		printf("  1. ket szam kozul nagyobb kivalasztasa\n");
		printf("  2. ket szam kozul kisebb kivalasztasa\n");
		printf("  3. kilepes\n");
		scanf("%d", &menupont);
		if (menupont==1)
		{
			int x, y;
			printf("Kerek ket szamot:\n");
			scanf("%d %d", &x, &y);
			int max=x;
			if (max<y)
				max=y;
			printf("a nagyobb a ketto kozul: %d\n", max);
		}
		else if (menupont==2)
		{
			int x, y;
			printf("Kerek ket szamot:\n");
			scanf("%d %d", &x, &y);
			int min=x;
			if (min>y)
				min=y;
			printf("a kisebb a ketto kozul: %d\n", min);
		}
	} while (menupont!=3);
	return 0;
}
