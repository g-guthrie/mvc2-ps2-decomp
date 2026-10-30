/*
 * Game functions that have no credited C (C_COVERAGE.md "unmatched"),
 * written for the host from the retail asm (Port J).  Each is a direct
 * transcription; the asm is in asm/main.s at the function's address.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "host.h"

extern int func_001E5710(void *, unsigned int);
extern int func_00423990(int, int);
extern int func_001E5700(void);
extern void func_00418B10(void);

/* func_0012DC00: the file-destination table D_004CA170..D_004CA204 (where
 * the async loader puts each file kind), carved out of the two big heaps
 * D_004C28BC (0x7E0000) and D_004C28B8 (0x200000). */
void func_0012DC00(void)
{
    u32 v1 = EE_BSS(u32, 0x004C28BC);
    u32 t3 = EE_BSS(u32, 0x004C28B8);
    u32 a3 = v1 + 0x141000, a1 = t3 + 0x67000, t0 = v1 + 0x291000;
    u32 a2 = v1 + 0x3E1000, a3b = v1 + 0x7D1000, a1b = v1 + 0x531000;
    u32 a0 = v1 + 0x3D0000, v1b = v1 + 0x681000;
    EE_BSS(u32, 0x004CA1F4) = v1 + 0x3F0000;
    EE_BSS(u32, 0x004CA1F8) = v1 + 0x150000;
    EE_BSS(u32, 0x004CA1FC) = v1 + 0x540000;
    EE_BSS(u32, 0x004CA200) = v1 + 0x2A0000;
    EE_BSS(u32, 0x004CA204) = v1 + 0x690000;
    EE_BSS(u32, 0x004CA1F0) = v1;
    EE_BSS(u32, 0x004CA170) = t3;
    EE_BSS(u32, 0x004CA174) = t3;
    EE_BSS(u32, 0x004CA178) = t3;
    EE_BSS(u32, 0x004CA17C) = t3;
    EE_BSS(u32, 0x004CA1DC) = v1 + 0x7C0000;
    EE_BSS(u32, 0x004CA180) = t3;
    EE_BSS(u32, 0x004CA184) = t3;
    EE_BSS(u32, 0x004CA1D0) = a3;
    EE_BSS(u32, 0x004CA190) = a3;
    EE_BSS(u32, 0x004CA1D4) = a1;
    EE_BSS(u32, 0x004CA1B0) = a1;
    EE_BSS(u32, 0x004CA1D8) = t0;
    EE_BSS(u32, 0x004CA198) = t0;
    EE_BSS(u32, 0x004CA1E0) = a2;
    EE_BSS(u32, 0x004CA1E4) = a3b;
    EE_BSS(u32, 0x004CA1B8) = a0;
    EE_BSS(u32, 0x004CA1B4) = a1b;
    EE_BSS(u32, 0x004CA194) = a1b;
    EE_BSS(u32, 0x004CA1BC) = v1b;
    EE_BSS(u32, 0x004CA19C) = v1b;
    EE_BSS(u32, 0x004CA1C0) = a2;
    EE_BSS(u32, 0x004CA1A0) = a2;
    EE_BSS(u32, 0x004CA1C4) = a3b;
    EE_BSS(u32, 0x004CA1A4) = a3b;
}

/* func_001E5870: now the credited C (see config/matches.csv). */

/* func_003F0E60(heap): compaction of the handle heap (the 6 MB pool
 * D_005BF280 and the arena blocks).  Heap: +0 block count, +8 block table
 * (16 bytes: addr, size, align, -), +0xC direction (0: blocks packed
 * downward from +0x14, else upward), +0x10 top, +0x14 base.  The live
 * blocks (size != 0) are listed as u16 indices at the heap base, bubble
 * sorted by address and slid together (func_003F5710 = memmove). */
typedef struct HBlk { u32 addr, size, align, pad; } HBlk;
static void heap_move(HBlk *b, u32 to)
{
    if (to != b->addr) {
        memmove((void *)(uintptr_t)to, (void *)(uintptr_t)b->addr, b->size);
        b->addr = to;
    }
}

/* func_003F0E60: now the credited C (see config/matches.csv). */

/* func_003DB020: per-player button configuration (D_0058EEF0) applied to the
 * fl device records D_004C2A68 -> D_004C2A6C (5 x 0x88).  APPROXIMATION
 * until the 0x75C-byte asm is ported: the records are copied unmapped (the
 * default configuration is the identity for the menus). */
