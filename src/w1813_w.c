typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x34]; f32 f34; } Src;
typedef struct {
    u8 pad0[5]; u8 b5; u8 pad6[0x12]; Src *src; u8 pad1c[0x18]; f32 f34; u8 pad38[0x24];
    f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0xD0]; s16 h140;
    u8 pad142[0x26]; u8 b168; u8 b169;
} S359;

void func_00359D50(S359 *p, u8 *q)
{
    extern s32 func_00118FA8(f32);
    extern void func_001757E0(S359 *, s32, s32);
    extern void func_00359C70(S359 *, u8 *);
    s32 d;
    s32 k;
    u32 t;
    Src *sp;
    t = p->b5;
    sp = p->src;
    p->b5 = t + 1;
    d = (s16)func_00118FA8(sp->f34 - p->f34);
    if (d < 0) d = (s16)-d;
    d = (s16)(d * 3 * 16 / 96 * 8);
    p->f60 = 2.1428571f * (f32)d / 256.0f;
    *(u32 *)&p->f6C = 0xBF4DB6DB;
    k = 0x500;
    if (p->h140 != 0) k = -0x500;
    p->f5C = 1.6666666f * (f32)k / 256.0f;
    p->f68 = 0;
    p->b169 = 0x17;
    p->b168 = 3;
    func_001757E0(p, *(volatile u8 *)&p->b169, *(volatile u8 *)&p->b168);
    func_00359C70(p, q);
}
