#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int globalvalue = 10;

int main()
{
	pid_t  pid1;
	pid_t pid2;
	int ret;
	int status;

	pid1 = fork();
	if (pid1 == 0) {		//child1
		getchar();
		puts("child1 ddddddd");
		exit(2);
	}
	else {		//father
		ret = wait(&status);
		printf("ret: %d\n", ret);
		printf("status: %d\n", WEXITSTATUS(status));
		if (WIFEXITED(status))
			puts("exit ");
		if (WIFSIGNALED(status))
			puts("killed");
		sleep(5);
	}
return 0;
}


//fork wait waitpid exit _exit()
