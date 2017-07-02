/*
 * versao_git.c
 *
 * Created: 6/25/17 9:12:16 AM
 * Author :Vinicius Cardoso
 */ 

#include "def_principais.h"
#include "lcd.h"
#include "one_wire.h"
#include "DHT.h"

// macros privadas
#define DQ_OUTPUT()		set_bit(DDRx,DQ)
#define DQ_INPUT()		clr_bit(DDRx,DQ)
#define CLR_DQ()		clr_bit(PORTx,DQ)
#define SET_DQ()		set_bit(PORTx,DQ)
#define TST_DQ()		tst_bit(PINx,DQ)


FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void)
{

    int i,t;

	// Init LCD
    DDRD  = 0xff;
	inic_LCD_4bits();
	stdout=&lcd_str;
    // Viriáveis
    // int cont=0;

    //uint8_t data [4];
    //int i,j,cnt;
    int cont=0;

    

    // Mensagem Iniciando LCD
	/* cmd_LCD(0x80,0);
	printf("Inicializando..");
    _delay_ms(1000);
    cmd_LCD(0x80,0);
    printf("                                  "); */
	
    while (1) 
    {

        //TCCR0B = (1<<CS01); // Preescaler 8 (0.5us por bit)
        //TCCR0B = (1<<CS02)|(1<<CS00); // Preescaler 1024 (64us por bit)

        uint8_t data,data2,data3,data4;
        
        // Enviar comando
        DQ_OUTPUT();            //DQ como saída
        CLR_DQ();               //DQ em nível zero 
        _delay_ms(19);      //Por 19 ms
        SET_DQ();               //DQ em nível alto
        DQ_INPUT();             //DQ como entrada, o resistor de pull-up mantém DQ em nível alto

        //TCCR0B = (1<<CS01); // Preescaler 8 (0.5us por bit)
        

        // if(i=0;i<5;i++){
        //     if(j=7;j>=0;j--){

        //     }
        // }

        // while(TST_DQ());
        // while(!TST_DQ());

        
        
        
        // /* Then wait for the second response to finish, high ~80µs */
        // while(IS_SET(DHT_PORT_IN,DHT_PIN))
        // { if (TCNT0 >= 100) return 0; }

        
        
        // cmd_LCD(0x80,0);
        while(TST_DQ());
        while(!TST_DQ());        

        for (i = 8; i > 0 ; --i){

            cont=0;

            while(!TST_DQ());
            
            while(TST_DQ()){
                cont = ++cont;
                _delay_us(1);
            }

            if(cont >= 5 && cont <= 18)
            { CLEAR_BIT(data,i); }

            else if (cont >= 20 && cont <= 65)
            { SET_BIT(data,i); }

        }

        for (i = 8; i > 0 ; --i){

            cont=0;

            while(!TST_DQ());
            
            while(TST_DQ()){
                cont = ++cont;
                _delay_us(1);
            }

            if(cont >= 5 && cont <= 18)
            { CLEAR_BIT(data2,i); }

            else if (cont >= 20 && cont <= 65)
            { SET_BIT(data2,i); }

        }

        for (i = 8; i > 0 ; --i){

            cont=0;

            while(!TST_DQ());
            
            while(TST_DQ()){
                cont = ++cont;
                _delay_us(1);
            }

            if(cont >= 5 && cont <= 18)
            { CLEAR_BIT(data3,i); }

            else if (cont >= 20 && cont <= 65)
            { SET_BIT(data3,i); }

        }

        for (i = 8; i > 0 ; --i){

            cont=0;

            while(!TST_DQ());
            
            while(TST_DQ()){
                cont = ++cont;
                _delay_us(1);
            }

            if(cont >= 5 && cont <= 18)
            { CLEAR_BIT(data4,i); }

            else if (cont >= 20 && cont <= 65)
            { SET_BIT(data4,i); }

        }

        cmd_LCD(0x80,0);
        printf("Umid: %d%%", data);
        cmd_LCD(0xC0,0);
        printf("Temp: %d*C ", data3);
        
        



        
    
        // printf("%d", data[1]);

        _delay_ms(500);

        /* if(TST_DQ()){

            printf("Alto");

            while(TST_DQ()){
                i = i+1;
                total = i;
                _delay_ms(1);
            }
            cmd_LCD(0xC0,0);
            printf("%d\n", total);

            while(!TST_DQ());


            while(TST_DQ()){
                i = i++;
                total = i;
                _delay_ms(1);
            }

            printf("%d\n", total); */

            // for (i = 0; i < 5; ++i)
            // {
            //     for(j = 7; j >= 0; --j)
            //     {
                    
            //         /* First there is always a 50µs low period */
            //         while(!TST_DQ());
                    
            //         /* Then the data signal is sent. 26 to 28µs (ideally)
            //          indicate a low bit, and around 70µs a high bit */
            //         while(TST_DQ())
            //         {
            //             cont = cont++;
            //             _delay_us(1);
            //         }
            //         cmd_LCD(0x80,0);
            //         if(cont<25){
            //             printf("0\n");
            //         }else if(cont<75){
            //             printf("1\n");
            //         }else{
            //             printf("Terminou\n");
            //         }
                    
            //         /* Store the value now so that the whole checking doesn't
            //          move the TCNT0 forward by too much to make the data look
            //          bad */
            //         /*cnt = TCNT0;
                    
            //         if (cnt >= 20 && cnt <= 35)
            //         { CLEAR_BIT(data[i],j); }
                    
            //         else if (cnt >= 60 && cnt <= 80)
            //         { SET_BIT(data[i],j); }
                    
            //         else return 0;*/
            //     }
            // }
        /*}else{
            printf("Beixo");
        }
            
        _delay_ms(100);*/

    }
}
