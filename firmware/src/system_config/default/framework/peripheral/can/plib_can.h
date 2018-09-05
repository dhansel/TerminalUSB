/*******************************************************************************
  CAN Peripheral Library Interface Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_can.h

  Summary:
    This file contains the interface definition for the CAN Peripheral Library.

  Description:
	This library provides a low-level abstraction of the Controller Area
	Network (CAN) module on Microchip microcontrollers with a convenient C language
	interface. It can be used to simplify low-level access to the module
	without the necessity of interacting directly with the module's registers,
	thus hiding differences between one microcontroller variant and another.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright 2013-2015 released Microchip Technology Inc. All rights reserved.

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

#ifndef _PLIB_CAN_H	// Guards against multiple inclusion
#define _PLIB_CAN_H

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
// Section: Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* CAN Transmit and Receive Message Buffer size

  Summary:
    Used as the array size of the CAN transmit and full receive message buffer.

  Description:
    This constant is used as the array size of the CAN transmit and full receive 
	message buffer.

*/

#define CAN_TX_RX_MESSAGE_SIZE_BYTES 16


// *****************************************************************************
/* CAN Data-Only Receive Message Buffer

  Summary:
    Used as the size of the CAN data-only receive message buffer in bytes.

  Description:
    This constant is used as the size of the CAN data-only receive message buffer 
	in bytes.

*/

#define CAN_RX_DATA_ONLY_SIZE_BYTES 8


// *****************************************************************************
// *****************************************************************************
// Section: Data types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* CAN Transmit Message SID Word

  Summary:
    Defines the structure of the SID word section of the transmit message.

  Description:
    This data structure represents the SID section of the CAN transmit message.
    The data structure is an element of the CAN_TX_MSG_BUFFER data structure.
*/

typedef	 struct
{
    /* CAN Transmit Message Standard ID. This value should be between
    0x0 - 0x7FF */
    unsigned sid:11;
    unsigned :21;

}CAN_TX_MSG_SID;


// *****************************************************************************
/* CAN Message EID Word

  Summary:
    Defines the structure of the EID word section of the transmit and receive
    message.

  Description:
    This data structure represents the EID section of the CAN transmit and
    receive message. The data structure is an element of the CAN_TX_MSG_BUFFER
    and CAN_RX_MSG_BUFFER data structure.
*/

typedef struct
{
    /* Data Length Control. Specifies the size of the data payload section of
    the CAN packet. Valid values are 0x0 - 0x8 */
    unsigned data_length_code:4;

    /* Reserved bit. Should be always 0. */
    unsigned reserved0:1;

    /* Unimplemented bit. Should be always 0. */
    unsigned unimplemented1:3;

    /* Reserved bit. Should be always 0. */
    unsigned reserved1:1;

    /* Remote Transmit Request bit. Should be set for RTR messages, clear
    otherwise.*/
    unsigned remote_request:1;

    /* CAN Transmit and Receive Extended ID field. Valid values are in range
    0x0 - 0x3FFFF */
    unsigned eid:18;

    /* Identifier bit. If 0 means that message is SID. If 1 means
    that message is EID type.*/
    unsigned ide:1;

    /* Substitute Remote request bit. This bit should always be clear for an
    EID message. It is ignored for an SID message.*/
    unsigned sub_remote_req:1;

    /* Unimplemented bit. Should be always 0. */
    unsigned unimplemented2:2;

}CAN_MSG_EID;


// *****************************************************************************
/* CAN Transmit Message Buffer

  Summary:
    Defines the structure of the CAN transmit message buffer.

  Description:
    This data structure represents the CAN transmit message buffer. This
    should be used for writing data to a CAN transmit channel and transmitting
    data. A pointer to this type of data structure is returned by the
    PLIB_CAN_TransmitBufferGet function.

    The data structure allows the transmit message buffer to be accessed as
    fields of a CAN transmit message and also as an array of four 32-bit words.
    The latter allows for quick initialization of the message buffer.

*/

typedef union
{
    struct
    {
        /* This is SID portion of the CAN Transmit message */
        CAN_TX_MSG_SID msgSID;

        /* This is EID portion of the CAN Transmit message */
        CAN_MSG_EID msgEID;

        /* This is the data portion of the CAN Transmit message */
        unsigned char data[8];
    };

    /* This is CAN Transmit message organized as a set of 32 bit words */
    uint32_t messageWord[4];

}CAN_TX_MSG_BUFFER;


// *****************************************************************************
/* CAN Receive Message SID Word

  Summary:
    Defines the structure of the SID word section of the receive message.

  Description:
    This data structure represents the SID section of the CAN receive message.
    The data structure is an element of the CAN_RX_MSG_BUFFER data structure.
*/

typedef	struct
{
    /* SID of the Received CAN Message */
	unsigned sid:11;

    /* Filter which accepted this message */
	unsigned filter_hit:5;

    /* Time stamp of the received message. This is valid only if the
    Timestamping is enabled */
	unsigned msg_timestamp:16;

}CAN_RX_MSG_SID;


// *****************************************************************************
/* CAN Receive Message Buffer

  Summary:
    Defines the structure of the CAN receive message buffer

  Description:
    This data structure represents the CAN receive message buffer. Received
    messages could be either full-receive messages or data-only messages. A full-receive
    message contains the message header and data payload section. For a
    full-receive CAN receive channel, the caller should use the msgSID, msgEID
    and data members. A data-only message contains only an 8-byte data payload.
    While using this data structure with a data-only type of CAN receive channel,
    the caller should use the dataOnlyMsgData member of the structure and should
    read only 8 bytes of data.
*/

typedef union {

	struct
	{
        /* This is SID portion of the CAN Receive message */
		CAN_RX_MSG_SID msgSID;

        /* This is EID portion of the CAN Receive message */
		CAN_MSG_EID msgEID;

        /* This is the data payload section of the received message */
		uint8_t data[8];
	};

    /* This can be used if the message buffer is to
    be read from a Data-Only type of CAN Receive Channel */
    uint8_t dataOnlyMsgData[8];

    /* This is CAN Receive message organized as a set of 32-bit words */
    uint32_t messageWord[4];

}CAN_RX_MSG_BUFFER;

// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued at end of file)
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.  However,
    please see the bottom of the file for additional implementation header files
    that are also included
*/

#include "peripheral/can/processor/can_processor.h"


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Basic Configuration
// *****************************************************************************
// *****************************************************************************
/*  APIs for the basic configuration of the CAN module. */

// *****************************************************************************
/* Function:
	void PLIB_CAN_Enable ( CAN_MODULE_ID index )

  Summary:
    Enables the specified CAN module.

  Description:
    This function enables the specified CAN module.

  Precondition:
    The module should be appropriately configured before being enabled.

  Parameters:
    index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
	#define MY_CAN_ID CAN_ID_1

	//Do all the other configurations before enabling.

	PLIB_CAN_Enable(MY_CAN_ID);
    </code>

  Remarks:
	The MY_CAN_ID macro in the example above is used as a place holder for the
	actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

	Some of the CAN module settings can be done only when the module is off.
	Therefore, always call the PLIB_CAN_Enable Function after all other
	configurations are complete.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsEnableControl in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_Enable ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_Disable ( CAN_MODULE_ID index )

  Summary:
    Disables the specified CAN module.

  Description:
    This function disables the specified CAN module.

  Precondition:
    None.

  Parameters:
    index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
	#define MY_CAN_ID CAN_ID_1

	PLIB_CAN_Disable(MY_CAN_ID);
    </code>

  Remarks:
	The MY_CAN_ID macro in the example above is used as a place holder for the
	actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

	If the user application clears this bit, it may take a number of cycles
	before the CAN module completes the current transaction and responds to
	this request. The user application should check this using the PLIB_CAN_IsActive
	function to verify that the request has been honored.

	This function works only if the CAN module is in Configuration mode. Use the
	PLIB_CAN_OperationModeGet function to get the current mode and the
	PLIB_CAN_OperationModeSelect function to change the mode.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsEnableControl in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_Disable ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    bool PLIB_CAN_IsActive ( CAN_MODULE_ID index )

  Summary:
    Returns 'true' if the CAN module is active.

  Description:
    This function returns 'true' if the CAN module is active. This function is
    typically called after the CAN module is disabled using the
    PLIB_CAN_Disable function. The CAN module disable request does not
    complete immediately when requested and depends on the CAN bus status. This
    function should be called to check whether the module disable is completed.

  Precondition:
    None.

  Parameters:
    index         - Identifies the desired CAN module

  Returns:
    - true  = The module is still active
    - false = The module is completely disabled

  Example:
    <code>

    // Disable CAN module 1. Wait until the module is completely disabled.

    PLIB_CAN_Disable(CAN_ID_1);

    while(PLIB_CAN_IsActive(CAN_ID_1) == true);

    </code>

  Remarks:
    The CAN module disable operation should not be confused with placing the
    CAN module in the Disable mode using the PLIB_CAN_OperationModeSelect
    function. The Disable mode is one of the operating modes of the CAN module.
    The CAN module is still enabled while in Disable mode. The module disable
    operation switches the CAN module off.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsActiveStatus in your application to determine whether
	this feature is available.
*/

bool PLIB_CAN_IsActive ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_TimeStampEnable ( CAN_MODULE_ID index )

  Summary:
    Enables the time stamp feature for the CAN module.

  Description:
    This function enables the time stamp capture feature for the CAN module. The CAN
    timer value will be stored on valid message reception and is stored with the
    message.

  Precondition:
    None

  Parameters:
    index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
	#define MY_CAN_ID CAN_ID_1

	PLIB_CAN_TimeStampEnable(MY_CAN_ID);
    </code>

  Remarks:
	The MY_CAN_ID macro in the example above is used as a place holder for the
	actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTimeStampEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_TimeStampEnable ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_TimeStampDisable ( CAN_MODULE_ID index )

  Summary:
    Disables the time stamp feature for the CAN module.

  Description:
    This function disables time stamp capture feature for the CAN module. This
    conserves power by stopping the CAN timer.

  Precondition:
    None.

  Parameters:
    index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
	#define MY_CAN_ID CAN_ID_1

	PLIB_CAN_TimeStampDisable(MY_CAN_ID);
    </code>

  Remarks:
	The MY_CAN_ID macro in the example above is used as a place holder for the
	actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTimeStampEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_TimeStampDisable ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_StopInIdleEnable ( CAN_MODULE_ID index )

  Summary:
    Enables the CAN module to stop when the processor enters Idle mode.

  Description:
    This function configures the CAN module to stop operation when the system 
	enters Idle mode.

  Precondition:
	None.

  Parameters:
    index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
	#define MY_CAN_ID CAN_ID_1

	PLIB_CAN_StopInIdleEnable(MY_CAN_ID);
    </code>

  Remarks:
	The MY_CAN_ID macro in the example above is used as a place holder for the
	actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsStopInIdle in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_StopInIdleEnable ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_StopInIdleDisable ( CAN_MODULE_ID index )

  Summary:
    Disables the Stop in Idle feature.

  Description:
    This function disables the CAN module from stopping operation when the system
    enters Idle mode. The module continues operation when the system enters Idle
    mode.

  Precondition:
	None.

  Parameters:
    index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
	#define MY_CAN_ID CAN_ID_1

	PLIB_CAN_StopInIdleDisable(MY_CAN_ID);
    </code>

  Remarks:
	The MY_CAN_ID macro in the example above is used as a place holder for the
	actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsStopInIdle in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_StopInIdleDisable ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_BusActivityWakeupEnable ( CAN_MODULE_ID index )

  Summary:
	Enables the wake-up on bus activity receive line filter.

  Description:
	This function enables the wake-up on bus activity receive line filter.

  Precondition:
	None.

  Parameters:
    index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
	#define MY_CAN_ID CAN_ID_1

	PLIB_CAN_BusActivityWakeupEnable(MY_CAN_ID);
    </code>

  Remarks:
	The MY_CAN_ID macro in the example above is used as a place holder for the
	actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsBusActivityWakeup in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_BusActivityWakeupEnable ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_BusActivityWakeupDisable ( CAN_MODULE_ID index )

  Summary:
	Disables the wake-up on bus activity receive line filter.

  Description:
	This function disables the Wake up on bus activity receive line filter.

  Precondition:
	None.

  Parameters:
    index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
	#define MY_CAN_ID CAN_ID_1

	PLIB_CAN_BusActivityWakeupDisable(MY_CAN_ID);
    </code>

  Remarks:
	The MY_CAN_ID macro in the example above is used as a place holder for the
	actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsBusActivityWakeup in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_BusActivityWakeupDisable ( CAN_MODULE_ID index );


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Advanced Configuration
// *****************************************************************************
// *****************************************************************************
/*  APIs for the CAN module Advanced Configuration */

