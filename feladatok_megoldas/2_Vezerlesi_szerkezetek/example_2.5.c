/****************************************
* 2.5 Feladat(!)                        *
*   Kérjen be egy évszámot              *
*   Írassa ki, hogy az évszám szökőév-e *
*     Osztható 4-el, akkor szökőév      *
*     Ha 100-al osztható, akkor nem     *
*     Ha 400-al osztható, akkor szökőév *
****************************************/

#include <stdio.h>

int main()
{
	int evszam;
	scanf("%d", &evszam);
	if (evszam%400==0) // ha 400-zal oszthato, akkor szokoev
	{
		printf("Az ev szokoev.\n");
	}
	else // ha nem oszthato 400-zal
	{
		if (evszam%4==0) // ha 4-gyel oszthato, akkor lehet szokoev
		{
			if (evszam%100==0) // ha 100-zal oszthato, akkor nem
			{
				printf("Az ev nem szokoev.\n");
			}
			else // ha 100-zal nem oszthato, akkor szokoev
			{
				printf("Az ev szokoev.\n");
			}
		}
		else // ha 4-gyel sem, akkor nem az
		{
			printf("Az ev nem szokoev.\n");
		}
	}
	return 0;
}

//Megjegyzes: A fenti kod nagyon reszletes, a problemat tomorebben is meg lehet oldani (egy feltetelbe tomoritve) az alabbi modon:
/*int main()
{
	int evszam;
	scanf("%d", &evszam);
	if ((evszam%400==0) || (evszam%4==0 && evszam%100!=0)) // ha 400-zal oszthato; vagy 4-gyel, de 100-zal nem; akkor szokoev
	{
		printf("Az ev szokoev.\n");
	}
	else
	{
		printf("Az ev nem szokoev.\n");
	}
	return 0;
}*/
