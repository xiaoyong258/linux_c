/*********************************************
 *       Filename: errno.c
 *         Author: yong.xiao
 *    Description: 
 *         Create: 2021-9-14 15:59
 *  Last Modified: 2021-9-14 15:59
 *  ******************************************/
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int fd;

	fd = open("hello.dat", O_WRONLY);
	if (fd == -1)
	{
		perror("open hello.dat failed!\n");
		return -1;
	}
	close(fd);
	return 0;
}

