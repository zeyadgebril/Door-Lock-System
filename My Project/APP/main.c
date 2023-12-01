/*
 * My Project.c
 *
 * Created: 10/13/2023 6:32:29 AM
 * Author : Zeyad
 */ 
#include "main.h"



 int main(void)
 {
	 LED_config_t IN1;
	 IN1.PORT=DIO_u8_PORTD;
	 IN1.Pin_num=DIO_u8_PIN0;
	 IN1.ConnType=SRS_conn;
	 	 LED_u8Init(&IN1);


	 LED_config_t IN2;
	 IN2.PORT=DIO_u8_PORTD;
	 IN2.Pin_num=DIO_u8_PIN1;
	 IN2.ConnType=SRS_conn;
	 
	 LED_u8Init(&IN2);
	 
	
	 	 

	 
		 uint8_t Local_u8UnLockCharacter[] = {                      //unLock  Character
			 0b00000000,
			 0b00001110,
			 0b00010000,
			 0b00010000,
			 0b00011111,
			 0b00011111,
			 0b00011111,
			 0b00000000,
		 };
		 uint8_t Local_u8LockCharacter[] = {                      //Lock  Character
			 0b00000000,
			 0b00001110,
			 0b00010001,
			 0b00010001,
			 0b00011111,
			 0b00011111,
			 0b00011111,
			 0b00000000,
		 };
	 

  	 uint8_t local_u8PressedKey = 0xff;	//Initilize the Pull up res in the MC for the keypad
	 uint8_t local_u8Counter = 5; //the place of the password
	 uint8_t local_u8Password = 2489; //the place of the password
	 uint8_t local_u8CheckPswd = 0; //to check for the Password
	 uint8_t local_u8flagPswd = 0; //if the password is ok is =1;
	 uint8_t local_u8SystemLock = 0; //if the password is ok is =1;


	 

  	 KPD_voidInit();
  	 LCD_INIT();
	   
	 LCD_SetCursor(0,0);
	 LCD_SEND_STRING(" Enter PASSWORD");
	 LCD_SetCursor(0,1);
	 LCD_SEND_STRING("Key:");

 
 while(1)
 {
	 if(local_u8SystemLock!=3)
	 {
	 LCD_SetCursor(0,0);
	 LCD_SEND_STRING(" Enter PASSWORD");
	 LCD_SetCursor(0,1);
	 LCD_SEND_STRING("Key:");
 		
	do 
  	{
  	 local_u8PressedKey = KPD_u8GetPressedKey();
  	} while (local_u8PressedKey == 0xff);
	  
	  
  /*  to print * insted of the number & to get the right password*/
  if(local_u8PressedKey<10)
  {
	  LCD_SetCursor(local_u8Counter,1);
	  LCD_SEND_DATA('*');
	  local_u8Counter++;
	  local_u8CheckPswd=(local_u8CheckPswd*10)+local_u8PressedKey;
  }
  
  
  /* if the password is OK*/
  if(local_u8PressedKey =='=')
  {
	if(local_u8CheckPswd==local_u8Password)
	{
	  LCD_CLear();
	  LCD_SEND_STRING("   DOOR OPEN ");
	  LCD_SpecialChar(Local_u8UnLockCharacter,2,7,1);
	  LED_u8TurnOn(&IN1);
	  LED_u8TurnOff(&IN2);
	  _delay_ms(50000);
	  LCD_CLear();
	  LCD_SEND_STRING("   DOOR ClOSE ");
	  LCD_SpecialChar(Local_u8LockCharacter,3,7,1);
	  LED_u8TurnOn(&IN2);
	  LED_u8TurnOff(&IN1);
	  _delay_ms(50000);
	  LED_u8TurnOff(&IN2);
	   LED_u8TurnOff(&IN1);
	  LCD_CLear();
	  local_u8Counter = 5;
	  local_u8CheckPswd=0;
	  local_u8SystemLock=0;
	  		}
	else if(local_u8CheckPswd!=local_u8Password)
	{
		LCD_CLear();
		LCD_SEND_STRING("	Wrong Password");
		LCD_SpecialChar(Local_u8LockCharacter,3,7,1);
		_delay_ms(50000);
		LCD_CLear();
	    local_u8Counter = 5;
 	    local_u8CheckPswd=0;
		local_u8SystemLock++;

	
		}
  }
  
  /* Set new password*/
  
 
  
  /*  to clear the password on the LCD */
  if(local_u8PressedKey=='c')
  {
	LCD_CLear();
 LCD_SetCursor(0,0);
 LCD_SEND_STRING(" Enter PASSWORD");
 LCD_SetCursor(0,1);
 LCD_SEND_STRING("Key:");
 local_u8Counter = 5;
 local_u8CheckPswd=0;
  }
  
  /* show the number on LCD */
  
  /*	if(local_u8PressedKey>9 && local_u8PressedKey!='c' && local_u8PressedKey!= '=')
	  {
		 LCD_SEND_DATA(local_u8PressedKey);
	  }
  */
	  }else if(local_u8SystemLock>=3)
	  {
		  LCD_SEND_STRING(" DOOR LOCKED FOR ");
		  LCD_SetCursor(3,1);
		  LCD_SEND_STRING("10MIN");
		  LCD_SpecialChar(Local_u8LockCharacter,3,9,1);
		  
		  _delay_ms(5000000);
		 local_u8SystemLock=0;
		 LCD_CLear();
	  }
 }

}
 