void func_003DB020(void)
{
    u8 *src = *(u8 **)EE_BSS_PTR(0x004C2A68);
    u8 *dst = *(u8 **)EE_BSS_PTR(0x004C2A6C);
    HOST_ONCE("func_003DB020: button config copied unmapped (approximation)");
    if (src && dst)
        memcpy(dst, src, 5 * 0x88);
}

/* func_00130040: the boot memory-card screen (front-end state 1/8, called
 * by func_003D24A0 every frame).  g = D_004C2840: g[2] step, g[3] sub-step,
 * g[4] flag, h8 = *(s16 *)(g + 8) timer.  D_004D17C9 = message id shown by
 * func_00151640, D_004D17CA = yes/no cursor, D_004D179B / D_004D17CB flags,
 * D_004D17CC / D_004D17A4 card data pointers, D_004C2620/2624 results of
 * func_0041F860.  C from the asm (jump table jtbl_004B10A0). */
extern unsigned short func_0012ABC0(int, int);
extern int func_0012AA90(int, int, int);
extern void func_003D6D50(void);
extern void func_003D6E20(void);
extern void func_00170160(int);
extern void func_003DA410(void);
extern void func_00131290(void);
extern void func_001517C0(int, int);
extern void func_00151640(void);
extern void func_0041F860(int);
extern void func_003298B0(int, int, int);
extern int func_003299D0(void);
extern int func_0012FD70(void);
extern int func_00418D70(int);
extern int func_0038C750(int, int);
extern void func_0038A900(int);
extern int func_001315F0(void);
extern int func_001317B0(void);
extern void func_001E3CE0(int);
extern void func_0012FC40(void);
extern int func_0012FFD0(int);

#define MSG EE_BSS(u8, 0x004D17C9)
#define YESNO EE_BSS(u8, 0x004D17CA)
static void msg_set(u8 id)
{
    if (MSG != id) {
        MSG = id;
        func_00151640();
    }
}

static void mcboot_to_6(u8 *g)
{
    g[2] = 6;
    func_003298B0((int)0xFF000000, 10, 1);
}

static void mcboot_yesno_done(u8 *g, int clear3)
{
    if (YESNO != 0) {
        g[2] = 1;
        g[4] = 0;
        g[3] = 0;
        *(s16 *)(g + 8) = 0x3C;
        EE_BSS(s32, 0x004C2624) = -1;
        MSG = 0x1D;
        EE_BSS(s32, 0x004C2620) = -1;
        func_0041F860(0);
        func_00418CC0();
        func_00151640();
    } else {
        YESNO = 0xFF;
        func_001E3CE0(2);
        EE_BSS(u8, 0x004D179B) = 0;
        mcboot_to_6(g);
        if (clear3)
            g[3] = 0;
    }
}

