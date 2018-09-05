/*******************************************************************************
  CMP Peripheral Library Template Implementation

  File Name:
    cmp_CVREFWideRangeControl_Default.h

  Summary:
    CMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : CVREFWideRangeControl
    and its Variant : Default
    For following APIs :
        PLIB_CMP_ExistsCVREFWideRangeControl
        PLIB_CMP_CVREF_WideRangeEnable
        PLIB_CMP_CVREF_WideRangeDisable
        PLIB_CMP_CVREF_WideRangeIsEnabled

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

#ifndef _CMP_CVREFWIDERANGECONTROL_DEFAULT_H
#define _CMP_CVREFWIDERANGECONTROL_DEFAULT_H

#include "cmp_registers.h"

//******************************************************************************
/* Function :  CMP_ExistsCVREFWideRangeControl_Default

  Summary:
    Implements Default variant of PLIB_CMP_ExistsCVREFWideRangeControl

  Description:
    This template implements the Default variant of the PLIB_CMP_ExistsCVREFWideRangeControl function.
*/

#define PLIB_CMP_ExistsCVREFWideRangeControl PLIB_CMP_ExistsCVREFWideRangeControl
PLIB_TEMPLATE bool CMP_ExistsCVREFWideRangeControl_Default( CMP_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CMP_CVREF_WideRangeEnable_Default

  Summary:
    Implements Default variant of PLIB_CMP_CVREF_WideRangeEnable 

  Description:
    This template implements the Default variant of the PLIB_CMP_CVREF_WideRangeEnable function.
*/

PLIB_TEMPLATE void CMP_CVREF_WideRangeEnable_Default( CMP_MODULE_ID index )
{
	CVRCONSET = _CVRCON_CVRR_MASK;
}


//******************************************************************************
/* Function :  CMP_CVREF_WideRangeDisable_Default

  Summary:
    Implements Default variant of PLIB_CMP_CVREF_WideRangeDisable 

  Description:
    This template implements the Default variant of the PLIB_CMP_CVREF_WideRangeDisable function.
*/

PLIB_TEMPLATE void CMP_CVREF_WideRangeDisable_Default( CMP_MODULE_ID index )
{
	CVRCONCLR = _CVRCON_CVRR_MASK;
}


//******************************************************************************
/* Function :  CMP_CVREF_WideRangeIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_CMP_CVREF_WideRangeIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_CMP_CVREF_WideRangeIsEnabled function.
*/

PLIB_TEMPLATE bool CMP_CVREF_WideRangeIsEnabled_Default( CMP_MODULE_ID index )
{
	return CVRCONbits.CVRR;
}


#endif /*_CMP_CVREFWIDERANGECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

