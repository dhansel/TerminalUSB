/*******************************************************************************
  ADC Peripheral Library Interface Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_adc.h

  Summary:
    ADC PLIB interface header for definitions common to the ADC peripheral.

  Description:
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the ADC
    PLIB for all families of Microchip microcontrollers. The definitions in
    this file are common to the ADC peripheral.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PLIB_ADC_H
#define _PLIB_ADC_H

#include <stdint.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************


// ****************************************************************************
/*  ADC Conversion Clock Selection Data Type

  Summary:
    Data type defines the different ADC Conversion clock

  Description:
    This data type defines the different ADC Conversion clock

  Remarks:
    None.
*/

typedef  uint32_t ADC_CONVERSION_CLOCK;

// ****************************************************************************
/*  ADC Acquisition Time Selection Data Type

  Summary:
    Data type defining the different ADC acquisition times by which the ADC
    can be configured.

  Description:
    This data type defines the different ADC acquisition times by which the ADC
    can be configured.

  Remarks:
    None.
*/

typedef  uint32_t  ADC_ACQUISITION_TIME;


// ****************************************************************************
/*  ADC Sample size

  Summary:
    Data type defining the size of the ADC sample register.

  Description:
    This data type defines  the size of the ADC sample register.

  Remarks:
    None.
*/

typedef  uint32_t	 ADC_SAMPLE;




// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued at end of file)
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.  However,
    please see the bottom of the file for additional implementation header files
    that are also included
*/

#include "peripheral/adc/processor/adc_processor.h"


// *****************************************************************************
// *****************************************************************************
// Section: ADC Peripheral Library Interface Routines
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
/* Function:
    void PLIB_ADC_Enable( ADC_MODULE_ID index )

  Summary:
    ADC module is enabled (turned ON).

  Description:
    This function enables (turns ON) the selected ADC module.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_Enable(MY_ADC_INSTANCE);
    </code>

  Remarks: 
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsEnableControl in your application to
	determine whether this feature is available.
*/

void PLIB_ADC_Enable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_Disable( ADC_MODULE_ID index )

  Summary:
    ADC module is disabled (turned OFF).

  Description:
    This function disables (turns OFF) the selected ADC module.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_Disable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsEnableControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_Disable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_StopInIdleEnable( ADC_MODULE_ID index )

  Summary:
    Discontinue ADC module operation when device enters Idle mode.

  Description:
    This function discontinues ADC module operation when the device enters Idle
    mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_StopInIdleEnable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsStopInIdleControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_StopInIdleEnable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_StopInIdleDisable( ADC_MODULE_ID index )

  Summary:
    Continue ADC module operation when the device is in Idle mode.

  Description:
    This function enables the ADC module to continue operation when the device
    is in Idle mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_StopInIdleDisable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsStopInIdleControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_StopInIdleDisable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_CalibrationEnable( ADC_MODULE_ID index )

  Summary:
    Calibration is performed on the next ADC conversion.

  Description:
    This function enables calibration to be performed on the next ADC conversion.

    When the Calibration bit is enabled, inputs are disconnected and tied to
    AVss. This sets the inputs of the ADC to zero. Then, the user can perform a
    conversion. Use of the Calibration mode is not affected if the ADC line
    has been configured as analog or digital, nor by channel input selection.
    Any analog input switches are disconnected from the ADC module in this mode.
    The conversion result is stored by the user software and is used to compensate
    subsequent conversions. This can be done by adding the two?s complement of
    the result obtained during calibration to all normal ADC conversions.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_CalibrationEnable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsCalibrationControl in your application to determine
        whether this feature is available.
*/

void PLIB_ADC_CalibrationEnable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_CalibrationDisable( ADC_MODULE_ID index )

  Summary:
    Normal ADC module operation (no calibration is performed).

  Description:
    This function enables normal ADC module operation without any calibration.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_CalibrationDisable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsCalibrationControl in your application to determine
        whether this feature is available.
*/

