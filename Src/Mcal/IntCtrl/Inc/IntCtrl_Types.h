/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//ENUM OF ALL INTERRRUPTS ,VALUE IS interrupt NUMBER
typedef enum
{
	INTCTRL_GPIO_PORTA=0,
	INTCTRL_GPIO_PORTB,
	INTCTRL_GPIO_PORTC,
	INTCTRL_GPIO_PORTD,
	INTCTRL_GPIO_PORTE,
	INTCTRL_UART0,
	INTCTRL_UART1,
	INTCTRL_SSI0,
	INTCTRL_I2C0,
	INTCTRL_PWM0_FAULT,
	INTCTRL_PWM0_GENERATOR0,
	INTCTRL_PWM0_GENERATOR1,
	INTCTRL_PWM0_GENERATOR2,
	INTCTRL_QEI0,
	INTCTRL_ADC0_SEQ0,
	INTCTRL_ADC0_SEQ1,
	INTCTRL_ADC0_SEQ2,
	INTCTRL_ADC0_SEQ3,
	INTCTRL_WATCHDOG_TIMER0AND1,
	INTCTRL_16_32_BIT_TIMER0A,
	INTCTRL_16_32_BIT_TIMER0B,
	INTCTRL_16_32_BIT_TIMER1A,
	INTCTRL_16_32_BIT_TIMER1B,
	INTCTRL_16_32_BIT_TIMER2A,
	INTCTRL_16_32_BIT_TIMER2B,
	INTCTRL_ANALOG_COMPARATOR0,
	INTCTRL_ANALOG_COMPARATOR1,
	INTCTRL_SYSTEM_CONTROL=28,
	INTCTRL_FLASH_MEMEORY_AND_EEPROM_CONTROL,
	INTCTRL_GPIO_PORTF,
	INTCTRL_UART2=33,
	INTCTRL_SSI1,
	INTCTRL_16_32_BIT_TIMER3A,
	INTCTRL_16_32_BIT_TIMER3B,
	INTCTRL_I2C1,
	INTCTRL_QEI1,
	INTCTRL_CAN0,
	INTCTRL_CAN1,
	INTCTRL_HIBERNATION_MODULE=43,
	INTCTRL_USB,
	INTCTRL_PWM_GENERATOR3,
	INTCTRL_uDMA_SOFTWARE,
	INTCTRL_uDMA_ERROR,
	INTCTRL_ADC1_SEQ0,
	INTCTRL_ADC1_SEQ1,
	INTCTRL_ADC1_SEQ2,
	INTCTRL_ADC1_SEQ3,
	INTCTRL_SSI2=57,
	INTCTRL_SSI3,
	INTCTRL_UART3,
	INTCTRL_UART4,
	INTCTRL_UART5,
	INTCTRL_UART6,
	INTCTRL_UART7,
	INTCTRL_I2C2=68,
	INTCTRL_I2C3,
	INTCTRL_16_32_BIT_TIMER4A,
	INTCTRL_16_32_BIT_TIMER4B,
	INTCTRL_16_32_BIT_TIMER5A=92,
	INTCTRL_16_32_BIT_TIMER5B,
	INTCTRL_32_64_BIT_TIMER0A,
	INTCTRL_32_64_BIT_TIMER0B,
	INTCTRL_32_64_BIT_TIMER1A,
	INTCTRL_32_64_BIT_TIMER1B,
	INTCTRL_32_64_BIT_TIMER2A,
	INTCTRL_32_64_BIT_TIMER2B,
	INTCTRL_32_64_BIT_TIMER3A,
	INTCTRL_32_64_BIT_TIMER3B,
	INTCTRL_32_64_BIT_TIMER4A,
	INTCTRL_32_64_BIT_TIMER4B,
	INTCTRL_32_64_BIT_TIMER5A,
	INTCTRL_32_64_BIT_TIMER5B,
	INTCTRL_SYSTEM_EXCEPRION,
	INTCTRL_PWM1_GENERATOR0=134,
	INTCTRL_PWM1_GENERATOR1,
	INTCTRL_PWM1_GENERATOR2,
	INTCTRL_PWM1_GENERATOR3,
	INTCTRL_PWM1_FAULT,
}IntCtrl_InterruptType;
//struct carry the interrupt number&its priorit for user config
typedef struct
{
	IntCtrl_InterruptType interuuptType;
	uint8 priority;
}IntCtrl_IntCFgType;

////ENUM OF exception ,VALUE IS vector NUMBER
typedef enum
{
	INTCTRL_MEMORY_MANEGMENT=4,
	INTCTRL_BUS_FAULT,
	INTCTRL_USAGE_FAULT,
	INTCTRL_SVCALL=11,
	INTCTRL_DEBUG_MONITOR,
	INTCTRL_PEND_CV=14,
	INTCTRL_SYS_TICK,
	
}IntCtrl_ExceptionType;
//struct carry the exception number&its priorit for user config
typedef struct
{
	IntCtrl_ExceptionType exceptionType;
	uint32 priority;
}IntCtrl_ExceptionCFgType;
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
