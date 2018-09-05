/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_DualModeMasterRXTX_Unsupported.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DualModeMasterRXTX
    and its Variant : Unsupported
    For following APIs :
        PLIB_PMP_ExistsDualModeMasterRXTX
        PLIB_PMP_DualModeMasterSend
        PLIB_PMP_DualModeMasterReceive

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

#ifndef _PMP_DUALMODEMASTERRXTX_UNSUPPORTED_H
#define _PMP_DUALMODEMASTERRXTX_UNSUPPORTED_H

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
/* Function :  PMP_ExistsDualModeMasterRXTX_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PMP_ExistsDualModeMasterRXTX

  Description:
    This template implements the Unsupported variant of the PLIB_PMP_ExistsDualModeMasterRXTX function.
*/

PLIB_TEMPLATE bool PMP_ExistsDualModeMasterRXTX_Unsupported( PMP_MODULE_ID index )
{
    return false;
}


//******************************************************************************
/* Function :  PMP_DualModeMasterSend_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PMP_DualModeMasterSend 

  Description:
    This template implements the Unsupported variant of the PLIB_PMP_DualModeMasterSend function.
*/

PLIB_TEMPLATE void PMP_DualModeMasterSend_Unsupported( PMP_MODULE_ID index , uint16_t data )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_PMP_DualModeMasterSend");
}


//******************************************************************************
/* Function :  PMP_DualModeMasterReceive_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_PMP_DualModeMasterReceive 

  Description:
    This template implements the Unsupported variant of the PLIB_PMP_DualModeMasterReceive function.
*/

PLIB_TEMPLATE uint16_t PMP_DualModeMasterReceive_Unsupported( PMP_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_PMP_DualModeMasterReceive");

    return 0;
}


#endif /*_PMP_DUALMODEMASTERRXTX_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

