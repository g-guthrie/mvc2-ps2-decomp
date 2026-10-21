#include "action_record.h"
/* Initialize the actor's timed state and five attached effect slots. */
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern const void * const D_00456A20[4];
extern Mvc2ActionRecord D_00456290[];

void func_0028B4D0(u8 *p) {
    extern s32 func_0028D8B0();
    extern void func_00131AB0();
    extern s32 func_00174170();
    extern void func_00185490();
    extern void func_00175C00();
    extern void func_003892F0();
    extern void func_0028D810(u8 *, u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    u8 *q;
    u32 t;
    p[0x40C] = 2;
    q = p + 0x2B8;
    p[0x33C] = 5;
    if (func_0028D8B0(p) == 0) {
        t = p[6];
        p[6] = t + 1;
        q[0xA] = 0;
        q[0x19] = 0;
        q[0x1C] = 0;
        p[0x215] = 1;
        *(s16 *)(q + 0x1E) = 0xB4;
        func_00131AB0(p, q + 0x1E, 6);
        *(void **)(q + 0x14) = (void *)D_00456A20[func_00174170() & 3];
        q[0x1B] = 1;
        func_00185490(p);
        func_00175C00(p, 0);
        func_003892F0(p, 0);
        func_003892F0(p, 1);
        func_003892F0(p, 2);
        func_003892F0(p, 3);
        func_003892F0(p, 4);
        func_0028D810(p, (u8 *)D_00456290);
        func_001757E0(p, 0x16, 0x12);
    }
}
