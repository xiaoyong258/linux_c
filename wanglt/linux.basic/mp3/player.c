#include <stdio.h>
#include "usb.h"
#include "lcd.h"
#include "media.h"

int main()
{
	printf("MP3 player  \n ");
	lcd_init();
	usb_init();
	media_init();
}
