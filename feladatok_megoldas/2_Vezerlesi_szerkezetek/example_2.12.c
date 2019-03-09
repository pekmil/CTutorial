/******************************************************
* 2.12 Feladat(!)                                     *
*   Olvasson be két számot                            *
*   Írassa ki a két szám legnagyobb közös osztóját    *
*   Írassa ki a két szám legkisebb közös többszörösét *
******************************************************/

#include <stdio.h>

int main()
{
	long long int ertek1, ertek2;
	scanf("%lld %lld", &ertek1, &ertek2);
	// Otlet: a kisebb szamtol megyunk lefele, es az elso, amely mindkettonek osztoja, az a legnagyobb kozos oszto
	if (ertek1>0 && ertek2>0) // csak pozitiv szamokkal foglalkozunk
	{
		long long int min=ertek1;
		if (min<ertek2)
			min=ertek2;
		long long int lnko=min;
		while (!(ertek1%lnko==0 && ertek2%lnko==0))
			lnko--;
		printf("A legnagyobb kozos oszto: %lld\n", lnko);
		long long int lkkt=(ertek1*ertek2)/lnko; // nyilvan ide is lehetne egy ciklust irni, ami a nagyobb szamtol megy felfele, de inkabb kihasznaljuk azt a matematikai tenyt, hogy lnko(a,b)*lkkt(a,b)=a*b
		printf("A legkisebb kozos tobbszoros: %lld\n", lkkt);
	}
	return 0;
}

//Megjegyzes: a fenti algoritmusnal hatekonyabban (de cserebe bonzolultabban) is meg lehet oldani a feladatot, az euklideszi-algoritmus implementalasaval:
/*int main()
{
	long long int ertek1, ertek2;
	scanf("%lld %lld", &ertek1, &ertek2);
	if (ertek1>0 && ertek2>0) // csak pozitiv szamokkal foglalkozunk
	{
		long long int kisebb=ertek1, nagyobb=ertek1, maradek;
		if (kisebb<ertek2)
			kisebb=ertek2;
		if (nagyobb>ertek2)
			nagyobb=ertek2;
		long long int lnko;
		while (nagyobb%kisebb!=0)
		{
			maradek=nagyobb%kisebb;
			nagyobb=kisebb;
			kisebb=maradek;
		}
		lnko=kisebb;
		printf("A legnagyobb kozos oszto: %lld\n", lnko);
		long long int lkkt=(ertek1*ertek2)/lnko; // nyilvan ide is lehetne egy ciklust irni, ami a nagyobb szamtol megy felfele, de inkabb kihasznaljuk azt a matematikai tenyt, hogy lnko(a,b)*lkkt(a,b)=a*b
		printf("A legkisebb kozos tobbszoros: %lld\n", lkkt);
	}
	return 0;
}*/
