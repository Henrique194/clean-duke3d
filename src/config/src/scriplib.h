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

// scriplib.h

#pragma once

#include "types.h"

/*
==============
=
= SCRIPT_Init
=
==============
*/
i32 SCRIPT_Init(u8* name);


/*
==============
=
= SCRIPT_Free
=
==============
*/
void SCRIPT_Free(i32 scripthandle);

/*
==============
=
= SCRIPT_Parse
=
==============
*/
i32 SCRIPT_Parse(u8* data, i32 length, char* name);


/*
==============
=
= SCRIPT_Load
=
==============
*/
i32 SCRIPT_Load(char* filename);

/*
==============
=
= SCRIPT_Save
=
==============
*/
void SCRIPT_Save(i32 scripthandle, char* filename);


/*
==============
=
= SCRIPT_NumberSections
=
==============
*/
i32 SCRIPT_NumberSections(i32 scripthandle);

/*
==============
=
= SCRIPT_Section
=
==============
*/
u8* SCRIPT_Section(i32 scripthandle, i32 which);

/*
==============
=
= SCRIPT_NumberEntries
=
==============
*/
i32 SCRIPT_NumberEntries(i32 scripthandle, char* sectionname);

/*
==============
=
= SCRIPT_Entry
=
==============
*/
char* SCRIPT_Entry(i32 scripthandle, char* sectionname, i32 which);


/*
==============
=
= SCRIPT_GetRaw
=
==============
*/
char* SCRIPT_GetRaw(i32 scripthandle, char* sectionname, char* entryname);

/*
==============
=
= SCRIPT_GetString
=
==============
*/
void SCRIPT_GetString(
    i32 scripthandle,
    char* sectionname,
    char* entryname,
    char* dest
);

/*
==============
=
= SCRIPT_GetDoubleString
=
==============
*/
void SCRIPT_GetDoubleString(
    i32 scripthandle,
    char* sectionname,
    char* entryname,
    char* dest1,
    char* dest2
);

/*
==============
=
= SCRIPT_GetNumber
=
==============
*/
boolean SCRIPT_GetNumber(
    i32 scripthandle,
    char* sectionname,
    char* entryname,
    i32* number
);

/*
==============
=
= SCRIPT_GetBoolean
=
==============
*/
void SCRIPT_GetBoolean(
    i32 scripthandle,
    u8* sectionname,
    u8* entryname,
    boolean* b
);

/*
==============
=
= SCRIPT_GetFloat
=
==============
*/
boolean SCRIPT_GetFloat(
    i32 scripthandle,
    char* sectionname,
    char* entryname,
    float* floatnumber
);


/*
==============
=
= SCRIPT_GetDouble
=
==============
*/
void SCRIPT_GetDouble(
    i32 scripthandle,
    char* sectionname,
    char* entryname,
    double* number
);


/*
==============
=
= SCRIPT_PutComment
=
==============
*/
void SCRIPT_PutComment(
    i32 scripthandle,
    u8* sectionname,
    u8* comment
);

/*
==============
=
= SCRIPT_PutEOL
=
==============
*/
void SCRIPT_PutEOL(i32 scripthandle, u8* sectionname);

/*
==============
=
= SCRIPT_PutMultiComment
=
==============
*/
void SCRIPT_PutMultiComment(
    i32 scripthandle,
    u8* sectionname,
    u8* comment,
    ...
);

/*
==============
=
= SCRIPT_PutSection
=
==============
*/
void SCRIPT_PutSection(i32 scripthandle, u8* sectionname);

/*
==============
=
= SCRIPT_PutRaw
=
==============
*/
void SCRIPT_PutRaw(
    i32 scripthandle,
    u8* sectionname,
    u8* entryname,
    u8* raw
);

/*
==============
=
= SCRIPT_PutString
=
==============
*/
void SCRIPT_PutString(
    i32 scripthandle,
    char* sectionname,
    char* entryname,
    char* string
);

/*
==============
=
= SCRIPT_PutDoubleString
=
==============
*/
void SCRIPT_PutDoubleString(
    i32 scripthandle,
    char* sectionname,
    char* entryname,
    char* string1,
    char* string2
);

/*
==============
=
= SCRIPT_PutNumber
=
==============
*/
void SCRIPT_PutNumber(
    i32 scripthandle,
    char* sectionname,
    char* entryname,
    i32 number,
    boolean hexadecimal,
    boolean defaultvalue
);

/*
==============
=
= SCRIPT_PutBoolean
=
==============
*/
void SCRIPT_PutBoolean(
    i32 scripthandle,
    u8* sectionname,
    u8* entryname,
    boolean b
);

/*
==============
=
= SCRIPT_PutDouble
=
==============
*/
void SCRIPT_PutDouble(
    i32 scripthandle,
    u8* sectionname,
    u8* entryname,
    double number,
    boolean defaultvalue
);
