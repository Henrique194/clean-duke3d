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

#include "con_parser.h"
#include "con_keyword.h"
#include "cmds/con_cmds.h"
#include "con_misc.h"
#include "duke3d.h"


typedef void (*cmd_parser_t)(con_compiler_t* ctx);

static cmd_parser_t parsers[NUM_KEYWORDS] = {
    [CK_DEF_LEVEL_NAME] = CON_DefineLevelName,
    [CK_ACTOR] = CON_Actor,
    [CK_ADD_AMMO] = CON_LexNum2,
    [CK_IF_RND] = CON_IfNum,
    [CK_END_ACTOR] = CON_EndActor,
    [CK_IF_CAN_SEE] = CON_If,
    [CK_IF_HIT_WEAPON] = CON_If,
    [CK_ACTION] = CON_Action,
    [CK_IF_PLAYER_DIST_LT] = CON_IfNum,
    [CK_IF_PLAYER_DIST_GT] = CON_IfNum,
    [CK_ELSE] = CON_Else,
    [CK_STRENGTH] = CON_LexNum,
    [CK_SHOOT] = CON_LexNum,
    [CK_PAL_FROM] = CON_PalFrom,
    [CK_SOUND] = CON_LexNum,
    [CK_STATE] = CON_State,
    [CK_ENDS] = CON_Ends,
    [CK_DEFINE] = CON_Define,
    [CK_COMMENT] = CON_SkipComment,
    [CK_IF_AI] = CON_IfNum,
    [CK_ADD_WEAPON] = CON_LexNum2,
    [CK_AI] = CON_AI,
    [CK_ADD_PLAYER_HEALTH] = CON_LexNum,
    [CK_IF_DEAD] = CON_If,
    [CK_IF_SQUISHED] = CON_If,
    [CK_SIZE_TO] = CON_LexNum2,
    [CK_LEFT_BRACE] = CON_LeftBrace,
    [CK_RIGHT_BRACE] = CON_RightBrace,
    [CK_SPAWN] = CON_LexNum,
    [CK_MOVE] = CON_Move,
    [CK_IF_WAS_WEAPON] = CON_IfNum,
    [CK_IF_ACTION] = CON_IfNum,
    [CK_IF_ACTION_COUNT] = CON_IfNum,
    [CK_DEBRIS] = CON_LexNum2,
    [CK_BLOCK_COMMENT] = CON_SkipBlockComment,
    [CK_SET_SPRITE_STAT] = CON_LexNum,
    [CK_IF_MOVE] = CON_IfNum,
    [CK_IF_ON_WATER] = CON_If,
    [CK_IF_IN_WATER] = CON_If,
    [CK_IF_CAN_SHOOT_TARGET] = CON_If,
    [CK_IF_COUNT] = CON_IfNum,
    [CK_ADD_INVENTORY] = CON_LexNum2,
    [CK_IF_ACTOR_NOT_STAYPUT] = CON_If,
    [CK_HIT_RADIUS] = CON_LexNum5,
    [CK_IF_PLAYER] = CON_IfPlayer,
    [CK_COUNT] = CON_LexNum,
    [CK_IF_ACTOR] = CON_IfNum,
    [CK_MUSIC] = CON_Music,
    [CK_INCLUDE] = CON_Include,
    [CK_IF_STRENGTH] = CON_IfNum,
    [CK_DEFINE_SOUND] = CON_DefineSound,
    [CK_GUTS] = CON_LexNum2,
    [CK_IF_SPAWNED_BY] = CON_IfNum,
    [CK_GAME_STARTUP] = CON_GameStartup,
    [CK_IF_GAP_Z_LT] = CON_IfNum,
    [CK_IF_HIT_SPACE] = CON_If,
    [CK_IF_OUTSIDE] = CON_If,
    [CK_IF_MULTIPLAYER] = CON_If,
    [CK_IF_IN_SPACE] = CON_If,
    [CK_DEBUG] = CON_LexNum,
    [CK_END_OF_GAME] = CON_LexNum,
    [CK_IF_BULLET_NEAR] = CON_If,
    [CK_IF_RESPAWN] = CON_If,
    [CK_IF_FLOOR_DIST_LT] = CON_IfNum,
    [CK_IF_CEILING_DIST_LT] = CON_IfNum,
    [CK_SPRITE_PAL] = CON_LexNum,
    [CK_IF_PLAYER_INVENTORY] = CON_IfPlayerInventory,
    [CK_BETA_NAME] = CON_BetaName,
    [CK_CHANGE_ACTOR] = CON_LexNum,
    [CK_IF_PLAYER_HEALTH_LT] = CON_IfNum,
    [CK_DEFINE_QUOTE] = CON_DefineQuote,
    [CK_QUOTE] = CON_LexNum,
    [CK_IF_IN_OUTER_SPACE] = CON_If,
    [CK_IF_NOT_MOVING] = CON_If,
    [CK_IF_SPRITE_PAL] = CON_IfNum,
    [CK_MONEY] = CON_LexNum,
    [CK_SOUND_ONCE] = CON_LexNum,
    [CK_ADD_KILLS] = CON_LexNum,
    [CK_STOP_SOUND] = CON_LexNum,
    [CK_IF_AWAY_FROM_WALL] = CON_If,
    [CK_IF_CAN_SEE_TARGET] = CON_If,
    [CK_GLOBAL_SOUND] = CON_LexNum,
    [CK_LOTS_OF_GLASS] = CON_LexNum,
    [CK_IF_GOT_WEAPON_ONCE] = CON_IfNum,
    [CK_USER_ACTOR] = CON_UserActor,
    [CK_SIZE_AT] = CON_LexNum2,
    [CK_ADD_STRENGTH] = CON_LexNum,
    [CK_SET_SPRITE_STAT_OR] = CON_LexNum,
    [CK_MAIL] = CON_LexNum,
    [CK_PAPER] = CON_LexNum,
    [CK_SLEEP_TIME] = CON_LexNum,
    [CK_DEFINE_VOL_NAME] = CON_DefineVolName,
    [CK_DEFINE_SKILL_NAME] = CON_DefineSkillName,
    [CK_IF_NO_SOUNDS] = CON_If,
    [CK_CLIP_DIST] = CON_LexNum,
    [CK_IF_ANGLE_DIFF_LT] = CON_IfNum,
};


con_keyword_t CON_ParseCmd(con_compiler_t* ctx) {
    if (ctx->error > 12) {
        // Too many errors, stop compiling.
        return CK_NONE;
    }
    if (ctx->cursor[0] == '\0' || ctx->cursor[1] == '\0') {
        // End of file.
        return CK_NONE;
    }
    con_keyword_t keyword = CON_LexKeyword(ctx);
    if (keyword == CK_NONE) {
        return CK_NONE;
    }
    cmd_parser_t parser = parsers[keyword];
    if (parser) {
        parser(ctx);
    }
    return keyword;
}

void CON_ParseFile(con_compiler_t* ctx) {
    while (true) {
        con_keyword_t keyword = CON_ParseCmd(ctx);
        if (keyword == CK_NONE) {
            break;
        }
    }
    if ((ctx->error + ctx->warning) > 12) {
        printf("  * ERROR! Too many warnings or errors.\n");
    }
    if (ctx->warning > 0 || ctx->error > 0) {
        printf("Found %hhd warning(s), '%c' error(s).\n", ctx->warning, ctx->error);
    }
    ctx->total_lines += ctx->line_number;
    script[0] = CON_EncodeScript(ctx->script_cursor);
}
