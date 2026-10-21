#include "mvc2_record_triplet.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 D_004D18A1[];
extern u8 D_004540A0[];

extern s32 func_00175700(u8 *);
extern s32 func_00175910(u8 *p, s32 a, s32 b, s32 c);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_003CAB20(void *p, void *q, s32 a);
extern void func_00169BC0(void *p, s32 a);
extern void func_00169E50(void *p, s32 a, s32 b);
extern s32 func_0016A250(void *p);
extern void func_00169AE0(void *p, s32 a);
extern void func_001AD170(void *p, s32 a, u8 b);
extern s32 func_00189950(void *p, void *a, void *b);
extern s32 func_0018A580(void *p);
extern void func_0018A990(void *p, void *q);
extern void func_00186A60(void *p, s32 a);

void func_001A0010(u8 *p, u8 *q, u8 *r) {
    s8 v;
    *(s8 *)(p + 0x24) = *(s8 *)(r + 0x24);
    *(s8 *)(p + 0x31) = -4;
    *(s16 *)(p + 0x140) = *(s16 *)(r + 0x140);
    v = *(s8 *)(r + 0x161);
    if (v != 0) {
        p[0x13C] = 1;
        *(V3 *)(p + 0x34) = *(V3 *)(r + 0x34);
        q[0] = 1;
        func_00175910(p, 0x17, (u8)(v + 0x26), *(s8 *)(r + 0x151));
        return;
    }
    if (q[0] != 0) {
        s8 r2 = func_00175700(p);
        if (r2 < 0) {
            p[0x13C] = 0;
            q[0] = 0;
        }
    }
}

void func_003CBE60(u8 *p, u8 *q) {
    if (p[6] == 0) {
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
            u32 t = p[6];
            p[6] = t + 1;
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
            func_001757E0(p, 0x17, 0x2E);
        }
    } else {
        s8 r = func_00175700(p);
        if (r < 0) func_003CAB20(p, q, 0xB);
    }
}

void func_00250A80(u8 *p, u8 *q) {
    f32 d;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x1C) = (p[0x1B7] != 0) ? 0x1E : 0xF;
        *(s16 *)(p + 0x1E) = *(s8 *)(q + 0xE) + 1;
        p[0x22] = 1;
        q[7] = 0;
        if (p[0x1E6] != 0) {
            d = 13.33333302f;
        } else {
            d = -13.33333302f;
        }
        *(f32 *)(p + 0x5C) = d;
        func_001AD170(p, 3, ((*(s8 *)(q + 0xE) != 0) ? 1 : 0) + 2);
    }
}

