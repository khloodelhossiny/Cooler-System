/*
 * Timer0.h
 *
 * Created: 11/22/2022 11:35:44 PM
 *  Author: Ve-ga
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "std_macros.h"
void Timer0_normal_init(void);
void Timer0_CTC_init(uint8_t max);
void Timer0_frq_gen_init(uint8_t max);



#endif /* TIMER0_H_ */