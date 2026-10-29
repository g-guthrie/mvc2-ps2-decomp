/*
 * Game functions that have no credited C (C_COVERAGE.md "unmatched"),
 * written for the host from the retail asm (Port J).  Each is a direct
 * transcription; the asm is in asm/main.s at the function's address.
 */
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

/* func_001E5870(entry, slot): send an AFS01 sound bank to the driver
 * (func_001E5710) and wait until the driver's pending-load count (TSD\1
 * fno 0xC) changes, at most 0xF0 server ticks (else the slot's EE sound
 * table D_004CC150[slot] is cleared and -1 returned), then until the bank
 * queue func_001E5700 drains. */
int func_001E5870(int entry, int slot)
{
    s32 before = func_00423990((int)0x8000000C, 1);
    s32 r = func_001E5710((void *)(uintptr_t)entry, (u32)slot);
    s32 n = 0xF0;
    if (r < 0)
        return r;
    while (func_00423990((int)0x8000000C, 1) == before) {
        func_00418B10();
        if (--n < 0) {
            memset((u8 *)EE_BSS_PTR(0x004CC150) + ((u32)slot << 9), 0, 0x200);
            return -1;
        }
    }
    while (func_001E5700() > 0)
        func_00418B10();
    return 0;
}

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

void func_003F0E60(int hp)
{
    s32 *h = (s32 *)(uintptr_t)hp;
    HBlk *B = (HBlk *)(uintptr_t)h[2];
    u16 *list = (u16 *)(uintptr_t)(h[3] ? (u32)h[5] - (u32)h[0] * 2 : (u32)h[5]);
    s32 cnt = 0, i, k, n, pass;
    for (i = 0; i < h[0]; i++)
        if (B[i].size != 0)
            list[cnt++] = (u16)i;
    if (cnt == 0) {
        h[4] = h[5];
        return;
    }
    /* bubble sort: ascending addresses (upward heap) or descending */
    for (pass = 0, n = cnt; pass < cnt; pass++, n--)
        for (k = 0; k < n - 1; k++) {
            u16 a = list[k], b = list[k + 1];
            if (h[3] ? B[b].addr < B[a].addr : B[a].addr < B[b].addr) {
                list[k + 1] = a;
                list[k] = b;
            }
        }
    if (h[3]) {
        HBlk *f = &B[list[0]];
        heap_move(f, ((u32)h[5] + f->align - 1) & ~(f->align - 1));
        for (k = 1; k < cnt; k++) {
            HBlk *p = &B[list[k - 1]], *c = &B[list[k]];
            heap_move(c, (p->addr + p->size + c->align - 1) & ~(c->align - 1));
        }
        h[4] = (s32)(B[list[cnt - 1]].addr + B[list[cnt - 1]].size);
    } else {
        HBlk *f = &B[list[0]];
        heap_move(f, ((u32)h[5] - f->size) & ~(f->align - 1));
        for (k = 1; k < cnt; k++) {
            HBlk *p = &B[list[k - 1]], *c = &B[list[k]];
            heap_move(c, (p->addr - c->size) & ~(c->align - 1));
        }
        h[4] = (s32)B[list[cnt - 1]].addr;
    }
}

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
extern void func_00418CC0(void);

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

