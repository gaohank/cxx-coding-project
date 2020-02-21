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

#define MCAST_PORT	10001
#define MCAST_ADDR	"239.1.2.3"

typedef struct _mesg_package_{
	char user[USER_NAME_LEN];
	char data[DATA_BUFF_LEN];
}mesgpack_st;


int main(int argc, const char **argv)
{
    int sockfd;
    struct sockaddr_in peeraddr,
                       mcastaddr;
	int nbytes;
	pid_t pid;
	mesgpack_st msgbuf;
	time_t time_sec;
	struct ip_mreqn mcastbuff;

	if (argc != 2) {
		puts("invalid argument !");
		return -1;
	}

	mcastbuff.imr_ifindex = 0;
	mcastbuff.imr_multiaddr.s_addr = inet_addr(MCAST_ADDR);
	if (-1 == inet_aton(argv[1], &mcastbuff.imr_address)) {
		puts("invalid address !");
		return -1;
	}

	if (-1 == (sockfd = socket(AF_INET, SOCK_DGRAM, 0))) 
        error_exit("socket");

	mcastaddr.sin_family = AF_INET;
	mcastaddr.sin_port = htons(MCAST_PORT);
	mcastaddr.sin_addr.s_addr = inet_addr(MCAST_ADDR);

    if (-1 == bind(sockfd, (struct sockaddr *)&mcastaddr, sizeof(mcastaddr)))
        error_exit("bind");

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
						(struct sockaddr *)&mcastaddr, sizeof(mcastaddr)))
				error_exit("send");
		}
	} else {
		/* child */
		if (-1 == setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mcastbuff, sizeof(mcastbuff)))
			error_exit("setsocket.IP_ADD_MEMBERSHIP");

		while (1) {
			memset(&msgbuf, 0, sizeof(msgbuf));
			if (0 >= (nbytes = recvfrom(sockfd, &msgbuf, sizeof(msgbuf), 0, NULL, NULL)))
				error_exit("recvfrom");
			printf("\e[1;31m%s\e[0m\e[1;33m#\e[0m\t\e[1;32m%s\e[0m%s",
					msgbuf.user, ctime(&time_sec), msgbuf.data);
		}
	}
	close(sockfd);

	return 0;
}

