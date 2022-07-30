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
#include "GPIO_header.h"
#include "GPIO_private.h"
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

/******************************************************************************
* \Syntax          : void GPIO_PortUnlock( GPIO_PortType port, GPIO_PortPeripheralBus bus)       
* \Description     : Unlock th port                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void GPIO_PortUnlock( GPIO_PortType port, GPIO_PortPeripheralBus bus)
{
	if(bus == GPIO_AHB)
		{
			/***************************************************************/
			/*its Advanced High-performance Bus*/
			/***************************************************************/
			*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIOLOCK_BASE+ (port * 0x1000) )  ) = 0x4C4F434B;
		}
		else
		{
			/***************************************************************/
			/*its Advanced Peripheral Bus*/
			/***************************************************************/
				if(port< GPIO_PORT_E)
				{
						*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOLOCK_BASE+ (port* 0x1000) )  ) = 0x4C4F434B;
				}
				else if(port==GPIO_PORT_E)
				{
					*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOLOCK_BASE+ (0x20000) )  ) = 0x4C4F434B;
				}
				else
				{
						*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOLOCK_BASE+ (0x21000) )  ) = 0x4C4F434B;
				}
			
		}
}
/******************************************************************************
* \Syntax          : void GPIO_PortLock( GPIO_PortType port, GPIO_PortPeripheralBus bus)      
* \Description     : Lock th port                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void GPIO_PortLock( GPIO_PortType port, GPIO_PortPeripheralBus bus)
{
	if(bus == GPIO_AHB)
		{
			/***************************************************************/
			/*its Advanced High-performance Bus*/
			/***************************************************************/
			*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIOLOCK_BASE+ (port * 0x1000) )  ) = 0x00f;
		}
		else
		{
			/***************************************************************/
			/*its Advanced Peripheral Bus*/
			/***************************************************************/
				if(port< GPIO_PORT_E)
				{
						*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOLOCK_BASE+ (port* 0x1000) )  ) = 0x00f;
				}
				else if(port==GPIO_PORT_E)
				{
					*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOLOCK_BASE+ (0x20000) )  ) = 0x00f;
				}
				else
				{
						*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOLOCK_BASE+ (0x21000) )  ) = 0x00f;
				}
			
		}
}

/******************************************************************************
* \Syntax          : bool GPIO_PortIsLocked( GPIO_PortType port, GPIO_PortPeripheralBus bus)      
* \Description     : return if port is Locked or not                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : uint32  zero_unlocked
*                            1_locked                                  
*******************************************************************************/
uint32 GPIO_PortIsLocked( GPIO_PortType port, GPIO_PortPeripheralBus bus)  
{
	if(bus == GPIO_AHB)
		{
			/***************************************************************/
			/*its Advanced High-performance Bus*/
			/***************************************************************/
			return  *( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIOLOCK_BASE+ (port * 0x1000) )  );
		}
		else
		{
			/***************************************************************/
			/*its Advanced Peripheral Bus*/
			/***************************************************************/
				if(port< GPIO_PORT_E)
				{
						return 		*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOLOCK_BASE+ (port* 0x1000) )  );
				}
				else if(port==GPIO_PORT_E)
				{
						return *( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOLOCK_BASE+ (0x20000) )  ) ;
				}
				else
				{
						return *( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOLOCK_BASE+ (0x21000) )  ) ;
				}
			
		}
}

