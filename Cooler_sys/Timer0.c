/*
 * Timer0.c
 *
 * Created: 11/22/2022 11:35:26 PM
 *  Author: Ve-ga
 */ 

#include "Timer0.h"

void Timer0_normal_init(void){
	TCCR0 = (1 << FOC0) | (1 << CS00) | (1 << CS01) ;// 64 prescaler 
	SETBIT(TIMSK, TOIE0);
	SETBIT(SREG, 7);
}
void Timer0_CTC_init(uint8_t max){
	TCCR0 = (1 << FOC0) | (1 << WGM01) | (1 << CS01);      //prescaler 8 CS01
	OCR0 = max;
	SETBIT(TIMSK, OCIE0);
	SETBIT(SREG, 7);
}
void Timer0_frq_gen_init(uint8_t max){
	SETBIT(DDRB, 3);
	OCR0 = max;
	TCCR0 = (1 << FOC0) | (1 << WGM01) | (1 << COM00) | (1 << CS00) ;
}