void func_00130040(void)
{
    u32 s0 = func_0012ABC0(3, 0) & 0xFFFF;
    u8 *g = *(u8 **)EE_BSS_PTR(0x004C2840);
    s32 r, t;
    switch ((u32)(s32)(s8)g[2]) {
    case 0:
        g[2] = g[2] + 1;
        g[3] = 0;
        *(s16 *)(g + 8) = 0x3C;
        func_003D6D50();
        func_003D6E20();
        func_00170160(0x14);
        func_003DA410();
        func_00131290();
        EE_BSS(u8, 0x004D1792) = 0;
        EE_BSS(u8, 0x004D17CB) = 0;
        EE_BSS(u8, 0x004D179B) = 0;
        func_001517C0(0, 0);
        MSG = 0x1D;
        func_00151640();
        EE_BSS(s32, 0x004C2624) = -1;
        EE_BSS(s32, 0x004C2620) = -1;
        func_0041F860(0);
        func_003298B0((int)0xFF000000, 10, 0);
        /* fall through */
    case 1:
        if (func_003299D0() != 0)
            return;
        r = func_0012FD70();
        if (EE_BSS(s32, 0x004C2620) == -1 || EE_BSS(s32, 0x004C2624) == -1)
            return;
        t = *(s16 *)(g + 8);
        *(s16 *)(g + 8) = (s16)(t - 1);
        if (t != 0 && r == 5)
            return;
        g[2] = (u8)r;
        return;
    case 2:
        switch ((s8)g[3]) {
        case 0:
            if (func_00418D70(0) != 0)
                return;
            g[3] = g[3] + 1;
            /* fall through */
        case 1:
            r = func_0038C750(EE_BSS(s32, 0x004D17CC), 1);
            if (r == 1) {
                g[3] = g[3] + 1;
                g[4] = 0;
                *(s16 *)(g + 8) = 0xB4;
                EE_BSS(u8, 0x004D179B) = 1;
                MSG = 0x13;
                EE_BSS(s32, 0x004D17A4) = EE_BSS(s32, 0x004D17CC);
                func_00151640();
                func_0038A900(EE_BSS(s32, 0x004D17A4));
                return;
            }
            if (r != 0)
                return;
            g[3] = 3;
            g[4] = 0;
            *(s16 *)(g + 8) = 0;
            MSG = 0x2B;
            EE_BSS(u8, 0x004D179B) = 0;
            func_00151640();
            return;
        case 2:
            t = *(s16 *)(g + 8);
            *(s16 *)(g + 8) = (s16)(t - 1);
            if (t != 0 && func_001315F0() == 0)
                return;
            mcboot_to_6(g);
            return;
        case 3:
            if (g[4] == 0) {
                if (func_00418D70(0) != 0)
                    return;
                g[4] = g[4] + 1;
            }
            g[3] = g[3] + 1;
            return;
        case 4:
            if (func_001317B0() == 0)
                return;
            mcboot_to_6(g);
            return;
        default:
            return;
        }
    case 3:
        if ((s8)g[3] == 0) {
            *(s16 *)(g + 8) = 0;
            g[3] = g[3] + 1;
            msg_set(0x21);
        } else if ((s8)g[3] != 1) {
            return;
        }
        *(s16 *)(g + 8) = (s16)(*(s16 *)(g + 8) + 1);
        if (func_001317B0() == 0 && *(s16 *)(g + 8) < 0xB4)
            return;
        EE_BSS(u8, 0x004D179B) = 0;
        mcboot_to_6(g);
        return;
    case 5:
        if ((s8)g[3] == 0) {
            YESNO = 1;
            msg_set(0x18);
            g[3] = g[3] + 1;
        } else if ((s8)g[3] != 1) {
            return;
        }
        YESNO = (u8)func_0012AA90((int)s0, YESNO, 1);
        if (func_001315F0() == 0)
            return;
        mcboot_yesno_done(g, 0);
        return;
    case 6:
        if (func_003299D0() != 0)
            return;
        g[1] = g[1] + 1;
        g[2] = 0;
        g[3] = 0;
        g[4] = 0;
        g[5] = 0;
        if (EE_BSS(u8, 0x004D17CB) != 0) {
            EE_BSS(u8, 0x004D17CB) = 0;
            func_0012FC40();
        }
        return;
    case 9:
        if ((s8)g[3] == 0) {
            msg_set(0x20);
            *(s16 *)(g + 8) = 0xB4;
            g[3] = g[3] + 1;
            return;
        }
        if ((s8)g[3] != 1)
            return;
        *(s16 *)(g + 8) = (s16)(*(s16 *)(g + 8) - 1);
        if (*(s16 *)(g + 8) != 0 && func_001317B0() == 0)
            return;
        EE_BSS(u8, 0x004D179B) = 0;
        mcboot_to_6(g);
        return;
    case 10:
        if (func_0012FFD0(0) != 0)
            return;
        msg_set(0x2F);
        return;
    case 11:
        switch ((s8)g[3]) {
        case 0:
            msg_set(0x21);
            *(s16 *)(g + 8) = 0;
            g[3] = g[3] + 1;
            return;
        case 1:
            *(s16 *)(g + 8) = (s16)(*(s16 *)(g + 8) + 1);
            if (func_001315F0() == 0 && *(s16 *)(g + 8) < 0xB4)
                return;
            g[3] = g[3] + 1;
            MSG = 0x30;
            YESNO = 1;
            func_00151640();
            return;
        case 2:
            YESNO = (u8)func_0012AA90((int)s0, YESNO, 1);
            if (func_001315F0() == 0)
                return;
            mcboot_yesno_done(g, 1);
            return;
        default:
            return;
        }
    default: /* 4, 7, 8, >= 12 */
        func_0012FFD0(0);
        return;
    }
}

/* func_00415590(model, pol, fmt, fmt_list): build a POL pack's meshes and
 * node trees (C from the asm).  model: +4 materials (func_00415320, 0x4C
 * each), +8/+0xA node count/base, +0xC nodes (0x190 bytes each, pool
 * D_0051DA70), +0x10/+0x12 mesh count/base, +0x14 meshes (0xB4 bytes each,
 * pool D_004F9170), +0x18 root count, +0x1C roots (pool D_004F8470).  Each
 * mesh: +0 clay handle (func_003EE6F0 with the format word from fmt_list
 * {fmt, count} pairs, or `fmt` when there is no list / it ran out), +4 draw
 * flags (pol[2][k]), +0xC/+0x10 material count/indices, +0x90 the clay
 * header copy (func_0041B3C0).  The pools are bounded at 0x340 entries. */
