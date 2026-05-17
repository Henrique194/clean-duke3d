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

#include "vm_main.h"
#include "ops/vm_ops.h"
#include "con_keyword.h"

typedef void (*con_operation_t)(con_vm_t* vm);

static con_operation_t ops[NUM_KEYWORDS] = {
    [CK_ADD_AMMO] = VM_AddAmmo,
    [CK_IF_RND] = VM_IfRnd,
    [CK_END_ACTOR] = VM_NullOp,
    [CK_IF_CAN_SEE] = VM_IfCanSee,
    [CK_IF_HIT_WEAPON] = VM_IfHitWeapon,
    [CK_ACTION] = VM_Action,
    [CK_IF_PLAYER_DIST_LT] = VM_IfPlrDistLt,
    [CK_IF_PLAYER_DIST_GT] = VM_IfPlrDistGt,
    [CK_ELSE] = VM_Else,
    [CK_STRENGTH] = VM_Strength,
    [CK_BREAK] = VM_NullOp,
    [CK_SHOOT] = VM_Shoot,
    [CK_PAL_FROM] = VM_PalFrom,
    [CK_SOUND] = VM_Sound,
    [CK_FALL] = VM_Fall,
    [CK_STATE] = VM_State,
    [CK_ENDS] = VM_NullOp,
    [CK_IF_AI] = VM_IfAI,
    [CK_KILL_IT] = VM_KillIt,
    [CK_ADD_WEAPON] = VM_AddWeapon,
    [CK_AI] = VM_AI,
    [CK_ADD_PLAYER_HEALTH] = VM_AddPlrHealth,
    [CK_IF_DEAD] = VM_IfDead,
    [CK_IF_SQUISHED] = VM_IfSquished,
    [CK_SIZE_TO] = VM_SizeTo,
    [CK_LEFT_BRACE] = VM_LeftBrace,
    [CK_RIGHT_BRACE] = VM_NullOp,
    [CK_SPAWN] = VM_Spawn,
    [CK_MOVE] = VM_Move,
    [CK_IF_WAS_WEAPON] = VM_IfWasWeapon,
    [CK_IF_ACTION] = VM_IfAction,
    [CK_IF_ACTION_COUNT] = VM_IfActionCount,
    [CK_RESET_ACTION_COUNT] = VM_ResetActionCount,
    [CK_DEBRIS] = VM_Debris,
    [CK_PLAYER_STOMP] = VM_PlrStomp,
    [CK_SET_SPRITE_STAT] = VM_SetSpriteStat,
    [CK_IF_MOVE] = VM_IfMove,
    [CK_RESET_PLAYER] = VM_ResetPlayer,
    [CK_IF_ON_WATER] = VM_IfOnWater,
    [CK_IF_IN_WATER] = VM_IfInWater,
    [CK_IF_CAN_SHOOT_TARGET] = VM_IfCanShootTarget,
    [CK_IF_COUNT] = VM_IfCount,
    [CK_RESET_COUNT] = VM_ResetCount,
    [CK_ADD_INVENTORY] = VM_AddInventory,
    [CK_IF_ACTOR_NOT_STAYPUT] = VM_IfActorNotStayPut,
    [CK_HIT_RADIUS] = VM_HitRadius,
    [CK_IF_PLAYER] = VM_IfPlr,
    [CK_COUNT] = VM_Count,
    [CK_IF_ACTOR] = VM_IfActor,
    [CK_IF_STRENGTH] = VM_IfStrength,
    [CK_GUTS] = VM_Guts,
    [CK_IF_SPAWNED_BY] = VM_IfSpawnedBy,
    [CK_WACK_PLAYER] = VM_WackPlayer,
    [CK_IF_GAP_Z_LT] = VM_IfGapZLt,
    [CK_IF_HIT_SPACE] = VM_IfHitSpace,
    [CK_IF_OUTSIDE] = VM_IfOutside,
    [CK_IF_MULTIPLAYER] = VM_IfMultiplayer,
    [CK_OPERATE] = VM_Operate,
    [CK_IF_IN_SPACE] = VM_IfInSpace,
    [CK_DEBUG] = VM_Debug,
    [CK_END_OF_GAME] = VM_EndOfGame,
    [CK_IF_BULLET_NEAR] = VM_IfBulletNear,
    [CK_IF_RESPAWN] = VM_IfRespawn,
    [CK_IF_FLOOR_DIST_LT] = VM_IfFloorDistLt,
    [CK_IF_CEILING_DIST_LT] = VM_IfCeilingDistLt,
    [CK_SPRITE_PAL] = VM_SpritePal,
    [CK_IF_PLAYER_INVENTORY] = VM_IfPlrInventory,
    [CK_CHANGE_ACTOR] = VM_ChangeActor,
    [CK_IF_PLAYER_HEALTH_LT] = VM_IfPlrHealthLt,
    [CK_QUOTE] = VM_Quote,
    [CK_IF_IN_OUTER_SPACE] = VM_IfInOuterSpace,
    [CK_IF_NOT_MOVING] = VM_IfNotMoving,
    [CK_RESPAWN_HITAG] = VM_RespawnHiTag,
    [CK_TIP] = VM_Tip,
    [CK_IF_SPRITE_PAL] = VM_IfSpritePal,
    [CK_MONEY] = VM_Money,
    [CK_SOUND_ONCE] = VM_SoundOnce,
    [CK_ADD_KILLS] = VM_AddKills,
    [CK_STOP_SOUND] = VM_StopSound,
    [CK_IF_AWAY_FROM_WALL] = VM_IfAwayFromWall,
    [CK_IF_CAN_SEE_TARGET] = VM_IfCanSeeTarget,
    [CK_GLOBAL_SOUND] = VM_GlobalSound,
    [CK_LOTS_OF_GLASS] = VM_LotsOfGlass,
    [CK_IF_GOT_WEAPON_ONCE] = VM_IfGotWeaponOnce,
    [CK_GET_LAST_PAL] = VM_GetLastPal,
    [CK_PLAYER_KICK] = VM_PlrKick,
    [CK_MIKE_SOUND] = VM_MikeSound,
    [CK_SIZE_AT] = VM_SizeAt,
    [CK_ADD_STRENGTH] = VM_AddStrength,
    [CK_SET_SPRITE_STAT_OR] = VM_SetSpriteStatOr,
    [CK_MAIL] = VM_Mail,
    [CK_PAPER] = VM_Paper,
    [CK_TOSS_WEAPON] = VM_TossWeapon,
    [CK_SLEEP_TIME] = VM_SleepTime,
    [CK_NULL_OP] = VM_NullOp,
    [CK_IF_NO_SOUNDS] = VM_IfNoSounds,
    [CK_CLIP_DIST] = VM_ClipDist,
    [CK_IF_ANGLE_DIFF_LT] = VM_IfAngDiffLt,
};


static bool VM_ExecuteOp(con_vm_t* vm, i32 opcode) {
    con_operation_t op = ops[opcode];
    if (op) {
        op(vm);
        return true;
    }
    return false;
}

bool parse(con_vm_t* vm) {
    if (vm->killit_flag) {
        return true;
    }
    i32 opcode = VM_READ(vm);
    if (!VM_ExecuteOp(vm, opcode)) {
        vm->killit_flag = 1;
        return false;
    }
    switch (opcode) {
        case CK_END_ACTOR:
        case CK_BREAK:
        case CK_ENDS:
            vm->ip--;
            return true;
        case CK_RIGHT_BRACE:
            return true;
        default:
            return false;
    }
}
