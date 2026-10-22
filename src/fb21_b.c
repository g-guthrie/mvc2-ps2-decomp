typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct BS {
    u8 _p0[0x2];
    u8 b2;
    u8 _p1[0x3];
    u8 b6;
    u8 _p2[0x2D];
    f32 f34;
    f32 f38;
    u8 _p3[0x20];
    f32 f5c;
    f32 f60;
    u8 _p4[0x4];
    f32 f68;
    f32 f6c;
    u8 _p5[0xE0];
    s8 b150;
    s8 b151;
    u8 _p6[0x60];
    u8 b1b2;
    u8 _p7[0x2];
    u8 b1b5;
    u8 _p8[0xA];
    u16 h1c0;
    u8 _p9[0x16];
    u32 w1d8;
    u8 _p10[0x31];
    u8 b20d;
    u8 _p11[0x5B];
    u8 b269;
    u8 _p12[0x4E];
    u32 w2b8;
    u8 _p13[0x7F];
    u8 b33b;
    u8 b33c;
    u8 _p14[0xC7];
    u8 b404;
    u8 b405;
    u8 _p15[0x6];
    u8 b40c;
    u8 b40d;
    u8 _p16[0x22];
    f32 f430;
} BS;

typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G_b;
extern G_b *D_004C2794;

void func_002F0830(BS *p)
{
    extern void func_00185490(BS *);
    extern void func_00183D10(BS *);
    extern void func_001757E0(BS *, s32, s32);
    extern void func_001E3210(BS *, s32);
    extern s8 func_00175700();
    extern s32 func_00184540(BS *);
    extern void func_002F1DF0();
    extern void func_003A82E0(BS *, s32);
    extern void func_001D6B50(BS *, s32);
    extern void func_00175C00(BS *, s32);
    extern void func_001830D0(BS *, u32 *, s32);
    u32 t;
    s32 n;
    u32 v[4];

    if (p->b6 == 0) {
        if (p->b269 == 6) {
            p->b404 = 0xFF;
            p->b405 = 0x10;
        }
        t = p->b6;
        p->b6 = t + 1;
        func_00185490(p);
        p->b1b5 = 0x34;
        p->b1b2 = p->h1c0 = 0;
        p->w1d8 = 0;
        D_004C2794->f7c[p->b2]++;
        if (p->b20d != 2) {
            p->b20d = 0;
            p->f38 = p->f430;
            func_00183D10(p);
            p->f5c = 0;
            n = 0;
            p->f60 = 0;
            p->f68 = 0;
            p->f6c = 0;
        } else {
            p->f5c /= 16.0f;
            p->f60 /= 8.0f;
            p->f6c /= 64.0f;
            n = 0xE;
            p->f68 = 0;
        }
        func_001757E0(p, 0x15, n & 0xFF);
        func_001E3210(p, 4);
    }
    p->b40c = 2;
    p->b33c = 5;
    p->b405 = (p->b269 == 6) ? 2 : 0;
    if (!(p->f38 < p->f430 - 102.85713958740234f)) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
    }
    if (func_00175700(p) < 0) {
        p->b40d = 0;
        p->b40c = 0;
        p->b33b = 0;
        p->b33c = 0;
        if (p->b20d == 2) {
            func_00184540(p);
            return;
        }
        func_002F1DF0(p);
        return;
    }
    if (p->b151 != 0) {
        p->b151 = 0;
        func_003A82E0(p, 1);
        func_003A82E0(p, 2);
        func_003A82E0(p, 3);
        func_001D6B50(p, 0);
        func_001E3210(p, 0x20);
    }
    if (p->b150 != 0) {
        p->b404 = 0;
        p->b405 = 0;
        p->b150 = 0;
        func_00175C00(p, 1);
        p->w2b8 = 0;
        v[0] = 0x4226AAAA;
        v[1] = 0x433A6DB6;
        if (p->b20d == 2) {
            v[0] = 0xC0D55555;
            v[1] = 0x4382B6DB;
        }
        func_001830D0(p, v, 1);
    }
}
