/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef 	SYSCTRL_TYPES_H
#define SYSCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*enum for clock source*/
typedef enum
{
	SysCtrl_Main_Oscillator=0,
	SysCtrl_Precision_Internal_Oscillator,
	SysCtrl_Precision_Internal_Oscillator_Divided_By_4,
	SysCtrl_LowFrequency_Internal_Oscillator,
	SySCtrl_Hibernation_Module_Clock_Source
}SysCtrl_ClockSourceType;

/*enum for PLL satat (bypass)*/
typedef enum
{
	SysCtrl_PLL_On=0,
	SysCtrl_PLL_Off	
}SysCtrl_PLL_State;

/*enum for clock divider*/
typedef enum
{
	SysCtrl_Clock_DibidedBy_1=0,
	SysCtrl_Clock_DibidedBy_2,
	SysCtrl_Clock_DibidedBy_3,
	SysCtrl_Clock_DibidedBy_4,
	SysCtrl_Clock_DibidedBy_5,
	SysCtrl_Clock_DibidedBy_6,
	SysCtrl_Clock_DibidedBy_7,
	SysCtrl_Clock_DibidedBy_8,
	SysCtrl_Clock_DibidedBy_9,
	SysCtrl_Clock_DibidedBy_10,
	SysCtrl_Clock_DibidedBy_11,
	SysCtrl_Clock_DibidedBy_12,
	SysCtrl_Clock_DibidedBy_13,
	SysCtrl_Clock_DibidedBy_14,
	SysCtrl_Clock_DibidedBy_15,
	SysCtrl_Clock_DibidedBy_16,
	SysCtrl_Clock_DibidedBy_17,
	SysCtrl_Clock_DibidedBy_18,
	SysCtrl_Clock_DibidedBy_19,
	SysCtrl_Clock_DibidedBy_20,
	SysCtrl_Clock_DibidedBy_21,
	SysCtrl_Clock_DibidedBy_22,
	SysCtrl_Clock_DibidedBy_23,
	SysCtrl_Clock_DibidedBy_24,
	SysCtrl_Clock_DibidedBy_25,
	SysCtrl_Clock_DibidedBy_26,
	SysCtrl_Clock_DibidedBy_27,
	SysCtrl_Clock_DibidedBy_28,
	SysCtrl_Clock_DibidedBy_29,
	SysCtrl_Clock_DibidedBy_30,
	SysCtrl_Clock_DibidedBy_31,
	SysCtrl_Clock_DibidedBy_32,
	SysCtrl_Clock_DibidedBy_33,
	SysCtrl_Clock_DibidedBy_34,
	SysCtrl_Clock_DibidedBy_35,
	SysCtrl_Clock_DibidedBy_36,
	SysCtrl_Clock_DibidedBy_37,
	SysCtrl_Clock_DibidedBy_38,
	SysCtrl_Clock_DibidedBy_39,
	SysCtrl_Clock_DibidedBy_40,
	SysCtrl_Clock_DibidedBy_41,
	SysCtrl_Clock_DibidedBy_42,
	SysCtrl_Clock_DibidedBy_43,
	SysCtrl_Clock_DibidedBy_44,
	SysCtrl_Clock_DibidedBy_45,
	SysCtrl_Clock_DibidedBy_46,
	SysCtrl_Clock_DibidedBy_47,
	SysCtrl_Clock_DibidedBy_48,
	SysCtrl_Clock_DibidedBy_49,
	SysCtrl_Clock_DibidedBy_50,
	SysCtrl_Clock_DibidedBy_51,
	SysCtrl_Clock_DibidedBy_52,
	SysCtrl_Clock_DibidedBy_53,
	SysCtrl_Clock_DibidedBy_54,
	SysCtrl_Clock_DibidedBy_55,
	SysCtrl_Clock_DibidedBy_56,
	SysCtrl_Clock_DibidedBy_57,
	SysCtrl_Clock_DibidedBy_58,
	SysCtrl_Clock_DibidedBy_59,
	SysCtrl_Clock_DibidedBy_60,
	SysCtrl_Clock_DibidedBy_61,
	SysCtrl_Clock_DibidedBy_62,
	SysCtrl_Clock_DibidedBy_63,
	SysCtrl_Clock_DibidedBy_64,
	SysCtrl_Clock_DibidedBy_65,
	SysCtrl_Clock_DibidedBy_66,
	SysCtrl_Clock_DibidedBy_67,
	SysCtrl_Clock_DibidedBy_68,
	SysCtrl_Clock_DibidedBy_69,
	SysCtrl_Clock_DibidedBy_70,
	SysCtrl_Clock_DibidedBy_71,
	SysCtrl_Clock_DibidedBy_72,
	SysCtrl_Clock_DibidedBy_73,
	SysCtrl_Clock_DibidedBy_74,
	SysCtrl_Clock_DibidedBy_75,
	SysCtrl_Clock_DibidedBy_76,
	SysCtrl_Clock_DibidedBy_77,
	SysCtrl_Clock_DibidedBy_78,
	SysCtrl_Clock_DibidedBy_79,
	SysCtrl_Clock_DibidedBy_80,
	SysCtrl_Clock_DibidedBy_81,
	SysCtrl_Clock_DibidedBy_82,
	SysCtrl_Clock_DibidedBy_83,
	SysCtrl_Clock_DibidedBy_84,
	SysCtrl_Clock_DibidedBy_85,
	SysCtrl_Clock_DibidedBy_86,
	SysCtrl_Clock_DibidedBy_87,
	SysCtrl_Clock_DibidedBy_88,
	SysCtrl_Clock_DibidedBy_89,
	SysCtrl_Clock_DibidedBy_90,
	SysCtrl_Clock_DibidedBy_91,
	SysCtrl_Clock_DibidedBy_92,
	SysCtrl_Clock_DibidedBy_93,
	SysCtrl_Clock_DibidedBy_94,
	SysCtrl_Clock_DibidedBy_95,
	SysCtrl_Clock_DibidedBy_96,
	SysCtrl_Clock_DibidedBy_97,
	SysCtrl_Clock_DibidedBy_98,
	SysCtrl_Clock_DibidedBy_99,
	SysCtrl_Clock_DibidedBy_100,
	SysCtrl_Clock_DibidedBy_101,
	SysCtrl_Clock_DibidedBy_102,
	SysCtrl_Clock_DibidedBy_103,
	SysCtrl_Clock_DibidedBy_104,
	SysCtrl_Clock_DibidedBy_105,
	SysCtrl_Clock_DibidedBy_106,
	SysCtrl_Clock_DibidedBy_107,
	SysCtrl_Clock_DibidedBy_108,
	SysCtrl_Clock_DibidedBy_109,
	SysCtrl_Clock_DibidedBy_110,
	SysCtrl_Clock_DibidedBy_111,
	SysCtrl_Clock_DibidedBy_112,
	SysCtrl_Clock_DibidedBy_113,
	SysCtrl_Clock_DibidedBy_114,
	SysCtrl_Clock_DibidedBy_115,
	SysCtrl_Clock_DibidedBy_116,
	SysCtrl_Clock_DibidedBy_117,
	SysCtrl_Clock_DibidedBy_118,
	SysCtrl_Clock_DibidedBy_119,
	SysCtrl_Clock_DibidedBy_120,
	SysCtrl_Clock_DibidedBy_121,
	SysCtrl_Clock_DibidedBy_122,
	SysCtrl_Clock_DibidedBy_123,
	SysCtrl_Clock_DibidedBy_124,
	SysCtrl_Clock_DibidedBy_125,
	SysCtrl_Clock_DibidedBy_126,
	SysCtrl_Clock_DibidedBy_127,
	SysCtrl_Clock_DibidedBy_128,
}SysCtrl_ClockDibider;

typedef struct
{
	SysCtrl_ClockSourceType clockSource;
	SysCtrl_PLL_State  pllState;
	SysCtrl_ClockDibider clockDivider;
	
}SysCtrl_ClockCFgType;

typedef enum
{
	SysCtrl_Timer0_16_23_Clock=0,
	SysCtrl_Timer1_16_23_Clock,
	SysCtrl_Timer2_16_23_Clock,
	SysCtrl_Timer3_16_23_Clock,
	SysCtrl_Timer4_16_23_Clock,
	SysCtrl_Timer5_16_23_Clock,
	SysCtrl_GPIO_PORTA_Clock,
	SysCtrl_GPIO_PORTB_Clock,
	SysCtrl_GPIO_PORTC_Clock,
	SysCtrl_GPIO_PORTD_Clock,
	SysCtrl_GPIO_PORTE_Clock,
	SysCtrl_GPIO_PORTF_Clock
	
	
	
}SysCtrl_PeripheralClock;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* SYSCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
