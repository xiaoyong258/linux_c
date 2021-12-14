/*
 *      Filename: shell1.c
 *        Author: xiaoyong
 *   Description:
 * 		  Create: 2021-12-14 06:01
 * Last modified: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int ret_from_fork;
	int child_ret_status;

	char *arglist[5] = {
		"ls",
		"-l",
		"-a"
	};
	
	ret_from_fork = fork();
	if(ret_from_fork == 0)
	{
		execvp(arglist[0],arglist);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if(ret_from_fork > 0)
	{
		if(wait(&child_ret_status) == 0)
			perror("wait");
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	printf("main shell exit\n");
	exit(0);
}
