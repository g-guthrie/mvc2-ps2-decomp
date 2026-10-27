#include "actor_motion_node.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004C286C;
extern u8 *D_004C2840;
extern s32 func_003299D0(void);
extern void func_003298B0(u32, s32, s32);
extern void func_004181F0(s32);
extern void func_003DA650(s32);
extern void func_00146BF0(void);
extern void func_00146C80(s32);
void func_0012A8F0(void) {
    if (func_003299D0() == 0) {
        func_003298B0(0xFF000000, 10, 0);
        func_004181F0(D_004C286C != 0 ? 0 : 1);
        func_003DA650(0xD);
        func_003DA650(0xF);
        D_004C2840[1] = 1;
        D_004C2840[2] = 0;
        D_004C2840[3] = 0;
        D_004C2840[4] = 0;
        D_004C2840[5] = 0;
        D_004C2840[6] = 0;
        D_004C2840[7] = 0;
        func_00146BF0();
        func_00146C80(0);
    }
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_00444C60;
extern s32 D_004C2838;
extern void func_00156BE0(void);
extern u8 *func_003DA750(s32, s32, s32);
void func_00156C50(u8 *p) {
    u8 *o;
    if ((o = func_003DA750(0, 0x1B, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00156BE0;
        *(s16 *)(o + 0xCC) = 0x17;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *(V3 *)(p + 0x34);
        *(s32 *)(o + 0x48) = 0x1555;
        *(V3 *)(o + 0x50) = D_00444C60;
        *(s32 *)(o + 0xD0) = 0x800199;
    }
}

typedef struct { u8 pad0[0xC]; f32 f0c; f32 f10; } C_001A4CB0;
extern s32 D_004BF740[2];
extern void func_001A4E80( void *);

extern int func_001A52F0(void *, void *);
extern void func_001A5090( void *, void *);
extern void func_001A4FB0( void *, void *);
void func_001A4CB0(u8 *a, u8 *b) {
    C_001A4CB0 *c = (C_001A4CB0 *)(b + 0x2B8);
    u32 t;
    func_001A4E80(a);
    t = a[4];
    a[4] = t + 1;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + c->f0c;
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + c->f10;
    *(s32 *)(a + 0x14) = D_004BF740[a[0x20]];
    func_001A5420((ActorMotionNode *)a);
    func_001A52F0(a, b);
    func_001A5090(a, b);
    func_001A4FB0(a, b);
}

extern void func_00157010(void);
void func_00157080(u8 *p, u8 k) {
    u8 *o;
    s32 t = (k == 9) ? 0x1C : 0x40;
    if ((o = func_003DA750(0, (u8)t, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00157010;
        *(s16 *)(o + 0xCC) = 0x18;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *(V3 *)(p + 0x34);
        *(V3 *)(o + 0x50) = D_00444C60;
        *(s32 *)(o + 0xD0) = 0x800191;
    }
}
