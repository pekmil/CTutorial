/***************************************************************************************
* 3.7 Feladat                                                                          *
*   Olvasson be egy vezeték- és keresztnevet                                           *
*   Jelenítse meg a beolvasott nevet a következő formátumban: „keresztnév, vezetéknév” *
***************************************************************************************/

#include <stdio.h>

int main()
{
	char vezeteknev[31], keresztnev[31];
	scanf("%s %s", vezeteknev, keresztnev);
	printf("%s, %s\n", keresztnev, vezeteknev);
	return 0;
}