extern int func_003F1950(int);
extern int func_003F1E10(void *, int);
extern int func_003F1E70(void *, int, void *);
extern void func_00415A00(int);
extern int func_003DFF80(int);
extern int func_003DF850(int, int);
extern void func_003DCF90(void *);
extern int func_003F2A50(void *, int, unsigned int);
extern int func_003EE6F0(void *, unsigned int);
extern void func_0041B3C0(void *, void *, int);
extern void func_003DCFB0(void *);
extern int func_003F13A0(void *);
extern int func_003F13E0(void *);
extern int func_003F16D0(void *, int);
extern int func_003F1730(void *, void *, void *, int);
extern int func_003DE7E0(void *);
extern void func_003DE880(int, int, int, int);
extern int func_003DEC90(int);
extern int func_003DE860(int);

/* func_00415590: now the credited C (see config/matches.csv). */

/* func_003DE230(out, a, b): VU0 3x3 product of the rotation parts,
 * out.row[i].xyz = a.row[i].x * b.row[0] + a.row[i].y * b.row[1] + a.row[i].z * b.row[2]
 * (rows of 4 floats; w and row 3 of out untouched).  Inputs are copied
 * first, as the asm does, so out may alias them. */
void func_003DE230(int outp, int ap, int bp)
{
    float a[16], b[16], *o = (float *)(uintptr_t)outp;
    int i, k;
    memcpy(a, (void *)(uintptr_t)ap, 64);
    memcpy(b, (void *)(uintptr_t)bp, 64);
    for (i = 0; i < 3; i++)
        for (k = 0; k < 3; k++)
            o[4 * i + k] = a[4 * i] * b[k] + a[4 * i + 1] * b[4 + k] + a[4 * i + 2] * b[8 + k];
}

/* func_00422150(str, &pos, x, y, scale): one record of the menu text/shape
 * byte code (func_004220B0 runs str[0] of them).  Header codes until code 1:
 * 1 = x(2) y(2) scale(1) and start drawing, 5 = space width, 6/7/8/9 =
 * colour A/R/G/B, 11 = texture slot (D_0057FB70), 12 = skip 2.  Then one
 * glyph per byte: 0 = end (clears the cursor D_004C2BA4/A8/AC/B0), 1 = new x,
 * 4 = new line (+extra), 5 = space, 13 = 8 px, 10 = glyph from D_004A7F80,
 * others from D_004A6F80 (':' 2 px up); each glyph is {x0,y0,x1,y1} in a
 * 512x512 texture page and is drawn by func_00421FB0.  C from the asm. */
extern void func_00421FB0(float, int, void *, void *, int);
extern void func_00422BE0(void);
extern s32 data_s32x4_004A6F80[], data_s32x4_004A7F80[];

/* func_00422150: now the credited C (see config/matches.csv). */

/* func_001428E0: the intro's event timeline (front-end state 1/2), run once
 * per frame from func_001431A0.  On given values of the scene clock
 * (*(s16 *)(D_004C2840 + 0xA)) it switches the intro's actor objects
 * (D_004CACB0[], 18 pointers, and D_004CAD00.. / D_004CAD3C..) on and off,
 * sets the fade colours D_004C2638 / D_004C263C, starts the BGM
 * (func_003298B0) and sound, then spawns the scheduled effects listed in
 * D_00441E30 (28-byte rows keyed by the clock).  C from the asm. */
extern void func_001E3CA0(int);
extern void func_001E3FE0(void);
extern void func_001422E0(void *, int);
extern void func_00141C90(int, int);
extern void func_001415B0(void *);
extern void *func_00142610(int);
extern u8 D_004415F0[], D_004416D0[], D_00441480[], D_00441550[], D_00441620[], D_00441700[],
    D_004413D0[];
extern u8 D_00441E30[];

#define IA(i) (EE_BSS(u8 *, 0x004CACB0 + 4 * (i)))
#define IP(a) (EE_BSS(u8 *, (a)))
#define U32P(a) ((u32)(uintptr_t)(a))

static void intro_set4(int base, int v)
{
    int i;
    for (i = 0; i < 4; i++)
        IP(base + 4 * i)[0x13C] = (u8)v;
}

static void intro_actors_5_8(void)
{
    func_00141C90(5, (int)U32P(D_00441480));
    func_00141C90(6, (int)U32P(D_00441550));
    func_00141C90(7, (int)U32P(D_00441620));
    func_00141C90(8, (int)U32P(D_00441700));
}

