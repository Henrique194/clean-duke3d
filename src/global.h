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

#include "types.h"

enum {
    filetype_binary,
    filetype_text,
};


int FindDistance3D(int ix, int iy, int iz);

void Shutdown(void);

void RegisterShutdownFunction(void (*shutdown)(void));

void Error(int errorType, const char* error, ...);


void FixFilePath(char* filename);

//
// Opens a file for writing, returns handle.
//
int32 SafeOpenWrite ( const char  * filename, int32 filetype );

//
// Opens a file for reading, returns handle.
//
int32 SafeOpenRead ( const char  * filename, int32 filetype );

//
// Opens a file for appending, returns handle.
//
int32 SafeOpenAppend ( const char  * filename, int32 filetype );

//
// Checks for existence of file..
//
boolean SafeFileExists ( const char  * filename );

//
// Reads from a handle.
//  handle - handle of file to read from
//  buffer - pointer of buffer to read into
//  count  - number of bytes to read
//
void SafeRead (int32 handle, void *buffer, int32 count);

//
// Writes to a handle.
//   handle - handle of file to write to
//   buffer - pointer of buffer to write from
//   count  - number of bytes to write
//
void SafeWrite (int32 handle, void *buffer, int32 count);


uint8_t CheckParm(const char* check);

void* SafeMalloc(int32 size);

void SafeFree(void* ptr);

void SafeRealloc(void** ptr, int32 newsize);


extern int32 _argc;
extern char** _argv;
