/********************************************************************
* 3.5 Feladat                                                       *
*   Olvasson be két háromelemű tömböt (vektort)                     *
*   Írassa ki az első vektor háromszorosát és a második kétszeresét *
*   Írassa ki az első vektorral azonos irányú egységvektort         *
*   Írassa ki a két vektor skaláris szorzatát ciklus nélkül         *
*   Írassa ki a két vektor skaláris szorzatát ciklus segítségével   *
*   Írassa ki a két vektor vektoriális szorzatát                    *
********************************************************************/

#include <stdio.h>
#include <math.h> // ez kell az sqrt() hasznalatahoz

// Megjegyzes: itt a feladat nem keri, hogy kulon valtozokba taroljuk el az eredmenyt, ilyenkor lehet egybol kiirni, tarolas nelkul, ha megoldhato.
// Megjegyzes: az ilyen feladatokat mindig celszeru ciklusokkal megoldani, mert ugy konnyu a meretet modositani. Ez alol a vektorialis szorzat a kivetel, azt csak haromdimenzios vektorokra ertelmezzunk.
int main()
{
	int vektor1[3], vektor2[3];
	// elso pont (beolvasas)
	int i;
	printf("Kerem az elso vektor elemeit:\n");
	for (i=0; i<3; i++)
	{
		scanf("%d", &vektor1[i]);
	}
	printf("Kerem a masodik vektor elemeit:\n");
	for (i=0; i<3; i++)
	{
		scanf("%d", &vektor2[i]);
	}
	
	// masodik pont (szorzas)
	printf("Az elso vektor haromszorosa: ");
	for (i=0; i<3; i++)
	{
		printf("%d ", vektor1[i]*3);
	}
	printf("\nA masodik vektor ketszerese: ");
	for (i=0; i<3; i++)
	{
		printf("%d ", vektor2[i]*2);
	}
	printf("\n");
	
	// harmadik pont (egysegvektor)
	double vektor_hossza=0.0; // ez lebegopontos, mert hasznalunk majd gyokvonast
	for (i=0; i<3; i++)
	{
		vektor_hossza+=vektor1[i]*vektor1[i];
	}
	vektor_hossza=sqrt(vektor_hossza);
	printf("Az iranyvektor: ");
	for (i=0; i<3; i++)
	{
		printf("%lf ", vektor1[i]/vektor_hossza);
	}
	printf("\n");
	
	// negyedik pont (skalaris szorzat ciklus nelkul)
	printf("A ket vektor skalaris szorzata: %d\n", vektor1[0]*vektor2[0]+vektor1[1]*vektor2[1]+vektor1[2]*vektor2[2]);
	
	// otodik pont (skalaris szorzat ciklussal)
	int skalarszorzat=0;
	for (i=0; i<3; i++)
	{
		skalarszorzat+=vektor1[i]*vektor2[i];
	}
	printf("A ket vektor skalaris szorzata: %d\n", skalarszorzat);
	
	// hatodik pont (vektorialis szorzat)
	printf("A ket vektor vektorialis szorzata: (%d, %d, %d)\n", vektor1[1]*vektor2[2]-vektor1[2]*vektor2[1], vektor1[2]*vektor2[0]-vektor1[0]*vektor2[2], vektor1[0]*vektor2[1]-vektor1[1]*vektor2[0]);
	
	return 0;
}
