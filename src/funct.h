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

#include "duke3d.h"
#include "audiolib/sounds.h"
#include "menu/menu.h"
#include "config/config.h"
#include "rts/rts.h"
#include "premap.h"
#include "player.h"
#include "sector.h"
#include "gamedefs.h"
#include "actors/actors.h"

extern void sendscore(char* s);
extern int USRHOOKS_GetMem(void** ptr, uint32_t size);
extern int USRHOOKS_FreeMem(void* ptr);
extern uint8_t checksum(int32_t sum);
extern int loadplayer(int8_t spot);
extern void sendgameinfo(void);
extern int probeXduke(int x, int y, int i, int n, int32_t spriteSize);
extern void overwritesprite(int32_t thex, int32_t they, short tilenum,
                            int8_t shade, uint8_t stat, uint8_t dapalnum);
extern void timerhandler(void);
extern int inittimer(int);
extern void uninittimer(void);
extern void ShutDown(void);
extern void allowtimetocorrecterrorswhenquitting(void);
extern void getpackets(void);
extern void faketimerhandler(void);
extern void checksync(void);
extern void check_fta_sounds(short i);
extern short inventory(spritetype* s);
extern short badguy(spritetype* s);
extern short badguypic(short pn);
extern void myos(int32_t x, int32_t y, short tilenum, int8_t shade,
                 uint8_t orientation);
extern void myospal(int32_t x, int32_t y, short tilenum, int8_t shade,
                    uint8_t orientation, uint8_t p);
extern void invennum(int32_t x, int32_t y, uint8_t num1, uint8_t ha,
                     uint8_t sbits);
extern void weaponnum(short ind, int32_t x, int32_t y, int32_t num1,
                      int32_t num2, uint8_t ha);
extern void weaponnum999(uint8_t ind, int32_t x, int32_t y, int32_t num1,
                         int32_t num2, uint8_t ha);
extern void displayfragbar(void);
extern void tics(short offx, short offy, short color);
extern void clocks(void);
extern void coords(short snum);
extern void HU_DrawQuotes(void);
extern void showtwoscreens(void);

extern void gameexit(char* t);
extern short strget(short x, short y, char* t, short dalen, short c);
extern void displayrest(int32_t smoothratio);
extern void updatesectorz(int32_t x, int32_t y, int32_t z, short* sectnum);
extern void view(struct player_struct* pp, int32_t* vx, int32_t* vy,
                 int32_t* vz, short* vsectnum, short ang, short horiz);
extern void drawbackground(void);
extern void displayrooms(short snum, int32_t smoothratio);
extern short LocateTheLocator(short n, short sn);
extern short EGS(
    short whatsect,
    i32 s_x,
    i32 s_y,
    i32 s_z,
    short s_pn,
    i8 s_s,
    i8 s_xr,
    i8 s_yr,
    short s_a,
    short s_ve,
    i32 s_zv,
    short s_ow,
    i8 s_ss
);
extern uint8_t wallswitchcheck(short i);
extern short spawn(short j, short pn);
extern void animatesprites(int32_t x, int32_t y, short a, int32_t smoothratio);
extern void cheats(void);
extern void nonsharedkeys(void);
extern void CMD_Help(char** argv);
extern void CMD_Execute(int argc, char** argv);
extern void printstr(short x, short y, uint8_t string[], uint8_t attribute);
extern void Logo(void);
extern void loadtmb(void);
extern void compilecons(void);
extern void Startup(void);
extern void getnames(void);
extern int main(int argc, char** argv);
extern uint8_t opendemoread(uint8_t which_demo);
extern void opendemowrite(void);
extern void record(void);
extern void closedemowrite(void);
extern int32_t playback(void);
extern uint8_t moveloop(void);
extern void fakedomovethingscorrect(void);
extern void fakedomovethings(void);
extern uint8_t domovethings(void);
extern void displaybonuspics(short x, short y, short p);
extern void doorders(void);
extern void dobonus(uint8_t bonusonly);
extern void cameratext(short i);
extern void vglass(int32_t x, int32_t y, short a, short wn, short n);
extern void lotsofglass(short i, short wallnum, short n);
extern void ceilingglass(short i, short sectnum, short n);
extern void lotsofcolourglass(short i, short wallnum, short n);
extern int32_t GetTime(void);
extern void CenterCenter(void);
extern void UpperLeft(void);
extern void LowerRight(void);
extern void CenterThrottle(void);
extern void CenterRudder(void);
extern void takescreenshot(void);

extern void readsavenames(void);
extern void CheckAnimStarted(uint8_t* funcname);
extern uint16 findpage(uint16 framenumber);
extern void loadpage(uint16 pagenumber, uint16* pagepointer);
extern void CPlayRunSkipDump(byte* srcP, byte* dstP);
extern void renderframe(uint16 framenumber, uint16* pagepointer);
extern void drawframe(uint16 framenumber);
extern void ANIM_LoadAnim(byte* buffer);
extern void ANIM_FreeAnim(void);
extern int32 ANIM_NumFrames(void);
extern byte* ANIM_DrawFrame(int32 framenumber);
extern byte* ANIM_GetPalette(void);


void HU_SetPlayerQuote(short q, player_t* p, int mode);
void HU_AddUserQuote(const char* quote);
void HU_TickPlayerQuote(player_t* p);
void HU_TickUserQuotes(void);
int HU_DrawText(int x, int y, const char* text, u8 shade, short stat);
int HU_GameTextPal(int x, int y, const char* text, u8 shade, u8 pal);
int HU_DrawMiniText(int x, int y, const char* text, u8 pal, u8 stat);
int HU_MiniTextShade(int x, int y, const char* text, u8 shade, u8 pal, u8 stat);

extern int32_t quotebot;
extern int32_t quotebotgoal;
extern char fta_quotes[NUMOFFIRSTTIMEACTIVE][64];
