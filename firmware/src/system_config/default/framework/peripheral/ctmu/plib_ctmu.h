/*******************************************************************************
  Charge Time Measurement Unit (CTMU) Peripheral Library Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ctmu.h

  Summary:
	This file contains the interface definition for the CTMU Peripheral
	Library.

  Description:
	This library provides a low-level abstraction of the Charge Time Measurement
	Unit(CTMU) module on Microchip microcontrollers with a convenient C
	language interface. It can be used to simplify low-level access to the
	module without the necessity of interacting directly with the module's
	registers, thus hiding differences between one microcontroller variant and
	another.
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
// DOM-IGNORE-END

#ifndef _PLIB_CTMU_H    // Guards against multiple inclusion
#define _PLIB_CTMU_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

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
    please see the bottom of the file for additional implementation header files
    that are also included
*/

#include "peripheral/ctmu/processor/ctmu_processor.h"

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void PLIB_CTMU_EdgeSensitivitySet ( CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber,
										CTMU_EDGE_SENSITIVITY edgeSense )

  Summary:
    Sets CTMU sensitivity for the selected edge.

  Description:
    This function can be used to set the sensitivity of a particular edge to 
	level-sensitive or edge sensitive.   

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module.
    edgeNumber - CTMU edge for which the sensitivity to be set, one of the possible
				 elements of the CTMU_EDGE_SELECT enum.
	edgeSense -  CTMU Edge sensitivity, one of the possible elements of the 
	             CTMU_EDGE_SENSITIVITY enum.

  Returns:
    None.

  Example:
	<code>
    // Example to set both edges to trigger on edges rather than levels
    PLIB_CTMU_EdgeSensitivitySet ( CTMU_ID_0, CTMU_EDGE1, CTMU_EDGE_X_EDGE_SENSITIVE ); 
	PLIB_CTMU_EdgeSensitivitySet ( CTMU_ID_0, CTMU_EDGE2, CTMU_EDGE_X_EDGE_SENSITIVE ); 
	</code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsEdgeSensitivity in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_EdgeSensitivitySet ( CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber,
								CTMU_EDGE_SENSITIVITY edgeSense );


