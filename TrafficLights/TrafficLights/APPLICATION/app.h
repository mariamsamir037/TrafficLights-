/*
 * app.h
 *
 * Created: 10/9/2022 3:30:07 PM
 *  Author: Mariam
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/LED/led.h"
#include "../MCAL/INTERRUPTS/interrupts.h"
#include "../MCAL/TIMER/timer.h"

typedef enum traffic_mode{
	NORMAL_MODE, PEDESTRIAN_MODE
}traffic_mode;

void start_app(void);
void init_app(void);


#endif /* APP_H_ */