
#include <IntCtrl.h>
#include <SysCtrl.h>
#define RCGCGPIO                                  *((volatile uint32*)(0x400FE000+0x608))
#define GPIO                                  ((volatile uint32*)(0x40007000))
	#define GPIODIR                                  *((volatile uint32*)(0x40007000+0x400))
int main ()
{
	SysCtrl_EnablePeripheralClock(SysCtrl_GPIO_PORTA_Clock );
	SysCtrl_EnablePeripheralClock(SysCtrl_GPIO_PORTF_Clock );
	SysCtrl_Init();
	//RCGCGPIO|=(1<<3);
	GPIODIR|=0xff;
	*(GPIO+0xff)|=0x5ff;
	
	
	//while(1)
	//{
	//	__asm__("add r8,1");
	//}
	IntCrtl_Init();
	return 2;
}

