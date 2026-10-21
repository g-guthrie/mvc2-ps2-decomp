#pragma padloop on
/* Child actors inherit the complete 0xc4-byte state region [0xec,0x1b0).
 * FC and 100 are existing float fields; other bytes are retained opaquely. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"
extern s16 D_004C27A4 __attribute__((section(".sdata")));
extern u8 *func_003DA750(u8 *, s32, s32);
extern int func_001757E0(u8 *, s32, s32);
extern int func_001754A0(u8 *, s32, s32);
extern void func_001E3710(u8 *, s32);
extern void func_003AE900(u8 *);
extern void func_003C06A0(u8 *);
extern void func_003C0940(u8 *);
extern void func_003C0B30(u8 *);

void func_003AF890(u8 *a, u8 *b, u8 *c)
{
    s16 *src;
    s32 i;
    u8 *v;
    s16 *dst;

    if (D_004C27A4 >= 2) {
        src = (s16 *)(b + 0x88);
        i = 0;
        do {
            v = func_003DA750(b, 1, 2);
            dst = (s16 *)(v + 0x88);
            *(void (**)(u8 *))(v + 0x10) = func_003AE900;

            v[0x20] = 1;
            *(u8 **)(v + 0x18) = c;
            *(u8 **)(v + 0x14) = a;
            v[0x22] = b[0x22];
            *(ActorState *)(v + 0xec) = *(ActorState *)(b + 0xec);
            v[0x13C] = 1;
            i++;
            v[2] = b[2];
            v[1] = b[1];
            *(f32 *)(v + 0x50) = *(f32 *)(b + 0x50);
            *(f32 *)(v + 0x54) = *(f32 *)(b + 0x54);
            v[0x1B7] = b[0x1B7];
            v[0x1B8] = b[0x1B8];
            *(s8 *)(v + 0x30) = *(s8 *)(b + 0x30);
            *(V3 *)(v + 0x50) = *(V3 *)(b + 0x50);
            *(s8 *)(v + 0x24) = *(s8 *)(b + 0x24);
            *(s8 *)(v + 0x31) = -1;
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
        } while (i < 2);
        *(s8 *)(a + 0xB0) = *(s8 *)(a + 0xB0) + 2;
    }
}

void func_003C0560(u8 *owner, u8 kind)
{
    u8 *p;
    u8 *o;
    if ((p = func_003DA750(owner, 1, 2)) != 0) {
        s32 tag = 0x3604;
        *(void (**)(u8 *))(p + 0x10) = &func_003C06A0;
        *(u8 **)(p + 0x18) = owner;
        p[1] = owner[1];
        p[0x20] = kind;
        *(s16 *)(p + 0x26) = (s16)tag;
        *(u8 **)(p + 0xD8) = *(u8 **)(owner + 0xD8);
        o = *(u8 **)(owner + 0xD8);
        *(ActorState *)(p + 0xec) = *(ActorState *)(o + 0xec);
        p[0x13C] = 1;
        o = *(u8 **)(owner + 0xD8);
        p[2] = o[2];
        o = *(u8 **)(owner + 0xD8);
        p[1] = o[1];
        o = *(u8 **)(owner + 0xD8);
        *(f32 *)(p + 0x50) = *(f32 *)(o + 0x50);
        o = *(u8 **)(owner + 0xD8);
        *(f32 *)(p + 0x54) = *(f32 *)(o + 0x54);
        o = *(u8 **)(owner + 0xD8);
        p[0x1B7] = o[0x1B7];
        o = *(u8 **)(owner + 0xD8);
        p[0x1B8] = o[0x1B8];
        o = *(u8 **)(owner + 0xD8);
        *(s8 *)(p + 0x30) = *(s8 *)(o + 0x30);
        o = *(u8 **)(owner + 0xD8);
        *(V3 *)(p + 0x50) = *(V3 *)(o + 0x50);
        o = *(u8 **)(owner + 0xD8);
        *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
        p[0x13C] = 1;
        *(s16 *)(p + 0x140) = 0;
        p[0x24] = 8;
        func_001754A0(p, 0x1B, 0xF);
    }
}

void func_003C0800(u8 *owner)
{
    u8 *p;
    u8 *o;
    if ((p = func_003DA750(owner, 1, 2)) != 0) {
        s32 tag = 0x3604;
        *(void (**)(u8 *))(p + 0x10) = func_003C0940;
        *(u8 **)(p + 0x18) = owner;
        p[1] = owner[1];
        *(s16 *)(p + 0x26) = (s16)tag;
        *(u8 **)(p + 0xD8) = *(u8 **)(owner + 0xD8);
        o = *(u8 **)(owner + 0xD8);
        *(ActorState *)(p + 0xec) = *(ActorState *)(o + 0xec);
        p[0x13C] = 1;
        o = *(u8 **)(owner + 0xD8);
        p[2] = o[2];
        o = *(u8 **)(owner + 0xD8);
        p[1] = o[1];
        o = *(u8 **)(owner + 0xD8);
        *(f32 *)(p + 0x50) = *(f32 *)(o + 0x50);
        o = *(u8 **)(owner + 0xD8);
        *(f32 *)(p + 0x54) = *(f32 *)(o + 0x54);
        o = *(u8 **)(owner + 0xD8);
        p[0x1B7] = o[0x1B7];
        o = *(u8 **)(owner + 0xD8);
        p[0x1B8] = o[0x1B8];
        o = *(u8 **)(owner + 0xD8);
        *(s8 *)(p + 0x30) = *(s8 *)(o + 0x30);
        o = *(u8 **)(owner + 0xD8);
        *(V3 *)(p + 0x50) = *(V3 *)(o + 0x50);
        o = *(u8 **)(owner + 0xD8);
        *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
        p[0x13C] = 1;
        *(s8 *)(p + 0x31) = -1;
        *(f32 *)(p + 0x68) = 40.0f;
        *(f32 *)(p + 0x6C) = 342.85711669921875f;
        func_001757E0(p, 0x16, 0x14);
    }
}

void func_003C09C0(u8 *owner)
{
    u8 *p;
    u8 *o;
    if ((p = func_003DA750(0, 1, 0)) != 0) {
        s32 tag = 0x3604;
        *(void (**)(u8 *))(p + 0x10) = func_003C0B30;

        *(u8 **)(p + 0x18) = owner;

        p[1] = owner[1];
        *(s16 *)(p + 0x26) = (s16)tag;
        *(u8 **)(p + 0xD8) = *(u8 **)(owner + 0xD8);
        o = *(u8 **)(owner + 0xD8);

        *(ActorState *)(p + 0xec) = *(ActorState *)(o + 0xec);
        p[0x13C] = 1;
        o = *(u8 **)(owner + 0xD8);
        p[2] = o[2];
        o = *(u8 **)(owner + 0xD8);
        p[1] = o[1];
        o = *(u8 **)(owner + 0xD8);
        *(f32 *)(p + 0x50) = *(f32 *)(o + 0x50);
        o = *(u8 **)(owner + 0xD8);
        *(f32 *)(p + 0x54) = *(f32 *)(o + 0x54);
        o = *(u8 **)(owner + 0xD8);
        p[0x1B7] = o[0x1B7];
        o = *(u8 **)(owner + 0xD8);
        p[0x1B8] = o[0x1B8];
        o = *(u8 **)(owner + 0xD8);
        *(s8 *)(p + 0x30) = *(s8 *)(o + 0x30);
        o = *(u8 **)(owner + 0xD8);
        *(V3 *)(p + 0x50) = *(V3 *)(o + 0x50);
        o = *(u8 **)(owner + 0xD8);
        *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
        p[0x13C] = 1;
        *(s16 *)(p + 0x1E) = 0x20;
        p[0x24] = 8;
        *(V3 *)(p + 0x34) = *(V3 *)(owner + 0x34);
        func_001757E0(p, 0x16, 0x16);
        func_001E3710(p, 9);
    }
}

extern void func_003CAA20(u8 *);
extern void func_003CAB20(u8 *, u8 *, s32);

u8 *func_003CA7E0(u8 *owner, u8 kind)
{
    u8 *p;
    if ((p = func_003DA750(0, 1, 1)) != 0) {
        s32 tag = 0x3a01;
        *(void (**)(u8 *))(p + 0x10) = &func_003CAA20;
        *(u8 **)(p + 0x18) = owner;
        p[1] = owner[1];
        *(s16 *)(p + 0x26) = (s16)tag;
        p[0x20] = kind;
        *(ActorState *)(p + 0xec) = *(ActorState *)(owner + 0xec);
        p[0x13C] = 1;
        p[2] = owner[2];
        p[1] = owner[1];
        *(f32 *)(p + 0x50) = *(f32 *)(owner + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(owner + 0x54);
        p[0x1B7] = owner[0x1B7];
        p[0x1B8] = owner[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(owner + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(owner + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(owner + 0x24);

        p[0x24] = 8;
        func_003CAB20(p, owner, 1);
    }
    return p;
}
