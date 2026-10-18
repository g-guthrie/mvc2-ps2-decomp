typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f[13]; } T53;
typedef struct { f32 f0, f4, f8, fC, f10; s32 f14; u8 pad[0x3C]; f32 f54, f58, f5C, f60, f64; } Q53;

extern s8 D_0057ED70[];
extern s32 D_0057FB70[];

void func_00153D20(s32 a0, Q53 *q, s32 idx)
{
    extern f32 func_00153E60(f32);
    extern void func_003DF850(s32, s32);
    extern void func_003EA660(s32, s32 *);
    extern void func_003DF490(T53 *);
    T53 t;
    s32 v;
    f32 *p1, *p2;
    f32 r;
    v = D_0057FB70[D_0057ED70[idx]];
    r = func_00153E60(-q->f8);
    func_003DF850(0x62, 0x10000);
    func_003DF850(0x63, 0x20000);
    func_003EA660(1, &v);
    func_003DF850(4, v);
    p1 = &t.f[1];
    p2 = &t.f[5];
    t.f[0] = q->f0;
    t.f[4] = q->f54;
    *p1 = q->f4;
    *p2 = q->f58;
    *p1 -= 16.0f;
    *p2 -= 16.0f;
    t.f[6] = r;
    t.f[7] = 1.0f;
    t.f[2] = r;
    t.f[3] = 1.0f;
    *(s32 *)&t.f[8] = q->f14;
    t.f[9] = q->fC;
    t.f[10] = 1.0f - q->f10;
    t.f[11] = q->f60 ;
    t.f[12] = 1.0f - q->f64;
    func_003DF490(&t);
    func_003DF850(0x62, 0);
    func_003DF850(0x63, 0);
}
