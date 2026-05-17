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

void VM_Sound(con_vm_t* vm) {
    i16 sound = (i16) VM_READ(vm);
    spritesound(sound, vm->sprite_idx);
}

void VM_StopSound(con_vm_t* vm) {
    i16 sound = (i16) VM_READ(vm);
    if (Sound[sound].num > 0) {
        stopsound(sound);
    }
}

void VM_SoundOnce(con_vm_t* vm) {
    i16 sound = (i16) VM_READ(vm);
    if (Sound[sound].num == 0) {
        spritesound(sound, vm->sprite_idx);
    }
}

void VM_GlobalSound(con_vm_t* vm) {
    i16 sound = (i16) VM_READ(vm);
    if (vm->player_idx == screenpeek || ud.coop == 1) {
        spritesound(sound, ps[screenpeek].i);
    }
}

void VM_MikeSound(con_vm_t* vm) {
    const spritetype* spr = vm->sprite;
    if (Sound[spr->yvel].num == 0) {
        spritesound(spr->yvel, vm->sprite_idx);
    }
}

void VM_IfNoSounds(con_vm_t* vm) {
    for (i32 j = 1; j < NUM_SOUNDS; j++) {
        if (SoundOwner[j][0].i == vm->sprite_idx) {
            VM_IfElse(vm, false);
            return;
        }
    }
    VM_IfElse(vm, true);
}
