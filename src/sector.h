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

short P_CallSound(short sn, short whatsprite);

short P_CheckActivatorMotion(short lotag);

uint8_t P_IsDoorWall(short dapic);

uint8_t P_IsUnderOperator(short lotag);

uint8_t P_IsNearOperator(short lotag);

short P_CheckCurSectNums(short sect);

int32_t P_Dist2D(spritetype* s1, spritetype* s2);

int32_t P_Dist3D(spritetype* s1, spritetype* s2);

short P_FindPlayer(spritetype* s, int32_t* d);

short P_FindOtherPlayer(short p, int32_t* d);

void P_DoAnimations(void);

int32_t P_GetAnimationGoal(int32_t* animptr);

void P_AnimateCamSprite(void);

void P_AnimateWalls(void);

uint8_t P_ActivateWarpElevators(short s, short d);

void P_OperateSectors(short sn, short ii);

void P_OperateRespawns(short low);

void P_OperateActivators(short low, short snum);

void P_OperateMasterSwitches(short low);

void P_OperateForceFields(short s, short low);

uint8_t P_CheckHitSwitch(short snum, int32_t w, uint8_t switchtype);

void P_ActivateBySector(short sect, short j);

void P_CheckHitWall(
    short spr,
    short dawallnum,
    int32_t x,
    int32_t y,
    int32_t z,
    short atwith
);

void P_CheckPlayerHurt(player_t* p, short j);

uint8_t P_CheckHitCeiling(short sn);

void P_CheckHitSprite(short i, short sn);

void P_AlignWarpElevators(void);

void P_CheatKeys(short snum);

void P_CheckSectors(short snum);
