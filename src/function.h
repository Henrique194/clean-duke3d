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

// function.h

// file created by makehead.exe
// these headers contain default key assignments, as well as
// default button assignments and game function names
// axis defaults are also included


#pragma once

#define NUMGAMEFUNCTIONS 55 //dont forget to check NUMKEYENTRIES

extern char* gamefunctions[];

typedef enum {
    GF_MOVE_FORWARD,
    GF_MOVE_BACKWARD,
    GF_TURN_LEFT,
    GF_TURN_RIGHT,
    GF_STRAFE,
    GF_FIRE,
    GF_OPEN,
    GF_RUN,
    GF_AUTORUN,
    GF_JUMP,
    GF_CROUCH,
    GF_LOOK_UP,
    GF_LOOK_DOWN,
    GF_LOOK_LEFT,
    GF_LOOK_RIGHT,
    GF_STRAFE_LEFT,
    GF_STRAFE_RIGHT,
    GF_AIM_UP,
    GF_AIM_DOWN,
    GF_WEAPON_1,
    GF_WEAPON_2,
    GF_WEAPON_3,
    GF_WEAPON_4,
    GF_WEAPON_5,
    GF_WEAPON_6,
    GF_WEAPON_7,
    GF_WEAPON_8,
    GF_WEAPON_9,
    GF_WEAPON_10,
    GF_INVENTORY,
    GF_INVENTORY_LEFT,
    GF_INVENTORY_RIGHT,
    GF_HOLO_DUKE,
    GF_JETPACK,
    GF_NIGHT_VISION,
    GF_MEDKIT,
    GF_TURN_AROUND,
    GF_SEND_MESSAGE,
    GF_MAP,
    GF_SHRINK_SCREEN,
    GF_ENLARGE_SCREEN,
    GF_CENTER_VIEW,
    GF_HOLSTER_WEAPON,
    GF_SHOW_OPPONENTS_WEAPON,
    GF_MAP_FOLLOW_MODE,
    GF_SEE_COOP_VIEW,
    GF_MOUSE_AIMING,
    GF_TOGGLE_CROSSHAIR,
    GF_STEROIDS,
    GF_QUICK_KICK,
    GF_NEXT_WEAPON,
    GF_PREV_WEAPON,
    GF_HIDE_WEAPON,
    GF_AUTO_AIM,
    GF_CONSOLE,
} game_func_t;
