/* Created by plibgen $Revision: 1.31 $ */

#ifndef _BMX_P32MX250F128B_H
#define _BMX_P32MX250F128B_H

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

    BMX_ID_0 = _BMX_BASE_ADDRESS,
    BMX_NUMBER_OF_MODULES = 1

} BMX_MODULE_ID;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/bmx_ArbitrationMode_Default.h"
#include "../templates/bmx_DataRamWaitState_Default.h"
#include "../templates/bmx_ProgramFlashMemoryCacheDma_Default.h"
#include "../templates/bmx_BusExceptionIXI_Default.h"
#include "../templates/bmx_BusExceptionICD_Default.h"
#include "../templates/bmx_BusExceptionDMA_Default.h"
#include "../templates/bmx_BusExceptionData_Default.h"
#include "../templates/bmx_BusExceptionInstruction_Default.h"
#include "../templates/bmx_ProgramFlashPartition_Default.h"
#include "../templates/bmx_DataRAMPartition_Default.h"
#include "../templates/bmx_ProgramFlashMemorySize_Default.h"
#include "../templates/bmx_DataRAMSize_Default.h"
#include "../templates/bmx_ProgramFlashBootSize_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_BMX_ExistsArbitrationMode(BMX_MODULE_ID index)
{
     return BMX_ExistsArbitrationMode_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_ArbitrationModeSet(BMX_MODULE_ID index, PLIB_BMX_ARB_MODE mode)
{
     BMX_ArbitrationModeSet_Default(index, mode);
}

PLIB_INLINE_API PLIB_BMX_ARB_MODE PLIB_BMX_ArbitrationModeGet(BMX_MODULE_ID index)
{
     return BMX_ArbitrationModeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsDataRamWaitState(BMX_MODULE_ID index)
{
     return BMX_ExistsDataRamWaitState_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_DataRamWaitStateSet(BMX_MODULE_ID index, PLIB_BMX_DATA_RAM_WAIT_STATES wait)
{
     BMX_DataRamWaitStateSet_Default(index, wait);
}

PLIB_INLINE_API PLIB_BMX_DATA_RAM_WAIT_STATES PLIB_BMX_DataRamWaitStateGet(BMX_MODULE_ID index)
{
     return BMX_DataRamWaitStateGet_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsProgramFlashMemoryCacheDma(BMX_MODULE_ID index)
{
     return BMX_ExistsProgramFlashMemoryCacheDma_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_ProgramFlashMemoryCacheDmaEnable(BMX_MODULE_ID index)
{
     BMX_ProgramFlashMemoryCacheDmaEnable_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_ProgramFlashMemoryCacheDmaDisable(BMX_MODULE_ID index)
{
     BMX_ProgramFlashMemoryCacheDmaDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionIXI(BMX_MODULE_ID index)
{
     return BMX_ExistsBusExceptionIXI_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionIXIEnable(BMX_MODULE_ID index)
{
     BMX_BusExceptionIXIEnable_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionIXIDisable(BMX_MODULE_ID index)
{
     BMX_BusExceptionIXIDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionICD(BMX_MODULE_ID index)
{
     return BMX_ExistsBusExceptionICD_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionICDEnable(BMX_MODULE_ID index)
{
     BMX_BusExceptionICDEnable_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionICDDisable(BMX_MODULE_ID index)
{
     BMX_BusExceptionICDDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionDMA(BMX_MODULE_ID index)
{
     return BMX_ExistsBusExceptionDMA_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionDMAEnable(BMX_MODULE_ID index)
{
     BMX_BusExceptionDMAEnable_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionDMADisable(BMX_MODULE_ID index)
{
     BMX_BusExceptionDMADisable_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionData(BMX_MODULE_ID index)
{
     return BMX_ExistsBusExceptionData_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionDataEnable(BMX_MODULE_ID index)
{
     BMX_BusExceptionDataEnable_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionDataDisable(BMX_MODULE_ID index)
{
     BMX_BusExceptionDataDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsBusExceptionInstruction(BMX_MODULE_ID index)
{
     return BMX_ExistsBusExceptionInstruction_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionInstructionEnable(BMX_MODULE_ID index)
{
     BMX_BusExceptionInstructionEnable_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_BusExceptionInstructionDisable(BMX_MODULE_ID index)
{
     BMX_BusExceptionInstructionDisable_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsProgramFlashPartition(BMX_MODULE_ID index)
{
     return BMX_ExistsProgramFlashPartition_Default(index);
}

PLIB_INLINE_API size_t PLIB_BMX_ProgramFlashPartitionGet(BMX_MODULE_ID index)
{
     return BMX_ProgramFlashPartitionGet_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_ProgramFlashPartitionSet(BMX_MODULE_ID index, size_t user_size)
{
     BMX_ProgramFlashPartitionSet_Default(index, user_size);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsDataRAMPartition(BMX_MODULE_ID index)
{
     return BMX_ExistsDataRAMPartition_Default(index);
}

PLIB_INLINE_API void PLIB_BMX_DataRAMPartitionSet(BMX_MODULE_ID index, size_t kernProgOffset, size_t userDataOffset, size_t userProgOffset)
{
     BMX_DataRAMPartitionSet_Default(index, kernProgOffset, userDataOffset, userProgOffset);
}

PLIB_INLINE_API size_t PLIB_BMX_DataRAMKernelProgramOffsetGet(BMX_MODULE_ID index)
{
     return BMX_DataRAMKernelProgramOffsetGet_Default(index);
}

PLIB_INLINE_API size_t PLIB_BMX_DataRAMUserDataOffsetGet(BMX_MODULE_ID index)
{
     return BMX_DataRAMUserDataOffsetGet_Default(index);
}

PLIB_INLINE_API size_t PLIB_BMX_DataRAMUserProgramOffsetGet(BMX_MODULE_ID index)
{
     return BMX_DataRAMUserProgramOffsetGet_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsProgramFlashMemorySize(BMX_MODULE_ID index)
{
     return BMX_ExistsProgramFlashMemorySize_Default(index);
}

PLIB_INLINE_API size_t PLIB_BMX_ProgramFlashMemorySizeGet(BMX_MODULE_ID index)
{
     return BMX_ProgramFlashMemorySizeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsDataRAMSize(BMX_MODULE_ID index)
{
     return BMX_ExistsDataRAMSize_Default(index);
}

PLIB_INLINE_API size_t PLIB_BMX_DataRAMSizeGet(BMX_MODULE_ID index)
{
     return BMX_DataRAMSizeGet_Default(index);
}

PLIB_INLINE_API bool PLIB_BMX_ExistsProgramFlashBootSize(BMX_MODULE_ID index)
{
     return BMX_ExistsProgramFlashBootSize_Default(index);
}

PLIB_INLINE_API size_t PLIB_BMX_ProgramFlashBootSizeGet(BMX_MODULE_ID index)
{
     return BMX_ProgramFlashBootSizeGet_Default(index);
}

#endif
