/* Created by plibgen $Revision: 1.31 $ */

#ifndef _CDAC_P32MX250F128B_H
#define _CDAC_P32MX250F128B_H

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

    CDAC_NUMBER_OF_MODULES = 0

} CDAC_MODULE_ID;

typedef enum {

    CDAC_OUTPUT_SELECTION_NONE

} CDAC_OUTPUT_SELECTION;

typedef enum {

    CDAC_MODULE_ENABLE_NONE

} CDAC_MODULE_ENABLE;

typedef enum {

    CDAC_OUTPUT_ENABLE_NONE

} CDAC_OUTPUT_ENABLE;

typedef enum {

    CDAC_REF_SEL_NONE

} CDAC_REF_SEL;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CDAC_Enable(CDAC_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CDAC_Disable(CDAC_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_CDAC_ExistsEnableControl(CDAC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CDAC_OutputEnable(CDAC_MODULE_ID index, CDAC_OUTPUT_SELECTION output)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CDAC_OutputDisable(CDAC_MODULE_ID index, CDAC_OUTPUT_SELECTION output)
{
     
}

PLIB_INLINE_API bool PLIB_CDAC_ExistsOutputControl(CDAC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CDAC_ReferenceVoltageSelect(CDAC_MODULE_ID index, CDAC_REF_SEL refSel)
{
     
}

PLIB_INLINE_API bool PLIB_CDAC_ExistsReferenceVoltageSelect(CDAC_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint16_t _PLIB_UNSUPPORTED PLIB_CDAC_DataRead(CDAC_MODULE_ID index)
{
     return (uint16_t)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_CDAC_DataWrite(CDAC_MODULE_ID index, uint16_t cdacData)
{
     
}

PLIB_INLINE_API bool PLIB_CDAC_ExistsDataControl(CDAC_MODULE_ID index)
{
     return (bool)0;
}

#endif
