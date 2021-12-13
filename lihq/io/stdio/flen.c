#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;

	int count = 0;
	long len = 0;

	if (argc < 2 )
	{
		fprintf(stderr, "Usage...\n");
		exit(1);
	}

	fp = fopen(argv[1],"r");
	if ( fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}
	/* 用fseek定位到文件末尾，并用ftell获得当前文件末尾的字节数 */
	fseek(fp, 0L, SEEK_END);
	len = ftell(fp);
	printf("len=%ld\n",len);

	/* 用fgetc读取文件的所有字节，并计数文件的字节长度.  
	while(fgetc(fp) != EOF)
	{
		count++;
	}

	printf("count=%d\n",count );
	*/

	fclose(fp);
	exit(0);
}
