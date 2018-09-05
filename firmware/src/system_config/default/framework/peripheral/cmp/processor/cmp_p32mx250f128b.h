/* Created by plibgen $Revision: 1.31 $ */

#ifndef _CMP_P32MX250F128B_H
#define _CMP_P32MX250F128B_H

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

    CMP_ID_1 = _CMP1_BASE_ADDRESS,
    CMP_ID_2 = _CMP2_BASE_ADDRESS,
    CMP_ID_3 = _CMP3_BASE_ADDRESS,
    CMP_NUMBER_OF_MODULES = 3

} CMP_MODULE_ID;

typedef enum {

    CMP_CVREF_VOLTAGE_SOURCE_NEG_REFERENCE_NONE = 0x00

} CMP_CVREF_VOLTAGE_SOURCE_NEG_REFERENCE;

typedef enum {

    CMP_MASK_C_PWM1H = 0x02,
    CMP_MASK_C_PWM2L = 0x03,
    CMP_MASK_C_PWM2H = 0x04,
    CMP_MASK_C_PWM3L = 0x05,
    CMP_MASK_C_PWM3H = 0x06,
    CMP_MASK_C_PTGO18 = 0x07,
    CMP_MASK_C_PTGO19 = 0x05,
    CMP_MASK_C_FLT2 = 0x06,
    CMP_MASK_C_FLT4 = 0x07

} CMP_MASK_C;

typedef enum {

    CMP_MASK_B_PWM1H = 0x02,
    CMP_MASK_B_PWM2L = 0x03,
    CMP_MASK_B_PWM2H = 0x04,
    CMP_MASK_B_PWM3L = 0x05,
    CMP_MASK_B_PWM3H = 0x06,
    CMP_MASK_B_PTGO18 = 0x07,
    CMP_MASK_B_PTGO19 = 0x05,
    CMP_MASK_B_FLT2 = 0x06,
    CMP_MASK_B_FLT4 = 0x07

} CMP_MASK_B;

typedef enum {

    CMP_MASK_A_PWM1H = 0x02,
    CMP_MASK_A_PWM2L = 0x03,
    CMP_MASK_A_PWM2H = 0x04,
    CMP_MASK_A_PWM3L = 0x05,
    CMP_MASK_A_PWM3H = 0x06,
    CMP_MASK_A_PTGO18 = 0x07,
    CMP_MASK_A_PTGO19 = 0x05,
    CMP_MASK_A_FLT2 = 0x06,
    CMP_MASK_A_FLT4 = 0x07

} CMP_MASK_A;

typedef enum {

    CMP_SPEED_POWER_LOWER = 0x01,
    CMP_SPEED_POWER_HIGHER = 0x02

} CMP_SPEED_POWER;

typedef enum {

    CMP_FILTER_CLOCK_FP = 0x01,
    CMP_FILTER_CLOCK_FOSC = 0x02,
    CMP_FILTER_CLOCK_SYNCO1 = 0x03,
    CMP_FILTER_CLOCK_T2CLK = 0x04,
    CMP_FILTER_CLOCK_T3CLK = 0x05,
    CMP_FILTER_CLOCK_T4CLK = 0x06,
    CMP_FILTER_CLOCK_T5CLK = 0x07

} CMP_FILTER_CLOCK;

typedef enum {

    CMP_FILTER_CLOCK_DIVIDE_1_1 = 0x01,
    CMP_FILTER_CLOCK_DIVIDE_1_2 = 0x02,
    CMP_FILTER_CLOCK_DIVIDE_1_4 = 0x04,
    CMP_FILTER_CLOCK_DIVIDE_1_8 = 0x08,
    CMP_FILTER_CLOCK_DIVIDE_1_16 = 0x10,
    CMP_FILTER_CLOCK_DIVIDE_1_32 = 0x20,
    CMP_FILTER_CLOCK_DIVIDE_1_64 = 0x40,
    CMP_FILTER_CLOCK_DIVIDE_1_128 = 0x80

} CMP_CLOCK_DIVIDE;

