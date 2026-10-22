typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct CS {
    u8 _p0[0x2];
    u8 b2;
    u8 _p1[0x1];
    u8 b4;
    u8 _p2[0x2];
    u8 b7;
    u8 _p3[0x10];
    struct CS * own;
    s16 h1c;
    s16 h1e;
    u8 _p4[0x2];
    u8 b22;
    u8 _p5[0x11];
    f32 f34;
    f32 f38;
    u8 _p6[0x14];
    f32 f50;
    f32 f54;
    u8 _p7[0x4];
    f32 f5c;
    f32 f60;
    f32 f64;
    f32 f68;
    f32 f6c;
    f32 f70;
    u8 _p8[0x5C];
    f32 fd0;
    u8 _p9[0x68];
    u8 b13c;
    u8 _p10[0x75];
    s8 b1b2;
    u8 _p11[0x1];
    s8 b1b4;
    u8 b1b5;
    u8 _p12[0xA];
    u16 h1c0;
    u8 _p13[0x16];
    u32 w1d8;
} CS;

typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G_c;
extern G_c *D_004C2794;
extern s32 fptosi(f32);

void func_003831F0(CS *p)
{
    extern void func_001757E0(CS *, s32, s32);
    extern void func_00175910(CS *, s32, s32, s32);
    extern int func_00174470(const void *);
    extern s8 func_00175700();
    extern void func_001E7F60();
    CS *q;
    s16 v;
    s32 m;
    u32 t;
    s8 w;

    q = p->own;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->b22 == 0) {
        v = fptosi((p->fd0 - p->f34) / p->f50 / 1.6666666269302368f);
        if (v < 0) v = -v;
        if (v >= 0xE0) {
            p->b22 = 1;
            func_001757E0(p, 0x17, 0xB);
        } else {
            m = v & 0xE0;
            func_00175910(p, 0x17, 0xD, (s16)(m >> 5));
        }
    }
    p->b13c = func_00174470(p);
    switch (p->b7) {
    case 0:
        func_00175700(p);
        if (!(1.2000000476837158f * q->f50 <= p->f50))
            p->f50 += p->f64;
        if (!(1.2000000476837158f * q->f54 <= p->f54))
            p->f54 += p->f70;
        v = p->h1e - 1;
        p->h1e = v;
        if (v <= 0) {
            p->b7 = 2;
            func_001757E0(p, 0x17, 0xC);
            break;
        }
        if (p->b1b2 != 0) {
            v = p->h1c - 1;
            p->h1c = v;
            if (v <= 0) {
                p->b7 = 2;
                func_001757E0(p, 0x17, 0xC);
                break;
            }
            t = p->b7;
            p->b7 = t + 1;
        }
        func_001E7F60(p);
        break;
    case 1:
        func_00175700(p);
        if (!(1.2000000476837158f * q->f50 <= p->f50))
            p->f50 += p->f64;
        if (!(1.2000000476837158f * q->f54 <= p->f54))
            p->f54 += p->f70;
        w = p->b1b4 - 1;
        p->b1b4 = w;
        if (w > 0) break;
        t = p->b7;
        p->b7 = t - 1;
        p->b1b5 = 0x36;
        p->b1b2 = p->h1c0 = 0;
        p->w1d8 = 0;
        D_004C2794->f7c[p->b2]++;
        func_001E7F60(p);
        break;
    case 2:
        if (func_00175700(p) < 0) {
            t = p->b4;
            p->b4 = t + 1;
            p->b13c = 0;
        }
        break;
    }
}
