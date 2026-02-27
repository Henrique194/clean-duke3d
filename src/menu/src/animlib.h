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

/////////////////////////////////////////////////////////////////////////////
//
//      ANIMLIB.H
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

//
// Structure declarations for deluxe animate large page files.
//
typedef struct {
    // 4 character ID == "LPF "
    uint32 id;
    // Max number of largePages allowed. 256 FOR NOW.
    uint16 maxLps;
    // Number of largePages in this file.
    uint16 nLps;
    // Number of records in this file. 65534 is current limit plus
    // one for last-to-first delta for looping the animation.
    uint32 nRecords;
    // Number of records permitted in an lp. 256 FOR NOW.
    uint16 maxRecsPerLp;
    // Absolute Seek position of lpfTable. 1280 FOR NOW.
    // The lpf Table is an array of 256 large page structures
    // that is used to facilitate finding records in an anim
    // file without having to seek through all the Large
    // Pages to find which one a specific record lives in.
    uint16 lpfTableOffset;
    // 4 character ID == "ANIM".
    uint32 contentType;
    // Width of screen in pixels.
    uint16 width;
    // Height of screen in pixels.
    uint16 height;
    // 0 == ANIM.
    byte variant;
    // 0 == frame rate is multiple of 18 cycles/sec.
    // 1 == frame rate is multiple of 70 cycles/sec.
    byte version;
    // 1 == Last record is a delta from last-to-first frame.
    byte hasLastDelta;
    // 0 == The last-to-first delta (if present) hasn't been
    // updated to match the current first&last frames, so it
    // should be ignored.
    byte lastDeltaValid;
    // 0 == 256 color.
    byte pixelType;
    // 1 == (RunSkipDump) Only one used FOR NOW.
    byte CompressionType;
    // 0 FOR NOW.
    byte otherRecsPerFrm;
    // 1 == 320x200, 256-color. Only one implemented so far.
    byte bitmaptype;
    // Not yet implemented.
    byte recordTypes[32];
    // In case future version adds other records at end of
    // file, we still know how many actual frames.
    // NOTE: DOES include last-to-first delta when present.
    uint32 nFrames;
    // Number of frames to play per second.
    uint16 framesPerSecond;
    // 58 bytes of filler to round up to 128 bytes total.
    uint16 pad2[29];
} lpfileheader;

//
// This is the format of a large page structure.
//
typedef struct {
    // Number of first record in this large page.
    uint16 baseRecord;
    // Number of records in lp.
    // bit 15 of "nRecords" == "has continuation from previous lp".
    // bit 14 of "nRecords" == "final record continues on next lp".
    uint16 nRecords;
    // Total number of bytes of contents, excluding header.
    uint16 nBytes;
} lp_descriptor;

typedef struct {
    // current frame of anim
    uint16 framecount;
    // file header will be loaded into this structure
    lpfileheader lpheader;
    // arrays of large page structs used to find frames
    lp_descriptor LpArray[256];
    // initialize to an invalid Large page number
    uint16 curlpnum;
    // header of large page currently in memory
    lp_descriptor curlp;
    // buffer where current large page is loaded
    uint16 thepage[0x8000];
    // buffer where anim frame is decoded
    byte imagebuffer[0x10000];
    byte* buffer;
    byte pal[768];
    int32 currentframe;
} anim_t;

//****************************************************************************
//
//      ANIM_LoadAnim ()
//
// Setup internal anim data structure
//
//****************************************************************************

void ANIM_LoadAnim(byte* buffer);

//****************************************************************************
//
//      ANIM_FreeAnim ()
//
// Free up internal anim data structure
//
//****************************************************************************

void ANIM_FreeAnim(void);

//****************************************************************************
//
//      ANIM_NumFrames ()
//
// returns the number of frames in the current anim
//
//****************************************************************************

int32 ANIM_NumFrames(void);

//****************************************************************************
//
//      ANIM_DrawFrame ()
//
// Draw the frame to a returned buffer
//
//****************************************************************************

byte* ANIM_DrawFrame(int32 framenumber);

//****************************************************************************
//
//      ANIM_GetPalette ()
//
// return the palette of the anim
//****************************************************************************

byte* ANIM_GetPalette(void);

extern anim_t* anim;
