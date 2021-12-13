#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	printf("[%d]:Begin!\n",getpid());
	
	fflush(NULL);   	/* !!! */
	pid = fork();

	if( pid < 0 )
	{
		perror("fork()");
		exit(1);
	}
	else if ( pid == 0)   	// child
	{
		printf("[%d]: Child is working!\n", getpid());
	}
	else   					// Parent
	{
		printf("[%d]: Parent is working!\n", getpid());
	}

	printf("[%d]:End!\n", getpid());
	
	//getchar();

	exit(0);
}
