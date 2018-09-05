/***********************************************************************
  Company:
    Microchip Technology Inc.
    
  File Name:
    plib_pmp.h
    
  Summary:
    Parallel Master Port (PMP) Peripheral Library Interface Header.
    
  Description:    
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the PMP
    Peripheral Library.
  ***********************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright 2013-2015 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PLIB_PMP_H
#define _PLIB_PMP_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Include files
// *****************************************************************************
// *****************************************************************************

#include "peripheral/pmp/processor/pmp_processor.h"

// *****************************************************************************
// *****************************************************************************
// Section: PMP Peripheral Library Interface Routines
// *****************************************************************************
// *****************************************************************************

//******************************************************************************
/* Function:
    void PLIB_PMP_ReadCycleStart( PMP_MODULE_ID index )
    
  Summary:
    Starts a read cycle on the PMP bus.
    
  Description:
    This function stars a read cycle on the bus for the selected PMP module.
    This bit is cleared by hardware at the end of the read cycle

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_ReadCycleStart( PMP_ID_0 );
    </code>

  Remarks:
	
	This function implements an operation of the StartReadControl feature.  
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_PMP_ExistsStartReadControl in your application to automatically 
    determine whether this feature is available.
*/

void PLIB_PMP_ReadCycleStart ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    bool PLIB_PMP_ReadCycleIsStarted ( PMP_MODULE_ID index )
    
  Summary:
    Checks whether or not the read cycle on PMP bus is enabled.
    
  Description:
    This function checks whether or not the read cycle on PMP bus is enabled.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    - true 	    - If the PMP Read cycle is enabled
    - false 	- if the PMP Read cycle is not enabled

  Example:
    <code>
    bool pmpReadStartStatus;
    pmpReadStartStatus = PLIB_PMP_ReadCycleIsStarted( PMP_ID_0 );
    </code>

  Remarks:
	This function implements an operation of the StartReadControl feature.  
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_PMP_ExistsStartReadControl in your application to automatically 
    determine whether this feature is available.
*/

bool PLIB_PMP_ReadCycleIsStarted ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_DualBufferEnable ( PMP_MODULE_ID index )
    
  Summary:
    Enables PMP dual Read/Write buffer.
    
  Description:
    This function enables dual Read/Write buffers for PMP module. Once enabled,
    PMP uses separate registers for read and write.
    * Registers used for Reads: PMRADDR and PMRDIN
    * Registers used for Writes: PMRWADDR and PMDOUT

  Precondition:
    The PMP module is configured as a master.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_DualBufferEnable( PMP_ID_0 );
    </code>

  Remarks:
    This feature is only valid in Master mode.
    
    This function implements an operation of the DualBufferControl feature.  
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_PMP_ExistsDualBufferControl in your application to automatically 
    determine whether this feature is available.
*/

void PLIB_PMP_DualBufferEnable ( PMP_MODULE_ID index );


//******************************************************************************
/*Function:
    void PLIB_PMP_DualBufferDisable ( PMP_MODULE_ID index )
    
  Summary:
    Disables the specific PMP module.
    
  Description:
    This function disables the specific PMP module.

  Precondition:
    The PMP module is configured as a master.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_DualBufferDisable( PMP_ID_0 );
    </code>

  Remarks:
    This feature is only valid in Master mode.
    
    This function implements an operation of the DualBufferControl feature.  
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_PMP_ExistsDualBufferControl in your application to automatically 
    determine whether this feature is available.   
*/

void PLIB_PMP_DualBufferDisable ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    bool PLIB_PMP_DualBufferIsEnabled ( PMP_MODULE_ID index )
    
  Summary:
    Checks whether or not the PMP module is enabled.
    
  Description:
    This function checks whether or not the PMP module is enabled.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    - true 	- If the PMP module is enabled
    - false - if the PMP module is disabled 

  Example:
    <code>
    bool pmpStatus;
    pmpStatus = PLIB_PMP_DualBufferIsEnabled( PMP_ID_0 );
    </code>

  Remarks:
    This feature is only valid in Master mode.
    
    This function implements an operation of the DualBufferControl feature.  
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_PMP_ExistsDualBufferControl in your application to automatically 
    determine whether this feature is available.
*/

