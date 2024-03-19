/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: HP
 */


#include "Bit_Math.h"
#include "types1.h"
#include "The_Safe_Interface.h"

void main(void)
{
	u8 local_u8SetPasswordFlag = 0 ;
	u8 local_ReceivedData ;

	TheSafe_vidInit();
	EEPROM_voidReadDataByte((u8)&local_ReceivedData , 1);

	if (local_ReceivedData != 1)
	{
		TheSafe_Set_VidPassword();
		local_u8SetPasswordFlag ++ ; // 1
		EEPROM_voidSendDataByte((u8)local_u8SetPasswordFlag , 1);
		_delay_ms(10);
	}

	TheSafe_vidCheck_Password();
}
