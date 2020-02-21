#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>

#define ERROR_EXIT(_errmsg_)	error(EXIT_FAILURE, errno, _errmsg_)

#define BUFF_SIZE	1024

int main()
{
	pid_t pid;
	int pipefd[2];
	int counter = 0;
	FILE *fp;
	char buff[BUFF_SIZE];

	if (-1 == pipe(pipefd))
		ERROR_EXIT("pipe");

	if (NULL == (fp = fdopen(pipefd[1], "w")))
		ERROR_EXIT("fdopen");
	setbuf(fp, NULL);

	for (counter = 0; ; counter ++) {
		if (0 > fprintf(fp, "%0128d", counter))
			ERROR_EXIT("fprintf");
		printf("%d\n", counter);
	}

	exit(EXIT_SUCCESS);
	return 0;
}
