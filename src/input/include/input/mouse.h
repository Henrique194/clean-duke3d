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

#define LEFT_MOUSE   1
#define RIGHT_MOUSE  2
#define MIDDLE_MOUSE 4

#define LEFT_MOUSE_PRESSED(button)   (((button) & LEFT_MOUSE) != 0)
#define RIGHT_MOUSE_PRESSED(button)  (((button) & RIGHT_MOUSE) != 0)
#define MIDDLE_MOUSE_PRESSED(button) (((button) & MIDDLE_MOUSE) != 0)


extern uint32 CONTROL_MouseButtonState1;
extern uint32 CONTROL_MouseButtonState2;
extern uint32 CONTROL_MouseDigitalAxisState1;
extern uint32 CONTROL_MouseDigitalAxisState2;
extern boolean CONTROL_MouseEnabled;

extern int32 MouseMapping[MAXMOUSEBUTTONS];
// [axesX/Y][directionLeft/Right or directionUp/Down]
extern int32 MouseDigitalAxeMapping[MAXMOUSEAXES][2];


int32 MOUSE_GetButtons(void);

void MOUSE_GetDelta(int32* x, int32* y);

void MOUSE_GetInput(ControlInfo* info);

void MOUSE_Reset(int32 whichbutton);

int32 CONTROL_GetMouseSensitivity_X(void);

void CONTROL_SetMouseSensitivity_X(int32 newsensitivity);

int32 CONTROL_GetMouseSensitivity_Y(void);

void CONTROL_SetMouseSensitivity_Y(int32 newsensitivity);

void CONTROL_MapDigitalAxis(
    int32 whichaxis,
    int32 whichfunction,
    int32 direction
);