void func_001428E0(void)
{
    int t = *(s16 *)(EE_BSS(u8 *, 0x004C2840) + 0xA), i;
    u8 *p;
    switch (t) {
    case 0:
        EE_BSS(u32, 0x004C2638) = 0xFF000000u;
        EE_BSS(u32, 0x004C263C) = 0xFF000000u;
        func_003298B0(0, 0x1E, 0);
        func_001E3CA0(0);
        EE_BSS(s32, 0x004C264C) = 0;
        EE_BSS(s32, 0x004C2644) = 0;
        break;
    case 0x3C:
        func_003298B0(0, 0x3C, 1);
        break;
    case 0x78:
        func_001E3FE0();
        break;
    case 0x6E:
        func_003298B0(0, 0x78, 0);
        break;
    case 0x1E3:
        p = IA(5);
        EE_BSS(u32, 0x004C2638) = 0xFF0000FFu;
        EE_BSS(u32, 0x004C263C) = 0xFF000000u;
        EE_BSS(u8, 0x004C27C0) = 4;
        EE_BSS(u8, 0x004C27C4) = 1;
        p[0x13C] = 0;
        p[0x320] = 0;
        *(u32 *)(p + 0x3D8) = U32P(D_004415F0);
        *(s16 *)(p + 0x3E4) = 1;
        *(u32 *)(p + 0x5BC) = U32P(D_004416D0);
        *(s16 *)(p + 0x5C8) = 1;
        break;
    case 0x233:
        EE_BSS(u32, 0x004C2640) = 0;
        EE_BSS(u32, 0x004C2638) = 0xFF90B0C0u;
        EE_BSS(u8, 0x004F1D20) = 1;
        for (i = 0; i < 9; i++)
            IA(i)[0x13C] = 0;
        for (i = 9; i < 13; i++) {
            IA(i)[0] = 0;
            IA(i)[0x13C] = 0;
        }
        for (i = 13; i < 18; i++)
            func_001422E0(IA(i), i - 13);
        break;
    case 0x346:
        EE_BSS(u8, 0x004F1D20) = 0;
        EE_BSS(u32, 0x004C2638) = 0xFF000000u;
        EE_BSS(u32, 0x004C263C) = 0xFF000000u;
        for (i = 13; i < 18; i++) {
            IA(i)[0] = 0;
            IA(i)[0x13C] = 0;
        }
        for (i = 0; i < 3; i++)
            IP(0x004CAD3C + 4 * i)[0x13C] = 0;
        EE_BSS(s32, 0x004C2644) = 0;
        intro_actors_5_8();
        for (i = 0; i < 5; i++) {
            p = IA(i);
            p[0x13C] = 1;
            if (i == 1) {
                *(s16 *)(p + 0xCC) = 2;
                *(u32 *)(p + 0x84) = EE_BSS(u32, 0x004C2814);
                *(u32 *)(p + 0x10) = U32P(D_004413D0);
                func_001415B0(p);
            }
        }
        for (i = 9; i < 18; i++) {
            IA(i)[0] = 0;
            IA(i)[0x13C] = 0;
        }
        break;
    case 0x3CA:
        p = IA(5);
        EE_BSS(u32, 0x004C2638) = 0xFFFF0000u;
        EE_BSS(u32, 0x004C263C) = 0xFF000000u;
        EE_BSS(u8, 0x004C27C0) = 5;
        EE_BSS(u8, 0x004C27C4) = 1;
        *(u32 *)(p + 0x10) = U32P(D_004415F0);
        *(s16 *)(p + 0x1C) = 1;
        *(u32 *)(p + 0x1F4) = U32P(D_004416D0);
        *(s16 *)(p + 0x200) = 1;
        p[0x504] = 0;
        p[0x6E8] = 0;
        for (i = 9; i < 13; i++)
            IA(i)[0x13C] = 0;
        IA(17)[0] = 0;
        IA(17)[0x13C] = 0;
        intro_set4(0x004CAD00, 0);
        break;
    case 0x41A:
        EE_BSS(u32, 0x004C2640) = 0;
        EE_BSS(u32, 0x004C2638) = 0xFF90B0C0u;
        EE_BSS(u8, 0x004F1D20) = 1;
        for (i = 0; i < 9; i++)
            IA(i)[0x13C] = 0;
        for (i = 13; i < 18; i++) {
            p = IA(i);
            p[0] = 0;
            p[0x13C] = 0;
            func_001422E0(p, i - 13);
        }
        for (i = 0; i < 3; i++)
            IP(0x004CAD3C + 4 * i)[0x13C] = 1;
        break;
    case 0x52F:
        EE_BSS(u32, 0x004C2638) = 0xFF000000u;
        EE_BSS(u32, 0x004C263C) = 0xFF000000u;
        EE_BSS(u8, 0x004F1D20) = 0;
        intro_actors_5_8();
        for (i = 0; i < 13; i++)
            IA(i)[0x13C] = 1;
        for (i = 13; i < 18; i++) {
            IA(i)[0] = 0;
            IA(i)[0x13C] = 0;
        }
        intro_set4(0x004CAD00, 1);
        for (i = 0; i < 3; i++) {
            IP(0x004CAD3C + 4 * i)[0x13C] = 0;
            IP(0x004CAD3C + 4 * i)[0] = 0;
        }
        break;
    case 0x60B:
        p = IA(3);
        *(u32 *)(p + 0x64) = 0x3E800000u; /* 0.25f */
        p[0x20] = 1;
        break;
    case 0x615:
        p = IA(4);
        *(u32 *)(p + 0x64) = 0x3E800000u;
        p[0x20] = 1;
        IA(0)[0x25] = 2;
        IA(2)[0x25] = 2;
        break;
    case 0x6B5:
        func_003298B0(-1, 5, 1);
        break;
    }
    for (;;) {
        s32 k = EE_BSS(s32, 0x004C264C);
        u8 *o;
        if (*(s16 *)(D_00441E30 + k * 28) != *(s16 *)(EE_BSS(u8 *, 0x004C2840) + 0xA))
            break;
        o = (u8 *)func_00142610(k);
        k = EE_BSS(s32, 0x004C264C);
        if (k >= 9 && k < 12)
            *(s16 *)(o + 0x1E) = 0x50;
        if (EE_BSS(s32, 0x004C264C) == 12)
            *(s16 *)(o + 0x1E) = 0x5A;
        EE_BSS(s32, 0x004C264C) = EE_BSS(s32, 0x004C264C) + 1;
    }
}

