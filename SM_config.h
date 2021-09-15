/***************************************************************************************/
/*********	Name	:	Omar Mossa	        ********************************************/
/*********  Date	:	20/9/2020	        ********************************************/
/*********	SWC		:	STEPPER MOTOR		********************************************/
/*********	Version	:	V1.0		        ********************************************/
/***************************************************************************************/


#ifndef	SM_CONFIG
#define SM_CONFIG

/********
OPTIONS :
FOR PORTS :
1- DIO_PORTA
2- DIO_PORTB
3- DIO_PORTC
4- DIO_PORTD

FOR PINS :

1- PIN0
2- PIN1
3- PIN2
4- PIN3
5- PIN4
6- PIN5
7- PIN6
8- PIN7
**********/
/*******************************************************************************************************************/
/**** The Control Pins Is Connected In Order To ULN 2003 IC Inputs(Active LOW) And Initialized To OUTPUT_HIGH ******/
/*******************************************************************************************************************/



#define SM_BLUE_PORT			DIO_PORTA_ID	
#define SM_BLUE_PIN				PIN0

#define SM_PINK_PORT			DIO_PORTA_ID
#define SM_PINK_PIN				PIN1

#define SM_YELLOW_PORT			DIO_PORTA_ID
#define SM_YELLOW_PIN			PIN2	
	
#define SM_ORANGE_PORT			DIO_PORTA_ID
#define SM_ORANGE_PIN			PIN3	



#endif