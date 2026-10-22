typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct S39 {
    u8 p0[5];
    u8 b5;
    u8 p6[0x12];
    struct S39 *owner;
    u8 p1c[0x18];
    f32 f34;
    f32 f38;
    u8 p3c[0x20];
    f32 f5c;
    f32 f60;
    u8 p64[4];
    f32 f68;
    f32 f6c;
    u8 p70[0x18];
    u32 w88[6];
    u8 pa0[0x146];
    u8 b1e6;
} S39;

extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_0039E110(S39 *p)
{
    extern s32 func_00175700(S39 *);
    extern void func_001757E0(S39 *, s32, s32);
    extern void func_001E7F60(S39 *);
    f32 *a3, *t0;
    u32 *w;
    f32 f;
    u32 v;

    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        func_00175700(p);
        p->f38 += p->f60;
        p->f60 += p->f6c;
    }
    a3 = &p->f5c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    f = 188.57142639160156f + p->owner->f38;
    t0 = &p->f68;
    if (p->f38 <= f) {
        w = p->w88;
        p->b5++;
        p->f38 = f;
        p->f34 = p->owner->f34;
        if (p->b1e6 != 0) w[5] = 0x290000;
        else w[5] = 0xFFD70000;
        v = w[5];
        p->f34 += 1.6666666269302368f * (f32)v / 65536.0f;
        *a3 = 0;
        p->f60 = 0;
        *t0 = 0;
        p->f6c = 0;
        func_001757E0(p, 0x16, 4);
    }
    if (!(p->f60 < 0.0f)) {
        if (!(p->f38 <= 702.8571166992188f + p->owner->f38))
            func_001E7F60(p);
    }
}
