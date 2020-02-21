#include "head.h"

int main()
{
	int sockfd,
		connfd;
	pid_t pid;
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

	signal(SIGCHLD, SIG_IGN);

	while (1) {

		if (-1 == (connfd = accept(sockfd, NULL, NULL)))
			ERROR_EXIT("accept");
		if (-1 == (pid = fork()))
			ERROR_EXIT("fork");
		
		if (0 < pid){
			/*father*/
			close(connfd);
			continue;
		} else {
			/*child*/
			while (1) {
				if (0 >= recv(connfd, buff, BUFF_SIZE, 0))
					break;
				strcat(buff, "------echo");
				if (0 >= send(connfd, buff, strlen(buff)+1, 0))
					break;
			}
			free(buff);
			close(connfd);
			exit(EXIT_SUCCESS);
		}
	}
	close(sockfd);
	free(buff);

	return 0;
}