void func_00415590(int dsti, int poli, int fmt, int fmt_list)
{
    u8 *dst = (u8 *)(uintptr_t)dsti;
    u32 *pol = (u32 *)(uintptr_t)poli;
    s32 *fl = (s32 *)(uintptr_t)fmt_list;
    int use_default = fl == 0, s6 = 0;
    u32 s5 = pol[0];
    s32 n = (s16)func_003F1950((int)s5), base, k, j, i;
    u8 *meshes, *mats, clay[0x40], mark[8];
    u32 tree;
    s32 nn, nr;
    u8 *nodes;
    u32 *roots;

    base = EE_BSS(s32, 0x004C2898);
    if (base + n >= 0x340)
        return;
    *(s16 *)(dst + 0x12) = (s16)base;
    *(s16 *)(dst + 0x10) = (s16)n;
    meshes = (u8 *)EE_BSS_PTR(0x004F9170) + base * 0xB4;
    *(u8 **)(dst + 0x14) = meshes;
    EE_BSS(s32, 0x004C2898) = base + n;
    mats = *(u8 **)(dst + 4);
    for (i = 0; i < n; i++) {
        *(s32 *)(meshes + i * 0xB4 + 0xC) = func_003F1E10((void *)(uintptr_t)s5, i);
        func_003F1E70((void *)(uintptr_t)s5, i, meshes + i * 0xB4 + 0x10);
    }
    for (k = 0; k < n; k++) {
        u8 *m = meshes + k * 0xB4;
        s32 st1;
        *(u32 *)(m + 4) = ((u32 *)(uintptr_t)pol[2])[k];
        *(u32 *)(m + 8) = 0;
        func_00415A00((int)*(u32 *)(m + 4));
        for (j = 0; (u32)j < *(u32 *)(m + 0xC); j++)
            func_003DF850(0x39 + j, (int)(uintptr_t)(mats + ((u32 *)(m + 0x10))[j] * 0x4C));
        st1 = func_003DFF80(1);
        if (st1 && func_003DFF80(0x15) == 1)
            func_003DF850(1, 0);
        func_003DCF90(mark);
        if (func_003F2A50(clay, (int)s5, (u32)k)) {
            int a1;
            if (!use_default) {
                a1 = fl[0];
                if (++s6 >= fl[1]) {
                    s6 = 0;
                    fl += 2;
                }
                if (fl[1] < 0)
                    use_default = 1;
            } else {
                a1 = fmt;
            }
            *(s32 *)m = func_003EE6F0(clay, (u32)a1);
            func_0041B3C0(m + 0x90, clay, *(s32 *)m);
        } else {
            *(s32 *)m = -1;
        }
        func_003DCFB0(mark);
        if (st1)
            func_003DF850(1, st1);
    }

    tree = pol[1];
    nn = (s16)func_003F13A0((void *)(uintptr_t)tree);
    base = EE_BSS(s32, 0x004C289C);
    if (base + nn >= 0x340)
        return;
    *(s16 *)(dst + 0xA) = (s16)base;
    *(s16 *)(dst + 8) = (s16)nn;
    nodes = (u8 *)EE_BSS_PTR(0x0051DA70) + base * 0x190;
    *(u8 **)(dst + 0xC) = nodes;
    EE_BSS(s32, 0x004C289C) = base + nn;
    nr = (s16)func_003F13E0((void *)(uintptr_t)tree);
    base = EE_BSS(s32, 0x004C2894);
    if (base + nr >= 0x340)
        return;
    *(s32 *)(dst + 0x18) = nr;
    roots = (u32 *)EE_BSS_PTR(0x004F8470) + base;
    *(u32 **)(dst + 0x1C) = roots;
    EE_BSS(s32, 0x004C2894) = base + nr;
    for (k = 0; k < nr; k++) {
        u8 st[0x10];
        void *(*alloc)(int) = *(void *(**)(int))EE_BSS_PTR(0x004C2B0C);
        int sz, s3, cnt;
        void *buf;
        func_003DCF90(mark);
        sz = func_003F16D0((void *)(uintptr_t)tree, k);
        buf = alloc(sz);
        func_003F1730(st, buf, (void *)(uintptr_t)tree, k);
        s3 = func_003DE7E0(st);
        func_003DCFB0(mark);
        func_003DE880((int)(uintptr_t)nodes, s3, 0, 0);
        *roots++ = (u32)(uintptr_t)nodes;
        cnt = func_003DEC90(s3);
        nodes += cnt * 0x190;
        func_003DE860(s3);
    }
}

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