// *****************************************************************************
/* Function:
	void PLIB_CAN_MemoryBufferAssign ( CAN_MODULE_ID index, void * buffer )

  Summary:
    Assigns buffer memory to the CAN module.

  Description:
    This function assigns buffer memory address to the CAN module. The CAN module 
	uses this buffer memory to store messages to be transmitted and received. The
    size of the memory buffer should be enough to accommodate the required
    number of message buffers and channels.

  Precondition:
    The module should be in Configuration mode (using the
    PLIB_CAN_OperationModeSelect function).

  Parameters:
    index       - Identifies the desired CAN module
    buffer      - Pointer to the buffer memory area

  Returns:
    None.

  Example:
    <code>
    // Define and assign a CAN 1 memory buffer for 2 Transmit channels and 1 Receive
    // channel, each with 4 message buffers

    uint8_t canMemoryBuffer [3 * 4 * CAN_TX_RX_MESSAGE_SIZE_BYTES];

    PLIB_CAN_MemoryBufferAssign(CAN_ID_1, canMemoryBuffer);

    </code>

  Remarks:
    This API is useful only if the CAN module uses device RAM for message
    buffers and message FIFO location is software configurable.
    This should not be used if the device message buffer is part of SFR.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsMemoryBufferAssign in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_MemoryBufferAssign ( CAN_MODULE_ID index, void * buffer );


// *****************************************************************************
/* Function:
    void PLIB_CAN_OperationModeSelect ( CAN_MODULE_ID index, CAN_OPERATION_MODES opMode )

  Summary:
    Sets the CAN operating mode.

  Description:
    This function sets the CAN operating mode. The CAN module requires itself to
    be in certain modes to gain access to module functionality. For example, the
    module should be in Normal mode to send and receive messages. Note that after
    this function is called, it should be checked to determine whether the mode was
    set by using the PLIB_CAN_OperationModeGet function.

  Precondition:
    None.

  Parameters:
    module      - Identifies the desired CAN module
    opMode      - Desired CAN_OP_MODE type of the mode to be set

  Returns:
    None.

  Example:
    <code>
    // Set the CAN_ID_1 operating mode to Configuration mode.

    PLIB_CAN_OperationModeSelect(CAN_ID_1, CAN_CONFIGURATION_MODE);

    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsOperationModeWrite in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_OperationModeSelect (CAN_MODULE_ID index, CAN_OPERATION_MODES opMode);


// *****************************************************************************
/* Function:
    CAN_OPERATION_MODES PLIB_CAN_OperationModeGet ( CAN_MODULE_ID index )

  Summary:
    Obtains the current CAN operating mode.

  Description:
    This function obtains the current CAN operating mode. This function is typically
    called after the PLIB_CAN_OperationModeSelect function to check if the
    requested operation mode change is complete.

  Precondition:
    None.

  Parameters:
    index        - Identifies the desired CAN module

  Returns:
    The current CAN_OP_MODE type of operation mode of the CAN module.

  Example:
    <code>
    // Check and wait until the CAN module is in Disable Mode.

    while(PLIB_CAN_OperationModeGet(CAN_ID_1) != CAN_DISABLE_MODE);

    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsOperationModeRead in your application to determine whether
	this feature is available.
*/

CAN_OPERATION_MODES PLIB_CAN_OperationModeGet ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_DeviceNetConfigure ( CAN_MODULE_ID index, CAN_DNET_FILTER_SIZE dncnt )

  Summary:
    Configures the CAN module DeviceNet(TM) filter feature.

  Description:
    This function configures the CAN module DeviceNet filter feature. DeviceNet
    filtering allows a portion of the data payload to be used as a filter
	criteria. This function allows the size of this filter to be configured in
	bits. The filter can also be disabled.

  Precondition:
    The CAN module should preferably be in Configuration mode (using the
    PLIB_CAN_OperationModeSelect function).

  Parameters:
    index    - Identifies the desired CAN module
    dncnt   - Specifies the CAN_DNET_FILTER_SIZE size of the DeviceNet
              filter in bits

  Returns:
    None.

  Example:
    <code>
    // Disable the CAN_ID_1 DeviceNet filter feature.

    PLIB_CAN_DeviceNetConfigure(CAN_ID_1, CAN_DNET_FILTER_DISABLE);

    // Set the CAN_ID_2 Device Net Filter Size to 10 bits.

    PLIB_CAN_DeviceNetConfigure(CAN_ID_2, CAN_DNET_FILTER_SIZE_10_BIT);

    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsDeviceNet in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_DeviceNetConfigure ( CAN_MODULE_ID index, CAN_DNET_FILTER_SIZE dncnt );


// *****************************************************************************
/* Function:
    void PLIB_CAN_TimeStampValueSet ( CAN_MODULE_ID index, unsigned value )

  Summary:
    Sets the CAN receive message time stamp timer value.

  Description:
    This function sets the CAN receive message time stamp timer value. The timer
    will then start counting up from this value.

  Precondition:
    None.

  Parameters:
    index   - Identifies the desired CAN module
    value   - Start value of the receive message time stamp timer. This value
              should be between 0x0 and 0xFFFF.

  Returns:
    None.

  Example:
    <code>
    // Set start value of CAN_ID_1 Receive Message Time Stamp Timer to 0x100
    PLIB_CAN_TimeStampValueSet(CAN_ID_1, 0x0100);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTimeStampValue in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_TimeStampValueSet ( CAN_MODULE_ID index, unsigned value );


// *****************************************************************************
/* Function:
    unsigned PLIB_CAN_TimeStampValueGet ( CAN_MODULE_ID index )

  Summary:
    Returns the current value of the CAN receive message time stamp timer value.

  Description:
    This function gets the current value of the CAN receive message time stamp
    timer value.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module

  Returns:
    The current value of the CAN receive message time stamp timer.

  Example:
    <code>

    unsigned int timeStampTimerVal;

    // Get the current time stamp timer value.
    timeStampTimerVal = PLIB_CAN_TimeStampValueGet(CAN_ID_1);

    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTimeStampValue in your application to determine whether
	this feature is available.
*/

unsigned PLIB_CAN_TimeStampValueGet ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_TimeStampPrescalerSet( CAN_MODULE_ID index, unsigned preScaler )

  Summary:
    Sets the CAN receive message time stamp timer prescaler.

  Description:
    This function sets the CAN receive message time stamp timer prescaler. This
    prescaler determines the rate at the which the time stamp timer is
    incremented. For example, if the prescaler value is 0xFF, the time stamp
    timer is incremented by 1 every 255 system clock periods.

  Precondition:
    None.

  Parameters:
    module      - Identifies the desired CAN module
    preScaler   - Prescaler for the CAN receive message time stamp timer. This
    			  value should be between 0x0 and 0xFFFF.

  Returns:
    None.

  Example:
    <code>

    // Set the CAN_ID_1 Receive Message Time Stamp Timer prescaler to increment
    //the Time Stamp Timer every 1024 system clock periods.

    PLIB_CAN_TimeStampPrescalerSet(CAN_ID_1, 1024);

    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTimeStampPrescaler in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_TimeStampPrescalerSet( CAN_MODULE_ID index, unsigned preScaler );


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Bus Speed Configuration
// *****************************************************************************
// *****************************************************************************
/*  APIs for the Bus Speed Configuration of the CAN module. */

// *****************************************************************************
/* Function:
    bool PLIB_CAN_PrecalculatedBitRateSetup( CAN_MODULE_ID  index,
                                             uint8_t        prescale,
                                             uint8_t        syncjumpWidth,
                                             uint8_t        propagation,
                                             uint8_t        segment1,
                                             uint8_t        segment2 );

  Summary:
    Sets the desired Baud rate for the respective CAN module.

  Description:
    This function sets the configuration register with the desired Baud rate.

  Precondition:
    Use the "ECAN Bit Rate Calculator" MPLAB X IDE plug-in to get all of the 
	parameters needed for the function.

    This function works only if the CAN module is in Configuration mode. Use the
    PLIB_CAN_OperationModeGet function to get the current mode and the
    PLIB_CAN_OperationModeSelect function to change the mode.

  Parameters:
    index               - Identifies the desired CAN module
    prescale            - The CAN module input clock prescale divisor.
    syncJumpWidth       - The synchronization jump width is the number of time 
                          quanta by which the CAN module may adjust phase 
                          segment 1 and segment 2 to compensate for jitter in 
                          the bit phase.
    propagation         - Propagation segment length is the number of time 
                          quanta allocated to allow for propagation variation 
                          in the bit sampling phase.
    segment1            - Phase segment 1 length(in time quanta) after the 
                          propagation segment before sampling of the bit begins.
    segment2            - Phase segment 2 length (in time quanta) after 
                          sampling has begun.

  Returns:
    - true  = Baud rate setup success
    - false = Baud rate setup failure, arguments passed are beyond the 
			  possible limits

  Example:
     <code>
    // Use ECAN Bit Rate Calculator plug-in to get parameter values for 500kbps 
	// Baud rate.
    #define MY_CAN_ID       CAN_ID_1
    #define PRESCALE        6
    #define SYNCJUMPWIDTH   1
    #define PROPAGATION     2
    #define SEGMENT1        4
    #define SEGMENT2        4
	bool result;

    if (CAN_CONFIGURATION_MODE == PLIB_CAN_OperationModeGet(MY_CAN_ID))
    {
        result = PLIB_CAN_PrecalculatedBitRateSetup( MY_CAN_ID, PRESCALE, SYNCJUMPWIDTH, 
                                            PROPAGATION, SEGMENT1, SEGMENT2 );
											
		if(false == result)
		{
			// Error occurred, handle accordingly
		}
    }
    </code>

  Remarks:
    This function's parameters must be precalculated for the desired baud rate
    and properly encoded for the registers of the CAN module that is in use.  
    This function is primarily intended to be used in conjunction with the 
    MPLAB X IDE ECAN Baud Rate calculator or the MPLAB Harmony Configurator 
    (MHC), which precalculates and correctly encodes these values.

    The MY_CAN_ID macro in the example above is used as a place holder for the
    actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_CAN_ExistsPrecalculatedBitRateSetup in your application to determine 
    whether this feature is available.
*/

bool PLIB_CAN_PrecalculatedBitRateSetup( CAN_MODULE_ID  index,
                                         uint8_t        prescale,
                                         uint8_t        syncjumpWidth,
                                         uint8_t        propagation,
                                         uint8_t        segment1,
                                         uint8_t        segment2 );


// *****************************************************************************
/* Function:
    bool PLIB_CAN_BitSamplePhaseSet(  CAN_MODULE_ID   index,
                                      uint8_t         syncJumpWidth,
                                      uint8_t         propagation,
                                      uint8_t         segment1,
                                      uint8_t         segment2)

  Summary:
    Sets the CAN bit-sampling phase parameters.

  Description:
    This function selects the CAN bit-sampling phase parameters that determine
    the Baud rate setting.  
    
    For a given baud rate setting, a single bit time is divided into a number 
    segments or phases of equal time length called "time quanta".  The bit time 
    for a given baud rate (i.e. 1/baud) is divided into a number of time 
    quanta of equal length.
    
    1 time quantum = (one bit time) / (total number of time quanta)
    
    These time quanta are then partitioned into different phases of the bit
    sample time called synchronization phase (always 1 time quantum long), the
    propagation phase, and the segment 1 and segment 2 phases.  Thus, the total 
    number of time quanta equals the sum of the time quanta allocated to each 
    phase.
            
    total number of time quanta = (1 + propagation + segment1 + segment2)
    
    (Sampling of the bit occurs at the end of the segment 1 phase.)
    
    This function determines the length of each phase (in time quanta) as well as 
    the synchronization jump width, the number of time quanta by which the CAN 
    module may move time from segment 1 to segment 2 (or vice versa) to adjust
    for jitter in the bit sampling phase timing.

  Precondition:
    This function works only if the CAN module is in Configuration mode. Use the
    PLIB_CAN_OperationModeGet function to get the current mode and the
    PLIB_CAN_OperationModeSelect function to change the mode.

  Parameters:
    index           - Identifies the desired CAN module
    syncJumpWidth   - The synchronization jump width is the number of time 
                      quanta by which the CAN module may adjust phase 
                      segment 1 and segment 2 to compensate for jitter in 
                      the bit phase to achieve a valid sampling point.          
    propagation     - Propagation segment length is the number of time 
                      quanta allocated to allow for propagation variation 
                      in the bit sampling phase.  
    segment1        - Phase segment 1 length(in time quanta) after the 
                      propagation segment before sampling of the bit begins.
    segment2        - Phase segment 2 length (in time quanta) after 
                      sampling has begun.
    
  Returns:
    - true  = BitSamplePhase Setup success
    - false = BitSamplePhase Setup failure, arguments passed are beyond the 
			  possible limits

  Example:
     <code>
    #define MY_CAN_ID       CAN_ID_1

    #define SYNCJUMPWIDTH   1
    #define PROPAGATION     2
    #define SEGMENT1        4
    #define SEGMENT2        4
    bool result;
    if (CAN_CONFIGURATION_MODE == PLIB_CAN_OperationModeGet(MY_CAN_ID))
    {
        result = PLIB_CAN_BitSamplePhaseSet(MY_CAN_ID, SYNCJUMPWIDTH, PROPAGATION, 
		                                SEGMENT1, SEGMENT2);
										
		if(false == result)
		{
			// Error occurred
		}
    }
    </code>

  Remarks:
      The values of the syncJumpWidth, propagation, segment1 and segment2 
    parameters should passed as a number of time quanta for each.  These 
    values will be encoded by this function correctly for the the part in use 
    before they are written to the registers of the CAN peripheral.  To pass 
    in precalculated values that are already encoded for the physical 
    registers of the CAN controller (such as the values provided by the ECAN 
    Baud Rate Calculator or the MPLAB Harmony Configurator (MHC) utility), use the 
    PLIB_CAN_PrecalculatedBitRateSetup function instead.

    The MY_CAN_ID macro in the example above is used as a place holder for the
    actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_CAN_ExistsBitSamplePhaseSet in your application to determine whether
    this feature is available.
*/

