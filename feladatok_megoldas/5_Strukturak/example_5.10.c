/******************************************************************************************************************************************************************************
* 5.9 Feladat                                                                                                                                                                 *
*   Készítsen programot, amely háromszögeket tárol a következő formában:                                                                                                      *
*     A struktúrában tárolunk 10 koordinátát                                                                                                                                  *
*     A struktúrában tárolunk 5 háromszöget                                                                                                                                   *
*     A háromszöget három index segítségével határozunk meg (a 10 elemű koordináta tömb indexei)                                                                              *
*   Olvassa be billentyűzetről tíz koordinátát                                                                                                                                *
*   Olvassa be billentyűzetről a háromszögek indexeit. Minden háromszög beolvasása előtt jelenítse meg a tíz koordinátát azok indexeivel együtt                               *
*   Jelenítse meg a beolvasott adatokat                                                                                                                                       *
*                                                                                                                                                                             *
* 5.10 Feladat(!)                                                                                                                                                             *
*   Módosítsa az előző programot úgy, hogy a beolvasás után a program ellenőrizze, hogy vannak-e olyan koordináták a tömbben, amelyek egyetlen háromszögben sem szerepelnek.  *
*   Ezeket törölje a tömbből, majd a használt értékeket rendezze a tömb elejére. Módosítsa a háromszögben tárolt indexeket is úgy, hogy ugyanazokra a pontokra hivatkozzanak. *
******************************************************************************************************************************************************************************/

#include <stdio.h>

#define N 10
#define M 5

typedef struct coord
{
	float x, y, z;
} Coord;

typedef struct triangle
{
	int indexek[3];
} Triangle;

int main()
{
	Coord koordinatak[N];
	Triangle haromszogek[M];
	int i, j, k;
	for (i=0; i<N; i++)
	{
		printf("Kerem a(z) %d. koordinatat (x, y, z): \n", i+1);
		scanf("%f %f %f", &koordinatak[i].x, &koordinatak[i].y, &koordinatak[i].z);
	}
	for (j=0; j<M; j++)
	{
		printf("A koordinatak (index, x, y, z): \n");
		for (i=0; i<N; i++)
		{
			printf("%d: (%f, %f, %f)\n", i, koordinatak[i].x, koordinatak[i].y, koordinatak[i].z);
		}
		printf("Kerem a harom indexet a(z) %d. haromszoghoz:\n", j+1);
		for (k=0; k<3; k++)
		{
			scanf("%d", &haromszogek[j].indexek[k]); // a hibakezelessel most nem foglalkozunk, feltetelezzuk, hogy minden index valid
		}
	}
	for (j=0; j<M; j++)
	{
		printf("A(z) %d. haromszog:\n", j+1);
		for (k=0; k<3; k++)
		{
			printf("(%f,%f,%f)", koordinatak[haromszogek[j].indexek[k]].x, koordinatak[haromszogek[j].indexek[k]].y, koordinatak[haromszogek[j].indexek[k]].z);
			if (k<2)
				printf(";");
			else
				printf("\n");
		}
	}
	printf("Nem hasznalt csucsok ellenorzese es torlese.\n");
	int csucs_darab=N; // mivel lehet, hogy torlonk ki csucsot, igy nem lesz tele a tomb, tehat csak annyi elemet kell kezelni, amennyi van benne
	int hivatkozas[N]; // osszegyujtjuk, hogy melyik csucs hanyszor szerepel
	for (i=0; i<N; i++)
		hivatkozas[i]=0;
	for (j=0; j<M; j++)
	{
		for (k=0; k<3; k++)
		{
			hivatkozas[haromszogek[j].indexek[k]]++;
		}
	}
	int helyette[N]; // mivel a csucsokat elorebb toljuk, ha elotte toroltunk, az indexek modosulnak; ez a tomb tarolja, hogy a csusztatas utan melyik indexet mire kell cserelni
	int ures=0;
	for (i=0; i<N; i++)
	{
		helyette[i]=-1; // amit nem hasznalunk, az -1 is marad
	}
	for (i=0; i<N; i++)
	{
		if (hivatkozas[i]>0) // van ra hivatkozas, akkor a kovetkezo ures hely az ove
		{
			helyette[i]=ures; // az eddig i. csucs ezutan az ures indexen lesz
			koordinatak[ures]=koordinatak[i]; // ezt tegyuk is meg
			ures++;
		}
		else // ha nem, akkor nem lesz ra hivatkozas, es a kovetkezo ures hely sem mozog, viszont a hasznalt csucsok szama csokken
		{
			csucs_darab--;
			printf("A(z) %d. indexu csucsot nem hasznaljuk.\n", i);
		}
	}
	printf("A hasznalt indexek csusztatasai (hova <- honnan):\n");
	for (i=0; i<N; i++)
	{
		if (helyette[i]!=-1)
		{
			printf("%d <- %d\n", helyette[i], i);
		}
	}
	// most jon a haromszogekben az idexek atirasa
	for (j=0; j<M; j++)
	{
		for (k=0; k<3; k++)
		{
			haromszogek[j].indexek[k]=helyette[haromszogek[j].indexek[k]];
		}
	}
	// es meg egy kiiratas
	printf("A koordinatak (index, x, y, z): \n");
	for (i=0; i<csucs_darab; i++)
	{
		printf("%d: (%f, %f, %f)\n", i, koordinatak[i].x, koordinatak[i].y, koordinatak[i].z);
	}
	for (j=0; j<M; j++)
	{
		printf("A(z) %d. haromszog:\n", j+1);
		for (k=0; k<3; k++)
		{
			printf("(%f,%f,%f)", koordinatak[haromszogek[j].indexek[k]].x, koordinatak[haromszogek[j].indexek[k]].y, koordinatak[haromszogek[j].indexek[k]].z);
			if (k<2)
				printf(";");
			else
				printf("\n");
		}
	}
	return 0;
}
