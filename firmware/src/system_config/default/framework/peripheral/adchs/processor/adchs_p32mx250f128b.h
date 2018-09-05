/* Created by plibgen $Revision: 1.31 $ */

#ifndef _ADCHS_P32MX250F128B_H
#define _ADCHS_P32MX250F128B_H

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

    ADCHS_NUMBER_OF_MODULES = 0

} ADCHS_MODULE_ID;

typedef enum {

    ADCHS_AN_INPUT_ID_NONE

} ADCHS_AN_INPUT_ID;

typedef enum {

    ADCHS_CLASS12_AN_INPUT_ID_NONE

} ADCHS_CLASS12_AN_INPUT_ID;

typedef enum {

    ADCHS_CLASS2_AN_INPUT_ID_NONE

} ADCHS_CLASS2_AN_INPUT_ID;

typedef enum {

    ADCHS_INTERRUPT_BIT_SHIFT_LEFT_NONE

} ADCHS_INTERRUPT_BIT_SHIFT_LEFT;

typedef enum {

    ADCHS_DATA_RESOLUTION_NONE

} ADCHS_DATA_RESOLUTION;

typedef enum {

    ADCHS_SCAN_TRIGGER_SOURCE_NONE

} ADCHS_SCAN_TRIGGER_SOURCE;

typedef enum {

    ADCHS_CHARGEPUMP_MODE_NONE

} ADCHS_CHARGEPUMP_MODE;

typedef enum {

    ADCHS_FAST_SYNC_SYSTEM_CLOCK_NONE

} ADCHS_FAST_SYNC_SYSTEM_CLOCK;

typedef enum {

    ADCHS_FAST_SYNC_PERIPHERAL_CLOCK_NONE

} ADCHS_FAST_SYNC_PERIPHERAL_CLOCK;

typedef enum {

    ADCHS_OUTPUT_DATA_FORMAT_NONE

} ADCHS_OUTPUT_DATA_FORMAT;

typedef enum {

    ADCHS_DMA_BUFFER_LENGTH_NONE

} ADCHS_DMA_BUFFER_LENGTH;

typedef enum {

    ADCHS_DMA_GLOBAL_NONE

} ADCHS_DMA_GLOBAL;

typedef enum {

    ADCHS_DMA_BUFFER_FULL_INTERRUPT_NONE

} ADCHS_DMA_BUFFER_FULL_INTERRUPT;

typedef enum {

    ADCHS_DMA_COUNT_NONE

} ADCHS_DMA_COUNT;

typedef enum {

    ADCHS_CVD_CAPACITOR_NONE

} ADCHS_CVD_CAPACITOR;

typedef enum {

    ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK_NONE

} ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK;

typedef enum {

    ADCHS_CLOCK_SOURCE_NONE

} ADCHS_CLOCK_SOURCE;

typedef enum {

    ADCHS_VREF_SOURCE_NONE

} ADCHS_VREF_SOURCE;

typedef enum {

    ADCHS_CHANNEL_ID_NONE

} ADCHS_CHANNEL_ID;

typedef enum {

    ADCHS_CHANNEL_INP_SEL_NONE

} ADCHS_CHANNEL_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_0_INP_SEL_NONE

} ADCHS_CHANNEL_0_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_1_INP_SEL_NONE

} ADCHS_CHANNEL_1_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_2_INP_SEL_NONE

} ADCHS_CHANNEL_2_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_3_INP_SEL_NONE

} ADCHS_CHANNEL_3_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_4_INP_SEL_NONE

} ADCHS_CHANNEL_4_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_5_INP_SEL_NONE

} ADCHS_CHANNEL_5_INP_SEL;

typedef enum {

    ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL_NONE

} ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL;

typedef enum {

    ADCHS_INPUT_MODE_NONE

} ADCHS_INPUT_MODE;

typedef enum {

    ADCHS_DIGITAL_COMPARATOR_ID_NONE

} ADCHS_DIGITAL_COMPARATOR_ID;

typedef enum {

    ADCHS_DIGITAL_FILTER_ID_NONE

} ADCHS_DIGITAL_FILTER_ID;

typedef enum {

    ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO_NONE

} ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO;

typedef enum {

    ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT_NONE

} ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT;

