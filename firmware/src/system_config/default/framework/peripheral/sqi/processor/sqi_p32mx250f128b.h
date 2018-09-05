/* Created by plibgen $Revision: 1.31 $ */

#ifndef _SQI_P32MX250F128B_H
#define _SQI_P32MX250F128B_H

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

    SQI_NUMBER_OF_MODULES = 0

} SQI_MODULE_ID;

typedef enum {

    SQI_XFER_MODE_NONE

} SQI_XFER_MODE;

typedef enum {

    SQI_DATA_MODE_NONE

} SQI_DATA_MODE;

typedef enum {

    SQI_DATA_FORMAT_NONE

} SQI_DATA_FORMAT;

typedef enum {

    SQI_DATA_OEN_NONE

} SQI_DATA_OEN;

typedef enum {

    SQI_CS_OEN_NONE

} SQI_CS_OEN;

typedef enum {

    SQI_XFER_CMD_NONE

} SQI_XFER_CMD;

typedef enum {

    SQI_LANE_MODE_NONE

} SQI_LANE_MODE;

typedef enum {

    SQI_CS_NUM_NONE

} SQI_CS_NUM;

typedef enum {

    SQI_CLK_DIV_NONE

} SQI_CLK_DIV;

typedef enum {

    SQI_ADDR_BYTES_NONE

} SQI_ADDR_BYTES;

typedef enum {

    SQI_DUMMY_BYTES_NONE

} SQI_DUMMY_BYTES;

typedef enum {

    SQI_MODE_BYTES_NONE

} SQI_MODE_BYTES;

typedef enum {

    SQI_INTERRUPTS_NONE

} SQI_INTERRUPTS;

