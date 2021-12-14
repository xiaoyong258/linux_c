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
#include <string.h>

int main(void)
{
	int ret_from_fork;
	int child_ret_status;
	char buffer[512] = {0};
	char c;
	int  pos = 0;

	// get input parameter.
	while(1)
	{
		c = getchar();
		if( c != '\n' && c != EOF)
			buffer[pos++] = c;
		else
		{
			buffer[pos++] = '\0';
			break;
		}
	}


	/* check input parameter.
	printf("%s\n", buffer);
	exit(0);
	
	char *arglist[5] = {
		"ls",
		"-l",
		"-a"
	};
	*/
	
	// Analysis input parameter.
	char *arglist[20] = {0};
	char *cp = buffer;
	int  args_num = 0;
	int  len;
	char *start;

	while( *cp != '\0')
	{
		while(*cp == ' ' || *cp == '\t' )
			cp++;

		start = cp;
		len = 1;
		c = *++cp;
		while( c != '\0' && c != ' ' && c != '\t')
		{
			len++;
			c = *++cp;
		}
		arglist[args_num] = (char *) malloc(len + 1);
		strncpy(arglist[args_num], start,len);
		arglist[args_num][len] = '\0';
		args_num++;
	}

	/* Check analysised parameter.
	int i = 0;
	while(arglist[i])
	{
		printf("%s\n",arglist[i]);
		free(arglist[i]);
		i++;
	}
	exit(0);
	*/

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

	int i = 0;
	while(arglist[i])
		free(arglist[i++]);



	exit(0);
}
