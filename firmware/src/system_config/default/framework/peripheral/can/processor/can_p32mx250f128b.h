/* Created by plibgen $Revision: 1.31 $ */

#ifndef _CAN_P32MX250F128B_H
#define _CAN_P32MX250F128B_H

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

    CAN_NUMBER_OF_MODULES = 0

} CAN_MODULE_ID;

typedef enum {

    CAN_CHANNEL_NONE

} CAN_CHANNEL;

typedef enum {

    CAN_OPERATION_MODES_NONE

} CAN_OPERATION_MODES;

typedef enum {

    CAN_CHANNEL_EVENT_NONE

} CAN_CHANNEL_EVENT;

typedef enum {

    CAN_BAUD_RATE_PRESCALE_NONE

} CAN_BAUD_RATE_PRESCALE;

typedef enum {

    CAN_TIME_SEGMENT_LENGTH_NONE

} CAN_TIME_SEGMENT_LENGTH;

typedef enum {

    CAN_EVENT_CODE_NONE

} CAN_EVENT_CODE;

typedef enum {

    CAN_FILTER_NONE

} CAN_FILTER;

typedef enum {

    CAN_FILTER_MASK_NONE

} CAN_FILTER_MASK;

typedef enum {

    CAN_TX_RTR_NONE

} CAN_TX_RTR;

typedef enum {

    CAN_RX_DATA_MODE_NONE

} CAN_RX_DATA_MODE;

typedef enum {

    CAN_FILTER_MASK_TYPE_NONE

} CAN_FILTER_MASK_TYPE;

typedef enum {

    CAN_TXCHANNEL_PRIORITY_NONE

} CAN_TXCHANNEL_PRIORITY;

typedef enum {

    CAN_DNET_FILTER_SIZE_NONE

} CAN_DNET_FILTER_SIZE;

typedef enum {

    CAN_MODULE_EVENT_NONE

} CAN_MODULE_EVENT;

typedef enum {

    CAN_ERROR_STATE_NONE

} CAN_ERROR_STATE;

typedef enum {

    CAN_ID_TYPE_NONE

} CAN_ID_TYPE;

typedef enum {

    CAN_CHANNEL_MASK_NONE

} CAN_CHANNEL_MASK;

