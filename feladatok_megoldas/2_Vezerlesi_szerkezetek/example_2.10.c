/***********************************************************
* 2.10 Feladat                                             *
*   Olvasson be egy számot                                 *
*   Írassa ki, hogy a beolvasott szám prímszám-e, vagy sem *
***********************************************************/

#include <stdio.h>

int main()
{
	int ertek;
	scanf("%d", &ertek);
	int prim=1, oszto=2;
	if (ertek<=1) prim=0; // Csak az egynel nagyobb szamok erdekesek. A 0 es az 1 nem primek, a negativakkal nem foglalkozunk.
	while (oszto<ertek && prim==1) // Otlet: ha a szam nem prim, akkor van egy nala kisebb szam, ami osztja, nezzuk hat vegig mindet. A prim valtozo tarolja, hogy talaltunk-e osztot a szamhoz.
	{
		if (ertek%oszto==0)
		{
			prim=0;
		}
		oszto++;
	}
	if (prim) // ugyanaz, mint az if (prim!=0)
	{
		printf("%d: primszam\n", ertek);
	}
	else
	{
		printf("%d: nem primszam\n", ertek);
	}
	return 0;
}

//Megjegyzes: ennel hatekonzabb algoritmust is lehetne irni. Pl. ha a szam negyzetgyokeig (sqrt(ertek)) nincs osztoja, azutan sem lesz. Vagy a 2-n kivul mas paros szamot nem erdemes nezni.
