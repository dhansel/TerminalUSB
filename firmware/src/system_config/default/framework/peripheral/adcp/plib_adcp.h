/*******************************************************************************
  Pipelined Analog-to-Digital Converter (ADCP) Peripheral Library Interface Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_adcp.h

  Summary:
    ADCP Peripheral Library Interface Header for ADCP common definitions

  Description:
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the ADCP
    PLIB for all families of Microchip microcontrollers. The definitions in
    this file are common to the ADCP peripheral.
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

#ifndef _PLIB_ADCP_H
#define _PLIB_ADCP_H

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

/*************************************************************************
  Summary:
    This union of structures is provided to simply selection of analog
    inputs for inclusion in a particular function.
	
  Description:
    ADCP AN Select Union
    
    The structure labels identify the analog inputs associated with each bit
    when initializing the structure. Unsigned 32-bit integers, lowWord and
    highWord are used as arguments to the function.
	
  Remarks:
    See the Channel Scanning example in the ADCP Help documentation
    regarding use of this type define. 	
  *************************************************************************/
typedef union AN_SELECT {
    int ret_val;

    struct {
        uint32_t lowWord;
        uint32_t highWord;
    } /* anWords */;

    struct {
        uint32_t AN0 : 1;
        uint32_t AN1 : 1;
        uint32_t AN2 : 1;
        uint32_t AN3 : 1;
        uint32_t AN4 : 1;
        uint32_t AN5 : 1;
        uint32_t AN6 : 1;
        uint32_t AN7 : 1;
        uint32_t AN8 : 1;
        uint32_t AN9 : 1;
        uint32_t AN10 : 1;
        uint32_t AN11 : 1;
        uint32_t AN12 : 1;
        uint32_t AN13 : 1;
        uint32_t AN14 : 1;
        uint32_t AN15 : 1;
        uint32_t AN16 : 1;
        uint32_t AN17 : 1;
        uint32_t AN18 : 1;
        uint32_t AN19 : 1;
        uint32_t AN20 : 1;
        uint32_t AN21 : 1;
        uint32_t AN22 : 1;
        uint32_t AN23 : 1;
        uint32_t AN24 : 1;
        uint32_t AN25 : 1;
        uint32_t AN26 : 1;
        uint32_t AN27 : 1;
        uint32_t AN28 : 1;
        uint32_t AN29 : 1;
        uint32_t AN30 : 1;
        uint32_t AN31 : 1;
        uint32_t AN32 : 1;
        uint32_t AN33 : 1;
        uint32_t AN34 : 1;
        uint32_t AN35 : 1;
        uint32_t AN36 : 1;
        uint32_t AN37 : 1;
        uint32_t AN38 : 1;
        uint32_t AN39 : 1;
        uint32_t AN40 : 1;
        uint32_t AN41 : 1;
        uint32_t AN42 : 1;
        uint32_t AN43 : 1;
        uint32_t AN44 : 1;
        uint32_t AN45 : 1;
        uint32_t AN46 : 1;
        uint32_t AN47 : 1;
        uint32_t AN48 : 1;
        uint32_t AN49 : 1;
        uint32_t AN50 : 1;
        uint32_t AN51 : 1;
        uint32_t AN52 : 1;
        uint32_t AN53 : 1;
        uint32_t AN54 : 1;
        uint32_t AN55 : 1;
        uint32_t AN56 : 1;
        uint32_t AN57 : 1;
        uint32_t AN58 : 1;
        uint32_t AN59 : 1;
        uint32_t AN60 : 1;
        uint32_t AN61 : 1;
        uint32_t AN62 : 1;
        uint32_t AN63 : 1;
    } /* anBits */;
} AN_SELECT;

/**************************************************************************
  Summary:
    This union (identical to the AN_SELECT union) is used as the return
    value by the PLIB_ADCP_Result_Ready function.
	
  Description:
    ADCP AN Ready Union
    
    The structure labels identify the analog inputs associated with each bit
    for testing ready status of individual inputs. Unsigned 32-bit
    integers, lowWord and highWord allow for testing ready status of groups
    of bits using a mask.
	
  Remarks:
    See the Simultaneous Sampling or Channel Scanning examples in the ADCP
    Help documentation regarding use of this type define.                  
  **************************************************************************/
typedef AN_SELECT AN_READY;

// *****************************************************************************
// *****************************************************************************
// Section: Include Processor Specific Files
// *****************************************************************************
// *****************************************************************************
#include "peripheral/adcp/processor/adcp_processor.h"

// *****************************************************************************
// *****************************************************************************
// Section: Helper Macros
// *****************************************************************************
// *****************************************************************************


// ****************************************************************************
// ****************************************************************************
// Section: Pipelined ADCP Peripheral Library Interface Routines: Converter
// ****************************************************************************
// ****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_ADCP_Enable( ADCP_MODULE_ID index )

  Summary:
    Enables the Pipelined ADC module.

  Description:
    This function enables (turns ON) the selected Pipelined ADC module. 

  Precondition:
    None.

  Parameters:
    index      - Identifier for the ADCP instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
    PLIB_ADCP_Enable(MY_ADCP_INSTANCE);
    </code>

  Remarks:
    None
 */

void PLIB_ADCP_Enable(ADCP_MODULE_ID index);

