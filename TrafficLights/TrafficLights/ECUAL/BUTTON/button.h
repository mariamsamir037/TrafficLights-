/*
 * button.h
 *
 * Created: 10/3/2022 9:39:09 PM
 *  Author: Mariam
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/dio.h"

void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* buttonState);



#endif /* BUTTON_H_ */