/*******************************************************************************
  Graphics LCD Controller (GLCD) Peripheral Library Interface Header.

  Company:
    Microchip Technology Inc.

  File Name:
    plib_glcd.h

  Summary:
    Defines the Graphics LCD Controller (GLCD) Peripheral Library Interface.

  Description:
    This header file contains the function prototypes and definitions of
    the data types and constants that make up the interface to the Graphics
    LCD Controller Peripheral Library for Microchip micro-controllers. The
    definitions in this file are only for the directly addressable memory mapped
    Graphics LCD Controller module.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright 2015 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PLIB_GLCD_H
#define _PLIB_GLCD_H

// *****************************************************************************
// *****************************************************************************
// Section: Constants & Data Types.
// *****************************************************************************
// *****************************************************************************

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
/* See Bottom of file for implementation header include files.
*/
// DOM-IGNORE-BEGIN
#include "peripheral/glcd/processor/glcd_processor.h"
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Peripheral Library Interface Routines
// *****************************************************************************
// *****************************************************************************

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsEnable ( GLCD_MODULE_ID index )

  Summary:
    Identifies whether the GLCD Enable feature exists on the GLCD module.

  Description:
    This function identifies whether the GLCD Enable feature is available on the
    GLCD module. When this function returns true, these functions are supported 
    on the device:
    - PLIB_GLCD_Enable
    - PLIB_GLCD_Disable

  Precondition:
    None.

  Parameters:
    index - Identifier for the device instance

  Returns:
    - true   - The GLCD Enable feature is supported on the device
    - false  - The GLCD Enable feature is not supported on the device

  Example:

    <code>
        if ( PLIB_GLCD_ExistsEnable( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_Enable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

bool PLIB_GLCD_ExistsEnable ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_Enable( GLCD_MODULE_ID index )

  Summary:
    Enables the Graphics LCD Controller.

  Description:
    This function enables the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_Enable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_Enable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_Disable( GLCD_MODULE_ID index )

  Summary:
    Disables the Graphics LCD Controller.

  Description:
    This function disables the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_Disable( GLCD_MODULE_ID_0 );
    </code>
  
  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_Disable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_IsEnabled ( GLCD_MODULE_ID index )

  Summary:
    Verifies whether the Graphics LCD Controller is Enabled. 
    
  Description:
    This function verifies whether the Graphics LCD Controller is Enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - Graphics LCD Controller is Enabled
    - false - Graphics LCD Controller is Disabled

  Example:

    <code>      
        if ( PLIB_GLCD_IsEnabled( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_Disable( GLCD_MODULE_ID_0 );
        }
    </code>
   
  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

bool PLIB_GLCD_IsEnabled ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsCursor( GLCD_MODULE_ID index )

  Summary:
    Verifies whether the cursor feature exists.
    
  Description:
    This function verifies whether the cursor feature exists.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - Cursor feature exists.
    - false - Cursor feature does not exits.

  Example:

    <code>      
        if ( PLIB_GLCD_ExistsCursor( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_CursorEnable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsCursor( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_CursorEnable( GLCD_MODULE_ID index )

  Summary:
    Enables the cursor of the Graphics LCD Controller.
    
  Description:
    This function enables the cursor of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>  
        if ( PLIB_GLCD_ExistsCursor( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_CursorEnable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
 
*/

void PLIB_GLCD_CursorEnable ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_CursorDisable( GLCD_MODULE_ID index )

  Summary:
    Disables the cursor of the Graphics LCD Controller.

  Description:
    This function disables the cursor of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>   
        if ( PLIB_GLCD_ExistsCursor( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_CursorDisable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_CursorDisable ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_CursorIsEnabled ( GLCD_MODULE_ID index )

  Summary:
    Verifies whether the cursor is enabled.
    
  Description:
    This function verifies whether the cursor is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - Cursor is enabled.
    - false - Cursor is disabled.

  Example:

    <code>        
        if ( PLIB_GLCD_CursorIsEnabled( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_CursorDisable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

bool PLIB_GLCD_CursorIsEnabled ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsSignalPolarity( GLCD_MODULE_ID index )

  Summary:
    Verifies whether the Signal Polarity Selection feature exists.
    
  Description:
    This function verifies whether the Signal Polarity Selection feature exists. 

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - Feature exists
    - false - Feature does not exist
  
  Example:

    <code>      
        if ( PLIB_GLCD_ExistsSignalPolarity( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_SignalPolaritySet( GLCD_MODULE_ID_0,
		                                 GLCD_POLARITY_POSITIVE | 
                                         GLCD_DE_POLARITY_NEGATIVE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

bool PLIB_GLCD_ExistsSignalPolarity( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_SignalPolaritySet( GLCD_MODULE_ID       index,
                                      GLCD_SIGNAL_POLARITY polarity )

  Summary:
    Sets the polarity of the pixel clock, DE, HSync and VSync pin of the 
	Graphics LCD Controller.

  Description:
    This function sets the polarity of the pixel clock, DE, HSync and VSync pin 
    of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    polarity - Enum variable specifying polarity.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_SignalPolaritySet( GLCD_MODULE_ID_0, 
                                     GLCD_POLARITY_POSITIVE | 
                                     GLCD_DE_POLARITY_NEGATIVE );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_SignalPolaritySet( GLCD_MODULE_ID       index,
                                  GLCD_SIGNAL_POLARITY polarity );

//******************************************************************************
/* Function: 
    GLCD_SIGNAL_POLARITY PLIB_GLCD_SignalPolarityGet( GLCD_MODULE_ID index )

  Summary:
    Gets the polarity of the pixel clock, DE, HSync and VSync pin of the 
	Graphics LCD Controller.

  Description:
    This function gets the polarity of the pixel clock, DE, HSync and VSync pin 
    of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        uint32_t signalPolarity = GLCD_POLARITY_POSITIVE; 

        signalPolarity = PLIB_GLCD_VSyncPolarityGet( GLCD_MODULE_ID_0 );

        if( signalPolarity & GLCD_DE_POLARITY_NEGATIVE )
        {
            // DE Polarity Negative
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/
GLCD_SIGNAL_POLARITY PLIB_GLCD_SignalPolarityGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsDithering( GLCD_MODULE_ID index )

  Summary:
    Verifies whether the Dithering feature exists.

  Description:
    This function verifies whether the Dithering feature exists.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true   - The Dithering feature is supported on the device
    - false  - The Dithering feature is not supported on the device

  Example:

    <code>      
        if ( PLIB_GLCD_ExistsDithering( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_DitheringEnable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsDithering( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_DitheringEnable( GLCD_MODULE_ID index )

  Summary:
    Enables the Dithering feature of the Graphics LCD Controller.

  Description:
    This function enables the Dithering feature of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_DitheringEnable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_DitheringEnable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_DitheringDisable( GLCD_MODULE_ID index )

  Summary:
    Disables the Dithering feature of the Graphics LCD Controller.

  Description:
    This function disables the Dithering feature of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_DitheringDisable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_DitheringDisable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_DitheringIsEnabled( GLCD_MODULE_ID index )

  Summary:
    Verifies whether Dithering is enabled.

  Description:
    This function verifies whether Dithering is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true   - The Dithering feature is enabled.
    - false  - The Dithering feature is disabled.

  Example:

    <code>
        if(PLIB_GLCD_DitheringIsEnabled(GLCD_MODULE_ID_0 ))
		{
		    PLIB_GLCD_DitheringDisable( GLCD_MODULE_ID_0 );
	    }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_DitheringIsEnabled( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsSingleCycleVsync( GLCD_MODULE_ID index )

  Summary:
    Verifies whether VSYNC on Single cycle Per Line Feature exists.

  Description:
    This function verifies whether VSYNC on Single cycle Per Line Feature exists.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true   - The feature: VSYNC on Single Cycle Per Line is supported on the 
               device.
    - false  - The feature: VSYNC on Single Cycle Per Line is not supported on 
               the device.

  Example:

    <code>
	    if(PLIB_GLCD_ExistsSingleCyclePerLineVsync( GLCD_MODULE_ID_0))
		{
		    PLIB_GLCD_SingleCyclePerLineVsyncEnable( GLCD_MODULE_ID_0 );
		}
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsSingleCyclePerLineVsync( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_SingleCyclePerLineVsyncSet( GLCD_MODULE_ID index )

  Summary:
    Sets VSYNC on single cycle per line.

  Description:
    This function sets VSYNC on single cycle per line.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_SingleCyclePerLineVsyncEnable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_SingleCyclePerLineVsyncEnable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_SingleCyclePerLineVsyncClear( GLCD_MODULE_ID index )

  Summary:
    Clears VSYNC on single cycle per line.

  Description:
    This function clears VSYNC on single cycle per line.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_SingleCyclePerLineVsyncClear( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_SingleCyclePerLineVsyncDisable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_SingleCyclePerLineVsyncIsEnabled( GLCD_MODULE_ID index )

  Summary:
    Verify whether VSYNC on Single Cycle Per Line feature is enabled.

  Description:
    This function verifies whether VSYNC on Single Cycle Per Line feature is
    enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - VSYNC on Single Cycle Per Line is enabled.
    - false - VSYNC on Single Cycle Per Line is disabled.

  Example:

    <code>
        if(PLIB_GLCD_SingleCyclePerLineVsyncIsEnabled(GLCD_MODULE_ID_0))
		{
		    PLIB_GLCD_SingleCyclePerLineVsyncDisable(GLCD_MODULE_ID_0);
		}
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_SingleCyclePerLineVsyncIsEnabled( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsPaletteGammaRamp( GLCD_MODULE_ID index )

  Summary:
    Verifies whether the palette / gamma ramp  feature is supported.

  Description:
    This function verifies whether the palette / gamma ramp  feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The palette / gamma ramp enable feature supported.
    - false - The palette / gamma ramp enable feature not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsPaletteGammaRamp( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_PaletteGammaRampEnable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsPaletteGammaRamp( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_PaletteGammaRampEnable( GLCD_MODULE_ID index )

  Summary:
    Enables the palette / gamma ramp of the Graphics LCD Controller.

  Description:
    This function enables the palette / gamma ramp of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_PaletteGammaRampEnable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_PaletteGammaRampEnable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_PaletteGammaRampDisable( GLCD_MODULE_ID index )

  Summary:
    Disables the palette / gamma ramp of the Graphics LCD Controller.

  Description:
    This function disables the palette / gamma ramp of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_PaletteGammaRampDisable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_PaletteGammaRampDisable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_PaletteGammaRampIsEnabled( GLCD_MODULE_ID index )

  Summary:
    Verify whether Palette / Gamma Ramp feature is enabled.

  Description:
    This function verifies whether Palette / Gamma Ramp feature is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The palette / gamma ramp feature is enabled.
    - false - The palette / gamma ramp feature is disabled.

  Example:

    <code>
	    if( PLIB_GLCD_PaletteGammaRampIsEnabled( GLCD_MODULE_ID_0 ) )
		{
            PLIB_GLCD_PaletteGammaRampDisable( GLCD_MODULE_ID_0 );
	    }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/
bool PLIB_GLCD_PaletteGammaRampIsEnabled( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsForceOutputBlank( GLCD_MODULE_ID index )

  Summary:
    Verify whether Force Output Blank feature is supported.

  Description:
    This function verifies whether Force Output Blank feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The force output blank feature supported
    - false - The force output blank feature not supported

  Example:

    <code>
        if( PLIB_GLCD_ExistsForceOutputBlank( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_ForceOutputBlankEnable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsForceOutputBlank( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_ForceOutputBlankEnable( GLCD_MODULE_ID index )

  Summary:
    Enable Force Output Blank feature.

  Description:
    This function enables the Force Output Blank feature.
    
  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
	   PLIB_GLCD_ForceOutputBlankEnable( GLCD_MODULE_ID_0 );
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_ForceOutputBlankEnable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_ForceOutputBlankDisable( GLCD_MODULE_ID index )

  Summary:
    Disable Force Output Blank feature.

  Description:
    This function disables the Force Output Blank feature.
    
  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_ForceOutputBlankDisable( GLCD_MODULE_ID_0 );
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_ForceOutputBlankDisable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ForceOutputBlankIsEnabled( GLCD_MODULE_ID index )

  Summary:
    Verify whether the Force Output Blank feature is enabled.

  Description:
    This function verifies whether the Force Output Blank feature is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The Force Output Blank feature is enabled.
    - false - The Force Output Blank feature is disabled.

  Example:

    <code> 
        if ( PLIB_GLCD_ForceOutputBlankIsEnabled( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_ForceOutputBlankDisable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/
bool PLIB_GLCD_ForceOutputBlankIsEnabled( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsYUVOutput( GLCD_MODULE_ID index )

  Summary:
    Verify whether YUV output feature is supported.

  Description:
    This function verifies whether YUV output feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The YUV output feature is supported.
    - false - The YUV output feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsYUVOutput( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_YUVOutputEnable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsYUVOutput( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_YUVOutputEnable( GLCD_MODULE_ID index )

  Summary:
    Enables the output of the Graphics LCD Controller in YUV format.

  Description:
    This function enables the output of the Graphics LCD Controller in YUV
    format.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_YUVOutputEnable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_YUVOutputEnable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_YUVOutputDisable( GLCD_MODULE_ID index )

  Summary:
    Disables the output of the Graphics LCD Controller in YUV format.

  Description:
    This function Disables the output of the Graphics LCD Controller in YUV
    format.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_YUVOutputDisable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_YUVOutputDisable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_YUVOutputIsEnabled( GLCD_MODULE_ID index )

  Summary:
    Verify whether the YUV Output feature is enabled.

  Description:
    This function verifies whether the YUV Output feature is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The YUV output feature is enabled.
    - false - The YUV output feature is disabled.

  Example:

    <code> 
        if ( PLIB_GLCD_YUVOutputIsEnabled( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_YUVOutputDisable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/
bool PLIB_GLCD_YUVOutputIsEnabled( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsFormattingClockDivide( GLCD_MODULE_ID index )

  Summary:
    Verify whether Clock Formatting feature is available.

  Description:
    This function verifies whether Clock formatting feature is available.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    
  Returns:
    - true - The Clock formatting feature is supported.
    - false - The Clock formatting feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsFormattingClockDivide( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_FormattingClockDivideEnable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsFormattingClockDivide( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_FormattingClockDivideEnable( GLCD_MODULE_ID index )

  Summary:
    Enable the Clock Formatting feature.

  Description:
    This function Enables the Clock Formatting feature.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    
  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_FormattingClockDivideEnable( GLCD_MODULE_ID_0 );
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_FormattingClockDivideEnable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_FormattingClockDivideDisable( GLCD_MODULE_ID index )

  Summary:
    Disbale the Clock Formatting feature.

  Description:
    This function disbales the Clock Formatting feature.
 
  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    
  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_FormattingClockDivideDisable( GLCD_MODULE_ID_0 );
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_FormattingClockDivideDisable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_FormattingClockDivideIsEnabled( GLCD_MODULE_ID index )

  Summary:
    Verify whether Clock Formatting feature is enabled.

  Description:
    This function verifies if the Clock Formatting feature is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    
  Returns:
    - true - The Clock Formatting feature is enabled.
    - false - The Clock Formatting feature is disabled.
    
  Example:

    <code> 
        if ( PLIB_GLCD_FormattingClockDivideIsEnabled( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_FormattingClockDivideDisable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_FormattingClockDivideIsEnabled( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsRGBSequentialMode( GLCD_MODULE_ID index )

  Summary:
    Verify whether RGB Sequential Mode feature is supported.

  Description:
    This function verifies whether RGB Sequential Mode feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    
  Returns:
    - true - The RGB Sequential Mode feature is supported.
    - false - The RGB Sequential Mode feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsRGBSequentialMode( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_RGBSequentialModeSet( GLCD_MODULE_ID_0, 
			                                GLCD_RGB_MODE_PARALLEL );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsRGBSequentialMode( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_RGBSequentialModeSet( GLCD_MODULE_ID index, GLCD_RGB_MODE mode )

  Summary:
    Sets the RGB output sequential mode.

  Description:
    This function sets the RGB output sequential mode.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    mode - RGB sequential mode defined by GLCD_RGB_MODE.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_RGBSequentialModeSet( GLCD_MODULE_ID_0,
                                        GLCD_RGB_MODE_PARALLEL );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_RGBSequentialModeSet( GLCD_MODULE_ID index,
                                     GLCD_RGB_MODE  mode );

//******************************************************************************
/* Function: 
    GLCD_RGB_MODE PLIB_GLCD_RGBSequentialModeGet( GLCD_MODULE_ID index )

  Summary:
    Get the RGB Sequential Mode already set.

  Description:
    This function gets the RGB Sequential Mode already set.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:

    - GLCD_RGB_MODE_PARALLEL_RGB565 - Parallel RGB 565 Mode
    - GLCD_RGB_MODE_PARALLEL_RGB888 - Parallel RGB 888 Mode
    - GLCD_RGB_MODE_SERIAL_RGB_3 - Byte Serial RGB 3 Mode
    - GLCD_RGB_MODE_SERIAL_RGBA_4 - Byte Serial RGB 4 Mode
    - GLCD_RGB_MODE_SERIAL_12BIT - Byte Two-Phase 12-bit Mode
    - GLCD_RGB_MODE_YUYV_16BIT - YUYV 16 bit Mode
    - GLCD_RGB_MODE_BT_656 - BT 656 Mode
            
  Example:

    <code>
	    uint32_t rgbMode;

		rgbMode = PLIB_GLCD_RGBSequentialModeGet( GLCD_MODULE_ID_0 );

		if( rgbMode == GLCD_RGB_MODE_PARALLEL_RGB565 )
		{
		    // RGB Mode set to RGB 565 format
		}
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

GLCD_RGB_MODE PLIB_GLCD_RGBSequentialModeGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsClockDivider( GLCD_MODULE_ID index )

  Summary:
    Verify whether the Clock Divider feature is supported.

  Description:
    This function verifies whether the Clock Divider feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Clock divide feature is supported.
    - false - The Clock divide feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsClockDivider( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_ClockDividerSet( GLCD_MODULE_ID_0, MY_CLOCK_DIVIDER_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsClockDivider( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_ClockDividerSet( GLCD_MODULE_ID index, uint32_t clockDivider )

  Summary:
    Sets clock controls of the Graphics LCD Controller.

  Description:
    This function sets clock controls of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    clockDivider - Factor dividing the GLCD clock.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_ClockDividerSet( GLCD_MODULE_ID_0, MY_CLOCK_DIVIDER_VALUE );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_ClockDividerSet( GLCD_MODULE_ID index, uint32_t clockDivider );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_ClockDividerGet( GLCD_MODULE_ID index )

  Summary:
    Gets Clock Divider value.

  Description:
    This function gets the Clock Divider value.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of clock divider.

  Example:

    <code>
	    uint32_t dividerValue;

		dividerValue = PLIB_GLCD_ClockDividerGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_ClockDividerGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLinesPrefetch( GLCD_MODULE_ID index )

  Summary:
    Verify whether Lines Prefetch Set Feature supported.

  Description:
    This function verifies whether Lines Prefetch Set Feature supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Lines Prefetch feature is supported.
    - false - The Lines Prefetch feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLinesPrefetch( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LinesPrefetchSet( GLCD_MODULE_ID_0, 
			                            MY_LINES_PREFETCH_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLinesPrefetch( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LinesPrefetchSet( GLCD_MODULE_ID index, uint32_t linesPrefetch )

  Summary:
    Sets the clock controls of the Graphics LCD Controller.

  Description:
    This function sets the clock controls of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index         - Identifier of the device instance
    linesPrefetch - clock lines prefetch

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_LinesPrefetchSet( GLCD_MODULE_ID_0, 
		                            MY_LINES_PREFETCH_VALUE );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LinesPrefetchSet( GLCD_MODULE_ID index, uint32_t linesPrefetch );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_LinesPrefetchGet( GLCD_MODULE_ID index )

  Summary:
    Gets value of lines to be prefetched.

  Description:
    This function gets the value of lines to be prefetched.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of lines to be prefetched.

  Example:

    <code>
	    uint32_t linesPrefetch;

		linesPrefetch = PLIB_GLCD_LinesPrefetchGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_LinesPrefetchGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsBackgroundColor( GLCD_MODULE_ID index )

  Summary:
    Verify whether the Background Color Feature is supported.

  Description:
    This function verifies whether the Background Color Feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Background Color feature is supported.
    - false - The Background Color feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsBackgroundColor( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_BackgroundColorSet( GLCD_MODULE_ID_0, 
			                              MY_BACKGROUND_COLOR_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsBackgroundColor( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void ExistsBackgroundColor( GLCD_MODULE_ID index )

  Summary:
    Sets the background color.

  Description:
    This function sets the background color of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    bgColor - Background color.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_BGColorSet( GLCD_MODULE_ID_0, 0x000000FF );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_BackgroundColorSet( GLCD_MODULE_ID index,
                                   uint32_t       bgColor );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_BackgroundColorGet( GLCD_MODULE_ID index );

  Summary:
    Gets the value of the Background Color.

  Description:
    This function gets the value of the Background Color.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of the Background Color.

  Example:

    <code>
	    uint32_t backgroundColor;

		backgroundColor = PLIB_GLCD_BackgroundColorGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_BackgroundColorGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsYUVOutput( GLCD_MODULE_ID index )

  Summary:
    Verify whether YUV Output feature is supported.

  Description:
    This function verifies whether YUV Output feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Resolution feature is supported.
    - false - The Resolution feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsResolutionXY( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_ResolutionXYSet( GLCD_MODULE_ID_0, 
			                           MY_RESOLUTION_X_VALUE,
									   MY_RESOLUTION_Y_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsResolutionXY ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_ResolutionXYSet( GLCD_MODULE_ID index,
                                    uint32_t       resolutionX,
                                    uint32_t       resolutionY )

  Summary:
    Sets the display resolution for the Graphics LCD Controller.

  Description:
    This function sets the display resolution for the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index       - Identifier of the device instance.
    resolutionX - Display resolution on x axis in terms of number of pixels.
    resolutionY - Display resolution on y axis in terms of number of pixels.

  Returns:
    None.

  Example:
    <code>
        // set display resolution as: width: 640 pixels and height: 480 pixels
        PLIB_GLCD_ResolutionXYSet( GLCD_MODULE_ID_0, 640, 480 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_ResolutionXYSet( GLCD_MODULE_ID index,
                                uint32_t       resolutionX,
                                uint32_t       resolutionY );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_ResolutionXGet( GLCD_MODULE_ID index )

  Summary:
    Gets X Axis Resolution.

  Description:
    This function gets the X Axis resolution.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of x axis resolution.

  Example:

    <code>
	    uint32_t resolutionX;

		resolutionX = PLIB_GLCD_ResolutionXGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_ResolutionXGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_ResolutionYGet( GLCD_MODULE_ID index )

  Summary:
    Gets Y Axis Resolution.

  Description:
    This function gets the Y Axis Resolution.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - Value of Y Axis Resolution.

  Example:

    <code>
	    uint32_t resolutionY;

		resolutionY = PLIB_GLCD_ResolutionYGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_ResolutionYGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsFrontPorchXY( GLCD_MODULE_ID index )

  Summary:
    Verify whether Front Porch Feature is supported.

  Description:
    This funtion verifies whether Front Porch Feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Front Porch feature is supported.
    - false - The Front Porch feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsFrontPorchXY( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_FrontPorchXYSet( GLCD_MODULE_ID_0, 
			                           MY_FRONT_PORCH_X_VALUE,
									   MY_FRONT_PORCH_Y_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsFrontPorchXY ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_FrontPorchXYSet( GLCD_MODULE_ID index,
                                    uint32_t       frontPorchX,
                                    uint32_t       frontPorchY )

  Summary:
    Sets the front porch on the x and y axis for the Graphics LCD Controller.

  Description:
    This function sets the front porch on the x and y axis for the Graphics LCD
    Controller.

  Precondition:
    None.

  Parameters:
    index       - Identifier of the device instance.
    frontPorchX - Front porch pulse width on x axis.
    frontPorchY - Front porch pulse width on y axis.

  Returns:
    None.

  Example:

    <code>
        // set front porch as: on x axis: 40 and on y axis: 20
        PLIB_GLCD_FrontPorchXYSet( GLCD_MODULE_ID_0, 40, 20 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_FrontPorchXYSet( GLCD_MODULE_ID index,
                                uint32_t       frontPorchX,
                                uint32_t       frontPorchY );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_FrontPorchXGet( GLCD_MODULE_ID index )

  Summary:
    Gets X Axis Front Porch.

  Description:
    This Function gets X Axis Front Porch.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of X Axis Front Porch.

  Example:

    <code>
	    uint32_t porchX;

		porchX = PLIB_GLCD_FrontPorchXGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_FrontPorchXGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_FrontPorchYGet( GLCD_MODULE_ID index )

  Summary:
    Gets Y Axis Front Porch.

  Description:
    This function gets Y Axis Front Porch.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of y axis front porch.

  Example:

    <code>
	    uint32_t porchY;

		porchY = PLIB_GLCD_FrontPorchYGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_FrontPorchYGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsBlankingXY( GLCD_MODULE_ID index )

  Summary:
    Verify whether Blanking Period Feature is supported.

  Description:
    This function verifies whether Blanking Period Feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Blanking feature is supported.
    - false - The Blanking feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsBlankingXY( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_BlankingXYSet( GLCD_MODULE_ID_0, 
			                         MY_BLANKING_PERIOD_X_VALUE,
									 MY_BLANKING_PERIOD_Y_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsBlankingXY ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_BlankingXYSet( GLCD_MODULE_ID index,
                                  uint32_t       blankingX
                                  uint32_t       blankingY )

  Summary:
    Sets the blanking period on the x and y axis of the Graphics LCD Controller.

  Description:
    This function sets the blanking period on the x and y axis of the Graphics LCD
    Controller.

  Precondition:
    None.

  Parameters:
    index     - Identifier of the device instance.
    blankingX - Blanking period on x axis.
    blankingY - Blanking period on y axis.

  Returns:
    None.

  Example:

    <code>
        // Set blanking period: on x axis: 10 and on y axis: 10
        PLIB_GLCD_BlankingXY_Set( GLCD_MODULE_ID_0, 10, 10 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_BlankingXYSet( GLCD_MODULE_ID index,
                              uint32_t       blankingX,
                              uint32_t       blankingY );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_BlankingXGet( GLCD_MODULE_ID index )

  Summary:
    Gets the X Axis Blanking Period.

  Description:
    This function gets the X Axis Blanking Period.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of X Axis Blanking Period.

  Example:

    <code>
	    uint32_t blankingX;

		blankingX = PLIB_GLCD_BlankingXGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_BlankingXGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_BlankingYGet( GLCD_MODULE_ID index )

  Summary:
    Gets the Y Axis Blanking Period.

  Description:
    This function gets the Y Axis Blanking Period.  

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of Y Axis Blanking Period.

  Example:

    <code>
	    uint32_t blankingY;

		blankingY = PLIB_GLCD_BlankingYGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_BlankingYGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsBackPorchXY( GLCD_MODULE_ID index )

  Summary:
    Verify whether Back Porch Feature is supported.

  Description:
    This function verifies whether Back Porch Feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Back Porch feature is supported.
    - false - The Back Porch feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsBackPorchXY( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_BackPorchXYSet( GLCD_MODULE_ID_0, 
			                          MY_BACK_PORCH_X_VALUE,
									  MY_BACK_PORCH_Y_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsBackPorchXY ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_BackPorchXYSet( GLCD_MODULE_ID index,
                                   uint32_t       backPorchX
                                   uint32_t       backPorchY )

  Summary:
    Sets the back porch on the x and y axis for the Graphics LCD Controller.

  Description:
    This function sets the back porch on the x and y axis for the Graphics LCD 
	Controller.

  Precondition:
    None.

  Parameters:
    index      - Identifier of the device instance.
    backPorchX - Back porch pulse width on x axis.
    backPorchY - Back porch pulse width on y axis.

  Returns:
    None.

  Example:

    <code>
        // set back porch as: on x axis: 40 and on y axis: 20
        PLIB_GLCD_BackPorchXYSet( GLCD_MODULE_ID_0, 40, 20 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_BackPorchXYSet( GLCD_MODULE_ID index,
                               uint32_t       backPorchX,
                               uint32_t       backPorchY );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_BackPorchXGet( GLCD_MODULE_ID index )

  Summary:
    Gets X Axis Back Porch.

  Description:
    This function gets X Axis Back Porch.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of X Axis Back Porch.

  Example:

    <code>
	    uint32_t backPorchX;

		backPorchX = PLIB_GLCD_BackPorchXGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_BackPorchXGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_BackPorchYGet( GLCD_MODULE_ID index )

  Summary:
    Gets Y Axis Back Porch.

  Description:
    This function gets Y Axis Back Porch.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - value of Y Axis Back Porch.

  Example:

    <code>
	    uint32_t backPorchY;

		backPorchY = PLIB_GLCD_BackPorchYGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_BackPorchYGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerEnable ( GLCD_MODULE_ID index )

  Summary:
    Verify whether Layer Enable Feature is supported.

  Description:
    This function verifies whether Layer enable Feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Enable feature is supported.
    - false - The Layer Enable feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerEnable( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerEnable( GLCD_MODULE_ID_0, GLCD_LAYER_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerEnable ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerEnable( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId )

  Summary:
    Enables the layer of the Graphics LCD Controller.

  Description:
    This function enables the layer of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_LayerEnable( GLCD_MODULE_ID_0, GLCD_LAYER_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerEnable( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerDisable( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId )

  Summary:
    Disables the layer of the Graphics LCD Controller.

  Description:
    This function disables the layer of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_LayerDisable( GLCD_MODULE_ID_0, GLCD_LAYER_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_LayerDisable( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_LayerIsEnabled ( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId )

  Summary:
    Verify whether Layer is enabled.

  Description:
    This function verifies whether a given Layer is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The given Layer is enabled.
    - false - The given Layer is disabled.

  Example:

    <code> 
        if ( PLIB_GLCD_LayerIsEnabled( GLCD_MODULE_ID_0, GLCD_LAYER_0 ) )
        {
            PLIB_GLCD_LayerDisable( GLCD_MODULE_ID_0, GLCD_LAYER_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_LayerIsEnabled ( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerPreMultiplyImageAlpha ( GLCD_MODULE_ID index )

  Summary:
    Verify whether Layer Pre-Multiply Image Alpha Feature is supported.

  Description:
    This function verifies whether Layer Pre-Multiply Image Alpha Feature is 
	supported.  

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Pre-Multiply Image Alpha feature is supported.
    - false - The Layer Pre-Multiply Image Alpha feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerPreMultiplyImageAlpha( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerPreMultiplyImageAlphaEnable( GLCD_MODULE_ID_0, 
			                                            GLCD_LAYER_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerPreMultiplyImageAlpha ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerPreMultiplyImageAlphaEnable ( GLCD_MODULE_ID index, 
	                                                  GLCD_LAYER_ID  layerId )

  Summary:
    Enable Layer Pre-Multiply Image Alpha Feature.

  Description:
    This function enables the Layer Pre-Multiply Image Alpha Feature.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    None.

  Example:

    <code>
	    PLIB_GLCD_LayerPreMultiplyImageAlphaEnable( GLCD_MODULE_ID_0, 
			                                        GLCD_LAYER_0 );
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerPreMultiplyImageAlphaEnable ( GLCD_MODULE_ID index,
                                                  GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerPreMultiplyImageAlphaDisable ( GLCD_MODULE_ID index,
                                                       GLCD_LAYER_ID  layerId )

  Summary:
    Disable Layer Pre-Multiply Image Alpha Feature.

  Description:
    This function disables Layer Pre-Multiply Image Alpha Feature.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    None.

  Example:

    <code>
	    PLIB_GLCD_LayerPreMultiplyImageAlphaDisable( GLCD_MODULE_ID_0, 
			                                         GLCD_LAYER_0 );
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerPreMultiplyImageAlphaDisable ( GLCD_MODULE_ID index,
                                                   GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_LayerPreMultiplyImageAlphaIsEnabled ( GLCD_MODULE_ID index,
                                                         GLCD_LAYER_ID  layerId )

  Summary:
    Verify whether the Layer Pre-Multiply Image Alpha Feature is enabled.
    
  Description:
    This function verifies whether the Layer Pre-Multiply Image Alpha Feature is 
	enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - true - The Layer Pre-Multiply Image Alpha feature is enabled
    - false - The Layer Pre-Multiply Image Alpha feature is disabled.

  Example:

    <code> 
        if ( PLIB_GLCD_LayerPreMultiplyImageAlphaIsEnabled( GLCD_MODULE_ID_0,
	                                                        GLCD_LAYER_0 ) )
        {
            PLIB_GLCD_LayerPreMultiplyImageAlphaDisable( GLCD_MODULE_ID_0, 
			                                             GLCD_LAYER_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_LayerPreMultiplyImageAlphaIsEnabled ( GLCD_MODULE_ID index, 
                                                     GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerForceWithGlobalAlpha ( GLCD_MODULE_ID index )

  Summary:
    Verify whether Layer Force with Global Alpha Feature is supported.

  Description:
    This function verifies whether Layer Force with Global Alpha Feature is 
	supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Force Global Alpha feature is supported.
    - false - The Layer Force Global Alpha feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerForceWithGlobalAlpha( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerForceWithGlobalAlphaEnable( GLCD_MODULE_ID_0, 
			                                           GLCD_LAYER_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerForceWithGlobalAlpha ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerForceWithGlobalAlphaEnable ( GLCD_MODULE_ID index, 
                                                     GLCD_LAYER_ID  layerId )

  Summary:
    Enable the Layer Force Global Alpha feature.

  Description:
    This function enables the Layer Force Global Alpha feature.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    None.

  Example:

    <code>
       PLIB_GLCD_LayerForceWithGlobalAlphaEnable ( GLCD_MODULE_ID_0, 
                                                   GLCD_LAYER_0 );
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerForceWithGlobalAlphaEnable ( GLCD_MODULE_ID index, 
                                                 GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerForceWithGlobalAlphaDisable ( GLCD_MODULE_ID index,
                                                      GLCD_LAYER_ID  layerId )

  Summary:
    Disables the Layer Force Global Alpha feature.

  Description:
    This function disables the Layer Force Global Alpha feature.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    None.

  Example:

    <code>
       PLIB_GLCD_LayerForceWithGlobalAlphaDisable ( GLCD_MODULE_ID_0, 
                                                    GLCD_LAYER_0 );
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerForceWithGlobalAlphaDisable ( GLCD_MODULE_ID index, 
                                                  GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_LayerForceWithGlobalAlphaIsEnabled ( GLCD_MODULE_ID index,
                                                        GLCD_LAYER_ID  layerId )

  Summary:
    Verify whether Layer Force with Global Alpha Feature is enabled.

  Description:
    This function verifies whether Layer Force with Global Alpha Feature is 
	enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - true - The Layer Force Global Alpha feature is enabled.
    - false - The Layer Force Global Alpha feature is disabled.

  Example:

    <code> 
        if ( PLIB_GLCD_LayerForceWithGlobalAlphaIsEnabled( GLCD_MODULE_ID_0,
	                                                       GLCD_LAYER_0	) )
        {
            PLIB_GLCD_LayerForceWithGlobalAlphaDisable( GLCD_MODULE_ID_0, 
			                                            GLCD_LAYER_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_LayerForceWithGlobalAlphaIsEnabled ( GLCD_MODULE_ID index,
                                                    GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerBilinearFilterEnable ( GLCD_MODULE_ID index )

  Summary:
    Enable Layer Bilinear Filter Feature.

  Description:
    This function enables the Layer Bilinear Filter Feature.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Bilinear Filter feature is supported.
    - false - The Layer Bilinear Filter feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerBilinearFilterEnable( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerBilinearFilterEnable( GLCD_MODULE_ID_0, 
			                                     GLCD_LAYER_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerBilinearFilterEnable ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerBilinearFilterEnable ( GLCD_MODULE_ID index,
                                               GLCD_LAYER_ID  layerId )

  Summary:
    Enables the layer Bilinear filter of the Graphics LCD Controller.

  Description:
    This function enables the layer Bilinear filter of the Graphics LCD
    Controller.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_LayerBilinearFilterEnable( GLCD_MODULE_ID_0, GLCD_LAYER_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_LayerBilinearFilterEnable ( GLCD_MODULE_ID index,
                                           GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerBilinearFilterDisable ( GLCD_MODULE_ID index,
                                                GLCD_LAYER_ID  layerId )

  Summary:
    Disables the layer Bilinear filter of the Graphics LCD Controller.

  Description:
    This function disables the layer Bilinear filter of the Graphics LCD
    Controller.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_LayerBilinearFilterDisable( GLCD_MODULE_ID_0, GLCD_LAYER_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_LayerBilinearFilterDisable ( GLCD_MODULE_ID index,
                                            GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_LayerBilinearFilterIsEnabled ( GLCD_MODULE_ID index,
                                                  GLCD_LAYER_ID  layerId )

  Summary:
    Verify whether Layer Bilinear Filter is enabled.

  Description:
    This function verifies whether Layer Bilinear Filter is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - true - The Layer Bilinear feature is enabled.
    - false - The Layer Bilinear feature is disabled.

  Example:

    <code> 
        if ( PLIB_GLCD_LayerBilinearFilterIsEnabled( GLCD_MODULE_ID_0, 
	                                                 GLCD_LAYER_0 ) )
        {
            PLIB_GLCD_LayerBilinearFilterDisable( GLCD_MODULE_ID_0, 
			                                      GLCD_LAYER_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_LayerBilinearFilterIsEnabled ( GLCD_MODULE_ID index,
                                              GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerGlobalAlpha( GLCD_MODULE_ID index )

  Summary:
    Verify whether Layer Global Alpha Feature is supported.

  Description:
    This function verifies whether Layer Global Alpha Feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Global Alpha feature is supported.
    - false - The Layer Global Alpha feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerGlobalAlpha( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerGlobalAlphaSet( GLCD_MODULE_ID_0, 
			                               GLCD_LAYER_0,
										   MY_LAYER_GLOBAL_ALPHA_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerGlobalAlpha( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerGlobalAlphaSet( GLCD_MODULE_ID index,
                                        GLCD_LAYER_ID  layerId,
                                        uint8_t        value )

  Summary:
    Sets the layer global alpha of the Graphics LCD Controller.

  Description:
    This function sets the layer global alpha of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.
    value   - Global alpha value.

  Returns:
    None.

  Example:

    <code>
        // set global alpha value of layer 0 to 255
        PLIB_GLCD_Layer_GlobalAlpha_Set( GLCD_MODULE_ID_0, GLCD_LAYER_0, 255 )
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerGlobalAlphaSet( GLCD_MODULE_ID index,
                                    GLCD_LAYER_ID  layerId,
                                    uint8_t        value );

//******************************************************************************
/* Function: 
    uint8_t PLIB_GLCD_LayerGlobalAlphaGet( GLCD_MODULE_ID index,
                                           GLCD_LAYER_ID  layerId )

  Summary:
    Gets the Layer Global Alpha value.

  Description:
    This function gets the Layer Global Alpha value.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - Layer Alpha value

  Example:

    <code>
	    uint8_t layerAlpha;

		layerAlpha = PLIB_GLCD_LayerGlobalAlphaGet( GLCD_MODULE_ID_0
	                                                GLCD_LAYER_0	);
    </code>  

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint8_t PLIB_GLCD_LayerGlobalAlphaGet( GLCD_MODULE_ID index,
                                       GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerDestBlendFunc ( GLCD_MODULE_ID index )

  Summary:
    Verify whether Layer Destination Blend Function Feature is supported.

  Description:
    This function verifies whether Layer Destination Blend Function Feature is 
	supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Destination Blend Function feature is supported.
    - false - The Layer Destination Blend Function feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerDestBlendFunc( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerDestBlendFuncSet( GLCD_MODULE_ID_0, 
			                                 GLCD_LAYER_0,
										     MY_LAYER_DEST_BLEND_FUNC_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerDestBlendFunc ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerDestBlendFuncSet( GLCD_MODULE_ID             index,
                                          GLCD_LAYER_ID              layerId,
                                          GLCD_LAYER_DEST_BLEND_FUNC blendFunc )

  Summary:
    Sets the layer destination blend function of the Graphics LCD Controller.

  Description:
    This function sets the layer destination blend function of the Graphics LCD
    Controller.

  Precondition:
    None.

  Parameters:
    index     - Identifier of the device instance.
    layerId   - Identifier of the Graphics rendering layer.
    blendFunc - Blend function defined by GLCD_LAYER_BLEND_FUNCTION.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_LayerDestBlendFuncSet( GLCD_MODULE_ID_0, GLCD_LAYER_0,
                                         GLCD_BLEND_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerDestBlendFuncSet( GLCD_MODULE_ID             index,
                                      GLCD_LAYER_ID              layerId,
                                      GLCD_LAYER_DEST_BLEND_FUNC blendFunc );

//******************************************************************************
/* Function: 
    GLCD_LAYER_DEST_BLEND_FUNC PLIB_GLCD_LayerDestBlendFuncGet( GLCD_MODULE_ID index,
                                                                GLCD_LAYER_ID  layerId )

  Summary:
    Gets the Layer Destination Blend Function.

  Description:
    This function gets the Layer Destination Blend Function.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - GLCD_LAYER_DEST_BLEND_BLACK - Destination Blend function set to 
	                                Black = 0.
    - GLCD_LAYER_DEST_BLEND_WHITE - Destination Blend function set to 
	                                White = 255.
	- GLCD_LAYER_DEST_BLEND_ALPHA_SRC - Destination Blend function set to 
	                                    Source Alpha.
    - GLCD_LAYER_DEST_BLEND_ALPHA_GBL - Destination Blend function set to 
	                                    Global Alpha.
    - GLCD_LAYER_DEST_BLEND_ALPHA_SRCGBL - Destination Blend function set to 
	                                       ( Source * Global Alpha )
    - GLCD_LAYER_DEST_BLEND_INV_SRC - Destination Blend function set to
	                                  ( 1 - Source Alpha )
    - GLCD_LAYER_DEST_BLEND_INV_GBL - Destination Blend function set to
	                                  ( 1 - Global Alpha )
    - GLCD_LAYER_DEST_BLEND_INV_SRCGBL - Destination Blend function set to
	                                     ( 1 - ( Source Alpha * Global Alpha )).
    - GLCD_LAYER_DEST_BLEND_ALPHA_DST - Destination Blend function set to
	                                    Destination Alpha.
    - GLCD_LAYER_DEST_BLEND_INV_DST - Destination Blend function set to
	                                  ( 1 - Destination Alpha )  

  Example:

    <code>

	    uint32_t destBlendFunc;

		destBlendFunc = PLIB_GLCD_LayerDestBlendFuncGet( GLCD_MODULE_ID_0
	                                                     GLCD_LAYER_0	);

    </code>  

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

GLCD_LAYER_DEST_BLEND_FUNC PLIB_GLCD_LayerDestBlendFuncGet( GLCD_MODULE_ID index,
                                                            GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerSrcBlendFunc ( GLCD_MODULE_ID index )

  Summary:
    Verify whether Layer Source Blend Function Feature is supported.

  Description:
    This function verifies whether Layer Source Blend Function Feature is 
	supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Source Blend Function feature is supported.
    - false - The Layer Source Blend Function feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerSrcBlendFunc( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerSrcBlendFuncSet( GLCD_MODULE_ID_0, 
			                                GLCD_LAYER_0,
										    MY_LAYER_SRC_BLEND_FUNC_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerSrcBlendFunc ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerSrcBlendFuncSet( GLCD_MODULE_ID             index,
                                         GLCD_LAYER_ID              layerId,
                                         GLCD_LAYER_SRC_BLEND_FUNC  blendFunc )

  Summary:
    Sets the layer source blend function of the Graphics LCD Controller.

  Description:
    This function sets the layer source blend function of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index     - Identifier of the device instance.
    layerId   - Identifier of the Graphics rendering layer.
    blendFunc - Blend function defined by GLCD_LAYER_BLEND_FUNCTION.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_LayerSrcBlendFuncSet( GLCD_MODULE_ID_0, GLCD_LAYER_0,
                                       GLCD_BLEND_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_LayerSrcBlendFuncSet( GLCD_MODULE_ID            index,
                                     GLCD_LAYER_ID             layerId,
                                     GLCD_LAYER_SRC_BLEND_FUNC blendFunc );

//******************************************************************************
/* Function: 
    GLCD_LAYER_SRC_BLEND_FUNC PLIB_GLCD_LayerSrcBlendFuncGet( GLCD_MODULE_ID index,
                                                              GLCD_LAYER_ID  layerId )

  Summary:
    Gets the Layer Source Blend Function.

  Description:
    This function gets the Layer Source Blend Function.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - GLCD_LAYER_SRC_BLEND_BLACK - Source Blend Function set to Black = 0.
    - GLCD_LAYER_SRC_BLEND_WHITE - Source Blend Function set to White = 255.
    - GLCD_LAYER_SRC_BLEND_ALPHA_SRC - Source Blend Function set to 
	                                   Source Alpha.
    - GLCD_LAYER_SRC_BLEND_ALPHA_GBL - Source Blend Function set to 
	                                   Global Alpha.
    - GLCD_LAYER_SRC_BLEND_ALPHA_SRCGBL - Source Blend Function set to 
	                                      ( Source Alpha * Global Alpha ).
    - GLCD_LAYER_SRC_BLEND_INV_SRC - Source Blend Function set to 
	                                 ( 1 - Source Alpha ).
    - GLCD_LAYER_SRC_BLEND_INV_GBL - Source Blend Function set to 
	                                 ( 1 - Global Alpha ).
    - GLCD_LAYER_SRC_BLEND_INV_SRCGBL - Source Blend Function set to 
	                                    ( 1 - ( Source Alpha * Global Alpha ) )
    - GLCD_LAYER_SRC_BLEND_ALPHA_DST - Source Blend Function set to 
	                                   Destination Alpha
    - GLCD_LAYER_SRC_BLEND_INV_DST - Source Blend Function set to 
                                     ( 1 - Destination Alpha )	

  Example:

    <code>

	    uint32_t srcBlendFunc;

		srcBlendFunc = PLIB_GLCD_LayerSrcBlendFuncGet( GLCD_MODULE_ID_0
	                                                   GLCD_LAYER_0	);

    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

GLCD_LAYER_SRC_BLEND_FUNC PLIB_GLCD_LayerSrcBlendFuncGet( GLCD_MODULE_ID index,
                                                          GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerColorMode ( GLCD_MODULE_ID index )

  Summary:
    Verify whether Layer Color Mode is supported.

  Description:
    This function verifies whether Layer Color Mode is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Color Mode feature is supported.
    - false - The Layer Color Mode feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerColorMode( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerColorModeSet( GLCD_MODULE_ID_0, 
			                             GLCD_LAYER_0,
										 MY_LAYER_COLOR_MODE_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerColorMode ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerColorModeSet( GLCD_MODULE_ID         index,
                                      GLCD_LAYER_ID          layerId,
                                      GLCD_LAYER_COLOR_MODE  colorMode )

  Summary:
    Sets the layer color mode of the Graphics LCD Controller.

  Description:
    This function sets the layer color mode of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index     - Identifier of the device instance.
    layerId   - Identifier of the Graphics rendering layer.
    colorMode - Color mode defined by GLCD_LAYER_COLOR_MODE.

  Returns:
    None.

  Example:

    <code>
        // Set layer color mode to RGB232
        PLIB_GLCD_LayerColorModeSet( GLCD_MODULE_ID_0, GLCD_LAYER_0,
                                    GLCD_LAYER_COLOR_MODE_RGB232 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerColorModeSet( GLCD_MODULE_ID         index,
                                  GLCD_LAYER_ID          layerId,
                                  GLCD_LAYER_COLOR_MODE  colorMode );

//******************************************************************************
/* Function: 
    GLCD_LAYER_COLOR_MODE PLIB_GLCD_LayerColorModeGet( GLCD_MODULE_ID index,
                                                       GLCD_LAYER_ID  layerId );

  Summary:
    Gets the Layer Color Mode.

  Description:
    This function gets the Layer Color Mode

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - GLCD_LAYER_COLOR_MODE_LUT8 - Layer Color Mode set to LUT8
    - GLCD_LAYER_COLOR_MODE_RGBA5551 - Layer Color Mode set to RGBA5551
    - GLCD_LAYER_COLOR_MODE_RGBA8888 - Layer Color Mode set to RGBA8888
    - GLCD_LAYER_COLOR_MODE_RGB332 - Layer Color Mode set to RGB 332
    - GLCD_LAYER_COLOR_MODE_RGB565 - Layer Color Mode set to RGB565
    - GLCD_LAYER_COLOR_MODE_ARGB8888 - Layer Color Mode set to ARGB8888
    - GLCD_LAYER_COLOR_MODE_L8 - Layer Color Mode set to L8
    - GLCD_LAYER_COLOR_MODE_L1 - Layer Color Mode set to L1
    - GLCD_LAYER_COLOR_MODE_L4 - Layer Color Mode set to L4
    - GLCD_LAYER_COLOR_MODE_YUYV - Layer Color Mode set to YUYV
    - GLCD_LAYER_COLOR_MODE_RGB888 - Layer Color Mode set to RGB888

  Example:

    <code>
	    uint32_t colorMode;

		colorMode = PLIB_GLCD_LayerColorModeGet( GLCD_MODULE_ID_0
	                                             GLCD_LAYER_0	);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

GLCD_LAYER_COLOR_MODE PLIB_GLCD_LayerColorModeGet( GLCD_MODULE_ID index,
                                                   GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerStartXY ( GLCD_MODULE_ID index )

  Summary:
    Verify whether Layer Start XY Position feature is supported.

  Description:
    This function verifies whether  Layer Start XY Position feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Start feature is supported.
    - false - The Layer Start feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerStartXY( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerStartXYSet( GLCD_MODULE_ID_0, 
			                           GLCD_LAYER_0,
									   MY_LAYER_START_X_VALUE,
									   MY_LAYER_START_Y_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerStartXY ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerStartXYSet( GLCD_MODULE_ID index,
                                    GLCD_LAYER_ID  layerId,
                                    uint32_t       startX,
                                    uint32_t       startY )

  Summary:
    Sets the layer start x and start y of the Graphics LCD Controller.

  Description:
    This function sets the layer start x and start y of the Graphics LCD
    Controller.

  Precondition:
    None

  Parameters:
    index   - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.
    startX  - Layer start on x axis in terms of pixels.
    startY  - Layer start on y axis in terms of pixels.

  Returns:
    None.

  Example:

    <code>
        // set layer start to (20, 20)
        PLIB_GLCD_LayerStartXYSet( GLCD_MODULE_ID_0, GLCD_LAYER_0, 20, 20);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerStartXYSet( GLCD_MODULE_ID index,
                                GLCD_LAYER_ID  layerId,
                                uint32_t      startX,
                                uint32_t      startY );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_LayerStartXGet( GLCD_MODULE_ID index,
                                       GLCD_LAYER_ID  layerId );

  Summary:
    Gets the Layer X Axis Start Position.

  Description:
    This function gets the Layer X Axis Start Position.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - Layer Start X value.

  Example:

   <code>
	    uint32_t startX;

		startX	= PLIB_GLCD_LayerStartXGet( GLCD_MODULE_ID_0
	                                        GLCD_LAYER_0	);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_LayerStartXGet( GLCD_MODULE_ID index,
                                   GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_LayerStartYGet( GLCD_MODULE_ID index,
                                       GLCD_LAYER_ID  layerId );

  Summary:
    Gets the Layer Y Axis Start Position.

  Description:
    This function gets the Layer Y Axis Start Position.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - Layer Start Y value.

  Example:

    <code>
	    uint32_t startY;

		startY	= PLIB_GLCD_LayerStartYGet( GLCD_MODULE_ID_0
	                                        GLCD_LAYER_0	);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_LayerStartYGet( GLCD_MODULE_ID index,
                                   GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerSizeXY ( GLCD_MODULE_ID index )

  Summary:
    Verify whether Layer X Axis and Y Axis Size feature is supported.

  Description:
    This function verifies whether Layer X Axis and Y Axis Size feature is 
	supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Size feature is supported.
    - false - The Layer Size feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerSizeXY( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerSizeXYSet( GLCD_MODULE_ID_0, 
			                          GLCD_LAYER_0,
									  MY_LAYER_SIZE_X_VALUE,
									  MY_LAYER_SIZE_Y_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerSizeXY ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerSizeXYSet( GLCD_MODULE_ID index,
                                   GLCD_LAYER_ID  layerId,
                                   uint32_t       sizeX,
                                   uint32_t       sizeY )

  Summary:
    Sets the layer size x and size y of the Graphics LCD Controller.

  Description:
    This function sets the layer start x and start y of the Graphics LCD
    Controller.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.
    sizeX   - Layer size on x axis in terms of pixels.
    sizeY   - Layer size on y axis in terms of pixels.

  Returns:
    None.

  Example:

    <code>
        // set layer size to (640, 480)
        PLIB_GLCD_LayerSizeXYSet( GLCD_MODULE_ID_0, GLCD_LAYER_0, 640, 480);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_LayerSizeXYSet( GLCD_MODULE_ID index,
                               GLCD_LAYER_ID  layerId,
                               uint32_t      sizeX,
                               uint32_t      sizeY );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_LayerSizeXGet( GLCD_MODULE_ID index, GLCD_LAYER_ID layerId )

  Summary:
    Gets the Layer X Axis Size.
	
  Description:
    This function gets the Layer X Axis Size.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - Layer Size X value.

  Example:

   <code>
	    uint32_t sizeX;

		startX	= PLIB_GLCD_LayerSizeXGet( GLCD_MODULE_ID_0
	                                       GLCD_LAYER_0	);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_LayerSizeXGet( GLCD_MODULE_ID index, GLCD_LAYER_ID layerId );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_LayerSizeYGet( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId )

  Summary:
    Gets the Layer Y Axis Size.

  Description:
    This function gets the Layer Y Axis Size.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - Layer Size Y value.

  Example:

   <code>
	    uint32_t sizeY;

		sizeY	= PLIB_GLCD_LayerSizeYGet( GLCD_MODULE_ID_0
	                                       GLCD_LAYER_0	);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_LayerSizeYGet( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerBaseAddress ( GLCD_MODULE_ID index )

  Summary:
    Verify whether the Layer Base Address feature is supported.

  Description:
    This function verifies whether the Layer Base Address feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Base Address feature is supported.
    - false - The Layer Base Address feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerBaseAddress( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerBaseAddressSet( GLCD_MODULE_ID_0, 
			                               GLCD_LAYER_0,
									       MY_LAYER_BASE_ADDRESS_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerBaseAddress ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerBaseAddressSet( GLCD_MODULE_ID index,
                                        GLCD_LAYER_ID  layerId,
                                        uint32_t       baseAddress )

  Summary:
    Sets the base address of layer surface of the Graphics LCD Controller.

  Description:
    This function sets the layer base address of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index       - Identifier of the device instance.
    layerId     - Identifier of the Graphics rendering layer.
    baseAddress - baseAddress of layer surface.

  Returns:
    None.

  Example:

    <code>
        // Set layer 0 surface base address as 0x20000000
        PLIB_GLCD_LayerBaseAddressSet( GLCD_MODULE_ID_0, GLCD_LAYER_0, 0x20000000 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerBaseAddressSet( GLCD_MODULE_ID index,
                                    GLCD_LAYER_ID  layerId,
                                    uint32_t       baseAddress );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_LayerBaseAddressGet( GLCD_MODULE_ID index, 
                                            GLCD_LAYER_ID  layerId )

  Summary:
    Gets the Layer Base Address.

  Description:
    This function sets the Layer Base Address.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - Layer base address value.

  Example:

   <code>

	    uint32_t layerBaseAddress;

		layerBaseAddress = PLIB_GLCD_LayerBaseAddressGet( GLCD_MODULE_ID_0
	                                                      GLCD_LAYER_0	);

    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_LayerBaseAddressGet( GLCD_MODULE_ID index, 
                                        GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerStride( GLCD_MODULE_ID index )

  Summary:
    Verify whether the Layer Stride Feature is supported.

  Description:
    This function verifies whether the Layer Stride Feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Stride feature is supported.
    - false - The Layer Stride feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerStride( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerStrideSet( GLCD_MODULE_ID_0, 
			                          GLCD_LAYER_0,
									  MY_LAYER_STRIDE_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerStride( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerStrideSet( GLCD_MODULE_ID index,
                                   GLCD_LAYER_ID  layerId,
                                   uint32_t       stride )

  Summary:
    Sets the layer surface stride of the Graphics LCD Controller.

  Description:
    This function sets the layer surface stride of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index          - Identifier of the device instance.
    layerId        - Identifier of the Graphics rendering layer.
    stride         - line width in bytes including padding.

  Returns:
    None.

  Example:

    <code>
        uint32_t imageStride = IMAGE_WIDTH * IMAGE_BYTES_PER_PIXEL;

        // To make stride 4 byte aligned
        imageStride += ( imageStride % 4 );

        PLIB_GLCD_LayerStrideSet( GLCD_MODULE_ID_0, GLCD_LAYER_0,
                                  imageStride );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerStrideSet( GLCD_MODULE_ID index,
                               GLCD_LAYER_ID  layerId,
                               uint32_t       stride );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_LayerStrideGet( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId )

  Summary:
    Gets the Layer Stride value.

  Description:
    This function gets the Layer Stride value.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - value of the stride.

  Example:

   <code>

	    uint32_t layerStride;

		layerStride = PLIB_GLCD_LayerStrideGet( GLCD_MODULE_ID_0
	                                            GLCD_LAYER_0	);

    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_LayerStrideGet( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsLayerResXY( GLCD_MODULE_ID index )

  Summary:
    
  Description:

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Layer Resolution feature is supported.
    - false - The Layer Resolution feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsLayerResXY( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_LayerResXYSet( GLCD_MODULE_ID_0, 
			                         GLCD_LAYER_0,
									 MY_LAYER_RES_X_VALUE,
									 MY_LAYER_RES_Y_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsLayerResXY( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_LayerResXYSet( GLCD_MODULE_ID index,
                                  GLCD_LAYER_ID  layerId,
                                  uint32_t       resolutionX,
                                  uint32_t       resolutionY )

  Summary:
    Sets the layer resolution in pixels.

  Description:
    This function sets the layer resolution in pixels. The resolution is defined as
    the number of pixels on the x axis and the number of pixels on the y axis.

  Precondition:
    None.

  Parameters:
    index       - Identifier of the device instance.
    layerId     - Identifier of the Graphics rendering layer.
    resolutionX - resolution on x axis in terms of pixels.
    resolutionY - resolution on y axis in terms of pixels.

  Returns:
    None.

  Example:

    <code>
        // Layer resolution set to x = 320 pixels and y = 240 pixels
        PLIB_GLCD_Layer_ResXY_Set( GLCD_MODULE_ID_0, GLCD_LAYER_0, 320, 240);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_LayerResXYSet( GLCD_MODULE_ID index,
                              GLCD_LAYER_ID  layerId,
                              uint32_t       resolutionX,
                              uint32_t       resolutionY );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_LayerResXGet( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId )

  Summary:
    Gets the Layer X Axis Resolution.

  Description:
    This function gets the Layer X Axis Resolution.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - value of layer x axis resolution.

  Example:

   <code>
	    uint32_t resolutionX;

		resolutionX = PLIB_GLCD_LayerResXGet( GLCD_MODULE_ID_0
	                                          GLCD_LAYER_0	);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_LayerResXGet( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_LayerResYGet( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId )

  Summary:
    Gets the Layer Y Axis Resolution.

  Description:
    This function gets the Layer Y Axis Resolution.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    layerId - Identifier of the Graphics rendering layer.

  Returns:
    - value of layer y axis resolution.

  Example:

   <code>
	    uint32_t resolutionY;

		resolutionY = PLIB_GLCD_LayerResYGet( GLCD_MODULE_ID_0
	                                          GLCD_LAYER_0	);
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_LayerResYGet( GLCD_MODULE_ID index, GLCD_LAYER_ID  layerId );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsIRQTriggerControl( GLCD_MODULE_ID index )

  Summary:
    Verify whether the IRQ Trigger Control feature is supported.

  Description:
    This function verifies whether the IRQ Trigger Control feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The IRQ Trigger Control feature is supported.
    - false - The IRQ Trigger Control feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsIRQTriggerControl( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_IRQTriggerControlSet( GLCD_MODULE_ID_0, 
			                                MY_IRQ_TRIGGER_CONTROL );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsIRQTriggerControl( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_IRQTriggerControlSet( GLCD_MODULE_ID index,
                                         GLCD_IRQ_TRIGGER_CONTROL irqControl)

  Summary:
    Sets the IRQ trigger control.

  Description:
    This function sets the IRQ trigger control. IRQ trigger detection is defined
    at the edge or level of the trigger pulse.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    control - Trigger control defined by GLCD_IRQ_TRIGGER_CONTROL.

  Returns:
    None.

  Example:

    <code>
        // Set trigger detection at edge
        PLIB_GLCD_IRQTriggerControlSet( GLCD_MODULE_ID_0, GLCD_IRQ_TRIGGER_EDGE );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_IRQTriggerControlSet( GLCD_MODULE_ID           index,
                                     GLCD_IRQ_TRIGGER_CONTROL irqControl);

//******************************************************************************
/* Function: 
    GLCD_IRQ_TRIGGER_CONTROL PLIB_GLCD_IRQTriggerControlGet( GLCD_MODULE_ID index )

  Summary:
    Gets the IRQ Trigger Control value.

  Description:
    This function gets the IRQ Trigger Control value.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - GLCD_IRQ_TRIGGER_LEVEL - IRQ is Level Triggered.
    - GLCD_IRQ_TRIGGER_EDGE - IRQ is edge Triggered.

  Example:

    <code>
	    uint32_t irqTrigger;

		irqTrigger = PLIB_GLCD_IRQTriggerControlGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

GLCD_IRQ_TRIGGER_CONTROL PLIB_GLCD_IRQTriggerControlGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsHSyncInterruptEnable( GLCD_MODULE_ID index )

  Summary:
    Verify whether the HSYNC Interrupt Enable feature is supported.

  Description:
    This function verifies whether the HSYNC Interrupt Enable feature is 
	supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The HSYNC Interrupt Enable feature is supported.
    - false - The HSYNC Interrupt Enable feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsHSyncInterruptEnable( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_HSyncInterruptEnable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsHSyncInterruptEnable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_HSyncInterruptEnable( GLCD_MODULE_ID  index )

  Summary:
    Enables interrupts at Hsync.

  Description:
    This function enables interrupts at Hsync.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_HSyncInterruptEnable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_HSyncInterruptEnable( GLCD_MODULE_ID  index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_HSyncInterruptDisable( GLCD_MODULE_ID  index )

  Summary:
    Disables interrupts at Hsync.

  Description:
    This function disables interrupts at Hsync.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_HsyncInterruptDisable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_HSyncInterruptDisable( GLCD_MODULE_ID  index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_HSyncInterruptIsEnabled( GLCD_MODULE_ID index )

  Summary:
    Verify whether HSYNC Interrupt is enabled.

  Description:
    This function verifies whether HSYNC Interrupt is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The HSYNC Interrupt feature is enabled.
    - false - The HSYNC Interrupt feature is disabled.

  Example:

    <code> 
        if ( PLIB_GLCD_HSyncInterruptIsEnabled( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_HSyncInterruptDisable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_HSyncInterruptIsEnabled( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsVSyncInterruptEnable( GLCD_MODULE_ID index )

  Summary:
    Verify whether VSYNC Interrupt Enable feature is supported.

  Description:
    This function verifies whether VSYNC Interrupt Enable feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The VSYNC Interrupt Enable feature is supported.
    - false - The VSYNC Interrupt Enable feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsVSyncInterruptEnable( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_VSyncInterruptEnable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsVSyncInterruptEnable( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_VSyncInterruptEnable( GLCD_MODULE_ID  index )

  Summary:
    Enables interrupts at Vsync.

  Description:
    This function enables interrupts at Vsync.

  Precondition:
    None

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_VSyncInterruptEnable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.

*/

void PLIB_GLCD_VSyncInterruptEnable( GLCD_MODULE_ID  index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_VSyncInterruptDisable( GLCD_MODULE_ID  index )

  Summary:
    Disables interrupts at Vsync.

  Description:
    This function disables interrupts at Vsync.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    None.

  Example:

    <code>
        PLIB_GLCD_VsyncInterruptDisable( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_VSyncInterruptDisable( GLCD_MODULE_ID  index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_VSyncInterruptIsEnabled( GLCD_MODULE_ID index )

  Summary:
    Verify whether VSYNC Interrupt is enabled.

  Description:
    This function verifies whether the VSYNC Interrupt is enabled.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The VSYNC Interrupt feature is enabled.
    - false - The VSYNC Interrupt feature is disabled.

  Example:

    <code> 
        if ( PLIB_GLCD_VSyncInterruptIsEnabled( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_VSyncInterruptDisable( GLCD_MODULE_ID_0 );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_VSyncInterruptIsEnabled( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsIsVerticalBlankingActive( GLCD_MODULE_ID index )

  Summary:
    Verify whether Is Vertical Blanking Active feature is supported.

  Description:
    This function verifies whether Is Vertical Blanking Active feature is
	supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Is Vertical Blanking feature is supported.
    - false - The Is Vertical Blanking feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsIsVerticalBlankingActive( GLCD_MODULE_ID_0 ) )
        {
            if( PLIB_GLCD_IsVerticalBlankingActive( GLCD_MODULE_ID_0 ) )
			{
			   // Vertical Blanking Active
			}
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsIsVerticalBlankingActive( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_IsVerticalBlankingActive( GLCD_MODULE_ID index )

  Summary:
    Get the active status.

  Description:
    This function returns the active status of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The Vertical Blanking is active.
    - false - The Vertical Blanking is inactive.

  Example:

    <code>
        if( PLIB_GLCD_IsVerticalBlankingActive( GLCD_MODULE_ID_0 ) )
        {
            //GLCD Vertical Blanking active
            return;
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_IsVerticalBlankingActive( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsDESignalLevel( GLCD_MODULE_ID index )

  Summary:
    Verify whether DE Signal Level feature is supported.

  Description:
    This function verifies whether DE Signal Level feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The DE Signal Level feature is supported.
    - false - The DE Signal Level feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsDESignalLevel( GLCD_MODULE_ID_0 ) )
        {
            if( PLIB_GLCD_DESignalLevelGet( GLCD_MODULE_ID_0 ) )
			{
			   // DE Signal Level High
			}
        }
    </code>
  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsDESignalLevel( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_DESignalLevelGet( GLCD_MODULE_ID index )

  Summary:
    Gets the display enable signal level.

  Description:
    This function returns the display enable (DE) signal of the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The DE signal level high.
    - false - The DE signal level low.

  Example:

    <code>
        if(!PLIB_GLCD_DESignalLevelGet( GLCD_MODULE_ID_0 ));
        {
            //DE signal low
            return;
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_DESignalLevelGet( GLCD_MODULE_ID  index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsHSyncSignalLevel( GLCD_MODULE_ID index )

  Summary:
    Verify whether HSYNC Signal Level feature is supported.

  Description:
    This function verifies whether the HSYNC Signal Level feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The HSYNC Signal Level feature is supported.
    - false - The HSYNC Signal Level feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsHSyncSignalLevel( GLCD_MODULE_ID_0 ) )
        {
            if( PLIB_GLCD_HSyncSignalLevelGet( GLCD_MODULE_ID_0 ) )
			{
			   // HSYNC Signal Level High
			}
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsHSyncSignalLevel( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
     bool PLIB_GLCD_HSyncSignalLevelGet( GLCD_MODULE_ID  index )

  Summary:
    Gets the Hsync signal level.

  Description:
    This function returns the Hsync signal level.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The Hsync signal level is high.
    - false - The Hsync signal level is low.

  Example:

    <code>
        if(!PLIB_GLCD_HSyncSignalLevelGet( GLCD_MODULE_ID_0 ));
        {
            //Hsync signal level is low
            return;
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_HSyncSignalLevelGet( GLCD_MODULE_ID  index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsVSyncSignalLevel( GLCD_MODULE_ID index )

  Summary:
    Verify whether VSYNC Signal Level feature is supported.

  Description:
    This function verifies whether VSYNC Signal Level feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The VSYNC Signal Level feature is supported.
    - false - The VSYNC Signal Level feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsVSyncSignalLevel( GLCD_MODULE_ID_0 ) )
        {
            if( PLIB_GLCD_VSyncSignalLevelGet( GLCD_MODULE_ID_0 ) )
			{
			   // VSYNC Signal Level High
			}
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsVSyncSignalLevel( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_VSyncSignalLevelGet( GLCD_MODULE_ID  index )

  Summary:
    Gets the Vsync signal level.

  Description:
    This function returns the Vsync signal level.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The Vsync signal level is high.
    - false - The Vsync signal level is low.

  Example:

    <code>
        if(!PLIB_GLCD_VSyncSignalLevelGet( GLCD_MODULE_ID_0 ));
        {
            //Vsync signal level is low
            return;
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_VSyncSignalLevelGet( GLCD_MODULE_ID  index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsIsLastRow( GLCD_MODULE_ID index )

  Summary:
    Verify whether Is Last Row Feature is supported.

  Description:
    This function verifies whether Is Last Row Feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Is Last Row feature is supported.
    - false - The Is Last Row feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsIsLastRow( GLCD_MODULE_ID_0 ) )
        {
            if( PLIB_GLCD_IsLastRow( GLCD_MODULE_ID_0 ) )
			{
			   // Last row currently displayed
			}
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsIsLastRow( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_IsLastRow( GLCD_MODULE_ID  index )

  Summary:
    Gets the status indicating whether a last row is currently displayed by the 
	Graphics Display Controller.

  Description:
    This function returns the status indicating whether a last row is currently 
	displayed by the Graphics LCD Controller.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true  - The last row is currently displayed.
    - false - The last row is not currently displayed.

  Example:

    <code>
        if(!PLIB_GLCD_IsLastRow( GLCD_MODULE_ID_0 ));
        {
            // The last row is not currently displayed
            return;
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_IsLastRow( GLCD_MODULE_ID  index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsGlobalColorLUT( GLCD_MODULE_ID index )

  Summary:
    Verify whether Global Color LUT feature is supported.

  Description:
    This function verifies whether Global Color LUT feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Global Color LUT feature is supported.
    - false - The Global Color LUT feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsGlobalColorLUT( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_GlobalColorLUTSet( GLCD_MODULE_ID_0,
		                                 MY_GLOBAL_LUT_POINTER_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsGlobalColorLUT ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_GlobalColorLUTSet( GLCD_MODULE_ID index, uint32_t *globalLUT )

  Summary:
    Set Global Color LUT.

  Description:
    This function sets the Global Color LUT.

  Precondition:
    None.

  Parameters:
    index     - Identifier of the device instance.
    globalLUT - pointer of the Global Color Lookup table data array.

  Returns:
    None.

  Example:

    <code>
	    uint32_t globalColorLUT[256] = { // Initial values 
		                         };
        PLIB_GLCD_GlobalColorLUTSet( GLCD_MODULE_ID_0, globalColorLUT );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_GlobalColorLUTSet( GLCD_MODULE_ID index, uint32_t *globalLUT );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_GlobalColorLUTGet( GLCD_MODULE_ID index, uint32_t lutIndex )

  Summary:
    Gets the Color from Global Color LUT at given Index.

  Description:
    This function gets the Color from Global Color LUT at given Index.

  Precondition:
    None.

  Parameters:
    index    - Identifier of the device instance.
    lutIndex - Color Lookup table index.
 
  Returns:
    - value of Color from the Color Lookup Table.

  Example:

    <code>

	    uint32_t lutColor;

		lutColor = PLIB_GLCD_GlobalColorLUTGet( GLCD_MODULE_ID_0, 
		                                        MY_LUT_COLOR_INDEX );

    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_GlobalColorLUTGet( GLCD_MODULE_ID index, uint32_t lutIndex );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsCursorXY( GLCD_MODULE_ID index )

  Summary:
    Verify whether Cursor XY Position feature is supported.

  Description:
    This function verifies whether Cursor XY Position feature is supported. 

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Cursor Position feature is supported.
    - false - The Cursor Position feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsCursorXY( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_CursorXYSet( GLCD_MODULE_ID_0,
		                           MY_CURSOR_POSITION_X_VALUE,
								   MY_CURSOR_POSITION_Y_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsCursorXY ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_CursorXYSet( GLCD_MODULE_ID index, 
	                            uint32_t cursorX,
                                uint32_t cursorY )

  Summary:
    Sets the x and y coordinates of the Graphics LCD Controller cursor.

  Description:
    This function sets the x and y coordinates of the Graphics Display Controller 
	cursor.

  Precondition:
    None.

  Parameters:
    index   - Identifier of the device instance.
    cursorX - cursor coordinate on x axis in terms of pixels.
    cursorY - cursor coordinate on y axis in terms of pixels.

  Returns:
    None.

  Example:

    <code>
        // update cursor position at x:20 pixels and y:20 pixels
        PLIB_GLCD_CursorXYSet( GLCD_MODULE_ID_0, 20, 20 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_CursorXYSet( GLCD_MODULE_ID index,
                           uint32_t      cursorX,
                           uint32_t      cursorY );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_CursorXGet( GLCD_MODULE_ID index )

  Summary:
    Gets the cursor X Axis Position.

  Description:
    This function gets the cursor X Axis Position.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - Cursor X Axis Position.

  Example:

   <code>
	    uint32_t cursorX;

		cursorX = PLIB_GLCD_CursorXGet( GLCD_MODULE_ID_0 );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_CursorXGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_CursorYGet( GLCD_MODULE_ID index )

  Summary:
    Gets the Cursor Y Axis Position.

  Description:
    This function gets the Cursor Y Axis Position.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - Cursor Y Axis Position.

  Example:

   <code>
	    uint32_t cursorY;

		cursorY = PLIB_GLCD_CursorYGet( GLCD_MODULE_ID_0 );
   </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_CursorYGet( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsCursorData( GLCD_MODULE_ID index )

  Summary:
    
  Description:

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Cursor Data feature is supported.
    - false - The Cursor Data feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsCursorData( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_CursorDataSet( GLCD_MODULE_ID_0,
		                             MY_CURSOR_DATA_POINTER_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsCursorData ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_CursorDataSet( GLCD_MODULE_ID index, uint32_t * cursorData )

  Summary:
    Sets the cursor image data.

  Description:
    This function sets the cursor image data. The image data format is 4-bit black, 
	white and 50 percent gray color.

  Precondition:
    None.

  Parameters:
    index      - Identifier of the device instance.
    cursorData - pointer to cursor data in the format 4-bit CLUT Index.

  Returns:
    None.

  Example:

    <code>
        uint32_t *cursorData = cursorDataAddress;

        // Set cursor data in the format: 4-bit CLUT Index
        PLIB_GLCD_CursorDataSet( GLCD_MODULE_ID_0, cursorData );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_CursorDataSet( GLCD_MODULE_ID  index,
                              uint32_t      * cursorData );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_CursorDataGet( GLCD_MODULE_ID index, uint32_t dataIndex )

  Summary:
    Gets the Cursor Data at given Index.

  Description:
    This function gets the Cursor Data at given Index.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    dataIndex - Index of the Cursor data.

  Returns:
    - value of the 8 pixels of the cursor at given index.

  Example:

    <code>
	    uint32_t cursorData;

		cursorData = PLIB_GLCD_CursorDataGet( GLCD_MODULE_ID_0,
		                                      MY_CURSOR_DATA_INDEX );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_CursorDataGet( GLCD_MODULE_ID index, uint32_t dataIndex );

//******************************************************************************
/* Function: 
    bool PLIB_GLCD_ExistsCursorLUT( GLCD_MODULE_ID index )

  Summary:
    Verify whether Cursor LUT feature is supported.

  Description:
    This function verifies whether Cursor LUT feature is supported.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.

  Returns:
    - true - The Cursor LUT feature is supported.
    - false - The Cursor LUT feature is not supported.

  Example:

    <code>
        if( PLIB_GLCD_ExistsCursorLUT( GLCD_MODULE_ID_0 ) )
        {
            PLIB_GLCD_CursorLUTSet( GLCD_MODULE_ID_0,
		                            MY_CURSOR_LUT_DATA_POINTER_VALUE );
        }
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

bool PLIB_GLCD_ExistsCursorLUT ( GLCD_MODULE_ID index );

//******************************************************************************
/* Function: 
    void PLIB_GLCD_CursorLUTSet( GLCD_MODULE_ID index, uint32_t * cursorLUT )

  Summary:
    Sets the cursor color look-up table (LUT) in XRGB8888 format.

  Description:
    This function sets the cursor color LUT of the Graphics LCD Controller in
    XRGB8888 format.

  Precondition:
    None.

  Parameters:
    index     - Identifier of the device instance.
    cursorLUT - Pointer to the cursor color LUT in XRGB8888 format.

  Returns:
    None.

  Example:

    <code>
        uint32_t * cursorLUTColors = cursorLUTAddress;

        PLIB_GLCD_CursorLUTSet( GLCD_MODULE_ID_0, cursorLUTColors );
    </code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

void PLIB_GLCD_CursorLUTSet( GLCD_MODULE_ID index,
                             uint32_t       * cursorLUT );

//******************************************************************************
/* Function: 
    uint32_t PLIB_GLCD_CursorLUTGet( GLCD_MODULE_ID index, uint32_t lutIndex )

  Summary:
    Gets the color from Cursor LUT at given Index.

  Description:
    This function gets the color from Cursor LUT at given Index.

  Precondition:
    None.

  Parameters:
    index - Identifier of the device instance.
    lutIndex - Cursor Color LUT index.

  Returns:
    - value of color from color LUT at given index.

  Example:

    <code>
        uint32_t cursorLUTColor;

		cursorLUTColor = PLIB_GLCD_CursorLUTGet( GLCD_MODULE_ID_0,
		                                         MY_CURSOR_CLUT_INDEX );
	</code>

  Remarks:
    This functionality is not available on all devices. Please refer to the
    specific device data sheet to determine availability.
*/

uint32_t PLIB_GLCD_CursorLUTGet( GLCD_MODULE_ID index, uint32_t lutIndex );

// ****************************************************************************
// ****************************************************************************
// Section: Included Files (continued)
// ****************************************************************************
// ****************************************************************************
/*  The following included file maps the interface definitions above to appropriate
    implementations defined in the implementation (imp) file(s).
*/
//#include "peripheral/glcd/processor/glcd_processor.h"

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
    
#endif //_PLIB_GLCD_H

//******************************************************************************
/* End of File
*/
