#include "head.h"

int main()
{
	int sockfd;
	struct sockaddr_in seraddr,
					   cltaddr;
	char *buff = NULL;

	buff = (char *)malloc(BUFF_SIZE);

	
	if (-1 == (sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		ERROR_EXIT("socket");
	
/* bind client`s address/port is not necessary */
	cltaddr.sin_family = AF_INET;
	cltaddr.sin_port = htons(CLIENT_PORT);
	cltaddr.sin_addr.s_addr = inet_addr(CLIENT_ADDR);
	if (-1 == bind(sockfd, (struct sockaddr *)&cltaddr, sizeof(cltaddr)))
		ERROR_EXIT("bind");
	
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SERVER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	if (-1 == connect(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)))
		ERROR_EXIT("connect");

	strcpy(buff, "helloworld");
	if (-1 == send(sockfd, buff, strlen(buff)+1, 0))
		ERROR_EXIT("send");

	memset(buff, 0, BUFF_SIZE);
	if (-1 == recv(sockfd, buff, BUFF_SIZE, 0))
		ERROR_EXIT("recv");

	printf("recv: %s\n", buff);

	close(sockfd);
	free(buff);
	
	return 0;
}
