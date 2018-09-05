/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_DualBufferControl_Unsupported.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DualBufferControl
    and its Variant : Unsupported
    For following APIs :
        PLIB_PMP_ExistsDualBufferControl
        PLIB_PMP_DualBufferDisable
        PLIB_PMP_DualBufferEnable
        PLIB_PMP_DualBufferIsEnabled

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

#ifndef _PMP_DUALBUFFERCONTROL_UNSUPPORTED_H
#define _PMP_DUALBUFFERCONTROL_UNSUPPORTED_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    None.

  MASKs: 
    None.

  POSs: 
    None.

  LENs: 
    None.

*/


//******************************************************************************
/* Function :  PMP_ExistsDualBufferControl_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PMP_ExistsDualBufferControl

  Description:
    This template implements the Unsupported variant of the PLIB_PMP_ExistsDualBufferControl function.
*/

PLIB_TEMPLATE bool PMP_ExistsDualBufferControl_Unsupported( PMP_MODULE_ID index )
{
    return false;
}


//******************************************************************************
/* Function :  PMP_DualBufferDisable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PMP_DualBufferDisable 

  Description:
    This template implements the Unsupported variant of the PLIB_PMP_DualBufferDisable function.
*/

PLIB_TEMPLATE void PMP_DualBufferDisable_Unsupported( PMP_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_PMP_DualBufferDisable");
}


//******************************************************************************
/* Function :  PMP_DualBufferEnable_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PMP_DualBufferEnable 

  Description:
    This template implements the Unsupported variant of the PLIB_PMP_DualBufferEnable function.
*/

PLIB_TEMPLATE void PMP_DualBufferEnable_Unsupported( PMP_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_PMP_DualBufferEnable");
}


//******************************************************************************
/* Function :  PMP_DualBufferIsEnabled_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PMP_DualBufferIsEnabled 

  Description:
    This template implements the Unsupported variant of the PLIB_PMP_DualBufferIsEnabled function.
*/

PLIB_TEMPLATE bool PMP_DualBufferIsEnabled_Unsupported( PMP_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_PMP_DualBufferIsEnabled");

    return false;
}


#endif /*_PMP_DUALBUFFERCONTROL_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

