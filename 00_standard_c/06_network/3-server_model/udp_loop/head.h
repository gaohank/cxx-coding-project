#ifndef __HEAD_H__
#define __HEAD_H__

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <error.h>

#define error_exit(_errmsg_)	error(EXIT_FAILURE, errno, _errmsg_)
#define BUFF_SIZE	1024
#define CLTPORT		10001
#define CLTADDR		"192.168.10.19"
#define SERPORT		50000
#define SERADDR		"192.168.100.1"

#endif
