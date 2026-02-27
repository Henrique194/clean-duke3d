/*
 * Copyright (C) 1994-1995 Apogee Software, Ltd.
 * Copyright (C) 1996, 2003 - 3D Realms Entertainment
 * Copyright (C) Henrique Barateli, <henriquejb194@gmail.com>, et al.
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

#include <stdint.h>

#define TRANS_NORMAL  0
#define TRANS_REVERSE 1

// tanguyf: pixelsAllowed causes too many subtle rendering bugs to be left on by default
#define RENDER_LIMIT_PIXELS 0

#define RENDER_DRAW_WALL_BORDERS 1
#define RENDER_DRAW_WALL_INSIDE 1
#define RENDER_DRAW_CEILING_AND_FLOOR 1
#define RENDER_DRAW_TOP_AND_BOTTOM_COLUMN 1
#define RENDER_SLOPPED_CEILING_AND_FLOOR 1

#if RENDER_DRAW_WALL_BORDERS                                                   \
    && RENDER_DRAW_WALL_INSIDE                                                 \
    && RENDER_DRAW_CEILING_AND_FLOOR                                           \
    && RENDER_DRAW_TOP_AND_BOTTOM_COLUMN                                       \
    && RENDER_SLOPPED_CEILING_AND_FLOOR
#define CLEAR_FRAMEBUFFER 0
#else
#define CLEAR_FRAMEBUFFER 1
#endif


#if RENDER_LIMIT_PIXELS
extern int64_t pixelsAllowed;
#endif

extern uint8_t* transluc;

extern uint8_t* globalpalwritten;
extern int16_t globalshiftval;
extern int32_t vplce[4], vince[4];
extern intptr_t bufplce[4];
extern uint8_t* palookupoffse[4];

extern int32_t asm1;
extern intptr_t asm2;
extern intptr_t asm3;
extern int32_t asm4;


void sethlinesizes(int32_t i1, int32_t _bits, const uint8_t * textureAddress);

void hlineasm4(
    int32_t numPixels,
    int32_t shade,
    uint32_t i4,
    uint32_t i5,
    uint8_t* dest
);

void setuprhlineasm4(
    int32_t i1,
    int32_t i2,
    int32_t i3,
    const uint8_t* i4,
    int32_t i5,
    int32_t i6
);

void rhlineasm4(
    int32_t i1,
    const uint8_t* texture,
    int32_t i3,
    uint32_t i4,
    uint32_t i5,
    uint8_t* dest
);

void setuprmhlineasm4(
    int32_t i1,
    int32_t i2,
    int32_t i3,
    const uint8_t* i4,
    int32_t tileHeight,
    int32_t i6
);

void rmhlineasm4(
    int32_t i1,
    const uint8_t* shade,
    int32_t colorIndex,
    int32_t i4,
    int32_t i5,
    uint8_t* dest
);


void setBytesPerLine(int32_t _bytesperline);

int32_t prevlineasm1(
    int32_t i1,
    const uint8_t* palette,
    int32_t i3,
    int32_t i4,
    const uint8_t* source,
    uint8_t* dest
);

int32_t vlineasm1(
    int32_t vince,
    const uint8_t* palookupoffse,
    int32_t numPixels,
    int32_t vplce,
    const uint8_t* texture,
    uint8_t* dest
);

int32_t tvlineasm1(
    int32_t i1,
    const uint8_t* texture,
    int32_t numPixels,
    int32_t i4,
    const uint8_t* source,
    uint8_t* dest
);

void setuptvlineasm2(int32_t i1, const uint8_t* i2, const uint8_t* i3);

void tvlineasm2(
    uint32_t i1,
    uint32_t i2,
    uintptr_t i3,
    uintptr_t i4,
    uint32_t i5,
    uintptr_t i6
);

int32_t mvlineasm1(
    int32_t,
    const uint8_t*,
    int32_t,
    int32_t,
    const uint8_t* texture,
    uint8_t* dest
);

void setupvlineasm(int32_t);

void vlineasm4(int32_t, uint8_t*);

void setupmvlineasm(int32_t);

void mvlineasm4(int32_t, uint8_t*);

void tsetupspritevline(
    const uint8_t*,
    int32_t,
    int32_t,
    int32_t,
    int32_t
);

void DrawSpriteVerticalLine(
    int32_t,
    int32_t,
    uint32_t,
    const uint8_t*,
    uint8_t*
);

void mhline(uint8_t*, int32_t, int32_t, int32_t, int32_t, uint8_t*);

void mhlineskipmodify(uint32_t, int32_t, int32_t, uint8_t*);

void msethlineshift(int32_t, int32_t);

void thline(uint8_t*, int32_t, int32_t, int32_t, int32_t, uint8_t*);

void thlineskipmodify(int32_t, uint32_t, uint32_t, int32_t, int32_t, uint8_t*);

void tsethlineshift(int32_t, int32_t);

void setupslopevlin(int32_t, intptr_t, int32_t);

void slopevlin(
    intptr_t,
    uint32_t,
    intptr_t*,
    uint32_t,
    int32_t,
    int32_t,
    int32_t
);

void settrans(int32_t type);