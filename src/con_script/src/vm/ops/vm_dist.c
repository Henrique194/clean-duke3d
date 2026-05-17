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

void VM_IfPlrDistLt(con_vm_t* vm) {
    i32 dist = VM_READ(vm);
    VM_IfElse(vm, vm->player_dist < dist);
    if (vm->player_dist > MAXSLEEPDIST && !vm->sprite_hit->timetosleep) {
        vm->sprite_hit->timetosleep = SLEEPTIME;
    }
}

void VM_IfPlrDistGt(con_vm_t* vm) {
    i32 dist = VM_READ(vm);
    VM_IfElse(vm, vm->player_dist > dist);
    if (vm->player_dist > MAXSLEEPDIST && !vm->sprite_hit->timetosleep) {
        vm->sprite_hit->timetosleep = SLEEPTIME;
    }
}

void VM_ClipDist(con_vm_t* vm) {
    vm->sprite->clipdist = (u8) VM_READ(vm);
}

void VM_IfFloorDistLt(con_vm_t* vm) {
    i32 val = VM_READ(vm);
    VM_IfElse(vm, (hittype[vm->sprite_idx].floorz - vm->sprite->z) <= (val << 8));
}

void VM_IfCeilingDistLt(con_vm_t* vm) {
    i32 val = VM_READ(vm);
    VM_IfElse(vm, (vm->sprite->z - hittype[vm->sprite_idx].ceilingz) <= (val << 8));
}

void VM_IfGapZLt(con_vm_t* vm) {
    i32 val = VM_READ(vm);
    const weapon_hit_t* hit = vm->sprite_hit;
    i32 gap = hit->floorz - hit->ceilingz;
    VM_IfElse(vm, (gap >> 8) < val);
}
