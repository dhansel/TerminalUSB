/* Created by plibgen $Revision: 1.31 $ */

#ifndef _PMP_P32MX250F128B_H
#define _PMP_P32MX250F128B_H

/* Section 1 - Enumerate instances, define constants, VREGs */

#include <xc.h>
#include <stdbool.h>

#include "peripheral/peripheral_common_32bit.h"

/* Default definition used for all API dispatch functions */
#ifndef PLIB_INLINE_API
    #define PLIB_INLINE_API extern inline
#endif

/* Default definition used for all other functions */
#ifndef PLIB_INLINE
    #define PLIB_INLINE extern inline
#endif

typedef enum {

    PMP_ID_0 = 0,
    PMP_NUMBER_OF_MODULES = 1

} PMP_MODULE_ID;

typedef enum {

    PMP_LEGACY_SLAVE = 0x00,
    PMP_ENHANCED_SLAVE = 0x01,
    PMP_MASTER_READ_WRITE_STROBES_INDEPENDENT = 0x2,
    PMP_MASTER_READ_WRITE_STROBES_MULTIPLEXED = 0x3

} PMP_OPERATION_MODE;

typedef enum {

    PMP_MUX_LINES_16_ADDRESS_16_DATA = 0x3,
    PMP_MUX_LINES_16_ADDRESS_8_DATA = 0x2,
    PMP_MUX_LINES_8_ADDRESS_8_DATA = 0x1,
    PMP_MUX_NONE = 0x0

} PMP_MUX_MODE;

typedef enum {

    PMP_BUFFERS_AUTO_INCREMENT = 0x3,
    PMP_ADDRESS_AUTO_DECREMENT = 0x2,
    PMP_ADDRESS_AUTO_INCREMENT = 0x1,
    PMP_ADDRESS_INCREMENT_DECREMENT_DISABLE = 0x0

} PMP_INCREMENT_MODE;

typedef enum {

    PMP_ADDRESS_LATCH_HIGH = 0x2,
    PMP_ADDRESS_LATCH_LOW = 0x1

} PMP_ADDRESS_LATCH;

typedef enum {

    PMP_DATA_WAIT_FOUR = 0x3,
    PMP_DATA_WAIT_THREE = 0x2,
    PMP_DATA_WAIT_TWO = 0x1,
    PMP_DATA_WAIT_ONE = 0x0

} PMP_DATA_WAIT_STATES;

typedef enum {

    PMP_STROBE_WAIT_1 = 0x0,
    PMP_STROBE_WAIT_2 = 0x1,
    PMP_STROBE_WAIT_3 = 0x2,
    PMP_STROBE_WAIT_4 = 0x3,
    PMP_STROBE_WAIT_5 = 0x4,
    PMP_STROBE_WAIT_6 = 0x5,
    PMP_STROBE_WAIT_7 = 0x6,
    PMP_STROBE_WAIT_8 = 0x7,
    PMP_STROBE_WAIT_9 = 0x8,
    PMP_STROBE_WAIT_10 = 0x9,
    PMP_STROBE_WAIT_11 = 0xa,
    PMP_STROBE_WAIT_12 = 0xb,
    PMP_STROBE_WAIT_13 = 0xc,
    PMP_STROBE_WAIT_14 = 0xd,
    PMP_STROBE_WAIT_15 = 0xe,
    PMP_STROBE_WAIT_16 = 0xf

} PMP_STROBE_WAIT_STATES;

typedef enum {

    PMP_DATA_HOLD_1 = 0x0,
    PMP_DATA_HOLD_2 = 0x1,
    PMP_DATA_HOLD_3 = 0x2,
    PMP_DATA_HOLD_4 = 0x3

} PMP_DATA_HOLD_STATES;

typedef enum {

    PMP_INTERRUPT_NONE = 0x0,
    PMP_INTERRUPT_EVERY_RW_CYCLE = 0x1,
    PMP_INTERRUPT_BUFFER_3_IS_ACCESSED = 0x2

} PMP_INTERRUPT_MODE;

typedef enum {

    PMP_DATA_SIZE_8_BITS = 0x0

} PMP_DATA_SIZE;

typedef enum {

    PMP_CHIP_SELECT_ONE = 0x0

} PMP_CHIP_SELECT;

typedef enum {

    PMCS1_AS_CHIP_SELECT = 0x2,
    PMCS1_AS_ADDRESS_LINE = 0x1

} PMP_CHIPSELECT_FUNCTION;

