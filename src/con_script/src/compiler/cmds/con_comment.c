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
#include "con_main.h"


void CON_SkipComment(con_compiler_t* ctx) {
    ctx->script_cursor--; // Negate the rem
    while (*ctx->cursor != '\n') {
        ctx->cursor++;
    }
}

void CON_SkipBlockComment(con_compiler_t* ctx) {
    ctx->script_cursor--;
    short new_lines = 0;
    do {
        if (*ctx->cursor == '\n') {
            new_lines++;
        }
        if (*ctx->cursor == 0) {
            CON_Error("Found '/*' with no '*/'.\n");
            ctx->line_number += new_lines;
            return;
        }
        ctx->cursor++;
    } while (ctx->cursor[0] != '*' || ctx->cursor[1] != '/');
    ctx->line_number += new_lines;
    ctx->cursor += 2;
}
