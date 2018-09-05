/*******************************************************************************
  CTMU Peripheral Library Template Implementation

  File Name:
    ctmu_EdgeTriggerSource_Default.h

  Summary:
    CTMU PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EdgeTriggerSource
    and its Variant : Default
    For following APIs :
        PLIB_CTMU_EdgeTriggerSourceSelect
        PLIB_CTMU_ExistsEdgeTriggerSource

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

//DOM-IGNORE-END

#ifndef _CTMU_EDGETRIGGERSOURCE_DEFAULT_H
#define _CTMU_EDGETRIGGERSOURCE_DEFAULT_H

#include "ctmu_registers.h"

//******************************************************************************
/* Function :  CTMU_EdgeTriggerSourceSelect_Default

  Summary:
    Implements Default variant of PLIB_CTMU_EdgeTriggerSourceSelect

  Description:
    This template implements the Default variant of the PLIB_CTMU_EdgeTriggerSourceSelect function.
*/

PLIB_TEMPLATE void CTMU_EdgeTriggerSourceSelect_Default( CTMU_MODULE_ID index , CTMU_EDGE_SELECT edgeNumber , CTMU_TRIGGER_SOURCES triggerSource )
{
	volatile ctmu_registers_t *ctmu = ((ctmu_registers_t *)(index));
    if ( edgeNumber == CTMU_EDGE1 )
	{
		ctmu->CTMUCON.EDG1SEL = triggerSource;
	}
	else
	{
		ctmu->CTMUCON.EDG2SEL = triggerSource;
	}
}


//******************************************************************************
/* Function :  CTMU_ExistsEdgeTriggerSource_Default

  Summary:
    Implements Default variant of PLIB_CTMU_ExistsEdgeTriggerSource

  Description:
    This template implements the Default variant of the PLIB_CTMU_ExistsEdgeTriggerSource function.
*/

#define PLIB_CTMU_ExistsEdgeTriggerSource PLIB_CTMU_ExistsEdgeTriggerSource
PLIB_TEMPLATE bool CTMU_ExistsEdgeTriggerSource_Default( CTMU_MODULE_ID index )
{
    return true;
}


#endif /*_CTMU_EDGETRIGGERSOURCE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

