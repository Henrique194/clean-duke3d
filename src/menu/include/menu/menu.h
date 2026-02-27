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
#include "audiolib/sounds.h"

void cmenu(short cm);

void savetemp(char* fn, uint8_t* daptr, int32_t dasiz);

void getangplayers(short snum);

int loadpheader(
    uint8_t spot,
    int32* vn,
    int32* ln,
    int32* psk,
    int32* numplr
);

int saveplayer(int8_t spot);

int probe(int x, int y, int i, int n);

int menutext(int x, int y, short s, short p, char* t);

int menutextc(int x, int y, short s, short p, char* t);

void bar(
    int x,
    int y,
    short* p,
    short dainc,
    uint8_t damodify,
    short s,
    short pa
);

void dispnames(void);

int getfilenames(char kind[]);

void sortfilenames(void);

void gameexitanycase(void);

void menus(void);

void palto(uint8_t r, uint8_t g, uint8_t b, int32_t e, int present);

void playanm(char* fn, uint8_t);
