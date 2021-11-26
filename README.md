# TerminalUSB

This is a modified firmware for [Geoff Graham's ASCII Video Terminal](http://geoffg.net/terminal.html) which 
changes it to use a keyboard connected to the USB port instead of the PS/2 port. All other features of the
terminal are identical to the original, except for the USB-to-serial bridge functionality (since the USB port
is now used for the keyboard).

## Hardware

No modification to the original hardware is necessary. There are a couple of things to note:

1. *USB Connector*. The USB connector on Geoff's terminal is used to plug the terminal
into a computer as a client device, therefore the socket on the board is a USB type B client side
connector. To plug in a keyboard, you need a type A host side connector. You can use an adapter
like [this](https://www.computercablestore.com/usb-20-adapter-usb-a-female-to-usb-b-male) 
(or [this](https://www.showmecables.com/micro-usb-2-b-male-to-a-female-6-in) 
or [this](https://www.computercablestore.com/usb-adapter-usb-a-female-to-usb-mini-5-male) depending on your socket).

2. *Power supply*. Since the USB socket is taken up by the keyboard, it can no longer be used to power
the Terminal. You need to power the terminal from the external 5V power connector. *Additionally* you
need to place a jumper on the "USB PWR" jumper pad so the keyboard receives power.

## Software

The new software can be applied as a firmware update to the Terminal. Just follow 
[Geoff's instructions](http://geoffg.net/Downloads/Terminal/Terminal_V1.3_UPGRADE.zip) from his V1.3 firmware update,
When loading the HEX file, use [this](https://raw.githubusercontent.com/dhansel/TerminalUSB/master/TerminalUSB_V1.3_UPGRADE.hex)
instead of the HEX file in Geoff's archive. It is always possible to revert the Terminal to the original
state by (re-)applying Geoff's original V1.3 update.

## Keyboard Compatibility

This firmware requires the USB keyboard to be directly connected to the Terminal's
USB socket. If there is a USB hub in between the terminal and the keyboard then the keyboard will not work.
Some keyboards have built-in USB hubs and those will not work either. If your keyboard has one or more
USB sockets on it (to connect a mouse for example) then it likely contains a USB hub and will not work.

## Source Code

The source code is provided in the "[firmware](https://github.com/dhansel/TerminalUSB/tree/master/firmware)" 
subdirectory. The main parts are almost identical (with minor modifications) to Geoff's code, except for the
USB keyboard support. To compile, use MPLAB X version 4.05 or later. There are two different configurations,
"Bootload" and "Programmer". Use "Bootload" to create a .hex file that can be uploaded via the bootloader.
Use "Programmer" to create a .hex file that can be uploaded directly via the MPLAB (IDE or IPE).
Note that when the "bootload" configuration is selected you will not be able to run or debug the code from 
within the MPLAB X IDE (will upload but not run properly).

Recently (as of October 2021) I have received feedback from two people who compiled the code with a 
recent version of MPLAB X. This required installing some extra legacy library and compilers.

**Steve Willoughby** (steve@madscience.zone) did the following to successfully compile the code:
- Download and install the 1.40 version of the XC32 compiler:
  - Go to  https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-ecosystem-downloads-archive 
  - Scroll down to "Language Tool Archive" and find the column for MPLAB XC32
  - In that column, click the link for "v1.40 (Linux)" (or whatever your operating system is)
- Install the legacy plib library from Microchip:
  - Go to  https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-xc-compilers
  - Scroll down and click the "Compiler Downloads" column
  - Scroll down further to "Legacy Peripheral Libraries"
  - Click on the "PIC32 Legacy Peripheral Libraries" for your operating system

It is important to install the compiler first, and then the plib library. After installing, start the MPLAB IDE.
Open your project properties and set the "Compiler Toolchain" setting to XC32 (v1.40).

**Rees Machtemes** succeeded with this procedure:
- Download and install the xc32 v1.44 compiler for your system
- Download and install the pic32 peripheral libraries. On MacOS, use this link:
  https://microchipsupport.force.com/s/article/PIC32-Legacy-peripheral-Library-for-MAC-OS
- Since the optional Harmony plug-in App was used to build this project in the beginning, install it.
  - From within MPLAB X IDE, Tools>Plugins and click Available Plugins.
  - Check "MPLAB Harmony Configurator" version 2.0.5.x
  - and click Install.
  - Restart MPLAB.
- Now build the TerminalUSB project and enjoy tweaking
