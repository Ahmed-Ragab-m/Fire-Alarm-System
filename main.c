#include "stand Types.h"
#include "Memory_Map.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "Motor_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "ADC.h"
#include "Sensors.h"
#include "WDT.h"
#include "NVM.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "Fire_system.h"
#include "RGB.h"
#include "Ultrasonic.h"
#include "UART.h"
#include "UART_Services.h"
#include "SPI.h"
#include "OS.h"
#include "Task.h"


//#include <avr/io.h>

#define F_CPU  8000000
#include <util/delay.h>



	
int main(void)
{
    DIO_Init();
	LCD_Init();
	ADC_Init(ADC_VCC,ADC_SCALER_64);

    while (1)
    {
		system_case_fine();
	   
	   if((temp > FINE) && (pres < FIRE))
	   {
		   system_case_heat();
	   }
	   if(pres > FIRE)
	   {
		  system_case_fire();
	   }
		
	}
}



