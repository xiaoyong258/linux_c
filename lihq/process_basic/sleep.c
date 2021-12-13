#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t pid;

	puts("Begin!");
	fflush(NULL); 			/* !!!  */

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	
	if (pid == 0 )
	{
		execl("/usr/bin/sleep","sleep","100",NULL);
		perror("execl()");
		exit(1);
	}

	wait(NULL);

	puts("End!");
	exit(0);

}
