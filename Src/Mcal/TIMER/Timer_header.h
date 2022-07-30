/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_HEADER_H
#define TIMER_HEADER_H

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
typedef enum
{
	TIMER_TIMER_0,
	TIMER_TIMER_1,
	TIMER_TIMER_2,
	TIMER_TIMER_3,
	TIMER_TIMER_4,
	TIMER_TIMER_5,
	TIMER_TIMER_W_0,
	TIMER_TIMER_W_1,
	TIMER_TIMER_W_2,
	TIMER_TIMER_W_3,
	TIMER_TIMER_W_4,
	TIMER_TIMER_W_5,
	
	
}Timer_TimerType;
typedef enum
{
	TIMER_CHANNEL_A,
	TIMER_CHANNEL_B
}Timer_channel;
typedef enum
{
	TIMER_ONE_SHOT_MODE=1,
	TIMER_PERIODIC_MODE=2
}Timer_Modes;

typedef enum
{
		TIMER_WAIT_ON_TIGGER_OFF,
	TIMER_WAIT_ON_TIGGER_ON

	
}Timer_WaitOnTriggerState;

typedef enum
{
	TIMER_NO_INTERRUPT,
	TIMER_PWM_INTERRUPT_ENABEL,
	TIMER_A_MATCH_INTERRUPT_ENABLE,
	TIMER_TIME_OUT_INTERRUPT_ENABLE
	
}Timer_InterruptEnable;

typedef enum
{
	TIMER_COUNT_DOWN,
	TIMER_COUNT_UP
	
}Timer_Direction;

typedef struct
{
	Timer_TimerType timerNum;
	Timer_channel cha;
	Timer_Direction dir;
	Timer_Modes mode;
	Timer_InterruptEnable interrupt;
	Timer_WaitOnTriggerState onTrigger;
	uint32 startValue;
}Timer_TimerConfig;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Timer_Init(Timer_TimerConfig );
void Timer_Timer0ASetCallBack(void(*CallBack)(void));
 
#endif  /* TIMER_HEADER_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
