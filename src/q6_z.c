#include "action_record.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern Mvc2ActionRecord D_00455D70[];

void func_0028C4C0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_0028D810(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001830D0(u8 *, u32 *, s32);
    u8 *s0 = p + 0x2B8;
    u32 v[4];
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        s0[0xB] = 6;
        func_0028D810(p, (u8 *)D_00455D70);
        if (p[0x20D] != 2) {
            func_001757E0(p, 0x16, 1);
        } else {
            func_001757E0(p, 0x16, 2);
        }
        if (p[2] == 0) {
            func_001266A0(p, 0xD, 3);
        } else {
            func_001266A0(p, 0xD, 4);
        }
        v[0] = 0xC1555555;
        v[1] = 0x42D20000;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}
