#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int builtin_cmd_exit(void)
{
	pid_t pid;
	pid = getpid();
	kill (pid, SIGHUP);
	return 0;
}

int builtin_cmd_cd(char path[])
{
	int ret;
	ret = chdir(path);
	if( ret == -1)
	{
		printf("cd %s failed\n", path);
		return -1;
	}
	return 0;
}

int is_builtin_cmd(char *arglist[])
{
	if(strcmp(arglist[0],"cd") == 0)
		return 1;
	if(strcmp(arglist[0],"exit") == 0)
		return 1;
	
	return 0;
}

int exec_builtin_cmd(char *arglist[])
{
	if(strcmp(arglist[0],"cd") == 0)
	{
		if(arglist[1] == 0)
			return 0;
		else
			builtin_cmd_cd(arglist[1]);
	}
	else if(strcmp(arglist[0],"exit") == 0 )
	{
		builtin_cmd_exit();
	}
	return 0;
}