typedef enum {

    CMP_CVREF_VALUE_0 = 0x00,
    CMP_CVREF_VALUE_1 = 0x01,
    CMP_CVREF_VALUE_2 = 0x02,
    CMP_CVREF_VALUE_3 = 0x03,
    CMP_CVREF_VALUE_4 = 0x04,
    CMP_CVREF_VALUE_5 = 0x05,
    CMP_CVREF_VALUE_6 = 0x06,
    CMP_CVREF_VALUE_7 = 0x07,
    CMP_CVREF_VALUE_8 = 0x08,
    CMP_CVREF_VALUE_9 = 0x09,
    CMP_CVREF_VALUE_10 = 0x0A,
    CMP_CVREF_VALUE_11 = 0x0B,
    CMP_CVREF_VALUE_12 = 0x0C,
    CMP_CVREF_VALUE_13 = 0x0D,
    CMP_CVREF_VALUE_14 = 0x0E,
    CMP_CVREF_VALUE_15 = 0x0F

} CMP_CVREF_VALUE;

typedef enum {

    CMP_CVREF_VOLTAGE_SOURCE_VDD = 0x00,
    CMP_CVREF_VOLTAGE_SOURCE_EXTERNAL = 0x01

} CMP_CVREF_VOLTAGE_SOURCE;

typedef enum {

    CMP_INTERRUPT_GENERATION_DISABLED = 0x00,
    CMP_INTERRUPT_GENERATION_LOW_TO_HIGH = 0x01,
    CMP_INTERRUPT_GENERATION_HIGH_TO_LOW = 0x02,
    CMP_INTERRUPT_GENERATION_BOTH = 0x03

} CMP_INTERRUPT_EVENT;

typedef enum {

    CMP_INVERTING_INPUT_EXTERNAL_PIN_B = 0x00,
    CMP_INVERTING_INPUT_EXTERNAL_PIN_C = 0x01,
    CMP_INVERTING_INPUT_EXTERNAL_PIN_D = 0x02,
    CMP_INVERTING_INPUT_IVREF = 0x03,
    CMP_INPUT_C2IN_NEGATIVE = 0x00,
    CMP_INPUT_C2IN_POSITIVE = 0x01,
    CMP_INPUT_C1IN_POSITIVE = 0x02,
    CMP_INPUT_IVREF = 0x03

} CMP_INVERTING_INPUT;

typedef enum {

    CMP_NON_INVERTING_INPUT_EXTERNAL_PIN_A = 0x00,
    CMP_NON_INVERTING_INPUT_CVREF = 0x01,
    CMP_INPUT_EXTERNAL_PIN = 0x00,
    CMP_INPUT_INTERNAL_CVREF = 0x01

} CMP_NON_INVERTING_INPUT;

typedef enum {

    CMP_CVREF_RESISTOR_LADDER_VOLTAGE = 0x00,
    CMP_CVREF_POSITIVE_REFERENCE_VOLTAGE = 0x01

} CMP_CVREF_REFERENCE_SELECT;

typedef enum {

    CMP_CVREF_BANDGAP_1_2V = 0x00,
    CMP_CVREF_BANDGAP_0_6V = 0x01,
    CMP_CVREF_BANDGAP_VREFPLUS = 0x03

} CMP_CVREF_BANDGAP_SELECT;

typedef enum {

    CMP_OUTPUT_FILTER_CLK_DIV_NONE

} CMP_OUTPUT_FILTER_CLK_DIV;

typedef enum {

    CMP_OUTPUT_FILTER_CLK_SOURCE_NONE

} CMP_OUTPUT_FILTER_CLK_SOURCE;

typedef enum {

    CMP_OUTPUT_MASK_SOURCE_NONE

} CMP_OUTPUT_MASK_SOURCE;

typedef enum {

    CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT_NONE

} CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT;

typedef enum {

    CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT_NONE

} CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT;

typedef enum {

    CMP_OUTPUT_MASKING_LEVEL_NONE

} CMP_OUTPUT_MASKING_LEVEL;

