/************************************************************************************************************************************************************************************
* 6.2 Feladat                                                                                                                                                                       *
*   Írjon függvényt, amely két számot vár paraméterül és eredményül 1-et ad vissza, ha az első szám nagyobb a másodiknál, -1-et, ha a második nagyobb az elsőnél, 0-át, ha egyenlők *
*   Olvasson be egy hételemű tömböt                                                                                                                                                 *
*   Írassa ki a képernyőre azon szomszédos elemeket, amelyekre igaz, hogy az első nagyobb a másodiknál. A feladat megoldásához használja fel az előzőleg megírt függvényt.          *
************************************************************************************************************************************************************************************/

#include <stdio.h>

#define N 7

int nagyobb(int egyik, int masik)
{
	if (egyik>masik)
		return 1;
	else if (masik>egyik)
		return -1;
	else
		return 0;
}

int main()
{
	int tomb[N];
	int i;
	printf("Kerem a tomb elemeit:\n");
	for (i=0; i<N; i++)
	{
		scanf("%d", &tomb[i]);
	}
	for (i=0; i<N-1; i++)
	{
		if (nagyobb(tomb[i], tomb[i+1])==1)
			printf("A(z) %d nagyobb a(z) %d-nel.\n", tomb[i], tomb[i+1]);
	}
	return 0;
}