typedef enum {

    ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS_NONE

} ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS;

typedef enum {

    ADCHS_SCAN_TRIGGER_SENSITIVE_NONE

} ADCHS_SCAN_TRIGGER_SENSITIVE;

typedef enum {

    ADCHS_WARMUP_CLOCK_NONE

} ADCHS_WARMUP_CLOCK;

typedef enum {

    ADCHS_TRIGGER_SOURCE_NONE

} ADCHS_TRIGGER_SOURCE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_ADCHS_ExistsRegisters(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_Enable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_Disable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsEnableControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_TurboModeEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_TurboModeDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_TurboModeErrorHasOccurred(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_TurboModeChannelSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID masterChannelID, ADCHS_CHANNEL_ID slaveChannelID)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsTurboMode(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalComparatorAnalogInputSelect(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator, ADCHS_AN_INPUT_ID analogInput)
{
     
}

PLIB_INLINE_API ADCHS_AN_INPUT_ID _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalComparatorAnalogInputGet(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     return (ADCHS_AN_INPUT_ID)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalComparatorEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalComparatorDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalComparatorInterruptEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalComparatorInterruptDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID digComparator)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalComparatorSetup(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID id, bool intEnable, bool inBetweenOrEqual, bool greaterEqualHi, bool lessThanHi, bool greaterEqualLo, bool lessThanLo, ADCHS_AN_INPUT_ID analogInput, int16_t hiLimit, int16_t loLimit)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalComparatorEventHasOccurred(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID id)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalComparatorLimitSet(ADCHS_MODULE_ID index, ADCHS_DIGITAL_COMPARATOR_ID id, int16_t hiLimit, int16_t loLimit)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsDigitalComparator(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterOversamplingModeSetup(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_AN_INPUT_ID analogInput, ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length, ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio, bool intEnable)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterAveragingModeSetup(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_AN_INPUT_ID analogInput, ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length, ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count, bool intEnable)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id, ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterDataIsReady(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID id)
{
     return (bool)0;
}

PLIB_INLINE_API int16_t _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterDataGet(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID dfltrID)
{
     return (int16_t)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID digFilter)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_DIGITAL_FILTER_ID digFilter)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsDigitalFilter(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API int32_t _PLIB_UNSUPPORTED PLIB_ADCHS_FIFORead(ADCHS_MODULE_ID index)
{
     return (int32_t)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_FIFODataIsAvailable(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_FIFODataReadyInterruptEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_FIFODataReadyInterruptDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_FIFOEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_FIFODisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_FIFOSourceSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (bool)0;
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_ADCHS_FIFODataCountGet(ADCHS_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API ADCHS_CHANNEL_ID _PLIB_UNSUPPORTED PLIB_ADCHS_FIFOSourceGet(ADCHS_MODULE_ID index)
{
     return (ADCHS_CHANNEL_ID)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_FIFOErrorHasOccurred(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_FIFODataIsNegative(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsFIFO(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DMAEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DMADisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_DMASetup(ADCHS_MODULE_ID index, ADCHS_DMA_BUFFER_LENGTH bufferLengthBytes, uint32_t baseAddress, ADCHS_DMA_COUNT countMode, uint32_t countBaseAddress)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMASourceEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMASourceDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_A_InterruptEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_A_InterruptDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_B_InterruptEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_B_InterruptDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (bool)0;
}

PLIB_INLINE_API int8_t _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_A_IsFull(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (int8_t)0;
}

PLIB_INLINE_API int8_t _PLIB_UNSUPPORTED PLIB_ADCHS_DMABuffer_B_IsFull(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (int8_t)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_DMAOverflowErrorHasOccurred(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsDMA(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_CVDEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_CVDDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_CVDSetup(ADCHS_MODULE_ID index, ADCHS_CVD_CAPACITOR capSel, bool inBetweenOrEqual, bool greaterEqualHi, bool lessThanHi, bool greaterEqualLo, bool lessThanLo, ADCHS_AN_INPUT_ID inputEnable, int16_t hiLimit, int16_t loLimit)
{
     
}

PLIB_INLINE_API int16_t _PLIB_UNSUPPORTED PLIB_ADCHS_CVDResultGet(ADCHS_MODULE_ID index)
{
     return (int16_t)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsCVD(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_VREFIsReady(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_VREFFaultHasOccurred(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_VREFReadyInterruptEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_VREFReadyInterruptDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_VREFFaultInterruptEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_VREFFaultInterruptDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsVREFControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputScanIsComplete(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputScanSelect(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputScanRemove(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputScanIsSelected(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputScanSetup(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput, ADCHS_SCAN_TRIGGER_SENSITIVE trgSensitive, ADCHS_SCAN_TRIGGER_SOURCE triggerSource)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ScanCompleteInterruptEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ScanCompleteInterruptDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsAnalogInputScan(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelAnalogFeatureEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelAnalogFeatureDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelIsReady(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelIsReadyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelIsReadyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelAnalogControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelDigitalFeatureEnable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelDigitalFeatureDisable(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelDigitalControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputModeSelect(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput, ADCHS_INPUT_MODE mode)
{
     
}

PLIB_INLINE_API ADCHS_INPUT_MODE _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputModeGet(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return (ADCHS_INPUT_MODE)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsAnalogInputModeControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputLevelTriggerSet(ADCHS_MODULE_ID index, ADCHS_CLASS12_AN_INPUT_ID analogInput)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputEdgeTriggerSet(ADCHS_MODULE_ID index, ADCHS_CLASS12_AN_INPUT_ID analogInput)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputTriggerSourceSelect(ADCHS_MODULE_ID index, ADCHS_CLASS12_AN_INPUT_ID inputId, ADCHS_TRIGGER_SOURCE triggerSource)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_GlobalSoftwareTriggerEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_GlobalLevelSoftwareTriggerEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_GlobalLevelSoftwareTriggerDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_TriggerSuspendEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_TriggerSuspendDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsTriggerControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelTriggerSampleSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, ADCHS_CHANNEL_TRIGGER_SAMPLING_SEL sampSel)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsTriggerSampleControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_EarlyInterruptEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_EarlyInterruptDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputEarlyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputEarlyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputEarlyInterruptIsReady(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsEarlyInterruptControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_SoftwareSamplingStart(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_SoftwareSamplingStop(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_SoftwareConversionStart(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_SoftwareConversionInputSelect(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID anInput)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsManualControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ControlRegistersCanBeUpdatedInterruptDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_ControlRegistersCanBeUpdated(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsUpdateReadyControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelInputSelect(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, ADCHS_CHANNEL_INP_SEL sel)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelInputSelectControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ExternalConversionRequestEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ExternalConversionRequestDisable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsExternalConversionRequestControl(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_Setup(ADCHS_MODULE_ID index, ADCHS_VREF_SOURCE voltageRefSelect, ADCHS_CHARGEPUMP_MODE chargePump, ADCHS_OUTPUT_DATA_FORMAT outputFormat, bool stopInIdle, ADCHS_FAST_SYNC_SYSTEM_CLOCK sysClk, ADCHS_FAST_SYNC_PERIPHERAL_CLOCK periClk, ADCHS_INTERRUPT_BIT_SHIFT_LEFT intVectorShift, uint16_t intVectorBase, ADCHS_CLOCK_SOURCE adcClockSource, int8_t adcClockDivider, ADCHS_WARMUP_CLOCK warmUpClock)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelSetup(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, ADCHS_DATA_RESOLUTION res, uint8_t channelClockDivider, uint16_t sampleTimeCount, ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK earlyInterruptClk)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsConfiguration(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputIsAvailable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsAnalogInputCheck(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelConfigurationGet(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID)
{
     return (uint32_t)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelConfigurationSet(ADCHS_MODULE_ID index, ADCHS_CHANNEL_ID channelID, uint32_t config)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsChannelConfiguration(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputDataReadyInterruptEnable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputDataReadyInterruptDisable(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputDataIsReady(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_ADCHS_AnalogInputResultGet(ADCHS_MODULE_ID index, ADCHS_AN_INPUT_ID analogInput)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsConversionResults(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelScanEnable(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADCHS_ChannelScanAbort(ADCHS_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_ADCHS_ExistsScanEnable(ADCHS_MODULE_ID index)
{
     return (bool)0;
}

#endif
