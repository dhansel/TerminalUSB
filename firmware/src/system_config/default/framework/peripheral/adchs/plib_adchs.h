/*******************************************************************************
  High-Speed Successive Approximation Register Analog-to-Digital Converter 
  (ADCHS) Peripheral Library Interface Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_adchs.h

  Summary:
    ADCHS Peripheral Library Interface Header for ADCHS common definitions.

  Description:
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the ADCHS
    PLIB for all families of Microchip microcontrollers.The definitions in
    this file are common to ADCHS peripheral.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PLIB_ADCHS_H
#define _PLIB_ADCHS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued at end of file)
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.  However,
    please see the bottom of the file for additional implementation header files
    that are also included
 */

#include <stdint.h>
#include <stdbool.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

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
#include "peripheral/adchs/processor/adchs_processor.h"

// *****************************************************************************
// *****************************************************************************
// Section: Helper Macros
// *****************************************************************************
// *****************************************************************************


// ****************************************************************************
// ****************************************************************************
// Section: Interface functions with global to ADCHS
// ****************************************************************************
// ****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_Enable( ADCHS_MODULE_ID index )

  Summary:
    Enables the High-Speed SAR ADC module.

  Description:
    This function enables (turns ON) the selected High-Speed SAR ADC module. There are
	many ADCHS functionalities which should be set/ selected before the ADCHS module
	is turned ON. Once the ADCHS is turned ON, the application code should check if
	the VREF is ready and without any fault. Subsequently, the analog bias circuitry
	for the required channel should be enabled followed by enabling the digital section.

  Precondition:
    All channels and analog input related selections should be made before enabling
	the ADCHS module.

  Parameters:
    index      - Identifier for the ADCHS instance to be configured.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    PLIB_ADCHS_Enable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_Enable(ADCHS_MODULE_ID index);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_Disable( ADCHS_MODULE_ID index )

  Summary:
    High-Speed SAR ADC module is disabled (turned OFF).

  Description:
    This function disables (turns OFF) the selected High-Speed SAR ADC module.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance to be configured.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    PLIB_ADCHS_Disable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    Not all functionality is available on all devices. Please refer to 
    the specific device data sheet for the list of available features.
 */

void PLIB_ADCHS_Disable(ADCHS_MODULE_ID index);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_TurboModeEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables Turbo mode for the High-Speed SAR ADC module.

  Description:
    This function enables (turns ON) Turbo mode on the High-Speed SAR ADC module. 

  Precondition:
    The master and slave channels must be selected to work in Turbo mode, before
	enabling Turbo mode.

  Parameters:
    index      - Identifier for the ADCHS instance to be configured.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    PLIB_ADCHS_TurboModeEnable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_TurboModeEnable(ADCHS_MODULE_ID index);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_TurboModeDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables Turbo mode for High-Speed SAR ADC module.

  Description:
    This function disables (turns OFF) Turbo mode on the High-Speed SAR ADC module. 

  Precondition:
    None.

  Parameters:
    index      - Identifier for the ADCHS instance to be configured.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    PLIB_ADCHS_TurboModeDisable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_TurboModeDisable(ADCHS_MODULE_ID index);

//********************************************************************
/* Function:
    bool PLIB_ADCHS_TurboModeErrorHasOccurred( ADCHS_MODULE_ID index )
    
  Summary:
    Returns the error state of Turbo mode.
	
  Description:
    Returns the state of error bit for Turbo mode. When Turbo mode is
	enabled, some parameters of master and slave channels should be same. 
	They are ADC channel clock divisor, ADC resolution, and Sampling time.
	Also, both master and slave channels should use synchronous sampling.
	If any or all these conditions are not met, the Turbo mode error
	will be set, which can be read by calling
	
  Precondition:
    None.
	
  Input:
    index 	- Identifier for the ADCHS instance.
	
  Returns:
    - true	- Turbo mode error has occurred
	- false	- Turbo mode error has not occurred
	
  Example:
    <code>
    bool errorState = PLIB_ADCHS_TurboModeErrorHasOccurred(MY_ADCHS_INSTANCE);
    </code>
	
  Remarks:
    None.                                                            
 */

bool PLIB_ADCHS_TurboModeErrorHasOccurred(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function:
    bool PLIB_ADCHS_TurboModeChannelSelect
	( 
		ADCHS_MODULE_ID index, 
        ADCHS_CHANNEL_ID masterChannelID,
        ADCHS_CHANNEL_ID slaveChannelID
	)

  Summary:
    Configures the channels for Turbo mode.

  Description:
    While running the High-Speed SAR ADC in Turbo mode, two channels (from 0 to 6) are 
	interleaved to get higher throughput. This function configures the two channels. 
	This configuration must occur prior to enabling the ADC and prior to enabling
	Turbo mode. Only valid channels from 0 to 6 can be made as master or slave. If
	Channel 7 is used, the function will return error

  Precondition:
    The channels are disabled and Turbo mode is disabled when calling this function. 

  Parameters:
    index           			- Identifier for the ADCHS instance. 
    masterChannelID				- Channel ID of master channel. Valid channel IDs are
								  from 0 to 6.
	slaveChannelID				- Channel ID of slave channel.  Valid channel IDs are
								  from 0 to 6.

  Returns:
    - true	- The function successfully selected the channels for Turbo mode
	- false	- The function could not select the channels for Turbo mode for the following
			  reasons:
			  - Both the master and slave channels are the same
			  - Channel 7 was used to set up Turbo mode (either as a master or a slave or both)

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.

    // Configure the ADC with Channel 0 as master and Channel 1 as slave
    if(!PLIB_ADCHS_TurboModeChannelSelect( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_0, ADCHS_CHANNEL_1))
	{
		// Error occurred while setting up Turbo mode
		while(1);
	}

	// Enable Turbo mode
	PLIB_ADCHS_TurboModeEnable(MY_ADCHS_INSTANCE);
	
	// Check for Turbo mode error
	if(PLIB_ADCHS_TurboModeErrorHasOccurred(MY_ADCHS_INSTANCE);
	{
		// Configuration of Turbo mode has caused an error
		// Process error here or reconfigure Turbo Mode
		while(1);
	}

    // Enable the ADC
    PLIB_ADCHS_Enable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

bool PLIB_ADCHS_TurboModeChannelSelect
( 
	ADCHS_MODULE_ID index, 
	ADCHS_CHANNEL_ID masterChannelID,
	ADCHS_CHANNEL_ID slaveChannelID
);

//********************************************************************
/* Function:
    bool PLIB_ADCHS_VREFIsReady( ADCHS_MODULE_ID index )
    
  Summary:
    Returns the state of VREF.
	
  Description:
    This function returns the VREF state.
	
  Precondition:
    The ADCHS module should be enabled before checking for VREF status. 
	The ADCHS module can be enabled by calling the PLIB_ADCHS_Enable function.
	
  Input:
    index -  Identifier for the ADCHS instance
	
  Returns:
    - true	- Both band gap reference voltage and ADC VREF are ready
	- false	- Either band gap reference voltage or ADC VREF is not ready
	
  Example:
    <code>
    bool vrefState = PLIB_ADCHS_VREFIsReady(MY_ADCHS_INSTANCE);
    </code>
	
  Remarks:
    None.                                                            
 */

bool PLIB_ADCHS_VREFIsReady( ADCHS_MODULE_ID index );

//********************************************************************
/* Function:
    bool PLIB_ADCHS_VREFFaultHasOccurred( ADCHS_MODULE_ID index )
    
  Summary:
    Returns the state of VREF fault.
	
  Description:
    This function returns the Fault state for VREF, Band Gap, or AVDD BOR.
	
  Precondition:
	The ADCHS module should be enabled before calling this function. 
	The ADCHS module can be enabled by calling the PLIB_ADCHS_Enable function.
	
  Input:
    index -  Identifier for the ADCHS instance
	
  Returns:
    - true	- A VREF Fault has occurred
	- false	- No Fault occurred on VREF
	
  Example:
    <code>
    bool vrefFaultState = PLIB_ADCHS_VREFFaultHasOccurred(MY_ADCHS_INSTANCE);
    </code>
	
  Remarks:
    None.                                                            
 */

bool PLIB_ADCHS_VREFFaultHasOccurred( ADCHS_MODULE_ID index );

//********************************************************************
/* Function:
    bool PLIB_ADCHS_AnalogInputScanIsComplete( ADCHS_MODULE_ID index )
    
  Summary:
    Returns the state of End of scan completion.
	
  Description:
    This function returns 'true', if all of the selected Analog Inputs 
	have completed scanning.
	
  Precondition:
    The ADCHS module should have Analog Inputs Scanning mode selected 
	and enabled for scanning to occur.
	
  Input:
    index -  Identifier for the ADCHS instance
	
  Returns:
    - true	- Analog input scanning is complete for the selected analog inputs
	- false	- Analog input scanning is not complete
	
  Example:
    <code>
    bool EOSState = PLIB_ADCHS_AnalogInputScanIsComplete(MY_ADCHS_INSTANCE);
    </code>
	
  Remarks:
    None.                                                            
 */

bool PLIB_ADCHS_AnalogInputScanIsComplete( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_EarlyInterruptEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables the early interrupt for the ADCHS.

  Description:
    This function enables (turns ON) the early interrupt for the entire ADCHS. Further
	selection (enabling/disabling) of early interrupt feature for individual analog
	input through the functions PLIB_ADCHS_AnalogInputEarlyInterruptEnable or 
	PLIB_ADCHS_AnalogInputEarlyInterruptDisable.
	
	The	interrupt is generated at a set number of clock prior to conversion complete.
	The number of clock for early interrupt is set using the "configure" function for
	specific channel.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Enable early interrupt
	PLIB_ADCHS_EarlyInterruptEnable( MY_ADCHS_INSTANCE );
	
	// Now, enable the early interrupt for each analog inputs
    PLIB_ADCHS_AnalogInputEarlyInterruptEnable(MY_ADCHS_INSTANCE, ADCHS_AN10);
	PLIB_ADCHS_AnalogInputEarlyInterruptEnable(MY_ADCHS_INSTANCE, ADCHS_AN11);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_EarlyInterruptEnable( ADCHS_MODULE_ID index );	

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_EarlyInterruptDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the early interrupt for the ADCHS.

  Description:
    This function Disables (turns OFF) the early interrupt for the entire ADCHS. Since
	early interrupt function is disabled, setting early interrupt enable for individual
	analog input will not work.
	
	Further selection (enabling/disabling) of interrupt feature for individual analog
	input is possible through the functions PLIB_ADCHS_AnalogInputDataReadyInterruptEnable or 
	PLIB_ADCHS_AnalogInputDataReadyInterruptDisable.
	
  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Disable early interrupt
	PLIB_ADCHS_EarlyInterruptDisable( MY_ADCHS_INSTANCE );
	
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_EarlyInterruptDisable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_Setup
	( 
		ADCHS_MODULE_ID index, 
        ADCHS_VREF_SOURCE voltageRefSelect,  	// voltage reference
        ADCHS_CHARGEPUMP_MODE chargePump,		// Charge pump enabled/disabled
        ADCHS_OUTPUT_DATA_FORMAT outputFormat,  // result format fractional
        bool stopInIdle,		  	        	// stop in idle
		ADCHS_FAST_SYNC_SYSTEM_CLOCK sysClk,	// Fast synchronous system clock  
		                                        // to ADC control clock
		ADCHS_FAST_SYNC_PERIPHERAL_CLOCK periClk,       // Fast synchronous peripheral 
		                                                // clock to ADC control clock
		ADCHS_INTERRUPT_BIT_SHIFT_LEFT intVectorShift,	// Interrupt vector shift bits
		uint16_t intVectorBase,					// Interrupt vector base address
        ADCHS_CLOCK_SOURCE adcClockSource, 		// clock source
        int8_t adcClockDivider,             	// clock divider
		ADCHS_WARMUP_CLOCK warmUpClock	        // Analog channel warm-up clocks.
	)
								
  Summary:
    Configures the High-Speed SAR ADC converter.

  Description:
    Configures all ADC parameters which are common to all ADC channels (from 0 to 7).  
	This configuration must occur prior to enabling the ADC and therefore must be 
	called when the ADC is disabled.

  Precondition:
    The ADCHS module is disabled when calling this function. 

  Parameters:
    index           			- Identifier for the ADCHS instance. 
    voltageRefSelect			- VREF Source Selection.
    chargePump					- Enables/ disables the charge pump. This variable 
								  is of ADCHS_CHARGEPUMP_MODE type. Use when 
								  VREFH - VREFL < .64 (AVDD - AVSS). This feature
								  is not available on all devices.
    outputFormat				- Sets output data format to be integer or fractional.
								  This parameter is of ADCHS_OUTPUT_DATA_FORMAT type.
    stopInIdle					- Sets ADC to stop when device is in Idle mode if true
	sysClk						- Sets the Fast synchronous system clock to ADC control clock.
								  This variable is of type ADCHS_FAST_SYNC_SYSTEM_CLOCK.
	periClk						- Sets the Fast synchronous peripheral clock to ADC control 
								  clock. This variable is of type ADCHS_FAST_SYNC_PERIPHERAL_CLOCK.
	intVectorShift				- Sets the interrupt vector shift left shift. This variable is of
								   ADCHS_INTERRUPT_BIT_SHIFT_LEFT type.
	intVectorBase				- Sets the interrupt vector base address.
    adcClockSource				- Clock source selection. This variable is of type ADCHS_CLOCK_SOURCE.
    adcClockDivider				- Clock source divider. Values range from 0 to 63. This divider
								  determines the input clock frequency which goes as input to 
								  all ADC channels (all ADC channels, 0 to 7). This clock is also
								  known as the "control clock" of ADC. The frequency of control
								  clock for ADC, as per the following equation:
								  Control clock frequency = (frequency of "adcClockSource")/(adcClockDivider * 2)
								  For adcClockDivider = 0, control clock frequency is same as frequency
								  of "adcClockSource".
	warmUpClock					- This parameter determines the number of channel clock (not control clock)
								  which is required as warm up time for the ADC channel, once the analog
								  feature of that ADC channel is enabled. The variable is of type
								  ADCHS_WARMUP_CLOCK.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.

    // Configure the ADC
    PLIB_ADCHS_Setup
	( 
		MY_ADCHS_INSTANCE,
		ADCHS_VREF_AVDD_AVSS,					// AVDD and AVSS as reference
		ADCHS_CHARGEPUMP_DISABLE,				// Charge pump is disabled
		ADCHS_OUTPUT_DATA_FORMAT_FRACTIONAL,	// Use fractional format
		true,		  							// Stop in idle
		ADCHS_FAST_SYNC_SYSTEM_CLOCK_ENABLE,	// Enable Fast synchronous system clock
		ADCHS_FAST_SYNC_PERIPHERAL_CLOCK_DISABLE, // Disable Fast synchronous peripheral clock
		ADCHS_INTERRUPT_BIT_SHIFT_LEFT_2_BITS,	// vector left shift set to 2
		0x1600,									// vector base address set to 0x1600
		ADCHS_CLOCK_SOURCE_SYSCLK, 				// SYSCLK is the clock source
		1,										// Control clock, TQ = 1/SYSCLK * 2
		ADCHS_WARMUP_CLOCK_32					// Warm-up up time = 32 clocks
	);

    // Enable the ADC
    PLIB_ADCHS_Enable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

void PLIB_ADCHS_Setup
( 
	ADCHS_MODULE_ID index, 
	ADCHS_VREF_SOURCE voltageRefSelect,
	ADCHS_CHARGEPUMP_MODE chargePump,
	ADCHS_OUTPUT_DATA_FORMAT outputFormat,
	bool stopInIdle,
	ADCHS_FAST_SYNC_SYSTEM_CLOCK sysClk,
	ADCHS_FAST_SYNC_PERIPHERAL_CLOCK periClk,
	ADCHS_INTERRUPT_BIT_SHIFT_LEFT intVectorShift,
	uint16_t intVectorBase,
	ADCHS_CLOCK_SOURCE adcClockSource,
	int8_t adcClockDivider,
	ADCHS_WARMUP_CLOCK warmUpClock
);


// ****************************************************************************
// ****************************************************************************
// Section: Interface functions for ADCHS channels
// ****************************************************************************
// ****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ChannelAnalogFeatureEnable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID
	)

  Summary:
    Enables the analog circuit for High-Speed SAR ADC channels.

  Description:
    This function enables (turns ON) the analog circuit for channels. The
	analog circuit can be disabled (when not required) to reduce current 
	consumption by the channel. Since, each channel has the feature to individually
	enable/disable the analog circuit, the unused channel's analog circuit
	can be disabled. When the analog circuit for a channel is enabled, it needs
	a minimum warm-up time before which the channel is ready to perform conversion.
	Once the channel analog feature (circuit) is enabled, its ready status can be
	check with PLIB_ADCHS_ChannelIsReady function.

  Precondition:
	The ADCHS module should be enabled before calling this function. The ADCHS module 
	can be enabled by calling the PLIB_ADCHS_Enable function.

  Parameters:
    index       - Identifier for the ADCHS instance to be configured.
	channelID   - ID of the required channel.	

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    PLIB_ADCHS_ChannelAnalogFeatureEnable(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1);
	
	// wait until the channel is ready
	while(!PLIB_ADCHS_ChannelIsReady(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1));
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ChannelAnalogFeatureEnable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ChannelAnalogFeatureDisable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID
	)

  Summary:
    Disables the analog circuit for channels of High-Speed SAR ADC.

  Description:
    This function disables (turns OFF) the analog circuit for channels.
	The analog circuit for unused channels can be disabled to reduce current
	consumption.

  Precondition:
    None.

  Parameters:
    index       - Identifier for the ADCHS instance to be configured.
	channelID   - ID of the required channel.	
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    PLIB_ADCHS_ChannelAnalogFeatureDisable(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ChannelAnalogFeatureDisable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);

//********************************************************************
/* Function:
    bool PLIB_ADCHS_ChannelIsReady
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID
	)
    
  Summary:
    Returns the state of the channel.
	
  Description:
    This function returns the state, indicating whether the channel is awake
	and ready after the warm-up time is complete. When a analog feature (circuit) 
	of a channel is enabled, there is a warm-up time required before the channel 
	is ready and can be used for conversion. The ready state of the channel can be
	acquired using this function.
	
  Precondition:
    The analog feature for the channel should be enabled using the
	PLIB_ADCHS_ChannelAnalogFeatureEnable function. Also, the ADCHS module 
	should be enabled before calling this function. 
	
  Input:
    index      		- Identifier for the ADCHS instance to be configured
	channelID   	- ID of the required channel	
	
  Returns:
    - true	- Channel is ready after warm-up time has elapsed
	- false	- Channel is not ready
	
  Example:
    <code>
	// Enable the analog feature for Channel 1
    PLIB_ADCHS_ChannelAnalogFeatureEnable(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1);
	
	// wait until the channel is ready
	while(!PLIB_ADCHS_ChannelIsReady(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1));
    </code>
	
  Remarks:
    None.                                                            
 */

bool PLIB_ADCHS_ChannelIsReady
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ChannelDigitalFeatureEnable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID
	)

  Summary:
    Enables (turns ON) the digital circuit for channels. 
	
  Description:
    This function enables (turns ON) the digital circuit for channels. 
	Unlike enabling the analog feature, enabling the digital feature does not
	require any warm-up time. 	

  Precondition:
 	The ADCHS module should be enabled before calling this function. The ADCHS 
	module can be enabled by calling PLIB_ADCHS_Enable function. Also, for the 
	channel to perform conversion, the analog features of the channel should be 
	enabled using PLIB_ADCHS_ChannelAnalogFeatureEnable, prior to enabling the 
	digital feature.	

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- ID of the required channel.	
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
	// Enable analog feature for Channel 1
    PLIB_ADCHS_ChannelAnalogFeatureEnable( MY_ADCHS_INSTANCE,
											ADCHS_CHANNEL_1 );
	
	// wait until channel is ready
	while(!PLIB_ADCHS_ChannelIsReady( MY_ADCHS_INSTANCE, 
										ADCHS_CHANNEL_1 ));

	// Enable the digital Channel 1
    PLIB_ADCHS_ChannelDigitalFeatureEnable( MY_ADCHS_INSTANCE,
											 ADCHS_CHANNEL_1 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ChannelDigitalFeatureEnable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ChannelDigitalFeatureDisable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID
	)

  Summary:
    Disables the digital circuit for channels of High-Speed SAR ADC.

  Description:
    This function disables (turns OFF) the digital circuit for channels. The
	digital feature (circuit) of unused channels can be disabled to reduce current
	consumption. The advantage of disabling the digital feature is that re-enabling
	the digital feature does not require any warm up time and the channel can be
	immediately used for conversion. 

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- ID of the required channel.	
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    PLIB_ADCHS_ChannelDigitalFeatureDisable( MY_ADCHS_INSTANCE,
											  ADCHS_CHANNEL_1 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ChannelDigitalFeatureDisable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);
		
