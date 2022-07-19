/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const int IntCtrl_NumOfInterrupts ;
 
extern const IntCtrl_IntCFgType IntCFg_arr[];

extern const int IntCtrl_NumOfExceptions ;
 
extern const IntCtrl_ExceptionCFgType ExpCFg_arr[];
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{

/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/

	#if (PRIGROUP<8)  //valid value
			APINT = 0x05fa0000 | (PRIGROUP<<8);
	#endif
/*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
	uint8 PRIn_RegisterNumber;
	uint8 PRIn_BitField;
	for(uint8 i=0;i<IntCtrl_NumOfInterrupts;i++)
	{
		PRIn_RegisterNumber=IntCFg_arr[i].interuuptType/4;
		PRIn_BitField=IntCFg_arr[i].interuuptType%4;
		uint8 pri=(IntCFg_arr[i].priority)&(0x7); //clear all bits except first 3bits
		if(PRIn_BitField==0)
			(PRI0+PRIn_RegisterNumber)->INTA=pri;
		else if(PRIn_BitField==1)
			(PRI0+PRIn_RegisterNumber)->INTB=pri;
		else if(PRIn_BitField==2)
			(PRI0+PRIn_RegisterNumber)->INTC=pri;
		else if(PRIn_BitField==3)
			(PRI0+PRIn_RegisterNumber)->INTD=pri;
	}
	for(uint8 i=0;i<IntCtrl_NumOfExceptions;i++)
	{
		uint32 pri=ExpCFg_arr[i].priority&(0x7); //clear all bits except first 3bits
		if(ExpCFg_arr[i].exceptionType == INTCTRL_MEMORY_MANEGMENT)
			SYSPRI1 |= (pri<<5);
		else if(ExpCFg_arr[i].exceptionType == INTCTRL_BUS_FAULT )
			SYSPRI1 |= (pri<<13);
		else if(ExpCFg_arr[i].exceptionType == INTCTRL_USAGE_FAULT )
			SYSPRI1 |= (pri<<21);
		else if(ExpCFg_arr[i].exceptionType == INTCTRL_SVCALL )
			SYSPRI2 |= (pri<<29);
		else if(ExpCFg_arr[i].exceptionType == INTCTRL_DEBUG_MONITOR )
			SYSPRI3 |= (pri<<5);
		else if(ExpCFg_arr[i].exceptionType == INTCTRL_PEND_CV )
			SYSPRI3 |= (pri<<21);
		else if(ExpCFg_arr[i].exceptionType == INTCTRL_SYS_TICK )
			SYSPRI3 |= (pri<<29);
	}

/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */

	//disable all interrupts;
	for(int i=0;i<4;i++)
		*(DIS0+4*i)=0xffffffff;
	//enable intturpt from confi
	uint8 ENn_RegisterNumber;
	uint8 ENn_BitField;
	for(uint8 i=0;i<IntCtrl_NumOfInterrupts;i++)
	{
		ENn_RegisterNumber=IntCFg_arr[i].interuuptType/32;
		ENn_BitField=IntCFg_arr[i].interuuptType%32;
		*(EN0+ENn_RegisterNumber)|=(1<<ENn_BitField);
	}
	//enable exceprionts

	for(uint8 i=0;i<IntCtrl_NumOfExceptions;i++)
	{
		if(ExpCFg_arr[i].exceptionType == INTCTRL_MEMORY_MANEGMENT)
			SYSHNDCTRL |= (1<<16);
		else if(ExpCFg_arr[i].exceptionType == INTCTRL_BUS_FAULT )
			SYSHNDCTRL |= (1<<17);
		else if(ExpCFg_arr[i].exceptionType == INTCTRL_USAGE_FAULT )
			SYSHNDCTRL |= (1<<18);
		
	}

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
