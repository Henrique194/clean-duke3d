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
#include "soundefs.h"

static void CON_AddSteroids(player_t* p, i16 amount) {
    p->steroids_amount = amount;
    p->inven_icon = 2;
}

static void CON_AddArmor(player_t* p, i16 amount) {
    p->shield_amount += amount; // 100;
    if (p->shield_amount > max_player_health) {
        p->shield_amount = (i16) max_player_health;
    }
}

static void CON_AddScuba(player_t* p, i16 amount) {
    p->scuba_amount = amount;
    p->inven_icon = 6;
}

static void CON_AddHoloDuke(player_t* p, i16 amount) {
    p->holoduke_amount = amount;
    p->inven_icon = 3;
}

static void CON_AddJetpack(player_t* p, i16 amount) {
    p->jetpack_amount = amount;
    p->inven_icon = 4;
}

static void CON_AddAccessCard(con_vm_t* vm) {
    player_t* p = vm->player;
    switch (vm->sprite->pal) {
        case 0:
            p->got_access |= 1;
            break;
        case 21:
            p->got_access |= 2;
            break;
        case 23:
            p->got_access |= 4;
            break;
        default:
            break;
    }
}

static void CON_AddNightVision(player_t* p, i16 amount) {
    p->heat_amount = amount;
    p->inven_icon = 5;
}

static void CON_AddMedkit(player_t* p, i16 amount) {
    p->inven_icon = 1;
    p->firstaid_amount = amount;
}

static void CON_AddBoots(player_t* p, i16 amount) {
    p->inven_icon = 7;
    p->boot_amount = amount;
}

void VM_AddInventory(con_vm_t* vm) {
    i32 item = VM_READ(vm);
    i16 amount = (i16) VM_READ(vm);
    player_t* plr = vm->player;
    switch (item) {
        case GET_STEROIDS:
            CON_AddSteroids(plr, amount);
            break;
        case GET_SHIELD:
            CON_AddArmor(plr, amount);
            break;
        case GET_SCUBA:
            CON_AddScuba(plr, amount);
            break;
        case GET_HOLODUKE:
            CON_AddHoloDuke(plr, amount);
            break;
        case GET_JETPACK:
            CON_AddJetpack(plr, amount);
            break;
        case GET_ACCESS:
            CON_AddAccessCard(vm);
            break;
        case GET_HEATS:
            CON_AddNightVision(plr, amount);
            break;
        case GET_FIRSTAID:
            CON_AddMedkit(plr, amount);
            break;
        case GET_BOOTS:
            CON_AddBoots(plr, amount);
            break;
        default:
            break;
    }
}


static void CON_IfAccessCard(con_vm_t* vm) {
    const player_t* plr = vm->player;
    switch (vm->sprite->pal) {
        case 0:
            VM_IfElse(vm, plr->got_access & 1);
            break;
        case 21:
            VM_IfElse(vm, plr->got_access & 2);
            break;
        case 23:
            VM_IfElse(vm, plr->got_access & 4);
            break;
        default:
            VM_IfElse(vm, false);
            break;
    }
}

void VM_IfPlrInventory(con_vm_t* vm) {
    i32 item = VM_READ(vm);
    i32 amount = VM_READ(vm);
    const player_t* plr = vm->player;
    switch (item) {
        case GET_STEROIDS:
            VM_IfElse(vm, plr->steroids_amount != amount);
            return;
        case GET_SHIELD:
            VM_IfElse(vm, plr->shield_amount != max_player_health);
            return;
        case GET_SCUBA:
            VM_IfElse(vm, plr->scuba_amount != amount);
            return;
        case GET_HOLODUKE:
            VM_IfElse(vm, plr->holoduke_amount != amount);
            return;
        case GET_JETPACK:
            VM_IfElse(vm, plr->jetpack_amount != amount);
            return;
        case GET_ACCESS:
            CON_IfAccessCard(vm);
            return;
        case GET_HEATS:
            VM_IfElse(vm, plr->heat_amount != amount);
            break;
        case GET_FIRSTAID:
            VM_IfElse(vm, plr->firstaid_amount != amount);
            break;
        case GET_BOOTS:
            VM_IfElse(vm, plr->boot_amount != amount);
            break;
        default:
            VM_IfElse(vm, false);
            break;
    }
}
