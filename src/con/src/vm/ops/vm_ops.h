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

#include "vm_main.h"

void VM_NullOp(con_vm_t* vm);

void VM_LeftBrace(con_vm_t* vm);

void VM_IfRnd(con_vm_t* vm);

void VM_IfCanShootTarget(con_vm_t* vm);

void VM_IfCanSeeTarget(con_vm_t* vm);

void VM_IfActorNotStayPut(con_vm_t* vm);

void VM_IfCanSee(con_vm_t* vm);

void VM_IfHitWeapon(con_vm_t* vm);

void VM_IfSquished(con_vm_t* vm);

void VM_IfDead(con_vm_t* vm);

void VM_AI(con_vm_t* vm);

void VM_Action(con_vm_t* vm);

void VM_IfPlrDistLt(con_vm_t* vm);

void VM_IfPlrDistGt(con_vm_t* vm);

void VM_IfElse(con_vm_t* vm, bool condition);

void VM_Else(con_vm_t* vm);

void VM_AddStrength(con_vm_t* vm);

void VM_Strength(con_vm_t* vm);

void VM_IfGotWeaponOnce(con_vm_t* vm);

void VM_GetLastPal(con_vm_t* vm);

void VM_TossWeapon(con_vm_t* vm);

void VM_MikeSound(con_vm_t* vm);

void VM_PlrKick(con_vm_t* vm);

void VM_SizeTo(con_vm_t* vm);

void VM_SizeAt(con_vm_t* vm);

void VM_Shoot(con_vm_t* vm);

void VM_SoundOnce(con_vm_t* vm);

void VM_StopSound(con_vm_t* vm);

void VM_GlobalSound(con_vm_t* vm);

void VM_Sound(con_vm_t* vm);

void VM_Tip(con_vm_t* vm);

void VM_Fall(con_vm_t* vm);

void VM_AddAmmo(con_vm_t* vm);

void VM_Money(con_vm_t* vm);

void VM_Mail(con_vm_t* vm);

void VM_SleepTime(con_vm_t* vm);

void VM_Paper(con_vm_t* vm);

void VM_AddKills(con_vm_t* vm);

void VM_LotsOfGlass(con_vm_t* vm);

void VM_KillIt(con_vm_t* vm);

void VM_AddWeapon(con_vm_t* vm);

void VM_Debug(con_vm_t* vm);

void VM_EndOfGame(con_vm_t* vm);

void VM_AddPlrHealth(con_vm_t* vm);

void VM_State(con_vm_t* vm);

void VM_Move(con_vm_t* vm);

void VM_Spawn(con_vm_t* vm);

void VM_IfWasWeapon(con_vm_t* vm);

void VM_IfAI(con_vm_t* vm);

void VM_IfAction(con_vm_t* vm);

void VM_IfActionCount(con_vm_t* vm);

void VM_ResetActionCount(con_vm_t* vm);

void VM_Debris(con_vm_t* vm);

void VM_Count(con_vm_t* vm);

void VM_SetSpriteStat(con_vm_t* vm);

void VM_SetSpriteStatOr(con_vm_t* vm);

void VM_ClipDist(con_vm_t* vm);

void VM_IfMove(con_vm_t* vm);

void VM_ResetPlayer(con_vm_t* vm);

void VM_IfOnWater(con_vm_t* vm);

void VM_IfInWater(con_vm_t* vm);

void VM_IfCount(con_vm_t* vm);

void VM_IfActor(con_vm_t* vm);

void VM_ResetCount(con_vm_t* vm);

void VM_AddInventory(con_vm_t* vm);

void VM_HitRadius(con_vm_t* vm);

void VM_IfPlr(con_vm_t* vm);

void VM_IfStrength(con_vm_t* vm);

void VM_Guts(con_vm_t* vm);

void VM_IfSpawnedBy(con_vm_t* vm);

void VM_WackPlayer(con_vm_t* vm);

void VM_IfGapZLt(con_vm_t* vm);

void VM_IfHitSpace(con_vm_t* vm);

void VM_IfOutside(con_vm_t* vm);

void VM_IfMultiplayer(con_vm_t* vm);

void VM_Operate(con_vm_t* vm);

void VM_IfInSpace(con_vm_t* vm);

void VM_SpritePal(con_vm_t* vm);

void VM_ChangeActor(con_vm_t* vm);

void VM_IfBulletNear(con_vm_t* vm);

void VM_IfRespawn(con_vm_t* vm);

void VM_IfFloorDistLt(con_vm_t* vm);

void VM_IfCeilingDistLt(con_vm_t* vm);

void VM_PalFrom(con_vm_t* vm);

void VM_IfPlrHealthLt(con_vm_t* vm);

void VM_IfPlrInventory(con_vm_t* vm);

void VM_PlrStomp(con_vm_t* vm);

void VM_IfAwayFromWall(con_vm_t* vm);

void VM_Quote(con_vm_t* vm);

void VM_IfInOuterSpace(con_vm_t* vm);

void VM_IfNotMoving(con_vm_t* vm);

void VM_RespawnHiTag(con_vm_t* vm);

void VM_IfSpritePal(con_vm_t* vm);

void VM_IfAngDiffLt(con_vm_t* vm);

void VM_IfNoSounds(con_vm_t* vm);
