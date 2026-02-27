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
// sounds.h
//
//****************************************************************************

#pragma once

#include "types.h"

#define HIRESMUSICPATH "tunes"

enum USRHOOKS_Errors {
    USRHOOKS_Warning = -2,
    USRHOOKS_Error = -1,
    USRHOOKS_Ok = 0,
};


extern int32 FXDevice;
extern int32 MusicDevice;
extern int32 FXVolume;
extern int32 MusicVolume;
extern int32 NumVoices;
extern int32 NumChannels;
extern int32 NumBits;
extern int32 MixRate;
extern int32 MidiPort;
extern int32 ReverseStereo;
extern int32 numenvsnds;


void SoundStartup(void);

void SoundShutdown(void);

void MusicStartup(void);

void MusicShutdown(void);


void playmusic(char* fn);

void clearsoundlocks(void);

void intomenusounds(void);

uint8_t loadsound(uint16_t num);

int xyzsound(short num, short i, int32_t x, int32_t y, int32_t z);

void sound(short num);

int spritesound(uint16_t num, short i);

void stopsound(short num);

void stopenvsound(short num, short i);

void pan3dsound(void);

void TestCallBack(int32_t num);

/* dunno where this came from; I added it. --ryan. */
void testcallback(uint32_t num);


int USRHOOKS_GetMem(void** ptr, uint32_t size);

int USRHOOKS_FreeMem(void* ptr);
