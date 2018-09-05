/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_InputBufferXStatus_Default.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : InputBufferXStatus
    and its Variant : Default
    For following APIs :
        PLIB_PMP_ExistsInputBufferXStatus
        PLIB_PMP_InputBufferXIsFull
        PLIB_PMP_IsDataReceived

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

#ifndef _PMP_INPUTBUFFERXSTATUS_DEFAULT_H
#define _PMP_INPUTBUFFERXSTATUS_DEFAULT_H

//******************************************************************************
/* Function :  PMP_ExistsInputBufferXStatus_Default

  Summary:
    Implements Default variant of PLIB_PMP_ExistsInputBufferXStatus

  Description:
    This template implements the Default variant of the PLIB_PMP_ExistsInputBufferXStatus function.
*/
#define PLIB_PMP_ExistsInputBufferXStatus PLIB_PMP_ExistsInputBufferXStatus
PLIB_TEMPLATE bool PMP_ExistsInputBufferXStatus_Default( PMP_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  PMP_InputBufferXIsFull_Default

  Summary:
    Implements Default variant of PLIB_PMP_InputBufferXIsFull 

  Description:
    This template implements the Default variant of the PLIB_PMP_InputBufferXIsFull function.
*/
PLIB_TEMPLATE bool PMP_InputBufferXIsFull_Default( PMP_MODULE_ID index , uint8_t buffer )
{
    return (bool)(((PMSTAT) & (_PMSTAT_IB0F_MASK << buffer)) >> (_PMSTAT_IB0F_POSITION + buffer));
}

//******************************************************************************
/* Function :  PMP_IsDataReceived_Default

  Summary:
    Implements Default variant of PLIB_PMP_IsDataReceived 

  Description:
    This template implements the Default variant of the PLIB_PMP_IsDataReceived function.
*/
PLIB_TEMPLATE bool PMP_IsDataReceived_Default( PMP_MODULE_ID index , uint8_t buffer )
{
    return (bool)(((PMSTAT) & (_PMSTAT_IB0F_MASK << buffer)) >> (_PMSTAT_IB0F_POSITION + buffer));
}

#endif /*_PMP_INPUTBUFFERXSTATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

