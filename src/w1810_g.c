typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {
    u8 p0[6]; u8 b6; u8 p7[0x15]; s16 h1c; u8 p1e[0x16]; f32 f34; f32 f38; u8 p3c[0x20]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c;
    u8 p70[0xF4]; u8 b164; u8 p165[3]; u8 b168; u8 p169[0x4]; u8 b16d_; u8 p16e[0x91]; u8 b1ff; u8 p200[0xD]; u8 b20d; u8 p20e[3]; s8 b211;
    u8 p212[0x35]; u8 b247; u8 p248[4]; u8 b24c; u8 p24d[0x3F]; s16 h28c; u8 p28e[0x1A6]; s16 h434;
} P;
void func_0017DC00(P *p) {
    extern void func_00175700(P *);
    extern void func_001E3A10(P *);
    extern void func_00163D70(P *);
    extern void func_00178E60(P *);
    extern s32 func_001864a0(P *);
    extern void func_001757E0(P *, s32, s32);
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->b211 != 0) {
        if (p->b24c == 0) {
            p->b24c = 1;
            func_001E3A10(p);
            func_00163D70(p);
        }
    }
    if (p->h1c == 0) {
        f32 z = 0.0f;
        if (p->f60 <= z) {
            p->h1c = 1;
            func_00178E60(p);
        }
    }
    if (func_001864a0(p) != 0) {
        p->b1ff = 2;
        p->h28c = 5;
        p->b6++;
        p->b168 = 0x1B;
        if (p->b247 != 1 || p->h434 == 0) {
            p->b6++;
            p->b168 = 0x1A;
            p->b20d = 3;
        }
        func_001757E0(p, 0xD, p->b168);
    }
}
