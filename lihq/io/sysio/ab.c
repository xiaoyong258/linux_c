#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	putchar('a');
	write(1,"b",1);

	putchar('a');
	write(1,"b",1);
	
	putchar('a');
	write(1,"b",1);

	exit(0);
}
