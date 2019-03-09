/*************************************************************************
* 1.7 Feladat                                                            *
*   Olvasson be egy ip-címet és egy portot (d.d.d.d:d)                   *
*   Írassa ki az adatokat a következő formában: „Ip-cím: ..., Port: ...” *
*************************************************************************/

#include <stdio.h>

int main()
{
	int ip1, ip2, ip3, ip4, port;
	scanf("%d.%d.%d.%d:%d", &ip1, &ip2, &ip3, &ip4, &port);
	printf("Ip-cim: %d.%d.%d.%d, Port: %d\n", ip1, ip2, ip3, ip4, port);
	return 0;
}