void func_00422150(int strp, int posp, int x, int y, float scale)
{
    u8 *p = (u8 *)(uintptr_t)strp;
    s32 *pos = (s32 *)(uintptr_t)posp;
    int started = 0, sp_w = 0, ofs, texslot = 0;
    u32 ca = 0xFF, cr = 0xFF, cg = 0xFF, cb = 0xFF;
    s32 s0 = 0, s1 = 0;
    float f20 = 0.f;
#define NEXT() (p[(*pos)++])
#define CUR(a) EE_BSS(s32, a)
    ofs = NEXT();
    while (!started) {
        u32 c = NEXT(), t;
        switch (c) {
        case 1:
            t = NEXT() << 8;
            CUR(0x004C2BB0) = (s32)(t + NEXT());
            s0 = CUR(0x004C2BB0);
            t = NEXT() << 8;
            CUR(0x004C2BAC) = (s32)(t + NEXT());
            s1 = CUR(0x004C2BAC);
            f20 = (float)NEXT() / 256.0f;
            started = 1;
            break;
        case 5: sp_w = NEXT(); break;
        case 6: ca = NEXT(); break;
        case 7: cr = NEXT(); break;
        case 8: cg = NEXT(); break;
        case 9: cb = NEXT(); break;
        case 11: texslot = NEXT(); break;
        case 12: *pos += 2; break;
        default: break;
        }
    }
    s0 += x;
    s1 += y;
    if (f20 != -1.0f)
        f20 = scale;
    for (;;) {
        u32 c = NEXT();
        s32 *g, dy = 0, rect[4], w, h, color;
        float uv[4];
        if (c == 1) {
            u32 t = NEXT() << 8;
            CUR(0x004C2BB0) = (s32)(t + NEXT());
            s0 = CUR(0x004C2BB0);
            *pos += 3;
            continue;
        }
        if (c == 5) { s0 += sp_w; continue; }
        if (c == 13) { s0 += 8; continue; }
        if (c == 0) {
            CUR(0x004C2BA4) = 0;
            CUR(0x004C2BA8) = 0;
            CUR(0x004C2BAC) = 0;
            CUR(0x004C2BB0) = 0;
            return;
        }
        if (c == 4) {
            s32 v = CUR(0x004C2BA8) + NEXT();
            CUR(0x004C2BA4) = 0;
            CUR(0x004C2BA8) = 0;
            s1 += v;
            continue;
        }
        if (c == 10) {
            g = data_s32x4_004A7F80 + 4 * NEXT();
        } else {
            if (c == 0x3A)
                dy = -2;
            g = data_s32x4_004A6F80 + 4 * (c & 0xFF);
        }
        uv[0] = (float)g[0] / 512.0f;
        uv[1] = (float)g[1] / 512.0f;
        uv[2] = (float)g[2] / 512.0f;
        uv[3] = (float)g[3] / 512.0f;
        w = g[2] - g[0];
        h = g[3] - g[1];
        rect[0] = s0 + CUR(0x004C2BA4);
        rect[1] = s1 + dy;
        CUR(0x004C2BA4) += w + ofs;
        rect[2] = rect[0] + w;
        rect[3] = rect[1] + h;
        if (CUR(0x004C2BA8) < h)
            CUR(0x004C2BA8) = h;
        color = (s32)((ca & 0xFF) << 24 | (cr & 0xFF) << 16 | (cg & 0xFF) << 8 | (cb & 0xFF));
        if (EE_BSS(u8, 0x004F7F52) != 0)
            func_00422BE0(); /* colour hook (empty in the retail build) */
        func_00421FB0(f20, (int)((u32 *)EE_BSS_PTR(0x0057FB70))[texslot], rect, uv, color);
    }
#undef NEXT
#undef CUR
}

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