// *****************************************************************************
/* Function:
    void PLIB_ADCP_Disable( ADCP_MODULE_ID index )

  Summary:
    Pipelined ADC module is disabled (turned OFF).

  Description:
    This function disables (turns OFF) the selected Pipelined ADC module.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCP instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
    PLIB_ADCP_Disable(MY_ADCP_INSTANCE);
    </code>

  Remarks:
    Note: Not all functionality is available on all devices. Please refer to 
    the specific device data sheet for the list of available features.
 */

void PLIB_ADCP_Disable(ADCP_MODULE_ID index);

// *****************************************************************************
/* Function:
    void PLIB_ADCP_CalibrationStart( ADCP_MODULE_ID index )

  Summary:
    Initiates Pipelined ADC Calibration.

  Description:
    This function initiates calibration of the module. During calibration
    the module cannot perform conversion.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCP instance to be configured

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
    PLIB_ADCP_CalibrationStart(MY_ADCP_INSTANCE);
        while (!PLIB_ADCP_ModuleIsRead(MY_ADCP_INSTANCE));
    </code>

  Remarks:
    Calibration is complete when PLIB_ADCP_ModuleIsReady() returns a TRUE result. 
 */

void PLIB_ADCP_CalibrationStart(ADCP_MODULE_ID index);

//******************************************************************************
/* Function:
    bool PLIB_ADCP_ModuleIsReady( ADCP_MODULE_ID index )

  Summary:
    Returns the overall ready status of the module.  

  Description:
    This function returns the ready status of the Pipelined ADC.  The ADC must 
	be ready before operation.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCP instance 

  Returns:
    Boolean indicating ready status. 

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Enable the module
    PLIB_ADCP_Enable(MY_ADCP_INSTANCE);
	
    // wait for calibration to complete
    while (!PLIB_ADCP_ModuleIsReady(MY_ADCP_INSTANCE));
	
    // begin sampling
    ...
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCP_ModuleIsReady(ADCP_MODULE_ID index);

//********************************************************************************
/*  Function:
      void PLIB_ADCP_LowPowerStateEnter ( ADCP_MODULE_ID index )
    
  Summary:
    Places the Pipelined ADC module in a low power state.
	
  Description:
    This function places the Pipelined ADC module in a low power state. The feature 
	is used in place of disabling the ADC when power reduction is needed. The 
	Pipelined ADC can come out of low power state and be operational much faster
    since recalibration is not required.
	
  Conditions:
    The Pipelined ADC must be enabled.
	
  Parameters:
    index -  Identifier for the ADCP instance 
	
  Returns:
    None.
	
  Example:
    <code>
    PLIB_ADCP_LowPowerStateEnter(MY_ADCP_INSTANCE);
    </code>
              
  Remarks:
    None.
			  
 */

void PLIB_ADCP_LowPowerStateEnter(ADCP_MODULE_ID index);

//******************************************************************************
/* Function:
    void PLIB_ADCP_LowPowerStateExit( ADCP_MODULE_ID index )

  Summary:
    Takes the Pipelined ADC module out of low power state and puts it into an
    operational mode.

  Description:
    This function takes the Pipelined ADC module out of a low power state and places
	it into an operational mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCP instance 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCP_LowPowerStateExit(MY_ADCP_INSTANCE);
    </code>

  Remarks:
    The first five conversions following the exit from ADC Low-power mode 
    may be subject to lower accuracy than specified in the device data sheet.
 */

void PLIB_ADCP_LowPowerStateExit(ADCP_MODULE_ID index);

//********************************************************************
/* Function:
    bool PLIB_ADCP_LowPowerStateGet( ADCP_MODULE_ID index )
    
  Summary:
    Returns the state of the low power setting.
	
  Description:
    This function returns the state of the low power setting.

  Preconditions:
    None.
	
  Parameters:
    index -  Identifier for the ADCP instance
	
  Returns:
    A Boolean indicating the state of the low power setting.
	
  Example:
    <code>
    bool lowPowerSate = PLIB_ADCP_LowPowerStateGet(MY_ADCP_INSTANCE);
    </code>
	
  Remarks:
    None.                                                            
 */

bool PLIB_ADCP_LowPowerStateGet(ADCP_MODULE_ID index);

//**************************************************************************
/*
  Function:
    AN_READY PLIB_ADCP_ResultReady( ADCP_MODULE_ID index )
    
  Summary:
    Returns the ADC conversion result ready bits for the module.
	
  Description:
    This function returns a result indicating which analog inputs have conversion
    results ready.

  Preconditions:
    None.
	
  Parameters:
    index -  Identifier for the ADCP instance
	
  Returns:
    A AN_READY type indicating conversion result status. 
	
  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
    AN_READY     MyRdyStatus;
    
    // check for data and process it
    if ((MyRdyStatus = PLIB_ADCP_ResultReady(MY_ADCP_INSTANCE)) != 0) {
        // fetch the results and process
    }
    </code>
	
  Remarks:
    This function returns individual conversion results. It does not return
    results from the module.
 */
AN_READY PLIB_ADCP_ResultReady(ADCP_MODULE_ID index);

