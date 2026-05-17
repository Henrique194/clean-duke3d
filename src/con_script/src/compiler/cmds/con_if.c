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

#include "con_cmds.h"
#include "con_keyword.h"
#include "con_misc.h"
#include "con_parser.h"
#include "con_script/con_script.h"

void CON_If(con_compiler_t* ctx) {
    i32* tempscrptr = ctx->script_cursor;
    ctx->script_cursor++; // Leave a spot for the fail location

    i32 j;
    do {
        j = CON_PeekKeyword(ctx);
        if (j == 20 || j == 39) {
            CON_ParseCmd(ctx);
        }
    } while (j == 20 || j == 39);

    CON_ParseCmd(ctx);

    *tempscrptr = CON_EncodeScript(ctx->script_cursor);

    ctx->if_depth++;
}

void CON_IfPlayer(con_compiler_t* ctx) {
    i32 j = 0;
    do {
        CON_LexNum(ctx);
        ctx->script_cursor--;
        j |= *ctx->script_cursor;
    } while (CON_PeekKeyword(ctx) == -1);
    *ctx->script_cursor = j;
    ctx->script_cursor++;
    CON_If(ctx);
}

void CON_IfPlayerInventory(con_compiler_t* ctx) {
    CON_LexNum(ctx);
    CON_LexNum(ctx);
    CON_If(ctx);
}

void CON_IfNum(con_compiler_t* ctx) {
    CON_LexNum(ctx);
    CON_If(ctx);
}

void CON_Else(con_compiler_t* ctx) {
    if (!ctx->if_depth) {
        ctx->script_cursor--;
        CON_Error("Found 'else' with no 'if'.\n");
        return;
    }
    ctx->if_depth--;
    i32* tempscrptr = ctx->script_cursor;
    ctx->script_cursor++; // Leave a spot for the fail location
    CON_ParseCmd(ctx);
    *tempscrptr = CON_EncodeScript(ctx->script_cursor);
}
