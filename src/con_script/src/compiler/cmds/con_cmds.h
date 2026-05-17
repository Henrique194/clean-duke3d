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

#include "con_main.h"

//
// action <name> <startframe> <frames> <viewtype> <incvalue> <delay>
//
void CON_Action(con_compiler_t* ctx);

void CON_Actor(con_compiler_t* ctx);

void CON_EndActor(con_compiler_t* ctx);

void CON_UserActor(con_compiler_t* ctx);

//
// ai <name> <action> <speed> <type>
//
void CON_AI(con_compiler_t* ctx);

void CON_BetaName(con_compiler_t* ctx);

void CON_RightBrace(con_compiler_t* ctx);

void CON_LeftBrace(con_compiler_t* ctx);

void CON_SkipComment(con_compiler_t* ctx);

void CON_SkipBlockComment(con_compiler_t* ctx);

//
// define <string> <value>
//
void CON_Define(con_compiler_t* ctx);

void CON_DefineSound(con_compiler_t* ctx);

void CON_DefineQuote(con_compiler_t* ctx);

void CON_DefineLevelName(con_compiler_t* ctx);

void CON_DefineSkillName(con_compiler_t* ctx);

void CON_DefineVolName(con_compiler_t* ctx);

void CON_GameStartup(con_compiler_t* ctx);

void CON_If(con_compiler_t* ctx);

void CON_IfPlayer(con_compiler_t* ctx);

void CON_IfPlayerInventory(con_compiler_t* ctx);

void CON_IfNum(con_compiler_t* ctx);

void CON_Else(con_compiler_t* ctx);

//
// include <filename>
//
void CON_Include(con_compiler_t* ctx);

//
// move <name> <horizontal> <vertical> <directions>
//
void CON_Move(con_compiler_t* ctx);

void CON_Music(con_compiler_t* ctx);

//
// palfrom <intensity> <red> <green> <blue>
//
void CON_PalFrom(con_compiler_t* ctx);

void CON_State(con_compiler_t* ctx);

void CON_Ends(con_compiler_t* ctx);
