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

void P_ResetMys(void);

void P_DoCacheIt(void);

void P_ClearFifo(void);

void P_CacheIt(void);

void P_XYZMirror(short i, short wn);

void P_ViewChanged(void);

int P_CountFragBars(void);

void P_PickRandomSpot(short snum);

void P_ResetWeapons(short snum);

void P_ResetInventory(short snum);

void P_NewGame(uint8_t vn, uint8_t ln, uint8_t sk);

void P_ResetTimeVars(void);

void P_GenSpriteRemaps(void);

void P_WaitForEverybody(void);

void P_EnterLevel(uint8_t g);
