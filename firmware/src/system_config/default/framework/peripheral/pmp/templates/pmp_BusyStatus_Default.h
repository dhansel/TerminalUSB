/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_BusyStatus_Default.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BusyStatus
    and its Variant : Default
    For following APIs :
        PLIB_PMP_ExistsBusyStatus
        PLIB_PMP_PortIsBusy

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

#ifndef _PMP_BUSYSTATUS_DEFAULT_H
#define _PMP_BUSYSTATUS_DEFAULT_H

//******************************************************************************
/* Function :  PMP_ExistsBusyStatus_Default

  Summary:
    Implements Default variant of PLIB_PMP_ExistsBusyStatus

  Description:
    This template implements the Default variant of the PLIB_PMP_ExistsBusyStatus function.
*/
#define PLIB_PMP_ExistsBusyStatus PLIB_PMP_ExistsBusyStatus
PLIB_TEMPLATE bool PMP_ExistsBusyStatus_Default( PMP_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  PMP_PortIsBusy_Default

  Summary:
    Implements Default variant of PLIB_PMP_PortIsBusy 

  Description:
    This template implements the Default variant of the PLIB_PMP_PortIsBusy function.
*/
PLIB_TEMPLATE bool PMP_PortIsBusy_Default( PMP_MODULE_ID index )
{
    return (PMMODE) & (_PMMODE_BUSY_MASK);
}

#endif /*_PMP_BUSYSTATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