//******************************************************************************
/* Function:
    void PLIB_ADCHS_ChannelSetup
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_CHANNEL_ID channelID, 						// channel ID 0 to 7
        ADCHS_DATA_RESOLUTION res,  						// Output data resolution
		uint8_t	channelClockDivider,						// Clock divider
		uint16_t sampleTimeCount,							// Sample time
		ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK earlyInterruptClk	// early interrupt clock setting
	)
								
  Summary:
    Configures the High-Speed SAR ADC channels.

  Description:
    This function configures all ADC parameters that are common to the specified 
	ADC Channel 0 to 7.
	
	This configuration must occur prior to enabling the ADC, and therefore, must be 
	called when the ADC is disabled. Also, this configuration must occur prior
	to enabling the digital circuit and analog bias circuit for the specified 
	ADC Channel 0 to 7.

  Precondition:
    The channel is disabled when calling this function. 

  Parameters:
    index           			- Identifier for the ADCHS instance.
	channelID					- Channel ID of the required ADC channel.
	res							- Sets the output data resolution.
	channelClockDivider			- Channel Clock source divider. Values range from 1 to 127.
								  This divider determines the channel clock (clock frequency
								  at which the channel 0 to 7 is running). The frequency of
								  channel clock, as per following equation:
								  Channel clock frequency = (control clock frequency)/(channelClockDivider * 2).
								  Please note that value of "0" for channelClockDivider is not
								  allowed. The minimum value of channelClockDivider is "1", which
								  also means that the highest channel clock frequency is half of
								  control clock frequency.
	sampleTimeCount				- Sets the sample time for ADC channel, 0 to 7. Values range from
								  0 to 1023. The sample time is given by the equation:
								  Sample time = ((1/Channel clock frequency) * (sampleTimeCount + 2)).
    earlyInterruptClk			- Sets the number of channel clocks prior to the availability of actual
                                  data that the early interrupt is generated. This variable
								  if of type ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK. The selection of this 
								  parameter is dependent on the resolution of output data.
	
  Returns:
    None.

  Example:
    <code>
	bool status = false;
	
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.

    // Configure the ADC
    PLIB_ADCHS_ChannelSetup( MY_ADCHS_INSTANCE,
			ADCHS_CHANNEL_1,						// channel - 1
            ADCHS_DATA_RESOLUTION_12BIT,			// resolution is set to 12bits
			1,										// channel clock divider bit is, TAD =  2 * TQ
			1,										// Sample time is 3 * TAD
			ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_1);	// Interrupt, 1 clock early

	status = PLIB_ADCHS_ChannelTriggerSampleSelect( MY_ADCHS_INSTANCE,
			ADCHS_CHANNEL_1,						// channel - 1
			ADCHS_CHANNEL_SYNC_SAMPLING);			// Synchronous sampling selected
			
	if( false == status)
	{
		// error has occurred
		while(1);
	}			
    // Enable the ADC
    PLIB_ADCHS_Enable(MY_ADCHS_INSTANCE);
	
	// Wait until the reference voltage is ready
	while(!PLIB_ADCHS_VREFIsReady(MY_ADCHS_INSTANCE));

	//Check if there is a fault in reference voltage
	if(PLIB_ADCHS_VREFFaultHasOccurred(MY_ADCHS_INSTANCE))
	{
		// process fault accordingly
		while(1);
	}

	// Enable the analog circuit
	PLIB_ADCHS_ChannelAnalogFeatureEnable(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1);

	// Wait until the channel wakes up after warm-up
	while(!PLIB_ADCHS_ChannelIsReady(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1));

	// Enable the digital circuit
	PLIB_ADCHS_ChannelDigitalFeatureEnable(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1);	
	
	// ADC will begin conversion now, after a valid trigger	
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

void PLIB_ADCHS_ChannelSetup
( 
	ADCHS_MODULE_ID index, 
	ADCHS_CHANNEL_ID channelID,
	ADCHS_DATA_RESOLUTION res,
	uint8_t	channelClockDivider,
	uint16_t sampleTimeCount,
	ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK earlyInterruptClk
);

//******************************************************************************
/* Function:
	bool PLIB_ADCHS_ChannelTriggerSampleSelect
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_CHANNEL_ID channelID,
		ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL sampSel
	)
								
  Summary:
    Selects the trigger and sampling modes for channels of High-Speed SAR ADC

  Description:
    The channels from 0 through 6 have features to select the trigger as presynchronized or
	unsynchronized. Also, the sampling can be selected as synchronous. This function
	provides the functionality to select the trigger and sampling for ADC channels.
	The valid channels for selecting trigger and sampling is 0 to 6. Channel 7 does
	not have the feature. Therefore, calling this function for Channel 7 will result
	in failure. This selection must occur prior to enabling the ADC and therefore must be 
	called when the ADC is disabled. Also, this selection must occur prior
	to enabling the digital circuit and analog bias circuit for the specified ADC channel.

  Precondition:
    The channel is disabled when calling this function. 

  Parameters:
    index           			- Identifier for the ADCHS instance.
	channelID					- Channel ID from 0 to 6.
	sampSel						- Sets the presync trigger or sync sampling options. This
								  variable is of type ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL.
	
  Returns:
    - true	- The function successfully selected the sampling and trigger mode
	- false	- The function could not select the sampling and trigger mode because Channel 7 was
			  selected and Channel 7 does not implement this feature

  Example:
    <code>
	bool status = false;
	
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.

    // Configure the ADC
    PLIB_ADCHS_ChannelSetup( MY_ADCHS_INSTANCE,
			ADCHS_CHANNEL_1,						// channel - 1
            ADCHS_DATA_RESOLUTION_12BIT,			// resolution is set to 12bits
			1,										// channel clock divider bit is, TAD =  2 * TQ
			1,										// Sample time is 3 * TAD
			ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_1);	// Interrupt, 1 clock early
			
	status = PLIB_ADCHS_ChannelTriggerSampleSelect( MY_ADCHS_INSTANCE,
			ADCHS_CHANNEL_1,						// channel - 1
			ADCHS_CHANNEL_SYNC_SAMPLING);			// Synchronous sampling selected
			
	if( false == status)
	{
		// error has occurred
		while(1);
	}
	
    // Enable the ADC
    PLIB_ADCHS_Enable(MY_ADCHS_INSTANCE);
	
	// Wait until the reference voltage is ready
	while(!PLIB_ADCHS_VREFIsReady(MY_ADCHS_INSTANCE));

	//Check if there is a fault in reference voltage
	if(PLIB_ADCHS_VREFFaultHasOccurred(MY_ADCHS_INSTANCE))
	{
		// process fault accordingly
		while(1);
	}

	// Enable the analog circuit
	PLIB_ADCHS_ChannelAnalogFeatureEnable(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1);

	// Wait until the channel wakes up after warm-up
	while(!PLIB_ADCHS_ChannelIsReady(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1));

	// Enable the digital circuit
	PLIB_ADCHS_ChannelDigitalFeatureEnable(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1);	
	
	// ADC will begin conversion now, after a valid trigger	
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

bool PLIB_ADCHS_ChannelTriggerSampleSelect
( 
	ADCHS_MODULE_ID index, 
	ADCHS_CHANNEL_ID channelID,
	ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL sampSel
);

// ****************************************************************************
// ****************************************************************************
// Section: Interface functions specific to analog inputs
// ****************************************************************************
// ****************************************************************************

// *****************************************************************************			
//*****************************************************************************
/*
  Function:
    void PLIB_ADCHS_AnalogInputModeSelect
	(	
		ADCHS_MODULE_ID index,
        ADCHS_AN_INPUT_ID analogInput,
        ADCHS_INPUT_MODE mode
	)
    
  Summary:
    Selects the mode for the specified analog input.
	
  Description:
    This function selects the mode (single ended or differential) and encoding 
	(unipolar or two's compliment) for the specified analog input.
	
	When selecting the mode of analog input which is meant to be alternate 
	input for an ADC channel, the default analog input ID should be passed to this 
	function.
	
	For example, for CHANNEL_0, the default analog input is AN0 and the alternate 
	analog input is AN45. If the mode for AN45 needs to be changed, the default 
	input ID (i.e., AN0) should be passed.
	
  Precondition:
    None.
	
  Input:
    index 			- Identifier for the ADCHS instance
    analogInput    	- Analog input ID for which the input mode is to be selected. It
					  is of type ADCHS_AN_INPUT_ID.
    mode  			- An ADCHS_INPUT_MODE type indicating the mode selection
	
  Returns:
    None.
	
  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Set AN10 and AN11 to use the single ended, two's complement mode
    // selection.
    PLIB_ADCHS_AnalogInputModeSelect(MY_ADCHS_INSTANCE, 
                           ADCHS_AN10,
                           ADCHS_INPUT_MODE_SINGLE_ENDED_TWOS_COMP);
						   
    PLIB_ADCHS_AnalogInputModeSelect(MY_ADCHS_INSTANCE, 
                           ADCHS_AN11,
                           ADCHS_INPUT_MODE_SINGLE_ENDED_TWOS_COMP);						   
    </code>
	
  Remarks:
    None.                                                                     
 */