typedef enum {

    PMP_PMA0_PORT = 0x1,
    PMP_PMA1_PORT = 0x2,
    PMP_PMA2_PORT = 0x4,
    PMP_PMA3_PORT = 0x8,
    PMP_PMA4_PORT = 0x10,
    PMP_PMA5_PORT = 0x20,
    PMP_PMA6_PORT = 0x40,
    PMP_PMA7_PORT = 0x80,
    PMP_PMA8_PORT = 0x100,
    PMP_PMA9_PORT = 0x200,
    PMP_PMA10_PORT = 0x400,
    PMP_PMA14_PORT = 0x4000,
    PMP_PMA2_TO_PMA10_PORTS = 0x7FC

} PMP_ADDRESS_PORT;

typedef enum {

    PMP_INPUT_BUFFER_TTL = 0x1,
    PMP_INPUT_BUFFER_SCHMITT = 0x0

} PMP_INPUT_BUFFER_TYPE;

typedef enum {

    PMP_POLARITY_ACTIVE_HIGH = 0x1,
    PMP_POLARITY_ACTIVE_LOW = 0x0

} PMP_POLARITY_LEVEL;

typedef enum {

    PMP_ACK_MODE_NONE

} PMP_ACK_MODE;

typedef enum {

    PMP_ADDRESS_WAIT_HALF = 0xFC

} PMP_ADDRESS_LATCH_WAIT_STATES;

typedef enum {

    PMP_ADDRESS_HOLD_LATCH_WAIT_STATES_NONE

} PMP_ADDRESS_HOLD_LATCH_WAIT_STATES;

typedef enum {

    PMP_PMBE_PORT_NONE

} PMP_PMBE_PORT;

typedef enum {

    PMP_MASTER_MODE_NONE

} PMP_MASTER_MODE;

