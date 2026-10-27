typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[2]; u8 b2; u8 p3; u8 b4; u8 b5; u8 b6; u8 b7; u8 p8[0x1C-8]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PH;

void func_001EA8F0(PH *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0(PH *, s32, s32);
    s16 h;
    f32 x, y;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700((u8 *)p);
    h = p->h1c - 1;
    p->h1c = h;
    if (h <= 0) {
        p->b6++;
        if (((u8 *)p)[0x1E6] != 0) x = 4.166666507720947f; else x = -4.166666507720947f;
        p->f5c = x;
        if (*(u8 *)((s32)p + 0x1E6) != 0) y = -0.3385416567325592f; else y = 0.3385416567325592f;
        p->f68 = y;
        func_001757E0(p, 2, 2);
    }
}
