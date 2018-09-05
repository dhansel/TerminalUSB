/*******************************************************************************
  BMX Peripheral Library Template Implementation

  File Name:
    bmx_ProgramFlashMemoryCacheDma_Default.h

  Summary:
    BMX PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ProgramFlashMemoryCacheDma
    and its Variant : Default
    For following APIs :
        PLIB_BMX_ExistsProgramFlashMemoryCacheDma
        PLIB_BMX_ProgramFlashMemoryCacheDmaEnable
        PLIB_BMX_ProgramFlashMemoryCacheDmaDisable

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

#ifndef _BMX_PROGRAMFLASHMEMORYCACHEDMA_DEFAULT_H
#define _BMX_PROGRAMFLASHMEMORYCACHEDMA_DEFAULT_H

#include "bmx_registers.h"

//******************************************************************************
/* Function :  BMX_ExistsProgramFlashMemoryCacheDma_Default

  Summary:
    Implements Default variant of PLIB_BMX_ExistsProgramFlashMemoryCacheDma

  Description:
    This template implements the Default variant of the PLIB_BMX_ExistsProgramFlashMemoryCacheDma function.
*/

#define PLIB_BMX_ExistsProgramFlashMemoryCacheDma PLIB_BMX_ExistsProgramFlashMemoryCacheDma
PLIB_TEMPLATE bool BMX_ExistsProgramFlashMemoryCacheDma_Default( BMX_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  BMX_ProgramFlashMemoryCacheDmaEnable_Default

  Summary:
    Implements Default variant of PLIB_BMX_ProgramFlashMemoryCacheDmaEnable 

  Description:
    This template implements the Default variant of the PLIB_BMX_ProgramFlashMemoryCacheDmaEnable function.
*/

PLIB_TEMPLATE void BMX_ProgramFlashMemoryCacheDmaEnable_Default( BMX_MODULE_ID index )
{
    volatile bmx_register_t *bmx = (bmx_register_t *)index;

    bmx->BMXCONSET = _BMXCON_BMXCHEDMA_MASK;
}


//******************************************************************************
/* Function :  BMX_ProgramFlashMemoryCacheDmaDisable_Default

  Summary:
    Implements Default variant of PLIB_BMX_ProgramFlashMemoryCacheDmaDisable 

  Description:
    This template implements the Default variant of the PLIB_BMX_ProgramFlashMemoryCacheDmaDisable function.
*/

PLIB_TEMPLATE void BMX_ProgramFlashMemoryCacheDmaDisable_Default( BMX_MODULE_ID index )
{
    volatile bmx_register_t *bmx = (bmx_register_t *)index;

    bmx->BMXCONCLR = _BMXCON_BMXCHEDMA_MASK;
}


#endif /*_BMX_PROGRAMFLASHMEMORYCACHEDMA_DEFAULT_H*/

/******************************************************************************
 End of File
*/

