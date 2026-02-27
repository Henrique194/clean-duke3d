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

#include "duke3d.h"
#include "types.h"

//
// Reads next instruction and advances IP.
//
#define VM_READ(vm) (*(vm)->ip++)

typedef struct {
    // Actor's local counter.
    i32 count;
    // Movement script pointer.
    i32 move_script;
    // The number of frames that have displayed from the current action.
    i32 action_count;
    // Offset used to animate the sprite.
    i32 anim_offset;
    // Action script pointer.
    i32 action_script;
    // AI script pointer.
    i32 ai_script;
} actor_state_t;

typedef struct {
    // Instruction Pointer.
    i32* ip;

    i16 sprite_idx;
    spritetype* sprite;
    weapon_hit_t* sprite_hit;

    i16 player_idx;
    player_t* player;

    // VM execution state of the current actor.
    actor_state_t* actor;
    // Distance from the current actor to the player.
    i32 player_dist;
    // Flag indicating whether the current actor should be destroyed.
    u8 killit_flag;
} con_vm_t;

bool VM_Dodge(spritetype* spr);

void move(con_vm_t* vm);

bool parse(con_vm_t* vm);
