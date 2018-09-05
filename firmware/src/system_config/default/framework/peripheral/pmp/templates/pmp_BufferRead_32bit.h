/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_BufferRead_32bit.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BufferRead
    and its Variant : 32bit
    For following APIs :
        PLIB_PMP_ExistsBufferRead
        PLIB_PMP_InputBufferXByteReceive

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

#ifndef _PMP_BUFFERREAD_32BIT_H
#define _PMP_BUFFERREAD_32BIT_H

//******************************************************************************
/* Function :  PMP_ExistsBufferRead_32bit

  Summary:
    Implements 32bit variant of PLIB_PMP_ExistsBufferRead

  Description:
    This template implements the 32bit variant of the PLIB_PMP_ExistsBufferRead function.
*/
#define PLIB_PMP_ExistsBufferRead PLIB_PMP_ExistsBufferRead
PLIB_TEMPLATE bool PMP_ExistsBufferRead_32bit( PMP_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  PMP_InputBufferXByteReceive_32bit

  Summary:
    Implements 32bit variant of PLIB_PMP_InputBufferXByteReceive 

  Description:
    This template implements the 32bit variant of the PLIB_PMP_InputBufferXByteReceive function.
*/
PLIB_TEMPLATE uint8_t PMP_InputBufferXByteReceive_32bit( PMP_MODULE_ID index , uint8_t buffer )
{
    return (uint8_t)((PMDIN & (0x000000FF << (8*buffer))) >> (8*buffer));
}

#endif /*_PMP_BUFFERREAD_32BIT_H*/

/******************************************************************************
 End of File
*/

