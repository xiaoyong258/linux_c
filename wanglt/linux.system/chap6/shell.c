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
#include <pwd.h>
#include <signal.h>

int exec_builtin_cmd(char *arglist[]);
int is_builtin_cmd(char *arglist[]);

void print_color_yellow(void);
void print_color_blue(void);
void print_color_reset(void);
void print_cmd_prompt(void);
int read_cmdline(char buffer[]);
int parse_cmdline(char bufer[], char *arglist[]);
int exec_cmdline(char *arglist[]);
int free_cmdline(char *arglist[], int args_num);

int main(void)
{
	char buffer[512] = {0};
	char *arglist[20] = {0};
	int  args_num = 0;

	while(1)
	{
		print_cmd_prompt();
		read_cmdline(buffer);
		args_num = parse_cmdline(buffer, arglist);
		exec_cmdline(arglist);
		free_cmdline(arglist, args_num);
		memset(buffer,'\0',512);
		memset(arglist,0,80);
	}

	printf("main shell exit\n");
	exit(0);
}

void print_color_yellow(void)
{
	printf("\033[33;1m");
}
void print_color_blue(void)
{
	printf("\033[34;1m");
}
void print_color_reset(void)
{
	printf("\033[0m");
}
void print_cmd_prompt(void)
{
	struct passwd *pwd;
	pwd = getpwuid(getuid());
	char path[256];
	getcwd(path,sizeof(path));
	print_color_yellow();
	printf("%s@ubuntu:",pwd->pw_name);
	print_color_blue();
	printf("%s",path);
	print_color_reset();
	printf(">>> ");
}
int read_cmdline(char buffer[])
{
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
	return pos;

	/* check input parameter.
	printf("%s\n", buffer);
	exit(0);
	
	char *arglist[5] = {
		"ls",
		"-l",
		"-a"
	};
	*/
}

int parse_cmdline(char buffer[], char *arglist[])
{
	// Analysis input parameter.
	char *cp = buffer;
	int  args_num = 0;
	int  len;
	char *start;
	char c;

	while( *cp != '\0')
	{
		while(*cp == ' ' || *cp == '\t' )
			cp++;
		
		if(*cp == 0)
			break;

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
	return args_num;

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
}

int exec_cmdline(char *arglist[])
{
	int ret_from_fork;
	int child_ret_status;
	
	if(arglist[0] == 0)
		return 0;

	if(is_builtin_cmd(arglist))
	{
		exec_builtin_cmd(arglist);
		return 0;
	}

	ret_from_fork = fork();
	if(ret_from_fork == 0)
	{
		signal(SIGINT,SIG_DFL);
		execvp(arglist[0],arglist);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if(ret_from_fork > 0)
	{
		signal(SIGINT,SIG_IGN);
		if(wait(&child_ret_status) == 0)
			perror("wait");
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int free_cmdline(char *arglist[], int args_num)
{
	int i = 0;
	for(i=0; i< args_num; i++)	
		free(arglist[i]);
	return 0;
}

