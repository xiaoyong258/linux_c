#include "hello.h"
#include "usb.h"
int main(int argc, char *argv[])
{
	if (MAX(1,2) == 2){
		hello("World");
		hello(" init");
	}
	return 0;
}