bool PLIB_CAN_BitSamplePhaseSet(  CAN_MODULE_ID   index,
                                  uint8_t         syncJumpWidth,
                                  uint8_t         propagation,
                                  uint8_t         segment1,
                                  uint8_t         segment2);


// *****************************************************************************
/* Function:
    bool PLIB_CAN_BaudRatePrescaleSetup( CAN_MODULE_ID index, uint16_t prescale )

  Summary:
    Sets the prescale divisor applied to the CAN module's input clock before it
    is used to determine the CAN baud rate.

  Description:
    Sets the prescale divisor applied to the CAN module's input clock before it
    is used to determine the CAN baud rate. 

  Precondition:
    This function works only if the CAN module is in Configuration mode. Use the
    PLIB_CAN_OperationModeGet function to get the current mode and the
    PLIB_CAN_OperationModeSelect function to change the mode.

  Parameters:
    index      - Identifies the desired CAN module
    prescale   - Prescale value by which the input clock to the CAN module is
                 divided to determine the CAN baud rate.

  Returns:
    - true  = BaudRate prescale Setup success
    - false = BaudRate prescale Setup failure, arguments passed are beyond the 
			  possible limits

  Example:
    <code>
    #define MY_CAN_ID   CAN_ID_1

    #define PRESCALE    7
    bool result;
    if (CAN_CONFIGURATION_MODE == PLIB_CAN_OperationModeGet(MY_CAN_ID))
    {

        result = PLIB_CAN_BaudRatePrescaleSetup(MY_CAN_ID, PRESCALE);
		
		if(false == result)
		{
			// Error occurred
		}
    }
    </code>

  Remarks:
    The prescale value is the actual input clock divisor value.  
    
        baud rate = input clock / divisor
    
    However, the values must be chosen carefully so that the desired resultant 
    baud rate is an integral number (not fractional).
    
    The MY_CAN_ID macro in the example above is used as a place holder for the
    actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_CAN_ExistsBaudRatePrescaleSetup in your application to determine whether
    this feature is available.
*/

bool PLIB_CAN_BaudRatePrescaleSetup( CAN_MODULE_ID index, uint16_t prescale );


// *****************************************************************************
/* Function:
    void PLIB_CAN_BusLine3TimesSamplingEnable ( CAN_MODULE_ID index )

  Summary:
    Enables the bus line three times sampling.

  Description:
    The bus line will be sampled three times at the sampling point. If this is
    disabled, the bus line will be sampled only once.

  Precondition:
    This function works only if the CAN module is in Configuration mode. Use the
    PLIB_CAN_OperationModeGet function to get the current mode and the
    PLIB_CAN_OperationModeSelect function to change the mode.

  Parameters:
    index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
    #define MY_CAN_ID CAN_ID_1

    if (CAN_CONFIGURATION_MODE == PLIB_CAN_OperationModeGet(MY_CAN_ID))
    {
    PLIB_CAN_BusLine3TimesSamplingEnable(MY_CAN_ID);

    }
    </code>

  Remarks:
    The MY_CAN_ID macro in the example above is used as a place holder for the
    actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

    This API may not function if the baud rate prescale value is more than a
    certain limit. Refer to the specific device data sheet to determine the maximum
    prescale that allows three times sampling.

    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_CAN_ExistsBusLine3TimesSampling in your application to determine whether
    this feature is available.
*/

void PLIB_CAN_BusLine3TimesSamplingEnable ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_BusLine3TimesSamplingDisable ( CAN_MODULE_ID index )

  Summary:
    Disables the bus line three times sampling.

  Description:
    The bus line will be sampled three times at the sampling point. If this is
    disabled, the bus line will be sampled only once.

  Precondition:
    This function works only if the CAN module is in Configuration mode. Use the
    PLIB_CAN_OperationModeGet function to get the current mode and the
    PLIB_CAN_OperationModeSelect function to change the mode.

  Parameters:
     index      - Identifies the desired CAN module

  Returns:
    None.

  Example:
    <code>
    #define MY_CAN_ID CAN_ID_1

    if (CAN_CONFIGURATION_MODE == PLIB_CAN_OperationModeGet(MY_CAN_ID))
    {
    PLIB_CAN_BusLine3TimesSamplingDisable(MY_CAN_ID);

    }
    </code>

  Remarks:
    The MY_CAN_ID macro in the example above is used as a place holder for the
    actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

    This API may not function if the baud rate prescale value is more than a
    certain limit. Refer to the specific device data sheet to determine the maximum
    prescale that allows three times sampling.

    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_CAN_ExistsBusLine3TimesSampling in your application to determine whether
    this feature is available.
*/

void PLIB_CAN_BusLine3TimesSamplingDisable ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    uint32_t PLIB_CAN_BaudRateGet(CAN_MODULE_ID index, uint32_t clock);

  Summary:
    Returns the current CAN module Baud rate.

  Description:
    This function returns the current baud rate of the CAN module.

  Precondition:
    None.

  Parameters:
    index      - Identifies the desired CAN module
    sysclock   - CAN input clock frequency
    
  Returns:
    Current Baud rate value in kbps.

  Example:
    <code>
    #define MY_CAN_ID   CAN_ID_1
    #define CAN_CLOCK   80000000
    
    uint32_t baudRate;
    
    baudRate = PLIB_CAN_BaudRateGet(MY_CAN_ID, CAN_CLOCK);
    </code>

  Remarks:
     The MY_CAN_ID macro in the example above is used as a place holder for the
    actual CAN bus ID (as defined by the processor-specific CAN_MODULE_ID enum).

    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_CAN_ExistsBaudRateGet in your application to determine whether
    this feature is available.
*/

uint32_t PLIB_CAN_BaudRateGet(CAN_MODULE_ID index, uint32_t sysclock);


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Channel Configuration
// *****************************************************************************
// *****************************************************************************
/*  APIs for the Channel configuration of the CAN module. */

// *****************************************************************************
/* Function:
    void PLIB_CAN_ChannelReset( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Resets a CAN channel.

  Description:
    This function resets a CAN channel. Resetting a CAN channel causes
    it to discard any unread received messages or any messages that have
    not been transmitted yet. The reset operation will wait if a message
    is being currently transmitted or is being received. The
    PLIB_CAN_ChannelResetIsComplete function can be used to check if the channel
	reset is complete.

  Precondition:
    None.

  Parameters:
    index     - Identifies the desired CAN module
    channel  - Identifies the CAN channel to be reset

  Returns:
    None.

  Example:
    <code>
    // Reset channel 4 of CAN_ID_1 module
    // and wait until the reset is complete

    PLIB_CAN_ChannelReset(CAN_ID_1,CAN_CHANNEL4);

    while(PLIB_CAN_ChannelResetIsComplete(CAN_ID_1,CAN_CHANNEL4) != true);
    </code>

  Remarks:
    Attempting to read from a channel that is reset will return
    messages that may have already been read or may not have been read at all.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsChannelReset in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ChannelReset ( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
/* Function:
    bool PLIB_CAN_ChannelResetIsComplete ( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Returns 'true' if the specified channel reset is complete.

  Description:
    This function returns 'true' if the specified channel reset is complete.
    This function should preferably be called after calling the
    PLIB_CAN_ChannelReset function.

  Precondition:
    None.

  Parameters:
    index     - Identifies the desired CAN module
    channel  - Identifies the CAN Channel to be inspected for reset

  Returns:
    - true  = Channel reset is complete
    - false = Channel reset is in progress

  Example:
    <code>

    // Reset channel 4 of CAN_ID_1 module
    // and wait until the reset is complete
    PLIB_CAN_ChannelReset(CAN_ID_1,CAN_CHANNEL4);

    while(PLIB_CAN_ChannelResetIsComplete(CAN_ID_1,CAN_CHANNEL4) != true);

    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsChannelReset in your application to determine whether
	this feature is available.
*/