/* func_003F01B0: now the credited C (see config/matches.csv). */

/* func_00176360(index, argb4444[16], -): character palette animation.  The
 * palette index is split over six ranges (thresholds data_s8_004ACD08[0..5],
 * the last open-ended) into a character slot (D_00446BF0[range], -1 = none)
 * and a palette within it; the 16 ARGB4444 colours become 32-bit CLUT
 * colours (nibble << 4 per channel, alpha 0xF -> 0xFF) and are written to
 * that slot's CLUT through func_00413C00 (D_0063248C[slot * 5] = the slot's
 * sprite handle) with the upload descriptor the asm builds.  C from the asm. */
extern s8 data_s8_004ACD08[];
extern s32 D_00446BF0[];
extern int func_00413C00(int, int, int);

/* func_00176360: now the credited C (see config/matches.csv). */

/* func_003EBF30(request, handles, n): VRAM placement search over the block
 * list D_004C2AB4 (node +0x4 next, +0x8 owner record, +0x10 kind (1, 4 =
 * reusable), s16 +0x14 start, +0x16 size; 0x4000 = end of the area).
 * Returns the first reusable node from which a run of reusable nodes not
 * owned by any of the n texture/palette handles spans the request size
 * (s16 request + 0x10); else 1 if the space after the last node fits, -1 if
 * not; 0 with an empty list.  C from the asm. */
static int vram_owned_by(u8 *node, const u32 *h, int n)
{
    int k;
    for (k = 0; k < n; k++) {
        u32 t = h[k] & 0xFFFF, p = h[k] >> 16;
        if (t && (uintptr_t)EE_BSS_PTR(0x006207A0) + (t - 1) * 64 == *(u32 *)(node + 8))
            return 1;
        if (p && (uintptr_t)EE_BSS_PTR(0x0061C7A0) + (p - 1) * 64 == *(u32 *)(node + 8))
            return 1;
    }
    return 0;
}

/* func_003EBF30: now the credited C (see config/matches.csv). */

/* func_003F59C0(fmt, pt): put one pixel {s16 x, s16 y, u32 colour} into the
 * image described by fmt (func_003F5900 gives the address).  Indexed formats
 * (fmt+0 & 4) write the index at the depth fmt+0x14 (0 = 4 bit: a whole byte
 * with flag 0x40, else the nibble chosen by x & 1 and flag 0x10; 1, 2, 4
 * bytes); direct colour scales each 8-bit channel to the format's maximum
 * (r: fmt+0x38 << fmt+0x34, g: 0x2C << 0x28, b: 0x20 << 0x1C, a: 0x44 << 0x40,
 * x * max / 255 truncated) and writes 4, 3 or 2 bytes.  C from the asm. */
extern int func_003F5900(int, int, void *);

/* func_003F59C0: now the credited C (see config/matches.csv). */

