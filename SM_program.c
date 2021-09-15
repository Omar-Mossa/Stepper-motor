/***************************************************************************************/
/*********	Name	:	Omar Mossa	        ********************************************/
/*********  Date	:	20/9/2020	        ********************************************/
/*********	SWC		:	STEPPER MOTOR		********************************************/
/*********	Version	:	V1.0		        ********************************************/
/***************************************************************************************/

#define F_CPU	8000000UL

#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SM_interface.h"
#include "SM_private.h"
#include "SM_config.h"


u8 SM_u8TurnAngleAntiCW( u16 Copy_u16Angle , u8 Copy_u8MotorSpeed )
{
	u8 Local_u8ErrorStatus = OK ;

	if( Copy_u8MotorSpeed <= MAX_SPEED && Copy_u16Angle <= 360 )
	{
		u16 Local_u16NumOfSteps = (Copy_u16Angle * 512UL ) / 360 ;

		for (u16 Local_u16StepNum = 0; Local_u16StepNum < Local_u16NumOfSteps ; Local_u16StepNum++ )
		{
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );
	
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );
	
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );
	
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_LOW  );
			_delay_ms( Copy_u8MotorSpeed );
		}

	}
	else 
	{
		Local_u8ErrorStatus = NOK ;
	}
	return Local_u8ErrorStatus ;
}


u8 SM_u8TurnAngleCW( u16 Copy_u16Angle , u8 Copy_u8MotorSpeed )
{
	u8 Local_u8ErrorStatus = OK ;

	if( Copy_u8MotorSpeed <= MAX_SPEED && Copy_u16Angle <= 360 )
	{
		u16 Local_u16NumOfSteps = (Copy_u16Angle * 512UL ) / 360 ;

		for (u16 Local_u16StepNum = 0; Local_u16StepNum < Local_u16NumOfSteps ; Local_u16StepNum++ )
		{
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_LOW  );
			_delay_ms( Copy_u8MotorSpeed );

			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );

			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );


			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );
		}
	}
	else 
	{
		Local_u8ErrorStatus = NOK ;
	}
	return Local_u8ErrorStatus ;	
}


u8 SM_u8TurnRevAntiCW( u16 Copy_u16RevNum , u8 Copy_u8MotorSpeed )
{
	u8 Local_u8ErrorStatus = OK ;

	if( Copy_u8MotorSpeed <= MAX_SPEED )
	{
		u16 Local_u16NumOfSteps = Copy_u16RevNum * 512UL  ;

		for (u16 Local_u16StepNum = 0; Local_u16StepNum < Local_u16NumOfSteps ; Local_u16StepNum++ )
		{
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );
	
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );
	
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );
	
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_LOW  );
			_delay_ms( Copy_u8MotorSpeed );
		}
	}
	else 
	{
		Local_u8ErrorStatus = NOK ;
	}
	return Local_u8ErrorStatus ;
}

u8 SM_u8TurnRevCW( u16 Copy_u16RevNum , u8 Copy_u8MotorSpeed )
{
	u8 Local_u8ErrorStatus = OK ;

	if( Copy_u8MotorSpeed <= MAX_SPEED )
	{
		u16 Local_u16NumOfSteps = Copy_u16RevNum * 512UL  ;

		for (u16 Local_u16StepNum = 0; Local_u16StepNum < Local_u16NumOfSteps ; Local_u16StepNum++ )
		{
			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_LOW  );
			_delay_ms( Copy_u8MotorSpeed );

			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );

			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );


			DIO_u8SetPinValue( SM_BLUE_PORT   , SM_BLUE_PIN   , OUTPUT_LOW  );
			DIO_u8SetPinValue( SM_PINK_PORT   , SM_PINK_PIN   , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_YELLOW_PORT , SM_YELLOW_PIN , OUTPUT_HIGH );
			DIO_u8SetPinValue( SM_ORANGE_PORT , SM_ORANGE_PIN , OUTPUT_HIGH );
			_delay_ms( Copy_u8MotorSpeed );
		}
		
	}
	else 
	{
		Local_u8ErrorStatus = NOK ;
	}
	return Local_u8ErrorStatus ;	
}

	
