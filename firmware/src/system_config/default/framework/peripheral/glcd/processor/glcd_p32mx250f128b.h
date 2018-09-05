/* Created by plibgen $Revision: 1.31 $ */

#ifndef _GLCD_P32MX250F128B_H
#define _GLCD_P32MX250F128B_H

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

    GLCD_NUMBER_OF_MODULES = 0

} GLCD_MODULE_ID;

typedef enum {

    GLCD_RGB_MODE_NONE

} GLCD_RGB_MODE;

typedef enum {

    GLCD_SIGNAL_POLARITY_NONE

} GLCD_SIGNAL_POLARITY;

typedef enum {

    GLCD_LAYER_ID_NONE

} GLCD_LAYER_ID;

typedef enum {

    GLCD_LAYER_COLOR_MODE_NONE

} GLCD_LAYER_COLOR_MODE;

typedef enum {

    GLCD_LAYER_SRC_BLEND_FUNC_NONE

} GLCD_LAYER_SRC_BLEND_FUNC;

typedef enum {

    GLCD_LAYER_DEST_BLEND_FUNC_NONE

} GLCD_LAYER_DEST_BLEND_FUNC;

typedef enum {

    GLCD_IRQ_TRIGGER_CONTROL_NONE

} GLCD_IRQ_TRIGGER_CONTROL;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_GLCD_ExistsRGBSequentialMode(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_RGBSequentialModeSet(GLCD_MODULE_ID index, GLCD_RGB_MODE mode)
{
     
}

PLIB_INLINE_API GLCD_RGB_MODE _PLIB_UNSUPPORTED PLIB_GLCD_RGBSequentialModeGet(GLCD_MODULE_ID index)
{
     return (GLCD_RGB_MODE)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsFormattingClockDivide(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_FormattingClockDivideEnable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_FormattingClockDivideDisable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_FormattingClockDivideIsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsYUVOutput(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_YUVOutputEnable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_YUVOutputDisable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_YUVOutputIsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsForceOutputBlank(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_ForceOutputBlankEnable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_ForceOutputBlankDisable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_ForceOutputBlankIsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsPaletteGammaRamp(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_PaletteGammaRampEnable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_PaletteGammaRampDisable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_PaletteGammaRampIsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsSignalPolarity(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_SignalPolaritySet(GLCD_MODULE_ID index, GLCD_SIGNAL_POLARITY polarity)
{
     
}

PLIB_INLINE_API GLCD_SIGNAL_POLARITY _PLIB_UNSUPPORTED PLIB_GLCD_SignalPolarityGet(GLCD_MODULE_ID index)
{
     return (GLCD_SIGNAL_POLARITY)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsSingleCyclePerLineVsync(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_SingleCyclePerLineVsyncEnable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_SingleCyclePerLineVsyncDisable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_SingleCyclePerLineVsyncIsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsDithering(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_DitheringEnable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_DitheringDisable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_DitheringIsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsCursor(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_CursorEnable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_CursorDisable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_CursorIsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsEnable(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_Enable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_Disable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_IsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsClockDivider(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_ClockDividerSet(GLCD_MODULE_ID index, uint32_t clockDivider)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_ClockDividerGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLinesPrefetch(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LinesPrefetchSet(GLCD_MODULE_ID index, uint32_t linesPrefetch)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_LinesPrefetchGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsBackgroundColor(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_BackgroundColorSet(GLCD_MODULE_ID index, uint32_t bgColor)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_BackgroundColorGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsResolutionXY(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_ResolutionXYSet(GLCD_MODULE_ID index, uint32_t resolutionX, uint32_t resolutionY)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_ResolutionXGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_ResolutionYGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsFrontPorchXY(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_FrontPorchXYSet(GLCD_MODULE_ID index, uint32_t frontPorchX, uint32_t frontPorchY)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_FrontPorchXGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_FrontPorchYGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsBlankingXY(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_BlankingXYSet(GLCD_MODULE_ID index, uint32_t blankingX, uint32_t blankingY)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_BlankingXGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_BlankingYGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsBackPorchXY(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_BackPorchXYSet(GLCD_MODULE_ID index, uint32_t backPorchX, uint32_t backPorchY)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_BackPorchXGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_BackPorchYGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsCursorXY(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_CursorXYSet(GLCD_MODULE_ID index, uint32_t cursorX, uint32_t cursorY)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_CursorXGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_CursorYGet(GLCD_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerColorMode(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerColorModeSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, GLCD_LAYER_COLOR_MODE colorMode)
{
     
}

PLIB_INLINE_API GLCD_LAYER_COLOR_MODE _PLIB_UNSUPPORTED PLIB_GLCD_LayerColorModeGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (GLCD_LAYER_COLOR_MODE)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerSrcBlendFunc(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerSrcBlendFuncSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, GLCD_LAYER_SRC_BLEND_FUNC blendFunc)
{
     
}

PLIB_INLINE_API GLCD_LAYER_SRC_BLEND_FUNC _PLIB_UNSUPPORTED PLIB_GLCD_LayerSrcBlendFuncGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (GLCD_LAYER_SRC_BLEND_FUNC)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerDestBlendFunc(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerDestBlendFuncSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, GLCD_LAYER_DEST_BLEND_FUNC blendFunc)
{
     
}

PLIB_INLINE_API GLCD_LAYER_DEST_BLEND_FUNC _PLIB_UNSUPPORTED PLIB_GLCD_LayerDestBlendFuncGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (GLCD_LAYER_DEST_BLEND_FUNC)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerGlobalAlpha(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerGlobalAlphaSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint8_t value)
{
     
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_GLCD_LayerGlobalAlphaGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerPreMultiplyImageAlpha(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerPreMultiplyImageAlphaEnable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerPreMultiplyImageAlphaDisable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_LayerPreMultiplyImageAlphaIsEnabled(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerForceWithGlobalAlpha(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerForceWithGlobalAlphaEnable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerForceWithGlobalAlphaDisable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_LayerForceWithGlobalAlphaIsEnabled(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerBilinearFilterEnable(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerBilinearFilterEnable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerBilinearFilterDisable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_LayerBilinearFilterIsEnabled(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerEnable(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerEnable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerDisable(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_LayerIsEnabled(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerStartXY(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerStartXYSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t startX, uint32_t startY)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_LayerStartXGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (uint32_t)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_LayerStartYGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerSizeXY(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerSizeXYSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t sizeX, uint32_t sizeY)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_LayerSizeXGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (uint32_t)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_LayerSizeYGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerBaseAddress(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerBaseAddressSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t baseAddress)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_LayerBaseAddressGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerStride(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerStrideSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t stride)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_LayerStrideGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsLayerResXY(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_LayerResXYSet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId, uint32_t resolutionX, uint32_t resolutionY)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_LayerResXGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (uint32_t)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_LayerResYGet(GLCD_MODULE_ID index, GLCD_LAYER_ID layerId)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsHSyncInterruptEnable(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_HSyncInterruptEnable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_HSyncInterruptDisable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_HSyncInterruptIsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsVSyncInterruptEnable(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_VSyncInterruptEnable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_VSyncInterruptDisable(GLCD_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_VSyncInterruptIsEnabled(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsIRQTriggerControl(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_IRQTriggerControlSet(GLCD_MODULE_ID index, GLCD_IRQ_TRIGGER_CONTROL irqControl)
{
     
}

PLIB_INLINE_API GLCD_IRQ_TRIGGER_CONTROL _PLIB_UNSUPPORTED PLIB_GLCD_IRQTriggerControlGet(GLCD_MODULE_ID index)
{
     return (GLCD_IRQ_TRIGGER_CONTROL)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsIsVerticalBlankingActive(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_IsVerticalBlankingActive(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsDESignalLevel(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_DESignalLevelGet(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsHSyncSignalLevel(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_HSyncSignalLevelGet(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsVSyncSignalLevel(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_VSyncSignalLevelGet(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsIsLastRow(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_GLCD_IsLastRow(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsGlobalColorLUT(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_GlobalColorLUTSet(GLCD_MODULE_ID index, uint32_t* globalLUT)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_GlobalColorLUTGet(GLCD_MODULE_ID index, uint32_t lutIndex)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsCursorData(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_CursorDataSet(GLCD_MODULE_ID index, uint32_t* cursorData)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_CursorDataGet(GLCD_MODULE_ID index, uint32_t dataIndex)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_GLCD_ExistsCursorLUT(GLCD_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_GLCD_CursorLUTSet(GLCD_MODULE_ID index, uint32_t* cursorLUT)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_GLCD_CursorLUTGet(GLCD_MODULE_ID index, uint32_t lutIndex)
{
     return (uint32_t)0;
}

#endif
