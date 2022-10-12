/*
* app.c
*
* Created: 10/6/2022 5:49:53 PM
*  Author: Mariam
*/

#include "app.h"

uint8_t bitState=LOW;
uint8_t mode=NORMAL_MODE;

void init_app(void)
{
	BUTTON_init(PORT_D,2);      //button configuration/int0
	
	//initialize cars' LEDS using PORTA
	LED_init(PORT_A,0);
	LED_init(PORT_A,1);
	LED_init(PORT_A,2);
	
	//initialize pedestrian mode LEDS using PORTB
	LED_init(PORT_B,0);
	LED_init(PORT_B,1);
	LED_init(PORT_B,2);
	
	//interrupt configuration
	enable_global_interrupt();
	interrupt_sense_risingEdge ();
	enable_external_INT0();
	
	//TIMER configuration
	timer0_init();
}

void start_app(void)
{
	switch (mode)
	{
		case NORMAL_MODE:      //normal mode when no interrupt takes place
		LED_ON(PORT_A,0);     //green led is on
		timer0_start();
	    timer0_stop(overflow_5sec);   //delay of 5 sec
		LED_OFF(PORT_A,0);   //green led is off

		blink_1led(5,PORT_A,1);   //yellow led blinks for 5 sec
		
		LED_ON(PORT_A,2);     //red led is on
		timer0_start();
		timer0_stop(overflow_5sec);   //delay of 5 sec
		LED_OFF(PORT_A,2);     //red led is off

		blink_1led(5,PORT_A,1);     //yellow led blinks for 5 sec
		break;

		case PEDESTRIAN_MODE:   //when crosswalk button is pressed once we enter pedestrian mode
		disable_global_interrupt();		//to avoid any changes when button is pressed twice in a row
		DIO_read(PORT_A, 2, &bitState);   //read the current state of pin2 in portA (state of red light)
		if (bitState==HIGH)   //if red light is on
		{
			LED_ON(PORT_B,0);   //pedestrian green light is on
			LED_ON(PORT_A,2);	//cars' red light is on
			timer0_start();
			timer0_stop(overflow_5sec);   //delay of 5 sec
			LED_OFF(PORT_B,0);
			LED_OFF(PORT_A,2);
		}
		else{
			LED_ON(PORT_B,2);    //red pedestrian is on
			timer0_start();
			timer0_stop(overflow_5sec);   //delay of 5 sec
			LED_OFF(PORT_B,2);    //red pedestrian is off
			LED_OFF(PORT_A,0);	//green cars is off
			blink_2leds(5,PORT_A,PORT_B,1,1);   //both yellow blink for 5 sec

			LED_ON(PORT_B,0);    //green pedestrian is on
			LED_ON(PORT_A,2);	//red car is on
			timer0_start();
			timer0_stop(overflow_5sec);   //delay of 5 sec
		}
		LED_OFF(PORT_A,2);	//red car is off
		blink_2leds(5,PORT_A,PORT_B,1,1);   //both yellow blink for 5 sec
		LED_OFF(PORT_B,0);    //green pedestrian is off
		LED_ON(PORT_B,2);		//pedestrian red led is on
		LED_ON(PORT_A,0);		//cars' green led is on
		timer0_start();
		timer0_stop(overflow_5sec);   //delay of 5 sec
		LED_OFF(PORT_B,2);		//pedestrian red led is off 34an nroo7 ll normal mode
		LED_OFF(PORT_A,0);
		enable_global_interrupt();    //enable interrupts for future button presses
		mode=NORMAL_MODE;    //return to normal mode flow
		break;
	}
}

ISR(EXT_INT0_vect){
	mode=PEDESTRIAN_MODE;
	start_app();
}





