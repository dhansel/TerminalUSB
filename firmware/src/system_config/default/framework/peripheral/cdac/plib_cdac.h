/*******************************************************************************
  Control Digital-to-Analog Converter (CDAC) Peripheral Library Interface Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_cdac.h

  Summary:
    CDAC Peripheral Library Interface Header for CDAC common definitions.

  Description:
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the CDAC
    PLIB for all families of Microchip microcontrollers. The definitions in
    this file are common to CDAC peripheral.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2016 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PLIB_CDAC_H
#define _PLIB_CDAC_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued at end of file)
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.  However,
    please see the end of the file for additional implementation header files
    that are also included
 */

#include <stdint.h>
#include <stdbool.h>

// *****************************************************************************
// *****************************************************************************
// Section: Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Include Processor Specific Files
// *****************************************************************************
// *****************************************************************************
#include "peripheral/cdac/processor/cdac_processor.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Helper Macros
// *****************************************************************************
// *****************************************************************************

// ****************************************************************************
// ****************************************************************************
// Section: Interface functions with global to CDAC
// ****************************************************************************
// ****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_CDAC_Enable( CDAC_MODULE_ID index )

  Summary:
    Enables the CDAC module.

  Description:
    This function enables (turns ON) the selected CDAC module. There are
    other CDAC configurations that should be set/selected before the CDAC
	module is turned ON. 

  Precondition:
    None.

  Parameters:
    index      - Identifier for the CDAC instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_CDAC_INSTANCE, is the CDAC instance selected for use by the
    // application developer.
    PLIB_CDAC_Enable(MY_CDAC_INSTANCE);
    </code>

  Remarks:
   The user should wait 'Ton' time, after enabling the module. This time is
   required to allow the CDAC output to stabilize. Refer to the 
   "Electrical Characteristics" chapter in the specific device data sheet for 
   the Ton specification.
 */

