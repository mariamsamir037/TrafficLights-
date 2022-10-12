/*
* timer.c
*
* Created: 10/8/2022 10:45:52 PM
*  Author: Mariam
*/
#include "timer.h"
unsigned int overflowCounter=0;

void blink_1led(uint8_t Seconds,uint8_t portNumber,uint8_t pinNumber){  //blink function
	for(uint8_t i=0;i<Seconds;i++){
		overflowCounter=0;
		LED_ON(portNumber,pinNumber);
		
		timer0_start();
		timer0_stop(overflow_halfsec);
		
		LED_OFF(portNumber,pinNumber);
		
		timer0_start();
		timer0_stop(overflow_halfsec);
	}
	overflowCounter=0;
}

void blink_2leds(uint8_t Seconds,uint8_t portNumber1,uint8_t portNumber2, uint8_t pinNumber1, uint8_t pinNumber2){
	for(uint8_t i=0;i<Seconds;i++){
		overflowCounter=0;

		LED_ON(portNumber1,pinNumber1);
		LED_ON(portNumber2,pinNumber2);
		timer0_start();
		timer0_stop(overflow_halfsec);
		
		LED_OFF(portNumber1,pinNumber1);
		LED_OFF(portNumber2,pinNumber2);
		timer0_start();
		timer0_stop(overflow_halfsec);
	}
	overflowCounter=0;

	LED_OFF(portNumber1,pinNumber1);
	LED_OFF(portNumber2,pinNumber2);

}

void timer0_init(void){
	TCCR0 =0x00;		//normal mode
	TCNT0 =0x0C;		//set timer initial value to 12
}
void timer0_start(void){
	overflowCounter=0;
	TCCR0 |=(1<<0)|(1<<2);		//start timer with pre-scalar value=1024
}

void timer0_stop(unsigned int NumbOfOverflows)
{
	while(overflowCounter < NumbOfOverflows){
		while((TIFR &(1<<0))== 0);	//busy wait l7d ma el overflow y7sl y3ny l7d ma el overflow bit/flag==1
		TIFR|=(1<<0);   //lazm a3ml clear ll overflow flag b3d kol overflow ezay? by writing on it
		overflowCounter++;
	}
	overflowCounter=0;
	TCCR0= 0x00;		//timer stop
}
