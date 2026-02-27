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

void CLS_Init(void);

void CLS_Shutdown(void);

void CLS_Reset(void);

void CLS_HandleInput(void);

void CLS_Render(void);

void CLS_Printf(const char* newmsg, ...);

//
// Get the current number of args for this keyword.
//
int CLS_GetArgc(void);

//
// Get the current list of args for this keyword.
//
char* CLS_GetArgv(unsigned int var);

//
// Is our console showing?
//
int CLS_IsActive(void);

void CLS_Hide(void);
