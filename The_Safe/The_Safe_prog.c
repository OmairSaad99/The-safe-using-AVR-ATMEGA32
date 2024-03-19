/*
 * The_Safe_prog.c
 *
 *  Created on: Sep 16, 2023
 *      Author: HP
 */



#include "types1.h"
#include "Bit_Math.h"
#include "The_Safe_Interface.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"
#include "TWI_Interface.h"
#include "EXTI_Interface.h"
#include "Global_interface.h"

#include "avr/delay.h"

u32 Password ;
u8 Reset_System_Flag = 0 ;
u8 NumberOfTries = 3 ;
u8 CheckPassLcdLocation = 11 ;

void TheSafe_Reset(void) ;
void TheSafe_vidInit(void)
{
	/*Set Data Port As Output*/
	DIO_vidSetPortDir(DIO_PORTC , 0b11111111);
	/*Set Control Port As Output*/
	DIO_vidSetPinDir(DIO_PORTA , DIO_PIN2 , DIO_OUTPUT);
	DIO_vidSetPinDir(DIO_PORTA , DIO_PIN3 , DIO_OUTPUT);
	DIO_vidSetPinDir(DIO_PORTA , DIO_PIN4 , DIO_OUTPUT);

	/*Make Col As output and Rows as Input*/
	DIO_vidSetPortDir(DIO_PORTB , 0b00001111);

	/*Initial Value for Keypad*/
	DIO_vidSetPortVal(DIO_PORTB , 0b11111111);

	/*Make INT0 PIN as Input*/
	DIO_vidSetPinDir(DIO_PORTD , DIO_PIN2 , DIO_INPUT);

	DIO_vidSetPinVal(DIO_PORTD , DIO_PIN2 ,DIO_HIGH);

	EXTI_INT0SetCallBack(&TheSafe_Reset);

	EXTI_Int0_Inti();

	/*Initialize LCD*/
	CLCD_voidInit();

	Enable_Global_Interrupt();
}
void TheSafe_Set_VidPassword()
{
	u8 key;
	u8 Lcd_Location = 9 ;

	CLCD_vidSendString("Set Pass:");
	while (Lcd_Location <=12)
	{
		do
		{
			if (Reset_System_Flag == 1)
			{
				Lcd_Location = 8 ;
				Reset_System_Flag = 0 ;
				CheckPassLcdLocation = 10 ;
				NumberOfTries = 3 ;
				CLCD_voidSendCommand(1);
				CLCD_vidSendString("Reset System");
				_delay_ms(500);
				CLCD_voidSendCommand(1);
				CLCD_vidSendString("Set Pass:");
				break ;
			}
			else
			{
				key = KPD_GetKeyPressed() ;
			}
		}while (key == 0xff);

		if(key == 0)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}
		else if(key == 1)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}
		else if(key == 2)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}
		else if(key == 3)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}
		else if(key == 4)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}
		else if(key == 5)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}
		else if(key == 6)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}
		else if(key == 7)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}
		else if(key == 8)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}
		else if(key == 9)
		{
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_voidSendData(key + '0');
			_delay_ms(500);
			CLCD_GoToXY(0,Lcd_Location) ;
			CLCD_vidSendString("*");
			if (Lcd_Location == 9)
			{
				Password = key ;
			}
			else
			{
				Password = (Password * 10) + key ;
			}
		}

		Lcd_Location ++ ;
	}

	EEPROM_voidSendDataByte((u8)Password , 0);
	_delay_ms(10);
}

void TheSafe_vidCheck_Password(void)
{
	u32 Check_Password ;
	u8 key ;
	u8 Local_u8ReceivedData ;
	CLCD_voidSendCommand(1);
	CLCD_vidSendString("Enter Pass:");

	while (1)
	{
		while (CheckPassLcdLocation <=14)
		{
			do
			{
				if (Reset_System_Flag == 1)
				{
					Reset_System_Flag = 0 ;
					CheckPassLcdLocation = 10 ;
					NumberOfTries = 3 ;
					CLCD_voidSendCommand(1);
					CLCD_vidSendString("Reset System");
					_delay_ms(500);
					CLCD_voidSendCommand(1);
					CLCD_vidSendString("Enter Pass:");
					break ;
				}
				else
				{
					key = KPD_GetKeyPressed() ;
				}
			}while (key == 0xff);

			if(key == 0)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}
			else if(key == 1)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}
			else if(key == 2)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}
			else if(key == 3)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}
			else if(key == 4)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}
			else if(key == 5)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}
			else if(key == 6)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}
			else if(key == 7)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}
			else if(key == 8)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}
			else if(key == 9)
			{
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_voidSendData(key + '0');
				_delay_ms(500);
				CLCD_GoToXY(0,CheckPassLcdLocation) ;
				CLCD_vidSendString("*");
				if (CheckPassLcdLocation == 11)
				{
					Check_Password = key ;
				}
				else
				{
					Check_Password = (Check_Password * 10) + key ;
				}
			}

			CheckPassLcdLocation ++ ;
		}
		/*Read Password From EEPROM*/
		EEPROM_voidReadDataByte((u8)&Local_u8ReceivedData , 0);

		if (Check_Password == Local_u8ReceivedData)
		{
			CLCD_voidSendCommand(1);
			CLCD_vidSendString("Right Password");
			CLCD_GoToXY(1,0);
			CLCD_vidSendString("Safe Opened");
			break ;
		}
		else
		{
			if (NumberOfTries == 1)
			{
				u8 local_u8Seconds = 2 ;
				CLCD_voidSendCommand(1);
				CLCD_vidSendString("Remaining") ;
				CLCD_GoToXY(0 , 13);
				CLCD_vidSendString("Sec");
				while (1)
				{
					CLCD_GoToXY(0 , 10);
					CLCD_write_Number(local_u8Seconds);
					_delay_ms(1000);
					local_u8Seconds -- ;
					if (local_u8Seconds == 0)
					{
						NumberOfTries = 3 ;
						CheckPassLcdLocation = 11 ;
						CLCD_voidSendCommand(1);
						CLCD_vidSendString("Enter Pass:");
						break ;
					}
				}
			}
			else
			{
				NumberOfTries -- ; //2 1
				CheckPassLcdLocation = 11 ;
				CLCD_voidSendCommand(1);
				CLCD_vidSendString("Wrong Password") ;
				CLCD_GoToXY(1,0);
				CLCD_vidSendString("Tries Left:");
				CLCD_GoToXY(1,11);
				CLCD_write_Number(NumberOfTries);
				_delay_ms(500);
				CLCD_voidSendCommand(1);
				CLCD_vidSendString("Enter Pass:");
			}
		}
	}
}

void TheSafe_Reset(void)
{
	Reset_System_Flag = 1 ;
}
