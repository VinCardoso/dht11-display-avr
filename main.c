/*
 * versao_git.c
 *
 * Created: 6/25/17 9:12:16 AM
 * Author :Vinicius Cardoso
 */ 

#include "def_principais.h"
#include "lcd.h"

FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void)
{
	DDRB  = 0xff;		// Set PortB as Out
	
	// Init LCD
	inic_LCD_4bits();
	stdout=&lcd_str;
	
	// First Print on Display
	cmd_LCD(0x80,0);
	printf("Init");
	
    while (1) 
    {
		
    }
}

