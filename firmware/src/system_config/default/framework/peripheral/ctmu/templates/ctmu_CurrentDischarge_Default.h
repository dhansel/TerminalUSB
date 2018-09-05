/*******************************************************************************
  CTMU Peripheral Library Template Implementation

  File Name:
    ctmu_CurrentDischarge_Default.h

  Summary:
    CTMU PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : CurrentDischarge
    and its Variant : Default
    For following APIs :
        PLIB_CTMU_CurrentDischargeEnable
        PLIB_CTMU_CurrentDischargeDisable
        PLIB_CTMU_ExistsCurrentDischarge

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

#ifndef _CTMU_CURRENTDISCHARGE_DEFAULT_H
#define _CTMU_CURRENTDISCHARGE_DEFAULT_H

#include "ctmu_registers.h"

//******************************************************************************
/* Function :  CTMU_CurrentDischargeEnable_Default

  Summary:
    Implements Default variant of PLIB_CTMU_CurrentDischargeEnable

  Description:
    This template implements the Default variant of the PLIB_CTMU_CurrentDischargeEnable function.
*/

PLIB_TEMPLATE void CTMU_CurrentDischargeEnable_Default( CTMU_MODULE_ID index )
{
	volatile ctmu_registers_t *ctmu = ((ctmu_registers_t *)(index));
	ctmu->CTMUCONSET = _CTMUCON_IDISSEN_MASK;
}


//******************************************************************************
/* Function :  CTMU_CurrentDischargeDisable_Default

  Summary:
    Implements Default variant of PLIB_CTMU_CurrentDischargeDisable

  Description:
    This template implements the Default variant of the PLIB_CTMU_CurrentDischargeDisable function.
*/

PLIB_TEMPLATE void CTMU_CurrentDischargeDisable_Default( CTMU_MODULE_ID index )
{
	volatile ctmu_registers_t *ctmu = ((ctmu_registers_t *)(index));
	ctmu->CTMUCONCLR = _CTMUCON_IDISSEN_MASK;
}


//******************************************************************************
/* Function :  CTMU_ExistsCurrentDischarge_Default

  Summary:
    Implements Default variant of PLIB_CTMU_ExistsCurrentDischarge

  Description:
    This template implements the Default variant of the PLIB_CTMU_ExistsCurrentDischarge function.
*/

#define PLIB_CTMU_ExistsCurrentDischarge PLIB_CTMU_ExistsCurrentDischarge
PLIB_TEMPLATE bool CTMU_ExistsCurrentDischarge_Default( CTMU_MODULE_ID index )
{
    return true;
}


#endif /*_CTMU_CURRENTDISCHARGE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

