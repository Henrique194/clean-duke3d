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

#include "com_main.h"

//
// action <name> <startframe> <frames> <viewtype> <incvalue> <delay>
//
void COM_Action(con_compiler_t* ctx);

void COM_Actor(con_compiler_t* ctx);

void COM_EndActor(con_compiler_t* ctx);

void COM_UserActor(con_compiler_t* ctx);

//
// ai <name> <action> <speed> <type>
//
void COM_AI(con_compiler_t* ctx);

void COM_BetaName(con_compiler_t* ctx);

void COM_RightBrace(con_compiler_t* ctx);

void COM_LeftBrace(con_compiler_t* ctx);

void COM_SkipComment(con_compiler_t* ctx);

void COM_SkipBlockComment(con_compiler_t* ctx);

//
// define <string> <value>
//
void COM_Define(con_compiler_t* ctx);

void COM_DefineSound(con_compiler_t* ctx);

void COM_DefineQuote(con_compiler_t* ctx);

void COM_DefineLevelName(con_compiler_t* ctx);

void COM_DefineSkillName(con_compiler_t* ctx);

void COM_DefineVolName(con_compiler_t* ctx);

void COM_GameStartup(con_compiler_t* ctx);

void COM_If(con_compiler_t* ctx);

void COM_IfPlayer(con_compiler_t* ctx);

void COM_IfPlayerInventory(con_compiler_t* ctx);

void COM_IfNum(con_compiler_t* ctx);

void COM_Else(con_compiler_t* ctx);

//
// include <filename>
//
void COM_Include(con_compiler_t* ctx);

//
// move <name> <horizontal> <vertical> <directions>
//
void COM_Move(con_compiler_t* ctx);

void COM_Music(con_compiler_t* ctx);

//
// palfrom <intensity> <red> <green> <blue>
//
void COM_PalFrom(con_compiler_t* ctx);

void COM_State(con_compiler_t* ctx);

void COM_Ends(con_compiler_t* ctx);