/*******************************************************************************
  Function:
    void PLIB_CTMU_EdgePolaritySet ( CTMU_MODULE_ID index,CTMU_EDGE_SELECT edgeNumber,
								CTMU_EDGE_POLARITY edgePolarity );

  Summary:
    Sets a CTMU edge to fire on an edge/level with the selected polarity 
	of signal.

  Description:
    This function sets a CTMU edge to fire on an edge/level with the selected 
	polarity of signal.

  Precondition:
    None.

  Parameters:
    index      - Identifier for the desired CTMU module.
    edgeNumber - CTMU Edge for which the polarity to be set, one of the possible 
				 elements of CTMU_EDGE_SELECT enum.
	edgeSense -  CTMU Edge polarity, one of the possible elements of the
				 CTMU_EDGE_POLARITY enum.

  Returns:
    None.

  Example:
	<code>
    // Example to set both edges to trigger on positive level/edge.
    PLIB_CTMU_EdgePolaritySet ( CTMU_ID_0, CTMU_EDGE1, CTMU_EDGE_X_POSITIVE_EDGE ); 
	PLIB_CTMU_EdgePolaritySet ( CTMU_ID_0, CTMU_EDGE2, CTMU_EDGE_X_POSITIVE_EDGE ); 
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsEdgePolarity in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_EdgePolaritySet ( CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber,
								CTMU_EDGE_POLARITY edgePolarity );
								
								
/*******************************************************************************
  Function:
    void PLIB_CTMU_EdgeTriggerSourceSelect ( CTMU_MODULE_ID index,
										CTMU_EDGE_SELECT edgeNumber,
										CTMU_TRIGGER_SOURCES triggerSource )

  Summary:
    Assigns a trigger source for an edge.

  Description:
    This function will enable the CTMU edge (given by edge_number) to trigger on the 
	signal provided by the trigger source selected.

  Precondition:
    None.

  Parameters:
	index         - Identifier for the desired CTMU module.
    edgeNumber    - CTMU Edge for which the trigger source to be set, one of the 
					possible elements of the CTMU_EDGE_SELECT enum.
	triggerSource - CTMU Edge trigger source, one of the possible elements of the 
					CTMU_TRIGGER_SOURCES enum.
	
  Returns:
    None.

  Example:
	<code>
	//Set source 0 as the trigger source for both the edges
    PLIB_CTMU_EdgeTriggerSourceSelect ( CTMU_ID_0, CTMU_EDGE1, CTMU_TRIGGERSOURCE_0 );
    PLIB_CTMU_EdgeTriggerSourceSelect ( CTMU_ID_0, CTMU_EDGE2, CTMU_TRIGGERSOURCE_0 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsEdgeTriggerSource in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_EdgeTriggerSourceSelect ( CTMU_MODULE_ID index,
										CTMU_EDGE_SELECT edgeNumber,
										CTMU_TRIGGER_SOURCES triggerSource );								
/*******************************************************************************
  Function:
    void PLIB_CTMU_EdgeSet ( CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber )

  Summary:
    Sets the status of a CTMU edge.

  Description:
    This function sets the status of the selected CTMU edge (given by edge_number).

  Precondition:
    None.

  Parameters:
    index      - Identifier for the desired CTMU module.
    edgeNumber - CTMU Edge for which the trigger source to be set, one of the 
				 possible elements of the CTMU_EDGE_SELECT enum.

  Returns:
    None.

  Example:
	<code>
    PLIB_CTMU_EdgeSet ( CTMU_ID_0, CTMU_EDGE1 );
	</code>
   
  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsEdgeStatus in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_EdgeSet ( CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber );
										

/*******************************************************************************
  Function:
    bool PLIB_CTMU_EdgeIsSet ( CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber )

  Summary:
    Gets the status of a CTMU edge.

  Description:
    This function gets the status of the selected CTMU edge ( given by edgeNumber ).

  Precondition:
    None.

  Parameters:
    index      - Identifier for the desired CTMU module.
    edgeNumber - CTMU Edge for which the trigger source to be set, one of the 
				 possible elements of the CTMU_EDGE_SELECT enum.

  Returns:
    None.

  Example:
	<code>
	bool edgeStatus;
	
    edgeStatus = PLIB_CTMU_EdgeIsSet ( CTMU_ID_0, CTMU_EDGE1 );
	</code>
   
  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsEdgeStatus in your application to determine whether
	this feature is available.
*/

