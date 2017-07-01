/*
 * versao_git.c
 *
 * Created: 6/25/17 9:12:16 AM
 * Author :Vinicius Cardoso
 */ 

#include "def_principais.h"
#include "lcd.h"
#include "one_wire.h"

FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void)
{
    uint8_t temp_LSB, temp_MSB;
	DDRD  = 0xff;		// Set PortD as Out
	
	// Init LCD
	inic_LCD_4bits();
	stdout=&lcd_str;
	
	// First Print on Display
	cmd_LCD(0x80,0);
	printf("Inicializando..");
	
    while (1) 
    {
        reset_1w();                     //reset do sensor (a resposta de presença é retornada mas não avaliada).
        write_byte_1w(0xCC);            //comando para pular ROM (só 1 dispositivo no barramento).
        write_byte_1w(0x44);            //manda iniciar a conversão

        reset_1w();
        write_byte_1w(0xCC);
        write_byte_1w(0xBE);            //avisa que quer ler a memória

        temp_LSB = read_byte_1w();      //só interesse em ler os dois bytes da temperatura
        temp_MSB = read_byte_1w();

        cmd_LCD(0x80,0);
        printf("%d %d\r", temp_LSB, temp_MSB);
        _delay_ms(500);


		
    }
}

