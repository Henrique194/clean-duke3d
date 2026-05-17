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

#ifdef _MSC_VER
#pragma warning(disable : 4761)
#endif

#ifdef _DEBUG
#define STUBBED(x) printf("STUB: %s in %s:%d\n", x, __FILE__, __LINE__)
#else
#define STUBBED(x)
#endif

#define PATH_SEP_CHAR '\\'
#define PATH_SEP_STR  "\\"

#include <sys/stat.h>
#include <io.h>
#include <assert.h>
#include <fcntl.h>

struct find_t {
    int32_t handle;
    struct _finddata_t data;
    uint8_t name[MAX_PATH];
};
int _dos_findfirst(uint8_t* filename, int x, struct find_t* f);
int _dos_findnext(struct find_t* f);

struct dosdate_t {
    uint8_t day;
    uint8_t month;
    unsigned int year;
    uint8_t dayofweek;
};

#ifndef min
#define min(x, y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x, y) ((x) > (y) ? (x) : (y))
#endif

// 64 megs should be enough for anybody.  :)  --ryan.
#define Z_AvailHeap() ((64 * 1024) * 1024)

#define printchrasm(x, y, ch) printf("%c", (uint8_t) (ch & 0xFF))

#define cdecl

#define open _open

#ifndef O_BINARY
#define O_BINARY _O_BINARY
#endif
#ifndef O_RDONLY
#define O_RDONLY _O_RDONLY
#endif
#ifndef O_WRONLY
#define O_WRONLY _O_WRONLY
#endif
#ifndef O_RDWR
#define O_RDWR _O_RDWR
#endif
#ifndef O_TRUNC
#define O_TRUNC _O_TRUNC
#endif
#ifndef O_CREAT
#define O_CREAT _O_CREAT
#endif
#ifndef S_IREAD
#define S_IREAD _S_IREAD
#endif
#ifndef S_IWRITE
#define S_IWRITE _S_IWRITE
#endif
#ifndef S_IRDWR
#define S_IRDWR _S_IRDWR
#endif

#ifndef S_IRUSR
#define S_IRUSR S_IREAD
#endif
#ifndef S_IWUSR
#define S_IWUSR S_IWRITE
#endif
#ifndef S_IRGRP
#define S_IRGRP 0
#endif
#ifndef S_IWGRP
#define S_IWGRP 0
#endif

#define F_OK 0

#define HAVE_PRAGMA_PACK 1