void PLIB_CDAC_Enable( CDAC_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_CDAC_Disable( CDAC_MODULE_ID index )

  Summary:
    Disables the CDAC module.

  Description:
    This function disables (turns OFF) the selected CDAC module.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the CDAC instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_CDAC_INSTANCE, is the CDAC instance selected for use by the
    // application developer.
    PLIB_CDAC_Disable(MY_CDAC_INSTANCE);
    </code>

  Remarks:
    If CDAC module is disabled, regardless of the state of the 
	Output Buffer, all analog circuitry is disabled; however the other 
	registers can still be accessed.
 */

void PLIB_CDAC_Disable( CDAC_MODULE_ID index );

//******************************************************************************
/* Function:
   void PLIB_CDAC_OutputEnable( CDAC_MODULE_ID index )

 Summary:
   Enables the CDAC Output.

 Description:
   The output of the CDAC module reaches the pin only if this function is
   called.

 Precondition:
   None.

 Parameters:
   index           - Identifier for the device instance to be configured

 Returns:
   None.

 Example:
   <code>
   // Where MY_CDAC_INSTANCE, is the CDAC instance selected for use by the
   // application developer.
   PLIB_CDAC_OutputEnable(MY_CDAC_INSTANCE, CDAC_OUTPUT1);
   </code>

 Remarks:
    None.
 */

void PLIB_CDAC_OutputEnable( CDAC_MODULE_ID index, CDAC_OUTPUT_SELECTION output );

//******************************************************************************
/* Function:
   void PLIB_CDAC_OutputDisable( CDAC_MODULE_ID index )

 Summary:
   Disables the CDAC Output.

 Description:
   This function disconnects the CDAC output from the pin and the pin goes into
	a high impedance state.

 Precondition:
   None.

 Parameters:
   index           - Identifier for the device instance to be configured
   output          - Output ID

 Returns:
   None.

 Example:
   <code>
   // Where MY_CDAC_INSTANCE, is the CDAC instance selected for use by the
   // application developer.
   PLIB_CDAC_OutputDisable(MY_CDAC_INSTANCE, CDAC_OUTPUT1);
   </code>

 Remarks:
    None.
 */

void PLIB_CDAC_OutputDisable( CDAC_MODULE_ID index, CDAC_OUTPUT_SELECTION output);

//******************************************************************************
/* Function:
    void PLIB_CDAC_ReferenceVoltageSelect ( CDAC_MODULE_ID index,
                                            CDAC_REF_SEL refSel )

  Summary:
    Selects the Reference Voltage that is applied to resistor network.

  Description:
    The user application can specify the voltage source to the resistor network.
    The four possible selections available for the reference voltage are 
	as follows:
    - AVDD: This selection will make the Positive Supply for Analog modules 
	  as reference for internal resistor network
    - 2_4V: 2 times the internal band gap reference, nominally 2.4V will be set
      as reference for internal resistor network 
    - ExtVref: Positive reference voltage, from external VREF+ pin as reference
	  for internal resistor network
    - NoRef: No reference is selected to the resistor network. This can be used
	  to reduce power consumption by CDAC module, when it is not being used.

  Precondition:
    None.

  Parameters:
    index		- Identifier for the device instance to be configured
    refSel		- One of the CDAC_REF_SEL enumeration values as the reference
                  for resistor network.

  Returns:
    None.

  Example:
    <code>
    // Where MY_CDAC_INSTANCE, is the CDAC instance selected for use by the
    // application developer.
    PLIB_CDAC_ReferenceVoltageSelect( MY_CDAC_INSTANCE, CDAC_VREF_AVDD );
    </code>

  Remarks:
    When the module is disabled, this is equivalent to the No Reference Selection.
 */

void PLIB_CDAC_ReferenceVoltageSelect( CDAC_MODULE_ID index, CDAC_REF_SEL refSel );

//******************************************************************************
/* Function:
    void PLIB_CDAC_DataWrite( CDAC_MODULE_ID index, uint16_t cdacData )

  Summary:
    Writes the specified data whose corresponding analog value to be output
	from CDAC.

  Description:
    The CDAC module is based on resistor network. The value available on the
	data function is presented as analog voltage output based on the following
	equation. Since the maximum allowed input is 4095 (12-bit), any higher input
	will be saturated to 4095.
	
	Analog Voltage Output =  ( cdacData/4095 ) * Reference Voltage
	
  Precondition:
    None.

  Input:
    index			- Identifier for the CDAC instance
    cdacDATA -12 bit data which is to be written to the CDAC Data register.
 
  Returns:
    None.

  Example:
    <code>
    // Where MY_CDAC_INSTANCE, is the CDAC instance selected for use by the
    // application developer.   
    uint16_t cdacData = 3000;
    PLIB_CDAC_DataWrite ( MY_CDAC_INSTANCE, cdacData );
    </code>

  Remarks:
    None.
*/

void PLIB_CDAC_DataWrite( CDAC_MODULE_ID index, uint16_t cdacData );

//******************************************************************************
/* Function:
    uint16_t PLIB_CDAC_DataRead( CDAC_MODULE_ID index )

  Summary:
    Returns the data on the CDAC register corresponding to the specified module.

  Description:
    This function returns the CDAC data corresponding to the specified module.
    
  Precondition:
    None.

  Input:
    index			- Identifier for the CDAC instance

  Returns:
    None.

  Example:
    <code>
    // Where MY_CDAC_INSTANCE, is the CDAC instance selected for use by the
    // application developer.   
    uint16_t cdacData;
    cdacData = PLIB_CDAC_DataRead ( MY_CDAC_INSTANCE );
    </code>

  Remarks:
    None.
*/

uint16_t PLIB_CDAC_DataRead( CDAC_MODULE_ID index );

// *****************************************************************************
// *****************************************************************************
// Section: CDAC Peripheral Library Exists API Routines
// *****************************************************************************
// *****************************************************************************

/* The following functions indicate the existence of the features on the device. */

//******************************************************************************
/* Function:
    PLIB_CDAC_ExistsEnableControl( CDAC_MODULE_ID index )

  Summary:
    Identifies whether the EnableControl feature exists on the CDAC module. 

  Description:
    This function identifies whether the EnableControl feature is available on 
    the CDAC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CDAC_Enable
    - PLIB_CDAC_Disable

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the EnableControl feature: 
    - true   - When EnableControl feature is supported on the device
    - false  - When EnableControl feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_CDAC_ExistsEnableControl( CDAC_MODULE_ID index );

//******************************************************************************
/* Function:
    PLIB_CDAC_ExistsOutputControl( CDAC_MODULE_ID index )

  Summary:
    Identifies whether the OutputControl feature exists on the CDAC module. 

  Description:
    This function identifies whether the OutputControl feature is available on the 
    CDAC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CDAC_OutputEnable
    - PLIB_CDAC_OutputDisable

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the OutputControl feature: 
    - true   - When OutputControl feature is supported on the device
    - false  - When OutputControl feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_CDAC_ExistsOutputControl( CDAC_MODULE_ID index );

//******************************************************************************
/* Function:
    PLIB_CDAC_ExistsReferenceVoltageSelect( CDAC_MODULE_ID index )

  Summary:
    Identifies whether the ReferenceVoltageSelect feature exists on the CDAC 
    module. 

  Description:
    This function identifies whether the ReferenceVoltageSelect feature is 
    available on the CDAC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_CDAC_ReferenceVoltageSelect

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the ReferenceVoltageSelect feature: 
    - true   - When ReferenceVoltageSelect feature is supported on the device
    - false  - When ReferenceVoltageSelect feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_CDAC_ExistsReferenceVoltageSelect( CDAC_MODULE_ID index );

//******************************************************************************
/* Function:
    PLIB_CDAC_ExistsDataControl( CDAC_MODULE_ID index )

  Summary:
    Identifies whether the DataControl feature exists on the CDAC 
    module.

  Summary:
    Implements pic32 variant of PLIB_CDAC_ExistsDataControl

  Description:
    This template implements the pic32 variant of the PLIB_CDAC_ExistsDataControl function.
 */

bool PLIB_CDAC_ExistsDataControl( CDAC_MODULE_ID index );

#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif
