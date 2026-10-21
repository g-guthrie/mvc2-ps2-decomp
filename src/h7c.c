#include "owner_vertical_threshold.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;



s32 func_00184150(u8 *p, f32 x, f32 r) {
    if (func_00184110((OwnerThresholdState *)p, x)) return 1;
    {
        f32 d = *(f32 *)(p + 0x38) - *(f32 *)(*(u8 **)(p + 0x220) + 0x38);
        if (r < d) return 1;
        return 0;
    }
}
#pragma padloop on
s32 func_0014A680(s32 b, s32 n) {
    s32 r = 1;
    s32 i;
    for (i = 0; i < n; i++) r *= b;
    return r;
}
extern u8 D_0044FE40[];
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_0018A990(void *p, u8 *b);
extern void func_00186A60(void *p, s32 a);
s32 func_001FC1B0(u8 *p) {
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_0044FE40, p + 0x380) == 0) return 0;
    if (*(s8 *)(q + 0x1A) != 0) return 0;
    func_0018A990(p, &p[0x380]);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    return 1;
}
extern u8 D_0045A8F0[];
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_0018A990(void *p, u8 *b);
s32 func_002D9730(u8 *p) {
    if (func_00189310(p, D_0045A8F0, p + 0x398) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    func_0018A990(p, &p[0x398]);
    p[0x26C] = 5;
    return 1;
}