//******************************************************************************
/* Function:
   int32_t PLIB_ADCP_ResultGet( ADCP_MODULE_ID index, ADCP_INPUT_ID inputId )

  Summary:
    Returns a Pipelined ADC conversion result.

  Description:
    This function returns the specified Pipelined ADC analog input conversion result.
	
  Precondition:
    A valid conversion is ready to be fetched. 
	
  Parameters:
    index   - Identifier for the ADCP instance
    inputId - Identifier for the input
	
  Returns:
    The conversion result expressed as a 32-bit integer. 

  Example:
    <code>
    int32_t		result;
    ...
    // fetch result for AN31
    result = PLIB_ADCP_ResultGet( MY_ADCP_INSTANCE, ADCP_AN31 );
    </code>

  Remarks:
    None.
 */

int32_t PLIB_ADCP_ResultGet(ADCP_MODULE_ID index, ADCP_INPUT_ID inputId);

//******************************************************************************
/* Function:
    void PLIB_ADCP_ChannelScanConfigure( ADCP_MODULE_ID index, 
                                        uint32_t  lowEnable,
                                        uint32_t highEnable,
                                        ADCP_SCAN_TRG_SRC triggerSource)

  Summary:
    Selects input to include in Channel Scan Mode

  Description:
    This function selects inputs, as determined by the low and high enable scan 
	list for inclusion in the channel scan sequence. If the input is a Class 1 or
    Class 2 type, it will also select the trigger source for that input
    to be the scan trigger, which is required if included in channel scanning.
	
  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCP instance 
    lowEnable		- bit mask for selecting low order scan channels
    highEnable		- bit mask for selecting high order scan channels
    triggerSource   - Trigger source used to initiate channel scan
	
  Returns:
    None.  

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Configure Channel Scanning
    // Channels 10 through 13
    // Trigger on Timer 1 match.
    PLIB_ADCP_ChannelScanConfigure(MY_ADCP_INSTANCE, 
                                   0XF000, //	AN12 - AN15
                                   0X0F00, //  AN24 - AN27
                                   ADCP_SCAN_TRG_SRC_TMR1_MATCH)
    </code>

  Remarks:
    The type def AN_SELECT can be used to create a variable to simplify selection
    of the inputs to include in the channel scan.  This typedef creates bit field
    structures for each ANx input that are joined with unions for the low and
    high 32-bit words.  See the code example for Channel scan in the ADCP PLIB
    help documentation for details on its use.
 */

void PLIB_ADCP_ChannelScanConfigure(ADCP_MODULE_ID index,
                                    uint32_t lowEnable, uint32_t highEnable,
                                    ADCP_SCAN_TRG_SRC triggerSource);

//****************************************************************************
/*  Function:
    void PLIB_ADCP_Class12TriggerConfigure( ADCP_MODULE_ID index,
                                            ADCP_CLASS12_INPUT_ID inputId,
                                            ADCP_TRG_SRC triggerSource)
    
  Summary:
    Configures a Class 1 or Class 2 Trigger Source.
	
  Description:
    This function configures the trigger source for Class 1 or Class 2 inputs. 
	A call to this function is not required when the input is being used as part 
	of a channel scan as the channel scan configure function also configures all
    trigger sources.
	
  Preconditions:
    The function only applies to Class 1 and Class 2 inputs.
	
  Parameters:
    index   		-  Identifier for the ADCP instance
    inputId 	    -  Class 1 or Class 2 input to configure the trigger for.
    triggerSource 	-  Trigger source to use for this input.
	
  Returns:
    none.
	
  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
    
    // Configure AN0 for triggering from INT0.
    PLIB_ADCP_Class12TriggerConfigure(MY_ADCP_INSTANCE, 
									  ADCP_CLASS12_AN0,
                                      ADCP_TRG_SRC_INT0);
    </code>
	
  Remarks:
    None.                                                                    
 */

void PLIB_ADCP_Class12TriggerConfigure(ADCP_MODULE_ID index,
                                       ADCP_CLASS12_INPUT_ID inputId,
                                       ADCP_TRG_SRC triggerSource);

//******************************************************************************
/* Function:
    void PLIB_ADCP_GlobalSoftwareTrigger( ADCP_MODULE_ID index )

  Summary:
    Initiates a Global Software Trigger on the specified module.  

  Description:
    All inputs or scan list that is configured to trigger on the global 
    software trigger are triggered by this function.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the ADCP instance 

  Returns:
    None.

  Example:
    <code>
    PLIB_ADCP_GlobalSoftwareTrigger(MY_ADCP_INSTANCE);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCP_GlobalSoftwareTrigger(ADCP_MODULE_ID index);

//******************************************************************************
/* Function:
    void PLIB_ADCP_IndividualTrigger( ADCP_MODULE_ID index, ADCP_INPUT_ID inputId)

  Summary:
    Triggers an individual channel independent of the configured trigger source

  Description:
    This function forces a trigger of an individual Class 1 or Class 2 channel 
	independent of its configured trigger source.
	
  Precondition:
    The function only applies to Class 1 and Class 2 inputs. 

  Parameters:
    index           - Identifier for the ADCP instance 
    inputId			- An ADCP_INPUT_ID type indicating which input to trigger.

  Returns:
    None.  

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Force a trigger of AN5
    PLIB_ADCP_IndividualTrigger(MY_ADCP_INSTANCE, ADCP_CLASS12_AN5)
    </code>

  Remarks:
    None. 
 */

void PLIB_ADCP_IndividualTrigger(ADCP_MODULE_ID index, ADCP_INPUT_ID inputId);