/* func_001E7CB0(A, B, boxA, boxB, out): overlap of two characters' boxes.
 * Boxes are s16 {x, w, y, h} at *(A + 0x180) + index * 8, in units scaled by
 * 5/3 horizontally and 15/7 vertically and by each character's scale
 * (+0x50, +0x54); x mirrors with the facing flag s16 +0x140, positions are
 * +0x34 / +0x38.  When |dx| < wA + wB and |dy| < hA + hB (zero widths or
 * heights of B never overlap) it stores the vertical overlap in *out and
 * sets B[0x1B3] = 1.  C from the asm. */
void func_001E7CB0(int a0, int a1, int a2, int a3, int t0)
{
    u8 *A = (u8 *)(uintptr_t)a0, *B = (u8 *)(uintptr_t)a1;
    const s16 *ba = (const s16 *)(uintptr_t)(*(u32 *)(A + 0x180) + (u32)(a2 & 0xFFFF) * 8);
    const s16 *bb = (const s16 *)(uintptr_t)(*(u32 *)(B + 0x180) + (u32)(a3 & 0xFFFF) * 8);
    const float kx = 1.6666666269302368f, ky = 2.142857074737549f;
    float sa = *(float *)(A + 0x50), sb = *(float *)(B + 0x50), xa, xb, d, wa, wb, ya, yb, ha, hb;
    xa = kx * (float)ba[0] * sa;
    xb = kx * (float)bb[0] * sb;
    if (*(s16 *)(A + 0x140))
        xa = -xa;
    xa += *(float *)(A + 0x34);
    if (*(s16 *)(B + 0x140))
        xb = -xb;
    xb += *(float *)(B + 0x34);
    d = xa - xb;
    if (d < 0)
        d = -d;
    wb = kx * (float)bb[1] * sb;
    if (wb == 0.0f)
        return;
    wa = kx * (float)ba[1] * sa;
    if (!(d < wb + wa))
        return;
    sa = *(float *)(A + 0x54);
    sb = *(float *)(B + 0x54);
    ya = -(ky * (float)ba[2] * sa) + *(float *)(A + 0x38);
    yb = -(ky * (float)bb[2] * sb) + *(float *)(B + 0x38);
    d = ya - yb;
    if (d < 0)
        d = -d;
    hb = ky * (float)bb[3] * sb;
    if (hb == 0.0f)
        return;
    ha = ky * (float)ba[3] * sa;
    if (!(d < hb + ha))
        return;
    *(float *)(uintptr_t)t0 = hb + ha - d;
    B[0x1B3] = 1;
}

/* func_00188860(p, k): assist / tag-in request of character p.  k = 1, 2
 * (assist 1 / 2: button masks 0x80 / 0x10, repeat timers p+0x26E / 0x26F)
 * or 3, 4 (the same buttons for the variable/tag moves, timers p+0x25E /
 * 0x25F, partner 1 / 2).  The first press arms a 16-frame timer; a second
 * press within it (and no held button, p+0x354) fires, unless the character
 * is busy (p[5], states p[0x20D], p[0x210], p[0x1E4] / p[0x213]), the
 * opponents are in a flagged state (+0x28B), the match forbids it (g+0xB9,
 * g+0xBA, D_004D18A0, D_004D18D4[side]) or the partner (team table
 * D_004C2794 + side * 12, +0x18 + slot * 4) is out or not ready
 * (func_0018A580).  Firing sets p+0x26B (partner slot) and either starts the
 * call (func_00186A60(p, 0x1C), k < 3) or flags p+0x2B0 = -1.  Returns 1 when
 * it fired.  C from the asm. */
extern void func_00186A60(void *, unsigned char);
extern int func_0018A580(void *);

/* func_00188860: now the credited C (see config/matches.csv). */

/* func_00122960(x, y, z): the stage light colours for this frame.  Each is
 * 0xRRGGBB from three byte triples scaled by the floats D_004F1D0C/10/14:
 * *x from D_004F1CF6/5/4 always, *y from D_004F1CFA/9/8 in modes 1-3 and
 * *z from D_004F1CFE/D/C in mode 3 (mode D_004F1CF0; other modes: nothing).
 * With func_0016D130() set: mode 0 and *x = D_004F1CBC; with the team flags
 * (D_004C2794)[0x76] and [6] both set: mode 0 and *x = 0.  C from the asm. */
extern int func_0016D130(void);