/* func_003F01B0: the textures a clay still needs in VRAM.  For each of the
 * clay's materials (count +0x28, material numbers +0x50[]) it records the
 * material's texture handle (D_0061B420 + m * 0x4C, +0x44) in +0x70[], and
 * appends it once to the upload list +0xF0[] (count +0x2C) unless the
 * texture record (D_006207A0) and, for a paletted handle, the palette record
 * (D_0061C7A0) are both resident (state 3).  C from the asm. */
void func_003F01B0(int a0, int a1)
{
    u8 *c = (u8 *)(uintptr_t)a0;
    s32 i, k, n;
    (void)a1;
    *(s32 *)(c + 0x2C) = 0;
    for (i = 0; i < *(s32 *)(c + 0x28); i++) {
        u8 m = c[0x50 + i];
        u32 h = *(u32 *)((u8 *)EE_BSS_PTR(0x0061B420) + m * 0x4C + 0x44);
        u32 pal = h >> 16;
        s32 ts;
        *(u32 *)(c + 0x70 + 4 * i) = 0;
        if (!h)
            continue;
        *(u32 *)(c + 0x70 + 4 * i) = h;
        n = *(s32 *)(c + 0x2C);
        for (k = 0; k < n; k++)
            if (*(u32 *)(c + 0xF0 + 4 * k) == h)
                break;
        if (k < n)
            continue;
        ts = *(s32 *)((u8 *)EE_BSS_PTR(0x006207A0) + ((h & 0xFFFF) - 1) * 64);
        if (pal == 0) {
            if (ts == 3)
                continue;
        } else if (ts == 3 && *(s32 *)((u8 *)EE_BSS_PTR(0x0061C7A0) + (pal - 1) * 64) == 3) {
            continue;
        }
        n = *(s32 *)(c + 0x2C);
        *(s32 *)(c + 0x2C) = n + 1;
        *(u32 *)(c + 0xF0 + 4 * n) = h;
    }
}

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

void func_00176360(int a0, int a1, int a2)
{
    const u16 *src = (const u16 *)(uintptr_t)a1;
    s32 slot = -1, d[18], i;
    u32 col[16];
    (void)a2;
    for (i = 0; i < 6; i++) {
        if (a0 < data_s8_004ACD08[i])
            continue;
        if (i < 5 && !(a0 < data_s8_004ACD08[i + 1]))
            continue;
        slot = D_00446BF0[i];
        a0 -= data_s8_004ACD08[i];
        break;
    }
    if (slot == -1)
        return;
    for (i = 0; i < 16; i++) {
        u32 c = src[i], a = ((c & 0xF000) >> 12) << 28;
        if (a == 0xF0000000u)
            a = 0xFF000000u;
        col[i] = a | (c & 0xF) << 4 | ((c & 0xF0) >> 4) << 12 | ((c & 0xF00) >> 8) << 20;
    }
    d[0] = 0;    d[1] = 0x10; d[2] = 1;    d[3] = 0x40;
    d[4] = (s32)(uintptr_t)col;
    d[5] = 4;    d[6] = 8;    d[7] = 0x10; d[8] = 0xFF;
    d[9] = 8;    d[10] = 8;   d[11] = 0xFF; d[12] = 8;
    d[13] = 0;   d[14] = 0xFF; d[15] = 8;   d[16] = 0x18; d[17] = 0xFF;
    func_00413C00(*(s32 *)((u8 *)EE_BSS_PTR(0x0063248C) + slot * 20), a0, (int)(uintptr_t)d);
}

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

