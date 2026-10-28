/* s8f: MW 3.0, ./try30.sh src/s8f_b.c "-O3 -Op -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct NQ73B_A {
    u8 pad0[0x34];
    f32 f34;
    u8 pad38[0x140 - 0x38];
    s16 h140;
    u8 pad142[0x180 - 0x142];
    s16 *w180;
    u8 pad184[0x4A4 - 0x184];
    f32 f4a4;
} NQ73B_A;

typedef struct NQ73B_R {
    u8 pad0[0x10];
    u8 b10;
    u8 b11;
} NQ73B_R;

s32 func_0016A5A0(NQ73B_A *p, NQ73B_A *q, NQ73B_R *r, s32 n)
{
    extern s32 func_0016A6D0(NQ73B_A *, NQ73B_A *, s32);
    s16 *t;
    f32 f;
    f32 d;
    f32 e;
    f32 z;

    if (n == 0) return 0;
    t = q->w180;
    t += n * 4;
    f = 1.6666666269302368f * (f32)(t[0] - t[1]);
    if (q->h140 & 1) f = -f;
    f += q->f34;
    e = p->f34;
    d = e;
    if (p->h140 & 1) {
        d = f;
        f = e;
    }
    f = d - f;
    z = 0.0f;
    if (f <= z) {
        if (func_0016A6D0(p, q, r->b10)) return 1;
        if (func_0016A6D0(p, q, r->b11)) return 1;
    } else if (!(p->f4a4 <= f)) {
        p->f4a4 = f;
        return 2;
    }
    return 0;
}
