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

#pragma once

#include "types.h"

//
// Moves any object (x, y, z) in any direction at any velocity
// and will make sure the object will stay a certain distance
// from walls (walldist).
//
// - (x, y, y):
//     Pointers of the starting position.
// - sectnum:
//     Starting position's sector number.
// - (xvect, yvect):
//     Vector indicating direction and velocity.
// - walldist:
//     How close the object can get to a wall. If you increase
//     walldist all of a sudden for a certain object, the object
//     might leak through a wall.
// - cliptype:
//     Mask that tells whether the object should be clipped to
//     or not. The lower 16 bits are anded with wall[].cstat
//     and the higher 16 bits are anded with sprite[].cstat.
//
// Returns:
//   0 (touched nothing)
//   32768+wallnum (wall first touched)
//   49152+spritenum (sprite first touched)
//
int PHYS_ClipMove(
    i32* x,
    i32* y,
    i32* z,
    short* sectnum,
    i32 xvect,
    i32 yvect,
    i32 walldist,
    i32 ceildist,
    i32 flordist,
    u32 cliptype
);

//
// This function makes sure a player or monster (defined by x, y, z, sectnum)
// is not too close to a wall. If it is, then it attempts to push it away.
// If after 256 tries, it is unable to push it away, it returns -1, in which
// case the thing should gib.
//
int PHYS_PushMove(
    i32* x,
    i32* y,
    i32* z,
    short* sectnum,
    i32 walldist,
    i32 ceildist,
    i32 flordist,
    u32 cliptype
);

//
// This function will keep the player from falling off cliffs when
// you're too close to the edge. This function finds the highest and
// lowest z coordinates that your clipping BOX can get to. It must
// search for all sectors (and sprites) that go into your clipping box.
//
// This method is better than using sector[cursectnum].ceilingz and
// sector[cursectnum].floorz because this searches the whole clipping
// box for objects, not just 1 point.
//
// - (x, y, y):
//     Starting position.
// - sectnum:
//     Starting position's sector number.
// - walldist:
//     How close the object can get to a wall.
// - cliptype:
//     Mask that tells whether the object should be clipped to
//     or not. The lower 16 bits are anded with wall[].cstat
//     and the higher 16 bits are anded with sprite[].cstat.
//
// Returns the z extents in ceilz and florz.
// It will return the object hit in ceilhit and florhit.
// Ceilhit and florhit will also be either:
//   16384+sector (sector first touched) or
//   49152+spritenum (sprite first touched)
//
void PHYS_GetZRange(
    i32 x,
    i32 y,
    i32 z,
    short sectnum,
    i32* ceilz,
    i32* ceilhit,
    i32* florz,
    i32* florhit,
    i32 walldist,
    u32 cliptype
);

//
// - (xstart, ystart, zstart, startsectnum):
//     Pass the starting 3D position.
// - (vectorx, vectory, vectorz):
//     Then pass the 3D angle to shoot (defined as a 3D vector).
// - (hitsect, hitwall, hitsprite):
//     Then return values for the object hit.
// - (hitx, hity, hitz):
//     The exact 3D point where the ray hits.
//
// How to determine what was hit:
// - Hitsect is always equal to the sector that was hit (always >= 0).
// - If the ray hits a sprite then:
//     hitsect = thesectornumber
//     hitsprite = thespritenumber
//     hitwall = -1
// - If the ray hits a wall then:
//     hitsect = thesectornumber
//     hitsprite = -1
//     hitwall = thewallnumber
// - If the ray hits the ceiling of a sector then:
//     hitsect = thesectornumber
//     hitsprite = -1
//     hitwall = -1
//     vectorz < 0
//       (If vectorz < 0 then you're shooting upward which means
//        that you couldn't have hit a floor)
// - If the ray hits the floor of a sector then:
//     hitsect = thesectornumber
//     hitsprite = -1
//     hitwall = -1
//     vectorz > 0
//       (If vectorz > 0 then you're shooting downard which means
//        that you couldn't have hit a ceiling)
//
int PHYS_Hitscan(
    i32 xs,
    i32 ys,
    i32 zs,
    short sectnum,
    i32 vx,
    i32 vy,
    i32 vz,
    short* hitsect,
    short* hitwall,
    short* hitsprite,
    i32* hitx,
    i32* hity,
    i32* hitz,
    u32 cliptype
);

//
// Works sort of like hitscan, but is optimized to scan only
// close objects and scan only objects with tags != 0. Neartag is
// perfect for the first line of your space bar code. It will tell
// you what door you want to open or what switch you want to flip.
//
// - (x, y, y):
//     Starting position.
// - sectnum:
//     Starting position's sector number.
// - ange:
//     Starting angle.
// - neartagsector:
//     Returns near sector if sector[].tag != 0.
// - neartagwall:
//     Returns near wall if wall[].tag != 0.
// - neartagsprite:
//     Returns near sprite if sprite[].tag != 0.
// - neartaghitdist:
//     Returns actual distance to object (scale: 1024=largest grid size).
// - neartagrange:
//     Choose maximum distance to scan (scale: 1024=largest grid size).
// - tagsearch:
//     1-lotag only, 2-hitag only, 3-lotag&hitag.
//
int PHYS_NearTag(
    i32 xs,
    i32 ys,
    i32 zs,
    short sectnum,
    short ange,
    short* neartagsector,
    short* neartagwall,
    short* neartagsprite,
    i32* neartaghitdist,
    i32 neartagrange,
    u8 tagsearch
);

//
// This function determines whether two 3D points can "see" each
// other or not. All you do is pass it the coordinates of a 3D line
// defined by two 3D points (with their respective sectors).
// The function will return a 1 if the points can see each other or
// a 0 if there is something blocking the two points from seeing each
// other. This is how I determine whether a monster can see you or not.
// Try playing DOOM1.DAT to fully enjoy this great function!
//
int PHYS_CanSee(
    i32 x1,
    i32 y1,
    i32 z1,
    short sect1,
    i32 x2,
    i32 y2,
    i32 z2,
    short sect2
);

//
// This function updates the sector number according to the
// x and y values passed to it. Be careful when you use this
// function with sprites because remember that the sprite's
// sector number should not be modified directly. If you want
// to update a sprite's sector, I recomment using the
// B_SetSprite function.
//
void PHYS_UpdateSector(i32 x, i32 y, short* lastKnownSector);

//
// Tests to see whether the overhead point (x, y) is inside
// sector (sectnum). Returns either 0 or 1, where 1 means it
// is inside, and 0 means it is not.
//
int PHYS_Inside(i32 x, i32 y, short sectnum);

//
// Returns true only if the given line (wallnum) intersects
// the square with center (x,y) and radius, walldist.
//
int PHYS_ClipInsideBox(i32 x, i32 y, short wallnum, i32 walldist);

//
// This function will drag a point in the exact same way a point
// is dragged in 2D EDIT MODE using the left mouse button.
// Simply pass it which wall to drag and then pass the new x and y
// coordinates for that point.
//
// Note: Every wall of course has 2 points. When you pass a wall number
// to this function, you are actually passing 1 point, the left side of
// the wall (given that you are in the sector of that wall).
//
void PHYS_DragPoint(short pointhighlight, i32 dax, i32 day);
