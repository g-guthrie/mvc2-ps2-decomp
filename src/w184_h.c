typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[4]; u8 b4; u8 pad5[0x1C - 5];
    s16 h1c, h1e; u8 pad20[0x34 - 0x20];
    f32 f34, f38; u8 pad3c[0x50 - 0x3C];
    f32 f50, f54, f58, f5c, f60;
    u8 pad64[0x68 - 0x64];
    f32 f68, f6c;
    u8 pad70[0x13C - 0x70];
    u8 b13c;
} S;

void func_00371FD0(S *p)
{
    extern void func_00175700(S *);
    extern f32 func_00417440(u16);
    f32 one = 1.0f;
    f32 k;
    s16 v;
    s16 w;
    if (p->f50 > one) {
        p->f50 = one;
        p->f54 = one;
    } else {
        k = 0.04f;
        p->f50 += k;
        p->f54 += k;
    }
    func_00175700(p);
    v = p->h1c;
    p->h1c = v - 1;
    if (v == 0) {
        p->b4++;
        p->b13c = 0;
    } else {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        p->f38 += 5.0f * func_00417440((u16)((u32)(s32)(65536.0 * (double)p->h1e / 360.0 + 0.5)));
        w = p->h1e - 6;
        p->h1e = w;
        if (w == 0) {
            p->h1e = 0x168;
        }
    }
}
