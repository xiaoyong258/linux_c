#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <string.h>

#define PAT "/etc/a*.conf"

int errfunc_(const char *errpath, int errno )
{
	puts(errpath);
	fprintf(stderr,"ERROR MSG: %s\n", strerror(errno));
	return 0;
}

int main(int argc, char **argv)
{
	int i;
	int err;
	glob_t globres;

	err = glob(PAT,0,NULL,&globres);
	if(err)
	{
		printf("Error code=%d\n",err);
		exit(1);
	}
	
	for( i=0; i < globres.gl_pathc; i++ )
		puts(globres.gl_pathv[i]);

	exit(0);
}