//******************************************************************************
/* Function:
    void PLIB_ADCP_AlternateInputSelect(ADCP_MODULE_ID index, ADCP_DSH_ID id)

  Summary:
    Selects the alternate physical input for the specified dedicated (Class 1)
    S&H.

  Description:
    This function selects the alternate physical input for the specified S&H.
	
  Precondition:
    The function only applies to dedicated S&H circuits (Class 1 Inputs). 

  Parameters:
    index   - Identifier for the ADCP instance 
    id		- An ADCP_DSH_ID type indicating which dedicated Class 1
              S&H to configure for its alternate input source.
	
  Returns:
    None.  

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Set S&H 1 to use the alternate input.
    PLIB_ADCP_AlternateInputSelect(MY_ADCP_INSTANCE, ADCP_DSH1)
    </code>

  Remarks:
    None. 
 */

void PLIB_ADCP_AlternateInputSelect(ADCP_MODULE_ID index, ADCP_DSH_ID id);

//******************************************************************************
/* Function:
    void PLIB_ADCP_DefaultInputSelect(ADCP_MODULE_ID index, ADCP_DSH_ID id)

  Summary:
    Selects the default physical input for the specified dedicated (Class 1)
    S&H.

  Description:
    This function selects the default physical input for the specified S&H.
	
  Precondition:
    The function only applies to dedicated S&H circuits (Class 1 Inputs). 

  Parameters:
    index   - Identifier for the ADCP instance 
    id		- An ADCP_DSH_ID type indicating which dedicated Class 1
              S&H to configure for its alternate input
              source.
	
  Returns:
    None.  

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Set S&H 1 to use the default input.
    PLIB_ADCP_DefaultInputSelect(MY_ADCP_INSTANCE, ADCP_DSH1)
    </code>

  Remarks:
    None. 
 */

void PLIB_ADCP_DefaultInputSelect(ADCP_MODULE_ID index, ADCP_DSH_ID id);

//*****************************************************************************
/*
  Function:
    void PLIB_ADCP_SHModeSelect( ADCP_MODULE_ID index,
                                 ADCP_SH_ID id,
                                 ADCP_SH_MODE mode)
    
  Summary:
    Selects the mode for the specified S&H.
	
  Description:
    This function selects the mode (single ended or differential) and encoding 
	(unipolar or two's compliment) for the specified S&H.
	
  Preconditions:
    None.
	
  Parameters:
    index - Identifier for the ADCP instance
    id    - An ADCP_DSH_ID type indicating which dedicated S&H to
            configure to use its alternate source
    mode  - An ADCP_SH_MODE type indicating the mode selection
	
  Returns:
    None.
	
  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
    
    // Set S&H 1 to use the single ended, two's complement mode
    // selection.
    PLIB_ADCP_SHModeSelect(MY_ADCP_INSTANCE, 
                           ADCP_SH1,
                           ADCP_SH_MODE_SINGLE_ENDED_TWOS_COMP)
    </code>
	
  Remarks:
    None.                                                                     
 */

void PLIB_ADCP_SHModeSelect(ADCP_MODULE_ID index,
                            ADCP_DSH_ID id,
                            ADCP_SH_MODE mode);


//******************************************************************************
/* Function:
    void PLIB_ADCP_ResultReadyGrpIntConfigure( ADCP_MODULE_ID index, 
                                               uint32_t  lowEnable,
                                               uint32_t highEnable)

  Summary:
    Selects input to include in global interrupt.

  Description:
    This function selects inputs, as determined by the input mask channel scan 
	list for inclusion in the global or global interrupt.
	
  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCP instance 
    lowEnable		- bit mask for selecting low order scan channels
    highEnable		- bit mask for selecting high order scan channels
	
  Returns:
    None.  

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Configure Global Interrupts
    // Analog inputs 10 through 13 are included in the global interrupt.
    PLIB_ADCP_ResultReadyGrpIntConfigure(MY_ADCP_INSTANCE, 
                                         0x0F00, 	// inputs AN8 - AN11
                                         0x000F );	// inputs AN16 - AN19
    </code>

  Remarks:
    The type def AN_SELECT can be used to create a variable to simplify selection
    of the inputs to include in the global interrupt.  This typedef creates bit field
    structures for each ANx input that are joined with unions for the low and
    high 32-bit words.  See the code example for Channel scan in the ADCP PLIB
    help documentation for details on its use.
 */

void PLIB_ADCP_ResultReadyGrpIntConfigure(ADCP_MODULE_ID index, 
                                          uint32_t lowEnable, 
                                          uint32_t highEnable);

