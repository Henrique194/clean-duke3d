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

#include "con_keyword.h"
#include "con_misc.h"
#include "duke3d.h"
#include <SDL_stdinc.h>

static const char* keyw[NUM_KEYWORDS] = {
    [CK_DEF_LEVEL_NAME] = "definelevelname",
    [CK_ACTOR] = "actor",
    [CK_ADD_AMMO] = "addammo",
    [CK_IF_RND] = "ifrnd",
    [CK_END_ACTOR] = "enda",
    [CK_IF_CAN_SEE] = "ifcansee",
    [CK_IF_HIT_WEAPON] = "ifhitweapon",
    [CK_ACTION] = "action",
    [CK_IF_PLAYER_DIST_LT] = "ifpdistl",
    [CK_IF_PLAYER_DIST_GT] = "ifpdistg",
    [CK_ELSE] = "else",
    [CK_STRENGTH] = "strength",
    [CK_BREAK] = "break",
    [CK_SHOOT] = "shoot",
    [CK_PAL_FROM] = "palfrom",
    [CK_SOUND] = "sound",
    [CK_FALL] = "fall",
    [CK_STATE] = "state",
    [CK_ENDS] = "ends",
    [CK_DEFINE] = "define",
    [CK_COMMENT] = "//",
    [CK_IF_AI] = "ifai",
    [CK_KILL_IT] = "killit",
    [CK_ADD_WEAPON] = "addweapon",
    [CK_AI] = "ai",
    [CK_ADD_PLAYER_HEALTH] = "addphealth",
    [CK_IF_DEAD] = "ifdead",
    [CK_IF_SQUISHED] = "ifsquished",
    [CK_SIZE_TO] = "sizeto",
    [CK_LEFT_BRACE] = "{",
    [CK_RIGHT_BRACE] = "}",
    [CK_SPAWN] = "spawn",
    [CK_MOVE] = "move",
    [CK_IF_WAS_WEAPON] = "ifwasweapon",
    [CK_IF_ACTION] = "ifaction",
    [CK_IF_ACTION_COUNT] = "ifactioncount",
    [CK_RESET_ACTION_COUNT] = "resetactioncount",
    [CK_DEBRIS] = "debris",
    [CK_PLAYER_STOMP] = "pstomp",
    [CK_BLOCK_COMMENT] = "/*",
    [CK_SET_SPRITE_STAT] = "cstat",
    [CK_IF_MOVE] = "ifmove",
    [CK_RESET_PLAYER] = "resetplayer",
    [CK_IF_ON_WATER] = "ifonwater",
    [CK_IF_IN_WATER] = "ifinwater",
    [CK_IF_CAN_SHOOT_TARGET] = "ifcanshoottarget",
    [CK_IF_COUNT] = "ifcount",
    [CK_RESET_COUNT] = "resetcount",
    [CK_ADD_INVENTORY] = "addinventory",
    [CK_IF_ACTOR_NOT_STAYPUT] = "ifactornotstayput",
    [CK_HIT_RADIUS] = "hitradius",
    [CK_IF_PLAYER] = "ifp",
    [CK_COUNT] = "count",
    [CK_IF_ACTOR] = "ifactor",
    [CK_MUSIC] = "music",
    [CK_INCLUDE] = "include",
    [CK_IF_STRENGTH] = "ifstrength",
    [CK_DEFINE_SOUND] = "definesound",
    [CK_GUTS] = "guts",
    [CK_IF_SPAWNED_BY] = "ifspawnedby",
    [CK_GAME_STARTUP] = "gamestartup",
    [CK_WACK_PLAYER] = "wackplayer",
    [CK_IF_GAP_Z_LT] = "ifgapzl",
    [CK_IF_HIT_SPACE] = "ifhitspace",
    [CK_IF_OUTSIDE] = "ifoutside",
    [CK_IF_MULTIPLAYER] = "ifmultiplayer",
    [CK_OPERATE] = "operate",
    [CK_IF_IN_SPACE] = "ifinspace",
    [CK_DEBUG] = "debug",
    [CK_END_OF_GAME] = "endofgame",
    [CK_IF_BULLET_NEAR] = "ifbulletnear",
    [CK_IF_RESPAWN] = "ifrespawn",
    [CK_IF_FLOOR_DIST_LT] = "iffloordistl",
    [CK_IF_CEILING_DIST_LT] = "ifceilingdistl",
    [CK_SPRITE_PAL] = "spritepal",
    [CK_IF_PLAYER_INVENTORY] = "ifpinventory",
    [CK_BETA_NAME] = "betaname",
    [CK_CHANGE_ACTOR] = "cactor",
    [CK_IF_PLAYER_HEALTH_LT] = "ifphealthl",
    [CK_DEFINE_QUOTE] = "definequote",
    [CK_QUOTE] = "quote",
    [CK_IF_IN_OUTER_SPACE] = "ifinouterspace",
    [CK_IF_NOT_MOVING] = "ifnotmoving",
    [CK_RESPAWN_HITAG] = "respawnhitag",
    [CK_TIP] = "tip",
    [CK_IF_SPRITE_PAL] = "ifspritepal",
    [CK_MONEY] = "money",
    [CK_SOUND_ONCE] = "soundonce",
    [CK_ADD_KILLS] = "addkills",
    [CK_STOP_SOUND] = "stopsound",
    [CK_IF_AWAY_FROM_WALL] = "ifawayfromwall",
    [CK_IF_CAN_SEE_TARGET] = "ifcanseetarget",
    [CK_GLOBAL_SOUND] = "globalsound",
    [CK_LOTS_OF_GLASS] = "lotsofglass",
    [CK_IF_GOT_WEAPON_ONCE] = "ifgotweaponce",
    [CK_GET_LAST_PAL] = "getlastpal",
    [CK_PLAYER_KICK] = "pkick",
    [CK_MIKE_SOUND] = "mikesnd",
    [CK_USER_ACTOR] = "useractor",
    [CK_SIZE_AT] = "sizeat",
    [CK_ADD_STRENGTH] = "addstrength",
    [CK_SET_SPRITE_STAT_OR] = "cstator",
    [CK_MAIL] = "mail",
    [CK_PAPER] = "paper",
    [CK_TOSS_WEAPON] = "tossweapon",
    [CK_SLEEP_TIME] = "sleeptime",
    [CK_NULL_OP] = "nullop",
    [CK_DEFINE_VOL_NAME] = "definevolumename",
    [CK_DEFINE_SKILL_NAME] = "defineskillname",
    [CK_IF_NO_SOUNDS] = "ifnosounds",
    [CK_CLIP_DIST] = "clipdist",
    [CK_IF_ANGLE_DIFF_LT] = "ifangdiffl",
};


