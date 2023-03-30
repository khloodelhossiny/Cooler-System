/*
 * Cooler_sys.c
 *
 * Created: 12/21/2022 1:37:20 PM
 * Author : Ve-ga
 */ 

#include "lcd.h"
#include "Timer0.h"
#include "Seven_Seg.h"
#include "PWM.h"
#include "ADC.h"
#define DC_direction SETBIT(DDRD,0);SETBIT(DDRD,1);SETBIT(PORTD,0);CLRBIT(PORTD,1);
#define start_degree_temp 35
#define  const_speed 6
#define  clear_row LCD_write_char(' ');LCD_write_char(' ');
uint16_t temp = 0;
int main(void)
{

	ADC_init();
    seven_seg_init();
    LCD_init();
    Timer0_normal_init();
	PWM1_OC1A_init();
	DC_direction;
	uint8_t speed = 0;
	SETBIT(DDRA,1);
    while (1) 
    {	
		temp = ADC_read(0);
		temp = (temp - 1) / 2.0;  // to convert the volt(0 - 5) to actual temperature
		clear_row;
		LCD_write_command(0x80);
		LCD_write_string("Temperature = ");
		LCD_write_number(temp);
		if(temp > start_degree_temp){
			SETBIT(PORTA, 1);  // on led
			speed = (temp - start_degree_temp) * const_speed;
			if(speed >= 90){
				speed = 100;
			}
		}
		else{
			CLRBIT(PORTA, 1); // off led
			speed = 0;
		}
		clear_row;
		LCD_write_command(0xC0);
		LCD_write_string("Speed = ");
		LCD_write_number(speed);
		PWM1_OC1A_duty(speed);		
    }
}
ISR(TIMER0_OVF_vect){// 1/16
	static uint8_t seven_seg_num = 0;
	if(seven_seg_num == 0) {
		seven_seg_write(temp / 10, 1);
		seven_seg_num = 1;
	}
	else{
		seven_seg_write(temp % 10, 2);
		seven_seg_num = 0;
	}		
}

