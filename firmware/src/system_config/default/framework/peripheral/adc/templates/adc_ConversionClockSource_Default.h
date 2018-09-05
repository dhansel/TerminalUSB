/*******************************************************************************
  ADC Peripheral Library Template Implementation

  File Name:
    adc_ConversionClockSource_Default.h

  Summary:
    ADC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ConversionClockSource
    and its Variant : Default
    For following APIs :
        PLIB_ADC_ConversionClockSourceSelect
        PLIB_ADC_ExistsConversionClockSource

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

#ifndef _ADC_CONVERSIONCLOCKSOURCE_DEFAULT_H
#define _ADC_CONVERSIONCLOCKSOURCE_DEFAULT_H

#include "adc_registers.h"

//******************************************************************************
/* Function :  ADC_ConversionClockSourceSelect_Default

  Summary:
    Implements Default variant of PLIB_ADC_ConversionClockSourceSelect 

  Description:
    This template implements the Default variant of the PLIB_ADC_ConversionClockSourceSelect function.
*/

PLIB_TEMPLATE void ADC_ConversionClockSourceSelect_Default( ADC_MODULE_ID index , ADC_CLOCK_SOURCE source )
{
	volatile adc_registers_t * adc = (adc_registers_t *) index;
	adc->AD1CON3.ADRC = source;
}


//******************************************************************************
/* Function :  ADC_ExistsConversionClockSource_Default

  Summary:
    Implements Default variant of PLIB_ADC_ExistsConversionClockSource

  Description:
    This template implements the Default variant of the PLIB_ADC_ExistsConversionClockSource function.
*/

#define PLIB_ADC_ExistsConversionClockSource PLIB_ADC_ExistsConversionClockSource
PLIB_TEMPLATE bool ADC_ExistsConversionClockSource_Default( ADC_MODULE_ID index )
{
    return true;
}


#endif /*_ADC_CONVERSIONCLOCKSOURCE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

