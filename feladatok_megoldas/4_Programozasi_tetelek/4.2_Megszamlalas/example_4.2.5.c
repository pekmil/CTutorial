/***************************************************************************************************************************************************
* 4.2.5 Feladat(!)                                                                                                                                 *
*   Olvasson be egy tízelemű tömböt                                                                                                                *
*   Írassa ki a képernyőre, hogy a tömbben szereplő értékek hányszor szerepelnek a tömbben. Minden érték előfordulását csak egyszer jelenítse meg. *
***************************************************************************************************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb[N];
	int i, j;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	for (i=0; i<N; i++)
	{
		int szerepelt=0; // minden erteket cask egyszer iratunk ki, ezt ugy tesszuk meg, hogy minden ertekre megvizsgaljuk, hogy korabban szerepelt-e mar a tombben
		for (j=0; j<i; j++) // i-ig megyunk, mert az erdekel, hogy korabban szerepelt-e mar
		{
			if (tomb[j]==tomb[i])
				szerepelt++;
		}
		if (szerepelt==0) // csak akkor erdekel minket ez az ertek, ha kisebb indexen meg nem volt a tombben
		{
			int darab=0;
			for (j=i; j<N; j++) // itt lehetne for (j=0; j<N; j++) is, de az i. ez elso elofordulasa a szamnak a tombben, es nem szeretnenk felesleges szamolasokat vegezni
			{
				if (tomb[j]==tomb[i])
					darab++;
			}
			printf("A(z) %d szam %d-szer szerepel a tombben.\n", tomb[i], darab);
		}
	}
	return 0;
}

// Megjegyzes: a megszamlalas mehetne ugy, is, hogy darab=1-nel kezunk, es a ciklus j=i+1-nel indul, mert a tomb[i]==tomb[i] ugyis igaz.
