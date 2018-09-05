/*******************************************************************************
  Comparator Peripheral Library Interface Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_cmp.h

  Summary:
    Comparator Peripheral Library Interface Header for Comparator module definitions.

  Description:
    This header file contains the function prototypes and definitions of the
    data types and constants that make up the interface to the Comparator
    Peripheral Library for all families of Microchip microcontrollers. The
    definitions in this file are common to the Comparator peripheral.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2015 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PLIB_CMP_H
#define _PLIB_CMP_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued at end of file)
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.  However,
    please see the end of the file for additional implementation header files
    that are also included
*/

#include "peripheral/cmp/processor/cmp_processor.h"

// *****************************************************************************
// *****************************************************************************
// Section: Comparator Voltage Reference Configuration
// *****************************************************************************
// *****************************************************************************

//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_Enable ( CMP_CVREF_MOD index )

 Summary:
   Enables the voltage reference of the Comparator module.

 Description:
   This function enables the voltage reference of the Comparator module.

 Precondition:
   The Comparator module should be appropriately configured before being enabled.

 Parameters:
   index    - Identifier for the device instance to be configured

 Returns:
   None.

 Example:
   <code>
    PLIB_CMP_CVREF_Enable ( CMP_ID_1 );
   </code>

 Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_CVREF_ExistsCVREFEnableControl
	in your application to determine whether this feature is available.
 */

void PLIB_CMP_CVREF_Enable ( CMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_Disable ( CMP_MODULE_ID index )

  Summary:
    Disables the voltage reference of the Comparator module.

  Description:
    This function disables the voltage reference of the Comparator module.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_Disable ( CMP_ID_1 );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_CVREF_ExistsCVREFEnableControl
	in your application to determine whether this feature is available.
 */

void PLIB_CMP_CVREF_Disable ( CMP_MODULE_ID index );


//******************************************************************************
/*  Function:
    void PLIB_CMP_CVREF_OutputEnable ( CMP_MODULE_ID index )

  Summary:
    Enables the voltage output.

  Description:
    This function enables the voltage output

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_OutputEnable(CMP_ID_1);
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_CVREF_ExistsCVREFOutputEnableControl
	in your application to determine whether this feature is available.

 */

void PLIB_CMP_CVREF_OutputEnable(CMP_MODULE_ID index);


//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_OutputDisable ( CMP_MODULE_ID index )

  Summary:
    Disables the output voltage.

  Description:
    This function disables the reference voltage output.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_OutputDisable ( CMP_ID_1 );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_CVREF_ExistsCVREFOutputEnableControl
	in your application to determine whether this feature is available.
 */

void PLIB_CMP_CVREF_OutputDisable ( CMP_MODULE_ID index );


// *****************************************************************************
// *****************************************************************************
// Section: Comparator Voltage Reference- External Voltage Reference
// *****************************************************************************
// *****************************************************************************

//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_ReferenceVoltageSelect ( CMP_MODULE_ID index,
        CMP_CVREF_REFERENCE_SELECT reference );

  Summary:
    Selects the voltage reference value, CVref.

  Description:
    This function selects the voltage reference value, CVref. This value decides which 
	voltage source should be taken as reference voltage from the 
	set CMP_CVREF_REFERENCE_SELECT.

  Precondition:
    Determine the correct value that should be passed.

  Parameters:
    index    - Identifier for the device instance to be configured
    value    - Select value from CMP_CVREF_REFERENCE_SELECT

  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_ReferenceVoltageSelect ( CMP_ID_1,  CMP_CVREF_RESISTOR_LADDER_VOLTAGE );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsCVREFRefVoltageRangeSelect
    in your application to determine whether this feature is available.
*/

void PLIB_CMP_CVREF_ReferenceVoltageSelect ( CMP_MODULE_ID index, CMP_CVREF_REFERENCE_SELECT reference );


//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_SourceVoltageSelect ( CMP_MODULE_ID index, CMP_CVREF_VOLTAGE_SOURCE source )

  Summary:
    Connects the Comparator module to the selected voltage source.

  Description:
    This function connects the Comparator module to the selected voltage source.
	
  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured
    source   - Select the voltage source from CMP_CVREF_VOLTAGE_SOURCE

  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_SourceVoltageSelect ( CMP_ID_1, CMP_CVREF_VOLTAGE_SOURCE_INTERNAL );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_CVREF_ExistsCVREFVoltageRangeSelect in your application
	to determine whether this feature is available.
 */

