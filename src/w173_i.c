#include "action_record.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern const void * const D_00456930[4];
extern Mvc2ActionRecord D_004560D0[];

void func_0028A2A0(u8 *p)
{
    extern s32 func_0028D8B0(u8 *);
    extern void func_00131AB0(u8 *, u8 *, s32);
    extern s32 func_00174170();
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_003888B0(u8 *, s32);
    extern void func_0028D810(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    u8 *s;
    p[0x40C] = 2;
    s = p + 0x2B8;
    p[0x33C] = 5;
    if (func_0028D8B0(p) == 0) {
        p[6]++;
        s[0xA] = 0;
        s[0x19] = 0;
        *(s16 *)(s + 0x1E) = 0xB4;
        func_00131AB0(p, s + 0x1E, 6);
        *(void **)(s + 0x14) = (void *)D_00456930[func_00174170() & 3];
        s[0x1B] = 1;
        func_00185490(p);
        func_00175C00(p, 0);
        func_003888B0(p, 0);
        func_003888B0(p, 1);
        func_003888B0(p, 3);
        func_003888B0(p, 4);
        func_0028D810(p, (u8 *)D_004560D0);
        func_001757E0(p, 0x16, 8);
        func_001E3210(p, 0x1E);
    }
}
