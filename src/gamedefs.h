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

//****************************************************************************
//
// gamedefs.h
//
// common defines between the game and the setup program
//
//****************************************************************************

#pragma once

#include "con/con.h"

//
// Setup program defines
//
#define SETUPFILENAME "duke3d.cfg"


// Max number of players
#define MAXPLAYERS 16

// Number of Mouse buttons
#define MAXMOUSEBUTTONS 7

// Number of JOY buttons
#define MAXJOYBUTTONS 32

// Number of joystick "top hats"
#define MAXJOYHATS 6

// Number of EXTERNAL buttons

//#define MAXEXTERNALBUTTONS 6

//
// modem string defines
//

#define MAXMODEMSTRING 50

// MACRO defines

#define MAXMACROS      10
#define MAXMACROLENGTH 34

// Phone list defines

#define PHONENUMBERLENGTH 28
#define PHONENAMELENGTH   16
#define MAXPHONEENTRIES   10

// length of program functions

#define MAXFUNCTIONLENGTH 30

// length of axis functions

#define MAXAXISFUNCTIONLENGTH 30

// Max Player Name length

#define MAXPLAYERNAMELENGTH 11

// Max RTS Name length

#define MAXRTSNAMELENGTH 15

// Number of Mouse Axes

#define MAXMOUSEAXES 2

// Number of JOY axes

#define MAXJOYAXES 6
//4

// Number of GAMEPAD axes

#define MAXGAMEPADAXES 2

// MIN/MAX scale value for controller scales

#define MAXCONTROLSCALEVALUE (1 << 19)

// DEFAULT scale value for controller scales

#define DEFAULTCONTROLSCALEVALUE (1 << 16)

// base value for controller scales

#define BASECONTROLSCALEVALUE (1 << 16)


short getincangle(short a, short na);

void getglobalz(short i);

void makeitfall(short i);

void CON_LoadFile(char* file, int read_grp);

short furthestangle(short i, short angs);
