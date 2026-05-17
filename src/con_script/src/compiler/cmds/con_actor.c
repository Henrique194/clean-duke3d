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

void CON_Actor(con_compiler_t* ctx) {
    if (ctx->in_state_block) {
        CON_Error("Found 'actor' within 'state'.\n");
    }
    if (ctx->curr_actor) {
        CON_Error("Found 'actor' within 'actor'.\n");
    }

    ctx->brace_depth = 0;
    ctx->script_cursor--;
    ctx->curr_actor = ctx->script_cursor;

    CON_LexNum(ctx);
    ctx->script_cursor--;
    actorscrptr[*ctx->script_cursor] = ctx->curr_actor;

    for (i32 i = 0; i < 4; i++) {
        ctx->curr_actor[i] = 0;
        if (i == 3) {
            i = 0;
            while (CON_PeekKeyword(ctx) == -1) {
                CON_LexNum(ctx);
                ctx->script_cursor--;
                i |= *ctx->script_cursor;
            }
            *ctx->script_cursor = i;
            ctx->script_cursor++;
            break;
        }
        if (CON_PeekKeyword(ctx) >= 0) {
            ctx->script_cursor += (4 - i);
            break;
        }
        CON_LexNum(ctx);
        ctx->curr_actor[i] = *(ctx->script_cursor - 1);
    }

    ctx->if_depth = 0;
}

void CON_EndActor(con_compiler_t* ctx) {
    if (ctx->curr_actor == NULL) {
        CON_Error("Found 'enda' without defining 'actor'.\n");
    }
    if (ctx->brace_depth > 0) {
        CON_Error("Found more '{' than '}' before 'enda'.\n");
    }
    ctx->curr_actor = NULL;
}

void CON_UserActor(con_compiler_t* ctx) {
    if (ctx->in_state_block) {
        CON_Error("Found 'useritem' within 'state'.\n");
    }
    if (ctx->curr_actor) {
        CON_Error("Found 'useritem' within 'actor'.\n");
    }

    ctx->brace_depth = 0;
    ctx->script_cursor--;
    ctx->curr_actor = ctx->script_cursor;

    CON_LexNum(ctx);
    ctx->script_cursor--;
    u8 type = (u8) *ctx->script_cursor;

    CON_LexNum(ctx);
    ctx->script_cursor--;
    actorscrptr[*ctx->script_cursor] = ctx->curr_actor;
    actortype[*ctx->script_cursor] = type;

    for (i32 i = 0; i < 4; i++) {
        ctx->curr_actor[i] = 0;
        if (i == 3) {
            i = 0;
            while (CON_PeekKeyword(ctx) == -1) {
                CON_LexNum(ctx);
                ctx->script_cursor--;
                i |= *ctx->script_cursor;
            }
            *ctx->script_cursor = i;
            ctx->script_cursor++;
            break;
        }
        if (CON_PeekKeyword(ctx) >= 0) {
            ctx->script_cursor += (4 - i);
            break;
        }
        CON_LexNum(ctx);
        ctx->curr_actor[i] = *(ctx->script_cursor - 1);
    }

    ctx->if_depth = 0;
}
