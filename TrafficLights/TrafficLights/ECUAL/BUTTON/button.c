/*
 * button.c
 *
 * Created: 10/3/2022 9:38:59 PM
 *  Author: Mariam
 */ 

#include "button.h"

void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);      //since button is an input device
}
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value){
	DIO_read(buttonPort, buttonPin, value);			
}