typedef enum {

    SQI_BD_STATE_NONE

} SQI_BD_STATE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPSDRCommandDDRDataSet(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_XIPSDRCommandDDRDataGet(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPSDRCommandDDRData(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPDDRModeSet(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPDDRMode(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPDummyBytesSet(SQI_MODULE_ID index, SQI_DUMMY_BYTES bytes)
{
     
}

PLIB_INLINE_API SQI_DUMMY_BYTES _PLIB_UNSUPPORTED PLIB_SQI_XIPDummyBytesGet(SQI_MODULE_ID index)
{
     return (SQI_DUMMY_BYTES)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPNumberOfDummyBytes(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPAddressBytesSet(SQI_MODULE_ID index, SQI_ADDR_BYTES bytes)
{
     
}

PLIB_INLINE_API SQI_ADDR_BYTES _PLIB_UNSUPPORTED PLIB_SQI_XIPAddressBytesGet(SQI_MODULE_ID index)
{
     return (SQI_ADDR_BYTES)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPNumberOfAddressBytes(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPReadOpcodeSet(SQI_MODULE_ID index, uint8_t opCode)
{
     
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_XIPReadOpcodeGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPReadOpCode(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPLaneModeSet(SQI_MODULE_ID index, SQI_LANE_MODE dataLanes, SQI_LANE_MODE dummyLanes, SQI_LANE_MODE modeLanes, SQI_LANE_MODE addrLanes, SQI_LANE_MODE cmdLanes)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPLaneMode(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPControlWord1Set(SQI_MODULE_ID index, SQI_DUMMY_BYTES dummyBytes, SQI_ADDR_BYTES addressBytes, uint8_t readOpcode, SQI_LANE_MODE dataLaneMode, SQI_LANE_MODE dummyLaneMode, SQI_LANE_MODE modeCodeLaneMode, SQI_LANE_MODE addressLaneMode, SQI_LANE_MODE cmdLaneMode)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_SQI_XIPControlWord1Get(SQI_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPControlWord1(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPChipSelectSet(SQI_MODULE_ID index, SQI_CS_NUM csNum)
{
     
}

PLIB_INLINE_API SQI_CS_NUM _PLIB_UNSUPPORTED PLIB_SQI_XIPChipSelectGet(SQI_MODULE_ID index)
{
     return (SQI_CS_NUM)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPChipSelect(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPModeBytesSet(SQI_MODULE_ID index, SQI_MODE_BYTES bytes)
{
     
}

PLIB_INLINE_API SQI_MODE_BYTES _PLIB_UNSUPPORTED PLIB_SQI_XIPModeBytesGet(SQI_MODULE_ID index)
{
     return (SQI_MODE_BYTES)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPModeBytes(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPModeCodeSet(SQI_MODULE_ID index, uint8_t code)
{
     
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_XIPModeCodeGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPModeCode(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPControlWord2Set(SQI_MODULE_ID index, SQI_CS_NUM devSelect, SQI_MODE_BYTES modeBytes, uint8_t modeCode)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_SQI_XIPControlWord2Get(SQI_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPControlWord2(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_Enable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_Disable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsEnableControl(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_CSOutputEnableSelect(SQI_MODULE_ID index, SQI_CS_OEN csPins)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsCSOutputEnable(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DataOutputEnableSelect(SQI_MODULE_ID index, SQI_DATA_OEN dataPins)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDataOutputEnable(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ConBufferSoftReset(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsConBufferSoftReset(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_RxBufferSoftReset(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxBufferSoftReset(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_TxBufferSoftReset(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxBufferSoftReset(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_SoftReset(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsSoftReset(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_BurstEnable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBurstControl(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_HoldSet(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_HoldClear(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_HoldGet(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsHoldPinControl(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_WriteProtectSet(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_WriteProtectClear(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_WriteProtectGet(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsWPPinControl(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ReceiveLatchEnable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ReceiveLatchDisable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_ReceiveLatchGet(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsReceiveLatch(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DataFormatSet(SQI_MODULE_ID index, SQI_DATA_FORMAT dataformat)
{
     
}

PLIB_INLINE_API SQI_DATA_FORMAT _PLIB_UNSUPPORTED PLIB_SQI_DataFormatGet(SQI_MODULE_ID index)
{
     return (SQI_DATA_FORMAT)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDataFormat(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DataModeSet(SQI_MODULE_ID index, SQI_DATA_MODE mode)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDataModeControl(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_TransferModeSet(SQI_MODULE_ID index, SQI_XFER_MODE mode)
{
     
}

PLIB_INLINE_API SQI_XFER_MODE _PLIB_UNSUPPORTED PLIB_SQI_TransferModeGet(SQI_MODULE_ID index)
{
     return (SQI_XFER_MODE)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTransferModeControl(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ConfigWordSet(SQI_MODULE_ID index, bool sqiEnable, SQI_CS_OEN csPins, SQI_DATA_OEN dataPins, bool reset, bool burstEn, bool hold, bool writeProtect, bool rxLatch, SQI_DATA_FORMAT lsbf, SQI_DATA_MODE dataMode, SQI_XFER_MODE xferMode)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_SQI_ConfigWordGet(SQI_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsConfigWord(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_StatusCheckSet(SQI_MODULE_ID index, uint16_t statCheckCmd, uint8_t numStatBytes, SQI_LANE_MODE statCmdType, bool statBitPos)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsStatusCheck(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DDRModeSet(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_DDRModeGet(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DDRModeClear(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDDRMode(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ChipSelectDeassertEnable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ChipSelectDeassertDisable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsCSDeassert(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ChipSelectSet(SQI_MODULE_ID index, SQI_CS_NUM csNum)
{
     
}

PLIB_INLINE_API SQI_CS_NUM _PLIB_UNSUPPORTED PLIB_SQI_ChipSelectGet(SQI_MODULE_ID index)
{
     return (SQI_CS_NUM)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsChipSelect(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_LaneModeSet(SQI_MODULE_ID index, SQI_LANE_MODE mode)
{
     
}

PLIB_INLINE_API SQI_LANE_MODE _PLIB_UNSUPPORTED PLIB_SQI_LaneModeGet(SQI_MODULE_ID index)
{
     return (SQI_LANE_MODE)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsLaneMode(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_TransferDirectionSet(SQI_MODULE_ID index, SQI_XFER_CMD command)
{
     
}

PLIB_INLINE_API SQI_XFER_CMD _PLIB_UNSUPPORTED PLIB_SQI_TransferDirectionGet(SQI_MODULE_ID index)
{
     return (SQI_XFER_CMD)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTransferCommand(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ByteCountSet(SQI_MODULE_ID index, uint16_t xferCount)
{
     
}

PLIB_INLINE_API uint16_t _PLIB_UNSUPPORTED PLIB_SQI_ByteCountGet(SQI_MODULE_ID index)
{
     return (uint16_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTransferCount(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ControlWordSet(SQI_MODULE_ID index, bool csDeassert, SQI_CS_NUM csNum, SQI_LANE_MODE laneMode, SQI_XFER_CMD command, uint16_t xferCount)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_SQI_ControlWordGet(SQI_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsControlWord(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ClockDividerSet(SQI_MODULE_ID index, SQI_CLK_DIV clkDivider)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsClockDivider(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_ClockIsStable(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsClockReady(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ClockEnable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ClockDisable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsClockControl(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_RxBufferThresholdSet(SQI_MODULE_ID index, uint8_t threshold)
{
     
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_RxBufferThresholdGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxBufThreshold(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_TxBufferThresholdSet(SQI_MODULE_ID index, uint8_t threshold)
{
     
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_TxBufferThresholdGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxBufThreshold(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_RxBufferThresholdIntSet(SQI_MODULE_ID index, uint8_t threshold)
{
     
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_RxBufferThresholdIntGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxBufIntThreshold(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_TxBufferThresholdIntSet(SQI_MODULE_ID index, uint8_t threshold)
{
     
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_TxBufferThresholdIntGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxBufIntThreshold(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_InterruptEnable(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_InterruptDisable(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_InterruptDisableAll(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_InterruptIsEnabled(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsInterruptControl(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_InterruptFlagGet(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_SQI_InterruptWordGet(SQI_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_InterruptWordClear(SQI_MODULE_ID index, uint32_t flags)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsInterruptStatus(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_TransmitData(SQI_MODULE_ID index, uint32_t data)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxData(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_SQI_ReceiveData(SQI_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxData(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_TransmitBufferFreeSpaceGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxBufferFree(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_NumberOfReceiveBufferReads(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxBufferCount(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_ConBufWordsAvailable(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsConBufAvailable(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_CommandStatusGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsCommandStatus(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_DataLineStatus(SQI_MODULE_ID index, uint8_t dataPin)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDataPinStatus(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_ReceiveBufferIsUnderrun(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsRxUnderRun(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_TransmitBufferHasOverflowed(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTxOverFlow(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DMAEnable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DMADisable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_DMAIsEnabled(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDmaEnable(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DMABDPollEnable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DMABDPollDisable(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_DMABDPollIsEnabled(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDPollingEnable(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DMABDFetchStart(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DMABDFetchStop(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDMABDFetch(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void* _PLIB_UNSUPPORTED PLIB_SQI_DMABDCurrentAddressGet(SQI_MODULE_ID index)
{
     return (void*)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDCurrentAddress(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DMABDBaseAddressSet(SQI_MODULE_ID index, void* baseBDAddress)
{
     
}

PLIB_INLINE_API void* _PLIB_UNSUPPORTED PLIB_SQI_DMABDBaseAddressGet(SQI_MODULE_ID index)
{
     return (void*)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDBaseAddress(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API SQI_BD_STATE _PLIB_UNSUPPORTED PLIB_SQI_DMABDStateGet(SQI_MODULE_ID index)
{
     return (SQI_BD_STATE)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDProcessState(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_DMAHasStarted(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDMAProcessInProgress(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_DMABDIsBusy(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsDMAEngineBusy(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint16_t _PLIB_UNSUPPORTED PLIB_SQI_DMABDControlWordGet(SQI_MODULE_ID index)
{
     return (uint16_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDControlWord(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_DMABDPollCounterSet(SQI_MODULE_ID index, uint16_t pollCount)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDPollCount(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API SQI_BD_STATE _PLIB_UNSUPPORTED PLIB_SQI_DMABDTransmitStateGet(SQI_MODULE_ID index)
{
     return (SQI_BD_STATE)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDTxState(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_DMABDTransmitBufferCountGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDTxBufCount(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_DMABDTransmitBufferLengthGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDTxLength(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API SQI_BD_STATE _PLIB_UNSUPPORTED PLIB_SQI_DMABDReceiveStateGet(SQI_MODULE_ID index)
{
     return (SQI_BD_STATE)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDRxState(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_DMABDReceiveBufferCountGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDRxBufCount(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_DMABDReceiveBufferLengthGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsBDRxLength(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_ControlBufferThresholdSet(SQI_MODULE_ID index, uint8_t threshold)
{
     
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_SQI_ControlBufferThresholdGet(SQI_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsConBufThreshold(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_InterruptSignalEnable(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_InterruptSignalDisable(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_InterruptSignalDisableAll(SQI_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_SQI_InterruptSignalIsEnabled(SQI_MODULE_ID index, SQI_INTERRUPTS interruptFlag)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsInterruptSignalControl(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_TapDelaySet(SQI_MODULE_ID index, uint8_t sdrClkInDly, uint8_t dataOutDly, uint8_t clkOutDly)
{
     
}

PLIB_INLINE_API bool PLIB_SQI_ExistsTapDelay(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPControlWord3Set(SQI_MODULE_ID index, bool initStatCheck, uint8_t initCmdCount, SQI_LANE_MODE initCmdType, uint8_t initCmd3, uint8_t initCmd2, uint8_t initCmd1)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_SQI_XIPControlWord3Get(SQI_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPControlWord3(SQI_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_SQI_XIPControlWord4Set(SQI_MODULE_ID index, bool initStatCheck, uint8_t initCmdCount, SQI_LANE_MODE initCmdType, uint8_t initCmd3, uint8_t initCmd2, uint8_t initCmd1)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_SQI_XIPControlWord4Get(SQI_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_SQI_ExistsXIPControlWord4(SQI_MODULE_ID index)
{
     return (bool)0;
}

#endif
