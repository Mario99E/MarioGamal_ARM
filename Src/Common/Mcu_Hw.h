/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct 
{
    uint32    :5;
		uint32 INTA   :3;
	  uint32    :5;
		uint32 INTB   :3;
		uint32    :5;
		uint32 INTC   :3;
		uint32    :5;
		uint32 INTD   :3;
}PRIn_BF;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define VTABLE                                  *( (volatile uint32*) (CORTEXM4_PERI_BASE_ADDRESS+0xD08) )
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define PRI0                                  ((volatile PRIn_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define EN0                                  ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define DIS0                                  ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define SYSPRI1                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define SYSHNDCTRL                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))	
#define RCC                                  *((volatile uint32*)(0x400fe060))	
#define RCGCTIMER                                  *((volatile uint32*)(0x400fe604))	
#define RCGCGPIO                             				*((volatile int*)(0x400fe604))
	

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/



 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
