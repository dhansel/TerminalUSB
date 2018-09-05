/*******************************************************************************
  CMP Peripheral Library Template Implementation

  File Name:
    cmp_NonInvertingInputSelect_Default.h

  Summary:
    CMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : NonInvertingInputSelect
    and its Variant : Default
    For following APIs :
        PLIB_CMP_ExistsNonInvertingInputSelect
        PLIB_CMP_NonInvertingInputChannelSelect

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

#ifndef _CMP_NONINVERTINGINPUTSELECT_DEFAULT_H
#define _CMP_NONINVERTINGINPUTSELECT_DEFAULT_H

#include "cmp_registers.h"

//******************************************************************************
/* Function :  CMP_ExistsNonInvertingInputSelect_Default

  Summary:
    Implements Default variant of PLIB_CMP_ExistsNonInvertingInputSelect

  Description:
    This template implements the Default variant of the PLIB_CMP_ExistsNonInvertingInputSelect function.
*/

#define PLIB_CMP_ExistsNonInvertingInputSelect PLIB_CMP_ExistsNonInvertingInputSelect
PLIB_TEMPLATE bool CMP_ExistsNonInvertingInputSelect_Default( CMP_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  CMP_NonInvertingInputChannelSelect_Default

  Summary:
    Implements Default variant of PLIB_CMP_NonInvertingInputChannelSelect 

  Description:
    This template implements the Default variant of the PLIB_CMP_NonInvertingInputChannelSelect function.
*/

PLIB_TEMPLATE void CMP_NonInvertingInputChannelSelect_Default( CMP_MODULE_ID index , CMP_NON_INVERTING_INPUT input )
{
	volatile cmp_registers_t *cmp = ((cmp_registers_t *)(index));
	cmp->CMxCON.CREF = input;
}


#endif /*_CMP_NONINVERTINGINPUTSELECT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

