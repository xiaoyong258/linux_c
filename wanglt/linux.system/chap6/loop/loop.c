#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int count = 0;
	while(1)
	{
		printf("hello count: %d\n", count++);
		sleep(1);
	}
	exit(0);
}
