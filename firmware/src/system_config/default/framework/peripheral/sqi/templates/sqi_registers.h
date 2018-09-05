/*******************************************************************************
    SQI Peripheral Library structure implementation

    File Name:
	sqi_registers.h

    Summary:
	SQI PLIB Register structure implementation

    Description:
	This header file contains instance structure for SQI plib module.

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

#ifndef _PLIB_SQI_REGISTERS_H
#define _PLIB_SQI_REGISTERS_H

typedef struct sqi_regs
{
    __SQI1XCON1bits_t    SQIXCON1;  /* 0x00 */
    __SQI1XCON2bits_t    SQIXCON2;
    __SQI1CFGbits_t      SQICFG;
    __SQI1CONbits_t      SQICON;
    __SQI1CLKCONbits_t   SQICLKCON; /* 0x10 */
    __SQI1CMDTHRbits_t   SQICMDTHR;
    __SQI1INTTHRbits_t   SQIINTTHR;
    __SQI1INTENbits_t    SQIINTEN;
    __SQI1INTSTATbits_t  SQIINTSTAT; /* 0x20 */
    uint32_t             SQITXDATA;
    uint32_t             SQIRXDATA;
    __SQI1STAT1bits_t    SQISTAT1;
    __SQI1STAT2bits_t    SQISTAT2;  /* 0x30 */
    __SQI1BDCONbits_t    SQIBDCON;
    __SQI1BDCURADDbits_t SQIBDCURADDR;
    uint32_t             DONTUSE;
    uint32_t             SQIBDBASEADDR; /* 0x40 */
    __SQI1BDSTATbits_t   SQIBDSTAT;
    __SQI1BDPOLLCONbits_t SQIBDPOLLCON;
    __SQI1BDTXDSTATbits_t SQIBDTXDSTAT;
    __SQI1BDRXDSTATbits_t SQIBDRXDSTAT; /* 0x50 */
    __SQI1THRbits_t       SQITHR;
#if defined(_SQI1INTSEN_TXEMPTYISE_POSITION)
    __SQI1INTSENbits_t    SQIINTSIGEN;
#else
    __SQI1INTSIGENbits_t  SQIINTSIGEN;
#endif
    /* v2/v3 specific */
    uint32_t    SQITAPCON;
    uint32_t    SQIMEMSTAT; /* 0x60 */
    uint32_t    SQIXCON3;
    uint32_t    SQIXCON4;
} sqi_registers_t;

#endif /*_PLIB_SQI_REGISTERS_H */

/******************************************************************************
 End of File
*/
