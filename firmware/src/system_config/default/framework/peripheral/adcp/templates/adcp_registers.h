/*******************************************************************************
  ADCP Peripheral Library structure implementation

  File Name:
    adcp_registers.h

  Summary:
    ADCP PLIB base structure implementation

  Description:
    This header file contains instance structure for ADCP PLIB module.

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

#ifndef _ADCP_STRUCTURE_H
#define _ADCP_STRUCTURE_H

/* This is the register set structure of ADCP module */
typedef struct __attribute__((packed, aligned(4)))
{
    __AD1CON1bits_t			 ADxCON1;
    __AD1CON2bits_t    		 ADxCON2;
	__AD1CON3bits_t    		 ADxCON3;
	__AD1IMODbits_t    		 ADxIMOD;
	volatile unsigned int    ADxGIRQEN1;
	volatile unsigned int    ADxGIRQEN2;
	volatile unsigned int    ADxCSS1;
	volatile unsigned int    ADxCSS2;
	volatile unsigned int    ADxDSTAT1;
	volatile unsigned int    ADxDSTAT2;
    
	struct 
	{
		volatile unsigned int    ADxCMPENx;
	    __AD1CMP1bits_t          ADxCMPx;
	} ADCCMPx[6];
    
	__AD1FLTR1bits_t	     ADxFLTR[6];
	__AD1TRG1bits_t	         ADxTRG[3];
	volatile unsigned int    offset1[5];
	__AD1CMPCON1bits_t	  	 ADxCMPCON[6];
	volatile unsigned int    offset2[4];
	volatile unsigned int    ADxDATA[45];
	volatile unsigned int    offset3[37];
	volatile unsigned int	 ADxCAL[5];
} adcp_registers_t;

/* Few mask definitions*/
#define    ADxTRG1_TRGSRC1_POSITION    _AD1TRG1_TRGSRC1_POSITION
#define    ADxTRG1_TRGSRC0_MASK	       _AD1TRG1_TRGSRC0_MASK

#define    ADxIMOD_SH0MOD_POSITION     _AD1IMOD_SH0MOD_POSITION         
#define    ADxIMOD_SH0MOD_MASK         _AD1IMOD_SH0MOD_MASK                  
#define    ADxIMOD_SH0MOD_LENGTH	   _AD1IMOD_SH0MOD_LENGTH

#define    ADxIMOD_SH0ALT_POSITION     _AD1IMOD_SH0ALT_POSITION        
#define    ADxIMOD_SH0ALT_MASK    	   _AD1IMOD_SH0ALT_MASK
#define    ADxIMOD_SH0ALT_LENGTH       _AD1IMOD_SH0ALT_LENGTH 

#define    ADxCMPCONx_IELOLO_POSITION      _AD1CMPCON1_IELOLO_POSITION 
#define    ADxCMPCONx_IELOLO_MASK          _AD1CMPCON1_IELOLO_MASK 

#define    ADxCMPCONx_IELOHI_POSITION      _AD1CMPCON1_IELOHI_POSITION 
#define    ADxCMPCONx_IELOHI_MASK          _AD1CMPCON1_IELOHI_MASK 

#define    ADxCMPCONx_IEHILO_POSITION      _AD1CMPCON1_IEHILO_POSITION 
#define    ADxCMPCONx_IEHILO_MASK          _AD1CMPCON1_IEHILO_MASK

#define    ADxCMPCONx_IEHIHI_POSITION      _AD1CMPCON1_IEHIHI_POSITION 
#define    ADxCMPCONx_IEHIHI_MASK          _AD1CMPCON1_IEHIHI_MASK

#define    ADxCMPCONx_IEBTWN_POSITION      _AD1CMPCON1_IEBTWN_POSITION 
#define    ADxCMPCONx_IEBTWN_MASK          _AD1CMPCON1_IEBTWN_MASK

#define    ADxCMPCONx_DCMPGIEN_POSITION    _AD1CMPCON1_DCMPGIEN_POSITION 
#define    ADxCMPCONx_DCMPGIEN_MASK        _AD1CMPCON1_DCMPGIEN_MASK


#endif /*_ADCP_STRUCTURE_H*/

/******************************************************************************
 End of File
*/

