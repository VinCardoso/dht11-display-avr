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
    uint8_t int_um,dec_um,int_temp,dec_temp;
	DDRD  = 0xff;		// Set PortD as Out
	
	// Init LCD
	inic_LCD_4bits();
	stdout=&lcd_str;
	
	// First Print on Display
	//cmd_LCD(0x80,0);
	//printf("Inicializando..");
    power_1w();
	
    while (1) 
    {
        char buffer[1];

        reset_1w();
        int_um = read_byte_1w();
        dec_um = read_byte_1w();
        int_temp = read_byte_1w();
        dec_temp = read_byte_1w();
        int a = 0;
        cmd_LCD(0x80,0);
        while(a<40){
            printf("%c",read_byte_1w());
            a=a++;
        }
        _delay_ms(2000)
        a=0;


        //reset_1w();                     //reset do sensor (a resposta de presença é retornada mas não avaliada).
        //write_byte_1w(0xCC);            //comando para pular ROM (só 1 dispositivo no barramento).
        //write_byte_1w(0x44);            //manda iniciar a conversão

        //reset_1w();
        //write_byte_1w(0xCC);
        //write_byte_1w(0xBE);            //avisa que quer ler a memória

        //temp = read_byte_1w(); 
        //temp2 = read_byte_1w(); 
        //temp3 = read_byte_1w(); 
        //temp4 = read_byte_1w();     //só interesse em ler os dois bytes da temperatura

        // cmd_LCD(0x80,0);
        // printf("%p\r", (void*)temp);
        // printf("%p\r", (void*)temp2);
        // cmd_LCD(0xC0,0);
        // printf("%p\r", (void*)temp3);
        // printf("%p\r", (void*)temp4);
        // _delay_ms(500);

        // cmd_LCD(0x80,0);
        // printf("%s . %d                    \n", buffer, int_um);
        // cmd_LCD(0xC0,0);
        // printf("%d.%d                    \n", dec_temp, int_temp);
        // _delay_ms(100);


		
    }
}

