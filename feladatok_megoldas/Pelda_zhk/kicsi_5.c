/********************************************************************************************************
* 5. Kis zárthelyi példa                                                                                *
*   Kérjen be egy egész számot, és hozzon létre dinamikusan egy ekkora méretű, egészeket tároló tömböt. *
*   Olvassa be a tömb elemeit.                                                                          *
*   Kérjen be egy egész számot.                                                                         *
*   Számolja meg, és közölje, hogy a szám hányszor szerepel a tömbben.                                  *
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int meret;
	printf("Kerem a tomb meretet:\n");
	scanf("%d", &meret);
	int *tomb=(int*)malloc(meret*sizeof(int));
	
	printf("Kerem a tomb elemeit:\n");
	int i=0;
	for (i=0; i<meret; i++)
	{
		scanf("%d", &tomb[i]);
	}
	
	int keresett;
	printf("Kerem a keresett szamot:\n");
	scanf("%d", &keresett);
	
	int szamol=0;
	for (i=0; i<meret; i++)
	{
		if (tomb[i]==keresett)
		{
			szamol++;
		}
	}
	printf("A szam a tombben %d-szer szerepel.\n", szamol);
	
	free(tomb);
	
	return 0;
}
