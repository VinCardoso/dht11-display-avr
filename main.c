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
	
	// First Print on Display
	//cmd_LCD(0x80,0);
	//printf("Init");
	
	// DHT11 Variables
	
	#if DHT_FLOAT == 0
	int8_t temperature = 0;
	int8_t humidity = 0;
	#elif DHT_FLOAT == 1
	float temperature = 0;
	float humidity = 0;
	#endif

	for (;;) {
		if(dht_gettemperaturehumidity(&temperature, &humidity) != -1) {

			#if DHT_FLOAT == 0
			itoa(temperature, printbuff, 10);
			#elif DHT_FLOAT == 1
			//dtostrf(temperature, 3, 3, printbuff);
			#endif
			//uart_puts("temperature: "); uart_puts(printbuff); uart_puts("C");uart_puts("\r\n");
			#if DHT_FLOAT == 0
			//itoa(humidity, printbuff, 10);
			#elif DHT_FLOAT == 1
			//dtostrf(humidity, 3, 3, printbuff);
			#endif
			//uart_puts("humidity: "); uart_puts(printbuff); uart_puts("%RH");uart_puts("\r\n");

			} else {
			//uart_puts("error"); uart_puts("\r\n");
			try_time = try_time+1;
			cmd_LCD(0x80,0);
			printf("error %d",try_time);
			
		}

		//uart_puts("\r\n");

		_delay_ms(1500);
	}

	
	
	
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

