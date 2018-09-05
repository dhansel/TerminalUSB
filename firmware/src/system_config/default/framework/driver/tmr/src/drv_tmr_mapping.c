/*******************************************************************************
  Timer Driver Interface Mapping Dynamic APIs to Static APIs           

  Company:
    Microchip Technology Inc.

  File Name:
    drv_tmr_mapping.h

  Summary:
    This file allows maintaining a single set of APIs for all Timer transactions  
    by making the type of implementation transparent to the application. In case
    where static implementation of Timer driver is selected, this file maps the 
    API functions to a particular driver instance-specific static implementation
    function, eliminating unnecessary dynamic parameters. 
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#include "driver/tmr/drv_tmr.h"
#include "driver/tmr/drv_tmr_static.h"

// *****************************************************************************
// *****************************************************************************
// Section: Driver System Interface Function Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ DRV_TMR_Initialize 
    ( 
        const SYS_MODULE_INDEX drvIndex,
        const SYS_MODULE_INIT * const init 
    )

  Summary:
    Initializes the Timer driver.

  Description:
    This function initializes the Timer driver, making it ready for clients to
    open and use it.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

SYS_MODULE_OBJ DRV_TMR_Initialize 
( 
    const SYS_MODULE_INDEX drvIndex,
    const SYS_MODULE_INIT  * const init 
)
{
	SYS_MODULE_OBJ sysObj;
	
	switch (drvIndex)
    {
                case DRV_TMR_INDEX_0:
        {
            DRV_TMR0_Initialize();
			sysObj = (SYS_MODULE_OBJ)DRV_TMR_INDEX_0;
            break;
        }
        default:
        {
			sysObj = SYS_MODULE_OBJ_INVALID;
            break;
        }
    }
	return sysObj;
}

// *****************************************************************************
/* Function:
    void DRV_TMR_Deinitialize ( SYS_MODULE_OBJ object )

  Summary:
    Deinitializes the specified instance of the Timer driver.

  Description:
    Deinitializes the specified instance of the Timer driver, disabling
    its operation (and any hardware). All internal data is invalidated.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

void DRV_TMR_Deinitialize ( SYS_MODULE_OBJ object )
{
	switch (object)
    {
        case DRV_TMR_INDEX_0:
        {
            DRV_TMR0_DeInitialize();
            break;
        }
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
/* Function:
    SYS_STATUS DRV_TMR_Status ( SYS_MODULE_OBJ object )

  Summary:
    Provides the current status of the Timer driver.

  Description:
    This function provides the current status of the Timer driver.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

SYS_STATUS DRV_TMR_Status ( SYS_MODULE_OBJ object )
{
	SYS_STATUS returnValue;
	
	switch (object)
    {
        case DRV_TMR_INDEX_0:
        {
            returnValue = DRV_TMR0_Status();
            break;
        }
        default:
        {
            break;
        }
    }
	return returnValue;
}

// *****************************************************************************
/* Function:
    void DRV_TMR_Tasks ( SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's state machine.

  Description:
    This function is used to maintain the driver's internal state machine and
    processes the timer events.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

void DRV_TMR_Tasks ( SYS_MODULE_OBJ object )
{
	switch (object)
    {
        case DRV_TMR_INDEX_0:
        {
            DRV_TMR0_Tasks();
            break;
        }
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: TMR Driver Client Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    DRV_HANDLE DRV_TMR_Open 
    ( 
        const SYS_MODULE_INDEX index,
        const DRV_IO_INTENT    intent
    )

  Summary:
    Opens the specified Timer driver instance and returns a handle to it.
  
  Description:
    This function opens the specified Timer driver instance and provides a
    handle that must be provided to all other client-level operations to
    identify the caller and the instance of the driver.  Timer driver does not
    support multiple clients. If two tasks want to use the timer, one should
    wait until the other one gets closed. 

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

DRV_HANDLE DRV_TMR_Open 
( 
    const SYS_MODULE_INDEX index, 
    const DRV_IO_INTENT intent 
)
{
    switch (index)
    {
        case DRV_TMR_INDEX_0:
        {
            return (DRV_HANDLE)DRV_TMR_INDEX_0;
            break;
        }
        default:
        {
            break;
        }
    }
    
    return (DRV_HANDLE)NULL;
}

// *****************************************************************************
/* Function:
    void DRV_TMR_Close ( DRV_HANDLE handle )

  Summary:
    Closes an opened instance of the Timer driver.

  Description:
    This function closes an opened instance of the Timer driver, invalidating
    the handle.
  
  Remarks:
    Refer to drv_tmr.h for usage information.
*/