void PLIB_ADCHS_AnalogInputModeSelect
(	
	ADCHS_MODULE_ID index,
	ADCHS_AN_INPUT_ID analogInput,
	ADCHS_INPUT_MODE mode
);
							 
//*****************************************************************************
/*
  Function:
    ADCHS_INPUT_MODE PLIB_ADCHS_AnalogInputModeGet
	( 
		ADCHS_MODULE_ID index,
        ADCHS_AN_INPUT_ID analogInput 
	)
    
  Summary:
    Returns the mode for the specified analog input.
	
  Description:
    This function returns the mode (single ended or differential) and encoding 
	(unipolar or two's compliment) for the specified analog input.
	
	When getting the mode of analog input which is meant to be alternate 
	input for an ADC channel, the default analog input ID should be passed to this 
	function.
	
	For example, for CHANNEL_0, the default analog input is AN0 and alternate 
	analog input is AN45. If the mode for AN45 needs to be obtained, the default 
	input ID (i.e., AN0) should be passed.
	
  Precondition:
    None.
	
  Input:
    index 			- Identifier for the ADCHS instance
    analogInput    	- An analog input selection of type ADCHS_AN_INPUT_ID

  Returns:
	Mode of the selected analog input of type ADCHS_INPUT_MODE type.
	
  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
	// Declare a variable of type "ADCHS_INPUT_MODE"
	ADCHS_INPUT_MODE mode;
	
    // Get mode for AN10
    mode = PLIB_ADCHS_AnalogInputModeGet(MY_ADCHS_INSTANCE, ADCHS_AN10);
    </code>
	
  Remarks:
    None.                                                                     
 */

ADCHS_INPUT_MODE PLIB_ADCHS_AnalogInputModeGet
( 
	ADCHS_MODULE_ID index,
	ADCHS_AN_INPUT_ID analogInput 
);
							 
// *****************************************************************************
/* Function:
    void PLIB_ADCHS_AnalogInputDataReadyInterruptEnable
	(
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput 
	)

  Summary:
    Enables the data ready interrupt for the selected analog input.

  Description:
    This function enables (turns ON) the data ready interrupt for the selected 
	analog input. The interrupt is generated when the converted data is ready 
	for the selected analog input.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Enable interrupt for AN10 and AN11
    PLIB_ADCHS_AnalogInputDataReadyInterruptEnable(MY_ADCHS_INSTANCE, ADCHS_AN10);
    PLIB_ADCHS_AnalogInputDataReadyInterruptEnable(MY_ADCHS_INSTANCE, ADCHS_AN11);	
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_AnalogInputDataReadyInterruptEnable
(
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_AnalogInputDataReadyInterruptDisable
	(
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput 
	)

  Summary:
    Disables the data ready interrupt for the selected analog inputs.

  Description:
    This function disables (turns OFF) the data ready interrupt for the selected 
	analog input. 

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Disable interrupt for AN10 and AN11
    PLIB_ADCHS_AnalogInputDataReadyInterruptDisable(MY_ADCHS_INSTANCE, ADCHS_AN10);
    PLIB_ADCHS_AnalogInputDataReadyInterruptDisable(MY_ADCHS_INSTANCE, ADCHS_AN11);	
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_AnalogInputDataReadyInterruptDisable
(
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput 
);						 

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_AnalogInputScanSelect
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput 
	)

  Summary:
    Selects the analog input for scanning.

  Description:
    This function selects the analog input for scanning.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Select for AN10 and AN11 for scanning
    PLIB_ADCHS_AnalogInputScanSelect(MY_ADCHS_INSTANCE, ADCHS_AN10);
    PLIB_ADCHS_AnalogInputScanSelect(MY_ADCHS_INSTANCE, ADCHS_AN11);	
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_AnalogInputScanSelect
( 
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_AnalogInputScanRemove
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput 
	)

  Summary:
    Removes the analog input from scanning selection.

  Description:
    This function removes the analog input for scanning queue. Therefore, the analog
	input is no longer used for scanning.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Remove AN10 and AN11 from scanning
    PLIB_ADCHS_AnalogInputScanRemove(MY_ADCHS_INSTANCE, ADCHS_AN10);
    PLIB_ADCHS_AnalogInputScanRemove(MY_ADCHS_INSTANCE, ADCHS_AN11);	
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_AnalogInputScanRemove
( 
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput 
);

// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_AnalogInputScanIsSelected
	( 
		ADCHS_MODULE_ID index,
		ADCHS_AN_INPUT_ID analogInput
	)

  Summary:
    Returns whether or note an analog input is selected for scanning.

  Description:
    This function returns whether or not an analog input is included in the 
	scanning queue.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    - true			- Analog input is in selected for scanning
	- false			- Analog input is not selected for scanning

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
	// Determine if AN10 is selected for scanning or not
	if(PLIB_ADCHS_AnalogInputScanIsSelected(MY_ADCHS_INSTANCE, ADCHS_AN10)  == true)
	{
		// Perform further operations
	}
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_AnalogInputScanIsSelected
( 
	ADCHS_MODULE_ID index,
	ADCHS_AN_INPUT_ID analogInput
);

// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_AnalogInputDataIsReady
	( 
		ADCHS_MODULE_ID index,
		ADCHS_AN_INPUT_ID analogInput
	)

  Summary:
    Returns the data ready status of analog inputs.

  Description:
    This function returns if the converted data is ready for the analog input.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.	
	
  Returns:
    - true			- Converted data is ready for selected analog input
	- false			- Conversion is not yet complete and data is not ready

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.

	// Check if data is ready for AN10
	if(PLIB_ADCHS_AnalogInputDataIsReady(MY_ADCHS_INSTANCE, ADCHS_AN10) == true)
	{
		// Do further processing
	}
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_AnalogInputDataIsReady
( 
	ADCHS_MODULE_ID index,
	ADCHS_AN_INPUT_ID analogInput
);	

//******************************************************************************
/* Function:
   uint32_t PLIB_ADCHS_AnalogInputResultGet
   ( 
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput 
	)

  Summary:
    Returns a ADC conversion result.

  Description:
    This function returns the converted result for the specified analog input.

  Precondition:
    A valid conversion is ready to be fetched. 
	
  Parameters:
    index   - Identifier for the ADCHS instance.
    analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    The conversion result expressed as a 32-bit integer. 

  Example:
    <code>
    uint32_t		result;
    //...
	
	// Check if data is ready for AN10
	if(PLIB_ADCHS_AnalogInputDataIsReady(MY_ADCHS_INSTANCE, ADCHS_AN10))
	{
		result = PLIB_ADCHS_AnalogInputResultGet( MY_ADCHS_INSTANCE, ADCHS_AN10 );
	}	
    </code>

  Remarks:
    None.
 */

uint32_t PLIB_ADCHS_AnalogInputResultGet
( 
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput 
);	

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_AnalogInputLevelTriggerSet
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_CLASS12_AN_INPUT_ID analogInput 
	)

  Summary:
    Sets the trigger as level sensitive for selected Class 1 and 2 analog input.

  Description:
    This function sets the trigger as level sensitive for selected Class 1 and 2 
	analog input.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID. Since the
					  trigger level can be selected only for Class 1 and 2 analog inputs.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Set for AN5 and AN6 for level trigger
    PLIB_ADCHS_AnalogInputLevelTriggerSet( MY_ADCHS_INSTANCE, ADCHS_CLASS12_AN5 );
	PLIB_ADCHS_AnalogInputLevelTriggerSet( MY_ADCHS_INSTANCE, ADCHS_CLASS12_AN6 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_AnalogInputLevelTriggerSet
( 
	ADCHS_MODULE_ID index, 
	ADCHS_CLASS12_AN_INPUT_ID analogInput 
);		

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_AnalogInputEdgeTriggerSet
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_CLASS12_AN_INPUT_ID analogInput
	)

  Summary:
    Sets the trigger as edge sensitive for selected class 1 and 2 analog input.

  Description:
    This function sets the trigger as edge sensitive for selected Class 1 and 2 
	analog input.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID. Since the
					  trigger level can be selected only for Class 1 and 2 analog inputs.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Set for AN10 and AN11 for edge trigger
    PLIB_ADCHS_AnalogInputEdgeTriggerSet( MY_ADCHS_INSTANCE, ADCHS_CLASS12_AN10 );
	PLIB_ADCHS_AnalogInputEdgeTriggerSet( MY_ADCHS_INSTANCE, ADCHS_CLASS12_AN11 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_AnalogInputEdgeTriggerSet
( 
	ADCHS_MODULE_ID index, 
	ADCHS_CLASS12_AN_INPUT_ID analogInput
);

//****************************************************************************
/*  Function:
    void PLIB_ADCHS_AnalogInputTriggerSourceSelect
	( 
		ADCHS_MODULE_ID index,
        ADCHS_CLASS12_AN_INPUT_ID inputId,
        ADCHS_TRIGGER_SOURCE triggerSource
	)
    
  Summary:
    Selects a trigger Source for analog input (Class 1 or Class 2 analog inputs
	only).
	
  Description:
    This function selects the trigger source for Class 1 or Class 2 inputs. A call 
    to this function is not required when the input is being used as part of an
    analog input scan, as the input scan configure function also configures all
    trigger sources.
	
  Precondition:
    The function only applies to Class 1 and Class 2 inputs.
	
  Parameters:
    index   		-  Identifier for the ADCHS instance.
    inputId 	    -  Class 1 or Class 2 input trigger to be configured.
    triggerSource 	-  Trigger source to use for this input of type ADCHS_TRIGGER_SOURCE.
	
  Returns:
    None.
	
  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Configure AN4 for triggering from INT0.
    PLIB_ADCHS_AnalogInputTriggerSourceSelect( MY_ADCHS_INSTANCE, 
									  ADCHS_CLASS12_AN4,
                                      ADCHS_TRIGGER_SOURCE_INT0 );
    </code>
	
  Remarks:
    None.                                                                    
 */

void PLIB_ADCHS_AnalogInputTriggerSourceSelect
( 
	ADCHS_MODULE_ID index,
	ADCHS_CLASS12_AN_INPUT_ID inputId,
	ADCHS_TRIGGER_SOURCE triggerSource
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_AnalogInputEarlyInterruptEnable
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput
	)

  Summary:
    Enables the early interrupt for the analog input.

  Description:
    This function enables (turns ON) the early interrupt for the selected analog input.
	The	interrupt is generated at a set number of clock prior to conversion complete.
	The number of clock for early interrupt is set using the "configure" function for
	a specific channel.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Enable interrupt for AN10 and AN11
    PLIB_ADCHS_AnalogInputEarlyInterruptEnable(MY_ADCHS_INSTANCE, ADCHS_AN10);
	PLIB_ADCHS_AnalogInputEarlyInterruptEnable(MY_ADCHS_INSTANCE, ADCHS_AN11);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_AnalogInputEarlyInterruptEnable
( 
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput
);	

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_AnalogInputEarlyInterruptDisable
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput
	)

  Summary:
    Disables the early interrupt for the analog input.

  Description:
    This function disables (turns OFF) the early interrupt for the selected 
	analog input.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Disable interrupt for AN10 and AN11
    PLIB_ADCHS_AnalogInputEarlyInterruptDisable(MY_ADCHS_INSTANCE, ADCHS_AN10);
	PLIB_ADCHS_AnalogInputEarlyInterruptDisable(MY_ADCHS_INSTANCE, ADCHS_AN11);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_AnalogInputEarlyInterruptDisable
( 
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput
);

// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_AnalogInputEarlyInterruptIsReady
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput
	)

  Summary:
    Returns the early interrupt ready status of analog input.

  Description:
    This function returns the status of early interrupt for the selected analog
	input.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    - true			- Early interrupt event is ready
	- false			- Early interrupt event has not occurred

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
	
	// Check if early interrupt is ready for AN10
	if(PLIB_ADCHS_AnalogInputEarlyInterruptIsReady(MY_ADCHS_INSTANCE, ADCHS_AN10))
	{
		// Do further processing
	}
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_AnalogInputEarlyInterruptIsReady
( 
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput
);


// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_AnalogInputIsAvailable
	(
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput
	)
	

  Summary:
    Returns the analog input configuration of ADCHS channel.

  Description:
    This function returns the if the selected analog input is available
	in the ADCHS channel.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID.
	
  Returns:
    - true			- Selected analog input is available.
	- false			- Selected analog input is not available in the ADCHS channel.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	

	// Check if AN10 is available in the ADCHS channel
	if(PLIB_ADCHS_AnalogInputIsAvailable(MY_ADCHS_INSTANCE, ADCHS_AN10))
	{
		// do further processing
	}
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_AnalogInputIsAvailable
(
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput
);



	
// ****************************************************************************
// ****************************************************************************
// Section: Interface functions for Digital comparator functionality
// ****************************************************************************
// ****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalComparatorAnalogInputSelect
	( 
		ADCHS_MODULE_ID index,
		ADCHS_DIGITAL_COMPARATOR_ID digComparator,
		ADCHS_AN_INPUT_ID analogInput 
	)

  Summary:
    Selects analog inputs, whose converted data will be processed by the comparator.

  Description:
    This function selects the analog input, whose converted data (once available)
	will be processed by the specified digital comparator. This function should be
	called only when the comparator is in a disabled state.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	digComparator	- Digital comparator ID of type ADCHS_DIGITAL_COMPARATOR_ID.
	analogInput		- An analog input selection of type ADCHS_AN_INPUT_ID. The 
					  valid input range for "analogInput" is from ADCHS_AN0 to 
					  ADCHS_AN31. Values from ADCHS_AN32 and higher will be ignored.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Set digital comparator 2 to process the output of AN2
    PLIB_ADCHS_DigitalComparatorAnalogInputSelect( MY_ADCHS_INSTANCE, 
										ADCHS_DIGITAL_COMPARATOR_2, ADCHS_AN2);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalComparatorAnalogInputSelect
( 
	ADCHS_MODULE_ID index,
	ADCHS_DIGITAL_COMPARATOR_ID digComparator,
	ADCHS_AN_INPUT_ID analogInput 
);
			
// *****************************************************************************
/* Function:
    ADCHS_AN_INPUT_ID PLIB_ADCHS_DigitalComparatorAnalogInputGet
	( 
		ADCHS_MODULE_ID index,
		ADCHS_DIGITAL_COMPARATOR_ID digComparator 
	)

  Summary:
    Returns the analog input ID used by the digital comparator.

  Description:
    This function returns the analog input ID, whose converted data is being
	compared by the specified digital comparator. In a typical application, when a 
	comparator event is recorded, the application will need to know the analog input 
	which caused the event. This function returns the value of type ADCHS_AN_INPUT_ID, 
	indicating the analog input ID.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance.
	digComparator	- Digital comparator ID of type ADCHS_DIGITAL_COMPARATOR_ID.
	
  Returns:
    An analog input ID of type ADCHS_AN_INPUT_ID.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
	ADCHS_AN_INPUT_ID input;

    // Get analog input tied to digital comparator 2
    input = PLIB_ADCHS_DigitalComparatorAnalogInputGet( MY_ADCHS_INSTANCE, ADCHS_DIGITAL_COMPARATOR_2 );
    </code>

  Remarks:
    None.
 */

ADCHS_AN_INPUT_ID PLIB_ADCHS_DigitalComparatorAnalogInputGet
( 
	ADCHS_MODULE_ID index,
	ADCHS_DIGITAL_COMPARATOR_ID digComparator 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalComparatorEnable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_DIGITAL_COMPARATOR_ID digComparator 
	)

  Summary:
    Enables the specified digital comparator.

  Description:
    This function enables (turns ON) the specified digital comparator.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	digComparator	- Digital comparator of type ADCHS_DIGITAL_COMPARATOR_ID.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    PLIB_ADCHS_DigitalComparatorEnable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_COMPARATOR_2);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalComparatorEnable
( 
	ADCHS_MODULE_ID index,
	ADCHS_DIGITAL_COMPARATOR_ID digComparator 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalComparatorDisable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_DIGITAL_COMPARATOR_ID digComparator 
	)

  Summary:
    Disables the specified digital comparator.

  Description:
    This function disables (turns OFF) the specified digital comparator.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	digComparator	- Digital comparator of type ADCHS_DIGITAL_COMPARATOR_ID.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    PLIB_ADCHS_DigitalComparatorDisable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_COMPARATOR_2);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalComparatorDisable
( 
	ADCHS_MODULE_ID index,
	ADCHS_DIGITAL_COMPARATOR_ID digComparator 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalComparatorInterruptEnable
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_COMPARATOR_ID digComparator 
	)

  Summary:
    Enables the interrupt for the selected digital comparator.

  Description:
    This function enables (turns ON) the interrupt for the selected digital comparator.
	The	interrupt is generated when the converted analog data for the related analog
	input goes out of the specified limits (set for comparator).

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	digComparator	- Digital comparator of type ADCHS_DIGITAL_COMPARATOR_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable interrupt for comparator 2
    PLIB_ADCHS_DigitalComparatorInterruptEnable( MY_ADCHS_INSTANCE, ADCHS_DIGITAL_COMPARATOR_2 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalComparatorInterruptEnable
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_COMPARATOR_ID digComparator 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalComparatorInterruptDisable
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_COMPARATOR_ID digComparator 
	)

  Summary:
    Disables the interrupt for the selected digital comparator.

  Description:
    This function disables (turns OFF) the interrupt for the selected digital comparator.
	The	interrupt will not be generated, once a comparator event occurs.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	digComparator	- Digital comparator of type ADCHS_DIGITAL_COMPARATOR_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable interrupt for comparator 2
    PLIB_ADCHS_DigitalComparatorInterruptDisable( MY_ADCHS_INSTANCE, ADCHS_DIGITAL_COMPARATOR_2 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalComparatorInterruptDisable
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_COMPARATOR_ID digComparator 
);

//***************************************************************************************
/*
  Function:
    void PLIB_ADCHS_DigitalComparatorSetup
	( 
		ADCHS_MODULE_ID index, 				// ADCHS channel ID
        ADCHS_DIGITAL_COMPARATOR_ID id,     // Comparator ID
        bool intEnable,  					// Int Enable
        bool inBetweenOrEqual,				// between low and high
        bool greaterEqualHi,  				// greater than equal to high
        bool lessThanHi,      				// less than high
        bool greaterEqualLo,   				// greater than equal to low
        bool lessThanLo,       				// less than low
        ADCHS_AN_INPUT_ID analogInput, 		// input enable bits
        int16_t  hiLimit,      				// high limit
        int16_t  loLimit     				// low limit
	)

  Summary:
    Configures the Digital Comparator on the High-Speed SAR ADC converter.
	
  Description:
    This function configures all parameters for the Digital Comparator of 
	the ADCHS module.
	
  Precondition:
    The module is disabled when calling this function.
	
  Parameters:
    index    		 -  Identifier for the ADCHS instance.
    id 		 		 -  Identifier for the digital comparator specified.
	intEnable  		 -  When true, comparator events generates interrupt.
    inBetweenOrEqual -  Event is generated when result is greater than or equal to
                        loLimit and less than hiLimit.
    greaterEqualHi 	 -  Event is generated when result is greater than or equal to
                        hiLimit.
    lessThanHi 		 -  Event is generated when result is less than hiLimit.
    greaterEqualLo 	 -  Event is generated when result is greater than or equal to
                        loLimit.
    lessThanLo 		 -  Event is generated when result is less than loLimit.
    analogInput 	 -  An analog input selection of type ADCHS_AN_INPUT_ID. The 
						valid input range for "analogInput" is from ADCHS_AN0 to
						ADCHS_AN31. Values from ADCHS_AN32 and higher will be ignored.
    hiLimit 		 -  High limit in the same format as the conversion result.
    loLimit 		 -  Low limit in the same format as the conversion result.
	
  Returns:
    None.
	
  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Configure the Digital Comparator
    // Creates an event when the reading of AN3 is between 20% to 80% of the
    // full scale 12-bit output.
    PLIB_ADCHS_DigitalComparatorSetup( MY_ADCHS_INSTANCE,  	// ADCHS module ID
                          ADCHS_DIGITAL_COMPARATOR_1,   	// Comparator ID
                          false,            				// No Int Enable
                          true,         					// test for between low and high
                          false,            				// no test for greater than equal to high
                          false,            				// no test for less than high
                          false,            				// no test for greater than equal to low
                          false,            				// no test for less than low
                          ADCHS_AN3,						// select AN3
                          0x0CCD,           				// high limit, 80% of full scale
                          0x0333);      					// low limit, 20% of full scale
    
    // Enable Digital Comparator 1
    PLIB_ADCHS_DigitalComparatorEnable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_COMPARATOR_1);
    </code>
	
  Remarks:
    This function must be called when the ADC is disabled.          
    The format of hiLimit and loLimit must match the output format of analog input specified in 
	analogInput.     
 */

void PLIB_ADCHS_DigitalComparatorSetup
( 
	ADCHS_MODULE_ID index,
	ADCHS_DIGITAL_COMPARATOR_ID id,
	bool intEnable,
	bool inBetweenOrEqual,
	bool greaterEqualHi,
	bool lessThanHi,
	bool greaterEqualLo,
	bool lessThanLo,
	ADCHS_AN_INPUT_ID analogInput,
	int16_t  hiLimit,
	int16_t  loLimit
);

// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_DigitalComparatorEventHasOccurred
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_COMPARATOR_ID id 
	)

  Summary:
    Returns the status of the selected digital comparator.

  Description:
    This function returns the status of the selected digital comparator, whether or 
	not an event related to this comparator has occurred. A comparator event will occur
	if the analog input selected for the comparator is outside the set limits.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance.
	id 		 		- Identifier for the digital comparator in this device.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
	// Check, if comparator event has occurred for digital comparator 2
	if(PLIB_ADCHS_DigitalComparatorEventHasOccurred( MY_ADCHS_INSTANCE, ADCHS_DIGITAL_COMPARATOR_2 ))
	{
		// Perform related tasks
	}
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_DigitalComparatorEventHasOccurred
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_COMPARATOR_ID id 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalComparatorLimitSet
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_COMPARATOR_ID id,
		int16_t  hiLimit,
		int16_t  loLimit 
	)		

  Summary:
    Sets the limit for the specified digital comparator.

  Description:
    This function sets the high and low limits for the specified digital comparator.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance.
	id 		 		-  Identifier for the digital comparator in this device.
	hiLimit 		-  High limit in the same format as the conversion result.
    loLimit 		-  Low limit in the same format as the conversion result.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
    
    // Configure the Digital Comparator
    // Creates an event when the reading of AN3 is between 20% to 80% of the
    // full scale 12-bit output.
    PLIB_ADCHS_DigitalComparatorLimitSet( MY_ADCHS_INSTANCE,  	// ADCHS module ID
                          ADCHS_DIGITAL_COMPARATOR_1,   		// Comparator ID
                          0x0CCD,           					// high limit, 80% of full scale
                          0x0333);      						// low limit, 20% of full scale
    

    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalComparatorLimitSet
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_COMPARATOR_ID id,
	int16_t  hiLimit,
	int16_t  loLimit 
);
			


// ****************************************************************************
// ****************************************************************************
// Section: Interface functions for Digital Filter functionality
// ****************************************************************************
// ****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalFilterEnable
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_FILTER_ID id 
	)

  Summary:
    Enables the Digital Filter.

  Description:
    This function enables (turns ON) the selected Digital Filter.

  Precondition:
    The ADC channel should be configured using the PLIB_ADCHS_Setup
    function prior to enabling.

  Parameters:
    index           - Identifier for the ADCHS instance.
    id				- Identifier for the digital Filter in the ADCHS channel.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable Digital Filter-1
    PLIB_ADCHS_DigitalFilterEnable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalFilterEnable
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_FILTER_ID id 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalFilterDisable
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_FILTER_ID id 
	)

  Summary:
    Disables the Digital Filter.

  Description:
    This function Disables (turns OFF) the selected Digital Filter.

  Precondition:
    None.. 

  Parameters:
    index           - Identifier for the ADCHS instance.
    id				- Identifier for the Digital Filter in the ADCHS channel.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable Digital Filter 1
    PLIB_ADCHS_DigitalFilterDisable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalFilterDisable
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_FILTER_ID id 
);

