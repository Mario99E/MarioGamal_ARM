/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Timer_header.h"
#include "Timer_private.h"
#include "SysCtrl.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void Timer_Timer0ASetCallBack(void(*CallBack)(void))
{
	TIMER_0A_CALLBACK_FUNCITON =CallBack;
}

void Timer_0A_ISR(void)
{
	if(TIMER_0A_CALLBACK_FUNCITON != 0)
		TIMER_0A_CALLBACK_FUNCITON();
	
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Timer_Init(Timer_TimerConfig myTimer)
{
	if(myTimer.timerNum<6)
		SysCtrl_EnablePeripheralClock(SysCtrl_Timer0_16_23_Clock);
	
	for(int i=0;i<5;i++);
	//make sure (the TnEN bit in the GPTMCTL register is cleared)
	if(myTimer.cha == TIMER_CHANNEL_A)
		*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) + GPTMCTL_OFFSET ) ) &= ~(1);
	else
		*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) )+ GPTMCTL_OFFSET ) &= ~(1<<8);

	//Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000.
	if(myTimer.mode <= TIMER_PERIODIC_MODE)
		*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMCFG_OFFSET ) ) =0;
	
	/*Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
			a. Write a value of 0x1 for One-Shot mode.
			b. Write a value of 0x2 for Periodic mode.*/
		
	if(myTimer.cha == TIMER_CHANNEL_A)
	{
		*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTAMR_OFFSET ) ) |= myTimer.mode;
	//	*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTAMR_OFFSET ) ) |= (1<<5);
		//if(myTimer.onTrigger==TIMER_WAIT_ON_TIGGER_ON)
			//*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTAMR_OFFSET ) ) |=(1<<6);
		if(myTimer.dir == TIMER_COUNT_UP)
			*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTAMR_OFFSET ) ) |=(1<<4);
		else
			*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTAMR_OFFSET ) ) &= ~(1<<4);
	}
	else
	{
		*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTBMR_OFFSET ) ) |= myTimer.mode;
		if(myTimer.onTrigger==TIMER_WAIT_ON_TIGGER_ON)
			*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTBMR_OFFSET ) ) |=(1<<6);
		if(myTimer.dir == TIMER_COUNT_UP)
			*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTBMR_OFFSET ) ) |=(1<<4);
		else
			*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTBMR_OFFSET ) ) &= ~(1<<4);
	}
	
		
	
	
	
	/* Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTnMR register
		to select whether to capture the value of the free-running timer at time-out, use an external
	trigger to start counting, configure an additional trigger or interrupt, and count up or down. */



	//Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).
	if(myTimer.cha == TIMER_CHANNEL_A)
		*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTAILR_OFFSET ) )=myTimer.startValue;
	else
		*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMTBILR_OFFSET ) )=myTimer.startValue;

	//If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register (GPTMIMR).
	if(myTimer.interrupt==TIMER_TIME_OUT_INTERRUPT_ENABLE)
	{
		if(myTimer.cha == TIMER_CHANNEL_A)
				*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMIMR_OFFSET ) )|=1;
		else
			*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) +GPTMIMR_OFFSET ) )|=(1<<8);
			
	}
	
	//Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.
	if(myTimer.cha == TIMER_CHANNEL_A)
		*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) + GPTMCTL_OFFSET ) ) |= (1);
	else
		*( (volatile uint32*)( TIMER0_BASE+(myTimer.timerNum *NEXT_TIMER_OFFSET) ) + GPTMCTL_OFFSET ) |= (1<<8);
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
