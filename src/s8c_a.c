/* func_00153AB0: MW 3.0 (MWCCPS2_30) -O3 -Op -sdatathreshold 8. #pragma opt_propagation off keeps
   the 0xFFFF mask and -1 index offset in registers (ori/li + and/addu), as retail does. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f[8]; s32 i8; f32 g[4]; } T53c;
typedef struct { s32 f0; f32 f4, f8, fC, f10, f14, f18, f1C, f20, f24; } Q53c;
typedef struct { u8 pad[0x18]; s16 h18, h1A; u8 pad2[0x24]; } E53c;

extern s8 D_0057ED70[];
extern s32 D_0057FB70[];
extern E53c D_006207A0[];

#pragma opt_propagation off
s32 func_00153AB0(Q53c *q, s32 flag)
{
    extern f32 func_00153E60(f32);
    extern void func_003DF850(s32, s32);
    extern void func_003EA660(s32, s32 *);
    extern void func_003DF490(T53c *);
    extern void func_003DCD40(void *, s32, s32);
    extern void func_003E9580(s32, s32, void *, s32);
    extern void func_003EA070(s32);
    s32 b[18];
    T53c t;
    s32 v; s32 i; s32 j;
    s32 *pw, *ph;
    E53c *e;
    f32 r;
    f32 a, c;
    v = D_0057FB70[D_0057ED70[q->f0]];
    func_003DCD40(b, 0, 0x48);
    if (q->f0 == 0x911) {
        i = 0xFFFF;
        func_003E9580(0, v & i, b, 3);
        func_003EA070((u16)v);
    }
    pw = &b[1];
    ph = &b[2];
    j = -1;
    e = &D_006207A0[(u16)v + j];
    *pw = e->h18;
    *ph = e->h1A;
    r = func_00153E60(-q->fC);
    func_003EA660(1, &v);
    func_003DF850(4, v);
    func_003DF850(0x63, 0x20000);
    if (flag == 0) {
        t.f[0] = q->f4;
        t.f[4] = q->f4 + q->f10 * (f32)*pw;
        t.f[1] = q->f8;
        t.f[5] = q->f8 + q->f14 * (f32)*ph;
    } else {
        a = q->f10 * (f32)*pw / 2.0f;
        c = q->f14 * (f32)*ph / 2.0f;
        t.f[0] = (320.0f + q->f4) - a;
        t.f[4] = (320.0f + q->f4) + a;
        t.f[1] = (240.0f + q->f8) - c;
        t.f[5] = (240.0f + q->f8) + c;
    }
    t.f[1] -= 16.0f;
    t.f[5] -= 16.0f;
    t.f[7] = 1.0f;
    t.f[6] = r;
    t.f[3] = 1.0f;
    t.f[2] = r;
    t.i8 = -1;
    t.g[0] = q->f18;
    t.g[1] = q->f1C;
    t.g[2] = q->f20;
    t.g[3] = q->f24;
    func_003DF490(&t);
    func_003DF850(0x63, 0);
    return 0;
}
