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
#include "duke3d.h"

void CON_Music(con_compiler_t* ctx) {
    ctx->script_cursor--;
    CON_LexNum(ctx); // Volume Number (0/4)
    ctx->script_cursor--;

    i32 k = *ctx->script_cursor - 1;
    char (*mus_fn)[13];
    if (k >= 0) {
        // Background music.
        mus_fn = music_fn[k];
    } else {
        mus_fn = env_music_fn;
    }

    i32 i = 0;
    while (CON_PeekKeyword(ctx) == -1) {
        CON_SkipSpace(ctx);

        i32 j = 0;
        while (CON_IsLetter(ctx->cursor[j])) {
            mus_fn[i][j] = ctx->cursor[j];
            j++;
        }
        mus_fn[i][j] = '\0';
        ctx->cursor += j;

        if (i > 9) {
            break;
        }
        i++;
    }
}
