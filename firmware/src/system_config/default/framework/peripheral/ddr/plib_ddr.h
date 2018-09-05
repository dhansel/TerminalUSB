/*******************************************************************************
  Dual Data Rate (DDR) SDRAM Peripheral Library Interface Header

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ddr.h

  Summary:
    Defines the DDR Peripheral Library Interface.

  Description:
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the DDR
    Peripheral Library for Microchip microcontrollers. The definitions in this
    file are for the DDR module.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _PLIB_DDR_H
#define _PLIB_DDR_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Constants and Data Types
// *****************************************************************************
// *****************************************************************************

#define DDR_CMD_IDLE_NOP            0x00FFFFFF
#define DDR_CMD_PRECHARGE_ALL       0x00FFF401
#define DDR_CMD_REFRESH             0x00FFF801
#define DDR_CMD_LOAD_MODE           0x00FFF001

/*
typedef enum
{
    DDR_TARGET_CPU,
    DDR_TARGET_GC_IN,
    DDR_TARGET_GC_OUT,
    DDR_TARGET_GPU_IN,
    DDR_TARGET_GPU_OUT
} DDR_TARGET;

typedef enum
{
    DDR_PHY_ODT_75_OHM,
    DDR_PHY_ODT_150_OHM
} DDR_PHY_ODT;

typedef enum
{
    DDR_PHY_DRIVE_STRENGTH_60,
    DDR_PHY_DRIVE_STRENGTH_FULL
} DDR_PHY_DRIVE_STRENGTH;

typedef enum
{
    DDR_PHY_PREAMBLE_DLY_2_0,
    DDR_PHY_PREAMBLE_DLY_1_5,
    DDR_PHY_PREAMBLE_DLY_1_0
} DDR_PHY_PREAMBLE_DLY;

typedef enum
{
    DDR_PHY_SCL_BURST_MODE_4,
    DDR_PHY_SCL_BURST_MODE_8
} DDR_PHY_SCL_BURST_MODE;

typedef enum
{
    DDR_PHY_DDR_TYPE_DDR2,
    DDR_PHY_DDR_TYPE_DDR3
} DDR_PHY_DDR_TYPE;

typedef enum
{
    DDR_PHY_SCL_DELAY_SINGLE,
    DDR_PHY_SCL_DELAY_DOUBLE
} DDR_PHY_SCL_DELAY;

typedef enum
{
    DDR_HOST_CMD_REG_100,
    DDR_HOST_CMD_REG_101,
    DDR_HOST_CMD_REG_102,
    DDR_HOST_CMD_REG_103,
    DDR_HOST_CMD_REG_104,
    DDR_HOST_CMD_REG_105,
    DDR_HOST_CMD_REG_106,
    DDR_HOST_CMD_REG_107,
    DDR_HOST_CMD_REG_108,
    DDR_HOST_CMD_REG_109,
    DDR_HOST_CMD_REG_110,
    DDR_HOST_CMD_REG_111,
    DDR_HOST_CMD_REG_112,
    DDR_HOST_CMD_REG_113,
    DDR_HOST_CMD_REG_114,
    DDR_HOST_CMD_REG_115,
    DDR_HOST_CMD_REG_200,
    DDR_HOST_CMD_REG_201,
    DDR_HOST_CMD_REG_202,
    DDR_HOST_CMD_REG_203,
    DDR_HOST_CMD_REG_204,
    DDR_HOST_CMD_REG_205,
    DDR_HOST_CMD_REG_206,
    DDR_HOST_CMD_REG_207,
    DDR_HOST_CMD_REG_208,
    DDR_HOST_CMD_REG_209,
    DDR_HOST_CMD_REG_210,
    DDR_HOST_CMD_REG_211,
    DDR_HOST_CMD_REG_212,
    DDR_HOST_CMD_REG_213,
    DDR_HOST_CMD_REG_214,
    DDR_HOST_CMD_REG_215,
} DDR_HOST_CMD_REG;
*/

// *****************************************************************************
// *****************************************************************************
// Section: Includes
// *****************************************************************************
// *****************************************************************************
/* See the end of the file for implementation header include files.
*/

#include "peripheral/ddr/processor/ddr_processor.h"

