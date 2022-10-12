/*
 * interrupts.h
 *
 * Created: 10/8/2022 11:00:45 PM
 *  Author: Mariam
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../../UTILITIES/registers.h"

/************************************************************************/
/*			FUNCTIONS' PROTOTYPES                                    */
/************************************************************************/
void enable_global_interrupt(void);
void disable_global_interrupt(void);
void interrupt_sense_risingEdge (void);
void enable_external_INT0(void);
/*
#define ISC01   1
#define ISC00   0
*/

#define EXT_INT0_vect __vector_1

#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__((signal,used)); \
void INT_VECT(void)


#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli() __asm__ __volatile__ ("cli" ::: "memory") // Clear the I-Bit in status register to 0

#endif /* INTERRUPTS_H_ */