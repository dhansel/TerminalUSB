/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_BufferUnderFlow_Default.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BufferUnderFlow
    and its Variant : Default
    For following APIs :
        PLIB_PMP_ExistsBufferUnderFlow
        PLIB_PMP_OutputUnderflowHasOccured
        PLIB_PMP_OutputUnderflowClear

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

#ifndef _PMP_BUFFERUNDERFLOW_DEFAULT_H
#define _PMP_BUFFERUNDERFLOW_DEFAULT_H

//******************************************************************************
/* Function :  PMP_ExistsBufferUnderFlow_Default

  Summary:
    Implements Default variant of PLIB_PMP_ExistsBufferUnderFlow

  Description:
    This template implements the Default variant of the PLIB_PMP_ExistsBufferUnderFlow function.
*/
#define PLIB_PMP_ExistsBufferUnderFlow PLIB_PMP_ExistsBufferUnderFlow
PLIB_TEMPLATE bool PMP_ExistsBufferUnderFlow_Default( PMP_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  PMP_OutputUnderflowHasOccured_Default

  Summary:
    Implements Default variant of PLIB_PMP_OutputUnderflowHasOccured 

  Description:
    This template implements the Default variant of the PLIB_PMP_OutputUnderflowHasOccured function.
*/
PLIB_TEMPLATE bool PMP_OutputUnderflowHasOccurred_Default( PMP_MODULE_ID index )
{
    return (PMSTAT) & (_PMSTAT_OBUF_MASK);
}

//******************************************************************************
/* Function :  PMP_OutputUnderflowClear_Default

  Summary:
    Implements Default variant of PLIB_PMP_OutputUnderflowClear 

  Description:
    This template implements the Default variant of the PLIB_PMP_OutputUnderflowClear function.
*/
PLIB_TEMPLATE void PMP_OutputUnderflowClear_Default( PMP_MODULE_ID index )
{
    (PMSTATCLR) = (_PMSTAT_OBUF_MASK);
}

#endif /*_PMP_BUFFERUNDERFLOW_DEFAULT_H*/

/******************************************************************************
 End of File
*/

