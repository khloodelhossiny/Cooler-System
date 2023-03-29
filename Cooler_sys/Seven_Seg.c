/*
 * Seven_Seg.c
 *
 * Created: 11/18/2022 1:02:11 PM
 *  Author: safifi
 */ 

#include "Seven_Seg.h"
#include "seven_Seg_cfg.h"
uint8_t ss_data [] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x7,0x7f,0x6f};
	                           
	                  
void seven_seg_init(void){
	SEVEN_SEG_INIT_PORTS();
	uint8_t i = 0;
	/* convert array element from cathode to anode*/
#ifdef SS_ANODE
	for(i = 0; i < 10; i++){
		ss_data[i] ^= 0b01111111;  
	}	
#endif
}
void seven_seg_write(uint8_t num, uint8_t ss_num){ 
	EN1_DIS();EN2_DIS();
	switch(ss_num){
		case 1: EN1_EN(); break;
		case 2: EN2_EN(); break;
	}
	SS_PORT &= 0b10000000;
	SS_PORT |= ss_data[num];
}