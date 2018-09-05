/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_ReadWritePolarity_Basic.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ReadWritePolarity
    and its Variant : Basic
    For following APIs :
        PLIB_PMP_ExistsReadWritePolarity
        PLIB_PMP_ReadWriteStrobePolaritySelect

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

#ifndef _PMP_READWRITEPOLARITY_BASIC_H
#define _PMP_READWRITEPOLARITY_BASIC_H

//******************************************************************************
/* Function :  PMP_ExistsReadWritePolarity_Basic

  Summary:
    Implements Basic variant of PLIB_PMP_ExistsReadWritePolarity

  Description:
    This template implements the Basic variant of the PLIB_PMP_ExistsReadWritePolarity function.
*/
#define PLIB_PMP_ExistsReadWritePolarity PLIB_PMP_ExistsReadWritePolarity
PLIB_TEMPLATE bool PMP_ExistsReadWritePolarity_Basic( PMP_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  PMP_ReadWriteStrobePolaritySelect_Basic

  Summary:
    Implements Basic variant of PLIB_PMP_ReadWriteStrobePolaritySelect 

  Description:
    This template implements the Basic variant of the PLIB_PMP_ReadWriteStrobePolaritySelect function.
*/
PLIB_TEMPLATE void PMP_ReadWriteStrobePolaritySelect_Basic( PMP_MODULE_ID index , PMP_POLARITY_LEVEL polarity )
{
    /* read-modify-write */
    PMCONbits.RDSP = polarity;
}

#endif /*_PMP_READWRITEPOLARITY_BASIC_H*/

/******************************************************************************
 End of File
*/

