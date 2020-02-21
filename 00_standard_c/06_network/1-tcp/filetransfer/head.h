#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <error.h>

#define error_exit(_errmsg_)	error(EXIT_FAILURE, errno, _errmsg_)

#define SERVER_PORT		10001
#define SERVER_ADDR		"192.168.10.10"

#define CLIENT_PORT		20002
#define CLIENT_ADDR		"192.168.10.10"

#define BUFF_SIZE		1024

#endif
