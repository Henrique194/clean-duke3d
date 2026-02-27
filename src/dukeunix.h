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

#define cdecl
#define __far
#define __interrupt


//#define STUBBED(x)
#ifdef __SUNPRO_C
#define STUBBED(x) fprintf(stderr,"STUB: %s (??? %s:%d)\n",x,__FILE__,__LINE__)
#else
#define STUBBED(x) fprintf(stderr,"STUB: %s (%s, %s:%d)\n",x,__FUNCTION__,__FILE__,__LINE__)
#endif

#define PATH_SEP_CHAR '/'
#define PATH_SEP_STR  "/"
#define ROOTDIR       "/"
#define CURDIR        "./"

#ifndef O_BINARY
#define O_BINARY 0
#endif

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <assert.h>

struct find_t
{
    DIR *dir;
    char  pattern[MAX_PATH];
    char  name[MAX_PATH];
};
int _dos_findfirst(char  *filename, int x, struct find_t *f);
int _dos_findnext(struct find_t *f);

struct dosdate_t
{
    uint8_t  day;
    uint8_t  month;
    unsigned int year;
    uint8_t  dayofweek;
};

#ifndef min
#define min(x, y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x, y) ((x) > (y) ? (x) : (y))
#endif

#ifdef DC
#undef stderr
#undef stdout
#undef getchar
/* kos compat */
#define stderr ((FILE*)2)
#define stdout ((FILE*)2)
#define Z_AvailHeap() ((10 * 1024) * 1024)
#else
// 64 megs should be enough for anybody.  :)  --ryan.
#define Z_AvailHeap() ((64 * 1024) * 1024)
#endif

#define printchrasm(x,y,ch) printf("%c", (uint8_t ) (ch & 0xFF))

#ifdef __GNUC__
#define GCC_PACK1_EXT __attribute__((packed,aligned(1)))
#endif


// FCS: Game.c features calls to mkdir without the proper flags.
// Giving all access is ugly but it is just game OK !
#define mkdir(X) mkdir(X,0777)

#define getch getchar