// *****************************************************************************
// *****************************************************************************
// Section: Peripheral Library Interface Routines
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
/* Function:
    void PLIB_DDR_MinLimit(DDR_MODULE_ID index, uint8_t minLim, DDR_TARGET target)

  Summary:
    Sets the minimum number of bursts for a DDR target.

  Description:
    This function sets the minimum number of bursts (two cycles per burst) that 
	a target must have uninterrupted access to without interference from another 
	target.

  Precondition:
    The target must be selected with PLIB_DDR_TargetSelect prior to using this
    function.

  Parameters:
    index           - Identifier for the device instance to be configured
    minLim          - Number of bursts
    target          - Target for minLim setting

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_MinLimit(DDR_ID_0, 1, DDR_TARGET_CPU);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_MinLimit(DDR_MODULE_ID index, uint8_t minLim, DDR_TARGET target);


// *****************************************************************************
/* Function:
    void PLIB_DDR_ReqPeriod(DDR_MODULE_ID index, uint8_t reqPer, DDR_TARGET target)

  Summary:
    Sets the timeout for MINCMD number of bursts to be serviced for a DDR 
    target. 

  Description:
    This function sets the timeout for MINCMD number of bursts to be serviced for 
	a DDR target. Used with PLIB_DDR_MinCommand to determine the total bandwidth
    allocated to a target.

  Precondition:
    The target must be selected with PLIB_DDR_TargetSelect prior to using this
    function.

  Parameters:
    index           - Identifier for the device instance to be configured
    reqPer          - Number of clocks (multiplied by 4)
    target          - Target for reqPer setting

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_ReqPeriod(DDR_ID_0, 167, DDR_TARGET_CPU);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_ReqPeriod(DDR_MODULE_ID index, uint8_t reqPer, DDR_TARGET target);


// *****************************************************************************
/* Function:
    void PLIB_DDR_MinCommand(DDR_MODULE_ID index, uint8_t minCmd, DDR_TARGET target)

  Summary:
    Sets the minimum number of bursts to be serviced for a DDR target within
    (REQPER * 4) number of clocks.

  Description:
    This function sets the minimum number of bursts to be serviced for a DDR target 
	within (REQPER * 4) number of clocks.  Used with PLIB_DDR_ReqPeriod to determine 
    the total bandwidth allocated to a target.

  Precondition:
    The target must be selected with PLIB_DDR_TargetSelect() prior to using this
    function.

  Parameters:
    index           - Identifier for the device instance to be configured
    minCmd          - Number of bursts
    target          - Target for minCmd setting

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_MinCommand(DDR_ID_0, 83, DDR_TARGET_CPU);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_MinCommand(DDR_MODULE_ID index, uint8_t minCmd, DDR_TARGET target);


// *****************************************************************************
/* Function:
    void PLIB_DDR_RowAddressSet(DDR_MODULE_ID index, uint32_t rowShft, uint32_t rowMsk);

  Summary:
    Initializes the DDR controller memory configuration registers for row
    address.

  Description:
    this function initializes the DDR controller memory configuration registers for 
	the row address. The following register fields are programmed with this function:
    - RWADDR<4:0>      - DDRMEMCFG0<4:0>
    - RWADDRMASK<12:0> - DDRMEMCFG1<12:0>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    rowShft         - Number of bits to shift the row address
    rowMask         - Row address bit mask

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_RowAddressSet(DDR_ID_0, 12, 0x1FFF);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_RowAddressSet(DDR_MODULE_ID index, uint32_t rowShft, uint32_t rowMsk);


// *****************************************************************************
/* Function:
    void PLIB_DDR_ColumnAddressSet(DDR_MODULE_ID index, uint32_t colShft, uint32_t colMskLo, uint32_t colMskHi);

  Summary:
    Initializes the DDR controller memory configuration registers 
	for the column address.

  Description:
    This function initializes the DDR controller memory configuration registers 
	for  the column address. The following register fields are programmed with this 
	function:
    - CLHADDR<4:0>        - DDRMEMCFG0<28:24>
    - CLADDRHMSK<12:0>    - DDRMEMCFG2<12:0>
    - CLADDRLMSK<12:0>    - DDRMEMCFG3<12:0>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    colShft         - Number of bits to shift the column address
    colMaskLo       - Column address bit mask low
    colMaskHi       - Column address bit mask high

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_ColumnAddressSet(DDR_ID_0, 0, 0x1FF, 0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_ColumnAddressSet(DDR_MODULE_ID index, uint32_t colShft, uint32_t colMskLo, uint32_t colMskHi);


// *****************************************************************************
/* Function:
    void PLIB_DDR_BankAddressSet(DDR_MODULE_ID index, uint32_t bnkShft, uint32_t bnkMsk);

  Summary:
    Initializes the DDR controller memory configuration registers for bank
    address.

  Description:
    This function initializes the DDR controller memory configuration registers 
	for the bank address. The following register fields are programmed with this 
	function:
    - BNKADDR<4:0>        - DDRMEMCFG0<12:8>
    - BNKADDRMSK<2:0>     - DDRMEMCFG4<2:0>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    bnkShft         - Number of bits to shift the bank address
    bnkMsk          - Bank address bit mask

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_BankAddressSet(DDR_ID_0, 9, 0x03);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_BankAddressSet(DDR_MODULE_ID index, uint32_t bnkShft, uint32_t bnkMsk);


// *****************************************************************************
/* Function:
    void PLIB_DDR_ChipSelectAddressSet(DDR_MODULE_ID index, uint32_t csShft, uint32_t csMsk);

  Summary:
    Initializes the DDR controller memory configuration registers for Chip Select
    address.

  Description:
    This function initializes the DDR controller memory configuration registers for 
	the Chip Select address. The following register fields are programmed with this 
	function:
    - CSADDR<4:0>         - DDRMEMCFG0<20:16>
    - CSADDRMSK<2:0>      - DDRMEMCFG4<8:6>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    csShft          - Number of bits to shift the Chip Select address
    csMsk           - Chip select address bit mask

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_ChipSelectAddressSet(DDR_ID_0, 18, 0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_ChipSelectAddressSet(DDR_MODULE_ID index, uint32_t csShft, uint32_t csMsk);


// *****************************************************************************
/* Function:
    void PLIB_DDR_RefreshTimingSet(DDR_MODULE_ID index, uint32_t tRFC, uint32_t tRFI, 
	                               uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller refresh configuration.

  Description:
    This function initializes the DDR controller refresh configuration and programs 
	the refresh interval and delay between refreshes. The following register fields 
	are programmed with this function:
    - REFCNT<15:0>        - DDRREFCFG<15:0>
    - REFDLY<7:0>         - DDRREFCFG<23:16>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tRFC            - Refresh Cycle Time in clock cycles
    tRFI            - Refresh Interval in clock cycles
    ctrlClkPer      - DDR Controller clock period

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)

    #define tRFC            75000   // psec
    #define tRFI            7800000 // psec

    PLIB_DDR_RefreshConfig(DDR_ID_0, tRFC, tRFI, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_RefreshTimingSet(DDR_MODULE_ID index, uint32_t tRFC, uint32_t tRFI, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_MaxPendingRefSet(DDR_MODULE_ID index, uint8_t maxRefs);

  Summary:
    Initializes the DDR controller refresh configuration.

  Description:
    This function initializes the DDR controller refresh configuration and programs 
	the number of refreshes that may be pending at one time. The following register 
	field is programmed with this function:
    - MAXREFS<4:0>        - DDRREFCFG<24:26>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    maxRefs         - Maximum number of refreshes that may be pending at one time

  Returns:
    None.

  Example:
  <code>
    #define MAX_PEND_REF 7

    PLIB_DDR_MaxPendingRefSet(DDR_ID_0, MAX_PEND_REF);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_MaxPendingRefSet(DDR_MODULE_ID index, uint8_t maxRefs);


// *****************************************************************************
/* Function:
   void PLIB_DDR_AutoPowerDownEnable(DDR_MODULE_ID index);

  Summary:
    Enables the DDR controller to automatically enter Power-down mode.

  Description:
    This function enables the DDR controller to automatically enter Power-down mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_AutoPowerDownEnable(DDR_ID_0, pdd);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_AutoPowerDownEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
   void PLIB_DDR_AutoPowerDownDisable(DDR_MODULE_ID index);

  Summary:
    Prevents the DDR controller from automatically entering Power-down mode.

  Description:
    This function prevents the DDR controller from automatically entering 
	Power-down mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_AutoPowerDownDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_AutoPowerDownDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
   void PLIB_DDR_AutoSelfRefreshEnable(DDR_MODULE_ID index);

  Summary:
    Enables the DDR controller to automatically enter Self-refresh mode. 

  Description:
    This function enables the DDR controller to automatically enter Self-refresh mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_AutoSelfRefreshEnable(DDR_ID_0, srd);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_AutoSelfRefreshEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
   void PLIB_DDR_AutoSelfRefreshDisable(DDR_MODULE_ID index);

  Summary:
    Prevents the DDR controller from automatically entering Self-refresh mode.

  Description:
    This function prevents the DDR controller from automatically entering 
	Self-refresh mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_AutoSelfRefreshDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_AutoSelfRefreshDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
   void PLIB_DDR_AutoPchrgEnable(DDR_MODULE_ID index);

  Summary:
    Enables the DDR controller to issue an auto-precharge command to close 
    the bank at the end of every user command.

  Description:
    This function enables the DDR controller to issue a auto-precharge command 
	to close the bank at the end of every user command.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_AutoPchrgEnable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_AutoPchrgEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
   void PLIB_DDR_AutoPchrgDisable(DDR_MODULE_ID index);

  Summary:
    Prevents the DDR controller from issuing an auto-precharge command to close 
    the bank at the end of every user command.

  Description:
    This function prevents the DDR controller from issuing a auto-precharge 
	command to close the bank at the end of every user command.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_AutoPchrgDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_AutoPchrgDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
   void PLIB_DDR_AutoPchrgPowerDownDisable(DDR_MODULE_ID index);

  Summary:
    Prevents the DDR controller from automatically entering Precharge Power-down mode.

  Description:
    This function prevents the DDR controller from automatically entering Precharge 
	Power-down mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_AutoPchrgPowerDownDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_AutoPchrgPowerDownDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
   void PLIB_DDR_AutoPchrgPowerDownEnable(DDR_MODULE_ID index);

  Summary:
    Enables the DDR controller to automatically enter Precharge Power-down mode.

  Description:
    This function enables the DDR controller to automatically enter Precharge 
	Power-down mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_AutoPchrgPowerDownEnable(DDR_ID_0);
  </code>
I
  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_AutoPchrgPowerDownEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_ReadWriteDelaySet(DDR_MODULE_ID index, uint8_t bLen, 
                                     uint8_t wLat, uint8_t rLat);

  Summary:
    Initializes the DDR controller with the read/write delays needed for the
    specific DDR in use.

  Description:
    This function initializes the DDR controller with the read/write delays for 
	the specific DDR in use. The following register fields are programmed with 
	this function:
    - R2WDLY<3:0>     - DDRDLYCFG0<27:24>
    - RMWDLY<3:0>     - DDRDLYCFG0<31:28>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    bLen            - Burst length in cycles (BL)
    wLat            - Write latency in cycles (WL)
    rLat            - Read latency in cycles (RL)

  Returns:
    None.

  Example:
  <code>
    #define BL  2
    #define WL  4
    #define RL  5
    PLIB_DDR_ReadWriteDelaySet(DDR_ID_0 BL, WL, RL);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_ReadWriteDelaySet(DDR_MODULE_ID index, uint8_t bLen, uint8_t wLat, uint8_t rLat);


// *****************************************************************************
/* Function:
    void PLIB_DDR_WriteReadDelaySet(DDR_MODULE_ID index, uint32_t tWTR, 
                                    uint8_t bLen, uint8_t wLat, uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the read/write delays needed for the
    specific DDR in use.

  Description:
    This function initializes the DDR controller with the read/write delays for 
	the specific  DDR in use. The following register fields are programmed with 
	this function:
    - W2RDLY<4:0>     - DDRDLYCFG0<3:0>, DDRDLYCFG1<27>
    - W2RCSDLY<4:0>   - DDRDLYCFG0<7:4>, DDRDLYCFG1<28>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tWTR            - Write to read latency (in psecs)
    bLen            - Burst length in cycles (BL)
    wLat            - Write latency in cycles (WL)
    ctrlClkPer      - Control clock period (psec)

  Returns:
    None.

  Example:
  <code>
    #define CLK_PERIOD          2500 // psec
    #define CTRL_CLK_PERIOD     (CLK_PERIOD * 2)
    #define tWTR                7500

    PLIB_DDR_WriteReadDelaySet(DDR_ID_0, tWTR, 2, 4, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_WriteReadDelaySet(DDR_MODULE_ID index, uint32_t tWTR, uint8_t bLen, uint8_t wLat, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_ReadReadDelaySet(DDR_MODULE_ID index, uint8_t bLen);

  Summary:
    Initializes the DDR controller with the read/write delays needed for the
    specific DDR in use.

  Description:
    This function initializes the DDR controller with the read/write delays for 
	the specific DDR in use. The following register fields are programmed with 
	this function:
    - R2RDLY<3:0>     - DDRDLYCFG0<11:8>
    - R2RCSDLY<3:0>   - DDRDLYCFG0<15:12>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    bLen            - Burst length in cycles (BL)

  Returns:
    None.

  Example:
  <code>
    #define BL  2
    PLIB_DDR_ReadReadDelaySet(DDR_ID_0, BL);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_ReadReadDelaySet(DDR_MODULE_ID index, uint8_t bLen);


// *****************************************************************************
/* Function:
    void PLIB_DDR_WriteWriteDelaySet(DDR_MODULE_ID index, uint8_t bLen);

  Summary:
    Initializes the DDR controller with the read/write delays needed for the
    specific DDR in use.

  Description:
    This function initializes the DDR controller with the read/write delays for 
	the specific DDR in use. The following register fields are programmed with 
	this function:
    - W2WDLY<3:0>     - DDRDLYCFG0<19:16>
    - W2WCSDLY<3:0>   - DDRDLYCFG0<23:20>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    bLen            - Burst length in cycles (BL)

  Returns:
    None.

  Example:
  <code>
    #define BL  2
    PLIB_DDR_WriteWriteDelaySet(DDR_ID_0, BL);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_WriteWriteDelaySet(DDR_MODULE_ID index, uint8_t bLen);


// *****************************************************************************
/* Function:
    void PLIB_DDR_SelfRefreshDelaySet(DDR_MODULE_ID index, uint32_t slfRefDly, 
	                                  uint32_t tCKE, uint32_t tDLLK);

  Summary:
    Initializes the DDR controller with the self-refresh delays needed for the
    specific DDR in use.

  Description:
    This function initializes the DDR controller with the self-refresh delays for 
	the specific DDR in use. The following register fields are programmed with 
	this function:
    - SLFREFDLY<9:0>        - DDRPWRCFG<21:12>
    - SLFREFMINDLY<7:0>     - DDRDLYCFG1<7:0>
    - SLFREFEXDLY<8:0>      - DDRDLYCFG1<15:8>, DDR2DLYCFG1<30>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    slfRefDly       - Self refresh delay in number of clock cycles divided 
                      by 1024 (e.g., 1 = 1024 clocks, 2 = 2048 clocks, etc.)
    tCKE            - Power down minimum delay in cycles (tCKE) 
    tDLLK           - DLL lock delay time in cycles (tDLLK)

  Returns:
    None.

  Example:
  <code>
    #define SELF_REF_DLY        17
    #define tCKE                3
    PLIB_DDR_SelfRefreshDelaySet(DDR_ID_0, SELF_REF_DLY, tCKE, 85);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_SelfRefreshDelaySet(DDR_MODULE_ID index, uint32_t slfRefDly, uint32_t tCKE, uint32_t tDLLK);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PowerDownDelaySet(DDR_MODULE_ID index, uint32_t pwrDnDly, 
	                                uint32_t tCKE, uint32_t tXP);

  Summary:
    Initializes the DDR controller with the power down delays needed for the
    specific DDR in use.

  Description:
    This function initializes the DDR controller with the power down delays for 
	the DDR in use. The folPowerDownDelaySetlowing register fields are programmed 
	with this function:
    - PWRDNDLY<7:0>        - DDRPWRCFG<11:4>
    - PWRDNMINDLY<3:0>     - DDR2DLYCFG1<19:16>
    - PWRDNEXDLY<5:0>      - DDR2DLYCFG1<25:20>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    pwrDnDly        - Power down delay (entry) in cycles
    tCKE            - Power down minimum delay in cycles (tCKE) 
    tXP             - Power down exit delay in cycles (tXP)

  Returns:
    None.

  Example:
  <code>
    #define CLK_PERIOD          2500 // psec
    #define CTRL_CLK_PERIOD     (CLK_PERIOD * 2)
    #define PWR_DN_DLY          8
    #define tCKE                3
    #define tXP                 2

    PLIB_DDR_PowerDownDelaySet(DDR_ID_0, PWR_DN_DLY, tCKE, tXP);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PowerDownDelaySet(DDR_MODULE_ID index,  uint32_t pwrDnDly, uint32_t tCKE, uint32_t tXP);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PrechargAllBanksSet(DDR_MODULE_ID index, uint32_t tRP, uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the read/write precharge delays needed 
    for the specific DDR in use.

  Description:
    This function initializes the DDR controller with the read/write precharge 
	delays for the DDR in use. The following register fields are programmed 
	with this function:
    - PCHRGALLDLY<3:0>     - DDRDLYCFG2<3:0>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tRP             - Precharge to active delay (psec)
    ctrlClkPer      - DDR Controller clock period (psec)

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)
    #define tRP             12500   // psec

    PLIB_DDR_PrechargAllBanksSet(DDR_ID_0, tRP, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PrechargAllBanksSet(DDR_MODULE_ID index, uint32_t tRP, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_ReadToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tRTP, 
	                                      uint8_t bLen, uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the read/write precharge delays needed 
    for the specific DDR in use.

  Description:
    This function initializes the DDR controller with the read/write precharge 
	delays for the DDR in use. The following register fields are programmed 
	with this function:
    - R2PCHRGDLY<3:0>      - DDRDLYCFG2<11:8>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tRTP            - Read to precharge delay (psec)
    bLen            - Burst length in cycles (BL)
    ctrlClkPer      - DDR Controller clock period (psec)

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)
    #define tRTP            7500    // psec
    #define BL              2

    PLIB_DDR_ReadToPrechargeDelaySet(DDR_ID_0, tRTP, BL, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_ReadToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tRTP, uint8_t bLen, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_WriteToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tWR, 
	                        uint8_t bLen, uint8_t wLat, uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the read/write precharge delays needed 
    for the specific DDR in use.

  Description:
    This function initializes the DDR controller with the read/write precharge 
	delays for the DDR in use. The following register fields are programmed 
	with this function:
    - W2PCHRGDLY<4:0>      - DDRDLYCFG2<15:12>, DDRDLYCFG1<26>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tWR             - Write recovery delay (psec)
    bLen            - Burst length in cycles (BL)
    wLat            - Write latency in cycles (WL)
    ctrlClkPer      - DDR Controller clock period (psec)

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)
    #define tRTP            7500    // psec
    #define BL              2
    #define wLat            4

    PLIB_DDR_WriteToPrechargeDelaySet(DDR_ID_0, tRTP, BL, wLat, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_WriteToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tWR, uint8_t bLen, uint8_t wLat, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PrechargeToRASDelaySet(DDR_MODULE_ID index, uint32_t tRP, 
	                                     uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the read/write precharge delays needed 
    for the specific DDR in use.

  Description:
    This function initializes the DDR controller with the read/write precharge 
	delays for the DDR in use. The following register fields are programmed 
	with this function:
    - PCHRG2RASDLY<3:0>    - DDRDLYCFG2<24:27>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tRP             - Precharge to active delay (psec)
    ctrlClkPer      - DDR Controller clock period

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)
    #define tRP             12500   // psec

    PLIB_DDR_PrechargeToRASDelaySet(DDR_ID_0, tRP, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PrechargeToRASDelaySet(DDR_MODULE_ID index, uint32_t tRP, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_RASToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tRAS, uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the read/write precharge delays needed 
    for the specific DDR in use.

  Description:
    This function initializes the DDR controller with the read/write precharge 
	delays for the DDR in use. The following register fields are programmed 
	with this function:
    - RAS2PCHRGDLY<4:0>    - DDRDLYCFG3<4:0>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tRAS            - Active to Precharge delay (psec)
    ctrlClkPer      - DDR Controller clock period (psec)

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)
    #define tRAS            45000   // psec

    PLIB_DDR_RASToPrechargeDelaySet(DDR_ID_0, tRAS, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_RASToPrechargeDelaySet(DDR_MODULE_ID index, uint32_t tRAS, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_RASToRASBankDelaySet(DDR_MODULE_ID index, uint32_t tRC, uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the row/column address delays needed 
    for the specific DDR in use.

  Description:
    This function initializes the DDR controller with the row/column address 
	delays for the DDR in use. The following register fields are programmed 
	with this function:
    - RAS2RASSBNKDLY<5:0>  - DDRDLYCFG3<13:8>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tRC             - Row cycle time (psec)
    ctrlClkPer      - DDR Controller clock period (psec)

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)
    #define tRC             57500   // psec

    PLIB_DDR_RASToRASBankDelaySet(DDR_ID_0, tRC, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_RASToRASBankDelaySet(DDR_MODULE_ID index, uint32_t tRC, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_RASToRASDelaySet(DDR_MODULE_ID index, uint32_t tRRD, uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the row/column address delays needed 
    for the specific DDR in use.

  Description:
    This function initializes the DDR controller with the row/column address delays 
	for the DDR in use. The following register fields are programmed with this function:
    - RAS2RASDLY<3:0>      - DDRDLYCFG2<19:16>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tRRD            - RAS to RAS delay (psec)
    ctrlClkPer      - DDR Controller clock period (psec)

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)
    #define tRRD            7500    // psec

    PLIB_DDR_RASToRASDelaySet(DDR_ID_0, tRRD, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_RASToRASDelaySet(DDR_MODULE_ID index, uint32_t tRRD, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_RASToCASDelaySet(DDR_MODULE_ID index, uint32_t tRCD, 
	                               uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the row/column address delays needed 
    for the specific DDR in use.

  Description:
    This function initializes the DDR controller with the row/column address 
	delays for the DDR in use. The following register fields are programmed 
	with this function:
    - RAS2CASDLY<3:0>      - DDRDLYCFG2<23:20>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tRCD            - RAS to CAS delay (psec)
    ctrlClkPer      - DDR Controller clock period (psec)

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)
    #define tRCD            12500   // psec

    PLIB_DDR_RASToCASDelaySet(DDR_ID_0, tRCD, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_RASToCASDelaySet(DDR_MODULE_ID index, uint32_t tRCD, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_DataDelaySet(DDR_MODULE_ID index, uint8_t rLat, uint8_t wLat);

  Summary:
    Initializes the DDR controller with the data delays needed for the specific 
    DDR in use.

  Description:
    This function initializes the DDR controller with the data delays for the 
	DDR in use. The following register fields are programmed with this function:
    - RBENDDLY<3:0>        - DDRDLYCFG2<31:28>
    - NXTDATRQDLY<3:0>     - DDRXFERCFG<3:0>
    - NXTDATAVDLY<4:0>     - DDRXFERCFG<7:4>, DDRDLYCFG1<28>
    - RDATENDLY<3:0>       - DDRXFERCFG<19:16>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    rLat            - Read (CAS) latency in cycles (RL)
    wLat            - Write latency in cycles (WL)

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_DataDelaySet(DDR_ID_0, 5, 4);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_DataDelaySet(DDR_MODULE_ID index, uint8_t rLat, uint8_t wLat);


// *****************************************************************************
/* Function:
    void PLIB_DDR_TfawDelaySet(DDR_MODULE_ID index, uint32_t tFaw, uint32_t ctrlClkPer);

  Summary:
    Initializes the DDR controller with the four-bank activation window needed 
    for the specific DDR in use.

  Description:
    This function initializes the DDR controller with the four-bank activation window 
	for the DDR in use. The following register field is programmed with this function:
    - FAWTDLY<5:0>     - DDRDLYCFG3<21:16>

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    tFaw            - Four bank activation window (psec)
    ctrlClkPer      - DDR Controller clock period (psec)

  Returns:
    None.

  Example:
  <code>
    #define clock_period    2500    // psec
    #define CTRL_CLK_PERIOD (clock_period * 2)
    #define tFAW            35000   // psec

    PLIB_DDR_TfawDelaySet(DDR_ID_0, tFAW, CTRL_CLK_PERIOD);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_TfawDelaySet(DDR_MODULE_ID index, uint32_t tFaw, uint32_t ctrlClkPer);


// *****************************************************************************
/* Function:
    void PLIB_DDR_OdtReadEnable(DDR_MODULE_ID index, uint8_t odtCS);

  Summary:
    Selects which Chip Select to enable ODT for data reads. 

  Description:
    This function selects which Chip Select to enable ODT for data reads. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    odtCS           - Chip select to program ODT control value

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_OdtReadEnable(DDR_ID_0, 0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_OdtReadEnable(DDR_MODULE_ID index, uint8_t odtCS);


// *****************************************************************************
/* Function:
    void PLIB_DDR_OdtReadDisable(DDR_MODULE_ID index, uint8_t odtCS);

  Summary:
    Selects which Chip Select to disable ODT for data reads. 

  Description:
    This function selects which Chip Select to disable ODT for data reads. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    odtCS           - Chip select to program ODT control value

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_OdtReadDisable(DDR_ID_0, 0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_OdtReadDisable(DDR_MODULE_ID index, uint8_t odtCS);


// *****************************************************************************
/* Function:
    void PLIB_DDR_OdtWriteEnable(DDR_MODULE_ID index, uint8_t odtCS);

  Summary:
    Selects which Chip Select to enable ODT for data writes. 

  Description:
    This function selects which Chip Select to enable ODT for data writes. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    odtCS           - Chip select to program ODT control value

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_OdtWriteEnable(DDR_ID_0, 0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_OdtWriteEnable(DDR_MODULE_ID index, uint8_t odtCS);


// *****************************************************************************
/* Function:
    void PLIB_DDR_OdtWriteDisable(DDR_MODULE_ID index, uint8_t odtCS);

  Summary:
    Selects which Chip Select to disable ODT for data writes. 

  Description:
    This function selects which Chip Select to disable ODT for data writes. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    odtCS           - Chip select to program ODT control value

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_OdtWriteDisable(DDR_ID_0, 0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_OdtWriteDisable(DDR_MODULE_ID index, uint8_t odtCS);


// *****************************************************************************
/* Function:
    void PLIB_DDR_OdtWriteParamSet(DDR_MODULE_ID index, uint8_t wLen, uint8_t wDly);

  Summary:
    Sets the ODT parameters for data writes. 

  Description:
    This function sets the ODT parameters for data writes. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    wLen            - The number of clocks the ODT is turned on for writes
    wDly            - The number of clocks after a write command before
                      turning on ODT to the DDR

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_OdtWriteParamSet(DDR_ID_0, 3, 1);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_OdtWriteParamSet(DDR_MODULE_ID index, uint8_t wLen, uint8_t wDly);


// *****************************************************************************
/* Function:
    void PLIB_DDR_OdtReadParamSet(DDR_MODULE_ID index, uint8_t rLen, uint8_t rDly);

  Summary:
    Sets the ODT parameters for data reads. 

  Description:
    This function sets the ODT parameters for data reads. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    rLen            - The number of clocks the ODT is turned on for reads
    rDly            - The number of clocks after a read command before
                      turning on ODT to the DDR

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_OdtReadParamSet(DDR_ID_0, 2, 4);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_OdtReadParamSet(DDR_MODULE_ID index, uint8_t rLen, uint8_t rDly);


// *****************************************************************************
/* Function:
    void PLIB_DDR_BigEndianSet(DDR_MODULE_ID index);

  Summary:
    Sets the DDR data endianness to big. 

  Description:
    This function sets the DDR data endianness to big. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_BigEndianSet(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_BigEndianSet(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_LittleEndianSet(DDR_MODULE_ID index);

  Summary:
    Sets the DDR data endianness to little. 

  Description:
    This function sets the DDR data endianness to little. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_LittleEndianSet(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_LittleEndianSet(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_FullRateSet(DDR_MODULE_ID index);

  Summary:
    Sets the DDR controller to Full-rate mode. 

  Description:
    This function sets the DDR controller to Full-rate mode. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_FullRateSet(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_FullRateSet(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_HalfRateSet(DDR_MODULE_ID index);

  Summary:
    Sets the DDR controller to Half-rate mode. 

  Description:
    This function sets the DDR controller to Half-rate mode. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_HalfRateSet(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_HalfRateSet(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_MaxCmdBrstCntSet(DDR_MODULE_ID index, int8_t maxCmds);

  Summary:
    Sets the maximum number of commands that can be written to the controller
    in Burst mode. 

  Description:
    This function sets the maximum number of commands that can be written to the 
	controller in Burst mode. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    maxCmds         - Maximum number of commands that can be written to the
                      controller in burst mode

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_MaxCmdBrstCntSet(DDR_ID_0, 3);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_MaxCmdBrstCntSet(DDR_MODULE_ID index, int8_t maxCmds);


// *****************************************************************************
/* Function:
    void PLIB_DDR_NumHostCmdsSet(DDR_MODULE_ID index, int8_t numCmds);

  Summary:
    Sets the number of commands to be transmitted to the SDRAM.

  Description:
    This function sets the number of commands to be transmitted to the SDRAM.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    numCmds         - Number of commands to be transmitted to the SDRAM

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_NumHostCmdsSet(DDR_ID_0, 0x0B);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_NumHostCmdsSet(DDR_MODULE_ID index, int8_t numCmds);


// *****************************************************************************
/* Function:
    void PLIB_DDR_CmdDataWrite(DDR_MODULE_ID index, DDR_HOST_CMD_REG cmdReg, uint32_t cmdData);

  Summary:
    Writes an SDRAM command word to a command register in the controller.

  Description:
    This function writes an SDRAM command word to a command register in the 
	controller.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    cmdData         - 32-bit command data word
    cmdReg          - Command register

  Returns:
    None.

  Example:
  <code>
    #define DDR_CMD_IDLE_NOP 0x00FFFFFF
    PLIB_DDR_CmdDataWrite(DDR_ID_0, DDR_HOST_CMD_REG_100, DDR_CMD_IDLE_NOP);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_CmdDataWrite(DDR_MODULE_ID index, DDR_HOST_CMD_REG cmdReg, uint32_t cmdData);


// *****************************************************************************
/* Function:
    void PLIB_DDR_CmdDataValid(DDR_MODULE_ID index);

  Summary:
    Indicates to the controller that the data in the command registers is valid.

  Description:
    This function indicates to the controller that the data in the command registers 
	is valid.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_CmdDataValid(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_CmdDataValid(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_CmdDataSend(DDR_MODULE_ID index);

  Summary:
    Transmits the data in the command registers to the SDRAM.

  Description:
    This function transmits the data in the command registers to the SDRAM.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_CmdDataSend(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_CmdDataSend(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    bool PLIB_DDR_CmdDataIsComplete(DDR_MODULE_ID index);

  Summary:
    Returns the value of the valid bit in the DDR2CMDISSUE register. This bit is 
    cleared by hardware, when the SDRAM initialization data has been transmitted.

  Description:
    This function returns the value of the valid bit in the DDR2CMDISSUE register. 
	This bit is cleared by hardware, when the SDRAM initialization data has been 
	transmitted.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    while (PLIB_DDR_CmdDataIsComplete(DDR_ID_0));
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

bool PLIB_DDR_CmdDataIsComplete(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_ControllerEnable(DDR_MODULE_ID index);

  Summary:
    Enables the controller for normal operations after SDRAM is initialized.

  Description:
    This function enables the controller for normal operations after SDRAM is 
	initialized.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_ControllerEnable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_ControllerEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_OdtEnable(DDR_MODULE_ID index, DDR_PHY_ODT odtVal);

  Summary:
    Enables On Die Termination and sets the value.

  Description:
    This function enables On Die Termination (ODT) and sets the value.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    odtVal          - The ODT value

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_OdtEnable(DDR_ID_0, DDR_PHY_ODT_75_OHM);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_OdtEnable(DDR_MODULE_ID index, DDR_PHY_ODT odtVal);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_OdtDisable(DDR_MODULE_ID index);

  Summary:
    Disables On Die Termination.

  Description:
    This function disables On Die Termination.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_OdtDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_OdtDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_DataDriveStrengthSet(DDR_MODULE_ID index, DDR_PHY_DRIVE_STRENGTH drvStr);

  Summary:
    Sets the drive strength for the PHY data pads.

  Description:
    Sets the drive strength for the PHY data pads.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    drvStr          - Drive strength

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_DataDriveStrengthSet(DDR_ID_0, DDR_PHY_DRIVE_STRENGTH_FULL);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_DataDriveStrengthSet(DDR_MODULE_ID index, DDR_PHY_DRIVE_STRENGTH drvStr);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_AddCtlDriveStrengthSet(DDR_MODULE_ID index, DDR_PHY_DRIVE_STRENGTH drvStr);

  Summary:
    Sets the drive strength for the PHY address and control pads.

  Description:
    Sets the drive strength for the PHY address and control pads.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    drvStr          - Drive strength

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_AddCtlDriveStrengthSet(DDR_ID_0, DDR_PHY_DRIVE_STRENGTH_FULL);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_AddCtlDriveStrengthSet(DDR_MODULE_ID index, DDR_PHY_DRIVE_STRENGTH drvStr);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_OdtCal(DDR_MODULE_ID index, uint8_t puCal, uint8_t pdCal);

  Summary:
    Calibrates the pull-up and pull-down ODT impedance.

  Description:
    This function calibrates the pull-up and pull-down ODT impedance.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    puCal           - Pull-up calibration value
    pdCal           - Pull-down calibration value

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_OdtCal(DDR_ID_0, 2, 2);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_OdtCal(DDR_MODULE_ID index, uint8_t puCal, uint8_t pdCal);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_DrvStrgthCal(DDR_MODULE_ID index, uint8_t nFet, uint8_t pFet);

  Summary:
    Calibrates the pad NFET and PFET output impedance.

  Description:
    This function calibrates the pad NFET and PFET output impedance.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    nFet            - NFET impedance calibration value
    pFet            - PFET impedance calibration value

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_DrvStrgthCal(DDR_ID_0, 0xF, 0xF);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_DrvStrgthCal(DDR_MODULE_ID index, uint8_t nFet, uint8_t pFet);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_ExtraClockEnable(DDR_MODULE_ID index);

  Summary:
    Enables the drive pad for an extra clock cycle after a write burst.


  Description:
    This function enables the drive pad for an extra clock cycle after a write burst.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_ExtraClockEnable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_ExtraClockEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_ExtraClockDisable(DDR_MODULE_ID index);

  Summary:
    Does not enable the drive pad for an extra clock cycle after a write burst.

  Description:
    This function does not enable the drive pad for an extra clock cycle after 
	a write burst.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_ExtraClockDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_ExtraClockDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_InternalDllEnable(DDR_MODULE_ID index);

  Summary:
    Enables the use of the internal digital DLL.

  Description:
    This function enables the use of the internal digital DLL.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_InternalDllEnable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_InternalDllEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_ExternalDllEnable(DDR_MODULE_ID index);

  Summary:
    Enables the use of an external DLL.

  Description:
    This function enables the use of an external DLL.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_ExternalDllEnable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_ExternalDllEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_PadReceiveEnable(DDR_MODULE_ID index);

  Summary:
    Enables pad receivers on bidirectional I/O.

  Description:
    This function enables pad receivers on bidirectional I/O.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_PadReceiveEnable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_PadReceiveEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_PadReceiveDisable(DDR_MODULE_ID index);

  Summary:
    Disables pad receivers on bidirectional I/O.

  Description:
    This function disables pad receivers on bidirectional I/O.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_PadReceiveDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_PadReceiveDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_PreambleDlySet(DDR_MODULE_ID index, DDR_PHY_PREAMBLE_DLY preDly);

  Summary:
    Sets the length of the preamble for data writes.

  Description:
    This function sets the length of the preamble for data writes.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    preDly          - Preamble delay

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_PreambleDlySet(DDR_ID_0, DDR_PHY_PREAMBLE_DLY_1_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_PreambleDlySet(DDR_MODULE_ID index, DDR_PHY_PREAMBLE_DLY preDly);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_DllRecalibEnable(DDR_MODULE_ID index, uint32_t recalibCnt);

  Summary:
    Enables periodic recalibration of the internal digital DLL, and sets the 
    recalibration period.

  Description:
    This function enables periodic recalibration of the internal digital DLL, 
	and sets the recalibration period.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    recalibCnt      - Period of DLL recalibration in units of (PHY clock * 256)

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_DllRecalibEnable(DDR_ID_0, 100);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_DllRecalibEnable(DDR_MODULE_ID index, uint32_t recalibCnt);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_HalfRateSet(DDR_MODULE_ID index);

  Summary:
    Sets the PHY to half rate mode. 

  Description:
    This function sets the PHY to half rate mode.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_HalfRateSet(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_HalfRateSet(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_WriteCmdDelayEnable(DDR_MODULE_ID index);

  Summary:
    Enables write command delay. The extra delay is needed for devices with 
	even write latency (WL).

  Description:
    Enables write command delay. The extra delay is needed for devices with 
	even write latency (WL).

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_WriteCmdDelayEnable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_WriteCmdDelayEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_WriteCmdDelayDisable(DDR_MODULE_ID index);

  Summary:
    Disables write command delay. 

  Description:
    Disables write command delay. 

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_WriteCmdDelayDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_WriteCmdDelayDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_DllRecalibDisable(DDR_MODULE_ID index);

  Summary:
    Disables periodic recalibration of the internal digital DLL.

  Description:
    this function disables periodic recalibration of the internal digital DLL.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_DllRecalibDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_DllRecalibDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_DllMasterDelayStartSet(DDR_MODULE_ID index, uint8_t dlyStart);

  Summary:
    Sets the start value of the digital DLL master delay line.

  Description:
    This function sets the start value of the digital DLL master delay line.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    dlyStart        - 

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_DllMasterDelayStartSet(DDR_ID_0, 3);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_DllMasterDelayStartSet(DDR_MODULE_ID index, uint8_t dlyStart);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_SCLTestBurstModeSet(DDR_MODULE_ID index, DDR_PHY_SCL_BURST_MODE brstMode);

  Summary:
    Sets the burst mode of the DRAM while running SCL test.

  Description:
    This function sets the burst mode of the DRAM while running SCL test.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    brstMode        - Burst mode of the DRAM 

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_SCLTestBurstModeSet(DDR_ID_0, DDR_PHY_SCL_BURST_MODE_8);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_SCLTestBurstModeSet(DDR_MODULE_ID index, DDR_PHY_SCL_BURST_MODE brstMode);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_DDRTypeSet(DDR_MODULE_ID index, DDR_PHY_DDR_TYPE ddrType);

  Summary:
    Sets the DRAM type for the PHY.

  Description:
    This function sets the DRAM type for the PHY.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    ddrType         - DDR type (DDR2 or DDR3)

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_DDRTypeSet(DDR_ID_0, DDR_PHY_DDR_TYPE_DDR2);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_DDRTypeSet(DDR_MODULE_ID index, DDR_PHY_DDR_TYPE ddrType);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_ReadCASLatencySet(DDR_MODULE_ID index, uint8_t rLat);

  Summary:
    Sets the read CAS latency while running SCL test.

  Description:
    This function sets the read CAS latency while running SCL test.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    rLat            - Read CAS latency (RL)

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_ReadCASLatencySet(DDR_ID_0, 5);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_ReadCASLatencySet(DDR_MODULE_ID index, uint8_t rLat);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_WriteCASLatencySet(DDR_MODULE_ID index, uint8_t wLat);

  Summary:
    Sets the write CAS latency while running SCL test.

  Description:
    This function sets the write CAS latency while running SCL test.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    wLat            - Write CAS latency (WL)

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_WriteCASLatencySet(DDR_ID_0, 4);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_WriteCASLatencySet(DDR_MODULE_ID index, uint8_t wLat);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_OdtCSEnable(DDR_MODULE_ID index);

  Summary:
    Enables ODT on Chip Select while running SCL test.

  Description:
    This function enables ODT on Chip Select while running SCL test.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_OdtCSEnable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_OdtCSEnable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_OdtCSDisable(DDR_MODULE_ID index);

  Summary:
    Disables ODT on Chip Select while running SCL test.

  Description:
    This function disables ODT on Chip Select while running SCL test.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_OdtCSDisable(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_OdtCSDisable(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_SCLDelay(DDR_MODULE_ID index, DDR_PHY_SCL_DELAY sclDly);

  Summary:
    Disables ODT on Chip Select while running SCL test.

  Description:
    This function disables ODT on Chip Select while running SCL test.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    sclDly          - SCL delay

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_SCLDelay(DDR_ID_0, DDR_PHY_SCL_DELAY_SINGLE);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_SCLDelay(DDR_MODULE_ID index, DDR_PHY_SCL_DELAY sclDly);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_SCLDDRClkDelaySet(DDR_MODULE_ID index, uint8_t ddrDly);

  Summary:
    Sets DDR clock delay during SCL.

  Description:
    This function sets DDR clock delay during SCL.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    ddrDly          - DDR Clock delay

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_SCLDDRClkDelaySet(DDR_ID_0, 4);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_SCLDDRClkDelaySet(DDR_MODULE_ID index, uint8_t ddrDly);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_SCLCapClkDelaySet(DDR_MODULE_ID index, uint8_t capDly);

  Summary:
    Sets capture clock delay during SCL.

  Description:
    This function sets capture clock delay during SCL.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    capDly          - Capture Clock delay

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_SCLCapClkDelaySet(DDR_ID_0, 4);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_SCLCapClkDelaySet(DDR_MODULE_ID index, uint8_t capDly);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_SCLEnable(DDR_MODULE_ID index, uint8_t cs);

  Summary:
    Enables SCL on the Chip Select 'cs'.

  Description:
    This function enables SCL on the Chip Select 'cs'.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    cs              - Chip select

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_SCLEnable(DDR_ID_0, 0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_SCLEnable(DDR_MODULE_ID index, uint8_t cs);


// *****************************************************************************
/* Function:
    void PLIB_DDR_PHY_SCLStart(DDR_MODULE_ID index);

  Summary:
    Runs PHY Self Calibration.

  Description:
    This function runs PHY Self Calibration.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    None.

  Example:
  <code>
    PLIB_DDR_PHY_SCLStart(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

void PLIB_DDR_PHY_SCLStart(DDR_MODULE_ID index);


// *****************************************************************************
/* Function:
    bool PLIB_DDR_PHY_SCLStatus(DDR_MODULE_ID index);

  Summary:
    Checks status of PHY Self Calibration.

  Description:
    This function checks status of PHY Self Calibration.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured

  Returns:
    - true   - The PHY SCL has passed
    - false  - The PHY SCL has not passed

  Example:
  <code>
    PLIB_DDR_PHY_SCLStatus(DDR_ID_0);
  </code>

  Remarks:
    This feature is not available on all devices.  Refer to the specific device 
	data sheet to determine availability.
*/

