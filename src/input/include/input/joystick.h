/*
 * Copyright (C) 1994-1995 Apogee Software, Ltd.
 * Copyright (C) 1996, 2003 - 3D Realms Entertainment
 *
 * This file is part of Duke Nukem 3D version 1.5 - Atomic Edition
 *
 * Duke Nukem 3D is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#pragma once

#include "control.h"

extern uint32 CONTROL_JoyButtonState1;
extern uint32 CONTROL_JoyButtonState2;

extern uint32 CONTROL_JoyHatState1;
extern uint32 CONTROL_JoyHatState2;

extern boolean CONTROL_JoystickEnabled;
extern byte CONTROL_JoystickPort;

void _joystick_init(void);

void _joystick_deinit(void);

int _joystick_update(void);

int _joystick_axis(int axis);

int _joystick_hat(int hat);

int _joystick_button(int button);

void JOY_Update(ControlInfo* info);

void JOY_Reset(int32 whichbutton);

void CONTROL_MapJoyButton(
    int32 whichfunction,
    int32 whichbutton,
    boolean doubleclicked
);

void CONTROL_MapJoyHat(
    int32 whichfunction,
    int32 whichhat,
    int32 whichvalue
);

void CONTROL_MapAnalogAxis(int32 whichaxis, int32 whichanalog);

void CONTROL_SetAnalogAxisScale(int32 whichaxis, float axisscale);

void CONTROL_SetAnalogAxisDeadzone(int32 whichaxis, int32 axisdeadzone);

int32 CONTROL_GetFilteredAxisValue(int32 axis);

int32 CONTROL_FilterDeadzone(int32 axisvalue, int32 axisdeadzone);