int func_003EBF30(int a0, int a1, int a2)
{
    u8 *req = (u8 *)(uintptr_t)a0, *v = EE_BSS(u8 *, 0x004C2AB4), *last = v;
    const u32 *h = (const u32 *)(uintptr_t)a1;
    s32 size = *(s16 *)(req + 0x10);
    if (!v)
        return 0;
    for (; v; v = *(u8 **)(v + 4)) {
        u8 *t1, *t5;
        s32 kind = *(s32 *)(v + 0x10), start;
        last = v;
        if (kind != 1 && kind != 4)
            continue;
        if (vram_owned_by(v, h, a2))
            continue;
        t1 = v;
        start = *(s16 *)(t1 + 0x14);
        t5 = *(u8 **)(v + 4);
        if (!t5) {
            if (0x4000 - start < size)
                continue;
            return (int)(uintptr_t)v;
        }
        for (;;) {
            s32 k5;
            if (*(s16 *)(t5 + 0x14) - start >= size)
                return (int)(uintptr_t)t1;
            v = t5;                 /* the asm's $v0 follows the run */
            last = v;
            k5 = *(s32 *)(t5 + 0x10);
            if (k5 != 1 && k5 != 4)
                break;
            if (vram_owned_by(t5, h, a2))
                break;
            t5 = *(u8 **)(t5 + 4);
            if (!t5) {
                if (0x4000 - start < size)
                    break;
                return (int)(uintptr_t)t1;
            }
        }
    }
    return 0x4000 - (*(s16 *)(last + 0x14) + *(s16 *)(last + 0x16)) < size ? -1 : 1;
}

/* func_003F59C0(fmt, pt): put one pixel {s16 x, s16 y, u32 colour} into the
 * image described by fmt (func_003F5900 gives the address).  Indexed formats
 * (fmt+0 & 4) write the index at the depth fmt+0x14 (0 = 4 bit: a whole byte
 * with flag 0x40, else the nibble chosen by x & 1 and flag 0x10; 1, 2, 4
 * bytes); direct colour scales each 8-bit channel to the format's maximum
 * (r: fmt+0x38 << fmt+0x34, g: 0x2C << 0x28, b: 0x20 << 0x1C, a: 0x44 << 0x40,
 * x * max / 255 truncated) and writes 4, 3 or 2 bytes.  C from the asm. */
extern int func_003F5900(int, int, void *);

void func_003F59C0(int a0, int a1)
{
    u8 *f = (u8 *)(uintptr_t)a0, *pt = (u8 *)(uintptr_t)a1, *d;
    u32 flags, c;
    s32 bpp;
    d = (u8 *)(uintptr_t)func_003F5900(*(s16 *)pt, *(s16 *)(pt + 2), f);
    if (!d)
        return;
    flags = *(u32 *)f;
    bpp = *(s32 *)(f + 0x14);
    c = *(u32 *)(pt + 4);
    if (flags & 4) {
        switch (bpp) {
        case 4: *(u32 *)d = c; break;
        case 2: *(u16 *)d = (u16)c; break;
        case 1: *d = (u8)c; break;
        case 0:
            if (flags & 0x40)
                *d = (u8)c;
            else if (((*(s16 *)pt & 1) != 0) ^ ((flags & 0x10) != 0))
                *d = (u8)((*d & 0xF0) | (c & 0xF));
            else
                *d = (u8)((*d & 0x0F) | (c & 0xF) << 4);
            break;
        }
        return;
    } else {
        s32 g = (s32)(((c >> 8) & 0xFF) * *(u32 *)(f + 0x2C)) / 255;
        s32 b = (s32)(((c >> 16) & 0xFF) * *(u32 *)(f + 0x20)) / 255;
        s32 r = (s32)((c & 0xFF) * *(u32 *)(f + 0x38)) / 255;
        s32 a = (s32)((c >> 24) * *(u32 *)(f + 0x44)) / 255;
        u32 v = (u32)g << *(s32 *)(f + 0x28) | (u32)b << *(s32 *)(f + 0x1C) |
                (u32)r << *(s32 *)(f + 0x34) | (u32)a << *(s32 *)(f + 0x40);
        if (bpp == 4)
            *(u32 *)d = v;
        else if (bpp == 3) {
            d[0] = (u8)v;
            d[1] = (u8)(v >> 8);
            d[2] = (u8)(v >> 16);
        } else if (bpp == 2)
            *(u16 *)d = (u16)v;
    }
}

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