bool PLIB_CTMU_EdgeIsSet ( CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber );

										
/*******************************************************************************
  Function:
    void PLIB_CTMU_Enable ( CTMU_MODULE_ID index )

  Summary:
    Enables the CTMU module.

  Description:
    This function enables (turns ON) the CTMU module. This function is called 
	after configuring the CTMU module.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Turn on (enable) CTMU Module
	PLIB_CTMU_Enable ( CTMU_ID_0 );
	</code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsModuleEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_Enable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_Disable ( CTMU_MODULE_ID index )

  Summary:
    Disables the CTMU module.

  Description:
    This function disables (turns OFF) the CTMU module. Typically, this function 
	is called before reconfiguring the CTMU module.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Turn off (disable) CTMU
	PLIB_CTMU_Disable ( CTMU_ID_0 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsModuleEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_Disable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_StopInIdleEnable ( CTMU_MODULE_ID index )

  Summary:
    Sets the CTMU module to not operate when the device is in Idle mode.

  Description:
    This function sets the CTMU module to not operate when the device is in 
	Idle mode.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Do not run in Idle mode
	PLIB_CTMU_StopInIdleEnable ( CTMU_ID_0 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsStopInIdle in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_StopInIdleEnable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_StopInIdleDisable ( CTMU_MODULE_ID index )

  Summary:
    Sets the CTMU module to continue running when the device is in Idle mode.

  Description:
    This function sets the CTMU module to continue running when the device is 
	in Idle mode.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
    // Enable CTMU to run when CPU is in Idle Mode
    PLIB_CTMU_StopInIdleDisable ( CTMU_ID_0 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsStopInIdle in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_StopInIdleDisable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_TimePulseGenerationEnable ( CTMU_MODULE_ID index )

  Summary:
    Enables the generation of time pulses.

  Description:
    This function enables generation of time pulses using Comparator 2.

    Current source will not be available for capacitance, time, or temperature
    measurements.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Examples:
	<code>
	// Send current to ADC S&H without going through ADC input MUX.
	PLIB_CTMU_TimePulseGenerationEnable ( CTMU_ID_0 );
	</code/>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsTimePulseGeneration in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_TimePulseGenerationEnable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_TimePulseGenerationDisable ( CTMU_MODULE_ID index )

  Summary:
    Disables generation of time pulses using Comparator 2.

  Description:
    This function disables generation of time pulses using Comparator 2.

    Current source is made available for other measurements, including capacitance,
    time, or temperature (if temperature sensor is available).

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Return to button relative capacitance measurements
	PLIB_CTMU_TimePulseGenerationDisable ( CTMU_ID_0 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsTimePulseGeneration in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_TimePulseGenerationDisable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_EdgeEnable ( CTMU_MODULE_ID index )

  Summary:
    Enables the edges of the CTMU.

  Description:
    This function enables the edges of the CTMU (makes it not blocked).

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Enable edges so that input signals can turn the CTMU charge pump on and off
	PLIB_CTMU_EdgeEnable ( CTMU_ID_0 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsEdgeEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_EdgeEnable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_EdgeDisable ( CTMU_MODULE_ID index )

  Summary:
    Disables the edges of the CTMU.

  Description:
    This function disables the edges of the CTMU (makes them blocked).

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Disable edges, now can only turn CTMU on/off by modifying edge status
	PLIB_CTMU_EdgeDisable ( CTMU_ID_0 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsEdgeEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_EdgeDisable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_EdgeSequenceEnable ( CTMU_MODULE_ID index )

  Summary:
    Enables the edge sequence of the CTMU.

  Description:
    This function enables the edge sequence of the CTMU. Edge 1 must occur before 
	Edge 2 can occur.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Trigger on Edge1 then Edge2, i.e., don't trigger on Edge 2 
	//until Edge 1 has occurred
	PLIB_CTMU_EdgeSequenceEnable ( CTMU_ID_0 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsEdgeSequencing in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_EdgeSequenceEnable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_EdgeSequenceDisable ( CTMU_MODULE_ID index )

  Summary:
    Disables the edge sequence of the CTMU.

  Description:
    This function disables the edge sequence of the CTMU.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Trigger on Edge1 or Edge2, which ever one occurs first
	PLIB_CTMU_EdgeSequenceDisable ( CTMU_ID_0 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsEdgeSequencing in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_EdgeSequenceDisable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_CurrentDischargeEnable ( CTMU_MODULE_ID index )

  Summary:
    Enables the Current discharge by connecting the current source output 
	to ground.

  Description:
    This function enables the Current discharge by connecting the current 
	source output to ground.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Measure button voltage
	// TO DO: Start ADC sampling to connect S&H capacitor to charge pump
	PLIB_CTMU_CurrentDischargeEnable ( CTMU_ID_0 );    // Ground charge pump
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsCurrentDischarge in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_CurrentDischargeEnable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_CurrentDischargeDisable ( CTMU_MODULE_ID index )

  Summary:
    Disables the Current discharge by not connecting the current source output 
	to ground.

  Description:
    This function disables the Current discharge by not connecting the current source 
	output to ground.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Measure button voltage
	// TO DO: Start ADC sampling to connect S&H capacitor to charge pump
	PLIB_CTMU_CurrentDischargeDisable ( CTMU_ID_0 );    // Ground charge pump
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsCurrentDischarge in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_CurrentDischargeDisable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_AutomaticADCTriggerEnable ( CTMU_MODULE_ID index )

  Summary:
    Enables the module to automatically trigger an analog-to-digital conversion 
	when the second edge event has occurred.

  Description:
    This function enables the module to automatically trigger an analog-to-digital 
	conversion when the second edge event has occurred.

    The ADC trigger is asserted whenever the CTMU current source switches from
    ON to OFF.  The ADC can then end sampling and start converting the measured
    voltage into bits.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Enable ADC trigger from CTMU
	PLIB_CTMU_AutomaticADCTriggerEnable ( CTMU_ID_0 );

	//To Do: Tell ADC to use CTMU trigger
	</code>

  Remarks:
    The ADC must be configured to use the CTMU trigger signal generated.
	
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsAutomaticADCTrigger in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_AutomaticADCTriggerEnable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_AutomaticADCTriggerDisable ( CTMU_MODULE_ID index )

  Summary:
    Disables the module to automatically trigger an analog-to-digital conversion.

  Description:
    This function disables the module to automatically trigger an analog-to-digital 
	conversion.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module

  Returns:
    None.

  Example:
	<code>
	// Disable ADC trigger from CTMU
	PLIB_CTMU_AutomaticADCTriggerDisable ( CTMU_ID_0 );

	//To Do: Tell ADC to use CTMU trigger
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsAutomaticADCTrigger in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_AutomaticADCTriggerDisable ( CTMU_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_CTMU_CurrentTrimSet ( CTMU_MODULE_ID index, int16_t currentTrim )

  Summary:
    Trims current source off of the nominal value.

  Description:
    This function trims current source off of the nominal value.

  Precondition:
    None.

  Parameters:
    index - Identifier for the desired CTMU module
    currentTrim - Current trim index, from -31 to 31

  Example:
	<code>
	// Set current trim, adjust from nominal by -10 x 2% = -20%
	PLIB_CTMU_CurrentTrimSet ( CTMU_ID_0, -10 );
	</code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsCurrentTrim in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_CurrentTrimSet ( CTMU_MODULE_ID index, int16_t currentTrim );


/*******************************************************************************
  Function:
    void PLIB_CTMU_CurrentRangeSet ( CTMU_MODULE_ID index, CTMU_CURRENT_RANGE currentRange )

  Summary:
    Selects the current source range.

  Description:
    This function selects the current source range.

  Precondition:
    None.

  Parameters:
    index        - Identifier for the desired CTMU module
    currentRange - Charge pump current range selected, one of the possible 
				   enumeration values from CTMU_CURRENT_RANGE enum

  Returns:
    None.

  Example:
	<code>
	// Select current range
	PLIB_CTMU_CurrentRangeSet ( CTMU_ID_0, CTMU_CURRENT_RANGE_BASE );
	</code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CTMU_ExistsCurrentRange in your application to determine whether
	this feature is available.
*/

