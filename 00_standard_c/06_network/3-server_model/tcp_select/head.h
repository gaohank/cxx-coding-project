#ifndef __HEAD_H__
#define __HEAD_H__

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h> /* select */
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <error.h>

#define error_exit(_errmsg_) 	error(EXIT_FAILURE, errno, _errmsg_)

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

#define SER_ADDR 	"192.168.1.10"
#define SER_PORT 	50001

#define BUFF_SIZE 	1024

#endif /* __HEAD_H__ */
