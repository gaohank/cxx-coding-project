#include "head.h"

int network_init(void);

int main(int argc, char **argv)
{
	int sockfd,
		fd;
	int nbytes;
	char *serverdir = argv[1];
	char *buff = NULL;

	if (2 != argc)
		error_exit("invalid argument");
	
	buff = malloc(BUFF_SIZE);
	sockfd = network_init();

	mkdir(serverdir, 0775);
	if (-1 == chdir(serverdir))
		error_exit("chdir");
	
	if (0 >= recv(sockfd, buff, BUFF_SIZE, 0))
		error_exit("recv");
	if (-1 == (fd = open(buff, O_CREAT | O_WRONLY, 0644)))
		error_exit("open");

	while (0 < (nbytes = recv(sockfd, buff, BUFF_SIZE, 0))) {
		if (-1 == write(fd, buff, nbytes))
			error_exit("write");
	}

	close(fd);
	close(sockfd);
	free(buff);
	return 0;
}

int network_init(void)
{
	int sockfd,
		connfd;
	struct sockaddr_in seraddr;
	
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SERVER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

	if (-1 == (sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		error_exit("socket");
	if (-1 == bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)))
		error_exit("bind");
	if (-1 == listen(sockfd, 10))
		error_exit("listen");

	if (-1 == (connfd = accept(sockfd, NULL, NULL)))
		error_exit("accept");

	return connfd;
}
