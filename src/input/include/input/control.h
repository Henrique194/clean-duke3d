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

#include "types.h"
#include "gamedefs.h"

typedef enum {
    axis_up,
    axis_down,
    axis_left,
    axis_right
} axis_direction_t;

typedef enum {
    analog_turning = 0,
    analog_strafing = 1,
    analog_lookingupanddown = 2,
    analog_elevation = 3,
    analog_rolling = 4,
    analog_moving = 5,
    analog_maxtype
} analog_control_t;

typedef enum {
    dir_North,
    dir_NorthEast,
    dir_East,
    dir_SouthEast,
    dir_South,
    dir_SouthWest,
    dir_West,
    dir_NorthWest,
    dir_None
} direction_t;

typedef struct {
    boolean button0;
    boolean button1;
    direction_t dir;
} UserInput;

typedef struct {
    fixed dx;
    fixed dy;
    fixed dz;
    fixed dyaw;
    fixed dpitch;
    fixed droll;
} ControlInfo;

typedef enum {
    controltype_keyboard,
    controltype_keyboardandmouse,
    controltype_keyboardandjoystick,
    controltype_keyboardandexternal,
    controltype_keyboardandgamepad,
    controltype_keyboardandflightstick,
    controltype_keyboardandthrustmaster,
    controltype_joystickandmouse
} control_type_t;

#include "input/keyboard.h"
#include "input/mouse.h"
#include "input/joystick.h"

#define MAXGAMEBUTTONS 64


extern uint32 CONTROL_RudderEnabled;
extern boolean CONTROL_MousePresent;

typedef struct {
    boolean key_active;
    kb_scancode key1;
    kb_scancode key2;
    // other mappings go here
} key_mapping_t;

extern key_mapping_t KeyMapping[MAXGAMEBUTTONS];


int ACTION(int i);

void CONTROL_MapKey(int32 which, kb_scancode key1, kb_scancode key2);

void CONTROL_MapButton(
    int32 whichfunction,
    int32 whichbutton,
    boolean clicked_or_doubleclicked
);

void CONTROL_GetInput(ControlInfo* info);

void CONTROL_ClearAction(int32 whichbutton);

void CONTROL_Startup(void);

void CONTROL_Shutdown(void);
