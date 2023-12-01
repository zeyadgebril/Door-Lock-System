/*
 * main.h
 *
 * Created: 10/20/2023 3:40:30 AM
 *  Author: Zeyad
 */ 


#include "Configurations.h"

//#include "SWITCH_interface.h"
#include "LED_interface.h"
#include "SEVENT_Segment_interface.h"
#include "CLCD_Privite.h"
#include "STEPPER_interface.h"





/* SEVEN SEGMENT DISPLAY counter*/
/*int main(void)
{
uint8_t counter;
SEVEN_Segment_config_t SSD;
SSD.PORT_Pin=DIO_u8_PORTA;
SSD.PORT_Enable=DIO_u8_PORTB;
SSD.EN1=DIO_u8_PIN2;
SSD.EN2=DIO_u8_PIN1;
SSD.PinA=DIO_u8_PIN4;
SSD.PinB=DIO_u8_PIN5;
SSD.PinC=DIO_u8_PIN6;
SSD.PinD=DIO_u8_PIN7;
SEVEN_Segment_Display_u8TurnOn(&SSD);
while (1)
{
for (counter=0;counter<=99;counter++)
{
SEVEN_Segment_Display_u8SetNumber(&SSD,counter);
_delay_ms(1200);
}
}
}*/



/* 8bit lcd display */
/*
int main(void)
{
	
	DIO_u8SetPortDirection(DIO_u8_PORTA,0xff);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_PIN_OUTPUT);
	
	LCD_voidInit();
	
	LCD_voidSendData('a');
	LCD_voidSendData('z');
	LCD_voidSendData('e');
	LCD_voidSendData('y');
	LCD_voidSendData('a');
	LCD_voidSendData('d');
	
	while (1)
	{
		
	}
}
*/



	
// ASSIGMENT - 1	
// 	/* Initilize the leds*/
// 	LED_config_t LED_RED,LED_YELLOW,LED_GREEN;
// 	 /***********RED********/
// 	LED_RED.PORT=DIO_u8_PORTC;
// 	LED_RED.Pin_num=DIO_u8_PIN2;
// 	LED_RED.ConnType=SRS_conn;
// 	
// 	
// 	/***********YELLOW********/
// 	LED_YELLOW.PORT=DIO_u8_PORTC;
// 	LED_YELLOW.Pin_num=DIO_u8_PIN7;
// 	LED_YELLOW.ConnType=SRS_conn;
// 	
// 	/***********GREEN********/
// 	LED_GREEN.PORT=DIO_u8_PORTD;
// 	LED_GREEN.Pin_num=DIO_u8_PIN3;
// 	LED_GREEN.ConnType=SRS_conn;
// 	
// 	/***********initilization of ssd*********/
// 	SEVEN_Segment_config_t SSD;
// 	SSD.PORT_Pin=DIO_u8_PORTA;
// 	SSD.PORT_Enable=DIO_u8_PORTB;
// 	SSD.EN1=DIO_u8_PIN2;
// 	SSD.EN2=DIO_u8_PIN1;
// 	SSD.PinA=DIO_u8_PIN4;
// 	SSD.PinB=DIO_u8_PIN5;
// 	SSD.PinC=DIO_u8_PIN6;
// 	SSD.PinD=DIO_u8_PIN7;
// 	SEVEN_Segment_Display_u8TurnOn(&SSD);
// 	
// 	uint8_t Local_u8TrafficLightCounter=0; 
// 	while(1)
// 	{
// 		
// 	SNAKE AFFECT LEFT
// 		LED_u8TurnOn(&LED_RED);
// 	 	_delay_ms(5000);
// 		LED_u8TurnOff(&LED_GREEN);
// 	 	LED_u8TurnOff(&LED_RED);
// 	 	/*****SECOND LED*****/
// 	 	LED_u8TurnOn(&LED_YELLOW);
// 	 	_delay_ms(10000);
// 	 	LED_u8TurnOff(&LED_YELLOW);
// 	 	/*****THIRUD LED*****/
// 	 	LED_u8TurnOn(&LED_GREEN);
// 	 	_delay_ms(10000);	 
// 		
// 		
// 		
// 		
// 	SHIFT LEFT 
// 		/*****FIRST LED*****/
// 		LED_u8TurnOn(&LED_RED);
// 		_delay_ms(10000);
// 		LED_u8TurnOff(&LED_RED);
// 		/*****SECOND LED*****/
// 		LED_u8TurnOn(&LED_YELLOW);
// 		_delay_ms(10000);
// 		LED_u8TurnOff(&LED_YELLOW);
// 		/*****THIRUD LED*****/
// 		LED_u8TurnOn(&LED_GREEN);
// 		_delay_ms(10000);
// 		LED_u8TurnOff(&LED_GREEN);
// 		
// 		// SHIFT RIGHT
// 		/*****FIRST LED*****/
// 		LED_u8TurnOn(&LED_GREEN);
// 		_delay_ms(10000);
// 		LED_u8TurnOff(&LED_GREEN);
// 		/*****SECOND LED*****/
// 		LED_u8TurnOn(&LED_YELLOW);
// 		_delay_ms(10000);
// 		LED_u8TurnOff(&LED_YELLOW);
// 		/*****THIRUD LED*****/
// 		LED_u8TurnOn(&LED_RED);
// 		_delay_ms(10000);
// 		LED_u8TurnOff(&LED_RED);
// 		
	
	/******************TRAFFIC LIGHT***********	
	/*************LED_RED*********	
	LED_u8TurnOn(&LED_RED);
	for (Local_u8TrafficLightCounter = 0 ; Local_u8TrafficLightCounter<25 ;Local_u8TrafficLightCounter++)
	{
		SEVEN_Segment_Display_u8SetNumber(&SSD,Local_u8TrafficLightCounter);
		_delay_ms(500);
	}
	_delay_ms(1000);
	LED_u8TurnOff(&LED_RED);
	
	/***********LED_YELLOW***********	
	LED_u8TurnOn(&LED_YELLOW);
	for (Local_u8TrafficLightCounter = 0 ; Local_u8TrafficLightCounter<10 ;Local_u8TrafficLightCounter++)
	{
		SEVEN_Segment_Display_u8SetNumber(&SSD,Local_u8TrafficLightCounter);
		_delay_ms(500);
	}
	_delay_ms(1000);
	LED_u8TurnOff(&LED_YELLOW);
	
	/************LED_GREEN************
		LED_u8TurnOn(&LED_GREEN);
	for (Local_u8TrafficLightCounter = 0 ; Local_u8TrafficLightCounter<25 ;Local_u8TrafficLightCounter++)
	{
		SEVEN_Segment_Display_u8SetNumber(&SSD,Local_u8TrafficLightCounter);
		_delay_ms(500);
	}
	_delay_ms(1000);
	LED_u8TurnOff(&LED_GREEN);
	
	/***********LED_YELLOW***********	
	LED_u8TurnOn(&LED_YELLOW);
	for (Local_u8TrafficLightCounter = 0 ; Local_u8TrafficLightCounter<10 ;Local_u8TrafficLightCounter++)
	{
		SEVEN_Segment_Display_u8SetNumber(&SSD,Local_u8TrafficLightCounter);
		_delay_ms(500);
	}
	_delay_ms(1000);
	LED_u8TurnOff(&LED_YELLOW);
	*/
	
	
	
	
	
	
	
	/***********************************HHHHHHHHAAAAMOOOKSHAAAAAAAA********************/
	//
	// 	uint8_t Local_u8HamoksaCharacter[] = {                      //hamoksha character
	// 		0b00001100,
	// 		0b00001100,
	// 		0b00000000,
	// 		0b00011110,
	// 		0b00001100,
	// 		0b00001100,
	// 		0b00010010,
	// 		0b00000000,
	// 	};
	// uint8_t Local_u8FirstLetterArray[] = {    //run_pos_1
	// 	0b00001100,
	// 	0b00001100,
	// 	0b00000000,
	// 	0b00001110,
	// 	0b00011100,
	// 	0b00001100,
	// 	0b00011010,
	// 	0b00010011,
	// };
	// uint8_t Local_u8SecondLetterArray[] = {		// run_pos_2
	// 	0b00001100,
	// 	0b00001100,
	// 	0b00000000,
	// 	0b00001100,
	// 	0b00001100,
	// 	0b00001100,
	// 	0b00001100,
	// 	0b00001110,
	// };
	// uint8_t Local_u8ThiredLetterArray[] = {   // football_pos_1
	// 	0b00001100,
	// 	0b00001100,
	// 	0b00000000,
	// 	0b00001000,
	// 	0b00001011,
	// 	0b00001111,
	// 	0b00011010,
	// 	0b00010011,
	// };
	//
	// uint8_t Local_u8FourthLetterArray[] = {		// football_pos_2
	// 	0b00001100,
	// 	0b00001100,
	// 	0b00000011,
	// 	0b00001011,
	// 	0b00001000,
	// 	0b00001100,
	// 	0b00011010,
	// 	0b00010011,
	// };
	//
	//  uint8_t Local_u8FifthLetterArray[] = {		// dance_pos_1
	// 	 0b00001100,
	// 	 0b00001100,
	// 	 0b00000010,
	// 	 0b00001100,
	// 	 0b00011100,
	// 	 0b00001110,
	// 	 0b00010000,
	// 	 0b00000000,
	//  };
	//    uint8_t Local_u8SixethLetterArray[] = {		// dance_pos_2
	// 	   0b00001100,
	// 	   0b00001100,
	// 	   0b00010000,
	// 	   0b00001110,
	// 	   0b00001100,
	// 	   0b00011100,
	// 	   0b00000010,
	// 	   0b00000000,
	//    };
	//
	//      uint8_t Local_u8SeventhLetterArray[] = {		// gun
	// 	     0b00000000,
	// 	     0b00000000,
	// 	     0b00011111,
	// 	     0b00011111,
	// 	     0b00010000,
	// 	     0b00010000,
	// 	     0b00000000,
	// 	     0b00000000,
	//      };
	// 	 uint8_t Local_u8EighthLetterArray[] = {		// gun_bulat
	// 		 0b00000000,
	// 		 0b00011100,
	// 		 0b00011110,
	// 		 0b00011111,
	// 		 0b00011110,
	// 		 0b00011100,
	// 		 0b00000000,
	// 		 0b00000000,
	// 	 };
	//
	// 	  uint8_t Local_u8SadFace[] = {		// sad face
	// 		  0b00001110,
	// 		  0b00010001,
	// 		  0b00011011,
	// 		  0b00010001,
	// 		  0b00010101,
	// 		  0b00011011,
	// 		  0b00001110,
	// 		  0b00000000,
	// 	  };
	//
	//
	// LCD_INIT();
	//
	// 	// 	LCD_SpecialChar(Local_u8FirstLetterArray,0,4,0);
	// 	// 	LCD_SpecialChar(Local_u8SecondLetterArray,1,3,0);
	// 	// 	LCD_SpecialChar(Local_u8ThiredLetterArray,2,2,0);
	// 	// 	LCD_SpecialChar(Local_u8FourthLetterArray,3,1,0);
	//
	// /*for(int i=0; i<16 ; i++)   //running
	// {
	// 	LCD_SpecialChar(Local_u8FirstLetterArray,0,i,0);
	// 	_delay_ms(500);
	// 	LCD_CLear();
	// 	LCD_SpecialChar(Local_u8SecondLetterArray,0,i,0);
	// 	_delay_ms(100);
	// 	LCD_CLear();
	// }*/
	//
	// /*
	// for(int i=0; i<3 ; i++)   // play football
	// {
	// 	LCD_SpecialChar(Local_u8ThiredLetterArray,0,10,0);
	// 	_delay_ms(500);
	// 	LCD_CLear();
	// 	LCD_SpecialChar(Local_u8FourthLetterArray,0,10,0);
	// 	_delay_ms(100);
	// 	LCD_CLear();
	// }
	//
	//
	// for(int i=0; i<3 ; i++)   // dance
	// {
	// 	LCD_SpecialChar(Local_u8FifthLetterArray,0,10,0);
	// 	_delay_ms(500);
	// 	LCD_CLear();
	// 	LCD_SpecialChar(Local_u8SixethLetterArray,0,10,0);
	// 	_delay_ms(100);
	// 	LCD_CLear();
	// }
	// */
	// /*
	// for(int i=3; i<16 ; i++)   //gun
	// {	LCD_SpecialChar(Local_u8SeventhLetterArray,0,0,0);
	// 	LCD_SpecialChar(Local_u8EighthLetterArray,1,i,0);
	// 	_delay_ms(500);
	// 	LCD_CLear();
	// }
	// */
	//
	// //LCD_SpecialChar(Local_u8SadFace,2,4,0);
	//
	//
	// /*
	//
	// LCD_SpecialChar(Local_u8HamoksaCharacter,0,0,0);    // definition
	// _delay_ms(100);
	// LCD_SEND_STRING("Hi I'm Hamoksha");
	// _delay_ms(30000);
	// LCD_CLear();
	//
	// LCD_SpecialChar(Local_u8HamoksaCharacter,1,0,0);
	// _delay_ms(100);
	// LCD_SEND_STRING(" I can run");
	// _delay_ms(30000);
	// LCD_CLear();
	//
	//
	// for(int i=0; i<15 ; i++)   //running
	// {
	// _delay_ms(100);
	// LCD_SpecialChar(Local_u8FirstLetterArray,2,i,0);
	// _delay_ms(500);
	// LCD_CLear();
	// LCD_SpecialChar(Local_u8SecondLetterArray,3,i,0);
	// _delay_ms(100);
	// LCD_CLear();
	// }
	//
	// */
	// LCD_SpecialChar(Local_u8HamoksaCharacter,0,15,0);    // football
	// LCD_SetCursor(0,1);
	// LCD_SEND_STRING("I can play football");
	// _delay_ms(30000);
	//
	//
	//
	//
	//
	//
	//
/***************************************************************************************************/