/* Created by plibgen $Revision: 1.31 $ */

#ifndef _ADC_P32MX250F128B_H
#define _ADC_P32MX250F128B_H

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

    ADC_ID_1 = _ADC10_BASE_ADDRESS,
    ADC_NUMBER_OF_MODULES = 1

} ADC_MODULE_ID;

typedef enum {

    ADC_MUX_A = 0x00,
    ADC_MUX_B = 0x01

} ADC_MUX;

typedef enum {

    ADC_FILLING_BUF_0TO7 = 0x00,
    ADC_FILLING_BUF_8TOF = 0x01

} ADC_RESULT_BUF_STATUS;

typedef enum {

    ADC_REFERENCE_VDD_TO_AVSS = 0x00,
    ADC_REFERENCE_VREFPLUS_TO_AVSS = 0x01,
    ADC_REFERENCE_AVDD_TO_VREF_NEG = 0x02,
    ADC_REFERENCE_VREFPLUS_TO_VREFNEG = 0x03

} ADC_VOLTAGE_REFERENCE;

typedef enum {

    ADC_SAMPLING_MODE_ALTERNATE_INPUT = 0x01,
    ADC_SAMPLING_MODE_MUXA = 0x00

} ADC_SAMPLING_MODE;

typedef enum {

    ADC_1SAMPLE_PER_INTERRUPT = 0x00,
    ADC_2SAMPLES_PER_INTERRUPT = 0x01,
    ADC_3SAMPLES_PER_INTERRUPT = 0x02,
    ADC_4SAMPLES_PER_INTERRUPT = 0x03,
    ADC_5SAMPLES_PER_INTERRUPT = 0x04,
    ADC_6SAMPLES_PER_INTERRUPT = 0x05,
    ADC_7SAMPLES_PER_INTERRUPT = 0x06,
    ADC_8SAMPLES_PER_INTERRUPT = 0x07,
    ADC_9SAMPLES_PER_INTERRUPT = 0x08,
    ADC_10SAMPLES_PER_INTERRUPT = 0x09,
    ADC_11SAMPLES_PER_INTERRUPT = 0x0A,
    ADC_12SAMPLES_PER_INTERRUPT = 0x0B,
    ADC_13SAMPLES_PER_INTERRUPT = 0x0C,
    ADC_14SAMPLES_PER_INTERRUPT = 0x0D,
    ADC_15SAMPLES_PER_INTERRUPT = 0x0E,
    ADC_16SAMPLES_PER_INTERRUPT = 0x0F

} ADC_SAMPLES_PER_INTERRUPT;

typedef enum {

    ADC_INPUT_POSITIVE_AN0 = 0x00,
    ADC_INPUT_POSITIVE_AN1 = 0x01,
    ADC_INPUT_POSITIVE_AN2 = 0x02,
    ADC_INPUT_POSITIVE_AN3 = 0x03,
    ADC_INPUT_POSITIVE_AN4 = 0x04,
    ADC_INPUT_POSITIVE_AN5 = 0x05,
    ADC_INPUT_POSITIVE_AN9 = 0x09,
    ADC_INPUT_POSITIVE_AN10 = 0x0A,
    ADC_INPUT_POSITIVE_AN11 = 0x0B,
    ADC_INPUT_POSITIVE_CTMU = 0x0D,
    ADC_INPUT_POSITIVE_IVREF = 0x0E,
    ADC_INPUT_POSITIVE_OPEN = 0x0F

} ADC_INPUTS_POSITIVE;

typedef enum {

    ADC_INPUT_SCAN_AN0 = 0x0001,
    ADC_INPUT_SCAN_AN1 = 0x0002,
    ADC_INPUT_SCAN_AN2 = 0x0004,
    ADC_INPUT_SCAN_AN3 = 0x0008,
    ADC_INPUT_SCAN_AN4 = 0x0010,
    ADC_INPUT_SCAN_AN5 = 0x0020,
    ADC_INPUT_SCAN_AN6 = 0x0040,
    ADC_INPUT_SCAN_AN7 = 0x0080,
    ADC_INPUT_SCAN_AN8 = 0x0100,
    ADC_INPUT_SCAN_AN9 = 0x0200,
    ADC_INPUT_SCAN_AN10 = 0x0400,
    ADC_INPUT_SCAN_AN11 = 0x0800,
    ADC_INPUT_SCAN_AN12 = 0x1000,
    ADC_INPUT_SCAN_AN13 = 0x2000,
    ADC_INPUT_SCAN_AN14 = 0x4000,
    ADC_INPUT_SCAN_AN15 = 0x8000

} ADC_INPUTS_SCAN;

