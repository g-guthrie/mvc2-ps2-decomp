typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct Q { u8 pad0[0x18]; u8 *f18; u8 pad1C[0x34 - 0x1C]; f32 f34, f38, f3C; } Q;
typedef struct P {
    u8 pad0[0x22]; u8 b22; u8 pad23; u8 b24; u8 pad25[0x34 - 0x25];
    f32 f34, f38, f3C; u8 pad40[0x5C - 0x40];
    f32 f5C, f60; u8 pad64[4]; f32 f68, f6C;
    u8 pad70[0x13C - 0x70]; u8 b13C;
} P;

void func_003BF2E0(P *p, Q *q)
{
    extern s32 func_00174170();
    extern void func_001757E0(P *, s32, s32);
    f32 d, kf, e;
    s32 k;
    u8 *r;
    p->b13C = 2;
    p->b24 = 0;
    *(V3 *)&p->f34 = *(V3 *)&q->f34;
    k = (s16)(((u32)(func_00174170() & 0xFF) * 3) >> 2) - 0x60;
    kf = (f32)k;
    e = *(f32 *)((r = q->f18) + 0x430);
    p->f5C = (q->f34 + 1.666666627f * kf - p->f34) / 12.0f;
    p->f60 = (e - p->f38) / 12.0f;
    p->f6C = 0;
    p->f68 = 0;
    func_001757E0(p, 0x16, (u8)(p->b22 + 0x3B + (func_00174170() & 3)));
}
