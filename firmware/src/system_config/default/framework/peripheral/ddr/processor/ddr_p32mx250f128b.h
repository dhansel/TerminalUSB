/* Created by plibgen $Revision: 1.31 $ */

#ifndef _DDR_P32MX250F128B_H
#define _DDR_P32MX250F128B_H

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

    DDR_NUMBER_OF_MODULES = 0

} DDR_MODULE_ID;

typedef enum {

    DDR_TARGET_NONE

} DDR_TARGET;

typedef enum {

    DDR_PHY_ODT_NONE

} DDR_PHY_ODT;

typedef enum {

    DDR_PHY_DRIVE_STRENGTH_NONE

} DDR_PHY_DRIVE_STRENGTH;

typedef enum {

    DDR_PHY_PREAMBLE_DLY_NONE

} DDR_PHY_PREAMBLE_DLY;

typedef enum {

    DDR_PHY_SCL_BURST_MODE_NONE

} DDR_PHY_SCL_BURST_MODE;

typedef enum {

    DDR_PHY_DDR_TYPE_NONE

} DDR_PHY_DDR_TYPE;

typedef enum {

    DDR_PHY_SCL_DELAY_NONE

} DDR_PHY_SCL_DELAY;

typedef enum {

    DDR_HOST_CMD_REG_NONE

} DDR_HOST_CMD_REG;

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_MinLimit(DDR_MODULE_ID index, uint8_t minLim, DDR_TARGET target)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_ReqPeriod(DDR_MODULE_ID index, uint8_t reqPer, DDR_TARGET target)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_MinCommand(DDR_MODULE_ID index, uint8_t minCmd, DDR_TARGET target)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsArbitrationControl(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_RowAddressSet(DDR_MODULE_ID index, uint32_t rowShft, uint32_t rowMsk)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_ColumnAddressSet(DDR_MODULE_ID index, uint32_t colShft, uint32_t colMskLo, uint32_t colMskHi)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_BankAddressSet(DDR_MODULE_ID index, uint32_t bnkShft, uint32_t bnkMsk)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_ChipSelectAddressSet(DDR_MODULE_ID index, uint32_t csShft, uint32_t csMsk)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsAddressMapping(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_RefreshTimingSet(DDR_MODULE_ID index, uint32_t tRFC, uint32_t tRFI, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_MaxPendingRefSet(DDR_MODULE_ID index, uint8_t maxRefs)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsRefreshConfig(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_AutoPowerDownEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_AutoPowerDownDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsAutoPowerDown(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_AutoSelfRefreshEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_AutoSelfRefreshDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsAutoSelfRefresh(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_AutoPchrgEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_AutoPchrgDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_AutoPchrgPowerDownEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_AutoPchrgPowerDownDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsAutoPrecharge(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_ReadWriteDelaySet(DDR_MODULE_ID index, uint8_t bLen, uint8_t wLat, uint8_t rLat)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_WriteReadDelaySet(DDR_MODULE_ID index, uint32_t tWTR, uint8_t bLen, uint8_t wLat, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_ReadReadDelaySet(DDR_MODULE_ID index, uint8_t bLen)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_WriteWriteDelaySet(DDR_MODULE_ID index, uint8_t bLen)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_SelfRefreshDelaySet(DDR_MODULE_ID index, uint32_t slfRefDly, uint32_t tCKE, uint32_t tDLLK)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PowerDownDelaySet(DDR_MODULE_ID index, uint32_t pwrDnDly, uint32_t tCKE, uint32_t tXP)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PrechargAllBanksSet(DDR_MODULE_ID index, uint32_t tRP, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_ReadToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tRTP, uint8_t bLen, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_WriteToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tWR, uint8_t bLen, uint8_t wLat, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PrechargeToRASDelaySet(DDR_MODULE_ID index, uint32_t tRP, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_RASToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tRAS, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_RASToRASBankDelaySet(DDR_MODULE_ID index, uint32_t tRC, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_RASToRASDelaySet(DDR_MODULE_ID index, uint32_t tRRD, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_RASToCASDelaySet(DDR_MODULE_ID index, uint32_t tRCD, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_DataDelaySet(DDR_MODULE_ID index, uint8_t rLat, uint8_t wLat)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_TfawDelaySet(DDR_MODULE_ID index, uint32_t tFaw, uint32_t ctrlClkPer)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsTimingDelays(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_OdtReadEnable(DDR_MODULE_ID index, uint8_t odtCS)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_OdtReadDisable(DDR_MODULE_ID index, uint8_t odtCS)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_OdtWriteEnable(DDR_MODULE_ID index, uint8_t odtCS)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_OdtWriteDisable(DDR_MODULE_ID index, uint8_t odtCS)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_OdtWriteParamSet(DDR_MODULE_ID index, uint8_t wLen, uint8_t wDly)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_OdtReadParamSet(DDR_MODULE_ID index, uint8_t rLen, uint8_t rDly)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsODTConfig(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_BigEndianSet(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_LittleEndianSet(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_FullRateSet(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_HalfRateSet(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsDDRControllerConfig(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_MaxCmdBrstCntSet(DDR_MODULE_ID index, int8_t maxCmds)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_NumHostCmdsSet(DDR_MODULE_ID index, int8_t numCmds)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_CmdDataWrite(DDR_MODULE_ID index, DDR_HOST_CMD_REG cmdReg, uint32_t cmdData)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_CmdDataValid(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_CmdDataSend(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_DDR_CmdDataIsComplete(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_ControllerEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsDDRCommands(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_OdtEnable(DDR_MODULE_ID index, DDR_PHY_ODT odtVal)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_OdtDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_DataDriveStrengthSet(DDR_MODULE_ID index, DDR_PHY_DRIVE_STRENGTH drvStr)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_AddCtlDriveStrengthSet(DDR_MODULE_ID index, DDR_PHY_DRIVE_STRENGTH drvStr)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_OdtCal(DDR_MODULE_ID index, uint8_t puCal, uint8_t pdCal)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_DrvStrgthCal(DDR_MODULE_ID index, uint8_t nFet, uint8_t pFet)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_ExtraClockEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_ExtraClockDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_InternalDllEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_ExternalDllEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_PadReceiveEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_PadReceiveDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_PreambleDlySet(DDR_MODULE_ID index, DDR_PHY_PREAMBLE_DLY preDly)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_HalfRateSet(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_WriteCmdDelayEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_WriteCmdDelayDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsPHY_PadConfig(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_DllRecalibEnable(DDR_MODULE_ID index, uint32_t recalibCnt)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_DllRecalibDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_DllMasterDelayStartSet(DDR_MODULE_ID index, uint8_t dlyStart)
{
     
}

PLIB_INLINE_API bool PLIB_DDR_ExistsPHY_DLLCalibration(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_SCLTestBurstModeSet(DDR_MODULE_ID index, DDR_PHY_SCL_BURST_MODE brstMode)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_DDRTypeSet(DDR_MODULE_ID index, DDR_PHY_DDR_TYPE ddrType)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_ReadCASLatencySet(DDR_MODULE_ID index, uint8_t rLat)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_WriteCASLatencySet(DDR_MODULE_ID index, uint8_t wLat)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_OdtCSEnable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_OdtCSDisable(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_SCLDelay(DDR_MODULE_ID index, DDR_PHY_SCL_DELAY sclDly)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_SCLEnable(DDR_MODULE_ID index, uint8_t cs)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_SCLDDRClkDelaySet(DDR_MODULE_ID index, uint8_t ddrDly)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_SCLCapClkDelaySet(DDR_MODULE_ID index, uint8_t capDly)
{
     
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_DDR_PHY_SCLStart(DDR_MODULE_ID index)
{
     
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_DDR_PHY_SCLStatus(DDR_MODULE_ID index)
{
     return (bool)0;
}

PLIB_INLINE_API bool PLIB_DDR_ExistsPHY_SCLConfig(DDR_MODULE_ID index)
{
     return (bool)0;
}

#endif
