#include "head.h"

int main()
{
	int sockfd;
	struct sockaddr_in seraddr;
	char *buff = NULL;
	int ret;

	buff = (char *)malloc(BUFF_SIZE);

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SERVER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

	if (-1 == (sockfd = socket(AF_INET, SOCK_DGRAM, 0)))
		ERROR_EXIT("socket");

	if (-1 == connect(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)))
		ERROR_EXIT("connect");

	while (1) {
		puts(">");
		fgets(buff, BUFF_SIZE, stdin);
		if (-1 == send(sockfd, buff, strlen(buff)+1, 0))
			ERROR_EXIT("send");
		if (-1 == (ret = recv(sockfd, buff, BUFF_SIZE, 0)))
			ERROR_EXIT("recv");
		printf("[%d]:%s\n", ret, buff);
	}
	close(sockfd);
	free(buff);

	return 0;
}
