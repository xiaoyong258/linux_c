#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>

#define PATHSIZE 1024

static int path_noloop( const char *path)
{
	char *pos;

	pos = strrchr(path ,'/');
	if( pos == NULL)
		exit(1);

	if(strcmp(pos+1,"." ) == 0 || strcmp(pos+1,"..") == 0)
		return 0;
}
static int64_t mydu(const char *path)
{
	int i;
	static struct stat statres;
	static char nextpath[PATHSIZE];
	glob_t globres;
	int64_t  sum;

	if(lstat(path, &statres) < 0)
	{
		perror("lstate()");
		exit(1);
	}

	if(!S_ISDIR(statres.st_mode))
		return statres.st_blocks;

	strncpy(nextpath,path, PATHSIZE);
	strncat(nextpath,"/*", PATHSIZE);
	glob(nextpath,0,NULL, &globres);

	strncpy(nextpath,path, PATHSIZE);
	strncat(nextpath,"/.*", PATHSIZE);
	glob(nextpath,GLOB_APPEND,NULL, &globres);

	sum = statres.st_blocks;
	for( i=0; i< globres.gl_pathc; i++)
	{
			if(path_noloop(globres.gl_pathv[i]))
				sum += mydu(globres.gl_pathv[i]);
	}

	globfree(&globres);
	return sum;			

}

int main(int argc, char ** argv)
{
	if ( argc < 2)
	{
		fprintf(stderr, "Usage....\n");
		exit(1);
	}

	printf("%lld\n",mydu(argv[1])/2 );

	exit(0);
}
