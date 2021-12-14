/*
 *      Filename: shell2.c
 *        Author: xiaoyong
 *   Description:
 * 		  Create: 2021-12-14 06:01
 * Last modified: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *arglist[5] = {
		"ls",
		"-l",
		"-a"
	};

	execvp(arglist[0], arglist);
	printf("main shell exit\n");
	exit(0);
}
