typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0;
    u8 b1;
    u8 pad[0x36];
    f32 f38;
    u8 pad2[0x14C - 0x3C];
    u8 b14C;
} G25;

extern G25 *D_004C25D4;
extern G25 *D_004C25D0;
extern f32 D_004F1FB8[];
extern f32 D_004F1FF0[];
extern f32 D_004F1FFC[];
extern u8 D_004F1FEC[];
extern u8 D_004F1FF8[];
extern void func_001269F0(u8 *, u8 *);
extern void func_001262C0(s32, s32);
extern void func_00126380(s32, s32);

void func_00125700(void)
{
    G25 *p = D_004C25D4;
    f32 a = 2.142857074737549f * (f32)(u32)p->b14C;
    G25 *q = D_004C25D0;
    f32 b = 2.142857074737549f * (f32)(u32)q->b14C;
    f32 t1;
    f32 t0;
    if (p->b1 >= 0x18 && p->b1 < 0x1B)
        a = 0.0f;
    if (q->b1 >= 0x18 && q->b1 < 0x1B)
        b = 0.0f;
    t1 = p->f38 + a;
    t0 = q->f38 + b;
    if (t1 > t0) {
        if (t1 > 350.0f)
            D_004F1FB8[0] = t1 - 350.0f;
    } else if (t0 > 350.0f) {
        t0 -= 350.0f;
        D_004F1FB8[0] = t0;
    }
    D_004F1FF0[0] = 95.0f + D_004F1FB8[0];
    func_001269F0(D_004F1FEC, D_004F1FF8);
    D_004F1FFC[0] = D_004F1FF0[0];
    func_001262C0(0, 4);
    func_00126380(0, 4);
}