typedef enum {

    CMP_MASK_ANDOR_LOGIC_NONE

} CMP_MASK_ANDOR_LOGIC;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/cmp_ComparatorEnableControl_Default.h"
#include "../templates/cmp_ComparatorOutputEnableControl_Default.h"
#include "../templates/cmp_InvertOutputSelectControl_Default.h"
#include "../templates/cmp_OutputStatusGet_Default.h"
#include "../templates/cmp_InterruptEventSelect_Default.h"
#include "../templates/cmp_NonInvertingInputSelect_Default.h"
#include "../templates/cmp_InvertingInputSelect_Default.h"
#include "../templates/cmp_StopInIdle_Default.h"
#include "../templates/cmp_CVREFEnableControl_Default.h"
#include "../templates/cmp_CVREFOutputEnableControl_Default.h"
#include "../templates/cmp_CVREFWideRangeControl_Default.h"
#include "../templates/cmp_CVREFVoltageRangeSelect_Default.h"
#include "../templates/cmp_CVREFRefVoltageRangeSelect_Unsupported.h"
#include "../templates/cmp_CVREFBGRefVoltageRangeSelect_Unsupported.h"
#include "../templates/cmp_CVREFValueSelect_Default.h"
#include "../templates/cmp_ComparatorEventStatusGet_Unsupported.h"
#include "../templates/cmp_ComparatorOutputDigitalFilter_Unsupported.h"
#include "../templates/cmp_OpAmpOutputEnableControl_Unsupported.h"
#include "../templates/cmp_OpAmpEnableControl_Unsupported.h"
#include "../templates/cmp_ComparatorOutputMasking_Unsupported.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_CMP_ExistsEnableControl(CMP_MODULE_ID index)
{
     return CMP_ExistsEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_Enable(CMP_MODULE_ID index)
{
     CMP_Enable_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_Disable(CMP_MODULE_ID index)
{
     CMP_Disable_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsOutputEnableControl(CMP_MODULE_ID index)
{
     return CMP_ExistsOutputEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_OutputEnable(CMP_MODULE_ID index)
{
     CMP_OutputEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_OutputDisable(CMP_MODULE_ID index)
{
     CMP_OutputDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsInvertOutputControl(CMP_MODULE_ID index)
{
     return CMP_ExistsInvertOutputControl_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_OutputInvertEnable(CMP_MODULE_ID index)
{
     CMP_OutputInvertEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_OutputInvertDisable(CMP_MODULE_ID index)
{
     CMP_OutputInvertDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsOutputStatusGet(CMP_MODULE_ID index)
{
     return CMP_ExistsOutputStatusGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_OutputStatusGet(CMP_MODULE_ID index)
{
     return CMP_OutputStatusGet_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsInterruptEventSelect(CMP_MODULE_ID index)
{
     return CMP_ExistsInterruptEventSelect_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_InterruptEventSelect(CMP_MODULE_ID index, CMP_INTERRUPT_EVENT event)
{
     CMP_InterruptEventSelect_Default(index, event);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsNonInvertingInputSelect(CMP_MODULE_ID index)
{
     return CMP_ExistsNonInvertingInputSelect_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_NonInvertingInputChannelSelect(CMP_MODULE_ID index, CMP_NON_INVERTING_INPUT input)
{
     CMP_NonInvertingInputChannelSelect_Default(index, input);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsInvertingInputSelect(CMP_MODULE_ID index)
{
     return CMP_ExistsInvertingInputSelect_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_InvertingInputChannelSelect(CMP_MODULE_ID index, CMP_INVERTING_INPUT channel)
{
     CMP_InvertingInputChannelSelect_Default(index, channel);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsStopInIdle(CMP_MODULE_ID index)
{
     return CMP_ExistsStopInIdle_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_StopInIdleModeEnable(CMP_MODULE_ID index)
{
     CMP_StopInIdleModeEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_StopInIdleModeDisable(CMP_MODULE_ID index)
{
     CMP_StopInIdleModeDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsCVREFEnableControl(CMP_MODULE_ID index)
{
     return CMP_ExistsCVREFEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_CVREF_Enable(CMP_MODULE_ID index)
{
     CMP_CVREF_Enable_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_CVREF_Disable(CMP_MODULE_ID index)
{
     CMP_CVREF_Disable_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsCVREFOutputEnableControl(CMP_MODULE_ID index)
{
     return CMP_ExistsCVREFOutputEnableControl_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_CVREF_OutputEnable(CMP_MODULE_ID index)
{
     CMP_CVREF_OutputEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_CVREF_OutputDisable(CMP_MODULE_ID index)
{
     CMP_CVREF_OutputDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsCVREFWideRangeControl(CMP_MODULE_ID index)
{
     return CMP_ExistsCVREFWideRangeControl_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_CVREF_WideRangeEnable(CMP_MODULE_ID index)
{
     CMP_CVREF_WideRangeEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_CVREF_WideRangeDisable(CMP_MODULE_ID index)
{
     CMP_CVREF_WideRangeDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_CVREF_WideRangeIsEnabled(CMP_MODULE_ID index)
{
     return CMP_CVREF_WideRangeIsEnabled_Default(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsCVREFVoltageRangeSelect(CMP_MODULE_ID index)
{
     return CMP_ExistsCVREFVoltageRangeSelect_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_CVREF_SourceVoltageSelect(CMP_MODULE_ID index, CMP_CVREF_VOLTAGE_SOURCE source)
{
     CMP_CVREF_SourceVoltageSelect_Default(index, source);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsCVREFRefVoltageRangeSelect(CMP_MODULE_ID index)
{
     return CMP_ExistsCVREFRefVoltageRangeSelect_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_CVREF_ReferenceVoltageSelect(CMP_MODULE_ID index, CMP_CVREF_REFERENCE_SELECT reference)
{
     CMP_CVREF_ReferenceVoltageSelect_Unsupported(index, reference);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsCVREFBGRefVoltageRangeSelect(CMP_MODULE_ID index)
{
     return CMP_ExistsCVREFBGRefVoltageRangeSelect_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_CVREF_BandGapReferenceSourceSelect(CMP_MODULE_ID index, CMP_CVREF_BANDGAP_SELECT select)
{
     CMP_CVREF_BandGapReferenceSourceSelect_Unsupported(index, select);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsCVREFValueSelect(CMP_MODULE_ID index)
{
     return CMP_ExistsCVREFValueSelect_Default(index);
}

PLIB_INLINE_API void PLIB_CMP_CVREF_ValueSelect(CMP_MODULE_ID index, CMP_CVREF_VALUE value)
{
     CMP_CVREF_ValueSelect_Default(index, value);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsComparatorEventStatusGet(CMP_MODULE_ID index)
{
     return CMP_ExistsComparatorEventStatusGet_Unsupported(index);
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_CMP_ComparatorEventStatusGet(CMP_MODULE_ID index)
{
     return CMP_ComparatorEventStatusGet_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsComparatorOutputDigitalFilter(CMP_MODULE_ID index)
{
     return CMP_ExistsComparatorOutputDigitalFilter_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_ComparatorOutputDigitalFilterClkSetup(CMP_MODULE_ID index, CMP_OUTPUT_FILTER_CLK_SOURCE clkSource, CMP_OUTPUT_FILTER_CLK_DIV clkDivider)
{
     CMP_ComparatorOutputDigitalFilterClkSetup_Unsupported(index, clkSource, clkDivider);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_ComparatorOutputDigitalFilterEnable(CMP_MODULE_ID index)
{
     CMP_ComparatorOutputDigitalFilterEnable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_ComparatorOutputDigitalFilterDisable(CMP_MODULE_ID index)
{
     CMP_ComparatorOutputDigitalFilterDisable_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsOpAmpOutputControl(CMP_MODULE_ID index)
{
     return CMP_ExistsOpAmpOutputControl_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_OpAmpOutputEnable(CMP_MODULE_ID index)
{
     CMP_OpAmpOutputEnable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_OpAmpOutputDisable(CMP_MODULE_ID index)
{
     CMP_OpAmpOutputDisable_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsOpAmpEnableControl(CMP_MODULE_ID index)
{
     return CMP_ExistsOpAmpEnableControl_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_OpAmpEnable(CMP_MODULE_ID index)
{
     CMP_OpAmpEnable_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_OpAmpDisable(CMP_MODULE_ID index)
{
     CMP_OpAmpDisable_Unsupported(index);
}

PLIB_INLINE_API bool PLIB_CMP_ExistsComparatorOutputMasking(CMP_MODULE_ID index)
{
     return CMP_ExistsComparatorOutputMasking_Unsupported(index);
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CMP_ComparatorOutputMaskingSetup(CMP_MODULE_ID index, CMP_OUTPUT_MASK_SOURCE sourceA, CMP_OUTPUT_MASK_SOURCE sourceB, CMP_OUTPUT_MASK_SOURCE sourceC, uint32_t logicSettings, CMP_NON_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGatePositiveOutput, CMP_INV_AND_GATE_OUTPUT_TO_OR_GATE_INPUT andGateNegativeOutput, CMP_OUTPUT_MASKING_LEVEL maskingLevels)
{
     CMP_ComparatorOutputMaskingSetup_Unsupported(index, sourceA, sourceB, sourceC, logicSettings, andGatePositiveOutput, andGateNegativeOutput, maskingLevels);
}

#endif
