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
#include "con_label.h"
#include "con_misc.h"
#include "con_script/con_script.h"

void CON_Action(con_compiler_t* ctx) {
    if (ctx->curr_actor || ctx->in_state_block) {
        CON_LexNum(ctx);
        return;
    }

    ctx->script_cursor--;
    const char* str = CON_LexLabel(ctx);

    // Check to see it's already defined.
    if (CON_IsKeyword(str)) {
        CON_Error("Symbol '%s' is a key word.\n", str);
        return;
    }
    if (CON_IsLabel(ctx, str)) {
        CON_Warn("Duplicate action '%s' ignored.\n", str);
    } else {
        ctx->label_code[ctx->label_cnt] = CON_EncodeScript(ctx->script_cursor);
        ctx->label_cnt++;
    }

    i32 i = 0;
    while (i < 5 && CON_PeekKeyword(ctx) < 0) {
        CON_LexNum(ctx);
        i++;
    }
    while (i < 5) {
        *ctx->script_cursor = 0;
        ctx->script_cursor++;
        i++;
    }
}
