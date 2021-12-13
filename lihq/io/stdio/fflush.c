#include <stdio.h>
#include <stdlib.h>

/*
 * 缓冲区的作用:大多数情况下是好事,合并系统调用
 * 行缓冲: _IOLBF line buffered
 * 		换行时候刷新，满了的时候刷新,强制刷新(标准输出是这样的,因为是终端设备)
 *
 * 全缓冲: _IOFBF fully buffered
 * 		满了的时候刷新,强制刷新(默认,只要不是终端设备)
 *
 * 无缓冲: _IONBF unbuffered.
 * 		如stderr, 需要立即输出的内容.
 *
 * 		setvbuf - 修改刷新模式
 */

int main()
{
	int i;

	printf("Before while()");
	fflush(stdout);

	while(1);

	printf("After while()");
	fflush(NULL);

	exit(0);
}
