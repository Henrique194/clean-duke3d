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

#include <stdint.h>
#include "renderer/renderer.h"
#include "physics/physics.h"


//#define SUPERBUILD  /* don't touch this. */

/*
 * this must be implemented by every program that uses the BUILD engine.
 *  engine.c calls this function in several places.
 *  See Ken's test game (in game.c), and his editor (in bstub.c) for examples.
 */
void faketimerhandler(void);

/*
 * exported engine functions, in absolutely no particular order.
 *  See build.txt, build2.txt...and anything else with a .txt extention for
 *  information on using these functions that may or may not be accurate. :)
 */
int initmouse(void);
int setgamemode(int32_t daxdim, int32_t daydim);
int getceilzofslope(int16_t sectnum, int32_t dax, int32_t day);
int getflorzofslope(int16_t sectnum, int32_t dax, int32_t day);
void getzsofslope(int16_t sectnum, int32_t dax, int32_t day, int32_t* ceilz,
                  int32_t* florz);
void setaspect(int32_t daxrange, int32_t daaspect);
void loadtile(int16_t tilenume);


void nextpage(void);
int loadboard(char* filename, int32_t* daposx, int32_t* daposy, int32_t* daposz,
              int16_t* daang, int16_t* dacursectnum);
void printext256(int32_t xpos, int32_t ypos, int16_t col, int16_t backcol,
                 char name[82], uint8_t fontsize);

void initengine(void);
void uninitengine(void);

int loadpics(char* filename, char* gamedir);
int saveboard(char* filename, int32_t* daposx, int32_t* daposy, int32_t* daposz,
              int16_t* daang, int16_t* dacursectnum);
void plotpixel(int32_t x, int32_t y, uint8_t col);
uint8_t getpixel(int32_t x, int32_t y);
void screencapture(char* filename);
void getmousevalues(int16_t* mousx, int16_t* mousy, int16_t* bstatus);
int getangle(int32_t xvect, int32_t yvect);
void alignceilslope(int16_t dasect, int32_t x, int32_t y, int32_t z);
void alignflorslope(int16_t dasect, int32_t x, int32_t y, int32_t z);
void rotatepoint(int32_t xpivot, int32_t ypivot, int32_t x, int32_t y,
                 int16_t daang, int32_t* x2, int32_t* y2);
int drawtilescreen(int32_t pictopleft, int32_t picbox);
void R_ClearView(int32_t col);
int ksqrt(int32_t num);
uint8_t* allocatepermanenttile(int16_t tilenume, int32_t xsiz, int32_t ysiz);
void drawline256(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint8_t col);
void copytilepiece(int32_t tilenume1, int32_t sx1, int32_t sy1, int32_t xsiz,
                   int32_t ysiz, int32_t tilenume2, int32_t sx2, int32_t sy2);
int nextsectorneighborz(int16_t sectnum, int32_t thez, int16_t topbottom,
                        int16_t direction);

int krand(void);

void setview(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void setviewtotile(int16_t tilenume, int32_t xsiz, int32_t ysiz);
void setviewback(void);
void squarerotatetile(int16_t tilenume);

#include "cache.h"
#include "build/filesystem.h"
#include "build/fixedPoint_math.h"
#include "build/tiles.h"
#include "build/mmulti.h"
#include "build/sprite.h"


//Exported for tile module
extern int32_t setviewcnt;
extern int32_t bakvidoption[4];
extern uint8_t* bakframeplace[4];
extern int32_t bakxsiz[4], bakysiz[4];
extern int32_t bakwindowx1[4], bakwindowy1[4];
extern int32_t bakwindowx2[4], bakwindowy2[4];
extern uint8_t picsiz[MAXTILES], tilefilenum[MAXTILES];
extern int16_t bakumost[MAXXDIM + 1], bakdmost[MAXXDIM + 1];
extern int32_t numtilefiles, artfil, artfilnum, artfilplc;
extern int32_t pow2long[32];
extern int32_t artsize;
extern int32_t tilefileoffs[MAXTILES];
extern int32_t totalclocklock;
