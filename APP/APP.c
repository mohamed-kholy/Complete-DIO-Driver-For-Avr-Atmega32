

#include "../Lib/STD_TYPES.h"
#include "../MCAl/DIO/MDIO_interface.h"

/* Function that used to Initialize the App */
void APP_Init (void )
{
	/* Make Pin0 in PortA as Output */ 
	MDIO_voidSetPinDirection(GPIOA,PIN0,HIGH) ;
	/* Make Pin0 in PortA Initially as Low */
	MDIO_voidSetPinValue(GPIOA,PIN0,LOW);
	/* Make Pin0 at PortC as Input pin */ 
	MDIO_voidSetPinDirection(GPIOC , PIN0 , LOW);
	/* Make Pin0 at PortC as Pull_Up Resistor */
	MDIO_voidSetPinValue(GPIOC , PIN0 , HIGH ); 
}