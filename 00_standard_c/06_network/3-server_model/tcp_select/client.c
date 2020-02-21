#include "head.h"

int main()
{
	int sockfd;
	struct sockaddr_in seraddr;
	char buff[BUFF_SIZE];
	
	if (-1 == (sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		error_exit("sockfd");
	
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_ADDR);
	
	if (-1 == connect(sockfd, (sockaddr *)&seraddr, sizeof(seraddr)))
		error_exit("connect");

	while (1) {

		usleep(200000);
		strcpy(buff, "helloword");
		if (-1 == send(sockfd, buff, BUFF_SIZE, 0))
			error_exit("send");

		memset(buff, 0, BUFF_SIZE);
		if (-1 == recv(sockfd, buff, BUFF_SIZE, 0))
			error_exit("recv");

		printf("recv: %s\n", buff);
	}

	close(sockfd);

	return 0;
}
