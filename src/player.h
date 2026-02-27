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

#include "duke3d.h"

void P_SetPal(player_t* p);

void P_IncurDamage(player_t* p);

void P_QuickKill(player_t* p);

void P_ForcePlayerAngle(player_t* p);

void P_Tracers(
    int32_t x1,
    int32_t y1,
    int32_t z1,
    int32_t x2,
    int32_t y2,
    int32_t z2,
    int32_t n
);

int32_t P_Hits(short i);

int32_t P_HitSprite(short i, short* hitsp);

int32_t P_HitWall(player_t* p, short* hitw);

short P_Aim(spritetype* s, short aang, short auto_aim);

void P_Shoot(short i, short atwith);

void P_DisplayLoogie(short snum);

uint8_t P_AnimateFist(short gs, short snum);

uint8_t P_AnimateKnee(short gs, short snum);

uint8_t P_AnimateKnuckles(short gs, short snum);

void P_DisplayMasks(short snum);

uint8_t P_AnimateTip(short gs, short snum);

uint8_t P_AnimateAccess(short gs, short snum);

void P_DisplayWeapon(short snum);

void P_GetInput(short snum);

uint8_t P_DoIncrements(player_t* p);

void P_CheckWeapons(player_t* p);

void P_ProcessInput(short snum);

void P_ComputerGetInput(int32_t snum, input* syn);
