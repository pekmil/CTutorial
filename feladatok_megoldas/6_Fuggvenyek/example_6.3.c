/*******************************************************************************************************************************************************
* 6.3 Feladat                                                                                                                                          *
*   Írjon függvényt, amely két számot vár paraméterül és eredményül visszaadja a két szám maximumát                                                    *
*   Olvasson be egy számot, amelyet eltárol jelenlegi maximális értékként.                                                                             *
*   Olvasson be számokat addig, míg nem adunk meg háromszor is nagyobb számot az előzőeknél. A nagyobb számot mindig tárolja el jelenlegi maximumként. *
*   A feladat megoldásához használja fel az előzőleg megírt függvényt.                                                                                 *
*******************************************************************************************************************************************************/

#include <stdio.h>

int max(int egyik, int masik)
{
	if (egyik>masik)
		return egyik;
	else
		return masik;
}

int main()
{
	int ertek, max_ertek;
	printf("Kerem az elso szamot:\n");
	scanf("%d", &ertek);
	max_ertek=ertek;
	printf("Kerem a tovabbi szamokat:\n");
	int szamol=0;
	do
	{
		scanf("%d", &ertek);
		if (max(ertek, max_ertek)>max_ertek)
		{
			max_ertek=ertek;
			szamol++;
			printf("Megvan a(z) %d. nagyobb szam.\n", szamol);
		}
	} while (szamol<3);
	return 0;
}
