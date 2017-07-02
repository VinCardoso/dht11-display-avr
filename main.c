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

    int i,f,cont;
    uint8_t data[4];

	// Init LCD
    DDRD  = 0xff;
	inic_LCD_4bits();
	stdout=&lcd_str;

    // Mensagem Iniciando LCD
	cmd_LCD(0x80,0);
	printf("Inicializando..");
    _delay_ms(1000);

    while (1) 
    {

        // Solicitar Conversão - Mestre
        DQ_OUTPUT();            //DQ como saída
        CLR_DQ();               //DQ em nível zero 
        _delay_ms(19);      //Por 19 ms
        SET_DQ();               //DQ em nível alto
        DQ_INPUT();             //DQ como entrada, o resistor de pull-up mantém DQ em nível alto

        // Resposta do Escravo - Conversor
        while(TST_DQ());        // 80us em nível alto
        while(!TST_DQ());       // 80us em nível baixo

        // Pegando dados da Conversão
        for(f=1;f<=4;++f){
            for (i = 8; i > 0 ; --i){

                cont=0;

                while(!TST_DQ());
                
                while(TST_DQ()){
                    cont = ++cont;
                    _delay_us(1);
                }

                if(cont >= 5 && cont <= 18)
                {clr_bit(data[f],i);}

                else if (cont >= 20 && cont <= 65)
                {set_bit(data[f],i);}

            }
        }

        // Imprimir valores no Display
        cmd_LCD(0x80,0);
        printf("Umid: %d%%            ", data[1]);
        cmd_LCD(0xC0,0);
        printf("Temp: %d*C ", data[3]);
        
        // Refaz conversão a cada 200ms
        _delay_ms(200);

    }
}
