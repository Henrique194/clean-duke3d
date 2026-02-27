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
#include "types.h"

typedef enum {
    CK_NONE = -1,
    CK_DEF_LEVEL_NAME,
    CK_ACTOR,
    CK_ADD_AMMO,
    CK_IF_RND,
    CK_END_ACTOR,
    CK_IF_CAN_SEE,
    CK_IF_HIT_WEAPON,
    CK_ACTION,
    CK_IF_PLAYER_DIST_LT,
    CK_IF_PLAYER_DIST_GT,
    CK_ELSE,
    CK_STRENGTH,
    CK_BREAK,
    CK_SHOOT,
    CK_PAL_FROM,
    CK_SOUND,
    CK_FALL,
    CK_STATE,
    CK_ENDS,
    CK_DEFINE,
    CK_COMMENT,
    CK_IF_AI,
    CK_KILL_IT,
    CK_ADD_WEAPON,
    CK_AI,
    CK_ADD_PLAYER_HEALTH,
    CK_IF_DEAD,
    CK_IF_SQUISHED,
    CK_SIZE_TO,
    CK_LEFT_BRACE,
    CK_RIGHT_BRACE,
    CK_SPAWN,
    CK_MOVE,
    CK_IF_WAS_WEAPON,
    CK_IF_ACTION,
    CK_IF_ACTION_COUNT,
    CK_RESET_ACTION_COUNT,
    CK_DEBRIS,
    CK_PLAYER_STOMP,
    CK_BLOCK_COMMENT,
    CK_SET_SPRITE_STAT,
    CK_IF_MOVE,
    CK_RESET_PLAYER,
    CK_IF_ON_WATER,
    CK_IF_IN_WATER,
    CK_IF_CAN_SHOOT_TARGET,
    CK_IF_COUNT,
    CK_RESET_COUNT,
    CK_ADD_INVENTORY,
    CK_IF_ACTOR_NOT_STAYPUT,
    CK_HIT_RADIUS,
    CK_IF_PLAYER,
    CK_COUNT,
    CK_IF_ACTOR,
    CK_MUSIC,
    CK_INCLUDE,
    CK_IF_STRENGTH,
    CK_DEFINE_SOUND,
    CK_GUTS,
    CK_IF_SPAWNED_BY,
    CK_GAME_STARTUP,
    CK_WACK_PLAYER,
    CK_IF_GAP_Z_LT,
    CK_IF_HIT_SPACE,
    CK_IF_OUTSIDE,
    CK_IF_MULTIPLAYER,
    CK_OPERATE,
    CK_IF_IN_SPACE,
    CK_DEBUG,
    CK_END_OF_GAME,
    CK_IF_BULLET_NEAR,
    CK_IF_RESPAWN,
    CK_IF_FLOOR_DIST_LT,
    CK_IF_CEILING_DIST_LT,
    CK_SPRITE_PAL,
    CK_IF_PLAYER_INVENTORY,
    CK_BETA_NAME,
    CK_CHANGE_ACTOR,
    CK_IF_PLAYER_HEALTH_LT,
    CK_DEFINE_QUOTE,
    CK_QUOTE,
    CK_IF_IN_OUTER_SPACE,
    CK_IF_NOT_MOVING,
    CK_RESPAWN_HITAG,
    CK_TIP,
    CK_IF_SPRITE_PAL,
    CK_MONEY,
    CK_SOUND_ONCE,
    CK_ADD_KILLS,
    CK_STOP_SOUND,
    CK_IF_AWAY_FROM_WALL,
    CK_IF_CAN_SEE_TARGET,
    CK_GLOBAL_SOUND,
    CK_LOTS_OF_GLASS,
    CK_IF_GOT_WEAPON_ONCE,
    CK_GET_LAST_PAL,
    CK_PLAYER_KICK,
    CK_MIKE_SOUND,
    CK_USER_ACTOR,
    CK_SIZE_AT,
    CK_ADD_STRENGTH,
    CK_SET_SPRITE_STAT_OR,
    CK_MAIL,
    CK_PAPER,
    CK_TOSS_WEAPON,
    CK_SLEEP_TIME,
    CK_NULL_OP,
    CK_DEFINE_VOL_NAME,
    CK_DEFINE_SKILL_NAME,
    CK_IF_NO_SOUNDS,
    CK_CLIP_DIST,
    CK_IF_ANGLE_DIFF_LT,
    NUM_KEYWORDS,
} con_keyword_t;


con_keyword_t COM_GetKeyword(const char* str);

bool COM_IsKeyword(const char* str);

con_keyword_t COM_LexKeyword(con_compiler_t* ctx);

i32 COM_PeekKeyword(const con_compiler_t* ctx);
