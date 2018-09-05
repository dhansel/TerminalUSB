/*******************************************************************************
  Timer Static Driver File

  File Name:
    drv_tmr_static.c

  Company:
    Microchip Technology Inc.   

  Summary:
    Timer driver implementation for the static single instance driver.

  Description:
    The Timer device driver provides a simple interface to manage the Timer
    modules on Microchip microcontrollers.
    
  Remarks:
    None
 *******************************************************************************/

/*******************************************************************************
Copyright (c) 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublTMRense terms in the accompanying lTMRense agreement).

You should refer to the lTMRense agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTTMRULAR PURPOSE.
IN NO EVENT SHALL MTMRROCHIP OR ITS LTMRENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRTMRT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVTMRES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Header Includes
// *****************************************************************************
// *****************************************************************************
#include "driver/tmr/drv_tmr_static.h"
#include "driver/tmr/src/drv_tmr_variant_mapping.h"

typedef struct
{
    DRV_TMR_CALLBACK alarmFunc;  // For alarm registering
    uint32_t alarmCount;    // For AlarmHasElapsed function
    bool    alarmEnabled;   // For Enable/Disable function
    bool    alarmPeriodic;      // Keep Alarm enabled or disable it
    uintptr_t   alarmContext;   // For Alarm Callback
    uint32_t    alarmPeriod;    // For Period Set/Get
} DRV_TMR_ALARM_OBJ;

static bool _DRV_TMR_ClockSourceSet(TMR_MODULE_ID timerId, DRV_TMR_CLK_SOURCES clockSource)
{
    bool clockSet = true;
    /* Clock Source Selection */
    if(clockSource == DRV_TMR_CLKSOURCE_INTERNAL)
    {
        if ( PLIB_TMR_ExistsClockSource ( timerId ) )
        {               
            PLIB_TMR_ClockSourceSelect ( timerId, TMR_CLOCK_SOURCE_PERIPHERAL_CLOCK );           
        }
        else
        {
            /* If clock source feature doesn't exist for any specific timer module instance,
            then by default internal peripheral clock is considered as timer source, so do nothing */ 
        }
    }
    /* External Synchronous Clock Source Selection */
    else if(!(clockSource & 0x10))
    {
        if ( PLIB_TMR_ExistsClockSource ( timerId ) )
        {               
            if ( PLIB_TMR_ExistsClockSourceSync ( timerId )  )
            {
                PLIB_TMR_ClockSourceSelect ( timerId, (TMR_CLOCK_SOURCE)(clockSource & 0x0F) );                
                PLIB_TMR_ClockSourceExternalSyncEnable ( timerId );                    
            }
            /* If Synchronization feature doesn't exist for any specific timer module 
            instance with external clock source then it is synchronous by default */
            else if (clockSource == DRV_TMR_CLKSOURCE_EXTERNAL_SYNCHRONOUS)
            {
                PLIB_TMR_ClockSourceSelect ( timerId, TMR_CLOCK_SOURCE_EXTERNAL_INPUT_PIN );
            }
            else
            {
                clockSet = false;
            }  
        }
        else
        {
            clockSet = false;
        }        
    }
    /* External Asynchronous Clock Source Selection */
    else if(clockSource & 0x10)
    {
        if ( PLIB_TMR_ExistsClockSourceSync ( timerId ) )
        {
            PLIB_TMR_ClockSourceSelect ( timerId, (TMR_CLOCK_SOURCE)(clockSource & 0x0F) );
            PLIB_TMR_ClockSourceExternalSyncDisable ( timerId );
        }
        else
        {
            clockSet = false;
        }        
    }
    
    return clockSet;
}

// Prescaler selection
static bool _DRV_TMR_ClockPrescaleSet(TMR_MODULE_ID timerId, TMR_PRESCALE  prescale)
{
    if( PLIB_TMR_ExistsPrescale( timerId ) )
    {
        PLIB_TMR_PrescaleSelect( timerId , prescale );
        return true;
    }
    return false;
}


// *****************************************************************************
// *****************************************************************************
// Section: Instance 0 static driver data
// *****************************************************************************
// *****************************************************************************

static bool                   DRV_TMR0_Running;

// *****************************************************************************
// *****************************************************************************
// Section: Instance 0 static driver functions
// *****************************************************************************
// *****************************************************************************
void DRV_TMR0_Initialize(void)
{   
    /* Initialize Timer Instance0 */
    /* Disable Timer */
    PLIB_TMR_Stop(TMR_ID_1);
    /* Select clock source */
    PLIB_TMR_ClockSourceSelect ( TMR_ID_1, TMR_CLOCK_SOURCE_PERIPHERAL_CLOCK );
    /* Select prescalar value */
    PLIB_TMR_PrescaleSelect(TMR_ID_1, TMR_PRESCALE_VALUE_256);
    /* Enable 16 bit mode */
    PLIB_TMR_Mode16BitEnable(TMR_ID_1);
    /* Clear counter */ 
    PLIB_TMR_Counter16BitClear(TMR_ID_1);
    /*Set period */ 
    PLIB_TMR_Period16BitSet(TMR_ID_1, 0);
    /* Setup Interrupt */   
    PLIB_INT_VectorPrioritySet(INT_ID_0, INT_VECTOR_T1, INT_PRIORITY_LEVEL1);
    PLIB_INT_VectorSubPrioritySet(INT_ID_0, INT_VECTOR_T1, INT_SUBPRIORITY_LEVEL0);          
}

