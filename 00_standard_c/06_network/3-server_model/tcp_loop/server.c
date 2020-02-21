#include "head.h"

int main()
{
	int sockfd,
		connfd;
	struct sockaddr_in seraddr,
					   peraddr;
	char *buff = NULL;

	buff = (char *)malloc(BUFF_SIZE);

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = SERVER_PORT;
	seraddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

	if (-1 == (sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		ERROR_EXIT("socket");
	if (-1 == bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)))
		ERROR_EXIT("bind");

	if (-1 == listen(sockfd, 10))
		ERROR_EXIT("listen");

	while (1)  {
		if (-1 == (connfd = accept(sockfd, NULL, NULL)))
			ERROR_EXIT("accept");
		while (1) {
			if (0 >= recv(connfd, buff, BUFF_SIZE, 0))
				break;
			printf("recv: %s\n", buff);

			strcat(buff, "----echo");
			if (0 >= send(connfd, buff, strlen(buff)+1, 0))
				break;
		}
		close(connfd);
	}
	
	close(sockfd);
	free(buff);

	return 0;
}
