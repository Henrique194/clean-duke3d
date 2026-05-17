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

#include "con_cmds.h"
#include "con_keyword.h"
#include "con_misc.h"
#include "duke3d.h"

void CON_GameStartup(con_compiler_t* ctx) {
    i32 params[30];

    ctx->script_cursor--;
    for (i32 j = 0; j < 30; j++) {
        CON_LexNum(ctx);
        ctx->script_cursor--;
        params[j] = *ctx->script_cursor;
        if (j != 25) {
            continue;
        }
        // We try to guess if we are using 1.3/1.3d or 1.4/1.5 con files.
        if (CON_PeekKeyword(ctx) != -1) {
            // Is the 26th variable set?
            // If so then it's probably a 1.4/1.5 con file
            break;
        }
        conVersion = 15;
    }

    i32 j = 0;

    ud.const_visibility = params[j++];
    impact_damage = params[j++];
    max_player_health = params[j++];
    max_armour_amount = params[j++];
    respawnactortime = params[j++];
    respawnitemtime = params[j++];
    dukefriction = params[j++];
    if (conVersion == 15) {
        gc = params[j++];
    } else {
        // default (guess) when using 1.3d CONs
        gc = 176;
    }
    rpgblastradius = params[j++];
    pipebombblastradius = params[j++];
    shrinkerblastradius = params[j++];
    tripbombblastradius = params[j++];
    morterblastradius = params[j++];
    bouncemineblastradius = params[j++];
    seenineblastradius = params[j++];
    max_ammo_amount[PISTOL_WEAPON] = params[j++];
    max_ammo_amount[SHOTGUN_WEAPON] = params[j++];
    max_ammo_amount[CHAINGUN_WEAPON] = params[j++];
    max_ammo_amount[RPG_WEAPON] = params[j++];
    max_ammo_amount[HANDBOMB_WEAPON] = params[j++];
    max_ammo_amount[SHRINKER_WEAPON] = params[j++];
    max_ammo_amount[DEVISTATOR_WEAPON] = params[j++];
    max_ammo_amount[TRIPBOMB_WEAPON] = params[j++];
    max_ammo_amount[FREEZE_WEAPON] = params[j++];
    if (conVersion == 15) {
        max_ammo_amount[GROW_WEAPON] = params[j++];
    } else {
        // default (guess) when using 1.3d CONs
        max_ammo_amount[GROW_WEAPON] = 50;
    }
    camerashitable = params[j++];
    numfreezebounces = params[j++];
    freezerhurtowner = params[j++];
    if (conVersion != 15) {
        // spriteqamount = 64 is the default
        // default (guess) when using 1.3d CONs
        lasermode = 0;
        return;
    }
    spriteqamount = params[j++];
    if (spriteqamount > 1024) {
        spriteqamount = 1024;
    } else if (spriteqamount < 0) {
        spriteqamount = 0;
    }
    lasermode = params[j++];
}
