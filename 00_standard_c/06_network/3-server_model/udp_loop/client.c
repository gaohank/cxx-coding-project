#include "head.h"

int main()
{
	int sockfd;
	struct sockaddr_in seraddr,
					   cltaddr;
	char buff[BUFF_SIZE];
	int ret;
	
	cltaddr.sin_family = AF_INET;
	cltaddr.sin_port = htons(CLTPORT);
	inet_aton(CLTADDR, &cltaddr.sin_addr);

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SERPORT);
	seraddr.sin_addr.s_addr = inet_addr(SERADDR);

	if (-1 == (sockfd = socket(AF_INET, SOCK_DGRAM, 0)))
		error_exit("socket");

//	if (-1 == bind(sockfd, (struct sockaddr *)&cltaddr, sizeof(cltaddr)))
//		error_exit("bind");
	
int count = 0;
	while (1) {
	sprintf(buff, "helloworld%d", count ++);
	if (-1 == sendto(sockfd, buff, strlen(buff)+1, 0,
			(struct sockaddr *)&seraddr, sizeof(seraddr)))
		error_exit("sendto");
	
	memset(buff, 0, BUFF_SIZE);
	if (-1 == (ret = recvfrom(sockfd, buff, BUFF_SIZE, 0, NULL, NULL)))
		error_exit("recvfrom");
	printf("[%d]%s\n", ret, buff);
	}
	close(sockfd);

	return 0;
}