void PLIB_CTMU_CurrentRangeSet ( CTMU_MODULE_ID index,
                                CTMU_CURRENT_RANGE currentRange );

								
// *****************************************************************************
// *****************************************************************************
// Section: CTMU Peripheral Library Exists API Routines
// *****************************************************************************
// *****************************************************************************
/* The functions below indicate the existence of the features on the device. 
*/

//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsEdgeSensitivity( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the EdgeSensitivity feature exists on the CTMU module, 

  Description:
    This function identifies whether the EdgeSensitivity feature is available 
	on the CTMU module.
    When this function returns true, this function is supported on the device: 
    - PLIB_CTMU_EdgeSensitivitySet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The EdgeSensitivity feature is supported on the device
    - false  - The EdgeSensitivity feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsEdgeSensitivity( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsEdgePolarity( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the EdgePolarity feature exists on the CTMU module. 

  Description:
    This function identifies whether the EdgePolarity feature is available on 
	the CTMU module.
    When this function returns true, this function is supported on the device: 
    - PLIB_CTMU_EdgePolaritySet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The EdgePolarity feature is supported on the device
    - false  - The EdgePolarity feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsEdgePolarity( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsEdgeTriggerSource( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the EdgeTriggerSource feature exists on the CTMU module. 

  Description:
    This function identifies whether the EdgeTriggerSource feature is available 
	on the CTMU module.
    When this function returns true, this function is supported on the device: 
    - PLIB_CTMU_EdgeTriggerSourceSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The EdgeTriggerSource feature is supported on the device
    - false  - The EdgeTriggerSource feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsEdgeTriggerSource( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsEdgeStatus( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the EdgeStatus feature exists on the CTMU module. 

  Description:
    This function identifies whether the EdgeStatus feature is available on the 
	CTMU module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CTMU_EdgeIsSet
    - PLIB_CTMU_EdgeSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The EdgeStatus feature is supported on the device
    - false  - The EdgeStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsEdgeStatus( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsModuleEnable( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the ModuleEnable feature exists on the CTMU module. 

  Description:
    This function identifies whether the ModuleEnable feature is available on the 
	CTMU module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CTMU_Disable
    - PLIB_CTMU_Enable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ModuleEnable feature is supported on the device
    - false  - The ModuleEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsModuleEnable( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsStopInIdle( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the StopInIdle feature exists on the CTMU module. 

  Description:
    This function identifies whether the StopInIdle feature is available on the 
	CTMU module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CTMU_StopInIdleDisable
    - PLIB_CTMU_StopInIdleEnable

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

bool PLIB_CTMU_ExistsStopInIdle( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsTimePulseGeneration( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the TimePulseGeneration feature exists on the CTMU module. 

  Description:
    This function identifies whether the TimePulseGeneration feature is available 
	on the CTMU module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CTMU_TimePulseGenerationDisable
    - PLIB_CTMU_TimePulseGenerationEnable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The TimePulseGeneration feature is supported on the device
    - false  - The TimePulseGeneration feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsTimePulseGeneration( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsEdgeEnable( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the EdgeEnable feature exists on the CTMU module. 

  Description:
    This function identifies whether the EdgeEnable feature is available on the 
	CTMU module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CTMU_EdgeDisable
    - PLIB_CTMU_EdgeEnable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The EdgeEnable feature is supported on the device
    - false  - The EdgeEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsEdgeEnable( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsEdgeSequencing( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the EdgeSequencing feature exists on the CTMU module. 

  Description:
    This function identifies whether the EdgeSequencing feature is available on 
	the CTMU module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CTMU_EdgeSequenceDisable 
    - PLIB_CTMU_EdgeSequenceEnable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The EdgeSequencing feature is supported on the device
    - false  - The EdgeSequencing feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsEdgeSequencing( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsCurrentDischarge( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the CurrentDischarge feature exists on the CTMU module. 

  Description:
    This function identifies whether the CurrentDischarge feature is available 
	on the CTMU module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CTMU_CurrentDischargeEnable
    - PLIB_CTMU_CurrentDischargeDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CurrentDischarge feature is supported on the device
    - false  - The CurrentDischarge feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsCurrentDischarge( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsAutomaticADCTrigger( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the AutomaticADCTrigger feature exists on the CTMU module. 

  Description:
    This function identifies whether the AutomaticADCTrigger feature is available 
	on the CTMU module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_CTMU_AutomaticADCTriggerDisable
    - PLIB_CTMU_AutomaticADCTriggerEnable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The AutomaticADCTrigger feature is supported on the device
    - false  - The AutomaticADCTrigger feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsAutomaticADCTrigger( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsCurrentTrim( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the CurrentTrim feature exists on the CTMU module. 

  Description:
    This function identifies whether the CurrentTrim feature is available on the 
	CTMU module.
    When this function returns true, this function is supported on the device: 
    - PLIB_CTMU_CurrentTrimSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CurrentTrim feature is supported on the device
    - false  - The CurrentTrim feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsCurrentTrim( CTMU_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CTMU_ExistsCurrentRange( CTMU_MODULE_ID index )

  Summary:
    Identifies whether the CurrentRange feature exists on the CTMU module. 

  Description:
    This function identifies whether the CurrentRange feature is available on 
	the CTMU module.
    When this function returns true, this function is supported on the device: 
    - PLIB_CTMU_CurrentRangeSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CurrentRange feature is supported on the device
    - false  - The CurrentRange feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CTMU_ExistsCurrentRange( CTMU_MODULE_ID index );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
								
#endif//!defined( _PLIB_CTMU_H )
