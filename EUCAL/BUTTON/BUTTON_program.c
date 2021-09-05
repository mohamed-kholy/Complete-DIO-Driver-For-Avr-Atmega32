#include "../../Lib/STD_TYPES.h"
#include "../../Lib/BIT_MATH.h"
#include "BUTTON_interface.h"
#include "../../MCAl/DIO/MDIO_interface.h"


/************************************************************************************
* Parameters  :(in): PORT Name , Pin Number , Type OF the Connection (Pull Up or Pull Down )
* Parameters  :(out): Button Pressed or None 
* Return value: 8-bit signed Char , if Pressed return 1 , not pressed return 0 otherwise return -1 
* Description : Check If the Button Pressed Or Not 
************************************************************************************/

s8	EUButtonPressed(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8ConnectionType )
{
	/* Local Variable hold the Return Value */
	s8 copy_u8LocalReturn = 0 ;
	/* In case of Pull Up Connection */
	if (copy_u8ConnectionType == PULL_UP)
	{	
		/* Read the Value */ 
		copy_u8LocalReturn=MDIO_voidGetPinValue(copy_u8Port,copy_u8Pin);
		/* If Pressed Return  */
		if (copy_u8LocalReturn == 0 )
			return 1 ;
		/* Otherwise Return 0 */
		else 
			return 	 0 ;
	}
	/* In case of PULL Down */
	else if (copy_u8ConnectionType == PULL_DOWN)
	{
		/* Read the Value */ 
		copy_u8LocalReturn=MDIO_voidGetPinValue(copy_u8Port,copy_u8Pin);
		/* If Pressed */
		if (copy_u8LocalReturn == 1 )
			return 1 ;
		/* Otherwise */
		else 
			return 	0 ;
		
	}
	/* if Error */
	else 
		return -1 ;
	
}