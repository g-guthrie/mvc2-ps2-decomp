#include "queue_request_api.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C287C;
extern s32 D_004CD1D8[];
extern u8 D_004CD1E6[];
extern void func_00418090();
extern void func_0012DA40();
extern void *func_003DA750(s32, s32, s32);

extern void func_003DCD40();
void func_001E23A0(void) {
    s32 a;
    func_00418090(5);
    a = (D_004C287C + 0x3F) & -0x40;
    if (D_004CD1D8[0] != 0x3D) {
        func_0012DA40(0x3D, a, 1);
        D_004CD1D8[0] = 0x3D;
        D_004CD1E6[0] = func_001E5870((const void *)(u32)a, 5);
        func_003DCD40(D_004C287C, 0, 4);
    }
}

extern s32 func_00175700();
extern void func_00184540();
extern void func_00126400();
extern u16 D_004C11C0[2];
void func_002F1CD0(u8 *a) {
    s8 r = func_00175700(a);
    if (r < 0) {
        func_00184540(a);
    } else {
        if (*(s8 *)(a + 0x151) < 0) {
            u8 *o;
            *(s8 *)(a + 0x151) = 0;
            *(u32 *)(a + 0x5C) = 0;
            *(u16 *)(a + 0x1C0) = D_004C11C0[*(s32 *)(a + 0x2D4)];
            o = *(u8 **)(a + 0x1DC);
            *(u8 **)(o + 0x1C8) = a;
            o[0x20A] = 1;
            o[0x1E6] = a[0x1E6];
            o[0x1B5] = 0x22;
            func_00126400(o);
        }
    }
}

extern s32 D_004C283C;
extern s16 D_004B8220[];
void func_0033A380(u8 *a) {
    s16 v = *(s16 *)(a + 0x1C) + 1;
    s16 h;
    *(s16 *)(a + 0x1C) = v;
    if (v >= 10) {
        *(s16 *)(a + 0x1C) = 0;
        a[4]++;
        a[4] &= 3;
        *(s16 *)(a + 0xCC) = *(s16 *)((u8 *)D_004B8220 + a[4] * 4);
        *(s32 *)(a + 0x84) = D_004C283C;
    }
    h = *(s16 *)(a + 0x1C);
    if (h % 2 == 0) {
        *(s8 *)(a + 0x13C) ^= 1;
    }
}

extern void func_00160F90();
extern s32 D_004C2838;
typedef struct { f32 x, y, z; } V3;
void func_00160DB0(V3 *p) {
    u8 *o = func_003DA750(0, 9, 1);
    if (o) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00160F90;
        *(s16 *)(o + 0xCC) = 0xDE;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *p;
        *(u32 *)(o + 0xD0) = 0x800025;
        *(s16 *)(o + 0x1C) = 0;
        *(f32 *)(o + 0x74) = 1.0f;
        *(u32 *)(o + 0x78) = 0;
        *(u32 *)(o + 0x7C) = 0;
        *(u32 *)(o + 0x80) = 0;
    }
}

extern void func_001319E0();
extern V3 D_0043DD28;
extern V3 D_0043DD38;
extern s32 D_004C2834;
void func_001319F0(s32 a, s32 b, s32 c) {
    u8 *o = func_003DA750(0, a, b);
    if (o) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_001319E0;
        *(s16 *)(o + 0xCC) = c;
        *(s32 *)(o + 0x84) = D_004C2834;
        *(u32 *)(o + 0xD0) = 0x1081F;
        *(V3 *)(o + 0x34) = D_0043DD28;
        *(V3 *)(o + 0x50) = D_0043DD38;
    }
}

extern u8 *D_004C2840;
extern void func_001E4480();
extern void func_001E3F50();
extern void func_001E4340();
extern void func_001E3FE0();
extern void func_003D3080();
extern void func_00126D10();
extern void func_001E3CE0();
void func_001271E0(void) {
    *(s8 *)(D_004C2840 + 0xB1) = *(s8 *)(D_004C2840 + 0x8F);
    if (*(s8 *)(D_004C2840 + 0x4C) == 7) *(s8 *)(D_004C2840 + 0xB1) = 2;
    D_004C2840[0x19] = 1;
    func_001E4480(6, 1);
    func_001E3F50(0x1B);
    func_001E4340(1);
    func_001E3FE0();
    func_003D3080(1);
    func_00126D10();
    func_003D3080(0);
    func_001E3CE0((u8)(0x46 + D_004C2840[0x10] % 3));
}
