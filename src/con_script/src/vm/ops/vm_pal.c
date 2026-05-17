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

void VM_GetLastPal(con_vm_t* vm) {
    spritetype* spr = vm->sprite;
    weapon_hit_t* spr_hit = vm->sprite_hit;
    if (spr->picnum == APLAYER) {
        spr->pal = ps[spr->yvel].palookup;
    } else {
        spr->pal = (u8) spr_hit->tempang;
    }
    spr_hit->tempang = 0;
}

void VM_SpritePal(con_vm_t* vm) {
    spritetype* spr = vm->sprite;
    if (spr->picnum != APLAYER) {
        hittype[vm->sprite_idx].tempang = spr->pal;
    }
    spr->pal = (u8) VM_READ(vm);
}

void VM_PalFrom(con_vm_t* vm) {
    vm->player->pals_time = VM_READ(vm);
    for (i32 i = 0; i < 3; i++) {
        vm->player->pals[i] = (u8) VM_READ(vm);
    }
}

void VM_IfSpritePal(con_vm_t* vm) {
    i32 pal = VM_READ(vm);
    VM_IfElse(vm, vm->sprite->pal == pal);
}
