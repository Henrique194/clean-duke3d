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

void HU_SetPlayerQuote(short q, player_t* p, int mode);

void HU_AddUserQuote(const char* quote);

void HU_TickPlayerQuote(player_t* p);

void HU_TickUserQuotes(void);

void HU_DrawQuotes(void);

int HU_DrawText(int x, int y, const char* text, u8 shade, short stat);

int HU_GameTextPal(int x, int y, const char* text, u8 shade, u8 pal);

int HU_DrawMiniText(int x, int y, const char* text, u8 pal, u8 stat);

int HU_MiniTextShade(int x, int y, const char* text, u8 shade, u8 pal, u8 stat);

extern int32_t quotebot;
extern int32_t quotebotgoal;
extern char fta_quotes[NUMOFFIRSTTIMEACTIVE][64];
