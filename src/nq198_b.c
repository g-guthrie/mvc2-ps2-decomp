#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef float f32;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
typedef struct { u8 pad[0x7C]; s16 count[2]; } Counters;
typedef struct { f32 a, b; } Pair;
extern Counters *D_004C2794;
extern Pair D_00472340[];
#define OWNER (*(u8**)(p+0x18))
void residual_00394DC0(u8 *p)
{
    extern void func_001757E0(u8 *, int, int);
    extern void func_00395040(u8 *);
    u8 *o;
    u32 t;
    u8 *c2;
    f32 c;
    f32 v;

    t = p[4];
    o = OWNER;
    p[4] = t + 1;
    *(Fields*)(p+0xEC)=*(Fields*)(OWNER+0xEC);
    p[0x13C]=1;
    c2 = p + 2;
    p[2]=OWNER[2];p[1]=OWNER[1];
    *(float*)(p+0x50)=*(float*)(OWNER+0x50);*(float*)(p+0x54)=*(float*)(OWNER+0x54);
    p[0x1B7]=OWNER[0x1B7];p[0x1B8]=OWNER[0x1B8];p[0x30]=*(s8*)(OWNER+0x30);
    *(V3*)(p+0x50)=*(V3*)(OWNER+0x50);p[0x24]=*(s8*)(OWNER+0x24);
    *(s16*)(p+0x140)=*(s16*)(OWNER+0x140);
    p[0x1B0]=0x42;p[0x1B1]=0x42;
    *(float*)(p+0x34)=*(float*)(OWNER+0x34);*(float*)(p+0x38)=*(float*)(OWNER+0x38);
    if (OWNER[0x1E6] != 0) {
        c = 156.66665649414062f;
    } else {
        c = -156.66665649414062f;
    }
    *(f32 *)(p + 0x34) += c;
    *(f32 *)(p + 0x38) += 259.28570556640625f;
    p[0x14E]=0x40;p[0x14F]=0x40;
    p[0x24]=0;
    if (o[0x269] == 3) {
        p[0x1B5] = 0x53;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
        ++D_004C2794->count[*c2];
    } else {
        p[0x1B5] = p[0x1B7] ? 0x44 : 0x42;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
        ++D_004C2794->count[*c2];
    }
    if (*(s16 *)(p + 0x140) != 0) {
        v = D_00472340[p[0x1B7]].a;
    } else {
        v = -D_00472340[p[0x1B7]].a;
    }
    *(f32 *)(p + 0x5C) = v;
    *(f32 *)(p + 0x60) = D_00472340[p[0x1B7]].b;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x14, 5);
    func_00395040(p);
}