bool PLIB_PMP_DualBufferIsEnabled ( PMP_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_PMP_Enable ( PMP_MODULE_ID index )
    
  Summary:
    Enables the specific PMP module.
    
  Description:
    This function enables the specific PMP module.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_Enable( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the EnableControl feature.  
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_PMP_ExistsEnableControl in your application to automatically 
    determine whether this feature is available.
*/

void PLIB_PMP_Enable ( PMP_MODULE_ID index );


//******************************************************************************
/*Function:
    void PLIB_PMP_Disable ( PMP_MODULE_ID index )
    
  Summary:
    Disables the specific PMP module.
    
  Description:
    This function disables the specific PMP module.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_Disable( PMP_ID_0 );
    </code>

  Remarks:
    The default state after any reset for a PMP module is the disable state.
    If the PMP is disabled, all the related pins are in control of the 
    general purpose I/O logic.
    
    Disabling the PMP module resets the buffers to empty states. Any data 
    characters in the buffers are lost. All error and status bits are also reset. 
    
    Disabling the PMP while the PMP is active, will abort all pending 
    transmissions and receptions.  Re-enabling the PMP will restart the 
    module in the same configuration. 
    
    When disabled, the PMP power consumption is minimal.

    This function implements an operation of the EnableControl feature.
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsEnableControl in your application to
    to automatically determine whether this feature is available.    
*/

void PLIB_PMP_Disable ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    bool PLIB_PMP_IsEnabled ( PMP_MODULE_ID index )
    
  Summary:
    Checks whether or not the PMP module is enabled.
    
  Description:
    This function checks whether or not the PMP module is enabled.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    - true 	- If the PMP module is enabled
    - false - if the PMP module is disabled 

  Example:
    <code>
    bool pmpStatus;
    pmpStatus = PLIB_PMP_IsEnabled( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the EnableControl feature.
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsEnableControl in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_IsEnabled ( PMP_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_PMP_StopInIdleEnable ( PMP_MODULE_ID index )
    
  Summary:
    Discontinues PMP module operation when the device enters Idle mode.
    
  Description:
    This function enables the PMP module to discontinue operation when the device
    enters Idle mode.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_StopInIdleEnable( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the StopInIdleControl feature.
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsStopInIdleControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_StopInIdleEnable ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_StopInIdleDisable ( PMP_MODULE_ID index )
    
  Summary:
    Enables the PMP module to continue operation in Idle mode.
    
  Description:
    This function disables the stop in idle flag. The PMP module continues
    operation in Idle mode.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_StopInIdleDisable( PMP_ID_0 );
    </code>

  Remarks:
    By default, the PMP module will continue operation in Idle mode.
    
    This function implements an operation of the StopInIdleControl feature.
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsStopInIdleControl in your application to
    to automatically determine whether this feature is available.
    */

void PLIB_PMP_StopInIdleDisable ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_MultiplexModeSelect( PMP_MODULE_ID index, 
                                       PMP_MUX_MODE multiplexMode )
    
  Summary:
    Configures the multiplexing between the address and data of the PMP module.
    
  Description:
    This function configures the pins used by the PMP module. Refer to 
    the enumeration PMP_MUX_MODE for the possible settings.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    multiplexMode	- One of the possible values from the PMP_MUX_MODE
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_MultiplexModeSelect( PMP_ID_0, PMP_MUX_NONE );
    </code>

  Remarks:
    This function implements an operation of the MUXModeSelect feature.
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsMUXModeSelect in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_MultiplexModeSelect( PMP_MODULE_ID index, 
                                   PMP_MUX_MODE multiplexMode );


//******************************************************************************
/* Function:
    PMP_MUX_MODE PLIB_PMP_MultiplexModeGet( PMP_MODULE_ID index )
    
  Summary:
    Gets the current multiplexing mode configured between the address and data of
    the PMP module.
    
  Description:
    This function gets the current multiplexing mode configured between the address
    and data of the PMP module.

  Precondition:
    None.

  Parameters:
    None.
    
  Returns:
    index		    - Identifier for the device instance to be addressed
    PMP_MUX_MODE	- One of the possible values from PMP_MUX_MODE

  Example:
    <code>
    PMP_MUX_MODE currentMuxMode; 
    currentMuxMode = PLIB_PMP_MultiplexModeGet( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the MUXModeSelect feature.
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsMUXModeSelect in your application to
    to automatically determine whether this feature is available.
*/

PMP_MUX_MODE PLIB_PMP_MultiplexModeGet( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_InputBufferTypeSelect ( PMP_MODULE_ID index, 
                                          PMP_INPUT_BUFFER_TYPE inputBuffer )
    
  Summary:
    Selects the input buffer based on the input passed.
    
  Description:
    This function selects the input buffer based on the input passed. Either TTL or
    Schmitt Trigger input buffers are selected.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    inputBuffer		- One of the possible input buffer types
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_InputBufferTypeSelect( PMP_ID_0, PMP_INPUT_BUFFER_TTL );
    </code>

  Remarks:
    This function implements an operation of the BufferType feature.
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsBufferType in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_InputBufferTypeSelect ( PMP_MODULE_ID index, 
                                      PMP_INPUT_BUFFER_TYPE inputBuffer );


//******************************************************************************
/* Function:
    void PLIB_PMP_WriteEnableStrobePortEnable ( PMP_MODULE_ID index )
    
  Summary:
    Enables the PMP module write strobe port.
    
  Description:
    This function enables the write strobe port of the PMP module.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_WriteEnableStrobePortEnable( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the WriteEnablePortControl feature.
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsWriteEnablePortControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_WriteEnableStrobePortEnable ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_WriteEnableStrobePortDisable ( PMP_MODULE_ID index )
    
  Summary:
    Disables the PMP module write strobe port.
    
  Description:
    This function disables the write strobe port of the PMP module.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_WriteEnableStrobePortDisable( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the WriteEnablePortControl feature.
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsWriteEnablePortControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_WriteEnableStrobePortDisable ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_ReadWriteStrobePortEnable ( PMP_MODULE_ID index )
    
  Summary:
    Enables the PMP module read strobe port.
    
  Description:
    This function enables the read strobe port of the PMP module.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_ReadWriteStrobePortEnable( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the ReadWriteStrobePortControl 
    feature. This feature may not be available on all devices. Please refer 
    to the specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsReadWriteStrobePortControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_ReadWriteStrobePortEnable ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_ReadWriteStrobePortDisable ( PMP_MODULE_ID index )
    
  Summary:
    Disables the PMP module read strobe port.
    
  Description:
    This function disables the read strobe port of the PMP module.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_ReadWriteStrobePortDisable( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the ReadWriteStrobePortControl 
    feature. This feature may not be available on all devices. Please refer
    to the specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsReadWriteStrobePortControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_ReadWriteStrobePortDisable ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_ChipSelectFunctionSelect( PMP_MODULE_ID index, 
                                            PMP_CHIPSELECT_FUNCTION chipselfunct )
    
  Summary:
    Defines the functionality of the pins intended to be used as Chip Select.
    
  Description:
    This function selects the PMCS1/PMCS2 as either Chip Select or as address
    lines depending on the way these bits are programmed.

  Precondition:
    None.

  Parameters:
    index		- Identifier for the device instance to be addressed
    chipselfunct	- One of the possible values from PMP_CHIPSELECT_FUNCTION
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_ChipSelectFunctionSelect( PMP_ID_0, PMCS1_PMCS2_AS_ADDRESS_LINES );
    </code>

  Remarks:
    This function implements an operation of the ChipSelectoperation feature.  
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsChipSelectoperation in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_ChipSelectFunctionSelect( PMP_MODULE_ID index, 
                                        PMP_CHIPSELECT_FUNCTION chipselfunct );


//******************************************************************************
/* Function:
    void PLIB_PMP_AddressLatchPolaritySelect( PMP_MODULE_ID index, 
                                              PMP_POLARITY_LEVEL polarity )

  Summary:
    Sets the address latch strobe polarity.

  Description:
    This function sets the address latch polarity to the level specified.

  Precondition:
    None.

  Parameters:
    index		- Identifier for the device instance to be addressed
    polarity	        - Possible polarity levels

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_AddressLatchPolaritySelect( PMP_ID_0, PMP_POLARITY_ACTIVE_HIGH );
    </code>

  Remarks:
    This function implements an operation of the AddressLatchPolarity feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsAddressLatchPolarity in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_AddressLatchPolaritySelect ( PMP_MODULE_ID index, 
                                           PMP_POLARITY_LEVEL polarity );


//******************************************************************************
/* Function:
    void PLIB_PMP_ChipSelectXPolaritySelect ( PMP_MODULE_ID index, 
                                              PMP_CHIP_SELECT chipSelect,
                                              PMP_POLARITY_LEVEL polarity )

  Summary:
    Sets the specified Chip Select polarity.

  Description:
    This function sets the specified Chip Select polarity to the level specified.

  Precondition:
    None.

  Parameters:
    index	    - Identifier for the device instance to be addressed
    chipSelect	- Identifier for Chip Select
    polarity	- Possible polarity levels

  Returns:
    None.

  Example:
    <code>
    PMP_CHIP_SELECT chipSelect = PMP_CHIP_SELECT_ONE;
    PLIB_PMP_ChipSelectXPolaritySelect( PMP_ID_0, 
                                        chipSelect, 
                                        PMP_POLARITY_ACTIVE_HIGH );
    </code>

  Remarks:
    This function implements an operation of the ChipXPolarity feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsChipXPolarity in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_ChipSelectXPolaritySelect ( PMP_MODULE_ID index, 
                                          PMP_CHIP_SELECT chipSelect,
                                          PMP_POLARITY_LEVEL polarity );


//******************************************************************************
/* Function:
    void PLIB_PMP_WriteEnableStrobePolaritySelect ( PMP_MODULE_ID index, 
                                                    PMP_POLARITY_LEVEL polarity )

  Summary:
    Sets the polarity of the write enable strobe.

  Description:
    This function sets the polarity of the write enable strobe to the level 
    specified.

  Precondition:
    None.

  Parameters:
    index		- Identifier for the device instance to be addressed
    polarity	- Possible polarity levels

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_WriteEnableStrobePolaritySelect( PMP_ID_0, PMP_POLARITY_ACTIVE_HIGH );
    </code>

  Remarks:
    This function implements an operation of the WriteEnablePolarity feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsWriteEnablePolarity in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_WriteEnableStrobePolaritySelect ( PMP_MODULE_ID index, 
                                                PMP_POLARITY_LEVEL polarity );


//******************************************************************************
/* Function:
    void PLIB_PMP_ReadWriteStrobePolaritySelect ( PMP_MODULE_ID index, 
                                                  PMP_POLARITY_LEVEL polarity )

  Summary:
    Sets the polarity of the read strobe.

  Description:
    This function sets polarity of the read strobe to the level specified.

  Precondition:
    None.

  Parameters:
    index		- Identifier for the device instance to be addressed
    polarity	- Possible polarity levels

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_ReadWriteStrobePolaritySelect( PMP_ID_0, PMP_POLARITY_ACTIVE_HIGH );
    </code>

  Remarks:
    This function implements an operation of the ReadWritePolarity feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsReadWritePolarity in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_ReadWriteStrobePolaritySelect ( PMP_MODULE_ID index, 
                                              PMP_POLARITY_LEVEL polarity );


//******************************************************************************
/* Function:
     bool	PLIB_PMP_PortIsBusy ( PMP_MODULE_ID index )
    
  Summary:
    Identifies if the (Master mode) PMP port is busy.
    
  Description:
    This function identifies if the PMP port is busy (in Master mode).
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    - true        - If the port is busy
    - false       - If the port is not busy

  Example:
    <code>
    bool status;
    status = PLIB_PMP_PortIsBusy( PMP_ID_0 );
    </code>

  Remarks:
    Works only in Master mode.
    This function implements an operation of the BusyStatus feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsBusyStatus in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_PortIsBusy ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_InterruptModeSelect( PMP_MODULE_ID index, 
                                       PMP_INTERRUPT_MODE interruptMode )
    
  Summary:
    Configures the interrupt request mode being used with the PMP module.
    
  Description:
    This function configures the pins used by the PMP module. Refer to 
    the enumeration PMP_INTERRUPT_MODE for the possible settings.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    interruptMode	- One of the possible values from PMP_INTERRUPT_MODE
    
  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_InterruptModeSelect( PMP_ID_0, PMP_INTERRUPT_NONE );
    </code>

  Remarks:
    This function implements an operation of the InterruptMode feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsInterruptMode in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_InterruptModeSelect( PMP_MODULE_ID index, 
                                   PMP_INTERRUPT_MODE interruptMode );


//******************************************************************************
/* Function:
    PMP_INTERRUPT_MODE PLIB_PMP_InterruptModeGet ( PMP_MODULE_ID index )
    
  Summary:
    Gets the current configured interrupt mode being used with the 
    PMP module.
    
  Description:
    This function gets the current configured interrupt mode being 
    used with the PMP module.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    One of the possible values from PMP_INTERRUPT_MODE.

  Example:
    <code>
    PMP_INTERRUPT_MODE currentIntMode;
    currentIntMode = PLIB_PMP_InterruptModeGet ( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the InterruptMode feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsInterruptMode in your application to
    to automatically determine whether this feature is available.
*/

PMP_INTERRUPT_MODE PLIB_PMP_InterruptModeGet ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_AddressIncrementModeSelect( PMP_MODULE_ID index, 
                                              PMP_INCREMENT_MODE incrementMode )
    
  Summary:
    Configures the increment mode being used with the address of the PMP module.
    
  Description:
    This function configures the pins used by the PMP module. Refer to 
    the enumeration PMP_INCREMENT_MODE for the possible settings.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    incrementMode	- One of the possible values from PMP_INCREMENT_MODE

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_AddressIncrementModeSelect( PMP_ID_0, PMP_ADDRESS_INCREMENT_DECREMENT_DISABLE );
    </code>

  Remarks:
    This function implements an operation of the IncrementMode feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsIncrementMode in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_AddressIncrementModeSelect( PMP_MODULE_ID index, 
                                          PMP_INCREMENT_MODE incrementMode );


//******************************************************************************
/* Function:
    PMP_INCREMENT_MODE PLIB_PMP_AddressIncrementModeGet ( PMP_MODULE_ID index )
    
  Summary:
    Gets the increment mode being used with the address of the PMP module.
    
  Description:
    This function gets the pins used by the PMP module. Refer to 
    the enumeration PMP_INCREMENT_MODE for the possible settings.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    PMP_INCREMENT_MODE	- One of the possible values from PMP_INCREMENT_MODE

  Example:
    <code>
    PMP_INCREMENT_MODE curAddressIncMode;
    curAddressIncMode = PLIB_PMP_AddressIncrementModeGet( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the IncrementMode feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsIncrementMode in your application to
    to automatically determine whether this feature is available.
*/

PMP_INCREMENT_MODE PLIB_PMP_AddressIncrementModeGet ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_DataSizeSelect ( PMP_MODULE_ID index, 
                                   PMP_DATA_SIZE size )
    
  Summary:
    Enables data transfer size for the PMP module.
    
  Description:
    This function enables 4-bit, 8-bit, or 16-bit data transfer for the PMP module.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    size	- Identifier for the data size to be used

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_DataSizeSelect( PMP_ID_0, PMP_DATA_SIZE_8_BITS );
    </code>

  Remarks:
    This function implements an operation of the DataTransferSize feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsDataTransferSize in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_DataSizeSelect ( PMP_MODULE_ID index, 
                               PMP_DATA_SIZE size );


//******************************************************************************
/* Function:
    void PLIB_PMP_OperationModeSelect( PMP_MODULE_ID index, 
                                       PMP_OPERATION_MODE operationMode )
    
  Summary:
    Configures the operation mode of the PMP module.
    
  Description:
    This function configures operation mode of the PMP module. Refer to 
    the enumeration PMP_OPERATION_MODE for the possible settings.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    operationMode	- One of the possible values from PMP_OPERATION_MODE

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_OperationModeSelect( PMP_ID_0, 
                                  PMP_MASTER_READ_WRITE_STROBES_MULTIPLEXED );
    </code>

  Remarks:
    This function implements an operation of the OperationMode feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsOperationMode in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_OperationModeSelect( PMP_MODULE_ID index, 
                                   PMP_OPERATION_MODE operationMode );


//******************************************************************************
/* Function:
    PMP_OPERATION_MODE PLIB_PMP_OperationModeGet ( PMP_MODULE_ID index )
    
  Summary:
    Gets the current operation mode of the PMP module.
    
  Description:
    This function gets the current operation mode of the PMP module.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    PMP_OPERATION_MODE	- One of the possible values from PMP_OPERATION_MODE

  Example:
    <code>
    PMP_OPERATION_MODE curOpMode;
    curOpMode = PLIB_PMP_OperationModeGet( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the OperationMode feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsOperationMode in your application to
    to automatically determine whether this feature is available.
*/

PMP_OPERATION_MODE PLIB_PMP_OperationModeGet ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_WaitStatesDataSetUpSelect( PMP_MODULE_ID index, 
                                             PMP_DATA_WAIT_STATES dataWaitState )
    
  Summary:
    Configures the data wait states (before the data transfer) needed to be used 
    with the PMP module.
    
  Description:
    This function configures the number of peripheral bus clock cycles needed for
    wait states. Refer to the enumeration PMP_DATA_WAIT_STATES for the 
    possible settings.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    dataWaitState	- One of the possible values from PMP_DATA_WAIT_STATES

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_WaitStatesDataSetUpSelect( PMP_ID_0, PMP_DATA_WAIT_TWO );
    </code>

  Remarks:
    This function implements an operation of the DataSetUpWaitStates feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsDataSetUpWaitStates in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_WaitStatesDataSetUpSelect( PMP_MODULE_ID index, 
                                         PMP_DATA_WAIT_STATES dataWaitState );


//******************************************************************************
/* Function:
    void PLIB_PMP_WaitStatesStrobeSelect( PMP_MODULE_ID index, 
                                          PMP_STROBE_WAIT_STATES strobeWaitState )
    
  Summary:
    Configures the strobe wait states (during the data transfer) needed to be 
    used with the PMP module.
    
  Description:
    This function configures the number of peripheral bus clock cycles needed for
    wait states. Refer to the enumeration PMP_STROBE_WAIT_STATES for the 
    possible settings.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    strobeWaitState	- One of the possible values from PMP_STROBE_WAIT_STATES

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_WaitStatesStrobeSelect( PMP_ID_0, PMP_STROBE_WAIT_2 );
    </code>

  Remarks:
    This function implements an operation of the DataStrobeWaitStates feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use
     PLIB_PMP_ExistsDataStrobeWaitStates in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_WaitStatesStrobeSelect( PMP_MODULE_ID index, 
                                      PMP_STROBE_WAIT_STATES strobeWaitState );


//******************************************************************************
/* Function:
    void PLIB_PMP_WaitStatesDataHoldSelect( PMP_MODULE_ID index, 
                                            PMP_DATA_HOLD_STATES dataHoldState )
    
  Summary:
    Configures the data hold states (after data transfer) needed to be used with 
    the PMP module.
    
  Description:
    This function configures the number of peripheral bus clock cycles needed for 
    wait states. Refer to the enumeration PMP_DATA_HOLD_STATES for the possible 
    settings.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    dataHoldState	- One of the possible values from PMP_DATA_HOLD_STATES

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_WaitStatesDataHoldSelect( PMP_ID_0, PMP_DATA_HOLD_2 );
    </code>

  Remarks:
    This function implements an operation of the DataHoldWaitStates feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsDataHoldWaitStates in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_WaitStatesDataHoldSelect( PMP_MODULE_ID index, 
                                        PMP_DATA_HOLD_STATES dataHoldState );


//******************************************************************************
/* Function:
    void PLIB_PMP_ChipSelectXEnable( PMP_MODULE_ID index, 
                                     PMP_CHIP_SELECT chipSelect )
    
  Summary:
    Configures the Chip Select.
    
  Description:
    This function configures the Chip Select(s) being used by the PMP module.
    The specified Chip Select pin functions as chipSelect.

  Precondition:
    None.

  Parameters:
    index		- Identifier for the device instance to be addressed
    chipSelect	- Identifier for which Chip Select to configure
    
  Returns:
    None.

  Example:
    <code>
    PMP_CHIP_SELECT chipSelect = PMP_CHIP_SELECT_ONE;
    PLIB_PMP_ChipSelectXEnable( PMP_ID_0, chipSelect );
    </code>

  Remarks:
    This function implements an operation of the ChipSelectEnable feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsChipSelectEnable in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_ChipSelectXEnable( PMP_MODULE_ID index, 
                                 PMP_CHIP_SELECT chipSelect );


//******************************************************************************
/* Function:
    void PLIB_PMP_ChipSelectXDisable( PMP_MODULE_ID index, 
                                      PMP_CHIP_SELECT chipSelect )
    
  Summary:
    Configures the Chip Select.
    
  Description:
    This function configures the Chip Select(s) being used by the PMP module.
    The specified Chip Select pin functions as the address pin.

  Precondition:
    None.

  Parameters:
    index		- Identifier for the device instance to be addressed
    chipSelect	- Identifier for which Chip Select to configure
    
  Returns:
    None.

  Example:
    <code>
    PMP_CHIP_SELECT chipSelect = PMP_CHIP_SELECT_ONE;
    PLIB_PMP_ChipSelectXDisable( PMP_ID_0, chipSelect );
    </code>

  Remarks:
    This function implements an operation of the ChipSelectEnable feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsChipSelectEnable in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_ChipSelectXDisable( PMP_MODULE_ID index, 
                                  PMP_CHIP_SELECT chipSelect );

//******************************************************************************
/* Function:
    void PLIB_PMP_WriteChipSelectXEnable( PMP_MODULE_ID index, 
                                     PMP_CHIP_SELECT chipSelect )
    
  Summary:
    Configures the Write Chip Select.
    
  Description:
    This function configures the Write Chip Select(s) being used by the PMP module.
    The specified Chip Select pin functions as chipSelect.

  Precondition:
    The PMP module is configured as master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.

  Parameters:
    index		- Identifier for the device instance to be addressed
    chipSelect	- Identifier for which Chip Select to configure
    
  Returns:
    None.

  Example:
    <code>
    PMP_CHIP_SELECT chipSelect = PMP_CHIP_SELECT_ONE;
    PLIB_PMP_WriteChipSelectXEnable( PMP_ID_0, chipSelect );
    </code>

  Remarks:
    This function implements an operation of the WriteChipSelectEnable feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsWriteChipSelectEnable in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_WriteChipSelectXEnable( PMP_MODULE_ID index, 
                                 PMP_CHIP_SELECT chipSelect );


//******************************************************************************
/* Function:
    void PLIB_PMP_WriteChipSelectXDisable( PMP_MODULE_ID index, 
                                      PMP_CHIP_SELECT chipSelect )
    
  Summary:
    Configures the Write Chip Select.
    
  Description:
    This function configures the Write Chip Select(s) being used by the PMP
    module. The specified Chip Select pin functions as the address pin.

  Precondition:
    The PMP module is configured as master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.

  Parameters:
    index		- Identifier for the device instance to be addressed
    chipSelect	- Identifier for which Chip Select to configure
    
  Returns:
    None.

  Example:
    <code>
    PMP_CHIP_SELECT chipSelect = PMP_CHIP_SELECT_ONE;
    PLIB_PMP_WriteChipSelectXDisable( PMP_ID_0, chipSelect );
    </code>

  Remarks:
    This function implements an operation of the WriteChipSelectEnable feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsWriteChipSelectEnable in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_WriteChipSelectXDisable( PMP_MODULE_ID index, 
                                  PMP_CHIP_SELECT chipSelect );

//******************************************************************************
/* Function:
    void PLIB_PMP_ReadChipSelectXEnable( PMP_MODULE_ID index, 
                                     PMP_CHIP_SELECT chipSelect )
    
  Summary:
    Configures the Read Chip Select.
    
  Description:
    This function configures the Read Chip Select(s) being used by the PMP module.
    The specified Chip Select pin functions as chipSelect.

  Precondition:
    The PMP module is configured as master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.

  Parameters:
    index		- Identifier for the device instance to be addressed
    chipSelect	- Identifier for which Chip Select to configure
    
  Returns:
    None.

  Example:
    <code>
    PMP_CHIP_SELECT chipSelect = PMP_CHIP_SELECT_ONE;
    PLIB_PMP_ReadChipSelectXEnable( PMP_ID_0, chipSelect );
    </code>

  Remarks:
    This function implements an operation of the ReadChipSelectEnable feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsReadChipSelectEnable in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_ReadChipSelectXEnable( PMP_MODULE_ID index, 
                                 PMP_CHIP_SELECT chipSelect );


//******************************************************************************
/* Function:
    void PLIB_PMP_ReadChipSelectXDisable( PMP_MODULE_ID index, 
                                      PMP_CHIP_SELECT chipSelect )
    
  Summary:
    Configures the Read Chip Select.
    
  Description:
    This function configures the Read Chip Select(s) being used by the PMP
    module. The specified Chip Select pin functions as the address pin.

  Precondition:
    The PMP module is configured as master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.

  Parameters:
    index		- Identifier for the device instance to be addressed
    chipSelect	- Identifier for which Chip Select to configure
    
  Returns:
    None.

  Example:
    <code>
    PMP_CHIP_SELECT chipSelect = PMP_CHIP_SELECT_ONE;
    PLIB_PMP_ReadChipSelectXDisable( PMP_ID_0, chipSelect );
    </code>

  Remarks:
    This function implements an operation of the ReadChipSelectEnable feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsReadChipSelectEnable in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_ReadChipSelectXDisable( PMP_MODULE_ID index, 
                                  PMP_CHIP_SELECT chipSelect ); 
                                  
//******************************************************************************
/* Function:
    void PLIB_PMP_AddressSet ( PMP_MODULE_ID index, 
                               uint32_t address )

  Summary:
    Sets the current address of the PMP module to the specified address.

  Description:
    This function sets the current address of the PMP module to the specified 
    value.

  Precondition:
    None.

  Parameters:
    index		- Identifier for the device instance to be addressed
    address		- Device address to be set
    
  Returns:
    None. 

  Example:
    <code>
    uint8_t no_of_addressLines = 8;
    PLIB_PMP_AddressSet( PMP_ID_0, 0xff );
    </code>

  Remarks:
    This function implements an operation of the AddressControl feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsAddressControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_AddressSet ( PMP_MODULE_ID index, 
                           uint32_t address );
                           
                           
//******************************************************************************
/* Function:
    uint32_t PLIB_PMP_AddressGet ( PMP_MODULE_ID index )

  Summary:
    Gets the current address of the PMP module.

  Description:
    This function gets the current address of the PMP module.

  Precondition:
    None.

  Parameters:
    index		- Identifier for the device instance to be addressed
    
  Returns:
    * address	- Device address to be set

  Example:
    <code>
    uint32_t address;
    address = PLIB_PMP_AddressGet( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the AddressControl feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsAddressControl in your application to
    to automatically determine whether this feature is available.
*/

uint32_t PLIB_PMP_AddressGet ( PMP_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_PMP_DualModeWriteAddressSet ( PMP_MODULE_ID index, 
                               uint32_t writeAddress )

  Summary:
    Sets the address to be written in Dual mode.

  Description:
    This function sets the address to be written to the specified 
    value in Dual mode.

  Precondition:
    The PMP module is configured as master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.

  Parameters:
    index		        - Identifier for the device instance to be addressed
    writeAddress		- Device write address to be set
    
  Returns:
    None. 

  Example:
    <code>
    uint8_t no_of_addressLines = 8;
    PLIB_PMP_DualModeWriteAddressSet( PMP_ID_0, 0xff );
    </code>

  Remarks:
    This function implements an operation of the DualModeWriteAddressControl
    feature. This feature may not be available on all devices. Please refer
    to the specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsDualModeWriteAddressControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_DualModeWriteAddressSet ( PMP_MODULE_ID index, 
                           uint32_t writeAddress );
                           
                           
//******************************************************************************
/* Function:
    uint32_t PLIB_PMP_DualModeWriteAddressGet ( PMP_MODULE_ID index )

  Summary:
    Gets the current write address of the PMP module.

  Description:
    This function gets the current write address of the PMP module.

  Precondition:
    The PMP module is configured as a master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.

  Parameters:
    index		- Identifier for the device instance to be addressed
    
  Returns:
    * writeAddress		- Device Write address to be set

  Example:
    <code>
    uint32_t address;
    address = PLIB_PMP_DualModeWriteAddressGet( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the DualModeWriteAddressControl
    feature. This feature may not be available on all devices. Please refer
    to the specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsDualModeWriteAddressControl in your application to
    to automatically determine whether this feature is available.
*/

uint32_t PLIB_PMP_DualModeWriteAddressGet ( PMP_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_PMP_DualModeReadAddressSet ( PMP_MODULE_ID index, 
                               uint32_t readAddress )

  Summary:
    Sets the address to be written in Dual mode.

  Description:
    This function sets the address to be written to the specified 
    value in Dual mode.

  Precondition:
    The PMP module is configured as a master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.

  Parameters:
    index		        - Identifier for the device instance to be addressed
    readAddress		    - Device address from where PMP read will happen
    
  Returns:
    None. 

  Example:
    <code>
    uint8_t no_of_addressLines = 8;
    PLIB_PMP_DualModeReadAddressSet( PMP_ID_0, 0xff );
    </code>

  Remarks:
    This function implements an operation of the DualModeReadAddressControl
    feature. This feature may not be available on all devices. Please refer
    to the specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsDualModeReadAddressControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_DualModeReadAddressSet ( PMP_MODULE_ID index, 
                           uint32_t readAddress );
                           
                           
//******************************************************************************
/* Function:
    uint32_t PLIB_PMP_DualModeReadAddressGet ( PMP_MODULE_ID index )

  Summary:
    Gets the current read address of the PMP module.

  Description:
    This function gets the current read address of the PMP module.

  Precondition:
    The PMP module is configured as a master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.
    
  Parameters:
    index		- Identifier for the device instance to be addressed
    
  Returns:
    * readAddress		- Device address from where PMP read will occur

  Example:
    <code>
    uint32_t readAddress;
    readAddress = PLIB_PMP_DualModeReadAddressGet( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the DualModeReadAddressControl
    feature. This feature may not be available on all devices. Please refer
    to the specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsDualModeReadAddressControl in your application to
    to automatically determine whether this feature is available.
*/

uint32_t PLIB_PMP_DualModeReadAddressGet ( PMP_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_PMP_AddressLinesA0A1Set ( PMP_MODULE_ID index, 
                                        uint8_t address )

  Summary:
    Sets the address lines PMA0 and PMA1 with the value specified.

  Description:
    This function sets the address lines PMA0 and PMA1 with the value 
    specified. This function is used in the addressable parallel slave port
    mode.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    address	- The two-bit address
    
  Returns:
    None.

  Example:
    <code>
    uint8_t bufferAddress = 0x2;
    PLIB_PMP_AddressLinesA0A1Set( PMP_ID_0, bufferAddress );
    </code>

  Remarks:
    This function implements an operation of the AddressControl feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsAddressControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_AddressLinesA0A1Set ( PMP_MODULE_ID index, 
                                    uint8_t address );


//******************************************************************************
/* Function:
    uint8_t PLIB_PMP_AddressLinesA0A1Get ( PMP_MODULE_ID index )

  Summary:
    Gets the value of the address lines PMA0 and PMA1.

  Description:
    This function gets the value of the address lines PMA0 and PMA1.
    This function is used in the addressable parallel slave port mode.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    uint8_t	- The two-bit address

  Example:
    <code>
    uint8_t bufferAddress;
    bufferAddress = PLIB_PMP_AddressLinesA0A1Get( PMP_ID_0 );
    </code>

  Remarks:
    This function implements an operation of the AddressControl feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsAddressControl in your application to
    to automatically determine whether this feature is available.
*/

uint8_t PLIB_PMP_AddressLinesA0A1Get ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_AddressPortEnable ( PMP_MODULE_ID index, 
                                      PMP_ADDRESS_PORT portfunctions )

  Summary:
    Enables the port lines specified as PMP address lines.

  Description:
    This function enables the port lines specified as PMP address lines.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    portfunctions	- One of the possible values from PMP_ADDRESS_PORT

  Returns:
    None.

  Example:
    <code>
    //Example-1
    PMP_ADDRESS_PORT portfunctions = PMP_PMA2_TO_PMA13_PORTS;
    PLIB_PMP_AddressPortEnable( PMP_ID_0, PMP_PMA2_TO_PMA13_PORTS );
    
    //Example-2
    PLIB_PMP_AddressPortEnable( PMP_ID_0, 
                               ( PMP_PMA14_PORT | PMP_PMA15_PORT ) );
    </code>

  Remarks:
    This function implements an operation of the AddressPortPinControl feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsAddressPortPinControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_AddressPortEnable ( PMP_MODULE_ID index, 
                                  PMP_ADDRESS_PORT portfunctions );


//******************************************************************************
/* Function:
    void PLIB_PMP_AddressPortDisable ( PMP_MODULE_ID index, 
                                       PMP_ADDRESS_PORT portfunctions )

  Summary:
    Disables the port lines specified as PMP address lines.

  Description:
    This function disables the port lines specified as PMP address lines. They 
    function as normal I/O lines.

  Precondition:
    None.

  Parameters:
    index		    - Identifier for the device instance to be addressed
    portfunctions	- One of the possible values from PMP_ADDRESS_PORT
    
  Returns:
    None.

  Example:
    <code>
    //Example-1
    PMP_ADDRESS_PORT portfunctions = PMP_PMA2_TO_PMA13_PORTS;
    PLIB_PMP_AddressPortDisable( PMP_ID_0, PMP_PMA2_TO_PMA13_PORTS );
    
    //Example-2
    PLIB_PMP_AddressPortDisable( PMP_ID_0, 
                                ( PMP_PMA14_PORT | PMP_PMA15_PORT ) );
    </code>

  Remarks:
    This function implements an operation of the AddressPortPinControl feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsAddressPortPinControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_AddressPortDisable ( PMP_MODULE_ID index, 
                                   PMP_ADDRESS_PORT portfunctions );


//******************************************************************************
/* Function:
    void PLIB_PMP_AddressLatchStrobeEnable ( PMP_MODULE_ID index, 
                                             PMP_ADDRESS_LATCH latch )
    
  Summary:
    Enables the specific address latch strobe.
    
  Description:
    This function enables the PMP module with a specific address latch strobe 
    depending on which strobes are needed.

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    latch	- Identifier for the latch to be enabled

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_AddressLatchStrobeEnable( PMP_ID_0, PMP_ADDRESS_LATCH_UPPER );
    PLIB_PMP_AddressLatchStrobeEnable( PMP_ID_0, PMP_ADDRESS_LATCH_HIGH );
    PLIB_PMP_AddressLatchStrobeEnable( PMP_ID_0, PMP_ADDRESS_LATCH_LOW );
    </code>

  Remarks:
    This function implements an operation of the AddressLatchStrobePortControl 
    feature. This feature may not be available on all devices. Please refer to 
    the specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsAddressLatchStrobePortControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_AddressLatchStrobeEnable ( PMP_MODULE_ID index, 
                                         PMP_ADDRESS_LATCH latch );


//******************************************************************************
/* Function:
    void PLIB_PMP_AddressLatchStrobeDisable ( PMP_MODULE_ID index, 
                                              PMP_ADDRESS_LATCH latch )
    
  Summary:
    Disables the specific address latch strobe.
    
  Description:
    This function disables the PMP module with a specific address latch strobe 
    depending on which strobes are not needed. 

  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    latch	- Identifier for the latch to be disabled

  Returns:
    None.

  Example:
    <code>
    PLIB_PMP_AddressLatchStrobeDisable( PMP_ID_0, PMP_ADDRESS_LATCH_UPPER );
    PLIB_PMP_AddressLatchStrobeDisable( PMP_ID_0, PMP_ADDRESS_LATCH_HIGH );
    PLIB_PMP_AddressLatchStrobeDisable( PMP_ID_0, PMP_ADDRESS_LATCH_LOW );
    </code>

  Remarks:
    This function implements an operation of the AddressLatchStrobePortControl 
    feature. This feature may not be available on all devices. Please refer to 
    the specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsAddressLatchStrobePortControl in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_AddressLatchStrobeDisable ( PMP_MODULE_ID index, 
                                          PMP_ADDRESS_LATCH latch );


//******************************************************************************
/* Function:
    bool PLIB_PMP_InputBuffersAreFull ( PMP_MODULE_ID index )
    
  Summary:
    Gets the state of the input buffers.    
    
  Description:
    This function gets the state of the input buffers. 
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    - true	-  If all input buffers are full
    - false	-  If all input buffers are not full
    
  Example:
    <code>
    uint8_t value;
    if(PLIB_PMP_InputBuffersAreFull( PMP_ID_0 ))
    {
     value = PLIB_PMP_InputBufferXByteReceive( PMP_ID_0, 1 );
    }
    </code>

  Remarks:
    This function implements an operation of the InputBufferFull feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsInputBufferFull in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_InputBuffersAreFull ( PMP_MODULE_ID index );


//***********************************************************************
/*
  Function:
      bool PLIB_PMP_InputOverflowHasOccurred ( PMP_MODULE_ID index )
    
  Summary:
    Identifies if there was a receiver overflow error.
    
  Description:
    This function identifies if there was a receiver overflow error.
    
  Conditions:
    None.
    
  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Return:
    - true  - If the input buffer has overflowed
    - false - If the input buffer has not overflowed
    
  Example:
    <code>
    if(PLIB_PMP_InputOverflowHasOccurred( PMP_ID_0 ))
    {
        PLIB_PMP_InputOverflowClear( PMP_ID_0 );
    }
    </code>
    
  Remarks:
    This function implements an operation of the BufferOverFlow feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsBufferOverFlow in your application to
    to automatically determine whether this feature is available.
 */

bool PLIB_PMP_InputOverflowHasOccurred ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_InputOverflowClear ( PMP_MODULE_ID index )
    
  Summary:
    Clears a PMP Overflow error.
    
  Description:
    This function clears an overflow error.  Clearing the error resets the
    receive buffer.
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    if(PLIB_PMP_InputOverflowHasOccurred( PMP_ID_0 ))
    {
        PLIB_PMP_InputOverflowClear( PMP_ID_0 );
    }
    </code>

  Remarks:
    This function implements an operation of the BufferOverFlow feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsBufferOverFlow in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_InputOverflowClear ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    bool PLIB_PMP_InputBufferXIsFull ( PMP_MODULE_ID index, 
                                       uint8_t buffer )
    
  Summary:
    Gets the state of the identified input buffer.
    
  Description:
    This function gets the state of the identified input buffer.
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    buffer	- The input buffer number (valid values are 0 to 3)
    
  Returns:
    - true	-  If all input buffers are full
    - false	-  If all input buffers are not full
    
  Example:
    <code>
    uint8_t value;
    // Check the status of buffer-2
    if(PLIB_PMP_InputBufferXIsFull( PMP_ID_0, 2 ))
    {
       // get data from buffer 2
       value = PLIB_PMP_InputBufferXByteReceive( PMP_ID_0, 2 );
    }
    </code>

  Remarks:
    This function implements an operation of the InputBufferXStatus feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsInputBufferXStatus in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_InputBufferXIsFull ( PMP_MODULE_ID index, 
                                   uint8_t buffer );
                                   
                                   
//******************************************************************************
/* Function:
    bool PLIB_PMP_IsDataReceived ( PMP_MODULE_ID index, 
                                   uint8_t buffer )
    
  Summary:
    Checks and returns if the data has been received in the specified buffer in
    Slave mode.
    
  Description:
    This function checks and returns if the data has been received in the 
    specified buffer in Slave mode.
    
  Precondition:
    The PMP module should be configured for Slave mode operation.

  Parameters:
    index	- Identifier for the device instance to be addressed
    buffer	- One of the possible input buffers (valid values are 0 to 3)
    
  Returns:
    - true	- Data has been received in the specified buffer
    - false	- Data has not been received in the specified buffer
    
  Example:
    <code>
    int8_t data;
    // Check if data is received on buffer-2
    if(PLIB_PMP_IsDataReceived( PMP_ID_0, 2 ))
    {
        // get data from buffer-2
        data = PLIB_PMP_InputBufferXByteReceive( PMP_ID_0, 2 );
    }
    </code>

  Remarks:
    This function implements an operation of the InputBufferXStatus feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsInputBufferXStatus in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_IsDataReceived ( PMP_MODULE_ID index, 
                               uint8_t buffer );


//******************************************************************************
/* Function:
    bool PLIB_PMP_OutputBuffersAreEmpty ( PMP_MODULE_ID index )
    
  Summary:
    Gets the state of the output buffers.
    
  Description:
    This function returns the state of the output buffers. 
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    - true   -  If all output buffers are empty
    - false  -  If all output buffers are not empty

  Example:
    <code>
    uint8_t value=0xEF;
    
    if(PLIB_PMP_OutputBuffersAreEmpty( PMP_ID_0 ))
    {
     PLIB_PMP_OutputBufferXByteSend( PMP_ID_0, 1, value);
    }
    </code>

  Remarks:
    This function implements an operation of the OutPutBufferEmpty feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsOutPutBufferEmpty in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_OutputBuffersAreEmpty ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    bool PLIB_PMP_OutputUnderflowHasOccurred ( PMP_MODULE_ID index )
    
  Summary:
    Identifies if there was an output buffer sent out with no data.
    
  Description:
    This function identifies if there was a output buffer was sent out with 
    no data.
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    - true	- If the input buffer was empty when data was sent
    - false	- If the output buffer was not empty when data was sent

  Example:
    <code>
    if(PLIB_PMP_OutputUnderflowHasOccurred( PMP_ID_0 ))
    {
        PLIB_PMP_OutputUnderflowClear( PMP_ID_0 );
    }
    </code>

  Remarks:
    This function implements an operation of the BufferUnderFlow feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsBufferUnderFlow in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_OutputUnderflowHasOccurred ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    void PLIB_PMP_OutputUnderflowClear ( PMP_MODULE_ID index )
    
  Summary:
   Clears a PMP output underflow error.
    
  Description:
    This function clears a PMP output underflow error.
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    
  Returns:
    None.

  Example:
    <code>
    if(PLIB_PMP_OutputUnderflowHasOccurred( PMP_ID_0 ))
    {
        PLIB_PMP_OutputUnderflowClear( PMP_ID_0 );
    }
    </code>

  Remarks:
    This function implements an operation of the BufferUnderFlow feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsBufferUnderFlow in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_OutputUnderflowClear ( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    bool PLIB_PMP_OutputBufferXIsEmpty ( PMP_MODULE_ID index, 
                                         uint8_t buffer )
    
  Summary:
    Gets the state of the input buffer.
    
  Description:
    This function returns the state of the input buffer. 
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    buffer	- Output buffer number (valid range is 0 to 3)
    
  Returns:
    - true	-  If the identified output buffer is empty
    - false	-  If the identified output buffer is not empty

  Example:
    <code>
    uint8_t value = 0xEF;
    
    if(PLIB_PMP_OutputBufferXIsEmpty( PMP_ID_0, 1 ) )
    {
     PLIB_PMP_OutputBufferXByteSend( PMP_ID_0,1, value);
    }
    </code>

  Remarks:
    This function implements an operation of the OutputBufferXStatus feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsOutputBufferXStatus in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_OutputBufferXIsEmpty ( PMP_MODULE_ID index, 
                                     uint8_t buffer );
                                     
                                     
//******************************************************************************
/* Function:
    bool PLIB_PMP_IsDataTransmitted ( PMP_MODULE_ID index, 
                                      uint8_t buffer )
    
  Summary:
    Checks and returns if the data has been transmitted from the specified buffer
    in Slave mode.
    
  Description:
    This function checks and returns if data has been transmitted from the specified 
	buffer.
    
  Precondition:
    The PMP module should be configured for Slave mode operation.

  Parameters:
    index	- Identifier for the device instance to be addressed
    buffer	- One of the possible output buffers (valid range is 0 to 3)
    
  Returns:
    - true	- If data has been transmitted from the specified buffer
    - false	- If data has not been transmitted from the specified buffer
    
  Example:
    <code>
    uint8_t data;
    if(PLIB_PMP_IsDataTransmitted( PMP_ID_0, 2 ))
    {
        PLIB_PMP_OutputBufferXByteSend( PMP_ID_0, 2, data );
    }
    </code>

  Remarks:
    This function implements an operation of the OutputBufferXStatus feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsOutputBufferXStatus in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_IsDataTransmitted ( PMP_MODULE_ID index, 
                                  uint8_t buffer );


//******************************************************************************
/* Function:
    uint8_t PLIB_PMP_InputBufferXByteReceive ( PMP_MODULE_ID index, 
                                               uint8_t buffer )
    
  Summary:
    Data to be received in Byte mode.
    
  Description:
    This function specifies the data to be received in Byte mode from the desired
	PMP module.
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    buffer	- One of the possible buffers (valid values are 0 to 3)
    
  Returns:
    * data	- Data to be received

  Example:
    <code>
    uint8_t mydata;
    if(!PLIB_PMP_PortIsBusy( PMP_ID_0 ))
    {
        // get data from buffer-1
        mydata = PLIB_PMP_InputBufferXByteReceive( PMP_ID_0, 1 );
    }
    </code>

  Remarks:
    This function implements an operation of the BufferRead feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsBufferRead in your application to
    to automatically determine whether this feature is available.
*/

uint8_t PLIB_PMP_InputBufferXByteReceive( PMP_MODULE_ID index, 
                                          uint8_t buffer );                                         
                                          

//******************************************************************************
/* Function:
    void PLIB_PMP_OutputBufferXByteSend ( PMP_MODULE_ID index, 
                                          uint8_t buffer, 
                                          uint8_t data )
    
  Summary:
    Data to be transmitted in Byte mode.
    
  Description:
    This function specifies the data to be transmitted in Byte mode for the desired
	PMP module.
    
  Precondition:
    None.

  Parameters:
    index	- Identifier for the device instance to be addressed
    buffer	- One of the possible output buffers (valid range is 0 to 3)
    data	- Data to be transmitted
    
  Returns:
    None.

  Example:
    <code>
    uint8_t data = 'a';
    if(!PLIB_PMP_PortIsBusy( PMP_ID_0 ))
    {
        PLIB_PMP_OutputBufferXByteSend( PMP_ID_0, 1, data );
    }
    </code>

  Remarks:
    This function implements an operation of the BufferWrite feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsBufferWrite in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_OutputBufferXByteSend ( PMP_MODULE_ID index, 
                                      uint8_t buffer, 
                                      uint8_t data );

                     					 
//******************************************************************************
/* Function:
    void PLIB_PMP_MasterSend ( PMP_MODULE_ID index, 
                         		uint16_t data )

  Summary:
    Sends the specified data in Master mode.

  Description:
    This function sends the specified data. The data flow is from master to 
    slave.

  Precondition:
    The PMP module is configured for Master mode.

  Parameters:
    index	- Identifier for the device instance to be addressed
    data  	- Data to be transmitted

  Returns:
    None.

  Example:
    <code>
    uint16_t data = 'a';
    if(!PLIB_PMP_PortIsBusy( PMP_ID_0 ))
    {
        PLIB_PMP_MasterSend( PMP_ID_0, data );
    }
    </code>

  Remarks:
    This function to be used only when the PMP is acting as master.
    This function implements an operation of the MasterRXTX feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsMasterRXTX in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_MasterSend ( 	PMP_MODULE_ID index, 
                     		uint16_t data );
                     
//******************************************************************************
/* Function:
    uint16_t PLIB_PMP_MasterReceive ( PMP_MODULE_ID index )

  Summary:
    Receives the data in Master mode.

  Description:
    This function receives the data. The flow of data is from the slave to the 
	master.

  Precondition:
    The PMP module is configured as a master.

  Parameters:
    index	- Identifier for the device instance to be addressed.

  Returns:
    uint16_t    - Data received

  Example:
    <code>
    uint16_t data;
    if(!PLIB_PMP_PortIsBusy( PMP_ID_0 ))
    {
        data = PLIB_PMP_MasterReceive( PMP_ID_0 );
    }
    </code>

  Remarks:
    This function to be used only when the PMP is acting as master.
    This function implements an operation of the MasterRXTX feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsMasterRXTX in your application to
    to automatically determine whether this feature is available.
*/

uint16_t PLIB_PMP_MasterReceive ( PMP_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_PMP_DualModeMasterSend ( PMP_MODULE_ID index, 
                         		uint16_t data )

  Summary:
    Sends the specified data in Dual Master mode.

  Description:
    This function sends the specified data in dual mode. The data flow is from
    master to slave.

  Precondition:
    The PMP module is configured as a master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.

  Parameters:
    index	- Identifier for the device instance to be addressed
    data  	- Data to be transmitted

  Returns:
    None.

  Example:
    <code>
    uint16_t data = 'a';
    if(!PLIB_PMP_PortIsBusy( PMP_ID_0 ))
    {
        PLIB_PMP_DualModeMasterSend( PMP_ID_0, data );
    }
    </code>

  Remarks:
    This function to be used only when the PMP is acting as master.
    This function implements an operation of the DualModeMasterRXTX feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsDualModeMasterRXTX in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_DualModeMasterSend ( 	PMP_MODULE_ID index, 
                     		uint16_t data );
                     
//******************************************************************************
/* Function:
    uint16_t PLIB_PMP_DualModeMasterReceive ( PMP_MODULE_ID index )

  Summary:
    Receives the data in the Master Dual mode.

  Description:
    This function receives the data in Dual mode. The flow of data is from the slave 
	to the master.

  Precondition:
    The PMP module is configured as a master.
    PMP Dual mode should be enabled using the API PLIB_PMP_DualBufferEnable.

  Parameters:
    index	- Identifier for the device instance to be addressed.

  Returns:
    * uint16_t    - Data received

  Example:
    <code>
    uint16_t data;
    if(!PLIB_PMP_PortIsBusy( PMP_ID_0 ))
    {
        data = PLIB_PMP_DualModeMasterReceive( PMP_ID_0 );
    }
    </code>

  Remarks:
    This function to be used only when the PMP is acting as master.
    This function implements an operation of the DualModeMasterRXTX feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsDualModeMasterRXTX in your application to
    to automatically determine whether this feature is available.
*/

uint16_t PLIB_PMP_DualModeMasterReceive ( PMP_MODULE_ID index );

//******************************************************************************
/* Function:
    void PLIB_PMP_SlaveSend ( 	PMP_MODULE_ID index, 
                                uint16_t data )

  Summary:
    Sends the specified data in Slave mode.

  Description:
    This function sends the specified data. The flow of data is from the slave to 
	the master.

  Precondition:
    The PMP module is configured for Slave mode.

  Parameters:
    index	- Identifier for the device instance to be addressed
    data  	- Data to be transmitted

  Returns:
    None.

  Example:
    <code>
    uint16_t data = 'a';
    if(!PLIB_PMP_PortIsBusy( PMP_ID_0 ))
    {
        PLIB_PMP_SlaveSend( PMP_ID_0, data );
    }
    </code>

  Remarks:
    This function to be used only when the PMP is acting as slave.
    This function implements an operation of the SlaveTX feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsSlaveTX in your application to
    to automatically determine whether this feature is available.
*/

void PLIB_PMP_SlaveSend ( 	PMP_MODULE_ID index, 
                     		uint16_t data );


//******************************************************************************
/* Function:
    uint16_t PLIB_PMP_SlaveReceive ( PMP_MODULE_ID index )

  Summary:
    Receives the data in Slave mode.

  Description:
    This function receives the data. The flow of data is from the master to 
	the slave.

  Precondition:
    The PMP module is configured as a slave.

  Parameters:
    index	- Identifier for the device instance to be addressed.

  Returns:
    * uint16_t    - Data received

  Example:
    <code>
    uint16_t data;
    if(!PLIB_PMP_PortIsBusy( PMP_ID_0 ))
    {
        data = PLIB_PMP_SlaveReceive( PMP_ID_0 );
    }
    </code>

  Remarks:
    This function to be used only when the PMP is acting as slave.
    This function implements an operation of the SlaveRX feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsSlaveRX in your application to
    to automatically determine whether this feature is available.
*/

uint16_t PLIB_PMP_SlaveReceive ( PMP_MODULE_ID index );

//******************************************************************************
/* Function:
    bool PLIB_PMP_ChipSelectXIsActive ( PMP_MODULE_ID index, 
                                        PMP_CHIP_SELECT chipSelect )

  Summary:
    Gets the current status of the specified Chip Select.

  Description:
    This function returns the current status of the specified Chip Select.

  Precondition:
    None.

  Parameters:
    index	    - Identifier for the device instance to be addressed
    chipSelect	- Identifier for the Chip Select to be checked
    
  Returns:
    - true	- Chip Select is active
    - false	- Chip Select is not active

  Example:
    <code>
    PMP_CHIP_SELECT chipSelect = PMP_CHIP_SELECT_ONE;
    if(PLIB_PMP_ChipSelectXIsActive( PMP_ID_0, chipSelect ))
    {
      //Do something useful
    }
    </code>

  Remarks:
    This function implements an operation of the CSXActiveStatus feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_PMP_ExistsCSXActiveStatus in your application to
    to automatically determine whether this feature is available.
*/

bool PLIB_PMP_ChipSelectXIsActive ( PMP_MODULE_ID index, 
                                    PMP_CHIP_SELECT chipSelect );
									
// *****************************************************************************
// *****************************************************************************
// Section: PMP Peripheral Library Exists Functions
// *****************************************************************************
// *****************************************************************************
/* The following functions indicate the existence of the features on the device. 
*/

//******************************************************************************
/* Function:
    PLIB_PMP_ExistsStartReadControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the StartReadControl feature exists on the PMP module. 

  Description:
    This function identifies whether the StartReadControl feature is available on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_ReadCycleStart
    - PLIB_PMP_ReadCycleIsStarted

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The StartReadControl feature is supported on the device
    - false  - The StartReadControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsStartReadControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsDualBufferControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the DualBufferControl feature exists on the PMP module. 

  Description:
    This function identifies whether the DualBufferControl feature is available on 
	the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_DualBufferDisable
    - PLIB_PMP_DualBufferEnable
    - PLIB_PMP_DualBufferIsEnabled

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DualBufferControl feature is supported on the device
    - false  - The DualBufferControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsDualBufferControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsEnableControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the EnableControl feature exists on the PMP module. 

  Description:
    This function identifies whether the EnableControl feature is available on the 
	PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_Disable
    - PLIB_PMP_Enable
    - PLIB_PMP_IsEnabled

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

bool PLIB_PMP_ExistsEnableControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsStopInIdleControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the StopInIdleControl feature exists on the PMP module. 

  Description:
    This function identifies whether the StopInIdleControl feature is available on 
	the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_StopInIdleEnable
    - PLIB_PMP_StopInIdleDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The StopInIdleControl feature is supported on the device
    - false  - The StopInIdleControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsStopInIdleControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsMUXModeSelect( PMP_MODULE_ID index )

  Summary:
    Identifies whether the MUXModeSelect feature exists on the PMP module. 

  Description:
    This function identifies whether the MUXModeSelect feature is available on 
	the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_MultiplexModeSelect
    - PLIB_PMP_MultiplexModeGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The MUXModeSelect feature is supported on the device
    - false  - The MUXModeSelect feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsMUXModeSelect( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsBufferType( PMP_MODULE_ID index )

  Summary:
    Identifies whether the BufferType feature exists on the PMP module. 

  Description:
    This function identifies whether the BufferType feature is available on the 
	PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_InputBufferTypeSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The BufferType feature is supported on the device
    - false  - The BufferType feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsBufferType( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsWriteEnablePortControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the WriteEnablePortControl feature exists on the PMP module. 

  Description:
    This function identifies whether the WriteEnablePortControl feature is available 
	on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_WriteEnableStrobePortEnable
    - PLIB_PMP_WriteEnableStrobePortDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The WriteEnablePortControl feature is supported on the device
    - false  - The WriteEnablePortControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsWriteEnablePortControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsReadWriteStrobePortControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the ReadWriteStrobePortControl feature exists on the PMP 
	module. 

  Description:
    This function identifies whether the ReadWriteStrobePortControl feature is 
	available on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_ReadWriteStrobePortEnable
    - PLIB_PMP_ReadWriteStrobePortDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ReadWriteStrobePortControl feature is supported on the device
    - false  - The ReadWriteStrobePortControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsReadWriteStrobePortControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsChipSelectoperation( PMP_MODULE_ID index )

  Summary:
    Identifies whether the ChipSelectoperation feature exists on the PMP module. 

  Description:
    This function identifies whether the ChipSelectoperation feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_ChipSelectFunctionSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ChipSelectoperation feature is supported on the device
    - false  - The ChipSelectoperation feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsChipSelectoperation( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsAddressLatchPolarity( PMP_MODULE_ID index )

  Summary:
    Identifies whether the AddressLatchPolarity feature exists on the PMP module. 

  Description:
    This function identifies whether the AddressLatchPolarity feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_AddressLatchPolaritySelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The AddressLatchPolarity feature is supported on the device
    - false  - The AddressLatchPolarity feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsAddressLatchPolarity( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsChipXPolarity( PMP_MODULE_ID index )

  Summary:
    Identifies whether the ChipXPolarity feature exists on the PMP module. 

  Description:
    This function identifies whether the ChipXPolarity feature is available on 
	the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_ChipSelectXPolaritySelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ChipXPolarity feature is supported on the device
    - false  - The ChipXPolarity feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsChipXPolarity( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsWriteEnablePolarity( PMP_MODULE_ID index )

  Summary:
    Identifies whether the WriteEnablePolarity feature exists on the PMP module. 

  Description:
    This function identifies whether the WriteEnablePolarity feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_WriteEnableStrobePolaritySelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The WriteEnablePolarity feature is supported on the device
    - false  - The WriteEnablePolarity feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsWriteEnablePolarity( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsReadWritePolarity( PMP_MODULE_ID index )

  Summary:
    Identifies whether the ReadWritePolarity feature exists on the PMP module. 

  Description:
    This function identifies whether the ReadWritePolarity feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_ReadWriteStrobePolaritySelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ReadWritePolarity feature is supported on the device
    - false  - The ReadWritePolarity feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsReadWritePolarity( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsBusyStatus( PMP_MODULE_ID index )

  Summary:
    Identifies whether the BusyStatus feature exists on the PMP module. 

  Description:
    This function identifies whether the BusyStatus feature is available on the 
	PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_PortIsBusy

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The BusyStatus feature is supported on the device
    - false  - The BusyStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsBusyStatus( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsInterruptMode( PMP_MODULE_ID index )

  Summary:
    Identifies whether the InterruptMode feature exists on the PMP module. 

  Description:
    This function identifies whether the InterruptMode feature is available on 
	the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_InterruptModeSelect
    - PLIB_PMP_InterruptModeGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The InterruptMode feature is supported on the device
    - false  - The InterruptMode feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsInterruptMode( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsIncrementMode( PMP_MODULE_ID index )

  Summary:
    Identifies whether the IncrementMode feature exists on the PMP module. 

  Description:
    This function identifies whether the IncrementMode feature is available on 
	the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_AddressIncrementModeSelect
    - PLIB_PMP_AddressIncrementModeGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The IncrementMode feature is supported on the device
    - false  - The IncrementMode feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsIncrementMode( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsDataTransferSize( PMP_MODULE_ID index )

  Summary:
    Identifies whether the DataTransferSize feature exists on the PMP module. 

  Description:
    This function identifies whether the DataTransferSize feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_DataSizeSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DataTransferSize feature is supported on the device
    - false  - The DataTransferSize feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsDataTransferSize( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsOperationMode( PMP_MODULE_ID index )

  Summary:
    Identifies whether the OperationMode feature exists on the PMP module. 

  Description:
    This function identifies whether the OperationMode feature is available on 
	the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_OperationModeSelect
    - PLIB_PMP_OperationModeGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The OperationMode feature is supported on the device
    - false  - The OperationMode feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsOperationMode( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsDataSetUpWaitStates( PMP_MODULE_ID index )

  Summary:
    Identifies whether the DataSetUpWaitStates feature exists on the PMP module. 

  Description:
    This function identifies whether the DataSetUpWaitStates feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_WaitStatesDataSetUpSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DataSetUpWaitStates feature is supported on the device
    - false  - The DataSetUpWaitStates feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsDataSetUpWaitStates( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsDataStrobeWaitStates( PMP_MODULE_ID index )

  Summary:
    Identifies whether the DataStrobeWaitStates feature exists on the PMP module. 

  Description:
    This function identifies whether the DataStrobeWaitStates feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_WaitStatesStrobeSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DataStrobeWaitStates feature is supported on the device
    - false  - The DataStrobeWaitStates feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsDataStrobeWaitStates( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsDataHoldWaitStates( PMP_MODULE_ID index )

  Summary:
    Identifies whether the DataHoldWaitStates feature exists on the PMP module. 

  Description:
    This function identifies whether the DataHoldWaitStates feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_WaitStatesDataHoldSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DataHoldWaitStates feature is supported on the device
    - false  - The DataHoldWaitStates feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsDataHoldWaitStates( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsChipSelectEnable( PMP_MODULE_ID index )

  Summary:
    Identifies whether the ChipSelectEnable feature exists on the PMP module. 

  Description:
    This function identifies whether the ChipSelectEnable feature is available 
	on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_ChipSelectXEnable
    - PLIB_PMP_ChipSelectXDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ChipSelectEnable feature is supported on the device
    - false  - The ChipSelectEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsChipSelectEnable( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsWriteChipSelectEnable( PMP_MODULE_ID index )

  Summary:
    Identifies whether the WriteChipSelectEnable feature exists on the PMP module. 

  Description:
    This function identifies whether the WriteChipSelectEnable feature is available 
	on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_WriteChipSelectXEnable
    - PLIB_PMP_WriteChipSelectXDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The WriteChipSelectEnable feature is supported on the device
    - false  - The WriteChipSelectEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsWriteChipSelectEnable( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsReadChipSelectEnable( PMP_MODULE_ID index )

  Summary:
    Identifies whether the ReadChipSelectEnable feature exists on the PMP module. 

  Description:
    This function identifies whether the ReadChipSelectEnable feature is available 
	on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_ReadChipSelectXEnable
    - PLIB_PMP_ReadChipSelectXDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ReadChipSelectEnable feature is supported on the device
    - false  - The ReadChipSelectEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsReadChipSelectEnable( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsAddressControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the AddressControl feature exists on the PMP module. 

  Description:
    This function identifies whether the AddressControl feature is available on 
	the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_AddressSet
    - PLIB_PMP_AddressGet
    - PLIB_PMP_AddressLinesA0A1Set
    - PLIB_PMP_AddressLinesA0A1Get

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The AddressControl feature is supported on the device
    - false  - The AddressControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsAddressControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsDualModeWriteAddressControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the DualModeWriteAddressControl feature exists on the 
	PMP module.

  Description:
    This function identifies whether the DualModeWriteAddressControl feature is 
	available on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_DualModeWriteAddressSet
    - PLIB_PMP_DualModeWriteAddressGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DualModeWriteAddressControl feature is supported on the device
    - false  - The DualModeWriteAddressControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsDualModeWriteAddressControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsDualModeReadAddressControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the DualModeReadAddressControl feature exists on the 
	PMP module.

  Description:
    This function identifies whether the DualModeReadAddressControl feature is 
	available on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_DualModeReadAddressSet
    - PLIB_PMP_DualModeReadAddressGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DualModeReadAddressControl feature is supported on the device
    - false  - The DualModeReadAddressControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsDualModeReadAddressControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsAddressPortPinControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the AddressPortPinControl feature exists on the PMP module. 

  Description:
    This function identifies whether the AddressPortPinControl feature is available 
	on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_AddressPortEnable
    - PLIB_PMP_AddressPortDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The AddressPortPinControl feature is supported on the device
    - false  - The AddressPortPinControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsAddressPortPinControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsAddressLatchStrobePortControl( PMP_MODULE_ID index )

  Summary:
    Identifies whether the AddressLatchStrobePortControl feature exists on the PMP 
	module.

  Description:
    This function identifies whether the AddressLatchStrobePortControl feature is 
	available on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_AddressLatchStrobeEnable
    - PLIB_PMP_AddressLatchStrobeDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The AddressLatchStrobePortControl feature is supported on the device
    - false  - The AddressLatchStrobePortControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsAddressLatchStrobePortControl( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsInputBufferFull( PMP_MODULE_ID index )

  Summary:
    Identifies whether the InputBufferFull feature exists on the PMP module. 

  Description:
    This function identifies whether the InputBufferFull feature is available on 
	the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_InputBuffersAreFull

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The InputBufferFull feature is supported on the device
    - false  - The InputBufferFull feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsInputBufferFull( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsBufferOverFlow( PMP_MODULE_ID index )

  Summary:
    Identifies whether the BufferOverFlow feature exists on the PMP module. 

  Description:
    This function identifies whether the BufferOverFlow feature is available on 
	the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_InputOverflowHasOccurred
    - PLIB_PMP_InputOverflowClear

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The BufferOverFlow feature is supported on the device
    - false  - The BufferOverFlow feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsBufferOverFlow( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsInputBufferXStatus( PMP_MODULE_ID index )

  Summary:
    Identifies whether the InputBufferXStatus feature exists on the PMP module. 

  Description:
    This function identifies whether the InputBufferXStatus feature is available 
	on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_InputBufferXIsFull
    - PLIB_PMP_IsDataReceived

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The InputBufferXStatus feature is supported on the device
    - false  - The InputBufferXStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsInputBufferXStatus( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsOutPutBufferEmpty( PMP_MODULE_ID index )

  Summary:
    Identifies whether the OutPutBufferEmpty feature exists on the PMP module. 

  Description:
    This function identifies whether the OutPutBufferEmpty feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_OutputBuffersAreEmpty

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The OutPutBufferEmpty feature is supported on the device
    - false  - The OutPutBufferEmpty feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsOutPutBufferEmpty( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsBufferUnderFlow( PMP_MODULE_ID index )

  Summary:
    Identifies whether the BufferUnderFlow feature exists on the PMP module. 

  Description:
    This function identifies whether the BufferUnderFlow feature is available on 
	the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_OutputUnderflowHasOccurred
    - PLIB_PMP_OutputUnderflowClear

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The BufferUnderFlow feature is supported on the device
    - false  - The BufferUnderFlow feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsBufferUnderFlow( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsOutputBufferXStatus( PMP_MODULE_ID index )

  Summary:
    Identifies whether the OutputBufferXStatus feature exists on the PMP module. 

  Description:
    This function identifies whether the OutputBufferXStatus feature is available 
	on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_OutputBufferXIsEmpty
    - PLIB_PMP_IsDataTransmitted

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The OutputBufferXStatus feature is supported on the device
    - false  - The OutputBufferXStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsOutputBufferXStatus( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsBufferRead( PMP_MODULE_ID index )

  Summary:
    Identifies whether the BufferRead feature exists on the PMP module. 

  Description:
    This function identifies whether the BufferRead feature is available on 
	the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_InputBufferXByteReceive

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The BufferRead feature is supported on the device
    - false  - The BufferRead feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsBufferRead( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsBufferWrite( PMP_MODULE_ID index )

  Summary:
    Identifies whether the BufferWrite feature exists on the PMP module. 

  Description:
    This function identifies whether the BufferWrite feature is available on 
	the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_OutputBufferXByteSend

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The BufferWrite feature is supported on the device
    - false  - The BufferWrite feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsBufferWrite( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsMasterRXTX( PMP_MODULE_ID index )

  Summary:
    Identifies whether the MasterRXTX feature exists on the PMP module. 

  Description:
    This function identifies whether the MasterRXTX feature is available on the 
	PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_MasterSend
    - PLIB_PMP_MasterReceive

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The MasterRXTX feature is supported on the device
    - false  - The MasterRXTX feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsMasterRXTX( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsDualModeMasterRXTX( PMP_MODULE_ID index )

  Summary:
    Identifies whether the DualModeMasterRXTX feature exists on the PMP module. 

  Description:
    This function identifies whether the DualModeMasterRXTX feature is available 
	on the PMP module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_PMP_DualModeMasterSend
    - PLIB_PMP_DualModeMasterReceive

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DualModeMasterRXTX feature is supported on the device
    - false  - The DualModeMasterRXTX feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsDualModeMasterRXTX( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsSlaveTX( PMP_MODULE_ID index )

  Summary:
    Identifies whether the SlaveTX feature exists on the PMP module. 

  Description:
    This function identifies whether the SlaveTX feature is available on the 
	PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_SlaveSend

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The SlaveTX feature is supported on the device
    - false  - The SlaveTX feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsSlaveTX( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsSlaveRX( PMP_MODULE_ID index )

  Summary:
    Identifies whether the SlaveRX feature exists on the PMP module. 

  Description:
    This function identifies whether the SlaveRX feature is available on the 
	PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_SlaveReceive

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The SlaveRX feature is supported on the device
    - false  - The SlaveRX feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsSlaveRX( PMP_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_PMP_ExistsCSXActiveStatus( PMP_MODULE_ID index )

  Summary:
    Identifies whether the CSXActiveStatus feature exists on the PMP module. 

  Description:
    This function identifies whether the CSXActiveStatus feature is available 
	on the PMP module.
    When this function returns true, this function is supported on the device: 
    - PLIB_PMP_ChipSelectXIsActive

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The CSXActiveStatus feature is supported on the device
    - false  - The CSXActiveStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_PMP_ExistsCSXActiveStatus( PMP_MODULE_ID index );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // #ifndef _PLIB_PMP_H
/*******************************************************************************
 End of File
*/