void DRV_TMR_Close ( DRV_HANDLE handle )
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            DRV_TMR0_Close();
            break;
        }
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
/* Function:
    DRV_TMR_CLIENT_STATUS DRV_TMR_ClientStatus ( DRV_HANDLE handle )

  Summary:
    Gets the status of the client operation.

  Description:
    This function gets the status of the recently completed client level
    operation.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

DRV_TMR_CLIENT_STATUS DRV_TMR_ClientStatus 
( DRV_HANDLE handle )
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            return DRV_TMR0_ClientStatus();
            break;
        }
        default:
        {
            break;
        }
    }

    return DRV_TMR_CLIENT_STATUS_INVALID;
}

// *****************************************************************************
// *****************************************************************************
// Section: TMR Driver Counter functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void DRV_TMR_CounterValueSet ( DRV_HANDLE handle, uint32_t counterPeriod )

  Summary:
    Updates the Timer's counter register.

  Description:
    This function updates the Timer's value in the counter register.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

void DRV_TMR_CounterValueSet ( DRV_HANDLE handle, uint32_t counterPeriod )
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            DRV_TMR0_CounterValueSet(counterPeriod);
            break;
        }
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
/* Function:
    uint32_t DRV_TMR_CounterValueGet ( DRV_HANDLE handle )

  Summary:
    Reads the Timer's counter register.

  Description:
    This function returns the Timer's value in the counter register.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

uint32_t DRV_TMR_CounterValueGet ( DRV_HANDLE handle )
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            return DRV_TMR0_CounterValueGet();
            break;
        }
        default:
        {
            break;
        }
    }

    return 0;
}

// *****************************************************************************
/* Function:
    void DRV_TMR_CounterClear ( DRV_HANDLE handle )

  Summary:
    Clears the Timer's counter register.

  Description:
    This function clears the Timer's value in the counter register.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

void DRV_TMR_CounterClear ( DRV_HANDLE handle )
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            DRV_TMR0_CounterClear();
            break;
        }
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: TMR Driver Alarm functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    bool DRV_TMR_AlarmRegister 
    ( 
        DRV_HANDLE handle, 
        uint32_t divider, 
        bool isPeriodic, 
        uintptr_t context, 
        DRV_TMR_CALLBACK callBack 
    )

  Summary:
    Sets up an alarm.

  Description:
    This function sets up an alarm, allowing the client to receive a callback
    from the driver when the timer counter reaches zero.  Alarms can be one-shot
    or periodic.  A periodic alarm will reload the timer and generate alarm
    until stopped.  The alarm frequency is: DRV_TMR_CounterFrequencyGet() /
    divider;

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

bool DRV_TMR_AlarmRegister 
(
    DRV_HANDLE handle, 
    uint32_t divider, 
    bool isPeriodic, 
    uintptr_t context, 
    DRV_TMR_CALLBACK callBack 
)
{
    switch (handle)
    {
        default:
        {
            break;
        }
    }

    return false;
}

// *****************************************************************************
/* Function:
    bool DRV_TMR_AlarmDisable ( DRV_HANDLE handle);

  Summary:
    Disables an alarm signal.

  Description:
    This function allows the client to disable an alarm generation.
    Use DRV_TMR_AlarmEnable to re-enable.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

bool DRV_TMR_AlarmDisable ( DRV_HANDLE handle)
{
    switch (handle)
    {
        default:
        {
            break;
        }
    }

    return false;
}

// *****************************************************************************
/* Function:
    void DRV_TMR_AlarmEnable ( DRV_HANDLE handle, bool enable );

  Summary:
    Re-enables an alarm signal.

  Description:
    This function allows the client to re-enable an alarm after it has been
    disabled by a DRV_TMR_AlarmDisable call.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

void DRV_TMR_AlarmEnable ( DRV_HANDLE handle, bool enable )
{
    switch (handle)
    {
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
/* Function:
    void DRV_TMR_AlarmPeriodSet ( DRV_HANDLE handle, uint32_t value )

  Summary:
    Updates the Timer's period.

  Description:
    This function updates the Timer's period.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

void DRV_TMR_AlarmPeriodSet ( DRV_HANDLE handle, uint32_t value )
{
    switch (handle)
    {
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
/* Function:
    uint32_t DRV_TMR_AlarmPeriodGet ( DRV_HANDLE handle )

  Summary:
    Provides the Timer's period.

  Description:
    This function gets the Timer's period.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

uint32_t DRV_TMR_AlarmPeriodGet ( DRV_HANDLE handle )
{
    switch (handle)
    {
        default:
        {
            break;
        }
    }

    return 0;
}

// *****************************************************************************
/* Function:
    void DRV_TMR_AlarmDeregister ( DRV_HANDLE handle )

  Summary:
    Removes a previously set alarm.

  Description:
    This function removes a previously set alarm.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

void DRV_TMR_AlarmDeregister ( DRV_HANDLE handle )
{
    switch (handle)
    {
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: TMR Driver Operation Control functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    bool DRV_TMR_Start ( DRV_HANDLE handle )

  Summary:
    Starts the Timer counting.

  Description:
    This function starts the Timer counting.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

bool DRV_TMR_Start ( DRV_HANDLE handle )
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            return DRV_TMR0_Start();
            break;
        }
        default:
        {
            break;
        }
    }

    return false;
}

// *****************************************************************************
/* Function:
    void DRV_TMR_Stop ( DRV_HANDLE handle )

  Summary:
    Stops the Timer from counting.

  Description:
    This function stops the running Timer from counting.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

void DRV_TMR_Stop ( DRV_HANDLE handle )
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            DRV_TMR0_Stop();
            break;
        }
        default:
        {
            break;
        }
    }
}

// *****************************************************************************
/* Function:
    uint32_t DRV_TMR_AlarmHasElapsed ( DRV_HANDLE handle )

  Summary:
    Provides the status of Timer's period elapse.

  Description:
    This function returns the number of times Timer's period has elapsed since
    last call to this API has made. On calling this API, the internally
    maintained counter will be cleared and count will be started again from next
    elapse.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

uint32_t DRV_TMR_AlarmHasElapsed ( DRV_HANDLE handle )
{
    switch (handle)
    {
        default:
        {
            break;
        }
    }

    return 0;
}

// *****************************************************************************
/* Function:
    DRV_TMR_OPERATION_MODE DRV_TMR_OperationModeGet(DRV_HANDLE handle)

  Summary:
    This function gets the currently selected operation mode.

  Description:
    This function gets the currently selected 16/32 bit operation mode.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

DRV_TMR_OPERATION_MODE DRV_TMR_OperationModeGet(DRV_HANDLE handle)
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            return DRV_TMR0_OperationModeGet();
            break;
        }
        default:
        {
            break;
        }
    }

    return DRV_TMR_OPERATION_MODE_NONE;
}

// *****************************************************************************
// *****************************************************************************
// Section: TMR Driver Miscellaneous information functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    bool DRV_TMR_ClockSet 
    ( 
        DRV_HANDLE handle, 
        DRV_TMR_CLK_SOURCES clockSource, 
        TMR_PRESCALE  preScale 
    )

  Summary:
    Sets the timers clock by selecting the source and prescaler.

  Description:
    This function sets the timers clock by selecting the source and prescaler.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

bool DRV_TMR_ClockSet 
( 
    DRV_HANDLE handle, 
    DRV_TMR_CLK_SOURCES clockSource, 
    TMR_PRESCALE  preScale 
)
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            return DRV_TMR0_ClockSet(clockSource, preScale);
            break;
        }
        default:
        {
            break;
        }
    }

    return false;
}

// *****************************************************************************
/* Function:
    TMR_PRESCALE DRV_TMR_PrescalerGet ( DRV_HANDLE handle )

  Summary:
    This function gets the currently selected prescaler.

  Description:
    This function gets the currently selected prescaler.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

TMR_PRESCALE DRV_TMR_PrescalerGet ( DRV_HANDLE handle )
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            return DRV_TMR0_PrescalerGet();
            break;
        }
        default:
        {
            break;
        }
    }

    return -1;
}

// *****************************************************************************
/* Function:
    bool DRV_TMR_GateModeSet ( DRV_HANDLE handle )

  Summary:
    Enables the Gate mode.

  Description:
    This function enables the Gated mode of Timer. User can measure the duration
    of an external signal in this mode. Once the Gate mode is enabled, Timer
    will start on the raising edge of the external signal. It will keep counting
    until the next falling edge. 

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

bool DRV_TMR_GateModeSet ( DRV_HANDLE handle )
{
    switch (handle)
    {
        default:
        {
            break;
        }
    }

    return false;
}

// *****************************************************************************
/* Function:
    bool DRV_TMR_GateModeClear ( DRV_HANDLE handle )

  Summary:
    Enables the Gate mode.

  Description:
    This function enables the Gated mode of Timer. User can measure the duration
    of an external signal in this mode. Once the Gate mode is enabled, Timer
    will start on the raising edge of the external signal. It will keep counting
    until the next falling edge. 

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

bool DRV_TMR_GateModeClear ( DRV_HANDLE handle )
{
    switch (handle)
    {
        default:
        {
            break;
        }
    }

    return false;
}

// *****************************************************************************
/* Function:
    uint32_t DRV_TMR_CounterFrequencyGet ( DRV_HANDLE handle )

  Summary:
    Provides the Timer input frequency.

  Description:
    This function provides the Timer input frequency. Input frequency is the
    clock to the Timer register and it is considering the prescaler divisor. 

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

uint32_t DRV_TMR_CounterFrequencyGet ( DRV_HANDLE handle )
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            return DRV_TMR0_CounterFrequencyGet();
            break;
        }
        default:
        {
            break;
        }
    }

    return 0;
}

// *****************************************************************************
/* Function:
    DRV_TMR_OPERATION_MODE DRV_TMR_DividerRangeGet 
    ( 
        DRV_HANDLE handle, 
        DRV_TMR_DIVIDER_RANGE* pDivRange
    )

  Summary:
    Returns the Timer divider values.

  Description:
    This function provides the Timer operating mode and divider range.

  Remarks:
    Refer to drv_tmr.h for usage information.
*/

DRV_TMR_OPERATION_MODE DRV_TMR_DividerRangeGet 
( 
    DRV_HANDLE handle,
    DRV_TMR_DIVIDER_RANGE* pDivRange
)
{
    switch (handle)
    {
        case DRV_TMR_INDEX_0:
        {
            return DRV_TMR0_DividerRangeGet(pDivRange);
            break;
        }
        default:
        {
            break;
        }
    }

    return DRV_TMR_OPERATION_MODE_NONE;
}

