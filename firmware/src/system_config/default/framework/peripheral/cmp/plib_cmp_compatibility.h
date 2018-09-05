/*******************************************************************************
  Comparator Peripheral Library Compatibility Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_cmp_compatibility.h

  Summary:
    Comparator Peripheral Library Interface header for backward compatibility.

  Description:
    This header file contains the definitions of the functions which are
    supported for backward compatibility only. These will be deprecated later. 
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright 2013-2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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
// DOM-IGNORE-END

#ifndef _PLIB_CMP_COMPATIBILITY_H
#define _PLIB_CMP_COMPATIBILITY_H

#include <stdint.h>
#include <stddef.h>


// *****************************************************************************
/* Function:
    void PLIB_CMP_OutputLogicHigh ( CMP_MODULE_ID index )

  Summary:
    This function will be deprecated later.

  Description:
    This API tries to write read-only bit of comparator module which is not 
    allowed. This function will be deprecated later.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    None.

  Remarks:
    This feature is not available on any devices and it will be deprecated later.
*/

PLIB_INLINE_API void PLIB_CMP_OutputLogicHigh( CMP_MODULE_ID index )
{
    PLIB_ASSERT(false, "This feature is not supported on the selected microcontroller");
}

// *****************************************************************************
/* Function:
    void PLIB_CMP_OutputLogicLow ( CMP_MODULE_ID index )

  Summary:
    This function will be deprecated later.

  Description:
    This API tries to write read-only bit of comparator module which is not 
    allowed. This function will be deprecated later.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    None.

  Remarks:
    This feature is not available on any devices and it will be deprecated later.
*/

PLIB_INLINE_API void PLIB_CMP_OutputLogicLow( CMP_MODULE_ID index )
{
    PLIB_ASSERT(false, "This feature is not supported on the selected microcontroller");
}

//******************************************************************************
/* Function :  
    bool PLIB_CMP_ExistsOutputLevelControl( CMP_MODULE_ID index )

  Summary:
    This function will be deprecated.

  Description:
    This function tries to identify OutputLevelSelectControl feature which 
    doesn't exist for comparator module and hence it will always return false.

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - false  - The OutputLevelSelectControl feature is not supported.

  Remarks:
    None.
*/

PLIB_INLINE_API bool PLIB_CMP_ExistsOutputLevelControl( CMP_MODULE_ID index )
{
    PLIB_ASSERT(false, "This feature is not supported on the selected microcontroller");
    return false;
}

#endif // #ifndef _PLIB_CMP_COMPATIBILITY_H
/*******************************************************************************
 End of File
*/
