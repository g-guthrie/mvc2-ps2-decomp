/* func_0016E080: MW 3.0.3 "-O3 -Op -fp off -sdatathreshold 8", compiled after src/chA_a.c (func_0016D4B0, soft-float warm rule). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct {
    u8 pad0[3];
    s8 b3;
    u8 pad4[0x48];
    s8 b4C;
} GC240;
typedef struct { u8 pad[0x554]; u8 b554, b555, b556, b557; u8 pad558[0x5B8 - 0x558]; } E240c;
typedef struct {
    s32 c0;
    f32 c4, c8, cc, d0, d4;
    s32 d8, dc;
    f32 e0, e4;
    s32 e8;
    f32 ec;
    s32 f0, f4, f8, fc;
} P240c;

typedef struct { f32 x, y, z, w; } V4c240;
typedef struct { f32 x, y, z, f3, f4; u32 c; f32 f6; } V7c240;
extern GC240 *D_004C2840;
extern E240c D_004F20B0[];
extern u8 D_004B5328[], D_004B5330[], D_004B5338[], D_004B5340[], D_004B5350[], D_004B5360[], D_004B5370[];
extern f32 D_004F7FD0[];
extern f32 D_004F7FD4[];
extern f32 D_00446540[];
extern f32 D_00446580[];
extern f32 D_004466A0[];
extern f32 D_004B52F0[];
extern f32 D_004465C0[];
extern u32 D_004B52D0[];
extern f32 D_00446630[];
extern P240c D_004463C0;

void func_0016E080(void)
{
    extern void func_00123090();
    extern void func_00417FF0(s32);
    extern void func_003D7350(u8, u8, u8, u8 *, ...);
    extern void func_00417AE0(s32, f32 *);
    extern void func_00153D20(s32, f32 *, s32);
    extern void func_00417FE0(s32);
    extern s32 func_00153AB0(void *, s32);
    s32 i;
    s32 k;
    s32 jo;
    s32 j;
    s32 d;
    f32 x;
    f32 y;
    E240c *e;
    s32 mo;
    s32 noff;
    f32 c;
    s32 dd;
    V4c240 *w;
    V4c240 *w2;
    V7c240 *v;
    s32 m;
    E240c *e2;
    V7c240 *u;
    s32 n;
    f32 *t;

    if (D_004C2840->b4C != 1) return;
    if (D_004C2840->b3 != 2) return;
    func_00123090();
    func_00417FF0(0);
    func_003D7350(0x29, 0x14, 0x17, D_004B5328);
    func_003D7350(0x61, 0x14, 0x18, D_004B5328);
    func_003D7350(0x3C, 0x14, 0x17, D_004B5330);
    func_003D7350(0x74, 0x14, 0x18, D_004B5338);
    for (i = 0; i < 2; i++) {
        e = &D_004F20B0[i];
        func_003D7350(i * 0x38 + 0x25, 0x20, 0x19, D_004B5340, e->b554);
        func_003D7350(i * 0x38 + 0x25, 0x28, 0x1A, D_004B5350, e->b555);
        func_003D7350(i * 0x38 + 0x25, 0x30, 0x1B, D_004B5360, e->b556);
        func_003D7350(i * 0x38 + 0x28, 0x3A, 0x1C, D_004B5370);
    }

    w = (V4c240 *)D_00446540;
    x = D_004F7FD0[0];
    y = D_004F7FD4[0];
    D_00446540[0] = D_00446540[8] = 108.0f + x;
    D_00446540[4] = D_00446540[12] = 532.0f + x;
    D_00446540[1] = D_00446540[5] = 60.0f + y;
    D_00446540[9] = D_00446540[13] = 420.0f + y;
    func_00417AE0(4, (f32 *)w);

    w2 = (V4c240 *)D_00446580;
    w2[0].x = w2[2].x = 112.0f + D_004F7FD0[0];
    w2[1].x = w2[3].x = 528.0f + D_004F7FD0[0];
    w2[0].y = w2[1].y = 64.0f + D_004F7FD4[0];
    w2[2].y = w2[3].y = 416.0f + D_004F7FD4[0];
    func_00417AE0(4, (f32 *)w2);

    v = (V7c240 *)D_004466A0;
    t = D_004B52F0;
    v[0].x = v[2].x = D_004B52F0[0] + D_004F7FD0[0];
    v[1].x = v[3].x = D_004B52F0[1] + D_004F7FD0[0];
    v[4].x = v[6].x = D_004B52F0[2] + D_004F7FD0[0];
    v[5].x = v[7].x = D_004B52F0[3] + D_004F7FD0[0];
    *(u32 *)&v[0].f3 = 0x3F7FF972;
    *(u32 *)&v[1].f3 = 0xB8D1B717;
    *(u32 *)&v[2].f3 = 0x3F7FF972;
    *(u32 *)&v[3].f3 = 0xB8D1B717;
    for (i = 0; i < 2; i++) {
        for (j = 0, jo = 0; j < 5; j++, jo += 8) {
            v[0].y = v[1].y = v[4].y = v[5].y = D_004F7FD4[0] + *(f32 *)((u8 *)t + jo + 0x10);
            v[2].y = v[3].y = v[6].y = v[7].y = ((V4c240 *)D_004F7FD0)->y + *(f32 *)((u8 *)t + jo + 0x14);
            func_00153D20(4, (f32 *)v, 0xB);
            func_00153D20(4, (f32 *)v + 28, 0xB);
        }
        c = 224.0f;
        v[0].x += c;
        v[1].x += c;
        v[2].x += c;
        v[3].x += c;
        v[4].x += c;
        v[5].x += c;
        v[6].x += c;
        v[7].x += c;
    }

    x = D_004F7FD0[0];
    y = D_004F7FD4[0];
    u = (V7c240 *)D_004465C0;
    D_004465C0[0] = D_004465C0[14] = 136.0f + x;
    D_004465C0[7] = D_004465C0[21] = 152.0f + x;
    D_004465C0[1] = D_004465C0[8] = 256.0f + y;
    D_004465C0[15] = D_004465C0[22] = 272.0f + y;
    for (n = 0, noff = 0; n < 2; n++, noff += 0x5B8) {
        e2 = (E240c *)((u8 *)D_004F20B0 + noff);
        for (m = 0, mo = 0; m < 7; m++, mo += 4) {
            u[0].f3 = u[2].f3 = 0.25f * (f32)(m & 3);
            u[1].f3 = u[3].f3 = 0.25f * (f32)((m & 3) + 1);
            dd = m / 4;
            u[0].f4 = u[1].f4 = (f32)(1.0 - (f32)(s32)dd * 0.25f);
            u[2].f4 = u[3].f4 = (f32)(1.0 - 0.25f * (f32)(dd + 1));
            for (k = 0; k < 4; k++) {
                u[k].x += 16.0f;
                u[k].c = *(u32 *)((u8 *)D_004B52D0 + mo);
                if (e2->b557 + 1 < m && m != 6) {
                    u[k].c = 0xFF777777;
                }
            }
            func_00153D20(4, (f32 *)u, 0xB);
        }
        c = 112.0f;
        u[0].x += c;
        u[1].x += c;
        u[2].x += c;
        u[3].x += c;
    }

    v = (V7c240 *)D_00446630;
    v[0].x = v[2].x = 312.0f + D_004F7FD0[0];
    v[1].x = v[3].x = 328.0f + D_004F7FD0[0];
    v[0].y = v[1].y = 266.0f + D_004F7FD4[0];
    v[2].y = v[3].y = 282.0f + D_004F7FD4[0];
    *(u32 *)&v[0].f4 = *(u32 *)&v[1].f4 = 0x3F400000;
    *(u32 *)&v[2].f4 = *(u32 *)&v[3].f4 = 0x3F000000;
    func_00153D20(4, (f32 *)v, 0xB);
    v[0].y = v[1].y = 402.0f + D_004F7FD4[0];
    v[2].y = v[3].y = 418.0f + D_004F7FD4[0];
    *(u32 *)&v[0].f4 = *(u32 *)&v[1].f4 = 0x3F000000;
    *(u32 *)&v[2].f4 = *(u32 *)&v[3].f4 = 0x3F400000;
    func_00153D20(4, (f32 *)v, 0xB);

    D_004463C0.d8 = 0;
    D_004463C0.c0 = 0x914;
    D_004463C0.c4 = 240.0f + D_004F7FD0[0];
    D_004463C0.c8 = 282.0f + D_004F7FD4[0];
    D_004463C0.dc = 0;
    D_004463C0.e8 = 0;
    D_004463C0.f0 = 0;
    D_004463C0.fc = 0;
    D_004463C0.cc = 0.9599999785423279f;
    D_004463C0.e0 = 1.0f;
    D_004463C0.d0 = 1.25f;
    D_004463C0.d4 = 0.9375f;
    D_004463C0.f4 = 5;
    D_004463C0.f8 = -1;
    D_004463C0.e4 = 1.0f;
    D_004463C0.ec = 1.0f;
    func_00417FE0(0);
    func_00153AB0(&D_004463C0, 0);
    D_004463C0.f0 = -1;
}