//******************************************************************************
/* Function:
    void PLIB_ADCP_Configure( ADCP_MODULE_ID index, 
            ADCP_VREF_SOURCE voltageRefSelect,  // voltage reference
            bool boostVref,			            // VREF boost
            bool fractionalOutputOn,            // result format fractional
            bool stopInIdle,		  	        // stop in idle
            ADCP_CLOCK_SOURCE adcClockSource, 	// clock source
            int8_t adcClockDivider,             // clock divider
            int8_t oversampleDigFilterSamTime,  // sample time between digital filter samples
            int8_t earlyIntEnable,              // early interrupt enable
            int8_t class2and3SampleTime )	    // Class 2&3 Sample time
								
  Summary:
    Configures the Pipelined ADC module including the ADC calibration registers.

  Description:
    This function configures all ADC parameters common to all inputs.  This 
	configuration must occur prior to  enabling the ADC and therefore must be 
	called when the ADC is disabled.

  Precondition:
    The module is disabled when calling this function. 

  Parameters:
    index           			- Identifier for the ADCP instance 
    voltageRefSelect			- VREF Source Selection
    boostVref					- Enables the VREF boost if TRUE.
                                  Use when VREFH - VREFL < .64 (AVDD - AVSS)
    fractionalOutputOn			- sets output to a fractional format if TRUE
    stopInIdle					- sets ADC to stop when device is in idle mode if TRUE
    adcClockSource				- Clock source selection
    adcClockDivider				- Clock source divider. Values range from 0 to 254.
    oversampleDigFilterSamTime	- Sets the delay (sample time) between automatically
                                  generated oversampling filter triggers. Values range
                                  from 0 to 31 for 1.5 TAD to 32.5 TAD respectively.
    earlyIntEnable				- Sets the number of clocks prior to the actual arrival
                                  of data that the ADRDY bit is set. Range is 0 to 7.
                                  Used to generate an early interrupt.
    class2and3SampleTime		- Set the sample time for Class 2 and Class 3 inputs.
                                  Range is 0 to 255 for a sample time of 1 to 256,
                                  respectively.
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.

    // Configure the ADC
    PLIB_ADCP_Configure( MY_ADCP_INSTANCE,
            ADCP_VREF_VREFP_VREFN,	// VREF+ and VREF- as reference
            FALSE,			// No VREF boost
            TRUE,	  		// Use fractional format
            TRUE,		  	// Do stop in idle
            ADCP_CLK_SRC_SYSCLK, 	// SYSCLK is the clock source
            3, 			    // TAD = 1/SYSCLK * 2 * 3
                            // or ADC Clock = SYSCLK / (2 * 3)
            2,			    // 2 + 1.5 = 3.5 TAD between
                            // oversampling triggers
            0,              // No early interrupt.
            3 );			// 3 + 1 = 4 TAD for Class 2 and 3
                            // Sample Time.

    // Enable the ADC
    PLIB_ADCP_Enable(MY_ADCP_INSTANCE);
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

void PLIB_ADCP_Configure(ADCP_MODULE_ID index,
                        ADCP_VREF_SOURCE voltageRefSelect,
                        bool boostVref,
                        bool fractionalOutputOn,
                        bool stopInIdle,
                        ADCP_CLOCK_SOURCE adcClockSource,
                        int8_t adcClockDivider,
                        int8_t oversampleDigFilterSamTime,
                        int8_t earlyIntEnable,
                        int8_t class2and3SampleTime);

// *****************************************************************************
/* Function:
    void PLIB_ADCP_DigCmpEnable( ADCP_MODULE_ID index, ADCP_DCMP_ID id )

  Summary:
    Enables the Digital Comparator in the Pipelined ADC module.

  Description:
    This function enables (turns ON) the selected Digital Comparator in the 
    specified Pipelined ADC module.

  Precondition:
    The digital comparator should be configured using the PLIB_ADCP_Configure()
    function prior to enabling.

  Parameters:
    index   	- Identifier for the ADCP instance
    id			- Identifier for the digital comparator in the ADCP module.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Enable Digital Comparator 1
    PLIB_ADCP_DigCmpEnable(MY_ADCP_INSTANCE, ADCP_DCMP1);
    </code>

  Remarks:
    None
 */

void PLIB_ADCP_DigCmpEnable(ADCP_MODULE_ID index, ADCP_DCMP_ID id);

// *****************************************************************************
/* Function:
    void PLIB_ADCP_DigCmpDisable( ADCP_MODULE_ID index, ADCP_DCMP_ID id )

  Summary:
    Disables the Digital Comparator in the Pipelined ADC module.

  Description:
    This function Disables (turns OFF) the selected Digital Comparator in the 
    specified Pipelined ADC module.

  Precondition:
    None. 

  Parameters:
    index       - Identifier for the ADCP instance
    id			- Identifier for the digital comparator in the ADCP module.

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Disable Digital Comparator 1
    PLIB_ADCP_DigCmpDisable(MY_ADCP_INSTANCE, ADCP_DCMP1);
    </code>

  Remarks:
    None
 */

void PLIB_ADCP_DigCmpDisable(ADCP_MODULE_ID index, ADCP_DCMP_ID id);

