/*******************************************************************************
  Bus Matrix Peripheral Library Interface Header

  Company:      Microchip Technology Inc.

  File Name:    plib_bmx.h

  Summary:
    Defines the Bus Matrix (BMX) Peripheral Library interface

  Description:
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the Bus Matrix
    (BMX) Peripheral Library (PLIB) for Microchip microcontrollers.  The
    definitions in this file are for the bus matrix controller module.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright © 2013-2015 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PLIB_BMX_H
#define _PLIB_BMX_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Includes
// *****************************************************************************
// *****************************************************************************
/* See Bottom of file for implementation of header include files.
*/


// *****************************************************************************
/* Program Flash Partition Block Size

  Summary:
    Defines the minimum partition block size in program Flash memory.

  Description:
    This definition specifies the minimum partition block size in program Flash
    memory.

*/

#define PLIB_BMX_PFM_BLOCK_SIZE 2048


// *****************************************************************************
/* Program Flash Partition Block Size

  Summary:
    Defines the minimum partition block size in data RAM memory.

  Description:
    This definition specifies the minimum partition block size in data RAM
    memory.

*/

#define PLIB_BMX_DRM_BLOCK_SIZE 2048


// *****************************************************************************
/* Arbitration Mode

  Summary:
    Lists the possible arbitration modes for the bus matrix.

  Description:
    This enumeration lists the possible arbitration modes for the bus matrix.

*/

typedef enum {

    /* Arbitration Mode 0 */
    PLIB_BMX_ARB_MODE_INST,

    /* Arbitration Mode 1 */
    PLIB_BMX_ARB_MODE_DMA,

    /* Arbitration Mode 2 */
    PLIB_BMX_ARB_MODE_ROT

} PLIB_BMX_ARB_MODE;


// *****************************************************************************
/* Exception Bits

  Summary:
    Defines which events trigger a bus exception.
    
  Description:
    This definition specifies which events trigger a bus exception.

*/

typedef enum {

    /* IXI Shared Bus */
    PLIB_BMX_ERR_IXI /*DOM-IGNORE-BEGIN*/ = 1 << 20 /*DOM-IGNORE-END*/,

    /* In-Circuit Debugger */
    PLIB_BMX_ERR_ICD /*DOM-IGNORE-BEGIN*/ = 1 << 19 /*DOM-IGNORE-END*/,

    /* DMA Controller */
    PLIB_BMX_ERR_DMA /*DOM-IGNORE-BEGIN*/ = 1 << 18 /*DOM-IGNORE-END*/,

    /* CPU Data Bus */
    PLIB_BMX_ERR_DATA /*DOM-IGNORE-BEGIN*/ = 1 << 17 /*DOM-IGNORE-END*/,

    /* CPU Instruction Bus */
    PLIB_BMX_ERR_INST /*DOM-IGNORE-BEGIN*/ = 1 << 16 /*DOM-IGNORE-END*/

} PLIB_BMX_EXCEPTION_SRC;


// *****************************************************************************
/* Wait States

  Summary:
    Defines the number of data RAM wait states for address setup.
    
  Description:
    This definition specifies the number of data RAM wait states for address setup.

*/
typedef enum {

    /* Zero wait states for address setup */
    PLIB_BMX_DATA_RAM_WAIT_ZERO,

    /* One wait state for address setup */
    PLIB_BMX_DATA_RAM_WAIT_ONE

} PLIB_BMX_DATA_RAM_WAIT_STATES;


// DOM-IGNORE-BEGIN
#include "peripheral/bmx/processor/bmx_processor.h"
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Peripheral Library Interface Routines
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void PLIB_BMX_ArbitrationModeSet ( BMX_MODULE_ID index, 
                                       PLIB_BMX_ARB_MODE mode )

  Summary:
    Sets the bus matrix arbitration mode.

  Description:
    This function sets the bus matrix arbitration mode.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be configured
    mode  - Identifies the desired arbitration mode

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_ArbitrationModeSet(BMX_ID_0, PLIB_BMX_ARB_MODE_DMA);
    </code>

  Remarks:
    This function implements an operation of the ArbitrationMode feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsArbitrationMode in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_ArbitrationModeSet(BMX_MODULE_ID index, PLIB_BMX_ARB_MODE mode);


