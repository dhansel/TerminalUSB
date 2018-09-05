/****************************************************************************************
    Keyboard.c

	USB Keyboard processing for the VT100 Terminal program


	Copyright (C) 2018 David Hansel (david@hansels.net)
	All rights reserved.

	This file and the program created from it are FREE FOR COMMERCIAL AND
	NON-COMMERCIAL USE as long as the following conditions are aheared to.

	Copyright remains David Hansel's, and as such any Copyright notices in the
	code are not to be removed.  If this code is used in a product,  David Hansel
	should be given attribution as the author of the parts used.  This can be in
	the form of a textual message at program startup or in documentation (online
	or textual) provided with the program or product.

	Redistribution and use in source and binary forms, with or without modification,
	are permitted provided that the following conditions  are met:
	1. Redistributions of source code must retain the copyright notice, this list
	   of conditions and the following disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice, this
	   list of conditions and the following disclaimer in the documentation and/or
	   other materials provided with the distribution.
	3. All advertising materials mentioning features or use of this software must
	   display the following acknowledgement:
	   This product includes software developed by Geoff Graham (projects@geoffg.net)
 
	THIS SOFTWARE IS PROVIDED BY GEOFF GRAHAM ``AS IS'' AND  ANY EXPRESS OR IMPLIED
	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
	MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT
	SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
	BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
	IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
	SUCH DAMAGE.

	The licence and distribution terms for any publically available version or
	derivative of this code cannot be changed.  i.e. this code cannot simply be copied
	and put under another distribution licence (including the GNU Public Licence).
****************************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
#include "Terminal.h"

typedef enum
{
    KBD_WAIT_CONNECTION = 0,
    KBD_INIT_CONNECTION,
    KBD_WAIT_KEY,
    KBD_RECEIVED_KEY
} KBD_STATE;

volatile int KeyDown = -1;


volatile static KBD_STATE kbdState = KBD_WAIT_CONNECTION;

static USB_HOST_HID_KEYBOARD_DATA keyData, prevKeyData;
static USB_HID_KEYBOARD_KEYPAD currentKey = USB_HID_KEYBOARD_KEYPAD_RESERVED_NO_EVENT_INDICATED;

static USB_HOST_HID_KEYBOARD_HANDLE kbdHandle;
volatile char CapsLock = false, ScrollLock = false, NumLock = false;


struct KeyMapStruct
{
  int mapNormal[70];
  int mapShift[70];
  struct { int code; bool shift; int character; } mapOther[10];
  struct { int code; int character; } mapAltGr[12];
};

const struct KeyMapStruct keyMaps[7] = {
  { // US - US English
    {-1   ,-1   ,-1   ,-1   ,'a'  ,'b'  ,'c'  ,'d'  ,
     'e'  ,'f'  ,'g'  ,'h'  ,'i'  ,'j'  ,'k'  ,'l'  ,
     'm'  ,'n'  ,'o'  ,'p'  ,'q'  ,'r'  ,'s'  ,'t'  ,
     'u'  ,'v'  ,'w'  ,'x'  ,'y'  ,'z'  ,'1'  ,'2'  ,
     '3'  ,'4'  ,'5'  ,'6'  ,'7'  ,'8'  ,'9'  ,'0'  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,'-'  ,'='  ,'['  ,
     ']'  ,'\\' ,-1   ,';'  ,'\'' ,'`'  ,','  ,'.'  ,
     '/'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {-1   ,-1   ,-1   ,-1   ,'A'  ,'B'  ,'C'  ,'D'  ,
     'E'  ,'F'  ,'G'  ,'H'  ,'I'  ,'J'  ,'K'  ,'L'  ,
     'M'  ,'N'  ,'O'  ,'P'  ,'Q'  ,'R'  ,'S'  ,'T'  ,
     'U'  ,'V'  ,'W'  ,'X'  ,'Y'  ,'Z'  ,'!'  ,'@'  ,
     '#'  ,'$'  ,'%'  ,'^'  ,'&'  ,'*'  ,'('  ,')'  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,'_'  ,'+'  ,'{'  ,
     '}'  ,'|'  ,-1   ,':'  ,'"'  ,'~'  ,'<'  ,'>'  ,
     '?'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {{0x64, 0, '\\'}, {0x64, 1, '|'}, {-1,-1}},
    {{-1,-1}}
  },{ // FR - French
    {-1   ,-1   ,-1   ,-1   ,'q'  ,'b'  ,'c'  ,'d'  ,
     'e'  ,'f'  ,'g'  ,'h'  ,'i'  ,'j'  ,'k'  ,'l'  ,
     ','  ,'n'  ,'o'  ,'p'  ,'a'  ,'r'  ,'s'  ,'t'  ,
     'u'  ,'v'  ,'z'  ,'x'  ,'y'  ,'w'  ,'&'  ,-1   ,
     '"'  ,'\'' ,'('  ,'-'  ,-1   ,'_'  ,-1   ,-1   ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,')'  ,'='  ,'^'  ,
     '$'  ,'*'  ,-1   ,'m'  ,-1   ,-1   ,';'  ,':'  ,
     '!'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {-1   ,-1   ,-1   ,-1   ,'Q'  ,'B'  ,'C'  ,'D'  ,
     'E'  ,'F'  ,'G'  ,'H'  ,'I'  ,'J'  ,'K'  ,'L'  ,
     '?'  ,'N'  ,'O'  ,'P'  ,'A'  ,'R'  ,'S'  ,'T'  ,
     'U'  ,'V'  ,'Z'  ,'X'  ,'Y'  ,'W'  ,'1'  ,'2'  ,
     '3'  ,'4'  ,'5'  ,'6'  ,'7'  ,'8'  ,'9'  ,'0'  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,-1   ,'+'  ,-1   ,
     -1   ,-1   ,-1   ,'M'  ,'%'  ,-1   ,'.'  ,'/'  ,
     -1   ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {{0x64, 0, '<'}, {0x64, 1, '>'}, {-1,-1}},
    {{0x1f, '~'  }, {0x21, '{'  }, {0x20, '#'  }, {0x22, '['  }, 
     {0x23, '|'  }, {0x25, '\\' }, {0x27, '@'  }, {0x2d, ']'  }, 
     {0x2e, '}'  }, {0x64, '\\'  }, {-1,-1}}
  },{ // GR - German
    {-1   ,-1   ,-1   ,-1   ,'a'  ,'b'  ,'c'  ,'d'  ,
     'e'  ,'f'  ,'g'  ,'h'  ,'i'  ,'j'  ,'k'  ,'l'  ,
     'm'  ,'n'  ,'o'  ,'p'  ,'q'  ,'r'  ,'s'  ,'t'  ,
     'u'  ,'v'  ,'w'  ,'x'  ,'z'  ,'y'  ,'1'  ,'2'  ,
     '3'  ,'4'  ,'5'  ,'6'  ,'7'  ,'8'  ,'9'  ,'0'  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,-1   ,'\'' ,-1   ,
     '+'  ,'#'  ,-1   ,-1   ,-1   ,'^'  ,','  ,'.'  ,
     '-'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {-1   ,-1   ,-1   ,-1   ,'A'  ,'B'  ,'C'  ,'D'  ,
     'E'  ,'F'  ,'G'  ,'H'  ,'I'  ,'J'  ,'K'  ,'L'  ,
     'M'  ,'N'  ,'O'  ,'P'  ,'Q'  ,'R'  ,'S'  ,'T'  ,
     'U'  ,'V'  ,'W'  ,'X'  ,'Z'  ,'Y'  ,'!'  ,'"'  ,
     -1   ,'$'  ,'%'  ,'&'  ,'/'  ,'('  ,')'  ,'='  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,'?'  ,'`'  ,-1   ,
     '*'  ,'\'' ,-1   ,-1   ,-1   ,-1   ,';'  ,':'  ,
     '_'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {{0x64, 0, '<'}, {0x64, 1, '>'}, {-1,-1}},
    {{0x14, '@'  }, {0x24, '{'  }, {0x25, '['  }, {0x27, '}'  }, 
     {0x26, ']'  }, {0x2d, '\\' }, {0x30, '~'  }, {0x64, '|'  }, 
     {-1,-1}}
  },{ // IT - Italian
    {-1   ,-1   ,-1   ,-1   ,'a'  ,'b'  ,'c'  ,'d'  ,
     'e'  ,'f'  ,'g'  ,'h'  ,'i'  ,'j'  ,'k'  ,'l'  ,
     'm'  ,'n'  ,'o'  ,'p'  ,'q'  ,'r'  ,'s'  ,'t'  ,
     'u'  ,'v'  ,'w'  ,'x'  ,'y'  ,'z'  ,'1'  ,'2'  ,
     '3'  ,'4'  ,'5'  ,'6'  ,'7'  ,'8'  ,'9'  ,'0'  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,'\'' ,-1   ,-1   ,
     '+'  ,-1   ,-1   ,-1   ,-1   ,'\\' ,','  ,'.'  ,
     '-'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {-1   ,-1   ,-1   ,-1   ,'A'  ,'B'  ,'C'  ,'D'  ,
     'E'  ,'F'  ,'G'  ,'H'  ,'I'  ,'J'  ,'K'  ,'L'  ,
     'M'  ,'N'  ,'O'  ,'P'  ,'Q'  ,'R'  ,'S'  ,'T'  ,
     'U'  ,'V'  ,'W'  ,'X'  ,'Y'  ,'Z'  ,'!'  ,'"'  ,
     -1   ,'$'  ,'%'  ,'&'  ,'/'  ,'('  ,')'  ,'='  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,'?'  ,'^'  ,-1   ,
     '*'  ,-1   ,-1   ,-1   ,-1   ,'|'  ,';'  ,':'  ,
     '_'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {{0x64, 0, '<'}, {0x64, 1, '>'}, {-1,-1}},
    {{0x33, '@'  }, {0x34, '#'  }, {0x2f, '['  }, {0x30, ']'  }, 
     {-1,-1}}
  },{ // BE - Belgian
    {-1   ,-1   ,-1   ,-1   ,'q'  ,'b'  ,'c'  ,'d'  ,
     'e'  ,'f'  ,'g'  ,'h'  ,'i'  ,'j'  ,'k'  ,'l'  ,
     ','  ,'n'  ,'o'  ,'p'  ,'a'  ,'r'  ,'s'  ,'t'  ,
     'u'  ,'v'  ,'z'  ,'x'  ,'y'  ,'w'  ,'&'  ,-1   ,
     '"'  ,'\'' ,'('  ,-1   ,-1   ,'!'  ,-1   ,-1   ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,')'  ,'-'  ,'^'  ,
     '$'  ,-1   ,-1   ,'m'  ,-1   ,-1   ,';'  ,':'  ,
     '='  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {-1   ,-1   ,-1   ,-1   ,'Q'  ,'B'  ,'C'  ,'D'  ,
     'E'  ,'F'  ,'G'  ,'H'  ,'I'  ,'J'  ,'K'  ,'L'  ,
     '?'  ,'N'  ,'O'  ,'P'  ,'A'  ,'R'  ,'S'  ,'T'  ,
     'U'  ,'V'  ,'Z'  ,'X'  ,'Y'  ,'W'  ,'1'  ,'2'  ,
     '3'  ,'4'  ,'5'  ,'6'  ,'7'  ,'8'  ,'9'  ,'0'  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,-1   ,'_'  ,-1   ,
     '*'  ,-1   ,-1   ,'M'  ,'%'  ,-1   ,'.'  ,'/'  ,
     '+'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {{0x64, 0, '<'}, {0x64, 1, '>'}, {-1,-1}},
    {{0x1e, '|'  }, {0x64, '\\' }, {0x1f, '@'  }, {0x20, '#'  }, 
     {0x27, '}'  }, {0x26, '{'  }, {0x38, '~'  }, {0x2f, '['  }, 
     {0x30, ']'  }, {-1,-1}}
  },{ // UK - UK English
    {-1   ,-1   ,-1   ,-1   ,'a'  ,'b'  ,'c'  ,'d'  ,
     'e'  ,'f'  ,'g'  ,'h'  ,'i'  ,'j'  ,'k'  ,'l'  ,
     'm'  ,'n'  ,'o'  ,'p'  ,'q'  ,'r'  ,'s'  ,'t'  ,
     'u'  ,'v'  ,'w'  ,'x'  ,'y'  ,'z'  ,'1'  ,'2'  ,
     '3'  ,'4'  ,'5'  ,'6'  ,'7'  ,'8'  ,'9'  ,'0'  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,'-'  ,'='  ,'['  ,
     ']'  ,'#'  ,-1   ,';'  ,'\'' ,'`'  ,','  ,'.'  ,
     '/'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {-1   ,-1   ,-1   ,-1   ,'A'  ,'B'  ,'C'  ,'D'  ,
     'E'  ,'F'  ,'G'  ,'H'  ,'I'  ,'J'  ,'K'  ,'L'  ,
     'M'  ,'N'  ,'O'  ,'P'  ,'Q'  ,'R'  ,'S'  ,'T'  ,
     'U'  ,'V'  ,'W'  ,'X'  ,'Y'  ,'Z'  ,'!'  ,'"'  ,
     '#'  ,'$'  ,'%'  ,'^'  ,'&'  ,'*'  ,'('  ,')'  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,'_'  ,'+'  ,'{'  ,
     '}'  ,'~'  ,-1   ,':'  ,'@'  ,'~'  ,'<'  ,'>'  ,
     '?'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {{0x64, 0, '\\'}, {0x64, 1, '|'}, {-1,-1}},
    {{-1,-1}}
  }, { // ES - Spanish
    {-1   ,-1   ,-1   ,-1   ,'a'  ,'b'  ,'c'  ,'d'  ,
     'e'  ,'f'  ,'g'  ,'h'  ,'i'  ,'j'  ,'k'  ,'l'  ,
     'm'  ,'n'  ,'o'  ,'p'  ,'q'  ,'r'  ,'s'  ,'t'  ,
     'u'  ,'v'  ,'w'  ,'x'  ,'y'  ,'z'  ,'1'  ,'2'  ,
     '3'  ,'4'  ,'5'  ,'6'  ,'7'  ,'8'  ,'9'  ,'0'  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,'\'' ,-1   ,'`'  ,
     '+'  ,-1   ,-1   ,-1   ,'\'' ,'\\' ,','  ,'.'  ,
     '-'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {-1   ,-1   ,-1   ,-1   ,'A'  ,'B'  ,'C'  ,'D'  ,
     'E'  ,'F'  ,'G'  ,'H'  ,'I'  ,'J'  ,'K'  ,'L'  ,
     'M'  ,'N'  ,'O'  ,'P'  ,'Q'  ,'R'  ,'S'  ,'T'  ,
     'U'  ,'V'  ,'W'  ,'X'  ,'Y'  ,'Z'  ,'!'  ,'"'  ,
     -1   ,'$'  ,'%'  ,'&'  ,'/'  ,'('  ,')'  ,'='  ,
     ENTER,ESC  ,BKSP ,TAB  ,' '  ,'?'  ,-1   ,'^'  ,
     '*'  ,-1   ,-1   ,-1   ,-1   ,'\\' ,';'  ,':'  ,
     '_'  ,-1   ,F1   ,F2   ,F3   ,F4   ,F5   ,F6   ,
     F7   ,F8   ,F9   ,F10  ,F11  ,F12  },
    {{0x64, 0, '<'}, {0x64, 1, '>'}, {-1,-1}},
    {{0x35, '\\' }, {0x1e, '|'  }, {0x1f, '@'  }, {0x21, '~'  }, 
     {0x20, '#'  }, {0x34, '{'  }, {0x2f, '['  }, {0x30, ']'  }, 
     {0x31, '}'  }, {-1,-1}}
  }
};

static const int keyMapKeypad[]    = { '\\', '*', '-', '+', NUM_ENT, END, DOWN, PDOWN, LEFT, -1, RIGHT, HOME, UP,  PUP, INSERT, DEL};

static const int keyMapKeypadNum[] = { '\\', '*', '-', '+', NUM_ENT, '1', '2',  '3',   '4', '5', '6',   '7',  '8', '9', '0',    '.'};

static const int keyMapSpecial[] = {INSERT, HOME, PUP, DEL, END, PDOWN, RIGHT, LEFT, DOWN, UP};


void setLEDs(int caps, int num, int scroll) 
{
  uint8_t ledStatus = 0;
  if( scroll ) ledStatus |= 0x01;
  if( caps   ) ledStatus |= 0x02;
  if( num    ) ledStatus |= 0x04;
  USB_HOST_HID_KEYBOARD_ReportSend(kbdHandle, ledStatus);
}


static int handleStatus(USB_HID_KEYBOARD_KEYPAD keyCode)
{
  if( keyCode == USB_HID_KEYBOARD_KEYPAD_KEYBOARD_CAPS_LOCK   || 
      keyCode == USB_HID_KEYBOARD_KEYPAD_KEYBOARD_SCROLL_LOCK ||
      keyCode == USB_HID_KEYBOARD_KEYPAD_KEYPAD_NUM_LOCK_AND_CLEAR )
    {
      if( keyCode == USB_HID_KEYBOARD_KEYPAD_KEYBOARD_CAPS_LOCK )
        CapsLock = !CapsLock;
      else if( keyCode == USB_HID_KEYBOARD_KEYPAD_KEYBOARD_SCROLL_LOCK )
        ScrollLock = !ScrollLock;
      else if( keyCode == USB_HID_KEYBOARD_KEYPAD_KEYPAD_NUM_LOCK_AND_CLEAR )
        NumLock = !NumLock;

      setLEDs(CapsLock, ScrollLock, NumLock);
    }
}


static int mapKeyCode(USB_HID_KEYBOARD_KEYPAD keyCode)
{
  const struct KeyMapStruct *map;
  int i, key = -1;
  
  // find the country-specific keyboard map (default to US if unknown)
  if( Option[O_KEYBOARD] < O_KEYBOARD_FR || Option[O_KEYBOARD] > O_KEYBOARD_ES )
    map = &(keyMaps[O_KEYBOARD_US+1]);
  else
    map = &(keyMaps[Option[O_KEYBOARD]+1]);

  if( keyData.modifierKeysData.rightAlt )
        {
          // AltGr pressed (international keyboard)
          for(i=0; map->mapAltGr[i].code>=0; i++)
            if( map->mapAltGr[i].code == keyCode )
              { key = map->mapAltGr[i].character; break; }
        }
  else if( keyCode <= USB_HID_KEYBOARD_KEYPAD_KEYBOARD_F12 )
    {
      bool ctrl  = keyData.modifierKeysData.leftControl || keyData.modifierKeysData.rightControl;
      bool shift = keyData.modifierKeysData.leftShift || keyData.modifierKeysData.rightShift;
      bool caps  = keyCode >= USB_HID_KEYBOARD_KEYPAD_KEYBOARD_A && keyCode <= USB_HID_KEYBOARD_KEYPAD_KEYBOARD_Z && CapsLock;

      if( shift ^ caps )
        key = map->mapShift[keyCode];
      else
        key = map->mapNormal[keyCode];
      
      if( ctrl && key>=0 && key<0x7f )
        key &= 0x1f;
      else if( key >= 0x80 )
        {
          if( shift ) key |= 0x20;
          if( ctrl  ) key |= 0x40;
        }
    }
  else if( keyCode >= USB_HID_KEYBOARD_KEYPAD_KEYBOARD_INSERT &&
           keyCode <= USB_HID_KEYBOARD_KEYPAD_KEYBOARD_UP_ARROW )
    {
      key = keyMapSpecial[keyCode-USB_HID_KEYBOARD_KEYPAD_KEYBOARD_INSERT];
    }
  else if( keyCode >= USB_HID_KEYBOARD_KEYPAD_KEYPAD_BACK_SLASH &&
           keyCode <= USB_HID_KEYBOARD_KEYPAD_KEYPAD_PERIOD_AND_DELETE )
    {
      if( NumLock )
        key = keyMapKeypadNum[keyCode-USB_HID_KEYBOARD_KEYPAD_KEYPAD_BACK_SLASH];
      else
        key = keyMapKeypad[keyCode-USB_HID_KEYBOARD_KEYPAD_KEYPAD_BACK_SLASH];
    }
  else
    {
      bool shift = keyData.modifierKeysData.leftShift || keyData.modifierKeysData.rightShift;

      for(i=0; map->mapOther[i].code>=0; i++)
        if( map->mapOther[i].code == keyCode && map->mapOther[i].shift == shift )
          key = map->mapOther[i].character;
    }
  
  return key;
}



void APP_USBHostHIDKeyboardEventHandler(USB_HOST_HID_KEYBOARD_HANDLE handle, 
                                        USB_HOST_HID_KEYBOARD_EVENT event, void * pData)
{   
  switch( event )
    {
    case USB_HOST_HID_KEYBOARD_EVENT_ATTACH:
      {
        kbdState = KBD_INIT_CONNECTION;
        kbdHandle = handle;
        break;
      }
      
    case USB_HOST_HID_KEYBOARD_EVENT_DETACH:
      {
        kbdState = KBD_WAIT_CONNECTION;
        break;
      }
      
    case USB_HOST_HID_KEYBOARD_EVENT_REPORT_RECEIVED:
      {
        if( (kbdState == KBD_WAIT_KEY) && memcmp(pData, &keyData, sizeof(keyData))!=0 )
          {
            kbdState = KBD_RECEIVED_KEY;
            memcpy(&keyData, pData, sizeof(keyData));
          }
        
        break;
      }
    }
}


void initKeyboard()
{
  // set up USB
  kbdState = KBD_WAIT_CONNECTION;
  USB_HOST_HID_KEYBOARD_EventHandlerSet(APP_USBHostHIDKeyboardEventHandler);
  PLIB_USB_StopInIdleDisable(USB_ID_1);
  USB_HOST_BusEnable(0);
}



void checkKeyboard()
{
  static uint64_t repeatTimerStart = 0, repeatTimerTimeout = 0;

  SYS_TMR_Tasks(sysObj.sysTmr);
  DRV_USBFS_Tasks(sysObj.drvUSBObject);
  USB_HOST_Tasks(sysObj.usbHostObject0);

  // nothing to do if no keyboard is connected
  if( kbdState == KBD_WAIT_CONNECTION ) return;

  if( kbdState == KBD_INIT_CONNECTION )
    {
      currentKey        = USB_HID_KEYBOARD_KEYPAD_RESERVED_NO_EVENT_INDICATED;
      CapsLock   = false;
      ScrollLock = false;
      NumLock    = true;
      setLEDs(CapsLock, ScrollLock, NumLock);
      memset(&prevKeyData, 0, sizeof(prevKeyData));
      kbdState = KBD_WAIT_KEY;
    }
  else if( kbdState == KBD_RECEIVED_KEY )
    { 
      int i, j;

      if( keyData.nNonModifierKeysData==0 )
        {
          // all keys have been released
          currentKey = USB_HID_KEYBOARD_KEYPAD_RESERVED_NO_EVENT_INDICATED;
        }
      else
        {
          for(i=0; i<keyData.nNonModifierKeysData; i++)
            {
              USB_HID_KEY_EVENT event = keyData.nonModifierKeysData[i].event;
              USB_HID_KEYBOARD_KEYPAD keyCode = keyData.nonModifierKeysData[i].keyCode;
                  
              if( event == USB_HID_KEY_PRESSED )
                {
                  for(j=0; j<prevKeyData.nNonModifierKeysData; j++)
                  {
                    if( prevKeyData.nonModifierKeysData[j].keyCode == keyCode &&
                        prevKeyData.nonModifierKeysData[j].event == USB_HID_KEY_PRESSED )
                      break;
                  }
                      
                  if( j==prevKeyData.nNonModifierKeysData )
                    {
                      // a key is newly pressed
                      currentKey = keyCode;
                      repeatTimerStart = SYS_TMR_SystemCountGet();
                      repeatTimerTimeout = SYS_TMR_SystemCountFrequencyGet() / 2;
                      KeyDown = mapKeyCode(currentKey);
                      handleStatus(currentKey);
                    }
                }
              else
                {
                  // a key has been released
                  if( keyCode == currentKey )
                    currentKey = USB_HID_KEYBOARD_KEYPAD_RESERVED_NO_EVENT_INDICATED;
                }
            }
        }
          
      memcpy(&prevKeyData, &keyData, sizeof(keyData));
      kbdState = KBD_WAIT_KEY;
    }

  if( currentKey!=USB_HID_KEYBOARD_KEYPAD_RESERVED_NO_EVENT_INDICATED && 
      (SYS_TMR_SystemCountGet()-repeatTimerStart)>repeatTimerTimeout )
    {
      KeyDown = mapKeyCode(currentKey);
      repeatTimerStart = SYS_TMR_SystemCountGet();
      repeatTimerTimeout = SYS_TMR_SystemCountFrequencyGet() / 25;
    }
}
