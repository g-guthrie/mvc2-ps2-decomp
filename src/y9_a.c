typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001B2980(u8 *p) {
    extern void func_00175670();
    s16 t;
    f32 v;
    func_00175670(p);
    *(f32 *)(p + 0x118) -= 0.06f;
    v = *(f32 *)(p + 0x118);
    if (v < 0.0f) {
        *(f32 *)(p + 0x118) = 0.0f;
    }
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        u32 b = p[4];
        p[4] = b + 1;
    }
}

void func_001EA840(u8 *p) {
    extern void func_00175700();
    f32 a, b;
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) {
            a = 13.333333015441895f;
        } else {
            a = -13.333333015441895f;
        }
        *(f32 *)(p + 0x5C) = a;
        if (p[0x1E6] != 0) {
            b = -0.1302083283662796f;
        } else {
            b = 0.1302083283662796f;
        }
        *(f32 *)(p + 0x68) = b;
        *(s16 *)(p + 0x1C) = 0x18;
    }
}

void func_00241A80(u8 *p) {
    extern s8 func_00175700();
    extern void func_00185490();
    extern void func_001757E0();
    u8 *q;
    f32 c;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x1C) = 8;
        func_00185490(p);
        c = 53.33333206f;
        q = *(u8 **)(p + 0x1DC);
        if (p[0x1E6] != 0) c = -c;
        *(f32 *)(p + 0x5C) = (*(f32 *)(q + 0x34) + c - *(f32 *)(p + 0x34)) / 8.0f;
        *(f32 *)(p + 0x60) = (*(f32 *)(q + 0x38) - *(f32 *)(p + 0x38)) / 8.0f;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x16, 1);
    }
}

void func_001ECB10(u8 *p) {
    extern void func_00175700();
    extern void func_00186A20();
    extern void func_001ECF90();
    f32 a, b;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        func_00186A20(p);
        if (p[0x1E6] != 0) a = 40.0f; else a = -40.0f;
        *(f32 *)(p + 0x34) += a;
        if (p[0x1E6] != 0) b = 1.666666627f; else b = -1.666666627f;
        *(f32 *)(p + 0x5C) = b;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x422B6DB6;
        *(u32 *)(p + 0x6C) = 0xBF892492;
    }
    func_001ECF90(p);
}


void func_00311D10(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    u32 *a1, *a2;
    u32 t;
    func_00175700(p);
    a1 = (u32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a2 = (u32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *a1 = 0;
        *a2 = 0;
        *(u32 *)(p + 0x5C) = 0x40855555;
        *(u32 *)(p + 0x68) = 0xBEA6AAAA;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 2, 3);
    }
}

#include "launch_record.h"

void func_001A9070(u8 *p, u8 *q) {
    f32 z = 0.0f;
    f32 c, t;
    const LaunchRecord *e;
    u32 n;
    *(s32 *)(p + 0x48) += *(s32 *)(p + 0xD0);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    e = &D_0044B570[p[0x20]];
    if (*(f32 *)(p + 0x60) <= z) {
        c = 2.142857074737549f;
        t = *(f32 *)(q + 0x430) + c * (f32)e->targetY;
        if (*(f32 *)(p + 0x38) <= t) {
            n = p[5];
            p[5] = n + 1;
            *(s32 *)(p + 0x48) = 0;
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430) + c * (f32)e->targetY;
        }
    }
}

extern f32 D_004F1FD0;
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_00315E20(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_001E3710();
    extern void func_001DD8A0();
    f32 c;
    u32 t;
    p[0x208] = 3;
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (D_004F1FD0 <= *(f32 *)(p + 0x38)) {
        t = p[6];
        c = 480.0f;
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = c + *(f32 *)(p + 0x430);
        func_001757E0(p, 0xF, 0xB);
        *(u32 *)(p + 0x5C) = 0x41D55555;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001E3710(p, 0x2F);
        func_001DD8A0(p, 8, 2);
    }
}
