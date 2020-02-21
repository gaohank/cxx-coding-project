#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <error.h>
#include <time.h>

#define error_exit(_errmsg_) 	\
	error(EXIT_FAILURE, errno, _errmsg_)

#define DATA_BUFF_LEN	512
#define USER_NAME_LEN	32

#define BCAST_PORT	10001
#define BCAST_ADDR	"192.168.10.255"

typedef struct _mesg_package_{
	char user[USER_NAME_LEN];
	char data[DATA_BUFF_LEN];
}mesgpack_st;


int main()
{
    int sockfd;
    struct sockaddr_in peeraddr,
                       bcastaddr;
	int nbytes;
	pid_t pid;
	mesgpack_st msgbuf;
	time_t time_sec;
	int f_isbcast = 1;
    
    if (-1 == (sockfd = socket(AF_INET, SOCK_DGRAM, 0))) 
        error_exit("socket");

	if (-1 == setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &f_isbcast, sizeof(f_isbcast)))
		error_exit("setsocket");

	bcastaddr.sin_family = AF_INET;
	bcastaddr.sin_port = htons(BCAST_PORT);
	bcastaddr.sin_addr.s_addr = inet_addr(BCAST_ADDR);

    if (-1 == bind(sockfd, (struct sockaddr *)&bcastaddr, sizeof(bcastaddr)))
        error_exit("bind");
#if 0 
	/* Don`t do that !!  it`s wrong !! */
    if (-1 == connect(sockfd, (struct sockaddr *)&bcastaddr, sizeof(bcastaddr)))
		error_exit("bind");
#endif

	puts("enter your name:");
	fgets(msgbuf.user, USER_NAME_LEN, stdin);
	msgbuf.user[strlen(msgbuf.user)-1] = '\0';
	
	if (-1 == (pid = fork()))
		error_exit("fork");

	if (0 < pid) {
		/* father */
		while (1) {
			printf(">");
			fflush(stdout);
			fgets(msgbuf.data, DATA_BUFF_LEN, stdin);
			if (-1 == sendto(sockfd, &msgbuf, sizeof(msgbuf), 0, 
						(struct sockaddr *)&bcastaddr, sizeof(bcastaddr)))
				error_exit("send");
		}
	} else {
		/* child */
		while (1) {
			memset(&msgbuf, 0, sizeof(msgbuf));
			puts("redv:");
			if (0 >= (nbytes = recvfrom(sockfd, &msgbuf, sizeof(msgbuf), 0, NULL, NULL)))
				error_exit("recvfrom");
			printf("\e[1;31m%s\e[0m\e[1;33m#\e[0m\t\e[1;32m%s\e[0m%s",
					msgbuf.user, ctime(&time_sec), msgbuf.data);
		}
	}
	close(sockfd);

	return 0;
}

