/*
 * versao_git.c
 *
 * Created: 6/25/17 9:12:16 AM
 * Author :Vinicius Cardoso
 */ 

#include "def_principais.h"
#include "lcd.h"
#include "dhtxx.h"

FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void)
{
	DDRB  = 0xff;		// Set PortB as Out
	
	// Init LCD
	inic_LCD_4bits();
	stdout=&lcd_str;
	
	// First Print on Display
	//cmd_LCD(0x80,0);
	//printf("Init");
	
	// DHT11 Variables
	unsigned char ec; //Exit code
	int temp, humid; //Temperature and humidity
	
	cmd_LCD(0x80,0);
	
    while (1) 
    {
		//Request DHT sensor to give it time to prepare data
		dhtxxconvert( DHTXX_DHT11, &PORTC, &DDRC, &PINC, ( 1 << 0 ) );

		_delay_ms(2000);

		//Read data from sensor to variables `temp` and `humid` (`ec` is exit code)
		ec = dhtxxread( DHTXX_DHT11, &PORTC, &DDRC, &PINC, ( 1 << 0 ), &temp, &humid );
		
		
		printf("%d", ec);
		
		_delay_ms(1000);
    }
}

