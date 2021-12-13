#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FNAME 	"/tmp/out"

static int daemonize(void)
{
	pid_t pid;
	int fd;

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		return -1;
	}

	if(pid > 0)  // parent
		exit(0);

	// child
	fd = open ("/dev/null",O_RDWR);
	if(fd < 0)
	{
		perror("open()");
		return -1;
	}

	dup2(fd,0);
	dup2(fd,1);
	dup2(fd,2);
	if(fd > 2)
		close(fd);

	setsid();

	chdir("/");
	umask(0);

	return 0;

}

int main()
{
	int i;
	FILE *fp;

	if(daemonize())
		exit(1);

	fp = fopen(FNAME,"w");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	for(i=0 ; ; i++)
	{
		fprintf(fp, "%d\n", i);
		fflush(fp);
		sleep(1);
	}

	fclose(fp);

	exit(0);
}