bool PLIB_DDR_PHY_SCLStatus(DDR_MODULE_ID index);


// *****************************************************************************
// *****************************************************************************
// Section: DDR Peripheral Library Exists API Routines
// *****************************************************************************
// *****************************************************************************
/* The functions below indicate the existence of the features on the device. 
*/

//******************************************************************************
/* Function :  PLIB_DDR_ExistsArbitrationControl( DDR_MODULE_ID index )

  Summary:
    Identifies whether the ArbitrationControl feature exists on the DDR module. 

  Description:
    This function identifies whether the ArbitrationControl feature is available 
	on the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_TargetSelect
    - PLIB_DDR_MinLimit
    - PLIB_DDR_ReqPeriod
    - PLIB_DDR_MinCommand

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ArbitrationControl feature is supported on the device
    - false  - The ArbitrationControl feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsArbitrationControl( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsAddressMapping( DDR_MODULE_ID index )

  Summary:
    Identifies whether the AddressMapping feature exists on the DDR module. 

  Description:
    This function identifies whether the AddressMapping feature is available on 
	the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_RowAddressSet
    - PLIB_DDR_ColumnAddressSet
    - PLIB_DDR_BankAddressSet
    - PLIB_DDR_ChipSelectAddressSet

	Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The AddressMapping feature is supported on the device
    - false  - The AddressMapping feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsAddressMapping( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsRefreshConfig( DDR_MODULE_ID index )

  Summary:
    Identifies whether the RefreshConfig feature exists on the DDR module. 

  Description:
    This function identifies whether the RefreshConfig feature is available on 
	the DDR module.
    When this function returns true, this function is supported on the device: 
    - PLIB_DDR_RefreshConfig

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The RefreshConfig feature is supported on the device
    - false  - The RefreshConfig feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsRefreshConfig( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsAutoPowerDown( DDR_MODULE_ID index )

  Summary:
    Identifies whether the AutoPowerDown feature exists on the DDR module. 

  Description:
    This function identifies whether the AutoPowerDown feature is available on 
	the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_AutoPowerDownEnable
    - PLIB_DDR_AutoPowerDownDisable
	
  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The AutoPowerDown feature is supported on the device
    - false  - The AutoPowerDown feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsAutoPowerDown( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsAutoSelfRefresh( DDR_MODULE_ID index )

  Summary:
    Identifies whether the AutoSelfRefresh feature exists on the DDR module. 

  Description:
    This function identifies whether the AutoSelfRefresh feature is available on 
	the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_AutoSelfRefreshEnable
    - PLIB_DDR_AutoSelfRefreshDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The AutoSelfRefresh feature is supported on the device
    - false  - The AutoSelfRefresh feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsAutoSelfRefresh( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsAutoPrecharge( DDR_MODULE_ID index )

  Summary:
    Identifies whether the AutoPrecharge feature exists on the DDR module. 

  Description:
    This function identifies whether the AutoPrecharge feature is available on 
	the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_AutoPchrgEnable
    - PLIB_DDR_AutoPchrgDisable
    - PLIB_DDR_AutoPchrgPowerDownEnable
    - PLIB_DDR_AutoPchrgPowerDownDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The AutoPrecharge feature is supported on the device
    - false  - The AutoPrecharge feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsAutoPrecharge( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsTimingDelays( DDR_MODULE_ID index )

  Summary:
    Identifies whether the TimingDelays feature exists on the DDR module 

  Description:
    This function identifies whether the TimingDelays feature is available on the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_ReadWriteDelaySet
    - PLIB_DDR_SelfRefreshDelaySet
    - PLIB_DDR_PowerDownDelaySet
    - PLIB_DDR_PchrgDelaySet
    - PLIB_DDR_AddressDelaySet
    - PLIB_DDR_DataDelaySet
    - PLIB_DDR_TfawDelaySet
	
  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The TimingDelays feature is supported on the device
    - false  - The TimingDelays feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsTimingDelays( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsODTConfig( DDR_MODULE_ID index )

  Summary:
    Identifies whether the ODTConfig feature exists on the DDR module. 

  Description:
    This function identifies whether the ODTConfig feature is available on the 
	DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_OdtReadEnable
    - PLIB_DDR_OdtReadDisable
    - PLIB_DDR_OdtWriteEnable
    - PLIB_DDR_OdtWriteDisable
    - PLIB_DDR_OdtWriteParamSet
	
  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The ODTConfig feature is supported on the device
    - false  - The ODTConfig feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsODTConfig( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsDDRControllerConfig( DDR_MODULE_ID index )

  Summary:
    Identifies whether the DDRControllerConfig feature exists on the DDR module. 

  Description:
    This function identifies whether the DDRControllerConfig feature is available 
	on the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_BigEndianSet
    - PLIB_DDR_LittleEndianSet
    - PLIB_DDR_FullRateSet
    - PLIB_DDR_HalfRateSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DDRControllerConfig feature is supported on the device
    - false  - The DDRControllerConfig feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsDDRControllerConfig( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsDDRCommands( DDR_MODULE_ID index )

  Summary:
    Identifies whether the DDRCommands feature exists on the DDR module. 

  Description:
    This function identifies whether the DDRCommands feature is available on the 
	DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_MaxCmdBrstCntSet
    - PLIB_DDR_NumHostCmdsSet
    - PLIB_DDR_CmdDataWrite
    - PLIB_DDR_CmdDataValid
    - PLIB_DDR_CmdDataSend
    - PLIB_DDR_CmdDataIsComplete
    - PLIB_DDR_ControllerEnable
	
  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The DDRCommands feature is supported on the device
    - false  - The DDRCommands feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsDDRCommands( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsPHY_PadConfig( DDR_MODULE_ID index )

  Summary:
    Identifies whether the PHY_PadConfig feature exists on the DDR module. 

  Description:
    This function identifies whether the PHY_PadConfig feature is available on 
	the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_PHY_OdtEnable
    - PLIB_DDR_PHY_OdtDisable
    - PLIB_DDR_PHY_DriveStrengthSet
    - PLIB_DDR_PHY_OdtCal
    - PLIB_DDR_PHY_DrvStrgthCal
    - PLIB_DDR_PHY_ExtraClockEnable
    - PLIB_DDR_PHY_ExtraClockDisable
    - PLIB_DDR_PHY_InternalDllEnable
    - PLIB_DDR_PHY_ExternalDllEnable
    - PLIB_DDR_PHY_PadReceiveEnable
    - PLIB_DDR_PHY_PreambleDlySet
	
  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The PHY_PadConfig feature is supported on the device
    - false  - The PHY_PadConfig feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsPHY_PadConfig( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsPHY_DLLCalibration( DDR_MODULE_ID index )

  Summary:
    Identifies whether the PHY_DLLCalibration feature exists on the DDR module. 

  Description:
    This function identifies whether the PHY_DLLCalibration feature is available 
	on the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_PHY_DllRecalibEnable
    - PLIB_DDR_PHY_DllRecalibDisable
    - PLIB_DDR_PHY_DllMasterDelayStartSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The PHY_DLLCalibration feature is supported on the device
    - false  - The PHY_DLLCalibration feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsPHY_DLLCalibration( DDR_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_DDR_ExistsPHY_SCLConfig( DDR_MODULE_ID index )

  Summary:
    Identifies whether the PHY_SCLConfig feature exists on the DDR module 

  Description:
    This function identifies whether the PHY_SCLConfig feature is available on the DDR module.
    When this function returns true, these functions are supported on the device: 
    - PLIB_DDR_PHY_SCLTestBurstModeSet
    - PLIB_DDR_PHY_DDRTypeSet
    - PLIB_DDR_PHY_ReadCASLatencySet
    - PLIB_DDR_PHY_WriteCASLatencySet
    - PLIB_DDR_PHY_OdtCSEnable
    - PLIB_DDR_PHY_OdtCSDisable
    - PLIB_DDR_PHY_SCLDelay
    - PLIB_DDR_PHY_SCLEnable
    - PLIB_DDR_PHY_SCLDDRClkDelaySet
    - PLIB_DDR_PHY_SCLCapClkDelaySet
    - PLIB_DDR_PHY_SCLStart
    - PLIB_DDR_PHY_SCLStatus

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true   - The PHY_SCLConfig feature is supported on the device
    - false  - The PHY_SCLConfig feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_DDR_ExistsPHY_SCLConfig( DDR_MODULE_ID index );


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif //_PLIB_DDR_H

//******************************************************************************
/* End of File
*/
