/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO_header.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPIOHBCTL   *((volatile uint32*)(0x400FE06c))
	//APB
#define 	GPIO_PORTA_BASE_APB				(0x40004000)
#define 	GPIO_PORTB_BASE_APB				(0x40005000)
#define 	GPIO_PORTC_BASE_APB				(0x40006000)
#define 	GPIO_PORTD_BASE_APB				(0x40007000)	
#define 	GPIO_PORTE_BASE_APB				(0x40024000)
#define 	GPIO_PORTF_BASE_APB				(0x40025000)

	//AHB
#define 	GPIO_PORTA_BASE_AHB				(0x40058000)
#define 	GPIO_PORTB_BASE_AHB				(0x40059000)
#define 	GPIO_PORTC_BASE_AHB				(0x4005A000)
#define 	GPIO_PORTD_BASE_AHB				(0x4005B000)			
#define 	GPIO_PORTE_BASE_AHB				(0x4005C000)
#define 	GPIO_PORTF_BASE_AHB				(0x4005D000)
	
//OFFSETS 
#define GPIODIR_BASE			0x400
#define GPIOAFSEL_BASE		0x420
#define GPIOPUR_BASE			0x510
#define GPIOPDR_BASE			0x514
#define GPIOLOCK_BASE			0x520
#define GPIOCR_BASE    		0x524
#define GPIOODR_BASE			0x50C
#define GPIOPUR_BASE			0x510
#define GPIOPDR_BASE			0x514
#define GPIODEN_BASE			0x51C


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void GPIO_PortUnlock( GPIO_PortType, GPIO_PortPeripheralBus);
void GPIO_PortLock( GPIO_PortType, GPIO_PortPeripheralBus);
uint32 GPIO_PortIsLocked( GPIO_PortType , GPIO_PortPeripheralBus )  ;
void GPIO_PortCommit( GPIO_PortType, GPIO_PortPeripheralBus);
void GPIO_PortUnCommit( GPIO_PortType, GPIO_PortPeripheralBus);
#endif  /* GPIO_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