//******************************************************************************
/* Function:
	void PLIB_ADCHS_DigitalFilterOversamplingModeSetup
	( 
		ADCHS_MODULE_ID index, 							// ADCHS ID
		ADCHS_DIGITAL_FILTER_ID id,	   					// Filter ID
		ADCHS_AN_INPUT_ID analogInput,					// analog input ID
		ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length,	// Significant data bit
		ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio, 	// Oversampling ratio
		bool intEnable   								// Int Enable
	)

  Summary:
    Configures the Digital Filter on the High-Speed SAR ADC converter in
	Oversampling mode.

  Description:
    This function configures the Digital Filter on the High-Speed SAR ADC 
	converter in Oversampling mode.

  Precondition:
    The Digital Filter channel is disabled when calling this function. 

  Parameters:
    index       	- Identifier for the ADCHS instance. 
    id				- Identifier for the Digital Filter in this device.
    analogInput		- Identifier for the analog input to be filtered.
	length			- Sets the significant data length.
	ratio			- Sets the oversampling filter ratio. This variable is of
					  type ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO.
    intEnable		- When set, Filter events generated interrupt.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Configure the Digital Filter in Oversampling mode
    // AN4 is oversampled at a 16X rate.  No global interrupt is enabled. 
    PLIB_ADCHS_DigitalFilterOversamplingModeSetup( MY_ADCHS_INSTANCE, 			// ADCHS module ID
                                   ADCHS_DIGITAL_FILTER_1,						// Filter ID
                                   ADCHS_AN4,		    						// Oversample AN4
								   ADCHS_DIGITAL_FILTER_SIGNIFICANT_ALL_16BITS,	// all 16bits significant
                                   ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_16X,	// 16 x oversampling
                                   false );										// No Int Enable

    // Enable Digital Filter-1
    PLIB_ADCHS_DigitalFilterEnable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1);
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

void PLIB_ADCHS_DigitalFilterOversamplingModeSetup
( 
	ADCHS_MODULE_ID index,
	ADCHS_DIGITAL_FILTER_ID id,
	ADCHS_AN_INPUT_ID analogInput,
	ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length,
	ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio,
	bool intEnable
);

//******************************************************************************
/* Function:
	void PLIB_ADCHS_DigitalFilterAveragingModeSetup
	( 
		ADCHS_MODULE_ID index, 							 // ADCHS module ID
		ADCHS_DIGITAL_FILTER_ID id,	   					 // Filter ID
		ADCHS_AN_INPUT_ID analogInput,					 // analog input ID
		ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length,	 // Significant data bit
		ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count, // Sample count
		bool intEnable   								 // Int Enable
	)

  Summary:
    Configures the Digital Filter on the High-Speed SAR ADC converter in
	Averaging mode.

  Description:
    This function configures the Digital Filter on the High-Speed SAR ADC converter 
	in Averaging mode.

  Precondition:
    The Digital Filter is disabled when calling this function. 

  Parameters:
    index       	- Identifier for the ADCHS instance. 
    id				- Identifier for the Digital Filter in this device.
    analogInput		- Identifier for the analog input to be filtered.
	length			- Sets the significant date length.
	count			- Sets the number of samples which will be averaged by
					  Digital Filter. This variable is of type.
					  ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT.
    intEnable		- When set, Filter events generated interrupt.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Configure the Digital Filter in Averaging mode
    // AN4 is averaged with 64 samples.  No global interrupt is enabled. 
    PLIB_ADCHS_DigitalFilterAveragingModeSetup( MY_ADCHS_INSTANCE, 				 // ADCHS module ID
                                   ADCHS_DIGITAL_FILTER_1,						 // Filter ID
                                   ADCHS_AN4,		    						 // Oversample AN4
								   ADCHS_DIGITAL_FILTER_SIGNIFICANT_ALL_16BITS,	 // all 16bits significant
                                   ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_64, // 64 samples averaged
                                   false );										 // No Int Enable

    // Enable Digital Filter-1
    PLIB_ADCHS_DigitalFilterEnable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1);
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

void PLIB_ADCHS_DigitalFilterAveragingModeSetup
( 
	ADCHS_MODULE_ID index,
	ADCHS_DIGITAL_FILTER_ID id,
	ADCHS_AN_INPUT_ID analogInput,
	ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length,
	ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count,
	bool intEnable
);

//******************************************************************************
/* Function:
	void PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect
	( 
		ADCHS_MODULE_ID index, 						// ADCHS module ID
		ADCHS_DIGITAL_FILTER_ID id,	   				// Filter ID
		ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio // Oversampling ratio
	)

  Summary:
    Selects the oversampling ratio for the Digital Filter.

  Description:
    This function selects the oversampling ratio for the Digital Filter. This function 
	can be used to change the oversampling ratio of the Digital Filter, when set in 
	Oversampling mode.

  Precondition:
    The Digital Filter is disabled when calling this function. 

  Parameters:
    index       	- Identifier for the ADCHS instance. 
    id				- Identifier for the Digital Filter in this device.
	ratio			- Sets the oversampling filter ratio. This variable is of
					  type ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
	// Disable Digital Filter
	PLIB_ADCHS_DigitalFilterDisable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1);
	
    // Select the oversampling ratio
    PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect( MY_ADCHS_INSTANCE, 	// ADCHS module ID
                                   ADCHS_DIGITAL_FILTER_1,						// Filter ID
                                   ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_16X);	// 16 x oversampling


    // Enable Digital Filter-1
    PLIB_ADCHS_DigitalFilterEnable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1);
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

void PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect
( 
	ADCHS_MODULE_ID index,
	ADCHS_DIGITAL_FILTER_ID id,
	ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio
);

//******************************************************************************
/* Function:
	void PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect
	( 
		ADCHS_MODULE_ID index, 								// ADCHS module ID
		ADCHS_DIGITAL_FILTER_ID id,	   						// Filter ID
		ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count 	// Sample count
	)

  Summary:
    Selects the number of samples which are averaged by the Digital Filter.

  Description:
    This function selects the number of samples which are averaged by the 
	Digital Filter, when the Digital Filter is configured for Averaging mode.

  Precondition:
    The Digital Filter is disabled when calling this function. 

  Parameters:
    index       	- Identifier for the ADCHS instance. 
    id				- Identifier for the Digital Filter in this device.
	count			- Sets the number of samples which will be averaged by
					  the Digital Filter. This variable is of type.
					  ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
	// Disable Digital Filter
	PLIB_ADCHS_DigitalFilterDisable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1);
	
    // Select the sample count to be 64 samples
    PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect( MY_ADCHS_INSTANCE,		// ADCHS module ID
                                   ADCHS_DIGITAL_FILTER_1,							// Filter ID
								   ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_64);	// 64 samples averaged

    // Enable Digital Filter-1
    PLIB_ADCHS_DigitalFilterEnable(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1);
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

void PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect
( 
	ADCHS_MODULE_ID index,
	ADCHS_DIGITAL_FILTER_ID id,
	ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count
);

//******************************************************************************
/* Function:
    bool PLIB_ADCHS_DigitalFilterDataIsReady
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_FILTER_ID id 
	)

  Summary:
    Used to determine if the Digital Filter has data ready.  

  Description:
    This function can be used to determine if the ADCHS Digital Filter has data ready. 
	A 'true' is returned when data is available, which can be fetched using 
	PLIB_ADCHS_DigitalFilterDataGet.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCHS instance. 
    id				- Identifier for the Digital Filter in this device.
	
  Returns:
    - true			- Digital Filter has filtered data ready to be read 
	- false			- Digital Filter data is not yet ready

  Example:
    <code>
    if (PLIB_ADCHS_DigitalFilterDataIsReady(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1)) {
                // fetch and process data
        }
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_DigitalFilterDataIsReady
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_FILTER_ID id 
);
						
//******************************************************************************
/* Function:
    int16_t PLIB_ADCHS_DigitalFilterDataGet
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_FILTER_ID dfltrID 
	)

  Summary:
    Used to fetch the data result from the Digital Filter.

  Description:
    This function is used to fetch data from the Digital Filter.  


  Precondition:
    This function will function only if the Digital Filter was already
	configured (in Oversampling mode or Averaging mode) and the Digital Filter
	was enabled.
	
  Parameters:
    index           - Identifier for the ADCHS instance. 
    dfltrID			- Identifier for the Digital Filter in this device.
	
  Returns:
    A 16-bit result in the format specified by the filter's configuration
	setting.

  Example:
    <code>
    int16_t myDFLTRResult;
	
    if (PLIB_ADCHS_DigitalFilterDataIsReady(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1)) {
        // fetch data
        myDFLTRResult = PLIB_ADCHS_DigitalFilterDataGet(MY_ADCHS_INSTANCE, ADCHS_DIGITAL_FILTER_1);
        // process result
        ...
    }
    </code>

  Remarks:
    None.
 */

int16_t PLIB_ADCHS_DigitalFilterDataGet
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_FILTER_ID dfltrID 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_FILTER_ID digFilter 
	)

  Summary:
    Enables the interrupt for the selected Digital Filter.

  Description:
    This function enables (turns ON) the interrupt for the selected Digital Filter.
	The	interrupt is generated when the Digital Filter completes the filtering and 
	data is ready in the register (to be read).

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	digFilter		- Digital Filter of type ADCHS_DIGITAL_FILTER_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable interrupt for filter - 2
    PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable( MY_ADCHS_INSTANCE, ADCHS_DFLTR2 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_FILTER_ID digFilter 
);	

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_DIGITAL_FILTER_ID digFilter 
	)

  Summary:
    Disables the interrupt for the selected Digital Filter.

  Description:
    This function disables (turns OFF) the interrupt for the selected Digital Filter.
	The	interrupt will not be generated, once filter data is ready.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	digFilter		- Digital Filter of type ADCHS_DIGITAL_FILTER_ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable interrupt for filter 2
    PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable( MY_ADCHS_INSTANCE, ADCHS_DFLTR2 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable
( 
	ADCHS_MODULE_ID index, 
	ADCHS_DIGITAL_FILTER_ID digFilter 
);

// ****************************************************************************
// ****************************************************************************
// Section: Interface functions for FIFO functionality
// ****************************************************************************
// ****************************************************************************

//******************************************************************************
/* Function:
    int32_t PLIB_ADCHS_FIFORead( ADCHS_MODULE_ID index )

  Summary:
    Used to fetch the data result from the FIFO.

  Description:
    This function is used to fetch data from the FIFO. The FIFO can only be 
	assigned to a Class 1 ADC analog input.

  Precondition:
    The FIFO should have data ready to be read from it.

  Parameters:
    index           - Identifier for the ADCHS instance. 
	
  Returns:
    A 32-bit result in the format specified by the ADC configuration for the module
	using the FIFO.

  Example:
    <code>
    int32_t myFIFOResult;
	
    if (PLIB_ADCHS_FIFODataIsAvailable(MY_ADCHS_INSTANCE)) {
        // fetch data
        myDFLTRResult = PLIB_ADCHS_FIFORead(MY_ADCHS_INSTANCE);
        // process result
        ...
    }
    </code>

  Remarks:
    None.
 */

int32_t PLIB_ADCHS_FIFORead( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    bool PLIB_ADCHS_FIFODataIsAvailable( ADCHS_MODULE_ID index )

  Summary:
    Used to determine if the FIFO has data ready.  

  Description:
    Used to determine if the ADCHS FIFO has data ready. A 'true' is returned when 
	data is available, which can be fetched using PLIB_ADCHS_FIFORead.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCHS instance. 
	
  Returns:
    Boolean:
	- true 		- If data is ready
	- false		- If data is not ready

  Example:
    <code>
    if (PLIB_ADCHS_FIFODataIsAvailable(MY_ADCHS_INSTANCE)) {
                // fetch and process data
        }
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_FIFODataIsAvailable(ADCHS_MODULE_ID index);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_FIFODataReadyInterruptEnable( ADCHS_MODULE_ID index ) 

  Summary:
    Enables the interrupt for FIFO.

  Description:
    This function enables (turns ON) the interrupt for FIFO.
	The	interrupt is generated when the FIFO has data to be read.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable interrupt for FIFO
    PLIB_ADCHS_FIFODataReadyInterruptEnable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_FIFODataReadyInterruptEnable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_FIFODataReadyInterruptDisable( ADCHS_MODULE_ID index ) 

  Summary:
    Disables the interrupt for FIFO.

  Description:
    This function disables (turns OFF) the interrupt for FIFO.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable interrupt for FIFO
    PLIB_ADCHS_FIFODataReadyInterruptDisable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_FIFODataReadyInterruptDisable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_FIFOEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables the FIFO in the High-Speed SAR ADC

  Description:
    This function enables (turns ON) the FIFO.

  Precondition:
    None. 

  Parameters:
    index           - Identifier for the ADCHS instance.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable FIFO
    PLIB_ADCHS_FIFOEnable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_FIFOEnable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_FIFODisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the FIFO in the High-Speed SAR ADC.

  Description:
    This function disables (turns OFF) the FIFO.

  Precondition:
    None. 

  Parameters:
    index           - Identifier for the ADCHS instance.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable FIFO
    PLIB_ADCHS_FIFODisable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_FIFODisable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_FIFOSourceSelect
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 		// Channel ID from 0 to 6
	)

  Summary:
    Sets the Channel 0 to 6 using the FIFO.

  Description:
    This function sets the Channel 0 to 6 ID, which would be storing data into FIFO.
	If this function is called with Channel ID as 7, the function will return an error.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- Channel ID from 0 to 6.
	
  Returns:
    - true	- The function successfully selected the FIFO source
	- false	- The function could not select the FIFO source, as selected
			  Channel is 7, which does not implement this feature

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
	// Set Channel 1 to be storing data into FIFO
    if(!PLIB_ADCHS_FIFOSourceSelect( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 ))
	{
		// error has occurred
		while(1);
	}
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_FIFOSourceSelect
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);

// *****************************************************************************
/* Function:
    uint8_t PLIB_ADCHS_FIFODataCountGet( ADCHS_MODULE_ID index )

  Summary:
    Returns the number of data to be read from FIFO.

  Description:
    This function returns the number of data which can be read from FIFO.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    The number of the data stored in the FIFO.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
	// variable to save data
	uint32_t convData;
	
	// Check, if FIFO has some data
	while(!PLIB_ADCHS_FIFODataIsAvailable(MY_ADCHS_INSTANCE));
	
	// Once data is available, check if the data belongs to channel ID -1
	if(PLIB_ADCHS_FIFOSourceGet(MY_ADCHS_INSTANCE) == ADCHS_CHANNEL_1)
	{
		// Continue reading FIFO, until the count is zero
		while(PLIB_ADCHS_FIFODataCountGet(MY_ADCHS_INSTANCE) != 0)
		{
			// Read from FIFO. For each read, the count is decremented
			convData = PLIB_ADCHS_FIFORead(MY_ADCHS_INSTANCE);
		}
	}
	</code>

  Remarks:
    None.
 */

uint8_t PLIB_ADCHS_FIFODataCountGet( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    ADCHS_CHANNEL_ID PLIB_ADCHS_FIFOSourceGet( ADCHS_MODULE_ID index )

  Summary:
    Returns the channel ID using the FIFO.

  Description:
    This function returns the channel ID of Channel 0 to 6, whose data is stored 
	on the FIFO.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    The Channel ID of data type ADCHS_CHANNEL_ID.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
	// variable to save data
	uint32_t convData;
	
	// Check, if FIFO has some data
	while(!PLIB_ADCHS_FIFODataIsAvailable(MY_ADCHS_INSTANCE));
	
	// Once data is available, check if the data belongs to channel ID -1
	if(PLIB_ADCHS_FIFOSourceGet(MY_ADCHS_INSTANCE) == ADCHS_CHANNEL_1)
	{
		// Continue reading FIFO, until the count is zero
		while(PLIB_ADCHS_FIFODataCountGet(MY_ADCHS_INSTANCE) != 0)
		{
			// Read from FIFO. For each read, the count is decremented
			convData = PLIB_ADCHS_FIFORead(MY_ADCHS_INSTANCE);
		}
	}
	</code>

  Remarks:
    None.
 */

ADCHS_CHANNEL_ID PLIB_ADCHS_FIFOSourceGet( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    bool PLIB_ADCHS_FIFOErrorHasOccurred( ADCHS_MODULE_ID index )

  Summary:
    Used to determine if the FIFO has encountered an overflow error.  

  Description:
    This function can be used to determine if the ADCHS FIFO had a data, which was 
	overwritten by the next round of a FIFO write (overflow error). A 'true' is returned 
	when an overflow error has occurred.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCHS instance. 
	
  Returns:
	- true			- An error has occurred
	- false			- No error occurred has in the FIFO

  Example:
    <code>
    if (!PLIB_ADCHS_FIFOErrorHasOccurred(MY_ADCHS_INSTANCE)) {
                // process data, if overflow error did not occur
        }
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_FIFOErrorHasOccurred( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    bool PLIB_ADCHS_FIFODataIsNegative( ADCHS_MODULE_ID index )

  Summary:
    Returns the sign of data stored in FIFO.  

  Description:
    This function returns the sign of data stored in the FIFO.

  Precondition:
    None.

  Parameters:
    index       - Identifier for the ADCHS instance.
	
  Returns:
    Boolean:
	- true		- If sign is negative
	- false		- If sign is not negative

  Example:
    <code>
    if (PLIB_ADCHS_FIFODataIsNegative(MY_ADCHS_INSTANCE)) {
                //process data
        }
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_FIFODataIsNegative( ADCHS_MODULE_ID index );



// ****************************************************************************
// ****************************************************************************
// Section: Interface functions for DMA functionality
// ****************************************************************************
// ****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DMAEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables the DMA in the High-Speed SAR ADC module.

  Description:
    This function enables (turns ON) the DMA in the High-Speed SAR ADC module.

  Precondition:
    None. 

  Parameters:
    index           - Identifier for the ADCHS instance.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable DMA
    PLIB_ADCHS_DMAEnable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DMAEnable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DMADisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the DMA in the High-Speed SAR ADC module.

  Description:
    This function disables (turns OFF) the DMA in the High-Speed SAR ADC module.

  Precondition:
    None. 

  Parameters:
    index           - Identifier for the ADCHS instance.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable DMA
    PLIB_ADCHS_DMADisable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_DMADisable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
	void PLIB_ADCHS_DMASetup
	( 
		ADCHS_MODULE_ID index, 							// ADCHS module ID
		ADCHS_DMA_BUFFER_LENGTH bufferLengthBytes,		// Buffer length
		uint32_t baseAddress,							// Base address for data
		ADCHS_DMA_COUNT countMode,						// Enable/ Disable count
		uint32_t countBaseAddress 						// Base address for count
	)
							

  Summary:
    Configures the DMA on the High-Speed SAR ADC.

  Description:
    This functin configures all parameters for the DMA of the High-Speed SAR ADC.

  Precondition:
    The ADC channel and the Channel 0 to 6 using DMA are disabled. 

  Parameters:
    index       		- Identifier for the ADCHS instance. 
	bufferLengthBytes	- Length of DMA Buffer in number of bytes. Buffer is saved on RAM.
						  The variable is of type ADCHS_DMA_BUFFER_LENGTH.
	baseAddress			- Address of RAM, which holds the buffer.
	countMode			- Enable/ Disable the DMA feature to keep count of number of 
						  converted data saved by DMA.
	countBaseAddress	- Address of RAM, which holds the counts.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Configure the DMA
	void PLIB_ADCHS_DMASetup( 	MY_ADCHS_INSTANCE,			    // ADCHS module ID
								ADCHS_DMA_BUFFER_LENGTH_8BYTES,	// buffer length is 8 Bytes	
								0xA002,							// Base address is 0xA002
								ADCHS_DMA_COUNT_ENABLE,			// count is enabled
								0xC400	);						// Count base address is 0xC400

    // Enable DMA
    PLIB_ADCHS_DMAEnable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

void PLIB_ADCHS_DMASetup
( 
	ADCHS_MODULE_ID index,
	ADCHS_DMA_BUFFER_LENGTH bufferLengthBytes,
	uint32_t baseAddress,
	ADCHS_DMA_COUNT countMode,
	uint32_t countBaseAddress
);
						
// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_DMASourceEnable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 		// Channel ID 0 to 6
	)

  Summary:
    Enables the DMA for the specified Channel 0 to 6.

  Description:
    This function enables (turns ON) the DMA for specified Channel 0 to 6.
	If selected Channel is 7, this function return error.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- Channel ID from 0 to 6.
	
  Returns:
    - true	- The function successfully selected the DMA source
	- false	- The function could not select the DMA source, as selected
			  Channel is 7, which does not implement this feature

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // DMA for Channel 1
    if(!PLIB_ADCHS_DMASourceEnable( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 ))
	{
		// error
		while(1);
	}
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_DMASourceEnable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);

// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_DMASourceDisable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 		// Channel ID 0 to 6
	)

  Summary:
    Disables the DMA for the specified Channel 0 to 6.

  Description:
    This function disables (turns OFF) the DMA for specified Channel 0 to 6.
	If Channel 7 is selected, this function returns error.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- Channel ID from 0 to 6.
	
  Returns:
    - true	- The function successfully removed the DMA source
	- false	- The function could not remove the DMA source, as selected
			  Channel is 7, which does not implement this feature

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // DMA for Channel 1
    if(!PLIB_ADCHS_DMASourceDisable( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 ))
	{
		// error
		while(1);
	}
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_DMASourceDisable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);					

// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_DMABuffer_A_InterruptEnable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 		// Channel ID 0 to 6
	)

  Summary:
    Enables the DMA Buffer A full interrupt for the specified Channel 0 to 6.

  Description:
    This function enables (turns ON) the DMA Buffer A full interrupt for the 
	specified Channel 0 to 6. The interrupt is generated when the DMA buffer A 
	is full. Since Channel 7 does not implement this feature, passing Channel 7 
	will result in an error.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- Channel ID from 0 to 6.
	
  Returns:
    - true	- The function successfully enabled interrupt
	- false	- The function could not enable the interrupt, as the selected Channel 
	          is 7, which does not implement this feature

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable DMA interrupt
    PLIB_ADCHS_DMABuffer_A_InterruptEnable( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 );
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_DMABuffer_A_InterruptEnable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);

// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_DMABuffer_A_InterruptDisable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 		// Channel ID 0 to 6
	)

  Summary:
    Disables the DMA Buffer A full interrupt for the specified Channel 0 to 6.

  Description:
    This function disables (turns OFF) the DMA Buffer A full interrupt for the 
	specified  Channel 0 to 6. Since Channel 7 does not implement this feature, 
	passing Channel 7 will result in an error.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- Channel ID from 0 to 6.
	
  Returns:
    - true	- The function successfully disabled interrupt
	- false	- The function could not disable the interrupt, as the selected
			  Channel is 7, which does not implement this feature

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable DMA interrupt
    PLIB_ADCHS_DMABuffer_A_InterruptDisable( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 );
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_DMABuffer_A_InterruptDisable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);
						
// *****************************************************************************
/* Function:
    void PLIB_ADCHS_DMABuffer_B_InterruptEnable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 	// Channel ID 0 to 6
	)

  Summary:
    Enables the DMA Buffer B full interrupt for the specified Channel 0 to 6.

  Description:
    This function enables (turns ON) the DMA Buffer B full interrupt for specified 
	Channel 0 to 6. The interrupt is generated when the DMA Buffer B is full.
	Since Channel 7 does not implement this feature, passing Channel 7 will 
	result in an error.	

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- Channel ID from 0 to 6.
	
  Returns:
    - true	- The function successfully enabled interrupt
	- false	- The function could not enable the interrupt, as the selected
			  Channel is 7, which does not implement this feature

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable DMA interrupt
    PLIB_ADCHS_DMABuffer_B_InterruptEnable( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 );
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_DMABuffer_B_InterruptEnable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);

// *****************************************************************************
/* Function:
    bool PLIB_ADCHS_DMABuffer_B_InterruptDisable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 		// Channel ID 0 to 6
	)

  Summary:
    Disables the DMA Buffer B full interrupt for the specified Channel 0 to 6.

  Description:
    This function disables (turns OFF) the DMA Buffer B full interrupt for specified 
	Channel 0 to 6. Since Channel 7 does not implement this feature, passing Channel 7 will 
	result in an error.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- Channel ID from 0 to 6.
	
  Returns:
    - true	- The function successfully disabled interrupt
	- false	- The function could not disable the interrupt, as the selected
			  Channel is 7, which does not implement this feature

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable DMA interrupt
    PLIB_ADCHS_DMABuffer_B_InterruptDisable( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 );
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_DMABuffer_B_InterruptDisable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);

//******************************************************************************
/* Function:
    int8_t PLIB_ADCHS_DMABuffer_A_IsFull
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_CHANNEL_ID channelID 		// channel ID 0 to 6
	)

  Summary:
    Used to determine if the DMA Buffer A is full, for the specified Channel 0 to 6.

  Description:
    This function can be used to determine if the ADCHS DMA Buffer A is full for the 
	specified Channel 0 to 6.
	
	A value of '1' is returned when the Buffer A is full. A value of '0' is returned when the
	Buffer A is empty.
	
	This feature is not implemented for Channel 7. Therefore, passing Channel 7 
	returns an error.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCHS instance.
	channelID		- Channel ID from 0 to 6.
	
  Returns:
    * 1				- Buffer is full
	* 0				- Buffer is empty
	* -1			- Invalid channel ID passed

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    if (1 == PLIB_ADCHS_DMABuffer_A_IsFull(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 )) 
	{
		// process data, if DMA Buffer A is full
    }
    </code>

  Remarks:
    None.
 */

int8_t PLIB_ADCHS_DMABuffer_A_IsFull
( 
	ADCHS_MODULE_ID index, 
	ADCHS_CHANNEL_ID channelID
);
					
//******************************************************************************
/* Function:
    int8_t PLIB_ADCHS_DMABuffer_B_IsFull
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_CHANNEL_ID channelID 		// Channel ID 0 to 6
	)

  Summary:
    Used to determine if the DMA Buffer B is full, for the specified Channel 0 to 6.

  Description:
    This functino is used to determine if the ADCHS DMA Buffer B is full for the specified 
	Channel 0 to 6.
	
	A value of '1' is returned when Buffer B is full. A value of '0' is returned when 
	Buffer B is empty.
	
	This feature is not implemented for Channel 7. Therefore, passing Channel 7 
	returns an error.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCHS instance. 
	channelID		- Channel ID from 0 to 6.
	
  Returns:
    - 1				- Buffer is full
	- 0				- Buffer is empty
	- -1			- Invalid channel ID passed

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    if (1 == PLIB_ADCHS_DMABuffer_B_IsFull(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 )) 
	{
		// process data, if DMA Buffer B is full
    }
    </code>

  Remarks:
    None.
 */

int8_t PLIB_ADCHS_DMABuffer_B_IsFull
( 
	ADCHS_MODULE_ID index, 
	ADCHS_CHANNEL_ID channelID
);	

//******************************************************************************
/* Function:
    bool PLIB_ADCHS_DMAOverflowErrorHasOccurred( ADCHS_MODULE_ID index )

  Summary:
    Used to determine if the DMA Buff had an overflow error.

  Description:
    DMA Buffers are circular in nature. If reading the data from DMA buffer is 
	slower as compared to filling the buffer, the newer data will overwrite
	the previous data (before the data is read). This function returns 'true' if an
	overflow error has occurred.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCHS instance 
	
  Returns:
    Boolean:
    - true		- If an overflow error occurred
	- false		- If an overflow error has not occurred

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    if (PLIB_ADCHS_DMAOverflowErrorHasOccurred(MY_ADCHS_INSTANCE) 
	{
		// Error occurred
		while(1);
    }
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_DMAOverflowErrorHasOccurred( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    uint32_t PLIB_ADCHS_ChannelConfigurationGet
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 	// Channel ID
	)

  Summary:
    Used to get the configuration for the specified channel.

  Description:
    This functions returns the configuration for the specified channel.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCHS instance.
	channelID		- Channel ID.
	
  Returns:
    32-bit value of the configuration for ADCHS channel.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
	uint32_t config;
	
	config = PLIB_ADCHS_ChannelConfigurationGet(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1);
		
    </code>

  Remarks:
    None.
 */

uint32_t PLIB_ADCHS_ChannelConfigurationGet
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);
					
//******************************************************************************
/* Function:
    void PLIB_ADCHS_ChannelConfigurationSet
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID, 
		uint32_t config 
	)

  Summary:
    Used to set the configuration for the specified channel.

  Description:
    This functions sets the configuration for the specified channel.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCHS instance.
	channelID		- Channel ID.
	config			- 32-bit value for the configuration of channel.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
	uint32_t config = 0x12345678;
	
	PLIB_ADCHS_ChannelConfigurationSet(MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1, config);
		
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ChannelConfigurationSet
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID, 
	uint32_t config 
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ChannelIsReadyInterruptEnable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 				// channel ID
	)

  Summary:
    Enables the Channel ready interrupt for the specified channel.

  Description:
    This function enables (turns ON) the channel ready interrupt for the specified 
	channel. The interrupt is generated when the channel is ready after wake-up 
	(following warm-up time).

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- Channel ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable wakeup interrupt for Channel 1
    PLIB_ADCHS_ChannelIsReadyInterruptEnable( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ChannelIsReadyInterruptEnable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);
				
// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ChannelIsReadyInterruptDisable
	( 
		ADCHS_MODULE_ID index,
		ADCHS_CHANNEL_ID channelID 				// channel ID
	)

  Summary:
    Disables the Channel ready interrupt for the specified channel.

  Description:
    This function disables (turns OFF) the channel ready interrupt for the specified 
	channel.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	channelID		- Channel ID.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable wakeup interrupt for Channel 1
    PLIB_ADCHS_ChannelIsReadyInterruptDisable( MY_ADCHS_INSTANCE, ADCHS_CHANNEL_1 );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ChannelIsReadyInterruptDisable
( 
	ADCHS_MODULE_ID index,
	ADCHS_CHANNEL_ID channelID
);	


//******************************************************************************
/* Function:
    void PLIB_ADCHS_AnalogInputScanSetup
	( 	
		ADCHS_MODULE_ID index, 
		ADCHS_AN_INPUT_ID analogInput, 
		ADCHS_SCAN_TRIGGER_SENSITIVE trgSensitive,
        ADCHS_SCAN_TRIGGER_SOURCE triggerSource
	)

  Summary:
    Selects input to include in Analog Input Scan mode.

  Description:
    Selects inputs, as determined by the low and high enable scan list for 
    inclusion in the analog input scan sequence. If the input is a Class 1 or
    Class 2 type, it will also select the trigger source for that input
    to be the scan trigger, which is required if included in analog input scanning.
	This function configures the scan functionality with a single ADC input.
	If more inputs are required to be added for scanning, the 
	PLIB_ADCHS_AnalogInputScanSelect function should be used.
	
  Precondition:
    None.

  Parameters:
    index           		- Identifier for the ADCHS instance. 
	analogInput				- An analog input selection of type ADCHS_AN_INPUT_ID.
	trgSensitive			- Enables level/edge sensitive scan trigger.
    triggerSource   		- Trigger source used to initiate analog input scan.
	
  Returns:
    None.  

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Configure analog input Scanning
    // Analog inputs 10 through 13
    // Trigger on Timer 1 match.
	
    PLIB_ADCHS_AnalogInputScanSetup(MY_ADCHS_INSTANCE, 
								   ADCHS_AN10,
								   ADCHS_SCAN_TRIGGER_SENSITIVE_EDGE,	// Edge sensitive
                                   ADCHS_SCAN_TRIGGER_SOURCE_TMR1_MATCH);
								   
    PLIB_ADCHS_AnalogInputScanSelect(MY_ADCHS_INSTANCE, ADCHS_AN11);
	PLIB_ADCHS_AnalogInputScanSelect(MY_ADCHS_INSTANCE, ADCHS_AN12);
	PLIB_ADCHS_AnalogInputScanSelect(MY_ADCHS_INSTANCE, ADCHS_AN13);
	
    </code>

  Remarks:
	None.
 */

