/*********************************************
 *       Filename: copy.c
 *         Author: yong.xiao
 *    Description: 
 *         Create: 2021-9-14 08:58
 *  Last Modified: 2021-9-14 08:58 
 *  ******************************************/
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 4096
int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		printf("usage:\n copy src dst\n");
		return 1;
	}
	
	int srcfd = open(argv[1],O_RDONLY);
	if (srcfd == -1)
	{
		perror("open");
		return -1;
	}
	int dstfd = open(argv[2],O_CREAT|O_WRONLY, 0666);
	if (dstfd == -1)
	{
		perror("open");
		return -1;
	}

	int len = 0;
	char buffer[BUFFERSIZE] = {0};
    while((len=read(srcfd,buffer,BUFFERSIZE))>0)
	{
		if(write(dstfd, buffer,len) != len)
		{
			perror("write error");
			return 2;
		}
	}
	if (len <0)	
	{
		perror("read error");
		return 3;
	}
	close(srcfd);
	close(dstfd);
	return 0;
}
