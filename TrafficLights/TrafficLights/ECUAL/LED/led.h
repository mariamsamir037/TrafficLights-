/*
 * led.h
 *
 * Created: 10/3/2022 6:01:30 PM
 *  Author: Mariam
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/dio.h"   //according to layering architecture: upper layers call lower layers w hena el upper howa el led aw lcd aw keypad w el lower howa el dio

void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_ON(uint8_t ledPort,uint8_t ledPin);
void LED_OFF(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);



#endif /* LED_H_ */