/* Created by plibgen $Revision: 1.31 $ */

#ifndef _CTMU_P32MX250F128B_H
#define _CTMU_P32MX250F128B_H

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

    CTMU_ID_0 = _CTMU_BASE_ADDRESS,
    CTMU_NUMBER_OF_MODULES = 1

} CTMU_MODULE_ID;

typedef enum {

    CTMU_EDGE1 = 0x00,
    CTMU_EDGE2 = 0x01

} CTMU_EDGE_SELECT;

typedef enum {

    CTMU_EDGE_X_LEVEL_SENSITIVE = 0x00,
    CTMU_EDGE_X_EDGE_SENSITIVE = 0x01

} CTMU_EDGE_SENSITIVITY;

typedef enum {

    CTMU_EDGE_X_POSITIVE_EDGE = 0x01,
    CTMU_EDGE_X_NEGATIVE_EDGE = 0x00

} CTMU_EDGE_POLARITY;

typedef enum {

    CTMU_TRIGGERSOURCE_TMR1 = 0x00,
    CTMU_TRIGGERSOURCE_OC1 = 0x01,
    CTMU_TRIGGERSOURCE_IC1 = 0x0A,
    CTMU_TRIGGERSOURCE_IC2 = 0x0B,
    CTMU_TRIGGERSOURCE_IC3 = 0x0C,
    CTMU_TRIGGERSOURCE_CMP1 = 0x0D,
    CTMU_TRIGGERSOURCE_CMP2 = 0x0E,
    CTMU_TRIGGERSOURCE_CMP3 = 0x0F,
    CTMU_TRIGGERSOURCE_1 = 0x03,
    CTMU_TRIGGERSOURCE_2 = 0x02,
    CTMU_TRIGGERSOURCE_3 = 0x04,
    CTMU_TRIGGERSOURCE_4 = 0x05,
    CTMU_TRIGGERSOURCE_5 = 0x06,
    CTMU_TRIGGERSOURCE_6 = 0x07,
    CTMU_TRIGGERSOURCE_7 = 0x08,
    CTMU_TRIGGERSOURCE_8 = 0x09

} CTMU_TRIGGER_SOURCES;