/******************************************************************************
* \Syntax          : void GPIO_PortCommit( GPIO_PortType, GPIO_PortPeripheralBus);      
* \Description     : set commit port to one //can be written                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : uint32  zero_unlocked
*                            1_locked                                  
*******************************************************************************/
void GPIO_PortCommit( GPIO_PortType port, GPIO_PortPeripheralBus bus)
{
	if(bus == GPIO_AHB)
		{
			/***************************************************************/
			/*its Advanced High-performance Bus*/
			/***************************************************************/
			*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIOCR_BASE+ (port * 0x1000) )  ) = 0xff;
		}
		else
		{
			/***************************************************************/
			/*its Advanced Peripheral Bus*/
			/***************************************************************/
				if(port< GPIO_PORT_E)
				{
						*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOCR_BASE+ (port* 0x1000) )  ) = 0xff;
				}
				else if(port==GPIO_PORT_E)
				{
					*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOCR_BASE+ (0x20000) )  ) = 0xff;
				}
				else
				{
						*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOCR_BASE+ (0x21000) )  ) = 0xff;
				}
	
		}
}
/******************************************************************************
* \Syntax          :void GPIO_PortUnCommit( GPIO_PortType port, GPIO_PortPeripheralBus bus);      
* \Description     : set commit port to zero //cant be written                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : uint32  zero_unlocked
*                            1_locked                                  
*******************************************************************************/
void GPIO_PortUnCommit( GPIO_PortType port, GPIO_PortPeripheralBus bus)
{
	if(bus == GPIO_AHB)
		{
			/***************************************************************/
			/*its Advanced High-performance Bus*/
			/***************************************************************/
			*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIOCR_BASE+ (port * 0x1000) )  ) = 0x00;
		}
		else
		{
			/***************************************************************/
			/*its Advanced Peripheral Bus*/
			/***************************************************************/
				if(port< GPIO_PORT_E)
				{
						*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOCR_BASE+ (port* 0x1000) )  ) = 0x00;
				}
				else if(port==GPIO_PORT_E)
				{
					*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOCR_BASE+ (0x20000) )  ) = 0x00;
				}
				else
				{
						*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOCR_BASE+ (0x21000) )  ) = 0x00;
				}
	
		}
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
void GPIO_PinInit(GPIO_Interface myInterface)
{
						//enable clock
						int portNum = myInterface.interface.pinInterface.pin /8;
						switch (portNum)
						{
							case 0:
								SysCtrl_EnablePeripheralClock(SysCtrl_GPIO_PORTA_Clock);break;
							case 1:
								SysCtrl_EnablePeripheralClock(SysCtrl_GPIO_PORTB_Clock);break;
							case 2:
								SysCtrl_EnablePeripheralClock(SysCtrl_GPIO_PORTC_Clock);break;
							case 3:
								SysCtrl_EnablePeripheralClock(SysCtrl_GPIO_PORTD_Clock);break;
							case 4:
								SysCtrl_EnablePeripheralClock(SysCtrl_GPIO_PORTE_Clock);break;
							case 5:
								SysCtrl_EnablePeripheralClock(SysCtrl_GPIO_PORTF_Clock);break;
						}
						//wait for mora than 4 clocks 
						for(int i=0;i<5;i++)
						;
						//bus
						GPIO_PortPeripheralBus mybus =myInterface.interface.pinInterface.bus;
						if (mybus== GPIO_APB)
								GPIOHBCTL &= ~(1<<portNum);
						else
								GPIOHBCTL |= (1<<portNum);
						//direction
						if(mybus == GPIO_AHB)
						{
							/***************************************************************/
							/*its Advanced High-performance Bus*/
							/***************************************************************/
							if(myInterface.interface.pinInterface.dir >= GPIO_OUTPUT)		//output
							*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIODIR_BASE+ (portNum* 0x1000) )  ) |= (1<< (myInterface.interface.pinInterface.pin%8) );
							else																												//input
							*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIODIR_BASE+ (portNum* 0x1000) )  ) &= ~(1<<(myInterface.interface.pinInterface.pin%8));
						}
						else
						{
							/***************************************************************/
							/*its Advanced Peripheral Bus*/
							/***************************************************************/
							if(myInterface.interface.pinInterface.dir >= GPIO_OUTPUT)
							{
								/*******************OUTPUT******************/
								if(portNum< GPIO_PORT_E)
								{
										*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIODIR_BASE+ (portNum* 0x1000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
								}
								else if(portNum==GPIO_PORT_E)
								{
									*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIODIR_BASE+ (0x20000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
								}
								else
								{
										*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIODIR_BASE+ (0x21000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
								}
							}
							else
							{
								/*******************INPUT******************/
								if(portNum< GPIO_PORT_E)
								{
										*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIODIR_BASE+ (portNum* 0x1000) )  ) &= ~(1<<(myInterface.interface.pinInterface.pin%8));
								}
								else if(portNum==GPIO_PORT_E)
								{
									*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIODIR_BASE+ (0x20000) )  ) &= ~(1<<(myInterface.interface.pinInterface.pin%8));
								}
								else
								{
										*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIODIR_BASE+ (0x21000) )  ) &= ~(1<<(myInterface.interface.pinInterface.pin%8));
								}
							}
						}
						//alternative funciont
						if(myInterface.interface.pinInterface.function == GPIO_ALTERNATIVE_FUNCTION)
						{
							/*TODO set the Alternative functions*/
						}
						//Open Drain
						if(myInterface.interface.pinInterface.dir == GPIO_OUTPUT_OPEN_DRAIN)
						{
								if(mybus == GPIO_AHB)
										{
												/***************************************************************/
												/*its Advanced High-performance Bus*/
												/***************************************************************/
												*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIOODR_BASE+ (portNum* 0x1000) )  ) |= (1<< (myInterface.interface.pinInterface.pin%8) );
										}
								else
										{
											/***************************************************************/
											/*its Advanced Peripheral Bus*/
											/***************************************************************/
										
														if(portNum< GPIO_PORT_E)
														{
																*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOODR_BASE+ (portNum* 0x1000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
														}
														else if(portNum==GPIO_PORT_E)
														{
															*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOODR_BASE+ (0x20000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
														}
														else
														{
																*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOODR_BASE+ (0x21000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
														}
										}
					}
						//Pullup resistor
						if(myInterface.interface.pinInterface.dir == GPIO_INPUT_PULL_UP )
							{
									if(mybus == GPIO_AHB)
											{
													/***************************************************************/
													/*its Advanced High-performance Bus*/
													/***************************************************************/
													*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIOPUR_BASE+ (portNum* 0x1000) )  ) |= (1<< (myInterface.interface.pinInterface.pin%8) );
											}
									else
											{
												/***************************************************************/
												/*its Advanced Peripheral Bus*/
												/***************************************************************/
											
															if(portNum< GPIO_PORT_E)
															{
																	*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOPUR_BASE+ (portNum* 0x1000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
															}
															else if(portNum==GPIO_PORT_E)
															{
																*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOPUR_BASE+ (0x20000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
															}
															else
															{
																	*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOPUR_BASE+ (0x21000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
															}
											}
							}
							//PUll Down resistor
							if(myInterface.interface.pinInterface.dir == GPIO_INPUT_PULL_UP )
							{
									if(mybus == GPIO_AHB)
											{
													/***************************************************************/
													/*its Advanced High-performance Bus*/
													/***************************************************************/
													*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIOPDR_BASE+ (portNum* 0x1000) )  ) |= (1<< (myInterface.interface.pinInterface.pin%8) );
											}
									else
											{
												/***************************************************************/
												/*its Advanced Peripheral Bus*/
												/***************************************************************/
											
															if(portNum< GPIO_PORT_E)
															{
																	*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOPDR_BASE+ (portNum* 0x1000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
															}
															else if(portNum==GPIO_PORT_E)
															{
																*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOPDR_BASE+ (0x20000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
															}
															else
															{
																	*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIOPDR_BASE+ (0x21000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
															}
											}
						}
						//digital or analog
						/*ToDo add digital alternative function and disable digital if analog*/
						if(myInterface.interface.pinInterface.function== GPIO_NORMAL_FUNCTION)
						{
									if(mybus == GPIO_AHB)
											{
													/***************************************************************/
													/*its Advanced High-performance Bus*/
													/***************************************************************/
													*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+GPIODEN_BASE+ (portNum* 0x1000) )  ) |= (1<< (myInterface.interface.pinInterface.pin%8) );
											}
									else
											{
												/***************************************************************/
												/*its Advanced Peripheral Bus*/
												/***************************************************************/
											
															if(portNum< GPIO_PORT_E)
															{
																	*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIODEN_BASE+ (portNum* 0x1000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
															}
															else if(portNum==GPIO_PORT_E)
															{
																*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIODEN_BASE+ (0x20000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
															}
															else
															{
																	*( (volatile uint32*)( GPIO_PORTA_BASE_APB+GPIODEN_BASE+ (0x21000) )  ) |= (1<<(myInterface.interface.pinInterface.pin%8));
															}
											}
						}
						
						GPIO_PortUnlock(portNum,mybus);
						GPIO_PortCommit(portNum,mybus);
						
					
		
}

void GPIO_PinWrite(GPIO_PinInterface mypin,GPIO_OutputState state)
{
	
	uint32 mask =( (1)<<( mypin.pin%8 +2 ));
	uint32 portNum = mypin.pin /8;
	GPIO_PortPeripheralBus mybus =mypin.bus;
	if(mybus == GPIO_AHB)
											{
													/***************************************************************/
													/*its Advanced High-performance Bus*/
													/***************************************************************/
													*( (volatile uint32*)( GPIO_PORTA_BASE_AHB+(portNum* 0x1000)) + 0xff   ) = (state<< (mypin.pin%8) );
											}
									else
											{
												/***************************************************************/
												/*its Advanced Peripheral Bus*/
												/***************************************************************/
											
															if(portNum< GPIO_PORT_E)
															{
																	//*( (volatile uint32*)(GPIO_PORTA_BASE_APB) + mask )= (state<< (mypin.pin%8) );
																*( (volatile uint32*)(GPIO_PORTA_BASE_APB+portNum*0x1000) + 0xff )= (state<< (mypin.pin%8) );
															}
															else if(portNum==GPIO_PORT_E)
															{
																//*( (volatile uint32*)(GPIO_PORTA_BASE_AHB+0x20000) + mask )=(state<< (mypin.pin%8) );
																	*( (volatile uint32*)(GPIO_PORTA_BASE_AHB+0x20000) + 0xff )=(state<< (mypin.pin%8) );
																
															}
															else
															{
																	*( (volatile uint32*)( GPIO_PORTA_BASE_APB+0x21000) +0xff  )  = (state<< (mypin.pin%8) );
															}
											}
	
	
	
}
uint32 GPIO_PinRead(GPIO_PinType);

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