con_keyword_t CON_GetKeyword(const char* str) {
    for (i32 i = 0; i < NUM_KEYWORDS; i++) {
        if (SDL_strcmp(str, keyw[i]) == 0) {
            return i;
        }
    }
    return CK_NONE;
}

bool CON_IsKeyword(const char* str) {
    return CON_GetKeyword(str) != CK_NONE;
}

static void CON_LexKeywordError(const char* str) {
    if (str[0] == '{' && str[1] != 0) {
        CON_Error("Expecting a SPACE or CR between '{' and '%s'.\n", str + 1);
        return;
    }
    if (str[0] == '}' && str[1] != 0) {
        CON_Error("Expecting a SPACE or CR between '}' and '%s'.\n", str + 1);
        return;
    }
    if (str[0] == '/' && str[1] == '/' && str[2] != 0) {
        CON_Error("Expecting a SPACE between '//' and '%s'.\n", str + 2);
        return;
    }
    if (str[0] == '/' && str[1] == '*' && str[2] != 0) {
        CON_Error("Expecting a SPACE between '/*' and '%s'.\n", str + 2);
        return;
    }
    if (str[0] == '*' && str[1] == '/' && str[2] != 0) {
        CON_Error("Expecting a SPACE between '*/' and '%s'.\n", str + 2);
        return;
    }
    CON_Error("Expecting key word, but found '%s'.\n", str);
}

con_keyword_t CON_LexKeyword(con_compiler_t* ctx) {
    CON_SkipSpace(ctx);
    if (*ctx->cursor == 0) {
        return CK_NONE;
    }
    const char* str = CON_LexString(ctx);
    con_keyword_t keyword = CON_GetKeyword(str);
    if (keyword == CK_NONE) {
        CON_LexKeywordError(str);
        return CK_NONE;
    }
    *ctx->script_cursor = keyword;
    ctx->script_cursor++;
    return keyword;
}

i32 CON_PeekKeyword(const con_compiler_t* ctx) {
    const char* temptextptr = ctx->cursor;

    while (!CON_IsLetter(*temptextptr)) {
        temptextptr++;
        if (*temptextptr == 0) {
            return 0;
        }
    }

    i32 i = 0;
    while (CON_IsLetter(*temptextptr)) {
        tempbuf[i] = *(temptextptr++);
        i++;
    }
    tempbuf[i] = 0;

    return CON_GetKeyword((char*) tempbuf);
}