bool PLIB_CAN_ChannelResetIsComplete ( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
/* Function:
    void PLIB_CAN_ChannelUpdate ( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Updates the CAN Channel internal pointers.

  Description:
    This function updates the CAN Channel internal pointers. This function
    should be called when a message has been read or processed completely from
    a CAN receive channel (using the PLIB_CAN_ReceivedMessageGet function).
    It should be called after a new message has been written to a CAN transmit
    channel (using the PLIB_CAN_TransmitBufferGet function) and before
    the PLIB_CAN_TransmitChannelFlush function.

    Trying to read a CAN receive channel that has not been updated will cause
    the PLIB_CAN_ReceivedMessageGet function to return the same message.
    Writing to a CAN transmit channel that has not been updated will cause the
    last written message to be overwritten.

  Precondition:
    This function is effective only when the CAN module is not in Configuration
    mode or Disable mode.

  Parameters:
    index     - Identifies the desired CAN module
    channel  - Identifies the CAN channel to be updated

  Returns:
    None.

  Example:
    <code>
    // CAN_ID_1 Channel 1 is a Receive channel and Channel 2 is a Transmit
    // channel. Read and update Channel 1. Write a message to Channel 2 and then
    // update and flush the channel.

    CAN_TX_MSG_BUFFER * TransmitMessage;
    CAN_RX_MSG_BUFFER * rxMessage;

    rxMessage = PLIB_CAN_ReceivedMessageGet(CAN_ID_1, CAN_CHANNEL1);

    if(rxMessage != NULL)
    {
        // Process the received message.

        PLIB_CAN_ChannelUpdate(CAN_ID_1, CAN_CHANNEL1);
    }

    TransmitMessage = PLIB_CAN_TransmitBufferGet(CAN_ID_1, CAN_CHANNEL2);
    if(TransmitMessage != NULL)
    {
        // Write a message to buffer

        PLIB_CAN_ChannelUpdate(CAN_ID_1, CAN_CHANNEL2);
        PLIB_CAN_TransmitChannelFlush(CAN_ID_1, CAN_CHANNEL2);
    }
    </code>

  Remarks:
    The PLIB_CAN_ChannelUpdate function should be called on a CAN receive
    channel only after the message obtained using the
    PLIB_CAN_ReceivedMessageGet function has been read or processed
    completely. The CAN module peripheral library does not provide access to
    older messages once the PLIB_CAN_ChannelUpdate function has been called.

    When using the PLIB_CAN_TransmitMessageBuffer function to write to a CAN
    transmit channel the PLIB_CAN_ChannelUpdate function should be called
    only when a valid message has been written to the channel. Calling the
    update function without writing to the CAN channel will cause an incorrect
    message to be output on the CAN channel when the transmit channel is
    flushed.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsChannelUpdate in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ChannelUpdate ( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Event Management
// *****************************************************************************
// *****************************************************************************
/*  APIs for the Event Management of the CAN module. */

// *****************************************************************************
/* Function:
    void PLIB_CAN_ModuleEventEnable ( CAN_MODULE_ID index, CAN_MODULE_EVENT flags )

  Summary:
    Enables the module level events.

  Description:
    This function enables module level events. Any enabled module event will
    cause the CAN module to generate a CPU interrupt.

  Precondition:
    None.

  Parameters:
    index  - Identifies the desired CAN module
    flags  - Identifies the CAN module level events to be affected. Several events
             can be controlled by logically ORed combination of events.

  Returns:
    None.

  Example:
    <code>
    // Enable CAN_ID_1 Transmit Event and Receive Events.
    // Disable Receive Overflow event and operation
    // mode change event.

    PLIB_CAN_ModuleEventEnable(CAN_ID_1, (CAN_TX_EVENT | CAN_RX_EVENT));
    PLIB_CAN_ModuleEventEnable(CAN_ID_1, (CAN_OPERATION_MODE_CHANGE_EVENT |
    	CAN_RX_OVERFLOW_EVENT));
    </code>

  Remarks:
    Note: An event can be active regardless of it being enabled or disabled.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsModuleEventEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ModuleEventEnable ( CAN_MODULE_ID index, CAN_MODULE_EVENT flags );


// *****************************************************************************
/* Function:
    void PLIB_CAN_ModuleEventDisable ( CAN_MODULE_ID index, CAN_MODULE_EVENT flags )

  Summary:
    Disables the module level events.

  Description:
    This function disables module level events. Any enabled module event will
    cause the CAN module to generate a CPU interrupt.

  Precondition:
    None.

  Parameters:
    index  - Identifies the desired CAN module
    flags  - Identifies the CAN module level events to be affected. Several events
             can be controlled by logically ORed combination of events.

  Returns:
    None.

  Example:
    <code>
    // Enable CAN_ID_1 Transmit Event and Receive Events.
    // Disable Receive Overflow event and operation
    // mode change event.

    PLIB_CAN_ModuleEventDisable(CAN_ID_1, (CAN_TX_EVENT | CAN_RX_EVENT));
    PLIB_CAN_ModuleEventDisable(CAN_ID_1, (CAN_OPERATION_MODE_CHANGE_EVENT |
    	CAN_RX_OVERFLOW_EVENT));
    </code>

  Remarks:
    Note: An event can be active regardless of it being enabled or disabled.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsModuleEventEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ModuleEventDisable ( CAN_MODULE_ID index, CAN_MODULE_EVENT flags );


// *****************************************************************************
/* Function:
    CAN_MODULE_EVENT PLIB_CAN_ModuleEventGet( CAN_MODULE_ID index )

  Summary:
    Returns the status of the CAN module events.

  Description:
    This function returns the status of the CAN module events. The routine
    returns a status word. This word should be logically ANDed with the
    desired CAN_MODULE_EVENT event mask. A non-zero result of such
    an operation would mean that the events specified in the event mask
    are active. An event mask can contain one event or can be a logical OR
    combination of multiple events.

  Precondition:
    None.

  Parameters:
    index  - Identifies the desired CAN module

  Returns:
    A status word representing the status of the CAN module events.

  Example:
    <code>

    // Check if the CAN_ID_1 Module Receive event
    // or if Transmit event is active

    if((PLIB_CAN_ModuleEventGet(CAN_ID_1) & (CAN_RX_EVENT | CAN_TX_EVENT)) != 0)
    {
        // Handle the Receive or Transmit module Event here.

    }

    // Check if the CAN_ID_2 System Error Event
    // is active

    if((PLIB_CAN_ModuleEventGet(CAN_ID_2) & CAN_SYSTEM_ERROR_EVENT) != 0)
    {
        // CAN_ID_2 System error event is active.

    }
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsModuleEventClear in your application to determine whether
	this feature is available.
*/

CAN_MODULE_EVENT PLIB_CAN_ModuleEventGet( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    void PLIB_CAN_ModuleEventClear (CAN_MODULE_ID index, CAN_MODULE_EVENT flags )

  Summary:
    Clears the CAN module level events.

  Description:
    This function clears module level events. If the event condition is
    persistent, clearing the event will have no effect. The event condition
    itself should be cleared. The CAN_SYSTEM_ERROR_EVENT can only be cleared by
    disabling the CAN module using the PLIB_CAN_Enable function.

  Precondition:
    None.

  Parameters:
    index - Identifies the desired CAN module
    flags  - Identifies the CAN module level events to be affected. Several events
             can be cleared by specifying a logically ORed combination of events.

  Returns:
    None.

  Example:
    <code>
    // Clear CAN_ID_1 Transmit Event and Receive Events.

    PLIB_CAN_ModuleEventClear(CAN_ID_1, (CAN_TX_EVENT | CAN_RX_EVENT));
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsModuleEventClear in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ModuleEventClear (CAN_MODULE_ID index, CAN_MODULE_EVENT flags );


// *****************************************************************************
/* Function:
    void PLIB_CAN_ChannelEventEnable ( CAN_MODULE_ID index, CAN_CHANNEL channel,
                        CAN_CHANNEL_EVENT flags )

  Summary:
    Enables channel level events.

  Description:
    This function enables channel level events. Any enabled channel event will
    cause a CAN module event. An event can be active regardless of it being
    enabled or disabled. Enabling a transmit type of event for a receive channel
    will have no any effect.

  Precondition:
    None.

  Parameters:
    index  - Identifies the desired CAN module
    channel - Identifies the desired CAN Channel
    flags  - Identifies the CAN channel event(s) to be affected. Several events
             can be controlled by logically ORed combination of events.

  Returns:
    None.

  Example:
    <code>
    // CAN_ID_1 Channel 1 and 3 are Transmit channels and Channel 2  and 4 are
    // Receive channels. Enable Channel 1 empty event and channel not full
    // event. Disable Channel 2 full and overflow event.
    // Enable all Transmit events on Channel 2 and disable all Receive events on
    // on Channel 4.

    PLIB_CAN_ChannelEventEnable(CAN_ID_1, CAN_CHANNEL1, (CAN_TX_CHANNEL_EMPTY |
    	CAN_TX_CHANNEL_NOT_FULL));

    PLIB_CAN_ChannelEventEnable(CAN_ID_1, CAN_CHANNEL2, (CAN_RX_CHANNEL_FULL |
    	CAN_RX_CHANNEL_OVERFLOW));

    PLIB_CAN_ChannelEventEnable(CAN_ID_1, CAN_CHANNEL3, CAN_TX_CHANNEL_ANY_EVENT);
    PLIB_CAN_ChannelEventEnable(CAN_ID_1, CAN_CHANNEL4, CAN_RX_CHANNEL_ANY_EVENT);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsChannelEventEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ChannelEventEnable ( CAN_MODULE_ID index, CAN_CHANNEL channel,
                        CAN_CHANNEL_EVENT flags );


// *****************************************************************************
/* Function:
    void PLIB_CAN_ChannelEventDisable ( CAN_MODULE_ID index, CAN_CHANNEL channel,
                        CAN_CHANNEL_EVENT flags )

  Summary:
    Enables channel level events.

  Description:
    This function disables channel level events. Any enabled channel event will
    cause a CAN module event.

  Precondition:
    None.

  Parameters:
    index  - Identifies the desired CAN module
    channel - Identifies the desired CAN channel
    flags  - Identifies the CAN channel event(s) to be affected. Several events
             can be controlled by logically ORed combination of events.

  Returns:
    None.

  Example:
    <code>
    PLIB_CAN_ChannelEventDisable(CAN_ID_1, CAN_CHANNEL1, CAN_TX_CHANNEL_EMPTY);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsChannelEventEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ChannelEventDisable ( CAN_MODULE_ID index, CAN_CHANNEL channel,
                        CAN_CHANNEL_EVENT flags );


// *****************************************************************************
/* Function:
    CAN_EVENT_CODE PLIB_CAN_PendingEventsGet ( CAN_MODULE_ID index )

  Summary:
    Returns a value representing the highest priority active event
    in the module.

  Description:
    This function returns a value representing the highest priority active event
    in the module. The return value is a CAN_EVENT_CODE type.

  Precondition:
    None.

  Parameters:
    index  - Identifies the desired CAN module

  Returns:
    Returns a CAN_EVENT_CODE type representing the highest priority active event
    in the module.

  Example:
    <code>
    // Implement a switch to check and process
    // any active CAN module events.

    CAN_EVENT_CODE eventCode;

    eventCode = PLIB_CAN_PendingEventsGet(CAN_ID_1);

    switch(eventCode)
	    {
	        case CAN_NO_EVENT:
	            // Procedure to handle no CAN events
	            break;

	        case CAN_WAKEUP_EVENT:
	            // Procedure to handle device wake-up
	            // on CAN bus activity event
	            break;

	        default:
	            break;
     	}
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsPendingEventsGet in your application to determine whether
	this feature is available.
*/

CAN_EVENT_CODE PLIB_CAN_PendingEventsGet ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    CAN_CHANNEL_MASK PLIB_CAN_AllChannelEventsGet( CAN_MODULE_ID index )

  Summary:
    Returns a value representing the event status of all CAN
    channels.

  Description:
    This function returns a value representing the event status of all of the
    CAN channels. The return value can be logically ANDed with a CAN_CHANNEL_MASK
    type to check whether the channel has any active events. Only an enabled
    channel event will cause the bit to be updated.

  Precondition:
    None.

  Parameters:
    index  - Identifies the desired CAN module

  Returns:
    Returns a value that can be logically ANDed with a CAN_CHANNEL_MASK mask value
    to check if any event on a channel is active.

  Example:
    <code>
    // Check if Channel 2 or 3 of CAN_ID_1 module
    // have any active events

    CAN_CHANNEL_MASK channelEvents;

    channelEvents = PLIB_CAN_AllChannelEventsGet(CAN_ID_1);

    if((channelEvents & (CAN_CHANNEL2_MASK | CAN_CHANNEL3_MASK)) != 0)
    {
        // Either Channel 2 or 3 has an active event.
        // The PLIB_CAN_ChannelEventGet function can be
        // used to query the channel for more details.
    }

    // Check if Channel 31 of CAN_ID_2 module
    // has an any active events

    channelEvents = PLIB_CAN_AllChannelEventsGet(CAN_ID_2);

    if((channelEvents & CAN_CHANNEL31_MASK) != 0)
    {
        // Channel 31 of CAN_ID_2 module
        // has an active event.
    }
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsAllChannelEvents in your application to determine whether
	this feature is available.
*/

CAN_CHANNEL_MASK PLIB_CAN_AllChannelEventsGet( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    CAN_CHANNEL_MASK PLIB_CAN_AllChannelOverflowStatusGet ( CAN_MODULE_ID index )

  Summary:
    Returns a value representing the receive overflow event status
    of all CAN channels.

  Description:
    This function returns a value representing the Receive overflow event status
    of all the CAN Channels. The return value can be logically ANDed with a
    CAN_CHANNEL_MASK type to check whether a channel has any active receive overflow
    events. The return value will reflect the channel status only if the receive
    overflow event of the channel is enabled.

  Precondition:
    None.

  Parameters:
    index  - Identifies the desired CAN module

  Returns:
    Returns a value that can be logically ANDed with a CAN_CHANNEL_MASK mask
    value to check if a receive channel overflow event is active.

  Example:
    <code>
    // Check if Receive Channel 2 or 3 of CAN_ID_1 module
    // have overflowed

    CAN_CHANNEL_MASK channelOverflowEvent;

    channelOverflowEvent = PLIB_CAN_AllChannelOverflowStatusGet(CAN_ID_1);

    if((channelOverflowEvent & (CAN_CHANNEL2_MASK | CAN_CHANNEL3_MASK)) != 0)
    {
        // Either Receive Channel 2 or 3 has  overflowed.
        // The PLIB_CAN_ChannelEventGet function can be
        // used to query the channel for more details.
    }

    // Check if Receive Channel 31 of CAN_ID_2 module
    // has overflowed

    channelOverflowEvent = PLIB_CAN_AllChannelOverflowStatusGet(CAN_ID_2);

    if((channelOverflowEvent & CAN_CHANNEL31_MASK) != 0)
    {
        // Channel 31 of CAN_ID_2 module
        // has overflowed.
    }
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsAllChannelOverflow in your application to determine whether
	this feature is available.
*/

CAN_CHANNEL_MASK PLIB_CAN_AllChannelOverflowStatusGet ( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    CAN_CHANNEL_EVENT PLIB_CAN_ChannelEventGet ( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Returns a value representing the event status of a CAN channel.

  Description:
    This function returns a value representing the event status of a CAN channel.
    The return value can be logically ANDed with CAN_CHANNEL_EVENT type to
    check for a specific event(s). Channels events are affected regardless of
    whether the event itself is enabled or disabled.

  Precondition:
    None.

  Parameters:
    index   - Identifies the desired CAN module
    channel - Identifies the desired CAN Channel

  Returns:
    Returns a value that can be logically ANDed with a CAN_CHANNEL_EVENT type to check
    if specific CAN channel events are active.

  Example:
    <code>
    // Check if Receive Channel 2 of CAN_ID_1 module
    // is not empty or if its full.

    CAN_CHANNEL_EVENT channelEvent;

    channelEvent = PLIB_CAN_ChannelEventGet(CAN_ID_1,CAN_CHANNEL2);

    if((channelEvent & (CAN_RX_CHANNEL_NOT_EMPTY | CAN_RX_CHANNEL_FULL)) != 0)
    {
        // This means that either Receive Channel 2 is not empty
        // or the Channel is full.


    }

    // Check if Transmit Channel 3 of CAN_ID_2 module
    // has any active events

    channelEvent = PLIB_CAN_ChannelEventGet(CAN_ID_2, CAN_CHANNEL3);

    if((channelEvent & CAN_TX_CHANNEL_ANY_EVENT) != 0)
    {
        // This means that some event is active

    }

    // Check if Transmit Channel 6 of CAN_ID_2 module is not full

    channelEvent = PLIB_CAN_ChannelEventGet(CAN_ID_2, CAN_CHANNEL6);

    if((channelEvent & CAN_TX_CHANNEL_NOT_FULL) != 0)
    {
        // This means the Channel is not full.

    }
    </code>


  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsChannelEvent in your application to determine whether
	this feature is available.
*/

CAN_CHANNEL_EVENT PLIB_CAN_ChannelEventGet ( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
/* Function:
    void PLIB_CAN_ChannelEventClear ( CAN_MODULE_ID index, CAN_CHANNEL channel, CAN_CHANNEL_EVENT events )

  Summary:
    Clears CAN channel events.

  Description:
    This function clears channel events. The events to be cleared are
    specified as mask. Note that only the receive overflow event is clearable.
    Attempting to clear other events will have no effect since these events are
    persistent and clear only when the event condition is cleared.

  Precondition:
    None.

  Parameters:
    index   - Identifies the desired CAN module
    channel - Identifies the desired CAN Channel
    events  - Mask specifying the events to be cleared

  Returns:
    None.

  Example:
    <code>
    // Clear CAN_ID_2 Receive Channel 3 overflow event

    PLIB_CAN_ChannelEventClear(CAN_ID_2, CAN_CHANNEL3, CAN_RX_CHANNEL_OVERFLOW);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsChannelEvent in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ChannelEventClear ( CAN_MODULE_ID index, CAN_CHANNEL channel, CAN_CHANNEL_EVENT events );


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Message Transmit Functions
// *****************************************************************************
// *****************************************************************************
/*  APIs for the Message Transmission of the CAN module. */

// *****************************************************************************
/* Function:
    void PLIB_CAN_ChannelForTransmitSet ( CAN_MODULE_ID index,
							CAN_CHANNEL channel, uint8_t channelSize,
							CAN_TX_RTR rtren, CAN_TXCHANNEL_PRIORITY priority )

  Summary:
    Configures a CAN channel for transmission.

  Description:
    This function configures a CAN Channel for transmission. The size of
    the channel specifies the number of messages that the channel can
    buffer. The channel is a First In First Out (FIFO) type of buffer. The
    remote transmit request feature allows the transmit channel to start
    transmitting when an associated filter has received a message. The transmit
    channel priority determines the priority as compared to other transmit
    channels. If two transmit channels have the same priority, the natural
    channel priority determines which channel transmits first.

  Precondition:
    The CAN Module should be in Configuration mode. This is achieved by using
    the PLIB_CAN_OperationModeSelect function.

  Parameters:
    index        - Identifies the desired CAN module
    channel      - Identifies the desired CAN Channel
    channelSize  - Size of the channel in messages. This value should be
                   between 1 and 32.
    rtren        - Enables disables Remote Transmit Request:
                   * CAN_TX_RTR_ENABLED - Remote Transmit Request is enabled
                   * CAN_TX_RTR_DISABLED - Remote Transmit Request is disabled
    priority     - Specifies the priority of the Transmit channel

  Returns:
    None.

  Example:
    <code>
    // Configure CAN 1 Channel 2 for Transmit operation. Set the channel size to 15
    // and enable remote transmit request. Set the priority to low medium
    // priority.

    PLIB_CAN_ChannelForTransmitSet (CAN_ID_1, CAN_CHANNEL2, 15,
    	CAN_TX_RTR_ENABLED, CAN_LOW_MEDIUM_PRIORITY);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsChannelForTransmitSet in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ChannelForTransmitSet ( CAN_MODULE_ID index,
                                    CAN_CHANNEL channel,
                                    uint8_t channelSize,
                                    CAN_TX_RTR rtren,
                                    CAN_TXCHANNEL_PRIORITY priority );


// *****************************************************************************
/* Function:
    void PLIB_CAN_PendingTransmissionsAbort ( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Aborts any pending transmit operations.

  Description:
    This function aborts any pending transmit operations. Any messages that are yet
    to be transmitted will not be transmitted. The messages will still be
    present in the respective channel. Any message that is in the process of
    being transmitted will be transmitted completely. Either one channel or
    all channels can be specified.

  Precondition:
    None.

  Parameters:
    index        - Identifies the desired CAN module
    channel      - Identifies the desired CAN channel. By specifying
                   CAN_ALL_CHANNELS, transmission on all transmit channels will be
                   aborted.

  Returns:
    None.

  Example:
    <code>
    // Abort any pending transmissions on CAN_ID_1 Channel 4 and
    // Channel 5.
    PLIB_CAN_PendingTransmissionsAbort(CAN_ID_1, CAN_CHANNEL4);
    PLIB_CAN_PendingTransmissionsAbort(CAN_ID_1, CAN_CHANNEL5);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsPendingTransmissionsAbort in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_PendingTransmissionsAbort ( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
/* Function:
    void PLIB_CAN_TransmitChannelFlush ( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Causes all messages in the specified transmit channel to be transmitted.

  Description:
    This function causes all messages in the specified transmit channel to be
    transmitted. All messages in the channel at the time of the flush operation
    will be transmitted. The transmit channel flush operation should preferably be
    called immediately after the PLIB_CAN_ChannelUpdate function. This will ensure
    that messages are transmitted promptly.

  Precondition:
    None.

  Parameters:
    index        - Identifies the desired CAN module
    channel      - Identifies the desired CAN channel

  Returns:
    None.

  Example:
    <code>
    // Flush CAN_ID_1 Transmit Channel 4.

    PLIB_CAN_TransmitChannelFlush(CAN_ID_1, CAN_CHANNEL4);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTransmitChannelFlush in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_TransmitChannelFlush ( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
/* Function:
    CAN_TX_CHANNEL_STATUS PLIB_CAN_TransmitChannelStatusGet( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Returns the condition of the transmit channel.

  Description:
    This function returns the condition of the transmit channel. The return value
    can be logically ANDed with CAN_TX_CHANNEL_STATUS type values.

  Precondition:
    None.

  Parameters:
    index        - Identifies the desired CAN module
    channel      - Identifies the desired CAN channel

  Returns:
    Returns a status word that can be logically ANDed with the
    CAN_TX_CHANNEL_STATUS type to check whether a condition exists.

  Example:
    <code>
    // Check if CAN_ID_1 Transmit Channel 4
    // is still transmitting

    CAN_TX_CHANNEL_STATUS status;

    status = PLIB_CAN_TransmitChannelStatusGet(CAN_ID_1, CAN_CHANNEL4);

    if((status & CAN_TX_CHANNEL_TRANSMITTING) != 0)
    {
        // This means that channel is still
        // transmitting.

    }

    // Check if CAN_ID_2 Transmit Channel 5 has lost arbitration
    // or other Transmit errors.

    status = PLIB_CAN_TransmitChannelStatusGet(CAN_ID_2, CAN_CHANNEL5);

    if((status & (CAN_TX_CHANNEL_ARBITRATION_LOST | CAN_TX_CHANNEL_ERROR)) != 0)
    {
        // This means that the Transmit channel has either
        // lost arbitration or a Transmit error has occurred.
    }
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTransmitChannelStatus in your application to determine
	whether this feature is available.
*/

CAN_TX_CHANNEL_STATUS PLIB_CAN_TransmitChannelStatusGet( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
/* Function:
    CAN_TX_MSG_BUFFER * PLIB_CAN_TransmitBufferGet( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Returns a pointer to an empty transmit buffer.

  Description:
    This function returns a pointer to an empty transmit buffer. The routine will
    return a NULL pointer if there aren't any empty transmit buffers. In such a
    case, the application should flush the channel and wait until the transmit
    channel has at least one empty buffer. In order to function correctly, it is
    essential that the PLIB_CAN_ChannelUpdate function is called in the proper
    sequence for the PLIB_CAN_TransmitBufferGet function to return a pointer
    to an empty buffer.

  Precondition:
    PLIB_CAN_MemoryBufferAssign must be called if the 'transmit buffer' should
    be in the device RAM. It is not required if the 'transmit buffer' is in
    SFR space.

  Parameters:
    index        - Identifies the desired CAN module
    channel      - Identifies the desired CAN Channel

  Returns:
    Returns a CAN_TX_MSG_BUFFER type pointer to an empty message buffer in the
    Transmit channel. Returns NULL if the channel is full and there aren't any
    empty message buffers.

  Example:
    <code>
    // Transmit a message through CAN_ID_1 Channel 4

    CAN_TX_MSG_BUFFER * msgBuffer;

    msgBuffer = PLIB_CAN_TransmitBufferGet(CAN_ID_1, CAN_CHANNEL4);

    if(msgBuffer != NULL)
    {
        // Load the message here

    }
    else
    {
        // No space in the channel
        // wait until a message
        // buffer is free.

        while((PLIB_CAN_ChannelEventGet(CAN_ID_1, CAN_CHANNEL4) &
        	CAN_TX_CHANNEL_NOT_FULL) == 0);
    }
    </code>

  Remarks:
    Calling the PLIB_CAN_TransmitBufferGet function on a channel that has not
    been updated after a message was written to the channel, will cause the
    function to return a pointer to the written message in case of
    transmit buffer FIFO. Therefore, a non-transmitted message could get
    overwritten.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTransmitBufferGet in your application to determine whether
	this feature is available.
*/

CAN_TX_MSG_BUFFER * PLIB_CAN_TransmitBufferGet( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
/* Function:
    bool PLIB_CAN_TransmissionIsAborted ( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Returns 'true' if the transmit abort operation is complete.

  Description:
    This function returns 'true' if the transmit abort operation is complete.
    Either individual channels can be specified or all channels can be specified.

  Precondition:
    None.

  Parameters:
    index        - Identifies the desired CAN module
    channel      - Identifies the desired CAN channel. By specifying
    			   CAN_ALL_CHANNELS the status of transmit abort on all
    			   transmit channels will be returned.
  Returns:
    - true  - If channel = CAN_ALL_CHANNELS, Transmit Abort is complete. If 
              channel = CAN_CHANNELx, Transmit Abort was successful.
    - false - If channel = CAN_ALL_CHANNELS, Transmit Abort is in progress. If 
              channel = CAN_CHANNELx, Transmit Abort was not successful.

  Example:
    <code>
    // Abort any pending transmissions on CAN_ID_1 Channel 4 and
    // check if the current message transmission was aborted.

    PLIB_CAN_PendingTransmissionsAbort(CAN_ID_1, CAN_CHANNEL4);

    if(PLIB_CAN_TransmissionIsAborted(CAN_ID_1, CAN_CHANNEL4) == false)
    {
        // The message was not aborted.
    }
    else
    {
        // The message was aborted.
    }
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTransmissionIsAborted in your application to determine whether
	this feature is available.
*/

bool PLIB_CAN_TransmissionIsAborted( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Message Receive Functions
// *****************************************************************************
// *****************************************************************************
/*  APIs for the Message Reception of the CAN module. */

// *****************************************************************************
/* Function:
    CAN_RX_MSG_BUFFER * PLIB_CAN_ReceivedMessageGet( CAN_MODULE_ID index, CAN_CHANNEL channel )

  Summary:
    Returns a pointer to a message to be read from the CAN channel.

  Description:
    This function returns a CAN_RX_MSG_BUFFER pointer to a message to be
    read from the CAN channel.  The PLIB_CAN_ChannelUpdate routine should be called
    after the received message has been processed.

  Precondition:
    None.

  Parameters:
    index        - Identifies the desired CAN module.
    channel      - Identifies the desired CAN Receive channel.

  Returns:
    Returns a pointer to a message to be read from the CAN channel;  returns a
    CAN_RX_MSG_BUFFER type pointer to a received CAN message. If the
    receive channel is a full CAN message receive channel, the caller should
    use the msgSID, msgEID and data members of the CAN_RX_MSG_BUFFER data
    structure to access the received CAN message. If the receive channel is
    a data-only channel, the message will only contain 8 payload data bytes
    (even if the message was placed on the bus with less than 8 bytes). The
    caller in this case should use the dataOnlyMsgData member of the
    CAN_RX_MSG_BUFFER data structure to read the data contained in the
    received CAN message.

  Example:
    <code>
    // Read a message from the CAN_ID_1 Channel 8
    // which is configured as full CAN message
    // receive channel.

    CAN_RX_MSG_BUFFER * receivedMsg;

    receivedMsg = (CAN_RX_MSG_BUFFER *)PLIB_CAN_ReceivedMessageGet(CAN_ID_1,
    	CAN_CHANNEL8);

    if(receivedMsg != NULL)
    {
        // rxMsg is pointing to
        // a CAN message. Process
        // the message and then update
        // the CAN channel.


        PLIB_CAN_ChannelUpdate(CAN_ID_1, CAN_CHANNEL8);
    }

    // Read a message from the CAN_ID_2 Channel 9
    // which is configured as data only message
    // receive channel. Access the message
    // as bytes;

    CAN_RX_MSG_BUFFER * rxMsg;

    rxMsg = PLIB_CAN_ReceivedMessageGet(CAN_ID_2, CAN_CHANNEL9);

    if(rxMsg != NULL)
    {
        // rxMsg is pointing to
        // a CAN message. Process
        // the message and then update
        // the CAN channel.

        // rxMsg->dataOnlyMsgData[0] is the first byte of message
        // data payload. rxMsg->dataOnlyMsgData[0] is the second
        // byte of message data payload and so on.


        PLIB_CAN_ChannelUpdate(CAN_ID_2, CAN_CHANNEL9);
    }
    </code>

  Remarks:
    The CAN receive channel is configured as a full CAN message receive channel
    or a data-Only channel while configuring the channel using the
    PLIB_CAN_ChannelForReceiveSet function.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsReceivedMessageGet in your application to determine whether
	this feature is available.
*/

CAN_RX_MSG_BUFFER * PLIB_CAN_ReceivedMessageGet( CAN_MODULE_ID index, CAN_CHANNEL channel );


// *****************************************************************************
/* Function:
    void PLIB_CAN_ChannelForReceiveSet( CAN_MODULE_ID index, CAN_CHANNEL channel,
                        uint32_t channelSize, CAN_RX_DATA_MODE dataOnly )

  Summary:
    Configures a CAN channel for receive operation.

  Description:
    This function configures a CAN channel for receive operation. A receive channel
    can be either a full CAN message receive channel, which receives an entire CAN
    message (Arbitration field + Data field) or a data-only message channel, which
    receives only the data payload section of the message. A receive channel can
    buffer up to 32 messages. The number of messages to buffer (i.e., the size of the
    channel) is set by the channelSize parameter.

  Precondition:
    The CAN module should be in Configuration mode. This is achieved by using the
    PLIB_CAN_OperationModeSelect function.

  Parameters:
    index        - Identifies the desired CAN module
    channel      - Identifies the desired CAN Receive channel
    channelSize  - Specifies the number of received messages that the channel
                   can buffer before it overflows. This should be a value
                   between 1 and 32.
    dataOnly     - Specifies a full CAN message Receive channel or a data-only
    				message channel.
                   * CAN_RX_DATA_ONLY - Channel will be a data-only message
                   	receive channel
                   * CAN_RX_FULL_RECEIVE - Channel will be a full CAN message
                   	receive channel
  Returns:
    None.

  Example:
    <code>
    // Configure channel 4 of CAN module for receive operation. Set channel
    // size to buffer 10 messages.
    // Channel should be data only receive channel

    PLIB_CAN_ChannelForReceiveSet(CAN_ID_1, CAN_CHANNEL4, 10, CAN_RX_DATA_ONLY);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsChannelForReceiveSet in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_ChannelForReceiveSet( CAN_MODULE_ID index, CAN_CHANNEL channel,
		uint32_t channelSize, CAN_RX_DATA_MODE dataOnly );


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Message Filtering functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PLIB_CAN_FilterMaskConfigure( CAN_MODULE_ID index, CAN_FILTER_MASK mask,
    			uint32_t maskBits, CAN_ID_TYPE idType, CAN_FILTER_MASK_TYPE mide )

  Summary:
    Configures a CAN filter mask.

  Description:
    This function configures a CAN filter mask. The mask bits determine which
    message ID bits are ignored and compared during the filtering process.

  Precondition:
    The CAN module should be in Configuration mode. This is achieved by using the
    PLIB_CAN_OperationModeSelect function.

  Parameters:
    index    - Identifies the desired CAN module
    mask     - Identifies the desired CAN receive filter mask.
    maskBits - A value in the range 0x0 to 0x7FF for SID range or 0x0 to
               0x1FFFFFFF for the EID range. Each set bit will mean that
               the corresponding bit in the filter will be compared to the
               corresponding bit in the message ID. A clear mask bit means
               the corresponding bit in the incoming message ID field will
               be ignored.
    idType   - Specifies the value range of maskBits parameter.
               * CAN_EID - Value range of maskBits parameter is 0x0 (ignore all
               	 29 bits of the incoming message ID) to 0x1FFFFFFF (compare all
               	 29 bits of the incoming message ID).
               * CAN_SID - Value range of maskBits parameter is 0x0 (ignore all
                 11 bits of the incoming message ID) to 0x7FF (compare all 11
                 bits of the incoming message ID).
    mide     - Specifies ID masking options
               * CAN_FILTER_MASK_IDE_TYPE - Masking will be performed
                 by filter type only. If the filter is set up for SID messages,
                 the mask will decline all incoming EID messages. If the filter
                 is set up for EID messages, the mask will decline all incoming
                 SID messages
               * CAN_FILTER_MASK_ANY_TYPE - Masking will be performed
                 regardless of the incoming message ID type. The message will
                 be accepted on a Filter and Message SID match or a filter
                 and message SID/EID match.

  Returns:
    None.

  Example:
    <code>
    // Configure CAN_ID_1 Filter Mask 2 to accept
    // extended ID messages in the range 0x4F1DE8 - 0x4F1DEC.
    // On analyzing this address range it can be seen that only
    // the last two bits of the incoming CAN message should ignored.
    // Therefore the mask value should 0x1FFFFFFC.
    // This mask will be used with a extended ID filter.
    // Set the masking option to filter IDE type.

    PLIB_CAN_FilterMaskConfigure(CAN_ID_1, CAN_FILTER_MASK2, 0x1FFFFFFC,
                                CAN_EID, CAN_FILTER_MASK_IDE_TYPE);
    </code>

  Remarks:
    A mask bit value of zero essentially means that all messages with any ID
    are accepted. The mode and idType input parameters are still relevant in
    such a case.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsFilterMaskConfigure in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_FilterMaskConfigure( CAN_MODULE_ID index, CAN_FILTER_MASK mask,
				uint32_t maskBits, CAN_ID_TYPE idType, CAN_FILTER_MASK_TYPE mide );


// *****************************************************************************
/* Function:
    void PLIB_CAN_FilterConfigure ( CAN_MODULE_ID index, CAN_FILTER filter,
                                        uint32_t id, CAN_ID_TYPE filterType )

  Summary:
    Configures a CAN message acceptance filter.

  Description:
    This function configures a CAN message acceptance  filter. The ID field
    of the incoming message must match the filter bits for the CAN
    module to accept the message. A filter can be a EID type filter, which
    filters EID messages or a SID filter, which in turn filters SID messages. The
    filter mask bits (configured using the PLIB_CAN_FilterMaskConfigure
    function) additionally allow specified message ID bits to be ignored in the
    filtering process.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module
    filter   - Identifies the desired CAN receive filter
    id       - A value in the range 0x0 to 0x7FF for SID filter type or
               0x0 to 0x1FFFFFFF for EID filter type.
    filterType - Specifies the type of filter
                 * CAN_EID - Filter is an extended ID message filter
                 * CAN_SID - Filter is an standard ID message filter

  Returns:
    None.

  Example:
    <code>
    // Configure CAN_ID_2 filter 4 to accept standard ID messages
    // with SID 0x100

    PLIB_CAN_FilterConfigure(CAN_ID_2, CAN_FILTER4, 0x100, CAN_SID);
    </code>

  Remarks:
    A CAN message acceptance filter can be configured in Normal
    operation mode. The filter must be disabled before this is done.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsFilterConfigure in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_FilterConfigure( CAN_MODULE_ID index, CAN_FILTER filter, uint32_t id, CAN_ID_TYPE filterType );


// *****************************************************************************
/* Function:
    void PLIB_CAN_FilterEnable( CAN_MODULE_ID index, CAN_FILTER filter )

  Summary:
    Enables a CAN message acceptance filter.

  Description:
    This function enables a CAN message acceptance filter. At least
    one filter must be enabled for the CAN module to receive messages.
    A receive channel associated with a filter will not receive messages unless
    the filter is enabled. After a filter is disabled, the
    PLIB_CAN_FilterIsDisabled function should be called to verify that the filter
    is disabled. A filter must be disabled before it can be configured.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module
    filter   - Identifies the desired CAN message acceptance filter

  Returns:
    None.

  Example:
    <code>
    // Enable filter 6 of CAN_ID_2

    PLIB_CAN_FilterEnable (CAN_ID_2, CAN_FILTER6);


    while(!PLIB_CAN_FilterIsDisabled(CAN_ID_1, CAN_FILTER4));
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsFilterEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_FilterEnable( CAN_MODULE_ID index, CAN_FILTER filter );


// *****************************************************************************
/* Function:
    void PLIB_CAN_FilterDisable( CAN_MODULE_ID index, CAN_FILTER filter )

  Summary:
    Disables a CAN message acceptance filter.

  Description:
    This function disables a CAN message acceptance filter. At least
    one filter must be enabled for the CAN module to receive messages.
    A receive channel associated with a filter will not receive messages unless
    the filter is enabled. After a filter is disabled, the
    PLIB_CAN_FilterIsDisabled function should be called to verify that the filter
    is disabled. A filter must be disabled before it can be configured.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module
    filter   - Identifies the desired CAN Message Acceptance Filter

  Returns:
    None.

  Example:
    <code>
    // Enable filter 6 of CAN_ID_2

    PLIB_CAN_FilterDisable (CAN_ID_2, CAN_FILTER6);

    while(PLIB_CAN_FilterIsDisabled(CAN_ID_1, CAN_FILTER4));
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsFilterEnable in your application to determine whether
	this feature is available.
*/

void PLIB_CAN_FilterDisable( CAN_MODULE_ID index, CAN_FILTER filter );


// *****************************************************************************
/* Function:
    bool PLIB_CAN_FilterIsDisabled( CAN_MODULE_ID index, CAN_FILTER filter )

  Summary:
    Returns 'true' if the specified filter is disabled.

  Description:
    Returns 'true' if the specified filter is disabled. This function should be
    called to check if the filter is disabled before calling the
    PLIB_CAN_FilterConfigure function and PLIB_CAN_FilterToChannelLink function.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module
    filter  - Identifies the desired CAN filter

  Returns:
    - true  = The filter is disabled
    - false = The filter is enabled

  Example:
    <code>
    // Disable CAN_ID_1 filter 3 and wait until the filter is disabled.
    PLIB_CAN_FilterEnable(CAN_ID_1, CAN_FILTER3);

    while(PLIB_CAN_FilterIsDisabled(CAN_ID_1, CAN_FILTER3) == false);
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsFilterEnable in your application to determine whether
	this feature is available.
*/

bool PLIB_CAN_FilterIsDisabled( CAN_MODULE_ID index, CAN_FILTER filter );


// *****************************************************************************
/* Function:
    CAN_FILTER	PLIB_CAN_LatestFilterMatchGet( CAN_MODULE_ID index )

  Summary:
    Returns the index of the filter that accepted the latest message.

  Description:
    This function returns the index of the filter that accepted the latest
    message.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module

  Returns:
    Index of the filter that accepted the latest message

  Example:
    <code>
    // Check if CAN_ID_2 module Receive Buffer event
    // is active and if so check which filter
    // accepted the message.

    CAN_FILTER filter;

    if((PLIB_CAN_ModuleEventGet(CAN_ID_1) & CAN_RX_EVENT) != 0)
    {
        // Check which filter accepted the message

        filter = PLIB_CAN_LatestFilterMatchGet(CAN_ID_1);
    }
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsLatestFilterMatchGet in your application to determine whether
	this feature is available.
*/

CAN_FILTER	PLIB_CAN_LatestFilterMatchGet( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
       void PLIB_CAN_FilterToChannelLink( CAN_MODULE_ID index, CAN_FILTER filter,
                       CAN_FILTER_MASK mask, CAN_CHANNEL channel )

  Summary:
    Links a filter to a channel.

  Description:
    This function links a filter to a channel. A filter is typically linked
    to a receive channel. This allows the channel to receive messages
    accepted by the filter. A filter can also be linked to a transmit
    channel if the transmit channel is configured for remote request
    transmit. In this case, a message accepted by the filter will
    automatically cause the linked transmit channel to transmit CAN
    messages that are buffered in the channel. Note that a filter should be
    enabled using the PLIB_CAN_FilterEnable function after the filter has
    been linked to the desired channel.

  Conditions:
    Filter should have been disabled using the PLIB_CAN_FilterDisable
    function.

  Input:
    index -    Identifies the desired CAN module
    filter -   Identifies the desired CAN Filter
    mask -     Identifies the mask to be used with this filter
    channel -  Identifies the channel to be linked to this filter. If a
               transmit channel is linked, the transmit channel should have
               its remote transmit request feature enabled.

  Return:
    None.

  Example:
    <code>
    // Configure CAN_ID_1 filter 3 to accept extended ID messages
    // with EID 0x1D400 and link the filter to CAN_ID_1 Channel 5.
    // Note the sequence in which the steps are performed.
    // Disable the filter and check if its disabled.
    // Configure the filter. Link it to the Channel and then
    // enable the filter.

    PLIB_CAN_FilterDisable(CAN_ID_1, CAN_FILTER3);

    while(PLIB_CAN_FilterIsDisabled(CAN_ID_1, CAN_FILTER3) == false);

    PLIB_CAN_FilterConfigure(CAN_ID_1, CAN_FILTER3, 0x1D400, CAN_EID);

    PLIB_CAN_FilterToChannelLink(CAN_ID_1, CAN_FILTER3, CAN_FILTER_MASK0,
        CAN_CHANNEL5);

    PLIB_CAN_FilterEnable(CAN_ID_1, CAN_FILTER3);
    </code>

  Remarks:
    This feature may not be available on all devices. Please refer to the
    specific device data sheet to determine availability or use
    PLIB_CAN_ExistsFilterToChannelLink in your application to determine
    whether this feature is available.
  ********************************************************************************/

void PLIB_CAN_FilterToChannelLink( CAN_MODULE_ID index, CAN_FILTER filter,
                    CAN_FILTER_MASK mask, CAN_CHANNEL channel );


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Error State Tracking
// *****************************************************************************
// *****************************************************************************
/*  APIs for the Error State Tracking of the CAN module. */

// *****************************************************************************
/* Function:
    int PLIB_CAN_ReceiveErrorCountGet( CAN_MODULE_ID index )

  Summary:
    Returns the CAN receive error count.

  Description:
    This function returns the CAN receive error count. Refer to the CAN 2.0B
    specification for more details on the CAN receive error count and its
    significance.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module

  Returns:
    Returns the CAN receive error count.

  Example:
    <code>
    // Check if CAN_ID_1 Receive error count is more than 200.
    int errCount;

    errCount = PLIB_CAN_ReceiveErrorCountGet(CAN_ID_1);
    if(errCount > 200)
    {
        // This error count is high.
        // Do some diagnostics.
    }
    </code>

  Remarks:
    There are multiple bus conditions, which could cause the receive error
    count to increase. Please refer to the CAN 2.0b specification for details.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsReceiveErrorCount in your application to determine whether
	this feature is available.
*/

int PLIB_CAN_ReceiveErrorCountGet( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    int PLIB_CAN_TransmitErrorCountGet( CAN_MODULE_ID index )

  Summary:
    Returns the CAN transmit error count

  Description:
    This function returns the CAN transmit error count. Refer to CAN 2.0B
    specification for more details on the CAN transmit error count and its
    significance.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module

  Returns:
    Returns the CAN transmit error count.

  Example:
    <code>
    // Check if the CAN_ID_1 Transmit error count is more than 200
    int errorCount;

    errorCount = PLIB_CAN_TransmitErrorCountGet(CAN_ID_1);
    if(errorCount > 200)
    {
        // This error count is high.
        // Do some diagnostics.
    }
    </code>

  Remarks:
    There are multiple bus conditions, which could cause the transmit error
    count to increase. Please refer to the CAN 2.0B specification for details.

	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsTransmitErrorCountGet in your application to determine
	whether this feature is available.
*/

int PLIB_CAN_TransmitErrorCountGet( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    CAN_ERROR_STATE PLIB_CAN_ErrorStateGet( CAN_MODULE_ID index )

  Summary:
    Returns the CAN error status word.

  Description:
    This function returns the CAN error status word. The return word can be
    logically ANDed with the desired CAN_ERROR_STATE member to check if the CAN
    module is in a specific error state.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module

  Returns:
    Returns the CAN_ERROR_STATE word, which can be logically ANDed with the
    desired CAN_ERROR_STATE member to check whether the CAN module is in a
    specific error state.

  Example:
    <code>
    // Check if CAN_ID_1 is in the Transmit or Receive warning state.
    CAN_ERROR_STATE errorState;

    errorState = PLIB_CAN_ErrorStateGet(CAN_ID_1);

    if((errorState & CAN_TX_RX_WARNING_STATE) != 0)
    {
        // CAN_ID_1 is in either  Transmit or Receive warning state.
    }
    // Check if CAN_ID_2 is in the Receive Bus Passive or Transmit Bus passive
    // state.
    errorState = PLIB_CAN_ErrorStateGet(CAN_ID_2);

    if((errorState & (CAN_TX_BUS_PASSIVE_STATE | CAN_RX_BUS_PASSIVE_STATE)) != 0)
    {
        // This means that the CAN module is in Transmit Bus Passive
        // or Receive Bus Passive state.
     }
    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsErrorState in your application to determine whether
	this feature is available.
*/

CAN_ERROR_STATE PLIB_CAN_ErrorStateGet ( CAN_MODULE_ID index );


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Information Functions
// *****************************************************************************
// *****************************************************************************
/*  APIs which gives the features of the CAN module. */

// *****************************************************************************
/* Function:
    char PLIB_CAN_TotalChannelsGet( CAN_MODULE_ID index )

  Summary:
    Returns the total number of CAN channels per CAN module.

  Description:
    This function returns the total number of CAN channels per CAN module.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module

  Example:
    <code>
    char totalChannels;

    totalChannels = PLIB_CAN_TotalChannelsGet(CAN_ID_1);
    </code>

  Returns:
    The total number of CAN channels per CAN module.

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsModuleInfo in your application to determine whether
	this feature is available.
*/

char PLIB_CAN_TotalChannelsGet( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    char PLIB_CAN_TotalFiltersGet( CAN_MODULE_ID index )

  Summary:
    Returns the total number of CAN Filters per CAN module.

  Description:
    This function returns the total number of CAN filters per CAN module.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module

  Example:
    <code>
    char totalFilters;

    totalFilters = PLIB_CAN_TotalFiltersGet(CAN_ID_1);
    </code>

  Returns:
    The total number of CAN Filters per CAN module.

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsModuleInfo in your application to determine whether
	this feature is available.
*/

char PLIB_CAN_TotalFiltersGet( CAN_MODULE_ID index );


// *****************************************************************************
/* Function:
    char PLIB_CAN_TotalMasksGet( CAN_MODULE_ID index )

  Summary:
    Returns the total number of CAN masks per CAN module.

  Description:
    This function returns the total number of CAN masks per CAN module.

  Precondition:
    None.

  Parameters:
    index    - Identifies the desired CAN module

  Example:
    <code>
    char totalMasks;

    totalMasks = PLIB_CAN_TotalMasksGet(CAN_ID_1);
    </code>

  Returns:
    The total number of CAN Masks per CAN module.

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_CAN_ExistsModuleInfo in your application to determine whether
	this feature is available.
*/

char PLIB_CAN_TotalMasksGet( CAN_MODULE_ID index );


//DOM-IGNORE-BEGIN
//******************************************************************************
/* The following functions have been deprecated.  Their use is not recommended 
   for the future development.  They are maintained here only for backward 
   compatibility.
*/
void PLIB_CAN_PhaseSegment2LengthFreelyProgrammableEnable ( CAN_MODULE_ID index );
void PLIB_CAN_PhaseSegment2LengthFreelyProgrammableDisable ( CAN_MODULE_ID index );
void PLIB_CAN_PhaseSegment1LengthSet ( CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length );
void PLIB_CAN_PhaseSegment2LengthSet ( CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length );
void PLIB_CAN_PropagationTimeSegmentSet ( CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length );
void PLIB_CAN_SyncJumpWidthSet ( CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length );
void PLIB_CAN_BaudRatePrescaleSet( CAN_MODULE_ID index, CAN_BAUD_RATE_PRESCALE prescale );
//DOM-IGNORE-END 


// *****************************************************************************
// *****************************************************************************
// Section: CAN Peripheral Library Exists API Routines
// *****************************************************************************
// *****************************************************************************
/* The functions below indicate the existence of the features on the device.
*/

//******************************************************************************
/* Function :  PLIB_CAN_ExistsDeviceNet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the DeviceNet feature exists on the CAN module.

  Description:
    This function identifies whether the DeviceNet feature is available on the 
	CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_DeviceNetConfigure

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The DeviceNet feature is supported on the device
    - false = The DeviceNet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsDeviceNet( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsActiveStatus( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ActiveStatus feature exists on the CAN module.

  Description:
    This function identifies whether the ActiveStatus feature is available on 
	the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_IsActive

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ActiveStatus feature is supported on the device
    - false = The ActiveStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsActiveStatus( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsStopInIdle( CAN_MODULE_ID index )

  Summary:
    Identifies whether the StopInIdle feature exists on the CAN module.

  Description:
    This function identifies whether the StopInIdle feature is available on the 
	CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_StopInIdleEnable
    - PLIB_CAN_StopInIdleDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The StopInIdle feature is supported on the device
    - false = The StopInIdle feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsStopInIdle( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsEnableControl( CAN_MODULE_ID index )

  Summary:
    Identifies whether the EnableControl feature exists on the CAN module.

  Description:
    This function identifies whether the EnableControl feature is available 
	on the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_Enable
    - PLIB_CAN_Disable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The EnableControl feature is supported on the device
    - false = The EnableControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsEnableControl( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsTimeStampEnable( CAN_MODULE_ID index )

  Summary:
    Identifies whether the TimeStampEnable feature exists on the CAN module

  Description:
    This function identifies whether the TimeStampEnable feature is available 
	on the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_TimeStampEnable
    - PLIB_CAN_TimeStampDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The TimeStampEnable feature is supported on the device
    - false = The TimeStampEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsTimeStampEnable( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsTimeStampValue( CAN_MODULE_ID index )

  Summary:
    Identifies whether the TimeStampValue feature exists on the CAN module.

  Description:
    This function identifies whether the TimeStampValue feature is available 
	on the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_TimeStampValueSet
    - PLIB_CAN_TimeStampValueGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The TimeStampValue feature is supported on the device
    - false = The TimeStampValue feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsTimeStampValue( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsBusActivityWakeup( CAN_MODULE_ID index )

  Summary:
    Identifies whether the BusActivityWakeup feature exists on the CAN module.

  Description:
    This function identifies whether the BusActivityWakeup feature is available 
	on the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_BusActivityWakeupEnable
    - PLIB_CAN_BusActivityWakeupDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The BusActivityWakeup feature is supported on the device
    - false = The BusActivityWakeup feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsBusActivityWakeup( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsMemoryBufferAssign( CAN_MODULE_ID index )

  Summary:
    Identifies whether the MemoryBufferAssign feature exists on the CAN module.

  Description:
    This function identifies whether the MemoryBufferAssign feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_MemoryBufferAssign

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The MemoryBufferAssign feature is supported on the device
    - false = The MemoryBufferAssign feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsMemoryBufferAssign( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsOperationModeRead( CAN_MODULE_ID index )

  Summary:
    Identifies whether the OperationModeRead feature exists on the CAN module.

  Description:
    This function identifies whether the OperationModeRead feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_OperationModeGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The OperationModeRead feature is supported on the device
    - false = The OperationModeRead feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsOperationModeRead( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsOperationModeWrite( CAN_MODULE_ID index )

  Summary:
    Identifies whether the OperationModeSet feature exists on the CAN module.

  Description:
    This function identifies whether the OperationModeSet feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_OperationModeSelect

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The OperationModeSet feature is supported on the device
    - false = The OperationModeSet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsOperationModeWrite( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsTimeStampPrescaler( CAN_MODULE_ID index )

  Summary:
    Identifies whether the TimeStampPrescaler feature exists on the CAN module.

  Description:
    This function identifies whether the TimeStampPrescaler feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_TimeStampPrescalerSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The TimeStampPrescaler feature is supported on the device
    - false = The TimeStampPrescaler feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsTimeStampPrescaler( CAN_MODULE_ID index );


//******************************************************************************
/* Function:  PLIB_CAN_ExistsPrecalculatedBitRateSetup( CAN_MODULE_ID index )

  Summary:
    Identifies whether the PrecalculatedBitRateSetup feature exists on the CAN 
    module.

  Description:
    This function identifies whether the PrecalculatedBitRateSetup feature is 
    available on the CAN module.  When this function returns true, this function 
    is supported on the device:
    - PLIB_CAN_PrecalculatedBitRateSetup

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The PrecalculatedBitRateSetup feature is supported on the device.
    - false = The PrecalculatedBitRateSetup feature is not supported on the device.

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsPrecalculatedBitRateSetup( CAN_MODULE_ID index );


//******************************************************************************
/* Function:
    PLIB_CAN_ExistsBitSamplePhaseSet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the BitSamplePhaseSet feature exists on the CAN module.

  Description:
    This function identifies whether the BitSamplePhaseSet feature is available on the
    CAN module.  When this function returns true, this function is supported on 
    the device:
    - PLIB_CAN_BitSamplePhaseSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The BitSamplePhaseSet feature is supported on the device.
    - false = The BitSamplePhaseSet feature is not supported on the device.

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsBitSamplePhaseSet( CAN_MODULE_ID index );


//******************************************************************************

/* Function:
    PLIB_CAN_ExistsBaudRatePrescaleSetup( CAN_MODULE_ID index )

  Summary:
    Identifies whether the BaudRatePrescaleSetup feature exists on the CAN module.

  Description:
    This function identifies whether the BaudRatePrescaleSetup feature is available
    on the CAN module.  When this function returns true, this function is 
    supported on the device:
    - PLIB_CAN_BaudRatePrescaleSetup

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The BaudRatePrescaleSetup feature is supported on the device.
    - false = The BaudRatePrescaleSetup feature is not supported on the device.

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsBaudRatePrescaleSetup( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsBusLine3TimesSampling( CAN_MODULE_ID index )

  Summary:
    Identifies whether the BusLine3TimesSampling feature exists on the CAN module.

  Description:
    This function identifies whether the BusLine3TimesSampling feature is available 
	on the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_BusLine3TimesSamplingEnable
    - PLIB_CAN_BusLine3TimesSamplingDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The BusLine3TimesSampling feature is supported on the device
    - false = The BusLine3TimesSampling feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsBusLine3TimesSampling( CAN_MODULE_ID index );
//******************************************************************************
/* Function:
    PLIB_CAN_ExistsBaudRateGet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the BaudRateGet feature exists on the CAN module.

  Description:
    This function identifies whether the BaudRateGet feature is available on the 
    CAN module.  When this function returns true, this function is supported 
    on the device:
    - PLIB_CAN_BaudRateGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The BaudRateGet feature is supported on the device.
    - false = The BaudRateGet feature is not supported on the device.

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsBaudRateGet( CAN_MODULE_ID index );

//******************************************************************************
/* Function :  PLIB_CAN_ExistsChannelReset( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ChannelReset feature exists on the CAN module.

  Description:
    This function identifies whether the ChannelReset feature is available on 
	the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_ChannelReset
    - PLIB_CAN_ChannelResetIsComplete

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ChannelReset feature is supported on the device
    - false = The ChannelReset feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsChannelReset( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsChannelUpdate( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ChannelUpdate feature exists on the CAN module.

  Description:
    This function identifies whether the ChannelUpdate feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_ChannelUpdate

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ChannelUpdate feature is supported on the device
    - false = The ChannelUpdate feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsChannelUpdate( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsModuleEventEnable( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ModuleEventEnable feature exists on the CAN module.

  Description:
    This function identifies whether the ModuleEventEnable feature is available 
	on the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_ModuleEventEnable
    - PLIB_CAN_ModuleEventDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ModuleEventEnable feature is supported on the device
    - false = The ModuleEventEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsModuleEventEnable( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsModuleEventClear( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ModuleEvents feature exists on the CAN module.

  Description:
    This function identifies whether the ModuleEvents feature is available on 
	the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_ModuleEventClear
    - PLIB_CAN_ModuleEventGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ModuleEvents feature is supported on the device
    - false = The ModuleEvents feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsModuleEventClear( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsChannelEventEnable( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ChannelEventEnable feature exists on the CAN module.

  Description:
    This function identifies whether the ChannelEventEnable feature is available 
	on the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_ChannelEventEnable
    - PLIB_CAN_ChannelEventDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ChannelEventEnable feature is supported on the device
    - false = The ChannelEventEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsChannelEventEnable( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsPendingEventsGet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the PendingEventsGet feature exists on the CAN module.

  Description:
    This function identifies whether the PendingEventsGet feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_PendingEventsGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The PendingEventsGet feature is supported on the device
    - false = The PendingEventsGet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsPendingEventsGet( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsAllChannelEvents( CAN_MODULE_ID index )

  Summary:
    Identifies whether the AllChannelEvents feature exists on the CAN module.

  Description:
    This function identifies whether the AllChannelEvents feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_AllChannelEventsGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The AllChannelEvents feature is supported on the device
    - false = The AllChannelEvents feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsAllChannelEvents( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsAllChannelOverflow( CAN_MODULE_ID index )

  Summary:
    Identifies whether the AllChannelOverflow feature exists on the CAN module.

  Description:
    This function identifies whether the AllChannelOverflow feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_AllChannelOverflowStatusGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The AllChannelOverflow feature is supported on the device
    - false = The AllChannelOverflow feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsAllChannelOverflow( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsChannelEvent( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ChannelEventGet feature exists on the CAN module.

  Description:
    This function identifies whether the ChannelEventGet feature is available on 
	the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_ChannelEventGet
    - PLIB_CAN_ChannelEventClear

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ChannelEventGet feature is supported on the device
    - false = The ChannelEventGet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsChannelEvent( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsChannelForTransmitSet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ChannelForTransmitSet feature exists on the CAN module.

  Description:
    This function identifies whether the ChannelForTransmitSet feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_ChannelForTransmitSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ChannelForTransmitSet feature is supported on the device
    - false = The ChannelForTransmitSet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsChannelForTransmitSet( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsPendingTransmissionsAbort( CAN_MODULE_ID index )

  Summary:
    Identifies whether the PendingTransmissionsAbort feature exists on the CAN module.

  Description:
    This function identifies whether the PendingTransmissionsAbort feature is 
	available on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_PendingTransmissionsAbort

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The PendingTransmissionsAbort feature is supported on the device
    - false = The PendingTransmissionsAbort feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsPendingTransmissionsAbort( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsTransmitChannelFlush( CAN_MODULE_ID index )

  Summary:
    Identifies whether the TransmitChannelFlush feature exists on the CAN module.

  Description:
    This function identifies whether the TransmitChannelFlush feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_TransmitChannelFlush

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The TransmitChannelFlush feature is supported on the device
    - false = The TransmitChannelFlush feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsTransmitChannelFlush( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsTransmitChannelStatus( CAN_MODULE_ID index )

  Summary:
    Identifies whether the TransmitChannelStatus feature exists on the CAN module.

  Description:
    This function identifies whether the TransmitChannelStatus feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_TransmitChannelStatusGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The TransmitChannelStatus feature is supported on the device
    - false = The TransmitChannelStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsTransmitChannelStatus( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsTransmitBufferGet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the TransmitBufferGet feature exists on the CAN module.

  Description:
    This function identifies whether the TransmitBufferGet feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_TransmitBufferGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The TransmitBufferGet feature is supported on the device
    - false = The TransmitBufferGet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsTransmitBufferGet( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsTransmissionIsAborted( CAN_MODULE_ID index )

  Summary:
    Identifies whether the TransmissionAbortStatus feature exists on the CAN module.

  Description:
    This function identifies whether the TransmissionAbortStatus feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_TransmissionIsAborted

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The TransmissionAbortStatus feature is supported on the device
    - false = The TransmissionAbortStatus feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsTransmissionIsAborted( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsReceivedMessageGet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ReceivedMessageGet feature exists on the CAN module.

  Description:
    This function identifies whether the ReceivedMessageGet feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_ReceivedMessageGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ReceivedMessageGet feature is supported on the device
    - false = The ReceivedMessageGet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsReceivedMessageGet( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsChannelForReceiveSet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ChannelForReceiveSet feature exists on the CAN module.

  Description:
    This function identifies whether the ChannelForReceiveSet feature is available 
	on the CAN module.
    When this function returns true, this function is are supported on the device:
    - PLIB_CAN_ChannelForReceiveSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ChannelForReceiveSet feature is supported on the device
    - false = The ChannelForReceiveSet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsChannelForReceiveSet( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsFilterMaskConfigure( CAN_MODULE_ID index )

  Summary:
    Identifies whether the FilterMaskConfigure feature exists on the CAN module.

  Description:
    This function identifies whether the FilterMaskConfigure feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_FilterMaskConfigure

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The FilterMaskConfigure feature is supported on the device
    - false = The FilterMaskConfigure feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsFilterMaskConfigure( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsFilterConfigure( CAN_MODULE_ID index )

  Summary:
    Identifies whether the FilterConfigure feature exists on the CAN module.

  Description:
    This function identifies whether the FilterConfigure feature is available on 
	the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_FilterConfigure

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The FilterConfigure feature is supported on the device
    - false = The FilterConfigure feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsFilterConfigure( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsFilterEnable( CAN_MODULE_ID index )

  Summary:
    Identifies whether the FilterEnable feature exists on the CAN module.

  Description:
    This function identifies whether the FilterEnable feature is available on the 
	CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_FilterEnable
    - PLIB_CAN_FilterDisable
    - PLIB_CAN_FilterIsDisabled

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The FilterEnable feature is supported on the device
    - false = The FilterEnable feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsFilterEnable( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsLatestFilterMatchGet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the LatestFilterMatchGet feature exists on the CAN module.

  Description:
    This function identifies whether the LatestFilterMatchGet feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_LatestFilterMatchGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The LatestFilterMatchGet feature is supported on the device
    - false = The LatestFilterMatchGet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsLatestFilterMatchGet( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsFilterToChannelLink( CAN_MODULE_ID index )

  Summary:
    Identifies whether the FilterToChannelLink feature exists on the CAN module.

  Description:
    This function identifies whether the FilterToChannelLink feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_FilterToChannelLink

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The FilterToChannelLink feature is supported on the device
    - false = The FilterToChannelLink feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsFilterToChannelLink( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsReceiveErrorCount( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ReceiveErrorCount feature exists on the CAN module.

  Description:
    This function identifies whether the ReceiveErrorCount feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_ReceiveErrorCountGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ReceiveErrorCount feature is supported on the device
    - false = The ReceiveErrorCount feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsReceiveErrorCount( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsTransmitErrorCountGet( CAN_MODULE_ID index )

  Summary:
    Identifies whether the TransmitErrorCountGet feature exists on the CAN module.

  Description:
    This function identifies whether the TransmitErrorCountGet feature is available 
	on the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_TransmitErrorCountGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The TransmitErrorCountGet feature is supported on the device
    - false = The TransmitErrorCountGet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsTransmitErrorCountGet( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsErrorState( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ErrorStateGet feature exists on the CAN module.

  Description:
    This function identifies whether the ErrorStateGet feature is available on 
	the CAN module.
    When this function returns true, this function is supported on the device:
    - PLIB_CAN_ErrorStateGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ErrorStateGet feature is supported on the device
    - false = The ErrorStateGet feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsErrorState( CAN_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_CAN_ExistsModuleInfo( CAN_MODULE_ID index )

  Summary:
    Identifies whether the ModuleInformation feature exists on the CAN module.

  Description:
    This function identifies whether the ModuleInformation feature is available 
	on the CAN module.
    When this function returns true, these functions are supported on the device:
    - PLIB_CAN_TotalChannelsGet
    - PLIB_CAN_TotalFiltersGet
    - PLIB_CAN_TotalMasksGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ModuleInformation feature is supported on the device
    - false = The ModuleInformation feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_CAN_ExistsModuleInfo( CAN_MODULE_ID index );

//DOM-IGNORE-BEGIN 
//******************************************************************************
/* The following functions have been deprecated.  Their use is not recommended 
   for the future development.  They are maintained here only for backward 
   compatibility.
*/
bool PLIB_CAN_ExistsPhaseSegment2LengthFreelyProgrammable( CAN_MODULE_ID index );
bool PLIB_CAN_ExistsPhaseSegment1Length( CAN_MODULE_ID index );
bool PLIB_CAN_ExistsPhaseSegment2Length( CAN_MODULE_ID index );
bool PLIB_CAN_ExistsPropagationTimeSegment( CAN_MODULE_ID index );
bool PLIB_CAN_ExistsSyncJumpWidthSet( CAN_MODULE_ID index );
bool PLIB_CAN_ExistsBaudRatePrescale( CAN_MODULE_ID index );
//DOM-IGNORE-END

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif  // _PLIB_CAN_H
/*******************************************************************************
 End of File
*/

