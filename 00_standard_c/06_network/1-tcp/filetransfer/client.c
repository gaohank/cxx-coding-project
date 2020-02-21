#include "head.h"

int network_init(void);

int main(int argc, char **argv)
{
	int sockfd,
		fd;
	int nbytes;
	char *filename = argv[1];
	char *buff = NULL;

	if (2 != argc)
		error_exit("invalid argument");
	
	sockfd = network_init();
	if (-1 == (fd = open(filename, O_RDONLY)))
		error_exit("open");
	buff = (char *)malloc(BUFF_SIZE);

	if (-1 == send(sockfd, filename, strlen(filename)+1, 0))
		error_exit("send");

	while (0 < (nbytes = read(fd, buff, BUFF_SIZE))) {
		if (-1 == send(sockfd, buff, nbytes, 0))
			error_exit("send");
	}

	close(sockfd);
	close(fd);
	free(buff);

	return 0;
}

int network_init(void)
{
	int sockfd;
	struct sockaddr_in seraddr,
					   cltaddr;
	
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SERVER_PORT);
	if (0 == inet_aton(SERVER_ADDR, &seraddr.sin_addr))
		error_exit("invalid address");

	cltaddr.sin_family = AF_INET;
	cltaddr.sin_port = htons(CLIENT_PORT);
	if (0 == inet_aton(CLIENT_ADDR, &cltaddr.sin_addr))
		error_exit("invalid address");
	
	if (-1 == (sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		error_exit("socket");
	if (-1 == bind(sockfd, (struct sockaddr *)&cltaddr, sizeof(cltaddr)))
		error_exit("bind");

	if (-1 == connect(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)))
		error_exit("connect");
	
	return sockfd;	
}
