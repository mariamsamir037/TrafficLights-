/*
 * dio.h
 *
 * Created: 10/3/2022 3:56:22 PM
 *  Author: Mariam
 */ 
			//each driver msh mo5ss l port mo3yn l2 da ll 32 pin elly 3ndy fel microcontroller


#ifndef DIO_H_
#define DIO_H_
//inclue registers.h elly gowaha kman types.h
#include "../INTERRUPTS/interrupts.h"
//all internal driver typedefs,

/************************************************************************/
/*        macros                                                              */
/************************************************************************/
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'


/************************************************************************/
/*		 enums for directions and values                                      */
/************************************************************************/
enum DIRECTION{
	IN,OUT
	};
	
enum VALUES{
	LOW,HIGH
	};	
/************************************************************************/
/*					function prototypes                                 */
/************************************************************************/

//init function btkoon mwgooda f kol driver becz it gives us control over configuration  
void DIO_init(uint8_t portNumber, uint8_t pinNumber,uint8_t direction); //initializes directions of pins

void DIO_write(uint8_t portNumber, uint8_t pinNumber,uint8_t value); //write data to dio

void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);  //toggle dio

void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value);  //read dio  


#endif /* DIO_H_ */