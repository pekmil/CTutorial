/**************************************************
* 4.1.2 Feladat                                   *
*   Olvasson be 2 ötelemű tömböt                  *
*   Cserélje meg a két tömb azonos indexű elemeit *
*   Jelenítse meg a két tömb értékeit             *
**************************************************/

#include <stdio.h>

int main()
{
	int tomb1[5], tomb2[5];
	int i;
	printf("Kerem az elso tomb elemeit:\n");
	for (i=0; i<5; i++)
	{
		scanf("%d", &tomb1[i]);
	}
	printf("Kerem a masodik tomb elemeit:\n");
	for (i=0; i<5; i++)
	{
		scanf("%d", &tomb2[i]);
	}
	int temp; // segedvaltozo a cserehez
	for (i=0; i<5; i++)
	{
		temp=tomb1[i];
		tomb1[i]=tomb2[i];
		tomb2[i]=temp;
	}
	printf("Az elso tomb elemei a csere utan: ");
	for (i=0; i<5; i++)
	{
		printf("%d ", tomb1[i]);
	}
	printf("\nA masodik tomb elemei a csere utan: ");
	for (i=0; i<5; i++)
	{
		printf("%d ", tomb2[i]);
	}
	printf("\n");
	return 0;
}
