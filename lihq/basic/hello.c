#include <stdio.h>
#include <stdlib.h>

/* 
void main(void);
void main(int argc, char **argv);  // char *argv[]
int main(int argc, char **argv);
int main(void);
 * */

int main(void)
{
	int *p = NULL;

	p = malloc(sizeof(int));

	printf("Hello world\n");


	exit(0);
}
