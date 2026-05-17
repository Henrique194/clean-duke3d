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
#include "player.h"
#include "actors/actors.h"

void VM_AddWeapon(con_vm_t* vm) {
    i16 weapon = (i16) VM_READ(vm);
    i16 ammo = (i16) VM_READ(vm);
    player_t* plr = vm->player;
    if (!plr->gotweapon[weapon]) {
        P_AddWeapon(plr, weapon);
    } else if (plr->ammo_amount[weapon] >= max_ammo_amount[weapon]) {
        vm->killit_flag = 2;
        return;
    }
    P_AddAmmo(weapon, plr, ammo);
    if (plr->curr_weapon == KNEE_WEAPON && plr->gotweapon[weapon]) {
        P_AddWeapon(plr, weapon);
    }
}

void VM_AddAmmo(con_vm_t* vm) {
    i16 weapon = (i16) VM_READ(vm);
    i16 amount = (i16) VM_READ(vm);
    player_t* plr = vm->player;
    if (plr->ammo_amount[weapon] >= max_ammo_amount[weapon]) {
        vm->killit_flag = 2;
        return;
    }
    P_AddAmmo(weapon, plr, amount);
    if (plr->curr_weapon == KNEE_WEAPON && plr->gotweapon[weapon]) {
        P_AddWeapon(plr, weapon);
    }
}

void VM_IfGotWeaponOnce(con_vm_t* vm) {
    i32 val = VM_READ(vm);
    if (ud.coop < 1 || ud.multimode < 2) {
        // Test always fails in single player mode.
        VM_IfElse(vm, false);
        return;
    }
    player_t* plr = vm->player;
    const spritetype* spr = vm->sprite;
    bool got_weapon = (spr->owner == vm->sprite_idx);
    if (val != 0) {
        if (plr->weapreccnt >= 16) {
            VM_IfElse(vm, false);
            return;
        }
        plr->weaprecs[plr->weapreccnt] = spr->picnum;
        plr->weapreccnt++;
        VM_IfElse(vm, got_weapon);
        return;
    }
    for (i32 i = 0; i < plr->weapreccnt; i++) {
        if (plr->weaprecs[i] == spr->picnum) {
            VM_IfElse(vm, got_weapon);
            return;
        }
    }
    VM_IfElse(vm, false);
}

void VM_IfHitWeapon(con_vm_t* vm) {
    bool was_hit = P_IfHitByWeapon(vm->sprite_idx) >= 0;
    VM_IfElse(vm, was_hit);
}

void VM_IfWasWeapon(con_vm_t* vm) {
    i32 weapon = VM_READ(vm);
    bool was_hit = (vm->sprite_hit->picnum == weapon);
    VM_IfElse(vm, was_hit);
}

void VM_TossWeapon(con_vm_t* vm) {
    P_CheckWeapons(&ps[vm->sprite->yvel]);
}
