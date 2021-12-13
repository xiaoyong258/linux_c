#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static volatile in loop = 1;

static void alrm_handler(int s)
{
	loop = 0;
}

int main()
{
	int64_t count = 0;
	alarm(5);
	signal(SIGALRM, alrm_handler);

	while(loop)
		count++;

	printf("%ld\n",count);

	exit(0);
}
