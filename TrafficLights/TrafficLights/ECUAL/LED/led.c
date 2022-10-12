/*
 * led.c
 *
 * Created: 10/3/2022 6:01:40 PM
 *  Author: Mariam
 */ 

#include "led.h"

void LED_init(uint8_t ledPort,uint8_t ledPin){ //led is an output device
	DIO_init(ledPort,ledPin,OUT);	 //since led is an output device
}

void LED_ON(uint8_t ledPort,uint8_t ledPin){
	DIO_write(ledPort,ledPin,HIGH);  
}

void LED_OFF(uint8_t ledPort,uint8_t ledPin){
	DIO_write(ledPort,ledPin,LOW);
}
void LED_toggle(uint8_t ledPort,uint8_t ledPin){
	DIO_toggle(ledPort,ledPin);
}
