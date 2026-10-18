typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct Q { u8 p0[0x1C]; s16 h1c; u8 p1e[0x16]; f32 f34; f32 f38; } Q;
typedef struct P {
    u8 p0[6]; u8 b6; u8 p7[0xD]; struct Q *q14; u8 p18[8]; u8 b20; u8 p21[0x13];
    f32 f34; f32 f38; u8 p3c[0xC]; s32 w48; u8 p4c[0xF4]; s16 h140; u8 p142[0xF];
    u8 b151; u8 p152[0x1EA]; u8 b33C; u8 p33d[0xCF]; u8 b40C;
} P;
void func_002663E0(P *p) {
    extern s8 func_00175700(P *);
    extern void func_001B3E30(P *, s32, s32);
    Q *q;
    f32 c;
    p->b40C = 2;
    p->b33C = 5;
    p->w48 = 0x4000;
    if (func_00175700(p) < 0) {
        p->b151 = 0;
        p->b6++;
        p->w48 = 0;
        q = p->q14;
        q->h1c--;
        p->f34 = q->f34;
        if (p->h140 != 0) c = -13.333333015441895f; else c = 13.333333015441895f;
        p->f34 += c;
        p->f38 = 137.14285278320312f + q->f38;
        switch (p->b20) {
        case 0x18: func_001B3E30(p, 0x12, 5); break;
        case 0x14: func_001B3E30(p, 0x11, 5); break;
        case 0x10: func_001B3E30(p, 0x10, 5); break;
        }
    }
}
