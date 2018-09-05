/*******************************************************************************
  ADC Peripheral Library Template Implementation

  File Name:
    adc_ConversionClock_Default.h

  Summary:
    ADC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ConversionClock
    and its Variant : Default
    For following APIs :
        PLIB_ADC_ConversionClockSet
        PLIB_ADC_ConversionClockGet
        PLIB_ADC_ExistsConversionClock

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

#ifndef _ADC_CONVERSIONCLOCK_DEFAULT_H
#define _ADC_CONVERSIONCLOCK_DEFAULT_H

#include "adc_registers.h"

//******************************************************************************
/* Function :  ADC_ConversionClockSet_Default

  Summary:
    Implements Default variant of PLIB_ADC_ConversionClockSet

  Description:
    This template implements the Default variant of the PLIB_ADC_ConversionClockSet function.
*/

PLIB_TEMPLATE void ADC_ConversionClockSet_Default( ADC_MODULE_ID index , uint32_t baseFrequency , ADC_CONVERSION_CLOCK value )
{
    char regValue = ((baseFrequency/value)/2) - 1;
	volatile adc_registers_t * adc = (adc_registers_t *) index;
	adc->AD1CON3SET = (_AD1CON3_ADCS_MASK & ((uint32_t) regValue << _AD1CON3_ADCS_POSITION));
}


//******************************************************************************
/* Function :  ADC_ConversionClockGet_Default

  Summary:
    Implements Default variant of PLIB_ADC_ConversionClockGet

  Description:
    This template implements the Default variant of the PLIB_ADC_ConversionClockGet function.
*/

PLIB_TEMPLATE uint32_t ADC_ConversionClockGet_Default( ADC_MODULE_ID index , uint32_t baseFrequency )
{
    char regValue;
    volatile adc_registers_t * adc = (adc_registers_t *) index;
    
	regValue = 	adc->AD1CON3.ADCS;

	return 	((baseFrequency/(regValue + 1))/2);
}


//******************************************************************************
/* Function :  ADC_ExistsConversionClock_Default

  Summary:
    Implements Default variant of PLIB_ADC_ExistsConversionClock

  Description:
    This template implements the Default variant of the PLIB_ADC_ExistsConversionClock function.
*/

#define PLIB_ADC_ExistsConversionClock PLIB_ADC_ExistsConversionClock
PLIB_TEMPLATE bool ADC_ExistsConversionClock_Default( ADC_MODULE_ID index )
{
    return true;
}


#endif /*_ADC_CONVERSIONCLOCK_DEFAULT_H*/

/******************************************************************************
 End of File
*/

