#include "netdevice.h"
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <stdlib.h>
#define error_exit(_errmsg_)	error(EXIT_FAILURE, errno, _errmsg_)

int main()
{
	struct sockaddr_in ipaddr;
	struct sockaddr hwaddr;
	int ifindex = 0;
	int i;


	puts("dev:\t\teth0");

	if (-1 == gethwaddr("eth0", &hwaddr))
		error_exit("gethwaddr");

	printf("mac:\t\t");
	for (i = 0; i < 6; i ++)
		printf("%02hhx:", hwaddr.sa_data[i]);
	puts("\b ");
	
	if (-1 == getipaddr("eth0", (struct sockaddr *)&ipaddr))
		error_exit("getipaddr");

	printf("ip:\t\t%s\n", inet_ntoa(ipaddr.sin_addr));

	if (-1 == (ifindex = getifindex("eth0")))
		error_exit("getifindex");

	printf("index:\t\t%d\n", ifindex);

	return 0;
}
