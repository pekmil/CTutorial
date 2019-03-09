/*******************************************************
* 2.11 Feladat(!)                                      *
*   Olvasson be egy számot                             *
*   Írja ki a beolvasott szám prímtényezős felbontását *
*******************************************************/

#include <stdio.h>

int main()
{
	int ertek;
	scanf("%d", &ertek);
	int eredeti_ertek=ertek; // Eltaroljuk az eredeti szamot, mert kozben valtozni fog. Nincs ra feltetlenul szukseg, de jol johet
	int oszto=2;
	int hatvany=0;
	if (ertek<=1)
	{
		printf("%d=%d\n", ertek, ertek); // Csak az egynel nagyobb szamok erdekesek. A 0 es az 1 nem primek, a negativakkal nem foglalkozunk.
	}
	else
	{
		printf("%d=", eredeti_ertek);
		while (oszto*oszto<=ertek) // most csak az ertek negyzetgyokeig megyunk, de ez igy gyorsabb, mint az sqrt(ertek)-et hasznalni
		{
			hatvany=0;
			while (ertek%oszto==0) // hanyszor van meg benne az oszto
			{
				hatvany++;
				ertek/=oszto;
			}
			// kiiratas szepen formazva:
			if (hatvany==1)
				printf("%d", oszto);
			else if (hatvany>1)
				printf("%d^%d", oszto, hatvany);
			if (hatvany!=0 && ertek>1)
				printf("*");
			oszto++; // kovetkezo szam
		}
		if (ertek>1) // a vegere maradt egy primszam, irjuk meg ki
		{
			printf("%d", ertek);
		}
		printf("\n"); // csak egy uj sor a vegere, hogy jol nezzen ki
	}
	return 0;
}

//Megjegyzes: A legnagyobb szam, amit a kod kezelni tud, 2^31-1, mert int tipussal dolgozunk. Helyette a long long int-et hasznalva sokkal nagyobb szamokra is mukodik, esetleg meg az unsigned kulcsszo is hasznalhato.
//Megjegyzes: egymasba agyazott ciklusok nelkul, kevesbe fancy megjelenitessel is meg lehet oldani:
/*int main()
{
	int ertek;
	scanf("%d", &ertek);
	int eredeti_ertek=ertek; // Eltaroljuk az eredeti szamot, mert kozben valtozni fog. Nincs ra feltetlenul szukseg, de jol johet
	int oszto=2;
	if (ertek<=1)
	{
		printf("%d=%d\n", ertek, ertek); // Csak az egynel nagyobb szamok erdekesek. A 0 es az 1 nem primek, a negativakkal nem foglalkozunk.
	}
	else
	{
		printf("%d=", eredeti_ertek);
		while (ertek>1) // osszuk, amig lehet
		{
			if (ertek%oszto==0)
			{
				printf("%d", oszto);
				ertek/=oszto;
				if (ertek>1)
					printf("*");
			}
			else
			{
				oszto++; // kovetkezo szam, de csak ha nem volt osztoja az erteknek
			}
		}
		printf("\n"); // csak egy uj sor a vegere, hogy jol nezzen ki
	}
	return 0;
}*/
