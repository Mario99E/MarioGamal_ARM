/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_HEADER_H
#define GPIO_HEADER_H

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
//pin enum
typedef enum
{
	GPIO_PIN_A0,
	GPIO_PIN_A1,
	GPIO_PIN_A2,
	GPIO_PIN_A3,
	GPIO_PIN_A4,
	GPIO_PIN_A5,
	GPIO_PIN_A6,
	GPIO_PIN_A7,
	
	GPIO_PIN_B0,
	GPIO_PIN_B1,
	GPIO_PIN_B2,
	GPIO_PIN_B3,
	GPIO_PIN_B4,
	GPIO_PIN_B5,
	GPIO_PIN_B6,
	GPIO_PIN_B7,
	
	GPIO_PIN_C0,
	GPIO_PIN_C1,
	GPIO_PIN_C2,
	GPIO_PIN_C3,
	GPIO_PIN_C4,
	GPIO_PIN_C5,
	GPIO_PIN_C6,
	GPIO_PIN_C7,
	
	GPIO_PIN_D0,
	GPIO_PIN_D1,
	GPIO_PIN_D2,
	GPIO_PIN_D3,
	GPIO_PIN_D4,
	GPIO_PIN_D5,
	GPIO_PIN_D6,
	GPIO_PIN_D7,
	
	GPIO_PIN_E0,
	GPIO_PIN_E1,
	GPIO_PIN_E2,
	GPIO_PIN_E3,
	GPIO_PIN_E4,
	GPIO_PIN_E5,
	
	GPIO_PIN_F0=40,
	GPIO_PIN_F1,
	GPIO_PIN_F2,
	GPIO_PIN_F3,
	GPIO_PIN_F4,

	
} GPIO_PinType;
//port enum
typedef enum
{
	GPIO_PORT_A,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_D,
	GPIO_PORT_E,
	GPIO_PORT_F,
}GPIO_PortType;
//pin direcction
typedef enum
{
	GPIO_INPUT_PULL_UP,
	GPIO_INPUT_PULL_DOWN,
	
	GPIO_OUTPUT,
	GPIO_OUTPUT_OPEN_DRAIN
}GPIO_Direction;
//enum for outputState
typedef enum
{
	GPIO_LOW,
	GPIO_HIGH
}GPIO_OutputState;

/*ToDo  enum for each pin function options digital/analog*/

//port bus options
typedef enum
{
	GPIO_AHB,
	GPIO_APB
}GPIO_PortPeripheralBus;
//GPIO or alternative
typedef enum
{
	GPIO_NORMAL_FUNCTION,
	GPIO_ALTERNATIVE_FUNCTION
}GPIO_FunctionType;
typedef enum
{
	GPIO_PIN_INTERFACE,
	GPIO_PORT_INTERFACE
}GPIO_InterfaceType;
//struct to hold all pin data
typedef struct
{
	GPIO_PinType pin;
	GPIO_Direction dir;
	GPIO_PortPeripheralBus bus;
	GPIO_FunctionType function;
	/*ToDo union hold the function of all pins*/
}GPIO_PinInterface;
//struct to hold all Port data
typedef struct
{
	GPIO_PortType pin;
	GPIO_Direction dir;
	GPIO_PortPeripheralBus bus;
	GPIO_FunctionType function;
	/*ToDo union hold the function of all pins*/
}GPIO_PortInterface;

//union for interface
typedef union
{
	GPIO_PinInterface pinInterface;
	GPIO_PinInterface portInterface;
}GPIO_InterfaceByPinOrPort;
//struct to hold pin/port data
typedef struct
{
	GPIO_InterfaceType interfaceType;
	GPIO_InterfaceByPinOrPort interface;
}GPIO_Interface;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void GPIO_PinInit(GPIO_Interface myInterface);

void GPIO_PinWrite(GPIO_PinInterface ,GPIO_OutputState);
uint32 GPIO_PinRead(GPIO_PinType);
void GPIO_PinToogle(GPIO_PinType);

void GPIO_PortWrite(GPIO_PortType,uint32 value,uint32 mask);
uint32 GPIO_PortRead(GPIO_PortType,int mask);
void GPIO_PortToogle(GPIO_PortType,int mask);

 
#endif  /* GPIO_HEADER_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
