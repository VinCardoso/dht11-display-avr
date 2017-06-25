/*
 * versao_git.c
 *
 * Created: 6/25/17 9:12:16 AM
 * Author :Vinicius Cardoso
 */ 
#include "def_principais.h"
#include "lcd.h"
#include "dht.h"

FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void)
{
	DDRB  = 0xff;		// Set PortB as Out
	
	// Init LCD
	inic_LCD_4bits();
	stdout=&lcd_str;
	
	int try_time = 0;
	int8_t temperatura;
	
	cmd_LCD(0x80,0);
	printf("Inicializando..");
	_delay_ms(500);
	
	dht_gettemperature(temperatura);
	cmd_LCD(0xC0,0);
	printf("1 %d",temperatura);
	
    while (1) 
    {

		
		try_time = try_time+1;
		cmd_LCD(0x80,0);
		//printf("Erro: %d Try:%d", ec, try_time);
		cmd_LCD(0xC0,0);
		//printf("Temp: %d *C",temp);
		_delay_ms(2000);
    }
}