void PLIB_ADCHS_AnalogInputScanSetup
( 	
	ADCHS_MODULE_ID index, 
	ADCHS_AN_INPUT_ID analogInput,
	ADCHS_SCAN_TRIGGER_SENSITIVE trgSensitive,
	ADCHS_SCAN_TRIGGER_SOURCE triggerSource
);

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_VREFReadyInterruptEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables the VREF ready interrupt.

  Description:
    This function enables (turns ON) the VREF ready interrupt. 
	The interrupt is generated when the Band gap voltage/VREF is ready to
	be used by the ADCHS instance.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable VREF ready interrupt
    PLIB_ADCHS_VREFReadyInterruptEnable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_VREFReadyInterruptEnable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_VREFReadyInterruptDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the VREF ready interrupt.

  Description:
    This function disables (turns OFF) the VREF ready interrupt. 

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable VREF interrupt
    PLIB_ADCHS_VREFReadyInterruptDisable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_VREFReadyInterruptDisable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_VREFFaultInterruptEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables the VREF fault interrupt.

  Description:
    This function enables (turns ON) the VREF fault interrupt. 
	The interrupt is generated when a fault is encountered with VREF (mostly
	by BOR of the analog supply).

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable VREF fault interrupt
    PLIB_ADCHS_VREFFaultInterruptEnable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_VREFFaultInterruptEnable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_VREFFaultInterruptDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the VREF Fault interrupt.

  Description:
    This function disables (turns OFF) the VREF Fault interrupt. 

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable VREF fault interrupt
    PLIB_ADCHS_VREFFaultInterruptDisable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_VREFFaultInterruptDisable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ScanCompleteInterruptEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables the end of scan interrupt.

  Description:
    This function enables (turns ON) the end of scan interrupt. 
	The interrupt is generated when scanning of all of the selected analog inputs 
	has completed.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable EOS interrupt
    PLIB_ADCHS_ScanCompleteInterruptEnable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ScanCompleteInterruptEnable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ScanCompleteInterruptDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the end of scan interrupt.

  Description:
    This function disables (turns OFF) the end of scan interrupt.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable EOS interrupt
    PLIB_ADCHS_ScanCompleteInterruptDisable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ScanCompleteInterruptDisable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ExternalConversionRequestEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables the external conversion request.

  Description:
    This function enables (turns ON) the external conversion request. 
	Once enabled, the ADCHS can accept conversion request from external sources 
	such as the PTG module.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Enable external conversion request
    PLIB_ADCHS_ExternalConversionRequestEnable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ExternalConversionRequestEnable( ADCHS_MODULE_ID index );

// *****************************************************************************
/* Function:
    void PLIB_ADCHS_ExternalConversionRequestDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the external conversion request.

  Description:
    This function disables (turns OFF) the external conversion request. 
	Once disabled, the external sources such as PTG cannot request a
	conversion.

  Precondition:
    None.

  Parameters:
    index      		- Identifier for the ADCHS instance to be configured.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Disable external conversion request
    PLIB_ADCHS_ExternalConversionRequestDisable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ExternalConversionRequestDisable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_GlobalSoftwareTriggerEnable( ADCHS_MODULE_ID index )

  Summary:
    Initiate a Global Software Trigger.  

  Description:
    All inputs or scan list that is configured to trigger on the global 
    software trigger are triggered. Once enabled, the trigger automatically
	gets disabled (edge sensitive).

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_GlobalSoftwareTriggerEnable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_GlobalSoftwareTriggerEnable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable( ADCHS_MODULE_ID index )

  Summary:
    Initiates a global level software trigger.  

  Description:
    This function initiates a global level software trigger. All inputs or the scan list 
	configured to trigger on the global level software trigger are triggered. Once initiated, 
	the trigger continues until the global level trigger is disabled using the function PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the global level software trigger.  

  Description:
    This function disables the global level software trigger on the specified
	channel.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_TriggerSuspendEnable( ADCHS_MODULE_ID index )

  Summary:
    Suspends all trigger for all ADCHS channels. 

  Description:
    This function suspends all triggers for all channels on the ADCHS module. The 
	trigger needs to be suspended so that the channels could be configured without 
	disabling (and subsequently enabling) the channels.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_TriggerSuspendEnable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_TriggerSuspendEnable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_TriggerSuspendDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables trigger suspend.

  Description:
    By calling this function, all triggers are allowed to reach the channel and
	triggers are not suspended.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_TriggerSuspendDisable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_TriggerSuspendDisable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables the update-ready interrupt.  

  Description:
    Once the triggers are suspended, the ADC channel raises an update ready flag 
	indicating that the updates to ADCHS registers can be performed. This function 
	enables the interrupt which occurs once the flag is raised.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptEnable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptEnable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the update-ready interrupt.  

  Description:
    This function disables the update-ready interrupt.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptDisable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptDisable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    bool PLIB_ADCHS_ControlRegistersCanBeUpdated( ADCHS_MODULE_ID index )

  Summary:
    Returns the status of update-ready.  

  Description:
    Once the triggers are suspended, the ADCHS raises an update-ready flag 
	indicating that the updates to ADCHS registers can be performed. This function
	returns the status of update ready.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    - true		- The ADCHS module can be safely updated (settings can be configured)
	- false		- The ADCHS module is not yet ready to be safely updated

  Example:
    <code>
	// Suspend trigger
	PLIB_ADCHS_TriggerSuspendEnable(MY_ADCHS_INSTANCE);
	
	// Wait until the channel registers can be updated
	while(!PLIB_ADCHS_ControlRegistersCanBeUpdated(MY_ADCHS_INSTANCE));
	
	// Once the function returns true, update the configurations of ADCHS
	//....
	
	// Enable triggers
	PLIB_ADCHS_TriggerSuspendDisable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCHS_ControlRegistersCanBeUpdated( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_SoftwareSamplingStart( ADCHS_MODULE_ID index )

  Summary:
    Enables sampling of analog input for Channel 7.  

  Description:
    This function can be used if Channel 7 needs to be brought to Sampling mode 
	manually (i.e., through software).

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_SoftwareSamplingStart(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_SoftwareSamplingStart( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_SoftwareSamplingStop( ADCHS_MODULE_ID index )

  Summary:
    Disables sampling of analog input for Channel 7, which places Channel 7 into 
	Hold mode.

  Description:
    After sampling for a significant time (using the function
	PLIB_ADCHS_SoftwareSamplingStart), the sampling can be disabled,
	which will bring the channel to Hold mode.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_SoftwareSamplingStop(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_SoftwareSamplingStop( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_SoftwareConversionStart( ADCHS_MODULE_ID index )

  Summary:
    Triggers the conversion of analog input signal connected to Channel 7.  

  Description:
    After a signal is held on the S&H of Channel 7, the conversion
	can be triggered manually using software by using this function.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_SoftwareConversionStart(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_SoftwareConversionStart( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_SoftwareConversionInputSelect
	( 
		ADCHS_MODULE_ID index,
		ADCHS_AN_INPUT_ID anInput 
	)

  Summary:
    Selects the analog input of Channel 7 for manual conversion.  

  Description:
    This function selects the analog input for Channel 7, which is
	used for manual conversion (using software control).

  Precondition:
    None.

  Parameters:
    index    	- Identifier for the ADCHS instance. 
	anInput		- Analog input of type ADCHS_AN_INPUT_ID.
	
  Returns:
    None.

  Example:
    <code>
	// Select AN24 for manual conversion
    PLIB_ADCHS_SoftwareConversionInputSelect(MY_ADCHS_INSTANCE, ADCHS_AN24);
	
	// Place S&H into Sampling mode
	PLIB_ADCHS_SoftwareSamplingStart(MY_ADCHS_INSTANCE);
	
	// Wait for the required sampling time
	int del;
	for(del = 0; del<=20; del++);
	
	// Now, make the S&H into Hold mode
	PLIB_ADCHS_SoftwareSamplingStop(MY_ADCHS_INSTANCE);
	
	// Now, start conversion
	PLIB_ADCHS_SoftwareConversionStart(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_SoftwareConversionInputSelect
( 
	ADCHS_MODULE_ID index,
	ADCHS_AN_INPUT_ID anInput 
);

//******************************************************************************
/* Function:
    bool PLIB_ADCHS_ChannelInputSelect
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_CHANNEL_ID channelID,
		ADCHS_CHANNEL_INP_SEL sel 
	)

  Summary:
    Selects the analog input for Channel 0 to 6.

  Description:
    Selects the analog input for Channel 0 to 6. The inputs for Channel 0 to 6
	can be changed between different inputs. This feature is not available for
	Channel 7; therefore, calling this function for Channel 7 will result in an 
	error. Also, the input selected should match the ones available for the 
	selected channel. Selecting an input which is not available for the channel 
	will return an error.
	
  Precondition:
    None.

  Parameters:
    index   	- Identifier for the ADCHS instance. 
	channelID	- Channel ID.
	sel			- Selection of inputs of type ADCHS_CHANNEL_INP_SEL.
	
  Returns:
    - true	- The function successfully selected the analog input for the channel
	- false	- The function could not select the input, as selected channel is 7, 
	          which does not implement this feature. Otherwise, the selected analog 
			  input is not available for the selected channel.

  Example:
    <code>
	bool status = false;
	
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Set Channel-0 to use the first input.
    status = PLIB_ADCHS_ChannelInputSelect
						(
							MY_ADCHS_INSTANCE, 
							ADCHS_CHANNEL_0, 
							ADCHS_CHANNEL_0_DEFAULT_INP_AN0
						);

	if(false == status)
	{
		// error
		while(1);
	}
    </code>

  Remarks:
    None. 
 */

bool PLIB_ADCHS_ChannelInputSelect
( 
	ADCHS_MODULE_ID index, 
	ADCHS_CHANNEL_ID channelID,
	ADCHS_CHANNEL_INP_SEL sel 
);

// ****************************************************************************
// ****************************************************************************
// Section: Interface functions for CVD functionality
// ****************************************************************************
// ****************************************************************************

//******************************************************************************
/* Function:
    void PLIB_ADCHS_CVDEnable( ADCHS_MODULE_ID index )

  Summary:
    Enables the CVD feature.
	
  Description:
    ADCHS channel supports the Capacitive Voltage Divider (CVD) mode. This function
	enables the CVD feature of an ADCHS instance.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_CVDEnable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_CVDEnable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_CVDDisable( ADCHS_MODULE_ID index )

  Summary:
    Disables the CVD feature.
	
  Description:
    This function disables the CVD feature of an ADCHS instance.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCHS instance. 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCHS_CVDDisable(MY_ADCHS_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCHS_CVDDisable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_ADCHS_CVDSetup
	( 
		ADCHS_MODULE_ID index, 
		ADCHS_CVD_CAPACITOR capSel,		// Input capacitor
		bool inBetweenOrEqual,			// between low and high
		bool greaterEqualHi,  			// greater than equal to high
		bool lessThanHi,      			// less than high
		bool greaterEqualLo,   			// greater than equal to low
		bool lessThanLo,       			// less than low
		ADCHS_AN_INPUT_ID inputEnable, 	// input enable bit
		int16_t  hiLimit,      			// high limit
		int16_t  loLimit      			// low limit								
	)

  Summary:
    Configures the CVD related setting of ADCHS channel.

  Description:
    While selecting the CVD mode, the internal capacitor should be similar
	in magnitude to the external capacitor being sensed. This function
	configures the internal capacitance. Additionally, the functions sets the
	limits for CVD measurement and the condition to detect a touch event.
	Since, CVD is implemented with digital comparator 0, using the CVD
	functionality also needs that digital comparator is enabled.
	
  Precondition:
    None.

  Parameters:
    index           		- Identifier for the ADCHS instance. 
	capSel					- Selection of value of input capacitor of type ADCHS_CVD_CAPACITOR.
    inBetweenOrEqual 		-  Event is generated when result is greater than or equal to
							   loLimit and less than hiLimit.
    greaterEqualHi 	 		-  Event is generated when result is greater than or equal to
							   hiLimit.
    lessThanHi 		 		-  Event is generated when result is less than hiLimit.
    greaterEqualLo 	 		-  Event is generated when result is greater than or equal to
							   loLimit.
    lessThanLo 		 		-  Event is generated when result is less than loLimit.
    inputEnable 	 		-  Bit field which determines which analog inputs are tested by
							   this comparator. This parameter is of type ADCHS_AN_INPUT_ID.
    hiLimit 		 		-  High limit in the same format as the conversion result.
    loLimit 		 		-  Low limit in the same format as the conversion result.	
	
  Returns:
    None.  

  Example:
    <code>
    // Where MY_ADCHS_INSTANCE, is the ADCHS instance selected for use by the
    // application developer.
	
    // Configure the CVD mode
    // Creates an event when the reading of AN3 is between 20% to 80% of the
    // full scale 12-bit output. This will be the touch event.
	
    PLIB_ADCHS_CVDSetup(	MY_ADCHS_INSTANCE,
							  ADCHS_CVD_CAPACITOR_5PF,
							  false,         	// no test for between low and high
							  true,             // Once touch event occurs, CVD output will
												// be higher than the set limits
							  false,            // no test for less than high
							  false,            // no test for greater than equal to low
							  false,            // no test for less than low
							  ADCHS_AN3, 		// enable AN3
							  0x0CCD,           // high limit, 80% of full scale
							  0x0333);      	// low limit, 20% of full scale							
    </code>

  Remarks:
	None.
 */

void PLIB_ADCHS_CVDSetup
( 
	ADCHS_MODULE_ID index, 
	ADCHS_CVD_CAPACITOR capSel,
	bool inBetweenOrEqual,
	bool greaterEqualHi,
	bool lessThanHi,
	bool greaterEqualLo,
	bool lessThanLo,
	ADCHS_AN_INPUT_ID inputEnable,
	int16_t  hiLimit,
	int16_t  loLimit
);

//******************************************************************************
/* Function:
   int16_t PLIB_ADCHS_CVDResultGet( ADCHS_MODULE_ID index )

  Summary:
    Returns a CVD result measured by an ADCHS instance.

  Description:
    During CVD measurement, the difference between the voltage measured
	during positive and negative phases is calculated. This function
	return the difference value.

  Precondition:
    CVD must be enabled and a comparator event linked to CVD should
	have occurred.
	
  Parameters:
    index   - Identifier for the ADCHS instance.
	
  Returns:
    The conversion result expressed as a signed 16-bit integer. 

  Example:
    <code>
    int16_t		result;
    ...
    // fetch result for CVD
    result = PLIB_ADCHS_CVDResultGet( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */

int16_t PLIB_ADCHS_CVDResultGet(ADCHS_MODULE_ID index);	

//******************************************************************************
/* Function:
   void PLIB_ADCHS_ChannelScanEnable(ADCHS_MODULE_ID index)

  Summary:
    Triggers a Scan Cycle.

  Description:
    This function triggers a scan cycle for the channels queued for scanning and
	for all third class channels.

  Precondition:
    ADC must be enabled and configured.
	
  Parameters:
    index   - Identifier for the ADCHS instance.
	
  Returns:
    None. 

  Example:
    <code>
    PLIB_ADCHS_ChannelScanEnable( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */
 
