#include <stdio.h>
#include "../usb/usb.h"
#include "../lcd/lcd.h"
#include "../media/media.h"

int main()
{
	printf("MP3 player  \n ");
	lcd_init();
	usb_init();
	media_init();
}
