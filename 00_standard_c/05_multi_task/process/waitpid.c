#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <error.h>
#include <errno.h>

int main()
{
	pid_t pid;
	int  status;
	int pids[3];
	int i = 0;

	for(i = 0; i < 3; i ++)
	{
		pid = fork();
		if (pid > 0)	//father process
		{
			pids[i] = pid;
			printf("new child [%d]\n", pid);
		}
		else if (pid == 0)	//child process
		{
			puts("I`m child, I`m going to die");
			if(i == 1)
				sleep(3);
			sleep(1);
			exit(20);
		}
		else
			error(EXIT_FAILURE, errno, "fail to fork --->%s:%s:%d\n",
					__FILE__, __func__, __LINE__);
	}
#if 1
	for(i = 0; i < 3; i ++)
		printf("%d\n", pids[i]);
	puts("I`m father, waiting for child died ... ...");
	waitpid(pids[1], &status, 0);
	printf("child %d is dead with [%d]\n", pids[1], WEXITSTATUS(status));
	exit(EXIT_SUCCESS);
#endif

}