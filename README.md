# TerminalUSB

This is a modified firmware for [Geoff Graham's ASCII Video Terminal](http://geoffg.net/terminal.html) which 
changes it to use a keyboard connected to the USB port instead of the PS/2 port. All other features of the
terminal are identical to the original, except for the USB-to-serial bridge functionally (since the USB port
is now used for the keyboard).

## Hardware

No modification to the original hardware is necessary. There are a couple of things to note:

1. *USB Connector*. The USB connector on Geoff's terminal is used to plug the terminal
into a computer as a client device, therefore the connector is a USB type B client side
connector. To plug in a keyboard, you need a type A host side connector. The easiest way
to do this is to use a converter like [this](https://www.computercablestore.com/usb-20-adapter-usb-a-female-to-usb-b-male) 
(or [this](https://www.showmecables.com/micro-usb-2-b-male-to-a-female-6-in) 
or [this](https://www.computercablestore.com/usb-adapter-usb-a-female-to-usb-mini-5-male) depending on your socket).

2. *Power supply*. Since the USB socket is taken up by the keyboard, it can no longer be used to power
the Terminal. You need to power the terminal from the external 5V power connector. *Additionally* you
need to place a jumper on the "USB PWR" jumper pad so the keyboard receives power.

## Software

The new software can be applied as a firmware update to the Terminal. Just follow 
[Geoff's instructions](http://geoffg.net/Downloads/Terminal/Terminal_V1.3_UPGRADE.zip) from his V1.3 firmware update,
When loading the HEX file, use [this](https://raw.githubusercontent.com/dhansel/TerminalUSB/master/TerminalUSB_V1.3_UPGRADE.hex)
instead of the HEX file in Geoff's archive.

## Keyboard Compatibility

This firmware requires the USB keyboard to be directly connected to the Terminal's
USB socket. If there is a USB hub in between the terminal and the keyboard then the keyboard will not work.
Some keyboards have built-in USB hubs and those will *not* work either. If your keyboard has
USB sockets on it (to connect a mouse for example) then it will likely not work.
