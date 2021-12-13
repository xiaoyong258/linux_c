/*********************************************
 *       Filename: strace.c
 *         Author: yong.xiao
 *    Description: 
 *         Create: 2021-9-14 11:02
 *  Last Modified: 2021-9-14 11:02
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
	int fd1, fd2;
	fd1 = open ("test.dat", O_RDONLY | O_CREAT);
	if(fd1 == -1 )
	{
		printf("open test.dat failed!\n");
		return -1;
	}

	fd2 = open("hello.dat", O_WRONLY);
	if (fd2 == -1)
	{
		close(fd1);
		printf("open hello.dat failed!\n");
		return -1;
	}
	close(fd1);
	close(fd2);
	return 0;
}

