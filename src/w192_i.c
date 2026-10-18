typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct Q { u8 pad[0x1E]; s16 h1E; u8 pad20[0x34 - 0x20]; f32 f34; } Q;
typedef struct P {
    u8 pad0[4]; u8 b4; u8 pad5[0x18 - 5]; Q *q; u8 pad1C[5]; u8 b21;
    u8 pad22[0x34 - 0x22]; f32 f34; u8 pad38[0x5C - 0x38]; f32 f5C; u8 pad60[4]; f32 f64;
    u8 pad68[0x13C - 0x68]; u8 b13C;
} P;
extern void func_00175700(P *);
extern f32 func_00117078(f32);

void func_0034C610(P *p)
{
    Q *q = p->q;
    p->f64 -= p->f5C;
    p->f34 = q->f34 + p->f64;
    func_00175700(p);
    if (func_00117078(q->f34 - p->f34) < 26.66666603088379f) {
        p->b4++;
        p->b13C = 0;
        if (p->b21 == 0) q->h1E &= ~1;
        if (p->b21 == 1) q->h1E &= ~2;
        if (p->b21 == 2) q->h1E &= ~4;
        if (p->b21 == 3) q->h1E &= ~8;
    }
}
