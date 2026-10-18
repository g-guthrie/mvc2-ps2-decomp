typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Q {
    u8 pad0[6];
    u8 b6;
    u8 b7;
    u8 pad8[0x34 - 8];
    f32 f34;
    f32 f38;
} Q;

typedef struct O {
    u8 pad0[0x14];
    Q *p14;
    u8 pad18[0x21 - 0x18];
    u8 b21;
    u8 pad22[0x34 - 0x22];
    f32 f34;
    f32 f38;
    u8 pad3C[0x140 - 0x3C];
    s16 s140;
} O;

extern s16 D_00462D90[];
extern s16 D_00462D92[];

void func_00357B30(O *p) {
    u32 n;
    s32 v;
    s32 i;
    f32 a, b, c;
    v = (p->p14->b7 != 0) ? p->p14->b7 : p->p14->b6;
    n = (u8)v;
    i = p->b21;
    a = 1.6666666269302368f * (f32)D_00462D90[i * 2];
    if (p->s140 == 0) a = -a;
    b = 2.1428570747375488f * (f32)D_00462D92[i * 2];
    a *= (f32)n;
    b *= (f32)n;
    p->f34 = p->p14->f34 + a;
    p->f38 = p->p14->f38 + b;
}
