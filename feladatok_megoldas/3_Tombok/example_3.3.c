/*********************************************************************************
* 3.3 Feladat                                                                    *
*   Olvasson be 2 három elemű tömböt                                             *
*   Egy harmadik tömbben tárolja el a két tömb azonos indexű elemeinek szorzatát *
*   Írassa ki a harmadik tömböt                                                  *
*********************************************************************************/

#include <stdio.h>

int main()
{
	int tomb1[3], tomb2[3], tomb3[3];
	int i;
	printf("kerem az elso tomb elemeit:\n");
	for (i=0; i<3; i++)
	{
		scanf("%d", &tomb1[i]);
	}
	printf("kerem a masodik tomb elemeit:\n");
	for (i=0; i<3; i++)
	{
		scanf("%d", &tomb2[i]);
	}
	for (i=0; i<3; i++)
	{
		tomb3[i]=tomb1[i]*tomb2[i];
	}
	printf("a szorzatok: ");
	for (i=0; i<3; i++)
	{
		printf("%d ", tomb3[i]);
	}
	printf("\n");
	return 0;
}
