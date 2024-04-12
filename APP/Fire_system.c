#include "stand Types.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "Motor_Interface.h"
#include "ADC.h"
#include "Sensors.h"
#include "Fire_system.h"

#define F_CPU  8000000
#include <util/delay.h>

u16 temp=0, press=0, key=0, password=12345, num=0, flag=0;

void system_case_fine(void)
{
	while(1)
	{
		DIO_Write_pin(Red_led,LOW);
		DIO_Write_pin(Yellow_led,LOW);
		DIO_Write_pin(M1,LOW);
		LCD_Set_Cursor(0,7);
		LCD_Write_String("FINE");
		LCD_Set_Cursor(1,0);
		LCD_Write_String("Temp=");
		temp=Read_temp();
		LCD_Write_Number(temp);
		LCD_Write_char('C');
		if(temp>FINE || press>FIRE)
		{
			break;
		}
	}	
}
	 
void system_case_heat(void)
{
	while(1)
	{
		DIO_Write_pin(Red_led,HIGH);
		DIO_Write_pin(Yellow_led,LOW);
		DIO_Write_pin(M1,LOW);
		LCD_Set_Cursor(0,7);
		LCD_Write_String("HEAT");
		LCD_Set_Cursor(1,0);
		LCD_Write_String("Temp=");
		temp=Read_temp();
		LCD_Write_Number(temp);
		LCD_Write_char('C');
		LCD_Set_Cursor(1,10);
		LCD_Write_String("Smoke=");
		press=Read_pressure();
		LCD_Write_Number(press);
		LCD_Write_char('%');
		if(press>FIRE)
		break;
	}
	
}

void system_case_fire(void)	 
{
	DIO_Write_pin(Red_led,HIGH);
	DIO_Write_pin(Yellow_led,HIGH);
	DIO_Write_pin(M1,HIGH);
	LCD_Set_Cursor(0,7);
	LCD_Write_String("FIRE");
	LCD_Set_Cursor(1,0);
	LCD_Write_String("Temp=");
	temp=Read_temp();
	LCD_Write_Number(temp);
	LCD_Write_char('C');
	LCD_Set_Cursor(1,10);
	LCD_Write_String("Smoke=");
	press=Read_pressure();
	LCD_Write_Number(press);
	LCD_Write_char('%');
	
}