static u32 light_rgb(u32 a, u32 b, u32 c)
{
    float f20 = EE_BSS(float, 0x004F1D0C), f21 = EE_BSS(float, 0x004F1D10), f22 = EE_BSS(float, 0x004F1D14);
    return ((u32)(s32)(f20 * (float)EE_BSS(u8, a)) & 0xFF) << 16 |
           ((u32)(s32)(f21 * (float)EE_BSS(u8, b)) & 0xFF) << 8 |
           ((u32)(s32)(f22 * (float)EE_BSS(u8, c)) & 0xFF);
}

/* func_00122960: now the credited C (see config/matches.csv). */

/* func_0032DF90(side): the CPU picks its team of three.  Player records are
 * D_004F20B0 + (side + slot * 2) * 0x5B8 (+0x540 character, +1 copy,
 * +0x4DD from D_004405A0[character]); slot counter s16 +0x1E of slot 0.
 * Mode 7 (g[0x85]) takes characters 0x18..0x1A.  Otherwise each pick tries
 * 16 random characters (func_00417A40: bit, then word) that the opponent has
 * not taken (+0x518 words) but the opponent's set lists
 * (D_00583B90 + set * 8 + 0x10) and this team does not have yet; failing
 * that, the first such character in order, then the first listed one.
 * D_00583B90[side + 2] collects 0x11 << slot.  C from the asm. */
extern int func_00417A40(void);
extern s8 D_004405A0[];

static int cpu_pick(u8 *opp, u8 *flags, const u32 *mask, s32 *pw, s32 *pb)
{
    s32 k, w, b;
#define SET_WORD(wi) (*(u32 *)(flags + (s32)(s8)opp[0x538] * 8 + (wi) * 4 + 0x10))
#define OPP_WORD(wi) (*(u32 *)(opp + 0x518 + (wi) * 4))
    for (k = 0; k < 16; k++) {
        u32 r1 = (u32)func_00417A40(), r2 = (u32)func_00417A40(), bit;
        w = (s8)(r2 & 1);
        b = (s32)(r1 & 0x1F);
        bit = 1u << b;
        if ((OPP_WORD(w) & bit) || !(SET_WORD(w) & bit) || (mask[w] & bit))
            continue;
        *pw = w, *pb = b;
        return 1;
    }
    for (w = 0; w < 2; w++)
        for (b = 0; b < 32; b++)
            if ((((OPP_WORD(w) ^ SET_WORD(w)) >> b) & 1) && !((mask[w] >> b) & 1)) {
                *pw = w, *pb = b;
                return 1;
            }
    for (w = 0; w < 2; w++)
        for (b = 0; b < 32; b++)
            if (((SET_WORD(w) >> b) & 1) && !((mask[w] >> b) & 1)) {
                *pw = w, *pb = b;
                return 1;
            }
#undef SET_WORD
#undef OPP_WORD
    return 0;
}

void func_0032DF90(int a0)
{
    s32 side = (s8)a0, w = 0, b = 0, t;
    u8 *base = (u8 *)EE_BSS_PTR(0x004F20B0), *flags = (u8 *)EE_BSS_PTR(0x00583B90);
    u8 *opp = base + (side ^ 1) * 0x5B8, *me = base + side * 0x5B8, *g = EE_BSS(u8 *, 0x004C2840), *rec;
    u32 mask[2] = { 0, 0 };
    flags[2 + side] = 0;
    for (*(s16 *)(me + 0x1E) = 0; *(s16 *)(me + 0x1E) < 3; (*(s16 *)(me + 0x1E))++) {
        t = *(s16 *)(me + 0x1E);
        rec = base + (side + t * 2) * 0x5B8;
        if (*(s8 *)(g + 0x85) == 7) {
            rec[0x540] = (u8)(t + 0x18);
            rec[1] = (u8)(t + 0x18);
            rec[0x4DD] = 0;
        } else {
            const char *force = getenv("MVC2_CPU_TEAM");  /* testing: "id,id,id" */
            if (force) {
                int ids[3] = { -1, -1, -1 };
                sscanf(force, "%i,%i,%i", &ids[0], &ids[1], &ids[2]);
                if (ids[t] >= 0) {
                    w = ids[t] >> 5;
                    b = ids[t] & 31;
                    goto picked;
                }
            }
            if (!cpu_pick(opp, flags, mask, &w, &b))
                HOST_ONCE("func_0032DF90: no character left to pick");
        picked:
            host_log("CPU pick %d: character %#x", t, b + w * 32);
            mask[w & 1] |= 1u << b;
            rec[0x540] = (u8)(b + w * 32);
            rec[1] = rec[0x540];
            rec[0x4DD] = (u8)D_004405A0[(s8)rec[0x540]];
        }
        flags[side + 2] |= (u8)(0x11 << (s8)t);
    }
}