void PLIB_ADCHS_ChannelScanEnable(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function:
   void PLIB_ADCHS_ChannelScanAbort(ADCHS_MODULE_ID index)

  Summary:
    Aborts a Scan Cycle.

  Description:
    This function aborts the currently running scan cycle.

  Precondition:
    ADC must be enabled and configured.
	
  Parameters:
    index   - Identifier for the ADCHS instance.
	
  Returns:
    None. 

  Example:
    <code>
    PLIB_ADCHS_ChannelScanAbort( MY_ADCHS_INSTANCE );
    </code>

  Remarks:
    None.
 */
void PLIB_ADCHS_ChannelScanAbort(ADCHS_MODULE_ID index);

// *****************************************************************************
// *****************************************************************************
// Section: ADCHS Peripheral Library Exists API Routines
// *****************************************************************************
// *****************************************************************************
/* The functions below indicate the existence of the features on the device. 
 */

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsEnableControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the EnableControl feature exists on the ADCHS module 

  Description:
    This function identifies whether the EnableControl feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCHS_Enable
    - PLIB_ADCHS_Disable

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the EnableControl feature: 
    - true   - The EnableControl feature is supported on the device
    - false  - The EnableControl feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsEnableControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsTurboMode( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Turbo mode feature exists on the ADCHS module. 

  Description:
    This function identifies whether the Turbo mode feature is available on the ADCHS
	module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCHS_TurboModeEnable
    - PLIB_ADCHS_TurboModeDisable
	- PLIB_ADCHS_TurboModeErrorHasOccurred
	- PLIB_ADCHS_TurboModeChannelSelect

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Turbo mode feature: 
    - true   - The Turbo mode feature is supported on the device
    - false  - The Turbo mode feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsTurboMode(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsDigitalComparator( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Digital Comparator feature exists on the ADCHS module .

  Description:
    This function identifies whether the Digital Comparator feature is available on the ADCHS module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCHS_DigitalComparatorAnalogInputSelect
	- PLIB_ADCHS_DigitalComparatorAnalogInputGet
	- PLIB_ADCHS_DigitalComparatorEnable
	- PLIB_ADCHS_DigitalComparatorDisable
	- PLIB_ADCHS_DigitalComparatorInterruptEnable
	- PLIB_ADCHS_DigitalComparatorInterruptDisable
	- PLIB_ADCHS_DigitalComparatorSetup
	- PLIB_ADCHS_DigitalComparatorEventHasOccurred
	- PLIB_ADCHS_DigitalComparatorLimitSet
	
  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Digital Comparator feature: 
    - true   - The Digital Comparator feature is supported on the device
    - false  - The Digital Comparator feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsDigitalComparator(ADCHS_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsDigitalFilter( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Digital Filter feature exists on the ADCHS module. 

  Description:
    This function identifies whether the Digital Filter feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCHS_DigitalFilterEnable
	- PLIB_ADCHS_DigitalFilterDisable
	- PLIB_ADCHS_DigitalFilterOversamplingModeSetup
	- PLIB_ADCHS_DigitalFilterAveragingModeSetup
	- PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect
	- PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect
	- PLIB_ADCHS_DigitalFilterDataIsReady
	- PLIB_ADCHS_DigitalFilterDataGet
	- PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable
	- PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Digital Filter feature: 
    - true   - The Digital Filter feature is supported on the device
    - false  - The Digital Filter feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsDigitalFilter(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsFIFO( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the FIFO exists on the ADCHS module. 

  Description:
    This function identifies whether the FIFO feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCHS_FIFORead
	- PLIB_ADCHS_FIFODataIsAvailable
	- PLIB_ADCHS_FIFODataReadyInterruptEnable
	- PLIB_ADCHS_FIFODataReadyInterruptDisable
	- PLIB_ADCHS_FIFOEnable
	- PLIB_ADCHS_FIFODisable
	- PLIB_ADCHS_FIFOSourceSelect
	- PLIB_ADCHS_FIFODataCountGet
	- PLIB_ADCHS_FIFOSourceGet
	- PLIB_ADCHS_FIFOErrorHasOccurred
	- PLIB_ADCHS_FIFODataIsNegative

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the FIFO feature: 
    - true   - The FIFO feature is supported on the device
    - false  - The FIFO feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsFIFO(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsDMA( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the DMA exists on the ADCHS module. 

  Description:
    This function identifies whether the DMA feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_DMAEnable
	- PLIB_ADCHS_DMADisable
	- PLIB_ADCHS_DMASetup
	- PLIB_ADCHS_DMASourceSelect
	- PLIB_ADCHS_DMASourceRemove
	- PLIB_ADCHS_DMABuffer_A_InterruptEnable
	- PLIB_ADCHS_DMABuffer_A_InterruptDisable
	- PLIB_ADCHS_DMABuffer_B_InterruptEnable
	- PLIB_ADCHS_DMABuffer_B_InterruptDisable
	- PLIB_ADCHS_DMABuffer_A_IsFull
	- PLIB_ADCHS_DMABuffer_B_IsFull
	- PLIB_ADCHS_DMAOverflowErrorHasOccurred
	
  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the DMA feature: 
    - true   - The DMA feature is supported on the device
    - false  - The DMA feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsDMA(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsCVD( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the CVD exists on the ADCHS module. 

  Description:
    This function identifies whether the CVD feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_CVDEnable
	- PLIB_ADCHS_CVDDisable
	- PLIB_ADCHS_CVDSetup
	- PLIB_ADCHS_CVDResultGet

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the CVD feature: 
    - true   - The CVD feature is supported on the device
    - false  - The CVD feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsCVD(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsVREFControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the VREF control exists on the ADCHS module. 

  Description:
    This function identifies whether the VREF control feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_VREFIsReady
	- PLIB_ADCHS_VREFFaultHasOccurred
	- PLIB_ADCHS_VREFReadyInterruptEnable
	- PLIB_ADCHS_VREFReadyInterruptDisable
	- PLIB_ADCHS_VREFFaultInterruptEnable
	- PLIB_ADCHS_VREFFaultInterruptDisable

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the VREF control feature: 
    - true   - The VREF control feature is supported on the device
    - false  - The VREF control feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsVREFControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsAnalogInputScan( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Analog input Scan exists on the ADCHS module. 

  Description:
    This function identifies whether the Analog Input Scan feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_AnalogInputScanIsComplete
	- PLIB_ADCHS_AnalogInputScanSelect
	- PLIB_ADCHS_AnalogInputScanRemove
	- PLIB_ADCHS_AnalogInputScanIsSelected
	- PLIB_ADCHS_AnalogInputScanSetup
	- PLIB_ADCHS_ScanCompleteInterruptEnable
	- PLIB_ADCHS_ScanCompleteInterruptDisable

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Scan feature: 
    - true   - The Analog Input Scan feature is supported on the device
    - false  - The Analog Input Scan feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsAnalogInputScan(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsChannelAnalogControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Channel Analog control exists on the ADCHS module. 

  Description:
    This function identifies whether the Channel Analog control feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_ChannelAnalogFeatureEnable
	- PLIB_ADCHS_ChannelAnalogFeatureDisable
	- PLIB_ADCHS_ChannelIsReady
	- PLIB_ADCHS_ChannelIsReadyInterruptEnable
	- PLIB_ADCHS_ChannelIsReadyInterruptDisable
	

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Channel Analog control feature: 
    - true   - The Channel Analog control feature is supported on the device
    - false  - The Channel Analog control feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsChannelAnalogControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsChannelDigitalControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Channel Digital control exists on the ADCHS module. 

  Description:
    This function identifies whether the Channel Digital control feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_ChannelDigitalFeatureEnable
	- PLIB_ADCHS_ChannelDigitalFeatureDisable
	

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Channel Digital control feature: 
    - true   - The Channel Digital control feature is supported on the device
    - false  - The Channel Digital control feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsChannelDigitalControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsAnalogInputModeControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the analog input mode control exists on the ADCHS module. 

  Description:
    This function identifies whether the analog input mode control feature is available 
	on the ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_AnalogInputModeSelect
	- PLIB_ADCHS_AnalogInputModeGet
	

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the input mode control feature: 
    - true   - The analog input mode control feature is supported on the device
    - false  - The analog input mode control feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsAnalogInputModeControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsTriggerControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Trigger control exists on the ADCHS module. 

  Description:
    This function identifies whether the Trigger control feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_AnalogInputLevelTriggerSet
	- PLIB_ADCHS_AnalogInputEdgeTriggerSet
	- PLIB_ADCHS_AnalogInputTriggerSourceSelect
	- PLIB_ADCHS_GlobalSoftwareTriggerEnable
	- PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable
	- PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable
	- PLIB_ADCHS_TriggerSuspendEnable
	- PLIB_ADCHS_TriggerSuspendDisable
	
  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Trigger control feature: 
    - true   - The Trigger control feature is supported on the device
    - false  - The Trigger control feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsTriggerControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsTriggerSampleControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Trigger Sample control feature exists on the ADCHS module. 

  Description:
    This function whether the Trigger Sample control feature exists on the ADCHS 
	module.
    When this function returns true, this function is supported on the device: 
	- PLIB_ADCHS_ChannelTriggerSampleSelect
	

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Trigger Sample control feature: 
    - true   - The Trigger Sample control feature is supported on the device
    - false  - The Trigger Sample control feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsTriggerSampleControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsEarlyInterruptControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Early Interrupt control exists on the ADCHS module. 

  Description:
    This function identifies whether the Early Interrupt control feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_EarlyInterruptEnable
	- PLIB_ADCHS_EarlyInterruptDisable
	- PLIB_ADCHS_AnalogInputEarlyInterruptEnable
	- PLIB_ADCHS_AnalogInputEarlyInterruptDisable
	- PLIB_ADCHS_AnalogInputEarlyInterruptIsReady
	

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Early Interrupt control feature: 
    - true   - The Early Interrupt control feature is supported on the device
    - false  - The Early Interrupt control feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsEarlyInterruptControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsManualControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Manual control exists on the ADCHS module. 

  Description:
    This function identifies whether the Manual control feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_SoftwareSamplingStart
	- PLIB_ADCHS_SoftwareSamplingStop
	- PLIB_ADCHS_SoftwareConversionStart
	- PLIB_ADCHS_SoftwareConversionInputSelect
	

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Manual control feature: 
    - true   - The Manual control feature is supported on the device
    - false  - The Manual control feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsManualControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsUpdateReadyControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Update Ready feature exists on the ADCHS module. 

  Description:
    This function identifies whether the Update Ready feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptEnable
	- PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptDisable
	- PLIB_ADCHS_ControlRegistersCanBeUpdated


  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Update Ready feature: 
    - true   - The Update Ready feature is supported on the device
    - false  - The Update Ready feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsUpdateReadyControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsChannelInputSelectControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Channel 0 to 6 Input select feature exists on the ADCHS module. 

  Description:
    This function identifies whether the Channel 0 to 6 Input select feature is available
	on the ADCHS module.
    When this function returns true, this function is supported on the device: 
	- PLIB_ADCHS_ChannelInputSelect

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the Channel 0 to 6 Input feature: 
    - true   - The Channel 0 to 6 Input Select feature is supported on the device
    - false  - The Channel 0 to 6 Input Select feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsChannelInputSelectControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsExternalConversionRequestControl( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the External Convert feature exists on the ADCHS module. 

  Description:
    This function identifies whether the External Convert feature is available on the 
	ADCHS module.
    When this function returns true, these functions are supported on the device: 
	- PLIB_ADCHS_ExternalConversionRequestEnable
	- PLIB_ADCHS_ExternalConversionRequestDisable
	

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the External Convert feature: 
    - true   - The External Convert feature is supported on the device
    - false  - The External Convert feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsExternalConversionRequestControl(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsConfiguration( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Configuration feature exists on the ADCHS module. 

  Description:
    This function identifies whether the Configuration feature is available on 
	the ADCHS module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCHS_Setup
	- PLIB_ADCHS_ChannelSetup

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Configuration feature: 
    - true   - The Configuration feature is supported on the device
    - false  - The Configuration feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsConfiguration(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsAnalogInputCheck( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the System Configuration feature exists on the ADCHS module. 

  Description:
    This function identifies whether the System Configuration feature is available 
	on the ADCHS module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADCHS_AnalogInputIsAvailable

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the System Configuration feature: 
    - true   - The System Configuration feature is supported on the device
    - false  - The System Configuration feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsAnalogInputCheck(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsChannelConfiguration( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Channel Configuration feature exists on the ADCHS module. 

  Description:
    This function identifies whether the Channel Configuration feature is available 
	on the ADCHS module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCHS_ChannelConfigurationGet
	- PLIB_ADCHS_ChannelConfigurationSet

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the Channel Configuration feature: 
    - true   - The Channel Configuration feature is supported on the device
    - false  - The Channel Configuration feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsChannelConfiguration(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsConversionResults( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Conversion Results feature exists on the ADCHS module. 

  Description:
    This function identifies whether the Conversion Results feature is available 
	on the ADCHS module.
	When this function returns true, these functions are supported on the device: 
    - PLIB_ADCHS_AnalogInputDataReadyInterruptEnable
	- PLIB_ADCHS_AnalogInputDataReadyInterruptDisable
	- PLIB_ADCHS_AnalogInputDataIsReady
	- PLIB_ADCHS_AnalogInputResultGet

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance.

  Returns:
    Existence of the ConversionResults feature: 
    - true   - The ConversionResults feature is supported on the device
    - false  - The ConversionResults feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCHS_ExistsConversionResults(ADCHS_MODULE_ID index);

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsScanEnable( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the ScanEnable feature exists on the ADCHS module 

  Description:
    This function identifies whether the ScanEnable feature is available on the ADCHS module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCHS_ChannelScanEnable
    - PLIB_ADCHS_ChannelScanAbort

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ScanEnable feature is supported on the device
    - false  - The ScanEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADCHS_ExistsScanEnable( ADCHS_MODULE_ID index );

//******************************************************************************
/* Function :  PLIB_ADCHS_ExistsRegisters( ADCHS_MODULE_ID index )

  Summary:
    Identifies whether the Registers data structure exists on the ADCHS module 

  Description:
    This function identifies whether the Registers data structure feature is available on the ADCHS module.
    When this function returns true, if Registers data structure structure exist: 

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The Registers data structure is supported on the device
    - false  - The Registers data structure is not supported on the device

  Remarks:
    None.
*/

bool PLIB_ADCHS_ExistsRegisters( ADCHS_MODULE_ID index );


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/******************************************************************************
 End of File
 */
#endif

