/* s5d: MW 3.0 WARM: mwccps2(3.0) src/nf10_b.c src/s5d_i.c -c -lang c -i src -O3 -Op -sdatathreshold 0 -fp off (driver MWWARM_30@src/nf10_b.c). Float truthiness if (s0->f10) fixes the f0/f1 order. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f0, f4, f8, fc, f10, f14, f18; } ET25;
extern ET25 D_004539E0[];

typedef struct {
    u8 p00[6];
    u8 b06;
    u8 b07;
    u8 p08[0x14];
    s16 h1C;
    s16 h1E;
    u8 p20[3];
    u8 b23;
    u8 p24[0x24];
    s32 w48;
    u8 p4C[4];
    f32 f50;
    f32 f54;
    u8 p58[4];
    f32 f5C;
    f32 f60;
    u8 p64[4];
    f32 f68;
    f32 f6C;
    u8 p70[0xD0];
    s16 h140;
    u8 p142[0x212];
    u16 h354;
} PK25;

void func_0025ECA0(PK25 *p) {
    extern void func_001B0F40(PK25 *, s32);
    extern void func_001757E0(PK25 *, s32, s32);
    ET25 *s0;
    f32 z;
    f32 x;
    s32 v;
    u32 t;
    u8 k;

    if (p->h1E < 2) {
        s0 = D_004539E0;
        z = 0.0f;
        v = (p->h354 & 0x3C00) >> 10;
        p->b23 = v;
        k = v;
        s0 += k;
        if (s0->f10) {
            t = p->b06;
            p->b06 = t + 1;
            p->h1C = 0x1E;
            p->h1E = p->h1E + 1;
            p->f5C = s0->f0;
            p->f68 = s0->f4;
            p->f60 = s0->f8;
            p->f6C = s0->fc;
            p->b07 = (u32)s0->f18;
            x = s0->f14;
            if (x >= z) {
                x = s0->f14;
            } else {
                x = (f32)p->h140;
            }
            p->h140 = (s32)x;
            func_001B0F40(p, 0);
            func_001B0F40(p, 1);
            p->w48 = 0;
            func_001757E0(p, 0x15, 1);
            p->f50 = 1.0f;
            p->f54 = 1.0800000429153442f;
        }
    }
    if (p->b23 == 5) {
        p->f50 = 1.0900000333786011f;
        p->f54 = 1.0900000333786011f;
    }
    if (p->b23 == 10) {
        p->f50 = 1.0399999618530273f;
        p->f54 = 1.0399999618530273f;
    }
    if (p->b23 == 4) {
        p->f50 = 1.0f;
        p->f54 = 1.0499999523162842f;
    }
}
