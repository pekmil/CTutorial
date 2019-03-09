/****************************************************************
* 7.5.9 Feladat                                                 *
*   Olvasson be egy legfeljebb 100 karakter hosszú szöveget     *
*   Hozzon létre egy a szöveg hosszának megfelelő méretű tömböt *
*   Másolja át a szöveget a számára létrehozott tömbbe          *
*   Írassa ki a szöveget                                        *
*   Szabadítsa fel a lefoglalt memóriaterületet                 *
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char szoveg[101];
	printf("Kerem a szoveget:\n");
	scanf("%s", szoveg);
	int hossz=strlen(szoveg);
	printf("A szoveg hossza: %d.\n", hossz);
	char *megfelelo=(char*)malloc(sizeof(char)*(hossz+1)); // hossz+1, mert itt is kell hely a lezaro '\0' karakternek
	strcpy(megfelelo, szoveg);
	printf("A szoveg (megfelelo hosszon): %s\n", megfelelo);
	free(megfelelo);
	return 0;
}
