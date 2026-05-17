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

void VM_Action(con_vm_t* vm) {
    i32 action_offset = VM_READ(vm);
    actor_state_t* actor = vm->actor;
    actor->action_count = 0;
    actor->anim_offset = 0;
    // FIX_00093:
    //   Fixed crashbugs in multiplayer (mine/blimp)
    //   This is the blimp bug.
    //   *.con code 1.3 and 1.4 are buggy when you try to blow up the
    //   blimp in multiplayer. duke3d_w32 /q2 /m /v3 /l9
    //   This is because the con code gives a timeout value of 2048
    //   as an action address instead of giving a real action address.
    //   We simply counter this specific con code bug by resetting
    //   the action address to 0 when we get an address "2048":
    actor->action_script = (action_offset == 2048) ? 0 : action_offset;
}

void VM_IfAction(con_vm_t* vm) {
    i32 action_script = VM_READ(vm);
    bool running_action = (vm->actor->action_script == action_script);
    VM_IfElse(vm, running_action);
}

void VM_ResetActionCount(con_vm_t* vm) {
    vm->actor->action_count = 0;
}

void VM_IfActionCount(con_vm_t* vm) {
    i32 count = VM_READ(vm);
    VM_IfElse(vm, vm->actor->action_count >= count);
}
