typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/sa9_a.c */

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x184]; u8 *f184; } Q17D;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad1[3];
    u8 b6;
    u8 pad2[0x34 - 7];
    f32 f34;
    f32 f38;
    u8 pad3[0x48 - 0x3C];
    u32 f48;
    u8 pad4[4];
    V3 f50;
    u8 pad5[0x118 - 0x5C];
    u32 f118;
    u8 pad6[0x13C - 0x11C];
    u8 b13C;
    u8 pad7[3];
    s16 h140;
    u8 pad8[0x1B4 - 0x142];
    u8 b1B4, b1B5;
    u8 pad9[0x1D0 - 0x1B6];
    u8 *f1D0;
    u8 pad10[0x1DC - 0x1D4];
    Q17D *f1DC;
    u8 pad11[0x1E6 - 0x1E0];
    u8 b1E6;
    u8 pad12[0x20D - 0x1E7];
    u8 b20D;
    u8 pad13[0x24E - 0x20E];
    s8 b24E;
    u8 pad14[0x298 - 0x24F];
    V3 f298;
    u8 pad15[0x430 - 0x2A4];
    f32 f430;
} S17D;

void func_0017DEC0(S17D *p)
{
    extern void func_00191430();
    extern void func_0018F730(S17D *, u8 *);
    extern void func_001E3A10(S17D *);
    extern void func_00158C70(f32 *, s32);
    extern void func_00186CE0(S17D *, s32);
    u32 t;
    t = p->b6;
    if (t == 0) {
        p->b6 = t + 1;
        p->b24E = p->b24E + 2;
        func_00191430();
    }
    {
        u8 *b = p->f1DC->f184;
        p->f1D0 = b + (p->b1B5 & 0x7F) * 28;
        func_0018F730(p, b);
    }
    p->h140 = p->b1E6;
    p->b20D = 2;
    func_001E3A10(p);
    t = p->f1D0[5];
    p->f1DC->pad[0x1B4] = t;
    p->b1B4 = t;
    p->f38 = p->f430;
    func_00158C70(&p->f34, p->b2);
    p->b13C = 1;
    p->f48 = 0;
    p->f50 = p->f298;
    p->f118 = 0x3F800000;
    func_00186CE0(p, 0x17);
}
