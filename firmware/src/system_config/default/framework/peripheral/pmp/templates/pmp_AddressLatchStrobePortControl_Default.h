/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_AddressLatchStrobePortControl_Default.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AddressLatchStrobePortControl
    and its Variant : Default
    For following APIs :
        PLIB_PMP_ExistsAddressLatchStrobePortControl
        PLIB_PMP_AddressLatchStrobeEnable
        PLIB_PMP_AddressLatchStrobeDisable

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PMP_ADDRESSLATCHSTROBEPORTCONTROL_DEFAULT_H
#define _PMP_ADDRESSLATCHSTROBEPORTCONTROL_DEFAULT_H

//******************************************************************************
/* Function :  PMP_ExistsAddressLatchStrobePortControl_Default

  Summary:
    Implements Default variant of PLIB_PMP_ExistsAddressLatchStrobePortControl

  Description:
    This template implements the Default variant of the PLIB_PMP_ExistsAddressLatchStrobePortControl function.
*/
#define PLIB_PMP_ExistsAddressLatchStrobePortControl PLIB_PMP_ExistsAddressLatchStrobePortControl
PLIB_TEMPLATE bool PMP_ExistsAddressLatchStrobePortControl_Default( PMP_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  PMP_AddressLatchStrobeEnable_Default

  Summary:
    Implements Default variant of PLIB_PMP_AddressLatchStrobeEnable 

  Description:
    This template implements the Default variant of the PLIB_PMP_AddressLatchStrobeEnable function.
*/
PLIB_TEMPLATE void PMP_AddressLatchStrobeEnable_Default( PMP_MODULE_ID index , PMP_ADDRESS_LATCH latch )
{
    PMAENSET = (uint32_t)( 0x3 & latch );
}


//******************************************************************************
/* Function :  PMP_AddressLatchStrobeDisable_Default

  Summary:
    Implements Default variant of PLIB_PMP_AddressLatchStrobeDisable 

  Description:
    This template implements the Default variant of the PLIB_PMP_AddressLatchStrobeDisable function.
*/

PLIB_TEMPLATE void PMP_AddressLatchStrobeDisable_Default( PMP_MODULE_ID index , PMP_ADDRESS_LATCH latch )
{
    PMAENCLR = (uint32_t)( 0x3 & latch );
}

#endif /*_PMP_ADDRESSLATCHSTROBEPORTCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

