/************************************************************************************************************************************************
* 7.5.10 Feladat                                                                                                                                *
*   Olvasson be egy számot                                                                                                                      *
*   Olvasson be egy a számnak megfelelő méretű, szövegeket tároló tömböt. Minden szövegnek akkora helyet foglaljon, amekkora szükséges számára. *
*   Rendezze a tömböt növekvő sorrendbe                                                                                                         *
*   Jelenítse meg a tömb tartalmát                                                                                                              *
*   Olvasson be egy számot, majd jelenítse meg az ennél nem hosszabb szövegeket                                                                 *
************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int darab;
	printf("Kerem az elemek szamat:\n");
	scanf("%d", &darab);
	char **szovegek=(char**)malloc(sizeof(char*)*darab);
	char atmeneti[101];
	int i, j;
	int hossz;
	printf("Kerek %d darab szoveget:\n", darab);
	for (i=0; i<darab; i++)
	{
		scanf("%s", atmeneti);
		hossz=strlen(atmeneti);
		printf("A szoveg hossza: %d.\n", hossz);
		szovegek[i]=(char*)malloc(sizeof(char)*(hossz+1));
		strcpy(szovegek[i], atmeneti);
	}
	int min_idx;
	char *csere; // eleg egy pointer, mivel a szovegek csak tombokre mutatnak, ha a ket pointer erteket csereljuk, olyan, mintha a szovegeket cserelnenk
	for (i=0; i<darab-1; i++)
	{
		min_idx=i;
		for (j=i+1; j<darab; j++)
		{
			if (strcmp(szovegek[j], szovegek[min_idx])<0)
				min_idx=j;
		}
		if (min_idx!=i)
		{
			csere=szovegek[i];
			szovegek[i]=szovegek[min_idx];
			szovegek[min_idx]=csere;
		}
	}
	for (i=0; i<darab; i++)
	{
		printf("%s\n", szovegek[i]);
	}
	int etalon;
	printf("Kerem a hosszt:\n");
	scanf("%d", &etalon);
	printf("Az ennel nem hosszab szovegek:\n");
	for (i=0; i<darab; i++)
	{
		if (strlen(szovegek[i])<=etalon)
			printf("%s\n", szovegek[i]);
	}
	for (i=0; i<darab; i++)
		free(szovegek[i]);
	free(szovegek);
	return 0;
}