/*******************************************************************************
  Function:
    PLIB_BMX_ARB_MODE PLIB_BMX_ArbitrationModeGet ( BMX_MODULE_ID index )

  Summary:
    Returns the bus matrix arbitration mode.

  Description:
    This function returns the bus matrix arbitration mode.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be read

  Returns:
    PLIB_BMX_ARB_MODE enumerator value representing the arbitration mode.

  Example:
    <code>
    PLIB_BMX_ARB_MODE mode;
    mode = PLIB_BMX_ArbitrationModeGet(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the ArbitrationMode feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsArbitrationMode in your application 
    to automatically determine whether this feature is available.
*/

PLIB_BMX_ARB_MODE PLIB_BMX_ArbitrationModeGet(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_DataRamWaitStateSet( BMX_MODULE_ID index, 
                                        PLIB_BMX_DATA_RAM_WAIT_STATES wait )

  Summary:
    Sets the number of data RAM Wait states.

  Description:
    This function sets the number of data RAM Wait states.

  Precondition:
    None.

  Parameters:
    index                         - Identifier for the device instance to be configured
    PLIB_BMX_DATA_RAM_WAIT_STATES - Enumeration representing the number of Wait states

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_DataRamWaitStateSet(BMX_ID_0, PLIB_BMX_DATA_RAM_WAIT_ONE);
    </code>

  Remarks:
    This function implements an operation of the DataRamWaitState feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsDataRamWaitState in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_DataRamWaitStateSet(BMX_MODULE_ID index, PLIB_BMX_DATA_RAM_WAIT_STATES wait);


/*******************************************************************************
  Function:
    PLIB_BMX_DATA_RAM_WAIT_STATES PLIB_BMX_DataRamWaitStateGet( BMX_MODULE_ID index )

  Summary:
    Returns the number of data RAM Wait states.

  Description:
    This function returns the number of data RAM Wait states.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be read

  Returns:
    PLIB_BMX_DATA_RAM_WAIT_STATES enumeration representing the number of wait 
    states.

  Example:
    <code>
    PLIB_BMX_DATA_RAM_WAIT_STATES wait;
    wait = PLIB_BMX_DataRamWaitStateGet(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the DataRamWaitState feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsDataRamWaitState in your application 
    to automatically determine whether this feature is available.
*/

PLIB_BMX_DATA_RAM_WAIT_STATES PLIB_BMX_DataRamWaitStateGet( BMX_MODULE_ID index );


/*******************************************************************************
  Function:
    void PLIB_BMX_ProgramFlashMemoryCacheDmaEnable( BMX_MODULE_ID index )

  Summary:
    Enables the bus matrix program Flash cacheability for DMA.

  Description:
    This function enables the program Flash cacheability for DMA.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be enabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_ProgramFlashMemoryCacheDmaEnable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the ProgramFlashMemoryCacheDma feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsProgramFlashMemoryCacheDma in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_ProgramFlashMemoryCacheDmaEnable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_ProgramFlashMemoryCacheDmaDisable( BMX_MODULE_ID index )

  Summary:
    Disables the bus matrix program Flash cacheability for DMA.

  Description:
    This function disables the program Flash cacheability for DMA.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be disabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_ProgramFlashMemoryCacheDmaDisable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the ProgramFlashMemoryCacheDma feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsProgramFlashMemoryCacheDma in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_ProgramFlashMemoryCacheDmaDisable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionICDEnable( BMX_MODULE_ID index )

  Summary:
    Enables the ICD bus exception.

  Description:
    This function enables the ICD bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be enabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionICDEnable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionICD feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionICD in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionICDEnable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionICDDisable( BMX_MODULE_ID index )

  Summary:
    Disables the ICD bus exception.

  Description:
    This function disables the ICD bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be disabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionICDDisable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionICD feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionICD in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionICDDisable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionIXIEnable( BMX_MODULE_ID index )

  Summary:
    Enables the IXI bus exception.

  Description:
    This function enables the IXI bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be enabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionIXIEnable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionIXI feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionIXI in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionIXIEnable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionIXIDisable( BMX_MODULE_ID index )

  Summary:
    Disables the IXI bus exception.

  Description:
    This function disables the IXI bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be disabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionIXIDisable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionIXI feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionIXI in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionIXIDisable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionDMAEnable( BMX_MODULE_ID index )

  Summary:
    Enables the DMA bus exception.

  Description:
    This function enables the DMA bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be enabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionDMAEnable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionDMA feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionDMA in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionDMAEnable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionDMADisable( BMX_MODULE_ID index )

  Summary:
    Disables the DMA bus exception.

  Description:
    This function disables the DMA bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be disabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionDMADisable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionDMA feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionDMA in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionDMADisable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionDataEnable( BMX_MODULE_ID index )

  Summary:
    Enables the Data bus exception.

  Description:
    This function enables the Data bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be enabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionDataEnable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionData feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionData in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionDataEnable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionDataDisable( BMX_MODULE_ID index )

  Summary:
    Disables the data bus exception.

  Description:
    This function disables the data bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be disabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionDataDisable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionData feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionData in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionDataDisable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionInstructionEnable( BMX_MODULE_ID index )

  Summary:
    Enables the instruction bus exception.

  Description:
    This function enables the instruction bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be enabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionInstructionEnable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionInstruction feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionInstruction in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionInstructionEnable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_BusExceptionInstructionDisable( BMX_MODULE_ID index )

  Summary:
    Disables the instruction bus exception.

  Description:
    This function disables the instruction bus exception.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be disabled

  Returns:
    None.

  Example:
    <code>
    PLIB_BMX_BusExceptionInstructionDisable(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the BusExceptionInstruction feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsBusExceptionInstruction in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_BusExceptionInstructionDisable(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_ProgramFlashPartitionSet( BMX_MODULE_ID index, 
                                            size_t userSize )

  Summary:
    Sets the size of the kernel and user partitions in program Flash memory.

  Description:
    This function sets the size of the kernel and user partitions in program
    Flash memory (PFM). Kernel programs may access both partitions, but user
    programs may not access the kernel partition (including peripheral 
    registers). By default, the entire Flash is mapped to Kernel mode.
    If called with a non-zero value, a user partition of size user_size is 
    created, and the remaining PFM remains in Kernel mode. The user partition
    must be a multiple of PLIB_BMX_PFM_BLOCK_SIZE. If programmed with a 
    value that is not a multiple of PLIB_BMX_PFM_BLOCK_SIZE, the value will 
    be truncated to a PLIB_BMX_PFM_BLOCK_SIZE boundary.

  Precondition:
    None.

  Parameters:
    index    - Identifier for the device instance to be configured
    userSize - Size of the user partition in PFM

  Returns:
    None.

  Example:
    <code>
    size_t pfm_size;
    size_t userSize = (6 * PLIB_BMX_PFM_BLOCK_SIZE);
    size_t userOffset;

    // Get size of PFM
    size_t pfmSize;
    pfmSize = PLIB_BMX_ProgramFlashMemorySizeGet(BMX_ID_0);
    userOffset = pfmSize - userSize;
    if (userOffset > 0)
    {
        PLIB_BMX_ProgramFlashPartitionSet(BMX_ID_0, userOffset);
    }
    </code>

  Remarks:
    This function implements an operation of the ProgramFlashPartition feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsProgramFlashPartition in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_ProgramFlashPartitionSet(BMX_MODULE_ID index, size_t user_size);


/*******************************************************************************
  Function:
    size_t PLIB_BMX_ProgramFlashPartitionGet( BMX_MODULE_ID index )

  Summary:
    Gets the size of the kernel partition in program Flash memory.

  Description:
    This function gets the size of the kernel partition in the program Flash
    memory. The remaining Flash is set to user mode, and may be accessed
    by user programs. On reset, the entire Flash is mapped to Kernel mode, and
    this function will return zero.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be read

  Returns:
    Size of the kernel partition in program Flash memory.

  Example:
    <code>
    size_t pfmSize;
    size_t userPfmSize;
    size_t kernPfmSize;

    // Get size of PFM
    pfmSize = PLIB_BMX_ProgramFlashMemorySizeGet(BMX_ID_0);
    kernPfmSize = PLIB_BMX_ProgramFlashPartitionGet(BMX_ID_0);
    userPfmSize = pfmSize - kernPfmSize;
    </code>

  Remarks:
    This function implements an operation of the ProgramFlashPartition feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsProgramFlashPartition in your application 
    to automatically determine whether this feature is available.
*/

size_t PLIB_BMX_ProgramFlashPartitionGet(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    void PLIB_BMX_DataRAMPartitionSet( BMX_MODULE_ID index, \
                                       size_t kernProgOffset, \
                                       size_t userDataOffset, \
                                       size_t userProgOffset )

  Summary:
    Sets the size of the kernel and user partitions in data RAM memory.

  Description:
    This function sets the size of the kernel and user partitions in the data
    RAM memory (DRM). By default, the entire data RAM is mapped to Kernel mode
    and all of the offsets are zero. To partition the data RAM, all of the 
    offsets must be set to a minimum of one DRM block size. If any of the 
    offsets are set to zero, the entire data RAM is allocated to kernel data.
    The partitions must be a multiple of PLIB_BMX_DRM_BLOCK_SIZE. If 
    programmed with a value that is not a multiple of 
    PLIB_BMX_DRM_BLOCK_SIZE, the value will be automatically truncated to 
    PLIB_BMX_DRM_BLOCK_SIZE.

  Precondition:
    None.

  Parameters:
    index          - Identifier for the device instance to be configured
    kernProgOffset - Size of the offset of the Kernel Program partition
    userDataOffset - Size of the offset of the User Data partition
    userProgOffset - Size of the offset of the User Program partition

  Returns:
    None.

  Example:
    <code>

    //Total Data RAM = 32 KB.
    size_t totalRamSize;
    size_t kernDataRamSize = (3 * PLIB_BMX_DRM_BLOCK_SIZE);
    size_t kernProgRamSize = (2 * PLIB_BMX_DRM_BLOCK_SIZE);
    size_t userDataRamSize = (6 * PLIB_BMX_DRM_BLOCK_SIZE);
    size_t userProgRamSize = (5 * PLIB_BMX_DRM_BLOCK_SIZE);

    //Get Size of Data RAM
    totalRamSize = PLIB_BMX_DataRAMSizeGet(BMX_ID_0);

    //Verify our partition sizes fit our RAM
    if ((kernDataRamSize + kernProgRamSize + userDataRamSize + \
         userProgRamSize) != totalRamSize)
    {
        printf("RAM Partitioning Error\n");
    }

    size_t kernProgOffset;
    size_t userDataOffset;
    size_t userProgOffset;
    
    kernProgOffset = kernDataRamSize;
    userDataOffset = kernDataRamSize + kernProgRamSize;
    userProgOffset = userDataOffset + userDataRamSize;

    PLIB_BMX_DataRAMPartitionSet(BMX_ID_0, kernProgOffset, \
                                 userDataOffset, userProgOffset);
    </code>

  Remarks:
    This function implements an operation of the DataRAMPartition feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsDataRAMPartition in your application 
    to automatically determine whether this feature is available.
*/

void PLIB_BMX_DataRAMPartitionSet(BMX_MODULE_ID index, size_t kernProgOffset, size_t userDataOffset, size_t userProgOffset);

/*******************************************************************************
  Function:
    size_t PLIB_BMX_DataRAMKernelProgramOffsetGet( BMX_MODULE_ID index )

  Summary:
    Gets the offset (from start of RAM) of the kernel program partition.

  Description:
    This function returns the offset of start address of the kernel program RAM
    partition. This represents the size of the kernel data RAM partition.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be read

  Returns:
    Offset of kernel program partition from base of RAM.

  Example:
    <code>
    size_t kernProgOffset;
    kernProgOffset = PLIB_BMX_DataRAMKernelProgramOffsetGet(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the DataRAMPartition feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsDataRAMPartition in your application 
    to automatically determine whether this feature is available.
*/

size_t PLIB_BMX_DataRAMKernelProgramOffsetGet(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    size_t PLIB_BMX_DataRAMUserDataOffsetGet( BMX_MODULE_ID index )

  Summary:
    Gets the offset (from start of RAM) of the user data partition.

  Description:
    This function returns the offset of start address of the user data RAM
    partition. Subtracting the kernel program offset from the user data offset
    gives the size of the kernel program RAM partition.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be configured

  Returns:
    Offset of user data partition from base of RAM.

  Example:
    <code>
    size_t userDataOffset;
    userDataOffset = PLIB_BMX_DataRAMUserDataOffsetGet(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the DataRAMPartition feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsDataRAMPartition in your application 
    to automatically determine whether this feature is available.
*/

size_t PLIB_BMX_DataRAMUserDataOffsetGet(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    size_t PLIB_BMX_DataRAMUserProgramOffsetGet( BMX_MODULE_ID index )

  Summary:
    Gets the offset (from start of RAM) of the user program partition.

  Description:
    This function returns the offset of start address of the user program RAM
    partition. Subtracting the user data offset from the user program offset
    gives the size of the user data RAM partition.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be read

  Returns:
    Offset of user data partition from base of RAM.

  Example:
    <code>
    size_t userProgOffset;
    userProgOffset = PLIB_BMX_DataRAMUserProgramOffsetGet(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the DataRAMPartition feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsDataRAMPartition in your application 
    to automatically determine whether this feature is available.
*/

size_t PLIB_BMX_DataRAMUserProgramOffsetGet(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    size_t PLIB_BMX_ProgramFlashMemorySizeGet ( BMX_MODULE_ID index )

  Summary:
    Gets the size of program Flash memory.

  Description:
    This function returns the size of the program Flash memory.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be read

  Returns:
    Size of program Flash memory.

  Example:
    <code>
    size_t pfmSize;
    pfmSize = PLIB_BMX_ProgramFlashMemorySizeGet(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the ProgramFlashMemorySize feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsProgramFlashMemorySize in your application 
    to automatically determine whether this feature is available.
*/

size_t PLIB_BMX_ProgramFlashMemorySizeGet(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    size_t PLIB_BMX_DataRAMSizeGet ( BMX_MODULE_ID index )

  Summary:
    Gets the size of data RAM memory.

  Description:
    This function returns the size of the data RAM memory.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be read

  Returns:
    Size of data RAM memory.

  Example:
    <code>
    size_t drmSize;
    drmSize = PLIB_BMX_DataRAMSizeGet(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the DataRAMSize feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsDataRAMSize in your application 
    to automatically determine whether this feature is available.
*/

size_t PLIB_BMX_DataRAMSizeGet(BMX_MODULE_ID index);


/*******************************************************************************
  Function:
    size_t PLIB_BMX_ProgramFlashBootSizeGet ( BMX_MODULE_ID index )

  Summary:
    Gets the size of boot program Flash memory.

  Description:
    This function returns the size of the boot program Flash memory.

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance to be read

  Returns:
    Size of boot program Flash memory.

  Example:
    <code>
    size_t bootSize;
    bootSize = PLIB_BMX_ProgramFlashBootSizeGet(BMX_ID_0);
    </code>

  Remarks:
    This function implements an operation of the ProgramFlashBootSize feature.
    This feature may not be available on all devices. Please refer to the 
    specific device data sheet to determine availability or use 
    PLIB_BMX_ExistsProgramFlashBootSize in your application 
    to automatically determine whether this feature is available.
*/

size_t PLIB_BMX_ProgramFlashBootSizeGet(BMX_MODULE_ID index);


// *****************************************************************************
// *****************************************************************************
// Section: BMX Peripheral Library Exists API Routines
// *****************************************************************************
// *****************************************************************************
/* The following functions indicate the existence of the features on the device. 
*/

//******************************************************************************
/* Function :  PLIB_BMX_ExistsArbitrationMode( BMX_MODULE_ID index )

  Summary:
    Identifies that the ArbitrationMode feature exists on the BMX module.

  Description:
    This interface identifies that the ArbitrationMode feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_ArbitrationModeSet
    - PLIB_BMX_ArbitrationModeGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ArbitrationMode feature is supported on the device
    - false = The ArbitrationMode feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsArbitrationMode( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsDataRamWaitState( BMX_MODULE_ID index )

  Summary:
    Identifies that the DataRamWaitState feature exists on the BMX module.

  Description:
    This interface identifies that the DataRamWaitState feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_DataRamWaitStateSet
    - PLIB_BMX_DataRamWaitStateGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The DataRamWaitState feature is supported on the device
    - false = The DataRamWaitState feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsDataRamWaitState( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsProgramFlashMemoryCacheDma( BMX_MODULE_ID index )

  Summary:
    Identifies that the ProgramFlashMemoryCacheDma feature exists on the BMX module.

  Description:
    This interface identifies that the ProgramFlashMemoryCacheDma feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_ProgramFlashMemoryCacheDmaEnable
    - PLIB_BMX_ProgramFlashMemoryCacheDmaDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ProgramFlashMemoryCacheDma feature is supported on the device
    - false = The ProgramFlashMemoryCacheDma feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsProgramFlashMemoryCacheDma( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsBusExceptionIXI( BMX_MODULE_ID index )

  Summary:
    Identifies that the BusExceptionIXI feature exists on the BMX module.

  Description:
    This interface identifies that the BusExceptionIXI feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_BusExceptionIXIEnable
    - PLIB_BMX_BusExceptionIXIDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
      true  = The BusExceptionIXI feature is supported on the device
    - false = The BusExceptionIXI feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsBusExceptionIXI( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsBusExceptionICD( BMX_MODULE_ID index )

  Summary:
    Identifies that the BusExceptionICD feature exists on the BMX module.

  Description:
    This interface identifies that the BusExceptionICD feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_BusExceptionICDEnable
    - PLIB_BMX_BusExceptionICDDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The BusExceptionICD feature is supported on the device
    - false = The BusExceptionICD feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsBusExceptionICD( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsBusExceptionDMA( BMX_MODULE_ID index )

  Summary:
    Identifies that the BusExceptionDMA feature exists on the BMX module.

  Description:
    This interface identifies that the BusExceptionDMA feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_BusExceptionDMAEnable
    - PLIB_BMX_BusExceptionDMADisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The BusExceptionDMA feature is supported on the device
    - false = The BusExceptionDMA feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsBusExceptionDMA( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsBusExceptionData( BMX_MODULE_ID index )

  Summary:
    Identifies that the BusExceptionData feature exists on the BMX module.

  Description:
    This interface identifies that the BusExceptionData feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_BusExceptionDataEnable
    - PLIB_BMX_BusExceptionDataDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The BusExceptionData feature is supported on the device
    - false = The BusExceptionData feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsBusExceptionData( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsBusExceptionInstruction( BMX_MODULE_ID index )

  Summary:
    Identifies that the BusExceptionInstruction feature exists on the BMX module.

  Description:
    This interface identifies that the BusExceptionInstruction feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_BusExceptionInstructionEnable
    - PLIB_BMX_BusExceptionInstructionDisable

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The BusExceptionInstruction feature is supported on the device
    - false = The BusExceptionInstruction feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsBusExceptionInstruction( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsProgramFlashPartition( BMX_MODULE_ID index )

  Summary:
    Identifies that the ProgramFlashPartition feature exists on the BMX module.

  Description:
    This interface identifies that the ProgramFlashPartition feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_ProgramFlashPartitionGet
    - PLIB_BMX_ProgramFlashPartitionSet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ProgramFlashPartition feature is supported on the device
    - false = The ProgramFlashPartition feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsProgramFlashPartition( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsDataRAMPartition( BMX_MODULE_ID index )

  Summary:
    Identifies that the DataRAMPartition feature exists on the BMX module.

  Description:
    This interface identifies that the DataRAMPartition feature is available on the BMX module.
    When this interface returns true, these functions are supported on the device:
    - PLIB_BMX_DataRAMPartitionSet
    - PLIB_BMX_DataRAMKernelProgramOffsetGet
    - PLIB_BMX_DataRAMUserDataOffsetGet
    - PLIB_BMX_DataRAMUserProgramOffsetGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The DataRAMPartition feature is supported on the device
    - false = The DataRAMPartition feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsDataRAMPartition( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsProgramFlashMemorySize( BMX_MODULE_ID index )

  Summary:
    Identifies that the ProgramFlashMemorySize feature exists on the BMX module.

  Description:
    This interface identifies that the ProgramFlashMemorySize feature is available on the BMX module.
    When this interface returns true, this function is supported on the device:
    - PLIB_BMX_ProgramFlashMemorySizeGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ProgramFlashMemorySize feature is supported on the device
    - false = The ProgramFlashMemorySize feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsProgramFlashMemorySize( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsDataRAMSize( BMX_MODULE_ID index )

  Summary:
    Identifies that the DataRAMSize feature exists on the BMX module.

  Description:
    This interface identifies that the DataRAMSize feature is available on the BMX module.
    When this interface returns true, this function is supported on the device:
    - PLIB_BMX_DataRAMSizeGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The DataRAMSize feature is supported on the device
    - false = The DataRAMSize feature is not supported on the device


  Remarks:
    None.
*/

bool PLIB_BMX_ExistsDataRAMSize( BMX_MODULE_ID index );


//******************************************************************************
/* Function :  PLIB_BMX_ExistsProgramFlashBootSize( BMX_MODULE_ID index )

  Summary:
    Identifies that the ProgramFlashBootSize feature exists on the BMX module.

  Description:
    This interface identifies that the ProgramFlashBootSize feature is available on the BMX module.
    When this interface returns true, this function is supported on the device:
    - PLIB_BMX_ProgramFlashBootSizeGet

  Preconditions:
    None.

  Parameters:
    index           - Identifier for the device instance

  Returns:
    - true  = The ProgramFlashBootSize feature is supported on the device
    - false = The ProgramFlashBootSize feature is not supported on the device

  Remarks:
    None.
*/

bool PLIB_BMX_ExistsProgramFlashBootSize( BMX_MODULE_ID index );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // #ifndef _PLIB_BMX_H
/*******************************************************************************
 End of File
*/

