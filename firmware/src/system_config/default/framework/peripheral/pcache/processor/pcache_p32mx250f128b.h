/* Created by plibgen $Revision: 1.31 $ */

#ifndef _PCACHE_P32MX250F128B_H
#define _PCACHE_P32MX250F128B_H

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

    PCACHE_NUMBER_OF_MODULES = 0

} PCACHE_MODULE_ID;

typedef enum {

    PLIB_PCACHE_PREFETCH_ENABLE_NONE

} PLIB_PCACHE_PREFETCH_ENABLE;

typedef enum {

    PLIB_PCACHE_DATA_ENABLE_NONE

} PLIB_PCACHE_DATA_ENABLE;

typedef enum {

    PCACHE_CACHE_TYPE_NONE

} PCACHE_CACHE_TYPE;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_PCACHE_ExistsWaitState(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_WaitStateSet(PCACHE_MODULE_ID index, uint32_t clocks)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_WaitStateGet(PCACHE_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsPFMAddressWaitStateEnable(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_PFMAddressWaitStateEnable(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_PFMAddressWaitStateDisable(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_PFMAddressWaitStateIsEnabled(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCachePerformanceCountersEnable(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CachePerformanceCountersEnable(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CachePerformanceCountersDisable(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CachePerformanceCountersIsEnabled(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsPrefetchEnable(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_PrefetchEnableSet(PCACHE_MODULE_ID index, PLIB_PCACHE_PREFETCH_ENABLE region)
{
     
}

PLIB_INLINE_API PLIB_PCACHE_PREFETCH_ENABLE _PLIB_UNSUPPORTED PLIB_PCACHE_PrefetchEnableGet(PCACHE_MODULE_ID index)
{
     return (PLIB_PCACHE_PREFETCH_ENABLE)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsDataCacheEnable(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_DataCacheEnableSet(PCACHE_MODULE_ID index, PLIB_PCACHE_DATA_ENABLE dcache_en)
{
     
}

PLIB_INLINE_API PLIB_PCACHE_DATA_ENABLE _PLIB_UNSUPPORTED PLIB_PCACHE_DataCacheEnableGet(PCACHE_MODULE_ID index)
{
     return (PLIB_PCACHE_DATA_ENABLE)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheEnable(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheEnable(PCACHE_MODULE_ID index, PCACHE_CACHE_TYPE cache_type)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheDisable(PCACHE_MODULE_ID index, PCACHE_CACHE_TYPE cache_type)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CacheIsEnabled(PCACHE_MODULE_ID index, PCACHE_CACHE_TYPE cache_type)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsFlashSECInt(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECIntEnable(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECIntDisable(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsFlashDEDStatus(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_FlashDEDStatusGet(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashDEDStatusClear(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsFlashSECStatus(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECStatusGet(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECStatusSet(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECStatusClear(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsFlashSECCount(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECCountSet(PCACHE_MODULE_ID index, uint8_t count)
{
     
}

PLIB_INLINE_API uint8_t _PLIB_UNSUPPORTED PLIB_PCACHE_FlashSECCountGet(PCACHE_MODULE_ID index)
{
     return (uint8_t)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsInvalidateOnPFMProgram(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_InvalidateOnPFMProgramAll(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_InvalidateOnPFMProgramUnlocked(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsInvalidateCache(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_ForceInvalidateCacheEnable(PCACHE_MODULE_ID index, PCACHE_CACHE_TYPE cache_type)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_ForceInvalidateCacheIsEnabled(PCACHE_MODULE_ID index, PCACHE_CACHE_TYPE cache_type)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_AutoInvalidateCacheEnable(PCACHE_MODULE_ID index, PCACHE_CACHE_TYPE cache_type)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_AutoInvalidateCacheDisable(PCACHE_MODULE_ID index, PCACHE_CACHE_TYPE cache_type)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_AutoInvalidateCacheIsEnabled(PCACHE_MODULE_ID index, PCACHE_CACHE_TYPE cache_type)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLine(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineSelect(PCACHE_MODULE_ID index, uint32_t cache_line)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineDeselect(PCACHE_MODULE_ID index, uint32_t cache_line)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineData(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineInst(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineIsInst(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineType(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineLock(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineUnlock(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineIsLocked(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineLock(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineValid(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineInvalid(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineIsValid(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineValid(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineAddrSet(PCACHE_MODULE_ID index, uint32_t addr)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineAddrGet(PCACHE_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineAddr(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineFlashTypeBoot(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineFlashTypeInst(PCACHE_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineFlashTypeIsInst(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineFlashType(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineMaskSet(PCACHE_MODULE_ID index, uint32_t mask)
{
     
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_CacheLineMaskGet(PCACHE_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheLineMask(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_WordRead(PCACHE_MODULE_ID index, uint32_t word)
{
     return (uint32_t)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_WordWrite(PCACHE_MODULE_ID index, uint32_t word, uint32_t data)
{
     
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsWord(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_LeastRecentlyUsedStateRead(PCACHE_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsLeastRecentlyUsedState(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_CacheHitRead(PCACHE_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheHitWrite(PCACHE_MODULE_ID index, uint32_t data)
{
     
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheHit(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_CacheMissRead(PCACHE_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_CacheMissWrite(PCACHE_MODULE_ID index, uint32_t data)
{
     
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsCacheMiss(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_PCACHE_PrefetchAbortRead(PCACHE_MODULE_ID index)
{
     return (uint32_t)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PCACHE_PrefetchAbortWrite(PCACHE_MODULE_ID index, uint32_t data)
{
     
}

PLIB_INLINE_API bool PLIB_PCACHE_ExistsPrefetchAbort(PCACHE_MODULE_ID index)
{
     return (bool)0;
}

#endif