typedef enum {

    PMP_ALTERNATE_MASTER_WAIT_3_NOT_SUPPORTED = -1,
    PMP_ALTERNATE_MASTER_WAIT_4_NOT_SUPPORTED = -1,
    PMP_ALTERNATE_MASTER_WAIT_5_NOT_SUPPORTED = -1,
    PMP_ALTERNATE_MASTER_WAIT_6_NOT_SUPPORTED = -1,
    PMP_ALTERNATE_MASTER_WAIT_7_NOT_SUPPORTED = -1,
    PMP_ALTERNATE_MASTER_WAIT_8_NOT_SUPPORTED = -1

} PMP_ALTERNATE_MASTER_WAIT_STATES;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/pmp_StartReadControl_Unsupported.h"
#include "../templates/pmp_DualBufferControl_Unsupported.h"
#include "../templates/pmp_EnableControl_Default.h"
#include "../templates/pmp_StopInIdleControl_Default.h"
#include "../templates/pmp_MUXModeSelect_Default.h"
#include "../templates/pmp_BufferType_Default.h"
#include "../templates/pmp_WriteEnablePortControl_Default.h"
#include "../templates/pmp_ReadWriteStrobePortControl_Default.h"
#include "../templates/pmp_ChipSelectoperation_Default.h"
#include "../templates/pmp_AddressLatchPolarity_Default.h"
#include "../templates/pmp_ChipXPolarity_Default.h"
#include "../templates/pmp_WriteEnablePolarity_Basic.h"
#include "../templates/pmp_ReadWritePolarity_Basic.h"
#include "../templates/pmp_BusyStatus_Default.h"
#include "../templates/pmp_InterruptMode_Default.h"
#include "../templates/pmp_IncrementMode_Default.h"
#include "../templates/pmp_DataTransferSize_Unsupported.h"
#include "../templates/pmp_OperationMode_Default.h"
#include "../templates/pmp_DataSetUpWaitStates_Default.h"
#include "../templates/pmp_DataStrobeWaitStates_Default.h"
#include "../templates/pmp_DataHoldWaitStates_Default.h"
#include "../templates/pmp_ChipSelectEnable_Basic.h"
#include "../templates/pmp_WriteChipSelectEnable_Unsupported.h"
#include "../templates/pmp_ReadChipSelectEnable_Unsupported.h"
#include "../templates/pmp_AddressControl_Default.h"
#include "../templates/pmp_DualModeWriteAddressControl_Unsupported.h"
#include "../templates/pmp_DualModeReadAddressControl_Unsupported.h"
#include "../templates/pmp_AddressPortPinControl_Basic.h"
#include "../templates/pmp_AddressLatchStrobePortControl_Default.h"
#include "../templates/pmp_InputBufferFull_Default.h"
#include "../templates/pmp_BufferOverFlow_Default.h"
#include "../templates/pmp_InputBufferXStatus_Default.h"
#include "../templates/pmp_OutPutBufferEmpty_Default.h"
#include "../templates/pmp_BufferUnderFlow_Default.h"
#include "../templates/pmp_OutputBufferXStatus_Default.h"
#include "../templates/pmp_BufferRead_32bit.h"
#include "../templates/pmp_BufferWrite_32bit.h"
#include "../templates/pmp_MasterRXTX_Default.h"
#include "../templates/pmp_DualModeMasterRXTX_Unsupported.h"
#include "../templates/pmp_SlaveTX_Default.h"
#include "../templates/pmp_SlaveRX_Default.h"
#include "../templates/pmp_CSXActiveStatus_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_PMP_ExistsStartReadControl(PMP_MODULE_ID index)
{
     return PMP_ExistsStartReadControl_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_ReadCycleStart(PMP_MODULE_ID index)
{
     PMP_ReadCycleStart_Unsupported(index);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PMP_ReadCycleIsStarted(PMP_MODULE_ID index)
{
     return PMP_ReadCycleIsStarted_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsDualBufferControl(PMP_MODULE_ID index)
{
     return PMP_ExistsDualBufferControl_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_DualBufferDisable(PMP_MODULE_ID index)
{
     PMP_DualBufferDisable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_DualBufferEnable(PMP_MODULE_ID index)
{
     PMP_DualBufferEnable_Unsupported(index);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PMP_DualBufferIsEnabled(PMP_MODULE_ID index)
{
     return PMP_DualBufferIsEnabled_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsEnableControl(PMP_MODULE_ID index)
{
     return PMP_ExistsEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_Disable(PMP_MODULE_ID index)
{
     PMP_Disable_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_Enable(PMP_MODULE_ID index)
{
     PMP_Enable_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_IsEnabled(PMP_MODULE_ID index)
{
     return PMP_IsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsStopInIdleControl(PMP_MODULE_ID index)
{
     return PMP_ExistsStopInIdleControl_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_StopInIdleEnable(PMP_MODULE_ID index)
{
     PMP_StopInIdleEnable_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_StopInIdleDisable(PMP_MODULE_ID index)
{
     PMP_StopInIdleDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsMUXModeSelect(PMP_MODULE_ID index)
{
     return PMP_ExistsMUXModeSelect_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_MultiplexModeSelect(PMP_MODULE_ID index, PMP_MUX_MODE multiplexMode)
{
     PMP_MultiplexModeSelect_Default(index, multiplexMode);
}

PLIB_INLINE_API PMP_MUX_MODE PLIB_PMP_MultiplexModeGet(PMP_MODULE_ID index)
{
     return PMP_MultiplexModeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsBufferType(PMP_MODULE_ID index)
{
     return PMP_ExistsBufferType_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_InputBufferTypeSelect(PMP_MODULE_ID index, PMP_INPUT_BUFFER_TYPE inputBuffer)
{
     PMP_InputBufferTypeSelect_Default(index, inputBuffer);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsWriteEnablePortControl(PMP_MODULE_ID index)
{
     return PMP_ExistsWriteEnablePortControl_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_WriteEnableStrobePortEnable(PMP_MODULE_ID index)
{
     PMP_WriteEnableStrobePortEnable_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_WriteEnableStrobePortDisable(PMP_MODULE_ID index)
{
     PMP_WriteEnableStrobePortDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsReadWriteStrobePortControl(PMP_MODULE_ID index)
{
     return PMP_ExistsReadWriteStrobePortControl_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_ReadWriteStrobePortEnable(PMP_MODULE_ID index)
{
     PMP_ReadWriteStrobePortEnable_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_ReadWriteStrobePortDisable(PMP_MODULE_ID index)
{
     PMP_ReadWriteStrobePortDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsChipSelectoperation(PMP_MODULE_ID index)
{
     return PMP_ExistsChipSelectoperation_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_ChipSelectFunctionSelect(PMP_MODULE_ID index, PMP_CHIPSELECT_FUNCTION chipselfunct)
{
     PMP_ChipSelectFunctionSelect_Default(index, chipselfunct);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsAddressLatchPolarity(PMP_MODULE_ID index)
{
     return PMP_ExistsAddressLatchPolarity_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_AddressLatchPolaritySelect(PMP_MODULE_ID index, PMP_POLARITY_LEVEL polarity)
{
     PMP_AddressLatchPolaritySelect_Default(index, polarity);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsChipXPolarity(PMP_MODULE_ID index)
{
     return PMP_ExistsChipXPolarity_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_ChipSelectXPolaritySelect(PMP_MODULE_ID index, PMP_CHIP_SELECT chipSelect, PMP_POLARITY_LEVEL polarity)
{
     PMP_ChipSelectXPolaritySelect_Default(index, chipSelect, polarity);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsWriteEnablePolarity(PMP_MODULE_ID index)
{
     return PMP_ExistsWriteEnablePolarity_Basic(index);
}

PLIB_INLINE_API void PLIB_PMP_WriteEnableStrobePolaritySelect(PMP_MODULE_ID index, PMP_POLARITY_LEVEL polarity)
{
     PMP_WriteEnableStrobePolaritySelect_Basic(index, polarity);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsReadWritePolarity(PMP_MODULE_ID index)
{
     return PMP_ExistsReadWritePolarity_Basic(index);
}

PLIB_INLINE_API void PLIB_PMP_ReadWriteStrobePolaritySelect(PMP_MODULE_ID index, PMP_POLARITY_LEVEL polarity)
{
     PMP_ReadWriteStrobePolaritySelect_Basic(index, polarity);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsBusyStatus(PMP_MODULE_ID index)
{
     return PMP_ExistsBusyStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_PortIsBusy(PMP_MODULE_ID index)
{
     return PMP_PortIsBusy_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsInterruptMode(PMP_MODULE_ID index)
{
     return PMP_ExistsInterruptMode_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_InterruptModeSelect(PMP_MODULE_ID index, PMP_INTERRUPT_MODE interruptMode)
{
     PMP_InterruptModeSelect_Default(index, interruptMode);
}

PLIB_INLINE_API PMP_INTERRUPT_MODE PLIB_PMP_InterruptModeGet(PMP_MODULE_ID index)
{
     return PMP_InterruptModeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsIncrementMode(PMP_MODULE_ID index)
{
     return PMP_ExistsIncrementMode_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_AddressIncrementModeSelect(PMP_MODULE_ID index, PMP_INCREMENT_MODE incrementMode)
{
     PMP_AddressIncrementModeSelect_Default(index, incrementMode);
}

PLIB_INLINE_API PMP_INCREMENT_MODE PLIB_PMP_AddressIncrementModeGet(PMP_MODULE_ID index)
{
     return PMP_AddressIncrementModeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsDataTransferSize(PMP_MODULE_ID index)
{
     return PMP_ExistsDataTransferSize_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_DataSizeSelect(PMP_MODULE_ID index, PMP_DATA_SIZE size)
{
     PMP_DataSizeSelect_Unsupported(index, size);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsOperationMode(PMP_MODULE_ID index)
{
     return PMP_ExistsOperationMode_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_OperationModeSelect(PMP_MODULE_ID index, PMP_OPERATION_MODE operationMode)
{
     PMP_OperationModeSelect_Default(index, operationMode);
}

PLIB_INLINE_API PMP_OPERATION_MODE PLIB_PMP_OperationModeGet(PMP_MODULE_ID index)
{
     return PMP_OperationModeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsDataSetUpWaitStates(PMP_MODULE_ID index)
{
     return PMP_ExistsDataSetUpWaitStates_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_WaitStatesDataSetUpSelect(PMP_MODULE_ID index, PMP_DATA_WAIT_STATES dataWaitState)
{
     PMP_WaitStatesDataSetUpSelect_Default(index, dataWaitState);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsDataStrobeWaitStates(PMP_MODULE_ID index)
{
     return PMP_ExistsDataStrobeWaitStates_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_WaitStatesStrobeSelect(PMP_MODULE_ID index, PMP_STROBE_WAIT_STATES strobeWaitState)
{
     PMP_WaitStatesStrobeSelect_Default(index, strobeWaitState);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsDataHoldWaitStates(PMP_MODULE_ID index)
{
     return PMP_ExistsDataHoldWaitStates_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_WaitStatesDataHoldSelect(PMP_MODULE_ID index, PMP_DATA_HOLD_STATES dataHoldState)
{
     PMP_WaitStatesDataHoldSelect_Default(index, dataHoldState);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsChipSelectEnable(PMP_MODULE_ID index)
{
     return PMP_ExistsChipSelectEnable_Basic(index);
}

PLIB_INLINE_API void PLIB_PMP_ChipSelectXEnable(PMP_MODULE_ID index, PMP_CHIP_SELECT chipSelect)
{
     PMP_ChipSelectXEnable_Basic(index, chipSelect);
}

PLIB_INLINE_API void PLIB_PMP_ChipSelectXDisable(PMP_MODULE_ID index, PMP_CHIP_SELECT chipSelect)
{
     PMP_ChipSelectXDisable_Basic(index, chipSelect);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsWriteChipSelectEnable(PMP_MODULE_ID index)
{
     return PMP_ExistsWriteChipSelectEnable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_WriteChipSelectXEnable(PMP_MODULE_ID index, PMP_CHIP_SELECT chipSelect)
{
     PMP_WriteChipSelectXEnable_Unsupported(index, chipSelect);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_WriteChipSelectXDisable(PMP_MODULE_ID index, PMP_CHIP_SELECT chipSelect)
{
     PMP_WriteChipSelectXDisable_Unsupported(index, chipSelect);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsReadChipSelectEnable(PMP_MODULE_ID index)
{
     return PMP_ExistsReadChipSelectEnable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_ReadChipSelectXEnable(PMP_MODULE_ID index, PMP_CHIP_SELECT chipSelect)
{
     PMP_ReadChipSelectXEnable_Unsupported(index, chipSelect);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_ReadChipSelectXDisable(PMP_MODULE_ID index, PMP_CHIP_SELECT chipSelect)
{
     PMP_ReadChipSelectXDisable_Unsupported(index, chipSelect);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsAddressControl(PMP_MODULE_ID index)
{
     return PMP_ExistsAddressControl_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_AddressSet(PMP_MODULE_ID index, uint32_t address)
{
     PMP_AddressSet_Default(index, address);
}

PLIB_INLINE_API uint32_t PLIB_PMP_AddressGet(PMP_MODULE_ID index)
{
     return PMP_AddressGet_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_AddressLinesA0A1Set(PMP_MODULE_ID index, uint8_t address)
{
     PMP_AddressLinesA0A1Set_Default(index, address);
}

PLIB_INLINE_API uint8_t PLIB_PMP_AddressLinesA0A1Get(PMP_MODULE_ID index)
{
     return PMP_AddressLinesA0A1Get_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsDualModeWriteAddressControl(PMP_MODULE_ID index)
{
     return PMP_ExistsDualModeWriteAddressControl_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_DualModeWriteAddressSet(PMP_MODULE_ID index, uint32_t writeAddress)
{
     PMP_DualModeWriteAddressSet_Unsupported(index, writeAddress);
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PMP_DualModeWriteAddressGet(PMP_MODULE_ID index)
{
     return PMP_DualModeWriteAddressGet_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsDualModeReadAddressControl(PMP_MODULE_ID index)
{
     return PMP_ExistsDualModeReadAddressControl_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_DualModeReadAddressSet(PMP_MODULE_ID index, uint32_t readAddress)
{
     PMP_DualModeReadAddressSet_Unsupported(index, readAddress);
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PMP_DualModeReadAddressGet(PMP_MODULE_ID index)
{
     return PMP_DualModeReadAddressGet_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsAddressPortPinControl(PMP_MODULE_ID index)
{
     return PMP_ExistsAddressPortPinControl_Basic(index);
}

PLIB_INLINE_API void PLIB_PMP_AddressPortEnable(PMP_MODULE_ID index, PMP_ADDRESS_PORT portfunctions)
{
     PMP_AddressPortEnable_Basic(index, portfunctions);
}

PLIB_INLINE_API void PLIB_PMP_AddressPortDisable(PMP_MODULE_ID index, PMP_ADDRESS_PORT portfunctions)
{
     PMP_AddressPortDisable_Basic(index, portfunctions);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsAddressLatchStrobePortControl(PMP_MODULE_ID index)
{
     return PMP_ExistsAddressLatchStrobePortControl_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_AddressLatchStrobeEnable(PMP_MODULE_ID index, PMP_ADDRESS_LATCH latch)
{
     PMP_AddressLatchStrobeEnable_Default(index, latch);
}

PLIB_INLINE_API void PLIB_PMP_AddressLatchStrobeDisable(PMP_MODULE_ID index, PMP_ADDRESS_LATCH latch)
{
     PMP_AddressLatchStrobeDisable_Default(index, latch);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsInputBufferFull(PMP_MODULE_ID index)
{
     return PMP_ExistsInputBufferFull_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_InputBuffersAreFull(PMP_MODULE_ID index)
{
     return PMP_InputBuffersAreFull_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsBufferOverFlow(PMP_MODULE_ID index)
{
     return PMP_ExistsBufferOverFlow_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_InputOverflowHasOccurred(PMP_MODULE_ID index)
{
     return PMP_InputOverflowHasOccurred_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_InputOverflowClear(PMP_MODULE_ID index)
{
     PMP_InputOverflowClear_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsInputBufferXStatus(PMP_MODULE_ID index)
{
     return PMP_ExistsInputBufferXStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_InputBufferXIsFull(PMP_MODULE_ID index, uint8_t buffer)
{
     return PMP_InputBufferXIsFull_Default(index, buffer);
}

PLIB_INLINE_API bool PLIB_PMP_IsDataReceived(PMP_MODULE_ID index, uint8_t buffer)
{
     return PMP_IsDataReceived_Default(index, buffer);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsOutPutBufferEmpty(PMP_MODULE_ID index)
{
     return PMP_ExistsOutPutBufferEmpty_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_OutputBuffersAreEmpty(PMP_MODULE_ID index)
{
     return PMP_OutputBuffersAreEmpty_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsBufferUnderFlow(PMP_MODULE_ID index)
{
     return PMP_ExistsBufferUnderFlow_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_OutputUnderflowHasOccurred(PMP_MODULE_ID index)
{
     return PMP_OutputUnderflowHasOccurred_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_OutputUnderflowClear(PMP_MODULE_ID index)
{
     PMP_OutputUnderflowClear_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsOutputBufferXStatus(PMP_MODULE_ID index)
{
     return PMP_ExistsOutputBufferXStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_OutputBufferXIsEmpty(PMP_MODULE_ID index, uint8_t buffer)
{
     return PMP_OutputBufferXIsEmpty_Default(index, buffer);
}

PLIB_INLINE_API bool PLIB_PMP_IsDataTransmitted(PMP_MODULE_ID index, uint8_t buffer)
{
     return PMP_IsDataTransmitted_Default(index, buffer);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsBufferRead(PMP_MODULE_ID index)
{
     return PMP_ExistsBufferRead_32bit(index);
}

PLIB_INLINE_API uint8_t PLIB_PMP_InputBufferXByteReceive(PMP_MODULE_ID index, uint8_t buffer)
{
     return PMP_InputBufferXByteReceive_32bit(index, buffer);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsBufferWrite(PMP_MODULE_ID index)
{
     return PMP_ExistsBufferWrite_32bit(index);
}

PLIB_INLINE_API void PLIB_PMP_OutputBufferXByteSend(PMP_MODULE_ID index, uint8_t buffer, uint8_t data)
{
     PMP_OutputBufferXByteSend_32bit(index, buffer, data);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsMasterRXTX(PMP_MODULE_ID index)
{
     return PMP_ExistsMasterRXTX_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_MasterSend(PMP_MODULE_ID index, uint16_t data)
{
     PMP_MasterSend_Default(index, data);
}

PLIB_INLINE_API uint16_t PLIB_PMP_MasterReceive(PMP_MODULE_ID index)
{
     return PMP_MasterReceive_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsDualModeMasterRXTX(PMP_MODULE_ID index)
{
     return PMP_ExistsDualModeMasterRXTX_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PMP_DualModeMasterSend(PMP_MODULE_ID index, uint16_t data)
{
     PMP_DualModeMasterSend_Unsupported(index, data);
}

PLIB_INLINE_API uint16_t _PLIB_UNSUPPORTED PLIB_PMP_DualModeMasterReceive(PMP_MODULE_ID index)
{
     return PMP_DualModeMasterReceive_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsSlaveTX(PMP_MODULE_ID index)
{
     return PMP_ExistsSlaveTX_Default(index);
}

PLIB_INLINE_API void PLIB_PMP_SlaveSend(PMP_MODULE_ID index, uint16_t data)
{
     PMP_SlaveSend_Default(index, data);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsSlaveRX(PMP_MODULE_ID index)
{
     return PMP_ExistsSlaveRX_Default(index);
}

PLIB_INLINE_API uint16_t PLIB_PMP_SlaveReceive(PMP_MODULE_ID index)
{
     return PMP_SlaveReceive_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ExistsCSXActiveStatus(PMP_MODULE_ID index)
{
     return PMP_ExistsCSXActiveStatus_Default(index);
}

PLIB_INLINE_API bool PLIB_PMP_ChipSelectXIsActive(PMP_MODULE_ID index, PMP_CHIP_SELECT chipSelect)
{
     return PMP_ChipSelectXIsActive_Default(index, chipSelect);
}

#endif
