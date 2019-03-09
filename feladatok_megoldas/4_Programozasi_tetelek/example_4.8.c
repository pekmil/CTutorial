/*********************************************************************************************************************
* 4.8 Feladat                                                                                                        *
*   Olvasson be két tízelemű tömböt                                                                                  *
*   Írassa ki a képernyőre a két tömb metszetét. Minden szám csak egyszer szerepeljen                                *
*   Írassa ki a képernyőre a két tömb metszetét. Minden szám annyiszor szerepeljen, ahányszor mindkettőben szerepel. *
*********************************************************************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb1[N], tomb2[N];
	int i, j, k;
	printf("Kerem az elso tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb1[i]);
	}
	printf("Kerem a masodik tomb elemeit:\n");
	for (j=0; j<N; j++)
	{
		scanf("%d", &tomb2[j]);
	}
	printf("A metszet (minden szam egyszer):\n");
	for (i=0; i<N; i++)
	{
		k=0;
		while (k<i && tomb1[k]!=tomb1[i])
			k++;
		if (k==i) // a tombben az i. indexen van eloszor ez a szam, igy vizsgalhatjuk, egyebkent nem
		{
			j=0;
			while (j<N && tomb2[j]!=tomb1[i])
				j++;
			if (j<N) // ekkor a szam a masik tombnek is resze, kiirjuk
			{
				printf("%d ", tomb2[j]);
			}
		}
	}
	printf("\nA metszet (minden szam tobbszor is):\n");
	for (i=0; i<N; i++)
	{
		int darab1=0; // mennyi van a szambol az adott tombben (a jelenlegi utaniakat nem szamolva)
		for (k=0; k<=i; k++)
		{
			if (tomb1[i]==tomb1[k])
				darab1++;
		}
		int darab2=0; // mennyi van a masik tombben osszesen
		for (k=0; k<N; k++)
		{
			if (tomb2[k]==tomb1[i])
				darab2++;
		}
		if (darab1<=darab2) // ha van a masik tombben eleg
			printf("%d ", tomb1[i]);
	}
	printf("\n");
	return 0;
}
