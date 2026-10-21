#include "action_record.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00289130(u8 *p) {
    extern void func_00175700();
    extern void func_0028D810(u8 *, u8 *);
    extern void func_0028D8B0();
    extern void func_001C09A0();
    extern void func_00385EE0();
    extern Mvc2ActionRecord D_00455CF0[];
    func_00175700();
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        func_0028D810(p, (u8 *)D_00455CF0);
        func_0028D8B0(p);
        func_001C09A0(p, 3);
        func_00385EE0(p, 0);
    }
}

void func_001E87D0(void) {
    extern void func_003DA6F0();
    func_003DA6F0(0x22);
    func_003DA6F0(0x24);
    func_003DA6F0(0x26);
    func_003DA6F0(0x28);
    func_003DA6F0(0x2B);
    func_003DA6F0(0x34);
    func_003DA6F0(0x13);
    func_003DA6F0(0x1B);
    func_003DA6F0(0x20);
    func_003DA6F0(0x21);
    func_003DA6F0(0x2A);
    func_003DA6F0(0x2C);
    func_003DA6F0(0x2D);
    func_003DA6F0(0x2E);
    func_003DA6F0(0x2F);
    func_003DA6F0(0x30);
    func_003DA6F0(0x31);
    func_003DA6F0(0x32);
    func_003DA6F0(0x33);
    func_003DA6F0(0x36);
}

void func_00283EB0(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_001757E0();
    extern s32 func_0018AB10();
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (q[1] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001757E0(p, 0x16, 4);
    }
    if (q[2] != 0) {
        if (func_0018AB10(p) != 0) {
            u32 t = q[2];
            u8 v = t - 1;
            q[2] = v;
            if ((v & 1) == 0) {
                s32 h = *(s16 *)(p + 0x1E);
                *(s16 *)(p + 0x1E) = h + 1;
            }
        }
    }
}

void func_00122CD0(u32 *a0, u32 *a1, u32 *a2) {
    extern s32 D_004F1CF0;
    extern u8 D_004F1CF4, D_004F1CF5, D_004F1CF6;
    extern u8 D_004F1CF8, D_004F1CF9, D_004F1CFA;
    extern u8 D_004F1CFC, D_004F1CFD, D_004F1CFE;
    switch (D_004F1CF0) {
    case 3:
        *a2 = D_004F1CFC | ((D_004F1CFE << 16) | (D_004F1CFD << 8));
    case 2:
    case 1:
        *a1 = D_004F1CF8 | ((D_004F1CFA << 16) | (D_004F1CF9 << 8));
    case 0:
        *a0 = D_004F1CF4 | ((D_004F1CF6 << 16) | (D_004F1CF5 << 8));
    }
}

void func_00230E70(u8 *p, u8 *q) {
    extern void func_00230DA0();
    extern void func_00230D30();
    extern void func_00175700();
    extern s32 func_001864A0();
    s32 v = *(s8 *)(p + 0x1B2);
    if (v < 0) {
        if ((v & 0x7F) == 0) {
            func_00230DA0(p);
            return;
        }
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00230D30(p, q);
    } else {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            if (func_001864A0(p) != 0)
                func_00230D30(p, q);
        }
    }
}

void func_00212BA0(u8 *p, u8 *q) {
    extern void func_00212DE0();
    extern s8 func_00175700();
    extern void func_00212E50();
    extern s32 func_0018AB10();
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    q[4] = 0xFF;
    func_00212DE0(p, q);
    if (func_00175700(p) < 0)
        func_00212E50(p, q);
    if (*(s8 *)(q + 5) != 0) {
        if (func_0018AB10(p) != 0) {
            s32 t = *(s8 *)(q + 5);
            q[5] = t - 1;
            *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        }
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 8;
        q[1] = 0;
    }
}

void func_0017EE80(u8 *p) {
    extern void func_001843A0();
    extern void func_00184540();
    s32 a, b;
    if (p[6] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x40;
        p[0x24D] = *(s8 *)(p + 0x246);
    }
    p[0x209] = 0;
    a = *(s8 *)(p + 0x24D) - 1;
    *(s8 *)(p + 0x24D) = a;
    b = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = b;
    if (*(s8 *)(p + 0x24D) != 0 || *(s16 *)(p + 0x1C) != 0)
        return;
    if (p[0x20D] != 2)
        func_001843A0();
    else
        func_00184540();
}
