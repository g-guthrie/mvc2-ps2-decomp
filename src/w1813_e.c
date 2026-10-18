typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[4]; u8 b4; u8 pad5[3]; u8 *p8; u8 pad_c[8]; u8 *p14; u8 pad18[0xC]; s8 b24; u8 pad25[0xF]; f32 f34; f32 f38; u8 pad3c[0x20]; s16 h[8]; } T3B;

void func_003B2750(T3B *p, T3B *q)
{
    extern void func_00175700(T3B *);
    extern s32 func_00118FA8(f32);
    s16 *h = p->h;
    u8 *a = p->p8;
    u8 *b = p->p14;
    p->b24 = q->b24;
    func_00175700(p);
    p->f34 = h[3];
    h[3] = h[2];
    h[2] = h[1];
    h[1] = h[0];
    h[0] = func_00118FA8(*(f32 *)(a + 0x34));
    p->f38 = h[7];
    h[7] = h[6];
    h[6] = h[5];
    h[5] = h[4];
    h[4] = func_00118FA8(*(f32 *)(a + 0x38));
    if (b[5] == 2) p->b4++;
}
