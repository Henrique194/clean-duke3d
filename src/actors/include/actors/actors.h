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
#include "types.h"

void P_UpdateInterpolations(void);

void P_SetInterpolation(int32_t* posptr);

void P_StopInterpolation(const i32* posptr);

void P_DoInterpolations(int32_t smoothratio);

void P_RestoreInterpolations(void);

int32_t P_CeilingSpace(short sectnum);

int32_t P_FloorSpace(i16 sectnum);

void P_AddAmmo(short weapon, player_t* p, short amount);

//
// Adds a weapon to the player's inventory.
//
// If the player already owns the weapon, this function simply
// switches the active weapon to it.
//
// On first pickup, the player will automatically switch to the
// newly acquired weapon unless auto-switch is enabled or the
// game is playing back an old demo.
//
void P_AddWeapon(player_t* p, short weapon);

void P_CheckAvailInven(player_t* p);

void P_CheckAvailWeapon(player_t* p);

int32_t P_IfSquished(short i, short p);

void P_HitRadius(
    short i,
    int32_t r,
    int32_t hp1,
    int32_t hp2,
    int32_t hp3,
    int32_t hp4
);

int P_MoveSprite(
    short spritenum,
    int32_t xchange,
    int32_t ychange,
    int32_t zchange,
    uint32_t cliptype
);

short P_SetSprite(short i, uint32_t cliptype);

void P_InsertSpriteq(short i);

void P_LotsOfMoney(spritetype* s, short n);

void P_LotsOfMail(spritetype* s, short n);

void P_LotsOfPaper(spritetype* s, short n);

void P_Guts(spritetype* s, short gtype, short n, short p);

void P_SetSectInterpolate(short i);

void P_ClearSectInterpolate(short i);

void P_MoveSprites(short i);

void P_MoveFTA(void);

short P_IfHitSectors(short sectnum);

short P_IfHitByWeapon(short sn);

void P_MoveCyclers(void);

void P_MoveDummyPlayers(void);

void P_MovePlayers(void);

void P_MoveFX(void);

void P_MoveFallers(void);

void P_MoveStandables(void);

void P_Bounce(short i);

void P_MoveWeapons(void);

void P_MoveTransports(void);

void P_MoveActors(void);

void P_MoveExplosions(void);

void P_MoveEffectors(void);

extern short otherp;
