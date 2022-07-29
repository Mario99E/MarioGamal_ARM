
#include <IntCtrl.h>
#include <SysCtrl.h>
#include <GPIO_header.h>
#define 	GPIO_PORTC_BASE_APB				((volatile uint32*)(0x40006000))
#define 	GPIO_PORTA_BASE_APB				((volatile uint32*)(0x40004000))

		

int main ()
{
	int x =0xf<<3;

	GPIO_Interface led;
	led.interfaceType = GPIO_PIN_INTERFACE;
	led.interface.pinInterface.pin = GPIO_PIN_A3;
	led.interface.pinInterface.dir = GPIO_OUTPUT_OPEN_DRAIN;
	led.interface.pinInterface.function = GPIO_NORMAL_FUNCTION;
	led.interface.pinInterface.bus = GPIO_AHB;
	GPIO_PinInit(led);
	GPIO_PinWrite(led.interface.pinInterface,GPIO_HIGH);
	GPIO_PinWrite(led.interface.pinInterface,GPIO_LOW);
	///	*(GPIO_PORTA_BASE_APB+0x0f) ) =0xff;
	
	
	//while(1)
	//{
	//	__asm__("add r8,1");
	//}
	IntCrtl_Init();
	return 2;
}