void PLIB_CMP_CVREF_SourceVoltageSelect ( CMP_MODULE_ID index, CMP_CVREF_VOLTAGE_SOURCE source );


//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_SourceNegativeInputSelect ( CMP_MODULE_ID index,
									CMP_CVREF_VOLTAGE_SOURCE_NEG_REFERENCE negInput )

  Summary:
    Configures the Comparator module to use the selected input as a negative reference.

  Description:
    This function configures the Comparator module to use the selected input as a negative
    reference for the voltage source.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured
    negInput - Select the voltage source negative reference from
			   CMP_CVREF_VOLTAGE_SOURCE_NEG_REFERENCE
  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_SourceNegativeInputSelect ( CMP_ID_1, CMP_CVREF_VOLTAGE_SOURCE_NEG_REF_GROUND );
    </code>

  Remarks:
    This feature is not available on all devices.  Please refer to the
    specific device data sheet for availability. For such devices, selecting
    the positive source will automatically select the negative input.
 */

void PLIB_CMP_CVREF_SourceNegativeInputSelect ( CMP_MODULE_ID index,
								CMP_CVREF_VOLTAGE_SOURCE_NEG_REFERENCE negInput );


//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_WideRangeEnable ( CMP_MODULE_ID index )

  Summary:
    Enables the wide range.

  Description:
    This function enables the wide range for reference voltage. The voltage range starts
    from zero if the wide range is selected.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_WideRangeEnable(CMP_ID_1);
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_CVREF_ExistsCVREFWideRangeControl
	in your application to determine whether this feature is available.
 */

