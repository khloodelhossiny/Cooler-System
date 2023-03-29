/*
 * seven_Seg_cfg.h
 *
 * Created: 11/18/2022 1:03:00 PM
 *  Author: safifi
 */ 


#ifndef SEVEN_SEG_CFG_H_
#define SEVEN_SEG_CFG_H_
#include "std_macros.h"

#define SS_ANODE
#define SEVEN_SEG_INIT_PORTS() DDRB |= 0x7f; PORTB = 0x7f; SETBIT(DDRC,0); SETBIT(DDRC,1); 
#define SS_PORT PORTB

#ifdef SS_ANODE
	#define EN1_DIS() CLRBIT(PORTC,0);
	#define EN1_EN()  SETBIT(PORTC,0);
	#define EN2_DIS() CLRBIT(PORTC,1);
	#define EN2_EN()  SETBIT(PORTC,1);
	
#else
	#define EN1_DIS() SETBIT(PORTC,0);
	#define EN1_EN()  CLRBIT(PORTC,0);
	#define EN2_DIS() SETBIT(PORTC,1);
	#define EN2_EN()  CLRBIT(PORTC,1);
	
#endif
#endif /* SEVEN_SEG_CFG_H_ */