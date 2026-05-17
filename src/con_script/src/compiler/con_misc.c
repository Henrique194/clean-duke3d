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

#include "con_misc.h"
#include "con_keyword.h"
#include "con_label.h"
#include "types.h"
#include "duke3d.h"

bool CON_IsLetter(char c) {
    return SDL_isalnum(c) || c == '{' || c == '}' || c == '/'
           || c == '*' || c == '-' || c == '_' || c == '.';
}

bool CON_IsSpecial(con_compiler_t* ctx, char c) {
    if (c == '\n') {
        ctx->line_number++;
        return true;
    }
    return c == ' ' || c == '\r';
}

void CON_SkipSpace(con_compiler_t* ctx) {
    while (!CON_IsLetter(*ctx->cursor)) {
        if (*ctx->cursor == 0) {
            break;
        }
        if (*ctx->cursor == '\n') {
            ctx->line_number++;
        }
        ctx->cursor++;
    }
}

char* CON_LexString(con_compiler_t* ctx) {
    i32 j = 0;
    while (CON_IsLetter(*ctx->cursor)) {
        tempbuf[j] = *(ctx->cursor++);
        j++;
    }
    tempbuf[j] = '\0';
    return (char*) tempbuf;
}

void CON_LexNum(con_compiler_t* ctx) {
    CON_SkipSpace(ctx);
    const char* str = CON_LexString(ctx);
    if (CON_IsKeyword(ctx->label + (ctx->label_cnt << 6))) {
        CON_Error("Symbol '%s' is a key word.\n", ctx->label + (ctx->label_cnt << 6));
    }
    const int code = CON_GetLabel(ctx, str);
    if (code >= 0) {
        *ctx->script_cursor = ctx->label_code[code];
        ctx->script_cursor++;
        return;
    }
    if (!SDL_isdigit(*str) && *str != '-') {
        CON_Error("Parameter '%s' is undefined.\n", str);
        return;
    }
    *ctx->script_cursor = atol(str);
    ctx->script_cursor++;
}

void CON_LexNum2(con_compiler_t* ctx) {
    CON_LexNum(ctx);
    CON_LexNum(ctx);
}

void CON_LexNum5(con_compiler_t* ctx) {
    CON_LexNum(ctx);
    CON_LexNum(ctx);
    CON_LexNum(ctx);
    CON_LexNum(ctx);
    CON_LexNum(ctx);
}
