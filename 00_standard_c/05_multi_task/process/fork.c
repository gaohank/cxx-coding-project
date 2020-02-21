#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <error.h>
#include <errno.h>

int main()
{
	pid_t pid;

	pid = fork();
	if (pid > 0)	//father process
	{
		while(1)
		{
			printf("PPID[%d]------PID[%d]\n\tI`m father !\n",
					getppid(), getpid());
			sleep(1);
		}
	}
	else if (pid == 0)	//child process
	{
		while(1)
		{
			printf("PPID[%d]------PID[%d]\n\tI`m child !\n",
					getppid(), getpid());
			sleep(1);
		}
	}
	else
		error(EXIT_FAILURE, errno, "fail to fork --->%s:%s:%d\n",
				__FILE__, __func__, __LINE__);
	
	exit(EXIT_SUCCESS);
}
