/* MW 3.0.3 or 3.0, "-O3 -Op -fp off -sdatathreshold 8", 4/79 words differ: post-call temps $a1/$a0 where retail $a3/$a2 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x1C];
    s16 h1C;
    u8 pad1E[0x20 - 0x1E];
    u8 b20;
    u8 pad21[0x78 - 0x21];
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0xCC - 0x84];
    s16 hCC;
    u8 padCE[0xD0 - 0xCE];
    u32 wD0;
    u8 padD4[0xE0 - 0xD4];
    s32 wE0;
    f32 fE4;
} S33E7A0;

extern s32 D_004C283C;

void func_0033E7A0(S33E7A0 *p) {
    extern s32 func_00153AA0(S33E7A0 *);
    extern void func_00170DA0(s32, s32, s32, s16);
    extern f32 func_00417440(s32);

    s16 h = p->h1C + 1;
    f32 v;
    p->h1C = h;
    if (p->h1C >= 1000) p->h1C = 0;
    func_00170DA0(D_004C283C, p->b20 * 2 + 10, func_00153AA0(p), p->hCC);
    p->wE0 = 0;
    p->fE4 = 0.001f * (f32)(-p->h1C);
    p->wD0 |= 0x20000;
    v = func_00417440((s32)(0.5 + 65536.0 * (double)(3600.0f * (f32)p->h1C / 1000.0f) / 360.0) & 0xFFFF);
    v = 0.25f + 0.25f * v;
    p->f78 = v;
    p->f7C = v;
    p->f80 = p->f78;
}
