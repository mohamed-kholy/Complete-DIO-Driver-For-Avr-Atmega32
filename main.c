/*
 * DIO.c
 *
 * Created: 9/2/2021 7:08:28 PM
 * Author : Mohamed El-Kholy
 */ 

/* Include The Libraries */ 

#include "Lib/STD_TYPES.h"
#include "Lib/BIT_MATH.h"
#include "MCAl/DIO/MDIO_interface.h"
#include "EUCAL/BUTTON/BUTTON_interface.h"
#include "EUCAL/LED/LED_interface.h"
#include "APP/APP.h"

#include <util/delay.h>


int main(void)
{
	/* Call App Initialization Function that make
		* PINA0 as Output Pin and Low 
		* PINC0 as Input Pin and PULL UP 
	*/ 
	 APP_Init();
	 /* Local Variable Holds the Return Value of the Pressed Button */
	 s8 s8_localvar = 0 ;

    while (1) 
    {
		/* get The Return Value */	
		s8_localvar = EUButtonPressed(GPIOC,PIN0 , PULL_UP);
		/* In Case of Error */
		if (s8_localvar == -1 )
		{
			return -1 ;
		}
		/* In Case of the Button is Pressed */
		else if (s8_localvar == 1 )
		{
			/* Wait 300ms */
			_delay_ms(300);
			/* Then Toggle the Pin */ 
			EULED_voidLedToggle(GPIOA,PIN0);
			
		}
    }
}