//***************************************************************************************
/*
  Function:
    void PLIB_ADCP_DigCmpConfig( ADCP_MODULE_ID index, 	// ADCP module ID
                                 ADCP_DCMP_ID id,       // Comparator ID
                                 bool globalIntEnable,  // Global Int Enable
                                 bool inBetweenOrEqual,	// between low and high
                                 bool greaterEqualHi,  	// greater than equal to high
                                 bool lessThanHi,      	// less than high
                                 bool greaterEqualLo,   // greater than equal to low
                                 bool lessThanLo,       // less than low
                                 uint32_t inputEnable,  // input enable bits
                                 int32_t  hiLimit,      // high limit
                                 int32_t  loLimit )     // low limit

  Summary:
    Configures the Digital Comparator on the Pipelined ADC converter.
	
  Description:
    This function configures all parameters for the Digital Comparator module of the
    pipelined ADC.
	
  Preconditions:
    The module is disabled when calling this function.
	
  Parameters:
    index    		 -  Identifier for the ADCP instance
    id 		 		 -  Identifier for the digital comparator in this device
    globalIntEnable  -  When set, comparator events are included in the Global
                        Interrupt
    inBetweenOrEqual -  Event is generated when result is greater than or equal to
                        loLimit and less than hiLimit
    greaterEqualHi 	 -  Event is generated when result is greater than or equal to
                        hiLimit
    lessThanHi 		 -  Event is generated when result is less than hiLimit
    greaterEqualLo 	 -  Event is generated when result is greater than or equal to
                        loLimit
    lessThanLo 		 -  Event is generated when result is less than loLimit
    inputEnable 	 -  Bit field which determines which analog inputs are tested by
                        this comparator module. Bit 0 applies to AN0 and bit 31 to
                        AN31.
    hiLimit 		 -  High limit in the same format as the conversion result.
    loLimit 		 -  Low limit in the same format as the conversion result.
	
  Returns:
    None.
	
  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
    
    // Configure the Digital Comparator
    // Creates an event when the reading of AN0 is between 20% to 80% of the
    // full scale 12-bit output.
    PLIB_ADCP_DigCmpConfig( MY_ADCP_INSTANCE,  	// ADCP module ID
                          ADCP_DCMP1,   	// Comparator ID
                          FALSE,            // Global Int Enable
                          TRUE,         	// test for between low and high
                          FALSE,            // no test for greater than equal to high
                          FALSE,            // no test for less than high
                          FALSE,            // no test for greater than equal to low
                          FALSE,            // no test for less than low
                          1 << 3, 			// enable AN3
                          0x0CCD,           // high limit, 80% of full scale
                          0x0333);      	// low limit, 20% of full scale
    
    // Enable Digital Comparator 1
    PLIB_ADCP_DigCmpEnable(MY_ADCP_INSTANCE, ADCP_DCMP1);
    </code>
	
  Remarks:
    This function must be called when the ADC is disabled.          
    The format of hiLimit and loLimit must match the output format of the 
    channel(s) specified in inputEnable.     
 */

void PLIB_ADCP_DigCmpConfig(ADCP_MODULE_ID index,
                            ADCP_DCMP_ID id,
                            bool globalIntEnable,
                            bool inBetweenOrEqual,
                            bool greaterEqualHi,
                            bool lessThanHi,
                            bool greaterEqualLo,
                            bool lessThanLo,
                            uint32_t inputEnable,
                            int32_t hiLimit,
                            int32_t loLimit);

// *****************************************************************************
/* Function:
    int16_t PLIB_ADCP_DigCmpAIdGet( ADCP_MODULE_ID index, ADCP_DCMP_ID id )

  Summary:
    Returns the Analog Input ID of for the Comparator Event

  Description:
    This function tests the DigCmp Event Flag and if true, returns the ANx 
    Identifier for the input that caused the event, or -1 if there was no
    pending DigCmp event. The ID value returned corresponds to numeric portion
    of the analog input ID, ANx.

  Precondition:
    None. 

  Parameters:
    index   - Identifier for the ADCP instance
    id	    - Identifier for the digital comparator in the ADCP module

  Returns:
    Value 'x' of type int16_t where 'x' is the index to the analog input ANx, 
    which caused the event or -1 if no event has occurred.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
    int16_t 	DigCmpResult;
	
    // Get Digital Comparator 1 result.
    DigCmpResult = PLIB_ADCP_DigCmpAIdGet(MY_ADCP_INSTANCE, ADCP_DCMP1);
    if (DigCmpResult != -1) {
        // process event
    }
    </code>

  Remarks:
    None.
 */

int16_t PLIB_ADCP_DigCmpAIdGet(ADCP_MODULE_ID index, ADCP_DCMP_ID id);

// *****************************************************************************
/* Function:
    void PLIB_ADCP_OsampDigFilterEnable( ADCP_MODULE_ID index, ADCP_ODFLTR_ID id )

  Summary:
    Enables the Oversampling Digital Filter in the Pipelined ADC module

  Description:
    This function enables (turns ON) the selected Oversampling Digital Filter in the 
    specified Pipelined ADC module.

  Precondition:
    The Oversampling Digital Filter should be configured using the PLIB_ADCP_Configure()
    function prior to enabling.

  Parameters:
    index           - Identifier for the ADCP instance
    id				- Identifier for the digital Filter in the ADCP module

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Enable OsampDigFilter1
    PLIB_ADCP_OsampDigFilterEnable(MY_ADCP_INSTANCE, ADCP_ODFLTR1);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCP_OsampDigFilterEnable(ADCP_MODULE_ID index, ADCP_ODFLTR_ID id);

// *****************************************************************************
/* Function:
    void PLIB_ADCP_OsampDigFilterDisable( ADCP_MODULE_ID index, ADCP_ODFLTR_ID id )

  Summary:
    Disables the Oversampling Digital Filter in the Pipelined ADC module.

  Description:
    This function Disables (turns OFF) the selected Oversampling Digital Filter in the 
    specified Pipelined ADC module.

  Precondition:
    None. 

  Parameters:
    index           - Identifier for the ADCP instance
    id				- Identifier for the digital Filter in the ADCP module

  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Disable OsampDigFilter1
    PLIB_ADCP_OsampDigFilterDisable(MY_ADCP_INSTANCE, ADCP_ODFLTR1);
    </code>

  Remarks:
    None.
 */