void PLIB_ADC_CalibrationDisable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_InputScanMaskAdd( ADC_MODULE_ID index,
                                    ADC_INPUTS_SCAN scanInputs )

  Summary:
    Select ADC analog channel for input scan.

  Description:
    This function selects the ADC analog channel for input scanning.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    scanInputs      - One of the possible values from ADC_INPUTS_SCAN. Inputs are added
                      for scanning.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    // Single channel addition
    PLIB_ADC_InputScanMaskAdd(MY_ADC_INSTANCE, ADC_INPUT_SCAN_AN2);
    // Multiple channels addition
    PLIB_ADC_InputScanMaskAdd(ADC_ID_1, ADC_INPUT_SCAN_AN2 | ADC_INPUT_SCAN_AN2);
    </code>

  Remarks:
    Multiple channels can be added simultaneously by ORing.

	This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_ADC_ExistsMuxInputScanSelect in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_InputScanMaskAdd( ADC_MODULE_ID index,
                                ADC_INPUTS_SCAN scanInputs );


// *****************************************************************************
/* Function:
    void PLIB_ADC_InputScanMaskRemove( ADC_MODULE_ID index,
                                       ADC_INPUTS_SCAN scanInputs )

  Summary:
    Omits ADC analog channel for input scan.

  Description:
    This function allows the ADC analog channel to be omitted from input
    scanning.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    scanInputs      - One of the possible values from ADC_INPUTS_SCAN. Inputs are removed
                      from scanning.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    // Single channel removing
    PLIB_ADC_InputScanMaskRemove(MY_ADC_INSTANCE, ADC_INPUT_SCAN_AN2);
    // Multiple channels removing
    PLIB_ADC_InputScanMaskRemove(ADC_ID_1, ADC_INPUT_SCAN_AN2 | ADC_INPUT_SCAN_AN3);
    </code>

  Remarks:
    Multiple channels can be removed simultaneously by ORing.

	This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_ADC_ExistsMuxInputScanSelect in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_InputScanMaskRemove( ADC_MODULE_ID index,
                                   ADC_INPUTS_SCAN scanInputs );


// *****************************************************************************
/* Function:
    void PLIB_ADC_InputScanMaskAddExtended( ADC_MODULE_ID index,
                                    ADC_INPUTS_SCAN_EXTENDED scanInputs )

  Summary:
    Select extended ADC analog channel for input scan.

  Description:
    This function selects the extended ADC analog channel for input scanning.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    scanInputs      - One of the possible values from ADC_INPUTS_SCAN_EXTENDED.
                      Inputs are added for scanning.

  Returns:
    None.

  Example:
    <code>

    // Single channel addition
    PLIB_ADC_InputScanMaskAddExtended(ADC_ID_1, ADC_INPUT_SCAN_AN36);
    // Multiple channels addition
    PLIB_ADC_InputScanMaskAddExtended(ADC_ID_1, ADC_INPUT_SCAN_AN36 | ADC_INPUT_SCAN_AN39);
    
    </code>

  Remarks:
    Multiple channels can be added simultaneously by ORing.

	This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_ADC_ExistsMuxInputScanSelectExtended in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_InputScanMaskAddExtended( ADC_MODULE_ID index,
                                ADC_INPUTS_SCAN_EXTENDED scanInputs );


// *****************************************************************************
/* Function:
    void PLIB_ADC_InputScanMaskRemove( ADC_MODULE_ID index,
                                       ADC_INPUTS_SCAN_EXTENDED scanInputs )

  Summary:
    Omits extended ADC analog channel for input scan.

  Description:
    This function allows the extended ADC analog channel to be omitted from input
    scanning.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    scanInputs      - One of the possible values from ADC_INPUTS_SCAN_EXTENDED.
                      Inputs are removed from scanning.

  Returns:
    None.

  Example:
    <code>

    // Single channel removing
    PLIB_ADC_InputScanMaskRemove(ADC_ID_1, ADC_INPUT_SCAN_AN36);
    // Multiple channels removing
    PLIB_ADC_InputScanMaskRemove(ADC_ID_1, ADC_INPUT_SCAN_AN36 | ADC_INPUT_SCAN_AN39);
    
    </code>

  Remarks:
    Multiple channels can be removed simultaneously by ORing.

	This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_ADC_ExistsMuxInputScanSelectExtended in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_InputScanMaskRemoveExtended( ADC_MODULE_ID index,
                                   ADC_INPUTS_SCAN_EXTENDED scanInputs );
                                   
// *****************************************************************************
/* Function:
    void PLIB_ADC_VoltageReferenceSelect( ADC_MODULE_ID index,
                                          ADC_VOLTAGE_REFERENCE configValue )

  Summary:
    Voltage reference configuration.

  Description:
    This function configures the ADC module voltage reference.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    configValue     - One of the possible values from ADC_VOLTAGE_REFERENCE

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_VoltageReferenceSelect(MY_ADC_INSTANCE, ADC_REFERENCE_VREFPLUS_TO_AVSS);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsVoltageReference in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_VoltageReferenceSelect( ADC_MODULE_ID index,
                                      ADC_VOLTAGE_REFERENCE configValue );


// *****************************************************************************
/* Function:
    void PLIB_ADC_MuxChannel0InputNegativeSelect( ADC_MODULE_ID index,
                                                  ADC_MUX muxType,
                                                  ADC_INPUTS_NEGATIVE input )

  Summary:
    Channel 0 negative input select for multiplexer setting.

  Description:
    This function selects the negative input for channel 0 of MUX A or MUX B.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    muxType         - One of the possible values from ADC_MUX
    input           - One of the possible values from ADC_INPUTS_NEGATIVE

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_MuxChannel0InputNegativeSelect(MY_ADC_INSTANCE, ADC_MUX_A, ADC_INPUT_NEGATIVE_VREF_MINUS);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsMuxChannel0NegativeInput in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_MuxChannel0InputNegativeSelect( ADC_MODULE_ID index,
                                              ADC_MUX muxType,
                                              ADC_INPUTS_NEGATIVE input );


// *****************************************************************************
/* Function:
    void PLIB_ADC_MuxChannel0InputPositiveSelect( ADC_MODULE_ID index,
                                                  ADC_MUX muxType,
                                                  ADC_INPUTS_POSITIVE input )

  Summary:
    Channel 0 positive input select for multiplexer setting.

  Description:
    This function selects the positive input for channel 0 of MUX A or MUX B.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    muxType         - One of the possible values from ADC_MUX
    input           - One of the possible values from ADC_INPUTS_POSITIVE

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_MuxChannel0InputPositiveSelect(MY_ADC_INSTANCE, ADC_MUX_A, ADC_INPUT_POSITIVE_AN2);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsMuxChannel0PositiveInput in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_MuxChannel0InputPositiveSelect( ADC_MODULE_ID index,
                                              ADC_MUX muxType,
                                              ADC_INPUTS_POSITIVE input );


// *****************************************************************************
/* Function:
    void PLIB_ADC_MuxAInputScanEnable( ADC_MODULE_ID index )

  Summary:
    Scan input selections for CH0+ of MUX A.

  Description:
    This function enables scan input for CH0+ of MUX A.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_MuxAInputScanEnable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsMuxInputScanControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_MuxAInputScanEnable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_MuxAInputScanDisable( ADC_MODULE_ID index )

  Summary:
    Do not scan input selections for CH0+ of MUX A.

  Description:
    This function disables scan input for CH0+ of MUX A.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_MuxAInputScanDisable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsMuxInputScanControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_MuxAInputScanDisable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_SamplingModeSelect( ADC_MODULE_ID index, ADC_SAMPLING_MODE mode )

  Summary:
    Enable the selected sampling mode.

  Description:
    This function selects the sampling mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    mode            - One of the possible values from ADC_SAMPLING_MODE

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_SamplingModeSelect(MY_ADC_INSTANCE, ADC_SAMPLING_MODE_ALTERNATE_INPUT);
    </code>

  Remarks:
    Sampling mode could be alternate input or Simultaneous or Sequential mode.
    Alternate input can be combined with Simultaneous or Sequential modes.
 
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsSamplingModeControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_SamplingModeSelect( ADC_MODULE_ID index, ADC_SAMPLING_MODE mode );


// *****************************************************************************
/* Function:
    void PLIB_ADC_SamplesPerInterruptSelect( ADC_MODULE_ID index,
                                             ADC_SAMPLES_PER_INTERRUPT value )

  Summary:
    Interrupts at the completion of conversion for each nth sample.

  Description:
    This function interrupts at the completion of conversion for each nth
    sample/convert sequence.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    value           - Possible values from ADC_SAMPLES_PER_INTERRUPT

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_SamplesPerInterruptSelect(MY_ADC_INSTANCE, ADC_16SAMPLES_PER_INTERRUPT);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsSamplesPerInterruptSelect in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_SamplesPerInterruptSelect( ADC_MODULE_ID index,
                                         ADC_SAMPLES_PER_INTERRUPT value );


// *****************************************************************************
/* Function:
    void PLIB_ADC_SampleAutoStartEnable( ADC_MODULE_ID index )

  Summary:
    Sampling auto-start is enabled.

  Description:
    This function enables auto-sampling. Sampling begins immediately after the
    last conversion is completed.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_SampleAutoStartEnable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsSamplingAutoStart in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_SampleAutoStartEnable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_SampleAutoStartDisable( ADC_MODULE_ID index )

  Summary:
    Sampling auto-start is disabled.

  Description:
    This function disables auto-sampling and enables manual sampling.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_SampleAutoStartDisable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsSamplingAutoStart in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_SampleAutoStartDisable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_SamplingStart( ADC_MODULE_ID index )

  Summary:
    Sampling is enabled.

  Description:
    This function starts the ADC Sample and Hold circuit to sample the
    input channel.

  Precondition:
    Automatic sampling must be disabled.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_SamplingStart(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsSamplingControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_SamplingStart( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_SamplingStop( ADC_MODULE_ID index )

  Summary:
    Holding is enabled.

  Description:
    This function stops the ADC Sample and Hold circuit from sampling and holds 
	the sampled data.

  Precondition:
    Automatic sampling must be disabled.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_SamplingStop(MY_ADC_INSTANCE);
    </code>

  Remarks: 
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsSamplingControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_SamplingStop( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_SampleAcquisitionTimeSet( ADC_MODULE_ID index,
                                           ADC_ACQUISITION_TIME acqTime )

  Summary:
    Sets the ADC acquisition/auto-sample time in TADs.

  Description:
    This function sets the ADC acquisition/auto-sample time in TADs.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    acqTime         - Unsigned value of type ADC_ACQUISITION_TIME

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_SampleAcquisitionTimeSet(MY_ADC_INSTANCE, 2);
    </code>

  Remarks: 
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsSamplingAcquisitionTime in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_SampleAcquisitionTimeSet( ADC_MODULE_ID index,
                                       ADC_ACQUISITION_TIME acqTime );


// *****************************************************************************
/* Function:
    bool PLIB_ADC_SamplingIsActive( ADC_MODULE_ID index )

  Summary:
    Provides the ADC sampling status.

  Description:
    This function returns the ADC sampling status on whether the ADC is sampling
    or holding.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    Boolean:
	- true  - ADC Sample and Hold circuit is sampling
    - false - ADC Sample and Hold circuit is holding

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    bool my_status = PLIB_ADC_SamplingIsActive(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsSamplingStatus in your application to determine
    whether this feature is available.
*/

