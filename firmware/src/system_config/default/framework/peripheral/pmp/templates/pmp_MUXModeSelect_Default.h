/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_MUXModeSelect_Default.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : MUXModeSelect
    and its Variant : Default
    For following APIs :
        PLIB_PMP_ExistsMUXModeSelect
        PLIB_PMP_MultiplexModeSelect
        PLIB_PMP_MultiplexModeGet

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

#ifndef _PMP_MUXMODESELECT_DEFAULT_H
#define _PMP_MUXMODESELECT_DEFAULT_H

//******************************************************************************
/* Function :  PMP_ExistsMUXModeSelect_Default

  Summary:
    Implements Default variant of PLIB_PMP_ExistsMUXModeSelect

  Description:
    This template implements the Default variant of the PLIB_PMP_ExistsMUXModeSelect function.
*/
#define PLIB_PMP_ExistsMUXModeSelect PLIB_PMP_ExistsMUXModeSelect
PLIB_TEMPLATE bool PMP_ExistsMUXModeSelect_Default( PMP_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  PMP_MultiplexModeSelect_Default

  Summary:
    Implements Default variant of PLIB_PMP_MultiplexModeSelect 

  Description:
    This template implements the Default variant of the PLIB_PMP_MultiplexModeSelect function.
*/
PLIB_TEMPLATE void PMP_MultiplexModeSelect_Default( PMP_MODULE_ID index , PMP_MUX_MODE multiplexMode )
{
    PMCONbits.ADRMUX = multiplexMode;
}

//******************************************************************************
/* Function :  PMP_MultiplexModeGet_Default

  Summary:
    Implements Default variant of PLIB_PMP_MultiplexModeGet 

  Description:
    This template implements the Default variant of the PLIB_PMP_MultiplexModeGet function.
*/

PLIB_TEMPLATE PMP_MUX_MODE PMP_MultiplexModeGet_Default( PMP_MODULE_ID index )
{
    return (PMP_MUX_MODE)(((PMCON) & (_PMCON_ADRMUX_MASK)) >> (_PMCON_ADRMUX_POSITION));
}

#endif /*_PMP_MUXMODESELECT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

