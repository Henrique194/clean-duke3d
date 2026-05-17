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

#include "vm_ops.h"
#include "names.h"
#include "funct.h"

void VM_Spawn(con_vm_t* vm) {
    i16 actor = (i16) VM_READ(vm);
    const spritetype* spr = vm->sprite;
    if (spr->sectnum >= 0 && spr->sectnum < MAXSECTORS) {
        spawn(vm->sprite_idx, actor);
    }
}


void VM_IfSpawnedBy(con_vm_t* vm) {
    i32 actor = VM_READ(vm);
    VM_IfElse(vm, vm->sprite_hit->picnum == actor);
}


void VM_IfRespawn(con_vm_t* vm) {
    if (badguy(vm->sprite)) {
        VM_IfElse(vm, ud.respawn_monsters);
        return;
    }
    if (inventory(vm->sprite)) {
        VM_IfElse(vm, ud.respawn_inventory);
        return;
    }
    VM_IfElse(vm, ud.respawn_items);
}


void VM_RespawnHiTag(con_vm_t* vm) {
    const spritetype* spr = vm->sprite;
    switch (spr->picnum) {
        case FEM1:
        case FEM2:
        case FEM3:
        case FEM4:
        case FEM5:
        case FEM6:
        case FEM7:
        case FEM8:
        case FEM9:
        case FEM10:
        case PODFEM1:
        case NAKED1:
        case STATUE:
            if (spr->yvel) {
                P_OperateRespawns(spr->yvel);
            }
            break;
        default:
            if (spr->hitag >= 0) {
                P_OperateRespawns(spr->hitag);
            }
            break;
    }
}
