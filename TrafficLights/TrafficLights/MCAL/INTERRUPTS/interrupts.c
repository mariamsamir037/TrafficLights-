/*
* interrupts.c
*
* Created: 10/8/2022 11:00:32 PM
*  Author: Mariam
*/
#include "interrupts.h"

void enable_global_interrupt(void)
{
	//SREG|=(1<<7);    //enable globall interrupts by setting bit I; bit7 y3ny
	sei();
}
void disable_global_interrupt(void){
	cli();
}

void interrupt_sense_risingEdge (void)
{
	//MCUCR = (1<<ISC01) | 1<<ISC00;
	MCUCR |= (1<<1)|(1<<0);     //interrupt sense:rising edge of INT0
	//MCUCR = (1<<1);     //interrupt sense:Falling edge of INT0
	//MCUCR =0x00;     //low level 
	
}

void enable_external_INT0(void)
{
	GICR |=(1<<6);		//external interupt0 enable
}
