/*******************************************************************************
  CMP Peripheral Library structure implementation

  File Name:
    cmp_registers.h

  Summary:
    CMP PLIB base structure implementation

  Description:
    This header file contains instance structure for CMP PLIB module.

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

#ifndef _CMP_STRUCTURE_H
#define _CMP_STRUCTURE_H

/* This is the register set structure of CMP module */
#if defined(__32MK1024MCF100_H)|| defined(__32MK1024MCF064_H) || defined(__32MK0512MCF100_H) || defined(__32MK0512MCF064_H)
	typedef struct __attribute__((packed, aligned(4)))
	{
			__CM1CONbits_t           CMxCON;
			volatile unsigned int    CMxCONCLR;
			volatile unsigned int    CMxCONSET;
			volatile unsigned int    CMxCONINV;
			__CM1MSKCONbits_t		 CMxMSKCON;
			volatile unsigned int    CMxMSKCONCLR;
			volatile unsigned int    CMxMSKCONSET;
			volatile unsigned int    CMxMSKCONINV;
			
			/*CVRCON and CMSTAT registers are common for all Comparator instances, hence accessing these registers directly */
	} cmp_registers_t;
#else
    typedef struct __attribute__((packed, aligned(4)))
	{
		__CM1CONbits_t           CMxCON;
		volatile unsigned int    CMxCONCLR;
		volatile unsigned int    CMxCONSET;
		volatile unsigned int    CMxCONINV;
	} cmp_registers_t;
#endif


/* Few mask definitions*/
#define CMxCON_ON_MASK         _CM1CON_ON_MASK
#define CMxCON_COE_MASK        _CM1CON_COE_MASK
#define CMxCON_EVPOL_POSITION  _CM1CON_EVPOL_POSITION
#define CMxCON_EVPOL_MASK      _CM1CON_EVPOL_MASK
#define CMxCON_CCH_POSITION    _CM1CON_CCH_POSITION
#define CMxCON_CCH_MASK        _CM1CON_CCH_MASK
#define CMxCON_CPOL_MASK       _CM1CON_CPOL_MASK
#define CMxCON_CREF_POSITION   _CM1CON_CREF_POSITION
#define CMxCON_CREF_MASK       _CM1CON_CREF_MASK
#define CMxCON_COUT_MASK       _CM1CON_COUT_MASK
#define CMxCON_CFLTREN_MASK    _CM1CON_CFLTREN_MASK
#define CMxCON_OAO_MASK        _CM1CON_OAO_MASK
#define CMxCON_AMPMOD_MASK     _CM1CON_AMPMOD_MASK

#endif /*_CMP_STRUCTURE_H*/

/******************************************************************************
 End of File
*/