void PLIB_CMP_CVREF_WideRangeEnable ( CMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_WideRangeDisable ( CMP_MODULE_ID index )

  Summary:
    Disables the wide range.

  Description:
    This function disables the wide range for reference voltage. The range of possible
    voltages will become narrower, and finer voltage options can be achieved
    in this case.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_WideRangeDisable ( CMP_ID_1 );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_CVREF_ExistsCVREFWideRangeControl
	in your application to determine whether this feature is available.
 */

void PLIB_CMP_CVREF_WideRangeDisable ( CMP_MODULE_ID index );


//******************************************************************************
/* Function:
    bool PLIB_CMP_CVREF_WideRangeIsEnabled ( CMP_MODULE_ID index );

  Summary:
    Returns whether the wide range is selected for the reference voltage.

  Description:
    This function returns whether the wide range is enabled.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    - true  = The wide range is enabled
    - false = The wide range is not enabled

  Example:
    <code>
    bool range;

    range = PLIB_CMP_CVREF_WideRangeIsEnabled ( MY_CMP_CVREF_ID );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_CVREF_ExistsCVREFWideRangeControl
	in your application to determine whether this feature is available.
 */

bool PLIB_CMP_CVREF_WideRangeIsEnabled ( CMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_ValueSelect ( CMP_MODULE_ID index,
        CMP_CVREF_VALUE value );

  Summary:
    Selects the voltage reference value.

  Description:
    This function selects the voltage reference value. This value decides how
    many resistance units will be added and therefore, decides the output voltage.

  Precondition:
    Determine the correct value that should be passed.

  Parameters:
    index    - Identifier for the device instance to be configured
    value    - Select value from CMP_CVREF_VALUE

  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_ValueSelect ( CMP_ID_1,  CMP_CVREF_VALUE_13 );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_CVREF_ExistsCVREFValueSelect
	in your application to determine whether this feature is available.
 */

void PLIB_CMP_CVREF_ValueSelect ( CMP_MODULE_ID index, CMP_CVREF_VALUE value );


//******************************************************************************
/* Function:
    void PLIB_CMP_CVREF_BandGapReferenceSourceSelect ( CMP_MODULE_ID index,
        CMP_CVREF_BANDGAP_SELECT bandGap );

  Summary:
    Selects the band gap reference voltage source.

  Description:
    This function selects the band gap reference voltage source from the
    available options from CMP_CVREF_BANDGAP_SELECT.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured
    select   - Select a band gap reference source from CMP_CVREF_BANDGAP_SELECT

  Returns:
    None.

  Example:
    <code>
    PLIB_CMP_CVREF_BandGapReferenceSourceSelect ( CMP_ID_1,  CMP_CVREF_BANDGAP_0_6V );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsCVREFBGRefVoltageRangeSelect
	in your application to determine whether this feature is available.
*/
void PLIB_CMP_CVREF_BandGapReferenceSourceSelect ( CMP_MODULE_ID index,
											CMP_CVREF_BANDGAP_SELECT select );


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Comparator Control
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_CMP_Enable ( CMP_MODULE_ID index )

  Summary:
    Enables the Comparator module.

  Description:
    This function enables (turns ON) the selected Comparator module.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_Enable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsEnableControl
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_Enable ( CMP_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CMP_Disable ( CMP_MODULE_ID index )

  Summary:
    Disables the Comparator module.

  Description:
    This function disables (turns OFF) the selected Comparator module.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_Disable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsEnableControl
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_Disable ( CMP_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CMP_OutputEnable ( CMP_MODULE_ID index )

  Summary:
    Enables the Comparator output.

  Description:
    This function enables (turns ON) the Comparator output.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_OutputEnable( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsOutputEnableControl
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_OutputEnable ( CMP_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CMP_OutputDisable ( CMP_MODULE_ID index )

  Summary:
    Disables the Comparator output.

  Description:
    This function disables (turns OFF) the Comparator output.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_OutputDisable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsOutputEnableControl
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_OutputDisable ( CMP_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CMP_OutputInvertEnable (CMP_MODULE_ID index)

  Summary:
    Comparator output is inverted.

  Description:
    Calling this function will set the comparator to make its output inverted.

  Precondition:
    None.

  Parameters:
    index     - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_OutputDisable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsOutputEnableControlExistsInvertOutputControl
	in your application to determine whether this feature is
    available.

	Setting this bit will invert the signal to the comparator interrupt generator
	as well. This will result in an interrupt being generated on the opposite edge
	from the one selected by PLIB_CMP_InterruptEventSelect function.
*/

void PLIB_CMP_OutputInvertEnable (CMP_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_CMP_OutputInvertDisable ( CMP_MODULE_ID index )

  Summary:
    Comparator output is non-inverted.

  Description:
    This function will select the non-inverted comparator output.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_OutputInvertDisable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsOutputEnableControlExistsInvertOutputControl
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_OutputInvertDisable ( CMP_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_CMP_InterruptEventSelect ( CMP_MODULE_ID index, CMP_INTERRUPT_EVENT event )

  Summary:
    Comparator interrupt event select.

  Description:
    This function will select when the Comparator interrupt should occur.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    event           - One of the possible values from CMP_INTERRUPT_EVENT

  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    // CMP_INTERRUPT_EVENT - CMP_LOW_TO_HIGH
    PLIB_CMP_InterruptEventSelect ( MY_CMP_INSTANCE,
    						CMP_INTERRUPT_GENERATION_LOW_TO_HIGH );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsInterruptEventSelect
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_InterruptEventSelect ( CMP_MODULE_ID index, CMP_INTERRUPT_EVENT event );


// *****************************************************************************
/* Function:
    void PLIB_CMP_InvertingInputChannelSelect ( CMP_MODULE_ID index,
												CMP_INVERTING_INPUT channel )

  Summary:
    Comparator inverting input channel select.

  Description:
    This function will select the inverting input channels for the Comparator.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    channel         - One of the possible values from CMP_INVERTING_INPUT
	
  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
     PLIB_CMP_InvertingInputChannelSelect ( MY_CMP_INSTANCE,
								CMP_INVERTING_INPUT_IVREF );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsInvertingInputSelect
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_InvertingInputChannelSelect ( CMP_MODULE_ID index, CMP_INVERTING_INPUT channel );


// *****************************************************************************
/* Function:
    void PLIB_CMP_NonInvertingInputChannelSelect ( CMP_MODULE_ID index,
											CMP_NON_INVERTING_INPUT input )

  Summary:
    Comparator input channel select.

  Description:
    This function will select the non-inverting input channels for the Comparator.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    channel         - One of the possible values from CMP_NON_INVERTING_INPUT
	
  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_NonInvertingInputChannelSelect ( MY_CMP_INSTANCE, CMP_NON_INVERTING_INPUT_CVREF );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsNonInvertingInputSelect
	in your application to determine whether this feature is
    available.s
*/

void PLIB_CMP_NonInvertingInputChannelSelect ( CMP_MODULE_ID index,
												CMP_NON_INVERTING_INPUT input );


// *****************************************************************************
/* Function:
    void PLIB_CMP_StopInIdleModeEnable ( CMP_MODULE_ID index )

  Summary:
    Enables Stop in Idle mode.

  Description:
    This function will discontinue operation of all comparators when the device
	enters Idle mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_StopInIdleModeEnable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsStopInIdle
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_StopInIdleModeEnable ( CMP_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CMP_StopInIdleModeDisable ( CMP_MODULE_ID index )

  Summary:
    Disables Stop in Idle mode.

  Description:
    This function will continue operation of all enabled comparators when the
	device enters Idle mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
	#define MY_CMP_INSTANCE   CMP_ID_1

    // Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_StopInIdleModeDisable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsStopInIdle
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_StopInIdleModeDisable ( CMP_MODULE_ID index );


// *****************************************************************************
/* Function:
   bool PLIB_CMP_OutputStatusGet ( CMP_MODULE_ID index )

 Summary:
   Comparator output status.

 Description:
   This function will return the current status of the Comparator output.

 Precondition:
   None.

 Parameters:
   index           - Identifier for the device instance to be configured

 Returns:
   - true  - The status flag is set
   - false - The status flag is clear

 Example:
   <code>
	#define MY_CMP_INSTANCE   CMP_ID_1
	bool cmp_status;

	// Where MY_CMP_INSTANCE, is the Comparator instance selected for use by the
	// application developer.
   cmp_status=PLIB_CMP_OutputStatusGet ( MY_CMP_INSTANCE );
   </code>

 Remarks:
   This feature is not available on all devices. Please refer to the
   specific device data sheet for availability.
*/

bool PLIB_CMP_OutputStatusGet ( CMP_MODULE_ID index );


// *****************************************************************************
/* Function:
   bool PLIB_CMP_ComparatorEventStatusGet ( CMP_MODULE_ID index);

 Summary:
    Returns comparator event status.

 Description:
    This function will return the current event status of the Comparator output.
    This operation is atomic.

 Precondition:
    None.

 Parameters:
    index    - Identifier for the device instance to be configured

 Returns:
    true  - The Comparator event has occurred
    false - The Comparator event did not occur

 Example:
    <code>
    bool eventStatus;

    // Where MY_CMP_INSTANCE is the Comparator instance selected for use by the
    // application developer.
    eventStatus = PLIB_CMP_ComparatorEventStatusGet ( MY_CMP_INSTANCE );
    </code>

 Remarks:
    This feature may not be available on all devices.
    Please refer to the specific device data sheet to determine
    availability or use PLIB_CMP_ExistsComparatorEventStatusGet
    in your application to determine whether this feature is
    available.
*/

bool PLIB_CMP_ComparatorEventStatusGet ( CMP_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_CMP_ComparatorOutputDigitalFilterEnable ( CMP_MODULE_ID index);

  Summary:
    Enables Digital Filter on comparator output.

  Description:
    This function enables the Comparator's Digital Filter functionality.
    This operation is atomic.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_CMP_INSTANCE is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_ComparatorOutputDigitalFilterEnable( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
    Please refer to the specific device data sheet to determine
    availability or use PLIB_CMP_ExistsComparatorOutputDigitalFilter
    in your application to determine whether this feature is
    available.

*/

void PLIB_CMP_ComparatorOutputDigitalFilterEnable ( CMP_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_CMP_ComparatorOutputDigitalFilterDisable ( CMP_MODULE_ID index);

  Summary:
    Disables Digital Filter on comparator output.

  Description:
    This function disables the Comparator's Digital Filter functionality.
    This operation is atomic.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_CMP_INSTANCE is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_ComparatorOutputDigitalFilterDisable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
    Please refer to the specific device data sheet to determine
    availability or use PLIB_CMP_ExistsComparatorOutputDigitalFilter
    in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_ComparatorOutputDigitalFilterDisable ( CMP_MODULE_ID index);

// *****************************************************************************
/* Function:
    void PLIB_CMP_ComparatorOutputDigitalFilterClkSetup 
    (
        CMP_MODULE_ID index,
        CMP_OUTPUT_FILTER_CLK_SOURCE clkSource,
        CMP_OUTPUT_FILTER_CLK_DIV clkDivider 
    )

  Summary:
    Configures the Comparator Output Digital Filter clock.

  Description:
    This function sets the clock source and clock divide options for the
    Digital Filter of the comparator.

  Precondition:
    None.

  Parameters:
    index      - Identifier for the device instance to be configured
    clkSource  - One of the possible clock sources for Digital Filter
    clkDivider - Selects a clock divide ratio for Digital Filter

  Returns:
    None.

  Example:
    <code>
    // Where MY_CMP_INSTANCE is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_ComparatorOutputDigitalFilterClkSetup ( MY_CMP_INSTANCE,
                                          CMP_OUTPUT_FILTER_CLK_SYSCLK,
                                          CMP_OUTPUT_FILTER_CLK_DIV_8 );
    </code>

  Remarks:
    This feature may not be available on all devices.
    Please refer to the specific device data sheet to determine
    availability or use PLIB_CMP_ExistsComparatorOutputDigitalFilter
    in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_ComparatorOutputDigitalFilterClkSetup 
(
    CMP_MODULE_ID index,
    CMP_OUTPUT_FILTER_CLK_SOURCE clkSource,
    CMP_OUTPUT_FILTER_CLK_DIV clkDivider 
);


// *****************************************************************************
/* Function:
    void PLIB_CMP_OpAmpOutputEnable ( CMP_MODULE_ID index)

  Summary:
    Enables the Op-Amp output on the device physical pin.

  Description:
    This function enables the op-amp output. By calling this
    function, the output of the op-amp is available on a physical pin(OAxOUT)
    of the device.
    This operation is atomic.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_CMP_INSTANCE is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_OpAmpOutputEnable( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
    Please refer to the specific device data sheet to determine
    availability or use PLIB_CMP_ExistsOpAmpOutputControl
    in your application to determine whether this feature is
    available.

*/

void PLIB_CMP_OpAmpOutputEnable ( CMP_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_CMP_OpAmpOutputDisable ( CMP_MODULE_ID index)

  Summary:
    Disables the op-amp output on physical pin.

  Description:
    This function disables the Op-Amp output. By calling this
    function, the output of the op-amp is no longer available on the physical 
    pin(OAxOUT)of the device.
    This operation is atomic.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_CMP_INSTANCE is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_OpAmpOutputDisable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    This feature may not be available on all devices.
    Please refer to the specific device data sheet to determine
    availability or use PLIB_CMP_ExistsOpAmpOutputControl
    in your application to determine whether this feature is
    available.

*/

void PLIB_CMP_OpAmpOutputDisable ( CMP_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_CMP_OpAmpEnable ( CMP_MODULE_ID index)

  Summary:
    Enables the Op-Amp mode.

  Description:
    This function enables the Op-Amp mode of the comparator module.
    This operation is atomic.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_CMP_INSTANCE is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_OpAmpEnable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    Note: This feature may not be available on all comparator modules/devices.
    Please refer to the specific device data sheet to determine
    availability or use PLIB_CMP_ExistsOpAmpEnableControl in your application
    to determine whether this feature is available.
*/

void PLIB_CMP_OpAmpEnable ( CMP_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_CMP_OpAmpDisable ( CMP_MODULE_ID index)

  Summary:
    Disables the Op-Amp mode.

  Description:
    This function disables the Op-Amp mode of the comparator module.
    This operation is atomic.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_CMP_INSTANCE is the Comparator instance selected for use by the
    // application developer.
    PLIB_CMP_OpAmpDisable ( MY_CMP_INSTANCE );
    </code>

  Remarks:
    Note: This feature may not be available on all comparator modules/devices.
    Please refer to the specific device data sheet to determine
    availability or use PLIB_CMP_ExistsOpAmpEnableControl in your application
    to determine whether this feature is available.
*/

void PLIB_CMP_OpAmpDisable ( CMP_MODULE_ID index);

// *****************************************************************************
/* Function:
void PLIB_CMP_ComparatorOutputMaskingSetup ( CMP_MODULE_ID index , 
											 CMP_OUTPUT_MASK_SOURCE sourceA , 
											 CMP_OUTPUT_MASK_SOURCE sourceB , CMP_OUTPUT_MASK_SOURCE sourceC , 
											 uint32_t logicSettings ,
											 CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGatePositiveOutput,
											 CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGateNegativeOutput,
											 CMP_OUTPUT_MASKING_LEVEL maskingLevels);

  Summary:
    Configures the Comparator Output masking/blanking function.

  Description:
    This function sets the blanking input sources and configures the logic for the
	programmable Blanking function of the Output of comparator.

  Precondition:
    None.

  Parameters:
	sourceX   - Selects one of the possible input sources for Masking from CMP_OUTPUT_MASK_SOURCE
	logicSettings - Logic OR of all required AND/OR settings from 
					CMP_MASK_ANDOR_LOGIC
    andGatePositiveOutput - Non inverted AND gate output connection listed by 
                    CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT
    andGateNegativeOutput - Inverted AND gate output connection listed by 
                    CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT
	maskingLevel - Masking level as required and enumerated by  
					CMP_OUTPUT_MASKING_LEVEL
	
  Returns:
    None.

  Example:
    uint32_t cmp2_logicSetting, cmp2_logicOuput = 0;
	
	<code>
	// CMP_OUTPUT_MASK_SOURCE - CMP_CMP_OUTPUT_MASK_PWM3H
	cmp2_logicSetting = ((CMP_OUTPUT_MASK_A_AND_GATE_INPUT_INV) | \
						   (CMP_OUTPUT_MASK_B_AND_GATE_INPUT_INV ));
	//CMP_OUTPUT_MASKING_LEVEL - CMP_OUTPUT_MASKING_HIGH_LEVEL;
    //CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT - CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_ENABLED
    //CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT - CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_DISABLED
	
    PLIB_CMP_ComparatorOutputMaskingSetup ( CMP_ID_0 , 
											 CMP_CMP_OUTPUT_MASK_PWM3H , 
											 CMP_CMP_OUTPUT_MASK_PWM6H , 0x0 , 
											 uint32_t logicSettings ,
											 CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGatePositiveOutput,
											 CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGateNegativeOutput,
											 CMP_OUTPUT_MASKING_LEVEL maskingLevels);
											 
    </code>

  Remarks:
    Note: This feature may not be available on all devices.
	Please refer to the specific device data sheet to determine
	availability or use PLIB_CMP_ExistsComparatorOutputMasking
	in your application to determine whether this feature is
    available.
*/

void PLIB_CMP_ComparatorOutputMaskingSetup ( CMP_MODULE_ID index , 
											 CMP_OUTPUT_MASK_SOURCE sourceA , 
											 CMP_OUTPUT_MASK_SOURCE sourceB , CMP_OUTPUT_MASK_SOURCE sourceC , 
											 uint32_t logicSettings ,
											 CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGatePositiveOutput,
											 CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGateNegativeOutput,
											 CMP_OUTPUT_MASKING_LEVEL maskingLevels);


// *****************************************************************************
// *****************************************************************************
// Section: CMP Peripheral Library Exists API Routines
// *****************************************************************************
// *****************************************************************************
/* The functions below indicate the existence of the features on the device.
*/

//******************************************************************************
/* Function :  PLIB_CMP_ExistsEnableControl( CMP_MODULE_ID index )

  Summary:
    Identifies whether the ComparatorEnableControl feature exists on the CMP module.

  Description:
    This function identifies whether the ComparatorEnableControl feature is available 
	on the CMP module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_Enable
    - PLIB_CMP_Disable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ComparatorEnableControl feature is supported on the device
    - false  - The ComparatorEnableControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsEnableControl( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsOutputEnableControl( CMP_MODULE_ID index )

  Summary:
    Identifies whether the ComparatorOutputEnableControl feature exists on the 
	CMP module.

  Description:
    This function identifies whether the ComparatorOutputEnableControl feature is 
	available on the CMP module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_OutputEnable
    - PLIB_CMP_OutputDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ComparatorOutputEnableControl feature is supported on the device
    - false  - The ComparatorOutputEnableControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsOutputEnableControl( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsInvertOutputControl( CMP_MODULE_ID index )

  Summary:
    Identifies whether the InvertOutputSelectControl feature exists on the 
	CMP module.

  Description:
    This function identifies whether the InvertOutputSelectControl feature is available 
	on the CMP module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_OutputInvertEnable
    - PLIB_CMP_OutputInvertDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The InvertOutputSelectControl feature is supported on the device
    - false  - The InvertOutputSelectControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsInvertOutputControl( CMP_MODULE_ID index );

//******************************************************************************
/* Function :  PLIB_CMP_ExistsOutputStatusGet( CMP_MODULE_ID index )

  Summary:
    Identifies whether the OutputStatusGet feature exists on the CMP module.

  Description:
    This function identifies whether the OutputStatusGet feature is available on 
	the CMP module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_OutputStatusGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The OutputStatusGet feature is supported on the device
    - false  - The OutputStatusGet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsOutputStatusGet( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsInterruptEventSelect( CMP_MODULE_ID index )

  Summary:
    Identifies whether the InterruptEventSelect feature exists on the CMP module.

  Description:
    This function identifies whether the InterruptEventSelect feature is available 
	on the CMP module.
    When this function returns true, this function is supported on the device:
    - PLIB_CMP_InterruptEventSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The InterruptEventSelect feature is supported on the device
    - false  - The InterruptEventSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsInterruptEventSelect( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsNonInvertingInputSelect( CMP_MODULE_ID index )

  Summary:
    Identifies whether the NonInvertingInputSelect feature exists on the CMP module.

  Description:
    This function identifies whether the NonInvertingInputSelect feature is 
	available on the CMP module.
    When this function returns true, this function is supported on the device:
    - PLIB_CMP_NonInvertingInputChannelSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The NonInvertingInputSelect feature is supported on the device
    - false  - The NonInvertingInputSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsNonInvertingInputSelect( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsInvertingInputSelect( CMP_MODULE_ID index )

  Summary:
    Identifies whether the InvertingInputSelect feature exists on the CMP module.

  Description:
    This function identifies whether the InvertingInputSelect feature is available 
	on the CMP module.
    When this function returns true, this function is supported on the device:
    - PLIB_CMP_InvertingInputChannelSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The InvertingInputSelect feature is supported on the device
    - false  - The InvertingInputSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsInvertingInputSelect( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsStopInIdle( CMP_MODULE_ID index )

  Summary:
    Identifies whether the StopInIdle feature exists on the CMP module.

  Description:
    This function identifies whether the StopInIdle feature is available on the 
	CMP module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_StopInIdleModeEnable
    - PLIB_CMP_StopInIdleModeDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The StopInIdle feature is supported on the device
    - false  - The StopInIdle feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsStopInIdle( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsCVREFEnableControl( CMP_MODULE_ID index )

  Summary:
    Identifies whether the CVREFEnableControl feature exists on the CMP module.

  Description:
    This function identifies whether the CVREFEnableControl feature is available 
	on the CMP module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_CVREF_Enable
    - PLIB_CMP_CVREF_Disable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CVREFEnableControl feature is supported on the device
    - false  - The CVREFEnableControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsCVREFEnableControl( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsCVREFOutputEnableControl( CMP_MODULE_ID index )

  Summary:
    Identifies whether the CVREFOutputEnableControl feature exists on the CMP module.

  Description:
    This function identifies whether the CVREFOutputEnableControl feature is 
	available on the CMP module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_CVREF_OutputEnable
    - PLIB_CMP_CVREF_OutputDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CVREFOutputEnableControl feature is supported on the device
    - false  - The CVREFOutputEnableControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsCVREFOutputEnableControl( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsCVREFWideRangeControl( CMP_MODULE_ID index )

  Summary:
    Identifies whether the CVREFWideRangeControl feature exists on the CMP module.

  Description:
    This function identifies whether the CVREFWideRangeControl feature is available 
	on the CMP module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_CVREF_WideRangeEnable
    - PLIB_CMP_CVREF_WideRangeDisable
    - PLIB_CMP_CVREF_WideRangeIsEnabled

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CVREFWideRangeControl feature is supported on the device
    - false  - The CVREFWideRangeControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsCVREFWideRangeControl( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsCVREFVoltageRangeSelect( CMP_MODULE_ID index )

  Summary:
    Identifies whether the CVREFVoltageRangeSelect feature exists on the CMP module.

  Description:
    This function identifies whether the CVREFVoltageRangeSelect feature is available 
	on the CMP module.
    When this function returns true, this function is supported on the device:
    - PLIB_CMP_CVREF_SourceVoltageSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CVREFVoltageRangeSelect feature is supported on the device
    - false  - The CVREFVoltageRangeSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsCVREFVoltageRangeSelect( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsCVREFRefVoltageRangeSelect( CMP_MODULE_ID index )

  Summary:
    Identifies whether the CVREFRefVoltageRangeSelect feature exists on the CMP 
	module.

  Description:
    This function identifies whether the CVREFRefVoltageRangeSelect feature is 
	available on the CMP module.
    When this function returns true, this function is supported on the device:
    - PLIB_CMP_CVREF_ReferenceVoltageSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CVREFRefVoltageRangeSelect feature is supported on the device
    - false  - The CVREFRefVoltageRangeSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsCVREFRefVoltageRangeSelect( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsCVREFBGRefVoltageRangeSelect( CMP_MODULE_ID index )

  Summary:
    Identifies whether the CVREFBGRefVoltageRangeSelect feature exists on the 
	CMP module.

  Description:
    This function identifies whether the CVREFBGRefVoltageRangeSelect feature 
	is available on the CMP module.
    When this function returns true, this function is supported on the device:
    - PLIB_CMP_CVREF_BandGapReferenceSourceSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CVREFBGRefVoltageRangeSelect feature is supported on the device
    - false  - The CVREFBGRefVoltageRangeSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsCVREFBGRefVoltageRangeSelect( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsCVREFValueSelect( CMP_MODULE_ID index )

  Summary:
    Identifies whether the CVREFValueSelect feature exists on the CMP module.

  Description:
    This function identifies whether the CVREFValueSelect feature is available 
	on the CMP module.
    When this function returns true, this function is supported on the device:
    - PLIB_CMP_CVREF_ValueSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CVREFValueSelect feature is supported on the device
    - false  - The CVREFValueSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsCVREFValueSelect( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsComparatorEventStatusGet( CMP_MODULE_ID index )

  Summary:
    Identifies whether the Comparator Event Status feature exists on the 
    Op-Amp/Comparator module.

  Description:
    This function identifies whether the Comparator Event feature is available on
    the module.
    When this function returns true, the following function is supported on the
    device:
    - PLIB_CMP_ComparatorEventStatusGet

  Preconditions:
    None.

  Parameters:
    None.

  Returns:
    - true   - The ComparatorEventStatus feature is supported on the device
    - false  - The ComparatorEventStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsComparatorEventStatusGet( CMP_MODULE_ID index );


//******************************************************************************
/* Function : PLIB_CMP_ExistsComparatorOutputDigitalFilter( CMP_MODULE_ID index )

  Summary:
    Identifies whether the digital filter feature exists on the Op-Amp/Comparator
    module.

  Description:
    This function identifies whether the Digital Filter feature is available on 
    the module.
    When this function returns true, the following functions are supported on the
    device:
    - PLIB_CMP_ComparatorOutputDigitalFilterClkSetup
    - PLIB_CMP_ComparatorOutputDigitalFilterEnable
    - PLIB_CMP_ComparatorOutputDigitalFilterDisable 

  Preconditions:
    None.

  Parameters:
    None.

  Returns:
    - true   - The digital filter feature is supported on the device
    - false  - The digital filter feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsComparatorOutputDigitalFilter( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsOpAmpOutputControl( CMP_MODULE_ID index )

  Summary:
    Identifies whether the OpAmpOutputControl feature exists on the
    CMP module.

  Description:
    This function identifies whether the OpAmpOutputControl feature is
    available on the CMP module.
    When this function returns true, the following functions are supported on the
    device:
    - PLIB_CMP_OpAmpOutputEnable
    - PLIB_CMP_OpAmpOutputDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The OpAmpOutputEnableControl feature is supported on the device
    - false  - The OpAmpOutputEnableControl feature is not supported on the
               device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsOpAmpOutputControl( CMP_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CMP_ExistsOpAmpEnableControl( CMP_MODULE_ID index)

  Summary:
    Identifies whether the op-amp feature exists on the CMP module.

  Description:
    This function identifies whether the op-amp feature is available on the 
    CMP module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_OpAmpEnable
    - PLIB_CMP_OpAmpDisable

  Preconditions:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured

  Returns:
    - true   - The op-amp feature is supported on the comparator channel/device
    - false  - The op-amp feature is not supported on the comparator/device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsOpAmpEnableControl( CMP_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_CMP_ExistsComparatorOutputMasking( CMP_MODULE_ID index )

  Summary:
    Identifies whether the CMP masking/blanking feature exists on the 
	Comparator module.

  Description:
    This function identifies whether the masking/blanking feature is available on
	the module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CMP_ComparatorOutputMaskingSetup 

  Preconditions:
    None.

  Parameters:
    none.

  Returns:
    - true   - The masking/blanking feature is supported on the device
    - false  - The masking/blanking feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CMP_ExistsComparatorOutputMasking( CMP_MODULE_ID index );

#include "peripheral/cmp/plib_cmp_compatibility.h"

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // #ifndef _PLIB_CMP_H
/*******************************************************************************
 End of File
*/