typedef enum {

    CTMU_CURRENT_RANGE_1000XBASE = 0x00,
    CTMU_CURRENT_RANGE_BASE = 0x01,
    CTMU_CURRENT_RANGE_10XBASE = 0x02,
    CTMU_CURRENT_RANGE_100XBASE = 0x03

} CTMU_CURRENT_RANGE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/ctmu_EdgeSensitivity_Default.h"
#include "../templates/ctmu_EdgePolarity_Default.h"
#include "../templates/ctmu_EdgeTriggerSource_Default.h"
#include "../templates/ctmu_EdgeStatus_Default.h"
#include "../templates/ctmu_ModuleEnable_Default.h"
#include "../templates/ctmu_StopInIdle_Default.h"
#include "../templates/ctmu_TimePulseGeneration_Default.h"
#include "../templates/ctmu_EdgeEnable_Default.h"
#include "../templates/ctmu_EdgeSequencing_Default.h"
#include "../templates/ctmu_CurrentDischarge_Default.h"
#include "../templates/ctmu_AutomaticADCTrigger_Default.h"
#include "../templates/ctmu_CurrentTrim_Default.h"
#include "../templates/ctmu_CurrentRange_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_CTMU_EdgeSensitivitySet(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber, CTMU_EDGE_SENSITIVITY edgeSense)
{
     CTMU_EdgeSensitivitySet_Default(index, edgeNumber, edgeSense);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeSensitivity(CTMU_MODULE_ID index)
{
     return CTMU_ExistsEdgeSensitivity_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_EdgePolaritySet(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber, CTMU_EDGE_POLARITY edgePolarity)
{
     CTMU_EdgePolaritySet_Default(index, edgeNumber, edgePolarity);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgePolarity(CTMU_MODULE_ID index)
{
     return CTMU_ExistsEdgePolarity_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_EdgeTriggerSourceSelect(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber, CTMU_TRIGGER_SOURCES triggerSource)
{
     CTMU_EdgeTriggerSourceSelect_Default(index, edgeNumber, triggerSource);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeTriggerSource(CTMU_MODULE_ID index)
{
     return CTMU_ExistsEdgeTriggerSource_Default(index);
}

PLIB_INLINE_API bool PLIB_CTMU_EdgeIsSet(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber)
{
     return CTMU_EdgeIsSet_Default(index, edgeNumber);
}

PLIB_INLINE_API void PLIB_CTMU_EdgeSet(CTMU_MODULE_ID index, CTMU_EDGE_SELECT edgeNumber)
{
     CTMU_EdgeSet_Default(index, edgeNumber);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeStatus(CTMU_MODULE_ID index)
{
     return CTMU_ExistsEdgeStatus_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_Disable(CTMU_MODULE_ID index)
{
     CTMU_Disable_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_Enable(CTMU_MODULE_ID index)
{
     CTMU_Enable_Default(index);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsModuleEnable(CTMU_MODULE_ID index)
{
     return CTMU_ExistsModuleEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_StopInIdleDisable(CTMU_MODULE_ID index)
{
     CTMU_StopInIdleDisable_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_StopInIdleEnable(CTMU_MODULE_ID index)
{
     CTMU_StopInIdleEnable_Default(index);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsStopInIdle(CTMU_MODULE_ID index)
{
     return CTMU_ExistsStopInIdle_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_TimePulseGenerationDisable(CTMU_MODULE_ID index)
{
     CTMU_TimePulseGenerationDisable_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_TimePulseGenerationEnable(CTMU_MODULE_ID index)
{
     CTMU_TimePulseGenerationEnable_Default(index);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsTimePulseGeneration(CTMU_MODULE_ID index)
{
     return CTMU_ExistsTimePulseGeneration_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_EdgeDisable(CTMU_MODULE_ID index)
{
     CTMU_EdgeDisable_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_EdgeEnable(CTMU_MODULE_ID index)
{
     CTMU_EdgeEnable_Default(index);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeEnable(CTMU_MODULE_ID index)
{
     return CTMU_ExistsEdgeEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_EdgeSequenceDisable(CTMU_MODULE_ID index)
{
     CTMU_EdgeSequenceDisable_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_EdgeSequenceEnable(CTMU_MODULE_ID index)
{
     CTMU_EdgeSequenceEnable_Default(index);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsEdgeSequencing(CTMU_MODULE_ID index)
{
     return CTMU_ExistsEdgeSequencing_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_CurrentDischargeEnable(CTMU_MODULE_ID index)
{
     CTMU_CurrentDischargeEnable_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_CurrentDischargeDisable(CTMU_MODULE_ID index)
{
     CTMU_CurrentDischargeDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsCurrentDischarge(CTMU_MODULE_ID index)
{
     return CTMU_ExistsCurrentDischarge_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_AutomaticADCTriggerDisable(CTMU_MODULE_ID index)
{
     CTMU_AutomaticADCTriggerDisable_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_AutomaticADCTriggerEnable(CTMU_MODULE_ID index)
{
     CTMU_AutomaticADCTriggerEnable_Default(index);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsAutomaticADCTrigger(CTMU_MODULE_ID index)
{
     return CTMU_ExistsAutomaticADCTrigger_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_CurrentTrimSet(CTMU_MODULE_ID index, int16_t currentTrim)
{
     CTMU_CurrentTrimSet_Default(index, currentTrim);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsCurrentTrim(CTMU_MODULE_ID index)
{
     return CTMU_ExistsCurrentTrim_Default(index);
}

PLIB_INLINE_API void PLIB_CTMU_CurrentRangeSet(CTMU_MODULE_ID index, CTMU_CURRENT_RANGE currentRange)
{
     CTMU_CurrentRangeSet_Default(index, currentRange);
}

PLIB_INLINE_API bool PLIB_CTMU_ExistsCurrentRange(CTMU_MODULE_ID index)
{
     return CTMU_ExistsCurrentRange_Default(index);
}

#endif