typedef enum {

    ADC_INPUTS_SCAN_EXTENDED_NONE

} ADC_INPUTS_SCAN_EXTENDED;

typedef enum {

    ADC_INPUT_NEGATIVE_VREF_MINUS = 0x00,
    ADC_INPUT_NEGATIVE_AN1 = 0x01

} ADC_INPUTS_NEGATIVE;

typedef enum {

    ADC_CLOCK_SOURCE_PERIPHERAL_BUS_CLOCK = 0x00,
    ADC_CLOCK_SOURCE_SYSTEM_CLOCK = 0x00,
    ADC_CLOCK_SOURCE_INTERNAL_RC = 0x01

} ADC_CLOCK_SOURCE;

typedef enum {

    ADC_CONVERSION_TRIGGER_SAMP_CLEAR = 0x00,
    ADC_CONVERSION_TRIGGER_INT0_TRANSITION = 0x01,
    ADC_CONVERSION_TRIGGER_TMR3_COMPARE_MATCH = 0x02,
    ADC_CONVERSION_TRIGGER_CTMU_EVENT = 0x03,
    ADC_CONVERSION_TRIGGER_INTERNAL_COUNT = 0x07

} ADC_CONVERSION_TRIGGER_SOURCE;

typedef enum {

    ADC_RESULT_FORMAT_INTEGER_16BIT = 0x00,
    ADC_RESULT_FORMAT_SIGNED_INTEGER_16BIT = 0x01,
    ADC_RESULT_FORMAT_FRACTIONAL_16BIT = 0x02,
    ADC_RESULT_FORMAT_SIGNED_FRACTIONAL_16BIT = 0x03,
    ADC_RESULT_FORMAT_INTEGER_32BIT = 0x04,
    ADC_RESULT_FORMAT_SIGNED_INTEGER_32BIT = 0x05,
    ADC_RESULT_FORMAT_FRACTIONAL_32BIT = 0x06,
    ADC_RESULT_FORMAT_SIGNED_FRACTIONAL_32BIT = 0x07

} ADC_RESULT_FORMAT;

