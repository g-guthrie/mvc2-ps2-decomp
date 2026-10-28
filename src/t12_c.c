typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189150(u8 *p);
extern void func_00186A60(u8 *p, s32 n);
#include "actor_selector_api.h"
extern void func_0018CC30(u8 *p, u8 r);
extern void func_0018CCD0(u8 *p, u8 r);
extern void func_0018CD70(u8 *p, u8 r);
extern void func_0018CBB0(u8 *p, u8 r);
extern void func_0018CA30(u8 *p, u8 r);
extern u8 D_0045AEB0[];
extern s32 func_00189310(u8 *p, u8 *a, u8 *b);
extern void func_0018A990(u8 *p, u8 *q);

s32 func_002E4310(u8 *p) {
    u8 *q = (u8 *)((s32)p + 0x2B8);
    if (func_00189150(p) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (*(s8 *)(q + 9) != 0) return 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 0x1D);
    return 1;
}

void func_0018C970(u8 *p, u8 *q) {
    u32 f;
    u8 r;
    *(u16 *)(p + 0x1C2) = *(u16 *)(q + 0x1C0);
    r = func_0018E970((G18E970 *)p);
    f = *(u16 *)(q + 0x1C0);
    if (f & 0x10) {
        func_0018CC30(p, r);
    } else if (f & 0x1000) {
        func_0018CCD0(p, r);
    } else if (f & 0x20) {
        func_0018CD70(p, r);
    } else if ((*(u8 **)(p + 0x1D0))[1] & 0x40) {
        func_0018CBB0(p, r);
    } else {
        func_0018CA30(p, r);
    }
}

s32 func_002E0FB0(u8 *p) {
    if (func_00189310(p, D_0045AEB0, p + 0x380) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        if (*(s8 *)(p + 0x1E8) != 0) return 0;
        p[0x1E8] = *(s8 *)(p + 0x1E8) + 1;
    }
    if (**(s8 **)(p + 0x420) == 0) return 0;
    func_0018A990(p, &p[0x380]);
    p[5] = 0;
    func_00186A60(p, 0x1D);
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    p[0x213] = 0;
    return 1;
}