void PLIB_ADCP_OsampDigFilterDisable(ADCP_MODULE_ID index, ADCP_ODFLTR_ID id);

//******************************************************************************
/* Function:
        void PLIB_ADCP_OsampDigFilterConfig( ADCP_MODULE_ID index, // ADCP module ID
                                ADCP_ODFLTR_ID id,	   // Filter ID
                                ADCP_INPUT_ID inputId,	 // Input Id
                                ADCP_ODFLTR_OSR oversampleRatio, // Oversampling ratio
                                bool globalIntEnable ) // Global Int Enable

  Summary:
    Configures the Oversampling Digital Filter on the Pipelined ADC converter.   

  Description:
    Configures all parameters for the Oversampling Digital Filter module of the pipelined
    ADC.

  Precondition:
    The Oversampling Digital Filter module is disabled when calling this function. 

  Parameters:
    index       	- Identifier for the ADCP instance 
    id				- Identifier for the digital Filter in this device
    inputId			- Identifier for the analog input to be oversampled
    oversampleRatio	- Enumerator specifying the oversampling ratio
    globalIntEnable	- When set, Filter events are included in the Global Interrupt
	
  Returns:
    None.

  Example:
    <code>
    // Where MY_ADCP_INSTANCE, is the ADCP instance selected for use by the
    // application developer.
	
    // Configure the Oversampling Digital Filter
    // AN4 is oversampled at a 16X rate.  No global interrupt is enabled. 
    PLIB_ADCP_OsampDigFilterConfig( MY_ADCP_INSTANCE, 	// ADCP module ID
                                   ADCP_ODFLTR1,		// Filter ID
                                   ADCP_AN4,		    // Oversample AN4
                                   ADCP_ODFLTR_16X,		// 16 x oversampling
                                   FALSE );				// No Global Int Enable

    // Enable OsampDigFilter1
    PLIB_ADCP_OsampDigFilterEnable(MY_ADCP_INSTANCE, ADCP_ODFLTR1);
    </code>

  Remarks:
    This function must be called when the ADC is disabled. 
 */

void PLIB_ADCP_OsampDigFilterConfig(ADCP_MODULE_ID index,
                                    ADCP_ODFLTR_ID id,
                                    ADCP_INPUT_ID inputId,
                                    ADCP_ODFLTR_SAMPLE_RATIO oversampleRatio,
                                    bool globalIntEnable);

//******************************************************************************
/* Function:
    bool PLIB_ADCP_OsampDigFilterDataRdy( ADCP_MODULE_ID index, ADCP_ODFLTR_ID id )

  Summary:
    Determines if the Oversampling Digital Filter has data ready.  

  Description:
    This function can be used to determine if the ADCP digital filter has data ready. 
	A TRUE is returned when data is available, which can be fetched using
    PLIB_ADCP_OsampDigFilterDataGet.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCP instance 
        id			- Identifier for the digital Filter in this device
	
  Returns:
    Boolean:
    - true  - Data is ready
	- false - Data is not ready 

  Example:
    <code>
    if (PLIB_ADCP_OsampDigFilterDataRdy(MY_ADCP_INSTANCE, ADCP_ODFLTR_ID_0)) {
                // fetch and process data
        }
    </code>

  Remarks:
    None.
 */

bool PLIB_ADCP_OsampDigFilterDataRdy(ADCP_MODULE_ID index, ADCP_ODFLTR_ID id);

//******************************************************************************
/* Function:
    int16_t PLIB_ADCP_OsampDigFilterDataGet( ADCP_MODULE_ID index, ADCP_ODFLTR_ID dfltrID )

  Summary:
    Fetches the data result from the Oversampling Digital Filter.

  Description:
    This function is used to fetch data from the Oversampling Digital Filter.  
    The format of the data is determined by the oversampling setting
    configuration defined in the call of PLIB_ADCP_OsampDigFilterConfig.
	
  Precondition:
    None.

  Parameters:
    index           - Identifier for the ADCP instance 
    dfltrID			- Identifier for the digital Filter in this device
	
  Returns:
    A 16-bit result in the format specified by the filter's oversampling
    setting.

  Example:
    <code>
    int16_t myODFLTRResult;
	
    if (PLIB_ADCP_OsampDigFilterDataRdy(MY_ADCP_INSTANCE, ADCP_ODFLTR1)) {
        // fetch data
        myODFLTRResult = PLIB_ADCP_OsampDigFilterDataGet(MY_ADCP_INSTANCE, ADCP_ODFLTR1);
        // process result
        ...
    }
    </code>

  Remarks:
    None.
 */

int16_t PLIB_ADCP_OsampDigFilterDataGet(ADCP_MODULE_ID index, ADCP_ODFLTR_ID id);

// *****************************************************************************
// *****************************************************************************
// Section: ADCP Peripheral Library Exists API Routines
// *****************************************************************************
// *****************************************************************************
/* The following functions indicate the existence of the features on the device. 
 */

