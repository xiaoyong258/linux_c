#include <stdio.h>
#include <stdlib.h>

#define PI 			3.14
#define ADD 		(2+3)
#define MAX 		((a) > (b) ? (a) : b)
#define MAX2(a,b) 	\
	({ typeof(a) A=a,B=b; ((A) > (B) ? (A):(B)); })

#if 0
int max(int a, int b)
{
	return a > b ? a : b;
}
#endif

int main()
{
	int a,b,c;
	int i = 5, j = 3;

	a = a * PI;
	b = b + PI;
	c = c / PI;

	printf("i = %d\tj=%d\n",i,j);
	printf("%d\n",MAX2(i++,j++));
	printf("i = %d\tj=%d\n",i,j);
		
	exit(0);
}