int func_00188860(int a0, int a1)
{
    u8 *p = (u8 *)(uintptr_t)a0, *s3, *team, *q, *g;
    u32 k = (u32)a1 & 0xFF, s4 = k, s1 = k, mask, side, any;
    s8 c;
    if (k == 1) { s3 = p + 0x26E; mask = 0x80; }
    else if (k == 2) { s3 = p + 0x26F; mask = 0x10; }
    else if (k == 3) { s3 = p + 0x25E; mask = 0x80; s4 = 1; }
    else { s3 = p + 0x25F; mask = 0x10; s4 = (k - 2) & 0xFF; }
    if (*(s8 *)(p + 0x539) == 0) {
        c = *(s8 *)s3;
        if (c == 0) {
            if (k < 3) {
                if (!(*(u16 *)(p + 0x35C) & mask))
                    return 0;
                if (!(*(u16 *)(p + 0x35E) & 0xC00))
                    *s3 = 0x10;
                return 0;
            }
            if (*(u16 *)(p + 0x35C) & mask)
                *s3 = 0x10;
            return 0;
        }
        c--;
        *(s8 *)s3 = c;
        if (c == 0)
            return 0;
        if (*(u16 *)(p + 0x354) & mask)
            return 0;
    }
    if (p[5] != 0)
        return 0;
    if (k < 3) {
        if (p[0x20D] == 3 || p[0x20D] == 2)
            return 0;
    } else {
        if (p[0x20D] == 3)
            return 0;
        if (p[0x20D] == 2 && p[0x210] != 0)
            return 0;
        if (p[0x1E4] == 0x14 && p[0x213] == 2)
            return 0;
    }
    side = p[2];
    g = EE_BSS(u8 *, 0x004C2840);
    team = EE_BSS(u8 *, 0x004C2794) + (side ^ 1) * 12;
    any = (*(u8 **)(team + 0x18))[0x28B] | (*(u8 **)(team + 0x1C))[0x28B] | (*(u8 **)(team + 0x20))[0x28B];
    if (*(s8 *)(g + 0xBA) == 0 && (any & 0xFF))
        return 0;
    if (EE_BSS(u8, 0x004D18A0) >= 5)
        return 0;
    if (*(s8 *)(g + 0xB9) != 0)
        return 0;
    if (*(s8 *)(g + 0xBA) == 0 && *(s8 *)((u8 *)EE_BSS_PTR(0x004D18D4) + side) >= 2)
        return 0;
    if (*(s8 *)(p + 0x205) != 0)
        return 0;
    team = EE_BSS(u8 *, 0x004C2794) + side * 12 + 0x18;
    q = *(u8 **)(team + (s4 & 0xFF) * 4);
    if (q[0] != 0 || *(s16 *)(q + 0x2B4) != 0)
        return 0;
    if (!func_0018A580(p))
        return 0;
    team = EE_BSS(u8 *, 0x004C2794) + p[2] * 12 + 0x18;
    if (*(s16 *)(*(u8 **)(team + (s4 & 0xFF) * 4) + 0x434) == 0) {
        /* that partner cannot come: try the other one */
        s1 = (((k - 1) ^ 1) + 1) & 0xFF;
        s4 = ((((u32)(s32)(s8)s4 - 1) ^ 1) + 1) & 0xFF;
        q = *(u8 **)(team + s4 * 4);
        if (q[0] != 0 || *(s16 *)(q + 0x2B4) != 0 || *(s16 *)(q + 0x434) == 0)
            return 0;
    }
    if ((s1 & 0xFF) < 3) {
        p[0x26B] = (u8)s4;
        func_00186A60(p, 0x1C);
        p[7] = 0;
        p[6] = 0;
        p[0x26A] = p[0x20D] == 2 ? 1 : 0;
    } else {
        p[0x26B] = (u8)s4;
        p[0x2B0] = 0xFF;
    }
    *s3 = 0;
    return 1;
}
