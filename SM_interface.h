/***************************************************************************************/
/*********	Name	:	Omar Mossa	        ********************************************/
/*********  Date	:	20/9/2020	        ********************************************/
/*********	SWC		:	STEPPER MOTOR		********************************************/
/*********	Version	:	V1.0		        ********************************************/
/***************************************************************************************/

#ifndef	SM_INTERFACE
#define SM_INTERFACE

/***** Options For Motor Speed ******/
#define MAX_SPEED 	10
#define SPEAD_90 	11
#define SPEAD_80 	13
#define SPEAD_70 	14
#define SPEAD_60 	16
#define SPEAD_50 	20
#define SPEAD_40 	25
#define SPEAD_30 	33
#define SPEED_20 	50
#define SPEED_10 	100
/***********************************/



u8 SM_u8TurnAngleCW( u16 Copy_u16Angle , u8 Copy_u8MotorSpeed );

u8 SM_u8TurnAngleAntiCW( u16 Copy_u16Angle , u8 Copy_u8MotorSpeed );

u8 SM_u8TurnRevCW( u16 Copy_u16RevNum , u8 Copy_u8MotorSpeed );

u8 SM_u8TurnRevAntiCW( u16 Copy_u16RevNum , u8 Copy_u8MotorSpeed );


#endif