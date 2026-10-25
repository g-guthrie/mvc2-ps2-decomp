#include "model_callback_api.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Raw frame address, two frame indices, and their interpolation fraction. */
typedef struct { s32 framesAddress,first,second; f32 blend; } L0033A700;
extern u8 *D_004C283C;
extern s32 D_004C28AC;
extern void func_0033A760(u8 *, u8 *, s32);
void func_0033A700(u8 *p, s32 a1, s32 a2, f32 f) {
    L0033A700 l;
    u8 *o = *(u8 **)(p + 0x84);
    l.framesAddress = D_004C28AC + 0x41000;
    l.first = a1;
    l.second = a2;
    l.blend = f;
    func_00170E60(
        (EL_d *)(u32)*(s32 *)(D_004C283C + 0x14),
        (ND_d *)(u32)*(s32 *)(*(u8 **)(o + 0x1C) + 4),
        (EL_d *)(u32)*(s32 *)(o + 0x14),
        (ND_d *)(u32)*(s32 *)(*(u8 **)(o + 0x1C) + 4),
        func_0033A760, (s32)&l);
}
extern u8 *D_004C2794;
void func_0031DEC0(u8 *p) {
    u32 v = p[0x15B];
    if (v != 0) {
        s8 w = v;
        s32 x = *(s8 *)(p + 0x1B7) * 2 + 0x4B;
        p[0x1B5] = x + w;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        *(s16 *)(((u32)p[2] << 1) + (u32)D_004C2794 + 0x7C) += 1;
        p[0x15B] = 0;
    }
}
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0032F970();
void func_0032F980(s32 a) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0032F970;
        *(s16 *)(o + 0xCC) = a;
        *(u8 **)(o + 0x84) = D_004C283C;
        *(u32 *)(o + 0xD0) = 0x800800;
    }
}
extern void func_00356450();
void func_003563E0(u8 *p) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o != 0) {
        *(void **)(o + 0x10) = func_00356450;
        o[0x20] = 1;
        *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[1] = p[1];
        *(s16 *)(o + 0x26) = 0x901;
    }
}
extern u8 D_004C0C28[8];
void func_002AA0E0(u8 *p) {
    if (*(s8 *)(p + 0x151) != 0) {
        if (*(s8 *)(p + 0x1B2) != 0) *(s16 *)(p + 0x1C) += 1;
        if (*(s16 *)(p + 0x1C) < 3) {
            p[0x1B5] = D_004C0C28[*(s8 *)(p + 0x151) >> 1];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            *(s16 *)(((u32)p[2] << 1) + (u32)D_004C2794 + 0x7C) += 1;
        }
    }
}
