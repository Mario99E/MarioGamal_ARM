
#include <IntCtrl.h>
#include <SysCtrl.h>
#include <GPIO_header.h>
#include <Timer_header.h>

#define TIMER_FREQ  16000       //kHz
#define ON_Time   5000				//ms
#define OFF_Time  5000				//ms

#define ms_per_timerOUT   (0xffffffff/TIMER_FREQ)

GPIO_Interface led;

void callbackfunck(void);

int main ()
{
	IntCrtl_Init();
	//Timer Config
	Timer_TimerConfig mytimer;
	mytimer.timerNum= TIMER_TIMER_0;
	mytimer.cha=TIMER_CHANNEL_A;
	mytimer.dir=TIMER_COUNT_DOWN;
	mytimer.mode=TIMER_PERIODIC_MODE;
	mytimer.interrupt=TIMER_TIME_OUT_INTERRUPT_ENABLE;
	mytimer.startValue=0xFff400;
	Timer_Init(mytimer);
	//Callback function
	Timer_Timer0ASetCallBack(callbackfunck);
	
	//LED Config
	led.interfaceType = GPIO_PIN_INTERFACE;
	led.interface.pinInterface.pin = GPIO_PIN_A3;
	led.interface.pinInterface.dir = GPIO_OUTPUT_OPEN_DRAIN;
	led.interface.pinInterface.function = GPIO_NORMAL_FUNCTION;
	led.interface.pinInterface.bus = GPIO_AHB;
	GPIO_PinInit(led);
	//initial value low
	GPIO_PinWrite(led.interface.pinInterface,GPIO_LOW);
	//initiate Interrupt contorl
	
	
	while(1)
	return 2;
}
void callbackfunck(void)
{
	static GPIO_OutputState state=GPIO_LOW;
	static uint32 msCountre=0;
	if(state == GPIO_LOW)
	{
		msCountre++;
		if(msCountre== OFF_Time)
		{
			msCountre=0;
			GPIO_PinWrite(led.interface.pinInterface,GPIO_HIGH);
			state=GPIO_HIGH;
		}
	}
	else
	{
		msCountre++;
		if(msCountre== ON_Time)
		{
			msCountre=0;
			GPIO_PinWrite(led.interface.pinInterface,GPIO_LOW);
			state=GPIO_LOW;
		}
	}
	
}