typedef enum {

    ADC_BUFFER_MODE_ONE_16WORD_BUFFER = 0x00,
    ADC_BUFFER_MODE_TWO_8WORD_BUFFERS = 0x01

} ADC_BUFFER_MODE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/adc_EnableControl_Default.h"
#include "../templates/adc_StopInIdle_Default.h"
#include "../templates/adc_CalibrationControl_Default.h"
#include "../templates/adc_MuxInputScanSelect_Default.h"
#include "../templates/adc_MuxInputScanSelectExtended_Unsupported.h"
#include "../templates/adc_VoltageReference_Default.h"
#include "../templates/adc_MuxChannel0PositiveInput_Default.h"
#include "../templates/adc_MuxChannel0NegativeInput_Default.h"
#include "../templates/adc_MuxInputScanControl_Default.h"
#include "../templates/adc_SamplingModeControl_Default.h"
#include "../templates/adc_SamplesPerInterruptSelect_Default.h"
#include "../templates/adc_SamplingAutoStart_Default.h"
#include "../templates/adc_SamplingControl_Default.h"
#include "../templates/adc_SamplingAcquisitionTime_Default.h"
#include "../templates/adc_SamplingStatus_Default.h"
#include "../templates/adc_ConversionControl_Default.h"
#include "../templates/adc_ConversionClock_Default.h"
#include "../templates/adc_ConversionClockSource_Default.h"
#include "../templates/adc_ConversionTriggerSource_Default.h"
#include "../templates/adc_ConversionStopSequenceControl_Default.h"
#include "../templates/adc_ConversionStatus_Default.h"
#include "../templates/adc_ResultFormat_Default.h"
#include "../templates/adc_ResultBufferMode_Default.h"
#include "../templates/adc_ResultBufferFillStatus_Default.h"
#include "../templates/adc_ResultGetByIndex_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_ADC_Enable(ADC_MODULE_ID index)
{
     ADC_Enable_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_Disable(ADC_MODULE_ID index)
{
     ADC_Disable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsEnableControl(ADC_MODULE_ID index)
{
     return ADC_ExistsEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_StopInIdleEnable(ADC_MODULE_ID index)
{
     ADC_StopInIdleEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_StopInIdleDisable(ADC_MODULE_ID index)
{
     ADC_StopInIdleDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsStopInIdleControl(ADC_MODULE_ID index)
{
     return ADC_ExistsStopInIdleControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_CalibrationEnable(ADC_MODULE_ID index)
{
     ADC_CalibrationEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_CalibrationDisable(ADC_MODULE_ID index)
{
     ADC_CalibrationDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsCalibrationControl(ADC_MODULE_ID index)
{
     return ADC_ExistsCalibrationControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_InputScanMaskAdd(ADC_MODULE_ID index, ADC_INPUTS_SCAN scanInputs)
{
     ADC_InputScanMaskAdd_Default(index, scanInputs);
}

PLIB_INLINE_API void PLIB_ADC_InputScanMaskRemove(ADC_MODULE_ID index, ADC_INPUTS_SCAN scanInputs)
{
     ADC_InputScanMaskRemove_Default(index, scanInputs);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxInputScanSelect(ADC_MODULE_ID index)
{
     return ADC_ExistsMuxInputScanSelect_Default(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_InputScanMaskAddExtended(ADC_MODULE_ID index, ADC_INPUTS_SCAN_EXTENDED scanInputs)
{
     ADC_InputScanMaskAddExtended_Unsupported(index, scanInputs);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_ADC_InputScanMaskRemoveExtended(ADC_MODULE_ID index, ADC_INPUTS_SCAN_EXTENDED scanInputs)
{
     ADC_InputScanMaskRemoveExtended_Unsupported(index, scanInputs);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxInputScanSelectExtended(ADC_MODULE_ID index)
{
     return ADC_ExistsMuxInputScanSelectExtended_Unsupported(index);
}

PLIB_INLINE_API void PLIB_ADC_VoltageReferenceSelect(ADC_MODULE_ID index, ADC_VOLTAGE_REFERENCE configValue)
{
     ADC_VoltageReferenceSelect_Default(index, configValue);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsVoltageReference(ADC_MODULE_ID index)
{
     return ADC_ExistsVoltageReference_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_MuxChannel0InputPositiveSelect(ADC_MODULE_ID index, ADC_MUX muxType, ADC_INPUTS_POSITIVE input)
{
     ADC_MuxChannel0InputPositiveSelect_Default(index, muxType, input);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxChannel0PositiveInput(ADC_MODULE_ID index)
{
     return ADC_ExistsMuxChannel0PositiveInput_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_MuxChannel0InputNegativeSelect(ADC_MODULE_ID index, ADC_MUX muxType, ADC_INPUTS_NEGATIVE input)
{
     ADC_MuxChannel0InputNegativeSelect_Default(index, muxType, input);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxChannel0NegativeInput(ADC_MODULE_ID index)
{
     return ADC_ExistsMuxChannel0NegativeInput_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_MuxAInputScanEnable(ADC_MODULE_ID index)
{
     ADC_MuxAInputScanEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_MuxAInputScanDisable(ADC_MODULE_ID index)
{
     ADC_MuxAInputScanDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsMuxInputScanControl(ADC_MODULE_ID index)
{
     return ADC_ExistsMuxInputScanControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_SamplingModeSelect(ADC_MODULE_ID index, ADC_SAMPLING_MODE mode)
{
     ADC_SamplingModeSelect_Default(index, mode);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingModeControl(ADC_MODULE_ID index)
{
     return ADC_ExistsSamplingModeControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_SamplesPerInterruptSelect(ADC_MODULE_ID index, ADC_SAMPLES_PER_INTERRUPT value)
{
     ADC_SamplesPerInterruptSelect_Default(index, value);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplesPerInterruptSelect(ADC_MODULE_ID index)
{
     return ADC_ExistsSamplesPerInterruptSelect_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_SampleAutoStartEnable(ADC_MODULE_ID index)
{
     ADC_SampleAutoStartEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_SampleAutoStartDisable(ADC_MODULE_ID index)
{
     ADC_SampleAutoStartDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingAutoStart(ADC_MODULE_ID index)
{
     return ADC_ExistsSamplingAutoStart_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_SamplingStart(ADC_MODULE_ID index)
{
     ADC_SamplingStart_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_SamplingStop(ADC_MODULE_ID index)
{
     ADC_SamplingStop_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingControl(ADC_MODULE_ID index)
{
     return ADC_ExistsSamplingControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_SampleAcquisitionTimeSet(ADC_MODULE_ID index, ADC_ACQUISITION_TIME acqTime)
{
     ADC_SampleAcquisitionTimeSet_Default(index, acqTime);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingAcquisitionTime(ADC_MODULE_ID index)
{
     return ADC_ExistsSamplingAcquisitionTime_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_SamplingIsActive(ADC_MODULE_ID index)
{
     return ADC_SamplingIsActive_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsSamplingStatus(ADC_MODULE_ID index)
{
     return ADC_ExistsSamplingStatus_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_ConversionStart(ADC_MODULE_ID index)
{
     ADC_ConversionStart_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionControl(ADC_MODULE_ID index)
{
     return ADC_ExistsConversionControl_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_ConversionClockSet(ADC_MODULE_ID index, uint32_t baseFrequency, ADC_CONVERSION_CLOCK value)
{
     ADC_ConversionClockSet_Default(index, baseFrequency, value);
}

PLIB_INLINE_API ADC_CONVERSION_CLOCK PLIB_ADC_ConversionClockGet(ADC_MODULE_ID index, uint32_t baseFrequency)
{
     return ADC_ConversionClockGet_Default(index, baseFrequency);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionClock(ADC_MODULE_ID index)
{
     return ADC_ExistsConversionClock_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_ConversionClockSourceSelect(ADC_MODULE_ID index, ADC_CLOCK_SOURCE source)
{
     ADC_ConversionClockSourceSelect_Default(index, source);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionClockSource(ADC_MODULE_ID index)
{
     return ADC_ExistsConversionClockSource_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_ConversionTriggerSourceSelect(ADC_MODULE_ID index, ADC_CONVERSION_TRIGGER_SOURCE source)
{
     ADC_ConversionTriggerSourceSelect_Default(index, source);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionTriggerSource(ADC_MODULE_ID index)
{
     return ADC_ExistsConversionTriggerSource_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_ConversionStopSequenceEnable(ADC_MODULE_ID index)
{
     ADC_ConversionStopSequenceEnable_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_ConversionStopSequenceDisable(ADC_MODULE_ID index)
{
     ADC_ConversionStopSequenceDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionStopSequenceControl(ADC_MODULE_ID index)
{
     return ADC_ExistsConversionStopSequenceControl_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ConversionHasCompleted(ADC_MODULE_ID index)
{
     return ADC_ConversionHasCompleted_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsConversionStatus(ADC_MODULE_ID index)
{
     return ADC_ExistsConversionStatus_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_ResultFormatSelect(ADC_MODULE_ID index, ADC_RESULT_FORMAT resultFormat)
{
     ADC_ResultFormatSelect_Default(index, resultFormat);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsResultFormat(ADC_MODULE_ID index)
{
     return ADC_ExistsResultFormat_Default(index);
}

PLIB_INLINE_API void PLIB_ADC_ResultBufferModeSelect(ADC_MODULE_ID index, ADC_BUFFER_MODE mode)
{
     ADC_ResultBufferModeSelect_Default(index, mode);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsResultBufferMode(ADC_MODULE_ID index)
{
     return ADC_ExistsResultBufferMode_Default(index);
}

PLIB_INLINE_API ADC_RESULT_BUF_STATUS PLIB_ADC_ResultBufferStatusGet(ADC_MODULE_ID index)
{
     return ADC_ResultBufferStatusGet_Default(index);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsResultBufferFillStatus(ADC_MODULE_ID index)
{
     return ADC_ExistsResultBufferFillStatus_Default(index);
}

PLIB_INLINE_API ADC_SAMPLE PLIB_ADC_ResultGetByIndex(ADC_MODULE_ID index, uint8_t bufferIndex)
{
     return ADC_ResultGetByIndex_Default(index, bufferIndex);
}

PLIB_INLINE_API bool PLIB_ADC_ExistsResultGetByIndex(ADC_MODULE_ID index)
{
     return ADC_ExistsResultGetByIndex_Default(index);
}

#endif
