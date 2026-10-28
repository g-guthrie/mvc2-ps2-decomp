typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* MW 3.0: ./try30.sh src/r3_22_a.c "-O3 -Op -sdatathreshold 8" */
typedef struct { u8 _p0[0xA]; s16 h0A; u8 _p1[0x22]; u32 w30; u32 w34; } G40;
typedef struct { f32 x, y, z, w; } E4;
typedef struct {
    u8 b0;
    u8 _p0[0x1B];
    s16 h1C;
    u8 _p1[6];
    s8 b24;
    u8 b25;
    u8 _p2[0xE];
    f32 f34, f38, f3C;
    u8 _p3[4];
    s32 w44;
    u8 _p4[8];
    f32 f50, f54, f58;
    u8 _p5[0x18];
    f32 f74, f78, f7C, f80;
    u8 _p6[0x4C];
    s32 wD0;
    u8 _p7[0x68];
    u8 b13C;
} O;

extern G40 *D_004C2840;
extern s32 D_004C2640;
extern u8 D_004C27C0;
extern u8 D_004C27C4;
extern u8 D_004CAC50[];
extern O *D_004CACE4[];
extern u8 D_004410A0[];
extern u8 D_004410C0[];
extern E4 D_00440CF0[];

void func_00142320(void)
{
    extern void func_00416AE0(s32);
    extern void func_00416F80(u8 *);
    extern void func_00416CC0(s32);
    extern void func_00417DA0(f32 *, f32 *);
    extern void func_001E6610(s32, s32);
    E4 *s0;
    s32 s1;
    u32 s2, s3;
    s32 s4;
    s32 t;
    O *o;
    f32 v[3];
    f32 w[2];
    f32 k;
    s32 bit;
    func_00416AE0(0);
    func_00416F80(D_004CAC50);
    s2 = D_004C2840->w30;
    s3 = D_004C2840->w34;
    if (D_004C2640 < 0x1C) {
        s1 = D_004C2640 % 5;
        if (D_004C2840->h0A >= 0x41A)
            t = D_004410A0[D_004C2640];
        else
            t = D_004410C0[D_004C2640];
        s4 = t & 0xFF;
        s0 = &D_00440CF0[s4];
        v[0] = 10.0f * s0->x;
        v[1] = 10.0f * s0->y;
        v[2] = 10.0f * s0->z;
        if (D_004C2840->h0A >= 0x41A)
            k = -5.0f;
        else if (D_004C2640 == 13 || D_004C2640 == 27)
            k = 12.0f;
        else
            k = 6.0f;
        v[0] += k;
        func_00417DA0(v, w);
        if ((D_004C2840->h0A >= 0x41A && w[0] <= 640.0f) || (D_004C2840->h0A < 0x41A && w[0] >= 0.0f)) {
            o = D_004CACE4[s1];
            D_004C27C4 = 1;
            D_004C27C0 = s1 + 6;
            func_001E6610(s1, s4);
            o->b0 = 1;
            o->b13C = 1;
            o->f34 = 10.0f * s0->x;
            o->f38 = 10.0f * s0->y;
            o->f3C = 10.0f * s0->z;
            o->f50 = o->f54 = o->f58 = s0->w;
            o->b24 = 0x3C - D_004C2640;
            o->wD0 = 0x200000;
            if (D_004C2840->h0A >= 0x41A)
                o->w44 = 0x10F2;
            else
                o->w44 = 0x6EB7;
            switch (s4) { case 0: default: if (s4 < 0x20) bit = (s2 & (1 << s4)) ? 1 : 0; else bit = (s3 & (1 << (s4 - 0x20))) ? 1 : 0; break; }
            o->f74 = o->f78 = o->f7C = o->f80 = (f32)bit;
            o->b25 = 0;
            o->h1C = 0;
            D_004C2640 = D_004C2640 + 1;
        }
    }
    func_00416CC0(1);
}
