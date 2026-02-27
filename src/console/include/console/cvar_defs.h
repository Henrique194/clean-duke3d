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

#include <inttypes.h>

void CVARDEFS_Init();
void CVARDEFS_Render();
//
// Function declarations
//
void CVARDEFS_DefaultFunction(void* cvar);
void CVARDEFS_FunctionQuit(void* var);
void CVARDEFS_FunctionClear(void* var);
void CVARDEFS_FunctionLevel(void* var);
void CVARDEFS_FunctionName(void* var);
void CVARDEFS_FunctionPlayMidi(void* var);
void CVARDEFS_FunctionFOV(void* var);
void CVARDEFS_FunctionTickRate(void* var);
void CVARDEFS_FunctionTicksPerFrame(void* var);
void CVARDEFS_FunctionHelp(void* var);

//
// Variable declarations
//
extern int g_CV_console_text_color;
extern int g_CV_num_console_lines;
extern int g_CV_classic;
extern int g_CV_TransConsole;
extern int g_CV_DebugJoystick;
extern int g_CV_DebugSound;
extern int g_CV_DebugFileAccess;
extern uint32_t sounddebugActiveSounds;
extern uint32_t sounddebugAllocateSoundCalls;
extern uint32_t sounddebugDeallocateSoundCalls;


extern int g_CV_CubicInterpolation;
