/*******************************************************************************
    ADC Peripheral Library structure implementation

    File Name:
        adc_registers.h

    Summary:
        ADC PLIB base structure implementation

    Description:
        This header file contains instance structure for ADC plib module.

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

#include <xc.h>

#ifndef _ADC_STRUCTURE_H
#define _ADC_STRUCTURE_H


typedef struct __attribute__((packed , aligned(4)))
{
	volatile unsigned int   ADC1BUF;      
	volatile unsigned int   ADC1BUF0CLR; 
	volatile unsigned int   ADC1BUF0SET;
	volatile unsigned int   ADC1BUF0INV;

} __ADC1BUFX;

typedef struct __attribute__((packed , aligned(4)))
{
	__AD1CON1bits_t AD1CON1;
	volatile unsigned int AD1CON1CLR; 
	volatile unsigned int AD1CON1SET;
	volatile unsigned int AD1CON1INV;
	__AD1CON2bits_t  AD1CON2;    
	volatile unsigned int AD1CON2CLR;
	volatile unsigned int AD1CON2SET; 
	volatile unsigned int AD1CON2INV; 
	__AD1CON3bits_t AD1CON3;
	volatile unsigned int AD1CON3CLR; 
	volatile unsigned int AD1CON3SET;  
	volatile unsigned int AD1CON3INV;
    /* AD1CON4 register is not present in any of the MX devices, it has been added as a buffer here */
    __AD1CON3bits_t AD1CON4;
	volatile unsigned int AD1CON4CLR; 
	volatile unsigned int AD1CON4SET;  
	volatile unsigned int AD1CON4INV;
	__AD1CHSbits_t AD1CHS;   
	volatile unsigned int AD1CHSCLR;  
	volatile unsigned int AD1CHSSET; 
	volatile unsigned int AD1CHSINV; 
	__AD1CSSLbits_t	AD1CSSL; 
	volatile unsigned int AD1CSSLCLR;   
	volatile unsigned int AD1CSSLSET; 
	volatile unsigned int AD1CSSLINV;   
	__AD1CSSLbits_t	AD1CSSL2; 
	volatile unsigned int AD1CSSL2CLR;   
	volatile unsigned int AD1CSSL2SET; 
	volatile unsigned int AD1CSSL2INV;   
	__ADC1BUFX	ADC1BUFX[16];

} adc_registers_t;

#endif /*_ADC_STRUCTURE_H*/
/******************************************************************************
 End of File
*/

