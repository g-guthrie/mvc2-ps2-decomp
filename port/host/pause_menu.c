/*
 * func_003D6530: the pause menu's COMMAND LIST page (option 2 of the in-fight
 * pause menu, func_003D3E90 case 2 sets p[0x19] = 2 and func_003D69A0 calls
 * this with D_004F7D10).  The function has no credited C, so the port had a
 * generated empty stub: the page never animated, never returned to the menu,
 * and the fight did not resume the way the PS2's does (oracle fuzz arcade
 * seed 1000005: g+0x5C / g+0x91 stayed set).  This is the retail code
 * (0x003D6530..0x003D6810) in C, instruction for instruction:
 *
 *   p       a0 (s4)   the pause menu state D_004F7F50
 *   sides   a1 (s3)   D_004F7D10, 16-byte records per side (+0xE: shown)
 *   side    s0/s2     0 when p[0] == 1 (P1 paused), else 1
 */
#include "host.h"

typedef struct {
    u8 b[4];            /* +0 x, +1 y, +2 (width), +3 colour/style */
    char *label;        /* +4 */
} PauseRow;

extern u8 *D_004C2840;
extern u16 D_004F4484[], D_004F4490[];   /* per-side pad words, stride 20 bytes */
extern PauseRow D_004B91D0[4];           /* CONTINUE, BUTTON CONFIG, COMMAND LIST, MODE MENU */
extern PauseRow data_button_config_render_004B9208[37];
extern void func_003D7310(void *);
extern void func_003D7350(unsigned char, unsigned char, unsigned char, const char *, ...); /* variadic: wasm passes a varargs pointer */
extern void func_001E3CE0(int);
extern int func_001315E0(void); /* src/simple_leaves.c: returns 64 */
extern int func_00119098(float);         /* fptoui */
extern void func_003D3750(void);
extern void func_003D4630(void);

#define PAD(base, side) (*(u16 *)((u8 *)(base) + (side) * 20))
#define SHOWN(sides, i) (*(s16 *)((sides) + (i) * 16 + 0xE))

void func_003D6530(int a0, int a1)
{
    u8 *p = (u8 *)(uintptr_t)a0;
    u8 *sides = (u8 *)(uintptr_t)a1;
    s32 side;
    s8 old;
    u32 m;

    D_004C2840[0x91] = 1;
    *(u32 *)(p + 0x10) = 0x42A00000u;   /* 80.0f */
    *(u32 *)(p + 0x14) = 0x42B00000u;   /* 88.0f */
    side = (*(s8 *)p == 1) ? 0 : 1;

    if (*(s8 *)(p + 0xC) == 0) {
        s16 h = *(s16 *)(p + 0xA);
        if (h != 0) {
            *(s16 *)(p + 0xA) = (s16)(h - 1);
            func_003D7310((void *)func_003D3750);
            return;
        }
        p[0xC] = 1;
        p[0x2E] = SHOWN(sides, side) == 0 ? 1 : 0;
        func_003D7310((void *)func_003D3750);
        return;
    }

    old = *(s8 *)(p + 0x2E);
    if ((PAD(D_004F4484, side) | PAD(D_004F4490, side)) & 0x2000)
        p[0x2E] = (u8)(old - 1);
    if ((PAD(D_004F4490, side) | PAD(D_004F4484, side)) & 0x1000)
        p[0x2E] = (u8)(*(s8 *)(p + 0x2E) + 1);
    p[0x2E] = (u8)((*(s8 *)(p + 0x2E) + 2) % 2);
    p[0xF] = (u8)(*(s8 *)(p + 0x2E) + 5);
    if (old != *(s8 *)(p + 0x2E))
        func_001E3CE0(1);

    m = (u32)func_001315E0() & 0xFFFF; /* takes no arguments */
    if (m & PAD(D_004F4484, side)) {
        if (*(s8 *)(p + 0x2E) == 0) {
            *(s16 *)(p + 0x2C) = (s16)(side + 1);
            SHOWN(sides, side) = 1;
            SHOWN(sides, side != 0 ? 0 : 1) = 0;
        } else {
            *(s16 *)(p + 0x2C) = 0;
            SHOWN(sides, side) = 0;
        }
        *(s16 *)(p + 0x2A) = 0;
        p[0x19] = 0;
        p[0xC] = 0;
        p[0x2E] = 0;
        *(s16 *)(p + 0x8) = 0x4650;
        *(s16 *)(p + 0xA) = 10;
        *(u32 *)(p + 0x10) = 0x42A00000u;
        *(u32 *)(p + 0x14) = 0x42B00000u;
        func_001E3CE0(2);
    }

    if (*(s8 *)(p + 0xC) != 0) {
        PauseRow *e = &D_004B91D0[2];            /* D_004B91E0 */
        PauseRow *r = &data_button_config_render_004B9208[35];   /* D_004B9320 */
        int i;
        func_003D7350(e->b[0], (unsigned char)func_00119098((float)e->b[1] - 16.0f), e->b[3], e->label);
        for (i = 0; i < 2; i++, r++)
            func_003D7350(r->b[0], r->b[1], r->b[3], r->label);
        func_003D7310((void *)func_003D4630);
    }
    func_003D7310((void *)func_003D3750);
}
