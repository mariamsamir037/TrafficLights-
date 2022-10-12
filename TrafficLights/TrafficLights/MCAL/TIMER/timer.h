/*
 * timer.h
 *
 * Created: 10/8/2022 10:44:37 PM
 *  Author: Mariam
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../ECUAL/LED/led.h"

#define overflow_5sec 20       //normal delay when on
#define overflow_halfsec 2     //used in blinking

void timer0_init(void);
void timer0_start(void);
void timer0_stop(unsigned int NumbOfOverflows);
void blink_1led(uint8_t Seconds,uint8_t portNumber,uint8_t pinNumber);  //blink function
void blink_2leds(uint8_t Seconds,uint8_t portNumber1, uint8_t portNumber2, uint8_t pinNumber1, uint8_t pinNumber2);


#endif /* TIMER_H_ */