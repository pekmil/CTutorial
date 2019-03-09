/*****************************************************************************************
* 4.3.4 Feladat                                                                          *
*   Olvasson be 2 tízelemű tömböt                                                        *
*   Írassa ki a képernyőre azokat az elemeket, amelyek csak az egyik tömbben szerepelnek *
*****************************************************************************************/

#include <stdio.h>

#define N 10

int main()
{
	int tomb1[N], tomb2[N];
	int i, j;
	printf("Kerem az elso tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb1[i]);
	}
	printf("Kerem a masodik tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb2[i]);
	}
	printf("Ertekek, amik csak az egyikben vannak jelen: ");
	// eloszor nezzuk azt, mi az, ami benne van az elsoben, de nincs benne a masodikban
	for (i=0; i<N; i++)
	{
		j=0;
		while (j<N && tomb2[j]!=tomb1[i])
		{
			j++;
		}
		if (j==N) // ez ilyen szam
			printf("%d ", tomb1[i]);
	}
	// majd forditva is kell
	for (j=0; j<N; j++)
	{
		i=0;
		while (i<N && tomb2[j]!=tomb1[i])
		{
			i++;
		}
		if (i==N) // ez ilyen szam
			printf("%d ", tomb2[j]);
	}
	printf("\n");
	return 0;
}