typedef enum {

    CAN_TX_CHANNEL_STATUS_NONE

} CAN_TX_CHANNEL_STATUS;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_DeviceNetConfigure(CAN_MODULE_ID index, CAN_DNET_FILTER_SIZE dncnt)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsDeviceNet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_CAN_IsActive(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsActiveStatus(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_StopInIdleEnable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_StopInIdleDisable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsStopInIdle(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_Enable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_Disable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsEnableControl(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_TimeStampEnable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_TimeStampDisable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTimeStampEnable(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_TimeStampValueSet(CAN_MODULE_ID index, unsigned value)
{
     
}

PLIB_INLINE_API unsigned _PLIB_UNSUPPORTED PLIB_CAN_TimeStampValueGet(CAN_MODULE_ID index)
{
     return (unsigned)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTimeStampValue(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_BusActivityWakeupEnable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_BusActivityWakeupDisable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBusActivityWakeup(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_MemoryBufferAssign(CAN_MODULE_ID index, void* buffer)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsMemoryBufferAssign(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_OPERATION_MODES _PLIB_UNSUPPORTED PLIB_CAN_OperationModeGet(CAN_MODULE_ID index)
{
     return (CAN_OPERATION_MODES)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsOperationModeRead(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_OperationModeSelect(CAN_MODULE_ID index, CAN_OPERATION_MODES opMode)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsOperationModeWrite(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_TimeStampPrescalerSet(CAN_MODULE_ID index, unsigned preScaler)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTimeStampPrescaler(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_PhaseSegment2LengthSet(CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPhaseSegment2Length(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_PhaseSegment1LengthSet(CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPhaseSegment1Length(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_PhaseSegment2LengthFreelyProgrammableEnable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_PhaseSegment2LengthFreelyProgrammableDisable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPhaseSegment2LengthFreelyProgrammable(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_BusLine3TimesSamplingEnable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_BusLine3TimesSamplingDisable(CAN_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBusLine3TimesSampling(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_PropagationTimeSegmentSet(CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPropagationTimeSegment(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_SyncJumpWidthSet(CAN_MODULE_ID index, CAN_TIME_SEGMENT_LENGTH length)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsSyncJumpWidthSet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_BaudRatePrescaleSet(CAN_MODULE_ID index, CAN_BAUD_RATE_PRESCALE prescale)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBaudRatePrescale(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_CAN_PrecalculatedBitRateSetup(CAN_MODULE_ID index, uint8_t prescale, uint8_t syncjumpWidth, uint8_t propagation, uint8_t segment1, uint8_t segment2)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPrecalculatedBitRateSetup(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_CAN_BitSamplePhaseSet(CAN_MODULE_ID index, uint8_t syncJumpWidth, uint8_t propagation, uint8_t segment1, uint8_t segment2)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBitSamplePhaseSet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_CAN_BaudRatePrescaleSetup(CAN_MODULE_ID index, uint16_t prescale)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBaudRatePrescaleSetup(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_CAN_BaudRateGet(CAN_MODULE_ID index, uint32_t sysclock)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsBaudRateGet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ChannelReset(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_CAN_ChannelResetIsComplete(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelReset(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ChannelUpdate(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelUpdate(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ModuleEventEnable(CAN_MODULE_ID index, CAN_MODULE_EVENT flags)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ModuleEventDisable(CAN_MODULE_ID index, CAN_MODULE_EVENT flags)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsModuleEventEnable(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ModuleEventClear(CAN_MODULE_ID index, CAN_MODULE_EVENT flags)
{
     
}

PLIB_INLINE_API CAN_MODULE_EVENT _PLIB_UNSUPPORTED PLIB_CAN_ModuleEventGet(CAN_MODULE_ID index)
{
     return (CAN_MODULE_EVENT)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsModuleEventClear(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ChannelEventEnable(CAN_MODULE_ID index, CAN_CHANNEL channel, CAN_CHANNEL_EVENT flags)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ChannelEventDisable(CAN_MODULE_ID index, CAN_CHANNEL channel, CAN_CHANNEL_EVENT flags)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelEventEnable(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_EVENT_CODE _PLIB_UNSUPPORTED PLIB_CAN_PendingEventsGet(CAN_MODULE_ID index)
{
     return (CAN_EVENT_CODE)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPendingEventsGet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_CHANNEL_MASK _PLIB_UNSUPPORTED PLIB_CAN_AllChannelEventsGet(CAN_MODULE_ID index)
{
     return (CAN_CHANNEL_MASK)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsAllChannelEvents(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_CHANNEL_MASK _PLIB_UNSUPPORTED PLIB_CAN_AllChannelOverflowStatusGet(CAN_MODULE_ID index)
{
     return (CAN_CHANNEL_MASK)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsAllChannelOverflow(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_CHANNEL_EVENT _PLIB_UNSUPPORTED PLIB_CAN_ChannelEventGet(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return (CAN_CHANNEL_EVENT)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ChannelEventClear(CAN_MODULE_ID index, CAN_CHANNEL channel, CAN_CHANNEL_EVENT events)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelEvent(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ChannelForTransmitSet(CAN_MODULE_ID index, CAN_CHANNEL channel, uint8_t channelSize, CAN_TX_RTR rtren, CAN_TXCHANNEL_PRIORITY priority)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelForTransmitSet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_PendingTransmissionsAbort(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsPendingTransmissionsAbort(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_TransmitChannelFlush(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmitChannelFlush(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_TX_CHANNEL_STATUS _PLIB_UNSUPPORTED PLIB_CAN_TransmitChannelStatusGet(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return (CAN_TX_CHANNEL_STATUS)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmitChannelStatus(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_TX_MSG_BUFFER* _PLIB_UNSUPPORTED PLIB_CAN_TransmitBufferGet(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return (CAN_TX_MSG_BUFFER*)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmitBufferGet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_CAN_TransmissionIsAborted(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmissionIsAborted(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_RX_MSG_BUFFER* _PLIB_UNSUPPORTED PLIB_CAN_ReceivedMessageGet(CAN_MODULE_ID index, CAN_CHANNEL channel)
{
     return (CAN_RX_MSG_BUFFER*)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsReceivedMessageGet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_ChannelForReceiveSet(CAN_MODULE_ID index, CAN_CHANNEL channel, uint32_t channelSize, CAN_RX_DATA_MODE dataOnly)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsChannelForReceiveSet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_FilterMaskConfigure(CAN_MODULE_ID index, CAN_FILTER_MASK mask, uint32_t maskBits, CAN_ID_TYPE idType, CAN_FILTER_MASK_TYPE mide)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsFilterMaskConfigure(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_FilterConfigure(CAN_MODULE_ID index, CAN_FILTER filter, uint32_t id, CAN_ID_TYPE filterType)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsFilterConfigure(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_FilterEnable(CAN_MODULE_ID index, CAN_FILTER filter)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_FilterDisable(CAN_MODULE_ID index, CAN_FILTER filter)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_CAN_FilterIsDisabled(CAN_MODULE_ID index, CAN_FILTER filter)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsFilterEnable(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_FILTER _PLIB_UNSUPPORTED PLIB_CAN_LatestFilterMatchGet(CAN_MODULE_ID index)
{
     return (CAN_FILTER)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsLatestFilterMatchGet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CAN_FilterToChannelLink(CAN_MODULE_ID index, CAN_FILTER filter, CAN_FILTER_MASK mask, CAN_CHANNEL channel)
{
     
}

PLIB_INLINE_API bool PLIB_CAN_ExistsFilterToChannelLink(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API int _PLIB_UNSUPPORTED PLIB_CAN_ReceiveErrorCountGet(CAN_MODULE_ID index)
{
     return (int)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsReceiveErrorCount(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API int _PLIB_UNSUPPORTED PLIB_CAN_TransmitErrorCountGet(CAN_MODULE_ID index)
{
     return (int)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsTransmitErrorCountGet(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API CAN_ERROR_STATE _PLIB_UNSUPPORTED PLIB_CAN_ErrorStateGet(CAN_MODULE_ID index)
{
     return (CAN_ERROR_STATE)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsErrorState(CAN_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API char _PLIB_UNSUPPORTED PLIB_CAN_TotalChannelsGet(CAN_MODULE_ID index)
{
     return (char)0;
}

PLIB_INLINE_API char _PLIB_UNSUPPORTED PLIB_CAN_TotalFiltersGet(CAN_MODULE_ID index)
{
     return (char)0;
}

PLIB_INLINE_API char _PLIB_UNSUPPORTED PLIB_CAN_TotalMasksGet(CAN_MODULE_ID index)
{
     return (char)0;
}

PLIB_INLINE_API bool PLIB_CAN_ExistsModuleInfo(CAN_MODULE_ID index)
{
     return (bool)0;
}

#endif
