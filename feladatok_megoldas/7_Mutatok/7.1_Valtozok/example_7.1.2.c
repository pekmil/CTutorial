/*********************************************************************************************************************
* 7.1.2 Feladat                                                                                                      *
*   Hozzon létre két, egész számokat tároló változót                                                                 *
*   Hozzon létre egy mutatót, amely az előzőleg létrehozott egyik változóra mutat                                    *
*   Olvasson be billentyűzetről egy számot a mutatón keresztül                                                       *
*   Olvasson be billentyűzetről még egy számot a mutatón keresztül úgy, hogy az a másik változó értékét befolyásolja *
*   Írassa ki a képernyőre a két szám értékét                                                                        *
*********************************************************************************************************************/

#include <stdio.h>

int main()
{
	int egyik, masik;
	int *mutato=&egyik;
	printf("Kerem az elso szamot:\n");
	scanf("%d", mutato);
	mutato=&masik;
	printf("Kerem a masodik szamot:\n");
	scanf("%d", mutato);
	printf("A ket szam erteke: %d, %d.\n", egyik, masik);
	return 0;
}
