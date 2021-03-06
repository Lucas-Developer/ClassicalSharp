#ifndef CC_INPUT_H
#define CC_INPUT_H
#include "Typedefs.h"
/* Manages the keyboard, and raises events when keys are pressed etc.
   Copyright 2017 ClassicalSharp | Licensed under BSD-3 | Based on OpenTK code
*/

/*
   The Open Toolkit Library License

   Copyright (c) 2006 - 2009 the Open Toolkit library.

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights to
   use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
   the Software, and to permit persons to whom the Software is furnished to do
   so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
   OTHER DEALINGS IN THE SOFTWARE.
*/

typedef enum Key_ {
	/* Key outside the known keys */
	Key_Unknown,

	/* Modifiers */
	Key_ShiftLeft, Key_ShiftRight, Key_ControlLeft, Key_ControlRight,
	Key_AltLeft, Key_AltRight, Key_WinLeft, Key_WinRight, Key_Menu,

	/* Function keys (hopefully enough for most keyboards - mine has 26)
	/ <keysymdef.h> on X11 reports up to 35 function keys. */
	Key_F1,  Key_F2,  Key_F3,  Key_F4,  Key_F5,  Key_F6,  Key_F7,  Key_F8,  Key_F9,  Key_F10,
	Key_F11, Key_F12, Key_F13, Key_F14, Key_F15, Key_F16, Key_F17, Key_F18, Key_F19, Key_F20,
	Key_F21, Key_F22, Key_F23, Key_F24, Key_F25, Key_F26, Key_F27, Key_F28, Key_F29, Key_F30,
	Key_F31, Key_F32, Key_F33, Key_F34, Key_F35,

	/* Direction arrows */
	Key_Up, Key_Down, Key_Left, Key_Right,

	/* Action keys */
	Key_Enter, Key_Escape, Key_Space, Key_Tab, Key_BackSpace, Key_Insert,
	Key_Delete, Key_PageUp, Key_PageDown, Key_Home, Key_End, Key_CapsLock,
	Key_ScrollLock, Key_PrintScreen, Key_Pause, Key_NumLock,

	/* Keypad keys */
	Key_Keypad0, Key_Keypad1, Key_Keypad2, Key_Keypad3, Key_Keypad4,
	Key_Keypad5, Key_Keypad6, Key_Keypad7, Key_Keypad8, Key_Keypad9,
	Key_KeypadDivide, Key_KeypadMultiply, Key_KeypadSubtract,
	Key_KeypadAdd, Key_KeypadDecimal, Key_KeypadEnter,

	/* Letters */
	Key_A, Key_B, Key_C, Key_D, Key_E, Key_F, Key_G, Key_H, Key_I, Key_J,
	Key_K, Key_L, Key_M, Key_N, Key_O, Key_P, Key_Q, Key_R, Key_S, Key_T,
	Key_U, Key_V, Key_W, Key_X, Key_Y, Key_Z,

	/* Numbers */
	Key_0, Key_1, Key_2, Key_3, Key_4,
	Key_5, Key_6, Key_7, Key_8, Key_9,

	/* Symbols */
	Key_Tilde, Key_Minus, Key_Plus, Key_BracketLeft, Key_BracketRight,
	Key_Semicolon, Key_Quote, Key_Comma, Key_Period, Key_Slash, Key_BackSlash,

	Key_Count,
} Key;

/* Gets whether the given key is currently being pressed. */
bool Key_GetPressed(Key key);
/* Sets whether the given key is currently being pressed. */
void Key_SetPressed(Key key, bool pressed);

#define Key_IsAltPressed() (Key_GetPressed(Key_AltLeft) || Key_GetPressed(Key_AltRight))
#define Key_IsControlPressed() (Key_GetPressed(Key_ControlLeft) || Key_GetPressed(Key_ControlRight))
#define Key_IsShiftPressed() (Key_GetPressed(Key_ShiftLeft) || Key_GetPressed(Key_ShiftRight))
#define Key_IsWinPressed() (Key_GetPressed(Key_WinLeft) || Key_GetPressed(Key_WinRight))

/* Gets whether key repeating is on or not. If on (desirable for text input), multiple KeyDowns (varies by OS) 
are generated for the same key when it is held down for a period of time. Should be off for game input. */
bool Key_KeyRepeat;
/* Names for each key. */
extern const UInt8* Key_Names[Key_Count];

/* Unpresses all keys that were previously pressed. */
void Key_Clear(void);


typedef enum MouseButton_ {
	/* The left mouse button. */
	MouseButton_Left,
	/* The right mouse button. */
	MouseButton_Right,
	/* The middle mouse button. */
	MouseButton_Middle,
	/* The first extra mouse button. */
	MouseButton_Button1,
	/* The second extra mouse button. */
	MouseButton_Button2,

	MouseButton_Count,
} MouseButton;

/* Gets whether the given mouse button is currently being pressed. */
bool Mouse_GetPressed(MouseButton btn);
/* Sets whether the given mouse button is currently being pressed. */
void Mouse_SetPressed(MouseButton btn, bool pressed);

/* Gets the current wheel value of the mouse. */
Real32 Mouse_Wheel;
/* Gets the current position of the mouse. */
Int32 Mouse_X, Mouse_Y;

/* Sets the current wheel value of the mouse. */
void Mouse_SetWheel(Real32 wheel);
/* Sets the current position of the mouse. */
void Mouse_SetPosition(Int32 x, Int32 y);


/* Enumeration of all custom key bindings. */
typedef enum KeyBind_ {
	KeyBind_Forward, KeyBind_Back, KeyBind_Left, KeyBind_Right, 
	KeyBind_Jump, KeyBind_Respawn, KeyBind_SetSpawn, KeyBind_Chat,
	KeyBind_Inventory, KeyBind_ToggleFog, KeyBind_SendChat, KeyBind_PauseOrExit, 
	KeyBind_PlayerList, KeyBind_Speed, KeyBind_NoClip, KeyBind_Fly, 
	KeyBind_FlyUp, KeyBind_FlyDown, KeyBind_ExtInput, KeyBind_HideFps,
	KeyBind_Screenshot, KeyBind_Fullscreen, KeyBind_ThirdPerson, KeyBind_HideGui, 
	KeyBind_AxisLines, KeyBind_ZoomScrolling, KeyBind_HalfSpeed, KeyBind_MouseLeft, 
	KeyBind_MouseMiddle, KeyBind_MouseRight, KeyBind_Autorotate, KeyBind_HotbarSwitching, 
	KeyBind_SmoothCamera, KeyBind_DropBlock, KeyBind_IDOverlay,
	KeyBind_Count
} KeyBind;

/* Gets the keyboard key that the given binding maps to. */
Key KeyBind_Get(KeyBind binding);
/* Gets the default keyboard key that the given binding maps to. */
Key KeyBind_GetDefault(KeyBind binding);
/* Gets whether the keyboard key that the given maps to is currently pressed. */
bool KeyBind_GetPressed(KeyBind binding);
/* Sets the keyboard key that the given binding maps to. */
void KeyBind_Set(KeyBind binding, Key key);
/* Initalises and loads key bindings. */
void KeyBind_Init(void);
#endif