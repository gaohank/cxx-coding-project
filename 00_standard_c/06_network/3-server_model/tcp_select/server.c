#include "head.h"

int main()
{
	int sockfd,
		connfd;
	struct sockaddr_in seraddr,
					   cltaddr;
	socklen_t addrlen = sizeof(struct sockaddr_in);
	char buff[BUFF_SIZE];
	fd_set rdfds, tmpfds;
	int maxfd,
		fd;

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_ADDR);

	if (-1 == (sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		error_exit("socket");

	if (-1 == bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)))
		error_exit("bind");

	if (-1 == listen(sockfd, 10))
		error_exit("listen");

	FD_ZERO(&tmpfds);
	FD_SET(sockfd, &tmpfds);
	maxfd = sockfd;

	while (1) {
		rdfds = tmpfds;
		if (-1 == select(maxfd + 1, &rdfds, NULL, NULL, NULL))
			error_exit("select");

		if (FD_ISSET(sockfd, &rdfds)) {

			if (-1 == (connfd = accept(sockfd, (struct sockaddr *)&cltaddr, &addrlen)))
				error_exit("accept");
			printf("%s:%d\n", inet_ntoa(cltaddr.sin_addr), ntohs(cltaddr.sin_port));
			FD_SET(connfd, &tmpfds);
			maxfd = connfd > maxfd ? connfd : maxfd;
			continue;
		} 

		for (fd = 0; fd <= maxfd; fd ++) {
			if ( !FD_ISSET(fd, &rdfds))
				continue;

			memset(buff, 0, BUFF_SIZE);
			if (0 >= recv(fd, buff, BUFF_SIZE - 20, 0)) {
				close(fd);
				FD_CLR(fd, &tmpfds);
				continue;
			}
			strcat(buff, "-------echo");
			if (-1 == send(fd, buff, strlen(buff)+1, 0))
				error_exit("send");
		} /* for (fd = 0; fd <= maxfd; fd ++) */
	} /* 32: while (1) */
	return 0;
}
