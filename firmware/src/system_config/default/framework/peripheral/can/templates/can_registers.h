/*******************************************************************************
	CAN Peripheral Library structure implementation

	File Name:
		can_structure.h

	Summary:
		CAN PLIB base structure implementation

	Description:
		This header file contains instance structure for CAN plib module.

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

#ifndef _CAN_STRUCTURE_H
#define _CAN_STRUCTURE_H

typedef struct __attribute__((packed, aligned(4)))
{
	__C1RXM0bits_t		CRXM0;
	volatile unsigned int		CRXM0CLR;
	volatile unsigned int		CRXM0SET;
	volatile unsigned int		CRXM0INV;

} __CXRXMREG_t ;

typedef struct __attribute__((packed, aligned(4)))
{
	__C1FLTCON0bits_t	CFLTCON0;
	volatile unsigned int	CFLTCON0CLR;
	volatile unsigned int	CFLTCON0SET;
	volatile unsigned int	CFLTCON0INV;

} __CXFLTCONREG_t ;

typedef struct __attribute__((packed, aligned(4)))
{
	__C1RXF1bits_t			CRXF1;
	volatile unsigned int	CRXF1CLR;
	volatile unsigned int	CRXF1SET;
	volatile unsigned int	CRXF1INV;

} __CXRXFREG_t ;

typedef struct __attribute__((packed, aligned(4)))
{
	__C1FIFOCON0bits_t		CFIFOCON0;
	volatile unsigned int	CFIFOCON0CLR;
	volatile unsigned int	CFIFOCON0SET;
	volatile unsigned int	CFIFOCON0INV;
	__C1FIFOINT0bits_t		CFIFOINT0;	
	volatile unsigned int	CFIFOINT0CLR;
	volatile unsigned int	CFIFOINT0SET;
	volatile unsigned int	CFIFOINT0INV;
	volatile unsigned int	CFIFOUA0;	
	volatile unsigned int	CFIFOUA0CLR;
	volatile unsigned int	CFIFOUA0SET;
	volatile unsigned int	CFIFOUA0INV;
	__C1FIFOCI0bits_t		CFIFOCI0;
	volatile unsigned int	CFIFOCI0CLR;
	volatile unsigned int	CFIFOCI0SET;
	volatile unsigned int	CFIFOCI0INV;

} __CXFIFOREG_t ;

typedef struct __attribute__((packed, aligned(4)))
{
	__C1CONbits_t			CCON;
	volatile unsigned int	CCONCLR;
	volatile unsigned int	CCONSET;
	volatile unsigned int	CCONINV;
	__C1CFGbits_t			CCFG;
	volatile unsigned int	CCFGCLR;
	volatile unsigned int	CCFGSET;
	volatile unsigned int	CCFGINV;
	__C1INTbits_t			CINT;	
	volatile unsigned int	CINTCLR;
	volatile unsigned int	CINTSET;
	volatile unsigned int	CINTINV;
	__C1VECbits_t			CVEC;
	volatile unsigned int	CVECCLR;
	volatile unsigned int	CVECSET;
	volatile unsigned int	CVECINV;
	__C1TRECbits_t			CTREC;
	volatile unsigned int	CTRECCLR;
	volatile unsigned int	CTRECSET;
	volatile unsigned int	CTRECINV;
	__C1FSTATbits_t			CFSTAT;
	volatile unsigned int	CFSTATCLR;
	volatile unsigned int	CFSTATSET;
	volatile unsigned int	CFSTATINV;
	__C1RXOVFbits_t			CRXOVRF;
	volatile unsigned int	CRXOVRFCLR;
	volatile unsigned int	CRXOVRFSET;
	volatile unsigned int	CRXOVRFINV;
	__C1TMRbits_t			CTMR;
	volatile unsigned int	CTMRCLR;
	volatile unsigned int	CTMRSET;
	volatile unsigned int	CTMRINV;
	__CXRXMREG_t			CRXM[4];
	__CXFLTCONREG_t			CFLTCON[8];
	__CXRXFREG_t			CRXF[32];
	volatile unsigned int	CFIFOBA;
	volatile unsigned int	CFIFOBACLR;
	volatile unsigned int	CFIFOBASET;
	volatile unsigned int	CFIFOBAINV;
	__CXFIFOREG_t			CFIFOREG[32];

} can_registers_t ;



#endif /*_CAN_STRUCTURE_H*/

/******************************************************************************
 End of File
*/