bool PLIB_ADC_SamplingIsActive( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_ConversionStart( ADC_MODULE_ID index )

  Summary:
    Starts ADC module manual conversion process.

  Description:
    This function starts the ADC module manual conversion process.

  Precondition:
    Automatic sampling must be disabled.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_ConversionStart(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsConversionControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_ConversionStart( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_ConversionClockSet( ADC_MODULE_ID index,
									   uint32_t baseFrequency,
                                      ADC_CONVERSION_CLOCK value )

  Summary:
    Sets the ADC module conversion clock.

  Description:
    This function sets the ADC module conversion clock prescaler.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
	baseFrequency	- Input clock frequency in Hertz (Hz). This is the input
					  clock to ADC module.
    value           - Unsigned value of type ADC_CONVERSION_CLOCK. This is
					  the required conversion clock of ADC module in Hz.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
	// Following functions passed the input clock to ADC as 80MHz and 
	// required conversion clock as 20MHz.
    PLIB_ADC_ConversionClockSet(MY_ADC_INSTANCE, 80000000, 20000000);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsConversionClock in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_ConversionClockSet( ADC_MODULE_ID index,
								  uint32_t baseFrequency,
                                  ADC_CONVERSION_CLOCK value );


// *****************************************************************************
/* Function:
    ADC_CONVERSION_CLOCK PLIB_ADC_ConversionClockGet( ADC_MODULE_ID index,
                                          uint32_t baseFrequencyHz )

  Summary:
    Obtains the conversion clock.

  Description:
    This function obtains the conversion clock that is being used by the ADC module.

  Precondition:
    None.

  Parameters:
    index                   - Identifier for the device instance to be configured
    baseFrequencyHz         - Input clock frequency to the ADC module in Hz

  Returns:
    ADC_CONVERSION_CLOCK    - ADC Conversion clock value (in Hz) of type 
							  ADC_CONVERSION_CLOCK

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    // baseFrequency is the peripheral input frequency
    ADC_CONVERSION_CLOCK conversionClock; // To store the conversion clock value
    conversionClock = PLIB_ADC_ConversionClockGet(MY_ADC_INSTANCE, 8000000);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsConversionClock in your application to determine
    whether this feature is available.
*/

ADC_CONVERSION_CLOCK PLIB_ADC_ConversionClockGet( ADC_MODULE_ID index, uint32_t baseFrequency );

								  
// *****************************************************************************
/* Function:
    void PLIB_ADC_ConversionClockSourceSelect( ADC_MODULE_ID index,
                                               ADC_CLOCK_SOURCE source )

  Summary:
    Selects the ADC module conversion clock source.

  Description:
    This function selects the ADC module conversion clock source.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    source          - One of the possible values from ADC_CLOCK_SOURCE

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_ConversionClockSourceSelect(MY_ADC_INSTANCE, ADC_CLOCK_SOURCE_PERIPHERAL_BUS_CLOCK);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsConversionClockSource in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_ConversionClockSourceSelect( ADC_MODULE_ID index, ADC_CLOCK_SOURCE source );


// *****************************************************************************
/* Function:
    void PLIB_ADC_ConversionTriggerSourceSelect( ADC_MODULE_ID index,
                                                 ADC_CONVERSION_TRIGGER_SOURCE source )

  Summary:
    Selects the conversion trigger source.

  Description:
    This function selects the ADC module conversion trigger source.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    source          - One of the possible values from ADC_CONVERSION_TRIGGER_SOURCE

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_ConversionTriggerSourceSelect(MY_ADC_INSTANCE, ADC_CONVERSION_TRIGGER_INTERNAL_COUNT);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsConversionTriggerSource in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_ConversionTriggerSourceSelect( ADC_MODULE_ID index,
                                             ADC_CONVERSION_TRIGGER_SOURCE source );


// *****************************************************************************
/* Function:
    void PLIB_ADC_ConversionStopSequenceEnable( ADC_MODULE_ID index )

  Summary:
    Stop conversion sequence (when the first ADC module interrupt is
    generated).

  Description:
    This function stops conversions when the first ADC module interrupt is
    generated. Hardware clears the Automatic Sampling bit when the ADC interrupt
    is generated.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_ConversionStopSequenceEnable(MY_ADC_INSTANCE);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsConversionStopSequenceControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_ConversionStopSequenceEnable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_ConversionStopSequenceDisable( ADC_MODULE_ID index )

  Summary:
    Normal conversion sequence.

  Description:
    This function enables normal operation, wherein the buffer contents will be
    overwritten by the next conversion sequence.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_ConversionStopSequenceDisable(MY_ADC_INSTANCE);
    </code>

  Remarks: 
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsConversionStopSequenceControl in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_ConversionStopSequenceDisable( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    bool PLIB_ADC_ConversionHasCompleted( ADC_MODULE_ID index )

  Summary:
    Provides the conversion completion status of the ADC.

  Description:
    This function provides the completion status of analog-to-digital conversion.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    Boolean:
	- true  - ADC conversion is done/completed
    - false - ADC conversion is in progress or has not started

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    bool my_status = PLIB_ADC_ConversionHasCompleted(MY_ADC_INSTANCE);
    </code>

  Remarks:  
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsConversionStatus in your application to determine
    whether this feature is available.
*/

bool PLIB_ADC_ConversionHasCompleted( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_ADC_ResultFormatSelect( ADC_MODULE_ID index,
                                      ADC_RESULT_FORMAT resultFormat )

  Summary:
    Selects the result format.

  Description:
    This function selects the result format.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    resultFormat    - One of the possible values from ADC_RESULT_FORMAT

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_ResultFormatSelect(MY_ADC_INSTANCE, ADC_RESULT_FORMAT_INTEGER_16BIT);
    </code>

  Remarks: 
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsResultFormat in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_ResultFormatSelect( ADC_MODULE_ID index,
                                  ADC_RESULT_FORMAT resultFormat );


// *****************************************************************************
/* Function:
    void PLIB_ADC_ResultBufferModeSelect( ADC_MODULE_ID index,
                                          ADC_BUFFER_MODE mode )

  Summary:
    Selects the result buffer mode.

  Description:
    This function selects the result buffer mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    mode            - One of the possible values from ADC_BUFFER_MODE

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    PLIB_ADC_ResultBufferModeSelect(MY_ADC_INSTANCE,
                                    ADC_BUFFER_MODE_TWO_8WORD_BUFFERS);
    </code>

  Remarks: 
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsResultBufferMode in your application to determine
    whether this feature is available.
*/

void PLIB_ADC_ResultBufferModeSelect( ADC_MODULE_ID index,
                                      ADC_BUFFER_MODE mode );


// *****************************************************************************
/* Function:
    ADC_RESULT_BUF_STATUS PLIB_ADC_ResultBufferStatusGet( ADC_MODULE_ID index )

  Summary:
    Provides the buffer fill status.

  Description:
    This function obtains the buffer fill status.

  Precondition:
    ADC multi-buffer support is available and configured.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    Boolean:
	- true  = ADC is currently filling buffer 08-0F, user should access data in 00-07
    - false = ADC is currently filling buffer 00-07, user should access data in 08-0F

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
	ADC_RESULT_BUF_STATUS my_status;
	
    my_status = PLIB_ADC_ResultBufferStatusGet(MY_ADC_INSTANCE);
    </code>

  Remarks: 
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsResultBufferFillStatus in your application to determine
    whether this feature is available.
*/

ADC_RESULT_BUF_STATUS PLIB_ADC_ResultBufferStatusGet( ADC_MODULE_ID index );


// *****************************************************************************
/* Function:
    ADC_SAMPLE PLIB_ADC_ResultGetByIndex( ADC_MODULE_ID index,
                                          uint8_t bufferIndex )

  Summary:
    Provides the ADC conversion result based on the buffer index.

  Description:
    This function provides the ADC module conversion result based on the buffer
    index.

  Precondition:
    ADC multi-buffer support available and configured.

  Parameters:
    index           - Identifier for the device instance to be configured
    bufferIndex     - Value ranging from 0 to 15

  Returns:
    int16_t        - ADC Conversion result at the respective bufferIndex

  Example:
    <code>
    // Where MY_ADC_INSTANCE, is the ADC instance selected for use by the
    // application developer.
    ADC_SAMPLE my_res = PLIB_ADC_ResultGetByIndex(MY_ADC_INSTANCE, 15);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the specific device data sheet
	to determine availability or use PLIB_ADC_ExistsResultGetByIndex in your application to determine
    whether this feature is available.
*/

ADC_SAMPLE PLIB_ADC_ResultGetByIndex( ADC_MODULE_ID index,
                                      uint8_t bufferIndex );


// *****************************************************************************
// *****************************************************************************
// Section: ADC Peripheral Library Exists API Routines
// *****************************************************************************
// *****************************************************************************
/* The functions below indicate the existence of the features on the device. 
*/

//******************************************************************************
/* Function :  PLIB_ADC_ExistsEnableControl( ADC_MODULE_ID index )

  Summary:
    Identifies whether the EnableControl feature exists on the ADC module 

  Description:
    This function identifies whether the EnableControl feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_Enable
    - PLIB_ADC_Disable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The EnableControl feature is supported on the device
    - false  - The EnableControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsEnableControl( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsStopInIdleControl( ADC_MODULE_ID index )

  Summary:
    Identifies whether the StopInIdle feature exists on the ADC module 

  Description:
    This function identifies whether the StopInIdle feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_StopInIdleEnable
    - PLIB_ADC_StopInIdleDisable

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

bool PLIB_ADC_ExistsStopInIdleControl( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsCalibrationControl( ADC_MODULE_ID index )

  Summary:
    Identifies whether the CalibrationControl feature exists on the ADC module 

  Description:
    This function identifies whether the CalibrationControl feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_CalibrationEnable
    - PLIB_ADC_CalibrationDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CalibrationControl feature is supported on the device
    - false  - The CalibrationControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsCalibrationControl( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsMuxInputScanSelect( ADC_MODULE_ID index )

  Summary:
    Identifies whether the MuxInputScanSelect feature exists on the ADC module 

  Description:
    This function identifies whether the MuxInputScanSelect feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_InputScanMaskAdd
    - PLIB_ADC_InputScanMaskRemove

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The MuxInputScanSelect feature is supported on the device
    - false  - The MuxInputScanSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsMuxInputScanSelect( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsMuxInputScanSelectExtended( ADC_MODULE_ID index )

  Summary:
    Identifies whether the MuxInputScanSelectExtended feature exists on the ADC module 

  Description:
    This function identifies whether the MuxInputScanSelectExtended feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_InputScanMaskAddExtended
    - PLIB_ADC_InputScanMaskRemoveExtended

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The MuxInputScanSelectExtended feature is supported on the device
    - false  - The MuxInputScanSelectExtended feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsMuxInputScanSelectExtended( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsVoltageReference( ADC_MODULE_ID index )

  Summary:
    Identifies whether the VoltageReference feature exists on the ADC module 

  Description:
    This function identifies whether the VoltageReference feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_VoltageReferenceSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The VoltageReference feature is supported on the device
    - false  - The VoltageReference feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsVoltageReference( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsMuxChannel0PositiveInput( ADC_MODULE_ID index )

  Summary:
    Identifies whether the MuxChannel0PositiveInput feature exists on the ADC module 

  Description:
    This function identifies whether the MuxChannel0PositiveInput feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_MuxChannel0InputPositiveSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The MuxChannel0PositiveInput feature is supported on the device
    - false  - The MuxChannel0PositiveInput feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsMuxChannel0PositiveInput( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsMuxChannel0NegativeInput( ADC_MODULE_ID index )

  Summary:
    Identifies whether the MuxChannel0NegativeInput feature exists on the ADC module 

  Description:
    This function identifies whether the MuxChannel0NegativeInput feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_MuxChannel0InputNegativeSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The MuxChannel0NegativeInput feature is supported on the device
    - false  - The MuxChannel0NegativeInput feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsMuxChannel0NegativeInput( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsMuxInputScanControl( ADC_MODULE_ID index )

  Summary:
    Identifies whether the MuxInputScanControl feature exists on the ADC module 

  Description:
    This function identifies whether the MuxInputScanControl feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_MuxAInputScanEnable
    - PLIB_ADC_MuxAInputScanDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The MuxInputScanControl feature is supported on the device
    - false  - The MuxInputScanControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsMuxInputScanControl( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsSamplingModeControl( ADC_MODULE_ID index )

  Summary:
    Identifies whether the SamplingModeControl feature exists on the ADC module 

  Description:
    This function identifies whether the SamplingModeControl feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_SamplingModeSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The SamplingModeControl feature is supported on the device
    - false  - The SamplingModeControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsSamplingModeControl( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsSamplesPerInterruptSelect( ADC_MODULE_ID index )

  Summary:
    Identifies whether the SamplesPerInterruptSelect feature exists on the ADC module 

  Description:
    This function identifies whether the SamplesPerInterruptSelect feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_SamplesPerInterruptSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The SamplesPerInterruptSelect feature is supported on the device
    - false  - The SamplesPerInterruptSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsSamplesPerInterruptSelect( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsSamplingAutoStart( ADC_MODULE_ID index )

  Summary:
    Identifies whether the SamplingAutoStart feature exists on the ADC module 

  Description:
    This function identifies whether the SamplingAutoStart feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_SampleAutoStartEnable
    - PLIB_ADC_SampleAutoStartDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The SamplingAutoStart feature is supported on the device
    - false  - The SamplingAutoStart feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsSamplingAutoStart( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsSamplingControl( ADC_MODULE_ID index )

  Summary:
    Identifies whether the SamplingControl feature exists on the ADC module 

  Description:
    This function identifies whether the SamplingControl feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_SamplingStart
    - PLIB_ADC_SamplingStop

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The SamplingControl feature is supported on the device
    - false  - The SamplingControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsSamplingControl( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsSamplingAcquisitionTime( ADC_MODULE_ID index )

  Summary:
    Identifies whether the SamplingAcquisitionTime feature exists on the ADC module 

  Description:
    This function identifies whether the SamplingAcquisitionTime feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_SampleAcquisitionTimeSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The SamplingAcquisitionTime feature is supported on the device
    - false  - The SamplingAcquisitionTime feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsSamplingAcquisitionTime( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsSamplingStatus( ADC_MODULE_ID index )

  Summary:
    Identifies whether the SamplingStatus feature exists on the ADC module 

  Description:
    This function identifies whether the SamplingStatus feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_SamplingIsActive

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The SamplingStatus feature is supported on the device
    - false  - The SamplingStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsSamplingStatus( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsConversionControl( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ConversionControl feature exists on the ADC module 

  Description:
    This function identifies whether the ConversionControl feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_ConversionStart

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ConversionControl feature is supported on the device
    - false  - The ConversionControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsConversionControl( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsConversionClock( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ConversionClock feature exists on the ADC module 

  Description:
    This function identifies whether the ConversionClock feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_ConversionClockSet
    - PLIB_ADC_ConversionClockGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ConversionClock feature is supported on the device
    - false  - The ConversionClock feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsConversionClock( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsConversionClockSource( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ConversionClockSource feature exists on the ADC module 

  Description:
    This function identifies whether the ConversionClockSource feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_ConversionClockSourceSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ConversionClockSource feature is supported on the device
    - false  - The ConversionClockSource feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsConversionClockSource( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsConversionTriggerSource( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ConversionTriggerSource feature exists on the ADC module 

  Description:
    This function identifies whether the ConversionTriggerSource feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_ConversionTriggerSourceSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ConversionTriggerSource feature is supported on the device
    - false  - The ConversionTriggerSource feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsConversionTriggerSource( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsConversionStopSequenceControl( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ConversionStopSequenceControl feature exists on the ADC module 

  Description:
    This function identifies whether the ConversionStopSequenceControl feature is available on the ADC module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADC_ConversionStopSequenceEnable
    - PLIB_ADC_ConversionStopSequenceDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ConversionStopSequenceControl feature is supported on the device
    - false  - The ConversionStopSequenceControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsConversionStopSequenceControl( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsConversionStatus( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ConversionStatus feature exists on the ADC module 

  Description:
    This function identifies whether the ConversionStatus feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_ConversionHasCompleted

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ConversionStatus feature is supported on the device
    - false  - The ConversionStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsConversionStatus( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsResultFormat( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ResultFormat feature exists on the ADC module 

  Description:
    This function identifies whether the ResultFormat feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_ResultFormatSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ResultFormat feature is supported on the device
    - false  - The ResultFormat feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsResultFormat( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsResultBufferMode( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ResultBufferMode feature exists on the ADC module 

  Description:
    This function identifies whether the ResultBufferMode feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_ResultBufferModeSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ResultBufferMode feature is supported on the device
    - false  - The ResultBufferMode feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsResultBufferMode( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsResultBufferFillStatus( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ResultBufferFillStatus feature exists on the ADC module 

  Description:
    This function identifies whether the ResultBufferFillStatus feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_ResultBufferStatusGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ResultBufferFillStatus feature is supported on the device
    - false  - The ResultBufferFillStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsResultBufferFillStatus( ADC_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_ADC_ExistsResultGetByIndex( ADC_MODULE_ID index )

  Summary:
    Identifies whether the ResultGetByIndex feature exists on the ADC module 

  Description:
    This function identifies whether the ResultGetByIndex feature is available on the ADC module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADC_ResultGetByIndex

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ResultGetByIndex feature is supported on the device
    - false  - The ResultGetByIndex feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADC_ExistsResultGetByIndex( ADC_MODULE_ID index );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // #ifndef _PLIB_ADC_H
/*******************************************************************************
 End of File
*/