//******************************************************************************
/* Function :  PLIB_ADCP_ExistsEnableControl( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the EnableControl feature exists on the ADCP module. 

  Description:
    This function identifies whether the EnableControl feature is available on the ADCP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCP_Enable
    - PLIB_ADCP_Disable

  Preconditions:
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

bool PLIB_ADCP_ExistsEnableControl(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsCalibration( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the Calibration feature exists on the ADCP module. 

  Description:
    This function identifies whether the Calibration feature is available on the ADCP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADCP_CalibrationStart

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the Calibration feature: 
    - true   - When Calibration feature is supported on the device
    - false  - When Calibration feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsCalibration(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsConfiguration( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the Configuration feature exists on the ADCP module. 

  Description:
    This function identifies whether the Configuration feature is available on the ADCP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADCP_Configure
	
  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the Configuration feature: 
    - true   - When Configuration feature is supported on the device
    - false  - When Configuration feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsConfiguration(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsLowPowerControl( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the LowPowerControl feature exists on the ADCP module. 

  Description:
    This function identifies whether the LowPowerControl feature is available on the ADCP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCP_LowPowerStateEnter
    - PLIB_ADCP_LowPowerStateExit
    - PLIB_ADCP_LowPowerStateGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the LowPowerControl feature: 
    - true   - When LowPowerControl feature is supported on the device
    - false  - When LowPowerControl feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsLowPowerControl(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsReadyStatus( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the ReadyStatus feature exists on the ADCP module. 

  Description:
    This function identifies whether the ReadyStatus feature is available on the ADCP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADCP_ModuleIsReady

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the ReadyStatus feature: 
    - true   - When ReadyStatus feature is supported on the device
    - false  - When ReadyStatus feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsReadyStatus(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsInputSelect( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the InputSelect feature exists on the ADCP module. 

  Description:
    This function identifies whether the InputSelect feature is available on the ADCP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADCP_DedicatedSHInputSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the InputSelect feature: 
    - true   - When InputSelect feature is supported on the device
    - false  - When InputSelect feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsInputSelect(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsModeSelect( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the ModeSelect feature exists on the ADCP module. 

  Description:
    This function identifies whether the ModeSelect feature is available on the ADCP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_ADCP_SHModeSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the ModeSelect feature: 
    - true   - When ModeSelect feature is supported on the device
    - false  - When ModeSelect feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsModeSelect(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsChannelScan( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the ChannelScan feature exists on the ADCP module. 

  Description:
    This function identifies whether the ChannelScan feature is available on the 
	ADCP module. When this function returns true, this function is supported on 
	the device: 
    - PLIB_ADCP_ChannelScanConfigure
	
  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the ChannelScan feature: 
    - true   - When ChannelScan feature is supported on the device
    - false  - When ChannelScan feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsChannelScan(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsTriggering( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the Triggering feature exists on the ADCP module. 

  Description:
    This function identifies whether the Triggering feature is available on the ADCP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_ADCP_Class12TriggerConfigure
    - PLIB_ADCP_GlobalSoftwareTrigger
    - PLIB_ADCP_IndividualTrigger

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the Triggering feature: 
    - true   - When Triggering feature is supported on the device
    - false  - When Triggering feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsTriggering(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsConversionResults( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the ConversionResults feature exists on the ADCP module. 

  Description:
    This function identifies whether the ConversionResults feature is available 
	on the ADCP module. When this function returns true, these functions are 
	supported on the device: 
    - PLIB_ADCP_ResultReady
    - PLIB_ADCP_ResultGet
    - PLIB_ADCP_ResultReadyGrpIntConfigure
	
  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the ConversionResults feature: 
    - true   - When ConversionResults feature is supported on the device
    - false  - When ConversionResults feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsConversionResults(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsDigCmp( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the DigitalComparator feature exists on the ADCP module. 

  Description:
    This function identifies whether the DigitalComparator feature is available 
	on the ADCP module. When this function returns true, these functions are 
	supported on the device: 
    - PLIB_ADCP_DigCmpConfig
    - PLIB_ADCP_DigCmpEnable
    - PLIB_ADCP_DigCmpDisable
    - PLIB_ADCP_DigCmpAIdGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the DigitalComparator feature: 
    - true   - When DigitalComparator feature is supported on the device
    - false  - When DigitalComparator feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsDigCmp(ADCP_MODULE_ID index);


//******************************************************************************
/* Function :  PLIB_ADCP_ExistsOsampDigFilter( ADCP_MODULE_ID index )

  Summary:
    Identifies whether the OsampDigitalFilter feature exists on the ADCP module. 

  Description:
    This function identifies whether the OsampDigitalFilter feature is available 
	on the ADCP module. When this function returns true, these functions are 
	supported on the device: 
    - PLIB_ADCP_OsampDigFilterConfig
    - PLIB_ADCP_OsampDigFilterEnable
    - PLIB_ADCP_OsampDigFilterDisable
    - PLIB_ADCP_OsampDigFilterDataRdy
    - PLIB_ADCP_OsampDigFilterDataGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    Existence of the OsampDigitalFilter feature: 
    - true   - When OsampDigitalFilter feature is supported on the device
    - false  - When OsampDigitalFilter feature is not supported on the device

  Remarks:
    None.
 */

bool PLIB_ADCP_ExistsOsampDigFilter(ADCP_MODULE_ID index);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/******************************************************************************
 End of File
 */
#endif