static void _DRV_TMR0_Resume(bool resume)
{
    if (resume)
    {
        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_TIMER_1);
        PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_TIMER_1);
        PLIB_TMR_Start(TMR_ID_1);
    }
}

bool DRV_TMR0_Start(void)
{
    /* Start Timer*/
    _DRV_TMR0_Resume(true);
    DRV_TMR0_Running = true;
    
    return true;
}

static bool _DRV_TMR0_Suspend(void)
{
    if (DRV_TMR0_Running)
    {
        PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_TIMER_1);
        PLIB_TMR_Stop(TMR_ID_1);
        return (true);
    }
    
    return (false);
}

void DRV_TMR0_Stop(void)
{
    _DRV_TMR0_Suspend();
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_TIMER_1);
    DRV_TMR0_Running = false;
}

DRV_TMR_CLIENT_STATUS DRV_TMR0_ClientStatus ( void )
{
    if (DRV_TMR0_Running)
        return DRV_TMR_CLIENT_STATUS_RUNNING;
    else
        return DRV_TMR_CLIENT_STATUS_READY;
}

void DRV_TMR0_CounterValueSet(uint32_t value)
{
    /* Set 16-bit counter value*/
    PLIB_TMR_Counter16BitSet(TMR_ID_1, (uint16_t)value);
}

uint32_t DRV_TMR0_CounterValueGet(void)
{
    /* Get 16-bit counter value*/
    return (uint32_t) PLIB_TMR_Counter16BitGet(TMR_ID_1);
}

void DRV_TMR0_CounterClear(void)
{
    /* Clear 16-bit counter value*/
    PLIB_TMR_Counter16BitClear(TMR_ID_1);
}

DRV_TMR_OPERATION_MODE DRV_TMR0_DividerRangeGet
(
	DRV_TMR_DIVIDER_RANGE * pDivRange
)
{
	if(pDivRange)
	{
        pDivRange->dividerMax = DRV_TIMER_DIVIDER_MAX_16BIT;
        pDivRange->dividerMin = DRV_TIMER_DIVIDER_MIN_16BIT;
		pDivRange->dividerStep = 1;
		return DRV_TMR_OPERATION_MODE_16_BIT;
	}
	return DRV_TMR_OPERATION_MODE_NONE;
}

uint32_t DRV_TMR0_CounterFrequencyGet(void)
{
    uint32_t prescale, tmrBaseFreq;
    
    tmrBaseFreq = SYS_CLK_PeripheralFrequencyGet ( CLK_BUS_FOR_TIMER_PERIPHERAL );
    prescale = PLIB_TMR_PrescaleGet(TMR_ID_1);
    return ( tmrBaseFreq / prescale );
}

TMR_PRESCALE DRV_TMR0_PrescalerGet(void)
{
    uint16_t prescale_value;
    /* Call the PLIB directly */
    prescale_value = PLIB_TMR_PrescaleGet(TMR_ID_1);
    
    switch(prescale_value)
    {
        case 1: return TMR_PRESCALE_VALUE_1;
        case 2: return TMR_PRESCALE_VALUE_2;
        case 4: return TMR_PRESCALE_VALUE_4;
        case 8: return TMR_PRESCALE_VALUE_8;
        case 16: return TMR_PRESCALE_VALUE_16;
        case 32: return TMR_PRESCALE_VALUE_32;
        case 64: return TMR_PRESCALE_VALUE_64;
        case 256: return TMR_PRESCALE_VALUE_256;
        default: return TMR_PRESCALE_VALUE_1;
    }
}

void DRV_TMR0_PeriodValueSet(uint32_t value)
{
    /* Set 16-bit counter value*/
    PLIB_TMR_Period16BitSet(TMR_ID_1, (uint16_t)value);
}

uint32_t DRV_TMR0_PeriodValueGet(void)
{
    /* Get 16-bit counter value*/
    return (uint32_t) PLIB_TMR_Period16BitGet(TMR_ID_1);
}

void DRV_TMR0_StopInIdleDisable(void)
{
    PLIB_TMR_StopInIdleDisable(TMR_ID_1);
}

void DRV_TMR0_StopInIdleEnable(void)
{
    PLIB_TMR_StopInIdleDisable(TMR_ID_1);
}

bool DRV_TMR0_ClockSet
(
    DRV_TMR_CLK_SOURCES clockSource,
    TMR_PRESCALE        preScale
)
{
    bool success = false;
    bool resume = _DRV_TMR0_Suspend();
    
    if (_DRV_TMR_ClockSourceSet(TMR_ID_1, clockSource) &&
        _DRV_TMR_ClockPrescaleSet(TMR_ID_1, preScale))
    {
        success = true;
    }
    
    _DRV_TMR0_Resume(resume);
    return success;
}

 
 
/*******************************************************************************
 End of File
*/
