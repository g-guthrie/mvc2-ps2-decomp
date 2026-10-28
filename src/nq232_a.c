typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#include "data/button_config_render.h"
typedef ButtonConfigRenderRecord Ent;

typedef struct { u16 b; u8 pad[18]; } E20;
extern E20 D_004F4484[];
extern E20 D_004F4490[];
extern Ent D_004B91D0[];
extern u8 D_004B9368[];

void func_003D4C10(s8 *a, s8 *p) {
    s32 s1;
    s8 *s2;
    s8 old = p[0];
    u16 r16;
    extern void func_001E3CE0(s32);
    extern s32 func_001315E0(s32);
    extern void func_003D4B70(s8 *);
    extern void func_003D47E0(void);
    extern void func_0016EDA0(s32, s32);
    extern void func_003D4AD0(s8 *, s32, s32);
    extern void func_003D7350(u8, u8, u8, u32, ...);

    if (((D_004F4484[p[1]].b | D_004F4490[p[1]].b) & 0x2000) != 0) {
        p[0] = old - 1;
    }
    if (((D_004F4484[p[1]].b | D_004F4490[p[1]].b) & 0x1000) != 0) {
        p[0] = p[0] + 1;
    }
    p[0] = (p[0] + 12) % 12;
    if (old != p[0]) {
        func_001E3CE0(1);
    }
    switch (p[0]) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        p[0xC] = 0x16;
        s1 = 0xC;
        s2 = p + p[0] + 4;
        break;
    case 8:
        p[0xC] = 0x22;
        s1 = 2;
        s2 = p + 2;
        break;
    case 9:
        p[0xC] = 0x24;
        s1 = 2;
        s2 = p + 3;
        break;
    case 10:
        p[0xC] = 0x12;
        s1 = -1;
        r16 = func_001315E0(p[1]);
        if ((r16 & D_004F4484[p[1]].b) != 0) {
            func_003D4B70(p);
            func_001E3CE0(2);
        }
        break;
    case 11:
        p[0xC] = 0x13;
        s1 = -1;
        r16 = func_001315E0(p[1]);
        if ((r16 & D_004F4484[p[1]].b) != 0) {
            a[0x19] = 0;
            a[0x1A] = 0;
            func_001E3CE0(2);
        }
        break;
    }
    if (s1 > 0) {
        s8 o = *s2;
        if (((D_004F4484[p[1]].b | D_004F4490[p[1]].b) & 0x800) != 0) {
            *s2 = o - 1;
        }
        if (((D_004F4484[p[1]].b | D_004F4490[p[1]].b) & 0x400) != 0) {
            *s2 = *s2 + 1;
        }
        *s2 = (*s2 + s1) % s1;
        if (o != *s2) {
            func_003D47E0();
            func_001E3CE0(4);
            if (p[0] == 8 && *s2 != 0) {
                func_0016EDA0(p[1], 8);
            }
        }
        p[0xC] = p[0xC] + *s2;
    }
    if (a[0x1A] != 0) {
        s32 i;
        s32 j;
        Ent *e;
        func_003D7350(p[1] * 0x35 + 0x1E, 0x24, p[1] + 0x20, (u32)D_004B9368, p[1] + 1);
        func_003D4AD0(p, 0xC, 8);
        func_003D4AD0(p, 0x26, 4);
        i = 0;
        j = 0;
        do {
            e = &D_004B91D0[p[i + 4] + 0x16];
            func_003D7350(e->rendererArgs[0] + p[1] * 0x35, e->rendererArgs[1] + j, e->rendererArgs[3] + i, (u32)e->resource);
            i++;
            j += 4;
        } while (i < 8);
        e = &D_004B91D0[p[2] + 0x22];
        func_003D7350(e->rendererArgs[0] + p[1] * 0x35, e->rendererArgs[1], e->rendererArgs[3], (u32)e->resource);
        e = &D_004B91D0[p[3] + 0x24];
        func_003D7350(e->rendererArgs[0] + p[1] * 0x35, e->rendererArgs[1], e->rendererArgs[3], (u32)e->resource);
    }
}
