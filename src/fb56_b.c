#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"
typedef struct {u8 prefix[0x7c];s16 count[2];} GameState;
extern GameState *D_004C2794;
extern u16 D_004C1E98[4];

void func_003A1BD0(u8 *p, u8 *q)
{
    extern s32 func_001757E0(u8 *, s32, s32);
    extern s32 func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_003DAA40(u8 *);
    p[0x13C] = 0;
    if (p[4] == 0) {
        p[4]++;
        *(ActorState *)(p + 0xEC) = *(ActorState *)(q + 0xEC);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        p[0x1B0] = 0x43;
        p[0x1B1] = 0;
        p[0x1B4] = 0;
        p[0x1B2] = 0;
        p[0x1B5] = 0x30 + ((s8 *)p)[0x1B7] * 2;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        { s32 x = p[2]; s16 y = D_004C2794->count[x]; D_004C2794->count[x] = y + 1; }
        func_001757E0(p, 0x14, ((u8 *)D_004C1E98)[p[0x1B7] * 2]);
        ((s8 *)p)[0x31] = -8;
        *(u32 *)(p + 0xD0) = *(u16 *)(q + 0x168);
    }
    ((s8 *)p)[0x24] = ((s8 *)q)[0x24];
    if (q[5] == 0 && *(s32 *)(p + 0xD0) == *(u16 *)(q + 0x168)) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        if (((s8 *)p)[0x1B2] == 0) {
            if ((s8)func_00175700(p) >= 0) {
                func_001E7F60(p);
                return;
            }
        }
    }
    if (p[0x20] == 0) q[0x2C4] = 0;
    func_003DAA40(p);
}
